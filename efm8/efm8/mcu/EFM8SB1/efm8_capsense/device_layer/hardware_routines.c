/**************************************************************************//**
 * Copyright (c) 2014 by Silicon Laboratories Inc. All rights reserved.
 *
 * (C) Copyright 2014 Silicon Labs Inc,
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifdef FFD
#include "config_profile.h"
#include "low_power_config.h"
#else
#include "cslib_hwconfig.h"
#include "cslib_config.h"
#include "low_power_config.h"
#endif

#include "cslib.h"
#include "hardware_routines.h"


#include "SI_EFM8SB1_Defs.h"

void gotoIdleStateAutoGround(void);
void gotoScanStateAutoGround(void);

void configureCS0ActiveMode(void);
void configurePortsActiveMode(void);

/**************************************************************************//**
 * update mux
 *
 * Low level access to the CS0MUX register.  This is called by scanSensor().
 *
 *****************************************************************************/
void setMux(uint8_t muxValue)
{
  CS0MX = muxValue;
}

/**************************************************************************//**
 * Configure gain setting
 *
 * Low level access to the gain bits.  This is called by scanSensor().
 *
 *****************************************************************************/
void setGain(uint8_t gainValue)
{
  CS0MD1 &= ~0x07;
  CS0MD1 |= 0x07 & gainValue;          // clear all bits except gain bits
}

/**************************************************************************//**
 * Return gain setting
 *
 * Returns the gain bits of the sensor.
 *
 *****************************************************************************/
uint8_t readGain(void)
{
  return CS0MD1 & 0x07;
}

/**************************************************************************//**
 * Return mux value
 *
 * Returns the mux value from the sensor peripheral.
 *
 *****************************************************************************/
uint8_t readMux(void)
{
  return CS0MX;
}

/**************************************************************************//**
 * Configure accumulation
 *
 * Sets hardware accumulator for CS0.
 *
 *****************************************************************************/
void setAccumulation(uint8_t accumulation)
{
  CS0CF = 0x07 & accumulation;         // Clear all bits except accumulation
}

/**************************************************************************//**
 * Execute one CS0 conversion
 *
 * Assumes that the performance characteristics of the sensor have already
 * been configured.  Enables the sensor, starts a scan, blocks until
 * the scan is complete.
 *
 *****************************************************************************/
uint16_t CSLIB_executeConversionCB(void)
{

  SI_UU16_t scanResult;

  CS0CN0 = 0x88;                           // Enable CS0, Enable Digital Comparator

  CS0CN0 &= ~0x20;                         // Clear the CS0 INT flag

  CS0CN0 |= 0x10;                          // Set CS0BUSY to begin conversion

#if DEF_SLEEP_MODE_ENABLE
  // disable_sleep_and_stall is controlled by low power routines if device- and
  // component positions are met.  If any component needs the device
  // to not fall to suspend mode during conversion, this conditional fails
  if (disable_sleep_and_stall == 0)
  {
    PMU0FL = 0x01;
    PMU0CF = 0x40;                        // Enter suspend until conversion completes
  }
#endif

  while (!(CS0CN0 & 0x20))
  {                                     // Wait in foreground
  }
  scanResult.u8[MSB] = CS0DH;             // Read Result
  scanResult.u8[LSB] = CS0DL;

  CS0CN0 = 0x00;                           // Disable CS0

#if DEF_SLEEP_MODE_ENABLE
  // If device did go into suspend mode, check RTC state to determine if 1 ms
  // tick has happened and reset RTC for next tick
  if (disable_sleep_and_stall == 0)
  {
    CSLIB_checkTimerCB();
  }
#endif
  return scanResult.u16;
}

/**************************************************************************//**
 * Ready CS0 for active mode, unbound sensor scanning
 *
 * This is a top-level call to configure the sensor to its operational state
 * during active mode.
 *
 *****************************************************************************/
void CSLIB_configureSensorForActiveModeCB(void)
{
  configurePortsActiveMode();
  configureCS0ActiveMode();
}

/**************************************************************************//**
 * Ready CS0 for active mode, unbound sensor scanning
 *
 * This is a top-level function that assumes there is a sensor node struct
 * with CS0-related controls.  This is called by the library to execute
 * one scan of one sensor node.  Note that the sensor output is returned
 * and not saved to buffers in this routine.  Saving is the responsibility
 * of the library routines.
 *
 *****************************************************************************/
