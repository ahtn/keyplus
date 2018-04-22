#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import six
import sys

from keyplus.exceptions import *
from keyplus.debug import DEBUG
from colorama import Style

class Warning(object):
    pass

class UnusedValueWarning(Warning):
    def __init__(self, path_name, values):
        self.path_name = path_name
        self.values = values

    def __str__(self):
        return ("in {}, the following fields were ignored: {}".format(
                self.path_name, ', '.join(self.values)
            )
        )

class KeyplusParserInfo(object):
    def __init__(self, dict_name, dictionary, print_warnings=False):
        self.property_stack = []

        self.current_field = dict_name
        self.current_obj = dictionary
        self.untouched_fields = list(self.current_obj.keys())

        self.last_field = None

        self.warnings = []
        self.print_warnings = print_warnings

    def touch_field(self, field):
        if DEBUG.parsing:
            self._debug_message("Touch:", "{}.{}".format(self.get_current_path(), field))
        if field in self.untouched_fields:
            self.untouched_fields.remove(field)

    def _debug_message(self, *message, **kwargs):
        indent = '  ' * (len(self.property_stack))
        if 'file' in kwargs:
            file_ = kwargs['file']
        else:
            file_ = sys.stdout
        print(indent, end='', file=file_)
        print(*message, file=file_)

    def enter(self, field):
        if field not in self.current_obj:
            raise KeyplusParseError("Couldn't find field '{}' in '{}'"
                                    .format(field, self.current_field))
        if DEBUG.parsing:
            self._debug_message("Entering field({})".format(field))
        self.property_stack.append( (self.current_field, self.current_obj, self.untouched_fields) )
        self.touch_field(field)
        self.current_field = field
        self.current_obj = self.current_obj[field]
        self.untouched_fields = list(self.current_obj.keys())

    def get_current_path(self):
        def sanitize_field(field):
            if field.isalnum():
                return field
            else:
                return "'{}'".format(field)

        field_path = []
        for (field, _, _) in self.property_stack:
            field_path.append(sanitize_field(field))
        field_path.append(sanitize_field(self.current_field))
        return '.'.join(field_path)

    def exit(self):
        assert(len(self.property_stack) != 0)

        old_field = self.current_field

        if len(self.untouched_fields) != 0:
            self.warnings.append(
                UnusedValueWarning(
                    self.get_current_path(),
                    self.untouched_fields
                )
            )

        # If this is debug code, print the warnings
        if self.print_warnings:
            for warn in self.warnings:
                print(
                    WARN_COLOR + "Warning: " + Style.RESET_ALL + str(warn),
                    file=sys.stderr
                )
            # Clear the warnings now that we have printed them
            self.warnings = []

        self.current_field, self.current_obj, self.untouched_fields = \
            self.property_stack.pop()

        if DEBUG.parsing:
            self._debug_message("Exit field({})".format(old_field))

    def try_get(self, field, default=None, ignore_case=True,
                field_type=None, field_range=None, field_valid_values=None,
                remap_function=None, remap_table=None,
                optional = False):
        """
        Arguments:
            ignore_case: ignore the case of the field names, the field will be
                converted to lower case.
            default: if the field is not found, return this default value instead
            field_type: the field value must match one of the types given in this
                variable. This can be either a single type, or a list of types.
            field_range: For integer types, check that the field value lies
                with in the given bounds. The bounds are provided as list/tuple
                of low and high bounds.
            remap_function: After reading the field, apply this function,
                use the given function to remap the value.
            remap_table: Similar to remap_function, except us a dictionary
                to remap the value. If the value is not in the dictionary,
                raise an error.
            field_valid_values: check if the field value is in the given set.
            optional: the same as default, except return `None` instead of the
                default value
        """

        if field in self.current_obj:
            value = self.current_obj[field]

            has_matching_type = True

            # Python2 compatibility
            if field_type == str:
                field_type = six.string_types

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

            if ignore_case and isinstance(value, six.string_types):
                value = value.lower()

            def check_in_set(valid_values):
                if value in valid_values:
                    return

                raise KeyplusSettingsError(
                    "In {}, for the field '{}' got unknown value '{}'.\nExpecting "
                    "one of: {}".format(
                        self.get_current_path(),
                        field,
                        value,
                        ", ".join(valid_values)
                    )
                )

            if remap_table != None:
                check_in_set(remap_table)
                value = remap_table[value]

            if field_valid_values:
                check_in_set(field_valid_values)

            if remap_function != None:
                try:
                    value = remap_function(value)
                except KeyplusParseError as err:
                    raise KeyplusParseError(
                        "Error in '{}' for field '{}':\n{}".format(
                            self.get_current_path(),
                            field,
                            err
                        )
                    )


            if field_range:
                self.check_range(field_range[0], field_range[1])

            return value
        else:
            # Couldn't find the field
            # Either:
            # * return a default value
            # * return `None` if it is optional
            # * raise Error if it is non-optional and doesn't have a default value
            if default != None:
                self.last_field = field
                return default
            elif optional == True:
                return None
            else:
                raise KeyplusParseError(
                    "In {}, could not find compulsory field '{}'."
                    .format(self.get_current_path(), field)
                )

    def get_last_value(self):
        return  self.current_obj[self.last_field]

    def check_range(self, low, high):
        """
        Check that the last parsed value is inside the given range.
        """
        last_value = self.get_last_value()
        if not (low <= last_value <= high):
            raise KeyplusParseError(
                "In {}, expected '{}' to be in the range [{},{}], but got '{}'."
                .format(
                    self.get_current_path(),
                    self.last_field,
                    low, high,
                    last_value
                )
            )

    def has_field(self, *fields, **kwargs):
        field_obj = self.current_obj
        for field in fields:
            if field in field_obj:
                field_obj = field_obj[field]
            else:
                return False
        if 'field_type' in kwargs:
            field_type = kwargs['field_type']
            return (isinstance(field_obj, field_type))
        else:
            return True

    def peek_field(self, field):
        return self.current_obj[field]

    def iter_fields(self):
        return six.iterkeys(self.current_obj)
