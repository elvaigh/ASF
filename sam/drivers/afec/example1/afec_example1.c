/**
 * \file
 *
 * \brief AFEC temperature sensor example for SAM.
 *
 * Copyright (c) 2013 Atmel Corporation. All rights reserved.
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
 * \mainpage AFEC Temperature Sensor Example
 *
 * \section Purpose
 *
 * The example demonstrates how to use the temperature sensor
 * feature inside the microcontroller.
 *
 * \section Requirements
 *
 * This example can be used on sam4e-ek boards.
 *
 * \section Description
 *
 * The example is aimed to demonstrate the temperature sensor feature
 * inside the device. To use this feature, the temperature sensor should be automatically
 * turned on by RTC event. The channel 15 is connected to the sensor by default.
 * If set RTCT = 1, then if TRGEN is disabled and all channels are disabled (AFE_CHSR = 0),
 * then only channel 15 is converted at a rate of 1 conversion per second.
 *
 * The temperature sensor provides an output voltage (VT) that is proportional
 * to absolute temperature (PTAT). The relationship between measured voltage and
 * actual temperature could be found in Electrical Characteristics part of the
 * datasheet.
 *
 * By configuring the temp sensor register, it will work in comparison window mode and will ouput
 * information when the temperature is in the comparison window.
 *
 * \section Usage
 *
 * -# Build the program and download it into the evaluation board. Please
 *    refer to the
 *    <a href="http://www.atmel.com/dyn/resources/prod_documents/6421B.pdf">
 *    SAM-BA User Guide</a>, the
 *    <a href="http://www.atmel.com/dyn/resources/prod_documents/doc6310.pdf">
 *    GNU-Based Software Development</a>
 *    application note or the
 *    <a href="http://www.iar.com/website1/1.0.1.0/78/1/">
 *    IAR EWARM User and reference guides</a>,
 *    depending on the solutions that users choose.
 * -# On the computer, open and configure a terminal application
 *    (e.g., HyperTerminal on Microsoft Windows) with these settings:
 *   - 115200 bauds
 *   - 8 bits of data
 *   - No parity
 *   - 1 stop bit
 *   - No flow control
 * -# In the terminal window, the
 *    following text should appear (values depend on the board and the chip used):
 *    \code
 *     -- AFEC Temperature Sensor xxx --
 *     -- xxxxxx-xx
 *     -- Compiled: xxx xx xxxx xx:xx:xx --
 *    \endcode
 * -# The application will output current Celsius temperature on the terminal.
 *
 */

#include "asf.h"

/** Reference voltage for AFEC,in mv. */
#define VOLT_REF        (3300)

/** The maximal digital value */
#define MAX_DIGITAL     (4095)

#define STRING_EOL    "\r"
#define STRING_HEADER "-- AFEC Temperature Sensor Example --\r\n" \
		"-- "BOARD_NAME" --\r\n" \
		"-- Compiled: "__DATE__" "__TIME__" --"STRING_EOL

/**
 * \brief Configure UART console.
 */
static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
		.paritytype = CONF_UART_PARITY
	};

	/* Configure console UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
}

/**
 * \brief AFEC interrupt callback function.
 */
static void afec_temp_sensor_data_ready(void)
{
	uint32_t ul_vol;
	uint32_t ul_value = 0;
	uint32_t ul_temp;

	if ((afec_get_interrupt_status(AFEC0) & (AFE_ISR_EOC15 | AFE_ISR_TEMPCHG)) ==
			(AFE_ISR_EOC15 | AFE_ISR_TEMPCHG)) {

		ul_value = afec_channel_get_value(AFEC0, AFEC_TEMPERATURE_SENSOR);

		ul_vol = ul_value * VOLT_REF / MAX_DIGITAL;

		/* Using multiplication (*0.21186) instead of division (/4.72). */
		ul_temp = (ul_vol - 1440) * 0.21186 + 27.0;

		printf("Tempature:%d \n\r", (int32_t)ul_temp);
		puts("The tempature is in comparison window \n\r");
	}
}

/**
 * \brief Application entry point.
 *
 * \return Unused (ANSI-C compatibility).
 */
int main(void)
{
	/* Initialize the SAM system. */
	sysclk_init();
	board_init();

	configure_console();

	/* Output example information. */
	puts(STRING_HEADER);

	afec_enable(AFEC0);

	struct afec_config afec_cfg;

	afec_get_config_defaults(&afec_cfg);

	afec_init(AFEC0, &afec_cfg);

	afec_set_trigger(AFEC0, AFEC_TRIG_SW);

	struct afec_ch_config afec_ch_cfg;
	afec_ch_get_config_defaults(&afec_ch_cfg);
	afec_ch_cfg.offset= true;
	afec_ch_set_config(AFEC0, AFEC_TEMPERATURE_SENSOR, &afec_ch_cfg);
	afec_channel_set_analog_offset(AFEC0, AFEC_TEMPERATURE_SENSOR, 0x800);
	
	struct afec_temp_sensor_config afec_temp_sensor_cfg;

	afec_temp_sensor_get_config_defaults(&afec_temp_sensor_cfg);
	afec_temp_sensor_cfg.rctc = true;
	afec_temp_sensor_set_config(AFEC0, &afec_temp_sensor_cfg);

	afec_set_callback(AFEC0, AFEC_INTERRUPT_TEMP_CHANGE | AFEC_INTERRUPT_EOC_15,
			afec_temp_sensor_data_ready, 1);

	afec_set_calib_mode(AFEC0);
	while(!(afec_get_interrupt_status(AFEC0) & AFE_ISR_EOCAL) == AFE_ISR_EOCAL);
	
	while (1) {
	}
}
