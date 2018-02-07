// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "config.h"

#include "core/util.h"

#include "hardware_user_impl.h"

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
#ifdef SDCC
#define AT__SETTINGS_ADDR AT(SETTINGS_ADDR) ROM
#else
#define AT__SETTINGS_ADDR __attribute__ ((section (".key_settings_block")))
#endif

#ifdef SDCC
#define AT__LAYOUT_ADDR AT(LAYOUT_ADDR) ROM
#else
#define AT__LAYOUT_ADDR __attribute__ ((section (".key_layout_block")))
#endif

#define SETTINGS_PAGE_COUNT     (SETTINGS_SIZE / PAGE_SIZE)
#define LAYOUT_PAGE_COUNT       (LAYOUT_SIZE / PAGE_SIZE)

#define LAYOUT_PAGE_NUM     (LAYOUT_ADDR / PAGE_SIZE)
#define SETTINGS_PAGE_NUM   (SETTINGS_ADDR / PAGE_SIZE)

void flash_modify_enable(void);
void flash_modify_disable(void);
void flash_erase_page(uint8_t page_num);

void flash_load_from_rom(XRAM uint8_t* dest, const ROM uint8_t* src, flash_size_t len);

void flash_write(uint8_t* data, flash_ptr_t addr, flash_size_t len);
void flash_read(uint8_t* dest, flash_ptr_t addr, flash_size_t len);
uint8_t flash_read_byte(flash_ptr_t);
uint16_t flash_read_word(flash_ptr_t);

bit_t is_valid_storage_pos(flash_ptr_t ptr);

#endif
