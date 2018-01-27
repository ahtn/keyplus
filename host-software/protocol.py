#!/usr/bin/env python
# -*- coding: utf-8 -*-

import collections
import struct
import hexdump
import datetime

from uniflash.crc16 import crc16_bytes

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
CMD_UPDATE_SETTINGS = 0x0A
CMD_UPDATE_LAYOUT = 0x0B

CMD_UNIFYING_PAIR = 0x10

INFO_MAIN_0 = 0
INFO_MAIN_1 = 1
INFO_LAYOUT = 2
INFO_RF = 3
INFO_FIRMWARE = 4
INFO_ERROR_SYSTEM = 5
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

RF_DR_LOW = 5
RF_DR_HIGH = 3
RF_DR_250KBPS  = (1 << RF_DR_LOW)
RF_DR_1MBPS    = 0
RF_DR_2MBPS    = (1 << RF_DR_HIGH)

MAX_NUMBER_LAYOUTS = 64
MAX_NUMBER_DEVICES = 64

FEATURE_CTRL_USB_DISABLE      = (1 << 0)
FEATURE_CTRL_WIRED_DISABLE    = (1 << 1)
FEATURE_CTRL_RF_DISABLE       = (1 << 2)
FEATURE_CTRL_RF_MOUSE_DISABLE = (1 << 3)
FEATURE_CTRL_BT_DISABLE       = (1 << 4)
FEATURE_CTRL_RESERVED_0       = (1 << 5)
FEATURE_CTRL_RESERVED_1       = (1 << 6)
FEATURE_CTRL_RESERVED_2       = (1 << 7)


class ProtocolError:
    ERROR_CODE_NONE = 0
    ERROR_CODE_TOO_MUCH_DATA = 1
    ERROR_INVALID_VALUE = 2
    ERROR_KEYBOARD_INACTIVE = 3
    ERROR_UNKNOWN_CMD = 4
    ERROR_UNSUPPORTED_COMMAND = 5

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
        raise KBProtocolException(code=code)


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

def get_supported_features(device):
    pass

def get_layers(device, layout_id):
    response = simple_command(device, CMD_GET_LAYER, [layout_id])
    return struct.unpack_from("<B HHH", response)


KBInfoMainNamedTuple = collections.namedtuple("KBInfoMain",
    "id name timestamp default_report_mode "
    "scan_mode row_count col_count feature_ctrl reserved crc"
)

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

    def has_usb_disabled(self):
        return bool(self.feature_ctrl & FEATURE_CTRL_USB_DISABLE)

    def has_i2c_disabled(self):
        return bool(self.feature_ctrl & FEATURE_CTRL_WIRED_DISABLE)

    def has_nrf24_disabled(self):
        return bool(self.feature_ctrl & FEATURE_CTRL_RF_DISABLE)

    def has_unifying_mouse_disabled(self):
        return bool(self.feature_ctrl & FEATURE_CTRL_RF_MOUSE_DISABLE)

    def has_bluetooth_disabled(self):
        return bool(self.feature_ctrl & FEATURE_CTRL_BT_DISABLE)


def get_device_info(device):
    DEVICE_INFO_SIZE = 96
    response = simple_command(device, CMD_GET_DEVICE_SETTINGS, [INFO_MAIN_0])[1:]
    response += simple_command(device, CMD_GET_DEVICE_SETTINGS, [INFO_MAIN_1])[1:]
    response = response[0:DEVICE_INFO_SIZE]

    # check if the flash has been initialized
    is_empty = sum([1 for byte in response if byte != 0xff]) == 0

    # uint8_t device_id;
    # char device_name[32];
    # uint8_t timestamp[8]; // utc time stamp of last update
    # uint8_t default_report_mode;
    # uint8_t scan_mode;
    # uint8_t row_count;
    # uint8_t col_count;
    # uint8_t feature_ctrl;
    # uint8_t _reserved[48];
    # uint16_t crc; // total size == 96

    crc = crc16_bytes(response[:DEVICE_INFO_SIZE-2])

    x = struct.unpack("< B 32s q 5B 48s H", response)
    return KBInfoMain._make_with_crc(x, crc, is_empty)

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

