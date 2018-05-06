#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

# TODO: might need to make this data device dependant since the efm8 port
# might need to use a different endpoint configuration
TYPE0_INTERFACE_BOOT_KEYBOARD = 0
TYPE0_INTERFACE_MOUSE = 1
TYPE0_INTERFACE_MEDIA = 2
TYPE0_INTERFACE_VENDOR = 3
TYPE0_INTERFACE_NKRO_KEYBOARD = 4

TYPE1_INTERFACE_BOOT_KEYBOARD = 0
TYPE1_INTERFACE_SHARED_HID = 1
TYPE1_INTERFACE_VENDOR = 2

USB_VERSION_ACCESS_TYPE_bp   = (12)
USB_VERSION_ACCESS_TYPE_MASK = (0xf000)
USB_VERSION_HID_INTERFACE_3  = (0 << USB_VERSION_ACCESS_TYPE_bp) # TYPE0
USB_VERSION_HID_INTERFACE_2  = (1 << USB_VERSION_ACCESS_TYPE_bp) # TYPE1
# USB_VERSION_HID_INTERFACE_1  = (2 << USB_VERSION_ACCESS_TYPE_bp)
# USB_VERSION_HID_INTERFACE_0  = (3 << USB_VERSION_ACCESS_TYPE_bp)
