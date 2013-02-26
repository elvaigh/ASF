/**
 *
 * \file
 *
 * \brief SAMD20 SERCOM USART Driver
 *
 * Copyright (C) 2012-2013 Atmel Corporation. All rights reserved.
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
#ifndef USART_H_INCLUDED
#define USART_H_INCLUDED

#ifndef PINMUX_DEFAULT
#define PINMUX_DEFAULT 0xFFFFFFFF
#endif

#include <sercom.h>

#ifdef USART_ASYNC
#include <sercom_interrupt.h>
#endif

#define USART_DEFAULT_TIMEOUT  0xFFFF

/**
 * \defgroup asfdoc_samd20_sercom_usart_group SAMD20 USART driver
 * This driver for the SAMD20 provides an interface to configure
 * and use the SERCOM in its USART mode to transfer or receive
 * USART dataframes.
 *
 * The following peripherals are used by this module:
 *
 * - SERCOM (Serial Communication Interface)
 *
 * The outline of this documentation is as follows:
 * - \ref asfdoc_samd20_sercom_usart_prerequisites
 * - \ref asfdoc_samd20_sercom_usart_overview
 * - \ref asfdoc_samd20_sercom_usart_special_considerations
 * - \ref asfdoc_samd20_sercom_usart_extra_info
 * - \ref asfdoc_samd20_sercom_usart_examples
 * - \ref asfdoc_samd20_sercom_usart_api_overview
 * - \ref asfdoc_samd20_sercom_usart_async
 *
 * \section asfdoc_samd20_sercom_usart_prerequisites Prerequisites
 *
 * To use the USART you need to have a GCLK generator enabled and running
 * that can be used as the SERCOM clock source. This can either be configured
 * in conf_clock.h or by using the system clock driver.
 *
 * \section asfdoc_samd20_sercom_usart_overview Module Overview
 *
 * This driver will use one (or more) SERCOM interfaces on the system
 * and configure it to run as a USART interface in either synchronous
 * or asynchronous mode.
 *
 * \subsection asfdoc_samd20_sercom_usart_overview_frame_format
 *
 * Communication is based on frames, where the frame format can be customized
 * to accomodate a wide range of standards. A frame consists of a start bit,
 * a number of data bits, an optional parity bit for error detection as well
 * as a configurable length stop bit(s).
 * The table below shows the available parameters you can change in a frame
 * <table>
 *  <tr>
 *      <th>Parameter</th>
 *      <th>Available Options</th>
 *  </tr>
 *  <tr>
 *      <th>Start bit</th>
 *      <td>1</td>
 *  </tr>
 *  <tr>
 *      <th>Data bits</th>
 *      <td>5, 6, 7, 8, 9</td>
 *  </tr>
 *  <tr>
 *      <th>Parity bit</th>
 *      <td>None, Even, Odd</td>
 *  </tr>
 *  <tr>
 *      <th>Stop bits</th>
 *      <td>1, 2</td>
 *  </tr>
 * </table>
 * \par Frame layout
 * <table>
 *  <tr>
 *      <th>Start bit</th>
 *      <th>Data bits</th>
 *      <th>(Parity bit)</th>
 *      <th>Stop bit(s)</th>
 *  </tr>
 *  <tr>
 *      <td>1</td>
 *      <td>5-9</td>
 *      <td>1</td>
 *      <td>1-2</td>
 *  </tr>
 * </table>
 *
 * \subsection asfdoc_samd20_sercom_usart_overview_sync Synchronous mode
 *
 * In synchronous mode a dedicated clock line is provided; either by the USART
 * itself if in master mode, or by an external master if in slave mode.
 * Maximum transmission speed is the same as the GCLK clocking the USART
 * peripheral when in slave mode, and the GCLK divided by two if in
 * master mode. In synchronous mode the interface needs three lines to
 * communicate:
 * - TX (Transmit pin)
 * - RX (Receive pin)
 * - XCK (Clock pin)
 *
 * \subsubsection asfdoc_samd20_sercom_usart_overview_sync_sampling Data sampling
 * In synchronous mode the data is sampled on either the rising or falling edge
 * of the clock signal. This is configured by setting the clock polarity in the
 * configuration struct.
 *
 * \subsection asfdoc_samd20_sercom_usart_overview_async Asynchronous mode
 *
 * In asynchronous mode no dedicated clock line is used, and the communication
 * is based on matching the clock speed on the transmitter and receiver. The
 * clock is generated from the internal SERCOM baudrate generator, and the
 * frames are synchronized by using the frame start bits. Maximum transmission
 * speed is limited to the SERCOM GCLK divided by 16.
 * In asynchronous mode the interface only needs to lines to communicate:
 * - TX (Transmit pin)
 * - RX (Receive pin)
 *
 * \subsubsection asfdoc_samd20_sercom_usart_overview_async_clock matching Transmitter/receiver clock matching
 *
 * For successfull transmit and receive using the asynchronous mode the receiver
 * and transmitter clocks needs to be closely matched. When receiving a frame
 * that does not match the selected baud rate closely enough the receiver will
 * be unable synchronize the frame(s), and garbage transmissions will result.
 *
 * \subsection asfdoc_samd20_sercom_usart_overview_pin_configuration GPIO configuration
 *
 * the SERCOM module have four internal PADS where the RX pin can be placed at all
 * the PADS, and the TX and XCK pins have two predefined positions that can be changed.
 * The PADS can then be routed to an external GPIO pin using the normal pin
 * multiplxing scheme on the SAMD20.
 *
 * \section asfdoc_samd20_sercom_usart_special_considerations Special considerations
 *
 * \section asfdoc_samd20_sercom_usart_extra_info Extra Information
 *
 * For extra information see \ref asfdoc_samd20_sercom_usart_extra. This includes:
 * - \ref asfdoc_samd20_sercom_usart_extra_acronyms
 * - \ref asfdoc_samd20_sercom_usart_extra_dependencies
 * - \ref asfdoc_samd20_sercom_usart_extra_errata
 * - \ref asfdoc_samd20_sercom_usart_extra_history
 *
 * \section asfdoc_samd20_sercom_usart_examples Examples
 *
 * The following Quick Start guides and application examples are available for this driver:
 * - \ref asfdoc_samd20_sercom_usart_basic_use_case
 *
 * \section asfdoc_samd20_sercom_usart_api_overview
 * @{
 */

