/**
 * \file
 *
 * \brief SAM D20 Analog to Digital Converter (ADC) Unit test
 *
 * Copyright (C) 2013 Atmel Corporation. All rights reserved.
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
 * \mainpage ADC UNIT TEST
 *
 * \section intro Introduction
 * This unit test carries out tests for the ADC driver.
 * It consists of test cases for the following functionalities:
 *      - Test for ADC initialization.
 *      - Test for ADC polled mode conversion.
 *      - Test for ADC callback mode conversion.
 *      - Test for ADC averaging mode.
 *      - Test for ADC window mode.
 * Input to the ADC is provided with the DAC module.
 *
 * The following kit is required for carrying out the test:
 *      - SAM D20 Xplained Pro board
 *
 * \section Setup
 *
 * The following connection is already available on the board.
 *
 *      - DAC VOUT (PA00) <-----> ADC2 (PA02)
 *
 * The following steps has to be done:
 *      - Connect the SAM D20 Xplained Pro board to the computer using
 *        a micro USB cable.
 *      - Open the virtual COM port in a terminal application.
 * \note  The USB composite firmware running on the Embedded Debugger (EDBG)
 *        will enumerate as debugger, virtual COM port and EDBG data
 *        gateway.
 *      - Build the project, program the target and run the application.
 *        The terminal shows the results of the unit test.
 *
 * \section Description
 *
 *      - The unit test configures DAC module to provide
 *        voltage to the ADC input.
 *      - DAC output is adjusted to generate various voltages
 *        which are measured by the ADC.
 *      - Different modes of the ADC are tested.
 *
 * \section contactinfo Contact Information
 * For further information, visit <a href="http://www.atmel.com/">Atmel</a>.\n
 * Support and FAQ: http://support.atmel.no/
 */

#include <asf.h>
#include <stdio_serial.h>
#include <string.h>

/* Number of ADC samples used in the test */
#define ADC_SAMPLES 128

/* Structure for UART module connected to EDBG (used for unit test output) */
struct usart_module cdc_uart_module;
/* Structure for ADC module */
struct adc_module adc_inst;
/* Structure for DAC module */
struct dac_module dac_inst;
/* ADC result buffer to store the sample values */
uint16_t adc_buf[ADC_SAMPLES];

/* Interrupt flag used during callback test */
volatile bool interrupt_flag = false;
/* Flag to check successful initialization */
volatile bool adc_init_success = false;

/**
 * \internal
 * \brief ADC callback function
 *
 * Called by ADC driver on interrupt detection.
 *
 * \param module Pointer to the ADC module (not used)
 */
void adc_user_callback(const struct adc_module *const module)
{
	interrupt_flag = true;
}

/**
 * \brief Initialize the USART for unit test
 *
 * Initializes the SERCOM USART (SERCOM4) used for sending the
 * unit test status to the computer via the EDBG CDC gateway.
 */
static void cdc_uart_init(void)
{
	struct usart_config cdc_uart_config;

	/* Configure USART for unit test output */
	usart_get_config_defaults(&cdc_uart_config);
	cdc_uart_config.mux_settings     = USART_RX_3_TX_2_XCK_3;
	cdc_uart_config.pinout_pad3      = EDBG_CDC_RX_PINMUX;
	cdc_uart_config.pinout_pad2      = EDBG_CDC_TX_PINMUX;
	cdc_uart_config.baudrate         = 115200;
	stdio_serial_init(&cdc_uart_module, EDBG_CDC_MODULE, &cdc_uart_config);
	usart_enable(&cdc_uart_module);
	/* Enable transceivers */
	usart_enable_transceiver(&cdc_uart_module, USART_TRANSCEIVER_TX);
	usart_enable_transceiver(&cdc_uart_module, USART_TRANSCEIVER_RX);
}

/**
 * \brief Initialize the DAC for unit test
 *
 * Initializes the DAC module used for sending the analog values
 * to the ADC during test.
 */
static void test_dac_init(void)
{
	/* Structures for DAC configuration */
	struct dac_config config;
	struct dac_chan_config chan_config;

	/* Configure the DAC module */
	dac_get_config_defaults(&config);
	config.reference    = DAC_REFERENCE_INT1V;
	config.clock_source = GCLK_GENERATOR_3;
	dac_init(&dac_inst, DAC, &config);
	dac_enable(&dac_inst);

	/* Configure the DAC channel */
	dac_chan_get_config_defaults(&chan_config);
	chan_config.enable_start_on_event = false;
	dac_chan_set_config(&dac_inst, DAC_CHANNEL_0, &chan_config);
	dac_chan_enable(&dac_inst, DAC_CHANNEL_0);
}

