/**
 * \file
 *
 * \brief SAM0+ Serial Peripheral Interface Driver
 *
 * Copyright (C) 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
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
#include "spi.h"

/**
 * \internal Resets the SERCOM SPI module
 *
 * \param dev_inst Pointer to the software instance struct
 */
void _spi_reset(struct spi_dev_inst *const dev_inst)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);

	SERCOM_t *const spi_module = dev_inst->hw_dev;

	/* Disable the module */
	spi_disable(dev_inst);

	/* Wait until the synchronization is complete */
	_spi_wait_for_sync(dev_inst);

	/* Software reset the module */
	spi_module->SPI.CTRLA |= SPI_SWRST_bm;
}

/**
 * \internal Writes an SPI SERCOM configuration to the hardware module.
 *
 * This function will write out a given configuration to the hardware module.
 * Can only be done when the module is disabled.
 *
 * \param[in] dev_inst  Pointer to the software instance struct
 * \param[in] config    Pointer to the configuration struct
 *
 * \return The status of the configuration
 * \retval STATUS_ERR_INVALID_ARG If invalid argument(s) were provided.
 * \retval STATUS_OK              If the configuration was written
 */
enum status_code _spi_set_config(struct spi_dev_inst *const dev_inst,
		struct spi_conf *config)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(config);
	Assert(dev_inst->hw_dev);

	SERCOM_t *const spi_module = dev_inst->hw_dev;

	dev_inst->mode = config->mode;
	dev_inst->chsize = config->chsize;

	/* Value to write to BAUD register */
	uint16_t baud;
	/* Value to write to CTRLA register */
	uint32_t ctrla;
	/* Status code */
	enum status_code err = STATUS_OK;

	/**
	 * \todo need to get reference clockspeed from conf struct and gclk_get_hz
	 */
	uint32_t external_clock;

	/* Find baud value and write it */
	if (config->mode == SPI_MODE_MASTER) {
		err = sercom_get_sync_baud_val(
				config->master.baudrate,
				external_clock, &baud);
		if (err != STATUS_OK) {
			/* Baud rate calculation error, return status code */
			return STATUS_ERR_INVALID_ARG;
		}
		spi_module->SPI.BAUD = (uint8_t)baud;
	}

	if (config->mode == SPI_MODE_MASTER) {
		/* Set module in master mode */
		ctrla = SPI_MASTER_bm;
	} else {
		/* Set frame format */
		ctrla = (config->slave.frame_format << SPI_FORM_gp);
		/* Set address mode */
		spi_module->SPI.CTRLB |= (config->slave.addr_mode << SPI_AMODE_gp);
		/* Set address and address mask*/
		spi_module->SPI.ADDR |= (config->slave.address
				<< SPI_ADDR_gp) | (config->slave.frame_format
				<< SPI_ADDRMASK_gp);
		if (config->slave.preload_enable) {
			/* Enable pre-loading of shift register */
			spi_module->SPI.CTRLB |= SPI_PLOADEN_bm;
		}
	}

	/* Set data order */
	ctrla |= config->data_order;

	/* Set clock polarity and clock phase */
	ctrla |= config->transfer_mode;

	/* Set mux setting */
	ctrla |= config->mux_setting;

	/* Set SPI character size */
	spi_module->SPI.CTRLB |= (config->chsize << SPI_CHSIZE_gp);

	if (config->sleep_enable) {
		/* Enable in sleep mode */
		ctrla |= SPI_SLEEPEN_bm;
	}

	if (config->receiver_enable) {
		/* Wait until the synchronization is complete */
		_spi_wait_for_sync(dev_inst);
		/* Enable receiver */
		spi_module->SPI.CTRLB |= SPI_RXEN_bm;
	}

	/* Write CTRLA register */
	spi_module->SPI.CTRLA = ctrla;

	return STATUS_OK;
}

/**
 * \brief Initializes the SERCOM SPI module
 *
 * This function will initialize the SERCOM SPI module, based on the values
 * of the config struct.
 *
 * \param[out] dev_inst   Pointer to the software instance struct
 * \param[in] module      Pointer to hardware instance
 * \param[in] config      Pointer to the config struct
 *
 * \return The status of the initialization
 * \retval STATUS_ERR_INVALID_ARG If invalid argument(s) were provided.
 * \retval STATUS_OK              If the initialization was done
 */
