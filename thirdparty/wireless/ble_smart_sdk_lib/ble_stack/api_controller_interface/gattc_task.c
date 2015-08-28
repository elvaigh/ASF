/*
 * gattc_task.c
 *
 *  Created on: Jul 19, 2014
 *      Author: delsissy
 */
#include "at_ble_api.h"
//#include "platform_drv.h"
#include "interface.h"

#include "gattc_task.h"
#include "gattm_task.h"


void gattc_write_cmd_ind_handler(uint8_t *msg, uint16_t len)
{
	INTERFACE_MSG_INIT(GATTC_WRITE_CMD_IND, TASK_GATTM);
	INTERFACE_PACK_ARG_BLOCK(msg, len);
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
}

void gattc_send_evt_cmd_handler(uint8_t u8ReqType, uint16_t u16AttHdl, uint16_t u16ConHdl)
{
	INTERFACE_MSG_INIT(GATTC_SEND_EVT_CMD, KE_BUILD_ID(TASK_GATTC, u16ConHdl));
	INTERFACE_PACK_ARG_UINT8(u8ReqType);
	INTERFACE_PACK_ARG_UINT8(0);//zero padding
	INTERFACE_PACK_ARG_UINT16(u16AttHdl);
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
}


void gattc_disc_cmd_handler (uint8_t u8ReqType, uint8_t u8UUIDLen, uint16_t u16StartHdl, 
							 uint16_t u16EndHdl, uint8_t* pu8UUID, uint16_t u16ConHdl)
{
	INTERFACE_MSG_INIT(GATTC_DISC_CMD, KE_BUILD_ID(TASK_GATTC, u16ConHdl));
	INTERFACE_PACK_ARG_UINT8(u8ReqType);
	if(pu8UUID == NULL)
	{
		// even if no UUID is sent this must be a valid value to pass some error check in FW
		INTERFACE_PACK_ARG_UINT8(2);
	}
	else
	{
		INTERFACE_PACK_ARG_UINT8(u8UUIDLen);
	}
	INTERFACE_PACK_ARG_UINT16(u16StartHdl);
	INTERFACE_PACK_ARG_UINT16(u16EndHdl);
	if(pu8UUID == NULL)
	{
		INTERFACE_PACK_ARG_UINT16(0); // padding in case of no value
	}
	else
	{
		INTERFACE_PACK_ARG_BLOCK(pu8UUID, u8UUIDLen);
	}
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
}

void gattc_reg_to_peer_handler(uint8_t u8ReqType, uint16_t u16StartHdl, uint16_t u16EndHdl,
							   uint16_t u16ConHdl)
{
	INTERFACE_MSG_INIT(GATTC_REG_TO_PEER_EVT_CMD, KE_BUILD_ID(TASK_GATTC, u16ConHdl));
	INTERFACE_PACK_ARG_UINT8(u8ReqType);
	INTERFACE_PACK_ARG_UINT8(0); //zero padding
	INTERFACE_PACK_ARG_UINT16(u16StartHdl);
	INTERFACE_PACK_ARG_UINT16(u16EndHdl);
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
}

void gattc_execute_write_cmd_handler(uint8_t u8Execute, uint16_t u16ConHdl)
{
	INTERFACE_MSG_INIT(GATTC_EXECUTE_WRITE_CMD, KE_BUILD_ID(TASK_GATTC, u16ConHdl));
	INTERFACE_PACK_ARG_UINT8(GATTC_EXEC_WRITE);
	INTERFACE_PACK_ARG_UINT8(u8Execute); 
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
}

	
void gattc_write_cmd_handler(uint8_t u8ReqType, uint8_t u8AutoExec, uint16_t u16AttHdl, uint16_t u16Offset,
							 uint16_t u16Length, uint8_t* pu8Val, uint16_t u16ConHdl)
{
	INTERFACE_MSG_INIT(GATTC_WRITE_CMD, KE_BUILD_ID(TASK_GATTC, u16ConHdl));
	INTERFACE_PACK_ARG_UINT8(u8ReqType);
	INTERFACE_PACK_ARG_UINT8(u8AutoExec); 
	INTERFACE_PACK_ARG_UINT16(u16AttHdl);
	INTERFACE_PACK_ARG_UINT16(u16Offset);
	INTERFACE_PACK_ARG_UINT16(u16Length);
	INTERFACE_PACK_ARG_UINT16(0); // Internal write cursor shall be initialized to 0
	INTERFACE_PACK_ARG_BLOCK(pu8Val, u16Length);
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
}

void gattc_read_cmd_handler_by_uuid(uint16_t u16StartHdl, uint16_t u16EndHdl,
							 uint8_t u8UUIDLen, uint8_t *pu8UUID, uint16_t u16ConHdl)
{
	INTERFACE_MSG_INIT(GATTC_READ_CMD, KE_BUILD_ID(TASK_GATTC, u16ConHdl));
	INTERFACE_PACK_ARG_UINT8(GATTC_READ_BY_UUID);
	INTERFACE_PACK_ARG_UINT8(0); 
	INTERFACE_PACK_ARG_UINT16(u16StartHdl);
	INTERFACE_PACK_ARG_UINT16(u16EndHdl);
	INTERFACE_PACK_ARG_UINT8(u8UUIDLen);
	INTERFACE_PACK_ARG_BLOCK(pu8UUID, u8UUIDLen);
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
}

