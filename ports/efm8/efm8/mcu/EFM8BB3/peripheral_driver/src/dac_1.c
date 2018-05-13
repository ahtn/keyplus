/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "dac_1.h"

#if EFM8PDL_DAC1_AUTO_PAGE == 1
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

#define SFRPAGE_DAC1 (0x30)

#if EFM8PDL_DAC1_USE_INIT == 1
void DAC1_init(DAC1_UpdateTrigger_t trigger)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC1);

  // DAC1/1 VREF == VDD
  DACGCF0_D01REFSL = 1;

  // DAC1/1 VREF Buffer Attenuation / Gain = 2.0/2.0
  DACGCF2 = (DACGCF2 & ~DACGCF2_D01REFGN__FMASK) | DACGCF2_D01REFGN__ATTEN_2P0;
  DAC1CF0 = trigger;
  DAC1CF1 = DAC1CF1_DRVGAIN__GAIN_2P0;

  DAC1_holdOutput(false);
  DAC1_enable();
  RESTORE_PAGE;
}
#endif

void DAC1_enable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC1);
  DAC1CF0 |=  DAC1CF0_EN__ENABLE;
  RESTORE_PAGE;
}

void DAC1_disable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC1);
  DAC1CF0 &= ~DAC1CF0_EN__BMASK;
  RESTORE_PAGE;
}

void DAC1_setOutput(uint16_t value)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC1);
  // MUST load DAC1L first!
  DAC1L = value & 0xFF;
  DAC1H = value >> 8;
  RESTORE_PAGE;
}

void DAC1_holdOutput(bool hold)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC1);
  DACGCF1_D1UDIS = hold;
  RESTORE_PAGE;
}

uint16_t DAC1_getOutput(void)
{
  uint16_t value;
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC1);
  value = (DAC1H <<8) | (DAC1L & 0xFF);
  RESTORE_PAGE;
  return value;
}
