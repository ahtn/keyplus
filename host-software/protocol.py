#!/usr/bin/env python
# -*- coding: utf-8 -*-

import collections
import struct
import hexdump

DEFAULT_PID = 0x1111
DEFAULT_VID = 0x6666
DEFAULT_INTERFACE = 3

EP_VENDOR_SIZE = 64

CMD_ERROR_CODE = 0x00
CMD_GET_DEVICE_SETTINGS = 0x01
CMD_LED_CONTROL = 0x02
CMD_RESET = 0x03
CMD_BOOTLOADER = 0x04
CMD_GET_LAYER = 0x05
CMD_LOGITECH_BOOTLOADER = 0x06
CMD_PRINT = 0x07
CMD_SET_PASSTHROUGH_MODE = 0x08
CMD_PASSTHROUGH_MATRIX = 0x09
CMD_UPDATE_SETTINGS_ALL = 0x0A
CMD_UPDATE_SETTINGS_LAYOUT = 0x0B
CMD_UPDATE_SETTINGS_RF = 0x0C
CMD_FLASH_LAYOUT = 0x0D

INFO_MAIN_0 = 0
INFO_MAIN_1 = 1
INFO_LAYOUT = 2
INFO_RF = 3
INFO_FIRMWARE = 4
INFO_UNSUPPORTED = 0xff

KEYBOARD_REPORT_MODE_AUTO = 0 # 6kro -> nkro if more than 6 keys pressed
KEYBOARD_REPORT_MODE_NKRO = 1 # nkro
KEYBOARD_REPORT_MODE_6KRO = 2 # 6kro

MATRIX_SCANNER_MODE_NONE = 0x00 # doesn't have a matrix
MATRIX_SCANNER_MODE_COL_ROW = 0x01 # normal col -->|-- row pin matrix
MATRIX_SCANNER_MODE_ROW_COL = 0x02 # normal row -->|-- col pin matrix
MATRIX_SCANNER_MODE_PINS = 0x03 # each pin represents a key

PWR_NEG_18DB = 0x00
PWR_NEG_12DB = 0x01
PWR_NEG_6DB = 0x02
PWR_0DB = 0x03

MAX_NUMBER_LAYOUTS = 64
MAX_NUMBER_DEVICES = 64


class ProtocolError:
    ERROR_CODE_NONE = 0
    ERROR_CODE_TOO_MUCH_DATA = 1
    ERROR_INVALID_VALUE = 2
    ERROR_KEYBOARD_INACTIVE = 3
    ERROR_UNKNOWN_CMD = 4

    def get_string(code):
        for (key, value) in ProtocolError.__dict__.items():
            if code == value:
                return key
        return "<Undefined error code>"

class KBProtocolException(Exception):
    def __init__(self, message="", code=None):
        if code:
            message = ProtocolError.get_string(code)
        super(Exception, self).__init__(message)
        self.error_code = code

def raise_error_code(code):
    if code == ProtocolError.ERROR_CODE_NONE:
        pass
    else:
        raise KBProtocolException(ProtocolError.get_string(code))


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


        # hexdump.hexdump(response)
        if response[0] == CMD_ERROR_CODE:
            raise_error_code(response[1])
        elif response[0] != cmd_id:
            raise KBProtocolException("Unexpected packet with packet_id: {}"
                    .format(response[0]))
        return response[1:]
    else:
        return None

def get_supported_features(device):
    pass

def get_layers(device, layout_id):
    response = simple_command(device, CMD_GET_LAYER, [layout_id])
    return struct.unpack_from("<B HHH", response)

def get_device_info(device):
    response = simple_command(device, CMD_GET_DEVICE_SETTINGS, [INFO_MAIN_0])[1:]
    response += simple_command(device, CMD_GET_DEVICE_SETTINGS, [INFO_MAIN_1])[1:]

    # uint8_t device_id;
    # char device_name[32];
    # uint8_t timestamp[8]; // utc time stamp of last update
    # uint8_t default_report_mode;
    # uint8_t scan_mode;
    # uint8_t row_count;
    # uint8_t col_count;
    # uint8_t _reserved[51]; // total size == 96
    KBInfoMain = collections.namedtuple("KBInfoMain",
        "id name timestamp default_report_mode "
        "scan_mode row_count col_count reserved"
    )

    x = struct.unpack("< B 32s q 4B 51s", response[0:96])
    return KBInfoMain._make(x)

