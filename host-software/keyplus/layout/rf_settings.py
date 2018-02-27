#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import struct
import sys
import os

from keyplus.utility import *
from keyplus.layout.parser_info import KeyplusParserInfo
from keyplus.exceptions import *
import keyplus.cdata_types

RF_ADDR_WIDTH = 5

RF_DR_LOW = 5
RF_DR_HIGH = 3
RF_DR_250KBPS  = (1 << RF_DR_LOW)
RF_DR_1MBPS    = 0
RF_DR_2MBPS    = (1 << RF_DR_HIGH)

PWR_NEG_18DB = 0x00
PWR_NEG_12DB = 0x01
PWR_NEG_6DB = 0x02
PWR_0DB = 0x03

MAX_RF_CHANNEL = 127

RF_POWER_MAP = {
    '0db': PWR_0DB,
    '-6db': PWR_NEG_6DB,
    '-12db': PWR_NEG_12DB,
    '-18db': PWR_NEG_18DB,
}
RF_DATA_RATE_MAP = {
    '2mbps': RF_DR_2MBPS,
    '1mbps': RF_DR_1MBPS,
    '250kbps': RF_DR_250KBPS,
}


def string_to_bytearray(string):
    try:
        return bytearray.fromhex(string)
    except:
        raise KeyplusParseError("'{}' is not a valid hex string".format(string))

def to_hex_string(value):
    if isinstance(value, int):
        return "{:02x}".format(value)
    elif type(value) in [list, bytearray, bytes]:
        return "".join(["{:02x}".format(byte) for byte in value])

def data_rate_to_str(x):
    for (key, value) in RF_DATA_RATE_MAP.items():
        if x == value:
            return key
    return None

def power_to_str(x):
    for (key, value) in RF_POWER_MAP.items():
        if x == value:
            return key
    return None

