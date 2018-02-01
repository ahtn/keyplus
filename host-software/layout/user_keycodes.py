#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from layout.common import *

from layout.ekc_data import *
import layout.mapped_keycodes as mapped_keycodes

class UserKeycode:
    def __init__(self, name, data, ekc):
        self.name = name
        self.data = data
        self.has_been_parsed_before = False
        self.ekc = ekc
        self.ekc_pos = None

class UserKeycodes:

    def __init__(self, keycode_list_dict):

        self.user_keycode_table = {}

        for entry in keycode_list_dict:
            name = entry.lower()
            data = keycode_list_dict[entry]
            self.add_keycode(name, data)

        self.generate_ekc_position_data()

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

    def add_keycode(self, name, data):
        if type(data) == str:
            # Alias keycode
            raise ParseLayoutError("TODO: implement alias keycodes")

        elif type(data) == dict:
            keycode_dict = data

            kc_type = try_get(
                keycode_dict,
                'keycode',
                hint=name,
                val_type=str
            )
            kc_type = kc_type.lower()

            if kc_type == "kc_hold":
                # Get the tap key field
                tap_key = try_get(
                    keycode_dict,
                    'tap_key',
                    hint=name,
                    val_type=str
                )
                # Get the hold key field
                hold_key = try_get(
                    keycode_dict,
                    'hold_key',
                    hint=name,
                    val_type=str
                )
                # Get the delay key field
                delay = try_get(
                    keycode_dict,
                    'delay',
                    hint=name,
                    val_type=int,
                    default=EKCHoldKey.DEFAULT_DELAY
                )

                self.user_keycode_table[name] = UserKeycode(
                    name,
                    data,
                    ekc = EKCHoldKey(
                        tap_key = tap_key,
                        hold_key = hold_key,
                        delay = delay,
                        kc_map_function=self.get_ekc_keycode_value
                    ),
                )

