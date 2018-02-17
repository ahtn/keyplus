#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import absolute_import, division, print_function, unicode_literals

import six

import cstruct
from cstruct import define, typedef, CStruct
# from keyplus.constants import *

typedef('uint8', 'uint8_t')
typedef('uint16', 'uint16_t')
typedef('uint32', 'uint32_t')

typedef('int8', 'int8_t')
typedef('int16', 'int16_t')
typedef('int32', 'int32_t')

define('MAX_NUM_KEYBOARDS', 64)
define('MAX_NUM_DEVICES', 64)

class scan_plan_t(CStruct):
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

class settings_t(CStruct):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
    uint8_t device_id;
    char device_name[32];
    uint8_t timestamp[8];
    uint8_t default_report_mode;
    struct scan_plan_t scan_plan;
    uint8_t _reserved0[8];
    uint8_t feature_ctrl;
    uint8_t _reserved1[32];
    uint16_t crc; /* total size == 96 */
    """

class keyboard_info_t(CStruct):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
    uint8_t matrix_size;
    uint8_t layer_count;
    """

class device_info_t(CStruct):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
    uint8_t layout_id;
    uint8_t matrix_offset;
    uint8_t matrix_size;
    """

class layout_settings_header_t(CStruct):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
        uint8_t number_layouts;
        uint8_t number_devices;
        uint8_t _reserved[30]; /* 32 */
    """

class layout_settings_t(CStruct):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __struct__ = """
        uint8_t number_layouts;
        uint8_t number_devices;
        uint8_t _reserved[30]; /* 32 */
        struct keyboard_info_t layouts[MAX_NUM_KEYBOARDS];
        struct device_info_t devices[MAX_NUM_DEVICES]; /* 353 bytes */
    """

class firmware_info_t(CStruct):
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
    uint8_t reserved[23];
    """
