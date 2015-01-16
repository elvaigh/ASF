/**
 * \file
 *
 * \brief SAM DAC Callback Quick Start
 *
 * Copyright (C) 2015 Atmel Corporation. All rights reserved.
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
 *    Atmel microcontroller product.
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
/**
 * \mainpage SAM0 DAC Unit Test
 * See \ref appdoc_main "here" for project documentation.
 * \copydetails appdoc_preface
 *
 *
 * \page appdoc_preface Overview
 * This unit test carries out tests for the DAC driver.
 * DAC conversion has already been tested by quick_start.
 * This test cases consists of the following functionalities:
 *      - Test for DAC initialization.
 *      - Test for DAC buffer empty
 */

/**
 * \page appdoc_main SAM0 DAC Unit Test
 *
 * Overview:
 * - \ref asfdoc_sam0_dac_unit_test_intro
 * - \ref asfdoc_sam0_dac_unit_test_setup
 * - \ref asfdoc_sam0_dac_unit_test_usage
 * - \ref asfdoc_sam0_dac_unit_test_compinfo
 * - \ref asfdoc_sam0_dac_unit_test_contactinfo
 *
 * \section asfdoc_sam0_dac_unit_test_intro Introduction
 * \copydetails appdoc_preface
 *
 * The following kit is required for carrying out the test:
 *  - SAM D21 Xplained Pro board
 *
 * \section asfdoc_sam0_dac_unit_test_setup Setup
 *
 * To run the test:
 *  - Connect the supported Xplained Pro board to the computer using a
 *    micro USB cable.
 *  - Open the virtual COM port in a terminal application.
 *    \note The USB composite firmware running on the Embedded Debugger (EDBG)
 *          will enumerate as debugger, virtual COM port and EDBG data
 *          gateway.
 *  - Build the project, program the target and run the application.
 *    The terminal shows the results of the unit test.
 *
 * \section asfdoc_sam0_dac_unit_test_usage Usage
 *  - Different operations of the dac are tested.
 *
 * \section asfdoc_sam0_dac_unit_test_compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for ARM.
 * Other compilers may or may not work.
 *
 * \section asfdoc_sam0_dac_unit_test_contactinfo Contact Information
 * For further information, visit
 * <a href="http://www.atmel.com">http://www.atmel.com</a>.
 */
/**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include <stdio_serial.h>
#include <string.h>
#include "conf_test.h"

void configure_rtc_count(void);
void configure_event_resource(void);

struct usart_module cdc_uart_module;
struct dac_module dac_instance;
struct rtc_module rtc_instance;
struct events_resource event_dac;

static void cdc_uart_init(void)
{
	struct usart_config usart_conf;

	/* Configure USART for unit test output */
	usart_get_config_defaults(&usart_conf);
	usart_conf.mux_setting = CONF_STDIO_MUX_SETTING;
	usart_conf.pinmux_pad0 = CONF_STDIO_PINMUX_PAD0;
	usart_conf.pinmux_pad1 = CONF_STDIO_PINMUX_PAD1;
	usart_conf.pinmux_pad2 = CONF_STDIO_PINMUX_PAD2;
	usart_conf.pinmux_pad3 = CONF_STDIO_PINMUX_PAD3;
	usart_conf.baudrate    = CONF_STDIO_BAUDRATE;

	stdio_serial_init(&cdc_uart_module, CONF_STDIO_USART, &usart_conf);
	usart_enable(&cdc_uart_module);
}


void configure_event_resource(void)
{
	struct events_config event_config;
	events_get_config_defaults(&event_config);

	event_config.generator      = EVSYS_ID_GEN_RTC_OVF;
	event_config.edge_detect    = EVENTS_EDGE_DETECT_RISING;
	event_config.path           = EVENTS_PATH_ASYNCHRONOUS;
	event_config.clock_source   = GCLK_GENERATOR_0;

	events_allocate(&event_dac, &event_config);
	events_attach_user(&event_dac, EVSYS_ID_USER_DAC_START);
}



//! [setup_rtc]
void configure_rtc_count(void)
{
	struct rtc_count_events  rtc_event;
	struct rtc_count_config config_rtc_count;
	rtc_count_get_config_defaults(&config_rtc_count);
	config_rtc_count.prescaler           = RTC_COUNT_PRESCALER_DIV_1;
	config_rtc_count.mode                = RTC_COUNT_MODE_16BIT;
	config_rtc_count.continuously_update = true;
	rtc_count_init(&rtc_instance, RTC, &config_rtc_count);
	rtc_event.generate_event_on_overflow = true;
	rtc_count_enable_events(&rtc_instance, &rtc_event);
	rtc_count_enable(&rtc_instance);
}
//! [setup_rtc]

/* Dac init test*/
static void run_dac_init_test(const struct test_case *test)
{
	enum status_code status = STATUS_ERR_IO;
	struct dac_config config_dac;

	dac_get_config_defaults(&config_dac);
	dac_instance.start_on_event = true;
	status = dac_init(&dac_instance, DAC, &config_dac);
		/* Check for successful initialization */
	test_assert_true(test, status == STATUS_OK,
			"DAC initialization failed");

	struct dac_events events =
		{ .on_event_start_conversion = true };
	dac_enable_events(&dac_instance, &events);
	dac_enable(&dac_instance);
	
    	struct dac_chan_config config_dac_chan;
	dac_chan_get_config_defaults(&config_dac_chan);

	dac_chan_set_config(&dac_instance, DAC_CHANNEL_0,
			&config_dac_chan);
	dac_chan_enable(&dac_instance, DAC_CHANNEL_0);
}

/* Dac channel buffer empty and underrun test */
static void run_dac_event_control_test(const struct test_case *test)
{
	enum status_code status = STATUS_ERR_IO;
	uint32_t dac_status;
	
	status = dac_chan_write(&dac_instance, DAC_CHANNEL_0, 100);
	test_assert_true(test, status == STATUS_OK,
			"DAC chan write failed");

	configure_rtc_count();
	rtc_count_set_period(&rtc_instance, 1);
	configure_event_resource();

	/* DAC buffer empty test*/
	delay_ms(3);
	dac_status = dac_get_status(&dac_instance);
	test_assert_true(test, dac_status & DAC_STATUS_CHANNEL_0_EMPTY == DAC_STATUS_CHANNEL_0_EMPTY,
			"dac channel buffer empty didn't happen");

	/* DAC buffer underrun test*/
	delay_ms(3);
	dac_status = dac_get_status(&dac_instance);
	test_assert_true(test, dac_status & DAC_STATUS_CHANNEL_0_UNDERRUN == DAC_STATUS_CHANNEL_0_UNDERRUN,
			"dac channel buffer underrun didn't happen");
}

int main(void)
{

	system_init();
	cdc_uart_init();
	delay_init();

    DEFINE_TEST_CASE(dac_init_test,NULL,
			run_dac_init_test,NULL,
			"dac buffer init test");
	DEFINE_TEST_CASE(dac_event_control_test,NULL,
			run_dac_event_control_test,NULL,
			"dac event control conversion test");


	/* Put test case addresses in an array */
	DEFINE_TEST_ARRAY(dac_tests) = {
		&dac_init_test,
		&dac_event_control_test,
	};

	/* Define the test suite */
	DEFINE_TEST_SUITE(dac_test_suite, dac_tests,
			"SAM DAC driver test suite");

	/* Run all tests in the suite*/
	test_suite_run(&dac_test_suite);

	while (true) {
		/* Intentionally left empty */
	}
}

