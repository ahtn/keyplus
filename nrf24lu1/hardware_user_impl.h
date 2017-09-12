// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

// NOTE: not the best solution, but it's good enough
void dynamic_delay_us(uint16_t us);

#define static_delay_us(x) dynamic_delay_us(x)
#define static_delay_ms(x) dynamic_delay_ms(x)

#if   defined(FLASH_16)
#define FLASH_SIZE              0x4000
#elif defined(FLASH_32)
#define FLASH_SIZE              0x8000
#else
#error "need to define flash size (use FLASH_16 or FLASH_32)"
#endif


#define PAGE_SIZE           0x0200

#define BOOTLOADER_SIZE     (1*PAGE_SIZE)
#define BOOTLOADER_ADDR     (FLASH_SIZE - BOOTLOADER_SIZE)
#define BOOTLOADER_PAGE_COUNT   (BOOTLOADER_SIZE / PAGE_SIZE)
#define BOOTLOAEDR_PAGE_NUM (BOOTLOADER_ADDR / PAGE_SIZE)

#define LOGITECH_BOOTLOADER_ADDR    0x7400

#define NONCE_ADDR (BOOTLOADER_ADDR - 1*PAGE_SIZE)
