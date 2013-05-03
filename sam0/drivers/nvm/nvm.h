/**
 * \file
 *
 * \brief SAM D20 Non-Volatile Memory driver
 *
 * Copyright (C) 2012-2013 Atmel Corporation. All rights reserved.
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
#ifndef NVM_H_INCLUDED
#define NVM_H_INCLUDED

/**
 * \defgroup asfdoc_samd20_nvm_group SAM D20 Non-Volatile Memory Driver (NVM)
 *
 * This driver for SAM D20 devices provides an interface for the configuration
 * and management of non-volatile memories within the device, for partitioning,
 * erasing, reading and writing of data.
 *
 * The following peripherals are used by this module:
 *
 *  - NVM (Non-Volatile Memory)
 *
 * The outline of this documentation is as follows:
 *  - \ref asfdoc_samd20_nvm_prerequisites
 *  - \ref asfdoc_samd20_nvm_module_overview
 *  - \ref asfdoc_samd20_nvm_special_considerations
 *  - \ref asfdoc_samd20_nvm_extra_info
 *  - \ref asfdoc_samd20_nvm_examples
 *  - \ref asfdoc_samd20_nvm_api_overview
 *
 *
 * \section asfdoc_samd20_nvm_prerequisites Prerequisites
 *
 * There are no prerequisites for this module.
 *
 *
 * \section asfdoc_samd20_nvm_module_overview Module Overview
 *
 * The Non-Volatile Memory (NVM) module provides an interface to the device's
 * Non-Volatile Memory controller, so that memory pages can be written, read,
 * erased and reconfigured in a standardized manner.
 *
 * \subsection asfdoc_samd20_nvm_module_overview_regions Memory Regions
 * The NVM memory space of the SAM D20 devices is divided into two sections:
 * a Main Array section, and an Auxiliary space section. The Main Array space
 * can be configured to have an (emulated) EEPROM and/or boot loader section.
 * The memory layout with the EEPROM and bootloader partitions is shown in
 * \ref asfdoc_samd20_nvm_module_mem_layout "the figure below".
 *
 * \anchor asfdoc_samd20_nvm_module_mem_layout
 * \dot
 * digraph memory_layout {
 *  size="5,5"
 *  node [shape=plaintext]
 *  memory [label=<
 *   <table border="0" cellborder="1" cellspacing="0" >
 *    <tr>
 *     <td align="right" border="0"> End of NVM Memory </td>
 *     <td rowspan="3" align="center"> Reserved EEPROM Section </td>
 *    </tr>
 *    <tr>
 *     <td align="right" border="0"> </td>
 *    </tr>
 *    <tr>
 *     <td align="right" border="0"> Start of EEPROM Memory </td>
 *    </tr>
 *    <tr>
 *     <td align="right" border="0"> End of Application Memory </td>
 *     <td rowspan="3" align="center"> Application Section </td>
 *    </tr>
 *    <tr>
 *     <td height="300" align="right" border="0"> </td>
 *    </tr>
 *    <tr>
 *     <td align="right" border="0"> Start of Application Memory </td>
 *    </tr>
 *    <tr>
 *     <td align="right" border="0"> End of Bootloader Memory </td>
 *     <td rowspan="3" align="center"> BOOT Section </td>
 *    </tr>
 *    <tr>
 *     <td align="right" border="0"> </td>
 *    </tr>
 *    <tr>
 *     <td align="right" border="0"> Start of NVM Memory</td>
 *    </tr>
 *   </table>
 *  >]
 * }
 * \enddot
 *
 * The Main Array is divided into rows and pages, where each row contains four
 * pages. The size of each page may vary from 8-1024 bytes dependent of the
 * device. Device specific parameters such as the page size and total number of
 * pages in the NVM memory space are available via the \ref nvm_get_parameters()
 * function.
 *
 * A NVM page number and address can be computed via the following equations:
 *
 * \f[ PageNum = (RowNum \times 4) + PagePosInRow \f]
 * \f[ PageAddr = PageNum \times PageSize \f]
 *
 * \ref asfdoc_samd20_nvm_module_row_layout "The figure below" shows an example
 * of the memory page and address values associated with logical row 7 of the
 * NVM memory space.
 *
 * \anchor asfdoc_samd20_nvm_module_row_layout
 * \dot
 * digraph row_layout {
 *  size="4,4"
 *  node [shape=plaintext]
 *  row [label=<
 *   <table border="0" cellborder="1" cellspacing="0">
 *    <tr>
 *     <td align="right" border ="0"> Row 0x07 </td>
 *     <td > Page 0x1F </td>
 *     <td > Page 0x1E </td>
 *     <td > Page 0x1D </td>
 *     <td > Page 0x1C </td>
 *    </tr>
 *    <tr>
 *     <td align="right" border ="0"> Address </td>
 *     <td border="0"> 0x7C0 </td>
 *     <td border="0"> 0x780 </td>
 *     <td border="0"> 0x740 </td>
 *     <td border="0"> 0x700 </td>
 *    </tr>
 *   </table>
 *  >]
 * }
 * \enddot
 *
 * \subsection asfdoc_samd20_nvm_module_overview_locking_regions Region Lock Bits
 * As mentioned in \ref asfdoc_samd20_nvm_module_overview_regions, the main
 * block of the NVM memory is divided into a number of individually addressable
 * pages. These pages are grouped into 16 equal sized regions, where each region
 * can be locked separately issuing an \ref NVM_COMMAND_LOCK_REGION command or
 * by writing the LOCK bits in the User Row. Rows reserved for the EEPROM
 * section are not affected by the lock bits or commands.
 *
 * \note By using the \ref NVM_COMMAND_LOCK_REGION or
 *       \ref NVM_COMMAND_UNLOCK_REGION commands the settings will remain in
 *       effect until the next device reset. By changing the default lock
 *       setting for the regions, the auxiliary space must to be written,
 *       however the adjusted configuration will not take effect until the next
 *       device reset.
 *
 * \note If the \ref asfdoc_samd20_nvm_special_consideration_security_bit is
 *       set, the auxiliary space cannot be written to. Clearing of the security
 *       bit can only be performed by a full chip erase.
 *
 * \subsection asfdoc_samd20_nvm_module_overview_sub_rw Read/Write
 * Reading from the NVM memory can be performed using direct addressing into the
 * NVM memory space, or by calling the \ref nvm_read_buffer() function.
 *
 * Writing to the NVM memory must be performed by the \ref nvm_write_buffer()
 * function - additionally, a manual page program command must be issued if
 * the NVM controller is configured in manual page writing mode, or a buffer of
 * data less than a full page is passed to the buffer write function.
 *
 * Before a page can be updated, the associated NVM memory row must be erased
 * first via the \ref nvm_erase_row() function. Writing to a non-erased page
 * will result in corrupt data being stored in the NVM memory space.
 *
 * \section asfdoc_samd20_nvm_special_considerations Special Considerations
 *
 * \subsection asfdoc_samd20_nvm_special_consideration_pageerase Page Erasure
 * The granularity of an erase is per row, while the granularity of a write is
 * per page. Thus, if the user application is modifying only one page of a row,
 * the remaining pages in the row must be buffered and the row erased, as an
 * erase is mandatory before writing to a page.
 *
 * \subsection asfdoc_samd20_nvm_special_consideration_clocks Clocks
 * The user must ensure that the driver is configured with a proper number of
 * wait states when the CPU is running at high frequencies.
 *
 * \subsection asfdoc_samd20_nvm_special_consideration_security_bit Security Bit
 * The User Row in the Auxiliary Space Cannot be read or written when
 * the Security Bit is set. The Security Bit can be set by using passing
 * \ref NVM_COMMAND_SET_SECURITY_BIT to the \ref nvm_execute_command() function,
 * or it will be be set if one tries to access a locked region. See
 * \ref asfdoc_samd20_nvm_module_overview_locking_regions.
 *
 * The Security Bit can only be cleared by performing a chip erase.
 *
 *
 * \section asfdoc_samd20_nvm_extra_info Extra Information for NVM
 *
 * For extra information see \ref asfdoc_samd20_nvm_extra. This includes:
 *  - \ref asfdoc_samd20_nvm_extra_acronyms
 *  - \ref asfdoc_samd20_nvm_extra_dependencies
 *  - \ref asfdoc_samd20_nvm_extra_errata
 *  - \ref asfdoc_samd20_nvm_extra_history
 *
 *
 * \section asfdoc_samd20_nvm_examples Examples
 *
 * The following Quick Start guides and application examples are available for this driver:
 * - \ref asfdoc_samd20_nvm_basic_use_case
 *
 *
 * \section asfdoc_samd20_nvm_api_overview API Overview
 * @{
 */

