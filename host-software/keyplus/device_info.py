#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import datetime
import struct

import keyplus.cdata_types
from keyplus.crc16 import crc16_bytes
from keyplus.constants import *

def _make_bit_field_variables(class_obj, field_list):
    """
    This function uses the python built-in `property()` to create attributes
    to access the bit fields of a function directly.

    The tuple should contain a list of properties where each property is
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


class KeyboardSettingsInfo(keyplus.cdata_types.settings_t):
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
        assert(isinstance(method, int))
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
