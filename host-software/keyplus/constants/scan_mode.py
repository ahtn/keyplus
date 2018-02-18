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

