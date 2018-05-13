#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import absolute_import, division, print_function, unicode_literals

import six

import cstruct
from cstruct import define, typedef, CStruct
from keyplus.constants import *

class CStructWithBytes(CStruct):
    def to_bytes(self):
        return bytearray(self.pack())

typedef('uint8', 'uint8_t')
typedef('uint16', 'uint16_t')
typedef('uint32', 'uint32_t')

typedef('int8', 'int8_t')
typedef('int16', 'int16_t')
typedef('int32', 'int32_t')

define('MAX_NUM_KEYBOARDS', 64)
define('MAX_NUM_DEVICES', 64)
define('AES_KEY_LEN', 16)
define('NRF_ADDR_LEN', 5)

def make_bit_field_variables(class_obj, field_list):
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


class scan_plan_t(CStructWithBytes):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
        uint8_t mode;
        uint8_t rows;
        uint8_t cols;
        uint8_t debounce_time_press;
        uint8_t debounce_time_release;
        uint8_t trigger_time_press;
        uint8_t trigger_time_release;
        uint8_t parasitic_discharge_delay_idle;
        uint8_t parasitic_discharge_delay_debouncing;
        uint8_t max_col_pin_num;
        uint8_t max_key_num;
    """


class settings_header_t(CStructWithBytes):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
    uint8_t device_id;
    uint8_t _device_name[50];
    uint8_t timestamp[8];
    uint8_t default_report_mode;
    struct scan_plan_t scan_plan;
    uint8_t _reserved0[8];
    uint8_t feature_ctrl;
    uint8_t _reserved1[14];
    uint16_t crc; /* total size == 96 */
    """


class feature_ctrl_t(CStructWithBytes):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
    uint8_t feature_ctrl;
    """

for class_name in [settings_header_t, feature_ctrl_t]:
    make_bit_field_variables(class_name, [
        ("feature_ctrl" , "usb_disabled"       , FEATURE_CTRL_USB_DISABLE)      ,
        ("feature_ctrl" , "i2c_disabled"       , FEATURE_CTRL_WIRED_DISABLE)    ,
        ("feature_ctrl" , "nrf24_disabled"     , FEATURE_CTRL_RF_DISABLE)       ,
        ("feature_ctrl" , "unifying_disabled"  , FEATURE_CTRL_RF_MOUSE_DISABLE) ,
        ("feature_ctrl" , "bluetooth_disabled" , FEATURE_CTRL_BT_DISABLE)       ,
    ])


class keyboard_info_t(CStructWithBytes):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
    uint8_t matrix_size;
    uint8_t layer_count;
    """

class device_info_t(CStructWithBytes):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
    uint8_t layout_id;
    uint8_t matrix_offset;
    uint8_t matrix_size;
    """

class layout_settings_header_t(CStructWithBytes):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
        uint8_t number_layouts;
        uint8_t number_devices;
        uint8_t _reserved[30]; /* 32 */
    """

class layout_settings_t(CStructWithBytes):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
        uint8_t number_layouts;
        uint8_t number_devices;
        uint8_t _reserved[30]; /* 32 */
        struct keyboard_info_t layouts[MAX_NUM_KEYBOARDS];
        struct device_info_t devices[MAX_NUM_DEVICES]; /* 353 bytes */
    """

class firmware_info_t(CStructWithBytes):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
    uint8_t version_major;
    uint8_t version_minor;
    uint8_t version_patch;
    uint32_t layout_flash_size;
    uint8_t timestamp[8];
    uint8_t git_hash[8];
    uint8_t connectivity;
    uint8_t scan_support;
    uint8_t keyboard_features;
    uint8_t key_handlers;
    uint8_t led_support;
    uint16_t bootloader_vid;
    uint16_t bootloader_pid;
    uint32_t chip_id;
    uint16_t board_id;
    uint8_t internal_scan_method;
    uint8_t page_size;
    uint8_t max_rows;
    uint8_t version_info;
    uint8_t reserved[20];
    """

make_bit_field_variables(firmware_info_t, [
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

    ("version_info" , "is_stable_build"  , VERSION_IS_STABLE)    ,
])

class rf_settings_t(CStructWithBytes):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
    uint8_t pipe_addr_0[NRF_ADDR_LEN];
    uint8_t pipe_addr_1[NRF_ADDR_LEN];
    uint8_t pipe_addr_2;
    uint8_t pipe_addr_3;
    uint8_t pipe_addr_4;
    uint8_t pipe_addr_5;
    uint8_t channel;
    uint8_t arc;
    uint8_t data_rate;
    uint8_t power;
    uint8_t _reserved[14];
    uint8_t ekey[AES_KEY_LEN];
    uint8_t dkey[AES_KEY_LEN];
    """

class settings_t(CStructWithBytes): #
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
    struct settings_header_t header; /* size == 96 */
    struct layout_settings_t layout; /* size == 352 */
    struct rf_settings_t rf; /* size == 64 */
    """ # size == 512 bytes
