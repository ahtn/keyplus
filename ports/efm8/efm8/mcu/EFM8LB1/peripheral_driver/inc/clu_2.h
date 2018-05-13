/******************************************************************************
 * Copyright (c) 2014 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __CLU_2_H__
#define __CLU_2_H__

#include "efm8_config.h"
#include "SI_EFM8LB1_Register_Enums.h"

/**************************************************************************//**
 * @addtogroup clu_2 CLU2 Driver
 * @{
 *
 * @brief Peripheral driver for CLU2
 *
 * ## Introduction ##
 * The configurable logic (CL) module provides multiple blocks of 
 * user-programmed digital logic that operates without CPU intervention. It
 * consists of four dedicated independent configurable logic units (CLUs) which
 * support user programmable asynchronous and synchronous boolean logic 
 * operations. A number of internal and external signals may be used as inputs
 * to each CLU, and the outputs may be routed out to port I/O pins or directly
 * to select peripheral inputs.
 *
 * This peripheral driver allows for the configuration and runtime operation of
 * one of the four Configurable Logic Units, CLU2.
 *
 * ## Memory Usage ##
 *
 * The following table shows the approximate amount of memory used by this
 * module with various features enabled.  Typically, only a portion of the
 * module's API is used, so actual memory usage is expected to be less.
 *
 * |Config        |Macro                     | CODE | XDATA | IDATA | DATA |
 * |--------------|--------------------------|------|-------|-------|------|
 * |Base          |                          |  115 |     0 |     0 |   3  |
 * |Auto-page     |EFM8PDL_CLU2_AUTO_PAGE    |  +77 |    +0 |    +0 |  +0  |
 * |Use ISR       |EFM8PDL_CLU2_USE_ISR      |  +91 |    +0 |    +0 |  +1  |
 * |Default       |                          |  192 |     0 |     0 |   3  |
 *
 * ## Configuring the CLU ##
 * The CLU has three inputs, two of which are configurable: Input A and Input B.
 * Input C is always the output of the previous CLU or, in the case of the first
 * CLU, the output of the last CLU.
 *
 * Additionally, the CLU output can be routed either directly from the CLU's
 * Look-Up Table (LUT), or synchronized through a D Flip-Flop. The CLU
 * initialization function, CLU2_init(), allows for the configuration of
 * these options.
 *
 * ~~~~~.c
 * // Configure the CLU inputs as CLU1 output, PCA channel CEX0, and have the
 * // output be sourced directly from the LUT.
 * CLU2_init(CLU2_INPUT_A_CLU1_OUT, CLU2_INPUT_A_CEX0, CLU2_OUTPUT_MODE_LUT);
 *
 * // Configure the CLU inputs as P0.0 and P0.1, with the output synchronized
 * CLU2_init(CLU2_INPUT_A_P0_0, CLU2_INPUT_B_P0_1, CLU_OUTPUT_MODE_FLIPFLOP);
 * ~~~~~
 *
 * If using the Flip-Flop output, the function CLU2_initFlipflop() allows for
 * some additional configuration options: the clock which will clock the
 * Flip-flop, as well as whether the Flip-flop's output will be inverted.
 *
 * ~~~~~.c
 *  // Initialize the flip-flop to be clocked by SYSCLK, output not inverted
 *  CLU2_initFlipflop(CLU2_FLIPFLOP_CLOCK_SYSCLK, false);
 * ~~~~~
 *
 * ## Configuring the Output Function ##
 * The output of the CLU can be any boolean expression containing any
 * of the inputs. The @ref clu2_func "Output Function Macros" provide a
 * simplified way of generating the correct output function, while the
 * function CLU2_setOutputFunction() will take this function and apply
 * it to the CLU.
 *
 * ~~~~~.c
 * // Set the CLU output to equal A NOR B.
 * CLU2_setOutputFunction(CLU2_FUNCTION_NOR(CLU2_INPUT_A, CLU2_INPUT_B));
 * ~~~~~
 *
 * The CLU Output can also be set directly using the CLU2_Input_t input enums
 * with the corresponding bitwise (instead of logical) operators for the
 * desired output.
 *
 * ~~~~~.c
 * // Set the CLU output to equal A AND B.
 * CLU2_setOutputFunction(CLU2_INPUT_A & CLU2_INPUT_B);
 *
 * // Set the CLU output to equal (A OR B) XOR NOT C.
 * CLU2_setOutputFunction((CLU2_INPUT_A | CLU2_INPUT_B) ^ ~CLU2_INPUT_C);
 * ~~~~~
 * 
 * ## Utilizing the Output ##
 * The CLU's output can be used in many ways: it can be consumed by many other
 * peripherals, output to a pin (enabled by CLU2_enablePinOutput()), or used
 * to trigger an interrupt on a rising or falling edge. Additionally, the 
 * output value can be obtained directly using the CLU2_getOutput() function.
 *
 * Rising and Falling interrupts can be enabled by passing the appropriate flag
 * to the CLU2_enableInt() function. If **EFM8PDL_CLU2_USE_ISR** is defined as 1
 * within **efm8_config.h**, interrupts will be handled by the driver, calling the
 * respective callback ,CLU2_fallingEdgeCb() or CLU2_risingEdgeCb(), on a
 * falling edge or rising edge event.
 *
 * @note CLU2_enableInt() does not enable the combined CL interrupt or global
 * interrupts. These must be enabled manually.
 *
 * ## Example ##
 * This example uses the CLU to OR together the A and B inputs, P0.2 and
 * P0.3. The rising edge of the CLU output is then used to trigger an
 * interrupt, which turns on an LED. The falling edge is used to trigger
 * an interrupt to turn the LED off.
 *
 * ~~~~~.c
 * void main (void)
 * {
 *    // Enable global Configurable Logic interrupts
 *    // as well as global interrupt enable in Configurator
 *    enter_DefaultMode_from_RESET();
 * 
 *    // Init CLU2 with P0.2 as Input A, P0.3 as Input B. Output from Flip-Flop
 *    CLU2_init(CLU2_INPUT_A_P0_2, CLU2_INPUT_B_P0_3, CLU2_OUTPUT_MODE_FLIPFLOP);
 * 
 *    // Initialize the flip-flop to be clocked by SYSCLK
 *    CLU2_initFlipflop(CLU2_FLIPFLOP_CLOCK_SYSCLK, false);
 * 
 *    // Set output function to A OR B
 *    CLU2_setOutputFunction(CLU2_INPUT_A | CLU2_INPUT_B);
 * 
 *    // Enable CLU2 Rising-edge and Falling-edge interrupts.
 *    CLU2_enableInt(CLU2_RISING_EDGE_IF | CLU2_FALLING_EDGE_IF, true);
 * 
 *    while (1) {}
 * }
 * 
 * SI_SBIT(LED0, SFR_P1, 4);
 * #define LED_ON  0
 * #define LED_OFF 1
 *
 * void CLU2_fallingEdgeCb()
 * {
 *   LED0 = LED_OFF;
 * }
 * 
 * void CLU2_risingEdgeCb()
 * {
 *   LED0 = LED_ON;
 * }
 * ~~~~~
 *
 *
 *****************************************************************************/

 //Option macro documentation
