#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

class KeyplusError(Exception):
    pass

class KeyplusProtocolError(KeyplusError):
    pass

class KeyplusConnectError(KeyplusError):
    pass


class ProtocolError:
    def get_string(code):
        for (key, value) in ProtocolError.__dict__.items():
            if code == value:
                return key
        return "<Undefined error code>"

class KBProtocolException(Exception):
    def __init__(self, message="", code=None):
        if code:
            message = ProtocolError.get_string(code)
        super(Exception, self).__init__(message)
        self.error_code = code

def raise_error_code(code):
    if code == ProtocolError.ERROR_CODE_NONE:
        pass
    else:
        raise KBProtocolException(code=code)


