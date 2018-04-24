/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "cslib_config.h"
#include "cslib.h"
#include "hardware_routines.h"
#include "cslib_hwconfig.h"
#include "SI_C8051F970_Defs.h"





//-----------------------------------------------------------------------------
// Local function prototypes
//-----------------------------------------------------------------------------
void gotoIdleStateAutoGround(void);
void gotoScanStateAutoGround(void);

void configureCS0ActiveMode(void);
void configurePortsActiveMode(void);
//-----------------------------------------------------------------------------
// setMux
//-----------------------------------------------------------------------------
//
// Low level access to the CS0MUX register.  This is called by scanSensor().
//
void setMux(uint8_t muxValue)
{
   CS0MX = muxValue;
}

//-----------------------------------------------------------------------------
// setGain
//-----------------------------------------------------------------------------
//
// Low level access to the gain bits.  This is called by scanSensor().
//
void setGain(uint8_t gainValue)
{
   CS0MD1 = 0x07 & gainValue;         // clear all bits except gain bits
}

//-----------------------------------------------------------------------------
// readGain
//-----------------------------------------------------------------------------
//
// Returns the gain bits of the sensor.
//
uint8_t readGain(void)
{
   return CS0MD1 & 0x07;
}

//-----------------------------------------------------------------------------
// readMux
//-----------------------------------------------------------------------------
//
// Returns the mux value from the sensor peripheral.
//
uint8_t readMux(void)
{
   return CS0MX;
}

//-----------------------------------------------------------------------------
// setAccumulation
//-----------------------------------------------------------------------------
//
// Sets the accumulation bits of the sensor register.
//
void setAccumulation(uint8_t accumulation)
{
   CS0CF = 0x07 & accumulation;        // Clear all bits except accumulation
}


//-----------------------------------------------------------------------------
// executeConversion
//-----------------------------------------------------------------------------
//
// Assumes that the performance characteristics of the sensor have already
// been configured.  Enables the sensor, starts a scan, blocks until
// the scan is complete.
// Note that this version of executeConversion() allows for a retrieval
// of sensor data from the serial port through a call to getU16().  This
// is a compile-time switch.
//
uint16_t CSLIB_executeConversionCB(void)
{

	SI_UU16_t scanResult;

	CS0CN = 0x88;                       // Enable CS0, Enable Digital Comparator

	CS0CN &= ~0x20;                     // Clear the CS0 INT flag

	CS0CN |= 0x10;                      // Set CS0BUSY to begin conversion

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

	while (!(CS0CN & 0x20));            // Wait in foreground


	scanResult.u8[MSB] = CS0DH;         // Read Result
	scanResult.u8[LSB] = CS0DL;

	CS0CN = 0x00;                       // Disable CS0

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
   uint8_t SFRPageSave = SFRPAGE;
   SFRPAGE = CONFIG_PAGE;

  // Configure all capsenes inputs to analog input to minimize interference
  // coupling
  P0MDIN &= ~ACTIVE_MODE_MASK_P0;
  P1MDIN &= ~ACTIVE_MODE_MASK_P1;
  P2MDIN &= ~ACTIVE_MODE_MASK_P2;
  P3MDIN &= ~ACTIVE_MODE_MASK_P3;
  P4MDIN &= ~ACTIVE_MODE_MASK_P4;
  P5MDIN &= ~ACTIVE_MODE_MASK_P5;

  SFRPAGE = SFRPageSave;  
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
//-----------------------------------------------------------------------------
// configureCS0ActiveMode
//-----------------------------------------------------------------------------
//
// This is a low-level local routine to handle configuration of the CS0 block.
//
void configureCS0ActiveMode(void)
{
   uint8_t SFRPAGEsave = SFRPAGE; // Save the current SFRPAGE
	SFRPAGE = CS0_PAGE;

	CS0CF = 0x00;                         // MODE: CS0BUSY
   CS0MD2 &= 0xC0;                       // 12-bit mode
   CS0MD2 |= 0x40;
   CS0THH = 0;
   CS0THL = 0;
   SFRPAGE = SFRPAGEsave;             // Restore the SFRPAGE

   CS0CN = 0x88;                       // Enable CS0, Enable Digital Comparator

   CS0CN &= ~0x20;

   CS0CN |= 0x10;                      // Set CS0BUSY to begin conversion
   while (!(CS0CN & 0x20));            // Wait in foreground

   CS0CN = 0x00;                       // Disable CS0

}


//-----------------------------------------------------------------------------
// configurePortsActiveMode
//-----------------------------------------------------------------------------
//
// This is a low-level local routine to handle configuration of the ports
// for active mode.
//
void configurePortsActiveMode(void)
{
   uint8_t SFRPageSave = SFRPAGE;
   SFRPAGE = LEGACY_PAGE;

   AMUX0P0 = ACTIVE_MODE_MASK_P0;
   AMUX0P1 = ACTIVE_MODE_MASK_P1;
   AMUX0P2 = ACTIVE_MODE_MASK_P2;
   AMUX0P3 = ACTIVE_MODE_MASK_P3;
   AMUX0P4 = ACTIVE_MODE_MASK_P4;
   AMUX0P5 = ACTIVE_MODE_MASK_P5;


   SFRPAGE = CONFIG_PAGE;

   P0MDOUT |= ACTIVE_MODE_MASK_P0;
   P1MDOUT |= ACTIVE_MODE_MASK_P1;
   P2MDOUT |= ACTIVE_MODE_MASK_P2;
   P3MDOUT |= ACTIVE_MODE_MASK_P3;
   P4MDOUT |= ACTIVE_MODE_MASK_P4;
   P5MDOUT |= ACTIVE_MODE_MASK_P5;


   SFRPAGE = LEGACY_PAGE;

   P0 &= ~ACTIVE_MODE_MASK_P0;
   P1 &= ~ACTIVE_MODE_MASK_P1;
   P2 &= ~ACTIVE_MODE_MASK_P2;
   P3 &= ~ACTIVE_MODE_MASK_P3;
   P4 &= ~ACTIVE_MODE_MASK_P4;
   P5 &= ~ACTIVE_MODE_MASK_P5;


   SFRPAGE = CONFIG_PAGE;

   P0MDOUT &= ~ACTIVE_MODE_MASK_P0;
   P1MDOUT &= ~ACTIVE_MODE_MASK_P1;
   P2MDOUT &= ~ACTIVE_MODE_MASK_P2;
   P3MDOUT &= ~ACTIVE_MODE_MASK_P3;
   P4MDOUT &= ~ACTIVE_MODE_MASK_P4;
   P5MDOUT &= ~ACTIVE_MODE_MASK_P5;

  gotoIdleStateAutoGround();

   SFRPAGE = SFRPageSave;
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
