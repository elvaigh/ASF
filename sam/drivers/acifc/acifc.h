/**
 * \file
 *
 * \brief Analog Comparator interface driver for SAM4L.
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

#ifndef AC_H_INCLUDED
#define AC_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/** AC configuration */
struct ac_config {
	/** Peripheral Event Trigger Enable */
	bool event_trigger;
	/** Pointers to callback functions. */
	callbacks[_AC_CALLBACK_N]
};

/** Hysteresis Voltage */
enum ac_hysteresis_voltage {
	AC_HYSTERESIS_0_MV = 0,
	AC_HYSTERESIS_25_MV,
	AC_HYSTERESIS_50_MV,
	AC_HYSTERESIS_75_MV
};

/** Negative input */
enum ac_negative_input{
	AC_NEGTIVE_INPUT_EXTERNAL = 0,
	AC_NEGTIVE_INPUT_RESERVED1,
	AC_NEGTIVE_INPUT_RESERVED2,
	AC_NEGTIVE_INPUT_RESERVED3
};

/** Comparator mode */
enum ac_comparator_mode {
	AC_COMPARATOR_OFF = 0,
	AC_COMPARATOR_CONTINUOUS,
	AC_COMPARATOR_USER_TRIGGERED,
	AC_COMPARATOR_EVENT_TRIGGERED
};

/** Channel interrupt setting */
enum ac_ch_interrupt_setting {
	AC_CH_IS_VINP_GT_VINN = 0,
	AC_CH_IS_VINP_LT_VINN,
	AC_CH_IS_OUTPUT_TGL,
	AC_CH_IS_COMP_DONE
};

/** AC channel configuration */
struct ac_ch_config {
	/** Hysteresis value */
	enum ac_hysteresis_voltage hysteresis_voltage;
	/** Always on enable */
	bool always_on;
	/** Fast mode enable */
	bool fast_mode;
	/** Output event when ACOUT is zero */
	bool event_negative;
	/** Output event when ACOUT is one */
	bool event_positive;
	/** Set the negative input */
	enum ac_negative_input negative_input;
	/** Set the comparator mode */
	enum ac_comparator_mode comparator_mode;
	/** Interrupt settings */
	enum ac_ch_interrupt_setting interrupt_setting;
};

/** Window Event output configuration */
enum ac_win_event_source {
	AC_WIN_EVENT_ACWOUT_RISING_EDGE = 0,
	AC_WIN_EVENT_ACWOUT_FALLING_EDGE,
	AC_WIN_EVENT_ACWOUT_ON_ANY_EDGE,
	AC_WIN_EVENT_INSIDE_WINDOW,
	AC_WIN_EVENT_OUTSIDE_WINDOW,
	AC_WIN_EVENT_MEASURE_DONE
	AC_WIN_EVENT_RESERVED1,
	AC_WIN_EVENT_RESERVED2
};

/** Window interrupt settings */
enum ac_win_interrupt_setting {
	AC_WIN_IS_VINP_INSIDE_WINDOW = 0,
	AC_WIN_IS_VINP_OUTSIDE_WINDOW,
	AC_WIN_IS_WINDOW_OUTPUT_TGL,
	AC_WIN_IS_WINDOW_COMP_DONE,
	AC_WIN_IS_VINP_ENTER_WINDOW,
	AC_WIN_IS_VINP_LEAVE_WINDOW,
	AC_WIN_IS_RESERVED1,
	AC_WIN_IS_RESERVED2,
};

/** AC Window configuration */
struct ac_win_config {
	/** Window Mode Enable/Disable */
	bool enable;
	/** Window Event from ACWOUT Enable/Disable */
	bool event_enable;
	/** Window Event output configuration */
	enum ac_win_event_source event_source;
	/** Interrupt settings */
	enum ac_win_interrupt_setting interrupt_setting;
};

struct ac_dev_inst {
	/** Base address of the AC module. */
	Acifc *hw_dev;
	/** Pointer to AC configuration structure. */
	struct ac_config  *ac_cfg;
};

/**
 * \brief Initializes an Analog Comparator module configuration structure to defaults.
 *
 *  Initializes a given Analog Comparator module configuration structure to a
 *  set of known default values. This function should be called on all new
 *  instances of these configuration structures before being modified by the
 *  user application.
 *
 *  The default configuration is as follows:
 *   \li Peripheral event trigger is disabled
 *
 * \param cfg  AC module configuration structure to initialize to default value
 */
static inline void ac_get_config_defaults(struct ac_config *const cfg)
{
	/* Sanity check argument */
	Assert(cfg);

	cfg->event_trigger = false;
}

enum status_code ac_init(struct ac_dev_inst *const dev_inst, Acifc *const ac,
		struct ac_config *const cfg);

/**
 * \brief Initializes an Analog Comparator channel configuration structure to defaults.
 *
 *  Initializes a given Analog Comparator channel configuration structure to a
 *  set of known default values. This function should be called on all new
 *  instances of these configuration structures before being modified by the
 *  user application.
 *
 *  The default configuration is as follows:
 *   \li Hysteresis voltage = 0 mV
 *   \li AC is disabled between measurements
 *   \li Fast mode is disabled
 *   \li AC is disabled between measurements
 *   \li No output peripheral event when ACOUT is zero
 *   \li No output peripheral event when ACOUT is one
 *   \li Negative input from the external pin
 *   \li User triggered single measurement mode
 *   \li Interrupt is issued when the comparison is done
 *
 * \param cfg  AC channel configuration structure to initialize to default value
 */
