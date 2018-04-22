#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import usb.core
import usb.util
import usb.control
import time
import sys

import intelhex
import crc16

from array import array
import hexdump
from btool import *


VID_LOGITECH = 0x046d
PID_UNIFYING = 0xc52b

PID_NRF24_1 = 0xaaaa # nRF24LU1+
PID_NRF24_2 = 0xaaae

NRF_PIDS = [
    PID_NRF24_1,
    PID_NRF24_2,
]

PID_BOOTLOADER_TI_1 = 0xaaac # TI CC2544
PID_BOOTLOADER_TI_2 = 0xaaad # TI CC2544

# Can find PID's for bootloaders here: https://github.com/Logitech/fw_updates
TI_PIDS = [
    PID_BOOTLOADER_TI_1,
    PID_BOOTLOADER_TI_2,
]

debug = True

# def usb_setup():
# dev = usb.core.find()

def detach_kernel_drivers(dev, intf_list):
    for i in intf_list:
        if dev.is_kernel_driver_active(i):
            dev.detach_kernel_driver(i)

def reattach_kernel_drivers(dev, intf_list):
    for i in intf_list:
        if not dev.is_kernel_driver_active(i):
            dev.attach_kernel_driver(i)

GET_REPORT      = 0x01
GET_IDLE        = 0x02
GET_PROTOCOL    = 0x03
SET_REPORT      = 0x09
SET_IDLE        = 0x0a
SET_PROTOCOL    = 0x0b

HOST_TO_DEVICE = 0
DEVICE_TO_HOST = 1
TYPE_STANDARD = 0
TYPE_CLASS = 1
TYPE_VENDOR = 2
TYPE_RESERVED = 3
RECIPIENT_DEVICE = 0
RECIPIENT_INTERFACE = 1
RECIPIENT_ENDPOINT = 2
RECIPIENT_OTHER = 3

REPORT_INPUT = 0x01
REPORT_OUTPUT = 0x02
REPORT_FEATURE = 0x03

def request_type(direction, req_type, recipient):
    return ((0x01 & direction) << 7) | ((0x03 & req_type) << 5) | ((0x1f & recipient) << 0)

def get_report_wValue(type_, id_):
    return ((type_) << 8)| (0xff & id_)

def set_report_request(dev, report_id, interface, data):
    bmRequestType = request_type(HOST_TO_DEVICE, TYPE_CLASS, RECIPIENT_INTERFACE)
    wValue = get_report_wValue(REPORT_OUTPUT, report_id)
    return dev.ctrl_transfer(bmRequestType, SET_REPORT, wValue, interface, data)

def get_report_request(dev, report_id, interface, length):
    bmRequestType = request_type(DEVICE_TO_HOST, TYPE_CLASS, RECIPIENT_INTERFACE)
    wValue = get_report_wValue(REPORT_INPUT, report_id)
    return dev.ctrl_transfer(bmRequestType, GET_REPORT, wValue, interface, length)


def enter_icp():
    report_id = 0x10
    interface = 0x02

    test_data_1 = [report_id, 0xff, 0x81, 0xf1, 0x01, 0x00, 0x00]
    test_data_2 = [report_id, 0xff, 0x81, 0xf1, 0x02, 0x00, 0x00]
    test_data_3 = [report_id, 0xff, 0x81, 0xf1, 0x03, 0x00, 0x00]
    test_data_4 = [report_id, 0xff, 0x81, 0xf1, 0x04, 0x00, 0x00]

    reset_icp = [report_id, 0xff, 0x80, 0xf0, 0x49, 0x43, 0x50]

    dev = usb.core.find(idVendor=VID_LOGITECH, idProduct=PID_UNIFYING)
    detach_kernel_drivers(dev, [0, 1, 2])
    def print_response(ep):
        hexdump.hexdump(ep.read(64))


    # if dev.is_kernel_driver_active(1):

    cfg = dev.get_active_configuration()
    intf = cfg[(2,0)]
    ep3in = intf.endpoints()[0]
    print(ep3in)


    set_report_request(dev, report_id, interface, test_data_1)
    print_response(ep3in)

    set_report_request(dev, report_id, interface, test_data_2)
    print_response(ep3in)

    set_report_request(dev, report_id, interface, test_data_3)
    print_response(ep3in)

    set_report_request(dev, report_id, interface, test_data_4)
    print_response(ep3in)

    set_report_request(dev, report_id, interface, reset_icp)
    # print_response(ep3in)


