/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "wdt_0.h"
#include "assert.h"

void WDT0_start(){
  PCA0MD |= PCA0MD_WDTE__BMASK;
  PCA0CPH4 = 0x00;
}

void WDT0_stop()
{
  PCA0MD &= ~PCA0MD_WDTE__BMASK;
}

void WDT0_feed()
{
  PCA0CPH4 = 0x00;
}

void WDT0_init(uint8_t interval,
               WDT0_Timebase_t  timebase,
               WDT0_IdleState_t idleState)
{
  //Counter/Timer can not be modified when WDT enabled
  SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
  PCA0MD &= ~(PCA0MD_CPS__FMASK | PCA0MD_CIDL__BMASK);
  PCA0MD |= timebase + idleState;

  //Reload value is interval/256
  PCA0CPL4 = interval;
}
