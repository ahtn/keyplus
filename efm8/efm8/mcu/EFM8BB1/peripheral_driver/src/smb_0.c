/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "smb_0.h"
#include "assert.h"

#define ALL_FLAGS  SMB0_TXMODE_SF \
                   | SMB0_START_SF \
                   | SMB0_STOP_SF \
                   | SMB0_ACKREQ_SF \
                   | SMB0_ARBLOST_SF \
                   | SMB0_ACK_SF

bool SMB0_getIntFlag()
{
  return SMB0CN0_SI;
}

void SMB0_clearIntFlag()
{
  SMB0CN0_SI = 0;
}

SI_REENTRANT_FUNCTION(SMB0_getStatusFlag, uint8_t, (uint8_t flag))
{
  return SMB0CN0 & flag;
}

SI_REENTRANT_FUNCTION(SMB0_setStatusFlag, void, (uint8_t flag, uint8_t state))
{
  if (state)
  {
    SMB0CN0 |= flag;
  }
  else
  {
    SMB0CN0 &= ~flag;
  }
}

uint8_t SMB0_read()
{
  return SMB0DAT;
}

void SMB0_write(uint8_t value)
{
  SMB0DAT = value;
}

void SMB0_abort()
{
  SMB0CF &= ~SMB0CF_ENSMB__BMASK;
  SMB0CF |= SMB0CF_ENSMB__BMASK;
  SMB0CN0 &= ~(SMB0CN0_STA__BMASK
      | SMB0CN0_STO__BMASK
      | SMB0CN0_ACKRQ__BMASK);
}

void SMB0_ack(bool ack)
{
  SMB0CN0_ACK = ack;
}

void SMB0_start()
{
  SMB0CN0_STA = 1;
}

void SMB0_stop()
{
  SMB0CN0_STO = 1;
}

void SMB0_init(SMB0_Timebase_t timebase, bool sclLow) {
  SMB0CF &= ~(SMB0CF_SMBCS__FMASK | SMB0CF_SMBTOE__BMASK);
  SMB0CF |= timebase
            | SMB0CF_ENSMB__ENABLED
            | SMB0CF_INH__SLAVE_DISABLED
            | SMB0CF_SMBFTE__FREE_TO_ENABLED
            | (uint8_t) sclLow << SMB0CF_SMBTOE__SHIFT;
  SMB0ADM |= SMB0ADM_EHACK__ADR_ACK_AUTOMATIC;
}

void SMB0_initSlaveAddress(uint8_t address, uint8_t mask) {
  SMB0CF  &= ~SMB0CF_INH__BMASK;
  SMB0ADR = address;
  SMB0ADM = mask | SMB0ADM_EHACK__BMASK;
}

void SMB0_reset() {
  SMB0CF  = 0x0;
  SMB0TC  = 0x0;
  SMB0CN0  = 0x0;
  SMB0ADR = 0x0;
  SMB0ADM = 0x0;
}

#if EFM8PDL_SMB0_USE_STATEMACHINE == 1
SI_INTERRUPT_PROTO(SMB0_ISR, SMBUS0_IRQn);
SI_INTERRUPT(SMB0_ISR, SMBUS0_IRQn)
{
  if(SMB0CN0_ARBLOST) {
    SMB0_arbLostCb(SMB0CN0 & 0xF0);
  }

  // Normal operation
  switch (SMB0CN0 & 0xF0)// Status vector
  {
    // SMB0CN0_MASTER ---------------------------------------------------------------

    // Master Transmitter/Receiver: START condition transmitted.
    case SMB0_MASTER_START:
      SMB0_startCb();
      SMB0CN0_STA = 0;
      break;

    // Master Transmitter: Data byte transmitted
    case SMB0_MASTER_TXDATA:
      SMB0_TxDataCb(true, SMB0CN0_ACK);
      break;

    // Master Receiver: byte received
    case SMB0_MASTER_RXDATA:
      SMB0_RxDataCb(true);
      break;

    case SMB0_SLAVE_TXDATA:
      SMB0_TxDataCb(false, SMB0CN0_ACK);
      break;

    case SMB0_SLAVE_ADDRESS:
      if(SMB0CN0_ARBLOST)
      {
        SMB0_arbLostCb(SMB0CN0 & 0xF0);
      }
      else
      {
        SMB0_addressCb();
      }
      SMB0CN0_STA = 0;  // Clear SMB0CN0_STA bit
      break;
                                      // Slave Receiver: Data received
    case SMB0_SLAVE_RXDATA:
      SMB0_RxDataCb(false);
      break;

                                      // Slave Receiver: Stop received while either a Slave Receiver or Slave
                                      // Transmitter
    case SMB0_SLAVE_RX_STOP:
    case SMB0_SLAVE_TX_STOP:
      SMB0_stopCb();
      SMB0CN0_STO = 0;
      break;

    default:
      break;

  } // end switch

  //Need an SMBus Restart?
  SMB0CN0_SI = 0;// Clear interrupt flag
}
#endif //EFM8PDL_SMB0_USE_STATEMACHINE

