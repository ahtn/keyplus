/******************************************************************************
 * Copyright (c) 2016 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __ADC_0_H__
#define __ADC_0_H__
 
#include "efm8_config.h"
#include "SI_EFM8BB1_Register_Enums.h"


/**************************************************************************//**
 * @addtogroup adc_0 ADC0 Driver
 * @{
 *
 * @brief Peripheral driver for ADC0
 *
 * # Introduction #
 *
 * This module contains all the driver content for ADC0. This provides a
 * runtime API for operating the ADC in polled or interrupt modes, as well
 * as an API to allow for the use of the ADC's autoscan mode. This module
 * also contains a basic initialization routine.
 *
 *****************************************************************************/

 /**************************************************************************//**
 * @addtogroup adc_0 ADC0 Driver
 * @{
 * ## Memory Usage ##
 *
 * The following table shows the approximate amount of memory used by this
 * module with various features enabled.  Typically, only a portion of the 
 * module's API is used, so actual memory usage is expected to be less.
 *
 * |Config        |Macro                     | CODE | XDATA | IDATA | DATA |
 * |--------------|--------------------------|------|-------|-------|------|
 * |Base          |                          |  148 |     0 |     0 |  0.2 |
 * |Init          |EFM8PDL_ADC0_USE_INIT     | +131 |     0 |     0 |   +7 |
 * |Default (All) |                          |  406 |     0 |     0 |  11.2|
 *
 *****************************************************************************/
 
 /**************************************************************************//**
 * @addtogroup adc_0 ADC0 Driver
 * @{
 * ## Polled Mode ##
 * The ADC can be used in a simple "Polled Mode" configuration, where conversions
 * are started manually, and then polls for a conversion complete event are
 * performed until the conversion is finished. This can be accomplished by:
 * ~~~~~.c
 * uint16_t result;
 * // Set the ADC input to ADC0_P0
 * ADC0_setPositiveInput(ADC0_POSITIVE_INPUT_P0);
 *
 * // Start a conversion
 * ADC0_startConversion();
 * 
 * // Wait for conversion to complete 
 * while(!ADC0_isConversionComplete());
 *
 * // Get the result
 * result = ADC0_getResult();
 * ~~~~~
 *
 *
 * ## Interrupt Mode ##
 * As an alternative to Polled Mode, which will block the CPU while the ADC
 * is performing a conversion, Interrupt Mode allows the ADC to trigger an
 * interrupt when a conversion is completed. This frees the CPU to perform
 * other tasks while the ADC is busy, or allows the CPU to go into a lower
 * power mode for the conversion duration.
 *
 * @note This example uses a manual conversion source (ADC0_CONVERSION_START_ADBUSY),
 *      which relies on the user calling ADC0_startConversion(). However, other sources are
 *      available that do not require user intervention.
 *
 * ~~~~~.c
 * void main (void)
 * {
 *   uint16_t result;
 *   // Initialization provided from Configurator
 *   enter_DefaultMode_from_RESET();
 *
 *   // Set the ADC input to ADC0_P0
 *   ADC0_setPositiveInput(ADC0_POSITIVE_INPUT_P0);
 *
 *   // Enable conversion-complete interrupt 
 *   ADC0_enableInt(ADC0_CONVERSION_COMPLETE_IF, true);
 *
 *   while (1)
 *   {
 *     // Start a conversion
 *     ADC0_startConversion();
 * 
 *     // Idle the CPU until the next interrupt
 *     PCON0 |= PCON0_IDLE__IDLE;
 *   }
 * }
 *
 * SI_INTERRUPT (ADC0EOC_ISR, ADC0EOC_IRQn)
 * {
 *   uint16_t result;
 *
 *   // Clear interrupt flag
 *   ADC0_clearIntFlags(ADC0_CONVERSION_COMPLETE_IF);
 *
 *   // Get the latest ADC result
 *   result = ADC0_getResult();
 *
 *  //Process the result
 *
 * }
 * ~~~~~
 *
 *****************************************************************************/
 
 //Option macro documentation
/**************************************************************************//**
 * @addtogroup adc_config Driver Configuration
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
 * @def EFM8PDL_ADC0_USE_INIT
 * @brief Controls inclusion of ADC0 Initialization function.
 *
 * When '1' the ADC0_init() function is available for use. This provides a
 * rudimentary way to initialize and enable the ADC. For more advanced 
 * configurations, generate an initialization routine using Configurator.
 *
 * Default setting is '1' and may be overridden by defining in 'efm8_config.h'.
 *
 *****************************************************************************/
/**  @} (end addtogroup adc_config Driver Configuration) */

#ifndef IS_DOXYGEN
  #define IS_DOXYGEN 0
#endif
 
#ifndef EFM8PDL_ADC0_USE_INIT
 #define EFM8PDL_ADC0_USE_INIT 1
