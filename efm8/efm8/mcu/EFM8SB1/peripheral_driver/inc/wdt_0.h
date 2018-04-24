/******************************************************************************
 * Copyright (c) 2014 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __WDT_0_H__
#define __WDT_0_H__


#include "efm8_config.h"
#include "SI_EFM8SB1_Register_Enums.h"

/**************************************************************************//**
 * @addtogroup wdt_0 WDT0 Driver
 * @{
 *
 * @brief
 * Peripheral driver for WDT0
 *
 * # Introduction #
 *
 * This module contains all the driver content for the Watch Dog Timer.
 *
 * @warning 
 * The WDT0 module on this device uses PCA channel 2. When the
 * Watchdog timer is running the PCA can not be halted and channel 2
 * can not be used. In addition calls to WDT0_init will overwrite any
 * previous PCA initialization.
 *
 * ### Memory Usage ###
 *
 * The table below shows the memory consumption of the library with various
 * options. The 'default' entry shows the consumption when most or all available
 * functions are called. Typical consumption is expected to be less than this
 * since there are normally many uncalled functions that will consume no
 * resources.
 *
 * @note It is possible for memory usage to exceed the listed values in rare cases
 *
 * | condition          | CODE | XRAM | IRAM | RAM |
 * |--------------------|------|------|------|-----|
 * |default             |  144 |    0 |    0 |   0 |
 *
 * # Theory of Operation #
 *
 * Typically the WDT is used to detect and respond to software lock-up
 * events. Code resets the timer periodically preventing it from timing out
 * if a timeout is seen the device is reset.
 *
 * The library provides functions for feeding (resetting) the timer
 * as well as doing basic initial configuration.
 *
 * ### Hardware Configuration ###
 *
 * While the driver does provide facilities for configuring the WDT
 * it is highly recommended that Simplicity Hardware Configurator be
 * used as it provides more comprehensive validation of user selections.
 *
 *****************************************************************************/

//Option macro documentation
/**************************************************************************//**
 * @addtogroup wdt0_config Driver Configuration
 * @{
 *****************************************************************************/

/***************************************************************************//**
 * @brief
 * Controls if the library handles SI_SFR paging.
 *
 * When '1' the WDT0 driver automatically handles setting and restoring
 * SI_SFR page for each call. When disabled the library consumes less code
 * space but the user must ensure that the correct page is set when calling
 * driver functions that access hardware.
 *
 * Default setting is '1' and may be overridden by defining in 'efm8_config.h'.
 *
 *****************************************************************************/
#define EFM8PDL_WDT0_AUTO_PAGE 1

/** @} (end addtogroup wdt0_config Driver Configuration) */


//Configuration defaults
#ifndef EFM8PDL_WDT0_AUTO_PAGE
#define EFM8PDL_WDT0_AUTO_PAGE 1
#endif

// Runtime API
/**************************************************************************//**
 * @addtogroup wdt0_runtime WDT0 Runtime API
 * @{
 *****************************************************************************/

/***************************************************************************//**
 * @brief
 * Convert a number of counter ticks to interval setting
 *
 * This macro will convert timer ticks to an interval value and round up
 * to the nearest interval value. It should be used to derive the required
 * interval value for WDT0_init.
 *
 *****************************************************************************/
#define WDT0_ticksToInterval(ticks) ((ticks+0xFF)>>8)

/******************************************************************************
 * @brief 
 * Initialize and start the watch dog.
 *
 *****************************************************************************/
void WDT0_start();

 /******************************************************************************
 * @brief 
 * Disables the WDT located in PCA channel 4.
 *
 * This function disables the WDT if enabled. If not enabled the function does nothing.
 * To re-enable the WDT init function.
 * 
 *****************************************************************************/
void WDT0_stop();

/***************************************************************************//**
 * @brief
 * Reset the timer.
 *
 *****************************************************************************/
void WDT0_feed();

/** @} (end addtogroup wdt0_runtime WDT0 Runtime API) */

// Initialization API
/**************************************************************************//**
 * @addtogroup wdt0_init WDT0 Initialization API
 * @{
 *****************************************************************************/

/// @brief Clock Selection Enum.
typedef enum
{
  WDT0_SYSCLK_DIV12 = PCA0MD_CPS__SYSCLK_DIV_12, //!< Select SystemClock/12
  WDT0_SYSCLK_DIV4 = PCA0MD_CPS__SYSCLK_DIV_4,   //!< Select SystemClock/4
  WDT0_TIMER0      = PCA0MD_CPS__T0_OVERFLOW,    //!< Select Timer0 Overflow
  WDT0_ECI         = PCA0MD_CPS__ECI,            //!< Select ECI falling edge
  WDT0_SYSCLK      = PCA0MD_CPS__SYSCLK,         //!< Select SystemClock
  WDT0_EXTOSC_DIV8 = PCA0MD_CPS__EXTOSC_DIV_8,   //!< Select ExternalOsc/8
  WDT0_LFOSC_DIV8  = PCA0MD_CPS__RTC_DIV_8,      //!< Select LFOSC (RTC)/8
#ifdef IS_DOXYGEN
  WDT0_LFOSC       = -1,   //!< NOT SUPPORTED ON THIS DEVICE
#endif
} WDT0_Timebase_t;

///  @brief Idle state of PCA Counter
typedef enum
{
  WDT0_IDLE_RUN     = PCA0MD_CIDL__NORMAL,  //!< PCA runs when idle
  WDT0_IDLE_SUSPEND = PCA0MD_CIDL__SUSPEND, //!< PCA suspended when idle
} WDT0_IdleState_t;


/***************************************************************************//**
 * @brief
 * Initialize and start the watch dog.
 *
 * @param timebase:
 * Timebase selection.
 * @param interval:
 * timeout interval setting.
 * @param idleState:
 * Idle state selection.
 *
 * The format timeout interval setting changes from device to device
 * The macro WDT0_ticksToInterval will convert the number of desired counter
 * ticks to the appropriate interval value rounding up to the nearest valid
 * interval.
 *
 *****************************************************************************/
void WDT0_init(uint8_t interval, WDT0_Timebase_t  timebase, WDT0_IdleState_t idleState);

/** @} (end addtogroup wdt0_init WDT0 Initialization API) */
/** @} (end addtogroup wdt_0 WDT0 Driver) */
#endif //__WDT_0_H__
