// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "vendor_report.h"

#include <avr/io.h>

vendor_report_t g_vendor_report_in;
vendor_report_t g_vendor_report_out;

bool is_ready_vendor_in_report(void) {
    return usb_xmega_endpoints[EP_NUM_VENDOR].in.STATUS & USB_EP_UNF_bm;
}

bool send_vendor_report(void) {
    if (is_ready_vendor_in_report() && g_vendor_report_in.len > 0) {
        LACR16(&(usb_xmega_endpoints[EP_NUM_VENDOR].in.STATUS), USB_EP_UNF_bm);

        memcpy(EP_IN_BUF_VENDOR, g_vendor_report_in.data, g_vendor_report_in.len);

        // send the data on it's way
        // NOTE: For this to be a valid HID report, the number of bytes that
        // we send must match that given in the HID descriptor.
        BC_IN_VENDOR = EP_SIZE_VENDOR;

        LACR16(&(usb_xmega_endpoints[EP_NUM_VENDOR].in.STATUS), USB_EP_BUSNACK0_bm);

        g_vendor_report_in.len = 0;
        return false;
    } else {
        return true;
    }
}

bool is_ready_vendor_out_report(void) {
    return usb_xmega_endpoints[EP_NUM_VENDOR].out.STATUS & USB_EP_BUSNACK0_bm;
}

uint8_t read_vendor_report(uint8_t *dest) {
    uint8_t length = 0;
    if (!is_ready_vendor_out_report()) {
        return length;
    }

    length = usb_xmega_endpoints[EP_NUM_VENDOR].out.CNT;
    memcpy(dest, EP_OUT_BUF_VENDOR, length);

    LACR16(&(usb_xmega_endpoints[EP_NUM_VENDOR].out.STATUS), USB_EP_BUSNACK0_bm);
    return length;
}

