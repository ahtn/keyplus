/**************************************************************************//**
 * Copyright (c) 2016 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "uart_1.h"

// Clock prescaler values for baud rate initialization
#define NUM_PRESC 4
static const uint8_t PRESC[NUM_PRESC]      = {1, 4, 12, 48};
static const uint8_t PRESC_ENUM[NUM_PRESC] = {SBCON1_BPS__DIV_BY_1,  SBCON1_BPS__DIV_BY_4, SBCON1_BPS__DIV_BY_12, SBCON1_BPS__DIV_BY_48};
static void UART1_initBaudRate(uint32_t sysclk, uint32_t baudrate)
{
  uint8_t i;
  uint8_t min_presc;
  uint16_t reload;

  // Calculate baud rate prescaler and baud rate reload
  // value to maximize precision.
  // See reference manual for calculation details
  min_presc = ((*((uint16_t*)(&sysclk)) >> 1) + baudrate) / baudrate; // calculate minimum prescaler necessary
  for(i = 0; i < NUM_PRESC; ++i)
  {
    if(PRESC[i] >= min_presc) // use a prescaler that is equal or just greater than the minimum
    {
      reload =  ((1 << 16) - (sysclk / (2 * baudrate * PRESC[i]))); // calculate reload value using prescaler
      SBRL1  = reload;
      SBCON1 |= (SBCON1_BREN__ENABLED | PRESC_ENUM[i]); // enable baud rate with calculated prescaler
      return;
    }
  }

  // Baud rate is too small to be match
  while(1);
}

//=========================================================
// Runtime API
//=========================================================

uint8_t UART1_getIntFlags(void)
{
  return SCON1 & (UART1_TX_IF | UART1_RX_IF);
}

void UART1_clearIntFlags(uint8_t flags)
{
  SCON1 &= ~flags;
}

void UART1_initTxPolling(void)
{
  SCON1 |= SCON1_TI__SET;
}

void UART1_write(uint8_t value)
{
  SBUF1 = value;
}

uint8_t UART1_read(void)
{
  return SBUF1;
}

void UART1_writeWithExtraBit(uint16_t value)
{
  uint8_t shift, mask;

  // Calculate shift and mask for data length
  shift = ((SMOD1 & SMOD1_SDL__FMASK) >> SMOD1_SDL__SHIFT) + 2;
  mask = 0xFF >> (5 - shift);

  SCON1 &= ~SCON1_TBX__BMASK;
  SCON1 |= ((value >> shift) & SCON1_TBX__BMASK);
  SBUF1 = (value & mask);
}

uint16_t UART1_readWithExtraBit(void)
{
  uint8_t shift, mask;
  uint16_t val;

  // Calculate shift and mask for data length
  shift = ((SMOD1 & SMOD1_SDL__FMASK) >> SMOD1_SDL__SHIFT) + 3;
  mask = 0xFF >> (6 - shift);

  val = SCON1 & SCON1_RBX__BMASK;
  val = val << shift;
  val |= (SBUF1 & mask);

  return val;
}

uint8_t UART1_getErrFlags(void)
{
  return SCON1 & (UART1_RXOVR_EF | UART1_PARITY_EF);
}

void UART1_clearErrFlags(uint8_t flags)
{
  SCON1 &= ~flags;
}

//=========================================================
// Initialization API
//=========================================================

void UART1_init(uint32_t sysclk, uint32_t baudrate,
                UART1_DataLen_t datalen, UART1_StopLen_t stoplen,
                UART1_FeatureBit_t featbit, UART1_ParityType_t partype,
                UART1_RxEnable_t rxen, UART1_Multiproc_t mcen)
{
  UART1_initBaudRate(sysclk, baudrate);
  SCON1 = rxen;
  SMOD1 = datalen | stoplen | featbit | partype | mcen;
}

void UART1_reset(void)
{
  SCON1 = SCON1_OVR__NOT_SET
          | SCON1_PERR__NOT_SET
          | SCON1_REN__RECEIVE_DISABLED
          | SCON1_TBX__LOW
          | SCON1_RBX__LOW
          | SCON1_TI__NOT_SET
          | SCON1_RI__NOT_SET;
  SMOD1 = SMOD1_MCE__MULTI_DISABLED
          | SMOD1_SPT__ODD_PARITY
          | SMOD1_PE__PARITY_DISABLED
          | SMOD1_SDL__8_BITS
          | SMOD1_XBE__DISABLED
          | SMOD1_SBL__SHORT;
  SBCON1 = SBCON1_BREN__DISABLED
           | SBCON1_BPS__DIV_BY_1;
}

//=========================================================
// Buffer Access API
//=========================================================
#if EFM8PDL_UART1_USE_BUFFER == 1

SI_SEGMENT_VARIABLE(txRemaining, static uint8_t, SI_SEG_XDATA) = 0;
SI_SEGMENT_VARIABLE(rxRemaining, static uint8_t, SI_SEG_XDATA) = 0;
SI_SEGMENT_VARIABLE_SEGMENT_POINTER(txBuffer, static uint8_t, EFM8PDL_UART1_TX_BUFTYPE, SI_SEG_XDATA);
SI_SEGMENT_VARIABLE_SEGMENT_POINTER(rxBuffer, static uint8_t, EFM8PDL_UART1_RX_BUFTYPE, SI_SEG_XDATA);

SI_INTERRUPT(UART1_ISR, UART1_IRQn)
{
  uint8_t discard;
#if (EFM8PDL_UART1_USE_ERR_CALLBACK == 1)
  uint8_t errors;
#endif //EFM8PDL_UART1_USE_ERR_CALLBACK

  // Read bytes as long as rx fifo is not empty
  while (SCON1 & UART1_RX_IF)
  {
    SCON1 &= ~UART1_RX_IF;

#if (EFM8PDL_UART1_USE_ERR_CALLBACK == 1)
    // If parity or overrun error, clear flags, and call user
    errors = SCON1 & (UART1_RXOVR_EF | UART1_PARITY_EF);
    if(errors)
    {
      SCON1 &= ~errors;
      UART1_transferErrorCb(errors);
    }

    // Store byte if there is room in rx buffer and no parity error
    if (rxRemaining && !(errors & UART1_PARITY_EF))
#else
    // Store byte if there is room in rx buffer
    if (rxRemaining)
#endif //EFM8PDL_UART1_USE_ERR_CALLBACK
    {
      *rxBuffer = SBUF1;
      ++rxBuffer;
      --rxRemaining;
      if (!rxRemaining)
      {
        UART1_receiveCompleteCb();
      }
    }
    // Discard byte if there is no room available in rx buffer (or parity error)
    else
    {
	  discard = SBUF1;
    }

    // Work around for receive FIFO collision error. If SBUF1 is read as a new
    // stop bit is received, OVR is set and the FIFO read pointer does not update.
    // Since we just cleared OVR then read SBUF1, OVR now indicates that a FIFO
    // collision occurred. If so, clear the error and pop the FIFO to update its
    // read pointer.
    if (SCON1 & UART1_RXOVR_EF)
    {
      SCON1 &= ~UART1_RXOVR_EF;
      discard = SBUF1;
    }
  }
    
  // If previous byte has been transmitted
  if (SCON1 & UART1_TX_IF)
  {
	SCON1 &= ~UART1_TX_IF;

    // Write byte if there is room in the tx buffer
    if (txRemaining)
    {
      SBUF1 = *txBuffer;
      ++txBuffer;
      --txRemaining;
    }
    else
    {
      UART1_transmitCompleteCb();
    }
  }
}

void UART1_writeBuffer(SI_VARIABLE_SEGMENT_POINTER(buffer, uint8_t, EFM8PDL_UART1_RX_BUFTYPE),
                       uint8_t length)
{
  // Initialize internal data
  txBuffer = buffer + 1;
  txRemaining = length - 1;

  //Send initial byte
  SBUF1 = *buffer;
}

void UART1_readBuffer(SI_VARIABLE_SEGMENT_POINTER(buffer, uint8_t, EFM8PDL_UART1_TX_BUFTYPE),
                      uint8_t length)
{
  // Initialize internal data
  rxBuffer = buffer;
  rxRemaining = length;
}

void UART1_abortTx(void)
{
  txRemaining = 0;
}

void UART1_abortRx(void)
{
  rxRemaining = 0;
}

uint8_t UART1_txBytesRemaining(void)
{
  return txRemaining;
}

uint8_t UART1_rxBytesRemaining(void)
{
  return rxRemaining;
}

#endif //EFM8PDL_UART1_USE_BUFFER

//=========================================================
// STDIO API
//=========================================================
#if EFM8PDL_UART1_USE_STDIO == 1
char putchar(char c){
  while(!(SCON1 & SCON1_TI__SET));
  SBUF1 = c;
  SCON1 &= ~SCON1_TI__SET;
  return c;
}

char _getkey(void){
  while(!(SCON1 & SCON1_RI__SET));
  SCON1 &= ~SCON1_RI__SET;
  return SBUF1;
}

void UART1_initStdio(uint32_t sysclk, uint32_t baudrate)
{
  SCON1  |= SCON1_REN__RECEIVE_ENABLED | SCON1_TI__SET;
  SMOD1  |= SMOD1_SDL__8_BITS;
  UART1_initBaudRate(sysclk, baudrate);
}

#endif //EFM8PDL_UART0_USE_STDIO
