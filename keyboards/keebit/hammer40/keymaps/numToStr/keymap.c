// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "hammer40.h"

// Thumb Keys
#define L_THUMB LT(_NAV, KC_ENTER)
#define R_THUMB LT(_NUM, KC_SPACE)

// Rotary
#define ROTARY TD(TD_MEDIA)

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

#define BOOTL_1 KC_GRAVE
#define BOOTL_2 KC_Q
#define BOOTL_3 KC_W

#define EECLR_1 KC_O
#define EECLR_2 KC_P
#define EECLR_3 KC_LBRC

enum hammer_tapdance {
    TD_MEDIA,
    TD_COPY_CUT,
};

void rotary_dance_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: register_code(KC_MPLY); break;
        case 2: register_code(KC_MNXT); break;
        case 3: register_code(KC_MPRV); break;
    }
}

void rotary_dance_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: unregister_code(KC_MPLY); break;
        case 2: unregister_code(KC_MNXT); break;
        case 3: unregister_code(KC_MPRV); break;
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Media-Next, twice for Media-Previous
    [TD_MEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rotary_dance_finished, rotary_dance_reset),
    // Tap once copy, twice for cut
    [TD_COPY_CUT] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C), LCTL(KC_X)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        BOOTL_1, BOOTL_2, BOOTL_3, KC_E,    KC_R,   KC_T,             KC_Y,    KC_U,    KC_I,     EECLR_1, EECLR_2,  EECLR_3,
        KC_TAB,  GUI_A,   ALT_S,   SFT_D,   CTL_F,  KC_G,             KC_H,    CTL_J,   SFT_K,    ALT_L,   GUI_SCLN, KC_QUOTE,
        KC_RBRC, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    ROTARY,  KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_MINUS,
        KC_BSLS, _______, _______, _______, KC_ESC, L_THUMB, KC_PSCR, R_THUMB, KC_BSPC, KC_DEL,   _______, _______,  KC_EQUAL
    ),
    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,          _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, _______, _______, _______, _______,             KC_0, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUM] = { ENCODER_CCW_CW(_______, _______) },
    [_NAV] = { ENCODER_CCW_CW(_______, _______) },
};

// Left and right thumb is CapsLock
const uint16_t PROGMEM capsw_combo[] = {L_THUMB, R_THUMB, COMBO_END};
const uint16_t PROGMEM bootl_combo[] = {BOOTL_1, BOOTL_2, BOOTL_3, COMBO_END};
const uint16_t PROGMEM eeclr_combo[] = {EECLR_1, EECLR_2, EECLR_3, COMBO_END};

combo_t key_combos[] = {
    COMBO(capsw_combo, QK_CAPS_WORD_TOGGLE),
    COMBO(bootl_combo, QK_BOOTLOADER),
    COMBO(eeclr_combo, QK_CLEAR_EEPROM),
};

#ifdef OLED_ENABLE
#include "bongo_128x64.c"
#endif
