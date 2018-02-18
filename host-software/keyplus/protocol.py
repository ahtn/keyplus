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

class KBInfoMain(KBInfoMainNamedTuple):
    @staticmethod
    def _make_with_crc(fields, crc, is_empty):
        result = KBInfoMain._make(fields)
        result.computed_crc = crc
        result.is_empty = is_empty
        return result

    def device_name_str(self):
        if self.is_empty:
            return ""
        else:
            try:
                result = self.name.decode('utf-8')
            except UnicodeDecodeError:
                result = str(self.name)
            return result

    def timestamp_str(self):
        return timestamp_to_str(self.timestamp)

    def default_report_mode_str(self):
        return report_mode_to_str(self.default_report_mode)

    def scan_mode_str(self):
        return scan_mode_to_str(self.scan_mode)

    def has_usb(self):
        return not bool(self.feature_ctrl & FEATURE_CTRL_USB_DISABLE)

    def has_i2c(self):
        return not bool(self.feature_ctrl & FEATURE_CTRL_WIRED_DISABLE)

    def has_nrf24(self):
        return not bool(self.feature_ctrl & FEATURE_CTRL_RF_DISABLE)

    def has_unifying_mouse(self):
        return not bool(self.feature_ctrl & FEATURE_CTRL_RF_MOUSE_DISABLE)

    def has_bluetooth(self):
        return not bool(self.feature_ctrl & FEATURE_CTRL_BT_DISABLE)

