![keyplus](https://rawgit.com/ahtn/keyplus/master/resources/keyplus_logo.svg)

## Setup instructions

TODO

## Building

Currently building of the firmware has been tested on Linux.

### xmega

You will need the `avr-gcc` tool chain and `python`.

```bash
git submodule init
git submodule update
```

Then from the `xmega` directory, run:

```bash
make keyplus_mini DEBUG_AES_KEY=1
```

TODO: improve build system

## Layout files

For more information about layout file format [see here](https://github.com/ahtn/keyplus/tree/master/layouts/README.md).

## Hardware files

For more information about the hardware [see this link](https://github.com/ahtn/keyboard_pcb/tree/master/keyplus_mini).

## License

The keyplus source code is released under the MIT software.
