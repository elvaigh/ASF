/**
* \file
*
* \brief Alert Notification Profile declarations
*
* Copyright (c) 2015 Atmel Corporation. All rights reserved.
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
*    Atmel micro controller product.
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

/**
* 
* \section preface Preface
* This is the reference manual for the Time Information Profile
*/

#ifndef __ALERT_NOTIFICATION_PROFILE_H__
#define __ALERT_NOTIFICATION_PROFILE_H__
/***********************************************************************************
 *									Macros			                               *
 **********************************************************************************/
/**@brief Advertisement Interval*/
#define APP_ANP_FAST_ADV							(100) //100 ms

/**@brief Advertisement Timeout*/
#define APP_ANP_ADV_TIMEOUT							(1000) // 100 Secs

/**@brief Scan Response length*/
#define SCAN_RESP_LEN								(10)

#define ADV_TYPE_LEN								(0x01)

/**@brief Appearance type & Length */
#define ANP_ADV_DATA_APPEARANCE_LEN					(2)
#define ANP_ADV_DATA_APPEARANCE_TYPE				(0x19)
#define ANP_ADV_DATA_APPEARANCE_DATA				("\x00\x40")

/**@brief Advertisement Name Type Length & data */
#define ANP_ADV_DATA_NAME_LEN						(9)
#define ANP_ADV_DATA_NAME_TYPE						(0x09)
#define ANP_ADV_DATA_NAME_DATA						("ATMEL-ANS")

/**@brief ANCS Service Solicitation Info*/
#define ANP_ADV_DATA_UUID_LEN						(2)

#define ANP_ADV_DATA_UUID_TYPE						(0x03)


#define SUPPORT_NEW_ALERT_CHAR_UUID					(0x2A47)
#define NEW_ALERT_CHAR_UUID							(0x2A46)
#define SUPPORT_UNREAD_ALERT_CHAR_UUID				(0x2A48)
#define UNREAD_ALERT_STATUS_CHAR_UUID				(0x2A45)
#define ALERT_NOTI_CONTROL_CHAR_UUID				(0x2A44)
#define CLIENT_CHAR_CONF_DESC_UUID					(0x2902)

#define AT_BLE_DISCOVERY_SUCCESS					(10)
#define AT_BLE_INSUFF_RESOURCE						AT_BLE_FAILURE

/***********************************************************************************
 *									types			                               *
 **********************************************************************************/
/* @brief connected callback */
typedef void (*connected_callback_t) (bool);

/***********************************************************************************
 *									Functions		                               *
 **********************************************************************************/
/**
 * @brief Initialize the profile specific information
 * 
 */
void anp_info_init(void);

/**
 * @brief Function used for profile initialization and also enable the advertisement
 * \note Called by the ble_manager
 * 
 */
void anp_client_init( void *params);

/**
 * @brief does all the profile initialization and starts the advertisement
 * \note Called by the ble_manager
 */
void anp_client_adv(void);

/**
 * @brief Handler for connection event 
 * @param[in] connected event parameter containing details like handle
 * \note Called by the ble_manager after receiving connection event
 */
void anp_client_connected_state_handler(at_ble_connected_t *params);

/**
 * @brief Handler for disconnection event
 * @param[in] disconnected event parameter containing details like handle
 * \note Called by the ble_manager after receiving disconnection event
 */
void anp_client_disconnected_event_handler(at_ble_disconnected_t *params);

/**
 * @brief Handler for service found event
 * @param[in] service found event parameter containing details like service handle,uuid
 * \note Called by the ble_manager after receiving service found event
 */
void anp_client_service_found_handler(at_ble_primary_service_found_t * params);

/**
 * @brief Handler for discovery complete event
 * @param[in] discovery complete event which contains result of discovery event
 * \note Called by the ble_manager after receiving discovery complete event
 */
void anp_client_discovery_complete_handler(at_ble_discovery_complete_t *params);

/**
 * @brief Handler for characteristic found event
 * @param[in] characteristic found event parameter containing details like characteristic handle,uuid
 * \note Called by the ble_manager after receiving characteristic found event
 */
void anp_client_characteristic_found_handler(at_ble_characteristic_found_t *params);

/**
 * @brief Handler for descriptor found event
 * @param[in] descriptor found event parameter containing details like descriptor handle,uuid
 * \note Called by the ble_manager after receiving descriptor found event
 */
void anp_client_descriptor_found_handler(at_ble_descriptor_found_t *params);

/**
 * @brief Handler for char changed handler 
 * @param[in] characteristic changed event parameter containing details like characteristic handle,value
 * \note Called by the ble_manager after receiving characteristic change event
 */
void anp_client_char_changed_handler(at_ble_characteristic_changed_t *params);

/**
 * @brief Handler for write response 
 * @param[in] write response parameter contacting the result of write request
 * \note Called by the ble_manager after receiving write response event
 */
void anp_client_write_response_handler(at_ble_characteristic_write_response_t *params);

/**
 * @brief Handler for notification event 
 * @param[in] notification received parameter containing the notification value
 * \note Called by the ble_manager after receiving the notification
 */
void anp_client_notification_handler(at_ble_notification_recieved_t *params);

/**
 * @brief Handler for enabling the notification 
 * \note Called by the ble_manager for enabling the notification in the gatt server
 */
void anp_client_write_notification_handler(void );

/**
 * @brief Handler for read response handle 
 * \note Called by the ble_manager for read response in the gatt server
 */
void anp_client_read_response_handler(at_ble_characteristic_read_response_t *read_response);

/**
 * @brief Handler for discover the services
 * \note Called by the ble_manager for enabling the notification in the gatt server
 */
at_ble_status_t anp_info_service_discover(at_ble_connected_t *conn_params);

/**
 * @brief register the call back for application state
 * @param[in]
 * @return none
 */
void register_connected_callback(connected_callback_t app_connected_cb);

/**
 * @brief invoked by app for disabling the notifications in gatt server
 */
void anp_client_disable_notification(void);

/**
 * @brief invoked by ble manager for setting the notification 
 */
void anp_client_security_done_handler(void *param);

#endif /* __ALERT_NOTIFICATION_PROFILE_H__ */
