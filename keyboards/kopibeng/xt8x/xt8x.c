/* Copyright 2021 Samuel Lu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

void matrix_init_kb(void) {
	// Initialize indicator LEDs to output
    
    gpio_set_pin_output(LED_CAPS_LOCK_PIN); // Caps
	gpio_set_pin_output(LED_SCROLL_LOCK_PIN); // Scroll lock
    gpio_set_pin_output(INDICATOR_PIN_0); // Layer indicator on F13

	matrix_init_user();
}

bool led_update_kb(led_t led_state) {

    bool res = led_update_user(led_state);

    if(res) {
        gpio_write_pin(LED_CAPS_LOCK_PIN, led_state.caps_lock);
        gpio_write_pin(LED_SCROLL_LOCK_PIN, led_state.scroll_lock);
    }
    return res;
}

__attribute__((weak)) layer_state_t layer_state_set_user(layer_state_t state) {
  gpio_write_pin(INDICATOR_PIN_0, layer_state_cmp(state, 1));
  return state;
}
