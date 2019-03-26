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
    def __init__(self, data=None, addr=None):
        self.data = data
        self.addr = addr

    def set_keycode_map_function(self, kc_map_function):
        self.kc_map_function = kc_map_function

    def size(self):
        return len(self.data)

    # def to_bytes(self):
    #     return bytearray(self.data)

    # def parse_json(self):
    #     pass


class EKCMouseGestureKey(EKCData):
    # Data: {
    #    0x00: KC_MOUSE_GESTURE
    #    0x02: threshold
    #    0x04: threshold_diag
    #    0x06: threshold_tap
    #    0x08: keycode left
    #    0x0A: keycode right
    #    0x0C: keycode up
    #    0x0E: keycode down
    #    0x10: keycode up_left
    #    0x12: keycode up_right
    #    0x14: keycode down_left
    #    0x16: keycode down_right
    #    0x18: keycode tap
    # }
    SIZE =  13*2

    # Threshold for Horizontal and Vertical mouse gestures
    GESTURE_THRESHOLD = 110

    # Threshold for Diagonal mouse gestures
    GESTURE_THRESHOLD_DIAG = 60

    # Threshold for tap mouse gesture.  The mouse has to move less than this
    # amount in both the X and Y axes to trigger a tap gesture.
    GESTURE_THRESHOLD_TAP = 20

    def __init__(self):
        self.threshold = EKCMouseGestureKey.GESTURE_THRESHOLD
        self.threshold_diag = EKCMouseGestureKey.GESTURE_THRESHOLD_DIAG
        self.threshold_tap = EKCMouseGestureKey.GESTURE_THRESHOLD_TAP

        self.kc_left = None
        self.kc_right = None
        self.kc_up = None
        self.kc_down = None

        self.kc_up_left = None
        self.kc_up_right = None
        self.kc_down_left = None
        self.kc_down_right = None

        self.kc_tap = None

    def size(self):
        return self.SIZE

    def to_bytes(self):
        result = bytearray(self.SIZE)

        struct.pack_into("< 13H", result, 0,
            keycodes.KC_MOUSE_GESTURE,
            self.threshold,
            self.threshold_diag,
            self.threshold_tap,
            self.kc_map_function(self.kc_left),
            self.kc_map_function(self.kc_right),
            self.kc_map_function(self.kc_up),
            self.kc_map_function(self.kc_down),
            self.kc_map_function(self.kc_up_left),
            self.kc_map_function(self.kc_up_right),
            self.kc_map_function(self.kc_down_left),
            self.kc_map_function(self.kc_down_right),
            self.kc_map_function(self.kc_tap),
        )

        return result

    def parse_json(self, kc_name, json_obj=None, parser_info=None):

        print_warnings = False

        if parser_info == None:
            assert(json_obj != None)
            print_warnings = True
            parser_info = KeyplusParserInfo(
                "<EKCMouseGestureKey Dict>",
                {kc_name : json_obj}
            )

        parser_info.enter(kc_name)

        # Get the tap key field
        self.keycode = parser_info.try_get(
            'keycode',
            field_type=str
        )
        assert_equal(self.keycode, 'mouse_gesture')

        # Get movement thresholds for gestures
        self.threshold = parser_info.try_get(
            'threshold',
            field_type=int,
            default=EKCMouseGestureKey.GESTURE_THRESHOLD
        )
        self.threshold_diag = parser_info.try_get(
            'threshold_diag',
            field_type=int,
            default=EKCMouseGestureKey.GESTURE_THRESHOLD_DIAG
        )
        self.threshold_tap = parser_info.try_get(
            'threshold_tap',
            field_type=int,
            default=EKCMouseGestureKey.GESTURE_THRESHOLD_TAP
        )

        # Get the keycodes for different directions field
        self.kc_left  = parser_info.try_get('left' , default='none')
        self.kc_right = parser_info.try_get('right', default='none')
        self.kc_up    = parser_info.try_get('up'   , default='none')
        self.kc_down  = parser_info.try_get('down' , default='none')

        self.kc_up_left    = parser_info.try_get('up_left'   , default='none')
        self.kc_up_right   = parser_info.try_get('up_right'  , default='none')
        self.kc_down_left  = parser_info.try_get('down_left' , default='none')
        self.kc_down_right = parser_info.try_get('down_right', default='none')

        self.kc_tap = parser_info.try_get('tap', default='none')

        # Finish parsing `device_name`
        parser_info.exit()

        # If this is debug code, print the warnings
        if print_warnings:
            for warn in parser_info.warnings:
                print(warn, file=sys.stderr)



