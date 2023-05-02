// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Pending
// - `~
// - |\\
// - Fn
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * -------------------- Base Layer --------------------
     *
     * ┌───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ │ 7 │ 8 │ 9 │ 0 │ - │ = │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │Tab│ q │ w │ e │ r │ t │ │ y │ u │ i │ o │ p │ [ │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │Cap│ a │ s │ d │ f │ g │ │ h │ j │ k │ l │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │Shf│ z │ x │ c │ v │ b │ │ n │ m │ , │ . │ / │ ] │
     * └───┴───┼───┼───┼───┼───┘ └───┼───┼───┼───┼───┴───┘
     *         │Win│ ← │ → ├───┐ ┌───┤ ↑ │ ↓ │Ret│
     *         └───┼───┼───┤   │ │   ├───┼───┼───┘
     *             │Ctl│Alt│Esc│ │Spc│Alt│Ctl│
     *             └───┴───┴───┘ └───┴───┴───┘
     *
     * -------------------- Shift Mod --------------------
     *
     * ┌───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┐
     * │ ! │ @ │ # │ $ │ % │ ^ │ │ & │ * │ ( │ ) │ _ │ + │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E │ R │ T │ │ Y │ U │ I │ O │ P │ { │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │Cap│ A │ S │ D │ F │ G │ │ H │ J │ K │ L │ : │ " │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │Shf│ Z │ X │ C │ V │ B │ │ N │ M │ < │ > │ ? │ } │
     * └───┴───┼───┼───┼───┼───┘ └───┼───┼───┼───┼───┴───┘
     *         │Win│Hom│End├───┐ ┌───┤Pg↑│Pg↓│Ret│
     *         └───┼───┼───┤   │ │   ├───┼───┼───┘
     *             │Ctl│Alt│Esc│ │Spc│Alt│Ctl│
     *             └───┴───┴───┘ └───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,           /**/  KC_7,   KC_8,       KC_9,       KC_0,       KC_MINUS,   KC_EQUAL
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,           /**/  KC_Y,   KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,           /**/  KC_H,   KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOTE
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,           /**/  KC_N,   KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_RBRC
        KC_LWIN,    KC_RIGHT,   KC_LEFT,    KC_LCTL,    KC_LALT,    LT(1, KC_ESC),  /**/  KC_UP,  KC_DOWN,    KC_ENTER,   KC_SPACE,   KC_RALT,    KC_RCTL
    )
    /*
     * --------------------- LT(Esc) ---------------------
     *
     * ┌───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┐
     * │󰃝  │󰃠  │   │ 󰝞 │ 󰝟 │ 󰝝 │ │ 󰒮 │ 󰐎 │ 󰒭 │   │Del│BSp│
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │F1 │F2 │F3 │F4 │F5 │F6 │ │F7 │F8 │F9 │F10│F11│F12│
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │ │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │ │   │   │   │   │   │   │
     * └───┴───┼───┼───┼───┼───┘ └───┼───┼───┼───┼───┴───┘
     *         │Win│   │   ├───┐ ┌───┤   │   │Ret│
     *         └───┼───┼───┤   │ │Prt├───┼───┼───┘
     *             │Ctl│Alt│---│ │Scr│Alt│Ctl│
     *             └───┴───┴───┘ └───┴───┴───┘
     */
    [1] = LAYOUT(
        KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,    /**/  KC_7,   KC_8,       KC_9,       KC_0,       KC_MINUS,   KC_EQUAL
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,    /**/  KC_Y,   KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,    /**/  KC_H,   KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOTE
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,    /**/  KC_N,   KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_RBRC
        KC_LWIN,    KC_RIGHT,   KC_LEFT,    KC_LCTL,    KC_LALT,    KC_ESC,  /**/  KC_UP,  KC_DOWN,    KC_ENTER,   KC_SPACE,   KC_RALT,    KC_RCTL
    )
};

// Shift Left is Home
const key_override_t left_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT, KC_HOME);
// Shift Right is End
const key_override_t right_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT, KC_END);
// Shift Up is PageUp
const key_override_t up_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_UP, KC_PGUP);
// Shift Down is PageDown
const key_override_t down_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOWN, KC_PGDN);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &left_key_override,
    &right_key_override,
    &up_key_override,
    &down_key_override,
    NULL // Null terminate the array of overrides!
};
