/**
 * \file
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
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef _SAM3S8_MATRIX_INSTANCE_
#define _SAM3S8_MATRIX_INSTANCE_

/* ========== Register definition for MATRIX peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_MATRIX_MCFG             (0x400E0200U) /**< \brief (MATRIX) Master Configuration Register */
#define REG_MATRIX_SCFG             (0x400E0240U) /**< \brief (MATRIX) Slave Configuration Register */
#define REG_MATRIX_PRAS0            (0x400E0280U) /**< \brief (MATRIX) Priority Register A for Slave 0 */
#define REG_MATRIX_PRAS1            (0x400E0288U) /**< \brief (MATRIX) Priority Register A for Slave 1 */
#define REG_MATRIX_PRAS2            (0x400E0290U) /**< \brief (MATRIX) Priority Register A for Slave 2 */
#define REG_MATRIX_PRAS3            (0x400E0298U) /**< \brief (MATRIX) Priority Register A for Slave 3 */
#define REG_MATRIX_PRAS4            (0x400E02A0U) /**< \brief (MATRIX) Priority Register A for Slave 4 */
#define REG_CCFG_SYSIO              (0x400E0314U) /**< \brief (MATRIX) System I/O Configuration register */
#define REG_CCFG_SMCNFCS            (0x400E031CU) /**< \brief (MATRIX) SMC Chip Select NAND Flash Assignment Register */
#define REG_MATRIX_WPMR             (0x400E03E4U) /**< \brief (MATRIX) Write Protect Mode Register */
#define REG_MATRIX_WPSR             (0x400E03E8U) /**< \brief (MATRIX) Write Protect Status Register */
#else
#define REG_MATRIX_MCFG    (*(RwReg*)0x400E0200U) /**< \brief (MATRIX) Master Configuration Register */
#define REG_MATRIX_SCFG    (*(RwReg*)0x400E0240U) /**< \brief (MATRIX) Slave Configuration Register */
#define REG_MATRIX_PRAS0   (*(RwReg*)0x400E0280U) /**< \brief (MATRIX) Priority Register A for Slave 0 */
#define REG_MATRIX_PRAS1   (*(RwReg*)0x400E0288U) /**< \brief (MATRIX) Priority Register A for Slave 1 */
#define REG_MATRIX_PRAS2   (*(RwReg*)0x400E0290U) /**< \brief (MATRIX) Priority Register A for Slave 2 */
#define REG_MATRIX_PRAS3   (*(RwReg*)0x400E0298U) /**< \brief (MATRIX) Priority Register A for Slave 3 */
#define REG_MATRIX_PRAS4   (*(RwReg*)0x400E02A0U) /**< \brief (MATRIX) Priority Register A for Slave 4 */
#define REG_CCFG_SYSIO     (*(RwReg*)0x400E0314U) /**< \brief (MATRIX) System I/O Configuration register */
#define REG_CCFG_SMCNFCS   (*(RwReg*)0x400E031CU) /**< \brief (MATRIX) SMC Chip Select NAND Flash Assignment Register */
#define REG_MATRIX_WPMR    (*(RwReg*)0x400E03E4U) /**< \brief (MATRIX) Write Protect Mode Register */
#define REG_MATRIX_WPSR    (*(RoReg*)0x400E03E8U) /**< \brief (MATRIX) Write Protect Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3S8_MATRIX_INSTANCE_ */
