/**
 * \file
 *
 * \brief SAM D20 Analog Comparator Driver
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
#ifndef AC_H_INCLUDED
#define AC_H_INCLUDED

/**
 * \defgroup asfdoc_samd20_ac_group SAM D20 Analog Comparator Driver (AC)
 *
 * This driver for SAM D20 devices provides an interface for the configuration
 * and management of the device's Analog Comparator functionality, for the
 * comparison of analog voltages against a known reference voltage to determine
 * its relative level.
 *
 * The following peripherals are used by this module:
 *
 *  - AC (Analog Comparator)
 *
 * The outline of this documentation is as follows:
 *  - \ref asfdoc_samd20_ac_prerequisites
 *  - \ref asfdoc_samd20_ac_module_overview
 *  - \ref asfdoc_samd20_ac_special_considerations
 *  - \ref asfdoc_samd20_ac_extra_info
 *  - \ref asfdoc_samd20_ac_examples
 *  - \ref asfdoc_samd20_ac_api_overview
 *
 *
 * \section asfdoc_samd20_ac_prerequisites Prerequisites
 *
 * There are no prerequisites for this module.
 *
 *
 * \section asfdoc_samd20_ac_module_overview Module Overview
 *
 * The Analog Comparator module provides an interface for the comparison of one
 * or more analog voltage inputs (sourced from external or internal inputs)
 * against a known reference voltage, to determine if the unknown voltage is
 * higher or lower than the reference. Additionally, window functions are
 * provided so that two comparators can be connected together to determine if
 * an input is below, inside, above or outside the two reference points of the
 * window.
 *
 * Each comparator requires two analog input voltages, a positive and negative
 * channel input. The result of the comparison is a binary \c true if the
 * comparator's positive channel input is higher than the comparator's negative
 * input channel, and \c false if otherwise.
 *
 * \subsection asfdoc_samd20_ac_module_overview_pairs Window Comparators and Comparator Pairs
 * Each comparator module contains one or more comparator pairs, a set of two
 * distinct comparators which can be used independently or linked together for
 * Window Comparator mode. In this latter mode, the two comparator units in a
 * comparator pair are linked together to allow the module to detect if an input
 * voltage is below, inside, above or outside a window set by the upper and
 * lower threshold voltages set by the two comparators. If not required, window
 * comparison mode can be turned off and the two comparator units can be
 * configured and used separately.
 *
 * \subsection asfdoc_samd20_ac_module_overview_pos_neg_mux Positive and Negative Input MUXs
 * Each comparator unit requires two input voltages, a positive and negative
 * channel (note that these names refer to the logical operation that the unit
 * performs, and both voltages should be above GND) which are then compared with
 * one another. Both the positive and negative channel inputs are connected to
 * a pair of MUXs, which allows one of several possible inputs to be selected
 * for each comparator channel.
 *
 * The exact channels available for each comparator differ for the positive and
 * negative inputs, but the same MUX choices are available for all comparator
 * units (i.e. all positive MUXes are identical, all negative MUXes are
 * identical). This allows the user application to select which voltages are
 * compared to one-another.
 *
 * When used in window mode, both comparators in the window pair should have
 * their positive channel input MUXs configured to the same input channel, with
 * the negative channel input MUXs used to set the lower and upper window
 * bounds.
 *
 * \subsection asfdoc_samd20_ac_module_overview_output_filtering Output Filtering
 * The output of each comparator unit can either be used directly with no
 * filtering (giving a lower latency signal, with potentially more noise around
 * the comparison threshold) or it can be passed through a multiple stage
 * digital majority filter. Several filter lengths are available, with the
 * longer stages producing a more stable result, at the expense of a higher
 * latency.
 *
 * When output filtering is used in single shot mode, a single trigger of the
 * comparator will automatically perform the required number of samples to
 * produce a correctly filtered result.
 *
 * \subsection asfdoc_samd20_ac_module_overview_input_hysteresis Input Hysteresis
 * To prevent unwanted noise around the threshold where the comparator unit's
 * positive and negative input channels are close in voltage to one another, an
 * optional hysteresis can be used to widen the point at which the output result
 * flips. This mode will prevent a change in the comparison output unless the
 * inputs cross one-another beyond the hysteresis gap introduces by this mode.
 *
 * \subsection asfdoc_samd20_ac_module_overview_sampling Single Shot and Continuous Sampling Modes
 * Comparators can be configured to run in either Single Shot or Continuous
 * sampling modes; when in Single Shot mode, the comparator will only perform a
 * comparison (and any resulting filtering, see
 * \ref asfdoc_samd20_ac_module_overview_output_filtering) when triggered via a
 * software or event trigger. This mode improves the power efficiency of the
 * system by only performing comparisons when actually required by the
 * application.
 *
 * For systems requiring a lower latency or more frequent comparisons,
 * continuous mode will place the comparator into continuous sampling mode,
 * which increases the module power consumption but decreases the latency
 * between each comparison result by automatically performing a comparison on
 * every cycle of the module's clock.
 *
 * \subsection asfdoc_samd20_ac_module_overview_events Input and Output Events
 * Each comparator unit is capable of being triggered by both software and
 * hardware triggers. Hardware input events allow for other peripherals to
 * automatically trigger a comparison on demand - for example, a timer output
 * event could be used to trigger comparisons at a desired regular interval.
 *
 * The module's output events can similarly be used to trigger other hardware
 * modules each time a new comparison result is available. This scheme allows
 * for reduced levels of CPU usage in an application and lowers the overall
 * system response latency by directly triggering hardware peripherals from one
 * another without requiring software intervention.
 *
 * \subsection asfdoc_samd20_ac_module_overview_physical Physical Connection
 * Physically, the modules are interconnected within the device as shown in
 * \ref asfdoc_samd20_ac_module_int_connections "the diagram below".
 *
 * \anchor asfdoc_samd20_ac_module_int_connections
 * \dot
 * digraph overview {
 *  rankdir = LR;
 *  splines = false;
 *
 *  pos_src1_1 [label="GPIO Pins", shape=none, height=0];
 *  neg_src1_1 [label="GPIO Pins", shape=none, height=0];
 *  neg_src1_2 [label="Internal DAC", shape=none, height=0];
 *  neg_src1_3 [label="Internal Refs", shape=none, height=0];
 *  pos_src2_1 [label="GPIO Pins", shape=none, height=0];
 *  neg_src2_1 [label="GPIO Pins", shape=none, height=0];
 *  neg_src2_2 [label="Internal DAC", shape=none, height=0];
 *  neg_src2_3 [label="Internal Refs", shape=none, height=0];
 *  res_out1 [label="", style=invisible];
 *  res_out2 [label="", style=invisible];
 *  res_window [label="", style=invisible];
 *
 *  mux_pos1 [label="", shape=polygon, sides=4, distortion=0.6, orientation=90, style=filled, fillcolor=black, height=0.9, width=0.2];
 *  mux_neg1 [label="", shape=polygon, sides=4, distortion=0.6, orientation=90, style=filled, fillcolor=black, height=0.9, width=0.2];
 *  mux_neg2 [label="", shape=polygon, sides=4, distortion=0.6, orientation=90, style=filled, fillcolor=black, height=0.9, width=0.2];
 *  mux_pos2 [label="", shape=polygon, sides=4, distortion=0.6, orientation=90, style=filled, fillcolor=black, height=0.9, width=0.2];
 *  ac1 [label="AC 1", shape=triangle, orientation=-90, style=filled, fillcolor=darkolivegreen1, height=1, width=1];
 *  ac2 [label="AC 2", shape=triangle, orientation=-90, style=filled, fillcolor=darkolivegreen1, height=1, width=1];
 *
 *  window_comp [label="Window\nLogic", shape=rectangle style=filled fillcolor=lightgray];
 *
 *  edge [dir="forward"];
 *
 *  pos_src1_1:e -> mux_pos1:w;
 *  mux_pos1:e -> ac1:nw [label="+"];
 *  neg_src1_1:e -> mux_neg1:nw;
 *  neg_src1_2:e -> mux_neg1:w;
 *  neg_src1_3:e -> mux_neg1:sw;
 *  mux_neg1:e -> ac1:sw [label="-"];
 *  ac1:e -> res_out1 [label="Comparator 1 Result"];
 *
 *  pos_src2_1:e -> mux_pos2:w;
 *  mux_pos2:e -> ac2:sw [label="+"];
 *  neg_src2_1:e -> mux_neg2:nw;
 *  neg_src2_2:e -> mux_neg2:w;
 *  neg_src2_3:e -> mux_neg2:sw;
 *  mux_neg2:e -> ac2:nw [label="-"];
 *  ac2:e -> res_out2 [label="Comparator 2 Result"];
 *
 *  ac1:e -> window_comp:nw;
 *  ac2:e -> window_comp:sw;
 *  window_comp:e -> res_window:w [label="Window Result"];
 *
 *  {rank=same; pos_src1_1 neg_src1_1 neg_src1_2 neg_src1_3 pos_src2_1 neg_src2_1 neg_src2_2 neg_src2_3 }
 *  {rank=same; mux_pos1 mux_neg1 mux_pos2 mux_neg2 }
 *  {rank=same; ac1 ac2 }
 *  {rank=same; res_out1 res_out2 res_window }
 * }
 * \enddot
 *
 *
 * \section asfdoc_samd20_ac_special_considerations Special Considerations
 *
 * The number of comparator pairs (and, thus, window comparators) within a
 * single hardware instance of the Analog Comparator module is device-specific.
 * Some devices will contain a single comparator pair, while others may have two
 * pairs; refer to your device specific datasheet for details.
 *
 *
 * \section asfdoc_samd20_ac_extra_info Extra Information for AC
 *
 * For extra information see \ref asfdoc_samd20_ac_extra. This includes:
 *  - \ref asfdoc_samd20_ac_extra_acronyms
 *  - \ref asfdoc_samd20_ac_extra_dependencies
 *  - \ref asfdoc_samd20_ac_extra_errata
 *  - \ref asfdoc_samd20_ac_extra_history
 *
 *
 * \section asfdoc_samd20_ac_examples Examples
 *
 * The following Quick Start guides and application examples are available for this driver:
 * - \ref asfdoc_samd20_ac_basic_use_case
 *
 *
 * \section asfdoc_samd20_ac_api_overview API Overview
 * @{
 */