def get_layout_info(device):
    response = simple_command(device, CMD_GET_DEVICE_SETTINGS, [INFO_LAYOUT])[1:]

    # uint8_t number_layouts;
    # uint8_t number_devices;
    # uint8_t _reserved[30]; // 32
    KBInfoLayout = collections.namedtuple("KBInfoLayout",
        "number_layouts number_devices reserved"
    )

    x = struct.unpack("< 2B 30s", response[0:32])
    return KBInfoLayout._make(x)

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


    # uint8_t reserved[31];

    response = simple_command(device, CMD_GET_DEVICE_SETTINGS, [INFO_FIRMWARE])[1:]

    KBInfoFirmware = collections.namedtuple("KBInfoFirmware",
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
        reserved
        """
    )

    x = struct.unpack("< 3B L Q Q 5B 2H 30s" ,response)
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

def set_passthrough_mode(device, enable):
    enable_bit = 0
    if enable:
        enable_bit = 1
    else:
        enable_bit = 0
    response = simple_command(device, CMD_SET_PASSTHROUGH_MODE, [enable_bit])

def enter_bootloader(device):
    fw_info = get_firmware_info(device)
    response = simple_command(device, CMD_BOOTLOADER, receive=False)
    return (fw_info.bootloader_vid, fw_info.bootloader_pid)

def set_indicator_led(device, state):
    response = simple_command(device, CMD_LED_CONTROL, [state], receive=False)
    return response

def reset_device(device):
    response = simple_command(device, CMD_RESET, receive=False)
    return response

def report_mode_to_str(mode):
    return {
        KEYBOARD_REPORT_MODE_AUTO: "Auto NKRO",
        KEYBOARD_REPORT_MODE_6KRO: "6KRO",
        KEYBOARD_REPORT_MODE_NKRO: "NKRO",
    }[mode]

def scan_mode_to_str(mode):
    return {
        MATRIX_SCANNER_MODE_NONE: "none",
        MATRIX_SCANNER_MODE_COL_ROW: "diodes column to row",
        MATRIX_SCANNER_MODE_ROW_COL: "diodes row to column",
        MATRIX_SCANNER_MODE_PINS: "pins",
    }[mode]

def power_to_str(power):
    return {
        PWR_NEG_18DB: "-18dB",
        PWR_NEG_12DB: "-12dB",
        PWR_NEG_6DB: "-6dB",
        PWR_0DB: "0dB",
    }[mode]

SUPPORT_SCANNING_MASK = 0x01
SUPPORT_SCANNING_COL_ROW_MASK = 0x02
SUPPORT_SCANNING_ROW_COL_MASK = 0x04
SUPPORT_SCANNING_PINS_MASK = 0x08
SUPPORT_SCANNING_ARBITRARY_MASK = 0x10
SUPPORT_SCANNING_BUILT_IN_MASK = 0x20

def has_fw_support_scanning(firmwareInfo):
    return (firmwareInfo.scan_support_flags & SUPPORT_SCANNING_MASK) != 0

def has_fw_support_scanning_row_col(firmwareInfo):
    return (firmwareInfo.scan_support_flags & SUPPORT_SCANNING_ROW_COL_MASK) != 0

def has_fw_support_scanning_col_row(firmwareInfo):
    return (firmwareInfo.scan_support_flags & SUPPORT_SCANNING_COL_ROW_MASK) != 0

def has_fw_support_scanning_pins(firmwareInfo):
    return (firmwareInfo.scan_support_flags & SUPPORT_SCANNING_PINS_MASK) != 0

def has_fw_support_scanning_arbitrary(firmwareInfo):
    return (firmwareInfo.scan_support_flags & SUPPORT_SCANNING_ARBITRARY_MASK) != 0

def has_fw_support_scanning_built_in(firmwareInfo):
    return (firmwareInfo.scan_support_flags & SUPPORT_SCANNING_BUILT_IN_MASK) != 0

SUPPORT_KEY_MEDIA = 0x01
SUPPORT_KEY_MOUSE = 0x02
SUPPORT_KEY_LAYERS = 0x04
SUPPORT_KEY_STICKY = 0x08
SUPPORT_KEY_TAP = 0x10
SUPPORT_KEY_HOLD = 0x20

def has_fw_support_key_media(firmwareInfo):
    return (firmwareInfo.keyhandler_support_flags & SUPPORT_KEY_MEDIA) != 0

def has_fw_support_key_mouse(firmwareInfo):
    return (firmwareInfo.keyhandler_support_flags & SUPPORT_KEY_MOUSE) != 0

def has_fw_support_key_layers(firmwareInfo):
    return (firmwareInfo.keyhandler_support_flags & SUPPORT_KEY_LAYERS) != 0

def has_fw_support_key_sticky(firmwareInfo):
    return (firmwareInfo.keyhandler_support_flags & SUPPORT_KEY_STICKY) != 0

def has_fw_support_key_tap(firmwareInfo):
    return (firmwareInfo.keyhandler_support_flags & SUPPORT_KEY_TAP) != 0

def has_fw_support_key_hold(firmwareInfo):
    return (firmwareInfo.keyhandler_support_flags & SUPPORT_KEY_HOLD) != 0

SUPPORT_KRO_N = 0x01;
SUPPORT_KRO_6 = 0x02;

def has_fw_support_nkro(firmwareInfo):
    return (firmwareInfo.kb_support_flags & SUPPORT_KRO_N) != 0
def has_fw_support_6kro(firmwareInfo):
    return (firmwareInfo.kb_support_flags & SUPPORT_KRO_6) != 0

SUPPORT_LED_INDICATORS = 0x01
SUPPORT_LED_BACKLIGHTING = 0x02
SUPPORT_LED_WS2812 = 0x04

def has_fw_support_led_indicators(firmwareInfo):
    return (firmwareInfo.led_support_flags & SUPPORT_LED_INDICATORS) != 0
def has_fw_support_led_backlighting(firmwareInfo):
    return (firmwareInfo.led_support_flags & SUPPORT_LED_BACKLIGHTING) != 0
def has_fw_support_led_ws2812(firmwareInfo):
    return (firmwareInfo.led_support_flags & SUPPORT_LED_WS2812) != 0

SUPPORT_WIRELESS = 0x01
SUPPORT_I2C = 0x02
SUPPORT_UNIFYING = 0x04
SUPPORT_USB = 0x08
SUPPORT_BT = 0x10

def has_fw_support_wireless(firmwareInfo):
    return (firmwareInfo.connectivity_support_flags & SUPPORT_WIRELESS) != 0
def has_fw_support_i2c(firmwareInfo):
    return (firmwareInfo.connectivity_support_flags & SUPPORT_I2C) != 0
def has_fw_support_unifying(firmwareInfo):
    return (firmwareInfo.connectivity_support_flags & SUPPORT_UNIFYING) != 0
def has_fw_support_usb(firmwareInfo):
    return (firmwareInfo.connectivity_support_flags & SUPPORT_USB) != 0
def has_fw_support_bluetooth(firmwareInfo):
    return (firmwareInfo.connectivity_support_flags & SUPPORT_BT) != 0

if __name__ == "__main__":
    import easyhid
    # hid_devs = easyhid.Enumeration(vid=0)
    hid_list = easyhid.Enumeration()
    sub_set = hid_list.filter(vid=0x6666, pid=0x1111, interface=3)
    device = sub_set[0].open()

    print(get_firmware_info(device))
    # print(get_device_info(device))
    # print(get_layers(device, 0))

