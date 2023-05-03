// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum Layers {
    BaseLyr,
    FnLyr
};

// [Miryoku](https://github.com/manna-harbour/miryoku) inspired key layout
// Think
//  - Hold Spc is Enter
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * -------------------- Base Layer --------------------
     *
     * ┌───┬───┬───┬───┬───┬───┐  ┌───┬───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │  │ 7 │ 8 │ 9 │ 0 │ - │ = │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │ ` │ q │ w │ e │ r │ t │  │ y │ u │ i │ o │ p │ [ │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │\\ │ a │ s │ d │ f │ g │  │ h │ j │ k │ l │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │Tab│ z │ x │ c │ v │ b │  │ n │ m │ , │ . │ / │ ] │
     * └───┴───┼───┼───┼───┼───┘  └───┼───┼───┼───┼───┴───┘
     *         │Win│Del│PSc├───┐  ┌───┤Ret│BSp│   │
     *         └───┼───┼───┤   │  │   ├───┼───┼───┘
     *             │ ← │ → │Esc│  │Spc│ ↑ │ ↓ │
     *             └───┴───┴───┘  └───┴───┴───┘
     *
     * -------------------- Shift Mod --------------------
     *
     * ┌───┬───┬───┬───┬───┬───┐  ┌───┬───┬───┬───┬───┬───┐
     * │ ! │ @ │ # │ $ │ % │ ^ │  │ & │ * │ ( │ ) │ _ │ + │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │ ~ │ Q │ W │ E │ R │ T │  │ Y │ U │ I │ O │ P │ { │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │ | │ A │ S │ D │ F │ G │  │ H │ J │ K │ L │ : │ " │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │Tab│ Z │ X │ C │ V │ B │  │ N │ M │ < │ > │ ? │ } │
     * └───┴───┼───┼───┼───┼───┘  └───┼───┼───┼───┼───┴───┘
     *         │Win│Del│PSc├───┐  ┌───┤Ret│BSp│   │
     *         └───┼───┼───┤   │  │   ├───┼───┼───┘
     *             │Hom│End│Esc│  │Spc│Pg↑│Pg↓│
     *             └───┴───┴───┘  └───┴───┴───┘
     * NOTE:
     *  - When held, G and H becomes LShift and RShift respectively (using mod-tap).
     *  - When held, F and J becomes LCtrl and RCtrl respectively (using mod-tap).
     *  - When held, D and K becomes LAlt and RAlt respectively (using mod-tap).
     *  - Pressing Shift and Left, Right, Up, and Down becomes Home, End, PgUp, and PgDown respectively (using key_overrides).
     *  - Pressing Esc and Space together will act as CapsLock (using combos).
     */
    [BaseLyr] = LAYOUT(
        KC_1,    KC_2,   KC_3,    KC_4,         KC_5,         KC_6,              /**/ KC_7,         KC_8,         KC_9,         KC_0,     KC_MINUS, KC_EQUAL,
        KC_GRV,  KC_Q,   KC_W,    KC_E,         KC_R,         KC_T,              /**/ KC_Y,         KC_U,         KC_I,         KC_O,     KC_P,     KC_LBRC,
        KC_BSLS, KC_A,   KC_S,    LALT_T(KC_D), LCTL_T(KC_F), LSFT_T(KC_G),      /**/ RSFT_T(KC_H), RCTL_T(KC_J), RALT_T(KC_K), KC_L,     KC_SCLN,  KC_QUOTE,
        KC_TAB,  KC_Z,   KC_X,    KC_C,         KC_V,         KC_B,              /**/ KC_N,         KC_M,         KC_COMMA,     KC_DOT,   KC_SLASH, KC_RBRC,
        KC_LWIN, KC_DEL, KC_PSCR, KC_LEFT,      KC_RIGHT,     LT(FnLyr, KC_ESC), /**/ KC_ENTER,     KC_BSPC,      _______,      KC_SPACE, KC_UP,    KC_DOWN
    ),
    /*
     * --------------------- LT(1, Esc) ---------------------
     *
     * ┌───┬───┬───┬───┬───┬───┐  ┌───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │󰃝  │󰃠  │  │ 󰒮 │ 󰐎 │ 󰒭 │ 󰝟 │ 󰝞 │ 󰝝 │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │F1 │F2 │F3 │F4 │F5 │F6 │  │F7 │F8 │F9 │F10│F11│F12│
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │  │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │  │   │   │   │   │   │   │
     * └───┴───┼───┼───┼───┼───┘  └───┼───┼───┼───┼───┴───┘
     *         │Win│Del│PSc├───┐  ┌───┤Ret│BSp│   │
     *         └───┼───┼───┤   │  │   ├───┼───┼───┘
     *             │ ← │ → │---│  │Spc│ ↑ │ ↓ │
     *             └───┴───┴───┘  └───┴───┴───┘
     */
    [FnLyr] = LAYOUT(
        _______, _______, _______, _______, KC_BRID,  KC_BRIU, /**/ KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD, KC_VOLU,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   /**/ KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
        _______, _______, _______, _______, _______,  _______, /**/ _______,  _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______,  _______, /**/ _______,  _______, _______, _______,  _______, _______,
        KC_LWIN, KC_DEL,  KC_PSCR, KC_LEFT, KC_RIGHT, _______, /**/ KC_ENTER, KC_BSPC, _______, KC_SPACE, KC_UP,   KC_DOWN
    )
};

// ======================= Overrides =======================

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

// ======================= Combos =======================

enum combos {
    CAPS_COMBO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// Esc + Space = CapsLock
const uint16_t PROGMEM caps_combo[] = {LT(FnLyr, KC_ESC), KC_SPACE, COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO(caps_combo, KC_CAPS),
};
