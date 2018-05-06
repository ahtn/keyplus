// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "descriptors.h"

#include <string.h>
#include <stddef.h>

#include "xmega/usb_xmega.h"

#include "usb_util/usb_hid.h"
#include "usb_util/descriptor_defs.h"
#include "usb_util/requests.h"

#include "vendor_report.h"
#include "util.h"

#define HID_USAGE_PAGE_VENDOR HID_USAGE_PAGE_VENDOR_START
#define HID_COLLECTION_VENDOR HID_COLLECTION_VENDOR_START
#define HID_USAGE_VENDOR_0 0x80+0
#define HID_USAGE_VENDOR_1 0x80+1
#define HID_USAGE_VENDOR_2 0x80+2

#define STRING_DESC_NONE 0
#define STRING_DESC_MANUFACTURER 1
#define STRING_DESC_PRODUCT 2
#define STRING_DESC_SERIAL_NUMBER 3
#define USB_STRING_DESC_COUNT 4

#ifndef USB_VID
#define USB_VID 0x6666
#endif

#ifndef USB_PID
#define USB_PID 0xB007
#endif

#ifndef USB_DEVICE_VERSION
#define USB_DEVICE_VERSION 0x0000
#endif

#define USB_REVISION USB_REVISION_1_1
#define USB_HID_REVISION USB_HID_REVISION_1_11

#define NUM_INTERFACES 1

typedef struct {
    usb_config_desc_t conf;
    usb_interface_desc_t intf1; // raw hid interface
    usb_hid_desc_t hid1;
    usb_endpoint_desc_t ep1in;
    usb_endpoint_desc_t ep1out;
} bootloader_conf_desc_t;

const usb_device_desc_t usb_device_desc = {
    .bLength                = sizeof(usb_device_desc_t),
    .bDescriptorType        = USB_DESC_DEVICE,
    .bcdUSB                 = USB_REVISION,
    .bDeviceClass           = 0,
    .bDeviceSubClass        = 0,
    .bDeviceProtocol        = 0,
    .bMaxPacketSize         = EP0_SIZE,
    .idVendor               = USB_VID,
    .idProduct              = USB_PID,
    .bcdDevice              = USB_DEVICE_VERSION,
    .iManufacturer          = STRING_DESC_MANUFACTURER,
    .iProduct               = STRING_DESC_PRODUCT,
    .iSerialNumber          = STRING_DESC_SERIAL_NUMBER,
    .bNumConfigurations     = 1,
};

const uint8_t hid_desc_vendor[] = {
    HID_USAGE_PAGE(2), DB16(HID_USAGE_PAGE_VENDOR_START),
    HID_USAGE(1), HID_USAGE_VENDOR_0,
    HID_COLLECTION(1), HID_COLLECTION_VENDOR,
        // input 64 byte report
        HID_LOGICAL_MINIMUM(1), DB8(0),
        HID_LOGICAL_MAXIMUM(2), DB16(0x00ff),
        HID_REPORT_SIZE(1), 8,
        HID_REPORT_COUNT(1), 64,
        HID_USAGE(1), HID_USAGE_VENDOR_1,
        HID_INPUT(1), IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
        // output 64 byte report
        HID_LOGICAL_MINIMUM(1), DB8(0),
        HID_LOGICAL_MAXIMUM(2), DB16(0x00ff),
        HID_REPORT_SIZE(1), 8,
        HID_REPORT_COUNT(1), 64,
        HID_USAGE(1), HID_USAGE_VENDOR_2,
        HID_OUTPUT(1), IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
    HID_END_COLLECTION(0),
};


