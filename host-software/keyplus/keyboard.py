#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import sys
import easyhid
import struct
import hexdump
import time

import keyplus.exceptions
import keyplus.io_map

from collections import namedtuple
from pprint import pprint

from keyplus.constants import *
from keyplus.usb_ids import is_keyplus_usb_id
from keyplus.chip_id import get_chip_id_from_name
from keyplus.error_table import KeyplusErrorTable
from keyplus.exceptions import *
from keyplus.device_info import *
from keyplus.utility import uint24_le

from keyplus.layout import *
from keyplus.debug import DEBUG
from keyplus.cdata_types import layout_settings_t

def _get_similar_serial_number(dev_list, serial_num):
    partial_match = None
    partial_match_pos = None
    for dev in dev_list.find():
        if dev.serial_number == serial_num:
            # found an exact match
            return serial_num
        else:
            if dev.serial_number == None:
                continue

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

def find_devices(name=None, serial_number=None, vid_pid=None, device_id=None,
                 hid_enumeration=None, chip_name=None):
    """
    Returns a list of keyplus keyboards that are currently connected to the
    computer. The arguments can be used to filter result.

    Args:
        name: filter list by the device name
        serial_number: filter list by the devices serial number. Tries for an
            exact match, but will accept a partial match if an exact match is
            not found.
        vid_pid: filter list by the USB vendor and product id for the device in
            the format 'VID:PID'.
        device_id: filter list by device id
        hid_enumeration: an enumeration of USB devices to test. If this argument
            is not set, the function will call `easyhid.Enumeration()` itself.
    """
    if chip_name != None:
        chip_id =  get_chip_id_from_name(chip_name)
    else:
        chip_id = None

    if not hid_enumeration:
        hid_enumeration = easyhid.Enumeration()

    target_vid = 0
    target_pid = 0

    if vid_pid:
        matches = vid_pid.split(":")
        if len(matches) == 1:
            try:
                target_vid = int(matches[0], base=16)
            except TypeError:
                KeyplusError("Bad VID/PID pair: " + vid_pid)
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
            except TypeError:
                raise KeyplusError("Bad VID/PID pair: " + vid_pid)

    assert(target_vid <= 0xffff)
    assert(target_pid <= 0xffff)

    if serial_number != None:
        serial_number = _get_similar_serial_number(hid_enumeration, serial_number)

    matching_devices = hid_enumeration.find(
        vid=target_vid,
        pid=target_pid,
        serial=serial_number,
        interface=INTERFACE_VENDOR
    )


    matching_dev_list = []
    for hid_device in matching_devices:
        try:
            if ((target_vid == 0 and target_pid == 0) and
                not is_keyplus_usb_id(hid_device.vendor_id, hid_device.product_id)
            ):
                # Ignore devices that don't use the keyplus vendor IDs
                continue

            new_kb = KeyplusKeyboard(hid_device)
            if device_id != None and device_id != new_kb.device_id:
                continue
            if name != None and (name not in new_kb.name):
                continue

            if chip_id != None and (chip_id != new_kb.firmware_info.chip_id):
                continue

            matching_dev_list.append(new_kb)
        except (KeyplusError, easyhid.HIDException) as err:
            # Couldn't open the device. Could be in use by another program or
            # do not have correct permissions to read from it.
            print("Warning: couldn't open device: " + str(err), file=sys.stderr)
            hid_device.close()

    return matching_dev_list


