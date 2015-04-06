#ifndef SERVER_DEBUG_H
#define SERVER_DEBUG_H

typedef enum {
	READ_MEMORY_REQUEST = 0x00,
	READ_MEMORY_CONFIRM,
	READ_MEMORY_INDICATION,
	WRITE_MEMORY_REQUEST,
	WRITE_MEMORY_CONFIRM,
	WRITE_MEMORY_INDICATION,
	LOG_REQUEST,
	LOG_CONFIRM,
	LOG_INDICATION,
	TRACE_REQUEST,
	TRACE_CONFIRM,
	TRACE_INDICATION,
	DEBUG_ERROR_MSG = 0xF0
}debug_msg_code_t;

typedef enum {
	DEBUG_OTA_IDLE,
	READ_MEMORY_REQUEST_SENT,
	WRITE_MEMORY_REQUEST_SENT,
	LOG_REQUEST_SENT,
	TRACE_REQUEST_SENT
}debug_widbg_state_t;

#endif /* SERVER_DEBUG_H */
