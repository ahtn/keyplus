/******************************************************************************
 * Copyright (c) 2016 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __UART_1_H__
#define __UART_1_H__


#include "efm8_config.h"
#include "SI_EFM8UB2_Register_Enums.h"

/**************************************************************************//**
 * @addtogroup uart_1 UART1 Driver
 * @{
 *
 * @brief Peripheral driver for uart1.
 *
 * # Introduction #
 *
 * This module contains all the driver content for UART1.
 *
 * ### Memory Usage ###
 *
 * The table below shows the memory consumption of the library with various
 * options. The 'default' entry shows the consumption when most or all available
 * functions are called. Typical consumption is expected to be less than this
 * since there are normally many uncalled functions that will consume no
 * resources.
 *
 * @note It is possible for memory usage to exceed the listed values in rare cases.
 *
 * | condition          | CODE | XRAM | IRAM | RAM |
 * |--------------------|------|------|------|-----|
 * |USE                 |  623 |   15 |    0 |  8  |
 * |STDIO               |  342 |    0 |    0 |  8  |
 *
 * # Theory of Operation #
 *
 * The UART1 driver provides several levels of functionality. Higher level
 * functionality is more user friendly but also less broadly applicable.
 *
 * ### Buffer Access API ###
 *
 * The driver provides high level functions for transferring a buffer of data.
 * This functionality is made available by setting EFM8PDL_UART1_USE_BUFFER
 * to 1.
 *
 * This functionality relies on the UART1 interrupt to function and the
 * library provides the ISR for that interrupt.
 *
 * For data transmission the user provides a data buffer and the length of that
 * buffer. The driver will then transmit the entire buffer before issuing an
 * end-of-transfer callback.
 *
 * In the following example we implement a ping-pong transmission.
 *
 * ~~~~~.c
 * SI_SEGMENT_VARIABLE(bufferA[32], uint8_t, SI_SEG_XDATA);
 * SI_SEGMENT_VARIABLE(bufferB[32], uint8_t, SI_SEG_XDATA);
 * SI_VARIABLE_SEGMENT_POINTER(curBuffer, uint8_t, SI_SEG_XDATA);
 * bool targetA;
 *
 * // Some other code pushes data to curBuffer and handles
 * // kicking the transfer with an initial call to initTxBuffer
 * // and txFifoIntEnable
 *
 * // When current transfer is complete send switch ping-pong
 * // and send all data accumulated in the other buffer.
 * // If no data is ready in other buffer we will write
 * void UART1_transmitCompleteCb()
 * {
 *   if(targetA)
 *   {
 *     //Don't transmit if no data is available
 *     if(curBuffer == bufferA)
 *     {
 *       //Some code to mark that the transfer is stalled
 *       return;
 *     }
 *
 *     //Send all data in A and start accumulating in B
 *     UART1_initTxBuffer(bufferA, curBuffer - bufferA);
 *     curBuffer = bufferB;
 *     targetA = false;
 *   }
 *   else
 *   {
 *     //Don't transmit if no data is available
 *     if(curBuffer == bufferA)
 *     {
 *       //Some code to mark that the transfer is stalled
 *       return;
 *     }
 *
 *     //Send all data in B and start accumulating in A
 *     UART1_initTxBuffer(bufferA, curBuffer - bufferA);
 *     curBuffer = bufferA;
 *     targetA = true;
 *   }
 * }
 * ~~~~~
 *
 * For reception the user provides a buffer and it's size. The library will
 * receive data into the buffer until it is full and then call the user
 * back. The user may query the number of bytes remaining in the buffer at
 * any time if they wish to process data before the buffer is full.
 *
 * This example provides ping-pong reception.
 *
 * ~~~~~.c
 * SI_SEGMENT_VARIABLE(bufferA[32], uint8_t, SI_SEG_XDATA);
 * SI_SEGMENT_VARIABLE(bufferB[32], uint8_t, SI_SEG_XDATA);
 * SI_VARIABLE_SEGMENT_POINTER(curBuffer, uint8_t, SI_SEG_XDATA);
 * SI_VARIABLE_SEGMENT_POINTER(dataReady, uint8_t, SI_SEG_XDATA);
 * bool targetA;
 *
 * //Here the main loop handles stuff
 * void main()
 * {
 *   //other initialization
 *   UART1_initRxBuffer(bufferA, 32);
 *   targetA = true;
 *
 *   while(1)
 *   {
 *     if(dataReady != NULL)
 *     {
 *       //process data
 *       dataReady = NULL;
 *     }
 *   }
 * }
 *
 * // When the current buffer is full inform the main loop it's
 * // ready for processing and switch to the other buffer.
 * void UART1_receiveCompleteCb()
 * {
 *   if(targetA)
 *   {
 *     dataReady = bufferA;
 *     UART1_initRxBuffer(bufferB, 32);
 *     targetA = false;
 *   }
 *   else
 *   {
 *     dataReady = bufferB;
 *     UART1_initRxBuffer(bufferA, 32);
 *     targetA = true;
 *   }
 * }
 * ~~~~~
 *
 * ### STDIO API ###
 * One of the simplest use cases is using UART 1 to stdio data. The driver
 * provides a standard blocking implementation accessed by setting
 * EFM8PDL_UART1_USE_STDIO.
 *
 * When this is in use no other functions are available.
 *
 *  When this is in use calls to printf will block until the entire string
 * has been transmitted on the uart.
 *
 * ### Runtime & Initialization API ###
 *
 * The final option is to use the Runtime and Initialization API to implement
 * a custom uart driver.
 *
 * The reference manual should be consulted for a full understanding of how
 * the block operates in order to use the Runtime API correctly.
 *
 * ### Hardware Configuration ###
 *
 * This Driver provides a basic level of configuration through the API. However
 * use of the Simplicity Hardware Configuration tool is highly recommended.
 *
 *****************************************************************************/

