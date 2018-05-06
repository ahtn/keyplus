/******************************************************************************
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "efm8_config.h"
#include "SI_EFM8UB2_Register_Enums.h"
#include "spi_0.h"

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

// ----------------------------------------------------------------------------
// Write a byte if transmit buffer is not full.
// ----------------------------------------------------------------------------
bool SPI0_writeByte(uint8_t value)
{
  bool ret = false;
  // check to see if transmit buffer is not full
  if (SPI0CN0_TXBMT)
  {
    SPI0DAT = value;
    ret = true;
  }
  return ret;
}

// ----------------------------------------------------------------------------
// Write a byte, waiting for transmit buffer to be empty
// ----------------------------------------------------------------------------
void SPI0_pollWriteByte(uint8_t value)
{
  // wait for TX empty
  while (!SPI0CN0_TXBMT)
  {}

  SPI0DAT = value;
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
  {
    uint8_t dummy = SPI0DAT;
  }

  // Clear the interrupt flag that is used to indicate transfer complete
  SPI0CN0_SPIF = 0;

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
    if (SPI0CN0_TXBMT && txCount)
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

    // If the interrupt flag is set it means a transfer has completed
    // so read a byte
    if (SPI0CN0_SPIF)
    {
      SPI0CN0_SPIF = 0;

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

  return xferCount;
}

// ----------------------------------------------------------------------------
// Check if SPI is busy with a transfer in progress.
// ----------------------------------------------------------------------------
bool SPI0_isBusy(void)
{
  uint8_t count = 0;
  bool ret = false;

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
  return ret;
}

// ----------------------------------------------------------------------------
// Initialize the SPI peripheral operating parameters
// ----------------------------------------------------------------------------
void SPI0_init(SPI0_ClockMode_t clockMode, bool isMasterMode, bool is4wire)
{
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
}

// ----------------------------------------------------------------------------
// Set the clock divider used to determine SPI clock rate
// ----------------------------------------------------------------------------
void SPI0_setClockDivider(uint16_t divider)
{
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
  SPI0CN0_SPIEN = 0;
  SPI0CKR = (uint8_t)divider;
  SPI0CN0_SPIEN = 1;
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
  rxCountRemaining = xferCount;
  txCountRemaining = xferCount;
  bytesRemaining = xferCount;
  pTxBuf = pTxBuffer;
  pRxBuf = pRxBuffer;
  useRx = dir & SPI0_TRANSFER_RX;
  useTx = dir & SPI0_TRANSFER_TX;

  // Check to see if run-time mode variables have been set up
  if (!initIsValid)
  {
    SPI0_internalInit();
  }

  // Flush the RX buffer in case something is in there
  {
    uint8_t dummy = SPI0DAT;
  }

  // Clear all the interrupt flags
  SPI0CN0 &= ~0xF0;

  // assert NSS (if used)
  if (modeIsMaster && useNss)
  {
    SPI0CN0_NSSMD0 = 0;
  }

#if EFM8PDL_SPI0_USE_PIPELINE == 0
  // Write the first byte to get the transfer started
  if (SPI0CN0_TXBMT && txCountRemaining)
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
  while (SPI0CN0_TXBMT && txCountRemaining)
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

  // At this point SPI should be running and the rest will be handled
  // in the interrupt service routine
}

// ----------------------------------------------------------------------------
// Stop a running SPI transfer.
// ----------------------------------------------------------------------------
void SPI0_abortTransfer(void)
{
  // Resetting the counters will cause the ISR to ignore any remaining
  // SPI interrupts.
  txCountRemaining = 0;
  rxCountRemaining = 0;
  useTx = false;
  useRx = false;
  pTxBuf = NULL;
  pRxBuf = NULL;

  // drop the chip select if used
  if (modeIsMaster && useNss)
  {
    SPI0CN0_NSSMD0 = 1;
  }
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

  // Get the interrupt flags and then clear any that are pending
  intFlags = SPI0CN0 & 0xF0;
  SPI0CN0 = (SPI0CN0 & (~intFlags | 0x0F));

  // Handle completion of one frame (byte) of data transferred.
  // This means we are ready to read a received byte, and write
  // the next TX byte.
  if (intFlags & SPI0_INT_IF)
  {
    // Read bytes as long as the read count is non-zero
    if (rxCountRemaining)
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
    if (txCountRemaining && SPI0CN0_TXBMT)
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
