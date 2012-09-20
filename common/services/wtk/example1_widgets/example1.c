/**
 * \file
 *
 * \brief Graphic Widget Toolkit library example application
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
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
 * \mainpage
 *
 * \section intro Introduction
 * This example will create a simple touch-enabled GUI on the display of the
 * mXT143E Xplained, using the Widget Toolkit.
 *
 * \section files Main files:
 * - example1.c: main example implementation
 * - widget_gui.c : display GUI creation and event handling
 * - widget_gui.h : header for the GUI management routines
 * - atmel_logo_small.h : Atmel logo for output to the display
 * - conf_board.h: board configuration
 * - conf_clock.h: system clock driver configuration
 * - conf_ili9341.h: display driver configuration
 * - conf_membag.h: memory bag allocation configuration
 * - conf_mxt.h: maXTouch driver configuration
 * - conf_sysfont.h: system font configuration
 * - conf_twim.h: TWI driver configuration
 * - conf_win.h: window system configuration
 * - conf_wtk.h: widget library configuration
 * - UC3 and SAM only: conf_spi_master.h: SPI master service configuration
 * - XMEGA only: conf_usart_spi.h: USART SPI service configuration
 *
 * \section apiinfo Widget library API
 * The widget library API can be found \ref wtk_group "here", while the
 * graphics service API can be found \ref gfx_group "here". The maXTouch API
 * can be found \ref mxt_group "here".
 *
 * \section deviceinfo Device Info
 * This example has been tested with the mXT143E Xplained on the following kits:
 * - UC3-A3 Xplained
 * - UC3-L0 Xplained
 * - XMEGA-A1 Xplained
 * - XMEGA-B1 Xplained
 * - XMEGA-A3BU Xplained
 * - SAM4S Xplained
 *
 * \section exampledescription Description of the example
 * On startup the example application will create a simple GUI on the display of
 * the maXTouch Xplained board, showing a slider, progress bar, check box,
 * radio buttons and buttons. Touching the display will manipulate each of these
 * widgets.
 *
 * \section dependencies Dependencies
 * Relevant module dependencies for this application are:
 * - \ref wtk_group
 * - \ref gfx_group
 * - \ref mxt_group
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for AVR.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com/">Atmel</A>.\n
 */

#include <asf.h>
#include "widget_gui.h"
#include "atmel_logo_small.h"

/** Address of the mXT143E on TWI bus */
#define MAXTOUCH_TWI_ADDRESS  0x4a

/**
 * \brief Set maXTouch configuration
 *
 * This function writes a set of predefined, optimal maXTouch configuration data
 * to the mXT143E Xplained.
 *
 * \param device Pointer to mxt_device struct
 */
static void mxt_init(struct mxt_device *device)
{
	enum status_code status;

	/* T8 configuration object data */
	uint8_t t8_object[] = {
		0x10, 0x05, 0x0a, 0x14, 0x64, 0x00, 0x05,
		0x0a, 0x00, 0x00,
	};

	/* T9 configuration object data */
	uint8_t t9_object[] = {
		0x8f, 0x00, 0x00, 0x0d, 0x0b, 0x00, 0x21,
		0x3c, 0x0f, 0x00, 0x32, 0x01, 0x01, 0x00,
		0x08, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x1c, 0x1c, 0x37, 0x37, 0x8f, 0x50,
		0xcf, 0x6e, 0x00, 0x02, 0x2f, 0x2c, 0x00
	};

	/* T48 configuration object data */
	uint8_t t48_object[] = {
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00
	};

	/* TWI configuration */
	twi_master_options_t twi_opt = {
		.speed = MXT_TWI_SPEED,
		.chip  = MAXTOUCH_TWI_ADDRESS,
	};

	status = twi_master_setup(TWI_INTERFACE, &twi_opt);
	Assert(status == STATUS_OK);

	/* Initialize the maXTouch device */
	status = mxt_init_device(device, TWI_INTERFACE,
			MAXTOUCH_TWI_ADDRESS, MXT143E_XPLAINED_CHG);
	Assert(status == STATUS_OK);

	/* Issue soft reset of maXTouch device by writing a non-zero value to
	 * the reset register */
	mxt_write_config_reg(device, mxt_get_object_address(device,
			MXT_GEN_COMMANDPROCESSOR_T6, 0)
			+ MXT_GEN_COMMANDPROCESSOR_RESET, 0x01);

	/* Wait for the reset of the device to complete */
	delay_ms(MXT_RESET_TIME);

	/* Write data to configuration registers in T7 configuration object */
	mxt_write_config_reg(device, mxt_get_object_address(device,
			MXT_GEN_POWERCONFIG_T7, 0) + 0, 0xff);
	mxt_write_config_reg(device, mxt_get_object_address(device,
			MXT_GEN_POWERCONFIG_T7, 0) + 1, 0xff);
	mxt_write_config_reg(device, mxt_get_object_address(device,
			MXT_GEN_POWERCONFIG_T7, 0) + 2, 0x32);

	/* Write predefined configuration data to configuration objects */
	mxt_write_config_object(device, mxt_get_object_address(device,
			MXT_GEN_ACQUISITIONCONFIG_T8, 0), &t8_object);
	mxt_write_config_object(device, mxt_get_object_address(device,
			MXT_TOUCH_MULTITOUCHSCREEN_T9, 0), &t9_object);
	mxt_write_config_object(device, mxt_get_object_address(device,
			MXT_PROCG_TOUCHSUPPRESSION_T48, 0), &t48_object);

	/* Issue recalibration command to maXTouch device by writing a non-zero
	 * value to the calibrate register */
	mxt_write_config_reg(device, mxt_get_object_address(device,
			MXT_GEN_COMMANDPROCESSOR_T6, 0)
			+ MXT_GEN_COMMANDPROCESSOR_CALIBRATE, 0x01);
}

