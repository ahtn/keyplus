/* This file has been prepared for Doxygen automatic documentation generation.*/
/*! \file *********************************************************************
 *
 * \brief
 *      XMEGA TWI master driver source file.
 *
 *      This file contains the function implementations the XMEGA master TWI
 *      driver.
 *
 *      The driver is not intended for size and/or speed critical code, since
 *      most functions are just a few lines of code, and the function call
 *      overhead would decrease code performance. The driver is intended for
 *      rapid prototyping and documentation purposes for getting started with
 *      the XMEGA TWI master module.
 *
 *      For size and/or speed critical code, it is recommended to copy the
 *      function contents directly into your application instead of making
 *      a function call.
 *
 *      Several functions use the following construct:
 *          "some_register = ... | (some_parameter ? SOME_BIT_bm : 0) | ..."
 *      Although the use of the ternary operator ( if ? then : else ) is
 *      discouraged, in some occasions the operator makes it possible to write
 *      pretty clean and neat code. In this driver, the construct is used to
 *      set or not set a configuration bit based on a boolean input parameter,
 *      such as the "some_parameter" in the example above.
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
 * $Revision: 1569 $
 * $Date: 2008-04-22 13:03:43 +0200 (ti, 22 apr 2008) $  \n
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

#include "twi_master_driver.h"


/*! \brief Initialize the TWI module.
 *
 *  TWI module initialization function.
 *  Enables master read and write interrupts.
 *  Remember to enable interrupts globally from the main application.
 *
 *  \param twi                      The TWI_Master_t struct instance.
 *  \param module                   The TWI module to use.
 *  \param intLevel                 Master interrupt level.
 *  \param baudRateRegisterSetting  The baud rate register value.
 */
void TWI_MasterInit(TWI_Master_t *twi,
                    TWI_t *module,
                    TWI_MASTER_INTLVL_t intLevel,
                    uint8_t baudRateRegisterSetting)
{
    twi->interface = module;
    twi->interface->MASTER.CTRLA = intLevel |
                                   TWI_MASTER_RIEN_bm |
                                   TWI_MASTER_WIEN_bm |
                                   TWI_MASTER_ENABLE_bm;
    twi->interface->MASTER.BAUD = baudRateRegisterSetting;
    twi->interface->MASTER.STATUS = TWI_MASTER_BUSSTATE_IDLE_gc;
}


/*! \brief Returns the TWI bus state.
 *
 *  Returns the TWI bus state (type defined in device headerfile),
 *  unknown, idle, owner or busy.
 *
 *  \param twi The TWI_Master_t struct instance.
 *
 *  \retval TWI_MASTER_BUSSTATE_UNKNOWN_gc Bus state is unknown.
 *  \retval TWI_MASTER_BUSSTATE_IDLE_gc    Bus state is idle.
 *  \retval TWI_MASTER_BUSSTATE_OWNER_gc   Bus state is owned by the master.
 *  \retval TWI_MASTER_BUSSTATE_BUSY_gc    Bus state is busy.
 */
TWI_MASTER_BUSSTATE_t TWI_MasterState(TWI_Master_t *twi)
{
    TWI_MASTER_BUSSTATE_t twi_status;
    twi_status = (TWI_MASTER_BUSSTATE_t) (twi->interface->MASTER.STATUS &
                                          TWI_MASTER_BUSSTATE_gm);
    return twi_status;
}


/*! \brief Returns true if transaction is ready.
 *
 *  This function returns a boolean whether the TWI Master is ready
 *  for a new transaction.
 *
 *  \param twi The TWI_Master_t struct instance.
 *
 *  \retval true  If transaction could be started.
 *  \retval false If transaction could not be started.
 */
bool TWI_MasterReady(TWI_Master_t *twi)
{
    bool twi_status = (twi->status & TWIM_STATUS_READY);
    return twi_status;
}


/*! \brief TWI write transaction.
 *
 *  This function is TWI Master wrapper for a write-only transaction.
 *
 *  \param twi          The TWI_Master_t struct instance.
 *  \param address      Slave address.
 *  \param writeData    Pointer to data to write.
 *  \param bytesToWrite Number of data bytes to write.
 *
 *  \retval true  If transaction could be started.
 *  \retval false If transaction could not be started.
 */
