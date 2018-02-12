#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from layout.common import try_get, ParseError, check_range, MAX_DEVICE_ID

from layout.scan_mode import *

from keyplus import *

import struct

DEFAULT_FEATURE_MASK = FEATURE_CTRL_RF_DISABLE | FEATURE_CTRL_RF_MOUSE_DISABLE \
    | FEATURE_CTRL_WIRED_DISABLE;

class FeatureControl(object):

    FEATURE_NAME_MAP = {
        'usb': FEATURE_CTRL_USB_DISABLE,
        'wired': FEATURE_CTRL_WIRED_DISABLE,
        'wireless': FEATURE_CTRL_RF_DISABLE,
        'wireless_mouse': FEATURE_CTRL_RF_MOUSE_DISABLE,
        'bluetooth': FEATURE_CTRL_BT_DISABLE,
    }

    def __init__(self, feature_mask=DEFAULT_FEATURE_MASK):
        self.feature_ctrl = feature_mask

    def _lookup_feature(self, name):
        if (name in self.FEATURE_NAME_MAP):
            return self.FEATURE_NAME_MAP[name]
        else:
            raise ParseError("Unknown feature '{}'".format(feature_name))

    def enable_feature(self, feature_name):
        self.feature_ctrl &= ~self._lookup_feature(feature_name)

    def disable_feature(self, feature_name):
        self.feature_ctrl |= self._lookup_feature(feature_name)

    def set_feature(self, feature_name, state):
        if state:
            self.enable_feature(feature_name)
        else:
            self.disable_feature(feature_name)

    def has_feature(self):
        feature = self._lookup_feature(feature_name)
        return not bool(self.feature_ctrl & feature)

    def to_bytes(self):
        return struct.pack('< B', self.feature_ctrl)

class Device(object):
    def __init__(self, id, name, scan_mode, layout_name, layout_offset,
                 feature_ctrl=FeatureControl()):
        self.id = id
        self.name = name
        self.scan_mode = scan_mode
        self.layout_name = layout_name
        self.layout_offset = layout_offset
        self.feature_ctrl = feature_ctrl

    @staticmethod
    def from_json_obj(dev, device_name):
        result = None

        dev_id = try_get(dev, 'id', device_name, val_type=int)
        check_range(dev_id, 'id', 0, MAX_DEVICE_ID)

        dev_id = try_get(dev, 'id', device_name, val_type=int)

        scan_mode = ScanMode(try_get(dev, 'scan_mode', device_name), device_name)

        if scan_mode.mode != ScanMode.NO_MATRIX:
            layout_name = try_get(dev, 'layout', device_name, val_type=str)
            layout_offset = try_get(dev, 'layout_offset', device_name)
            result = Device(dev_id, device_name, scan_mode, layout_name, layout_offset)
        else:
            result = Device(dev_id, device_name, scan_mode, None, None)

        wireless = try_get(dev, 'enable_wireless_split', device_name, default=False, val_type=bool)
        result.feature_ctrl.set_feature('wireless', wireless)

        wireless = try_get(dev, 'enable_wireless_split', device_name, default=False, val_type=bool)
        result.feature_ctrl.set_feature('wireless', wireless)

        mouse = try_get(dev, 'enable_wireless_mouse', device_name, default=False, val_type=bool)
        result.feature_ctrl.set_feature('wireless_mouse', mouse)

        return result


    def __str__(self):
        if self.scan_mode.mode == ScanMode.NO_MATRIX:
            return "ScanMode(id={}, scan_mode=NO_MATRIX)".format(self.id)
        else:
            return "ScanMode(id={}, scan_mode={}, layout={}, layout_offset={})" \
                .format( self.id, self.scan_mode, self.layout_name, self.layout_offset)
