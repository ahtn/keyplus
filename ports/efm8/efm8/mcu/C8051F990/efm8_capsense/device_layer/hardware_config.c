/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "cslib_hwconfig.h"
#include "hardware_routines.h"
#include "cslib_config.h"

/// @brief Derive thresholds at init based on config profile settings
idata uint16_t active_thresh[DEF_NUM_SENSORS];
idata uint16_t inactive_thresh[DEF_NUM_SENSORS];

// Default values in a one-to-one mapping with the sensor node.  These values
// are copied into the sensor node entry for that sensor at startup.
SI_SEGMENT_VARIABLE (CSLIB_muxValues[DEF_NUM_SENSORS], uint8_t, SI_SEG_CODE) =
{
  MUX_VALUE_ARRAY
};
// Default values in a one-to-one mapping with the sensor node.  These values
// are copied into the sensor node entry for that sensor at startup.
SI_SEGMENT_VARIABLE (CSLIB_gainValues[DEF_NUM_SENSORS], uint8_t, SI_SEG_CODE) =
{
  GAIN_VALUE_ARRAY
};

// Default values in a one-to-one mapping with the sensor node.  These values
// are copied into the sensor node entry for that sensor at startup.
SI_SEGMENT_VARIABLE (CSLIB_accumulationValues[DEF_NUM_SENSORS], uint8_t, SI_SEG_CODE) =
{
  ACCUMULATION_VALUE_ARRAY
};

SI_SEGMENT_VARIABLE (CSLIB_activeThreshold[DEF_NUM_SENSORS], uint8_t, SI_SEG_CODE) =
{
  ACTIVE_THRESHOLD_ARRAY
};
SI_SEGMENT_VARIABLE (CSLIB_inactiveThreshold[DEF_NUM_SENSORS], uint8_t, SI_SEG_CODE) =
{
  INACTIVE_THRESHOLD_ARRAY
};

SI_SEGMENT_VARIABLE (CSLIB_averageTouchDelta[DEF_NUM_SENSORS], uint8_t, SI_SEG_CODE) =
{
  AVERAGE_TOUCH_DELTA_ARRAY
};
