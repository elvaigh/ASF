/**
 *
 * @file mac_associate.c
 *
 * @brief Implements the functionality required for Association.
 *
 *
 * Copyright (c) 2013-2015 Atmel Corporation. All rights reserved.
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
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
 *
 * Licensed under Atmel's Limited License Agreement --> EULA.txt
 */

/* === Includes ============================================================= */
#include <compiler.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "return_val.h"
#include "pal.h"
#include "bmm.h"
#include "qmm.h"
#include "tal.h"
#include "ieee_const.h"
#include "mac_msg_const.h"
#include "mac_api.h"
#include "mac_msg_types.h"
#include "mac_data_structures.h"
#include "stack_config.h"
#include "mac_internal.h"
#include "mac.h"
#include "mac_config.h"
#include "mac_build_config.h"

/* === Macros =============================================================== */

/* Payload length of association request frame. */
#define ASSOC_REQ_PAYLOAD_LEN           (2)

/* Payload length of association response frame. */
#define ASSOC_RESP_PAYLOAD_LEN          (4)

/* === Globals ============================================================== */

/* === Prototypes =========================================================== */

/* === Implementation ======================================================= */

#if (MAC_ASSOCIATION_REQUEST_CONFIRM == 1)

/*
 * @brief Initiates MLME associate confirm message
 *
 * This function creates and appends a MLME associate confirm message
 * into the  internal event queue.
 *
 * @param buf_ptr Buffer for sending MLME associate confirm message to NHLE
 * @param status Status of association
 * @param assoc_short_addr Allocated short address
 */
void mac_gen_mlme_associate_conf(buffer_t *buf_ptr,
		uint8_t status,
		uint16_t assoc_short_addr)
{
	/* Reuse the associate request buffer for associate confirm. */
	mlme_associate_conf_t *assoc_conf
		= (mlme_associate_conf_t *)BMM_BUFFER_POINTER(buf_ptr);

	assoc_conf->cmdcode = MLME_ASSOCIATE_CONFIRM;
	assoc_conf->status = status;
	assoc_conf->AssocShortAddress = assoc_short_addr;

	/* Append the associate confirm message to MAC-NHLE queue. */
	qmm_queue_append(&mac_nhle_q, buf_ptr);
}

#endif /* (MAC_ASSOCIATION_REQUEST_CONFIRM == 1) */

#if (MAC_ASSOCIATION_REQUEST_CONFIRM == 1)

/**
 * @brief Handles the MLME associate request command from the NWK layer
 *
 * The MLME associate request primitive is generated by the next higher layer
 * of an unassociated device and issued to its MAC to request an association
 * with a coordinator.
 *
 * @param m Pointer to MLME association request parameters
 */
