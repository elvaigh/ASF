/**
 * @file serial_interface.c
 *
 * @brief RF4CE Serial Interface Implementation
 *
 * $Id: serial_interface.c 32659 2012-07-16 11:37:19Z agasthian.s $
 *
 * @author    Atmel Corporation: http://www.atmel.com
 * @author    Support email: avr@atmel.com
 */
/*
 * Copyright (c) 2009, Atmel Corporation All rights reserved.
 *
 * Licensed under Atmel's Limited License Agreement --> EULA.txt
 */

#ifdef SIO_HUB

/* === INCLUDES ============================================================ */

#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "pal.h"
#include "nwk_msg_code.h"
#include "serial_interface.h"
#include "sio_helper.h"
#include "rf4ce.h"

/* === MACROS ============================================================== */

/* UART communication framing */

/** The start of transmission delimiter. */
#define SOT                             (1)

/** The end of transmission delimiter. */
#define EOT                             (4)

/**
 * A UART state that expects a \ref SOT to be received as the next character.
 */
#define UART_RX_STATE_SOT               (1)

/**
 * A UART state that expects the length to be received as the next character.
 */
#define UART_RX_STATE_LENGTH            (2)

/**
 * A UART state that expects the length to be received as the next character.
 */
#define UART_RX_PROTOCOL_ID             (3)

/**
 * A UART state that expects the next data character to be received.
 */
#define UART_RX_STATE_DATA              (4)

/**
 * A UART state that expects a \ref EOT to be received as the next character.
 */
#define UART_RX_STATE_EOT               (5)

#define SIO_BUF_COUNT                   (2)

#define SIO_RX_BUF_SIZE                 (200)
#define SIO_TX_BUF_SIZE                 SIO_RX_BUF_SIZE

#ifdef UART0
#define SIO_CHANNEL                     (SIO_0)
#endif
#ifdef UART1
#define SIO_CHANNEL                     (SIO_1)
#endif
#ifdef USB0
#define SIO_CHANNEL                     (SIO_2)
#endif

/* === Globals ============================================================= */

/**
 * This is the receive buffer of the UART.
 */
static uint8_t sio_rx_buf[SIO_RX_BUF_SIZE];

/**
 * This is the transmit buffer of the UART.
 */
static uint8_t sio_tx_buf[SIO_BUF_COUNT][SIO_TX_BUF_SIZE];

/**
 * This pointer points to the next free element inside the
 * receive buffer of the UART.
 */
static uint8_t *sio_rx_ptr;

/**
 * This is the receiver state of the UART. (\ref UART_RX_STATE_SOT,
 *   \ref UART_RX_STATE_LENGTH, \ref UART_RX_STATE_DATA, or
 *   \ref UART_RX_STATE_EOT)
 */
static volatile uint8_t sio_rx_state;

/**
 * This is the transmit state of the UART. (\ref UART_TX_STATE_SOT,
 *   \ref UART_TX_STATE_LENGTH, \ref UART_TX_STATE_DATA, or
 *   \ref UART_TX_STATE_EOT)
 */
//volatile uint8_t sio_tx_state;

/**
 * This is the length of the message should be received.
 */
static uint8_t sio_rx_length;


/**
 * This is the length of the message should be transmitted.
 */
static uint8_t data[SIO_RX_BUF_SIZE];
static uint8_t data_length = 0;
static uint8_t rx_index = 0;
static uint8_t head = 0, buf_count = 0;

static uint8_t protocol_id;

#ifdef RF4CE_CALLBACK_PARAM
static nwk_indication_callback_t nwk_ind;
#endif

/* === Prototypes ========================================================== */

static inline void process_incoming_sio_data(void);
static uint8_t *get_next_tx_buffer(void);
static inline void handle_incoming_msg(void);

#ifdef RF4CE_CALLBACK_PARAM
static void nlde_data_confirm(nwk_enum_t Status, uint8_t PairingRef, profile_id_t ProfileId
#if (defined NLDE_HANDLE) || (defined DOXYGEN)
                              , uint8_t Handle
#endif
                             );
static void nlme_start_confirm(nwk_enum_t Status);
static void nlme_get_confirm(nwk_enum_t Status, nib_attribute_t NIBAttribute,
                             uint8_t NIBAttributeIndex, void *NIBAttributeValue);
static void nlme_set_confirm(nwk_enum_t Status, nib_attribute_t NIBAttribute, uint8_t NIBAttributeIndex);
static void nlme_rx_enable_confirm(nwk_enum_t Status);
static void nlme_reset_confirm(nwk_enum_t Status);
static void nlme_pair_confirm(nwk_enum_t Status, uint8_t PairingRef, uint16_t RecVendorId,
                              uint8_t RecVendorString[7], uint8_t RecAppCapabilities,
                              uint8_t RecUserString[15], dev_type_t RecDevTypeList[3],
                              profile_id_t RecProfileIdList[7]);
static void nlme_discovery_confirm(nwk_enum_t Status, uint8_t NumNodes,
                                   node_desc_t *NodeDescList);

#if (defined CHANNEL_AGILITY) || (defined RF4CE_PLATFORM)
static void nwk_ch_agility_confirm(nwk_enum_t Status, bool ChannelChanged, uint8_t LogicalChannel);
#endif
#if ((NWK_UPDATE_KEY == 1) && (defined RF4CE_SECURITY)) || (defined RF4CE_PLATFORM)
static void nlme_update_key_confirm(nwk_enum_t Status, uint8_t PairingRef);
#endif
#if (NWK_UNPAIR_REQ_CONF == 1) || (defined RF4CE_PLATFORM)
static void nlme_unpair_confirm(uint8_t Status, uint8_t PairingRef);
#endif
#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
static void nlme_auto_discovery_confirm(nwk_enum_t Status, uint64_t SrcIEEEAddr);
#endif

#if (defined CHANNEL_AGILITY) || (defined RF4CE_PLATFORM)
static void nwk_ch_agility_indication(uint8_t LogicalChannel);
#endif

