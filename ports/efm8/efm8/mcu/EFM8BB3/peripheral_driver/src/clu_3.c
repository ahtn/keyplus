/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "clu_3.h"
#include "assert.h"

#if EFM8PDL_CLU3_AUTO_PAGE == 1
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

void CLU3_init(CLU3_InputA_t inputA,
               CLU3_InputB_t inputB,
               CLU3_OutputMode_t mode)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);

  CLU3MX = inputA | inputB;
  CLU3CF = (CLU3CF & ~CLU3CF_OUTSEL__BMASK) | mode;
  
  CLEN0 |= CLEN0_C3EN__ENABLE;

  RESTORE_PAGE;
}

void CLU3_initFlipflop(CLU3_FlipflopClock_t clock, bool clockInvert)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);

  CLU3CF = (CLU3CF & ~CLU3CF_CLKINV__BMASK) | ((uint8_t)clockInvert << CLU3CF_CLKINV__SHIFT);
  CLU3CF = (CLU3CF & ~CLU3CF_CLKSEL__FMASK) | clock;

  RESTORE_PAGE;
}

void CLU3_setOutputFunction(CLU3_Function_t function)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  CLU3FN = (uint8_t) function;
  RESTORE_PAGE;
}

uint8_t CLU3_getIntFlags(void)
{
  uint8_t flags;
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);

  flags = CLIF0 & (CLU3_RISING_EDGE_IF | CLU3_FALLING_EDGE_IF);

  RESTORE_PAGE;
  return flags;
}

void CLU3_clearIntFlags(uint8_t flags)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);

  // Must pass one of the valid flags
  SLAB_ASSERT(flags & (CLU3_RISING_EDGE_IF | CLU3_FALLING_EDGE_IF));

  CLIF0 &= ~(flags & (CLU3_RISING_EDGE_IF | CLU3_FALLING_EDGE_IF));
  RESTORE_PAGE;
}

void CLU3_enableInt(uint8_t flags, bool enable)
{
  uint8_t en;
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  en = (uint8_t) enable;
  
  // Must pass one of the valid flags
  SLAB_ASSERT(flags & (CLU3_RISING_EDGE_IF | CLU3_FALLING_EDGE_IF));

  if(flags & CLU3_RISING_EDGE_IF)
  {
    CLIE0 = (CLIE0 & ~CLIE0_C3RIE__BMASK) | (en << CLIE0_C3RIE__SHIFT);
  }

  if(flags & CLU3_FALLING_EDGE_IF)
  {
    CLIE0 = (CLIE0 & ~CLIE0_C3FIE__BMASK) | (en << CLIE0_C3FIE__SHIFT);
  }

  RESTORE_PAGE;
}

void CLU3_enable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  CLEN0 |= CLEN0_C3EN__ENABLE;
  RESTORE_PAGE;
}


void CLU3_disable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  CLEN0 &= ~CLEN0_C3EN__BMASK;
  RESTORE_PAGE;
}


void CLU3_enablePinOutput(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  CLU3CF |= CLU3CF_OEN__ENABLE;
  RESTORE_PAGE;
}

void CLU3_disablePinOutput(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);
  CLU3CF &= ~CLU3CF_OEN__BMASK;
  RESTORE_PAGE;
}

bool CLU3_getOutput(void)
{
  bool output;
  DECL_PAGE;
  SET_PAGE(SFRPAGE_CLU);

  output = (CLOUT0 & CLOUT0_C3OUT__BMASK) == CLOUT0_C3OUT__BMASK;

  RESTORE_PAGE;
  return output;
}
