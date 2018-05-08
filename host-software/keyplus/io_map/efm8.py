#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

import keyplus.chip_id

from keyplus.io_map.common import PinMap, IoMapperNumbered

EFM8_20_Pin = PinMap(
    ports = {
        'P0': 0,
        'P1': 1,
        'P2': 2,
    },
    pins = [
        0xff,
        0x07,
        0x03,
    ],
    gpio_count = 13,
    port_size = 8
)

EFM8_24_Pin = PinMap(
    ports = {
        'P0': 0,
        'P1': 1,
        'P2': 2,
    },
    pins = [
        0xff,
        0x7f,
        0x03,
    ],
    gpio_count = 17,
    port_size = 8
)

EFM8_28_Pin = PinMap(
    ports = {
        'P0': 0,
        'P1': 1,
        'P2': 2,
        'P3': 3,
    },
    pins = [
        0xff,
        0xff,
        0x0f,
        0x03,
    ],
    gpio_count = 22,
    port_size = 8
)

EFM8_32_Pin = PinMap(
    ports = {
        'P0': 0,
        'P1': 1,
        'P2': 2,
        'P3': 3,
    },
    pins = [
        0xff,
        0xff,
        0xff,
        0x01,
    ],
    gpio_count = 25,
    port_size = 8
)

EFM8_48_Pin = PinMap(
    ports = {
        'P0': 0,
        'P1': 1,
        'P2': 2,
        'P3': 3,
        'P4': 4,
    },
    pins = [
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
    ],
    gpio_count = 40,
    port_size = 8
)

class IoMapperEFM8(IoMapperNumbered):
    EFM8_PIN_MAP_TABLE = {
        20: EFM8_20_Pin,
        24: EFM8_24_Pin,
        28: EFM8_28_Pin,
        32: EFM8_32_Pin,
        48: EFM8_48_Pin,
    }

    def __init__(self, chip_id):
        super(IoMapperEFM8, self).__init__()
        self.chip_info = keyplus.chip_id.lookup_chip_id(chip_id)

        assert(self.chip_info != None)
        assert(self.chip_info.architecture == 'EFM8')
        assert(self.chip_info.pins in self.EFM8_PIN_MAP_TABLE)
        self.pin_map = IoMapperEFM8.EFM8_PIN_MAP_TABLE[self.chip_info.pins]
