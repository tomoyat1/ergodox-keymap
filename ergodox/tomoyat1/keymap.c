#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0
#define SYMBOLS 1
#define MOUSE 2
#define ESDF 3
#define VIM_NORMAL 4
#define VIM_NORMAL_SHIFTED 5
#define VIM_VISUAL_LINE 6
#define EMOJI 9

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  CLEAR,
  QUIT_VIM,
  VIM_A,
  VIM_O,
  VIM_SHIFT_A,
  VIM_SHIFT_I,
  VIM_SHIFT_O,
  VIM_U,
  VIM_X,
  VIM_V,
  VIM_SHIFT_V,
  VIM_VS_DW,
  VIM_VS_UP,
  VIM_ESC_VIS,
  VIM_Y,
  VIM_P,
  VIM_SHIFT_P,
};

int is_visual_mode = false;
int is_visual_line_mode = false;
int is_clipboard_visual_line = false;

enum tap_dance_keycodes {
  VIM_DD,
  VIM_YY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Layer 0: Base layer
  [BASE] = LAYOUT_ergodox(
                //left hand
                KC_EQUAL,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       CLEAR,
                KC_GRV,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       LGUI(LSFT(KC_ENT)),
                KC_LCTL,        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
                KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       MEH(KC_SPC),
                TG(4),          KC_LGUI,    KC_LALT,    TG(3),      MO(2),
                                KC_DEL,     KC_INS,
                                           KC_MEH,
                           KC_SPC, KC_BSPC,KC_PSCR,
                //right hand
                TG(1),       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,           KC_MINUS,
                LGUI(KC_ENT),KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,           KC_BSLS,
                            KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,        KC_QUOT,
                KC_TAB,     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,        KC_LSFT,
                                        MO(1),      KC_HOME,    KC_PGDN,    KC_PGUP,        KC_END,
                KC_RALT,    CTL_T(KC_ESC),
                KC_HYPR,
                KC_PAUS, GUI_T(KC_ENT), KC_RSFT),

  // Layer 1:  Symbols
  [SYMBOLS] = LAYOUT_ergodox(
                //left hand
                KC_ESCAPE,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_TRNS,
                KC_TRNS,        KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_EQUAL,   KC_TRNS,
                KC_TRNS,        KC_HASH,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_MINUS,
                KC_TRNS,        KC_PERC,    KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_TILD,    KC_TRNS,
                KC_TRNS,        KC_AMPR,    KC_ASTR,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,
                                            KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_TRNS,
                //right hand
                KC_TRNS,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,         KC_F11,
                KC_TRNS,    KC_BSLS,    KC_7,       KC_8,       KC_9,       KC_ASTR,        KC_F12,
                            KC_DOWN,    KC_4,       KC_5,       KC_6,       KC_PLUS,        KC_TRNS,
                KC_TRNS,    KC_AMPR,    KC_1,       KC_2,       KC_3,       KC_BSLS,        KC_TRNS,
                                        KC_TRNS,    KC_0,       KC_DOT,     KC_EQUAL,       KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS),

  // Layer 2:  Mouse
  [MOUSE] = LAYOUT_ergodox(
                //left hand
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_MS_U,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,
                                            KC_TRNS,
                    KC_WBAK,    KC_WFWD,    KC_NO,
                //right hand
                KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_MPLY,    KC_MSTP,    KC_MNXT,        RESET,
                KC_TRNS,    KC_VOLU,    KC_TRNS,    KC_WH_U,    KC_TRNS,    KC_TRNS,        VRSN,
                            KC_VOLD,    KC_WH_L,    KC_WH_D,    KC_WH_R,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_MUTE,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_BTN2,    KC_BTN3,    KC_BTN1),

