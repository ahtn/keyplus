// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/io_map.h"

io_port_t * const g_io_port_map[IO_PORT_COUNT] = {
    &PORTA,
    &PORTB,
    &PORTC,
    &PORTD,
    &PORTE,
    &PORTR,
};
