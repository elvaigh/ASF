/**
 * \file
 *
 * \brief I2C Master Driver for SAMB11
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include "i2c.h"

/**
 * \brief Resets the I2C module
 *
 * This function will reset the I2C module to its power on default values and
 * disable it.
 *
 * \param[in,out] module Pointer to the software instance struct
 */
static enum status_code _i2c_reset(I2C *const i2c_module)
{
	if (i2c_module == (I2C *)I2C0) {
		LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &=
			~(LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_CORTUS_I2C0_CORE_RSTN |
			LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_CORTUS_I2C0_IF_RSTN);
		LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |=
			(LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_CORTUS_I2C0_CORE_RSTN |
			LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_CORTUS_I2C0_IF_RSTN);
	}
#ifdef CHIPVERSION_B0
	else if (i2c_module == (I2C *)I2C1) {
		LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &=
			~(LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_CORTUS_I2C1_CORE_RSTN |
			LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_CORTUS_I2C1_IF_RSTN);
		LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |=
			(LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_CORTUS_I2C1_CORE_RSTN |
			LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_CORTUS_I2C1_IF_RSTN);
	}
#endif

	return STATUS_OK;
}

/**
 * \internal Sets configurations to module
 *
 * \param[out] module  Pointer to software module structure
 * \param[in]  config  Configuration structure with configurations to set
 *
 * \return Status of setting configuration.
 * \retval STATUS_OK                        If module was configured correctly
 * \retval STATUS_ERR_ALREADY_INITIALIZED   If setting other GCLK generator than
 *                                          previously set
 * \retval STATUS_ERR_BAUDRATE_UNAVAILABLE  If given baud rate is not compatible
 *                                          with set GCLK frequency
 */
static enum status_code _i2c_master_set_config(
		struct i2c_module *const module,
		const struct i2c_master_config *const config)
{
	enum status_code status = STATUS_OK;
	uint8_t idx = 0;
	I2C *const i2c_module = (module->hw);

	/* Set the pinmux for this i2c module. */
	for (idx = 0; idx < 2; idx++) {
		gpio_pinmux_cofiguration(config->pinmux_pad[idx]>>16, \
								(uint16_t)(config->pinmux_pad[idx] & 0xFFFF));
	}
	/* Find and set baudrate. */
	i2c_module->CLOCK_SOURCE_SELECT.reg = config->clock_source;
	i2c_module->I2C_CLK_DIVIDER.reg = I2C_I2C_CLK_DIVIDER_I2C_DIVIDE_RATIO(0x10);
	i2c_module->I2C_MASTER_MODE.reg = I2C_I2C_MASTER_MODE_MASTER_ENABLE_1;

	return status;
}

/**
 * \brief Attempt to get lock on driver instance
 *
 * This function checks the instance's lock, which indicates whether or not it
 * is currently in use, and sets the lock if it was not already set.
 *
 * The purpose of this is to enable exclusive access to driver instances, so
 * that, e.g., transactions by different services will not interfere with each
 * other.
 *
 * \param[in,out] module Pointer to the driver instance to lock
 *
 * \retval I2C_STATUS_OK   If the module was locked
 * \retval I2C_STATUS_BUSY If the module was already locked
 */
enum status_code i2c_lock(
		struct i2c_module *const module)
{
	enum status_code status;

	//system_interrupt_enter_critical_section();

	if (module->locked) {
		status = STATUS_BUSY;
	} else {
		module->locked = true;
		status = STATUS_OK;
	}

	//system_interrupt_leave_critical_section();

	return status;
}

/**
 * \brief Unlock driver instance
 *
 * This function clears the instance lock, indicating that it is available for
 * use.
 *
 * \param[in,out] module Pointer to the driver instance to lock
 *
 */
void i2c_unlock(struct i2c_module *const module)
{
	module->locked = false;
}

/**
 * \internal
 * Wait for hardware module to sync
 *
 * \param[in]  module  Pointer to software module structure
 */
static void _i2c_wait_for_idle(
		const struct i2c_module *const module)
{
	/* Sanity check. */
	Assert(module);

	while (i2c_is_active(module)) {
		/* Wait for I2C module to sync. */
	}
}

/**
 * \brief Enables the I<SUP>2</SUP>C module
 *
 * Enables the requested I<SUP>2</SUP>C module and set the bus state to IDLE
 * after the specified \ref asfdoc_sam0_i2c_timeout "timeout" period if no
 * stop bit is detected.
 *
 * \param[in]  module  Pointer to the software module struct
 */
