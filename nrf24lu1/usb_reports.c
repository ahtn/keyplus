// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <string.h>

#include "nrf24lu1_usb.h"
#include "nrf24lu1_usb_regs.h"

#include "core/util.h"

#include "usb_reports/usb_reports.h"

bit_t is_in_endpoint_ready(uint8_t endpoint_num) {
    return (USB_EP_IN_CS(endpoint_num) & CS_BSY) == 0;
}

void usb_write_in_endpoint(
    uint8_t endpoint_num,
    const XRAM uint8_t *data,
    uint8_t length
) {
    memcpy(
        USB_EP_IN_BUF(endpoint_num),
        data,
        length
    );
    USB_EP_IN_BC(endpoint_num) = length;
}

extern XRAM uint8_t g_has_received_usb_data;

bit_t is_out_endpoint_ready(uint8_t endpoint_num) {
    return bitn(g_has_received_usb_data, endpoint_num);
}

void usb_read_out_endpoint(
    uint8_t endpoint_num,
    XRAM uint8_t *dest,
    uint8_t *length
) {
    *length = USB_EP_OUT_BC(endpoint_num);
    memcpy(
        dest,
        USB_EP_OUT_BUF(endpoint_num),
        *length
    );
    USB_EP_OUT_BC(endpoint_num) = 0xff;
    g_has_received_usb_data &= ~(1 << endpoint_num);
}
