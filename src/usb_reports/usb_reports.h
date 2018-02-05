/// Copyright 2018 jem@seethis.link
/// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

/// These functions need to be implemented for each microcontroller port.

bit_t is_in_endpoint_ready(uint8_t endpoint_num);

bit_t is_out_endpoint_ready(uint8_t endpoint_num);

void usb_write_in_endpoint(
    uint8_t endpoint_num,
    const uint8_t *data,
    uint8_t length
);

void usb_read_out_endpoint(
    uint8_t endpoint_num,
    const uint8_t *data,
    uint8_t *length
);
