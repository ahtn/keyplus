#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from layout.common import *

from keyplus.layout.ekc_data import *
import keyplus.keycodes.mapped_keycodes as mapped_keycodes
from keyplus.keycodes.keycodes import *
from keyplus.keycodes.keycode_mapper import KeycodeMapper
from keyplus.layout.parser_info import KeyplusParserInfo
from keyplus.exceptions import *
from keyplus.layout.ekc_data import EKCDataTable

class UserKeycode(object):
    def __init__(self, name, ekc):
        self.name = name
        self.has_been_parsed_before = False
        self.ekc = ekc

class UserKeycodes(object):

    def __init__(self, kc_mapper=None):
        self.user_keycode_table = {}

        if kc_mapper == None:
            self.kc_mapper = KeycodeMapper()
        else:
            self.kc_mapper = kc_mapper
        self.kc_mapper.set_user_keycodes(self)

    def has_keycode(self, kc_name):
        kc_name = kc_name.lower()
        return kc_name in self.user_keycode_table

    def get_ekc_keycode_value(self, kc_name):
        kc_name = kc_name.lower()
        kc = self.user_keycode_table[kc_name]
        return keycodes.generate_external_keycode(kc.ekc.addr)

    def generate_ekc_data(self):
        result = EKCDataTable()

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

    def add_keycode(self, kc_name, json_obj=None, parser_info=None):
        print_warnings = False

        keycode_data = parser_info.peek_field(kc_name)
        if 'keycode' not in keycode_data:
            raise ParseLayoutError(
                "User keycode '{}' must include the 'keycode' field."
                .format(kc_name)
            )

        kc_type = keycode_data['keycode']
        kc_type = kc_type.lower()

        if kc_type == "hold":
            hold_key = EKCHoldKey()
            hold_key.parse_json(kc_name, parser_info=parser_info)
            hold_key.set_keycode_map_function(self.kc_mapper.from_string)

            self.user_keycode_table[kc_name.lower()] = UserKeycode(
                kc_name.lower(),
                ekc = hold_key,
            )
        else:
            raise ParseLayoutError(
                "Unknown keycode type: '{}'".format(kc_type)
            )

    def parse_json(self, json_obj=None, parser_info=None):

        print_warnings = False

        if parser_info == None:
            assert(json_obj != None)
            print_warnings = True
            parser_info = KeyplusParserInfo(
                "<keycodes Dict>",
                {'keycodes' : json_obj}
            )

        parser_info.enter('keycodes')
        for kc_name in parser_info.iter_fields():
            self.add_keycode(
                kc_name = kc_name,
                json_obj = parser_info.try_get(kc_name),
                parser_info = parser_info
            )
        parser_info.exit()
