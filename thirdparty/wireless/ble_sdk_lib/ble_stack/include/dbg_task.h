/*
 * dbg_task.h
 *
 *  Created on: Oct 28, 2014
 *      Author: lali
 */
#ifndef DBG_TASK_H_
#define DBG_TASK_H_

#include "cmn_defs.h"

#define RPL_POWER_MIN 1
#define RPL_POWER_MAX 6 
#define RPL_PWR_TBL_SIZE 0x0f

/// dbg Task messages
enum dbg_msg_id
{
    /// Debug commands description.
    DBG_MSG_ID_CMD_FIRST = (uint16_t)(3 << 10),
    DBG_RD_MEM_REQ = DBG_MSG_ID_CMD_FIRST,
    DBG_WR_MEM_REQ, //0c01
    DBG_DEL_PARAM_REQ,
    DBG_RD_PARAM_REQ,
    DBG_WR_PARAM_REQ,
    DBG_PLF_RESET_REQ,
    DBG_FLASH_IDENT_REQ,
    DBG_FLASH_ERASE_REQ,
    DBG_FLASH_WRITE_REQ,
    DBG_FLASH_READ_REQ,
    
    DBG_RD_KE_STATS_REQ, //0c0a
    DBG_RF_REG_RD_REQ,
    DBG_RF_REG_WR_REQ,
    DBG_HW_REG_RD_REQ,
    DBG_HW_REG_WR_REQ,
  
    DBG_LE_SET_BD_ADDR_REQ, //0c0f
    DBG_LE_SET_TYPE_PUB_REQ,//0c10
    DBG_LE_SET_TYPE_RAND_REQ,//0c11
    DBG_LE_SET_CRC_REQ,
    DBG_LE_LLCP_DISCARD_REQ,//0c13
    DBG_LE_RESET_RX_CNT_REQ,
    DBG_LE_RESET_TX_CNT_REQ,
    DBG_SET_TX_PW_REQ,//0c16
};

enum dbg_evt_id
{
    /// Debug events description.
    DBG_RD_MEM_CMP_EVT = 0x0c19,
    DBG_WR_MEM_CMP_EVT, //0c1a
    DBG_DEL_PARAM_CMP_EVT,
    DBG_RD_PARAM_CMP_EVT,
    DBG_WR_PARAM_CMP_EVT,
    DBG_FLASH_IDENT_CMP_EVT,
    DBG_FLASH_ERASE_CMP_EVT,//0c1f
    DBG_FLASH_WRITE_CMP_EVT,
    DBG_FLASH_READ_CMP_EVT, //0c21
    
    DBG_RD_KE_STATS_CMP_EVT,
    DBG_TRACE_WARNING_EVT,
    DBG_RF_REG_RD_CMP_EVT,
    DBG_RF_REG_WR_CMP_EVT,
    DBG_PLF_RESET_CMP_EVT,
    DBG_HW_REG_RD_CMP_EVT,
    DBG_HW_REG_WR_CMP_EVT,
   
    DBG_LE_SET_BD_ADDR_CMP_EVT, //0c29
    DBG_LE_SET_TYPE_PUB_CMP_EVT,
    DBG_LE_SET_TYPE_RAND_CMP_EVT,
    DBG_LE_SET_CRC_CMP_EVT,
    DBG_LE_LLCP_DISCARD_CMP_EVT,
    DBG_LE_RESET_RX_CNT_CMP_EVT,
    DBG_LE_RESET_TX_CNT_CMP_EVT,
    DBG_SET_TX_PW_CMP_EVT,  
};

uint8_t dbg_le_set_bd_addr_req_handler(uint8_t* addr);
uint8_t dbg_set_tx_pw_req_handler(uint16_t conn_handle, uint8_t level);
uint8_t dbg_wr_mem_req_handler(uint32_t memAddr,uint8_t * data,uint8_t size);
uint8_t dbg_wr_mem_req_handler32(uint32_t memAddr,uint32_t * data,uint8_t size);
void dbg_wr_mem_req_handler32_reset(uint32_t memAddr,uint32_t * data,uint8_t size);
uint8_t dbg_rd_mem_req_handler(uint32_t memAddr,uint8_t* data ,uint8_t size);

#endif

