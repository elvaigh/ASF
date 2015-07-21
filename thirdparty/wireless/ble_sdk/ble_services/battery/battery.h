
/**
 * \file
 *
 * \brief Battery Service declarations
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
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


#ifndef __BATTERY_H__
#define __BATTERY_H__

#include "at_ble_api.h"
#include "ble_manager.h"

/** characteristic presentation format value */
#define BAT_CHAR_PRESENTATION_FORMAT_VALUE 0x04

/** characteristic presentation format exponent */
#define BAT_CHAR_PRESENTATION_FORMAT_EXPONENT 0x00

/** characteristic presentation format unit */
#define BAT_CHAR_PRESENTATION_FORMAT_UNIT 	BAT_SERVICE_UUID

/** characteristic presentation format namespace */
#define BAT_CHAR_PRESENTATION_FORMAT_NAMESPACE 0x01

/** characteristic presentation format descriptor */
#define BAT_CHAR_PRESENTATION_FORMAT_DESCRIPTOR 0x0000

/** battery level characteristic value initial and maximum length */
#define BAT_CHAR_BAT_LEVEL_INIT_VALUE 	0x01
#define BAT_CHAR_BAT_LEVEL_MAX_VALUE 	0x01


/**@brief Function used to update characteristic value
 *
 * @param[in] battery_serv gatt service information
 * @param[in] char_len length of the new characteristic value
 * @param[in] char_data new characteristic value information
 * @return @ref AT_BLE_SUCCESS operation completed successfully
 * @return @ref AT_BLE_FAILURE Generic error.
 */
at_ble_status_t bat_update_char_value (gatt_service_handler_t *battery_serv , uint8_t char_len, uint8_t *char_data);

/**@brief Initialize the service with its included service, characteristics, and descriptors
 *
 * @param[in] battery_serv gatt service information
 *
 * @return none
 */
void bat_init_service(gatt_service_handler_t *battery_serv);

/**@brief defining a initialized service 
 *
 * @param[in] battery_service gatt service information
 *
 * @return @ref AT_BLE_SUCCESS operation completed successfully
 * @return @ref AT_BLE_FAILURE Generic error.
 */
at_ble_status_t bat_primary_service_define(gatt_service_handler_t *battery_service);


#endif /* __BATTERY_H__ */