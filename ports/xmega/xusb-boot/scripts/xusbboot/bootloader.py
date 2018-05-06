#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import struct
import easyhid
import intelhex
import math
from collections import namedtuple

import xusbboot.crc as crc
from xusbboot.constants import *

BootInfo = namedtuple(
    "BootInfo",
    "version_major "
    "version_minor "
    "mcu_string "
    "flash_size "
    "page_size "
)

class XUSBBootloaderException(Exception):
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
        raise XUSBBootloaderException("USB read/write error")
    return response

def unpack_status(data):
    pack_type, err_code = struct.unpack_from("<BB", data)
    if (pack_type != PACKET_ERROR_STATUS):
        raise XUSBBootloaderException("Unexpected packet type: {}".format(pack_type))
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
    info = BootInfo(
        version_major = major,
        version_minor = minor,
        mcu_string = mcu.decode('utf-8').strip('\x00'),
        flash_size = fsize,
        page_size = psize,
    )
    return info

def erase(device):
    err = unpack_status(simple_command(device, CMD_ERASE))
    if err != OKAY:
        raise XUSBBootloaderException("Error erasing flash: {}".format(err))

def reset(device):
    simple_command(device, CMD_RESET, receive=False)

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

def write_start(device, start, size):
    data = bytearray(4 + 4)
    struct.pack_into("<LL", data, 0, start, size)
    response = simple_command(device, CMD_WRITE, data)
    err_code = unpack_status(response)

    if (err_code == ERROR_NOT_ERASED):
        raise XUSBBootloaderException("Flash must be erased before write")
    elif (err_code == ERROR_MISALIGNED):
        raise XUSBBootloaderException("Write size/position not aligned correctly with page boundaries")
    elif (err_code != OKAY):
        raise XUSBBootloaderException("Unexpected error: {}".format(err_code))

def write_data_packet(device, data):
    if (len(data) != VENDOR_REPORT_SIZE):
        raise XUSBBootloaderException("Expected {} bytes for data, got: {}".format(
            VENDOR_REPORT_SIZE, len(data)))
    device.write(data)
    err_code = unpack_status(device.read())
    if err_code != OKAY:
        raise XUSBBootloaderException("Unexpected error status while writing data: {}".format(
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
        end = int(math.ceil(ihex.maxaddr() / page_size)) * page_size
        if end > flash_size:
            raise XUSBBootloaderException("Hex file to large for flash size. Got {}"
                    " maximum is {}".format(ihex.maxaddr(), flash_size))

        hex_data = ihex.tobinarray(0, flash_end)
        hex_crc = crc.xmega_nvm_crc(hex_data)

        erase(device) # must erase before we can write
        write_start(device, start, end) # tell mcu the region to write

        for i in range(start, end, page_size): # handle one page at a time
            data = bytearray(hex_data[i:i+page_size])
            write_page(device, data, page_size)

        app_crc, boot_crc = compute_crc(device)

        if app_crc != hex_crc:
            raise XUSBBootloaderException("CRC mismatch: 0x{:06x} != 0x{:06x} ".format(app_crc, hex_crc))

        try:
            reset(device)
        except:
            pass
