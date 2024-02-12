// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "hammer40.h"

// Thumb Keys
#define L_THUMB LT(_BASE, KC_ENTER)
#define R_THUMB LT(_BASE, KC_SPACE)

#define BOOTL_1 KC_GRAVE
#define BOOTL_2 KC_Q
#define BOOTL_3 KC_W

// Rotary
#define KK_ROT KC_MPLY

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        BOOTL_1, BOOTL_2, BOOTL_3, KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_LBRC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOTE,
        KC_RBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KK_ROT, KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_MINUS,
        KC_BSLS, KC_PSCR, _______, KC_LCTL, KC_LALT, L_THUMB, KC_ESC, R_THUMB, KC_LSFT, KC_LGUI,  KC_BSPC, KC_DEL,   KC_EQUAL
    )
};

// Left and right thumb is CapsLock
const uint16_t PROGMEM capsw_combo[] = {L_THUMB, R_THUMB, COMBO_END};
const uint16_t PROGMEM bootl_combo[] = {BOOTL_1, BOOTL_2, BOOTL_3, COMBO_END};
// const uint16_t PROGMEM eeclr_combo[] = {EECLR_1, EECLR_2, EECLR_3, COMBO_END};

combo_t key_combos[] = {
    COMBO(capsw_combo, QK_CAPS_WORD_TOGGLE),
    COMBO(bootl_combo, QK_BOOTLOADER),
    // COMBO(eeclr_combo, QK_CLEAR_EEPROM),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

#ifdef OLED_ENABLE
#include "bongo.c"
#endif
