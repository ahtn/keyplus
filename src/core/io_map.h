/// Copyright 2018 jem@seethis.link
/// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

// #include <stdint.h>
#include "hardware_user_impl.h"

#ifndef MCU_BITNESS
#error "MCU_BITNESS is not defined"
#endif

#define IO_PORT_SIZE MCU_BITNESS

#if IO_PORT_SIZE == 8
typedef uint8_t port_mask_t;
#elif IO_PORT_SIZE == 32
typedef uint32_t port_mask_t;
#else
#error "IO_PORT_SIZE is bad"
#endif

#define IO_MAP_PIN_NUMBER(port, pin) (port * MCU_BITNESS + pin)
#define IO_MAP_GET_PORT(pin_num) (pin_num / MCU_BITNESS)
#define IO_MAP_GET_PIN(pin_num) (pin_num % MCU_BITNESS)

void io_map_init(void);
uint8_t io_map_is_legal_pin(uint8_t port_num, uint8_t pin_num);
uint8_t io_map_is_pin_free(uint8_t port_num, uint8_t pin_num);
void io_map_claim_pin(uint8_t port_num, uint8_t pin_num);
void io_map_claim_mask(uint8_t port_num, uint8_t mask);
port_mask_t io_map_get_free_pins_mask(uint8_t port_num);