void mlme_associate_request(uint8_t *m)
{
	mlme_associate_req_t mar;
	memcpy(&mar, BMM_BUFFER_POINTER((buffer_t *)m),
			sizeof(mlme_associate_req_t));

	/*
	 * Store the buffer which was received from the NHLE as it will be
	 * reused
	 * while sending MLME association confirmation to the NHLE.
	 */
	mac_conf_buf_ptr = m;

#ifndef REDUCED_PARAM_CHECK
	if ((FCF_SHORT_ADDR != mar.CoordAddrMode) &&
			(FCF_LONG_ADDR != mar.CoordAddrMode)) {
		mac_gen_mlme_associate_conf((buffer_t *)m,
				MAC_INVALID_PARAMETER,
				INVALID_SHORT_ADDRESS);

		return;
	}
#endif  /* REDUCED_PARAM_CHECK */

	if (FCF_SHORT_ADDR == mar.CoordAddrMode) {
		ADDR_COPY_DST_SRC_16(mac_pib.mac_CoordShortAddress,
				mar.CoordAddress.short_address);
	} else {
		ADDR_COPY_DST_SRC_64(mac_pib.mac_CoordExtendedAddress,
				mar.CoordAddress.long_address);

		/*
		 * Since the coordinator used its extended address, we need to
		 * mark
		 * this also in its short address.
		 */
		mac_pib.mac_CoordShortAddress = CCPU_ENDIAN_TO_LE16(
				MAC_NO_SHORT_ADDR_VALUE);
	}

	/* Set the PAN ID. */
#if (_DEBUG_ > 0)
	retval_t set_status =
#endif
	set_tal_pib_internal(macPANId, (void *)&mar.CoordPANId);

#if (_DEBUG_ > 0)
	Assert(MAC_SUCCESS == set_status);
#endif

	mac_trx_wakeup();

	/* Build the Association Request command frame. */
	retval_t status, status_2;
	uint8_t frame_len;
	uint8_t *frame_ptr;
	uint8_t *temp_frame_ptr;
	uint16_t fcf;
	uint16_t bc_addr = BROADCAST;

	/*
	 * Use the mlme association request buffer for transmitting an
	 * association request frame.
	 */
	frame_info_t *assoc_req_frame
		= (frame_info_t *)(BMM_BUFFER_POINTER((buffer_t *)m));

	assoc_req_frame->msg_type = ASSOCIATIONREQUEST;
	assoc_req_frame->buffer_header = (buffer_t *)m;

	/* Get the payload pointer. */
	frame_ptr = temp_frame_ptr
				= (uint8_t *)assoc_req_frame +
					LARGE_BUFFER_SIZE -
					ASSOC_REQ_PAYLOAD_LEN - 2; /* Add 2
	                                                           * octets for
	                                                           * FCS. */

	/* Update the payload field. */
	*frame_ptr++ = ASSOCIATIONREQUEST;
	/* Build the capability info. */
	*frame_ptr = mar.CapabilityInformation;

	/* Get the payload pointer again to add the MHR. */
	frame_ptr = temp_frame_ptr;

	/* Update the length. */
	frame_len = ASSOC_REQ_PAYLOAD_LEN +
			2 + /* Add 2 octets for FCS */
			2 + /* 2 octets for Destination PAN-Id */
			2 + /* 2 octets for short Destination Address */
			2 + /* 2 octets for Source PAN-Id */
			8 + /* 8 octets for long Source Address */
			3; /* 3 octets DSN and FCF */

	/* Source address */
	frame_ptr -= 8;

	convert_64_bit_to_byte_array(tal_pib.IeeeAddress, frame_ptr);

	/* Source PAN-Id is broadcast PAN ID */
	frame_ptr -= 2;
	convert_16_bit_to_byte_array(bc_addr, frame_ptr);

	/* Destination address */
	if (FCF_SHORT_ADDR == mar.CoordAddrMode) {
		frame_ptr -= 2;
		convert_16_bit_to_byte_array(mac_pib.mac_CoordShortAddress,
				frame_ptr);

		fcf = FCF_SET_FRAMETYPE(FCF_FRAMETYPE_MAC_CMD) |
				FCF_SET_DEST_ADDR_MODE(FCF_SHORT_ADDR) |
				FCF_SET_SOURCE_ADDR_MODE(FCF_LONG_ADDR) |
				FCF_ACK_REQUEST;
	} else {
		frame_ptr -= 8;
		frame_len += 6; /* Add further 6 octets for long Destination
		                 * Address */

		convert_64_bit_to_byte_array(mac_pib.mac_CoordExtendedAddress,
				frame_ptr);

		fcf = FCF_SET_FRAMETYPE(FCF_FRAMETYPE_MAC_CMD) |
				FCF_SET_DEST_ADDR_MODE(FCF_LONG_ADDR) |
				FCF_SET_SOURCE_ADDR_MODE(FCF_LONG_ADDR) |
				FCF_ACK_REQUEST;
	}

	/* Destination PAN-Id */
	frame_ptr -= 2;
	convert_16_bit_to_byte_array(tal_pib.PANId, frame_ptr);

	/* Set DSN. */
	frame_ptr--;
	*frame_ptr = mac_pib.mac_DSN++;

	/* Set the FCF. */
	frame_ptr -= 2;
	convert_spec_16_bit_to_byte_array(fcf, frame_ptr);

	/* First element shall be length of PHY frame. */
	frame_ptr--;
	*frame_ptr = frame_len;

	/* Finished building of frame. */
	assoc_req_frame->mpdu = frame_ptr;

	/* Set the channel page passed by the request. */
	status = set_tal_pib_internal(phyCurrentPage,
			(void *)&(mar.ChannelPage));

#if (_DEBUG_ > 0)
	Assert(MAC_SUCCESS == status);
#endif

	/* Set the channel passed by the request. */
	status_2 = set_tal_pib_internal(phyCurrentChannel,
			(void *)&(mar.LogicalChannel));

#if (_DEBUG_ > 0)
	Assert(MAC_SUCCESS == status_2);
#endif

	if ((MAC_SUCCESS == status) && (MAC_SUCCESS == status_2)) {
#ifdef BEACON_SUPPORT

		/*
		 * In Beacon network the association request frame is sent with
		 * slotted CSMA-CA if the node is synced before assocaition.
		 * In all other cases the frame is transmitted using unslotted
		 * CSMA-CA.
		 */
		csma_mode_t cur_csma_mode;

		if (MAC_SYNC_BEFORE_ASSOC == mac_sync_state) {
			cur_csma_mode = CSMA_SLOTTED;
		} else {
			cur_csma_mode = CSMA_UNSLOTTED;
		}

		status = tal_tx_frame(assoc_req_frame, cur_csma_mode, true);
#else   /* No BEACON_SUPPORT */

		/*
		 * In Nonbeacon build the association request frame is
		 * transmitted
		 * with unslotted CSMA-CA and frame retry.
		 */
		status = tal_tx_frame(assoc_req_frame, CSMA_UNSLOTTED, true);
#endif  /* BEACON_SUPPORT / No BEACON_SUPPORT */

		if (MAC_SUCCESS == status) {
			MAKE_MAC_BUSY();
		} else {
			mac_gen_mlme_associate_conf((buffer_t *)m,
					MAC_CHANNEL_ACCESS_FAILURE,
					INVALID_SHORT_ADDRESS);

			/* Set radio to sleep if allowed */
			mac_sleep_trans();
		}
	} else {
		mac_gen_mlme_associate_conf((buffer_t *)m,
				MAC_CHANNEL_ACCESS_FAILURE,
				INVALID_SHORT_ADDRESS);

		/* Set radio to sleep if allowed */
		mac_sleep_trans();
	}
} /* mlme_associate_request */