//Option macro documentation
/**************************************************************************//**
 * @addtogroup uart1_config Driver Configuration
 * @{
 *
 * @brief
 * Driver configuration constants read from efm8_config.h
 * 
 * This peripheral driver will look for configuration constants in 
 * **efm8_config.h**. This file is provided/written by the user and should be 
 * located in a directory that is part of the include path. 
 *  

 *****************************************************************************/
 
/**************************************************************************//**
 * @def EFM8PDL_UART1_USE_STDIO
 * @brief Controls the inclusion of putchar and setchar for use with printf/scanf.
 *
 * When '1' blocking implementations of putchar and set char are defined. This option
 * is intended to be use in place of all other options. If EFM8PDL_UART1_USE_STDIO
 * is '1' then EFM8PDL_UART1_USE should be 0 and the UART 0 peripheral driver should
 * not be called by the user directly accept for the initial setup.
 *
 * The putchar implementation provides an initialization function to prime the TX transfer
 * and configure the UART for receive and transmit. This function should be called immediately
 * after device configuration and before any printf or scanf calls.
 *
 * Default setting is '0' and may be overridden by defining in 'efm8_config.h'.
 *
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_UART1_USE_BUFFER
 * @brief Controls inclusion of UART1 Buffer Access API.
 *
 * When '1' the UART1 Buffered Access API is included in the driver.
 *
 * Default setting is '1' and may be overridden by defining in 'efm8_config.h'.
 *
 *****************************************************************************/

 /**************************************************************************//**
 * @def EFM8PDL_UART1_USE_ERR_CALLBACK
 * @brief Controls whether buffered API uses an error callback function.
 *
 * This option is only meaningful if @ref EFM8PDL_UART1_USE_BUFFER is enabled.
 * If this option is enabled, when an error is detected in the UART1 interrupt
 * handler, the callback function UART1_transferErrorCb() will be called.
 * If this option is not enabled, then the error callback will not be called
 * and it does not need to be provided by the application.
 *
 * If this feature is enabled along with @ref EFM8PDL_UART1_USE_BUFFER, when a
 * parity error is detected, the parity flag will be cleared and the user can
 * decide to discard or handle the oldest byte in the Fifo through the callback
 * function. If a receive Fifo overrun error is detected, the receive overrun
 * flag will be cleared and the user can handle the error accordingly through
 * the callback function as well.
 *
 * The default setting is '0' and may be overridden by defining the value
 * in 'efm8_config.h'.
 *****************************************************************************/

