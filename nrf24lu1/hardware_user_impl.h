// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "nrf24lu1.h"

#define MCU_BITNESS 8
#define IO_PORT_SIZE 8
typedef uint8_t io_port_t;
#define IO_PORT_COUNT 1

// NOTE: not the best solution, but it's good enough
void dynamic_delay_us(uint16_t us);
#define static_delay_us(x) dynamic_delay_us(x)
#define static_delay_ms(x) dynamic_delay_ms(x)

#define enable_interrupts() do { \
    EA = 1; \
} while(0);

#define disable_interrupts() do { \
    EA = 0; \
} while(0);

#if   defined(FLASH_16)
#define FLASH_SIZE              0x4000
#elif defined(FLASH_32)
#define FLASH_SIZE              0x8000
#else
#error "need to define flash size (use FLASH_16 or FLASH_32)"
#endif


#define PAGE_SIZE           0x0200

#ifndef BOOTLOADER_ADDR
#define BOOTLOADER_SIZE     (1*PAGE_SIZE)
#define BOOTLOADER_ADDR     (FLASH_SIZE - BOOTLOADER_SIZE)
#define BOOTLOADER_PAGE_COUNT   (BOOTLOADER_SIZE / PAGE_SIZE)
#define BOOTLOAEDR_PAGE_NUM (BOOTLOADER_ADDR / PAGE_SIZE)
#endif

#define LOGITECH_BOOTLOADER_ADDR    0x7400

#ifndef NONCE_ADDR
#define NONCE_ADDR (BOOTLOADER_ADDR - 1*PAGE_SIZE)
#endif

// flash pointer defines
typedef uint16_t flash_ptr_t;
typedef uint16_t flash_size_t;

