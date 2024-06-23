/* Copyright (C) 2023 @geewiz
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

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _LAYERONE:
            oled_write_P(PSTR("ONE\n"), false);
            break;
        case _LAYERTWO:
            oled_write_P(PSTR("TWO\n"), false);
            break;
        case _LAYERTHREE:
            oled_write_P(PSTR("THREE\n"), false);
            break;
        case _LAYERFOUR:
            oled_write_P(PSTR("FOUR\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock ? PSTR("NUM  ") : PSTR("     "), false);
    oled_write_P(led_usb_state.caps_lock ? PSTR("CAPS  ") : PSTR("      "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRL  ") : PSTR("      "), false);
}

__attribute__((weak)) bool oled_task_user(void) {
    render_status();
    return false;
}