#include <compiler.h>
#include <status_codes.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__DOXYGEN__)
/**
 * \brief Mask for the error flags in the status register.
 */
#  define NVM_ERRORS_MASK (NVMCTRL_STATUS_PROGE | \
                           NVMCTRL_STATUS_LOCKE | \
                           NVMCTRL_STATUS_NVME)
#endif

/**
 * \brief NVM error flags.
 *
 * Possible NVM controller error codes, which can be returned by the NVM
 * controller after a command is issued.
 */
enum nvm_error {
	/** No errors */
	NVM_ERROR_NONE = 0,
	/** Lock error, a locked region was attempted accessed. */
	NVM_ERROR_LOCK = NVMCTRL_STATUS_NVME | NVMCTRL_STATUS_LOCKE,
	/** Program error, invalid command was executed. */
	NVM_ERROR_PROG = NVMCTRL_STATUS_NVME | NVMCTRL_STATUS_PROGE,
};

/**
 * \brief NVM controller commands.
 */
enum nvm_command {
	/** Erases the addressed memory row. */
	NVM_COMMAND_ERASE_ROW                  = NVMCTRL_CTRLA_CMD_ER,

	/** Write the contents of the page buffer to the addressed memory page. */
	NVM_COMMAND_WRITE_PAGE                 = NVMCTRL_CTRLA_CMD_WP,

