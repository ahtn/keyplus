/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "clu_2.h"
#include "assert.h"

#if EFM8PDL_CLU2_AUTO_PAGE == 1
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
#define SET_PAGE(p)
#define RESTORE_PAGE
#endif

#define SFRPAGE_CLU (0x20)

void CLU2_init(CLU2_InputA_t inputA,
               CLU2_InputB_t inputB,
               CLU2_OutputMode_t mode)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);

  CLU2MX = inputA | inputB;
  CLU2CF = (CLU2CF & ~CLU2CF_OUTSEL__BMASK) | mode;
  
  CLEN0 |= CLEN0_C2EN__ENABLE;

  RESTORE_PAGE;
}

void CLU2_initFlipflop(CLU2_FlipflopClock_t clock, bool clockInvert)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);

  CLU2CF = (CLU2CF & ~CLU2CF_CLKINV__BMASK) | ((uint8_t)clockInvert << CLU2CF_CLKINV__SHIFT);
  CLU2CF = (CLU2CF & ~CLU2CF_CLKSEL__FMASK) | clock;

  RESTORE_PAGE;
}

void CLU2_setOutputFunction(CLU2_Function_t function)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  CLU2FN = (uint8_t) function;
  RESTORE_PAGE;
}

uint8_t CLU2_getIntFlags(void)
{
  uint8_t flags;
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);

  flags = CLIF0 & (CLU2_RISING_EDGE_IF | CLU2_FALLING_EDGE_IF);

  RESTORE_PAGE;
  return flags;
}

void CLU2_clearIntFlags(uint8_t flags)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);

  // Must pass one of the valid flags
  SLAB_ASSERT(flags & (CLU2_RISING_EDGE_IF | CLU2_FALLING_EDGE_IF));

  CLIF0 &= ~(flags & (CLU2_RISING_EDGE_IF | CLU2_FALLING_EDGE_IF));
  RESTORE_PAGE;
}

void CLU2_enableInt(uint8_t flags, bool enable)
{
  uint8_t en;
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  en = (uint8_t) enable;
  
  // Must pass one of the valid flags
  SLAB_ASSERT(flags & (CLU2_RISING_EDGE_IF | CLU2_FALLING_EDGE_IF));

  if(flags & CLU2_RISING_EDGE_IF)
  {
    CLIE0 = (CLIE0 & ~CLIE0_C2RIE__BMASK) | (en << CLIE0_C2RIE__SHIFT);
  }

  if(flags & CLU2_FALLING_EDGE_IF)
  {
    CLIE0 = (CLIE0 & ~CLIE0_C2FIE__BMASK) | (en << CLIE0_C2FIE__SHIFT);
  }

  RESTORE_PAGE;
}

void CLU2_enable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  CLEN0 |= CLEN0_C2EN__ENABLE;
  RESTORE_PAGE;
}


void CLU2_disable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  CLEN0 &= ~CLEN0_C2EN__BMASK;
  RESTORE_PAGE;
}


void CLU2_enablePinOutput(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  CLU2CF |= CLU2CF_OEN__ENABLE;
  RESTORE_PAGE;
}

void CLU2_disablePinOutput(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  CLU2CF &= ~CLU2CF_OEN__BMASK;
  RESTORE_PAGE;
}

bool CLU2_getOutput(void)
{
  bool output;
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);

  output = (CLOUT0 & CLOUT0_C2OUT__BMASK) == CLOUT0_C2OUT__BMASK;

  RESTORE_PAGE;
  return output;
}
