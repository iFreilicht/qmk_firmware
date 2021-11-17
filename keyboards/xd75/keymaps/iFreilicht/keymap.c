/* Copyright 2017 Wunder
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
#include "xd75.h"
#include "keymap_us_international_revive_dead.h"

// Layer shorthand
#define _QB 0  // QWERTY base layer
#define _QA 1  // Alternate Graph layer QWERTY
#define _GM 2  // GameMode Layer
#define _NM 3  // NumMode Layer
#define _FN 4  // FN Layer

// US-Intl keycodes
// AltGr
#define KC_ALGR KC_RALT


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Visual guide to the layers can be found at http://www.keyboard-layout-editor.com/#/gists/f0196aab501bc234ef708e5527d6ad31 */

#define SPC_SFT SFT_T(KC_SPC)
#define CTL_ESC CTL_T(KC_ESC)

 [_QB] = { /* QWERTY */
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F22,  KC_MAIL, KC_CALC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MPRV, KC_MPLY, KC_MNXT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC },
  { CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_VOLD, KC_MUTE, KC_VOLU, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT  },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F18,  KC_UP,   KC_F19,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
  { KC_LCTL, KC_SPC,  MO(_FN), KC_LGUI, KC_LALT, SPC_SFT, KC_LEFT, KC_DOWN, KC_RGHT, MO(_QA), MO(_FN), KC_ALGR, KC_SPC,  MO(_GM), MO(_NM) },
 },

 [_QA] = { /* Alternate Graphs + Function*/
  { _______, US_IEXL, US_POW2, US_POW3, US_CURR, US_EURO, _______, _______, _______, US_1OV4, US_1OV4, US_3OV4, US_MINS, US_EQL,  _______ },
  { _______, _______, _______, US_LABK, _______, US_MINS, _______, _______, _______, US_EQL,  US_U_UM, US_RABK, US_O_UM, US_MINS, _______ },
  { _______, US_A_UM, US_SS,   US_LBRC, US_LCBR, US_LPRN, _______, _______, _______, US_RPRN, US_RCBR, US_RBRC, US_QUOT, US_PCRW, _______ },
  { _______, _______, _______, _______, _______, _______, _______, US_PGUP, _______, _______, US_MU,   US_GRV,  US_TILD, US_BSLS, _______ },
  { _______, _______, _______, _______, _______, _______, US_HOME, US_PGDN, US_END,  _______, _______, _______, _______, _______, _______ },
 },

 [_GM] = { /* GameMode */
  { _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, KC_F23 , _______, KC_F24,  _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, KC_SPC , _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 },

 [_NM] = { /* NumMode */
  { _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, _______, _______, _______, KC_PENT },
  { _______, _______, _______, _______, _______, _______, KC_P0,   _______, KC_PDOT, KC_PPLS, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PENT, _______, _______, _______, _______, _______ },
 },

 [_FN] = { /* Function */
  { _______, _______, _______, _______, _______, DEBUG,   KC_SLCK, KC_PAUS, RESET,   _______, _______, _______, _______, KC_PSCR, KC_INS  },
  { _______, _______, _______, _______, _______, _______, RGB_HUD, _______, RGB_HUI, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______ },
  { _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_TOG, RGB_VAI, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______ },
  { _______, _______, _______, _______, _______, _______, RGB_SAD, _______, RGB_SAI, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 },

/* [9] = { // Template
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 }*/
};
