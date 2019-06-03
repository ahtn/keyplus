// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/error.h"

#include <string.h>

XRAM uint8_t g_error_code_table[SIZE_ERROR_CODE_TABLE];

static XRAM uint8_t s_has_critical_error;

void init_error_system(void) {
    memset(g_error_code_table, 0, SIZE_ERROR_CODE_TABLE);
    s_has_critical_error = false;
}

bit_t has_critical_error(void) {
    return s_has_critical_error;
}

void register_error(uint8_t code) {
    if (code >= CRITICAL_ERROR_START) {
        s_has_critical_error = true;
    }

    g_error_code_table[code / 8] =
        g_error_code_table[code / 8] | (1 << (code % 8));
}

void unregister_error(uint8_t code) {
    uint8_t i;
    uint8_t critical_errors = 0;

    g_error_code_table[code / 8] &= (1 << (code % 8));

    for (i = 0; i < CRITICAL_ERROR_START/8; ++i) {
        critical_errors |= g_error_code_table[i];
    }

    if (!critical_errors) {
        s_has_critical_error = false;
    }
}