/**
 * \brief USART Callback enum
 *
 * Callbacks for the Asynchronous USART driver
 *
 */
/* TODO: Add support for RX started interrupt. */
#ifdef USART_ASYNC
enum usart_callback {
	/** Callback for buffer transmitted */
	USART_CALLBACK_BUFFER_TRANSMITTED,
	/** Callback for buffer received */
	USART_CALLBACK_BUFFER_RECEIVED,
	/** Callback for error */
	USART_CALLBACK_ERROR,
#if !defined(__DOXYGEN__)
	/** Number of available callbacks. */
	USART_CALLBACK_N,
#endif
};
#endif

/**
 * \brief USART Dataorder enum
 *
 * The dataorder decides which of MSB or LSB
 * is shifted out first when data is transferred
 */
enum usart_dataorder {
	/** The MSB will be shifted out first during transmission,
	 *  and shifted in first during reception */
	USART_DATAORDER_MSB = 0,
	/** The LSB will be shifted out first during transmission,
	 *  and shifted in first during reception */
	USART_DATAORDER_LSB = SERCOM_USART_CTRLA_DORD,
};

/**
 * \brief USART Transfer mode enum
 *
 *
 */
enum usart_transfer_mode {
	/* Transfer of data is done synchronously */
	USART_TRANSFER_SYNCHRONOUSLY = (SERCOM_USART_CTRLA_CMODE),
	/* Transfer of data is done asynchronously */
	USART_TRANSFER_ASYNCHRONOUSLY = 0
};

/**
 * \brief USART Parity enum
 *
 * Parity is enabled for error checking of the data transferred. If even parity
 * is selected, the parity bit will be set if number of ones being transferred
 * is odd. If odd parity is selected, the parity bit will be set if number of
 * ones being transferred is even.
 *
 */
