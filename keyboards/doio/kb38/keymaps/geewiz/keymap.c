/* Copyright 2021 Katrina (@PepperKats)
 * Copyright 2023 geewiz (@geewiz)
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

enum layers {
    _DEFAULT,
    _RESOLVE,
    _SHOTCUT,
    _TRUCKSIM,
    _FUNCTION,
};

#ifdef OLED_ENABLE
#include "oled.c"
#endif

// DaVinci Resolve keycodes
#define DR_RDEL  KC_DEL
#define DR_SPLIT C(KC_BSLS)
#define DR_UNDO  C(KC_Z)
#define DR_PMEDI S(KC_2)
#define DR_PCUT  S(KC_3)
#define DR_PEDIT S(KC_4)
#define DR_PDLVR S(KC_8)
#define DR_APETL S(KC_F12)  // Append to end of timeline
#define DR_SELCL S(KC_V)    // Select clip

// Shotcut keycodes
#define SC_UNDO C(KC_Z)
#define SC_SKPL A(KC_LEFT) // Skip to previous clip
#define SC_SKPR A(KC_RIGHT) // Skip to next clip
#define SC_CUT  C(KC_X)
#define SC_COPY C(KC_C)
#define SC_PSTE C(KC_V)
#define SC_FRZF C(S(KC_H)) // Freeze frame
#define SC_DELC KC_BSPC // Delete clip
#define SC_LIFT KC_Z // Lift clip
#define SC_RDEL KC_X // Ripple delete

// ETS2 keycodes
#define ET_STEA S(KC_TAB)

// System keycodes
#define WS_1 LGUI(KC_1)
#define WS_2 LGUI(KC_2)
#define WS_3 LGUI(KC_3)
#define WS_4 LGUI(KC_4)
#define WS_5 LGUI(KC_5)
#define WS_6 LGUI(KC_6)
#define WS_7 LGUI(KC_7)
#define WS_8 LGUI(KC_8)
#define WS_9 LGUI(KC_9)
#define WS_10 LGUI(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        // Default
        TO(_RESOLVE),       KC_BSPC ,              KC_F10  , KC_F11  , KC_F12  ,    KC_F13 , KC_F14 , KC_F15 ,
        KC_NUM  , KC_PSLS , KC_PAST , KC_PMNS ,    KC_F7   , KC_F8   , KC_F9   ,
        KC_P7   , KC_P8   , KC_P9   , KC_PPLS ,    KC_F4   , KC_F5   , KC_F6   ,    KC_HOME,          KC_MUTE,
        KC_P4   , KC_P5   , KC_P6   ,              KC_F1   , KC_F2   , KC_F3   ,
        KC_P1   , KC_P2   , KC_P3   , KC_PENT ,              KC_UP   ,                       KC_NO  ,
        KC_P0   ,           KC_PDOT ,              KC_LEFT , KC_DOWN , KC_RGHT
    ),
    [_RESOLVE] = LAYOUT(
        // Davinci Resolve
        TO(_SHOTCUT),       DR_UNDO ,              KC_A    , KC_B    , KC_T    ,    DR_PMEDI, DR_PCUT , DR_PEDIT,
        KC_NUM  , KC_BSPC , KC_PAST , DR_RDEL ,    KC_I    , DR_APETL, KC_O    ,
        KC_P7   , KC_P8   , KC_P9   , KC_SLSH ,    KC_LCBR , DR_SPLIT, KC_RCBR ,    KC_HOME ,           KC_END  ,
        KC_P4   , KC_P5   , KC_P6   ,              KC_J    , KC_K    , KC_L    ,
        KC_P1   , KC_P2   , KC_P3   , DR_SELCL,              KC_UP   ,                        KC_NO   ,
        KC_P0   ,           KC_PDOT ,              KC_LEFT , KC_DOWN , KC_RGHT
    ),
    [_SHOTCUT] = LAYOUT(
        // Shotcut
        TO(_TRUCKSIM),      SC_UNDO ,              SC_CUT  , SC_COPY , SC_PSTE ,    SC_FRZF , KC_NO   , KC_NO   ,
        KC_NUM  , SC_DELC , SC_LIFT , SC_RDEL ,    KC_I    , KC_NO   , KC_O    ,
        KC_P7   , KC_P8   , KC_P9   , KC_B    ,    KC_LCBR , KC_S    , KC_RCBR ,    KC_HOME ,           KC_END  ,
        KC_P4   , KC_P5   , KC_P6   ,              KC_J    , KC_K    , KC_L    ,
        KC_P1   , KC_P2   , KC_P3   , KC_PENT ,              SC_SKPL ,                        KC_NO   ,
        KC_P0   ,           KC_PDOT ,              KC_LEFT , SC_SKPR , KC_RGHT
    ),
    [_TRUCKSIM] = LAYOUT(
        // Euro Truck Simulator
        TO(_FUNCTION),       KC_ESC  ,              KC_P    , KC_O    , KC_L    ,    KC_M   , KC_HOME, KC_R   ,
        KC_U    , KC_SLSH , KC_ASTR , KC_T    ,    KC_F7   , KC_F8   , KC_F9   ,
        KC_7    , KC_8    , KC_9    , KC_SPC  ,    KC_F4   , KC_F5   , KC_F6   ,    ET_STEA,          KC_MUTE,
        KC_4    , KC_5    , KC_6    ,              KC_F1   , KC_F2   , KC_F3   ,
        KC_1    , KC_2    , KC_3    , KC_ENT  ,              KC_UP   ,                       KC_NO  ,
        KC_E    ,           KC_DOT  ,              KC_LEFT , KC_DOWN , KC_RGHT
    ),
    [_FUNCTION] = LAYOUT(
        TO(_DEFAULT),       KC_NO   ,              RGB_RMOD, RGB_TOG , RGB_MOD ,    KC_NO   , QK_RBT  , QK_BOOT,
        KC_NO   , KC_NO   , KC_NO   , KC_NO   ,    KC_NO   , KC_NO   , KC_NO   ,
        WS_7    , WS_8    , WS_9    , KC_NO   ,    KC_NO   , KC_NO   , KC_NO   ,    RGB_TOG ,           KC_MUTE ,
        WS_4    , WS_5    , WS_6    ,              KC_NO   , KC_NO   , KC_NO   ,
        WS_1    , WS_2    , WS_3    , KC_NO   ,              KC_UP   ,                        KC_NO   ,
        WS_10   ,           KC_PDOT ,              KC_LEFT , KC_DOWN , KC_RGHT
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // Encoder order: small right, small left, big
    // Default
    [_DEFAULT] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)
    },
    // DaVince Resolve
    [_RESOLVE] = {
        // Zoom out, zoom in
        ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)),
        // 1 s back, 1 s forward
        ENCODER_CCW_CW(S(KC_LEFT), S(KC_RGHT)),
        // Frame back, frame forward
        ENCODER_CCW_CW(KC_LEFT, KC_RGHT)
    },
    // Shotcut
    [_SHOTCUT] = {
        // Zoom out, zoom in
        ENCODER_CCW_CW(KC_MINS, KC_PLUS),
        // 1 s back, 1 s forward
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        // Frame back, frame forward
        ENCODER_CCW_CW(KC_LEFT, KC_RGHT)
    },
    [_TRUCKSIM] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)
    },
    [_FUNCTION] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),
        ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)
    }
};
#endif
