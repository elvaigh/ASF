/**
 * \file
 *
 * \brief SAM0+ SERCOM USART Asynchronous Driver
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

#include "usart_async.h"

#if !defined (__DOXYGEN__)

/**
 * \internal      Asynchronous write of a buffer with a given length
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 * \param[in]     tx_data  Pointer to data to be transmitted
 * \param[in]     length   Length of data buffer
 *
 */
void _usart_async_write_buffer(struct usart_dev_inst *const dev_inst,
		uint8_t *tx_data, uint16_t length)
{
	/* Write parameters to the device instance */
	dev_inst->remaining_tx_buffer_length = length;
	dev_inst->tx_buffer_ptr = tx_data;

	/* Get a pointer to the hardware module instance */
	SercomUsart *const usart_module = &(dev_inst->hw_dev->USART);

	/* Enable the Data Register Empty Interrupt */
	usart_module->INTENSET.reg = SERCOM_USART_INTFLAG_DREIF;
}

/**
 * \internal      Asynchronous read of a buffer with a given length
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 * \param[in]     rx_data  Pointer to data to be received
 * \param[in]     length   Length of data buffer
 *
 */
void _usart_async_read_buffer(struct usart_dev_inst *const dev_inst,
		uint8_t *rx_data, uint16_t length)
{
	/* Set length for the buffer and the pointer, and let
	 * the interrupt handler do the rest */
	dev_inst->remaining_rx_buffer_length = length;
	dev_inst->rx_buffer_ptr = rx_data;
}

#endif

/**
 * \brief Registers a callback
 *
 * Registers a callback function which is implemented by the user.
 *
 * \note The callback must be enabled by \ref usart_async_register_callback,
 * in order for the interrupt handler to call it when the conditions for the
 * callback type is met.
 *
 * \param[in]     dev_inst      Pointer to USART software instance struct
 * \param[in]     callback_func Pointer to callback function
 * \param[in]     callback_type Callback type given by an enum
 *
 */
void usart_async_register_callback(struct usart_dev_inst *const dev_inst,
		usart_async_callback_t *callback_func,
		enum usart_callback callback_type)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(callback_func);

	/* Register callback function */
	dev_inst->callback[callback_type] = callback_func;

	/* Set the bit corresponding to the callback_type */
	dev_inst->callback_reg_mask |= (1 << callback_type);
}

/**
 * \brief Unregisters a callback
 *
 * Unregisters a callback function which is implemented by the user.
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 * \param[in]     callback_func Pointer to callback function
 * \param[in]     callback_type Callback type given by an enum
 *
 */
void usart_async_unregister_callback(struct usart_dev_inst *const dev_inst,
		enum usart_callback callback_type)
{
	/* Sanity check arguments */
	Assert(dev_inst);

	/* Unregister callback function */
	dev_inst->callback[callback_type] = NULL;
	_sercom_instances[_sercom_get_module_irq_index(dev_inst)] = 0;

	/* Clear the bit corresponding to the callback_type */
	dev_inst->callback_reg_mask |= (0 << callback_type);
}

/**
 * \brief Enables callback
 *
 * Enables the callback function registered by the \ref
 * usart_async_register_callback. The callback function will be called from the
 * interrupt handler when the conditions for the callback type are met.
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 * \param[in]     callback_type Callback type given by an enum
 *
 * \returns    Status of the operation
 * \retval     STATUS_OK              If operation was completed
 * \retval     STATUS_ERR_INVALID     If operation was not completed,
 *                                    due to invalid callback_type
 *
 */
enum status_code usart_async_enable_callback(
		struct usart_dev_inst *const dev_inst,
		enum usart_callback callback_type)
{
	/* Sanity check arguments */
	Assert(dev_inst);

	/* Enable callback */
	dev_inst->callback_enable_mask |= (1 << callback_type);

	/* Get a pointer to the hardware module instance */
	SercomUsart *const usart_module = &(dev_inst->hw_dev->USART);

	/* Enable the interrupt flag */
	switch (callback_type) {
	case USART_CALLBACK_BUFFER_TRANSMITTED:
		usart_module->INTENSET.reg = SERCOM_USART_INTFLAG_TXCIF;
		break;

	case USART_CALLBACK_BUFFER_RECEIVED:
		usart_module->INTENSET.reg = SERCOM_USART_INTFLAG_RXCIF;
		break;

	default:
		Assert(false);
		return STATUS_ERR_INVALID_ARG;
	}

