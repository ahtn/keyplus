/******************************************************************************
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __SPI_0_H__
#define __SPI_0_H__

#include "efm8_config.h"
#include "SI_EFM8BB3_Register_Enums.h"

/**************************************************************************//**
 *
 * @addtogroup spi_0_group SPI0 Driver
 * @{
 *
 * @brief Peripheral driver for SPI 0
 *
 * # Introduction #
 *
 * This module provides an API for using the SPI0 peripheral.  There is a
 * basic API to provide simple access to the SPI features, and a more advanced
 * buffered API that provides interrupt based transfers.  The user can also
 * choose to configure the SPI peripheral at run-time using the initialization
 * API or to bypass the initialization API and configure the peripheral during
 * a central system initialization function.
 *
 * ## Multibyte Transfers ##
 *
 * There are two methods of performing multibyte transfers, using a polling
 * (blocking) method or an interrupt (non-blocking) method.  The setup and
 * function call signature is the same for both.  In each case the caller
 * provides buffers for transmit and receive data.  The transmit data buffer
 * must be pre-filled with the data to be sent, while the receive buffer will
 * be filled with received data bytes.  The caller must provide pointers to
 * buffers of sufficient size to complete the transfer.
 *
 * If you want to only perform a transfer in one direction, then you can supply
 * a NULL pointer for the unused buffer.  For transmit-only transfers, all
 * received bytes are discarded.  For receive-only transfers, zero bytes will
 * be transmitted.
 *
 * For bidirectional transfers, the same number of bytes are transmitted and
 * received.  For a transfer where the number of transmitted and received bytes
 * are not the same, you must chain together transfers as needed to get the
 * number of bytes needed in each direction.
 *
 * ## Chip Select ##
 *
 * The SPI interface can be used in 3-wire or 4-wire mode.  If 3-wire mode
 * is used, then the SPI interface can be used with no chip select, or the
 * application can use a separate GPIO for the chip select.  For example, if
 * a SPI master needs to control several SPI slaves, then you would choose
 * 3-wire mode, and use a separate GPIO as the chip select for each SPI
 * slave.  In this case, the application must control the GPIO as chip select,
 * asserting it before starting a transfer and de-asserting when the transfer
 * is complete.
 *
 * If 4-wire mode is used, then the chip select is managed by the driver and
 * the peripheral.  When a SPI master, the chip select signal (NSS) will be
 * asserted automatically at the start of the transfer and de-asserted when
 * complete.  If a SPI slave, then the NSS signal is monitored and used to
 * gate SPI transfers.
 *
 *****************************************************************************/

// The following section is used to document configuration options