#include <compiler.h>
#include <string.h>
#include <clock.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief AC comparator channel selection enum.
 *
 * Enum for the possible comparator channels.
 */
enum ac_chan_channel {
	/** Comparator channel 0 (Pair 0, Comparator 0) */
	AC_CHAN_CHANNEL_0 = 0,
	/** Comparator channel 1 (Pair 0, Comparator 1) */
	AC_CHAN_CHANNEL_1 = 1,
#if defined(__DOXYGEN__) || (AC_NUM_CMP > 2)
	/** Comparator channel 2 (Pair 1, Comparator 0) */
	AC_CHAN_CHANNEL_2 = 2,
	/** Comparator channel 3 (Pair 1, Comparator 1) */
	AC_CHAN_CHANNEL_3 = 3,
#endif
};

/**
 * \brief AC channel input sampling mode configuration enum.
 *
 * Enum for the possible channel sampling modes of an Analog Comparator channel.
 */
enum ac_chan_sample_mode {
	/** Continuous sampling mode; when the channel is enabled the comparator
	 *  output is available for reading at any time. */
	AC_CHAN_MODE_CONTINUOUS    = 0,
	/** Single shot mode; when used the comparator channel must be triggered to
	 *  perform a comparison before reading the result. */
	AC_CHAN_MODE_SINGLE_SHOT   = AC_COMPCTRL_SINGLE,
};

