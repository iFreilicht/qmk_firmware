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
#define _CB 2  // Colemak DH base Layer
#define _CA 3  // Alternate Graph Layer Colemak
#define _GM 4  // GameMode Layer
#define _NM 5  // NumMode Layer
#define _FN 6  // FN Layer

#undef RGBLIGHT_HUE_STEP
#undef RGBLIGHT_SAT_STEP
#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_HUE_STEP 15
#define RGBLIGHT_SAT_STEP 25
#define RGBLIGHT_VAL_STEP 10

// US-Intl keycodes
// AltGr
#define ALGR(kc) RALT(kc)
#define US_ALGR KC_RALT

// Shortened keycodes
#define KC_WWWB KC_WWW_BACK
#define KC_WWWN KC_WWW_FORWARD


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Visual guide to the layers can be found at http://www.keyboard-layout-editor.com/#/gists/f0196aab501bc234ef708e5527d6ad31 */

#define SPC_SFT SFT_T(US_SPC)
#define CTL_ESC CTL_T(US_ESC)

 [_QB] = { /* QWERTY */
  { US_ESC,  US_1,    US_2,    US_3,    US_4,    US_5,    US_F22,  KC_MAIL, KC_CALC, US_6,    US_7,    US_8,    US_9,    US_0,    US_DEL  },
  { US_TAB,  US_Q,    US_W,    US_E,    US_R,    US_T,    KC_MPRV, KC_MPLY, KC_MNXT, US_Y,    US_U,    US_I,    US_O,    US_P,    US_BSPC },
  { CTL_ESC, US_A,    US_S,    US_D,    US_F,    US_G,    KC_VOLD, KC_MUTE, KC_VOLU, US_H,    US_J,    US_K,    US_L,    US_SCLN, US_ENT  },
  { US_LSFT, US_Z,    US_X,    US_C,    US_V,    US_B,    US_F18,  KC_UP,   US_F19,  US_N,    US_M,    US_COMM, US_DOT,  US_SLSH, US_RSFT },
  { US_LCTL, US_SPC,  MO(_FN), US_LGUI, US_LALT, SPC_SFT, US_LEFT, US_DOWN, US_RGHT, MO(_QA), MO(_FN), US_ALGR, US_SPC,  MO(_GM), MO(_NM) },
 },

 [_QA] = { /* Alternate Graphs + Function*/
  { US_GRV,  US_IEXL, US_POW2, US_POW3, US_CURR, US_EURO, _______, _______, _______, US_1OV4, US_1OV4, US_3OV4, US_MINS, US_EQL,  _______ },
  { _______, _______, _______, US_LABK, _______, US_MINS, _______, _______, _______, US_EQL,  US_U_UM, US_RABK, US_O_UM, US_MINS, US_EQL  },
  { _______, US_A_UM, US_SS,   US_LBRC, US_LCBR, US_LPRN, _______, _______, _______, US_RPRN, US_RCBR, US_RBRC, US_QUOT, US_PCRW, _______ },
  { _______, _______, _______, _______, _______, _______, _______, US_PGUP, _______, _______, US_MU,   US_GRV,  US_TILD, US_BSLS, _______ },
  { _______, _______, _______, _______, _______, _______, US_HOME, US_PGDN, US_END,  _______, _______, _______, _______, _______, _______ },
 },

 [_CB] = { /* Colemak DH base */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, US_Q,    US_W,    US_F,    US_P,    US_B,    _______, _______, _______, US_J,    US_L,    US_U,    US_Y,    US_SCLN, _______ },
  { _______, US_A,    US_R,    US_S,    US_T,    US_G,    _______, _______, _______, US_M,    US_N,    US_E,    US_I,    US_O,    _______ },
  { _______, US_Z,    US_X,    US_C,    US_D,    US_V,    _______, _______, _______, US_K,    US_H,    US_COMM, US_DOT,  US_SLSH, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 },

 [_CA] = { /* Colemak DH Alternate Graphs */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, US_U_UM, _______, _______, _______ },
  { _______, US_A_UM, _______, US_SS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, US_O_UM, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 },

 [_GM] = { /* GameMode */
  { _______, US_1,    US_2,    US_3,    US_4,    US_5,    US_6,    US_7,    US_8,    US_9,    US_0,    US_MINS, US_EQL,  US_DGRV, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { US_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, US_F23 , _______, US_F24,  _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, US_SPC , _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 },

 [_NM] = { /* NumMode */
  { _______, _______, _______, _______, _______, _______, US_P7,   US_P8,   US_P9,   US_PSLS, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, US_P4,   US_P5,   US_P6,   US_PAST, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, US_P1,   US_P2,   US_P3,   US_PMNS, _______, _______, _______, _______, US_PENT },
  { _______, _______, _______, _______, _______, _______, US_P0,   _______, US_PDOT, US_PPLS, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, US_PENT, _______, _______, _______, _______, _______ },
 },

 [_FN] = { /* Function */
  { _______, _______, _______, _______, _______, _______, KC_SLCK, KC_PAUS, RESET,   US_DCRC, _______, _______, _______, KC_PSCR, KC_INS  },
  { _______, TG(_CB), _______, _______, _______, _______, RGB_HUD, _______, RGB_HUI, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______ },
  { _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_TOG, RGB_VAI, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______ },
  { _______, _______, _______, _______, _______, _______, RGB_SAD, _______, RGB_SAI, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 },

 [9] = { /* Template */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Revive dead keys
  if(!process_record_revive_dead_keys(keycode, record)) return false;

  return true;
}

const uint16_t PROGMEM fn_actions[] = {

};