/**************************************************************************//**
 * @addtogroup clu2_config Driver Configuration
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
 * @def EFM8PDL_CLU2_AUTO_PAGE
 * @brief Controls if the library handles SI_SFR paging.
 *
 * When '1' the CLU2 driver automatically handles setting and restoring
 * SI_SFR page for each call. When disabled the library consumes less code
 * space but the user must ensure that the correct page is set when calling
 * driver functions that access hardware.
 *
 * Default setting is '1' and may be overridden by defining in 'efm8_config.h'.
 *
 *****************************************************************************/

 /**************************************************************************//**
 * @def EFM8PDL_CLU2_USE_ISR
 * @brief Controls inclusion of CLU2 ISR and associated callbacks.
 *
 * When '1' the CL0 ISR in the driver is used and callbacks are functional.
 *
 * Default setting is '0' and may be overridden by defining in 'efm8_config.h'.
 *
 *****************************************************************************/
/**  @} (end addtogroup clu2_config Driver Configuration) */

#ifndef IS_DOXYGEN
  #define IS_DOXYGEN 0
#endif

#ifndef EFM8PDL_CLU2_AUTO_PAGE
 #define EFM8PDL_CLU2_AUTO_PAGE 1
#endif

#ifndef EFM8PDL_CLU2_USE_ISR
 #define EFM8PDL_CLU2_USE_ISR 0
