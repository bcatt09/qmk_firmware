#include QMK_KEYBOARD_H
#include "version.h"

#define COLEMAK 0 // default Colemak layer
#define GAMING 1 // layer for gaming
#define QWERTY 2 // QWERTY  layer
#define NAV 3 // arrow keys and some symbols
#define NUM 4 // numberpad and mouse keys
#define QWERTYSWAPLEFT 5 // layer to toggle QWERTY if left is pressed first
#define QWERTYSWAPRIGHT 6 // layer to toggle QWERTY if right is pressed first

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Colemak layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   ESC  |   1  |   2  |   3  |   4  |   5  |  Grv |           |      |   6  |   7  |   8  |   9  |   0  | Bckspc |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |   Tab  |   Q  |   W  |   F  |   P  |   G  | Space|           |      |   J  |   L  |   U  |   Y  |  ; : |  / |   |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |  LCtrl |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |  O   |   ' "  |
   * |--------+------+------+------+------+------|   Y  |           |      |------+------+------+------+------+--------|
   * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |  /   | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | LGUI |      |      |      | LAlt |                                       | RAlt |  [   |   ]  |      | RGUI |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | Del  | MO 5 |       | MO 6 |  App |
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      |CpsLck|       | Del  |        |      |
   *                                 | BckSp| MO 2 |------|       |------|  Enter | Space|
   *                                 |      |      | MO 3 |       | MO 2 |        |      |
   *                                 `--------------------'       `----------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [COLEMAK] = LAYOUT_ergodox(  // layer 0 : default
          // left hand
          KC_ESC,    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_GRV,
          KC_TAB,    KC_Q,    KC_W,   KC_F,   KC_P,   KC_G,   KC_SPACE,
          KC_LCTRL,  KC_A,    KC_R,   KC_S,   KC_T,   KC_D,
          KC_LSFT,   KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_Y,
          KC_LGUI,  KC_NO,   KC_NO,  KC_NO, KC_LALT,
                                         KC_DELETE, MO(QWERTYSWAPLEFT),
                                                           KC_CAPSLOCK,
                                           KC_BSPACE, MO(NAV), MO(NUM),
          // right hand
               KC_NO,       KC_6,   KC_7,        KC_8,        KC_9,      KC_0, KC_BSPACE,
               KC_EQUAL,    KC_J,   KC_L,        KC_U,        KC_Y, KC_SCOLON, KC_BSLASH,
                            KC_H,   KC_N,        KC_E,        KC_I,      KC_O,  KC_QUOTE,
               KC_MINUS,    KC_K,   KC_M,    KC_COMMA,      KC_DOT,   KC_SLSH,   KC_RSFT,
                                 KC_RALT, KC_LBRACKET, KC_RBRACKET,     KC_NO,   KC_RGUI,
               MO(QWERTYSWAPRIGHT),  KC_APPLICATION,
                         KC_DELETE,
                           MO(NAV),   KC_ENTER, KC_SPACE
      ),
    /* Keymap 1: Gaming layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ESC  |   1  |   2  |   3  |   4  |   5  |   6  |           |      |   6  |   7  |   8  |   9  |   0  | Bckspc |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   Tab  |   Q  |   W  |   E  |   R  |   T  | - _  |           |  + = |   Y  |   U  |   I  |   O  |   P  |  / |   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  LCtrl |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  : ; |   ' "  |
     * |--------+------+------+------+------+------| Enter|           |  ] } |------+------+------+------+------+--------|
     * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LCtrl|      |      | LGUI | LAlt |                                       | RAlt | RGUI |      |  App |RCtrl |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Del  | MO 5 |       | MO 6 |  App |
     *                                 ,------|------|------|       |------+--------+------.
     *                                 |      |      |CpsLck|       | Del  |        |      |
     *                                 | Space| MO 2 |------|       |------|  Enter | Space|
     *                                 |      |      | MO 3 |       | MO 2 |        |      |
     *                                 `--------------------'       `----------------------'
     */
     // GAMING
    [GAMING] = LAYOUT_ergodox(
            // left hand
              KC_ESC,  KC_1,    KC_2,     KC_3,    KC_4,   KC_5,     KC_6,
              KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,   KC_T,   KC_MINUS,
            KC_LCTRL,  KC_A,    KC_S,     KC_D,    KC_F,   KC_G,
             KC_LSFT,  KC_Z,    KC_X,     KC_C,    KC_V,   KC_B,   KC_ENTER,
            KC_LCTRL, KC_NO,   KC_NO,  KC_LGUI, KC_LALT,
                                              KC_DELETE, MO(QWERTYSWAPLEFT),
                                                                KC_CAPSLOCK,
                                                KC_SPACE, MO(NAV), MO(NUM),
            // right hand
                 KC_NO,       KC_6,   KC_7,        KC_8,        KC_9,      KC_0, KC_BSPACE,
                 KC_EQUAL,    KC_Y,   KC_U,        KC_I,        KC_O,      KC_P, KC_BSLASH,
                              KC_H,   KC_J,        KC_K,        KC_L, KC_SCOLON,  KC_QUOTE,
                 KC_RBRACKET, KC_N,   KC_M,    KC_COMMA,      KC_DOT,   KC_SLSH,   KC_RSFT,
                                   KC_RALT,     KC_RGUI,       KC_NO,    KC_APP,  KC_RCTRL,
                 MO(QWERTYSWAPRIGHT),  KC_APPLICATION,
                           KC_DELETE,
                             MO(NAV),   KC_ENTER, KC_SPACE
        ),
        /* Keymap 2: QWERTY layer
         *
         * ,--------------------------------------------------.           ,--------------------------------------------------.
         * |   ESC  |   1  |   2  |   3  |   4  |   5  |  Grv |           |      |   6  |   7  |   8  |   9  |   0  | Bckspc |
         * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
         * |   Tab  |   Q  |   W  |   E  |   R  |   T  | - _  |           |  + = |   Y  |   U  |   I  |   O  |   P  |  / |   |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |  CAPS  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  : ; |   ' "  |
         * |--------+------+------+------+------+------|  [ { |           |  ] } |------+------+------+------+------+--------|
         * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
         * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         *   | LCtrl|      |      | LGUI | LAlt |                                       | RAlt | RGUI |      |  App |RCtrl |
         *   `----------------------------------'                                       `----------------------------------'
         *                                        ,-------------.       ,-------------.
         *                                        | Del  | MO 5 |       | MO 6 |  App |
         *                                 ,------|------|------|       |------+--------+------.
         *                                 |      |      |CpsLck|       | Del  |        |      |
         *                                 | BckSp| MO 2 |------|       |------|  Enter | Space|
         *                                 |      |      | MO 3 |       | MO 2 |        |      |
         *                                 `--------------------'       `----------------------'
         */
         // QWERTY
        [QWERTY] = LAYOUT_ergodox(
                // left hand
                  KC_ESC,  KC_1,    KC_2,     KC_3,    KC_4,   KC_5,     KC_GRV,
                  KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,   KC_T,   KC_MINUS,
             KC_CAPSLOCK,  KC_A,    KC_S,     KC_D,    KC_F,   KC_G,
                 KC_LSFT,  KC_Z,    KC_X,     KC_C,    KC_V,   KC_B,KC_LBRACKET,
                KC_LCTRL, KC_NO,   KC_NO,  KC_LGUI, KC_LALT,
                                                  KC_DELETE, MO(QWERTYSWAPLEFT),
                                                                    KC_CAPSLOCK,
                                                    KC_BSPACE, MO(NAV), MO(NUM),
                // right hand
                     KC_NO,       KC_6,   KC_7,        KC_8,        KC_9,      KC_0, KC_BSPACE,
                     KC_EQUAL,    KC_Y,   KC_U,        KC_I,        KC_O,      KC_P, KC_BSLASH,
                                  KC_H,   KC_J,        KC_K,        KC_L, KC_SCOLON,  KC_QUOTE,
                     KC_RBRACKET, KC_N,   KC_M,    KC_COMMA,      KC_DOT,   KC_SLSH,   KC_RSFT,
                                       KC_RALT,     KC_RGUI,       KC_NO,    KC_APP,  KC_RCTRL,
                     MO(QWERTYSWAPRIGHT),  KC_APPLICATION,
                               KC_DELETE,
                                 MO(NAV),   KC_ENTER, KC_SPACE
            ),
      /* Keymap 3: Navigation/Symbols Layer
       *
       * ,---------------------------------------------------.           ,--------------------------------------------------.
       * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |   Del  |
       * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
       * |         |      |      |  Up  |      |      | Enter|           |      |  + = |   (  |  Up  |   )  |      |        |
       * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |         |      | Left | Down | Right|      |------|           |------| Home | Left | Down | Right|      |        |
       * |---------+------+------+------+------+------|  N   |           |      |------+------+------+------+------+--------|
       * |         |      |      |      |      |      |      |           |      |  End |  [ { |  - _ |  [ { |      |        |
       * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
       *   |       |      |      |      |      |                                       |      |      |      |      |      |
       *   `-----------------------------------'                                       `----------------------------------'
       *                                        ,-------------.       ,-------------.
       *                                        |      |PrntSc|       |PrntSc|      |
       *                                 ,------|------|------|       |------+------+------.
       *                                 |      |      |      |       |      |      |      |
       *                                 | Del  |      |------|       |------|      |      |
       *                                 |      |      |      |       |      |      |      |
       *                                 `--------------------'       `--------------------'
       */
      // NAVIGATION/SYMBOLS
      [NAV] = LAYOUT_ergodox(
             // left hand
             KC_TRNS,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F11,
             KC_TRNS,  KC_NO,  KC_NO,  KC_UP,  KC_NO,  KC_NO, KC_ENTER,
             KC_TRNS,  KC_NO,KC_LEFT,KC_DOWN,KC_RGHT,  KC_NO,
             KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,     KC_N,
             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                               KC_NO, KC_PSCREEN,
                                                         KC_TRNS,
                                     KC_DELETE, KC_TRNS, KC_TRNS,
             // right hand
              KC_F12,    KC_F6,           KC_F7,   KC_F8,             KC_F9,  KC_F10, KC_DELETE,
             KC_TRNS, KC_EQUAL,   KC_LEFT_PAREN,   KC_UP,    KC_RIGHT_PAREN, KC_TRNS,   KC_TRNS,
                       KC_HOME,         KC_LEFT, KC_DOWN,          KC_RIGHT,   KC_NO,   KC_TRNS,
             KC_TRNS,   KC_END,     KC_LBRACKET,KC_MINUS,       KC_RBRACKET,   KC_NO,   KC_TRNS,
                                        KC_TRNS,   KC_NO,             KC_NO,   KC_NO,   KC_TRNS,
             KC_PSCREEN, KC_NO,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
      ),
    /* Keymap 4: Numberpad and mouse keys
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |NumLck|      |      |      |      |  +   |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      | Rclk |MsWhUp| Lclk |      |      |           |      |      |   7  |   8  |   9  |  -   |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |MsWhLt|MsWhDn|MsWhRt|      |------|           |------|      |   4  |   5  |   6  |  *   | Enter  |
     * |--------+------+------+------+------+------|  K   |           |      |------+------+------+------+------+--------|
     * |        |      | Rclk | MsUp | Lclk |      |      |           |      |      |   3  |   2  |   1  |  /   |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |MsLeft|MsDown|MsRght|                                       |   0  |   0  |   .  |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      | BckSp|      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    // NUMBERPAD AND MOUSE
    [NUM] = LAYOUT_ergodox(
           KC_TRNS, KC_NO,         KC_NO,         KC_NO,          KC_NO, KC_NO,   KC_NO,
           KC_TRNS, KC_NO,    KC_MS_BTN2,   KC_MS_WH_UP,     KC_MS_BTN1, KC_NO, KC_TRNS,
           KC_TRNS, KC_NO, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_NO,
           KC_TRNS, KC_NO,       KC_BTN2,      KC_MS_UP,        KC_BTN1, KC_NO,    KC_K,
           KC_TRNS, KC_NO,    KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT,
                                                              KC_TRNS,   KC_NO,
                                                                       KC_TRNS,
                                                     KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
           KC_NUMLOCK,  KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_KP_PLUS,  KC_TRNS,
              KC_TRNS,  KC_NO, KC_KP_7, KC_KP_8, KC_KP_9,    KC_KP_MINUS,    KC_NO,
                        KC_NO, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_ENTER,
              KC_TRNS,  KC_NO, KC_KP_1, KC_KP_2, KC_KP_3,    KC_KP_SLASH,  KC_TRNS,
                              KC_KP_0, KC_KP_0, KC_KP_DOT,  KC_NO,  KC_TRNS,
           KC_NO, KC_TRNS,
           KC_TRNS,
           KC_TRNS, KC_BSPACE, KC_TRNS
    ),
    /* Keymap 5: QWERTY Swap Layer (Left)
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |  V   |       | TG 4 |      |
     *                                 ,------|------|------|       |------+--------+------.
     *                                 |      |      |      |       |      |        |      |
     *                                 | TG 2 | TG 2 |------|       |------|  TG 2  | TG 2 |
     *                                 |      |      |      |       |      |        |      |
     *                                 `--------------------'       `----------------------'
     */
     // QWERTY Swap Starting with Left Hand
    [QWERTYSWAPLEFT] = LAYOUT_ergodox(
            // left hand
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                             KC_NO, KC_TRNS,
                                                      KC_NO,
                              TG(GAMING), TG(GAMING), KC_NO,
            // right hand
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            TG(QWERTY), KC_NO,
            KC_NO,
            KC_NO, TG(GAMING), TG(GAMING)
        ),
      /* Keymap 6: QWERTY Swap Layer (Right)
       *
       * ,--------------------------------------------------.           ,--------------------------------------------------.
       * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
       * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
       * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
       *   |      |      |      |      |      |                                       |      |      |      |      |      |
       *   `----------------------------------'                                       `----------------------------------'
       *                                        ,-------------.       ,-------------.
       *                                        |      | TG 4 |       |   V  |      |
       *                                 ,------|------|------|       |------+--------+------.
       *                                 |      |      |      |       |      |        |      |
       *                                 | TG 2 | TG 2 |------|       |------|  TG 2  | TG 2 |
       *                                 |      |      |      |       |      |        |      |
       *                                 `--------------------'       `----------------------'
       */
       // QWERTY Swap Starting with Right Hand
      [QWERTYSWAPRIGHT] = LAYOUT_ergodox(
              // left hand
              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                            KC_NO, TG(QWERTY),
                                                        KC_NO,
                                TG(GAMING), TG(GAMING), KC_NO,
              // right hand
              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
              KC_NO, KC_TRNS,
              KC_NO,
              KC_NO, TG(GAMING), TG(GAMING)
          ),
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
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
