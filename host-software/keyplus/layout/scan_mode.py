#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from collections import namedtuple

from keyplus.device_info import KeyboardPinMapping
import keyplus.cdata_types

from keyplus.constants import *

DEFAULT_DEBOUNCE_PRESS_TIME = 5
DEFAULT_DEBOUNCE_RELEASE_TIME = (2*DEFAULT_DEBOUNCE_PRESS_TIME)
DEFAULT_RELEASE_TRIGGER_TIME = 3
DEFAULT_PRESS_TRIGGER_TIME = 1
DEFAULT_PARASITIC_DISCHARGE_DELAY_IDLE = 2.0
DEFAULT_PARASITIC_DISCHARGE_DELAY_DEBOUNCE = 10.0

MatrixPosition = namedtuple("MatrixPosition", "row col")

NO_MATRIX = MATRIX_SCANNER_MODE_NO_MATRIX
COL_ROW = MATRIX_SCANNER_MODE_COL_ROW
ROW_COL = MATRIX_SCANNER_MODE_ROW_COL
PIN_GND = MATRIX_SCANNER_MODE_PIN_GND
PIN_VCC = MATRIX_SCANNER_MODE_PIN_VCC

class ScanMode(object):
    MODE_MAP = {
        'no_matrix': NO_MATRIX,
        'col_row': COL_ROW,
        'row_col': ROW_COL,
        'pin_gnd': PIN_GND,
        'pin_vcc': PIN_VCC,
    }

    def __init__(self):
        self.mode = NO_MATRIX

        self.column_pins = []
        self.direct_wiring_pins = []
        self.row_pins = []

        self.matrix_map = {}
        self.matrix_pin_map = {}

        self.debounce_time_press = DEFAULT_DEBOUNCE_PRESS_TIME
        self.debounce_time_release = DEFAULT_DEBOUNCE_RELEASE_TIME
        self.trigger_time_press = DEFAULT_PRESS_TRIGGER_TIME
        self.trigger_time_release = DEFAULT_RELEASE_TRIGGER_TIME
        self.parasitic_discharge_delay_idle = DEFAULT_PARASITIC_DISCHARGE_DELAY_IDLE
        self.parasitic_discharge_delay_debouncing = DEFAULT_PARASITIC_DISCHARGE_DELAY_DEBOUNCE

        self.max_number_supported_keys = 127

    def parse_yaml(self, yaml_dict):
        pass

    @property
    def number_columns(self):
        """ The number of columns in the matrix """
        return len(self.column_pins)

    @property
    def number_rows(self):
        """ The number of rows in the matrix """
        return len(self.row_pins)

    @property
    def number_direct_wiring_pins(self):
        """ The number of direct wiring pins """
        return len(self.direct_wiring_pins)

    @property
    def max_column_key_number(self):
        return max(self.matrix_map.values())

    @property
    def max_pin_key_number(self):
        return max(self.matrix_pin_map.values())

    def is_pin_in_use(self, pin_name):
        """ Returns True if the pin has already been assigned for matrix scanning """
        return (
            (pin_name in self.column_pins) or
            (pin_name in self.row_pins) or
            (pin_name in self.direct_wiring_pins)
        )

    def _check_pin_not_in_use(self, pin_name):
        if self.is_pin_in_use(pin_name):
            raise KeyplusSettingsError(
                "Duplicate use of '{}' pin in row/column pins".format(pin_name)
            )

    def _check_key_number(self, key_number):
        if key_number > self.max_number_supported_keys:
            raise KeyplusSettingsError(
                "Can't assign anymore keys to the matrix map. The maximum number "
                "is {} keys.".format(self.max_number_supported_keys)
            )

    def add_direct_wiring_pin(self, pin_name):
        """ Add a pin to the list of column pins for direct wiring """
        self._check_pin_not_in_use(pin_name)
        self.direct_wiring_pins.append(pin_name)

    def add_column_pins(self, pin_names):
        """ Add a pin to the list of column pins for matrix scanning """
        if isinstance(pin_names, str):
            pin_names = [pin_names]
        for pin_name in pin_names:
            self._check_pin_not_in_use(pin_name)
            self.column_pins.append(pin_name)

    def add_row_pins(self, pin_names):
        """ Add a pin to the list of row pins for matrix scanning """
        if isinstance(pin_names, str):
            pin_names = [pin_names]
        for pin_name in pin_names:
            self._check_pin_not_in_use(pin_name)
            self.row_pins.append(pin_name)

    def add_key_to_matrix_map(self, key_number, row, col):
        """ Assign a key number to (row,column) position in the matrix """
        self._check_key_number(key_number)
        self.matrix_map[MatrixPosition(row, col)] = key_number

    def add_pin_to_matrix_map(self, key_number, pin_number):
        """ Assign a key number to a pin used in direct wiring """
        self._check_key_number(key_number)
        self.matrix_pin_map[pin_number] = key_number

    def set_scan_mode(self, mode):
        """
        Set the scan mode

        Args:
            mode: a string with one of the values 'row_col', 'col_row',
                'pin_gnd', or 'pin_vcc'.
        """
        if mode.lower() not in self.MODE_MAP:
            raise KeyplusSettingsError("Unknown scan mode '{}'".format(mode))
        self.mode = self.MODE_MAP[mode.lower()]

    def _scale_microseconds(self, value):
        """
        Parasitic discharge values are store on a scale of 0-48μs. This function
        scales a value in this range and scales it to an integer in the range
        0-255
        """
        return int(255 * (value / 48.0))

    def _to_microseconds(self, value):
        """
        Parasitic discharge values are store on a scale of 0-48μs. This function
        converts a value on the scale of 0-255 value to a value in 0-48μs.
        """
        return (value / 255 * 48.0)

    def generate_scan_plan(self, device_target):
        scan_plan = keyplus.cdata_types.scan_plan_t()
        scan_plan.mode = self.mode

        if self.mode != NO_MATRIX:
            io_mapper = device_target.get_io_mapper()

        if self.mode == NO_MATRIX:
            # If no matrix is set, then all values can be set to zero
            scan_plan.pack(bytearray(keyplus.cdata_type.scan_plan_t.__size__))
            return scan_plan
        elif self.mode in [COL_ROW, ROW_COL]:
            scan_plan.rows = self.number_rows
            scan_plan.cols = self.number_columns
            scan_plan.max_key_num = self.max_column_key_number;

            # Find the maximum column pin number used
            max_column_pin = 0
            for pin_name in self.column_pins:
                pin_number = io_mapper.get_pin_number(pin_name)
                max_column_pin = max(max_column_pin, pin_number)
            scan_plan.max_col_pin_num = max_column_pin
        elif self.mode == [PIN_GND, PIN_VCC]:
            scan_plan.cols = self.number_direct_wiring_pins
            scan_plan.rows = 0
            scan_plan.max_key_num = self.max_pin_key_number;

            # Find the maximum direct wiring pin number used
            max_pin = 0
            for pin_name in self.direct_wiring_pins:
                pin_number = io_mapper.get_pin_number(pin_name)
                max_pin = max(max_pin, pin_number)
            scan_plan.max_col_pin_num = max_pin
        else:
            raise KeyplusSettingsError("Unknown scan mode '{}'".format(self.mode))

        # Copy debounce settings over
        scan_plan.debounce_time_press = self.debounce_time_press
        scan_plan.debounce_time_release = self.debounce_time_release
        scan_plan.trigger_time_press = self.trigger_time_press
        scan_plan.trigger_time_release = self.trigger_time_release
        scan_plan.parasitic_discharge_delay_idle = \
            self._scale_microseconds(self.parasitic_discharge_delay_idle)
        scan_plan.parasitic_discharge_delay_debouncing = \
            self._scale_microseconds(self.parasitic_discharge_delay_debouncing)

        return scan_plan

    def _generate_key_number_map(self, column_pins, pin_mode=False):
        num_column_positions = max(column_pins) + 1
        if pin_mode == True:
            num_rows = 1
        else:
            num_rows = self.number_rows
        result = [0xff] * num_rows * num_column_positions

        for matrix_pos in self.matrix_map:
            row = matrix_pos.row
            col = matrix_pos.col
            # The FAST_ROW_COL internal scan method assumes a fixed
            # ordering for the column pin numbers. Where col=0 is the
            # lowest pin number on the device, col=1 the next lowest, etc.
            # Since the ScanMode object can supply the pins in an arbitrary
            # order, we need to remapped them the their fixed column
            # positions.
            mapped_col_num = column_pins[col]

            # Store the key number at the correct (row,col) position.
            key_number = self.matrix_map[matrix_pos]
            result[row*num_column_positions + mapped_col_num] = key_number

        return result

    def generate_pin_mapping(self, device_target):
        pin_mapping = KeyboardPinMapping()

        internal_scan_method = device_target.firmware_info.internal_scan_method

        pin_mapping.mode = self.mode
        pin_mapping.internal_scan_method = internal_scan_method

        io_mapper = device_target.get_io_mapper()
        pin_mapping.io_mapper = io_mapper

        if self.mode == NO_MATRIX:
            pass
        elif self.mode in [ROW_COL, COL_ROW]:
            row_pin_numbers = io_mapper.get_pin_numbers(self.row_pins)
            column_pin_numbers = io_mapper.get_pin_numbers(self.column_pins)
            pin_mapping.row_pins = row_pin_numbers
            pin_mapping.column_pins = column_pin_numbers
            pin_mapping.key_number_map = self._generate_key_number_map(column_pin_numbers)
        elif self.mode in [PIN_VCC, PIN_GND]:
            # NOTE: The direct wiring pins are treated the same way as column
            # pins
            direct_pins = io_mapper.get_pin_numbers(self.direct_wiring_pins)
            pin_mapping.column_pins = direct_pins
            pin_mapping.key_number_map = self._generate_key_number_map(direct_pins, pin_mode = True)

        return pin_mapping

    def load_raw_data(self, scan_plan, pin_mapping):
        """ Load data into the ScanMode object form its serialized form.  """
        if not is_valid_scan_mode(scan_plan.mode):
            raise KeyplusSettingsError("Unknown scan mode '{}'".format(scan_plan.mode))
        self.mode = scan_plan.mode

        io_mapper = pin_mapping.io_mapper

        if pin_mapping.internal_scan_method == MATRIX_SCANNER_INTERNAL_FAST_ROW_COL:
            self.row_pins = io_mapper.get_pin_names(pin_mapping.row_pins)
            self.column_pins = io_mapper.get_pin_names(pin_mapping.column_pins)

            self.matrix_map = {}
            num_col_positions = scan_plan.max_col_pin_num+1
            for row in range(scan_plan.rows):
                actual_column_number = 0
                for col in range(num_col_positions):
                    # Ignore columns that aren't in the
                    if col not in pin_mapping.column_pins:
                        continue
                    raw_matrix_map_pos = row * num_col_positions + col
                    key_number = pin_mapping.key_number_map[raw_matrix_map_pos]
                    if key_number == INVALID_KEY_NUMBER:
                        continue
                    actual_matrix_pos = MatrixPosition(row, actual_column_number)
                    self.matrix_map[actual_matrix_pos] = key_number
                    actual_column_number += 1


        self.debounce_time_press = scan_plan.debounce_time_press
        self.debounce_time_release = scan_plan.debounce_time_release
        self.trigger_time_press = scan_plan.trigger_time_press
        self.trigger_time_release = scan_plan.trigger_time_release
        self.parasitic_discharge_delay_idle = self._to_microseconds(
            scan_plan.parasitic_discharge_delay_idle
        )
        self.parasitic_discharge_delay_debouncing = self._to_microseconds(
            scan_plan.parasitic_discharge_delay_debouncing
        )


    def parse_json(self, parser_info=None):
        pass