#endif

// Initialization API
/**************************************************************************//**
 * @addtogroup clu2_init CLU2 Initialization API
 * @{
 *****************************************************************************/
typedef enum {
  CLU2_INPUT_A_CLU0_OUT = CLU2MX_MXA__CLU2A0,  //!< CLU Input A is the CLU2 output.
  CLU2_INPUT_A_CLU1_OUT = CLU2MX_MXA__CLU2A1,  //!< CLU Input A is the CLU1 output.
  CLU2_INPUT_A_CLU2_OUT = CLU2MX_MXA__CLU2A2,  //!< CLU Input A is the CLU2 output.
  CLU2_INPUT_A_CLU3_OUT = CLU2MX_MXA__CLU2A3,  //!< CLU Input A is the CLU3 output.
  CLU2_INPUT_A_TIMER4 = CLU2MX_MXA__CLU2A4,    //!< CLU Input A is Timer4 overflow.
  CLU2_INPUT_A_CEX1 = CLU2MX_MXA__CLU2A5,      //!< CLU Input A is PCA CEX1.
  CLU2_INPUT_A_CEX3 = CLU2MX_MXA__CLU2A6,      //!< CLU Input A is PCA CEX3.
  CLU2_INPUT_A_CEX5 = CLU2MX_MXA__CLU2A7,      //!< CLU Input A is PCA CEX5.
  CLU2_INPUT_A_P0_0 = CLU2MX_MXA__CLU2A8,      //!< CLU Input A is pin P0.0.
  CLU2_INPUT_A_P0_1 = CLU2MX_MXA__CLU2A9,      //!< CLU Input A is pin P0.1.
  CLU2_INPUT_A_P1_0 = CLU2MX_MXA__CLU2A10,      //!< CLU Input A is pin P1.0.
  CLU2_INPUT_A_P1_1 = CLU2MX_MXA__CLU2A11,      //!< CLU Input A is pin P1.1.
  CLU2_INPUT_A_P1_6 = CLU2MX_MXA__CLU2A12,      //!< CLU Input A is pin P1.6.
  CLU2_INPUT_A_P1_7 = CLU2MX_MXA__CLU2A13,      //!< CLU Input A is pin P1.7.
  CLU2_INPUT_A_P2_0 = CLU2MX_MXA__CLU2A14,      //!< CLU Input A is pin P2.0.
  CLU2_INPUT_A_P2_1 = CLU2MX_MXA__CLU2A15,      //!< CLU Input A is pin P2.1.
}CLU2_InputA_t;
/// @brief CLU Input B enums.
typedef enum {
  CLU2_INPUT_B_CLU0_OUT = CLU2MX_MXB__CLU2B0,  //!< CLU Input B is the CLU2 output.
  CLU2_INPUT_B_CLU1_OUT = CLU2MX_MXB__CLU2B1,  //!< CLU Input B is the CLU1 output.
  CLU2_INPUT_B_CLU2_OUT = CLU2MX_MXB__CLU2B2,  //!< CLU Input B is the CLU2 output.
  CLU2_INPUT_B_CLU3_OUT = CLU2MX_MXB__CLU2B3,  //!< CLU Input B is the CLU3 output.
  CLU2_INPUT_B_ADBUSY = CLU2MX_MXB__CLU2B4,    //!< CLU Input B is the ADC's ADBUSY flag.
  CLU2_INPUT_B_CEX0 = CLU2MX_MXB__CLU2B5,      //!< CLU Input B is PCA CEX0.
  CLU2_INPUT_B_CEX2 = CLU2MX_MXB__CLU2B6,      //!< CLU Input B is PCA CEX2.
  CLU2_INPUT_B_CEX4 = CLU2MX_MXB__CLU2B7,      //!< CLU Input B is PCA CEX4.
  CLU2_INPUT_B_P0_2 = CLU2MX_MXB__CLU2B8,      //!< CLU Input B is pin P0.2.
  CLU2_INPUT_B_P0_3 = CLU2MX_MXB__CLU2B9,      //!< CLU Input B is pin P0.3.
  CLU2_INPUT_B_P1_2 = CLU2MX_MXB__CLU2B10,      //!< CLU Input B is pin P1.2.
  CLU2_INPUT_B_P1_3 = CLU2MX_MXB__CLU2B11,      //!< CLU Input B is pin P1.3.
  CLU2_INPUT_B_P1_4 = CLU2MX_MXB__CLU2B12,      //!< CLU Input B is pin P1.4.
  CLU2_INPUT_B_P1_5 = CLU2MX_MXB__CLU2B13,      //!< CLU Input B is pin P1.5.
  CLU2_INPUT_B_P2_2 = CLU2MX_MXB__CLU2B14,      //!< CLU Input B is pin P2.2.
  CLU2_INPUT_B_P2_3 = CLU2MX_MXB__CLU2B15,      //!< CLU Input B is pin P2.3.
}CLU2_InputB_t;

