/**
 * \file
 *
 * \brief SAM D2x System Interrupt Driver
 *
 * Copyright (C) 2013 Atmel Corporation. All rights reserved.
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

#ifndef SYSTEM_PINMUX_H_INCLUDED
#define SYSTEM_PINMUX_H_INCLUDED

#include "pinmux.h"

/**
 * \brief Port pin drive output strength enum.
 *
 * Enum for the possible output drive strengths for the port pin
 * configuration structure, to indicate the driver strength the pin should
 * use.
 */
enum system_pinmux_pin_strength {
	/** Normal output driver strength. */
	SYSTEM_PINMUX_PIN_STRENGTH_NORMAL,
	/** High current output driver strength. */
	SYSTEM_PINMUX_PIN_STRENGTH_HIGH,
};

/**
 * \brief Port pin output slew rate enum.
 *
 * Enum for the possible output drive slew rates for the port pin
 * configuration structure, to indicate the driver slew rate the pin should
 * use.
 */
enum system_pinmux_pin_slew_rate {
	/** Normal pin output slew rate. */
	SYSTEM_PINMUX_PIN_SLEW_RATE_NORMAL,
	/** Enable slew rate limiter on the pin. */
	SYSTEM_PINMUX_PIN_SLEW_RATE_LIMITED,
};

/**
 * \brief Port pin output drive mode enum.
 *
 * Enum for the possible output drive modes for the port pin configuration
 * structure, to indicate the output mode the pin should use.
 */
enum system_pinmux_pin_drive {
	/** Use totem pole output drive mode. */
	SYSTEM_PINMUX_PIN_DRIVE_TOTEM,
	/** Use open drain output drive mode. */
	SYSTEM_PINMUX_PIN_DRIVE_OPEN_DRAIN,
};

void system_pinmux_group_set_output_strength(
		PortGroup *const port,
		const uint32_t mask,
		const enum system_pinmux_pin_strength mode);

void system_pinmux_group_set_output_slew_rate(
		PortGroup *const port,
		const uint32_t mask,
		const enum system_pinmux_pin_slew_rate mode);

void system_pinmux_group_set_output_drive(
		PortGroup *const port,
		const uint32_t mask,
		const enum system_pinmux_pin_drive mode);

/**
 * \brief Configures the output driver strength mode for a GPIO pin.
 *
 * Configures the output drive strength for a GPIO output, to
 * control the amount of current the pad is able to sink/source.
 *
 * \param[in] gpio_pin  Index of the GPIO pin to configure.
 * \param[in] mode      New output driver strength mode to configure.
 */
static inline void system_pinmux_pin_set_output_strength(
		const uint8_t gpio_pin,
		const enum system_pinmux_pin_strength mode)
{
	PortGroup* const port = system_pinmux_get_group_from_gpio_pin(gpio_pin);
	uint32_t pin_index = (gpio_pin % 32);

	if (mode == SYSTEM_PINMUX_PIN_STRENGTH_HIGH) {
		port->PINCFG[pin_index].reg |=  PORT_PINCFG_DRVSTR;
	}
	else {
		port->PINCFG[pin_index].reg &= ~PORT_PINCFG_DRVSTR;
	}
}

/**
 * \brief Configures the output slew rate mode for a GPIO pin.
 *
 * Configures the output slew rate mode for a GPIO output, to
 * control the speed at which the physical output pin can react to
 * logical changes of the I/O pin value.
 *
 * \param[in] gpio_pin  Index of the GPIO pin to configure.
 * \param[in] mode      New pin slew rate mode to configure.
 */
static inline void system_pinmux_pin_set_output_slew_rate(
		const uint8_t gpio_pin,
		const enum system_pinmux_pin_slew_rate mode)
{
	PortGroup* const port = system_pinmux_get_group_from_gpio_pin(gpio_pin);
	uint32_t pin_index = (gpio_pin % 32);

	if (mode == SYSTEM_PINMUX_PIN_SLEW_RATE_LIMITED) {
		port->PINCFG[pin_index].reg |=  PORT_PINCFG_SLEWLIM;
	}
	else {
		port->PINCFG[pin_index].reg &= ~PORT_PINCFG_SLEWLIM;
	}
}

/**
 * \brief Configures the output driver mode for a GPIO pin.
 *
 * Configures the output driver mode for a GPIO output, to
 * control the pad behavior.
 *
 * \param[in] gpio_pin  Index of the GPIO pin to configure.
 * \param[in] mode      New pad output driver mode to configure.
 */
static inline void system_pinmux_pin_set_output_drive(
		const uint8_t gpio_pin,
		const enum system_pinmux_pin_drive mode)
{
	PortGroup* const port = system_pinmux_get_group_from_gpio_pin(gpio_pin);
	uint32_t pin_index = (gpio_pin % 32);

	if (mode == SYSTEM_PINMUX_PIN_DRIVE_OPEN_DRAIN) {
		port->PINCFG[pin_index].reg |=  PORT_PINCFG_ODRAIN;
	}
	else {
		port->PINCFG[pin_index].reg &= ~PORT_PINCFG_ODRAIN;
	}
}

#endif