class EKCHoldKey(EKCData):
    # Layout option:
    #   1: kc_hold_key
    #   1: delay
    #   1: option_data
    #   1: hold_key
    #   1: tap_key

    SIZE = 5 * 2

    DEFAULT_DELAY = 200
    DEFAULT_ACTIVATE_TYPE = 'delay'

    HOLD_KEY_ACTIVATE_DELAY     =  (1 << 0)
    HOLD_KEY_ACTIVATE_OTHER_KEY =  (1 << 1)

    ACTIVATE_TYPE_MAP = {
        'delay': (1 << 0),
        'other_key': (1 << 1),
    }


    def __init__(self, tap_key=None, hold_key=None, delay=200,
                 activate_type=None, kc_map_function=None):
        self.tap_key = tap_key
        self.hold_key = hold_key
        self.delay = delay
        self.kc_map_function = kc_map_function
        self.activate_type = activate_type or EKCHoldKey.DEFAULT_ACTIVATE_TYPE

    def size(self):
        return self.SIZE

    def check_activate_type_valid(self, type_):
        if type_ not in EKCHoldKey.ACTIVATE_TYPE_MAP:
            raise KeyplusSettingsError(
                "Unknown 'activate_type', got '{}', but expected one of: {}"
                .format(
                    self.activate_type,
                    list(EKCHoldKey.ACTIVATE_TYPE_MAP.keys())
                )
            )

    def to_bytes(self):
        result = bytearray(self.SIZE)

        option_data = 0

        self.check_activate_type_valid(self.activate_type)

        option_data |= EKCHoldKey.ACTIVATE_TYPE_MAP[self.activate_type]

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

    def parse_json(self, kc_name, json_obj=None, parser_info=None):

        print_warnings = False

        if parser_info == None:
            assert(json_obj != None)
            print_warnings = True
            parser_info = KeyplusParserInfo(
                "<EKCHoldKeycode Dict>",
                {kc_name : json_obj}
            )

        parser_info.enter(kc_name)

        # Get the tap key field
        self.keycode = parser_info.try_get(
            'keycode',
            field_type=str
        )
        assert_equal(self.keycode, 'hold')

        # Get the hold key field
        self.hold_key = parser_info.try_get('hold_key')

        # Get the tap key field
        self.tap_key = parser_info.try_get('tap_key')

        # Get the delay key field
        self.delay = parser_info.try_get(
            'delay',
            field_type=int,
            default=EKCHoldKey.DEFAULT_DELAY
        )

        # Get the delay key field
        self.activate_type = parser_info.try_get(
            'activate_type',
            field_type=str,
            field_valid_values=EKCHoldKey.ACTIVATE_TYPE_MAP.keys(),
            default=EKCHoldKey.DEFAULT_ACTIVATE_TYPE,
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
        child.addr = self.current_size
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

EKCKeycodeTable = {
    'hold': EKCHoldKey,
    'mouse_gesture': EKCMouseGestureKey,
}

if __name__ == '__main__':
    ekc_data = EKCDataTable()
    ekc_data.add_child(EKCData([1,2,3]))
    sticky_ent = EKCHoldKey(keycodes.KC_ENTER, keycodes.KC_STICKY_LSHIFT)
    ekc_data.add_child(sticky_ent)

    hexdump(ekc_data.to_bytes())
