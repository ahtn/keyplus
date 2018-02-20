#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import hexdump
import time

import keyplus

from pprint import pprint


from keyplus.constants import *
from keyplus.exceptions import KeyplusUSBCommandError

from keyplus.layout import ScanMode
from keyplus.device_info import KeyboardPinMapping

import keyplus.cdata_types


if __name__ == '__main__':
    dev_list = keyplus.find_devices()
    print(dev_list)
    kb = dev_list[0]
    kb.connect()

    if 0:
        led = 0
        led_state = 0
        for _ in range(6):
            led_state = not led_state
            kb.set_indicator_led(led, led_state)
            time.sleep(0.5)
        kb.reset()
        time.sleep(3)
        kb.reconnect()
        kb.set_indicator_led(led, not led_state)

    if 1:
        for kb_id in range(64):
            try:
                print("layer info: ", kb.get_layers(kb_id))
            except KeyplusUSBCommandError as err:
                if err.code == CMD_ERROR_KEYBOARD_INACTIVE:
                    continue
                else:
                    raise err

    print("name:", kb.device_info.device_name)
    print("nrf24_disabled:", kb.device_info.nrf24_disabled)
    print("i2c_disabled:", kb.device_info.i2c_disabled)


    scan_mode = ScanMode()

    scan_mode.set_scan_mode('row_col')
    scan_mode.add_row_pins(['D0', 'D1', 'D2', 'D3'])

    if 1:
        scan_mode.add_column_pins(['A0', 'A1', 'A2', 'A3', 'A4', 'A5'])
        for row in range(4):
            for col in range(6):
                if col == row:
                    continue
                scan_mode.add_key_to_matrix_map(row*6+col, row, col)
    else:
        scan_mode.add_column_pins(['A5', 'A4', 'A3', 'A2', 'A1', 'A0'])
        for row in range(4):
            for col in range(6):
                # Note: reverse column position in row
                scan_mode.add_key_to_matrix_map(row*6+(5-col), row, col)

    target = kb.get_device_target()
    scan_plan = scan_mode.generate_scan_plan(target)
    scan_plan_bytes = scan_plan.pack()
    hexdump.hexdump(scan_plan_bytes)
    new_scan_plan = keyplus.cdata_types.scan_plan_t()
    new_scan_plan.unpack(scan_plan_bytes)
    pprint(("Matches: {}".format(scan_plan == new_scan_plan), new_scan_plan))

    pin_mapping = scan_mode.generate_pin_mapping(target)
    pin_mapping_raw = pin_mapping.pack()
    hexdump.hexdump(pin_mapping_raw)

    new_pin_mapping = KeyboardPinMapping()
    new_pin_mapping.unpack(pin_mapping_raw, new_scan_plan, target)
    hexdump.hexdump(new_pin_mapping.pack())

    new_scan_mode = ScanMode()
    new_scan_mode.load_raw_data(new_scan_plan, new_pin_mapping)
    pprint(vars(scan_mode))
    pprint(vars(new_scan_mode))


    # kb.set_passthrough_mode(True)
    kb.disconnect()
