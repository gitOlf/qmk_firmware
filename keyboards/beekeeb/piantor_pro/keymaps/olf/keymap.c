// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include "features/achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

#include QMK_KEYBOARD_H
#define _BASE 0
#define _LAYER_1 1
#define _LAYER_2 2
#define _LAYER_3 3
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY

#define LAYER_1_KEYCODE LT(_LAYER_1, KC_BSPC)
#define LAYER_2_KEYCODE LT(_LAYER_2, KC_BSPC)
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case LAYER_1_KEYCODE:
            return true;
        case LAYER_2_KEYCODE:
            return true;

    }
    return achordion_opposite_hands(tap_hold_record, other_record);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ ' │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_BASE] = LAYOUT_split_3x6_3(
        KC_NO, KC_Q,            KC_W,            KC_E,            KC_R,              KC_T,                            KC_Y,    KC_U,           KC_I,             KC_O,            KC_P,             KC_NO,
        KC_NO, LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),      KC_G,                            KC_H,    LSFT_T(KC_J),   LCTL_T(KC_K),     LALT_T(KC_L),    LGUI_T(KC_SCLN),  KC_NO,
        KC_NO, KC_Z,            KC_X,            KC_C,            KC_V,              KC_B,                            KC_N,    KC_M,           KC_COMM,          KC_DOT,          KC_QUOTE,          KC_NO,
                                                 KC_NO,           KC_LSFT,           LT(_LAYER_1, KC_BSPC),           LT(_LAYER_2, KC_ENTER),  LCTL_T(KC_SPACE), KC_NO
    ),
    [_LAYER_1] = LAYOUT_split_3x6_3(
        KC_NO, KC_EXLM,        KC_AT,           KC_HASH,          KC_DLR,            KC_PERC,                          KC_CIRC, KC_AMPR,         KC_ASTR,         KC_MINUS,      KC_PLUS,            KC_NO,
        KC_NO, LGUI_T(KC_GRV), LALT_T(KC_EQL),  LCTL_T(KC_LBRC),  LSFT_T(KC_RBRC),   KC_LCBR,                          KC_LEFT, LSFT_T(KC_DOWN), LCTL_T(KC_UP),   LALT_T(KC_RIGHT), LGUI_T(KC_BSLS), KC_NO,
        KC_NO, KC_TILD,        KC_UNDS,         KC_LABK,          KC_RABK,           KC_RCBR,                          KC_LPRN, KC_RPRN,         KC_PIPE,         KC_QUES,       KC_SLSH,            KC_NO,
                                      KC_NO, KC_LSFT, KC_NO,                                                           LT(_LAYER_3, KC_ESC),  LCTL_T(KC_TAB),  KC_NO
    ),
    [_LAYER_2] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,    KC_1,    KC_2,    KC_3,    KC_NO,                                                             KC_NO,    KC_NO,             KC_NO,             KC_NO,            KC_NO,             KC_NO,
        KC_NO, KC_NO,    KC_4,    KC_5,    KC_6,    KC_NO,                                                             KC_NO,    LSFT_T(KC_DOT),    LCTL_T(KC_COMM),   LALT_T(KC_MINUS), LGUI_T(KC_PLUS),   KC_NO,
        KC_NO, KC_NO,    KC_7,    KC_8,    KC_9,    KC_NO,                                                             KC_NO,    KC_NO,             KC_COMM,           KC_DOT,            KC_NO,             KC_NO,
                        KC_NO, KC_0, LT(_LAYER_3, KC_DEL),                                                             KC_NO,    KC_NO,             KC_NO
    ),
    [_LAYER_3] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,           KC_F1,          KC_F2,            KC_F3,              KC_F10,                           KC_NO,    KC_NO,             KC_NO,            KC_NO,            KC_NO,         KC_NO,
        KC_NO, LGUI_T(KC_NO),   LALT_T(KC_F4),  LCTL_T(KC_F5),    LSFT_T(KC_F6),      KC_F11,                           KC_NO,    LSFT_T(KC_NO),     LCTL_T(KC_NO),    LALT_T(KC_NO),    LGUI_T(KC_NO), KC_NO,
        KC_NO, KC_NO,           KC_F7,          KC_F8,            KC_F9,              KC_F12,                           KC_NO,    KC_NO,             KC_NO,            KC_NO,            QK_BOOT,       KC_NO,
                      KC_NO, KC_LSFT, LT(_LAYER_1, KC_BSPC),                                                            LT(_LAYER_2, KC_ENTER),  LCTL_T(KC_SPACE),  KC_NO
    )
};
