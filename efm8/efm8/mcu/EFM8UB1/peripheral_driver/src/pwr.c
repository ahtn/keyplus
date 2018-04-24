/******************************************************************************
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "pwr.h"

#if (EFM8PDL_PWR_AUTO_PAGE == 1)
#define SAVE_SFRPAGE uint8_t save_sfrpage = SFRPAGE
#define RESTORE_SFRPAGE SFRPAGE = save_sfrpage
#else
#define SAVE_SFRPAGE
#define RESTORE_SFRPAGE
#endif

void PWR_enterIdle(void)
{
  SAVE_SFRPAGE;
  SFRPAGE = 0;

  // Set the IDLE bit followed by a 3-cycle dummy instruction to ensure the
  // CPU wakes under all conditions (see ref manual)
  PCON0 |= PCON0_IDLE__IDLE;
  PCON0 = PCON0;

  RESTORE_SFRPAGE;
}

#if (EFM8PDL_PWR_USE_STOP == 1)
void PWR_enterStop(void)
{
  // No need to service interrupts or save the SFRPAGE since the device
  // will be stopped
  IE_EA = 0;
  SFRPAGE = 0;
  
  // Clock source must be HFOSC0 for lowest power (see ref manual)
  // Enable HFOSC0 then source the system clock from it
  HFOCN |= HFOCN_HFO0EN__ENABLED;
  CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__HFOSC0;
  while((CLKSEL & CLKSEL_DIVRDY__BMASK) == 0);
  
  // Set the STOP bit
  PCON0 |= PCON0_STOP__BMASK;

  // NOTE: Reset is required to exit stop mode. Program execution
  // will not continue to this point.
}
#endif // EFM8PDL_PWR_USE_STOP

void PWR_enterSuspend(void)
{
  uint8_t save_ie, save_clksel;
  SAVE_SFRPAGE;
  SFRPAGE = 0;

  // Disable interrupts until the system is awake and restored
  save_ie = IE;
  IE_EA = 0;
  
  // System clock must be HFOSC0 (see ref manual)
  // Set the system clock to HFOSC0 / 1
  save_clksel = CLKSEL;
  HFOCN |= HFOCN_HFO0EN__ENABLED;
  CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__HFOSC0;
  while((CLKSEL & CLKSEL_DIVRDY__BMASK) == 0);

  // Enter suspend mode
  PCON1 |= PCON1_SUSPEND__SUSPEND;

  // Next restore the system clock source and divider
  CLKSEL = save_clksel;
  while((CLKSEL & CLKSEL_DIVRDY__BMASK) == 0);
  
  // Finally restore the interrupt enable
  IE = save_ie;
  RESTORE_SFRPAGE;
}

void PWR_enterSnooze(void)
{
  uint8_t save_ie, save_clksel;
  SAVE_SFRPAGE;
  SFRPAGE = 0;

  // Disable interrupts until the system is awake and restored
  save_ie = IE;
  IE_EA = 0;
  
  // System clock must be HFOSC0 (see ref manual)
  // Set the system clock to HFOSC0 / 1
  save_clksel = CLKSEL;
  CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__HFOSC0;
  while((CLKSEL & CLKSEL_DIVRDY__BMASK) == 0);

  // Enter suspend mode
  PCON1 |= PCON1_SNOOZE__SNOOZE;
  
  // Next restore the system clock source and divider
  CLKSEL = save_clksel;
  while((CLKSEL & CLKSEL_DIVRDY__BMASK) == 0);

  // Finally restore the interrupt enable
  IE = save_ie;
  RESTORE_SFRPAGE;
}

void PWR_enterShutdown(void)
{
  // No need to service interrupts or save the SFRPAGE since the device
  // will be stopped
  IE_EA = 0;
  SFRPAGE = 0;

  // Set the STOPCF bit to shutdown regulator 
  REG0CN |= REG0CN_STOPCF__SHUTDOWN;

  // Set the STOP bit
  PCON0 |= PCON0_STOP__BMASK;

  // NOTE: Reset is required to exit stop mode. Program execution
  // will not continue to this point.
}
