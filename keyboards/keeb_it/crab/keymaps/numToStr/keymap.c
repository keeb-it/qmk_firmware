// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_UP,          KC_DOWN,        KC_1,   KC_2,
        LSFT_T(KC_A),   RSFT_T(KC_B),   KC_3,   KC_4
    )
};

// ======================= Overrides =======================

const key_override_t up_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_UP, KC_PGUP);
const key_override_t down_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOWN, KC_PGDN);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &up_key_override,
    &down_key_override,
    NULL // Null terminate the array of overrides!
};

// ======================= Combos =======================

enum combos {
    CAPS_COMBO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_combo[] = {LSFT_T(KC_A), RSFT_T(KC_B), COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO(caps_combo, KC_CAPS),
};
