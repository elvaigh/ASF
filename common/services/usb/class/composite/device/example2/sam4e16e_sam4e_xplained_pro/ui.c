/**
 * \file
 *
 * \brief User Interface
 *
 * Copyright (c) 2014 Atmel Corporation. All rights reserved.
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
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include "ui.h"

#define  MOUSE_MOVE_RANGE  3
#define  MOUSE_MOVE_COUNT  50

#define  MOVE_UP     0
#define  MOVE_RIGHT  1
#define  MOVE_DOWN   2
#define  MOVE_LEFT   3

/*! Sequence process running each \c SEQUENCE_PERIOD ms */
#define SEQUENCE_PERIOD 150

static struct {
	bool b_modifier;
	bool b_down;
	uint8_t u8_value;
} ui_sequence[] = {
	/* Display windows menu */
	{true,true,HID_MODIFIER_LEFT_UI},
	/* Launch Windows Command line */
	{false,true,HID_R},
	{false,false,HID_R},
	/* Clear modifier */
	{true,false,HID_MODIFIER_LEFT_UI},
	/* Tape sequence "notepad" + return */
	{false,true,HID_N},
	{false,false,HID_N},
	{false,true,HID_O},
	{false,false,HID_O},
	{false,true,HID_T},
	{false,false,HID_T},
	{false,true,HID_E},
	{false,false,HID_E},
	{false,true,HID_P},
	{false,false,HID_P},
	{false,true,HID_A},
	{false,false,HID_A},
	{false,true,HID_D},
	{false,false,HID_D},
	{false,true,HID_ENTER},
	{false,false,HID_ENTER},
	/* Delay to wait "notepad" focus */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	/* Display "Atmel " */
	{true,true,HID_MODIFIER_RIGHT_SHIFT}, /* Enable Maj */
	{false,true,HID_A},
	{false,false,HID_A},
	{true,false,HID_MODIFIER_RIGHT_SHIFT}, /* Disable Maj */
	{false,true,HID_T},
	{false,false,HID_T},
	{false,true,HID_M},
	{false,false,HID_M},
	{false,true,HID_E},
	{false,false,HID_E},
	{false,true,HID_L},
	{false,false,HID_L},
	{false,true,HID_SPACEBAR},
	{false,false,HID_SPACEBAR},
	/* Display "ARM " */
	{false,true,HID_CAPS_LOCK}, /* Enable caps lock */
	{false,false,HID_CAPS_LOCK},
	{false,true,HID_A},
	{false,false,HID_A},
	{false,true,HID_R},
	{false,false,HID_R},
	{false,true,HID_M},
	{false,false,HID_M},
	{false,true,HID_CAPS_LOCK}, /* Disable caps lock */
	{false,false,HID_CAPS_LOCK},
};

/* Wakeup pin is push button (SW0) */
#define  WAKEUP_PIN      (GPIO_PUSH_BUTTON_1)
#define  WAKEUP_PIO      (PIN_PUSHBUTTON_1_PIO)
#define  WAKEUP_PIO_ID   (PIN_PUSHBUTTON_1_ID)
#define  WAKEUP_PIO_MASK (PIN_PUSHBUTTON_1_MASK)
#define  WAKEUP_PIO_ATTR \
	(PIO_INPUT | PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_LOW_LEVEL)

static uint8_t move_dir = MOVE_UP;
static int32_t move_count = MOUSE_MOVE_COUNT;

/* Interrupt on "pin change" from push button to do wakeup on USB
 * Note:
 * This interrupt is enable when the USB host enable remotewakeup feature
 * This interrupt wakeup the CPU if this one is in idle mode
 */
static void ui_wakeup_handler(uint32_t id, uint32_t mask)
{
	if (WAKEUP_PIO_ID == id && WAKEUP_PIO_MASK == mask) {
		/* It is a wakeup then send wakeup USB */
		udc_remotewakeup();
	}
}

void ui_init(void)
{
	sleepmgr_lock_mode(SLEEPMGR_SLEEP_WFI);
	/* Set handler for push button */
	pio_handler_set(WAKEUP_PIO, WAKEUP_PIO_ID, WAKEUP_PIO_MASK,
		WAKEUP_PIO_ATTR, ui_wakeup_handler);
	/* Enable IRQ for button */
	NVIC_EnableIRQ((IRQn_Type) WAKEUP_PIO_ID);
	/* Initialize LED */
	LED_Off(LED0);
}

void ui_powerdown(void)
{
	LED_Off(LED0);
}


void ui_wakeup_enable(void)
{
	/* Configure PIO as input */
	pio_configure_pin(WAKEUP_PIN, WAKEUP_PIO_ATTR);
	/* Enable interrupt */
	pio_enable_pin_interrupt(WAKEUP_PIN);
}