enum status_code spi_init(struct spi_dev_inst *const dev_inst, SERCOM_t *module,
		struct spi_conf *config)
{

	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(module);
	Assert(config);

	/* Initialize device instance */
	dev_inst->hw_dev = module;

	SERCOM_t *const spi_module = dev_inst->hw_dev;
	/* Reset the module */
	_spi_reset(dev_inst);

	/* Set the SERCOM in SPI mode */
	spi_module->SPI.CTRLA |= SERCOM_MODE_SPI_gc << SERCOM_MODE_gp;

	/* Write configuration to module and return status code */
	return _spi_set_config(dev_inst, config);
}

/**
 * \brief Reads buffer of \c length SPI characters
 *
 * This function will read a buffer of data from an SPI peripheral by sending
 * dummy SPI character if in master mode, or by waiting for data in slave mode.
 *
 * \note Data buffer for received data must be uint16_t and cast to uint8_t if
 * SPI character size is 9 bit.
 *
 * \param[in] dev_inst  Pointer to the software instance struct
 * \param[out] rx_data  Data buffer for received data
 * \param[in] length    Length of data to receive
 * \param[in] dummy     8- or 9-bit dummy byte to shift out in master mode
 *
 * \return Status of the read operation
 * \retval STATUS_OK              If the read was completed
 * \retval STATUS_ERR_INVALID_ARG If invalid argument(s) were provided.
 * \retval STATUS_ERR_TIMEOUT     If the operation was not completed within the
 *                                timeout in slave mode.
 */
enum status_code spi_read_buffer(struct spi_dev_inst *const dev_inst,
		uint8_t *rx_data, uint8_t length, uint16_t dummy)
{
//note kun 9 el 8
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);

	SERCOM_t *const spi_module = dev_inst->hw_dev;

	/* Sanity check arguments */
	if (length == 0) {
		return STATUS_ERR_INVALID_ARG;
	}

	uint8_t i = 0;
	uint16_t j = 0;
	while (length--) {
		if (dev_inst->mode == SPI_MODE_MASTER) {
			/* Wait until the module is ready to write a character */
			while (!spi_is_ready_to_write(dev_inst)) {
			}
			/* Send dummy SPI character to read in master mode */
			spi_write(dev_inst, dummy);
		} 

		/* Start timeout period for slave */
		if (dev_inst->mode == SPI_MODE_SLAVE) {
			for (j = 0; j <= 10000; j++) {
				if (spi_is_ready_to_read(dev_inst)) {
					break;
				} else if (j == 10000) {
					/* Not ready to read data within timeout period */
					return STATUS_ERR_TIMEOUT;
				}
			}
		}

		/* Wait until the module is ready to read a character */
		
		while (!spi_is_ready_to_read(dev_inst)) {
		}

		/* Read SPI character */
		spi_read(dev_inst, &(((uint16_t*)(rx_data))[i++]));
	}
	return STATUS_OK;
}

/**
 * \brief Sends a buffer of \c length SPI characters
 *
 * This function will send a buffer of SPI characters via the SPI
 * and discard any data that is received. To both send and receive a buffer of
 * data, use the \ref spi_tranceive_buffer function.
 *
 * Note that this function does not handle the _SS (slave select) pin(s) in
 * master mode; this must be handled by the user application.
 *
 * \note Data buffer to send must be of type uint16_t and cast to uint8_t if
 * SPI character size is 9 bit.
 *
 * \param[in] dev_inst  Pointer to the software instance struct
 * \param[in] data      Pointer to the buffer to transmit
 * \param[in] length    Number of SPI characters to transfer
 *
 * \return Status of the write operation
 * \retval STATUS_OK              If the write was completed
 * \retval STATUS_ERR_INVALID_ARG If invalid argument(s) were provided.
 * \retval STATUS_ERR_TIMEOUT     If the operation was not completed within the
 *                                timeout in slave mode.
 */
