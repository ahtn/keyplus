#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import keyplus.cdata_types
from keyplus.crc16 import crc16_bytes
from keyplus.constants import *

class KeyboardSettingsInfo(keyplus.cdata_types.settings_t):
    def has_valid_crc(self):
        return self.crc == self.compute_crc()

    def compute_crc(self):
        return crc16_bytes(self.pack()[:-2])

    def is_empty(self):
        # check if the flash has been initialized
        return sum([1 for byte in self.pack() if byte != 0xff]) == 0

    def get_name(self):
        if self.is_empty():
            return ""
        else:
            try:
                result = self.device_name.decode('utf-8')
            except UnicodeDecodeError:
                result = str(self.device_name)
            return result

    def get_timestamp_str(self):
        return timestamp_to_str(self.timestamp)

    def get_default_report_mode_str(self):
        return report_mode_to_str(self.default_report_mode)

    def get_scan_mode_str(self):
        return scan_mode_to_str(self.scan_mode)

    def has_usb(self):
        return not bool(self.feature_ctrl & FEATURE_CTRL_USB_DISABLE)

    def has_i2c(self):
        return not bool(self.feature_ctrl & FEATURE_CTRL_WIRED_DISABLE)

    def has_nrf24(self):
        return not bool(self.feature_ctrl & FEATURE_CTRL_RF_DISABLE)

    def has_unifying_mouse(self):
        return not bool(self.feature_ctrl & FEATURE_CTRL_RF_MOUSE_DISABLE)

    def has_bluetooth(self):
        return not bool(self.feature_ctrl & FEATURE_CTRL_BT_DISABLE)

class KeyboardLayoutInfo(keyplus.cdata_types.layout_settings_header_t):
    pass

class KeyboardRFInfo(keyplus.cdata_types.rf_settings_t):
    pass

class KeyboardFirmwareInfo(keyplus.cdata_types.firmware_info_t):
    def has_fw_support_scanning(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_MASK) != 0

    def has_fw_support_scanning_row_col(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_ROW_COL_MASK) != 0

    def has_fw_support_scanning_col_row(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_COL_ROW_MASK) != 0

    def has_fw_support_scanning_pins(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_PINS_MASK) != 0

    def has_fw_support_scanning_arbitrary(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_ARBITRARY_MASK) != 0

    def has_fw_support_scanning_built_in(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_BUILT_IN_MASK) != 0

    def has_fw_support_key_media(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_MEDIA) != 0

    def has_fw_support_key_mouse(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_MOUSE) != 0

    def has_fw_support_key_layers(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_LAYERS) != 0

    def has_fw_support_key_sticky(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_STICKY) != 0

    def has_fw_support_key_tap(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_TAP) != 0

    def has_fw_support_key_hold(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_HOLD) != 0

    def has_fw_support_nkro(self):
        return (self.kb_support_flags & SUPPORT_KRO_N) != 0
    def has_fw_support_6kro(self):
        return (self.kb_support_flags & SUPPORT_KRO_6) != 0

    def has_fw_support_led_indicators(self):
        return (self.led_support_flags & SUPPORT_LED_INDICATORS) != 0
    def has_fw_support_led_backlighting(self):
        return (self.led_support_flags & SUPPORT_LED_BACKLIGHTING) != 0
    def has_fw_support_led_ws2812(self):
        return (self.led_support_flags & SUPPORT_LED_WS2812) != 0

    def has_fw_support_nrf24(self):
        return (self.connectivity_support_flags & SUPPORT_NRF24) != 0
    def has_fw_support_i2c(self):
        return (self.connectivity_support_flags & SUPPORT_I2C) != 0
    def has_fw_support_unifying(self):
        return (self.connectivity_support_flags & SUPPORT_UNIFYING) != 0
    def has_fw_support_usb(self):
        return (self.connectivity_support_flags & SUPPORT_USB) != 0
    def has_fw_support_bluetooth(self):
        return (self.connectivity_support_flags & SUPPORT_BT) != 0

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
