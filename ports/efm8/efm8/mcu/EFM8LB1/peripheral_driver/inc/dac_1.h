/******************************************************************************
 * Copyright (c) 2014 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __DAC_1_H__
#define __DAC_1_H__
 
#include "efm8_config.h"
#include "SI_EFM8LB1_Register_Enums.h"

/**************************************************************************//**
 * @addtogroup dac_1 DAC1 Driver
 * @{
 *
 * @brief Peripheral driver for DAC1
 *
 * # Introduction #
 *
 * This module provides an API for using the DAC1 peripheral. This includes
 * a simple initialization routine, as well as an API for using this
 * peripheral during run-time.
 *
 * ## Memory Usage ##
 *
 * The following table shows the approximate amount of memory used by this
 * module with various features enabled.  Typically, only a portion of the
 * module's API is used, so actual memory usage is expected to be less.
 *
 * |Config        |Macro                     | CODE | XDATA | IDATA | DATA |
 * |--------------|--------------------------|------|-------|-------|------|
 * |Base          |                          |  29  |     0 |     0 |   0.1|
 * |Init          |EFM8PDL_DAC1_USE_INIT     | +18  |     0 |     0 |   0  |
 * |Auto Page     |EFM8PDL_DAC1_AUTO_PAGE    | +45  |     0 |     0 |  +1  |
 * |Default (All) |                          |  92  |     0 |     0 |   1.1|
 *
 * ## Setting Output Voltage ##
 * The DAC1 module is used to output a user determined voltage to a pin. The
 * formula for determining the value required for a particular voltage is
 * as follows:
 * ~~~~~.c
 * Output Value = (Desired Voltage * Maximum Value) / Reference Voltage 
 * ~~~~~
 *
 * Since the DAC has twelve bits of resolution, this translates into:
 * ~~~~~.c
 * Output Value = (Desired Voltage * 0xFFF) / Reference Voltage 
 * ~~~~~
 *
 * @note This output value may need to be shifted depending on whether or not left-justify
 *       is enabled. With left-justify enabled, this twelve-bit value will need to be
 *       shifted left four times.
 *
 * For example, if the DAC's reference voltage is configured to be 3.0V, and left
 * justification is off, to set the output to 1.0V:
 * ~~~~~.c
 * DAC1_setOutput((1*0xFFF)/3);
 * ~~~~~
 *
 * This will set the DAC's output value, but this may not be reflected as a change
 * in voltage on the output pin until the DAC's update source triggers an update.
 * This trigger source can be configured to by the system clock, or one of a 
 * number of signals from various peripherals. These sources can be selected when
 * using the simple initialization function DAC1_init(), or when generating 
 * initialization code using Hardware Configurator.
 *
 * ## Enabling/Disabling or Holding the Output ##
 * The DAC can be enabled or disabled, which will determine if the output voltage
 * is driven on the output pin. This can be accomplished through the DAC1_enable()
 * and DAC1_disable() functions.
 *
 * Additionally, the output voltage can also be frozen, or held, to prevent it
 * from changing if the output value is changed and an update trigger occurs.
 * To freeze the output voltage:
 * ~~~~~.c
 * DAC1_holdOutput(true);
 * ~~~~~
 * This will halt updates to the output voltage until the following function
 * is called:
 * ~~~~~.c
 * DAC1_holdOutput(false);
 * ~~~~~
 *
 *
 *****************************************************************************/
 
 //Option macro documentation
/**************************************************************************//**
 * @addtogroup dac_config Driver Configuration
 * @{
 *  
 *  @brief
 *    Driver configuration constants read from efm8_config.h
 * 
 *  This peripheral driver will look for configuration constants in 
 *  **efm8_config.h**. This file is provided/written by the user and should be 
 *  located in a directory that is part of the include path. 
 *  
 ******************************************************************************/
/**************************************************************************//**
 * @def EFM8PDL_DAC1_AUTO_PAGE
 * @brief Controls if the library handles SI_SFR paging.
 *
 * When '1' the DAC1 driver automatically handles setting and restoring
 * SI_SFR page for each call. When disabled the library consumes less code
 * space but the user must ensure that the correct page is set when calling
 * driver functions that access hardware.
 *
 * Default setting is '1' and may be overridden by defining in 'efm8_config.h'.
 *
 *****************************************************************************/
 /**************************************************************************//**
 * @def EFM8PDL_DAC1_USE_INIT
 * @brief Controls inclusion of DAC1 Initialization function.
 *
 * When '1' the DAC1_init() function is available for use. This provides a
 * rudimentary way to initialize and enable the DAC. For more advanced 
 * configurations, generate an initialization routine using Configurator.
 *
 * Default setting is '1' and may be overridden by defining in 'efm8_config.h'.
 * 
 *****************************************************************************/
 
/**  @} (end addtogroup dac_config Driver Configuration) */

#ifndef IS_DOXYGEN
  #define IS_DOXYGEN 0
#endif

