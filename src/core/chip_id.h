// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file src/core/chip_id.h

#pragma once

/// Upper 16 bits of the chip_id is used for vendor specific id. We use the
/// USB Vendor ID of the chip manufacturer to differentiate them.
enum chip_id_vendor_type {
    CHIP_ID_ATMEL = 0x03eb0000,
    CHIP_ID_NORDIC = 0x19150000,
};

enum chip_id_controller_type {
/*********************************************************************
 *                               Atmel                               *
 *********************************************************************/

    // xmega AVR

    CHIP_ID_ATxmega16A4 = CHIP_ID_ATMEL | 0x0001,
    CHIP_ID_ATxmega32A4 = CHIP_ID_ATMEL | 0x0002,
    CHIP_ID_ATxmega64A3 = CHIP_ID_ATMEL | 0x0003,
    CHIP_ID_ATxmega128A3 = CHIP_ID_ATMEL | 0x0004,
    CHIP_ID_ATxmega192A3 = CHIP_ID_ATMEL | 0x0005,
    CHIP_ID_ATxmega256A3 = CHIP_ID_ATMEL | 0x0006,
    CHIP_ID_ATxmega64A1 = CHIP_ID_ATMEL | 0x0007,
    CHIP_ID_ATxmega128A1 = CHIP_ID_ATMEL | 0x0008,

    CHIP_ID_ATxmega16A4U = CHIP_ID_ATMEL | 0x0009,
    CHIP_ID_ATxmega32A4U = CHIP_ID_ATMEL | 0x000A,
    CHIP_ID_ATxmega64A4U = CHIP_ID_ATMEL | 0x000B,
    CHIP_ID_ATxmega128A4U = CHIP_ID_ATMEL | 0x000C,
    CHIP_ID_ATxmega64A3U = CHIP_ID_ATMEL | 0x000D,
    CHIP_ID_ATxmega128A3U = CHIP_ID_ATMEL | 0x000E,
    CHIP_ID_ATxmega192A3U = CHIP_ID_ATMEL | 0x000F,
    CHIP_ID_ATxmega256A3U = CHIP_ID_ATMEL | 0x0010,
    CHIP_ID_ATxmega256A3BU = CHIP_ID_ATMEL | 0x0011,
    CHIP_ID_ATxmega64A1U = CHIP_ID_ATMEL | 0x0012,
    CHIP_ID_ATxmega128A1U = CHIP_ID_ATMEL | 0x0013,

    CHIP_ID_ATxmega64B3 = CHIP_ID_ATMEL | 0x0020,
    CHIP_ID_ATxmega128B3 = CHIP_ID_ATMEL | 0x0021,
    CHIP_ID_ATxmega64B1 = CHIP_ID_ATMEL | 0x0022,
    CHIP_ID_ATxmega128B1 = CHIP_ID_ATMEL | 0x0023,

    CHIP_ID_ATxmega16C4  = CHIP_ID_ATMEL | 0x0030,
    CHIP_ID_ATxmega32C4  = CHIP_ID_ATMEL | 0x0031,
    CHIP_ID_ATxmega32C3  = CHIP_ID_ATMEL | 0x0032,
    CHIP_ID_ATxmega64C3  = CHIP_ID_ATMEL | 0x0033,
    CHIP_ID_ATxmega128C3 = CHIP_ID_ATMEL | 0x0034,
    CHIP_ID_ATxmega192C3 = CHIP_ID_ATMEL | 0x0035,
    CHIP_ID_ATxmega256C3 = CHIP_ID_ATMEL | 0x0036,
    CHIP_ID_ATxmega384C3 = CHIP_ID_ATMEL | 0x0037,


    // mega AVR with USB
    CHIP_ID_ATmega8U2   = CHIP_ID_ATMEL | 0x1000,
    CHIP_ID_ATmega16U2  = CHIP_ID_ATMEL | 0x1001,
    CHIP_ID_ATmega32U2  = CHIP_ID_ATMEL | 0x1002,

    CHIP_ID_ATmega16U4  = CHIP_ID_ATMEL | 0x1003,
    CHIP_ID_ATmega32U4  = CHIP_ID_ATMEL | 0x1004,

    CHIP_ID_ATmega32U6  = CHIP_ID_ATMEL | 0x1005,
    CHIP_ID_AT90USB646  = CHIP_ID_ATMEL | 0x1006,
    CHIP_ID_AT90USB647  = CHIP_ID_ATMEL | 0x1007,
    CHIP_ID_AT90USB1286 = CHIP_ID_ATMEL | 0x1008,
    CHIP_ID_AT90USB1287 = CHIP_ID_ATMEL | 0x1009,


/*********************************************************************
 *                     Nordic Semiconductor                          *
 *********************************************************************/

    CHIP_ID_nRF24LU1_F16  = CHIP_ID_NORDIC | 0x0001,
    CHIP_ID_nRF24LU1P_F16 = CHIP_ID_NORDIC | 0x0002,
    CHIP_ID_nRF24LU1P_F32 = CHIP_ID_NORDIC | 0x0003,
    // CHIP_ID_nRF52840 = CHIP_ID_NORDIC | 0x5200,

};

