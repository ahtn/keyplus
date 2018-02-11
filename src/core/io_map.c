/// Copyright 2018 jem@seethis.link
/// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "io_map.h"

#include <string.h>

#include "core/debug.h"
#include "core/error.h"
#include "core/flash.h"
#include "core/layout.h"
#include "core/util.h"


const ROM io_map_info_t g_io_map_info = {
    .usable_pins = IO_USABLE_PINS,
};

port_mask_t s_available_pins[IO_PORT_COUNT];

void io_map_init(void) {
    flash_load_from_rom(
        s_available_pins,
        g_io_map_info.usable_pins,
        sizeof(port_mask_t)*IO_PORT_COUNT
    );
}

// return non-zero on error
uint8_t io_map_claim_pins(uint8_t port_num, uint8_t pin_mask) {
    const uint8_t free_pins = s_available_pins[port_num];
    if ( (free_pins & pin_mask) != pin_mask || port_num >= IO_PORT_COUNT) {
        // Some of the pins in the mask are in use
        register_error(ERROR_PIN_MAPPING_CONFLICT);
        return -1;
    }
    s_available_pins[port_num] &= ~(pin_mask);
    return 0;
}

port_mask_t io_map_get_col_port_mask(uint8_t port_num) {
    return flash_read_byte(
        LAYOUT_PORT_COL_MASKS_ADDR + port_num
    );
}

port_mask_t io_map_get_row_pin(uint8_t row) {
    return flash_read_byte(
        LAYOUT_PORT_ROW_PINS_ADDR + row
    );
}

