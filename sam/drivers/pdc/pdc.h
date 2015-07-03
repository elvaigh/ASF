/**
 * \file
 *
 * \brief SAM Peripheral DMA Controller (PDC) driver.
 *
 * Copyright (c) 2011-2015 Atmel Corporation. All rights reserved.
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
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef PDC_H_INCLUDED
#define PDC_H_INCLUDED

/**
 * \defgroup asfdoc_sam_drivers_pdc_group SAM3A/3N/3S/3U/3X/4E/4N/4S/G Peripheral DMA Controller (PDC) Driver
 * This driver for Atmel&reg; | SMART ARM&reg;-based microcontrollers provides 
 * an interface for the configuration and management of the the Peripheral 
 * Direct Memory Access (DMA) Controller (PDC) module.
 *
 * The PDC transfers data between on-chip serial peripherals and the on and/or
 * off-chip memories. The link between the PDC and a serial peripheral is
 * operated by the AHB to ABP bridge.
 *
 * This module:
 * - Performs transfers to/from APB communication serial peripherals
 * - Supports half-duplex and full-duplex peripherals
 *
 * Devices from the following series can use this module:
 * - Atmel | SMART SAM3A
 * - Atmel | SMART SAM3N
 * - Atmel | SMART SAM3S
 * - Atmel | SMART SAM3U
 * - Atmel | SMART SAM3X
 * - Atmel | SMART SAM4E
 * - Atmel | SMART SAM4N
 * - Atmel | SMART SAM4S
 * - Atmel | SMART SAM G
 *
 * The outline of this documentation is as follows:
 *  - \ref asfdoc_sam_drivers_pdc_prerequisites
 *  - \ref asfdoc_sam_drivers_pdc_module_overview
 *  - \ref asfdoc_sam_drivers_pdc_special_considerations
 *  - \ref asfdoc_sam_drivers_pdc_extra_info
 *  - \ref asfdoc_sam_drivers_pdc_examples
 *  - \ref asfdoc_sam_drivers_pdc_api_overview
 *
 *
 * \section asfdoc_sam_drivers_pdc_prerequisites Prerequisites
 *
 * There are no prerequisites for this module.
 *
 *
 * \section asfdoc_sam_drivers_pdc_module_overview Module Overview
 * The user interface of each PDC channel is integrated into the user interface
 * of the peripheral it serves. The user interface of unidirectional channels
 * (receive only or transmit only), contains two 32-bit memory pointers and
 * two 16-bit counters, one set (pointer, counter) for current transfer and
 * one set (pointer, counter) for next transfer. The bidirectional channel
 * user interface contains four 32-bit memory pointers and four 16-bit counters.
 * Each set (pointer, counter) is used by current transmit, next transmit,
 * current receive and next receive. Using the PDC removes processor overhead
 * by reducing its intervention during the transfer. This significantly reduces
 * the number of clock cycles required for a data transfer, which improves
 * microcontroller performance. To launch a transfer, the peripheral triggers
 * its associated PDC channels by using transmit and receive signals.
 * When the programmed data is transferred, an end of transfer interrupt is
 * generated by the peripheral itself.
 *
 * \section asfdoc_sam_drivers_pdc_special_considerations Special Considerations
 * There are no special considerations for this module.
 *
 *
 * \section asfdoc_sam_drivers_pdc_extra_info Extra Information

 * For extra information, see \ref asfdoc_sam_drivers_pdc_extra. This includes:
 *  - \ref asfdoc_sam_drivers_pdc_extra_acronyms
 *  - \ref asfdoc_sam_drivers_pdc_extra_dependencies
 *  - \ref asfdoc_sam_drivers_pdc_extra_errata
 *  - \ref asfdoc_sam_drivers_pdc_extra_history
 *
 * \section asfdoc_sam_drivers_pdc_examples Examples
 *
 * For a list of examples related to this driver, see
 * \ref asfdoc_sam_drivers_pdc_exqsg.
 *
 *
 * \section asfdoc_sam_drivers_pdc_api_overview API Overview
 * @{
 */

#include <compiler.h>

/// @cond
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/**
 * \brief PDC data packet for transfer.
 */
typedef struct pdc_packet {
	/** Start address of the transfer packet data. */
	uint32_t ul_addr;
	/** Transfer packet size (in units of the peripheral data width). */
	uint32_t ul_size;
} pdc_packet_t;

void pdc_tx_init(Pdc *p_pdc, pdc_packet_t *p_packet,
		pdc_packet_t *p_next_packet);
void pdc_rx_init(Pdc *p_pdc, pdc_packet_t *p_packet,
		pdc_packet_t *p_next_packet);
