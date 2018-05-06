/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef _LOW_POWER_CONFIG_H
#define _LOW_POWER_CONFIG_H
#include <si_toolchain.h>

// Functions which must be defined with implementation-specific
// responsibilities.  These are called by LowPowerRoutines.c
void CSLIB_configureSensorForSleepModeCB(void);
void CSLIB_configureTimerForSleepModeCB(void);
void CSLIB_configureTimerForActiveModeCB(void);
void CSLIB_enterLowPowerStateCB(void);
void CSLIB_checkTimerCB(void);
extern xdata uint8_t timerTick;


#endif
