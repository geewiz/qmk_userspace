#include QMK_KEYBOARD_H
#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_planck_grid(
      KC_Q   , KC_W,    KC_E,    KC_R,    KC_T,    WKSPPRE, WKSPNXT, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
      KC_A   , KC_S,    KC_D,    KC_F,    KC_G,    WINLEFT, WINRGHT, KC_H   , KC_J   , KC_K   , KC_L   , BSP_NAV,
      KC_Z   , KC_X   , KC_C,    KC_V,    KC_B,    _______, _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
      KC_MUTE, LY_MOUS, KC_LGUI, LY_NUMB, KC_NO  , KC_LSFT, KC_NO  , KC_SPC , LY_SYMB, KC_LCTL, XXXXXXX, XXXXXXX
    ),

    [_NAVI] = LAYOUT_planck_grid(
      OS_RGUI, OS_RALT, OS_RCTL, OS_RSFT, XXXXXXX, _______, _______, KC_TAB , KC_ESC , SW_WIN , CW_TOGG, XXXXXXX,
      OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
      KC_UNDO, KC_CUT , KC_COPY, KC_PSTE, KC_INS , _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_DEL ,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO  , _______, KC_NO  , KC_BSPC, KC_ENT , XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_SYMBOL] = LAYOUT_planck_grid(
      KC_LCBR, KC_AMPR, KC_ASTR, KC_PIPE, KC_RCBR, _______, _______, XXXXXXX, KC_QUOT, KC_DQUO, XXXXXXX, KC_GRV ,
      KC_LPRN, KC_DLR , KC_PERC, KC_CIRC, KC_RPRN, _______, _______, KC_TILD, KC_MINS, KC_PLUS, KC_EQL , KC_QUES,
      KC_LBRC, KC_EXLM, KC_AT  , KC_HASH, KC_RBRC, _______, _______, XXXXXXX, KC_UNDS, KC_SCLN, KC_COLN, KC_BSLS,
      XXXXXXX, XXXXXXX, XXXXXXX, LY_ADJT, KC_NO  , XXXXXXX, KC_NO  , XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NUMBER] = LAYOUT_planck_grid(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_7   , KC_8   , KC_9   , KC_EQL ,
      OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX, _______, _______, KC_MINS, KC_4   , KC_5   , KC_6   , KC_ASTR,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PLUS, KC_1   , KC_2   , KC_3   , KC_SLSH,
      XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_NO  , XXXXXXX, KC_NO  , KC_BSPC, KC_0   , KC_DOT , XXXXXXX, XXXXXXX
    ),

    [_MOUSE] = LAYOUT_planck_grid(
      RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, U_RDO  , U_PST  , U_CPY  , U_CUT  , U_UND  ,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
      XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_NO  , XXXXXXX, KC_NO  , KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX
    ),

    [_MEDIA] = LAYOUT_planck_grid(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, _______, _______, _______, KC_NO  , _______, KC_NO  , KC_MSTP, KC_MPLY, KC_MUTE, _______, _______
    ),

    [_ADJUST] = LAYOUT_planck_grid(
      KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PAUS, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
      KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_PSCR, _______, _______, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_SCRL, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_MUTE, XXXXXXX, XXXXXXX, _______, KC_NO  , QK_BOOT, KC_NO  , QK_BOOT, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  // Note that layer keys need achordion_timeout disabled below
  switch (get_highest_layer(layer_state)) {
    case _SYMBOL:
      clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
      break;
    case _NUMBER:
      clockwise ? tap_code16(C(KC_TAB)) : tap_code16(S(C(KC_TAB)));
      break;
    case _ADJUST:
      clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
      break;
    default:
      clockwise ? tap_code(KC_WH_D) : tap_code(KC_WH_U);
      break;
  }
  return false;
}
#endif
