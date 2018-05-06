/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "pca_0.h"

#include "assert.h"

#if EFM8PDL_PCA0_AUTO_PAGE == 1
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

uint8_t PCA0_getIntFlags()
{
  uint8_t val;
  DECL_PAGE;
  SET_PAGE(0x00);
  val = PCA0CN0 & (PCA0_OVERFLOW_IF
                   | PCA0_CHAN0_IF
                   | PCA0_CHAN1_IF
                   | PCA0_CHAN2_IF
                   | PCA0_CHAN3_IF
                   | PCA0_CHAN4_IF
                   | PCA0_CHAN5_IF);
  val |= ((PCA0PWM<<1) & PCA0_IOVERFLOW_IF);
  RESTORE_PAGE;
  return val;
}

void PCA0_clearIntFlag(uint8_t flag)
{
  DECL_PAGE;
  SET_PAGE(0x00);
  PCA0CN0  &= ~(flag & ~PCA0_IOVERFLOW_IF);
  PCA0PWM &= (~(flag & PCA0_IOVERFLOW_IF)) >> 1;
  RESTORE_PAGE;
}

void PCA0_enableInt(uint8_t flag, bool enable)
{
  uint8_t en;
  DECL_PAGE;
  SET_PAGE(0x00);
  en = (uint8_t) enable;

  if(flag & PCA0_CHAN0_IF){
    PCA0CPM0 &= ~PCA0CPM0_ECCF__BMASK;
    PCA0CPM0 |= en << PCA0CPM0_ECCF__SHIFT;
  }
  if(flag & PCA0_CHAN1_IF){
    PCA0CPM1 &= ~PCA0CPM1_ECCF__BMASK;
    PCA0CPM1 |= en << PCA0CPM1_ECCF__SHIFT;
  }
  if(flag & PCA0_CHAN2_IF){
    PCA0CPM2 &= ~PCA0CPM2_ECCF__BMASK;
    PCA0CPM2 |= en << PCA0CPM2_ECCF__SHIFT;
  }
  if(flag & PCA0_CHAN3_IF){
    PCA0CPM3 &= ~PCA0CPM3_ECCF__BMASK;
    PCA0CPM3 |= en << PCA0CPM3_ECCF__SHIFT;
  }
  if(flag & PCA0_CHAN4_IF){
    PCA0CPM4 &= ~PCA0CPM4_ECCF__BMASK;
    PCA0CPM4 |= en << PCA0CPM4_ECCF__SHIFT;
  }
  if(flag & PCA0_CHAN5_IF){
    //Channel can not be modified when WDT enabled
    SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
    PCA0CPM5 &= ~PCA0CPM5_ECCF__BMASK;
    PCA0CPM5 |= en << PCA0CPM5_ECCF__SHIFT;
  }
  if(flag & PCA0_OVERFLOW_IF){
    PCA0MD &= ~PCA0MD_ECF__BMASK;
    PCA0MD |= en << PCA0MD_ECF__SHIFT;
  }
  if(flag & PCA0_IOVERFLOW_IF){
    PCA0PWM &= ~PCA0PWM_ECOV__BMASK;
    PCA0PWM |= en << PCA0PWM_ECOV__SHIFT;
  }

  RESTORE_PAGE;
}

uint16_t PCA0_readChannel(PCA0_Channel_t channel)
{
  uint16_t value;
  DECL_PAGE;
  SET_PAGE(0x00);
  switch(channel)
  {
  case 0:
    value = PCA0CP0;
    break;
  case 1:
    value = PCA0CP1;
    break;
  case 2:
    value = PCA0CP2;
    break;
  case 3:
    value = PCA0CP3;
    break;
  case 4:
    value = PCA0CP4;
    break;
  case 5:
    value = PCA0CP5;
    break;
  }

  RESTORE_PAGE;
  return value;
}

void PCA0_writeChannel(PCA0_Channel_t channel, uint16_t value)
{
  uint8_t lower;
  DECL_PAGE;
  SET_PAGE(0x00);
  lower = value >> 8;

  switch(channel)
  {
  case 0:
    PCA0CPL0 = value;
    PCA0CPH0 = lower;
    break;
  case 1:
    PCA0CPL1 = value;
    PCA0CPH1 = lower;
    break;
  case 2:
    PCA0CPL2 = value;
    PCA0CPH2 = lower;
    break;
  case 3:
    PCA0CPL3 = value;
    PCA0CPH3 = lower;
    break;
  case 4:
    PCA0CPL4 = value;
    PCA0CPH4 = lower;
    break;
  case 5:
    //Channel 5 can't be set when WDT enabled
    SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
    PCA0CPL5 = value;
    PCA0CPH5 = lower;
    break;
  }
  RESTORE_PAGE;
}

