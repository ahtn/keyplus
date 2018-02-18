#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

###############################################################################
#                               usb_commands.h                                #
###############################################################################

CMD_ERROR_CODE = 0x00
CMD_GET_INFO = 0x01
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

# USB command errors
CMD_ERROR_CODE_NONE = 0
CMD_ERROR_CODE_TOO_MUCH_DATA = 1
CMD_ERROR_INVALID_VALUE = 2
CMD_ERROR_KEYBOARD_INACTIVE = 3
CMD_ERROR_UNKNOWN_CMD = 4
CMD_ERROR_UNSUPPORTED_COMMAND = 5

CMD_ERROR_CODE_TABLE = {
    CMD_ERROR_CODE_NONE: "CMD_ERROR_CODE_NONE",
    CMD_ERROR_CODE_TOO_MUCH_DATA: "CMD_ERROR_CODE_TOO_MUCH_DATA",
    CMD_ERROR_INVALID_VALUE: "CMD_ERROR_INVALID_VALUE",
    CMD_ERROR_KEYBOARD_INACTIVE: "CMD_ERROR_KEYBOARD_INACTIVE",
    CMD_ERROR_UNKNOWN_CMD: "CMD_ERROR_UNKNOWN_CMD",
    CMD_ERROR_UNSUPPORTED_COMMAND: "CMD_ERROR_UNSUPPORTED_COMMAND",
}

# Values for CMD_GET_INFO
INFO_MAIN_0 = 0
INFO_MAIN_1 = 1
INFO_LAYOUT = 2
INFO_RF = 3
INFO_FIRMWARE = 4
INFO_ERROR_SYSTEM = 5
INFO_UNSUPPORTED = 0xff

# Values for CMD_RESET
RESET_TYPE_HARDWARE = 0
RESET_TYPE_SOFTWARE = 1

