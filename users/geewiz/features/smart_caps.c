/***
* Smart Caps Lock
* Based on work from @dnaq and @iaap on the splitkb.com Discord.
***/

#include "smart_caps.h"

static bool smart_caps_enabled = false;

void enable_smart_caps(void) {
    smart_caps_enabled = true;
    tap_code(KC_CAPS);
}

void disable_smart_caps(void) {
    smart_caps_enabled = false;
    tap_code(KC_CAPS);
}

void toggle_smart_caps(void) {
    if (smart_caps_enabled) {
        disable_smart_caps();
    } else {
        enable_smart_caps();
    }
}

bool process_smart_caps(uint16_t keycode, keyrecord_t *record) {
    if (smart_caps_enabled) {
        // first strip off the mod taps and layer taps if needed
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                if (record->tap.count == 0)
                    return true;
                keycode = keycode & 0xFF;
        }
        switch (keycode) {
            case U_SMCL:
                if (record->event.pressed) {
                    toggle_smart_caps();
                }
                return false;
            // we end caps lock on one of the following keypresses
            case KC_ESC:
            case KC_ENT:
            case KC_TAB:
            case KC_DOT:
            case KC_COMM:
                if (record->event.pressed) {
                    disable_smart_caps();
                }
                return true;
            // Turn space into underscore
            case KC_SPC:
                // _ on space
                if (record->event.pressed) {
                    register_code16(KC_UNDS);
                } else {
                    unregister_code16(KC_UNDS);
                }
                return false;
        }
    }

    return true;
}
