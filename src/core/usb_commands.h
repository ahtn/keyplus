//
// MIT License
//
// Copyright (c) 2017 seethis.link
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#pragma once

#include <stdint.h>
#include "core/util.h"

#define CHUNKS_PER_PAGE (PAGE_SIZE / EP_SIZE_VENDOR)

// USB commands. These values are also attached to response packets to indicate
// the packet type.
enum usb_vendor_cmd_t {
    CMD_ERROR_CODE = 0x00, // the response from the controller
    CMD_GET_DEVICE_SETTINGS = 0x01, // flash keyboard layout
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

    CMD_UNIFYING_PAIR = 0x10, // enter pairing mode
};

enum {
    ERROR_CODE_NONE = 0,
    ERROR_CODE_TOO_MUCH_DATA = 1,
    ERROR_INVALID_VALUE = 2,
    ERROR_KEYBOARD_INACTIVE = 3,
    ERROR_UNKNOWN_CMD = 4,
    ERROR_UNSUPPORTED_COMMAND = 5,
};

enum usb_vendor_state {
    STATE_WAIT_CMD, // wait for next cmd
    STATE_SCAN,
    STATE_WRITE_FLASH,
};

enum {
    SETTING_UPDATE_ALL = 0,
    SETTING_UPDATE_KEEP_RF = 1,
};

enum {
    INFO_MAIN_0 = 0,
    INFO_MAIN_1 = 1,
    INFO_LAYOUT = 2,
    INFO_RF = 3,
    INFO_FIRMWARE = 4,
    INFO_UNSUPPORTED = 0xff,
};

uint8_t usb_print(const uint8_t *data, uint8_t len);
void usb_blocking_print(const uint8_t *data, uint8_t len);
void reset_usb_reports(void);
void cmd_send_layer(uint8_t kb_id);
void handle_vendor_out_reports(void);
bit_t is_passthrough_enabled(void);
