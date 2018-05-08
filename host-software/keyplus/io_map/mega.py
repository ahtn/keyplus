#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

import keyplus.chip_id

from keyplus.io_map.common import PinMap, IoMapperAVR

AVRMegaU4 = PinMap(
    ports = {
        'B': 0,
        'C': 1,
        'D': 2,
        'E': 3,
        'F': 4,
    },
    pins = [
        0xff,
        0xc0,
        0xff,
        0x44,
        0xf3,
    ],
    gpio_count = 26,
    default_rows = [
    ],
    default_cols = [
    ],
    port_size = 8
)

class IoMapperAVRMega(IoMapperAVR):
    AVR_MEGA_SERIES_TABLE = {
        'U2': None,
        'U4': AVRMegaU4,
        'U6': None, # same as A series
    }

    def __init__(self, chip_id):
        super(IoMapperAVRMega, self).__init__()
        self.chip_info = keyplus.chip_id.lookup_chip_id(chip_id)

        assert(self.chip_info != None)
        assert(self.chip_info.architecture == 'AVR_MEGA')
        assert(self.chip_info.series in self.AVR_MEGA_SERIES_TABLE)
        self.pin_map = IoMapperAVRMega.AVR_MEGA_SERIES_TABLE[self.chip_info.series]
