#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import copy
import struct

from keyplus.exceptions import KeyplusSettingsError

class IoMapper(object):
    def __init__(self):
        self.pin_mapper = None
        self.chip_info = None

    def get_pin_number(self, pin_name):
        raise Exception("InternalError: get_pin_number() not implemented")

    def get_pin_name(self, pin_number):
        raise Exception("InternalError: get_pin_name() not implemented")

    def get_pin_numbers(self, pin_names):
        return [self.get_pin_number(pin) for pin in pin_names]

    def get_pin_names(self, pin_numbers):
        return [self.get_pin_name(pin) for pin in pin_numbers]

    def get_pin_port_and_bit(self, pin_number):
        port_size = self.pin_mapper.port_size
        return (pin_number // port_size, pin_number % port_size)

    @property
    def io_port_size(self):
        return self.pin_mapper.port_size

    @property
    def io_port_count(self):
        return len(self.pin_mapper.ports)

    def get_storage_size(self):
        io_port_byte_size = self.io_port_size // 8
        io_port_total_size = self.io_port_count * io_port_byte_size
        return io_port_total_size

    def get_usable_pins(self):
        return copy.copy(self.pin_mapper.pins)

    def get_pin_masks(self, pin_list):
        result = [0] * self.io_port_count
        port_size = self.io_port_size
        for pin_number in pin_list:
            port, pin = (pin_number // port_size, pin_number % port_size)
            result[port] |= 1 << pin
        return result

    def get_pin_masks_as_bytes(self, pin_list):
        masks = self.get_pin_masks(pin_list)

        # Find out mask format based on port size
        port_size = self.io_port_size
        if port_size == 8:
            byte_fmt = '< {}B'.format(self.io_port_count)
        elif port_size == 32:
            byte_fmt = '< {}L'.format(self.io_port_count)

        return struct.pack(byte_fmt, *masks)

    def get_pins_from_mask_bytes(self, masks):
        result = []
        pin_number = 0
        for byte in masks:
            bit_mask = 1
            for bit_num in range(8):
                if byte & bit_mask:
                    result.append(pin_number)
                pin_number += 1
                bit_mask <<= 1
        return result

    def get_default_cols(self, count):
        result = []

        if count > len(self.pin_mapper.default_cols):
            raise KeyplusSettingsError(
                "Couldn't find {} column pins for {}. Maximum is {}. You might"
                " need to specify the pins manually."
                .format(
                    count,
                    self.chip_info.name,
                    len(self.pin_mapper.default_cols)
                )
            )

        for i in range(count):
            result.append(self.get_pin_number(self.pin_mapper.default_cols[i]))
        return result

    def get_default_rows(self, count):
        result = []

        if count > len(self.pin_mapper.default_rows):
            raise KeyplusSettingsError(
                "Couldn't find {} row pins for {}. Maximum is {}. You might"
                " need to specify the pins manually."
                .format(
                    count,
                    self.chip_info.name,
                    len(self.pin_mapper.default_rows)
                )
            )

        for i in range(count):
            result.append(self.get_pin_number(self.pin_mapper.default_rows[i]))
        return result

    def get_gpio_count(self):
        return self.pin_mapper.gpio_count

class IoMapperPins(IoMapper):
    def __init__(self, ports, pins, gpio_count, port_size=8, default_cols=[],
                 default_rows=[]):
        self.ports = ports
        self.pins = pins
        self.gpio_count = gpio_count
        self.port_size = port_size
        self.default_rows = default_rows
        self.default_cols = default_cols

        self.port_num_to_name = {}
        for port_name in self.ports:
            port_num = self.ports[port_name]
            self.port_num_to_name[port_num] = port_name

    def is_valid_pin(self, port, pin):
        if port not in self.ports:
            return False
        if pin > self.port_size:
            return False
        port_num = self.ports[port]

        return self.pins[port_num] & 1 << pin

    def is_valid_pin_number(self, pin_number):
        port = pin_number % self.port_size
        pin = pin_number // self.port_size
        if port not in self.ports:
            return False
        return self.pins[port] & 1 << pin

    def get_highest_pin_number(self):
        pin_number = 0
        max_pin_number = 0
        for pin_mask in self.pins:
            for i in range(self.port_size):
                if (pin_mask & (1 << i)):
                    max_pin_number = pin_number
                pin_number += 1
        return max_pin_number

    def get_pin_number(self, port, pin):
        port_num = self.ports[port]
        absolute_pin_num = port_num * self.port_size + pin
        return absolute_pin_num

