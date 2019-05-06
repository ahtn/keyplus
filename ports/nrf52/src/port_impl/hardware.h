// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "nrf_delay.h"
#include "nrfx.h"

#define static_delay_us(x) nrf_delay_us(x)
#define static_delay_ms(x) nrf_delay_ms(x)

#if USE_BLUETOOTH
// When using a SOFT DEVICE use these to disable all non-vital interrupts
#define enable_interrupts() do { \
    sd_nvic_critical_region_enter(); \
} while(0);

#define disable_interrupts() do { \
    sd_nvic_critical_region_exit() \
} while(0);

#else
// These functions are unsafe when using a SOFT DEVICE
#define enable_interrupts() do { \
    __enable_irq(); \
} while(0);

#define disable_interrupts() do { \
    __disable_irq(); \
} while(0);
#endif


#define PAGE_SIZE           4096

// define flash pointer sizes
typedef uint32_t flash_ptr_t;
typedef uint32_t flash_addr_t;
typedef uint32_t flash_size_t;

#define MCU_BITNESS 32
#define IO_PORT_SIZE 32
typedef NRF_GPIO_Type io_port_t;

#if NRF52810_XXAA
    #include "io_map/nrf52810.h"
#elif NRF52811_XXAA
    #include "io_map/nrf52811.h"
#elif NRF52832_XXAA
    #include "io_map/nrf52832.h"
#elif NRF52840_XXAA
    #include "io_map/nrf52840.h"
#else
    #error "NRF chip type not defined"
#endif