/**************************************************************************//**
 * @addtogroup uart1_config_buffered Buffered API Options
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_UART1_RX_BUFTYPE
 * @brief Controls the type of pointer used for buffered receives.
 *
 * Sets the memory segment for the rx data buffer pointer when EFM8PDL_UART1_USE_BUFFER is '1'
 * valid values are:
 *
 * - SI_SEG_XDATA (default)
 * - SI_SEG_PDATA
 * - SI_SEG_IDATA
 * - SI_SEG_CODE
 * - SI_SEG_GENERIC
 *
 * @warning
 * Use of generic pointers will adversely effect the size and performance
 * of the buffering functions.
 *
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_UART1_TX_BUFTYPE
 * @brief Controls the type of pointer used for buffered transmits.
 *
 * Sets the memory segment for the tx data buffer pointer when EFM8PDL_UART1_USE_BUFFER is '1'
 * valid values are:
 *
 * - SI_SEG_XDATA (default)
 * - SI_SEG_PDATA
 * - SI_SEG_IDATA
 * - SI_SEG_CODE
 * - SI_SEG_GENERIC
 *
 *****************************************************************************/

/**  @} (end addtogroup uart1_config_buffered Buffered API Options) */
/**  @} (end addtogroup uart1_config Driver Configuration) */

// Option macro default values
#ifndef IS_DOXYGEN
  #define IS_DOXYGEN 0
#endif

#ifndef EFM8PDL_UART1_USE_STDIO
#define EFM8PDL_UART1_USE_STDIO 0
#endif
#ifndef EFM8PDL_UART1_USE_BUFFER
  #if (!EFM8PDL_UART1_USE_STDIO)
    #define EFM8PDL_UART1_USE_BUFFER 1 //buffer mode by default
  #else
    #define EFM8PDL_UART1_USE_BUFFER 0
  #endif
#endif
#ifndef EFM8PDL_UART1_TX_BUFTYPE
#define EFM8PDL_UART1_TX_BUFTYPE SI_SEG_XDATA
#endif
#ifndef EFM8PDL_UART1_RX_BUFTYPE
#define EFM8PDL_UART1_RX_BUFTYPE SI_SEG_XDATA
#endif
#ifndef EFM8PDL_UART1_USE_ERR_CALLBACK
#define EFM8PDL_UART1_USE_ERR_CALLBACK 0
#endif

//=========================================================
// Runtime API
//=========================================================
/**************************************************************************//**
 * @addtogroup uart1_runtime UART1 Runtime API
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @addtogroup uart1_if Interrupt Flag Enums
 * @{
 *****************************************************************************/
#define UART1_TX_IF SCON1_TI__BMASK /**< UART1 TX Interrupt */
#define UART1_RX_IF SCON1_RI__BMASK /**< UART1 RX Interrupt  */
/**  @} (end addtogroup uart1_if Interrupt Flag Enums) */

/***************************************************************************//**
 * @brief
 * Return the value of the specified Interrupt Flag.
 *
 * @return
 * The state of the flags. This value is the OR of all flags which are set.
 *
 * ~~~~~.c
 * if(UART1_getIntFlags() & UART_TX_IF)
 * {
 *   //do something
 * }
 *
 * uint8_t value = UART1_getIntFlags();
 * if(value)
 * {
 *   //do some stuff that needs to be done for RX and TX
 *   if (value & UART_RX_IF)
 *   {
 *     //do stuff that only needs to be done for RX
 *   }
 * }
 * ~~~~~
 *
 * Valid flags can be found in the Interrupt Flag Enums group.
 *
 *****************************************************************************/
uint8_t UART1_getIntFlags(void);

 /***************************************************************************//**
  * @brief
  * Clear the specified Interrupt flag.
  *
  * @param flags:
  * Flags to clear. Multiple flags can be cleared by OR-ing the flags.
  *
  * Valid flags can be found in the Interrupt Flag Enums group.
  *
  * @note This function is implemented as a macro if EFM8PDL_UART1_AUTO_PAGE
  * is 0.
  *
  ******************************************************************************/
 void UART1_clearIntFlags(uint8_t flags);

/***************************************************************************//**
 * @brief
 * Sets the TX complete interrupt flag.
 *
 * It is common to operate the UART in polling mode where the procedure for
 * transmitting a byte is to block till TX is complete and then clear the flag
 * and write to SBUF. For these cases it is necessary to manually set the TX bit
 * to initialize the UART.
 *
 ******************************************************************************/
void UART1_initTxPolling(void);

/***************************************************************************//**
 * @brief
 * Write a byte without extra bit to the UART.
 *
 * @param value:
 * Data to be transmitted.
 *
 * If the UART already has data pending transmission it will be overwritten.
 *
 ******************************************************************************/
