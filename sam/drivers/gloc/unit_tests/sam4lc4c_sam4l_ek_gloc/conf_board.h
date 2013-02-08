/**
 * \file
 *
 * \brief Board configuration.
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

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

//! Osc frequency (Hz.) and startup time (RCOsc periods).
#define FOSC0                       (12000000)

//! Osc32 frequency (Hz.) and startup time (RCOsc periods).
#define FOSC32                      (32768)

/**
 * \name Board oscillator configuration
 *
 */
//@{
#define BOARD_OSC32_IS_XTAL         true
#define BOARD_OSC32_HZ              FOSC32
#define BOARD_OSC32_STARTUP_US      (1100000)
#define BOARD_OSC32_SELCURR         BSCIF_OSCCTRL32_SELCURR(10)
#define BOARD_OSC0_IS_XTAL          true
#define BOARD_OSC0_HZ               FOSC0
#define BOARD_OSC0_STARTUP_US       (1100)
//@}

/**
 * \name LEDs
 *
 * LED0 is a single yellow LED that is active low.
 */
//@{
#define LED0                            PC10
#define LED0_GPIO                       PIN_PC10
#define LED0_GPIO_MASK                  GPIO_PC10
#define LED0_ACTIVE_LEVEL             IOPORT_PIN_LEVEL_HIGH
#define LED0_INACTIVE_LEVEL           IOPORT_PIN_LEVEL_LOW
//@}

//! \name USART connections to GPIO for Virtual Com Port
// @{
#define COM_PORT_USART                 USART2
#define COM_PORT_USART_ID              ID_USART2
#define COM_PORT_RX_PIN                PIN_PC11B_USART2_RXD
#define COM_PORT_RX_GPIO               GPIO_PC11B_USART2_RXD
#define COM_PORT_RX_MUX                MUX_PC11B_USART2_RXD
#define COM_PORT_TX_PIN                PIN_PC12B_USART2_TXD
#define COM_PORT_TX_GPIO               GPIO_PC12B_USART2_TXD
#define COM_PORT_TX_MUX                MUX_PC12B_USART2_TXD
// @}

/* Enable Com Port. */
#define CONF_BOARD_COM_PORT

/* Backlight: configured to initialize & off to save power */
#define CONF_BOARD_BL

/* USB port: configured to initialize to draw less current on 4L USB port */
#define CONF_BOARD_USB_PORT

/* Enable GLOC LUT 0 pins. */
#define CONF_BOARD_GLOC_LUT0_PORT

#endif /* CONF_BOARD_H_INCLUDED */