/**
 * \internal
 * \brief Test for ADC initialization.
 *
 * This test initializes the ADC module and checks whether the
 * initialization is successful or not.
 *
 * If this test fails no other tests will run.
 *
 * \param test Current test case.
 */
static void run_adc_init_test(const struct test_case *test)
{
	enum status_code status = STATUS_ERR_IO;
	
	/* Structure for ADC configuration */
	struct adc_config config;
	adc_get_config_defaults(&config);
	config.positive_input = ADC_POSITIVE_INPUT_PIN2;
	config.reference      = ADC_REFERENCE_INT1V;
	config.clock_source   = GCLK_GENERATOR_3;
	config.gain_factor    = ADC_GAIN_FACTOR_1X;
	/* Initialize the ADC */
	status = adc_init(&adc_inst, ADC, &config);
	/* Check for successful initialization */
	test_assert_true(test, status == STATUS_OK,
			"ADC initialization failed");
	status = STATUS_ERR_IO;
	/* Enable the ADC */
	status = adc_enable(&adc_inst);
	/* Check for successful enable */
	test_assert_true(test, status == STATUS_OK,
			"ADC enabling failed");

	if (status == STATUS_OK) {
		adc_init_success = true;
	}
}

/**
 * \internal
 * \brief Test for ADC conversion in polled mode.
 *
 * This test checks the polled mode functionality of the ADC.
 * 0.5V and 1V inputs are applied to the ADC via DAC and the ADC
 * outputs are verified for expected results.
 *
 * \param test Current test case.
 */
static void run_adc_polled_mode_test(const struct test_case *test)
{
	uint16_t adc_result = 0;
	/* Skip test if ADC initialization failed */
	test_assert_true(test, adc_init_success,
			"Skipping test due to failed initialization");
	
	/* Set 0.5V on DAC output */
	dac_chan_write(&dac_inst, DAC_CHANNEL_0, 512);
	delay_ms(1);
	/* Start an ADC conversion */
	adc_start_conversion(&adc_inst);
	while (adc_read(&adc_inst, &adc_result) != STATUS_OK) {
	}
	/* Test result */
	test_assert_true(test, adc_result > 1990,
			"Error in ADC conversion at 0.5V input");

	adc_flush(&adc_inst);
	/* Set 1V on DAC output */
	dac_chan_write(&dac_inst, DAC_CHANNEL_0, 1023);
	delay_ms(1);
	/* Start an ADC conversion */
	adc_start_conversion(&adc_inst);
	while (adc_read(&adc_inst, &adc_result) != STATUS_OK) {
	}
	/* Test result */
	test_assert_true(test, adc_result > 4000,
			"Error in ADC conversion at 1V input");
}

/**
 * \internal
 * \brief Setup Function: ADC callback mode test.
 *
 * This function initializes the ADC result buffer and
 * registers & enables callback for the ADC buffer read.
 *
 * \param test Current test case.
 */
static void setup_adc_callback_mode_test(const struct test_case *test)
{
	interrupt_flag = false;
	/* Skip test if ADC initialization failed */
	test_assert_true(test, adc_init_success,
			"Skipping test due to failed initialization");
	
	/* Initialize ADC buffer */
	for (uint8_t i = 0; i < ADC_SAMPLES; i++) {
		adc_buf[i] = 0;
	}
	/* Register and enable buffer read callback */
	adc_register_callback(&adc_inst, adc_user_callback,
			ADC_CALLBACK_READ_BUFFER);
	adc_enable_callback(&adc_inst, ADC_CALLBACK_READ_BUFFER);
	/* Enable global interrupt */
	system_interrupt_enable_global();
}

/**
 * \internal
 * \brief ADC callback mode test function
 *
 * This test checks the callback functionality of the ADC driver.
 * ADC callback for buffered conversion is enabled.
 * Converted results are verified for expected results.
 *
 * \param test Current test case.
 */
