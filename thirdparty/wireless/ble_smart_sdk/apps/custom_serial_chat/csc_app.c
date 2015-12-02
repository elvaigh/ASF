/**
 * \file
 *
 * \brief Custom Serial Chat Application declarations
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel micro controller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel
 * Support</a>
 */

/**
 * \mainpage
 * \section preface Preface
 * This is the reference manual for the Custom Serial Chat Application declarations
 */
/*- Includes -----------------------------------------------------------------------*/
#include <asf.h>
#include "platform.h"
#include "at_ble_api.h"
#include "ble_manager.h"
#include "csc_app.h"
#include "cscp.h"
#include "cscs.h"
#include "ble_utils.h"
#include "console_serial.h"
#include "uart.h"

/* =========================== GLOBALS ============================================================ */

#define APP_STACK_SIZE  (1024)

volatile unsigned char app_stack_patch[APP_STACK_SIZE];

/* Data length to be send over the air */
uint16_t send_length = 0;

/* Buffer data to be send over the air */
uint8_t send_data[APP_TX_BUF_SIZE];
uint8_t buff = 0;

bool app_exec = true;

/* Function used for receive data */
static void csc_app_recv_buf(uint8_t *recv_data, uint8_t recv_len)
{
	uint16_t ind = 0;

	if (recv_len) {
		for (ind = 0; ind < recv_len; ind++) {
			DBG_LOG_CONT("%c", recv_data[ind]);
		}
		DBG_LOG("\r\n");
	}
}

/* Callback called for new data from remote device */
static void csc_prf_report_ntf_cb(csc_report_ntf_t *report_info)
{
	DBG_LOG("\r\n");

	csc_app_recv_buf(report_info->recv_buff, report_info->recv_buff_len);
}

/* Function used for send data */
static void uart_rx_callback(void)
{
	if(buff == '\r') {
		send_plf_int_msg_ind(UART_RX_COMPLETE, UART_RX_INTERRUPT_MASK_RX_FIFO_NOT_EMPTY_MASK, send_data, send_length);
		
		memset(send_data, 0, APP_TX_BUF_SIZE);
		send_length = 0;
		DBG_LOG("");
	}
	else {
		send_data[send_length++] = buff;
		DBG_LOG_CONT("%c", buff);
	}
	
	getchar_aysnc(uart_rx_callback, &buff);
}

static void user_event_callback(struct uart_module *const module) {
	uint16_t plf_event_type;
	uint16_t plf_event_data_len;
	uint8_t plf_event_data[APP_TX_BUF_SIZE] = {0, };

	platform_event_get(&plf_event_type, plf_event_data, &plf_event_data_len);
	
	if(plf_event_type == ((UART_RX_INTERRUPT_MASK_RX_FIFO_NOT_EMPTY_MASK << 8) | UART_RX_COMPLETE)) {
		csc_prf_send_data(plf_event_data, plf_event_data_len);
	}
}

int main(void)
{
	platform_driver_init();
	acquire_sleep_lock();

	/* Initializing the console  */
	serial_console_init();

	DBG_LOG("Initializing Custom Serial Chat Application");

	/* Initialize the buffer address and buffer length based on user input */
	csc_prf_buf_init(&send_data[0], APP_TX_BUF_SIZE);

	/* initialize the ble chip  and Set the device mac address */
	ble_device_init(NULL);

	register_ble_user_event_cb(user_event_callback);

	/* Register the notification handler */
	notify_recv_ntf_handler(csc_prf_report_ntf_cb);

	getchar_aysnc(uart_rx_callback, &buff);

	/* Capturing the events  */
	while (app_exec) {
		ble_event_task();
	}
	return 0;
}