void gattc_read_cmd_handler_simple_read(uint16_t u16Handle, uint16_t u16Offset,
							 uint16_t u16Len, uint16_t u16ConHdl)
{
	INTERFACE_MSG_INIT(GATTC_READ_CMD, KE_BUILD_ID(TASK_GATTC, u16ConHdl));
	INTERFACE_PACK_ARG_UINT8(GATTC_READ);
	INTERFACE_PACK_ARG_UINT8(0); 
	INTERFACE_PACK_ARG_UINT16(u16Handle);
	INTERFACE_PACK_ARG_UINT16(u16Offset);
	INTERFACE_PACK_ARG_UINT16(u16Len);
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
}

void gattc_read_cmd_handler_multible(uint16_t* u16Handle_list, uint8_t u8Count,
							 uint16_t* u16Length_list, uint16_t u16ConHdl)
{
	uint8_t counter;
	
	INTERFACE_MSG_INIT(GATTC_READ_CMD, KE_BUILD_ID(TASK_GATTC, u16ConHdl));
	INTERFACE_PACK_ARG_UINT8(GATTC_READ_MULTIPLE);
	INTERFACE_PACK_ARG_UINT8(u8Count);
	for(counter = 0; counter < u8Count; counter++)
	{
		INTERFACE_PACK_ARG_UINT16(u16Handle_list[counter]);
		INTERFACE_PACK_ARG_UINT16(u16Length_list[counter]);
	}
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
}

void gattc_write_cmd_ind(uint16_t src, uint8_t* data, at_ble_characteristic_changed_t *params)
{
	uint8_t resp, last;

	params->conn_handle =  KE_IDX_GET(src);
	
	INTERFACE_UNPACK_INIT(data);
	INTERFACE_UNPACK_UINT16(&(params->char_handle));
	INTERFACE_UNPACK_UINT16(&(params->char_len));
	INTERFACE_UNPACK_UINT16(&(params->char_offset));
	INTERFACE_UNPACK_UINT8(&resp);
	INTERFACE_UNPACK_UINT8(&last);
	INTERFACE_UNPACK_BLOCK(params->char_new_value, params->char_len);
	INTERFACE_DONE();

	INTERFACE_MSG_INIT(GATTC_WRITE_CMD_IND, TASK_GATTM);
	INTERFACE_PACK_ARG_UINT16(params->char_handle);
	INTERFACE_PACK_ARG_UINT16(params->char_len);
	INTERFACE_PACK_ARG_UINT16(params->char_offset);
	INTERFACE_PACK_ARG_UINT8(resp);
	INTERFACE_PACK_ARG_UINT8(last);
	INTERFACE_PACK_ARG_BLOCK(params->char_new_value, params->char_len);
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
#if 0
	gattm_att_set_value_req_handler(params->char_handle, params->char_len, params->char_new_value);
	
	INTERFACE_MSG_INIT(GATTC_WRITE_CMD_CFM, src);
	INTERFACE_PACK_ARG_UINT16(params->char_handle);
	INTERFACE_PACK_ARG_UINT8(0);
	INTERFACE_PACK_ARG_UINT8(resp);
	INTERFACE_SEND_NO_WAIT();
	INTERFACE_DONE();
#endif

}

void gattc_disc_svc_ind_parser(uint16_t src, uint8_t* data, at_ble_primary_service_found_t* params)
{
	uint8_t uuid_len;
	
	params->conn_handle = KE_IDX_GET(src);
	INTERFACE_UNPACK_INIT(data);
	INTERFACE_UNPACK_UINT16(&params->start_handle);
	INTERFACE_UNPACK_UINT16(&params->end_handle);
	INTERFACE_UNPACK_UINT8(&uuid_len);
	params->service_uuid.type = at_ble_uuid_len2type(uuid_len);
	INTERFACE_UNPACK_BLOCK(params->service_uuid.uuid, uuid_len);
	INTERFACE_DONE();
}

void gattc_disc_svc_incl_ind_parser(uint16_t src, uint8_t* data, at_ble_included_service_found_t* params)
{
	uint8_t uuid_len;
	
	params->conn_handle = KE_IDX_GET(src);
	INTERFACE_UNPACK_INIT(data);
	INTERFACE_UNPACK_UINT16(&params->attr_handle);
	INTERFACE_UNPACK_UINT16(&params->start_handle);
	INTERFACE_UNPACK_UINT16(&params->end_handle);
	INTERFACE_UNPACK_UINT8(&uuid_len);
	params->service_uuid.type = at_ble_uuid_len2type(uuid_len);
	INTERFACE_UNPACK_BLOCK(params->service_uuid.uuid, uuid_len);
	INTERFACE_DONE();
}

