#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import hexdump

from layout.parser import SettingsGenerator, ParseError
from layout.rf_settings import RFSettings

import yaml

if __name__ == "__main__":
    layout = None
    rf = None

    with open("test_layout.yaml") as file_name:
        layout = yaml.safe_load(file_name.read())
    with open("test_rf_config.yaml") as file_name:
        rf = yaml.safe_load(file_name.read())

    settings = SettingsGenerator(layout_data=layout, rf_settings=rf)

    target_layout_id = 0x30

    print("settings:")
    try:
        hexdump.hexdump(bytes(settings.gen_settings_section(target_layout_id)))
    except ParseError as e:
        print(e)
        # print(e.with_traceback())
        exit(1)

    print("layout:")
    try:
        hexdump.hexdump(bytes(settings.gen_layout_section(target_layout_id)))
    except ParseError as e:
        print(e)
        exit(1)

    print()
    print()
    rf_settings = RFSettings.from_rand()
    print(rf_settings.to_json_obj())
    print(rf_settings.to_yaml())
    hexdump.hexdump(bytes(rf_settings.to_bytes()))

    with open("_ignore_rf_settings.yaml") as file_name:
        rf = yaml.safe_load(file_name.read())
    settings = SettingsGenerator(layout_data=layout, rf_settings=rf)
    print("layout:")
    try:
        hexdump.hexdump(bytes(settings.gen_layout_section(10)))
    except ParseError as e:
        print(e)
        exit(1)

    print("settings:")
    try:
        hexdump.hexdump(bytes(settings.gen_settings_section(10)))
    except ParseError as e:
        print(e)
        exit(1)