#endif

// Initialization API
/**************************************************************************//**
 * @addtogroup adc0_init ADC0 Initialization API
 * @{
 *****************************************************************************/
 
/// @brief Start of Conversion Source Enum.
typedef enum {
    ADC0_CONVERSION_START_MANUAL    = ADC0CN0_ADCM__ADBUSY, //!< Conversions are only started manually, with ADC0_startConversion()
    ADC0_CONVERSION_START_TIMER0    = ADC0CN0_ADCM__TIMER0, //!< Timer0 Overflow starts a conversion.
    ADC0_CONVERSION_START_TIMER2    = ADC0CN0_ADCM__TIMER2, //!< Timer2 Overflow starts a conversion.
    ADC0_CONVERSION_START_TIMER3    = ADC0CN0_ADCM__TIMER3, //!< Timer3 Overflow starts a conversion.
    ADC0_CONVERSION_START_CNVSTR    = ADC0CN0_ADCM__CNVSTR, //!< Rising edge of CNVSTR pin starts a conversion.
}ADC0_ConversionStart_t ;

/// @brief ADC Resolution Enum.
typedef enum {
    ADC0_RESOLUTION_8_BIT  = ADC0CF_AD8BE__8_BIT,            //!< Select 8-bit resolution
    ADC0_RESOLUTION_10_BIT = ADC0AC_AD12BE__12_BIT_DISABLED, //!< Select 10-bit resolution.
    ADC0_RESOLUTION_12_BIT = ADC0AC_AD12BE__12_BIT_ENABLED,  //!< Select 12-bit resolution.
} ADC0_Resolution_t;

 /***************************************************************************//**
 * @brief
 * Initialize the ADC.
 *
 * @param convStart:
 * The start of conversion source.
 * @param resolution:
 * The resolution in which the ADC takes measurements.
 * @param sysclk:
 * The system clock frequency, in Hz.
 *
 * This is a basic initialization function that configures the ADC for single
 * conversions at the fastest possible SARCLK frequency given the SYSCLK frequency.
 *
 * The initialization API provides only the most basic and common configuration
 * options. To access more advanced options, or to generate more efficient 
 * initialization code, please use the Hardware Configuration tool.
 *
 ******************************************************************************/
void ADC0_init(ADC0_ConversionStart_t convStart, 
                ADC0_Resolution_t resolution,
                uint32_t sysclk);

/** @} (end adc0_init ADC0 Initialization API) */

// Runtime API
/**************************************************************************//**
 * @addtogroup adc0_runtime ADC0 Runtime API
 * @{
 *****************************************************************************/
 
 /**************************************************************************//**
 * @addtogroup adc0_if Interrupt Flag Enums
 * @{
 ******************************************************************************/
#define ADC0_CONVERSION_COMPLETE_IF  ADC0CN0_ADINT__BMASK    //!<  Conversion complete flag
#define ADC0_WINDOW_COMPARE_IF ADC0CN0_ADWINT__BMASK //!<  Window compare flag

/** @} (end addtogroup adc0_if Interrupt Flag Enums) */

/***************************************************************************//**
 * @brief
 * Return the value of the interrupt flags
 *
 * @return
 * The state of the Interrupt flags. This value is the logical OR of any of the 
 * following  flags found within @ref adc0_if "Interrupt Flag Enums":
 *  - \b ADC0_CONVERSION_COMPLETE_IF - Interrupt flag for a conversion complete
 *    event.
 *  - \b ADC0_WINDOW_COMPARE_IF - Interrupt flag for when a newly completed
 *    conversion falls outside the set compare window.
 *
 ******************************************************************************/
 uint8_t ADC0_getIntFlags(void);

/***************************************************************************//**
 * @brief
 * Clear the specified interrupt flags.
 *
 * @param flags:
 * A bit mask of interrupt flags to be cleared. This value is the logical OR
 * of any of the following flags found within @ref adc0_if "Interrupt Flag Enums":
 *  - \b ADC0_CONVERSION_COMPLETE_IF - Interrupt flag for a conversion complete
 *    event.
 *  - \b ADC0_WINDOW_COMPARE_IF - Interrupt flag for when a newly completed
 *    conversion falls outside the set compare window.
 *
 ******************************************************************************/
void ADC0_clearIntFlags(uint8_t flags);

/***************************************************************************//**
 * @brief
 * Enable or disable the ADC interrupts
 *
 * @param flags:
 * A bit mask of interrupts to be enabled or disabled. This value is the logical OR
 * of any of the following flags found within @ref adc0_if "Interrupt Flag Enums":
 *  - \b ADC0_CONVERSION_COMPLETE_IF - Interrupt flag for a conversion complete
 *    event.
 *  - \b ADC0_WINDOW_COMPARE_IF - Interrupt flag for when a newly completed
 *    conversion falls outside the set compare window.
 *
 * @param enable:
 * New interrupt status (**true** to enable, **false** to disable)
 *
 *
 ******************************************************************************/
