#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import struct
import math
import six

import keyplus.cdata_types
from keyplus.utility import crc16_bytes
from keyplus.constants import *
from keyplus.exceptions import *
from keyplus.io_map.io_mapper import get_io_mapper_for_chip

class KeyboardPinMapping(object):
    def __init__(self):
        self.mode = MATRIX_SCANNER_MODE_NO_MATRIX
        self.internal_scan_method = MATRIX_SCANNER_INTERNAL_NONE
        self.max_rows = None
        self.row_pins = None
        self.column_pins = None
        self.key_number_map = None
        self.io_mapper = None

        assert( not (
            (self.internal_scan_method == MATRIX_SCANNER_INTERNAL_BASIC_SCAN) \
            and (self.mode == MATRIX_SCANNER_MODE_ROW_COL) \
        ))

    def _pin_map_to_bytes(self):
        result = bytearray(0)

        assert_less_eq(len(self.row_pins), self.max_rows+1)
        row_pin_padding = self.max_rows - len(self.row_pins)
        result += bytearray(self.row_pins) + bytearray([0]*row_pin_padding)

        col_pin_padding = self.io_mapper.get_gpio_count() - len(self.column_pins)
        result += bytearray(self.column_pins) + bytearray([0]*col_pin_padding)
        result += bytearray(self.key_number_map)

        # Check that the resulting object has the correct size
        row_size = max(self.column_pins) + 1
        total_size = (
            self.max_rows +
            self.io_mapper.get_gpio_count() +
            len(self.row_pins) * row_size
        )
        assert_equal(len(result), total_size)

        return result

    def to_bytes(self):
        result = bytearray(0)

        if self.internal_scan_method == MATRIX_SCANNER_INTERNAL_NONE:
            pass
        elif self.internal_scan_method == MATRIX_SCANNER_INTERNAL_FAST_ROW_COL:
            # NOTE: This should work for both the matrix and direct wiring
            # pin scanning modes, since the pin mode emulates matrix scanning
            # with one row.
            result += self._pin_map_to_bytes();
        elif self.internal_scan_method == MATRIX_SCANNER_INTERNAL_BASIC_SCAN:
            if self.mode == MATRIX_SCANNER_MODE_PIN_VCC:
                raise KeyplusSettingsError(
                    "The target device can't support the `pin_vcc` scan method. "
                    "Using the BASIC_SCAN method it can only support: "
                    "`pin_gnd`, `col_row` and `row_col`."
                )
            result += self._pin_map_to_bytes();
        else:
            raise KeyplusSettingsError(
                "Unknown internal scan method '{}'".format(self.internal_scan_method)
            )

        return result

    def unpack(self, raw_data, scan_plan, device_target):
        self.internal_scan_method = device_target.firmware_info.internal_scan_method
        self.mode = scan_plan.mode
        io_mapper = device_target.get_io_mapper()
        self.io_mapper = io_mapper

        if self.internal_scan_method == MATRIX_SCANNER_INTERNAL_NONE:
            pass
        elif self.internal_scan_method == MATRIX_SCANNER_INTERNAL_FAST_ROW_COL:
            # row_data
            pos = 0
            row_size = self.scanner
            row_data = raw_data[:row_size]
            pos += row_size
            # column_data
            column_storage_size = io_mapper.get_gpio_count()
            column_data = raw_data[pos:pos+column_storage_size]
            pos += column_storage_size
            # matrix_map_data
            map_size = (scan_plan.max_col_pin_num+1) * scan_plan.rows
            matrix_map_data = raw_data[pos:pos+map_size]

            self.row_pins = list(row_data[:scan_plan.rows])
            self.column_pins = list(column_data[:scan_plan.cols])
            self.key_number_map = matrix_map_data
        elif self.internal_scan_method == MATRIX_SCANNER_INTERNAL_BASIC_SCAN:
            raise KeyplusSettingsError("Unimplemented: decoding BASIC_SCAN")
        else:
            raise KeyplusSettingsError(
                "Unknown internal scan method '{}'".format(self.internal_scan_method)
            )


class KeyboardDeviceTarget(object):
    """
    To correctly generate the layout settings, it is necessary to know what
    device is being targeted. This class stores the necessary information
    needed to instruct the settings generation commands for a specific device
    type.
    """
    def __init__(self, device_id, firmware_info):
        self.device_id = device_id
        if firmware_info == None:
            self.firmware_info = keyplus.cdata_types.firmware_info_t()
        else:
            self.firmware_info = firmware_info

        self.io_mapper = get_io_mapper_for_chip(self.firmware_info.chip_id)

    def get_io_mapper(self):
        return self.io_mapper


class KeyboardSettingsInfo(keyplus.cdata_types.settings_header_t):
    def has_valid_crc(self):
        return self.crc == self.compute_crc()

    def compute_crc(self):
        bytes_ = bytearray(self.to_bytes())[:-2]
        return crc16_bytes(bytes_)

    def is_empty(self):
        # check if the flash has been initialized
        return sum([1 for byte in self.to_bytes() if byte != 0xff]) == 0

    @property
    def timestamp_raw(self):
        return struct.unpack("<Q", bytearray(self.timestamp))[0]

    @timestamp_raw.setter
    def timestamp_raw(self, value):
        bytes_ = struct.pack("<Q", value)
        if six.PY2:
            self.timestamp = [ord(c) for c in bytes_]
        elif six.PY3:
            self.timestamp = [int(c) for c in bytes_]


    def get_name_str(self):
        if self.is_empty():
            return ""
        else:
            try:
                result = self.device_name.strip(b'\x00').decode('utf-8')
            except UnicodeDecodeError:
                result = str(self.device_name)
            return result

    def get_default_report_mode_str(self):
        return report_mode_to_str(self.default_report_mode)

    def get_scan_mode_str(self):
        return scan_mode_to_str(self.scan_plan.mode)

