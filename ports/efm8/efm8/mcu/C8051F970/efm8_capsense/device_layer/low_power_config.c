/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include <si_toolchain.h>

#include "cslib_config.h"
#include "low_power_hardware.h"
#include "cslib.h"
#include "SI_C8051F970_Defs.h"
#include "low_power_config.h"
#include "cslib_hwconfig.h"
xdata uint8_t timerTick = 0;


//-----------------------------------------------------------------------------
// Local function prototypes
//-----------------------------------------------------------------------------
void RTC_init (void);
void LPM_init (void);
void RTC_setAlarmPeriod(uint16_t alarm_frequency);
uint8_t RTC_read (uint8_t reg);
void RTC_write (uint8_t reg, uint8_t value);
void RTC_writeAlarm (uint32_t alarm);
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

// Define Wake-Up Flags
uint8_t RTC_alarm;
uint8_t RTC_failure;
uint8_t Comp_wakeup;
uint8_t PM_wakeup;



typedef struct registerSaveState{
   uint8_t CLKSELsave;
   uint8_t P0MDINsave;
   uint8_t P1MDIN_save;
   uint8_t P2MDIN_save;
   uint8_t P3MDIN_save;
   uint8_t P4MDIN_save;
   uint8_t P5MDIN_save;
   uint8_t XBR1save;
} registerSaveStateStruct;

xdata registerSaveStateStruct registerSaveState;

