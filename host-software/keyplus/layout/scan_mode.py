#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from collections import namedtuple
from copy import copy
import re
import sys

from keyplus.device_info import KeyboardPinMapping
import keyplus.cdata_types

from keyplus.layout.parser_info import KeyplusParserInfo
from keyplus.layout.debounce_profiles import *
from keyplus.exceptions import *

from keyplus.utility import list_to_map, inverse_map

from keyplus.constants import *

MatrixPosition = namedtuple("MatrixPosition", "row col")

NO_MATRIX = MATRIX_SCANNER_MODE_NO_MATRIX
COL_ROW = MATRIX_SCANNER_MODE_COL_ROW
ROW_COL = MATRIX_SCANNER_MODE_ROW_COL
PIN_GND = MATRIX_SCANNER_MODE_PIN_GND
PIN_VCC = MATRIX_SCANNER_MODE_PIN_VCC

MODE_MAP = {
    'no_matrix': NO_MATRIX,
    'col_row': COL_ROW,
    'row_col': ROW_COL,
    'pin_gnd': PIN_GND,
    'pin_vcc': PIN_VCC,
}

INV_MODE_MAP = {}
for key in MODE_MAP:
    INV_MODE_MAP[MODE_MAP[key]] = key

def fullmatch(regex, string, flags=0):
    """Emulate python-3.4 re.fullmatch()."""
    return re.match("(?:" + regex + r")\Z", string, flags=flags)

def is_blank_pin(pin_name):
    return fullmatch('-+', pin_name) or fullmatch('_+', pin_name) or \
            pin_name == 'none'