/**
 * \brief AC channel positive comparator pin input configuration enum.
 *
 * Enum for the possible channel positive pin input of an Analog Comparator
 * channel.
 */
enum ac_chan_pos_mux {
	/** Positive comparator input is connected to physical AC input pin 0. */
	AC_CHAN_POS_MUX_PIN0       = AC_COMPCTRL_MUXPOS_PIN0,
	/** Positive comparator input is connected to physical AC input pin 1. */
	AC_CHAN_POS_MUX_PIN1       = AC_COMPCTRL_MUXPOS_PIN1,
	/** Positive comparator input is connected to physical AC input pin 2. */
	AC_CHAN_POS_MUX_PIN2       = AC_COMPCTRL_MUXPOS_PIN2,
	/** Positive comparator input is connected to physical AC input pin 3. */
	AC_CHAN_POS_MUX_PIN3       = AC_COMPCTRL_MUXPOS_PIN3,
};

/**
 * \brief AC channel negative comparator pin input configuration enum.
 *
 * Enum for the possible channel negative pin input of an Analog Comparator
 * channel.
 */
enum ac_chan_neg_mux {
	/** Negative comparator input is connected to physical AC input pin 0. */
	AC_CHAN_NEG_MUX_PIN0       = AC_COMPCTRL_MUXNEG_PIN0,
	/** Negative comparator input is connected to physical AC input pin 1. */
	AC_CHAN_NEG_MUX_PIN1       = AC_COMPCTRL_MUXNEG_PIN1,
	/** Negative comparator input is connected to physical AC input pin 2. */
	AC_CHAN_NEG_MUX_PIN2       = AC_COMPCTRL_MUXNEG_PIN2,
	/** Negative comparator input is connected to physical AC input pin 3. */
	AC_CHAN_NEG_MUX_PIN3       = AC_COMPCTRL_MUXNEG_PIN3,
	/** Negative comparator input is connected to the internal ground plane. */
	AC_CHAN_NEG_MUX_GND        = AC_COMPCTRL_MUXNEG_GND,
	/** Negative comparator input is connected to the channel's internal VCC
	 *  plane voltage scalar. */
	AC_CHAN_NEG_MUX_SCALED_VCC = AC_COMPCTRL_MUXNEG_VSCALE,
	/** Negative comparator input is connected to the internal band gap voltage
	 *  reference. */
	AC_CHAN_NEG_MUX_BANDGAP    = AC_COMPCTRL_MUXNEG_BANDGAP,
	/** Negative comparator input is connected to the channel's internal DAC
	 *  channel 0 output. */
	AC_CHAN_NEG_MUX_DAC0       = AC_COMPCTRL_MUXNEG_DAC,
};

/**
 * \brief AC channel output filtering configuration enum.
 *
 * Enum for the possible channel output filtering configurations of an Analog
 * Comparator channel.
 */
