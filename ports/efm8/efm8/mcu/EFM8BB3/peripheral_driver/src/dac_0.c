/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "dac_0.h"

#if EFM8PDL_DAC0_AUTO_PAGE == 1
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

#define SFRPAGE_DAC0 (0x30)

#if EFM8PDL_DAC0_USE_INIT == 1
void DAC0_init(DAC0_UpdateTrigger_t trigger)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC0);

  // DAC0/1 VREF == VDD
  DACGCF0_D01REFSL = 1;

  // DAC0/1 VREF Buffer Attenuation / Gain = 2.0/2.0
  DACGCF2 = (DACGCF2 & ~DACGCF2_D01REFGN__FMASK) | DACGCF2_D01REFGN__ATTEN_2P0;
  DAC0CF0 = trigger;
  DAC0CF1 = DAC0CF1_DRVGAIN__GAIN_2P0;

  DAC0_holdOutput(false);
  DAC0_enable();
  RESTORE_PAGE;
}
#endif

void DAC0_enable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC0);
  DAC0CF0 |=  DAC0CF0_EN__ENABLE;
  RESTORE_PAGE;
}

void DAC0_disable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC0);
  DAC0CF0 &= ~DAC0CF0_EN__BMASK;
  RESTORE_PAGE;
}

void DAC0_setOutput(uint16_t value)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC0);
  // MUST load DAC0L first!
  DAC0L = value & 0xFF;
  DAC0H = value >> 8;
  RESTORE_PAGE;
}

void DAC0_holdOutput(bool hold)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC0);
  DACGCF1_D0UDIS = hold;
  RESTORE_PAGE;
}

uint16_t DAC0_getOutput(void)
{
  uint16_t value;
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC0);
  value = (DAC0H <<8) | (DAC0L & 0xFF);
  RESTORE_PAGE;
  return value;
}
