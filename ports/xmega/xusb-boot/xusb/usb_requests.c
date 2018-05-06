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

uint16_t usb_ep0_in_size;
const uint8_t* usb_ep0_in_ptr;

#ifdef DESCRIPTORS_IN_PROGMEM
#include <avr/pgmspace.h>
static const uint8_t* usb_ep0_from_progmem(const uint8_t* addr, uint16_t size) {
    uint8_t *buf = ep0_buf_in;
    uint16_t remaining = size;
    NVM.CMD = NVM_CMD_NO_OPERATION_gc;
    while (remaining--){
        *buf++ = pgm_read_byte(addr++);
    }
    return ep0_buf_in;
}
#endif

void usb_ep0_in_multi(void) {
    uint16_t tsize = usb_ep0_in_size;

    if (tsize > USB_EP0_SIZE) {
        tsize = USB_EP0_SIZE;
    }

#ifdef DESCRIPTORS_IN_PROGMEM
    usb_ep0_from_progmem(usb_ep0_in_ptr, tsize);
#else
    memcpy(ep0_buf_in, usb_ep0_in_ptr, tsize);
#endif
    usb_ep0_in(tsize);

    if (tsize == 0) {
        usb_ep0_out();
    }

    usb_ep0_in_size -= tsize;
    usb_ep0_in_ptr += tsize;
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
                const uint8_t* descriptor = 0;
                uint16_t interface = (usb_setup.wIndex);
                uint16_t size = usb_cb_get_descriptor(type, index, interface, &descriptor);

                if (size && descriptor) {
                    if (size > usb_setup.wLength) {
                        size = usb_setup.wLength;
                    }

                    if (descriptor == ep0_buf_in) {
                        usb_ep0_in_size = 0;
                        usb_ep_start_in(0x80, ep0_buf_in, size, true);
                    } else {
                        usb_ep0_in_size = size;
                        usb_ep0_in_ptr = descriptor;
                        usb_ep0_in_multi();
                    }

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