#endif /* (MAC_ASSOCIATION_REQUEST_CONFIRM == 1) */

#if (MAC_ASSOCIATION_INDICATION_RESPONSE == 1)

/**
 * @brief Processes a received association request command frame
 *
 * This function will process a received association request command frame and
 * generates a MLME associate indication to the NHLE.
 *
 * @param assoc_req Specifies a pointer to the received association request
 * frame
 */
void mac_process_associate_request(buffer_t *assoc_req)
{
	/* Use the frame reception buffer for association indication. */
	mlme_associate_ind_t *mai = (mlme_associate_ind_t *)BMM_BUFFER_POINTER(
			assoc_req);

	/*
	 * If the coordinator has macAssociationPermit set to false, and
	 * receives an
	 * association request command from a device, the command shall be
	 * ignored.
	 */
	if (!mac_pib.mac_AssociationPermit) {
		bmm_buffer_free(assoc_req);
		return;
	}

	/* Build the MLME association indication parameters. */
	ADDR_COPY_DST_SRC_64(mai->DeviceAddress,
			mac_parse_data.src_addr.long_address);
	mai->CapabilityInformation
		= mac_parse_data.mac_payload_data.assoc_req_data.
			capability_info;
	mai->cmdcode = MLME_ASSOCIATE_INDICATION;

	/* Append the MLME associate indication to the MAC-NHLE queue. */
	qmm_queue_append(&mac_nhle_q, assoc_req);
}