	/** Erases the addressed auxiliary memory row.
	 *
	 *  \note This command can only be given when the security bit is not set.
	 */
	NVM_COMMAND_ERASE_AUX_ROW              = NVMCTRL_CTRLA_CMD_EAR,

	/** Write the contents of the page buffer to the addressed auxiliary memory
	 *  row.
	 *
	 *  \note This command can only be given when the security bit is not set.
	 */
	NVM_COMMAND_WRITE_AUX_ROW              = NVMCTRL_CTRLA_CMD_WAP,

	/** Locks the addressed memory region, preventing further modifications
	 *  until the region is unlocked or the device is erased.
	 */
	NVM_COMMAND_LOCK_REGION                = NVMCTRL_CTRLA_CMD_LR,

	/** Unlocks the addressed memory region, allowing the region contents to be
	 *  modified.
	 */
	NVM_COMMAND_UNLOCK_REGION              = NVMCTRL_CTRLA_CMD_UR,

	/** Clears the page buffer of the NVM controller, resetting the contents to
	 *  all zero values.
	 */
	NVM_COMMAND_PAGE_BUFFER_CLEAR          = NVMCTRL_CTRLA_CMD_PBC,

	/** Sets the device security bit, disallowing the changing of lock bits and
	 *  auxiliary row data until a chip erase has been performed.
	 */
	NVM_COMMAND_SET_SECURITY_BIT           = NVMCTRL_CTRLA_CMD_SSB,

	/** Enter power reduction mode in the NVM controller to reduce the power
	 *  consumption of the system. When in low power mode, all commands other
	 *  than \ref NVM_COMMAND_EXIT_LOW_POWER_MODE will fail.
	 */
	NVM_COMMAND_ENTER_LOW_POWER_MODE       = NVMCTRL_CTRLA_CMD_SPRM,