#if ((NWK_UNPAIR_IND_RESP == 1) || (defined RF4CE_PLATFORM))
static void nlme_unpair_indication(uint8_t PairingRef);
#endif

#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
static void nlme_pair_indication(nwk_enum_t Status, uint16_t SrcPANId, uint64_t SrcIEEEAddr,
                                 uint8_t OrgNodeCapabilities, uint16_t OrgVendorId,
                                 uint8_t OrgVendorString[7], uint8_t OrgAppCapabilities,
                                 uint8_t OrgUserString[15], dev_type_t OrgDevTypeList[3],
                                 profile_id_t OrgProfileIdList[7], uint8_t KeyExTransferCount,
                                 uint8_t ProvPairingRef);
#endif

#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
static void nlme_discovery_indication(nwk_enum_t Status, uint64_t SrcIEEEAddr,
                                      uint8_t OrgNodeCapabilities, uint16_t OrgVendorId,
                                      uint8_t OrgVendorString[7], uint8_t OrgAppCapabilities,
                                      uint8_t OrgUserString[15], dev_type_t OrgDevTypeList[3],
                                      profile_id_t OrgProfileIdList[7],
                                      dev_type_t SearchDevType, uint8_t RxLinkQuality);
#endif
#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
static void nlme_comm_status_indication(nwk_enum_t Status, uint8_t PairingRef,
                                        uint16_t DstPANId, uint8_t DstAddrMode,
                                        uint64_t DstAddr);
#endif

static void nlde_data_indication(uint8_t PairingRef, profile_id_t ProfileId,
                                 uint16_t VendorId, uint8_t nsduLength, uint8_t *nsdu,
                                 uint8_t RxLinkQuality, uint8_t RxFlags);
void nwk_indication_callback_init(void);


#endif

/* === Implementation ====================================================== */

#ifdef RF4CE_CALLBACK_PARAM
void nwk_indication_callback_init(void)
{
    nwk_ind.nlde_data_indication_cb = nlde_data_indication;
#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
    nwk_ind.nlme_comm_status_indication_cb = nlme_comm_status_indication;
#endif
#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
    nwk_ind.nlme_discovery_indication_cb = nlme_discovery_indication;
#endif
#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
    nwk_ind.nlme_pair_indication_cb = nlme_pair_indication;
#endif
#if (defined CHANNEL_AGILITY) || (defined RF4CE_PLATFORM)
    nwk_ind.nwk_ch_agility_indication_cb = nwk_ch_agility_indication;
#endif
#if ((NWK_UNPAIR_IND_RESP == 1) || (defined RF4CE_PLATFORM))
    nwk_ind.nlme_unpair_indication_cb =  nlme_unpair_indication;
#endif

    register_nwk_indication_callback(&nwk_ind);
}
#endif
/**
 * @brief This function does the initialization of the SIO or UART.
 */
void serial_interface_init(void)
{
    sio_rx_state = UART_RX_STATE_SOT;
    sio_init();
}


/**
 * @brief Function to handle the state machine serial data exchange.
 */
void serial_data_handler(void)
{
    /* Rx processing */
    if (data_length == 0)
    {
        /* No data to process, read the stream IO */
        rx_index = 0;
        data_length = sio_rx(data, SIO_RX_BUF_SIZE);
    }
    else    /* Data has been received, process the data */
    {
        /* Process each single byte */
        process_incoming_sio_data();
        data_length--;
        rx_index++;
    }

    /* Tx processing */
    if (buf_count != 0)
    {
        if (sio_tx(sio_tx_buf[head], (sio_tx_buf[head][1] + 3)) != 0)
        {
            head++;
            head %= SIO_BUF_COUNT;
            buf_count--;
        }
        else
        {
            // @ToDo what happens if none or only a part of the bytes could be transmitted?
        }
    }
}


/*
 * @brief Process data received from SIO
 */
static inline void process_incoming_sio_data(void)
{
    switch (sio_rx_state)
    {
        case UART_RX_STATE_SOT:
            sio_rx_ptr = sio_rx_buf;
            if (SOT == data[rx_index])
            {
                sio_rx_state = UART_RX_STATE_LENGTH;
            }
            break;

        case UART_RX_STATE_LENGTH:
            sio_rx_length = data[rx_index];
            if (sio_rx_length)
            {
                sio_rx_state = UART_RX_PROTOCOL_ID;
                *sio_rx_ptr = sio_rx_length;
                sio_rx_ptr++;
            }
            else
            {
                /* NULL message */
                sio_rx_ptr = sio_rx_buf;
                sio_rx_state = UART_RX_STATE_SOT;
            }
            break;

		case UART_RX_PROTOCOL_ID:
            
            protocol_id = data[rx_index];
			sio_rx_length--;
            sio_rx_state = UART_RX_STATE_DATA;
          
            break;
			
        case UART_RX_STATE_DATA:
            *sio_rx_ptr = data[rx_index];
            sio_rx_ptr++;
            sio_rx_length--;
            if (!sio_rx_length)
            {
                sio_rx_state = UART_RX_STATE_EOT;
            }
            break;

        case UART_RX_STATE_EOT:
            if (EOT == data[rx_index])
            {
			    if(RF4CONTROL_PID == protocol_id)
                {
                    /* Message received successfully */
                    handle_incoming_msg();
				}
            }
            /* Make rx buffer ready for next reception before handling received data. */
            sio_rx_ptr = sio_rx_buf;
            sio_rx_state = UART_RX_STATE_SOT;
            break;

        default:
            sio_rx_ptr = sio_rx_buf;
            sio_rx_state = UART_RX_STATE_SOT;
            break;
    }
}


static uint8_t *get_next_tx_buffer(void)
{
    if (buf_count != SIO_BUF_COUNT)
    {
        uint8_t *buf;
        uint8_t tail;

        tail = (head + buf_count) % SIO_BUF_COUNT;
        buf = (uint8_t *)(&sio_tx_buf[tail]);
        buf_count++;
        /* Add message start character */
        *buf++ = SOT;
        return buf;
    }

    return NULL;
}


