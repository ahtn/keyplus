// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <avr/io.h>

typedef volatile uint8_t register8_t;
typedef volatile uint16_t register16_t;
typedef volatile uint32_t register32_t;

typedef struct PORT_struct {
    register8_t IN;
    register8_t DDR;
    register8_t OUT;
} PORT_t;

/// This macro allows us to the AVR ports as if they were a C structure
#define PORT(port_letter) (*(PORT_t*)&(PIN ## port_letter))
