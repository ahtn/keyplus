/******************************************************************************
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __PWR_H__
#define __PWR_H__

#include "efm8_config.h"
#include "SI_EFM8SB1_Register_Enums.h"

/**************************************************************************//**
 * @addtogroup pwr_group Power Mode Driver
 * @{
 *
 * @brief Power mode driver for the EFM8SB1.
 *
 * # Introduction #
 *
 * This module provides an API for entering each of the low power modes of 
 * the EFM8SB1. The API reconfigures the system as required to enter each  
 * specific mode, then restores the system configuration upon returning 
 * from that mode. Before calling this API, the application will need to 
 * make additional system adjustments such as disabling unneeded peripherals 
 * or reconfiguring port pins in order to achieve the lowest power for a 
 * given mode. Also, the application will need to properly configure any 
 * peripheral or subsystem that is used to wake the device from a low power 
 * mode.
 *
 * ## Memory Usage ##
 *
 * The following table shows the approximate amount of memory used by this
 * module with various features enabled.  Typically, only a portion of the 
 * module's API is used, so actual memory usage is expected to be less.
 *
 * |Config     |Macro                        | CODE | XDATA | IDATA | DATA |
 * |-----------|-----------------------------|------|-------|-------|------|
 * |Default    |                             |  160 |     1 |     0 |    0 |
 * |Stop       |EFM8PDL_PWR_USE_STOP         |  +31 |     0 |     0 |    0 |
 * |Auto Delay |EFM8PDL_PWR_AUTO_RSTWK_DELAY |  +20 |     0 |     0 |    0 |
 * |Auto Page  |EFM8PDL_PWR_AUTO_PAGE        |  +16 |     0 |     0 |    0 |
 *
 * ## Supported Power Modes ##
 *
 * This module provides functions for entering each of the modes listed below. 
 * To reduce memory footprint, build options are provided to include each API 
 * individually. The supported modes are listed from highest to lowest power.
 *
 *  - **Idle**: The CPU core is halted; peripherals are fully operational; 
 *    the core waits for any interrupt to continue.
 *  - **Stop**: All clocks are stopped; memory is retained; the device waits 
 *    for any reset source to restart.
 *  - **Suspend**: The high-frequency internal clocks are halted; select 
 *    peripherals remain active; the system waits for a wake event to continue.
 *  - **Sleep**: The internal clocks and regulator are shut down; memory, 
 *    registers and ports are retained; the system waits for a wake event to 
 *    continue.
 *
 * ## Notes ##
 *
 * Including this module automatically reserves address 0x0000 of the external 
 * data memory space (XRAM). Due to a device errata, this location may be 
 * overwritten with a random value on device reset or upon waking from Sleep
 * mode.
 *
 *****************************************************************************/

// The following section documents configuration options

/**************************************************************************//**
 * @addtogroup pwr_config Driver Configuration
 * @{
 *
 * @brief Driver configuration constants read from efm8_config.h.
 *
 * This peripheral driver will look for configuration constants in 
 * **efm8_config.h**. This file is provided/written by the user and 
 * must be located in a directory that is part of the include path. 
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_PWR_USE_STOP
 * @brief Controls inclusion of the Power STOP Mode API.
 *
 * If this setting is '1' the API for entering Stop mode is included.
 *
 * @warning Suspend mode provides equal or better power savings with a faster 
 * wake-up time. Stop mode is supported for legacy reasons only. New designs
 * are strongly encouraged to use Suspend mode instead.
 *
 * Default setting is '0' and may be overridden by defining in 'efm8_config.h'.
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_PWR_AUTO_RSTWK_DELAY
 * @brief Provides an automatic delay for the reset pin wake source.
 *
 * If this setting is '1' the PWR_enterSuspend() and PWR_enterSleep() functions 
 * will automatically delay 15 usec after waking from the reset pin source.
 *
 * @note In order for the MCU to respond to the pin reset event, software must 
 * not re-enter Suspend or Sleep mode for a period of 15 usec.
 *
 * The default setting is '1' and may be overridden by defining the value
 * in 'efm8_config.h'.
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_PWR_AUTO_PAGE
 * @brief Provides automatic SFR paging and restoring.
 *
 * If this setting is '1' the power driver will not assume the SFR page and 
 * will explicitly set and restore the SFR page whenever it accesses an SFR. 
 * This adds more code and processing time to the power driver API. If your 
 * code ensures that the SFRPAGE remains at 0 by default whenever calling 
 * this API, then this setting can be turned off which will save code and 
 * improve performance.
 *
 * The default setting is '1' and may be overridden by defining the value
 * in 'efm8_config.h'.
 *****************************************************************************/

