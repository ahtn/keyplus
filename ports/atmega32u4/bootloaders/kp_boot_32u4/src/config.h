// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define BOOTLOADER_VERSION 0

#define CHIP_ID_MASK 0x3F
enum {
    CHIP_ID_ATmega8U2   = 0x00,
    CHIP_ID_ATmega16U2  = 0x01,
    CHIP_ID_ATmega32U2  = 0x02,

    CHIP_ID_ATmega16U4  = 0x03,
    CHIP_ID_ATmega32U4  = 0x04,

    CHIP_ID_ATmega32U6  = 0x05,

    CHIP_ID_AT90USB646  = 0x06,
    CHIP_ID_AT90USB647  = 0x07,
    CHIP_ID_AT90USB1286 = 0x08,
    CHIP_ID_AT90USB1287 = 0x09,
};

#define BOOT_SIZE_MASK 0xC0
enum {
    BOOT_SIZE_00 = (0b00 << 6),
    BOOT_SIZE_01 = (0b01 << 6),
    BOOT_SIZE_10 = (0b10 << 6),
    BOOT_SIZE_11 = (0b11 << 6),
};
