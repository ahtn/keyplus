#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

PWR_NEG_18DB = 0x00
PWR_NEG_12DB = 0x01
PWR_NEG_6DB = 0x02
PWR_0DB = 0x03

POWER_STR_MAP = {
    PWR_NEG_18DB: "-18dB",
    PWR_NEG_12DB: "-12dB",
    PWR_NEG_6DB: "-6dB",
    PWR_0DB: "0dB",
}

RF_DR_LOW = 5
RF_DR_HIGH = 3
RF_DR_250KBPS  = (1 << RF_DR_LOW)
RF_DR_1MBPS    = 0
RF_DR_2MBPS    = (1 << RF_DR_HIGH)

DATA_RATE_STR_MAP = {
    RF_DR_250KBPS: "250kbps",
    RF_DR_1MBPS: "1mbps",
    RF_DR_2MBPS: "2mbps",
}
