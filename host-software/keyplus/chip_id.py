#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from collections import namedtuple

from keyplus.exceptions import KeyplusSettingsError, KeyplusInternalError

import re

CHIP_ID_ATMEL = 0x03eb0000
CHIP_ID_NORDIC = 0x19150000
CHIP_ID_SILABS = 0x10C40000

ChipInfo = namedtuple(
    'ChipInfo',
    " ".join([
        "name",
        "chip_id",
        "architecture",
        "processor",
        "package",
        "pins",
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
        architecture = "nRF24",
        processor = "8051",
        series = 'nRF24LU1',
        pins = 32,
        package = "qfn32",
        flash_size = flash_size * 2**10,
        ram_size = 2 * 2**10,
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
        architecture = "AVR_XMEGA",
        processor = "AVR8",
        series = series,
        pins = pins,
        package = "",
        flash_size = flash_size * 2**10,
        ram_size = ram_size * 2**10,
        usb = usb_support,
    )

def _create_mega(flash_size, series):
    pins, usb_support, ram_size = {
        ('U2',  8): (32, True, 512),
        ('U2', 16): (32, True, 512),
        ('U2', 32): (32, True, 1024),
        ('U4', 16): (44, True, 1536),
        ('U4', 32): (44, True, 2560),
        ('U6', 32): (44, True, 2560),
        ('AT90USB', 64): (44, True, 4096),
        ('AT90USB', 128): (44, True, 8192),
    }[(series, flash_size)]

    return ChipInfo(
        name = "ATmega{flash}{series}".format(flash=flash_size, series=series),
        chip_id = None, # filled out automatically later
        architecture = "AVR_MEGA",
        processor = "AVR8",
        series = series,
        pins = pins,
        package = "",
        flash_size = flash_size * 2**10,
        ram_size = ram_size,
        usb = usb_support,
    )

def _create_efm8(name):
    # example string to match against:
    #   EFM8UB11F16G_QFN24
    m = re.match(r"EFM8(.B.)(.)F(\d+)(.)_(\D+)(\d+)", name)

    family       = m.group(1)
    feature_set  = m.group(2)
    flash_size   = int(m.group(3))
    temp_grade   = m.group(4)
    package_type = m.group(5)
    pin_count    = int(m.group(6))

    if flash_size <= 16:
        ram_size = 2 # 2kB XRAM
    else:
        ram_size = 4 # 4kB XRAM

    return ChipInfo(
        name = name,
        chip_id = None, # filled out automatically later
        architecture = "EFM8",
        processor = "8051",
        series = 'EFM8' + family.upper(),
        package = package_type + str(pin_count),
        pins = pin_count,
        flash_size = flash_size * 2**10,
        ram_size = ram_size * 2**10,
        usb = True,
    )


def get_chip_name_from_id(chip_id):
    if chip_id in CHIP_ID_TABLE:
        return CHIP_ID_TABLE[chip_id].name
    else:
        return "UnknownChipID({})".format(hex(chip_id))

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
        name = table[chip_id].name
        lookup_name = name.lower().replace('-', '_')
        result[lookup_name] = table[chip_id]
    return result

def get_chip_id_from_name(name):
    lookup_name = name.lower().replace('-', '_')
    if lookup_name in CHIP_NAME_TABLE:
        return CHIP_NAME_TABLE[lookup_name].chip_id
    else:
        raise KeyplusSettingsError("Unknown chip name '{}'".format(name))

CHIP_ID_TABLE = {
###############################################################################
#                              ATMEL (Microchip)                              #
###############################################################################

    CHIP_ID_ATMEL | 0x0001 : _create_xmega(16 , 'A4'),
    CHIP_ID_ATMEL | 0x0002 : _create_xmega(32 , 'A4'),
    CHIP_ID_ATMEL | 0x0002 : _create_xmega(64 , 'A4'),
    CHIP_ID_ATMEL | 0x0003 : _create_xmega(64 , 'A3'),
    CHIP_ID_ATMEL | 0x0004 : _create_xmega(128, 'A3'),
    CHIP_ID_ATMEL | 0x0005 : _create_xmega(192, 'A3'),
    CHIP_ID_ATMEL | 0x0006 : _create_xmega(256, 'A3'),
    CHIP_ID_ATMEL | 0x0007 : _create_xmega(64 , 'A1'),
    CHIP_ID_ATMEL | 0x0008 : _create_xmega(128, 'A1'),

    CHIP_ID_ATMEL | 0x0009 : _create_xmega(16 , 'A4U'),
    CHIP_ID_ATMEL | 0x000A : _create_xmega(32 , 'A4U'),
    CHIP_ID_ATMEL | 0x000B : _create_xmega(64 , 'A4U'),
    CHIP_ID_ATMEL | 0x000C : _create_xmega(128, 'A4U'),
    CHIP_ID_ATMEL | 0x000D : _create_xmega(64 , 'A3U'),
    CHIP_ID_ATMEL | 0x000E : _create_xmega(128, 'A3U'),
    CHIP_ID_ATMEL | 0x000F : _create_xmega(192, 'A3U'),
    CHIP_ID_ATMEL | 0x0010 : _create_xmega(256, 'A3U'),
    CHIP_ID_ATMEL | 0x0011 : _create_xmega(256, 'A3BU'),
    CHIP_ID_ATMEL | 0x0012 : _create_xmega(64 , 'A1U'),
    CHIP_ID_ATMEL | 0x0013 : _create_xmega(128, 'A1U'),

    CHIP_ID_ATMEL | 0x0020 : _create_xmega(64 , 'B3'),
    CHIP_ID_ATMEL | 0x0021 : _create_xmega(64 , 'B3'),
    CHIP_ID_ATMEL | 0x0022 : _create_xmega(128, 'B1'),
    CHIP_ID_ATMEL | 0x0023 : _create_xmega(128, 'B1'),

    CHIP_ID_ATMEL | 0x0030 : _create_xmega(16 , 'C4'),
    CHIP_ID_ATMEL | 0x0031 : _create_xmega(32 , 'C4'),
    CHIP_ID_ATMEL | 0x0032 : _create_xmega(32 , 'C3'),
    CHIP_ID_ATMEL | 0x0033 : _create_xmega(64 , 'C3'),
    CHIP_ID_ATMEL | 0x0034 : _create_xmega(128, 'C3'),
    CHIP_ID_ATMEL | 0x0035 : _create_xmega(192, 'C3'),
    CHIP_ID_ATMEL | 0x0036 : _create_xmega(256, 'C3'),
    CHIP_ID_ATMEL | 0x0037 : _create_xmega(384, 'C3'),


    CHIP_ID_ATMEL | 0x1000 : _create_mega(  8, 'U2'),   # CHIP_ID_ATmega8U2
    CHIP_ID_ATMEL | 0x1001 : _create_mega( 16, 'U2'),   # CHIP_ID_ATmega16U2
    CHIP_ID_ATMEL | 0x1002 : _create_mega( 32, 'U2'),   # CHIP_ID_ATmega32U2

    CHIP_ID_ATMEL | 0x1003 : _create_mega( 16, 'U4'),   # CHIP_ID_ATmega16U4
    CHIP_ID_ATMEL | 0x1004 : _create_mega( 32, 'U4'),   # CHIP_ID_ATmega32U4

    CHIP_ID_ATMEL | 0x1005 : _create_mega( 32, 'U6'),   # CHIP_ID_ATmega32U6
    CHIP_ID_ATMEL | 0x1006 : _create_mega( 64, 'AT90USB'),   # CHIP_ID_AT90USB646
    CHIP_ID_ATMEL | 0x1007 : _create_mega( 64, 'AT90USB'),   # CHIP_ID_AT90USB647
    CHIP_ID_ATMEL | 0x1008 : _create_mega(128, 'AT90USB'),   # CHIP_ID_AT90USB1286
    CHIP_ID_ATMEL | 0x1009 : _create_mega(128, 'AT90USB'),   # CHIP_ID_AT90USB1287

###############################################################################
#                            Nordic Semiconductor                             #
###############################################################################

    CHIP_ID_NORDIC | 0x0001 : _create_nrf24(16, 'nRF24LU1-F16'),
    CHIP_ID_NORDIC | 0x0002 : _create_nrf24(16, 'nRF24LU1P-F16'),
    CHIP_ID_NORDIC | 0x0003 : _create_nrf24(32, 'nRF24LU1P-F32'),

###############################################################################
#                                Silicon Labs                                 #
###############################################################################

    # efm8ub3
    CHIP_ID_SILABS | 0x00 : _create_efm8('EFM8UB30F40G_QFN20'),
    CHIP_ID_SILABS | 0x01 : _create_efm8('EFM8UB31F40G_QFN24'),
    CHIP_ID_SILABS | 0x02 : _create_efm8('EFM8UB31F40G_QSOP24'),

    # efm8ub2
    CHIP_ID_SILABS | 0x60 : _create_efm8('EFM8UB20F64G_QFP48'),
    CHIP_ID_SILABS | 0x61 : _create_efm8('EFM8UB20F64G_QFP32'),
    CHIP_ID_SILABS | 0x62 : _create_efm8('EFM8UB20F64G_QFN32'),
    CHIP_ID_SILABS | 0x63 : _create_efm8('EFM8UB20F32G_QFP48'),
    CHIP_ID_SILABS | 0x64 : _create_efm8('EFM8UB20F32G_QFP32'),
    CHIP_ID_SILABS | 0x65 : _create_efm8('EFM8UB20F32G_QFN32'),

    # efm8ub1
    CHIP_ID_SILABS | 0x41 : _create_efm8('EFM8UB10F16G_QFN28'),
    CHIP_ID_SILABS | 0x43 : _create_efm8('EFM8UB10F16G_QFN20'),
    CHIP_ID_SILABS | 0x45 : _create_efm8('EFM8UB11F16G_QSOP24'),
    CHIP_ID_SILABS | 0x49 : _create_efm8('EFM8UB10F8G_QFN20'),
    CHIP_ID_SILABS | 0x4A : _create_efm8('EFM8UB11F16G_QFN24'),

}

# Add the chip_ids to the objects in the table
for chip_id in CHIP_ID_TABLE:
    CHIP_ID_TABLE[chip_id] = CHIP_ID_TABLE[chip_id]._replace(chip_id=chip_id)

CHIP_NAME_TABLE = _generate_chip_name_table(CHIP_ID_TABLE)

if __name__ == '__main__':
    print(CHIP_ID_TABLE)
