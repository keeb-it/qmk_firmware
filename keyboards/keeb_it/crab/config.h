// Copyright 2023 Vikas Rajbanshi (@numToStr)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

// #define MATRIX_ROW_PINS_RIGHT { <row pins> }
// #define MATRIX_COL_PINS_RIGHT { <col pins> }

#define SOFT_SERIAL_PIN D0
#define SPLIT_HAND_PIN D5
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500