enum usart_parity {
	/** For odd parity checking, the parity bit will be set if number of
	 *  ones being transferred is even */
	USART_PARITY_ODD  = SERCOM_USART_CTRLB_PMODE,

	/** For even parity checking, the parity bit will be set if number of
	 *  ones being received is odd */
	USART_PARITY_EVEN = 0,

	/** No parity checking will be executed, and there will be no parity bit
	 *  in the received frame */
	USART_PARITY_NONE = 0xFF,
};

/**
 * \brief USART signal mux settings
 *
 * Set the functionality of the SERCOM pins.
 * TODO: As not all settings can be used in different modes of operation, proper
 * settings must be chosen according to the rest of the configuration.
 *
 */
/* TODO: rename to mux_settings_a-h */
enum usart_signal_mux_settings {
	/** See \ref mux_setting_a */
	USART_RX_0_TX_0_XCK_1 = (SERCOM_USART_CTRLA_RXPO(0)),
	/** See \ref mux_setting_b */
	USART_RX_0_TX_2_XCK_3
		= (SERCOM_USART_CTRLA_RXPO(0) |
			SERCOM_USART_CTRLA_TXPO),
	/** See \ref mux_setting_c */
	USART_RX_1_TX_0_XCK_1 = (SERCOM_USART_CTRLA_RXPO(1)),
	/** See \ref mux_setting_d */
	USART_RX_1_TX_2_XCK_3
		= (SERCOM_USART_CTRLA_RXPO(1) |
			SERCOM_USART_CTRLA_TXPO),
	/** See \ref mux_setting_e */
	USART_RX_2_TX_0_XCK_1 = (SERCOM_USART_CTRLA_RXPO(2)),
	/** See \ref mux_setting_f */
	USART_RX_2_TX_2_XCK_3
		= (SERCOM_USART_CTRLA_RXPO(2) |
			SERCOM_USART_CTRLA_TXPO),
	/** See \ref mux_setting_g */
	USART_RX_3_TX_0_XCK_1 = (SERCOM_USART_CTRLA_RXPO(3)),
	/** See \ref mux_setting_h */
	USART_RX_3_TX_2_XCK_3
		= (SERCOM_USART_CTRLA_RXPO(3) |
			SERCOM_USART_CTRLA_TXPO),
};

/**
 * \brief USART Stop Bits enum
 *
 * Number of stop bits for a frame.
 *
 */
enum usart_stopbits {
	/** Each transferred frame contains 1 stop bit */
	USART_STOPBITS_1 = 0,
	/** Each transferred frame contains 2 stop bits */
	USART_STOPBITS_2 = SERCOM_USART_CTRLB_SBMODE,
};

/**
 * \brief USART Character Size
 *
 * Number of bits for the character sent in a frame.
 *
 */
enum usart_char_size {
	/** The char being sent in a frame is 5 bits long */
	USART_CHAR_SIZE_5BIT = SERCOM_USART_CTRLB_CHSIZE(5),
	/** The char being sent in a frame is 6 bits long */
	USART_CHAR_SIZE_6BIT = SERCOM_USART_CTRLB_CHSIZE(6),
	/** The char being sent in a frame is 7 bits long */
	USART_CHAR_SIZE_7BIT = SERCOM_USART_CTRLB_CHSIZE(7),
	/** The char being sent in a frame is 8 bits long */
	USART_CHAR_SIZE_8BIT = SERCOM_USART_CTRLB_CHSIZE(0),
	/** The char being sent in a frame is 9 bits long */
	USART_CHAR_SIZE_9BIT = SERCOM_USART_CTRLB_CHSIZE(1),
};


/**
 * \brief USART Transceiver Mode
 *
 * States if a parameter is for the RX or TX line
 *
 */
enum usart_transceiver_type {
	/** The parameter is for the receiver/reception/read */
	USART_TRANSCEIVER_RX,
	/** The parameter is for the transmitter/transmission/write */
	USART_TRANSCEIVER_TX,
};