/** @} (end addtogroup pwr_config */

// Configuration default values
#ifdef IS_DOXYGEN
#define EFM8PDL_PWR_USE_STOP 1
#endif

#ifndef EFM8PDL_PWR_USE_STOP
#define EFM8PDL_PWR_USE_STOP 0
#endif
#ifndef EFM8PDL_PWR_AUTO_RSTWK_DELAY
#define EFM8PDL_PWR_AUTO_RSTWK_DELAY 1
#endif
#ifndef EFM8PDL_PWR_AUTO_PAGE
#define EFM8PDL_PWR_AUTO_PAGE 1
#endif

// The API starts here

/**************************************************************************//**
 * @addtogroup pwr_runtime Power Driver Runtime API
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @addtogroup pwr_wakeflags Power Driver Wake-up Flags
 * @{
 *
 * The following macros define the wake-up bits used to configure the power
 * management unit (PMU0). These values are OR'd and passed to the functions 
 * PWR_enterSuspend() and PWR_enterSleep() to enable wake-up sources. They are 
 * also used to form the return value for PWR_readAndClearWakeFlags().
 *****************************************************************************/

/// Wake-up from a Comparator 0 rising edge.
#define PWR_CPT0_WF PMU0CF_CPT0WK__BMASK

/// Wake-up from a Port Match event.
#define PWR_PMAT_WF PMU0CF_PMATWK__BMASK

/// Wake-up from an RTC Alarm.
#define PWR_RTCA_WF PMU0CF_RTCAWK__BMASK

/// Wake-up from an RTC oscillator fail event.
#define PWR_RTCF_WF PMU0CF_RTCFWK__BMASK

/// Wake-up from a glitch detected on RSTb.                          
#define PWR_RST_WF PMU0CF_RSTWK__BMASK

/// Wake-up from a Capacitive Sensing event.
#define PWR_CS0_WF 0x80

/** @} (end addtogroup pwr_wakeflags) */

/**************************************************************************//**
 * Reads then clears all PMU0 wake-up flags.
 *
 * @return Snapshot of the wake-up flags before clearing. The value is the 
 * OR of all flags that were set. Valid flags are defined in @ref pwr_wakeflags.
 *
 * PMU0 includes registers that capture system events that wake-up the device 
 * from either the Suspend or Sleep modes. This function reads and clears these 
 * registers. PMU0 continuously captures wake-up events during all power modes 
 * including normal mode. The wake-up flags are sticky and must be cleared by 
 * firmware. The Suspend and Sleep modes will not be entered if a wake-up 
 * flag is set when the mode is requested.
 *
 * ~~~~~.c
 * uint8_t wflags;
 *
 * // Enter Sleep mode waiting for a port match event
 * PWR_enterSleep(PWR_PMAT_WF);
 *
 * // Read then clear all wake-up flags
 * wflags = PWR_readAndClearWakeFlags();
 * ~~~~~
 *
 * @note Reading and clearing the wake-up flags is not an atomic operation. 
 * Because the flags are edge-triggered, it is possible to lose an event that 
 * occurs between the reading and clearing operations. To be safe, the 
 * application should also check the configured wake sources to see if an 
 * event has occurred. 
 *
 * @note Enabled wake-up sources with an active wake-up flag will cause the 
 * PMU0 to draw additional power. Thus the application should always call this 
 * function soon after waking up, including after a reset since the Reset Pin
 * wake-up source is always enabled.
 *****************************************************************************/
