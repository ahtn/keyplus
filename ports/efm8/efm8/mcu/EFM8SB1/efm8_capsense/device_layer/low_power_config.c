/**************************************************************************//**
 * Copyright (c) 2014 by Silicon Laboratories Inc. All rights reserved.
 *
 * (C) Copyright 2014 Silicon Labs Inc,
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include <si_toolchain.h>


#ifdef FFD
#include "config_profile.h"
#else
#include "cslib_hwconfig.h"
#include "cslib_config.h"
#endif
#include "cslib.h"
#include "low_power_hardware.h"
#include "hardware_routines.h"
#include "SI_EFM8SB1_Defs.h"
#include "low_power_config.h"

xdata uint8_t timerTick = 0;

uint8_t host_control = 0;
//-----------------------------------------------------------------------------
// Local function prototypes
//-----------------------------------------------------------------------------
void RTC_init(void);
void LPM_init(void);
void RTC_setAlarmPeriod(uint16_t alarm_frequency);
uint8_t RTC_read(uint8_t reg);
void RTC_write(uint8_t reg, uint8_t value);
void RTC_writeAlarm(uint32_t alarm);
void RTC0CN_setBits(uint8_t bits);
void RTC0CN_clearBits(uint8_t bits);
void RTC_zeroCurrentTime(void);
void configureRTCActiveMode(void);
void configureRTCSleepMode(void);
uint8_t updateRTCFlags(void);
void configureCS0SleepMode(void);
void configurePortsSleepMode(void);


//-----------------------------------------------------------------------------
// File-scope variables
//-----------------------------------------------------------------------------
// Variables used for the RTC interface

// Holds the desired RTC0CN settings
SI_SEGMENT_VARIABLE(RTC_RTC0CNLocal, uint8_t, SI_SEG_DATA);

SI_SEGMENT_VARIABLE(RTC_clkFreq, uint16_t, SI_SEG_XDATA);

// Variables used for the RTC interface
uint8_t PMU_PMU0CFLocal;                       // Holds the desired Wake-up sources

/// Defined wake-up flags
uint8_t RTC_alarm;
uint8_t RTC_failure;
uint8_t Comp_wakeup;
uint8_t PM_wakeup;


uint8_t CLKSEL_save_state;
//uint8_t XBR1_save_state;

/**************************************************************************//**
 * Disable sleep check
 *
 * This function will disable going to sleep in active mode when any one
 * condition below is met
 *
 *****************************************************************************/
void SleepDisableCheck(void)
{
  disable_sleep_and_stall = 0;
  if (0
         // Do not go to sleep if host is reading data
         || (host_control)
         )
  {
    disable_sleep_and_stall = 1;
  }


}


/**************************************************************************//**
 * Ready system for entrance into sleep mode
 *
 * Function configures hardware for optimal low power in sleep mode
 *
 *****************************************************************************/
void readyRegistersForSleep(void)
{
  // Switch to precision osc (following guidelines)
  CLKSEL_save_state = CLKSEL;
  CLKSEL = 0x14;
  while (!(CLKSEL & 0x80))
  {
    ;
  }

}

/**************************************************************************//**
 * Restore registers from sleep
 *
 * Re-enable and get system ready for active mode
 *
 *****************************************************************************/
void restoreRegistersFromSleep(void)
{
  uint8_t SFRPAGEsave = SFRPAGE;
  SFRPAGE = LEGACY_PAGE;

  CLKSEL = CLKSEL_save_state;
  while (!(CLKSEL & 0x80))
  {
  }

  // Restore crossbar to pre-sleep state
  SFRPAGE = SFRPAGEsave;
}


/**************************************************************************//**
 * Configure to sleep mode
 *
 * Re-enable and get system ready for active mode
 *
 *****************************************************************************/
