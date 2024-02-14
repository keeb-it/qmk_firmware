// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "hammer40.h"

#define RGB_ENABLE_PIN GP11
#define RGB_DEFAULT_COLOR HSV_GREEN

// ===== LED/RGB INDICATOR =====
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_BLUE}
);

const rgblight_segment_t PROGMEM capsword_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_WHITE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
   [RGBL_CAPSL] =  capslock_layer,
   [RGBL_CAPSW] =  capsword_layer
);

bool led_update_kb(led_t led_state) {
    if (!led_update_user(led_state)) {
        return false;
    }
    rgblight_set_layer_state(RGBL_CAPSL, led_state.caps_lock);
    return true;
}

__attribute__((weak)) void caps_word_set_user(bool active) {
    rgblight_set_layer_state(RGBL_CAPSW, active);
}

void keyboard_post_init_kb(void) {
    // Set LED color at the startup; by default it's red
    rgblight_sethsv(RGB_DEFAULT_COLOR);

    // Enable the on-board WS2812 LED
    setPinOutput(RGB_ENABLE_PIN);
    writePin(RGB_ENABLE_PIN, true);
    wait_ms(30);

    // Enable the LED layers
    rgblight_layers = rgb_layers;
    keyboard_post_init_user();
}
