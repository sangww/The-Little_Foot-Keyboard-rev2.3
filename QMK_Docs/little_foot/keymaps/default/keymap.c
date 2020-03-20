/*
Copyright 2020 Sang Leigh

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial 
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT 
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*
Original code provided by Royal: https://github.com/TheRoyalSweatshirt/The-Little_Foot-Keyboard-rev2.3

Keymap modified to support other customized behaviors
*/

#include QMK_KEYBOARD_H
#include "quantum.h"

// Layer names
enum{
  // - Win Base layer:
  _BASE,
  // - Mac Base layer:
  _MBASE,
  // - Win Symbols, numbers, and functions:
  _SYM,
  // - Mac Symbols, numbers, and functions:
  _MSYM,
  // - Win Function layer:
  _FN,
  // - Mac Function layer:
  _MFN,
  // - Win Function layer:
  _LN,
  // - Mac Function layer:
  _MLN,
  // - HYPE-BOI Function layer:
  _HYPE
};

enum combos { //add the number of combos to config.h
  combo_ESC,
  combo_BACK,
  combo_TAB,
  combo_DELETE,
};

const uint16_t PROGMEM esc_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_O, KC_P, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [combo_ESC] = COMBO(esc_combo, KC_ESC),
  [combo_BACK] = COMBO(bspc_combo, KC_BSPC),
  [combo_TAB] = COMBO(tab_combo, KC_TAB),
  [combo_DELETE] = COMBO(del_combo, KC_DEL),
};

enum custom_keycodes {
  S_CTL_Z = SAFE_RANGE,
  S_CTL_A,
  S_CMD_Z,
  S_CMD_A
};

static uint16_t start;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case S_CTL_Z:
      if (record->event.pressed) {
        start = timer_read();
              layer_on(_FN);
            } else {
              layer_off(_FN);
              if(timer_elapsed(start) < TAPPING_TERM) {
          SEND_STRING(SS_LCTRL("z"));
        }
      }
      break;
    case S_CTL_A:
      if (record->event.pressed) {
        start = timer_read();
        layer_on(_LN);
      } else {
        layer_off(_LN);
        if(timer_elapsed(start) < TAPPING_TERM) {
          SEND_STRING(SS_LCTRL("a"));
        }
      }
      break;
    case S_CMD_Z:
      if (record->event.pressed) {
        start = timer_read();
        layer_on(_FN);
      } else {
        layer_off(_FN);
        if(timer_elapsed(start) < TAPPING_TERM) {
          SEND_STRING(SS_LGUI("z"));
        }
      }
      break;
    case S_CMD_A:
      if (record->event.pressed) {
        start = timer_read();
        layer_on(_LN);
      } else {
        layer_off(_LN);
        if(timer_elapsed(start) < TAPPING_TERM) {
          SEND_STRING(SS_LGUI("a"));
        }
      }
      break;
  }
  return true;
};

#define BASE MO(_BASE)
#define MBASE MO(_MBASE)
#define SYM MO(_SYM)
#define MSYM MO(_MSYM)
#define FN MO(_FN)
#define MFN MO(_MFN)
#define LN MO(_LN)
#define MLN MO(_MLN)