CMD_INFO_PAGE        = 0x10
CMD_WRITE            = 0x20
CMD_ERASE_PAGE       = 0x30
CMD_GET_MCU_STR      = 0x40
CMD_50               = 0x50
CMD_SUM16            = 0x60
CMD_RESET            = 0x70
CMD_BOOTLOADER_INFO  = 0x80
CMD_90               = 0x90
CMD_A0               = 0xa0

REPORT_LEN = 32

def b(data):
    return array('B', data)

# # if True:
# time.sleep(0.2)

class PacketPrinter:
    def __init__(self):
        self.count = 0

    def print(self, packet):
        print("Packet{}:".format(self.count))
        hexdump.hexdump(packet)
        self.count += 1

class BootloaderError(Exception):
    def __init__(self, message):
        self.message = message

class BadCommandOrder(BootloaderError):
    pass

class TooMuchData(BootloaderError):
    pass

class WriteFailed(BootloaderError):
    pass

class EraseFailed(BootloaderError):
    pass

class HexfileTooBig(BootloaderError):
    pass

class BadCRC16(BootloaderError):
    pass

class UnsupportedMCU(BootloaderError):
    pass


PAGE_SIZE = 0x200
BOOT_IN_EP = 0x81
PACKET_SIZE = 0x20
MAX_PROGRAMMABLE_ADDR = 0x67ff
MAX_PROGRAMMABLE_PAGE = MAX_PROGRAMMABLE_ADDR // PAGE_SIZE