  // Layer 3: ESDF gaming layout
  [ESDF] = LAYOUT_ergodox(
                //left hand
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
                KC_TRNS,        KC_I,       KC_A,       KC_S,       KC_D,       KC_F,
                KC_TRNS,        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_G,
                KC_TRNS,        KC_TRNS,    KC_LALT,    TO(0),      KC_B,
                                KC_M,       KC_TRNS,
                                            KC_TRNS,
                      KC_SPC,    KC_ENTER,  KC_LALT,
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
  [VIM_NORMAL] = LAYOUT_ergodox(
                //left hand
                KC_NO,          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        VIM_A,      KC_TRNS,    TD(VIM_DD), KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    VIM_X,      KC_TRNS,    VIM_V,      KC_TRNS,    KC_TRNS,
                QUIT_VIM,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,
                                            KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_TRNS,
                //right hand
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    TD(VIM_YY), VIM_U,      QUIT_VIM,   VIM_O,      VIM_P,          KC_TRNS,
                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    VIM_ESC_VIS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    MO(5)),

  // Layer 5: Universal vim controls shifted
  [VIM_NORMAL_SHIFTED] = LAYOUT_ergodox(
                //left hand
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        VIM_SHIFT_A,KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(6),      KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,
                                            KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_TRNS,
                //right hand
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    VIM_SHIFT_I,VIM_SHIFT_O,KC_TRNS,        KC_TRNS,
                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_LEAD,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS),
  // Layer 6: Universal vim controls visual line
  [VIM_VISUAL_LINE] = LAYOUT_ergodox(
                //left hand
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_NO,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,        KC_TRNS,    KC_TRNS,      KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,
                                            KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_TRNS,
                //right hand
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    VIM_SHIFT_I,VIM_SHIFT_O,KC_TRNS,        KC_TRNS,
                            KC_NO,      VIM_VS_DW,  VIM_VS_UP,  KC_NO,      KC_TRNS,        KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                KC_TRNS,    VIM_ESC_VIS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS),
  // Layer 9: Emoji
  [EMOJI] = LAYOUT_ergodox(
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
    case CLEAR:
      if (record->event.pressed) {
        SEND_STRING (SS_LCTRL("l"));
      }
      return false;
      break;
    case QUIT_VIM:
      if (record->event.pressed) {
        SEND_STRING (SS_UP(X_LSHIFT));
        layer_off(4);
      }
      return false;
      break;
    case VIM_A:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_RIGHT));
        SEND_STRING (SS_UP(X_LSHIFT));
        layer_off(4);
      }
      return false;
      break;
    case VIM_SHIFT_A:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_END));
        SEND_STRING (SS_UP(X_LSHIFT));
        layer_off(5);
        layer_off(4);
      }
      return false;
      break;
    case VIM_O:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_END)SS_TAP(X_ENTER));
        SEND_STRING (SS_UP(X_LSHIFT));
        layer_off(4);
      }
      return false;
      break;
    case VIM_SHIFT_O:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_HOME)SS_TAP(X_ENTER));
        layer_off(5);
        SEND_STRING (SS_UP(X_LSHIFT));
        layer_off(4);
        SEND_STRING (SS_TAP(X_UP));
      }
      return false;
      break;
    case VIM_SHIFT_I:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_HOME));
        layer_off(5);
        SEND_STRING (SS_UP(X_LSHIFT));
        layer_off(4);
      }
      return false;
      break;
    case VIM_DD:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_HOME));
        SEND_STRING (SS_DOWN(X_LSHIFT));
        SEND_STRING (SS_TAP(X_END));
        SEND_STRING (SS_UP(X_LSHIFT));
        SEND_STRING (SS_LCTRL("x"));
        SEND_STRING (SS_TAP(X_DELETE));
      }
      return false;
      break;
    case VIM_P:
      if (record->event.pressed) {
        if (is_clipboard_visual_line) {
          SEND_STRING (SS_TAP(X_END)SS_TAP(X_ENTER));
          SEND_STRING (SS_LCTRL("v"));
        } else {
          SEND_STRING (SS_TAP(X_RIGHT));
          SEND_STRING (SS_LCTRL("v"));
        }
      }
      return false;
      break;
    case VIM_SHIFT_P:
      if (record->event.pressed) {
        if (is_clipboard_visual_line) {
          SEND_STRING (SS_TAP(X_HOME)SS_TAP(X_ENTER));
          SEND_STRING (SS_LCTRL("v"));
        } else {
          SEND_STRING (SS_LCTRL("v"));
        }
      }
      return false;
      break;
    case VIM_U:
      if (record->event.pressed) {
        SEND_STRING (SS_LCTRL("z"));
      }
      return false;
      break;
    case VIM_V:
      if (record->event.pressed) {
        is_visual_mode = true;
        SEND_STRING (SS_DOWN(X_LSHIFT));
        SEND_STRING (SS_TAP(X_RIGHT));
      }
      return false;
      break;
    case VIM_SHIFT_V:
      if (record->event.pressed) {
        is_visual_mode = true;
        is_visual_line_mode = true;
        layer_on(6);
        SEND_STRING (SS_TAP(X_HOME));
        SEND_STRING (SS_DOWN(X_LSHIFT));
        SEND_STRING (SS_TAP(X_END));
      }
      return false;
      break;
    case VIM_ESC_VIS:
      if (record->event.pressed) {
        if (is_visual_mode) {
          is_visual_mode = false;
          is_visual_line_mode = false;
          SEND_STRING (SS_UP(X_LSHIFT));
          SEND_STRING (SS_TAP(X_LEFT)SS_TAP(X_LEFT));
          layer_off(6);
          /*
           * Unselects current text selection
           * Conflicts with application-side vim-like key bindings
           */
          SEND_STRING (SS_TAP(X_ESCAPE));
        } else {
          /* Unselects current text selection */
          SEND_STRING (SS_TAP(X_ESCAPE));
        }
      }
      return false;
      break;
    case VIM_VS_DW:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_DOWN)SS_TAP(X_HOME)SS_TAP(X_END));
      }
      return false;
      break;
    case VIM_VS_UP:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_UP)SS_TAP(X_HOME)SS_TAP(X_END));
      }
      return false;
      break;
    case VIM_X:
      if (record->event.pressed) {
        if (is_visual_mode) {
          SEND_STRING (SS_UP(X_LSHIFT)); //for visual mode
          SEND_STRING (SS_LCTRL("x"));
          is_visual_mode = false;
          if (is_visual_line_mode) {
            is_clipboard_visual_line = true;
          } else {
            is_clipboard_visual_line = false;
          }
        } else {
          SEND_STRING (SS_DOWN(X_LSHIFT));
          SEND_STRING (SS_TAP(X_RIGHT));
          SEND_STRING (SS_UP(X_LSHIFT));
          SEND_STRING (SS_LCTRL("x"));
          is_clipboard_visual_line = false;
        }
      }
      return false;
      break;
    case VIM_Y:
      if (record->event.pressed) {
        if (is_visual_mode) {
          SEND_STRING (SS_UP(X_LSHIFT)); // for visual mode
          SEND_STRING (SS_LCTRL("c"));
          SEND_STRING (SS_TAP(X_LEFT));
          is_visual_mode = false;
          if (is_visual_line_mode) {
            is_clipboard_visual_line = true;
          } else {
            is_clipboard_visual_line = false;
          }
        }
        is_clipboard_visual_line = false;
      }
      return false;
      break;
  }
  return true;
}

