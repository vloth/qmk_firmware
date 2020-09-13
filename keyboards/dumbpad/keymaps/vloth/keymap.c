#include QMK_KEYBOARD_H

#define _BASE 0
#define _LOW  1
#define _HIGH 2

enum {
  CT_INPUT,
  ZOOM_MUTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    ZOOM_MUTE,    KC_F7,    KC_8,      KC_9,
    TD(CT_INPUT), KC_F4,    KC_F5,     KC_F6,
    S(G(KC_L)),   KC_F1,    KC_F2,     KC_F3,
    _______,      TG(_LOW), TG(_HIGH), KC_MPLY
  ),
  [_LOW] = LAYOUT(
    _______,     _______,     _______,      RESET,
    _______,     _______,     KC_KP_PLUS,   KC_KP_PLUS,
    _______,     _______,     _______,      KC_KP_MINUS,
    _______,     _______,     _______,      KC_EQL
  ),
  [_HIGH] = LAYOUT(
    _______,     _______,     _______,      RESET,
    _______,     _______,     KC_KP_PLUS,   KC_KP_PLUS,
    _______,     _______,     _______,      KC_KP_MINUS,
    _______,     _______,     _______,      KC_EQL
  ),
};


void dance_input(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count <= 1) {
        SEND_STRING("John Doe :)");
        reset_tap_dance(state);
        return;
    }
    if (state->count <= 2) {
        SEND_STRING("0670701706");
        reset_tap_dance(state);
        return;
    }
    if (state->count >= 3) {
        SEND_STRING("The quick brown fox jumps over the lazy dog.");
        reset_tap_dance(state);
        return;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_INPUT] = ACTION_TAP_DANCE_FN(dance_input),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case ZOOM_MUTE:
      if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSHIFT) SS_TAP(X_Z) SS_UP(X_LSHIFT) SS_UP(X_LGUI));
				_delay_ms(100);
				SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSHIFT) SS_TAP(X_A) SS_UP(X_LSHIFT) SS_UP(X_LGUI));
      }
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (biton32(state)) {
    case _BASE:
      DDRD &= ~(1<<5); PORTD &= ~(1<<5);
      DDRB &= ~(1<<0); PORTB &= ~(1<<0);
      break;
    case _LOW:
      DDRD &= ~(1<<5); PORTD &= ~(1<<5);
      DDRB |= (1<<0); PORTB &= ~(1<<0);
      break;
    case _HIGH:
      DDRD |= (1<<5); PORTD &= ~(1<<5);
      DDRB &= ~(1<<0); PORTB &= ~(1<<0);
      break;
  }
  return state;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch (biton32(layer_state)) {
      case _BASE:
        clockwise ? rgblight_increase_val() : rgblight_decrease_val();
        break;
      
      case _HIGH:
        clockwise ? rgblight_increase() : rgblight_decrease();
        break;

      case _LOW:
        clockwise ? rgblight_increase_hue() : rgblight_decrease_hue();
        break;
    }
  } else if (index == 1) {
    switch (biton32(layer_state)) {
      case _BASE:
        clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
        break;

      case _HIGH:
        clockwise ? tap_code(KC_MPLY) : tap_code(KC_PAUSE);
        break;

      case _LOW:
        clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
        break;
    }
  }
}
