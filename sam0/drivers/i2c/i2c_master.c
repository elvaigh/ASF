/**
 * \file
 *
 * \brief I2C Master Driver
 *
 * Copyright (C) 2012-2015 Atmel Corporation. All rights reserved.
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <stdint.h>
#include <string.h>
#include <asf.h>
#include "i2c_master.h"

#if I2C_MASTER_CALLBACK_MODE == true
//# include "i2c_master_interrupt.h"
#endif

/* Forward declaration */
enum i2c_status_code _i2c_master_wait_for_bus(
		struct i2c_master_module *const module);

enum i2c_status_code _i2c_master_address_response(
		struct i2c_master_module *const module);

#if !defined(__DOXYGEN__)

/**
 * \internal Sets configurations to module
 *
 * \param[out] module  Pointer to software module structure
 * \param[in]  config  Configuration structure with configurations to set
 *
 * \return Status of setting configuration.
 * \retval I2C_STATUS_OK                        If module was configured correctly
 * \retval I2C_STATUS_ERR_ALREADY_INITIALIZED   If setting other GCLK generator than
 *                                          previously set
 * \retval I2C_STATUS_ERR_BAUDRATE_UNAVAILABLE  If given baud rate is not compatible
 *                                          with set GCLK frequency
 */
static enum i2c_status_code _i2c_master_set_config(
		struct i2c_master_module *const module,
		const struct i2c_master_config *const config)
{
	enum i2c_status_code status;
	I2C *const i2c_module = (module->hw);
	
	status = _i2c_set_config(i2c_module,(uint16_t *)config->pinmux_pad, config->baud_rate, config->clock_source);
	i2c_module->I2C_MASTER_MODE.bit.MASTER_ENABLE = I2C_I2C_MASTER_MODE_MASTER_ENABLE_1;
	
	return status;
}
#endif /* __DOXYGEN__ */

enum i2c_status_code i2c_master_lock(
		struct i2c_master_module *const module)
{
	enum i2c_status_code status;

	//system_interrupt_enter_critical_section();

	if (module->locked) {
		status = I2C_STATUS_BUSY;
	} else {
		module->locked = true;
		status = I2C_STATUS_OK;
	}

	//system_interrupt_leave_critical_section();

	return status;
}

void i2c_master_unlock(struct i2c_master_module *const module)
{
	module->locked = false;
}

/**
 * \brief Returns the activity status of the module
 *
 * Returns the activity status of the module.
 *
 * \param[in]  module  Pointer to software module structure
 *
 * \return Status of the synchronization.
 * \retval true   Module is active 
 * \retval false  Module is not active
 */
static inline bool i2c_master_is_active (
		const struct i2c_master_module *const module)
{
	/* Sanity check. */
	//Assert(module);
	//Assert(module->hw);
	
	I2C *const i2c_hw = (module->hw);
	return (i2c_hw->I2C_STATUS.bit.I2C_ACTIVE);
}


/**
 * \internal
 * Wait for hardware module to sync
 *
 * \param[in]  module  Pointer to software module structure
 */
static void _i2c_master_wait_for_idle(
		const struct i2c_master_module *const module)
{
	/* Sanity check. */
	//Assert(module);

	while (i2c_master_is_active(module)) {
		/* Wait for I2C module to sync. */
	}
}

/**
 * \brief Enables the I<SUP>2</SUP>C module
 *
 * Enables the requested I<SUP>2</SUP>C module and set the bus state to IDLE
 * after the specified \ref asfdoc_sam0_sercom_i2c_timeout "timeout" period if no
 * stop bit is detected.
 *
 * \param[in]  module  Pointer to the software module struct
 */
static inline void i2c_master_enable(
		const struct i2c_master_module *const module)
{
	I2C *const i2c_module = (module->hw);

	/* Wait for module to sync. */
	_i2c_master_wait_for_idle(module);
	/* Enable module. */
	_i2c_enable(i2c_module);
}

