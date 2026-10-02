#include "kb.h"
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_UP, KC_DOT, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, TT(1),TT(2) , KC_LEFT, KC_DOWN, KC_RGHT),

	KEYMAP(
		KC_GRV,KC_7,KC_8,KC_9,KC_MINS,KC_F1,KC_F2,KC_F3,KC_F4,KC_LBRC,KC_RBRC,KC_BSPC,
		KC_CAPS,KC_4,KC_5,KC_6,KC_EQL,KC_F5,KC_F6,KC_F7,KC_SCLN,KC_QUOT,KC_ENT,
		KC_RSFT,KC_1,KC_2,KC_3,KC_PDOT,KC_F8,KC_F9,KC_F10,KC_SLSH,KC_PGUP,KC_BSLS,
		KC_RCTL,KC_RGUI,KC_0,KC_SPC,TT(1),KC_F11,KC_F12,KC_PGDN,KC_DEL),

	KEYMAP(
		TO(0),RM_SPDU,RM_SPDD,KC_BRIU,KC_BRID,KC_F13,KC_F14,KC_F15,KC_F16,KC_F17,KC_F18,KC_F19,
		_______,RM_TOGG,RM_PREV, RM_NEXT, RM_HUEU, RM_HUED, RM_SATU, RM_SATD, RM_VALU, RM_VALD,QK_BOOT,
		_______,KC_PSCR,KC_CUT,KC_COPY,KC_PASTE,NK_TOGG,XXXXXXX,XXXXXXX,KC_MPLY,KC_VOLU,KC_MUTE,
		KC_F20,KC_F21,KC_F22,KC_F23,KC_F24,TT(2),KC_MPRV,KC_VOLD,KC_MNXT),

};

static uint8_t mouse_keycode_for_fkey(uint16_t keycode) {
    switch (keycode) {
        case KC_F13: return MS_BTN1;
        case KC_F14: return MS_BTN2;
        case KC_F15: return MS_BTN3;
        case KC_F16: return MS_UP;
        case KC_F17: return MS_DOWN;
        case KC_F18: return MS_LEFT;
        case KC_F19: return MS_RGHT;
        case KC_F20: return MS_WHLU;
        case KC_F21: return MS_WHLD;
        default:     return KC_NO;
    }
}

void tap_code(uint8_t keycode) {
    uint8_t mouse_keycode = mouse_keycode_for_fkey(keycode);

    if (mouse_keycode != KC_NO) {
        tap_code_delay(mouse_keycode, TAP_CODE_DELAY);
        return;
    }

    tap_code_delay(keycode, keycode == KC_CAPS_LOCK ? TAP_HOLD_CAPS_DELAY : TAP_CODE_DELAY);
}

led_config_t g_led_config = {{// Key Matrix to LED Index
                              {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
                              {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, NO_LED},
                              {23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, NO_LED},
                              {34, 35, 36, 37, NO_LED, 38, 39, 40, 41, 42, NO_LED, NO_LED}},
                             {// LED Index to Physical Position
                              {220, 0}, {200, 0}, {180, 0}, {160, 0}, {140, 0}, {120, 0}, {100, 0}, {80, 0}, {60, 0}, {40, 0}, {20, 0}, {0, 0}, {215, 21}, {195, 21}, {175, 21}, {155, 21}, {135, 21}, {115, 21}, {95, 21}, {75, 21}, {55, 21}, {35, 21}, {10, 21}, {210, 42}, {190, 42}, {170, 42}, {150, 42}, {130, 42}, {110, 42}, {90, 42}, {70, 42}, {50, 42}, {20, 42}, {0, 42}, {220, 63}, {200, 63}, {180, 63}, {140, 63}, {90, 63}, {60, 63}, {40, 63}, {20, 63}, {0, 63}},
                             {// LED Index to Flag
                              0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