void CSLIB_enterLowPowerStateCB(void)
{
  uint8_t temp;

  // If it's allowed that we go to sleep, enter sleep mode
  if (disable_sleep_and_stall == 0)
  {
    readyRegistersForSleep();

    // Enable the Flash read one-shot timer
    FLSCL &= ~BYPASS;                  // Clear the one-shot bypass bit


    // Verify that the system clock setting has been applied
    while (!(CLKSEL & 0x80))
    {                                  // Wait until CLKRDY -> 1
    }
    PMU0CFconfig(SLEEP | RTC);         // Enter Sleep Until Next Event

    // Disable (Bypass) the Flash Read one-shot timer if the system clock

    FLSCL |= BYPASS;                   // Set the one-shot bypass bit

    updateRTCFlags();                  // This call will clear the alarm flag
    restoreRegistersFromSleep();
  }
  else
  {
    // Don't go to sleep but stall in active mode until RTC alarm
    while (1)
    {
      temp = PMU0CF_get();
      if (temp & RTCAWK)
      {
        CSLIB_checkTimerCB();
        timerTick = 0;
        break;
      }
    }
    // This bit must be re-set every iteration through main's while(1) loop

  }
}

//-----------------------------------------------------------------------------
// Implementation-dependent functions called by LowPowerRoutines.c
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// CSLIB_configureTimerForActiveModeCB
//-----------------------------------------------------------------------------
//
// This is a top-level call to configure the timer to active mode, one of the
// two defined modes of operation in the system.  This instance of the function
// configures the SmaRTClock to the frequency defined in cslib_config.h.
//
void CSLIB_configureTimerForActiveModeCB(void)
{
  configureRTCActiveMode();
}


//-----------------------------------------------------------------------------
// CSLIB_checkTimerCB
//-----------------------------------------------------------------------------
//
// Top-level call into an abstracted timer.  This function is in charge
// of setting the timerTick variable whenever a configured amount of time
// passes according to the timer being used.
// This instance of the CSLIB_checkTimerCB() routine uses the SmaRTClock through
// a call to UPdateRTCFlags(), which returns TRUE if the configured
// elapsed time has passed.
//
void CSLIB_checkTimerCB(void)
{
  if (updateRTCFlags())
  {
    timerTick = 1;                     // Checked and cleared in low power code
  }
}


//-----------------------------------------------------------------------------
// CSLIB_configureSensorForSleepModeCB
//-----------------------------------------------------------------------------
//
// This is a top-level call to configure the sensor to its operational state
// during sleep mode.
//
void CSLIB_configureSensorForSleepModeCB(void)
{
  configurePortsSleepMode();
  configureCS0SleepMode();
}


//-----------------------------------------------------------------------------
// configureTimerForSleepMode
//-----------------------------------------------------------------------------
//
// This is a top-level call to configure the timer to sleep mode, one of the
// two defined modes of operation in the system.  This instance of the function
// configures the SmaRTClock to the frequency defined in cslib_config.h.
//
void CSLIB_configureTimerForSleepModeCB(void)
{
  configureRTCSleepMode();
}

//-----------------------------------------------------------------------------
// configurePortsSleepMode
//-----------------------------------------------------------------------------
//
// This is a low-level local routine to handle configuration of the ports
// for active mode.  It configures the analog pins to select
// channels that are bound to a single sensor input.
//
void configurePortsSleepMode(void)
{

  P0MDIN |= SLEEP_MODE_MASK_P0;
  P0MDOUT |= SLEEP_MODE_MASK_P0;
  P0 &= ~SLEEP_MODE_MASK_P0;

  P0MDOUT &= ~SLEEP_MODE_MASK_P0;
  P0 |= SLEEP_MODE_MASK_P0;
  P0MDIN &= ~SLEEP_MODE_MASK_P0;


  P1MDIN |= SLEEP_MODE_MASK_P1;
  P1MDOUT |= SLEEP_MODE_MASK_P1;
  P1 &= ~SLEEP_MODE_MASK_P1;

  P1MDOUT &= ~SLEEP_MODE_MASK_P1;
  P1 |= SLEEP_MODE_MASK_P1;
  P1MDIN &= ~SLEEP_MODE_MASK_P1;

}

