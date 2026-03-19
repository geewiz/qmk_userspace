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
     XXXXXXX, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_BSPC, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                     KC_M   , KC_N   , KC_E   , KC_I   , O_NAV  , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_MUTE,   KC_HOME, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, LY_MOUS, LY_NUMB, KC_LSFT,       KC_SPC , LY_SYMB, LY_MEDI, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),
#else
  [_DEFAULT] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                     KC_H   , KC_J   , KC_K   , KC_L   , BSP_NAV, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_MUTE,   KC_HOME, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, LY_MOUS, LY_NUMB, KC_LSFT,       KC_SPC , LY_SYMB, LY_MEDI, XXXXXXX \
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
                              XXXXXXX, KC_ESC , _______, KC_SPC ,       KC_LSFT, _______, XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_NAVI] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, OS_RGUI, OS_RALT, OS_RCTL, OS_RSFT, KC_RGUI,                     KC_TAB , KC_ESC , SW_WIN , CW_TOGG, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, KC_LGUI,                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     _______, U_UND  , U_CUT  , U_CPY  , U_PST  , KC_INS , XXXXXXX,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_DEL , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_BSPC, KC_ENT , XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_SYMBOL] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_PIPE, KC_RCBR,                     KC_TILD, KC_QUOT, KC_DQUO, KC_EQL , KC_GRV , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, KC_LPRN, KC_DLR , KC_PERC, KC_CIRC, KC_RPRN,                     XXXXXXX, KC_MINS, KC_PLUS, KC_LABK, KC_RABK, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     _______, KC_LBRC, KC_EXLM, KC_AT  , KC_HASH, KC_RBRC, XXXXXXX,   XXXXXXX, XXXXXXX, KC_UNDS, KC_SCLN, KC_COLN, KC_BSLS, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, XXXXXXX, LY_ADJT, XXXXXXX,       XXXXXXX, _______, XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_NUMBER] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_ASTR, KC_7   , KC_8   , KC_9   , KC_SLSH, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX,                     KC_MINS, KC_4   , KC_5   , KC_6   , KC_0   , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_PLUS, KC_1   , KC_2   , KC_3   , KC_DOT , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, XXXXXXX, _______, XXXXXXX,       KC_BSPC, LY_ADJT, XXXXXXX, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_MOUSE] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, WKSP1  , WKSP2  , WKSP3  , WKSP4  , WKSP5  ,                     WKSP6  , WKSP7  , WKSP8  , WKSP9  , WKSP0  , XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     _______, U_UND  , U_CUT  , U_CPY  , U_PST  , XXXXXXX, XXXXXXX,   XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, _______, XXXXXXX, XXXXXXX,       MS_BTN1, MS_BTN3, MS_BTN2, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_MEDIA] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     _______, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, _______, XXXXXXX \
/*                          |--------+--------+--------|--------/     \--------|--------+--------+--------|                          */
  ),

  [_ADJUST] = LAYOUT( \
/* ,-----------------------------------------------------.                   ,-----------------------------------------------------. */
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PAUS,                     TG_GAME, UG_TOGG, UG_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_PSCR,                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------|--------. .--------|--------+--------+--------+--------+--------+--------| */
     XXXXXXX, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_SCRL, XXXXXXX,   XXXXXXX, XXXXXXX, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, XXXXXXX, \
/* |--------+--------+--------+--------+--------+--------/-------/   \-------\--------+--------+--------+--------+--------+--------| */
                              XXXXXXX, XXXXXXX, _______, QK_BOOT,       QK_BOOT, _______, XXXXXXX, XXXXXXX \
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
