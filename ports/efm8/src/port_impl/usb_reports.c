// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "hid_reports/usb_reports.h"

#include "usb_test.h"

bit_t is_in_endpoint_ready(uint8_t endpoint_num) {
    return !USBD_EpIsBusy(endpoint_num);
}

bit_t is_out_endpoint_ready(uint8_t endpoint_num) {
    // // NOTE: only use one out endpoint 3, so just ignore endpoint_num arg
    UNREFERENCED_ARGUMENT(endpoint_num);
    return !USBD_EpIsBusy(EP3OUT);
}

void usb_write_in_endpoint(
    uint8_t endpoint_num,
    const XRAM uint8_t *data,
    uint8_t length
) {
    USBD_Write(endpoint_num, data, length, false);
}

void usb_read_out_endpoint(
    uint8_t endpoint_num,
    XRAM uint8_t *dest,
    uint8_t *length
) {
    UNREFERENCED_ARGUMENT(endpoint_num);
    if (USBD_Read(EP3OUT, dest, 64, false)) {
        *length = 0;
    } else {
        *length = 64;
    }
}