extern uint16_t CSLIB_sleepDelta_temp;
void set_sleep_threshold(void)
{
  uint8_t index;
  uint8_t gain_at_sensor;
  CSLIB_sleepDelta_temp = 0xFF;
  for (index = 0; index < DEF_NUM_SENSORS; index++)
  {
    if (CSLIB_averageTouchDelta[index] < CSLIB_sleepDelta_temp)
    {
      gain_at_sensor = CSLIB_gainValues[index];
      CSLIB_sleepDelta_temp = CSLIB_averageTouchDelta[index];
    }
  }
  // Decompress touch delta (x16) and divide by 4 to find quarter scale = * 4
  CSLIB_sleepDelta_temp = CSLIB_averageTouchDelta[index] * 4;
  while(gain_at_sensor > (CS0MD1 & 0x07))
  {
	  CSLIB_sleepDelta_temp = CSLIB_sleepDelta_temp  * 80 / 100;
	  gain_at_sensor--;
  }
  if (CSLIB_sleepDelta_temp > 400)
  {
    CSLIB_sleepDelta_temp = 400;
  }
  if (CSLIB_sleepDelta_temp < 60)
  {
    CSLIB_sleepDelta_temp = 60;
  }
}

//-----------------------------------------------------------------------------
// configureCS0SleepMode
//-----------------------------------------------------------------------------
//
// This is a low-level local routine to handle configuration of the ports
// for active mode.
//

void configureCS0SleepMode(void)
{
  CS0CN0 = 0x88;                            // Enable CS0, Enable Digital Comparator
  // Clear CS0INT, Clear CS0CMPF
  // Bind channels
  // Bind channels and take threshold of entire slider
  CS0SCAN0 = SLEEP_MODE_MASK_P0;
  CS0SCAN1 = SLEEP_MODE_MASK_P1;
  CS0MD2 &= ~0xC0;
  CS0MD2 |= 0x40;
  CS0CF = 0x88;                        // Enable binding
  CS0MD2 |= 0x38;
  if (noise_level != 1)                                 // High noise, oversample more aggressively
  {
    CS0CF |= 0x04;                              // oversample at 64x
  }
  else
  {
    CS0CF |= 0x02;                                      // oversample at 8x
  }
  CS0MD1 &= ~0x07;                     // Clear Gain Field
  CS0MD1 |= determine_highest_gain();

  set_sleep_threshold();

  CSLIB_executeConversionCB();
}


//-----------------------------------------------------------------------------
// configureRTCSleepMode
//-----------------------------------------------------------------------------
//
// Initialize the SmaRTClock to overflow at the frequency specified in
// cslib_config.h.
//
void configureRTCSleepMode(void)
{
  LPM_init();                          // Initialize Power Management Unit
  RTC_init();                          // Initialize SmaRTClock

  RTC_setAlarmPeriod(CSLIB_sleepModePeriod);  // Set the Alarm Frequency to 25 Hz
  RTC0CN_setBits(RTC0TR + RTC0AEN + ALRM);// Enable Counter, Alarm, and Auto-Reset
}

//-----------------------------------------------------------------------------
// configureRTCActiveMode
//-----------------------------------------------------------------------------
//
// Initialize the SmaRTClock to overflow at the frequency specified in
// cslib_config.h.
//
void configureRTCActiveMode(void)
{
  LPM_init();                          // Initialize Power Management Unit
  RTC_init();                          // Initialize SmaRTClock

  RTC_setAlarmPeriod(CSLIB_activeModePeriod);  // Set the Alarm Frequency to 25 Hz
  RTC0CN_setBits(RTC0TR + RTC0AEN + ALRM);// Enable Counter, Alarm, and Auto-Reset

}


