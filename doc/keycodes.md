
# Keyplus keycode documentation


## Simple HID keycodes

Note: keycode names are case insensitive. So `A` and `a` will both output lower
case `a`. To make upper case letters, you will need to use modkeys to type
`s-A` to get capital `A`. See below for a more thorough explanation of modkeys.

Note: The behaviour of keycodes is dependent on your computers keyboard layout
setting.

| Key Code | Long Name   | Description |
|----------|-------------|-------------|
| none     | none        | Does nothing when pressed. |
| a        |             | Sends the USB HID keycode for A |
| b        |             | Sends the USB HID keycode for B |
| c        |             | Sends the USB HID keycode for C |
| d        |             | Sends the USB HID keycode for D |
| e        |             | Sends the USB HID keycode for E |
| f        |             | Sends the USB HID keycode for F |
| g        |             | Sends the USB HID keycode for G |
| h        |             | Sends the USB HID keycode for H |
| i        |             | Sends the USB HID keycode for I |
| j        |             | Sends the USB HID keycode for J |
| k        |             | Sends the USB HID keycode for K |
| l        |             | Sends the USB HID keycode for L |
| m        |             | Sends the USB HID keycode for M |
| n        |             | Sends the USB HID keycode for N |
| o        |             | Sends the USB HID keycode for O |
| p        |             | Sends the USB HID keycode for P |
| q        |             | Sends the USB HID keycode for Q |
| r        |             | Sends the USB HID keycode for R |
| s        |             | Sends the USB HID keycode for S |
| t        |             | Sends the USB HID keycode for T |
| u        |             | Sends the USB HID keycode for U |
| v        |             | Sends the USB HID keycode for V |
| w        |             | Sends the USB HID keycode for W |
| x        |             | Sends the USB HID keycode for X |
| y        |             | Sends the USB HID keycode for Y |
| z        |             | Sends the USB HID keycode for Z |
| 1        |             | Sends the USB HID keycode for 1 |
| 2        |             | Sends the USB HID keycode for 2 |
| 3        |             | Sends the USB HID keycode for 3 |
| 4        |             | Sends the USB HID keycode for 4 |
| 5        |             | Sends the USB HID keycode for 5 |
| 6        |             | Sends the USB HID keycode for 6 |
| 7        |             | Sends the USB HID keycode for 7 |
| 8        |             | Sends the USB HID keycode for 8 |
| 9        |             | Sends the USB HID keycode for 9 |
| 0        |             | Sends the USB HID keycode for 0 |
| `ent`        | enter         |                            |
| `esc`        | escape        |                            |
| `bspc`       | backspace     |                            |
| `tab`        | tab           |                            |
| `spc`        | space         |                            |
| `min` / `-`  | minus         |                            |
| `equ` / `=`  | equal         |                            |
| `lbrc` / `[` | left_bracket  |                            |
| `rbrc` / `]` | right_bracket |                            |
| `bsls` / `\` | back_slash    |                            |
| `iso#`       | iso_hash      |                            |
| iso\\        | iso_back_slash |                         |
| scln         | semicolon   |                            |
| quot         | quote       |                            |
| grv          | grave       |                            |
| comm         | comma       |                            |
| dot          | period      |                            |
| fsls         | forward_slash |                          |
| caps         | caps_lock   |                            |
| f1           |             |                            |
| f2           |             |                            |
| f3           |             |                            |
| f4           |             |                            |
| f5           |             |                            |
| f6           |             |                            |
| f7           |             |                            |
| f8           |             |                            |
| f9           |             |                            |
| f10          |             |                            |
| f11          |             |                            |
| f12          |             |                            |
| pscr         | print_screen|                            |
| slck         | scroll_lock |                            |
| paus         | pause       |                            |
| ins          | insert      |                            |
| home         | home        |                            |
| pgup         | page_up     |                            |
| del          | delete      |                            |
| end          | end         |                            |
| pgdn         | page_down   |                            |
| rght         | right       |                            |
| left         | left        |                            |
| down         | down        |                            |
| up           | up          |                            |
| nlck         | num_lock    |                            |
| kp_/         | kp_forward_slash | Keypad forward slash / divide symbol |
| kp_*         | kp_asterisk | Keypad asterisk / star / multiple symbol |
| kp_-         | kp_minus    | Keypad hyphen / minus symbol |
| kp_+         | kp_plus     | Keypad plus / addition symbol |
| kp_ent       | kp_enter    | Keypad enter / return      |
| kp_1         | kp_1       |                            |
| kp_2         | kp_2       |                            |
| kp_3         | kp_3       |                            |
| kp_4         | kp_4       |                            |
| kp_5         | kp_5       |                            |
| kp_6         | kp_6       |                            |
| kp_7         | kp_7       |                            |
| kp_8         | kp_8       |                            |
| kp_9         | kp_9       |                            |
| kp_0         | kp_0       |                            |
| kp_.         | kp_.       |                            |
| application          |             |                            |
| power        |             |                            |
| kp_=         |             |                            |
| f13          |             |                            |
| f14          |             |                            |
| f15          |             |                            |
| f16          |             |                            |
| f17          |             |                            |
| f18          |             |                            |
| f19          |             |                            |
| f20          |             |                            |
| f21          |             |                            |
| f22          |             |                            |
| f23          |             |                            |
| f24          |             |                            |
| execute          |             |                            |
| help         |             |                            |
| hid_menu         |             |                            |
| select           |             |                            |
| stop         |             |                            |
| again        |             |                            |
| undo         |             |                            |
| cut          |             |                            |
| copy         |             |                            |
| paste        |             |                            |
| find         |             |                            |
| mute         |             |                            |
| volume_up        |             |                            |
| volume_down          |             |                            |
| locking_caps_lock        |             |                            |
| locking_num_lock         |             |                            |
| locking_scroll_lock          |             |                            |
| kp_,         |             |                            |
| kp_equal_as400           |             |                            |
| international_1          |             |                            |
| international_2          |             |                            |
| international_3          |             |                            |
| international_4          |             |                            |
| international_5          |             |                            |
| international_6          |             |                            |
| international_7          |             |                            |
| international_8          |             |                            |
| international_9          |             |                            |
| lang_1           |             |                            |
| lang_2           |             |                            |
| lang_3           |             |                            |
| lang_4           |             |                            |
| lang_5           |             |                            |
| lang_6           |             |                            |
| lang_7           |             |                            |
| lang_8           |             |                            |
| lang_9           |             |                            |
| alternate_erase          |             |                            |
| sys_req          |             |                            |
| cancel           |             |                            |
| clear        |             |                            |
| prior        |             |                            |
| return           |             |                            |
| separator        |             |                            |
| out          |             |                            |
| oper         |             |                            |
| clear_again          |             |                            |
| crsel        |             |                            |
| exsel        |             |                            |
| kp_00        |             |                            |
| kp_000           |             |                            |
| thousands_separator          |             |                            |
| decimal_separator        |             |                            |
| currency_unit        |             |                            |
| currency_sub_unit        |             |                            |
| kp_(         |             |                            |
| kp_)         |             |                            |
| kp_[         |             |                            |
| kp_]         |             |                            |
| kp_tab           |             |                            |
| kp_bspc          |             |                            |
| kp_a         |             |                            |
| kp_b         |             |                            |
| kp_c         |             |                            |
| kp_d         |             |                            |
| kp_e         |             |                            |
| kp_f         |             |                            |
| kp_xor           |             |                            |
| kp_^         |             |                            |
| kp_%         |             |                            |
| kp_<         |             |                            |
| kp_>         |             |                            |
| kp_&         |             |                            |
| kp_&&        |             |                            |
| kp_|         |             |                            |
| kp_||        |             |                            |
| kp_:         |             |                            |
| kp_#         |             |                            |
| kp_spc           |             |                            |
| kp_@         |             |                            |
| kp_!         |             |                            |
| kp_memory_store          |             |                            |
| kp_memory_recall         |             |                            |
| kp_memory_clear          |             |                            |
| kp_memory_add        |             |                            |
| kp_memory_subtract           |             |                            |
| kp_memory_multiply           |             |                            |
| kp_memory_divide         |             |                            |
| kp_plus_minus        |             |                            |
| kp_clear         |             |                            |
| kp_clear_entry           |             |                            |
| kp_binary        |             |                            |
| kp_octal         |             |                            |
| kp_decimal           |             |                            |
| kp_hexadecimal           |             |                            |
| lctl         | left_control|                            |
| lsft         | left_shift  |                            |
| lalt         | left_alt    |                            |
| lgui         | left_gui    |                            |
| rctl         | right_control|                           |
| rsft         | right_shift |                            |
| ralt         | right_alt   |                            |
| rgui         | right_gui   |                            |
| !        | s-1         |                            |
| @        | s-2         |                            |
| #        | s-3         |                            |
| $        | s-4         |                            |
| %        | s-5         |                            |
| ^        | s-6         |                            |
| &        | s-7         |                            |
| *        | s-8         |                            |
| (        | s-9         |                            |
| )        | s-0         |                            |
| _        | s--         |                            |
| +        | s-=         |                            |
| \|       | s-\         |                            |
| {        | s-[         |                            |
| }        | s-]         |                            |
| :        | s-;         |                            |
| "        | s-'         |                            |
| <        | s-,         |                            |
| >        | s-.         |                            |
| ?        | s-/         |                            |
| ~        | s-`         |                            |
| iso~         |             |                            |
| iso|         |             |                            |
| trns        | transparent | Checks for an active layer below the current layer, and uses the key in the same position on that layer. Uses the closest layer below the current one that is currently active. |
| ms_u      | mouse_up      |           |
| ms_d      | mouse_down    |           |
| ms_l      | mouse_left    |           |
| ms_r      | mouse_right   |           |
| wh_u      | mouse_wh_up       |           |
| wh_d      | mouse_wh_down     |           |
| wh_l      | mouse_wh_left     |           |
| wh_r      | mouse_wh_right    |           |
| btn1      |   mouse_btn1 |            |
| btn2      |   mouse_btn2 |            |
| btn3      |   mouse_btn3 |            |
| btn4      |   mouse_btn4 |            |
| btn5      |   mouse_btn5 |            |
| btn6      |   mouse_btn6 |            |
| btn7      |   mouse_btn7 |            |
| btn8      |   mouse_btn8 |            |
|           | system_power |            |
|           | system_sleep |            |
|           | system_wake  |            |
| mute | audio_mute          |  |
| volu | audio_vol_up        |  |
| vold | audio_vol_down      |  |
| mnxt | media_next_track    |  |
| mprv | media_prev_track    |  |
| mffd | media_fast_forward  |  |
| mrwd | media_rewind        |  |
| mstp | media_stop          |  |
| mply | media_play_pause    |  |
| mjct | media_eject         |  |
| msel | media_select        |  |
|      | "mail"          | |
| calc | "calculator"    | |
| comp | "my_computer"   | |
|      | "www_search"    | |
|      | "www_home"      | |
|      | "www_back"      | |
|      | "www_forward"   | |
|      | "www_stop"      | |
|      | "www_refresh"   | |
|      | "www_favorites" | |
|      | dongle_0 | Used for switching between different wireless receivers (NOTE: currently disabled in firmware, so can't be used yet) |
|      | dongle_1 |  |
|      | dongle_2 |  |
|      | dongle_3 |  |
|      | dongle_4 |  |
|      | dongle_5 |  |
|      | dongle_6 |  |
|      | dongle_7 |  |
| boot | bootloader | make the keyboard enter its bootloader |
| boot2| bootloader_2 | for devices that have more than one bootloader, make the keyboard enter its second bootloader |
| rst   | reset | Reset the keyboard firmware. |
| kro_6 |       | Turn on 6 key roll over.     |
| kro_n |       | Turn on n key roll over.     |
| kro_auto |    | Turn on auto key roll over. Uses 6KRO by default, and automatically enables NKRO if more than 6 keys are pressed |
| pair |        | Enter pairing mode.  Can currently be used to pair a unifying mouse. |
| L0  | | activates layer 0 when held down |
| L1  | | activates layer 1 when held down |
| L2  | | activates layer 2 when held down |
| L3  | | activates layer 3 when held down |
| L4  | | activates layer 4 when held down |
| L5  | | activates layer 5 when held down |
| L6  | | activates layer 6 when held down |
| L7  | | activates layer 7 when held down |
| L8  | | activates layer 8 when held down |
| L9  | | activates layer 9 when held down |
| L10 | | activates layer 10 when held down |
| L11 | | activates layer 11 when held down |
| L12 | | activates layer 12 when held down |
| L13 | | activates layer 13 when held down |
| L14 | | activates layer 14 when held down |
| L15 | | activates layer 15 when held down |
| set_L0  | | Makes layer 0 the active layer. |
| set_L1  | | Makes layer 1 the active layer. |
| set_L2  | | Makes layer 2 the active layer. |
| set_L3  | | Makes layer 3 the active layer. |
| set_L4  | | Makes layer 4 the active layer. |
| set_L5  | | Makes layer 5 the active layer. |
| set_L6  | | Makes layer 6 the active layer. |
| set_L7  | | Makes layer 7 the active layer. |
| set_L8  | | Makes layer 8 the active layer. |
| set_L9  | | Makes layer 9 the active layer. |
| set_L10 | | Makes layer 10 the active layer. |
| set_L11 | | Makes layer 11 the active layer. |
| set_L12 | | Makes layer 12 the active layer. |
| set_L13 | | Makes layer 13 the active layer. |
| set_L14 | | Makes layer 14 the active layer. |
| set_L15 | | Makes layer 15 the active layer. |
| tog_L0  | toggle_L0  | Turns layer 0 on when pressed. Turns off when pressed again. |
| tog_L1  | toggle_L1  | Turns layer 1 on when pressed. Turns off when pressed again. |
| tog_L2  | toggle_L2  | Turns layer 2 on when pressed. Turns off when pressed again. |
| tog_L3  | toggle_L3  | Turns layer 3 on when pressed. Turns off when pressed again. |
| tog_L4  | toggle_L4  | Turns layer 4 on when pressed. Turns off when pressed again. |
| tog_L5  | toggle_L5  | Turns layer 5 on when pressed. Turns off when pressed again. |
| tog_L6  | toggle_L6  | Turns layer 6 on when pressed. Turns off when pressed again. |
| tog_L7  | toggle_L7  | Turns layer 7 on when pressed. Turns off when pressed again. |
| tog_L8  | toggle_L8  | Turns layer 8 on when pressed. Turns off when pressed again. |
| tog_L9  | toggle_L9  | Turns layer 9 on when pressed. Turns off when pressed again. |
| tog_L10 | toggle_L10 | Turns layer 10 on when pressed. Turns off when pressed again. |
| tog_L11 | toggle_L11 | Turns layer 11 on when pressed. Turns off when pressed again. |
| tog_L12 | toggle_L12 | Turns layer 12 on when pressed. Turns off when pressed again. |
| tog_L13 | toggle_L13 | Turns layer 13 on when pressed. Turns off when pressed again. |
| tog_L14 | toggle_L14 | Turns layer 14 on when pressed. Turns off when pressed again. |
| tog_L15 | toggle_L15 | Turns layer 15 on when pressed. Turns off when pressed again. |
|     | sticky_L0  | Sticky layer 0 key. |
|     | sticky_L1  | Sticky layer 1 key. |
|     | sticky_L2  | Sticky layer 2 key. |
|     | sticky_L3  | Sticky layer 3 key. |
|     | sticky_L4  | Sticky layer 4 key. |
|     | sticky_L5  | Sticky layer 5 key. |
|     | sticky_L6  | Sticky layer 6 key. |
|     | sticky_L7  | Sticky layer 7 key. |
|     | sticky_L8  | Sticky layer 8 key. |
|     | sticky_L9  | Sticky layer 9 key. |
|     | sticky_L10 | Sticky layer 10 key. |
|     | sticky_L11 | Sticky layer 11 key. |
|     | sticky_L12 | Sticky layer 12 key. |
|     | sticky_L13 | Sticky layer 13 key. |
|     | sticky_L14 | Sticky layer 14 key. |
|     | sticky_L15 | Sticky layer 15 key. |
|     | sticky_lctrl  | Sticky left control                |
|     | sticky_lshift | Sticky left shift                  |
|     | sticky_lalt   | Sticky left alt                    |
|     | sticky_lgui   | Sticky left gui / win key / meta   |
|     | sticky_rctrl  | Sticky right control               |
|     | sticky_rshift | Sticky right shift                 |
|     | sticky_ralt   | Sticky right alt                   |
|     | sticky_rgui   | Sticky right gui / win key / meta  |
|     | layer_reset   | Reset all layer state. Clears sticky keys, as well as returning to the default layer. (TODO: not implemented)     |

## Modkeys keycodes with modifiers

Modkeys allow you to press a key and a modifier at the same time. The format
for entering a modkey is `<mod>-<keycode>`. So to make a key that press
`ctrl+v`, use `c-v`.  To make a key that press `ctrl+shift+alt+up` use
`csa-up`.

The available modifiers are

* `c` -> control
* `s` -> shift
* `a` -> alt keycode
* `g` -> gui / win key / meta

By default the modifier keys will use the left hand modifier, if instead want
to use the right hand modifier, prefix the sequence with `r`. Note: at this
time it is currently not possible to use both the right and left modifiers
in a single modkey.


### Modkey behaviour when pressing other keys

Some of the keycodes are implemented as modkeys like `)` which is implemented
as `s-0`.  However, modkeys are implemented in such a way that this should
not interfere when other keys are pressed, automatically removing the modifiers
if necessary.

For example, suppose you have 3 keys on one layer with keycodes `(`, `0` and `)`
implemented as the mod keys `s-9`, `0` and `s-0`.  If you type the sequence
`(0)` without releasing any of the keys it should still output `(0)` instead
of `())` as when `0` is pressed it will automatically unpress the shift key
used to generate the `(` key press.

An exception to this rule are pure modifier keys (i.e. ordinary shift, ctrl,
etc). Pure modifiers will not be removed when using modkeys. So if you held
down `shift` while typing `(0)`, then each key will be shifted regardless and
output `())`. With this behaviour, it is also possible to make a
modkey that presses multiple modifiers at once like `ca-none` (`ctrl+alt+none`)
that gets applied to other key presses.


## Advanced keycodes

Some advanced keycodes needed to be defined external before they can be used
in your layout. To do this you need to defined in the `keycodes` section of
the layout file. The `keycodes` is a top level section of the yaml file, with
each of it's members defining a new keycode for use in layout.

Here's a small example that defines a new keycode `SFTEnt`:

```yaml
keycodes:
  SFTEnt: # our name for the new keycode
    keycode: hold   # what type of keycode to define
    # The rest of the fields are options for controlling the beahviour of the keycode
    tap_key: enter
    hold_key: sticky_lshift
