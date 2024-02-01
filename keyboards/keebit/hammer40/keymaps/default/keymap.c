// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Thumb Keys
#define L_THUMB LT(_BASE, KC_ENTER)
#define R_THUMB LT(_BASE, KC_SPACE)

// Rotary
#define KK_ROT KC_MPLY

enum hammer_layers {
    _BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRAVE, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_LBRC,
        KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOTE,
        KC_RBRC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KK_ROT, KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_MINUS,
        KC_BSLS,  KC_PSCR, _______, KC_LCTL, KC_LALT, L_THUMB, KC_ESC, R_THUMB, KC_LSFT, KC_LGUI,  KC_BSPC, KC_DEL,   KC_EQUAL
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

#ifdef OLED_ENABLE
#include "bongo.c"
#endif
