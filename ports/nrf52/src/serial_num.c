// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "serial_num.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "nrf_drv_usbd.h"
#include "nrf_log.h"

#include "usb/descriptors.h"

serial_num_t g_nrf52_serial_number;

uint16_t g_nrf52_serial_usb_desc[SERIAL_NUMBER_STRING_SIZE+1];

void nrf52_init_serial_number(void) {
    char serial_number_string[SERIAL_NUMBER_STRING_SIZE + 1];

    // The masking makes the address match the Random Static BLE address.
    g_nrf52_serial_number.high = (uint16_t)NRF_FICR->DEVICEADDR[1] | 0xC000,
    g_nrf52_serial_number.low = NRF_FICR->DEVICEADDR[0],

    (void)snprintf(serial_number_string,
                   SERIAL_NUMBER_STRING_SIZE + 1,
                   "%04hX%08lX",
                   g_nrf52_serial_number.high,
                   g_nrf52_serial_number.low);

    // USB string descriptors are encoded as utf-16le, with no null terminator
    g_nrf52_serial_usb_desc[0] = USB_STRING_DESC_SIZE((SERIAL_NUMBER_STRING_SIZE+1)*sizeof(uint16_t));

    for (int i = 0; i < SERIAL_NUMBER_STRING_SIZE; ++i) {
        g_nrf52_serial_usb_desc[i+1] = serial_number_string[i];
    }
}