/**
 * \name USART configuration struct
 * \note Configuration options for USART
 */
struct usart_config {
	/** USART bit order (MSB or LSB first) */
	enum usart_dataorder data_order;
	/** USART in asynchronous or synchronous mode */
	enum usart_transfer_mode transfer_mode;
	/** USART parity */
	enum usart_parity parity;
	/** Number of stop bits */
	enum usart_stopbits stopbits;
	/** USART character size */
	enum usart_char_size char_size;
	/** USART pin out */
	enum usart_signal_mux_settings mux_settings;
	/** USART baud rate */
	uint32_t baudrate;

	/** USART Clock Polarity
	 * If true, data changes on falling XCK edge and
	 * is sampled at rising edge
	 * If false, data changes on rising XCK edge and
	 * is sampled at falling edge
	 * */
	bool clock_polarity_inverted;

	/** States whether to use the external clock applied to the XCK pin.
	 * In SYNC mode the shift register will act directly on the XCK clock.
	 * In ASYNC mode the XCK will be the input to the USART hardware module.
	 */
	bool use_external_clock;

	/** External clock frequency in synchronous mode.
	 * Must be given if clock source (XCK) is set to external. */
	uint32_t ext_clock_freq;
	/** Generator source for the clock used by USART */
	/* enum gclk_generator generator_source; */
	/** If true the clock used by USART will run in standby mode */
	bool run_in_standby;
	/** GCLK generator source */
	enum gclk_generator generator_source;
	/** PAD0 Pinout */
	uint32_t pinout_pad0;
	/** PAD0 Pinout */
	uint32_t pinout_pad1;
	/** PAD0 Pinout */
	uint32_t pinout_pad2;
	/** PAD0 Pinout */
	uint32_t pinout_pad3;
};

#ifdef USART_ASYNC
/* Prototype for the device instance */
struct usart_module;

/* Type of the callback functions */
typedef void (*usart_callback_t)(const struct usart_module *const
		module);
#endif

/**
 * \name USART device struct
 * \note Device information for USART
 */
struct usart_module {
	/** Pointer to the hardware instance */
	Sercom *hw;
	/** Character size of the data being transferred */
	enum usart_char_size char_size;
#ifdef USART_ASYNC
	/** Array to store callback function pointers in */
	usart_callback_t callback[USART_CALLBACK_N];
	/** Buffer pointer to where the next received character will be put */
	volatile uint8_t *rx_buffer_ptr;

	/** Buffer pointer to where the next character will be transmitted from
	**/
	volatile uint8_t *tx_buffer_ptr;
	/** Remaining characters to receive */
	volatile uint16_t remaining_rx_buffer_length;
	/** Remaining characters to transmit */
	volatile uint16_t remaining_tx_buffer_length;
	/** Bit mask for callbacks registered */
	uint8_t callback_reg_mask;
	/** Bit mask for callbacks enabled */
	uint8_t callback_enable_mask;
	/** Holds the status of the ongoing or last read operation */
	volatile enum status_code rx_status;
	/** Holds the status of the ongoing or last write operation */
	volatile enum status_code tx_status;
#endif
};

#if !defined (__DOXYGEN__)

/**
 * \internal Wait until synchronization is complete
 */
static inline void _usart_wait_for_sync(const struct usart_module
		*const module)
{
	/* Get a pointer to the hardware module instance */
	SercomUsart *const usart_hw = &(module->hw->USART);

	/* Wait until the synchronization is complete */
	while (usart_hw->STATUS.reg & SERCOM_USART_STATUS_SYNCBUSY) {
		/* Intentionally left empty */
	}
}

#endif

static inline bool usart_is_syncing(const struct usart_module *const module)
{
	/* Sanity check arguments */
	Assert(module);
	Assert(module->hw);

	SercomUsart *const usart_hw = &(module->hw->USART);

	if(usart_hw->STATUS.reg & SERCOM_USART_STATUS_SYNCBUSY) {
		return true;
	} else {
		return false;
	}
}

