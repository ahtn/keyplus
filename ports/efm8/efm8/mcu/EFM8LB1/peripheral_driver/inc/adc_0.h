/******************************************************************************
 * Copyright (c) 2014 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __ADC_0_H__
#define __ADC_0_H__
 
#include "efm8_config.h"
#include "SI_EFM8LB1_Register_Enums.h"


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
 * |Base          |                          |  93  |     0 |     0 |  0.2 |
 * |Init          |EFM8PDL_ADC0_USE_INIT     | +95  |     0 |     0 |   +7 |
 * |Autoscan      |EFM8PDL_ADC0_USE_AUTOSCAN | +113 |     0 |     0 |   +2 |
 * |Auto Page     |EFM8PDL_ADC0_AUTO_PAGE    | +105 |     0 |     0 |   +2 |
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
 
 /**************************************************************************//**
 * @addtogroup adc_0 ADC0 Driver
 * @{
 * ## Autoscan Mode ##
 * The ADC also has the ability to collect up to sixty-four samples total, across
 * up to four channels, into a buffer, without any CPU intervention. This can
 * be accomplished through the Autoscan API.
 *
 * In Autoscan mode, samples will be stored in consecutive spots within a buffer
 * in xdata space, and the conversion complete interrupt will now indicate that
 * the entire buffer is full, rather than just a single conversion has been completed. 
 *
 * When Autoscan mode is enabled, all settings for this mode are
 * loaded into internal registers, allowing the user to immediately set up the 
 * next Autoscan parameters. In continuous mode, the current user settings will be loaded
 * into the internal registers immediately upon the completion of a scan. In
 * single-scan mode, Autoscan is disabled upon completion of the initial scan.
 *
 * ### Polled Mode with Autoscan ###
 * This example shows how to perform a similar "Polled Mode" with Autoscan. However,
 * instead of only taking one sample from the ADC input, 64 samples are taken and
 * stored in a buffer declared **BUFFER**.
 *
 * @note This example uses a manual conversion source (ADC0_CONVERSION_START_ADBUSY),
 *      which relies on the user calling ADC0_startConversion(). However, other sources are
 *      available that do not require user intervention.
 *
 * @note This example also has autoscan configured so that one trigger will cause the
 *      ADC to take all samples within a scan. The ADC, by default, will require one
 *      trigger per conversion in a scan. For these configuration options, please see
 *      the Autoscan tab within the ADC peripheral in Hardware Configurator.
 *
 * ~~~~~.c
 * #define BUFFER_SIZE 64          // The size, in 14-bit samples, of the autoscan
 *                                 // buffer
 * 
 * // The starting address of autoscan buffer BUFFER in XDATA space.
 * // MUST START ON AN EVEN ADDRESS!
 * #define BUFFER_START_ADDR (0x0000)
 * 
 * // Define a new autoscan buffer array
 * ADC0_NEW_AUTOSCAN_BUFFER_ARRAY(BUFFER, BUFFER_SIZE, BUFFER_START_ADDR);
 * 
 * void main(void)
 * {
 *   uint8_t i;
 *
 *   // Initialization provided by Configurator
 *   enter_DefaultMode_from_RESET();
 * 
 *   // Scan one channel, ADC0_P0
 *   ADC0_setAutoscanInputs(ADC0_POSITIVE_INPUT_P0, 1);
 * 
 *   // Enable Autoscan to store 64 results in BUFFER[]
 *   ADC0_enableAutoscan(BUFFER, BUFFER_SIZE, ADC0_AUTOSCAN_MODE_CONTINUOUS);
 * 
 *   while (1)
 *   {
 *     ADC0_startConversion();
 *
 *     // Wait for conversion to complete 
 *     while(!ADC0_isConversionComplete());
 * 
 *     // Process the results
 *     for (i = 0; i < BUFFER_SIZE; i++)
 *     {
 *       printf("%d \n", BUFFER[i]);
 *     }
 *   }
 * }
 * ~~~~~
 *
 * ### Ping-Pong Mode with Autoscan ###
 * This example demonstrates the use of Autoscan to implement a ping-pong
 * buffer. **BUFFER1** is initially filled with samples, then the ADC is switched
 * to used **BUFFER2** while **BUFFER1**'s samples are being processed.
 *
 * @note This example has autoscan configured so that one trigger will cause the
 *      ADC to take all samples within a scan. The ADC, by default, will require one
 *      trigger per conversion in a scan. For these configuration options, please see
 *      the Autoscan tab within the ADC peripheral in Hardware Configurator.
 *
 * ~~~~~.c
 *  #define BUFFER_SIZE 64          // The size, in 14-bit samples, of the autoscan
 *                                 // buffers BUFFER1 and BUFFER2
 * 
 * // The starting address of autoscan buffer BUFFER1 in XDATA space.
 * // MUST END ON AN EVEN ADDRESS!
 * #define BUFFER1_START_ADDR (0x0000)
 * ADC0_NEW_AUTOSCAN_BUFFER_ARRAY(BUFFER1, BUFFER_SIZE, BUFFER1_START_ADDR);
 * 
 * // The starting address of autoscan buffer BUFFER2 in XDATA space. This is placed
 * // immediately after BUFFER1
 * #define BUFFER2_START_ADDR (BUFFER1_START_ADDR + sizeof(BUFFER1))
 * ADC0_NEW_AUTOSCAN_BUFFER_ARRAY(BUFFER2, BUFFER_SIZE, BUFFER2_START_ADDR);
 * 
 * ADC0_AutoscanBuffer_t * CURRENT_BUFFER;   // A pointer to an autoscan buffer
 * bool CONVERSION_COMPLETE = false;
 * 
 * void main(void)
 * {
 *   // Initialization provided by Configurator
 *   enter_DefaultMode_from_RESET();
 * 
 *   // Scan one channel, ADC0_P0
 *   ADC0_setAutoscanInputs(ADC0_POSITIVE_INPUT_P0, 1);
 *
 *   // Enable Autoscan to start sampling on BUFFER1
 *   CURRENT_BUFFER = BUFFER1;
 *   ADC0_enableAutoscan(CURRENT_BUFFER, BUFFER_SIZE, ADC0_AUTOSCAN_MODE_CONTINUOUS);
 *
 *   // Set BUFFER2 as the autoscan buffer following the completion of filling BUFFER1
 *   ADC0_setNextAutoscanBuffer(BUFFER2, BUFFER_SIZE);
 *
 *   // Enable conversion-complete interrupt 
 *   ADC0_enableInt(ADC0_CONVERSION_COMPLETE_IF, true);
 * 
 *   while (1)
 *   {
 *     // Manually start a conversion  
 *     ADC0_startConversion();
 * 
 *     // Idle the CPU until the next interrupt
 *     PCON0 |= PCON0_IDLE__IDLE;
 *   }
 * }
 *
 * SI_INTERRUPT (ADC0EOC_ISR, ADC0EOC_IRQn)
 * {
 *   uint8_t i;
 *   // Clear interrupt flag
 *   ADC0_clearIntFlags(ADC0_CONVERSION_COMPLETE_IF);
 * 
 *   // Swap current buffers
 *   if (CURRENT_BUFFER == BUFFER1)
 *   {
 *     CURRENT_BUFFER = BUFFER2;
 *   }
 *   else
 *   {
 *     CURRENT_BUFFER = BUFFER1;
 *   }
 * 
 *   // Set the next autoscan buffer to be the newly filled buffer
 *   // This will be used after the current scan is complete,
 *   // which will already have started with the other buffer
 *   ADC0_setNextAutoscanBuffer(CURRENT_BUFFER, BUFFER_SIZE);
 * 
 *   // Process the results
 *   for (i = 0; i < BUFFER_SIZE; i++)
 *   {
 *     printf("%d \n", CURRENT_BUFFER[i]);
 *   }
 * }
 * 
 * ~~~~~
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
 * @def EFM8PDL_ADC0_AUTO_PAGE
 * @brief Controls if the library handles SI_SFR paging.
 *
 * When '1' the ADC0 driver automatically handles setting and restoring
 * SI_SFR page for each call. When disabled the library consumes less code
 * space but the user must ensure that the correct page is set when calling
 * driver functions that access hardware.
 *
 * Default setting is '1' and may be overridden by defining in 'efm8_config.h'.
 *
 *****************************************************************************/
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
 
 /**************************************************************************//**
 * @def EFM8PDL_ADC0_USE_AUTOSCAN
 * @brief Controls inclusion of ADC0 Autoscan functions.
 *
 * When '1', all Autoscan functions are enabled and available for use.
 *
 * Default setting is '1' and may be overridden by defining in 'efm8_config.h'.
 *
 *****************************************************************************/