```

After defining a keycode, it can be used freely in any layout.

### Tap/Hold keycodes

TODO

```yaml
keycodes:
  space_fn:
    keycode: hold
    tap_key: space
    hold_key: sticky_l2

    # activate_type: other_key # activate hold_key when other key is pressed
    # delay: 200
```

### Mouse Gesture keycodes

NOTE: A Logitech Unifying mouse must be paired with the keyplus
keyboard/receiver for mouse gestures to work.

Mouse gestures allow you to activate one of several keys depending on how
you move the mouse. Below is an example showing all the features of mouse
gestures.

```yaml
keycodes:
  gesture:
    keycode: mouse_gesture

    left: media_prev_track   # press gesture key and move mouse left
    right: media_next_track  # press gesture key and move mouse right
    up: audio_vol_up         # press gesture key and move mouse up
    down: audio_vol_down     # press gesture key and move mouse down

    up_left: page_up         # press gesture key and move mouse up and left
    up_right: a-tab          # press gesture key and move mouse up and right
    down_left: page_down     # press gesture key and move mouse down and left
    down_right: as-tab       # press gesture key and move mouse down and right

    tap: t # TODO, functionallity not fully implemented yet

    # These 3 values control the how far the mouse must move to activate a gesture
    # Setting a threshold value to 0 will disable gestures in that direction.
    threshold: 120     # horizontal/vertical gestures
    threshold_diag: 70 # diagonal gestures
    threshold_tap: 30  # tap gestures