bool TWI_MasterWrite(TWI_Master_t *twi,
                     uint8_t address,
                     const uint8_t *writeData,
                     uint8_t bytesToWrite)
{
    bool twi_status = TWI_MasterWriteRead(twi, address, writeData, bytesToWrite, 0);
    return twi_status;
}


/*! \brief TWI read transaction.
 *
 *  This function is a TWI Maste wrapper for read-only transaction.
 *
 *  \param twi            The TWI_Master_t struct instance.
 *  \param address        The slave address.
 *  \param bytesToRead    The number of bytes to read.
 *
 *  \retval true  If transaction could be started.
 *  \retval false If transaction could not be started.
 */
bool TWI_MasterRead(TWI_Master_t *twi,
                    uint8_t address,
                    uint8_t bytesToRead)
{
    bool twi_status = TWI_MasterWriteRead(twi, address, 0, 0, bytesToRead);
    return twi_status;
}


/*! \brief TWI write and/or read transaction.
 *
 *  This function is a TWI Master write and/or read transaction. The function
 *  can be used to both write and/or read bytes to/from the TWI Slave in one
 *  transaction.
 *
 *  \param twi            The TWI_Master_t struct instance.
 *  \param address        The slave address.
 *  \param writeData      Pointer to data to write.
 *  \param bytesToWrite   Number of bytes to write.
 *  \param bytesToRead    Number of bytes to read.
 *
 *  \retval true  If transaction could be started.
 *  \retval false If transaction could not be started.
 */
bool TWI_MasterWriteRead(TWI_Master_t *twi,
                         uint8_t address,
                         const uint8_t *writeData,
                         uint8_t bytesToWrite,
                         uint8_t bytesToRead)
{
    /*Parameter sanity check. */
    if (bytesToWrite > TWIM_WRITE_BUFFER_SIZE) {
        return false;
    }
    if (bytesToRead > TWIM_READ_BUFFER_SIZE) {
        return false;
    }

    /*Initiate transaction if bus is ready. */
    if (twi->status == TWIM_STATUS_READY) {

        twi->status = TWIM_STATUS_BUSY;
        twi->result = TWIM_RESULT_UNKNOWN;

        twi->address = address<<1;

        /* Fill write data buffer. */
        for (uint8_t bufferIndex=0; bufferIndex < bytesToWrite; bufferIndex++) {
            twi->writeData[bufferIndex] = writeData[bufferIndex];
        }

        twi->bytesToWrite = bytesToWrite;
        twi->bytesToRead = bytesToRead;
        twi->bytesWritten = 0;
        twi->bytesRead = 0;

        /* If write command, send the START condition + Address +
         * 'R/_W = 0'
         */
        if (twi->bytesToWrite > 0) {
            uint8_t writeAddress = twi->address & ~0x01;
            twi->interface->MASTER.ADDR = writeAddress;
        }

        /* If read command, send the START condition + Address +
         * 'R/_W = 1'
         */
        else if (twi->bytesToRead > 0) {
            uint8_t readAddress = twi->address | 0x01;
            twi->interface->MASTER.ADDR = readAddress;
        }
        return true;
    } else {
        return false;
    }
}


/*! \brief Common TWI master interrupt service routine.
 *
 *  Check current status and calls the appropriate handler.
 *
 *  \param twi  The TWI_Master_t struct instance.
 */
void TWI_MasterInterruptHandler(TWI_Master_t *twi)
{
    uint8_t currentStatus = twi->interface->MASTER.STATUS;

    /* If arbitration lost or bus error. */
    if ((currentStatus & TWI_MASTER_ARBLOST_bm) ||
        (currentStatus & TWI_MASTER_BUSERR_bm)) {

        TWI_MasterArbitrationLostBusErrorHandler(twi);
    }

    /* If master write interrupt. */
    else if (currentStatus & TWI_MASTER_WIF_bm) {
        TWI_MasterWriteHandler(twi);
    }

    /* If master read interrupt. */
    else if (currentStatus & TWI_MASTER_RIF_bm) {
        TWI_MasterReadHandler(twi);
    }

    /* If unexpected state. */
    else {
        TWI_MasterTransactionFinished(twi, TWIM_RESULT_FAIL);
    }
}


/*! \brief TWI master arbitration lost and bus error interrupt handler.
 *
 *  Handles TWI responses to lost arbitration and bus error.
 *
 *  \param twi  The TWI_Master_t struct instance.
 */
