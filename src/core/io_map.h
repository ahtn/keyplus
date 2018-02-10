/// Copyright 2018 jem@seethis.link
/// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

// #include <stdint.h>
#include "hardware_user_impl.h"
#include "core/util.h"

#ifndef MCU_BITNESS
#error "MCU_BITNESS is not defined"
#endif

#ifndef IO_PORT_SIZE
#define IO_PORT_SIZE MCU_BITNESS
#endif

#if IO_PORT_SIZE == 8
typedef uint8_t port_mask_t;
#elif IO_PORT_SIZE == 32
typedef uint32_t port_mask_t;
#else
#error "IO_PORT_SIZE is bad"
#endif

#define IO_MAP_PIN_NUMBER(port, pin) (port * MCU_BITNESS + pin)
#define IO_MAP_GET_PIN_PORT(pin_num) (pin_num / MCU_BITNESS)
#define IO_MAP_GET_PIN_BIT(pin_num) (pin_num % MCU_BITNESS)

#define IO_MAP_GET_PORT(port_num) (g_io_port_map[port_num])

extern io_port_t * const g_io_port_map[IO_PORT_COUNT];

void io_map_init(void);
uint8_t io_map_claim_pins(uint8_t port_num, uint8_t mask);
uint8_t io_map_get_col_port_mask(uint8_t port_num);
uint8_t io_map_get_row_pin(uint8_t row);