void UART1_write(uint8_t value);

/***************************************************************************//**
 * @brief
 * Read the last received byte without extra bit from UART.
 *
 * @return
 * The most recent byte read by the UART.
 *
 ******************************************************************************/
uint8_t UART1_read(void);

/***************************************************************************//**
 * @brief
 * Write a byte with an extra bit to the UART.
 *
 * @param value:
 * Data to be transmitted.
 *
 * The extra bit should be prepended to the data value.
 *
 * @note 
 * For example, the extra bit for a 5-bit data value should be bit 5,
 * the extra bit for a 6-bit data value should be bit 6, and so on.
 *
 ******************************************************************************/
void UART1_writeWithExtraBit(uint16_t value);

/***************************************************************************//**
 * @brief
 * Read the last received byte with extra bit from UART.
 *
 * @return
 * The data value received with extra bit value prepended.
 *
 * @note 
 * For example, the extra bit for a 5-bit data value should be bit 5,
 * the extra bit for a 6-bit data value should be bit 6, and so on.
 *
 ******************************************************************************/
uint16_t UART1_readWithExtraBit(void);

/**************************************************************************//**
 * @addtogroup uart1_ef Error Flag Enums
 * @{
 *****************************************************************************/
#define UART1_RXOVR_EF  SCON1_OVR__BMASK  /**< UART1 Receive Fifo Overrun Error*/
#define UART1_PARITY_EF SCON1_PERR__BMASK /**< UART1 Parity Error */
/**  @} (end addtogroup uart1_ef Error Flag Enums) */

 /***************************************************************************//**
 * @brief
 * Return the value of the specified Error flag.
 *
 * @param flag:
 * Flag to check. If OR'd together will return >0 if either flag is set.
 *
 * @return
 * The state of the flags. This value is the OR of all flags which are set.
 *
 * ~~~~~.c
 * uint8_t value = UART1_getErrFlags();
 * if(value)
 * {
 *   if (value & UART1_RXOVR_EF)
 *   {
 *     // do something to address receive fifo overrun error
 *   }
 *   if (value & UART1_PARITY_EF)
 *   {
 *     //do something to address parity error
 *   }
 * }
 * ~~~~~
 *
 * Valid flags can be found in the Error Flag Enums group.
 *
 *****************************************************************************/
uint8_t UART1_getErrFlags(void);

/***************************************************************************//**
 * @brief
 * Clear the specified Error flag.
 *
 * @param flags:
 * Flags to clear. Multiple flags can be cleared by OR-ing the flags.
 *
 * Valid flags can be found in the Error Flag Enums group.
 *
 ******************************************************************************/
void UART1_clearErrFlags(uint8_t flags);

/** @} (end addtogroup uart1_runtime UART1 Runtime API) */

//=========================================================
// Initialization API
//=========================================================
/***************************************************************************//**
 * @addtogroup uart1_init UART1 Initialization API
 * @{
 ******************************************************************************/

/// UART Data Length support enums.
typedef enum
{
  UART1_DATALEN_5 = SMOD1_SDL__5_BITS, //!< UART 5-bit Data Length.
  UART1_DATALEN_6 = SMOD1_SDL__6_BITS, //!< UART 6-bit Data Length.
  UART1_DATALEN_7 = SMOD1_SDL__7_BITS, //!< UART 7-bit Data Length.
  UART1_DATALEN_8 = SMOD1_SDL__8_BITS, //!< UART 8-bit Data Length.
} UART1_DataLen_t;

/// UART Stop Bit Length support enums.
typedef enum
{
  UART1_STOPLEN_SHORT = SMOD1_SBL__SHORT, //!< UART Short Stop Bit Length.
  UART1_STOPLEN_LONG  = SMOD1_SBL__LONG,  //!< UART Long Stop Bit Length.
} UART1_StopLen_t;

/// UART Feature Bit support enums.
typedef enum
{
  UART1_FEATURE_DISABLE  = SMOD1_PE__PARITY_DISABLED | SMOD1_XBE__DISABLED, //!< UART Feature Bit Disabled.
  UART1_FEATURE_PARITY   = SMOD1_PE__PARITY_ENABLED,                        //!< UART Parity Bit Enabled.
  UART1_FEATURE_EXTRABIT = SMOD1_XBE__ENABLED,                              //!< UART Extra Bit Enabled.
} UART1_FeatureBit_t;