uint16_t PCA0_readCounter()
{
  //PCA0L must be read first for accurate results. If PCA0
  //  is returned then PCA0H will be read first (compiler specific).
  // @todo: check that this actually reads pca0l first.
  uint16_t value;
  DECL_PAGE;
  SET_PAGE(0x00);
  value = PCA0L + (PCA0H << 8);
  RESTORE_PAGE;
  return value;
}

void PCA0_writeCounter(uint16_t value)
{
  DECL_PAGE;
  SET_PAGE(0x00);
  //Timer can't be set when WDT enabled
  SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
  PCA0 = value;
  RESTORE_PAGE;
}

void PCA0_run()
{
  DECL_PAGE;
  SET_PAGE(0x00);
  //Counter/Timer can not stopped/started when WDT running
  SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
  PCA0CN0_CR = 1;
  RESTORE_PAGE;
}

void PCA0_halt()
{
  DECL_PAGE;
  SET_PAGE(0x00);
  //Counter/Timer can not stopped/started when WDT running
  SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
  PCA0CN0_CR = 0;
  RESTORE_PAGE;
}

void PCA0_init(PCA0_Timebase_t  timebase, PCA0_IdleState_t idleState)
{
  DECL_PAGE;
  SET_PAGE(0x00);
  //Counter/Timer can not be modified when WDT enabled
  SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
  PCA0MD &= ~(PCA0MD_CPS__FMASK | PCA0MD_CIDL__BMASK);
  PCA0MD |= timebase + idleState;
  RESTORE_PAGE;
}

void PCA0_initChannel(PCA0_Channel_t channel,
                      PCA0_ChannelMode_t  mode,
                      PCA0_ChannelOutPolatiry_t pol
                      )
{
  uint8_t pwmValue;
  DECL_PAGE;
  SET_PAGE(0x00);
  #define MODE_MASK  ~(PCA0CPM0_PWM16__BMASK \
                       | PCA0CPM0_ECOM__BMASK \
                       | PCA0CPM0_CAPP__BMASK \
                       | PCA0CPM0_CAPN__BMASK \
                       | PCA0CPM0_MAT__BMASK \
                       | PCA0CPM0_TOG__BMASK \
                       | PCA0CPM0_PWM__BMASK)
  pol=pol;

#define MODE_MASK  ~(PCA0CPM0_PWM16__BMASK \
                     | PCA0CPM0_ECOM__BMASK \
                     | PCA0CPM0_CAPP__BMASK \
                     | PCA0CPM0_CAPN__BMASK \
                     | PCA0CPM0_MAT__BMASK \
                     | PCA0CPM0_TOG__BMASK \
                     | PCA0CPM0_PWM__BMASK)
#define PWM_MASK  ~(PCA0PWM_ARSEL__BMASK \
                    | PCA0PWM_CLSEL__FMASK)

#define NBIT_VALUE_MASK 0x07
#define NBIT_MASK 0x70
#define NBIT_PCM   PCA0CPM0_PWM16__8_BIT \
                   | PCA0CPM0_ECOM__ENABLED \
                   | PCA0CPM0_CAPP__DISABLED \
                   | PCA0CPM0_CAPN__DISABLED \
                   | PCA0CPM0_MAT__ENABLED \
                   | PCA0CPM0_TOG__DISABLED \
                   | PCA0CPM0_PWM__ENABLED
# define IS_16BIT 0x80

 pwmValue = (uint8_t) mode;

 //UPDATE PWM if we are a PWM mode
 if( (mode & NBIT_MASK) == NBIT_MASK)
 {
   PCA0PWM &= PWM_MASK;

   if(mode & IS_16BIT)
   {
     pwmValue = NBIT_PCM | IS_16BIT;
   }
   else
   {
     PCA0PWM |= (mode & NBIT_VALUE_MASK) | PCA0PWM_ARSEL__AUTORELOAD;
     pwmValue = NBIT_PCM;
   }
 }


  //Kill WDT mode if it is not the current target mode