/**
 * \brief Configure the root GUI window
 *
 * Configures the root window background to be a tiled version of the
 * Atmel company logo, and sets it as being visible.
 */
static void setup_gui_root_window(void)
{
	struct win_attributes root_attr;
	struct win_window *win_root;

	win_root = win_get_root();
	root_attr = *win_get_attributes(win_root);
	root_attr.background = &atmel_logo_small;
	win_set_attributes(win_root, &root_attr, WIN_ATTR_BACKGROUND);

	win_show(win_root);
}

/**
 * \brief Show an out of memory error on the display
 *
 * Shows a full screen error when called, signaling that the system
 * ran out of memory when initializing a WTK application.
 */
static void show_out_of_memory_error(void)
{
	const char memory_string[] = "OUT OF MEMORY";
	gfx_coord_t disp_width, disp_height;
	gfx_coord_t str_x, str_y;

	/* Get the display width and height */
	disp_width = gfx_get_width();
	disp_height = gfx_get_height();

	/* Determine the X,Y coordinates of the error string when centered */
	gfx_get_string_bounding_box(memory_string, &sysfont, &str_x, &str_y);
	str_x = (disp_width / 2) - (str_x / 2);
	str_y = (disp_height / 2) - (str_y / 2);

	/* Blank display, show out of memory error text */
	gfx_set_clipping(0, 0, disp_width, disp_height);
	gfx_draw_filled_rect(0, 0, disp_width, disp_height, GFX_COLOR_BLACK);
	gfx_draw_string(memory_string, str_x, str_y, &sysfont,
			GFX_COLOR_TRANSPARENT, GFX_COLOR_RED);
}

/**
 * \brief Convert touch events from the touchscreen into window pointer events
 *
 * Reads touch events in from the touchscreen and converts them into a
 * Window Manager pointer event, for enqueuing into the window event queue.
 *
 * \return Boolean true if a touch event was read, false if no touch event
 *         or a corrupt touch event was received
 */
static bool read_touch_event(struct mxt_device *device,
		struct win_pointer_event *win_touch_event)
{
	struct mxt_touch_event touch_event;

	/* Abort if no touch event is pending */
	if (!(mxt_is_message_pending(device))) {
		return false;
	}
	
	/* Get the first touch event in queue */
	if (mxt_read_touch_event(device, &touch_event) != STATUS_OK) {
		return false;
	}

	/* Translate touch event type into a WTK event type */
	if (touch_event.status & MXT_PRESS_EVENT) {
		win_touch_event->type = WIN_POINTER_PRESS;
	} else if (touch_event.status & MXT_MOVE_EVENT) {
		win_touch_event->type = WIN_POINTER_MOVE;
	} else if (touch_event.status & MXT_RELEASE_EVENT) {
		win_touch_event->type = WIN_POINTER_RELEASE;
	} else {
		return false;
	}

	/* Indicate the touch event is a non-relative movement with the virtual
	 * touch button pressed
	 */
	win_touch_event->is_relative = false;
	win_touch_event->buttons = WIN_TOUCH_BUTTON;

	/* Translate the touch X and Y position into a screen coordinate */
	win_touch_event->pos.x =
			((uint32_t)touch_event.x * gfx_get_width()) / 4096;
	win_touch_event->pos.y =
			((uint32_t)touch_event.y * gfx_get_height()) / 4096;
			
	return true;
}

/**
 * \brief main example code
 *
 * The main function will draw all the graphic primitives from the graphic
 * library on a line from left to right (incrementing x) and repeat this
 * from bottom to top with varying colors (incrementing y). Below the figures
 * it draws the Atmel logo centered on the screen.
 */
int main(void)
{
	static struct mxt_device device;

	board_init();
	sysclk_init();
	membag_init();

	gfx_init();
	gfx_set_orientation(GFX_SWITCH_XY | GFX_FLIP_Y);

	mxt_init(&device);
	win_init();

	setup_gui_root_window();
	if (app_widget_launch() == false) {
		show_out_of_memory_error();
		for (;;);
	}

	while (true) {
		struct win_pointer_event win_touch_event;
	
		/* Queue touch events from the touchscreen if any are available */
		while (read_touch_event(&device, &win_touch_event)) {
			win_queue_pointer_event(&win_touch_event);
		}

		/* Process queued events in the windowing system */
		win_process_events();
	}
}