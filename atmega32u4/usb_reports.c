// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <string.h>

#include "core/util.h"

#include "usb/util/descriptor_defs.h"
#include "usb_32u4.h"

bit_t is_in_endpoint_ready(uint8_t endpoint_num) {
    return usb_is_endpoint_ready(endpoint_num);
}

bit_t is_out_endpoint_ready(uint8_t endpoint_num) {
    return usb_is_endpoint_ready(endpoint_num);
}

void usb_write_in_endpoint(
    uint8_t endpoint_num,
    const uint8_t *data,
    uint8_t size
) {
    usb_write_endpoint(endpoint_num, data, size);
}

void usb_read_out_endpoint(
    uint8_t endpoint_num,
    uint8_t *dest,
    uint8_t length
) {
    usb_read_endpoint(endpoint_num, dest, length);
}
