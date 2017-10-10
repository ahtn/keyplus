// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

// USB0XCN: USB0 Transceiver Control
#define PREN_bp 7
#define PREN_bm (1 << PREN_bp)
#define PHYEN_bp 6
#define PHYEN_bm (1 << PHYEN_bp)
#define SPEED_bp 5
#define SPEED_bm (1 << SPEED_bp)

#define PHYTST_gp 3
enum {
    PHYTST_NORMAL = 0b00,
    PHYTST_DIFFERENTIAL_1 = 0b01,
    PHYTST_DIFFERENTIAL_0 = 0b10,
    PHYTST_SINGLE_ENDED_0 = 0b11,
};

#define DFREC_bp 2
#define DFREC_bm (1 << DFREC_bp)
#define Dp_bp 1
#define Dp_bm (1 << Dp_bp)
#define Dn_bp 0
#define Dn_bm (1 << Dn_bp)

// USB0ADR: USB0 Indirect Address
#define BUSY_bp 7
#define BUSY_bm (1 << BUSY_bp)
#define AUTORD_bp 6
#define AUTORD_bm (1 << AUTORD_bp)

#define USBADDR_bp 0
#define USBADDR_bm (0b00111111 << USBADDR_bp)

// USB0 control registers
// The are read and written by writing to the USB0ADR and USB0DAT registers.
// The USB0ADR is set to one of the addresses below and then it can be read
// and written by reading/writing to the USB0DAT register.
//
// The indexed registers are used for controlling endpoints0-3. To select which
// endpoint the registers are controlling, the USB0_INDEX register must be
// set to the corresponding endpoint.

// interrupt registers
#define USB0_IN1INT    0x02
#define USB0_OUT1INT   0x04
#define USB0_CMINT     0x06
#define USB0_IN1IE     0x07
#define USB0_OUT1IE    0x09
#define USB0_CMIE      0x0B
// common registers
#define USB0_FADDR     0x00
#define USB0_POWER     0x01
#define USB0_FRAMEL    0x0C
#define USB0_FRAMEH    0x0D
#define USB0_INDEX     0x0E
#define USB0_CLKREC    0x0F
#define USB0_EENABLE   0x1E
#define USB0_FIFO0     0x20
#define USB0_FIFO1     0x21
#define USB0_FIFO2     0x22
#define USB0_FIFO3     0x23
// indexed registers
#define USB0_E0CSR     0x11
#define USB0_EINCSRL   0x11
#define USB0_EINCSRH   0x12
#define USB0_EOUTCSRH  0x14
#define USB0_EOUTCSRL  0x15
#define USB0_E0CNT     0x16
#define USB0_EOUTCNTL  0x16
#define USB0_EOUTCNTH  0x17

#define USB0_W_ADDR(addr, src) {\
    USB0ADR = USB0_#addr; \
    USB0DAT = val; \
}

#define USB0_R_ADDR(addr) \
    USB0ADR = USB0_#addr, \
    dest = USB0DAT

#define USB0_SET_ADDR(addr) {\
    USB0ADR = USB0_#addr; \
}

#define USB0_R() (USB0DAT)

#define USB0_W(val) (USB0DAT = val)

#define USB0_SET_INDEX(index) {\
    USB0ADR = USB0_INDEX; \
    USB0DAT = index; \
}
