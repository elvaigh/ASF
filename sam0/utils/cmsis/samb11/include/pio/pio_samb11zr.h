/**
 * \file
 *
 * \brief Peripheral I/O description for SAMB11ZR
 *
 * Copyright (c) 2016 Atmel Corporation. All rights reserved.
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

#ifndef _SAMB11ZR_PIO_
#define _SAMB11ZR_PIO_

#define GPIO_LP_GPIO_0           (1u << 0)  /**< \brief Pin Controlled by LP_GPIO_0 */
#define GPIO_LP_GPIO_0_IDX               0 
#define GPIO_LP_GPIO_1           (1u << 1)  /**< \brief Pin Controlled by LP_GPIO_1 */
#define GPIO_LP_GPIO_1_IDX               1 
#define GPIO_LP_GPIO_2           (1u << 2)  /**< \brief Pin Controlled by LP_GPIO_2 */
#define GPIO_LP_GPIO_2_IDX               2 
#define GPIO_LP_GPIO_3           (1u << 3)  /**< \brief Pin Controlled by LP_GPIO_3 */
#define GPIO_LP_GPIO_3_IDX               3 
#define GPIO_LP_GPIO_4           (1u << 4)  /**< \brief Pin Controlled by LP_GPIO_4 */
#define GPIO_LP_GPIO_4_IDX               4 
#define GPIO_LP_GPIO_5           (1u << 5)  /**< \brief Pin Controlled by LP_GPIO_5 */
#define GPIO_LP_GPIO_5_IDX               5 
#define GPIO_LP_GPIO_6           (1u << 6)  /**< \brief Pin Controlled by LP_GPIO_6 */
#define GPIO_LP_GPIO_6_IDX               6 
#define GPIO_LP_GPIO_7           (1u << 7)  /**< \brief Pin Controlled by LP_GPIO_7 */
#define GPIO_LP_GPIO_7_IDX               7 
#define GPIO_LP_GPIO_8           (1u << 8)  /**< \brief Pin Controlled by LP_GPIO_8 */
#define GPIO_LP_GPIO_8_IDX               8 
#define GPIO_LP_GPIO_9           (1u << 9)  /**< \brief Pin Controlled by LP_GPIO_9 */
#define GPIO_LP_GPIO_9_IDX               9 
#define GPIO_LP_GPIO_10          (1u << 10) /**< \brief Pin Controlled by LP_GPIO_10 */
#define GPIO_LP_GPIO_10_IDX              10
#define GPIO_LP_GPIO_11          (1u << 11) /**< \brief Pin Controlled by LP_GPIO_11 */
#define GPIO_LP_GPIO_11_IDX              11
#define GPIO_LP_GPIO_12          (1u << 12) /**< \brief Pin Controlled by LP_GPIO_12 */
#define GPIO_LP_GPIO_12_IDX              12
#define GPIO_LP_GPIO_13          (1u << 13) /**< \brief Pin Controlled by LP_GPIO_13 */
#define GPIO_LP_GPIO_13_IDX              13
#define GPIO_LP_GPIO_14          (1u << 14) /**< \brief Pin Controlled by LP_GPIO_14 */
#define GPIO_LP_GPIO_14_IDX              14
#define GPIO_LP_GPIO_15          (1u << 15) /**< \brief Pin Controlled by LP_GPIO_15 */
#define GPIO_LP_GPIO_15_IDX              15
#define GPIO_LP_GPIO_16          (1u << 0)  /**< \brief Pin Controlled by LP_GPIO_16 */
#define GPIO_LP_GPIO_16_IDX              16
#define GPIO_LP_GPIO_17          (1u << 1)  /**< \brief Pin Controlled by LP_GPIO_17 */
#define GPIO_LP_GPIO_17_IDX              17
#define GPIO_LP_GPIO_18          (1u << 2)  /**< \brief Pin Controlled by LP_GPIO_18 */
#define GPIO_LP_GPIO_18_IDX              18
#define GPIO_LP_GPIO_19          (1u << 3)  /**< \brief Pin Controlled by LP_GPIO_19 */
#define GPIO_LP_GPIO_19_IDX              19
#define GPIO_AO_GPIO_2           (1u << 13) /**< \brief Pin Controlled by AO_GPIO_2 */
#define GPIO_AO_GPIO_2_IDX               29
#define GPIO_AO_GPIO_1           (1u << 14) /**< \brief Pin Controlled by AO_GPIO_1 */
#define GPIO_AO_GPIO_1_IDX               30
#define GPIO_AO_GPIO_0           (1u << 15) /**< \brief Pin Controlled by AO_GPIO_0 */
#define GPIO_AO_GPIO_0_IDX               31
#define GPIO_GPIO_MS4            (1u << 12) /**< \brief Pin Controlled by GPIO_MS4 */
#define GPIO_GPIO_MS4_IDX                44
#define GPIO_GPIO_MS3            (1u << 13) /**< \brief Pin Controlled by GPIO_MS3 */
#define GPIO_GPIO_MS3_IDX                45
#define GPIO_GPIO_MS2            (1u << 14) /**< \brief Pin Controlled by GPIO_MS2 */
#define GPIO_GPIO_MS2_IDX                46
#define GPIO_GPIO_MS1            (1u << 15) /**< \brief Pin Controlled by GPIO_MS1 */
#define GPIO_GPIO_MS1_IDX                47

