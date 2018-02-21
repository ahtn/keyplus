#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

# from layout.common import try_get, ParseError, check_range, MAX_DEVICE_ID

from keyplus.layout.scan_mode import ScanMode
from keyplus.cdata_types import feature_ctrl_t

from keyplus.constants import *

import struct

DEFAULT_FEATURE_MASK = FEATURE_CTRL_RF_DISABLE | FEATURE_CTRL_RF_MOUSE_DISABLE \
    | FEATURE_CTRL_WIRED_DISABLE;

class LayoutDevice(object):
    def __init__(self, device_id=0, name=None, layout_name=None,
                 scan_mode=None, layout_id=None, split_device_num=0):
        self.device_id = device_id
        self.name = name
        self.layout_id = layout_id
        self.scan_mode = scan_mode or ScanMode()
        self.split_device_num = split_device_num
        self.feature_ctrl = feature_ctrl_t()
        self.feature_ctrl.feature_ctrl = DEFAULT_FEATURE_MASK

    def load_raw_data(self, device_info, layout_info, pin_mapping=None):
        self.device_id = device_info.device_id
        self.name = device_info.get_name_str()
        self.feature_ctrl.feature_ctrl = device_info.feature_ctrl

        if pin_mapping:
            self.scan_mode.load_raw_data(device_info.scan_plan, pin_mapping)

        # NOTE: yaml files use a name for layout_id, using a number here
        # TODO: Might need to apply the layout name differently later.
        dev_info = layout_info.get_device_info(self.device_id)
        self.layout_id = dev_info.layout_id
        self.split_device_num = layout_info.get_split_device_number(self.device_id)

    def parse_json_object(self, json_obj, parser_info=None):
        if parser_info == None:
            parser_info = KeyplusParserInfo(
                "<ScanMode Dict>",
                {"scan_mode": json_obj}
            )
        parser_info.enter("scan_mode")

        self.device_id = parser_info.try_get("id", field_type=int)
        parser_info.check_range(0, MAX_DEVICE_ID)


# class Device(object):
#     def __init__(self, id, name, scan_mode, layout_name, layout_offset,
#                  feature_ctrl=DEFAULT_FEATURE_MASK):
#         self.id = id
#         self.name = name
#         self.scan_mode = scan_mode
#         self.layout_name = layout_name
#         self.layout_offset = layout_offset
#         self.feature_ctrl = FeatureControl(feature_ctrl)

#     @staticmethod
#     def from_json_obj(dev, device_name):
#         result = None

#         dev_id = try_get(dev, 'id', device_name, val_type=int)
#         check_range(dev_id, 'id', 0, MAX_DEVICE_ID)

#         dev_id = try_get(dev, 'id', device_name, val_type=int)

#         scan_mode = ScanMode(try_get(dev, 'scan_mode', device_name), device_name)

#         if scan_mode.mode != ScanMode.NO_MATRIX:
#             layout_name = try_get(dev, 'layout', device_name, val_type=str)
#             layout_offset = try_get(dev, 'layout_offset', device_name)
#             result = Device(dev_id, device_name, scan_mode, layout_name, layout_offset)
#         else:
#             result = Device(dev_id, device_name, scan_mode, None, None)

#         wireless = try_get(dev, 'wireless_split', device_name, default=False, val_type=bool)
#         result.feature_ctrl.set_feature('wireless', wireless)

#         wired = try_get(dev, 'wired_split', device_name, default=False, val_type=bool)
#         result.feature_ctrl.set_feature('wired', wired)

#         mouse = try_get(dev, 'wireless_mouse', device_name, default=False, val_type=bool)
#         result.feature_ctrl.set_feature('wireless_mouse', mouse)

#         return result


#     def __str__(self):
#         if self.scan_mode.mode == ScanMode.NO_MATRIX:
#             return "ScanMode(id={}, scan_mode=NO_MATRIX)".format(self.id)
#         else:
#             return "ScanMode(id={}, scan_mode={}, layout={}, layout_offset={})" \
#                 .format( self.id, self.scan_mode, self.layout_name, self.layout_offset)