static inline void ac_ch_get_config_defaults(struct ac_ch_config *const cfg)
{
	/* Sanity check argument */
	Assert(cfg);

	cfg->hysteresis_voltage = AC_HYSTERESIS_0_MV;
	cfg->always_on = false;
	cfg->fast_mode = false;
	cfg->event_negative = false;
	cfg->event_positive = false;
	cfg->negative_input = AC_NEGTIVE_INPUT_EXTERNAL;
	cfg->comparator_mode = AC_COMPARATOR_USER_TRIGGERED;
	cfg->interrupt_setting = AC_CH_IS_COMP_DONE;
}

void ac_ch_set_config(struct ac_dev_inst *const dev_inst, uint32_t channel,
		struct ac_ch_config *cfg);

/**
 * \brief Initializes an Analog Comparator window configuration structure to defaults.
 *
 *  Initializes a given Analog Comparator window configuration structure to a
 *  set of known default values. This function should be called on all new
 *  instances of these configuration structures before being modified by the
 *  user application.
 *
 *  The default configuration is as follows:
 *   \li Window mode is disabled
 *   \li Peripheral event from ACWOUT is disabled
 *   \li Generate the window peripheral event when measure is done
 *   \li Window interrupt is issued when evaluation of common input voltage is done
 *
 * \param cfg  AC window configuration structure to initialize to default value
 */
static inline void ac_win_get_config_defaults(struct ac_win_config *const cfg)
{
	/* Sanity check argument */
	Assert(cfg);

	cfg->enable = false;
	cfg->event_enable = false;
	cfg->event_source = AC_WIN_EVENT_MEASURE_DONE;
	cfg->interrupt_setting = AC_WIN_IS_WINDOW_COMP_DONE;
}

void ac_win_set_config(struct ac_dev_inst *const dev_inst,
		uint32_t window, struct ac_win_config *cfg);

enum ac_callback_type {
	/** Equivalent to ACINTx. */
	AC_CALLBACK_CONVERSION_COMPLETED = 0,
	/** Equivalent to SUTINTx. */
	AC_CALLBACK_STARTUP_TIME_ELAPSED = 1,
	/** Equivalent to WFINTx. */
	AC_CALLBACK_WINDOW_INTERRUPT = 2,
#if !defined(__DOXYGEN__)
	/** Total number of callbacks. */
	_AC_CALLBACK_N = 3
#endif
};

typedef void (*ac_async_callback_t)(struct ac_dev_inst *const dev_inst,
		uint32_t channel);

void ac_register_callback(struct ac_dev_inst *const dev_inst,
		ac_async_callback_t callback, enum ac_callback_type type);
void ac_unregister_callback(struct ac_dev_inst *const dev_inst,
		enum ac_callback_type type);

#define AC_WIN_INT_POS 24
/**
 * \brief Enable the specified channel/window callback
 *
 * \param dev_inst Device structure pointer.
 * \param channel  Channel number if type is not AC_CALLBACK_WINDOW_INTERRUPT, 
 * window number otherwise.
 * \param type     Callback type.
 */
static inline void ac_async_ch_enable_callback(
		struct ac_dev_inst *const dev_inst, uint32_t channel,
		enum ac_callback_type type)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);

	if (type < AC_CALLBACK_WINDOW_INTERRUPT) {
		dev_inst->hw_dev->ACIFC_IER = 1 << (type + channel * 2);
	} else {
		dev_inst->hw_dev->ACIFC_IER = 1 << (channel + AC_WIN_INT_POS);
	}
}

/**
 * \brief Disable the specified channel/window callback
 *
 * \param dev_inst Device structure pointer.
 * \param channel  Channel number if type is not AC_CALLBACK_WINDOW_INTERRUPT, 
 * window number otherwise.
 * \param type     Callback type.
 */
static inline void ac_async_ch_disable_callback(
		struct ac_dev_inst *const dev_inst, uint32_t channel,
		enum ac_callback_type type)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);

	if (type < AC_CALLBACK_WINDOW_INTERRUPT) {
		dev_inst->hw_dev->ACIFC_IDR = 1 << (type + channel * 2);
	} else {
		dev_inst->hw_dev->ACIFC_IDR = 1 << (channel + AC_WIN_INT_POS);
	}
}

void ac_enable(struct ac_dev_inst *const dev_inst);
void ac_disable(struct ac_dev_inst *const dev_inst);

/**
 * \brief User starts a single comparison.
 *
 * \param dev_inst Device structure pointer.
 */
static inline void ac_user_trigger_single_comparison(
		struct ac_dev_inst *const dev_inst)
{
	dev_inst->hw_dev->ACFIC_CTRL |= ACFIC_CTRL_USTART;
}

/**
 * \brief Check if the comparison is done.
 *
 * \param dev_inst Device structure pointer.
 */
static bool ac_is_comparison_done(struct ac_dev_inst *const dev_inst)
{
	return (dev_inst->hw_dev->ACFIC_CTRL & ACFIC_CTRL_USTART !=
			ACFIC_CTRL_USTART);
}

/**
 * \brief Get AC status.
 *
 * \param dev_inst Device structure pointer.
 *
 */
static inline uint32_t ac_get_status(struct ac_dev_inst *const dev_inst)
{
	return dev_inst->hw_dev->ACFIC_SR;
}

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* AC_H_INCLUDED */