void readyRegistersForSleep(void)
{
   uint8_t SFRPAGEsave = SFRPAGE;

   SFRPAGE = LEGACY_PAGE;


   registerSaveState.CLKSELsave = CLKSEL;
   CLKSEL = 0x04;
   while (!(CLKSEL & 0x80));

   SFRPAGE = CONFIG_PAGE;

   registerSaveState.P0MDINsave = P0MDIN;
   registerSaveState.P1MDIN_save = P1MDIN;
   registerSaveState.P2MDIN_save = P2MDIN;
   registerSaveState.P3MDIN_save = P3MDIN;
   registerSaveState.P4MDIN_save = P4MDIN;
   registerSaveState.P5MDIN_save = P5MDIN;
   registerSaveState.XBR1save = XBR1;

   SFRPAGE = SFRPAGEsave;

}
void restoreRegistersFromSleep(void)
{
   uint8_t SFRPAGEsave = SFRPAGE;
   SFRPAGE = LEGACY_PAGE;

   CLKSEL = registerSaveState.CLKSELsave;
   while (!(CLKSEL & 0x80));

   SFRPAGE = CONFIG_PAGE;
   P0MDIN = registerSaveState.P0MDINsave;
   P1MDIN = registerSaveState.P1MDIN_save;
   P2MDIN = registerSaveState.P2MDIN_save;
   P3MDIN = registerSaveState.P3MDIN_save;
   P4MDIN = registerSaveState.P4MDIN_save;
   P5MDIN = registerSaveState.P5MDIN_save;
   XBR1 = registerSaveState.XBR1save;
   SFRPAGE = SFRPAGEsave;
}
//-----------------------------------------------------------------------------
// enterLowPowerState
//-----------------------------------------------------------------------------
//
// Enter low power sleep mode.
//
void CSLIB_enterLowPowerStateCB(void)
{
   readyRegistersForSleep();
   PMU0CFconfig(SLEEP | RTC);   // Enter Sleep Until Next Event
   updateRTCFlags();             // This call will clear the alarm flag
   restoreRegistersFromSleep();
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
// checkTimer
//-----------------------------------------------------------------------------
//
// Top-level call into an abstracted timer.  This function is in charge
// of setting the timerTick variable whenever a configured amount of time
// passes according to the timer being used.
// This instance of the checkTimer() routine uses the SmaRTClock through
// a call to UPdateRTCFlags(), which returns TRUE if the configured
// elapsed time has passed.
//
void CSLIB_checkTimerCB(void)
{

   if(updateRTCFlags())
   {
      timerTick = 1;                   // Checked and cleared in low power code
   }
}


//-----------------------------------------------------------------------------
// configureSensorForSleepMode
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
   uint8_t SFRPageSave = SFRPAGE;
   SFRPAGE = LEGACY_PAGE;

   AMUX0P0 = ACTIVE_MODE_MASK_P0;
   AMUX0P1 = ACTIVE_MODE_MASK_P1;
   AMUX0P2 = ACTIVE_MODE_MASK_P2;
   AMUX0P3 = ACTIVE_MODE_MASK_P3;
   AMUX0P4 = ACTIVE_MODE_MASK_P4;
   AMUX0P5 = ACTIVE_MODE_MASK_P5;


   SFRPAGE = CONFIG_PAGE;

   P0MDOUT |= SLEEP_MODE_MASK_P0;
   P1MDOUT |= SLEEP_MODE_MASK_P1;
   P2MDOUT |= SLEEP_MODE_MASK_P2;
   P3MDOUT |= SLEEP_MODE_MASK_P3;
   P4MDOUT |= SLEEP_MODE_MASK_P4;
   P5MDOUT |= SLEEP_MODE_MASK_P5;


   SFRPAGE = LEGACY_PAGE;

   P0 &= ~SLEEP_MODE_MASK_P0;
   P1 &= ~SLEEP_MODE_MASK_P1;
   P2 &= ~SLEEP_MODE_MASK_P2;
   P3 &= ~SLEEP_MODE_MASK_P3;
   P4 &= ~SLEEP_MODE_MASK_P4;
   P5 &= ~SLEEP_MODE_MASK_P5;


   SFRPAGE = CONFIG_PAGE;

   P0MDOUT &= ~SLEEP_MODE_MASK_P0;
   P1MDOUT &= ~SLEEP_MODE_MASK_P1;
   P2MDOUT &= ~SLEEP_MODE_MASK_P2;
   P3MDOUT &= ~SLEEP_MODE_MASK_P3;
   P4MDOUT &= ~SLEEP_MODE_MASK_P4;
   P5MDOUT &= ~SLEEP_MODE_MASK_P5;

   P0MDIN &= ~SLEEP_MODE_MASK_P0;
   P1MDIN &= ~SLEEP_MODE_MASK_P1;
   P2MDIN &= ~SLEEP_MODE_MASK_P2;
   P3MDIN &= ~SLEEP_MODE_MASK_P3;
   P4MDIN &= ~SLEEP_MODE_MASK_P4;
   P5MDIN &= ~SLEEP_MODE_MASK_P5;

   SFRPAGE = SFRPageSave;

   SFRPAGE = SFRPageSave;

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
   uint8_t SFRPageSave = SFRPAGE;
   SFRPAGE = LEGACY_PAGE;
   CS0CN = 0x88;                       // Enable CS0, Enable Digital Comparator
                                       // Clear CS0INT, Clear CS0CMPF
   // Bind channels
   // Bind channels and take threshold of entire slider

   CS0CF  = 0x8A;                      // Enable binding and enable channel masking, 8x oversample
   CS0MD1 &= ~0x07;                    // Clear Gain Field
   CS0MD1  |= 0x01;                    // Set Gain to 2X
   CS0MD2 = 0x00;                      // 12-bit mode

   SFRPAGE = SFRPageSave;
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


   LPM_init ();                        // Initialize Power Management Unit



   RTC_init ();                        // Initialize SmaRTClock
   RTC_setAlarmPeriod(CSLIB_sleepModePeriod); // Set the Alarm Frequency to 25 Hz
   RTC0CN_setBits(RTC0TR+RTC0AEN+ALRM);// Enable Counter, Alarm, and Auto-Reset
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
   LPM_init ();                        // Initialize Power Management Unit
   RTC_init ();                        // Initialize SmaRTClock

   RTC_setAlarmPeriod(CSLIB_activeModePeriod); // Set the Alarm Frequency to 25 Hz
   RTC0CN_setBits(RTC0TR+RTC0AEN+ALRM);// Enable Counter, Alarm, and Auto-Reset

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
   if((PMU0CFstate & RTCAWK))
   {
      RTC_alarm = 1;
   }
   // Check for an RTC Clock Failure
   if((PMU0CFstate & RTCFWK))
   {
      RTC_failure = 1;
   }
   // Check for a Port Match Wakeup
   if(PMU0CFstate & PMATWK)
   {
      PM_wakeup = 1;
   }
   // Check for a reset pin Wakeup
   if(PMU0CFstate & RSTWK)
   {
      // Delay greater than 15uS per datasheet recommendation
      b = 255;
      while(b > 0) b--;
   }

   PMU0CFconfig(CLEAR);

   if(RTC_alarm)
   {
      RTC_alarm = 0;
      return 1;
   }
   else
   {
      return 0;
   }
}






