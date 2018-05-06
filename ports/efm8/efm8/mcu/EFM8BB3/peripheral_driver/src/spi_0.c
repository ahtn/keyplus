/******************************************************************************
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "efm8_config.h"
#include "SI_EFM8BB3_Register_Enums.h"
#include "spi_0.h"

#if EFM8PDL_SPI0_AUTO_PAGE == 1
// declare variable needed for autopage enter/exit
#define DECL_PAGE uint8_t savedPage
// enter autopage section
#define SET_PAGE(p)     do                                                    \
                        {                                                     \
                          savedPage = SFRPAGE;  /* save current SFR page */   \
                          SFRPAGE = (p);        /* set SFR page */            \
                        } while(0)
// exit autopage section
#define RESTORE_PAGE(x) do                                                    \
                        {                                                     \
                          SFRPAGE = savedPage;  /* restore saved SFR page */  \
                        } while(0)
#else
#define DECL_PAGE
#define SET_PAGE(x)
#define RESTORE_PAGE(x)
#endif

// SFR page used to access SPI registers
#define SPI_SFR_PAGE 0x20

// Runtime API

// Flag to indicate if driver should control Nss (chip select)
static bool useNss  = false;

// flag to indicate we are in master mode (else slave)
static bool modeIsMaster = false;

// flag to indicate that init vars (above) are valid.  If they are
// not valid then a special one-time init will be called to set them
static bool initIsValid = false;

// ----------------------------------------------------------------------------
// Initialize internal state variables.  This is used if init API is
// not called.
// ----------------------------------------------------------------------------
static void SPI0_internalInit(void)
{
  // figure out if we are master mode, and using 4-wire or not
  modeIsMaster = SPI0CFG & SPI0CFG_MSTEN__MASTER_ENABLED;
  useNss = SPI0CN0 & SPI0CN0_NSSMD__FMASK;

  // indicate that init has now been done
  initIsValid = true;
}

#if (EFM8PDL_SPI0_AUTO_PAGE == 1)
// ----------------------------------------------------------------------------
// Get interrupt flags
// ----------------------------------------------------------------------------
uint8_t SPI0_getIntFlags(void)
{
  uint8_t ret;
  DECL_PAGE;
  SET_PAGE(SPI_SFR_PAGE);
  ret = SPI0CN0 & 0xF0;
  RESTORE_PAGE();
  return ret;
}

// ----------------------------------------------------------------------------
// Clear specific interrupt flags
// ----------------------------------------------------------------------------
void SPI0_clearIntFlags(uint8_t flags)
{
  DECL_PAGE;
  SET_PAGE(SPI_SFR_PAGE);
  SPI0CN0 = (SPI0CN0 & (~flags | 0x0F));
  RESTORE_PAGE();
}
#endif

// ----------------------------------------------------------------------------
// Write a byte if transmit buffer is not full.
// ----------------------------------------------------------------------------
bool SPI0_writeByte(uint8_t value)
{
  bool ret = false;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);

  // check to see if transmit buffer is not full
  if (SPI0CN0_TXNF)
  {
    SPI0DAT = value;
    ret = true;
  }

  RESTORE_PAGE();
  return ret;
}

// ----------------------------------------------------------------------------
// Write a byte, waiting for transmit buffer to be empty
// ----------------------------------------------------------------------------
void SPI0_pollWriteByte(uint8_t value)
{
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);

  // wait for TX empty
  while (!SPI0CN0_TXNF)
  {}

  SPI0DAT = value;

  RESTORE_PAGE();
}

#if (EFM8PDL_SPI0_AUTO_PAGE == 1)
// ----------------------------------------------------------------------------
// Read a byte without checking status
// ----------------------------------------------------------------------------
extern uint8_t SPI0_readByte(void)
{
  uint8_t ret;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);
  ret = SPI0DAT;
  RESTORE_PAGE();
  return ret;
}
#endif