/**
 * \brief Disable the I<SUP>2</SUP>C module
 *
 * Disables the requested I<SUP>2</SUP>C module.
 *
 * \param[in]  module  Pointer to the software module struct
 */
static inline void i2c_master_disable(
		const struct i2c_master_module *const module)
{

	I2C *const i2c_module = (module->hw);

	/* Wait for module to sync. */
	_i2c_master_wait_for_idle(module);
	/* Enable module. */
	_i2c_disable(i2c_module);
}

void i2c_master_get_config_defaults(
		struct i2c_master_config *const config)
{
	config->core_idx		= I2C_CORE1;
	config->baud_rate		= I2C_MASTER_BAUD_RATE_100KHZ;
	config->clock_source 	= I2C_CLK_INPUT_3;
	///config->pinmux_pad[0]   = ((LPGPIO_8 << PINNUM_OFFSET) | PINMUX_VAL_2);
	///config->pinmux_pad[1]   = ((LPGPIO_9 << PINNUM_OFFSET) | PINMUX_VAL_2);
}

/**
 * \brief Initializes the requested I<SUP>2</SUP>C hardware module
 *
 * Initializes the SERCOM I<SUP>2</SUP>C master device requested and sets the provided
 * software module struct. Run this function before any further use of
 * the driver.
 *
 * \param[out] module  Pointer to software module struct
 * \param[in]  config  Pointer to the configuration struct
 *
 * \return Status of initialization.
 * \retval I2C_STATUS_OK                        Module initiated correctly
 * \retval I2C_STATUS_ERR_INVALID_ARG           Invalid argument in module or config structure.
 * \retval I2C_STATUS_ERR_ALREADY_INITIALIZED   If the Pinmux is not a valid one for I2C signals.
 *
 */
enum i2c_status_code i2c_master_init(
		struct i2c_master_module *const module,
		const struct i2c_master_config *const config)
{
	/* Sanity check arguments. */
	if((module == NULL) || (config == NULL))
		return I2C_STATUS_ERR_INVALID_ARG;
	
	/* Initialize software module */
	if(config->core_idx == I2C_CORE1)
		module->hw = (void *)I2C0;
#ifdef CHIPVERSION_B0
	else if(config->core_idx == I2C_CORE2)
		module->hw = (void *)I2C1;
#endif	//CHIPVERSION_B0
	else
		return I2C_STATUS_ERR_INVALID_ARG;

	I2C *const i2c_module = (module->hw);
	
	///if(i2c_module->ENABLE) {
		//return I2C_STATUS_ERR_DENIED;
		///i2c_module->ENABLE = I2C_DISABLE;
	///}
	
	_i2c_reset(i2c_module);


#if I2C_MASTER_CALLBACK_MODE == true

	/* Initialize values in module. */
	module->registered_callback = 0;
	module->enabled_callback = 0;
	module->buffer_length = 0;
	module->buffer_remaining = 0;

	module->status = I2C_STATUS_OK;
	module->buffer = NULL;
#endif

	i2c_master_enable(module);
	/* Set config and return status. */
	if(_i2c_master_set_config(module, config) != I2C_STATUS_OK)
		return I2C_STATUS_ERR_NOT_INITIALIZED;
	
	return I2C_STATUS_OK;
}

/**
 * \brief Resets the hardware module
 *
 * Reset the module to hardware defaults.
 *
 * \param[in,out] module Pointer to software module structure
 */
void i2c_master_reset(struct i2c_master_module *const module)
{
	/* Sanity check arguments */

	I2C *const i2c_module = (module->hw);

	/* Disable module */
	i2c_master_disable(module);

#if I2C_MASTER_CALLBACK_MODE == true
	/* Clear all pending interrupts */
	//system_interrupt_enter_critical_section();
	//system_interrupt_clear_pending(_sercom_get_interrupt_vector(module->hw));
	//system_interrupt_leave_critical_section();
#endif

	/* Reset module */
	_i2c_reset(i2c_module);
}

