// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/io_map.h"

#if XMEGA_PIN_COUNT == 44

io_port_t * const g_io_port_map[IO_PORT_COUNT] = {
    &PORTA,
    &PORTB,
    &PORTC,
    &PORTD,
    &PORTE,
    &PORTR,
};

#elif XMEGA_PIN_COUNT == 64

io_port_t * const g_io_port_map[IO_PORT_COUNT] = {
    &PORTA,
    &PORTB,
    &PORTC,
    &PORTD,
    &PORTE,
    &PORTF,
    &PORTR,
};

#elif XMEGA_PIN_COUNT == 100

io_port_t * const g_io_port_map[IO_PORT_COUNT] = {
    &PORTA,
    &PORTB,
    &PORTC,
    &PORTD,
    &PORTE,
    &PORTF,
    &PORTH,
    &PORTJ,
    &PORTK,
    &PORTQ,
    &PORTR,
};

#endif
