// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

// NOTE: must implement static_delay_us(t) and static_delay_ms(t)
// Also, make sure that F_CPU and CLOCK_SPEED_SLOW are set
#include "hardware_user_impl.h"

extern bit_t g_slow_clock_mode;

#include <stdint.h>

#ifndef F_CPU
#error "F_CPU needs to be defined"
#endif

#define CLOCK_SPEED_FAST F_CPU

#ifndef CLOCK_SPEED_SLOW
#define CLOCK_SPEED_SLOW F_CPU
#endif

#define CLOCK_SLOW_DIV ((float)CLOCK_SPEED_FAST/(float)CLOCK_SPEED_SLOW)

// Note: the static_delay functions must take compile time constants as arguments
#define static_delay_slow_us(t) (static_delay_us( (int)((float)t/CLOCK_SLOW_DIV) ))
#define static_delay_slow_ms(t) (static_delay_ms( (int)((float)t/CLOCK_SLOW_DIV) ))

#define static_delay_variable_clock_us(t) { \
    if (g_slow_clock_mode) { \
        static_delay_slow_us(t); \
    } else { \
        static_delay_us(t); \
    } \
}


void dynamic_delay_ms(uint16_t ms);

void hardware_init(void);
void bootloader_jmp(void);
void bootloader_jmp_2(void);
void reset_mcu(void);
void idle_sleep(void);

void wdt_init(void);
void wdt_disable(void);
void wdt_kick(void);