#endif /* (MAC_ASSOCIATION_INDICATION_RESPONSE == 1) */

#if (MAC_ASSOCIATION_INDICATION_RESPONSE == 1)

/**
 * @brief Entry point from the stack for MLME associate response
 *
 * The MLME associate response primitive is used to initiate a response to a
 * MLME association indication primitive.
 *
 * @param m Pointer to association response parameters
 */
void mlme_associate_response(uint8_t *m)
{
	uint8_t frame_len;
	uint8_t *frame_ptr;
	uint8_t *temp_frame_ptr;
	uint16_t fcf;

	mlme_associate_resp_t mar;
	memcpy(&mar, BMM_BUFFER_POINTER((buffer_t *)m),
			sizeof(mlme_associate_resp_t));

	frame_info_t *assoc_resp_frame
		= (frame_info_t *)BMM_BUFFER_POINTER((buffer_t *)m);

	/*
	 * A MLME associate response can only be processed
	 * in the MAC_PAN_COORD_STARTED or MAC_COORDINATOR state.
	 */
	if ((MAC_PAN_COORD_STARTED != mac_state) &&
			(MAC_COORDINATOR != mac_state)
			) {
		bmm_buffer_free((buffer_t *)m);
		return;
	}

	/* Build the Association Response frame. */
	assoc_resp_frame->msg_type = ASSOCIATIONRESPONSE;

	/* Get the payload pointer. */
	frame_ptr = temp_frame_ptr
				= (uint8_t *)assoc_resp_frame +
					LARGE_BUFFER_SIZE -
					ASSOC_RESP_PAYLOAD_LEN - 2; /* Add 2
	                                                            * octets for
	                                                            * FCS. */

	/* Update the payload field. */
	*frame_ptr++ = ASSOCIATIONRESPONSE;

	/* Add the short address allocated for the device. */
	convert_16_bit_to_byte_array(mar.AssocShortAddress, frame_ptr);
	frame_ptr += 2;

	/* Build the association status. */
	*frame_ptr = mar.status;

	/* Get the payload pointer again to add the MHR. */
	frame_ptr = temp_frame_ptr;

	/* Update the length. */
	frame_len = ASSOC_RESP_PAYLOAD_LEN +
			2 + /* Add 2 octets for FCS */
			2 + /* 2 octets for Destination PAN-Id */
			8 + /* 8 octets for long Destination Address */
			8 + /* 8 octets for long Source Address */
			3; /* 3 octets DSN and FCF */

	/* Source address */
	frame_ptr -= 8;
	convert_64_bit_to_byte_array(tal_pib.IeeeAddress, frame_ptr);

	/* Build the Destination address. */
	frame_ptr -= 8;
	convert_64_bit_to_byte_array(mar.DeviceAddress, frame_ptr);

	/* Build the Destination PAN ID. */
	frame_ptr -= 2;
	convert_16_bit_to_byte_array(tal_pib.PANId, frame_ptr);

	/* Set DSN. */
	frame_ptr--;
	*frame_ptr = mac_pib.mac_DSN++;

	/* Set the FCF. */
	/* Create the frame control field. */
	fcf = FCF_SET_FRAMETYPE(FCF_FRAMETYPE_MAC_CMD) |
			FCF_SET_DEST_ADDR_MODE(FCF_LONG_ADDR) |
			FCF_SET_SOURCE_ADDR_MODE(FCF_LONG_ADDR) |
			FCF_PAN_ID_COMPRESSION |
			FCF_ACK_REQUEST;
	frame_ptr -= 2;
	convert_spec_16_bit_to_byte_array(fcf, frame_ptr);

	/* First element shall be length of PHY frame. */
	frame_ptr--;
	*frame_ptr = frame_len;

	/* Finished building of frame. */
	assoc_resp_frame->mpdu = frame_ptr;

#if (MAC_INDIRECT_DATA_FFD == 1)
	/* Indirect transmission not ongoing yet. */
	assoc_resp_frame->indirect_in_transit = false;
#endif  /* (MAC_INDIRECT_DATA_FFD == 1) */

	/* Append the association response into indirect queue. */
#ifdef ENABLE_QUEUE_CAPACITY
	if (QUEUE_FULL == qmm_queue_append(&indirect_data_q, (buffer_t *)m)) {
		/*
		 * Indirect queue reached the maximum size allowed.
		 * Send the comm status indication with MAC transaction
		 * overflow.
		 */
		mac_mlme_comm_status(MAC_TRANSACTION_OVERFLOW,
				(buffer_t *)m);

		return;
	}

#else
	qmm_queue_append(&indirect_data_q, (buffer_t *)m);
#endif  /* ENABLE_QUEUE_CAPACITY */

	/*
	 * If an FFD does have pending data,
	 * the MAC persistence timer needs to be started.
	 */
	assoc_resp_frame->persistence_time
		= mac_pib.mac_TransactionPersistenceTime;
	mac_check_persistence_timer();
} /* mlme_associate_response */

