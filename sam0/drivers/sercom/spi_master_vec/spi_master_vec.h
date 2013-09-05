/**
 * \file
 *
 * \brief SERCOM SPI master with vectored I/O driver include
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

#ifndef SPI_MASTER_VEC_H
#define SPI_MASTER_VEC_H

#include <compiler.h>
#include <gclk.h>
#include <port.h>
#include <status_codes.h>

/**
 * \defgroup sercom_spi_master_vec_group SERCOM SPI master driver with
 * vectored I/O
 *
 * This driver is a SPI master driver that supports uni- and bidirectional
 * transfers of 8-bit data with vectored I/O, also know as scatter/gather.
 * It does not implement slave selection or addressing since the intended usage
 * is in stacks which usually have their own protocols and handshaking schemes.
 *
 * Scatter/gather is implemented by the use of buffer descriptor arrays, which
 * must be passed to the driver to start a transfer.
 * See \ref spi_master_vec_transceive_buffer_job() for more information.
 *
 * @{
 */

/**
 * \name Configuration types and macros
 * @{
 */

/**
 * \def PINMUX_DEFAULT
 * \brief Specify that default pin MUX setting should be used for pad.
 *
 * \note If this specifier is used, it is up to the user to ensure that the
 * configuration does not try to use the same pin for another SERCOM pad.
 */
#ifndef PINMUX_DEFAULT
#  define PINMUX_DEFAULT 0
#endif

/**
 * \def PINMUX_UNUSED
 * \brief Specify that pin MUX should be skipped.
 */
#ifndef PINMUX_UNUSED
#  define PINMUX_UNUSED 0xFFFFFFFF
#endif

/** SERCOM pad multiplexing */
enum spi_master_vec_padmux_setting {
	/** SCK on pad 1, MOSI on pad 0, MISO on pad 2 */
	SPI_MASTER_VEC_PADMUX_SETTING_A =
			(0x0 << SERCOM_SPI_CTRLA_DOPO_Pos) |
			(0x2 << SERCOM_SPI_CTRLA_DIPO_Pos),
	/** SCK on pad 1, MOSI on pad 0, MISO on pad 3 */
	SPI_MASTER_VEC_PADMUX_SETTING_B =
			(0x0 << SERCOM_SPI_CTRLA_DOPO_Pos) |
			(0x3 << SERCOM_SPI_CTRLA_DIPO_Pos),
	/** SCK on pad 3, MOSI on pad 2, MISO on pad 0 */
	SPI_MASTER_VEC_PADMUX_SETTING_C =
			(0x1 << SERCOM_SPI_CTRLA_DOPO_Pos) |
			(0x0 << SERCOM_SPI_CTRLA_DIPO_Pos),
	/** SCK on pad 3, MOSI on pad 2, MISO on pad 1 */
	SPI_MASTER_VEC_PADMUX_SETTING_D =
			(0x1 << SERCOM_SPI_CTRLA_DOPO_Pos) |
			(0x1 << SERCOM_SPI_CTRLA_DIPO_Pos),
};

/** SPI transfer mode. */
enum spi_master_vec_transfer_mode {
	/** Mode 0. Leading edge: rising, sample. Trailing edge: falling, setup. */
	SPI_MASTER_VEC_TRANSFER_MODE_0 = 0,
	/** Mode 1. Leading edge: rising, setup. Trailing edge: falling, sample. */
	SPI_MASTER_VEC_TRANSFER_MODE_1 = SERCOM_SPI_CTRLA_CPHA,
	/** Mode 2. Leading edge: falling, sample. Trailing edge: rising, setup. */
	SPI_MASTER_VEC_TRANSFER_MODE_2 = SERCOM_SPI_CTRLA_CPOL,
	/** Mode 3. Leading edge: falling, setup. Trailing edge: rising, sample. */
	SPI_MASTER_VEC_TRANSFER_MODE_3 = SERCOM_SPI_CTRLA_CPHA | SERCOM_SPI_CTRLA_CPOL,
};

/** SPI data transfer order. */
enum spi_master_vec_data_order {
	/** LSB of data is transmitted first. */
	SPI_MASTER_VEC_DATA_ORDER_LSB  = SERCOM_SPI_CTRLA_DORD,
	/** MSB of data is transmitted first. */
	SPI_MASTER_VEC_DATA_ORDER_MSB  = 0,
};

