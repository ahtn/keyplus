#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import math
import sys

from keyplus.layout.parser_info import KeyplusParserInfo
from keyplus.layout.device import LayoutDevice
from keyplus.layout.keyboard_layout import *

class KeyplusLayout(object):
    def __init__(self):
        self.settings = {}
        self.devices = []
        self.layouts = []
        self.rf_settings = None

    def from_json_file(self, layout_file, rf_file=None):
        pass

    def from_yaml_file(self, layout_file, rf_file=None):
        pass

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

    def parse_json(self, layout_json, rf_json=None, parser_info=None):
        if parser_info == None:
            parser_info = KeyplusParserInfo(
                "<KeyplusLayout>",
                layout_json,
                print_warnings = True
            )

        self._parse_devices(parser_info)
        self._parse_layouts(parser_info)


if 0:
    parser_info.enter("scan_mode")

    self.mode = parser_info.try_get("mode", field_type=str)
    self.mode = parser_info.map_to_value(self.mode, MODE_MAP)

    if self.mode == NO_MATRIX:
        return
    elif self.mode in [ROW_COL, COL_ROW]:
        self.row_pins = parser_info.try_get("rows", field_type=list)
        self.column_pins = parser_info.try_get("cols", field_type=list)
        self.parse_matrix_map(parser_info.try_get("matrix_map", field_type=list))
    elif self.mode in [PIN_GND, PIN_VCC]:
        self.direct_wiring_pins = parser_info.try_get("pins", field_type=list)
        self.parse_pin_map(parser_info.try_get("pin_map", field_type=list))

    if parser_info.has_field('debounce', field_type=str):
        debounce_profile = parser_info.try_get("debounce", field_type=str)
        self.set_debounce_profile(debounce_profile)
    elif parser_info.has_field('debounce', field_type=dict):
        parser_info.enter('debounce')

        self.set_debounce_profile('default')

        self.debounce_time_press = parser_info.try_get(
            "debounce_time_press", default=self.debounce_time_press, field_type=int,
            field_range=[0, 255]
        )

        self.debounce_time_release = parser_info.try_get(
            "debounce_time_release", default=self.debounce_time_release, field_type=int,
            field_range=[0, 255]
        )

        self.trigger_time_press = parser_info.try_get(
            "trigger_time_press", default=self.trigger_time_press, field_type=int,
            field_range=[0, 255]
        )

        self.trigger_time_release = parser_info.try_get(
            "trigger_time_release", default=self.trigger_time_release, field_type=int,
            field_range=[0, 255]
        )

        self.parasitic_discharge_delay_idle = parser_info.try_get(
            "parasitic_discharge_delay_idle",
            default=self.parasitic_discharge_delay_idle,
            field_type=[int, float],
            field_range=[0, 48.0]
        )

        self.parasitic_discharge_delay_debouncing = parser_info.try_get(
            "parasitic_discharge_delay_debouncing",
            default=self.parasitic_discharge_delay_debouncing,
            field_type=[int, float],
            field_range=[0, 48.0]
        )

        parser_info.exit()

class Layout:
    def __init__(self, layout, layout_id, layout_name):
        self.id = layout_id
        self.layers = try_get(layout, "layers", layout_name, val_type=list)
        self.sub_matrix_sizes = []
        self.name = layout_name

        # optional default layer
        if "default_layer" in layout:
            self.default_layer = try_get(layout, "default_layer", layout_name, val_type=int)
        else:
            self.default_layer = 0

        # first determine the layer structure for the keyboard
        try:
            self.layer_count = len(self.layers)
        except:
            raise ParseError("Expected at least one layer in {}".format(layout_name))

        # check for at least one keyboard
        try:
            self.keyboard_count = len(self.layers[0])
        except:
            raise ParseError("Expected at least one keyboard device in 'layers' field of {}".format(layout_name))

        # number of keys in keyboards
        try:
            self.sub_matrix_sizes = [len(kb) for kb in self.layers[0]]
        except:
            raise ParseError("Couldn't get keyboard sizes {}".format(layout_name))

        # check that all the layers have the same dimensions
        for layer_i in range(self.layer_count):
            device_count_i = len(self.layers[layer_i])
            if device_count_i != self.keyboard_count:
                raise ParseError("Unbalanced layer structure in layout '{}'. "
                    " The first layer has '{}' devices, but the {} layer has '{}' devices."
                    .format(layout_name, self.layer_count,
                            num_to_ordinal_str(layer_i+1), device_count_i)
                )
            for device_i in range(self.keyboard_count):
                expected_size = self.sub_matrix_sizes[device_i]
                actual_size = len(self.layers[layer_i][device_i])
                if actual_size != expected_size:
                    raise ParseError("Mismatching devices in layout '{}'. "
                        "The {} device has '{}' keycodes in the first layer, but "
                        "in the {} layer the same device has '{}' keycodes."
                        .format(
                            layout_name,
                            num_to_ordinal_str(device_i+1), expected_size,
                            num_to_ordinal_str(layer_i+1), actual_size
                        )
                    )

        # total matrix size of layout
        self.matrix_size = self.calc_total_matrix_size()

        # which matrix_maps are used (if any) for the layout
        if "matrix_maps" in layout:
            self.matrix_maps = try_get(layout, "matrix_maps", layout_name, val_type=list)
            if len(self.matrix_maps) != self.keyboard_count:
                raise ParseError("In layout '{}', found '{}' maps in 'matrix_maps', "
                        "but found {} devices in its 'layers' list".found(
                        self.name, len(self.matrix_maps), self.keyboard_count))
        else:
            self.matrix_maps = None

    def calc_total_matrix_size(self):
        # total size need for the key matrices in the layout
        matrix_size = 0
        for size in self.sub_matrix_sizes:
            matrix_size += int(math.ceil(size / 8))
        if matrix_size > MAX_MATRIX_SIZE:
            raise ParseError("Too many keys in layout '{}'".format(layout_name))
        return matrix_size

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

