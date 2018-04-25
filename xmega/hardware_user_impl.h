// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "board_config.h"
#include "xmega_hardware.h"

#define static_delay_us(x) _delay_us(x)
#define static_delay_ms(x) _delay_ms(x)

#define enable_interrupts() do { \
    sei(); \
} while(0);

#define disable_interrupts() do { \
    cli(); \
} while(0);


#define PAGE_SIZE           APP_SECTION_PAGE_SIZE

// define flash pointer sizes
#if MCU_FLASH_SIZE <= 64
typedef uint16_t flash_ptr_t;
typedef uint16_t flash_addr_t;
typedef uint32_t flash_size_t;
#else
typedef uint16_t flash_ptr_t;
typedef uint32_t flash_addr_t;
typedef uint32_t flash_size_t;
#define XMEGA_FAR_FLASH
#endif

#define MCU_BITNESS 8

typedef PORT_t io_port_t;

#if XMEGA_PIN_COUNT == 44
#include "io_map/xio44.h"
#elif XMEGA_PIN_COUNT == 64
#include "io_map/xio64.h"
#elif XMEGA_PIN_COUNT == 100
#include "io_map/xio100.h"
#else
#error "Message unsupported XMEGA_PIN_COUNT"
#endif