static inline void handle_incoming_msg(void)
{
    bool ret_val;

    switch (sio_rx_buf[1])  /* message type */
    {
        case NLDE_DATA_REQUEST:
            /* Attention: The TxOption field is moved before the nsduLength field! */
            ret_val = nlde_data_request(sio_rx_buf[2], (profile_id_t)sio_rx_buf[3],
                                        ((uint16_t)sio_rx_buf[4] | ((uint16_t)sio_rx_buf[5] << 8)),    /* VendorId */
                                        sio_rx_buf[7],     /* nsduLength */
                                        &sio_rx_buf[8],
                                        sio_rx_buf[6]     /* TxOptions */
#ifdef NLDE_HANDLE
                                        , 1              /*handle for data retrty*/
#endif
#ifdef RF4CE_CALLBACK_PARAM
                                        , (FUNC_PTR)nlde_data_confirm
#endif
                                       );
            break;

#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
        case NLME_AUTO_DISCOVERY_REQUEST:
#if (UC3) || (SAM)
            {
                dev_type_t RecDevTypeList[DEVICE_TYPE_LIST_SIZE];
                profile_id_t RecProfileIdList[PROFILE_ID_LIST_SIZE];
                uint32_t AutoDiscDuration;

                for (uint8_t i = 0; i < DEVICE_TYPE_LIST_SIZE; i++)
                {
                    RecDevTypeList[i] = (dev_type_t)sio_rx_buf[3 + i];
                }
                for (uint8_t i = 0; i < PROFILE_ID_LIST_SIZE; i++)
                {
                    RecProfileIdList[i] = (profile_id_t)sio_rx_buf[6 + i];
                }
                MEMCPY_ENDIAN(&AutoDiscDuration, &sio_rx_buf[13], sizeof(uint32_t));

                ret_val = nlme_auto_discovery_request(sio_rx_buf[2], // RecAppCapabilities
                                                      RecDevTypeList,//(dev_type_t *)&sio_rx_buf[3],
                                                      RecProfileIdList,//(profile_id_t *)&sio_rx_buf[3 + 3],
                                                      AutoDiscDuration//*(uint32_t *)&sio_rx_buf[3 + 3 + 7]);
#ifdef RF4CE_CALLBACK_PARAM
                                                      , (FUNC_PTR)nlme_auto_discovery_confirm
#endif
                                                     );
            }
#else
            ret_val = nlme_auto_discovery_request(sio_rx_buf[2],
                                                  (dev_type_t *)&sio_rx_buf[3],
                                                  (profile_id_t *)&sio_rx_buf[3 + 3],
                                                  *(uint32_t *)&sio_rx_buf[3 + 3 + 7]
#ifdef RF4CE_CALLBACK_PARAM
                                                  , (FUNC_PTR)nlme_auto_discovery_confirm
#endif
                                                 );
#endif
            break;
#endif

        case NLME_DISCOVERY_REQUEST:
#if (UC3) || (SAM)
            {
#if (UC3) 
                uint16_t PANId = ((uint16_t)sio_rx_buf[2] << 8) | (uint16_t)sio_rx_buf[3];
                uint16_t NwkAddr = ((uint16_t)sio_rx_buf[4] << 8) | (uint16_t)sio_rx_buf[5];
#else
                uint16_t PANId = (uint16_t)sio_rx_buf[2] | ((uint16_t)sio_rx_buf[3] << 8);
                uint16_t NwkAddr = (uint16_t)sio_rx_buf[4] | ((uint16_t)sio_rx_buf[5] << 8);
#endif
                dev_type_t dev_type_list[DEVICE_TYPE_LIST_SIZE];
                for (uint8_t i = 0; i < DEVICE_TYPE_LIST_SIZE; i++)
                {
                    dev_type_list[i] = (dev_type_t)sio_rx_buf[7 + i];
                }
                profile_id_t org_profile_id_list[PROFILE_ID_LIST_SIZE];
                for (uint8_t i = 0; i < PROFILE_ID_LIST_SIZE; i++)
                {
                    org_profile_id_list[i] = (profile_id_t)sio_rx_buf[10 + i];
                }
                profile_id_t disc_profile_id_list[PROFILE_ID_LIST_SIZE];
                for (uint8_t i = 0; i < PROFILE_ID_LIST_SIZE; i++)
                {
                    disc_profile_id_list[i] = (profile_id_t)sio_rx_buf[19 + i];
                }
                uint32_t disc_duration;
                MEMCPY_ENDIAN(&disc_duration, &sio_rx_buf[26], sizeof(uint32_t));

                ret_val = nlme_discovery_request(PANId, NwkAddr,
                                                 sio_rx_buf[6],   // uint8_t OrgAppCapabilities,
                                                 dev_type_list,  //uint8_t OrgDevTypeList[DEVICE_TYPE_LIST_SIZE],
                                                 org_profile_id_list,  //uint8_t OrgProfileIdList[DEVICE_TYPE_LIST_SIZE],
                                                 (dev_type_t)sio_rx_buf[7 + 3/*num_dev_types*/ + 7/*num_profiles*/],    //uint8_t SearchDevType,
                                                 sio_rx_buf[8 + 3 + 7],    //uint8_t DiscProfileIdListSize,
                                                 disc_profile_id_list,   //uint8_t DiscProfileIdList[PROFILE_ID_LIST_SIZE],
                                                 disc_duration       //uint32_t DiscDuration);
#ifdef RF4CE_CALLBACK_PARAM
                                                 , (FUNC_PTR)nlme_discovery_confirm
#endif
                                                );
            }
#else
            ret_val = nlme_discovery_request(*(uint16_t *)&sio_rx_buf[2], *(uint16_t *)&sio_rx_buf[4],
                                             sio_rx_buf[6],   // uint8_t OrgAppCapabilities,
                                             (dev_type_t *)&sio_rx_buf[7],  //uint8_t OrgDevTypeList[DEVICE_TYPE_LIST_SIZE],
                                             (profile_id_t *)&sio_rx_buf[7 + 3/*num_dev_types*/],  //uint8_t OrgProfileIdList[DEVICE_TYPE_LIST_SIZE],
                                             (dev_type_t)sio_rx_buf[7 + 3/*num_dev_types*/ + 7/*num_profiles*/],    //uint8_t SearchDevType,
                                             sio_rx_buf[8 + 3 + 7],    //uint8_t DiscProfileIdListSize,
                                             (profile_id_t *)&sio_rx_buf[9 + 3 + 7],   //uint8_t DiscProfileIdList[PROFILE_ID_LIST_SIZE],
                                             * (uint32_t *)&sio_rx_buf[9 + 3 + 7 + 7]      //uint32_t DiscDuration);
#ifdef RF4CE_CALLBACK_PARAM
                                             , (FUNC_PTR) nlme_discovery_confirm
#endif
                                            );
#endif
            break;

#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
        case NLME_DISCOVERY_RESPONSE:
#if (UC3) || (SAM)
            {
                nwk_enum_t Status = (nwk_enum_t)sio_rx_buf[2];
                uint64_t DstIEEEAddr;
                memcpy(&DstIEEEAddr, &sio_rx_buf[3], 8);
                dev_type_t dev_type_list[DEVICE_TYPE_LIST_SIZE];
                for (uint8_t i = 0; i < DEVICE_TYPE_LIST_SIZE; i++)
                {
                    dev_type_list[i] = (dev_type_t)sio_rx_buf[12 + i];
                }
                profile_id_t profile_id_list[PROFILE_ID_LIST_SIZE];
                for (uint8_t i = 0; i < PROFILE_ID_LIST_SIZE; i++)
                {
                    profile_id_list[i] = (profile_id_t)sio_rx_buf[15 + i];
                }
                ret_val = nlme_discovery_response(Status,    //nwk_enum_t Status,
                                                  DstIEEEAddr,  //uint64_t DstIEEEAddr,
                                                  sio_rx_buf[11],       //uint8_t RecAppCapabilities,
                                                  dev_type_list,  //uint8_t RecDevTypeList[DEVICE_TYPE_LIST_SIZE],
                                                  profile_id_list,  //uint8_t RecProfileIdList[PROFILE_ID_LIST_SIZE],
                                                  sio_rx_buf[12 + 3 + 7]);       //uint8_t DiscReqLQI);
            }
#else
            ret_val = nlme_discovery_response((nwk_enum_t)sio_rx_buf[2],    //nwk_enum_t Status,
                                              * (uint64_t *)&sio_rx_buf[3], //uint64_t DstIEEEAddr,
                                              sio_rx_buf[11],       //uint8_t RecAppCapabilities,
                                              (dev_type_t *)&sio_rx_buf[12],  //uint8_t RecDevTypeList[DEVICE_TYPE_LIST_SIZE],
                                              (profile_id_t *)&sio_rx_buf[12 + 3/*num_dev_types*/],  //uint8_t RecProfileIdList[PROFILE_ID_LIST_SIZE],
                                              sio_rx_buf[12 + 3 + 7]);       //uint8_t DiscReqLQI);
#endif
            break;
#endif

#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
        case NLME_PAIR_RESPONSE:
#if (UC3) || (SAM)
            {
                nwk_enum_t Status = (nwk_enum_t)sio_rx_buf[2];
#if (UC3)
                uint16_t DstPANId = ((uint16_t)sio_rx_buf[3] << 8) | (uint16_t)sio_rx_buf[4];
#else
                uint16_t DstPANId = (uint16_t)sio_rx_buf[3] | ((uint16_t)sio_rx_buf[4] << 8);
#endif
                uint64_t DstIEEEAddr;
                memcpy(&DstIEEEAddr, &sio_rx_buf[5], 8);
                dev_type_t dev_type_list[DEVICE_TYPE_LIST_SIZE];
                for (uint8_t i = 0; i < DEVICE_TYPE_LIST_SIZE; i++)
                {
                    dev_type_list[i] = (dev_type_t)sio_rx_buf[14 + i];
                }
                profile_id_t profile_id_list[PROFILE_ID_LIST_SIZE];
                for (uint8_t i = 0; i < PROFILE_ID_LIST_SIZE; i++)
                {
                    profile_id_list[i] = (profile_id_t)sio_rx_buf[17 + i];
                }
                ret_val = nlme_pair_response(Status, //nwk_enum_t Status,
                                             DstPANId,   //uint16_t DstPANId,
                                             DstIEEEAddr,   //uint64_t DstIEEEAddr,
                                             sio_rx_buf[13],            //uint8_t RecAppCapabilities,
                                             dev_type_list,   //uint8_t RecDevTypeList[DEVICE_TYPE_LIST_SIZE],
                                             profile_id_list,   //uint8_t RecProfileIdList[PROFILE_ID_LIST_SIZE],
                                             sio_rx_buf[14 + 3 + 7]);    //uint8_t ProvPairingRef);
            }
#else
            ret_val = nlme_pair_response((nwk_enum_t)sio_rx_buf[2], //nwk_enum_t Status,
                                         * (uint16_t *)&sio_rx_buf[3],  //uint16_t DstPANId,
                                         * (uint64_t *)&sio_rx_buf[5],  //uint64_t DstIEEEAddr,
                                         sio_rx_buf[13],            //uint8_t RecAppCapabilities,
                                         (dev_type_t *)&sio_rx_buf[14],   //uint8_t RecDevTypeList[DEVICE_TYPE_LIST_SIZE],
                                         (profile_id_t *)&sio_rx_buf[14 + 3/*num_dev_types*/],   //uint8_t RecProfileIdList[PROFILE_ID_LIST_SIZE],
                                         sio_rx_buf[14 + 3 + 7]);    //uint8_t ProvPairingRef);
#endif
            break;
#endif

        case NLME_RESET_REQUEST:
            ret_val = nlme_reset_request(sio_rx_buf[2]
#ifdef RF4CE_CALLBACK_PARAM
                                         , (FUNC_PTR)nlme_reset_confirm
#endif
                                        );
            break;

        case NLME_PAIR_REQUEST:
#if (UC3) || (SAM)
            {
#if (UC3) 
                uint16_t DstPANId = ((uint16_t)sio_rx_buf[3] << 8) | (uint16_t)sio_rx_buf[4];
#else
                uint16_t DstPANId = (uint16_t)sio_rx_buf[3]  | ((uint16_t)sio_rx_buf[4] << 8);
#endif
                uint64_t DstIEEEAddr;
                memcpy(&DstIEEEAddr, &sio_rx_buf[5], 8);
                dev_type_t dev_type_list[DEVICE_TYPE_LIST_SIZE];
                for (uint8_t i = 0; i < DEVICE_TYPE_LIST_SIZE; i++)
                {
                    dev_type_list[i] = (dev_type_t)sio_rx_buf[14 + i];
                }
                profile_id_t profile_id_list[PROFILE_ID_LIST_SIZE];
                for (uint8_t i = 0; i < PROFILE_ID_LIST_SIZE; i++)
                {
                    profile_id_list[i] = (profile_id_t)sio_rx_buf[17 + i];
                }
                ret_val = nlme_pair_request(sio_rx_buf[2],  //uint8_t LogicalChannel,
                                            DstPANId,    //uint16_t DstPANId,
                                            DstIEEEAddr,    //uint64_t DstIEEEAddr,
                                            sio_rx_buf[13], //uint8_t OrgAppCapabilities,
                                            dev_type_list,    //uint8_t OrgDevTypeList[DEVICE_TYPE_LIST_SIZE],
                                            profile_id_list,    //uint8_t OrgProfileIdList[PROFILE_ID_LIST_SIZE],
                                            sio_rx_buf[14 + 3 + 7] //uint8_t KeyExTransferCount);
#ifdef RF4CE_CALLBACK_PARAM
                                            , (FUNC_PTR)nlme_pair_confirm
#endif
                                           );
            }
#else
            ret_val = nlme_pair_request(sio_rx_buf[2],  //uint8_t LogicalChannel,
                                        * (uint16_t *)&sio_rx_buf[3],   //uint16_t DstPANId,
                                        * (uint64_t *)&sio_rx_buf[5],   //uint64_t DstIEEEAddr,
                                        sio_rx_buf[13], //uint8_t OrgAppCapabilities,
                                        (dev_type_t *)&sio_rx_buf[14],    //uint8_t OrgDevTypeList[DEVICE_TYPE_LIST_SIZE],
                                        (profile_id_t *)&sio_rx_buf[14 + 3/*num_dev_types*/],    //uint8_t OrgProfileIdList[PROFILE_ID_LIST_SIZE],
                                        sio_rx_buf[14 + 3 + 7] //uint8_t KeyExTransferCount);
#ifdef RF4CE_CALLBACK_PARAM
                                        , (FUNC_PTR)nlme_pair_confirm
#endif
                                       );
#endif
            break;

        case NLME_GET_REQUEST:
            ret_val = nlme_get_request((nib_attribute_t)sio_rx_buf[2], sio_rx_buf[3]
#ifdef RF4CE_CALLBACK_PARAM
                                       , (FUNC_PTR)nlme_get_confirm
#endif
                                      );
            break;

        case NLME_RX_ENABLE_REQUEST:
#if (UC3) || (SAM)
            {
                uint32_t rx_on_duration;
                MEMCPY_ENDIAN(&rx_on_duration, &sio_rx_buf[2], sizeof(uint32_t));
                ret_val = nlme_rx_enable_request(rx_on_duration
#ifdef RF4CE_CALLBACK_PARAM
                                                 , (FUNC_PTR)nlme_rx_enable_confirm
#endif
                                                );
            }
#else
            ret_val = nlme_rx_enable_request(*(uint32_t *)&sio_rx_buf[2]
#ifdef RF4CE_CALLBACK_PARAM
                                             , (FUNC_PTR)nlme_rx_enable_confirm
#endif
                                            );
#endif
            break;

        case NLME_SET_REQUEST:
            ret_val = nlme_set_request((nib_attribute_t)sio_rx_buf[2], sio_rx_buf[3], &sio_rx_buf[5]
#ifdef RF4CE_CALLBACK_PARAM
                                       , (FUNC_PTR)nlme_set_confirm
#endif
                                      );
            break;

        case NLME_START_REQUEST:
            ret_val = nlme_start_request(
#ifdef RF4CE_CALLBACK_PARAM
                          (FUNC_PTR) nlme_start_confirm
#endif
                      );
            break;
#if ((NWK_UNPAIR_REQ_CONF == 1) || (defined RF4CE_PLATFORM))
        case NLME_UNPAIR_REQUEST:
            ret_val = nlme_unpair_request(sio_rx_buf[2]
#ifdef RF4CE_CALLBACK_PARAM
                                          , (FUNC_PTR)nlme_unpair_confirm
#endif
                                         );
            break;
#endif
#if ((NWK_UNPAIR_IND_RESP == 1)  || (defined RF4CE_PLATFORM))
        case NLME_UNPAIR_RESPONSE:
            ret_val = nlme_unpair_response(sio_rx_buf[2]);
            break;
#endif
#if ((NWK_UPDATE_KEY == 1) && (defined RF4CE_SECURITY)) || (defined RF4CE_PLATFORM)
        case NLME_UPDATE_KEY_REQUEST:
            ret_val = nlme_update_key_request(sio_rx_buf[2], &sio_rx_buf[3]
#ifdef RF4CE_CALLBACK_PARAM
                                              , (FUNC_PTR)nlme_update_key_confirm
#endif
                                             );
            break;
#endif
#if (defined CHANNEL_AGILITY) || (defined RF4CE_PLATFORM)
        case NWK_CH_AGILITY_REQUEST:
            ret_val = nwk_ch_agility_request((nwk_agility_mode_t)sio_rx_buf[2]
#ifdef RF4CE_CALLBACK_PARAM
                                             , (FUNC_PTR) nwk_ch_agility_confirm
#endif
                                            );
            break;
#endif
        default:
            Assert("???" == 0);
            break;
    }

    if (ret_val == false)
    {
        Assert("Buffer is not available (Test harness)" == 0);
    }
}