#if !defined(__DOXYGEN__)
#endif /* __DOXYGEN__ */


/**
 * \internal
 * Starts blocking read operation.
 *
 * \param[in,out] module  Pointer to software module struct
 * \param[in,out] packet  Pointer to I<SUP>2</SUP>C packet to transfer
 *
 * \return Status of reading packet.
 * \retval I2C_STATUS_OK                    The packet was read successfully
 * \retval I2C_STATUS_ERR_TIMEOUT           If no response was given within
 *                                      specified timeout period
 * \retval I2C_STATUS_ERR_DENIED            If error on bus
 * \retval I2C_STATUS_ERR_PACKET_COLLISION  If arbitration is lost
 * \retval I2C_STATUS_ERR_BAD_ADDRESS       If slave is busy, or no slave
 *                                      acknowledged the address
 *
 */
static enum i2c_status_code _i2c_master_read_packet(
		struct i2c_master_module *const module,
		struct i2c_master_packet *const packet)
{

	I2C *const i2c_module = (module->hw);
	uint16_t i	= 0;
	uint32_t cfg = 0;
	uint32_t status = 0;

	/* Return value. */
	uint16_t tmp_data_length = packet->data_length;

	do {
		status = i2c_module->I2C_STATUS.bit.I2C_ACTIVE;
	} while(status);
	
	/* Flush the FIFO */
	i2c_module->I2C_FLUSH.reg;
	
	//Enable I2C on bus (start condition)
	i2c_module->I2C_ONBUS.bit.ONBUS_ENABLE = I2C_I2C_ONBUS_ONBUS_ENABLE_1;
	
	/* Address I2C slave in case of Master mode enabled */
	cfg = I2C_TRANSMIT_DATA_ADDRESS_FLAG_1 | (packet->address << 1) | I2C_READ_FROM_SLAVE;
	i2c_module->TRANSMIT_DATA.reg = cfg;
	do {
		status = i2c_module->RECEIVE_STATUS.reg;
		if (status & I2C_RECEIVE_STATUS_RX_FIFO_NOT_EMPTY)
			packet->data[i++] = i2c_module->RECEIVE_DATA.reg;
	} while(i < tmp_data_length); 
	
	/* Now check whether the core has sent the data out and its good to free the bus. */
	while (!(status & I2C_TRANSMIT_STATUS_TX_FIFO_EMPTY)) {
		status = i2c_module->TRANSMIT_STATUS.reg;
	}
	
	/* Send stop condition. */
	if(!module->no_stop)
		i2c_module->I2C_ONBUS.bit.ONBUS_ENABLE = I2C_I2C_ONBUS_ONBUS_ENABLE_0;
	
	return I2C_STATUS_OK;
}

/**
 * \brief Reads data packet from slave
 *
 * Reads a data packet from the specified slave address on the I<SUP>2</SUP>C
 * bus and sends a stop condition when finished.
 *
 * \note This will stall the device from any other operation. For
 *       interrupt-driven operation, see \ref i2c_master_read_packet_job.
 *
 * \param[in,out] module  Pointer to software module struct
 * \param[in,out] packet  Pointer to I<SUP>2</SUP>C packet to transfer
 *
 * \return Status of reading packet.
 * \retval I2C_STATUS_OK                    The packet was read successfully
 * \retval I2C_STATUS_ERR_INVALID_ARG       Invalid argument in module or config strucuture
 *                                      		specified timeout period
 * \retval I2C_STATUS_BUSY            			If module has a pending request.
 */
enum i2c_status_code i2c_master_read_packet_wait(
		struct i2c_master_module *const module,
		struct i2c_master_packet *const packet)
{
	/* Sanity check */
	//Assert(module);
	//Assert(module->hw);
	//Assert(packet);
	if((module == NULL) || (packet == NULL))
		return I2C_STATUS_ERR_INVALID_ARG;

#if I2C_MASTER_CALLBACK_MODE == true
	/* Check if the I2C module is busy with a job. */
	if (module->buffer_remaining > 0) {
		return I2C_STATUS_BUSY;
	}
#endif