	return STATUS_OK;
}

/**
 * \brief Disable callback
 *
 * Disables the callback function registered by the \ref
 * usart_async_register_callback, and the callback will be neglected
 * by the interrupt routine.
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 * \param[in]     callback_type Callback type given by an enum
 *
 * \returns    Status of the operation
 * \retval     STATUS_OK              If operation was completed
 * \retval     STATUS_ERR_INVALID     If operation was not completed,
 *                                    due to invalid callback_type
 *
 */
enum status_code usart_async_disable_callback(
		struct usart_dev_inst *const dev_inst,
		enum usart_callback callback_type)
{
	/* Sanity check arguments */
	Assert(dev_inst);

	/* Disable callback */
	dev_inst->callback_enable_mask |= (0 << callback_type);

	/* Get a pointer to the hardware module instance */
	SercomUsart *const usart_module = &(dev_inst->hw_dev->USART);

	/* Disable the interrupt flag */
	switch (callback_type) {
	case USART_CALLBACK_BUFFER_TRANSMITTED:
		usart_module->INTENCLR.reg = SERCOM_USART_INTFLAG_TXCIF;
		break;

	case USART_CALLBACK_BUFFER_RECEIVED:
		usart_module->INTENCLR.reg = SERCOM_USART_INTFLAG_RXCIF;
		break;

	default:
		Assert(false);
		return STATUS_ERR_INVALID_ARG;
	}

	return STATUS_OK;
}

/**
 * \brief Asynchronous write a single char
 *
 * Sets up the driver to write the data given. If registered and enabled,
 * a callback function will be called when the transmit is completed.
 *
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 * \param[in]     tx_data  Data to transfer
 *
 * \returns    Status of the operation
 * \retval     STATUS_OK              If operation was completed
 * \retval     STATUS_ERR_BUSY        If operation was not completed,
 *                                    due to the USART module being busy.
 */
enum status_code usart_async_write(struct usart_dev_inst *const dev_inst,
		const uint16_t tx_data)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);
	/* Check if the USART transmitter is busy */
	if (dev_inst->remaining_tx_buffer_length > 0) {
		return STATUS_ERR_BUSY;
	}

	/* Call internal write buffer function with length 1 */
	_usart_async_write_buffer(dev_inst, (uint8_t *)&tx_data, 1);

	return STATUS_OK;
}

/**
 * \brief Asynchronous read a single char
 *
 * Sets up the driver to read data from the USART module to the data
 * pointer given. If registered and enabled, a callback will be called
 * when the receiving is completed.
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 * \param[out]    rx_data  Pointer to where received data should
 *                         be put
 *
 * \returns    Status of the operation
 * \retval     STATUS_OK              If operation was completed
 * \retval     STATUS_ERR_BUSY        If operation was not completed,
 *                                    due to the USART module being busy.
 */
enum status_code usart_async_read(struct usart_dev_inst *const dev_inst,
		uint16_t *const rx_data)
{
	/* Sanity check arguments */
	Assert(dev_inst);

	/* Check if the USART receiver is busy */
	if (dev_inst->remaining_rx_buffer_length > 0) {
		return STATUS_ERR_BUSY;
	}

	/* Call internal read buffer function with length 1 */
	_usart_async_read_buffer(dev_inst, (uint8_t *)rx_data, 1);

	return STATUS_OK;
}

/**
 * \brief Asynchronous buffer write
 *
 * Sets up the driver to write a given buffer over the USART. If registered and
 * enabled, a callback function will be called.
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 * \param[in]     tx_data  Pointer do data buffer to transmit
 *
 * \returns    Status of the operation
 * \retval     STATUS_OK              If operation was completed
 * \retval     STATUS_ERR_BUSY        If operation was not completed,
 *                                    due to the USART module being busy.
 */
enum status_code usart_async_write_buffer(struct usart_dev_inst *const dev_inst,
		uint8_t *tx_data, uint16_t length)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	if (length == 0) {
		return STATUS_ERR_INVALID_ARG;
	}

	/* Check if the USART transmitter is busy */
	if (dev_inst->remaining_tx_buffer_length > 0) {
		return STATUS_ERR_BUSY;
	}

	/* Issue internal asynchronous write */
	_usart_async_write_buffer(dev_inst, tx_data, length);

	return STATUS_OK;
}

