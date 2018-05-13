// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define PORT_0_NUM 0
#define PORT_1_NUM 1
#define PORT_2_NUM 2

#define PORT_TO_NUM(port) ( \
    (port == P0) ? (PORT_0_NUM) : \
    (port == P1) ? (PORT_1_NUM) : \
    (port == P2) ? (PORT_2_NUM) : 255 \
)

#define IO_PORT_COUNT 3
#define IO_PORT_MAX_PIN_NUM ( IO_MAP_PIN_NUMBER(PORT_2_NUM, 1) )

#define PORT_0_USABLE_PINS 0xff
#define PORT_1_USABLE_PINS 0x07
#define PORT_2_USABLE_PINS 0x03

#define IO_MAP_GPIO_COUNT (13)

#ifndef IO_USABLE_PINS
#define IO_USABLE_PINS { \
    PORT_0_USABLE_PINS, \
    PORT_1_USABLE_PINS, \
    PORT_2_USABLE_PINS, \
}
#endif
