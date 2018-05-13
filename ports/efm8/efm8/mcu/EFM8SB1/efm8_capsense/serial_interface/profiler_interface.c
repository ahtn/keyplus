/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "cslib_hwconfig.h"
#include "profiler_interface.h"
#include "cslib.h"
#include "comm_routines.h"
//#include "SliderLibrary.h"
//#include "SliderConfig.h"
#include "cslib_sensor_descriptors.h"
//#include "SliderDescriptors.h"

void printOutput(uint16_t offset, uint8_t bytes);





#define HEADER_TYPE_COUNT 9

idata HeaderStruct_t headerEntries[HEADER_TYPE_COUNT] = {

{"BASELINE", DEF_NUM_SENSORS},
{"RAW", DEF_NUM_SENSORS},
{"SINGACT", DEF_NUM_SENSORS},
{"DEBACT", DEF_NUM_SENSORS},
{"TDELTA", DEF_NUM_SENSORS},
{"EXPVAL", DEF_NUM_SENSORS},
//{"SLIDER", DEF_NUM_SLIDERS},
{"NOISEEST", 1},
{"INACTTHR", DEF_NUM_SENSORS},
{"ACTTHR", DEF_NUM_SENSORS},
};

idata uint8_t offsetArray[HEADER_TYPE_COUNT];


//-----------------------------------------------------------------------------
// Local variables and macros
//-----------------------------------------------------------------------------



uint8_t needANewLine = 0;                 // Flag to tell output to add a
                                       // carriage return

// These macros are called throughout the file to add carriage returns
// to the output byte stream as needed
#define NEED_NEWLINE() needANewLine = 1
#define CLEAR_NEWLINE() needANewLine = 0

// This flag is a one-shot that will output the defined header string
// at the start of the string.  This example requires a device reset
// before the header is ever sent again.
uint8_t sendHeader = 1;

//-----------------------------------------------------------------------------
// Local function prototypes
//-----------------------------------------------------------------------------

void printHeader(void);               // Generates and outputs a header
                                       // describing the data in the stream


//-----------------------------------------------------------------------------
// CSLIB_CommUpdate()
//-----------------------------------------------------------------------------
//
// Exposed top-level debug output function.  Outputs one line of data output
// for each call.  Output controls are compile-time switches found in
// profiler_interface.h.  Function prints all of defined variable types in
// sequence before printing the next defined variable type.  For exmample,
// a configuration to print raw and baseline data for a system with two
// channels would print:
// <RAW_0> <RAW_1> <BASELINE_0> <BASELINE_1>
//

void CSLIB_commUpdate(void)
{
   xdata uint16_t value[DEF_NUM_SENSORS];

   // This is set during device initialization as a one-shot
   if(sendHeader == 1)
   {
      printHeader();
      sendHeader = 0;
   }

#if OUTPUT_MODE == FULL_OUTPUT_RX_FROM_SENSOR


   printBase = &CSLIB_node;
   printSize = sizeof(CSLIB_node[0]);
   printCount = DEF_NUM_SENSORS;

   //"BASELINE",
   printOutput(offsetArray[0], 2);
   //"RAW",
   printOutput(offsetArray[1], 2);
   //"SINGACT",
   printOutputSingAct(offsetArray[2]);
   //"DEBACT",
   printOutputDebAct(offsetArray[3]);
   //"TDELTA",
   printOutputTDelta(offsetArray[4]);
   //"EXPVAL",
   printOutput(offsetArray[6], 2);
   /*
   //"SLIDER"
   printBase = &Slider;
   printSize = sizeof(Slider[0]);
   */

   //"NOISEEST",
   // Have to copy from idata CSLIB_systemNoiseAverage into xdata variable for printOutput()
   value[0] = (uint16_t)CSLIB_systemNoiseAverage;
   printBase = (uint16_t)&value[0];
   printCount = 1;
   printOutput(0, 2);

   //"INACTTHR",
   // Have to copy CODE CSLIB_inactiveThreshold into xdata variable for printOutput()
   for( printSize = 0; printSize < DEF_NUM_SENSORS; printSize++)
   {
	   value[printSize] = CSLIB_inactiveThreshold[printSize];
   }
   printBase = (uint16_t)&value[0];
   printSize = sizeof(uint16_t);
   printCount = DEF_NUM_SENSORS;
   printOutput( 0, sizeof(uint16_t));

   //"ACTTHR",
   // Have to copy CODE CSLIB_activeThreshold into xdata variable for printOutput()
   for( printSize = 0; printSize < DEF_NUM_SENSORS; printSize++)
   {
	   value[printSize] = CSLIB_activeThreshold[printSize];
   }
   printBase = (uint16_t)&value[0];
   printSize = sizeof(uint16_t);
   printCount = DEF_NUM_SENSORS;
   printOutput( 0, sizeof(uint16_t));

   outputNewLine();
   
   for( value[0] = 0; value[0] < 50; value[0]++ )
   {
	   //Empty loop to add delay after serial output.
   }
#endif



}




//-----------------------------------------------------------------------------
// printHeader
//-----------------------------------------------------------------------------
//
// Function defines data bytes to follow with byte-by-byte designators.
//

void calculateOffsets(void)
{
/*
"BASELINE",
"RAW",
"PROCESS",
"SINGACT",
"DEBACT",
"TDELTA",
"NOISE",
"EXPVAL",
"NOISEEST"
*/
#if OUTPUT_MODE == FULL_OUTPUT_RX_FROM_SENSOR
   uint16_t base = &CSLIB_node;
   // "BASELINE",
   offsetArray[0] = (uint16_t)&(CSLIB_node[0].currentBaseline) - base;
   // "RAW",
   offsetArray[1] = (uint16_t)&(CSLIB_node[0].rawBuffer[0]) - base;
   // "SINGACT",
   offsetArray[2] = (uint16_t)&(CSLIB_node[0].activeIndicator) - base;
   // "DEBACT",
   offsetArray[3] = (uint16_t)&(CSLIB_node[0].activeIndicator) - base;
   // "TDELTA",
   offsetArray[4] = (uint16_t)&(CSLIB_node[0].touchDeltaDiv16) - base;
   // "EXPVAL",
   offsetArray[6] = (uint16_t)&(CSLIB_node[0].expValue[0]) - base;
   // "NOISEEST"
   // Handled above, does not come from CSLIB_node[]
   // "ACTTHR",
   // Handled above, does not come from CSLIB_node[]
   // "INACTTHR",
   // Handled above, does not come from CSLIB_node[]



#endif
}

void printHeader(void)
{
   uint8_t index;
   outputNewLine();
#ifdef HAS_SENSOR_DESCRIPTORS
   outputsensorDescriptors();
#endif
#ifdef HAS_SLIDER_DESCRIPTORS
   OutputSliderDescriptors();
#endif
   outputBeginHeader();

#if OUTPUT_MODE == FULL_OUTPUT_RX_FROM_SENSOR
   for(index = 0; index < HEADER_TYPE_COUNT; index++)
   {
      outputHeaderCount(headerEntries[index]);
      outputBreak();
   }
#endif

#if OUTPUT_MODE == FULL_OUTPUT_RX_FROM_FILE
   for(index = 0; index < HEADER_TYPE_COUNT; index++)
   {
      outputHeaderCount(HeaderStrings[index], NUM_SENSORS);
      outputBreak();
   }
#endif
   outputNewLine();
   calculateOffsets();


}

