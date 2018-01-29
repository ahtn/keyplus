![keyplus](https://rawgit.com/ahtn/keyplus/master/resources/keyplus_logo.svg)

Keyplus aims to be an easy to use keyboard firmware with support for wireless
and wired split keyboards.

Currently in beta so lots of stuff still might change.

## Setup instructions

TODO

## Building

Currently building of the firmware has been tested on Linux.

### xmega

You will need the `avr-gcc` tool chain and `python3`.

```bash
git submodule init
git submodule update
```

Then from the `xmega` directory, run:

```bash
make BOARD=keyplus_mini
```

You can provide the build system with layout files and it will preload them
into the generated hex file:

```bash
make BOARD=keyplus_mini RF_FILE=rf.yaml LAYOUT_FILE=layout.yaml ID=0
```

## Layout files

For more information about layout file format [see here](https://github.com/ahtn/keyplus/tree/master/layouts/README.md).

## Hardware files

For more information about the hardware [see this link](https://github.com/ahtn/keyboard_pcb/tree/master/keyplus_mini).

## License

The keyplus source code is released under the MIT software.
