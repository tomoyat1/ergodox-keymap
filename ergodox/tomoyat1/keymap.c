#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  VIM_O,
  VIM_A,
  VIM_CAPITAL_A
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Layer 0: Base layer
  [0] = KEYMAP(
                //left hand
                KC_ESC,         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_LEFT,
                KC_GRV,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_LBRC,
                KC_LCTL,        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
                KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LSFT,
                MO(2),          KC_LGUI,    TG(4),      TG(3),      TG(4),
                                KC_DEL,     KC_INS,
                                           KC_HYPR,
                       KC_SPC,  KC_BSPC,    KC_LSFT,
                //right hand
                KC_EQUAL,   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,           KC_MINUS,
                KC_RBRC,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,           KC_BSLS,
                            KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,        KC_QUOT,
                KC_RSFT,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,        KC_LSFT,
                                        KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,         MO(1),
                KC_LALT,    CTL_T(KC_ESCAPE),
                KC_MEH,
                KC_RSFT,GUI_T(KC_TAB),     SFT_T(KC_ENTER)),

  // Layer 1:  Symbols
  [1] = KEYMAP(
                //left hand
                KC_ESCAPE,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_TRNS,
                KC_TRNS,        KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,    KC_TRNS,
                KC_TRNS,        KC_HASH,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRAVE,
                KC_TRNS,        KC_PERC,    KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_TILD,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,
                                            KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_TRNS,
                //right hand
                KC_TRNS,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,         KC_F11,
                KC_TRNS,    KC_UP,      KC_7,       KC_8,       KC_9,       KC_ASTR,        KC_F12,
                            KC_DOWN,    KC_4,       KC_5,       KC_6,       KC_PLUS,        KC_TRNS,
                KC_TRNS,    KC_AMPR,    KC_1,       KC_2,       KC_3,       KC_BSLS,        KC_TRNS,
                                        KC_TRNS,    KC_DOT,     KC_0,       KC_EQUAL,       KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS),

  // Layer 2:  Mouse
  [2] = KEYMAP(
                //left hand
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_MS_U,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,
                                            KC_TRNS,
                    KC_BTN1,    KC_BTN2,    KC_BTN3,
                //right hand
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    VRSN,           RESET,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_WH_U,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                            KC_TRNS,    KC_WH_L,    KC_WH_D,    KC_WH_R,    KC_TRNS,        KC_MEDIA_PLAY_PAUSE,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_MNXT,    KC_TRNS,        KC_TRNS,
                                        KC_VOLU,    KC_VOLD,    KC_MUTE,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_WBAK),

  // Layer 3: ESDF gaming layout
  [3] = KEYMAP(
                //left hand
                KC_TRNS,        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,
                KC_TRNS,        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
                KC_TRNS,        KC_I,       KC_A,       KC_S,       KC_D,       KC_F,
                KC_TRNS,        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_G,
                KC_TRNS,        KC_TRNS,    KC_LALT,    TO(0),      KC_B,
                                KC_M,       KC_TRNS,
                                            KC_TRNS,
                      KC_SPC,    KC_TRNS,   KC_TRNS,
                //right hand
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS),

  // Layer 4: Universal vim controls
  [4] = KEYMAP(
                //left hand
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    TO(0),      KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,
                                            KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_TRNS,
                //right hand
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(0),      KC_TRNS,    KC_TRNS,        KC_TRNS,
                            KC_LEFT,    KC_DOWN,    KC_UP,     KC_RGHT,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS),

  // Layer 4: Emoji
  [4] = KEYMAP(
                //left hand
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    TO(0),      KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,
                                            KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_TRNS,
                //right hand
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(0),      KC_TRNS,    KC_TRNS,        KC_TRNS,
                            KC_LEFT,    KC_DOWN,    KC_UP,     KC_RGHT,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS)
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    case VIM_O:
      if (record->event.pressed) {
      }
      return false;
      break;
    
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
