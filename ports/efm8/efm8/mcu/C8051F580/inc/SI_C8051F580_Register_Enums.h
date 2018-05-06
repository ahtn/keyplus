//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  C8051F580_IM
//  C8051F580_IQ
//  C8051F581_IM
//  C8051F581_IQ
//  C8051F582_IM
//  C8051F582_IQ
//  C8051F583_IM
//  C8051F583_IQ
//  C8051F584_IM
//  C8051F584_IQ
//  C8051F585_IM
//  C8051F585_IQ
//  C8051F586_IM
//  C8051F586_IQ
//  C8051F587_IM
//  C8051F587_IQ
//  C8051F588_IM
//  C8051F589_IM
//  C8051F590_IM
//  C8051F591_IM
//  C8051F592_AM

#ifndef SI_C8051F580_REGISTER_ENUMS_H
#define SI_C8051F580_REGISTER_ENUMS_H

//Standard device includes
#include "SI_C8051F580_Defs.h"
//------------------------------------------------------------------------------
// ADC0CF Enums (ADC0 Configuration @ 0xBC)
//------------------------------------------------------------------------------
#define ADC0CF_GAINEN__BMASK    0x01 ///< Gain Access Enable                            
#define ADC0CF_GAINEN__SHIFT    0x00 ///< Gain Access Enable                            
#define ADC0CF_GAINEN__DISABLED 0x00 ///< Disable access to the internal gain registers.
#define ADC0CF_GAINEN__ENABLED  0x01 ///< Enable access to the internal gain registers. 
                                                                                        
#define ADC0CF_ADRPT__FMASK     0x06 ///< Repeat Count                                  
#define ADC0CF_ADRPT__SHIFT     0x01 ///< Repeat Count                                  
#define ADC0CF_ADRPT__ACC_1     0x00 ///< Perform and Accumulate 1 conversion.          
#define ADC0CF_ADRPT__ACC_4     0x02 ///< Perform and Accumulate 4 conversions.         
#define ADC0CF_ADRPT__ACC_8     0x04 ///< Perform and Accumulate 8 conversions.         
#define ADC0CF_ADRPT__ACC_16    0x06 ///< Perform and Accumulate 16 conversions.        
                                                                                        
#define ADC0CF_ADSC__FMASK      0xF8 ///< SAR Clock Divider                             
#define ADC0CF_ADSC__SHIFT      0x03 ///< SAR Clock Divider                             
                                                                                        
//------------------------------------------------------------------------------
// ADC0CN Enums (ADC0 Control @ 0xE8)
//------------------------------------------------------------------------------
#define ADC0CN_ADCM__FMASK            0x03 ///< Start of Conversion Mode Select                   
#define ADC0CN_ADCM__SHIFT            0x00 ///< Start of Conversion Mode Select                   
#define ADC0CN_ADCM__ADBUSY           0x00 ///< ADC0 conversion initiated on write of 1 to ADBUSY.
#define ADC0CN_ADCM__TIMER1           0x01 ///< ADC0 conversion initiated on overflow of Timer 1. 
#define ADC0CN_ADCM__CNVSTR           0x02 ///< ADC0 conversion initiated on rising edge of       
                                           ///< CNVSTR.                                           
#define ADC0CN_ADCM__TIMER2           0x03 ///< ADC0 conversion initiated on overflow of Timer 2. 
                                                                                                  
#define ADC0CN_ADLJST__BMASK          0x04 ///< Justification Select                              
#define ADC0CN_ADLJST__SHIFT          0x02 ///< Justification Select                              
#define ADC0CN_ADLJST__RIGHT          0x00 ///< Data in ADC0H:L is right-justified.               
#define ADC0CN_ADLJST__LEFT           0x04 ///< Data in ADC0H:L is left-justified. This option    
                                           ///< should not be used with a repeat count greater    
                                           ///< than 1 (ADRPT set to any value other than 0).     
                                                                                                  
#define ADC0CN_ADWINT__BMASK          0x08 ///< Window Compare Interrupt Flag                     
#define ADC0CN_ADWINT__SHIFT          0x03 ///< Window Compare Interrupt Flag                     
#define ADC0CN_ADWINT__NOT_SET        0x00 ///< An ADC window compare event did not occur.        
#define ADC0CN_ADWINT__SET            0x08 ///< An ADC window compare event occurred.             
                                                                                                  
#define ADC0CN_ADBUSY__BMASK          0x10 ///< ADC Busy                                          
#define ADC0CN_ADBUSY__SHIFT          0x04 ///< ADC Busy                                          
#define ADC0CN_ADBUSY__NOT_SET        0x00 ///< An ADC0 conversion is not currently in progress.  
#define ADC0CN_ADBUSY__SET            0x10 ///< ADC0 conversion is in progress or start an ADC0   
                                           ///< conversion.                                       
                                                                                                  
#define ADC0CN_ADINT__BMASK           0x20 ///< Conversion Complete Interrupt Flag                
#define ADC0CN_ADINT__SHIFT           0x05 ///< Conversion Complete Interrupt Flag                
#define ADC0CN_ADINT__NOT_SET         0x00 ///< ADC0 has not completed a conversion since the last
                                           ///< time ADINT was cleared.                           
#define ADC0CN_ADINT__SET             0x20 ///< ADC0 completed a data conversion.                 
                                                                                                  
#define ADC0CN_ADBMEN__BMASK          0x40 ///< Burst Mode Enable                                 
#define ADC0CN_ADBMEN__SHIFT          0x06 ///< Burst Mode Enable                                 
#define ADC0CN_ADBMEN__BURST_DISABLED 0x00 ///< Disable ADC0 Burst Mode.                          
#define ADC0CN_ADBMEN__BURST_ENABLED  0x40 ///< Enable ADC0 Burst Mode.                           
                                                                                                  
#define ADC0CN_ADEN__BMASK            0x80 ///< ADC Enable                                        
#define ADC0CN_ADEN__SHIFT            0x07 ///< ADC Enable                                        
#define ADC0CN_ADEN__DISABLED         0x00 ///< Disable ADC0 (low-power shutdown).                
#define ADC0CN_ADEN__ENABLED          0x80 ///< Enable ADC0 (active and ready for data            
                                           ///< conversions).                                     
                                                                                                  
//------------------------------------------------------------------------------
// ADC0GNA Enums (ADC0 Adjustable Selectable Gain @ 0x08)
//------------------------------------------------------------------------------
#define ADC0GNA_GAINADD__BMASK    0x01 ///< Additional Gain Control                         
#define ADC0GNA_GAINADD__SHIFT    0x00 ///< Additional Gain Control                         
#define ADC0GNA_GAINADD__DISABLED 0x00 ///< Do not add any additional gain to the value in  
                                       ///< ADC0GNH:L.                                      
#define ADC0GNA_GAINADD__ENABLED  0x01 ///< Add 1/64 (0.016) gain to the value in ADC0GNH:L.
                                                                                            
//------------------------------------------------------------------------------
// ADC0GNH Enums (ADC0 Selectable Gain High @ 0x04)
//------------------------------------------------------------------------------
#define ADC0GNH_GAINH__FMASK 0xFF ///< Selectable Gain High
#define ADC0GNH_GAINH__SHIFT 0x00 ///< Selectable Gain High
                                                           
//------------------------------------------------------------------------------
// ADC0GNL Enums (ADC0 Selectable Gain Low @ 0x07)
//------------------------------------------------------------------------------
#define ADC0GNL_GAINL__FMASK 0xF0 ///< Selectable Gain Low
#define ADC0GNL_GAINL__SHIFT 0x04 ///< Selectable Gain Low
                                                          
//------------------------------------------------------------------------------
// ADC0GTH Enums (ADC0 Greater-Than High Byte @ 0xC4)
//------------------------------------------------------------------------------
#define ADC0GTH_ADC0GTH__FMASK 0xFF ///< Greater-Than High Byte
#define ADC0GTH_ADC0GTH__SHIFT 0x00 ///< Greater-Than High Byte
                                                               
//------------------------------------------------------------------------------
// ADC0GTL Enums (ADC0 Greater-Than Low Byte @ 0xC3)
//------------------------------------------------------------------------------
#define ADC0GTL_ADC0GTL__FMASK 0xFF ///< Greater-Than Low Byte
#define ADC0GTL_ADC0GTL__SHIFT 0x00 ///< Greater-Than Low Byte
                                                              
//------------------------------------------------------------------------------
// ADC0H Enums (ADC0 Data Word High Byte @ 0xBE)
//------------------------------------------------------------------------------
#define ADC0H_ADC0H__FMASK 0xFF ///< Data Word High Byte
#define ADC0H_ADC0H__SHIFT 0x00 ///< Data Word High Byte
                                                        
//------------------------------------------------------------------------------
// ADC0L Enums (ADC0 Data Word Low Byte @ 0xBD)
//------------------------------------------------------------------------------
#define ADC0L_ADC0L__FMASK 0xFF ///< Data Word Low Byte
#define ADC0L_ADC0L__SHIFT 0x00 ///< Data Word Low Byte
                                                       
//------------------------------------------------------------------------------
// ADC0LTH Enums (ADC0 Less-Than High Byte @ 0xC6)
//------------------------------------------------------------------------------
#define ADC0LTH_ADC0LTH__FMASK 0xFF ///< Less-Than High Byte
#define ADC0LTH_ADC0LTH__SHIFT 0x00 ///< Less-Than High Byte
                                                            
//------------------------------------------------------------------------------
// ADC0LTL Enums (ADC0 Less-Than Low Byte @ 0xC5)
//------------------------------------------------------------------------------
#define ADC0LTL_ADC0LTL__FMASK 0xFF ///< Less-Than Low Byte
#define ADC0LTL_ADC0LTL__SHIFT 0x00 ///< Less-Than Low Byte
                                                           
//------------------------------------------------------------------------------
// ADC0MX Enums (ADC0 Multiplexer Selection @ 0xBB)
//------------------------------------------------------------------------------
#define ADC0MX_ADC0MX__FMASK   0x3F ///< AMUX Positive Input Selection
#define ADC0MX_ADC0MX__SHIFT   0x00 ///< AMUX Positive Input Selection
#define ADC0MX_ADC0MX__ADC0P0  0x00 ///< Select channel ADC0.0.       
#define ADC0MX_ADC0MX__ADC0P1  0x01 ///< Select channel ADC0.1.       
#define ADC0MX_ADC0MX__ADC0P2  0x02 ///< Select channel ADC0.2.       
#define ADC0MX_ADC0MX__ADC0P3  0x03 ///< Select channel ADC0.3.       
#define ADC0MX_ADC0MX__ADC0P4  0x04 ///< Select channel ADC0.4.       
#define ADC0MX_ADC0MX__ADC0P5  0x05 ///< Select channel ADC0.5.       
#define ADC0MX_ADC0MX__ADC0P6  0x06 ///< Select channel ADC0.6.       
#define ADC0MX_ADC0MX__ADC0P7  0x07 ///< Select channel ADC0.7.       
#define ADC0MX_ADC0MX__ADC0P8  0x08 ///< Select channel ADC0.8.       
#define ADC0MX_ADC0MX__ADC0P9  0x09 ///< Select channel ADC0.9.       
#define ADC0MX_ADC0MX__ADC0P10 0x0A ///< Select channel ADC0.10.      
#define ADC0MX_ADC0MX__ADC0P11 0x0B ///< Select channel ADC0.11.      
#define ADC0MX_ADC0MX__ADC0P12 0x0C ///< Select channel ADC0.12.      
#define ADC0MX_ADC0MX__ADC0P13 0x0D ///< Select channel ADC0.13.      
#define ADC0MX_ADC0MX__ADC0P14 0x0E ///< Select channel ADC0.14.      
#define ADC0MX_ADC0MX__ADC0P15 0x0F ///< Select channel ADC0.15.      
#define ADC0MX_ADC0MX__ADC0P16 0x10 ///< Select channel ADC0.16.      
#define ADC0MX_ADC0MX__ADC0P17 0x11 ///< Select channel ADC0.17.      
#define ADC0MX_ADC0MX__ADC0P18 0x12 ///< Select channel ADC0.18.      
#define ADC0MX_ADC0MX__ADC0P19 0x13 ///< Select channel ADC0.19.      
#define ADC0MX_ADC0MX__ADC0P20 0x14 ///< Select channel ADC0.20.      
#define ADC0MX_ADC0MX__ADC0P21 0x15 ///< Select channel ADC0.21.      
#define ADC0MX_ADC0MX__ADC0P22 0x16 ///< Select channel ADC0.22.      
#define ADC0MX_ADC0MX__ADC0P23 0x17 ///< Select channel ADC0.23.      
#define ADC0MX_ADC0MX__ADC0P24 0x18 ///< Select channel ADC0.24.      
#define ADC0MX_ADC0MX__ADC0P25 0x19 ///< Select channel ADC0.25.      
#define ADC0MX_ADC0MX__ADC0P26 0x1A ///< Select channel ADC0.26.      
#define ADC0MX_ADC0MX__ADC0P27 0x1B ///< Select channel ADC0.27.      
#define ADC0MX_ADC0MX__ADC0P28 0x1C ///< Select channel ADC0.28.      
#define ADC0MX_ADC0MX__ADC0P29 0x1D ///< Select channel ADC0.29.      
#define ADC0MX_ADC0MX__ADC0P30 0x1E ///< Select channel ADC0.30.      
#define ADC0MX_ADC0MX__ADC0P31 0x1F ///< Select channel ADC0.31.      
#define ADC0MX_ADC0MX__TEMP    0x30 ///< Temperature Sensor.          
#define ADC0MX_ADC0MX__VDD     0x31 ///< VDD Supply Voltage.          
#define ADC0MX_ADC0MX__GND     0x3F ///< Ground.                      
                                                                      
//------------------------------------------------------------------------------
// ADC0TK Enums (ADC0 Burst Mode Track Time @ 0xBA)
//------------------------------------------------------------------------------
#define ADC0TK_ADTK__FMASK         0x03 ///< Post Tracking Time                                
#define ADC0TK_ADTK__SHIFT         0x00 ///< Post Tracking Time                                
#define ADC0TK_ADTK__2_SAR_CLOCKS  0x00 ///< Post-Tracking time is equal to 2 SAR clock cycles 
                                        ///< + 2 FADCCLK cycles.                               
#define ADC0TK_ADTK__4_SAR_CLOCKS  0x01 ///< Post-Tracking time is equal to 4 SAR clock cycles 
                                        ///< + 2 FADCCLK cycles.                               
#define ADC0TK_ADTK__8_SAR_CLOCKS  0x02 ///< Post-Tracking time is equal to 8 SAR clock cycles 
                                        ///< + 2 FADCCLK cycles.                               
#define ADC0TK_ADTK__16_SAR_CLOCKS 0x03 ///< Post-Tracking time is equal to 16 SAR clock cycles
                                        ///< + 2 FADCCLK cycles.                               
                                                                                               
#define ADC0TK_ADTM__FMASK         0x0C ///< Tracking Mode                                     
#define ADC0TK_ADTM__SHIFT         0x02 ///< Tracking Mode                                     
#define ADC0TK_ADTM__POST_TRACKING 0x04 ///< ADC0 is configured to Post-Tracking Mode.         
#define ADC0TK_ADTM__PRE_TRACKING  0x08 ///< ADC0 is configured to Pre-Tracking Mode.          
#define ADC0TK_ADTM__DUAL_TRACKING 0x0C ///< ADC0 is configured to Dual-Tracking Mode.         
                                                                                               
#define ADC0TK_ADPWR__FMASK        0xF0 ///< Burst Mode Power Up Time                          
#define ADC0TK_ADPWR__SHIFT        0x04 ///< Burst Mode Power Up Time                          
                                                                                               
//------------------------------------------------------------------------------
// CAN0BRPE Enums (CAN BRP Extension @ 0xA1)
//------------------------------------------------------------------------------
#define CAN0BRPE_BRPE__FMASK 0x0F ///< Baud Rate Prescaler Extension
#define CAN0BRPE_BRPE__SHIFT 0x00 ///< Baud Rate Prescaler Extension
                                                                    
//------------------------------------------------------------------------------
// CAN0BTH Enums (CAN Bit Timing High @ 0x9B)
//------------------------------------------------------------------------------
#define CAN0BTH_TSEG1__FMASK 0x0F ///< Timing Segment 1
#define CAN0BTH_TSEG1__SHIFT 0x00 ///< Timing Segment 1
                                                       
#define CAN0BTH_TSEG2__FMASK 0x70 ///< Timing Segment 2
#define CAN0BTH_TSEG2__SHIFT 0x04 ///< Timing Segment 2
                                                       
//------------------------------------------------------------------------------
// CAN0BTL Enums (CAN Bit Timing Low @ 0x9A)
//------------------------------------------------------------------------------
#define CAN0BTL_BRP__FMASK 0x3F ///< Baud Rate Prescaler       
#define CAN0BTL_BRP__SHIFT 0x00 ///< Baud Rate Prescaler       
                                                               
#define CAN0BTL_SJW__FMASK 0xC0 ///< Synchronization Jump Width
#define CAN0BTL_SJW__SHIFT 0x06 ///< Synchronization Jump Width
                                                               
//------------------------------------------------------------------------------
// CAN0CFG Enums (CAN Clock Configuration @ 0x92)
//------------------------------------------------------------------------------
#define CAN0CFG_SYSDIV__FMASK        0x03 ///< CAN System Clock Divider           
#define CAN0CFG_SYSDIV__SHIFT        0x00 ///< CAN System Clock Divider           
#define CAN0CFG_SYSDIV__SYSCLK       0x00 ///< CAN controller clock is SYSCLK.    
#define CAN0CFG_SYSDIV__SYSCLK_DIV_2 0x01 ///< CAN controller clock is SYSCLK / 2.
#define CAN0CFG_SYSDIV__SYSCLK_DIV_4 0x02 ///< CAN controller clock is SYSCLK / 4.
#define CAN0CFG_SYSDIV__SYSCLK_DIV_8 0x03 ///< CAN controller clock is SYSCLK / 8.
                                                                                  
//------------------------------------------------------------------------------
// CAN0CN Enums (CAN Control @ 0xC0)
//------------------------------------------------------------------------------
#define CAN0CN_INIT__BMASK                     0x01 ///< Initialization Start                              
#define CAN0CN_INIT__SHIFT                     0x00 ///< Initialization Start                              
#define CAN0CN_INIT__NORMAL                    0x00 ///< Normal operation.                                 
#define CAN0CN_INIT__STARTED                   0x01 ///< Initialization is started.                        
                                                                                                           
#define CAN0CN_IE__BMASK                       0x02 ///< Interrupt Enable                                  
#define CAN0CN_IE__SHIFT                       0x01 ///< Interrupt Enable                                  
#define CAN0CN_IE__INT_DISABLED                0x00 ///< Disabled - Module interrupt interrupt request     
                                                    ///< (IRQB) is always high.                            
#define CAN0CN_IE__INT_ENABLED                 0x02 ///< Enabled - Interrupts will set IRQB to low. IRQB   
                                                    ///< remains low until all pending interrupts are      
                                                    ///< processed.                                        
                                                                                                           
#define CAN0CN_SIE__BMASK                      0x04 ///< Status Change Interrupt Enable                    
#define CAN0CN_SIE__SHIFT                      0x02 ///< Status Change Interrupt Enable                    
#define CAN0CN_SIE__STATUS_CHANGE_INT_DISABLED 0x00 ///< Disabled - No status change interrupt will be     
                                                    ///< generated.                                        
#define CAN0CN_SIE__STATUS_CHANGE_INT_ENABLED  0x04 ///< Enabled - An interrupt will be generated when a   
                                                    ///< message transfer is successfully completed or a   
                                                    ///< CAN bus error is detected.                        
                                                                                                           
#define CAN0CN_EIE__BMASK                      0x08 ///< Error Interrupt Enable                            
#define CAN0CN_EIE__SHIFT                      0x03 ///< Error Interrupt Enable                            
#define CAN0CN_EIE__ERROR_INT_DISABLED         0x00 ///< Disabled - No error status interrupt will be      
                                                    ///< generated.                                        
#define CAN0CN_EIE__ERROR_INT_ENABLED          0x08 ///< Enabled - A change in the bits BOFF or EWARN in   
                                                    ///< the CAN0STAT register will generate an interrupt. 
                                                                                                           
#define CAN0CN_DAR__BMASK                      0x20 ///< Automatic Retransmission Disable                  
#define CAN0CN_DAR__SHIFT                      0x05 ///< Automatic Retransmission Disable                  
#define CAN0CN_DAR__AUTO_RETRANS_ENABLED       0x00 ///< Automatic retransmission of disturbed messages    
                                                    ///< enabled.                                          
#define CAN0CN_DAR__AUTO_RETRANS_DISABLED      0x20 ///< Automatic retransmission disabled.                
                                                                                                           
#define CAN0CN_CCE__BMASK                      0x40 ///< Configuration Change Enable                       
#define CAN0CN_CCE__SHIFT                      0x06 ///< Configuration Change Enable                       
#define CAN0CN_CCE__CONFIG_CHANGE_DISABLED     0x00 ///< The core has no write access to the bit timing    
                                                    ///< registers (CAN0BTL and CAN0BTH).                  
#define CAN0CN_CCE__CONFIG_CHANGE_ENABLED      0x40 ///< The core has write access to the bit timing       
                                                    ///< registers (CAN0BTL and CAN0BTH) while the INIT bit
                                                    ///< is set to 1.                                      
                                                                                                           
#define CAN0CN_TEST__BMASK                     0x80 ///< Test Mode Enable                                  
#define CAN0CN_TEST__SHIFT                     0x07 ///< Test Mode Enable                                  
#define CAN0CN_TEST__DISABLED                  0x00 ///< Test mode disabled (normal operation).            
#define CAN0CN_TEST__ENABLED                   0x80 ///< Test mode enabled.                                
                                                                                                           
//------------------------------------------------------------------------------
// CAN0ERRH Enums (CAN Error Counter High @ 0x97)
//------------------------------------------------------------------------------
#define CAN0ERRH_REC__FMASK  0x7F ///< Receive Error Counter                             
#define CAN0ERRH_REC__SHIFT  0x00 ///< Receive Error Counter                             
                                                                                         
#define CAN0ERRH_RP__BMASK   0x80 ///< Receive Error Passive                             
#define CAN0ERRH_RP__SHIFT   0x07 ///< Receive Error Passive                             
#define CAN0ERRH_RP__NOT_SET 0x00 ///< The receive error counter is below the error      
                                  ///< passive level.                                    
#define CAN0ERRH_RP__SET     0x80 ///< The receive error counter has reached the error   
                                  ///< passive level as defined in the CAN specification.
                                                                                         
//------------------------------------------------------------------------------
// CAN0ERRL Enums (CAN Error Counter Low @ 0x96)
//------------------------------------------------------------------------------
#define CAN0ERRL_TEC__FMASK 0xFF ///< Transmit Error Counter
#define CAN0ERRL_TEC__SHIFT 0x00 ///< Transmit Error Counter
                                                            
//------------------------------------------------------------------------------
// CAN0IF1A1H Enums (CAN Interface 1 Arbitration 1 High @ 0xCB)
//------------------------------------------------------------------------------
#define CAN0IF1A1H_ID__FMASK 0xFF ///< Interface 1 Message Identifier
#define CAN0IF1A1H_ID__SHIFT 0x00 ///< Interface 1 Message Identifier
                                                                     
//------------------------------------------------------------------------------
// CAN0IF1A1L Enums (CAN Interface 1 Arbitration 1 Low @ 0xCA)
//------------------------------------------------------------------------------
#define CAN0IF1A1L_ID__FMASK 0xFF ///< Interface 1 Message Identifier
#define CAN0IF1A1L_ID__SHIFT 0x00 ///< Interface 1 Message Identifier
                                                                     
//------------------------------------------------------------------------------
// CAN0IF1A2H Enums (CAN Interface 1 Arbitration 2 High @ 0xCD)
//------------------------------------------------------------------------------
#define CAN0IF1A2H_ID__FMASK       0x1F ///< Interface 1 Message Identifier                   
#define CAN0IF1A2H_ID__SHIFT       0x00 ///< Interface 1 Message Identifier                   
                                                                                              
#define CAN0IF1A2H_DIR__BMASK      0x20 ///< Message Direction                                
#define CAN0IF1A2H_DIR__SHIFT      0x05 ///< Message Direction                                
#define CAN0IF1A2H_DIR__RECEIVE    0x00 ///< Direction = receive. On TXRQST, a remote frame   
                                        ///< with the identifier of this message object is    
                                        ///< transmitted. On reception of a data frame with   
                                        ///< matching identifier, that message is stored in   
                                        ///< this message object.                             
#define CAN0IF1A2H_DIR__TRANSMIT   0x20 ///< Direction = transmit. On TXRQST, the respective  
                                        ///< message object is transmitted as a data frame. On
                                        ///< reception of a remote frame with matching        
                                        ///< identifier, the TXRQST bit of this message object
                                        ///< is set if RMTEN is set to 1.                     
                                                                                              
#define CAN0IF1A2H_XTD__BMASK      0x40 ///< Extended Identifier Select                       
#define CAN0IF1A2H_XTD__SHIFT      0x06 ///< Extended Identifier Select                       
#define CAN0IF1A2H_XTD__STANDARD   0x00 ///< The 11-bit standard identifier will be used for  
                                        ///< this message object.                             
#define CAN0IF1A2H_XTD__EXTENDED   0x40 ///< The 29-bit extended identifier will be used for  
                                        ///< this message object.                             
                                                                                              
#define CAN0IF1A2H_MSGVAL__BMASK   0x80 ///< Message Valid Flag                               
#define CAN0IF1A2H_MSGVAL__SHIFT   0x07 ///< Message Valid Flag                               
#define CAN0IF1A2H_MSGVAL__NOT_SET 0x00 ///< The message object is ignored by the message     
                                        ///< handler.                                         
#define CAN0IF1A2H_MSGVAL__SET     0x80 ///< The message object is configured and should be   
                                        ///< considered by the message handler.               
                                                                                              
//------------------------------------------------------------------------------
// CAN0IF1A2L Enums (CAN Interface 1 Arbitration 2 Low @ 0xCC)
//------------------------------------------------------------------------------
#define CAN0IF1A2L_ID__FMASK 0xFF ///< Interface 1 Message Identifier
#define CAN0IF1A2L_ID__SHIFT 0x00 ///< Interface 1 Message Identifier
                                                                     
//------------------------------------------------------------------------------
// CAN0IF1CMH Enums (CAN Interface 1 Command Mask High @ 0xC3)
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// CAN0IF1CML Enums (CAN Interface 1 Command Mask Low @ 0xC2)
//------------------------------------------------------------------------------
#define CAN0IF1CML_DATAB__BMASK             0x01 ///< Access Data Bytes 4-7                             
#define CAN0IF1CML_DATAB__SHIFT             0x00 ///< Access Data Bytes 4-7                             
#define CAN0IF1CML_DATAB__DO_NOT_TRANSFER   0x00 ///< Data bytes 4-7 are unchanged.                     
#define CAN0IF1CML_DATAB__TRANSFER          0x01 ///< On a write, transfer data bytes 4-7 to the message
                                                 ///< object. On a read, transfer data bytes 4-7 to the 
                                                 ///< IFx message buffer register.                      
                                                                                                        
#define CAN0IF1CML_DATAA__BMASK             0x02 ///< Access Data Bytes 0-3                             
#define CAN0IF1CML_DATAA__SHIFT             0x01 ///< Access Data Bytes 0-3                             
#define CAN0IF1CML_DATAA__DO_NOT_TRANSFER   0x00 ///< Data bytes 0-3 are unchanged.                     
#define CAN0IF1CML_DATAA__TRANSFER          0x02 ///< On a write, transfer data bytes 0-3 to the message
                                                 ///< object. On a read, transfer data bytes 0-3 to the 
                                                 ///< IFx message buffer register.                      
                                                                                                        
#define CAN0IF1CML_TXRND__BMASK             0x04 ///< Access Transmission Request                       
#define CAN0IF1CML_TXRND__SHIFT             0x02 ///< Access Transmission Request                       
#define CAN0IF1CML_TXRND__DO_NOT_CHANGE     0x00 ///< On a write, the TXRQST bit is unchanged. On a     
                                                 ///< read, the NEWDAT bit remains unchanged.           
#define CAN0IF1CML_TXRND__SET_OR_CLEAR      0x04 ///< On a write, set the TXRQST bit. On a read, clear  
                                                 ///< the NEWDAT bit in the message object.             
                                                                                                        
#define CAN0IF1CML_CLRINTPND__BMASK         0x08 ///< Clear Interrupt Pending                           
#define CAN0IF1CML_CLRINTPND__SHIFT         0x03 ///< Clear Interrupt Pending                           
#define CAN0IF1CML_CLRINTPND__DO_NOT_CLEAR  0x00 ///< The INTPND bit remains unchanged.                 
#define CAN0IF1CML_CLRINTPND__CLEAR         0x08 ///< Clear the INTPND bit in the message object.       
                                                                                                        
#define CAN0IF1CML_CONTROL__BMASK           0x10 ///< Access Control                                    
#define CAN0IF1CML_CONTROL__SHIFT           0x04 ///< Access Control                                    
#define CAN0IF1CML_CONTROL__DO_NOT_TRANSFER 0x00 ///< Do not transfer the control bits.                 
#define CAN0IF1CML_CONTROL__TRANSFER        0x10 ///< On a write, transfer the control bits to the      
                                                 ///< message object. On a read, transfer the control   
                                                 ///< bits to the IFx message buffer register.          
                                                                                                        
#define CAN0IF1CML_ARB__BMASK               0x20 ///< Access Arbitration                                
#define CAN0IF1CML_ARB__SHIFT               0x05 ///< Access Arbitration                                
#define CAN0IF1CML_ARB__DO_NOT_TRANSFER     0x00 ///< Do not transfer the arbitration bits.             
#define CAN0IF1CML_ARB__TRANSFER            0x20 ///< On a write, transfer the identifier + DIR + XTD + 
                                                 ///< MSGVAL to the message object. On a read, transfer 
                                                 ///< the identifier + DIR + XTD+ MSGVAL to the IFx     
                                                 ///< message buffer register.                          
                                                                                                        
#define CAN0IF1CML_MASK__BMASK              0x40 ///< Access Mask                                       
#define CAN0IF1CML_MASK__SHIFT              0x06 ///< Access Mask                                       
#define CAN0IF1CML_MASK__DO_NOT_TRANSFER    0x00 ///< Do not transfer the mask bits.                    
#define CAN0IF1CML_MASK__TRANSFER           0x40 ///< On a write, transfer the identifier mask + MDIR + 
                                                 ///< MXTD to the message object. On a read, transfer   
                                                 ///< the identifier mask + MDIR + MXTD to the IFx      
                                                 ///< message buffer register.                          
                                                                                                        
#define CAN0IF1CML_WRRD__BMASK              0x80 ///< Write / Read Direction Control                    
#define CAN0IF1CML_WRRD__SHIFT              0x07 ///< Write / Read Direction Control                    
#define CAN0IF1CML_WRRD__READ               0x00 ///< Read: transfer data from the message object       
                                                 ///< addressed by the command request register into the
                                                 ///< selected message buffer registers.                
#define CAN0IF1CML_WRRD__WRITE              0x80 ///< Write: transfer data from the selected message    
                                                 ///< buffer registers to the message object addressed  
                                                 ///< by the command request register.                  
                                                                                                        
//------------------------------------------------------------------------------
// CAN0IF1CRH Enums (CAN Interface 1 Command Request High @ 0xBF)
//------------------------------------------------------------------------------
#define CAN0IF1CRH_BUSY__BMASK   0x80 ///< Busy Flag                                       
#define CAN0IF1CRH_BUSY__SHIFT   0x07 ///< Busy Flag                                       
#define CAN0IF1CRH_BUSY__NOT_SET 0x00 ///< Set to 1 when writing to the IFx command request
                                      ///< register.                                       
#define CAN0IF1CRH_BUSY__SET     0x80 ///< Reset to 0 when the read or write action has    
                                      ///< finished.                                       
                                                                                           
//------------------------------------------------------------------------------
// CAN0IF1CRL Enums (CAN Interface 1 Command Request Low @ 0xBE)
//------------------------------------------------------------------------------
#define CAN0IF1CRL_MSGNUM__FMASK 0x3F ///< Message Number
#define CAN0IF1CRL_MSGNUM__SHIFT 0x00 ///< Message Number
                                                         
//------------------------------------------------------------------------------
// CAN0IF1DA1H Enums (CAN Interface 1 Data A 1 High @ 0xD5)
//------------------------------------------------------------------------------
#define CAN0IF1DA1H_DATA1__FMASK 0xFF ///< Interface 1 Data 1
#define CAN0IF1DA1H_DATA1__SHIFT 0x00 ///< Interface 1 Data 1
                                                             
//------------------------------------------------------------------------------
// CAN0IF1DA1L Enums (CAN Interface 1 Data A 1 Low @ 0xD4)
//------------------------------------------------------------------------------
#define CAN0IF1DA1L_DATA0__FMASK 0xFF ///< Interface 1 Data 0
#define CAN0IF1DA1L_DATA0__SHIFT 0x00 ///< Interface 1 Data 0
                                                             
//------------------------------------------------------------------------------
// CAN0IF1DA2H Enums (CAN Interface 1 Data A 2 High @ 0xD7)
//------------------------------------------------------------------------------
#define CAN0IF1DA2H_DATA3__FMASK 0xFF ///< Interface 1 Data 3
#define CAN0IF1DA2H_DATA3__SHIFT 0x00 ///< Interface 1 Data 3
                                                             
//------------------------------------------------------------------------------
// CAN0IF1DA2L Enums (CAN Interface 1 Data A 2 Low @ 0xD6)
//------------------------------------------------------------------------------
#define CAN0IF1DA2L_DATA2__FMASK 0xFF ///< Interface 1 Data 2
#define CAN0IF1DA2L_DATA2__SHIFT 0x00 ///< Interface 1 Data 2
                                                             
//------------------------------------------------------------------------------
// CAN0IF1DB1H Enums (CAN Interface 1 Data B 1 High @ 0xDB)
//------------------------------------------------------------------------------
#define CAN0IF1DB1H_DATA5__FMASK 0xFF ///< Interface 1 Data 5
#define CAN0IF1DB1H_DATA5__SHIFT 0x00 ///< Interface 1 Data 5
                                                             
//------------------------------------------------------------------------------
// CAN0IF1DB1L Enums (CAN Interface 1 Data B 1 Low @ 0xDA)
//------------------------------------------------------------------------------
#define CAN0IF1DB1L_DATA4__FMASK 0xFF ///< Interface 1 Data 4
#define CAN0IF1DB1L_DATA4__SHIFT 0x00 ///< Interface 1 Data 4
                                                             
//------------------------------------------------------------------------------
// CAN0IF1DB2H Enums (CAN Interface 1 Data B 2 High @ 0xDD)
//------------------------------------------------------------------------------
#define CAN0IF1DB2H_DATA7__FMASK 0xFF ///< Interface 1 Data 7
#define CAN0IF1DB2H_DATA7__SHIFT 0x00 ///< Interface 1 Data 7
                                                             
//------------------------------------------------------------------------------
// CAN0IF1DB2L Enums (CAN Interface 1 Data B 2 Low @ 0xDC)
//------------------------------------------------------------------------------
#define CAN0IF1DB2L_DATA6__FMASK 0xFF ///< Interface 1 Data 6
#define CAN0IF1DB2L_DATA6__SHIFT 0x00 ///< Interface 1 Data 6
                                                             
//------------------------------------------------------------------------------
// CAN0IF1M1H Enums (CAN Interface 1 Mask 1 High @ 0xC5)
//------------------------------------------------------------------------------
#define CAN0IF1M1H_MSK__FMASK 0xFF ///< Interface 1 Identifier Mask
#define CAN0IF1M1H_MSK__SHIFT 0x00 ///< Interface 1 Identifier Mask
                                                                   
//------------------------------------------------------------------------------
// CAN0IF1M1L Enums (CAN Interface 1 Mask 1 Low @ 0xC4)
//------------------------------------------------------------------------------
#define CAN0IF1M1L_MSK__FMASK 0xFF ///< Interface 1 Identifier Mask
#define CAN0IF1M1L_MSK__SHIFT 0x00 ///< Interface 1 Identifier Mask
                                                                   
//------------------------------------------------------------------------------
// CAN0IF1M2H Enums (CAN Interface 1 Mask 2 High @ 0xC7)
//------------------------------------------------------------------------------
#define CAN0IF1M2H_MSK__FMASK     0x1F ///< Interface 1 Identifier Mask                       
#define CAN0IF1M2H_MSK__SHIFT     0x00 ///< Interface 1 Identifier Mask                       
                                                                                              
#define CAN0IF1M2H_MDIR__BMASK    0x40 ///< Mask Message Direction                            
#define CAN0IF1M2H_MDIR__SHIFT    0x06 ///< Mask Message Direction                            
#define CAN0IF1M2H_MDIR__DISABLED 0x00 ///< The message direction bit (DIR) has no effect on  
                                       ///< the acceptance filtering.                         
#define CAN0IF1M2H_MDIR__ENABLED  0x40 ///< The message direction bit (DIR) is used for       
                                       ///< acceptance filtering.                             
                                                                                              
#define CAN0IF1M2H_MXTD__BMASK    0x80 ///< Mask Extended Identifier                          
#define CAN0IF1M2H_MXTD__SHIFT    0x07 ///< Mask Extended Identifier                          
#define CAN0IF1M2H_MXTD__DISABLED 0x00 ///< The extended identifier bit (IDE) has no effect on
                                       ///< the acceptance filtering.                         
#define CAN0IF1M2H_MXTD__ENABLED  0x80 ///< The extended identifier bit (IDE) is used for     
                                       ///< acceptance filtering.                             
                                                                                              
//------------------------------------------------------------------------------
// CAN0IF1M2L Enums (CAN Interface 1 Mask 2 Low @ 0xC6)
//------------------------------------------------------------------------------
#define CAN0IF1M2L_MSK__FMASK 0xFF ///< Interface 1 Identifier Mask
#define CAN0IF1M2L_MSK__SHIFT 0x00 ///< Interface 1 Identifier Mask
                                                                   
//------------------------------------------------------------------------------
// CAN0IF1MCH Enums (CAN Interface 1 Message Control High @ 0xD3)
//------------------------------------------------------------------------------
#define CAN0IF1MCH_TXRQST__BMASK   0x01 ///< Transmit Request Flag                             
#define CAN0IF1MCH_TXRQST__SHIFT   0x00 ///< Transmit Request Flag                             
#define CAN0IF1MCH_TXRQST__NOT_SET 0x00 ///< The message object is not waiting for             
                                        ///< transmission.                                     
#define CAN0IF1MCH_TXRQST__SET     0x01 ///< The transmission of this message object is        
                                        ///< requested and is not yet done.                    
                                                                                               
#define CAN0IF1MCH_RMTEN__BMASK    0x02 ///< Remote Enable                                     
#define CAN0IF1MCH_RMTEN__SHIFT    0x01 ///< Remote Enable                                     
#define CAN0IF1MCH_RMTEN__DISABLED 0x00 ///< At the reception of a remote frame, TXRQST is left
                                        ///< unchanged.                                        
#define CAN0IF1MCH_RMTEN__ENABLED  0x02 ///< At the reception of a remote frame, TXRQST is set 
                                        ///< to 1.                                             
                                                                                               
#define CAN0IF1MCH_RXIE__BMASK     0x04 ///< Receive Interrupt Enable                          
#define CAN0IF1MCH_RXIE__SHIFT     0x02 ///< Receive Interrupt Enable                          
#define CAN0IF1MCH_RXIE__DISABLED  0x00 ///< INTPND will be left unchanged after the successful
                                        ///< reception of a frame.                             
#define CAN0IF1MCH_RXIE__ENABLED   0x04 ///< INTPND will be set after a successful reception of
                                        ///< a frame.                                          
                                                                                               
#define CAN0IF1MCH_TXIE__BMASK     0x08 ///< Transmit Interrupt Enable                         
#define CAN0IF1MCH_TXIE__SHIFT     0x03 ///< Transmit Interrupt Enable                         
#define CAN0IF1MCH_TXIE__DISABLED  0x00 ///< INTPND will be left unchanged after the successful
                                        ///< transmission of a frame.                          
#define CAN0IF1MCH_TXIE__ENABLED   0x08 ///< INTPND will be set after a successful transmission
                                        ///< of a frame.                                       
                                                                                               
#define CAN0IF1MCH_UMASK__BMASK    0x10 ///< Use Acceptance Mask                               
#define CAN0IF1MCH_UMASK__SHIFT    0x04 ///< Use Acceptance Mask                               
#define CAN0IF1MCH_UMASK__DISABLED 0x00 ///< Mask ignored.                                     
#define CAN0IF1MCH_UMASK__ENABLED  0x10 ///< Use the mask (MSK, MXTD, and MDIR) for acceptance 
                                        ///< filtering.                                        
                                                                                               
#define CAN0IF1MCH_INTPND__BMASK   0x20 ///< Interrupt Pending Flag                            
#define CAN0IF1MCH_INTPND__SHIFT   0x05 ///< Interrupt Pending Flag                            
#define CAN0IF1MCH_INTPND__NOT_SET 0x00 ///< This message object is not the source of an       
                                        ///< interrupt.                                        
#define CAN0IF1MCH_INTPND__SET     0x20 ///< This message object is the source of an interrupt.
                                        ///< The interrupt identifier in the interrupt register
                                        ///< will point to this message object if there is no  
                                        ///< other interrupt source with higher priority.      
                                                                                               
#define CAN0IF1MCH_MSGLST__BMASK   0x40 ///< Message Lost Flag                                 
#define CAN0IF1MCH_MSGLST__SHIFT   0x06 ///< Message Lost Flag                                 
#define CAN0IF1MCH_MSGLST__NOT_SET 0x00 ///< No message was lost since the last time this flag 
                                        ///< was cleared by firmware.                          
#define CAN0IF1MCH_MSGLST__SET     0x40 ///< The message handler stored a new message into this
                                        ///< object when NEWDAT was still set and a message has
                                        ///< been lost.                                        
                                                                                               
#define CAN0IF1MCH_NEWDAT__BMASK   0x80 ///< New Data Flag                                     
#define CAN0IF1MCH_NEWDAT__SHIFT   0x07 ///< New Data Flag                                     
#define CAN0IF1MCH_NEWDAT__NOT_SET 0x00 ///< No new data has been written into the data portion
                                        ///< of this message object by the message handler     
                                        ///< since the last time this flag was cleared by      
                                        ///< firmware.                                         
#define CAN0IF1MCH_NEWDAT__SET     0x80 ///< The message handler or firmware have written new  
                                        ///< data into the data portion of this message object.
                                                                                               
//------------------------------------------------------------------------------
// CAN0IF1MCL Enums (CAN Interface 1 Message Control Low @ 0xD2)
//------------------------------------------------------------------------------
#define CAN0IF1MCL_DLC__FMASK   0x0F ///< Data Length Code                                  
#define CAN0IF1MCL_DLC__SHIFT   0x00 ///< Data Length Code                                  
#define CAN0IF1MCL_DLC__0_BYTES 0x00 ///< The data frame has 0 data bytes.                  
#define CAN0IF1MCL_DLC__1_BYTE  0x01 ///< The data frame has 1 data byte.                   
#define CAN0IF1MCL_DLC__2_BYTES 0x02 ///< The data frame has 2 data bytes.                  
#define CAN0IF1MCL_DLC__3_BYTES 0x03 ///< The data frame has 3 data bytes.                  
#define CAN0IF1MCL_DLC__4_BYTES 0x04 ///< The data frame has 4 data bytes.                  
#define CAN0IF1MCL_DLC__5_BYTES 0x05 ///< The data frame has 5 data bytes.                  
#define CAN0IF1MCL_DLC__6_BYTES 0x06 ///< The data frame has 6 data bytes.                  
#define CAN0IF1MCL_DLC__7_BYTES 0x07 ///< The data frame has 7 data bytes.                  
#define CAN0IF1MCL_DLC__8_BYTES 0x08 ///< The data frame has 8 data bytes.                  
                                                                                            
#define CAN0IF1MCL_EOB__BMASK   0x80 ///< End of Buffer Flag                                
#define CAN0IF1MCL_EOB__SHIFT   0x07 ///< End of Buffer Flag                                
#define CAN0IF1MCL_EOB__NOT_SET 0x00 ///< The message object belongs to a FIFO buffer and is
                                     ///< not the last message object of that FIFO buffer.  
#define CAN0IF1MCL_EOB__SET     0x80 ///< The message object is a single message object or  
                                     ///< the last message object of a FIFO buffer.         
                                                                                            
//------------------------------------------------------------------------------
// CAN0IF2A1H Enums (CAN Interface 2 Arbitration 1 High @ 0xEF)
//------------------------------------------------------------------------------
#define CAN0IF2A1H_ID__FMASK 0xFF ///< Interface 2 Message Identifier
#define CAN0IF2A1H_ID__SHIFT 0x00 ///< Interface 2 Message Identifier
                                                                     
//------------------------------------------------------------------------------
// CAN0IF2A1L Enums (CAN Interface 2 Arbitration 1 Low @ 0xEE)
//------------------------------------------------------------------------------
#define CAN0IF2A1L_ID__FMASK 0xFF ///< Interface 2 Message Identifier
#define CAN0IF2A1L_ID__SHIFT 0x00 ///< Interface 2 Message Identifier
                                                                     
//------------------------------------------------------------------------------
// CAN0IF2A2H Enums (CAN Interface 2 Arbitration 2 High @ 0xF3)
//------------------------------------------------------------------------------
#define CAN0IF2A2H_ID__FMASK       0x1F ///< Interface 2 Message Identifier                   
#define CAN0IF2A2H_ID__SHIFT       0x00 ///< Interface 2 Message Identifier                   
                                                                                              
#define CAN0IF2A2H_DIR__BMASK      0x20 ///< Message Direction                                
#define CAN0IF2A2H_DIR__SHIFT      0x05 ///< Message Direction                                
#define CAN0IF2A2H_DIR__RECEIVE    0x00 ///< Direction = receive. On TXRQST, a remote frame   
                                        ///< with the identifier of this message object is    
                                        ///< transmitted. On reception of a data frame with   
                                        ///< matching identifier, that message is stored in   
                                        ///< this message object.                             
#define CAN0IF2A2H_DIR__TRANSMIT   0x20 ///< Direction = transmit. On TXRQST, the respective  
                                        ///< message object is transmitted as a data frame. On
                                        ///< reception of a remote frame with matching        
                                        ///< identifier, the TXRQST bit of this message object
                                        ///< is set if RMTEN is set to 1.                     
                                                                                              
#define CAN0IF2A2H_XTD__BMASK      0x40 ///< Extended Identifier Select                       
#define CAN0IF2A2H_XTD__SHIFT      0x06 ///< Extended Identifier Select                       
#define CAN0IF2A2H_XTD__STANDARD   0x00 ///< The 11-bit standard identifier will be used for  
                                        ///< this message object.                             
#define CAN0IF2A2H_XTD__EXTENDED   0x40 ///< The 29-bit extended identifier will be used for  
                                        ///< this message object.                             
                                                                                              
#define CAN0IF2A2H_MSGVLD__BMASK   0x80 ///< Message Valid Flag                               
#define CAN0IF2A2H_MSGVLD__SHIFT   0x07 ///< Message Valid Flag                               
#define CAN0IF2A2H_MSGVLD__NOT_SET 0x00 ///< The message object is ignored by the message     
                                        ///< handler.                                         
#define CAN0IF2A2H_MSGVLD__SET     0x80 ///< The message object is configured and should be   
                                        ///< considered by the message handler.               
                                                                                              
//------------------------------------------------------------------------------
// CAN0IF2A2L Enums (CAN Interface 2 Arbitration 2 Low @ 0xF2)
//------------------------------------------------------------------------------
#define CAN0IF2A2L_ID__FMASK 0xFF ///< Interface 2 Message Identifier
#define CAN0IF2A2L_ID__SHIFT 0x00 ///< Interface 2 Message Identifier
                                                                     
//------------------------------------------------------------------------------
// CAN0IF2CMH Enums (CAN Interface 2 Command Mask High @ 0xE3)
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// CAN0IF2CML Enums (CAN Interface 2 Command Mask Low @ 0xE2)
//------------------------------------------------------------------------------
#define CAN0IF2CML_DATAB__BMASK             0x01 ///< Access Data Bytes 4-7                             
#define CAN0IF2CML_DATAB__SHIFT             0x00 ///< Access Data Bytes 4-7                             
#define CAN0IF2CML_DATAB__DO_NOT_TRANSFER   0x00 ///< Data bytes 4-7 are unchanged.                     
#define CAN0IF2CML_DATAB__TRANSFER          0x01 ///< On a write, transfer data bytes 4-7 to the message
                                                 ///< object. On a read, transfer data bytes 4-7 to the 
                                                 ///< IFx message buffer register.                      
                                                                                                        
#define CAN0IF2CML_DATAA__BMASK             0x02 ///< Access Data Bytes 0-3                             
#define CAN0IF2CML_DATAA__SHIFT             0x01 ///< Access Data Bytes 0-3                             
#define CAN0IF2CML_DATAA__DO_NOT_TRANSFER   0x00 ///< Data bytes 0-3 are unchanged.                     
#define CAN0IF2CML_DATAA__TRANSFER          0x02 ///< On a write, transfer data bytes 0-3 to the message
                                                 ///< object. On a read, transfer data bytes 0-3 to the 
                                                 ///< IFx message buffer register.                      
                                                                                                        
#define CAN0IF2CML_TXRND__BMASK             0x04 ///< Access Transmission Request                       
#define CAN0IF2CML_TXRND__SHIFT             0x02 ///< Access Transmission Request                       
#define CAN0IF2CML_TXRND__DO_NOT_CHANGE     0x00 ///< On a write, the TXRQST bit is unchanged. On a     
                                                 ///< read, the NEWDAT bit remains unchanged.           
#define CAN0IF2CML_TXRND__SET_OR_CLEAR      0x04 ///< On a write, set the TXRQST bit. On a read, clear  
                                                 ///< the NEWDAT bit in the message object.             
                                                                                                        
#define CAN0IF2CML_CLRINTPND__BMASK         0x08 ///< Clear Interrupt Pending                           
#define CAN0IF2CML_CLRINTPND__SHIFT         0x03 ///< Clear Interrupt Pending                           
#define CAN0IF2CML_CLRINTPND__DO_NOT_CLEAR  0x00 ///< The INTPND bit remains unchanged.                 
#define CAN0IF2CML_CLRINTPND__CLEAR         0x08 ///< Clear the INTPND bit in the message object.       
                                                                                                        
#define CAN0IF2CML_CONTROL__BMASK           0x10 ///< Access Control                                    
#define CAN0IF2CML_CONTROL__SHIFT           0x04 ///< Access Control                                    
#define CAN0IF2CML_CONTROL__DO_NOT_TRANSFER 0x00 ///< Do not transfer the control bits.                 
#define CAN0IF2CML_CONTROL__TRANSFER        0x10 ///< On a write, transfer the control bits to the      
                                                 ///< message object. On a read, transfer the control   
                                                 ///< bits to the IFx message buffer register.          
                                                                                                        
#define CAN0IF2CML_ARB__BMASK               0x20 ///< Access Arbitration                                
#define CAN0IF2CML_ARB__SHIFT               0x05 ///< Access Arbitration                                
#define CAN0IF2CML_ARB__DO_NOT_TRANSFER     0x00 ///< Do not transfer the arbitration bits.             
#define CAN0IF2CML_ARB__TRANSFER            0x20 ///< On a write, transfer the identifier + DIR + XTD + 
                                                 ///< MSGVAL to the message object. On a read, transfer 
                                                 ///< the identifier + DIR + XTD+ MSGVAL to the IFx     
                                                 ///< message buffer register.                          
                                                                                                        
#define CAN0IF2CML_MASK__BMASK              0x40 ///< Access Mask                                       
#define CAN0IF2CML_MASK__SHIFT              0x06 ///< Access Mask                                       
#define CAN0IF2CML_MASK__DO_NOT_TRANSFER    0x00 ///< Do not transfer the mask bits.                    
#define CAN0IF2CML_MASK__TRANSFER           0x40 ///< On a write, transfer the identifier mask + MDIR + 
                                                 ///< MXTD to the message object. On a read, transfer   
                                                 ///< the identifier mask + MDIR + MXTD to the IFx      
                                                 ///< message buffer register.                          
                                                                                                        
#define CAN0IF2CML_WRRD__BMASK              0x80 ///< Write / Read Direction Control                    
#define CAN0IF2CML_WRRD__SHIFT              0x07 ///< Write / Read Direction Control                    
#define CAN0IF2CML_WRRD__READ               0x00 ///< Read: transfer data from the message object       
                                                 ///< addressed by the command request register into the
                                                 ///< selected message buffer registers.                
#define CAN0IF2CML_WRRD__WRITE              0x80 ///< Write: transfer data from the selected message    
                                                 ///< buffer registers to the message object addressed  
                                                 ///< by the command request register.                  
                                                                                                        
//------------------------------------------------------------------------------
// CAN0IF2CRH Enums (CAN Interface 2 Command Request High @ 0xDF)
//------------------------------------------------------------------------------
#define CAN0IF2CRH_BUSY__BMASK   0x80 ///< Busy Flag                                       
#define CAN0IF2CRH_BUSY__SHIFT   0x07 ///< Busy Flag                                       
#define CAN0IF2CRH_BUSY__NOT_SET 0x00 ///< Set to 1 when writing to the IFx command request
                                      ///< register.                                       
#define CAN0IF2CRH_BUSY__SET     0x80 ///< Reset to 0 when the read or write action has    
                                      ///< finished.                                       
                                                                                           
//------------------------------------------------------------------------------
// CAN0IF2CRL Enums (CAN Interface 2 Command Request Low @ 0xDE)
//------------------------------------------------------------------------------
#define CAN0IF2CRL_MSGNUM__FMASK 0x3F ///< Message Number
#define CAN0IF2CRL_MSGNUM__SHIFT 0x00 ///< Message Number
                                                         
//------------------------------------------------------------------------------
// CAN0IF2DA1H Enums (CAN Interface 2 Data A 1 High @ 0xF7)
//------------------------------------------------------------------------------
#define CAN0IF2DA1H_DATA1__FMASK 0xFF ///< Interface 2 Data 1
#define CAN0IF2DA1H_DATA1__SHIFT 0x00 ///< Interface 2 Data 1
                                                             
//------------------------------------------------------------------------------
// CAN0IF2DA1L Enums (CAN Interface 2 Data A 1 Low @ 0xF6)
//------------------------------------------------------------------------------
#define CAN0IF2DA1L_DATA0__FMASK 0xFF ///< Interface 2 Data 0
#define CAN0IF2DA1L_DATA0__SHIFT 0x00 ///< Interface 2 Data 0
                                                             
//------------------------------------------------------------------------------
// CAN0IF2DA2H Enums (CAN Interface 2 Data A 2 High @ 0xFB)
//------------------------------------------------------------------------------
#define CAN0IF2DA2H_DATA3__FMASK 0xFF ///< Interface 2 Data 3
#define CAN0IF2DA2H_DATA3__SHIFT 0x00 ///< Interface 2 Data 3
                                                             
//------------------------------------------------------------------------------
// CAN0IF2DA2L Enums (CAN Interface 2 Data A 2 Low @ 0xFA)
//------------------------------------------------------------------------------
#define CAN0IF2DA2L_DATA2__FMASK 0xFF ///< Interface 2 Data 2
#define CAN0IF2DA2L_DATA2__SHIFT 0x00 ///< Interface 2 Data 2
                                                             
//------------------------------------------------------------------------------
// CAN0IF2DB1H Enums (CAN Interface 2 Data B 1 High @ 0xFD)
//------------------------------------------------------------------------------
#define CAN0IF2DB1H_DATA5__FMASK 0xFF ///< Interface 2 Data 5
#define CAN0IF2DB1H_DATA5__SHIFT 0x00 ///< Interface 2 Data 5
                                                             
//------------------------------------------------------------------------------
// CAN0IF2DB1L Enums (CAN Interface 2 Data B 1 Low @ 0xFC)
//------------------------------------------------------------------------------
#define CAN0IF2DB1L_DATA4__FMASK 0xFF ///< Interface 2 Data 4
#define CAN0IF2DB1L_DATA4__SHIFT 0x00 ///< Interface 2 Data 4
                                                             
//------------------------------------------------------------------------------
// CAN0IF2DB2H Enums (CAN Interface 2 Data B 2 High @ 0xFF)
//------------------------------------------------------------------------------
#define CAN0IF2DB2H_DATA7__FMASK 0xFF ///< Interface 2 Data 7
#define CAN0IF2DB2H_DATA7__SHIFT 0x00 ///< Interface 2 Data 7
                                                             
//------------------------------------------------------------------------------
// CAN0IF2DB2L Enums (CAN Interface 2 Data B 2 Low @ 0xFE)
//------------------------------------------------------------------------------
#define CAN0IF2DB2L_DATA6__FMASK 0xFF ///< Interface 2 Data 6
#define CAN0IF2DB2L_DATA6__SHIFT 0x00 ///< Interface 2 Data 6
                                                             
//------------------------------------------------------------------------------
// CAN0IF2M1H Enums (CAN Interface 2 Mask 1 High @ 0xEB)
//------------------------------------------------------------------------------
#define CAN0IF2M1H_MSK__FMASK 0xFF ///< Interface 2 Identifier Mask
#define CAN0IF2M1H_MSK__SHIFT 0x00 ///< Interface 2 Identifier Mask
                                                                   
//------------------------------------------------------------------------------
// CAN0IF2M1L Enums (CAN Interface 2 Mask 1 Low @ 0xEA)
//------------------------------------------------------------------------------
#define CAN0IF2M1L_MSK__FMASK 0xFF ///< Interface 2 Identifier Mask
#define CAN0IF2M1L_MSK__SHIFT 0x00 ///< Interface 2 Identifier Mask
                                                                   
//------------------------------------------------------------------------------
// CAN0IF2M2H Enums (CAN Interface 2 Mask 2 High @ 0xED)
//------------------------------------------------------------------------------
#define CAN0IF2M2H_MSK__FMASK     0x1F ///< Interface 2 Identifier Mask                       
#define CAN0IF2M2H_MSK__SHIFT     0x00 ///< Interface 2 Identifier Mask                       
                                                                                              
#define CAN0IF2M2H_MDIR__BMASK    0x40 ///< Mask Message Direction                            
#define CAN0IF2M2H_MDIR__SHIFT    0x06 ///< Mask Message Direction                            
#define CAN0IF2M2H_MDIR__DISABLED 0x00 ///< The message direction bit (DIR) has no effect on  
                                       ///< the acceptance filtering.                         
#define CAN0IF2M2H_MDIR__ENABLED  0x40 ///< The message direction bit (DIR) is used for       
                                       ///< acceptance filtering.                             
                                                                                              
#define CAN0IF2M2H_MXTD__BMASK    0x80 ///< Mask Extended Identifier                          
#define CAN0IF2M2H_MXTD__SHIFT    0x07 ///< Mask Extended Identifier                          
#define CAN0IF2M2H_MXTD__DISABLED 0x00 ///< The extended identifier bit (IDE) has no effect on
                                       ///< the acceptance filtering.                         
#define CAN0IF2M2H_MXTD__ENABLED  0x80 ///< The extended identifier bit (IDE) is used for     
                                       ///< acceptance filtering.                             
                                                                                              
//------------------------------------------------------------------------------
// CAN0IF2M2L Enums (CAN Interface 2 Mask 2 Low @ 0xEC)
//------------------------------------------------------------------------------
#define CAN0IF2M2L_MSK__FMASK 0xFF ///< Interface 2 Identifier Mask
#define CAN0IF2M2L_MSK__SHIFT 0x00 ///< Interface 2 Identifier Mask
                                                                   
//------------------------------------------------------------------------------
// CAN0IF2MCH Enums (CAN Interface 2 Message Control High @ 0xCF)
//------------------------------------------------------------------------------
#define CAN0IF2MCH_TXRQST__BMASK   0x01 ///< Transmit Request Flag                             
#define CAN0IF2MCH_TXRQST__SHIFT   0x00 ///< Transmit Request Flag                             
#define CAN0IF2MCH_TXRQST__NOT_SET 0x00 ///< The message object is not waiting for             
                                        ///< transmission.                                     
#define CAN0IF2MCH_TXRQST__SET     0x01 ///< The transmission of this message object is        
                                        ///< requested and is not yet done.                    
                                                                                               
#define CAN0IF2MCH_RMTEN__BMASK    0x02 ///< Remote Enable                                     
#define CAN0IF2MCH_RMTEN__SHIFT    0x01 ///< Remote Enable                                     
#define CAN0IF2MCH_RMTEN__DISABLED 0x00 ///< At the reception of a remote frame, TXRQST is left
                                        ///< unchanged.                                        
#define CAN0IF2MCH_RMTEN__ENABLED  0x02 ///< At the reception of a remote frame, TXRQST is set 
                                        ///< to 1.                                             
                                                                                               
#define CAN0IF2MCH_RXIE__BMASK     0x04 ///< Receive Interrupt Enable                          
#define CAN0IF2MCH_RXIE__SHIFT     0x02 ///< Receive Interrupt Enable                          
#define CAN0IF2MCH_RXIE__DISABLED  0x00 ///< INTPND will be left unchanged after the successful
                                        ///< reception of a frame.                             
#define CAN0IF2MCH_RXIE__ENABLED   0x04 ///< INTPND will be set after a successful reception of
                                        ///< a frame.                                          
                                                                                               
#define CAN0IF2MCH_TXIE__BMASK     0x08 ///< Transmit Interrupt Enable                         
#define CAN0IF2MCH_TXIE__SHIFT     0x03 ///< Transmit Interrupt Enable                         
#define CAN0IF2MCH_TXIE__DISABLED  0x00 ///< INTPND will be left unchanged after the successful
                                        ///< transmission of a frame.                          
#define CAN0IF2MCH_TXIE__ENABLED   0x08 ///< INTPND will be set after a successful transmission
                                        ///< of a frame.                                       
                                                                                               
#define CAN0IF2MCH_UMASK__BMASK    0x10 ///< Use Acceptance Mask                               
#define CAN0IF2MCH_UMASK__SHIFT    0x04 ///< Use Acceptance Mask                               
#define CAN0IF2MCH_UMASK__DISABLED 0x00 ///< Mask ignored.                                     
#define CAN0IF2MCH_UMASK__ENABLED  0x10 ///< Use the mask (MSK, MXTD, and MDIR) for acceptance 
                                        ///< filtering.                                        
                                                                                               
#define CAN0IF2MCH_INTPND__BMASK   0x20 ///< Interrupt Pending Flag                            
#define CAN0IF2MCH_INTPND__SHIFT   0x05 ///< Interrupt Pending Flag                            
#define CAN0IF2MCH_INTPND__NOT_SET 0x00 ///< This message object is not the source of an       
                                        ///< interrupt.                                        
#define CAN0IF2MCH_INTPND__SET     0x20 ///< This message object is the source of an interrupt.
                                        ///< The interrupt identifier in the interrupt register
                                        ///< will point to this message object if there is no  
                                        ///< other interrupt source with higher priority.      
                                                                                               
#define CAN0IF2MCH_MSGLST__BMASK   0x40 ///< Message Lost Flag                                 
#define CAN0IF2MCH_MSGLST__SHIFT   0x06 ///< Message Lost Flag                                 
#define CAN0IF2MCH_MSGLST__NOT_SET 0x00 ///< No message was lost since the last time this flag 
                                        ///< was cleared by firmware.                          
#define CAN0IF2MCH_MSGLST__SET     0x40 ///< The message handler stored a new message into this
                                        ///< object when NEWDAT was still set and a message has
                                        ///< been lost.                                        
                                                                                               
#define CAN0IF2MCH_NEWDAT__BMASK   0x80 ///< New Data Flag                                     
#define CAN0IF2MCH_NEWDAT__SHIFT   0x07 ///< New Data Flag                                     
#define CAN0IF2MCH_NEWDAT__NOT_SET 0x00 ///< No new data has been written into the data portion
                                        ///< of this message object by the message handler     
                                        ///< since the last time this flag was cleared by      
                                        ///< firmware.                                         
#define CAN0IF2MCH_NEWDAT__SET     0x80 ///< The message handler or firmware have written new  
                                        ///< data into the data portion of this message object.
                                                                                               
//------------------------------------------------------------------------------
// CAN0IF2MCL Enums (CAN Interface 2 Message Control Low @ 0xCE)
//------------------------------------------------------------------------------
#define CAN0IF2MCL_DLC__FMASK   0x0F ///< Data Length Code                                  
#define CAN0IF2MCL_DLC__SHIFT   0x00 ///< Data Length Code                                  
#define CAN0IF2MCL_DLC__0_BYTES 0x00 ///< The data frame has 0 data bytes.                  
#define CAN0IF2MCL_DLC__1_BYTE  0x01 ///< The data frame has 1 data byte.                   
#define CAN0IF2MCL_DLC__2_BYTES 0x02 ///< The data frame has 2 data bytes.                  
#define CAN0IF2MCL_DLC__3_BYTES 0x03 ///< The data frame has 3 data bytes.                  
#define CAN0IF2MCL_DLC__4_BYTES 0x04 ///< The data frame has 4 data bytes.                  
#define CAN0IF2MCL_DLC__5_BYTES 0x05 ///< The data frame has 5 data bytes.                  
#define CAN0IF2MCL_DLC__6_BYTES 0x06 ///< The data frame has 6 data bytes.                  
#define CAN0IF2MCL_DLC__7_BYTES 0x07 ///< The data frame has 7 data bytes.                  
#define CAN0IF2MCL_DLC__8_BYTES 0x08 ///< The data frame has 8 data bytes.                  
                                                                                            
#define CAN0IF2MCL_EOB__BMASK   0x80 ///< End of Buffer Flag                                
#define CAN0IF2MCL_EOB__SHIFT   0x07 ///< End of Buffer Flag                                
#define CAN0IF2MCL_EOB__NOT_SET 0x00 ///< The message object belongs to a FIFO buffer and is
                                     ///< not the last message object of that FIFO buffer.  
#define CAN0IF2MCL_EOB__SET     0x80 ///< The message object is a single message object or  
                                     ///< the last message object of a FIFO buffer.         
                                                                                            
//------------------------------------------------------------------------------
// CAN0IIDH Enums (CAN Interrupt High @ 0x9D)
//------------------------------------------------------------------------------
#define CAN0IIDH_INTID__FMASK 0xFF ///< Interrupt Identifier
#define CAN0IIDH_INTID__SHIFT 0x00 ///< Interrupt Identifier
                                                            
//------------------------------------------------------------------------------
// CAN0IIDL Enums (CAN Interrupt Low @ 0x9C)
//------------------------------------------------------------------------------
#define CAN0IIDL_INTID__FMASK 0xFF ///< Interrupt Identifier
#define CAN0IIDL_INTID__SHIFT 0x00 ///< Interrupt Identifier
                                                            
//------------------------------------------------------------------------------
// CAN0IP1H Enums (CAN Interrupt Pending 1 High @ 0xAF)
//------------------------------------------------------------------------------
#define CAN0IP1H_INTPND__FMASK 0xFF ///< Interrupt Pending
#define CAN0IP1H_INTPND__SHIFT 0x00 ///< Interrupt Pending
                                                          
//------------------------------------------------------------------------------
// CAN0IP1L Enums (CAN Interrupt Pending 1 Low @ 0xAE)
//------------------------------------------------------------------------------
#define CAN0IP1L_INTPND__FMASK 0xFF ///< Interrupt Pending
#define CAN0IP1L_INTPND__SHIFT 0x00 ///< Interrupt Pending
                                                          
//------------------------------------------------------------------------------
// CAN0IP2H Enums (CAN Interrupt Pending 2 High @ 0xB3)
//------------------------------------------------------------------------------
#define CAN0IP2H_INTPND__FMASK 0xFF ///< Interrupt Pending
#define CAN0IP2H_INTPND__SHIFT 0x00 ///< Interrupt Pending
                                                          
//------------------------------------------------------------------------------
// CAN0IP2L Enums (CAN Interrupt Pending 2 Low @ 0xB2)
//------------------------------------------------------------------------------
#define CAN0IP2L_INTPND__FMASK 0xFF ///< Interrupt Pending
#define CAN0IP2L_INTPND__SHIFT 0x00 ///< Interrupt Pending
                                                          
//------------------------------------------------------------------------------
// CAN0MV1H Enums (CAN Message Valid 1 High @ 0xBB)
//------------------------------------------------------------------------------
#define CAN0MV1H_MSGVAL__FMASK 0xFF ///< Message Valid
#define CAN0MV1H_MSGVAL__SHIFT 0x00 ///< Message Valid
                                                      
//------------------------------------------------------------------------------
// CAN0MV1L Enums (CAN Message Valid 1 Low @ 0xBA)
//------------------------------------------------------------------------------
#define CAN0MV1L_MSGVAL__FMASK 0xFF ///< Message Valid
#define CAN0MV1L_MSGVAL__SHIFT 0x00 ///< Message Valid
                                                      
//------------------------------------------------------------------------------
// CAN0MV2H Enums (CAN Message Valid 2 High @ 0xBD)
//------------------------------------------------------------------------------
#define CAN0MV2H_MSGVAL__FMASK 0xFF ///< Message Valid
#define CAN0MV2H_MSGVAL__SHIFT 0x00 ///< Message Valid
                                                      
//------------------------------------------------------------------------------
// CAN0MV2L Enums (CAN Message Valid 2 Low @ 0xBC)
//------------------------------------------------------------------------------
#define CAN0MV2L_MSGVAL__FMASK 0xFF ///< Message Valid
#define CAN0MV2L_MSGVAL__SHIFT 0x00 ///< Message Valid
                                                      
//------------------------------------------------------------------------------
// CAN0ND1H Enums (CAN New Data 1 High @ 0xAB)
//------------------------------------------------------------------------------
#define CAN0ND1H_NEWDAT__FMASK 0xFF ///< New Data
#define CAN0ND1H_NEWDAT__SHIFT 0x00 ///< New Data
                                                 
//------------------------------------------------------------------------------
// CAN0ND1L Enums (CAN New Data 1 Low @ 0xAA)
//------------------------------------------------------------------------------
#define CAN0ND1L_NEWDAT__FMASK 0xFF ///< New Data
#define CAN0ND1L_NEWDAT__SHIFT 0x00 ///< New Data
                                                 
//------------------------------------------------------------------------------
// CAN0ND2H Enums (CAN New Data 2 High @ 0xAD)
//------------------------------------------------------------------------------
#define CAN0ND2H_NEWDAT__FMASK 0xFF ///< New Data
#define CAN0ND2H_NEWDAT__SHIFT 0x00 ///< New Data
                                                 
//------------------------------------------------------------------------------
// CAN0ND2L Enums (CAN New Data 2 Low @ 0xAC)
//------------------------------------------------------------------------------
#define CAN0ND2L_NEWDAT__FMASK 0xFF ///< New Data
#define CAN0ND2L_NEWDAT__SHIFT 0x00 ///< New Data
                                                 
//------------------------------------------------------------------------------
// CAN0STAT Enums (CAN Status @ 0x94)
//------------------------------------------------------------------------------
#define CAN0STAT_LEC__FMASK       0x07 ///< Last Error Code                                   
#define CAN0STAT_LEC__SHIFT       0x00 ///< Last Error Code                                   
#define CAN0STAT_LEC__NO_ERROR    0x00 ///< No error.                                         
#define CAN0STAT_LEC__STUFF_ERROR 0x01 ///< More than 5 equal bits in a sequence have occurred
                                       ///< in a part of a received message where this is not 
                                       ///< allowed.                                          
#define CAN0STAT_LEC__FORM_ERROR  0x02 ///< A fixed format part of a received frame has the   
                                       ///< wrong format.                                     
#define CAN0STAT_LEC__ACK_ERROR   0x03 ///< The message this CAN module transmitted was not   
                                       ///< acknowledged by another node.                     
#define CAN0STAT_LEC__BIT1_ERROR  0x04 ///< During the transmission of a message (with the    
                                       ///< exception of the arbitration field), the device   
                                       ///< wanted to send a recessive level (bit of logical  
                                       ///< value 1), but the monitored bus value was         
                                       ///< dominant.                                         
#define CAN0STAT_LEC__BIT0_ERROR  0x05 ///< During the transmission of a message, acknowledge 
                                       ///< bit, active error flag, or overload flag, the     
                                       ///< device wanted to send a dominant level (data or   
                                       ///< identifier bit logical value 0), but the monitored
                                       ///< bus value was recessive. During busoff recovery,  
                                       ///< this status is set each time a sequence of 11     
                                       ///< recessive bits has been monitored. This enables   
                                       ///< the CAN module to monitor the proceeding of the   
                                       ///< busoff recovery sequence (indicating the bus is   
                                       ///< not stuck at dominant or continuously disturbed). 
#define CAN0STAT_LEC__CRC_ERROR   0x06 ///< The CRC checksum was incorrect in the message     
                                       ///< received; the CRC received for an incoming message
                                       ///< does not match with the calculated CRC for the    
                                       ///< received data.                                    
                                                                                              
#define CAN0STAT_TXOK__BMASK      0x08 ///< Message Transmit Flag                             
#define CAN0STAT_TXOK__SHIFT      0x03 ///< Message Transmit Flag                             
#define CAN0STAT_TXOK__NOT_SET    0x00 ///< Since this bit was last reset, no message has bee 
                                       ///< successfully transmitted.                         
#define CAN0STAT_TXOK__SET        0x08 ///< Since this bit was last reset, a message has been 
                                       ///< successfully (error free and acknowledged by at   
                                       ///< least one other node) transmitted.                
                                                                                              
#define CAN0STAT_RXOK__BMASK      0x10 ///< Message Receive Flag                              
#define CAN0STAT_RXOK__SHIFT      0x04 ///< Message Receive Flag                              
#define CAN0STAT_RXOK__NOT_SET    0x00 ///< Since this bit was last reset, no message has bee 
                                       ///< successfully received.                            
#define CAN0STAT_RXOK__SET        0x10 ///< Since this bit was last reset, a message has been 
                                       ///< successfully  received independent of the result  
                                       ///< of acceptance filtering.                          
                                                                                              
#define CAN0STAT_EPASS__BMASK     0x20 ///< Error Passive Flag                                
#define CAN0STAT_EPASS__SHIFT     0x05 ///< Error Passive Flag                                
#define CAN0STAT_EPASS__NOT_SET   0x00 ///< The CAN module is in the error passive state as   
                                       ///< defined by the CAN specification.                 
#define CAN0STAT_EPASS__SET       0x20 ///< The CAN module is error active.                   
                                                                                              
#define CAN0STAT_EWARN__BMASK     0x40 ///< Warning Status Flag                               
#define CAN0STAT_EWARN__SHIFT     0x06 ///< Warning Status Flag                               
#define CAN0STAT_EWARN__NOT_SET   0x00 ///< Both error counters are below the error warning   
                                       ///< limit of 96.                                      
#define CAN0STAT_EWARN__SET       0x40 ///< At least one of the error counters has reached the
                                       ///< error warning limit of 96.                        
                                                                                              
#define CAN0STAT_BOFF__BMASK      0x80 ///< Busoff Status Flag                                
#define CAN0STAT_BOFF__SHIFT      0x07 ///< Busoff Status Flag                                
#define CAN0STAT_BOFF__NOT_SET    0x00 ///< The CAN module is not busoff.                     
#define CAN0STAT_BOFF__SET        0x80 ///< The CAN module is in busoff state.                
                                                                                              
//------------------------------------------------------------------------------
// CAN0TR1H Enums (CAN Transmission Request 1 High @ 0xA3)
//------------------------------------------------------------------------------
#define CAN0TR1H_TXRQST__FMASK 0xFF ///< Transmission Request
#define CAN0TR1H_TXRQST__SHIFT 0x00 ///< Transmission Request
                                                             
//------------------------------------------------------------------------------
// CAN0TR1L Enums (CAN Transmission Request 1 Low @ 0xA2)
//------------------------------------------------------------------------------
#define CAN0TR1L_TXRQST__FMASK 0xFF ///< Transmission Request
#define CAN0TR1L_TXRQST__SHIFT 0x00 ///< Transmission Request
                                                             
//------------------------------------------------------------------------------
// CAN0TR2H Enums (CAN Transmission Request 2 High @ 0xA5)
//------------------------------------------------------------------------------
#define CAN0TR2H_TXRQST__FMASK 0xFF ///< Transmission Request
#define CAN0TR2H_TXRQST__SHIFT 0x00 ///< Transmission Request
                                                             
//------------------------------------------------------------------------------
// CAN0TR2L Enums (CAN Transmission Request 2 Low @ 0xA4)
//------------------------------------------------------------------------------
#define CAN0TR2L_TXRQST__FMASK 0xFF ///< Transmission Request
#define CAN0TR2L_TXRQST__SHIFT 0x00 ///< Transmission Request
                                                             
//------------------------------------------------------------------------------
// CAN0TST Enums (CAN Test @ 0x9E)
//------------------------------------------------------------------------------
#define CAN0TST_BASIC__BMASK      0x04 ///< Basic Mode                                       
#define CAN0TST_BASIC__SHIFT      0x02 ///< Basic Mode                                       
#define CAN0TST_BASIC__DISABLED   0x00 ///< Basic mode disabled.                             
#define CAN0TST_BASIC__ENABLED    0x04 ///< IF1 registers are used as the TX buffer, and IF2 
                                       ///< registers are used as the RX buffer.             
                                                                                             
#define CAN0TST_SILENT__BMASK     0x08 ///< Silent Mode                                      
#define CAN0TST_SILENT__SHIFT     0x03 ///< Silent Mode                                      
#define CAN0TST_SILENT__DISABLED  0x00 ///< Disable silent mode (normal operation).          
#define CAN0TST_SILENT__ENABLED   0x08 ///< Enable silent mode.                              
                                                                                             
#define CAN0TST_LBACK__BMASK      0x10 ///< Loop Back Mode                                   
#define CAN0TST_LBACK__SHIFT      0x04 ///< Loop Back Mode                                   
#define CAN0TST_LBACK__DISABLED   0x00 ///< Loop back mode is disabled.                      
#define CAN0TST_LBACK__ENABLED    0x10 ///< Loop back mode is enabled.                       
                                                                                             
#define CAN0TST_TX__FMASK         0x60 ///< Transmit Pin Mode                                
#define CAN0TST_TX__SHIFT         0x05 ///< Transmit Pin Mode                                
#define CAN0TST_TX__HW_CONTROLLED 0x00 ///< CAN0_TX is controlled by the CAN module.         
#define CAN0TST_TX__SAMPLE        0x20 ///< Sample point can be monitored at the CAN0_TX pin.
#define CAN0TST_TX__DOMINANT      0x40 ///< CAN0_TX drives a dominant value (0).             
#define CAN0TST_TX__RECESSIVE     0x60 ///< CAN0_TX drives a recessive value (1).            
                                                                                             
#define CAN0TST_RX__BMASK         0x80 ///< Receive Pin Status                               
#define CAN0TST_RX__SHIFT         0x07 ///< Receive Pin Status                               
#define CAN0TST_RX__DOMINANT      0x00 ///< The CAN bus is dominant (CAN0_RX is 0).          
#define CAN0TST_RX__RECESSIVE     0x80 ///< The CAN bus is recessive (CAN0_RX is 1).         
                                                                                             
//------------------------------------------------------------------------------
// ACC Enums (Accumulator @ 0xE0)
//------------------------------------------------------------------------------
#define ACC_ACC__FMASK 0xFF ///< Accumulator
#define ACC_ACC__SHIFT 0x00 ///< Accumulator
                                            
//------------------------------------------------------------------------------
// B Enums (B Register @ 0xF0)
//------------------------------------------------------------------------------
#define B_B__FMASK 0xFF ///< B Register
#define B_B__SHIFT 0x00 ///< B Register
                                       
//------------------------------------------------------------------------------
// DPH Enums (Data Pointer High @ 0x83)
//------------------------------------------------------------------------------
#define DPH_DPH__FMASK 0xFF ///< Data Pointer High
#define DPH_DPH__SHIFT 0x00 ///< Data Pointer High
                                                  
//------------------------------------------------------------------------------
// DPL Enums (Data Pointer Low @ 0x82)
//------------------------------------------------------------------------------
#define DPL_DPL__FMASK 0xFF ///< Data Pointer Low
#define DPL_DPL__SHIFT 0x00 ///< Data Pointer Low
                                                 
//------------------------------------------------------------------------------
// PSBANK Enums (Program Space Bank Select @ 0xF5)
//------------------------------------------------------------------------------
#define PSBANK_IFBANK__FMASK       0x03 ///< Instruction Fetch Operations Bank Select         
#define PSBANK_IFBANK__SHIFT       0x00 ///< Instruction Fetch Operations Bank Select         
#define PSBANK_IFBANK__INSTR_BANK0 0x00 ///< Instructions fetch from Bank 0 (note that Bank 0 
                                        ///< is also mapped between 0x0000 to 0x7FFF).        
#define PSBANK_IFBANK__INSTR_BANK1 0x01 ///< Instructions fetch from Bank 1.                  
#define PSBANK_IFBANK__INSTR_BANK2 0x02 ///< Instructions fetch from Bank 2.                  
#define PSBANK_IFBANK__INSTR_BANK3 0x03 ///< Instructions fetch from Bank 3.                  
                                                                                              
#define PSBANK_COBANK__FMASK       0x30 ///< Constant Operations Bank Select                  
#define PSBANK_COBANK__SHIFT       0x04 ///< Constant Operations Bank Select                  
#define PSBANK_COBANK__CONST_BANK0 0x00 ///< Constant operations target Bank 0 (note that Bank
                                        ///< 0 is also mapped between 0x0000 to 0x7FFF).      
#define PSBANK_COBANK__CONST_BANK1 0x10 ///< Constant operations target Bank 1.               
#define PSBANK_COBANK__CONST_BANK2 0x20 ///< Constant operations target Bank 2.               
#define PSBANK_COBANK__CONST_BANK3 0x30 ///< Constant operations target Bank 3.               
                                                                                              
//------------------------------------------------------------------------------
// PSW Enums (Program Status Word @ 0xD0)
//------------------------------------------------------------------------------
#define PSW_PARITY__BMASK   0x01 ///< Parity Flag                                       
#define PSW_PARITY__SHIFT   0x00 ///< Parity Flag                                       
#define PSW_PARITY__NOT_SET 0x00 ///< The sum of the 8 bits in the accumulator is even. 
#define PSW_PARITY__SET     0x01 ///< The sum of the 8 bits in the accumulator is odd.  
                                                                                        
#define PSW_F1__BMASK       0x02 ///< User Flag 1                                       
#define PSW_F1__SHIFT       0x01 ///< User Flag 1                                       
#define PSW_F1__NOT_SET     0x00 ///< Flag is not set.                                  
#define PSW_F1__SET         0x02 ///< Flag is set.                                      
                                                                                        
#define PSW_OV__BMASK       0x04 ///< Overflow Flag                                     
#define PSW_OV__SHIFT       0x02 ///< Overflow Flag                                     
#define PSW_OV__NOT_SET     0x00 ///< An overflow did not occur.                        
#define PSW_OV__SET         0x04 ///< An overflow occurred.                             
                                                                                        
#define PSW_RS__FMASK       0x18 ///< Register Bank Select                              
#define PSW_RS__SHIFT       0x03 ///< Register Bank Select                              
#define PSW_RS__BANK0       0x00 ///< Bank 0, Addresses 0x00-0x07                       
#define PSW_RS__BANK1       0x08 ///< Bank 1, Addresses 0x08-0x0F                       
#define PSW_RS__BANK2       0x10 ///< Bank 2, Addresses 0x10-0x17                       
#define PSW_RS__BANK3       0x18 ///< Bank 3, Addresses 0x18-0x1F                       
                                                                                        
#define PSW_F0__BMASK       0x20 ///< User Flag 0                                       
#define PSW_F0__SHIFT       0x05 ///< User Flag 0                                       
#define PSW_F0__NOT_SET     0x00 ///< Flag is not set.                                  
#define PSW_F0__SET         0x20 ///< Flag is set.                                      
                                                                                        
#define PSW_AC__BMASK       0x40 ///< Auxiliary Carry Flag                              
#define PSW_AC__SHIFT       0x06 ///< Auxiliary Carry Flag                              
#define PSW_AC__NOT_SET     0x00 ///< A carry into (addition) or borrow from            
                                 ///< (subtraction) the high order nibble did not occur.
#define PSW_AC__SET         0x40 ///< A carry into (addition) or borrow from            
                                 ///< (subtraction) the high order nibble occurred.     
                                                                                        
#define PSW_CY__BMASK       0x80 ///< Carry Flag                                        
#define PSW_CY__SHIFT       0x07 ///< Carry Flag                                        
#define PSW_CY__NOT_SET     0x00 ///< A carry (addition) or borrow (subtraction) did not
                                 ///< occur.                                            
#define PSW_CY__SET         0x80 ///< A carry (addition) or borrow (subtraction)        
                                 ///< occurred.                                         
                                                                                        
//------------------------------------------------------------------------------
// SFRLAST Enums (SFR Page Last @ 0x86)
//------------------------------------------------------------------------------
#define SFRLAST_SFRLAST__FMASK 0xFF ///< SFR Page Last
#define SFRLAST_SFRLAST__SHIFT 0x00 ///< SFR Page Last
                                                      
//------------------------------------------------------------------------------
// SFRNEXT Enums (SFR Page Next @ 0x85)
//------------------------------------------------------------------------------
#define SFRNEXT_SFRNEXT__FMASK 0xFF ///< SFR Page Next
#define SFRNEXT_SFRNEXT__SHIFT 0x00 ///< SFR Page Next
                                                      
//------------------------------------------------------------------------------
// SFRPAGE Enums (SFR Page @ 0xA7)
//------------------------------------------------------------------------------
#define SFRPAGE_SFRPAGE__FMASK 0xFF ///< SFR Page
#define SFRPAGE_SFRPAGE__SHIFT 0x00 ///< SFR Page
                                                 
//------------------------------------------------------------------------------
// SFRPGCN Enums (SFR Page Control @ 0x84)
//------------------------------------------------------------------------------
#define SFRPGCN_SFRPGEN__BMASK              0x01 ///< SFR Automatic Page Control Enable                 
#define SFRPGCN_SFRPGEN__SHIFT              0x00 ///< SFR Automatic Page Control Enable                 
#define SFRPGCN_SFRPGEN__AUTO_PAGE_DISABLED 0x00 ///< Disable SFR automatic paging. The C8051 core will 
                                                 ///< not automatically change to the appropriate SFR   
                                                 ///< page (i.e., the SFR page that contains the SFRs   
                                                 ///< for the peripheral/function that was the source of
                                                 ///< the interrupt).                                   
#define SFRPGCN_SFRPGEN__AUTO_PAGE_ENABLED  0x01 ///< Enable SFR automatic paging. Upon interrupt, the  
                                                 ///< C8051 will switch the SFR page to the page that   
                                                 ///< contains the SFRs for the peripheral or function  
                                                 ///< that is the source of the interrupt.              
                                                                                                        
//------------------------------------------------------------------------------
// SP Enums (Stack Pointer @ 0x81)
//------------------------------------------------------------------------------
#define SP_SP__FMASK 0xFF ///< Stack Pointer
#define SP_SP__SHIFT 0x00 ///< Stack Pointer
                                            
//------------------------------------------------------------------------------
// CLKMUL Enums (Clock Multiplier Control @ 0x97)
//------------------------------------------------------------------------------
#define CLKMUL_MULSEL__FMASK            0x03 ///< Clock Multiplier Input Select                     
#define CLKMUL_MULSEL__SHIFT            0x00 ///< Clock Multiplier Input Select                     
#define CLKMUL_MULSEL__HFOSC_DIV_2      0x00 ///< Clock Multiplier input clock source is the        
                                             ///< Internal High-Frequency Oscillator / 2.           
#define CLKMUL_MULSEL__EXTOSC_DIV_2     0x01 ///< Clock Multiplier input clock source is the        
                                             ///< External Oscillator / 2.                          
#define CLKMUL_MULSEL__HFOSC            0x02 ///< Clock Multiplier input clock source is the        
                                             ///< Internal High-Frequency Oscillator.               
#define CLKMUL_MULSEL__EXTOSC           0x03 ///< Clock Multiplier input clock source is the        
                                             ///< External Oscillator.                              
                                                                                                    
#define CLKMUL_MULDIV__FMASK            0x1C ///< Clock Multiplier Output Scaling Factor            
#define CLKMUL_MULDIV__SHIFT            0x02 ///< Clock Multiplier Output Scaling Factor            
#define CLKMUL_MULDIV__DIV_ONE          0x00 ///< Clock Multiplier Output scaled by a factor of 1.  
#define CLKMUL_MULDIV__DIV_TWO_THIRDS   0x0C ///< Clock Multiplier Output scaled by a factor of 2/3.
#define CLKMUL_MULDIV__DIV_HALF         0x10 ///< Clock Multiplier Output scaled by a factor of 2/4 
                                             ///< (or 1/2).                                         
#define CLKMUL_MULDIV__DIV_TWO_FIFTHS   0x14 ///< Clock Multiplier Output scaled by a factor of 2/5.
#define CLKMUL_MULDIV__DIV_ONE_THIRD    0x18 ///< Clock Multiplier Output scaled by a factor of 2/6 
                                             ///< (or 1/3).                                         
#define CLKMUL_MULDIV__DIV_TWO_SEVENTHS 0x1C ///< Clock Multiplier Output scaled by a factor of 2/7.
                                                                                                    
#define CLKMUL_MULRDY__BMASK            0x20 ///< Clock Multiplier Ready                            
#define CLKMUL_MULRDY__SHIFT            0x05 ///< Clock Multiplier Ready                            
#define CLKMUL_MULRDY__NOT_SET          0x00 ///< Clock Multiplier not ready.                       
#define CLKMUL_MULRDY__SET              0x20 ///< Clock Multiplier is ready (locked).               
                                                                                                    
#define CLKMUL_MULINIT__BMASK           0x40 ///< Clock Multiplier Initialize                       
#define CLKMUL_MULINIT__SHIFT           0x06 ///< Clock Multiplier Initialize                       
#define CLKMUL_MULINIT__NOT_SET         0x00 ///< Do not initialize the Clock Multiplier.           
#define CLKMUL_MULINIT__SET             0x40 ///< Initialize the Clock Multiplier.                  
                                                                                                    
#define CLKMUL_MULEN__BMASK             0x80 ///< Clock Multiplier Enable                           
#define CLKMUL_MULEN__SHIFT             0x07 ///< Clock Multiplier Enable                           
#define CLKMUL_MULEN__DISABLED          0x00 ///< Disable the Clock Multiplier.                     
#define CLKMUL_MULEN__ENABLED           0x80 ///< Enable the Clock Multiplier.                      
                                                                                                    
//------------------------------------------------------------------------------
// CLKSEL Enums (Clock Select @ 0x8F)
//------------------------------------------------------------------------------
#define CLKSEL_CLKSL__FMASK  0x03 ///< Clock Source Select                               
#define CLKSEL_CLKSL__SHIFT  0x00 ///< Clock Source Select                               
#define CLKSEL_CLKSL__HFOSC  0x00 ///< Clock (SYSCLK) derived from the Internal precision
                                  ///< High-Frequency Oscillator and scaled per the IFCN 
                                  ///< bits in register OSCICN.                          
#define CLKSEL_CLKSL__EXTOSC 0x01 ///< Clock (SYSCLK) derived from the External          
                                  ///< Oscillator circuit.                               
#define CLKSEL_CLKSL__CLKMUL 0x02 ///< Clock (SYSCLK) derived from the Clock Multiplier. 
                                                                                         
//------------------------------------------------------------------------------
// CPT0CN Enums (Comparator 0 Control @ 0x9A)
//------------------------------------------------------------------------------
#define CPT0CN_CPHYN__FMASK                0x03 ///< Comparator Negative Hysteresis Control            
#define CPT0CN_CPHYN__SHIFT                0x00 ///< Comparator Negative Hysteresis Control            
#define CPT0CN_CPHYN__DISABLED             0x00 ///< Disable negative hysteresis.                      
#define CPT0CN_CPHYN__ENABLED_MODE1        0x01 ///< Negative Hysteresis = Hysteresis 1.               
#define CPT0CN_CPHYN__ENABLED_MODE2        0x02 ///< Negative Hysteresis = Hysteresis 2.               
#define CPT0CN_CPHYN__ENABLED_MODE3        0x03 ///< Negative Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                       
#define CPT0CN_CPHYP__FMASK                0x0C ///< Comparator Positive Hysteresis Control            
#define CPT0CN_CPHYP__SHIFT                0x02 ///< Comparator Positive Hysteresis Control            
#define CPT0CN_CPHYP__DISABLED             0x00 ///< Disable positive hysteresis.                      
#define CPT0CN_CPHYP__ENABLED_MODE1        0x04 ///< Positive Hysteresis = Hysteresis 1.               
#define CPT0CN_CPHYP__ENABLED_MODE2        0x08 ///< Positive Hysteresis = Hysteresis 2.               
#define CPT0CN_CPHYP__ENABLED_MODE3        0x0C ///< Positive Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                       
#define CPT0CN_CPFIF__BMASK                0x10 ///< Comparator Falling-Edge Flag                      
#define CPT0CN_CPFIF__SHIFT                0x04 ///< Comparator Falling-Edge Flag                      
#define CPT0CN_CPFIF__NOT_SET              0x00 ///< No comparator falling edge has occurred since this
                                                ///< flag was last cleared.                            
#define CPT0CN_CPFIF__FALLING_EDGE         0x10 ///< Comparator falling edge has occurred.             
                                                                                                       
#define CPT0CN_CPRIF__BMASK                0x20 ///< Comparator Rising-Edge Flag                       
#define CPT0CN_CPRIF__SHIFT                0x05 ///< Comparator Rising-Edge Flag                       
#define CPT0CN_CPRIF__NOT_SET              0x00 ///< No comparator rising edge has occurred since this 
                                                ///< flag was last cleared.                            
#define CPT0CN_CPRIF__RISING_EDGE          0x20 ///< Comparator rising edge has occurred.              
                                                                                                       
#define CPT0CN_CPOUT__BMASK                0x40 ///< Comparator Output State Flag                      
#define CPT0CN_CPOUT__SHIFT                0x06 ///< Comparator Output State Flag                      
#define CPT0CN_CPOUT__POS_LESS_THAN_NEG    0x00 ///< Voltage on CP0P < CP0N.                           
#define CPT0CN_CPOUT__POS_GREATER_THAN_NEG 0x40 ///< Voltage on CP0P > CP0N.                           
                                                                                                       
#define CPT0CN_CPEN__BMASK                 0x80 ///< Comparator Enable                                 
#define CPT0CN_CPEN__SHIFT                 0x07 ///< Comparator Enable                                 
#define CPT0CN_CPEN__DISABLED              0x00 ///< Comparator disabled.                              
#define CPT0CN_CPEN__ENABLED               0x80 ///< Comparator enabled.                               
                                                                                                       
//------------------------------------------------------------------------------
// CPT0MD Enums (Comparator 0 Mode @ 0x9B)
//------------------------------------------------------------------------------
#define CPT0MD_CPMD__FMASK              0x03 ///< Comparator Mode Select                      
#define CPT0MD_CPMD__SHIFT              0x00 ///< Comparator Mode Select                      
#define CPT0MD_CPMD__MODE0              0x00 ///< Mode 0 (Fastest Response Time, Highest Power
                                             ///< Consumption)                                
#define CPT0MD_CPMD__MODE1              0x01 ///< Mode 1                                      
#define CPT0MD_CPMD__MODE2              0x02 ///< Mode 2                                      
#define CPT0MD_CPMD__MODE3              0x03 ///< Mode 3 (Slowest Response Time, Lowest Power 
                                             ///< Consumption)                                
                                                                                              
#define CPT0MD_CPFIE__BMASK             0x10 ///< Comparator Falling-Edge Interrupt Enable    
#define CPT0MD_CPFIE__SHIFT             0x04 ///< Comparator Falling-Edge Interrupt Enable    
#define CPT0MD_CPFIE__FALL_INT_DISABLED 0x00 ///< Comparator falling-edge interrupt disabled. 
#define CPT0MD_CPFIE__FALL_INT_ENABLED  0x10 ///< Comparator falling-edge interrupt enabled.  
                                                                                              
#define CPT0MD_CPRIE__BMASK             0x20 ///< Comparator Rising-Edge Interrupt Enable     
#define CPT0MD_CPRIE__SHIFT             0x05 ///< Comparator Rising-Edge Interrupt Enable     
#define CPT0MD_CPRIE__RISE_INT_DISABLED 0x00 ///< Comparator rising-edge interrupt disabled.  
#define CPT0MD_CPRIE__RISE_INT_ENABLED  0x20 ///< Comparator rising-edge interrupt enabled.   
                                                                                              
//------------------------------------------------------------------------------
// CPT0MX Enums (Comparator 0 Multiplexer Selection @ 0x9C)
//------------------------------------------------------------------------------
#define CPT0MX_CMXP__FMASK   0x0F ///< Comparator Positive Input MUX Selection
#define CPT0MX_CMXP__SHIFT   0x00 ///< Comparator Positive Input MUX Selection
#define CPT0MX_CMXP__CMP0P0  0x00 ///< External pin CMP0P.0.                  
#define CPT0MX_CMXP__CMP0P1  0x01 ///< External pin CMP0P.1.                  
#define CPT0MX_CMXP__CMP0P2  0x02 ///< External pin CMP0P.2.                  
#define CPT0MX_CMXP__CMP0P3  0x03 ///< External pin CMP0P.3.                  
#define CPT0MX_CMXP__CMP0P4  0x04 ///< External pin CMP0P.4.                  
#define CPT0MX_CMXP__CMP0P5  0x05 ///< External pin CMP0P.5.                  
#define CPT0MX_CMXP__CMP0P6  0x06 ///< External pin CMP0P.6.                  
#define CPT0MX_CMXP__CMP0P7  0x07 ///< External pin CMP0P.7.                  
#define CPT0MX_CMXP__CMP0P8  0x08 ///< External pin CMP0P.8.                  
#define CPT0MX_CMXP__CMP0P9  0x09 ///< External pin CMP0P.9.                  
#define CPT0MX_CMXP__CMP0P10 0x0A ///< External pin CMP0P.10.                 
#define CPT0MX_CMXP__CMP0P11 0x0B ///< External pin CMP0P.11.                 
#define CPT0MX_CMXP__NONE    0x0F ///< No input selected.                     
                                                                              
#define CPT0MX_CMXN__FMASK   0xF0 ///< Comparator Negative Input MUX Selection
#define CPT0MX_CMXN__SHIFT   0x04 ///< Comparator Negative Input MUX Selection
#define CPT0MX_CMXN__CMP0N0  0x00 ///< External pin CMP0N.0.                  
#define CPT0MX_CMXN__CMP0N1  0x10 ///< External pin CMP0N.1.                  
#define CPT0MX_CMXN__CMP0N2  0x20 ///< External pin CMP0N.2.                  
#define CPT0MX_CMXN__CMP0N3  0x30 ///< External pin CMP0N.3.                  
#define CPT0MX_CMXN__CMP0N4  0x40 ///< External pin CMP0N.4.                  
#define CPT0MX_CMXN__CMP0N5  0x50 ///< External pin CMP0N.5.                  
#define CPT0MX_CMXN__CMP0N6  0x60 ///< External pin CMP0N.6.                  
#define CPT0MX_CMXN__CMP0N7  0x70 ///< External pin CMP0N.7.                  
#define CPT0MX_CMXN__CMP0N8  0x80 ///< External pin CMP0N.8.                  
#define CPT0MX_CMXN__CMP0N9  0x90 ///< External pin CMP0N.9.                  
#define CPT0MX_CMXN__CMP0N10 0xA0 ///< External pin CMP0N.10.                 
#define CPT0MX_CMXN__CMP0N11 0xB0 ///< External pin CMP0N.11.                 
#define CPT0MX_CMXN__NONE    0xF0 ///< No input selected.                     
                                                                              
//------------------------------------------------------------------------------
// CPT1CN Enums (Comparator 1 Control @ 0x9D)
//------------------------------------------------------------------------------
#define CPT1CN_CPHYN__FMASK                0x03 ///< Comparator Negative Hysteresis Control            
#define CPT1CN_CPHYN__SHIFT                0x00 ///< Comparator Negative Hysteresis Control            
#define CPT1CN_CPHYN__DISABLED             0x00 ///< Disable negative hysteresis.                      
#define CPT1CN_CPHYN__ENABLED_MODE1        0x01 ///< Negative Hysteresis = Hysteresis 1.               
#define CPT1CN_CPHYN__ENABLED_MODE2        0x02 ///< Negative Hysteresis = Hysteresis 2.               
#define CPT1CN_CPHYN__ENABLED_MODE3        0x03 ///< Negative Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                       
#define CPT1CN_CPHYP__FMASK                0x0C ///< Comparator Positive Hysteresis Control            
#define CPT1CN_CPHYP__SHIFT                0x02 ///< Comparator Positive Hysteresis Control            
#define CPT1CN_CPHYP__DISABLED             0x00 ///< Disable positive hysteresis.                      
#define CPT1CN_CPHYP__ENABLED_MODE1        0x04 ///< Positive Hysteresis = Hysteresis 1.               
#define CPT1CN_CPHYP__ENABLED_MODE2        0x08 ///< Positive Hysteresis = Hysteresis 2.               
#define CPT1CN_CPHYP__ENABLED_MODE3        0x0C ///< Positive Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                       
#define CPT1CN_CPFIF__BMASK                0x10 ///< Comparator Falling-Edge Flag                      
#define CPT1CN_CPFIF__SHIFT                0x04 ///< Comparator Falling-Edge Flag                      
#define CPT1CN_CPFIF__NOT_SET              0x00 ///< No comparator falling edge has occurred since this
                                                ///< flag was last cleared.                            
#define CPT1CN_CPFIF__FALLING_EDGE         0x10 ///< Comparator falling edge has occurred.             
                                                                                                       
#define CPT1CN_CPRIF__BMASK                0x20 ///< Comparator Rising-Edge Flag                       
#define CPT1CN_CPRIF__SHIFT                0x05 ///< Comparator Rising-Edge Flag                       
#define CPT1CN_CPRIF__NOT_SET              0x00 ///< No comparator rising edge has occurred since this 
                                                ///< flag was last cleared.                            
#define CPT1CN_CPRIF__RISING_EDGE          0x20 ///< Comparator rising edge has occurred.              
                                                                                                       
#define CPT1CN_CPOUT__BMASK                0x40 ///< Comparator Output State Flag                      
#define CPT1CN_CPOUT__SHIFT                0x06 ///< Comparator Output State Flag                      
#define CPT1CN_CPOUT__POS_LESS_THAN_NEG    0x00 ///< Voltage on CP1P < CP1N.                           
#define CPT1CN_CPOUT__POS_GREATER_THAN_NEG 0x40 ///< Voltage on CP1P > CP1N.                           
                                                                                                       
#define CPT1CN_CPEN__BMASK                 0x80 ///< Comparator Enable                                 
#define CPT1CN_CPEN__SHIFT                 0x07 ///< Comparator Enable                                 
#define CPT1CN_CPEN__DISABLED              0x00 ///< Comparator disabled.                              
#define CPT1CN_CPEN__ENABLED               0x80 ///< Comparator enabled.                               
                                                                                                       
//------------------------------------------------------------------------------
// CPT1MD Enums (Comparator 1 Mode @ 0x9E)
//------------------------------------------------------------------------------
#define CPT1MD_CPMD__FMASK              0x03 ///< Comparator Mode Select                      
#define CPT1MD_CPMD__SHIFT              0x00 ///< Comparator Mode Select                      
#define CPT1MD_CPMD__MODE0              0x00 ///< Mode 0 (Fastest Response Time, Highest Power
                                             ///< Consumption)                                
#define CPT1MD_CPMD__MODE1              0x01 ///< Mode 1                                      
#define CPT1MD_CPMD__MODE2              0x02 ///< Mode 2                                      
#define CPT1MD_CPMD__MODE3              0x03 ///< Mode 3 (Slowest Response Time, Lowest Power 
                                             ///< Consumption)                                
                                                                                              
#define CPT1MD_CPFIE__BMASK             0x10 ///< Comparator Falling-Edge Interrupt Enable    
#define CPT1MD_CPFIE__SHIFT             0x04 ///< Comparator Falling-Edge Interrupt Enable    
#define CPT1MD_CPFIE__FALL_INT_DISABLED 0x00 ///< Comparator falling-edge interrupt disabled. 
#define CPT1MD_CPFIE__FALL_INT_ENABLED  0x10 ///< Comparator falling-edge interrupt enabled.  
                                                                                              
#define CPT1MD_CPRIE__BMASK             0x20 ///< Comparator Rising-Edge Interrupt Enable     
#define CPT1MD_CPRIE__SHIFT             0x05 ///< Comparator Rising-Edge Interrupt Enable     
#define CPT1MD_CPRIE__RISE_INT_DISABLED 0x00 ///< Comparator rising-edge interrupt disabled.  
#define CPT1MD_CPRIE__RISE_INT_ENABLED  0x20 ///< Comparator rising-edge interrupt enabled.   
                                                                                              
//------------------------------------------------------------------------------
// CPT1MX Enums (Comparator 1 Multiplexer Selection @ 0x9F)
//------------------------------------------------------------------------------
#define CPT1MX_CMXP__FMASK   0x0F ///< Comparator Positive Input MUX Selection
#define CPT1MX_CMXP__SHIFT   0x00 ///< Comparator Positive Input MUX Selection
#define CPT1MX_CMXP__CMP1P0  0x00 ///< External pin CMP1P.0.                  
#define CPT1MX_CMXP__CMP1P1  0x01 ///< External pin CMP1P.1.                  
#define CPT1MX_CMXP__CMP1P2  0x02 ///< External pin CMP1P.2.                  
#define CPT1MX_CMXP__CMP1P3  0x03 ///< External pin CMP1P.3.                  
#define CPT1MX_CMXP__CMP1P4  0x04 ///< External pin CMP1P.4.                  
#define CPT1MX_CMXP__CMP1P5  0x05 ///< External pin CMP1P.5.                  
#define CPT1MX_CMXP__CMP1P6  0x06 ///< External pin CMP1P.6.                  
#define CPT1MX_CMXP__CMP1P7  0x07 ///< External pin CMP1P.7.                  
#define CPT1MX_CMXP__CMP1P8  0x08 ///< External pin CMP1P.8.                  
#define CPT1MX_CMXP__CMP1P9  0x09 ///< External pin CMP1P.9.                  
#define CPT1MX_CMXP__CMP1P10 0x0A ///< External pin CMP1P.10.                 
#define CPT1MX_CMXP__CMP1P11 0x0B ///< External pin CMP1P.11.                 
#define CPT1MX_CMXP__NONE    0x0F ///< No input selected.                     
                                                                              
#define CPT1MX_CMXN__FMASK   0xF0 ///< Comparator Negative Input MUX Selection
#define CPT1MX_CMXN__SHIFT   0x04 ///< Comparator Negative Input MUX Selection
#define CPT1MX_CMXN__CMP1N0  0x00 ///< External pin CMP1N.0.                  
#define CPT1MX_CMXN__CMP1N1  0x10 ///< External pin CMP1N.1.                  
#define CPT1MX_CMXN__CMP1N2  0x20 ///< External pin CMP1N.2.                  
#define CPT1MX_CMXN__CMP1N3  0x30 ///< External pin CMP1N.3.                  
#define CPT1MX_CMXN__CMP1N4  0x40 ///< External pin CMP1N.4.                  
#define CPT1MX_CMXN__CMP1N5  0x50 ///< External pin CMP1N.5.                  
#define CPT1MX_CMXN__CMP1N6  0x60 ///< External pin CMP1N.6.                  
#define CPT1MX_CMXN__CMP1N7  0x70 ///< External pin CMP1N.7.                  
#define CPT1MX_CMXN__CMP1N8  0x80 ///< External pin CMP1N.8.                  
#define CPT1MX_CMXN__CMP1N9  0x90 ///< External pin CMP1N.9.                  
#define CPT1MX_CMXN__CMP1N10 0xA0 ///< External pin CMP1N.10.                 
#define CPT1MX_CMXN__CMP1N11 0xB0 ///< External pin CMP1N.11.                 
#define CPT1MX_CMXN__NONE    0xF0 ///< No input selected.                     
                                                                              
//------------------------------------------------------------------------------
// CPT2CN Enums (Comparator 2 Control @ 0x9A)
//------------------------------------------------------------------------------
#define CPT2CN_CPHYN__FMASK                0x03 ///< Comparator Negative Hysteresis Control            
#define CPT2CN_CPHYN__SHIFT                0x00 ///< Comparator Negative Hysteresis Control            
#define CPT2CN_CPHYN__DISABLED             0x00 ///< Disable negative hysteresis.                      
#define CPT2CN_CPHYN__ENABLED_MODE1        0x01 ///< Negative Hysteresis = Hysteresis 1.               
#define CPT2CN_CPHYN__ENABLED_MODE2        0x02 ///< Negative Hysteresis = Hysteresis 2.               
#define CPT2CN_CPHYN__ENABLED_MODE3        0x03 ///< Negative Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                       
#define CPT2CN_CPHYP__FMASK                0x0C ///< Comparator Positive Hysteresis Control            
#define CPT2CN_CPHYP__SHIFT                0x02 ///< Comparator Positive Hysteresis Control            
#define CPT2CN_CPHYP__DISABLED             0x00 ///< Disable positive hysteresis.                      
#define CPT2CN_CPHYP__ENABLED_MODE1        0x04 ///< Positive Hysteresis = Hysteresis 1.               
#define CPT2CN_CPHYP__ENABLED_MODE2        0x08 ///< Positive Hysteresis = Hysteresis 2.               
#define CPT2CN_CPHYP__ENABLED_MODE3        0x0C ///< Positive Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                       
#define CPT2CN_CPFIF__BMASK                0x10 ///< Comparator Falling-Edge Flag                      
#define CPT2CN_CPFIF__SHIFT                0x04 ///< Comparator Falling-Edge Flag                      
#define CPT2CN_CPFIF__NOT_SET              0x00 ///< No comparator falling edge has occurred since this
                                                ///< flag was last cleared.                            
#define CPT2CN_CPFIF__FALLING_EDGE         0x10 ///< Comparator falling edge has occurred.             
                                                                                                       
#define CPT2CN_CPRIF__BMASK                0x20 ///< Comparator Rising-Edge Flag                       
#define CPT2CN_CPRIF__SHIFT                0x05 ///< Comparator Rising-Edge Flag                       
#define CPT2CN_CPRIF__NOT_SET              0x00 ///< No comparator rising edge has occurred since this 
                                                ///< flag was last cleared.                            
#define CPT2CN_CPRIF__RISING_EDGE          0x20 ///< Comparator rising edge has occurred.              
                                                                                                       
#define CPT2CN_CPOUT__BMASK                0x40 ///< Comparator Output State Flag                      
#define CPT2CN_CPOUT__SHIFT                0x06 ///< Comparator Output State Flag                      
#define CPT2CN_CPOUT__POS_LESS_THAN_NEG    0x00 ///< Voltage on CP2P < CP2N.                           
#define CPT2CN_CPOUT__POS_GREATER_THAN_NEG 0x40 ///< Voltage on CP2P > CP2N.                           
                                                                                                       
#define CPT2CN_CPEN__BMASK                 0x80 ///< Comparator Enable                                 
#define CPT2CN_CPEN__SHIFT                 0x07 ///< Comparator Enable                                 
#define CPT2CN_CPEN__DISABLED              0x00 ///< Comparator disabled.                              
#define CPT2CN_CPEN__ENABLED               0x80 ///< Comparator enabled.                               
                                                                                                       
//------------------------------------------------------------------------------
// CPT2MD Enums (Comparator 2 Mode @ 0x9B)
//------------------------------------------------------------------------------
#define CPT2MD_CPMD__FMASK              0x03 ///< Comparator Mode Select                      
#define CPT2MD_CPMD__SHIFT              0x00 ///< Comparator Mode Select                      
#define CPT2MD_CPMD__MODE0              0x00 ///< Mode 0 (Fastest Response Time, Highest Power
                                             ///< Consumption)                                
#define CPT2MD_CPMD__MODE1              0x01 ///< Mode 1                                      
#define CPT2MD_CPMD__MODE2              0x02 ///< Mode 2                                      
#define CPT2MD_CPMD__MODE3              0x03 ///< Mode 3 (Slowest Response Time, Lowest Power 
                                             ///< Consumption)                                
                                                                                              
#define CPT2MD_CPFIE__BMASK             0x10 ///< Comparator Falling-Edge Interrupt Enable    
#define CPT2MD_CPFIE__SHIFT             0x04 ///< Comparator Falling-Edge Interrupt Enable    
#define CPT2MD_CPFIE__FALL_INT_DISABLED 0x00 ///< Comparator falling-edge interrupt disabled. 
#define CPT2MD_CPFIE__FALL_INT_ENABLED  0x10 ///< Comparator falling-edge interrupt enabled.  
                                                                                              
#define CPT2MD_CPRIE__BMASK             0x20 ///< Comparator Rising-Edge Interrupt Enable     
#define CPT2MD_CPRIE__SHIFT             0x05 ///< Comparator Rising-Edge Interrupt Enable     
#define CPT2MD_CPRIE__RISE_INT_DISABLED 0x00 ///< Comparator rising-edge interrupt disabled.  
#define CPT2MD_CPRIE__RISE_INT_ENABLED  0x20 ///< Comparator rising-edge interrupt enabled.   
                                                                                              
//------------------------------------------------------------------------------
// CPT2MX Enums (Comparator 2 Multiplexer Selection @ 0x9C)
//------------------------------------------------------------------------------
#define CPT2MX_CMXP__FMASK   0x0F ///< Comparator Positive Input MUX Selection
#define CPT2MX_CMXP__SHIFT   0x00 ///< Comparator Positive Input MUX Selection
#define CPT2MX_CMXP__CMP2P0  0x00 ///< External pin CMP2P.0.                  
#define CPT2MX_CMXP__CMP2P1  0x01 ///< External pin CMP2P.1.                  
#define CPT2MX_CMXP__CMP2P2  0x02 ///< External pin CMP2P.2.                  
#define CPT2MX_CMXP__CMP2P3  0x03 ///< External pin CMP2P.3.                  
#define CPT2MX_CMXP__CMP2P4  0x04 ///< External pin CMP2P.4.                  
#define CPT2MX_CMXP__CMP2P5  0x05 ///< External pin CMP2P.5.                  
#define CPT2MX_CMXP__CMP2P6  0x06 ///< External pin CMP2P.6.                  
#define CPT2MX_CMXP__CMP2P7  0x07 ///< External pin CMP2P.7.                  
#define CPT2MX_CMXP__CMP2P8  0x08 ///< External pin CMP2P.8.                  
#define CPT2MX_CMXP__CMP2P9  0x09 ///< External pin CMP2P.9.                  
#define CPT2MX_CMXP__CMP2P10 0x0A ///< External pin CMP2P.10.                 
#define CPT2MX_CMXP__CMP2P11 0x0B ///< External pin CMP2P.11.                 
#define CPT2MX_CMXP__NONE    0x0F ///< No input selected.                     
                                                                              
#define CPT2MX_CMXN__FMASK   0xF0 ///< Comparator Negative Input MUX Selection
#define CPT2MX_CMXN__SHIFT   0x04 ///< Comparator Negative Input MUX Selection
#define CPT2MX_CMXN__CMP2N0  0x00 ///< External pin CMP2N.0.                  
#define CPT2MX_CMXN__CMP2N1  0x10 ///< External pin CMP2N.1.                  
#define CPT2MX_CMXN__CMP2N2  0x20 ///< External pin CMP2N.2.                  
#define CPT2MX_CMXN__CMP2N3  0x30 ///< External pin CMP2N.3.                  
#define CPT2MX_CMXN__CMP2N4  0x40 ///< External pin CMP2N.4.                  
#define CPT2MX_CMXN__CMP2N5  0x50 ///< External pin CMP2N.5.                  
#define CPT2MX_CMXN__CMP2N6  0x60 ///< External pin CMP2N.6.                  
#define CPT2MX_CMXN__CMP2N7  0x70 ///< External pin CMP2N.7.                  
#define CPT2MX_CMXN__CMP2N8  0x80 ///< External pin CMP2N.8.                  
#define CPT2MX_CMXN__CMP2N9  0x90 ///< External pin CMP2N.9.                  
#define CPT2MX_CMXN__CMP2N10 0xA0 ///< External pin CMP2N.10.                 
#define CPT2MX_CMXN__CMP2N11 0xB0 ///< External pin CMP2N.11.                 
#define CPT2MX_CMXN__NONE    0xF0 ///< No input selected.                     
                                                                              
//------------------------------------------------------------------------------
// SN0 Enums (Serial Number Byte 0 @ 0xF9)
//------------------------------------------------------------------------------
#define SN0_SERNUM0__FMASK 0xFF ///< Serial Number Byte 0
#define SN0_SERNUM0__SHIFT 0x00 ///< Serial Number Byte 0
                                                         
//------------------------------------------------------------------------------
// SN1 Enums (Serial Number Byte 1 @ 0xFA)
//------------------------------------------------------------------------------
#define SN1_SERNUM1__FMASK 0xFF ///< Serial Number Byte 1
#define SN1_SERNUM1__SHIFT 0x00 ///< Serial Number Byte 1
                                                         
//------------------------------------------------------------------------------
// SN2 Enums (Serial Number Byte 2 @ 0xFB)
//------------------------------------------------------------------------------
#define SN2_SERNUM2__FMASK 0xFF ///< Serial Number Byte 2
#define SN2_SERNUM2__SHIFT 0x00 ///< Serial Number Byte 2
                                                         
//------------------------------------------------------------------------------
// SN3 Enums (Serial Number Byte 3 @ 0xFC)
//------------------------------------------------------------------------------
#define SN3_SERNUM3__FMASK 0xFF ///< Serial Number Byte 3
#define SN3_SERNUM3__SHIFT 0x00 ///< Serial Number Byte 3
                                                         
//------------------------------------------------------------------------------
// IT01CF Enums (INT0/INT1 Configuration @ 0xE4)
//------------------------------------------------------------------------------
#define IT01CF_IN0SL__FMASK       0x07 ///< INT0 Port Pin Selection   
#define IT01CF_IN0SL__SHIFT       0x00 ///< INT0 Port Pin Selection   
#define IT01CF_IN0SL__P1_0        0x00 ///< Select P1.0.              
#define IT01CF_IN0SL__P1_1        0x01 ///< Select P1.1.              
#define IT01CF_IN0SL__P1_2        0x02 ///< Select P1.2.              
#define IT01CF_IN0SL__P1_3        0x03 ///< Select P1.3.              
#define IT01CF_IN0SL__P1_4        0x04 ///< Select P1.4.              
#define IT01CF_IN0SL__P1_5        0x05 ///< Select P1.5.              
#define IT01CF_IN0SL__P1_6        0x06 ///< Select P1.6.              
#define IT01CF_IN0SL__P1_7        0x07 ///< Select P1.7.              
                                                                      
#define IT01CF_IN0PL__BMASK       0x08 ///< INT0 Polarity             
#define IT01CF_IN0PL__SHIFT       0x03 ///< INT0 Polarity             
#define IT01CF_IN0PL__ACTIVE_LOW  0x00 ///< INT0 input is active low. 
#define IT01CF_IN0PL__ACTIVE_HIGH 0x08 ///< INT0 input is active high.
                                                                      
#define IT01CF_IN1SL__FMASK       0x70 ///< INT1 Port Pin Selection   
#define IT01CF_IN1SL__SHIFT       0x04 ///< INT1 Port Pin Selection   
#define IT01CF_IN1SL__P1_0        0x00 ///< Select P1.0.              
#define IT01CF_IN1SL__P1_1        0x10 ///< Select P1.1.              
#define IT01CF_IN1SL__P1_2        0x20 ///< Select P1.2.              
#define IT01CF_IN1SL__P1_3        0x30 ///< Select P1.3.              
#define IT01CF_IN1SL__P1_4        0x40 ///< Select P1.4.              
#define IT01CF_IN1SL__P1_5        0x50 ///< Select P1.5.              
#define IT01CF_IN1SL__P1_6        0x60 ///< Select P1.6.              
#define IT01CF_IN1SL__P1_7        0x70 ///< Select P1.7.              
                                                                      
#define IT01CF_IN1PL__BMASK       0x80 ///< INT1 Polarity             
#define IT01CF_IN1PL__SHIFT       0x07 ///< INT1 Polarity             
#define IT01CF_IN1PL__ACTIVE_LOW  0x00 ///< INT1 input is active low. 
#define IT01CF_IN1PL__ACTIVE_HIGH 0x80 ///< INT1 input is active high.
                                                                      
//------------------------------------------------------------------------------
// OSCXCN Enums (External Oscillator Control @ 0x9F)
//------------------------------------------------------------------------------
#define OSCXCN_XFCN__FMASK           0x07 ///< External Oscillator Frequency Control           
#define OSCXCN_XFCN__SHIFT           0x00 ///< External Oscillator Frequency Control           
#define OSCXCN_XFCN__MODE0           0x00 ///< Select external oscillator mode 0: Crystal      
                                          ///< frequency <= 20 kHz, RC/C frequency <= 25 kHz, C
                                          ///< mode K factor = 0.87.                           
#define OSCXCN_XFCN__MODE1           0x01 ///< Select external oscillator mode 1: 20 kHz <     
                                          ///< Crystal frequency <= 58 kHz, 25 kHz < RC/C      
                                          ///< frequency <= 50 kHz, C mode K factor = 2.6.     
#define OSCXCN_XFCN__MODE2           0x02 ///< Select external oscillator mode 2: 58 kHz <     
                                          ///< Crystal frequency <= 155 kHz, 50 kHz < RC/C     
                                          ///< frequency <= 100 kHz, C mode K factor = 7.7.    
#define OSCXCN_XFCN__MODE3           0x03 ///< Select external oscillator mode 3: 155 kHz <    
                                          ///< Crystal frequency <= 415 kHz, 100 kHz < RC/C    
                                          ///< frequency <= 200 kHz, C mode K factor = 22.     
#define OSCXCN_XFCN__MODE4           0x04 ///< Select external oscillator mode 4: 415 kHz <    
                                          ///< Crystal frequency <= 1.1 MHz, 200 kHz < RC/C    
                                          ///< frequency <= 400 kHz, C mode K factor = 65.     
#define OSCXCN_XFCN__MODE5           0x05 ///< Select external oscillator mode 5: 1.1 MHz <    
                                          ///< Crystal frequency <= 3.1 MHz, 400 kHz < RC/C    
                                          ///< frequency <= 800 kHz, C mode K factor = 180.    
#define OSCXCN_XFCN__MODE6           0x06 ///< Select external oscillator mode 6: 3.1 MHz <    
                                          ///< Crystal frequency <= 8.2 MHz, 800 kHz < RC/C    
                                          ///< frequency <= 1.6 MHz, C mode K factor = 664.    
#define OSCXCN_XFCN__MODE7           0x07 ///< Select external oscillator mode 7: 8.2 MHz <    
                                          ///< Crystal frequency <= 25 MHz, 1.6 MHz < RC/C     
                                          ///< frequency <= 3.2 MHz, C mode K factor = 1590.   
                                                                                               
#define OSCXCN_XOSCMD__FMASK         0x70 ///< External Oscillator Mode                        
#define OSCXCN_XOSCMD__SHIFT         0x04 ///< External Oscillator Mode                        
#define OSCXCN_XOSCMD__DISABLED      0x00 ///< External Oscillator circuit disabled.           
#define OSCXCN_XOSCMD__CMOS          0x20 ///< External CMOS Clock Mode.                       
#define OSCXCN_XOSCMD__CMOS_DIV_2    0x30 ///< External CMOS Clock Mode with divide by 2 stage.
#define OSCXCN_XOSCMD__RC            0x40 ///< RC Oscillator Mode.                             
#define OSCXCN_XOSCMD__C             0x50 ///< Capacitor Oscillator Mode.                      
#define OSCXCN_XOSCMD__CRYSTAL       0x60 ///< Crystal Oscillator Mode.                        
#define OSCXCN_XOSCMD__CRYSTAL_DIV_2 0x70 ///< Crystal Oscillator Mode with divide by 2 stage. 
                                                                                               
#define OSCXCN_XTLVLD__BMASK         0x80 ///< Crystal Oscillator Valid Flag                   
#define OSCXCN_XTLVLD__SHIFT         0x07 ///< Crystal Oscillator Valid Flag                   
#define OSCXCN_XTLVLD__NOT_SET       0x00 ///< External crystal is unused or not yet stable.   
#define OSCXCN_XTLVLD__SET           0x80 ///< External crystal is running and stable.         
                                                                                               
//------------------------------------------------------------------------------
// CCH0CN Enums (Cache Control @ 0xE3)
//------------------------------------------------------------------------------
#define CCH0CN_CHBLKW__BMASK                0x01 ///< Flash Block Write Enable                       
#define CCH0CN_CHBLKW__SHIFT                0x00 ///< Flash Block Write Enable                       
#define CCH0CN_CHBLKW__BLOCK_WRITE_DISABLED 0x00 ///< Each byte of a firmware flash write is written 
                                                 ///< individually.                                  
#define CCH0CN_CHBLKW__BLOCK_WRITE_ENABLED  0x01 ///< Flash bytes are written in groups of two.      
                                                                                                     
#define CCH0CN_CHPFEN__BMASK                0x20 ///< Prefetch Enable                                
#define CCH0CN_CHPFEN__SHIFT                0x05 ///< Prefetch Enable                                
#define CCH0CN_CHPFEN__DISABLED             0x00 ///< Disable the prefetch engine (SYSCLK <= 25 MHz).
#define CCH0CN_CHPFEN__ENABLED              0x20 ///< Enable the prefetch engine (SYSCLK > 25 MHz).  
                                                                                                     
//------------------------------------------------------------------------------
// FLKEY Enums (Flash Lock and Key @ 0xB7)
//------------------------------------------------------------------------------
#define FLKEY_FLKEY__FMASK    0xFF ///< Flash Lock and Key Register                       
#define FLKEY_FLKEY__SHIFT    0x00 ///< Flash Lock and Key Register                       
#define FLKEY_FLKEY__LOCKED   0x00 ///< Flash is write/erase locked.                      
#define FLKEY_FLKEY__FIRST    0x01 ///< The first key code has been written (0xA5).       
#define FLKEY_FLKEY__UNLOCKED 0x02 ///< Flash is unlocked (writes/erases allowed).        
#define FLKEY_FLKEY__DISABLED 0x03 ///< Flash writes/erases disabled until the next reset.
#define FLKEY_FLKEY__KEY1     0xA5 ///< Flash writes and erases are enabled by writing    
                                   ///< 0xA5 followed by 0xF1 to the FLKEY register.      
#define FLKEY_FLKEY__KEY2     0xF1 ///< Flash writes and erases are enabled by writing    
                                   ///< 0xA5 followed by 0xF1 to the FLKEY register.      
                                                                                          
//------------------------------------------------------------------------------
// FLSCL Enums (Flash Scale @ 0xB6)
//------------------------------------------------------------------------------
#define FLSCL_FLEWT__BMASK              0x02 ///< Flash Erase Write Time Control             
#define FLSCL_FLEWT__SHIFT              0x01 ///< Flash Erase Write Time Control             
#define FLSCL_FLEWT__SHORT              0x00 ///< Select short flash erase / write timing.   
#define FLSCL_FLEWT__EXTENDED           0x02 ///< Select extended flash erase / write timing.
                                                                                             
#define FLSCL_FLRT__BMASK               0x10 ///< Flash Read Timing                          
#define FLSCL_FLRT__SHIFT               0x04 ///< Flash Read Timing                          
#define FLSCL_FLRT__SYSCLK_BELOW_25_MHZ 0x00 ///< SYSCLK <= 25 MHz.                          
#define FLSCL_FLRT__SYSCLK_BELOW_48_MHZ 0x10 ///< SYSCLK > 25 MHz.                           
                                                                                             
//------------------------------------------------------------------------------
// ONESHOT Enums (Flash Oneshot Period @ 0xBE)
//------------------------------------------------------------------------------
#define ONESHOT_PERIOD__FMASK 0x0F ///< Oneshot Period Control
#define ONESHOT_PERIOD__SHIFT 0x00 ///< Oneshot Period Control
                                                              
//------------------------------------------------------------------------------
// PSCTL Enums (Program Store Control @ 0x8F)
//------------------------------------------------------------------------------
#define PSCTL_PSWE__BMASK          0x01 ///< Program Store Write Enable                      
#define PSCTL_PSWE__SHIFT          0x00 ///< Program Store Write Enable                      
#define PSCTL_PSWE__WRITE_DISABLED 0x00 ///< Writes to flash program memory disabled.        
#define PSCTL_PSWE__WRITE_ENABLED  0x01 ///< Writes to flash program memory enabled; the MOVX
                                        ///< write instruction targets flash memory.         
                                                                                             
#define PSCTL_PSEE__BMASK          0x02 ///< Program Store Erase Enable                      
#define PSCTL_PSEE__SHIFT          0x01 ///< Program Store Erase Enable                      
#define PSCTL_PSEE__ERASE_DISABLED 0x00 ///< Flash program memory erasure disabled.          
#define PSCTL_PSEE__ERASE_ENABLED  0x02 ///< Flash program memory erasure enabled.           
                                                                                             
//------------------------------------------------------------------------------
// OSCICN Enums (High Frequency Oscillator Control @ 0xA1)
//------------------------------------------------------------------------------
#define OSCICN_IFCN__FMASK         0x07 ///< Oscillator Frequency Divider Control             
#define OSCICN_IFCN__SHIFT         0x00 ///< Oscillator Frequency Divider Control             
#define OSCICN_IFCN__HFOSC_DIV_128 0x00 ///< SYSCLK derived from High Frequency Oscillator    
                                        ///< divided by 128.                                  
#define OSCICN_IFCN__HFOSC_DIV_64  0x01 ///< SYSCLK derived from High Frequency Oscillator    
                                        ///< divided by 64.                                   
#define OSCICN_IFCN__HFOSC_DIV_32  0x02 ///< SYSCLK derived from High Frequency Oscillator    
                                        ///< divided by 32.                                   
#define OSCICN_IFCN__HFOSC_DIV_16  0x03 ///< SYSCLK derived from High Frequency Oscillator    
                                        ///< divided by 16.                                   
#define OSCICN_IFCN__HFOSC_DIV_8   0x04 ///< SYSCLK derived from High Frequency Oscillator    
                                        ///< divided by 8.                                    
#define OSCICN_IFCN__HFOSC_DIV_4   0x05 ///< SYSCLK derived from High Frequency Oscillator    
                                        ///< divided by 4.                                    
#define OSCICN_IFCN__HFOSC_DIV_2   0x06 ///< SYSCLK derived from High Frequency Oscillator    
                                        ///< divided by 2.                                    
#define OSCICN_IFCN__HFOSC_DIV_1   0x07 ///< SYSCLK derived from High Frequency Oscillator    
                                        ///< divided by 1.                                    
                                                                                              
#define OSCICN_IFRDY__BMASK        0x10 ///< Oscillator Frequency Ready Flag                  
#define OSCICN_IFRDY__SHIFT        0x04 ///< Oscillator Frequency Ready Flag                  
#define OSCICN_IFRDY__NOT_SET      0x00 ///< The Internal High Frequency Oscillator is not    
                                        ///< running at the programmed frequency.             
#define OSCICN_IFRDY__SET          0x10 ///< The Internal High Frequency Oscillator is running
                                        ///< at the programmed frequency.                     
                                                                                              
#define OSCICN_SUSPEND__BMASK      0x20 ///< Oscillator Suspend Enable                        
#define OSCICN_SUSPEND__SHIFT      0x05 ///< Oscillator Suspend Enable                        
#define OSCICN_SUSPEND__DISABLED   0x00 ///< The internal oscillator is not in suspend mode.  
#define OSCICN_SUSPEND__ENABLED    0x20 ///< Place the internal oscillator in suspend mode.   
                                                                                              
#define OSCICN_IOSCEN__FMASK       0xC0 ///< Oscillator Enable                                
#define OSCICN_IOSCEN__SHIFT       0x06 ///< Oscillator Enable                                
#define OSCICN_IOSCEN__DISABLED    0x00 ///< Disable the High Frequency Oscillator.           
#define OSCICN_IOSCEN__ENABLED     0xC0 ///< Oscillator enabled in normal mode and disabled in
                                        ///< Suspend mode.                                    
                                                                                              
//------------------------------------------------------------------------------
// OSCICRS Enums (High Frequency Oscillator Coarse Calibration @ 0xA2)
//------------------------------------------------------------------------------
#define OSCICRS_OSCICRS__FMASK 0x7F ///< Internal Oscillator Coarse Calibration
#define OSCICRS_OSCICRS__SHIFT 0x00 ///< Internal Oscillator Coarse Calibration
                                                                               
//------------------------------------------------------------------------------
// OSCIFIN Enums (High Frequency Oscillator Fine Calibration @ 0x9E)
//------------------------------------------------------------------------------
#define OSCIFIN_OSCIFIN__FMASK 0x3F ///< Internal Oscillator Fine Calibration
#define OSCIFIN_OSCIFIN__SHIFT 0x00 ///< Internal Oscillator Fine Calibration
                                                                             
//------------------------------------------------------------------------------
// EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
//------------------------------------------------------------------------------
#define EIE1_ESMB0__BMASK     0x01 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__SHIFT     0x00 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__DISABLED  0x00 ///< Disable all SMB0 interrupts.                      
#define EIE1_ESMB0__ENABLED   0x01 ///< Enable interrupt requests generated by SMB0.      
                                                                                          
#define EIE1_EWADC0__BMASK    0x02 ///< Window Comparison ADC0 Interrupt Enable           
#define EIE1_EWADC0__SHIFT    0x01 ///< Window Comparison ADC0 Interrupt Enable           
#define EIE1_EWADC0__DISABLED 0x00 ///< Disable ADC0 Window Comparison interrupt.         
#define EIE1_EWADC0__ENABLED  0x02 ///< Enable interrupt requests generated by ADC0 Window
                                   ///< Compare flag (ADWINT).                            
                                                                                          
#define EIE1_EADC0__BMASK     0x04 ///< ADC0 Conversion Complete Interrupt Enable         
#define EIE1_EADC0__SHIFT     0x02 ///< ADC0 Conversion Complete Interrupt Enable         
#define EIE1_EADC0__DISABLED  0x00 ///< Disable ADC0 Conversion Complete interrupt.       
#define EIE1_EADC0__ENABLED   0x04 ///< Enable interrupt requests generated by the ADINT  
                                   ///< flag.                                             
                                                                                          
#define EIE1_EPCA0__BMASK     0x08 ///< Programmable Counter Array (PCA0) Interrupt Enable
#define EIE1_EPCA0__SHIFT     0x03 ///< Programmable Counter Array (PCA0) Interrupt Enable
#define EIE1_EPCA0__DISABLED  0x00 ///< Disable all PCA0 interrupts.                      
#define EIE1_EPCA0__ENABLED   0x08 ///< Enable interrupt requests generated by PCA0.      
                                                                                          
#define EIE1_ECP0__BMASK      0x10 ///< Comparator0 (CP0) Interrupt Enable                
#define EIE1_ECP0__SHIFT      0x04 ///< Comparator0 (CP0) Interrupt Enable                
#define EIE1_ECP0__DISABLED   0x00 ///< Disable CP0 interrupts.                           
#define EIE1_ECP0__ENABLED    0x10 ///< Enable interrupt requests generated by the        
                                   ///< comparator 0 CPRIF or CPFIF flags.                
                                                                                          
#define EIE1_ECP1__BMASK      0x20 ///< Comparator1 (CP1) Interrupt Enable                
#define EIE1_ECP1__SHIFT      0x05 ///< Comparator1 (CP1) Interrupt Enable                
#define EIE1_ECP1__DISABLED   0x00 ///< Disable CP1 interrupts.                           
#define EIE1_ECP1__ENABLED    0x20 ///< Enable interrupt requests generated by the        
                                   ///< comparator 1 CPRIF or CPFIF flags.                
                                                                                          
#define EIE1_ET3__BMASK       0x40 ///< Timer 3 Interrupt Enable                          
#define EIE1_ET3__SHIFT       0x06 ///< Timer 3 Interrupt Enable                          
#define EIE1_ET3__DISABLED    0x00 ///< Disable Timer 3 interrupts.                       
#define EIE1_ET3__ENABLED     0x40 ///< Enable interrupt requests generated by the TF3L or
                                   ///< TF3H flags.                                       
                                                                                          
#define EIE1_ELIN0__BMASK     0x80 ///< LIN0 Interrupt Enable                             
#define EIE1_ELIN0__SHIFT     0x07 ///< LIN0 Interrupt Enable                             
#define EIE1_ELIN0__DISABLED  0x00 ///< Disable LIN0 interrupts.                          
#define EIE1_ELIN0__ENABLED   0x80 ///< Enable interrupt requests generated by LIN0.      
                                                                                          
//------------------------------------------------------------------------------
// EIE2 Enums (Extended Interrupt Enable 2 @ 0xE7)
//------------------------------------------------------------------------------
#define EIE2_EREG0__BMASK    0x01 ///< Voltage Regulator Interrupt Enable                
#define EIE2_EREG0__SHIFT    0x00 ///< Voltage Regulator Interrupt Enable                
#define EIE2_EREG0__DISABLED 0x00 ///< Disable the voltage regulator dropout interrupt.  
#define EIE2_EREG0__ENABLED  0x01 ///< Enable the voltage regulator dropout interrupt.   
                                                                                         
#define EIE2_ECAN0__BMASK    0x02 ///< CAN0 Interrupt Enable                             
#define EIE2_ECAN0__SHIFT    0x01 ///< CAN0 Interrupt Enable                             
#define EIE2_ECAN0__DISABLED 0x00 ///< Disable CAN0 interrupts.                          
#define EIE2_ECAN0__ENABLED  0x02 ///< Enable interrupt requests generated by CAN0.      
                                                                                         
#define EIE2_EMAT__BMASK     0x04 ///< Port Match Interrupts Enable                      
#define EIE2_EMAT__SHIFT     0x02 ///< Port Match Interrupts Enable                      
#define EIE2_EMAT__DISABLED  0x00 ///< Disable all Port Match interrupts.                
#define EIE2_EMAT__ENABLED   0x04 ///< Enable interrupt requests generated by a Port     
                                  ///< Match.                                            
                                                                                         
#define EIE2_ES1__BMASK      0x08 ///< UART1 Interrupt Enable                            
#define EIE2_ES1__SHIFT      0x03 ///< UART1 Interrupt Enable                            
#define EIE2_ES1__DISABLED   0x00 ///< Disable UART1 interrupt.                          
#define EIE2_ES1__ENABLED    0x08 ///< Enable UART1 interrupt.                           
                                                                                         
#define EIE2_EPCA1__BMASK    0x10 ///< Programmable Counter Array (PCA1) Interrupt Enable
#define EIE2_EPCA1__SHIFT    0x04 ///< Programmable Counter Array (PCA1) Interrupt Enable
#define EIE2_EPCA1__DISABLED 0x00 ///< Disable all PCA1 interrupts.                      
#define EIE2_EPCA1__ENABLED  0x10 ///< Enable interrupt requests generated by PCA1.      
                                                                                         
#define EIE2_ECP2__BMASK     0x20 ///< Comparator2 (CP2) Interrupt Enable                
#define EIE2_ECP2__SHIFT     0x05 ///< Comparator2 (CP2) Interrupt Enable                
#define EIE2_ECP2__DISABLED  0x00 ///< Disable CP2 interrupts.                           
#define EIE2_ECP2__ENABLED   0x20 ///< Enable interrupt requests generated by the        
                                  ///< comparator 2 CPRIF or CPFIF flags.                
                                                                                         
#define EIE2_ET4__BMASK      0x40 ///< Timer 4 Interrupt Enable                          
#define EIE2_ET4__SHIFT      0x06 ///< Timer 4 Interrupt Enable                          
#define EIE2_ET4__DISABLED   0x00 ///< Disable Timer 4 interrupt.                        
#define EIE2_ET4__ENABLED    0x40 ///< Enable interrupt requests generated by the TF4L or
                                  ///< TF4H flags.                                       
                                                                                         
#define EIE2_ET5__BMASK      0x80 ///< Timer 5 Interrupt Enable                          
#define EIE2_ET5__SHIFT      0x07 ///< Timer 5 Interrupt Enable                          
#define EIE2_ET5__DISABLED   0x00 ///< Disable Timer 5 interrupt.                        
#define EIE2_ET5__ENABLED    0x80 ///< Enable interrupt requests generated by the TF5L or
                                  ///< TF5H flags.                                       
                                                                                         
//------------------------------------------------------------------------------
// EIP1 Enums (Extended Interrupt Priority 1 @ 0xF6)
//------------------------------------------------------------------------------
#define EIP1_PSMB0__BMASK  0x01 ///< SMBus (SMB0) Interrupt Priority Control                     
#define EIP1_PSMB0__SHIFT  0x00 ///< SMBus (SMB0) Interrupt Priority Control                     
#define EIP1_PSMB0__LOW    0x00 ///< SMB0 interrupt set to low priority level.                   
#define EIP1_PSMB0__HIGH   0x01 ///< SMB0 interrupt set to high priority level.                  
                                                                                                 
#define EIP1_PWADC0__BMASK 0x02 ///< ADC0 Window Comparator Interrupt Priority Control           
#define EIP1_PWADC0__SHIFT 0x01 ///< ADC0 Window Comparator Interrupt Priority Control           
#define EIP1_PWADC0__LOW   0x00 ///< ADC0 Window interrupt set to low priority level.            
#define EIP1_PWADC0__HIGH  0x02 ///< ADC0 Window interrupt set to high priority level.           
                                                                                                 
#define EIP1_PADC0__BMASK  0x04 ///< ADC0 Conversion Complete Interrupt Priority Control         
#define EIP1_PADC0__SHIFT  0x02 ///< ADC0 Conversion Complete Interrupt Priority Control         
#define EIP1_PADC0__LOW    0x00 ///< ADC0 Conversion Complete interrupt set to low               
                                ///< priority level.                                             
#define EIP1_PADC0__HIGH   0x04 ///< ADC0 Conversion Complete interrupt set to high              
                                ///< priority level.                                             
                                                                                                 
#define EIP1_PPCA0__BMASK  0x08 ///< Programmable Counter Array (PCA0) Interrupt Priority Control
#define EIP1_PPCA0__SHIFT  0x03 ///< Programmable Counter Array (PCA0) Interrupt Priority Control
#define EIP1_PPCA0__LOW    0x00 ///< PCA0 interrupt set to low priority level.                   
#define EIP1_PPCA0__HIGH   0x08 ///< PCA0 interrupt set to high priority level.                  
                                                                                                 
#define EIP1_PCP0__BMASK   0x10 ///< Comparator0 (CP0) Interrupt Priority Control                
#define EIP1_PCP0__SHIFT   0x04 ///< Comparator0 (CP0) Interrupt Priority Control                
#define EIP1_PCP0__LOW     0x00 ///< CP0 interrupt set to low priority level.                    
#define EIP1_PCP0__HIGH    0x10 ///< CP0 interrupt set to high priority level.                   
                                                                                                 
#define EIP1_PCP1__BMASK   0x20 ///< Comparator1 (CP1) Interrupt Priority Control                
#define EIP1_PCP1__SHIFT   0x05 ///< Comparator1 (CP1) Interrupt Priority Control                
#define EIP1_PCP1__LOW     0x00 ///< CP1 interrupt set to low priority level.                    
#define EIP1_PCP1__HIGH    0x20 ///< CP1 interrupt set to high priority level.                   
                                                                                                 
#define EIP1_PT3__BMASK    0x40 ///< Timer 3 Interrupt Priority Control                          
#define EIP1_PT3__SHIFT    0x06 ///< Timer 3 Interrupt Priority Control                          
#define EIP1_PT3__LOW      0x00 ///< Timer 3 interrupts set to low priority level.               
#define EIP1_PT3__HIGH     0x40 ///< Timer 3 interrupts set to high priority level.              
                                                                                                 
#define EIP1_PLIN0__BMASK  0x80 ///< LIN0 Interrupt Priority Control                             
#define EIP1_PLIN0__SHIFT  0x07 ///< LIN0 Interrupt Priority Control                             
#define EIP1_PLIN0__LOW    0x00 ///< LIN0 interrupts set to low priority level.                  
#define EIP1_PLIN0__HIGH   0x80 ///< LIN0 interrupts set to high priority level.                 
                                                                                                 
//------------------------------------------------------------------------------
// EIP2 Enums (Extended Interrupt Priority 2 @ 0xF7)
//------------------------------------------------------------------------------
#define EIP2_PREG0__BMASK 0x01 ///< Voltage Regulator Interrupt Priority Control                
#define EIP2_PREG0__SHIFT 0x00 ///< Voltage Regulator Interrupt Priority Control                
#define EIP2_PREG0__LOW   0x00 ///< Voltage regulator dropout interrupts set to low             
                               ///< priority level.                                             
#define EIP2_PREG0__HIGH  0x01 ///< Voltage regulator dropout interrupts set to high            
                               ///< priority level.                                             
                                                                                                
#define EIP2_PCAN0__BMASK 0x02 ///< CAN0 Interrupt Priority Control                             
#define EIP2_PCAN0__SHIFT 0x01 ///< CAN0 Interrupt Priority Control                             
#define EIP2_PCAN0__LOW   0x00 ///< CAN0 interrupts set to low priority level.                  
#define EIP2_PCAN0__HIGH  0x02 ///< CAN0 interrupts set to high priority level.                 
                                                                                                
#define EIP2_PMAT__BMASK  0x04 ///< Port Match Interrupt Priority Control                       
#define EIP2_PMAT__SHIFT  0x02 ///< Port Match Interrupt Priority Control                       
#define EIP2_PMAT__LOW    0x00 ///< Port Match interrupt set to low priority level.             
#define EIP2_PMAT__HIGH   0x04 ///< Port Match interrupt set to high priority level.            
                                                                                                
#define EIP2_PS1__BMASK   0x08 ///< UART1 Interrupt Priority Control                            
#define EIP2_PS1__SHIFT   0x03 ///< UART1 Interrupt Priority Control                            
#define EIP2_PS1__LOW     0x00 ///< UART1 interrupt set to low priority level.                  
#define EIP2_PS1__HIGH    0x08 ///< UART1 interrupt set to high priority level.                 
                                                                                                
#define EIP2_PPCA1__BMASK 0x10 ///< Programmable Counter Array (PCA1) Interrupt Priority Control
#define EIP2_PPCA1__SHIFT 0x04 ///< Programmable Counter Array (PCA1) Interrupt Priority Control
#define EIP2_PPCA1__LOW   0x00 ///< PCA1 interrupt set to low priority level.                   
#define EIP2_PPCA1__HIGH  0x10 ///< PCA1 interrupt set to high priority level.                  
                                                                                                
#define EIP2_PCP2__BMASK  0x20 ///< Comparator2 (CP2) Interrupt Priority Control                
#define EIP2_PCP2__SHIFT  0x05 ///< Comparator2 (CP2) Interrupt Priority Control                
#define EIP2_PCP2__LOW    0x00 ///< CP2 interrupt set to low priority level.                    
#define EIP2_PCP2__HIGH   0x20 ///< CP2 interrupt set to high priority level.                   
                                                                                                
#define EIP2_PT4__BMASK   0x40 ///< Timer 4 Interrupt Priority Control                          
#define EIP2_PT4__SHIFT   0x06 ///< Timer 4 Interrupt Priority Control                          
#define EIP2_PT4__LOW     0x00 ///< Timer 4 interrupt set to low priority level.                
#define EIP2_PT4__HIGH    0x40 ///< Timer 4 interrupt set to high priority level.               
                                                                                                
#define EIP2_PT5__BMASK   0x80 ///< Timer 5 Interrupt Priority Control                          
#define EIP2_PT5__SHIFT   0x07 ///< Timer 5 Interrupt Priority Control                          
#define EIP2_PT5__LOW     0x00 ///< Timer 5 interrupt set to low priority level.                
#define EIP2_PT5__HIGH    0x80 ///< Timer 5 interrupt set to high priority level.               
                                                                                                
//------------------------------------------------------------------------------
// IE Enums (Interrupt Enable @ 0xA8)
//------------------------------------------------------------------------------
#define IE_EX0__BMASK      0x01 ///< External Interrupt 0 Enable                       
#define IE_EX0__SHIFT      0x00 ///< External Interrupt 0 Enable                       
#define IE_EX0__DISABLED   0x00 ///< Disable external interrupt 0.                     
#define IE_EX0__ENABLED    0x01 ///< Enable interrupt requests generated by the /INT0  
                                ///< input.                                            
                                                                                       
#define IE_ET0__BMASK      0x02 ///< Timer 0 Interrupt Enable                          
#define IE_ET0__SHIFT      0x01 ///< Timer 0 Interrupt Enable                          
#define IE_ET0__DISABLED   0x00 ///< Disable all Timer 0 interrupt.                    
#define IE_ET0__ENABLED    0x02 ///< Enable interrupt requests generated by the TF0    
                                ///< flag.                                             
                                                                                       
#define IE_EX1__BMASK      0x04 ///< External Interrupt 1 Enable                       
#define IE_EX1__SHIFT      0x02 ///< External Interrupt 1 Enable                       
#define IE_EX1__DISABLED   0x00 ///< Disable external interrupt 1.                     
#define IE_EX1__ENABLED    0x04 ///< Enable interrupt requests generated by the /INT1  
                                ///< input.                                            
                                                                                       
#define IE_ET1__BMASK      0x08 ///< Timer 1 Interrupt Enable                          
#define IE_ET1__SHIFT      0x03 ///< Timer 1 Interrupt Enable                          
#define IE_ET1__DISABLED   0x00 ///< Disable all Timer 1 interrupt.                    
#define IE_ET1__ENABLED    0x08 ///< Enable interrupt requests generated by the TF1    
                                ///< flag.                                             
                                                                                       
#define IE_ES0__BMASK      0x10 ///< UART0 Interrupt Enable                            
#define IE_ES0__SHIFT      0x04 ///< UART0 Interrupt Enable                            
#define IE_ES0__DISABLED   0x00 ///< Disable UART0 interrupt.                          
#define IE_ES0__ENABLED    0x10 ///< Enable UART0 interrupt.                           
                                                                                       
#define IE_ET2__BMASK      0x20 ///< Timer 2 Interrupt Enable                          
#define IE_ET2__SHIFT      0x05 ///< Timer 2 Interrupt Enable                          
#define IE_ET2__DISABLED   0x00 ///< Disable Timer 2 interrupt.                        
#define IE_ET2__ENABLED    0x20 ///< Enable interrupt requests generated by the TF2L or
                                ///< TF2H flags.                                       
                                                                                       
#define IE_ESPI0__BMASK    0x40 ///< SPI0 Interrupt Enable                             
#define IE_ESPI0__SHIFT    0x06 ///< SPI0 Interrupt Enable                             
#define IE_ESPI0__DISABLED 0x00 ///< Disable all SPI0 interrupts.                      
#define IE_ESPI0__ENABLED  0x40 ///< Enable interrupt requests generated by SPI0.      
                                                                                       
#define IE_EA__BMASK       0x80 ///< All Interrupts Enable                             
#define IE_EA__SHIFT       0x07 ///< All Interrupts Enable                             
#define IE_EA__DISABLED    0x00 ///< Disable all interrupt sources.                    
#define IE_EA__ENABLED     0x80 ///< Enable each interrupt according to its individual 
                                ///< mask setting.                                     
                                                                                       
//------------------------------------------------------------------------------
// IP Enums (Interrupt Priority @ 0xB8)
//------------------------------------------------------------------------------
#define IP_PX0__BMASK   0x01 ///< External Interrupt 0 Priority Control                        
#define IP_PX0__SHIFT   0x00 ///< External Interrupt 0 Priority Control                        
#define IP_PX0__LOW     0x00 ///< External Interrupt 0 set to low priority level.              
#define IP_PX0__HIGH    0x01 ///< External Interrupt 0 set to high priority level.             
                                                                                               
#define IP_PT0__BMASK   0x02 ///< Timer 0 Interrupt Priority Control                           
#define IP_PT0__SHIFT   0x01 ///< Timer 0 Interrupt Priority Control                           
#define IP_PT0__LOW     0x00 ///< Timer 0 interrupt set to low priority level.                 
#define IP_PT0__HIGH    0x02 ///< Timer 0 interrupt set to high priority level.                
                                                                                               
#define IP_PX1__BMASK   0x04 ///< External Interrupt 1 Priority Control                        
#define IP_PX1__SHIFT   0x02 ///< External Interrupt 1 Priority Control                        
#define IP_PX1__LOW     0x00 ///< External Interrupt 1 set to low priority level.              
#define IP_PX1__HIGH    0x04 ///< External Interrupt 1 set to high priority level.             
                                                                                               
#define IP_PT1__BMASK   0x08 ///< Timer 1 Interrupt Priority Control                           
#define IP_PT1__SHIFT   0x03 ///< Timer 1 Interrupt Priority Control                           
#define IP_PT1__LOW     0x00 ///< Timer 1 interrupt set to low priority level.                 
#define IP_PT1__HIGH    0x08 ///< Timer 1 interrupt set to high priority level.                
                                                                                               
#define IP_PS0__BMASK   0x10 ///< UART0 Interrupt Priority Control                             
#define IP_PS0__SHIFT   0x04 ///< UART0 Interrupt Priority Control                             
#define IP_PS0__LOW     0x00 ///< UART0 interrupt set to low priority level.                   
#define IP_PS0__HIGH    0x10 ///< UART0 interrupt set to high priority level.                  
                                                                                               
#define IP_PT2__BMASK   0x20 ///< Timer 2 Interrupt Priority Control                           
#define IP_PT2__SHIFT   0x05 ///< Timer 2 Interrupt Priority Control                           
#define IP_PT2__LOW     0x00 ///< Timer 2 interrupt set to low priority level.                 
#define IP_PT2__HIGH    0x20 ///< Timer 2 interrupt set to high priority level.                
                                                                                               
#define IP_PSPI0__BMASK 0x40 ///< Serial Peripheral Interface (SPI0) Interrupt Priority Control
#define IP_PSPI0__SHIFT 0x06 ///< Serial Peripheral Interface (SPI0) Interrupt Priority Control
#define IP_PSPI0__LOW   0x00 ///< SPI0 interrupt set to low priority level.                    
#define IP_PSPI0__HIGH  0x40 ///< SPI0 interrupt set to high priority level.                   
                                                                                               
//------------------------------------------------------------------------------
// LIN0ADR Enums (LIN0 Indirect Address @ 0xD3)
//------------------------------------------------------------------------------
#define LIN0ADR_LINADDR__FMASK    0xFF ///< Indirect Address                      
#define LIN0ADR_LINADDR__SHIFT    0x00 ///< Indirect Address                      
#define LIN0ADR_LINADDR__LIN0DT1  0x00 ///< Select the LIN0DT1 internal register. 
#define LIN0ADR_LINADDR__LIN0DT2  0x01 ///< Select the LIN0DT2 internal register. 
#define LIN0ADR_LINADDR__LIN0DT3  0x02 ///< Select the LIN0DT3 internal register. 
#define LIN0ADR_LINADDR__LIN0DT4  0x03 ///< Select the LIN0DT4 internal register. 
#define LIN0ADR_LINADDR__LIN0DT5  0x04 ///< Select the LIN0DT5 internal register. 
#define LIN0ADR_LINADDR__LIN0DT6  0x05 ///< Select the LIN0DT6 internal register. 
#define LIN0ADR_LINADDR__LIN0DT7  0x06 ///< Select the LIN0DT7 internal register. 
#define LIN0ADR_LINADDR__LIN0DT8  0x07 ///< Select the LIN0DT8 internal register. 
#define LIN0ADR_LINADDR__LIN0CTRL 0x08 ///< Select the LIN0CTRL internal register.
#define LIN0ADR_LINADDR__LIN0ST   0x09 ///< Select the LIN0ST internal register.  
#define LIN0ADR_LINADDR__LIN0ERR  0x0A ///< Select the LIN0ERR internal register. 
#define LIN0ADR_LINADDR__LIN0SIZE 0x0B ///< Select the LIN0SIZE internal register.
#define LIN0ADR_LINADDR__LIN0DIV  0x0C ///< Select the LIN0DIV internal register. 
#define LIN0ADR_LINADDR__LIN0MUL  0x0D ///< Select the LIN0MUL internal register. 
#define LIN0ADR_LINADDR__LIN0ID   0x0E ///< Select the LIN0ID internal register.  
                                                                                  
//------------------------------------------------------------------------------
// LIN0CF Enums (LIN0 Control Mode @ 0xC9)
//------------------------------------------------------------------------------
#define LIN0CF_ABAUD__BMASK    0x20 ///< Automatic Baud Rate Enable                
#define LIN0CF_ABAUD__SHIFT    0x05 ///< Automatic Baud Rate Enable                
#define LIN0CF_ABAUD__DISABLED 0x00 ///< Disable auto-baud and use manual baud rate
                                    ///< selection.                                
#define LIN0CF_ABAUD__ENABLED  0x20 ///< Enable auto-baud.                         
                                                                                   
#define LIN0CF_MODE__BMASK     0x40 ///< Mode Selection                            
#define LIN0CF_MODE__SHIFT     0x06 ///< Mode Selection                            
#define LIN0CF_MODE__SLAVE     0x00 ///< LIN0 operates in slave mode.              
#define LIN0CF_MODE__MASTER    0x40 ///< LIN0 operates in master mode.             
                                                                                   
#define LIN0CF_LINEN__BMASK    0x80 ///< Interface Enable                          
#define LIN0CF_LINEN__SHIFT    0x07 ///< Interface Enable                          
#define LIN0CF_LINEN__DISABLED 0x00 ///< Disable the LIN0 module.                  
#define LIN0CF_LINEN__ENABLED  0x80 ///< Enable the LIN0 module.                   
                                                                                   
//------------------------------------------------------------------------------
// LIN0CTRL Enums (LIN0 Control @ 0x08)
//------------------------------------------------------------------------------
#define LIN0CTRL_STREQ__BMASK   0x01 ///< Start Request                                     
#define LIN0CTRL_STREQ__SHIFT   0x00 ///< Start Request                                     
#define LIN0CTRL_STREQ__START   0x01 ///< Start a LIN transmission. Firmware should set this
                                     ///< bit after loading the identifier, data length, and
                                     ///< data buffer, if necessary.                        
                                                                                            
#define LIN0CTRL_WUPREQ__BMASK  0x02 ///< Wake-Up Request                                   
#define LIN0CTRL_WUPREQ__SHIFT  0x01 ///< Wake-Up Request                                   
#define LIN0CTRL_WUPREQ__WAKEUP 0x02 ///< Terminate sleep mode by sending a wakeup signal.  
                                                                                            
#define LIN0CTRL_RSTERR__BMASK  0x04 ///< Error Reset                                       
#define LIN0CTRL_RSTERR__SHIFT  0x02 ///< Error Reset                                       
#define LIN0CTRL_RSTERR__RESET  0x04 ///< Clear the error bits in the LIN0ST and LIN0ERR    
                                     ///< registers.                                        
                                                                                            
#define LIN0CTRL_RSTINT__BMASK  0x08 ///< Interrupt Reset                                   
#define LIN0CTRL_RSTINT__SHIFT  0x03 ///< Interrupt Reset                                   
#define LIN0CTRL_RSTINT__RESET  0x08 ///< Clear the LININT interrupt flag.                  
                                                                                            
#define LIN0CTRL_DTACK__BMASK   0x10 ///< Data Acknowledge                                  
#define LIN0CTRL_DTACK__SHIFT   0x04 ///< Data Acknowledge                                  
#define LIN0CTRL_DTACK__ACK     0x10 ///< Acknowledge the transfer after a data request     
                                     ///< interrupt.                                        
                                                                                            
#define LIN0CTRL_TXRX__BMASK    0x20 ///< Transmit/Receive Selection                        
#define LIN0CTRL_TXRX__SHIFT    0x05 ///< Transmit/Receive Selection                        
#define LIN0CTRL_TXRX__RECEIVE  0x00 ///< The current frame is a receive operation.         
#define LIN0CTRL_TXRX__TRANSMIT 0x20 ///< The current frame is a transmit operation.        
                                                                                            
#define LIN0CTRL_SLEEP__BMASK   0x40 ///< Sleep Mode Warning                                
#define LIN0CTRL_SLEEP__SHIFT   0x06 ///< Sleep Mode Warning                                
#define LIN0CTRL_SLEEP__CLEAR   0x00 ///< Clear the sleep mode warning.                     
#define LIN0CTRL_SLEEP__WARN    0x40 ///< A sleep mode frame or bus idle timeout was        
                                     ///< received.                                         
                                                                                            
#define LIN0CTRL_STOP__BMASK    0x80 ///< Stop Communication Processing                     
#define LIN0CTRL_STOP__SHIFT    0x07 ///< Stop Communication Processing                     
#define LIN0CTRL_STOP__STOP     0x80 ///< Block the processing of the LIN0 communications   
                                     ///< until the next SYNCH BREAK.                       
                                                                                            
//------------------------------------------------------------------------------
// LIN0DAT Enums (LIN0 Indirect Data @ 0xD2)
//------------------------------------------------------------------------------
#define LIN0DAT_LINDATA__FMASK 0xFF ///< Indirect Data
#define LIN0DAT_LINDATA__SHIFT 0x00 ///< Indirect Data
                                                      
//------------------------------------------------------------------------------
// LIN0DIV Enums (LIN0 Divider @ 0x0C)
//------------------------------------------------------------------------------
#define LIN0DIV_LINDIV__FMASK 0xFF ///< Baud Rate Divider Low Byte
#define LIN0DIV_LINDIV__SHIFT 0x00 ///< Baud Rate Divider Low Byte
                                                                  
//------------------------------------------------------------------------------
// LIN0DT1 Enums (LIN0 Data Byte 1 @ 0x00)
//------------------------------------------------------------------------------
#define LIN0DT1_LIN0DT1__FMASK 0xFF ///< Data Byte 1
#define LIN0DT1_LIN0DT1__SHIFT 0x00 ///< Data Byte 1
                                                    
//------------------------------------------------------------------------------
// LIN0DT2 Enums (LIN0 Data Byte 2 @ 0x01)
//------------------------------------------------------------------------------
#define LIN0DT2_LIN0DT2__FMASK 0xFF ///< Data Byte 2
#define LIN0DT2_LIN0DT2__SHIFT 0x00 ///< Data Byte 2
                                                    
//------------------------------------------------------------------------------
// LIN0DT3 Enums (LIN0 Data Byte 3 @ 0x02)
//------------------------------------------------------------------------------
#define LIN0DT3_LIN0DT3__FMASK 0xFF ///< Data Byte 3
#define LIN0DT3_LIN0DT3__SHIFT 0x00 ///< Data Byte 3
                                                    
//------------------------------------------------------------------------------
// LIN0DT4 Enums (LIN0 Data Byte 4 @ 0x03)
//------------------------------------------------------------------------------
#define LIN0DT4_LIN0DT4__FMASK 0xFF ///< Data Byte 4
#define LIN0DT4_LIN0DT4__SHIFT 0x00 ///< Data Byte 4
                                                    
//------------------------------------------------------------------------------
// LIN0DT5 Enums (LIN0 Data Byte 5 @ 0x04)
//------------------------------------------------------------------------------
#define LIN0DT5_LIN0DT5__FMASK 0xFF ///< Data Byte 5
#define LIN0DT5_LIN0DT5__SHIFT 0x00 ///< Data Byte 5
                                                    
//------------------------------------------------------------------------------
// LIN0DT6 Enums (LIN0 Data Byte 6 @ 0x05)
//------------------------------------------------------------------------------
#define LIN0DT6_LIN0DT6__FMASK 0xFF ///< Data Byte 6
#define LIN0DT6_LIN0DT6__SHIFT 0x00 ///< Data Byte 6
                                                    
//------------------------------------------------------------------------------
// LIN0DT7 Enums (LIN0 Data Byte 7 @ 0x06)
//------------------------------------------------------------------------------
#define LIN0DT7_LIN0DT7__FMASK 0xFF ///< Data Byte 7
#define LIN0DT7_LIN0DT7__SHIFT 0x00 ///< Data Byte 7
                                                    
//------------------------------------------------------------------------------
// LIN0DT8 Enums (LIN0 Data Byte 8 @ 0x07)
//------------------------------------------------------------------------------
#define LIN0DT8_LIN0DT8__FMASK 0xFF ///< Data Byte 8
#define LIN0DT8_LIN0DT8__SHIFT 0x00 ///< Data Byte 8
                                                    
//------------------------------------------------------------------------------
// LIN0ERR Enums (LIN0 Error @ 0x0A)
//------------------------------------------------------------------------------
#define LIN0ERR_BITERR__BMASK   0x01 ///< Bit Transmission Error Flag                     
#define LIN0ERR_BITERR__SHIFT   0x00 ///< Bit Transmission Error Flag                     
#define LIN0ERR_BITERR__NOT_SET 0x00 ///< No error in transmission has been detected.     
#define LIN0ERR_BITERR__SET     0x01 ///< The bit value monitored during transmission is  
                                     ///< different than the bit value sent.              
                                                                                          
#define LIN0ERR_CHK__BMASK      0x02 ///< Checksum Error Flag                             
#define LIN0ERR_CHK__SHIFT      0x01 ///< Checksum Error Flag                             
#define LIN0ERR_CHK__NOT_SET    0x00 ///< Checksum error has not been detected.           
#define LIN0ERR_CHK__SET        0x02 ///< Checksum error has been detected.               
                                                                                          
#define LIN0ERR_TOUT__BMASK     0x04 ///< Timeout Error Flag                              
#define LIN0ERR_TOUT__SHIFT     0x02 ///< Timeout Error Flag                              
#define LIN0ERR_TOUT__NOT_SET   0x00 ///< A timeout error has not been detected.          
#define LIN0ERR_TOUT__SET       0x04 ///< A timeout error has been detected.              
                                                                                          
#define LIN0ERR_PRTY__BMASK     0x08 ///< Parity Error Flag                               
#define LIN0ERR_PRTY__SHIFT     0x03 ///< Parity Error Flag                               
#define LIN0ERR_PRTY__NOT_SET   0x00 ///< No parity error has been detected.              
#define LIN0ERR_PRTY__SET       0x08 ///< A parity error has been detected.               
                                                                                          
#define LIN0ERR_SYNCH__BMASK    0x10 ///< Synchronization Error Flag                      
#define LIN0ERR_SYNCH__SHIFT    0x04 ///< Synchronization Error Flag                      
#define LIN0ERR_SYNCH__NOT_SET  0x00 ///< No error with the SYNCH FIELD has been detected.
#define LIN0ERR_SYNCH__SET      0x10 ///< Edges of the SYNCH FIELD are outside of the     
                                     ///< maximum tolerance.                              
                                                                                          
//------------------------------------------------------------------------------
// LIN0ID Enums (LIN0 Identifier @ 0x0E)
//------------------------------------------------------------------------------
#define LIN0ID_ID__FMASK   0x3F ///< LIN Identifier                                  
#define LIN0ID_ID__SHIFT   0x00 ///< LIN Identifier                                  
#define LIN0ID_ID__2_BYTES 0x00 ///< If LINSIZE is set to 15, select a data size of 2
                                ///< bytes.                                          
#define LIN0ID_ID__4_BYTES 0x02 ///< If LINSIZE is set to 15, select a data size of 4
                                ///< bytes.                                          
#define LIN0ID_ID__8_BYTES 0x03 ///< If LINSIZE is set to 15, select a data size of 8
                                ///< bytes.                                          
                                                                                     
//------------------------------------------------------------------------------
// LIN0MUL Enums (LIN0 Multiplier @ 0x0D)
//------------------------------------------------------------------------------
#define LIN0MUL_LINDIV__BMASK 0x01 ///< Baud Rate Divider High Bit
#define LIN0MUL_LINDIV__SHIFT 0x00 ///< Baud Rate Divider High Bit
                                                                  
#define LIN0MUL_LINMUL__FMASK 0x3E ///< Baud Rate Multiplier      
#define LIN0MUL_LINMUL__SHIFT 0x01 ///< Baud Rate Multiplier      
                                                                  
#define LIN0MUL_PRESCL__FMASK 0xC0 ///< Baud Rate Prescaler       
#define LIN0MUL_PRESCL__SHIFT 0x06 ///< Baud Rate Prescaler       
                                                                  
//------------------------------------------------------------------------------
// LIN0SIZE Enums (LIN0 Size @ 0x0B)
//------------------------------------------------------------------------------
#define LIN0SIZE_LINSIZE__FMASK        0x0F ///< Data Field Size                                  
#define LIN0SIZE_LINSIZE__SHIFT        0x00 ///< Data Field Size                                  
#define LIN0SIZE_LINSIZE__0_DATA_BYTES 0x00 ///< Select 0 data bytes.                             
#define LIN0SIZE_LINSIZE__1_DATA_BYTE  0x01 ///< Select 1 data byte.                              
#define LIN0SIZE_LINSIZE__2_DATA_BYTES 0x02 ///< Select 2 data bytes.                             
#define LIN0SIZE_LINSIZE__3_DATA_BYTES 0x03 ///< Select 3 data bytes.                             
#define LIN0SIZE_LINSIZE__4_DATA_BYTES 0x04 ///< Select 4 data bytes.                             
#define LIN0SIZE_LINSIZE__5_DATA_BYTES 0x05 ///< Select 5 data bytes.                             
#define LIN0SIZE_LINSIZE__6_DATA_BYTES 0x06 ///< Select 6 data bytes.                             
#define LIN0SIZE_LINSIZE__7_DATA_BYTES 0x07 ///< Select 7 data bytes.                             
#define LIN0SIZE_LINSIZE__8_DATA_BYTES 0x08 ///< Select 8 data bytes.                             
#define LIN0SIZE_LINSIZE__USE_ID       0x0F ///< Use the ID bits to determine the data length.    
                                                                                                  
#define LIN0SIZE_ENHCHK__BMASK         0x80 ///< Checksum Selection                               
#define LIN0SIZE_ENHCHK__SHIFT         0x07 ///< Checksum Selection                               
#define LIN0SIZE_ENHCHK__CLASSIC       0x00 ///< Use the classic checksum compliant with          
                                            ///< specification 1.3. The checksum covers the data  
                                            ///< bytes.                                           
#define LIN0SIZE_ENHCHK__ENHANCED      0x80 ///< Use the enhanced checksum compliant with         
                                            ///< specification 2.0. The checksum covers data bytes
                                            ///< and the protected identifier.                    
                                                                                                  
//------------------------------------------------------------------------------
// LIN0ST Enums (LIN0 Status @ 0x09)
//------------------------------------------------------------------------------
#define LIN0ST_DONE__BMASK      0x01 ///< Transmission Complete Flag                        
#define LIN0ST_DONE__SHIFT      0x00 ///< Transmission Complete Flag                        
#define LIN0ST_DONE__NOT_SET    0x00 ///< A transmission is not in progress or has not been 
                                     ///< started. Hardware clears this bit at the start of 
                                     ///< a transmission.                                   
#define LIN0ST_DONE__SET        0x01 ///< The current transmission is complete.             
                                                                                            
#define LIN0ST_WAKEUP__BMASK    0x02 ///< Wake-Up Flag                                      
#define LIN0ST_WAKEUP__SHIFT    0x01 ///< Wake-Up Flag                                      
#define LIN0ST_WAKEUP__NOT_SET  0x00 ///< A wakeup signal is not being transmitted and has  
                                     ///< not been received.                                
#define LIN0ST_WAKEUP__SET      0x02 ///< A wakeup signal is being transmitted or has been  
                                     ///< received.                                         
                                                                                            
#define LIN0ST_ERROR__BMASK     0x04 ///< Communication Error Flag                          
#define LIN0ST_ERROR__SHIFT     0x02 ///< Communication Error Flag                          
#define LIN0ST_ERROR__NOT_SET   0x00 ///< No error has been detected. This bit is cleared by
                                     ///< setting RSTERR                                    
#define LIN0ST_ERROR__SET       0x04 ///< An error has been detected.                       
                                                                                            
#define LIN0ST_LININT__BMASK    0x08 ///< Interrupt Request Flag                            
#define LIN0ST_LININT__SHIFT    0x03 ///< Interrupt Request Flag                            
#define LIN0ST_LININT__NOT_SET  0x00 ///< An interrupt is not pending.                      
#define LIN0ST_LININT__SET      0x08 ///< A LIN0 interrupt is pending.                      
                                                                                            
#define LIN0ST_DTREQ__BMASK     0x10 ///< Data Request Flag                                 
#define LIN0ST_DTREQ__SHIFT     0x04 ///< Data Request Flag                                 
#define LIN0ST_DTREQ__NOT_SET   0x00 ///< A data identifier has not been received.          
#define LIN0ST_DTREQ__SET       0x10 ///< A data identifier has been received.              
                                                                                            
#define LIN0ST_ABORT__BMASK     0x20 ///< Aborted Transmission Signal Flag                  
#define LIN0ST_ABORT__SHIFT     0x05 ///< Aborted Transmission Signal Flag                  
#define LIN0ST_ABORT__NOT_SET   0x00 ///< The current transmission has not been interrupted 
                                     ///< or stopped.                                       
#define LIN0ST_ABORT__SET       0x20 ///< Hardware detected a new SYNCH BREAK before the end
                                     ///< of the last transmission or firmware set the STOP 
                                     ///< bit.                                              
                                                                                            
#define LIN0ST_IDLTOUT__BMASK   0x40 ///< Bus Idle Timeout Flag                             
#define LIN0ST_IDLTOUT__SHIFT   0x06 ///< Bus Idle Timeout Flag                             
#define LIN0ST_IDLTOUT__NOT_SET 0x00 ///< The bus has not been idle for four seconds.       
#define LIN0ST_IDLTOUT__SET     0x40 ///< No bus activity has been detected for four        
                                     ///< seconds, but the bus is not yet in sleep mode.    
                                                                                            
#define LIN0ST_ACTIVE__BMASK    0x80 ///< LIN Bus Activity Flag                             
#define LIN0ST_ACTIVE__SHIFT    0x07 ///< LIN Bus Activity Flag                             
#define LIN0ST_ACTIVE__NOT_SET  0x00 ///< No transmission activity detected on the LIN bus. 
#define LIN0ST_ACTIVE__SET      0x80 ///< Transmission activity detected on the LIN bus.    
                                                                                            
//------------------------------------------------------------------------------
// XBR0 Enums (Port I/O Crossbar 0 @ 0xE1)
//------------------------------------------------------------------------------
#define XBR0_URT0E__BMASK    0x01 ///< UART0 I/O Output Enable                        
#define XBR0_URT0E__SHIFT    0x00 ///< UART0 I/O Output Enable                        
#define XBR0_URT0E__DISABLED 0x00 ///< UART0 I/O unavailable at Port pins.            
#define XBR0_URT0E__ENABLED  0x01 ///< UART0 TX, RX routed to Port pins P0.4 and P0.5.
                                                                                      
#define XBR0_CAN0E__BMASK    0x02 ///< CAN0 I/O Enable                                
#define XBR0_CAN0E__SHIFT    0x01 ///< CAN0 I/O Enable                                
#define XBR0_CAN0E__DISABLED 0x00 ///< CAN0 I/O unavailable at Port pins.             
#define XBR0_CAN0E__ENABLED  0x02 ///< CAN0 TX, RX routed to Port pins P0.6 and P0.7. 
                                                                                      
#define XBR0_SPI0E__BMASK    0x04 ///< SPI I/O Enable                                 
#define XBR0_SPI0E__SHIFT    0x02 ///< SPI I/O Enable                                 
#define XBR0_SPI0E__DISABLED 0x00 ///< SPI I/O unavailable at Port pins.              
#define XBR0_SPI0E__ENABLED  0x04 ///< SPI I/O routed to Port pins. The SPI can be    
                                  ///< assigned either 3 or 4 GPIO pins.              
                                                                                      
#define XBR0_SMB0E__BMASK    0x08 ///< SMBus0 I/O Enable                              
#define XBR0_SMB0E__SHIFT    0x03 ///< SMBus0 I/O Enable                              
#define XBR0_SMB0E__DISABLED 0x00 ///< SMBus0 I/O unavailable at Port pins.           
#define XBR0_SMB0E__ENABLED  0x08 ///< SMBus0 I/O routed to Port pins.                
                                                                                      
#define XBR0_CP0E__BMASK     0x10 ///< Comparator0 Output Enable                      
#define XBR0_CP0E__SHIFT     0x04 ///< Comparator0 Output Enable                      
#define XBR0_CP0E__DISABLED  0x00 ///< CP0 unavailable at Port pin.                   
#define XBR0_CP0E__ENABLED   0x10 ///< CP0 routed to Port pin.                        
                                                                                      
#define XBR0_CP0AE__BMASK    0x20 ///< Comparator0 Asynchronous Output Enable         
#define XBR0_CP0AE__SHIFT    0x05 ///< Comparator0 Asynchronous Output Enable         
#define XBR0_CP0AE__DISABLED 0x00 ///< Asynchronous CP0 unavailable at Port pin.      
#define XBR0_CP0AE__ENABLED  0x20 ///< Asynchronous CP0 routed to Port pin.           
                                                                                      
#define XBR0_CP1E__BMASK     0x40 ///< Comparator1 Output Enable                      
#define XBR0_CP1E__SHIFT     0x06 ///< Comparator1 Output Enable                      
#define XBR0_CP1E__DISABLED  0x00 ///< CP1 unavailable at Port pin.                   
#define XBR0_CP1E__ENABLED   0x40 ///< CP1 routed to Port pin.                        
                                                                                      
#define XBR0_CP1AE__BMASK    0x80 ///< Comparator1 Asynchronous Output Enable         
#define XBR0_CP1AE__SHIFT    0x07 ///< Comparator1 Asynchronous Output Enable         
#define XBR0_CP1AE__DISABLED 0x00 ///< Asynchronous CP1 unavailable at Port pin.      
#define XBR0_CP1AE__ENABLED  0x80 ///< Asynchronous CP1 routed to Port pin.           
                                                                                      
//------------------------------------------------------------------------------
// XBR1 Enums (Port I/O Crossbar 1 @ 0xE2)
//------------------------------------------------------------------------------
#define XBR1_SYSCKE__BMASK                         0x02 ///< SYSCLK Output Enable                             
#define XBR1_SYSCKE__SHIFT                         0x01 ///< SYSCLK Output Enable                             
#define XBR1_SYSCKE__DISABLED                      0x00 ///< SYSCLK unavailable at Port pin.                  
#define XBR1_SYSCKE__ENABLED                       0x02 ///< SYSCLK output routed to Port pin.                
                                                                                                              
#define XBR1_PCA0ME__FMASK                         0x1C ///< PCA0 Module I/O Enable                           
#define XBR1_PCA0ME__SHIFT                         0x02 ///< PCA0 Module I/O Enable                           
#define XBR1_PCA0ME__DISABLED                      0x00 ///< All PCA0 I/O unavailable at Port pins.           
#define XBR1_PCA0ME__CEX0                          0x04 ///< CEX0 routed to Port pin.                         
#define XBR1_PCA0ME__CEX0_CEX1                     0x08 ///< CEX0, CEX1 routed to Port pins.                  
#define XBR1_PCA0ME__CEX0_CEX1_CEX2                0x0C ///< CEX0, CEX1, CEX2 routed to Port pins.            
#define XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3           0x10 ///< CEX0, CEX1, CEX2, CEX3 routed to Port pins.      
#define XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4      0x14 ///< CEX0, CEX1, CEX2, CEX3, CEX4 routed to Port pins.
#define XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4_CEX5 0x18 ///< CEX0, CEX1, CEX2, CEX3, CEX4, CEX5 routed to Port
                                                        ///< pins.                                            
                                                                                                              
#define XBR1_ECI0E__BMASK                          0x20 ///< PCA0 External Counter Input Enable               
#define XBR1_ECI0E__SHIFT                          0x05 ///< PCA0 External Counter Input Enable               
#define XBR1_ECI0E__DISABLED                       0x00 ///< ECI0 unavailable at Port pin.                    
#define XBR1_ECI0E__ENABLED                        0x20 ///< ECI0 routed to Port pin.                         
                                                                                                              
#define XBR1_T0E__BMASK                            0x40 ///< T0 Enable                                        
#define XBR1_T0E__SHIFT                            0x06 ///< T0 Enable                                        
#define XBR1_T0E__DISABLED                         0x00 ///< T0 unavailable at Port pin.                      
#define XBR1_T0E__ENABLED                          0x40 ///< T0 routed to Port pin.                           
                                                                                                              
#define XBR1_T1E__BMASK                            0x80 ///< T1 Enable                                        
#define XBR1_T1E__SHIFT                            0x07 ///< T1 Enable                                        
#define XBR1_T1E__DISABLED                         0x00 ///< T1 unavailable at Port pin.                      
#define XBR1_T1E__ENABLED                          0x80 ///< T1 routed to Port pin.                           
                                                                                                              
//------------------------------------------------------------------------------
// XBR2 Enums (Port I/O Crossbar 2 @ 0xC7)
//------------------------------------------------------------------------------
#define XBR2_LIN0E__BMASK               0x01 ///< LIN0 I/O Enable                                 
#define XBR2_LIN0E__SHIFT               0x00 ///< LIN0 I/O Enable                                 
#define XBR2_LIN0E__DISABLED            0x00 ///< LIN0 I/O unavailable at Port pins.              
#define XBR2_LIN0E__ENABLED             0x01 ///< LIN0 I/O routed to Port pins.                   
                                                                                                  
#define XBR2_URT1E__BMASK               0x02 ///< UART1 I/O Output Enable                         
#define XBR2_URT1E__SHIFT               0x01 ///< UART1 I/O Output Enable                         
#define XBR2_URT1E__DISABLED            0x00 ///< UART1 I/O unavailable at Port pins.             
#define XBR2_URT1E__ENABLED             0x02 ///< UART1 TX, RX routed to Port pins.               
                                                                                                  
#define XBR2_CP2E__BMASK                0x04 ///< Comparator2 Output Enable                       
#define XBR2_CP2E__SHIFT                0x02 ///< Comparator2 Output Enable                       
#define XBR2_CP2E__DISABLED             0x00 ///< CP2 unavailable at Port pin.                    
#define XBR2_CP2E__ENABLED              0x04 ///< CP2 routed to Port pin.                         
                                                                                                  
#define XBR2_CP2AE__BMASK               0x08 ///< Comparator2 Asynchronous Output Enable          
#define XBR2_CP2AE__SHIFT               0x03 ///< Comparator2 Asynchronous Output Enable          
#define XBR2_CP2AE__DISABLED            0x00 ///< Asynchronous CP2 unavailable at Port pin.       
#define XBR2_CP2AE__ENABLED             0x08 ///< Asynchronous CP2 routed to Port pin.            
                                                                                                  
#define XBR2_XBARE__BMASK               0x40 ///< Crossbar Enable                                 
#define XBR2_XBARE__SHIFT               0x06 ///< Crossbar Enable                                 
#define XBR2_XBARE__DISABLED            0x00 ///< Crossbar disabled.                              
#define XBR2_XBARE__ENABLED             0x40 ///< Crossbar enabled.                               
                                                                                                  
#define XBR2_WEAKPUD__BMASK             0x80 ///< Port I/O Weak Pullup Disable                    
#define XBR2_WEAKPUD__SHIFT             0x07 ///< Port I/O Weak Pullup Disable                    
#define XBR2_WEAKPUD__PULL_UPS_ENABLED  0x00 ///< Weak Pullups enabled (except for Ports whose I/O
                                             ///< are configured for analog mode).                
#define XBR2_WEAKPUD__PULL_UPS_DISABLED 0x80 ///< Weak Pullups disabled.                          
                                                                                                  
//------------------------------------------------------------------------------
// XBR3 Enums (Port I/O Crossbar 3 @ 0xC6)
//------------------------------------------------------------------------------
#define XBR3_PCA1ME__FMASK                           0x07 ///< PCA1 Module I/O Enable                            
#define XBR3_PCA1ME__SHIFT                           0x00 ///< PCA1 Module I/O Enable                            
#define XBR3_PCA1ME__DISABLED                        0x00 ///< All PCA1 I/O unavailable at Port pins.            
#define XBR3_PCA1ME__CEX6                            0x01 ///< CEX6 routed to Port pin.                          
#define XBR3_PCA1ME__CEX6_CEX7                       0x02 ///< CEX6, CEX7 routed to Port pins.                   
#define XBR3_PCA1ME__CEX6_CEX7_CEX8                  0x03 ///< CEX6, CEX7, CEX8 routed to Port pins.             
#define XBR3_PCA1ME__CEX6_CEX7_CEX8_CEX9             0x04 ///< CEX6, CEX7, CEX8, CEX9 routed to Port pins.       
#define XBR3_PCA1ME__CEX6_CEX7_CEX8_CEX9_CEX10       0x05 ///< CEX6, CEX7, CEX8, CEX9, CEX10 routed to Port pins.
#define XBR3_PCA1ME__CEX6_CEX7_CEX8_CEX9_CEX10_CEX11 0x06 ///< CEX6, CEX7, CEX8, CEX9, CEX10, CEX11 routed to    
                                                          ///< Port pins.                                        
                                                                                                                 
#define XBR3_ECI1E__BMASK                            0x08 ///< PCA1 External Counter Input Enable                
#define XBR3_ECI1E__SHIFT                            0x03 ///< PCA1 External Counter Input Enable                
#define XBR3_ECI1E__DISABLED                         0x00 ///< ECI1 unavailable at Port pin.                     
#define XBR3_ECI1E__ENABLED                          0x08 ///< ECI1 routed to Port pin.                          
                                                                                                                 
#define XBR3_T4E__BMASK                              0x10 ///< T4 Enable                                         
#define XBR3_T4E__SHIFT                              0x04 ///< T4 Enable                                         
#define XBR3_T4E__DISABLED                           0x00 ///< T4 unavailable at Port pin.                       
#define XBR3_T4E__ENABLED                            0x10 ///< T4 routed to Port pin.                            
                                                                                                                 
#define XBR3_T4EXE__BMASK                            0x20 ///< T4EX Enable                                       
#define XBR3_T4EXE__SHIFT                            0x05 ///< T4EX Enable                                       
#define XBR3_T4EXE__DISABLED                         0x00 ///< T4EX unavailable at Port pin.                     
#define XBR3_T4EXE__ENABLED                          0x20 ///< T4EX routed to Port pin.                          
                                                                                                                 
#define XBR3_T5E__BMASK                              0x40 ///< T5 Enable                                         
#define XBR3_T5E__SHIFT                              0x06 ///< T5 Enable                                         
#define XBR3_T5E__DISABLED                           0x00 ///< T5 unavailable at Port pin.                       
#define XBR3_T5E__ENABLED                            0x40 ///< T5 routed to Port pin.                            
                                                                                                                 
#define XBR3_T5EXE__BMASK                            0x80 ///< T5EX Enable                                       
#define XBR3_T5EXE__SHIFT                            0x07 ///< T5EX Enable                                       
#define XBR3_T5EXE__DISABLED                         0x00 ///< T5EX unavailable at Port pin.                     
#define XBR3_T5EXE__ENABLED                          0x80 ///< T5EX routed to Port pin.                          
                                                                                                                 
//------------------------------------------------------------------------------
// PCA0CN Enums (PCA Control @ 0xD8)
//------------------------------------------------------------------------------
#define PCA0CN_CCF0__BMASK   0x01 ///< PCA Module 0 Capture/Compare Flag             
#define PCA0CN_CCF0__SHIFT   0x00 ///< PCA Module 0 Capture/Compare Flag             
#define PCA0CN_CCF0__NOT_SET 0x00 ///< A match or capture did not occur on channel 0.
#define PCA0CN_CCF0__SET     0x01 ///< A match or capture occurred on channel 0.     
                                                                                     
#define PCA0CN_CCF1__BMASK   0x02 ///< PCA Module 1 Capture/Compare Flag             
#define PCA0CN_CCF1__SHIFT   0x01 ///< PCA Module 1 Capture/Compare Flag             
#define PCA0CN_CCF1__NOT_SET 0x00 ///< A match or capture did not occur on channel 1.
#define PCA0CN_CCF1__SET     0x02 ///< A match or capture occurred on channel 1.     
                                                                                     
#define PCA0CN_CCF2__BMASK   0x04 ///< PCA Module 2 Capture/Compare Flag             
#define PCA0CN_CCF2__SHIFT   0x02 ///< PCA Module 2 Capture/Compare Flag             
#define PCA0CN_CCF2__NOT_SET 0x00 ///< A match or capture did not occur on channel 2.
#define PCA0CN_CCF2__SET     0x04 ///< A match or capture occurred on channel 2.     
                                                                                     
#define PCA0CN_CCF3__BMASK   0x08 ///< PCA Module 3 Capture/Compare Flag             
#define PCA0CN_CCF3__SHIFT   0x03 ///< PCA Module 3 Capture/Compare Flag             
#define PCA0CN_CCF3__NOT_SET 0x00 ///< A match or capture did not occur on channel 3.
#define PCA0CN_CCF3__SET     0x08 ///< A match or capture occurred on channel 3.     
                                                                                     
#define PCA0CN_CCF4__BMASK   0x10 ///< PCA Module 4 Capture/Compare Flag             
#define PCA0CN_CCF4__SHIFT   0x04 ///< PCA Module 4 Capture/Compare Flag             
#define PCA0CN_CCF4__NOT_SET 0x00 ///< A match or capture did not occur on channel 4.
#define PCA0CN_CCF4__SET     0x10 ///< A match or capture occurred on channel 4.     
                                                                                     
#define PCA0CN_CCF5__BMASK   0x20 ///< PCA Module 5 Capture/Compare Flag             
#define PCA0CN_CCF5__SHIFT   0x05 ///< PCA Module 5 Capture/Compare Flag             
#define PCA0CN_CCF5__NOT_SET 0x00 ///< A match or capture did not occur on channel 5.
#define PCA0CN_CCF5__SET     0x20 ///< A match or capture occurred on channel 5.     
                                                                                     
#define PCA0CN_CR__BMASK     0x40 ///< PCA Counter/Timer Run Control                 
#define PCA0CN_CR__SHIFT     0x06 ///< PCA Counter/Timer Run Control                 
#define PCA0CN_CR__STOP      0x00 ///< Stop the PCA Counter/Timer.                   
#define PCA0CN_CR__RUN       0x40 ///< Start the PCA Counter/Timer running.          
                                                                                     
#define PCA0CN_CF__BMASK     0x80 ///< PCA Counter/Timer Overflow Flag               
#define PCA0CN_CF__SHIFT     0x07 ///< PCA Counter/Timer Overflow Flag               
#define PCA0CN_CF__NOT_SET   0x00 ///< The PCA counter/timer did not overflow.       
#define PCA0CN_CF__SET       0x80 ///< The PCA counter/timer overflowed.             
                                                                                     
//------------------------------------------------------------------------------
// PCA0CPH0 Enums (PCA Channel 0 Capture Module High Byte @ 0xFC)
//------------------------------------------------------------------------------
#define PCA0CPH0_PCA0CPH0__FMASK 0xFF ///< PCA Channel 0 Capture Module High Byte
#define PCA0CPH0_PCA0CPH0__SHIFT 0x00 ///< PCA Channel 0 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPH1 Enums (PCA Channel 1 Capture Module High Byte @ 0xEA)
//------------------------------------------------------------------------------
#define PCA0CPH1_PCA0CPH1__FMASK 0xFF ///< PCA Channel 1 Capture Module High Byte
#define PCA0CPH1_PCA0CPH1__SHIFT 0x00 ///< PCA Channel 1 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPH2 Enums (PCA Channel 2 Capture Module High Byte @ 0xEC)
//------------------------------------------------------------------------------
#define PCA0CPH2_PCA0CPH2__FMASK 0xFF ///< PCA Channel 2 Capture Module High Byte
#define PCA0CPH2_PCA0CPH2__SHIFT 0x00 ///< PCA Channel 2 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPH3 Enums (PCA Channel 3 Capture Module High Byte @ 0xEE)
//------------------------------------------------------------------------------
#define PCA0CPH3_PCA0CPH3__FMASK 0xFF ///< PCA Channel 3 Capture Module High Byte
#define PCA0CPH3_PCA0CPH3__SHIFT 0x00 ///< PCA Channel 3 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPH4 Enums (PCA Channel 4 Capture Module High Byte @ 0xFE)
//------------------------------------------------------------------------------
#define PCA0CPH4_PCA0CPH4__FMASK 0xFF ///< PCA Channel 4 Capture Module High Byte
#define PCA0CPH4_PCA0CPH4__SHIFT 0x00 ///< PCA Channel 4 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPH5 Enums (PCA Channel 5 Capture Module High Byte @ 0xCF)
//------------------------------------------------------------------------------
#define PCA0CPH5_PCA0CPH5__FMASK 0xFF ///< PCA Channel 5 Capture Module High Byte
#define PCA0CPH5_PCA0CPH5__SHIFT 0x00 ///< PCA Channel 5 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL0 Enums (PCA Channel 0 Capture Module Low Byte @ 0xFB)
//------------------------------------------------------------------------------
#define PCA0CPL0_PCA0CPL0__FMASK 0xFF ///< PCA Channel 0 Capture Module Low Byte
#define PCA0CPL0_PCA0CPL0__SHIFT 0x00 ///< PCA Channel 0 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA0CPL1 Enums (PCA Channel 1 Capture Module Low Byte @ 0xE9)
//------------------------------------------------------------------------------
#define PCA0CPL1_PCA0CPL1__FMASK 0xFF ///< PCA Channel 1 Capture Module Low Byte
#define PCA0CPL1_PCA0CPL1__SHIFT 0x00 ///< PCA Channel 1 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA0CPL2 Enums (PCA Channel 2 Capture Module Low Byte @ 0xEB)
//------------------------------------------------------------------------------
#define PCA0CPL2_PCA0CPL2__FMASK 0xFF ///< PCA Channel 2 Capture Module Low Byte
#define PCA0CPL2_PCA0CPL2__SHIFT 0x00 ///< PCA Channel 2 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA0CPL3 Enums (PCA Channel 3 Capture Module Low Byte @ 0xED)
//------------------------------------------------------------------------------
#define PCA0CPL3_PCA0CPL3__FMASK 0xFF ///< PCA Channel 3 Capture Module Low Byte
#define PCA0CPL3_PCA0CPL3__SHIFT 0x00 ///< PCA Channel 3 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA0CPL4 Enums (PCA Channel 4 Capture Module Low Byte @ 0xFD)
//------------------------------------------------------------------------------
#define PCA0CPL4_PCA0CPL4__FMASK 0xFF ///< PCA Channel 4 Capture Module Low Byte
#define PCA0CPL4_PCA0CPL4__SHIFT 0x00 ///< PCA Channel 4 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA0CPL5 Enums (PCA Channel 5 Capture Module Low Byte @ 0xCE)
//------------------------------------------------------------------------------
#define PCA0CPL5_PCA0CPL5__FMASK 0xFF ///< PCA Channel 5 Capture Module Low Byte
#define PCA0CPL5_PCA0CPL5__SHIFT 0x00 ///< PCA Channel 5 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA0CPM0 Enums (PCA Channel 0 Capture/Compare Mode 0 @ 0xDA)
//------------------------------------------------------------------------------
#define PCA0CPM0_ECCF__BMASK    0x01 ///< Channel 0 Capture/Compare Flag Interrupt Enable
#define PCA0CPM0_ECCF__SHIFT    0x00 ///< Channel 0 Capture/Compare Flag Interrupt Enable
#define PCA0CPM0_ECCF__DISABLED 0x00 ///< Disable CCF0 interrupts.                       
#define PCA0CPM0_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request
                                     ///< when CCF0 is set.                              
                                                                                         
#define PCA0CPM0_PWM__BMASK     0x02 ///< Channel 0 Pulse Width Modulation Mode Enable   
#define PCA0CPM0_PWM__SHIFT     0x01 ///< Channel 0 Pulse Width Modulation Mode Enable   
#define PCA0CPM0_PWM__DISABLED  0x00 ///< Disable PWM function.                          
#define PCA0CPM0_PWM__ENABLED   0x02 ///< Enable PWM function.                           
                                                                                         
#define PCA0CPM0_TOG__BMASK     0x04 ///< Channel 0 Toggle Function Enable               
#define PCA0CPM0_TOG__SHIFT     0x02 ///< Channel 0 Toggle Function Enable               
#define PCA0CPM0_TOG__DISABLED  0x00 ///< Disable toggle function.                       
#define PCA0CPM0_TOG__ENABLED   0x04 ///< Enable toggle function.                        
                                                                                         
#define PCA0CPM0_MAT__BMASK     0x08 ///< Channel 0 Match Function Enable                
#define PCA0CPM0_MAT__SHIFT     0x03 ///< Channel 0 Match Function Enable                
#define PCA0CPM0_MAT__DISABLED  0x00 ///< Disable match function.                        
#define PCA0CPM0_MAT__ENABLED   0x08 ///< Enable match function.                         
                                                                                         
#define PCA0CPM0_CAPN__BMASK    0x10 ///< Channel 0 Capture Negative Function Enable     
#define PCA0CPM0_CAPN__SHIFT    0x04 ///< Channel 0 Capture Negative Function Enable     
#define PCA0CPM0_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                 
#define PCA0CPM0_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                  
                                                                                         
#define PCA0CPM0_CAPP__BMASK    0x20 ///< Channel 0 Capture Positive Function Enable     
#define PCA0CPM0_CAPP__SHIFT    0x05 ///< Channel 0 Capture Positive Function Enable     
#define PCA0CPM0_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                 
#define PCA0CPM0_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                  
                                                                                         
#define PCA0CPM0_ECOM__BMASK    0x40 ///< Channel 0 Comparator Function Enable           
#define PCA0CPM0_ECOM__SHIFT    0x06 ///< Channel 0 Comparator Function Enable           
#define PCA0CPM0_ECOM__DISABLED 0x00 ///< Disable comparator function.                   
#define PCA0CPM0_ECOM__ENABLED  0x40 ///< Enable comparator function.                    
                                                                                         
#define PCA0CPM0_PWM16__BMASK   0x80 ///< Channel 0 16-bit Pulse Width Modulation Enable 
#define PCA0CPM0_PWM16__SHIFT   0x07 ///< Channel 0 16-bit Pulse Width Modulation Enable 
#define PCA0CPM0_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                      
#define PCA0CPM0_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0CPM1 Enums (PCA Channel 1 Capture/Compare Mode @ 0xDB)
//------------------------------------------------------------------------------
#define PCA0CPM1_ECCF__BMASK    0x01 ///< Channel 1 Capture/Compare Flag Interrupt Enable
#define PCA0CPM1_ECCF__SHIFT    0x00 ///< Channel 1 Capture/Compare Flag Interrupt Enable
#define PCA0CPM1_ECCF__DISABLED 0x00 ///< Disable CCF1 interrupts.                       
#define PCA0CPM1_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request
                                     ///< when CCF1 is set.                              
                                                                                         
#define PCA0CPM1_PWM__BMASK     0x02 ///< Channel 1 Pulse Width Modulation Mode Enable   
#define PCA0CPM1_PWM__SHIFT     0x01 ///< Channel 1 Pulse Width Modulation Mode Enable   
#define PCA0CPM1_PWM__DISABLED  0x00 ///< Disable PWM function.                          
#define PCA0CPM1_PWM__ENABLED   0x02 ///< Enable PWM function.                           
                                                                                         
#define PCA0CPM1_TOG__BMASK     0x04 ///< Channel 1 Toggle Function Enable               
#define PCA0CPM1_TOG__SHIFT     0x02 ///< Channel 1 Toggle Function Enable               
#define PCA0CPM1_TOG__DISABLED  0x00 ///< Disable toggle function.                       
#define PCA0CPM1_TOG__ENABLED   0x04 ///< Enable toggle function.                        
                                                                                         
#define PCA0CPM1_MAT__BMASK     0x08 ///< Channel 1 Match Function Enable                
#define PCA0CPM1_MAT__SHIFT     0x03 ///< Channel 1 Match Function Enable                
#define PCA0CPM1_MAT__DISABLED  0x00 ///< Disable match function.                        
#define PCA0CPM1_MAT__ENABLED   0x08 ///< Enable match function.                         
                                                                                         
#define PCA0CPM1_CAPN__BMASK    0x10 ///< Channel 1 Capture Negative Function Enable     
#define PCA0CPM1_CAPN__SHIFT    0x04 ///< Channel 1 Capture Negative Function Enable     
#define PCA0CPM1_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                 
#define PCA0CPM1_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                  
                                                                                         
#define PCA0CPM1_CAPP__BMASK    0x20 ///< Channel 1 Capture Positive Function Enable     
#define PCA0CPM1_CAPP__SHIFT    0x05 ///< Channel 1 Capture Positive Function Enable     
#define PCA0CPM1_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                 
#define PCA0CPM1_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                  
                                                                                         
#define PCA0CPM1_ECOM__BMASK    0x40 ///< Channel 1 Comparator Function Enable           
#define PCA0CPM1_ECOM__SHIFT    0x06 ///< Channel 1 Comparator Function Enable           
#define PCA0CPM1_ECOM__DISABLED 0x00 ///< Disable comparator function.                   
#define PCA0CPM1_ECOM__ENABLED  0x40 ///< Enable comparator function.                    
                                                                                         
#define PCA0CPM1_PWM16__BMASK   0x80 ///< Channel 1 16-bit Pulse Width Modulation Enable 
#define PCA0CPM1_PWM16__SHIFT   0x07 ///< Channel 1 16-bit Pulse Width Modulation Enable 
#define PCA0CPM1_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                      
#define PCA0CPM1_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0CPM2 Enums (PCA Channel 2 Capture/Compare Mode @ 0xDC)
//------------------------------------------------------------------------------
#define PCA0CPM2_ECCF__BMASK    0x01 ///< Channel 2 Capture/Compare Flag Interrupt Enable
#define PCA0CPM2_ECCF__SHIFT    0x00 ///< Channel 2 Capture/Compare Flag Interrupt Enable
#define PCA0CPM2_ECCF__DISABLED 0x00 ///< Disable CCF2 interrupts.                       
#define PCA0CPM2_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request
                                     ///< when CCF2 is set.                              
                                                                                         
#define PCA0CPM2_PWM__BMASK     0x02 ///< Channel 2 Pulse Width Modulation Mode Enable   
#define PCA0CPM2_PWM__SHIFT     0x01 ///< Channel 2 Pulse Width Modulation Mode Enable   
#define PCA0CPM2_PWM__DISABLED  0x00 ///< Disable PWM function.                          
#define PCA0CPM2_PWM__ENABLED   0x02 ///< Enable PWM function.                           
                                                                                         
#define PCA0CPM2_TOG__BMASK     0x04 ///< Channel 2 Toggle Function Enable               
#define PCA0CPM2_TOG__SHIFT     0x02 ///< Channel 2 Toggle Function Enable               
#define PCA0CPM2_TOG__DISABLED  0x00 ///< Disable toggle function.                       
#define PCA0CPM2_TOG__ENABLED   0x04 ///< Enable toggle function.                        
                                                                                         
#define PCA0CPM2_MAT__BMASK     0x08 ///< Channel 2 Match Function Enable                
#define PCA0CPM2_MAT__SHIFT     0x03 ///< Channel 2 Match Function Enable                
#define PCA0CPM2_MAT__DISABLED  0x00 ///< Disable match function.                        
#define PCA0CPM2_MAT__ENABLED   0x08 ///< Enable match function.                         
                                                                                         
#define PCA0CPM2_CAPN__BMASK    0x10 ///< Channel 2 Capture Negative Function Enable     
#define PCA0CPM2_CAPN__SHIFT    0x04 ///< Channel 2 Capture Negative Function Enable     
#define PCA0CPM2_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                 
#define PCA0CPM2_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                  
                                                                                         
#define PCA0CPM2_CAPP__BMASK    0x20 ///< Channel 2 Capture Positive Function Enable     
#define PCA0CPM2_CAPP__SHIFT    0x05 ///< Channel 2 Capture Positive Function Enable     
#define PCA0CPM2_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                 
#define PCA0CPM2_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                  
                                                                                         
#define PCA0CPM2_ECOM__BMASK    0x40 ///< Channel 2 Comparator Function Enable           
#define PCA0CPM2_ECOM__SHIFT    0x06 ///< Channel 2 Comparator Function Enable           
#define PCA0CPM2_ECOM__DISABLED 0x00 ///< Disable comparator function.                   
#define PCA0CPM2_ECOM__ENABLED  0x40 ///< Enable comparator function.                    
                                                                                         
#define PCA0CPM2_PWM16__BMASK   0x80 ///< Channel 2 16-bit Pulse Width Modulation Enable 
#define PCA0CPM2_PWM16__SHIFT   0x07 ///< Channel 2 16-bit Pulse Width Modulation Enable 
#define PCA0CPM2_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                      
#define PCA0CPM2_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0CPM3 Enums (PCA Channel 3 Capture/Compare Mode @ 0xDD)
//------------------------------------------------------------------------------
#define PCA0CPM3_ECCF__BMASK    0x01 ///< Channel 3 Capture/Compare Flag Interrupt Enable
#define PCA0CPM3_ECCF__SHIFT    0x00 ///< Channel 3 Capture/Compare Flag Interrupt Enable
#define PCA0CPM3_ECCF__DISABLED 0x00 ///< Disable CCF3 interrupts.                       
#define PCA0CPM3_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request
                                     ///< when CCF3 is set.                              
                                                                                         
#define PCA0CPM3_PWM__BMASK     0x02 ///< Channel 3 Pulse Width Modulation Mode Enable   
#define PCA0CPM3_PWM__SHIFT     0x01 ///< Channel 3 Pulse Width Modulation Mode Enable   
#define PCA0CPM3_PWM__DISABLED  0x00 ///< Disable PWM function.                          
#define PCA0CPM3_PWM__ENABLED   0x02 ///< Enable PWM function.                           
                                                                                         
#define PCA0CPM3_TOG__BMASK     0x04 ///< Channel 3 Toggle Function Enable               
#define PCA0CPM3_TOG__SHIFT     0x02 ///< Channel 3 Toggle Function Enable               
#define PCA0CPM3_TOG__DISABLED  0x00 ///< Disable toggle function.                       
#define PCA0CPM3_TOG__ENABLED   0x04 ///< Enable toggle function.                        
                                                                                         
#define PCA0CPM3_MAT__BMASK     0x08 ///< Channel 3 Match Function Enable                
#define PCA0CPM3_MAT__SHIFT     0x03 ///< Channel 3 Match Function Enable                
#define PCA0CPM3_MAT__DISABLED  0x00 ///< Disable match function.                        
#define PCA0CPM3_MAT__ENABLED   0x08 ///< Enable match function.                         
                                                                                         
#define PCA0CPM3_CAPN__BMASK    0x10 ///< Channel 3 Capture Negative Function Enable     
#define PCA0CPM3_CAPN__SHIFT    0x04 ///< Channel 3 Capture Negative Function Enable     
#define PCA0CPM3_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                 
#define PCA0CPM3_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                  
                                                                                         
#define PCA0CPM3_CAPP__BMASK    0x20 ///< Channel 3 Capture Positive Function Enable     
#define PCA0CPM3_CAPP__SHIFT    0x05 ///< Channel 3 Capture Positive Function Enable     
#define PCA0CPM3_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                 
#define PCA0CPM3_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                  
                                                                                         
#define PCA0CPM3_ECOM__BMASK    0x40 ///< Channel 3 Comparator Function Enable           
#define PCA0CPM3_ECOM__SHIFT    0x06 ///< Channel 3 Comparator Function Enable           
#define PCA0CPM3_ECOM__DISABLED 0x00 ///< Disable comparator function.                   
#define PCA0CPM3_ECOM__ENABLED  0x40 ///< Enable comparator function.                    
                                                                                         
#define PCA0CPM3_PWM16__BMASK   0x80 ///< Channel 3 16-bit Pulse Width Modulation Enable 
#define PCA0CPM3_PWM16__SHIFT   0x07 ///< Channel 3 16-bit Pulse Width Modulation Enable 
#define PCA0CPM3_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                      
#define PCA0CPM3_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0CPM4 Enums (PCA Channel 4 Capture/Compare Mode @ 0xDE)
//------------------------------------------------------------------------------
#define PCA0CPM4_ECCF__BMASK    0x01 ///< Channel 4 Capture/Compare Flag Interrupt Enable
#define PCA0CPM4_ECCF__SHIFT    0x00 ///< Channel 4 Capture/Compare Flag Interrupt Enable
#define PCA0CPM4_ECCF__DISABLED 0x00 ///< Disable CCF4 interrupts.                       
#define PCA0CPM4_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request
                                     ///< when CCF4 is set.                              
                                                                                         
#define PCA0CPM4_PWM__BMASK     0x02 ///< Channel 4 Pulse Width Modulation Mode Enable   
#define PCA0CPM4_PWM__SHIFT     0x01 ///< Channel 4 Pulse Width Modulation Mode Enable   
#define PCA0CPM4_PWM__DISABLED  0x00 ///< Disable PWM function.                          
#define PCA0CPM4_PWM__ENABLED   0x02 ///< Enable PWM function.                           
                                                                                         
#define PCA0CPM4_TOG__BMASK     0x04 ///< Channel 4 Toggle Function Enable               
#define PCA0CPM4_TOG__SHIFT     0x02 ///< Channel 4 Toggle Function Enable               
#define PCA0CPM4_TOG__DISABLED  0x00 ///< Disable toggle function.                       
#define PCA0CPM4_TOG__ENABLED   0x04 ///< Enable toggle function.                        
                                                                                         
#define PCA0CPM4_MAT__BMASK     0x08 ///< Channel 4 Match Function Enable                
#define PCA0CPM4_MAT__SHIFT     0x03 ///< Channel 4 Match Function Enable                
#define PCA0CPM4_MAT__DISABLED  0x00 ///< Disable match function.                        
#define PCA0CPM4_MAT__ENABLED   0x08 ///< Enable match function.                         
                                                                                         
#define PCA0CPM4_CAPN__BMASK    0x10 ///< Channel 4 Capture Negative Function Enable     
#define PCA0CPM4_CAPN__SHIFT    0x04 ///< Channel 4 Capture Negative Function Enable     
#define PCA0CPM4_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                 
#define PCA0CPM4_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                  
                                                                                         
#define PCA0CPM4_CAPP__BMASK    0x20 ///< Channel 4 Capture Positive Function Enable     
#define PCA0CPM4_CAPP__SHIFT    0x05 ///< Channel 4 Capture Positive Function Enable     
#define PCA0CPM4_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                 
#define PCA0CPM4_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                  
                                                                                         
#define PCA0CPM4_ECOM__BMASK    0x40 ///< Channel 4 Comparator Function Enable           
#define PCA0CPM4_ECOM__SHIFT    0x06 ///< Channel 4 Comparator Function Enable           
#define PCA0CPM4_ECOM__DISABLED 0x00 ///< Disable comparator function.                   
#define PCA0CPM4_ECOM__ENABLED  0x40 ///< Enable comparator function.                    
                                                                                         
#define PCA0CPM4_PWM16__BMASK   0x80 ///< Channel 4 16-bit Pulse Width Modulation Enable 
#define PCA0CPM4_PWM16__SHIFT   0x07 ///< Channel 4 16-bit Pulse Width Modulation Enable 
#define PCA0CPM4_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                      
#define PCA0CPM4_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0CPM5 Enums (PCA Channel 5 Capture/Compare Mode @ 0xDF)
//------------------------------------------------------------------------------
#define PCA0CPM5_ECCF__BMASK    0x01 ///< Channel 5 Capture/Compare Flag Interrupt Enable
#define PCA0CPM5_ECCF__SHIFT    0x00 ///< Channel 5 Capture/Compare Flag Interrupt Enable
#define PCA0CPM5_ECCF__DISABLED 0x00 ///< Disable CCF5 interrupts.                       
#define PCA0CPM5_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request
                                     ///< when CCF5 is set.                              
                                                                                         
#define PCA0CPM5_PWM__BMASK     0x02 ///< Channel 5 Pulse Width Modulation Mode Enable   
#define PCA0CPM5_PWM__SHIFT     0x01 ///< Channel 5 Pulse Width Modulation Mode Enable   
#define PCA0CPM5_PWM__DISABLED  0x00 ///< Disable PWM function.                          
#define PCA0CPM5_PWM__ENABLED   0x02 ///< Enable PWM function.                           
                                                                                         
#define PCA0CPM5_TOG__BMASK     0x04 ///< Channel 5 Toggle Function Enable               
#define PCA0CPM5_TOG__SHIFT     0x02 ///< Channel 5 Toggle Function Enable               
#define PCA0CPM5_TOG__DISABLED  0x00 ///< Disable toggle function.                       
#define PCA0CPM5_TOG__ENABLED   0x04 ///< Enable toggle function.                        
                                                                                         
#define PCA0CPM5_MAT__BMASK     0x08 ///< Channel 5 Match Function Enable                
#define PCA0CPM5_MAT__SHIFT     0x03 ///< Channel 5 Match Function Enable                
#define PCA0CPM5_MAT__DISABLED  0x00 ///< Disable match function.                        
#define PCA0CPM5_MAT__ENABLED   0x08 ///< Enable match function.                         
                                                                                         
#define PCA0CPM5_CAPN__BMASK    0x10 ///< Channel 5 Capture Negative Function Enable     
#define PCA0CPM5_CAPN__SHIFT    0x04 ///< Channel 5 Capture Negative Function Enable     
#define PCA0CPM5_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                 
#define PCA0CPM5_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                  
                                                                                         
#define PCA0CPM5_CAPP__BMASK    0x20 ///< Channel 5 Capture Positive Function Enable     
#define PCA0CPM5_CAPP__SHIFT    0x05 ///< Channel 5 Capture Positive Function Enable     
#define PCA0CPM5_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                 
#define PCA0CPM5_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                  
                                                                                         
#define PCA0CPM5_ECOM__BMASK    0x40 ///< Channel 5 Comparator Function Enable           
#define PCA0CPM5_ECOM__SHIFT    0x06 ///< Channel 5 Comparator Function Enable           
#define PCA0CPM5_ECOM__DISABLED 0x00 ///< Disable comparator function.                   
#define PCA0CPM5_ECOM__ENABLED  0x40 ///< Enable comparator function.                    
                                                                                         
#define PCA0CPM5_PWM16__BMASK   0x80 ///< Channel 5 16-bit Pulse Width Modulation Enable 
#define PCA0CPM5_PWM16__SHIFT   0x07 ///< Channel 5 16-bit Pulse Width Modulation Enable 
#define PCA0CPM5_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                      
#define PCA0CPM5_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0H Enums (PCA Counter/Timer High Byte @ 0xFA)
//------------------------------------------------------------------------------
#define PCA0H_PCA0H__FMASK 0xFF ///< PCA Counter/Timer High Byte
#define PCA0H_PCA0H__SHIFT 0x00 ///< PCA Counter/Timer High Byte
                                                                
//------------------------------------------------------------------------------
// PCA0L Enums (PCA Counter/Timer Low Byte @ 0xF9)
//------------------------------------------------------------------------------
#define PCA0L_PCA0L__FMASK 0xFF ///< PCA Counter/Timer Low Byte
#define PCA0L_PCA0L__SHIFT 0x00 ///< PCA Counter/Timer Low Byte
                                                               
//------------------------------------------------------------------------------
// PCA0MD Enums (PCA Mode @ 0xD9)
//------------------------------------------------------------------------------
#define PCA0MD_ECF__BMASK            0x01 ///< PCA Counter/Timer Overflow Interrupt Enable       
#define PCA0MD_ECF__SHIFT            0x00 ///< PCA Counter/Timer Overflow Interrupt Enable       
#define PCA0MD_ECF__OVF_INT_DISABLED 0x00 ///< Disable the CF interrupt.                         
#define PCA0MD_ECF__OVF_INT_ENABLED  0x01 ///< Enable a PCA Counter/Timer Overflow interrupt     
                                          ///< request when CF (PCA0CN.7) is set.                
                                                                                                 
#define PCA0MD_CPS__FMASK            0x0E ///< PCA Counter/Timer Pulse Select                    
#define PCA0MD_CPS__SHIFT            0x01 ///< PCA Counter/Timer Pulse Select                    
#define PCA0MD_CPS__SYSCLK_DIV_12    0x00 ///< System clock divided by 12.                       
#define PCA0MD_CPS__SYSCLK_DIV_4     0x02 ///< System clock divided by 4.                        
#define PCA0MD_CPS__T0_OVERFLOW      0x04 ///< Timer 0 overflow.                                 
#define PCA0MD_CPS__ECI              0x06 ///< High-to-low transitions on ECI (max rate = system 
                                          ///< clock divided by 4).                              
#define PCA0MD_CPS__SYSCLK           0x08 ///< System clock.                                     
#define PCA0MD_CPS__EXTOSC_DIV_8     0x0A ///< External clock divided by 8 (synchronized with the
                                          ///< system clock).                                    
#define PCA0MD_CPS__RTC_DIV_8        0x0C ///< RTC divided by 8.                                 
                                                                                                 
#define PCA0MD_WDLCK__BMASK          0x20 ///< Watchdog Timer Lock                               
#define PCA0MD_WDLCK__SHIFT          0x05 ///< Watchdog Timer Lock                               
#define PCA0MD_WDLCK__UNLOCKED       0x00 ///< Watchdog Timer Enable unlocked.                   
#define PCA0MD_WDLCK__LOCKED         0x20 ///< Watchdog Timer Enable locked.                     
                                                                                                 
#define PCA0MD_WDTE__BMASK           0x40 ///< Watchdog Timer Enable                             
#define PCA0MD_WDTE__SHIFT           0x06 ///< Watchdog Timer Enable                             
#define PCA0MD_WDTE__DISABLED        0x00 ///< Disable Watchdog Timer.                           
#define PCA0MD_WDTE__ENABLED         0x40 ///< Enable PCA Module 5 as the Watchdog Timer.        
                                                                                                 
#define PCA0MD_CIDL__BMASK           0x80 ///< PCA Counter/Timer Idle Control                    
#define PCA0MD_CIDL__SHIFT           0x07 ///< PCA Counter/Timer Idle Control                    
#define PCA0MD_CIDL__NORMAL          0x00 ///< PCA continues to function normally while the      
                                          ///< system controller is in Idle Mode.                
#define PCA0MD_CIDL__SUSPEND         0x80 ///< PCA operation is suspended while the system       
                                          ///< controller is in Idle Mode.                       
                                                                                                 
//------------------------------------------------------------------------------
// PCA0PWM Enums (PCA PWM Configuration @ 0xD9)
//------------------------------------------------------------------------------
#define PCA0PWM_CLSEL__FMASK             0x03 ///< Cycle Length Select                              
#define PCA0PWM_CLSEL__SHIFT             0x00 ///< Cycle Length Select                              
#define PCA0PWM_CLSEL__8_BITS            0x00 ///< 8 bits.                                          
#define PCA0PWM_CLSEL__9_BITS            0x01 ///< 9 bits.                                          
#define PCA0PWM_CLSEL__10_BITS           0x02 ///< 10 bits.                                         
#define PCA0PWM_CLSEL__11_BITS           0x03 ///< 11 bits.                                         
                                                                                                    
#define PCA0PWM_COVF__BMASK              0x20 ///< Cycle Overflow Flag                              
#define PCA0PWM_COVF__SHIFT              0x05 ///< Cycle Overflow Flag                              
#define PCA0PWM_COVF__NO_OVERFLOW        0x00 ///< No overflow has occurred since the last time this
                                              ///< bit was cleared.                                 
#define PCA0PWM_COVF__OVERFLOW           0x20 ///< An overflow has occurred since the last time this
                                              ///< bit was cleared.                                 
                                                                                                    
#define PCA0PWM_ECOV__BMASK              0x40 ///< Cycle Overflow Interrupt Enable                  
#define PCA0PWM_ECOV__SHIFT              0x06 ///< Cycle Overflow Interrupt Enable                  
#define PCA0PWM_ECOV__COVF_MASK_DISABLED 0x00 ///< COVF will not generate PCA interrupts.           
#define PCA0PWM_ECOV__COVF_MASK_ENABLED  0x40 ///< A PCA interrupt will be generated when COVF is   
                                              ///< set.                                             
                                                                                                    
#define PCA0PWM_ARSEL__BMASK             0x80 ///< Auto-Reload Register Select                      
#define PCA0PWM_ARSEL__SHIFT             0x07 ///< Auto-Reload Register Select                      
#define PCA0PWM_ARSEL__CAPTURE_COMPARE   0x00 ///< Read/Write Capture/Compare Registers at PCA0CPHn 
                                              ///< and PCA0CPLn.                                    
#define PCA0PWM_ARSEL__AUTORELOAD        0x80 ///< Read/Write Auto-Reload Registers at PCA0CPHn and 
                                              ///< PCA0CPLn.                                        
                                                                                                    
//------------------------------------------------------------------------------
// PCA1CN Enums (PCA Control @ 0xD8)
//------------------------------------------------------------------------------
#define PCA1CN_CCF6__BMASK    0x01 ///< PCA Module 6 Capture/Compare Flag              
#define PCA1CN_CCF6__SHIFT    0x00 ///< PCA Module 6 Capture/Compare Flag              
#define PCA1CN_CCF6__NOT_SET  0x00 ///< A match or capture did not occur on Channel 6. 
#define PCA1CN_CCF6__SET      0x01 ///< A match or capture occurred on Channel 6.      
                                                                                       
#define PCA1CN_CCF7__BMASK    0x02 ///< PCA Module 7 Capture/Compare Flag              
#define PCA1CN_CCF7__SHIFT    0x01 ///< PCA Module 7 Capture/Compare Flag              
#define PCA1CN_CCF7__NOT_SET  0x00 ///< A match or capture did not occur on Channel 7. 
#define PCA1CN_CCF7__SET      0x02 ///< A match or capture occurred on Channel 7.      
                                                                                       
#define PCA1CN_CCF8__BMASK    0x04 ///< PCA Module 8 Capture/Compare Flag              
#define PCA1CN_CCF8__SHIFT    0x02 ///< PCA Module 8 Capture/Compare Flag              
#define PCA1CN_CCF8__NOT_SET  0x00 ///< A match or capture did not occur on Channel 8. 
#define PCA1CN_CCF8__SET      0x04 ///< A match or capture occurred on Channel 8.      
                                                                                       
#define PCA1CN_CCF9__BMASK    0x08 ///< PCA Module 9 Capture/Compare Flag              
#define PCA1CN_CCF9__SHIFT    0x03 ///< PCA Module 9 Capture/Compare Flag              
#define PCA1CN_CCF9__NOT_SET  0x00 ///< A match or capture did not occur on Channel 9. 
#define PCA1CN_CCF9__SET      0x08 ///< A match or capture occurred on Channel 9.      
                                                                                       
#define PCA1CN_CCF10__BMASK   0x10 ///< PCA Module 10 Capture/Compare Flag             
#define PCA1CN_CCF10__SHIFT   0x04 ///< PCA Module 10 Capture/Compare Flag             
#define PCA1CN_CCF10__NOT_SET 0x00 ///< A match or capture did not occur on Channel 10.
#define PCA1CN_CCF10__SET     0x10 ///< A match or capture occurred on Channel 10.     
                                                                                       
#define PCA1CN_CCF11__BMASK   0x20 ///< PCA Module 11 Capture/Compare Flag             
#define PCA1CN_CCF11__SHIFT   0x05 ///< PCA Module 11 Capture/Compare Flag             
#define PCA1CN_CCF11__NOT_SET 0x00 ///< A match or capture did not occur on Channel 11.
#define PCA1CN_CCF11__SET     0x20 ///< A match or capture occurred on Channel 11.     
                                                                                       
#define PCA1CN_CR__BMASK      0x40 ///< PCA Counter/Timer Run Control                  
#define PCA1CN_CR__SHIFT      0x06 ///< PCA Counter/Timer Run Control                  
#define PCA1CN_CR__STOP       0x00 ///< Stop the PCA Counter/Timer.                    
#define PCA1CN_CR__RUN        0x40 ///< Start the PCA Counter/Timer running.           
                                                                                       
#define PCA1CN_CF__BMASK      0x80 ///< PCA Counter/Timer Overflow Flag                
#define PCA1CN_CF__SHIFT      0x07 ///< PCA Counter/Timer Overflow Flag                
#define PCA1CN_CF__NOT_SET    0x00 ///< The PCA counter/timer did not overflow.        
#define PCA1CN_CF__SET        0x80 ///< The PCA counter/timer overflowed.              
                                                                                       
//------------------------------------------------------------------------------
// PCA1CPH10 Enums (PCA Channel 10 Capture Module High Byte @ 0xFE)
//------------------------------------------------------------------------------
#define PCA1CPH10_PCA1CPH10__FMASK 0xFF ///< PCA Channel 10 Capture Module High Byte
#define PCA1CPH10_PCA1CPH10__SHIFT 0x00 ///< PCA Channel 10 Capture Module High Byte
                                                                                    
//------------------------------------------------------------------------------
// PCA1CPH11 Enums (PCA Channel 11 Capture Module High Byte @ 0xCF)
//------------------------------------------------------------------------------
#define PCA1CPH11_PCA1CPH11__FMASK 0xFF ///< PCA Channel 11 Capture Module High Byte
#define PCA1CPH11_PCA1CPH11__SHIFT 0x00 ///< PCA Channel 11 Capture Module High Byte
                                                                                    
//------------------------------------------------------------------------------
// PCA1CPH6 Enums (PCA Channel 6 Capture Module High Byte @ 0xFC)
//------------------------------------------------------------------------------
#define PCA1CPH6_PCA1CPH6__FMASK 0xFF ///< PCA Channel 6 Capture Module High Byte
#define PCA1CPH6_PCA1CPH6__SHIFT 0x00 ///< PCA Channel 6 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA1CPH7 Enums (PCA Channel 7 Capture Module High Byte @ 0xEA)
//------------------------------------------------------------------------------
#define PCA1CPH7_PCA1CPH7__FMASK 0xFF ///< PCA Channel 7 Capture Module High Byte
#define PCA1CPH7_PCA1CPH7__SHIFT 0x00 ///< PCA Channel 7 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA1CPH8 Enums (PCA Channel 8 Capture Module High Byte @ 0xEC)
//------------------------------------------------------------------------------
#define PCA1CPH8_PCA1CPH8__FMASK 0xFF ///< PCA Channel 8 Capture Module High Byte
#define PCA1CPH8_PCA1CPH8__SHIFT 0x00 ///< PCA Channel 8 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA1CPH9 Enums (PCA Channel 9 Capture Module High Byte @ 0xEE)
//------------------------------------------------------------------------------
#define PCA1CPH9_PCA1CPH9__FMASK 0xFF ///< PCA Channel 9 Capture Module High Byte
#define PCA1CPH9_PCA1CPH9__SHIFT 0x00 ///< PCA Channel 9 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA1CPL10 Enums (PCA Channel 10 Capture Module Low Byte @ 0xFD)
//------------------------------------------------------------------------------
#define PCA1CPL10_PCA1CPL10__FMASK 0xFF ///< PCA Channel 10 Capture Module Low Byte
#define PCA1CPL10_PCA1CPL10__SHIFT 0x00 ///< PCA Channel 10 Capture Module Low Byte
                                                                                   
//------------------------------------------------------------------------------
// PCA1CPL11 Enums (PCA Channel 11 Capture Module Low Byte @ 0xCE)
//------------------------------------------------------------------------------
#define PCA1CPL11_PCA1CPL11__FMASK 0xFF ///< PCA Channel 11 Capture Module Low Byte
#define PCA1CPL11_PCA1CPL11__SHIFT 0x00 ///< PCA Channel 11 Capture Module Low Byte
                                                                                   
//------------------------------------------------------------------------------
// PCA1CPL6 Enums (PCA Channel 6 Capture Module Low Byte @ 0xFB)
//------------------------------------------------------------------------------
#define PCA1CPL6_PCA1CPL6__FMASK 0xFF ///< PCA Channel 6 Capture Module Low Byte
#define PCA1CPL6_PCA1CPL6__SHIFT 0x00 ///< PCA Channel 6 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA1CPL7 Enums (PCA Channel 7 Capture Module Low Byte @ 0xE9)
//------------------------------------------------------------------------------
#define PCA1CPL7_PCA1CPL7__FMASK 0xFF ///< PCA Channel 7 Capture Module Low Byte
#define PCA1CPL7_PCA1CPL7__SHIFT 0x00 ///< PCA Channel 7 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA1CPL8 Enums (PCA Channel 8 Capture Module Low Byte @ 0xEB)
//------------------------------------------------------------------------------
#define PCA1CPL8_PCA1CPL8__FMASK 0xFF ///< PCA Channel 8 Capture Module Low Byte
#define PCA1CPL8_PCA1CPL8__SHIFT 0x00 ///< PCA Channel 8 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA1CPL9 Enums (PCA Channel 9 Capture Module Low Byte @ 0xED)
//------------------------------------------------------------------------------
#define PCA1CPL9_PCA1CPL9__FMASK 0xFF ///< PCA Channel 9 Capture Module Low Byte
#define PCA1CPL9_PCA1CPL9__SHIFT 0x00 ///< PCA Channel 9 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA1CPM10 Enums (PCA Channel 10 Capture/Compare Mode @ 0xDE)
//------------------------------------------------------------------------------
#define PCA1CPM10_ECCF__BMASK    0x01 ///< Channel 10 Capture/Compare Flag Interrupt Enable
#define PCA1CPM10_ECCF__SHIFT    0x00 ///< Channel 10 Capture/Compare Flag Interrupt Enable
#define PCA1CPM10_ECCF__DISABLED 0x00 ///< Disable CCF10 interrupts.                       
#define PCA1CPM10_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request 
                                      ///< when CCF10 is set.                              
                                                                                           
#define PCA1CPM10_PWM__BMASK     0x02 ///< Channel 10 Pulse Width Modulation Mode Enable   
#define PCA1CPM10_PWM__SHIFT     0x01 ///< Channel 10 Pulse Width Modulation Mode Enable   
#define PCA1CPM10_PWM__DISABLED  0x00 ///< Disable PWM function.                           
#define PCA1CPM10_PWM__ENABLED   0x02 ///< Enable PWM function.                            
                                                                                           
#define PCA1CPM10_TOG__BMASK     0x04 ///< Channel 10 Toggle Function Enable               
#define PCA1CPM10_TOG__SHIFT     0x02 ///< Channel 10 Toggle Function Enable               
#define PCA1CPM10_TOG__DISABLED  0x00 ///< Disable toggle function.                        
#define PCA1CPM10_TOG__ENABLED   0x04 ///< Enable toggle function.                         
                                                                                           
#define PCA1CPM10_MAT__BMASK     0x08 ///< Channel 10 Match Function Enable                
#define PCA1CPM10_MAT__SHIFT     0x03 ///< Channel 10 Match Function Enable                
#define PCA1CPM10_MAT__DISABLED  0x00 ///< Disable match function.                         
#define PCA1CPM10_MAT__ENABLED   0x08 ///< Enable match function.                          
                                                                                           
#define PCA1CPM10_CAPN__BMASK    0x10 ///< Channel 10 Capture Negative Function Enable     
#define PCA1CPM10_CAPN__SHIFT    0x04 ///< Channel 10 Capture Negative Function Enable     
#define PCA1CPM10_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                  
#define PCA1CPM10_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                   
                                                                                           
#define PCA1CPM10_CAPP__BMASK    0x20 ///< Channel 10 Capture Positive Function Enable     
#define PCA1CPM10_CAPP__SHIFT    0x05 ///< Channel 10 Capture Positive Function Enable     
#define PCA1CPM10_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                  
#define PCA1CPM10_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                   
                                                                                           
#define PCA1CPM10_ECOM__BMASK    0x40 ///< Channel 10 Comparator Function Enable           
#define PCA1CPM10_ECOM__SHIFT    0x06 ///< Channel 10 Comparator Function Enable           
#define PCA1CPM10_ECOM__DISABLED 0x00 ///< Disable comparator function.                    
#define PCA1CPM10_ECOM__ENABLED  0x40 ///< Enable comparator function.                     
                                                                                           
#define PCA1CPM10_PWM16__BMASK   0x80 ///< Channel 10 16-bit Pulse Width Modulation Enable 
#define PCA1CPM10_PWM16__SHIFT   0x07 ///< Channel 10 16-bit Pulse Width Modulation Enable 
#define PCA1CPM10_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                       
#define PCA1CPM10_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                            
                                                                                           
//------------------------------------------------------------------------------
// PCA1CPM11 Enums (PCA Channel 11 Capture/Compare Mode @ 0xDF)
//------------------------------------------------------------------------------
#define PCA1CPM11_ECCF__BMASK    0x01 ///< Channel 11 Capture/Compare Flag Interrupt Enable
#define PCA1CPM11_ECCF__SHIFT    0x00 ///< Channel 11 Capture/Compare Flag Interrupt Enable
#define PCA1CPM11_ECCF__DISABLED 0x00 ///< Disable CCF11 interrupts.                       
#define PCA1CPM11_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request 
                                      ///< when CCF11 is set.                              
                                                                                           
#define PCA1CPM11_PWM__BMASK     0x02 ///< Channel 11 Pulse Width Modulation Mode Enable   
#define PCA1CPM11_PWM__SHIFT     0x01 ///< Channel 11 Pulse Width Modulation Mode Enable   
#define PCA1CPM11_PWM__DISABLED  0x00 ///< Disable PWM function.                           
#define PCA1CPM11_PWM__ENABLED   0x02 ///< Enable PWM function.                            
                                                                                           
#define PCA1CPM11_TOG__BMASK     0x04 ///< Channel 11 Toggle Function Enable               
#define PCA1CPM11_TOG__SHIFT     0x02 ///< Channel 11 Toggle Function Enable               
#define PCA1CPM11_TOG__DISABLED  0x00 ///< Disable toggle function.                        
#define PCA1CPM11_TOG__ENABLED   0x04 ///< Enable toggle function.                         
                                                                                           
#define PCA1CPM11_MAT__BMASK     0x08 ///< Channel 11 Match Function Enable                
#define PCA1CPM11_MAT__SHIFT     0x03 ///< Channel 11 Match Function Enable                
#define PCA1CPM11_MAT__DISABLED  0x00 ///< Disable match function.                         
#define PCA1CPM11_MAT__ENABLED   0x08 ///< Enable match function.                          
                                                                                           
#define PCA1CPM11_CAPN__BMASK    0x10 ///< Channel 11 Capture Negative Function Enable     
#define PCA1CPM11_CAPN__SHIFT    0x04 ///< Channel 11 Capture Negative Function Enable     
#define PCA1CPM11_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                  
#define PCA1CPM11_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                   
                                                                                           
#define PCA1CPM11_CAPP__BMASK    0x20 ///< Channel 11 Capture Positive Function Enable     
#define PCA1CPM11_CAPP__SHIFT    0x05 ///< Channel 11 Capture Positive Function Enable     
#define PCA1CPM11_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                  
#define PCA1CPM11_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                   
                                                                                           
#define PCA1CPM11_ECOM__BMASK    0x40 ///< Channel 11 Comparator Function Enable           
#define PCA1CPM11_ECOM__SHIFT    0x06 ///< Channel 11 Comparator Function Enable           
#define PCA1CPM11_ECOM__DISABLED 0x00 ///< Disable comparator function.                    
#define PCA1CPM11_ECOM__ENABLED  0x40 ///< Enable comparator function.                     
                                                                                           
#define PCA1CPM11_PWM16__BMASK   0x80 ///< Channel 11 16-bit Pulse Width Modulation Enable 
#define PCA1CPM11_PWM16__SHIFT   0x07 ///< Channel 11 16-bit Pulse Width Modulation Enable 
#define PCA1CPM11_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                       
#define PCA1CPM11_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                            
                                                                                           
//------------------------------------------------------------------------------
// PCA1CPM6 Enums (PCA Channel 6 Capture/Compare Mode @ 0xDA)
//------------------------------------------------------------------------------
#define PCA1CPM6_ECCF__BMASK    0x01 ///< Channel 6 Capture/Compare Flag Interrupt Enable
#define PCA1CPM6_ECCF__SHIFT    0x00 ///< Channel 6 Capture/Compare Flag Interrupt Enable
#define PCA1CPM6_ECCF__DISABLED 0x00 ///< Disable CCF6 interrupts.                       
#define PCA1CPM6_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request
                                     ///< when CCF6 is set.                              
                                                                                         
#define PCA1CPM6_PWM__BMASK     0x02 ///< Channel 6 Pulse Width Modulation Mode Enable   
#define PCA1CPM6_PWM__SHIFT     0x01 ///< Channel 6 Pulse Width Modulation Mode Enable   
#define PCA1CPM6_PWM__DISABLED  0x00 ///< Disable PWM function.                          
#define PCA1CPM6_PWM__ENABLED   0x02 ///< Enable PWM function.                           
                                                                                         
#define PCA1CPM6_TOG__BMASK     0x04 ///< Channel 6 Toggle Function Enable               
#define PCA1CPM6_TOG__SHIFT     0x02 ///< Channel 6 Toggle Function Enable               
#define PCA1CPM6_TOG__DISABLED  0x00 ///< Disable toggle function.                       
#define PCA1CPM6_TOG__ENABLED   0x04 ///< Enable toggle function.                        
                                                                                         
#define PCA1CPM6_MAT__BMASK     0x08 ///< Channel 6 Match Function Enable                
#define PCA1CPM6_MAT__SHIFT     0x03 ///< Channel 6 Match Function Enable                
#define PCA1CPM6_MAT__DISABLED  0x00 ///< Disable match function.                        
#define PCA1CPM6_MAT__ENABLED   0x08 ///< Enable match function.                         
                                                                                         
#define PCA1CPM6_CAPN__BMASK    0x10 ///< Channel 6 Capture Negative Function Enable     
#define PCA1CPM6_CAPN__SHIFT    0x04 ///< Channel 6 Capture Negative Function Enable     
#define PCA1CPM6_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                 
#define PCA1CPM6_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                  
                                                                                         
#define PCA1CPM6_CAPP__BMASK    0x20 ///< Channel 6 Capture Positive Function Enable     
#define PCA1CPM6_CAPP__SHIFT    0x05 ///< Channel 6 Capture Positive Function Enable     
#define PCA1CPM6_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                 
#define PCA1CPM6_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                  
                                                                                         
#define PCA1CPM6_ECOM__BMASK    0x40 ///< Channel 6 Comparator Function Enable           
#define PCA1CPM6_ECOM__SHIFT    0x06 ///< Channel 6 Comparator Function Enable           
#define PCA1CPM6_ECOM__DISABLED 0x00 ///< Disable comparator function.                   
#define PCA1CPM6_ECOM__ENABLED  0x40 ///< Enable comparator function.                    
                                                                                         
#define PCA1CPM6_PWM16__BMASK   0x80 ///< Channel 6 16-bit Pulse Width Modulation Enable 
#define PCA1CPM6_PWM16__SHIFT   0x07 ///< Channel 6 16-bit Pulse Width Modulation Enable 
#define PCA1CPM6_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                      
#define PCA1CPM6_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA1CPM7 Enums (PCA Channel 7 Capture/Compare Mode @ 0xDB)
//------------------------------------------------------------------------------
#define PCA1CPM7_ECCF__BMASK    0x01 ///< Channel 7 Capture/Compare Flag Interrupt Enable
#define PCA1CPM7_ECCF__SHIFT    0x00 ///< Channel 7 Capture/Compare Flag Interrupt Enable
#define PCA1CPM7_ECCF__DISABLED 0x00 ///< Disable CCF7 interrupts.                       
#define PCA1CPM7_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request
                                     ///< when CCF7 is set.                              
                                                                                         
#define PCA1CPM7_PWM__BMASK     0x02 ///< Channel 7 Pulse Width Modulation Mode Enable   
#define PCA1CPM7_PWM__SHIFT     0x01 ///< Channel 7 Pulse Width Modulation Mode Enable   
#define PCA1CPM7_PWM__DISABLED  0x00 ///< Disable PWM function.                          
#define PCA1CPM7_PWM__ENABLED   0x02 ///< Enable PWM function.                           
                                                                                         
#define PCA1CPM7_TOG__BMASK     0x04 ///< Channel 7 Toggle Function Enable               
#define PCA1CPM7_TOG__SHIFT     0x02 ///< Channel 7 Toggle Function Enable               
#define PCA1CPM7_TOG__DISABLED  0x00 ///< Disable toggle function.                       
#define PCA1CPM7_TOG__ENABLED   0x04 ///< Enable toggle function.                        
                                                                                         
#define PCA1CPM7_MAT__BMASK     0x08 ///< Channel 7 Match Function Enable                
#define PCA1CPM7_MAT__SHIFT     0x03 ///< Channel 7 Match Function Enable                
#define PCA1CPM7_MAT__DISABLED  0x00 ///< Disable match function.                        
#define PCA1CPM7_MAT__ENABLED   0x08 ///< Enable match function.                         
                                                                                         
#define PCA1CPM7_CAPN__BMASK    0x10 ///< Channel 7 Capture Negative Function Enable     
#define PCA1CPM7_CAPN__SHIFT    0x04 ///< Channel 7 Capture Negative Function Enable     
#define PCA1CPM7_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                 
#define PCA1CPM7_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                  
                                                                                         
#define PCA1CPM7_CAPP__BMASK    0x20 ///< Channel 7 Capture Positive Function Enable     
#define PCA1CPM7_CAPP__SHIFT    0x05 ///< Channel 7 Capture Positive Function Enable     
#define PCA1CPM7_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                 
#define PCA1CPM7_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                  
                                                                                         
#define PCA1CPM7_ECOM__BMASK    0x40 ///< Channel 7 Comparator Function Enable           
#define PCA1CPM7_ECOM__SHIFT    0x06 ///< Channel 7 Comparator Function Enable           
#define PCA1CPM7_ECOM__DISABLED 0x00 ///< Disable comparator function.                   
#define PCA1CPM7_ECOM__ENABLED  0x40 ///< Enable comparator function.                    
                                                                                         
#define PCA1CPM7_PWM16__BMASK   0x80 ///< Channel 7 16-bit Pulse Width Modulation Enable 
#define PCA1CPM7_PWM16__SHIFT   0x07 ///< Channel 7 16-bit Pulse Width Modulation Enable 
#define PCA1CPM7_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                      
#define PCA1CPM7_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA1CPM8 Enums (PCA Channel 8 Capture/Compare Mode @ 0xDC)
//------------------------------------------------------------------------------
#define PCA1CPM8_ECCF__BMASK    0x01 ///< Channel 8 Capture/Compare Flag Interrupt Enable
#define PCA1CPM8_ECCF__SHIFT    0x00 ///< Channel 8 Capture/Compare Flag Interrupt Enable
#define PCA1CPM8_ECCF__DISABLED 0x00 ///< Disable CCF8 interrupts.                       
#define PCA1CPM8_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request
                                     ///< when CCF8 is set.                              
                                                                                         
#define PCA1CPM8_PWM__BMASK     0x02 ///< Channel 8 Pulse Width Modulation Mode Enable   
#define PCA1CPM8_PWM__SHIFT     0x01 ///< Channel 8 Pulse Width Modulation Mode Enable   
#define PCA1CPM8_PWM__DISABLED  0x00 ///< Disable PWM function.                          
#define PCA1CPM8_PWM__ENABLED   0x02 ///< Enable PWM function.                           
                                                                                         
#define PCA1CPM8_TOG__BMASK     0x04 ///< Channel 8 Toggle Function Enable               
#define PCA1CPM8_TOG__SHIFT     0x02 ///< Channel 8 Toggle Function Enable               
#define PCA1CPM8_TOG__DISABLED  0x00 ///< Disable toggle function.                       
#define PCA1CPM8_TOG__ENABLED   0x04 ///< Enable toggle function.                        
                                                                                         
#define PCA1CPM8_MAT__BMASK     0x08 ///< Channel 8 Match Function Enable                
#define PCA1CPM8_MAT__SHIFT     0x03 ///< Channel 8 Match Function Enable                
#define PCA1CPM8_MAT__DISABLED  0x00 ///< Disable match function.                        
#define PCA1CPM8_MAT__ENABLED   0x08 ///< Enable match function.                         
                                                                                         
#define PCA1CPM8_CAPN__BMASK    0x10 ///< Channel 8 Capture Negative Function Enable     
#define PCA1CPM8_CAPN__SHIFT    0x04 ///< Channel 8 Capture Negative Function Enable     
#define PCA1CPM8_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                 
#define PCA1CPM8_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                  
                                                                                         
#define PCA1CPM8_CAPP__BMASK    0x20 ///< Channel 8 Capture Positive Function Enable     
#define PCA1CPM8_CAPP__SHIFT    0x05 ///< Channel 8 Capture Positive Function Enable     
#define PCA1CPM8_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                 
#define PCA1CPM8_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                  
                                                                                         
#define PCA1CPM8_ECOM__BMASK    0x40 ///< Channel 8 Comparator Function Enable           
#define PCA1CPM8_ECOM__SHIFT    0x06 ///< Channel 8 Comparator Function Enable           
#define PCA1CPM8_ECOM__DISABLED 0x00 ///< Disable comparator function.                   
#define PCA1CPM8_ECOM__ENABLED  0x40 ///< Enable comparator function.                    
                                                                                         
#define PCA1CPM8_PWM16__BMASK   0x80 ///< Channel 8 16-bit Pulse Width Modulation Enable 
#define PCA1CPM8_PWM16__SHIFT   0x07 ///< Channel 8 16-bit Pulse Width Modulation Enable 
#define PCA1CPM8_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                      
#define PCA1CPM8_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA1CPM9 Enums (PCA Channel 9 Capture/Compare Mode @ 0xDD)
//------------------------------------------------------------------------------
#define PCA1CPM9_ECCF__BMASK    0x01 ///< Channel 9 Capture/Compare Flag Interrupt Enable
#define PCA1CPM9_ECCF__SHIFT    0x00 ///< Channel 9 Capture/Compare Flag Interrupt Enable
#define PCA1CPM9_ECCF__DISABLED 0x00 ///< Disable CCF9 interrupts.                       
#define PCA1CPM9_ECCF__ENABLED  0x01 ///< Enable a Capture/Compare Flag interrupt request
                                     ///< when CCF9 is set.                              
                                                                                         
#define PCA1CPM9_PWM__BMASK     0x02 ///< Channel 9 Pulse Width Modulation Mode Enable   
#define PCA1CPM9_PWM__SHIFT     0x01 ///< Channel 9 Pulse Width Modulation Mode Enable   
#define PCA1CPM9_PWM__DISABLED  0x00 ///< Disable PWM function.                          
#define PCA1CPM9_PWM__ENABLED   0x02 ///< Enable PWM function.                           
                                                                                         
#define PCA1CPM9_TOG__BMASK     0x04 ///< Channel 9 Toggle Function Enable               
#define PCA1CPM9_TOG__SHIFT     0x02 ///< Channel 9 Toggle Function Enable               
#define PCA1CPM9_TOG__DISABLED  0x00 ///< Disable toggle function.                       
#define PCA1CPM9_TOG__ENABLED   0x04 ///< Enable toggle function.                        
                                                                                         
#define PCA1CPM9_MAT__BMASK     0x08 ///< Channel 9 Match Function Enable                
#define PCA1CPM9_MAT__SHIFT     0x03 ///< Channel 9 Match Function Enable                
#define PCA1CPM9_MAT__DISABLED  0x00 ///< Disable match function.                        
#define PCA1CPM9_MAT__ENABLED   0x08 ///< Enable match function.                         
                                                                                         
#define PCA1CPM9_CAPN__BMASK    0x10 ///< Channel 9 Capture Negative Function Enable     
#define PCA1CPM9_CAPN__SHIFT    0x04 ///< Channel 9 Capture Negative Function Enable     
#define PCA1CPM9_CAPN__DISABLED 0x00 ///< Disable negative edge capture.                 
#define PCA1CPM9_CAPN__ENABLED  0x10 ///< Enable negative edge capture.                  
                                                                                         
#define PCA1CPM9_CAPP__BMASK    0x20 ///< Channel 9 Capture Positive Function Enable     
#define PCA1CPM9_CAPP__SHIFT    0x05 ///< Channel 9 Capture Positive Function Enable     
#define PCA1CPM9_CAPP__DISABLED 0x00 ///< Disable positive edge capture.                 
#define PCA1CPM9_CAPP__ENABLED  0x20 ///< Enable positive edge capture.                  
                                                                                         
#define PCA1CPM9_ECOM__BMASK    0x40 ///< Channel 9 Comparator Function Enable           
#define PCA1CPM9_ECOM__SHIFT    0x06 ///< Channel 9 Comparator Function Enable           
#define PCA1CPM9_ECOM__DISABLED 0x00 ///< Disable comparator function.                   
#define PCA1CPM9_ECOM__ENABLED  0x40 ///< Enable comparator function.                    
                                                                                         
#define PCA1CPM9_PWM16__BMASK   0x80 ///< Channel 9 16-bit Pulse Width Modulation Enable 
#define PCA1CPM9_PWM16__SHIFT   0x07 ///< Channel 9 16-bit Pulse Width Modulation Enable 
#define PCA1CPM9_PWM16__8_BIT   0x00 ///< 8 to 11-bit PWM selected.                      
#define PCA1CPM9_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA1H Enums (PCA Counter/Timer High Byte @ 0xFA)
//------------------------------------------------------------------------------
#define PCA1H_PCA1H__FMASK 0xFF ///< PCA Counter/Timer High Byte
#define PCA1H_PCA1H__SHIFT 0x00 ///< PCA Counter/Timer High Byte
                                                                
//------------------------------------------------------------------------------
// PCA1L Enums (PCA Counter/Timer Low Byte @ 0xF9)
//------------------------------------------------------------------------------
#define PCA1L_PCA1L__FMASK 0xFF ///< PCA Counter/Timer Low Byte
#define PCA1L_PCA1L__SHIFT 0x00 ///< PCA Counter/Timer Low Byte
                                                               
//------------------------------------------------------------------------------
// PCA1MD Enums (PCA Mode @ 0xD9)
//------------------------------------------------------------------------------
#define PCA1MD_ECF__BMASK            0x01 ///< PCA Counter/Timer Overflow Interrupt Enable       
#define PCA1MD_ECF__SHIFT            0x00 ///< PCA Counter/Timer Overflow Interrupt Enable       
#define PCA1MD_ECF__OVF_INT_DISABLED 0x00 ///< Disable the CF interrupt.                         
#define PCA1MD_ECF__OVF_INT_ENABLED  0x01 ///< Enable a PCA Counter/Timer Overflow interrupt     
                                          ///< request when CF (PCA1CN.7) is set.                
                                                                                                 
#define PCA1MD_CPS__FMASK            0x0E ///< PCA Counter/Timer Pulse Select                    
#define PCA1MD_CPS__SHIFT            0x01 ///< PCA Counter/Timer Pulse Select                    
#define PCA1MD_CPS__SYSCLK_DIV_12    0x00 ///< System clock divided by 12.                       
#define PCA1MD_CPS__SYSCLK_DIV_4     0x02 ///< System clock divided by 4.                        
#define PCA1MD_CPS__T0_OVERFLOW      0x04 ///< Timer 0 overflow.                                 
#define PCA1MD_CPS__ECI              0x06 ///< High-to-low transitions on ECI (max rate = system 
                                          ///< clock divided by 4).                              
#define PCA1MD_CPS__SYSCLK           0x08 ///< System clock.                                     
#define PCA1MD_CPS__EXTOSC_DIV_8     0x0A ///< External clock divided by 8 (synchronized with the
                                          ///< system clock).                                    
#define PCA1MD_CPS__RTC_DIV_8        0x0C ///< RTC divided by 8.                                 
                                                                                                 
#define PCA1MD_WDLCK__BMASK          0x20 ///< Watchdog Timer Lock                               
#define PCA1MD_WDLCK__SHIFT          0x05 ///< Watchdog Timer Lock                               
#define PCA1MD_WDLCK__UNLOCKED       0x00 ///< Watchdog Timer Enable unlocked.                   
#define PCA1MD_WDLCK__LOCKED         0x20 ///< Watchdog Timer Enable locked.                     
                                                                                                 
#define PCA1MD_WDTE__BMASK           0x40 ///< Watchdog Timer Enable                             
#define PCA1MD_WDTE__SHIFT           0x06 ///< Watchdog Timer Enable                             
#define PCA1MD_WDTE__DISABLED        0x00 ///< Disable Watchdog Timer.                           
#define PCA1MD_WDTE__ENABLED         0x40 ///< Enable PCA Module 2 as the Watchdog Timer.        
                                                                                                 
#define PCA1MD_CIDL__BMASK           0x80 ///< PCA Counter/Timer Idle Control                    
#define PCA1MD_CIDL__SHIFT           0x07 ///< PCA Counter/Timer Idle Control                    
#define PCA1MD_CIDL__NORMAL          0x00 ///< PCA continues to function normally while the      
                                          ///< system controller is in Idle Mode.                
#define PCA1MD_CIDL__SUSPEND         0x80 ///< PCA operation is suspended while the system       
                                          ///< controller is in Idle Mode.                       
                                                                                                 
//------------------------------------------------------------------------------
// PCA1PWM Enums (PCA PWM Configuration @ 0xDA)
//------------------------------------------------------------------------------
#define PCA1PWM_CLSEL__FMASK             0x03 ///< Cycle Length Select                              
#define PCA1PWM_CLSEL__SHIFT             0x00 ///< Cycle Length Select                              
#define PCA1PWM_CLSEL__8_BITS            0x00 ///< 8 bits.                                          
#define PCA1PWM_CLSEL__9_BITS            0x01 ///< 9 bits.                                          
#define PCA1PWM_CLSEL__10_BITS           0x02 ///< 10 bits.                                         
#define PCA1PWM_CLSEL__11_BITS           0x03 ///< 11 bits.                                         
                                                                                                    
#define PCA1PWM_COVF__BMASK              0x20 ///< Cycle Overflow Flag                              
#define PCA1PWM_COVF__SHIFT              0x05 ///< Cycle Overflow Flag                              
#define PCA1PWM_COVF__NO_OVERFLOW        0x00 ///< No overflow has occurred since the last time this
                                              ///< bit was cleared.                                 
#define PCA1PWM_COVF__OVERFLOW           0x20 ///< An overflow has occurred since the last time this
                                              ///< bit was cleared.                                 
                                                                                                    
#define PCA1PWM_ECOV__BMASK              0x40 ///< Cycle Overflow Interrupt Enable                  
#define PCA1PWM_ECOV__SHIFT              0x06 ///< Cycle Overflow Interrupt Enable                  
#define PCA1PWM_ECOV__COVF_MASK_DISABLED 0x00 ///< COVF will not generate PCA interrupts.           
#define PCA1PWM_ECOV__COVF_MASK_ENABLED  0x40 ///< A PCA interrupt will be generated when COVF is   
                                              ///< set.                                             
                                                                                                    
#define PCA1PWM_ARSEL__BMASK             0x80 ///< Auto-Reload Register Select                      
#define PCA1PWM_ARSEL__SHIFT             0x07 ///< Auto-Reload Register Select                      
#define PCA1PWM_ARSEL__CAPTURE_COMPARE   0x00 ///< Read/Write Capture/Compare Registers at PCA1CPHn 
                                              ///< and PCA1CPLn.                                    
#define PCA1PWM_ARSEL__AUTORELOAD        0x80 ///< Read/Write Auto-Reload Registers at PCA1CPHn and 
                                              ///< PCA1CPLn.                                        
                                                                                                    
//------------------------------------------------------------------------------
// PCON Enums (Power Control @ 0x87)
//------------------------------------------------------------------------------
#define PCON_IDLE__BMASK  0x01 ///< Idle Mode Select                                
#define PCON_IDLE__SHIFT  0x00 ///< Idle Mode Select                                
#define PCON_IDLE__NORMAL 0x00 ///< Idle mode not activated.                        
#define PCON_IDLE__IDLE   0x01 ///< CPU goes into Idle mode (shuts off clock to CPU,
                               ///< but clocks to enabled peripherals are still     
                               ///< active).                                        
                                                                                    
#define PCON_STOP__BMASK  0x02 ///< Stop Mode Select                                
#define PCON_STOP__SHIFT  0x01 ///< Stop Mode Select                                
#define PCON_STOP__NORMAL 0x00 ///< Stop mode not activated.                        
#define PCON_STOP__STOP   0x02 ///< CPU goes into Stop mode (internal oscillator    
                               ///< stopped).                                       
                                                                                    
#define PCON_GF0__BMASK   0x04 ///< General Purpose Flag 0                          
#define PCON_GF0__SHIFT   0x02 ///< General Purpose Flag 0                          
#define PCON_GF0__NOT_SET 0x00 ///< The GF0 flag is not set. Clear the GF0 flag.    
#define PCON_GF0__SET     0x04 ///< The GF0 flag is set. Set the GF0 flag.          
                                                                                    
#define PCON_GF1__BMASK   0x08 ///< General Purpose Flag 1                          
#define PCON_GF1__SHIFT   0x03 ///< General Purpose Flag 1                          
#define PCON_GF1__NOT_SET 0x00 ///< The GF1 flag is not set. Clear the GF1 flag.    
#define PCON_GF1__SET     0x08 ///< The GF1 flag is set. Set the GF1 flag.          
                                                                                    
#define PCON_GF2__BMASK   0x10 ///< General Purpose Flag 2                          
#define PCON_GF2__SHIFT   0x04 ///< General Purpose Flag 2                          
#define PCON_GF2__NOT_SET 0x00 ///< The GF2 flag is not set. Clear the GF2 flag.    
#define PCON_GF2__SET     0x10 ///< The GF2 flag is set. Set the GF2 flag.          
                                                                                    
#define PCON_GF3__BMASK   0x20 ///< General Purpose Flag 3                          
#define PCON_GF3__SHIFT   0x05 ///< General Purpose Flag 3                          
#define PCON_GF3__NOT_SET 0x00 ///< The GF3 flag is not set. Clear the GF3 flag.    
#define PCON_GF3__SET     0x20 ///< The GF3 flag is set. Set the GF3 flag.          
                                                                                    
#define PCON_GF4__BMASK   0x40 ///< General Purpose Flag 4                          
#define PCON_GF4__SHIFT   0x06 ///< General Purpose Flag 4                          
#define PCON_GF4__NOT_SET 0x00 ///< The GF4 flag is not set. Clear the GF4 flag.    
#define PCON_GF4__SET     0x40 ///< The GF4 flag is set. Set the GF4 flag.          
                                                                                    
#define PCON_GF5__BMASK   0x80 ///< General Purpose Flag 5                          
#define PCON_GF5__SHIFT   0x07 ///< General Purpose Flag 5                          
#define PCON_GF5__NOT_SET 0x00 ///< The GF5 flag is not set. Clear the GF5 flag.    
#define PCON_GF5__SET     0x80 ///< The GF5 flag is set. Set the GF5 flag.          
                                                                                    
//------------------------------------------------------------------------------
// P0 Enums (Port 0 Pin Latch @ 0x80)
//------------------------------------------------------------------------------
#define P0_B0__BMASK 0x01 ///< Port 0 Bit 0 Latch                            
#define P0_B0__SHIFT 0x00 ///< Port 0 Bit 0 Latch                            
#define P0_B0__LOW   0x00 ///< P0.0 is low. Set P0.0 to drive low.           
#define P0_B0__HIGH  0x01 ///< P0.0 is high. Set P0.0 to drive or float high.
                                                                             
#define P0_B1__BMASK 0x02 ///< Port 0 Bit 1 Latch                            
#define P0_B1__SHIFT 0x01 ///< Port 0 Bit 1 Latch                            
#define P0_B1__LOW   0x00 ///< P0.1 is low. Set P0.1 to drive low.           
#define P0_B1__HIGH  0x02 ///< P0.1 is high. Set P0.1 to drive or float high.
                                                                             
#define P0_B2__BMASK 0x04 ///< Port 0 Bit 2 Latch                            
#define P0_B2__SHIFT 0x02 ///< Port 0 Bit 2 Latch                            
#define P0_B2__LOW   0x00 ///< P0.2 is low. Set P0.2 to drive low.           
#define P0_B2__HIGH  0x04 ///< P0.2 is high. Set P0.2 to drive or float high.
                                                                             
#define P0_B3__BMASK 0x08 ///< Port 0 Bit 3 Latch                            
#define P0_B3__SHIFT 0x03 ///< Port 0 Bit 3 Latch                            
#define P0_B3__LOW   0x00 ///< P0.3 is low. Set P0.3 to drive low.           
#define P0_B3__HIGH  0x08 ///< P0.3 is high. Set P0.3 to drive or float high.
                                                                             
#define P0_B4__BMASK 0x10 ///< Port 0 Bit 4 Latch                            
#define P0_B4__SHIFT 0x04 ///< Port 0 Bit 4 Latch                            
#define P0_B4__LOW   0x00 ///< P0.4 is low. Set P0.4 to drive low.           
#define P0_B4__HIGH  0x10 ///< P0.4 is high. Set P0.4 to drive or float high.
                                                                             
#define P0_B5__BMASK 0x20 ///< Port 0 Bit 5 Latch                            
#define P0_B5__SHIFT 0x05 ///< Port 0 Bit 5 Latch                            
#define P0_B5__LOW   0x00 ///< P0.5 is low. Set P0.5 to drive low.           
#define P0_B5__HIGH  0x20 ///< P0.5 is high. Set P0.5 to drive or float high.
                                                                             
#define P0_B6__BMASK 0x40 ///< Port 0 Bit 6 Latch                            
#define P0_B6__SHIFT 0x06 ///< Port 0 Bit 6 Latch                            
#define P0_B6__LOW   0x00 ///< P0.6 is low. Set P0.6 to drive low.           
#define P0_B6__HIGH  0x40 ///< P0.6 is high. Set P0.6 to drive or float high.
                                                                             
#define P0_B7__BMASK 0x80 ///< Port 0 Bit 7 Latch                            
#define P0_B7__SHIFT 0x07 ///< Port 0 Bit 7 Latch                            
#define P0_B7__LOW   0x00 ///< P0.7 is low. Set P0.7 to drive low.           
#define P0_B7__HIGH  0x80 ///< P0.7 is high. Set P0.7 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P0MASK Enums (Port 0 Mask @ 0xF2)
//------------------------------------------------------------------------------
#define P0MASK_B0__BMASK    0x01 ///< Port 0 Bit 0 Mask Value                           
#define P0MASK_B0__SHIFT    0x00 ///< Port 0 Bit 0 Mask Value                           
#define P0MASK_B0__IGNORED  0x00 ///< P0.0 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P0MASK_B0__COMPARED 0x01 ///< P0.0 pin logic value is compared to P0MAT.0.      
                                                                                        
#define P0MASK_B1__BMASK    0x02 ///< Port 0 Bit 1 Mask Value                           
#define P0MASK_B1__SHIFT    0x01 ///< Port 0 Bit 1 Mask Value                           
#define P0MASK_B1__IGNORED  0x00 ///< P0.1 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P0MASK_B1__COMPARED 0x02 ///< P0.1 pin logic value is compared to P0MAT.1.      
                                                                                        
#define P0MASK_B2__BMASK    0x04 ///< Port 0 Bit 2 Mask Value                           
#define P0MASK_B2__SHIFT    0x02 ///< Port 0 Bit 2 Mask Value                           
#define P0MASK_B2__IGNORED  0x00 ///< P0.2 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P0MASK_B2__COMPARED 0x04 ///< P0.2 pin logic value is compared to P0MAT.2.      
                                                                                        
#define P0MASK_B3__BMASK    0x08 ///< Port 0 Bit 3 Mask Value                           
#define P0MASK_B3__SHIFT    0x03 ///< Port 0 Bit 3 Mask Value                           
#define P0MASK_B3__IGNORED  0x00 ///< P0.3 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P0MASK_B3__COMPARED 0x08 ///< P0.3 pin logic value is compared to P0MAT.3.      
                                                                                        
#define P0MASK_B4__BMASK    0x10 ///< Port 0 Bit 4 Mask Value                           
#define P0MASK_B4__SHIFT    0x04 ///< Port 0 Bit 4 Mask Value                           
#define P0MASK_B4__IGNORED  0x00 ///< P0.4 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P0MASK_B4__COMPARED 0x10 ///< P0.4 pin logic value is compared to P0MAT.4.      
                                                                                        
#define P0MASK_B5__BMASK    0x20 ///< Port 0 Bit 5 Mask Value                           
#define P0MASK_B5__SHIFT    0x05 ///< Port 0 Bit 5 Mask Value                           
#define P0MASK_B5__IGNORED  0x00 ///< P0.5 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P0MASK_B5__COMPARED 0x20 ///< P0.5 pin logic value is compared to P0MAT.5.      
                                                                                        
#define P0MASK_B6__BMASK    0x40 ///< Port 0 Bit 6 Mask Value                           
#define P0MASK_B6__SHIFT    0x06 ///< Port 0 Bit 6 Mask Value                           
#define P0MASK_B6__IGNORED  0x00 ///< P0.6 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P0MASK_B6__COMPARED 0x40 ///< P0.6 pin logic value is compared to P0MAT.6.      
                                                                                        
#define P0MASK_B7__BMASK    0x80 ///< Port 0 Bit 7 Mask Value                           
#define P0MASK_B7__SHIFT    0x07 ///< Port 0 Bit 7 Mask Value                           
#define P0MASK_B7__IGNORED  0x00 ///< P0.7 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P0MASK_B7__COMPARED 0x80 ///< P0.7 pin logic value is compared to P0MAT.7.      
                                                                                        
//------------------------------------------------------------------------------
// P0MAT Enums (Port 0 Match @ 0xF1)
//------------------------------------------------------------------------------
#define P0MAT_B0__BMASK 0x01 ///< Port 0 Bit 0 Match Value                         
#define P0MAT_B0__SHIFT 0x00 ///< Port 0 Bit 0 Match Value                         
#define P0MAT_B0__LOW   0x00 ///< P0.0 pin logic value is compared with logic LOW. 
#define P0MAT_B0__HIGH  0x01 ///< P0.0 pin logic value is compared with logic HIGH.
                                                                                   
#define P0MAT_B1__BMASK 0x02 ///< Port 0 Bit 1 Match Value                         
#define P0MAT_B1__SHIFT 0x01 ///< Port 0 Bit 1 Match Value                         
#define P0MAT_B1__LOW   0x00 ///< P0.1 pin logic value is compared with logic LOW. 
#define P0MAT_B1__HIGH  0x02 ///< P0.1 pin logic value is compared with logic HIGH.
                                                                                   
#define P0MAT_B2__BMASK 0x04 ///< Port 0 Bit 2 Match Value                         
#define P0MAT_B2__SHIFT 0x02 ///< Port 0 Bit 2 Match Value                         
#define P0MAT_B2__LOW   0x00 ///< P0.2 pin logic value is compared with logic LOW. 
#define P0MAT_B2__HIGH  0x04 ///< P0.2 pin logic value is compared with logic HIGH.
                                                                                   
#define P0MAT_B3__BMASK 0x08 ///< Port 0 Bit 3 Match Value                         
#define P0MAT_B3__SHIFT 0x03 ///< Port 0 Bit 3 Match Value                         
#define P0MAT_B3__LOW   0x00 ///< P0.3 pin logic value is compared with logic LOW. 
#define P0MAT_B3__HIGH  0x08 ///< P0.3 pin logic value is compared with logic HIGH.
                                                                                   
#define P0MAT_B4__BMASK 0x10 ///< Port 0 Bit 4 Match Value                         
#define P0MAT_B4__SHIFT 0x04 ///< Port 0 Bit 4 Match Value                         
#define P0MAT_B4__LOW   0x00 ///< P0.4 pin logic value is compared with logic LOW. 
#define P0MAT_B4__HIGH  0x10 ///< P0.4 pin logic value is compared with logic HIGH.
                                                                                   
#define P0MAT_B5__BMASK 0x20 ///< Port 0 Bit 5 Match Value                         
#define P0MAT_B5__SHIFT 0x05 ///< Port 0 Bit 5 Match Value                         
#define P0MAT_B5__LOW   0x00 ///< P0.5 pin logic value is compared with logic LOW. 
#define P0MAT_B5__HIGH  0x20 ///< P0.5 pin logic value is compared with logic HIGH.
                                                                                   
#define P0MAT_B6__BMASK 0x40 ///< Port 0 Bit 6 Match Value                         
#define P0MAT_B6__SHIFT 0x06 ///< Port 0 Bit 6 Match Value                         
#define P0MAT_B6__LOW   0x00 ///< P0.6 pin logic value is compared with logic LOW. 
#define P0MAT_B6__HIGH  0x40 ///< P0.6 pin logic value is compared with logic HIGH.
                                                                                   
#define P0MAT_B7__BMASK 0x80 ///< Port 0 Bit 7 Match Value                         
#define P0MAT_B7__SHIFT 0x07 ///< Port 0 Bit 7 Match Value                         
#define P0MAT_B7__LOW   0x00 ///< P0.7 pin logic value is compared with logic LOW. 
#define P0MAT_B7__HIGH  0x80 ///< P0.7 pin logic value is compared with logic HIGH.
                                                                                   
//------------------------------------------------------------------------------
// P0MDIN Enums (Port 0 Input Mode @ 0xF1)
//------------------------------------------------------------------------------
#define P0MDIN_B0__BMASK   0x01 ///< Port 0 Bit 0 Input Mode                 
#define P0MDIN_B0__SHIFT   0x00 ///< Port 0 Bit 0 Input Mode                 
#define P0MDIN_B0__ANALOG  0x00 ///< P0.0 pin is configured for analog mode. 
#define P0MDIN_B0__DIGITAL 0x01 ///< P0.0 pin is configured for digital mode.
                                                                             
#define P0MDIN_B1__BMASK   0x02 ///< Port 0 Bit 1 Input Mode                 
#define P0MDIN_B1__SHIFT   0x01 ///< Port 0 Bit 1 Input Mode                 
#define P0MDIN_B1__ANALOG  0x00 ///< P0.1 pin is configured for analog mode. 
#define P0MDIN_B1__DIGITAL 0x02 ///< P0.1 pin is configured for digital mode.
                                                                             
#define P0MDIN_B2__BMASK   0x04 ///< Port 0 Bit 2 Input Mode                 
#define P0MDIN_B2__SHIFT   0x02 ///< Port 0 Bit 2 Input Mode                 
#define P0MDIN_B2__ANALOG  0x00 ///< P0.2 pin is configured for analog mode. 
#define P0MDIN_B2__DIGITAL 0x04 ///< P0.2 pin is configured for digital mode.
                                                                             
#define P0MDIN_B3__BMASK   0x08 ///< Port 0 Bit 3 Input Mode                 
#define P0MDIN_B3__SHIFT   0x03 ///< Port 0 Bit 3 Input Mode                 
#define P0MDIN_B3__ANALOG  0x00 ///< P0.3 pin is configured for analog mode. 
#define P0MDIN_B3__DIGITAL 0x08 ///< P0.3 pin is configured for digital mode.
                                                                             
#define P0MDIN_B4__BMASK   0x10 ///< Port 0 Bit 4 Input Mode                 
#define P0MDIN_B4__SHIFT   0x04 ///< Port 0 Bit 4 Input Mode                 
#define P0MDIN_B4__ANALOG  0x00 ///< P0.4 pin is configured for analog mode. 
#define P0MDIN_B4__DIGITAL 0x10 ///< P0.4 pin is configured for digital mode.
                                                                             
#define P0MDIN_B5__BMASK   0x20 ///< Port 0 Bit 5 Input Mode                 
#define P0MDIN_B5__SHIFT   0x05 ///< Port 0 Bit 5 Input Mode                 
#define P0MDIN_B5__ANALOG  0x00 ///< P0.5 pin is configured for analog mode. 
#define P0MDIN_B5__DIGITAL 0x20 ///< P0.5 pin is configured for digital mode.
                                                                             
#define P0MDIN_B6__BMASK   0x40 ///< Port 0 Bit 6 Input Mode                 
#define P0MDIN_B6__SHIFT   0x06 ///< Port 0 Bit 6 Input Mode                 
#define P0MDIN_B6__ANALOG  0x00 ///< P0.6 pin is configured for analog mode. 
#define P0MDIN_B6__DIGITAL 0x40 ///< P0.6 pin is configured for digital mode.
                                                                             
#define P0MDIN_B7__BMASK   0x80 ///< Port 0 Bit 7 Input Mode                 
#define P0MDIN_B7__SHIFT   0x07 ///< Port 0 Bit 7 Input Mode                 
#define P0MDIN_B7__ANALOG  0x00 ///< P0.7 pin is configured for analog mode. 
#define P0MDIN_B7__DIGITAL 0x80 ///< P0.7 pin is configured for digital mode.
                                                                             
//------------------------------------------------------------------------------
// P0MDOUT Enums (Port 0 Output Mode @ 0xA4)
//------------------------------------------------------------------------------
#define P0MDOUT_B0__BMASK      0x01 ///< Port 0 Bit 0 Output Mode  
#define P0MDOUT_B0__SHIFT      0x00 ///< Port 0 Bit 0 Output Mode  
#define P0MDOUT_B0__OPEN_DRAIN 0x00 ///< P0.0 output is open-drain.
#define P0MDOUT_B0__PUSH_PULL  0x01 ///< P0.0 output is push-pull. 
                                                                   
#define P0MDOUT_B1__BMASK      0x02 ///< Port 0 Bit 1 Output Mode  
#define P0MDOUT_B1__SHIFT      0x01 ///< Port 0 Bit 1 Output Mode  
#define P0MDOUT_B1__OPEN_DRAIN 0x00 ///< P0.1 output is open-drain.
#define P0MDOUT_B1__PUSH_PULL  0x02 ///< P0.1 output is push-pull. 
                                                                   
#define P0MDOUT_B2__BMASK      0x04 ///< Port 0 Bit 2 Output Mode  
#define P0MDOUT_B2__SHIFT      0x02 ///< Port 0 Bit 2 Output Mode  
#define P0MDOUT_B2__OPEN_DRAIN 0x00 ///< P0.2 output is open-drain.
#define P0MDOUT_B2__PUSH_PULL  0x04 ///< P0.2 output is push-pull. 
                                                                   
#define P0MDOUT_B3__BMASK      0x08 ///< Port 0 Bit 3 Output Mode  
#define P0MDOUT_B3__SHIFT      0x03 ///< Port 0 Bit 3 Output Mode  
#define P0MDOUT_B3__OPEN_DRAIN 0x00 ///< P0.3 output is open-drain.
#define P0MDOUT_B3__PUSH_PULL  0x08 ///< P0.3 output is push-pull. 
                                                                   
#define P0MDOUT_B4__BMASK      0x10 ///< Port 0 Bit 4 Output Mode  
#define P0MDOUT_B4__SHIFT      0x04 ///< Port 0 Bit 4 Output Mode  
#define P0MDOUT_B4__OPEN_DRAIN 0x00 ///< P0.4 output is open-drain.
#define P0MDOUT_B4__PUSH_PULL  0x10 ///< P0.4 output is push-pull. 
                                                                   
#define P0MDOUT_B5__BMASK      0x20 ///< Port 0 Bit 5 Output Mode  
#define P0MDOUT_B5__SHIFT      0x05 ///< Port 0 Bit 5 Output Mode  
#define P0MDOUT_B5__OPEN_DRAIN 0x00 ///< P0.5 output is open-drain.
#define P0MDOUT_B5__PUSH_PULL  0x20 ///< P0.5 output is push-pull. 
                                                                   
#define P0MDOUT_B6__BMASK      0x40 ///< Port 0 Bit 6 Output Mode  
#define P0MDOUT_B6__SHIFT      0x06 ///< Port 0 Bit 6 Output Mode  
#define P0MDOUT_B6__OPEN_DRAIN 0x00 ///< P0.6 output is open-drain.
#define P0MDOUT_B6__PUSH_PULL  0x40 ///< P0.6 output is push-pull. 
                                                                   
#define P0MDOUT_B7__BMASK      0x80 ///< Port 0 Bit 7 Output Mode  
#define P0MDOUT_B7__SHIFT      0x07 ///< Port 0 Bit 7 Output Mode  
#define P0MDOUT_B7__OPEN_DRAIN 0x00 ///< P0.7 output is open-drain.
#define P0MDOUT_B7__PUSH_PULL  0x80 ///< P0.7 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// P0SKIP Enums (Port 0 Skip @ 0xD4)
//------------------------------------------------------------------------------
#define P0SKIP_B0__BMASK       0x01 ///< Port 0 Bit 0 Skip                       
#define P0SKIP_B0__SHIFT       0x00 ///< Port 0 Bit 0 Skip                       
#define P0SKIP_B0__NOT_SKIPPED 0x00 ///< P0.0 pin is not skipped by the crossbar.
#define P0SKIP_B0__SKIPPED     0x01 ///< P0.0 pin is skipped by the crossbar.    
                                                                                 
#define P0SKIP_B1__BMASK       0x02 ///< Port 0 Bit 1 Skip                       
#define P0SKIP_B1__SHIFT       0x01 ///< Port 0 Bit 1 Skip                       
#define P0SKIP_B1__NOT_SKIPPED 0x00 ///< P0.1 pin is not skipped by the crossbar.
#define P0SKIP_B1__SKIPPED     0x02 ///< P0.1 pin is skipped by the crossbar.    
                                                                                 
#define P0SKIP_B2__BMASK       0x04 ///< Port 0 Bit 2 Skip                       
#define P0SKIP_B2__SHIFT       0x02 ///< Port 0 Bit 2 Skip                       
#define P0SKIP_B2__NOT_SKIPPED 0x00 ///< P0.2 pin is not skipped by the crossbar.
#define P0SKIP_B2__SKIPPED     0x04 ///< P0.2 pin is skipped by the crossbar.    
                                                                                 
#define P0SKIP_B3__BMASK       0x08 ///< Port 0 Bit 3 Skip                       
#define P0SKIP_B3__SHIFT       0x03 ///< Port 0 Bit 3 Skip                       
#define P0SKIP_B3__NOT_SKIPPED 0x00 ///< P0.3 pin is not skipped by the crossbar.
#define P0SKIP_B3__SKIPPED     0x08 ///< P0.3 pin is skipped by the crossbar.    
                                                                                 
#define P0SKIP_B4__BMASK       0x10 ///< Port 0 Bit 4 Skip                       
#define P0SKIP_B4__SHIFT       0x04 ///< Port 0 Bit 4 Skip                       
#define P0SKIP_B4__NOT_SKIPPED 0x00 ///< P0.4 pin is not skipped by the crossbar.
#define P0SKIP_B4__SKIPPED     0x10 ///< P0.4 pin is skipped by the crossbar.    
                                                                                 
#define P0SKIP_B5__BMASK       0x20 ///< Port 0 Bit 5 Skip                       
#define P0SKIP_B5__SHIFT       0x05 ///< Port 0 Bit 5 Skip                       
#define P0SKIP_B5__NOT_SKIPPED 0x00 ///< P0.5 pin is not skipped by the crossbar.
#define P0SKIP_B5__SKIPPED     0x20 ///< P0.5 pin is skipped by the crossbar.    
                                                                                 
#define P0SKIP_B6__BMASK       0x40 ///< Port 0 Bit 6 Skip                       
#define P0SKIP_B6__SHIFT       0x06 ///< Port 0 Bit 6 Skip                       
#define P0SKIP_B6__NOT_SKIPPED 0x00 ///< P0.6 pin is not skipped by the crossbar.
#define P0SKIP_B6__SKIPPED     0x40 ///< P0.6 pin is skipped by the crossbar.    
                                                                                 
#define P0SKIP_B7__BMASK       0x80 ///< Port 0 Bit 7 Skip                       
#define P0SKIP_B7__SHIFT       0x07 ///< Port 0 Bit 7 Skip                       
#define P0SKIP_B7__NOT_SKIPPED 0x00 ///< P0.7 pin is not skipped by the crossbar.
#define P0SKIP_B7__SKIPPED     0x80 ///< P0.7 pin is skipped by the crossbar.    
                                                                                 
//------------------------------------------------------------------------------
// P1 Enums (Port 1 Pin Latch @ 0x90)
//------------------------------------------------------------------------------
#define P1_B0__BMASK 0x01 ///< Port 1 Bit 0 Latch                            
#define P1_B0__SHIFT 0x00 ///< Port 1 Bit 0 Latch                            
#define P1_B0__LOW   0x00 ///< P1.0 is low. Set P1.0 to drive low.           
#define P1_B0__HIGH  0x01 ///< P1.0 is high. Set P1.0 to drive or float high.
                                                                             
#define P1_B1__BMASK 0x02 ///< Port 1 Bit 1 Latch                            
#define P1_B1__SHIFT 0x01 ///< Port 1 Bit 1 Latch                            
#define P1_B1__LOW   0x00 ///< P1.1 is low. Set P1.1 to drive low.           
#define P1_B1__HIGH  0x02 ///< P1.1 is high. Set P1.1 to drive or float high.
                                                                             
#define P1_B2__BMASK 0x04 ///< Port 1 Bit 2 Latch                            
#define P1_B2__SHIFT 0x02 ///< Port 1 Bit 2 Latch                            
#define P1_B2__LOW   0x00 ///< P1.2 is low. Set P1.2 to drive low.           
#define P1_B2__HIGH  0x04 ///< P1.2 is high. Set P1.2 to drive or float high.
                                                                             
#define P1_B3__BMASK 0x08 ///< Port 1 Bit 3 Latch                            
#define P1_B3__SHIFT 0x03 ///< Port 1 Bit 3 Latch                            
#define P1_B3__LOW   0x00 ///< P1.3 is low. Set P1.3 to drive low.           
#define P1_B3__HIGH  0x08 ///< P1.3 is high. Set P1.3 to drive or float high.
                                                                             
#define P1_B4__BMASK 0x10 ///< Port 1 Bit 4 Latch                            
#define P1_B4__SHIFT 0x04 ///< Port 1 Bit 4 Latch                            
#define P1_B4__LOW   0x00 ///< P1.4 is low. Set P1.4 to drive low.           
#define P1_B4__HIGH  0x10 ///< P1.4 is high. Set P1.4 to drive or float high.
                                                                             
#define P1_B5__BMASK 0x20 ///< Port 1 Bit 5 Latch                            
#define P1_B5__SHIFT 0x05 ///< Port 1 Bit 5 Latch                            
#define P1_B5__LOW   0x00 ///< P1.5 is low. Set P1.5 to drive low.           
#define P1_B5__HIGH  0x20 ///< P1.5 is high. Set P1.5 to drive or float high.
                                                                             
#define P1_B6__BMASK 0x40 ///< Port 1 Bit 6 Latch                            
#define P1_B6__SHIFT 0x06 ///< Port 1 Bit 6 Latch                            
#define P1_B6__LOW   0x00 ///< P1.6 is low. Set P1.6 to drive low.           
#define P1_B6__HIGH  0x40 ///< P1.6 is high. Set P1.6 to drive or float high.
                                                                             
#define P1_B7__BMASK 0x80 ///< Port 1 Bit 7 Latch                            
#define P1_B7__SHIFT 0x07 ///< Port 1 Bit 7 Latch                            
#define P1_B7__LOW   0x00 ///< P1.7 is low. Set P1.7 to drive low.           
#define P1_B7__HIGH  0x80 ///< P1.7 is high. Set P1.7 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P1MASK Enums (Port 1 Mask @ 0xF4)
//------------------------------------------------------------------------------
#define P1MASK_B0__BMASK    0x01 ///< Port 1 Bit 0 Mask Value                           
#define P1MASK_B0__SHIFT    0x00 ///< Port 1 Bit 0 Mask Value                           
#define P1MASK_B0__IGNORED  0x00 ///< P1.0 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P1MASK_B0__COMPARED 0x01 ///< P1.0 pin logic value is compared to P1MAT.0.      
                                                                                        
#define P1MASK_B1__BMASK    0x02 ///< Port 1 Bit 1 Mask Value                           
#define P1MASK_B1__SHIFT    0x01 ///< Port 1 Bit 1 Mask Value                           
#define P1MASK_B1__IGNORED  0x00 ///< P1.1 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P1MASK_B1__COMPARED 0x02 ///< P1.1 pin logic value is compared to P1MAT.1.      
                                                                                        
#define P1MASK_B2__BMASK    0x04 ///< Port 1 Bit 2 Mask Value                           
#define P1MASK_B2__SHIFT    0x02 ///< Port 1 Bit 2 Mask Value                           
#define P1MASK_B2__IGNORED  0x00 ///< P1.2 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P1MASK_B2__COMPARED 0x04 ///< P1.2 pin logic value is compared to P1MAT.2.      
                                                                                        
#define P1MASK_B3__BMASK    0x08 ///< Port 1 Bit 3 Mask Value                           
#define P1MASK_B3__SHIFT    0x03 ///< Port 1 Bit 3 Mask Value                           
#define P1MASK_B3__IGNORED  0x00 ///< P1.3 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P1MASK_B3__COMPARED 0x08 ///< P1.3 pin logic value is compared to P1MAT.3.      
                                                                                        
#define P1MASK_B4__BMASK    0x10 ///< Port 1 Bit 4 Mask Value                           
#define P1MASK_B4__SHIFT    0x04 ///< Port 1 Bit 4 Mask Value                           
#define P1MASK_B4__IGNORED  0x00 ///< P1.4 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P1MASK_B4__COMPARED 0x10 ///< P1.4 pin logic value is compared to P1MAT.4.      
                                                                                        
#define P1MASK_B5__BMASK    0x20 ///< Port 1 Bit 5 Mask Value                           
#define P1MASK_B5__SHIFT    0x05 ///< Port 1 Bit 5 Mask Value                           
#define P1MASK_B5__IGNORED  0x00 ///< P1.5 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P1MASK_B5__COMPARED 0x20 ///< P1.5 pin logic value is compared to P1MAT.5.      
                                                                                        
#define P1MASK_B6__BMASK    0x40 ///< Port 1 Bit 6 Mask Value                           
#define P1MASK_B6__SHIFT    0x06 ///< Port 1 Bit 6 Mask Value                           
#define P1MASK_B6__IGNORED  0x00 ///< P1.6 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P1MASK_B6__COMPARED 0x40 ///< P1.6 pin logic value is compared to P1MAT.6.      
                                                                                        
#define P1MASK_B7__BMASK    0x80 ///< Port 1 Bit 7 Mask Value                           
#define P1MASK_B7__SHIFT    0x07 ///< Port 1 Bit 7 Mask Value                           
#define P1MASK_B7__IGNORED  0x00 ///< P1.7 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P1MASK_B7__COMPARED 0x80 ///< P1.7 pin logic value is compared to P1MAT.7.      
                                                                                        
//------------------------------------------------------------------------------
// P1MAT Enums (Port 1 Match @ 0xF3)
//------------------------------------------------------------------------------
#define P1MAT_B0__BMASK 0x01 ///< Port 1 Bit 0 Match Value                         
#define P1MAT_B0__SHIFT 0x00 ///< Port 1 Bit 0 Match Value                         
#define P1MAT_B0__LOW   0x00 ///< P1.0 pin logic value is compared with logic LOW. 
#define P1MAT_B0__HIGH  0x01 ///< P1.0 pin logic value is compared with logic HIGH.
                                                                                   
#define P1MAT_B1__BMASK 0x02 ///< Port 1 Bit 1 Match Value                         
#define P1MAT_B1__SHIFT 0x01 ///< Port 1 Bit 1 Match Value                         
#define P1MAT_B1__LOW   0x00 ///< P1.1 pin logic value is compared with logic LOW. 
#define P1MAT_B1__HIGH  0x02 ///< P1.1 pin logic value is compared with logic HIGH.
                                                                                   
#define P1MAT_B2__BMASK 0x04 ///< Port 1 Bit 2 Match Value                         
#define P1MAT_B2__SHIFT 0x02 ///< Port 1 Bit 2 Match Value                         
#define P1MAT_B2__LOW   0x00 ///< P1.2 pin logic value is compared with logic LOW. 
#define P1MAT_B2__HIGH  0x04 ///< P1.2 pin logic value is compared with logic HIGH.
                                                                                   
#define P1MAT_B3__BMASK 0x08 ///< Port 1 Bit 3 Match Value                         
#define P1MAT_B3__SHIFT 0x03 ///< Port 1 Bit 3 Match Value                         
#define P1MAT_B3__LOW   0x00 ///< P1.3 pin logic value is compared with logic LOW. 
#define P1MAT_B3__HIGH  0x08 ///< P1.3 pin logic value is compared with logic HIGH.
                                                                                   
#define P1MAT_B4__BMASK 0x10 ///< Port 1 Bit 4 Match Value                         
#define P1MAT_B4__SHIFT 0x04 ///< Port 1 Bit 4 Match Value                         
#define P1MAT_B4__LOW   0x00 ///< P1.4 pin logic value is compared with logic LOW. 
#define P1MAT_B4__HIGH  0x10 ///< P1.4 pin logic value is compared with logic HIGH.
                                                                                   
#define P1MAT_B5__BMASK 0x20 ///< Port 1 Bit 5 Match Value                         
#define P1MAT_B5__SHIFT 0x05 ///< Port 1 Bit 5 Match Value                         
#define P1MAT_B5__LOW   0x00 ///< P1.5 pin logic value is compared with logic LOW. 
#define P1MAT_B5__HIGH  0x20 ///< P1.5 pin logic value is compared with logic HIGH.
                                                                                   
#define P1MAT_B6__BMASK 0x40 ///< Port 1 Bit 6 Match Value                         
#define P1MAT_B6__SHIFT 0x06 ///< Port 1 Bit 6 Match Value                         
#define P1MAT_B6__LOW   0x00 ///< P1.6 pin logic value is compared with logic LOW. 
#define P1MAT_B6__HIGH  0x40 ///< P1.6 pin logic value is compared with logic HIGH.
                                                                                   
#define P1MAT_B7__BMASK 0x80 ///< Port 1 Bit 7 Match Value                         
#define P1MAT_B7__SHIFT 0x07 ///< Port 1 Bit 7 Match Value                         
#define P1MAT_B7__LOW   0x00 ///< P1.7 pin logic value is compared with logic LOW. 
#define P1MAT_B7__HIGH  0x80 ///< P1.7 pin logic value is compared with logic HIGH.
                                                                                   
//------------------------------------------------------------------------------
// P1MDIN Enums (Port 1 Input Mode @ 0xF2)
//------------------------------------------------------------------------------
#define P1MDIN_B0__BMASK   0x01 ///< Port 1 Bit 0 Input Mode                 
#define P1MDIN_B0__SHIFT   0x00 ///< Port 1 Bit 0 Input Mode                 
#define P1MDIN_B0__ANALOG  0x00 ///< P1.0 pin is configured for analog mode. 
#define P1MDIN_B0__DIGITAL 0x01 ///< P1.0 pin is configured for digital mode.
                                                                             
#define P1MDIN_B1__BMASK   0x02 ///< Port 1 Bit 1 Input Mode                 
#define P1MDIN_B1__SHIFT   0x01 ///< Port 1 Bit 1 Input Mode                 
#define P1MDIN_B1__ANALOG  0x00 ///< P1.1 pin is configured for analog mode. 
#define P1MDIN_B1__DIGITAL 0x02 ///< P1.1 pin is configured for digital mode.
                                                                             
#define P1MDIN_B2__BMASK   0x04 ///< Port 1 Bit 2 Input Mode                 
#define P1MDIN_B2__SHIFT   0x02 ///< Port 1 Bit 2 Input Mode                 
#define P1MDIN_B2__ANALOG  0x00 ///< P1.2 pin is configured for analog mode. 
#define P1MDIN_B2__DIGITAL 0x04 ///< P1.2 pin is configured for digital mode.
                                                                             
#define P1MDIN_B3__BMASK   0x08 ///< Port 1 Bit 3 Input Mode                 
#define P1MDIN_B3__SHIFT   0x03 ///< Port 1 Bit 3 Input Mode                 
#define P1MDIN_B3__ANALOG  0x00 ///< P1.3 pin is configured for analog mode. 
#define P1MDIN_B3__DIGITAL 0x08 ///< P1.3 pin is configured for digital mode.
                                                                             
#define P1MDIN_B4__BMASK   0x10 ///< Port 1 Bit 4 Input Mode                 
#define P1MDIN_B4__SHIFT   0x04 ///< Port 1 Bit 4 Input Mode                 
#define P1MDIN_B4__ANALOG  0x00 ///< P1.4 pin is configured for analog mode. 
#define P1MDIN_B4__DIGITAL 0x10 ///< P1.4 pin is configured for digital mode.
                                                                             
#define P1MDIN_B5__BMASK   0x20 ///< Port 1 Bit 5 Input Mode                 
#define P1MDIN_B5__SHIFT   0x05 ///< Port 1 Bit 5 Input Mode                 
#define P1MDIN_B5__ANALOG  0x00 ///< P1.5 pin is configured for analog mode. 
#define P1MDIN_B5__DIGITAL 0x20 ///< P1.5 pin is configured for digital mode.
                                                                             
#define P1MDIN_B6__BMASK   0x40 ///< Port 1 Bit 6 Input Mode                 
#define P1MDIN_B6__SHIFT   0x06 ///< Port 1 Bit 6 Input Mode                 
#define P1MDIN_B6__ANALOG  0x00 ///< P1.6 pin is configured for analog mode. 
#define P1MDIN_B6__DIGITAL 0x40 ///< P1.6 pin is configured for digital mode.
                                                                             
#define P1MDIN_B7__BMASK   0x80 ///< Port 1 Bit 7 Input Mode                 
#define P1MDIN_B7__SHIFT   0x07 ///< Port 1 Bit 7 Input Mode                 
#define P1MDIN_B7__ANALOG  0x00 ///< P1.7 pin is configured for analog mode. 
#define P1MDIN_B7__DIGITAL 0x80 ///< P1.7 pin is configured for digital mode.
                                                                             
//------------------------------------------------------------------------------
// P1MDOUT Enums (Port 1 Output Mode @ 0xA5)
//------------------------------------------------------------------------------
#define P1MDOUT_B0__BMASK      0x01 ///< Port 1 Bit 0 Output Mode  
#define P1MDOUT_B0__SHIFT      0x00 ///< Port 1 Bit 0 Output Mode  
#define P1MDOUT_B0__OPEN_DRAIN 0x00 ///< P1.0 output is open-drain.
#define P1MDOUT_B0__PUSH_PULL  0x01 ///< P1.0 output is push-pull. 
                                                                   
#define P1MDOUT_B1__BMASK      0x02 ///< Port 1 Bit 1 Output Mode  
#define P1MDOUT_B1__SHIFT      0x01 ///< Port 1 Bit 1 Output Mode  
#define P1MDOUT_B1__OPEN_DRAIN 0x00 ///< P1.1 output is open-drain.
#define P1MDOUT_B1__PUSH_PULL  0x02 ///< P1.1 output is push-pull. 
                                                                   
#define P1MDOUT_B2__BMASK      0x04 ///< Port 1 Bit 2 Output Mode  
#define P1MDOUT_B2__SHIFT      0x02 ///< Port 1 Bit 2 Output Mode  
#define P1MDOUT_B2__OPEN_DRAIN 0x00 ///< P1.2 output is open-drain.
#define P1MDOUT_B2__PUSH_PULL  0x04 ///< P1.2 output is push-pull. 
                                                                   
#define P1MDOUT_B3__BMASK      0x08 ///< Port 1 Bit 3 Output Mode  
#define P1MDOUT_B3__SHIFT      0x03 ///< Port 1 Bit 3 Output Mode  
#define P1MDOUT_B3__OPEN_DRAIN 0x00 ///< P1.3 output is open-drain.
#define P1MDOUT_B3__PUSH_PULL  0x08 ///< P1.3 output is push-pull. 
                                                                   
#define P1MDOUT_B4__BMASK      0x10 ///< Port 1 Bit 4 Output Mode  
#define P1MDOUT_B4__SHIFT      0x04 ///< Port 1 Bit 4 Output Mode  
#define P1MDOUT_B4__OPEN_DRAIN 0x00 ///< P1.4 output is open-drain.
#define P1MDOUT_B4__PUSH_PULL  0x10 ///< P1.4 output is push-pull. 
                                                                   
#define P1MDOUT_B5__BMASK      0x20 ///< Port 1 Bit 5 Output Mode  
#define P1MDOUT_B5__SHIFT      0x05 ///< Port 1 Bit 5 Output Mode  
#define P1MDOUT_B5__OPEN_DRAIN 0x00 ///< P1.5 output is open-drain.
#define P1MDOUT_B5__PUSH_PULL  0x20 ///< P1.5 output is push-pull. 
                                                                   
#define P1MDOUT_B6__BMASK      0x40 ///< Port 1 Bit 6 Output Mode  
#define P1MDOUT_B6__SHIFT      0x06 ///< Port 1 Bit 6 Output Mode  
#define P1MDOUT_B6__OPEN_DRAIN 0x00 ///< P1.6 output is open-drain.
#define P1MDOUT_B6__PUSH_PULL  0x40 ///< P1.6 output is push-pull. 
                                                                   
#define P1MDOUT_B7__BMASK      0x80 ///< Port 1 Bit 7 Output Mode  
#define P1MDOUT_B7__SHIFT      0x07 ///< Port 1 Bit 7 Output Mode  
#define P1MDOUT_B7__OPEN_DRAIN 0x00 ///< P1.7 output is open-drain.
#define P1MDOUT_B7__PUSH_PULL  0x80 ///< P1.7 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// P1SKIP Enums (Port 1 Skip @ 0xD5)
//------------------------------------------------------------------------------
#define P1SKIP_B0__BMASK       0x01 ///< Port 1 Bit 0 Skip                       
#define P1SKIP_B0__SHIFT       0x00 ///< Port 1 Bit 0 Skip                       
#define P1SKIP_B0__NOT_SKIPPED 0x00 ///< P1.0 pin is not skipped by the crossbar.
#define P1SKIP_B0__SKIPPED     0x01 ///< P1.0 pin is skipped by the crossbar.    
                                                                                 
#define P1SKIP_B1__BMASK       0x02 ///< Port 1 Bit 1 Skip                       
#define P1SKIP_B1__SHIFT       0x01 ///< Port 1 Bit 1 Skip                       
#define P1SKIP_B1__NOT_SKIPPED 0x00 ///< P1.1 pin is not skipped by the crossbar.
#define P1SKIP_B1__SKIPPED     0x02 ///< P1.1 pin is skipped by the crossbar.    
                                                                                 
#define P1SKIP_B2__BMASK       0x04 ///< Port 1 Bit 2 Skip                       
#define P1SKIP_B2__SHIFT       0x02 ///< Port 1 Bit 2 Skip                       
#define P1SKIP_B2__NOT_SKIPPED 0x00 ///< P1.2 pin is not skipped by the crossbar.
#define P1SKIP_B2__SKIPPED     0x04 ///< P1.2 pin is skipped by the crossbar.    
                                                                                 
#define P1SKIP_B3__BMASK       0x08 ///< Port 1 Bit 3 Skip                       
#define P1SKIP_B3__SHIFT       0x03 ///< Port 1 Bit 3 Skip                       
#define P1SKIP_B3__NOT_SKIPPED 0x00 ///< P1.3 pin is not skipped by the crossbar.
#define P1SKIP_B3__SKIPPED     0x08 ///< P1.3 pin is skipped by the crossbar.    
                                                                                 
#define P1SKIP_B4__BMASK       0x10 ///< Port 1 Bit 4 Skip                       
#define P1SKIP_B4__SHIFT       0x04 ///< Port 1 Bit 4 Skip                       
#define P1SKIP_B4__NOT_SKIPPED 0x00 ///< P1.4 pin is not skipped by the crossbar.
#define P1SKIP_B4__SKIPPED     0x10 ///< P1.4 pin is skipped by the crossbar.    
                                                                                 
#define P1SKIP_B5__BMASK       0x20 ///< Port 1 Bit 5 Skip                       
#define P1SKIP_B5__SHIFT       0x05 ///< Port 1 Bit 5 Skip                       
#define P1SKIP_B5__NOT_SKIPPED 0x00 ///< P1.5 pin is not skipped by the crossbar.
#define P1SKIP_B5__SKIPPED     0x20 ///< P1.5 pin is skipped by the crossbar.    
                                                                                 
#define P1SKIP_B6__BMASK       0x40 ///< Port 1 Bit 6 Skip                       
#define P1SKIP_B6__SHIFT       0x06 ///< Port 1 Bit 6 Skip                       
#define P1SKIP_B6__NOT_SKIPPED 0x00 ///< P1.6 pin is not skipped by the crossbar.
#define P1SKIP_B6__SKIPPED     0x40 ///< P1.6 pin is skipped by the crossbar.    
                                                                                 
#define P1SKIP_B7__BMASK       0x80 ///< Port 1 Bit 7 Skip                       
#define P1SKIP_B7__SHIFT       0x07 ///< Port 1 Bit 7 Skip                       
#define P1SKIP_B7__NOT_SKIPPED 0x00 ///< P1.7 pin is not skipped by the crossbar.
#define P1SKIP_B7__SKIPPED     0x80 ///< P1.7 pin is skipped by the crossbar.    
                                                                                 
//------------------------------------------------------------------------------
// P2 Enums (Port 2 Pin Latch @ 0xA0)
//------------------------------------------------------------------------------
#define P2_B0__BMASK 0x01 ///< Port 2 Bit 0 Latch                            
#define P2_B0__SHIFT 0x00 ///< Port 2 Bit 0 Latch                            
#define P2_B0__LOW   0x00 ///< P2.0 is low. Set P2.0 to drive low.           
#define P2_B0__HIGH  0x01 ///< P2.0 is high. Set P2.0 to drive or float high.
                                                                             
#define P2_B1__BMASK 0x02 ///< Port 2 Bit 1 Latch                            
#define P2_B1__SHIFT 0x01 ///< Port 2 Bit 1 Latch                            
#define P2_B1__LOW   0x00 ///< P2.1 is low. Set P2.1 to drive low.           
#define P2_B1__HIGH  0x02 ///< P2.1 is high. Set P2.1 to drive or float high.
                                                                             
#define P2_B2__BMASK 0x04 ///< Port 2 Bit 2 Latch                            
#define P2_B2__SHIFT 0x02 ///< Port 2 Bit 2 Latch                            
#define P2_B2__LOW   0x00 ///< P2.2 is low. Set P2.2 to drive low.           
#define P2_B2__HIGH  0x04 ///< P2.2 is high. Set P2.2 to drive or float high.
                                                                             
#define P2_B3__BMASK 0x08 ///< Port 2 Bit 3 Latch                            
#define P2_B3__SHIFT 0x03 ///< Port 2 Bit 3 Latch                            
#define P2_B3__LOW   0x00 ///< P2.3 is low. Set P2.3 to drive low.           
#define P2_B3__HIGH  0x08 ///< P2.3 is high. Set P2.3 to drive or float high.
                                                                             
#define P2_B4__BMASK 0x10 ///< Port 2 Bit 4 Latch                            
#define P2_B4__SHIFT 0x04 ///< Port 2 Bit 4 Latch                            
#define P2_B4__LOW   0x00 ///< P2.4 is low. Set P2.4 to drive low.           
#define P2_B4__HIGH  0x10 ///< P2.4 is high. Set P2.4 to drive or float high.
                                                                             
#define P2_B5__BMASK 0x20 ///< Port 2 Bit 5 Latch                            
#define P2_B5__SHIFT 0x05 ///< Port 2 Bit 5 Latch                            
#define P2_B5__LOW   0x00 ///< P2.5 is low. Set P2.5 to drive low.           
#define P2_B5__HIGH  0x20 ///< P2.5 is high. Set P2.5 to drive or float high.
                                                                             
#define P2_B6__BMASK 0x40 ///< Port 2 Bit 6 Latch                            
#define P2_B6__SHIFT 0x06 ///< Port 2 Bit 6 Latch                            
#define P2_B6__LOW   0x00 ///< P2.6 is low. Set P2.6 to drive low.           
#define P2_B6__HIGH  0x40 ///< P2.6 is high. Set P2.6 to drive or float high.
                                                                             
#define P2_B7__BMASK 0x80 ///< Port 2 Bit 7 Latch                            
#define P2_B7__SHIFT 0x07 ///< Port 2 Bit 7 Latch                            
#define P2_B7__LOW   0x00 ///< P2.7 is low. Set P2.7 to drive low.           
#define P2_B7__HIGH  0x80 ///< P2.7 is high. Set P2.7 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P2MASK Enums (Port 2 Mask @ 0xB2)
//------------------------------------------------------------------------------
#define P2MASK_B0__BMASK    0x01 ///< Port 2 Bit 0 Mask Value                           
#define P2MASK_B0__SHIFT    0x00 ///< Port 2 Bit 0 Mask Value                           
#define P2MASK_B0__IGNORED  0x00 ///< P2.0 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P2MASK_B0__COMPARED 0x01 ///< P2.0 pin logic value is compared to P2MAT.0.      
                                                                                        
#define P2MASK_B1__BMASK    0x02 ///< Port 2 Bit 1 Mask Value                           
#define P2MASK_B1__SHIFT    0x01 ///< Port 2 Bit 1 Mask Value                           
#define P2MASK_B1__IGNORED  0x00 ///< P2.1 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P2MASK_B1__COMPARED 0x02 ///< P2.1 pin logic value is compared to P2MAT.1.      
                                                                                        
#define P2MASK_B2__BMASK    0x04 ///< Port 2 Bit 2 Mask Value                           
#define P2MASK_B2__SHIFT    0x02 ///< Port 2 Bit 2 Mask Value                           
#define P2MASK_B2__IGNORED  0x00 ///< P2.2 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P2MASK_B2__COMPARED 0x04 ///< P2.2 pin logic value is compared to P2MAT.2.      
                                                                                        
#define P2MASK_B3__BMASK    0x08 ///< Port 2 Bit 3 Mask Value                           
#define P2MASK_B3__SHIFT    0x03 ///< Port 2 Bit 3 Mask Value                           
#define P2MASK_B3__IGNORED  0x00 ///< P2.3 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P2MASK_B3__COMPARED 0x08 ///< P2.3 pin logic value is compared to P2MAT.3.      
                                                                                        
#define P2MASK_B4__BMASK    0x10 ///< Port 2 Bit 4 Mask Value                           
#define P2MASK_B4__SHIFT    0x04 ///< Port 2 Bit 4 Mask Value                           
#define P2MASK_B4__IGNORED  0x00 ///< P2.4 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P2MASK_B4__COMPARED 0x10 ///< P2.4 pin logic value is compared to P2MAT.4.      
                                                                                        
#define P2MASK_B5__BMASK    0x20 ///< Port 2 Bit 5 Mask Value                           
#define P2MASK_B5__SHIFT    0x05 ///< Port 2 Bit 5 Mask Value                           
#define P2MASK_B5__IGNORED  0x00 ///< P2.5 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P2MASK_B5__COMPARED 0x20 ///< P2.5 pin logic value is compared to P2MAT.5.      
                                                                                        
#define P2MASK_B6__BMASK    0x40 ///< Port 2 Bit 6 Mask Value                           
#define P2MASK_B6__SHIFT    0x06 ///< Port 2 Bit 6 Mask Value                           
#define P2MASK_B6__IGNORED  0x00 ///< P2.6 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P2MASK_B6__COMPARED 0x40 ///< P2.6 pin logic value is compared to P2MAT.6.      
                                                                                        
#define P2MASK_B7__BMASK    0x80 ///< Port 2 Bit 7 Mask Value                           
#define P2MASK_B7__SHIFT    0x07 ///< Port 2 Bit 7 Mask Value                           
#define P2MASK_B7__IGNORED  0x00 ///< P2.7 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P2MASK_B7__COMPARED 0x80 ///< P2.7 pin logic value is compared to P2MAT.7.      
                                                                                        
//------------------------------------------------------------------------------
// P2MAT Enums (Port 2 Match @ 0xB1)
//------------------------------------------------------------------------------
#define P2MAT_B0__BMASK 0x01 ///< Port 2 Bit 0 Match Value                         
#define P2MAT_B0__SHIFT 0x00 ///< Port 2 Bit 0 Match Value                         
#define P2MAT_B0__LOW   0x00 ///< P2.0 pin logic value is compared with logic LOW. 
#define P2MAT_B0__HIGH  0x01 ///< P2.0 pin logic value is compared with logic HIGH.
                                                                                   
#define P2MAT_B1__BMASK 0x02 ///< Port 2 Bit 1 Match Value                         
#define P2MAT_B1__SHIFT 0x01 ///< Port 2 Bit 1 Match Value                         
#define P2MAT_B1__LOW   0x00 ///< P2.1 pin logic value is compared with logic LOW. 
#define P2MAT_B1__HIGH  0x02 ///< P2.1 pin logic value is compared with logic HIGH.
                                                                                   
#define P2MAT_B2__BMASK 0x04 ///< Port 2 Bit 2 Match Value                         
#define P2MAT_B2__SHIFT 0x02 ///< Port 2 Bit 2 Match Value                         
#define P2MAT_B2__LOW   0x00 ///< P2.2 pin logic value is compared with logic LOW. 
#define P2MAT_B2__HIGH  0x04 ///< P2.2 pin logic value is compared with logic HIGH.
                                                                                   
#define P2MAT_B3__BMASK 0x08 ///< Port 2 Bit 3 Match Value                         
#define P2MAT_B3__SHIFT 0x03 ///< Port 2 Bit 3 Match Value                         
#define P2MAT_B3__LOW   0x00 ///< P2.3 pin logic value is compared with logic LOW. 
#define P2MAT_B3__HIGH  0x08 ///< P2.3 pin logic value is compared with logic HIGH.
                                                                                   
#define P2MAT_B4__BMASK 0x10 ///< Port 2 Bit 4 Match Value                         
#define P2MAT_B4__SHIFT 0x04 ///< Port 2 Bit 4 Match Value                         
#define P2MAT_B4__LOW   0x00 ///< P2.4 pin logic value is compared with logic LOW. 
#define P2MAT_B4__HIGH  0x10 ///< P2.4 pin logic value is compared with logic HIGH.
                                                                                   
#define P2MAT_B5__BMASK 0x20 ///< Port 2 Bit 5 Match Value                         
#define P2MAT_B5__SHIFT 0x05 ///< Port 2 Bit 5 Match Value                         
#define P2MAT_B5__LOW   0x00 ///< P2.5 pin logic value is compared with logic LOW. 
#define P2MAT_B5__HIGH  0x20 ///< P2.5 pin logic value is compared with logic HIGH.
                                                                                   
#define P2MAT_B6__BMASK 0x40 ///< Port 2 Bit 6 Match Value                         
#define P2MAT_B6__SHIFT 0x06 ///< Port 2 Bit 6 Match Value                         
#define P2MAT_B6__LOW   0x00 ///< P2.6 pin logic value is compared with logic LOW. 
#define P2MAT_B6__HIGH  0x40 ///< P2.6 pin logic value is compared with logic HIGH.
                                                                                   
#define P2MAT_B7__BMASK 0x80 ///< Port 2 Bit 7 Match Value                         
#define P2MAT_B7__SHIFT 0x07 ///< Port 2 Bit 7 Match Value                         
#define P2MAT_B7__LOW   0x00 ///< P2.7 pin logic value is compared with logic LOW. 
#define P2MAT_B7__HIGH  0x80 ///< P2.7 pin logic value is compared with logic HIGH.
                                                                                   
//------------------------------------------------------------------------------
// P2MDIN Enums (Port 2 Input Mode @ 0xF3)
//------------------------------------------------------------------------------
#define P2MDIN_B0__BMASK   0x01 ///< Port 2 Bit 0 Input Mode                 
#define P2MDIN_B0__SHIFT   0x00 ///< Port 2 Bit 0 Input Mode                 
#define P2MDIN_B0__ANALOG  0x00 ///< P2.0 pin is configured for analog mode. 
#define P2MDIN_B0__DIGITAL 0x01 ///< P2.0 pin is configured for digital mode.
                                                                             
#define P2MDIN_B1__BMASK   0x02 ///< Port 2 Bit 1 Input Mode                 
#define P2MDIN_B1__SHIFT   0x01 ///< Port 2 Bit 1 Input Mode                 
#define P2MDIN_B1__ANALOG  0x00 ///< P2.1 pin is configured for analog mode. 
#define P2MDIN_B1__DIGITAL 0x02 ///< P2.1 pin is configured for digital mode.
                                                                             
#define P2MDIN_B2__BMASK   0x04 ///< Port 2 Bit 2 Input Mode                 
#define P2MDIN_B2__SHIFT   0x02 ///< Port 2 Bit 2 Input Mode                 
#define P2MDIN_B2__ANALOG  0x00 ///< P2.2 pin is configured for analog mode. 
#define P2MDIN_B2__DIGITAL 0x04 ///< P2.2 pin is configured for digital mode.
                                                                             
#define P2MDIN_B3__BMASK   0x08 ///< Port 2 Bit 3 Input Mode                 
#define P2MDIN_B3__SHIFT   0x03 ///< Port 2 Bit 3 Input Mode                 
#define P2MDIN_B3__ANALOG  0x00 ///< P2.3 pin is configured for analog mode. 
#define P2MDIN_B3__DIGITAL 0x08 ///< P2.3 pin is configured for digital mode.
                                                                             
#define P2MDIN_B4__BMASK   0x10 ///< Port 2 Bit 4 Input Mode                 
#define P2MDIN_B4__SHIFT   0x04 ///< Port 2 Bit 4 Input Mode                 
#define P2MDIN_B4__ANALOG  0x00 ///< P2.4 pin is configured for analog mode. 
#define P2MDIN_B4__DIGITAL 0x10 ///< P2.4 pin is configured for digital mode.
                                                                             
#define P2MDIN_B5__BMASK   0x20 ///< Port 2 Bit 5 Input Mode                 
#define P2MDIN_B5__SHIFT   0x05 ///< Port 2 Bit 5 Input Mode                 
#define P2MDIN_B5__ANALOG  0x00 ///< P2.5 pin is configured for analog mode. 
#define P2MDIN_B5__DIGITAL 0x20 ///< P2.5 pin is configured for digital mode.
                                                                             
#define P2MDIN_B6__BMASK   0x40 ///< Port 2 Bit 6 Input Mode                 
#define P2MDIN_B6__SHIFT   0x06 ///< Port 2 Bit 6 Input Mode                 
#define P2MDIN_B6__ANALOG  0x00 ///< P2.6 pin is configured for analog mode. 
#define P2MDIN_B6__DIGITAL 0x40 ///< P2.6 pin is configured for digital mode.
                                                                             
#define P2MDIN_B7__BMASK   0x80 ///< Port 2 Bit 7 Input Mode                 
#define P2MDIN_B7__SHIFT   0x07 ///< Port 2 Bit 7 Input Mode                 
#define P2MDIN_B7__ANALOG  0x00 ///< P2.7 pin is configured for analog mode. 
#define P2MDIN_B7__DIGITAL 0x80 ///< P2.7 pin is configured for digital mode.
                                                                             
//------------------------------------------------------------------------------
// P2MDOUT Enums (Port 2 Output Mode @ 0xA6)
//------------------------------------------------------------------------------
#define P2MDOUT_B0__BMASK      0x01 ///< Port 2 Bit 0 Output Mode  
#define P2MDOUT_B0__SHIFT      0x00 ///< Port 2 Bit 0 Output Mode  
#define P2MDOUT_B0__OPEN_DRAIN 0x00 ///< P2.0 output is open-drain.
#define P2MDOUT_B0__PUSH_PULL  0x01 ///< P2.0 output is push-pull. 
                                                                   
#define P2MDOUT_B1__BMASK      0x02 ///< Port 2 Bit 1 Output Mode  
#define P2MDOUT_B1__SHIFT      0x01 ///< Port 2 Bit 1 Output Mode  
#define P2MDOUT_B1__OPEN_DRAIN 0x00 ///< P2.1 output is open-drain.
#define P2MDOUT_B1__PUSH_PULL  0x02 ///< P2.1 output is push-pull. 
                                                                   
#define P2MDOUT_B2__BMASK      0x04 ///< Port 2 Bit 2 Output Mode  
#define P2MDOUT_B2__SHIFT      0x02 ///< Port 2 Bit 2 Output Mode  
#define P2MDOUT_B2__OPEN_DRAIN 0x00 ///< P2.2 output is open-drain.
#define P2MDOUT_B2__PUSH_PULL  0x04 ///< P2.2 output is push-pull. 
                                                                   
#define P2MDOUT_B3__BMASK      0x08 ///< Port 2 Bit 3 Output Mode  
#define P2MDOUT_B3__SHIFT      0x03 ///< Port 2 Bit 3 Output Mode  
#define P2MDOUT_B3__OPEN_DRAIN 0x00 ///< P2.3 output is open-drain.
#define P2MDOUT_B3__PUSH_PULL  0x08 ///< P2.3 output is push-pull. 
                                                                   
#define P2MDOUT_B4__BMASK      0x10 ///< Port 2 Bit 4 Output Mode  
#define P2MDOUT_B4__SHIFT      0x04 ///< Port 2 Bit 4 Output Mode  
#define P2MDOUT_B4__OPEN_DRAIN 0x00 ///< P2.4 output is open-drain.
#define P2MDOUT_B4__PUSH_PULL  0x10 ///< P2.4 output is push-pull. 
                                                                   
#define P2MDOUT_B5__BMASK      0x20 ///< Port 2 Bit 5 Output Mode  
#define P2MDOUT_B5__SHIFT      0x05 ///< Port 2 Bit 5 Output Mode  
#define P2MDOUT_B5__OPEN_DRAIN 0x00 ///< P2.5 output is open-drain.
#define P2MDOUT_B5__PUSH_PULL  0x20 ///< P2.5 output is push-pull. 
                                                                   
#define P2MDOUT_B6__BMASK      0x40 ///< Port 2 Bit 6 Output Mode  
#define P2MDOUT_B6__SHIFT      0x06 ///< Port 2 Bit 6 Output Mode  
#define P2MDOUT_B6__OPEN_DRAIN 0x00 ///< P2.6 output is open-drain.
#define P2MDOUT_B6__PUSH_PULL  0x40 ///< P2.6 output is push-pull. 
                                                                   
#define P2MDOUT_B7__BMASK      0x80 ///< Port 2 Bit 7 Output Mode  
#define P2MDOUT_B7__SHIFT      0x07 ///< Port 2 Bit 7 Output Mode  
#define P2MDOUT_B7__OPEN_DRAIN 0x00 ///< P2.7 output is open-drain.
#define P2MDOUT_B7__PUSH_PULL  0x80 ///< P2.7 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// P2SKIP Enums (Port 2 Skip @ 0xD6)
//------------------------------------------------------------------------------
#define P2SKIP_B0__BMASK       0x01 ///< Port 2 Bit 0 Skip                       
#define P2SKIP_B0__SHIFT       0x00 ///< Port 2 Bit 0 Skip                       
#define P2SKIP_B0__NOT_SKIPPED 0x00 ///< P2.0 pin is not skipped by the crossbar.
#define P2SKIP_B0__SKIPPED     0x01 ///< P2.0 pin is skipped by the crossbar.    
                                                                                 
#define P2SKIP_B1__BMASK       0x02 ///< Port 2 Bit 1 Skip                       
#define P2SKIP_B1__SHIFT       0x01 ///< Port 2 Bit 1 Skip                       
#define P2SKIP_B1__NOT_SKIPPED 0x00 ///< P2.1 pin is not skipped by the crossbar.
#define P2SKIP_B1__SKIPPED     0x02 ///< P2.1 pin is skipped by the crossbar.    
                                                                                 
#define P2SKIP_B2__BMASK       0x04 ///< Port 2 Bit 2 Skip                       
#define P2SKIP_B2__SHIFT       0x02 ///< Port 2 Bit 2 Skip                       
#define P2SKIP_B2__NOT_SKIPPED 0x00 ///< P2.2 pin is not skipped by the crossbar.
#define P2SKIP_B2__SKIPPED     0x04 ///< P2.2 pin is skipped by the crossbar.    
                                                                                 
#define P2SKIP_B3__BMASK       0x08 ///< Port 2 Bit 3 Skip                       
#define P2SKIP_B3__SHIFT       0x03 ///< Port 2 Bit 3 Skip                       
#define P2SKIP_B3__NOT_SKIPPED 0x00 ///< P2.3 pin is not skipped by the crossbar.
#define P2SKIP_B3__SKIPPED     0x08 ///< P2.3 pin is skipped by the crossbar.    
                                                                                 
#define P2SKIP_B4__BMASK       0x10 ///< Port 2 Bit 4 Skip                       
#define P2SKIP_B4__SHIFT       0x04 ///< Port 2 Bit 4 Skip                       
#define P2SKIP_B4__NOT_SKIPPED 0x00 ///< P2.4 pin is not skipped by the crossbar.
#define P2SKIP_B4__SKIPPED     0x10 ///< P2.4 pin is skipped by the crossbar.    
                                                                                 
#define P2SKIP_B5__BMASK       0x20 ///< Port 2 Bit 5 Skip                       
#define P2SKIP_B5__SHIFT       0x05 ///< Port 2 Bit 5 Skip                       
#define P2SKIP_B5__NOT_SKIPPED 0x00 ///< P2.5 pin is not skipped by the crossbar.
#define P2SKIP_B5__SKIPPED     0x20 ///< P2.5 pin is skipped by the crossbar.    
                                                                                 
#define P2SKIP_B6__BMASK       0x40 ///< Port 2 Bit 6 Skip                       
#define P2SKIP_B6__SHIFT       0x06 ///< Port 2 Bit 6 Skip                       
#define P2SKIP_B6__NOT_SKIPPED 0x00 ///< P2.6 pin is not skipped by the crossbar.
#define P2SKIP_B6__SKIPPED     0x40 ///< P2.6 pin is skipped by the crossbar.    
                                                                                 
#define P2SKIP_B7__BMASK       0x80 ///< Port 2 Bit 7 Skip                       
#define P2SKIP_B7__SHIFT       0x07 ///< Port 2 Bit 7 Skip                       
#define P2SKIP_B7__NOT_SKIPPED 0x00 ///< P2.7 pin is not skipped by the crossbar.
#define P2SKIP_B7__SKIPPED     0x80 ///< P2.7 pin is skipped by the crossbar.    
                                                                                 
//------------------------------------------------------------------------------
// P3 Enums (Port 3 Pin Latch @ 0xB0)
//------------------------------------------------------------------------------
#define P3_B0__BMASK 0x01 ///< Port 3 Bit 0 Latch                            
#define P3_B0__SHIFT 0x00 ///< Port 3 Bit 0 Latch                            
#define P3_B0__LOW   0x00 ///< P3.0 is low. Set P3.0 to drive low.           
#define P3_B0__HIGH  0x01 ///< P3.0 is high. Set P3.0 to drive or float high.
                                                                             
#define P3_B1__BMASK 0x02 ///< Port 3 Bit 1 Latch                            
#define P3_B1__SHIFT 0x01 ///< Port 3 Bit 1 Latch                            
#define P3_B1__LOW   0x00 ///< P3.1 is low. Set P3.1 to drive low.           
#define P3_B1__HIGH  0x02 ///< P3.1 is high. Set P3.1 to drive or float high.
                                                                             
#define P3_B2__BMASK 0x04 ///< Port 3 Bit 2 Latch                            
#define P3_B2__SHIFT 0x02 ///< Port 3 Bit 2 Latch                            
#define P3_B2__LOW   0x00 ///< P3.2 is low. Set P3.2 to drive low.           
#define P3_B2__HIGH  0x04 ///< P3.2 is high. Set P3.2 to drive or float high.
                                                                             
#define P3_B3__BMASK 0x08 ///< Port 3 Bit 3 Latch                            
#define P3_B3__SHIFT 0x03 ///< Port 3 Bit 3 Latch                            
#define P3_B3__LOW   0x00 ///< P3.3 is low. Set P3.3 to drive low.           
#define P3_B3__HIGH  0x08 ///< P3.3 is high. Set P3.3 to drive or float high.
                                                                             
#define P3_B4__BMASK 0x10 ///< Port 3 Bit 4 Latch                            
#define P3_B4__SHIFT 0x04 ///< Port 3 Bit 4 Latch                            
#define P3_B4__LOW   0x00 ///< P3.4 is low. Set P3.4 to drive low.           
#define P3_B4__HIGH  0x10 ///< P3.4 is high. Set P3.4 to drive or float high.
                                                                             
#define P3_B5__BMASK 0x20 ///< Port 3 Bit 5 Latch                            
#define P3_B5__SHIFT 0x05 ///< Port 3 Bit 5 Latch                            
#define P3_B5__LOW   0x00 ///< P3.5 is low. Set P3.5 to drive low.           
#define P3_B5__HIGH  0x20 ///< P3.5 is high. Set P3.5 to drive or float high.
                                                                             
#define P3_B6__BMASK 0x40 ///< Port 3 Bit 6 Latch                            
#define P3_B6__SHIFT 0x06 ///< Port 3 Bit 6 Latch                            
#define P3_B6__LOW   0x00 ///< P3.6 is low. Set P3.6 to drive low.           
#define P3_B6__HIGH  0x40 ///< P3.6 is high. Set P3.6 to drive or float high.
                                                                             
#define P3_B7__BMASK 0x80 ///< Port 3 Bit 7 Latch                            
#define P3_B7__SHIFT 0x07 ///< Port 3 Bit 7 Latch                            
#define P3_B7__LOW   0x00 ///< P3.7 is low. Set P3.7 to drive low.           
#define P3_B7__HIGH  0x80 ///< P3.7 is high. Set P3.7 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P3MASK Enums (Port 3 Mask @ 0xAF)
//------------------------------------------------------------------------------
#define P3MASK_B0__BMASK    0x01 ///< Port 3 Bit 0 Mask Value                           
#define P3MASK_B0__SHIFT    0x00 ///< Port 3 Bit 0 Mask Value                           
#define P3MASK_B0__IGNORED  0x00 ///< P3.0 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P3MASK_B0__COMPARED 0x01 ///< P3.0 pin logic value is compared to P3MAT.0.      
                                                                                        
#define P3MASK_B1__BMASK    0x02 ///< Port 3 Bit 1 Mask Value                           
#define P3MASK_B1__SHIFT    0x01 ///< Port 3 Bit 1 Mask Value                           
#define P3MASK_B1__IGNORED  0x00 ///< P3.1 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P3MASK_B1__COMPARED 0x02 ///< P3.1 pin logic value is compared to P3MAT.1.      
                                                                                        
#define P3MASK_B2__BMASK    0x04 ///< Port 3 Bit 2 Mask Value                           
#define P3MASK_B2__SHIFT    0x02 ///< Port 3 Bit 2 Mask Value                           
#define P3MASK_B2__IGNORED  0x00 ///< P3.2 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P3MASK_B2__COMPARED 0x04 ///< P3.2 pin logic value is compared to P3MAT.2.      
                                                                                        
#define P3MASK_B3__BMASK    0x08 ///< Port 3 Bit 3 Mask Value                           
#define P3MASK_B3__SHIFT    0x03 ///< Port 3 Bit 3 Mask Value                           
#define P3MASK_B3__IGNORED  0x00 ///< P3.3 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P3MASK_B3__COMPARED 0x08 ///< P3.3 pin logic value is compared to P3MAT.3.      
                                                                                        
#define P3MASK_B4__BMASK    0x10 ///< Port 3 Bit 4 Mask Value                           
#define P3MASK_B4__SHIFT    0x04 ///< Port 3 Bit 4 Mask Value                           
#define P3MASK_B4__IGNORED  0x00 ///< P3.4 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P3MASK_B4__COMPARED 0x10 ///< P3.4 pin logic value is compared to P3MAT.4.      
                                                                                        
#define P3MASK_B5__BMASK    0x20 ///< Port 3 Bit 5 Mask Value                           
#define P3MASK_B5__SHIFT    0x05 ///< Port 3 Bit 5 Mask Value                           
#define P3MASK_B5__IGNORED  0x00 ///< P3.5 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P3MASK_B5__COMPARED 0x20 ///< P3.5 pin logic value is compared to P3MAT.5.      
                                                                                        
#define P3MASK_B6__BMASK    0x40 ///< Port 3 Bit 6 Mask Value                           
#define P3MASK_B6__SHIFT    0x06 ///< Port 3 Bit 6 Mask Value                           
#define P3MASK_B6__IGNORED  0x00 ///< P3.6 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P3MASK_B6__COMPARED 0x40 ///< P3.6 pin logic value is compared to P3MAT.6.      
                                                                                        
#define P3MASK_B7__BMASK    0x80 ///< Port 3 Bit 7 Mask Value                           
#define P3MASK_B7__SHIFT    0x07 ///< Port 3 Bit 7 Mask Value                           
#define P3MASK_B7__IGNORED  0x00 ///< P3.7 pin logic value is ignored and will not cause
                                 ///< a port mismatch event.                            
#define P3MASK_B7__COMPARED 0x80 ///< P3.7 pin logic value is compared to P3MAT.7.      
                                                                                        
//------------------------------------------------------------------------------
// P3MAT Enums (Port 3 Match @ 0xAE)
//------------------------------------------------------------------------------
#define P3MAT_B0__BMASK 0x01 ///< Port 3 Bit 0 Match Value                         
#define P3MAT_B0__SHIFT 0x00 ///< Port 3 Bit 0 Match Value                         
#define P3MAT_B0__LOW   0x00 ///< P3.0 pin logic value is compared with logic LOW. 
#define P3MAT_B0__HIGH  0x01 ///< P3.0 pin logic value is compared with logic HIGH.
                                                                                   
#define P3MAT_B1__BMASK 0x02 ///< Port 3 Bit 1 Match Value                         
#define P3MAT_B1__SHIFT 0x01 ///< Port 3 Bit 1 Match Value                         
#define P3MAT_B1__LOW   0x00 ///< P3.1 pin logic value is compared with logic LOW. 
#define P3MAT_B1__HIGH  0x02 ///< P3.1 pin logic value is compared with logic HIGH.
                                                                                   
#define P3MAT_B2__BMASK 0x04 ///< Port 3 Bit 2 Match Value                         
#define P3MAT_B2__SHIFT 0x02 ///< Port 3 Bit 2 Match Value                         
#define P3MAT_B2__LOW   0x00 ///< P3.2 pin logic value is compared with logic LOW. 
#define P3MAT_B2__HIGH  0x04 ///< P3.2 pin logic value is compared with logic HIGH.
                                                                                   
#define P3MAT_B3__BMASK 0x08 ///< Port 3 Bit 3 Match Value                         
#define P3MAT_B3__SHIFT 0x03 ///< Port 3 Bit 3 Match Value                         
#define P3MAT_B3__LOW   0x00 ///< P3.3 pin logic value is compared with logic LOW. 
#define P3MAT_B3__HIGH  0x08 ///< P3.3 pin logic value is compared with logic HIGH.
                                                                                   
#define P3MAT_B4__BMASK 0x10 ///< Port 3 Bit 4 Match Value                         
#define P3MAT_B4__SHIFT 0x04 ///< Port 3 Bit 4 Match Value                         
#define P3MAT_B4__LOW   0x00 ///< P3.4 pin logic value is compared with logic LOW. 
#define P3MAT_B4__HIGH  0x10 ///< P3.4 pin logic value is compared with logic HIGH.
                                                                                   
#define P3MAT_B5__BMASK 0x20 ///< Port 3 Bit 5 Match Value                         
#define P3MAT_B5__SHIFT 0x05 ///< Port 3 Bit 5 Match Value                         
#define P3MAT_B5__LOW   0x00 ///< P3.5 pin logic value is compared with logic LOW. 
#define P3MAT_B5__HIGH  0x20 ///< P3.5 pin logic value is compared with logic HIGH.
                                                                                   
#define P3MAT_B6__BMASK 0x40 ///< Port 3 Bit 6 Match Value                         
#define P3MAT_B6__SHIFT 0x06 ///< Port 3 Bit 6 Match Value                         
#define P3MAT_B6__LOW   0x00 ///< P3.6 pin logic value is compared with logic LOW. 
#define P3MAT_B6__HIGH  0x40 ///< P3.6 pin logic value is compared with logic HIGH.
                                                                                   
#define P3MAT_B7__BMASK 0x80 ///< Port 3 Bit 7 Match Value                         
#define P3MAT_B7__SHIFT 0x07 ///< Port 3 Bit 7 Match Value                         
#define P3MAT_B7__LOW   0x00 ///< P3.7 pin logic value is compared with logic LOW. 
#define P3MAT_B7__HIGH  0x80 ///< P3.7 pin logic value is compared with logic HIGH.
                                                                                   
//------------------------------------------------------------------------------
// P3MDIN Enums (Port 3 Input Mode @ 0xF4)
//------------------------------------------------------------------------------
#define P3MDIN_B0__BMASK   0x01 ///< Port 3 Bit 0 Input Mode                 
#define P3MDIN_B0__SHIFT   0x00 ///< Port 3 Bit 0 Input Mode                 
#define P3MDIN_B0__ANALOG  0x00 ///< P3.0 pin is configured for analog mode. 
#define P3MDIN_B0__DIGITAL 0x01 ///< P3.0 pin is configured for digital mode.
                                                                             
#define P3MDIN_B1__BMASK   0x02 ///< Port 3 Bit 1 Input Mode                 
#define P3MDIN_B1__SHIFT   0x01 ///< Port 3 Bit 1 Input Mode                 
#define P3MDIN_B1__ANALOG  0x00 ///< P3.1 pin is configured for analog mode. 
#define P3MDIN_B1__DIGITAL 0x02 ///< P3.1 pin is configured for digital mode.
                                                                             
#define P3MDIN_B2__BMASK   0x04 ///< Port 3 Bit 2 Input Mode                 
#define P3MDIN_B2__SHIFT   0x02 ///< Port 3 Bit 2 Input Mode                 
#define P3MDIN_B2__ANALOG  0x00 ///< P3.2 pin is configured for analog mode. 
#define P3MDIN_B2__DIGITAL 0x04 ///< P3.2 pin is configured for digital mode.
                                                                             
#define P3MDIN_B3__BMASK   0x08 ///< Port 3 Bit 3 Input Mode                 
#define P3MDIN_B3__SHIFT   0x03 ///< Port 3 Bit 3 Input Mode                 
#define P3MDIN_B3__ANALOG  0x00 ///< P3.3 pin is configured for analog mode. 
#define P3MDIN_B3__DIGITAL 0x08 ///< P3.3 pin is configured for digital mode.
                                                                             
#define P3MDIN_B4__BMASK   0x10 ///< Port 3 Bit 4 Input Mode                 
#define P3MDIN_B4__SHIFT   0x04 ///< Port 3 Bit 4 Input Mode                 
#define P3MDIN_B4__ANALOG  0x00 ///< P3.4 pin is configured for analog mode. 
#define P3MDIN_B4__DIGITAL 0x10 ///< P3.4 pin is configured for digital mode.
                                                                             
#define P3MDIN_B5__BMASK   0x20 ///< Port 3 Bit 5 Input Mode                 
#define P3MDIN_B5__SHIFT   0x05 ///< Port 3 Bit 5 Input Mode                 
#define P3MDIN_B5__ANALOG  0x00 ///< P3.5 pin is configured for analog mode. 
#define P3MDIN_B5__DIGITAL 0x20 ///< P3.5 pin is configured for digital mode.
                                                                             
#define P3MDIN_B6__BMASK   0x40 ///< Port 3 Bit 6 Input Mode                 
#define P3MDIN_B6__SHIFT   0x06 ///< Port 3 Bit 6 Input Mode                 
#define P3MDIN_B6__ANALOG  0x00 ///< P3.6 pin is configured for analog mode. 
#define P3MDIN_B6__DIGITAL 0x40 ///< P3.6 pin is configured for digital mode.
                                                                             
#define P3MDIN_B7__BMASK   0x80 ///< Port 3 Bit 7 Input Mode                 
#define P3MDIN_B7__SHIFT   0x07 ///< Port 3 Bit 7 Input Mode                 
#define P3MDIN_B7__ANALOG  0x00 ///< P3.7 pin is configured for analog mode. 
#define P3MDIN_B7__DIGITAL 0x80 ///< P3.7 pin is configured for digital mode.
                                                                             
//------------------------------------------------------------------------------
// P3MDOUT Enums (Port 3 Output Mode @ 0xAE)
//------------------------------------------------------------------------------
#define P3MDOUT_B0__BMASK      0x01 ///< Port 3 Bit 0 Output Mode  
#define P3MDOUT_B0__SHIFT      0x00 ///< Port 3 Bit 0 Output Mode  
#define P3MDOUT_B0__OPEN_DRAIN 0x00 ///< P3.0 output is open-drain.
#define P3MDOUT_B0__PUSH_PULL  0x01 ///< P3.0 output is push-pull. 
                                                                   
#define P3MDOUT_B1__BMASK      0x02 ///< Port 3 Bit 1 Output Mode  
#define P3MDOUT_B1__SHIFT      0x01 ///< Port 3 Bit 1 Output Mode  
#define P3MDOUT_B1__OPEN_DRAIN 0x00 ///< P3.1 output is open-drain.
#define P3MDOUT_B1__PUSH_PULL  0x02 ///< P3.1 output is push-pull. 
                                                                   
#define P3MDOUT_B2__BMASK      0x04 ///< Port 3 Bit 2 Output Mode  
#define P3MDOUT_B2__SHIFT      0x02 ///< Port 3 Bit 2 Output Mode  
#define P3MDOUT_B2__OPEN_DRAIN 0x00 ///< P3.2 output is open-drain.
#define P3MDOUT_B2__PUSH_PULL  0x04 ///< P3.2 output is push-pull. 
                                                                   
#define P3MDOUT_B3__BMASK      0x08 ///< Port 3 Bit 3 Output Mode  
#define P3MDOUT_B3__SHIFT      0x03 ///< Port 3 Bit 3 Output Mode  
#define P3MDOUT_B3__OPEN_DRAIN 0x00 ///< P3.3 output is open-drain.
#define P3MDOUT_B3__PUSH_PULL  0x08 ///< P3.3 output is push-pull. 
                                                                   
#define P3MDOUT_B4__BMASK      0x10 ///< Port 3 Bit 4 Output Mode  
#define P3MDOUT_B4__SHIFT      0x04 ///< Port 3 Bit 4 Output Mode  
#define P3MDOUT_B4__OPEN_DRAIN 0x00 ///< P3.4 output is open-drain.
#define P3MDOUT_B4__PUSH_PULL  0x10 ///< P3.4 output is push-pull. 
                                                                   
#define P3MDOUT_B5__BMASK      0x20 ///< Port 3 Bit 5 Output Mode  
#define P3MDOUT_B5__SHIFT      0x05 ///< Port 3 Bit 5 Output Mode  
#define P3MDOUT_B5__OPEN_DRAIN 0x00 ///< P3.5 output is open-drain.
#define P3MDOUT_B5__PUSH_PULL  0x20 ///< P3.5 output is push-pull. 
                                                                   
#define P3MDOUT_B6__BMASK      0x40 ///< Port 3 Bit 6 Output Mode  
#define P3MDOUT_B6__SHIFT      0x06 ///< Port 3 Bit 6 Output Mode  
#define P3MDOUT_B6__OPEN_DRAIN 0x00 ///< P3.6 output is open-drain.
#define P3MDOUT_B6__PUSH_PULL  0x40 ///< P3.6 output is push-pull. 
                                                                   
#define P3MDOUT_B7__BMASK      0x80 ///< Port 3 Bit 7 Output Mode  
#define P3MDOUT_B7__SHIFT      0x07 ///< Port 3 Bit 7 Output Mode  
#define P3MDOUT_B7__OPEN_DRAIN 0x00 ///< P3.7 output is open-drain.
#define P3MDOUT_B7__PUSH_PULL  0x80 ///< P3.7 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// P3SKIP Enums (Port 3 Skip @ 0xD7)
//------------------------------------------------------------------------------
#define P3SKIP_B0__BMASK       0x01 ///< Port 3 Bit 0 Skip                       
#define P3SKIP_B0__SHIFT       0x00 ///< Port 3 Bit 0 Skip                       
#define P3SKIP_B0__NOT_SKIPPED 0x00 ///< P3.0 pin is not skipped by the crossbar.
#define P3SKIP_B0__SKIPPED     0x01 ///< P3.0 pin is skipped by the crossbar.    
                                                                                 
#define P3SKIP_B1__BMASK       0x02 ///< Port 3 Bit 1 Skip                       
#define P3SKIP_B1__SHIFT       0x01 ///< Port 3 Bit 1 Skip                       
#define P3SKIP_B1__NOT_SKIPPED 0x00 ///< P3.1 pin is not skipped by the crossbar.
#define P3SKIP_B1__SKIPPED     0x02 ///< P3.1 pin is skipped by the crossbar.    
                                                                                 
#define P3SKIP_B2__BMASK       0x04 ///< Port 3 Bit 2 Skip                       
#define P3SKIP_B2__SHIFT       0x02 ///< Port 3 Bit 2 Skip                       
#define P3SKIP_B2__NOT_SKIPPED 0x00 ///< P3.2 pin is not skipped by the crossbar.
#define P3SKIP_B2__SKIPPED     0x04 ///< P3.2 pin is skipped by the crossbar.    
                                                                                 
#define P3SKIP_B3__BMASK       0x08 ///< Port 3 Bit 3 Skip                       
#define P3SKIP_B3__SHIFT       0x03 ///< Port 3 Bit 3 Skip                       
#define P3SKIP_B3__NOT_SKIPPED 0x00 ///< P3.3 pin is not skipped by the crossbar.
#define P3SKIP_B3__SKIPPED     0x08 ///< P3.3 pin is skipped by the crossbar.    
                                                                                 
#define P3SKIP_B4__BMASK       0x10 ///< Port 3 Bit 4 Skip                       
#define P3SKIP_B4__SHIFT       0x04 ///< Port 3 Bit 4 Skip                       
#define P3SKIP_B4__NOT_SKIPPED 0x00 ///< P3.4 pin is not skipped by the crossbar.
#define P3SKIP_B4__SKIPPED     0x10 ///< P3.4 pin is skipped by the crossbar.    
                                                                                 
#define P3SKIP_B5__BMASK       0x20 ///< Port 3 Bit 5 Skip                       
#define P3SKIP_B5__SHIFT       0x05 ///< Port 3 Bit 5 Skip                       
#define P3SKIP_B5__NOT_SKIPPED 0x00 ///< P3.5 pin is not skipped by the crossbar.
#define P3SKIP_B5__SKIPPED     0x20 ///< P3.5 pin is skipped by the crossbar.    
                                                                                 
#define P3SKIP_B6__BMASK       0x40 ///< Port 3 Bit 6 Skip                       
#define P3SKIP_B6__SHIFT       0x06 ///< Port 3 Bit 6 Skip                       
#define P3SKIP_B6__NOT_SKIPPED 0x00 ///< P3.6 pin is not skipped by the crossbar.
#define P3SKIP_B6__SKIPPED     0x40 ///< P3.6 pin is skipped by the crossbar.    
                                                                                 
#define P3SKIP_B7__BMASK       0x80 ///< Port 3 Bit 7 Skip                       
#define P3SKIP_B7__SHIFT       0x07 ///< Port 3 Bit 7 Skip                       
#define P3SKIP_B7__NOT_SKIPPED 0x00 ///< P3.7 pin is not skipped by the crossbar.
#define P3SKIP_B7__SKIPPED     0x80 ///< P3.7 pin is skipped by the crossbar.    
                                                                                 
//------------------------------------------------------------------------------
// P4 Enums (Port 4 Pin Latch @ 0xB5)
//------------------------------------------------------------------------------
#define P4_B0__BMASK 0x01 ///< Port 4 Bit 0 Latch                            
#define P4_B0__SHIFT 0x00 ///< Port 4 Bit 0 Latch                            
#define P4_B0__LOW   0x00 ///< P4.0 is low. Set P4.0 to drive low.           
#define P4_B0__HIGH  0x01 ///< P4.0 is high. Set P4.0 to drive or float high.
                                                                             
#define P4_B1__BMASK 0x02 ///< Port 4 Bit 1 Latch                            
#define P4_B1__SHIFT 0x01 ///< Port 4 Bit 1 Latch                            
#define P4_B1__LOW   0x00 ///< P4.1 is low. Set P4.1 to drive low.           
#define P4_B1__HIGH  0x02 ///< P4.1 is high. Set P4.1 to drive or float high.
                                                                             
#define P4_B2__BMASK 0x04 ///< Port 4 Bit 2 Latch                            
#define P4_B2__SHIFT 0x02 ///< Port 4 Bit 2 Latch                            
#define P4_B2__LOW   0x00 ///< P4.2 is low. Set P4.2 to drive low.           
#define P4_B2__HIGH  0x04 ///< P4.2 is high. Set P4.2 to drive or float high.
                                                                             
#define P4_B3__BMASK 0x08 ///< Port 4 Bit 3 Latch                            
#define P4_B3__SHIFT 0x03 ///< Port 4 Bit 3 Latch                            
#define P4_B3__LOW   0x00 ///< P4.3 is low. Set P4.3 to drive low.           
#define P4_B3__HIGH  0x08 ///< P4.3 is high. Set P4.3 to drive or float high.
                                                                             
#define P4_B4__BMASK 0x10 ///< Port 4 Bit 4 Latch                            
#define P4_B4__SHIFT 0x04 ///< Port 4 Bit 4 Latch                            
#define P4_B4__LOW   0x00 ///< P4.4 is low. Set P4.4 to drive low.           
#define P4_B4__HIGH  0x10 ///< P4.4 is high. Set P4.4 to drive or float high.
                                                                             
#define P4_B5__BMASK 0x20 ///< Port 4 Bit 5 Latch                            
#define P4_B5__SHIFT 0x05 ///< Port 4 Bit 5 Latch                            
#define P4_B5__LOW   0x00 ///< P4.5 is low. Set P4.5 to drive low.           
#define P4_B5__HIGH  0x20 ///< P4.5 is high. Set P4.5 to drive or float high.
                                                                             
#define P4_B6__BMASK 0x40 ///< Port 4 Bit 6 Latch                            
#define P4_B6__SHIFT 0x06 ///< Port 4 Bit 6 Latch                            
#define P4_B6__LOW   0x00 ///< P4.6 is low. Set P4.6 to drive low.           
#define P4_B6__HIGH  0x40 ///< P4.6 is high. Set P4.6 to drive or float high.
                                                                             
#define P4_B7__BMASK 0x80 ///< Port 4 Bit 7 Latch                            
#define P4_B7__SHIFT 0x07 ///< Port 4 Bit 7 Latch                            
#define P4_B7__LOW   0x00 ///< P4.7 is low. Set P4.7 to drive low.           
#define P4_B7__HIGH  0x80 ///< P4.7 is high. Set P4.7 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P4MDOUT Enums (Port 4 Output Mode @ 0xAF)
//------------------------------------------------------------------------------
#define P4MDOUT_B0__BMASK      0x01 ///< Port 4 Bit 0 Output Mode  
#define P4MDOUT_B0__SHIFT      0x00 ///< Port 4 Bit 0 Output Mode  
#define P4MDOUT_B0__OPEN_DRAIN 0x00 ///< P4.0 output is open-drain.
#define P4MDOUT_B0__PUSH_PULL  0x01 ///< P4.0 output is push-pull. 
                                                                   
#define P4MDOUT_B1__BMASK      0x02 ///< Port 4 Bit 1 Output Mode  
#define P4MDOUT_B1__SHIFT      0x01 ///< Port 4 Bit 1 Output Mode  
#define P4MDOUT_B1__OPEN_DRAIN 0x00 ///< P4.1 output is open-drain.
#define P4MDOUT_B1__PUSH_PULL  0x02 ///< P4.1 output is push-pull. 
                                                                   
#define P4MDOUT_B2__BMASK      0x04 ///< Port 4 Bit 2 Output Mode  
#define P4MDOUT_B2__SHIFT      0x02 ///< Port 4 Bit 2 Output Mode  
#define P4MDOUT_B2__OPEN_DRAIN 0x00 ///< P4.2 output is open-drain.
#define P4MDOUT_B2__PUSH_PULL  0x04 ///< P4.2 output is push-pull. 
                                                                   
#define P4MDOUT_B3__BMASK      0x08 ///< Port 4 Bit 3 Output Mode  
#define P4MDOUT_B3__SHIFT      0x03 ///< Port 4 Bit 3 Output Mode  
#define P4MDOUT_B3__OPEN_DRAIN 0x00 ///< P4.3 output is open-drain.
#define P4MDOUT_B3__PUSH_PULL  0x08 ///< P4.3 output is push-pull. 
                                                                   
#define P4MDOUT_B4__BMASK      0x10 ///< Port 4 Bit 4 Output Mode  
#define P4MDOUT_B4__SHIFT      0x04 ///< Port 4 Bit 4 Output Mode  
#define P4MDOUT_B4__OPEN_DRAIN 0x00 ///< P4.4 output is open-drain.
#define P4MDOUT_B4__PUSH_PULL  0x10 ///< P4.4 output is push-pull. 
                                                                   
#define P4MDOUT_B5__BMASK      0x20 ///< Port 4 Bit 5 Output Mode  
#define P4MDOUT_B5__SHIFT      0x05 ///< Port 4 Bit 5 Output Mode  
#define P4MDOUT_B5__OPEN_DRAIN 0x00 ///< P4.5 output is open-drain.
#define P4MDOUT_B5__PUSH_PULL  0x20 ///< P4.5 output is push-pull. 
                                                                   
#define P4MDOUT_B6__BMASK      0x40 ///< Port 4 Bit 6 Output Mode  
#define P4MDOUT_B6__SHIFT      0x06 ///< Port 4 Bit 6 Output Mode  
#define P4MDOUT_B6__OPEN_DRAIN 0x00 ///< P4.6 output is open-drain.
#define P4MDOUT_B6__PUSH_PULL  0x40 ///< P4.6 output is push-pull. 
                                                                   
#define P4MDOUT_B7__BMASK      0x80 ///< Port 4 Bit 7 Output Mode  
#define P4MDOUT_B7__SHIFT      0x07 ///< Port 4 Bit 7 Output Mode  
#define P4MDOUT_B7__OPEN_DRAIN 0x00 ///< P4.7 output is open-drain.
#define P4MDOUT_B7__PUSH_PULL  0x80 ///< P4.7 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// RSTSRC Enums (Reset Source @ 0xEF)
//------------------------------------------------------------------------------
#define RSTSRC_PINRSF__BMASK   0x01 ///< HW Pin Reset Flag                                                    
#define RSTSRC_PINRSF__SHIFT   0x00 ///< HW Pin Reset Flag                                                    
#define RSTSRC_PINRSF__NOT_SET 0x00 ///< The /RST pin did not cause the last reset.                           
#define RSTSRC_PINRSF__SET     0x01 ///< The /RST pin caused the last reset.                                  
                                                                                                              
#define RSTSRC_PORSF__BMASK    0x02 ///< Power-On / Supply Monitor Reset Flag, and Supply Monitor Reset Enable
#define RSTSRC_PORSF__SHIFT    0x01 ///< Power-On / Supply Monitor Reset Flag, and Supply Monitor Reset Enable
#define RSTSRC_PORSF__NOT_SET  0x00 ///< A power-on or supply monitor reset did not occur.                    
#define RSTSRC_PORSF__SET      0x02 ///< A power-on or supply monitor reset occurred.                         
                                                                                                              
#define RSTSRC_MCDRSF__BMASK   0x04 ///< Missing Clock Detector Enable and Flag                               
#define RSTSRC_MCDRSF__SHIFT   0x02 ///< Missing Clock Detector Enable and Flag                               
#define RSTSRC_MCDRSF__NOT_SET 0x00 ///< A missing clock detector reset did not occur.                        
#define RSTSRC_MCDRSF__SET     0x04 ///< A missing clock detector reset occurred.                             
                                                                                                              
#define RSTSRC_WDTRSF__BMASK   0x08 ///< Watchdog Timer Reset Flag                                            
#define RSTSRC_WDTRSF__SHIFT   0x03 ///< Watchdog Timer Reset Flag                                            
#define RSTSRC_WDTRSF__NOT_SET 0x00 ///< A watchdog timer overflow reset did not occur.                       
#define RSTSRC_WDTRSF__SET     0x08 ///< A watchdog timer overflow reset occurred.                            
                                                                                                              
#define RSTSRC_SWRSF__BMASK    0x10 ///< Software Reset Force and Flag                                        
#define RSTSRC_SWRSF__SHIFT    0x04 ///< Software Reset Force and Flag                                        
#define RSTSRC_SWRSF__NOT_SET  0x00 ///< A software reset did not occur.                                      
#define RSTSRC_SWRSF__SET      0x10 ///< A software reset occurred.                                           
                                                                                                              
#define RSTSRC_C0RSEF__BMASK   0x20 ///< Comparator0 Reset Enable and Flag                                    
#define RSTSRC_C0RSEF__SHIFT   0x05 ///< Comparator0 Reset Enable and Flag                                    
#define RSTSRC_C0RSEF__NOT_SET 0x00 ///< A Comparator 0 reset did not occur.                                  
#define RSTSRC_C0RSEF__SET     0x20 ///< A Comparator 0 reset occurred.                                       
                                                                                                              
#define RSTSRC_FERROR__BMASK   0x40 ///< Flash Error Reset Flag                                               
#define RSTSRC_FERROR__SHIFT   0x06 ///< Flash Error Reset Flag                                               
#define RSTSRC_FERROR__NOT_SET 0x00 ///< A flash error reset did not occur.                                   
#define RSTSRC_FERROR__SET     0x40 ///< A flash error reset occurred.                                        
                                                                                                              
//------------------------------------------------------------------------------
// SMB0CF Enums (SMBus 0 Configuration @ 0xC1)
//------------------------------------------------------------------------------
#define SMB0CF_SMBCS__FMASK             0x03 ///< SMBus Clock Source Selection                     
#define SMB0CF_SMBCS__SHIFT             0x00 ///< SMBus Clock Source Selection                     
#define SMB0CF_SMBCS__TIMER0            0x00 ///< Timer 0 Overflow.                                
#define SMB0CF_SMBCS__TIMER1            0x01 ///< Timer 1 Overflow.                                
#define SMB0CF_SMBCS__TIMER2_HIGH       0x02 ///< Timer 2 High Byte Overflow.                      
#define SMB0CF_SMBCS__TIMER2_LOW        0x03 ///< Timer 2 Low Byte Overflow.                       
                                                                                                   
#define SMB0CF_SMBFTE__BMASK            0x04 ///< SMBus Free Timeout Detection Enable              
#define SMB0CF_SMBFTE__SHIFT            0x02 ///< SMBus Free Timeout Detection Enable              
#define SMB0CF_SMBFTE__FREE_TO_DISABLED 0x00 ///< Disable bus free timeouts.                       
#define SMB0CF_SMBFTE__FREE_TO_ENABLED  0x04 ///< Enable bus free timeouts. The bus the bus will be
                                             ///< considered free if SCL and SDA remain high for   
                                             ///< more than 10 SMBus clock source periods.         
                                                                                                   
#define SMB0CF_SMBTOE__BMASK            0x08 ///< SMBus SCL Timeout Detection Enable               
#define SMB0CF_SMBTOE__SHIFT            0x03 ///< SMBus SCL Timeout Detection Enable               
#define SMB0CF_SMBTOE__SCL_TO_DISABLED  0x00 ///< Disable SCL low timeouts.                        
#define SMB0CF_SMBTOE__SCL_TO_ENABLED   0x08 ///< Enable SCL low timeouts.                         
                                                                                                   
#define SMB0CF_EXTHOLD__BMASK           0x10 ///< SMBus Setup and Hold Time Extension Enable       
#define SMB0CF_EXTHOLD__SHIFT           0x04 ///< SMBus Setup and Hold Time Extension Enable       
#define SMB0CF_EXTHOLD__DISABLED        0x00 ///< Disable SDA extended setup and hold times.       
#define SMB0CF_EXTHOLD__ENABLED         0x10 ///< Enable SDA extended setup and hold times.        
                                                                                                   
#define SMB0CF_BUSY__BMASK              0x20 ///< SMBus Busy Indicator                             
#define SMB0CF_BUSY__SHIFT              0x05 ///< SMBus Busy Indicator                             
#define SMB0CF_BUSY__NOT_SET            0x00 ///< The bus is not busy.                             
#define SMB0CF_BUSY__SET                0x20 ///< The bus is busy and a transfer is currently in   
                                             ///< progress.                                        
                                                                                                   
#define SMB0CF_INH__BMASK               0x40 ///< SMBus Slave Inhibit                              
#define SMB0CF_INH__SHIFT               0x06 ///< SMBus Slave Inhibit                              
#define SMB0CF_INH__SLAVE_ENABLED       0x00 ///< Slave states are enabled.                        
#define SMB0CF_INH__SLAVE_DISABLED      0x40 ///< Slave states are inhibited.                      
                                                                                                   
#define SMB0CF_ENSMB__BMASK             0x80 ///< SMBus Enable                                     
#define SMB0CF_ENSMB__SHIFT             0x07 ///< SMBus Enable                                     
#define SMB0CF_ENSMB__DISABLED          0x00 ///< Disable the SMBus module.                        
#define SMB0CF_ENSMB__ENABLED           0x80 ///< Enable the SMBus module.                         
                                                                                                   
//------------------------------------------------------------------------------
// SMB0CN Enums (SMBus 0 Control @ 0xC0)
//------------------------------------------------------------------------------
#define SMB0CN_SI__BMASK           0x01 ///< SMBus Interrupt Flag                           
#define SMB0CN_SI__SHIFT           0x00 ///< SMBus Interrupt Flag                           
#define SMB0CN_SI__NOT_SET         0x00 ///<                                                
#define SMB0CN_SI__SET             0x01 ///<                                                
                                                                                            
#define SMB0CN_ACK__BMASK          0x02 ///< SMBus Acknowledge                              
#define SMB0CN_ACK__SHIFT          0x01 ///< SMBus Acknowledge                              
#define SMB0CN_ACK__NOT_SET        0x00 ///< Generate a NACK, or the response was a NACK.   
#define SMB0CN_ACK__SET            0x02 ///< Generate an ACK, or the response was an ACK.   
                                                                                            
#define SMB0CN_ARBLOST__BMASK      0x04 ///< SMBus Arbitration Lost Indicator               
#define SMB0CN_ARBLOST__SHIFT      0x02 ///< SMBus Arbitration Lost Indicator               
#define SMB0CN_ARBLOST__NOT_SET    0x00 ///< No arbitration error.                          
#define SMB0CN_ARBLOST__ERROR      0x04 ///< Arbitration error occurred.                    
                                                                                            
#define SMB0CN_ACKRQ__BMASK        0x08 ///< SMBus Acknowledge Request                      
#define SMB0CN_ACKRQ__SHIFT        0x03 ///< SMBus Acknowledge Request                      
#define SMB0CN_ACKRQ__NOT_SET      0x00 ///< No ACK requested.                              
#define SMB0CN_ACKRQ__REQUESTED    0x08 ///< ACK requested.                                 
                                                                                            
#define SMB0CN_STO__BMASK          0x10 ///< SMBus Stop Flag                                
#define SMB0CN_STO__SHIFT          0x04 ///< SMBus Stop Flag                                
#define SMB0CN_STO__NOT_SET        0x00 ///< A STOP is not pending.                         
#define SMB0CN_STO__SET            0x10 ///< Generate a STOP or a STOP is currently pending.
                                                                                            
#define SMB0CN_STA__BMASK          0x20 ///< SMBus Start Flag                               
#define SMB0CN_STA__SHIFT          0x05 ///< SMBus Start Flag                               
#define SMB0CN_STA__NOT_SET        0x00 ///< A START was not detected.                      
#define SMB0CN_STA__SET            0x20 ///< Generate a START, repeated START, or a START is
                                        ///< currently pending.                             
                                                                                            
#define SMB0CN_TXMODE__BMASK       0x40 ///< SMBus Transmit Mode Indicator                  
#define SMB0CN_TXMODE__SHIFT       0x06 ///< SMBus Transmit Mode Indicator                  
#define SMB0CN_TXMODE__RECEIVER    0x00 ///< SMBus in Receiver Mode.                        
#define SMB0CN_TXMODE__TRANSMITTER 0x40 ///< SMBus in Transmitter Mode.                     
                                                                                            
#define SMB0CN_MASTER__BMASK       0x80 ///< SMBus Master/Slave Indicator                   
#define SMB0CN_MASTER__SHIFT       0x07 ///< SMBus Master/Slave Indicator                   
#define SMB0CN_MASTER__SLAVE       0x00 ///< SMBus operating in slave mode.                 
#define SMB0CN_MASTER__MASTER      0x80 ///< SMBus operating in master mode.                
                                                                                            
//------------------------------------------------------------------------------
// SMB0DAT Enums (SMBus 0 Data @ 0xC2)
//------------------------------------------------------------------------------
#define SMB0DAT_SMB0DAT__FMASK 0xFF ///< SMBus 0 Data
#define SMB0DAT_SMB0DAT__SHIFT 0x00 ///< SMBus 0 Data
                                                     
//------------------------------------------------------------------------------
// SPI0CFG Enums (SPI0 Configuration @ 0xA1)
//------------------------------------------------------------------------------
#define SPI0CFG_RXBMT__BMASK                0x01 ///< Receive Buffer Empty                              
#define SPI0CFG_RXBMT__SHIFT                0x00 ///< Receive Buffer Empty                              
#define SPI0CFG_RXBMT__NOT_SET              0x00 ///< New data is available in the receive buffer (Slave
                                                 ///< mode).                                            
#define SPI0CFG_RXBMT__SET                  0x01 ///< No new data in the receive buffer (Slave mode).   
                                                                                                        
#define SPI0CFG_SRMT__BMASK                 0x02 ///< Shift Register Empty                              
#define SPI0CFG_SRMT__SHIFT                 0x01 ///< Shift Register Empty                              
#define SPI0CFG_SRMT__NOT_SET               0x00 ///< The shift register is not empty.                  
#define SPI0CFG_SRMT__SET                   0x02 ///< The shift register is empty.                      
                                                                                                        
#define SPI0CFG_NSSIN__BMASK                0x04 ///< NSS Instantaneous Pin Input                       
#define SPI0CFG_NSSIN__SHIFT                0x02 ///< NSS Instantaneous Pin Input                       
#define SPI0CFG_NSSIN__LOW                  0x00 ///< The NSS pin is low.                               
#define SPI0CFG_NSSIN__HIGH                 0x04 ///< The NSS pin is high.                              
                                                                                                        
#define SPI0CFG_SLVSEL__BMASK               0x08 ///< Slave Selected Flag                               
#define SPI0CFG_SLVSEL__SHIFT               0x03 ///< Slave Selected Flag                               
#define SPI0CFG_SLVSEL__NOT_SELECTED        0x00 ///< The Slave is not selected (NSS is high).          
#define SPI0CFG_SLVSEL__SELECTED            0x08 ///< The Slave is selected (NSS is low).               
                                                                                                        
#define SPI0CFG_CKPOL__BMASK                0x10 ///< SPI0 Clock Polarity                               
#define SPI0CFG_CKPOL__SHIFT                0x04 ///< SPI0 Clock Polarity                               
#define SPI0CFG_CKPOL__IDLE_LOW             0x00 ///< SCK line low in idle state.                       
#define SPI0CFG_CKPOL__IDLE_HIGH            0x10 ///< SCK line high in idle state.                      
                                                                                                        
#define SPI0CFG_CKPHA__BMASK                0x20 ///< SPI0 Clock Phase                                  
#define SPI0CFG_CKPHA__SHIFT                0x05 ///< SPI0 Clock Phase                                  
#define SPI0CFG_CKPHA__DATA_CENTERED_FIRST  0x00 ///< Data centered on first edge of SCK period.        
#define SPI0CFG_CKPHA__DATA_CENTERED_SECOND 0x20 ///< Data centered on second edge of SCK period.       
                                                                                                        
#define SPI0CFG_MSTEN__BMASK                0x40 ///< Master Mode Enable                                
#define SPI0CFG_MSTEN__SHIFT                0x06 ///< Master Mode Enable                                
#define SPI0CFG_MSTEN__MASTER_DISABLED      0x00 ///< Disable master mode. Operate in slave mode.       
#define SPI0CFG_MSTEN__MASTER_ENABLED       0x40 ///< Enable master mode. Operate as a master.          
                                                                                                        
#define SPI0CFG_SPIBSY__BMASK               0x80 ///< SPI Busy                                          
#define SPI0CFG_SPIBSY__SHIFT               0x07 ///< SPI Busy                                          
#define SPI0CFG_SPIBSY__NOT_SET             0x00 ///< A SPI transfer is not in progress.                
#define SPI0CFG_SPIBSY__SET                 0x80 ///< A SPI transfer is in progress.                    
                                                                                                        
//------------------------------------------------------------------------------
// SPI0CKR Enums (SPI0 Clock Rate @ 0xA2)
//------------------------------------------------------------------------------
#define SPI0CKR_SPI0CKR__FMASK 0xFF ///< SPI0 Clock Rate
#define SPI0CKR_SPI0CKR__SHIFT 0x00 ///< SPI0 Clock Rate
                                                        
//------------------------------------------------------------------------------
// SPI0CN Enums (SPI0 Control @ 0xF8)
//------------------------------------------------------------------------------
#define SPI0CN_SPIEN__BMASK                  0x01 ///< SPI0 Enable                                       
#define SPI0CN_SPIEN__SHIFT                  0x00 ///< SPI0 Enable                                       
#define SPI0CN_SPIEN__DISABLED               0x00 ///< Disable the SPI module.                           
#define SPI0CN_SPIEN__ENABLED                0x01 ///< Enable the SPI module.                            
                                                                                                         
#define SPI0CN_TXBMT__BMASK                  0x02 ///< Transmit Buffer Empty                             
#define SPI0CN_TXBMT__SHIFT                  0x01 ///< Transmit Buffer Empty                             
#define SPI0CN_TXBMT__NOT_SET                0x00 ///< The transmit buffer is not empty.                 
#define SPI0CN_TXBMT__SET                    0x02 ///< The transmit buffer is empty.                     
                                                                                                         
#define SPI0CN_NSSMD__FMASK                  0x0C ///< Slave Select Mode                                 
#define SPI0CN_NSSMD__SHIFT                  0x02 ///< Slave Select Mode                                 
#define SPI0CN_NSSMD__3_WIRE                 0x00 ///< 3-Wire Slave or 3-Wire Master Mode. NSS signal is 
                                                  ///< not routed to a port pin.                         
#define SPI0CN_NSSMD__4_WIRE_SLAVE           0x04 ///< 4-Wire Slave or Multi-Master Mode. NSS is an input
                                                  ///< to the device.                                    
#define SPI0CN_NSSMD__4_WIRE_MASTER_NSS_LOW  0x08 ///< 4-Wire Single-Master Mode. NSS is an output and   
                                                  ///< logic low.                                        
#define SPI0CN_NSSMD__4_WIRE_MASTER_NSS_HIGH 0x0C ///< 4-Wire Single-Master Mode. NSS is an output and   
                                                  ///< logic high.                                       
                                                                                                         
#define SPI0CN_RXOVRN__BMASK                 0x10 ///< Receive Overrun Flag                              
#define SPI0CN_RXOVRN__SHIFT                 0x04 ///< Receive Overrun Flag                              
#define SPI0CN_RXOVRN__NOT_SET               0x00 ///< A receive overrun did not occur.                  
#define SPI0CN_RXOVRN__SET                   0x10 ///< A receive overrun occurred.                       
                                                                                                         
#define SPI0CN_MODF__BMASK                   0x20 ///< Mode Fault Flag                                   
#define SPI0CN_MODF__SHIFT                   0x05 ///< Mode Fault Flag                                   
#define SPI0CN_MODF__NOT_SET                 0x00 ///< A master collision did not occur.                 
#define SPI0CN_MODF__SET                     0x20 ///< A master collision occurred.                      
                                                                                                         
#define SPI0CN_WCOL__BMASK                   0x40 ///< Write Collision Flag                              
#define SPI0CN_WCOL__SHIFT                   0x06 ///< Write Collision Flag                              
#define SPI0CN_WCOL__NOT_SET                 0x00 ///< A write collision did not occur.                  
#define SPI0CN_WCOL__SET                     0x40 ///< A write collision occurred.                       
                                                                                                         
#define SPI0CN_SPIF__BMASK                   0x80 ///< SPI0 Interrupt Flag                               
#define SPI0CN_SPIF__SHIFT                   0x07 ///< SPI0 Interrupt Flag                               
#define SPI0CN_SPIF__NOT_SET                 0x00 ///< A data transfer has not completed since the last  
                                                  ///< time SPIF was cleared.                            
#define SPI0CN_SPIF__SET                     0x80 ///< A data transfer completed.                        
                                                                                                         
//------------------------------------------------------------------------------
// SPI0DAT Enums (SPI0 Data @ 0xA3)
//------------------------------------------------------------------------------
#define SPI0DAT_SPI0DAT__FMASK 0xFF ///< SPI0 Transmit and Receive Data
#define SPI0DAT_SPI0DAT__SHIFT 0x00 ///< SPI0 Transmit and Receive Data
                                                                       
//------------------------------------------------------------------------------
// TH0 Enums (Timer 0 High Byte @ 0x8C)
//------------------------------------------------------------------------------
#define TH0_TH0__FMASK 0xFF ///< Timer 0 High Byte
#define TH0_TH0__SHIFT 0x00 ///< Timer 0 High Byte
                                                  
//------------------------------------------------------------------------------
// TH1 Enums (Timer 1 High Byte @ 0x8D)
//------------------------------------------------------------------------------
#define TH1_TH1__FMASK 0xFF ///< Timer 1 High Byte
#define TH1_TH1__SHIFT 0x00 ///< Timer 1 High Byte
                                                  
//------------------------------------------------------------------------------
// TL0 Enums (Timer 0 Low Byte @ 0x8A)
//------------------------------------------------------------------------------
#define TL0_TL0__FMASK 0xFF ///< Timer 0 Low Byte
#define TL0_TL0__SHIFT 0x00 ///< Timer 0 Low Byte
                                                 
//------------------------------------------------------------------------------
// TL1 Enums (Timer 1 Low Byte @ 0x8B)
//------------------------------------------------------------------------------
#define TL1_TL1__FMASK 0xFF ///< Timer 1 Low Byte
#define TL1_TL1__SHIFT 0x00 ///< Timer 1 Low Byte
                                                 
//------------------------------------------------------------------------------
// TMR2CN Enums (Timer 2 Control @ 0xC8)
//------------------------------------------------------------------------------
#define TMR2CN_T2XCLK__BMASK          0x01 ///< Timer 2 External Clock Select                    
#define TMR2CN_T2XCLK__SHIFT          0x00 ///< Timer 2 External Clock Select                    
#define TMR2CN_T2XCLK__SYSCLK_DIV_12  0x00 ///< Timer 2 clock is the system clock divided by 12. 
#define TMR2CN_T2XCLK__EXTOSC_DIV_8   0x01 ///< Timer 2 clock is the external oscillator divided 
                                           ///< by 8 (synchronized with SYSCLK).                 
                                                                                                 
#define TMR2CN_TR2__BMASK             0x04 ///< Timer 2 Run Control                              
#define TMR2CN_TR2__SHIFT             0x02 ///< Timer 2 Run Control                              
#define TMR2CN_TR2__STOP              0x00 ///< Stop Timer 2.                                    
#define TMR2CN_TR2__RUN               0x04 ///< Start Timer 2 running.                           
                                                                                                 
#define TMR2CN_T2SPLIT__BMASK         0x08 ///< Timer 2 Split Mode Enable                        
#define TMR2CN_T2SPLIT__SHIFT         0x03 ///< Timer 2 Split Mode Enable                        
#define TMR2CN_T2SPLIT__16_BIT_RELOAD 0x00 ///< Timer 2 operates in 16-bit auto-reload mode.     
#define TMR2CN_T2SPLIT__8_BIT_RELOAD  0x08 ///< Timer 2 operates as two 8-bit auto-reload timers.
                                                                                                 
#define TMR2CN_TF2CEN__BMASK          0x10 ///< Timer 2 Capture Enable                           
#define TMR2CN_TF2CEN__SHIFT          0x04 ///< Timer 2 Capture Enable                           
#define TMR2CN_TF2CEN__DISABLED       0x00 ///< Disable capture mode.                            
#define TMR2CN_TF2CEN__ENABLED        0x10 ///< Enable capture mode.                             
                                                                                                 
#define TMR2CN_TF2LEN__BMASK          0x20 ///< Timer 2 Low Byte Interrupt Enable                
#define TMR2CN_TF2LEN__SHIFT          0x05 ///< Timer 2 Low Byte Interrupt Enable                
#define TMR2CN_TF2LEN__DISABLED       0x00 ///< Disable low byte interrupts.                     
#define TMR2CN_TF2LEN__ENABLED        0x20 ///< Enable low byte interrupts.                      
                                                                                                 
#define TMR2CN_TF2L__BMASK            0x40 ///< Timer 2 Low Byte Overflow Flag                   
#define TMR2CN_TF2L__SHIFT            0x06 ///< Timer 2 Low Byte Overflow Flag                   
#define TMR2CN_TF2L__NOT_SET          0x00 ///< Timer 2 low byte did not overflow.               
#define TMR2CN_TF2L__SET              0x40 ///< Timer 2 low byte overflowed.                     
                                                                                                 
#define TMR2CN_TF2H__BMASK            0x80 ///< Timer 2 High Byte Overflow Flag                  
#define TMR2CN_TF2H__SHIFT            0x07 ///< Timer 2 High Byte Overflow Flag                  
#define TMR2CN_TF2H__NOT_SET          0x00 ///< Timer 2 8-bit high byte or 16-bit value did not  
                                           ///< overflow.                                        
#define TMR2CN_TF2H__SET              0x80 ///< Timer 2 8-bit high byte or 16-bit value          
                                           ///< overflowed.                                      
                                                                                                 
//------------------------------------------------------------------------------
// TMR2H Enums (Timer 2 High Byte @ 0xCD)
//------------------------------------------------------------------------------
#define TMR2H_TMR2H__FMASK 0xFF ///< Timer 2 High Byte
#define TMR2H_TMR2H__SHIFT 0x00 ///< Timer 2 High Byte
                                                      
//------------------------------------------------------------------------------
// TMR2L Enums (Timer 2 Low Byte @ 0xCC)
//------------------------------------------------------------------------------
#define TMR2L_TMR2L__FMASK 0xFF ///< Timer 2 Low Byte
#define TMR2L_TMR2L__SHIFT 0x00 ///< Timer 2 Low Byte
                                                     
//------------------------------------------------------------------------------
// TMR2RLH Enums (Timer 2 Reload High Byte @ 0xCB)
//------------------------------------------------------------------------------
#define TMR2RLH_TMR2RLH__FMASK 0xFF ///< Timer 2 Reload High Byte
#define TMR2RLH_TMR2RLH__SHIFT 0x00 ///< Timer 2 Reload High Byte
                                                                 
//------------------------------------------------------------------------------
// TMR2RLL Enums (Timer 2 Reload Low Byte @ 0xCA)
//------------------------------------------------------------------------------
#define TMR2RLL_TMR2RLL__FMASK 0xFF ///< Timer 2 Reload Low Byte
#define TMR2RLL_TMR2RLL__SHIFT 0x00 ///< Timer 2 Reload Low Byte
                                                                
//------------------------------------------------------------------------------
// TMR3CN Enums (Timer 3 Control @ 0x91)
//------------------------------------------------------------------------------
#define TMR3CN_T3XCLK__BMASK          0x01 ///< Timer 3 External Clock Select                    
#define TMR3CN_T3XCLK__SHIFT          0x00 ///< Timer 3 External Clock Select                    
#define TMR3CN_T3XCLK__SYSCLK_DIV_12  0x00 ///< Timer 3 clock is the system clock divided by 12. 
#define TMR3CN_T3XCLK__EXTOSC_DIV_8   0x01 ///< Timer 3 clock is the external oscillator divided 
                                           ///< by 8 (synchronized with SYSCLK).                 
                                                                                                 
#define TMR3CN_TR3__BMASK             0x04 ///< Timer 3 Run Control                              
#define TMR3CN_TR3__SHIFT             0x02 ///< Timer 3 Run Control                              
#define TMR3CN_TR3__STOP              0x00 ///< Stop Timer 3.                                    
#define TMR3CN_TR3__RUN               0x04 ///< Start Timer 3 running.                           
                                                                                                 
#define TMR3CN_T3SPLIT__BMASK         0x08 ///< Timer 3 Split Mode Enable                        
#define TMR3CN_T3SPLIT__SHIFT         0x03 ///< Timer 3 Split Mode Enable                        
#define TMR3CN_T3SPLIT__16_BIT_RELOAD 0x00 ///< Timer 3 operates in 16-bit auto-reload mode.     
#define TMR3CN_T3SPLIT__8_BIT_RELOAD  0x08 ///< Timer 3 operates as two 8-bit auto-reload timers.
                                                                                                 
#define TMR3CN_TF3CEN__BMASK          0x10 ///< Timer 3 Capture Enable                           
#define TMR3CN_TF3CEN__SHIFT          0x04 ///< Timer 3 Capture Enable                           
#define TMR3CN_TF3CEN__DISABLED       0x00 ///< Disable capture mode.                            
#define TMR3CN_TF3CEN__ENABLED        0x10 ///< Enable capture mode.                             
                                                                                                 
#define TMR3CN_TF3LEN__BMASK          0x20 ///< Timer 3 Low Byte Interrupt Enable                
#define TMR3CN_TF3LEN__SHIFT          0x05 ///< Timer 3 Low Byte Interrupt Enable                
#define TMR3CN_TF3LEN__DISABLED       0x00 ///< Disable low byte interrupts.                     
#define TMR3CN_TF3LEN__ENABLED        0x20 ///< Enable low byte interrupts.                      
                                                                                                 
#define TMR3CN_TF3L__BMASK            0x40 ///< Timer 3 Low Byte Overflow Flag                   
#define TMR3CN_TF3L__SHIFT            0x06 ///< Timer 3 Low Byte Overflow Flag                   
#define TMR3CN_TF3L__NOT_SET          0x00 ///< Timer 3 low byte did not overflow.               
#define TMR3CN_TF3L__SET              0x40 ///< Timer 3 low byte overflowed.                     
                                                                                                 
#define TMR3CN_TF3H__BMASK            0x80 ///< Timer 3 High Byte Overflow Flag                  
#define TMR3CN_TF3H__SHIFT            0x07 ///< Timer 3 High Byte Overflow Flag                  
#define TMR3CN_TF3H__NOT_SET          0x00 ///< Timer 3 8-bit high byte or 16-bit value did not  
                                           ///< overflow.                                        
#define TMR3CN_TF3H__SET              0x80 ///< Timer 3 8-bit high byte or 16-bit value          
                                           ///< overflowed.                                      
                                                                                                 
//------------------------------------------------------------------------------
// TMR3H Enums (Timer 3 High Byte @ 0x95)
//------------------------------------------------------------------------------
#define TMR3H_TMR3H__FMASK 0xFF ///< Timer 3 High Byte
#define TMR3H_TMR3H__SHIFT 0x00 ///< Timer 3 High Byte
                                                      
//------------------------------------------------------------------------------
// TMR3L Enums (Timer 3 Low Byte @ 0x94)
//------------------------------------------------------------------------------
#define TMR3L_TMR3L__FMASK 0xFF ///< Timer 3 Low Byte
#define TMR3L_TMR3L__SHIFT 0x00 ///< Timer 3 Low Byte
                                                     
//------------------------------------------------------------------------------
// TMR3RLH Enums (Timer 3 Reload High Byte @ 0x93)
//------------------------------------------------------------------------------
#define TMR3RLH_TMR3RLH__FMASK 0xFF ///< Timer 3 Reload High Byte
#define TMR3RLH_TMR3RLH__SHIFT 0x00 ///< Timer 3 Reload High Byte
                                                                 
//------------------------------------------------------------------------------
// TMR3RLL Enums (Timer 3 Reload Low Byte @ 0x92)
//------------------------------------------------------------------------------
#define TMR3RLL_TMR3RLL__FMASK 0xFF ///< Timer 3 Reload Low Byte
#define TMR3RLL_TMR3RLL__SHIFT 0x00 ///< Timer 3 Reload Low Byte
                                                                
//------------------------------------------------------------------------------
// TMR4CAPH Enums (Timer 4 Reload High Byte @ 0xCB)
//------------------------------------------------------------------------------
#define TMR4CAPH_TMR4CAPH__FMASK 0xFF ///< Timer 4 Reload High Byte
#define TMR4CAPH_TMR4CAPH__SHIFT 0x00 ///< Timer 4 Reload High Byte
                                                                   
//------------------------------------------------------------------------------
// TMR4CAPL Enums (Timer 4 Reload Low Byte @ 0xCA)
//------------------------------------------------------------------------------
#define TMR4CAPL_TMR4CAPL__FMASK 0xFF ///< Timer 4 Reload Low Byte
#define TMR4CAPL_TMR4CAPL__SHIFT 0x00 ///< Timer 4 Reload Low Byte
                                                                  
//------------------------------------------------------------------------------
// TMR4CF Enums (Timer 4 Config @ 0xC9)
//------------------------------------------------------------------------------
#define TMR4CF_DCEN4__BMASK                 0x01 ///< Decrement Enable                                 
#define TMR4CF_DCEN4__SHIFT                 0x00 ///< Decrement Enable                                 
#define TMR4CF_DCEN4__UP_ONLY               0x00 ///< Timer 4 will count up, regardless of the state of
                                                 ///< T4EX.                                            
#define TMR4CF_DCEN4__UP_OR_DOWN            0x01 ///< Timer 4 will count up if T4EX is high and count  
                                                 ///< down if T4EX is low.                             
                                                                                                       
#define TMR4CF_T4OE__BMASK                  0x02 ///< Output Enable                                    
#define TMR4CF_T4OE__SHIFT                  0x01 ///< Output Enable                                    
#define TMR4CF_T4OE__TOGGLE_OUTPUT_DISABLED 0x00 ///< The output of toggle mode is not available at the
                                                 ///< timer's assigned port pin.                       
#define TMR4CF_T4OE__TOGGLE_OUTPUT_ENABLED  0x02 ///< The output of toggle mode is available at the    
                                                 ///< timer's assigned port pin.                       
                                                                                                       
#define TMR4CF_TOG4__BMASK                  0x04 ///< Toggle Output State                              
#define TMR4CF_TOG4__SHIFT                  0x02 ///< Toggle Output State                              
#define TMR4CF_TOG4__LOW                    0x00 ///< Output is low or force the T4 output low.        
#define TMR4CF_TOG4__HIGH                   0x04 ///< Output is high or force the T4 output high.      
                                                                                                       
#define TMR4CF_T4M__FMASK                   0x18 ///< Clock Mode Select                                
#define TMR4CF_T4M__SHIFT                   0x03 ///< Clock Mode Select                                
#define TMR4CF_T4M__SYSCLK_DIV_12           0x00 ///< Timer 4 clock is SYSCLK / 12.                    
#define TMR4CF_T4M__SYSCLK                  0x08 ///< Timer 4 clock is SYSCLK.                         
#define TMR4CF_T4M__EXTOSC_DIV_8            0x10 ///< Timer 4 clock is EXTOSC / 8 (synchronized to the 
                                                 ///< system clock).                                   
#define TMR4CF_T4M__SYSCLK_DIV_2            0x18 ///< Timer 4 clock is SYSCLK / 2.                     
                                                                                                       
//------------------------------------------------------------------------------
// TMR4CN Enums (Timer 4 Control @ 0xC8)
//------------------------------------------------------------------------------
#define TMR4CN_CPRL4__BMASK          0x01 ///< Capture / Reload Select                           
#define TMR4CN_CPRL4__SHIFT          0x00 ///< Capture / Reload Select                           
#define TMR4CN_CPRL4__AUTO_RELOAD    0x00 ///< Timer 4 is in auto-reload mode.                   
#define TMR4CN_CPRL4__CAPTURE        0x01 ///< Timer 4 is in capture mode.                       
                                                                                                 
#define TMR4CN_CT4__BMASK            0x02 ///< Counter / Timer Select                            
#define TMR4CN_CT4__SHIFT            0x01 ///< Counter / Timer Select                            
#define TMR4CN_CT4__TIMER            0x00 ///< Timer function: the timer increments by the clock 
                                          ///< defined in the T4M bits in the TMR4CF register.   
#define TMR4CN_CT4__COUNTER          0x02 ///< Counter function: the timer increments by high-to-
                                          ///< low transitions on the T4EX pin.                  
                                                                                                 
#define TMR4CN_TR4__BMASK            0x04 ///< Timer 4 Run Control                               
#define TMR4CN_TR4__SHIFT            0x02 ///< Timer 4 Run Control                               
#define TMR4CN_TR4__STOP             0x00 ///< Stop Timer 4.                                     
#define TMR4CN_TR4__RUN              0x04 ///< Start Timer 4 running.                            
                                                                                                 
#define TMR4CN_EXE4__BMASK           0x08 ///< Timer 4 External Enable                           
#define TMR4CN_EXE4__SHIFT           0x03 ///< Timer 4 External Enable                           
#define TMR4CN_EXE4__EX_PIN_DISABLED 0x00 ///< Transitions on the T4EX pin are ignored.          
#define TMR4CN_EXE4__EX_PIN_ENABLED  0x08 ///< Transitions on the T4EX pin cause capture, reload,
                                          ///< or control the direction of timer count (up or    
                                          ///< down).                                            
                                                                                                 
#define TMR4CN_EXF4__BMASK           0x40 ///< Timer 4 External Flag                             
#define TMR4CN_EXF4__SHIFT           0x06 ///< Timer 4 External Flag                             
#define TMR4CN_EXF4__NOT_SET         0x00 ///< Timer 4 capture or reload did not occur.          
#define TMR4CN_EXF4__SET             0x40 ///< Timer 4 capture or reload occurred.               
                                                                                                 
#define TMR4CN_TF4__BMASK            0x80 ///< Timer 4 Overflow or Underflow Flag                
#define TMR4CN_TF4__SHIFT            0x07 ///< Timer 4 Overflow or Underflow Flag                
#define TMR4CN_TF4__NOT_SET          0x00 ///< Timer 4 16-bit value did not overflow or          
                                          ///< underflow.                                        
#define TMR4CN_TF4__SET              0x80 ///< Timer 4 16-bit value overflowed or underflowed.   
                                                                                                 
//------------------------------------------------------------------------------
// TMR4H Enums (Timer 4 High Byte @ 0xCD)
//------------------------------------------------------------------------------
#define TMR4H_TMR4H__FMASK 0xFF ///< Timer 4 High Byte
#define TMR4H_TMR4H__SHIFT 0x00 ///< Timer 4 High Byte
                                                      
//------------------------------------------------------------------------------
// TMR4L Enums (Timer 4 Low Byte @ 0xCC)
//------------------------------------------------------------------------------
#define TMR4L_TMR4L__FMASK 0xFF ///< Timer 4 Low Byte
#define TMR4L_TMR4L__SHIFT 0x00 ///< Timer 4 Low Byte
                                                     
//------------------------------------------------------------------------------
// TMR5CAPH Enums (Timer 5 Reload High Byte @ 0x93)
//------------------------------------------------------------------------------
#define TMR5CAPH_TMR5CAPH__FMASK 0xFF ///< Timer 5 Reload High Byte
#define TMR5CAPH_TMR5CAPH__SHIFT 0x00 ///< Timer 5 Reload High Byte
                                                                   
//------------------------------------------------------------------------------
// TMR5CAPL Enums (Timer 5 Reload Low Byte @ 0x92)
//------------------------------------------------------------------------------
#define TMR5CAPL_TMR5CAPL__FMASK 0xFF ///< Timer 5 Reload Low Byte
#define TMR5CAPL_TMR5CAPL__SHIFT 0x00 ///< Timer 5 Reload Low Byte
                                                                  
//------------------------------------------------------------------------------
// TMR5CF Enums (Timer 5 Config @ 0x96)
//------------------------------------------------------------------------------
#define TMR5CF_DCEN5__BMASK                 0x01 ///< Decrement Enable                                 
#define TMR5CF_DCEN5__SHIFT                 0x00 ///< Decrement Enable                                 
#define TMR5CF_DCEN5__UP_ONLY               0x00 ///< Timer 5 will count up, regardless of the state of
                                                 ///< T5EX.                                            
#define TMR5CF_DCEN5__UP_OR_DOWN            0x01 ///< Timer 5 will count up if T5EX is high and count  
                                                 ///< down if T5EX is low.                             
                                                                                                       
#define TMR5CF_T5OE__BMASK                  0x02 ///< Output Enable                                    
#define TMR5CF_T5OE__SHIFT                  0x01 ///< Output Enable                                    
#define TMR5CF_T5OE__TOGGLE_OUTPUT_DISABLED 0x00 ///< The output of toggle mode is not available at the
                                                 ///< timer's assigned port pin.                       
#define TMR5CF_T5OE__TOGGLE_OUTPUT_ENABLED  0x02 ///< The output of toggle mode is available at the    
                                                 ///< timer's assigned port pin.                       
                                                                                                       
#define TMR5CF_TOG5__BMASK                  0x04 ///< Toggle Output State                              
#define TMR5CF_TOG5__SHIFT                  0x02 ///< Toggle Output State                              
#define TMR5CF_TOG5__LOW                    0x00 ///< Output is low or force the T5 output low.        
#define TMR5CF_TOG5__HIGH                   0x04 ///< Output is high or force the T5 output high.      
                                                                                                       
#define TMR5CF_T5M__FMASK                   0x18 ///< Clock Mode Select                                
#define TMR5CF_T5M__SHIFT                   0x03 ///< Clock Mode Select                                
#define TMR5CF_T5M__SYSCLK_DIV_12           0x00 ///< Timer 5 clock is SYSCLK / 12.                    
#define TMR5CF_T5M__SYSCLK                  0x08 ///< Timer 5 clock is SYSCLK.                         
#define TMR5CF_T5M__EXTOSC_DIV_8            0x10 ///< Timer 5 clock is EXTOSC / 8 (synchronized to the 
                                                 ///< system clock).                                   
#define TMR5CF_T5M__SYSCLK_DIV_2            0x18 ///< Timer 5 clock is SYSCLK / 2.                     
                                                                                                       
//------------------------------------------------------------------------------
// TMR5CN Enums (Timer 5 Control @ 0x91)
//------------------------------------------------------------------------------
#define TMR5CN_CPRL5__BMASK          0x01 ///< Capture / Reload Select                           
#define TMR5CN_CPRL5__SHIFT          0x00 ///< Capture / Reload Select                           
#define TMR5CN_CPRL5__AUTO_RELOAD    0x00 ///< Timer 5 is in auto-reload mode.                   
#define TMR5CN_CPRL5__CAPTURE        0x01 ///< Timer 5 is in capture mode.                       
                                                                                                 
#define TMR5CN_CT5__BMASK            0x02 ///< Counter / Timer Select                            
#define TMR5CN_CT5__SHIFT            0x01 ///< Counter / Timer Select                            
#define TMR5CN_CT5__TIMER            0x00 ///< Timer function: the timer increments by the clock 
                                          ///< defined in the T5M bits in the TMR5CF register.   
#define TMR5CN_CT5__COUNTER          0x02 ///< Counter function: the timer increments by high-to-
                                          ///< low transitions on the T5EX pin.                  
                                                                                                 
#define TMR5CN_TR5__BMASK            0x04 ///< Timer 5 Run Control                               
#define TMR5CN_TR5__SHIFT            0x02 ///< Timer 5 Run Control                               
#define TMR5CN_TR5__STOP             0x00 ///< Stop Timer 5.                                     
#define TMR5CN_TR5__RUN              0x04 ///< Start Timer 5 running.                            
                                                                                                 
#define TMR5CN_EXE5__BMASK           0x08 ///< Timer 5 External Enable                           
#define TMR5CN_EXE5__SHIFT           0x03 ///< Timer 5 External Enable                           
#define TMR5CN_EXE5__EX_PIN_DISABLED 0x00 ///< Transitions on the T5EX pin are ignored.          
#define TMR5CN_EXE5__EX_PIN_ENABLED  0x08 ///< Transitions on the T5EX pin cause capture, reload,
                                          ///< or control the direction of timer count (up or    
                                          ///< down).                                            
                                                                                                 
#define TMR5CN_EXF5__BMASK           0x40 ///< Timer 5 External Flag                             
#define TMR5CN_EXF5__SHIFT           0x06 ///< Timer 5 External Flag                             
#define TMR5CN_EXF5__NOT_SET         0x00 ///< Timer 5 capture or reload did not occur.          
#define TMR5CN_EXF5__SET             0x40 ///< Timer 5 capture or reload occurred.               
                                                                                                 
#define TMR5CN_TF5__BMASK            0x80 ///< Timer 5 Overflow or Underflow Flag                
#define TMR5CN_TF5__SHIFT            0x07 ///< Timer 5 Overflow or Underflow Flag                
#define TMR5CN_TF5__NOT_SET          0x00 ///< Timer 5 16-bit value did not overflow or          
                                          ///< underflow.                                        
#define TMR5CN_TF5__SET              0x80 ///< Timer 5 16-bit value overflowed or underflowed.   
                                                                                                 
//------------------------------------------------------------------------------
// TMR5H Enums (Timer 5 High Byte @ 0x95)
//------------------------------------------------------------------------------
#define TMR5H_TMR5H__FMASK 0xFF ///< Timer 5 High Byte
#define TMR5H_TMR5H__SHIFT 0x00 ///< Timer 5 High Byte
                                                      
//------------------------------------------------------------------------------
// TMR5L Enums (Timer 5 Low Byte @ 0x94)
//------------------------------------------------------------------------------
#define TMR5L_TMR5L__FMASK 0xFF ///< Timer 5 Low Byte
#define TMR5L_TMR5L__SHIFT 0x00 ///< Timer 5 Low Byte
                                                     
//------------------------------------------------------------------------------
// CKCON Enums (Clock Control @ 0x8E)
//------------------------------------------------------------------------------
#define CKCON_SCA__FMASK           0x03 ///< Timer 0/1 Prescale                             
#define CKCON_SCA__SHIFT           0x00 ///< Timer 0/1 Prescale                             
#define CKCON_SCA__SYSCLK_DIV_12   0x00 ///< System clock divided by 12.                    
#define CKCON_SCA__SYSCLK_DIV_4    0x01 ///< System clock divided by 4.                     
#define CKCON_SCA__SYSCLK_DIV_48   0x02 ///< System clock divided by 48.                    
#define CKCON_SCA__EXTOSC_DIV_8    0x03 ///< External oscillator divided by 8 (synchronized 
                                        ///< with the system clock).                        
                                                                                            
#define CKCON_T0M__BMASK           0x04 ///< Timer 0 Clock Select                           
#define CKCON_T0M__SHIFT           0x02 ///< Timer 0 Clock Select                           
#define CKCON_T0M__PRESCALE        0x00 ///< Counter/Timer 0 uses the clock defined by the  
                                        ///< prescale field, SCA.                           
#define CKCON_T0M__SYSCLK          0x04 ///< Counter/Timer 0 uses the system clock.         
                                                                                            
#define CKCON_T1M__BMASK           0x08 ///< Timer 1 Clock Select                           
#define CKCON_T1M__SHIFT           0x03 ///< Timer 1 Clock Select                           
#define CKCON_T1M__PRESCALE        0x00 ///< Timer 1 uses the clock defined by the prescale 
                                        ///< field, SCA.                                    
#define CKCON_T1M__SYSCLK          0x08 ///< Timer 1 uses the system clock.                 
                                                                                            
#define CKCON_T2ML__BMASK          0x10 ///< Timer 2 Low Byte Clock Select                  
#define CKCON_T2ML__SHIFT          0x04 ///< Timer 2 Low Byte Clock Select                  
#define CKCON_T2ML__EXTERNAL_CLOCK 0x00 ///< Timer 2 low byte uses the clock defined by the 
                                        ///< T2XCLK bit in TMR2CN.                          
#define CKCON_T2ML__SYSCLK         0x10 ///< Timer 2 low byte uses the system clock.        
                                                                                            
#define CKCON_T2MH__BMASK          0x20 ///< Timer 2 High Byte Clock Select                 
#define CKCON_T2MH__SHIFT          0x05 ///< Timer 2 High Byte Clock Select                 
#define CKCON_T2MH__EXTERNAL_CLOCK 0x00 ///< Timer 2 high byte uses the clock defined by the
                                        ///< T2XCLK bit in TMR2CN.                          
#define CKCON_T2MH__SYSCLK         0x20 ///< Timer 2 high byte uses the system clock.       
                                                                                            
#define CKCON_T3ML__BMASK          0x40 ///< Timer 3 Low Byte Clock Select                  
#define CKCON_T3ML__SHIFT          0x06 ///< Timer 3 Low Byte Clock Select                  
#define CKCON_T3ML__EXTERNAL_CLOCK 0x00 ///< Timer 3 low byte uses the clock defined by the 
                                        ///< T3XCLK bit in TMR3CN.                          
#define CKCON_T3ML__SYSCLK         0x40 ///< Timer 3 low byte uses the system clock.        
                                                                                            
#define CKCON_T3MH__BMASK          0x80 ///< Timer 3 High Byte Clock Select                 
#define CKCON_T3MH__SHIFT          0x07 ///< Timer 3 High Byte Clock Select                 
#define CKCON_T3MH__EXTERNAL_CLOCK 0x00 ///< Timer 3 high byte uses the clock defined by the
                                        ///< T3XCLK bit in TMR3CN.                          
#define CKCON_T3MH__SYSCLK         0x80 ///< Timer 3 high byte uses the system clock.       
                                                                                            
//------------------------------------------------------------------------------
// TCON Enums (Timer 0/1 Control @ 0x88)
//------------------------------------------------------------------------------
#define TCON_IT0__BMASK   0x01 ///< Interrupt 0 Type Select  
#define TCON_IT0__SHIFT   0x00 ///< Interrupt 0 Type Select  
#define TCON_IT0__LEVEL   0x00 ///< /INT0 is level triggered.
#define TCON_IT0__EDGE    0x01 ///< /INT0 is edge triggered. 
                                                             
#define TCON_IE0__BMASK   0x02 ///< External Interrupt 0     
#define TCON_IE0__SHIFT   0x01 ///< External Interrupt 0     
#define TCON_IE0__NOT_SET 0x00 ///< Edge/level not detected. 
#define TCON_IE0__SET     0x02 ///< Edge/level detected      
                                                             
#define TCON_IT1__BMASK   0x04 ///< Interrupt 1 Type Select  
#define TCON_IT1__SHIFT   0x02 ///< Interrupt 1 Type Select  
#define TCON_IT1__LEVEL   0x00 ///< /INT1 is level triggered.
#define TCON_IT1__EDGE    0x04 ///< /INT1 is edge triggered. 
                                                             
#define TCON_IE1__BMASK   0x08 ///< External Interrupt 1     
#define TCON_IE1__SHIFT   0x03 ///< External Interrupt 1     
#define TCON_IE1__NOT_SET 0x00 ///< Edge/level not detected. 
#define TCON_IE1__SET     0x08 ///< Edge/level detected      
                                                             
#define TCON_TR0__BMASK   0x10 ///< Timer 0 Run Control      
#define TCON_TR0__SHIFT   0x04 ///< Timer 0 Run Control      
#define TCON_TR0__STOP    0x00 ///< Stop Timer 0.            
#define TCON_TR0__RUN     0x10 ///< Start Timer 0 running.   
                                                             
#define TCON_TF0__BMASK   0x20 ///< Timer 0 Overflow Flag    
#define TCON_TF0__SHIFT   0x05 ///< Timer 0 Overflow Flag    
#define TCON_TF0__NOT_SET 0x00 ///< Timer 0 did not overflow.
#define TCON_TF0__SET     0x20 ///< Timer 0 overflowed.      
                                                             
#define TCON_TR1__BMASK   0x40 ///< Timer 1 Run Control      
#define TCON_TR1__SHIFT   0x06 ///< Timer 1 Run Control      
#define TCON_TR1__STOP    0x00 ///< Stop Timer 1.            
#define TCON_TR1__RUN     0x40 ///< Start Timer 1 running.   
                                                             
#define TCON_TF1__BMASK   0x80 ///< Timer 1 Overflow Flag    
#define TCON_TF1__SHIFT   0x07 ///< Timer 1 Overflow Flag    
#define TCON_TF1__NOT_SET 0x00 ///< Timer 1 did not overflow.
#define TCON_TF1__SET     0x80 ///< Timer 1 overflowed.      
                                                             
//------------------------------------------------------------------------------
// TMOD Enums (Timer 0/1 Mode @ 0x89)
//------------------------------------------------------------------------------
#define TMOD_T0M__FMASK      0x03 ///< Timer 0 Mode Select                               
#define TMOD_T0M__SHIFT      0x00 ///< Timer 0 Mode Select                               
#define TMOD_T0M__MODE0      0x00 ///< Mode 0, 13-bit Counter/Timer                      
#define TMOD_T0M__MODE1      0x01 ///< Mode 1, 16-bit Counter/Timer                      
#define TMOD_T0M__MODE2      0x02 ///< Mode 2, 8-bit Counter/Timer with Auto-Reload      
#define TMOD_T0M__MODE3      0x03 ///< Mode 3, Two 8-bit Counter/Timers                  
                                                                                         
#define TMOD_CT0__BMASK      0x04 ///< Counter/Timer 0 Select                            
#define TMOD_CT0__SHIFT      0x02 ///< Counter/Timer 0 Select                            
#define TMOD_CT0__TIMER      0x00 ///< Timer Mode. Timer 0 increments on the clock       
                                  ///< defined by T0M in the CKCON register.             
#define TMOD_CT0__COUNTER    0x04 ///< Counter Mode. Timer 0 increments on high-to-low   
                                  ///< transitions of an external pin (T0).              
                                                                                         
#define TMOD_GATE0__BMASK    0x08 ///< Timer 0 Gate Control                              
#define TMOD_GATE0__SHIFT    0x03 ///< Timer 0 Gate Control                              
#define TMOD_GATE0__DISABLED 0x00 ///< Timer 0 enabled when TR0 = 1 irrespective of /INT0
                                  ///< logic level.                                      
#define TMOD_GATE0__ENABLED  0x08 ///< Timer 0 enabled only when TR0 = 1 and /INT0 is    
                                  ///< active as defined by bit IN0PL in register IT01CF.
                                                                                         
#define TMOD_T1M__FMASK      0x30 ///< Timer 1 Mode Select                               
#define TMOD_T1M__SHIFT      0x04 ///< Timer 1 Mode Select                               
#define TMOD_T1M__MODE0      0x00 ///< Mode 0, 13-bit Counter/Timer                      
#define TMOD_T1M__MODE1      0x10 ///< Mode 1, 16-bit Counter/Timer                      
#define TMOD_T1M__MODE2      0x20 ///< Mode 2, 8-bit Counter/Timer with Auto-Reload      
#define TMOD_T1M__MODE3      0x30 ///< Mode 3, Timer 1 Inactive                          
                                                                                         
#define TMOD_CT1__BMASK      0x40 ///< Counter/Timer 1 Select                            
#define TMOD_CT1__SHIFT      0x06 ///< Counter/Timer 1 Select                            
#define TMOD_CT1__TIMER      0x00 ///< Timer Mode. Timer 1 increments on the clock       
                                  ///< defined by T1M in the CKCON register.             
#define TMOD_CT1__COUNTER    0x40 ///< Counter Mode. Timer 1 increments on high-to-low   
                                  ///< transitions of an external pin (T1).              
                                                                                         
#define TMOD_GATE1__BMASK    0x80 ///< Timer 1 Gate Control                              
#define TMOD_GATE1__SHIFT    0x07 ///< Timer 1 Gate Control                              
#define TMOD_GATE1__DISABLED 0x00 ///< Timer 1 enabled when TR1 = 1 irrespective of /INT1
                                  ///< logic level.                                      
#define TMOD_GATE1__ENABLED  0x80 ///< Timer 1 enabled only when TR1 = 1 and /INT1 is    
                                  ///< active as defined by bit IN1PL in register IT01CF.
                                                                                         
//------------------------------------------------------------------------------
// SBCON0 Enums (UART0 Baud Rate Generator Control @ 0xAB)
//------------------------------------------------------------------------------
#define SBCON0_SBPS__FMASK     0x03 ///< Baud Rate Prescaler Select                     
#define SBCON0_SBPS__SHIFT     0x00 ///< Baud Rate Prescaler Select                     
#define SBCON0_SBPS__DIV_BY_12 0x00 ///< Prescaler = 12.                                
#define SBCON0_SBPS__DIV_BY_4  0x01 ///< Prescaler = 4.                                 
#define SBCON0_SBPS__DIV_BY_48 0x02 ///< Prescaler = 48.                                
#define SBCON0_SBPS__DIV_BY_1  0x03 ///< Prescaler = 1.                                 
                                                                                        
#define SBCON0_SBRUN__BMASK    0x40 ///< Baud Rate Generator Enable                     
#define SBCON0_SBRUN__SHIFT    0x06 ///< Baud Rate Generator Enable                     
#define SBCON0_SBRUN__DISABLED 0x00 ///< Disable the baud rate generator. UART0 will not
                                    ///< function.                                      
#define SBCON0_SBRUN__ENABLED  0x40 ///< Enable the baud rate generator.                
                                                                                        
//------------------------------------------------------------------------------
// SBRLH0 Enums (UART0 Baud Rate Generator High Byte @ 0xAD)
//------------------------------------------------------------------------------
#define SBRLH0_SBRL__FMASK 0xFF ///< UART0 Baud Rate Reload High
#define SBRLH0_SBRL__SHIFT 0x00 ///< UART0 Baud Rate Reload High
                                                                
//------------------------------------------------------------------------------
// SBRLL0 Enums (UART0 Baud Rate Generator Low Byte @ 0xAC)
//------------------------------------------------------------------------------
#define SBRLL0_SBRL__FMASK 0xFF ///< UART0 Baud Rate Reload Low
#define SBRLL0_SBRL__SHIFT 0x00 ///< UART0 Baud Rate Reload Low
                                                               
//------------------------------------------------------------------------------
// SBUF0 Enums (UART0 Serial Port Data Buffer @ 0x99)
//------------------------------------------------------------------------------
#define SBUF0_SBUF0__FMASK 0xFF ///< Serial Port Data Buffer
#define SBUF0_SBUF0__SHIFT 0x00 ///< Serial Port Data Buffer
                                                            
//------------------------------------------------------------------------------
// SCON0 Enums (UART0 Serial Port Control @ 0x98)
//------------------------------------------------------------------------------
#define SCON0_RI__BMASK             0x01 ///< Receive Interrupt Flag                            
#define SCON0_RI__SHIFT             0x00 ///< Receive Interrupt Flag                            
#define SCON0_RI__NOT_SET           0x00 ///< A byte of data has not been received by UART0.    
#define SCON0_RI__SET               0x01 ///< UART0 received a byte of data or data remains in  
                                         ///< the receive FIFO.                                 
                                                                                                
#define SCON0_TI__BMASK             0x02 ///< Transmit Interrupt Flag                           
#define SCON0_TI__SHIFT             0x01 ///< Transmit Interrupt Flag                           
#define SCON0_TI__NOT_SET           0x00 ///< A byte of data has not been transmitted by UART0. 
#define SCON0_TI__SET               0x02 ///< UART0 transmitted a byte of data.                 
                                                                                                
#define SCON0_RBX__BMASK            0x04 ///< Extra Receive Bit                                 
#define SCON0_RBX__SHIFT            0x02 ///< Extra Receive Bit                                 
#define SCON0_RBX__LOW              0x00 ///< The extra bit or the first stop bit is 0.         
#define SCON0_RBX__HIGH             0x04 ///< The extra bit or the first stop bit is 1.         
                                                                                                
#define SCON0_TBX__BMASK            0x08 ///< Extra Transmission Bit                            
#define SCON0_TBX__SHIFT            0x03 ///< Extra Transmission Bit                            
#define SCON0_TBX__LOW              0x00 ///< Set extra bit to 0 (low).                         
#define SCON0_TBX__HIGH             0x08 ///< Set extra bit to 1 (high).                        
                                                                                                
#define SCON0_REN__BMASK            0x10 ///< Receive Enable                                    
#define SCON0_REN__SHIFT            0x04 ///< Receive Enable                                    
#define SCON0_REN__RECEIVE_DISABLED 0x00 ///< UART0 reception disabled.                         
#define SCON0_REN__RECEIVE_ENABLED  0x10 ///< UART0 reception enabled.                          
                                                                                                
#define SCON0_THRE__BMASK           0x20 ///< Transmit Holding Register Empty Flag              
#define SCON0_THRE__SHIFT           0x05 ///< Transmit Holding Register Empty Flag              
#define SCON0_THRE__NOT_SET         0x00 ///< The transmit holding register is not empty. Do not
                                         ///< write to SBUF0.                                   
#define SCON0_THRE__SET             0x20 ///< The transmit holding register is empty. It is safe
                                         ///< to write to SBUF0.                                
                                                                                                
#define SCON0_PERR__BMASK           0x40 ///< Parity Error Flag                                 
#define SCON0_PERR__SHIFT           0x06 ///< Parity Error Flag                                 
#define SCON0_PERR__NOT_SET         0x00 ///< Parity error has not occurred.                    
#define SCON0_PERR__SET             0x40 ///< Parity error has occurred.                        
                                                                                                
#define SCON0_OVR__BMASK            0x80 ///< Receive FIFO Overrun Flag                         
#define SCON0_OVR__SHIFT            0x07 ///< Receive FIFO Overrun Flag                         
#define SCON0_OVR__NOT_SET          0x00 ///< Receive FIFO overrun has not occurred.            
#define SCON0_OVR__SET              0x80 ///< Receive FIFO overrun has occurred.                
                                                                                                
//------------------------------------------------------------------------------
// SMOD0 Enums (UART0 Mode @ 0xA9)
//------------------------------------------------------------------------------
#define SMOD0_SBL__BMASK          0x01 ///< Stop Bit Length                                 
#define SMOD0_SBL__SHIFT          0x00 ///< Stop Bit Length                                 
#define SMOD0_SBL__SHORT          0x00 ///< Short: Stop bit is active for one bit time.     
#define SMOD0_SBL__LONG           0x01 ///< Long: Stop bit is active for two bit times (data
                                       ///< length = 6, 7, or 8 bits) or 1.5 bit times (data
                                       ///< length = 5 bits).                               
                                                                                            
#define SMOD0_XBE__BMASK          0x02 ///< Extra Bit Enable                                
#define SMOD0_XBE__SHIFT          0x01 ///< Extra Bit Enable                                
#define SMOD0_XBE__DISABLED       0x00 ///< Disable the extra bit.                          
#define SMOD0_XBE__ENABLED        0x02 ///< Enable the extra bit.                           
                                                                                            
#define SMOD0_SDL__FMASK          0x0C ///< Data Length                                     
#define SMOD0_SDL__SHIFT          0x02 ///< Data Length                                     
#define SMOD0_SDL__5_BITS         0x00 ///< 5 bits.                                         
#define SMOD0_SDL__6_BITS         0x04 ///< 6 bits.                                         
#define SMOD0_SDL__7_BITS         0x08 ///< 7 bits.                                         
#define SMOD0_SDL__8_BITS         0x0C ///< 8 bits.                                         
                                                                                            
#define SMOD0_PE__BMASK           0x10 ///< Parity Enable                                   
#define SMOD0_PE__SHIFT           0x04 ///< Parity Enable                                   
#define SMOD0_PE__PARITY_DISABLED 0x00 ///< Disable hardware parity.                        
#define SMOD0_PE__PARITY_ENABLED  0x10 ///< Enable hardware parity.                         
                                                                                            
#define SMOD0_SPT__FMASK          0x60 ///< Parity Type                                     
#define SMOD0_SPT__SHIFT          0x05 ///< Parity Type                                     
#define SMOD0_SPT__ODD_PARTY      0x00 ///< Odd.                                            
#define SMOD0_SPT__EVEN_PARITY    0x20 ///< Even.                                           
#define SMOD0_SPT__MARK_PARITY    0x40 ///< Mark.                                           
#define SMOD0_SPT__SPACE_PARITY   0x60 ///< Space.                                          
                                                                                            
#define SMOD0_MCE__BMASK          0x80 ///< Multiprocessor Communication Enable             
#define SMOD0_MCE__SHIFT          0x07 ///< Multiprocessor Communication Enable             
#define SMOD0_MCE__MULTI_DISABLED 0x00 ///< RI will be activated if the stop bits are 1.    
#define SMOD0_MCE__MULTI_ENABLED  0x80 ///< RI will be activated if the stop bits and extra 
                                       ///< bit are 1. The extra bit must be enabled using  
                                       ///< XBE.                                            
                                                                                            
//------------------------------------------------------------------------------
// SBUF1 Enums (UART1 Serial Port Data Buffer @ 0x99)
//------------------------------------------------------------------------------
#define SBUF1_SBUF1__FMASK 0xFF ///< Serial Data Buffer
#define SBUF1_SBUF1__SHIFT 0x00 ///< Serial Data Buffer
                                                       
//------------------------------------------------------------------------------
// SCON1 Enums (UART1 Serial Port Control @ 0x98)
//------------------------------------------------------------------------------
#define SCON1_RI__BMASK             0x01 ///< Receive Interrupt Flag                           
#define SCON1_RI__SHIFT             0x00 ///< Receive Interrupt Flag                           
#define SCON1_RI__NOT_SET           0x00 ///< A byte of data has not been received by UART1.   
#define SCON1_RI__SET               0x01 ///< UART1 received a byte of data.                   
                                                                                               
#define SCON1_TI__BMASK             0x02 ///< Transmit Interrupt Flag                          
#define SCON1_TI__SHIFT             0x01 ///< Transmit Interrupt Flag                          
#define SCON1_TI__NOT_SET           0x00 ///< A byte of data has not been transmitted by UART1.
#define SCON1_TI__SET               0x02 ///< UART1 transmitted a byte of data.                
                                                                                               
#define SCON1_RB8__BMASK            0x04 ///< Ninth Receive Bit                                
#define SCON1_RB8__SHIFT            0x02 ///< Ninth Receive Bit                                
#define SCON1_RB8__CLEARED_TO_0     0x00 ///< In Mode 0, the STOP bit was 0. In Mode 1, the 9th
                                         ///< bit was 0.                                       
#define SCON1_RB8__SET_TO_1         0x04 ///< In Mode 0, the STOP bit was 1. In Mode 1, the 9th
                                         ///< bit was 1.                                       
                                                                                               
#define SCON1_TB8__BMASK            0x08 ///< Ninth Transmission Bit                           
#define SCON1_TB8__SHIFT            0x03 ///< Ninth Transmission Bit                           
#define SCON1_TB8__CLEARED_TO_0     0x00 ///< In Mode 1, set the 9th transmission bit to 0.    
#define SCON1_TB8__SET_TO_1         0x08 ///< In Mode 1, set the 9th transmission bit to 1.    
                                                                                               
#define SCON1_REN__BMASK            0x10 ///< Receive Enable                                   
#define SCON1_REN__SHIFT            0x04 ///< Receive Enable                                   
#define SCON1_REN__RECEIVE_DISABLED 0x00 ///< UART1 reception disabled.                        
#define SCON1_REN__RECEIVE_ENABLED  0x10 ///< UART1 reception enabled.                         
                                                                                               
#define SCON1_MCE__BMASK            0x20 ///< Multiprocessor Communication Enable              
#define SCON1_MCE__SHIFT            0x05 ///< Multiprocessor Communication Enable              
#define SCON1_MCE__MULTI_DISABLED   0x00 ///< Ignore level of 9th bit / Stop bit.              
#define SCON1_MCE__MULTI_ENABLED    0x20 ///< RI is set and an interrupt is generated only when
                                         ///< the stop bit is logic 1 (Mode 0) or when the 9th 
                                         ///< bit is logic 1 (Mode 1).                         
                                                                                               
#define SCON1_SMODE__BMASK          0x80 ///< Serial Port 0 Operation Mode                     
#define SCON1_SMODE__SHIFT          0x07 ///< Serial Port 0 Operation Mode                     
#define SCON1_SMODE__8_BIT          0x00 ///< 8-bit UART with Variable Baud Rate (Mode 0).     
#define SCON1_SMODE__9_BIT          0x80 ///< 9-bit UART with Variable Baud Rate (Mode 1).     
                                                                                               
//------------------------------------------------------------------------------
// VDM0CN Enums (VDD Supply Monitor Control @ 0xFF)
//------------------------------------------------------------------------------
#define VDM0CN_VDMLVL__BMASK      0x20 ///< VDD Monitor Threshold Level Select              
#define VDM0CN_VDMLVL__SHIFT      0x05 ///< VDD Monitor Threshold Level Select              
#define VDM0CN_VDMLVL__LOW        0x00 ///< VDD Monitor Threshold is set to VRST-LOW.       
#define VDM0CN_VDMLVL__HIGH       0x20 ///< VDD Monitor Threshold is set to VRST-HIGH. This 
                                       ///< setting is required for any system with firmware
                                       ///< that writes and/or erases flash.                
                                                                                            
#define VDM0CN_VDDSTAT__BMASK     0x40 ///< VDD Status                                      
#define VDM0CN_VDDSTAT__SHIFT     0x06 ///< VDD Status                                      
#define VDM0CN_VDDSTAT__VDD_BELOW 0x00 ///< VDD is at or below the VDD monitor threshold.   
#define VDM0CN_VDDSTAT__VDD_ABOVE 0x40 ///< VDD is above the VDD monitor threshold.         
                                                                                            
#define VDM0CN_VDMEN__BMASK       0x80 ///< VDD Monitor Enable                              
#define VDM0CN_VDMEN__SHIFT       0x07 ///< VDD Monitor Enable                              
#define VDM0CN_VDMEN__DISABLED    0x00 ///< Disable the VDD Monitor.                        
#define VDM0CN_VDMEN__ENABLED     0x80 ///< Enable the VDD Monitor.                         
                                                                                            
//------------------------------------------------------------------------------
// REF0CN Enums (Voltage Reference Control @ 0xD1)
//------------------------------------------------------------------------------
#define REF0CN_REFBE__BMASK         0x01 ///< Internal Reference Buffer Enable                  
#define REF0CN_REFBE__SHIFT         0x00 ///< Internal Reference Buffer Enable                  
#define REF0CN_REFBE__DISABLED      0x00 ///< Disable the internal reference buffer.            
#define REF0CN_REFBE__ENABLED       0x01 ///< Enable the internal reference buffer. The internal
                                         ///< voltage reference is driven on the VREF pin.      
                                                                                                
#define REF0CN_BIASE__BMASK         0x02 ///< Internal Analog Bias Generator Enable             
#define REF0CN_BIASE__SHIFT         0x01 ///< Internal Analog Bias Generator Enable             
#define REF0CN_BIASE__DISABLED      0x00 ///< Disable the internal bias generator.              
#define REF0CN_BIASE__ENABLED       0x02 ///< Enable the internal bias generator.               
                                                                                                
#define REF0CN_TEMPE__BMASK         0x04 ///< Temperature Sensor Enable                         
#define REF0CN_TEMPE__SHIFT         0x02 ///< Temperature Sensor Enable                         
#define REF0CN_TEMPE__DISABLED      0x00 ///< Disable the internal Temperature Sensor.          
#define REF0CN_TEMPE__ENABLED       0x04 ///< Enable the internal Temperature Sensor.           
                                                                                                
#define REF0CN_REFSL__BMASK         0x08 ///< Voltage Reference Select                          
#define REF0CN_REFSL__SHIFT         0x03 ///< Voltage Reference Select                          
#define REF0CN_REFSL__VREF          0x00 ///< Use the VREF pin as the voltage reference.        
#define REF0CN_REFSL__VDD           0x08 ///< Use VDD as the voltage reference.                 
                                                                                                
#define REF0CN_REFLV__BMASK         0x10 ///< Voltage Reference Output Level                    
#define REF0CN_REFLV__SHIFT         0x04 ///< Voltage Reference Output Level                    
#define REF0CN_REFLV__1P5           0x00 ///< Internal voltage reference set to 1.5 V.          
#define REF0CN_REFLV__2P2           0x10 ///< Internal voltage reference set to 2.2 V.          
                                                                                                
#define REF0CN_ZTCEN__BMASK         0x20 ///< Zero-TempCo Bias Enable                           
#define REF0CN_ZTCEN__SHIFT         0x05 ///< Zero-TempCo Bias Enable                           
#define REF0CN_ZTCEN__AUTOMATIC     0x00 ///< Zero-TC bias generator automatically enabled when 
                                         ///< needed.                                           
#define REF0CN_ZTCEN__FORCE_ENABLED 0x20 ///< Zero-TC bias generator forced on.                 
                                                                                                
//------------------------------------------------------------------------------
// REG0CN Enums (Voltage Regulator Control @ 0xC9)
//------------------------------------------------------------------------------
#define REG0CN_DROPOUT__BMASK   0x01 ///< Voltage Regulator Dropout Indicator     
#define REG0CN_DROPOUT__SHIFT   0x00 ///< Voltage Regulator Dropout Indicator     
#define REG0CN_DROPOUT__NOT_SET 0x00 ///< Voltage Regulator is not in dropout.    
#define REG0CN_DROPOUT__SET     0x01 ///< Voltage Regulator is in or near dropout.
                                                                                  
#define REG0CN_REGMD__BMASK     0x10 ///< Voltage Regulator Output Mode           
#define REG0CN_REGMD__SHIFT     0x04 ///< Voltage Regulator Output Mode           
#define REG0CN_REGMD__2P1       0x00 ///< Voltage Regulator output is 2.1 V.      
#define REG0CN_REGMD__2P6       0x10 ///< Voltage Regulator output is 2.6 V.      
                                                                                  
#define REG0CN_REGDIS__BMASK    0x80 ///< Voltage Regulator Disable               
#define REG0CN_REGDIS__SHIFT    0x07 ///< Voltage Regulator Disable               
#define REG0CN_REGDIS__ENABLED  0x00 ///< Enable the Voltage Regulator.           
#define REG0CN_REGDIS__DISABLED 0x80 ///< Disable the Voltage Regulator.          
                                                                                  
//------------------------------------------------------------------------------
// EMI0CF Enums (External Memory Configuration @ 0xB2)
//------------------------------------------------------------------------------
#define EMI0CF_EALE__FMASK                    0x03 ///< ALE Pulse-Width Select                            
#define EMI0CF_EALE__SHIFT                    0x00 ///< ALE Pulse-Width Select                            
#define EMI0CF_EALE__1_CLOCK                  0x00 ///< ALE high and ALE low pulse width = 1 SYSCLK cycle.
#define EMI0CF_EALE__2_CLOCKS                 0x01 ///< ALE high and ALE low pulse width = 2 SYSCLK       
                                                   ///< cycles.                                           
#define EMI0CF_EALE__3_CLOCKS                 0x02 ///< ALE high and ALE low pulse width = 3 SYSCLK       
                                                   ///< cycles.                                           
#define EMI0CF_EALE__4_CLOCKS                 0x03 ///< ALE high and ALE low pulse width = 4 SYSCLK       
                                                   ///< cycles.                                           
                                                                                                          
#define EMI0CF_EMD__FMASK                     0x0C ///< EMIF Operating Mode Select                        
#define EMI0CF_EMD__SHIFT                     0x02 ///< EMIF Operating Mode Select                        
#define EMI0CF_EMD__INTERNAL_ONLY             0x00 ///< Internal Only: MOVX accesses on-chip XRAM only.   
                                                   ///< All effective addresses alias to on-chip memory   
                                                   ///< space.                                            
#define EMI0CF_EMD__SPLIT_WITHOUT_BANK_SELECT 0x04 ///< Split Mode without Bank Select: Accesses below the
                                                   ///< internal XRAM boundary are directed on-chip.      
                                                   ///< Accesses above the internal XRAM boundary are     
                                                   ///< directed off-chip. 8-bit off-chip MOVX operations 
                                                   ///< use the current contents of the Address high port 
                                                   ///< latches to resolve the upper address byte. To     
                                                   ///< access off chip space, EMI0CN must be set to a    
                                                   ///< page that is not contained in the on-chip address 
                                                   ///< space.                                            
#define EMI0CF_EMD__SPLIT_WITH_BANK_SELECT    0x08 ///< Split Mode with Bank Select: Accesses below the   
                                                   ///< internal XRAM boundary are directed on-chip.      
                                                   ///< Accesses above the internal XRAM boundary are     
                                                   ///< directed off-chip. 8-bit off-chip MOVX operations 
                                                   ///< uses the contents of EMI0CN to determine the high-
                                                   ///< byte of the address.                              
#define EMI0CF_EMD__EXTERNAL_ONLY             0x0C ///< External Only: MOVX accesses off-chip XRAM only.  
                                                   ///< On-chip XRAM is not visible to the core.          
                                                                                                          
#define EMI0CF_MUXMD__BMASK                   0x10 ///< EMIF Multiplex Mode Select                        
#define EMI0CF_MUXMD__SHIFT                   0x04 ///< EMIF Multiplex Mode Select                        
#define EMI0CF_MUXMD__MULTIPLEXED             0x00 ///< EMIF operates in multiplexed address/data mode.   
#define EMI0CF_MUXMD__NON_MULTIPLEXED         0x10 ///< EMIF operates in non-multiplexed mode (separate   
                                                   ///< address and data pins).                           
                                                                                                          
//------------------------------------------------------------------------------
// EMI0CN Enums (External Memory Interface Control @ 0xAA)
//------------------------------------------------------------------------------
#define EMI0CN_PGSEL__FMASK 0xFF ///< XRAM Page Select
#define EMI0CN_PGSEL__SHIFT 0x00 ///< XRAM Page Select
                                                      
//------------------------------------------------------------------------------
// EMI0TC Enums (External Memory Timing Control @ 0xAA)
//------------------------------------------------------------------------------
#define EMI0TC_AHOLD__FMASK      0x03 ///< EMIF Address Hold Time                      
#define EMI0TC_AHOLD__SHIFT      0x00 ///< EMIF Address Hold Time                      
#define EMI0TC_AHOLD__0_CLOCKS   0x00 ///< Address hold time = 0 SYSCLK cycles.        
#define EMI0TC_AHOLD__1_CLOCK    0x01 ///< Address hold time = 1 SYSCLK cycle.         
#define EMI0TC_AHOLD__2_CLOCKS   0x02 ///< Address hold time = 2 SYSCLK cycles.        
#define EMI0TC_AHOLD__3_CLOCKS   0x03 ///< Address hold time = 3 SYSCLK cycles.        
                                                                                       
#define EMI0TC_PWIDTH__FMASK     0x3C ///< EMIF /WR and /RD Pulse-Width Control        
#define EMI0TC_PWIDTH__SHIFT     0x02 ///< EMIF /WR and /RD Pulse-Width Control        
#define EMI0TC_PWIDTH__1_CLOCK   0x00 ///< /WR and /RD pulse width is 1 SYSCLK cycle.  
#define EMI0TC_PWIDTH__2_CLOCKS  0x04 ///< /WR and /RD pulse width is 2 SYSCLK cycles. 
#define EMI0TC_PWIDTH__3_CLOCKS  0x08 ///< /WR and /RD pulse width is 3 SYSCLK cycles. 
#define EMI0TC_PWIDTH__4_CLOCKS  0x0C ///< /WR and /RD pulse width is 4 SYSCLK cycles. 
#define EMI0TC_PWIDTH__5_CLOCKS  0x10 ///< /WR and /RD pulse width is 5 SYSCLK cycles. 
#define EMI0TC_PWIDTH__6_CLOCKS  0x14 ///< /WR and /RD pulse width is 6 SYSCLK cycles. 
#define EMI0TC_PWIDTH__7_CLOCKS  0x18 ///< /WR and /RD pulse width is 7 SYSCLK cycles. 
#define EMI0TC_PWIDTH__8_CLOCKS  0x1C ///< /WR and /RD pulse width is 8 SYSCLK cycles. 
#define EMI0TC_PWIDTH__9_CLOCKS  0x20 ///< /WR and /RD pulse width is 9 SYSCLK cycles. 
#define EMI0TC_PWIDTH__10_CLOCKS 0x24 ///< /WR and /RD pulse width is 10 SYSCLK cycles.
#define EMI0TC_PWIDTH__11_CLOCKS 0x28 ///< /WR and /RD pulse width is 11 SYSCLK cycles.
#define EMI0TC_PWIDTH__12_CLOCKS 0x2C ///< /WR and /RD pulse width is 12 SYSCLK cycles.
#define EMI0TC_PWIDTH__13_CLOCKS 0x30 ///< /WR and /RD pulse width is 13 SYSCLK cycles.
#define EMI0TC_PWIDTH__14_CLOCKS 0x34 ///< /WR and /RD pulse width is 14 SYSCLK cycles.
#define EMI0TC_PWIDTH__15_CLOCKS 0x38 ///< /WR and /RD pulse width is 15 SYSCLK cycles.
#define EMI0TC_PWIDTH__16_CLOCKS 0x3C ///< /WR and /RD pulse width is 16 SYSCLK cycles.
                                                                                       
#define EMI0TC_ASETUP__FMASK     0xC0 ///< EMIF Address Setup Time                     
#define EMI0TC_ASETUP__SHIFT     0x06 ///< EMIF Address Setup Time                     
#define EMI0TC_ASETUP__0_CLOCKS  0x00 ///< Address setup time = 0 SYSCLK cycles.       
#define EMI0TC_ASETUP__1_CLOCK   0x40 ///< Address setup time = 1 SYSCLK cycle.        
#define EMI0TC_ASETUP__2_CLOCKS  0x80 ///< Address setup time = 2 SYSCLK cycles.       
#define EMI0TC_ASETUP__3_CLOCKS  0xC0 ///< Address setup time = 3 SYSCLK cycles.       
                                                                                       
#endif // SI_C8051F580_REGISTER_ENUMS_H
//-eof--------------------------------------------------------------------------