class KeyplusKeyboard(object):
    def __init__(self, hid_device):
        self.hid_device = hid_device

        self._layout_data_dirty = True
        self._layout_info_dirty = True
        self._rf_info_dirty = True

        with self.hid_device:
            self.get_device_info()
            self.get_firmware_info()
            self.get_rf_info()

        self._is_connected = False

    def __enter__(self):
        self.connect()

    def __exit__(self, err_type, err_value, traceback):
        self.disconnect()

    def _copy_device_info(self, other):
        """ Copy the internal device information to the object """
        self.hid_device = other.hid_device
        self.device_info = other.device_info
        self.firmware_info = other.firmware_info
        # self.layout_info = other.layout_info

    def get_device_target(self):
        device_target = KeyboardDeviceTarget(
            device_id = self.device_info.device_id,
            firmware_info = self.firmware_info,
        )
        return device_target

    def reconnect(self):
        """ Reconnect to a device after it has been reset.  """
        if self.serial_number not in ["", None]:
            self.hid_device.close()
            new_kb = find_devices(
                serial_number=self.serial_number
            )[0]
            self._copy_device_info(new_kb)
            self.connect()

    def connect(self):
        """ Establish a connection with the keyboard """
        self.hid_device.open()
        self._is_connected = True

    def disconnect(self):
        """ Disconnect a device.  """
        self.hid_device.close()
        self._is_connected = False

    @property
    def device_id(self):
        return self.device_info.device_id

    @property
    def name(self):
        return self.device_info.get_name_str()

    @property
    def serial_number(self):
        return self.hid_device.get_serial_number()