//-----------------------------------------------------------------------------
// configureRTCActiveMode
//-----------------------------------------------------------------------------
//
// Reads all potential wake-up sources.  Only the alarm is communicated
// to upper levels because this is the flag that indicates when
// the sleep/active mode state machine needs to take action.
//
uint8_t updateRTCFlags(void)
{
  uint8_t PMU0CFstate, b;
  PMU0CFstate = PMU0CF_get();
  // Check for an RTC Alarm
  if ((PMU0CFstate & RTCAWK))
  {
    RTC_alarm = 1;
  }
  // Check for an RTC Clock Failure
  if ((PMU0CFstate & RTCFWK))
  {
    RTC_failure = 1;
  }
  // Check for a Port Match Wakeup
  if (PMU0CFstate & PMATWK)
  {
    PM_wakeup = 1;
  }
  // Check for a reset pin Wakeup
  if (PMU0CFstate & RSTWK)
  {
    // Delay greater than 15uS per datasheet recommendation
    b = 255;
    while (b > 0)
    {
      b--;
    }
  }

  PMU0CFconfig(CLEAR);

  if (RTC_alarm)
  {
    RTC_alarm = 0;
    return 1;
  }
  else
  {
    return 0;
  }
}

// LPM_init ()
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// This function will initialize the low power functionality
//
//-----------------------------------------------------------------------------
void LPM_init(void)
{
  PMU0CFconfig(CLEAR);
  PMU_PMU0CFLocal = 0;
  RTC_alarm = 0;
  RTC_failure = 0;
  Comp_wakeup = 0;
  PM_wakeup = 0;
}

//-----------------------------------------------------------------------------
// RTC_init ()
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// This function will initialize the smaRTClock.
//
//-----------------------------------------------------------------------------
void RTC_init(void)
{
  uint16_t i;
  static uint8_t configured = 0;

  uint8_t CLKSEL_SAVE = CLKSEL;

  if (configured)
  {
    return;
  }

  // If the interface is locked
  if (RTC0KEY == 0x00)
  {
    RTC0KEY = 0xA5;                    // Unlock the smaRTClock interface
    RTC0KEY = 0xF1;
  }

  //----------------------------------------
  // Configure the SmaRTClock to crystal
  // or self-oscillate mode
  //----------------------------------------

#if (RTC_CLKSRC == CRYSTAL)

  RTC_write(RTC0XCN, 0x60);            // Configure the smaRTClock
                                       // oscillator for crystal mode
                                       // Bias Doubling Enabled
                                       // AGC Disabled

  RTC_write(RTC0XCF, 0x83);            // Enable Automatic Load Capacitance
                                       // stepping and set the desired
                                       // load capacitance to 4.5pF plus
                                       // the stray PCB capacitance

#elif (RTC_CLKSRC == SELFOSC)

  // Configure smaRTClock to self-oscillate mode with bias X2 disabled
  RTC_write(RTC0XCN, 0x08);

  // Disable Auto Load Cap Stepping
  RTC_write(RTC0XCF, (0x00 | LOADCAP_VALUE));

#endif

  RTC_write(RTC0CN, 0x80);             // Enable smaRTClock oscillator

  CLKSEL = 0x74;                       // Switch to 156 kHz low power
                                       // internal oscillator

  //----------------------------------------
  // Wait for crystal to start
  // No need to wait in self-oscillate mode
  //----------------------------------------

#if (RTC_CLKSRC == CRYSTAL)

  // Wait > 20 ms
  for (i = 0x550; i != 0; i--)
  {
    ;
  }

  // Wait for smaRTClock valid
  while ((RTC_read(RTC0XCN) & 0x10) == 0x00)
  {
    ;
  }

  // Wait for Load Capacitance Ready
  while ((RTC_read(RTC0XCF) & 0x40) == 0x00)
  {
    ;
  }

  RTC_write(RTC0XCN, 0xC0);               // Enable Automatic Gain Control
                                          // and disable bias doubling

#endif

  RTC_write(RTC0CN, 0xC0);             // Enable missing smaRTClock detector
                                       // and leave smaRTClock oscillator
                                       // enabled.

  // Wait > 2 ms (assumption: running at 22MHz/128)
  for (i = 50; i != 0; i--)
  {
  }

  RTC_write(RTC0CN, 0xC0);             // Clear the clock fail flag (precautionary).

  PMU0CF = 0x20;                       // Clear PMU wake-up source flags

  CLKSEL = CLKSEL_SAVE;                // Restore system clock
  while (!(CLKSEL & 0x80))
  {                                    // Poll CLKRDY
  }
  RTC_RTC0CNLocal = 0xC0;                 // Initialize Local Copy of RTC0CN
  configured = 1;
}