// ----------------------------------------------------------------------------
// Read a byte, waiting for ther receive buffer to contain at least one byte.
// ----------------------------------------------------------------------------
uint8_t SPI0_pollReadByte(void)
{
  uint8_t ret;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);

  // wait while RX is empty
  while (SPI0CFG & SPI0CFG_RXE__BMASK)
  {}

  ret = SPI0DAT;
  RESTORE_PAGE();

  return ret;
}

// ----------------------------------------------------------------------------
// Perform a multi-byte transfer, waiting for each byte to complete.
// ----------------------------------------------------------------------------
uint8_t
SPI0_pollTransfer(SI_VARIABLE_SEGMENT_POINTER(pTxBuffer, uint8_t,
                                              EFM8PDL_SPI0_TX_SEGTYPE),
                  SI_VARIABLE_SEGMENT_POINTER(pRxBuffer, uint8_t,
                                              EFM8PDL_SPI0_RX_SEGTYPE),
                  SPI0_TransferDirection_t dir,
                  uint8_t xferCount)
{
  uint8_t txCount = xferCount;
  bool checkNss = false;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);

  // This function is not interrupt driven and if SPI interrupts are
  // enabled, it can cause interference.
  SPI0_disableInt();

  // make sure SPI is not already busy
  while (SPI0CFG & SPI0CFG_SPIBSY__BMASK)
  {}

  // Check to see if run-time mode variables have been set up
  if (!initIsValid)
  {
    SPI0_internalInit();
  }

  // Flush the RX buffer in case something is in there
#if (EFM8PDL_SPI0_AUTO_PAGE == 1)
  {
    // if auto page is enabled then we dont need to change pages here
    SPI0FCN0 |= SPI0FCN0_RFLSH__FLUSH;
  }
#else
  {
    // if auto page is not enabled, then we need to change pages for
    // this section of code
    uint8_t savedPage = SFRPAGE;
    SFRPAGE = SPI_SFR_PAGE;
    SPI0FCN0 |= SPI0FCN0_RFLSH__FLUSH;
    SFRPAGE = savedPage;
  }
#endif

  // assert NSS (if used)
  if (modeIsMaster && useNss)
  {
    SPI0CN0_NSSMD0 = 0;
  }

  // Wait in loop until the requested number of transfers are complete
  // Note: xferCount tracks the number of bytes received
  while (xferCount)
  {
    // If the transmit buffer is empty and there are still bytes to
    // write, then write a byte out
    if (SPI0CN0_TXNF && txCount)
    {
      // If user provided a write buffer then use that
      if (dir & SPI0_TRANSFER_TX)
      {
        SPI0DAT = *pTxBuffer;
        ++pTxBuffer;
      }

      // else user did not provide write buffer so just use zeroes
      else
      {
        SPI0DAT = 0;
      }

      --txCount;
    }

    // If the receive buffer is not empty and there are more bytes to read
    if (!(SPI0CFG & SPI0CFG_RXE__BMASK) && xferCount)
    {
      // If user provided RX buffer, then read byte into buffer
      if (dir & SPI0_TRANSFER_RX)
      {
        *pRxBuffer = SPI0DAT;
        ++pRxBuffer;
      }

      // else there is no RX buffer so just throw away the incoming byte
      else
      {
        uint8_t dummy = SPI0DAT;
      }

      --xferCount;
    }

    // If we are in slave mode and 4-wire, then check to make sure
    // slave is selected.  If not it means the spi master stopped
    // the transfer.  Bust out of the polling loop so we dont hang
    // here forever.
    if (!modeIsMaster && useNss)
    {
      // wait for nss to be asserted the first time before we
      // start checking it
      if (!checkNss)
      {
        if ((SPI0CFG & SPI0CFG_SLVSEL__BMASK))
        {
          checkNss = true;
        }
      }
      else
      {
        if (!(SPI0CFG & SPI0CFG_SLVSEL__BMASK))
        {
          break;
        }
      }
    }
  }

  // Transfer is done.  Deassert NSS (if used)
  if (modeIsMaster && useNss)
  {
    SPI0CN0_NSSMD0 = 1;
  }

  RESTORE_PAGE();
  return xferCount;
}

