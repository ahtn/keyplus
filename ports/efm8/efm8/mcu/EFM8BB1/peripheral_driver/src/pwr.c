/******************************************************************************
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "pwr.h"

void PWR_enterIdle(void)
{
  // Set the IDLE bit followed by a 3-cycle dummy instruction to ensure the
  // CPU wakes under all conditions (see ref manual)
  PCON0 |= PCON0_IDLE__IDLE;
  PCON0 = PCON0;
}

#if (EFM8PDL_PWR_USE_STOP == 1)
void PWR_enterStop(void)
{
  // No need to service interrupts
  IE_EA = 0;

  // Clock source must be HFOSC for lowest power (see ref manual)
  // Enable HFOSC then source the system clock from it
  CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__HFOSC;

  // Set the STOP bit
  PCON0 |= PCON0_STOP__BMASK;

  // NOTE: Reset is required to exit stop mode. Program execution
  // will not continue to this point.
}
#endif // EFM8PDL_PWR_USE_STOP

void PWR_enterShutdown(void)
{
  // No need to service interrupts 
  IE_EA = 0;

  // Set the STOPCF bit to shutdown regulator 
  REG0CN |= REG0CN_STOPCF__SHUTDOWN;

  // Set the STOP bit
  PCON0 |= PCON0_STOP__BMASK;
  
  // NOTE: Reset is required to exit stop mode. Program execution 
  // will not continue to this point.
}
