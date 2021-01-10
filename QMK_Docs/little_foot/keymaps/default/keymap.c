#include QMK_KEYBOARD_H
#include "quantum.h"

// Layer names
enum{
  // - Win Base layer:
  _BASE,
  _SYM,
  _ZN,
  _TN,

  //Mac layers
  _uBASE,
  _uSYM,
  _uZN,
  _uTN,
  
  // - HYPE-BOI Function layer:
  _HYPE
};

#define BASE MO(_BASE)
#define SYM MO(_SYM)
#define ZN MO(_ZN)
#define TN MO(_TN)

#define uBASE MO(_uBASE)
#define uSYM MO(_uSYM)
#define uZN MO(_uZN)
#define uTN MO(_uTN)

#define xxx KC_TRNS
#define no KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_big_space_base(
    KC_ESC,          KC_TAB, KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, KC_MINS, KC_EQL, KC_DEL,         KC_BSPC,
    KC_Q,            KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,   KC_O,           KC_P,
    KC_A,            KC_S,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,   KC_L,           KC_ENT,
    LT(ZN, KC_COMM), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   LT(TN, KC_DOT), KC_LSFT,
    LT(SYM, KC_SPC)
  ),  

  [_SYM] = LAYOUT_big_space_base(
    KC_1,    KC_2,                KC_3,       KC_4,                 KC_5, KC_6, KC_7,          KC_8,     KC_9,           KC_0,
    xxx,     LCTL(LGUI(KC_LEFT)), KC_PGUP,    LCTL(LGUI(KC_RIGHT)), xxx,  xxx,  LCTL(KC_LEFT), KC_UP,    LCTL(KC_RIGHT), xxx,
    xxx,     KC_HOME,             KC_PGDN,    KC_END,               xxx,  xxx,  KC_LEFT,       KC_DOWN,  KC_RIGHT,       KC_RALT,
    KC_BSLS, LCTL(KC_Y),          xxx,        xxx,                  xxx,  xxx,  xxx,           xxx,      KC_SLSH,        xxx,
    xxx
  ),

  [_ZN] = LAYOUT_big_space_base(
    xxx,        xxx,        KC_PSCR,    xxx,        xxx,        xxx,        LCTL(KC_MINS), LCTL(KC_EQL), LCTL(KC_DEL), LCTL(KC_BSPC),
    LCTL(KC_Q), LCTL(KC_W), LCTL(KC_E), LCTL(KC_R), LCTL(KC_T), LCTL(KC_Y), LCTL(KC_U),    KC_LBRC,      KC_RBRC,      KC_GRV,
    LCTL(KC_A), LCTL(KC_S), LALT(KC_D), LCTL(KC_F), LCTL(KC_G), LCTL(KC_H), LCTL(KC_J),    KC_SCLN,      KC_QUOT,      LCTL(KC_ENT),
    xxx,        LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B), LCTL(KC_N),    LCTL(KC_M),   KC_SLSH,      xxx,
    LGUI(KC_SPC)
  ),

  [_TN] = LAYOUT_big_space_base(
    TG(uBASE), xxx,              xxx,              xxx,              xxx,              xxx, xxx, xxx,          xxx,    xxx,
    xxx,       xxx,              xxx,              xxx,              xxx,              xxx, xxx, LSFT(KC_TAB), KC_TAB, xxx,
    xxx,       xxx,              xxx,              xxx,              xxx,              xxx, xxx, xxx,          xxx,    LCTL(KC_ENT),
    KC_BSLS,   LCTL(LALT(KC_C)), LCTL(LALT(KC_V)), LCTL(LSFT(KC_C)), LCTL(LSFT(KC_V)), xxx, xxx, xxx,          xxx,    xxx,
    xxx
  ),



  [_uBASE] = LAYOUT_big_space_base(
    KC_ESC,           KC_TAB, KC_LCTL, KC_LALT, KC_LGUI, LGUI(KC_SPC), KC_MINS, KC_EQL, KC_DEL, KC_BSPC,
    KC_Q,             KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,         KC_U,    KC_I,   KC_O,   KC_P,
    KC_A,             KC_S,   KC_D,    KC_F,    KC_G,    KC_H,         KC_J,    KC_K,   KC_L,   KC_ENT,
    LT(uZN, KC_COMM), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,   LT(uTN, KC_DOT), KC_LSFT,
    LT(uSYM, KC_SPC)
  ),  


  [_uSYM] = LAYOUT_big_space_base(
    KC_1,    KC_2,             KC_3,       KC_4,           KC_5, KC_6, KC_7,          KC_8,     KC_9,           KC_0,
    xxx,     LCTL(KC_LEFT),    LALT(KC_UP),    LCTL(KC_RIGHT), xxx,  xxx,  LALT(KC_LEFT), KC_UP,    LALT(KC_RIGHT), xxx,
    xxx,     LGUI(KC_LEFT),          LALT(KC_DOWN),    LGUI(KC_RIGHT),         xxx,  xxx,  KC_LEFT,       KC_DOWN,  KC_RIGHT,       LGUI(KC_SPC),
    KC_BSLS, LGUI(LSFT(KC_Z)), xxx,        xxx,            xxx,  xxx,  xxx,           xxx,      KC_SLSH,        xxx,
    xxx
  ),

  [_uZN] = LAYOUT_big_space_base(
    xxx,        xxx,        LGUI(LCTL(KC_4)), LGUI(LCTL(LSFT(KC_4))), xxx,        xxx,        LGUI(KC_MINS), LGUI(KC_EQL), LALT(KC_DEL), LALT(KC_BSPC),
    LGUI(KC_Q), LGUI(KC_W), LGUI(KC_E),       LGUI(KC_R),             LGUI(KC_T), LGUI(KC_Y), LGUI(KC_U),    KC_LBRC,      KC_RBRC,      KC_GRV,
    LGUI(KC_A), LGUI(KC_S), LGUI(KC_D),       LGUI(KC_F),             LGUI(KC_G), LGUI(KC_H), LGUI(KC_J),    KC_SCLN,      KC_QUOT,      LGUI(KC_ENT),
    xxx,        LGUI(KC_Z), LGUI(KC_X),       LGUI(KC_C),             LGUI(KC_V), LGUI(KC_B), LGUI(KC_N),    LGUI(KC_M),   KC_SLSH,      xxx,
    LCTL(KC_SPC)
  ),

  [_uTN] = LAYOUT_big_space_base(
    TG(uBASE), xxx,              xxx,              xxx,              xxx,              xxx, xxx, xxx,           xxx,           xxx,
    xxx,       xxx,              xxx,              xxx,              xxx,              xxx, xxx, LGUI(KC_LBRC), LGUI(KC_RBRC), xxx,
    xxx,       xxx,              xxx,              xxx,              xxx,              xxx, xxx, xxx,           xxx,           LCTL(KC_ENT),
    KC_BSLS,   LGUI(LSFT(KC_C)), LGUI(LSFT(KC_V)), LGUI(LALT(KC_C)), LGUI(LALT(KC_V)), xxx, xxx, xxx,           xxx,           xxx,
    xxx
  )
};



