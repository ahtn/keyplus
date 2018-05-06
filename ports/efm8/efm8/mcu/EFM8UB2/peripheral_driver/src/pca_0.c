/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "pca_0.h"

#include "assert.h"

uint8_t PCA0_getIntFlags()
{
  return PCA0CN0 & (PCA0_OVERFLOW_IF
                    | PCA0_CHAN0_IF
                    | PCA0_CHAN1_IF
                    | PCA0_CHAN2_IF
                    | PCA0_CHAN3_IF
                    | PCA0_CHAN4_IF);
}

void PCA0_clearIntFlags(uint8_t flag)
{
  PCA0CN0 &= ~flag;
}

void PCA0_enableInt(uint8_t flag, bool enable)
{
  uint8_t en = (uint8_t) enable;

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
    //Channel can not be modified when WDT enabled
    SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
    PCA0CPM4 &= ~PCA0CPM4_ECCF__BMASK;
    PCA0CPM4 |= en << PCA0CPM4_ECCF__SHIFT;
  }
  if(flag & PCA0_OVERFLOW_IF){
    PCA0MD &= ~PCA0MD_ECF__BMASK;
    PCA0MD |= en << PCA0MD_ECF__SHIFT;
  }
}

uint16_t PCA0_readChannel(PCA0_Channel_t channel)
{
  switch(channel)
  {
  case 0:
    return PCA0CP0;
  case 1:
    return PCA0CP1;
  case 2:
    return PCA0CP2;
  case 3:
    return PCA0CP3;
  case 4:
    return PCA0CP4;
  }
  return 0x0;
}

void PCA0_writeChannel(PCA0_Channel_t channel, uint16_t value)
{
  uint8_t lower = value >> 8;
  switch(channel)
  {
  case 0:
    //PCA0CP0 = value;
    PCA0CPL0 = value;
    PCA0CPH0 = lower;
    break;
  case 1:
    //PCA0CP1 = value;
    PCA0CPL1 = value;
    PCA0CPH1 = lower;
    break;
  case 2:
    //PCA0CP2 = value;
    PCA0CPL2 = value;
    PCA0CPH2 = lower;
    break;
  case 3:
    //PCA0CP3 = value;
    PCA0CPL3 = value;
    PCA0CPH3 = lower;
    break;
  case 4:
    //Timer can't be set when WDT enabled
    SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
    //PCA0CP4 = value;
    PCA0CPL4 = value;
    PCA0CPH4 = lower;
    break;
  }
}

uint16_t PCA0_readCounter()
{
  //PCA0L must be read first for accurate results. If PCA0
  //  is returned then PCA0H will be read first (compiler specific).
  // @todo: check that this actually reads pca0l first.
  return PCA0L + (PCA0H << 8);
}

void PCA0_writeCounter(uint16_t value)
{
  //Timer can't be set when WDT enabled
  SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
  PCA0 = value;
}

void PCA0_run()
{
  //Counter/Timer can not stopped/started when WDT running
  SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
  PCA0CN0_CR = 1;
}

void PCA0_halt()
{
  //Counter/Timer can not stopped/started when WDT running
  SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
  PCA0CN0_CR = 0;
}

void PCA0_init(PCA0_Timebase_t  timebase, PCA0_IdleState_t idleState)
{
  //Counter/Timer can not be modified when WDT enabled
  SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
  PCA0MD &= ~(PCA0MD_CPS__FMASK | PCA0MD_CIDL__BMASK);
  PCA0MD |= timebase + idleState;
}

void PCA0_initChannel(PCA0_Channel_t channel,
                      PCA0_ChannelMode_t  mode,
                      PCA0_ChannelOutPolatiry_t pol
                      )
{
  #define MODE_MASK  ~(PCA0CPM0_PWM16__BMASK \
                       | PCA0CPM0_ECOM__BMASK \
                       | PCA0CPM0_CAPP__BMASK \
                       | PCA0CPM0_CAPN__BMASK \
                       | PCA0CPM0_MAT__BMASK \
                       | PCA0CPM0_TOG__BMASK \
                       | PCA0CPM0_PWM__BMASK)
  pol=pol;

  //Kill WDT mode if it is not the current target mode
  if(mode)
  {
    PCA0MD &= ~PCA0MD_WDTE__BMASK;
  }

  switch (channel)
  {
  case 0:
    PCA0CPM0 &= MODE_MASK;
    PCA0CPM0 |= mode;
    break;

  case 1:
    PCA0CPM1 &= MODE_MASK;
    PCA0CPM1 |= mode;
    break;

  case 2:
    PCA0CPM2 &= MODE_MASK;
    PCA0CPM2 |= mode;
    break;

  case 3:
    PCA0CPM3 &= MODE_MASK;
    PCA0CPM3 |= mode;
    break;

  case 4:
    //Channel 4 can not be modified when WDT enabled
    SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
    PCA0CPM4 &= MODE_MASK;
    PCA0CPM4 |= mode;
    break;
  }

}

void PCA0_reset()
{
  //Reset channels
  uint8_t i;
  for (i=0; i<=4; i++)
  {
    PCA0_resetChannel(i);
  }

  //Reset PCA regs
  PCA0MD = 0x0;
  PCA0CN0 = 0x0;
  PCA0   = 0x0;
}

void PCA0_resetChannel(PCA0_Channel_t channel)
{
  switch (channel)
  {
  case 0:
    PCA0CP0 = 0x00;
    PCA0CPM0 = 0x0;
    return;
  case 1:
    PCA0CP1 = 0x00;
    PCA0CPM1 = 0x0;
    return;
  case 2:
    PCA0CP2 = 0x00;
    PCA0CPM2 = 0x0;
    return;
  case 3:
    PCA0CP3 = 0x00;
    PCA0CPM3 = 0x0;
    return;
  case 4:
    //Channel 4 can not be modified when WDT enabled
    SLAB_ASSERT(!(PCA0MD & PCA0MD_WDTE__BMASK));
    PCA0CP4 = 0x00;
    PCA0CPM4 = 0x0;
    return;
  }
}

#if EFM8PDL_PCA0_USE_ISR == 1

//TODO: update to mask with interrupt enables.
SI_INTERRUPT(PCA0_ISR, PCA0_IRQn)
{
	//Save and clear flags
  uint8_t flags = PCA0CN0 & (PCA0CN0_CF__BMASK
                             | PCA0CN0_CCF0__BMASK
                             | PCA0CN0_CCF1__BMASK
                             | PCA0CN0_CCF2__BMASK
                             | PCA0CN0_CCF3__BMASK
                             | PCA0CN0_CCF4__BMASK);
  PCA0CN0 &= ~flags;

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
}

#endif //EFM8PDL_PCA0_USE_CALLBACKS
