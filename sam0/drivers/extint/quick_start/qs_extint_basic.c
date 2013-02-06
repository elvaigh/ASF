/**
 * \file
 *
 * \brief SAMD20 External Interrupt Driver Quick Start
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
#include <asf.h>

void config_extint_channel(void);

//! [setup]
void config_extint_channel(void)
{
//! [setup_1]
	struct extint_chan_conf eint_chan_conf;
//! [setup_1]
//! [setup_2]
	extint_chan_get_config_defaults(&eint_chan_conf);
//! [setup_2]

//! [setup_3]
	eint_chan_conf.gpio_pin            = PIN_PA01A_EIC_EXTINT1;
	eint_chan_conf.gpio_pin_mux        = MUX_PA01A_EIC_EXTINT1;
	eint_chan_conf.wake_if_sleeping    = true;
	eint_chan_conf.filter_input_signal = false;
	eint_chan_conf.detection_criteria  = EXTINT_DETECT_FALLING;
//! [setup_3]
//! [setup_4]
	extint_chan_set_config(1, &eint_chan_conf);
//! [setup_4]
}
//! [setup]

int main(void)
{
	//! [setup_init]
	extint_enable();
	config_extint_channel();
	//! [setup_init]

	//! [main]
	while (true) {
		//! [main_1]
		if (extint_chan_is_detected(1)) {
		//! [main_1]
			// Do something in response to EXTINT 1 detection
		//! [main_2]
			extint_chan_clear_detected(1);
		//! [main_2]
		}
	}
	//! [main]
}
