/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef _HARDWARE_ROUTINES_H
#define _HARDWARE_ROUTINES_H
#include <si_toolchain.h>


// Note: the functions below are hardware-specific callbacks used by the library to
// perform capacitive sense scanning.  All must be defined
// in the project in order for the library to function correctly.
uint16_t CSLIB_executeConversionCB(void);
uint16_t scanSensor(uint8_t);
void configureSensorForActiveMode(void);
void nodeInit(uint8_t sensor_index);
uint8_t determine_highest_gain(void);
typedef struct
{
   uint8_t mux;
   uint8_t accumulation;
   uint8_t gain;
} TechSpecificStruct_t;


extern SI_SEGMENT_VARIABLE (CSLIB_gainValues[], uint8_t, SI_SEG_CODE);
extern SI_SEGMENT_VARIABLE (CSLIB_muxValues[], uint8_t, SI_SEG_CODE);
extern SI_SEGMENT_VARIABLE (CSLIB_accumulationValues[], uint8_t, SI_SEG_CODE);


#define __HAS_DEVICE_LAYER

#endif