```

See also: [Remmaping mouse buttons.](../doc/layout_format.md#remapping-mouse-buttons)

### Macro keycodes

Macros provide the ability to execute a series of keycodes and macro commands
with a single key press. Several examples are provided below demonstrating the
various features of macros.

#### Basic macro

This simple macro presses a sequence of keycodes in order. The
`commands` field is run when the macro key is pressed and the
`commands_release` field is run when the macro key is released.
Both the `commands` and `commands_release` field are optional, so it is
possible to omit one of them to have  macros that only execute on press or
release of the macro key.

```yaml
keycodes:
  macro1:
    keycode: macro
    commands: # run when key is pressed (optional)
      - a
      - b
      - c
    commands_release: # run when key is released (optional)
      - d
      - e
      - f
```

All keyplus keycodes should work as normal when used inside macros except for
other macro keycodes.


#### Macro press rate

The rate at which macro keys are pressed can be configured with the
`set_rate(r)` macro command where `r` is the number of milliseconds between
key presses. The rate will stay the same until the next `set_rate` instruction.
For example to press a key every 100ms, use:

```yaml
keycodes:
  macro1:
    keycode: macro
    commands:
      - set_rate(1000)
      - a
      - b
      - c
```

By default macro key presses will be released shortly after they are pressed,
however, it is possible to configure how long they are held for with
`set_clear_rate(r)`. For example to hold the keys for 800ms use:

```yaml
keycodes:
  macro1:
    keycode: macro
    # This macro should output: abc111112222233333
    # (the number of 1/2/3 depends on your OS key repeat rate setting).
    commands:
      - set_rate(1000)      # 1s between key presses #
      - a
      - b
      - c
      - set_clear_rate(800) # Keys are held for 0.8s before being released
      - 1                   # should print `1` multiple times since its held
      - 2                   # effect last until next `set_clear_rate()` is found
      - 3