###############################################################################
#                                USB Commands                                 #
###############################################################################

    def simple_command(self, cmd_id, cmd_data=None, receive=True, match_data=None):
        """
        Returns:
            The bytes read from the command if `receive` is True

        Raises:
            HIDException, KeyplusProtocolError
        """
        cmd_packet = bytearray(EP_VENDOR_SIZE)
        nop_packet = bytearray([0xff]*EP_VENDOR_SIZE)
        cmd_packet[0] = cmd_id

        # Optional data component
        if cmd_data != None:
            cmd_data = bytearray(cmd_data)
            if len(cmd_data) > (EP_VENDOR_SIZE-1):
                raise KeyplusProtocolError("Data can't fit in one packet. Got {} "
                    "bytes, max is {}".format(len(cmd_data), EP_VENDOR_SIZE))
            for i, byte in enumerate(cmd_data):
                cmd_packet[i+1] = byte

        self.hid_write(cmd_packet)

        if receive:
            response = self.hid_read(timeout=1000)

            packet_type = None
            if response != None:
                packet_type = response[0]

            retries_left = 5
            while packet_type != cmd_id: # ignore other packets
                if packet_type == CMD_ERROR_CODE and response != None:
                    # If we got a error code packet, then break out of this
                    # loop (except for CMD_ERROR_BUSY).
                    error_code = response[1]
                    if error_code != CMD_ERROR_BUSY:
                        break

                response = self.hid_read(timeout=1000)
                if response == None and retries_left > 3:
                    # self.hid_write(nop_packet)
                    pass
                elif response == None and retries_left == 3:
                    self.hid_write(cmd_packet)
                elif response == None and retries_left < 3:
                    pass
                    # self.hid_write(nop_packet)
                else:
                    packet_type = response[0]

                retries_left -= 1
                if retries_left == 0:
                    raise KeyplusProtocolError(
                        "Device not replying to packets correctly. Packet that failed: {}"
                        .format(hexdump.dump(bytes(cmd_packet)))
                    )


            if response[0] == CMD_ERROR_CODE:
                keyplus.exceptions.raise_error_code(response[1])
            elif response[0] != cmd_id:
                raise KeyplusProtocolError("Unexpected packet with packet_id: {}"
                        .format(response[0]))
            return response[1:]
        else:
            return None

    def hid_write(self, data):
        if len(data) != EP_VENDOR_SIZE:
            raise KeyplusProtocolError("HID write packets must be 64 bytes")
        if DEBUG.usb_cmd_timing:
            print("{:.3F} usb sent:".format(time.time()))
            hexdump.hexdump(bytes(data))
        self.hid_device.write(data)

    def hid_read(self, timeout=None):
        response = self.hid_device.read(timeout=timeout)
        if DEBUG.usb_cmd_timing:
            if response == None:
                print("{:.3F} usb recv timeout:".format(time.time()))
            else:
                print("{:.3F} usb recv:".format(time.time()))
                hexdump.hexdump(bytes(response))
        return response

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
        return (self.firmware_info.bootloader_vid, self.firmware_info.bootloader_pid)

    def enter_pairing_mode(self):
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

    def get_error_info(device):
        """ Read the error code table from the device. """
        response = self.simple_command(CMD_GET_INFO, [INFO_ERROR_SYSTEM])[1:]
        error_table_data = response[:KeyplusErrorTable.SIZE_ERROR_CODE_TABLE]
        return KeyplusErrorTable(error_table_data)

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

    def listen_raw(self):
        # TODO: better way to interface with this
        while True:
            response = self.hid_device.read()
            if (response[0] == CMD_PRINT):
                length = response[1]
                hexdump.hexdump(bytes(response[2:length+2]))
            else:
                hexdump.hexdump(bytes(response))

    def get_info_cmd(self, info_page_number):
        retries = 2
        while retries != 0:
            response = self.simple_command(CMD_GET_INFO, [info_page_number])
            if response[0] == INFO_UNSUPPORTED:
                raise KeyplusUnsupportedError(
                    "Device doesn't have any data for info page number '{}'"
                    .format(info_page_number)
                )
            elif response[0] != info_page_number:
                response = self.simple_command(CMD_GET_INFO, [info_page_number])
                retries -= 1
            else:
                break
        if retries == 0 and response[0] != info_page_number:
            raise KeyplusProtocolError(
                "Error while getting info from device. "
                "Expected data for info page: {}, but got from {}."
                .format(info_page_number, response[0])
            )
        return response[1:]

    def get_device_info(self):
        DEVICE_INFO_SIZE = 96
        response = self.get_info_cmd(INFO_MAIN_0)
        response += self.get_info_cmd(INFO_MAIN_1)
        response = response[0:DEVICE_INFO_SIZE]

        device_info = KeyboardSettingsInfo()
        device_info.unpack(response)
        self.device_info = device_info
        return device_info

    def get_firmware_info(self):
        response = self.get_info_cmd(INFO_FIRMWARE)
        firmware_info = KeyboardFirmwareInfo()
        firmware_info.unpack(response)
        self.firmware_info = firmware_info
        return firmware_info

    def get_layout_info_header(self):
        response = self.get_info_cmd(INFO_LAYOUT)
        layout_info = KeyboardLayoutInfo()
        layout_info.unpack(response[0:KeyboardLayoutInfo.__size__])
        self.layout_info = layout_info
        return layout_info

    def get_layout_info(self):
        if not self._layout_info_dirty:
            return self.layout_settings

        response = bytearray(0)
        for i in range(INFO_NUM_LAYOUT_DATA_PAGES):
            response = response + self.get_info_cmd(INFO_LAYOUT_DATA_0 + i)

        layout_settings = KeyboardLayoutInfo()

        layout_settings.unpack(response[:layout_settings_t.__size__])
        self.layout_settings = layout_settings
        self._layout_info_dirty = False
        return layout_settings

    def get_rf_info(self):
        if not self._rf_info_dirty:
            return self.rf_info

        response = self.get_info_cmd(INFO_RF)

        rf_info = KeyboardRFInfo()
        rf_info.unpack(response[0:SETTINGS_RF_INFO_HEADER_SIZE] + bytearray(AES_KEY_LEN*2))
        self.rf_info = rf_info
        self._rf_info_dirty = False
        return rf_info

    def read_settings_section(self):
        """ Reads the settings section from the device and returns it """
        # NOTE: In the future, might support mulitple formats of the settings
        # section.
        # self.get_firmware_info()

        settings = keyplus.cdata_types.settings_t()
        settings.header = self.get_device_info()
        settings.layout = self.get_layout_info()
        settings.rf = self.get_rf_info()

        return settings

    def read_whole_layout(self):
        if not self._layout_data_dirty:
            return self._whole_layout_data

        start = time.time()
        bytes_remaining = self.firmware_info.layout_flash_size
        offset = 0

        result = bytearray()
        while bytes_remaining != 0:
            bytes_to_read = min(bytes_remaining, 63)
            result += self.read_layout_data(offset, bytes_to_read)
            bytes_remaining -= bytes_to_read
            offset += bytes_to_read

        finish = time.time()
        if DEBUG.usb_cmd_timing:
            print("Time to read layout: ", finish - start)

        self._whole_layout_data = result
        self._layout_data_dirty = False

        return result

    def _get_layout_data_sections(self):
        device_target = self.get_device_target()

        if self.firmware_info.internal_scan_method == MATRIX_SCANNER_INTERNAL_NONE:
            pin_mapping_section = 0
        elif self.firmware_info.internal_scan_method == MATRIX_SCANNER_INTERNAL_FAST_ROW_COL:
            header_size = 0
            header_size += self.firmware_info.scanner_max_rows
            header_size += device_target.get_io_mapper().get_gpio_count()
            scan_plan = self.device_info.scan_plan
            map_size = (scan_plan.max_col_pin_num+1) * scan_plan.rows
            pin_mapping_section = header_size + map_size

        data = self._whole_layout_data

        # ekc_size =
        external_keycode_table = pin_mapping_section + struct.unpack(
            "< H",
            data[pin_mapping_section:pin_mapping_section+2],
        )[0]

        pin_map_data = data[:pin_mapping_section]
        ekc_data = data[pin_mapping_section:external_keycode_table]
        layout_data = data[external_keycode_table+2:]

        return (
            pin_map_data,
            ekc_data,
            layout_data
        )

    def _get_layout_keycode_arrays(self, layout_data):
        self.get_layout_info()

        result = []

        pos = 0

        for layout_i in range(self.layout_settings.number_layouts):
            layout = self.layout_settings.layouts[layout_i]
            devices = self.layout_settings.get_layout_device_sizes(layout_i)
            num_layers = self.layout_settings.layouts[layout_i].layer_count
            layout_keycodes = []
            for layer_i in range(num_layers):
                layer = []
                for (offset, size) in devices:
                    keycodes = struct.unpack(
                        "<" + "H" * (size // 2),
                        layout_data[pos:pos+size]
                    )
                    layer.append(list(keycodes))
                    pos += size
                layout_keycodes.append(layer)
            result.append(layout_keycodes)


        return result

    def unpack_layout_data(self):
        self.get_layout_info()
        self.read_whole_layout()
        device_target = self.get_device_target()

        pin_map_data, ekc_table, layout_data = self._get_layout_data_sections()

        scan_mode = ScanMode()
        pin_mapping = KeyboardPinMapping()
        pin_mapping.unpack(
            pin_map_data,
            self.device_info.scan_plan,
            device_target,
        )
        scan_mode.load_raw_data(self.device_info.scan_plan, pin_mapping)

        layout_device = LayoutDevice()
        layout_device.load_raw_data(
            self.device_info,
            self.layout_settings,
            pin_mapping,
        )

        # TODO:
        # ekc_table = EKCTable()
        # ekc_table.unpack()
        # hexdump.hexdump(layout_data)

        layout_arrays = self._get_layout_keycode_arrays(layout_data)

        result = []
        kp_layout = KeyplusLayout()
        for (layout_i, _) in enumerate(layout_arrays):
            layout = LayoutKeyboard(layout_i)
            layout.load_keycodes(layout_arrays[layout_i])
            result.append(layout)
            kp_layout.add_layout(layout)
        kp_layout.add_device(layout_device)

        return kp_layout


    def read_layout_data(self, offset, size):
        assert(size <= VENDOR_REPORT_LEN-1)
        control_data = struct.pack("< L B", offset, size)
        return self.simple_command(CMD_READ_LAYOUT, control_data)[:size]

    def get_layers(self, layout_id):
        response = self.simple_command(CMD_GET_LAYER, [layout_id])
        return struct.unpack_from("<B HHH", response)

    def _get_chunks(self, data, chunk_size, pad=0xff):
        chunk_data = None
        remainder = len(data) % chunk_size
        if remainder != 0:
            chunk_data = bytearray(data[:]) + bytearray([pad] * (chunk_size - remainder))
        else:
            chunk_data = bytearray(data)
        return [bytes(chunk_data[i*chunk_size:(i+1)*chunk_size]) for i in range(len(chunk_data)//chunk_size)]

    def _check_cmd_response(self, packet):
        packet_type = packet[0]
        err_code = packet[1]

        if packet_type != CMD_ERROR_CODE:
            raise KeyplusProtocolError(
                "Received unexpected packet type while writing settings "
                "section. Expected {}, but got {} instead."
                .format(CMD_ERROR_CODE, packet_type)
            )
        if err_code != CMD_ERROR_CODE_NONE:
            raise_error_code(err_code)

    def create_flash_write_packet(self, write_pos, write_size, data):
        # CMD_WRITE_FLASH format:
        # byte0:    this command name
        # byte1-3:  24-bit write address
        # byte4:    number of bytes to write in this packet.
        # byte5-63: bytes to be written to flash
        result = bytearray()
        result.append(CMD_WRITE_FLASH)
        result.extend(uint24_le(write_pos))
        result.append(write_size)
        result.extend(data)
        return result

    def _write_flash_chunks(self, chunk_list, length):
        address_pos = 0
        length_remaining = length
        for chunk in chunk_list:
            packet = self.create_flash_write_packet(
                address_pos,
                min(FLASH_WRITE_PACKET_LEN, length_remaining),
                chunk,
            )
            self.hid_write(packet)
            response = self.hid_read(timeout=3500)
            self._check_cmd_response(response)
            address_pos += FLASH_WRITE_PACKET_LEN;
            length_remaining -= FLASH_WRITE_PACKET_LEN

        # Writing to address 0xffffff ends flash write.
        finish_packet = bytearray([0xff]*64)
        finish_packet[0] = CMD_WRITE_FLASH
        self.hid_write(finish_packet)
        self._check_cmd_response( self.hid_read(timeout=30) ) # check response

    def update_settings_section(self, settings_data, keep_rf):
        assert(isinstance(keep_rf, bool))
        keep_rf = int(keep_rf)

        self._rf_info_dirty = True
        self._layout_info_dirty = True

        size = SETTINGS_SIZE
        if (keep_rf):
            size = SETTINGS_SIZE - SETTINGS_RF_INFO_SIZE
        chunk_list = self._get_chunks(settings_data[0:size], FLASH_WRITE_PACKET_LEN)

        self.simple_command(CMD_UPDATE_SETTINGS, [keep_rf])

        if DEBUG.usb_cmd:
            print("Setting chunks:", chunk_list)

        self._write_flash_chunks(chunk_list, size)

        self.get_device_info()

    def update_layout_section(self, layout_data):
        self._layout_info_dirty = True

        # TODO: change this to a uint32_t
        start_address = 0
        end_address = len(layout_data) - 1

        if end_address >= self.firmware_info.layout_flash_size:
            raise KeyplusSettingsError(
                "Not enough storage space for layout settings. The device has "
                "{} bytes of storage space. The given layout requires {} bytes."
                .format(self.firmware_info.layout_flash_size, end_address)
            )

        flash_write_info = struct.pack(
            "<L L",
            start_address,
            end_address,
        )
        self.simple_command(CMD_UPDATE_LAYOUT, flash_write_info)

        chunk_list = self._get_chunks(layout_data, FLASH_WRITE_PACKET_LEN)

        self._write_flash_chunks(chunk_list, end_address)

    def _test_update_layout(self):
        data = [i & 0xff for i in range(self.firmware_info.layout_flash_size)]
        self.update_layout_section(data)

    def erase_settings_section(self):
        self.update_settings_section(bytearray(), keep_rf=False)

    def erase_layout_section(self):
        flash_write_info = struct.pack(
            "<L L",
            0,
            (self.firmware_info.layout_flash_size) - 1,
        )
        self.simple_command(CMD_UPDATE_LAYOUT, flash_write_info)
        self._write_flash_chunks([], 0)





if __name__ == '__main__':
    Keyboard()
