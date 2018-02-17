#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import six
import sys

import easyhid

from keyplus.crc16 import crc16_bytes
import keyplus.cdata_types
from keyplus.constants import *

class KeyplusKeyboardError(Exception):
    pass

class KeyplusKeyboardConnectError(KeyplusKeyboardError):
    pass

def _get_similar_serial_number(dev_list, serial_num):
    partial_match = None
    partial_match_pos = None
    for dev in dev_list.find():
        if dev.serial_number == serial_num:
            # found an exact match
            return serial_num
        else:
            # didn't find an exact match, so keep track of partial matches
            match_pos = dev.serial_number.find(serial_num)

            # no match, ignore
            if match_pos == -1:
                continue

            # update the best match we found, prioritize serial_num numbers
            # that match near the start of the string
            if partial_match_pos == None or match_pos < partial_match_pos:
                partial_match = dev.serial_number
                partial_match_pos = match_pos

    if partial_match:
        return partial_match
    else:
        return serial_num


def find_devices(name=None, serial_number=None, vid_pid=None, dev_id=None,
                 hid_enumeration=None):
    if not hid_enumeration:
        hid_enumeration = easyhid.Enumeration()

    target_vid = 0
    target_pid = 0

    if vid_pid:
        matches = vid_pid.split(":")
        if len(matches) == 1:
            try:
                target_vid = int(matches[0], base=16)
                if target_vid > 0xffff: raise Exception
            except:
                KeyplusKeyboardError("Bad VID/PID pair: " + vid_pid)
        elif len(matches) == 2:
            try:
                if matches[0] == '':
                    target_vid = None
                else:
                    target_vid = target_vid = int(matches[0], base=16)
                if matches[1] == '':
                    target_pid = None
                else:
                    target_pid = target_pid = int(matches[1], base=16)
                if target_vid and target_vid > 0xffff: raise Exception
                if target_pid and target_pid > 0xffff: raise Exception
            except:
                raise KeyplusKeyboardError("Bad VID/PID pair: " + vid_pid)

    if serial_number != None:
        serial_number = _get_similar_serial_number(hid_enumeration, serial_number)

    matching_devices = hid_enumeration.find(
        vid=target_vid,
        pid=target_pid,
        serial=serial_number,
        interface=INTERFACE_VENDOR
    )

    matching_dev_list = []
    for hid_dev in matching_devices:
        try:
            new_kb = KeyplusKeyboard(hid_dev)
            if dev_id != None and dev_id != new_kb.get_device_id():
                continue
            if name != None and (name not in new_kb.get_device_name()):
                continue

            matching_dev_list.append(new_kb)
        except Exception as err:
            # Couldn't open the device. Could be in use by another program or
            #
            print("Warning: couldn't open device: " + str(err), file=sys.stderr)
            hid_dev.close()

    return matching_dev_list