void gattc_disc_char_ind_parser(uint16_t src, uint8_t* data, at_ble_characteristic_found_t* params)
{
	uint8_t uuid_len;
	
	params->conn_handle = KE_IDX_GET(src);

	INTERFACE_UNPACK_INIT(data);
	INTERFACE_UNPACK_UINT16(&params->char_handle);
	INTERFACE_UNPACK_UINT16(&params->value_handle);
	INTERFACE_UNPACK_UINT8(&params->properties);
	INTERFACE_UNPACK_UINT8(&uuid_len);
	params->char_uuid.type = at_ble_uuid_len2type(uuid_len);
	INTERFACE_UNPACK_BLOCK(params->char_uuid.uuid, uuid_len);
	INTERFACE_DONE();
}

void gattc_disc_char_desc_ind_parser(uint16_t src, uint8_t* data, at_ble_descriptor_found_t* params)
{
	uint8_t uuid_len;
	
	params->conn_handle = KE_IDX_GET(src);

	INTERFACE_UNPACK_INIT(data);
	INTERFACE_UNPACK_UINT16(&params->desc_handle);
	INTERFACE_UNPACK_UINT8(&uuid_len);
	params->desc_uuid.type = at_ble_uuid_len2type(uuid_len);
	INTERFACE_UNPACK_BLOCK(params->desc_uuid.uuid, uuid_len);
	INTERFACE_DONE();
}

void gattc_read_ind_parser(uint16_t src, uint8_t* data, at_ble_characteristic_read_response_t* params)
{
	params->conn_handle = KE_IDX_GET(src);

	INTERFACE_UNPACK_INIT(data);
	INTERFACE_UNPACK_UINT16(&params->char_handle);
	INTERFACE_UNPACK_UINT16(&params->char_offset);
	INTERFACE_UNPACK_UINT16(&params->char_len);
	INTERFACE_UNPACK_BLOCK(params->char_value, params->char_len);
	INTERFACE_DONE();
}

at_ble_events_t gattc_event_ind_parser(uint16_t src, uint8_t* data, void* params)
{
	uint8_t type;
	at_ble_events_t evt;
	
	INTERFACE_UNPACK_INIT(data);
	INTERFACE_UNPACK_UINT8(&type);
	INTERFACE_UNPACK_SKIP(1);

	if(type == GATTC_NOTIFY)
	{
		at_ble_notification_recieved_t *params_notify = (at_ble_notification_recieved_t*)params;
		evt = AT_BLE_NOTIFICATION_RECIEVED;
		params_notify->conn_handle = KE_IDX_GET(src);
		INTERFACE_UNPACK_UINT16(&(params_notify->char_len));
		INTERFACE_UNPACK_UINT16(&(params_notify->char_handle));
		INTERFACE_UNPACK_BLOCK(params_notify->char_value, params_notify->char_len);
	}


	if(type == GATTC_INDICATE)
	{
		at_ble_indication_recieved_t *params_indicate = (at_ble_indication_recieved_t*)params;
		evt = AT_BLE_INDICATION_RECIEVED;
		params_indicate->conn_handle = KE_IDX_GET(src);
		INTERFACE_UNPACK_UINT16(&(params_indicate->char_len));
		INTERFACE_UNPACK_UINT16(&(params_indicate->char_handle));
		INTERFACE_UNPACK_BLOCK(params_indicate->char_value, params_indicate->char_len);
	}

	INTERFACE_DONE();

	return evt;
}

at_ble_events_t gattc_complete_evt_handler(uint16_t src, uint8_t* data, void* params)
{
	uint8_t req_type, status;
	at_ble_events_t evt = AT_BLE_UNDEFINED_EVENT;

	INTERFACE_UNPACK_INIT(data);
	INTERFACE_UNPACK_UINT8(&req_type);
	INTERFACE_UNPACK_UINT8(&status);
	INTERFACE_DONE();

	if(	(req_type == GATTC_DISC_ALL_SVC)		|| 
		(req_type == GATTC_DISC_BY_UUID_SVC)	||
		(req_type == GATTC_DISC_INCLUDED_SVC)	||
		(req_type == GATTC_DISC_ALL_CHAR)		||
		(req_type == GATTC_DISC_BY_UUID_CHAR)	||
		(req_type == GATTC_DISC_DESC_CHAR))
	{
		if((status == AT_BLE_SUCCESS) || (status == ATT_ERR_ATTRIBUTE_NOT_FOUND))
		{
			((at_ble_discovery_complete_t*)params)->status = AT_BLE_DISCOVERY_SUCCESS;
		}
		else
		{
			((at_ble_discovery_complete_t*)params)->status = AT_BLE_DISCOVERY_FAILURE;
		}
		evt = AT_BLE_DISCOVERY_COMPLETE;
	}
	
	return evt;
}
