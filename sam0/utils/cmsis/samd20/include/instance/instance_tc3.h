/**
 * \file
 *
 * Copyright (c) 2013 Atmel Corporation. All rights reserved.
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

#ifndef _SAMD20_TC3_INSTANCE_
#define _SAMD20_TC3_INSTANCE_

/* ========== Register definition for TC3 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_TC3_CTRLA0                        (0x42002C00U) /**< \brief (TC3) Control A Register 0 */
#define REG_TC3_CTRLA1                        (0x42002C02U) /**< \brief (TC3) Control A Register 1 */
#define REG_TC3_CTRLA2                        (0x42002C04U) /**< \brief (TC3) Control A Register 2 */
#define REG_TC3_CTRLA3                        (0x42002C06U) /**< \brief (TC3) Control A Register 3 */
#define REG_TC3_READREQ0                      (0x42002C02U) /**< \brief (TC3) Read Request Register 0 */
#define REG_TC3_READREQ1                      (0x42002C04U) /**< \brief (TC3) Read Request Register 1 */
#define REG_TC3_READREQ2                      (0x42002C06U) /**< \brief (TC3) Read Request Register 2 */
#define REG_TC3_READREQ3                      (0x42002C08U) /**< \brief (TC3) Read Request Register 3 */
#define REG_TC3_CTRLBCLR0                     (0x42002C04U) /**< \brief (TC3) Control B Clear Register 0 */
#define REG_TC3_CTRLBCLR1                     (0x42002C05U) /**< \brief (TC3) Control B Clear Register 1 */
#define REG_TC3_CTRLBCLR2                     (0x42002C06U) /**< \brief (TC3) Control B Clear Register 2 */
#define REG_TC3_CTRLBCLR3                     (0x42002C07U) /**< \brief (TC3) Control B Clear Register 3 */
#define REG_TC3_CTRLBSET0                     (0x42002C05U) /**< \brief (TC3) Control B Set Register 0 */
#define REG_TC3_CTRLBSET1                     (0x42002C06U) /**< \brief (TC3) Control B Set Register 1 */
#define REG_TC3_CTRLBSET2                     (0x42002C07U) /**< \brief (TC3) Control B Set Register 2 */
#define REG_TC3_CTRLBSET3                     (0x42002C08U) /**< \brief (TC3) Control B Set Register 3 */
#define REG_TC3_CTRLC0                        (0x42002C06U) /**< \brief (TC3) Control C Register 0 */
#define REG_TC3_CTRLC1                        (0x42002C07U) /**< \brief (TC3) Control C Register 1 */
#define REG_TC3_CTRLC2                        (0x42002C08U) /**< \brief (TC3) Control C Register 2 */
#define REG_TC3_CTRLC3                        (0x42002C09U) /**< \brief (TC3) Control C Register 3 */
#define REG_TC3_DEBUG0                        (0x42002C08U) /**< \brief (TC3) Debug Register 0 */
#define REG_TC3_DEBUG1                        (0x42002C09U) /**< \brief (TC3) Debug Register 1 */
#define REG_TC3_DEBUG2                        (0x42002C0AU) /**< \brief (TC3) Debug Register 2 */
#define REG_TC3_DEBUG3                        (0x42002C0BU) /**< \brief (TC3) Debug Register 3 */
#define REG_TC3_EVCTRL0                       (0x42002C0AU) /**< \brief (TC3) Event Control Register 0 */
#define REG_TC3_EVCTRL1                       (0x42002C0CU) /**< \brief (TC3) Event Control Register 1 */
#define REG_TC3_EVCTRL2                       (0x42002C0EU) /**< \brief (TC3) Event Control Register 2 */
#define REG_TC3_EVCTRL3                       (0x42002C10U) /**< \brief (TC3) Event Control Register 3 */
#define REG_TC3_INTENCLR0                     (0x42002C0CU) /**< \brief (TC3) Interrupt Enable Clear Register 0 */
#define REG_TC3_INTENCLR1                     (0x42002C0DU) /**< \brief (TC3) Interrupt Enable Clear Register 1 */
#define REG_TC3_INTENCLR2                     (0x42002C0EU) /**< \brief (TC3) Interrupt Enable Clear Register 2 */
#define REG_TC3_INTENCLR3                     (0x42002C0FU) /**< \brief (TC3) Interrupt Enable Clear Register 3 */
#define REG_TC3_INTENSET0                     (0x42002C0DU) /**< \brief (TC3) Interrupt Enable Set Register 0 */
#define REG_TC3_INTENSET1                     (0x42002C0EU) /**< \brief (TC3) Interrupt Enable Set Register 1 */
#define REG_TC3_INTENSET2                     (0x42002C0FU) /**< \brief (TC3) Interrupt Enable Set Register 2 */
#define REG_TC3_INTENSET3                     (0x42002C10U) /**< \brief (TC3) Interrupt Enable Set Register 3 */
#define REG_TC3_INTFLAG0                      (0x42002C0EU) /**< \brief (TC3) Interrupt Flag Status and Clear Register 0 */
#define REG_TC3_INTFLAG1                      (0x42002C0FU) /**< \brief (TC3) Interrupt Flag Status and Clear Register 1 */
#define REG_TC3_INTFLAG2                      (0x42002C10U) /**< \brief (TC3) Interrupt Flag Status and Clear Register 2 */
#define REG_TC3_INTFLAG3                      (0x42002C11U) /**< \brief (TC3) Interrupt Flag Status and Clear Register 3 */
#define REG_TC3_STATUS0                       (0x42002C0FU) /**< \brief (TC3) Status Register 0 */
#define REG_TC3_STATUS1                       (0x42002C10U) /**< \brief (TC3) Status Register 1 */
#define REG_TC3_STATUS2                       (0x42002C11U) /**< \brief (TC3) Status Register 2 */
#define REG_TC3_STATUS3                       (0x42002C12U) /**< \brief (TC3) Status Register 3 */
#define REG_TC3_COUNT16_COUNT0                (0x42002C10U) /**< \brief (TC3) COUNT16 Count Register 0 */
#define REG_TC3_COUNT16_COUNT1                (0x42002C12U) /**< \brief (TC3) COUNT16 Count Register 1 */
#define REG_TC3_COUNT16_COUNT2                (0x42002C14U) /**< \brief (TC3) COUNT16 Count Register 2 */
#define REG_TC3_COUNT16_COUNT3                (0x42002C16U) /**< \brief (TC3) COUNT16 Count Register 3 */
#define REG_TC3_COUNT32_COUNT0                (0x42002C10U) /**< \brief (TC3) COUNT32 Count Register 0 */
#define REG_TC3_COUNT32_COUNT1                (0x42002C14U) /**< \brief (TC3) COUNT32 Count Register 1 */
#define REG_TC3_COUNT32_COUNT2                (0x42002C18U) /**< \brief (TC3) COUNT32 Count Register 2 */
#define REG_TC3_COUNT32_COUNT3                (0x42002C1CU) /**< \brief (TC3) COUNT32 Count Register 3 */
#define REG_TC3_COUNT8_COUNT0                 (0x42002C10U) /**< \brief (TC3) COUNT8 Count Register 0 */
#define REG_TC3_COUNT8_COUNT1                 (0x42002C11U) /**< \brief (TC3) COUNT8 Count Register 1 */
#define REG_TC3_COUNT8_COUNT2                 (0x42002C12U) /**< \brief (TC3) COUNT8 Count Register 2 */
#define REG_TC3_COUNT8_COUNT3                 (0x42002C13U) /**< \brief (TC3) COUNT8 Count Register 3 */
#define REG_TC3_COUNT8_PER0                   (0x42002C14U) /**< \brief (TC3) COUNT8 Period Register 0 */
#define REG_TC3_COUNT8_PER1                   (0x42002C15U) /**< \brief (TC3) COUNT8 Period Register 1 */
#define REG_TC3_COUNT8_PER2                   (0x42002C16U) /**< \brief (TC3) COUNT8 Period Register 2 */
#define REG_TC3_COUNT8_PER3                   (0x42002C17U) /**< \brief (TC3) COUNT8 Period Register 3 */
#define REG_TC3_COUNT16_CC0                   (0x42002C18U) /**< \brief (TC3) COUNT16 Compare and Capture Register 0 */
#define REG_TC3_COUNT16_CC1                   (0x42002C1AU) /**< \brief (TC3) COUNT16 Compare and Capture Register 1 */
#define REG_TC3_COUNT32_CC0                   (0x42002C18U) /**< \brief (TC3) COUNT32 Compare and Capture Register 0 */
#define REG_TC3_COUNT32_CC1                   (0x42002C1CU) /**< \brief (TC3) COUNT32 Compare and Capture Register 1 */
#define REG_TC3_COUNT8_CC0                    (0x42002C18U) /**< \brief (TC3) COUNT8 Compare and Capture Register 0 */
#define REG_TC3_COUNT8_CC1                    (0x42002C19U) /**< \brief (TC3) COUNT8 Compare and Capture Register 1 */
#else
#define REG_TC3_CTRLA              (*(RwReg16*)0x42002C00U) /**< \brief (TC3) Control A Register */
#define REG_TC3_READREQ            (*(RwReg16*)0x42002C02U) /**< \brief (TC3) Read Request Register */
#define REG_TC3_CTRLBCLR           (*(RwReg8 *)0x42002C04U) /**< \brief (TC3) Control B Clear Register */
#define REG_TC3_CTRLBSET           (*(RwReg8 *)0x42002C05U) /**< \brief (TC3) Control B Set Register */
#define REG_TC3_CTRLC              (*(RwReg8 *)0x42002C06U) /**< \brief (TC3) Control C Register */
#define REG_TC3_DEBUG              (*(RwReg8 *)0x42002C08U) /**< \brief (TC3) Debug Register */
#define REG_TC3_EVCTRL             (*(RwReg16*)0x42002C0AU) /**< \brief (TC3) Event Control Register */
#define REG_TC3_INTENCLR           (*(RwReg8 *)0x42002C0CU) /**< \brief (TC3) Interrupt Enable Clear Register */
#define REG_TC3_INTENSET           (*(RwReg8 *)0x42002C0DU) /**< \brief (TC3) Interrupt Enable Set Register */
#define REG_TC3_INTFLAG            (*(RwReg8 *)0x42002C0EU) /**< \brief (TC3) Interrupt Flag Status and Clear Register */
#define REG_TC3_STATUS             (*(RoReg8 *)0x42002C0FU) /**< \brief (TC3) Status Register */
#define REG_TC3_COUNT16_COUNT      (*(RwReg16*)0x42002C10U) /**< \brief (TC3) COUNT16 Count Register */
#define REG_TC3_COUNT32_COUNT      (*(RwReg  *)0x42002C10U) /**< \brief (TC3) COUNT32 Count Register */
#define REG_TC3_COUNT8_COUNT       (*(RwReg8 *)0x42002C10U) /**< \brief (TC3) COUNT8 Count Register */
#define REG_TC3_COUNT8_PER         (*(RwReg8 *)0x42002C14U) /**< \brief (TC3) COUNT8 Period Register */
#define REG_TC3_COUNT16_CC0        (*(RwReg16*)0x42002C18U) /**< \brief (TC3) COUNT16 Compare and Capture Register 0 */
#define REG_TC3_COUNT16_CC1        (*(RwReg16*)0x42002C1AU) /**< \brief (TC3) COUNT16 Compare and Capture Register 1 */
#define REG_TC3_COUNT32_CC0        (*(RwReg  *)0x42002C18U) /**< \brief (TC3) COUNT32 Compare and Capture Register 0 */
#define REG_TC3_COUNT32_CC1        (*(RwReg  *)0x42002C1CU) /**< \brief (TC3) COUNT32 Compare and Capture Register 1 */
#define REG_TC3_COUNT8_CC0         (*(RwReg8 *)0x42002C18U) /**< \brief (TC3) COUNT8 Compare and Capture Register 0 */
#define REG_TC3_COUNT8_CC1         (*(RwReg8 *)0x42002C19U) /**< \brief (TC3) COUNT8 Compare and Capture Register 1 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for TC3 peripheral ========== */
#define TC3_CC8_NUM                 2
#define TC3_CC16_NUM                2
#define TC3_CC32_NUM                2
#define TC3_GCLK_ID                 20
#define TC3_OW_NUM                  2

#endif /* _SAMD20_TC3_INSTANCE_ */
