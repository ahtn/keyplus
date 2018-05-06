/******************************************************************************
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "pwr.h"

// Mask of all wake source enable bits in PMU0CF (used for writing PMU0CF)
#define PWR_PMU0CF_WAKE_ENABLES (PWR_CPT0_WF | PWR_PMAT_WF | PWR_RTCA_WF | PWR_RTCF_WF)

// Mask of all wake flags in PMU0CF (used for reading PMU0CF)
#define PWR_PMU0CF_WAKE_FLAGS (PWR_PMU0CF_WAKE_ENABLES | PWR_RST_WF)

#if (EFM8PDL_PWR_AUTO_PAGE == 1)
#define SAVE_SFRPAGE uint8_t save_sfrpage = SFRPAGE
#define RESTORE_SFRPAGE SFRPAGE = save_sfrpage
#else
#define SAVE_SFRPAGE
#define RESTORE_SFRPAGE
#endif

// Reads and clears all PMU0 wake-up flags.
uint8_t PWR_readAndClearWakeFlags(void)
{
  uint8_t save_ie, snapshot_pmu0cf;
  SAVE_SFRPAGE;
  SFRPAGE = 0;

  // Disable interrupts to minimize time between reading and clearing the flags
  save_ie = IE;
  IE_EA = 0;

  // Snapshot the wake-up source flags, then clear them
  snapshot_pmu0cf = PMU0CF;
  PMU0CF = PMU0CF_CLEAR__ALL_FLAGS;

  // Now restore the interrupt enable
  IE = save_ie;
  RESTORE_SFRPAGE;

  // Return the wake-up flag snapshot
  return snapshot_pmu0cf & PWR_PMU0CF_WAKE_FLAGS;
}

void PWR_enterIdle(void)
{
  uint8_t save_flscl;
  SAVE_SFRPAGE;
  SFRPAGE = 0;

  // Select flash one-shot read timing for lowest power (see ref manual)
  save_flscl = FLSCL;
  FLSCL = FLSCL_BYPASS__ONE_SHOT;
  // Third op-code byte is indeterminate after clearing FLSCL.BYPASS (see errata)
  // This line will load the B register with an unknown value
  B = 0x55;

  // Set the IDLE bit followed by a 3-cycle dummy instruction to ensure the 
  // CPU wakes under all conditions (see ref manual)
  PCON0 |= PCON0_IDLE__IDLE;
  PCON0 = PCON0;
  
  // Restore flash timing
  FLSCL = save_flscl;
  RESTORE_SFRPAGE;
}

#if (EFM8PDL_PWR_USE_STOP == 1)
void PWR_enterStop(void)
{
  // No need to service interrupts or save the SFRPAGE since the device 
  // will be stopped
  IE_EA = 0;
  SFRPAGE = 0;
  
  // Clock source must be HFOSC for lowest power (see ref manual)
  // Enable HFOSC then source the system clock from it
  REG0CN |= REG0CN_OSCBIAS__BMASK;  // force bias to ensure osc start-up
  HFO0CN |= HFO0CN_IOSCEN__ENABLED;
  while ((HFO0CN & HFO0CN_IFRDY__BMASK) == 0);
  CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__HFOSC;
  while((CLKSEL & CLKSEL_CLKRDY__BMASK) == 0);

  // Turn off the osc bias force bit, so the bias will be automatically 
  // disabled in stop mode
  REG0CN &= ~REG0CN_OSCBIAS__BMASK;

  // Select flash one-shot read timing for lowest power (see ref manual)
  FLSCL = FLSCL_BYPASS__ONE_SHOT;
  // Third op-code byte is indeterminate after clearing FLSCL.BYPASS (see errata)
  // This line will load the B register with an unknown value
  B = 0x55;

  // Set the STOP bit
  PCON0 |= PCON0_STOP__BMASK;
  
  // NOTE: Reset is required to exit stop mode. Program execution 
  // will not continue to this point.
}
#endif // EFM8PDL_PWR_USE_STOP

void PWR_enterSuspend(uint8_t flags)
{
  uint8_t save_ie, save_clksel, save_flscl;
  SAVE_SFRPAGE;
  SFRPAGE = 0;

  // Disable interrupts until the system is awake and restored
  save_ie = IE;
  IE_EA = 0;

  // System clock must be HFOSC or LPOSC divided by 1 (see ref manual)
  // Set the system clock to LPOSC / 1
  save_clksel = CLKSEL;
  CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__LPOSC;
  while((CLKSEL & CLKSEL_CLKRDY__BMASK) == 0);

  // Select flash one-shot read timing for lowest power (see ref manual)
  save_flscl = FLSCL;
  FLSCL = FLSCL_BYPASS__ONE_SHOT;
  // Third op-code byte is indeterminate after clearing FLSCL.BYPASS (see errata)
  // This line will load the B register with an unknown value
  B = 0x55;

  // Enter suspend mode with the requested wake sources
  PMU0CF = PMU0CF_SUSPEND__START | (flags & PWR_PMU0CF_WAKE_ENABLES);

  // Execution resumes here when the device wakes up ..
  // .. execute four nop's first (see ref manual)
  // .. wait 2 cycles before reading PMU0CF (see ref manual)
  NOP(); NOP(); NOP(); NOP();

  // Restore flash read timing first
  FLSCL = save_flscl;

#if (EFM8PDL_PWR_AUTO_RSTWK_DELAY == 1)
  // If reset wake-up flag is set, delay for 15 usec (300 cycles @ 20MHz)
  // Ensures we don't re-enter a low power mode before the device can 
  // respond to a pin reset (see ref manual)
  if (PMU0CF & PWR_RST_WF)
  {
    ACC = 75;
    while (--ACC);  // 4 cycles per loop
  }
#endif // EFM8PDL_PWR_AUTO_RSTWK_DELAY

  // Next restore the system clock source and divider
  CLKSEL = save_clksel;
  while((CLKSEL & CLKSEL_CLKRDY__BMASK) == 0);

  // Finally restore the interrupt enable
  IE = save_ie;
  RESTORE_SFRPAGE;
}

void PWR_enterSleep(uint8_t flags)
{
  uint8_t save_ie, save_clksel, save_ioscen;
  SAVE_SFRPAGE;
  SFRPAGE = 0;

  // Disable interrupts until the system is awake and restored
  save_ie = IE;
  IE_EA = 0;

  // System clock must be LPOSC divided by 1 (see ref manual)
  save_clksel = CLKSEL;
  CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__LPOSC;
  while((CLKSEL & CLKSEL_CLKRDY__BMASK) == 0);

  // Disable HFOSC0 to avoid lock-up when exiting sleep (see ref manual)
  save_ioscen = HFO0CN & HFO0CN_IOSCEN__BMASK;
  HFO0CN &= ~HFO0CN_IOSCEN__BMASK;

  // Enter sleep mode with the requested wake sources
  PMU0CF = PMU0CF_SLEEP__START | (flags & PWR_PMU0CF_WAKE_ENABLES);

  // Execution resumes here when the device wakes up ..
  // .. execute four nop's first (see ref manual)
  NOP(); NOP(); NOP(); NOP();

#if (EFM8PDL_PWR_AUTO_RSTWK_DELAY == 1)
  // If reset wake-up flag is set, delay for 15 usec (300 cycles @ 20MHz)
  // Ensures we don't re-enter a low power mode before the device can 
  // respond to a pin reset (see ref manual)
  if (PMU0CF & PWR_RST_WF)
  {
    ACC = 75;
    while (--ACC);  // 4 cycles per loop
  }
#endif // EFM8PDL_PWR_AUTO_RSTWK_DELAY

  // Restore the system clock
  HFO0CN |= save_ioscen;
  CLKSEL = save_clksel;
  while((CLKSEL & CLKSEL_CLKRDY__BMASK) == 0);

  // Now restore the interrupt enable
  IE = save_ie;
  RESTORE_SFRPAGE;
}
