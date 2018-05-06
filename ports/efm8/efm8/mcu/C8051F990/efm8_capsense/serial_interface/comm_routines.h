/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef _COMMROUTINES_H
#define _COMMROUTINES_H

#include <si_toolchain.h>


typedef struct{
   char* header;
   uint8_t instances;
}HeaderStruct_t;

uint8_t OutputU8(uint8_t* buffer, uint8_t lengthh, uint8_t transmitconfig);
uint8_t OutputU16(uint8_t* buffer, uint8_t length, uint8_t transmitconfig);
uint8_t OutputString(uint8_t* buffer);
void CSLIB_commInit(void);
uint16_t getU16(void);
void outputHeaderCount(HeaderStruct_t);
void outputBreak(void);
void outputBeginHeader(void);
void outputNewLine(void);

void printOutputSingAct(uint16_t offset);
void printOutputDebAct(uint16_t offset);
void printOutputTDelta(uint16_t offset);

extern idata uint8_t bufferU8[];
extern idata uint16_t bufferU16[];

void printOutput(uint16_t, uint8_t);
extern uint16_t printBase;
extern uint16_t printSize;
extern uint16_t printCount;

// Implementation-specific information
#define UART_BAUDRATE    (921600L)           // Baud rate of UART in bps
//#define UART_BAUDRATE    (230400L)           // Baud rate of UART in bps
#define UART_SYSCLK      24500000L           // SYSCLK frequency in Hz
#define INCLUDE_SPACES 1


#endif
