// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define MCU_BITNESS 8
#define IO_PORT_SIZE 8
typedef uint8_t io_port_t;

#define enable_interrupts() do { \
    EA = 1; \
} while(0);

#define disable_interrupts() do { \
    EA = 0; \
} while(0);

// flash pointer defines
typedef uint16_t flash_ptr_t;
typedef uint16_t flash_addr_t;
typedef uint16_t flash_size_t;
