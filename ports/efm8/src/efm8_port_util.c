// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "efm8_port_util.h"

#include "efm8_util/io.h"

#include "core/io_map.h"

void efm8_port_setup(uint8_t port_num, uint8_t mdout, uint8_t mdin) {
    // NOTE: 8051 can't indirectly address SFRs, so need to hard code them here.

#if defined(EFM8UB1_DEVICE) || defined(EFM8UB3_DEVICE)
    // All PxMDIN, PxMDOUT, PxSKIP, XBRx are all on PG3 on these micros
    SFRPAGE = PG3_PAGE;
#endif

    switch (port_num) {
        case 0: {
            P0MDOUT = mdout;
            P0MDIN = mdin;
        } break;
        case 1: {
            P1MDOUT = mdout;
            P1MDIN = mdin;
        } break;
        case 2: {
            P2MDOUT = mdout;
            P2MDIN = mdin;
        } break;
#if IO_PORT_MAX_PORT_NUM >= 3
        case 3: {
            P3MDOUT = mdout;
            P3MDIN = mdin;
        } break;
#endif
#if IO_PORT_MAX_PORT_NUM >= 4
        case 4: {
            P4MDOUT = mdout;
            P4MDIN = mdin;
        } break;
#endif
    }

#if defined(EFM8UB1_DEVICE) || defined(EFM8UB3_DEVICE)
    SFRPAGE = 0;
#endif
}

void efm8_reset_ports(void) {
    uint8_t i;
    for (i = 0; i <= IO_PORT_MAX_PORT_NUM; ++i) {
        efm8_port_setup(i, 0x00, 0xff);
        efm8_port_set(i, 0xff);
    }
}

void efm8_port_set(uint8_t port_num, uint8_t pin_mask) {
    switch (port_num) {
        case 0: {
            P0 |= pin_mask;
        } break;
        case 1: {
            P1 |= pin_mask;
        } break;
        case 2: {
            P2 |= pin_mask;
        } break;
#if IO_PORT_MAX_PORT_NUM >= 3
        case 3: {
            P3 |= pin_mask;
        } break;
#endif
#if IO_PORT_MAX_PORT_NUM >= 4
        case 4: {
            P4 |= pin_mask;
        } break;
#endif
    }
}

void efm8_port_clear(uint8_t port_num, uint8_t pin_mask) {
    pin_mask = ~pin_mask;
    switch (port_num) {
        case 0: {
            P0 &= pin_mask;
        } break;
        case 1: {
            P1 &= pin_mask;
        } break;
        case 2: {
            P2 &= pin_mask;
        } break;
#if IO_PORT_MAX_PORT_NUM >= 3
        case 3: {
            P3 &= pin_mask;
        } break;
#endif
#if IO_PORT_MAX_PORT_NUM >= 4
        case 4: {
            P4 &= pin_mask;
        } break;
#endif
    }
}

uint8_t efm8_port_read(uint8_t port_num) {
    switch (port_num) {
        case 0: {
            return P0;
        } break;
        case 1: {
            return P1;
        } break;
        case 2: {
            return P2;
        } break;
#if IO_PORT_MAX_PORT_NUM >= 3
        case 3: {
            return P3;
        } break;
#endif
#if IO_PORT_MAX_PORT_NUM >= 4
        case 4: {
            return P4;
        } break;
#endif
    }
    return 0;
}
