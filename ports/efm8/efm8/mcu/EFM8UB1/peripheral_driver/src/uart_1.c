/**************************************************************************//**
 * Copyright (c) 2016 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "uart_1.h"

#if EFM8PDL_UART1_AUTO_PAGE == 1
// declare variable needed for autopage enter/exit
#define DECL_PAGE uint8_t savedPage
// enter autopage section
#define SET_PAGE(p)     do                                                    \
                        {                                                     \
                          savedPage = SFRPAGE;  /* save current SFR page */   \
                          SFRPAGE = (p);        /* set SFR page */            \
                        } while(0)
// exit autopage section
#define RESTORE_PAGE    do                                                    \
                        {                                                     \
                          SFRPAGE = savedPage;  /* restore saved SFR page */  \
                        } while(0)

#else
#define DECL_PAGE
#define SET_PAGE(x)
#define RESTORE_PAGE
#endif //EFM8PDL_UART1_AUTO_PAGE

// SFR page used to access UART1 registers
#define UART1_SFR_PAGE 0x20

// Clock prescaler values for baud rate initialization
#define NUM_PRESC 8
static const uint8_t PRESC[NUM_PRESC]      = {1, 4, 8, 12, 16, 24, 32, 48};
static const uint8_t PRESC_ENUM[NUM_PRESC] = {SBCON1_BPS__DIV_BY_1,  SBCON1_BPS__DIV_BY_4,  SBCON1_BPS__DIV_BY_8,  SBCON1_BPS__DIV_BY_12,
                                              SBCON1_BPS__DIV_BY_16, SBCON1_BPS__DIV_BY_24, SBCON1_BPS__DIV_BY_32, SBCON1_BPS__DIV_BY_48};
static void UART1_initBaudRate(uint32_t sysclk, uint32_t baudrate)
{
  uint8_t i;
  uint8_t min_presc;
  uint16_t reload;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);

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
      RESTORE_PAGE;
      return;
    }
  }

  // Baud rate is too small to be match
  while(1);
}

//=========================================================
// Runtime API
//=========================================================

#if (EFM8PDL_UART1_AUTO_PAGE == 1)
uint8_t UART1_getIntFlags(void)
{
  uint8_t val;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  val = SCON1 & (UART1_TX_IF | UART1_RX_IF);
  RESTORE_PAGE;
  return val;
}

void UART1_clearIntFlags(uint8_t flags)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  SCON1 &= ~(flags);
  RESTORE_PAGE;
}

void UART1_enableTxInt(bool enable)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  UART1FCN1_TIE = enable;
  RESTORE_PAGE;
}

void UART1_enableRxInt(bool enable)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  UART1FCN1_RIE = enable;
  RESTORE_PAGE;
}

void UART1_initTxPolling(void)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  SCON1_TI = 1;
  RESTORE_PAGE;
}

void UART1_write(uint8_t value)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  SBUF1 = value;
  RESTORE_PAGE;
}

uint8_t UART1_read(void)
{
  uint8_t val;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  val = SBUF1;
  RESTORE_PAGE;
  return val;
}
#endif

void UART1_writeWithExtraBit(uint16_t value)
{
  uint8_t shift, mask;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);

  // Calculate shift and mask for data length
  shift = ((SMOD1 & SMOD1_SDL__FMASK) >> SMOD1_SDL__SHIFT) + 5;
  mask = 0xFF >> (8 - shift);

  SCON1_TBX = (value >> shift) & 0x1;
  SBUF1 = (value & mask);

  RESTORE_PAGE;
}

uint16_t UART1_readWithExtraBit(void)
{
  uint8_t shift, mask;
  uint16_t val;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);

  // Calculate shift and mask for data length
  shift = ((SMOD1 & SMOD1_SDL__FMASK) >> SMOD1_SDL__SHIFT) + 5;
  mask = 0xFF >> (8 - shift);

  val = SCON1_RBX;
  val = val << shift;
  val |= (SBUF1 & mask);

  RESTORE_PAGE;
  return val;
}

#if (EFM8PDL_UART1_AUTO_PAGE == 1)
uint8_t UART1_getErrFlags(void)
{
  uint8_t val;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  val = SCON1 & (UART1_RXOVR_EF | UART1_PARITY_EF);
  RESTORE_PAGE;
  return val;
}

void UART1_clearErrFlags(uint8_t flags)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  SCON1 &= ~flags;
  RESTORE_PAGE;
}

uint8_t UART1_getFifoIntFlags(void)
{
  uint8_t val;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  val = UART1FCN1 & (UART1_TFRQ_IF | UART1_RFRQ_IF);
  RESTORE_PAGE;
  return val;
}
#endif

void UART1_enableTxFifoInt(bool enable)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  if(enable)
  {
    UART1FCN0 |= UART1FCN0_TFRQE__ENABLED;
  }
  else
  {
    UART1FCN0 &= ~UART1FCN0_TFRQE__ENABLED;
  }
  RESTORE_PAGE;
}

