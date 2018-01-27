// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <string.h>

#include "nrf24lu1_usb.h"
/* #include "usb_regs.h" */
#include "nrf24lu1_usb_regs.h"

#include "core/keyboard_report.h"
#include "core/media_report.h"
#include "core/mouse_report.h"
#include "core/vendor_report.h"


#define CS_IN_BOOT_KEYBOARD in1cs
#define CS_IN_MOUSE         in2cs
#define CS_IN_MEDIA         in3cs
#define CS_IN_VENDOR        in4cs
#define CS_IN_NKRO_KEYBOARD in5cs

#define CS_OUT_VENDOR       out4cs

#define BC_IN_BOOT_KEYBOARD in1bc
#define BC_IN_MOUSE         in2bc
#define BC_IN_MEDIA         in3bc
#define BC_IN_VENDOR        in4bc
#define BC_IN_NKRO_KEYBOARD in5bc

#define BC_OUT_VENDOR       out4bc

#define EP_IN_BUF_BOOT_KEYBOARD in1buf
#define EP_IN_BUF_MOUSE         in2buf
#define EP_IN_BUF_MEDIA         in3buf
#define EP_IN_BUF_VENDOR        in4buf
#define EP_IN_BUF_NKRO_KEYBOARD in5buf

#define EP_OUT_BUF_VENDOR   out4buf

bit_t is_ready_boot_keyboard_report(void) {
    return (CS_IN_BOOT_KEYBOARD & CS_BSY) == 0;
}

bit_t send_boot_keyboard_report(void) {
    if (is_ready_boot_keyboard_report()) {
        uint8_t report_size = sizeof(hid_report_boot_keyboard_t);

        // send the current keyboard report
        memcpy(EP_IN_BUF_BOOT_KEYBOARD, &g_boot_keyboard_report, report_size);

        BC_IN_BOOT_KEYBOARD = report_size;

        return false;
    } else {
        return true;
    }
}

bit_t is_ready_nkro_keyboard_report(void) {
    return (CS_IN_NKRO_KEYBOARD & CS_BSY) == 0;
}

bit_t send_nkro_keyboard_report(void) {
    if (is_ready_nkro_keyboard_report()) {
        uint8_t report_size = sizeof(hid_report_nkro_keyboard_t);
        // send the current keyboard report
        memcpy(EP_IN_BUF_NKRO_KEYBOARD, &g_nkro_keyboard_report, report_size);
        BC_IN_NKRO_KEYBOARD = report_size;

        return false;
    } else {
        return true;
    }
}

bit_t is_ready_mouse_report(void) {
    return (CS_IN_MOUSE & CS_BSY) == 0;
}

bit_t send_mouse_report(void) {
    if (is_ready_mouse_report() && g_report_pending_mouse) {
        memcpy(EP_IN_BUF_MOUSE, (uint8_t*)&g_mouse_report, sizeof(g_mouse_report));

        // send the data on it's way
        BC_IN_MOUSE = sizeof(g_mouse_report);

        g_report_pending_mouse = false;

        return false;
    } else {
        return true;
    }
}

bit_t is_ready_media_report(void) {
    return (CS_IN_MEDIA & CS_BSY) == 0;
}

bit_t send_media_report(void) {
    if (g_report_pending_media && is_ready_media_report()) {
        memcpy(EP_IN_BUF_MEDIA, (uint8_t*)&g_media_report, sizeof(g_media_report));

        // send the data on it's way
        BC_IN_MEDIA = sizeof(g_media_report);

        g_report_pending_media = false;
        return false;
    } else {
        return true;
    }
}

bit_t is_ready_vendor_in_report(void) {
    return (CS_IN_VENDOR & CS_BSY) == 0;
}

bit_t send_vendor_report(void) {
    if (is_ready_vendor_in_report() && g_vendor_report_in.len) {
        if (g_vendor_report_in.len > VENDOR_REPORT_LEN) {
            g_vendor_report_in.len = 0;
            return true;
        }
        memcpy(EP_IN_BUF_VENDOR, g_vendor_report_in.data, g_vendor_report_in.len);

        // NOTE: Since our HID descriptor for this report says the report
        // size is $EP_IN_SIZE_VENDOR bytes, we must send that many bytes.
        // Otherwise the OS's HID driver may drop this packet.
        BC_IN_VENDOR = EP_IN_SIZE_VENDOR;

        g_vendor_report_in.len = 0;
        return false;
    } else {
        return true;
    }
}

extern XRAM uint8_t has_received_usb_data;

bit_t is_ready_vendor_out_report(void) {
    return has_received_usb_data;
}

uint8_t read_vendor_report(uint8_t *buf) {
    if (is_ready_vendor_out_report()) {
        uint8_t length = BC_OUT_VENDOR;

        if (length > VENDOR_REPORT_LEN) {
            BC_OUT_VENDOR = 0xff;
            return 0;
        }

        memcpy(buf, EP_OUT_BUF_VENDOR, length);
        g_vendor_report_out.len = length;

        // rearm the out endpoint by writing any value to its bc register
        BC_OUT_VENDOR = 0xff;
        has_received_usb_data = false;

        return length;
    } else {
        return 0;
    }
}

