// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum Layers {
    BaseLyr,
    FnLyr
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BaseLyr] = LAYOUT(
        LT(FnLyr, KC_1),    KC_2,           _______, /**/ _______,    KC_A,  KC_B,
        LSFT_T(KC_3),       RSFT_T(KC_4),   KC_MPLY, /**/ KC_MUTE,    KC_UP, KC_DOWN
    ),
    [FnLyr] = LAYOUT(
        _______,    KC_MUTE,    _______,    _______,    KC_1,   KC_2,
        KC_VOLD,    KC_VOLU,    _______,    _______,    KC_3,   KC_4
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

const uint16_t PROGMEM caps_combo[] = {LSFT_T(KC_3), RSFT_T(KC_4), COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO(caps_combo, KC_CAPS),
};

// ======================= Encoder =======================

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
            // tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code(KC_VOLD);
            // tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_BRIGHTNESS_UP);
        } else {
            tap_code(KC_BRIGHTNESS_DOWN);
        }
    }
    return false;
}