uint16_t CSLIB_scanSensorCB(uint8_t nodeIndex)
{
  uint16_t ret_val;
  setMux(CSLIB_muxValues[nodeIndex]);
  setGain(CSLIB_gainValues[nodeIndex]);

  // If baseline = 0, no scans have happened and we must be in baseline
  // initialization routine.  If baseline is non-zero, then we are
  // already initialized
  if (CSLIB_node[nodeIndex].currentBaseline != 0)
  {
    setAccumulation(CSLIB_accumulationValues[nodeIndex]);
  }
  else
  {
    // this only occurs during startup or if a baseline is reset,
    // forces highest accumulation to get the cleanest sample to init baseline
	// Sets accumulator to 32x
    setAccumulation(0x04);
  }
  gotoScanStateAutoGround();
  ret_val = CSLIB_executeConversionCB();
  gotoIdleStateAutoGround();
  return ret_val;
}

/**************************************************************************//**
 * CS0 input auto-ground
 *
 * Gives code a chance to short non-scanning input pins to ground.  It
 * was determined in testing that shorting to ground couples more noise into
 * the sensor than leaving sensors as analog inputs.
 *
 *****************************************************************************/
void gotoIdleStateAutoGround(void)
{
  // Configure all capsenes inputs to analog input to minimize interference
  // coupling
  P0MDIN &= ~ACTIVE_MODE_MASK_P0;
  P1MDIN &= ~ACTIVE_MODE_MASK_P1;
}
/**************************************************************************//**
 * Scan state for auto-ground system
 *
 * Function used to enable sensor about to be scanned as analog input,
 * leaving all other sensors as open drain outputs.  During testing it
 * was determined that this coupled more noise into sensors and so now
 * all capsense inputs are always analog input.
 *
 *****************************************************************************/
void gotoScanStateAutoGround(void)
{
}

/**************************************************************************//**
 * Configure CS0 block for active scanning
 *
 * Configure capsense input block for unbound, sensor-by-sensor scanning.
 *
 *****************************************************************************/
void configureCS0ActiveMode(void)
{

  CS0CF = 0x00;                        // Clear CS0CF

  CS0MD2 &= 0xC0;                      // Configure for 16-bit conversions
  CS0MD2 |= 0xC0;                      // and CS0 discharge time of 1.5 uS
  CS0MD2 &= ~0x38;
  CS0MD2 |= 0x18;

  CS0THH = 0;                         // Set threshold to 0 to always wake
  CS0THL = 0;                         // from suspend mode with comparator

  CS0SCAN0 = 0;                       // Clear all channel binding
  CS0SCAN1 = 0;

  CS0MD1 |= 0x10;                      // Enable double reset
  CS0CN0 = 0x88;                        // Enable CS0, Enable Digital Comparator

  CS0CN0 &= ~0x20;

  // A single conversion is executed during initialization because
  // it was seen that the first sample after exiting sleep had bit errors
  CS0CN0 |= 0x10;                       // Set CS0BUSY to begin conversion
  while (!(CS0CN0 & 0x20))
  {
    ;                                  // Wait in foreground

  }
  CS0CN0 = 0x00;                        // Disable CS0

}

/**************************************************************************//**
 * Capsense input configuration for active mode
 *
 * Configure CS0 block for active scanning.  This configures all capsense
 * inputs for the part to analog input mode, regardless of whether they
 * are enabled by the config profile or validated at runtime.
 *
 *****************************************************************************/
void configurePortsActiveMode(void)
{
  P0 &= ~ACTIVE_MODE_MASK_P0;
  P1 &= ~ACTIVE_MODE_MASK_P1;

  gotoIdleStateAutoGround();

}

/**************************************************************************//**
 * Find highest valid gain setting
 *
 * @returns CS0MD1 gain setting that is valid
 *
 * Executed before entering sleep mode.  used to find highest gain setting
 * possible for all bound CS0 inputs without saturating sensor and gives
 * margin for sleep touch qualification.
 *
 *****************************************************************************/
uint8_t determine_highest_gain(void)
{
  uint8_t index;
  // Step through all gain settings until valid one is found
  for (index = 0; index < 8; index++)
  {
	// Start at highest gain and decrement
    setGain(7 - index);
    // If sensor isn't saturated and there is sufficent margin, stop
    if (CSLIB_executeConversionCB() < 0xFFFF - 1000)
    {
      break;
    }
  }
  // Catch case in above loop where it could avoid the break and
  // return an index incremented to an invalid value
  if (index == 8)
  {
    return 0;
  }
  else
  {
    return (7 - index);
  }
}
void CSLIB_baselineInitEnableCB(void)
{
  // Stub for this build because baseline config is the same as active mode config
}

void CSLIB_baselineInitDisableCB(void)
{
  // Stub for this build because baseline config is the same as active mode config
}
