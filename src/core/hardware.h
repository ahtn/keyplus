// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file
///
/// @brief Common defines for controlling the MCU hardware.

#pragma once

#include "core/util.h"

#if !defined(DOXYGEN)
    // NOTE: must implement static_delay_us(t) and static_delay_ms(t)
    // Also, make sure that F_CPU and CLOCK_SPEED_SLOW are set
    #include "port_impl/hardware.h"
#else
    // Values that will need to be defined by the mcu port

    /// @brief A delay in us for a delay value known at compile time
    ///
    /// NOTE: may be implemented by a macro
    ///
    /// @param us The delay in microseconds
    void static_delay_us(us);

    /// @brief A delay in ms for a delay value known at compile time
    ///
    /// NOTE: may be implemented by a macro
    ///
    /// @param ms The delay in milliseconds
    void static_delay_ms(ms);

    /// @brief Enable interrupts on the microcontroller
    ///
    /// NOTE: may be implemented by a macro
    void enable_interrupts();

    /// @brief Disable interrupts on the microcontroller
    ///
    /// NOTE: may be implemented by a macro
    void disable_interrupts();

    /// @brief A flash memory address. Type is platform dependent
    typedef int flash_ptr_t;

    /// @brief The bus width of the microprocessor
    #define MCU_BITNESS

    /// @brief The page size of flash memory
    /// TODO: rename to FLASH_PAGE_SIZE?
    #define PAGE_SIZE
#endif

#include <stdint.h>

#ifndef F_CPU
    #error "F_CPU needs to be defined"
#endif

#ifndef enable_interrupts
    #error "enale_interrupts needs to be defined in 'hardware_port_impl.h'"
#endif

#ifndef disable_interrupts
    #error "disable_interrupts needs to be defined in 'hardware_port_impl.h'"
#endif

#ifndef SETTINGS_ADDR
    #error "SETTINGS_ADDR not defined"
#endif

#ifndef LAYOUT_ADDR
    #error "LAYOUT_ADDR not defined"
#endif

#define CLOCK_SPEED_FAST F_CPU

#ifndef CLOCK_SPEED_SLOW
    #define CLOCK_SPEED_SLOW F_CPU
#endif

#define CLOCK_SLOW_DIV ((float)CLOCK_SPEED_FAST/(float)CLOCK_SPEED_SLOW)

/// @brief A static delay in microseconds for when the system clock is slow.
///
/// See @ref static_delay_slow_us()
///
/// Note: this function should take a compile time constant as an argument
///
/// @param ms The delay in milliseconds
#define static_delay_slow_us(t) (static_delay_us( (int)((float)t/CLOCK_SLOW_DIV) ))

/// @brief A static delay in milliseconds for when the system clock is slow.
///
/// For platforms that run the device at multiple clock frequencies, this
/// delay will be used for the slow clock frequency.
///
/// Note: this function should take a compile time constant as an argument
///
/// @param us The delay in microseconds
#define static_delay_slow_ms(t) (static_delay_ms( (int)((float)t/CLOCK_SLOW_DIV) ))

/// @brief A us delay that may run on fast or slow clock.
///
/// Selects either @ref static_delay_us() or @ref static_delay_slow_us()
/// based on the value of @ref g_slow_clock_mode.
/// This allow the same code to be run on whether the normal or slow clock
/// speed.
#define static_delay_variable_clock_us(t) { \
    if (g_slow_clock_mode) { \
        static_delay_slow_us(t); \
    } else { \
        static_delay_us(t); \
    } \
}

/// Tracks whether the clock is running in fast or slow mode.
// TODO: only define for battery mode
// TODO: implement as a function
extern bit_t g_slow_clock_mode;

#if (USE_I2C || USE_NRF24) && USE_USB
    /// Tracks whether the device is connected to a USB port.
    /// TODO: implement as a function
    extern bit_t g_has_usb_port;
#endif

/// Perform a software reset.
void software_reset(void);

/*********************************************************************
 *              functions that need to be implemented                *
 *********************************************************************/

/// @brief A delay in ms for a delay value that may not be known at compile time
///
/// @param ms The delay in milliseconds
void dynamic_delay_ms(uint16_t t);

/// @brief Initialize the hardware of the microcontroller
void hardware_init(void);

/// @brief Run the devices bootloader.
void bootloader_jmp(void);

/// TODO: deprecated this
void bootloader_jmp_2(void);

/// @brief Resets the mcu
void reset_mcu(void);

#ifdef NO_IDLE_SLEEP
    #define idle_sleep() {}
#else
    /// @brief Put the microcontroller into sleep mode until the next interrupt.
    void idle_sleep(void);
#endif

/// @brief Initialize the watchdog timer
void wdt_init(void);

/// @brief Disables the watchdog timer
void wdt_disable_(void); // NOTE: cannot be supported on some platforms

/// @brief Resets the watchdog timer
void wdt_kick(void);
