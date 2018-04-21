
0.3.1 (unreleased)
==================

* `layout` add support for `keycodes` section in the layout file for defining
  custom special keycodes
* `layout` add support for `hold` key in `keycodes` section
* `layout` add more alternative names to some keycodes: `trns`, `space`, 's_l0`,
  `s_lctl`, `int1`. Changed `lang_1` to `lang1` etc.

* `firmware` atmega32u4 support
* `firmware` made the maximum number of supported rows configurable at compile
  time, and increased the default value from 10 to 18.

* `keyplus-flasher` more error messages
* `keyplus-flasher` fixed labels not updating properly


0.3.0
==================

Changes to layout and config files:
-----------------------------------

* `layout` format is incompatible with previous versions
* `layout` files now have options to enable/disable I²C, nRF24 and mouse
  support.  By default these options are now turned off. So if you used any
  of these features they will need to be re-enabled in the layout file. See
  the example layout files for details.
* `layout` the keycode `menu`, HID keycode `KC_MENU`, has now been renamed to
  `hid_menu`. The keycode `menu` in layout files now maps to the HID keycode
  `KC_APPLICATION` as this is what most people expect.

Internal changes:
-----------------

* `python-api` new python API added. It is available in the `keyplus` package
  on PyPI.
* `python-api` rework all the code for parsing layout files.
* `python-api` add commands to read the layout and settings form the device.
* `python-api` add commands to deserialize layouts read from devices

* `keyplus-cli` add command to erase all layouts and settings
* `keyplus-cli` add commands to dump the raw hex of the layout and settings section
* `keyplus-cli` is now able to update RF, layout, and ID separately.

* `keyplus-flasher` add support for kp_boot_32u4 bootloader

* `firmware` add new `chip_id` concept to firmware settings allowing the
  `python-api` to discover what microcontroller the keyboard is using.
* `firmware` rework flash writing commands so that is possible to update only a
  portion of the layout.
* `firmware` layout updates can now be performed without the USB device
  needing to be reset
* `firmware-xmega` now utilizes the IRQ pin in receive mode
* `firmware-xmega` add arbitrary pin mapping to matrix scanning algorithm. It
  should now be possible to use any pins as row/columns.
* `firmware-xmega` add new matrix scanning modes: `col_row`, `pin_gnd`,
  `pin_vcc`. The `col_row` mode allows the direction of diodes to be flipped.
  The `pin_gnd` and `pin_vcc` modes allow for direct wiring of switches to GPIO
  pin and one of either GND (`pin_gnd`) or VCC (`pin_vcc`).

Bug fixes:
----------

* `firmware` fixes bug where it was possible to read the encryption key from the
  device.
* `firmware` fixes some bugs that would allow the nRF24 code to accept invalid
  packets.
* `firmware` I²C split keyboards now disable their nRF24 module if they are
  not connected to a USB port. This was causing dropped packets before.

*******************************************************************************

0.2.2 (2018-01-27)
==================

* Add error detection and recovery system
* Add ability for controllers to enter recover mode when it detect
  corrupt or invalid settings. Recover mode disables all features except those
  necessary to upload a new layout.

Start of change log.
====================