/// @brief CLU Input C enums.
typedef enum {
  CLU2_INPUT_C_CLU3_OUT,    //!< CLU Input C is the CLU3 output.
}CLU2_InputC_t;

/// @brief CLU Output mode enums.
typedef enum {
  CLU2_OUTPUT_MODE_LUT = CLU2CF_OUTSEL__LUT,      //!< CLU Output is directly from the LUT.
  CLU2_OUTPUT_MODE_FLIPFLOP = CLU2CF_OUTSEL__D_FF, //!< CLU Output passes through a D Flip-flop.
}CLU2_OutputMode_t;

/***************************************************************************//**
* @brief
* Initialize the CLU.
*
* @param inputA:
* The A input to the CLU.
* @param inputB:
* The B input to the CLU.
* @param mode:
* The output mode of the CLU - direct from the LUT or through a D flip-flop.
*
* This is a basic initialization function that configures the CLU inputs and
* output mode, then enables the CLU.
*
* The CLU's output function is not initialized, and must be changed with
* CLU2_setOutputFunction().
*
* The initialization API provides only the most basic and common configuration
* options. To access more advanced options, or to generate more efficient
* initialization code, please use the Hardware Configuration tool.
*
******************************************************************************/

// Three functions, instead?
//void CLU2_setInputA(CLU2_InputA_t input);
//void CLU2_setInputB(CLU2_InputB_t input);
//void CLU2_setOutputMode(CLU2_OutputMode_t mode);

void CLU2_init(CLU2_InputA_t inputA,
               CLU2_InputB_t inputB,
               CLU2_OutputMode_t mode);