// ----------------------------------------------------------------------------
// Check if SPI is busy with a transfer in progress.
// ----------------------------------------------------------------------------
bool SPI0_isBusy(void)
{
  uint8_t count = 0;
  bool ret = false;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);

  // the SPI busy bit can drop between bytes so you cant just poll
  // it to find out when all the bytes have been transferred.  Or sometimes
  // you will catch it not set, between bytes when it is really still
  // busy.  To make busy test useful, we need to know when it is done
  // with all bytes.  That is why there is a loop below.

  // Read it several times and if the bit is ever marked busy, then
  // return busy indication.
  for (count = 0; count < 3; count++)
  {
    if (SPI0CFG & SPI0CFG_SPIBSY__BMASK)
    {
      ret = true;
    }
  }

  // If it makes it through the loops above without find the busy bit
  // then it is not busy.
  RESTORE_PAGE();
  return ret;
}

#if (EFM8PDL_SPI0_AUTO_PAGE == 1)
// ----------------------------------------------------------------------------
// Check if transmit buffer is full
// ----------------------------------------------------------------------------
bool SPI0_isTxFull(void)
{
  bool ret;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);
  ret = !SPI0CN0_TXNF;
  RESTORE_PAGE();
  return ret;
}

// ----------------------------------------------------------------------------
// Check if slave is selected
// ----------------------------------------------------------------------------
bool SPI0_isSlaveSelected(void)
{
  bool ret;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);
  ret = SPI0CFG & SPI0CFG_SLVSEL__BMASK;
  RESTORE_PAGE();
  return ret;
}

// ----------------------------------------------------------------------------
// Check if shift register is empty
// ----------------------------------------------------------------------------
bool SPI0_isShiftEmpty(void)
{
  bool ret;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);
  ret = SPI0CFG & SPI0CFG_SRMT__BMASK;
  RESTORE_PAGE();
  return ret;
}

// ----------------------------------------------------------------------------
// Check if receive buffer is empty
// ----------------------------------------------------------------------------
bool SPI0_isRxEmpty(void)
{
  bool ret;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);
  ret = SPI0CFG & SPI0CFG_RXE__BMASK;
  RESTORE_PAGE();
  return ret;
}
#endif

// ----------------------------------------------------------------------------
// Initialize the SPI peripheral operating parameters
// ----------------------------------------------------------------------------
void SPI0_init(SPI0_ClockMode_t clockMode, bool isMasterMode, bool is4wire)
{
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);

  // Figure out if this driver controls NSS signal (chip select)
  modeIsMaster = isMasterMode;
  useNss = is4wire;
  initIsValid = true;

  // disable SPI before configuring
  SPI0CN0_SPIEN = 0;

  // Set up the clock mode (phase and polarity), and the
  // master/slave selection
  SPI0CFG = clockMode | (isMasterMode ? SPI0CFG_MSTEN__MASTER_ENABLED
                                      : SPI0CFG_MSTEN__MASTER_DISABLED);

  // Set up the NSS mode bits depending on whether 3-wire or 4-wire
  // is used, and whether master or slave mode
  if (is4wire)
  {
    SPI0CN0_NSSMD0 = 1;
    SPI0CN0_NSSMD1 = isMasterMode ? 1 : 0;
  }
  else
  {
    SPI0CN0_NSSMD0 = 0;
    SPI0CN0_NSSMD1 = 0;
  }

  // clear all the interrupt bits and enable the SPI
  SPI0CN0 &= ~0xF0;
  SPI0CN0_SPIEN = 1;

  RESTORE_PAGE();
}

// ----------------------------------------------------------------------------
// Set the clock divider used to determine SPI clock rate
// ----------------------------------------------------------------------------
void SPI0_setClockDivider(uint16_t divider)
{
  DECL_PAGE;

  // constrain input in case user passes a bad value
  if (divider > 512)
  {
    divider = 512;
  }
  if (divider < 2)
  {
    divider = 2;
  }
  // make even value
  divider &= ~1;

  // Transform the divider to the form needed by SFR.
  // See equation in the data sheet for more information
  divider /= 2;
  divider -= 1;

  // disable SPI before configuring, then update the value
  SET_PAGE(SPI_SFR_PAGE);
  SPI0CN0_SPIEN = 0;
  SPI0CKR = (uint8_t)divider;
  SPI0CN0_SPIEN = 1;
  RESTORE_PAGE();
}