void TWI_MasterArbitrationLostBusErrorHandler(TWI_Master_t *twi)
{
    uint8_t currentStatus = twi->interface->MASTER.STATUS;

    /* If bus error. */
    if (currentStatus & TWI_MASTER_BUSERR_bm) {
        twi->result = TWIM_RESULT_BUS_ERROR;
    }
    /* If arbitration lost. */
    else {
        twi->result = TWIM_RESULT_ARBITRATION_LOST;
    }

    /* Clear interrupt flag. */
    twi->interface->MASTER.STATUS = currentStatus | TWI_MASTER_ARBLOST_bm;

    twi->status = TWIM_STATUS_READY;
}


/*! \brief TWI master write interrupt handler.
 *
 *  Handles TWI transactions (master write) and responses to (N)ACK.
 *
 *  \param twi The TWI_Master_t struct instance.
 */
void TWI_MasterWriteHandler(TWI_Master_t *twi)
{
    /* Local variables used in if tests to avoid compiler warning. */
    uint8_t bytesToWrite  = twi->bytesToWrite;
    uint8_t bytesToRead   = twi->bytesToRead;

    /* If NOT acknowledged (NACK) by slave cancel the transaction. */
    if (twi->interface->MASTER.STATUS & TWI_MASTER_RXACK_bm) {
        twi->interface->MASTER.CTRLC = TWI_MASTER_CMD_STOP_gc;
        twi->result = TWIM_RESULT_NACK_RECEIVED;
        twi->status = TWIM_STATUS_READY;
    }

    /* If more bytes to write, send data. */
    else if (twi->bytesWritten < bytesToWrite) {
        uint8_t data = twi->writeData[twi->bytesWritten];
        twi->interface->MASTER.DATA = data;
        ++twi->bytesWritten;
    }

    /* If bytes to read, send repeated START condition + Address +
     * 'R/_W = 1'
     */
    else if (twi->bytesRead < bytesToRead) {
        uint8_t readAddress = twi->address | 0x01;
        twi->interface->MASTER.ADDR = readAddress;
    }

    /* If transaction finished, send STOP condition and set RESULT OK. */
    else {
        twi->interface->MASTER.CTRLC = TWI_MASTER_CMD_STOP_gc;
        TWI_MasterTransactionFinished(twi, TWIM_RESULT_OK);
    }
}


/*! \brief TWI master read interrupt handler.
 *
 *  This is the master read interrupt handler that takes care of
 *  reading bytes from the TWI slave.
 *
 *  \param twi The TWI_Master_t struct instance.
 */
void TWI_MasterReadHandler(TWI_Master_t *twi)
{
    /* Fetch data if bytes to be read. */
    if (twi->bytesRead < TWIM_READ_BUFFER_SIZE) {
        uint8_t data = twi->interface->MASTER.DATA;
        twi->readData[twi->bytesRead] = data;
        twi->bytesRead++;
    }

    /* If buffer overflow, issue STOP and BUFFER_OVERFLOW condition. */
    else {
        twi->interface->MASTER.CTRLC = TWI_MASTER_CMD_STOP_gc;
        TWI_MasterTransactionFinished(twi, TWIM_RESULT_BUFFER_OVERFLOW);
    }

    /* Local variable used in if test to avoid compiler warning. */
    uint8_t bytesToRead = twi->bytesToRead;

    /* If more bytes to read, issue ACK and start a byte read. */
    if (twi->bytesRead < bytesToRead) {
        twi->interface->MASTER.CTRLC = TWI_MASTER_CMD_RECVTRANS_gc;
    }

    /* If transaction finished, issue NACK and STOP condition. */
    else {
        twi->interface->MASTER.CTRLC = TWI_MASTER_ACKACT_bm |
                                       TWI_MASTER_CMD_STOP_gc;
        TWI_MasterTransactionFinished(twi, TWIM_RESULT_OK);
    }
}


/*! \brief TWI transaction finished handler.
 *
 *  Prepares module for new transaction.
 *
 *  \param twi     The TWI_Master_t struct instance.
 *  \param result  The result of the operation.
 */
void TWI_MasterTransactionFinished(TWI_Master_t *twi, uint8_t result)
{
    twi->result = result;
    twi->status = TWIM_STATUS_READY;
}