class KBInfoErrorSystem(object):
    NUM_ERROR_CODES = 128
    SIZE_ERROR_CODE_TABLE = NUM_ERROR_CODES // 8
    CRITICAL_ERROR_START = 64

    # ERROR_EKC_OUT_OF_BOUNDS_ACCESS = 0
    # ERROR_UNHANDLED_KEYCODE = 1
    # ERROR_RECEIVED_TOO_LARGE_DEVICE_ID = 2
    # ERROR_RECEIVED_TOO_LARGE_MATRIX = 3
    # ERROR_KEY_EVENT_QUEUE_FULL = 4
    # ERROR_KEY_EVENT_QUEUE_UNLOADED_DEVICE = 5

    # ERROR_EKC_STORAGE_TOO_LARGE = 64
    # ERROR_NUM_LAYOUTS_TOO_LARGE = 65
    # ERROR_SETTINGS_CRC_MISMATCH = 66
    # ERROR_LAYOUT_STORAGE_OUT_OF_BOUNDS = 67

    ERROR_CODE_MAP = {
         0: "ERROR_EKC_OUT_OF_BOUNDS_ACCESS",
         1: "ERROR_UNHANDLED_KEYCODE",
         2: "ERROR_RECEIVED_TOO_LARGE_DEVICE_ID",
         3: "ERROR_RECEIVED_TOO_LARGE_MATRIX",
         4: "ERROR_KEY_EVENT_QUEUE_FULL",
         5: "ERROR_KEY_EVENT_QUEUE_UNLOADED_DEVICE",

         64: "ERROR_EKC_STORAGE_TOO_LARGE",
         65: "ERROR_NUM_LAYOUTS_TOO_LARGE",
         66: "ERROR_SETTINGS_CRC_MISMATCH",
         67: "ERROR_LAYOUT_STORAGE_OUT_OF_BOUNDS",
    }

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
        if code in self.ERROR_CODE_MAP:
            return self.ERROR_CODE_MAP[code]
        else:
            return "<UNKNOWN_ERROR_CODE>"


    def has_critical_error(self):
        return self._has_critical_error

