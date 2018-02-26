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
    CHIP_ID_ATxmega128A4U = CHIP_ID_ATMEL | 0x000B,
    CHIP_ID_ATxmega64A3U = CHIP_ID_ATMEL | 0x000C,
    CHIP_ID_ATxmega128A3U = CHIP_ID_ATMEL | 0x000D,
    CHIP_ID_ATxmega192A3U = CHIP_ID_ATMEL | 0x000E,
    CHIP_ID_ATxmega256A3U = CHIP_ID_ATMEL | 0x000F,
    CHIP_ID_ATxmega256A3BU = CHIP_ID_ATMEL | 0x0010,
    CHIP_ID_ATxmega64A1U = CHIP_ID_ATMEL | 0x0011,
    CHIP_ID_ATxmega128A1U = CHIP_ID_ATMEL | 0x0012,

    CHIP_ID_ATxmega64B3 = CHIP_ID_ATMEL | 0x0013,
    CHIP_ID_ATxmega128B3 = CHIP_ID_ATMEL | 0x0014,
    CHIP_ID_ATxmega64B1 = CHIP_ID_ATMEL | 0x0015,
    CHIP_ID_ATxmega128B1 = CHIP_ID_ATMEL | 0x0016,

    CHIP_ID_ATxmega16C4  = CHIP_ID_ATMEL | 0x0017,
    CHIP_ID_ATxmega32C4  = CHIP_ID_ATMEL | 0x0018,
    CHIP_ID_ATxmega32C3  = CHIP_ID_ATMEL | 0x0019,
    CHIP_ID_ATxmega64C3  = CHIP_ID_ATMEL | 0x001A,
    CHIP_ID_ATxmega128C3 = CHIP_ID_ATMEL | 0x001B,
    CHIP_ID_ATxmega192C3 = CHIP_ID_ATMEL | 0x001C,
    CHIP_ID_ATxmega256C3 = CHIP_ID_ATMEL | 0x001D,
    CHIP_ID_ATxmega384C3 = CHIP_ID_ATMEL | 0x001E,

/*********************************************************************
 *                     Nordic Semiconductor                          *
 *********************************************************************/

    CHIP_ID_nRF24LU1_F16  = CHIP_ID_NORDIC | 0x0001,
    CHIP_ID_nRF24LU1P_F16 = CHIP_ID_NORDIC | 0x0002,
    CHIP_ID_nRF24LU1P_F32 = CHIP_ID_NORDIC | 0x0003,
    // CHIP_ID_nRF52840 = CHIP_ID_NORDIC | 0x5200,

};