/// @brief D Flip-flop clocking enums.
typedef enum {
  CLU2_FLIPFLOP_CLOCK_CARRY_IN = CLU2CF_CLKSEL__CARRY_IN,       //!< The D Flip-flop clock is the Carry-in (Input C).
  CLU2_FLIPFLOP_CLOCK_A_INPUT = CLU2CF_CLKSEL__MXA_INPUT,        //!< The D Flip-flop clock is Input A.
  CLU2_FLIPFLOP_CLOCK_SYSCLK = CLU2CF_CLKSEL__SYSCLK,         //!< The D Flip-flop clock is Sysclk.
  CLU2_FLIPFLOP_CLOCK_TIMER1 = CLU2CF_CLKSEL__ALTCLK,         //!< The D Flip-flop clock is Timer 1 overflow.
}CLU2_FlipflopClock_t;
/***************************************************************************//**
* @brief
* Initialize the CLU's D Flip-flop.
*
* @param clock:
* The flip-flop clock.
* @param clockInvert:
* Sets whether the clock is inverted.
*
* This is a basic initialization function that configures the CLU's D flip-flop.
*
* @note If the CLU is configured to output directly from its LUT, these settings
* will have no effect.
*
******************************************************************************/
void CLU2_initFlipflop(CLU2_FlipflopClock_t clock, bool clockInvert);


/// @brief Input Enums to be passed to the Output Function Macros.
typedef enum {
  CLU2_INPUT_A = 0xF0, //!< CLU2 Input A
  CLU2_INPUT_B = 0xCC, //!< CLU2 Input B
  CLU2_INPUT_C = 0xAA, //!< CLU2 Input C
}CLU2_Input_t;

typedef uint8_t CLU2_Function_t;
/**************************************************************************//**
* @addtogroup clu2_func Output Function Macros
*
* These macros take CLU inputs of type CLU2_Input_t and generate the appropriate
* function of type CLU2_Function_t for CLU2_setOutputFunction(). These macros
* can be nested for more advanced logical functions.
*
* @note These functions are implemented as macros.
* @{
******************************************************************************/
#if IS_DOXYGEN
/// @brief Returns the logical NOT output function for the given input.
CLU2_Function_t CLU2_FUNCTION_NOT(CLU2_Input_t x);
/// @brief Returns the logical AND output function for the given inputs.
CLU2_Function_t CLU2_FUNCTION_AND(CLU2_Input_t x, CLU2_Input_t y);
/// @brief Returns the logical OR output function for the given inputs.
CLU2_Function_t CLU2_FUNCTION_OR(CLU2_Input_t x, CLU2_Input_t y);
/// @brief Returns the logical NOR output function for the given inputs.
CLU2_Function_t CLU2_FUNCTION_NOR(CLU2_Input_t x, CLU2_Input_t y);
/// @brief Returns the logical NAND output function for the given inputs.
CLU2_Function_t CLU2_FUNCTION_NAND(CLU2_Input_t x, CLU2_Input_t y);
/// @brief Returns the logical XOR output function for the given inputs.
CLU2_Function_t CLU2_FUNCTION_XOR(CLU2_Input_t x, CLU2_Input_t y);
/// @brief Returns the logical XNOR output function for the given inputs.
CLU2_Function_t CLU2_FUNCTION_XNOR(CLU2_Input_t x, CLU2_Input_t y);
/***************************************************************************//**
 * @brief
 * Returns an output function that outputs one of two given inputs based on a select input.
 *
 * @param x:
 * The input selected when **sel** is high.
 * @param y:
 * The input selected when **sel** is low.
 * @param sel:
 * The input that selects between **x** and **y** inputs.
 *
 ******************************************************************************/
