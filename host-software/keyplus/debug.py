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
    usb_cmd_timing = True
    usb_cmd = True
    parsing = False
    parsing_extra = False

