/* Copyright (C) 2021 @filterpaper
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

/* Graphical active layer and modifier status display. Module can be
   rendered on primary OLED or without layer state on secondary.

   Modified from @soundmonster's graphical status code
   (keyboards/crkbd/keymaps/soundmonster)
*/

#include "keymap.h"

__attribute__((weak)) oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void render_corne_logo(void) {
    static const char PROGMEM font_logo[16] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(font_logo, false);
};

void render_qmk_logo(void) {
    static const char PROGMEM font_qmk_logo[16] = {0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0};
    oled_write_P(font_qmk_logo, false);
};

static void render_status(void) {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _DEFAULT:
                oled_write_P(PSTR("DEFAULT\n"), false);
                break;
            case _GAME:
                oled_write_P(PSTR("GAME\n"), false);
                break;
            case _NAVI:
                oled_write_P(PSTR("NAVI\n"), false);
                break;
            case _NUMBER:
                oled_write_P(PSTR("NUMBER\n"), false);
                break;
            case _SYMBOL:
                oled_write_P(PSTR("SYMBOL\n"), false);
                break;
            case _MEDIA:
                oled_write_P(PSTR("MEDIA\n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("MOUSE\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("ADJUST\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        oled_write_P(PSTR("\n"), false);

        // Host Keyboard LED Status
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR("NUM  ") : PSTR("     "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPS  ") : PSTR("      "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRL  ") : PSTR("      "), false);
}

void render_logos(void) {
    oled_clear();

    oled_write_ln("", false);
    oled_write_ln("", false);

    render_corne_logo();

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_qmk_logo();
}

__attribute__((weak)) bool oled_task_user(void) {
    if (is_keyboard_master()) {
      render_status();
    } else {
      render_logos();
    }
    return false;
}