	/** Exit power reduction mode in the NVM controller to allow other NVM
	 *  commands to be issued.
	 */
	NVM_COMMAND_EXIT_LOW_POWER_MODE        = NVMCTRL_CTRLA_CMD_CPRM,
};

/**
 * \brief NVM controller power reduction mode configurations.
 *
 * Power reduction modes of the NVM controller, to conserve power while the
 * device is in sleep.
 */
enum nvm_sleep_power_mode {
	/** NVM controller exits low power mode on first access after sleep. */
	NVM_SLEEP_POWER_MODE_WAKEONACCESS  = NVMCTRL_CTRLB_SLEEPPRM_WAKEONACCESS,
	/** NVM controller exits low power mode when the device exits sleep mode. */
	NVM_SLEEP_POWER_MODE_WAKEUPINSTANT = NVMCTRL_CTRLB_SLEEPPRM_WAKEUPINSTANT,
	/** Power reduction mode in the NVM controller disabled. */
	NVM_SLEEP_POWER_MODE_ALWAYS_AWAKE  = NVMCTRL_CTRLB_SLEEPPRM_DISABLED,
};

/**
 * \brief NVM controller configuration structure.
 *
 * Configuration structure for the NVM controller within the device.
 */
struct nvm_config {
	/** Power reduction mode during device sleep. */
	enum nvm_sleep_power_mode sleep_power_mode;
	/** Manual write mode; if enabled, pages loaded into the NVM buffer will
	 *  not be written until a separate write command is issued. If disabled,
	 *  writing to the last byte in the NVM page buffer will trigger an automatic
	 *  write.
	 *
	 *  \note If a partial page is to be written, a manual write command must be
	 *        executed in either mode.
	 */
	bool manual_page_write;
	/** Number of wait states to insert when reading from flash, to prevent
	 *  invalid data from being read at high clock frequencies.
	 */
	uint8_t wait_states;
};

/**
 * \brief NVM memory parameter structure.
 *
 * Structure containing the memory layout parameters of the NVM module.
 */
struct nvm_parameters {
	/** Number of bytes per page. */
	uint8_t  page_size;
	/** Number of pages in the main array. */
	uint16_t nvm_number_of_pages;
	/** Size of the emulated EEPROM memory section configured in the NVM
	 *  auxiliary memory space. */
	uint32_t eeprom_number_of_pages;
	/** Size of the Bootloader memory section configured in the NVM auxiliary
	 *  memory space. */
	uint32_t bootloader_number_of_pages;
};

/**
 * \name Configuration and Initialization
 * @{
 */

/**
 * \brief Initializes an NVM controller configuration structure to defaults.
 *
 * Initializes a given NVM controller configuration structure to a set of
 * known default values. This function should be called on all new
 * instances of these configuration structures before being modified by the
 * user application.
 *
 * The default configuration is as follows:
 *  \li Power reduction mode enabled after sleep until first NVM access
 *  \li Automatic page commit when full pages are written to
 *  \li Number of FLASH wait states left unchanged
 *
 * \param[out] config  Configuration structure to initialize to default values
 *
 */
static inline void nvm_get_config_defaults(
		struct nvm_config *const config)
{
	/* Sanity check the parameters */
	Assert(config);

	/* Write the default configuration for the NVM configuration */
	config->sleep_power_mode  = NVM_SLEEP_POWER_MODE_WAKEONACCESS;
	config->manual_page_write = false;
	config->wait_states       = NVMCTRL->CTRLB.bit.RWS;
}

enum status_code nvm_set_config(
		const struct nvm_config *const config);

/**
 * \brief Checks if the NVM controller is ready to accept a new command.
 *
 * Checks the NVM controller to determine if it is currently busy execution an
 * operation, or ready for a new command.
 *
 * \return Busy state of the NVM controller.
 *
 * \retval true   If the hardware module is ready for a new command
 * \retval false  If the hardware module is busy executing a command
 *
 */
static inline bool nvm_is_ready(void)
{
	/* Get a pointer to the module hardware instance */
	Nvmctrl *const nvm_module = NVMCTRL;

	return nvm_module->INTFLAG.reg & NVMCTRL_INTFLAG_READY;
}

