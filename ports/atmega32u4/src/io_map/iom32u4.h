// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define PORT_B_NUM 0
#define PORT_C_NUM 1
#define PORT_D_NUM 2
#define PORT_E_NUM 3
#define PORT_F_NUM 4

// #define PORTB _SFR_IO8(0x05)
// #define PORTC _SFR_IO8(0x08)
// #define PORTD _SFR_IO8(0x0B)
// #define PORTE _SFR_IO8(0x0E)
// #define PORTF _SFR_IO8(0x11)
#define PORT_TO_NUM(port_num) (\
    (PINB <= &port && &port <= PORTB) ? (PORT_B_NUM) : \
    (PINC <= &port && &port <= PORTC) ? (PORT_C_NUM) : \
    (PIND <= &port && &port <= PORTD) ? (PORT_D_NUM) : \
    (PINE <= &port && &port <= PORTE) ? (PORT_E_NUM) : \
    (PINF <= &port && &port <= PORTF) ? (PORT_F_NUM) : 255 \
)

#define IO_PORT_COUNT 5
#define IO_PORT_MAX_PIN_NUM ( IO_MAP_PIN_NUMBER(PORT_F_NUM, 7) )

#define PORT_B_USABLE_PINS 0xff
#define PORT_C_USABLE_PINS 0xC0
#define PORT_D_USABLE_PINS 0xff
#define PORT_E_USABLE_PINS 0x44
#define PORT_F_USABLE_PINS 0xf3

// (8 + 2 + 8 + 2 + 6)
#define IO_MAP_GPIO_COUNT (26)

#ifndef IO_USABLE_PINS
#define IO_USABLE_PINS { \
    PORT_B_USABLE_PINS, \
    PORT_C_USABLE_PINS, \
    PORT_D_USABLE_PINS, \
    PORT_E_USABLE_PINS, \
    PORT_F_USABLE_PINS, \
}
#endif