	module->no_stop = false;
	
	return _i2c_master_read_packet(module, packet);
}

/**
 * \brief Reads data packet from slave without sending a stop condition when done
 *
 * Reads a data packet from the specified slave address on the I<SUP>2</SUP>C
 * bus without sending a stop condition when done, thus retaining ownership of
 * the bus when done. To end the transaction, a
 * \ref i2c_master_read_packet_wait "read" or
 * \ref i2c_master_write_packet_wait "write" with stop condition must be
 * performed.
 *
 * \note This will stall the device from any other operation. For
 *       interrupt-driven operation, see \ref i2c_master_read_packet_job.
 *
 * \param[in,out] module  Pointer to software module struct
 * \param[in,out] packet  Pointer to I<SUP>2</SUP>C packet to transfer
 *
 * \return Status of reading packet.
 * \retval I2C_STATUS_OK                    The packet was read successfully
 * \retval I2C_STATUS_ERR_INVALID_ARG       Invalid argument in module or config strucuture
 *                                      		specified timeout period
 * \retval I2C_STATUS_BUSY            			If module has a pending request.
 */
enum i2c_status_code i2c_master_read_packet_wait_no_stop(
		struct i2c_master_module *const module,
		struct i2c_master_packet *const packet)
{
	/* Sanity check */
	//Assert(module);
	//Assert(module->hw);
	//Assert(packet);
	if((module == NULL) || (packet == NULL))
		return I2C_STATUS_ERR_INVALID_ARG;

#if I2C_MASTER_CALLBACK_MODE == true
	/* Check if the I2C module is busy with a job. */
	if (module->buffer_remaining > 0) {
		return I2C_STATUS_BUSY;
	}
#endif

	module->no_stop = true;

	return _i2c_master_read_packet(module, packet);
}

/**
 * \internal
 * Starts blocking write operation.
 *
 * \param[in,out] module  Pointer to software module struct
 * \param[in,out] packet  Pointer to I<SUP>2</SUP>C packet to transfer
 *
 * \return Status of write packet.
 * \retval I2C_STATUS_OK                    The packet was write successfully
 */
static enum i2c_status_code _i2c_master_write_packet(
		struct i2c_master_module *const module,
		struct i2c_master_packet *const packet)
{
	I2C *const i2c_module = (module->hw);
	uint16_t i	= 0;
	uint32_t cfg = 0;
	uint32_t status = 0;

	/* Return value. */
	uint16_t tmp_data_length = packet->data_length;

	do {
		status = i2c_module->I2C_STATUS.bit.I2C_ACTIVE;
	} while (status);
	
	/* Flush the FIFO */
	i2c_module->I2C_FLUSH.reg;
	
	/* Enable I2C on bus (start condition) */
	i2c_module->I2C_ONBUS.bit.ONBUS_ENABLE = I2C_I2C_ONBUS_ONBUS_ENABLE_1;
	
	/* Address I2C slave in case of Master mode enabled */
	cfg = I2C_TRANSMIT_DATA_ADDRESS_FLAG_1 | ((packet->address) << 1) | I2C_WRITE_TO_SLAVE;
	i2c_module->TRANSMIT_DATA.reg = cfg;
	do {
		status = i2c_module->TRANSMIT_STATUS.reg;
		if (status & I2C_TRANSMIT_STATUS_TX_FIFO_NOT_FULL_Msk)
			i2c_module->TRANSMIT_DATA.reg = packet->data[i++];
	} while (i < tmp_data_length); 
	
	/* Now check whether the core has sent the data out and its good to free the bus */
	while (!(status & I2C_TRANSMIT_STATUS_TX_FIFO_EMPTY)) {
			status = i2c_module->TRANSMIT_STATUS.reg;
	}

