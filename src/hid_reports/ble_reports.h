// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>

#include "kp_ble/hid.h"

void kp_ble_hids_input_report_send(
    uint8_t report_index,
    uint8_t report_size,
    uint8_t* data
);

bool kp_ble_hids_output_has_data(uint8_t report_index);

void kp_ble_hids_output_report_read(
    uint8_t report_index,
    uint8_t report_size,
    uint8_t* data
);
