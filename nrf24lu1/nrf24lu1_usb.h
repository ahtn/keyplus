// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

// interrupt codes
#define IVEC_SUDAV     0x00
#define IVEC_SOF       0x04
#define IVEC_SUTOK     0x08
#define IVEC_SUSPEND   0x0C
#define IVEC_USBRESET  0x10
#define IVEC_EP0IN     0x18
#define IVEC_EP0OUT    0x1C
#define IVEC_EP1IN     0x20
#define IVEC_EP1OUT    0x24
#define IVEC_EP2IN     0x28
#define IVEC_EP2OUT    0x2C
#define IVEC_EP3IN     0x30
#define IVEC_EP3OUT    0x34
#define IVEC_EP4IN     0x38
#define IVEC_EP4OUT    0x3C
#define IVEC_EP5IN     0x40
#define IVEC_EP5OUT    0x44

// usbirq, usbien
#define USBIRQ_URES_bm  (1 << 4)
#define USBIRQ_SUSP_bm  (1 << 3)
#define USBIRQ_SUTOK_bm (1 << 2)
#define USBIRQ_SOF_bm   (1 << 1)
#define USBIRQ_SUDAV_bm (1 << 0)

// in_irq, out_irq
#define USBIRQ_EP0 (1 << 0)
#define USBIRQ_EP1 (1 << 1)
#define USBIRQ_EP2 (1 << 2)
#define USBIRQ_EP3 (1 << 3)
#define USBIRQ_EP4 (1 << 4)
#define USBIRQ_EP5 (1 << 5)

// ep0cs
#define EP0CS_CHGSET_bm (1 << 5)
#define EP0CS_DSTALL_bm (1 << 4)
#define EP0CS_OUTBSY_bm (1 << 3)
#define EP0CS_INBSY_bm (1 << 2)
#define EP0CS_HSNAK_bm (1 << 1)
#define EP0CS_EP0STALL_bm (1 << 0)

// inxcs
#define INXCS_INXBSY (1 << 1)
#define INXCS_INXSTL (1 << 0)

// outxcs
#define OUTXCS_OUTXBSY (1 << 1)
#define OUTXCS_OUTXSTL (1 << 0)

// inxcs, outxcs
#define CS_BSY (1 << 1)
#define CS_STL (1 << 0)

// usbcs
#define USBCS_WAKESRC_bm  (1 << 7)
#define USBCS_SOFGEN_bm   (1 << 5)
#define USBCS_DISCON_bm   (1 << 3)
#define USBCS_FORCEJ_bm   (1 << 1)
#define USBCS_SIGRSUME_bm (1 << 0)

// togctl
#define TOGCTL_Q_bm  (1 << 7)
#define TOGCTL_S_bm   (1 << 6)
#define TOGCTL_R_bm   (1 << 5)
#define TOGCTL_IO_bm   (1 << 4)
#define TOGCTL_EP_bp 0
#define TOGCTL_EP_bm (0b111 << TOGCTL_EP_bp)

// usbpair
#define USBPAIR_isosend0_bm (1 << 7)
#define USBPAIR_PR4OUT_bm   (1 << 4)
#define USBPAIR_PR2OUT_bm   (1 << 3)
#define USBPAIR_PR6IN_bm    (1 << 2)
#define USBPAIR_PR4IN_bp    (1 << 1)
#define USBPAIR_PR2IN_bm    (1 << 0)