extern uint8_t PWR_readAndClearWakeFlags(void);

/**************************************************************************//**
 * Enter power mode IDLE. 
 *
 * Idle is a standard 8051 power mode. The core is halted with all peripherals 
 * clocked and fully operational. All internal registers and memory are retained. 
 * Power consumption is dependent upon the system clock frequency and any active 
 * peripherals.
 * 
 * This function returns when any enabled interrupt is asserted. Also, any reset 
 * will cancel Idle mode and resume execution from the reset vector.
 *
 * ~~~~~.c
 * // Configure and enable any interrupt source
 *
 * // Enable all interrupts
 * IE_EA = 1;
 *
 * // Enter Idle mode waiting for the configured interrupt or any reset
 * PWR_enterIdle();
 * ~~~~~
 *
 * @note A watchdog (WDT) time-out will cancel Idle mode by generating a reset.
 *
 * @note To achieve lowest power, this function selects flash one-shot read 
 * timing before entering Idle mode and restores the original value upon return.
 * Note that one-shot flash read timing will be in effect when the resuming 
 * interrupt handler runs. 
 *
 * @warning This API is not re-entrant and must not be called from interrupt
 * context.
 *****************************************************************************/
extern void PWR_enterIdle(void);

#if (EFM8PDL_PWR_USE_STOP == 1)
/**************************************************************************//**
 * Enter power mode STOP. 
 *
 * Stop is a standard 8051 power mode. The CPU is halted and peripheral clocks 
 * are stopped. Analog peripherals remain in their selected states, but are not
 * provided a clock. Internal memory is retained.
 *
 * This function does not return. Any reset terminates Stop mode and execution 
 * resumes at the reset vector.
 *
 * ~~~~~.c
 * // Enter Stop mode waiting for any reset
 * PWR_enterStop();
 * ~~~~~
 *
 * @note If enabled as a reset source, the missing clock detector will trigger 
 * an internal reset and cancel Stop mode.
 *
 * @note To achieve lowest power, this function selects flash one-shot read 
 * timing before entering Stop mode.
 *
 * @warning Suspend mode provides equal or better power savings with a faster 
 * wake-up time. Stop mode is supported for legacy reasons only. New designs
 * are strongly encouraged to use Suspend mode instead.
 *
 * @warning This API is not re-entrant and must not be called from interrupt
 * context.
 *****************************************************************************/
extern void PWR_enterStop(void);
#endif // EFM8PDL_PWR_USE_STOP

