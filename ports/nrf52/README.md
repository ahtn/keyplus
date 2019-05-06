# nRF52

## Notes

* [Notes on setting using nrf52 sdk](../../doc/nrf52/nrf52_sdk.md)
* [How to flash hex files using nRF Connect](https://wiki.makerdiary.com/nrf52840-mdk-usb-dongle/programming/).

## Building

Simplest way to build

```sh
make BOARD=nrf52840_dongle hex
```

## Programming

### Programming the nRF52840 DevKit

Use the `program` target, e.g.

```sh
make BOARD=nrf52840_dongle LAYOUT_FILE=layout.yaml RF_FILE=rf.yaml ID=21 program
```

### Programming the Nordic nRF52840 USB Dongle
[The Nordic nRF52840 USB
dongle](https://www.nordicsemi.com/?sc_itemid=%7BCDCCA013-FE4C-4655-B20C-1557AB6568C9%7D)
uses the nRF52 Open DFU Bootloader. First build the hex file with:

```
make BOARD=nrf52840_dongle hex
```

This will create the hex in the `build/nrf52840_dongle` directory. This file
then be flashed to the dongle using [nRF Connect Desktop](https://wiki.makerdiary.com/nrf52840-mdk-usb-dongle/programming/).

Note when using this bootloader, you should not pre-load layout/rf settings,
since the bootloader runs a CRC error detection over the flashed hex file.

### Programming the nRF52840 Micro Dev Kit USB Dongle
For [the nRF52840 MDK USB
Dongle](https://wiki.makerdiary.com/nrf52840-mdk-usb-dongle/), follow the same
steps as the Nordic dongle. To enter the bootloader on the MDK dongle, hold down
the black button while plugging it in. The red LED should glow when the
bootloader is running and the device should show up in nRF Connect.
