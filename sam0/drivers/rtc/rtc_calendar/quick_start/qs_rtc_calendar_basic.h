/**
 * \file
 *
 * \brief SAMD20 PAC Quick Start
 *
 * Copyright (C) 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
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
 * \page rtc_cal_basic_use_case Quick Start Guide for the RTC calendar - Basic
 * In this use case, the RTC is set up in calendar mode. The time is set and
 * also a alarm is set to show a general use of the RTC in calendar mode. Also
 * the clock is swapped from 24h to 12h mode after initialization.
 *
 * \section rtc_cal_basic_use_case_prereq Prerequisites
 * The clocks need be be set up correctly in the clock domain, and the drivers
 * also needs to be included in the project.
 *
 * \section rtc_cal_basic_setup Setup
 * Set up the RTC as intended.
 *
 * \subsection rtc_cal_init_code Initialization Code
 * Copy-paste the following setup code to your application:
 * \snippet qs_rtc_calendar_basic.c initiate
 *
 * \subsection rtc_cal_main_code Add to Main
 * Add the following to your main().
 * \snippet qs_rtc_calendar_basic.c add_main
 *
 * \subsection rtc_cal_basic_use_workflow Workflow
 * -# Make configuration structure.
 *  - \snippet qs_rtc_calendar_basic.c set_conf
 * -# Set default in configuration structure.
 *  - \snippet qs_rtc_calendar_basic.c get_default
 * -# Make time structure for alarm and set with default and desired values.
 *  - \snippet qs_rtc_calendar_basic.c time_struct
 * -# Change configurations as desired.
 *  - \snippet qs_rtc_calendar_basic.c set_config
 * -# Initialize module.
 *  - \snippet qs_rtc_calendar_basic.c init_rtc
 * -# Enable module
 *  - \snippet qs_rtc_calendar_basic.c enable
 *
 * \section rtc_count_basic_implement Implementation
 * There is no implementation for this quick start.
 */