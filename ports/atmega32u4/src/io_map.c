// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/hardware.h"

#if defined(__AVR_ATmega32U4__) \
    || defined(__AVR_ATmega16U4) \
    || defined(__AVR_ATmega32U2) \
    || defined(__AVR_ATmega16U2)

io_port_t * const g_io_port_map[IO_PORT_COUNT] = {
    &PORT(B),
    &PORT(C),
    &PORT(D),
    &PORT(E),
    &PORT(F),
};


#elif defined(__AVR_AT90USB646) \
    || defined(__AVR_AT90USB647) \
    || defined(__AVR_AT90USB1286) \
    || defined(__AVR_AT90USB1287) \
    || defined(__AVR_ATmega32U6)
#endif
