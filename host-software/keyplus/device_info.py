#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import struct

import keyplus.cdata_types
from keyplus.utility import crc16_bytes
from keyplus.constants import *
from keyplus.exceptions import *
from keyplus.io_map.io_mapper import get_io_mapper_for_chip

def _make_bit_field_variables(class_obj, field_list):
    """
    This function uses the python built-in `property()` to create attributes
    to access the bit fields of a function directly.

    The field_list should contain a list of properties where each property is
    defined as a tuple of the form:
        (bit_mask_variable, bit_field_name, bit_field_mask)

    After this function has been called, you should be able to get and set
    the bit fields using the `bit_field_name`.
    """
    for (bit_mask_variable, attribute_name, attribute_mask) in field_list:

        # This function returns a getter function used to get a variable in
        # a bitmask
        def make_getter(bit_mask_variable, mask):
            def getter(self):
                return bool(getattr(self, bit_mask_variable) & mask)
            return getter

        # This function returns a setter function used to set a variable in
        # a bitmask
        def make_setter(bit_mask_variable, mask):
            def setter(self, value):
                # First find the new value for the bit mask variable
                new_mask_value = getattr(self, bit_mask_variable)
                if value:
                    new_mask_value |= mask
                else:
                    new_mask_value &= ~mask

                # then update the bitmask variable with this value
                setattr(
                    self,
                    bit_mask_variable,
                    new_mask_value,
                )
            return setter

        setattr(
            class_obj ,
            attribute_name,
            property(
                fget = make_getter(bit_mask_variable, attribute_mask),
                fset = make_setter(bit_mask_variable, attribute_mask),
            )
        )

class KeyboardPinMapping(object):
    def __init__(self):
        self.mode = MATRIX_SCANNER_MODE_NO_MATRIX
        self.internal_scan_method = MATRIX_SCANNER_INTERNAL_NONE
        self.row_pins = None
        self.column_pins = None
        self.key_number_map = None
        self.io_mapper = None

    def pack(self):
        result = bytearray(0)

        if self.internal_scan_method == MATRIX_SCANNER_INTERNAL_NONE:
            pass
        elif self.internal_scan_method == MATRIX_SCANNER_INTERNAL_FAST_ROW_COL:
            # NOTE: This should work for both the matrix and direct wiring
            # pin scanning modes, since the pin mode emulates matrix scanning
            # with one row.
            assert_less_than(len(self.row_pins), MAX_NUM_ROWS)
            row_pin_padding = MAX_NUM_ROWS - len(self.row_pins)
            result += bytearray(self.row_pins) + bytearray([0]*row_pin_padding)
            result += self.io_mapper.get_pin_masks_as_bytes(self.column_pins)
            result += bytearray(self.key_number_map)

            # Check that the resulting object has the correct size
            column_mask_size = self.io_mapper.get_storage_size()
            row_size = max(self.column_pins) + 1
            total_size = (
                MAX_NUM_ROWS +
                column_mask_size +
                len(self.row_pins) * row_size
            )
            assert_equal(len(result), total_size)
        elif self.internal_scan_method == MATRIX_SCANNER_INTERNAL_SLOW_ROW_COL:
            raise KeyplusSettingsError("Unimplemented internal scan method")
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
        if self.internal_scan_method == MATRIX_SCANNER_INTERNAL_FAST_ROW_COL:
            # row_data
            pos = 0
            row_size = MAX_NUM_ROWS
            row_data = raw_data[:MAX_NUM_ROWS]
            pos += MAX_NUM_ROWS
            # column_data
            column_storage_size = io_mapper.get_storage_size()
            column_data = raw_data[pos:pos+column_storage_size]
            pos += column_storage_size
            # matrix_map_data
            map_size = (scan_plan.max_col_pin_num+1) * scan_plan.rows
            matrix_map_data = raw_data[pos:pos+map_size]

            self.row_pins = row_data[:scan_plan.rows]
            self.column_pins = io_mapper.get_pins_from_mask_bytes(column_data)
            self.key_number_map = matrix_map_data
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
    def __init__(self, device_id=None, firmware_info=None):
        self.device_id = device_id
        if firmware_info == None:
            self.firmware_info = keyplus.cdata_types.firmware_info_t()
        else:
            self.firmware_info = firmware_info

    def get_io_mapper(self):
        return get_io_mapper_for_chip(self.firmware_info.chip_id)


