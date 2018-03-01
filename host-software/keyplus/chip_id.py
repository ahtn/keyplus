#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from collections import namedtuple

from keyplus.exceptions import KeyplusSettingsError

ATMEL_ID = 0x03eb0000
NORDIC_ID = 0x19150000

ChipInfo = namedtuple(
    'ChipInfo',
    " ".join([
        "name",
        "chip_id",
        "architecture",
        "series",
        "flash_size",
        "ram_size",
        "usb"
    ])
)

def _create_nrf24(flash_size, name):
    return ChipInfo(
        name = name,
        chip_id = None, # filled out automatically later
        architecture = "8051",
        series = 'nRF24',
        flash_size = flash_size,
        ram_size = 2,
        usb = True,
    )

def _create_xmega(flash_size, series):
    pins, usb_support = {
        'A4': (44, False),
        'A3': (64, False),
        'A1': (100, False),
        'A4U': (44, True),
        'A3U': (64, True),
        'A3BU': (64, True),
        'A1U': (100, True),
        'B3': (64, True),
        'B1': (100, True),
        'C4': (44, True),
        'C3': (64, True),
    }[series]
    if flash_size <= 16:
        ram_size = 2
    elif flash_size <= 64:
        ram_size = 4
    elif flash_size <= 128:
        ram_size = 8
    elif flash_size <= 256:
        ram_size = 16
    elif flash_size <= 384:
        ram_size = 32
    return ChipInfo(
        name = "ATxmega{flash}{series}".format(flash=flash_size, series=series),
        chip_id = None, # filled out automatically later
        architecture = "XMEGA",
        series = series,
        flash_size = flash_size,
        ram_size = ram_size,
        usb = usb_support,
    )

def get_chip_name_from_id(chip_id):
    if chip_id in CHIP_ID_TABLE:
        return CHIP_ID_TABLE[chip_id].name
    else:
        raise KeyplusSettingsError("UnknownChipID({})".format(hex(chip_id)))

def lookup_chip_id(chip_id):
    if chip_id in CHIP_ID_TABLE:
        return CHIP_ID_TABLE[chip_id]
    else:
        return None

def _generate_chip_name_table(table):
    """
    Generate a mapping from chip_name -> chip_id.
    NOTE: names will be converted to lower case when added to the lookup table
    """
    result = {}
    for chip_id in table:
        result[table[chip_id].name.lower()] = table[chip_id]
    return result

def get_chip_id_from_name(name):
    if name in CHIP_NAME_TABLE:
        return CHIP_NAME_TABLE[name.lower()].chip_id
    else:
        raise KeyplusSettingsError("Unknown chip name '{}'".format(name))

CHIP_ID_TABLE = {
    # ATMEL micro controllers
    ATMEL_ID | 0x0001 : _create_xmega(16 , 'A4'),
    ATMEL_ID | 0x0002 : _create_xmega(32 , 'A4'),
    ATMEL_ID | 0x0002 : _create_xmega(64 , 'A4'),
    ATMEL_ID | 0x0003 : _create_xmega(64 , 'A3'),
    ATMEL_ID | 0x0004 : _create_xmega(128, 'A3'),
    ATMEL_ID | 0x0005 : _create_xmega(192, 'A3'),
    ATMEL_ID | 0x0006 : _create_xmega(256, 'A3'),
    ATMEL_ID | 0x0007 : _create_xmega(64 , 'A1'),
    ATMEL_ID | 0x0008 : _create_xmega(128, 'A1'),

    ATMEL_ID | 0x0009 : _create_xmega(16 , 'A4U'),
    ATMEL_ID | 0x000A : _create_xmega(32 , 'A4U'),
    ATMEL_ID | 0x000B : _create_xmega(64 , 'A4U'),
    ATMEL_ID | 0x000B : _create_xmega(128, 'A4U'),
    ATMEL_ID | 0x000C : _create_xmega(64 , 'A3U'),
    ATMEL_ID | 0x000D : _create_xmega(128, 'A3U'),
    ATMEL_ID | 0x000E : _create_xmega(192, 'A3U'),
    ATMEL_ID | 0x000F : _create_xmega(256, 'A3U'),
    ATMEL_ID | 0x0010 : _create_xmega(256, 'A3BU'),
    ATMEL_ID | 0x0011 : _create_xmega(64 , 'A1U'),
    ATMEL_ID | 0x0012 : _create_xmega(128, 'A1U'),

    ATMEL_ID | 0x0013 : _create_xmega(64 , 'B3'),
    ATMEL_ID | 0x0014 : _create_xmega(64 , 'B3'),
    ATMEL_ID | 0x0015 : _create_xmega(128, 'B1'),
    ATMEL_ID | 0x0016 : _create_xmega(128, 'B1'),

    ATMEL_ID | 0x0017 : _create_xmega(16 , 'C4'),
    ATMEL_ID | 0x0018 : _create_xmega(32 , 'C4'),
    ATMEL_ID | 0x0019 : _create_xmega(32 , 'C3'),
    ATMEL_ID | 0x001A : _create_xmega(64 , 'C3'),
    ATMEL_ID | 0x001B : _create_xmega(128, 'C3'),
    ATMEL_ID | 0x001C : _create_xmega(192, 'C3'),
    ATMEL_ID | 0x001D : _create_xmega(256, 'C3'),
    ATMEL_ID | 0x001E : _create_xmega(384, 'C3'),

    NORDIC_ID | 0x0001 : _create_nrf24(16, 'nRF24LU1-F16'),
    NORDIC_ID | 0x0002 : _create_nrf24(16, 'nRF24LU1P-F16'),
    NORDIC_ID | 0x0003 : _create_nrf24(32, 'nRF24LU1P-F32'),
}

# Add the chip_ids to the objects in the table
for chip_id in CHIP_ID_TABLE:
    CHIP_ID_TABLE[chip_id] = CHIP_ID_TABLE[chip_id]._replace(chip_id=chip_id)

CHIP_NAME_TABLE = _generate_chip_name_table(CHIP_ID_TABLE)

if __name__ == '__main__':
    print(CHIP_ID_TABLE)
