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
        self.pin_map = None
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
        port_size = self.pin_map.port_size
        return (pin_number // port_size, pin_number % port_size)

    @property
    def io_port_size(self):
        return self.pin_map.port_size

    @property
    def io_port_count(self):
        return len(self.pin_map.ports)

    def get_storage_size(self):
        io_port_byte_size = self.io_port_size // 8
        io_port_total_size = self.io_port_count * io_port_byte_size
        return io_port_total_size

    def get_usable_pins(self):
        return copy.copy(self.pin_map.pins)

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

        if count > len(self.pin_map.default_cols):
            raise KeyplusSettingsError(
                "Couldn't find {} column pins for {}. Maximum is {}. You might"
                " need to specify the pins manually."
                .format(
                    count,
                    self.chip_info.name,
                    len(self.pin_map.default_cols)
                )
            )

        for i in range(count):
            result.append(self.get_pin_number(self.pin_map.default_cols[i]))
        return result

    def get_default_rows(self, count):
        result = []

        if count > len(self.pin_map.default_rows):
            raise KeyplusSettingsError(
                "Couldn't find {} row pins for {}. Maximum is {}. You might"
                " need to specify the pins manually."
                .format(
                    count,
                    self.chip_info.name,
                    len(self.pin_map.default_rows)
                )
            )

        for i in range(count):
            result.append(self.get_pin_number(self.pin_map.default_rows[i]))
        return result

    def get_gpio_count(self):
        return self.pin_map.gpio_count

class PinMap(object):
    def __init__(self, ports, pins, gpio_count, port_size=8, default_cols=None,
                 default_rows=None):
        self.ports = ports
        self.pins = pins
        self.gpio_count = gpio_count
        self.port_size = port_size
        self.default_rows = default_rows or []
        self.default_cols = default_cols or []

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

class IoMapperAVR(IoMapper):
    def get_pin_number(self, pin_name):
        try:
            pin_name = pin_name.upper()
            port = pin_name[0]
            pin = int(pin_name[1:])
        except:
            raise KeyplusSettingsError("Invalid pin name '{}', correct format "
                                "is a letter followed by a number. E.g. C1, B0, etc"
                                .format(pin_name))

        if not self.pin_map.is_valid_pin(port, pin):
            raise KeyplusSettingsError("The pin '{}' does not exist on the given microcontroller '{}'"
                                .format(pin_name, self.chip_info.name))

        return self.pin_map.get_pin_number(port, pin)

    def get_pin_name(self, pin_number):
        port_number, pin_bit = self.get_pin_port_and_bit(pin_number)
        if pin_number > self.pin_map.get_highest_pin_number():
            raise KeyplusSettingsError("Pin number '{}' doesn't exist on this mcu"
                                .format(pin_number))
        return "{port_name}{pin_bit}".format(
            port_name = self.pin_map.port_num_to_name[port_number],
            pin_bit = pin_bit,
        )

class IoMapperNumbered(IoMapper):
    """ IoMapper for pins with format 'Px.x'. Used with 8051 and some ARM chips"""

    def get_pin_number(self, pin_name):
        try:
            port, pin = pin_name.upper().split('.')
            pin = int(pin)
        except:
            raise KeyplusSettingsError("Invalid pin name '{}', correct format for 8051 is"
                                "a 'Px.x'. For example: P0.3, P1.7"
                                .format(pin_name))

        if not self.pin_map.is_valid_pin(port, pin):
            raise KeyplusSettingsError("The pin '{}' does not exist on the given microcontroller '{}'"
                                .format(pin_name, self.chip_info.name))

        return self.pin_map.get_pin_number(port, pin)

    def get_pin_name(self, pin_number):
        port_number, pin_bit = self.get_pin_port_and_bit(pin_number)
        if pin_number > self.pin_map.get_highest_pin_number():
            raise KeyplusSettingsError("Pin number '{}' doesn't exist on this mcu."
                                .format(pin_number))
        return "{port_name}.{pin_bit}".format(
            port_name = self.pin_map.port_num_to_name[port_number],
            pin_bit = pin_bit,
        )

