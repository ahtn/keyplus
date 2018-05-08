#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import keyplus.io_map.xmega
import keyplus.io_map.mega
import keyplus.io_map.efm8
import keyplus.chip_id

from keyplus.exceptions import KeyplusSettingsError

IO_MAPPER_LOOKUP_TABLE = {
    'AVR_XMEGA' : keyplus.io_map.xmega.IoMapperXmega,
    'AVR_MEGA' : keyplus.io_map.mega.IoMapperAVRMega,
    'EFM8' : keyplus.io_map.efm8.IoMapperEFM8,
}

def get_io_mapper_for_chip(chip_id):
    chip = keyplus.chip_id.lookup_chip_id(chip_id)
    if chip.architecture in IO_MAPPER_LOOKUP_TABLE:
        return IO_MAPPER_LOOKUP_TABLE[chip.architecture](chip_id)
    else:
        return None

