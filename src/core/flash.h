// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "config.h"

#include "core/hardware.h"
#include "core/util.h"

#ifndef NO_FLASH_MODULE

#define SETTINGS_SIZE       (0x0200)

#ifndef SETTINGS_ADDR
    #define SETTINGS_ADDR         ((flash_ptr_t)&g_settings)
#endif

#ifndef LAYOUT_ADDR
    #define LAYOUT_ADDR         ((flash_ptr_t)&g_layout_storage[0])
#endif

// NOTE: We want to fix the locations of these structures because we will be
// reprogramming when we update the layout. We want to reserve space for them,
// and have them page aligned.
#ifdef __SDCC_mcs51
    #define AT__SETTINGS_ADDR AT(SETTINGS_ADDR) ROM
#else
    #define AT__SETTINGS_ADDR __attribute__ ((section (".key_settings_block")))
#endif

#ifdef __SDCC_mcs51
    #define AT__LAYOUT_ADDR AT(LAYOUT_ADDR) ROM
#else
    #define AT__LAYOUT_ADDR __attribute__ ((section (".key_layout_block")))
#endif

#define SETTINGS_PAGE_COUNT     (INT_DIV_ROUND_UP(SETTINGS_SIZE, PAGE_SIZE))
#define LAYOUT_PAGE_COUNT       (INT_DIV_ROUND_UP(LAYOUT_SIZE, PAGE_SIZE))

#define LAYOUT_PAGE_NUM     (LAYOUT_ADDR / PAGE_SIZE)
#define SETTINGS_PAGE_NUM   (SETTINGS_ADDR / PAGE_SIZE)

/// Converts PAGE_SIZE to LOG2(x) of the page size at compile time.
#define PAGE_SIZE_TO_LOG2(x) (\
    x ==      1 ? 0  : \
    x ==      2 ? 1  : \
    x ==      4 ? 2  : \
    x ==      8 ? 3  : \
    x ==     16 ? 4  : \
    x ==     32 ? 5  : \
    x ==     64 ? 6  : \
    x ==    128 ? 7  : \
    x ==    256 ? 8  : \
    x ==    512 ? 9  : \
    x ==   1024 ? 10  : \
    x ==   2048 ? 11 : \
    x ==   4096 ? 12 : \
    x ==   8192 ? 13 : \
    x ==  16384 ? 14 : \
    x ==  32768 ? 15 : \
    "SETTINGS_ERROR_PAGE_SIZE_UNSUPPORTED"[0] / 0 \
)

// Emulate flash storage using an array
#if USE_VIRTUAL_MODE
    #define VIRTUAL_STORAGE_SIZE (SETTINGS_SIZE + LAYOUT_SIZE)
    extern uint8_t g_virtual_storage[SETTINGS_SIZE + LAYOUT_SIZE];

    uint8_t *virtual_storage_get_address(flash_addr_t addr);
#endif


// Functions for modifying flash, needed to be implement
void flash_modify_enable(void);
void flash_modify_disable(void);
void flash_erase_page(flash_addr_t page_num);
void flash_write(uint8_t* src, flash_addr_t addr, flash_size_t len) REENT;

// Functions for reading flash, need to be implemented
void flash_read(uint8_t* dest, flash_addr_t addr, flash_size_t len);
uint8_t flash_read_byte(flash_addr_t);
uint16_t flash_read_word(flash_addr_t);

void flash_load_from_rom(XRAM uint8_t* dest, const ROM uint8_t* src, flash_addr_t len);
bit_t is_valid_storage_pos(flash_addr_t ptr);

#endif
