// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/led.h"

#include "nrf_gpio.h"

#include "core/io_map.h"

#define LED1   (NRF_GPIO_PIN_MAP(0, 13))
#define LED2   (NRF_GPIO_PIN_MAP(0, 14))
#define LED3   (NRF_GPIO_PIN_MAP(0, 15))
#define LED4   (NRF_GPIO_PIN_MAP(0, 16))

void led_init(void) {
    nrf_gpio_cfg_output(LED1);
    nrf_gpio_cfg_output(LED2);
    nrf_gpio_cfg_output(LED3);
    nrf_gpio_cfg_output(LED4);

    IO_MAP_CLAIM_PIN_NUMBER(LED1);
    IO_MAP_CLAIM_PIN_NUMBER(LED2);
    IO_MAP_CLAIM_PIN_NUMBER(LED3);
    IO_MAP_CLAIM_PIN_NUMBER(LED4);

    for (int i = 0; i < 4; ++i) {
        led_testing_set(i, 0);
    }
}

void led_testing_set(uint8_t led_num, uint8_t state) {
    state = !state; // LEDs are active LOW, so invert

    switch (led_num) {
        case 0: { nrf_gpio_pin_write(LED1, state); } break;
        case 1: { nrf_gpio_pin_write(LED2, state); } break;
        case 2: { nrf_gpio_pin_write(LED3, state); } break;
        case 3: { nrf_gpio_pin_write(LED4, state); } break;
    }
}

void led_testing_toggle(uint8_t led_num) {
    switch (led_num) {
        case 0: { nrf_gpio_pin_toggle(LED1); } break;
        case 1: { nrf_gpio_pin_toggle(LED2); } break;
        case 2: { nrf_gpio_pin_toggle(LED3); } break;
        case 3: { nrf_gpio_pin_toggle(LED4); } break;
    }
}
