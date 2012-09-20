/**
 * \file
 *
 * \brief FlashCALW driver for SAM4L.
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
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

#ifndef FLASHCALW_H_INCLUDED
#define FLASHCALW_H_INCLUDED

#include <stddef.h>
#include <stdbool.h>
#include "compiler.h"

/* These defines should be part of the auto-generated header files */
#if (!defined FLASH_PAGE_SIZE)
#   define FLASH_PAGE_SIZE     512UL
#endif
#if (!defined FLASH_NB_OF_REGIONS)
#   define FLASH_NB_OF_REGIONS 16
#endif


/* ! Number of flash regions defined by the FLASHCALW. */
#define FLASHCALW_REGIONS  FLASH_NB_OF_REGIONS

/** \brief Maximum operating frequency when FWS is 1 in PS0 mode and
 the Fast wakeup is enabled */
#define FLASH_FREQ_PS1_FWS_1_FWU_MAX_FREQ    (12000000UL)
/** \brief Maximum operating frequency when FWS is 0 in PS0 mode */
#define FLASH_FREQ_PS0_FWS_0_MAX_FREQ        (18000000UL)
/** \brief Maximum operating frequency when FWS is 1 in PS0 mode */
#define FLASH_FREQ_PS0_FWS_1_MAX_FREQ        (36000000UL)
/** \brief Maximum operating frequency when FWS is 0 in PS1 mode */
#define FLASH_FREQ_PS1_FWS_0_MAX_FREQ        (8000000UL)
/** \brief Maximum operating frequency when FWS is 1 in PS1 mode */
#define FLASH_FREQ_PS1_FWS_1_MAX_FREQ        (12000000UL)

/*! \name Flash Properties
 */
//! @{

uint32_t flashcalw_get_flash_size(void);

uint32_t flashcalw_get_page_count(void);

uint32_t flashcalw_get_page_count_per_region(void);

uint32_t flashcalw_get_page_region(uint32_t page_number);

uint32_t flashcalw_get_region_first_page_number(uint32_t region);

//! @}


/*! \name FLASHCALW Control
 */
//! @{

uint32_t flashcalw_get_wait_state(void);

void flashcalw_set_wait_state(uint32_t wait_state);

void flashcalw_set_flash_waitstate_and_readmode(uint32_t cpu_f_hz,
		uint32_t ps_value, bool is_fwu_enabled);

/*! \brief Alias on the flashcalw_set_flash_waitstate_and_readmode() function.
 *
 * \param cpu_f_hz The CPU frequency
 * \param ps_value (boolean), Power Scaling mode
 * \param fwu_value (boolean), Fast wakeup mode
 */
#define flash_set_bus_freq(cpu_f_hz, ps_value, is_fwu_enabled) \
	flashcalw_set_flash_waitstate_and_readmode(cpu_f_hz, ps_value, is_fwu_enabled)

bool flashcalw_is_ready_int_enabled(void);

void flashcalw_enable_ready_int(bool enable);

bool flashcalw_is_lock_error_int_enabled(void);

void flashcalw_enable_lock_error_int(bool enable);

bool flashcalw_is_prog_error_int_enabled(void);

void flashcalw_enable_prog_error_int(bool enable);

//! @}


/*! \name FLASHCALW Status
 */
//! @{

bool flashcalw_is_ready(void);

void flashcalw_default_wait_until_ready(void);

extern void (*volatile flashcalw_wait_until_ready)(void);

bool flashcalw_is_lock_error(void);

bool flashcalw_is_programming_error(void);

//! @}


/*! \name FLASHCALW Command Control
 */
//! @{

uint32_t flashcalw_get_command(void);

uint32_t flashcalw_get_page_number(void);

void flashcalw_issue_command(uint32_t command, int page_number);

//! @}


/*! \name FLASHCALW Global Commands
 */
//! @{

void flashcalw_no_operation(void);

void flashcalw_erase_all(void);

//! @}


/*! \name FLASHCALW Protection Mechanisms
 */
//! @{

bool flashcalw_is_security_bit_active(void);

void flashcalw_set_security_bit(void);

bool flashcalw_is_page_region_locked(uint32_t page_number);

bool flashcalw_is_region_locked(uint32_t region);

