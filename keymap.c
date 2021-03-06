#include QMK_KEYBOARD_H

/* 

Create keyboard profile:
mkdir ~/qmk_firmware/keyboards/planck/keymaps/mine

Move config into profile:
move keymap.c into /mine

Compile:
qmk compile -kb planck/rev6 -km mine

Copy .bin file somewhere to flash:
cp ~/qmk_firmware/planck_rev6_mine.bin /mnt/c/qmk

On edit, re-copy to profile and repeat compilation:
cp /mnt/c/qmk/keymap.c ~/qmk_firmware/keyboards/planck/keymaps/mine

*/

enum custom_keycodes
{
    ARROW = SAFE_RANGE,
    UNDO,
    COPY,
    CUT,
    PASTE,
    REDO
};

/* 
Custom macros

Case statements follow: if case then press_action else release_action
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case ARROW:
        if (record->event.pressed)
            SEND_STRING("=>");
        break;
    case UNDO:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("z"));
        break;
    case CUT:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("x"));
        break;
    case PASTE:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("v"));
        break;
    case COPY:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("c"));
        break;
    case REDO:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("y"));
        break;
    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x12(
        /* 
        tab     q       w       e       r       t       y       u       i       o       p       bksp
        gui     a       s       d       f       g       h       j       k       l       ;       "'
        lsft    z       x       c       v       b       n       m       ,<      .>      /?      del
        lctl    esc     `~      lalt    spc     mod     mod     ent     =+      -_      \|      _
        */
        // r1
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        // r2
        KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        // r3
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_DEL,
        // r4
        KC_LCTL, KC_ESC, KC_GRV, KC_LALT, KC_SPC, MO(2), MO(1), KC_ENT, KC_EQL, KC_MINS, KC_BSLS, KC_UNDS),
    [1] = LAYOUT_ortho_4x12(
        /* 
        tab     mute    vol-    vol+    prev    next    =>      (       )       [{      }]      bksp
        gui     f1      f2      f3      f4      f5      pgup    left    up      down    right   menu
        lsft    f6      f7      f8      f9      f10     pgdown  home    <       >       end     del
        lctl    f11     f12     lalt    spc     lsft    mod     nil     nil     nil     nil     nil
        */
        // r1
        KC_TAB, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, ARROW, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_BSPC,
        // r2
        KC_LGUI, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_PGUP, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_APP,
        // r3
        KC_LSFT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_PGDN, KC_HOME, KC_LT, KC_GT, KC_END, KC_DEL,
        // r4
        KC_LCTL, KC_F11, KC_F12, KC_LALT, KC_SPC, KC_LSFT, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_CAPS),
    [2] = LAYOUT_ortho_4x12(
        /* 
        tab     !       @       #       $       ~       nil     7       8       9       *       bksp
        gui     %       ^       &       *       `       .>      4       5       6       +       nil
        lsft    undo    cut     copy    paste   redo    ,<      1       2       3       -       del
        lctl    nil     nil     lalt    nil     mod     nil     0       =       nil     nil     nil
        */
        // r1
        KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_TILD, KC_NO, KC_7, KC_8, KC_9, KC_PAST, KC_BSPC,
        // r2
        KC_LGUI, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV, KC_DOT, KC_4, KC_5, KC_6, KC_PPLS, KC_NO,
        // r3
        KC_LSFT, UNDO, CUT, COPY, PASTE, REDO, KC_COMM, KC_1, KC_2, KC_3, KC_PMNS, KC_DEL,
        // r4
        KC_LCTL, KC_NO, KC_NO, KC_LALT, KC_NO, KC_TRNS, KC_NO, KC_0, KC_PEQL, KC_NO, KC_NO, KC_NO)};