/**  @} (end addtogroup adc_config Driver Configuration) */

#ifndef IS_DOXYGEN
  #define IS_DOXYGEN 0
#endif

#ifndef EFM8PDL_ADC0_AUTO_PAGE
 #define EFM8PDL_ADC0_AUTO_PAGE 1
#endif

#ifndef EFM8PDL_ADC0_USE_INIT
 #define EFM8PDL_ADC0_USE_INIT 1
#endif

#ifndef EFM8PDL_ADC0_USE_AUTOSCAN
 #define EFM8PDL_ADC0_USE_AUTOSCAN 1
#endif

// Initialization API
/**************************************************************************//**
 * @addtogroup adc0_init ADC0 Initialization API
 * @{
 *****************************************************************************/
 
/// @brief Start of Conversion Source Enum.
typedef enum {
    ADC0_CONVERSION_START_MANUAL    = ADC0CN2_ADCM__ADBUSY, //!< Conversions are only started manually, with ADC0_startConversion()
    ADC0_CONVERSION_START_TIMER0    = ADC0CN2_ADCM__TIMER0, //!< Timer0 Overflow starts a conversion.
    ADC0_CONVERSION_START_TIMER2    = ADC0CN2_ADCM__TIMER2, //!< Timer2 Overflow starts a conversion.
    ADC0_CONVERSION_START_TIMER3    = ADC0CN2_ADCM__TIMER3, //!< Timer3 Overflow starts a conversion.
    ADC0_CONVERSION_START_CNVSTR    = ADC0CN2_ADCM__CNVSTR, //!< Rising edge of CNVSTR pin starts a conversion.
    ADC0_CONVERSION_START_CEX5      = ADC0CN2_ADCM__CEX5,   //!< Rising edge of PCA CEX5 starts a conversion.
    ADC0_CONVERSION_START_TIMER4    = ADC0CN2_ADCM__TIMER4, //!< Timer4 Overflow starts a conversion.
    ADC0_CONVERSION_START_TIMER5    = ADC0CN2_ADCM__TIMER5, //!< Timer5 Overflow starts a conversion.
    ADC0_CONVERSION_START_CLU0      = ADC0CN2_ADCM__CLU0,   //!< CLU0 Output starts a conversion.
    ADC0_CONVERSION_START_CLU1      = ADC0CN2_ADCM__CLU1,   //!< CLU1 Output starts a conversion.
    ADC0_CONVERSION_START_CLU2      = ADC0CN2_ADCM__CLU2,   //!< CLU2 Output starts a conversion.
    ADC0_CONVERSION_START_CLU3      = ADC0CN2_ADCM__CLU3,   //!< CLU3 Output starts a conversion.
}ADC0_ConversionStart_t ;

