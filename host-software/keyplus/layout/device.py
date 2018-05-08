#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import keyplus.layout.scan_mode
from keyplus.layout.scan_mode import ScanMode
from keyplus.layout.parser_info import KeyplusParserInfo
from keyplus.cdata_types import feature_ctrl_t
from keyplus.device_info import KeyboardSettingsInfo

from keyplus.constants import *

import six
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
        self.layout = None
        self.layout_offset = None

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

    def build_settings_header(self, device_target):
        header = KeyboardSettingsInfo()

        header.device_id = self.device_id
        # TODO: encode utf-16LE
        # header.device_name = self.name.encode('utf-16le')

        header.device_name = self.name.encode('utf-8')
        header.scan_plan = self.scan_mode.generate_scan_plan(device_target)
        header.feature_ctrl = self.feature_ctrl.feature_ctrl

        # header.

        return header

    def to_json(self):
        result = {}

        result["id"] = self.device_id
        if not self.feature_ctrl.i2c_disabled:
            result["wired_split"] = True
        if not self.feature_ctrl.nrf24_disabled:
            result["wireless_split"] = True
        if not self.feature_ctrl.unifying_disabled:
            result["wireless_mouse"] = True

        result["layout"] = self.layout_id
        result["split_device_num"] = self.layout
        result["scan_mode"] = self.scan_mode.to_json()

        return result

    def parse_json(self, device_name, json_obj=None, parser_info=None):
        if parser_info == None:
            assert(json_obj != None)
            parser_info = KeyplusParserInfo(
                "<LayoutDevice>",
                {device_name : json_obj},
                print_warnings = True,
            )

        parser_info.enter(device_name)
        self.name = device_name

        self.device_id = parser_info.try_get(
            "id",
            field_type = int,
            field_range = [0, MAX_NUMBER_DEVICES-1]
        )

        self.mcu = parser_info.try_get(
            "mcu",
            default = None,
            field_type = six.string_types,
            optional = True,
        )

        self.scan_mode = ScanMode()
        self.scan_mode.parse_json(parser_info=parser_info)

        if self.scan_mode.mode != keyplus.layout.scan_mode.NO_MATRIX:
            self.layout = parser_info.try_get(
                "layout",
                field_type = [str, int],
            )

            self.split_device_num = parser_info.try_get(
                "layout_offset",
                default = 0,
                field_type = int,
                field_range = [0, MAX_NUMBER_DEVICES-1]
            )


        # TODO: unifying naming of feature_ctrl variables
        # Load any of the feature settings, use defaults if they are not found
        self.feature_ctrl.nrf24_disabled = not parser_info.try_get(
            "wireless_split",
            default = not self.feature_ctrl.nrf24_disabled,
            field_type = bool,
        )
        self.feature_ctrl.unifying_disabled = not parser_info.try_get(
            "wireless_mouse",
            default = not self.feature_ctrl.unifying_disabled,
            field_type = bool,
        )
        self.feature_ctrl.i2c_disabled = not parser_info.try_get(
            "wired_split",
            default = not self.feature_ctrl.i2c_disabled,
            field_type = bool,
        )

        self.studio_kle = parser_info.try_get(
            "studio_kle",
            default = None,
            field_type = list,
            optional = True,
        )

        # Finish parsing `device_name`
        parser_info.exit()