/**************************************************************************//**
 * Enter power mode SUSPEND. 
 *
 * @param flags Wake-up sources to enable. Multiple sources are enabled by 
 * OR-ing their flags. Valid flags are defined in @ref pwr_wakeflags.
 *
 * Suspend is similar to Stop mode, but resumes execution at the next instruction 
 * with a very fast wake-up time. In Suspend mode the core and digital peripherals 
 * are halted; internal oscillators are disabled; and all internal registers, 
 * memory and ports are retained.
 *
 * This function returns when any of the selected wake-up events occur. The 
 * application is responsible for configuring the associated peripherals to 
 * generate the event. The available wake-up sources are:
 * - RTC0 Alarm Event
 * - RTC0 Fail Event
 * - Port Match Event
 * - Comparator 0 Rising Edge
 * - CS0 End of Conversion/Scan
 * - Pin Reset glitch too short to reset the device (always enabled)
 *
 * Additionally, Suspend is terminated by any reset source with execution 
 * resuming at the reset vector. 
 *
 * If any of the selected wake-up flags are set on entry, this function will return
 * immediately. Wake-up flags are continuously updated and the application is 
 * responsible for clearing them using PWR_readAndClearWakeFlags().
 *
 * ~~~~~.c
 * // Configure an RTC0 alarm
 *
 * // Enter Suspend mode waiting for RTC alarm or clock failure
 * PWR_enterSuspend(PWR_RTCA_WF | PWR_RTCF_WF);
 *
 * // Read then clear all wake-up flags
 * wflags = PWR_readAndClearWakeFlags();
 * ~~~~~
 *
 * @note This routine automatically adjusts the system clock and flash timing
 * to ensure Suspend mode is safely entered. The original system settings are 
 * restored on wake-up. 
 *
 * @note To provide consistent timing, this function disables and restores the
 * global interrupt enable until after all system settings are restored. For 
 * wake-up sources that have interrupts enabled, the ISR will not be serviced 
 * until after the original clock settings are restored. This ensures that the 
 * ISR runs under the original application settings.
 *
 * @note In order for the MCU to respond to the pin reset event, software must 
 * not re-enter Suspend or Sleep mode for a period of 15 usec. This function 
 * will automatically delay after waking from the reset pin source if the 
 * EFM8PDL_PWR_AUTO_RSTWK_DELAY configuration option is enabled.
 *
 * @warning This API is not re-entrant and must not be called from interrupt
 * context.
 *****************************************************************************/
extern void PWR_enterSuspend(uint8_t flags);

/**************************************************************************//**
 * Enter power mode SLEEP. 
 *
 * @param flags Wake-up sources to enable. Multiple sources are enabled by 
 * OR-ing their flags. Valid flags are defined in @ref pwr_wakeflags.
 *
 * Sleep is similar to Suspend Mode, with the internal LDO shut-down. Very low 
 * power is achieved at the cost of a longer wake-up time. In Sleep mode most 
 * internal power nets are shut down; only select circuits remain powered; port 
 * pins retain state; and internal registers and memory are retained.
 *
 * This function returns when any of the selected wake-up events occur. The 
 * application is responsible for configuring the associated peripherals to 
 * generate the event. The available wake-up sources are:
 * - RTC0 Alarm Event
 * - RTC0 Fail Event
 * - Port Match Event
 * - Comparator 0 Rising Edge
 * - Pin Reset glitch too short to reset the device (always enabled)
 *
 * If any of the selected wake-up flags are set on entry, this function will return
 * immediately. Wake-up flags are continuously updated and the application is 
 * responsible for clearing them using PWR_readAndClearWakeFlags().
 *
 * ~~~~~.c
 * // Configure an RTC0 alarm
 *
 * // Enter Sleep mode waiting for RTC alarm or clock failure
 * PWR_enterSleep(PWR_RTCA_WF | PWR_RTCF_WF);
 *
 * // Read then clear all wake-up flags
 * wflags = PWR_readAndClearWakeFlags();
 * ~~~~~
 *
 * @note This routine automatically adjusts the system clock and flash timing
 * to ensure Suspend mode is safely entered. The original system settings are 
 * restored on wake-up. 
 *
 * @note To provide consistent timing, this function disables and restores the
 * global interrupt enable until after all system settings are restored. For 
 * wake-up sources that have interrupts enabled, the ISR will not be serviced 
 * until after the original clock settings are restored. This ensures that the 
 * ISR runs under the original application settings.
 *
 * @note In order for the MCU to respond to the pin reset event, software must 
 * not re-enter Suspend or Sleep mode for a period of 15 usec. This function 
 * will automatically delay after waking from the reset pin source if the 
 * EFM8PDL_PWR_AUTO_RSTWK_DELAY configuration option is enabled.
 *
 * @warning This API is not re-entrant and must not be called from interrupt
 * context.
 *****************************************************************************/
extern void PWR_enterSleep(uint8_t flags);

/** @} (end addtogroup pwr_runtime) */
/** @} (end addtogroup pwr_group) */
#endif // __PWR_H__