void i2c_enable(
		const struct i2c_module *const module)
{
	I2C *const i2c_module = (module->hw);

	/* Wait for module to sync. */
	_i2c_wait_for_idle(module);
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
void i2c_disable(
		const struct i2c_module *const module)
{

	I2C *const i2c_module = (module->hw);

	/* Wait for module to sync. */
	_i2c_wait_for_idle(module);
	/* Enable module. */
	_i2c_disable(i2c_module);
}

#  if CONF_I2C_MASTER_ENABLE == true

void i2c_master_get_config_defaults(
		struct i2c_master_config *const config)
{
	config->core_idx        = I2C_CORE1;
	config->baud_rate       = I2C_MASTER_BAUD_RATE_100KHZ;
	config->clock_source    = I2C_CLK_INPUT_3;
	config->pinmux_pad[0]   = PINMUX_LP_GPIO_8_MUX2_I2C0_SDA;
	config->pinmux_pad[1]   = PINMUX_LP_GPIO_9_MUX2_I2C0_SCK;
}

/**
 * \brief Initializes the requested I<SUP>2</SUP>C hardware module
 *
 * Initializes the I<SUP>2</SUP>C master device requested and sets the provided
 * software module struct. Run this function before any further use of
 * the driver.
 *
 * \param[out] module  Pointer to software module struct
 * \param[in]  config  Pointer to the configuration struct
 *
 * \return Status of initialization.
 * \retval STATUS_OK                        Module initiated correctly
 * \retval STATUS_ERR_INVALID_ARG           Invalid argument in module or config structure.
 * \retval STATUS_ERR_ALREADY_INITIALIZED   If the Pinmux is not a valid one for I2C signals.
 *
 */
enum status_code i2c_master_init(
		struct i2c_module *const module,
		const struct i2c_master_config *const config)
{
	/* Sanity check arguments. */
	if((module == NULL) || (config == NULL))
		return STATUS_ERR_INVALID_ARG;

	/* Initialize software module */
	if(config->core_idx == I2C_CORE1)
		module->hw = (void *)I2C0;
#ifdef CHIPVERSION_B0
	else if(config->core_idx == I2C_CORE2)
		module->hw = (void *)I2C1;
#endif  //CHIPVERSION_B0
	else {
		return STATUS_ERR_INVALID_ARG;
	}
	I2C *const i2c_module = (module->hw);

	if (i2c_module->I2C_MODULE_ENABLE.reg) {
		i2c_module->I2C_MODULE_ENABLE.reg = I2C_I2C_MODULE_ENABLE_ENABLE;
	}

	_i2c_reset(i2c_module);

#if I2C_MASTER_CALLBACK_MODE == true

	/* Initialize values in module. */
	module->registered_callback = 0;
	module->enabled_callback = 0;
	module->buffer_length = 0;
	module->buffer_remaining = 0;
	module->status = STATUS_OK;
	module->buffer = NULL;
#endif

	i2c_enable(module);
	/* Set config and return status. */
	if(_i2c_master_set_config(module, config) != STATUS_OK)
		return STATUS_ERR_NOT_INITIALIZED;

	return STATUS_OK;
}

/**
 * \brief Resets the hardware module
 *
 * Reset the module to hardware defaults.
 *
 * \param[in,out] module Pointer to software module structure
 */
void i2c_reset(struct i2c_module *const module)
{
	/* Sanity check arguments */

	I2C *const i2c_module = (module->hw);

	/* Disable module */
	i2c_disable(module);

#if I2C_MASTER_CALLBACK_MODE == true
	/* Clear all pending interrupts */
	//system_interrupt_enter_critical_section();
	//system_interrupt_clear_pending(_get_interrupt_vector(module->hw));
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
 * \retval STATUS_OK                    The packet was read successfully
 * \retval STATUS_ERR_TIMEOUT           If no response was given within
 *                                      specified timeout period
 * \retval STATUS_ERR_DENIED            If error on bus
 * \retval STATUS_ERR_PACKET_COLLISION  If arbitration is lost
 * \retval STATUS_ERR_BAD_ADDRESS       If slave is busy, or no slave
 *                                      acknowledged the address
 *
 */
static enum status_code _i2c_master_read_packet(
		struct i2c_module *const module,
		struct i2c_master_packet *const packet)
{

	I2C *const i2c_module = (module->hw);
	uint16_t i = 0;
	uint32_t cfg = 0;
	uint32_t status = 0;

	/* Return value. */
	uint16_t tmp_data_length = packet->data_length;

	do {
		status = i2c_module->I2C_STATUS.bit.I2C_ACTIVE;
	} while(status);

	/* Flush the FIFO */
	i2c_module->I2C_FLUSH.reg = 1;

	/* Enable I2C on bus (start condition) */
	i2c_module->I2C_ONBUS.reg = I2C_I2C_ONBUS_ONBUS_ENABLE_1;

	/* Address I2C slave in case of Master mode enabled */
	cfg = I2C_TRANSMIT_DATA_ADDRESS_FLAG_1 | (packet->address << 1) | I2C_READ_FROM_SLAVE;
	i2c_module->TRANSMIT_DATA.reg = cfg;
	do {
		status = i2c_module->RECEIVE_STATUS.reg;
		if (status & I2C_RECEIVE_STATUS_RX_FIFO_NOT_EMPTY)
			packet->data[i++] = i2c_module->RECEIVE_DATA.reg;
	} while (i < tmp_data_length); 

	/* Now check whether the core has sent the data out and its good to free the bus. */
	while (!(status & I2C_TRANSMIT_STATUS_TX_FIFO_EMPTY)) {
		status = i2c_module->TRANSMIT_STATUS.reg;
	}

	/* Send stop condition. */
	if (!module->no_stop) {
		i2c_module->I2C_ONBUS.reg = I2C_I2C_ONBUS_ONBUS_ENABLE_0;
	}

	return STATUS_OK;
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
 * \retval STATUS_OK                    The packet was read successfully
 * \retval STATUS_ERR_INVALID_ARG       Invalid argument in module or config strucuture
 *                                      specified timeout period
 * \retval STATUS_BUSY                  If module has a pending request.
 */
enum status_code i2c_master_read_packet_wait(
		struct i2c_module *const module,
		struct i2c_master_packet *const packet)
{
	/* Sanity check */
	Assert(module);
	Assert(module->hw);
	Assert(packet);

	if((module == NULL) || (packet == NULL))
		return STATUS_ERR_INVALID_ARG;

#if I2C_MASTER_CALLBACK_MODE == true
	/* Check if the I2C module is busy with a job. */
	if (module->buffer_remaining > 0) {
		return STATUS_BUSY;
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
 * \retval STATUS_OK                    The packet was read successfully
 * \retval STATUS_ERR_INVALID_ARG       Invalid argument in module or config strucuture
 *                                      specified timeout period
 * \retval STATUS_BUSY                  If module has a pending request.
 */
enum status_code i2c_master_read_packet_wait_no_stop(
		struct i2c_module *const module,
		struct i2c_master_packet *const packet)
{
	/* Sanity check */
	Assert(module);
	Assert(module->hw);
	Assert(packet);

	if((module == NULL) || (packet == NULL))
		return STATUS_ERR_INVALID_ARG;

#if I2C_MASTER_CALLBACK_MODE == true
	/* Check if the I2C module is busy with a job. */
	if (module->buffer_remaining > 0) {
		return STATUS_BUSY;
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
 * \retval STATUS_OK                    The packet was write successfully
 */
static enum status_code _i2c_master_write_packet(
		struct i2c_module *const module,
		struct i2c_master_packet *const packet)
{
	I2C *const i2c_module = (module->hw);
	uint16_t i      = 0;
	uint32_t cfg    = 0;
	uint32_t status = 0;

	/* Return value */
	uint16_t tmp_data_length = packet->data_length;

	do {
		status = i2c_module->I2C_STATUS.bit.I2C_ACTIVE;
	} while (status);

	/* Flush the FIFO */
	i2c_module->I2C_FLUSH.reg = 1;

	/* Enable I2C on bus (start condition) */
	i2c_module->I2C_ONBUS.reg = I2C_I2C_ONBUS_ONBUS_ENABLE_1;

	/* Address I2C slave in case of Master mode enabled */
	cfg = I2C_TRANSMIT_DATA_ADDRESS_FLAG_1 | ((packet->address) << 1) | I2C_WRITE_TO_SLAVE;
	i2c_module->TRANSMIT_DATA.reg = cfg;
	do {
		status = i2c_module->TRANSMIT_STATUS.reg;
		if (status & I2C_TRANSMIT_STATUS_TX_FIFO_NOT_FULL_Msk) {
			i2c_module->TRANSMIT_DATA.reg = packet->data[i++];
		}
	} while (i < tmp_data_length); 

	/* Now check whether the core has sent the data out and its good to free the bus */
	while (!(status & I2C_TRANSMIT_STATUS_TX_FIFO_EMPTY)) {
			status = i2c_module->TRANSMIT_STATUS.reg;
	}

	/* Send stop condition */
	if (!module->no_stop) {
		i2c_module->I2C_ONBUS.reg = I2C_I2C_ONBUS_ONBUS_ENABLE_0;
	}

	return STATUS_OK;
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
 * \retval STATUS_OK                    The packet was written successfully
 * \retval STATUS_ERR_INVALID_ARG       Invalid argument in module or packet structure
 *                                      specified timeout period
 * \retval STATUS_BUSY                  If module has a pending request.
 */
enum status_code i2c_master_write_packet_wait(
		struct i2c_module *const module,
		struct i2c_master_packet *const packet)
{
	/* Sanity check */
	Assert(module);
	Assert(module->hw);
	Assert(packet);

	if ((module == NULL) || (packet == NULL)) {
		return STATUS_ERR_INVALID_ARG;
	}
#if I2C_MASTER_CALLBACK_MODE == true
	/* Check if the I2C module is busy with a job */
	if (module->buffer_remaining > 0) {
		return STATUS_BUSY;
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
 * \retval STATUS_OK                    The packet was written successfully
 * \retval STATUS_ERR_INVALID_ARG       Invalid argument in module or config structure
 *                                      specified timeout period
 * \retval STATUS_BUSY                  If module has a pending request.
 */
enum status_code i2c_master_write_packet_wait_no_stop(
		struct i2c_module *const module,
		struct i2c_master_packet *const packet)
{
	/* Sanity check */
	Assert(module);
	Assert(module->hw);
	Assert(packet);

	if((module == NULL) || (packet == NULL)) {
		return STATUS_ERR_INVALID_ARG;
	}
#if I2C_MASTER_CALLBACK_MODE == true
	/* Check if the I2C module is busy with a job */
	if (module->buffer_remaining > 0) {
		return STATUS_BUSY;
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
void i2c_master_send_stop(struct i2c_module *const module)
{
	/* Sanity check */
	Assert(module);
	Assert(module->hw);

	I2C *const i2c_module = (module->hw);

	/* Send stop command */
	_i2c_wait_for_idle(module);

	i2c_module->I2C_ONBUS.reg = I2C_I2C_ONBUS_ONBUS_ENABLE_0;
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
void i2c_master_send_start(struct i2c_module *const module)
{
	I2C *const i2c_module = (module->hw);

	_i2c_wait_for_idle(module);

	/* Send start command */
	i2c_module->I2C_ONBUS.reg = I2C_I2C_ONBUS_ONBUS_ENABLE_1;
}

/**
 * \brief Reads one byte data from slave
 *
 * \param[in,out]  module  Pointer to software module struct
 * \param[out]     byte    Read one byte data to slave
 *
 * \return Status of reading byte.
 * \retval STATUS_OK                    The packet was read successfully
 */
enum status_code i2c_master_read_byte(
		struct i2c_module *const module,
		uint8_t *byte)
{
	I2C *const i2c_module = (module->hw);

	/* Read a byte from slave. */
	_i2c_wait_for_idle(module);

	*byte = i2c_module->RECEIVE_DATA.bit.RX_BYTE;

	return STATUS_OK;
}

/**
 * \brief Write Address & command to slave
 *
 * \param[in,out]  module  Pointer to software module struct
 * \param[in]      byte    Address of slave
 * \param[in]      byte    command 0 - Write, 1 - Read
 *
 * \return Status of writing byte.
 * \retval STATUS_OK   The Address and command was written successfully
 */
enum status_code i2c_master_write_address(
		struct i2c_module *const module,
		uint8_t address,
		uint8_t command)
{
	I2C *const i2c_module = (module->hw);

	/* Write byte to slave. */
	_i2c_wait_for_idle(module);

	i2c_module->TRANSMIT_DATA.reg = I2C_TRANSMIT_DATA_ADDRESS_FLAG_1 | (address << 1) | command;

	return STATUS_OK;
}


/**
 * \brief Write one byte data to slave
 *
 * \param[in,out]  module  Pointer to software module struct
 * \param[in]      byte    Send one byte data to slave
 *
 * \return Status of writing byte.
 * \retval STATUS_OK   One byte was written successfully
 */
enum status_code i2c_master_write_byte(
		struct i2c_module *const module,
		uint8_t byte)
{
	I2C *const i2c_module = (module->hw);

	/* Write byte to slave. */
	_i2c_wait_for_idle(module);

	i2c_module->TRANSMIT_DATA.reg = (uint16_t)I2C_TRANSMIT_DATA_TX_DATA(byte);

	return STATUS_OK;
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
static inline void i2c_master_dma_set_transfer(struct i2c_module *const module,
		uint16_t addr, uint8_t length, enum i2c_transfer_direction direction)
{
}

#  endif

/** @} */
#endif
