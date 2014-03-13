/**
 * \file
 *
 * \brief Provides the low-level initialization functions that called 
 * on chip startup.
 *
 * Copyright (c) 2014 Atmel Corporation. All rights reserved.
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

#include "system_samg54.h"
#include "samg54.h"

/* @cond 0 */
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/* @endcond */

/* Clock Settings (96MHz) */
#define SYS_BOARD_PLLAR     (CKGR_PLLAR_MULA(0xbb8U) \
							| CKGR_PLLAR_PLLACOUNT(0x3fU) \
							| CKGR_PLLAR_PLLAEN(0x1U))
#define SYS_BOARD_MCKR      (PMC_MCKR_PRES_CLK_1 | PMC_MCKR_CSS_PLLA_CLK)

/* Key to unlock MOR register */
#define SYS_CKGR_MOR_KEY_VALUE    CKGR_MOR_KEY(0x37)

uint32_t SystemCoreClock = CHIP_FREQ_MAINCK_RC_8MHZ;

/**
 * \brief Setup the microcontroller system.
 * Initialize the System and update the SystemFrequency variable.
 */
void SystemInit(void)
{
	/* Set FWS according to SYS_BOARD_MCKR configuration */
	EFC0->EEFC_FMR = EEFC_FMR_FWS(2)|EEFC_FMR_CLOE;
#if defined(ID_EFC1)
	EFC1->EEFC_FMR = EEFC_FMR_FWS(2)|EEFC_FMR_CLOE;
#endif

	/* Initialize PLLA */
	PMC->CKGR_PLLAR = SYS_BOARD_PLLAR;
	while (!(PMC->PMC_SR & PMC_SR_LOCKA)) {
	}

	/* Switch to PLLA */
	PMC->PMC_MCKR = SYS_BOARD_MCKR;
	while (!(PMC->PMC_SR & PMC_SR_MCKRDY)) {
	}

	SystemCoreClock = CHIP_FREQ_CPU_MAX;
}

void SystemCoreClockUpdate(void)
{
	/* Determine clock frequency according to clock register values */
	switch (PMC->PMC_MCKR & (uint32_t) PMC_MCKR_CSS_Msk) {
	case PMC_MCKR_CSS_SLOW_CLK:	/* Slow clock */
		if (SUPC->SUPC_SR & SUPC_SR_OSCSEL) {
			SystemCoreClock = CHIP_FREQ_XTAL_32K;
		} else {
			SystemCoreClock = CHIP_FREQ_SLCK_RC;
		}
		break;
	case PMC_MCKR_CSS_MAIN_CLK:	/* Main clock */
		if (PMC->CKGR_MOR & CKGR_MOR_MOSCSEL) {
			SystemCoreClock = CHIP_FREQ_XTAL_12M;
		} else {
			SystemCoreClock = CHIP_FREQ_MAINCK_RC_8MHZ;

			switch (PMC->CKGR_MOR & CKGR_MOR_MOSCRCF_Msk) {
			case CKGR_MOR_MOSCRCF_8_MHz:
				break;
			case CKGR_MOR_MOSCRCF_16_MHz:
				SystemCoreClock *= 2U;
				break;
			case CKGR_MOR_MOSCRCF_24_MHz:
				SystemCoreClock *= 3U;
				break;
			default:
				break;
			}
		}
		break;
	case PMC_MCKR_CSS_PLLA_CLK:	/* PLLA clock */
		SystemCoreClock = CHIP_FREQ_SLCK_RC;
		if ((uint32_t) (PMC->PMC_MCKR & (uint32_t) PMC_MCKR_CSS_Msk) == PMC_MCKR_CSS_PLLA_CLK) {
			SystemCoreClock *= ((((PMC->CKGR_PLLAR) & CKGR_PLLAR_MULA_Msk) >> 
					CKGR_PLLAR_MULA_Pos) + 1U);
		}
		break;
	default:
		break;
	}

	if ((PMC->PMC_MCKR & PMC_MCKR_PRES_Msk) == PMC_MCKR_PRES_CLK_3) {
		SystemCoreClock /= 3U;
	} else {
		SystemCoreClock >>= ((PMC->PMC_MCKR & PMC_MCKR_PRES_Msk) >> PMC_MCKR_PRES_Pos);
	}
}

/** 
 * Initialize flash.
 */
void system_init_flash(uint32_t ul_clk)
{
	/* Set FWS for embedded Flash access according to operating frequency */
	if (ul_clk < CHIP_FREQ_FWS_0) {
		EFC0->EEFC_FMR = EEFC_FMR_FWS(0)|EEFC_FMR_CLOE;
	} else if (ul_clk < CHIP_FREQ_FWS_1) {
		EFC0->EEFC_FMR = EEFC_FMR_FWS(1)|EEFC_FMR_CLOE;
	} else if (ul_clk < CHIP_FREQ_FWS_2) {
		EFC0->EEFC_FMR = EEFC_FMR_FWS(2)|EEFC_FMR_CLOE;
	} else if (ul_clk < CHIP_FREQ_FWS_3) {
		EFC0->EEFC_FMR = EEFC_FMR_FWS(3)|EEFC_FMR_CLOE;
	} else if (ul_clk < CHIP_FREQ_FWS_4) {
		EFC0->EEFC_FMR = EEFC_FMR_FWS(4)|EEFC_FMR_CLOE;
	} else if (ul_clk < CHIP_FREQ_FWS_5) {
		EFC0->EEFC_FMR = EEFC_FMR_FWS(5)|EEFC_FMR_CLOE;
	} else if (ul_clk < CHIP_FREQ_FWS_6) {
		EFC0->EEFC_FMR = EEFC_FMR_FWS(6)|EEFC_FMR_CLOE;
	} else if (ul_clk < CHIP_FREQ_FWS_7) {
		EFC0->EEFC_FMR = EEFC_FMR_FWS(7)|EEFC_FMR_CLOE;
	} else {
		EFC0->EEFC_FMR = EEFC_FMR_FWS(8)|EEFC_FMR_CLOE;
	}
}

/* @cond 0 */
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/* @endcond */
