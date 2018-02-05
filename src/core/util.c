// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/util.h"

#ifdef INTEL_8052
ROM const uint8_t bit_lookup[8] = {
    (1 << 0),
    (1 << 1),
    (1 << 2),
    (1 << 3),
    (1 << 4),
    (1 << 5),
    (1 << 6),
    (1 << 7),
};

bit_t bitn(uint8_t byte, uint8_t n) {
    return (byte & bit_lookup[n]);
}
#else
bit_t bitn(uint8_t byte, uint8_t n) {
    if (byte & (1 << n)) {
        return true;
    } else {
        return false;
    }
}
#endif

uint8_t is_buffer_zeroed(uint8_t *buffer, uint8_t len) {
    uint8_t i;
    for (i = 0; i < len; ++i) {
        if (buffer[i] != 0) {
            return 0;
        }
    }
    return 1;
}