/* Network primitives callbacks*/


#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlde_data_indication(uint8_t PairingRef, profile_id_t ProfileId,
                          uint16_t VendorId, uint8_t nsduLength, uint8_t *nsdu,
                          uint8_t RxLinkQuality, uint8_t RxFlags)
{
    uint8_t *msg_buf;
    uint8_t *nsdu_ptr;
    uint8_t i;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLDE_DATA_IND_LEN + nsduLength + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLDE_DATA_INDICATION;
    *msg_buf++ = PairingRef;
    *msg_buf++ = ProfileId;
    *msg_buf++ = (uint8_t)VendorId; // LSB
    *msg_buf++ = (uint8_t)(VendorId >> 8); // MSB
    *msg_buf++ = RxLinkQuality;
    *msg_buf++ = RxFlags;
    *msg_buf++ = nsduLength;
    nsdu_ptr = nsdu;
    // @ToDo use memcpy
    for (i = 0; i < nsduLength; i++)
    {
        *msg_buf++ = *nsdu_ptr++;
    }
    *msg_buf = EOT;
}

#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlde_data_confirm(nwk_enum_t Status, uint8_t PairingRef, profile_id_t ProfileId
#ifdef NLDE_HANDLE
                       , uint8_t Handle
#endif
                      )
{
    uint8_t *msg_buf;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLDE_DATA_CONF_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLDE_DATA_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf++ = PairingRef;
    *msg_buf++ = ProfileId;
    *msg_buf = EOT;
    /* Keeps Compiler happy*/
#ifdef NLDE_HANDLE
    Handle = Handle;
#endif
}