void flashcalw_lock_page_region(int page_number, bool lock);

void flashcalw_lock_region(uint32_t region, bool lock);

void flashcalw_lock_all_regions(bool lock);

//! @}


/*! \name Access to General-Purpose Fuses
 */
//! @{

bool flashcalw_read_gp_fuse_bit(uint32_t gp_fuse_bit);

uint64_t flashcalw_read_gp_fuse_bitfield(uint32_t pos, uint32_t width);

uint8_t flashcalw_read_gp_fuse_byte(uint32_t gp_fuse_byte);

uint64_t flashcalw_read_all_gp_fuses(void);

bool flashcalw_erase_gp_fuse_bit(uint32_t gp_fuse_bit, bool check);

bool flashcalw_erase_gp_fuse_bitfield(uint32_t pos, uint32_t width,
		bool check);

bool flashcalw_erase_gp_fuse_byte(uint32_t gp_fuse_byte, bool check);

bool flashcalw_erase_all_gp_fuses(bool check);

void flashcalw_write_gp_fuse_bit(uint32_t gp_fuse_bit, bool value);

void flashcalw_write_gp_fuse_bitfield(uint32_t pos, uint32_t width,
		uint64_t value);

void flashcalw_write_gp_fuse_byte(uint32_t gp_fuse_byte, uint8_t value);

void flashcalw_write_all_gp_fuses(uint64_t value);

void flashcalw_set_gp_fuse_bit(uint32_t gp_fuse_bit, bool value);

void flashcalw_set_gp_fuse_bitfield(uint32_t pos, uint32_t width,
		uint64_t value);

void flashcalw_set_gp_fuse_byte(uint32_t gp_fuse_byte, uint8_t value);

void flashcalw_set_all_gp_fuses(uint64_t value);

//! @}


/*! \name Access to Flash Pages
 */
//! @{

void flashcalw_clear_page_buffer(void);

bool flashcalw_is_page_erased(void);

bool flashcalw_quick_page_read(int page_number);

bool flashcalw_erase_page(int page_number, bool check);

bool flashcalw_erase_all_pages(bool check);

void flashcalw_write_page(int page_number);

bool flashcalw_quick_user_page_read(void);

bool flashcalw_erase_user_page(bool check);

void flashcalw_write_user_page(void);

volatile void *flashcalw_memset8(volatile void *dst, uint8_t src,
		size_t nbytes, bool erase);

volatile void *flashcalw_memset16(volatile void *dst, uint16_t src,
		size_t nbytes, bool erase);

volatile void *flashcalw_memset32(volatile void *dst, uint32_t src,
		size_t nbytes, bool erase);

volatile void *flashcalw_memset64(volatile void *dst, uint64_t src,
		size_t nbytes, bool erase);

/*! \brief Copies \a nbytes bytes to the flash destination pointed to by \a dst
 *         from the repeated \a src big-endian source pattern.
 *
 * All pointer and size alignments are supported.
 *
 * \param dst Pointer to flash destination.
 * \param src Source double-word.
 * \param src_width \a src width in bits: 8, 16, 32 or 64.
 * \param nbytes Number of bytes to set.
 * \param erase Whether to erase before writing: \c true or \c false.
 *
 * \return The value of \a dst.
 *
 * \warning This function may be called with \a erase set to \c false only if
 *          the destination consists only of erased words, i.e. this function
 *          can not be used to write only one bit of a previously written word.
 *          E.g., if \c 0x00000001 then \c 0xFFFFFFFE are written to a word, the
 *          resulting value in flash may be different from \c 0x00000000.
 *
 * \warning A Lock Error is issued if the command is applied to pages belonging
 *          to a locked region or to the bootloader protected area.
 *
 * \note The FLASHCALW error status returned by \ref flashcalw_is_lock_error and
 *       \ref flashcalw_is_programming_error is updated.
 */
#define flashcalw_memset(dst, src, src_width, nbytes, erase) \
	TPASTE2(flashcalw_memset, src_width) ((dst), (src), (nbytes), (erase))

volatile void *flashcalw_memcpy(volatile void *dst, const void *src,
		size_t nbytes, bool erase);

//! @}

#endif  /* FLASHCALW_H_INCLUDED */