/**
 * \brief Asynchronous buffer read
 *
 * Sets up the driver to read from the USART to a given buffer. If registered
 * and enabled, a callback function will be called.
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 * \param[out]    rx_data  Pointer to data buffer to receive
 * \param[in]     length   Data buffer length
 *
 * \returns    Status of the operation
 * \retval     STATUS_OK              If operation was completed.
 * \retval     STATUS_ERR_BUSY        If operation was not completed,
 *                                    due to the USART module being busy.
 */
enum status_code usart_async_read_buffer(struct usart_dev_inst *const dev_inst,
		uint8_t *rx_data, uint16_t length)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	if (length == 0) {
		return STATUS_ERR_INVALID_ARG;
	}

	/* Check if the USART receiver is busy */
	if (dev_inst->remaining_rx_buffer_length > 0) {
		return STATUS_ERR_BUSY;
	}

	/* Issue internal asynchronous read */
	_usart_async_read_buffer(dev_inst, rx_data, length);

	return STATUS_OK;
}

/**
 * \brief Cancels ongoing write operation
 *
 * Cancels the ongoing write operation modifying parameters in the
 * USART software struct.
 *
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 *
 */
void usart_async_cancel_transmission(struct usart_dev_inst *const dev_inst)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);

	/* Getl a pointer to the hardware module instance */
	SercomUsart *const usart_module = &(dev_inst->hw_dev->USART);

	/* Clear the interrupt flag in order to prevent the transmission
	 * complete callback to fire */
	usart_module->INTFLAG.reg |= SERCOM_USART_INTFLAG_TXCIF;

	/* Clear the software transmission buffer */
	dev_inst->remaining_tx_buffer_length = 0;
}

/**
 * \brief Cancels ongoing read operation
 *
 * Cancels the ongoing read operation modifying parameters in the
 * USART software struct.
 *
 * \param[in]     dev_inst Pointer to USART software instance struct
 *
 */
void usart_async_cancel_reception(struct usart_dev_inst *const dev_inst)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);

	/* Get a pointer to the hardware module instance */
	SercomUsart *const usart_module = &(dev_inst->hw_dev->USART);

	/* Clear the interrupt flag in order to prevent the receive
	 * complete callback to fire */
	usart_module->INTFLAG.reg |= SERCOM_USART_INTFLAG_RXCIF;

	/* Clear the software reception buffer */
	dev_inst->remaining_rx_buffer_length = 0;
}

/**
 * \brief Get last error from asynchronous operation
 *
 * Returns the last error that occurred in asynchronous transfer operation,
 * and resets the status to STATUS_OK.
 *
 * \param[in] dev_inst    Pointer to USART software instance struct 
 *
 * \return 
 * \retval STATUS_OK                No error has occurred 
 * \retval STATUS_ERR_BAD_DATA      
 * \retval STATUS_ERR_BAD_FORMAT     
 * \retval STATUS_ERR_OVERFLOW       
 */
enum status_code usart_async_get_last_error(
		struct usart_dev_inst *const dev_inst)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);

	/* Save current status code */
	enum status_code status_code = dev_inst->status;

	/* Reset status code */
	dev_inst->status = STATUS_OK;

	return status_code;
}

/**
 * \brief Interrupt Handler for USART module
 *
 * Handles interrupts as they occur, and it will run callback functions
 * which are registered and enabled.
 *
 * \note This function will be called by the Sercom_Handler, and should
 * not be called directly from any application code.
 *
 * \param[in]  instance  ID of the SERCOM instance calling the interrupt
 *                       handler.
 */