#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_auto_discovery_confirm(nwk_enum_t Status, uint64_t SrcIEEEAddr)
{
    uint8_t *msg_buf;
    uint8_t *addr_ptr;
    uint8_t i;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_AUTO_DISCOVERY_CONF_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_AUTO_DISCOVERY_CONFIRM;
    *msg_buf++ = Status;
    addr_ptr = (uint8_t *)&SrcIEEEAddr;
    // @ToDo use memcpy
    for (i = 0; i < 8; i++)
    {
        *msg_buf++ = *addr_ptr++;
    }
    *msg_buf = EOT;
}
#endif


#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_comm_status_indication(nwk_enum_t Status, uint8_t PairingRef,
                                 uint16_t DstPANId, uint8_t DstAddrMode,
                                 uint64_t DstAddr)
{
    uint8_t *msg_buf;
    uint8_t *addr_ptr;
    uint8_t i;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_COMM_STATUS_IND_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_COMM_STATUS_INDICATION;
    *msg_buf++ = Status;
    *msg_buf++ = PairingRef;
#if (UC3) || (SAM)
    uint8_t *ptr = (uint8_t *)&DstPANId;
    *msg_buf++ = *ptr++;
    *msg_buf++ = *ptr;
#else
    *msg_buf++ = (uint8_t)DstPANId; // LSB
    *msg_buf++ = (uint8_t)(DstPANId >> 8); // MSB
#endif
    *msg_buf++ = DstAddrMode;
    // @ToDo use memcpy
    addr_ptr = (uint8_t *)&DstAddr;
    for (i = 0; i < 8; i++)
    {
        *msg_buf++ = *addr_ptr++;
    }
    *msg_buf = EOT;
}
#endif


