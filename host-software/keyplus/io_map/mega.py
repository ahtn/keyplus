#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

import keyplus.chip_id

from keyplus.io_map.common import *

AVRMegaU4 = IoMapperPins(
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

class IoMapperAVRMega(IoMapper):
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
        self.pin_mapper = IoMapperAVRMega.AVR_MEGA_SERIES_TABLE[self.chip_info.series]

    def get_pin_number(self, pin_name):
        try:
            pin_name = pin_name.upper()
            port = pin_name[0]
            pin = int(pin_name[1:])
        except:
            raise IoMapperError("Invalid pin name '{}', correct format "
                                "is a letter followed by a number. E.g. C1, B0, etc"
                                .format(pin_name))

        if not self.pin_mapper.is_valid_pin(port, pin):
            raise IoMapperError("The pin '{}' does not exist on the given microcontroller '{}'"
                                .format(pin_name, self.chip_info.name))

        return self.pin_mapper.get_pin_number(port, pin)

    def get_pin_name(self, pin_number):
        port_number, pin_bit = self.get_pin_port_and_bit(pin_number)
        if pin_number > self.pin_mapper.get_highest_pin_number():
            raise IoMapperError("Pin number '{}' doesn't exist on this mcu"
                                .format(pin_number))
        return "{port_name}{pin_bit}".format(
            port_name = self.pin_mapper.port_num_to_name[port_number],
            pin_bit = pin_bit,
        )
