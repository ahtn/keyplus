/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include <compiler_defs.h>

#include "comm_routines.h"

#include <stdio.h>
#include <stdlib.h>
#include "SI_C8051F990_Defs.h"


//-----------------------------------------------------------------------------
// Local variables and macros
//-----------------------------------------------------------------------------
// NOTE: Calls to serial interface transfers using these buffers as
// parameters must size data appropriately or increase the buffer sizes defined
// below.
idata uint8_t bufferU8[10];
idata uint16_t bufferU16[10];


volatile uint16_t printBase;
volatile uint16_t printSize;
volatile uint16_t printCount;

//-----------------------------------------------------------------------------
// Local function prototypes
//-----------------------------------------------------------------------------

void UART0_init(void);
char getChar (void);
uint16_t getU8(void);
/*
//-----------------------------------------------------------------------------
// OutputU8
//-----------------------------------------------------------------------------
//
// Function can return a byte if the serial interface
// has the potential for arbitration issues.  This implementation always returns 1.
// Function outputs a buffer of 1-byte values.  If INCLUDE_SPACES is set in the
// <transmitconfig> parameter, one space is added between bytes.
uint8_t OutputU8(uint8_t* buffer, uint8_t length, uint8_t transmitconfig)
{
   uint8_t index;

   for(index = 0; index < length; index++)
   {
      printf("%bd", buffer[index]);
      if(transmitconfig & INCLUDE_SPACES)
         printf(" ");
   }

   return 1;
}



//-----------------------------------------------------------------------------
// OutputU16
//-----------------------------------------------------------------------------
//
// Function outputs a buffer of 2-byte values.  If INCLUDE_SPACES is set in the
// <transmitconfig> parameter, one space is added between bytes.
// Function can return a byte if the serial interface
// has the potential for arbitration issues.  This implementation always returns 1.
uint8_t OutputU16(uint16_t* buffer, uint8_t length, uint8_t transmitconfig)
{
   uint8_t index;

   for(index = 0; index < length; index++)
   {
      printf("%u", buffer[index]);
      if(transmitconfig & INCLUDE_SPACES)
         printf(" ");
   }

   return 1;
}



//-----------------------------------------------------------------------------
// OutputString
//-----------------------------------------------------------------------------
//
// Function outputs a string.  Function can return a byte if the serial interface
// has the potential for arbitration issues.  This implementation always returns 1.
uint8_t OutputString(uint8_t* buffer)
{
   printf("%s",buffer);

   return 1;
}

*/
//-----------------------------------------------------------------------------
// getChar
//-----------------------------------------------------------------------------
//
// Low-level getChar replacement routine.  Reads one byte from UART and
// returns that byte.
//
char getChar (void)
{
  char c;

  while (!SCON0_RI);
  SCON0_RI = 0;
  c = SBUF0;
  return c;
}


//-----------------------------------------------------------------------------
// getU16
//-----------------------------------------------------------------------------
//
// Routine that reads a 2-byte unsigned integer using the low-level
// getChar() routine.  This function excepts data in decimal format and
// expects data to be delimited by space (' ') characters.
//
uint16_t getU16(void)
{
   uint8_t character;
   uint16_t output = 0;
   do
   {
      character = getChar();
   }
   while((character <= '0') || (character >= '9'));

   do
   {
      output = output * 10 + character - '0';
      character = getChar();

   }
   while((character >= '0') && (character <= '9'));

   return output;


}

uint16_t getU8(void)
{
   uint8_t character;
   uint16_t output = 0;

   character = getChar();

   return output;


}

//-----------------------------------------------------------------------------
// Comm_Init
//-----------------------------------------------------------------------------
//
// Function should configure all non-port pin resources dedicated to the serial
// interface.  Shared resources such as port pin configuration should
// be handled in DeviceInit.c.
// Function is called in the systemInit routine inside DeviceInit.c
void CSLIB_commInit(void)
{
   UART0_init();

   P0MDOUT |= 0x10;                    // Enable UTX as push-pull output
   XBR0    = 0x01;                     // Enable UART on P0.4(TX) and P0.5(RX)
   XBR2    = 0x40;                     // Enable crossbar and weak pull-ups



}

