#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

USB_VID = 0x1209
USB_PID = 0xBB05

EP_SIZE_VENDOR = 64

SPMEN_bm = (1<<0)
PGERS_bm = (1<<1)
PGWRT_bm = (1<<2)
BLBSET_bm = (1<<3)
RWWSRE_bm = (1<<4)
SIGRD_bm = (1<<5)
RWWSB_bm = (1<<6)
SPMIE_bm = (1<<7)

SPM_HEADER_SIZE = 6
SPM_PAYLOAD_SIZE = EP_SIZE_VENDOR - SPM_HEADER_SIZE

USB_CMD_VERSION = 0
USB_CMD_INFO = 1
USB_CMD_ERASE = 2
USB_CMD_SPM = 3
USB_CMD_WRITE_EEPROM = 4
USB_CMD_RESET = 5

CHIP_ID_MASK = 0x3F

CHIP_ID_TABLE = {
    0x00: ("ATmega8U2"   , 8 * 2**10   , 512),
    0x01: ("ATmega16U2"  , 16 * 2**10  , 512),
    0x02: ("ATmega32U2"  , 32 * 2**10  , 1024),

    0x03: ("ATmega16U4"  , 16 * 2**10  , 512),
    0x04: ("ATmega32U4"  , 32 * 2**10  , 1024),

    0x05: ("ATmega32U6"  , 32 * 2**10  , 1024),

    0x06: ("AT90USB646"  , 64 * 2**10  , 2048),
    0x07: ("AT90USB647"  , 64 * 2**10  , 2048),
    0x08: ("AT90USB1286" , 128 * 2**10 , 4096),
    0x09: ("AT90USB1287" , 128 * 2**10 , 4096),
}

BOOT_SIZE_MASK = 0xC0
BOOT_SIZE_bp = 6
BOOT_SIZE_00 = (0b00 << BOOT_SIZE_bp)
BOOT_SIZE_01 = (0b01 << BOOT_SIZE_bp)
BOOT_SIZE_10 = (0b10 << BOOT_SIZE_bp)
BOOT_SIZE_11 = (0b11 << BOOT_SIZE_bp)

