# keyplus layout format

The layout configuration files used by keyplus are yaml files. Yaml syntax
is pretty easy to understand, so you should be able to pick up everything
you need to know just by looking at the example layouts. The main thing you
need to watch out for are [special symbols and reserved words](https://stackoverflow.com/a/22235064), which need to be surrounded by single quote marks `'`.

## Overview

There's two files that you need to configure a keyplus layout:

* a layout file
* RF configuration for wireless keyboards (TODO: currently this is required even
  for wireless boards, instead make it optional if the target board is wired only)

## Layout file

The layout file is comprised of two main sections: the `devices` section and
the `layouts` section. The `devices` section describes the hardware and wiring
properties of keyboards, while the `layouts` section describes what keycodes
the keyboards will generate

### Global properties

| Field   | Description   |
|---------|---------------|
| report_mode | The default keyboard report_mode. Possible values: `auto_nkro`, `6kro`, `nkro`.  The `auto_nkro` mode will start the keyboard in `6kro` mode, and will automatically switch to `nkro` mode if more than 6 keys are pressed. This mode is useful as some BIOS's don't handle NKRO, so this mode allows you still access your BIOS without having to worry about configuring NKRO. |
| default_lang | TODO |

### Devices section

The `devices` section contains a list of keyboard devices. Each device is a
name, followed by the properties describing the device, for example:

```yaml
devices:
    my_keyboard:
        # device properties
    "Ergodox -- Left": # <- the device name can be quoted and include symbols/characters
        # device properties
    "Ergodox -- Right":
        # device properties
    Numpad:
        # device properties
    "wireless dongle - 1": # Note: wireless dongles are described in this list too!
        # device properties
```

#### Valid properties for devices

| Field   | Description   |
|---------|---------------|
| id      | A unique id between 0-64. |
| layout  | The name of the layout which this device maps to in the `layouts` section. |
| layout_offset  | When mapping to a split layout, this value determines which component this device will map to. It starts at `0` and must be less than the number of split components found in this device's `layout` field. |
| wireless_split | Enables or disables wireless split support (using nRF24). Note: this value needs to be enabled for non-split nRF24 keyboards as well (TODO: maybe it should be renamed?) |
| wireless_mouse | Enables unifying mouse support. Requires `wireless_split` to be enabled. |
| wired_split | Enables wired split support (using i2c). |
| scan_mode | A section for settings that control how the keyboard matrix is wired and functions. |
| scan_mode.mode | Possible values: `none, col_row, row_col, pin_gnd, pin_vcc`. |
| scan_mode.rows | Controls what row pins are used. Can simple be a number (in which case the default rows will be used). Alternatively, it can be a list of microcontroller pins to use as the row pins (e.g. `[A0, A1, B0, C7]`). |
| scan_mode.cols | Controls what column pins are used. Can simple be a number in which case the default columns will be used. Alternatively, it can be a list of microcontroller pins to use as the column pins (e.g. `[A0, A1, B0, C7]`).|
| scan_mode.matrix_map | Describes how the (row,column) pairs map to keys in the layout section. The field is a list of row, column pairs in the form `rXcY` (e.g. `[r0c0, r0c3, r0c1]`). The values are used to map a given (row,column) pair in the physical matrix to a key in a layout. That is the first value in the list will be mapped to the first key in the target `layout`, etc. If a device has no (row,column) pair to map to a key in the target `layout`, then the value `none` can be used to skip a key in the target layout. |
| scan_mode.pins | When pin scanning mode is used this value maps microcontroller pins to pins on the target `layout`. The values used here depend on what microcontroller you are using. For example, if target microcontroller was an AVR, your pin map might look like this: `[A3, A2, B0, B1]`. See the `spectre.yaml` layout for an example of pin scanning mode. NOTE: This value is only used when `scan_mode.mode` is set to `pin_gnd` or `pin_vcc`.|

##### Debounce settings

In side the `scan_mode` section you add a `debounce` section which will allow
you to tune various parameters in the key debouncing algorithm. If you omit
this section, then the some safe default values will be used.

| Field                                | Description     |
| ---------                            | --------------- |
| debounce_time_press                  | The amount of time to debounce a key when it is pressed (given in milliseconds). Basically, the amount of time that must pass before a key release can be registered. |
| debounce_time_release                | The amount of time to debounce a key after it is released (given in milliseconds). Basically, the amount of time that must pass before a new key press can be registered. |
| trigger_time_press                   | The minimum amount of time that a key must remain down before a key press will be generated. If a value of 0 is used, the key press will be registered immediately. |
| trigger_time_release                 | The minimum amount of time that a key must remain up before a key release will be generated. If a value of 0 is used, the key release will be registered immediately. |
| parasitic_discharge_delay_idle       | The delay between reading each row when scanning the matrix, given as a value between 0.0 to 48.0 in microseconds. When scanning a key matrix the microcontroller will read the keys in the matrix one row at a time. When the microcontroller reads a row, it will need to wait some amount of time before it can read a stable value for the keys in that row. This value allows you to modify the amount of time the microcontroller will wait before attempting to read the row.|
| parasitic_discharge_delay_debouncing | The same as `parasitic_discharge_delay_idle` except this value will be used when any key in the matrix is debouncing. |

#### The `matrix_map` field

How you wire the keyboard matrix doesn't have to match how the keys are arranged
in your layout. The `matrix_map` field lets you describe how the keys in the matrix
map to the corresponding layout in the `layouts` section.

As an example suppose you make a keyboard with 6 keys, and in your layout section (described below)
you have:

```yaml
layouts:
  abc_layout:
    default_layer: 0
    layers: [
      [ # layer 0 (base)
        [
            a, b, c, d, e, f
        ]
      ]
],
```

If you wired your keyboard to use 1 row and 6 columns,
then you might use a matrix map that looks like this:

```yaml
matrix_map: [ # version 1
    r0c0, r0c1, r0c2, r0c3, r0c4, r0c5,
    ]
```

Thus the key connected to row 0, column 0, will ouptput `a`. The key connected
to row 0, column 1 will output `b`, etc.

However, suppose you wired keyboard matrix with 2 rows and 3 columns, then
you might use a matrix map like this:

```yaml
matrix_map: [ # version 2
    r0c0, r0c1, r0c2, r1c0, r1c1, r1c2,
    ]
```

With this implementation, you can reuse the same layout for multiple different
boards even if they are wired differently. For example, if you wanted to use
two boards with the `abc_layout` example, you could define two different
devices each using one of the `matrix_map`'s given above and for both set
`layout: abc_layout`, and then they would both use the `abc_layout` without
having to make a separate layout for each board.

TODO: show how to use `keyplus-cli passthrough` to easily generate the matrix_map
section.

### Layouts section

The layout section determines what keycodes your keyboards will output, what
layers the keyboards have, and how the pieces of a split keyboard work together.

Ultimately, the layouts are made up of a list of keycodes which define what a
key does when it is pressed. Keyplus provides all the traditional keycodes
found on a standard keyboard, as well as its own special keycodes that can be
used to achieve advanced functionality. The [documentation for the keycodes
provided by keyplus can be found here](../doc/keycodes.md).

The next few sections will cover examples of how to make a simple keyboard
layout with multiple layers, as well as some examples of split keyboards.

#### Simple layouts

Below is a simple example that describes a simple numpad layout, with one
layer:

```yaml
  numpad_layout:
    layers: [
      [ # layer 0
        [ # numpad
          nlck, kp_/, kp_*, kp_-  ,
          kp_7, kp_8, kp_9, kp_+  , # note, since this is a numpad, we use the
          kp_4, kp_5, kp_6,         #`kp_` (keypad) version of the keycodes
          kp_1, kp_2, kp_3, kp_ent,
          kp_0,       kp_.
        ]
      ]
    ]
```

Now lets add another layer to the `numpad_layout` by replacing the `kp_.` key
with a layer key `L1`:

```yaml
  numpad_layout:
    layers: [
      [ # layer 0
        [ # numpad
          nlck, kp_/, kp_*, kp_-  ,
          kp_7, kp_8, kp_9, kp_+  ,
          kp_4, kp_5, kp_6,
          kp_1, kp_2, kp_3, kp_ent,
          kp_0,       L1,
        ]
      ],
      [ # layer 1
        [ # numpad
          ____, ____, ____, ____  ,
          g   , h   , i   , ____  ,
          d   , e   , f   ,
          a   , b   , c   , ____  ,
          ____,       ____,
        ]
      ]
    ]
```

Now when the `L1` is held, the keycodes on layer 1 will be used instead of layer 0.
Notice how we define some of the keycodes on layer 1 with a blank symbol `____`.
What this means is that keycode is *transparent* on that layer, and if that key
is pressed, it will fall back to the definition of the previous active layer.

There are also other kinds of layer keys with their own separate behaviour,
(TODO: add documentation on different layer changing keys)

#### Split keyboard layouts

Keyplus also has very flexible split keyboard support, and provides two ways
for how layers can be handled between devices. The first and more common way
is for all the devices in a split keyboard layout to share the same layer state.
In this case when a layer key is pressed on one piece of a split keyboard, it
will change layers on all the other devices as well. However, it is also
possible to have a split keyboard where each piece maintains its own
independent layer state.

##### Split keyboard layouts with shared layers

Defining a split keyboard layout with shared layers is very similar to the
non-split examples given above, except on each layer we include the list of
keycodes for each device. Also, when the device is defined in the `devices`
section, it is necessary to define which component of the split layout the
device maps to with the `layout_offset field`.  For example, below would define
a 3-way split keyboard with 2 layers:

```yaml
devices:
    device_1:
        layout: name_of_split_layout
        layout_offset: 0        # 0 means that this will be the 1st piece in the split layout
        # other device settings ...

    device_2:
        layout: name_of_split_layout
        layout_offset: 1        # 1 means that this will be the 2nd piece
        # other device settings ...

    device_3:
        layout: name_of_split_layout
        layout_offset: 2        # 2 means that this will be the 3rd piece
        # other device settings ...

layout:
  name_of_split_layout:
    layers: [
      [ # layer 0
        [
            # keycodes for 1st piece on layer 0
        ],
        [
            # keycodes for 2nd piece on layer 0
        ],
        [
            # keycodes for 3rd piece on layer 0
        ],
        # etc.
        # this list can continue for as many devices in the split layout
      ],
      [ # layer 1
        [
            # keycodes for 1st piece on layer 1
        ],
        [
            # keycodes for 2nd piece on layer 1
        ],
        [
            # keycodes for 3rd piece on layer 1
        ],
        # etc.
        # this list should have the same length as layer 0
      ],
      # etc. for up to 16 layers
```

##### Split keyboard layouts with independent layer state

It is also possible to define a split keyboard with each piece maintaining its
own layer state. In this way, when a layer key is press on one piece of a
split keyboard, it will not affect the layer state of any of the other pieces, and
all the pieces can potentially be on different layers at any moment in time.

Since keyplus maintains a separate layer state for each layout, what we need to
do is to map each piece of the split keyboard to its own individual layout.
Here is the same 3-way split keyboard example as above, except this time each
piece is mapped to a different layout and hence will get its own layer state:

```yaml
devices:
    device_1:
        layout: layout_piece_1
        layout_offset: 0   # 0 use zero for each layout offset, since we are
                           # going to map each piece to its own layout with
                           # only one spilt component in each of the layouts
        # other device settings ...

    device_2:
        layout: layout_piece_2
        layout_offset: 0
        # other device settings ...

    device_3:
        layout: layout_piece_3
        layout_offset: 0
        # other device settings ...

layout:
  layout_piece_1:
    layers: [
      [ # layer 0
        [
            # keycodes for 1st piece on layer 0
        ],
      ],
      [ # layer 1
        [
            # keycodes for 1st piece on layer 1
        ],
      ],
      # etc. for up to 16 layers

  layout_piece_2:
    layers: [
      [ # layer 0
        [
            # keycodes for 1st piece on layer 0
        ],
      ],
      [ # layer 1
        [
            # keycodes for 1st piece on layer 1
        ],
      ],
      # etc. for up to 16 layers

  layout_piece_3:
    layers: [
      [ # layer 0
        [
            # keycodes for 1st piece on layer 0
        ],
      ],
      [ # layer 1
        [
            # keycodes for 1st piece on layer 1
        ],
      ],
      # etc. for up to 16 layers
```
