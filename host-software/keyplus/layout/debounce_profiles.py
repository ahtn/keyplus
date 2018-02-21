#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

DEBOUNCE_PROFILE_TABLE = {
    "default": {
        "debounce_time_press": 5,
        "debounce_time_release": 10,
        "trigger_time_press": 1,
        "trigger_time_release": 3,
        "parasitic_discharge_delay_idle": 2.0,
        "parasitic_discharge_delay_debouncing": 10.0,
    },
    "cherry_mx": {
        "debounce_time_press": 5,
        "debounce_time_release": 5,
        "trigger_time_press": 0,
        "trigger_time_release": 2,
        "parasitic_discharge_delay_idle": 2.0,
        "parasitic_discharge_delay_debouncing": 10.0,
    },
    "kailh_box": {
        "debounce_time_press": 8,
        "debounce_time_release": 8,
        "trigger_time_press": 2,
        "trigger_time_release": 3,
        "parasitic_discharge_delay_idle": 2.0,
        "parasitic_discharge_delay_debouncing": 10.0,
    },
}