//-----------------------------------------------------------------------------
// UART0_init
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// Configure the UART0 using Timer1, for <BAUDRATE> and 8-N-1.
//-----------------------------------------------------------------------------

void UART0_init ()
{
   SCON0 = 0x10;                       // SCON0: 8-bit variable bit rate
                                       //        level of STOP bit is ignored
                                       //        RX enabled
                                       //        ninth bits are zeros
                                       //        clear RI0 and TI0 bits
   #if (UART_SYSCLK/UART_BAUDRATE/2/256 < 1)
      TH1 = -(UART_SYSCLK/UART_BAUDRATE/2);
      CKCON &= ~0x0B;                  // T1M = 1; SCA1:0 = xx
      CKCON |=  0x08;
   #elif (UART_SYSCLK/UART_BAUDRATE/2/256 < 4)
      TH1 = -(UART_SYSCLK/UART_BAUDRATE/2/4);
      CKCON &= ~0x0B;                  // T1M = 0; SCA1:0 = 01
      CKCON |=  0x01;
   #elif (UART_SYSCLK/UART_BAUDRATE/2/256 < 12)
      TH1 = -(UART_SYSCLK/UART_BAUDRATE/2/12);
      CKCON &= ~0x0B;                  // T1M = 0; SCA1:0 = 00
   #else
      TH1 = -(UART_SYSCLK/UART_BAUDRATE/2/48);
      CKCON &= ~0x0B;                  // T1M = 0; SCA1:0 = 10
      CKCON |=  0x02;
   #endif

   TL1 = TH1;                          // Init Timer1
   TMOD &= ~0xf0;                      // TMOD: timer 1 in 8-bit autoreload
   TMOD |=  0x20;
   TCON_TR1 = 1;                            // START Timer1
   SCON0_TI = 1;                            // Indicate TX0 ready

}


void outputHeaderCount(HeaderStruct_t headerEntry)
{
   uint8_t index;
   if(headerEntry.instances > 1)
      for(index = 0; index < headerEntry.instances; index++)
      {
         printf("%s_%bd ", headerEntry.header,index);
      }
   else
      printf("%s ", headerEntry.header);
}
void outputBreak(void)
{
   printf(" | ");
}

void outputBeginHeader(void)
{
   printf("*HEADER ");
}

void outputNewLine(void)
{
   printf("\n");
}

void printOutputSingAct(uint16_t offset)
{
	volatile uint8_t index, output;
	uint8_t xdata *ptr;
	   //*((char code *) 0x8000)

	   ptr = ((uint8_t xdata *)(printBase + offset));

	   for(index = 0; index < printCount; index++)
	   {

	         output = *ptr;
	         if(output & 0x40)
	         {
	        	 printf("1 ");
	         }
	         else
	         {
	        	 printf("0 ");
	         }
	         ptr = ptr + printSize;
	   }

}
void printOutputDebAct(uint16_t offset)
{
	volatile uint8_t index, output;
	uint8_t xdata *ptr;
	   //*((char code *) 0x8000)

	   ptr = ((uint8_t xdata *)(printBase + offset));

	   for(index = 0; index < printCount; index++)
	   {

	         output = *ptr;
	         if(output & 0x80)
	         {
	        	 printf("1 ");
	         }
	         else
	         {
	        	 printf("0 ");
	         }
	         ptr = ptr + printSize;
	   }

}

void printOutputTDelta(uint16_t offset)
{
	uint8_t index;
	uint8_t xdata *ptr;
	ptr = ((uint8_t xdata *)(printBase + offset));
	   for(index = 0; index < printCount; index++)
	   {

	      printf("%5u ", *(uint16_t*)ptr * 4);

	      ptr = ptr + printSize;
	   }
}

void printOutput(uint16_t offset, uint8_t bytes)
{
   uint8_t index;
   //*((char code *) 0x8000)
   uint8_t xdata *ptr;
   ptr = ((uint8_t xdata *)(printBase + offset));

   for(index = 0; index < printCount; index++)
   {
      if(bytes == 2)
      {
         printf("%5u ", *(uint16_t*)ptr);
      }
      else if(bytes == 1)
         printf("%3bu ", *ptr);

      ptr = ptr + printSize;
   }
}