/**************************************************************************//**
 * @addtogroup spi0_config SPI Driver Configuration
 * @{
 *
 * @brief Driver configuration constants read from efm8_config.h
 *
 * This peripheral driver will look for configuration constants in
 * **efm8_config.h**. This file is provided/written by the user and should be
 * located in a directory that is part of the include path.
 *
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_SPI0_USE_BUFFER
 * @brief Controls inclusion of SPI0 Buffer Access API.
 *
 * The Buffer Access API includes code in the SPI driver to buffer incoming
 * and outgoing SPI data including an interrupt handler that makes callbacks.
 * When set to '1' the SPI0 Buffered Access API is included in the driver.
 *
 * @note When this feature is enabled, a SPI0 interrupt handler will be
 * included in the driver.  If you want to manage SPI interrupts with
 * application code, then this option should be disabled.
 *
 * The default setting is '0' and may be overridden by defining the value
 * in 'efm8_config.h'.
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_SPI0_USE_ERR_CALLBACK
 * @brief Controls whether buffered API uses an error callback function.
 *
 * This option is only meaningful if @ref EFM8PDL_SPI0_USE_BUFFER is enabled.
 * If this option is enabled, when an error is detected in the SPI interrupt
 * handler, the callback function SPI0_transferErrorCallback() will be called.
 * If this option is not enabled, then the error callback will not be called
 * and it does not need to be provided by the application.
 *
 * @note This feature is only useful if the SPI peripheral is to be used
 * in slave mode.
 *
 * The default setting is '0' and may be overridden by defining the value
 * in 'efm8_config.h'.
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_SPI0_USE_PIPELINE
 * @brief Controls buffered mode data pipelining.
 *
 * When using a buffered transfer with SPI0_transfer() the data can be
 * pipelined such that the driver attempts to keep the transmit buffer as
 * full as possible.  This will use the full bandwidth of the hardware
 * peripheral, but can cause data loss if system interrupt latency is too
 * high.  The SPI interrupt must be serviced within 2 byte-times or received
 * data can be lost.  If this feature is disabled, then writes and reads
 * will be matched to ensure that no receive data is lost.  However then
 * there can be irregular timing gaps between bytes and the full bandwidth
 * of the SPI bus is not used.
 *
 * @note This applies to master mode.  If you intend to use slave mode,
 * then this feature must be turned on.
 *
 * If you are using slave mode then this feature should be enabled.  If you
 * are only using master mode then you can leave this disabled if you are
 * concerned about interrupt latency in your system and SPI bus performance
 * is not important.  You can enable this if the interrupt latency in your
 * system is not too high, or if the SPI interrupt priority is set high
 * enough that it cannot miss SPI interrupts.
 *
 * The default setting is '0' and may be overridden by defining the value
 * in 'efm8_config.h'.
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_SPI0_AUTO_PAGE
 * @brief Provides automatic SFR paging and restoring.
 *
 * If this setting is '1' then the SPI driver will not assume the SFR page
 * and will explicitly set and restore the SFR page whenever it accesses
 * an SFR.  This will add more code and processing time to the SPI driver
 * functions.  If your code ensures that the SFRPAGE remains at 0 by default
 * whenever calling SPI functions, then this setting can be turned off which
 * will save code and improve performance.
 *
 * The default setting is '1' and may be overridden by defining the value
 * in 'efm8_config.h'.
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_SPI0_RX_SEGTYPE
 * @brief Controls the type of pointer used for receive buffers.
 *
 * Sets the memory segment type for the receive buffer pointer when using
 * SPI0_pollTransfer() or SPI0_transfer().  Valid values are:
 *
 * - SI_SEG_XDATA (default)
 * - SI_SEG_PDATA
 * - SI_SEG_IDATA
 * - SI_SEG_CODE
 * - SI_SEG_GENERIC
 *
 * @warning Use of generic pointers will increase the code size and reduce
 * performance of buffering functions.  The specific memory segment should
 * always be specified if possible.
 *****************************************************************************/

/**************************************************************************//**
 * @def EFM8PDL_SPI0_TX_SEGTYPE
 * @brief Controls the type of pointer used for transmit buffers.
 *
 * Sets the memory segment type for the transmit buffer pointer when using
 * SPI0_pollTransfer() or SPI0_transfer().  Valid values are:
 *
 * - SI_SEG_XDATA (default)
 * - SI_SEG_PDATA
 * - SI_SEG_IDATA
 * - SI_SEG_CODE
 * - SI_SEG_GENERIC
 *****************************************************************************/

/**  @} (end addtogroup spi0_config */

// Option macro default values

#ifdef IS_DOXYGEN
#define EFM8PDL_SPI0_USE_BUFFER 1
#define EFM8PDL_SPI0_AUTO_PAGE 1
#define EFM8PDL_SPI0_USE_ERR_CALLBACK 1
#endif

#ifndef EFM8PDL_SPI0_USE_BUFFER
#define EFM8PDL_SPI0_USE_BUFFER 0
#endif
#ifndef EFM8PDL_SPI0_TX_SEGTYPE
#define EFM8PDL_SPI0_TX_SEGTYPE SI_SEG_XDATA
#endif
#ifndef EFM8PDL_SPI0_RX_SEGTYPE
#define EFM8PDL_SPI0_RX_SEGTYPE SI_SEG_XDATA
#endif
#ifndef EFM8PDL_SPI0_AUTO_PAGE
#define EFM8PDL_SPI0_AUTO_PAGE 1
#endif
#ifndef EFM8PDL_SPI0_USE_PIPELINE
#define EFM8PDL_SPI0_USE_PIPELINE 0
#endif
#ifndef EFM8PDL_SPI0_USE_ERR_CALLBACK
#define EFM8PDL_SPI0_USE_ERR_CALLBACK 0
#endif

// Runtime API

/**************************************************************************//**
 * @addtogroup spi0_runtime SPI0 Runtime API
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @addtogroup spi0_if SPI Interrupt Flag Enums
 *
 * The following macros define the interrupt bits in the SPI interrupt flag
 * register.  These value are used with the functions SPI0_getIntFlags() and
 * SPI0_clearIntFlags().
 *
 * @{
 *****************************************************************************/

/// SPI interrupt flag.  This flag will be set when a transfer is complete.
#define SPI0_INT_IF SPI0CN0_SPIF__BMASK