static void run_adc_callback_mode_test(const struct test_case *test)
{
	uint16_t timeout_cycles = 10000;
	/* Set 0.5V DAC output */
	dac_chan_write(&dac_inst, DAC_CHANNEL_0, 512);
	delay_ms(1);
	/* Start ADC read */
	adc_read_buffer_job(&adc_inst, ADC_SAMPLES, adc_buf);

	do {
		timeout_cycles--;
		if (interrupt_flag) {
			break;
		}
	} while (timeout_cycles > 0);
	/* Test for timeout */
	test_assert_true(test, timeout_cycles > 0,
			"Timeout in ADC read");
	/* Test result */
	for (uint8_t i = 0; i < ADC_SAMPLES; i++) {
		test_assert_true(test, adc_buf[i] > 1990,
				"Error in ADC conversion for 0.5V at index %d", i);
	}
}

/**
 * \internal
 * \brief Cleanup Function: ADC callback mode test.
 *
 * This function clears the ADC result buffer and
 * unregisters & disables callback for the ADC buffer read.
 *
 * \param test Current test case.
 */
static void cleanup_adc_callback_mode_test(const struct test_case *test)
{
	/* Clear ADC buffer */
	for (uint8_t i = 0; i < ADC_SAMPLES; i++) {
		adc_buf[i] = 0;
	}
	/* Unregister & disable ADC read buffer callback */
	adc_unregister_callback(&adc_inst, ADC_CALLBACK_READ_BUFFER);
	adc_disable_callback(&adc_inst, ADC_CALLBACK_READ_BUFFER);
	/* Disable global interrupt */
	system_interrupt_disable_global();
}

/**
 * \internal
 * \brief Setup Function: ADC average mode test.
 *
 * This function initializes the ADC in averaging mode.
 *
 * \param test Current test case.
 */
static void setup_adc_average_mode_test(const struct test_case *test)
{
	enum status_code status = STATUS_ERR_IO;
	/* Skip test if ADC initialization failed */
	test_assert_true(test, adc_init_success,
			"Skipping test due to failed initialization");
			
	/* Disable ADC before initialization */
	adc_disable(&adc_inst);
	struct adc_config config;
	adc_get_config_defaults(&config);
	config.positive_input  = ADC_POSITIVE_INPUT_PIN2;
	config.reference       = ADC_REFERENCE_INT1V;
	config.clock_source    = GCLK_GENERATOR_3;
	config.gain_factor     = ADC_GAIN_FACTOR_1X;
	config.resolution      = ADC_RESOLUTION_16BIT;
	config.average_samples = ADC_AVERAGE_SAMPLES_16;
	/* Re-initialize & enable ADC */
	status = adc_init(&adc_inst, ADC, &config);
	test_assert_true(test, status == STATUS_OK,
			"ADC initialization failed");
	status = STATUS_ERR_IO;
	status = adc_enable(&adc_inst);
	test_assert_true(test, status == STATUS_OK,
			"ADC enabling failed");
}

/**
 * \internal
 * \brief ADC average mode test function
 *
 * This test performs the ADC averaging by starting a conversion.
 * 0.5V is applied as input from DAC.
 * Converted result is verified for expected results.
 *
 * \param test Current test case.
 */
static void run_adc_average_mode_test(const struct test_case *test)
{
	uint16_t adc_result = 0;
	/* Set 0.5V DAC output */
	dac_chan_write(&dac_inst, DAC_CHANNEL_0, 512);
	delay_ms(1);
	/* Start an ADC conversion */
	adc_start_conversion(&adc_inst);
	while (adc_read(&adc_inst, &adc_result) != STATUS_OK) {
	}
	adc_result = adc_result >> 4;
	/* Test result */
	test_assert_true(test, adc_result > 1990,
			"Error in ADC average mode conversion at 0.5V input");
}

/**
 * \internal
 * \brief Setup Function: ADC window mode test.
 *
 * This function initializes the ADC in window mode.
 * Upper and lower threshold values are provided.
 * It also registers & enables callback for window detection.
 *
 * \param test Current test case.
 */
