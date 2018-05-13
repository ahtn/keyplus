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
  HFO0CN |= HFO0CN_IOSCEN__ENABLED; 
  CLKSEL = CLKSEL_CLKSL__HFOSC;

  // Set the STOP bit
  PCON0 |= PCON0_STOP__BMASK;
  
  // NOTE: Reset is required to exit stop mode. Program execution 
  // will not continue to this point.
}
#endif // EFM8PDL_PWR_USE_STOP

#include "bsp.h"

void PWR_enterSuspend(void)
{
  uint8_t save_ie, save_clksel;
  SAVE_SFRPAGE;
  SFRPAGE = 0;

  // Disable interrupts until the system is awake and restored
  save_ie = IE;
  IE_EA = 0;

  // System clock must be HFOSC to halt CPU (see ref manual)
  // Set the system clock to HFOSC / 1
  save_clksel = CLKSEL;
  HFO0CN |= HFO0CN_IOSCEN__ENABLED;
  CLKSEL = CLKSEL_CLKSL__HFOSC;

  // Enter suspend mode
  HFO0CN |= HFO0CN_SUSPEND__ENABLED;

  // Next restore the system clock source and divider
  CLKSEL = save_clksel;

  // Finally restore the interrupt enable
  IE = save_ie;
  RESTORE_SFRPAGE;
}

void PWR_enterShutdown(void)
{
  // No need to service interrupts or save the SFRPAGE since the device 
  // will be stopped
  IE_EA = 0;

  // Set the STOPCF bit to shutdown regulator 
  REG01CN |= REG01CN_STOPCF__SHUTDOWN;

  // Set the STOP bit
  PCON0 |= PCON0_STOP__BMASK;
  
  // NOTE: Reset is required to exit stop mode. Program execution 
  // will not continue to this point.
}