/// Write collision interrupt flag.  This flag will be set when new data
/// is written before the prior transfer is complete.
#define SPI0_WCOL_IF SPI0CN0_WCOL__BMASK

/// Mode fault interrupt flag.  This flag will be set when the peripheral
/// is configured for master mode, but another SPI master tries to drive
/// the select (NSS) signal.
#define SPI0_MODF_IF SPI0CN0_MODF__BMASK

/// Receive overrun interrupt flag.  This flag is used only in slave mode
/// and indicates that a new byte was received before the prior received
/// byte was read from the receive buffer.
#define SPI0_RXOVR_IF SPI0CN0_RXOVRN__BMASK

/**  @} (end addtogroup spi0_if) */

/**************************************************************************//**
 * Return the value of the interrupt flags.
 *
 * @return The state of the interrupt flags register.  This will be non-zero
 * if any interrupt bits are set.
 *
 * This function returns the value of the SPI interrupt flags.  The returned
 * value can be tested against the [Interrupt flag enums](@ref spi0_if ) by
 * performing a logical AND of an enum value and the interrupt flags value.
 * It is possible that multiple flags can be set so all values should be
 * checked:
 *
 * ~~~~~~~~.c
 * uint8_t intFlags = SPI0_getIntFlags();
 *
 * if (intFlags & SPI0_INT_IF)
 * {
 *   // handle transfer complete interrupt
 * }
 * if (intFlags & SPI0_RXOVR_IF)
 * {
 *   // handle receive overflow
 * }
 *
 * // Clear interrupts
 * SPI0_clearIntFlags(intFlags);
 * ~~~~~~~~
 *
 * @note This function is implemented as a macro if EFM8PDL_SPI0_AUTO_PAGE
 * is 0.
 *****************************************************************************/
#if defined(IS_DOXYGEN) || (EFM8PDL_SPI0_AUTO_PAGE == 1)
extern uint8_t SPI0_getIntFlags(void);
#else
#define SPI0_getIntFlags(x) (SPI0CN0 & 0xF0)
#endif

/**************************************************************************//**
 * Clear interrupt flags.
 *
 * @param flags is the bitmask of all interrupt flags to clear
 *
 * This function will clear specific interrupt flags.  The _flags_ parameter
 * is a bit mask of all interrupt flags to clear.  It is the logical OR
 * of one or more [Interrupt flag enums](@ref spi0_if).
 *
 * @note This function is implemented as a macro if EFM8PDL_SPI0_AUTO_PAGE
 * is 0.
 *****************************************************************************/
#if defined(IS_DOXYGEN) || (EFM8PDL_SPI0_AUTO_PAGE == 1)
extern void SPI0_clearIntFlags(uint8_t flags);
#else
#define SPI0_clearIntFlags(flags)                                             \
            do {SPI0CN0 = (SPI0CN0 & (~flags | 0x0F));} while (0)
#endif

/**************************************************************************//**
 * Enable SPI interrupts.
 *
 * @note This function is implemented as a macro.
 *****************************************************************************/
#if defined(IS_DOXYGEN)
extern bool SPI0_enableInt(void);
#else
#define SPI0_enableInt(x) IE_ESPI0 = 1
#endif

/**************************************************************************//**
 * Disable SPI interrupts.
 *
 * @note This function is implemented as a macro.
 *****************************************************************************/
#if defined(IS_DOXYGEN)
extern bool SPI0_disableInt(void);
#else
#define SPI0_disableInt(x) IE_ESPI0 = 0
#endif

/**************************************************************************//**
 * Write a byte to the SPI transmit buffer.
 *
 * @param value Data byte to transmit
 * @return **True** if the byte was written, or **false** if the transmit
 * buffer was not empty.
 *
 * This function will write the byte to the SPI transmit register.  If the
 * transmit buffer is full then the write will fail and the function
 * will return **false**.  If SPI interrupts are enabled, then this will also
 * cause a "write collision" interrupt.
 *****************************************************************************/
extern bool SPI0_writeByte(uint8_t value);

/**************************************************************************//**
 * Write a byte to the SPI transmit buffer using polling.
 *
 * @param value Data byte to transmit
 *
 * This function will wait until the SPI transmit register is not full and then
 * write the value to the register.
 *****************************************************************************/
extern void SPI0_pollWriteByte(uint8_t value);

/**************************************************************************//**
 * Read the last received byte from the SPI receive buffer.
 *
 * @return The last byte received into the SPI receive buffer.
 *
 * This function will read and return the most recent byte from the SPI
 * receive buffer register.  If no new byte has been received since the last
 * read, then the same value is return again.
 *
 * @note This function is implemented as a macro if EFM8PDL_SPI0_AUTO_PAGE
 * is 0.
 *****************************************************************************/
