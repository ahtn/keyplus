![keyplus](https://rawgit.com/ahtn/keyplus/master/resources/keyplus_logo.svg)

Keyplus aims to be an easy to use keyboard firmware with support for wireless
and wired split keyboards.

Currently in beta so lots of stuff still might change.

# Keyplus Flasher GUI

## Setup instructions

### Windows

Just download the EXE file.

### Linux

Clone the repository:
```bash
git clone https://github.com/ahtn/keyplus
git checkout v0.3.0
```

Next, install the packages `avr-gcc`, `avr-libc`, `avr-binutils`, `python3`, `make`, `hidapi`, and `python3-pyside`.

Then, install the python dependencies:
```bash
sudo pip install -U keyplus
```

Also, you need to initialize the git submodules:

```bash
cd keyplus
git submodule update --init --recursive
```

Now, you can run the program:

```bash
cd host-software
sudo python3 keyplus_flasher.py
```

#### Flashing without sudo on Linux

To connect USB devices on Linux without using sudo, you need to add the
appropriate udev rules to set their permissions.

To do this add [these udev rules](host-software/etc/udev/rules.d/50-embedded_devices.rules) to
the file `/etc/udev/rules.d/50-embedded_devices.rules` (create it if it doesn't
exist). Then to active these rules run:

```
sudo udevadm control --reload-rules
sudo udevadm trigger
```

You also will need to unplug and reconnect the USB device you want to use.

## Using the GUI

When starting with a new keyplus mini board, flash the latest firmware, configure the device and RF, and configure the layout, in that order.

### Flashing the firmware

Download the latest firmware from [the releases page](https://github.com/ahtn/keyplus/releases). In the drop down box at the top of the window, select "Firmware Update". Then, click the "Browse" button and select the firmware file you downloaded. Plug in your keyplus mini (or other compatible board), and you should see it appear in the bottom box.

![The box](https://rawgit.com/merlin04/keyplus/master/resources/box.png)

Click the "Program" button, and it should flash the firmware onto the board. If it gives an error, try again.

### Configure the device and RF

In the drop down box at the top of the window, select "Device and RF". Then, click "Generate new RF settings", and save the file somewhere. Click the "Browse" button next to the "Layout settings file" box, and select your layout YAML file. Input your device ID, and click the program button that is next to the board you want to program. If it doesn't work, try again.

To make the layout file, see [here](https://github.com/ahtn/keyplus/tree/master/layouts).

### Configure the layout

In the drop down box at the top of the window, select "Layout". Click the "Browse" button next to the "Layout settings file" box, and select your layout YAML file. Click the program button that is next to the board you want to program. If it doesn't work, try again.

# Keyplus CLI

## Setup instructions

TODO

## Building

Currently building of the firmware has been tested on Linux.

### xmega

#### Installing dependencies

To compile the code on Linux, you will need the following programs installed:
`avr-gcc`, `avr-libc`, `avr-binutils`, `python3`, `make`, and `hidapi`. On Arch
Linux:

```
sudo pacman -S avr-gcc avr-libc avr-binutils python3 make hidapi python-pyside
```

Make sure that you have a relatively recent version of
`avr-gcc`. Some older versions do not have support for xmega chips (e.g. avr-gcc
included in Ubuntu 14.04). If the build commands fail with an error like
`warning "device type not defined"`, then you probably need a newer version
of `avr-gcc` and `avr-libc`.

The build scripts need some python libraries installed. You should get
all the necessary packages if you install the `keyplus` python library with:

```
sudo pip install -U keyplus
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
