/**
 * \file
 *
 * \brief SAM D20 SPI Quick Start
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

void configure_spi(void);

//! [setup]
//! [buf_length]
#define BUF_LENGTH 20
//! [buf_length]

//! [buffer]
static const uint8_t buffer[20] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
		 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13
};
//! [buffer]

//! [dev_inst]
struct spi_module slave;
//! [dev_inst]
//! [setup]

//! [configure_spi]
void configure_spi(void)
{
//! [config]
	struct spi_config config;
//! [config]
	/* Configure, initialize and enable SERCOM SPI module */
//! [conf_defaults]
	spi_get_config_defaults(&config);
//! [conf_defaults]
//! [conf_slave]
	config.mode = SPI_MODE_SLAVE;
//! [conf_slave]
//! [conf_preload]
	config.slave.preload_enable = true;
//! [conf_preload]
//! [conf_format]
	config.slave.frame_format = SPI_FRAME_FORMAT_SPI_FRAME;
//! [conf_format]
//! [mux_setting]
	config.mux_setting = SPI_SIGNAL_MUX_SETTING_E;
//! [mux_setting]
	/* Configure pad 0 for data in */
//! [di]
	config.pinmux_pad0 = EXT1_SPI_MISO_PINMUX;
//! [di]
	/* Configure pad 1 as unused */
//! [ss]
	config.pinmux_pad1 = EXT1_SPI_SS_PINMUX;
//! [ss]
	/* Configure pad 2 for data out */
//! [do]
	config.pinmux_pad2 = EXT1_SPI_MOSI_PINMUX;
//! [do]
	/* Configure pad 3 for SCK */
//! [sck]
	config.pinmux_pad3 = EXT1_SPI_SCK_PINMUX;
//! [sck]
//! [init]
	spi_init(&slave, EXT1_SPI_MODULE, &config);
//! [init]

//! [enable]
	spi_enable(&slave);
//! [enable]

}
//! [configure_spi]

int main(void)
{
//! [main_start]
	/* Initialize system */
//! [system_init]
	system_init();
//! [system_init]

//! [run_config]
	configure_spi();
//! [run_config]
//! [main_start]

//! [main_use_case]
//! [write]
	while (spi_write_buffer_wait(&slave, buffer, BUF_LENGTH != STATUS_OK) {
		/* Wait for transfer from master */
	}
//! [write]


//! [inf_loop]
	while (true) {
		/* Infinite loop */
	}
//! [inf_loop]
//! [main_use_case]
}
