#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

# Convenience functions for operating with unsigned integer types
def u32(x):
    return x & 0xffffffff

def u24(x):
    return x & 0xffffff

def u16(x):
    return x & 0xffff

def u8(x):
    return x & 0xff

# The NVM controller for the xmega uses its own custom 24 bit CRC. This CRC is
# different from the CRC16 and CRC32 used by the its CRC engine.
def xmega_nvm_crc_word(crc, word, poly=0x80001b):
    crc_carry = (crc >> 23) & 0x01 # bit that is shifted out of crc
    if (crc_carry):
        crc = u24((crc << 1) ^ poly)
    else:
        crc = u24(crc << 1)
    crc = crc ^ word
    return crc

def xmega_nvm_crc(data):
    crc = 0
    data_iter = iter(data)
    for byte in data_iter:
        # the nvm CRC operates on words, not bytes
        next_byte = next(data_iter)
        word = u16((next_byte << 8) | (byte << 0))
        crc = xmega_nvm_crc_word(crc, word)
    return crc

# WARNING: This is NOT the CRC used by the NVM when it generates a crc for the
# app/boot section. The NVM uses a different 24-bit CRC. The code is left here
# to show the difference
def calc_crc32_byte(crc, byte, poly=0x04C11DB7):
    for n in range(8):
        crc_msb = (crc >> 31) & 0x01
        bit_n = (byte >> n) & 0x01 # next bit of input stream
        if (bit_n ^ crc_msb):
            crc = u32((crc << 1) ^ poly)
        else:
            crc = u32(crc << 1)
    return crc

def reverse32(x):
    x = ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555)
    x = ((x & 0x33333333) << 2) | ((x >> 2) & 0x33333333)
    x = ((x & 0x0F0F0F0F) << 4) | ((x >> 4) & 0x0F0F0F0F)
    x = (x << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | (x >> 24)
    return u32(x)

def calc_crc32(data):
    crc = 0xFFFFFFFF
    for byte in data:
        crc = calc_crc32_byte(crc, byte)
    return reverse32(~crc)

def compute_crc(device):
    response = simple_command(device, CMD_CRC)
    pack_type, app_crc, boot_crc = struct.unpack_from("<BLL", response)
    if pack_type == PACKET_ERROR_STATUS:
        err = response[1]
        if err == ERROR_NOT_ERASED:
            raise XUSBBootloaderException("Flash must be erased before computing CRC")
        else:
            raise XUSBBootloaderException("Unexpected error status: {}".format(err))
    elif pack_type != PACKET_CRC:
        raise XUSBBootloaderException("Unexpected packet type: {}".format(pack_type))
    return (app_crc & 0xFFFFFF, boot_crc & 0xFFFFFF)