const bootloader_conf_desc_t usb_config_desc = {
    .conf = { // configuration descriptor
        .bLength                = sizeof(usb_config_desc_t),
        .bDescriptorType        = USB_DESC_CONFIGURATION,
        .wTotalLength           = sizeof(bootloader_conf_desc_t),
        .bNumInterfaces         = NUM_INTERFACES,
        .bConfigurationValue    = 1,
        .iConfiguration         = STRING_DESC_NONE,
        .bmAttributes           = USB_CONFIG_BUS_POWERED,
        .bMaxPower              = 250, // 500ma
    },

    .intf1 = { // raw HID interface
        .bLength            = sizeof(usb_interface_desc_t),
        .bDescriptorType    = USB_DESC_INTERFACE,
        .bInterfaceNumber   = INTERFACE_VENDOR,
        .bAlternateSetting  = 0,
        .bNumEndpoints      = 2,
        .bInterfaceClass    = USB_CLASS_HID,
        .bInterfaceSubClass = 0,
        .bInterfaceProtocol = 0, // TODO
        .iInterface         = STRING_DESC_NONE,
    },
    .hid1 = { // HID descriptor
        .bLength                = sizeof(usb_hid_desc_t),
        .bDescriptorType        = USB_DESC_HID,
        .bcdHID                 = USB_HID_REVISION,
        .bCountryCode           = HID_COUNTRY_NONE,
        .bNumDescriptors        = 1,
        .bDescriptorType_HID    = USB_DESC_HID_REPORT,
        .wDescriptorLength      = sizeof(hid_desc_vendor),
    },
    .ep1in = { // in endpoint
        .bLength            = sizeof(usb_endpoint_desc_t),
        .bDescriptorType    = USB_DESC_ENDPOINT,
        .bEndpointAddress   = USB_DIR_IN | EP_NUM_VENDOR,
        .bmAttributes       = USB_EP_TYPE_INT,
        .wMaxPacketSize     = EP_SIZE_VENDOR,
        .bInterval          = REPORT_INTERVAL_VENDOR,
    },
    .ep1out = { // out endpoint
        .bLength            = sizeof(usb_endpoint_desc_t),
        .bDescriptorType    = USB_DESC_ENDPOINT,
        .bEndpointAddress   = USB_DIR_OUT | EP_NUM_VENDOR,
        .bmAttributes       = USB_EP_TYPE_INT,
        .wMaxPacketSize     = EP_SIZE_VENDOR,
        .bInterval          = REPORT_INTERVAL_VENDOR,
    },
};


// language id in string 0 descriptor
const uint16_t usb_string_desc_0[2] = {
    USB_STRING_DESC_SIZE(sizeof(usb_string_desc_0)),
    HID_LANG_ID(HID_LANG_ENGLISH, HID_SUBLANG_ENGLISH_US),
};

// TODO: make these easier to change
const uint16_t usb_string_desc_1[5] = {
    USB_STRING_DESC_SIZE(sizeof(usb_string_desc_1)),
    'X','u','s','b'
};

const uint16_t usb_string_desc_2[10] = {
    USB_STRING_DESC_SIZE(sizeof(usb_string_desc_2)),
    'X','u','s','b','-','b','o','o','t'
};


// USB string used for serial number of the device
// string format (17 byte ascii): "LLLLL-WW-XXXXYYYY"
// LLLLL: 5byte ascii lot number
// WW: wafer number in hexadecimal
// XXXX: 2 byte X wafer coordinate in hexadecimal
// YYYY: 2 byte Y wafer coordinate in hexadecimal
uint16_t usb_string_desc_3[18];

// use these functions to save flash space
static void write_string_3_byte(uint8_t byte) {
    static uint8_t string_3_write_pos = 1;
    usb_string_desc_3[string_3_write_pos++] = byte;
}

static void write_string_3_hex(uint8_t hex_char) {
    write_string_3_byte(hexdigit_to_char(hex_char >> 4));
    write_string_3_byte(hexdigit_to_char(hex_char >> 0));
}