def get_error_info(device):
    response = simple_command(device, CMD_GET_DEVICE_SETTINGS, [INFO_ERROR_SYSTEM])[1:]

    x = KBInfoErrorSystem.SIZE_ERROR_CODE_TABLE
    error_table = response[:KBInfoErrorSystem.SIZE_ERROR_CODE_TABLE]

    return KBInfoErrorSystem(error_table)



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
    reserved
    """
)

class KBInfoFirmware(KBInfoFirmwareNamedTuple):
    SUPPORT_SCANNING_MASK = 0x01
    SUPPORT_SCANNING_COL_ROW_MASK = 0x02
    SUPPORT_SCANNING_ROW_COL_MASK = 0x04
    SUPPORT_SCANNING_PINS_MASK = 0x08
    SUPPORT_SCANNING_ARBITRARY_MASK = 0x10
    SUPPORT_SCANNING_BUILT_IN_MASK = 0x20

    def has_fw_support_scanning(self):
        return (self.scan_support_flags & self.SUPPORT_SCANNING_MASK) != 0

    def has_fw_support_scanning_row_col(self):
        return (self.scan_support_flags & self.SUPPORT_SCANNING_ROW_COL_MASK) != 0

    def has_fw_support_scanning_col_row(self):
        return (self.scan_support_flags & self.SUPPORT_SCANNING_COL_ROW_MASK) != 0

    def has_fw_support_scanning_pins(self):
        return (self.scan_support_flags & self.SUPPORT_SCANNING_PINS_MASK) != 0

    def has_fw_support_scanning_arbitrary(self):
        return (self.scan_support_flags & self.SUPPORT_SCANNING_ARBITRARY_MASK) != 0

    def has_fw_support_scanning_built_in(self):
        return (self.scan_support_flags & self.SUPPORT_SCANNING_BUILT_IN_MASK) != 0

    SUPPORT_KEY_MEDIA = 0x01
    SUPPORT_KEY_MOUSE = 0x02
    SUPPORT_KEY_LAYERS = 0x04
    SUPPORT_KEY_STICKY = 0x08
    SUPPORT_KEY_TAP = 0x10
    SUPPORT_KEY_HOLD = 0x20

    def has_fw_support_key_media(self):
        return (self.keyhandler_support_flags & self.SUPPORT_KEY_MEDIA) != 0

    def has_fw_support_key_mouse(self):
        return (self.keyhandler_support_flags & self.SUPPORT_KEY_MOUSE) != 0

    def has_fw_support_key_layers(self):
        return (self.keyhandler_support_flags & self.SUPPORT_KEY_LAYERS) != 0

    def has_fw_support_key_sticky(self):
        return (self.keyhandler_support_flags & self.SUPPORT_KEY_STICKY) != 0

    def has_fw_support_key_tap(self):
        return (self.keyhandler_support_flags & self.SUPPORT_KEY_TAP) != 0

    def has_fw_support_key_hold(self):
        return (self.keyhandler_support_flags & self.SUPPORT_KEY_HOLD) != 0

    SUPPORT_KRO_N = 0x01;
    SUPPORT_KRO_6 = 0x02;

    def has_fw_support_nkro(self):
        return (self.kb_support_flags & self.SUPPORT_KRO_N) != 0
    def has_fw_support_6kro(self):
        return (self.kb_support_flags & self.SUPPORT_KRO_6) != 0

    SUPPORT_LED_INDICATORS = 0x01
    SUPPORT_LED_BACKLIGHTING = 0x02
    SUPPORT_LED_WS2812 = 0x04

    def has_fw_support_led_indicators(self):
        return (self.led_support_flags & self.SUPPORT_LED_INDICATORS) != 0
    def has_fw_support_led_backlighting(self):
        return (self.led_support_flags & self.SUPPORT_LED_BACKLIGHTING) != 0
    def has_fw_support_led_ws2812(self):
        return (self.led_support_flags & self.SUPPORT_LED_WS2812) != 0

    SUPPORT_NRF24 = 0x01
    SUPPORT_I2C = 0x02
    SUPPORT_UNIFYING = 0x04
    SUPPORT_USB = 0x08
    SUPPORT_BT = 0x10

    def has_fw_support_nrf24(self):
        return (self.connectivity_support_flags & self.SUPPORT_NRF24) != 0
    def has_fw_support_i2c(self):
        return (self.connectivity_support_flags & self.SUPPORT_I2C) != 0
    def has_fw_support_unifying(self):
        return (self.connectivity_support_flags & self.SUPPORT_UNIFYING) != 0
    def has_fw_support_usb(self):
        return (self.connectivity_support_flags & self.SUPPORT_USB) != 0
    def has_fw_support_bluetooth(self):
        return (self.connectivity_support_flags & self.SUPPORT_BT) != 0

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


    # uint8_t reserved[31];

    response = simple_command(device, CMD_GET_DEVICE_SETTINGS, [INFO_FIRMWARE])[1:]

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

def begin_pairing(device):
    response = simple_command(device, CMD_UNIFYING_PAIR, receive=False)
    return response

def set_indicator_led(device, state):
    response = simple_command(device, CMD_LED_CONTROL, [state], receive=False)
    return response

def reset_device(device):
    response = simple_command(device, CMD_RESET, receive=False)
    return response

def get_chunks(data, chunk_size, pad=0xff):
    chunk_data = None
    remainder = len(data) % chunk_size
    if remainder != 0:
        chunk_data = data[:] + bytearray([pad] * (chunk_size - remainder))
    else:
        chunk_data = data
    return [bytes(chunk_data[i*chunk_size:(i+1)*chunk_size]) for i in range(len(chunk_data)//chunk_size)]

RF_INFO_SIZE = 64
SETTINGS_SIZE = 512

def update_settings_section(device, settings_data, keep_rf=0):
    simple_command(device, CMD_UPDATE_SETTINGS, [keep_rf])

    size = SETTINGS_SIZE
    if (keep_rf):
        size = SETTINGS_SIZE - RF_INFO_SIZE
    chunk_list = get_chunks(settings_data[0:size], EP_VENDOR_SIZE)

    for chunk in chunk_list:
        device.write(chunk)
        device.read()

def update_layout_section(device, layout_data):
    chunk_list = get_chunks(layout_data, EP_VENDOR_SIZE)

    simple_command(device, CMD_UPDATE_LAYOUT, [len(chunk_list)])

    for chunk in chunk_list:
        device.write(chunk)
        response = device.read()

REPORT_MODE_STR_MAP = {
    KEYBOARD_REPORT_MODE_AUTO: "Auto NKRO",
    KEYBOARD_REPORT_MODE_6KRO: "6KRO",
    KEYBOARD_REPORT_MODE_NKRO: "NKRO",
}

def report_mode_to_str(mode):
    if mode in REPORT_MODE_STR_MAP:
        return REPORT_MODE_STR_MAP[mode]
    else:
        return "Unknown({})".format(mode)

SCAN_MODE_STR_MAP = {
    MATRIX_SCANNER_MODE_NONE: "none",
    MATRIX_SCANNER_MODE_COL_ROW: "diodes column to row",
    MATRIX_SCANNER_MODE_ROW_COL: "diodes row to column",
    MATRIX_SCANNER_MODE_PINS: "pins",
}
def scan_mode_to_str(mode):
    if mode in SCAN_MODE_STR_MAP:
        return SCAN_MODE_STR_MAP[mode]
    else:
        return "Unknown({})".format(mode)

POWER_STR_MAP = {
    PWR_NEG_18DB: "-18dB",
    PWR_NEG_12DB: "-12dB",
    PWR_NEG_6DB: "-6dB",
    PWR_0DB: "0dB",
}
def power_to_str(mode):
    if mode in POWER_STR_MAP:
        return POWER_STR_MAP[mode]
    else:
        return "Unknown({})".format(mode)

DATA_RATE_STR_MAP = {
    RF_DR_250KBPS: "250kbps",
    RF_DR_1MBPS: "1mbps",
    RF_DR_2MBPS: "2mbps",
}
def data_rate_to_str(rate):
    if rate in DATA_RATE_STR_MAP:
        return DATA_RATE_STR_MAP[rate]
    else:
        return "Unknown({})".format(rate)

def timestamp_to_str(timestamp_raw):
    if timestamp_raw == 0:
        return '<Unavailable>'
    else:
        try:
            return str(datetime.datetime.fromtimestamp(timestamp_raw))
        except OSError:
            return str(hex(timestamp_raw))

if __name__ == "__main__":
    import easyhid
    # hid_devs = easyhid.Enumeration(vid=0)
    hid_list = easyhid.Enumeration()
    sub_set = hid_list.find(vid=0x6666, pid=0x1111, interface=3)
    print(sub_set)
    device = sub_set[0]
    device.open()

    # print(get_firmware_info(device))
    # print(get_device_info(device))
    update_settings_section(device, bytes([i%256 for i in range(512)]), keep_rf=1)