CLU2_Function_t CLU2_FUNCTION_SELECT(CLU2_Input_t x, CLU2_Input_t y, CLU2_Input_t sel);
#else
#define CLU2_FUNCTION_NOT(CLU2_Input_x)                 ~(CLU2_Input_x)
#define CLU2_FUNCTION_AND(CLU2_Input_x, CLU2_Input_y)    ((CLU2_Input_x)&(CLU2_Input_y))
#define CLU2_FUNCTION_OR(CLU2_Input_x, CLU2_Input_y)     ((CLU2_Input_x)|(CLU2_Input_y))
#define CLU2_FUNCTION_NOR(CLU2_Input_x, CLU2_Input_y)    ~(CLU2_FUNCTION_OR(CLU2_Input_x,CLU2_Input_y))
#define CLU2_FUNCTION_NAND(CLU2_Input_x, CLU2_Input_y)   ~(CLU2_FUNCTION_AND(CLU2_Input_x,CLU2_Input_y))
#define CLU2_FUNCTION_XOR(CLU2_Input_x, CLU2_Input_y)    (CLU2_FUNCTION_AND(CLU2_FUNCTION_OR(CLU2_Input_x,CLU2_Input_y),~CLU2_FUNCTION_AND(CLU2_Input_x,CLU2_Input_y)))
#define CLU2_FUNCTION_XNOR(CLU2_Input_x, CLU2_Input_y)   ~(CLU2_FUNCTION_XOR(CLU2_Input_x,CLU2_Input_y))
#define CLU2_FUNCTION_SELECT(CLU2_Input_x, CLU2_Input_y, CLU2_Input_sel)     (CLU2_FUNCTION_OR(CLU2_FUNCTION_AND(CLU2_Input_x,CLU2_Input_sel),CLU2_FUNCTION_AND(CLU2_Input_y,~(CLU2_Input_sel))))
#endif
/** @} (end addtogroup clu2_func Output Function Macros) */

/***************************************************************************//**
 * @brief
 * Sets the output function of the CLU's LUT
 *
 * @param function:
 * The desired output function.
 *
 * This function determines the output of the CLU based on the inputs. Valid
 * inputs include any of the @ref clu2_func "Output Function Macros", or any custom 8-bit
 * function output. The bits of the variable **function** correspond to
 * the CLU's LUT output. The truth-table for this output is as follows:
 *
 * | A input | B input | C input | LUT Output  |
 * |---------|---------|---------|-------------|
 * |    0    |    0    |    0    |  function.0 |
 * |    0    |    0    |    1    |  function.1 |
 * |    0    |    1    |    0    |  function.2 |
 * |    0    |    1    |    1    |  function.3 |
 * |    1    |    0    |    0    |  function.4 |
 * |    1    |    0    |    1    |  function.5 |
 * |    1    |    1    |    0    |  function.6 |
 * |    1    |    1    |    1    |  function.7 |
 *
 ******************************************************************************/
void CLU2_setOutputFunction(CLU2_Function_t function);
/** @} (end clu2_init CLU2 Initialization API) */

// Runtime API
/**************************************************************************//**
 * @addtogroup clu2_runtime CLU2 Runtime API
 * @{
 *****************************************************************************/
 /**************************************************************************//**
 * @addtogroup clu2_if Interrupt Flag Enums
 * @{
 ******************************************************************************/
#define CLU2_FALLING_EDGE_IF  CLIF0_C2FIF__BMASK    //!<  Rising Edge flag
#define CLU2_RISING_EDGE_IF CLIF0_C2RIF__BMASK //!<  Falling Edge flag

/** @} (end addtogroup clu2_if Interrupt Flag Enums) */
/***************************************************************************//**
 * @brief
 * Return the value of the interrupt flags
 *
 * @return
 * The state of the Interrupt flags. This value is the logical OR of any of the
 * following  flags found within @ref clu2_if "Interrupt Flag Enums":
 *  - \b CLU2_FALLING_EDGE_IF - Interrupt flag set when the output of the CLU
 *    changes from high to low.
 *  - \b CLU2_RISING_EDGE_IF - Interrupt flag set when the output of the CLU
 *    changes from low to high.
 *
 ******************************************************************************/
uint8_t CLU2_getIntFlags(void);

/***************************************************************************//**
 * @brief
 * Clear the specified interrupt flags.
 *
 * @param flags:
 * A bit mask of interrupt flags to be cleared. This value is the logical OR
 * of any of the following flags found within @ref clu2_if "Interrupt Flag Enums":
 *  - \b CLU2_FALLING_EDGE_IF - Interrupt flag set when the output of the CLU
 *    changes from high to low.
 *  - \b CLU2_RISING_EDGE_IF - Interrupt flag set when the output of the CLU
 *    changes from low to high.
 *
 ******************************************************************************/
