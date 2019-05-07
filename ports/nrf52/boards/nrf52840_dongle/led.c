// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/led.h"

#include "nrf_gpio.h"

#include "core/io_map.h"

#define LED1   (NRF_GPIO_PIN_MAP(0, 6))

#define LED2_R (NRF_GPIO_PIN_MAP(0, 8))
#define LED2_G (NRF_GPIO_PIN_MAP(1, 9))
#define LED2_B (NRF_GPIO_PIN_MAP(0, 12))

void led_init(void) {
    nrf_gpio_cfg_output(LED1);
    nrf_gpio_cfg_output(LED2_R);
    nrf_gpio_cfg_output(LED2_G);
    nrf_gpio_cfg_output(LED2_B);

    IO_MAP_CLAIM_PIN_NUMBER(LED1);
    IO_MAP_CLAIM_PIN_NUMBER(LED2_R);
    IO_MAP_CLAIM_PIN_NUMBER(LED2_G);
    IO_MAP_CLAIM_PIN_NUMBER(LED2_B);

    for (int i = 0; i < 4; ++i) {
        led_testing_set(i, 0);
    }
}

void led_testing_set(uint8_t led_num, uint8_t state) {
    state = !state; // LEDs are active LOW, so invert

    switch (led_num) {
        case 0: { nrf_gpio_pin_write(LED1, state); } break;

        case 1: { nrf_gpio_pin_write(LED2_R, state); } break;
        case 2: { nrf_gpio_pin_write(LED2_G, state); } break;
        case 3: { nrf_gpio_pin_write(LED2_B, state); } break;
    }
}

void led_testing_toggle(uint8_t led_num) {
    switch (led_num) {
        case 0: { nrf_gpio_pin_toggle(LED1); } break;

        case 1: { nrf_gpio_pin_toggle(LED2_R); } break;
        case 2: { nrf_gpio_pin_toggle(LED2_G); } break;
        case 3: { nrf_gpio_pin_toggle(LED2_B); } break;
    }
}