class KeyplusKeyboard(object):
    def __init__(self, hid_device):
        self.hid_dev = hid_device
        self.hid_dev.open()
        self.get_device_info()
        self.get_firmware_info()
        self.get_layout_info()
        self.hid_dev.close()
        self._is_connected = False

    def _copy_device_info(self, other):
        """ Copy the internal device information to the object """
        self.hid_dev = other.hid_dev
        self.dev_info = other.dev_info
        self.fw_info = other.fw_info
        # self.layout_info = other.layout_info

    def get_serial_number(self):
        return self.hid_dev.serial_number

    def get_device_id(self):
        return self.dev_info.id

    def get_device_name(self):
        return self.dev_info.name

    def reconnect(self):
        """ Reconnect to a device after it has been reset.  """
        if self.get_serial_number() not in ["", None]:
            self.hid_dev.close()
            new_kb = find_devices(
                serial_number=self.get_serial_number()
            )[0]
            self._copy_device_info(new_kb)
            self.connect()

    def connect(self):
        """ Establish a connection with the keyboard """
        self.hid_dev.open()
        self._is_connected = True

    def disconnect(self):
        """ Disconnect a device.  """
        self.hid_dev.close()
        self._is_connected = False

    def simple_command(self, cmd_id, cmd_data=None, receive=True):
        """
        Returns:
            The bytes read from the command if `receive` is True

        Raises:
            HIDException, KBProtocolException
        """
        cmd_packet = bytearray(EP_VENDOR_SIZE)
        cmd_packet[0] = cmd_id

        # Optional data component
        if cmd_data != None:
            cmd_data = bytearray(cmd_data)
            if len(cmd_data) > (EP_VENDOR_SIZE-1):
                raise KBProtocolException("Data can't fit in one packet. Got {} "
                    "bytes, max is {}".format(len(cmd_data), EP_VENDOR_SIZE))
            for i, byte in enumerate(cmd_data):
                cmd_packet[i+1] = byte

        self.hid_dev.write(cmd_packet)

        if receive:
            response = self.hid_dev.read()

            packet_type = response[0]

            while packet_type != cmd_id and packet_type != CMD_ERROR_CODE: # ignore other packets
                response = self.hid_dev.read(timeout=2)
                if response == None:
                    self.hid_dev.write(cmd_packet)
                else:
                    packet_type = response[0]


            if response[0] == CMD_ERROR_CODE:
                keyplus.protocol.raise_error_code(response[1])
            elif response[0] != cmd_id:
                raise KBProtocolException("Unexpected packet with packet_id: {}"
                        .format(response[0]))
            return response[1:]
        else:
            return None

    def set_passthrough_mode(self, enable):
        """
        Enable or disable passthrough mode. When enabled passthrough mode makes
        the keyboard send it's raw device matrix to the host.
        """
        enable_bit = 0
        if enable:
            enable_bit = 1
        else:
            enable_bit = 0
        response = self.simple_command(
            CMD_SET_PASSTHROUGH_MODE,
            [enable_bit]
        )

    def enter_bootloader(self):
        """ Enter the device's bootloader. """
        response = self.simple_command(
            CMD_BOOTLOADER,
            receive=False
        )
        return (self.fw_info.bootloader_vid, self.fw_info.bootloader_pid)

    def begin_pairing(self):
        """ Enter pairing mode for connecting to a unifying mouse """
        response = self.simple_command(
            CMD_UNIFYING_PAIR,
            receive=False
        )
        return response

    def set_indicator_led(self, led_num, state):
        """ Set an indicator LED """
        response = self.simple_command(
            CMD_LED_CONTROL,
            [led_num, state],
            receive=False
        )
        return response

    def reset(self, reset_type=RESET_TYPE_HARDWARE):
        """
        Reset the keyboard. There are two types of resets:
            * RESET_TYPE_HARDWARE: causes the mcu to reset
            * RESET_TYPE_SOFTWARE: reruns the initilization code without reseting the USB interface
        """
        response = self.simple_command(
            CMD_RESET,
            [reset_type],
            receive=False
        )
        return response

    def get_device_info(self):
        DEVICE_INFO_SIZE = 96
        response = self.simple_command(CMD_GET_DEVICE_SETTINGS, [INFO_MAIN_0])[1:]
        response += self.simple_command(CMD_GET_DEVICE_SETTINGS, [INFO_MAIN_1])[1:]
        response = response[0:DEVICE_INFO_SIZE]

        dev_info = KeyboardSettingsInfo()
        dev_info.unpack(response)
        self.dev_info = dev_info
        return dev_info

    def get_firmware_info(self):
        response = self.simple_command(CMD_GET_DEVICE_SETTINGS, [INFO_FIRMWARE])[1:]
        fw_info = KeyboardFirmwareInfo()
        fw_info.unpack(response)
        self.fw_info = fw_info
        return fw_info

    def get_layout_info(self):
        response = self.simple_command(CMD_GET_DEVICE_SETTINGS, [INFO_LAYOUT])[1:]
        layout_info = KeyboardLayoutInfo()
        layout_info.unpack(response[0:KeyboardLayoutInfo.__size__])
        self.layout_info = layout_info
        return layout_info


class KeyboardSettingsInfo(keyplus.cdata_types.settings_t):
    def has_valid_crc(self):
        return self.crc == self.compute_crc()

    def compute_crc(self):
        return crc16_bytes(self.pack()[:-2])

    def is_empty(self):
        # check if the flash has been initialized
        return sum([1 for byte in response if byte != 0xff]) == 0

class KeyboardLayoutInfo(keyplus.cdata_types.layout_settings_header_t):
    pass

class KeyboardFirmwareInfo(keyplus.cdata_types.firmware_info_t):
    pass

if __name__ == '__main__':
    Keyboard()
