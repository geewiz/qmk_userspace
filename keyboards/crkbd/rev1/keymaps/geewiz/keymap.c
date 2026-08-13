/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2025 Jochen Lillich <jochen@lillich.co>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap.h"

extern uint8_t is_master;

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

#ifdef OLED_ENABLE
#include "oled.c"
#endif

enum {
  TD_NEXT_PREV,
  TD_VOLD_MUTE,
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_NEXT_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
  [TD_VOLD_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
};

#define TD_NXPR TD(TD_NEXT_PREV)
#define TD_VDMT TD(TD_VOLD_MUTE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, DH_A   , DH_S   , DH_D   , DH_F   , KC_G   ,                      KC_H   , DH_J   , DH_K   , DH_L   , DH_SCLN, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, ESC_NUM, SPC_NAV,    ENT_MSE, BSP_SYM, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAVI] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, OS_RGUI, OS_RALT, OS_RCTL, OS_RSFT, XXXXXXX,                      CW_TOGG, U_CUT  , U_CPY  , U_PST  , U_UND  , XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TAB , XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS ,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_DEL , XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOL] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_PIPE, KC_RCBR,                      XXXXXXX, KC_QUOT, KC_DQUO, XXXXXXX, KC_GRV , XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LPRN, KC_DLR , KC_PERC, KC_CIRC, KC_RPRN,                      KC_TILD, KC_MINS, KC_PLUS, KC_EQL , KC_QUES, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LBRC, KC_EXLM, KC_AT  , KC_HASH, KC_RBRC,                      XXXXXXX, KC_UNDS, KC_SCLN, KC_COLN, KC_BSLS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMBER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_ASTR, KC_7   , KC_8   , KC_9   , KC_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_MINS, KC_4   , KC_5   , KC_6   , KC_0   , XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PLUS, KC_1   , KC_2   , KC_3   , KC_DOT , XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, MS_WHLL, MS_WHLU, MS_UP  , MS_WHLD, MS_WHLR,                      _______, _______, _______, KC_LGUI, KC_LALT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______,                      _______, MS_BTN1, MS_BTN2, MS_BTN3, KC_LCTL, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, KC_LSFT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PAUS,                      TD_NXPR, TD_VDMT, KC_MPLY, KC_VOLU, UG_TOGG, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_PSCR,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_SCRL,                      UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, QK_BOOT, _______,    _______, QK_BOOT, _______ \
                                      //`--------------------------'  `--------------------------'
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUMBER, _MOUSE, _ADJUST);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD_NXPR:
      return 200;
    case TD_VDMT:
      return 150;
    default:
      return TAPPING_TERM;
  }
}

#ifdef ACHORDION_ENABLE
// Exceptions for the opposite hands rule
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Allow same-hand holds for thumb keys
  if (tap_hold_record->event.key.row >= 3) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    // Standard QMK hold behaviour for thumb keys
    case ESC_NUM:
    case SPC_NAV:
    case ENT_MSE:
    case BSP_SYM:
      return 0;
  }

  return 280;  // Reasonable default timeout
}
#endif