```

NOTE: Some programs may have issues when handling rapid button press sequences.
Also, libinput on Linux has built in support for button debouncing, and may
ignore some rapid presses. [See here for how to disable debouncing in
libinput](../doc/disable_libinput_debouncing.md).

#### Macro key presses and releases

For more fine control over the button presses and release, the `press(keycode)`
and the `release(keycode)` macro commands can be used.

```yaml
keycodes:
  macro1:
    keycode: macro
    # This macro should output: ABCdef
    commands:
      - press(lsft)
      - a
      - b
      - c
      - release(lsft)
      - d
      - e
      - f
```

#### Looping macros

The `repeat` and `end_repeat` commands can be used to repeat a group of
instructions a given amount of times.

```yaml
keycodes:
  # A macro that rapidly clicks the left mouse button while it is held down.
  rapid_click:
    keycode: macro
    commands: # run when key is pressed
      - set_rate(10)
      - repeat(100) # Repeat the commands between the repeat and end_repeat
      -   press(lmsb)
      -   release(lmsb)
      - end_repeat
    commands_release: # run when key is released
      - release(lmsb)
```

To create an infinite loop use `repeat(0)`.

#### Mouse motion

The `move_mouse(x,y)` and `scroll_mouse(x,y)` can control the movement of the
mouse.

```yaml
keycodes:
  draw_triangle:
    keycode: macro
    commands:
      - set_rate(500)
      - move_mouse(-300, -300)
      - move_mouse( 300,    0)
      - move_mouse(   0,  300)