	/* Send stop condition */
	if(!module->no_stop)
		i2c_module->I2C_ONBUS.bit.ONBUS_ENABLE = I2C_I2C_ONBUS_ONBUS_ENABLE_0;
	
	return I2C_STATUS_OK;
}

/**
 * \brief Writes data packet to slave
 *
 * Writes a data packet to the specified slave address on the I<SUP>2</SUP>C bus
 * and sends a stop condition when finished.
 *
 * \note This will stall the device from any other operation. For
 *       interrupt-driven operation, see \ref i2c_master_read_packet_job.
 *
 * \param[in,out] module  Pointer to software module struct
 * \param[in,out] packet  Pointer to I<SUP>2</SUP>C packet to transfer
 *
 * \return Status of write packet.
 * \retval I2C_STATUS_OK                    The packet was written successfully
 * \retval I2C_STATUS_ERR_INVALID_ARG       Invalid argument in module or packet structure
 *                                      		specified timeout period
 * \retval I2C_STATUS_BUSY            			If module has a pending request.
 */
enum i2c_status_code i2c_master_write_packet_wait(
		struct i2c_master_module *const module,
		struct i2c_master_packet *const packet)
{
	/* Sanity check */
	//Assert(module);
	//Assert(module->hw);
	//Assert(packet);
	if((module == NULL) || (packet == NULL))
		return I2C_STATUS_ERR_INVALID_ARG;
	
#if I2C_MASTER_CALLBACK_MODE == true
	/* Check if the I2C module is busy with a job */
	if (module->buffer_remaining > 0) {
		return I2C_STATUS_BUSY;
	}
#endif

	module->no_stop = false;

	return _i2c_master_write_packet(module, packet);
}

/**
 * \brief Writes data packet to slave without sending a stop condition when done
 *
 * Writes a data packet to the specified slave address on the I<SUP>2</SUP>C bus
 * without sending a stop condition, thus retaining ownership of the bus when
 * done. To end the transaction, a \ref i2c_master_read_packet_wait "read" or
 * \ref i2c_master_write_packet_wait "write" with stop condition or sending a
 * stop with the \ref i2c_master_send_stop function must be performed.
 *
 * \note This will stall the device from any other operation. For
 *       interrupt-driven operation, see \ref i2c_master_read_packet_job.
 *
 * \param[in,out] module  Pointer to software module struct
 * \param[in,out] packet  Pointer to I<SUP>2</SUP>C packet to transfer
 *
 * \return Status of write packet.
 * \retval I2C_STATUS_OK                    The packet was written successfully
 * \retval I2C_STATUS_ERR_INVALID_ARG       Invalid argument in module or config structure
 *                                      		specified timeout period
 * \retval I2C_STATUS_BUSY            			If module has a pending request.
 */
enum i2c_status_code i2c_master_write_packet_wait_no_stop(
		struct i2c_master_module *const module,
		struct i2c_master_packet *const packet)
{
	/* Sanity check */
	//Assert(module);
	//Assert(module->hw);
	//Assert(packet);

	if((module == NULL) || (packet == NULL))
		return I2C_STATUS_ERR_INVALID_ARG;
	
#if I2C_MASTER_CALLBACK_MODE == true
	/* Check if the I2C module is busy with a job */
	if (module->buffer_remaining > 0) {
		return I2C_STATUS_BUSY;
	}
#endif

	module->no_stop = true;

	return _i2c_master_write_packet(module, packet);
}

/**
 * \brief Sends stop condition on bus
 *
 * Sends a stop condition on bus.
 *
 * \note This function can only be used after the
 *       \ref i2c_master_write_packet_wait_no_stop function. If a stop condition
 *       is to be sent after a read, the \ref i2c_master_read_packet_wait
 *       function must be used.
 *
 * \param[in,out] module  Pointer to the software instance struct
 */