/// @brief ADC Resolution Enum.
typedef enum {
    ADC0_RESOLUTION_10_BIT = ADC0CN1_ADBITS__10_BIT, //!< Select 10-bit resolution.
    ADC0_RESOLUTION_12_BIT = ADC0CN1_ADBITS__12_BIT, //!< Select 12-bit resolution.
    ADC0_RESOLUTION_14_BIT = ADC0CN1_ADBITS__14_BIT, //!< Select 14-bit resolution.
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
    ADC0_POSITIVE_INPUT_P16, //!< ADC0P16 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P17, //!< ADC0P17 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P18, //!< ADC0P18 is ADC Positive Input
    ADC0_POSITIVE_INPUT_P19, //!< ADC0P19 is ADC Positive Input
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

 /***************************************************************************//**
 * @addtogroup adc0_autoscan_api Autoscan API
 * @{
 *
 * These functions are used in conjunction with the ADC's Autoscan feature.
 *
 * Autoscan allows the ADC to fill a buffer of up to 64 samples without CPU intervention.
 *
 *****************************************************************************/
 /***************************************************************************//**
 * @brief
 * Configures Autoscan inputs.
 *
 * @param startChannel:
 * The first input to be sampled from in Autoscan mode.
 * @param numChannels:
 * The number of consecutive inputs to sample in Autoscan mode.
 *
 * This function determines which ADC inputs will be sampled during an autoscan.
 * The scanner is capable of taking samples from up to four contiguous ADC
 * channels in sequence. **startChannel** will determine the first channel to
 * be converted, while **numChannels** will determine how many contiguous channels
 * from **startChannel** to sample.
 *
 ******************************************************************************/           
void ADC0_setAutoscanInputs(ADC0_PositiveInput_t startChannel,
                      uint8_t numChannels); //1-4
                      
/// ADC Autoscan Mode selection enums.
typedef enum {
    ADC0_AUTOSCAN_MODE_SINGLE, //!< The ADC will only perform one scan.
    ADC0_AUTOSCAN_MODE_CONTINUOUS, //!< The ADC will begin a new scan after each scan ends.
}ADC0_AutoscanMode_t;

/// ADC Autoscan Buffer type
#if IS_DOXYGEN == 1
typedef uint16_t xdata ADC0_AutoscanBuffer_t;
#else
typedef SI_SEGMENT_VARIABLE(ADC0_AutoscanBuffer_t, uint16_t, SI_SEG_XDATA);
#endif
/***************************************************************************//**
* @brief
* Create a buffer in the global scope to store autoscan results.
* @param name:
* The name of the variable.
* @param numElements:
* The size of the buffer / number of 16-bit samples the buffer can store, max 64.
* @param address:
* The address in xdata space where the buffer will start.
* @warning
* **address** must be even. Setting this value to an odd address will result in
* data actually being placed in the nearest even address, which can result in
* lost or corrupted data.
*
* This macro declares an autoscan buffer array of a given numElements in xdata space of
* type ADC0_AutoscanBuffer_t.
*
******************************************************************************/
#define ADC0_NEW_AUTOSCAN_BUFFER_ARRAY(name, numElements, address) SI_LOCATED_VARIABLE_NO_INIT(\
                                                              name[numElements],\
                                                              ADC0_AutoscanBuffer_t, ,\
                                                              address)

 /***************************************************************************//**
 * @brief
 * Initialize a scan operation to fill the given buffer, starting on the next
 * trigger.
 * @param buffer:
 * A pointer to the buffer where the scan results will be stored.
 * @param numElements:
 * The size of the buffer / number of 16-bit samples the buffer can store, max 64.
 * @param mode:
 * Perform a single scan, or start another scan at the end of each scan.
 *
 * This function enables and configures the first scan for Autoscan mode. If
 * mode is set to ADC_AUTOSCAN_SINGLE, a trigger will perform one scan, then
 * Autoscan mode will be disabled.
 *
 ******************************************************************************/
