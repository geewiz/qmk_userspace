 /* Copyright 2021 Jochen Lillich
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

#include "keymap.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT(
  //,--------------------------------------------.                  ,--------------------------------------------.
      KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                    KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
  //|--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
      KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                    KC_H   , KC_J   , KC_K   , KC_L   , BSP_NAV,
  //|--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
      KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX,  XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
  //|--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, LY_MOUS, LY_NUMB, KC_LSFT , KC_SPC , LY_SYMB, LY_MEDI, XXXXXXX, XXXXXXX, XXXXXXX
  //`-----------------------------------------------------'`-----------------------------------------------------'
  ),

  [_NAVI] = LAYOUT(
  //,--------------------------------------------.                  ,--------------------------------------------.
      OS_RGUI, OS_RALT, OS_RCTL, OS_RSFT, KC_RGUI,                    KC_TAB , KC_ESC , SW_WIN , CW_TOGG, XXXXXXX,
  //|--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
      OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, KC_LGUI,                    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
      KC_UNDO, KC_CUT , KC_COPY, KC_PSTE, KC_INS , XXXXXXX,  XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_DEL ,
  //|--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,  KC_BSPC, KC_ENT , _______, _______, _______, _______
  //`-----------------------------------------------------'`-----------------------------------------------------'
  ),

  [_SYMBOL] = LAYOUT(
  //,--------------------------------------------.                  ,--------------------------------------------.
      KC_LCBR, KC_AMPR, KC_ASTR, KC_PIPE, KC_RCBR,                    KC_TILD, KC_QUOT, KC_DQUO, KC_EQL , KC_GRV ,
  //|--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
      KC_LPRN, KC_DLR , KC_PERC, KC_CIRC, KC_RPRN,                    XXXXXXX, KC_MINS, KC_PLUS, KC_LABK, KC_RABK,
  //|--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
      KC_LBRC, KC_EXLM, KC_AT  , KC_HASH, KC_RBRC, XXXXXXX,  XXXXXXX, XXXXXXX, KC_UNDS, KC_SCLN, KC_COLN, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, LY_ADJT, _______,  _______, _______, _______, _______, _______, _______
  //`-----------------------------------------------------'`-----------------------------------------------------'
  ),

  [_NUMBER] = LAYOUT(
  //,--------------------------------------------.                  ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_ASTR, KC_7   , KC_8   , KC_9   , KC_SLSH,
  //|--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
      OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX,                    KC_MINS, KC_4   , KC_5   , KC_6   , KC_0   ,
  //|--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_PLUS, KC_1   , KC_2   , KC_3   , KC_DOT ,
  //|--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,  KC_BSPC, LY_ADJT, _______, _______, _______, _______
  //`-----------------------------------------------------'`-----------------------------------------------------'
  ),

  [_MEDIA] = LAYOUT(
  //,--------------------------------------------.                  ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
      KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
      KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______
  //`-----------------------------------------------------'`-----------------------------------------------------'
  ),

  [_MOUSE] = LAYOUT(
  //,--------------------------------------------.                  ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    U_RDO  , U_PST  , U_CPY  , U_CUT  , U_UND  ,
  //|--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                    MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,  MS_BTN1, MS_BTN3, MS_BTN2, _______, _______, _______
  //`-----------------------------------------------------'`-----------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT(
  //,--------------------------------------------.                  ,--------------------------------------------.
      KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PAUS,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------|
      KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_PSCR,                    XXXXXXX, OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI,
  //|--------+--------+--------+--------+--------+--------.,--------+--------+--------+--------+--------+--------|
      KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_SCRL, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, _______, QK_BOOT,  QK_BOOT, _______, _______, _______, _______, _______
  //`-----------------------------------------------------'`-----------------------------------------------------'
  ),
};
// clang-format on