void i2c_master_send_stop(struct i2c_master_module *const module)
{
	/* Sanity check */
	//Assert(module);
	//Assert(module->hw);

	I2C *const i2c_module = (module->hw);

	/* Send stop command */
	_i2c_master_wait_for_idle(module);
	
	i2c_module->I2C_ONBUS.bit.ONBUS_ENABLE = I2C_I2C_ONBUS_ONBUS_ENABLE_0;
}

/**
 * \brief Sends start condition on bus
 *
 * Sends a start condition on bus.
 *
 * \note This function can only be used after the
 * \ref i2c_master_write_packet_wait_no_stop function. If a stop condition
 * is to be sent after a read, the \ref i2c_master_read_packet_wait
 * function must be used.
 *
 * \param[in,out] module  Pointer to the software instance struct
 */
void i2c_master_send_start(struct i2c_master_module *const module)
{
	I2C *const i2c_module = (module->hw);

	_i2c_master_wait_for_idle(module);
	
	/* Send start command */
	i2c_module->I2C_ONBUS.bit.ONBUS_ENABLE = I2C_I2C_ONBUS_ONBUS_ENABLE_1;
}

/**
 * \brief Reads one byte data from slave
 *
 * \param[in,out]  module  Pointer to software module struct
 * \param[out]     byte    Read one byte data to slave
 *
 * \return Status of reading byte.
 * \retval I2C_STATUS_OK                    The packet was read successfully
 */
enum i2c_status_code i2c_master_read_byte(
		struct i2c_master_module *const module,
		uint8_t *byte)
{
  	I2C *const i2c_module = (module->hw);

	/* Read a byte from slave. */
	_i2c_master_wait_for_idle(module);
	
	*byte = i2c_module->RECEIVE_DATA.bit.RX_BYTE;
	
	return I2C_STATUS_OK;
}

/**
 * \brief Write Address & command to slave
 *
 * \param[in,out]  module  Pointer to software module struct
 * \param[in]      byte    Address of slave
 * \param[in]			 byte		 command 0 - Write, 1 - Read
 *
 * \return Status of writing byte.
 * \retval I2C_STATUS_OK   The Address and command was written successfully
 */
enum i2c_status_code i2c_master_write_address(
		struct i2c_master_module *const module,
		uint8_t address,
		uint8_t command)
{
  	I2C *const i2c_module = (module->hw);
	  
	/* Write byte to slave. */
	_i2c_master_wait_for_idle(module);
	
	i2c_module->TRANSMIT_DATA.reg = I2C_TRANSMIT_DATA_ADDRESS_FLAG_1 | (address << 1) | command;
		
	return I2C_STATUS_OK;
}


/**
 * \brief Write one byte data to slave
 *
 * \param[in,out]  module  Pointer to software module struct
 * \param[in]      byte    Send one byte data to slave
 *
 * \return Status of writing byte.
 * \retval I2C_STATUS_OK   One byte was written successfully
 */
enum i2c_status_code i2c_master_write_byte(
		struct i2c_master_module *const module,
		uint8_t byte)
{
  	I2C *const i2c_module = (module->hw);

	/* Write byte to slave. */
	_i2c_master_wait_for_idle(module);
	
	i2c_module->TRANSMIT_DATA.reg = (uint16_t)byte;
	
	return I2C_STATUS_OK;
}

#ifdef FEATURE_I2C_DMA_SUPPORT
/**
* \name I2C Master with DMA Interfaces
* @{
*/

/**
 * \brief Set I<SUP>2</SUP>C for DMA transfer with slave address and transfer size.
 *
 * This function will set the slave address, transfer size and enable the auto transfer
 * mode for DMA.
 *
 * \param[in,out] module Pointer to the driver instance to lock
 * \param[in] addr I<SUP>2</SUP>C slave address
 * \param[in] length I<SUP>2</SUP>C transfer length with DMA
 * \param[in] direction I<SUP>2</SUP>C transfer direction
 *
 */
static inline void i2c_master_dma_set_transfer(struct i2c_master_module *const module,
		uint16_t addr, uint8_t length, enum i2c_transfer_direction direction)
{
}

/** @} */
#endif
