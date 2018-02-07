/// Copyright 2018 jem@seethis.link
/// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "io_map.h"

// #include <string.h>

#include "core/debug.h"
#include "core/flash.h"

#include "core/util.h"

const static ROM port_mask_t s_usable_pins[IO_MAP_PORT_COUNT] = IO_MAP_USABLE_PINS;
static port_mask_t s_available_pins[IO_MAP_PORT_COUNT];

void io_map_init(void) {
    flash_load_from_rom(s_available_pins, s_usable_pins, sizeof(s_usable_pins));
}

uint8_t io_map_is_legal_pin(uint8_t port_num, uint8_t pin_num) {
    if (port_num >= IO_MAP_PORT_COUNT) {
        return false;
    }

    return is_bitn_set(s_usable_pins[port_num], pin_num);
}

uint8_t io_map_is_pin_free(uint8_t port_num, uint8_t pin_num) {
    return is_bitn_set(s_available_pins[port_num], pin_num);
}

void io_map_claim_pin(uint8_t port_num, uint8_t pin_num) {
    s_available_pins[port_num] &= ~(1 << pin_num);
}

void io_map_claim_mask(uint8_t port_num, uint8_t mask) {
    s_available_pins[port_num] &= ~(mask);
}

port_mask_t io_map_get_free_pins_mask(uint8_t port_num) {
    assert(port_num < IO_MAP_PORT_COUNT);
    return s_available_pins[port_num];
}