void pdc_rx_clear_cnt(Pdc *p_pdc);
void pdc_enable_transfer(Pdc *p_pdc, uint32_t ul_controls);
void pdc_disable_transfer(Pdc *p_pdc, uint32_t ul_controls);
uint32_t pdc_read_status(Pdc *p_pdc);
uint32_t pdc_read_rx_ptr(Pdc *p_pdc);
uint32_t pdc_read_rx_counter(Pdc *p_pdc);
uint32_t pdc_read_tx_ptr(Pdc *p_pdc);
uint32_t pdc_read_tx_counter(Pdc *p_pdc);
uint32_t pdc_read_rx_next_ptr(Pdc *p_pdc);
uint32_t pdc_read_rx_next_counter(Pdc *p_pdc);
uint32_t pdc_read_tx_next_ptr(Pdc *p_pdc);
uint32_t pdc_read_tx_next_counter(Pdc *p_pdc);

/// @cond
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

/** @} */
 
/**
 * \page asfdoc_sam_drivers_pdc_extra Extra Information for Peripheral DMA Controller
 *
 * \section asfdoc_sam_drivers_pdc_extra_acronyms Acronyms
 * Below is a table listing the acronyms used in this module, along with their
 * intended meanings.
 *
 * <table>
 *  <tr>
 *      <th>Acronym</th>
 *      <th>Definition</th>
 * </tr>
 * </tr>
 * <tr>
 *      <td>AHB</td>
 *      <td>Advanced High-performance Bus</td>
 * </tr>
 * <tr>
 *      <td>AMBA</td>
 *      <td> Advanced Microcontroller Bus Architecture</td>
 * </tr>
 * <tr>
 *      <td>QSG</td>
 *      <td>Quick Start Guide</td>
 *
 * </tr>
 * <tr>
 *   <td>RCR</td>
 *   <td>Receive Counter Register</td>
 * </tr>
 * <tr>
 *   <td>RNCR</td>
 *   <td>Return Receive Next Counter Register</td>
 * </tr>
 * <tr>
 *   <td>RNPR</td>
 *   <td>Receive Next Pointer Register</td>
 * </tr>
 * <tr>
 *   <td>RPR</td>
 *   <td>Receive Pointer Register</td>
 * </tr>
 * <tr>
 *   <td>TCR</td>
 *   <td>Transmit Counter Register</td>
 * </tr>
 * <tr>
 *   <td>TNCR</td>
 *   <td>Transmit Next Counter Register</td>
 * </tr>
 * <tr>
 *   <td>TNPR</td>
 *   <td>Transmit Next Pointer Register</td>
 * </tr>
 * <tr>
 *   <td>TPR</td>
 *   <td>Transmit Pointer Register</td>
 * </tr>
 * </table>
 *
 *
 * \section asfdoc_sam_drivers_pdc_extra_dependencies Dependencies
 * This driver has the following dependencies:
 *
 *  - None
 *
 *
 * \section asfdoc_sam_drivers_pdc_extra_errata Errata
 * There are no errata related to this driver.
 *
 *
 * \section asfdoc_sam_drivers_pdc_extra_history Module History
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
 *		<td>Initial document release</td>
 *	</tr>
 * </table>
 *
 *
 *
 * \page asfdoc_sam_pmc_quickstart Quickstart Guide for SAM4
 * This is the quickstart guide for the "PDC driver" with step-by-step
 * instructions on how to configure and use the driver.
 *
 * \section asfdoc_sam_pmc_quickstart_basic_use_case Basic Use Case
 *
 * A handler is required for the interrupt, below is a simple example:
 * \snippet pdc_uart_example.c int_handler
 *
 * First initialise the board:
 *
 * \snippet pdc_uart_example.c board_setup
 *
 * Now setup the PDC registers:
 * \snippet pdc_uart_example.c pdc_config
 *
 * Enable UART IRQ:
 * \snippet pdc_uart_example.c uart_irq
 *
 * Enable UART interrupt
 * \snippet pdc_uart_example.c uart_nvic_irq
 *
 * Once the required number of bytes have been transferred, an interrupt is
 * triggered and the handler will run. The main program may execute other code
 * or be busy-waiting:
 *
 * \snippet pdc_uart_example.c busy_waiting
 *
 * \page asfdoc_sam_drivers_pdc_exqsg Examples for Peripheral DMA Controller
 *
 * This is a list of the available Quick Start guides (QSGs) and example
 * applications for \ref asfdoc_sam_drivers_pdc_group. QSGs are simple examples with
 * step-by-step instructions to configure and use this driver in a selection of
 * use cases. Note that a QSG can be compiled as a standalone application or be
 * added to the user application.
 *
 *  - \subpage asfdoc_sam_drivers_pdc_example
 *
 *
 * \page asfdoc_sam_drivers_pdc_document_revision_history Document Revision History
 *
 * <table>
 *	<tr>
 *		<th>Doc. Rev.</td>
 *		<th>Date</td>
 *		<th>Comments</td>
 *	</tr>
 *	<tr>
 *		<td>42316B</td>
 *		<td>07/2015</td>
 *		<td>Updated title of application note and added list of supported devices</td>
 *	</tr>
 *	<tr>
 *		<td>42316A</td>
 *		<td>05/2014</td>
 *		<td>Initial document release</td>
 *	</tr>
 * </table>
 *
 */

#endif /* PDC_H_INCLUDED */
