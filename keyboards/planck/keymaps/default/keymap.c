// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUMBER
  };

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBER,
  LOWER,
  RAISE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |NUMBER| GUI  | ALT  |Lower | ESC	 | SPACE|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTRL,NUMBER, KC_LGUI, KC_LALT, LOWER,   KC_ESC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      | Home |  Up  | PgUp |NumLck|   7  |   8  |   9  | *    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |      |      |      | Left |      |Right |   /  |   4  |   5  |   6  |  +   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | End  | Down | PgDn |   -  |   1  |   2  |   3  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | GUI  | Alt  |      | Esc  | Space|      | 0    |  00  |  .   |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = {
  { _______, _______, _______, _______, KC_HOME, KC_UP,   KC_PGUP, ACTION_LAYER_TOGGLE(NUMBER),    KC_KP_7, KC_KP_8,    KC_KP_9,   KC_KP_ASTR},
  {  KC_TAB, _______, _______, _______, KC_LEFT, _______, KC_RGHT, KC_KP_SLSH, KC_KP_4, KC_KP_5,    KC_KP_6,   KC_KP_PLUS},
  { _______, _______, _______, _______, KC_END,  KC_DOWN, KC_PGDN, KC_KP_MINS, KC_KP_1, KC_KP_2,    KC_KP_3,   KC_KP_ENT },
  {KC_LCTRL, _______, KC_LGUI, KC_LALT, _______,   KC_ESC,  KC_SPC,  _______,      KC_KP_0, ACTION_MODS_KEY(KC_KP_0, KC_KP_0),    KC_KP_DOT, KC_KP_ENT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |PRNTSC|      |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |PAUSE |STOP  |  _   |  +   |PLAY  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |      | GUI  |  ALT |      | ESC  | SPACE|      | PREV | Vol- | Vol+ | NEXT |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, 	KC_EXLM, 	KC_AT,   	KC_HASH, KC_DLR,  KC_PERC, 	KC_CIRC,	KC_AMPR, 	KC_ASTR, 	KC_LPRN, 	KC_RPRN, 		KC_DEL},
  {KC_TAB,  	KC_F1,   	KC_F2,  	KC_F3,   KC_F4,   KC_F5,   	KC_F6,  	KC_PSCR, 	_______, 	KC_LCBR, 	KC_RCBR, 		KC_PIPE},
  {_______, 	KC_F7,   	KC_F8,   	KC_F9,   KC_F10,  KC_F11,  	KC_F12,		KC_PAUS,	KC_MSTP,	LSFT(KC_MINS), 	LSHFT(KC_EQL), 	KC_MPLY},
  {KC_LCTRL, 	_______, 	KC_LGUI, 	KC_LALT, _______, KC_ESC, 	KC_SPACE, 	_______, 	KC_MPRV, 	KC_VOLD, 	KC_VOLU, 		KC_MNXT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |      | LEFT |      |      |      |      |  UP  |      |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | LEFT | DOWN |RIGHT |      |      | LEFT | DOWN | RIGHT|   -  |  =   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  CTRL|      | GUI  | ALT  |      | ESC  | SPACE|      | HOME | PGUP | PGDN |  END |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  	KC_1,    	KC_2,    	KC_3,		KC_4,    	KC_5,    	KC_6,    	KC_7,    	KC_8,    	KC_9,    	KC_0,    	KC_BSPC},
  {KC_TAB,  	_______,   	KC_UP,   	_______,	_______,   	_______,   	_______,   	KC_UP, 		_______,  	KC_LBRC, 	KC_RBRC, 	KC_BSLS},
  {_______, 	KC_LEFT,   	KC_DOWN,   	KC_RIGHT,  	_______,  	_______,  	KC_LEFT,  	KC_DOWN, 	KC_RIGHT, 	KC_MINS, 	KC_EQL, 	KC_ENT},
  {KC_LCTRL, 	_______, 	KC_LGUI, 	KC_LALT,	_______,	KC_ESC, 	KC_SPACE, 	_______, 	KC_HOME, 	KC_PGUP, 	KC_PGDN, 	KC_END}
}	
};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case NUMBER:
      if (record->event.pressed) {
        layer_on(_NUMBER);
        update_tri_layer(_LOWER, _RAISE, _NUMBER);
      } else {
        layer_off(_NUMBER);
        update_tri_layer(_LOWER, _RAISE, _NUMBER);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NUMBER);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NUMBER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NUMBER);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NUMBER);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