#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_discovery_indication(nwk_enum_t Status, uint64_t SrcIEEEAddr,
                               uint8_t OrgNodeCapabilities, uint16_t OrgVendorId,
                               uint8_t OrgVendorString[7], uint8_t OrgAppCapabilities,
                               uint8_t OrgUserString[15], dev_type_t OrgDevTypeList[3],
                               profile_id_t OrgProfileIdList[7],
                               dev_type_t SearchDevType, uint8_t RxLinkQuality)
{
    uint8_t *msg_buf;
    uint8_t *ptr;
    uint8_t i;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_DISCOVERY_IND_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_DISCOVERY_INDICATION;
    *msg_buf++ = Status;
    // @ToDo use memcpy
    ptr = (uint8_t *)&SrcIEEEAddr;
    for (i = 0; i < 8; i++)
    {
        *msg_buf++ = *ptr++;
    }
    *msg_buf++ = OrgNodeCapabilities;
#if (UC3) || (SAM)
    ptr = (uint8_t *)&OrgVendorId;
    *msg_buf++ = *ptr++;
    *msg_buf++ = *ptr++;
#else
    *msg_buf++ = (uint8_t)OrgVendorId; //LSB
    *msg_buf++ = (uint8_t)(OrgVendorId >> 8); //MSB
#endif
    ptr = OrgVendorString;
    for (i = 0; i < 7; i++)
    {
        *msg_buf++ = *ptr++;
    }
    *msg_buf++ = OrgAppCapabilities;
    ptr = OrgUserString;
    for (i = 0; i < 15; i++)
    {
        *msg_buf++ = *ptr++;
    }
#ifndef UC3
    ptr = (uint8_t *)OrgDevTypeList;
#endif
    for (i = 0; i < DEVICE_TYPE_LIST_SIZE; i++)
    {
#if (UC3)
        *msg_buf++ = OrgDevTypeList[i];
#else
        *msg_buf++ = *ptr++;
#endif
    }
#ifndef UC3
    ptr = (uint8_t *)OrgProfileIdList;
#endif
    for (i = 0; i < PROFILE_ID_LIST_SIZE; i++)
    {
#if (UC3)
        *msg_buf++ = OrgProfileIdList[i];
#else
        *msg_buf++ = *ptr++;
#endif
    }
    *msg_buf++ = SearchDevType;
    *msg_buf++ = RxLinkQuality;
    *msg_buf = EOT;
}
#endif