#if (EFM8PDL_SPI0_AUTO_PAGE == 1)
// ----------------------------------------------------------------------------
// Reset SPI to disabled state.
// ----------------------------------------------------------------------------
void SPI0_reset(void)
{
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);
  SPI0CN0 &= 0x0E;
  IE_ESPI0 = 0;
  RESTORE_PAGE();
}
#endif

// ----------------------------------------------------------------------------
// Read status of TFRQ
// ----------------------------------------------------------------------------
bool SPI0_isFifoTxReq(void)
{
  bool ret = false;
  uint8_t savedPage = SFRPAGE;
  SFRPAGE = SPI_SFR_PAGE;
  if (SPI0FCN1 & SPI0FCN1_TFRQ__BMASK)
  {
    ret = true;
  }
  SFRPAGE = savedPage;
  return ret;
}

// ----------------------------------------------------------------------------
// Read status of RFRQ
// ----------------------------------------------------------------------------
bool SPI0_isFifoRxReq(void)
{
  bool ret = false;
  uint8_t savedPage = SFRPAGE;
  SFRPAGE = SPI_SFR_PAGE;
  if (SPI0FCN1 & SPI0FCN1_RFRQ__BMASK)
  {
    ret = true;
  }
  SFRPAGE = savedPage;
  return ret;
}

// ----------------------------------------------------------------------------
// Get count of bytes in RX fifo
// ----------------------------------------------------------------------------
uint8_t SPI0_getRxFifoCount(void)
{
  uint8_t ret;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);
  ret = SPI0FCT & SPI0FCT_RXCNT__FMASK;

  RESTORE_PAGE();
  return ret;
}

// ----------------------------------------------------------------------------
// Get count of bytes in TX fifo
// ----------------------------------------------------------------------------
uint8_t SPI0_getTxFifoCount(void)
{
  uint8_t ret;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);
  ret = (SPI0FCT & SPI0FCT_TXCNT__FMASK) >> SPI0FCT_TXCNT__SHIFT;

  RESTORE_PAGE();
  return ret;
}

// ----------------------------------------------------------------------------
// Configure the FIFO operation
// ----------------------------------------------------------------------------
void SPI0_configureFifo(uint8_t txThreshold, uint8_t rxThreshold,
                        uint8_t rxTimeout)
{
  uint8_t fifoCtrl;
  DECL_PAGE;

  SET_PAGE(SPI_SFR_PAGE);

  // Set the TX and RX threshold fields
  fifoCtrl = SPI0FCN0;
  fifoCtrl &= ~(SPI0FCN0_TXTH__FMASK | SPI0FCN0_RXTH__FMASK);
  fifoCtrl |= ((txThreshold & 3) << SPI0FCN0_TXTH__SHIFT)
            | ((rxThreshold & 3) << SPI0FCN0_RXTH__SHIFT);

  // Only change the RX timeout if in slave mode
  if (!(SPI0CFG & SPI0CFG_MSTEN__BMASK))
  {
    // If non-zero then enable the rx timeout bit, and set the
    // timeout count
    if (rxTimeout)
    {
      fifoCtrl |= SPI0FCN1_RXTOE__ENABLED;
      SPI0CKR = rxTimeout;
    }

    // Else rxTimeout is 0, so disable the timeout bit
    else
    {
      fifoCtrl &= ~SPI0FCN1_RXTOE__ENABLED;
    }
  }
  SPI0FCN0 = fifoCtrl;
  RESTORE_PAGE();
}

#if EFM8PDL_SPI0_USE_BUFFER == 1

// flag to indicate that RX buffer should be used for buffered transfers
static bool useRx = false;

// flag to indicate that TX buffer should be used for buffered transfers
static bool useTx = false;