#ifndef EFM8PDL_DAC1_AUTO_PAGE
 #define EFM8PDL_DAC1_AUTO_PAGE 1
#endif

#ifndef EFM8PDL_DAC1_USE_INIT
 #define EFM8PDL_DAC1_USE_INIT 1
#endif

// Initialization API
/**************************************************************************//**
 * @addtogroup dac1_init DAC1 Initialization API
 * @{
 *****************************************************************************/
 
/// @brief Output Update Trigger Source Enum.
typedef enum {
    DAC1_UPDATE_TRIGGER_SYSCLK  = DAC1CF0_UPDATE__SYSCLK, //!< DAC1 output updates occur on every SYSCLK clock cycle
    DAC1_UPDATE_TRIGGER_TIMER3  = DAC1CF0_UPDATE__TIMER3, //!< DAC1 output updates occur on Timer 3 high byte overflow
    DAC1_UPDATE_TRIGGER_TIMER4  = DAC1CF0_UPDATE__TIMER4, //!< DAC1 output updates occur on Timer 4 high byte overflow
    DAC1_UPDATE_TRIGGER_TIMER5  = DAC1CF0_UPDATE__TIMER5, //!< DAC1 output updates occur on Timer 5 high byte overflow
    DAC1_UPDATE_TRIGGER_CLU0    = DAC1CF0_UPDATE__CLU0, //!< DAC1 output updates occur on Configurable Logic output 0 rising edge
    DAC1_UPDATE_TRIGGER_CLU1    = DAC1CF0_UPDATE__CLU1,   //!< DAC1 output updates occur on Configurable Logic output 1 rising edge
    DAC1_UPDATE_TRIGGER_CLU2    = DAC1CF0_UPDATE__CLU2, //!< DAC1 output updates occur on Configurable Logic output 2 rising edge
    DAC1_UPDATE_TRIGGER_CLU3    = DAC1CF0_UPDATE__CLU3, //!< DAC1 output updates occur on Configurable Logic output 3 rising edge
  }DAC1_UpdateTrigger_t ;

 /***************************************************************************//**
 * @brief
 * Initialize the DAC.
 *
 * @param trigger:
 * The update trigger source. This determines when the output voltage of the DAC
 * will change to the currently loaded output value.
 *
 * This is a basic initialization function that configures and enables the DAC,
 * allowing an output voltage range of GND to VDD.
 *
 * The initialization API provides only the most basic and common configuration
 * options. To access more advanced options, or to generate more efficient 
 * initialization code, please use the Hardware Configuration tool.
 *
 ******************************************************************************/
void DAC1_init(DAC1_UpdateTrigger_t trigger);

/** @} (end dac1_init DAC1 Initialization API) */

// Runtime API
/**************************************************************************//**
 * @addtogroup dac1_runtime DAC1 Runtime API
 * @{
 *****************************************************************************/
 /***************************************************************************//**
 * @brief
 * Enable the DAC
 *
 * The DAC will be enabled and the output voltage will be driven at the output pin.
 *
 ******************************************************************************/
void DAC1_enable(void);

 /***************************************************************************//**
 * @brief
 * Disable the DAC
 *
 * The DAC will be immediately disabled and the output pin will no longer be driven.
 *
 ******************************************************************************/
void DAC1_disable(void);

/***************************************************************************//**
* @brief
* Set the output level of the DAC.
*
* @param value
* The value to write to the DAC output registers.
*
* This function writes the given value to the DAC output registers. While
* the registers are being updated, update sources will be disabled. 
*
* @note The value to write for a particular voltage will depend on the DAC's reference,
*       output gain, and data word justification settings.
*
* @note The output voltage will not change until the update source triggers
*       after the output value is set.
*
******************************************************************************/
void DAC1_setOutput(uint16_t value);

/***************************************************************************//**
* @brief
* Prevent the DAC output from changing from its current output voltage.
*
* @param hold
* Determines whether the output will be held or allowed to update.
*
* This function will prevent update triggers from changing the output voltage.
* If hold is **true**, the DAC's output value can be changed, but this change 
* will not be reflected in a change in the output pin voltage when following 
* update triggers occur. Setting hold to **false** will allow update triggers
* to continue changing the output voltage to the DAC's loaded output value.
*
******************************************************************************/
void DAC1_holdOutput(bool hold);

 /***************************************************************************//**
 * @brief
 * Read the current output value.
 *
 * @return The current output value setting for the DAC.
 *
 * This function reads the current output value setting loaded into the DAC's
 * output registers.
 *
 * @note This value may not reflect the current output voltage of the DAC if the 
 * DAC update source has not triggered an update since the last write to the output
 * registers, or if the DAC's output voltage is being held by DAC1_holdOutput().
 *
 ******************************************************************************/
uint16_t DAC1_getOutput(void);

/** @} (end adc0_runtime ADC0 Runtime API) */
/** @} (end addtogroup dac_1 DAC1 Driver) */

#endif //__DAC_1_H__
