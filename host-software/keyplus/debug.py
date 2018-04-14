#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

class DEBUG(object):
    """
    The static variables in this class can be used to turn on and off debug
    messages.
    """
    usb_cmd_timing = False
    usb_cmd = False
    parsing = False
    parsing_extra = False
    layout = False
    gui = False
