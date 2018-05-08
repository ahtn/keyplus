/******************************************************************************
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "efm8_device.h"
#include "flash.h"

// Holds the flash keys received in the prefix command
uint8_t flash_key1;
uint8_t flash_key2;

// Holds the running CRC16 value
uint16_t flash_crc;

// ----------------------------------------------------------------------------
// Reads one byte from flash memory.
// ----------------------------------------------------------------------------
uint8_t flash_readByte(uint16_t addr)
{
  return *((uint8_t SI_SEG_CODE *)addr);
}

// ----------------------------------------------------------------------------
// Writes one byte to flash memory.
// ----------------------------------------------------------------------------
void writeByte(uint16_t addr, uint8_t byte)
{
  uint8_t SI_SEG_XDATA * pwrite = (uint8_t SI_SEG_XDATA *) addr;

  // Enable VDD monitor and set it as a reset source
  VDM0CN |= VDM0CN_VDMEN__ENABLED;
  RSTSRC = RSTSRC_PORSF__SET;

  // Unlock flash by writing the key sequence
  FLKEY = flash_key1;
  FLKEY = flash_key2;

  // Enable flash writes, then do the write
  PSCTL |= PSCTL_PSWE__WRITE_ENABLED;
  *pwrite = byte;
  PSCTL &= ~(PSCTL_PSEE__ERASE_ENABLED|PSCTL_PSWE__WRITE_ENABLED);
}

// ----------------------------------------------------------------------------
// Erases one page of flash memory.
// ----------------------------------------------------------------------------
void flash_erasePage(uint16_t addr)
{
  // Enable flash erasing, then start a write cycle on the selected page
  PSCTL |= PSCTL_PSEE__ERASE_ENABLED;
  writeByte(addr, 0);
}

// ----------------------------------------------------------------------------
// Writes one byte to flash memory.
// ----------------------------------------------------------------------------
void flash_writeByte(uint16_t addr, uint8_t byte)
{
  // Don't bother writing the erased value to flash
  if (byte != 0xFF)
  {
    writeByte(addr, byte);
  }
}

// ----------------------------------------------------------------------------
// Check if flash address range may be erased or written.
// ----------------------------------------------------------------------------
bool flash_isValidRange(uint16_t addr, uint8_t size)
{
  // Test address range against the upper flash limit for this device
  if ((addr < BL_LIMIT_ADDRESS) && (addr + size <= BL_LIMIT_ADDRESS))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// ----------------------------------------------------------------------------
// Updates a running CRC with the provided byte.
// ----------------------------------------------------------------------------
#define POLY 0x1021       // CRC16-CCITT (X^16+X^12+X^5+1)

void flash_updateCRC(uint8_t byte)
{
  uint8_t i, msb;

  // Use polynomial arithmetic (binary arithmetic with no carries) to divide 
  // the POLY into a dividend formed from the incoming data. flash_crc holds 
  // the "remainder" of each divide. 

  // Create the CRC "dividend"
  flash_crc = flash_crc ^ (byte << 8);

  // "Divide" the POLY into the dividend using CRC XOR subtraction for each
  // bit of the incoming data byte
  for (i = 8; i; i--)
  {
    // Save the MSB and shift the CRC value
    msb = flash_crc >> 8;
    flash_crc = flash_crc << 1;
    
    // If MSB was 1, then the POLY can "divide" into the "dividend"
    if (msb & 0x80)
    {
      // XOR "subtract" the POLY
      flash_crc ^= POLY;
    }
  }
}
