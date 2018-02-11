#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

class IoMapperError(Exception):
    pass

class IoMapper(object):
    def __init__(self):
        pass

    def get_pin_number(self, pin_name):
        raise Exception("get_pin_number() not implemented")

class IoMapperPins(object):
    def __init__(self, ports, pins, port_size=8):
        self.ports = ports
        self.pins = pins
        self.port_size = port_size

    def is_valid_pin(self, port, pin):
        if port not in self.ports:
            return False
        if pin > self.port_size:
            return False
        port_num = self.ports[port]

        return self.pins[port_num] & 1 << pin

    def get_pin_number(self, port, pin):
        port_num = self.ports[port]
        absolute_pin_num = port_num * self.port_size + pin
        return absolute_pin_num
