#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from keyplus.exceptions import KeyplusProtocolError
from keyplus.constants import ERROR_CODE_MAP

class KeyplusErrorTable(object):
    NUM_ERROR_CODES = 128
    SIZE_ERROR_CODE_TABLE = NUM_ERROR_CODES // 8
    CRITICAL_ERROR_START = 64

    def __init__(self, error_table):
        self._error_table = error_table;

        if len(error_table) != self.SIZE_ERROR_CODE_TABLE:
            raise KeyplusProtocolError(
                "Invalid size for error table, expected {} bytes but got {}"
                .format(self.SIZE_ERROR_CODE_TABLE, len(error_table))
            )

        for i in range(self.CRITICAL_ERROR_START//8, self.SIZE_ERROR_CODE_TABLE):
            if self._error_table[i] != 0:
                self._has_critical_error = True

    def get_error_codes(self):
        result = []
        for (byte_i, byte) in enumerate(self._error_table):
            if byte == 0:
                continue;
            for bit_i in range(8):
                if byte & (1 << bit_i):
                    error_code = byte_i * 8 + bit_i
                    result.append(error_code)
        return result

    def error_code_to_name(self, code):
        if code in ERROR_CODE_MAP:
            return ERROR_CODE_MAP[code]
        else:
            return "UnknownErrorCode({})".format(code)


    def has_critical_error(self):
        return self._has_critical_error