/**
 * \brief Initializes the device to predefined defaults
 *
 * Initialize the USART device to predefined defaults:
 * - 8-bit asynchronous USART
 * - no parity
 * - 1 stop bit
 * - 9600 baud
 *
 * The configuration struct will be updated with the default
 * configuration.
 *
 * \param[out] module Pointer to configuration struc
 *
 */
static inline void usart_get_config_defaults(struct usart_config *const config)
{
	/* Sanity check arguments */
	Assert(config);

	/* Set default config in the config struct */
	config->data_order = USART_DATAORDER_LSB;
	config->transfer_mode = USART_TRANSFER_ASYNCHRONOUSLY;
	config->parity = USART_PARITY_NONE;
	config->stopbits = USART_STOPBITS_1;
	config->char_size = USART_CHAR_SIZE_8BIT;
	config->baudrate = 9600;
	config->clock_polarity_inverted = false;
	config->use_external_clock = false;
	config->ext_clock_freq = 0;
	config->mux_settings = USART_RX_1_TX_2_XCK_3;
	config->run_in_standby = false;
	config->generator_source = GCLK_GENERATOR_0;
	config->pinout_pad0 = PINMUX_DEFAULT;
	config->pinout_pad1 = PINMUX_DEFAULT;
	config->pinout_pad2 = PINMUX_DEFAULT;
	config->pinout_pad3 = PINMUX_DEFAULT;
}

enum status_code usart_init(struct usart_module *const module,
		Sercom *const hw, const struct usart_config *const config);

/**
 * \brief Enable the module
 *
 * Enables the USART module
 *
 * \param[in] module Pointer to USART software instance struct
 *
 */
static inline void usart_enable(const struct usart_module *const module)
{
	/* Sanity check arguments */
	Assert(module);
	Assert(module->hw);

	/* Get a pointer to the hardware module instance */
	SercomUsart *const usart_hw = &(module->hw->USART);

	/* Enable Global interrupt for module */
	system_interrupt_enable(_sercom_get_interrupt_vector(module->hw));

	/* Wait until synchronization is complete */
	_usart_wait_for_sync(module);

	/* Enable USART module */
	usart_hw->CTRLA.reg |= SERCOM_USART_CTRLA_ENABLE;
}

/**
 * /brief Disable module
 *
 * Disables the USART module
 *
 * \param[in] module Pointer to USART software instance struct
 */
static inline void usart_disable(const struct usart_module *const module)
{
	/* Sanity check arguments */
	Assert(module);
	Assert(module->hw);

	/* Get a pointer to the hardware module instance */
	SercomUsart *const usart_hw = &(module->hw->USART);

	/* Enable Global interrupt for module */
	system_interrupt_disable(_sercom_get_interrupt_vector(module->hw));

	/* Wait until synchronization is complete */
	_usart_wait_for_sync(module);

	/* Disable USART module */
	usart_hw->CTRLA.reg &= ~SERCOM_USART_CTRLA_ENABLE;
}

/**
 * \brief Resets the USART module
 *
 * Disables and resets the USART module.
 *
 * \param[in] module Pointer to the USART software instance struct
 *
 */
static inline void usart_reset(const struct usart_module *const module)
{
	/* Sanity check arguments */
	Assert(module);
	Assert(module->hw);

	/* Get a pointer to the hardware module instance */
	SercomUsart *const usart_hw = &(module->hw->USART);

	usart_disable(module);

	/* Wait until synchronization is complete */
	_usart_wait_for_sync(module);

	/* Reset module */
	usart_hw->CTRLA.reg = SERCOM_USART_CTRLA_SWRST;
}

/**
 * \name Writing and reading
 * {@
 */
/* TODO: Would it be enough with write/read_buffer? */
enum status_code usart_write_wait(struct usart_module *const module,
		const uint16_t tx_data);

enum status_code usart_read_wait(struct usart_module *const module,
		uint16_t *const rx_data);

enum status_code usart_write_buffer_wait(struct usart_module *const module,
		const uint8_t *tx_data, uint16_t length);