#endif /* (MAC_ASSOCIATION_INDICATION_RESPONSE == 1) */

#if (MAC_ASSOCIATION_REQUEST_CONFIRM == 1)

/**
 * @brief Processing of an associaton reponse command frame
 *
 * This function processes the received association response
 * command frame.
 *
 * @param assoc_resp Association response receive buffer
 */
void mac_process_associate_response(buffer_t *assoc_resp)
{
	uint16_t panid;
	uint16_t short_addr;
#if (_DEBUG_ > 0)
	retval_t set_status;
#endif
	uint8_t status
		= mac_parse_data.mac_payload_data.assoc_response_data.
			assoc_status;

	/* Free the buffer received for association response frame. */
	bmm_buffer_free(assoc_resp);

	if (ASSOCIATION_SUCCESSFUL == status) {
		/* Set the short address received in association response frame.
		**/
#if (_DEBUG_ > 0)
		set_status =
#endif
		set_tal_pib_internal(macShortAddress,
				(void *)&(mac_parse_data.mac_payload_data.
				assoc_response_data.short_addr));

#if (_DEBUG_ > 0)
		Assert(MAC_SUCCESS == set_status);
#endif
		short_addr
			= mac_parse_data.mac_payload_data.assoc_response_data.
				short_addr;

		ADDR_COPY_DST_SRC_64(mac_pib.mac_CoordExtendedAddress,
				mac_parse_data.src_addr.long_address);

		/* Node is properly associated now */
		mac_state = MAC_ASSOCIATED;
		mac_poll_state = MAC_POLL_IDLE;

		if (MAC_SYNC_BEFORE_ASSOC == mac_sync_state) {
			mac_sync_state = MAC_SYNC_TRACKING_BEACON;
		}
	} else {
		/* Restore the default values. */
		mac_poll_state = MAC_POLL_IDLE;

		panid = macPANId_def;

#if (_DEBUG_ > 0)
		set_status =
#endif
		set_tal_pib_internal(macPANId, (void *)&panid);

#if (_DEBUG_ > 0)
		Assert(MAC_SUCCESS == set_status);
#endif
		mac_pib.mac_CoordShortAddress = macCoordShortAddress_def;
		memset((uint8_t *)&mac_pib.mac_CoordExtendedAddress, 0,
				sizeof(mac_pib.mac_CoordExtendedAddress));
		/* mac_pib.mac_CoordExtendedAddress = CLEAR_ADDR_64; */

		short_addr = INVALID_SHORT_ADDRESS;
	}

	/*
	 * The MLME association request buffer is stored in mac_conf_buf_ptr,
	 * which is reused to generate MLME association confirmation.
	 */
	mac_gen_mlme_associate_conf((buffer_t *)mac_conf_buf_ptr,
			status,
			short_addr);

	/* Set radio to sleep if allowed */
	mac_sleep_trans();
} /* mac_process_associate_response */

#endif /* (MAC_ASSOCIATION_REQUEST_CONFIRM == 1) */

#if (MAC_ASSOCIATION_REQUEST_CONFIRM == 1)

