#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import six

from keyplus.utility.crc16 import crc16_bytes, is_valid_crc16, crc16
from keyplus.utility.round_keys import gen_final_round_key

def list_to_map(list_):
    return dict({(i, v) for (i, v) in enumerate(list_)})

def inverse_map(mapping):
    return dict([v, k] for (k, v) in six.iteritems(mapping))

def uint24_le(data):
    return [
        (data >>  0) & 0xff,
        (data >>  8) & 0xff,
        (data >> 16) & 0xff,
    ]
