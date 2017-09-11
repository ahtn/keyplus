#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

import struct
import easyhid
import intelhex
import math
import time
import hexdump

DEFAULT_MANUFACTUER = 'Xusb'
DEFAULT_PRODUCT = 'Xusb-boot'

DEFAULT_VID = 0x6666
DEFAULT_PID = 0xB007
DEFAULT_INTERFACE = 0

VERSION_MAJOR = 1
VERSION_MINOR = 0

CMD_GET_BOOT_INFO = 0x00
CMD_WRITE = 0x01
CMD_CRC = 0x02
CMD_RESET = 0x03
CMD_ERASE = 0x04

PACKET_ERROR_STATUS  = 0x00
PACKET_CRC  = 0x01

OKAY = 0x00
ERROR = 0x01
ERROR_MISALIGNED = 0x02
ERROR_NOT_ERASED = 0x03

VENDOR_REPORT_SIZE = 64

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


class BootInfo:
    pass

class BootloaderException(Exception):
    pass

def simple_command(device, cmd_id, data=None, receive=True):
    cmd = bytearray(64)
    cmd[0] = cmd_id
    if data != None:
        for (i, data_byte) in enumerate(data):
            cmd[i+1] = data_byte
    response = None
    try:
        device.write(cmd)
        if receive:
            response = device.read()
    except easyhid.HIDException:
        raise BootloaderException("USB read/write error")
    return response

def unpack_status(data):
    pack_type, err_code = struct.unpack_from("<BB", data)
    if (pack_type != PACKET_ERROR_STATUS):
        raise BootloaderException("Unexpected packet type: {}".format(pack_type))
    return err_code

def get_boot_info(device):
    response = simple_command(device, CMD_GET_BOOT_INFO)
    # typedef struct {
    #     uint8_t version_major;
    #     uint8_t version_minor;
    #     char mcu_string[32];
    #     uint32_t flash_size;
    #     uint16_t page_size;
    #     char _reserved[24];
    # } boot_info_t;
    major, minor, mcu, fsize, psize = struct.unpack_from("<BB32sLH", response)
    info = BootInfo()
    info.version_major = major
    info.version_minor = minor
    info.mcu_string = mcu.decode('utf-8').strip('\x00')
    info.flash_size = fsize
    info.page_size = psize
    return info

def erase(device):
    err = unpack_status(simple_command(device, CMD_ERASE))
    if err != OKAY:
        raise BootloaderException("Error erasing flash: {}".format(err))

def reset(device):
    simple_command(device, CMD_RESET, receive=False)


def crc(device):
    response = simple_command(device, CMD_CRC)
    pack_type, app_crc, boot_crc = struct.unpack_from("<BLL", response)
    if pack_type == PACKET_ERROR_STATUS:
        err = response[1]
        if err == ERROR_NOT_ERASED:
            raise BootloaderException("Flash must be erased before computing CRC")
        else:
            raise BootloaderException("Unexpected error status: {}".format(err))
    elif pack_type != PACKET_CRC:
        raise BootloaderException("Unexpected packet type: {}".format(pack_type))
    return (app_crc & 0xFFFFFF, boot_crc & 0xFFFFFF)

def write_start(device, start, size):
    data = bytearray(4 + 4)
    struct.pack_into("<LL", data, 0, start, size)
    response = simple_command(device, CMD_WRITE, data)
    err_code = unpack_status(response)

    if (err_code == ERROR_NOT_ERASED):
        raise BootloaderException("Flash must be erased before write")
    elif (err_code == ERROR_MISALIGNED):
        raise BootloaderException("Write size/position not aligned correctly with page boundaries")
    elif (err_code != OKAY):
        raise BootloaderException("Unexpected error: {}".format(err_code))

def write_data_packet(device, data):
    if (len(data) != VENDOR_REPORT_SIZE):
        raise BootloaderException("Expected {} bytes for data, got: {}".format(
            VENDOR_REPORT_SIZE, len(data)))
    device.write(data)
    err_code = unpack_status(device.read())
    if err_code != OKAY:
        raise BootloaderException("Unexpected error status while writing data: {}".format(
            err_code))

def write_page(device, data, page_size=256):
    assert(page_size % VENDOR_REPORT_SIZE == 0)
    for i in range(0, page_size, VENDOR_REPORT_SIZE):
        write_data_packet(device, data[i:i+VENDOR_REPORT_SIZE])

def write_hexfile(device, hexfile):
    boot_info = get_boot_info(device)

    page_size = boot_info.page_size
    flash_size = boot_info.flash_size
    flash_end = boot_info.flash_size-1
    with open(hexfile) as f:
        ihex = intelhex.IntelHex(f)
        ihex.padding = 0xff
        start = 0
        max_addr = ihex.maxaddr()
        if max_addr > flash_size:
            raise BootloaderException("Hex file to large for flash size. Got {}"
                    " maximum is {}".format(max_addr, flash_size))
        end = int(math.ceil(1.0 * max_addr / page_size)) * page_size

        if end > flash_size:
            raise Exception("Hex file too large: " + str(end))

        hex_data = ihex.tobinarray(0, flash_end)
        hex_crc = xmega_nvm_crc(hex_data)

        erase(device) # must erase before we can write
        write_start(device, start, end) # tell mcu the region to write

        for i in range(start, end, page_size): # handle one page at a time
            data = bytearray(hex_data[i:i+page_size])
            write_page(device, data, page_size)

        app_crc, boot_crc = crc(device)

        if app_crc != hex_crc:
            raise BootloaderException("CRC mismatch: 0x{:06x} != 0x{:06x} ".format(app_crc, hex_crc))

        try:
            reset(device)
        except:
            pass