//-----------------------------------------------------------------------------
// Low level RTC and LPM control
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// LPM_init ()
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// This function will initialize the low power functionality
//
//-----------------------------------------------------------------------------
void LPM_init (void)
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
void RTC_init (void)
{
   unsigned int i;

   unsigned char CLKSEL_SAVE = CLKSEL;

   static unsigned char RTC_Configured = 0;

   if(RTC_Configured) return;

   RTC_write(0x07, 0xFF);

   //----------------------------------------
   // Configure the SmaRTClock to crystal
   // or self-oscillate mode
   //----------------------------------------

   #if(RTC_CLKSRC == CRYSTAL)

      RTC_write (RTC0XCN, 0x60);       // Configure the smaRTClock
                                       // oscillator for crystal mode
                                       // Bias Doubling Enabled
                                       // AGC Disabled


      RTC_write (RTC0XCF, 0x83);       // Enable Automatic Load Capacitance
                                       // stepping and set the desired
                                       // load capacitance to 4.5pF plus
                                       // the stray PCB capacitance
   #elif(RTC_CLKSRC == SELFOSC)
      RTC_write (RTC0XCN, 0x60);       // Configure the smaRTClock
                                       // oscillator for crystal mode
                                       // Bias Doubling Enabled
                                       // AGC Disabled
   #else
      // Configure SmaRTClock to LFO mode
      RTC_write (RTC0XCN, 0x08);

      // Disable Auto Load Cap Stepping
      RTC_write (RTC0XCF, (0x00 | LOADCAP_VALUE));

   #endif



   RTC_write (RTC0CN, 0x80);           // Enable smaRTClock oscillator

   CLKSEL    =  0x74;                  // Switch to 156 kHz low power
                                       // internal oscillator
   //----------------------------------------
   // Wait for crystal to start
   // No need to wait in self-oscillate mode
   //----------------------------------------

   #if(RTC_CLKSRC == CRYSTAL)

      // Wait > 20 ms
      for (i=0x150; i!=0; i--);

      // Wait for smaRTClock valid
      while ((RTC_read (RTC0XCN) & 0x10)== 0x00);


      // Wait for Load Capacitance Ready
      while ((RTC_read (RTC0XCF) & 0x40)== 0x00);

      RTC_write (RTC0XCN, 0xC0);          // Enable Automatic Gain Control
                                          // and disable bias doubling

   #endif


   RTC_write (RTC0CN, 0xC0);           // Enable missing smaRTClock detector
                                       // and leave smaRTClock oscillator
                                       // enabled.

   // Wait > 2 ms
   for (i=0x340; i!=0; i--);

   RTC_write (RTC0CN, 0xC0);           // Clear the clock fail flag (precautionary).

   PMU0CF = 0x20;                      // Clear PMU wake-up source flags

   CLKSEL = CLKSEL_SAVE;               // Restore system clock
   while(!(CLKSEL & 0x80));            // Poll CLKRDY

   RTC_RTC0CNLocal = 0xC0;                // Initialize Local Copy of RTC0CN

   RTC_Configured = 1;
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
//  Timing of SmaRTClock register read with short bit set
//
//     mov      RTC0ADR, #094h
//     nop
//     nop
//     nop
//     mov      A, RTC0DAT
//
//-----------------------------------------------------------------------------

uint8_t RTC_read (uint8_t reg)
{
   SI_SEGMENT_VARIABLE(SFRPAGEsave, uint8_t, SI_SEG_IDATA);

	SFRPAGEsave = SFRPAGE;
	SFRPAGE = RTC0_PAGE;

	while (RTC0ADR & 0x80);			// Poll to ensure the smartclk interface is free
	RTC0ADR = (reg | 0x80);				// write the read register and write 1 to BUSY bit (bit 7)
	while (RTC0ADR & 0x80);  			// Poll for busy bit
	SFRPAGE = SFRPAGEsave;
   return RTC0DAT;                     	// return value
}


//-----------------------------------------------------------------------------
// RTC_write ()
//-----------------------------------------------------------------------------
//
// Return Value : none
// Parameters   : 1) uint8_t reg - address of RTC register to write
//                2) uint8_t value - the value to write to <reg>
//
// This function will Write one byte to the specified RTC register.
// Using a register number greater that 0x0F is not permited.
//
// Timing of SmaRTClock register write with short bit set
//
//       mov      RTC0ADR, #014h
//       mov      RTC0DAT, #088h
//       nop
//
//-----------------------------------------------------------------------------

void RTC_write (uint8_t reg, uint8_t value)
{
   SI_SEGMENT_VARIABLE(SFRPAGEsave, uint8_t, SI_SEG_IDATA);

   SFRPAGEsave = SFRPAGE;
	SFRPAGE = RTC0_PAGE;

	while (RTC0ADR & 0x80);			// Poll busy bit to ensure the smartclk interface is free
   RTC0ADR = reg;								//write to address
	RTC0DAT = value;							// Write data
	while (RTC0ADR & 0x80);  			// Poll for busy bit

	SFRPAGE = SFRPAGEsave;
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
//       mov      RTC0ADR, #010h
//       mov      RTC0DAT, #05h
//       nop
//       mov      RTC0DAT, #06h
//       nop
//       mov      RTC0DAT, #07h
//       nop
//       mov      RTC0DAT, #08h
//       nop
//
//-----------------------------------------------------------------------------

void RTC_writeAlarm (uint32_t alarm)
{
   SI_SEGMENT_VARIABLE(alarm_value, SI_UU32_t, SI_SEG_IDATA);
   SI_SEGMENT_VARIABLE(SFRPAGEsave, uint8_t, SI_SEG_IDATA);

	SFRPAGEsave = SFRPAGE;
	SFRPAGE = RTC0_PAGE;

   alarm_value.u32 = alarm;
   //alarm_local = alarm;

   // Temporarily disable alarm while updating registers
   RTC0ADR = (0x10 | RTC0CN);
   RTC0DAT = (RTC_RTC0CNLocal & ~RTC0AEN);
   while (RTC0ADR & 0x80);						 // poll for busy bit -> 0

   // Write the value to the alarm registers
   RTC0ADR = (0x10 | ALARM0);
   RTC0DAT = alarm_value.u8[B0];    // write data
   while (RTC0ADR & 0x80);						 // poll for busy bit -> 0
   RTC0DAT = alarm_value.u8[B1];    // write data
   while (RTC0ADR & 0x80);						 // poll for busy bit -> 0
   RTC0DAT = alarm_value.u8[B2];    // write data
   while (RTC0ADR & 0x80);					 // poll for busy bit -> 0
   RTC0DAT = alarm_value.u8[B3];    // write data
   while (RTC0ADR & 0x80);						 // poll for busy bit -> 0

   // Restore alarm state after registers have been written
   RTC0ADR = (0x10 | RTC0CN);
   RTC0DAT = RTC_RTC0CNLocal;

	SFRPAGE = SFRPAGEsave;
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
   RTC_write( RTC0CN, RTC_RTC0CNLocal | bits);
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
   RTC_write( RTC0CN, RTC_RTC0CNLocal);
}


//-----------------------------------------------------------------------------
// RTC_zeroCurrentTime()
//-----------------------------------------------------------------------------
//
// Return Value : none
// Parameters   :
//
// This function sets the current value of the SmaRTClock
//
// Instruction timing of multi-byte write with short bit set
//
//       mov      RTC0ADR, #010h
//       mov      RTC0DAT, #05h
//       nop
//       mov      RTC0DAT, #06h
//       nop
//       mov      RTC0DAT, #07h
//       nop
//       mov      RTC0DAT, #08h
//       nop

//-----------------------------------------------------------------------------
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
/*
   if(alarm_frequency > 300) alarm_frequency = 300;
   if(alarm_frequency < 1) alarm_frequency = 1;
*/
   RTC_zeroCurrentTime();              // Reset the RTC Timer
   RTC_writeAlarm((RTCCLK * (uint32_t)alarm_frequency) / 1000L);

}


void RTC_zeroCurrentTime(void)
{
   // Write the time to the capture registers
   RTC0ADR = (0x10 | CAPTURE0);
   RTC0DAT = 0x00;                   // write data
   NOP();
   RTC0DAT = 0x00;                   // write data
   NOP();
   RTC0DAT = 0x00;                   // write data
   NOP();
   RTC0DAT = 0x00;                   // write data
   NOP();

   RTC_write( RTC0CN, RTC_RTC0CNLocal | RTC0SET);   // Write '1' to RTC0SET
   while((RTC_read(RTC0CN) & RTC0SET))
   {}          // Wait for RTC0SET -> 0
}
