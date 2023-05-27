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
// #define NO_ACTION_ONESHOT

#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6, F5 }
#define MATRIX_ROW_PINS_RIGHT { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS_RIGHT { F5, B6, B2, B3, B1, F7, F6 }

#define SOFT_SERIAL_PIN D0
#define SPLIT_HAND_PIN D5
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500

// NOTE: Uncomment the following line, if you want the left side to be the `master`
// #define SPLIT_HAND_PIN_LOW_IS_LEFT
