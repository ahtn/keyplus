#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from keyplus.exceptions import KeyplusParseError

class Warning(object):
    pass

class UnusedValueWarning(Warning):
    def __init__(self, path_name, values):
        self.path_name = path_name
        self.values = values

    def __str__(self):
        return "Warning: in '{}', the following fields were ignored: {}".format(
            self.path_name, self.values
        )

class KeyplusParserInfo(object):
    def __init__(self, dict_name, dictionary):
        self.property_stack = []

        self.current_field = dict_name
        self.current_obj = dictionary
        self.untouched_fields = list(self.current_obj.keys())

        self.last_field = None

        self.warnings = []

    def touch_field(self, field):
        self.untouched_fields.remove(field)

    def enter(self, field):
        if field not in self.current_obj:
            raise KeyplusParseError("Couldn't find field '{}' in '{}'"
                                    .format(field, self.current_field))
        self.property_stack.append( (self.current_field, self.current_obj, self.untouched_fields) )
        self.touch_field(field)
        self.current_field = field
        self.current_obj = self.current_obj[field]
        self.untouched_fields = list(self.current_obj.keys())

    def get_current_path(self):
        field_path = []
        for (field, _, _) in self.property_stack:
            field_path.append(field)
        return '.'.join(field_path)

    def exit(self):
        assert(len(self.property_stack) != 0)
        if len(self.untouched_fields) != 0:
            self.warnings.append(
                UnusedValueWarning(self.get_current_path(), self.untouched_fields)
            )
        self.current_field, self.current_obj, self.untouched_fields = \
            self.property_stack.pop()

    def try_get(self, field, default=None, ignore_case=True, field_type=None,
                field_range=None, remap_function=None, remap_table=None):
        try:
            value = self.current_obj[field]

            has_matching_type = True
            if field_type == None:
                pass
            elif isinstance(field_type, list):
                # a list of valid types
                has_matching_type = type(value) in field_type
            else:
                # only one valid type
                has_matching_type = isinstance(value, field_type)

            if not has_matching_type:
                raise KeyplusParseError(
                    "Expected an '{}' for '{}' but got '{}' which is a '{}'"
                    .format(
                        field_type,
                        field,
                        value,
                        type(value)
                    )
                )

            self.last_field = field
            self.touch_field(field)

            if ignore_case and (type(value) is str):
                value = value.lower()

            if remap_table != None:
                value = remap_table[value]

            if remap_function != None:
                value = remap_function(value)

            return value
        except:
            if default != None:
                self.last_field = field
                return default
            else:
                raise KeyplusParseError(
                    "Couldn't find field '{}' inside of '{}'"
                    .format(field, self.current_field)
                )

        if field_range:
            self.check_range(field_range[0], field_range[1])

    def get_last_value(self):
        return  self.current_obj[self.last_field]

    def check_range(self, low, high):
        """
        Check that the last parsed value is inside the given range.
        """
        last_value = self.get_last_value()
        if not (low <= last_value <= high):
            raise KeyplusParseError(
                "Expected '{}' to be in range [{},{}]"
                .format(self.last_field, low, high)
            )

    def check_in_set(self, valid_values):
        """
        Check that the last parsed value is one of a given set of values.
        """
        last_value = self.get_last_value()
        if last_value not in valid_values:
            raise KeyplusParseError(
                "For the field '{}', expected one of the following values: {}"
                .format(self.last_field, valid_values)
            )

    def map_to_value(self, value, mapping):
        self.check_in_set(list(mapping.keys()))
        return mapping[value]

    def has_field(self, *fields, field_type=None):
        current_field_obj = self.current_obj
        for field in fields:
            if field in current_field_obj:
                current_field_obj = current_field_obj[field]
            else:
                return False
        if field_type != None:
            return (isinstance(self.current_obj, field_type))
        else:
            return True

    def peek_field(self, *fields):
        current_field_obj = self.current_obj
        for field in fields:
            current_field_obj = current_field_obj[field]
        return current_field_obj