void UART1_enableRxFifoInt(bool enable)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  if(enable)
  {
    UART1FCN0 |= UART1FCN0_RFRQE__ENABLED;
  }
  else
  {
    UART1FCN0 &= ~UART1FCN0_RFRQE__ENABLED;
  }
  RESTORE_PAGE;
}

#if (EFM8PDL_UART1_AUTO_PAGE == 1)
uint8_t UART1_getTxFifoCount(void)
{
  uint8_t txcnt;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  txcnt = (UART1FCT & UART1FCT_TXCNT__FMASK) >> UART1FCT_TXCNT__SHIFT;
  RESTORE_PAGE;
  return txcnt;
}

uint8_t UART1_getRxFifoCount(void)
{
  uint8_t rxcnt;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  rxcnt = (UART1FCT & UART1FCT_RXCNT__FMASK) >> UART1FCT_RXCNT__SHIFT;
  RESTORE_PAGE;
  return rxcnt;
}
#endif

bool UART1_isTxFifoFull(void){
  bool txfull;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  if(UART1FCN1 & UART1FCN1_TXNF__NOT_FULL)
  {
    txfull = false;
  }
  else
  {
    txfull = true;
  }
  RESTORE_PAGE;
  return txfull;
}

void UART1_stallTxFifo(bool enable)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  if(enable)
  {
    UART1FCN1 |= UART1FCN1_TXHOLD__HOLD;
  }
  else
  {
    UART1FCN1 &= ~UART1FCN1_TXHOLD__HOLD;
  }
  RESTORE_PAGE;
}

#if (EFM8PDL_UART1_AUTO_PAGE == 1)
void UART1_flushTxFifo(void)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  UART1FCN0 |= UART1FCN0_TFLSH__FLUSH;
  RESTORE_PAGE;
}

void UART1_flushRxFifo(void)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  UART1FCN0 |= UART1FCN0_RFLSH__FLUSH;
  RESTORE_PAGE;
}

uint8_t UART1_getAutobaudIntFlag(void)
{
  uint8_t val;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  val = UART1LIN & UART1_AUTOBAUD_IF;
  RESTORE_PAGE;
  return val;
}

void UART1_clearAutobaudIntFlag(void)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  UART1LIN &= ~UART1_AUTOBAUD_IF;
  RESTORE_PAGE;
}
#endif

void UART1_enableAutobaud(bool enable)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  if(enable)
  {
    UART1LIN |= (UART1LIN_AUTOBDE__ENABLED | UART1LIN_SYNCDIE__ENABLED);
  }
  else
  {
    UART1LIN &= ~(UART1LIN_AUTOBDE__ENABLED | UART1LIN_SYNCDIE__ENABLED);
  }
  RESTORE_PAGE;
}

//=========================================================
// Initialization API
//=========================================================

void UART1_init(uint32_t sysclk, uint32_t baudrate,
                UART1_DataLen_t datalen, UART1_StopLen_t stoplen,
                UART1_FeatureBit_t featbit, UART1_ParityType_t partype,
                UART1_RxEnable_t rxen, UART1_Multiproc_t mcen)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  UART1_initBaudRate(sysclk, baudrate);
  SCON1 = rxen;
  SMOD1 = datalen | stoplen | featbit | partype | mcen;
  RESTORE_PAGE;
}

void UART1_initWithAutobaud(UART1_BrPrescaler_t presc, UART1_StopLen_t stoplen,
                            UART1_FeatureBit_t featbit, UART1_ParityType_t partype,
                            UART1_RxEnable_t rxen, UART1_Multiproc_t mcen)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  SCON1 = rxen;
  SMOD1 = SMOD1_SDL__8_BITS | stoplen | featbit | partype | mcen;
  UART1LIN = (UART1LIN_AUTOBDE__ENABLED | UART1LIN_SYNCDIE__ENABLED);
  SBCON1 = (SBCON1_BREN__ENABLED | presc);
  RESTORE_PAGE;
}

void UART1_reset(void)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
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
  UART1LIN = (UART1LIN_AUTOBDE__DISABLED | UART1LIN_SYNCDIE__DISABLED);
  RESTORE_PAGE;
}

void UART1_initTxFifo(UART1_TxFifoThreshold_t txth, UART1_TxFifoInt_t txint)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);

  UART1FCN0 &= ~(UART1FCN0_TFRQE__BMASK
                 | UART1FCN0_TFLSH__BMASK
                 | UART1FCN0_TXTH__FMASK
                 | UART1FCN0_TFRQE__BMASK);
  UART1FCN0 |= (txth | txint);

  UART1FCN1 &= ~(UART1FCN1_TFRQ__BMASK
                 | UART1FCN1_TXHOLD__BMASK
                 | UART1FCN1_TXNF__BMASK
                 | UART1FCN1_TIE__BMASK);
  UART1FCN1 |= (UART1FCN1_TFRQ__SET
                | UART1FCN1_TXHOLD__CONTINUE
                | UART1FCN1_TIE__DISABLED);

  RESTORE_PAGE;
}