#define xxx KC_TRNS
#define no KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_big_space_base(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_LSFT,
    LT(SYM, KC_SPC)
  ),  

  [_SYM] = LAYOUT_big_space_base(
    KC_LGUI,    xxx,        KC_PSCR,    xxx,        xxx,        xxx,        xxx,        KC_MINS, KC_PLUS, KC_GRV,
    LCTL(KC_Q), LCTL(KC_W), LCTL(KC_E), LCTL(KC_R), LCTL(KC_T), LCTL(KC_Y), LCTL(KC_U), KC_LBRC, KC_RBRC, LGUI(KC_SPC),
    S_CTL_A,    LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), LCTL(KC_G), LCTL(KC_H), LCTL(KC_J), KC_SCLN, KC_QUOT, KC_RALT,
    S_CTL_Z,    LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B), LCTL(KC_N), LCTL(KC_M), KC_BSLS, KC_SLSH, xxx,
    xxx
  ),

  [_FN] = LAYOUT_big_space_base(
    xxx,          xxx,           xxx,              xxx,              xxx, xxx, xxx, xxx,          xxx,    xxx,
    LGUI(KC_TAB), LCTL(KC_LEFT), KC_UP,            LCTL(KC_RIGHT),   xxx, xxx, xxx, LSFT(KC_TAB), KC_TAB, xxx,
    no,           KC_LEFT,       KC_DOWN,          KC_RIGHT,         xxx, xxx, xxx, xxx,          xxx,    LCTL(KC_ENT),
    xxx,          LCTL(KC_Y),    LCTL(LSFT(KC_C)), LCTL(LSFT(KC_V)), xxx, xxx, xxx, xxx,          xxx,    xxx,
    xxx
  ),

  [_LN] = LAYOUT_big_space_base(
    xxx, xxx,                 xxx,              xxx,                  xxx, xxx, xxx, xxx, xxx, TG(MBASE),
    xxx, LCTL(LGUI(KC_LEFT)), KC_PGUP,          LCTL(LGUI(KC_RIGHT)), xxx, xxx, xxx, xxx, xxx, xxx,
    xxx, KC_HOME,             KC_PGDN,          KC_RIGHT,             xxx, xxx, xxx, xxx, xxx, LSFT(KC_ENT),
    no,  xxx,                 LCTL(LALT(KC_C)), LCTL(LALT(KC_V)),     xxx, xxx, xxx, xxx, xxx, xxx,
    xxx
  ),


  [_MBASE] = LAYOUT_big_space_base(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_LSFT,
    LT(MSYM, KC_SPC)
  ),  

  [_MSYM] = LAYOUT_big_space_base(
    xxx,        xxx,        LGUI(LCTL(KC_4)),  LGUI(LCTL(LSFT(KC_4))), xxx,        xxx,        xxx,        KC_MINS, KC_PLUS, KC_GRV,
    LGUI(KC_Q), LGUI(KC_W), LGUI(KC_E),        LGUI(KC_R),             LGUI(KC_T), LGUI(KC_Y), LGUI(KC_U), KC_LBRC, KC_RBRC, LGUI(KC_SPC),
    S_CMD_A,    LGUI(KC_S), LGUI(KC_D),        LGUI(KC_F),             LGUI(KC_G), LGUI(KC_H), LGUI(KC_J), KC_SCLN, KC_QUOT, LCTL(KC_SPC),
    S_CMD_Z,    LGUI(KC_X), LGUI(KC_C),        LGUI(KC_V),             LGUI(KC_B), LGUI(KC_N), LGUI(KC_M), KC_BSLS, KC_SLSH, xxx,
    xxx
  ),

  [_MFN] = LAYOUT_big_space_base(
    xxx,          xxx,              xxx,              xxx,              xxx, xxx, xxx, xxx,           xxx,           xxx,
    LGUI(KC_TAB), LALT(KC_LEFT),    KC_UP,            LALT(KC_RIGHT),   xxx, xxx, xxx, LGUI(KC_LBRC), LGUI(KC_RBRC), xxx,
    no,           KC_LEFT,          KC_DOWN,          KC_RIGHT,         xxx, xxx, xxx, xxx,           xxx,           LGUI(KC_ENT),
    xxx,          LCTL(LSFT(KC_Z)), LCTL(LALT(KC_C)), LCTL(LALT(KC_V)), xxx, xxx, xxx, xxx,           xxx,           xxx,
    xxx
  ),

  [_MLN] = LAYOUT_big_space_base(
    xxx, xxx,           xxx,     xxx,            xxx, xxx, xxx, xxx, xxx, TG(BASE),
    xxx, LCTL(KC_LEFT), KC_PGUP, LCTL(KC_RIGHT), xxx, xxx, xxx, xxx, xxx, xxx,
    xxx, LGUI(KC_LEFT), KC_PGDN, LGUI(KC_RIGHT), xxx, xxx, xxx, xxx, xxx, LSFT(KC_ENT),
    no,  xxx,           xxx,     xxx,            xxx, xxx, xxx, xxx, xxx, xxx,
    xxx
  )
};
