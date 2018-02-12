// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/util.h"

#ifdef __SDCC_mcs51
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

bit_t is_bitn_set(uint8_t byte, uint8_t n) {
    return (byte & bit_lookup[n]);
}

uint8_t bitn_mask(uint8_t n) {
    return bit_lookup[n];
}

bit_t bitmap_get_bit(uint8_t *array, uint8_t n) {
    return is_bitn_set(array[n / 8], n%8);
}

void bitmap_set_bit(uint8_t *array, uint8_t n) {
    array[n / 8] |= (bitn_mask(n % 8));
}

void bitmap_clear_bit(uint8_t *array, uint8_t n) {
    array[n / 8] &= ~(bitn_mask(n % 8));
}
#endif
