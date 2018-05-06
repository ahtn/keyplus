// Copyright (c) 2015 Josh Levine
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
// Source: https://github.com/bigjosh/SimpleNeoPixelDemo

#pragma once

// These values depend on which pin your string is connected to and what board you are using
// More info on how to find these at http://www.arduino.cc/en/Reference/PortManipulation

// These values are for digital pin 8 on an Arduino Yun or digital pin 12 on a DueMilinove
// Note that you could also include the DigitalWriteFast header file to not need to to this lookup.

/* #define PIXEL_PORT PORTB // Port of the pin the pixels are connected to */
/* #define PIXEL_DDR DDRB // Port of the pin the pixels are connected to */
/* #define PIXEL_BIT 4 // Bit of the pin the pixels are connected to */

#define PIXEL_PORT PORTE // Port of the pin the pixels are connected to
#define PIXEL_BIT (1 << 3) // Bit of the pin the pixels are connected to

void ledsetup(void);
void sendPixel( unsigned char r, unsigned char g , unsigned char b );
void show(void);
