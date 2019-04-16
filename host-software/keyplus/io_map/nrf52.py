#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

import keyplus.chip_id

from keyplus.io_map.common import PinMap, IoMapperNumbered

NRF52_48GPIO = PinMap(
    ports = {
        'P0': 0,
        'P1': 1,
    },
    pins = [
        0xffffffff,
        0x0000ffff,
    ],
    gpio_count = 48,
    port_size = 32
)

class IoMapperNRF52(IoMapperNumbered):
    PIN_MAP_TABLE = {
        73: NRF52_48GPIO,
        93: NRF52_48GPIO,
    }

    def __init__(self, chip_id):
        super(IoMapperNRF52, self).__init__()
        self.chip_info = keyplus.chip_id.lookup_chip_id(chip_id)

        assert(self.chip_info != None)
        assert(self.chip_info.architecture == 'nRF52')
        assert(self.chip_info.pins in self.PIN_MAP_TABLE)
        self.pin_map = IoMapperNRF52.PIN_MAP_TABLE[self.chip_info.pins]
