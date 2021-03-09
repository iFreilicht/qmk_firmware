/* Copyright 2018 Felix Uhl
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

#ifndef KEMAP_US_INTERNATIONAL_H
#define KEMAP_US_INTERNATIONAL_H

#include "keymap.h"

// =====================================================================
// = This keymap extra provides aliases for all symbols that can be    =
// = input directly using the US International layout with dead keys.  =
// = It also provides a function to "revive" dead keys, which makes    =
// = them function just like they do on the regular US layout.         =
// =====================================================================

// Aliasing original names of dead keys
#define US_CIRC KC_CIRC
#define US_QUOT KC_QUOT
#define US_DQT KC_DQT
#define US_GRV KC_GRV
#define US_TILD KC_TILD

// Tagged names for intentionally dead keys
// These can be used if specific dead keys are desired, for example
// if some glyphs need to be entered that require a dead key
// These interfere with some macro IDs when in use.
#define TAG_FOR_INTENTIONALLY_DEAD_KEYS QK_MACRO

#define US_DEAD_CIRCUMFLEX (TAG_FOR_INTENTIONALLY_DEAD_KEYS | US_CIRC)
#define US_DCRC US_DEAD_CIRCUMFLEX

#define US_DEAD_QUOTE (TAG_FOR_INTENTIONALLY_DEAD_KEYS | US_QUOT)
#define US_DQOT US_DEAD_QUOTE

#define US_DEAD_DOUBLE_QUOTE (TAG_FOR_INTENTIONALLY_DEAD_KEYS | US_DQT)
#define US_DDQT US_DEAD_DOUBLE_QUOTE

#define US_DEAD_GRAVE (TAG_FOR_INTENTIONALLY_DEAD_KEYS | US_GRV)
#define US_DGRV US_DEAD_GRAVE

#define US_DEAD_TILDE (TAG_FOR_INTENTIONALLY_DEAD_KEYS | US_TILD)
#define US_DTLD US_DEAD_TILDE

// Actual revival of the dead keys
//==============================================================
//=  THIS FUNCTION NEEDS TO BE CALLED IN process_record_user!  =
//==============================================================
bool process_record_revive_dead_keys(uint16_t keycode, keyrecord_t *record) {
    // Check whether the pressed key is left dead intentionally
    bool intentionally_dead = keycode & TAG_FOR_INTENTIONALLY_DEAD_KEYS;

    // Clear bit marking intentionally dead keys
    keycode = keycode & ~TAG_FOR_INTENTIONALLY_DEAD_KEYS;

    // Check whether we need to handle the pressed key
    switch (keycode) {
        // These are dead for sure
        case US_CIRC:
        case US_QUOT:
        case US_DQT:
        case US_GRV:
        case US_TILD:
            break;
        // If a ^ was entered by holding shift and pressing 6,
        // keycode will not be US_CIRC, so we have to check separately
        case KC_6:
            if (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
                break;
            }
            return true;
        // All other keys are not interesting for us
        default:
            return true;
    }

    // Handle the actual keypress
    if (record->event.pressed) {
        // press key as usual
        register_code16(keycode);

        // revive if desired
        if (!intentionally_dead) {
            // space is only tapped so as to not interfere with
            // the original key being held down
            SEND_STRING(" ");
        }
    } else {
        // release key as usual
        unregister_code16(keycode);
    }
    return false;
}

// Keycode macros for AltGr symbols of the US International Layout
#define US_POWER_OF_1 SAGR(KC_1)  // ¹
#define US_POW1 US_POWER_OF_1

#define US_INVERTED_EXCLAIM ALGR(KC_1)  // ¡
#define US_IEXL US_INVERTED_EXCLAIM

#define US_POWER_OF_2 ALGR(KC_2)  // ²
#define US_POW2 US_POWER_OF_2

#define US_POWER_OF_3 ALGR(KC_3)  // ³
#define US_POW3 US_POWER_OF_3

#define US_CURRENCY ALGR(KC_4)  // ¤
#define US_CURR US_CURRENCY

#define US_POUND SAGR(KC_4)  // £
#define US_POUN US_POUND

#define US_EURO ALGR(KC_5)  // €

#define US_1_OVER_4 ALGR(KC_6)  // ¼
#define US_1OV4 US_1_OVER_4

#define US_1_OVER_2 ALGR(KC_7)  // ½
#define US_1OV2 US_1_OVER_2

#define US_3_OVER_4 ALGR(KC_8)  // ¾
#define US_3OV4 US_3_OVER_4

#define US_SINGLE_QUOTE_LEFT ALGR(KC_9)  // ‘
#define US_SQTL US_SINGLE_QUOTE_LEFT

#define US_SINGLE_QUOTE_RIGHT ALGR(KC_0)  // ’
#define US_SQTR US_SINGLE_QUOTE_RIGHT

#define US_YUAN ALGR(KC_MINS)  // ¥
#define US_YEN US_YUAN

#define US_MULTIPLICATION ALGR(KC_EQL)  // ×
#define US_MUL US_MULTIPLICATION

#define US_DIVISION SAGR(KC_EQL)  // ÷
#define US_DIV US_DIVISION

#define US_A_UMLAUT ALGR(KC_Q)  // ä Ä
#define US_A_UM US_A_UMLAUT

#define US_A_RING ALGR(KC_W)  // å Å
#define US_A_RG US_A_RING

#define US_E_ACUTE ALGR(KC_E)  // é É
#define US_E_AC US_E_ACUTE

#define US_REGISTERED_TRADEMARK ALGR(KC_R)  // ®
#define US_RETM US_REGISTERED_TRADEMARK

#define US_THORN ALGR(KC_T)  // þ Þ
#define US_TORN US_THORN

#define US_U_UMLAUT ALGR(KC_Y)  // ü Ü
#define US_U_UM US_U_UMLAUT

#define US_U_ACUTE ALGR(KC_U)  // ú Ú
#define US_U_AC US_U_ACUTE

#define US_I_ACUTE ALGR(KC_I)  // í Í
#define US_I_AC US_I_ACUTE

#define US_O_ACUTE ALGR(KC_O)  // ó Ó
#define US_O_AC US_O_ACUTE

#define US_O_UMLAUT ALGR(KC_P)  // ö Ö
#define US_O_UM US_O_UMLAUT

#define US_ANGLE_QUOTE_LEFT ALGR(KC_LBRC)  // «
#define US_AQTL US_ANGLE_QUOTE_LEFT

#define US_ANGLE_QUOTE_RIGHT ALGR(KC_RBRC)  // »
#define US_AQTR US_ANGLE_QUOTE_RIGHT

#define US_NEGATION ALGR(KC_BSLS)  // ¬
#define US_NEG US_NEGATION

#define US_BROKEN_BAR SAGR(KC_BSLS)  // ¦
#define US_BRBR US_BROKEN_BAR

#define US_A_ACUTE ALGR(KC_A)  // á
#define US_A_AC US_A_ACUTE

#define US_SHARP_S ALGR(KC_S)  // ß
#define US_ESZETT US_SHARP_S
#define US_SS US_SHARP_S

#define US_SECTION SAGR(KC_S)  // §
#define US_SECT US_SECTION

#define US_ETH ALGR(KC_D)  // ð Ð

#define US_O_STROKE ALGR(KC_L)  // ø Ø
#define US_O_ST US_O_STROKE

#define US_PILCROW ALGR(KC_SCLN)  // ¶
#define US_PCRW US_PILCROW

#define US_DEGREE SAGR(KC_SCLN)  // °
#define US_DEG US_DEGREE

#define US_ACUTE ALGR(KC_QUOT)  // ´
#define US_ACUT US_ACUTE

#define US_TREMA SAGR(KC_QUOT)  // ¨
#define US_TREM US_TREMA

#define US_ASH ALGR(KC_Z)  // æ Æ

#define US_COPYRIGHT ALGR(KC_C)  // ©
#define US_CPRT US_COPYRIGHT

#define US_CENT SAGR(KC_C)  // ¢

#define US_N_TILDE ALGR(KC_N)  // ñ Ñ
#define US_N_TD US_N_TILDE

#define US_MU ALGR(KC_M)  // μ

#define US_C_CEDILLA ALGR(KC_COMM)  // ç Ç
#define US_C_CE US_C_CEDILLA

#define US_INVERTED_QUESTION ALGR(KC_SLSH)  // ¿
#define US_IQES US_INVERTED_QUESTION

// Keys that are the exact same as on regular US keyboard
#define US_A KC_A
#define US_B KC_B
#define US_C KC_C
#define US_D KC_D
#define US_E KC_E
#define US_F KC_F
#define US_G KC_G
#define US_H KC_H
#define US_I KC_I
#define US_J KC_J
#define US_K KC_K
#define US_L KC_L
#define US_M KC_M
#define US_N KC_N
#define US_O KC_O
#define US_P KC_P
#define US_Q KC_Q
#define US_R KC_R
#define US_S KC_S
#define US_T KC_T
#define US_U KC_U
#define US_V KC_V
#define US_W KC_W
#define US_X KC_X
#define US_Y KC_Y
#define US_Z KC_Z

#define US_1 KC_1
#define US_2 KC_2
#define US_3 KC_3
#define US_4 KC_4
#define US_5 KC_5
#define US_6 KC_6
#define US_7 KC_7
#define US_8 KC_8
#define US_9 KC_9
#define US_0 KC_0

#define US_F1 KC_F1
#define US_F2 KC_F2
#define US_F3 KC_F3
#define US_F4 KC_F4
#define US_F5 KC_F5
#define US_F6 KC_F6
#define US_F7 KC_F7
#define US_F8 KC_F8
#define US_F9 KC_F9
#define US_F10 KC_F10
#define US_F11 KC_F11
#define US_F12 KC_F12
#define US_F13 KC_F13
#define US_F14 KC_F14
#define US_F15 KC_F15
#define US_F16 KC_F16
#define US_F17 KC_F17
#define US_F18 KC_F18
#define US_F19 KC_F19
#define US_F20 KC_F20
#define US_F21 KC_F21
#define US_F22 KC_F22
#define US_F23 KC_F23
#define US_F24 KC_F24

#define US_SCLN KC_SCLN
#define US_COMM KC_COMM
#define US_DOT KC_DOT
#define US_SLSH KC_SLSH
#define US_EXLM KC_EXLM
#define US_UNDS KC_UNDS
#define US_MINS KC_MINS
#define US_LCBR KC_LCBR
#define US_RCBR KC_RCBR
#define US_DLR KC_DLR
#define US_PERC KC_PERC
#define US_PLUS KC_PLUS
#define US_EQL KC_EQL
#define US_LPRN KC_LPRN
#define US_RPRN KC_RPRN
#define US_AMPR KC_AMPR
#define US_LABK KC_LABK
#define US_LBRC KC_LBRC
#define US_RBRC KC_RBRC
#define US_RABK KC_RABK
#define US_ASTR KC_ASTR
#define US_BSLS KC_BSLS

#define US_P1 KC_P1
#define US_P2 KC_P2
#define US_P3 KC_P3
#define US_P4 KC_P4
#define US_P5 KC_P5
#define US_P6 KC_P6
#define US_P7 KC_P7
#define US_P8 KC_P8
#define US_P9 KC_P9
#define US_P0 KC_P0
#define US_PDOT KC_PDOT
#define US_PCMM KC_PCMM
#define US_PSLS KC_PSLS
#define US_PAST KC_PAST
#define US_PMNS KC_PMNS
#define US_PPLS KC_PPLS
#define US_PEQL KC_PEQL
#define US_PENT KC_PENT

#define US_TAB KC_TAB
#define US_ENT KC_ENT
#define US_LSFT KC_LSFT
#define US_LCTL KC_LCTL
#define US_LALT KC_LALT
#define US_LGUI KC_LGUI
#define US_SPC KC_SPC
#define US_DEL KC_DEL
#define US_BSPC KC_BSPC
#define US_RSFT KC_RSFT
#define US_RCTL KC_RCTL
#define US_RALT KC_RALT
#define US_RGUI KC_RGUI
#define US_ESC KC_ESC
#define US_PSCR KC_PSCR
#define US_SLCK KC_SLCK
#define US_PAUS KC_PAUS
#define US_INS KC_INS
#define US_HOME KC_HOME
#define US_PGUP KC_PGUP
#define US_END KC_END
#define US_PGDN KC_PGDN
#define US_LEFT KC_LEFT
#define US_RGHT KC_RGHT
#define US_UP KC_UP
#define US_DOWN KC_DOWN

#endif