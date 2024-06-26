/* Copyright 2021 jurassic73
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes {
  AB_MACRO_1 = SAFE_RANGE
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    BASE,
    AUD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE */
    [0] = LAYOUT(
        KC_ESC,  KC_F1,  KC_F2,        KC_F3,  KC_F4,  KC_F5,     KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10, KC_F11,     KC_F12,    KC_PSCR, KC_SCRL, KC_PAUS,
        KC_1,    KC_2,   KC_3,         KC_4,   KC_5,   KC_6,      KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS, KC_EQL,    KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,
        KC_GRV,  KC_Q,   KC_W,         KC_E,   KC_R,   KC_T,      KC_U,   KC_I,   KC_O,   KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
        KC_TAB,  KC_A,   KC_S,         KC_D,   KC_F,   KC_G,      KC_Y,   KC_J,   KC_K,   KC_L,    KC_SCLN,KC_QUOT,    KC_ENT,
        KC_CAPS, KC_Z,   KC_X,         KC_C,   KC_V,   KC_B,      KC_H,   KC_M,   KC_COMM,KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        KC_LSFT, KC_LCTL,MO(1),KC_LGUI,KC_LALT,KC_SPACE,    KC_N,   KC_SPACE, KC_RALT,KC_RGUI, KC_APP,  KC_RCTL,   KC_LEFT,   KC_DOWN, KC_RGHT
        ),
    /* AUD */
    [1] = LAYOUT(
      KC_TRNS,AB_MACRO_1,AB_MACRO_1,AB_MACRO_1,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_MEDIA_PLAY_PAUSE,
      KC_TRNS,KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_WWW_BACK,KC_WWW_FORWARD,  KC_TRNS,KC_TRNS,KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_UP,
      KC_TRNS,KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,
      KC_TRNS,KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,             KC_PGUP,
      KC_TRNS,KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,AB_MACRO_1,  KC_TRNS,AB_MACRO_1,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_HOME,   KC_PGDN, KC_END
        ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AB_MACRO_1:
      uint16_t kc = keymap_key_to_keycode(0, record->event.key);
      if (record->event.pressed) {
        register_code(KC_LWIN);
        register_code(kc);
      } else {
        unregister_code(kc);
        unregister_code(KC_LWIN);
      }
      break;
  }
  return true;
}

