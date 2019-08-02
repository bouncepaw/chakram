#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
  {{{KC_NO}}};

void encoder_update_user(uint8_t index, bool clockwise) {
  tap_code(clockwise ? KC_VOLU : KC_VOLD);
}
