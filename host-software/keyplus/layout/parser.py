#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import yaml
import struct
import hexdump
import re
import time
import os

import layout.mapped_keycodes as mapped_keycodes

from layout.common import *

from layout.scan_mode import ScanMode
from layout.user_keycodes import UserKeycodes
from layout.rf_settings import *
from layout.device import *
from layout.layout import Layout
from layout.ekc_data import EKCDataMain

from uniflash.crc16 import crc16_bytes

RF_INFO_SIZE = 64

class SettingsGenerator(object):
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

                size = int(math.ceil(len(kb)/8))*8 # pad to multiple of 8
                keycodes = [0] * size

                for (kc_i, kc_str) in enumerate(kb):
                    if isinstance(kc_str, int):
                        kc_str = str(kc_str)
                    if kc_str.lower() in self.user_keycodes.user_keycode_table:
                        print(kc_str, self.user_keycodes.user_keycode_table)
                        kc = self.user_keycodes.get_ekc_keycode_value(kc_str)
                        print(hex(kc))
                    else:
                        kc = mapped_keycodes.interpret_keycode(kc_str)
                    keycodes[kc_i] = kc

                # pack all the keycodes as uint16_t
                for kc in keycodes:
                    result += struct.pack('<H', kc)
        return result

    def gen_pin_mapping_section(self, dev_id):
        result = bytearray(0)

        dev_data = self.get_device_by_id(dev_id)

        # First up is the column map.
        result += dev_data.scan_mode.generate_pin_maps(None)

        print("Pin map data: ")
        hexdump.hexdump(result)
        print()

        return result

    def gen_layout_section(self, dev_id):
        # Layout section has the format
        # matrix_keynumber_map for this specific device[rows * cols]
        # layouts for all devices

        self.build_device_data()

        result = bytearray(0)


        dev_data = self.get_device_by_id(dev_id)
        if dev_data.scan_mode.mode == ScanMode.NO_MATRIX:
            pass
        # TODO: need to make layout generation take KbInfo as input
        elif dev_data.scan_mode.mode == ScanMode.COL_ROW:
            result += self.gen_pin_mapping_section(dev_id)
            result += dev_data.scan_mode.generate_key_number_map(dev_id)

        # Add ekc data to the layout section
        result += self.ekc_data.to_bytes()

        for layout_id in range(self.number_layouts):
            layout = self.get_layout_by_id(layout_id)
            result += self.gen_single_layout(layout)

        return result

    def gen_settings_section(self, device_id):
        result = bytearray(0);
        result += self.gen_global_settings(device_id)
        result += self.gen_layout_settings()
        result += self.gen_rf_settings()
        return result

    def gen_global_settings(self, device_id):
        # uint8_t device_id;
        # char device_name[32];
        # uint8_t timestamp[8]; // utc time stamp of last update
        # uint8_t default_report_mode;
        # typedef struct matrix_scan_plan_t {
        #     uint8_t mode; // scanning method
        #     uint8_t rows; // number of rows in the scan matrix
        #     uint8_t cols; // number of cols in the scan matrix
        #     uint8_t debounce_time_press; // How long to debounce a key when it is pressed (ms)
        #     uint8_t debounce_time_release; // How long to debounce a key when it is released (ms)
        #     uint8_t trigger_time_press; // The key must be down this long before being registered (ms)
        #     uint8_t trigger_time_release; // The key must be up this long before being registered (ms)

        #     // Both delays are measured on a scale of 0-48µs
        #     uint8_t parasitic_discharge_delay_idle; // How long to hold a row low before reading the columns
        #     uint8_t parasitic_discharge_delay_debouncing; // How long to hold a row low when a key is debouncing

        #     uint8_t max_col_pin_num; // maximum column pin number used
        #     uint8_t max_key_num; // highest key number used
        # } matrix_scan_plan_t;
        # uint8_t _reserved0[8];
        # uint8_t feature_ctrl;
        # uint8_t _reserved1[32];
        # uint16_t crc; // total size == 96
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

        # resreved0
        result += bytearray(8)

        # feature control information
        result += device.feature_ctrl.to_bytes()
        # result += bytearray([0xff])

        result += bytearray(32)

        result += struct.pack('<H', crc16_bytes(result))

        return result

    def parse_keycodes(self):
        self.user_keycodes = UserKeycodes([])

        if 'keycodes' not in self.layout:
            print("no user keycodes")
            return
        print("got some keycodes")

        self.user_keycodes = UserKeycodes(self.layout['keycodes'])
        ekc_data = self.user_keycodes.generate_ekc_data()
        self.ekc_data = ekc_data
        print("ekc_data:", ekc_data)

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
        raise ParseError("Couldn't find layout with id: {}".format(layout_id))

    def get_layout_by_name(self, layout_name):
        if layout_name in self.layout_data:
            return self.layout_data[layout_name]
        raise ParseError("Couldn't find layout with name: {}".format(layout_name))

    def get_device_by_name(self, device_name):
        if device_name in self.device_name_map:
            dev_id = self.device_name_map[device_name]
            return self.device_data[dev_id]
        else:
            raise ParseError("Couldn't find device named: {}".format(device_name))

    def has_id(self, dev_id):
        return dev_id in self.device_data

    def get_device_by_id(self, dev_id):
        if dev_id in self.device_data:
            return self.device_data[dev_id]
        else:
            raise ParseError("Couldn't find device with id: {}".format(dev_id))

    def parse_devices(self):
        self.device_data = {}
        self.device_name_map = {}
        self.largest_device_id = 0

        for (device_name, device_data) in try_get(self.layout, 'devices').items():
            dev = Device.from_json_obj(device_data, device_name)

            self.assert_validate_device(dev, device_name)

            self.device_data[dev.id] = dev
            self.device_name_map[device_name] = dev.id
            self.largest_device_id = max(self.largest_device_id, dev.id)

    def assert_validate_device(self, dev, device_name):
        if dev.scan_mode.mode == ScanMode.NO_MATRIX:
            return

        if not dev.id < MAX_DEVICE_ID:
            raise ParseError("Device id '{}' too large. Max allowed value is {}"
                             .format(dev.id, MAX_DEVICE_ID))

        # if not dev.id in self.device_data:
        #     raise ParseError("Tried to build layout for device id '{}', but no"
        #                      " matching device was found in the layout file."
        #                      .format(dev.id))

        # check layout identifier
        if not dev.layout_name in self.layout_data:
            raise ParseError("Couldn't find layout with name '{}' for "
                "keyboard '{}'".format(dev.layout_name, device_name))

        if (dev.id in self.device_data):
            raise ParseError("Duplicate device id '{}' used in both "
                    "'{}' and '{}'".format(dev.id, device_name, self.device_data[dev.id].name))

        # check layout offset
        offset_max = self.layout_data[dev.layout_name].keyboard_count
        if not dev.layout_offset < offset_max:
            raise ParseError("'layout_offset' too large. Got '{}' but "
                "'{}' only has {} device in its layout".format(dev.layout_offset, dev.layout_name, offset_max))

    def build_device_data(self):
        self.parse_keycodes()
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
                raise ParseError("The matrix for device '{}' (size {}) doesn't fit in "
                        "layout '{}' (size {})".format(
                            device.name, matrix_size,
                            layout.name, layout.matrix_size
                        ))

            result += struct.pack('<B', layout_id)
            result += struct.pack('<B', matrix_offset)
            result += struct.pack('<B', matrix_size)
        return result

    def gen_rf_settings(self):
        if self.rf == None:
            return bytearray([0xff] * RF_INFO_SIZE)
        else:
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

        scan_obj = ScanMode(scan_mode, device_id)

        result = scan_obj.generate_scan_mode_info()
        print("ScanModeInfo:")
        hexdump.hexdump(result)
        return result


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
        hexdump.hexdump(bytes(settings.gen_settings_section(target_layout_id)))
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