void ADC0_enableInt(uint8_t flags, bool enable);

 /***************************************************************************//**
 * @brief
 * Enable the ADC
 *
 * The ADC will be enabled, allowing conversion triggers to start a conversion.
 *
 ******************************************************************************/
void ADC0_enable(void);

 /***************************************************************************//**
 * @brief
 * Disable the ADC
 *
 * The ADC will be immediately disabled. If an ADC conversion is in progress,
 * it will be aborted.
 *
 ******************************************************************************/
void ADC0_disable(void);

/// Positive input selection enums.
typedef enum {
    ADC0_POSITIVE_INPUT_P0, //!< ADC0P0 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P1, //!< ADC0P1 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P2, //!< ADC0P2 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P3, //!< ADC0P3 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P4, //!< ADC0P4 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P5, //!< ADC0P5 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P6, //!< ADC0P6 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P7, //!< ADC0P7 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P8, //!< ADC0P8 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P9, //!< ADC0P9 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P10, //!< ADC0P10 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P11, //!< ADC0P11 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P12, //!< ADC0P12 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P13, //!< ADC0P13 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P14, //!< ADC0P14 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P15, //!< ADC0P15 is ADC Positive Input
    ADC0_POSITIVE_INPUT_TEMP, //!< Internal Temperature Sensor is ADC Positive Input
    ADC0_POSITIVE_INPUT_LDO_OUT, //!< Internal 1.8 V LDO Output is ADC Positive Input
    ADC0_POSITIVE_INPUT_VDD, //!< VDD Supply Pin is ADC Positive Input
    ADC0_POSITIVE_INPUT_GND, //!< GND Supply Pin is ADC Positive Input
    ADC0_POSITIVE_INPUT_NONE = 31, //!< ADC Positive Input is disconnected
}ADC0_PositiveInput_t;

 /***************************************************************************//**
 * @brief
 * Select the positive input for the ADC.
 *
 * @param input:
 * The positive input selection.
 *
 ******************************************************************************/
void ADC0_setPositiveInput(ADC0_PositiveInput_t input);

 /***************************************************************************//**
 * @def void ADC0_selectNegativeInput(ADC0_NegativeInput_t input)
 * @warning NOT SUPPORTED ON THIS DEVICE
 ******************************************************************************/

 /***************************************************************************//**
 * @brief
 * Clears the conversion complete flag and manually initiates an ADC conversion.
 *
 * @note This function will start a conversion even if a non-manual conversion
 *      source is selected. The selected conversion source will still be able
 *      to trigger conversions.
 *
 ******************************************************************************/
void ADC0_startConversion(void);

 /***************************************************************************//**
 * @brief
 * Returns whether the ADC0 Conversion Complete flag is set.
 *
 * @return **true** if the ADC Conversion Complete flag is set, or **false** if
 * the flag is cleared.
 *
 * @note The conversion complete flag is also used as the conversion complete
 *      interrupt flag. Clearing this interrupt flag, **ADC0_CONVERSION_COMPLETE_IF**
 *      will cause the function to return **false**, even if a conversion has been 
 *      completed.
 *
 ******************************************************************************/
bool ADC0_isConversionComplete(void);

 /***************************************************************************//**
 * @brief
 * Read the result from the ADC.
 *
 * @return Result from the most recent conversion performed by the ADC.
 *
 * This reads from the ADC's result registers. If no conversion was performed
 * since the last call, the previous conversion will be returned.
 *
 ******************************************************************************/
uint16_t ADC0_getResult(void);

 /***************************************************************************//**
 * @brief
 * Set the window compare values.
 *
 * @param lessThan:
 * The value that the ADC result must be less than to trigger a Window
 * Compare event.
 *
 * @param greaterThan:
 * The value that the ADC result must be greater than to trigger a Window
 * Compare event.
 *
 * This function sets the greater-than and less-than values for the Window
 * Compare functionality of the ADC. When a conversion completes, if the
 * resulting value is greater than **greaterThan** or less than **lessThan**,
 * the Window Compare Interrupt flag found within @ref adc0_if "Interrupt Flag Enums" 
 * will be set. If Window Compare interrupts are enabled, a Window Compare
 * interrupt will be triggered.
 *
 ******************************************************************************/
void ADC0_setWindowCompare(uint16_t lessThan, uint16_t greaterThan);
/** @} (end adc0_runtime Runtime API) */

/** @} (end adc0_runtime ADC0 Runtime API) */
/** @} (end addtogroup adc_0 ADC0 Driver) */

#endif //__ADC_0_H__
