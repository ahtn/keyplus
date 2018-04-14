#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

MATRIX_SCANNER_MODE_NO_MATRIX = 0x00
MATRIX_SCANNER_MODE_COL_ROW = 0x01
MATRIX_SCANNER_MODE_ROW_COL = 0x02
MATRIX_SCANNER_MODE_PIN_GND = 0x03
MATRIX_SCANNER_MODE_PIN_VCC = 0x04

SCAN_MODE_STR_MAP = {
    MATRIX_SCANNER_MODE_NO_MATRIX: "none",
    MATRIX_SCANNER_MODE_COL_ROW: "diodes column to row",
    MATRIX_SCANNER_MODE_ROW_COL: "diodes row to column",
    MATRIX_SCANNER_MODE_PIN_GND: "pin_gnd",
    MATRIX_SCANNER_MODE_PIN_VCC: "pin_vcc",
}

INVALID_KEY_NUMBER = 0xff

def is_valid_scan_mode(mode):
    return mode in SCAN_MODE_STR_MAP

def scan_mode_to_str(mode):
    if mode in SCAN_MODE_STR_MAP:
        return SCAN_MODE_STR_MAP[mode]
    else:
        return "Unknown({})".format(mode)