void usb_init_descriptors(void) {
    // Load the unique serial number into the serial number string of the
    // USB device descriptor. Convert the non-ascii components to ascii.
    uint8_t i;

    usb_string_desc_3[0] = USB_STRING_DESC_SIZE(sizeof(usb_string_desc_3));

    { // lot number
        uint16_t addr = offsetof(NVM_PROD_SIGNATURES_t, LOTNUM0);
        for (i = 0; i < 5; ++i) {
            write_string_3_byte(read_production_signature_byte(addr++));
        }
    }
    write_string_3_byte('-');
    { // wafer number
        const uint16_t addr = offsetof(NVM_PROD_SIGNATURES_t, WAFNUM);
        const uint8_t wafer_num = read_production_signature_byte(addr);
        write_string_3_hex(wafer_num);
    }
    write_string_3_byte('-');
    { // xy pos
        uint16_t addr = offsetof(NVM_PROD_SIGNATURES_t, COORDX0);
        for (i = 0; i < 2; ++i) {
            const uint8_t coord0 = read_production_signature_byte(addr++);
            const uint8_t coord1 = read_production_signature_byte(addr++);
            write_string_3_hex(coord1);
            write_string_3_hex(coord0);
        }
    }
}

uint16_t usb_cb_get_descriptor(uint8_t type, uint8_t index, uint8_t interface, const uint8_t** ptr) {
    const void* address = NULL;
    uint16_t size    = 0;

    switch (type) {
        case USB_DTYPE_Device: {
            address = &usb_device_desc;
            size    = sizeof(usb_device_desc);
        } break;

        case USB_DTYPE_Configuration: {
            address = &usb_config_desc;
            size    = sizeof(usb_config_desc);
        } break;

        case USB_DTYPE_HID_REPORT: {
            if (interface == INTERFACE_VENDOR) {
                address = hid_desc_vendor;
                size = sizeof(hid_desc_vendor);
            }
        } break;

        case USB_DTYPE_String: {
            switch (index) {
                case 0x00: address = usb_string_desc_0; break;
                case 0x01: address = usb_string_desc_1; break;
                case 0x02: address = usb_string_desc_2; break;
                case 0x03: address = usb_string_desc_3; break;
            }
            size = ((USB_StringDescriptor*)address)->bLength;
        } break;
    }

    *ptr = address;
    return size;
}

uint8_t ep1_buf_in[EP_SIZE_VENDOR];
uint8_t ep1_buf_out[EP_SIZE_VENDOR];

void usb_cb_reset(void) {
    // in endpoints
    usb_xmega_endpoints[1].in.STATUS = USB_EP_BUSNACK0_bm;
    usb_xmega_endpoints[1].in.CTRL = USB_EP_TYPE_BULK_gc | USB_EP_size_to_gc(EP_SIZE_VENDOR);
    usb_xmega_endpoints[1].in.DATAPTR = (uint16_t)ep1_buf_in;

    // out endpoints
    usb_xmega_endpoints[1].out.STATUS = 0;
    usb_xmega_endpoints[1].out.CTRL = USB_EP_TYPE_BULK_gc | USB_EP_size_to_gc(EP_SIZE_VENDOR);
    usb_xmega_endpoints[1].out.DATAPTR = (uint16_t)ep1_buf_out;
}

bool usb_cb_set_configuration(uint8_t config) {
    if (config <= 1) {
        return true;
    } else {
        return false;
    }
}

void usb_cb_completion(void) {
}

void usb_cb_control_setup(void) {
    if ((usb_setup.bmRequestType & USB_REQTYPE_TYPE_MASK) == 0x20) {
        uint8_t request = usb_setup.bRequest;
        uint8_t interface = usb_setup.wIndex;

        switch (request) {
            case USB_REQ_HID_GET_REPORT: {
                if (interface == INTERFACE_VENDOR) {
                    memcpy(ep0_buf_in, ep1_buf_in, EP_SIZE_VENDOR);
                    usb_ep0_in(EP_SIZE_VENDOR);
                    usb_ep0_out();
                } else {
                    usb_ep0_stall();
                }
            } break;

            default:
            case USB_REQ_HID_SET_REPORT: {
                usb_ep0_stall();
            } break;
        }
    }
}


void usb_cb_control_in_completion(void) {
}

void usb_cb_control_out_completion(void) {
}

bool usb_cb_set_interface(uint16_t interface, uint16_t altsetting) {
    return false;
}
