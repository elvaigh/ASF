/**
 * \file
 *
 * \brief SAM B11 I2C Master Quick Start Guide
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
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

#include <asf.h>

//! [packet_data]
#define DATA_LENGTH 10
static uint8_t write_buffer[DATA_LENGTH] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
};

static uint8_t read_buffer[DATA_LENGTH];
//! [packet_data]

//! [address]
#define SLAVE_ADDRESS 0x12
//! [address]

/* Number of times to try to send packet if failed. */
//! [timeout]
#define TIMEOUT 1000
//! [timeout]

/* Init software module. */
//! [dev_inst]
struct i2c_slave_module i2c_slave_instance;
//! [dev_inst]

//! [initialize_i2c]
static void configure_i2c_slave(void)
{
	/* Initialize config structure and software module. */
	//! [init_conf]
	struct i2c_slave_config config_i2c_slave;
	i2c_slave_get_config_defaults(&config_i2c_slave);
	//! [init_conf]

	/* Initialize and enable device with config, and enable i2c. */
	//! [init_module]
	i2c_slave_init(&i2c_slave_instance, &config_i2c_slave);
	//! [init_module]
}
//! [initialize_i2c]

int main(void)
{
	enum i2c_slave_direction dir = 0;
	
	//! [init]
	system_clock_config(CLOCK_RESOURCE_RC_26_MHZ, CLOCK_FREQ_26_MHZ);
	
	configure_i2c_slave();

	//! [packet]
	struct i2c_slave_packet packet = {
		.data_length = DATA_LENGTH,
		.data        = write_buffer,
	};
	//! [packet]
	//! [init]
	
	//! [while]
	while (true) {
		//! [get_dir]
		dir = i2c_slave_get_direction_wait(&i2c_slave_instance);
		//! [get_dir]
		if (dir == I2C_SLAVE_DIRECTION_READ) {
			packet.data = read_buffer;
			i2c_slave_read_packet_wait(&i2c_slave_instance, &packet);
		} else if (dir == I2C_SLAVE_DIRECTION_WRITE) {
			packet.data = write_buffer;
			i2c_slave_write_packet_wait(&i2c_slave_instance, &packet);
		}
	}
	//! [while]
}
