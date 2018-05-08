#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from keyplus.version import __version__

IS_PRE_RELASE = ('pre' in __version__)

class DEBUG(object):
    """
    The static variables in this class can be used to turn on and off debug
    messages.
    """
    usb_cmd_timing = False and IS_PRE_RELASE
    usb_cmd = True and IS_PRE_RELASE
    parsing = False and IS_PRE_RELASE
    parsing_extra = False and IS_PRE_RELASE
    layout = False and IS_PRE_RELASE
    gui = True and IS_PRE_RELASE
