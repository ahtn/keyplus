/// Copyright 2018 jem@seethis.link
/// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

// #include <stdint.h>
#include "hardware_user_impl.h"
#include "core/util.h"

#ifndef MCU_BITNESS
#error "MCU_BITNESS is not defined"
#endif

#ifndef IO_PORT_MAX_PIN_NUM
#error "IO_PORT_MAX_PIN_NUM needs to be defined"
#endif

#ifndef IO_PORT_SIZE
#define IO_PORT_SIZE MCU_BITNESS
#endif

#if IO_PORT_SIZE == 8
typedef uint8_t port_mask_t;
#elif IO_PORT_SIZE == 16
typedef uint16_t port_mask_t;
#elif IO_PORT_SIZE == 32
typedef uint32_t port_mask_t;
#else
#error "IO_PORT_SIZE is bad"
#endif

typedef struct io_map_info_t {
    uint8_t usable_pins[16];
    uint8_t reserved[16];
} io_map_info_t;


#define IO_MAP_PIN_NUMBER(port, pin) (port * MCU_BITNESS + pin)
#define IO_MAP_GET_PIN_PORT(pin_num) (pin_num / MCU_BITNESS)
#define IO_MAP_GET_PIN_BIT(pin_num) (pin_num % MCU_BITNESS)

#define IO_MAP_GET_PORT(port_num) (g_io_port_map[port_num])

extern const ROM io_map_info_t g_io_map_info;
extern io_port_t * const g_io_port_map[IO_PORT_COUNT];

void io_map_init(void);
uint8_t io_map_claim_pins(uint8_t port_num, uint8_t mask);

uint8_t io_map_get_row_pin(uint8_t row);
uint8_t io_map_get_col_pin(uint8_t col);

/// Returns the column mask for a port used by the matrix scanner using the
/// `MATRIX_SCANNER_INTERNAL_FAST_ROW_COL` method.
///
/// For example, if the matrix scanning algorithm is using pins P0.0, P0.1 and
/// P0.7 as column pins on `P0`, then `get_column_masks(0) -> 0b10000011`.
uint8_t io_map_get_col_port_mask(uint8_t port_num);

uint8_t get_col_mask(uint8_t port_num);