#if defined(IS_DOXYGEN) || (EFM8PDL_SPI0_AUTO_PAGE == 1)
extern uint8_t SPI0_readByte(void);
#else
#define SPI0_readByte(x) (SPI0DAT)
#endif

/**************************************************************************//**
 * Read a byte from the SPI receive buffer using polling.
 *
 * This function will wait until the SPI receive register is not emptyand then
 * return the value from the register.
 *
 * @return The next available byte from the SPI receive buffer.
 *****************************************************************************/
extern uint8_t SPI0_pollReadByte(void);

/**************************************************************************//**
 * Define SPI transfer direction.  The direction can be RX-only, TX-only,
 * or RX/TX.
 *****************************************************************************/
typedef enum
{
  SPI0_TRANSFER_RX = 1,     /**< RX only */
  SPI0_TRANSFER_TX = 2,     /**< TX only */
  SPI0_TRANSFER_RXTX = 3,   /**< both directions */
} SPI0_TransferDirection_t;

/**************************************************************************//**
 * Perform multibyte SPI transfer using polling.
 *
 * @param pTxBuffer The buffer holding the data to transmit.
 * @param pRxBuffer The buffer to use for holding received data.
 * @param dir The direction of the transfer, RX, TX, or RXTX.
 * @param xferCount The number of bytes to transfer.
 *
 * This function is used to perform a SPI multibyte receive and/or transmit
 * operation.  It will block using polling until all the bytes have been
 * transferred.  The caller supplies transmit and receive buffers and a count
 * of the number of bytes to transfer.  The _xferCount_ must not be larger
 * than the space in either buffer.
 *
 * The _dir_ argument is used to specify the direction of the transfer.
 * If transfer is needed only in one direction, then the other buffer can
 * be **NULL**.  For example, to only transmit some bytes and not receive any,
 * the _dir_ argument should be SPI0_TRANSFER_TX, and the _pRxBuffer_
 * argument can be **NULL**.
 *
 * Because SPI always transfers in both directions, bytes will be transmitted
 * and received for all SPI transfers.  For a transmit-only operation,
 * _dir_ should be set to SPI0_TRANSFER_TX and _pRxBuffer_ can be set to
 * **NULL** and all bytes received from the interface will be discarded.
 * For a receive-only operation, _dir_ should be set to SPI0_TRANSFER_RX,
 * _pTxBuffer_ can be set to **NULL** and zeroes will be transmitted on the
 * SPI interface while all received bytes are stored.
 *
 * __Example__
 *
 * ~~~~~~~~.c
 * // Declare transmit and receive buffers in XDATA, each 16 bytes
 * SI_SEGMENT_VARIABLE(myTxBuf[16], uint8_t, SI_SEG_XDATA);
 * SI_SEGMENT_VARIABLE(myRxBuf[16], uint8_t, SI_SEG_XDATA);
 *
 * // Transfer 16 bytes in and out
 * SPI0_pollTransfer(myTxBuf, myRxBuf, SPI0_TRANSFER_RXTX, 16);
 *
 * // Receive 12 bytes, and send none
 * // (This will cause 12 zero bytes to be sent)
 * SPI0_pollTransfer(NULL, myRxBuf, SPI0_TRANSFER_RX, 12);
 * ~~~~~~~~
 *
 * @note The memory type of the TX and RX buffers much match the type
 * of the configuration macros @ref EFM8PDL_SPI0_TX_SEGTYPE and
 * @ref EFM8PDL_SPI0_RX_SEGTYPE.
 *
 * @note If using slave mode and non-zero is returned, there could still
 * be bytes remaining in the transmit buffer.  In this case you should
 * reset and re-init the SPI.
 *
 * @return The number of bytes remaining to transfer.  This should almost
 * always be 0, meaning that all the bytes have been transferred.  It could
 * be non-zero if the SPI is configured for 4-wire slave mode, and the
 * master de-asserted the chip select in the middle of a transfer.  In
 * this case the function will return with the number of bytes that were
 * not transferred.
 *****************************************************************************/
extern uint8_t
SPI0_pollTransfer(SI_VARIABLE_SEGMENT_POINTER(pTxBuffer, uint8_t, EFM8PDL_SPI0_TX_SEGTYPE),
                  SI_VARIABLE_SEGMENT_POINTER(pRxBuffer, uint8_t, EFM8PDL_SPI0_RX_SEGTYPE),
                  SPI0_TransferDirection_t dir, uint8_t xferCount);