enum ac_chan_filter {
	/** No output filtering is performed on the comparator channel. */
	AC_CHAN_FILTER_NONE        = AC_COMPCTRL_FLEN_OFF,
	/** Comparator channel output is passed through a Majority-of-Three
	 *  filter. */
	AC_CHAN_FILTER_MAJORITY_3  = AC_COMPCTRL_FLEN_MAJ3,
	/** Comparator channel output is passed through a Majority-of-Five
	 *  filter. */
	AC_CHAN_FILTER_MAJORITY_5  = AC_COMPCTRL_FLEN_MAJ5,
};

/**
 * \brief AC channel GPIO output routing configuration enum.
 *
 * Enum for the possible channel GPIO output routing configurations of an Analog
 * Comparator channel.
 */
enum ac_chan_output {
	/** Comparator channel output is not routed to a physical GPIO pin, and is
	 *  used internally only. */
	AC_CHAN_OUTPUT_INTERNAL    = AC_COMPCTRL_OUT_OFF,
	/** Comparator channel output is routed to it's matching physical GPIO pin,
	 *  via an asynchronous path. */
	AC_CHAN_OUTPUT_ASYNCRONOUS = AC_COMPCTRL_OUT_ASYNC,
	/** Comparator channel output is routed to it's matching physical GPIO pin,
	 *  via a synchronous path. */
	AC_CHAN_OUTPUT_SYNCHRONOUS = AC_COMPCTRL_OUT_SYNC,
};

/**
 * \brief AC channel output state enum.
 *
 * Enum for the possible output states of an Analog Comparator channel.
 */
enum ac_chan_state {
	/** Unknown output state; the comparator channel was not ready. */
	AC_CHAN_STATE_UNKNOWN,
	/** Comparator's negative input pin is higher in voltage than the positive
	 *  input pin. */
	AC_CHAN_STATE_NEG_ABOVE_POS,
	/** Comparator's positive input pin is higher in voltage than the negative
	 *  input pin. */
	AC_CHAN_STATE_POS_ABOVE_NEG,
};

/**
 * \brief AC window channel selection enum.
 *
 * Enum for the possible window comparator channels.
 */
enum ac_win_channel {
	/** Window channel 0 (Pair 0, Comparators 0 and 1) */
	AC_WIN_CHANNEL_0 = 0,
#if defined(__DOXYGEN__) || (AC_PAIRS > 1)
	/** Window channel 1 (Pair 1, Comparators 2 and 3) */
	AC_WIN_CHANNEL_1 = 1,
#endif
};

/**
 * \brief AC window channel detection mode configuration enum.
 *
 * Enum for the possible detection modes of an Analog Comparator window channel.
 */
enum ac_win_detect {
	/** Window Comparator should detect an input above the upper threshold. */
	AC_WIN_DETECT_ABOVE,
	/** Window Comparator should detect an input between the lower and upper
	 *  thresholds. */
	AC_WIN_DETECT_INSIDE,
	/** Window Comparator should detect an input below the lower threshold. */
	AC_WIN_DETECT_BELOW,
	/** Window Comparator should detect an input above the upper threshold or
	 *  below the lower threshold. */
	AC_WIN_DETECT_OUTSIDE,
};

/**
 * \brief AC window channel output state enum.
 *
 * Enum for the possible output states of an Analog Comparator window channel.
 */
enum ac_win_state {
	/** Unknown output state; the comparator window channel was not ready. */
	AC_WIN_STATE_UNKNOWN,
	/** Window Comparator's input voltage is above the upper window
	 *  threshold. */
	AC_WIN_STATE_ABOVE,
	/** Window Comparator's input voltage is between the lower and upper window
	 *  thresholds. */
	AC_WIN_STATE_INSIDE,
	/** Window Comparator's input voltage is below the lower window
	 *  threshold. */
	AC_WIN_STATE_BELOW,
};

/**
 * \brief AC software device instance structure.
 *
 * AC software instance structure, used to retain software state information
 * of an associated hardware module instance.
 *
 * \note The fields of this structure should not be altered by the user
 *       application; they are reserved for module-internal use only.
 */
struct ac_module {
#if !defined(__DOXYGEN__)
	/** Hardware module pointer of the associated Analog Comparator peripheral. */
	Ac *hw;
#endif
};

/**
 * \brief AC event enable/disable structure.
 *
 * Event flags for the Analog Comparator module. This is used to enable and
 * disable events via \ref ac_enable_events() and \ref ac_disable_events().
 */
struct ac_events {
	/** If \c true, an event will be generated when a comparator window state
	 *  changes. */
	bool generate_event_on_window[AC_PAIRS];

	/** If \c true, an event will be generated when a comparator state
	 *  changes. */
	bool generate_event_on_state[AC_NUM_CMP];

	/** If \c true, a comparator will be sampled each time an event is
	 *  received. */
	bool on_event_sample[AC_NUM_CMP];
};

