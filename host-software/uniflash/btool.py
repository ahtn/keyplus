#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

def u16(x):
    return x & 0xffff

def little_endian_u16(data):
    return (data[0]) | (data[1] << 8)

def big_endian_u16(data):
    return (data[0] << 8) | (data[1])

def u8(x):
    return x & 0xff

def hi(x):
    return u8(x >> 8)

def lo(x):
    return u8(x)

