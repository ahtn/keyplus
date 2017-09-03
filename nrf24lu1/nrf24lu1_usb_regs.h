// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include "usb/util/requests.h"

#ifdef DECLARE_USB_REGS
// actual declaration
#define USB_REG_DECL(x) volatile __xdata __at(x)
#else
// forward declaration
#define USB_REG_DECL(x) extern volatile __xdata
#endif

// NOTE: these registers map to a shared region of memory that is configured by
// setting the boutXaddr and binXaddr registers. These registers determine the
// actual size of the buffers. Refer to section 7.7 of the nrf24lu1+ datasheet.
USB_REG_DECL(0xC440) uint8_t out5buf[64];
USB_REG_DECL(0xC480) uint8_t in5buf[64];
USB_REG_DECL(0xC4C0) uint8_t out4buf[64];
USB_REG_DECL(0xC500) uint8_t in4buf[64];
USB_REG_DECL(0xC540) uint8_t out3buf[64];
USB_REG_DECL(0xC580) uint8_t in3buf[64];
USB_REG_DECL(0xC5C0) uint8_t out2buf[64];
USB_REG_DECL(0xC600) uint8_t in2buf[64];
USB_REG_DECL(0xC640) uint8_t out1buf[64];
USB_REG_DECL(0xC680) uint8_t in1buf[64];
USB_REG_DECL(0xC6C0) uint8_t out0buf[64];
USB_REG_DECL(0xC700) uint8_t in0buf[64];

USB_REG_DECL(0xC760) uint8_t out8data;
USB_REG_DECL(0xC768) uint8_t in8data;

USB_REG_DECL(0xC770) uint8_t out8bch;
USB_REG_DECL(0xC771) uint8_t out8bcl;

USB_REG_DECL(0xC781) uint8_t bout1addr;
USB_REG_DECL(0xC782) uint8_t bout2addr;
USB_REG_DECL(0xC783) uint8_t bout3addr;
USB_REG_DECL(0xC784) uint8_t bout4addr;
USB_REG_DECL(0xC785) uint8_t bout5addr;
USB_REG_DECL(0xC788) uint8_t binstaddr;
USB_REG_DECL(0xC789) uint8_t bin1addr;
USB_REG_DECL(0xC78A) uint8_t bin2addr;
USB_REG_DECL(0xC78B) uint8_t bin3addr;
USB_REG_DECL(0xC78C) uint8_t bin4addr;
USB_REG_DECL(0xC78D) uint8_t bin5addr;


USB_REG_DECL(0xC7A0) uint8_t isoerr;
USB_REG_DECL(0xC7A2) uint8_t zbcout;

USB_REG_DECL(0xC7A8) uint8_t ivec;
USB_REG_DECL(0xC7A9) uint8_t in_irq;
USB_REG_DECL(0xC7AA) uint8_t out_irq;
USB_REG_DECL(0xC7AB) uint8_t usbirq;
USB_REG_DECL(0xC7AC) uint8_t in_ien;
USB_REG_DECL(0xC7AD) uint8_t out_ien;
USB_REG_DECL(0xC7AE) uint8_t usbien;
USB_REG_DECL(0xC7AF) uint8_t usbbav;

USB_REG_DECL(0xC7B4) uint8_t ep0cs;
USB_REG_DECL(0xC7B5) uint8_t in0bc;
USB_REG_DECL(0xC7B6) uint8_t in1cs;
USB_REG_DECL(0xC7B7) uint8_t in1bc;
USB_REG_DECL(0xC7B8) uint8_t in2cs;
USB_REG_DECL(0xC7B9) uint8_t in2bc;
USB_REG_DECL(0xC7BA) uint8_t in3cs;
USB_REG_DECL(0xC7BB) uint8_t in3bc;
USB_REG_DECL(0xC7BC) uint8_t in4cs;
USB_REG_DECL(0xC7BD) uint8_t in4bc;
USB_REG_DECL(0xC7BE) uint8_t in5cs;
USB_REG_DECL(0xC7BF) uint8_t in5bc;

USB_REG_DECL(0xC7C5) uint8_t out0bc;
USB_REG_DECL(0xC7C6) uint8_t out1cs;
USB_REG_DECL(0xC7C7) uint8_t out1bc;
USB_REG_DECL(0xC7C8) uint8_t out2cs;
USB_REG_DECL(0xC7C9) uint8_t out2bc;
USB_REG_DECL(0xC7CA) uint8_t out3cs;
USB_REG_DECL(0xC7CB) uint8_t out3bc;
USB_REG_DECL(0xC7CC) uint8_t out4cs;
USB_REG_DECL(0xC7CD) uint8_t out4bc;
USB_REG_DECL(0xC7CE) uint8_t out5cs;
USB_REG_DECL(0xC7CF) uint8_t out5bc;

USB_REG_DECL(0xC7D6) uint8_t usbcs;
USB_REG_DECL(0xC7D7) uint8_t togctl;
USB_REG_DECL(0xC7D8) uint8_t usbframel;
USB_REG_DECL(0xC7D9) uint8_t usbframeh;
USB_REG_DECL(0xC7DB) uint8_t fnaddr;
USB_REG_DECL(0xC7DD) uint8_t usbpair;
USB_REG_DECL(0xC7DE) uint8_t inbulkval;
USB_REG_DECL(0xC7DF) uint8_t outbulkval;
USB_REG_DECL(0xC7E0) uint8_t inisoval;
USB_REG_DECL(0xC7E1) uint8_t outisoval;
USB_REG_DECL(0xC7E8) uint8_t setupbuf[8];
USB_REG_DECL(0xC7F0) uint8_t out8addr;
USB_REG_DECL(0xC7F8) uint8_t in8addr;

USB_REG_DECL(0xC7E8) usb_request_t usb_request;
