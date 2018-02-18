![keyplus](https://rawgit.com/ahtn/keyplus/master/resources/keyplus_logo.svg)

Keyplus aims to be an easy to use keyboard firmware with support for wireless
and wired split keyboards.

Currently in beta so lots of stuff still might change.

## Setup instructions

TODO

## Building

Currently building of the firmware has been tested on Linux.

### xmega

#### Installing dependencies

To compile the code on Linux, you will need the following programs installed:
`avr-gcc`, `avr-libc`, `avr-binutils`, `python3`, `make` and `hidapi`. On Arch
Linux:

```
sudo pacman -S avr-gcc avr-libc avr-binutils python3 make hidapi
```

Make sure that you have a relatively recent version of
`avr-gcc`. Some older versions do not have support for xmega chips (e.g. avr-gcc
included in Ubuntu 14.04). If the build commands fail with an error like
`warning "device type not defined"`, then you probably need a newer version
of `avr-gcc` and `avr-libc`.

The build scripts need some python libraries installed. You should get
all the necessary packages if you install the `keyplus` python library with:

```
sudo pip install keyplus
```

Also, you need to initialize the git submodules:

```bash
git submodule update --init --recursive
```

#### Building the firmware

From the `xmega` directory, run:

```bash
make BOARD=keyplus_mini
```

You can provide the build system with layout files and it will preload them
into the generated hex file:

```bash
make BOARD=keyplus_mini RF_FILE=rf.yaml LAYOUT_FILE=layout.yaml ID=0
```

You should then be able to program the board using the bootloader using:

```bash
make BOARD=keyplus_mini program-boot
```

#### Programming the bootloader

If you have a board that you made yourself, then you will need to flash the
bootloader before you can use the `program-boot` command. To do this, you will
first need to build and flash the bootloader.

To build the bootloader, first enter the `xmega/xusb-boot/` directory, and
run:

```bash
make BOARD=keyplus_mini
```

To program the bootloader, you will need a PDI programmer. Based on which
programmer you are using you will need to change the `AVRDUDE_CMD` variable
in the `Makefile`. The default is set for AVRISP MkII, so if you are using
this programmer, you don't need to change anything.

Then once the programmer is configured and connected to the board correctly,
you should be able to run:
```
make program-fuses
make BOARD=keyplus_mini program-hard
make program-lock
```

#### Working with different XMEGA chips

There are several different versions of xmega microcontrollers, with different
flash and package sizes. The build system assumes that you are using an
`ATxmega32a4u` by default. If you are not using this chip, then you will need
to tell the build system which one you are using by setting the `MCU` variable.
For example, to build the bootloader or firmware for the `ATxmega64a4u` you
would need to call the `make` like this:

```bash
make MCU=atxmega64a4u BOARD=keyplus_mini
```

You will also need to set the `MCU` variable when calling the programming commands.

## Layout files

For more information about layout file format [see here](https://github.com/ahtn/keyplus/tree/master/layouts/README.md).

## Hardware files

For more information about the hardware [see this link](https://github.com/ahtn/keyboard_pcb/tree/master/keyplus_mini).

## License

The keyplus source code is released under the MIT software.
