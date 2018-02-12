#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from layout.common import try_get, ParseError

import re
import math
import struct
import hexdump

from io_map.io_mapper import get_io_mapper_for_chip

MATRIX_SCANNER_MODE_NO_MATRIX = 0x00
MATRIX_SCANNER_MODE_COL_ROW = 0x01
MATRIX_SCANNER_MODE_ROW_COL = 0x02
MATRIX_SCANNER_MODE_PINS = 0x03

DEFAULT_DEBOUNCE_PRESS_TIME = 5
DEFAULT_DEBOUNCE_RELEASE_TIME = (2*DEFAULT_DEBOUNCE_PRESS_TIME)
DEFAULT_RELEASE_TRIGGER_TIME = 3
DEFAULT_PRESS_TRIGGER_TIME = 1
DEFAULT_PARASITIC_DISCHARGE_DELAY_IDLE = 2.0
DEFAULT_PARASITIC_DISCHARGE_DELAY_DEBOUNCE = 10.0

MAX_NUM_ROWS = 10

class ScanMode:
    NO_MATRIX = MATRIX_SCANNER_MODE_NO_MATRIX
    COL_ROW = MATRIX_SCANNER_MODE_COL_ROW
    PINS = MATRIX_SCANNER_MODE_PINS
    MODE_MAP = {
        'no_matrix': NO_MATRIX,
        'col_row': COL_ROW,
        'pins': PINS,
    }

    def __init__(self, scan_mode_dict, debug_hint):
        self.parse_header(scan_mode_dict, debug_hint)

        self.debounce_time_press = DEFAULT_DEBOUNCE_PRESS_TIME
        self.matrix_map = None
        self.debounce_time_release = DEFAULT_DEBOUNCE_RELEASE_TIME
        self.trigger_time_press = DEFAULT_PRESS_TRIGGER_TIME
        self.trigger_time_release = DEFAULT_RELEASE_TRIGGER_TIME
        self.parasitic_discharge_delay_idle = DEFAULT_PARASITIC_DISCHARGE_DELAY_IDLE
        self.parasitic_discharge_delay_debouncing = DEFAULT_PARASITIC_DISCHARGE_DELAY_DEBOUNCE

        if 'matrix_map' in scan_mode_dict:
            self.parse_matrix_map(scan_mode_dict['matrix_map'], debug_hint)

    # uint8_t trigger_time_press; // The key must be down this long before being registered (ms)
    # uint8_t trigger_time_release; // The key must be up this long before being registered (ms)

    # // Both delays are measured on a scale of 0-48µs
    # uint8_t parasitic_discharge_delay_idle; // How long to hold a row low before reading the columns
    # uint8_t parasitic_discharge_delay_debouncing; // How long to hold a row low when a key is debouncing
        if 'debounce_time_press' in scan_mode_dict:
            self.debounce_time_press = scan_mode_dict['debounce_time_press']

        if 'debounce_time_release' in scan_mode_dict:
            self.debounce_time_release = scan_mode_dict['debounce_time_release']

        if 'trigger_time_press' in scan_mode_dict:
            self.trigger_time_press = scan_mode_dict['trigger_time_press']

        if 'trigger_time_release' in scan_mode_dict:
            self.trigger_time_release = scan_mode_dict['trigger_time_release']

        if 'parasitic_discharge_delay_idle' in scan_mode_dict:
            delay = scan_mode_dict['parasitic_discharge_delay_idle']
            if (0 < delay > 48.0):
                raise ParseError("parasitic_discharge_delay_idle must less than 48.0µs")
            self.parasitic_discharge_delay_idle = delay

        if 'parasitic_discharge_delay_debouncing' in scan_mode_dict:
            delay = scan_mode_dict['parasitic_discharge_delay_debouncing']
            if (0 < delay > 48.0):
                raise ParseError("parasitic_discharge_delay_debouncing must less than 48.0µs")
            self.parasitic_discharge_delay_debouncing = delay

        self.get_pin_numbers_for_device(None)


    def __str__(self):
        if self.mode == ScanMode.NO_MATRIX:
            return "ScanMode(mode=ScanMode.NO_MATRIX)"
        elif self.mode == ScanMode.COL_ROW:
            return "ScanMode(mode=ScanMode.COL_ROW, rows={}, cols={})".format(
                    self.rows, self.col_count)

    def parse_header(self, sm_raw, debug_hint):
        self.mode = try_get(sm_raw, 'mode', debug_hint, val_type=str)
        mode = self.mode
        if self.mode not in ScanMode.MODE_MAP:
            raise ParseError("Unsupported scan mode '{}' for device '{}'"
                             .format(self.mode, debug_hint))
        self.mode = ScanMode.MODE_MAP[self.mode]

        self.col_pins = None
        self.row_pins = None
        self.row_count = 0
        self.col_count = 0

        if self.mode == ScanMode.NO_MATRIX:
            pass
        elif self.mode == ScanMode.COL_ROW:
            # Get the row pins
            row_data = try_get(sm_raw, 'rows', debug_hint, val_type=[int, list])
            if isinstance(row_data, int):
                self.row_pins = None
                self.row_count = row_data
            elif isinstance(row_data, list):
                self.row_pins = row_data
                self.row_count = len(self.row_pins)

            # Get the column pins
            col_data = try_get(sm_raw, 'cols', debug_hint, val_type=[int, list])
            if isinstance(col_data, int):
                self.col_pins = None
                self.col_count = col_data
            elif isinstance(col_data, list):
                self.col_pins = col_data
                self.col_count = len(self.col_pins)
        elif self.mode == ScanMode.PINS:
            # TODO:
            # self.row_count = 1
            # self.col_count = 10
            raise ParseError("pins not implemented")
        else:
            raise ParseError("InternalError: Unknown ScanMode({})".format(self.mode))

    def get_pin_numbers_for_device(self, target_device):
        # TODO: don't hard code the chip id, instead obtain it from the device
        ATMEL_ID = 0x03eb0000
        self.pin_mapper = get_io_mapper_for_chip(ATMEL_ID | 0x000A)

        if self.row_pins == None:
            row_pins = self.pin_mapper.get_default_rows(self.row_count)
        else:
            row_pins =[self.pin_mapper.get_pin_number(pin) for pin in self.row_pins]

        if len(row_pins) < MAX_NUM_ROWS:
            row_pins += [0] * (MAX_NUM_ROWS-len(row_pins))
        elif len(row_pins) > MAX_NUM_ROWS:
            raise ParseError("Device only supports a maximum of 10 rows, got '{}'"
                                   .format(len(row_pins)))

        if self.col_pins == None:
            col_pins = self.pin_mapper.get_default_cols(self.col_count)
        else:
            col_pins = [self.pin_mapper.get_pin_number(pin) for pin in self.col_pins]

        self.col_pin_numbers = col_pins
        self.row_pin_numbers = row_pins

        if self.mode != ScanMode.NO_MATRIX:
            self.max_col_pin_num = max(self.col_pin_numbers)
            self.max_key_num = max(self.inverse_map)
        else:
            self.max_col_pin_num = 0
            self.max_key_num = 0


    def generate_pin_maps(self, target_device):
        col_pin_masks = self.pin_mapper.get_pin_masks_as_bytes(self.col_pin_numbers)

        return bytearray(self.row_pin_numbers) + col_pin_masks

    def generate_scan_mode_info(self):
        return struct.pack('<B BB BB BB BB BB',
            self.mode,
            self.row_count,
            self.col_count,
            self.debounce_time_press,
            self.debounce_time_release,
            self.trigger_time_press,
            self.trigger_time_release,
            int(255 * (self.parasitic_discharge_delay_idle / 48.0)),
            int(255 * (self.parasitic_discharge_delay_debouncing / 48.0)),
            self.max_col_pin_num,
            self.max_key_num,
        )

    def generate_key_number_map(self, dev_id):
        result = bytearray(0)

        # print("FAST_ROW_COL map:")
        for row in range(self.row_count):
            row_columns = [0] * (self.max_col_pin_num+1)
            for col in range(self.col_count):
                pin_num = self.col_pin_numbers[col]
                key_map_pos = self.col_count*row + col
                row_columns[pin_num] = self.inverse_map[key_map_pos]
            result += bytearray(row_columns)

        # # Add matrix map to the layout section
        # for key_num in self.inverse_map:
        #     result += struct.pack('<B', key_num)

        return result

    def calc_matrix_size(self):
        if self.mode == ScanMode.COL_ROW:
            return int(math.ceil(self.row_count * self.col_count / 8))
        elif self.mode == ScanMode.PINS:
            return int(math.ceil(self.pin_count / 8))

    def parse_matrix_map(self, mmap_raw, kb_name):
        """ The matrix_map is used to map the keys from how they are "visually
        arranged" to to how they are physically wired. """
        if len(mmap_raw) > self.row_count*self.col_count:
            raise ParseError("Too many keys in matrix_map for '{}'"
                    "got {} but expected at most {} (={}*{})".format(
                    kb_name, len(mmap_raw), self.row_count*self.col_count, self.row_count, self.col_count))
        matrix_map = []
        inverse_map = [0x00] * self.row_count * self.col_count
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
            key_num = self.col_count*r + c
            if r >= self.row_count or c >= self.col_count:
                raise ParseError("Key remap {} out of bounds "
                "rows={}, cols={} in device matrix_map '{}'".format(map_key, self.row_count, self.col_count, kb_name))

            if key_num in matrix_map:
                raise ParseError("The key '{}' appears twice in the matrix_map "
                "of '{}'".format(map_key, kb_name))
            matrix_map.append(key_num)
            inverse_map[key_num] = key_pos

        self.matrix_map = matrix_map
        self.inverse_map = inverse_map