/* PinMux definitions                                               */
/* Mux values for LP_GPIO_0 */
#define MUX_LP_GPIO_0_GPIO                     0x0
#define MUX_LP_GPIO_0_MEGAMUX                  0x1
#define MUX_LP_GPIO_0_SWD_CLK                  0x2
#define MUX_LP_GPIO_0_TEST_OUT_0               0x7
/* Mux values for LP_GPIO_1 */
#define MUX_LP_GPIO_1_GPIO                     0x0
#define MUX_LP_GPIO_1_SWD_IO                   0x2
#define MUX_LP_GPIO_1_MEGAMUX                  0x1
#define MUX_LP_GPIO_1_TEST_OUT_1               0x7
/* Mux values for LP_GPIO_2 */
#define MUX_LP_GPIO_2_MEGAMUX                  0x1
#define MUX_LP_GPIO_2_SPI_FLASH0_SCK           0x6
#define MUX_LP_GPIO_2_SPI1_SCK                 0x4
#define MUX_LP_GPIO_2_TEST_OUT_2               0x7
#define MUX_LP_GPIO_2_UART0_RXD                0x2
#define MUX_LP_GPIO_2_GPIO                     0x0
#define MUX_LP_GPIO_2_SPI0_SCK                 0x5
/* Mux values for LP_GPIO_3 */
#define MUX_LP_GPIO_3_UART0_TXD                0x2
#define MUX_LP_GPIO_3_SPI0_MOSI                0x5
#define MUX_LP_GPIO_3_MEGAMUX                  0x1
#define MUX_LP_GPIO_3_SPI1_MOSI                0x4
#define MUX_LP_GPIO_3_SPI_FLASH0_TXD           0x6
#define MUX_LP_GPIO_3_TEST_OUT_3               0x7
#define MUX_LP_GPIO_3_GPIO                     0x0
/* Mux values for LP_GPIO_4 */
#define MUX_LP_GPIO_4_MEGAMUX                  0x1
#define MUX_LP_GPIO_4_UART0_CTS                0x2
#define MUX_LP_GPIO_4_SPI0_SSN                 0x5
#define MUX_LP_GPIO_4_SPI_FLASH0_SSN           0x6
#define MUX_LP_GPIO_4_TEST_OUT_4               0x7
#define MUX_LP_GPIO_4_GPIO                     0x0
#define MUX_LP_GPIO_4_SPI1_SSN                 0x4
/* Mux values for LP_GPIO_5 */
#define MUX_LP_GPIO_5_SPI_FLASH0_RXD           0x6
#define MUX_LP_GPIO_5_MEGAMUX                  0x1
#define MUX_LP_GPIO_5_SPI0_MISO                0x5
#define MUX_LP_GPIO_5_SPI1_MISO                0x4
#define MUX_LP_GPIO_5_TEST_OUT_5               0x7
#define MUX_LP_GPIO_5_UART0_RTS                0x2
#define MUX_LP_GPIO_5_GPIO                     0x0
/* Mux values for LP_GPIO_6 */
#define MUX_LP_GPIO_6_MEGAMUX                  0x1
#define MUX_LP_GPIO_6_SPI_FLASH0_SCK           0x6
#define MUX_LP_GPIO_6_UART1_RXD                0x2
#define MUX_LP_GPIO_6_TEST_OUT_6               0x7
#define MUX_LP_GPIO_6_GPIO                     0x0
#define MUX_LP_GPIO_6_SPI0_SCK                 0x5
/* Mux values for LP_GPIO_7 */
#define MUX_LP_GPIO_7_SPI0_MOSI                0x5
#define MUX_LP_GPIO_7_UART1_TXD                0x2
#define MUX_LP_GPIO_7_MEGAMUX                  0x1
#define MUX_LP_GPIO_7_TEST_OUT_7               0x7
#define MUX_LP_GPIO_7_SPI_FLASH0_TXD           0x6
#define MUX_LP_GPIO_7_GPIO                     0x0
/* Mux values for LP_GPIO_8 */
#define MUX_LP_GPIO_8_MEGAMUX                  0x1
#define MUX_LP_GPIO_8_SPI0_SSN                 0x5
#define MUX_LP_GPIO_8_SPI_FLASH0_SSN           0x6
#define MUX_LP_GPIO_8_GPIO                     0x0
#define MUX_LP_GPIO_8_I2C0_SDA                 0x2
#define MUX_LP_GPIO_8_TEST_OUT_8               0x7
/* Mux values for LP_GPIO_9 */
#define MUX_LP_GPIO_9_SPI_FLASH0_RXD           0x6
#define MUX_LP_GPIO_9_MEGAMUX                  0x1
#define MUX_LP_GPIO_9_SPI0_MISO                0x5
#define MUX_LP_GPIO_9_I2C0_SCL                 0x2
#define MUX_LP_GPIO_9_GPIO                     0x0
#define MUX_LP_GPIO_9_TEST_OUT_9               0x7
/* Mux values for LP_GPIO_10 */
#define MUX_LP_GPIO_10_GPIO                    0x0
#define MUX_LP_GPIO_10_MEGAMUX                 0x1
#define MUX_LP_GPIO_10_TEST_OUT_10             0x7
#define MUX_LP_GPIO_10_SPI_FLASH0_SCK          0x6
#define MUX_LP_GPIO_10_SPI0_SCK                0x2
/* Mux values for LP_GPIO_11 */
#define MUX_LP_GPIO_11_SPI0_MOSI               0x2
#define MUX_LP_GPIO_11_GPIO                    0x0
#define MUX_LP_GPIO_11_MEGAMUX                 0x1
#define MUX_LP_GPIO_11_SPI_FLASH0_TXD          0x6
#define MUX_LP_GPIO_11_TEST_OUT_11             0x7
/* Mux values for LP_GPIO_12 */
#define MUX_LP_GPIO_12_SPI_FLASH0_SSN          0x6
#define MUX_LP_GPIO_12_GPIO                    0x0
#define MUX_LP_GPIO_12_SPI0_SSN                0x2
#define MUX_LP_GPIO_12_MEGAMUX                 0x1
#define MUX_LP_GPIO_12_TEST_OUT_12             0x7
/* Mux values for LP_GPIO_13 */
#define MUX_LP_GPIO_13_GPIO                    0x0
#define MUX_LP_GPIO_13_SPI_FLASH0_RXD          0x6
#define MUX_LP_GPIO_13_MEGAMUX                 0x1
#define MUX_LP_GPIO_13_SPI0_MISO               0x2
#define MUX_LP_GPIO_13_TEST_OUT_13             0x7
/* Mux values for LP_GPIO_14 */
#define MUX_LP_GPIO_14_TEST_OUT_14             0x7
#define MUX_LP_GPIO_14_GPIO                    0x0
#define MUX_LP_GPIO_14_I2C1_SDA                0x4
#define MUX_LP_GPIO_14_MEGAMUX                 0x1
#define MUX_LP_GPIO_14_UART1_CTS               0x2
/* Mux values for LP_GPIO_15 */
#define MUX_LP_GPIO_15_GPIO                    0x0
#define MUX_LP_GPIO_15_MEGAMUX                 0x1
#define MUX_LP_GPIO_15_UART1_RTS               0x2
#define MUX_LP_GPIO_15_I2C1_SCL                0x4
#define MUX_LP_GPIO_15_TEST_OUT_15             0x7
/* Mux values for LP_GPIO_16 */
#define MUX_LP_GPIO_16_MEGAMUX                 0x1
#define MUX_LP_GPIO_16_SPI_FLASH0_SCK          0x2
#define MUX_LP_GPIO_16_TEST_OUT_16             0x7
#define MUX_LP_GPIO_16_SPI_FLASH0_SSN          0x6
#define MUX_LP_GPIO_16_GPIO                    0x0
#define MUX_LP_GPIO_16_SPI1_SSN                0x4
#define MUX_LP_GPIO_16_SPI0_SCK                0x5
/* Mux values for LP_GPIO_17 */
#define MUX_LP_GPIO_17_SPI0_MOSI               0x5
#define MUX_LP_GPIO_17_MEGAMUX                 0x1
#define MUX_LP_GPIO_17_TEST_OUT_17             0x7
#define MUX_LP_GPIO_17_SPI1_SCK                0x4
#define MUX_LP_GPIO_17_SPI_FLASH0_TXD          0x2
#define MUX_LP_GPIO_17_GPIO                    0x0
/* Mux values for LP_GPIO_18 */
#define MUX_LP_GPIO_18_SPI_FLASH0_RXD          0x6
#define MUX_LP_GPIO_18_MEGAMUX                 0x1
#define MUX_LP_GPIO_18_TEST_OUT_18             0x7
#define MUX_LP_GPIO_18_SPI0_SSN                0x5
#define MUX_LP_GPIO_18_SPI1_MISO               0x4
#define MUX_LP_GPIO_18_SPI_FLASH0_SSN          0x2
#define MUX_LP_GPIO_18_GPIO                    0x0
/* Mux values for LP_GPIO_19 */
#define MUX_LP_GPIO_19_SPI_FLASH0_RXD          0x2
#define MUX_LP_GPIO_19_MEGAMUX                 0x1
#define MUX_LP_GPIO_19_SPI0_MISO               0x5
#define MUX_LP_GPIO_19_TEST_OUT_19             0x7
#define MUX_LP_GPIO_19_SPI1_MOSI               0x4
#define MUX_LP_GPIO_19_GPIO                    0x0

