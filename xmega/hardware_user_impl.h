// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

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
typedef uint16_t flash_size_t;
#else
typedef uint32_t flash_ptr_t;
typedef uint32_t flash_size_t;
#endif
