/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "wdt_0.h"
#include "assert.h"

#if (EFM8PDL_WDT0_AUTO_PAGE == 1)
// declare variable needed for autopage enter/exit
#define DECL_PAGE uint8_t savedPage
// enter autopage section
#define SET_PAGE(p)     do                                                    \
                        {                                                     \
                          savedPage = SFRPAGE;  /* save current SFR page */   \
                          SFRPAGE = (p);        /* set SFR page */            \
                        } while(0)
// exit autopage section
#define RESTORE_PAGE    do                                                    \
                        {                                                     \
                          SFRPAGE = savedPage;  /* restore saved SFR page */  \
                        } while(0)

#else
#define DECL_PAGE
#define SET_PAGE
#define RESTORE_PAGE
#endif

void WDT0_start(){
  DECL_PAGE;
  SET_PAGE(0x00);
  PCA0MD |= PCA0MD_WDTE__BMASK;
  PCA0CPH5 = 0x00;
  RESTORE_PAGE;
}

void WDT0_stop()
{
  DECL_PAGE;
  SET_PAGE(0x00);
  PCA0MD &= ~PCA0MD_WDTE__BMASK;
  RESTORE_PAGE;
}

void WDT0_feed()
{
  DECL_PAGE;
  SET_PAGE(0x00);
  PCA0CPH5 = 0x00;
  RESTORE_PAGE;
}

void WDT0_init(uint8_t interval,
               WDT0_Timebase_t  timebase,
               WDT0_IdleState_t idleState)
{
  DECL_PAGE;
  SET_PAGE(0x00);
  //Counter/Timer can not be modified when WDT enabled
  SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
  PCA0MD &= ~(PCA0MD_CPS__FMASK | PCA0MD_CIDL__BMASK);
  PCA0MD |= timebase + idleState;

  //Reload value is interval/256
  PCA0CPL5 = interval;

  RESTORE_PAGE;
}