#if EFM8PDL_SMB0_USE_BUFFER == 1

SI_SEGMENT_VARIABLE(mAddress, uint8_t, SI_SEG_XDATA);
SI_SEGMENT_VARIABLE(mTxCount, uint8_t, SI_SEG_XDATA);
SI_SEGMENT_VARIABLE(mRxCount, uint8_t, SI_SEG_XDATA);
SI_SEGMENT_VARIABLE_SEGMENT_POINTER(mTxBuffer, uint8_t, EFM8PDL_SMB0_RX_BUFTYPE,
    SI_SEG_XDATA);
SI_SEGMENT_VARIABLE_SEGMENT_POINTER(mRxBuffer, uint8_t, EFM8PDL_SMB0_TX_BUFTYPE,
    SI_SEG_XDATA);

SI_SEGMENT_VARIABLE(sRxSize, uint8_t, SI_SEG_XDATA);
SI_SEGMENT_VARIABLE(sRxCount, uint8_t, SI_SEG_XDATA);
SI_SEGMENT_VARIABLE(sTxCount, uint8_t, SI_SEG_XDATA);
SI_SEGMENT_VARIABLE_SEGMENT_POINTER(sRxBuffer, uint8_t, EFM8PDL_SMB0_RX_BUFTYPE,
    SI_SEG_XDATA);
SI_SEGMENT_VARIABLE_SEGMENT_POINTER(sTxBuffer, uint8_t, EFM8PDL_SMB0_TX_BUFTYPE,
    SI_SEG_XDATA);

SI_SEGMENT_VARIABLE(smbBusy, bool, SI_SEG_IDATA);
SI_SEGMENT_VARIABLE(smbReq, bool, SI_SEG_IDATA);
SI_SEGMENT_VARIABLE(smbReceive, bool, SI_SEG_IDATA);
SI_SEGMENT_VARIABLE(mRetries, uint8_t, SI_SEG_XDATA);

void SMB0_transfer(uint8_t address,
    SI_VARIABLE_SEGMENT_POINTER(txBuffer, uint8_t, EFM8PDL_SMB0_TX_BUFTYPE),
    SI_VARIABLE_SEGMENT_POINTER(rxBuffer, uint8_t, EFM8PDL_SMB0_RX_BUFTYPE),
    uint8_t tx_len, uint8_t rx_len) {

  //Setup transfer
  mAddress = address;
  mTxBuffer = txBuffer;
  mRxBuffer = rxBuffer;
  mTxCount = tx_len;
  mRxCount = rx_len;
  mRetries = EFM8PDL_SMB0_MASTER_RETRIES;

  if (smbBusy) {
    smbReq = true;
  } else {
    //Start transfer
    SMB0CN0_STA = 1;
  }
}

void SMB0_abortTransfer(){
  mTxCount = 0;
  mRxCount = 0;
  sTxCount = 0;
  
  smbBusy = false;
  smbReq = false;
}

uint8_t SMB0_txBytesRemaining() {
  return mTxCount;
}

uint8_t SMB0_rxBytesRemaining() {
  return mRxCount;
}

void SMB0_initSlave(uint8_t address,
                    SI_VARIABLE_SEGMENT_POINTER(commandBuffer, uint8_t, EFM8PDL_SMB0_RX_BUFTYPE), uint8_t length) {
  SMB0CF  &= ~SMB0CF_INH__BMASK;
  SMB0ADR = address;
  SMB0ADM = 0xFF | SMB0ADM_EHACK__BMASK;
  sRxBuffer = commandBuffer;
  sRxSize = length;
  sRxCount = 0;
}

uint8_t SMB0_getCommandLength() {
  return sRxCount;
}

void SMB0_sendResponse(
    SI_VARIABLE_SEGMENT_POINTER(dataBuffer, uint8_t, EFM8PDL_SMB0_TX_BUFTYPE),
    uint8_t length) {
  sTxBuffer = dataBuffer;
  sTxCount = length;
}

SI_INTERRUPT_PROTO(SMB0_ISR, SMBUS0_IRQn);