/* MegaMux definitions                                              */
/* MegaMux values for LP_GPIO_0 */
#define MEGAMUX_LP_GPIO_0_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_0_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_0_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_0_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_0_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_0_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_0_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_0_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_0_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_0_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_0_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_0_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_0_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_0_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_0_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_0_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_0_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_0_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_0_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_0_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_0_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_0_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_0_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_0_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_0_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_0_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_0_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_0_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_0_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_0_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_0_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_1 */
#define MEGAMUX_LP_GPIO_1_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_1_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_1_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_1_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_1_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_1_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_1_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_1_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_1_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_1_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_1_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_1_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_1_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_1_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_1_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_1_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_1_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_1_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_1_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_1_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_1_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_1_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_1_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_1_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_1_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_1_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_1_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_1_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_1_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_1_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_1_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_2 */
#define MEGAMUX_LP_GPIO_2_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_2_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_2_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_2_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_2_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_2_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_2_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_2_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_2_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_2_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_2_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_2_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_2_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_2_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_2_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_2_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_2_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_2_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_2_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_2_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_2_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_2_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_2_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_2_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_2_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_2_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_2_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_2_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_2_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_2_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_2_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_3 */
#define MEGAMUX_LP_GPIO_3_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_3_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_3_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_3_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_3_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_3_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_3_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_3_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_3_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_3_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_3_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_3_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_3_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_3_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_3_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_3_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_3_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_3_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_3_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_3_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_3_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_3_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_3_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_3_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_3_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_3_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_3_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_3_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_3_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_3_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_3_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_4 */
#define MEGAMUX_LP_GPIO_4_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_4_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_4_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_4_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_4_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_4_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_4_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_4_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_4_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_4_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_4_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_4_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_4_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_4_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_4_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_4_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_4_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_4_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_4_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_4_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_4_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_4_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_4_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_4_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_4_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_4_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_4_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_4_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_4_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_4_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_4_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_4_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_4_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_4_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_4_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_5 */
#define MEGAMUX_LP_GPIO_5_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_5_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_5_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_5_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_5_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_5_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_5_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_5_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_5_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_5_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_5_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_5_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_5_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_5_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_5_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_5_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_5_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_5_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_5_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_5_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_5_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_5_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_5_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_5_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_5_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_5_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_5_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_5_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_5_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_5_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_5_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_5_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_5_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_5_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_5_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_6 */
#define MEGAMUX_LP_GPIO_6_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_6_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_6_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_6_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_6_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_6_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_6_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_6_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_6_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_6_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_6_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_6_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_6_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_6_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_6_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_6_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_6_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_6_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_6_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_6_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_6_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_6_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_6_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_6_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_6_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_6_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_6_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_6_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_6_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_6_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_6_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_6_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_6_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_6_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_6_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_7 */
#define MEGAMUX_LP_GPIO_7_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_7_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_7_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_7_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_7_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_7_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_7_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_7_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_7_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_7_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_7_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_7_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_7_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_7_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_7_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_7_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_7_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_7_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_7_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_7_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_7_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_7_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_7_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_7_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_7_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_7_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_7_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_7_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_7_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_7_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_7_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_7_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_7_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_7_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_7_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_8 */
#define MEGAMUX_LP_GPIO_8_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_8_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_8_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_8_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_8_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_8_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_8_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_8_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_8_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_8_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_8_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_8_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_8_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_8_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_8_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_8_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_8_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_8_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_8_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_8_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_8_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_8_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_8_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_8_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_8_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_8_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_8_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_8_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_8_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_8_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_8_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_9 */
#define MEGAMUX_LP_GPIO_9_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_9_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_9_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_9_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_9_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_9_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_9_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_9_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_9_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_9_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_9_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_9_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_9_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_9_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_9_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_9_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_9_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_9_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_9_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_9_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_9_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_9_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_9_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_9_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_9_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_9_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_9_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_9_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_9_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_9_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_9_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_10 */
#define MEGAMUX_LP_GPIO_10_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_10_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_10_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_10_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_10_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_10_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_10_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_10_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_10_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_10_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_10_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_10_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_10_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_10_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_10_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_10_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_10_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_10_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_10_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_10_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_10_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_10_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_10_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_10_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_10_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_10_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_10_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_10_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_10_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_10_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_10_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_11 */
#define MEGAMUX_LP_GPIO_11_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_11_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_11_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_11_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_11_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_11_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_11_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_11_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_11_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_11_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_11_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_11_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_11_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_11_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_11_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_11_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_11_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_11_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_11_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_11_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_11_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_11_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_11_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_11_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_11_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_11_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_11_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_11_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_11_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_11_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_11_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_12 */
#define MEGAMUX_LP_GPIO_12_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_12_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_12_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_12_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_12_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_12_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_12_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_12_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_12_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_12_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_12_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_12_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_12_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_12_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_12_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_12_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_12_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_12_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_12_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_12_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_12_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_12_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_12_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_12_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_12_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_12_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_12_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_12_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_12_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_12_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_12_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_13 */
#define MEGAMUX_LP_GPIO_13_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_13_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_13_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_13_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_13_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_13_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_13_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_13_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_13_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_13_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_13_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_13_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_13_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_13_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_13_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_13_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_13_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_13_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_13_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_13_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_13_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_13_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_13_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_13_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_13_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_13_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_13_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_13_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_13_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_13_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_13_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_14 */
#define MEGAMUX_LP_GPIO_14_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_14_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_14_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_14_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_14_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_14_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_14_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_14_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_14_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_14_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_14_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_14_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_14_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_14_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_14_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_14_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_14_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_14_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_14_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_14_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_14_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_14_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_14_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_14_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_14_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_14_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_14_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_14_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_14_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_14_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_14_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_14_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_14_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_14_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_14_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_15 */
#define MEGAMUX_LP_GPIO_15_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_15_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_15_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_15_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_15_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_15_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_15_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_15_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_15_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_15_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_15_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_15_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_15_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_15_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_15_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_15_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_15_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_15_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_15_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_15_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_15_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_15_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_15_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_15_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_15_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_15_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_15_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_15_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_15_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_15_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_15_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_15_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_15_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_15_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_15_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_16 */
#define MEGAMUX_LP_GPIO_16_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_16_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_16_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_16_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_16_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_16_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_16_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_16_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_16_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_16_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_16_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_16_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_16_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_16_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_16_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_16_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_16_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_16_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_16_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_16_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_16_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_16_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_16_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_16_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_16_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_16_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_16_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_16_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_16_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_16_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_16_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_16_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_16_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_16_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_16_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_17 */
#define MEGAMUX_LP_GPIO_17_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_17_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_17_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_17_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_17_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_17_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_17_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_17_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_17_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_17_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_17_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_17_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_17_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_17_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_17_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_17_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_17_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_17_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_17_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_17_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_17_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_17_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_17_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_17_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_17_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_17_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_17_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_17_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_17_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_17_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_17_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_17_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_17_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_17_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_17_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_18 */
#define MEGAMUX_LP_GPIO_18_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_18_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_18_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_18_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_18_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_18_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_18_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_18_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_18_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_18_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_18_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_18_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_18_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_18_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_18_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_18_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_18_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_18_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_18_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_18_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_18_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_18_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_18_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_18_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_18_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_18_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_18_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_18_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_18_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_18_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_18_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_18_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_18_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_18_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_18_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_19 */
#define MEGAMUX_LP_GPIO_19_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_19_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_19_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_19_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_19_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_19_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_19_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_19_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_19_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_19_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_19_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_19_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_19_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_19_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_19_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_19_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_19_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_19_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_19_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_19_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_19_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_19_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_19_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_19_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_19_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_19_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_19_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_19_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_19_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_19_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_19_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_19_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_19_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_19_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_19_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_20 */
#define MEGAMUX_LP_GPIO_20_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_20_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_20_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_20_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_20_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_20_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_20_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_20_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_20_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_20_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_20_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_20_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_20_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_20_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_20_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_20_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_20_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_20_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_20_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_20_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_20_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_20_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_20_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_20_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_20_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_20_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_20_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_20_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_20_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_20_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_20_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_20_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_20_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_20_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_20_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_21 */
#define MEGAMUX_LP_GPIO_21_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_21_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_21_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_21_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_21_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_21_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_21_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_21_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_21_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_21_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_21_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_21_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_21_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_21_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_21_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_21_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_21_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_21_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_21_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_21_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_21_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_21_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_21_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_21_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_21_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_21_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_21_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_21_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_21_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_21_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_21_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_21_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_21_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_21_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_21_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_22 */
#define MEGAMUX_LP_GPIO_22_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_22_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_22_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_22_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_22_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_22_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_22_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_22_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_22_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_22_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_22_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_22_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_22_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_22_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_22_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_22_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_22_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_22_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_22_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_22_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_22_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_22_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_22_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_22_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_22_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_22_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_22_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_22_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_22_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_22_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_22_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_22_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_22_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_22_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_22_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_23 */
#define MEGAMUX_LP_GPIO_23_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_23_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_23_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_23_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_23_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_23_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_23_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_23_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_23_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_23_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_23_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_23_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_23_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_23_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_23_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_23_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_23_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_23_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_23_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_23_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_23_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_23_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_23_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_23_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_23_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_23_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_23_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_23_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_23_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_23_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_23_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_23_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_23_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_23_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_23_PWM2_OUT                0xe