//  if(mode)
//  {
//    PCA0MD &= ~PCA0MD_WDTE__BMASK;
//  }

  switch (channel)
  {
  case 0:
    PCA0CPM0 &= MODE_MASK;
    PCA0CPM0 |= pwmValue;
    break;

  case 1:
    PCA0CPM1 &= MODE_MASK;
    PCA0CPM1 |= pwmValue;
    break;

  case 2:
    PCA0CPM2 &= MODE_MASK;
    PCA0CPM2 |= pwmValue;
    break;

  case 3:
    PCA0CPM3 &= MODE_MASK;
    PCA0CPM3 |= pwmValue;
    break;

  case 4:
    PCA0CPM4 &= MODE_MASK;
    PCA0CPM4 |= pwmValue;
    break;
  case 5:
    //Channel 5 can not be modified when WDT enabled
    SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
    PCA0CPM5 &= MODE_MASK;
    PCA0CPM5 |= pwmValue;
    break;
  }

  RESTORE_PAGE;
}

void PCA0_reset()
{
  uint8_t i;
  DECL_PAGE;
  SET_PAGE(0x00);
  //Reset channels
  for (i=0; i<=4; i++)
  {
    PCA0_resetChannel(i);
  }

  //Reset PCA regs
  PCA0MD = 0x0;
  PCA0CN0 = 0x0;
  PCA0   = 0x0;
  PCA0PWM = 0x0;
  RESTORE_PAGE;
}

void PCA0_resetChannel(PCA0_Channel_t channel)
{
  DECL_PAGE;
  SET_PAGE(0x00);
  switch (channel)
  {
  case 0:
    PCA0CP0 = 0x00;
    PCA0CPM0 = 0x0;
    break;
  case 1:
    PCA0CP1 = 0x00;
    PCA0CPM1 = 0x0;
    break;
  case 2:
    PCA0CP2 = 0x00;
    PCA0CPM2 = 0x0;
    break;
  case 3:
    PCA0CP3 = 0x00;
    PCA0CPM3 = 0x0;
    break;
  case 4:
    PCA0CP4 = 0x00;
    PCA0CPM4 = 0x0;
    break;
  case 5:
    //Channel 5 can not be modified when WDT enabled
    SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
    PCA0CP5 = 0x00;
    PCA0CPM5 = 0x0;
    break;
  }

  RESTORE_PAGE;
}

#if EFM8PDL_PCA0_USE_ISR == 1

SI_INTERRUPT(PCA0_ISR, PCA0_IRQn)
{
  //Save and clear flags
  uint8_t flags;
  DECL_PAGE;
  SET_PAGE(0x00);
  flags = PCA0CN0 & (PCA0CN0_CF__BMASK
                     | PCA0CN0_CCF0__BMASK
                     | PCA0CN0_CCF1__BMASK
                     | PCA0CN0_CCF2__BMASK
                     | PCA0CN0_CCF3__BMASK
                     | PCA0CN0_CCF4__BMASK
                     | PCA0CN0_CCF5__BMASK);
  PCA0CN0 &= ~flags;

  if( (PCA0PWM & PCA0PWM_COVF__BMASK)
      && (PCA0PWM & PCA0PWM_ECOV__BMASK))
  {
    PCA0_intermediateOverflowCb();
  }
  PCA0PWM &= ~PCA0PWM_COVF__BMASK;

  if((flags & PCA0CN0_CF__BMASK)
     && (PCA0MD & PCA0MD_ECF__BMASK))
  {
    PCA0_overflowCb();
  }
  if((flags & PCA0CN0_CCF0__BMASK)
     && (PCA0CPM0 & PCA0CPM0_ECCF__BMASK))
  {
    PCA0_channel0EventCb();
  }
  if((flags & PCA0CN0_CCF1__BMASK)
     && (PCA0CPM1 & PCA0CPM1_ECCF__BMASK))
  {
    PCA0_channel1EventCb();
  }
  if((flags & PCA0CN0_CCF2__BMASK)
     && (PCA0CPM2 & PCA0CPM2_ECCF__BMASK))
  {
    PCA0_channel2EventCb();
  }
  if((flags & PCA0CN0_CCF3__BMASK)
     && (PCA0CPM3 & PCA0CPM3_ECCF__BMASK))
  {
    PCA0_channel3EventCb();
  }
  if((flags & PCA0CN0_CCF4__BMASK)
     && (PCA0CPM4 & PCA0CPM4_ECCF__BMASK))
  {
    PCA0_channel4EventCb();
  }
  if((flags & PCA0CN0_CCF5__BMASK)
     && (PCA0CPM5 & PCA0CPM5_ECCF__BMASK))
  {
    PCA0_channel5EventCb();
  }
  RESTORE_PAGE;
}


#endif //EFM8PDL_PCA0_USE_CALLBACKS
