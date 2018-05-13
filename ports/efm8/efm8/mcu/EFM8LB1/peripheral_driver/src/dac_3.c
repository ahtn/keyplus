/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "dac_3.h"

#if EFM8PDL_DAC3_AUTO_PAGE == 1
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

#define SFRPAGE_DAC3 (0x30)

#if EFM8PDL_DAC3_USE_INIT == 1
void DAC3_init(DAC3_UpdateTrigger_t trigger)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC3);

   // DAC2/3 VREF == VDD
  DACGCF0_D23REFSL = 1;

  // DAC2/3 VREF Buffer Attenuation / Gain = 2.0/2.0
  DACGCF2 = (DACGCF2 & ~DACGCF2_D23REFGN__FMASK) | DACGCF2_D23REFGN__ATTEN_2P0;
  DAC3CF0 = trigger;
  DAC3CF1 = DAC3CF1_DRVGAIN__GAIN_2P0;

  DAC3_holdOutput(false);
  DAC3_enable();
  RESTORE_PAGE;
}
#endif

void DAC3_enable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC3);
  DAC3CF0 |=  DAC3CF0_EN__ENABLE;
  RESTORE_PAGE;
}

void DAC3_disable(void)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC3);
  DAC3CF0 &= ~DAC3CF0_EN__BMASK;
  RESTORE_PAGE;
}

void DAC3_setOutput(uint16_t value)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC3);
  // MUST load DAC3L first!
  DAC3L = value & 0xFF;
  DAC3H = value >> 8;
  RESTORE_PAGE;
}

void DAC3_holdOutput(bool hold)
{
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC3);
  DACGCF1_D3UDIS = hold;
  RESTORE_PAGE;
}

uint16_t DAC3_getOutput(void)
{
  uint16_t value;
  DECL_PAGE;
  SET_PAGE(SFRPAGE_DAC3);
  value = (DAC3H <<8) | (DAC3L & 0xFF);
  RESTORE_PAGE;
  return value;
}
