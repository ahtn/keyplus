// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"

#include "core/layout.h"
#include "core/util.h"

void flash_load_from_rom(XRAM uint8_t* dest, const ROM uint8_t* src, flash_addr_t len) {
    while (len--) {
        *(dest++) = *(src++);
    }
}

bit_t is_valid_storage_pos(flash_addr_t ptr) {
#if USE_VIRTUAL_MODE
    return (ptr >= 0) && (ptr < LAYOUT_SIZE);
#else
    return (ptr >= LAYOUT_ADDR) && (ptr < ((uint32_t)LAYOUT_ADDR + (uint32_t)LAYOUT_SIZE) );
#endif
}

#if USE_VIRTUAL_MODE
    #include <string.h>
    #include "core/debug.h"

    uint8_t g_virtual_storage[SETTINGS_SIZE + LAYOUT_SIZE];

    uint8_t flash_read_byte(flash_addr_t addr) {
        assert(addr < VIRTUAL_STORAGE_SIZE);
        return g_virtual_storage[addr];
    }

    // TODO: rename this, since ARM has 32 bit word size, but this is 16 bit
    uint16_t flash_read_word(flash_addr_t addr) {
        assert((addr+1) < VIRTUAL_STORAGE_SIZE);
        return *((uint16_t *)(g_virtual_storage+addr));
    }

    void flash_read(uint8_t* dest, flash_addr_t addr, flash_size_t len) {
        assert((addr+len) < VIRTUAL_STORAGE_SIZE);
        memcpy(dest, g_virtual_storage+addr, len);
    }

    uint8_t *virtual_storage_get_address(flash_addr_t addr) {
        assert(addr < VIRTUAL_STORAGE_SIZE);
        return &g_virtual_storage[addr];
    }
#endif