/**
 * @brief Handle T_Poll_Wait_Time timer after successful transmission of an
 *        association request frame and before sending out the subsequent
 *        data request frame.
 *
 * @param callback_parameter Callback parameter.
 */
void mac_t_response_wait_cb(void *callback_parameter)
{
	uint32_t response_time_us;
	retval_t timer_status;
	bool status;

	response_time_us = TAL_CONVERT_SYMBOLS_TO_US(
			mac_pib.mac_ResponseWaitTime);

	/*
	 * IEEE 802.15.4-2006 page 154:
	 *
	 * If the data request command is being sent following the
	 * acknowledgment
	 * to an association request command frame, the Destination Addressing
	 * Mode
	 * subfield of the Frame Control field shall be set according to the
	 * coordinator to which the data request command is directed.
	 * If macCoordShortAddress is equal to 0xfffe, extended addressing
	 * shall be used. Short addressing shall be used otherwise.
	 * The Source Addressing Mode subfield shall be set to use
	 * extended addressing.
	 */

	/*
	 * No explicit destination address attached, so use current values of
	 * PIB attributes macCoordShortAddress or macCoordExtendedAddress.
	 */
	status = mac_build_and_tx_data_req(false, true, 0, NULL, 0);

	if (!status) {
		/*
		 * Data request could not be transmitted, hence association
		 * confirmation
		 * is generated using the buffer stored in mac_conf_buf_ptr.
		 */
		mac_gen_mlme_associate_conf((buffer_t *)mac_conf_buf_ptr,
				MAC_CHANNEL_ACCESS_FAILURE,
				INVALID_SHORT_ADDRESS);
		return;
	}

	timer_status = pal_timer_start(T_Poll_Wait_Time,
			response_time_us,
			TIMEOUT_RELATIVE,
			(FUNC_PTR)mac_t_assocresponsetime_cb, NULL);

#if (_DEBUG_ > 0)
	Assert(MAC_SUCCESS == timer_status);
#endif

	if (MAC_SUCCESS != timer_status) {
		/* Timer could not be started. */
		mac_t_assocresponsetime_cb(NULL);
	}

	callback_parameter = callback_parameter; /* Keep compiler happy. */
}

#endif /* (MAC_ASSOCIATION_REQUEST_CONFIRM == 1) */

#if (MAC_ASSOCIATION_REQUEST_CONFIRM == 1)

/*
 * @brief Handle T_Poll_Wait_Time while waiting for the association reponse
 * frame
 *
 * @param callback_parameter Callback parameter
 */
void mac_t_assocresponsetime_cb(void *callback_parameter)
{
	uint16_t panid;

	/*
	 * Association response is not received within time, hence generate
	 * mlme association confirm with MAC_NO_DATA using the buffer stored in
	 * mac_conf_buf_ptr.
	 */
	mac_gen_mlme_associate_conf((buffer_t *)mac_conf_buf_ptr,
			MAC_NO_DATA,
			BROADCAST);

	/* Restore the mac poll state in case of association failure. */
	mac_poll_state = MAC_POLL_IDLE;

	/* Set the default parameters. */
	panid = macPANId_def;
#if (_DEBUG_ > 0)
	retval_t set_status =
#endif
	set_tal_pib_internal(macPANId, (void *)&panid);

#if (_DEBUG_ > 0)
	Assert(MAC_SUCCESS == set_status);
	set_status = set_status;
#endif
	mac_pib.mac_CoordShortAddress = macCoordShortAddress_def;
	memset((uint8_t *)&mac_pib.mac_CoordExtendedAddress, 0,
			sizeof(mac_pib.mac_CoordExtendedAddress));
	/* mac_pib.mac_CoordExtendedAddress = CLEAR_ADDR_64; */

	/* Set radio to sleep if allowed */
	mac_sleep_trans();

	callback_parameter = callback_parameter; /* Keep compiler happy. */
}

#endif /* (MAC_ASSOCIATION_REQUEST_CONFIRM == 1) */

/* EOF */
