#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

def u16(x):
    return x & 0xffff

def crc16_step(crc, byte):
    crc_poly = 0x1021

    for n in range(7, -1, -1):
        crc_carry = crc >> 15 # bit that is shifted out of crc
        bit_n = (byte >> n) & 0x01 # next bit of input stream
        if (bit_n ^ crc_carry):
            crc = u16((crc << 1) ^ crc_poly)
        else:
            crc = u16(crc << 1)
    return crc

def crc16_bytes(data):
    crc = 0xffff
    for b in data:
        crc = crc16_step(crc, b)
    return crc

def crc16(data, endaddr=None):
    crc = 0xffff
    if endaddr == None:
        endaddr = len(data)
    for i in range(endaddr):
        crc = crc16_step(crc, data[i])
    return crc

def is_valid_crc16(data, endaddr=None):
    return crc16(data, endaddr) == 0

if __name__ == "__main__":
    import intelhex
    import sys
    hexfile = intelhex.IntelHex()
    hexfile.loadhex("unifying.hex")
    endaddr = hexfile.maxaddr()

    checksum = crc16(hexfile, 0x6800-2)
    # print("crc16", hex(checksum))
    # print("crc16 is valid", is_valid_crc16(hexfile, 0x6800))

    hexfile.write_hex_file(sys.stdout)