```

If smooth mouse motion between two points is desire, you can use loops:

```yaml
  smooth_triangle:
    keycode: macro
    commands:
      - set_rate(5)
      - repeat(100)
      -   move_mouse(-3, -3)
      - end_repeat()
      - repeat(100)
      -   move_mouse(+3,  0)
      - end_repeat()
      - repeat(100)
      -   move_mouse( 0, +3)
      - end_repeat()
```

#### List of macro functions

Below is a list of commands that can be used in macros.

Note: Macro commands are executed one after the other with a delay between each
command. However, commands with no delay will be executed immediately one after
the other.

| Macro Command        | Delay | Range                | Description                                                                                       |
| -------------        | ----- | -----                | -----------                                                                                       |
| keyplus keycode      | yes   | non-macro keycode    | Send a press and then a release event for the given keycode.                                      |
| `macro_finish()`     | no    |                      | Finish the macro. Automatically added at the end of the macro program.                            |
| `set_rate(r)`        | no    | r: (0, 65535)        | Set the rate at which macro keys/commands are pressed/executed.                                   |
| `set_clear_rate(r)`  | no    | r: (0, 65535)        | Set the hold time for key presses. That is how long it takes to generate a RELEASE after a PRESS. |
| `clear_keyboard()`   | no    |                      | Unpress all HID keyboard keys.                                                                    |
| `clear_mouse()`      | no    |                      | Unpress all mouse buttons.                                                                        |
| `repeat(count)`      | no    | count: (0, 65535)    | Repeat the next block of command `count` times. Using `count=0` to repeat forever.                |
| `end_repeat()`       | no    |                      | Finish a repeat block.                                                                            |
| `press(keycode)`     | yes   |                      | Generate a press event for the given `keycode`.                                                   |
| `release(keycode)`   | yes   |                      | Generate a release event for the given `keycode`.                                                 |
| `move_mouse(x, y)`   | yes   | x,y: (-32768, 32767) | Move the mouse by the given `x`, `y` values.                                                      |
| `scroll_mouse(x, y)` | yes   | x,y: (-128, 127)     | Scroll the mouse wheel by the given `x`, `y` values                                               |