class KeyboardLayoutInfo(keyplus.cdata_types.layout_settings_t):
    def __init__(self):
        super(KeyboardLayoutInfo, self).__init__()
        self.has_built_lookup_table = False

    def get_device_info(self, device_id):
        return self.devices[device_id]

    def _build_lookup_table(self):
        self.lookup_table = {}
        # Build a lookup table that maps layout_id to a list of devices that
        # use that layout
        for (dev_id, device) in enumerate(self.devices):
            if device.layout_id >= MAX_NUMBER_LAYOUTS:
                # Ignore devices that have an invalid/no_matrix layout.
                continue

            if device.layout_id not in self.lookup_table:
                self.lookup_table[device.layout_id] = [device]
            else:
                self.lookup_table[device.layout_id].append(device)

        # Sort each device list by its matrix offset (smallest first)
        # If their sizes match, sort by matrix_size (largest first)
        for layout_id in self.lookup_table:
            self.lookup_table[layout_id].sort(
                key = lambda x: x.matrix_offset * 256 - x.matrix_size
            )

        self.has_built_lookup_table = True

    def get_layout_size(self, layout_id):
        devices = self.get_devices_in_layout(layout_id)
        layout = self.layouts[layout_id]

        matrix_size = 0

        for device in devices:
            matrix_size += int(math.ceil(device.matrix_size/8))

        if matrix_size > MAX_MATRIX_SIZE:
            raise KeyplusParseError("Too many keys in layout '{}'".format(layout_id))

        matrix_size *= layout.layer_count * 2

        return matrix_size

    def get_layout_device_sizes(self, layout_id):
        devices = self.get_devices_in_layout(layout_id)
        # TODO: need to change the layout storage format to use key numbers
        # not byte numers.

        # NOTE: The devices in the list returned by get_devices_in_layout()
        # is sorted by their matrix_offset
        offset_pos = devices[0].matrix_offset + devices[0].matrix_size*2*8
        offset_list = [(0, offset_pos)]
        for device in devices:
            this_offset_pos = device.matrix_offset*2*8
            if this_offset_pos > offset_pos:
                raise KeyplusSettingsError(
                    "Unexpected overlap in matrix_sizes: {}".format(devices)
                )
            if this_offset_pos < offset_pos:
                continue
            size = device.matrix_size*8*2
            offset_list.append((offset_pos, size))
            offset_pos += size

        return offset_list



    def get_devices_in_layout(self, layout_id):
        """ For a given `layout_id`, find all the devices using that layout """
        if not self.has_built_lookup_table:
            self._build_lookup_table()

        if layout_id not in self.lookup_table:
            return None
        else:
            return self.lookup_table[layout_id]

    def get_split_device_number(self, device_id):
        """
        Given a `device_id`, find this devices realtive position in the
        layout
        """
        device_info = self.devices[device_id]
        if device_info.layout_id == LAYOUT_ID_NONE:
            return None
        assert(device_info.layout_id < MAX_NUMBER_LAYOUTS)
        devices = self.get_devices_in_layout(device_info.layout_id)
        offsets = sorted(list(set([dev.matrix_offset for dev in devices])))
        return offsets.index(device_info.matrix_offset)



class KeyboardRFInfo(keyplus.cdata_types.rf_settings_t):
    pass

class KeyboardFirmwareInfo(keyplus.cdata_types.firmware_info_t):
    @property
    def timestamp_raw(self):
        return struct.unpack("<Q", bytearray(self.timestamp))[0]

    @timestamp_raw.setter
    def timestamp_raw(self, value):
        self.timestamp = struct.to_bytes("<Q", value)

    def get_interal_scan_method(self):
        return self.internal_scan_method

    def get_interal_scan_method_as_str(self):
        return self.internal_scan_method_to_str(self.internal_scan_method)

    def set_internal_scan_method(self, new_value):
        if isinstance(new_value, six.string_types):
            self.internal_scan_method = self.internal_scan_method_from_str(new_value)
        elif isinstance(new_value, int):
            self.internal_scan_method = new_value
        else:
            raise TypeError("Expected a string or integer for scan_method")

    def set_max_rows(self, new_value):
        try:
            self.max_rows = int(new_value)
        except:
            raise TypeError("Expected an integer for max_rows")

    def internal_scan_method_from_str(self, scan_method):
        if scan_method in INTERNAL_SCAN_METHOD_NAME_TABLE:
            return INTERNAL_SCAN_METHOD_NAME_TABLE[scan_method]
        else:
            raise KeyplusSettingsError(
                "Unknown internal scan method: {}".format(scan_method)
            )

    def internal_scan_method_to_str(self, method):
        assert_equal(type(method), int)
        if method in INTERNAL_SCAN_METHOD_TABLE:
            return INTERNAL_SCAN_METHOD_TABLE[method]
        else:
            return "UnknownInternalScanMethod({})".format(method)


    def has_at_least_version(self, version_str):
        (major, minor, patch) = [int(x) for x in version_str.split('.')]

        return \
            self.version_major > major or (
                self.version_major == major and
                self.version_minor >  minor
            ) or (
                self.version_major == major and
                self.version_minor == minor and
                self.version_patch >= patch
            )
