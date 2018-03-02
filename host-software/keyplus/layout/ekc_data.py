#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import struct
from hexdump import hexdump
from keyplus.layout.parser_info import KeyplusParserInfo
from keyplus.exceptions import *

import keyplus.keycodes as keycodes

class EKCData(object):
    def __init__(self, data):
        self.data = data

    def set_keycode_map_function(self, kc_map_function):
        self.kc_map_function = kc_map_function

    def size(self):
        return len(self.data)

    # def to_bytes(self):
    #     return bytearray(self.data)

class EKCHoldKey(EKCData):
    # Layout option:
    #   1: kc_hold_key
    #   1: delay
    #   1: options
    #   1: hold_key
    #   1: tap_key

    SIZE = 5 * 2

    DEFAULT_DELAY = 200

    def __init__(self, tap_key, hold_key, delay=200, options=None, kc_map_function=None):
        self.tap_key = tap_key
        self.hold_key = hold_key
        self.delay = delay
        self.options = options
        self.kc_map_function = kc_map_function

    def size(self):
        return EKCHoldKey.SIZE

    def to_bytes(self):
        result = bytearray(EKCHoldKey.SIZE)

        option_data = 0

        # _16(KC_HOLD_KEY), \
        # _16(200), \
        # _16(0), \
        # _16(KC_STICKY_LSHIFT), \
        # _16(KC_ENT),
        struct.pack_into("< 5H", result, 0,
            keycodes.KC_HOLD_KEY,
            self.delay,
            option_data,
            self.kc_map_function(self.hold_key),
            self.kc_map_function(self.tap_key)
        )

        return result

    def parse_json(self, keycode_name, json_obj=None, parser_info=None):

        print_warnings = False

        if parser_info == None:
            assert(json_obj != None)
            print_warnings = True
            parser_info = KeyplusParserInfo(
                "<EKCHoldKeycode Dict>",
                {keycode_name : json_obj}
            )
        parser_info.enter(keycode_name)

        # Get the tap key field
        self.keycode = parser_info.try_get(
            'keycode',
            field_type=str
        )
        assert_equal(self.keycode, 'kc_hold')

        # Get the hold key field
        self.hold_key = parser_info.try_get(
            'hold_key',
            type=str
        )

        # Get the tap key field
        self.tap_key = parser_info.try_get(
            'tap_key',
            type=str
        )

        # Get the delay key field
        self.delay = try_get(
            'delay',
            field_type=int,
            default=EKCHoldKey.DEFAULT_DELAY
        )

        # Finish parsing `device_name`
        parser_info.exit()

        # If this is debug code, print the warnings
        if print_warnings:
            for warn in parser_info.warnings:
                print(warn, file=sys.stderr)


class EKCMacroRepeatKey(EKCData):
    pass

# class EKCMacro(EKCData):

#     def __init__(self, macro_data):
#         ekc_format = bytearray()

#         for item in macro_data:
#             if type(item) == dict:
#                 event_type = item[event]
#             elif type(item) == str:


class EKCDataTable(EKCData):
    # def __init__(self, children=[]):
    def __init__(self):
        self.children = []
        self.children_addresses = []
        self.current_size = 0

    def add_child(self, child):
        child_id = len(self.children)
        self.children.append(child)
        self.children_addresses.append(self.current_size)
        self.current_size += child.size()
        return child_id

    def size(self):
        return self.current_size

    def to_bytes(self):
        total_size = self.size()
        if total_size > 0xFFFF:
            raise ValueError("EKC data section too large: {} bytes".format(total_size))

        result = bytearray(0)

        # first byte is the total size of the data
        result += struct.pack('<H', total_size)

        # after append all the children
        for (i, child) in enumerate(self.children):
            result += child.to_bytes()

        return result
    pack = to_bytes

if __name__ == '__main__':
    ekc_data = EKCDataTable()
    ekc_data.add_child(EKCData([1,2,3]))
    sticky_ent = EKCHoldKey(keycodes.KC_ENTER, keycodes.KC_STICKY_LSHIFT)
    ekc_data.add_child(sticky_ent)

    hexdump(ekc_data.to_bytes())
