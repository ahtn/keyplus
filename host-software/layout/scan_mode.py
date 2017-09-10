#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from layout.common import try_get, ParseError
import re, math

MATRIX_SCANNER_MODE_NONE = 0x00 # doesn't have a matrix
MATRIX_SCANNER_MODE_COL_ROW = 0x01 # normal row,col pin matrix
MATRIX_SCANNER_MODE_PINS = 0x02 # each pin represents a key

class ScanMode:
    COL_ROW = 0
    PINS = 1
    NO_MATRIX = 2
    MODE_MAP = {
        'col_row': COL_ROW,
        'pins': PINS,
        'no_matrix': NO_MATRIX
    }

    def __init__(self, scan_mode_dict, debug_hint):
        self.parse_header(scan_mode_dict, debug_hint)

        if 'matrix_map' in scan_mode_dict:
            self.parse_matrix_map(scan_mode_dict['matrix_map'], debug_hint)
        else:
            self.matrix_map = None

    def __str__(self):
        if self.mode == ScanMode.NO_MATRIX:
            return "ScanMode(mode=ScanMode.NO_MATRIX)"
        elif self.mode == ScanMode.COL_ROW:
            return "ScanMode(mode=ScanMode.COL_ROW, rows={}, cols={})".format(
                    self.rows, self.cols)

    def parse_header(self, sm_raw, debug_hint):
        self.mode = try_get(sm_raw, 'mode', debug_hint, val_type=str)
        self.mode = ScanMode.MODE_MAP[self.mode]

        self.rows = 0
        self.cols = 0

        if self.mode == ScanMode.COL_ROW:
            self.rows = try_get(sm_raw, 'rows', debug_hint, val_type=int)
            self.cols = try_get(sm_raw, 'cols', debug_hint, val_type=int)
        elif self.mode == ScanMode.PINS:
            # self.rows =
            self.cols = 1
            raise ParseError("pins not implemented")
        else:
            pass # TODO

    def calc_matrix_size(self):
        if self.mode == ScanMode.COL_ROW:
            return int(math.ceil(self.rows * self.cols / 8))
        elif self.mode == ScanMode.PINS:
            return int(math.ceil(self.pin_count / 8))

    def parse_matrix_map(self, mmap_raw, kb_name):
        """ The matrix_map is used to map the keys from how they are "visually
        arranged" to to how they are physically wired. """
        if len(mmap_raw) > self.rows*self.cols:
            raise ParseError("Too many keys in matrix_map for '{}'"
                    "got {} but expected at most {} (={}*{})".format(
                    kb_name, len(mmap_raw), self.rows*self.cols, self.rows, self.cols))
        matrix_map = []
        inverse_map = [0xff] * self.rows * self.cols
        for (key_pos, map_key) in enumerate(mmap_raw):
            # these values can be used as spaces and are ignored
            if map_key in ['none', '_'*4, '_'*5, '_'*6, '-'*4, '-'*5, '-'*6]:
                continue

            r, c = None, None
            try:
                results = re.match('r(\d+)c(\d+)', map_key)
                if results == None:
                    raise ParseError
                r, c = results.groups()
                r, c = int(r), int(c)
            except (ParseError, TypeError):
                raise ParseError("Expected string of the form rXcY, but got '{}' "
                        "in matrix_map '{}'".format(map_key, kb_name))
            key_num = self.cols*r + c
            if r >= self.rows or c >= self.cols:
                raise ParseError("Key remap {} out of bounds "
                "rows={}, cols={} in device matrix_map '{}'".format(map_key, self.rows, self.cols, kb_name))

            if key_num in matrix_map:
                raise ParseError("The key '{}' appears twice in the matrix_map "
                "of '{}'".format(map_key, kb_name))
            matrix_map.append(key_num)
            inverse_map[key_num] = key_pos

        self.matrix_map = matrix_map
        self.inverse_map = inverse_map
