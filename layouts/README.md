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
| name    | The name of your configuration. Currently doesn't do anything. |
| report_mode | The default keyboard report_mode. Possible values: `auto_nkro`, `6kro`, `nkro`.  The `auto_nkro` mode will start the keyboard in `6kro` mode, and will automatically switch to `nkro` mode if more than 6 keys are pressed. This mode is useful as some BIOS's don't handle NKRO, so this mode allows you till still access your BIOS without having to worry about configuring NKRO. |
| default_lang | TODO: |

### Devices section

The `devices` section contains a list of keyboard devices. Each device is a
name, followed by the properties describing describing the device, for exmaple:

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
| id      | A unique id between 0-64 |
| layout  | A string that references which layout this key maps to in the layout section. |
| layout_offset  | An integer that represent which component of a split keyboard this device should represent. Starts at `0` and must be less than the number of split components found in this device's `layout` field |
| scan_mode | Settings that control how the keyboard matrix is wired |
| scan_mode.mode | Possible values: `none, col_row, row_col(TODO), built_in(TODO)` |
| scan_mode.rows | The number of rows in the keyboard matrix. |
| scan_mode.cols | The number of columns in the keyboard matrix. |
| scan_mode.matrix_map | Describes how the (row,column) pairs map to keys in the layout section. This field is a list were each entry can either be a row,column pair`rXcY`, or 'none' to skip an entry. This list must have `scan_mode.rows * scan_mode.cols` entries. |


#### The `matrix_map` field

How you wire the keyboard matrix doesn't have to match how the keys are arranged
in your layout. The `matrix_map` field lets you describe how the keys in the matrix
map to the corresponding layout in the `layouts` section.

As an example suppose you make a keyboard with 6 keys, and in your layout section
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
devices each using one of the `matrix_map`'s given above for both set
`layout: abc_layout`, and then they would both use the `abc_layout` without
having to make a separate layout for each board.

### Layouts section