SI_INTERRUPT(SMB0_ISR, SMBUS0_IRQn)
{

  // Jump to status vector handler
  switch (SMB0CN0 & 0xF0)
  {
  // Master Transmitter/Receiver: START condition transmitted.
  case SMB0_MASTER_START:
    //Send address. If no tx data then initiate read.
    SMB0DAT = mAddress;
    if (!mTxCount)
    {
      SMB0DAT |= 0x01;
    }
    smbReceive = SMB0DAT & 0x01;

    //tailchain: clear_start;
    SMB0CN0_STA = 0;
    smbBusy = true;
    break;

  // Master Transmitter: Data byte transmitted
  case SMB0_MASTER_TXDATA:
    if (SMB0CN0_ACK)
    {
      if (smbReceive)
      {
        //Handle read transfer
        if(!--mRxCount)
        {
          SMB0CN0_ACK = 0; //ack for first data received byte
        }
        //ACK = 1 by default so no need to set it
      }
      else
      {
        //Handle writes
        if (mTxCount)
        {
          //if data remains in tx buffer send next byte
          SMB0DAT = *mTxBuffer++;
          mTxCount--;
        }
        else
        {
          //Handle writes finished
          if (mRxCount)
          {
            //if tx done and rx remaining do repeated start
            SMB0CN0_STA = 1;
          }
          else
          {
            //if tx done and no rx then stop
            //tailchain: stop_seq
            SMB0_transferCompleteCb();
            SMB0CN0_STO = 1;
            SMB0CN0_STA = smbReq;
            smbReq = false;
            smbBusy = false;
          } // if rxCount else
        }   //if txCount else
      }     //if ! rxReceive (rxReceive = ack of address so ignore)
    }       // if ACK
    else
    {
      //Error on NAC
      SMB0_errorCb(SMB0_NACK_ERROR);

      //tailchain: stop_seq
      SMB0CN0_STO = 1;
      SMB0CN0_STA = smbReq; //necessary for tailchain
      smbReq = false; //necessary for tailchain
      smbBusy = false;
    }
    break;

  // Master Receiver: byte received
  case SMB0_MASTER_RXDATA:
    //Read in data we just received
    *mRxBuffer++ = SMB0DAT;

    //if bytes remain read this one and set up for next one
    if (mRxCount)
    {
      //NACK if the byte we are about to read is our last
      if (!--mRxCount)
      {
        SMB0CN0_ACK = 0;
      }
      //ACK =1  by default so no need to set it.
    }
    else
    {
      SMB0CN0_ACK = 0;

      // If no bytes remain notify user xfer complete and issue stop.
      //tailchain: stop_seq
      SMB0_transferCompleteCb();
      SMB0CN0_STO = 1;
      SMB0CN0_STA = smbReq;
      smbReq = false;
      smbBusy = false;
    }
    break;

  // Slave Transmitter: Data byte transmitted
  case SMB0_SLAVE_TXDATA:
    if(SMB0CN0_ACK)
    {
      if(--sTxCount)
      {
        SMB0DAT = *sTxBuffer++;
      }
      else
      {
        SMB0_errorCb(SMB0_TXUNDER_ERROR);
      }
    }
    break;

  // Slave Receiver: Start+Address received
  case SMB0_SLAVE_ADDRESS:
    if(SMB0CN0_ARBLOST)
    {
      if(mRetries--)
      {
        smbReq = true;
      }
      else
      {
        SMB0_errorCb(SMB0_ARBLOST_ERROR);
      }
    }

    smbReceive = !(SMB0DAT & 0x01);
    // Nack defaults to 1 so no need to set it

    //Clear receive count if we are about to receive OR
    // if we have no rx phase (we are a write only xfer)
    // We leave rxCount alone if this is a repeated start
    if(smbReceive || !smbBusy)
    {
      sRxCount = 0;
    }

    // If this is a read then fire command received
    // either a read or a repeated start has been requested
    if (!smbReceive) {
    	// If rx buffer overflowed then commandReceivedCb all ready fired
    	if(sRxCount || !smbBusy){
        //Issue a command received callback if there is RX data or if this
        // is not a repeated start
        SMB0_commandReceivedCb();
      }

      SMB0DAT = *sTxBuffer++;
      //DO NOT dec sTxSize This is handled AFTER the first byte is transmitted
    }

    //tailchain: clear_start
    SMB0CN0_STA = 0;
    smbBusy = true;
    break;

  // Slave Receiver: Data received
  case SMB0_SLAVE_RXDATA:
    //Read data into buffer
    sRxBuffer[sRxCount++] = SMB0DAT;

    //If buffer is about to overflow callback user and reset buffer
    if (sRxCount == sRxSize)
    {
      SMB0_commandReceivedCb();
      sRxCount = 0;
    }

    //ACK = 1 by default so no need to set it
    break;

  // Slave Receiver: Stop received while either a Slave Receiver or Transmitter
  case SMB0_SLAVE_RX_STOP:
  case SMB0_SLAVE_TX_STOP:
    if (smbReceive && sRxCount)
    {
    	//Fire callback only if there is data in the buffer
      SMB0_commandReceivedCb();
    }

    //clear stop
    SMB0CN0_STO = 0;

    //If master request pending send a start.
    //tailchain: stop_seq
    SMB0CN0_STA = smbReq;
    smbReq = false;
    smbBusy = false;
    break;

  default:
    // All other cases are an error
    SMB0_errorCb(SMB0_UNKNOWN_ERROR);
    // ----------------------------------------------------------------------
  } // end switch

  //Clear interrupt flag
  SMB0CN0_SI = 0;

}

#endif //EFM8PDL_SMB0_USE_BUFFER