/**
 * \brief Analog Comparator module configuration structure.
 *
 *  Configuration structure for a Comparator channel, to configure the input and
 *  output settings of the comparator.
 */
struct ac_config {
	/** If \c true, the comparator pairs will continue to sample during sleep
	 *  mode when triggered. */
	bool run_in_standby[AC_PAIRS];

	/** Event generation and reception configuration for the AC module; event
	 *  flags set to true are enabled when the module is configured. */
	struct ac_events events;

	/** Source generator for AC GCLK. */
	enum gclk_generator source_generator;
};

/**
 * \brief Analog Comparator module Comparator configuration structure.
 *
 *  Configuration structure for a Comparator channel, to configure the input and
 *  output settings of the comparator.
 */
struct ac_chan_config {
	/** Sampling mode of the comparator channel. */
	enum ac_chan_sample_mode sample_mode;
	/** Filtering mode for the comparator output, when the comparator is used
	 *  in a supported mode. */
	enum ac_chan_filter filter;
	/** When \c true, hysteresis mode is enabled on the comparator inputs. */
	bool enable_hysteresis;
	/** Output mode of the comparator, whether it should be available for
	 *  internal use, or asynchronously/synchronously linked to a GPIO pin. */
	enum ac_chan_output output_mode;
	/** Input multiplexer selection for the comparator's positive input pin. */
	enum ac_chan_pos_mux positive_input;
	/** Input multiplexer selection for the comparator's negative input pin. */
	enum ac_chan_neg_mux negative_input;
	/** Scaled \f$\frac{V_{CC}\times\mbox{n}}{64}\f$ VCC voltage division factor
	 *  for the channel, when a comparator pin is connected to the VCC voltage
	 *  scalar input. If the VCC voltage scalar is not selected as a comparator
	 *  channel pin's input, this value will be ignored. */
	uint8_t vcc_scale_factor;
};

/**
 * \brief Analog Comparator module Window Comparator configuration structure.
 *
 *  Configuration structure for a Window Comparator channel, to configure the
 *  detection characteristics of the window.
 */
struct ac_win_config {
	/** Window detection criteria that should be used to determine the state
	 *  of the window detection flag. */
	enum ac_win_detect window_detection;
};

/**
 * \name Configuration and Initialization
 * @{
 */

enum status_code ac_reset(
		struct ac_module *const module_inst);

enum status_code ac_init(
		struct ac_module *const module_inst,
		Ac *const hw,
		struct ac_config *const config);

/**
 * \brief Determines if the hardware module(s) are currently synchronizing to the bus.
 *
 * Checks to see if the underlying hardware peripheral module(s) are currently
 * synchronizing across multiple clock domains to the hardware bus, This
 * function can be used to delay further operations on a module until such time
 * that it is ready, to prevent blocking delays for synchronization in the
 * user application.
 *
 * \param[in] module_inst  Pointer to the AC software instance struct
 *
 * \return Synchronization status of the underlying hardware module(s).
 *
 * \retval true if the module has completed synchronization
 * \retval false if the module synchronization is ongoing
 */
static inline bool ac_is_syncing(
        struct ac_module *const module_inst)
{
        /* Sanity check arguments */
        Assert(module_inst);

        Ac *const ac_module = module_inst->hw;

        if (ac_module->STATUSB.reg & AC_STATUSB_SYNCBUSY) {
                return true;
        }

        return false;
}

/**
 * \brief Initializes an Analog Comparator configuration structure to defaults.
 *
 *  Initializes a given Analog Comparator configuration structure to a set of
 *  known default values. This function should be called on all new instances
 *  of these configuration structures before being modified by the user
 *  application.
 *
 *  The default configuration is as follows:
 *   \li All comparator pairs disabled during sleep mode
 *   \li No events enabled by default
 *   \li Generator 0 is the default GCLK generator
 *
 *  \param[out] config  Configuration structure to initialize to default values
 */
static inline void ac_get_config_defaults(
		struct ac_config *const config)
{
	/* Sanity check arguments */
	Assert(config);

	/* Default configuration values */
	for (uint32_t i = 0; i < AC_PAIRS; i++) {
		config->run_in_standby[i] = false;
	}
	config->run_in_standby[0] = false;
	memset(&config->events, 0x00, sizeof(config->events));
	config->source_generator = GCLK_GENERATOR_0;
}

/**
 * \brief Enables an Analog Comparator that was previously configured.
 *
 * Enables and starts an Analog Comparator that was previously configured via a
 * call to \ref ac_init().
 *
 * \param[in] module_inst  Software instance for the Analog Comparator peripheral
 */
static inline void ac_enable(
		struct ac_module *const module_inst)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);

	Ac *const ac_module = module_inst->hw;

	while (ac_is_syncing(module_inst)) {
		/* Wait until synchronization is complete */
	}

	/* Write the new comparator module control configuration */
	ac_module->CTRLA.reg |= AC_CTRLA_ENABLE;
}

