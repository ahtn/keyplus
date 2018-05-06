/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "cslib_hwconfig.h"
#include <si_toolchain.h>
#include <stdio.h>
#include "cslib_sensor_descriptors.h"

code char* sensorDescriptors[DEF_NUM_SENSORS] =
{
 SENSOR_DESCRIPTOR_LIST
};

void outputsensorDescriptors(void)
{
   uint8_t index;
   printf("*SENSOR_DESCRIPTORS ");
   for(index = 0; index < DEF_NUM_SENSORS; index++)
   {
      printf("%s | ",sensorDescriptors[index]);
   }
   printf("\n");
}

