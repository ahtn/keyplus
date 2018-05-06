/******************************************************************************
 * Copyright (c) 2014 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#ifndef __I2C_0_H__
#define __I2C_0_H__

#include "smb_0.h"
#include "efm8_config.h"

/***************************************************************************//**
 *
 * @addtogroup i2c0 I2C0 Legacy Driver
 * @{
 *
 * These function-like macros use legacy name I2C0 instead of SMB0 in
 * order for backwards compatibility. All I2C0 macros are replaced by
 * their corresponding SMB0 functions at compile time. It is highly
 * suggested to replace all I2C0 macros with the corresponding SMB0
 * function wherever possible.
 *
 * See corresponding smb_0.h and smb_0.c for information on usage
 *
 ******************************************************************************/

// Legacy I2C0 Driver API Names
#warning "Deprecated I2C_0 API naming is being used. Switch over to SMB_0 driver instead."

//Configuration defaults
#ifndef IS_DOXYGEN
  #define IS_DOXYGEN 0
#endif

#ifndef EFM8PDL_I2C0_USE_STATEMACHINE
  #define EFM8PDL_I2C0_USE_STATEMACHINE 0
#endif

#ifndef EFM8PDL_I2C0_USE_BUFFER
  #if (EFM8PDL_I2C0_USE_STATEMACHINE == 1)
    #define EFM8PDL_I2C0_USE_BUFFER 0
  #else
    #define EFM8PDL_I2C0_USE_BUFFER 1
  #endif
#endif

#if ((EFM8PDL_I2C0_USE_STATEMACHINE == 1) && (EFM8PDL_I2C0_USE_BUFFER == 1))
#error("EFM8PDL_I2C0_USE_STATEMACHINE and EFM8PDL_I2C0_USE_BUFFER can not be used at the same time. Disable one.")
#endif

#ifndef EFM8PDL_I2C0_MASTER_RETRIES
  #define EFM8PDL_I2C0_MASTER_RETRIES 255
#endif
#ifndef EFM8PDL_I2C0_TX_BUFTYPE
  #define EFM8PDL_I2C0_TX_BUFTYPE SI_SEG_XDATA
#endif
#ifndef EFM8PDL_I2C0_RX_BUFTYPE
  #define EFM8PDL_I2C0_RX_BUFTYPE SI_SEG_XDATA
#endif
                                                              
#define I2C0_MASTER_SF                        SMB0_MASTER_SF  
#define I2C0_TXMODE_SF                        SMB0_TXMODE_SF  
#define I2C0_START_SF                         SMB0_START_SF   
#define I2C0_STOP_SF                          SMB0_STOP_SF    
#define I2C0_ACKREQ_SF                        SMB0_ACKREQ_SF  
#define I2C0_ARBLOST_SF                       SMB0_ARBLOST_SF 
#define I2C0_ACK_SF                           SMB0_ACK_SF     
                                              
// Runtime API                                
//typedef enum                                
//{                                           
#define I2C0_MASTER_START                     SMB0_MASTER_START     
#define I2C0_MASTER_TXDATA                    SMB0_MASTER_TXDATA    
#define I2C0_MASTER_RXDATA                    SMB0_MASTER_RXDATA    
#define I2C0_SLAVE_ADDRESS                    SMB0_SLAVE_ADDRESS    
#define I2C0_SLAVE_RX_STOP                    SMB0_SLAVE_RX_STOP    
#define I2C0_SLAVE_RXDATA                     SMB0_SLAVE_RXDATA     
#define I2C0_SLAVE_TXDATA                     SMB0_SLAVE_TXDATA     
#define I2C0_SLAVE_TX_STOP                    SMB0_SLAVE_TX_STOP    
//} I2C0_State_t;
#define I2C0_State_t                          SMB0_State_t

                                              
#define I2C0_getIntFlag()                     SMB0_getIntFlag()
#define I2C0_clearIntFlag()                   SMB0_clearIntFlag()
#define I2C0_getStatusFlag(flag)              SMB0_getStatusFlag(flag)
#define I2C0_setStatusFlag(flag, state)       SMB0_setStatusFlag(flag, state)
#define I2C0_read()                           SMB0_read()
#define I2C0_write(value)                     SMB0_write(value)
#define I2C0_abort()                          SMB0_abort()
#define I2C0_ack(ack)                         SMB0_ack(ack)
                                              