class LayoutRFSettings(object):
    def __init__(self):
        self.pipe0 = None
        self.pipe1 = None
        self.pipe2 = None
        self.pipe3 = None
        self.pipe4 = None
        self.pipe5 = 0

        self.channel = None

        self.encryption_key = None

        self.auto_retransmit_count = 15
        self.data_rate = RF_DR_2MBPS
        self.power = PWR_0DB

    def generate_random_channel(self):
        """ Returns a random RF channel """
        channel = MAX_RF_CHANNEL+1
        while channel > MAX_RF_CHANNEL:
            n = int((bytearray(os.urandom(1))[0]))
            channel = 3*n+2
        self.channel = channel

    def generate_random_pipe_addresses(self):
        while True:
            # least significant bytes of address can't match
            pipeBytes = []

            self.pipe0 = bytearray(os.urandom(5))
            self.pipe1 = bytearray(os.urandom(5))
            if self.pipe0 == self.pipe1: continue
            if int(self.pipe0[4]) in [0x55, 0xAA]: continue
            if int(self.pipe1[4]) in [0x55, 0xAA]: continue

            pipeBytes.append(int(self.pipe0[0]))
            pipeBytes.append(int(self.pipe1[0]))

            self.pipe2 = int(bytearray(os.urandom(1))[0])
            self.pipe3 = int(bytearray(os.urandom(1))[0])
            self.pipe4 = int(bytearray(os.urandom(1))[0])
            self.pipe5 = 0

            valid = True
            for pipe in ['pipe2', 'pipe3', 'pipe4', 'pipe5']:
                if getattr(self, pipe) in pipeBytes:
                    valid = False
                else:
                    pipeBytes.append(getattr(self, pipe))

            if not valid:
                continue
            else:
                return

    def check_settings(self):
        """
        Returns a list of error messages strings.
        """
        errors = []

        MAX_ARC = 15
        if self.channel > MAX_RF_CHANNEL:
            errors.append("Channel must be <128, got: {}".format(self.channel))
        if self.auto_retransmit_count > MAX_ARC:
            errors.append("ARC must be <128, got: {}".format(self.auto_retransmit_count))
        if self.power not in RF_POWER_MAP.values():
            errors.append("Power must be <4, got: {}".format(self.power))
        if self.data_rate not in RF_DATA_RATE_MAP.values():
            errors.append("Power must be <4, got: {}".format(self.data_rate))
        # if sum([i == 0 for i in self.encryption_key]) == 16:
        #     errors.append("Warning got null encryption key! {}".format(self.encryption_key))

        if len(errors) != 0:
            msg = "Invalid Settings: " + "\n".join(errors)
            raise KeyplusSettingsError(msg)

    def to_json(self):
        self.check_settings()

        return {
            'pipe0': to_hex_string(self.pipe0),
            'pipe1': to_hex_string(self.pipe1),
            'pipe2': to_hex_string(self.pipe2),
            'pipe3': to_hex_string(self.pipe3),
            'pipe4': to_hex_string(self.pipe4),
            'pipe5': to_hex_string(self.pipe5),
            'aes_encryption_key': to_hex_string(self.encryption_key),
            'rf_channel': self.channel,
            'data_rate': data_rate_to_str(self.data_rate),
            'transmit_power': power_to_str(self.power),
            'auto_retransmit_count': self.auto_retransmit_count
        }

    def load_raw_data(self, rf_settings):
        self.pipe0 = rf_settings.pipe_addr_0
        self.pipe1 = rf_settings.pipe_addr_1
        self.pipe2 = rf_settings.pipe_addr_2
        self.pipe3 = rf_settings.pipe_addr_3
        self.pipe4 = rf_settings.pipe_addr_4
        self.pipe5 = rf_settings.pipe_addr_5
        self.channel = rf_settings.channel;
        self.auto_retransmit_count = rf_settings.arc;
        self.data_rate = rf_settings.data_rate;
        self.power = rf_settings.power;
        self.encryption_key = rf_settings.ekey
        self.check_settings()


    def load_random(self):
        # Generate a random encryption key
        self.encryption_key = bytearray(os.urandom(16))
        self.generate_random_channel()
        self.generate_random_pipe_addresses()

    def parse_json(self, json_obj=None, parser_info=None):
        print_warnings = False

        if parser_info == None:
            assert(json_obj != None)
            print_warnings = True
            parser_info = KeyplusParserInfo(
                "<LayoutRFSettings Dict>",
                {"rf_settings" : json_obj}
            )

        parser_info.enter("rf_settings")

        self.channel = parser_info.try_get(
            "rf_channel",
            field_type = int,
            field_range = [0, MAX_RF_CHANNEL]
        )

        self.encryption_key = parser_info.try_get(
            "aes_encryption_key",
            field_type = str,
            remap_function = string_to_bytearray,
        )

        for field in ['pipe0', 'pipe1']:
            setattr(self, field, parser_info.try_get(
                    field,
                    field_type = str,
                    remap_function = string_to_bytearray,
                )
            )
        for field in ['pipe2', 'pipe3', 'pipe4','pipe5']:
            setattr(self, field, parser_info.try_get(
                    field,
                    field_type = str,
                    remap_function = string_to_bytearray,
                )[0]
            )

        self.data_rate = parser_info.try_get(
            "data_rate",
            field_type = str,
            remap_table = RF_DATA_RATE_MAP
        )

        self.power = parser_info.try_get(
            "transmit_power",
            field_type = str,
            remap_table = RF_POWER_MAP,
        )

        self.auto_retransmit_count = parser_info.try_get(
            "auto_retransmit_count",
            field_type = int,
            field_range = [0, MAX_RF_CHANNEL]
        )

        # Finish parsing `rf_settings`
        parser_info.exit()

        # If this is debug code, print the warnings
        if print_warnings:
            for warn in parser_info.warnings:
                print(warn, file=sys.stderr)

    def generate_rf_settings(self):
        result = keyplus.cdata_types.rf_settings_t()

        # pipes 0-1
        result.pipe_addr_0 = list(self.pipe0)
        result.pipe_addr_1 = list(self.pipe1)
        result.pipe_addr_2 = self.pipe2
        result.pipe_addr_3 = self.pipe3
        result.pipe_addr_4 = self.pipe4
        result.pipe_addr_5 = self.pipe5

        result.channel = self.channel
        result.arc = self.auto_retransmit_count
        result.data_rate = self.data_rate
        result.power = self.power

        decryption_key = list(gen_final_round_key(self.encryption_key))
        result.ekey = list(self.encryption_key)
        result.dkey = decryption_key

        return result

    def to_bytes(self):
        return self.generate_rf_settings().pack()