//-----------------------------------------------------------------------------
// RTC_read ()
//-----------------------------------------------------------------------------
//
// Return Value : RTC0DAT
// Parameters   : 1) uint8_t reg - address of RTC register to read
//
// This function will read one byte from the specified RTC register.
// Using a register number greater that 0x0F is not permited.
//
// Timing of SmaRTClock register read with short bit set
//
// mov      RTC0ADR, #094h
// nop
// nop
// nop
// mov      A, RTC0DAT
//
//-----------------------------------------------------------------------------
uint8_t RTC_read(uint8_t reg)
{

  RTC0ADR = (0x90 | reg);              // pick register and set BUSY to
                                       // initiate the read

  NOP(); NOP(); NOP();                 // delay 3 system clocks

  return RTC0DAT;                      // return value
}

//-----------------------------------------------------------------------------
// RTC_write ()
//-----------------------------------------------------------------------------
//
// Return Value : none
// Parameters   : 1) uint8_t reg - address of RTC register to write
// 2) uint8_t value - the value to write to <reg>
//
// This function will Write one byte to the specified RTC register.
// Using a register number greater that 0x0F is not permited.
//
// Timing of SmaRTClock register write with short bit set
//
// mov      RTC0ADR, #014h
// mov      RTC0DAT, #088h
// nop
//
//-----------------------------------------------------------------------------
void RTC_write(uint8_t reg, uint8_t value)
{
  RTC0ADR = (0x10 | reg);              // pick register
  RTC0DAT = value;                     // write data
}

//-----------------------------------------------------------------------------
// RTC_writeAlarm ()
//-----------------------------------------------------------------------------
//
// Return Value : none
// Parameters   : 1) uint32_t alarm - the value to write to <ALARM>
//
// This function writes a value to the <ALRM> registers
//
// Instruction timing of multi-byte write with short bit set
//
// mov      RTC0ADR, #010h
// mov      RTC0DAT, #05h
// nop
// mov      RTC0DAT, #06h
// nop
// mov      RTC0DAT, #07h
// nop
// mov      RTC0DAT, #08h
// nop
//
//-----------------------------------------------------------------------------

void RTC_writeAlarm(uint32_t alarm)
{
  SI_UU32_t alarm_value;

  alarm_value.u32 = alarm;

  // Temporarily disable alarm while updating registers
  RTC0ADR = (0x10 | RTC0CN);
  RTC0DAT = (RTC_RTC0CNLocal & ~RTC0AEN);
  NOP();

  // Write the value to the alarm registers
  RTC0ADR = (0x10 | ALARM0);
  RTC0DAT = alarm_value.u8[B0];     // write data
  NOP();
  RTC0DAT = alarm_value.u8[B1];     // write data
  NOP();
  RTC0DAT = alarm_value.u8[B2];     // write data
  NOP();
  RTC0DAT = alarm_value.u8[B3];     // write data
  NOP();

  // Restore alarm state after registers have been written
  RTC0ADR = (0x10 | RTC0CN);
  RTC0DAT = RTC_RTC0CNLocal;
}

//-----------------------------------------------------------------------------
// RTC_GetCurrentTime()
//-----------------------------------------------------------------------------
//
// Return Value : uint32_t value - the value of the SmaRTClock
// Parameters   : none
//
// This function reads the current value of the SmaRTClock
//
// Instruction timing of multi-byte read with short bit set
//
// mov      RTC0ADR, #0d0h
// nop
// nop
// nop
// mov      A, RTC0DAT
// nop
// nop
// mov      A, RTC0DAT
// nop
// nop
// mov      A, RTC0DAT
// nop
// nop
// mov      A, RTC0DAT
//
//-----------------------------------------------------------------------------
uint32_t RTC_GetCurrentTime(void)
{
  SI_UU32_t current_time;

  RTC_write(RTC0CN, RTC_RTC0CNLocal | RTC0CAP);     // Write '1' to RTC0CAP
  while ((RTC_read(RTC0CN) & RTC0CAP))
  {                                                 // Wait for RTC0CAP -> 0
  }
  RTC0ADR = (0xD0 | CAPTURE0);
  NOP(); NOP(); NOP();
  current_time.u8[B0] = RTC0DAT;                // Least significant byte
  NOP(); NOP();
  current_time.u8[B1] = RTC0DAT;
  NOP(); NOP();
  current_time.u8[B2] = RTC0DAT;
  NOP(); NOP();
  current_time.u8[B3] = RTC0DAT;                // Most significant byte

  return current_time.u32;

}

