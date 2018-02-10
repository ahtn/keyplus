/// Copyright 2018 jem@seethis.link
/// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "io_map.h"

#include <string.h>

#include "core/debug.h"
#include "core/error.h"
#include "core/flash.h"
#include "core/layout.h"
#include "core/util.h"

const static ROM port_mask_t s_usable_pins[IO_PORT_COUNT] = IO_USABLE_PINS;
port_mask_t s_available_pins[IO_PORT_COUNT];

void io_map_init(void) {
    flash_load_from_rom(s_available_pins, s_usable_pins, sizeof(s_usable_pins));
}

// return non-zero on error
uint8_t io_map_claim_pins(uint8_t port_num, uint8_t pin_mask) {
    const uint8_t free_pins = s_available_pins[port_num];
    if ( (free_pins & pin_mask) != pin_mask ) {
        // Some of the pins in the mask are in use
        register_error(ERROR_PIN_MAPPING_CONFLICT);
        return -1;
    }
    s_available_pins[port_num] &= ~(pin_mask);
    return 0;
}

uint8_t debug_port_masks[IO_PORT_COUNT] = {
    0x3F,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
};

uint8_t debug_row_pins[MAX_NUM_ROWS] = {
    IO_MAP_PIN_NUMBER(PORT_D_NUM, 0),
    IO_MAP_PIN_NUMBER(PORT_D_NUM, 1),
    IO_MAP_PIN_NUMBER(PORT_D_NUM, 2),
    IO_MAP_PIN_NUMBER(PORT_D_NUM, 3),
    // IO_MAP_PIN_NUMBER(PORT_D_NUM, 4),
    // IO_MAP_PIN_NUMBER(PORT_D_NUM, 5),
};

port_mask_t io_map_get_col_port_mask(uint8_t port_num) {
#if 0
    return flash_read_byte(
        LAYOUT_PORT_COL_MASKS_ADDR + port_num
    );
#else
    return debug_port_masks[port_num];
#endif
}

port_mask_t io_map_get_row_pin(uint8_t row) {
#if 0
    return flash_read_byte(
        LAYOUT_PORT_ROW_PINS_ADDR + row
    );
#else
    return debug_row_pins[row];
#endif
}

