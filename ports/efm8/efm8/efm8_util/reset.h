// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "efm8_util/io.h"

/// @brief  Perform a software reset
/// @note   This function is implemented as a macro.
#ifdef IS_DOXYGEN
extern void efm8_software_reset(void);
#else
    #if defined(EFM8UB3_DEVICE) || defined(EFM8UB1_DEVICE)
        // reset on page 0
        #define efm8_software_reset() \
            do { \
                SFRPAGE = 0x00; \
                RSTSRC  = RSTSRC_SWRSF__BMASK; \
            } while (0)
    #elif defined(EFM8UB2_DEVICE)
        // reset on all pages
        #define efm8_software_reset() \
            do { \
                RSTSRC  = RSTSRC_SWRSF__BMASK; \
            } while (0)
    #endif
#endif


/// @brief  Perform a software reset, and enter the factor bootloader
/// @note   This function is implemented as a macro.
#ifdef IS_DOXYGEN
extern void efm8_factory_bootloader_jump(void);
#else
    #if defined(EFM8UB3_DEVICE) || defined(EFM8UB1_DEVICE)
        // reset on page 0
        #define efm8_factory_bootloader_jump() \
            do { \
                SFRPAGE = 0x00; \
                *((uint8_t __idata*) 0x00) = 0xA5; \
                RSTSRC = RSTSRC_SWRSF__BMASK; \
            } while (0)
    #elif defined(EFM8UB2_DEVICE)
        // reset on all pages
        #define efm8_factory_bootloader_jump() \
            do { \
                *((uint8_t __idata*) 0x00) = 0xA5; \
                RSTSRC = RSTSRC_SWRSF__BMASK; \
            } while (0)
    #endif
#endif