static void setup_adc_window_mode_test(const struct test_case *test)
{
	uint16_t adc_result = 0;
	enum status_code status = STATUS_ERR_IO;
	interrupt_flag = false;
	/* Set 0.5V DAC output */
	dac_chan_write(&dac_inst, DAC_CHANNEL_0, 512);
	delay_ms(1);
	/* Skip test if ADC initialization failed */
	test_assert_true(test, adc_init_success,
			"Skipping test due to failed initialization");
	
	/* Disable ADC before initialization */
	adc_disable(&adc_inst);
	struct adc_config config;
	adc_get_config_defaults(&config);
	config.positive_input  = ADC_POSITIVE_INPUT_PIN2;
	config.reference       = ADC_REFERENCE_INT1V;
	config.clock_source    = GCLK_GENERATOR_3;
	config.gain_factor     = ADC_GAIN_FACTOR_1X;
	config.resolution      = ADC_RESOLUTION_12BIT;
	config.freerunning     = true;
	config.window.window_mode = ADC_WINDOW_MODE_BETWEEN_INVERTED;
	config.window.window_lower_value = 1990;
	config.window.window_upper_value = 2100;
	/* Re-initialize & enable ADC */
	status = adc_init(&adc_inst, ADC, &config);
	test_assert_true(test, status == STATUS_OK,
			"ADC initialization failed");
	status = STATUS_ERR_IO;
	status = adc_enable(&adc_inst);
	test_assert_true(test, status == STATUS_OK,
			"ADC enabling failed");
	
	/* Register and enable window mode callback */
	adc_register_callback(&adc_inst, adc_user_callback,
			ADC_CALLBACK_WINDOW);
	adc_enable_callback(&adc_inst, ADC_CALLBACK_WINDOW);
	adc_enable_interrupt(&adc_inst, ADC_INTERRUPT_WINDOW);
	/* Enable global interrupt */
	system_interrupt_enable_global();
	/* Start ADC conversion */
	adc_start_conversion(&adc_inst);
}

/**
 * \internal
 * \brief ADC window mode test function
 *
 * This test gives an input voltage outside the window and checks
 * whether the callback is triggered or not.
 *
 * \param test Current test case.
 */
static void run_adc_window_mode_test(const struct test_case *test)
{
	uint16_t adc_result = 0;
	uint16_t timeout_cycles = 10000;
	/* Set 1V DAC output */
	dac_chan_write(&dac_inst, DAC_CHANNEL_0, 1023);
	delay_ms(1);

	do {
		timeout_cycles--;
		if (interrupt_flag) {
			break;
		}
	} while (timeout_cycles > 0);
	test_assert_true(test, timeout_cycles > 0,
			"Timeout in window detection");
}

/**
 * \internal
 * \brief Cleanup Function: ADC window mode test.
 *
 * This function unregisters & disables callback for window detection.
 *
 * \param test Current test case.
 */
static void cleanup_adc_window_mode_test(const struct test_case *test)
{
	/* Unregister and disable window mode callback */
	adc_disable_interrupt(&adc_inst, ADC_INTERRUPT_WINDOW);
	adc_disable_callback(&adc_inst, ADC_CALLBACK_WINDOW);
	adc_unregister_callback(&adc_inst, ADC_CALLBACK_WINDOW);
	/* Disable global interrupt */
	system_interrupt_disable_global();
}

/**
 * \brief Run ADC unit tests
 *
 * Initializes the system and serial output, then sets up the
 * ADC unit test suite and runs it.
 */
int main(void)
{
	system_init();
	delay_init();
	cdc_uart_init();
	test_dac_init();

	/* Define Test Cases */
	DEFINE_TEST_CASE(adc_init_test, NULL,
			run_adc_init_test, NULL,
			"Testing ADC Initialization");

	DEFINE_TEST_CASE(adc_polled_mode_test, NULL,
			run_adc_polled_mode_test, NULL,
			"Testing ADC single ended mode by polling");

	DEFINE_TEST_CASE(adc_callback_mode_test,
			setup_adc_callback_mode_test,
			run_adc_callback_mode_test,
			cleanup_adc_callback_mode_test,
			"Testing ADC single ended mode by interrupt");

	DEFINE_TEST_CASE(adc_average_mode_test,
			setup_adc_average_mode_test,
			run_adc_average_mode_test, NULL,
			"Testing ADC average mode");

	DEFINE_TEST_CASE(adc_window_mode_test,
			setup_adc_window_mode_test,
			run_adc_window_mode_test,
			cleanup_adc_window_mode_test,
			"Testing ADC window mode");

	/* Put test case addresses in an array */
	DEFINE_TEST_ARRAY(adc_tests) = {
		&adc_init_test,
		&adc_polled_mode_test,
		&adc_callback_mode_test,
		&adc_average_mode_test,
		&adc_window_mode_test,
	};

	/* Define the test suite */
	DEFINE_TEST_SUITE(adc_test_suite, adc_tests,
			"SAM0 ADC driver test suite");

	/* Run all tests in the suite*/
	test_suite_run(&adc_test_suite);

	while (true) {
		/* Intentionally left empty */
	}
}
