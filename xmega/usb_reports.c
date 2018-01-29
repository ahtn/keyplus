// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <string.h>

#include "xmega/usb_xmega.h"

#include "core/keyboard_report.h"
#include "core/media_report.h"
#include "core/mouse_report.h"
#include "core/vendor_report.h"

/* TODO: move to header file */
extern uint8_t ep1_buf_in[EP1_IN_SIZE];
extern uint8_t ep2_buf_in[EP2_IN_SIZE];
extern uint8_t ep3_buf_in[EP3_IN_SIZE];
extern uint8_t ep4_buf_in[EP4_IN_SIZE];
extern uint8_t ep5_buf_in[EP5_IN_SIZE];

extern uint8_t ep4_buf_out[EP4_OUT_SIZE];

#define EP_IN_BUF_BOOT_KEYBOARD ep1_buf_in
#define BC_IN_BOOT_KEYBOARD usb_xmega_endpoints[EP_NUM_BOOT_KEYBOARD].in.CNT

#define EP_IN_BUF_MOUSE ep2_buf_in
#define BC_IN_MOUSE usb_xmega_endpoints[EP_NUM_MOUSE].in.CNT

#define EP_IN_BUF_MEDIA ep3_buf_in
#define BC_IN_MEDIA usb_xmega_endpoints[EP_NUM_MEDIA].in.CNT

#define EP_IN_BUF_VENDOR ep4_buf_in
#define BC_IN_VENDOR usb_xmega_endpoints[EP_NUM_VENDOR].in.CNT

#define EP_OUT_BUF_VENDOR ep4_buf_out
#define BC_OUT_VENDOR usb_xmega_endpoints[EP_NUM_VENDOR].out.CNT

#define EP_IN_BUF_NKRO_KEYBOARD ep5_buf_in
#define BC_IN_NKRO_KEYBOARD usb_xmega_endpoints[EP_NUM_NKRO_KEYBOARD].in.CNT

// boot keyboard report
bit_t is_ready_boot_keyboard_report(void) {
    return usb_xmega_endpoints[EP_NUM_BOOT_KEYBOARD].in.STATUS & USB_EP_UNF_bm;
}

bit_t send_boot_keyboard_report(void) {
    if (is_ready_boot_keyboard_report()) {
        uint8_t report_size = sizeof(hid_report_boot_keyboard_t);

        LACR16(&(usb_xmega_endpoints[EP_NUM_BOOT_KEYBOARD].in.STATUS), USB_EP_UNF_bm);

        // send the current keyboard report
        memcpy(EP_IN_BUF_BOOT_KEYBOARD, &g_boot_keyboard_report, report_size);

        BC_IN_BOOT_KEYBOARD = report_size;
        LACR16(&(usb_xmega_endpoints[EP_NUM_BOOT_KEYBOARD].in.STATUS), USB_EP_BUSNACK0_bm);

        return false;
    } else {
        return true;
    }
}

// nkro keyboard report
bit_t is_ready_nkro_keyboard_report(void) {
    return usb_xmega_endpoints[EP_NUM_NKRO_KEYBOARD].in.STATUS & USB_EP_UNF_bm;
}

bit_t send_nkro_keyboard_report(void) {
    if (is_ready_nkro_keyboard_report()) {
        uint8_t report_size = sizeof(hid_report_nkro_keyboard_t);
        LACR16(&(usb_xmega_endpoints[EP_NUM_NKRO_KEYBOARD].in.STATUS), USB_EP_UNF_bm);

        // send the current keyboard report
        memcpy(EP_IN_BUF_NKRO_KEYBOARD, &g_nkro_keyboard_report, report_size);

        BC_IN_NKRO_KEYBOARD = report_size;
        LACR16(&(usb_xmega_endpoints[EP_NUM_NKRO_KEYBOARD].in.STATUS), USB_EP_BUSNACK0_bm);

        return false;
    } else {
        return true;
    }
}

bit_t is_ready_mouse_report(void) {
    return usb_xmega_endpoints[EP_NUM_MOUSE].in.STATUS & USB_EP_UNF_bm;
}

// mouse report
bit_t send_mouse_report(void) {
    if (is_ready_mouse_report() && g_report_pending_mouse) {
        uint8_t report_size = sizeof(hid_report_mouse_t);
        LACR16(&(usb_xmega_endpoints[EP_NUM_MOUSE].in.STATUS), USB_EP_UNF_bm);

        memcpy(EP_IN_BUF_MOUSE, (uint8_t*)&g_mouse_report, report_size);

        BC_IN_MOUSE = report_size;
        LACR16(&(usb_xmega_endpoints[EP_NUM_MOUSE].in.STATUS), USB_EP_BUSNACK0_bm);

        g_report_pending_mouse = false;

        return false;
    } else {
        return true;
    }
}

bit_t is_ready_media_report(void) {
    return usb_xmega_endpoints[EP_NUM_MEDIA].in.STATUS & USB_EP_UNF_bm;
}
// media report
bit_t send_media_report(void) {
    if (is_ready_media_report() && g_report_pending_media) {
        uint8_t report_size = sizeof(hid_report_media_t);
        LACR16(&(usb_xmega_endpoints[EP_NUM_MEDIA].in.STATUS), USB_EP_UNF_bm);

        memcpy(EP_IN_BUF_MEDIA, (uint8_t*)&g_media_report, report_size);

        BC_IN_MEDIA = report_size;
        LACR16(&(usb_xmega_endpoints[EP_NUM_MEDIA].in.STATUS), USB_EP_BUSNACK0_bm);

        g_report_pending_media = false;

        return false;
    } else {
        return true;
    }
}

bit_t is_ready_vendor_in_report(void) {
    return usb_xmega_endpoints[EP_NUM_VENDOR].in.STATUS & USB_EP_UNF_bm;
}

bit_t send_vendor_report(void) {
#if USB_BUFFERED
    // if (g_vendor_report_in.len == 0 && vendor_in_buf_has_packet()) {
    //     vendor_in_load_packet();
    // }
    if (is_ready_vendor_in_report() && vendor_in_buf_has_packet()) {
        vendor_in_load_packet();
    }
#endif

    if (is_ready_vendor_in_report() && g_vendor_report_in.len > 0) {
        LACR16(&(usb_xmega_endpoints[EP_NUM_VENDOR].in.STATUS), USB_EP_UNF_bm);

        memcpy(EP_IN_BUF_VENDOR, g_vendor_report_in.data, g_vendor_report_in.len);

        // send the data on it's way
        BC_IN_VENDOR = EP_IN_SIZE_VENDOR;
        LACR16(&(usb_xmega_endpoints[EP_NUM_VENDOR].in.STATUS), USB_EP_BUSNACK0_bm);

        g_vendor_report_in.len = 0;
        return false;
    } else {
        return true;
    }
}

bit_t is_ready_vendor_out_report(void) {
    return usb_xmega_endpoints[EP_NUM_VENDOR].out.STATUS & USB_EP_BUSNACK0_bm;
}

uint8_t read_vendor_report(uint8_t *dest) {
    uint8_t i;
    uint8_t length = 0;

    if (!is_ready_vendor_out_report()) {
        return 1;
    }

    length = usb_xmega_endpoints[EP_NUM_VENDOR].out.CNT;
    g_vendor_report_out.len = length;

    for (i = 0; i < length; ++i) {
        dest[i] = EP_OUT_BUF_VENDOR[i];
    }

    LACR16(&(usb_xmega_endpoints[EP_NUM_VENDOR].out.STATUS), USB_EP_BUSNACK0_bm);
    return 0;
}