static uint8_t rxCountRemaining = 0;
static uint8_t txCountRemaining = 0;
static uint8_t bytesRemaining = 0;
static SI_VARIABLE_SEGMENT_POINTER(pTxBuf, uint8_t, EFM8PDL_SPI0_TX_SEGTYPE) = NULL;
static SI_VARIABLE_SEGMENT_POINTER(pRxBuf, uint8_t, EFM8PDL_SPI0_RX_SEGTYPE) = NULL;

// ----------------------------------------------------------------------------
// Set up an interrupt driven SPI transfer.
// ----------------------------------------------------------------------------
void
SPI0_transfer(SI_VARIABLE_SEGMENT_POINTER(pTxBuffer, uint8_t,
                                          EFM8PDL_SPI0_TX_SEGTYPE),
              SI_VARIABLE_SEGMENT_POINTER(pRxBuffer, uint8_t,
                                          EFM8PDL_SPI0_RX_SEGTYPE),
              SPI0_TransferDirection_t dir,
              uint8_t xferCount)
{
  DECL_PAGE;

  rxCountRemaining = xferCount;
  txCountRemaining = xferCount;
  bytesRemaining = xferCount;
  pTxBuf = pTxBuffer;
  pRxBuf = pRxBuffer;
  useRx = dir & SPI0_TRANSFER_RX;
  useTx = dir & SPI0_TRANSFER_TX;

  SET_PAGE(SPI_SFR_PAGE);

  // Check to see if run-time mode variables have been set up
  if (!initIsValid)
  {
    SPI0_internalInit();
  }

  // Flush the RX buffer in case something is in there
#if (EFM8PDL_SPI0_AUTO_PAGE == 1)
  {
    // if auto page is enabled then we dont need to change pages here
    SPI0FCN0 |= SPI0FCN0_RFLSH__FLUSH;
  }
#else
  {
    // if auto page is not enabled, then we need to change pages for
    // this section of code
    uint8_t savedPage = SFRPAGE;
    SFRPAGE = SPI_SFR_PAGE;
    SPI0FCN0 |= SPI0FCN0_RFLSH__FLUSH;
    SFRPAGE = savedPage;
  }
#endif

  // Clear all the interrupt flags
  SPI0CN0 &= ~0xF0;

  // Set up the interrupt to use the FIFO request levels instead of SPIF
  SPI0FCN1 &= ~SPI0FCN1_SPIFEN__BMASK;
  SPI0FCN0 |= SPI0FCN0_RFRQE__ENABLED;

  // assert NSS (if used)
  if (modeIsMaster && useNss)
  {
    SPI0CN0_NSSMD0 = 0;
  }

#if EFM8PDL_SPI0_USE_PIPELINE == 0
  // Write the first byte to get the transfer started
  if (SPI0CN0_TXNF && txCountRemaining)
  {
    // If user provided tx data, then use that
    if (useTx)
    {
      SPI0DAT = *pTxBuf;
      ++pTxBuf;
    }

    // Otherwise no tx data, so just stuff zeroes
    else
    {
      SPI0DAT = 0;
    }
    --txCountRemaining;
  }
#else
  // Stuff as many bytes as we can in the tx buffer to start.
  while (SPI0CN0_TXNF && txCountRemaining)
  {
    // If user provided tx data, then use that
    if (useTx)
    {
      SPI0DAT = *pTxBuf;
      ++pTxBuf;
    }

    // Otherwise no tx data, so just stuff zeroes
    else
    {
      SPI0DAT = 0;
    }
    --txCountRemaining;
  }
#endif

  RESTORE_PAGE();
  // At this point SPI should be running and the rest will be handled
  // in the interrupt service routine
}

// ----------------------------------------------------------------------------
// Stop a running SPI transfer.
// ----------------------------------------------------------------------------
void SPI0_abortTransfer(void)
{
  DECL_PAGE;

  // Resetting the counters will cause the ISR to ignore any remaining
  // SPI interrupts.
  txCountRemaining = 0;
  rxCountRemaining = 0;
  useTx = false;
  useRx = false;
  pTxBuf = NULL;
  pRxBuf = NULL;

  SET_PAGE(SPI_SFR_PAGE);

  // drop the chip select if used
  if (modeIsMaster && useNss)
  {
    SPI0CN0_NSSMD0 = 1;
  }

  // Flush buffers
  SPI0CN0_SPIEN = 0;
  SPI0FCN0 |= SPI0FCN0_RFLSH__FLUSH | SPI0FCN0_TFLSH__FLUSH;
  SPI0CN0_SPIEN = 1;

  RESTORE_PAGE();
}