/**
 * \brief Disables an Analog Comparator that was previously enabled.
 *
 * Stops an Analog Comparator that was previously started via a call to
 * \ref ac_enable().
 *
 * \param[in] module_inst  Software instance for the Analog Comparator peripheral
 */
static inline void ac_disable(
		struct ac_module *const module_inst)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);

	Ac *const ac_module = module_inst->hw;

	while (ac_is_syncing(module_inst)) {
		/* Wait until synchronization is complete */
	}

	/* Write the new comparator module control configuration */
	ac_module->CTRLA.reg &= ~AC_CTRLA_ENABLE;
}

/**
 * \brief Enables an Analog Comparator event input or output.
 *
 *  Enables one or more input or output events to or from the Analog Comparator
 *  module. See \ref ac_events "here" for a list of events this module
 *  supports.
 *
 *  \note Events cannot be altered while the module is enabled.
 *
 *  \param[in] module_inst  Software instance for the Analog Comparator peripheral
 *  \param[in] events       Struct containing flags of events to enable
 */
static inline void ac_enable_events(
		struct ac_module *const module_inst,
		struct ac_events *const events)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);
	Assert(events);

	Ac *const ac_module = module_inst->hw;

	uint32_t event_mask = 0;

	/* Configure window output events for each comparator pair */
	for (uint8_t i = 0; i < AC_PAIRS; i++) {
		if (events->generate_event_on_window[i] == true) {
			event_mask |= (AC_EVCTRL_WINEO0 << i);
		}
	}

	/* Configure sample input/output events for each comparator */
	for (uint8_t i = 0; i < AC_NUM_CMP; i++) {
		if (events->on_event_sample[i] == true) {
			event_mask |= (AC_EVCTRL_COMPEI0 << i);
		}

		if (events->generate_event_on_state[i] == true) {
			event_mask |= (AC_EVCTRL_COMPEO0 << i);
		}
	}

	ac_module->EVCTRL.reg |= event_mask;
}

/**
 * \brief Disables an Analog Comparator event input or output.
 *
 *  Disables one or more input or output events to or from the Analog Comparator
 *  module. See \ref ac_events "here" for a list of events this module
 *  supports.
 *
 *  \note Events cannot be altered while the module is enabled.
 *
 *  \param[in] module_inst  Software instance for the Analog Comparator peripheral
 *  \param[in] events       Struct containing flags of events to disable
 */
static inline void ac_disable_events(
		struct ac_module *const module_inst,
		struct ac_events *const events)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);
	Assert(events);

	Ac *const ac_module = module_inst->hw;

	uint32_t event_mask = 0;

	/* Configure window output events for each comparator pair */
	for (uint8_t i = 0; i < AC_PAIRS; i++) {
		if (events->generate_event_on_window[i] == true) {
			event_mask |= (AC_EVCTRL_WINEO0 << i);
		}
	}

	/* Configure sample input/output events for each comparator */
	for (uint8_t i = 0; i < AC_NUM_CMP; i++) {
		if (events->on_event_sample[i] == true) {
			event_mask |= (AC_EVCTRL_COMPEI0 << i);
		}

		if (events->generate_event_on_state[i] == true) {
			event_mask |= (AC_EVCTRL_COMPEO0 << i);
		}
	}

	ac_module->EVCTRL.reg &= ~event_mask;
}

/** @} */


/**
 * \name Channel Configuration and Initialization
 * @{
 */

/**
 * \brief Initializes an Analog Comparator channel configuration structure to defaults.
 *
 *  Initializes a given Analog Comparator channel configuration structure to a
 *  set of known default values. This function should be called on all new
 *  instances of these configuration structures before being modified by the
 *  user application.
 *
 *  The default configuration is as follows:
 *   \li Continuous sampling mode
 *   \li Majority of 5 sample output filter
 *   \li Hysteresis enabled on the input pins
 *   \li Internal comparator output mode
 *   \li Comparator pin multiplexer 0 selected as the positive input
 *   \li Scaled VCC voltage selected as the negative input
 *   \li VCC voltage scaler set for a division factor of 2 (\f$\frac{V_{CC}\times32}{64}\f$)
 *
 *   \param[out] config  Channel configuration structure to initialize to
 *                       default values
 */
static inline void ac_chan_get_config_defaults(
		struct ac_chan_config *const config)
{
	/* Sanity check arguments */
	Assert(config);

	/* Default configuration values */
	config->sample_mode       = AC_CHAN_MODE_CONTINUOUS;
	config->filter            = AC_CHAN_FILTER_MAJORITY_5;
	config->enable_hysteresis = true;
	config->output_mode       = AC_CHAN_OUTPUT_INTERNAL;
	config->positive_input    = AC_CHAN_POS_MUX_PIN0;
	config->negative_input    = AC_CHAN_NEG_MUX_SCALED_VCC;
	config->vcc_scale_factor  = 32;
}

