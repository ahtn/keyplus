#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import io_map.chip_id
import io_map.xmega

from io_map.common import *

IO_MAPPER_LOOKUP_TABLE = {
    ('XMEGA', '') : io_map.xmega.IoMapperXmega,
}

def get_io_mapper_for_chip(chip_id):
    chip = io_map.chip_id.lookup_chip_id(chip_id)
    for key in IO_MAPPER_LOOKUP_TABLE:
        arch = key[0]
        series = key[1]

        if arch in chip.architecture and series in chip.series:
            return IO_MAPPER_LOOKUP_TABLE[key](chip_id)
    return None
