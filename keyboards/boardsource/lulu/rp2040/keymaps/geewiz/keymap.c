// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// Copyright 2022 Jochen Lillich <hello@geewiz.dev>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "geewiz.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#if defined(GEEWIZ_COLEMAK)
  [_DEFAULT] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT   , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                     KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_MUTE,   KC_HOME, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, LY_NUMB, LY_NAVI, KC_LSFT,       KC_SPC , LY_SYMB, XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),
#else
  [_DEFAULT] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                     KC_H   , KC_J   , KC_K   , KC_L   , KC_QUOT, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_MUTE,   KC_HOME, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, LY_NUMB, LY_NAVI, KC_LSFT,       KC_SPC , LY_SYMB, XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),
#endif

  [_GAME] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_MUTE,   KC_HOME, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT , \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              LY_NAVI, KC_LALT, KC_SPC , KC_LSFT,       KC_SPC , LY_SYMB, XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_NAVI] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, OS_RGUI, OS_RALT, OS_RCTL, OS_RSFT, KC_RGUI,                     KC_TAB , KC_ESC , SW_WIN , XXXXXXX, CW_TOGG, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, KC_LGUI,                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     _______, U_UND  , U_CUT  , U_CPY  , U_PST  , KC_INS , XXXXXXX,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_DEL , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, XXXXXXX, _______, XXXXXXX,       KC_BSPC, KC_ENT , XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_SYMBOL] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_GRV , KC_RCBR,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, KC_LPRN, KC_DLR , KC_PERC, KC_CIRC, KC_RPRN,                     KC_TILD, KC_MINS, KC_PLUS, KC_EQL , XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     _______, KC_LBRC, KC_EXLM, KC_AT  , KC_HASH, KC_RBRC, XXXXXXX,   XXXXXXX, XXXXXXX, KC_UNDS, KC_SCLN, KC_COLN, KC_BSLS, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, XXXXXXX, LY_ADJT, LY_NUMB,       XXXXXXX, _______, XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_NUMBER] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_SLSH, KC_7   , KC_8   , KC_9   , KC_MINS, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX,                     KC_ASTR, KC_4   , KC_5   , KC_6   , KC_PLUS, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_EQL , KC_1   , KC_2   , KC_3   , XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, _______, XXXXXXX, XXXXXXX,       KC_BSPC, KC_0   , KC_DOT , XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_MOUSE] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, DESK_1 , DESK_2 , DESK_3 , DESK_4 , DESK_5 ,                     DESK_6 , DESK_7 , DESK_8 , DESK_9 , DESK_0 , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     _______, U_UND  , U_CUT  , U_CPY  , U_PST  , XXXXXXX, XXXXXXX,   XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              _______, XXXXXXX, XXXXXXX, XXXXXXX,       KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_MEDIA] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX,                     XXXXXXX, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, _______ \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_ADJUST] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PAUS,                     TG_GAME, TG_RGB , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_PSCR,                     XXXXXXX, OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_SCRL, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, XXXXXXX, _______, QK_BOOT,       QK_BOOT, _______, XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_RGB] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, TG_RGB , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),
};

#ifdef ACHORDION_ENABLE
// Exceptions for the opposite hands rule
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Allow same-hand holds for thumb keys
  if (tap_hold_record->event.key.row == 4) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    // Standard QMK hold behaviour for thumb keys
    case ESC_MED:
    case BSP_NAV:
    case TAB_MSE:
    case ENT_ADJ:
    case SPC_SYM:
    case DEL_NUM:
      return 0;
  }

  return 800;  // Reasonable default timeout
}
#endif

#ifdef OLED_ENABLE
static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("\nLayer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _DEFAULT: oled_write_P(PSTR("DEFAULT\n"), false); break;
        case _COLEMAK: oled_write_P(PSTR("COLEMAK\n"), false); break;
        case _SYMBOL: oled_write_P(PSTR("SYMBOL\n"), false); break;
        case _NAVI: oled_write_P(PSTR("NAVIGATION\n"), false); break;
        case _NUMBER: oled_write_P(PSTR("NUMBER\n"), false); break;
        case _ADJUST: oled_write_P(PSTR("ADJUST\n"), false); break;
        case _MEDIA: oled_write_P(PSTR("MEDIA\n"), false); break;
        case _MOUSE: oled_write_P(PSTR("MOUSE\n"), false); break;
        case _GAME: oled_write_P(PSTR("GAME\n"), false); break;
        default: oled_write_ln_P(PSTR("N/A"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

void render_logo_user(void) {
    static const char PROGMEM logo[] = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0x60, 0x60, 0x60,
      0x60, 0x60, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
      0x00, 0xe0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xfc, 0x1e, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x80, 0xc0,
      0x80, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0xfc, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff,
      0xe0, 0xc0, 0x80, 0x80, 0xc0, 0xc0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
      0x00, 0x1f, 0xff, 0xff, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0xe0, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x78, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x01,
      0x01, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0x78, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03,
      0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(logo, sizeof(logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo_user();
    }
    return false;
}
#endif
