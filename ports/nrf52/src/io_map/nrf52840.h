// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define PORT_0_NUM 0
#define PORT_1_NUM 1

#define PORT_TO_NUM(port) ( \
    (port == NRF_P0) ? (PORT_0_NUM) : \
    (port == NRF_P1) ? (PORT_1_NUM) : 255 \
)

#define IO_PORT_COUNT GPIO_COUNT
#define IO_PORT_MAX_PIN_NUM ( IO_MAP_PIN_NUMBER(PORT_1_NUM, 15) )

#define PORT_0_USABLE_PINS 0xffffffff
#define PORT_1_USABLE_PINS 0x0000ffff

#define IO_MAP_GPIO_COUNT (32 + 16)

#ifndef IO_USABLE_PINS
#define IO_USABLE_PINS { \
    PORT_0_USABLE_PINS, \
    PORT_1_USABLE_PINS, \
}
#endif
