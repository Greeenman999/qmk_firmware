// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "gpio.h"

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

enum layers {
    _DEFAULT,
    _NUMBERS,
    _SYMBOLS,
    _RGB
};

const uint16_t PROGMEM altgr[] = {MO(_NUMBERS), MO(_SYMBOLS), COMBO_END};

const uint16_t PROGMEM l_bracket_combo[] = {KC_W, LALT_T(KC_R), COMBO_END};
const uint16_t PROGMEM l_paren_combo[] = {KC_F, LCTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM l_brace_combo[] = {KC_P, LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM l_abk_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM r_bracket_combo[] = {KC_Y, LALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM r_paren_combo[] = {KC_U, LCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM r_brace_combo[] = {KC_L, LSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM r_abk_combo[] = {KC_J, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(altgr, KC_RIGHT_ALT),
    COMBO(l_bracket_combo, KC_LBRC),
    COMBO(l_paren_combo, KC_LPRN),
    COMBO(l_brace_combo, KC_LCBR),
    COMBO(l_abk_combo, KC_LABK),
    COMBO(r_bracket_combo, KC_RBRC),
    COMBO(r_paren_combo, KC_RPRN),
    COMBO(r_brace_combo, KC_RCBR),
    COMBO(r_abk_combo, KC_RABK),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │GUI├───┐           ┌───┤Alt│
      *           └───┤Bsp├───┐   ┌───┤Ent├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [0] = LAYOUT_split_3x5_3(
        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                               KC_J,    KC_L,          KC_U,           KC_Y,           KC_SCLN,
        KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                               KC_M,    KC_N,          KC_E,           KC_I,           KC_O,
        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                               KC_K,    KC_H,          KC_COMM,        KC_DOT,         KC_SLSH,
                                                                    KC_ESC, KC_SPC, MO(1),              MO(2),  KC_ENT,  KC_BSPC
    ),
    [_NUMBERS] = LAYOUT_split_3x5_3(
      /*
       * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
       * │Tab│ 1 │ 2 │ 3 │ 4 │       │ 5 │ 6 │ 7 │ 8 │ 9 │
       * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       * │Ctl│XXX│XXX│XXX│XXX│       │←  │↓  │↑  │→  │XXX│
       * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       * │Sft│XXX│XXX│XXX│XXX│       │XXX│XXX│XXX│XXX│XXX│
       * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
       *           ┌───┐                   ┌───┐
       *           │GUI├───┐           ┌───┤MO3│
       *           └───┤___├───┐   ┌───┤Spc├───┘
       *               └───┤Spc│   │Ent├───┘
       *                   └───┘   └───┘
       */
      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,                               KC_5,    KC_6,    KC_7,    KC_8,    KC_9,
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                     KC_LGUI, _______, KC_SPC,           KC_ENT, MO(3), KC_RALT
  ),
  [_SYMBOLS] = LAYOUT_split_3x5_3(
      /*
       * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
       * │Tab│ ! │ @ │ # │ $ │       │ % │ ^ │ & │ * │ ( │
       * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       * │Ctl│XXX│XXX│XXX│XXX│       │ - │ = │ [ │ ] │ \ │
       * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       * │Sft│XXX│XXX│XXX│XXX│       │ _ │ + │ { │ } │ | │
       * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
       *           ┌───┐                   ┌───┐
       *           │GUI├───┐           ┌───┤MO3│
       *           └───┤MO3├───┐   ┌───┤Spc├───┘
       *               └───┤Spc│   │Ent├───┘
       *                   └───┘   └───┘
       */
      KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR,                                 KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                     KC_LGUI, MO(3), KC_SPC,            KC_ENT, _______, KC_RALT
  ),
  [_RGB] = LAYOUT_split_3x5_3(
      /*
       * ┌────┬────┬────┬────┬────┐       ┌────┬────┬────┬────┬────┐
       * │BOOT│XXX │XXX │XXX │XXX │       │XXX │XXX │XXX │XXX │XXX │
       * ├────┼────┼────┼────┼────┤       ├────┼────┼────┼────┼────┤
       * │RGBT│HUE+│SAT+│VAL+│XXX │       │XXX │XXX │XXX │XXX │XXX │
       * ├────┼────┼────┼────┼────┤       ├────┼────┼────┼────┼────┤
       * │NEXT│HUE-│SAT-│VAL-│XXX │       │XXX │XXX │XXX │XXX │XXX │
       * └────┴────┴────┴────┴────┘       └────┴────┴────┴────┴────┘
       *           ┌───┐                   ┌───┐
       *           │GUI├───┐           ┌───┤___│
       *           └───┤___├───┐   ┌───┤Spc├───┘
       *               └───┤Spc│   │Ent├───┘
       *                   └───┘   └───┘
       */
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                     KC_LGUI, _______, KC_SPC,            KC_ENT, _______, KC_RALT
  )
};

#ifdef OLED_ENABLE
// NOTE: Most of the OLED code was originally written by Soundmonster for the Corne,
// and has been copied directly from `crkbd/soundmonster/keymap.c`

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Number\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}

#endif
