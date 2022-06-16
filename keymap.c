/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H
/* #include "sendstring_jis.h" */

#define _BASE 0
#define _MAC_ 1
#define _HHKB 2
#define _UTIL 3

//#undef JP_UNDS
//#define JP_UNDS S(JP_0) // _
// それぞれの基本レイヤーの上にFnの設定レイヤーが必要？

/*
 --- 覚書 --------------------------------------------------------------
  # qmk compile -kb hhkb/ansi -km qtea
  # qmk flash -kb hhkb/ansi -km qteaqmk flash -kb hhkb/ansi -km qtea

  KC_TRNS ... 透過 下位のレイヤーのキーになる

 ・レイヤー切替
   DF(layer) ... 指定されたレイヤーを基本レイヤーにする
   MO(layer) ... キーを押したら一時的にlayerにきりかえる 相手にKC_TRNSが必要
   OSL(layer) .. 次のキーが押されるまでlayerにきりかえる ワンショットキー
   LM(layer, mod) ... mod がアクティブな状態で一時的にレイヤーをアクティブ ex LM(LAYER_1, MOD_LALT)
   LT(layer, kc)
   TG(layer) ... layer のオン・オフを切り替え
   TO(layer) ... layer をオンにしてデフォルトレイヤーを除くレイヤーをオフ
   TT(layer) ... 複数回タップしない限りMOのように動作し、複数回タップされるとlayerをオンにトグルする

 ・モッドタイプ(mod) モッドタップキー MT(mod, kc) 押したままの時にモディファイアのように機能 離したら元のキー
   MOD_LCTL ... 左ctrl
   MOD_RCTL ... 右ctrl
   MOD_LALT ... 左alt
   MOD_RALT ... 右alt
   MOD_LGUI ... 左GUI (Windows/Command/Meta キー)
   MOD_RGUI ... 右GUI (Windows/Command/Meta キー)
   MOD_LSFT ... 左shift
   MOD_RCSFT ... 右shift
   MOD_HYPR ... HYPER (左 Control、左 Shift、左 Alt、左 GUI)
   MOD_MEH  ... Meh  (左 Control、左 Shift、左 Alt)
   ※OR することが可能 ex MT(MOD_LCL | MOD_LSFT, KC_ESC)
   モッドタップショートカット LCTL_T(kc), RSFT_T(kc)など
   LSG_T, SHIFT + GUI, S...Shift, G...GUI, C...CTL, A...ALT,,,C_S_T...CTL+Shift MOD_RSFT...右シフト
   kc は基本的なキーコードセットに制限
   LCTL(LALT(KC_DEL)) または C(A(KC_DEL)) は1回のキー押下で Control+Alt+Delete を送信するキー
 -----------------------------------------------------------------------
*/

/*
   -- キーマップ
   - ESC は全角/半角キー(grave ではうまくいかないので、変換キーを割り当てる)として振る舞う
   - Fn-ESC がESCとして振る舞う
   - Fn-TAB のCapsは無効にしたい(Fn-Alt-TABなどでCapsにしたい)
   - home/end をFn-LGUI,Fn-RGUIの場所に.Fn-a Fn-e のが使いやすいかも
   - Fn-SPACE は押しやすいのでなにか設定したいかも
   - 右GUI -> 無変換
   - 右ALT -> 普段全然使ってないから何か割り振りたい RALT->Fn-CTRL-ALTとかできないかな -> LAlt+LCtlにした
   - 2つ以上の同時押しのやりかたは？レイヤーをかぶせる？現状ではPowerキー利用しか思いつかん
   - HOME END はRUP RDWNと交換した

※日本語、英語はOS側の設定で挙動が変わる。
こちらのマクロでなにかするのは、Shift-0 を _ アンダーバーとして送信すること


   -- 変更履歴
   - 2020-06-16 右Superを Menu から Muhenkan に変更
   -            Fn-Spc を Muhenkan から Menu に変更
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* _BASE Level: Default Layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | 変換  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LAlt | LGUI | ******* Space ******* | MHen | ALL  |
            |------+------+-----------------------+------+------|
    */

    [_BASE] = LAYOUT( //  default layer
        KC_HENK, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(_HHKB),
        KC_LALT, KC_LGUI, /*        */ KC_SPC, KC_MHEN, ALL_T(KC_TRNS)),

    // -----------------------------------------------------------------------------------------------
    //
    //
    /* Layer _MAC_: Mac layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | 変換  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LAlt | LGUI | ******* Space ******* | Menu | LCA  |
            | opt  | cmd  | ******* Space ******* | cmd  | opt  |
            |------+------+-----------------------+------+------|

     control option command eisu space kana command option //voupA vodnS muteD ejetF

    */
    
    [_MAC_] = LAYOUT( // Mac layer
        KC_HENK, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(_HHKB),
        KC_LALT, KC_LGUI, /*        */ KC_SPC, KC_APP, LCA_T(KC_TRNS)),

    // -----------------------------------------------------------------------------------------------
    //
    //  - Home/End
    //
    //
    /* Layer _HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Esc  | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | _UTIL|     |     | End |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | Hom |     |     |    |    | *  | /  | PgU | Hom | Lef | Rig | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | +  | -  | PgU | End | Dow |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | Menu              | **** | **** |
                 |------+------+----------------------+------+------+

     */
    // KC_HOME, KC_PGUP KC_END, KC_PGDN
    [_HHKB] = LAYOUT( // Fn Layout
        KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        OSL(_UTIL), KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_TRNS, KC_BSPC,
        KC_TRNS, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_PGUP, KC_HOME, KC_LEFT, KC_RGHT, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_PGDN, KC_END, KC_DOWN, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_APP, KC_TRNS, LCA_T(KC_TRNS)),
    
    // -----------------------------------------------------------------------------------------------
    //
    //
    /* Layer _UTIL: util layer
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | Base| Mac | JAP |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps |     |     |     |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 |      |      |                      |      |      |
                 |------+------+----------------------+------+------+

     */

    [_UTIL] = LAYOUT( // util layer
        KC_TRNS, DF(_BASE), DF(_MAC_), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

    // -----------------------------------------------------------------------------------------------
    //
    //
    /* Layer _EMPT: Empty layer
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 |      |      |                      |      |      |
                 |------+------+----------------------+------+------+

     */
    /*
    [_EMPT] = LAYOUT( // empty layer
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
    */

};
