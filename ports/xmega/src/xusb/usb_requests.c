// Copyright (c) 2011-2014 Nonolith Labs
// Copyright (c) 2014 Technical Machine
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#include "usb.h"
#include <string.h>

USB_SetupPacket usb_setup;
__attribute__((__aligned__(4))) uint8_t ep0_buf_in[USB_EP0_SIZE];
__attribute__((__aligned__(4))) uint8_t ep0_buf_out[USB_EP0_SIZE];
volatile uint8_t usb_configuration;

static fat_ptr_t desc_data;

void usb_ep0_in_multi(void) {
    uint16_t tsize = desc_data.size;

    if (tsize > USB_EP0_SIZE) {
        tsize = USB_EP0_SIZE;
    }

    switch (desc_data.type) {
        case PTR_FLASH: {
            NVM.CMD = NVM_CMD_NO_OPERATION_gc;
            memcpy_P(ep0_buf_in, (void*) desc_data.ptr.flash, tsize);
        } break;
        case PTR_DATA: {
            memcpy(ep0_buf_in, desc_data.ptr.data, tsize);
        } break;
    }

    usb_ep0_in(tsize);

    if (tsize == 0) {
        usb_ep0_out();
    }

    desc_data.ptr.raw += tsize;
    desc_data.size -= tsize;
}

void usb_handle_setup(void){
    if ((usb_setup.bmRequestType & USB_REQTYPE_TYPE_MASK) == USB_REQTYPE_STANDARD){
        switch (usb_setup.bRequest){
            case USB_REQ_GetStatus:
                ep0_buf_in[0] = 0;
                ep0_buf_in[1] = 0;
                usb_ep0_in(2);
                return usb_ep0_out();

            case USB_REQ_ClearFeature:
            case USB_REQ_SetFeature:
                usb_ep0_in(0);
                return usb_ep0_out();

            case USB_REQ_SetAddress:
                usb_ep0_in(0);
                return usb_ep0_out();

            case USB_REQ_GetDescriptor: {
                uint8_t index = (usb_setup.wValue & 0xFF);
                uint8_t type = (usb_setup.wValue >> 8);
                fat_ptr_t desc_ptr = {0};
                uint16_t interface = (usb_setup.wIndex);
                usb_cb_get_descriptor(type, index, interface, &desc_ptr);

                if (desc_ptr.size && desc_ptr.ptr.raw) {
                    if (desc_ptr.size > usb_setup.wLength) {
                        desc_ptr.size = usb_setup.wLength;
                    }

                    desc_data = desc_ptr;

                    usb_ep0_in_multi();
                    return;
                } else {
                    return usb_ep0_stall();
                }
            }
            case USB_REQ_GetConfiguration:
                ep0_buf_in[0] = usb_configuration;
                usb_ep0_in(1);
                return usb_ep0_out();

            case USB_REQ_SetConfiguration:
                if (usb_cb_set_configuration((uint8_t)usb_setup.wValue)) {
                    usb_ep0_in(0);
                    usb_configuration = (uint8_t)(usb_setup.wValue);
                    return usb_ep0_out();
                } else {
                    return usb_ep0_stall();
                }

            case USB_REQ_SetInterface:
                if (usb_cb_set_interface(usb_setup.wIndex, usb_setup.wValue)) {
                    usb_ep0_in(0);
                    return usb_ep0_out();
                } else {
                    return usb_ep0_stall();
                }

            default:
                return usb_ep0_stall();
        }
    }

    usb_cb_control_setup();
}

void usb_handle_control_out_complete(void) {
    if ((usb_setup.bmRequestType & USB_REQTYPE_TYPE_MASK) == USB_REQTYPE_STANDARD) {
        // Let the status stage proceed
    } else {
        usb_cb_control_out_completion();
    }
}

void usb_handle_control_in_complete(void) {
    if ((usb_setup.bmRequestType & USB_REQTYPE_TYPE_MASK) == USB_REQTYPE_STANDARD) {
        const uint8_t req = usb_setup.bRequest;
        if (req == USB_REQ_SetAddress) {
            usb_set_address(usb_setup.wValue & 0x7F);
        } else if (req == USB_REQ_GetDescriptor) {
            usb_ep0_in_multi();
        }
    } else {
        usb_cb_control_in_completion();
    }
}
