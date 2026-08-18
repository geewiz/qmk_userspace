#include QMK_KEYBOARD_H
#include "keymap.h"

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

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_planck_grid(
    'L', 'L', 'L', 'L', 'L', '*', '*', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', '*', '*', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', '*', '*', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', '*', '*', '*', '*', 'R', 'R', 'R', 'R'
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_planck_grid(
      KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , WKSPPRE, WKSPNXT, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
      DH_A   , DH_S   , DH_D   , DH_F   , KC_G   , WINLEFT, WINRGHT, KC_H   , DH_J   , DH_K   , DH_L   , DH_SCLN,
      KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______ , _______ , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
      KC_MUTE, XXXXXXX, KC_LGUI, XXXXXXX, SPC_NAV , ESC_NUM , ENT_MSE , BSP_SYM , XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX
    ),

    [_NAVI] = LAYOUT_planck_grid(
      OS_RGUI, OS_RALT, OS_RCTL, OS_RSFT, XXXXXXX, _______ , _______ , CW_TOGG, U_CUT  , U_CPY  , U_PST  , U_UND  ,
      OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX, _______ , _______ , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TAB ,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS , _______ , _______ , KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_DEL ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),

    [_SYMBOL] = LAYOUT_planck_grid(
      KC_LCBR, KC_AMPR, KC_ASTR, KC_PIPE, KC_RCBR, _______ , _______ , XXXXXXX, KC_QUOT, KC_DQUO, XXXXXXX, KC_GRV ,
      KC_LPRN, KC_DLR , KC_PERC, KC_CIRC, KC_RPRN, _______ , _______ , KC_TILD, KC_MINS, KC_PLUS, KC_EQL , KC_QUES,
      KC_LBRC, KC_EXLM, KC_AT  , KC_HASH, KC_RBRC, _______ , _______ , XXXXXXX, KC_UNDS, KC_SCLN, KC_COLN, KC_BSLS,
      _______ , _______ , _______ , LY_ADJT, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),

    [_NUMBER] = LAYOUT_planck_grid(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______ , _______ , KC_ASTR, KC_7   , KC_8   , KC_9   , KC_SLSH,
      OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX, _______ , _______ , KC_MINS, KC_4   , KC_5   , KC_6   , KC_0   ,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______ , _______ , KC_PLUS, KC_1   , KC_2   , KC_3   , KC_DOT ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),

    [_MOUSE] = LAYOUT_planck_grid(
      MS_WHLL, MS_WHLU, MS_UP  , MS_WHLD, MS_WHLR, _______ , _______ , _______ , _______ , _______ , KC_LGUI, KC_LALT,
      _______ , MS_LEFT, MS_DOWN, MS_RGHT, _______ , _______ , _______ , _______ , MS_BTN1, MS_BTN2, MS_BTN3, KC_LCTL,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_LSFT,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),

    [_ADJUST] = LAYOUT_planck_grid(
      KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PAUS, _______ , _______ , TD_NXPR, TD_VDMT, KC_MPLY, KC_VOLU, UG_TOGG,
      KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_PSCR, _______ , _______ , XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_SCRL, _______ , _______ , UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU,
      _______ , _______ , _______ , _______ , QK_BOOT, _______ , _______ , QK_BOOT, _______ , _______ , _______ , _______
    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
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
      clockwise ? tap_code(MS_WHLD) : tap_code(MS_WHLU);
      break;
  }
  return false;
}
#endif

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
