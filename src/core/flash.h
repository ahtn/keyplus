// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "config.h"

#include "core/util.h"

#ifndef NO_FLASH_MODULE

// TODO: move this to a project specific location

/* TODO: change this */
#if   defined(FLASH_16)
#define FLASH_SIZE              0x4000
#elif defined(FLASH_32)
#define FLASH_SIZE              0x8000
#else
#error "need to define flash size (use FLASH_16 or FLASH_32)"
#endif


typedef uint16_t flash_ptr_t;
typedef uint16_t flash_size_t;

// TODO: this is nrf24lu1+ specific ATM, adapt to other architectures

#define PAGE_SIZE           0x0200

#define BOOTLOADER_SIZE     (1*PAGE_SIZE)
#define SETTINGS_SIZE       (1*PAGE_SIZE)
// #define LAYOUT_SIZE         (2*PAGE_SIZE)
#define LAYOUT_SIZE         (5*PAGE_SIZE)

#define SETTINGS_PAGE_COUNT     (SETTINGS_SIZE / PAGE_SIZE)
#define LAYOUT_PAGE_COUNT       (LAYOUT_SIZE / PAGE_SIZE)
#define BOOTLOADER_PAGE_COUNT   (BOOTLOADER_SIZE / PAGE_SIZE)

#define BOOTLOADER_ADDR     (FLASH_SIZE - BOOTLOADER_SIZE)
#define SETTINGS_ADDR       (BOOTLOADER_ADDR - SETTINGS_SIZE)
// #define LAYOUT_ADDR         (SETTINGS_ADDR - LAYOUT_SIZE)
// #define LAYOUT_ADDR         ((flash_ptr_t)&g_layout_storage[0])
#define LAYOUT_ADDR         ((flash_ptr_t)0x6000)

#define LAYOUT_PAGE_NUM     (LAYOUT_ADDR / PAGE_SIZE)
#define SETTINGS_PAGE_NUM   (SETTINGS_ADDR / PAGE_SIZE)
#define BOOTLOAEDR_PAGE_NUM (BOOTLOADER_ADDR / PAGE_SIZE)

#define LOGITECH_BOOTLOADER_ADDR    0x7400


// TODO: link scripts for xmega
// NOTE: We want to fix the locations of these structures because we will be
// reprogramming when we update the layout. We want to reserve space for them,
// and have them page aligned.
#ifdef SDCC
// #define AT__SETTINGS_ADDR AT(SETTINGS_ADDR)
#define AT__SETTINGS_ADDR
#else
// #define AT__SETTINGS_ADDR __attribute__ ((section (".settings_storage")))
#define AT__SETTINGS_ADDR
#endif

#ifdef SDCC
#define AT__LAYOUT_ADDR AT(LAYOUT_ADDR)
// #define AT__LAYOUT_ADDR
#else
// #define AT__LAYOUT_ADDR __attribute__ ((section (".layout_storage")))
#define AT__LAYOUT_ADDR
#endif

void flash_modify_enable(void);
void flash_modify_disable(void);
void flash_erase_page(uint8_t page_num);

void flash_load_rom(XRAM uint8_t* dest, const ROM uint8_t* src, flash_size_t len);

void flash_write(uint8_t* data, flash_ptr_t addr, flash_size_t len);
void flash_read(uint8_t* dest, flash_ptr_t addr, flash_size_t len);
uint8_t flash_read_byte(flash_ptr_t);
uint16_t flash_read_word(flash_ptr_t);

bit_t is_valid_storage_pos(flash_ptr_t ptr);

#endif