enum status_code spi_write_buffer(struct spi_dev_inst
		*const dev_inst, const uint8_t *tx_data, uint8_t length)
{
	/* Sanity check arguments */
	Assert(dev_inst);

	if (length == 0) {
		return STATUS_ERR_INVALID_ARG;
	}
	uint8_t i = 0;
	uint16_t j = 0;
	//timeout for slave []
	/* Write block */
	while (length--) {
		/* Start timeout period for slave */
		if (dev_inst->mode == SPI_MODE_SLAVE) {
			for (j = 0; j <= 10000; j++) {
				if (spi_is_ready_to_write(dev_inst)) {
					break;
				} else if (j == 10000) {
					/* Not ready to write data within timeout period */
					return STATUS_ERR_TIMEOUT;
				}
			}
		}

		/* Wait until the module is ready to write a character */
		while (!spi_is_ready_to_write(dev_inst)) {
		}

		if (dev_inst->chsize == SPI_CHARACTER_SIZE_9BIT) {
			/* Write the 9 bit character */
			spi_write(dev_inst, ((uint16_t*)(tx_data))[i++]);
		} else {
			/* Write 8 bit character*/
			spi_write(dev_inst, (uint16_t)tx_data[i++]);
		}
	}

	return STATUS_OK;
}

/**
 * \brief Sends and receives a buffer of \c length SPI characters
 *
 * This function will send and receive a buffer of data via the SPI.
 *
 * In master mode the SPI characters will be sent immediately and the
 * received SPI character will  be read as soon as the shifting of the SPI
 * character is complete.
 *
 * In slave mode this function will place the data to be sent into the transmit
 * buffer. It will then block until an SPI master has shifted the complete
 * buffer and the received data is available.
 *
 * \note Data buffer for receive data and data buffer to send must be of type
 * uint16_t and cast to uint8_t if SPI character size is 9 bit.
 *
 * \param[in] dev_inst Pointer to the software instance struct
 * \param[in] tx_data  Pointer to the buffer to transmit
 * \param[out] rx_data Pointer to the buffer where received data will be stored
 * \param[in] length   Number of SPI characters to transfer
 *
 * \return Status of the operation
 * \retval STATUS_OK              If the operation was completed
 * \retval STATUS_ERR_INVALID_ARG If invalid argument(s) were provided.
 * \retval STATUS_ERR_TIMEOUT     If the operation was not completed within the
 *                                timeout in slave mode.
 */
enum status_code spi_tranceive_buffer(struct spi_dev_inst *const dev_inst,
		uint8_t *tx_data, uint8_t *rx_data, uint8_t length)
{
	/* Sanity check arguments */
	Assert(dev_inst);

	/* Sanity check arguments */
	if (length == 0) {
		return STATUS_ERR_INVALID_ARG;
	}

	uint8_t i = 0;
	uint16_t j = 0;
	/* Send and receive buffer */
	while (length--) {
		/* Start timeout period for slave */
		if (dev_inst->mode == SPI_MODE_SLAVE) {
			for (j = 0; j <= 10000; j++) {
				if (spi_is_ready_to_write(dev_inst)) {
					break;
				} else if (j == 10000) {
					/* Not ready to write data within timeout period */
					return STATUS_ERR_TIMEOUT;
				}
			}
		}

		/* Wait until the module is ready to write a character */
		while (!spi_is_ready_to_write(dev_inst)) {
		}

		if (dev_inst->chsize == SPI_CHARACTER_SIZE_9BIT) {
			/* Write the 9 bit character */
			spi_write(dev_inst, ((uint16_t*)(tx_data))[i++]);
		} else {
			/* Write character */
			spi_write(dev_inst, (uint16_t)tx_data[i++]);
		}

		/* Start timeout period for slave */
		if (dev_inst->mode == SPI_MODE_SLAVE) {
			for (j = 0; j <= 10000; j++) {
				if (spi_is_ready_to_read(dev_inst)) {
					break;
				} else if (j == 10000) {
					/* Not ready to read data within timeout period */
					return STATUS_ERR_TIMEOUT;
				}
			}
		}
		
		/* Wait until the module is ready to read a character */
		while (!spi_is_ready_to_read(dev_inst)) {
		}
		/* Read the SPI character */
		spi_read(dev_inst, &(((uint16_t*)(rx_data))[i++]));
	}

	return STATUS_OK;
}
