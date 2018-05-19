// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

// Universal Bee
#if defined(EFM8UB1_DEVICE)
    #define EFM8_UID_SIZE 16
    #define EFM8_UID_FLASH
    #define EFM8_UUID 1
#elif defined(EFM8UB2_DEVICE)
    #define EFM8_UID_SIZE 16
    #define EFM8_UID_XRAM
    #define EFM8_UUID 0
#elif defined(EFM8UB3_DEVICE)
    #define EFM8_UID_SIZE 16
    #define EFM8_UID_FLASH
    #define EFM8_UUID 1
#elif defined(EFM8UB4_DEVICE)
    #define EFM8_UID_SIZE 16
    #define EFM8_UID_FLASH
    #define EFM8_UUID 1
// Busy Bee
#elif defined(EFM8BB1_DEVICE)
    #define EFM8_UID_SIZE 4
    #define EFM8_UID_XRAM
    #define EFM8_UUID 0
#elif defined(EFM8BB2_DEVICE)
    #define EFM8_UID_SIZE 16
    #define EFM8_UID_FLASH
    #define EFM8_UUID 1
#elif defined(EFM8BB3_DEVICE)
    #define EFM8_UID_SIZE 16
    #define EFM8_UID_FLASH
    #define EFM8_UUID 1
// Laser Bee
#elif defined(EFM8LB1_DEVICE)
    #define EFM8_UID_SIZE 16
    #define EFM8_UID_FLASH
    #define EFM8_UUID 1
// Sleepy Bee
#elif defined(EFM8SB1_DEVICE)
    #define EFM8_UID_SIZE 4
    #define EFM8_UID_XRAM
    #define EFM8_UUID 0
#elif defined(EFM8SB2_DEVICE)
    #define EFM8_UID_SIZE 4
    #define EFM8_UID_XRAM
    #define EFM8_UUID 0
// No match
#else
    #error "EFM8 device type not define"
#endif

// For variants that have 0 bytes of XRAM, use internal RAM instead
#if DEVICE_XRAM_SIZE == 0
    #undef  EFM8_UID_XRAM
    #define EFM8_UID_RAM
#endif


#if defined(DOXYGEN)
    /// The size in bytes of the EFM8 UID. (May vary by device)
    #define EFM8_UID_SIZE

    /// @brief EFM8 128 bit unique identifier (UID)
    ///
    /// Each EFM8 has a UID that is stored in either flash or ram at a fixed
    /// address.
    ///
    /// On some chips this UID is a UUID, on others it is only a UID and does
    /// not have the standard UUID format.
    ///
    /// * On EFM8UB1: 128bit UUID stored in flash
    /// * On EFM8UB3: 128bit UUID stored in flash
    /// * On EFM8UB2: 128bit UID stored in XRAM
    ///
    static const uint8_t EFM8_UID[EFM8_UID_SIZE];

    /// Defined if the EFM8_UID is stored in XRAM
    #define EFM8_UID_XRAM

    /// Defined if the EFM8_UID is stored in flash
    #define EFM8_UID_FLASH

    /// Defined if the EFM8_UID is stored in internal RAM
    #define EFM8_UID_RAM
#else
    // Variants that store the UID in flash
    #if defined(EFM8_UID_FLASH)
        #define EFM8_UID_ADDRESS   0xFFC0
        static const __code __at(EFM8_UID_ADDRESS) uint8_t EFM8_UID[EFM8_UID_SIZE];
    // Variants that store the UID in XRAM
    #elif defined(EFM8_UID_XRAM)
        #define EFM8_UID_ADDRESS   (DEVICE_XRAM_SIZE - EFM8_UID_SIZE)
        static const __xdata __at(EFM8_UID_ADDRESS) uint8_t EFM8_UID[EFM8_UID_SIZE];
    // Variants that store the UID in internal RAM
    #elif defined(EFM8_UID_RAM)
        #define EFM8_UID_ADDRESS   (256 - EFM8_UID_SIZE)
        static const __idata __at(EFM8_UID_ADDRESS) uint8_t EFM8_UID[EFM8_UID_SIZE];
    #endif
#endif