/** @} */

/**
 * \name NVM Access Management
 * @{
 */

void nvm_get_parameters(
		struct nvm_parameters *const parameters);

enum status_code nvm_write_buffer(
		const uint32_t destination_address,
		const uint8_t *buffer,
		uint16_t length);

enum status_code nvm_read_buffer(
		const uint32_t source_address,
		uint8_t *const buffer,
		uint16_t length);

enum status_code nvm_update_buffer(
		const uint32_t destination_address,
		uint8_t *const buffer,
		uint16_t offset,
		uint16_t length);

enum status_code nvm_erase_row(
		const uint32_t row_address);

enum status_code nvm_execute_command(
		const enum nvm_command command,
		const uint32_t address,
		const uint32_t parameter);

/**
 * \brief Retrieves the error code of the last issued NVM operation.
 *
 * Retrieves the error code from the last executed NVM operation. Once
 * retrieved, any error state flags in the controller are cleared.
 *
 * \note The \ref nvm_is_ready() function is an exception. Thus, errors
 *       retrieved after running this function should be valid for the function
 *       executed before \ref nvm_is_ready().
 *
 * \return Error caused by the last NVM operation.
 *
 * \retval NVM_ERROR_NONE  No error occurred in the last NVM operation
 *
 * \retval NVM_ERROR_LOCK  The last NVM operation attempted to access a locked
 *                         region
 * \retval NVM_ERROR_PROG  An invalid NVM command was issued
 */
static inline enum nvm_error nvm_get_error(void)
{
	enum nvm_error ret_val;

	/* Get a pointer to the module hardware instance */
	Nvmctrl *const nvm_module = NVMCTRL;

	/* Mask out non-error bits */
	ret_val = (enum nvm_error)(nvm_module->STATUS.reg & NVM_ERRORS_MASK);

	/* Clear error flags */
	nvm_module->STATUS.reg &= ~NVMCTRL_STATUS_MASK;

	/* Return error code from the NVM controller */
	return ret_val;
}

/** @} */

#ifdef __cplusplus
}
#endif

/** @} */

/**
 * \page asfdoc_samd20_nvm_extra Extra Information for NVM Driver
 *
 * \section asfdoc_samd20_nvm_extra_acronyms Acronyms
 * The table below presents the acronyms used in this module:
 *
 * <table>
 *  <tr>
 *   <th>Acronym</th>
 *   <th>Description</th>
 *  </tr>
 *  <tr>
 *   <td>NVM</td>
 *   <td>Non-Volatile Memory</td>
 *  </tr>
 *  <tr>
 *   <td>EEPROM</td>
 *   <td>Electrically Erasable Programmable Read-Only Memory</td>
 *  </tr>
 * </table>
 *
 *
 * \section asfdoc_samd20_nvm_extra_dependencies Dependencies
 * This driver has the following dependencies:
 *
 *  - None
 *
 *
 * \section asfdoc_samd20_nvm_extra_errata Errata
 * There are no errata related to this driver.
 *
 *
 * \section asfdoc_samd20_nvm_extra_history Module History
 * An overview of the module history is presented in the table below, with
 * details on the enhancements and fixes made to the module since its first
 * release. The current version of this corresponds to the newest version in
 * the table.
 *
 * <table>
 *	<tr>
 *		<th>Changelog</th>
 *	</tr>
 *	<tr>
 *		<td>Initial Release</td>
 *	</tr>
 * </table>
 */

/**
 * \page asfdoc_samd20_nvm_exqsg Examples for NVM Driver
 *
 * This is a list of the available Quick Start guides (QSGs) and example
 * applications for \ref asfdoc_samd20_nvm_group. QSGs are simple examples with
 * step-by-step instructions to configure and use this driver in a selection of
 * use cases. Note that QSGs can be compiled as a standalone application or be
 * added to the user application.
 *
 *  - \subpage asfdoc_samd20_nvm_basic_use_case
 */

#endif /* NVM_H_INCLUDED */