enum status_code ac_chan_set_config(
		struct ac_module *const module_inst,
		const enum ac_chan_channel channel,
		struct ac_chan_config *const config);

/**
 * \brief Enables an Analog Comparator channel that was previously configured.
 *
 *  Enables and starts an Analog Comparator channel that was previously
 *  configured via a call to \ref ac_chan_set_config().
 *
 *  \param[in] module_inst  Software instance for the Analog Comparator peripheral
 *  \param[in] channel      Comparator channel to enable
 */
static inline void ac_chan_enable(
		struct ac_module *const module_inst,
		const enum ac_chan_channel channel)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);

	Ac *const ac_module = module_inst->hw;

	/* Write the new comparator module control configuration */
	ac_module->COMPCTRL[(uint8_t)channel].reg |= AC_COMPCTRL_ENABLE;
}

/**
 * \brief Disables an Analog Comparator channel that was previously enabled.
 *
 *  Stops an Analog Comparator channel that was previously started via a call to
 *  \ref ac_chan_enable().
 *
 *  \param[in] module_inst  Software instance for the Analog Comparator peripheral
 *  \param[in] channel      Comparator channel channel to disable
 */
static inline void ac_chan_disable(
		struct ac_module *const module_inst,
		const enum ac_chan_channel channel)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);

	Ac *const ac_module = module_inst->hw;

	/* Write the new comparator module control configuration */
	ac_module->COMPCTRL[(uint8_t)channel].reg &= ~AC_COMPCTRL_ENABLE;
}

/** @} */


/**
 * \name Channel Control
 * @{
 */

/**
 * \brief Triggers a comparison on a comparator that is configured in single shot mode.
 *
 *  Triggers a single conversion on a comparator configured to compare on demand
 *  (single shot mode) rather than continuously.
 *
 *  \param[in] module_inst  Software instance for the Analog Comparator peripheral
 *  \param[in] channel      Comparator channel channel to trigger
 */
static inline void ac_chan_trigger_single_shot(
		struct ac_module *const module_inst,
		const enum ac_chan_channel channel)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);

	Ac *const ac_module = module_inst->hw;

	/* Write the new comparator module control configuration */
	ac_module->CTRLB.reg |= (AC_CTRLB_START0 << (uint8_t)channel);
}

/**
 * \brief Determines if a given comparator channel is ready for comparisons.
 *
 *  Checks a comparator channel to see if the comparator is currently ready to
 *  begin comparisons.
 *
 *  \param[in] module_inst  Software instance for the Analog Comparator peripheral
 *  \param[in] channel      Comparator channel channel to test
 *
 *  \return Comparator channel readiness state.
 */
static inline bool ac_chan_is_ready(
		struct ac_module *const module_inst,
		const enum ac_chan_channel channel)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);

	Ac *const ac_module = module_inst->hw;

	return (ac_module->STATUSB.reg & (AC_STATUSB_READY0 << (uint8_t)channel));
}

/**
 * \brief Determines the output state of a comparator channel.
 *
 *  Retrieves the last comparison value (after filtering) of a given comparator.
 *  If the comparator was not ready at the time of the check, the comparison
 *  result will be indicated as being unknown.
 *
 *  \param[in] module_inst   Software instance for the Analog Comparator peripheral
 *  \param[in] channel       Comparator channel channel to test
 *
 *  \return Comparator channel state.
 */
static inline enum ac_chan_state ac_chan_get_state(
		struct ac_module *const module_inst,
		const enum ac_chan_channel channel)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);

	Ac *const ac_module = module_inst->hw;

	if (ac_chan_is_ready(module_inst, channel) == false) {
		return AC_CHAN_STATE_UNKNOWN;
	}

	if (ac_module->STATUSA.reg & (AC_STATUSA_STATE0 << (uint8_t)channel)) {
		return AC_CHAN_STATE_POS_ABOVE_NEG;
	} else {
		return AC_CHAN_STATE_NEG_ABOVE_POS;
	}
}

/** @} */


/**
 * \name Window Mode Configuration and Initialization
 * @{
 */

/**
 * \brief Initializes an Analog Comparator window channel configuration structure to defaults.
 *
 *  Initializes a given Analog Comparator window channel configuration structure
 *  to a set of known default values. This function should be called on all new
 *  instances of these configuration structures before being modified by the
 *  user application.
 *
 *  The default configuration is as follows:
 *   \li Detect when the signal is inside the comparator pair window
 *
 *  \param[out] config  Window channel configuration structure to initialize to
 *                      default values
 */
static inline void ac_win_get_config_defaults(
		struct ac_win_config *const config)
{
	/* Sanity check arguments */
	Assert(config);

	/* Default configuration values */
	config->window_detection = AC_WIN_DETECT_INSIDE;
}

enum status_code ac_win_set_config(
		struct ac_module *const module_inst,
		const enum ac_win_channel win_channel,
		struct ac_win_config *const config);

