// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).

#include QMK_KEYBOARD_H
#include "version.h"

#include "debug.h"
#include "action_layer.h"

#define _QWR 0
#define _DVR 1
#define _SYM 2
#define _NAV 3

// how to build: make ergodox_ez:default-osx-zhs

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
//  see xyverz!!!, townk_osx

// quantum/keymap.h
// townk_osx/keymap.c
// norwegian_programmer_osx_pc_colemak/keymap.c
// default_osx/keymap.c

/// !!!*** WARNING: only C_LAlt, C_LGui used in layout, add all `custom_keycodes` to _QWR and _DVR layouts ***!!!
enum custom_keycodes {
    CUSTOM_KEYCODE_MIN = SAFE_RANGE,
    C_LCtrl,
    // C_RCtrl,
    C_LGui,
    // C_RGui,
    C_LAlt,
    // C_RAlt,
    CUSTOM_KEYCODE_MAX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer: QWERTY
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | Esc    |   1  |   2  |   3  |   4  |   5  | _QWR |           | _DVR |   6  |   7  |   8  |   9  |   0  |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Tab    |   Q  |   W  |   E  |   R  |   T  |   -  |           |  [   |   Y  |   U  |   I  |   O  |   P  |   '"   |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   \    |
   * |--------+------+------+------+------+------|   =  |           |   ]  |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *  | ~_SYM|C_LCtrl|C_LAlt|C_LGui| ~_NAV|                                       | ~_NAV|C_LGui|C_LAlt|C_LCtrl| ~_SYM|
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      | Home |       |  App |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      | End  |       | PgUp |      |      |
   *                                 | Space|Backsp|------|       |------|  Del |Enter |
   *                                 |      |ace   | ` ~  |       | PgDn |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [_QWR] = LAYOUT_ergodox(
          // left hand
          KC_ESC,          KC_1,         KC_2,        KC_3,        KC_4,     KC_5,   TO(_QWR),
          KC_TAB,          KC_Q,         KC_W,        KC_E,        KC_R,     KC_T,   KC_MINS,
          KC_LSFT,         KC_A,         KC_S,        KC_D,        KC_F,     KC_G,
          KC_LSFT,         CTL_T(KC_Z),  ALT_T(KC_X), GUI_T(KC_C), KC_V,     KC_B,   KC_EQL,
          MO(_SYM),        C_LCtrl,      C_LAlt,      C_LGui,      MO(_NAV),
          // MO(_SYM),        KC_LCTL,      KC_LALT,      KC_LGUI,      MO(_NAV),
                                                                             XXXXXXX, KC_HOME,
                                                                                      KC_END,
                                                                     KC_SPC, KC_BSPC, KC_GRV,
          // right hand
               TO(_DVR),    KC_6,   KC_7,     KC_8,           KC_9,          KC_0,            XXXXXXX,
               KC_LBRC,     KC_Y,   KC_U,     KC_I,           KC_O,          KC_P,            KC_QUOT,
                            KC_H,   KC_J,     KC_K,           KC_L,          KC_SCLN,         KC_BSLS,
               KC_RBRC,     KC_N,   KC_M,     GUI_T(KC_COMM), ALT_T(KC_DOT), CTL_T(KC_SLSH),  KC_RSFT,
                                    MO(_NAV), C_LGui,         C_LAlt,        C_LCtrl,         MO(_SYM),
                                    // MO(_NAV), KC_RGUI,        KC_RALT,      KC_RCTL,          MO(_SYM),
               KC_APP,  XXXXXXX,
               KC_PGUP,
               KC_PGDN, KC_DELT, KC_ENT
      ),

/* Layer: Dvorak
 * ,--------------------------------------------------. ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      | |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------| |------+------+------+------+------+------+--------|
 * | Tab    |   /  |   ,  |   .  |   P  |   Y  |      | |      |   F  |   G  |   C  |   R  |   L  |        |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * | LShift |   A  |   O  |   E  |   U  |   I  |------| |------|   D  |   H  |   T  |   N  |   S  |        |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |      | |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------' `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |      |      |      |
 *   `----------------------------------'                             `----------------------------------'
 *                                      ,-------------. ,-------------.
 *                                      |      |      | |      |      |
 *                               ,------|------|------| |------+------+------.
 *                               |      |      |      | |      |      |      |
 *                               |      |      |------| |------|      |      |
 *                               |      |      |      | |      |      |      |
 *                               `--------------------' `--------------------'
 *
 */
[_DVR] = LAYOUT_ergodox(
        // left hand
        _______, KC_1,           KC_2,    KC_3,    KC_4,    KC_5,    TO(_QWR),
        KC_TAB,  KC_SLSH,        KC_COMM, KC_DOT,  KC_P,    KC_Y,    XXXXXXX,
        KC_LSFT, KC_A,           KC_O,    KC_E,    KC_U,    KC_I,
        KC_LSFT, KC_SCLN,        KC_Q,    KC_J,    KC_K,    KC_X,    XXXXXXX,
        // _______, C_LCtrl,      C_LAlt,      C_LGui, _______,
        _______, _______, _______, _______, _______,
                                                            _______, _______,
                                                                     _______,
                                                   _______, _______, _______,
        // right hand
        TO(_DVR),KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        XXXXXXX, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    _______,
                 KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    _______,
        XXXXXXX, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                          // _______, C_RGui,  C_RAlt,  C_RCtrl,  _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
  ),

/* Layer: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   ^  |   {  |   }  |   $  |   ~  |           |   `  |   /  |   7  |   8  |   9  |   -  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   @  |   (  |   )  |   -  |------|           |------|   *  |   4  |   5  |   6  |   +  |    =   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   "  |   [  |   ]  |   _  |   '  |           |      |   0  |   1  |   2  |   3  |   .  |        |
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
[_SYM] = LAYOUT_ergodox(
                // left hand
                XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    XXXXXXX,
                XXXXXXX,  KC_EXLM,  KC_CIRC,  KC_LCBR,  KC_RCBR,  KC_DLR,   KC_TILD,
                XXXXXXX,  KC_PERC,  KC_AT,    KC_LPRN,  KC_RPRN,  KC_MINS,
                _______,  KC_HASH,  KC_DQT,   KC_LBRC,  KC_RBRC,  KC_UNDS,  KC_QUOT,
                _______,  _______,  _______,  _______,  _______,
                                                                  _______,  _______,
                                                                            _______,
                                                        _______,  _______,  _______,
                // right hand
                XXXXXXX,  KC_F6,    KC_F7,    KC_F8,   KC_F9,     KC_F10,   KC_F11,
                KC_GRV,   KC_SLSH,  KC_7,     KC_8,    KC_9,      KC_MINS,  KC_F12,
                          KC_ASTR,  KC_4,     KC_5,    KC_6,      KC_PLUS,  KC_EQL,
                XXXXXXX,  KC_0,     KC_1,     KC_2,    KC_3,      KC_DOT,   _______,
                                    _______,  _______, _______,   _______,  _______,
                _______,  _______,
                _______,
                _______,  _______,  _______
      ),

/* Layer: Navigate, Media and Mouse
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
[_NAV] = LAYOUT_ergodox(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,
       _______, KC_BTN1, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY,
       XXXXXXX,  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_ACL2, KC_VOLU,
                 XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_ACL1, KC_VOLD,
       XXXXXXX,  XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R, KC_ACL0, _______,
                          _______, KC_WH_D, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
)

};

static int DVR_to_QWR__MODS_flags = 0;
enum DVR_to_QWR__MOD
{
    DVR_to_QWR__MOD__LCtrl  = (1 << 0),
    //DVR_to_QWR__MOD__RCtrl  = (1 << 1),
    DVR_to_QWR__MOD__LGui   = (1 << 2),
    // DVR_to_QWR__MOD__RGui   = (1 << 3),
    DVR_to_QWR__MOD__LAlt   = (1 << 4),
    // DVR_to_QWR__MOD__RAlt   = (1 << 5)
};

bool is_custom_keycode(uint16_t keycode)
{
    if (   keycode > CUSTOM_KEYCODE_MIN
        && keycode < CUSTOM_KEYCODE_MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

uint16_t get_flag_for_custom_keycode(uint16_t custom_keycode)
{
    switch (custom_keycode)
    {
        case C_LCtrl:   return DVR_to_QWR__MOD__LCtrl;
        // case C_RCtrl:   return DVR_to_QWR__MOD__RCtrl;
        case C_LGui:    return DVR_to_QWR__MOD__LGui;
        // case C_RGui:    return DVR_to_QWR__MOD__RGui;
        case C_LAlt:    return DVR_to_QWR__MOD__LAlt;
        // case C_RAlt:    return DVR_to_QWR__MOD__RAlt;
        default:        return 0;
    }
}

uint16_t get_mod_for_custom_keycode(uint16_t custom_keycode)
{
    switch (custom_keycode)
    {
        case C_LCtrl:   return MOD_LCTL;
        // case C_RCtrl:   return MOD_RCTL;
        case C_LGui:    return MOD_LGUI;
        // case C_RGui:    return MOD_RGUI;
        case C_LAlt:    return MOD_LALT;
        // case C_RAlt:    return MOD_RALT;
        default:        return 0;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (is_custom_keycode(keycode))
    {
        const uint16_t custom_keycode = keycode;

        if (IS_LAYER_ON(_DVR))
        {
            if (record->event.pressed)
            {
              // register_code(KC_LCTL);
              // unregister_code(KC_LCTL);

                uint16_t mod      = get_mod_for_custom_keycode(custom_keycode);
                uint16_t mod_flag = get_flag_for_custom_keycode(custom_keycode);

                // layer_move(_QWR);
                layer_off(_DVR);

                register_mods(mod);

                // store `flag` manualy registered `mod`
                DVR_to_QWR__MODS_flags |= mod_flag;
            }
            else
            {
                // this will be handled in _QWR layout
            }
        }
        else
        {
            if (record->event.pressed)
            {
                uint16_t mod = get_mod_for_custom_keycode(custom_keycode);
                register_mods(mod);
            }
            else
            {
                uint16_t mod = get_mod_for_custom_keycode(custom_keycode);
                unregister_mods(mod);

                // handle `register_mods` from (_DVR) layout custom key pressed
                uint16_t mod_flag = get_flag_for_custom_keycode(custom_keycode);
                if (DVR_to_QWR__MODS_flags & mod_flag)
                {
                    DVR_to_QWR__MODS_flags &= ~mod_flag;
                    if (0 == DVR_to_QWR__MODS_flags)
                    {
                      layer_on(_DVR);
                        // layer_move(_DVR);
                    }
                }
            }
        }

        return false;
    }

    return true;
}

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
        case _DVR:
            ergodox_right_led_3_on();
            break;
        case _SYM:
            ergodox_right_led_1_on();
            break;
        case _NAV:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