/**************************************************************************//**
 * Check if SPI transmit register is full.
 *
 * @return __True__ if the SPI TX buffer is full and can not take another byte.
 *
 * @note This function is implemented as a macro if EFM8PDL_SPI0_AUTO_PAGE
 * is 0.
 *****************************************************************************/
#if defined(IS_DOXYGEN) || (EFM8PDL_SPI0_AUTO_PAGE == 1)
extern bool SPI0_isTxFull(void);
#else
#define SPI0_isTxFull(x) (!((bool)(SPI0CN0_TXNF)))
#endif

/**************************************************************************//**
 * Check if SPI is busy with a transfer.
 *
 * @return __True__ if a SPI transfer is in progress.
 *****************************************************************************/
extern bool SPI0_isBusy(void);

/**************************************************************************//**
 * Check if SPI slave is selected (assumes SPI is slave mode).
 *
 * @return __True__ if this SPI slave is selected.
 *
 * @note This function is only valid for SPI slave mode.
 * @note This function is implemented as a macro if EFM8PDL_SPI0_AUTO_PAGE
 * is 0.
 *****************************************************************************/
#if defined(IS_DOXYGEN) || (EFM8PDL_SPI0_AUTO_PAGE == 1)
extern bool SPI0_isSlaveSelected(void);
#else
#define SPI0_isSlaveSelected(x) ((bool)(SPI0CFG & 0x8))
#endif

/**************************************************************************//**
 * Check if SPI slave shift register is empty.
 *
 * @return __True__ if this SPI slave shift register is empty.
 *
 * @note This function is only valid for SPI slave mode.
 * @note This function is implemented as a macro if EFM8PDL_SPI0_AUTO_PAGE
 * is 0.
 *****************************************************************************/
#if defined(IS_DOXYGEN) || (EFM8PDL_SPI0_AUTO_PAGE == 1)
extern bool SPI0_isShiftEmpty(void);
#else
#define SPI0_isShiftEmpty(x) ((bool)(SPI0CFG & 0x2))
#endif

/**************************************************************************//**
 * Check if SPI receive buffer is empty.
 *
 * @return __True__ if this SPI RX buffer is empty.
 *
 * @note This function is implemented as a macro if EFM8PDL_SPI0_AUTO_PAGE
 * is 0.
 *****************************************************************************/
#if defined(IS_DOXYGEN) || (EFM8PDL_SPI0_AUTO_PAGE == 1)
extern bool SPI0_isRxEmpty(void);
#else
#define SPI0_isRxEmpty(x) ((bool)(SPI0CFG & 0x1))
#endif

/**  @} (end addtogroup spi0_runtime) */

/**************************************************************************//**
 * @addtogroup spi0_init SPI0 Initialization API
 *
 * The following functions are part of the SPI initialization API.  These
 * functions are used to configure the SPI peripheral at run-time.  It is
 * possible to also configure the SPI peripheral as part of system
 * initialization in which case it is not necessary to use these functions.
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * Define the SPI clocking mode.  There are 4 modes which define the SPI
 * clock polarity and phase.  The polarity refers to whether the clock is
 * resting low or high.  The phase refers to which edge is used to capture
 * the data, relative to the clock polarity.  The following table shows
 * the relation between the SPI mode and the clock polarity and phase.  The
 * EFM8 device data sheet has timing diagrams to show this in more detail.
 *
 * |Mode|Polarity|Phase|Description                                      |
 * |----|--------|-----|-------------------------------------------------|
 * | 0  |   0    |  0  |Clock normally low, data capture on rising edge  |
 * | 1  |   0    |  1  |Clock normally low, data capture on falling edge |
 * | 2  |   1    |  0  |Clock normally high, data capture on rising edge|
 * | 3  |   1    |  1  |Clock normally high, data capture on falling edge |
 *****************************************************************************/
typedef enum
{
  /// POL=0, PHA=0
  SPI0_CLKMODE_0 = SPI0CFG_CKPOL__IDLE_LOW | SPI0CFG_CKPHA__DATA_CENTERED_FIRST,
  /// POL=0, PHA=1
  SPI0_CLKMODE_1 = SPI0CFG_CKPOL__IDLE_LOW | SPI0CFG_CKPHA__DATA_CENTERED_SECOND,
  /// POL=1, PHA=0
  SPI0_CLKMODE_2 = SPI0CFG_CKPOL__IDLE_HIGH | SPI0CFG_CKPHA__DATA_CENTERED_FIRST,
  /// POL=1, PHA=1
  SPI0_CLKMODE_3 = SPI0CFG_CKPOL__IDLE_HIGH | SPI0CFG_CKPHA__DATA_CENTERED_SECOND
} SPI0_ClockMode_t;