#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_discovery_confirm(nwk_enum_t Status, uint8_t NumNodes,
                            node_desc_t *NodeDescList)
{
    uint8_t *msg_buf;
    uint8_t *addr_ptr;
    uint8_t i, k;

    msg_buf = get_next_tx_buffer();
    *msg_buf = NLME_DISCOVERY_CONF_LEN + RF4CONTROL_PID_LEN; // 1: first byte of octect_t
    if (NumNodes > 0)
    {
#if (UC3) || (SAM)
        *msg_buf += NumNodes * 49;//sizeof(node_desc_t);
#else
        *msg_buf += NumNodes * sizeof(node_desc_t);
#endif
    }
    msg_buf++;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_DISCOVERY_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf++ = NumNodes;
#if (UC3) || (SAM)
    *msg_buf++ = NumNodes * 49;
#else
    *msg_buf++ = NumNodes * sizeof(node_desc_t);   // length of octect_t
#endif
    for (i = 0; i < NumNodes; i++)
    {
        *msg_buf++ = NodeDescList[i].Status;
        *msg_buf++ = NodeDescList[i].LogicalChannel;
#if (UC3) || (SAM)
        addr_ptr = (uint8_t *)&NodeDescList[i].PANId;
        *msg_buf++ = *addr_ptr++;
        *msg_buf++ = *addr_ptr;
#else
        *msg_buf++ = (uint8_t)NodeDescList[i].PANId; // LSB
        *msg_buf++ = (uint8_t)(NodeDescList[i].PANId >> 8); // MSB
#endif
        addr_ptr = (uint8_t *)(&NodeDescList[i].IEEEAddr);
        for (k = 0; k < 8; k++)
        {
            *msg_buf++ = *addr_ptr++;
        }
        *msg_buf++ = NodeDescList[i].NodeCapabilities;
#if (UC3) || (SAM)
        addr_ptr = (uint8_t *)&NodeDescList[i].VendorId;
        *msg_buf++ = *addr_ptr++;
        *msg_buf++ = *addr_ptr;
#else
        *msg_buf++ = (uint8_t)NodeDescList[i].VendorId; // LSB
        *msg_buf++ = (uint8_t)(NodeDescList[i].VendorId >> 8); // MSB
#endif
        for (k = 0; k < 7; k++)
        {
            *msg_buf++ = NodeDescList[i].VendorString[k];
        }
        *msg_buf++ = NodeDescList[i].AppCapabilities;
        for (k = 0; k < 15; k++)
        {
            *msg_buf++ = NodeDescList[i].UserString[k];
        }
        for (k = 0; k < DEVICE_TYPE_LIST_SIZE; k++)
        {
#if (UC3) || (SAM)
            *msg_buf++ = (dev_type_t)NodeDescList[i].DevTypeList[k];
#else
            *msg_buf++ = NodeDescList[i].DevTypeList[k];
#endif
        }
        for (k = 0; k < PROFILE_ID_LIST_SIZE; k++)
        {
#if (UC3) || (SAM)
            *msg_buf++ = (profile_id_t)NodeDescList[i].ProfileIdList[k];
#else
            *msg_buf++ = NodeDescList[i].ProfileIdList[k];
#endif
        }
        *msg_buf++ = NodeDescList[i].DiscReqLQI;
    }
    *msg_buf = EOT;
}


#if (defined RF4CE_TARGET) || (defined RF4CE_PLATFORM)
#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_pair_indication(nwk_enum_t Status, uint16_t SrcPANId, uint64_t SrcIEEEAddr,
                          uint8_t OrgNodeCapabilities, uint16_t OrgVendorId,
                          uint8_t OrgVendorString[7], uint8_t OrgAppCapabilities,
                          uint8_t OrgUserString[15], dev_type_t OrgDevTypeList[3],
                          profile_id_t OrgProfileIdList[7], uint8_t KeyExTransferCount,
                          uint8_t ProvPairingRef)
{
    uint8_t *msg_buf;
    uint8_t *addr_ptr;
    uint8_t i;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_PAIR_IND_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_PAIR_INDICATION;
    *msg_buf++ = Status;
#if (UC3) || (SAM)
    {
        uint8_t *ptr = (uint8_t *)&SrcPANId;
        *msg_buf++ = *ptr++;
        *msg_buf++ = *ptr;
    }
#else
    *msg_buf++ = (uint8_t)SrcPANId; // LSB
    *msg_buf++ = (uint8_t)(SrcPANId >> 8); // MSB
#endif
    addr_ptr = (uint8_t *)&SrcIEEEAddr;
    for (i = 0; i < 8; i++)
    {
        *msg_buf++ = *addr_ptr++;
    }
    *msg_buf++ = OrgNodeCapabilities;
#if (UC3) || (SAM)
    {
        uint8_t *ptr = (uint8_t *)&OrgVendorId;
        *msg_buf++ = *ptr++;
        *msg_buf++ = *ptr;
    }
#else
    *msg_buf++ = (uint8_t)OrgVendorId; // LSB
    *msg_buf++ = (uint8_t)(OrgVendorId >> 8); // MSB
#endif
    for (i = 0; i < 7; i++)
    {
        *msg_buf++ = OrgVendorString[i];
    }
    *msg_buf++ = OrgAppCapabilities;
    for (i = 0; i < 15; i++)
    {
        *msg_buf++ = OrgUserString[i];
    }
    for (i = 0; i < DEVICE_TYPE_LIST_SIZE; i++)
    {
#if (UC3)
        *msg_buf++ = (uint8_t)OrgDevTypeList[i];
#else
        *msg_buf++ = OrgDevTypeList[i];
#endif
    }
    for (i = 0; i < PROFILE_ID_LIST_SIZE; i++)
    {
#if (UC3)
        *msg_buf++ = (uint8_t)OrgProfileIdList[i];
#else
        *msg_buf++ = OrgProfileIdList[i];
#endif
    }
    *msg_buf++ = KeyExTransferCount;
    *msg_buf++ = ProvPairingRef;
    *msg_buf = EOT;
}
#endif