//#if EFM8PDL_I2C0_USE_MASTER == 1            
#define I2C0_start()                          SMB0_start()
#define I2C0_stop()                           SMB0_stop()
                                              
// Initialization API                         
//typedef enum                                
//{                                           
#define I2C0_TIMER0                           SMB0_TIMER0            
#define I2C0_TIMER1                           SMB0_TIMER1            
#define I2C0_TIMER2_HIGH                      SMB0_TIMER2_HIGH       
#define I2C0_TIMER2_LOW                       SMB0_TIMER2_LOW        
//} I2C0_Timebase_t;                          
#define I2C0_Timebase_t                       SMB0_Timebase_t

#define I2C0_init(timebase, sclLow)           SMB0_init(timebase, sclLow)
#define I2C0_initSlaveAddress(address, mask)  SMB0_initSlaveAddress(address, mask)
#define I2C0_reset()                          SMB0_reset()

// StateMachine API
#if (EFM8PDL_SMB0_USE_STATEMACHINE == 1) || IS_DOXYGEN
#define I2C0_ISR                              SMB0_ISR
#endif // !EFM8PDL_SMB0_USE_STATEMACHINE

// Buffered API
#if (EFM8PDL_I2C0_USE_BUFFER == 1) || IS_DOXYGEN
//typedef enum
//{
#define I2C0_ARBLOST_ERROR                    SMB0_ARBLOST_ERROR    
#define I2C0_NACK_ERROR                       SMB0_NACK_ERROR       
#define I2C0_UNKNOWN_ERROR                    SMB0_UNKNOWN_ERROR    
#define I2C0_TXUNDER_ERROR                    SMB0_TXUNDER_ERROR    
//} I2C0_TransferError_t;
#define I2C0_TransferError_t                  SMB0_TransferError_t

#define I2C0_transfer(address, txBuffer, rxBuffer, tx_len, rx_len)  SMB0_transfer(address, txBuffer, rxBuffer, tx_len, rx_len)
#define I2C0_abortTransfer()                  SMB0_abortTransfer()
#define I2C0_txBytesRemaining()               SMB0_txBytesRemaining()
#define I2C0_rxBytesRemaining()               SMB0_rxBytesRemaining()
#define I2C0_initSlave(address, commandBuffer, length)  SMB0_initSlave(address, commandBuffer, length)
#define I2C0_getCommandLength()               SMB0_getCommandLength()
#define I2C0_sendResponse(dataBuffer, length) SMB0_sendResponse(dataBuffer, length)

#endif //EFM8PDL_I2C0_USE_BUFFER

// Callbacks
#if (EFM8PDL_I2C0_USE_STATEMACHINE == 1) || IS_DOXYGEN

#define I2C0_arbLostCb(state)                 SMB0_arbLostCb(state)
#define I2C0_TxDataCb(master, ack)            SMB0_TxDataCb(master, ack)
#define I2C0_RxDataCb(master)                 SMB0_RxDataCb(master)
#define I2C0_startCb()                        SMB0_startCb()     
#define I2C0_addressCb()                      SMB0_addressCb()   
#define I2C0_stopCb()                         SMB0_stopCb()      

#endif // !EFM8PDL_I2C0_USE_BUFFER

#if (EFM8PDL_I2C0_USE_BUFFER == 1) || IS_DOXYGEN

#define I2C0_transferCompleteCb()             SMB0_transferCompleteCb()
#define I2C0_errorCb(error)                   SMB0_errorCb(error)
#define I2C0_commandReceivedCb()              SMB0_commandReceivedCb()

#endif //EFM8PDL_I2C0_USE_BUFFER = 1

#endif //__I2C_0_H__