enum status_code usart_read_buffer_wait(struct usart_module *const module,
		const uint8_t *rx_data, uint16_t length);

/**
 * @}
 */

/**
 * \name Enabling/Disabling receiver and transmitter
 * {@
 */

/**
 * \brief Enable Transceiver
 *
 * Enable the given transceiver. Either RX or TX.
 *
 * \param[in] module   Pointer to USART software instance struct
 * \param[in] transceiver_type  Transceiver type.
 */
static inline void usart_enable_transceiver(const struct usart_module
		*const module,
		enum usart_transceiver_type transceiver_type)
{
	/* Sanity check arguments */
	Assert(module);
	Assert(module->hw);

	/* Get a pointer to the hardware module instance */
	SercomUsart *const usart_hw = &(module->hw->USART);

	/* Wait until synchronization is complete */
	_usart_wait_for_sync(module);

	switch (transceiver_type) {
	case USART_TRANSCEIVER_RX:
		/* Enable RX */
		usart_hw->CTRLB.reg |= SERCOM_USART_CTRLB_RXEN;
		break;

	case USART_TRANSCEIVER_TX:
		/* Enable TX */
		usart_hw->CTRLB.reg |= SERCOM_USART_CTRLB_TXEN;
		break;
	}
}

/**
 * \brief Disable Transceiver
 *
 * Disable the given transceiver. Either RX or TX.
 *
 * \param[in] module          Pointer to USART software instance struct
 * \param[in] transceiver_type  Transceiver type.
 */
static inline void usart_disable_transceiver(const struct usart_module
		*const module,
		enum usart_transceiver_type transceiver_type)
{
	/* Sanity check arguments */
	Assert(module);
	Assert(module->hw);

	/* Get a pointer to the hardware module instance */
	SercomUsart *const usart_hw = &(module->hw->USART);

	/* Wait until synchronization is complete */
	_usart_wait_for_sync(module);

	switch (transceiver_type) {
	case USART_TRANSCEIVER_RX:
		/* Disable RX */
		usart_hw->CTRLB.reg &= ~SERCOM_USART_CTRLB_RXEN;
		break;

	case USART_TRANSCEIVER_TX:
		/* Disable TX */
		usart_hw->CTRLB.reg &= ~SERCOM_USART_CTRLB_TXEN;
		break;
	}
}

/*
 * @}
 */
/**
* \page asfdoc_samd20_sercom_usart_extra Extra Information
*
* \section asfdoc_samd20_sercom_usart_extra_acronyms Acronyms
* Below is a table listing the acronyms used in this module, along with their
* intended meanings.
*
* <table>
* <tr>
* <th>Acronym</th>
* <th>Description</th>
* </tr>
* <tr>
* <td>SERCOM</td>
* <td>Serial Communication interface</td>
* </tr>
* <tr>
* <td>USART</td>
* <td>Universal Synchronous and Asynchronous Serial Receiver and Transmitter</td>
* </tr>
* <tr>
* <td>LSB</td>
* <td>Least Significant Bit</td>
* </tr>
* <tr>
* <td>MSB</td>
* <td>Most Significant Bit</td>
* </tr>
* </table>
*
*
* \section asfdoc_samd20_sercom_usart_extra_dependencies Dependencies
* This driver has the following dependencies:
*
* - \ref asfdoc_samd20_pinmux_group "System Pin Multiplexer Driver"
* - \ref asfdoc_samd20_system_clock_group "System clock configuration"
*
*
* \section asfdoc_samd20_sercom_usart_extra_errata Errata
* There are no errata related to this driver.
*
*
* \section asfdoc_samd20_sercom_usart_extra_history Module History
* An overview of the module history is presented in the table below, with
* details on the enhancements and fixes made to the module since its first
* release. The current version of this corresponds to the newest version in
* the table.
*
* <table>
* <tr>
* <th>Changelog</th>
* </tr>
* <tr>
* <td>Initial Release</td>
* </tr>
* </table>
*/

#endif /* USART_H_INCLUDED */