void vim_dd(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    SEND_STRING (SS_TAP(X_HOME));
    SEND_STRING (SS_DOWN(X_LSHIFT));
    SEND_STRING (SS_TAP(X_END));
    SEND_STRING (SS_UP(X_LSHIFT));
    SEND_STRING (SS_LCTRL("x"));
    SEND_STRING (SS_TAP(X_HOME));
    SEND_STRING (SS_TAP(X_BSPACE));
    is_clipboard_visual_line = true;
  }
}

void vim_yy(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (is_visual_mode) {
      SEND_STRING (SS_UP(X_LSHIFT)); // for visual mode
      SEND_STRING (SS_LCTRL("c"));
      SEND_STRING (SS_TAP(X_LEFT));
      is_visual_mode = false;
      if (is_visual_line_mode) {
        is_clipboard_visual_line = true;
      } else {
        is_clipboard_visual_line = false;
      }
    }
    is_clipboard_visual_line = false;
  } else if (state->count == 2) {
    SEND_STRING (SS_TAP(X_HOME));
    SEND_STRING (SS_DOWN(X_LSHIFT));
    SEND_STRING (SS_TAP(X_END));
    SEND_STRING (SS_UP(X_LSHIFT));
    SEND_STRING (SS_LCTRL("c"));
    SEND_STRING (SS_TAP(X_HOME));
    is_clipboard_visual_line = true;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [VIM_DD] = ACTION_TAP_DANCE_FN (vim_dd),
  [VIM_YY] = ACTION_TAP_DANCE_FN (vim_yy)
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_W) {
      SEND_STRING (SS_LCTRL("s"));
    }

    SEQ_ONE_KEY(KC_E) {
      SEND_STRING (SS_LCTRL("o"));
    }

    SEQ_ONE_KEY(KC_O) {
      SEND_STRING (SS_LCTRL("o"));
    }
  }
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
/* vim: set ts=2 sts=2 sw=2 expandtab: */
