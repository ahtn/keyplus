#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from layout.common import *

from keyplus.layout.ekc_data import *
import keyplus.keycodes.mapped_keycodes as mapped_keycodes
from keyplus.keycodes.keycodes import *
from keyplus.layout.parser_info import KeyplusParserInfo
from keyplus.exceptions import *

class UserKeycode(object):
    def __init__(self, name, data, ekc):
        self.name = name
        self.has_been_parsed_before = False
        self.ekc = ekc
        self.ekc_pos = None

class UserKeycodes(object):

    def __init__(self):
        self.user_keycode_table = {}

    def get_ekc_keycode_value(self, kc_name):
        kc_name = kc_name.lower()
        if kc_name in mapped_keycodes.key_symbols:
            return mapped_keycodes.key_symbols[kc_name]

        if kc_name not in self.user_keycode_table:
            raise ParseLayoutError("Undefined keycode: {}".format(kc_name))

        kc = self.user_keycode_table[kc_name]

        return keycodes.gen_ekc(kc.ekc_pos)

    def generate_ekc_data(self):
        result = EKCDataMain()

        for kc_name in self.user_keycode_table:
            kc = self.user_keycode_table[kc_name]
            result.add_child(kc.ekc)

        return result

    def generate_ekc_position_data(self):
        ekc_pos = 0
        for kc_name in self.user_keycode_table:
            kc = self.user_keycode_table[kc_name]
            if kc.has_been_parsed_before:
                raise ParseLayoutError("Keycode {} evetually calls itself in "
                                       "a recursive loop.".format(kc_name))
            else:
                self.has_been_parsed_before = True

            kc.ekc_pos = ekc_pos
            ekc_pos += kc.ekc.size()

    def add_keycode(self, kc_name, json_obj=None, parse_info=None):
        print_warnings = False

        if not parser_info.has_field(kc_name, 'keycode'):
            raise KeyplusSettingsError("The field 'keycode' must be defined"
                                       "for '{}'.".format(kc_name))

        kc_type = self.peek_field(kc_name, 'keycode')
        kc_type = kc_type.lower()

        if kc_type == "kc_hold":
            hold_key = EKCHoldKey()
            hold_key.parse_json(kc_name, parser_info=parser_info)
            hold_key.set_keycode_map_function(self.get_ekc_keycode_value)

            self.user_keycode_table[kc_name] = UserKeycode(
                kc_name,
                data,
                ekc = hold_key,
            )
