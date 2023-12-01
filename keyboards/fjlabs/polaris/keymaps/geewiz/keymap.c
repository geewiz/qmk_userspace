/*
Copyright 2020 <me@fjlaboratories.com>
Copyright 2022 <contact@geewiz.dev>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "geewiz.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_60_tsangan_hhkb(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS, KC_GRV ,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSPC,
        ESC_CTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, LY_ADJT,
        XXXXXXX, KC_LGUI, KC_LALT,          KC_SPC ,                   KC_RALT, KC_RGUI, XXXXXXX
    ),

    [_GAME] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX, _______,          _______,                   _______, KC_LGUI, XXXXXXX
    ),

    [_MOUSE] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, _______,
        _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, _______, _______, KC_WH_L, KC_WH_U, KC_MS_L, KC_MS_R, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_R, KC_WH_D, KC_MS_D, _______, _______,
        XXXXXXX, _______, _______,          _______,                   _______, _______, XXXXXXX
    ),

    [_ADJUST] = LAYOUT_60_tsangan_hhkb(
        QK_BOOT, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_DEL ,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP  , _______, _______,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, TG_GAME, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_END , KC_PGDN, KC_DOWN, _______, _______,
        XXXXXXX, _______, _______,          LY_MOUS,                   _______, _______, XXXXXXX
    )
};
