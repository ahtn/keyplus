// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <string.h>

#include "xmega/usb_xmega.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/media_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"

bit_t is_in_endpoint_ready(uint8_t endpoint_num) {
    return usb_xmega_endpoints[endpoint_num].in.STATUS & USB_EP_UNF_bm;
}

bit_t is_out_endpoint_ready(uint8_t endpoint_num) {
    return usb_xmega_endpoints[endpoint_num].out.STATUS & USB_EP_BUSNACK0_bm;
}

void usb_write_in_endpoint(
    uint8_t endpoint_num,
    const uint8_t *data,
    uint8_t size
) {
    LACR16(&(usb_xmega_endpoints[endpoint_num].in.STATUS), USB_EP_UNF_bm);

    memcpy(
        (uint8_t*)usb_xmega_endpoints[endpoint_num].in.DATAPTR,
        data,
        size
    );

    usb_xmega_endpoints[endpoint_num].in.CNT = size;

    LACR16(&(usb_xmega_endpoints[endpoint_num].in.STATUS), USB_EP_BUSNACK0_bm);
}

void usb_read_out_endpoint(
    uint8_t endpoint_num,
    uint8_t *dest,
    uint8_t *length
) {
    uint8_t i;

    *length = usb_xmega_endpoints[endpoint_num].out.CNT;

    for (i = 0; i < *length; ++i) {
        dest[i] = ((uint8_t*)usb_xmega_endpoints[endpoint_num].out.DATAPTR)[i];
    }

    LACR16(&(usb_xmega_endpoints[endpoint_num].out.STATUS), USB_EP_BUSNACK0_bm);
}
