#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

MAX_DEVICE_ID = 64
MAX_LAYOUT_ID = 64
MAX_MATRIX_SIZE = 32

KEYBOARD_REPORT_MODE_AUTO = 0 # 6kro -> nkro if more than 6 keys pressed
KEYBOARD_REPORT_MODE_NKRO = 1 # nkro
KEYBOARD_REPORT_MODE_6KRO = 2 # 6kro

class ParseError(Exception):
    pass

class ParseTypeError(Exception):
    pass

def try_get(dictionary, key, default=None, hint="", ignore_case=True, val_type=None):
    try:
        value = dictionary[key]

        if val_type != None and type(value) != val_type:
            raise ParseTypeError("Expected an '{}' for '{}' but got '{}' which is a '{}'"
                    .format(
                        val_type,
                        key,
                        value,
                        type(value)
                    )
            )

        if ignore_case and (type(value) is str):
            return value.lower()
        else:
            return value
    except:
        if default != None:
            return default
        if (hint == ""):
            raise ParseError("Expected '{}' field".format(key))
        else:
            raise ParseError("Expected '{}' field in '{}'".format(key, hint))


def bytes_from_hex(string):
    try:
        return bytearray.fromhex(string)
    except:
        raise ParseError("'{}' is not a valid hex string".format(string))


def check_range(var, hint, lo, hi):
    if var < lo or var > hi:
        raise ParseError("Expected '{}' to be in range 0-15".format(hint))