class BootloaderWriter:
    MAX_WRITE_PACKET_SIZE = PACKET_SIZE-4
    def __init__(self, dev):
        self.has_erased_page0 = False
        self.dev = dev

    def send_packet(self, packet):
        set_report_request(self.dev, 0, 0, packet)

    def recv_packet(self):
        return self.dev.read(BOOT_IN_EP, PACKET_SIZE)

    def create_cmd_packet(self, cmd_id, data=[]):
        if len(data) > REPORT_LEN:
            raise "cmd data too long ({} bytes) for report".format(len(data))
        padding = [0x00]*(REPORT_LEN - 1 - len(data))
        return  b([cmd_id]) + b(data) + b(padding)

    def simple_cmd(self, cmd_code):
        cmd_packet = self.create_cmd_packet(cmd_code)
        self.send_packet(cmd_packet)
        return self.recv_packet()

    def cmd_bootloader_info(self):
        response = self.simple_cmd(CMD_BOOTLOADER_INFO)
        self.min_addr = big_endian_u16(response[4:6])
        self.max_addr = big_endian_u16(response[6:8])
        self.page_size = big_endian_u16(response[8:10])
        return (self.min_addr, self.max_addr, self.page_size)

    def cmd_sum16(self):
        return self.simple_cmd(CMD_SUM16)

    def cmd_get_mcu_str(self):
        data = self.simple_cmd(CMD_GET_MCU_STR)
        # hexdump.hexdump(data)

        # todo add error messages
        if len(data) == 0:
            raise Exception;
        if data[0] != 0x40 or data[1] != 0x00 or data[2] != 0x00:
            raise Exception("usb cmd returned error {}".format(data[0:3]));
        # if data[3] > 0x10:
        #     raise Exception;
        str_len = data[3]
        return data[4:4+str_len].tostring()

    def cmd_reset(self):
        reset_packet = self.create_cmd_packet(CMD_RESET)
        self.send_packet(reset_packet)
        hexdump.hexdump(self.recv_packet())

    def create_write_packet(self, addr, data):
        addr = addr
        if len(data) > self.MAX_WRITE_PACKET_SIZE:
            raise TooMuchData("Bootloader write cmd only allows {} per block",  max_size)
        # if size > 0x10:
        #     print('Warning: packet sizes greater than 16 not tested.')
        addr_bytes = self.get_address_bytes(addr)
        data = array('B', data)
        print(len(data))
        return self.create_cmd_packet(CMD_WRITE, addr_bytes + b([len(data)]) + data)

    def cmd_write_bytes(self, addr, data):
        if not self.has_erased_page0:
            raise BadCommandOrder("Must erase 0 page before writing.")

        for offset in range(0, len(data), self.MAX_WRITE_PACKET_SIZE):
            end = offset + self.MAX_WRITE_PACKET_SIZE
            if end > len(data):
                end = len(data)
            block = data[offset:end]

            is_empty = True
            for b in block:
                if b != 0xff:
                    is_empty = False
            if is_empty:
                continue

            # print(hex(addr+offset), hex(offset), hex(end), hexdump.dump(block))
            # print(hex(addr+offset), hex(offset), hex(end), hexdump.dump(block))
            print(hex(addr+offset), hex(offset), hex(end), "->",  hexdump.dump(block))
            write_packet = self.create_write_packet(addr + offset, block)
            self.send_packet(write_packet)
            response = self.recv_packet()
            if response[0] != CMD_WRITE:
                raise WriteFailed("Failed to write flash memory")

    def get_address_bytes(self, addr):
        addr_lo = addr & 0xff
        addr_hi = (addr >> 8) & 0xff
        return array('B', [addr_hi, addr_lo])

    def create_erase_packet(self, addr, size):
        addr = (addr // PAGE_SIZE) * PAGE_SIZE
        size = b([size])
        addr_bytes = self.get_address_bytes(addr)
        return self.create_cmd_packet(CMD_ERASE_PAGE, addr_bytes + size)

    def cmd_erase_page(self, page_num):
        if not self.has_erased_page0 and page_num != 0:
            raise BadCommandOrder("Must erase 0 page before other erasing other pages.")
        if page_num > MAX_PROGRAMMABLE_PAGE:
            raise EraseFailed("Cannot erase past page {}".format(MAX_PROGRAMMABLE_PAGE))
        erase_packet = self.create_erase_packet(page_num * PAGE_SIZE, 1)
        self.send_packet(erase_packet)
        response = self.recv_packet()
        if response[0] != CMD_ERASE_PAGE:
            raise EraseFailed("Failed to erase page. Error code: {}".format(response[0]))
        self.has_erased_page0 = True


    def write_hexfile(self, filename, generate_crc=None):
        max_write_addr = 0x6800
        crc_addr = max_write_addr-2

        hexfile = intelhex.IntelHex()
        hexfile.padding = 0xff
        with open(filename) as f:
            hexfile.loadhex(f)

        print(hexfile.maxaddr(), max_write_addr-2)
        if generate_crc == None and hexfile.maxaddr() < max_write_addr-2:
            generate_crc = True

        if generate_crc:
            if hexfile.maxaddr() > max_write_addr-2:
                raise HexfileTooBig("hexfile too big")
            crc = crc16.crc16(hexfile, max_write_addr-2)
            hexfile[crc_addr+0] = hi(crc)
            hexfile[crc_addr+1] = lo(crc)
        else:
            if hexfile.maxaddr() > max_write_addr:
                raise HexfileTooBig("hexfile too big")
            expected_crc = crc16.crc16(hexfile, max_write_addr-2)
            got_crc = (hexfile[crc_addr+0] << 8) | (hexfile[crc_addr+1])
            if expected_crc != got_crc:
                raise BadCRC16("Invalid crc16 include inhexfile. Expected 0x{:x}, got 0x{:x}" \
                        .format(expected_crc, got_crc))
        # hexfile.dump()
        for i in range(MAX_PROGRAMMABLE_PAGE+1):
            self.cmd_erase_page(i)
        # a = [hex(hexfile[i]) for i in range(1, max_write_addr)]
        # print(a, hex(len(a)))
        self.cmd_write_bytes(0x0001, array('B', [hexfile[i] for i in range(1, max_write_addr)]))
        self.cmd_write_bytes(0x0000, array('B', [hexfile[0]]))


if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(description='Uniflash script',
        usage=""" %(prog)s <command> [<args>]

    command is one of:
        icp         reset the unifying firmware into its bootloader mode
        reset       reset from the bootloader
        flash       when in icp mode flash the given hexfile
        info        print info about bootloader (nRF24LU1+)
        info_ti     print info about bootloader (CC2544)
        """)
    parser.add_argument('command', type=str, action='store', default=None,
                        help='Command to run (icp, reset, flash)'),
    parser.add_argument('hex_file', nargs='?', type=str, action='store', default=None,
                        help='The hexfile to flash'),

    args = parser.parse_args()

    if args.command == "icp":
        # TODO, get bootloader PID from 0x03 above, and bootloader version
        enter_icp()

    elif args.command == "reset":
        for pid in (NRF_PIDS + TI_PIDS):
            boot_dev = usb.core.find(idVendor=VID_LOGITECH, idProduct=pid)
            if boot_dev != None:
                break
        detach_kernel_drivers(boot_dev, [0, 1])

        boot_writer = BootloaderWriter(boot_dev)
        boot_writer.cmd_reset()

    elif args.command == "flash" or args.command == "info" or args.command == "info_ti":
        fileName = None
        if args.command == "flash":
            fileName = args.hex_file


        boot_devices = list(usb.core.find(
            idVendor=VID_LOGITECH,
            find_all=True,
        ))

        # from the list of devices, try and filter out those that are known
        # to be for unifying receiver bootloaders
        nrf_devices = [
            dev for dev in boot_devices if dev.idProduct in NRF_PIDS
        ]
        ti_devices = [
            dev for dev in boot_devices if dev.idProduct in TI_PIDS
        ]

        is_ti_device = False

        if (len(ti_devices) + len(nrf_devices) == 0):
            print("Couldn't find any devices to program", file=sys.stderr)
            exit(1);
        elif (len(ti_devices) + len(nrf_devices) > 1):
            print(
                "Found multiple matching devices, try disconnecting the "
                "other devices and try again. Devices found: {}."
                .format([(hex(dev.idVendor), hex(dev.idProduct)) for dev in boot_devices]),
                file=sys.stderr
            )
            exit(1);
        elif (len(ti_devices) == 1):
            dev = ti_devices[0]
            print(
                "Found a device with unsupported bootloader: ({}, {}). Disconnect "
                "the device to reset it."
                .format(hex(dev.idVendor), hex(dev.idProduct)),
                file=sys.stderr
            )
            boot_dev = boot_devices[0]
            is_ti_device = True
            exit(1);
        elif (len(nrf_devices) == 1):
            dev = nrf_devices[0]
            print(
                "Found a supported device with bootloader: ({}, {})"
                .format(hex(dev.idVendor), hex(dev.idProduct))
            )
            boot_dev = boot_devices[0]
        else:
            # shouldn't reach this
            print(
                "Couldn't find any devices running the Logitech bootloader. "
            )
            exit(1)


        detach_kernel_drivers(boot_dev, [0, 1])

        boot_writer = BootloaderWriter(boot_dev)

        pp = PacketPrinter()
        ## TODO, check that this info is valid befor flashing
        boot_info = boot_writer.cmd_bootloader_info()
        print("flash_start?: 0x{:04X}".format(boot_info[0]))
        print("flash_end: 0x{:04X}".format(boot_info[1]))
        print("block_size: 0x{:04X}".format(boot_info[2]))

        mcu_str = boot_writer.cmd_get_mcu_str()
        if mcu_str != b'nRF24LU1+ rev. A':
            raise UnsupportedMCU("Unsupported microcontroller: {}".format(mcu_str))
        print("mcu: {}".format(mcu_str))

        # terminate early for the info command
        if args.command == "info" or args.command == "info_ti" or is_ti_device:
            sys.exit(0);

        pp.print(boot_writer.cmd_sum16())

        boot_writer.write_hexfile(fileName)
        boot_writer.cmd_reset()
        # reattach_kernel_drivers(boot_dev, [0, 1])
