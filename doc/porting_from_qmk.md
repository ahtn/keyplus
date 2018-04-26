# Porting a keyboard from QMK

**The 32u4 port of keyplus is in a highly ALPHA stage. This guide will show you how to get it working for _testing_. 
While it is functional, keyplus for 32u4 may contain bugs and is not production ready.**

A major advantage of keyplus over QMK is its ability to update the keymap and almost every setting without compilation.
After a generic hex (same for almost every keyboard) is flashed, the board can be configured through a user friendly 
YAML file uploaded through keyplus flasher. This includes the matrix and pin information that defines your keyboard.
The user should not need to build or flash a new hex unless there is a major firmware release with new features.

## Requirements
* ATmega32u4 based (other MCUs may be supported in the future)
* Uses the DFU or [kp_boot_32u4](https://github.com/ahtn/kp_boot_32u4) bootloader
  * If your board is Pro Micro based you can [convert it to kp_boot_32u4](https://github.com/ahtn/kp_boot_32u4#convert-a-arduino-pro-micro-to-use-the-bootloader-without-an-isp-programmer)
    without an ISP programmer.

## Writing your layout file
[See layout.yaml documentation.](https://github.com/ahtn/keyplus/blob/master/doc/layout_format.md)

### Convert layout file from QMK
[Q2K](https://github.com/2Cas/Q2K) is a python-based utility that can automatically parse and 
convert QMK keymaps into a keyplus YAML for most keyboards.

## Building keyplus (Ubuntu)
The latest version of keyplus is released [here](https://github.com/ahtn/keyplus/releases) **(No 32u4 release yet)**.
For most cases, you can just download the hex and flash. If you require more customisation (for instance, baking in a default layout)
this section will detail how to create your own build.

Set up your environment (TODO)

### For DFU 
Enter `/atmega32u4` and run `make BOARD=atmel-dfu`.

### For kp_boot_32u4
Enter `/atmega32u4` and run `make BOARD=default`.

### Including a default layout
You can bake a default layout in your hex file with by adding the following option to your make command.

`LAYOUT_FILE=<your layout file>.yaml`

### Advanced usage
If your keyboard requires advanced compile-time configuration or additional functionality/features, you can define a new board.
1. Duplicate `/atmega32u4/boards/atmel-dfu` or `/atmega32u4/boards/default`.
2. Rename the folder to `<your board name>`.
3. Modify `/atmega32u4/boards/<your board name>/config.mk` to suit your needs. See config.mk reference (TODO).
4. Build your version with `make BOARD=<your board name>`.

## Flashing
For devices with kp_boot_32u4, the firmware can be updated from keyplus flasher.

For devices with DFU, follow the regular steps to update your firmware using dfu-programmer, FLIP, or QMK Toolbox.
Further firmware updates will also need to be done with a DFU programmer.

## Compromises
* No wireless support (the ATmega32u4 does not have a hardware AES encryption module).
* LED backlighting and underglow is not implemented at this time.
