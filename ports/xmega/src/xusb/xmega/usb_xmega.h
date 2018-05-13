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

#pragma once

#include "xmega/usb_xmega_internal.h"
#include "usb.h"

/// Configure the XMEGA's clock for use with USB.
void usb_configure_clock(void);

#ifdef DESCRIPTORS_FROM_PROGMEM
/// Copy data from program memory to the ep0 IN buffer
const uint8_t* usb_ep0_from_progmem(const uint8_t* addr, uint16_t size);
#endif


typedef union USB_EP_pair{
    union{
        struct{
            USB_EP_t out;
            USB_EP_t in;
        };
        USB_EP_t ep[2];
    };
} __attribute__((packed)) USB_EP_pair_t;

extern USB_EP_pair_t usb_xmega_endpoints[];
extern const uint8_t usb_num_endpoints;

/* inline void usb_ep_enable(uint8_t ep, uint8_t type, usb_size bufsize); */
#define _USB_EP(epaddr) \
    USB_EP_pair_t* pair = &usb_xmega_endpoints[(epaddr & 0x3F)]; \
    USB_EP_t* e __attribute__ ((unused)) = &pair->ep[!!(epaddr&0x80)]; \

inline void usb_ep_enable(uint8_t ep, uint8_t type, usb_size bufsize) {
    _USB_EP(ep);
    e->STATUS = USB_EP_BUSNACK0_bm;
    e->CTRL = type | USB_EP_size_to_gc(bufsize);
}

inline void usb_ep_disable(uint8_t ep) {
    _USB_EP(ep);
    e->CTRL = 0;
}

inline void usb_ep_reset(uint8_t ep){
    _USB_EP(ep);
    e->STATUS = USB_EP_BUSNACK0_bm;
}

#define GCC_FORCE_ALIGN_2  __attribute__((__aligned__(2)))

#define USB_ENDPOINTS(NUM_EP) \
    const uint8_t usb_num_endpoints = (NUM_EP); \
    USB_EP_pair_t usb_xmega_endpoints[(NUM_EP)+1] GCC_FORCE_ALIGN_2;
