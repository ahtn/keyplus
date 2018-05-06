/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "uart_0.h"

#if EFM8PDL_UART0_AUTO_PAGE == 1
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
#define SET_PAGE
#define RESTORE_PAGE
#endif


uint8_t UART0_getIntFlags()
{
  uint8_t val;
  DECL_PAGE;
  SET_PAGE(0x00);
  val = SCON0 & (UART0_TX_IF | UART0_RX_IF);
  RESTORE_PAGE;
  return val;
}

void UART0_clearIntFlag(uint8_t flag)
{
  DECL_PAGE;
  SET_PAGE(0x00);
  SCON0 &= ~(flag);
  RESTORE_PAGE;
}

void UART0_initTxPolling()
{
  DECL_PAGE;
  SET_PAGE(0x00);
  SCON0_TI = 1;
  RESTORE_PAGE;
}

void UART0_write(uint8_t value)
{
  DECL_PAGE;
  SET_PAGE(0x00);
  SBUF0 = value;
  RESTORE_PAGE;
}

uint8_t UART0_read(void)
{
  uint8_t val;
  DECL_PAGE;
  SET_PAGE(0x00);
  val = SBUF0;
  RESTORE_PAGE;
  return val;
}
void UART0_writeWithExtraBit(uint16_t value)
{
  DECL_PAGE;
  SET_PAGE(0x00);
  SCON0_TB8 = value >> 8;
  SBUF0 = value;
  RESTORE_PAGE;
}

uint16_t UART0_readWithExtraBit(void)
{
  uint16_t val;
  DECL_PAGE;
  SET_PAGE(0x00);
  val = (SBUF0 | ((SCON0 & SCON0_RB8__BMASK) << 6) );
  RESTORE_PAGE;
  return val;
}

void UART0_init(UART0_RxEnable_t rxen, UART0_Width_t width, UART0_Multiproc_t mce)
{
  DECL_PAGE;
  SET_PAGE(0x00);
  SCON0 &= ~(SCON0_SMODE__BMASK
             | SCON0_MCE__BMASK
             | SCON0_REN__BMASK);
  SCON0 = mce | rxen | width;
  RESTORE_PAGE;
}

void UART0_reset()
{
  DECL_PAGE;
  SET_PAGE(0x00);
  SCON0 = SCON0_SMODE__8_BIT
          | SCON0_MCE__MULTI_DISABLED
          | SCON0_REN__RECEIVE_DISABLED
          | SCON0_TB8__NOT_SET
          | SCON0_RB8__NOT_SET
          | SCON0_TI__NOT_SET
          | SCON0_RI__NOT_SET;
  RESTORE_PAGE;
}

//=========================================================
// Interrupt API
//=========================================================
#if EFM8PDL_UART0_USE_BUFFER == 1

/**
 * Internal variable fort trackig buffer transfers. transferLenth[UART0_TX_TRANSFER] = bytes remaining in transfer.
 */
SI_SEGMENT_VARIABLE(txRemaining, static uint8_t,  SI_SEG_XDATA)=0;
SI_SEGMENT_VARIABLE(rxRemaining, static uint8_t,  SI_SEG_XDATA)=0;
SI_SEGMENT_VARIABLE_SEGMENT_POINTER(txBuffer,    static uint8_t, EFM8PDL_UART0_TX_BUFTYPE, SI_SEG_XDATA);
SI_SEGMENT_VARIABLE_SEGMENT_POINTER(rxBuffer,    static uint8_t, EFM8PDL_UART0_RX_BUFTYPE, SI_SEG_XDATA);


SI_INTERRUPT(UART0_ISR, UART0_IRQn)
{
  //Buffer and clear flags immediately so we don't miss an interrupt while processing
  uint8_t flags, discard;
  SFRPAGE = 0x00; // Rely on page stack to restore page on return from int

  flags = SCON0;
  UART0_clearIntFlag(UART0_TX_IF); //can't clear RX with software

  if (flags &  SCON0_RI__SET)
  {
    if(rxRemaining)
    {
      *rxBuffer = SBUF0;
      ++rxBuffer;
      --rxRemaining;
      if (!rxRemaining)
      {
        UART0_receiveCompleteCb();
      }
    }
    else
    {
      discard = SBUF0; //Need to read SBUF to clear interrupt flag.
    }
  }

  if ((flags & SCON0_TI__SET))
  {
    if (txRemaining){
      SBUF0 = *txBuffer;
      ++txBuffer;
      --txRemaining;
    }
    else
    {
      UART0_transmitCompleteCb();
    }
  }
}

void UART0_writeBuffer(SI_VARIABLE_SEGMENT_POINTER(buffer,
                                                uint8_t,
                                                EFM8PDL_UART0_TX_BUFTYPE),
                       uint8_t length)
{
  DECL_PAGE;
  SET_PAGE(0x00);
  //Init internal data
  txBuffer = buffer+1;
  txRemaining = length-1;

  //Send initial byte
  SBUF0 = *buffer;
  RESTORE_PAGE;
}

void UART0_readBuffer(SI_VARIABLE_SEGMENT_POINTER(buffer,
		                                       uint8_t,
		                                       EFM8PDL_UART0_RX_BUFTYPE),
		              uint8_t length)
{
  //Init internal data
  rxBuffer = buffer;
  rxRemaining = length;
}

void UART0_abortWrite()
{
  txRemaining = 0;
}

void UART0_abortRead()
{
  rxRemaining = 0;
}

uint8_t UART0_txBytesRemaining()
{
  return txRemaining;
}

uint8_t UART0_rxBytesRemaining()
{
  return rxRemaining;
}

#endif //EFM8PDL_UART0_USE_BUFFER

#if EFM8PDL_UART0_USE_STDIO == 1

#if defined __C51__

char putchar(char c){
  DECL_PAGE;
  SET_PAGE(0x00);
  while(!SCON0_TI);
  SBUF0 = c;
  SCON0_TI = 0;
  RESTORE_PAGE;
  return c;
}

char _getkey(){
  char val;
  DECL_PAGE;
  SET_PAGE(0x00);
  while(!SCON0_RI);
  SCON0_RI = 0;

  val = SBUF0;
  RESTORE_PAGE;
  return val;
}

#elif defined __ICC8051__

int putchar(int c){
  DECL_PAGE;
  SET_PAGE(0x00);
  while(!SCON0_TI);
  SBUF0 = c;
  SCON0_TI = 0;
  RESTORE_PAGE;
  return c;
}

int getchar(void){
  char val;
  DECL_PAGE;
  SET_PAGE(0x00);
  while(!SCON0_RI);
  SCON0_RI = 0;

  val = SBUF0;
  RESTORE_PAGE;
  return val;
}

#endif

void UART0_initStdio()
{
  DECL_PAGE;
  SET_PAGE(0x00);
  SCON0 |= SCON0_REN__RECEIVE_ENABLED | SCON0_TI__SET;
  RESTORE_PAGE;
}
#endif //EFM8PDL_UART0_USE_STDIO