#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_pair_confirm(nwk_enum_t Status, uint8_t PairingRef, uint16_t RecVendorId,
                       uint8_t RecVendorString[7], uint8_t RecAppCapabilities,
                       uint8_t RecUserString[15], dev_type_t RecDevTypeList[3],
                       profile_id_t RecProfileIdList[7])
{
    uint8_t *msg_buf;
    uint8_t i;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_PAIR_CONF_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_PAIR_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf++ = PairingRef;
#if (UC3)
    *msg_buf++ = (uint8_t)(RecVendorId >> 8); // MSB
    *msg_buf++ = (uint8_t)RecVendorId; // LSB
#else
    *msg_buf++ = (uint8_t)RecVendorId; // LSB
    *msg_buf++ = (uint8_t)(RecVendorId >> 8); // MSB
#endif
    for (i = 0; i < 7; i++)
    {
        *msg_buf++ = RecVendorString[i];
    }
    *msg_buf++ = RecAppCapabilities;
    for (i = 0; i < 15; i++)
    {
        *msg_buf++ = RecUserString[i];
    }
    for (i = 0; i < DEVICE_TYPE_LIST_SIZE; i++)
    {
        *msg_buf++ = RecDevTypeList[i];
    }
    for (i = 0; i < PROFILE_ID_LIST_SIZE; i++)
    {
        *msg_buf++ = RecProfileIdList[i];
    }
    *msg_buf = EOT;
}

#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_reset_confirm(nwk_enum_t Status)
{
    uint8_t *msg_buf;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_RESET_CONF_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_RESET_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf = EOT;
}

#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_rx_enable_confirm(nwk_enum_t Status)
{
    uint8_t *msg_buf;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_RX_ENABLE_CONF_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_RX_ENABLE_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf = EOT;
}

#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_set_confirm(nwk_enum_t Status, nib_attribute_t NIBAttribute, uint8_t NIBAttributeIndex)
{
    uint8_t *msg_buf;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_SET_CONF_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_SET_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf++ = NIBAttribute;
    *msg_buf++ = NIBAttributeIndex;
    *msg_buf = EOT;
}

#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_get_confirm(nwk_enum_t Status, nib_attribute_t NIBAttribute,
                      uint8_t NIBAttributeIndex, void *NIBAttributeValue)
{
    uint8_t *msg_buf;
    uint8_t i;
    uint8_t attr_len;
    uint8_t *ptr;
    ptr = NIBAttributeValue;
    msg_buf = get_next_tx_buffer();
    attr_len = nwk_get_nib_attribute_size(NIBAttribute);
    *msg_buf++ = NLME_GET_CONF_LEN + attr_len + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_GET_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf++ = NIBAttribute;
    *msg_buf++ = NIBAttributeIndex;
    *msg_buf++ = attr_len;
    for (i = 0; i < attr_len; i++)
    {
        *msg_buf++ = *ptr++;
    }
    *msg_buf = EOT;
}

#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_start_confirm(nwk_enum_t Status)
{
    uint8_t *msg_buf;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_START_CONF_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_START_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf = EOT;
}


#if ((NWK_UNPAIR_IND_RESP == 1) || (defined RF4CE_PLATFORM))
#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_unpair_indication(uint8_t PairingRef)
{
    uint8_t *msg_buf;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_UNPAIR_IND_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_UNPAIR_INDICATION;
    *msg_buf++ = PairingRef;
    *msg_buf = EOT;
}
#endif


#if (NWK_UNPAIR_REQ_CONF == 1) || (defined RF4CE_PLATFORM)
#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_unpair_confirm(uint8_t Status, uint8_t PairingRef)
{
    uint8_t *msg_buf;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_UNPAIR_CONF_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_UNPAIR_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf++ = PairingRef;
    *msg_buf = EOT;
}
#endif


#if ((NWK_UPDATE_KEY == 1) && (defined RF4CE_SECURITY)) || (defined RF4CE_PLATFORM)
#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nlme_update_key_confirm(nwk_enum_t Status, uint8_t PairingRef)
{
    uint8_t *msg_buf;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NLME_UPDATE_KEY_CONF_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NLME_UPDATE_KEY_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf++ = PairingRef;
    *msg_buf = EOT;
}
#endif


#if (defined CHANNEL_AGILITY) || (defined RF4CE_PLATFORM)
#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nwk_ch_agility_indication(uint8_t LogicalChannel)
{
    uint8_t *msg_buf;

    msg_buf = get_next_tx_buffer();
    *msg_buf++ = NWK_CH_AGILITY_IND_LEN + RF4CONTROL_PID_LEN;
	*msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NWK_CH_AGILITY_INDICATION;
    *msg_buf++ = LogicalChannel;
    *msg_buf = EOT;
}
#endif


#if (defined CHANNEL_AGILITY) || (defined RF4CE_PLATFORM)
#ifdef RF4CE_CALLBACK_PARAM
static
#endif
void nwk_ch_agility_confirm(nwk_enum_t Status, bool ChannelChanged, uint8_t LogicalChannel)
{
    uint8_t *msg_buf;

    msg_buf = get_next_tx_buffer();
	*msg_buf++ = NWK_CH_AGILITY_CONF_LEN + RF4CONTROL_PID_LEN;
    *msg_buf++ = RF4CONTROL_PID;
    *msg_buf++ = NWK_CH_AGILITY_CONFIRM;
    *msg_buf++ = Status;
    *msg_buf++ = (uint8_t)ChannelChanged;
    *msg_buf++ = LogicalChannel;
    *msg_buf = EOT;
}
#endif




#endif /* SIO_HUB */
/* EOF */

