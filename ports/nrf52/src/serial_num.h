// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>

#define SERIAL_NUMBER_STRING_SIZE (12)

typedef struct serial_num_t {
    uint16_t high;
    uint32_t low;
} serial_num_t;

void nrf52_init_serial_number(void);

extern serial_num_t g_nrf52_serial_number;
extern uint16_t g_nrf52_serial_usb_desc[SERIAL_NUMBER_STRING_SIZE+1];
