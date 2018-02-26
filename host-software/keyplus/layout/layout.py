#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import json
import yaml
import os

from keyplus.layout.parser_info import KeyplusParserInfo
from keyplus.layout.device import LayoutDevice
from keyplus.layout.keyboard_layout import *
from keyplus.layout.rf_settings import *
from keyplus.constants import *
from keyplus.debug import DEBUG

REPORT_MODE_MAP = {
    'auto_nkro': KEYBOARD_REPORT_MODE_AUTO,
    'nkro': KEYBOARD_REPORT_MODE_NKRO,
    '6kro': KEYBOARD_REPORT_MODE_6KRO,
}

class KeyplusLayout(object):
    def __init__(self):
        self.settings = {}
        self.devices = []
        self.layouts = []
        self.rf_settings = None

    def _from_file_common(self, layout_file, rf_file=None, print_warnings=False,
                           load_method=yaml.load):
        basename = os.path.basename(layout_file)
        with open(layout_file) as f:
            layout_json_obj = load_method(f.read())
        parser_info = KeyplusParserInfo(
            "<{}>".format(basename),
            layout_json_obj,
            print_warnings = print_warnings,
        )
        if rf_file:
            rf_basename = os.path.basename(rf_file)
            with open(rf_file) as f:
                rf_json_obj = load_method(f.read())
            rf_parser_info = KeyplusParserInfo(
                "<{}>".format(rf_basename),
                rf_json_obj,
                print_warnings = print_warnings,
            )
        else:
            rf_parser_info = None

        return self.parse_json(
            parser_info =  parser_info,
            rf_parser_info = rf_parser_info,
        )

    def from_json_file(self, layout_file, rf_file=None, print_warnings=False):
        return self._from_file_common(
            layout_file,
            rf_file,
            print_warnings,
            json.loads,
        )

    def from_yaml_file(self, layout_file, rf_file=None, print_warnings=False):
        return self._from_file_common(
            layout_file,
            rf_file,
            print_warnings,
            yaml.load,
        )

    def _parse_devices(self, parser_info):
        parser_info.enter("devices")
        devices = []
        for field in parser_info.iter_fields():
            device = LayoutDevice()
            device.parse_json(
                device_name = field,
                parser_info = parser_info
            )
            devices.append(device)
        self.devices = devices
        parser_info.exit()

    def _parse_layouts(self, parser_info):
        parser_info.enter("layouts")
        layouts = []
        for field in parser_info.iter_fields():
            layout = LayoutKeyboard(field)
            layout.parse_json(
                layout_id = field,
                parser_info = parser_info
            )
            layouts.append(layout)
        self.layouts = layouts
        parser_info.exit()

    def parse_json(self, layout_json=None, rf_json=None, parser_info=None, rf_parser_info=None):
        if parser_info == None:
            assert(layout_json != None)
            parser_info = KeyplusParserInfo(
                "<KeyplusLayout(layout)>",
                layout_json,
                print_warnings = True
            )
        if not rf_parser_info and rf_json:
            rf_parser_info = KeyplusParserInfo(
                "<KeyplusLayout(rf)>",
                rf_json,
                print_warnings = True
            )

        self.settings["name"] = parser_info.try_get(
            field = "name",
            field_type = str,
            default = "Keyplus Layout",
        )

        self.settings["version"] = parser_info.try_get(
            field = "version",
            field_type = str,
            optional = True
        )

        self.settings["report_mode"] = parser_info.try_get(
            field = "report_mode",
            field_type = str,
            default = KEYBOARD_REPORT_MODE_AUTO,
            remap_table = REPORT_MODE_MAP,
        )

        self._parse_devices(parser_info)
        self._parse_layouts(parser_info)

        if rf_parser_info:
            self.rf_settings = LayoutRFSettings()
            self.rf_settings.parse_json(rf_json, rf_parser_info)

        if DEBUG.parsing_extra:
            for device in self.devices:
                print("LayoutDevice({})".format(device.name))
                print(device.to_json())
                print()
            for layout in self.layouts:
                print("LayoutKeyboard({})".format(layout.layout_id))
                print(layout.to_json())
                print()
            if self.rf_settings:
                print("LayoutRFSettings({})".format(rf_parser_info.current_field))
                print(self.rf_settings.to_json())
                print()


class Layout:
    def check_layers(self, layout, debug_hint, layout_id):
        # check all layers have the same number of keyboards and all
        # keyboards have the same number of keys
        for (l_i, layer) in enumerate(self.layers):
            if len(layer) != self.layer_count:
                raise ParseError("'{}' has a mismatched number of keyboards "
                    "in its layers starting at layer '{}'".format(debug_hint, l_i))
            for (kb_i, kb) in enumerate(layer):
                if len(kb) != self.sub_matrix_sizes[kb_i]:
                    raise ParseError("'{}' has a mismatched number of keys "
                        "starting at keyboard '{}' of layer '{}'".format(debug_hint, kb_i, l_i))
