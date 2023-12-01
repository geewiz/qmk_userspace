/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

#define EE_HANDS
#define SPLIT_USB_DETECT

#ifdef OLED_ENABLE
#    define SPLIT_OLED_ENABLE
#    define OLED_TIMEOUT 10000
#    define OLED_DISABLE_TIMEOUT // Prevent matrix_changed triggering oled_on()
#    define OLED_UPDATE_INTERVAL 50
#    define OLED_BRIGHTNESS 180
#    define OLED_FONT_H "keyboards/crkbd/keymaps/geewiz/glcdfont.c"
#endif

#ifdef RGB_MATRIX_ENABLE
#  define RGB_DISABLE_WHEN_USB_SUSPENDED true
#  define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#  define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_ALPHAS_MODS
#  define RGB_MATRIX_STARTUP_HUE 85
#  define RGB_MATRIX_STARTUP_SAT 135
#  define RGB_MATRIX_STARTUP_VAL 50
#  define RGB_MATRIX_STARTUP_SPD 201

#  define RGB_MATRIX_KEYPRESSES
#  define ENABLE_RGB_MATRIX_SOLID_COLOR
#  define ENABLE_RGB_MATRIX_ALPHAS_MODS
#  define ENABLE_RGB_MATRIX_BREATHING
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLED_NUM 27
    // Save memory by enabling individually instead of all RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
