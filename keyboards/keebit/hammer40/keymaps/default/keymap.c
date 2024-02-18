// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "hammer40.h"

// Thumb Keys
#define L_THUMB LT(_NAV, KC_ENTER)
#define R_THUMB LT(_NUM, KC_SPACE)

#define BOOTL_1 KC_GRAVE
#define BOOTL_2 KC_Q
#define BOOTL_3 KC_W

#define EECLR_1 KC_O
#define EECLR_2 KC_P
#define EECLR_3 KC_LBRC

// Rotary
#define KK_ROT KC_MPLY

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        BOOTL_1, BOOTL_2, BOOTL_3, KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,     EECLR_1, EECLR_2,  EECLR_3,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOTE,
        KC_RBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KK_ROT, KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_MINUS,
        KC_BSLS, KC_PSCR, KC_LCTL, KC_LGUI, KC_LALT, L_THUMB, KC_ESC, R_THUMB, KC_LSFT, KC_RCTL,  KC_BSPC, KC_DEL,   KC_EQUAL
    ),
    [_NUM] = LAYOUT(
        _______, _______, KC_7,    KC_8,    KC_9,    _______,          _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, KC_4,    KC_5,    KC_6,    KC_0,             KC_0,    KC_4,    KC_5,    KC_6,    _______, _______,
        _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUM] = { ENCODER_CCW_CW(_______, _______) },
    [_NAV] = { ENCODER_CCW_CW(_______, _______) },
};

// Left and right thumb is CapsLock
const uint16_t PROGMEM bootl_combo[] = {BOOTL_1, BOOTL_2, BOOTL_3, COMBO_END};
const uint16_t PROGMEM eeclr_combo[] = {EECLR_1, EECLR_2, EECLR_3, COMBO_END};

combo_t key_combos[] = {
    COMBO(bootl_combo, QK_BOOTLOADER),
    COMBO(eeclr_combo, QK_CLEAR_EEPROM),
};