/**************************************************************************//**
 * Initialize the SPI peripheral.
 *
 * @param clockMode Selects the phase and polarity of the SPI clock.
 * @param isMasterMode Select master mode (true=master, false=slave).
 * @param is4wire Select 4-wire mode (true=4-wire, false=3-wire)
 *
 * This function is used to initialize the SPI peripheral clock and interface
 * mode.  The SPI can be in master mode or slave mode, and can use the 3-wire
 * or 4-wire interface.
 *
 * **Master Mode**
 *
 * In master mode, this peripheral is the SPI master and will drive the SPI
 * clock, transmit data on the MOSI signal and receive data on the MISO signal.
 * In 4-wire mode, the chip select (NSS) signal will also be driven low at
 * the start of a transfer and high at the end of the transfer.  In 3-wire
 * mode, the NSS signal is not managed.  The SPI interface can either be used
 * without a chip select, or the chip select can be managed separately as a
 * GPIO pin.
 *
 * **Slave Mode**
 *
 * In slave mode, this peripheral is the SPI slave.  There must be an
 * external SPI device that is the SPI master and that drives the SPI
 * clock and the chip select (if used).  When in slave mode, this peripheral
 * receives data on MOSI and transmits data on MISO.  In 4-wire mode, SPI
 * data transfer is gated by the assertion of NSS by the external SPI master.
 * In 3-wire mode, the peripheral will perform transfers whenever the SPI
 * clock is active.
 *
 * **Clock Configuration**
 *
 * The _clockMode_ controls the polarity and phase of the SPI clock.  The
 * SPI master and SPI slave must use the same configuration.  See the
 * @ref SPI0_ClockMode_t for clock configuration choices.
 *
 * @note Be aware that changing between 4-wire and 3-wire mode will affect
 * the way pins are enabled in the crossbar.  Normally you should not change
 * modes at run-time.  You should set the mode at the beginning and leave
 * it that way.  Otherwise you will have pin IO functions shifting to
 * different pins every time you change between 4/3 wire mode.
 *****************************************************************************/
extern void SPI0_init(SPI0_ClockMode_t clockMode,
                      bool isMasterMode, bool is4wire);

/**************************************************************************//**
 * Reset SPI peripheral and disable interrupt.
 *
 * Disables the SPI peripheral and also disables all SPI interrupts.
 *
 * @note This function is implemented as a macro if EFM8PDL_SPI0_AUTO_PAGE
 * is 0.
 *****************************************************************************/
#if defined(IS_DOXYGEN) || (EFM8PDL_SPI0_AUTO_PAGE == 1)
extern void SPI0_reset(void);
#else
#define SPI0_reset(x) do{SPI0CN0 &= 0x0E; IE_ESPI0 = 0;}while(0)
#endif

/**************************************************************************//**
 * Set the SPI clock divider.
 *
 * @param divider The system clock divider to use for the SPI clock rate.
 *
 * The clock divider is divided into the system clock frequency to determine
 * the SPI clock rate.  The SPI clock rate is determined by the following
 * equation:
 *
 * `Fspi = SysClock / divider`
 *
 * The _divider_ parameter is constrained as follows:
 *
 * - range 2 - 512
 * - must be even number
 *
 * If the divider does not meet the above constraints, the nearest valid
 * value will be used.
 *****************************************************************************/
extern void SPI0_setClockDivider(uint16_t divider);

/** @} spi0_init */

/**************************************************************************//**
 * @addtogroup spi0_fifo SPI0 FIFO Control API
 *
 * The following functions are part of the SPI FIFO control API.  These
 * functions are used to configure the usage of the SPI transmit and receive
 * FIFOs and to check status of the FIFOs.
 *
 * The FIFO API functions are available when
 * @ref EFM8PDL_SPI0_USE_FIFO is set to 1 in 'efm8_config.h'.
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * Check FIFO transmit request flag.
 *
 * The FIFO transmit request flag will be set when the transmit FIFO level
 * is below the trigger threshold.  This indicates that more bytes can be
 * written to the transmit buffer using SPI0_writeByte() or
 * SPI0_pollWriteByte().
 *
 * @return __True__ if the FIFO transmit request flag is set.
 *****************************************************************************/
