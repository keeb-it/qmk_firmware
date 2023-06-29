// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum Layers {
    BaseLyr,
    FnLyr
};

// Inspired by [Miryoku](https://github.com/manna-harbour/miryoku) layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * -------------------- Base Layer --------------------
     *
     * ┌───┬───┬───┬───┬───┬───┐  ┌───┬───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │  │ 7 │ 8 │ 9 │ 0 │ - │ = │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │Tab│ q │ w │ e │ r │ t │  │ y │ u │ i │ o │ p │ [ │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │ ~ │ a │ s │ d │ f │ g │  │ h │ j │ k │ l │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │\\ │ z │ x │ c │ v │ b │  │ n │ m │ , │ . │ / │ ] │
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
     * │Tab│ Q │ W │ E │ R │ T │  │ Y │ U │ I │ O │ P │ { │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │ ~ │ A │ S │ D │ F │ G │  │ H │ J │ K │ L │ : │ " │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │ | │ Z │ X │ C │ V │ B │  │ N │ M │ < │ > │ ? │ } │
     * └───┴───┼───┼───┼───┼───┘  └───┼───┼───┼───┼───┴───┘
     *         │Win│Del│PSc├───┐  ┌───┤Ret│BSp│Win│
     *         └───┼───┼───┤   │  │   ├───┼───┼───┘
     *             │Hom│End│Esc│  │Spc│Pg↑│Pg↓│
     *             └───┴───┴───┘  └───┴───┴───┘
     * NOTE:
     *  - Pressing Shift and Left, Right, Up, and Down becomes Home, End, PgUp, and PgDown respectively (using key_overrides).
     *  - When held, S and L becomes LShift and RShift respectively (using mod-tap).
     *  - When held, D and K becomes LAlt and RAlt respectively (using mod-tap).
     *  - When held, F and J becomes LCtrl and RCtrl respectively (using mod-tap).
     *  - Pressing Esc and Space together will act as CapsLock (using combos).
     *
     * ----------------- Mod-Tap + Combo -----------------
     *
     * ┌───┬───┬───┬───┬───┬───┐  ┌───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │  │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │  │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │   │   │Sft│Alt│Clt│   │  │   │Ctl│Alt│Sft│   │   │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │  │   │   │   │   │   │   │
     * └───┴───┼───┼───┼───┼───┘  └───┼───┼───┼───┼───┴───┘
     *         │   │   │   ├───┐  ┌───┤   │   │   │
     *         └───┼───┼───┤   Caps   ├───┼───┼───┘
     *             │   │   │   Lock   │   │   │
     *             └───┴───┴───┘  └───┴───┴───┘
     */
    [BaseLyr] = LAYOUT(
        KC_1,    KC_2,   KC_3,         KC_4,         KC_5,         KC_6,              _______, /**/ _______, KC_7,     KC_8,         KC_9,         KC_0,         KC_MINUS, KC_EQUAL,
        KC_TAB,  KC_Q,   KC_W,         KC_E,         KC_R,         KC_T,              _______, /**/ _______, KC_Y,     KC_U,         KC_I,         KC_O,         KC_P,     KC_LBRC,
        KC_GRV,  KC_A,   LSFT_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), KC_G,              _______, /**/ _______, KC_H,     RCTL_T(KC_J), RALT_T(KC_K), RSFT_T(KC_L), KC_SCLN,  KC_QUOTE,
        KC_BSLS, KC_Z,   KC_X,         KC_C,         KC_V,         KC_B,              _______, /**/ _______, KC_N,     KC_M,         KC_COMMA,     KC_DOT,       KC_SLASH, KC_RBRC,
        KC_LWIN, KC_DEL, KC_PSCR,      KC_LEFT,      KC_RIGHT,     LT(FnLyr, KC_ESC), KC_MPLY, /**/ KC_MUTE, KC_ENTER, KC_BSPC,      KC_RWIN,      KC_SPACE,     KC_UP,    KC_DOWN
    ),
    /*
     * --------------------- LT(FnLyr, Esc) ---------------------
     *
     * ┌───┬───┬───┬───┬───┬───┐  ┌───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │󰃝  │󰃠  │  │ 󰒮 │ 󰐎 │ 󰒭 │ 󰝟 │ 󰝞 │ 󰝝 │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │F1 │F2 │F3 │F4 │F5 │F6 │  │F7 │F8 │F9 │F10│F11│F12│
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │   │   │Sft│Alt│Clt│   │  │   │Ctl│Alt│Sft│   │   │
     * ├───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │  │   │   │   │   │   │   │
     * └───┴───┼───┼───┼───┼───┘  └───┼───┼───┼───┼───┴───┘
     *         │Win│Del│PSc├───┐  ┌───┤Ret│BSp│Win│
     *         └───┼───┼───┤   │  │   ├───┼───┼───┘
     *             │ ← │ → │---│  │Spc│ ↑ │ ↓ │
     *             └───┴───┴───┘  └───┴───┴───┘
     */
    [FnLyr] = LAYOUT(
        _______, _______, _______, _______, KC_BRID,  KC_BRIU, _______, /**/ _______, KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD, KC_VOLU,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   _______, /**/ _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
        _______, _______, KC_LSFT, KC_LALT, KC_LCTL,  _______, _______, /**/ _______, _______,  KC_RCTL, KC_RALT, KC_RSFT,  _______, _______,
        _______, _______, _______, _______, _______,  _______, _______, /**/ _______, _______,  _______, _______, _______,  _______, _______,
        KC_LWIN, KC_DEL,  KC_PSCR, KC_LEFT, KC_RIGHT, _______, _______, /**/ _______, KC_ENTER, KC_BSPC, KC_RWIN, KC_SPACE, KC_UP,   KC_DOWN
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