/// UART Parity type support enums.
typedef enum
{
  UART1_PARITY_ODD   = SMOD1_SPT__ODD_PARITY,   //!< UART Odd Parity.
  UART1_PARITY_EVEN  = SMOD1_SPT__EVEN_PARITY,  //!< UART Even Parity.
  UART1_PARITY_MARK  = SMOD1_SPT__MARK_PARITY,  //!< UART Mark Parity.
  UART1_PARITY_SPACE = SMOD1_SPT__SPACE_PARITY, //!< UART Space Parity.
} UART1_ParityType_t;

/// UART RX Enable support enums.
typedef enum
{
  UART1_RX_ENABLE  = SCON0_REN__RECEIVE_ENABLED,   //!< UART Receive Enabled.
  UART1_RX_DISABLE = SCON0_REN__RECEIVE_DISABLED,  //!< UART Receive Disabled.
} UART1_RxEnable_t;

/// UART Multiprocessor Enable support enums.
typedef enum
{
  UART1_MULTIPROC_DISABLE = SMOD1_MCE__MULTI_DISABLED, //!< UART Multiprocessor communication Disabled.
  UART1_MULTIPROC_ENABLE  = SMOD1_MCE__MULTI_ENABLED,  //!< UART Multiprocessor communication Enabled.
} UART1_Multiproc_t;

/***************************************************************************//**
 * @brief
 * Initialize the UART.
 *
 * @param sysclk:
 * System clock frequency in Hz.
 * @param baudrate:
 * Desired baud rate in Hz.
 * @param datalen:
 * Data word length.
 * @param stoplen:
 * Stop bit length.
 * @param featbit:
 * Feature bit enable.
 * @param partype:
 * Parity type.
 * @param rxen:
 * Receive enable status.
 * @param mce:
 * Multiprocessor mode status.
 *
 * @note
 * For reliable UART reception, it is recommended that the baud rate should not
 * exceed sysclk / 16.
 * If parity is enabled, extra bit is disabled and vice versa. Parity type will
 * will be ignored if extra bit or feature bit disable is set.
 *
 * @warning
 * Baud rate cannot be greater than sysclk / 2. Initialization will stall if
 * user defined baud rate is too small to be matched.
 *
 ******************************************************************************/
void UART1_init(uint32_t sysclk, uint32_t baudrate, 
                UART1_DataLen_t datalen, UART1_StopLen_t stoplen, 
                UART1_FeatureBit_t featbit, UART1_ParityType_t partype,
                UART1_RxEnable_t rxen, UART1_Multiproc_t mcen);
                             
/***************************************************************************//**
 * @brief
 * Restore the UART to it's uninitialized (reset) state.
 *
 ******************************************************************************/
void UART1_reset(void);

/** @} (end uart1_init UART1 Initialization API) */

//=========================================================
// Buffer Access API
//=========================================================
/**************************************************************************//**
 * @addtogroup uart1_buffer UART1 Buffer Access API
 * @{
 *****************************************************************************/
#if (EFM8PDL_UART1_USE_BUFFER == 1) || IS_DOXYGEN               

/***************************************************************************//**
 * @brief
 * Transmit a buffer of data via UART.
 *
 * @param buffer:
 * Pointer to buffer of data to be transmitted.
 * @param length:
 * Number of bytes in transfer to be transmitted.
 *
 * @note
 * Buffer transfers support only 8-bit or fewer wide transfers. 
 * TFRQ interrupts are not enabled in initialization.
 *
 ******************************************************************************/
void UART1_writeBuffer(SI_VARIABLE_SEGMENT_POINTER(buffer,
                                                   uint8_t,
                                                   EFM8PDL_UART1_TX_BUFTYPE),
                                                   uint8_t length);
                                                
/***************************************************************************//**
 * @brief
 * Receive a buffer of data via UART.
 *
 * @param buffer:
 * Pointer to buffer of data to be received.
 * @param length:
 * Number of bytes in transfer to be received.
 *
 * Buffered transfers support only 8-bit or fewer words.
 *
 ******************************************************************************/
void UART1_readBuffer(SI_VARIABLE_SEGMENT_POINTER(buffer,
                                                  uint8_t,
                                                  EFM8PDL_UART1_RX_BUFTYPE),
                                                  uint8_t length);

