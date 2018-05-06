/* This file has been prepared for Doxygen automatic documentation generation.*/
/*! \file *********************************************************************
 *
 * \brief  XMEGA TWI driver example source.
 *
 *      This file contains an example application that demonstrates the TWI
 *      master and slave driver. It shows how to set up one TWI module as both
 *      master and slave, and communicate with itself.
 *
 *      The recommended test setup for this application is to connect 10K
 *      pull-up resistors on PC0 (SDA) and PC1 (SCL). Connect a 10-pin cable
 *      between the PORTD and SWITCHES, and PORTE and LEDS.
 *
 * \par Application note:
 *      AVR1308: Using the XMEGA TWI
 *
 * \par Documentation
 *      For comprehensive code documentation, supported compilers, compiler
 *      settings and supported devices see readme.html
 *
 * \author
 *      Atmel Corporation: http://www.atmel.com \n
 *      Support email: avr@atmel.com
 *
 * $Revision: 2660 $
 * $Date: 2009-08-11 12:28:58 +0200 (ti, 11 aug 2009) $  \n
 *
 * Copyright (c) 2008, Atmel Corporation All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. The name of ATMEL may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY AND
 * SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
#include "avr_compiler.h"
#include "twi_master_driver.h"
#include "twi_slave_driver.h"

/*! Defining an example slave address. */
#define SLAVE_ADDRESS    0x55

/*! Defining number of bytes in buffer. */
#define NUM_BYTES        8

/*! CPU speed 2MHz, BAUDRATE 100kHz and Baudrate Register Settings */
#define CPU_SPEED       2000000
#define BAUDRATE    100000
#define TWI_BAUDSETTING TWI_BAUD(CPU_SPEED, BAUDRATE)


/* Global variables */
TWI_Master_t twiMaster;    /*!< TWI master module. */
TWI_Slave_t twiSlave;      /*!< TWI slave module. */


/*! Buffer with test data to send.*/
uint8_t sendBuffer[NUM_BYTES] = {0x55, 0xAA, 0xF0, 0x0F, 0xB0, 0x0B, 0xDE, 0xAD};


/*! Simple function that invert the received value in the sendbuffer. This
 *  function is used in the driver and passed on as a pointer to the driver.
 */
void TWIC_SlaveProcessData(void)
{
    uint8_t bufIndex = twiSlave.bytesReceived;
    twiSlave.sendData[bufIndex] = (~twiSlave.receivedData[bufIndex]);
}


/*! /brief Example code
 *
 *  Example code that reads the key pressed and show a value from the buffer,
 *  sends the value to the slave and read back the processed value which will
 *  be inverted and displayed after key release.
 */
int main(void)
{
    /* Initialize PORTE for output and PORTD for inverted input. */
    PORTE.DIRSET = 0xFF;
    PORTD.DIRCLR = 0xFF;
    PORTCFG.MPCMASK = 0xFF;
    PORTD.PIN0CTRL |= PORT_INVEN_bm;
//      PORTCFG.MPCMASK = 0xFF;
//      PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_OPC_gm) | PORT_OPC_PULLUP_gc;

    // Enable internal pull-up on PC0, PC1.. Uncomment if you don't have external pullups
//  PORTCFG.MPCMASK = 0x03; // Configure several PINxCTRL registers at the same time
//  PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_OPC_gm) | PORT_OPC_PULLUP_gc; //Enable pull-up to get a defined level on the switches



    /* Initialize TWI master. */
    TWI_MasterInit(&twiMaster,
                   &TWIC,
                   TWI_MASTER_INTLVL_LO_gc,
                   TWI_BAUDSETTING);

    /* Initialize TWI slave. */
    TWI_SlaveInitializeDriver(&twiSlave, &TWIC, TWIC_SlaveProcessData);
    TWI_SlaveInitializeModule(&twiSlave,
                              SLAVE_ADDRESS,
                              TWI_SLAVE_INTLVL_LO_gc);

    /* Enable LO interrupt level. */
    PMIC.CTRL |= PMIC_LOLVLEN_bm;
    sei();

    uint8_t BufPos = 0;
    while (1) {
                while(!PORTD.IN); /* Wait for user to press button */

        switch(PORTD.IN){
            case (PIN0_bm):  BufPos = 0; break;
            case (PIN1_bm):  BufPos = 1; break;
            case (PIN2_bm):  BufPos = 2; break;
            case (PIN3_bm):  BufPos = 3; break;
            case (PIN4_bm):  BufPos = 4; break;
            case (PIN5_bm):  BufPos = 5; break;
            case (PIN6_bm):  BufPos = 6; break;
            case (PIN7_bm):  BufPos = 7; break;
            default:    break;
        }

        /* Show the byte to send while holding down the key. */
        while(PORTD.IN != 0x00){
            PORTE.OUT = sendBuffer[BufPos];
        }

        TWI_MasterWriteRead(&twiMaster,
                            SLAVE_ADDRESS,
                            &sendBuffer[BufPos],
                            1,
                            1);


        while (twiMaster.status != TWIM_STATUS_READY) {
            /* Wait until transaction is complete. */
        }

        /* Show the sent byte received and processed on LEDs. */
        PORTE.OUT = (twiMaster.readData[0]);

                while(PORTD.IN); /* Wait for user to release button */
    }
}

/*! TWIC Master Interrupt vector. */
ISR(TWIC_TWIM_vect)
{
    TWI_MasterInterruptHandler(&twiMaster);
}

/*! TWIC Slave Interrupt vector. */
ISR(TWIC_TWIS_vect)
{
    TWI_SlaveInterruptHandler(&twiSlave);
}
