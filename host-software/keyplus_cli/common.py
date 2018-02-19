#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import datetime
import sys
import protocol

EXIT_COMMAND_ERROR = 1
EXIT_MATCH_DEVICE = 2
EXIT_UNSUPPORTED_FEATURE = 3
EXIT_BAD_FILE = 4
EXIT_INSUFFICIENT_SPACE = 5

def print_hid_info(hid_device):
    print("{:x}:{:x} | {} | {} | {}"
        .format(
            hid_device.vendor_id,
            hid_device.product_id,
            hid_device.manufacturer_string,
            hid_device.product_string,
            hid_device.serial_number,
        )
    )

def timestamp_to_string(tstamp):
    timestamp_str = "<Unavailable>"
    if tstamp != 0:
        build_date = datetime.datetime.fromtimestamp(tstamp)
        timestamp_str = str(build_date)
    return timestamp_str

def print_device_info(device_info, indent="  "):
    print(indent, "id: ", device_info.device_id)
    print(indent, "name: '{}'".format(device_info.get_name_str()) )
    print(indent, "layout last updated: ", timestamp_to_string(device_info.timestamp_raw))
    print(indent, "default_report_mode: ", device_info.get_default_report_mode_str())
    print(indent, "scan_mode: ", device_info.scan_plan.mode)
    print(indent, "row_count: ", device_info.scan_plan.rows)
    print(indent, "col_count: ", device_info.scan_plan.cols)

def print_layout_info(device, indent="  "):
    layout_info = protocol.get_layout_info(device)
    print(indent, "number_devices: ", layout_info.number_devices)
    print(indent, "number_layouts: ", layout_info.number_layouts)

def print_firmware_info(device, indent="  "):
    fw_info = protocol.get_firmware_info(device)
    print(indent, "build time: ", timestamp_to_string(fw_info.timestamp_raw))
    print(indent, "git_hash: {:08x}".format(fw_info.git_hash))

def print_all_info(kb_device):
    print_hid_info(kb_device.hid_device)
    print_device_info(kb_device.device_info)
    # print_layout_info(device)
    # print("firmware info:")
    # print_firmware_info(device)

