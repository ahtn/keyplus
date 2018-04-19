#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from copy import copy
from colorama import Fore, Style

import six

from keyplus.keycodes import *
from keyplus.exceptions import KeyplusParseError

class KeycodeMapper(object):
    def __init__(self):
        self.symbol_to_keycode_map = copy(SYMBOL_TO_KEYCODE_MAP)
        self.keycode_to_symbol_map = self.build_inverse_keycode_map(SYMBOL_TO_KEYCODE_MAP)
        self.user_keycodes = None

    def set_user_keycodes(self, user_keycodes):
        self.user_keycodes = user_keycodes

    def build_inverse_keycode_map(self, keycode_map, inverse_override=None):
        """
        Create an inverse mapping from keycodes (integers) to keycode names
        (strings). If there are multiple names for the same keycode, then use
        the shortest one.
        """
        inverse_map = {}
        inverse_override = inverse_override or INVERSE_OVERIDE_MAP
        for keycode_name in keycode_map:
            keycode = keycode_map[keycode_name]
            if keycode in inverse_override:
                inverse_map[keycode] = inverse_override[keycode]
            elif keycode in inverse_map:
                if len(keycode_name) < len(inverse_map[keycode]):
                    inverse_map[keycode] = keycode_name
            else:
                inverse_map[keycode] = keycode_name
        return inverse_map

    def get_keycode_type(self, keycode):
        if not isinstance(keycode, six.integer_types):
            raise KeyplusParseError("keycode must be an int")
        if keycode < 0 or keycode > 0xffff:
            raise KeyplusParseError("keycode must be a 16 bit integer")

        return (keycode & KC_TYPE_MASK) >> 12

    def modkey_to_string(self, modkey_kc):
        result = ''
        ctrl = modkey_kc & MODKEY_TAG_CTL
        shift = modkey_kc & MODKEY_TAG_SFT
        alt = modkey_kc & MODKEY_TAG_ALT
        gui = modkey_kc & MODKEY_TAG_GUI
        right = modkey_kc & MODKEY_TAG_RIGHT
        force = modkey_kc & MODKEY_TAG_FORCE

        # Construct the modifier section
        if force:
            result += 'f'
        if right:
            result += 'r'
        if gui:
            result += 'g'
        if alt:
            result += 'a'
        if shift:
            result += 's'
        if ctrl:
            result += 'c'

        if result != '':
            result += '-'

        result += self.keycode_to_string(modkey_kc & HID_KEYCODE_MASK)

        return result


    def keycode_to_string(self, keycode):
        assert(isinstance(keycode, six.integer_types))
        assert(0 <= keycode <= 0xffff)

        if keycode in self.keycode_to_symbol_map:
            return self.keycode_to_symbol_map[keycode]

        kc_type = self.get_keycode_type(keycode)

        if kc_type in [
            KC_TYPE_L_MODKEY,
            KC_TYPE_R_MODKEY,
            KC_TYPE_L_MODKEY_FORCE,
            KC_TYPE_R_MODKEY_FORCE
        ]:
            return self.modkey_to_string(keycode)
        elif kc_type == KC_TYPE_SPECIAL:
            pass
        elif kc_type == KC_TYPE_EKC:
            pass
        else:
            raise KeyplusParseError("Unknown keycode format")

    def from_string(self, kc_in):
        kc_str = str(kc_in).lower()

        if self.user_keycodes and self.user_keycodes.has_keycode(kc_str):
            return self.user_keycodes.get_ekc_keycode_value(kc_str)

        if kc_str in SYMBOL_TO_KEYCODE_MAP:
            return SYMBOL_TO_KEYCODE_MAP[kc_str]
        elif "-" in kc_str:
            if kc_str.count('-') > 2:
                raise KeyplusParseError("Too many '-' in keycode: '{}'".format(kc_str))
            if kc_str.count('-') == 2:
                if kc_str.count('--') != 1 or kc_str[-1] != '-' or kc_str == "--":
                    raise KeyplusParseError("Couldn't handle keycode: '{}'".format(kc_str))
            mods, kc = kc_str.split("-", 1)
            ctrl = False
            shift = False
            alt = False
            gui = False
            right = False
            left = False
            force = False
            for mod in mods:
                if mod == 'c' and not ctrl:
                    ctrl = True
                elif mod == 's' and not shift:
                    shift = True
                elif mod == 'a' and not alt:
                    alt = True
                elif mod == 'g' or mod == 'w' or mod == 'm' and not gui:
                    gui = True
                elif mod == 'r' and not (right or left):
                    right = True
                elif mod == 'l' and not (right or left):
                    left = True
                elif mod == 'f':
                    force = True
                else:
                    raise KeyplusParseError("Unexpected or duplicate character in mods mask: '{}'".format(mod))
            kc = self.from_string(kc)
            return generate_modkey(kc, ctrl=ctrl, shift=shift, alt=alt, gui=gui, right=right, force=force)
        else:
            # TODO: need to add back support for external keycodes, but
            # for now use KC_NONE as a placeholder
            print(
                Fore.RED + "Warning: " + Style.RESET_ALL +
                " ignoring keycode: " + kc_str
            )
            return KC_NONE
            # TODO:  add this exception back in
            # raise KeyplusParseError("Unexpected keycode: '{}'".format(kc_in))
