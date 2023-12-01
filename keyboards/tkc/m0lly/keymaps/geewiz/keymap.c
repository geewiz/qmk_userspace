/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
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

#include QMK_KEYBOARD_H
#include "geewiz.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer
     *
     * ,-----------------------------------------------------------. .-------------------.
     * |Esc| 1 |  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `| |NumL| /  | *  | -  |
     * |-----------------------------------------------------------| |-------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Bsp | | 7  | 8  | 9  |    |
     * |-----------------------------------------------------------| |--------------| +  |
     * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return | | 4  | 5  | 6  |    |
     * |-----------------------------------------------------------| |-------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn | | 1  | 2  | 3  | Ent|
     * |-----------------------------------------------------------| |--------------|    |
     * |Lead |Win  |Alt  |      Space            |Alt  |Win  |Lead | |   0     | .  |    |
     * `-----------------------------------------------------------' '-------------------'
     */
    [_DEFAULT] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV ,     KC_NUM , KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,              KC_P7,   KC_P8,   KC_P9,   XXXXXXX,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,               KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, LY_ADJT,              KC_P1,   KC_P2,   KC_P3,   XXXXXXX,
        LY_DESK, KC_LGUI, KC_LALT,                            KC_SPC,                             XXXXXXX, KC_RALT, KC_RGUI, KC_HYPR,              KC_P0,   XXXXXXX, KC_PDOT, KC_PENT
    ),

    [_DESKTOP] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              DESK_7 , DESK_8 , DESK_9 , XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,              DESK_4 , DESK_5 , DESK_6 , XXXXXXX,
        _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              DESK_1 , DESK_2 , DESK_3 , XXXXXXX,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______,              DESK_0 , XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_ADJUST] = LAYOUT_all(
        QK_BOOT, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_INS , KC_DEL ,     _______, _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP  , _______, _______,              _______, _______, _______, XXXXXXX,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, XXXXXXX, _______,              _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END , KC_PGDN, KC_DOWN, QK_LEAD, _______,              _______, _______, _______, XXXXXXX,
        _______, _______, _______,                            _______,                            _______, _______, XXXXXXX, _______,              _______, XXXXXXX, _______, _______
    )
};