void UART1_initRxFifo(UART1_RxFiFoThreshold_t rxth, UART1_RxFifoTimeout_t rxto,
                      UART1_RxFifoInt_t rxint)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);

  UART1FCN0 &= ~(UART1FCN0_RFRQE__BMASK
                 | UART1FCN0_RFLSH__BMASK
                 | UART1FCN0_RXTH__FMASK
                 | UART1FCN0_RFRQE__BMASK);
  UART1FCN0 |= (rxth | rxint);

  UART1FCN1 &= ~(UART1FCN1_RFRQ__BMASK
                 | UART1FCN1_RXTO__FMASK
                 | UART1FCN1_RIE__BMASK);
  UART1FCN1 |= (UART1FCN1_RFRQ__SET
                | rxto
                | UART1FCN1_RIE__DISABLED);

  RESTORE_PAGE;
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
#if (EFM8PDL_UART1_USE_ERR_CALLBACK == 1)
  uint8_t discard;
  uint8_t errors;
#endif //EFM8PDL_UART1_USE_ERR_CALLBACK

  // If auto-baud sync word detected to set baudrate, clear flag and disable auto-baud detection
  if (UART1LIN & UART1_AUTOBAUD_IF)
  {
    UART1LIN &= ~(UART1_AUTOBAUD_IF | UART1LIN_AUTOBDE__ENABLED | UART1LIN_SYNCDIE__ENABLED);
  }
  
  // If rx fifo request interrupt is set and enabled
  if ((UART1FCN1 & UART1_RFRQ_IF) && (UART1FCN0 & UART1FCN0_RFRQE__ENABLED))
  {
    // Read bytes as long as rx fifo count is not zero and there
	// is room in the tx buffer
    while (rxRemaining && ((UART1FCT & UART1FCT_RXCNT__FMASK) >> UART1FCT_RXCNT__SHIFT))
    {
#if (EFM8PDL_UART1_USE_ERR_CALLBACK == 1)
      // If parity or overrun error, clear flags, and call user
      errors = SCON1 & (UART1_RXOVR_EF | UART1_PARITY_EF);
      if(errors)
      {
        SCON1 &= ~errors;
        UART1_transferErrorCb(errors);
      }

      // Store byte if there is no parity error a
      if (errors & UART1_PARITY_EF)
      {
        discard = SBUF1;
      }
      else
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
    }
    if(!rxRemaining)
    {
      // Flush Fifo if there is no room available in rx buffer
      UART1FCN0 |= UART1FCN0_RFLSH__FLUSH;
    }
  }

  // If tx fifo request interrupt is set and enabled
  if ((UART1FCN1 &  UART1_TFRQ_IF) && (UART1FCN0 & UART1FCN0_TFRQE__ENABLED))
  {
    // Write bytes as long as the tx fifo is not full and there
    // is room in the tx buffer
    while (txRemaining && (UART1FCN1 & UART1FCN1_TXNF__NOT_FULL))
    {
      SBUF1 = *txBuffer;
      ++txBuffer;
      --txRemaining;
    }
    if(!txRemaining)
    {
      UART1_transmitCompleteCb();
    }
  }
}

void UART1_writeBuffer(SI_VARIABLE_SEGMENT_POINTER(buffer, uint8_t, EFM8PDL_UART1_RX_BUFTYPE),
                       uint8_t length)
{
  // Initialize internal data
  txBuffer = buffer;
  txRemaining = length;

  // Enable tx fifo interrupts to kick off transfer
  UART1FCN0 |= UART1FCN0_TFRQE__ENABLED;
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
  UART1_flushTxFifo();
}

void UART1_abortRx(void)
{
  rxRemaining = 0;
  UART1_flushRxFifo();
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
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  while(!SCON1_TI);
  SBUF1 = c;
  SCON1_TI = 0;
  RESTORE_PAGE;
  return c;
}

char _getkey(void){
  char val;
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  while(!SCON1_RI);
  SCON1_RI = 0;

  val = SBUF1;
  RESTORE_PAGE;
  return val;
}

void UART1_initStdio(uint32_t sysclk, uint32_t baudrate)
{
  DECL_PAGE;
  SET_PAGE(UART1_SFR_PAGE);
  SCON1  |= SCON1_REN__RECEIVE_ENABLED | SCON1_TI__SET;
  SMOD1  |= SMOD1_SDL__8_BITS;
  UART1_initBaudRate(sysclk, baudrate);
  RESTORE_PAGE;
}

#endif //EFM8PDL_UART0_USE_STDIO
