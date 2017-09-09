// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"

#include "core/util.h"
#include "core/layout.h"

void flash_load_rom(XRAM uint8_t* dest, const ROM uint8_t* src, flash_ptr_t len) {
    uint32_t i;
    for (i = 0; i < len; ++i) {
        dest[i] = src[i];
    }
}

bit_t is_valid_storage_pos(flash_ptr_t ptr) {
    return (ptr >= LAYOUT_ADDR) && (ptr < ((uint32_t)LAYOUT_ADDR + (uint32_t)LAYOUT_SIZE) );
}