/* PinMux macros for LP_GPIO_0 */
#define PINMUX_LP_GPIO_0_GPIO                     ( PIN_LP_GPIO_0<<16 | MUX_LP_GPIO_0_GPIO )
#define PINMUX_LP_GPIO_0_M_I2C0_SCL               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_I2C0_SCL<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART1_CTS              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART1_CTS<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_TX            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_TX<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART0_RTS              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART0_RTS<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART0_RXD              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART0_RXD<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_32KHZ_CLK              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_32KHZ_CLK<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART0_TXD              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART0_TXD<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART1_TXD              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART1_TXD<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_I2C1_SCL               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_I2C1_SCL<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_WLAN_RX           ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_WLAN_RX<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_WLAN_TX           ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_WLAN_TX<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_PWM1_OUT               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_PWM1_OUT<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC0_B            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC0_B<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART1_RTS              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART1_RTS<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART0_CTS              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART0_CTS<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART1_RXD              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART1_RXD<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_I2C1_SDA               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_I2C1_SDA<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_I2C0_SDA               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_I2C0_SDA<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC2_A            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC2_A<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC2_B            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC2_B<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_RX            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_RX<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC1_B            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC1_B<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_PWM3_OUT               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_PWM3_OUT<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC0_A            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC0_A<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_PWM0_OUT               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_PWM0_OUT<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC1_A            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC1_A<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_PWM2_OUT               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_PWM2_OUT<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_SWD_CLK                  ( PIN_LP_GPIO_0<<16 | MUX_LP_GPIO_0_SWD_CLK )
#define PINMUX_LP_GPIO_0_TEST_OUT_0               ( PIN_LP_GPIO_0<<16 | MUX_LP_GPIO_0_TEST_OUT_0 )
/* PinMux macros for LP_GPIO_1 */
#define PINMUX_LP_GPIO_1_GPIO                     ( PIN_LP_GPIO_1<<16 | MUX_LP_GPIO_1_GPIO )
#define PINMUX_LP_GPIO_1_SWD_IO                   ( PIN_LP_GPIO_1<<16 | MUX_LP_GPIO_1_SWD_IO )
#define PINMUX_LP_GPIO_1_M_I2C0_SCL               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_I2C0_SCL<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART1_CTS              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART1_CTS<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_TX            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_TX<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART0_RTS              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART0_RTS<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART0_RXD              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART0_RXD<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_32KHZ_CLK              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_32KHZ_CLK<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART0_TXD              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART0_TXD<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART1_TXD              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART1_TXD<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_I2C1_SCL               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_I2C1_SCL<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_WLAN_RX           ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_WLAN_RX<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_WLAN_TX           ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_WLAN_TX<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_PWM1_OUT               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_PWM1_OUT<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC0_B            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC0_B<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART1_RTS              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART1_RTS<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART0_CTS              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART0_CTS<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART1_RXD              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART1_RXD<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_I2C1_SDA               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_I2C1_SDA<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_I2C0_SDA               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_I2C0_SDA<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC2_A            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC2_A<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC2_B            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC2_B<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_RX            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_RX<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC1_B            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC1_B<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_PWM3_OUT               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_PWM3_OUT<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC0_A            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC0_A<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_PWM0_OUT               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_PWM0_OUT<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC1_A            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC1_A<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_PWM2_OUT               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_PWM2_OUT<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_TEST_OUT_1               ( PIN_LP_GPIO_1<<16 | MUX_LP_GPIO_1_TEST_OUT_1 )
/* PinMux macros for LP_GPIO_2 */
#define PINMUX_LP_GPIO_2_M_I2C0_SCL               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_I2C0_SCL<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART1_CTS              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART1_CTS<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_TX            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_TX<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART0_RTS              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART0_RTS<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART0_RXD              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART0_RXD<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_32KHZ_CLK              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_32KHZ_CLK<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART0_TXD              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART0_TXD<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART1_TXD              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART1_TXD<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_I2C1_SCL               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_I2C1_SCL<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_WLAN_RX           ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_WLAN_RX<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_WLAN_TX           ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_WLAN_TX<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_PWM1_OUT               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_PWM1_OUT<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC0_B            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC0_B<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART1_RTS              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART1_RTS<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART0_CTS              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART0_CTS<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART1_RXD              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART1_RXD<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_I2C1_SDA               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_I2C1_SDA<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_I2C0_SDA               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_I2C0_SDA<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC2_A            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC2_A<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC2_B            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC2_B<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_RX            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_RX<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC1_B            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC1_B<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_PWM3_OUT               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_PWM3_OUT<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC0_A            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC0_A<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_PWM0_OUT               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_PWM0_OUT<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC1_A            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC1_A<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_PWM2_OUT               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_PWM2_OUT<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_SPI_FLASH0_SCK           ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_SPI_FLASH0_SCK )
#define PINMUX_LP_GPIO_2_SPI1_SCK                 ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_SPI1_SCK )
#define PINMUX_LP_GPIO_2_TEST_OUT_2               ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_TEST_OUT_2 )
#define PINMUX_LP_GPIO_2_UART0_RXD                ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_UART0_RXD )
#define PINMUX_LP_GPIO_2_GPIO                     ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_GPIO )
#define PINMUX_LP_GPIO_2_SPI0_SCK                 ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_SPI0_SCK )
/* PinMux macros for LP_GPIO_3 */
#define PINMUX_LP_GPIO_3_UART0_TXD                ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_UART0_TXD )
#define PINMUX_LP_GPIO_3_SPI0_MOSI                ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_SPI0_MOSI )
#define PINMUX_LP_GPIO_3_M_I2C0_SCL               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_I2C0_SCL<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART1_CTS              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART1_CTS<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_TX            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_TX<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART0_RTS              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART0_RTS<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART0_RXD              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART0_RXD<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_32KHZ_CLK              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_32KHZ_CLK<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART0_TXD              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART0_TXD<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART1_TXD              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART1_TXD<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_I2C1_SCL               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_I2C1_SCL<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_WLAN_RX           ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_WLAN_RX<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_WLAN_TX           ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_WLAN_TX<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_PWM1_OUT               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_PWM1_OUT<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC0_B            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC0_B<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART1_RTS              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART1_RTS<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART0_CTS              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART0_CTS<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART1_RXD              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART1_RXD<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_I2C1_SDA               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_I2C1_SDA<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_I2C0_SDA               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_I2C0_SDA<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC2_A            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC2_A<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC2_B            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC2_B<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_RX            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_RX<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC1_B            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC1_B<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_PWM3_OUT               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_PWM3_OUT<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC0_A            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC0_A<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_PWM0_OUT               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_PWM0_OUT<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC1_A            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC1_A<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_PWM2_OUT               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_PWM2_OUT<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_SPI1_MOSI                ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_SPI1_MOSI )
#define PINMUX_LP_GPIO_3_SPI_FLASH0_TXD           ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_SPI_FLASH0_TXD )
#define PINMUX_LP_GPIO_3_TEST_OUT_3               ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_TEST_OUT_3 )
#define PINMUX_LP_GPIO_3_GPIO                     ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_GPIO )
/* PinMux macros for LP_GPIO_4 */
#define PINMUX_LP_GPIO_4_M_I2C0_SCL               ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_I2C0_SCL<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_UART1_CTS              ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_UART1_CTS<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_BLE_TX            ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_BLE_TX<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_UART0_RTS              ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_UART0_RTS<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_UART0_RXD              ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_UART0_RXD<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_32KHZ_CLK              ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_32KHZ_CLK<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_UART0_TXD              ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_UART0_TXD<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_UART1_TXD              ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_UART1_TXD<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_I2C1_SCL               ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_I2C1_SCL<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_WLAN_RX           ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_WLAN_RX<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_WLAN_TX           ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_WLAN_TX<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_PWM1_OUT               ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_PWM1_OUT<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_QUAD_DEC0_B            ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_QUAD_DEC0_B<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_UART1_RTS              ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_UART1_RTS<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_UART0_CTS              ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_UART0_CTS<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_UART1_RXD              ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_UART1_RXD<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_I2C1_SDA               ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_I2C1_SDA<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_I2C0_SDA               ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_I2C0_SDA<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_QUAD_DEC2_A            ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_QUAD_DEC2_A<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_QUAD_DEC2_B            ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_QUAD_DEC2_B<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_BLE_RX            ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_BLE_RX<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_QUAD_DEC1_B            ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_QUAD_DEC1_B<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_PWM3_OUT               ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_PWM3_OUT<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_QUAD_DEC0_A            ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_QUAD_DEC0_A<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_PWM0_OUT               ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_PWM0_OUT<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_QUAD_DEC1_A            ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_QUAD_DEC1_A<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_M_PWM2_OUT               ( PIN_LP_GPIO_4<<16 | MEGAMUX_LP_GPIO_4_PWM2_OUT<<8 | MUX_LP_GPIO_4_MEGAMUX )
#define PINMUX_LP_GPIO_4_UART0_CTS                ( PIN_LP_GPIO_4<<16 | MUX_LP_GPIO_4_UART0_CTS )
#define PINMUX_LP_GPIO_4_SPI0_SSN                 ( PIN_LP_GPIO_4<<16 | MUX_LP_GPIO_4_SPI0_SSN )
#define PINMUX_LP_GPIO_4_SPI_FLASH0_SSN           ( PIN_LP_GPIO_4<<16 | MUX_LP_GPIO_4_SPI_FLASH0_SSN )
#define PINMUX_LP_GPIO_4_TEST_OUT_4               ( PIN_LP_GPIO_4<<16 | MUX_LP_GPIO_4_TEST_OUT_4 )
#define PINMUX_LP_GPIO_4_GPIO                     ( PIN_LP_GPIO_4<<16 | MUX_LP_GPIO_4_GPIO )
#define PINMUX_LP_GPIO_4_SPI1_SSN                 ( PIN_LP_GPIO_4<<16 | MUX_LP_GPIO_4_SPI1_SSN )
/* PinMux macros for LP_GPIO_5 */
#define PINMUX_LP_GPIO_5_SPI_FLASH0_RXD           ( PIN_LP_GPIO_5<<16 | MUX_LP_GPIO_5_SPI_FLASH0_RXD )
#define PINMUX_LP_GPIO_5_M_I2C0_SCL               ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_I2C0_SCL<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_UART1_CTS              ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_UART1_CTS<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_BLE_TX            ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_BLE_TX<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_UART0_RTS              ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_UART0_RTS<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_UART0_RXD              ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_UART0_RXD<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_32KHZ_CLK              ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_32KHZ_CLK<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_UART0_TXD              ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_UART0_TXD<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_UART1_TXD              ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_UART1_TXD<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_I2C1_SCL               ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_I2C1_SCL<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_WLAN_RX           ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_WLAN_RX<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_WLAN_TX           ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_WLAN_TX<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_PWM1_OUT               ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_PWM1_OUT<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_QUAD_DEC0_B            ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_QUAD_DEC0_B<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_UART1_RTS              ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_UART1_RTS<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_UART0_CTS              ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_UART0_CTS<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_UART1_RXD              ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_UART1_RXD<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_I2C1_SDA               ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_I2C1_SDA<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_I2C0_SDA               ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_I2C0_SDA<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_QUAD_DEC2_A            ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_QUAD_DEC2_A<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_QUAD_DEC2_B            ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_QUAD_DEC2_B<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_BLE_RX            ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_BLE_RX<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_QUAD_DEC1_B            ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_QUAD_DEC1_B<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_PWM3_OUT               ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_PWM3_OUT<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_QUAD_DEC0_A            ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_QUAD_DEC0_A<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_PWM0_OUT               ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_PWM0_OUT<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_QUAD_DEC1_A            ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_QUAD_DEC1_A<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_M_PWM2_OUT               ( PIN_LP_GPIO_5<<16 | MEGAMUX_LP_GPIO_5_PWM2_OUT<<8 | MUX_LP_GPIO_5_MEGAMUX )
#define PINMUX_LP_GPIO_5_SPI0_MISO                ( PIN_LP_GPIO_5<<16 | MUX_LP_GPIO_5_SPI0_MISO )
#define PINMUX_LP_GPIO_5_SPI1_MISO                ( PIN_LP_GPIO_5<<16 | MUX_LP_GPIO_5_SPI1_MISO )
#define PINMUX_LP_GPIO_5_TEST_OUT_5               ( PIN_LP_GPIO_5<<16 | MUX_LP_GPIO_5_TEST_OUT_5 )
#define PINMUX_LP_GPIO_5_UART0_RTS                ( PIN_LP_GPIO_5<<16 | MUX_LP_GPIO_5_UART0_RTS )
#define PINMUX_LP_GPIO_5_GPIO                     ( PIN_LP_GPIO_5<<16 | MUX_LP_GPIO_5_GPIO )
/* PinMux macros for LP_GPIO_6 */
#define PINMUX_LP_GPIO_6_M_I2C0_SCL               ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_I2C0_SCL<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_UART1_CTS              ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_UART1_CTS<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_BLE_TX            ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_BLE_TX<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_UART0_RTS              ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_UART0_RTS<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_UART0_RXD              ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_UART0_RXD<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_32KHZ_CLK              ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_32KHZ_CLK<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_UART0_TXD              ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_UART0_TXD<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_UART1_TXD              ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_UART1_TXD<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_I2C1_SCL               ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_I2C1_SCL<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_WLAN_RX           ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_WLAN_RX<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_WLAN_TX           ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_WLAN_TX<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_PWM1_OUT               ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_PWM1_OUT<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_QUAD_DEC0_B            ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_QUAD_DEC0_B<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_UART1_RTS              ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_UART1_RTS<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_UART0_CTS              ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_UART0_CTS<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_UART1_RXD              ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_UART1_RXD<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_I2C1_SDA               ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_I2C1_SDA<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_I2C0_SDA               ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_I2C0_SDA<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_QUAD_DEC2_A            ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_QUAD_DEC2_A<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_QUAD_DEC2_B            ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_QUAD_DEC2_B<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_BLE_RX            ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_BLE_RX<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_QUAD_DEC1_B            ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_QUAD_DEC1_B<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_PWM3_OUT               ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_PWM3_OUT<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_QUAD_DEC0_A            ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_QUAD_DEC0_A<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_PWM0_OUT               ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_PWM0_OUT<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_QUAD_DEC1_A            ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_QUAD_DEC1_A<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_M_PWM2_OUT               ( PIN_LP_GPIO_6<<16 | MEGAMUX_LP_GPIO_6_PWM2_OUT<<8 | MUX_LP_GPIO_6_MEGAMUX )
#define PINMUX_LP_GPIO_6_SPI_FLASH0_SCK           ( PIN_LP_GPIO_6<<16 | MUX_LP_GPIO_6_SPI_FLASH0_SCK )
#define PINMUX_LP_GPIO_6_UART1_RXD                ( PIN_LP_GPIO_6<<16 | MUX_LP_GPIO_6_UART1_RXD )
#define PINMUX_LP_GPIO_6_TEST_OUT_6               ( PIN_LP_GPIO_6<<16 | MUX_LP_GPIO_6_TEST_OUT_6 )
#define PINMUX_LP_GPIO_6_GPIO                     ( PIN_LP_GPIO_6<<16 | MUX_LP_GPIO_6_GPIO )
#define PINMUX_LP_GPIO_6_SPI0_SCK                 ( PIN_LP_GPIO_6<<16 | MUX_LP_GPIO_6_SPI0_SCK )
/* PinMux macros for LP_GPIO_7 */
#define PINMUX_LP_GPIO_7_SPI0_MOSI                ( PIN_LP_GPIO_7<<16 | MUX_LP_GPIO_7_SPI0_MOSI )
#define PINMUX_LP_GPIO_7_UART1_TXD                ( PIN_LP_GPIO_7<<16 | MUX_LP_GPIO_7_UART1_TXD )
#define PINMUX_LP_GPIO_7_M_I2C0_SCL               ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_I2C0_SCL<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_UART1_CTS              ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_UART1_CTS<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_BLE_TX            ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_BLE_TX<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_UART0_RTS              ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_UART0_RTS<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_UART0_RXD              ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_UART0_RXD<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_32KHZ_CLK              ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_32KHZ_CLK<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_UART0_TXD              ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_UART0_TXD<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_UART1_TXD              ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_UART1_TXD<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_I2C1_SCL               ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_I2C1_SCL<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_WLAN_RX           ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_WLAN_RX<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_WLAN_TX           ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_WLAN_TX<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_PWM1_OUT               ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_PWM1_OUT<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_QUAD_DEC0_B            ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_QUAD_DEC0_B<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_UART1_RTS              ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_UART1_RTS<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_UART0_CTS              ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_UART0_CTS<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_UART1_RXD              ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_UART1_RXD<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_I2C1_SDA               ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_I2C1_SDA<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_I2C0_SDA               ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_I2C0_SDA<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_QUAD_DEC2_A            ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_QUAD_DEC2_A<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_QUAD_DEC2_B            ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_QUAD_DEC2_B<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_BLE_RX            ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_BLE_RX<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_QUAD_DEC1_B            ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_QUAD_DEC1_B<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_PWM3_OUT               ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_PWM3_OUT<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_QUAD_DEC0_A            ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_QUAD_DEC0_A<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_PWM0_OUT               ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_PWM0_OUT<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_QUAD_DEC1_A            ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_QUAD_DEC1_A<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_M_PWM2_OUT               ( PIN_LP_GPIO_7<<16 | MEGAMUX_LP_GPIO_7_PWM2_OUT<<8 | MUX_LP_GPIO_7_MEGAMUX )
#define PINMUX_LP_GPIO_7_TEST_OUT_7               ( PIN_LP_GPIO_7<<16 | MUX_LP_GPIO_7_TEST_OUT_7 )
#define PINMUX_LP_GPIO_7_SPI_FLASH0_TXD           ( PIN_LP_GPIO_7<<16 | MUX_LP_GPIO_7_SPI_FLASH0_TXD )
#define PINMUX_LP_GPIO_7_GPIO                     ( PIN_LP_GPIO_7<<16 | MUX_LP_GPIO_7_GPIO )
/* PinMux macros for LP_GPIO_8 */
#define PINMUX_LP_GPIO_8_M_I2C0_SCL               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_I2C0_SCL<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART1_CTS              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART1_CTS<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_TX            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_TX<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART0_RTS              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART0_RTS<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART0_RXD              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART0_RXD<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_32KHZ_CLK              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_32KHZ_CLK<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART0_TXD              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART0_TXD<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART1_TXD              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART1_TXD<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_I2C1_SCL               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_I2C1_SCL<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_WLAN_RX           ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_WLAN_RX<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_WLAN_TX           ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_WLAN_TX<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_PWM1_OUT               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_PWM1_OUT<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC0_B            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC0_B<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART1_RTS              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART1_RTS<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART0_CTS              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART0_CTS<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART1_RXD              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART1_RXD<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_I2C1_SDA               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_I2C1_SDA<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_I2C0_SDA               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_I2C0_SDA<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC2_A            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC2_A<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC2_B            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC2_B<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_RX            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_RX<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC1_B            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC1_B<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_PWM3_OUT               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_PWM3_OUT<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC0_A            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC0_A<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_PWM0_OUT               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_PWM0_OUT<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC1_A            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC1_A<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_PWM2_OUT               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_PWM2_OUT<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_SPI0_SSN                 ( PIN_LP_GPIO_8<<16 | MUX_LP_GPIO_8_SPI0_SSN )
#define PINMUX_LP_GPIO_8_SPI_FLASH0_SSN           ( PIN_LP_GPIO_8<<16 | MUX_LP_GPIO_8_SPI_FLASH0_SSN )
#define PINMUX_LP_GPIO_8_GPIO                     ( PIN_LP_GPIO_8<<16 | MUX_LP_GPIO_8_GPIO )
#define PINMUX_LP_GPIO_8_I2C0_SDA                 ( PIN_LP_GPIO_8<<16 | MUX_LP_GPIO_8_I2C0_SDA )
#define PINMUX_LP_GPIO_8_TEST_OUT_8               ( PIN_LP_GPIO_8<<16 | MUX_LP_GPIO_8_TEST_OUT_8 )
/* PinMux macros for LP_GPIO_9 */
#define PINMUX_LP_GPIO_9_SPI_FLASH0_RXD           ( PIN_LP_GPIO_9<<16 | MUX_LP_GPIO_9_SPI_FLASH0_RXD )
#define PINMUX_LP_GPIO_9_M_I2C0_SCL               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_I2C0_SCL<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART1_CTS              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART1_CTS<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_TX            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_TX<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART0_RTS              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART0_RTS<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART0_RXD              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART0_RXD<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_32KHZ_CLK              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_32KHZ_CLK<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART0_TXD              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART0_TXD<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART1_TXD              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART1_TXD<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_I2C1_SCL               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_I2C1_SCL<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_WLAN_RX           ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_WLAN_RX<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_WLAN_TX           ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_WLAN_TX<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_PWM1_OUT               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_PWM1_OUT<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC0_B            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC0_B<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART1_RTS              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART1_RTS<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART0_CTS              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART0_CTS<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART1_RXD              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART1_RXD<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_I2C1_SDA               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_I2C1_SDA<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_I2C0_SDA               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_I2C0_SDA<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC2_A            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC2_A<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC2_B            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC2_B<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_RX            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_RX<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC1_B            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC1_B<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_PWM3_OUT               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_PWM3_OUT<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC0_A            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC0_A<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_PWM0_OUT               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_PWM0_OUT<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC1_A            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC1_A<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_PWM2_OUT               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_PWM2_OUT<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_SPI0_MISO                ( PIN_LP_GPIO_9<<16 | MUX_LP_GPIO_9_SPI0_MISO )
#define PINMUX_LP_GPIO_9_I2C0_SCL                 ( PIN_LP_GPIO_9<<16 | MUX_LP_GPIO_9_I2C0_SCL )
#define PINMUX_LP_GPIO_9_GPIO                     ( PIN_LP_GPIO_9<<16 | MUX_LP_GPIO_9_GPIO )
#define PINMUX_LP_GPIO_9_TEST_OUT_9               ( PIN_LP_GPIO_9<<16 | MUX_LP_GPIO_9_TEST_OUT_9 )
/* PinMux macros for LP_GPIO_10 */
#define PINMUX_LP_GPIO_10_GPIO                    ( PIN_LP_GPIO_10<<16 | MUX_LP_GPIO_10_GPIO )
#define PINMUX_LP_GPIO_10_M_I2C0_SCL              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_I2C0_SCL<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART1_CTS             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART1_CTS<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_TX           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_TX<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART0_RTS             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART0_RTS<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART0_RXD             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART0_RXD<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_32KHZ_CLK             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_32KHZ_CLK<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART0_TXD             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART0_TXD<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART1_TXD             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART1_TXD<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_I2C1_SCL              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_I2C1_SCL<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_WLAN_RX          ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_WLAN_RX<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_WLAN_TX          ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_WLAN_TX<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_PWM1_OUT              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_PWM1_OUT<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC0_B           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC0_B<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART1_RTS             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART1_RTS<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART0_CTS             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART0_CTS<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART1_RXD             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART1_RXD<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_I2C1_SDA              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_I2C1_SDA<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_I2C0_SDA              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_I2C0_SDA<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC2_A           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC2_A<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC2_B           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC2_B<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_RX           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_RX<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC1_B           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC1_B<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_PWM3_OUT              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_PWM3_OUT<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC0_A           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC0_A<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_PWM0_OUT              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_PWM0_OUT<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC1_A           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC1_A<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_PWM2_OUT              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_PWM2_OUT<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_TEST_OUT_10             ( PIN_LP_GPIO_10<<16 | MUX_LP_GPIO_10_TEST_OUT_10 )
#define PINMUX_LP_GPIO_10_SPI_FLASH0_SCK          ( PIN_LP_GPIO_10<<16 | MUX_LP_GPIO_10_SPI_FLASH0_SCK )
#define PINMUX_LP_GPIO_10_SPI0_SCK                ( PIN_LP_GPIO_10<<16 | MUX_LP_GPIO_10_SPI0_SCK )
/* PinMux macros for LP_GPIO_11 */
#define PINMUX_LP_GPIO_11_SPI0_MOSI               ( PIN_LP_GPIO_11<<16 | MUX_LP_GPIO_11_SPI0_MOSI )
#define PINMUX_LP_GPIO_11_GPIO                    ( PIN_LP_GPIO_11<<16 | MUX_LP_GPIO_11_GPIO )
#define PINMUX_LP_GPIO_11_M_I2C0_SCL              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_I2C0_SCL<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART1_CTS             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART1_CTS<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_TX           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_TX<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART0_RTS             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART0_RTS<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART0_RXD             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART0_RXD<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_32KHZ_CLK             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_32KHZ_CLK<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART0_TXD             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART0_TXD<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART1_TXD             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART1_TXD<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_I2C1_SCL              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_I2C1_SCL<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_WLAN_RX          ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_WLAN_RX<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_WLAN_TX          ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_WLAN_TX<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_PWM1_OUT              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_PWM1_OUT<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC0_B           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC0_B<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART1_RTS             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART1_RTS<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART0_CTS             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART0_CTS<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART1_RXD             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART1_RXD<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_I2C1_SDA              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_I2C1_SDA<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_I2C0_SDA              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_I2C0_SDA<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC2_A           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC2_A<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC2_B           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC2_B<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_RX           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_RX<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC1_B           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC1_B<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_PWM3_OUT              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_PWM3_OUT<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC0_A           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC0_A<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_PWM0_OUT              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_PWM0_OUT<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC1_A           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC1_A<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_PWM2_OUT              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_PWM2_OUT<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_SPI_FLASH0_TXD          ( PIN_LP_GPIO_11<<16 | MUX_LP_GPIO_11_SPI_FLASH0_TXD )
#define PINMUX_LP_GPIO_11_TEST_OUT_11             ( PIN_LP_GPIO_11<<16 | MUX_LP_GPIO_11_TEST_OUT_11 )
/* PinMux macros for LP_GPIO_12 */
#define PINMUX_LP_GPIO_12_SPI_FLASH0_SSN          ( PIN_LP_GPIO_12<<16 | MUX_LP_GPIO_12_SPI_FLASH0_SSN )
#define PINMUX_LP_GPIO_12_GPIO                    ( PIN_LP_GPIO_12<<16 | MUX_LP_GPIO_12_GPIO )
#define PINMUX_LP_GPIO_12_SPI0_SSN                ( PIN_LP_GPIO_12<<16 | MUX_LP_GPIO_12_SPI0_SSN )
#define PINMUX_LP_GPIO_12_M_I2C0_SCL              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_I2C0_SCL<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART1_CTS             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART1_CTS<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_TX           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_TX<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART0_RTS             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART0_RTS<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART0_RXD             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART0_RXD<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_32KHZ_CLK             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_32KHZ_CLK<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART0_TXD             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART0_TXD<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART1_TXD             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART1_TXD<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_I2C1_SCL              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_I2C1_SCL<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_WLAN_RX          ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_WLAN_RX<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_WLAN_TX          ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_WLAN_TX<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_PWM1_OUT              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_PWM1_OUT<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC0_B           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC0_B<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART1_RTS             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART1_RTS<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART0_CTS             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART0_CTS<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART1_RXD             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART1_RXD<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_I2C1_SDA              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_I2C1_SDA<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_I2C0_SDA              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_I2C0_SDA<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC2_A           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC2_A<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC2_B           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC2_B<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_RX           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_RX<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC1_B           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC1_B<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_PWM3_OUT              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_PWM3_OUT<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC0_A           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC0_A<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_PWM0_OUT              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_PWM0_OUT<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC1_A           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC1_A<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_PWM2_OUT              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_PWM2_OUT<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_TEST_OUT_12             ( PIN_LP_GPIO_12<<16 | MUX_LP_GPIO_12_TEST_OUT_12 )
/* PinMux macros for LP_GPIO_13 */
#define PINMUX_LP_GPIO_13_GPIO                    ( PIN_LP_GPIO_13<<16 | MUX_LP_GPIO_13_GPIO )
#define PINMUX_LP_GPIO_13_SPI_FLASH0_RXD          ( PIN_LP_GPIO_13<<16 | MUX_LP_GPIO_13_SPI_FLASH0_RXD )
#define PINMUX_LP_GPIO_13_M_I2C0_SCL              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_I2C0_SCL<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART1_CTS             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART1_CTS<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_TX           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_TX<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART0_RTS             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART0_RTS<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART0_RXD             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART0_RXD<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_32KHZ_CLK             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_32KHZ_CLK<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART0_TXD             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART0_TXD<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART1_TXD             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART1_TXD<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_I2C1_SCL              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_I2C1_SCL<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_WLAN_RX          ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_WLAN_RX<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_WLAN_TX          ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_WLAN_TX<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_PWM1_OUT              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_PWM1_OUT<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC0_B           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC0_B<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART1_RTS             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART1_RTS<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART0_CTS             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART0_CTS<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART1_RXD             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART1_RXD<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_I2C1_SDA              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_I2C1_SDA<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_I2C0_SDA              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_I2C0_SDA<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC2_A           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC2_A<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC2_B           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC2_B<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_RX           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_RX<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC1_B           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC1_B<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_PWM3_OUT              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_PWM3_OUT<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC0_A           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC0_A<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_PWM0_OUT              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_PWM0_OUT<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC1_A           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC1_A<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_PWM2_OUT              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_PWM2_OUT<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_SPI0_MISO               ( PIN_LP_GPIO_13<<16 | MUX_LP_GPIO_13_SPI0_MISO )
#define PINMUX_LP_GPIO_13_TEST_OUT_13             ( PIN_LP_GPIO_13<<16 | MUX_LP_GPIO_13_TEST_OUT_13 )
/* PinMux macros for LP_GPIO_14 */
#define PINMUX_LP_GPIO_14_TEST_OUT_14             ( PIN_LP_GPIO_14<<16 | MUX_LP_GPIO_14_TEST_OUT_14 )
#define PINMUX_LP_GPIO_14_GPIO                    ( PIN_LP_GPIO_14<<16 | MUX_LP_GPIO_14_GPIO )
#define PINMUX_LP_GPIO_14_I2C1_SDA                ( PIN_LP_GPIO_14<<16 | MUX_LP_GPIO_14_I2C1_SDA )
#define PINMUX_LP_GPIO_14_M_I2C0_SCL              ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_I2C0_SCL<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_UART1_CTS             ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_UART1_CTS<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_BLE_TX           ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_BLE_TX<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_UART0_RTS             ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_UART0_RTS<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_UART0_RXD             ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_UART0_RXD<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_32KHZ_CLK             ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_32KHZ_CLK<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_UART0_TXD             ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_UART0_TXD<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_UART1_TXD             ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_UART1_TXD<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_I2C1_SCL              ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_I2C1_SCL<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_WLAN_RX          ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_WLAN_RX<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_WLAN_TX          ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_WLAN_TX<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_PWM1_OUT              ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_PWM1_OUT<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_QUAD_DEC0_B           ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_QUAD_DEC0_B<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_UART1_RTS             ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_UART1_RTS<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_UART0_CTS             ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_UART0_CTS<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_UART1_RXD             ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_UART1_RXD<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_I2C1_SDA              ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_I2C1_SDA<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_I2C0_SDA              ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_I2C0_SDA<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_QUAD_DEC2_A           ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_QUAD_DEC2_A<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_QUAD_DEC2_B           ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_QUAD_DEC2_B<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_BLE_RX           ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_BLE_RX<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_QUAD_DEC1_B           ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_QUAD_DEC1_B<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_PWM3_OUT              ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_PWM3_OUT<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_QUAD_DEC0_A           ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_QUAD_DEC0_A<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_PWM0_OUT              ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_PWM0_OUT<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_QUAD_DEC1_A           ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_QUAD_DEC1_A<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_M_PWM2_OUT              ( PIN_LP_GPIO_14<<16 | MEGAMUX_LP_GPIO_14_PWM2_OUT<<8 | MUX_LP_GPIO_14_MEGAMUX )
#define PINMUX_LP_GPIO_14_UART1_CTS               ( PIN_LP_GPIO_14<<16 | MUX_LP_GPIO_14_UART1_CTS )
/* PinMux macros for LP_GPIO_15 */
#define PINMUX_LP_GPIO_15_GPIO                    ( PIN_LP_GPIO_15<<16 | MUX_LP_GPIO_15_GPIO )
#define PINMUX_LP_GPIO_15_M_I2C0_SCL              ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_I2C0_SCL<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_UART1_CTS             ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_UART1_CTS<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_BLE_TX           ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_BLE_TX<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_UART0_RTS             ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_UART0_RTS<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_UART0_RXD             ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_UART0_RXD<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_32KHZ_CLK             ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_32KHZ_CLK<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_UART0_TXD             ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_UART0_TXD<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_UART1_TXD             ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_UART1_TXD<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_I2C1_SCL              ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_I2C1_SCL<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_WLAN_RX          ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_WLAN_RX<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_WLAN_TX          ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_WLAN_TX<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_PWM1_OUT              ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_PWM1_OUT<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_QUAD_DEC0_B           ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_QUAD_DEC0_B<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_UART1_RTS             ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_UART1_RTS<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_UART0_CTS             ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_UART0_CTS<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_UART1_RXD             ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_UART1_RXD<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_I2C1_SDA              ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_I2C1_SDA<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_I2C0_SDA              ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_I2C0_SDA<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_QUAD_DEC2_A           ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_QUAD_DEC2_A<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_QUAD_DEC2_B           ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_QUAD_DEC2_B<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_BLE_RX           ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_BLE_RX<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_QUAD_DEC1_B           ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_QUAD_DEC1_B<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_PWM3_OUT              ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_PWM3_OUT<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_QUAD_DEC0_A           ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_QUAD_DEC0_A<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_PWM0_OUT              ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_PWM0_OUT<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_QUAD_DEC1_A           ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_QUAD_DEC1_A<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_M_PWM2_OUT              ( PIN_LP_GPIO_15<<16 | MEGAMUX_LP_GPIO_15_PWM2_OUT<<8 | MUX_LP_GPIO_15_MEGAMUX )
#define PINMUX_LP_GPIO_15_UART1_RTS               ( PIN_LP_GPIO_15<<16 | MUX_LP_GPIO_15_UART1_RTS )
#define PINMUX_LP_GPIO_15_I2C1_SCL                ( PIN_LP_GPIO_15<<16 | MUX_LP_GPIO_15_I2C1_SCL )
#define PINMUX_LP_GPIO_15_TEST_OUT_15             ( PIN_LP_GPIO_15<<16 | MUX_LP_GPIO_15_TEST_OUT_15 )
/* PinMux macros for LP_GPIO_16 */
#define PINMUX_LP_GPIO_16_M_I2C0_SCL              ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_I2C0_SCL<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_UART1_CTS             ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_UART1_CTS<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_BLE_TX           ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_BLE_TX<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_UART0_RTS             ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_UART0_RTS<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_UART0_RXD             ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_UART0_RXD<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_32KHZ_CLK             ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_32KHZ_CLK<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_UART0_TXD             ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_UART0_TXD<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_UART1_TXD             ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_UART1_TXD<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_I2C1_SCL              ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_I2C1_SCL<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_WLAN_RX          ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_WLAN_RX<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_WLAN_TX          ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_WLAN_TX<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_PWM1_OUT              ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_PWM1_OUT<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_QUAD_DEC0_B           ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_QUAD_DEC0_B<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_UART1_RTS             ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_UART1_RTS<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_UART0_CTS             ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_UART0_CTS<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_UART1_RXD             ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_UART1_RXD<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_I2C1_SDA              ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_I2C1_SDA<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_I2C0_SDA              ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_I2C0_SDA<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_QUAD_DEC2_A           ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_QUAD_DEC2_A<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_QUAD_DEC2_B           ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_QUAD_DEC2_B<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_BLE_RX           ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_BLE_RX<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_QUAD_DEC1_B           ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_QUAD_DEC1_B<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_PWM3_OUT              ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_PWM3_OUT<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_QUAD_DEC0_A           ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_QUAD_DEC0_A<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_PWM0_OUT              ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_PWM0_OUT<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_QUAD_DEC1_A           ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_QUAD_DEC1_A<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_M_PWM2_OUT              ( PIN_LP_GPIO_16<<16 | MEGAMUX_LP_GPIO_16_PWM2_OUT<<8 | MUX_LP_GPIO_16_MEGAMUX )
#define PINMUX_LP_GPIO_16_SPI_FLASH0_SCK          ( PIN_LP_GPIO_16<<16 | MUX_LP_GPIO_16_SPI_FLASH0_SCK )
#define PINMUX_LP_GPIO_16_TEST_OUT_16             ( PIN_LP_GPIO_16<<16 | MUX_LP_GPIO_16_TEST_OUT_16 )
#define PINMUX_LP_GPIO_16_SPI_FLASH0_SSN          ( PIN_LP_GPIO_16<<16 | MUX_LP_GPIO_16_SPI_FLASH0_SSN )
#define PINMUX_LP_GPIO_16_GPIO                    ( PIN_LP_GPIO_16<<16 | MUX_LP_GPIO_16_GPIO )
#define PINMUX_LP_GPIO_16_SPI1_SSN                ( PIN_LP_GPIO_16<<16 | MUX_LP_GPIO_16_SPI1_SSN )
#define PINMUX_LP_GPIO_16_SPI0_SCK                ( PIN_LP_GPIO_16<<16 | MUX_LP_GPIO_16_SPI0_SCK )
/* PinMux macros for LP_GPIO_17 */
#define PINMUX_LP_GPIO_17_SPI0_MOSI               ( PIN_LP_GPIO_17<<16 | MUX_LP_GPIO_17_SPI0_MOSI )
#define PINMUX_LP_GPIO_17_M_I2C0_SCL              ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_I2C0_SCL<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_UART1_CTS             ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_UART1_CTS<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_BLE_TX           ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_BLE_TX<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_UART0_RTS             ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_UART0_RTS<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_UART0_RXD             ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_UART0_RXD<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_32KHZ_CLK             ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_32KHZ_CLK<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_UART0_TXD             ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_UART0_TXD<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_UART1_TXD             ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_UART1_TXD<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_I2C1_SCL              ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_I2C1_SCL<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_WLAN_RX          ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_WLAN_RX<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_WLAN_TX          ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_WLAN_TX<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_PWM1_OUT              ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_PWM1_OUT<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_QUAD_DEC0_B           ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_QUAD_DEC0_B<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_UART1_RTS             ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_UART1_RTS<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_UART0_CTS             ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_UART0_CTS<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_UART1_RXD             ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_UART1_RXD<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_I2C1_SDA              ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_I2C1_SDA<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_I2C0_SDA              ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_I2C0_SDA<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_QUAD_DEC2_A           ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_QUAD_DEC2_A<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_QUAD_DEC2_B           ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_QUAD_DEC2_B<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_BLE_RX           ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_BLE_RX<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_QUAD_DEC1_B           ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_QUAD_DEC1_B<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_PWM3_OUT              ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_PWM3_OUT<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_QUAD_DEC0_A           ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_QUAD_DEC0_A<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_PWM0_OUT              ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_PWM0_OUT<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_QUAD_DEC1_A           ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_QUAD_DEC1_A<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_M_PWM2_OUT              ( PIN_LP_GPIO_17<<16 | MEGAMUX_LP_GPIO_17_PWM2_OUT<<8 | MUX_LP_GPIO_17_MEGAMUX )
#define PINMUX_LP_GPIO_17_TEST_OUT_17             ( PIN_LP_GPIO_17<<16 | MUX_LP_GPIO_17_TEST_OUT_17 )
#define PINMUX_LP_GPIO_17_SPI1_SCK                ( PIN_LP_GPIO_17<<16 | MUX_LP_GPIO_17_SPI1_SCK )
#define PINMUX_LP_GPIO_17_SPI_FLASH0_TXD          ( PIN_LP_GPIO_17<<16 | MUX_LP_GPIO_17_SPI_FLASH0_TXD )
#define PINMUX_LP_GPIO_17_GPIO                    ( PIN_LP_GPIO_17<<16 | MUX_LP_GPIO_17_GPIO )
/* PinMux macros for LP_GPIO_18 */
#define PINMUX_LP_GPIO_18_SPI_FLASH0_RXD          ( PIN_LP_GPIO_18<<16 | MUX_LP_GPIO_18_SPI_FLASH0_RXD )
#define PINMUX_LP_GPIO_18_M_I2C0_SCL              ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_I2C0_SCL<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_UART1_CTS             ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_UART1_CTS<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_BLE_TX           ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_BLE_TX<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_UART0_RTS             ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_UART0_RTS<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_UART0_RXD             ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_UART0_RXD<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_32KHZ_CLK             ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_32KHZ_CLK<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_UART0_TXD             ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_UART0_TXD<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_UART1_TXD             ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_UART1_TXD<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_I2C1_SCL              ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_I2C1_SCL<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_WLAN_RX          ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_WLAN_RX<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_WLAN_TX          ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_WLAN_TX<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_PWM1_OUT              ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_PWM1_OUT<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_QUAD_DEC0_B           ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_QUAD_DEC0_B<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_UART1_RTS             ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_UART1_RTS<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_UART0_CTS             ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_UART0_CTS<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_UART1_RXD             ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_UART1_RXD<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_I2C1_SDA              ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_I2C1_SDA<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_I2C0_SDA              ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_I2C0_SDA<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_QUAD_DEC2_A           ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_QUAD_DEC2_A<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_QUAD_DEC2_B           ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_QUAD_DEC2_B<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_BLE_RX           ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_BLE_RX<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_QUAD_DEC1_B           ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_QUAD_DEC1_B<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_PWM3_OUT              ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_PWM3_OUT<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_QUAD_DEC0_A           ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_QUAD_DEC0_A<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_PWM0_OUT              ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_PWM0_OUT<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_QUAD_DEC1_A           ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_QUAD_DEC1_A<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_M_PWM2_OUT              ( PIN_LP_GPIO_18<<16 | MEGAMUX_LP_GPIO_18_PWM2_OUT<<8 | MUX_LP_GPIO_18_MEGAMUX )
#define PINMUX_LP_GPIO_18_TEST_OUT_18             ( PIN_LP_GPIO_18<<16 | MUX_LP_GPIO_18_TEST_OUT_18 )
#define PINMUX_LP_GPIO_18_SPI0_SSN                ( PIN_LP_GPIO_18<<16 | MUX_LP_GPIO_18_SPI0_SSN )
#define PINMUX_LP_GPIO_18_SPI1_MISO               ( PIN_LP_GPIO_18<<16 | MUX_LP_GPIO_18_SPI1_MISO )
#define PINMUX_LP_GPIO_18_SPI_FLASH0_SSN          ( PIN_LP_GPIO_18<<16 | MUX_LP_GPIO_18_SPI_FLASH0_SSN )
#define PINMUX_LP_GPIO_18_GPIO                    ( PIN_LP_GPIO_18<<16 | MUX_LP_GPIO_18_GPIO )
/* PinMux macros for LP_GPIO_19 */
#define PINMUX_LP_GPIO_19_SPI_FLASH0_RXD          ( PIN_LP_GPIO_19<<16 | MUX_LP_GPIO_19_SPI_FLASH0_RXD )
#define PINMUX_LP_GPIO_19_M_I2C0_SCL              ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_I2C0_SCL<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_UART1_CTS             ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_UART1_CTS<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_BLE_TX           ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_BLE_TX<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_UART0_RTS             ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_UART0_RTS<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_UART0_RXD             ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_UART0_RXD<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_32KHZ_CLK             ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_32KHZ_CLK<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_UART0_TXD             ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_UART0_TXD<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_UART1_TXD             ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_UART1_TXD<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_I2C1_SCL              ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_I2C1_SCL<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_WLAN_RX          ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_WLAN_RX<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_WLAN_TX          ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_WLAN_TX<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_PWM1_OUT              ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_PWM1_OUT<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_QUAD_DEC0_B           ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_QUAD_DEC0_B<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_UART1_RTS             ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_UART1_RTS<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_UART0_CTS             ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_UART0_CTS<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_UART1_RXD             ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_UART1_RXD<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_I2C1_SDA              ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_I2C1_SDA<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_I2C0_SDA              ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_I2C0_SDA<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_QUAD_DEC2_A           ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_QUAD_DEC2_A<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_QUAD_DEC2_B           ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_QUAD_DEC2_B<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_BLE_RX           ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_BLE_RX<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_QUAD_DEC1_B           ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_QUAD_DEC1_B<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_PWM3_OUT              ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_PWM3_OUT<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_QUAD_DEC0_A           ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_QUAD_DEC0_A<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_PWM0_OUT              ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_PWM0_OUT<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_QUAD_DEC1_A           ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_QUAD_DEC1_A<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_M_PWM2_OUT              ( PIN_LP_GPIO_19<<16 | MEGAMUX_LP_GPIO_19_PWM2_OUT<<8 | MUX_LP_GPIO_19_MEGAMUX )
#define PINMUX_LP_GPIO_19_SPI0_MISO               ( PIN_LP_GPIO_19<<16 | MUX_LP_GPIO_19_SPI0_MISO )
#define PINMUX_LP_GPIO_19_TEST_OUT_19             ( PIN_LP_GPIO_19<<16 | MUX_LP_GPIO_19_TEST_OUT_19 )
#define PINMUX_LP_GPIO_19_SPI1_MOSI               ( PIN_LP_GPIO_19<<16 | MUX_LP_GPIO_19_SPI1_MOSI )
#define PINMUX_LP_GPIO_19_GPIO                    ( PIN_LP_GPIO_19<<16 | MUX_LP_GPIO_19_GPIO )

#endif /* _SAMB11ZR_PIO_ */
