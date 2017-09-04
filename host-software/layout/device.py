#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from layout.common import try_get, ParseError, check_range, MAX_DEVICE_ID

from layout.scan_mode import *

class Device:
    def __init__(self, id, name, scan_mode, layout_name, layout_offset):
        self.id = id
        self.name = name
        self.scan_mode = scan_mode
        self.layout_name = layout_name
        self.layout_offset = layout_offset

    def from_json_obj(dev, device_name):

        dev_id = try_get(dev, 'id', device_name, val_type=int)
        check_range(dev_id, 'id', 0, MAX_DEVICE_ID)

        scan_mode = ScanMode(try_get(dev, 'scan_mode', device_name), device_name)

        if scan_mode.mode != ScanMode.NO_MATRIX:
            layout_name = try_get(dev, 'layout', device_name, val_type=str)
            layout_offset = try_get(dev, 'layout_offset', device_name)
            return Device(dev_id, device_name, scan_mode, layout_name, layout_offset)
        else:
            return Device(dev_id, device_name, scan_mode, None, None)


    def __str__(self):
        if self.scan_mode.mode == ScanMode.NO_MATRIX:
            return "ScanMode(id={}, scan_mode=NO_MATRIX)".format(self.id)
        else:
            return "ScanMode(id={}, scan_mode={}, layout={}, layout_offset={})" \
                .format( self.id, self.scan_mode, self.layout_name, self.layout_offset)
