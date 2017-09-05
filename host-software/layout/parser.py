#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import yaml
import struct
import hexdump
import math
import re
import time
import os

import layout.mapped_keycodes as mapped_keycodes

from layout.common import *

from layout.scan_mode import *
from layout.rf_settings import *
from layout.device import *
from layout.ekc_data import EKCDataMain

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
            raise ParseError("Expected at least one keyboard for layers in {}".format(layout_name))

        # number of keys in keyboards
        try:
            self.sub_matrix_sizes = [len(kb) for kb in self.layers[0]]
        except:
            raise ParseError("Couldn't get keyboard sizes {}".format(layout_name))

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

class SettingsGenerator:
    def __init__(self, layout_data, rf_settings):
        self.layout = layout_data
        self.rf = rf_settings
        self.ekc_data = EKCDataMain()

        self.build_device_data()

    def gen_single_layout(self, layout):
        result = bytearray(0)
        for layer in layout.layers:
            for (kb_i, kb) in enumerate(layer):
                kc_map = None
                size = 0

                # # Check for 'matrix_maps'. It is a list of device names with
                # # one for each sub-matrix in the layout. The matrix_map is
                # # used to map the keys from how they are "visually arranged" to
                # # to how they are physically wired.
                # # The matrix_maps is optional. If it is not given, then the
                # # list of keys in the matrix will match how they are physically
                # # wired.
                # if layout.matrix_maps != None:
                #     map_name = layout.matrix_maps[kb_i]
                #     try:
                #         map_device = self.get_device_by_name(map_name)
                #         kc_map = map_device.scan_mode.matrix_map
                #         sm = map_device.scan_mode
                #         size = sm.rows * sm.cols
                #         size = int(math.ceil(len(kb)/8))*8 # pad to multiple of 8
                #     except:
                #         raise ParseError("Couldn't find matrix_map for '{}' in"
                #                 " layout '{}'".format(map_name, layout.name))

                #     if len(kc_map) != len(kb):
                #         raise ParseError("The matrix_map for '{}' has '{}' "
                #             "keys, but the corresponding matrix in the layout "
                #             "'{}' has '{}' keys".format(
                #                 map_name, len(kc_map),
                #                 layout.name, len(kb)))
                # else:
                #     # no map given, so generate a list that is a 1-to-1 mapping
                #     kc_map = list(range(len(kb)))
                #     size = int(math.ceil(len(kb)/8))*8 # pad to multiple of 8

                size = int(math.ceil(len(kb)/8))*8 # pad to multiple of 8
                keycodes = [0] * size

                for (kc_i, kc_str) in enumerate(kb):
                    kc = mapped_keycodes.interpret_keycode(kc_str)
                    keycodes[kc_i] = kc

                # pack all the keycodes as uint16_t
                for kc in keycodes:
                    result += struct.pack('<H', kc)
        return result

    def gen_layout_section(self, dev_id):
        # Layout section has the format
        # matrix_keynumber_map for this specific device[rows * cols]
        # layouts for all devices

        self.build_device_data()

        result = bytearray(0)

        dev_data = self.get_device_by_id(dev_id)

        if dev_data.scan_mode.mode != ScanMode.NO_MATRIX:
            # Add matrix map to the layout section
            for key_num in dev_data.scan_mode.matrix_map:
                result += struct.pack('<B', key_num)

            # # Align to two byte boundary
            # if len(dev_data.scan_mode.matrix_map) % 2 != 0:
            #     result += struct.pack('<B', 0)

        # Add ekc data to the layout section
        result += self.ekc_data.to_bytes()


        for layout_id in range(self.number_layouts):
            layout = self.get_layout_by_id(layout_id)
            result += self.gen_single_layout(layout)

        return result

    def gen_all_settings(self, device_id):
        result = bytearray(0);
        result += self.gen_global_settings(device_id)
        result += self.gen_rf_settings()
        result += self.gen_layout_settings()
        return result

    def gen_global_settings(self, device_id):
        # uint8_t device_id;
        # char device_name[32];
        # uint8_t timestamp[8]; // utc time stamp of last update
        # uint8_t default_report_mode;
        # uint8_t scan_mode;
        # uint8_t row_count;
        # uint8_t col_count;
        # uint8_t _reserved[51]; // total size == 96
        result = bytearray(0)

        device = self.get_device_by_id(device_id)

        # device_id
        result += struct.pack('<B', device.id)

        # device_id
        result += struct.pack('<32s', device.name.encode('utf-8'))

        # build timestamp, 64 bit UTC
        result += struct.pack('<q', int(time.time()) )

        # default_report_mode
        result += struct.pack('<B', self.get_report_mode())

        # scan mode information
        result += self.gen_scan_mode_info(device_id)

        result += bytearray(51)
        return result


    def parse_layouts(self):
        self.layout_data = {}
        layout_id = 0
        for (layout_name, layout) in try_get(self.layout, 'layouts').items():
            self.layout_data[layout_name] = Layout(layout, layout_id, layout_name)
            layout_id += 1
        self.number_layouts = layout_id

    def get_layout_by_id(self, layout_id):
        for (_, layout) in self.layout_data.items():
            if layout.id == layout_id:
                return layout
        raise IndexError("Couldn't find layout with id: {}".format(layout_id))

    def get_layout_by_name(self, layout_name):
        if layout_name in self.layout_data:
            return self.layout_data[layout_name]
        raise KeyError("Couldn't find layout with name: {}".format(layout_name))

    def get_device_by_name(self, device_name):
        if device_name in self.device_name_map:
            dev_id = self.device_name_map[device_name]
            return self.device_data[dev_id]
        else:
            raise KeyError("Couldn't find device named: {}".format(device_name))

    def get_device_by_id(self, dev_id):
        if dev_id in self.device_data:
            return self.device_data[dev_id]
        else:
            raise IndexError("Couldn't find device with id: {}".format(dev_id))

    def parse_devices(self):
        self.device_data = {}
        self.device_name_map = {}
        self.largest_device_id = 0

        for (device_name, device_data) in try_get(self.layout, 'devices').items():
            dev = Device.from_json_obj(device_data, device_name)

            self.assert_validate_device(dev)

            self.device_data[dev.id] = dev
            self.device_name_map[device_name] = dev.id
            self.largest_device_id = max(self.largest_device_id, dev.id)

    def assert_validate_device(self, dev):
        if dev.scan_mode.mode == ScanMode.NO_MATRIX:
            return

        if not dev.id < MAX_DEVICE_ID:
            raise ParseError("Device id '{}' too large. Max allowed value is {}"
                             .format(dev.id, MAX_DEVICE_ID))

        # check layout identifier
        if not dev.layout_name in self.layout_data:
            raise ParseError("Couldn't find layout with name '{}' for "
                "keyboard '{}'".format(dev.layout_name, device_name))
        if (dev.id in self.device_data):
            raise ParseError("Duplicate device id '{}' used in both "
                    "'{}' and '{}'".format(dev.id, device_name, self.device_data[dev.id]['name']))

        # check layout offset
        offset_max = self.layout_data[dev.layout_name].keyboard_count
        if not dev.layout_offset < offset_max:
            raise ParseError("'layout_offset' too large. Got '{}' but "
                "'{}' only has {} device in its layout".format(dev.layout_offset, dev.layout_name, offset_max))


    def build_device_data(self):
        self.parse_layouts()
        self.parse_devices()


    def gen_layout_settings(self):
        # uint8_t number_layouts;
        # uint8_t number_devices;
        # uint8_t _reserved[30]; // 32
        # keyboard_info_t layouts[64];
        # device_info_t devices[64];

        result = bytearray(0)

        result += struct.pack('<B', self.number_layouts)
        result += struct.pack('<B', self.largest_device_id)
        result += bytearray(30)

        # layout_info_t {
        #   uint8_t matrix_size;
        #   uint8_t layer_count;
        # }[64]
        for layout_id in range(MAX_LAYOUT_ID):
            if layout_id >= self.number_layouts:
                result += bytearray(2)
                continue
            layout = self.get_layout_by_id(layout_id)
            layout_name = layout.name

            # calculate how many bytes are needed for the matrix.
            # each keyboard in the layout needs ceil(kb_size/8)

            result += struct.pack('<B', layout.matrix_size)
            result += struct.pack('<B', layout.layer_count)

        # typedef struct device_info_t {
        #     uint8_t keyboard_id; // the keyboard layout that this device maps to
        #     uint8_t matrix_offset; // the component byte offset into the given keyboard
        #     uint8_t matrix_size; // the size of this component == ceil(rows*cols/8)
        # } [64]
        for device_id in range(MAX_DEVICE_ID):
            if not device_id in self.device_data or \
                    self.device_data[device_id].scan_mode.mode == ScanMode.NO_MATRIX:
                result += bytearray(3)
                continue
            device = self.device_data[device_id]

            layout = self.layout_data[device.layout_name]
            layout_id = layout.id

            # TODO: validate this value
            matrix_size = device.scan_mode.calc_matrix_size()

            keyboard_offset = device.layout_offset
            matrix_offset = 0
            for (i, size) in enumerate(layout.sub_matrix_sizes):
                if not i < keyboard_offset:
                    break;
                matrix_offset += int(math.ceil(size / 8))

            if matrix_offset + matrix_size > layout.matrix_size:
                raise ParseError("The matrix for device '{}' doesn't fit in "
                        "layout '{}'".format(device.name, layout.name))

            result += struct.pack('<B', layout_id)
            result += struct.pack('<B', matrix_offset)
            result += struct.pack('<B', matrix_size)
        return result

    def gen_rf_settings(self):
        rf_settings = RFSettings.from_json_obj(self.rf)

        return rf_settings.to_bytes()

    def get_report_mode(self):
        mode = try_get(self.layout, 'report_mode')
        # KEYBOARD_REPORT_MODE_AUTO = 0, // 6kro -> nkro if more than 6 keys pressed
        # KEYBOARD_REPORT_MODE_NKRO = 1, // nkro
        # KEYBOARD_REPORT_MODE_6KRO = 2, // 6kro
        if mode == "auto_nkro":
            return KEYBOARD_REPORT_MODE_AUTO
        elif mode == "6kro":
            return KEYBOARD_REPORT_MODE_6KRO
        elif mode == "nkro":
            return KEYBOARD_REPORT_MODE_NKRO
        else:
            raise ParseError("Unknown report mode {}".format(mode))

    def get_scan_mode(self, device_id):
        for (kb_name, kb) in try_get(self.layout, 'devices').items():
            if (try_get(kb, 'id', kb_name) == device_id):
                return try_get(kb, 'scan_mode', kb_name)
        raise ParseError("No device defined for id={}".format(device_id))

    def gen_scan_mode_info(self, device_id):
        scan_mode = self.get_scan_mode(device_id)
        mode = try_get(scan_mode, 'mode', 'scan_mode')

        if mode == 'none' or mode == 'no_matrix':
            return struct.pack('<BBB', MATRIX_SCANNER_MODE_NONE, 0, 0)
        elif mode == 'col_row':
            rows = try_get(scan_mode, 'rows', 'scan_mode')
            cols = try_get(scan_mode, 'cols', 'scan_mode')
            return struct.pack('<BBB', MATRIX_SCANNER_MODE_COL_ROW, rows, cols)
        elif mode == 'pins':
            # count = scan_mode['pin_count']
            # return struct.pack('<BBB', MATRIX_SCANNER_MODE_PINS, count, 0)
            raise ParseError("TODO: 'pins' scan mode not implemented yet")
        else:
            raise ParseError("Unsupported scan mode {}".format(mode))


if __name__ == "__main__":
    layout = None
    rf = None

    with open("test_layout.yaml") as file_name:
        layout = yaml.safe_load(file_name.read())
    with open("test_rf_config.yaml") as file_name:
        rf = yaml.safe_load(file_name.read())

    settings = SettingsGenerator(layout_data=layout, rf_settings=rf)

    target_layout_id = 0x30

    print("settings:")
    try:
        hexdump.hexdump(bytes(settings.gen_all_settings(target_layout_id)))
    except ParseError as e:
        print(e)
        # print(e.with_traceback())
        exit(1)

    print("layout:")
    try:
        hexdump.hexdump(bytes(settings.gen_layout_section(target_layout_id)))
    except ParseError as e:
        print(e)
        exit(1)

    print()
    print()
    settings = RFSettings.from_rand()
    print(settings.to_json_obj())
    print(settings.to_yaml())
    hexdump.hexdump(settings.to_bytes())
