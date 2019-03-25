// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include "core/util.h"

#define CHUNKS_PER_PAGE (PAGE_SIZE / EP_SIZE_VENDOR)

// USB commands. These values are also attached to response packets to indicate
// the packet type.
enum usb_vendor_cmd_t {
    CMD_ERROR_CODE = 0x00, // the response from the controller
    CMD_GET_INFO = 0x01, // get device information from the keyboard
    CMD_LED_CONTROL = 0x02, // control leds on the keyboard/receiver
    CMD_RESET = 0x03, // reset the dongle
    CMD_BOOTLOADER = 0x04, // go to the bootloader
    CMD_LAYER_STATE = 0x05, // the active layer
    CMD_LOGITECH_BOOTLOADER = 0x06, // go to the logitech bootloader
    CMD_PRINT = 0x07, // send debug data
    CMD_SET_PASSTHROUGH_MODE = 0x08, // set passthrough mode
    CMD_PASSTHROUGH_MATRIX = 0x09, // raw matrix data sent to the host without interpretting it
    CMD_UPDATE_SETTINGS = 0x0A,
    CMD_UPDATE_LAYOUT = 0x0B, // flash keyboard layout
    CMD_READ_LAYOUT = 0x0C, // read keyboard layout
    CMD_WRITE_FLASH = 0x0D, // write data to flash

    CMD_UNIFYING_PAIR = 0x10, // enter pairing mode
    CMD_UNIFYING_SEND = 0x11, //< send data as a unifying packet

    CMD_UNIFYING_RECV_SHORT = 0x50, //< received HID++ packet
    CMD_UNIFYING_RECV_LONG  = 0x51, //< received HID++ packet

    CMD_NOP = 0xff, // do nothing, can be used to get an acknowledgement from slave
};

enum {
    CMD_ERROR_CODE_NONE = 0,
    CMD_ERROR_CODE_TOO_MUCH_DATA = 1,
    CMD_ERROR_INVALID_VALUE = 2,
    CMD_ERROR_KEYBOARD_INACTIVE = 3,
    CMD_ERROR_UNKNOWN_CMD = 4,
    CMD_ERROR_UNSUPPORTED_COMMAND = 5,
    CMD_ERROR_BUSY = 6,
};

enum usb_vendor_state {
    STATE_WAIT_CMD, // wait for next cmd
    STATE_SCAN,
    STATE_WRITE_FLASH,
};

/// Settings update type
enum {
    SETTING_UPDATE_ALL = 0,
    SETTING_UPDATE_KEEP_RF = 1,
};

enum {
    STATIC_LENGTH_CMD = 0,
    VARIABLE_LENGTH_CMD = 1,
};

enum {
    INFO_MAIN_0 = 0,
    INFO_MAIN_1 = 1,
    INFO_LAYOUT_HEADER = 2, // TODO: deprecate this
    INFO_RF = 3,
    INFO_FIRMWARE = 4,
    INFO_ERROR_SYSTEM = 5,
    INFO_LAYOUT_DATA_0 = 6, // 62
    INFO_LAYOUT_DATA_1 = 7, // 124
    INFO_LAYOUT_DATA_2 = 8, // 186
    INFO_LAYOUT_DATA_3 = 9, // 248
    INFO_LAYOUT_DATA_4 = 10, // 310
    INFO_LAYOUT_DATA_5 = 11, // 372
    INFO_UNSUPPORTED = 0xff,
};

#define INFO_NUM_LAYOUT_DATA_PAGES (INFO_LAYOUT_DATA_5 - INFO_LAYOUT_DATA_0 + 1)

enum {
    RESET_TYPE_HARDWARE = 0,
    RESET_TYPE_SOFTWARE = 1,
};

#define USB_PRINT_TEXT(text) (usb_print(text, sizeof(text)))
#define USB_PRINT_VAR(variable) (usb_print(&variable, sizeof(variable)))
#define USB_PRINT_CONST(value) do { \
    uint32_t x = value; \
    usb_print(&x, sizeof(uint32_t)); \
} while(0)

uint8_t usb_print(const void* data, uint8_t len);

void reset_usb_reports(void);
void cmd_send_layer(uint8_t kb_id);
void handle_vendor_out_reports(void);
bit_t is_passthrough_enabled(void);

void queue_vendor_in_packet(
    uint8_t usb_cmd,
    const XRAM uint8_t *payload,
    uint8_t payload_length,
    bool is_variable_length
);