enum status_code ac_win_enable(
		struct ac_module *const module_inst,
		const enum ac_win_channel win_channel);

void ac_win_disable(
		struct ac_module *const module_inst,
		const enum ac_win_channel win_channel);

/** @} */


/**
 * \name Window Mode Control
 * @{
 */

/**
 * \brief Determines if a given Window Comparator is ready for comparisons.
 *
 *  Checks a Window Comparator to see if the both comparators used for window
 *  detection is currently ready to begin comparisons.
 *
 *  \param[in] module_inst  Software instance for the Analog Comparator peripheral
 *  \param[in] win_channel  Window Comparator channel channel to test
 *
 *  \return Window Comparator channel readiness state.
 */
static inline bool ac_win_is_ready(
		struct ac_module *const module_inst,
		const enum ac_win_channel win_channel)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);

	/* Convert a window channel index to the individual comparator channels */
	enum ac_chan_channel win_pair_comp0 =
			(enum ac_chan_channel)((uint8_t)win_channel * 2);
	enum ac_chan_channel win_pair_comp1 =
			(enum ac_chan_channel)(((uint8_t)win_channel * 2) + 1);

	/* Check if the two comparators used in the window are ready */
	bool win_pair_comp0_ready = ac_chan_is_ready(module_inst, win_pair_comp0);
	bool win_pair_comp1_ready = ac_chan_is_ready(module_inst, win_pair_comp1);

	/* If one or both window comparators not ready, return failure */
	if ((win_pair_comp0_ready == false) || (win_pair_comp1_ready == false)) {
		return false;
	}

	return true;
}

enum ac_win_state ac_win_get_state(
		struct ac_module *const module_inst,
		const enum ac_win_channel channel);

/**
 * \brief Determines if a Window Comparator has detected the configured window criteria.
 *
 *  Tests if a Windows Comparator has detected that the input signal relative
 *  to the window bounds matches the detection criteria previously configured
 *  for the Window Comparator.
 *
 *  \param[in] module_inst  Software instance for the Analog Comparator peripheral
 *  \param[in] win_channel  Comparator Window channel to test
 *
 *  \return State of the Window Comparator criteria detection flag.
 */
static inline bool ac_win_is_detected(
		struct ac_module *const module_inst,
		const enum ac_win_channel win_channel)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);

	Ac *const ac_module = module_inst->hw;

	return (ac_module->INTFLAG.reg & (AC_INTFLAG_WIN0 << (uint8_t)win_channel));
}

/**
 * \brief Clears a Comparator Window condition criteria detection flag.
 *
 *  Clears the Analog Comparator window condition detection flag for a specified
 *  comparator channel.
 *
 *  \param[in] module_inst  Software instance for the Analog Comparator peripheral
 *  \param[in] win_channel  Comparator Window channel to modify
 */
static inline void ac_win_clear_detected(
		struct ac_module *const module_inst,
		const enum ac_win_channel win_channel)
{
	/* Sanity check arguments */
	Assert(module_inst);
	Assert(module_inst->hw);

	Ac *const ac_module = module_inst->hw;

	ac_module->INTFLAG.reg = (AC_INTFLAG_WIN0 << (uint8_t)win_channel);
}

/** @} */

#ifdef __cplusplus
}
#endif

/** @} */


/**
 * \page asfdoc_samd20_ac_extra Extra Information for AC Driver
 *
 * \section asfdoc_samd20_ac_extra_acronyms Acronyms
 * Below is a table listing the acronyms used in this module, along with their
 * intended meanings.
 *
 * <table>
 *	<tr>
 *		<th>Acronym</th>
 *		<th>Description</th>
 *	</tr>
 *	<tr>
 *		<td>AC</td>
 *		<td>Analog Comparator</td>
 *	</tr>
 *	<tr>
 *		<td>DAC</td>
 *		<td>Digital-to-Analog Converter</td>
 *	</tr>
 *	<tr>
 *		<td>MUX</td>
 *		<td>Multiplexer</td>
 *	</tr>
 * </table>
 *
 *
 * \section asfdoc_samd20_ac_extra_dependencies Dependencies
 * This driver has the following dependencies:
 *
 *  - \ref asfdoc_samd20_system_pinmux_group "System Pin Multiplexer Driver"
 *
 *
 * \section asfdoc_samd20_ac_extra_errata Errata
 * There are no errata related to this driver.
 *
 *
 * \section asfdoc_samd20_ac_extra_history Module History
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
 * \page asfdoc_samd20_ac_exqsg Examples for AC Driver
 *
 * This is a list of the available Quick Start guides (QSGs) and example
 * applications for \ref asfdoc_samd20_ac_group. QSGs are simple examples with
 * step-by-step instructions to configure and use this driver in a selection of
 * use cases. Note that QSGs can be compiled as a standalone application or be
 * added to the user application.
 *
 *  - \subpage asfdoc_samd20_ac_basic_use_case
 */

#endif
