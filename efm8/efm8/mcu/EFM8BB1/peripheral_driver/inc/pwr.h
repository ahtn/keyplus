/******************************************************************************
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __PWR_H__
#define __PWR_H__

#include "efm8_config.h"
#include "SI_EFM8BB1_Register_Enums.h"

/**************************************************************************//**
 * @addtogroup pwr_group Power Mode Driver
 * @{
 *
 * @brief Power mode driver for the EFM8BB1.
 *
 * # Introduction #
 *
 * This module provides an API for entering each of the low power modes of 
 * the EFM8BB1. The API reconfigures the system as required to enter each  
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
 * |Default    |                             |   16 |     0 |     0 |    0 |
 * |Stop       |EFM8PDL_PWR_USE_STOP         |   +9 |     0 |     0 |    0 |
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
 * 	- **Shutdown**: The CPU is halted; internal circuitry is powered down,
 *	  no RAM nor registers are retained; external I/O retain configured state, 
 *	  system waits for POR or pin reset to wake up the device.
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
 * @warning Stop mode is supported for legacy reasons only. New designs
 * are strongly encouraged to use other modes instead.
 *
 * Default setting is '0' and may be overridden by defining in 'efm8_config.h'.
 *****************************************************************************/

/** @} (end addtogroup pwr_config */

// Configuration default values
#ifdef IS_DOXYGEN
#define EFM8PDL_PWR_USE_STOP 1
#endif

#ifndef EFM8PDL_PWR_USE_STOP
#define EFM8PDL_PWR_USE_STOP 0
#endif

// The API starts here

/**************************************************************************//**
 * @addtogroup pwr_runtime Power Driver Runtime API
 * @{
 *****************************************************************************/

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
 * Enter power mode SHUTDOWN. 
 *
 * Shutdown is similar to stop mode. The CPU is halted and the internal LDO is
 * powered down. Internal circuitry is powered down and debug circuitry is 
 * disconencted. Internal memory is not retained. External peripherals remain 
 * in their selected states, but are not provided a clock.
 *
 * This function does not return. Only POR or pin reset terminates Shutdown mode 
 * and execution resumes at the reset vector.
 *
 * ~~~~~.c
 * // Enter Shutdown mode waiting for any reset
 * PWR_enterShutdown();
 * ~~~~~
 *
 * @warning This API is not re-entrant and must not be called from interrupt
 * context.
 *****************************************************************************/
extern void PWR_enterShutdown(void);

/** @} (end addtogroup pwr_runtime) */
/** @} (end addtogroup pwr_group) */
#endif // __PWR_H__
