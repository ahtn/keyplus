#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

DEFAULT_MANUFACTUER = 'Xusb'
DEFAULT_PRODUCT = 'Xusb-boot'

PROTOTYPE_VID = 0x6666
PROTOTYPE_PID = 0xB007

DEFAULT_VID = 0x1209
DEFAULT_PID = 0xBB01

DEFAULT_USB_IDS = [
    (PROTOTYPE_VID, PROTOTYPE_PID),
    (DEFAULT_VID, DEFAULT_PID),
]

DEFAULT_INTERFACE = 0

VERSION_MAJOR = 1
VERSION_MINOR = 0

CMD_GET_BOOT_INFO = 0x00
CMD_WRITE = 0x01
CMD_CRC = 0x02
CMD_RESET = 0x03
CMD_ERASE = 0x04

PACKET_ERROR_STATUS  = 0x00
PACKET_CRC  = 0x01

OKAY = 0x00
ERROR = 0x01
ERROR_MISALIGNED = 0x02
ERROR_NOT_ERASED = 0x03

VENDOR_REPORT_SIZE = 64
