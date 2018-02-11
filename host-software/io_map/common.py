#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import copy
import struct

class IoMapperError(Exception):
    pass

class IoMapper(object):
    def __init__(self):
        self.pin_mapper = None

    def get_pin_number(self, pin_name):
        raise Exception("get_pin_number() not implemented")

    def get_pin(self, pin_name):
        pin_num = self.get_pin_number(pin_name)
        port_size = self.pin_mapper.port_size
        return (pin_num // port_size, pin_num % port_size)

    def get_io_port_size(self):
        return self.pin_mapper.port_size

    def get_io_port_count(self):
        return len(self.pin_mapper.ports)

    def get_usable_pins(self):
        return copy.copy(self.pin_mapper.pins)

    def get_pin_masks(self, pin_list):
        result = [0] * self.get_io_port_count()
        port_size = self.get_io_port_size()
        for pin_number in pin_list:
            port, pin = (pin_number // port_size, pin_number % port_size)
            result[port] |= 1 << pin
        return result

    def get_pin_masks_as_bytes(self, pin_list):
        masks = self.get_pin_masks(pin_list)

        # Find out mask format based on port size
        port_size = self.get_io_port_size()
        if port_size == 8:
            byte_fmt = '< {}B'.format(self.get_io_port_count())
        elif port_size == 32:
            byte_fmt = '< {}L'.format(self.get_io_port_count())

        return struct.pack(byte_fmt, *masks)

    def get_default_cols(self, count):
        result = []
        for i in range(count):
            result.append(self.get_pin_number(self.pin_mapper.default_cols[i]))
        return result

    def get_default_rows(self, count):
        result = []
        for i in range(count):
            result.append(self.get_pin_number(self.pin_mapper.default_rows[i]))
        return result

class IoMapperPins(object):
    def __init__(self, ports, pins, port_size=8, default_cols=[], default_rows=[]):
        self.ports = ports
        self.pins = pins
        self.port_size = port_size
        self.default_rows = default_rows
        self.default_cols = default_cols

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

    def get_pin_number(self, port, pin):
        port_num = self.ports[port]
        absolute_pin_num = port_num * self.port_size + pin
        return absolute_pin_num