class KeyboardSettingsInfo(keyplus.cdata_types.settings_header_t):
    def has_valid_crc(self):
        return self.crc == self.compute_crc()

    def compute_crc(self):
        return crc16_bytes(self.pack()[:-2])

    def is_empty(self):
        # check if the flash has been initialized
        return sum([1 for byte in self.pack() if byte != 0xff]) == 0

    @property
    def timestamp_raw(self):
        return struct.unpack("<Q", bytearray(self.timestamp))[0]

    @timestamp_raw.setter
    def timestamp_raw(self, value):
        self.timestamp = struct.pack("<Q", value)

    def get_name_str(self):
        if self.is_empty():
            return ""
        else:
            try:
                result = self.device_name.decode('utf-8')
            except UnicodeDecodeError:
                result = str(self.device_name)
            return result

    def get_default_report_mode_str(self):
        return report_mode_to_str(self.default_report_mode)

    def get_scan_mode_str(self):
        return scan_mode_to_str(self.scan_plan.mode)

_make_bit_field_variables(KeyboardSettingsInfo, [
    ("feature_ctrl" , "usb_disabled"       , FEATURE_CTRL_USB_DISABLE)      ,
    ("feature_ctrl" , "i2c_disabled"       , FEATURE_CTRL_WIRED_DISABLE)    ,
    ("feature_ctrl" , "nrf24_disabled"     , FEATURE_CTRL_RF_DISABLE)       ,
    ("feature_ctrl" , "unifying_disabled"  , FEATURE_CTRL_RF_MOUSE_DISABLE) ,
    ("feature_ctrl" , "bluetooth_disabled" , FEATURE_CTRL_BT_DISABLE)       ,
])

class KeyboardLayoutInfo(keyplus.cdata_types.layout_settings_header_t):
    pass

class KeyboardRFInfo(keyplus.cdata_types.rf_settings_t):
    pass

class KeyboardFirmwareInfo(keyplus.cdata_types.firmware_info_t):
    @property
    def timestamp_raw(self):
        return struct.unpack("<Q", bytearray(self.timestamp))[0]

    @timestamp_raw.setter
    def timestamp_raw(self, value):
        self.timestamp = struct.pack("<Q", value)

    def get_interal_scan_method(self):
        return self.internal_scan_method

    def get_interal_scan_method_as_str(self):
        return self.internal_scan_method_to_str(self.internal_scan_method)

    def internal_scan_method_to_str(self, method):
        assert_equal(type(method), int)
        if method in INTERNAL_SCAN_METHOD_TABLE:
            return INTERNAL_SCAN_METHOD_TABLE[method]
        else:
            return "UnknownInternalScanMethod({})".format(method)


    def has_at_least_version(self, version_str):
        (major, minor, patch) = [int(x) for x in version_str.split('.')]

        return \
            self.version_major >= major and \
            self.version_minor >= minor and \
            self.version_patch >= patch

_make_bit_field_variables(KeyboardFirmwareInfo, [
    ("scan_support" , "has_scanning"           , SUPPORT_SCANNING_MASK)           ,
    ("scan_support" , "has_scanning_col_row"   , SUPPORT_SCANNING_COL_ROW_MASK)   ,
    ("scan_support" , "has_scanning_row_col"   , SUPPORT_SCANNING_ROW_COL_MASK)   ,
    ("scan_support" , "has_scanning_pins"      , SUPPORT_SCANNING_PINS_MASK)      ,
    ("scan_support" , "has_scanning_arbitrary" , SUPPORT_SCANNING_ARBITRARY_MASK) ,
    ("scan_support" , "has_scanning_built_in"  , SUPPORT_SCANNING_BUILT_IN_MASK)  ,

    ("key_handlers" , "has_media_keys"  , SUPPORT_KEY_MEDIA)  ,
    ("key_handlers" , "has_mouse_keys"  , SUPPORT_KEY_MOUSE)  ,
    ("key_handlers" , "has_layer_keys"  , SUPPORT_KEY_LAYERS) ,
    ("key_handlers" , "has_sticky_keys" , SUPPORT_KEY_STICKY) ,
    ("key_handlers" , "has_tap_keys"    , SUPPORT_KEY_TAP)    ,
    ("key_handlers" , "has_hold_keys"   , SUPPORT_KEY_HOLD)   ,

    ("keyboard_features" , "has_6kro"   , SUPPORT_KRO_6)   ,
    ("keyboard_features" , "has_nkro"   , SUPPORT_KRO_N)   ,

    ("led_support" , "has_led_indicators"   , SUPPORT_LED_INDICATORS)   ,
    ("led_support" , "has_led_backlighting" , SUPPORT_LED_BACKLIGHTING) ,
    ("led_support" , "has_led_ws2812"       , SUPPORT_LED_WS2812)       ,

    ("connectivity" , "has_nrf24"     , SUPPORT_NRF24)    ,
    ("connectivity" , "has_i2c"       , SUPPORT_I2C)      ,
    ("connectivity" , "has_unifying"  , SUPPORT_UNIFYING) ,
    ("connectivity" , "has_usb"       , SUPPORT_USB)      ,
    ("connectivity" , "has_bluetooth" , SUPPORT_BT)       ,
])
