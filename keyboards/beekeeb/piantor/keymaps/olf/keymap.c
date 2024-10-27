// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define _BASE 0
#define _LAYER_1 1
#define _LAYER_2 2
#define _LAYER_3 3
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
        KC_NO, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_NO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_NO,
        KC_NO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                  KC_NO, KC_LSFT, LT(_LAYER_1, KC_BSPC),                               LT(_LAYER_2, KC_ENTER),  LCTL_T(KC_SPACE),  KC_NO
    ),
    [_LAYER_1] = LAYOUT_split_3x6_3(
        KC_NO, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC,    KC_AMPR, KC_ASTR,    KC_MINUS,    KC_PLUS,    KC_NO,
        KC_NO, KC_EQUAL, KC_S,    KC_LBRC, KC_RBRC, KC_LCBR,                           KC_LPRN,    KC_J,    KC_K,       KC_L,        KC_SCLN,    KC_NO,
        KC_NO, QK_BOOT,  KC_UNDS, KC_C,    KC_V,    KC_RCBR,                           KC_RPRN,    KC_PIPE, KC_QUES,    KC_QUES,     KC_NO,      KC_NO,
                                      KC_NO, KC_LSFT, KC_NO,                           LT(_LAYER_3, KC_ESC),  LCTL_T(KC_SPACE),  KC_NO
    ),
    [_LAYER_2] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,    KC_1,    KC_2,    KC_3,    KC_NO,                             KC_NO,    KC_NO,             KC_NO,             KC_NO,            KC_NO,    KC_NO,
        KC_NO, KC_NO,    KC_4,    KC_5,    KC_6,    KC_NO,                             KC_NO,    LSFT_T(KC_NO),     LCTL_T(KC_NO),     LALT_T(KC_NO),    KC_NO ,   KC_NO,
        KC_NO, KC_NO,    KC_7,    KC_8,    KC_9,    KC_NO,                             KC_NO,    KC_NO,             KC_NO,             QK_BOOT,          KC_NO,    KC_NO,
                     KC_0, KC_LSFT, LT(_LAYER_3, KC_BSPC),                             KC_NO,    LCTL_T(KC_SPACE),  KC_NO
    ),
    [_LAYER_3] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,   KC_F1,   KC_F2,    KC_F3,    KC_F10,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_NO, KC_NO,   KC_F4,   KC_F5,    KC_F6,    KC_F11,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_NO,
        KC_NO, KC_NO,   KC_F7,   KC_F8,    KC_F9,    KC_F12,                           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                      KC_NO, KC_LSFT, LT(_LAYER_1, KC_BSPC),                           LT(_LAYER_2, KC_ENTER),  LCTL_T(KC_SPACE),  KC_NO
    )
};
