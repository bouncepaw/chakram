#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
  {{{KC_NO}}};

void init_led(void) {
  DDRD |= _BV(0) | _BV(1) | _BV(4);
  DDRB |= _BV(5);
  DDRF |= _BV(4) | _BV(7);
  DDRE |= _BV(6);
}

void clear_led(void) {
  init_led();
  DDRD &=~ (_BV(0) | _BV(1) | _BV(4));
  DDRB &=~ _BV(5);
  DDRF &=~ (_BV(4) | _BV(7));
  DDRE &=~ _BV(6);
}

/* 
 * 0 D4 	1 B5
 * 2 F4 	3 F7
 * 4 D1 	5 D0
 * 6 D4 	7 E6
 */

// 1: cw
// -1: ccw
void rotate(int where) {
  static int pos = 0;
  clear_led();
  pos += where;
  pos = (pos == 8) ? 0 
    : (pos == -1) ? 7 
    : pos;
  switch (pos) {
    case 0: PORTD |= _BV(4); break;
    case 1: PORTB |= _BV(5); break;
    case 2: PORTF |= _BV(4); break;
    case 3: PORTF |= _BV(7); break;
    case 4: PORTD |= _BV(1); break;
    case 5: PORTD |= _BV(0); break;
    case 6: PORTD |= _BV(4); break;
    case 7: PORTE |= _BV(6); break;
  }
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
    rotate(1);
  } else {
    tap_code(KC_VOLD);
    rotate(-1);
  }
}
