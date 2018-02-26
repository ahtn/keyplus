#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import yaml
import time
from pprint import pprint
from hexdump import hexdump

import keyplus
from keyplus.constants import *
from keyplus.exceptions import KeyplusUSBCommandError

from keyplus.layout import *
from keyplus.device_info import KeyboardPinMapping
from keyplus.keycodes import *

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

    scan_mode.set_debounce_profile("cherry_mx")

    print("scan_mode.to_json:", scan_mode.to_json())

    target = kb.get_device_target()
    scan_plan = scan_mode.generate_scan_plan(target)
    scan_plan_bytes = scan_plan.pack()
    hexdump(scan_plan_bytes)
    new_scan_plan = keyplus.cdata_types.scan_plan_t()
    new_scan_plan.unpack(scan_plan_bytes)
    pprint(("Matches: {}".format(scan_plan == new_scan_plan), new_scan_plan))

    pin_mapping = scan_mode.generate_pin_mapping(target)
    pin_mapping_raw = pin_mapping.pack()
    hexdump(pin_mapping_raw)

    new_pin_mapping = KeyboardPinMapping()
    new_pin_mapping.unpack(pin_mapping_raw, new_scan_plan, target)
    hexdump(new_pin_mapping.pack())

    new_scan_mode = ScanMode()
    new_scan_mode.load_raw_data(new_scan_plan, new_pin_mapping)
    pprint(vars(scan_mode))
    pprint(vars(new_scan_mode))


    layout_settings = kb.get_layout_info()
    hexdump(layout_settings.pack())
    pprint(vars(layout_settings))


    layout_device = LayoutDevice()
    layout_device.load_raw_data(
        kb.device_info, layout_settings, new_pin_mapping
    )

    pprint(vars(layout_device))

    print(("#"*80 + "\n")*3)

    scan_mode_test = ScanMode()
    test_scan_mode_dict = {
        'mode': 'col_row',
        'rows': ['D0', 'D1', 'D2', 'D3'],
        'cols': ['A0', 'A1', 'A2', 'A3', 'A4', 'A5'],
        'matrix_map': [
            'r0c0', 'r0c1', 'r0c2', 'r0c3', 'r0c4', 'r0c5',
            'r1c0', 'r1c1', 'r1c2', 'r1c3', 'r1c4', 'r1c5',
            'r2c0', 'r2c1', 'r2c2', 'r2c3', 'r2c4', 'r2c5',
            'r3c0', 'r3c1', 'r3c2', 'r3c3', 'r3c4', 'r3c5',
        ],
        # 'debounce': 'kailh_box',
        'debounce': {
            "debounce_time_press": 5,
            "debounce_time_release": 10,
            "trigger_time_press": 1,
            "trigger_time_release": 3,
            "parasitic_discharge_delay_idle": 2.0,
            "parasitic_discharge_delay_debouncing": 10.0,
        }
    }
    scan_mode_test.parse_json(test_scan_mode_dict)

    hexdump(scan_mode_test.generate_scan_plan(target).pack())
    hexdump(scan_mode_test.generate_pin_mapping(target).pack())
    pprint(vars(scan_mode_test))

    print(("@"*80 + "\n")*3)

    test_layout_device_dict = {
        'id': 0,
        'layout': 0,
        'layout_offset': 0,
        'scan_mode': test_scan_mode_dict,
    }
    layout_device = LayoutDevice()
    layout_device.parse_json("test_device", json_obj=test_layout_device_dict)

    pprint(vars(layout_device))

    print(("*"*80 + "\n")*3)

    rf_settings = LayoutRFSettings()
    rf_settings.load_random()
    pprint(vars(rf_settings))

    rf_settings = LayoutRFSettings()
    test_rf_settings = {
        "aes_encryption_key": "9febeb27209e131ceaf812f73feed577",
        "rf_channel": 0x08,
        "auto_retransmit_count": 8, # options: 0-15
        # TODO: should include retransmit delay option
        "data_rate":  "2mbps", # options: 2mbps, 1mbps, 250kbps
        "transmit_power": "0dB", # options: 0dB, -6dB, -12dB, -18dB
        "pipe0": '2aef63473c',
        "pipe1": '168d715956',
        "pipe2": 'c1',
        "pipe3": 'fc',
        "pipe4": '63',
        "pipe5": '00',
        "pipe6": '00',
    }
    rf_settings.parse_json(test_rf_settings)

    pprint(vars(rf_settings))
    new_json = rf_settings.to_json()
    print(rf_settings, new_json)
    new_rf_settings = LayoutRFSettings()
    new_rf_settings.parse_json(new_json)

    newest_rf_settings = LayoutRFSettings()
    newest_rf_settings.load_raw_data(kb.rf_info)
    thingy = newest_rf_settings.to_json()
    print("newest_rf_settings:", thingy)

    newest_raw = newest_rf_settings.generate_rf_settings()
    something = newest_raw
    print(something.pack)
    print(something.pack())

    keycode_mapper = KeycodeMapper()
    layout = LayoutKeyboard(
        layout_id = "foo",
        number_layers = 3,
        device_sizes = [3, 5],
    )

    layout.set_keycode(
        layer = 0,
        device = 0,
        key_number = 0,
        keycode = "ca-up"
    )

    layout.set_keycode(
        layer = 1,
        device = 0,
        key_number = 0,
        keycode = "a"
    )
    layout.set_keycode(
        layer = 1,
        device = 0,
        key_number = 1,
        keycode = "b"
    )

    pprint(vars(layout))
    for layer in layout.layer_list:
        pprint(vars(layer))
        for device in layer.device_list:
            pprint(vars(device))

    keycode_mapper = KeycodeMapper()
    pprint(layout.to_json())
    pprint(layout.to_keycodes())

    new_layout = LayoutKeyboard('new')
    new_layout.load_keycodes(layout.to_keycodes())
    print("new_layout: ", end="")
    pprint(new_layout.to_json())
    print("new_layout: ", end="")
    pprint(new_layout.to_keycodes())

    print(kb.read_layout_data(0, 63))
    print()
    layout_data = kb.read_whole_layout()
    print("Full layout data: ")
    hexdump(layout_data)

    unpacked_layout_data = kb.unpack_layout_data()

    for (i, layout) in enumerate(unpacked_layout_data):
        # pprint(vars(layout))
        print("This is layout {}:".format(i))
        print(layout.to_json())
        print()

    keyplus_layout = KeyplusLayout()
    with open("../layouts/arbitrary_map_tester.yaml") as f:
        layout_json = yaml.load(f.read())
    keyplus_layout.parse_json(layout_json)


    # kb.set_passthrough_mode(True)
    kb.disconnect()
