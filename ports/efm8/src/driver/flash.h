/******************************************************************************
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __FLASH_H__
#define __FLASH_H__

extern uint16_t flash_crc;
extern uint8_t flash_key1;
extern uint8_t flash_key2;

/**************************************************************************//**
 * Initialize the CRC register.
 *****************************************************************************/
#if defined(IS_DOXYGEN)
extern void flash_initCRC(void);
#else
#define flash_initCRC(x) \
  do { flash_crc=0; } while(0)
#endif

/**************************************************************************//**
 * Update the CRC with the passed value.
 *
 * @param byte The CRC will be updated using this data byte
 *****************************************************************************/
extern void flash_updateCRC(uint8_t byte);

/**************************************************************************//**
 * Return the CRC register value.
 *
 * @return The current value of the CRC register
 *****************************************************************************/
#if defined(IS_DOXYGEN)
extern uint16_t flash_readCRC(void);
#else
#define flash_readCRC(x) (flash_crc)
#endif

/**************************************************************************//**
 * Set the flash key codes.
 *
 * @param key1 First flash unlock key code.
 * @param key2 Second flash unlock key code.
 *****************************************************************************/
#if defined(IS_DOXYGEN)
extern void flash_setKeys(uint8_t key1, uint8_t key2);
#else
#define flash_setKeys(key1, key2) \
  do { flash_key1=(key1); flash_key2=(key2); } while(0)
#endif

/**************************************************************************//**
 * Selects the active flash bank for erase, write and verify.
 *
 * @param bank Requested flash bank.
 *****************************************************************************/
#if defined(IS_DOXYGEN)
extern void flash_setBank(uint8_t bank);
#else
#define flash_setBank(x)
#endif

/**************************************************************************//**
 * Check if flash address range may be erased or written.
 *
 * @param addr Start address of range to check.
 * @param size Size of address range to check.
 * @return **True** if the address is writeable, or **false** if the address 
 * is write protected
 *****************************************************************************/
extern bool flash_isValidRange(uint16_t addr, uint8_t size);

/**************************************************************************//**
 * Erase the flash page the contains the specified address.
 *
 * @param addr Flash address that lies within the page to erase.
 *****************************************************************************/
extern void flash_erasePage(uint16_t addr);

/**************************************************************************//**
 * Read one byte from flash.
 *
 * @param addr Flash address that will be read.
 * @return Data value that was read.
 *****************************************************************************/
extern uint8_t flash_readByte(uint16_t addr);

/**************************************************************************//**
 * Write one byte to flash.
 *
 * @param addr Flash address that will be written.
 * @param byte Data value that will be written.
 *****************************************************************************/
extern void flash_writeByte(uint16_t addr, uint8_t byte);

#endif // __FLASH_H__
