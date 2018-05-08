#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

import keyplus.chip_id

from keyplus.io_map.common import IoMapperAVR, PinMap

XmegaPinsA4U = PinMap(
    ports = {
        'A': 0,
        'B': 1,
        'C': 2,
        'D': 3,
        'E': 4,
        'R': 5
    },
    pins = [
        0xff,
        0x0f,
        0xff,
        0x3f,
        0x0f,
        0x03,
    ],
    gpio_count = 34 - 2,
    default_rows = [
        'D0', 'D1', 'D2', 'D3', 'D4', 'D5',
        'C3', 'C2', 'C1', 'C0'
    ],
    default_cols = [
        'A0', 'A1', 'A2', 'A3', 'A4', 'A5', 'A6', 'A7',
        'B0', 'B1', 'B2', 'B3',
        'C0', 'C1', 'C2', 'C3',
    ],
    port_size = 8
)


XmegaPinsA3U = PinMap(
    ports = {
        'A': 0,
        'B': 1,
        'C': 2,
        'D': 3,
        'E': 4,
        'F': 5,
        'R': 6
    },
    pins = [
        0xff,
        0xff,
        0xff,
        0x3f,
        0xff,
        0xff,
        0x03,
    ],
    gpio_count = 50 - 2,
    port_size = 8,
    default_rows = [
    ],
    default_cols = [
    ],
)

XmegaPinsA1U = PinMap(
    ports = {
        'A':  0,
        'B':  1,
        'C':  2,
        'D':  3,
        'E':  4,
        'F':  5,
        'H':  6,
        'J':  7,
        'K':  8,
        'Q':  9,
        'R': 10,
    },
    pins = [
        0xff,
        0xff,
        0xff,
        0x3f,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0x0f,
        0x03,
    ],
    gpio_count = 78 - 2,
    port_size = 8
)

class IoMapperXmega(IoMapperAVR):
    XMEGA_SERIES_TABLE = {
        'A4U': XmegaPinsA4U,
        'A3U': XmegaPinsA3U,
        'C3': XmegaPinsA3U, # same as A series
        'A1U': XmegaPinsA1U,
        'C1': XmegaPinsA1U, # same as A series
    }

    def __init__(self, chip_id):
        super(IoMapperXmega, self).__init__()
        self.chip_info = keyplus.chip_id.lookup_chip_id(chip_id)

        assert(self.chip_info != None)
        assert(self.chip_info.architecture == 'AVR_XMEGA')
        assert(self.chip_info.series in self.XMEGA_SERIES_TABLE)
        self.pin_map = IoMapperXmega.XMEGA_SERIES_TABLE[self.chip_info.series]
