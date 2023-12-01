// Custom config settings for @geewiz
#pragma once

/* Key combos */
#define COMBO_TERM 50
#define COMBO_VARIABLE_LEN

// Time (in ms) before one shot keys are released
#define ONESHOT_TIMEOUT 3000

// Leader key
#define LEADER_TIMEOUT 500

// Media keys
#define MEDIA_KEY_DELAY 10

// Mouse keys
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

// Auto-shift
#ifdef AUTO_SHIFT_ENABLE
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP
#endif
