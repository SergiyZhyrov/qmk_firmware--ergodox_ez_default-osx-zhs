// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define NAVG 3 // navigate keys

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
//  see xyverz!!!, townk_osx

// quantum/keymap.h
// townk_osx/keymap.c
// norwegian_programmer_osx_pc_colemak/keymap.c
// default_osx/keymap.c

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   -  |           |  [   |   Y  |   U  |   I  |   O  |   P  |   '"   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   \    |
 * |--------+------+------+------+------+------|   =  |           |   ]  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  ~L1 | LCtrl| LAlt | LGui |  ~L2 |                                       |  ~L2 | RGui | RAlt | RCtrl|  ~L1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  ~L2 | Home |       |  App |  ~L2 |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | End  |       | PgUp |      |      |
 *                                 | Space|Backsp|------|       |------|  Del |Enter |
 *                                 |      |ace   | Grv  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,          KC_1,         KC_2,           KC_3,    KC_4,   KC_5,   KC_NO,
        KC_TAB,          KC_Q,         KC_W,           KC_E,    KC_R,   KC_T,   KC_MINS,
        KC_LSFT,         KC_A,         KC_S,           KC_D,    KC_F,   KC_G,
        KC_LSFT,         KC_Z,         KC_X,           KC_C,    KC_V,   KC_B,   KC_EQL,
        MO(SYMB),        KC_LCTL,      KC_LALT,        KC_LGUI, MO(MDIA),
                                                    MO(MDIA), KC_HOME,
                                                              KC_END,
                                             KC_SPC, KC_BSPC, KC_GRV,
        // right hand
             KC_NO,       KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_NO,
             KC_LBRC,     KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_QUOT,
                          KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_BSLS,
             KC_RBRC,     KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                  MO(MDIA), KC_RGUI, KC_RALT, KC_RCTL, MO(SYMB),
             KC_APP,  MO(MDIA),
             KC_PGUP,
             KC_PGDN, KC_DELT, KC_ENT
    ),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   "  |      |           |      |   /  |   7  |   8  |   9  |   -  |   F12  |
 * |--------+------+------+------+------+------|   `  |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   |  |------|           |------|   *  |   4  |   5  |   6  |   +  |    =   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |   '  |           |      |   0  |   1  |   2  |   3  |   .  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
                // left hand
                XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    XXXXXXX,
                XXXXXXX,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_DQT,   KC_GRV,
                XXXXXXX,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_PIPE,
                _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  KC_QUOT,
                _______,  _______,  _______,  _______,  _______,
                                                                  KC_TRNS,  KC_TRNS,
                                                                            KC_TRNS,
                                                        KC_TRNS,  KC_TRNS,  KC_TRNS,
                // right hand
                XXXXXXX,  KC_F6,    KC_F7,    KC_F8,   KC_F9,     KC_F10,   KC_F11,
                XXXXXXX,  KC_SLSH,  KC_7,     KC_8,    KC_9,      KC_MINS,  KC_F12,
                          KC_ASTR,  KC_4,     KC_5,    KC_6,      KC_PLUS,  KC_EQL,
                XXXXXXX,  KC_0,     KC_1,     KC_2,    KC_3,      KC_DOT,   _______,
                                    _______,  _______, _______,   _______,  _______,
                KC_TRNS,  KC_TRNS,
                KC_TRNS,
                KC_TRNS,  KC_TRNS,  KC_TRNS
      ),

    ///* Keymap 1: Symbol Layer
    // *
    // * ,--------------------------------------------------.           ,--------------------------------------------------.
    // * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
    // * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    // * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
    // * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    // * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
    // * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    // * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
    // * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    // *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
    // *   `----------------------------------'                                       `----------------------------------'
    // *                                        ,-------------.       ,-------------.
    // *                                        |      |      |       |      |      |
    // *                                 ,------|------|------|       |------+------+------.
    // *                                 |      |      |      |       |      |      |      |
    // *                                 |      |      |------|       |------|      |      |
    // *                                 |      |      |      |       |      |      |      |
    // *                                 `--------------------'       `--------------------'
    // */
    //// SYMBOLS
    //[SYMB] = KEYMAP(
    //                // left hand
    //                KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
    //                KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
    //                KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
    //                KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
    //                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    //                KC_TRNS,KC_TRNS,
    //                KC_TRNS,
    //                KC_TRNS,KC_TRNS,KC_TRNS,
    //                // right hand
    //                KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //                KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
    //                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
    //                KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
    //                KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
    //                KC_TRNS, KC_TRNS,
    //                KC_TRNS,
    //                KC_TRNS, KC_TRNS, KC_TRNS
    //                ),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      | Mute |  Play  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |  Up  |      |M.Acl2|  VolUp |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Rclk |MsLeft|MsDown|MsRght|      |------|           |------|      | Left | Down | Right|M.Acl1|  VolDn |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Lclk |      | Mclk |      |      |      |           |      |      | ScrL | ScrU | ScrR |M.Acl0|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      | ScrD |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,
       _______, KC_BTN1, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, _______, _______, _______, _______,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY,
       XXXXXXX,  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_ACL2, KC_VOLU,
                 XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_ACL1, KC_VOLD,
       XXXXXXX,  XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R, KC_ACL0, _______,
                          _______, KC_WH_D, _______, _______, _______,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap NAVG:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      | Lclk | Mclk | Rclk | Home | PgUp |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   U  | ScrU | End  | PgDn |M.Accel2|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   L  | ScrL |   R  | ScrR |      |M.Accel1|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Lclk | Mclk | Rclk |      |      |      |           |      | Lclk |   D  | ScrD |      |  Up  |M.Accel0|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS |      |      |      |      |                                       |      |      | Left | Down | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAVG] = KEYMAP(
                // left hand
                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                KC_TRNS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                                  XXXXXXX,  XXXXXXX,
                                                                            XXXXXXX,
                                                        XXXXXXX,  XXXXXXX,  XXXXXXX,
                // right hand
                XXXXXXX,  KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,
                XXXXXXX,  KC_7,     KC_8,     KC_9,    KC_ASTR, KC_AMPR,  KC_F12,
                          KC_4,     KC_5,     KC_6,    KC_PLUS, KC_EQL,   KC_TRNS,
                XXXXXXX,  KC_1,     KC_2,     KC_3,    KC_BSLS, KC_UP,    KC_TRNS,
                                    KC_0,     KC_DOT,  KC_LEFT, KC_DOWN,  KC_RGHT,
                XXXXXXX,  KC_TRNS,
                XXXXXXX,
                KC_TRNS,  KC_TRNS,  KC_TRNS
      )
};

const uint16_t PROGMEM fn_actions[] = {
  //[BASE] = ACTION_FUNCTION(BASE),
  //[SYMB] = ACTION_LAYER_TAP_TOGGLE(SYMB)               // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  // Tests LED function when the keyboard initializes.
  wait_ms(500);
  ergodox_board_led_on();
  wait_ms(200);
  ergodox_right_led_1_on();
  wait_ms(200);
  ergodox_right_led_2_on();
  wait_ms(200);
  ergodox_right_led_3_on();
  wait_ms(200);
  ergodox_board_led_off();
  wait_ms(200);
  ergodox_right_led_1_off();
  wait_ms(200);
  ergodox_right_led_2_off();
  wait_ms(200);
  ergodox_right_led_3_off();
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