void ui_wakeup_disable(void)
{
	/* Disable interrupt for button pin */
	pio_disable_pin_interrupt(WAKEUP_PIN);
}

void ui_wakeup(void)
{
	LED_On(LED0);
}

void ui_com_open(uint8_t port)
{
	UNUSED(port);
}

void ui_com_close(uint8_t port)
{
	UNUSED(port);
}

void ui_com_rx_start(void)
{
}

void ui_com_rx_stop(void)
{
}

void ui_com_tx_start(void)
{
}

void ui_com_tx_stop(void)
{
}

void ui_com_error(void)
{
}

void ui_com_overflow(void)
{
}

void ui_start_read(void)
{
}

void ui_stop_read(void)
{
}

void ui_start_write(void)
{
}

void ui_stop_write(void)
{
}

void ui_process(uint16_t framenumber)
{
	bool b_btn_state, sucess;
	static bool btn_last_state = false;
	static bool sequence_running = false;
	static uint8_t u8_sequence_pos = 0;
	uint8_t u8_value;
	static uint16_t cpt_sof = 0;

	if ((framenumber % 1000) == 0) {
		LED_On(LED0);
	}
	if ((framenumber % 1000) == 500) {
		LED_Off(LED0);
	}
	/* Scan process running each 2ms */
	cpt_sof++;
	if ((cpt_sof % 2) == 0) {
		return;
	}

	/* Uses buttons to move mouse */
	if (!ioport_get_pin_level(GPIO_PUSH_BUTTON_1)) {
		move_count --;
		switch(move_dir) {
		case MOVE_UP:
			udi_hid_mouse_moveY(-MOUSE_MOVE_RANGE);
			if (move_count < 0) {
				move_dir = MOVE_RIGHT;
				move_count = MOUSE_MOVE_COUNT;
			}
			break;
		case MOVE_RIGHT:
			udi_hid_mouse_moveX(+MOUSE_MOVE_RANGE);
			if (move_count < 0) {
				move_dir = MOVE_DOWN;
				move_count = MOUSE_MOVE_COUNT;
			}
			break;
		case MOVE_DOWN:
			udi_hid_mouse_moveY(+MOUSE_MOVE_RANGE);
			if (move_count < 0) {
				move_dir = MOVE_LEFT;
				move_count = MOUSE_MOVE_COUNT;
			}
			break;
		case MOVE_LEFT:
			udi_hid_mouse_moveX(-MOUSE_MOVE_RANGE);
			if (move_count < 0) {
				move_dir = MOVE_UP;
				move_count = MOUSE_MOVE_COUNT;
			}
			break;
		}
	}
	
	/* Both buttons down to send keys sequence */
	b_btn_state = (!ioport_get_pin_level(GPIO_PUSH_BUTTON_1));
	if (b_btn_state != btn_last_state) {
		btn_last_state = b_btn_state;
		sequence_running = true;
	}

	/* Sequence process running each period */
	if (SEQUENCE_PERIOD > cpt_sof) {
		return;
	}
	cpt_sof = 0;

	if (sequence_running) {
		/* Send next key */
		u8_value = ui_sequence[u8_sequence_pos].u8_value;
		if (u8_value!=0) {
			if (ui_sequence[u8_sequence_pos].b_modifier) {
				if (ui_sequence[u8_sequence_pos].b_down) {
					sucess = udi_hid_kbd_modifier_down(u8_value);
				} else {
					sucess = udi_hid_kbd_modifier_up(u8_value);
				}
			} else {
				if (ui_sequence[u8_sequence_pos].b_down) {
					sucess = udi_hid_kbd_down(u8_value);
				} else {
					sucess = udi_hid_kbd_up(u8_value);
				}
			}
			if (!sucess) {
				return; /* Retry it on next schedule */
			}
		}
		/* Valid sequence position */
		u8_sequence_pos++;
		if (u8_sequence_pos >=
			sizeof(ui_sequence) / sizeof(ui_sequence[0])) {
			u8_sequence_pos = 0;
			sequence_running = false;
		}
	}
}

void ui_kbd_led(uint8_t value)
{
	UNUSED(value);
}


/**
 * \defgroup UI User Interface
 *
 * Human interface on SAM4E-XPRO:
 * - LED0 blinks when USB host has checked and enabled HID and MSC interface
 * - No mouse buttons are linked
 * - SW0 is used to move mouse around
 * - SW0 down opens a notepad application on Windows O.S.
 *   and sends key sequence "Atmel ARM"
 * - Only a low level on SW0 will generate a wakeup to USB Host in remote wakeup mode.
 *
 */