extern bool SPI0_isFifoTxReq(void);

/**************************************************************************//**
 * Check FIFO receive request flag.
 *
 * The FIFO receive request flag will be set when the receive FIFO level
 * is above the trigger threshold.  This indicates that more bytes can be
 * read from the receive buffer using SPI0_readByte() or SPI0_pollReadByte().
 *
 * @return __True__ if the FIFO receive request flag is set.
 *****************************************************************************/
extern bool SPI0_isFifoRxReq(void);

/**************************************************************************//**
 * Get number of bytes in the receive FIFO.
 *
 * @return Count of bytes in the receive FIFO.
 *****************************************************************************/
extern uint8_t SPI0_getRxFifoCount(void);

/**************************************************************************//**
 * Get number of bytes in the transmit FIFO.
 *
 * @return Count of bytes in the transmit FIFO.
 *****************************************************************************/
extern uint8_t SPI0_getTxFifoCount(void);

/**************************************************************************//**
 * Configure FIFO operating parameters.
 *
 * @param txThreshold count of bytes in TX FIFO to trigger a request (0-3)
 * @param rxThreshold count of bytes in RX FIFO to trigger a request (0-3)
 * @param rxTimeout number of SYSCLK*32 periods for receive timeout
 *
 * This function sets the FIFO transmit and receive request trigger thresholds
 * and also the receive timeout.  The threshold is the number of bytes in the
 * FIFO that will trigger a TX or RX request: see SPI0_isFifoTxReq() and
 * SPI0_isFifoRxReq().  The threshold can be a value from 0-3.  For the
 * transmit threshold, the request is triggered when the number of bytes in
 * the FIFO is less than or equal to the threshold.  For the receive threshold,
 * the request is triggered when the number of bytes in the FIFO is greater
 * than the threshold.  Please refer to the device Reference Manual for more
 * details about the FIFO and the request thresholds.
 *
 * The receive timeout can be used to ensure that a RX request will be
 * triggered even if the number of bytes in the receive FIFO is less than
 * the threshold.  This situation can arise if some bytes have been received
 * in the receive FIFO but not enough to trigger the request, and the SPI
 * master stops transferring any more data.  Without the timeout, the RX
 * request will never occur.  With a timeout, the RX request will occur after
 * the timeout elapses, even if master sends no more data.  This feature is
 * only useful in slave mode.
 *
 * If the timeout value is 0, then the timeout is disabled.  If the value
 * is a non-zero value, then the timeout period is the value of *rxTimeout*
 * times 32 SYSCLK cycles.  Please refer to the device Reference Manual for
 * more details about the receive timeout feature.
 *
 * @note The *rxTimeout* argument is ignored if the SPI peripheral is in
 * master mode.
 *****************************************************************************/
extern void SPI0_configureFifo(uint8_t txThreshold, uint8_t rxThreshold,
                               uint8_t rxTimeout);

/** @} spi0_fifo */

#if EFM8PDL_SPI0_USE_BUFFER == 1
/**************************************************************************//**
 * @addtogroup spi0_buffer SPI0 Buffered API
 *
 * The following functions are part of the SPI buffered API.  These functions
 * are used to perform buffered, interrupt driven transfers on the SPI bus.
 *
 * The buffered API functions are available when @ref EFM8PDL_SPI0_USE_BUFFER
 * is set to 1 in 'efm8_config.h'.
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * User callback for SPI transfer complete.
 *
 * This function is called when an interrupt-driven SPI transfer is complete.
 * The transfer must have been started using SPI0_transfer().
 *
 * @note This function is called in interrupt context.
 *****************************************************************************/
extern void SPI0_transferCompleteCb(void);

#if EFM8PDL_SPI0_USE_ERR_CALLBACK == 1
/**************************************************************************//**
 * User callback for SPI transfer errors.
 *
 * @param errFlags Bit mask of error flags.
 *
 * This function is called when an error occurs during an interrupt-driven
 * SPI transfer.  The transfer must have been started using SPI0_transfer().
 * The cause of the error can be determined from the _errFlags_ argument.
 * This is a bit mask and can be the logical OR of the following:
 *
 * - @ref SPI0_MODF_IF - master mode conflict with external SPI master
 * - @ref SPI0_RXOVR_IF - receive overrun
 *
 * If there is a receive overrun, it probably means that the SPI interrupt
 * was not serviced soon enough because the system interrupt latency is
 * too high.  The receive overrun condition is only detected in slave mode.
 *
 * This function will only be called if the option
 * @ref EFM8PDL_SPI0_USE_ERR_CALLBACK is set to 1 in 'efm8_config.h'.
 *
 * @note This function is called in interrupt context.
 *****************************************************************************/
