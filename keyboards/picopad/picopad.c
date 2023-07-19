#include QMK_KEYBOARD_H

enum RGB_LAYERS {
    RGBL_CAPS = 0
};

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_BLUE}       // Light 4 LEDs, starting with LED 6
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
   [RGBL_CAPS] =  my_capslock_layer
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(RGBL_CAPS, led_state.caps_lock);
    return true;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

