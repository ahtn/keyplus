/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/
/////////////////////////////////////////////////////////////////////////////
// Tick.c
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include "bsp.h"
#include "tick.h"

/////////////////////////////////////////////////////////////////////////////
// Globals
/////////////////////////////////////////////////////////////////////////////

static volatile uint16_t Ticks = 0;

/////////////////////////////////////////////////////////////////////////////
// Functions
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
// GetTickCount
//---------------------------------------------------------------------------
//
// Description - Return the system up time in milliseconds
//
// return - Number of milliseconds since system start.
//
uint16_t GetTickCount()
{
    uint16_t ticks;
    uint8_t save_page = SFRPAGE;

    // Disable Timer 3 interrupts
    SFRPAGE = 0x10;
    EIE1 &= ~EIE1_ET3__BMASK;

    ticks = Ticks;

    // Enable Timer 3 interrupts
    EIE1 |= EIE1_ET3__BMASK;
    SFRPAGE = save_page;

    return ticks;
}

//---------------------------------------------------------------------------
// Wait
//---------------------------------------------------------------------------
//
// Description - Wait the specified number of milliseconds
//
// ms - The number of milliseconds to wait
//
void Wait(uint16_t ms)
{
    uint16_t ticks = GetTickCount();

    while ((GetTickCount() - ticks) < ms);
}

//-----------------------------------------------------------------------------
// TIMER3_ISR
//-----------------------------------------------------------------------------
//
// TIMER3 ISR Content goes here. Remember to clear flag bits:
// TMR3CN::TF3H (Timer # High Byte Overflow Flag)
// TMR3CN::TF3L (Timer # Low Byte Overflow Flag)
//
// SFRPAGE automatically pushed/popped and set to 0x10
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER3_ISR, TIMER3_IRQn)
{
    // Overflows every 1 ms
    TMR3CN0 &= ~TMR3CN0_TF3H__BMASK;

    Ticks++;
}
