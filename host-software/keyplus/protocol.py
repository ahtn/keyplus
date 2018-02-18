#!/usr/bin/env python
# -*- coding: utf-8 -*-

import collections
import struct
import hexdump
import datetime

from keyplus.crc16 import crc16_bytes

DEFAULT_PID = 0x1111
DEFAULT_VID = 0x6666
DEFAULT_INTERFACE = 3

from keyplus import *

def simple_command(device, cmd_id, data=None, receive=True):
    """
    Raises:
    HIDException -> if reading/writing to the USB device failed:
    KBProtocolException -> if the packet is too large
    """
    cmd_packet = bytearray(EP_VENDOR_SIZE)
    cmd_packet[0] = cmd_id

    # Optional data component
    if data != None:
        data = bytearray(data)
        if len(data) > (EP_VENDOR_SIZE-1):
            raise KBProtocolException("Data can't fit in one packet. Got {} "
                "bytes, max is {}".format(len(data), EP_VENDOR_SIZE))
        for i, byte in enumerate(data):
            cmd_packet[i+1] = byte

    device.write(cmd_packet)

    if receive:
        response = device.read()

        packet_type = response[0]

        while packet_type != cmd_id and packet_type != CMD_ERROR_CODE: # ignore other packets
            response = device.read(timeout=2)
            if response == None:
                device.write(cmd_packet)
            else:
                packet_type = response[0]


        if response[0] == CMD_ERROR_CODE:
            raise_error_code(response[1])
        elif response[0] != cmd_id:
            raise KBProtocolException("Unexpected packet with packet_id: {}"
                    .format(response[0]))
        return response[1:]
    else:
        return None


def listen_raw(device):
    """
    Debug mode
    """
    while True:
        response = device.read()
        if (response[0] == CMD_PRINT):
            length = response[1]
            hexdump.hexdump(bytes(response[2:length+2]))
        else:
            hexdump.hexdump(bytes(response))
