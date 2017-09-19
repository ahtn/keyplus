# Logitech Bootloader for nRF24Lu1+ Unifying Receiver

## Flash layout

* 0x0000 - 0x67FF: Application code
* 0x6800 - 0x73FF: Data section
* 0x7400 - 0x7FFF: Bootloader region

## Behaviour

The bootloader is run at start-up of the nrf24lu1+.
It first decides if it should run the enter programming mode, or run the user program in the
region 0x0000-0x6800. It will enter programming mode if any of the following conditions
are met:

* If the bytes in the `AESIV` vector match the string `Enter ICP\0`.
    This is how a software reset to programming mode can be performed.
    The `AESIV` vector is 16 bytes long, the remaining 6 bytes may be loaded
    with any value.
* If the first instruction is not ljmp, that is the first byte of the program
region is not 0x02.
* If the jump address of the ljmp instruction is outside 0x67ff.
* If pins p0.4 and p0.5 are shorted.

User programs should be aware that the bootloader:

* Starts the watch dog counter with
```
TICKDV = 0xff // tick frequency 9ms
WWD = 0x0040 // 512 ms
```


## USB Programming

* 0x30 -> erase addr (maybe fill):
  - addr: uint16_t; The address to operate on
  - numpages?: uint8_t; the number of pages to fill/erase
  <!-- - fill_value: unit8_t; the value to fill the block -->
  - count(???): unit8_t; only seen 0x01

* 0x20 -> write data:
  args:
    - addr: uint16_t; The address to write to
    - size: uint8_t; The number of bytes to write to
    - data: uint8_t[size]; the data to write at the address

* 0x70 -> reset
  args:
    seems to set `00 00 00`, potentially the reset address

* 0x80 -> something

### Checksum
The used for the user program is crc16-ccitt
