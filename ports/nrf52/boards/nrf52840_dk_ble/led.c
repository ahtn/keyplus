// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/led.h"

#include "nrf_gpio.h"

#include "core/io_map.h"
#include "core/error.h"

#include <assert.h>

#define NUM_DEBUG_LEDS 8

// Debug pins for use with LEDS or a logic analyzer
uint8_t s_debug_pins[NUM_DEBUG_LEDS] = {
    (NRF_GPIO_PIN_MAP(1, 1)),
    (NRF_GPIO_PIN_MAP(1, 2)),
    (NRF_GPIO_PIN_MAP(1, 3)),
    (NRF_GPIO_PIN_MAP(1, 4)),

    (NRF_GPIO_PIN_MAP(1, 5)),
    (NRF_GPIO_PIN_MAP(1, 6)),
    (NRF_GPIO_PIN_MAP(1, 7)),
    (NRF_GPIO_PIN_MAP(1, 8)),
};

void led_init(void) {
    uint32_t i;
    for (i = 0; i < NUM_DEBUG_LEDS; ++i) {
        uint8_t pin = s_debug_pins[i];
        nrf_gpio_cfg_output(pin);
        IO_MAP_CLAIM_PIN_NUMBER(pin);
        if (has_critical_error()) {
            return;
        }
        led_testing_set(i, 0);
    }
}

void led_testing_set(uint8_t led_num, uint8_t state) {
    // state = !state; // LEDs are active LOW, so invert
    assert(led_num < NUM_DEBUG_LEDS);
    nrf_gpio_pin_write(s_debug_pins[led_num], state);
}

void led_testing_toggle(uint8_t led_num) {
    assert(led_num < NUM_DEBUG_LEDS);
    nrf_gpio_pin_toggle(s_debug_pins[led_num]);
}
