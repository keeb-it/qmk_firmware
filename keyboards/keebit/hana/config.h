// Copyright 2023 numToStr (@numToStr)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 220U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25 // GP16/GP17/GP25 | Specify a optional status led by GPIO number which blinks when entering the bootloader

#define SPI_DRIVER SPID0
#define SPI_LATCH_PIN GP1 /* io_cs */
#define SPI_SCK_PIN GP2
#define SPI_MISO_PIN NO_PIN
#define SPI_MOSI_PIN GP3
#define SPI_MODE 3

//rp2040 supports nothing else
#define SPI_lsbFirst false

#define SPI_DIVISOR 32

// 0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080
// 1QA     1QB     1QC     1QD     1QE     1QF     1QG     1QH
//
// 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000
// 2QA     2QB     2QC     2QD     2QE     2QF     2QG     2QH

                       // 1QG     1QF     1QE     1QD     1QC     1QA     1QH     1QB
#define MATRIX_COLS_LEFT {0x0040, 0x0020, 0x0010, 0x0008, 0x0004, 0x0001, 0x0080, 0x0002}
                        // 1QB     1QC     1QA     1QH     1QG     1QF     1QE     1QD
#define MATRIX_COLS_RIGHT {0x0002, 0x0004, 0x0001, 0x0080, 0x0040, 0x0020, 0x0010, 0x0008}

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7
