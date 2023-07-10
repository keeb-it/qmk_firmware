// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


// ======================= Tap Dance =======================

enum {
    TD_MNXT_MPREV,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Media-Next, twice for Media-Previous
    [TD_MNXT_MPREV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
};

// ======================= Layers =======================

enum Layers {
    BaseLayer,
    FnLayer,
    NavLayer
};

enum CustomKeycodes {
    SS_LOREM = SAFE_RANGE,
};

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

// Thumb Keys
#define L_THUMB LT(NavLayer, KC_ESC)
#define R_THUMB LT(FnLayer, KC_SPACE)

// Rotary
#define L_ROT TD(TD_MNXT_MPREV)
#define R_ROT KC_MPLY

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SS_LOREM:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam interdum scelerisque velit non cursus. Morbi accumsan diam in mauris sagittis laoreet. Curabitur hendrerit tortor dapibus mattis mattis. Suspendisse sollicitudin nec dui id tincidunt. Nam pellentesque libero nisi, eget tempus mauris rutrum nec. Quisque scelerisque scelerisque libero id tempor. Donec lectus orci, dictum eu eros in, ornare viverra ex. Morbi blandit eleifend odio, eu ullamcorper augue mollis eget. Praesent ligula enim, mattis egestas rhoncus in, vehicula at lectus. Cras maximus eleifend sagittis. Fusce sit amet scelerisque tellus, placerat tempor magna. Nulla sagittis lobortis felis, et semper magna facilisis a. Maecenas laoreet mi sit amet eros placerat imperdiet.");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
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
    [BaseLayer] = LAYOUT(
        KC_1,    KC_2,   KC_3,    KC_4,    KC_5,     KC_6,    _______, /**/ _______, KC_7,     KC_8,    KC_9,     KC_0,    KC_MINUS, KC_EQUAL,
        KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,    _______, /**/ _______, KC_Y,     KC_U,    KC_I,     KC_O,    KC_P,     KC_LBRC,
        KC_GRV,  GUI_A,  ALT_S,   SFT_D,   CTL_F,    KC_G,    _______, /**/ _______, KC_H,     CTL_J,   SFT_K,    ALT_L,   GUI_SCLN, KC_QUOTE,
        KC_BSLS, KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,    _______, /**/ _______, KC_N,     KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_RBRC,
        KC_LWIN, KC_DEL, KC_PSCR, KC_LEFT, KC_RIGHT, L_THUMB, L_ROT,   /**/ R_ROT,   KC_ENTER, KC_BSPC, KC_RWIN,  R_THUMB, KC_UP,    KC_DOWN
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
    [FnLayer] = LAYOUT(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, /**/ _______, _______, _______, _______, _______, _______, _______,
        KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, /**/ _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______,
        SS_LOREM, _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______
    ),
    [NavLayer] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, /**/ _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, /**/ _______, KC_BRID, KC_BRIU, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, /**/ _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______,  _______, SS_LOREM,
        _______, _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______,  _______, _______
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
const uint16_t PROGMEM caps_combo[] = {L_THUMB, R_THUMB, COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO(caps_combo, KC_CAPS),
};

// ======================= Encoder =======================

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