void usart_async_handler(uint8_t instance)
{
	/* Temporary variables */
	uint16_t interrupt_status;
	uint16_t callback_status;
	uint8_t error_code;

	/* Get device instance from the look-up table */
	struct usart_dev_inst *dev_inst
		= (struct usart_dev_inst *)_sercom_instances[instance];

	/* Sanity check content from the look-up table */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);

	/* Pointer to the hardware module instance */
	SercomUsart *const usart_module
		= &(dev_inst->hw_dev->USART);

	/* Wait for the synchronization to complete */
	_usart_wait_for_sync(dev_inst);

	/* Read and mask interrupt flag register */
	interrupt_status = usart_module->INTFLAG.reg;
	callback_status = dev_inst->callback_reg_mask
			&dev_inst->callback_enable_mask;



	/* Check if a DATA READY interrupt has occurred,
	 * and if there if there is more to transfer */
	if (interrupt_status & SERCOM_USART_INTFLAG_DREIF &&
		dev_inst->remaining_tx_buffer_length) {

		/* Check if there is only one more transmission
		 * to make */
		if (dev_inst->remaining_tx_buffer_length == 1) {
			/* Disable the Data Register Empty Interrupt */
			usart_module->INTENCLR.reg
				= SERCOM_USART_INTFLAG_DREIF;
		}

		/* Write current packet from transmission buffer
		 * and increment buffer pointer */
		if (dev_inst->char_size == USART_CHAR_SIZE_9BIT) {
			usart_module->DATA.reg |= *(dev_inst->tx_buffer_ptr)
					& SERCOM_USART_DATA_MASK;
			dev_inst->tx_buffer_ptr += 2;

		} else {
			usart_module->DATA.reg |= (*(dev_inst->tx_buffer_ptr)
					& SERCOM_USART_DATA_MASK);
			(dev_inst->tx_buffer_ptr)++;

		}

		/* Decrement buffer length */
		(dev_inst->remaining_tx_buffer_length)--;
	}

	/* Check if the Transmission Complete interrupt has occurred and
	 * that the transmit buffer is empty */
	if (((callback_status & interrupt_status) & SERCOM_USART_INTFLAG_TXCIF) &&
			!dev_inst->remaining_tx_buffer_length){


		/* Run callback if registered and enabled */
		if (callback_status
				& USART_CALLBACK_BUFFER_TRANSMITTED) {
			(*(dev_inst->callback[USART_CALLBACK_BUFFER_TRANSMITTED]))(dev_inst);
		}

	}

	/* Check if the Receive Complete interrupt has occurred, and that
	 * the callback is enabled */
	if (((callback_status & interrupt_status) & SERCOM_USART_INTFLAG_RXCIF)){
		/* Check if the reception buffer has data
		 * to receive */
		if (dev_inst->remaining_rx_buffer_length) {
			/* Read out the status code and mask away all but the 4 LSBs*/
			error_code = (uint8_t)(usart_module->STATUS.reg & SERCOM_USART_STATUS_MASK);

			/* Check if an error has occurred during the receiving */
			if (error_code) {
				/* Check which error occurred */
				if (error_code & USART_STATUS_FLAG_FERR) {
					/* Store the error code and clearing
					 * flag by writing 1 to it */
					dev_inst->status = STATUS_ERR_BAD_FORMAT;
					usart_module->STATUS.reg &= ~USART_STATUS_FLAG_FERR;

				} else if (error_code & USART_STATUS_FLAG_BUFOVF) {
					/* Store the error code and clearing
					 * flag by writing 1 to it */
					dev_inst->status = STATUS_ERR_OVERFLOW;
					usart_module->STATUS.reg &= ~USART_STATUS_FLAG_BUFOVF;

				} else if (error_code & USART_STATUS_FLAG_PERR) {
					/* Store the error code and clearing
					 * flag by writing 1 to it */
					dev_inst->status = STATUS_ERR_BAD_DATA;
					usart_module->STATUS.reg &= ~USART_STATUS_FLAG_PERR;
				}

				/* Run callback if registered and enabled */
				if (callback_status
						& USART_CALLBACK_ERROR) {
					(*(dev_inst->callback[USART_CALLBACK_ERROR]))(dev_inst);
				}
			}

			/* Read current packet from DATA register,
			 * increment buffer pointer and decrement buffer length */
			if(dev_inst->char_size == USART_CHAR_SIZE_9BIT) {
				/* Read out from DATA and increment 8bit ptr by two */
				*(dev_inst->rx_buffer_ptr) = (usart_module->DATA.reg & SERCOM_USART_DATA_MASK);
				dev_inst->tx_buffer_ptr += 2;
			} else {
				/* Read out from DATA and increment 8bit ptr by one */
				*(dev_inst->rx_buffer_ptr) = (usart_module->DATA.reg & SERCOM_USART_DATA_MASK);
				dev_inst->tx_buffer_ptr++;
			}

			/* Decrement length of the remaining buffer */
			(dev_inst->remaining_rx_buffer_length)--;

		} else {
			/* If the transmission buffer is empty,
			 * run callback*/

			/* Run callback if registered and enabled */
			if (callback_status
					& USART_CALLBACK_BUFFER_RECEIVED) {
				(*(dev_inst->callback[USART_CALLBACK_BUFFER_RECEIVED]))(dev_inst);
			}
		}
	}
}
