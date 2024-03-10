/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_EQL  ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , LT(1,KC_QUOT),
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_LBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_BSLS  ,
    KC_LGUI  , KC_RCTL  , KC_LALT  , KC_GRV   ,LT(1,KC_LNG2),RSFT_T(KC_SPC),LT(3,KC_LNG1),    KC_BSPC, KC_ENT,   LT(1,KC_LNG2), KC_RGUI, _______ , KC_PSCR  , MO(1)
  ),

  [1] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                  XXXXXXX  , XXXXXXX  , KC_UP    , XXXXXXX  , XXXXXXX  , KC_F12   ,
    _______  , XXXXXXX  , KC_BTN3  , KC_BTN2  , KC_BTN1  , XXXXXXX  ,                                  XXXXXXX  , XXXXXXX  , KC_LEFT  , KC_RGHT  , XXXXXXX  , XXXXXXX  ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,            XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_DOWN  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    _______  , _______  , _______  , KC_DEL   , _______  , _______  , _______  ,            KC_DEL   , _______  , _______  , _______  , _______  , XXXXXXX  , _______
  ),
  //Unused
  [2] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  _______  , KC_LEFT  , KC_UP    , KC_RGHT  , _______  , KC_F12   ,
    _______  , _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_PGUP  , KC_BTN1  , KC_DOWN  , KC_BTN2  , KC_BTN3  , _______  ,
    _______  , _______  , KC_1     , KC_2     , KC_3     ,S(KC_MINS), S(KC_8)  ,            S(KC_9)  , KC_PGDN  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , KC_0     , KC_DOT   , _______  , _______  , _______  ,             KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    CPI_I100 , CPI_I1K  , XXXXXXX  , XXXXXXX  , XXXXXXX  , SCRL_DVD ,                                  XXXXXXX  , XXXXXXX  , KC_P7    , KC_P8    , KC_P9    , KC_PAST  ,
    CPI_D100 , CPI_D1K  , XXXXXXX  , XXXXXXX  , XXXXXXX  , SCRL_DVI ,                                  XXXXXXX  , XXXXXXX  , KC_P4    , KC_P5    , KC_P6    , KC_PMNS  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                  XXXXXXX  , XXXXXXX  , KC_P1    , KC_P2    , KC_P3    , KC_PPLS  ,
    XXXXXXX  , KBC_SAVE , XXXXXXX  , KBC_RST  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,            XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_P0    , KC_P0    , KC_PDOT  , KC_PENT  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_PSLS  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