// ----------------------------------------------------------------------------
// Get the number of bytes remaining in the transfer.  This will really
// be the number of RX bytes.
// ----------------------------------------------------------------------------
uint8_t SPI0_bytesRemaining(void)
{
  return bytesRemaining;
}

// ----------------------------------------------------------------------------
// Handler for interrupt driven SPI data transfers.
// ----------------------------------------------------------------------------
SI_INTERRUPT(SPI0_ISR, SPI0_IRQn)
{
  uint8_t intFlags;
  uint8_t fifoFlags;

  // This device has SFRPAGE autosave so we can change page here and
  // it will automatically be restored when interrupt exits
  SFRPAGE = SPI_SFR_PAGE;

  // Get the interrupt flags and then clear any that are pending
  intFlags = SPI0CN0 & 0xF0;
  SPI0CN0 = (SPI0CN0 & (~intFlags | 0x0F));
  // we are not using the normal interrupt flags for anything
  // in this ISR

  // Get the FIFO request flags
  fifoFlags = SPI0FCN1;

  // If either FIFO request flag is set, it means that there is
  // either more data to read or write, or both.  So just try
  // to read and write as much as we can at this time.
  if (fifoFlags & SPI0FCN1_RFRQ__BMASK)
  {
    // Read bytes as long as the read count is non-zero and there
    // are more bytes in the RX buffer
#if EFM8PDL_SPI0_USE_PIPELINE == 1
    while (rxCountRemaining && !(SPI0CFG & SPI0CFG_RXE__BMASK))
#else
    if (rxCountRemaining && !(SPI0CFG & SPI0CFG_RXE__BMASK))
#endif
    {
      // If the user provided an RX buffer then read a byte into that.
      if (useRx)
      {
        *pRxBuf = SPI0DAT;
        ++pRxBuf;
      }

      // Else, user does not care about RX data so do a dummy read.
      else
      {
        uint8_t dummy = SPI0DAT;
      }
      --rxCountRemaining;

      // If we get to zero remaining, it means that all the
      // bytes have been transferred.
      if (rxCountRemaining == 0)
      {
        // deassert NSS (if used)
        if (modeIsMaster && useNss)
        {
          SPI0CN0_NSSMD0 = 1;
        }
        // Tell user that the transfer is complete.
        SPI0_transferCompleteCb();
      }

      // If there are more RX bytes to receive, then remember the
      // current count to be used by _bytesRemaining()
      else
      {
        bytesRemaining = rxCountRemaining;
      }
    }

    // Write bytes if there are more TX bytes to send and the
    // TX buffer is not full
#if EFM8PDL_SPI0_USE_PIPELINE == 1
    while (txCountRemaining && SPI0CN0_TXNF)
#else
    if (txCountRemaining && SPI0CN0_TXNF)
#endif
    {
      // If user provided a TX buffer then write the next byte
      if (useTx)
      {
        SPI0DAT = *pTxBuf;
        ++pTxBuf;
      }

      // Otherwise user did not provide a buffer so just write a zero.
      else
      {
        SPI0DAT = 0;
      }
      --txCountRemaining;
    }
  }

#if EFM8PDL_SPI0_USE_ERR_CALLBACK == 1
  // Check for errors and notify user
  if (intFlags & (SPI0_MODF_IF | SPI0_RXOVR_IF))
  {
    // Note, the RXOVRN bit only happens in slave mode, and the MODF
    // bit is not very likely, so in master mode this block will
    // probably not ever be used.
    SPI0_transferErrorCb(intFlags & (SPI0_MODF_IF | SPI0_RXOVR_IF));
  }
#endif // EFM8PDL_SPI0_USE_ERR_CALLBACK
}

#endif // EFM8PDL_SPI0_USE_BUFFER

/** @} (end spi_0_group) */
