#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals
from builtins import int

import json
import ruamel.yaml as yaml
import os
import io
import six
import time
import copy
import math

from keyplus.layout.parser_info import KeyplusParserInfo
from keyplus.layout.device import LayoutDevice
from keyplus.layout.keyboard_layout import *
from keyplus.layout.rf_settings import *
from keyplus.layout.ekc_data import *
from keyplus.layout.user_keycodes import UserKeycodes
from keyplus.keycodes.keycode_mapper import KeycodeMapper
from keyplus.cdata_types import rf_settings_t, settings_t
from keyplus.device_info import KeyboardLayoutInfo
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
        self.rf_settings = None

        self._devices = {}
        self._layouts = {}
        self._layout_id_map = {}

        self.user_keycodes = UserKeycodes()
        self.ekc_data = EKCDataTable()

        self.kc_mapper = KeycodeMapper()
        self.kc_mapper.set_user_keycodes(self.user_keycodes)


    def _from_file_common(self, layout_file=None, rf_file=None, print_warnings=False,
                           load_method=yaml.safe_load, warnings=None):
        basename = os.path.basename(layout_file)
        if layout_file:
            with io.open(layout_file, encoding='utf8') as f:
                layout_json_obj = load_method(f.read())
            parser_info = KeyplusParserInfo(
                "<{}>".format(basename),
                layout_json_obj,
                print_warnings = print_warnings,
            )
        else:
            parser_info = None

        if rf_file:
            rf_basename = os.path.basename(rf_file)
            with io.open(rf_file, encoding='utf8') as f:
                rf_json_obj = load_method(f.read())
            rf_parser_info = KeyplusParserInfo(
                "<{}>".format(rf_basename),
                rf_json_obj,
                print_warnings = print_warnings,
            )
        else:
            rf_parser_info = None

        result = self.parse_json(
            parser_info =  parser_info,
            rf_parser_info = rf_parser_info,
        )

        if warnings != None:
            # print(warnings, parser_info.warnings, rf_parser_info.warnings)
            if parser_info != None:
                warnings.extend(parser_info.warnings)
            if rf_parser_info != None:
                warnings.extend(rf_parser_info.warnings)

        return result

    def from_json_file(self, layout_file=None, rf_file=None,
                       print_warnings=False, warnings=None):
        return self._from_file_common(
            layout_file,
            rf_file,
            print_warnings,
            json.loads,
            warnings,
        )

    def from_yaml_file(self, layout_file=None, rf_file=None,
                       print_warnings=False, warnings=None):
        return self._from_file_common(
            layout_file,
            rf_file,
            print_warnings,
            yaml.safe_load,
            warnings,
        )

    def add_device(self, device):
        dev_id = device.device_id
        if dev_id in self._devices:
            raise KeyplusSettingsError(
                "Failed to add device '{}' because the device '{}' "
                "is already using the device id '{}'."
                .format(
                    device.name,
                    self._devices[dev_id].name,
                    dev_id
                )
            )
        else:
            self._devices[dev_id] = device

    def del_device(self, device):
        dev_id = device.device_id
        if dev_id in self._devices:
            del self._devices[dev_id]
        else:
            raise KeyplusError(
                "Tried to delete non-existent device '{}' with id '{}'."
                .format(device.name, layout_id)
            )

    def get_layout_by_id(self, layout_id):
        return self._layouts[layout_id]

    def get_layout_by_name(self, name):
        layout_id = self._layout_id_map[name]
        return self._layouts[layout_id]

    def add_layout(self, layout):
        layout_id = layout.layout_id
        if layout_id in self._layouts:
            raise KeyplusSettingsError(
                "Failed to add layout '{}' because the layout '{}' has the "
                "same name"
                .format(
                    layout.name,
                    self._devices[layout_id].name,
                )
            )
        else:
            self._layouts[layout_id] = layout
            if layout.name != None:
                self._layout_id_map[layout.name] = layout_id

    def del_layout(self, layout):
        layout_id = device.layout_id
        if layout_id in self._layouts:
            del self._layouts[layout_id]
            if layout.name != None:
                del self._layout_id_map[layout.name]
        else:
            raise KeyplusError(
                "Tried to delete non-existent layout '{}'."
                .format(layout_id)
            )

    def _parse_devices(self, parser_info):
        parser_info.enter("devices")
        for field in parser_info.iter_fields():
            device = LayoutDevice()
            device.parse_json(
                device_name = field,
                parser_info = parser_info
            )
            self.add_device(device)
        parser_info.exit()

    def _parse_keycodes(self, parser_info):
        if not parser_info.has_field('keycodes'):
            return
        self.user_keycodes.parse_json(parser_info = parser_info)
        self.ekc_data = self.user_keycodes.generate_ekc_data()

    def _parse_layouts(self, parser_info):
        parser_info.enter("layouts")
        for (layout_num, field) in enumerate(parser_info.iter_fields()):
            layout = LayoutKeyboard(field)
            layout.set_keycode_mapper(self.kc_mapper)

            layout.parse_json(
                name = field,
                parser_info = parser_info
            )
            if layout.layout_id == None:
                layout.layout_id = layout_num
            self.add_layout(layout)
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
            field_type = [str, int],
            optional = True
        )

        self.settings["default_report_mode"] = parser_info.try_get(
            field = "default_report_mode",
            field_type = str,
            default = KEYBOARD_REPORT_MODE_AUTO,
            remap_table = REPORT_MODE_MAP,
        )

        self._parse_devices(parser_info)
        self._parse_keycodes(parser_info)
        self._parse_layouts(parser_info)

        for dev in six.itervalues(self._devices):
            if dev.scan_mode.mode == MATRIX_SCANNER_MODE_NO_MATRIX:
                continue

            layout = self.get_layout_by_name(dev.layout)
            dev_sizes = layout.layer_list[0].device_sizes

            if dev.split_device_num >= len(dev_sizes):
                raise KeyplusParseError(
                    "Layout doesn't have the given split device number. The "
                    "device \"{}\" maps to split device {}, but "
                    "the layout \"{}\" only has {} split devices."
                    .format(
                        dev.name,
                        dev.split_device_num,
                        layout.name,
                        len(dev_sizes),
                    )
                )
            layout_size = dev_sizes[dev.split_device_num]

            if dev.scan_mode.number_mapped_keys != layout_size:
                raise KeyplusParseError(
                    "Layout size doesn't match device matrix_map size. The "
                    "device \"{}\" has a matrix map of length {}, but "
                    "the layout \"{}\" has length {} for split device {}."
                    .format(
                        dev.name,
                        dev.scan_mode.number_mapped_keys,
                        layout.name,
                        layout_size,
                        dev.split_device_num
                    )
                )

        if rf_parser_info:
            self.rf_settings = LayoutRFSettings()
            self.rf_settings.parse_json(rf_json, rf_parser_info)

        if DEBUG.parsing_extra:
            for device in six.itervalues(self._devices):
                print("LayoutDevice({})".format(device.name))
                print(device.to_json())
                print()
            for layout in six.itervalues(self._layouts):
                print("LayoutKeyboard({}, {})".format(layout.layout_id, layout.name))
                print(layout.to_json())
                print()
            if self.rf_settings and rf_parser_info:
                print("LayoutRFSettings({})".format(rf_parser_info.current_field))
                print(self.rf_settings.to_json())
                print()

    def pack_settings_data(self, device_target):
        pass

    def _build_layouts(self):
        result = bytearray()
        num_layouts = len(self._layouts)

        for layout_id in range(num_layouts):
            if layout_id not in self._layouts:
                raise KeyplusSettingsError(
                    "Layout ids cannot skip values. TODO(remove this requirement)"
                )
            result += self._layouts[layout_id].to_bytes()
        return result

    @property
    def number_layouts(self):
        return len(self._layouts)

    @property
    def number_devices(self):
        return len(self._devices)

    def build_layout_settings(self):
    # uint8_t number_layouts;
    # uint8_t number_devices;
    # uint8_t _reserved[30]; // 32
    # keyboard_info_t layouts[MAX_NUM_KEYBOARDS];
    # device_info_t devices[MAX_NUM_DEVICES];
        layout_info = KeyboardLayoutInfo()
        layout_info.number_layouts = self.number_layouts
        layout_info.number_devices = max(self._devices)

        # struct keyboard_info_t layouts[MAX_NUM_KEYBOARDS];

        # Build the layout table
        # The layout table holds precomputed values for layout sizes
        # and their number of layers
        for layout_id in self._layouts:
            layout = self._layouts[layout_id]
            layer = layout.layer_list[0]

            size = 0
            for (split_device_number, _) in enumerate(layer.device_list):
                size += layer.get_layout_component_size(split_device_number)
            layout_info.layouts[layout_id].matrix_size = size
            layout_info.layouts[layout_id].layer_count = layout.number_layers

        # Build the device map, need to store:
        # * layout_id: the layout this device maps to
        # * matrix_offset: the offset of this device into the layout with the
        #   given id
        # * matrix_size:
        # NOTE: matrix_offset and matrix_size are given in bytes, i.e.
        # ceil(num_keys/8)
        for device_id in range(MAX_NUMBER_DEVICES):
            dev = layout_info.devices[device_id]
            if device_id in self._devices:
                this_dev = self._devices[device_id]
                if this_dev.scan_mode.mode == MATRIX_SCANNER_MODE_NO_MATRIX:
                    dev.layout_id = LAYOUT_ID_NONE
                else:
                    if this_dev.layout in self._layout_id_map:
                        dev.layout_id = self._layout_id_map[this_dev.layout]
                        target_layout = self._layouts[dev.layout_id]
                        target_layer = target_layout.layer_list[0]
                        dev.matrix_offset = target_layer.get_layout_component_offset(this_dev.split_device_num)
                        # TODO: Change this to a key number
                        dev.matrix_size = target_layer.get_layout_component_size(this_dev.split_device_num)
                    else:
                        raise KeyplusSettingsError(
                            "Device '{}' is set to use layout '{}', but that "
                            "layout does not exist."
                            .format(this_dev.name, this_dev.layout)
                        )
                    # dev.layout_id =
                    pass
            else:
                dev.layout_id = LAYOUT_ID_INVALID

        return layout_info

    def get_device(self, dev_id):
        if dev_id not in self._devices:
            raise KeyplusSettingsError(
                "Couldn't find any device in the layout with device id {}"
                .format(dev_id)
            )
        return self._devices[dev_id]

    def build_settings_section(self, device_target):
        device = self.get_device(device_target.device_id)

        settings = settings_t()

        settings_header = device.build_settings_header(device_target)
        settings_header.timestamp_raw = int(time.time())
        settings_header.default_report_mode = self.settings['default_report_mode']
        settings_header.crc = settings_header.compute_crc()

        settings.header = settings_header

        settings.layout = self.build_layout_settings()

        if self.rf_settings == None:
            settings.rf = rf_settings_t()
        else:
            settings.rf = self.rf_settings.generate_rf_settings()

        return settings.to_bytes()

    def build_layout_section(self, device_target):
        device = self.get_device(device_target.device_id)
        result = bytearray()

        pin_map = device.scan_mode.generate_pin_mapping(device_target)

        result += pin_map.to_bytes()
        result += self.ekc_data.to_bytes()
        result += self._build_layouts()

        return result



class OldLayout(object):
    # TODO: add these checks back in

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
