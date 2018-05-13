#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from colorama import Fore

from keyplus.constants import *

WARN_COLOR = Fore.GREEN
ERROR_COLOR = Fore.RED

class KeyplusError(Exception):
    pass

class KeyplusConnectError(KeyplusError):
    pass

class KeyplusProtocolError(KeyplusError):
    pass

class KeyplusUnsupportedError(KeyplusError):
    pass

class KeyplusParseError(KeyplusError):
    pass

class KeyplusSettingsError(KeyplusError):
    pass

# Error is a result of internal error in the library and should not be seen
# normally
class KeyplusInternalError(KeyplusError):
    pass

class KeyplusUSBCommandError(KeyplusError):
    def __init__(self, message="", code=None):
        if code:
            message = self.get_string(code)
        super(Exception, self).__init__(message)
        self.code = code

    def get_string(self, code):
        if code in CMD_ERROR_CODE_TABLE:
            return CMD_ERROR_CODE_TABLE[code]
        else:
            return "UnknownCmdErrorCode({})".format(code)

def raise_error_code(code):
    if code == CMD_ERROR_CODE_NONE:
        pass
    else:
        raise KeyplusUSBCommandError(code=code)

def assert_equal(lhs, rhs):
    assert lhs == rhs, AssertionError(
        "Assertion failed lhs '{}' not equal to rhs '{}'".format(lhs, rhs)
    )

def assert_less(lhs, rhs):
    assert lhs < rhs, AssertionError(
        "Assertion failed lhs '{}' is not less than rhs '{}'".format(lhs, rhs)
    )

def assert_less_eq(lhs, rhs):
    assert lhs < rhs, AssertionError(
        "Assertion failed lhs '{}' is not less than rhs '{}'".format(lhs, rhs)
    )