void ADC0_enableAutoscan(const ADC0_AutoscanBuffer_t * buffer,
                      uint8_t numElements, //Max 64
                      ADC0_AutoscanMode_t mode); 

/***************************************************************************//**
* @brief
* Get a pointer to the next buffer that will be used by Autoscan
*
* @return a pointer to the last buffer that was configured to be used by
*  Autoscan.
*
******************************************************************************/
const ADC0_AutoscanBuffer_t * ADC0_getNextAutoscanBuffer(void);

 /***************************************************************************//**
 * @brief
 * Configure the settings for the next Autoscan.
 * @param buffer:
 * A pointer to the xdata buffer where the scan results will be stored.
 * @param numElements:
 * The size of the buffer / number of 16-bit samples the buffer can store, max 64.
 *
 * This function configures where the next scan will store its samples. 
 * This scan will begin after the current scan has been completed, if Autoscan is
 * still enabled.
 *
 ******************************************************************************/
void ADC0_setNextAutoscanBuffer(const ADC0_AutoscanBuffer_t * buffer,
                      uint8_t numElements); //Max 64                      

 /***************************************************************************//**
 * @brief
 * Halts scan operations once any pending scan is complete.
 *
 ******************************************************************************/
void ADC0_disableAutoscan(void);

/** @} (end addtogroup adc0_autoscan_api Autoscan API) */
/** @} (end adc0_runtime ADC0 Runtime API) */
/** @} (end addtogroup adc_0 ADC0 Driver) */

#endif //__ADC_0_H__