/**
 * \brief Driver configuration structure
 *
 * \note There are two layers of multiplexing for the SPI signals: first the
 * pad MUX in the SERCOM, and then the pin MUX in the PORT. This means that
 * \c padmux_setting must be set in combination with the \c pinmux_padN.
 * And for \ref spi_master_vec_init() to function properly, the order of the
 * values in \c pinmux_padN must be correct, i.e., \c pinmux_pad0 must contain
 * the pin MUX setting for multiplexing SERCOM pad 0, and so on.
 */
struct spi_master_vec_config {
	/** Baud rate in Hertz. */
	uint32_t baudrate;
	/** GCLK generator to use for the SERCOM. */
	enum gclk_generator gclk_generator;
	/** SERCOM Pad MUX setting. */
	enum spi_master_vec_padmux_setting padmux_setting;
	/** Transfer mode. */
	enum spi_master_vec_transfer_mode transfer_mode;
	/** Data order. */
	enum spi_master_vec_data_order data_order;
	/** Pin MUX setting for SERCOM pad 0. */
	uint32_t pinmux_pad0;
	/** Pin MUX setting for SERCOM pad 1. */
	uint32_t pinmux_pad1;
	/** Pin MUX setting for SERCOM pad 2. */
	uint32_t pinmux_pad2;
	/** Pin MUX setting for SERCOM pad 4. */
	uint32_t pinmux_pad3;
};

/** @} */

/**
 * \name Buffer description
 * @{
 */

/** Buffer length container. */
typedef uint16_t spi_master_vec_buflen_t;

/** Buffer descriptor structure. */
struct spi_master_vec_bufdesc {
	uint8_t *data;
	spi_master_vec_buflen_t length;
};

/** @} */

/**
 * \internal
 * \brief Transfer direction.
 */
enum _spi_master_vec_direction {
	SPI_MASTER_VEC_DIRECTION_READ,
	SPI_MASTER_VEC_DIRECTION_WRITE,
	SPI_MASTER_VEC_DIRECTION_BOTH,
	SPI_MASTER_VEC_DIRECTION_IDLE,
};

/** Driver instance. */
struct spi_master_vec_module {
	Sercom *volatile sercom;
	volatile enum _spi_master_vec_direction direction;
	volatile enum status_code status;
	volatile spi_master_vec_buflen_t rx_length;
	volatile spi_master_vec_buflen_t tx_length;
	uint8_t *volatile rx_head_ptr;
	uint8_t *volatile tx_head_ptr;
	volatile uint_fast8_t tx_lead_on_rx;
	struct spi_master_vec_bufdesc *volatile rx_bufdesc_ptr;
	struct spi_master_vec_bufdesc *volatile tx_bufdesc_ptr;
};

/**
 * \brief Initialize configuration with default values.
 *
 * \param[out] config Configuration struct to initialize.
 */
static inline void spi_master_vec_get_config_defaults(
		struct spi_master_vec_config *const config)
{
	config->baudrate = 100000;
	config->gclk_generator = GCLK_GENERATOR_0;
	config->padmux_setting = SPI_MASTER_VEC_PADMUX_SETTING_D;
	config->transfer_mode = SPI_MASTER_VEC_TRANSFER_MODE_0;
	config->data_order = SPI_MASTER_VEC_DATA_ORDER_MSB;
	config->pinmux_pad0 = PINMUX_DEFAULT;
	config->pinmux_pad1 = PINMUX_DEFAULT;
	config->pinmux_pad2 = PINMUX_DEFAULT;
	config->pinmux_pad3 = PINMUX_DEFAULT;
}

/**
 * \brief Get current status of instance.
 *
 * \param[in] module Driver instance to operate on.
 *
 * \retval \c STATUS_OK if idle and previous transfer succeeded.
 * \retval \c STATUS_BUSY if a transfer is ongoing.
 * \return Other status codes upon failure.
 */
static inline enum status_code spi_master_vec_get_job_status(
		const struct spi_master_vec_module *const module)
{
	return module->status;
}

#ifdef __cplusplus
extern "C" {
#endif

enum status_code spi_master_vec_init(struct spi_master_vec_module *const module,
		Sercom *const sercom, struct spi_master_vec_config *const config);
void spi_master_vec_enable(const struct spi_master_vec_module *const module);
void spi_master_vec_disable(const struct spi_master_vec_module *const module);
enum status_code spi_master_vec_transceive_buffer_job(
		struct spi_master_vec_module *const module,
		struct spi_master_vec_bufdesc tx_bufdescs[],
		struct spi_master_vec_bufdesc rx_bufdescs[]);
void spi_master_vec_reset(const struct spi_master_vec_module *const module);
#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* SPI_MASTER_VEC_H */