extern void SPI0_transferErrorCb(uint8_t errFlags);
#endif // EFM8PDL_SPI0_USE_ERR_CALLBACK

/**************************************************************************//**
 * Perform interrupt-driven multibyte SPI transfer.
 *
 * @param pTxBuffer The buffer holding the data to transmit.
 * @param pRxBuffer The buffer to use for holding received data.
 * @param dir The direction of the transfer, RX, TX, or RXTX.
 * @param xferCount The number of bytes to transfer.
 *
 * This function is used to perform a SPI multibyte receive and/or transmit
 * operation.  The transfer will be started and this function will return
 * immediately.  The transfer will be carried out using interrupts and the
 * user callback function SPI0_transferCompleteCb() will be called when
 * all bytes have been transferred.
 *
 * The caller supplies transmit and receive buffers and a count of the number
 * of bytes to transfer.  The _xferCount_ must not be larger than the space
 * in either buffer.
 *
 * The _dir_ argument is used to specify the direction of the transfer.
 * If transfer is needed only in one direction, then the other buffer can
 * be **NULL**.  For example, to only transmit some bytes and not receive any,
 * the _dir_ argument should be SPI0_TRANSFER_TX, and the _pRxBuffer_
 * argument can be **NULL**.
 *
 * Because SPI always transfers in both directions, bytes will be transmitted
 * and received for all SPI transfers.  For a transmit-only operation,
 * _dir_ should be set to SPI0_TRANSFER_TX and _pRxBuffer_ can be set to
 * **NULL** and all bytes received from the interface will be discarded.
 * For a receive-only operation, _dir_ should be set to SPI0_TRANSFER_RX,
 * _pTxBuffer_ can be set to **NULL** and zeroes will be transmitted on the
 * SPI interface while all received bytes are stored.
 *
 * __Example__
 *
 * ~~~~~~~~.c
 * // Declare transmit and receive buffers in XDATA, each 16 bytes
 * SI_SEGMENT_VARIABLE(myTxBuf[16], uint8_t, SI_SEG_XDATA);
 * SI_SEGMENT_VARIABLE(myRxBuf[16], uint8_t, SI_SEG_XDATA);
 *
 * // Implement callback function
 * SPI0_transferCompleteCb(void)
 * {
 *   // set flag to indicate transfer is done
 *   // this function is called in interrupt context so
 *   // work should be minimized
 *   myTransferComplete = true;
 * }
 *
 * // Transfer 16 bytes in and out
 * SPI0_transfer(myTxBuf, myRxBuf, SPI0_TRANSFER_RXTX, 16);
 *
 * // Receive 12 bytes, and send none
 * // (This will cause 12 zero bytes to be sent)
 * SPI0_transfer(NULL, myRxBuf, SPI0_TRANSFER_RX, 12);
 * ~~~~~~~~
 *
 * @note The memory type of the TX and RX buffers much match the type
 * of the configuration macros @ref EFM8PDL_SPI0_TX_SEGTYPE and
 * @ref EFM8PDL_SPI0_RX_SEGTYPE.
 *****************************************************************************/
extern void
SPI0_transfer(SI_VARIABLE_SEGMENT_POINTER(pTxBuffer, uint8_t, EFM8PDL_SPI0_TX_SEGTYPE),
              SI_VARIABLE_SEGMENT_POINTER(pRxBuffer, uint8_t, EFM8PDL_SPI0_RX_SEGTYPE),
              SPI0_TransferDirection_t dir, uint8_t xferCount);

/**************************************************************************//**
 * Abort a buffered SPI transfer.
 *
 * Stop a buffered SPI transfer that is in progress.  No remaining bytes
 * will be transferred and the callback function will not be called.
 *****************************************************************************/
extern void SPI0_abortTransfer(void);

/**************************************************************************//**
 * Get the remaining bytes for a buffered transfer.
 *
 * @return The number of bytes remaining to transfer.
 *
 * When a transfer is started with SPI0_transfer(), this function can be
 * used to determine how many bytes are remaining to transfer.  This value
 * will be zero if the transfer is complete.
 *****************************************************************************/
extern uint8_t SPI0_bytesRemaining(void);

/** @} spi0_buffer */
#endif // EFM8PDL_SPI0_USE_BUFFER

/** @} (end spi_0_group) */

#endif // __SPI_0_H__
