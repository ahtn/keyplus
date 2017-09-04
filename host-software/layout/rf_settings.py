#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import struct, os
import yaml

from layout.common import try_get, ParseError, bytes_from_hex, check_range

import layout.round_keys as round_keys

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

MAX_CHANNEL = 127

class RFSettings:
    PowerStrMap = {
        '0db': PWR_0DB,
        '-6db': PWR_NEG_6DB,
        '-12db': PWR_NEG_12DB,
        '-18db': PWR_NEG_18DB,
    }
    DataRateStrMap = {
        '2mbps': RF_DR_2MBPS,
        '1mbps': RF_DR_1MBPS,
        '250kbps': RF_DR_250KBPS,
    }

    def __init__(self):

        self.pipe0 = None
        self.pipe1 = None
        self.pipe2 = None
        self.pipe3 = None
        self.pipe4 = None
        self.pipe5 = 0

        self.channel = None

        self.ekey = None

        self.arc = 8
        self.data_rate = RF_DR_2MBPS
        self.power = PWR_0DB

    def from_rand():
        result = RFSettings()
        result.ekey = os.urandom(16)
        x = MAX_CHANNEL+1
        while not x <= MAX_CHANNEL:
            n = int(os.urandom(1)[0])
            x = 3*n+2
        result.channel = x

        while True:
            # least significant bytes of address can't match
            pipeBytes = []

            result.pipe0 = os.urandom(5)
            result.pipe1 = os.urandom(5)
            if result.pipe0 == result.pipe1: continue
            if int(result.pipe0[4]) in [0x55, 0xAA]: continue
            if int(result.pipe1[4]) in [0x55, 0xAA]: continue

            pipeBytes.append(int(result.pipe0[0]))
            pipeBytes.append(int(result.pipe1[0]))

            result.pipe2 = int(os.urandom(1)[0])
            result.pipe3 = int(os.urandom(1)[0])
            result.pipe4 = int(os.urandom(1)[0])
            result.pipe5 = 0

            valid = True
            for pipe in ['pipe2', 'pipe3', 'pipe4', 'pipe5']:
                if getattr(result, pipe) in pipeBytes:
                    valid = False
                else:
                    pipeBytes.append(getattr(result, pipe))

            if not valid:
                continue
            else:
                break;

        return result



    def from_json_obj(json_obj):
        result = RFSettings()

        rf_data = try_get(json_obj, "rf_settings")
        # pipes 0-1
        for pipe in ['pipe0', 'pipe1']:
            # bytes are stored in big endian
            data = bytes_from_hex(try_get(rf_data, pipe))
            if len(data) != RF_ADDR_WIDTH:
                raise ParseError("Expected '{}' to be {} byte(s) long", data, RF_ADDR_WIDTH)
            setattr(result, pipe, data)


        # pipes 2-5
        for pipe in ['pipe2', 'pipe3', 'pipe4', 'pipe5']:
            data = int(try_get(rf_data, pipe), base=16)
            check_range(data, pipe, 0, 255)
            setattr(result, pipe, data)

        # channel
        channel = try_get(rf_data, 'rf_channel', val_type=int)
        if channel < 0 or channel > 255:
            raise ParseError("Expected 'rf_channel' to be in range 0-255")
        result.channel = channel

        # arc
        arc = try_get(rf_data, 'auto_retransmit_count', val_type=int)
        check_range(arc, 'auto_retransmit_count', 0, 15)
        result.arc = arc

        # data rate
        data_rate = try_get(rf_data, 'data_rate')
        if data_rate in RFSettings.DataRateStrMap:
            data_rate = RFSettings.DataRateStrMap[data_rate]
        else:
            raise ParseError("Unexpected value '{}' for 'data_rate'".format(data_rate))
        result.data_rate = data_rate

        # power
        power = try_get(rf_data, 'transmit_power')
        if power in RFSettings.PowerStrMap:
            power = RFSettings.PowerStrMap[power]
        else:
            raise ParseError("Unexpected value '{}' for 'transmit_power'".format(power))
        result.power = power

        # reserved[14]
        result.reserved = bytearray(14)

        # aes encryption key and the final round key data for decryption
        aes_ekey = bytes_from_hex(try_get(rf_data, 'aes_encryption_key'))
        result.ekey = aes_ekey

        return result

    def frombytes(data):
        # uint8_t pipe_addr_0[NRF_ADDR_LEN];
        # uint8_t pipe_addr_1[NRF_ADDR_LEN];
        # uint8_t pipe_addr_2;
        # uint8_t pipe_addr_3;
        # uint8_t pipe_addr_4;
        # uint8_t pipe_addr_5;
        # uint8_t channel; // TODO: when using unifying, channel must be (ch%3 == 0)
        #                 // this should be enforced somewhere/somehow
        # uint8_t arc;
        # uint8_t data_rate;
        # uint8_t power;
        # uint8_t _reserved[14]; // pad to 32 bytes
        # uint8_t ekey[AES_KEY_LEN];
        # uint8_t dkey[AES_KEY_LEN];

        assert(len(data == 32))

        DeviceSettingsRaw = collections.namedtuple("KBInfoFirmware",
            """
            pipe0 pipe1 pipe2 pipe2 pipe3 pipe4 pipe5
            channel arc data_rate power reserved
            ekey dkey
            """
        )

        x = struct.unpack("< 5s 8B 14s 16s 16s" , data)
        x = KBInfoFirmware._make(x)
        result = RFSettings()
        result.pipe0 = x.pipe0
        result.pipe1 = x.pipe1
        result.pipe2 = x.pipe2
        result.pipe3 = x.pipe3
        result.pipe4 = x.pipe4
        result.pipe5 = x.pipe5

        result.channel = x.channel
        result.arc = x.arc
        result.data_rate = x.data_rate
        result.power = x.power
        result._reserved = x._reserved
        result.ekey = x.ekey
        # result.dkey = x.dkey # don't need this

    def to_bytes(self):
        # uint8_t pipe_addr_0[NRF_ADDR_LEN];
        # uint8_t pipe_addr_1[NRF_ADDR_LEN];
        # uint8_t pipe_addr_2;
        # uint8_t pipe_addr_3;
        # uint8_t pipe_addr_4;
        # uint8_t pipe_addr_5;
        # uint8_t channel; // TODO: when using unifying, channel must be (ch%3 == 0)
        #                 // this should be enforced somewhere/somehow
        # uint8_t arc;
        # uint8_t data_rate;
        # uint8_t power;
        # uint8_t _reserved[14]; // pad to 32 bytes
        # uint8_t ekey[AES_KEY_LEN];
        # uint8_t dkey[AES_KEY_LEN];
        result = bytearray(0)

        # pipes 0-1
        for pipe in ['pipe0', 'pipe1']:
            result += getattr(self, pipe)

        # pipes 2-5
        for pipe in ['pipe2', 'pipe3', 'pipe4', 'pipe5']:
            result += struct.pack('<B', getattr(self, pipe))

        # channel
        result += struct.pack('<B', self.channel)

        # arc
        result += struct.pack('<B', self.arc)

        # data rate
        result += struct.pack('<B', self.data_rate)

        # power
        result += struct.pack('<B', self.power)

        # reserved[14]
        result += bytearray(14)

        # aes encryption key and the final round key data for decryption
        # dkey = gen_final_round_key(self.ekey)
        dkey = round_keys.gen_final_round_key(self.ekey)
        result += self.ekey
        result += dkey

        return result

    def data_rate_to_str(x):
        for (key, value) in RFSettings.DataRateStrMap.items():
            if x == value:
                return key
        return None

    def power_to_str(x):
        for (key, value) in RFSettings.PowerStrMap.items():
            if x == value:
                return key
        return None

    def to_json_obj(self):
        error_msgs = self.checkSettings()
        if len(error_msgs) != 0:
            msg = "Invalid Settings: " + "\n".join(error_msgs)
            raise ParseError(msg)


        return {
            'rf_settings': {
                'pipe0': self.pipe0.hex(),
                'pipe1': self.pipe1.hex(),
                'pipe2': "{:02x}".format(self.pipe2),
                'pipe3': "{:02x}".format(self.pipe3),
                'pipe4': "{:02x}".format(self.pipe4),
                'pipe5': "{:02x}".format(self.pipe5),
                'aes_encryption_key': self.ekey.hex(),
                'rf_channel': self.channel,
                'data_rate': RFSettings.data_rate_to_str(self.data_rate),
                'power': RFSettings.power_to_str(self.power),
            }
        }

    def to_yaml(self):
        return yaml.dump(self.to_json_obj(), default_flow_style=False)


    def checkSettings(self):
        """
        Returns a list of error messages strings.
        """
        result = []

        MAX_ARC = 15
        if self.channel > MAX_CHANNEL:
            result.append("Channel must be <128, got: {}".format(self.channel))
        if self.arc > MAX_ARC:
            result.append("ARC must be <128, got: {}".format(self.arc))
        if self.power not in RFSettings.PowerStrMap.values():
            result.append("Power must be <4, got: {}".format(self.power))
        if self.data_rate not in RFSettings.DataRateStrMap.values():
            result.append("Power must be <4, got: {}".format(self.data_rate))
        if sum([i == 0 for i in self.ekey]) == 16:
            result.append("Warning got null encryption key! {}".format(self.ekey))

        return result


