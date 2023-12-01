#pragma once

#include QMK_KEYBOARD_H
#include "geewiz.h"

void toggle_smart_caps(void);
void enable_smart_caps(void);
void disable_smart_caps(void);
bool process_smart_caps(uint16_t keycode, keyrecord_t *record);
