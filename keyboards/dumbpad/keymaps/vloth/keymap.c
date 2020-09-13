#include QMK_KEYBOARD_H

#define _BASE 0
#define _SUB  1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    _______,   KC_F7,   KC_8,     KC_9,
    _______,   KC_F4,   KC_F5,    KC_F6,
    _______,   KC_F1,   KC_F2,    KC_F3,
    _______,  TG(_SUB), TG(_SUB),   KC_MUTE
  ),
  [_SUB] = LAYOUT(
    _______,     _______,     _______,      RESET,
    _______,     _______,     KC_KP_PLUS,   KC_KP_PLUS,
    _______,     _______,     _______,      KC_KP_MINUS,
    _______,     _______,     _______,      KC_EQL
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (biton32(state)) {
    case _BASE:
      DDRD &= ~(1<<5); PORTD &= ~(1<<5);
      DDRB &= ~(1<<0); PORTB &= ~(1<<0);
      break;
    case _SUB:
      DDRD &= ~(1<<5); PORTD &= ~(1<<5);
      DDRB |= (1<<0); PORTB &= ~(1<<0);
      break;
  }
  return state;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch (biton32(layer_state)) {
      case _BASE:
        clockwise ? rgblight_increase() : rgblight_decrease();
        break;

      default:
        clockwise ? rgblight_increase_val() : rgblight_decrease_val();
        break;
    }
  } else if (index == 1) {
    switch (biton32(layer_state)) {
      case _BASE:
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;

      default:
        clockwise ? rgblight_increase_val() : rgblight_decrease_val();
        break;
    }
  }
}