/***************************************************************************//**
 * @brief
 * Abort current buffer transmission.
 *
 * Data already moved into the UART will finish transmission. No more
 * data will be pulled out of the TX buffer.
 *
 ******************************************************************************/
void UART1_abortTx(void);

/***************************************************************************//**
 * @brief 
 * Abort current buffer reception.
 *
 * No more data will be written to the RX buffer.
 *
 ******************************************************************************/
void UART1_abortRx(void);

/***************************************************************************//**
 * @brief
 * Return the number of bytes remaining in the TX buffer.
 *
 * @return
 * number of bytes remaining in TX buffer. 0 if no transfer is in progress.
 *
 * @returns 0 if transfer is not in progress.
 ******************************************************************************/
uint8_t UART1_txBytesRemaining(void);

/***************************************************************************//**
 * @brief
 * Return the number of bytes remaining in the RX buffer.
 *
 * @return
 * number of bytes remaining in RX buffer. 0 if no transfer is in progress.
 *
 ******************************************************************************/
uint8_t UART1_rxBytesRemaining(void);
/** @} (end uart1_buffer UART1 Buffer Access API) */

/**************************************************************************//**
 * @def void UART1_ISR()
 * @brief UART1 Interrupt handler.
 *
 * This callback is implemented inside the driver if EFM8PDL_UART1_USE_BUFFER is set
 * otherwise the user must implement the ISR.
 *
 *****************************************************************************/
#endif //EFM8PDL_UART1_USE_BUFFER

// Callbacks
/**************************************************************************//**
 * @addtogroup uart1_callbacks User Callbacks
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @addtogroup uart1_callbacks_buffer Buffer Access API
 * @{
 *
 * These callbacks will be called by the library when
 * EFM8PDL_UART1_USE_BUFFER. If the Buffered Access API is disabled
 * the callbacks do not need to be provided by the user.
 *
 *****************************************************************************/
#if (EFM8PDL_UART1_USE_BUFFER == 1) || IS_DOXYGEN

#if EFM8PDL_UART1_USE_ERR_CALLBACK == 1 || IS_DOXYGEN
/***************************************************************************//**
 * @brief
 * Callback for transfer errors.
 *
 * @param errFlags:
 * Bit mask of error flags
 *
 * This function is called when an error is detected during a buffer transfer interrupt.
 *
 * If there is a receive overrun, it probably means that the UART interrupt
 * was not serviced soon enough because the system interrupt latency is
 * too high.  
 *
 * @warning
 * This function is called from an ISR and should be as short as possible.
 *
 ******************************************************************************/
void UART1_transferErrorCb(uint8_t errFlags);
#endif // EFM8PDL_UART1_USE_ERR_CALLBACK

/***************************************************************************//**
 * @brief
 * Callback for reception of data.
 *
 * This function is called when all expected bytes have been received.
 *
 * @warning
 * This function is called from an ISR and should be as short as possible.
 *
 ******************************************************************************/
void UART1_receiveCompleteCb(void);

/***************************************************************************//**
 * @brief
 * Callback for transmission of a data.
 *
 * This function is called when all bytes in the buffer have been transferred.
 *
 * @warning
 * This function is called from an ISR and should be as short as possible.
 *
 ******************************************************************************/
void UART1_transmitCompleteCb(void);

#endif //EFM8PDL_UART1_USE_BUFFER
/** @} (end uart1_callbacks_buffer Buffer Access API) */
/** @} (end uart1_callbacks User Callbacks) */

//=========================================================
// STDIO API
//=========================================================
/**************************************************************************//**
 * @addtogroup uart1_stdio UART1 STDIO API
 * @{
 *
 * This API is intended to be used in place of all other uart driver
 * API's and will assume control of the uart.
 *
 * @warning
 * This implementation is blocking and may hang the MCU under certain
 * conditions.
 *
 ******************************************************************************/
#if (EFM8PDL_UART1_USE_STDIO == 1) || IS_DOXYGEN

/***************************************************************************//**
 * @brief
 * Initializes uart for STDIO operation.
 *
 * This function sets up the uart for use by printf/scanif. It must be called
 * once during device initialization **before** using STDIO.
 *
 ******************************************************************************/
void UART1_initStdio(uint32_t sysclk, uint32_t baudrate);

#endif //EFM8PDL_UART1_USE_STDIO
/** @} (end uart1_stdio UART1 STDIO API) */
/** @} (end uart_1 UART1 Driver) */
#endif //__UART_0_H__
