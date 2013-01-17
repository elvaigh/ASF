/**
 * \file
 *
 * \brief SAMD20 External Interrupt Driver Quick Start
 *
 * Copyright (C) 2012-2013 Atmel Corporation. All rights reserved.
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
#include "extint.h"
#include "extint_async.h"

/**
 * \internal
 * Internal driver device instance struct, declared in the main module driver.
 */
extern struct _extint_device _extint_dev;

/**
 * \brief Registers an asynchronous callback function with the driver.
 *
 * Registers an asynchronous callback with the EXTINT driver, fired when a
 * channel detects the configured channel detection criteria
 * (e.g. edge or level). Callbacks are fired once for each detected channel.
 *
 * \param callback  Pointer to the callback function to register
 * \param type      Type of callback function to register
 *
 * \return Status of the registration operation.
 * \retval STATUS_OK             The callback was registered successfully.
 * \retval STATUS_ERR_NO_MEMORY  No free entries were found in the registration
 *                               table.
 */
enum status_code extint_async_register_callback(
	extint_async_callback_t callback,
	enum extint_async_type type)
{
	for (uint8_t i = 0; i < EXTINT_CALLBACKS_MAX; i++) {
		if (_extint_dev.callbacks[i].handler == NULL) {
			_extint_dev.callbacks[i].type    = type;
			_extint_dev.callbacks[i].handler = callback;
			return STATUS_OK;
		}
	}

	Assert(false);
	return STATUS_ERR_NO_MEMORY;
}

/**
 * \brief De-registers an asynchronous callback function with the driver.
 *
 * De-registers an asynchronous callback with the EXTINT driver, removing it
 * from the internal callback registration table.
 *
 * \param callback  Pointer to the callback function to de-register
 *
 * \return Status of the de-registration operation.
 * \retval STATUS_OK             The callback was de-registered successfully.
 * \retval STATUS_ERR_NO_MEMORY  No matching entry was found in the registration
 *                               table.
 */
enum status_code extint_async_unregister_callback(
	extint_async_callback_t callback)
{
	for (uint8_t i = 0; i < EXTINT_CALLBACKS_MAX; i++) {
		if (_extint_dev.callbacks[i].handler == callback) {
			_extint_dev.callbacks[i].handler = NULL;
			return STATUS_OK;
		}
	}

	return STATUS_ERR_BAD_ADDRESS;
}

void EIC_IRQn_Handler(void);
void EIC_IRQn_Handler(void)
{
	/* Find any triggered channels, run associated callback handlers */
	for (uint32_t i = 0; i < (32 * EIC_INST_NUM); i++) {
		if (extint_ch_is_detected(i)) {
			/* Find any associated callback entries in the callback table */
			for (uint8_t j = 0; j < EXTINT_CALLBACKS_MAX; j++) {
				if (_extint_dev.callbacks[j].type !=
						EXTINT_ASYNC_TYPE_CHANNEL) {
					continue;
				}

				if (_extint_dev.callbacks[j].handler != NULL) {
					/* Run the registered callback */
					_extint_dev.callbacks[j].handler(i);
				}
			}

			extint_ch_clear_detected(i);
		}
	}

	/* Find any triggered NMI channels, run associated callback handlers */
	for (uint32_t k = 0; k < EIC_INST_NUM; k++) {
		if (extint_nmi_is_detected(k)) {
			/* Find any associated callback entries in the callback table */
			for (uint8_t l = 0; l < EXTINT_CALLBACKS_MAX; l++) {
				if (_extint_dev.callbacks[l].type !=
						EXTINT_ASYNC_TYPE_NMI) {
					continue;
				}

				if (_extint_dev.callbacks[l].handler != NULL) {
					/* Run the registered callback */
					_extint_dev.callbacks[l].handler(k);
				}
			}

			extint_nmi_clear_detected(k);
		}
	}
}