void CLU2_clearIntFlags(uint8_t flags);

/***************************************************************************//**
 * @brief
 * Enable or disable the CLU interrupts
 *
 * @param flags:
 * A bit mask of interrupts to be enabled or disabled. This value is the logical OR
 * of any of the following flags found within @ref clu2_if "Interrupt Flag Enums":
 *  - \b CLU2_FALLING_EDGE_IF - Interrupt flag set when the output of the CLU
 *    changes from high to low.
 *  - \b CLU2_RISING_EDGE_IF - Interrupt flag set when the output of the CLU
 *    changes from low to high.
 *
 * @param enable:
 * New interrupt status (**true** to enable, **false** to disable)
 *
 ******************************************************************************/
void CLU2_enableInt(uint8_t flags, bool enable);

/***************************************************************************//**
* @brief
* Enable the CLU
*
* The CLU will be enabled, allowing the CLU output to change based on the
* CLU inputs.
*
******************************************************************************/
void CLU2_enable(void);

/***************************************************************************//**
* @brief
* Disable the CLU
*
* The CLU will be disabled. The CLU output will be set to zero.
*
******************************************************************************/
void CLU2_disable(void);

/***************************************************************************//**
* @brief
* Enable the CLU output pin.
*
* The CLU's output pin will be enabled and will be driven to the logic level
* of the CLU output.
*
******************************************************************************/
void CLU2_enablePinOutput(void);

/***************************************************************************//**
* @brief
* Disable the CLU output pin.
*
* The CLU's output pin will be disabled.
*
******************************************************************************/
void CLU2_disablePinOutput(void);

/***************************************************************************//**
* @brief
* Get the current CLU output value
*
* @return The value of the CLU output, *true* or *false*.
*
******************************************************************************/
bool CLU2_getOutput(void);

/** @} (end clu2_runtime CLU2 Runtime API) */
//=========================================================
// ISR API
//=========================================================
#if (EFM8PDL_CLU2_USE_ISR == 1) || IS_DOXYGEN
/**************************************************************************//**
 * @def void CLU2_ISR()
 * @brief CLU Interrupt handler (not a callback).
 *
 * This ISR is provided by the library when EFM8PDL_CLU2_USE_ISR = "1".
 *
 *****************************************************************************/
#endif //EFM8PDL_CLU2_USE_ISR

// Callbacks
/**************************************************************************//**
 * @addtogroup clu2_callback User Callbacks
 * @{
 *****************************************************************************/
#if (EFM8PDL_CLU2_USE_ISR == 1) || IS_DOXYGEN

/***************************************************************************//**
 * @addtogroup clu2_callbacks_isr ISR API
 * @{
 *
 * These callbacks will be called by the library when
 * EFM8PDL_CLU2_USE_ISR. If the ISR Api is disabled
 * the callbacks do not need to be provided by the user.
 *
 ******************************************************************************/

/***************************************************************************//**
 * @brief
 * Callback for CLU Falling Edge interrupt.
 *
 * This function is defined by the user and called by the peripheral driver when
 * the CLU output transitions from high to low.
 *
 * @warning
 * This function is called from an ISR and should be as short as possible.
 *
 ******************************************************************************/
extern void CLU2_fallingEdgeCb();

/***************************************************************************//**
 * @brief
 * Callback for CLU Rising Edge interrupt.
 *
 * This function is defined by the user and called by the peripheral driver when
 * the CLU output transitions from low to high.
 *
 * @warning
 * This function is called from an ISR and should be as short as possible.
 *
 ******************************************************************************/
extern void CLU2_risingEdgeCb();

#endif //EFM8PDL_CLU2_USE_ISR
/**  @} (end addtogroup clu2_callbacks_isr ISR API) */
/**  @} (end addtogroup clu2_callback User Callbacks) */

/** @} (end addtogroup clu_2 CLU2 Driver) */

#endif //__CLU_2_H__