class ScanMode(object):
    def __init__(self):
        self.mode = NO_MATRIX

        self.column_pins = []
        self.row_pins = []
        self.direct_wiring_pins = []

        self.matrix_map = {}
        self.matrix_pin_map = {}

        self._unused_key_numbers = []

        self.set_debounce_profile('default')

        self.max_number_supported_keys = 127

    @property
    def number_columns(self):
        """ The number of columns in the matrix """
        if isinstance(self.column_pins, int):
            return self.column_pins
        else:
            return len(self.column_pins)

    @property
    def number_rows(self):
        """ The number of rows in the matrix """
        if isinstance(self.row_pins, int):
            return self.row_pins
        else:
            return len(self.row_pins)

    @property
    def number_direct_wiring_pins(self):
        """ The number of direct wiring pins """
        return len(self.direct_wiring_pins)

    @property
    def max_pin_key_number(self):
        return max(self.matrix_pin_map.values())

    @property
    def number_mapped_keys(self):
        if self.mode == NO_MATRIX:
            return 0
        elif self.mode in [COL_ROW, ROW_COL]:
            return len(self.matrix_map) + len(self._unused_key_numbers)
        elif self.mode in [PIN_GND, PIN_VCC]:
            return len(self.direct_wiring_pins) + len(self._unused_key_numbers)

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
        print(self.direct_wiring_pins, pin_name)
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
        if (col >= self.number_columns):
            raise KeyplusParseError(
                "Invalid matrix map position r{}c{}. This matrix uses {} "
                " columns, so the largest allowed column number "
                " is {}, but got {}.".format(
                    row, col,
                    self.number_columns,
                    self.number_columns-1,
                    col
                )
            )
        if (row >= self.number_rows):
            raise KeyplusParseError(
                "Invalid matrix map position r{}c{}. This matrix uses {} "
                " rows, so the largest allowed row number "
                " is {}, but got {}.".format(
                    row, col,
                    self.number_rows,
                    self.number_rows-1,
                    row
                )
            )
        if MatrixPosition(row, col) in self.matrix_map:
            raise KeyplusParseError(
                "Duplicate use of matrix map position r{}c{}."
                .format(row, col)
            )
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
        if mode.lower() not in MODE_MAP:
            raise KeyplusSettingsError("Unknown scan mode '{}'".format(mode))
        self.mode = MODE_MAP[mode.lower()]

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

    def get_column_pin_numbers(self, io_mapper):
        if isinstance(self.column_pins, int):
            return io_mapper.get_default_cols(self.column_pins)
        else:
            return io_mapper.get_pin_numbers(self.column_pins)

    def get_column_pin_order_map(self, io_mapper):
        """
        When the matrix_map is serialized and sent to the device, the order
        that the column pins where defined is lost.
        """
        pins = self.get_column_pin_numbers(io_mapper)
        col_num_map = {}
        for (col_num, pin) in enumerate(pins):
            col_num_map[pin] = col_num
        pin_rank = sorted(pins)
        result = []
        for (rank, pin) in pin_rank:
            result[rank] = con_num_map[pin]
        return result

    def get_row_pin_numbers(self, io_mapper):
        if isinstance(self.row_pins, int):
            return io_mapper.get_default_rows(self.row_pins)
        else:
            return  io_mapper.get_pin_numbers(self.row_pins)

    def generate_scan_plan(self, device_target):
        scan_plan = keyplus.cdata_types.scan_plan_t()

        scan_plan.mode = self.mode

        fw_info = device_target.firmware_info
        use_basic_scan = (fw_info.internal_scan_method == MATRIX_SCANNER_INTERNAL_BASIC_SCAN)

        if self.mode != NO_MATRIX:
            io_mapper = device_target.get_io_mapper()
        if self.mode == NO_MATRIX:
            # If no matrix is set, then all values can be set to zero
            scan_plan.unpack(bytearray(keyplus.cdata_types.scan_plan_t.__size__))
            return scan_plan
        elif self.mode in [COL_ROW, ROW_COL]:
            scan_plan.rows = self.number_rows
            scan_plan.cols = self.number_columns

            if use_basic_scan and self.mode == ROW_COL:
                # BASIC_SCAN mode emulates ROW_COL mode by swapping COLS and
                # ROWS
                scan_plan.rows, scan_plan.cols = scan_plan.cols, scan_plan.rows
                scan_plan.mode = COL_ROW
                column_pin_numbers = self.get_row_pin_numbers(io_mapper)
            else:
                column_pin_numbers = self.get_column_pin_numbers(io_mapper)

            scan_plan.max_key_num = max(self.matrix_map.values())

            if scan_plan.rows > device_target.firmware_info.max_rows:
                raise KeyplusSettingsError(
                    "Maximum number of rows exceeded. This version of the firmware "
                    " only supports {}, but {} rows were used."
                    .format(
                        device_target.firmware_info.max_rows,
                        scan_plan.rows
                    )
                )

            # Find the maximum column pin number used
            max_column_pin = 0
            for pin_number in column_pin_numbers:
                max_column_pin = max(max_column_pin, pin_number)
            scan_plan.max_col_pin_num = max_column_pin
        elif self.mode in [PIN_GND, PIN_VCC]:

            if use_basic_scan and self.mode == PIN_VCC:
                raise KeyplusSettingsError(
                    "The target device can't support the `pin_vcc` scan method. "
                    "Using the BASIC_SCAN method it can only support: "
                    "`pin_gnd`, `col_row` and `row_col`."
                )

            scan_plan.cols = self.number_direct_wiring_pins
            scan_plan.rows = 1

            # Find the maximum direct wiring pin number used
            max_pin = 0
            for pin_name in self.direct_wiring_pins:
                pin_number = io_mapper.get_pin_number(pin_name)
                max_pin = max(max_pin, pin_number)

            scan_plan.max_key_num = max_pin
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

    def _generate_key_number_map(self, column_pins, use_pin_map=False,
                                 invert_row_col=False):
        """
        Convert the matrix map from the format used in the layout files to
        the one internally used by the controller.
        """
        num_column_positions = max(column_pins) + 1

        if use_pin_map:
            # For pin mode, make the matrix_map based on the order the pins
            # were listed, treating each pin as its own column.
            matrix_map = {}
            for (pin_i, pin_name) in enumerate(self.direct_wiring_pins):
                if is_blank_pin(pin_name):
                    continue
                matrix_map[MatrixPosition(0, pin_i)] = pin_i
            num_rows = 1
        elif invert_row_col:
            # For BASIC_SCAN mode, we need to invert the rows and columns. So
            # make a matrix map with the rows and columns swaped
            matrix_map = {}
            for old_pos in self.matrix_map:
                new_pos = MatrixPosition(old_pos.col, old_pos.row)
                print(old_pos, "->", new_pos, self.matrix_map[old_pos])
                matrix_map[new_pos] = self.matrix_map[old_pos]

            # columns are now rows
            num_rows = self.number_columns
        else:
            # Otherwise just use the matrix map
            matrix_map = self.matrix_map
            num_rows = self.number_rows
        result = [0xff] * num_rows * num_column_positions

        for matrix_pos in matrix_map:
            row = matrix_pos.row
            col = matrix_pos.col
            # The FAST_ROW_COL internal scan method assumes a fixed
            # ordering for the column pin numbers. Where col=0 is the
            # lowest pin number on the device, col=1 the next lowest, etc.
            # Since the ScanMode object can supply the pins in an arbitrary
            # order, we need to remapped them to their fixed column positions.
            mapped_col_num = column_pins[col]

            # Store the key number at the correct (row,col) position.
            key_number = matrix_map[matrix_pos]
            result[row*num_column_positions + mapped_col_num] = key_number

        return result

    def generate_pin_mapping(self, dev_target):
        pin_mapping = KeyboardPinMapping()

        fw_info = dev_target.firmware_info

        pin_mapping.mode = self.mode
        pin_mapping.internal_scan_method = fw_info.internal_scan_method
        using_basic_scan = (fw_info.internal_scan_method == MATRIX_SCANNER_INTERNAL_BASIC_SCAN)
        pin_mapping.max_rows = fw_info.max_rows

        io_mapper = dev_target.get_io_mapper()
        pin_mapping.io_mapper = io_mapper

        if self.mode == NO_MATRIX:
            pass
        elif self.mode in [ROW_COL, COL_ROW]:
            row_pin_numbers = self.get_row_pin_numbers(io_mapper)
            column_pin_numbers = self.get_column_pin_numbers(io_mapper)

            if (using_basic_scan and self.mode == ROW_COL):
                # ROW_COL method can't use pull-down resistors, so it needs
                # treat the columns as rows, and the rows as columns.
                # So we swap them here.
                (row_pin_numbers, column_pin_numbers) = (column_pin_numbers, row_pin_numbers)
                invert_row_col = True

                # Since the internal scan method used by the device is still
                # COL_ROW since we are flipping ROWS and COLUMNS here.
                pin_mapping.mode = COL_ROW
            else:
                invert_row_col = False

            pin_mapping.row_pins = row_pin_numbers
            pin_mapping.column_pins = column_pin_numbers
            pin_mapping.key_number_map = self._generate_key_number_map(
                column_pin_numbers,
                invert_row_col = invert_row_col
            )
        elif self.mode in [PIN_VCC, PIN_GND]:
            # NOTE: The direct wiring pins are treated the same way as column
            # pins
            if (using_basic_scan and self.mode == PIN_VCC):
                raise KeyplusSettingsError(
                    "The target device can't support the `pin_vcc` scan method. "
                    "Using the BASIC_SCAN method it can only support: "
                    "`pin_gnd`, `col_row` and `row_col`."
                )

            direct_pins = io_mapper.get_pin_numbers(self.direct_wiring_pins)
            pin_mapping.column_pins = direct_pins
            pin_mapping.row_pins = [0] # dummy value
            pin_mapping.key_number_map = self._generate_key_number_map(
                direct_pins,
                use_pin_map = True
            )

        return pin_mapping

    def load_raw_data(self, scan_plan, pin_mapping):
        """ Load data into the ScanMode object form its serialized form.  """
        if not is_valid_scan_mode(scan_plan.mode):
            raise KeyplusSettingsError("Unknown scan mode '{}'".format(scan_plan.mode))
        self.mode = scan_plan.mode

        io_mapper = pin_mapping.io_mapper

        if pin_mapping.internal_scan_method == MATRIX_SCANNER_INTERNAL_FAST_ROW_COL:
            if self.mode in [ROW_COL, COL_ROW]:
                self.row_pins = io_mapper.get_pin_names(pin_mapping.row_pins)
                self.column_pins = io_mapper.get_pin_names(pin_mapping.column_pins)
            if self.mode in [PIN_GND, PIN_VCC]:
                self.direct_wiring_pins = io_mapper.get_pin_names(pin_mapping.column_pins)

            pin_to_column_map = inverse_map(list_to_map(pin_mapping.column_pins))

            self.matrix_map = {}
            num_col_positions = scan_plan.max_col_pin_num+1
            for row in range(scan_plan.rows):
                for col in range(num_col_positions):
                    # Ignore columns that aren't in the
                    if col not in pin_mapping.column_pins:
                        continue
                    raw_matrix_map_pos = row * num_col_positions + col
                    key_number = pin_mapping.key_number_map[raw_matrix_map_pos]
                    if key_number == INVALID_KEY_NUMBER:
                        continue

                    logical_column_number = pin_to_column_map[col]
                    actual_matrix_pos = MatrixPosition(row, logical_column_number)
                    self.matrix_map[actual_matrix_pos] = key_number


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

    def debounce_to_json(self):
        result = {}

        result['debounce_time_press'] = self.debounce_time_press
        result['debounce_time_release'] = self.debounce_time_release
        result['trigger_time_press'] = self.trigger_time_press
        result['trigger_time_release'] = self.trigger_time_release
        result['parasitic_discharge_delay_idle'] = self.parasitic_discharge_delay_idle
        result['parasitic_discharge_delay_debouncing'] = self.parasitic_discharge_delay_debouncing

        matches_debounce_profile = True
        for field in result:
            if result[field] != DEBOUNCE_PROFILE_TABLE[self.debounce_profile][field]:
                matches_debounce_profile = False
                break

        if matches_debounce_profile:
            return self.debounce_profile
        else:
            return result

    def set_debounce_profile(self, profile_name):
        """
        Set the debounce profile from given presets.

        TODO: maybe consider making the presets scale parasitic discharge
        delay according to the number of row/cols used.
        """
        if profile_name not in DEBOUNCE_PROFILE_TABLE:
            raise KeyplusSettingsError("Unknown debounce profile: {}"
                                       .format(profile_name))
        else:
            self.debounce_profile = profile_name
            profile = DEBOUNCE_PROFILE_TABLE[profile_name]
            # copy all the fields of the debounce profile to this object
            for field in profile:
                setattr(self, field, profile[field])

    def parse_matrix_map_refrence(self, reference):
        """
        Convert a matrix_map reference (i.e. rXcY) to a MatrixPosition object
        """
        reference = reference.lower()
        if is_blank_pin(reference):
            return None
        results = re.match('^r(\d+)c(\d+)$', reference)
        if results == None and results2 == None:
            raise KeyplusParseError(
                "Expected string of the form rXcY, but got '{}'".format(reference)
            )
        r, c = results.groups()
        return MatrixPosition(int(r), int(c))

    def parse_matrix_map(self, mapping):
        self.matrix_map = {}
        for (key_num, row_col_refrence) in enumerate(mapping):
            pos = self.parse_matrix_map_refrence(row_col_refrence)
            if pos == None:
                self._unused_key_numbers.append(key_num)
                continue
            self.add_key_to_matrix_map(key_num, pos.row, pos.col)

    def parse_json(self, json_obj=None, parser_info=None):
        if parser_info == None:
            assert(json_obj != None)
            parser_info = KeyplusParserInfo(
                "<ScanMode>",
                {"scan_mode": json_obj},
                print_warnings = True
            )
        parser_info.enter("scan_mode")

        self.mode = parser_info.try_get(
            field = "mode",
            field_type=str,
            remap_table = MODE_MAP,
        )

        if self.mode == NO_MATRIX:
            parser_info.exit()
            return
        elif self.mode in [ROW_COL, COL_ROW]:
            self.row_pins = parser_info.try_get("rows", field_type=[list, int])
            self.column_pins = parser_info.try_get("cols", field_type=[list, int])
            parser_info.try_get(
                "matrix_map",
                field_type=list,
                remap_function=self.parse_matrix_map,
            )
        elif self.mode in [PIN_GND, PIN_VCC]:
            self.direct_wiring_pins = parser_info.try_get("pins", field_type=[list, int])

        if parser_info.has_field('debounce', field_type=str):
            debounce_profile = parser_info.try_get("debounce", field_type=str)
            self.set_debounce_profile(debounce_profile)
        elif parser_info.has_field('debounce', field_type=dict):

            parser_info.enter('debounce')

            self.set_debounce_profile('default')

            self.debounce_time_press = parser_info.try_get(
                "debounce_time_press", default=self.debounce_time_press, field_type=int,
                field_range=[0, 255]
            )

            self.debounce_time_release = parser_info.try_get(
                "debounce_time_release", default=self.debounce_time_release, field_type=int,
                field_range=[0, 255]
            )

            self.trigger_time_press = parser_info.try_get(
                "trigger_time_press", default=self.trigger_time_press, field_type=int,
                field_range=[0, 255]
            )

            self.trigger_time_release = parser_info.try_get(
                "trigger_time_release", default=self.trigger_time_release, field_type=int,
                field_range=[0, 255]
            )

            self.parasitic_discharge_delay_idle = parser_info.try_get(
                "parasitic_discharge_delay_idle",
                default=self.parasitic_discharge_delay_idle,
                field_type=[int, float],
                field_range=[0, 48.0]
            )

            self.parasitic_discharge_delay_debouncing = parser_info.try_get(
                "parasitic_discharge_delay_debouncing",
                default=self.parasitic_discharge_delay_debouncing,
                field_type=[int, float],
                field_range=[0, 48.0]
            )

            parser_info.exit()

        parser_info.exit()

    def to_json(self):
        result  = {}

        result['mode'] = INV_MODE_MAP[self.mode]

        if self.mode == NO_MATRIX:
            pass
        elif self.mode in [ROW_COL, COL_ROW]:
            result['rows'] = copy(self.row_pins)
            result['cols'] = copy(self.column_pins)
            num_keys = max(self.matrix_map.values()) + 1
            matrix_map = ['____'] * num_keys
            for matrix_pos in self.matrix_map:
                key_number = self.matrix_map[matrix_pos]
                matrix_pos_str = "r{}c{}".format(matrix_pos.row, matrix_pos.col)
                matrix_map[key_number] = matrix_pos_str
            result['matrix_map'] = matrix_map
        elif self.mode in [PIN_GND, PIN_VCC]:
            result['pins'] = copy(self.direct_wiring_pins)

        result['debounce'] = self.debounce_to_json()

        return result
