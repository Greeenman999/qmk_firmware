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
    _QWERTY,
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

const uint16_t PROGMEM tab_combo[] = {LSFT_T(KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM qwerty_combo[] = {KC_D, KC_V, COMBO_END};

const uint16_t PROGMEM numbers_combo[] = {KC_SPC, KC_LSFT, COMBO_END};

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
    COMBO(tab_combo, KC_TAB),
    COMBO(qwerty_combo, DF(_QWERTY)),
    COMBO(numbers_combo, MO(_NUMBERS)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x5_3(
        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                               KC_J,    KC_L,          KC_U,           KC_Y,           KC_SCLN,
        LGUI_T(KC_A),   LALT_T(KC_R),   LCTL_T(KC_S),   LSFT_T(KC_T),   KC_G,                               KC_M,    LSFT_T(KC_N),  LCTL_T(KC_E),   LALT_T(KC_I),   LGUI_T(KC_O),
        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                               KC_K,    KC_H,          KC_COMM,        KC_DOT,         KC_SLSH,
                                                                    KC_ESC, KC_SPC, MO(_NUMBERS),              MO(_SYMBOLS),  KC_LSFT,  KC_BSPC
    ),
    [_NUMBERS] = LAYOUT_split_3x5_3(
        KC_TAB,    KC_DEL,    KC_7,    KC_8,    KC_9,                        KC_DOWN,   KC_RIGHT,   KC_MPRV,   KC_MPLY,   KC_MNXT,
        XXXXXXX,   KC_PSCR,   KC_4,    KC_5,    KC_6,                        KC_HOME,   KC_PGUP,    KC_PGDN,   KC_END,    XXXXXXX,
        XXXXXXX,   KC_0,      KC_1,    KC_2,    KC_3,                        KC_UP,     KC_LEFT,    XXXXXXX,   XXXXXXX,   XXXXXXX,
                                         XXXXXXX, MO(_RGB), XXXXXXX,         KC_ENT,    MO(_RGB),   KC_RALT
    ),
    [_SYMBOLS] = LAYOUT_split_3x5_3(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                 KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PLUS,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_GRV,  KC_DQUO, KC_QUOT, KC_MINS, KC_EQL,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                  KC_TILD, KC_QUES, KC_COLN, KC_BSLS, KC_PIPE,
                                   KC_F11,  KC_F12,  KC_RALT,        XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_RGB] = LAYOUT_split_3x5_3(
        QK_BOOT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                        XXXXXXX,   XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        RM_TOGG,   RM_HUEU,   RM_SATU,   RM_VALU,   XXXXXXX,                        XXXXXXX,   DF(_QWERTY),  XXXXXXX,      XXXXXXX,      XXXXXXX,
        RM_NEXT,   RM_HUED,   RM_SATD,   RM_VALD,   XXXXXXX,                        XXXXXXX,   XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                                         XXXXXXX,   XXXXXXX,   XXXXXXX,             XXXXXXX,   XXXXXXX,      XXXXXXX
    ),
    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_T,   KC_Q,   KC_W,   KC_E,   KC_R,                             KC_Y,   KC_U,   KC_I,      KC_O,      KC_P,
        KC_G,   KC_A,   KC_S,   KC_D,   KC_F,                             KC_H,   KC_J,   KC_K,      KC_L,      KC_TAB,
        KC_B,   KC_Z,   KC_X,   KC_C,   KC_V,                             KC_N,   KC_M,   XXXXXXX,   XXXXXXX,   KC_ESC,
                                   KC_LCTL, KC_SPC, KC_LSFT,              MO(_SYMBOLS), MO(_NUMBERS), DF(_DEFAULT)
    ),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_QWERTY) && combo_index != 11) {
        return false;
    }

    return true;
}

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
        case 4:
            oled_write_P(PSTR("Qwerty\n"), false);
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