//-----------------------------------------------------------------------------
// RTC_SetCurrentTime()
//-----------------------------------------------------------------------------
//
// Return Value : none
// Parameters   :
//
// This function sets the current value of the SmaRTClock
//
// Instruction timing of multi-byte write with short bit set
//
// mov      RTC0ADR, #010h
// mov      RTC0DAT, #05h
// nop
// mov      RTC0DAT, #06h
// nop
// mov      RTC0DAT, #07h
// nop
// mov      RTC0DAT, #08h
// nop

//-----------------------------------------------------------------------------
void RTC_SetCurrentTime(uint32_t time)
{
  SI_UU32_t current_time;

  current_time.u32 = time;

  // Write the time to the capture registers
  RTC0ADR = (0x10 | CAPTURE0);
  RTC0DAT = current_time.u8[B0];     // write data
  NOP();
  RTC0DAT = current_time.u8[B1];     // write data
  NOP();
  RTC0DAT = current_time.u8[B2];     // write data
  NOP();
  RTC0DAT = current_time.u8[B3];     // write data
  NOP();

  RTC_write(RTC0CN, RTC_RTC0CNLocal | RTC0SET);     // Write '1' to RTC0SET
  while ((RTC_read(RTC0CN) & RTC0SET))
  {                                                 // Wait for RTC0SET -> 0
  }
}

//-----------------------------------------------------------------------------
// RTC0CN_setBits()
//-----------------------------------------------------------------------------
//
// Return Value : none
// Parameters   :
//
// This function sets bits in the RTC0CN register
//-----------------------------------------------------------------------------
void RTC0CN_setBits(uint8_t bits)
{
  RTC_RTC0CNLocal |= (bits & ~0x03);
  RTC_write(RTC0CN, RTC_RTC0CNLocal | bits);
}

//-----------------------------------------------------------------------------
// RTC0CN_clearBits()
//-----------------------------------------------------------------------------
//
// Return Value : none
// Parameters   :
//
// This function clears bits in the RTC0CN register
//-----------------------------------------------------------------------------
void RTC0CN_clearBits(uint8_t bits)
{
  RTC_RTC0CNLocal &= bits;
  RTC_write(RTC0CN, RTC_RTC0CNLocal);
}

//-----------------------------------------------------------------------------
// RTC_setAlarmPeriod ()
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : alarm_frequency
//
// This function will set the RTC Alarm Interval to alarm_ms milliseconds
//
//-----------------------------------------------------------------------------
void RTC_setAlarmPeriod(uint16_t alarm_frequency)
{
  RTC_zeroCurrentTime();               // Reset the RTC Timer
  RTC_writeAlarm((RTCCLK * (uint32_t)alarm_frequency) / 1000L);
}

void RTC_zeroCurrentTime(void)
{
  // Write the time to the capture registers
  RTC0ADR = (0x10 | CAPTURE0);
  RTC0DAT = 0x00;                         // write data
  NOP();
  RTC0DAT = 0x00;                         // write data
  NOP();
  RTC0DAT = 0x00;                         // write data
  NOP();
  RTC0DAT = 0x00;                         // write data
  NOP();

  RTC_write(RTC0CN, RTC_RTC0CNLocal | RTC0SET);          // Write '1' to RTC0SET
  while ((RTC_read(RTC0CN) & RTC0SET))
  {                                                      // Wait for RTC0SET -> 0
  }
}
