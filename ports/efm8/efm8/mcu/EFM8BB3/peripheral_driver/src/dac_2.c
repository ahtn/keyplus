/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "dac_2.h"

#if EFM8PDL_DAC2_AUTO_PAGE == 1
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

#define SFRPAGE_DAC2 (0x30)

#if EFM8PDL_DAC2_USE_INIT == 1
void DAC2_init(DAC2_UpdateTrigger_t trigger)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC2);

   // DAC2/3 VREF == VDD
  DACGCF0_D23REFSL = 1;

  // DAC2/3 VREF Buffer Attenuation / Gain = 2.0/2.0
  DACGCF2 = (DACGCF2 & ~DACGCF2_D23REFGN__FMASK) | DACGCF2_D23REFGN__ATTEN_2P0;
  DAC2CF0 = trigger;
  DAC2CF1 = DAC2CF1_DRVGAIN__GAIN_2P0;

  DAC2_holdOutput(false);
  DAC2_enable();
  RESTORE_PAGE;
}
#endif

void DAC2_enable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC2);
  DAC2CF0 |=  DAC2CF0_EN__ENABLE;
  RESTORE_PAGE;
}

void DAC2_disable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC2);
  DAC2CF0 &= ~DAC2CF0_EN__BMASK;
  RESTORE_PAGE;
}

void DAC2_setOutput(uint16_t value)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC2);
  // MUST load DAC2L first!
  DAC2L = value & 0xFF;
  DAC2H = value >> 8;
  RESTORE_PAGE;
}

void DAC2_holdOutput(bool hold)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC2);
  DACGCF1_D2UDIS = hold;
  RESTORE_PAGE;
}

uint16_t DAC2_getOutput(void)
{
  uint16_t value;
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC2);
  value = (DAC2H <<8) | (DAC2L & 0xFF);
  RESTORE_PAGE;
  return value;
}