class KBInfoErrorSystem(object):
    NUM_ERROR_CODES = 128
    SIZE_ERROR_CODE_TABLE = NUM_ERROR_CODES // 8
    CRITICAL_ERROR_START = 64

    def __init__(self, error_table):
        self._error_table = error_table;

        if len(error_table) != self.SIZE_ERROR_CODE_TABLE:
            raise KBProtocolException(
                "Invalid size for error table, expected {} bytes but got {}"
                .format(self.SIZE_ERROR_CODE_TABLE, len(error_table))
            )

        for i in range(self.CRITICAL_ERROR_START//8, self.SIZE_ERROR_CODE_TABLE):
            if self._error_table[i] != 0:
                self._has_critical_error = True

    def get_error_codes(self):
        result = []
        for (byte_i, byte) in enumerate(self._error_table):
            if byte == 0:
                continue;
            for bit_i in range(8):
                if byte & (1 << bit_i):
                    error_code = byte_i * 8 + bit_i
                    result.append(error_code)
        return result

    def error_code_to_name(self, code):
        if code in ERROR_CODE_MAP:
            return ERROR_CODE_MAP[code]
        else:
            return "<UNKNOWN_ERROR_CODE>"


    def has_critical_error(self):
        return self._has_critical_error

KBInfoFirmwareNamedTuple = collections.namedtuple("KBInfoFirmware",
    """
    version_major version_minor version_patch
    layout_flash_size
    timestamp
    git_hash
    connectivity_support_flags
    scan_support_flags
    kb_support_flags
    keyhandler_support_flags
    led_support_flags
    bootloader_vid
    bootloader_pid
    chip_id
    board_id
    internal_scan_method
    reserved
    """
)

class KBInfoFirmware(KBInfoFirmwareNamedTuple):
    def has_fw_support_scanning(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_MASK) != 0

    def has_fw_support_scanning_row_col(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_ROW_COL_MASK) != 0

    def has_fw_support_scanning_col_row(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_COL_ROW_MASK) != 0

    def has_fw_support_scanning_pins(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_PINS_MASK) != 0

    def has_fw_support_scanning_arbitrary(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_ARBITRARY_MASK) != 0

    def has_fw_support_scanning_built_in(self):
        return (self.scan_support_flags & SUPPORT_SCANNING_BUILT_IN_MASK) != 0

    def has_fw_support_key_media(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_MEDIA) != 0

    def has_fw_support_key_mouse(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_MOUSE) != 0

    def has_fw_support_key_layers(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_LAYERS) != 0

    def has_fw_support_key_sticky(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_STICKY) != 0

    def has_fw_support_key_tap(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_TAP) != 0

    def has_fw_support_key_hold(self):
        return (self.keyhandler_support_flags & SUPPORT_KEY_HOLD) != 0

    def has_fw_support_nkro(self):
        return (self.kb_support_flags & SUPPORT_KRO_N) != 0
    def has_fw_support_6kro(self):
        return (self.kb_support_flags & SUPPORT_KRO_6) != 0

    def has_fw_support_led_indicators(self):
        return (self.led_support_flags & SUPPORT_LED_INDICATORS) != 0
    def has_fw_support_led_backlighting(self):
        return (self.led_support_flags & SUPPORT_LED_BACKLIGHTING) != 0
    def has_fw_support_led_ws2812(self):
        return (self.led_support_flags & SUPPORT_LED_WS2812) != 0

    def has_fw_support_nrf24(self):
        return (self.connectivity_support_flags & SUPPORT_NRF24) != 0
    def has_fw_support_i2c(self):
        return (self.connectivity_support_flags & SUPPORT_I2C) != 0
    def has_fw_support_unifying(self):
        return (self.connectivity_support_flags & SUPPORT_UNIFYING) != 0
    def has_fw_support_usb(self):
        return (self.connectivity_support_flags & SUPPORT_USB) != 0
    def has_fw_support_bluetooth(self):
        return (self.connectivity_support_flags & SUPPORT_BT) != 0

    def get_interal_scan_method(self):
        return self.internal_scan_method

    def get_interal_scan_method_as_str(self):
        return self.internal_scan_method_to_str(self.internal_scan_method)

    def internal_scan_method_to_str(self, method):
        assert(isinstance(method, int))
        if method in INTERNAL_SCAN_METHOD_TABLE:
            return INTERNAL_SCAN_METHOD_TABLE[method]
        else:
            return "UnknownInternalScanMethod({})".format(method)


    def has_at_least_version(self, version_str):
        (major, minor, patch) = [int(x) for x in version_str.split('.')]

        return \
            self.version_major >= major and \
            self.version_minor >= minor and \
            self.version_patch >= patch


def get_firmware_info(device):
    # uint8_t version_major;
    # uint8_t version_minor;
    # uint8_t version_patch;
    # uint32_t layout_flash_size;
    # uint8_t timestamp[8]; // utc time stamp of last update
    # uint8_t git_hash[8]; // git hash of firmware when it was built

    # // supported connectivity features
    # uint8_t wireless_support: 1;
    # uint8_t i2c_support: 1;
    # uint8_t unifying_support: 1;
    # uint8_t usb_support: 1;
    # uint8_t bt_support: 1;
    # uint8_t _reserved0 : 3; // 1 byte

    # // supported scanning features
    # uint8_t scan_support: 1;
    # uint8_t scan_row_col: 1;
    # uint8_t scan_col_rol: 1;
    # uint8_t scan_pins: 1;
    # uint8_t scan_arbitrary: 1;
    # uint8_t scan_built_in: 1;
    # uint8_t _reserved1 : 2; // 1 byte

    # // generic keyboard features
    # uint8_t kro_n_support: 1;
    # uint8_t kro_6_support: 1;
    # uint8_t _reserved2: 6; // 1 byte

    # // keyhandler_support
    # uint8_t key_media: 1;
    # uint8_t key_mouse: 1;
    # uint8_t key_layers: 1;
    # uint8_t key_sticky: 1;
    # uint8_t key_tap: 1;
    # uint8_t key_hold: 1;
    # uint8_t _reserved3: 2; // 1 byte

    # // led_features
    # uint8_t led_indicators: 1;
    # uint8_t led_backlighting: 1;
    # uint8_t led_ws2812: 1;
    # uint8_t _reserved4: 5; // 1 byte

    # uint16_t bootloader_vid;
    # uint16_t bootloader_pid;

    # uint32_t chip_id;
    # uint16_t board_id;
    # uint8_t internal_scan_method;

    # uint8_t reserved[23];

    response = simple_command(device, CMD_GET_DEVICE_SETTINGS, [INFO_FIRMWARE])[1:]

    x = struct.unpack("< 3B L Q Q 5B 2H L H B 23s" ,response)
    return KBInfoFirmware._make(x)

def get_rf_info(device):
    response = simple_command(device, CMD_GET_DEVICE_SETTINGS, [INFO_RF])[1:]

    # uint8_t pipe_addr_0[NRF_ADDR_LEN];
    # uint8_t pipe_addr_1[NRF_ADDR_LEN];
    # uint8_t pipe_addr_2;
    # uint8_t pipe_addr_3;
    # uint8_t pipe_addr_4;
    # uint8_t pipe_addr_5;
    # uint8_t channel; // TODO: when using unifying, channel must be (ch%3 == 0)
    #                  // this should be enforced somewhere/somehow
    # uint8_t arc;
    # uint8_t data_rate;
    # uint8_t power;
    # uint8_t _reserved[14]; // pad to 32 bytes

    KBInfoRF = collections.namedtuple("KBInfoRF",
        """
        pipe0 pipe1 pipe2 pipe3 pipe4 pipe5
        channel arc data_rate power reserved padding
        """
    )

    x = struct.unpack("< 5s 5s 4B 4B 14s 30s", response)
    return KBInfoRF._make(x)


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
