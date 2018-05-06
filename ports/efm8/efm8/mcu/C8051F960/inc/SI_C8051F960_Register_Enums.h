//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  C8051F960_GM
//  C8051F960_GQ
//  C8051F961_GM
//  C8051F962_GM
//  C8051F962_GQ
//  C8051F963_GM
//  C8051F964_GM
//  C8051F964_GQ
//  C8051F965_GM
//  C8051F966_GM
//  C8051F966_GQ
//  C8051F967_GM
//  C8051F968_GM
//  C8051F968_GQ
//  C8051F969_GM

#ifndef SI_C8051F960_REGISTER_ENUMS_H
#define SI_C8051F960_REGISTER_ENUMS_H

//Standard device includes
#include "SI_C8051F960_Defs.h"
//------------------------------------------------------------------------------
// ADC0AC Enums (ADC0 Accumulator Configuration @ 0xBA)
//------------------------------------------------------------------------------
#define ADC0AC_ADRPT__FMASK            0x07 ///< Repeat Count                                      
#define ADC0AC_ADRPT__SHIFT            0x00 ///< Repeat Count                                      
#define ADC0AC_ADRPT__ACC_1            0x00 ///< Perform and Accumulate 1 conversion (not used in  
                                            ///< 12-bit mode).                                     
#define ADC0AC_ADRPT__ACC_4            0x01 ///< Perform and Accumulate 4 conversions (1 conversion
                                            ///< in 12-bit mode).                                  
#define ADC0AC_ADRPT__ACC_8            0x02 ///< Perform and Accumulate 8 conversions (2           
                                            ///< conversions in 12-bit mode).                      
#define ADC0AC_ADRPT__ACC_16           0x03 ///< Perform and Accumulate 16 conversions (4          
                                            ///< conversions in 12-bit mode).                      
#define ADC0AC_ADRPT__ACC_32           0x04 ///< Perform and Accumulate 32 conversions (8          
                                            ///< conversions in 12-bit mode).                      
#define ADC0AC_ADRPT__ACC_64           0x05 ///< Perform and Accumulate 64 conversions (16         
                                            ///< conversions in 12-bit mode).                      
                                                                                                   
#define ADC0AC_ADSJST__FMASK           0x38 ///< Accumulator Shift and Justify                     
#define ADC0AC_ADSJST__SHIFT           0x03 ///< Accumulator Shift and Justify                     
#define ADC0AC_ADSJST__RIGHT_NO_SHIFT  0x00 ///< Right justified. No shifting applied.             
#define ADC0AC_ADSJST__RIGHT_SHIFT_1   0x08 ///< Right justified. Shifted right by 1 bit.          
#define ADC0AC_ADSJST__RIGHT_SHIFT_2   0x10 ///< Right justified. Shifted right by 2 bits.         
#define ADC0AC_ADSJST__RIGHT_SHIFT_3   0x18 ///< Right justified. Shifted right by 3 bits.         
#define ADC0AC_ADSJST__LEFT_NO_SHIFT   0x20 ///< Left justified. No shifting applied.              
                                                                                                   
#define ADC0AC_ADAE__BMASK             0x40 ///< Accumulate Enable                                 
#define ADC0AC_ADAE__SHIFT             0x06 ///< Accumulate Enable                                 
#define ADC0AC_ADAE__ACC_DISABLED      0x00 ///< ADC0H:ADC0L contain the result of the latest      
                                            ///< conversion when Burst Mode is disabled.           
#define ADC0AC_ADAE__ACC_ENABLED       0x40 ///< ADC0H:ADC0L contain the accumulated conversion    
                                            ///< results when Burst Mode is disabled. Firmware must
                                            ///< write 0x0000 to ADC0H:ADC0L to clear the          
                                            ///< accumulated result.                               
                                                                                                   
#define ADC0AC_AD12BE__BMASK           0x80 ///< 12-Bit Mode Enable                                
#define ADC0AC_AD12BE__SHIFT           0x07 ///< 12-Bit Mode Enable                                
#define ADC0AC_AD12BE__12_BIT_DISABLED 0x00 ///< Disable 12-bit mode.                              
#define ADC0AC_AD12BE__12_BIT_ENABLED  0x80 ///< Enable 12-bit mode.                               
                                                                                                   
//------------------------------------------------------------------------------
// ADC0CF Enums (ADC0 Configuration @ 0xBC)
//------------------------------------------------------------------------------
#define ADC0CF_ADGN__BMASK         0x01 ///< Gain Control                                      
#define ADC0CF_ADGN__SHIFT         0x00 ///< Gain Control                                      
#define ADC0CF_ADGN__GAIN_0P5      0x00 ///< The on-chip PGA gain is 0.5.                      
#define ADC0CF_ADGN__GAIN_1        0x01 ///< The on-chip PGA gain is 1.                        
                                                                                               
#define ADC0CF_ADTM__BMASK         0x02 ///< Track Mode                                        
#define ADC0CF_ADTM__SHIFT         0x01 ///< Track Mode                                        
#define ADC0CF_ADTM__TRACK_NORMAL  0x00 ///< Normal Track Mode. When ADC0 is enabled,          
                                        ///< conversion begins immediately following the start-
                                        ///< of-conversion signal.                             
#define ADC0CF_ADTM__TRACK_DELAYED 0x02 ///< Delayed Track Mode. When ADC0 is enabled,         
                                        ///< conversion begins 3 SAR clock cycles following the
                                        ///< start-of-conversion signal. The ADC is allowed to 
                                        ///< track during this time.                           
                                                                                               
#define ADC0CF_AD8BE__BMASK        0x04 ///< 8-Bit Mode Enable                                 
#define ADC0CF_AD8BE__SHIFT        0x02 ///< 8-Bit Mode Enable                                 
#define ADC0CF_AD8BE__NORMAL       0x00 ///< ADC0 operates in 10-bit or 12-bit mode (normal    
                                        ///< operation).                                       
#define ADC0CF_AD8BE__8_BIT        0x04 ///< ADC0 operates in 8-bit mode.                      
                                                                                               
#define ADC0CF_ADSC__FMASK         0xF8 ///< SAR Clock Divider                                 
#define ADC0CF_ADSC__SHIFT         0x03 ///< SAR Clock Divider                                 
                                                                                               
//------------------------------------------------------------------------------
// ADC0CN Enums (ADC0 Control @ 0xE8)
//------------------------------------------------------------------------------
#define ADC0CN_ADCM__FMASK            0x07 ///< Start of Conversion Mode Select                   
#define ADC0CN_ADCM__SHIFT            0x00 ///< Start of Conversion Mode Select                   
#define ADC0CN_ADCM__ADBUSY           0x00 ///< ADC0 conversion initiated on write of 1 to ADBUSY.
#define ADC0CN_ADCM__TIMER0           0x01 ///< ADC0 conversion initiated on overflow of Timer 0. 
#define ADC0CN_ADCM__TIMER2           0x02 ///< ADC0 conversion initiated on overflow of Timer 2. 
#define ADC0CN_ADCM__TIMER3           0x03 ///< ADC0 conversion initiated on overflow of Timer 3. 
#define ADC0CN_ADCM__CNVSTR           0x04 ///< ADC0 conversion initiated on rising edge of       
                                           ///< CNVSTR.                                           
                                                                                                  
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
#define ADC0CN_ADBMEN__BURST_DISABLED 0x00 ///< Disable ADC0 burst mode.                          
#define ADC0CN_ADBMEN__BURST_ENABLED  0x40 ///< Enable ADC0 burst mode.                           
                                                                                                  
#define ADC0CN_ADEN__BMASK            0x80 ///< ADC Enable                                        
#define ADC0CN_ADEN__SHIFT            0x07 ///< ADC Enable                                        
#define ADC0CN_ADEN__DISABLED         0x00 ///< Disable ADC0 (low-power shutdown).                
#define ADC0CN_ADEN__ENABLED          0x80 ///< Enable ADC0 (active and ready for data            
                                           ///< conversions).                                     
                                                                                                  
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
#define ADC0MX_ADC0MX__FMASK   0x1F ///< AMUX0 Positive Input Selection
#define ADC0MX_ADC0MX__SHIFT   0x00 ///< AMUX0 Positive Input Selection
#define ADC0MX_ADC0MX__ADC0P0  0x00 ///< Select channel ADC0.0.        
#define ADC0MX_ADC0MX__ADC0P1  0x01 ///< Select channel ADC0.1.        
#define ADC0MX_ADC0MX__ADC0P2  0x02 ///< Select channel ADC0.2.        
#define ADC0MX_ADC0MX__ADC0P3  0x03 ///< Select channel ADC0.3.        
#define ADC0MX_ADC0MX__ADC0P4  0x04 ///< Select channel ADC0.4.        
#define ADC0MX_ADC0MX__ADC0P5  0x05 ///< Select channel ADC0.5.        
#define ADC0MX_ADC0MX__ADC0P6  0x06 ///< Select channel ADC0.6.        
#define ADC0MX_ADC0MX__ADC0P7  0x07 ///< Select channel ADC0.7.        
#define ADC0MX_ADC0MX__ADC0P12 0x0C ///< Select channel ADC0.12.       
#define ADC0MX_ADC0MX__ADC0P13 0x0D ///< Select channel ADC0.13.       
#define ADC0MX_ADC0MX__ADC0P14 0x0E ///< Select channel ADC0.14.       
#define ADC0MX_ADC0MX__ADC0P15 0x0F ///< Select channel ADC0.15.       
#define ADC0MX_ADC0MX__ADC0P16 0x10 ///< Select channel ADC0.16.       
#define ADC0MX_ADC0MX__ADC0P17 0x11 ///< Select channel ADC0.17.       
#define ADC0MX_ADC0MX__ADC0P18 0x12 ///< Select channel ADC0.18.       
#define ADC0MX_ADC0MX__ADC0P19 0x13 ///< Select channel ADC0.19.       
#define ADC0MX_ADC0MX__TEMP    0x1B ///< Temperature Sensor.           
#define ADC0MX_ADC0MX__VBAT    0x1C ///< VBAT Supply Voltage.          
#define ADC0MX_ADC0MX__LDO     0x1D ///< Internal LDO regulator output.
#define ADC0MX_ADC0MX__VDC     0x1E ///< VDC Supply Voltage.           
#define ADC0MX_ADC0MX__GND     0x1F ///< Ground.                       
                                                                       
//------------------------------------------------------------------------------
// ADC0PWR Enums (ADC0 Power Control @ 0xBA)
//------------------------------------------------------------------------------
#define ADC0PWR_ADPWR__FMASK              0x0F ///< Burst Mode Power Up Time                         
#define ADC0PWR_ADPWR__SHIFT              0x00 ///< Burst Mode Power Up Time                         
                                                                                                     
#define ADC0PWR_ADLPM__BMASK              0x80 ///< Low Power Mode Enable                            
#define ADC0PWR_ADLPM__SHIFT              0x07 ///< Low Power Mode Enable                            
#define ADC0PWR_ADLPM__LOW_POWER_DISABLED 0x00 ///< Disable low power mode.                          
#define ADC0PWR_ADLPM__LOW_POWER_ENABLED  0x80 ///< Enable low power mode (requires extended tracking
                                               ///< time).                                           
                                                                                                     
//------------------------------------------------------------------------------
// ADC0TK Enums (ADC0 Burst Mode Track Time @ 0xBB)
//------------------------------------------------------------------------------
#define ADC0TK_ADTK__FMASK 0x3F ///< Burst Mode Tracking Time
#define ADC0TK_ADTK__SHIFT 0x00 ///< Burst Mode Tracking Time
                                                             
//------------------------------------------------------------------------------
// AES0BCFG Enums (AES Block Configuration @ 0xE9)
//------------------------------------------------------------------------------
#define AES0BCFG_KSIZE__FMASK    0x03 ///< AES Key Size                                    
#define AES0BCFG_KSIZE__SHIFT    0x00 ///< AES Key Size                                    
#define AES0BCFG_KSIZE__128_BITS 0x00 ///< 128 bits (16 bytes).                            
#define AES0BCFG_KSIZE__196_BITS 0x01 ///< 198 bits (24 bytes).                            
#define AES0BCFG_KSIZE__256_BITS 0x02 ///< 256 bits (32 bytes).                            
                                                                                           
#define AES0BCFG_ENCMD__BMASK    0x04 ///< Encryption/Decryption Select                    
#define AES0BCFG_ENCMD__SHIFT    0x02 ///< Encryption/Decryption Select                    
#define AES0BCFG_ENCMD__DECRYPT  0x00 ///< Select a decryption operation.                  
#define AES0BCFG_ENCMD__ENCRYPT  0x04 ///< Select an encryption operation.                 
                                                                                           
#define AES0BCFG_START__BMASK    0x08 ///< AES Start                                       
#define AES0BCFG_START__SHIFT    0x03 ///< AES Start                                       
#define AES0BCFG_START__CLEAR    0x00 ///< Reset the AES module.                           
#define AES0BCFG_START__START    0x08 ///< Start an encryption or decryption operation.    
                                                                                           
#define AES0BCFG_BUSY__BMASK     0x10 ///< AES Busy                                        
#define AES0BCFG_BUSY__SHIFT     0x04 ///< AES Busy                                        
#define AES0BCFG_BUSY__NOT_SET   0x00 ///< The AES block is not completing an encryption or
                                      ///< decryption operation.                           
#define AES0BCFG_BUSY__SET       0x10 ///< The AES block is completing an encryption or    
                                      ///< decryption operation.                           
                                                                                           
#define AES0BCFG_DONE__BMASK     0x20 ///< Done Flag                                       
#define AES0BCFG_DONE__SHIFT     0x05 ///< Done Flag                                       
#define AES0BCFG_DONE__NOT_SET   0x00 ///< The encryption or decryption operation has not  
                                      ///< started or is in progress.                      
#define AES0BCFG_DONE__SET       0x20 ///< The encyrption or decryption operation is       
                                      ///< complete.                                       
                                                                                           
//------------------------------------------------------------------------------
// AES0BIN Enums (AES Block Input @ 0xEB)
//------------------------------------------------------------------------------
#define AES0BIN_AES0BIN__FMASK 0xFF ///< AES Block Input
#define AES0BIN_AES0BIN__SHIFT 0x00 ///< AES Block Input
                                                        
//------------------------------------------------------------------------------
// AES0DCFG Enums (AES Data Configuration @ 0xEA)
//------------------------------------------------------------------------------
#define AES0DCFG_XORIN__BMASK       0x01 ///< XOR Input Enable                                 
#define AES0DCFG_XORIN__SHIFT       0x00 ///< XOR Input Enable                                 
#define AES0DCFG_XORIN__DISABLED    0x00 ///< Disable the XOR data path of the AES input.      
#define AES0DCFG_XORIN__ENABLED     0x01 ///< Enable the XOR data path of the AES input.       
                                                                                               
#define AES0DCFG_OUTSEL__FMASK      0x06 ///< Output Data Select                               
#define AES0DCFG_OUTSEL__SHIFT      0x01 ///< Output Data Select                               
#define AES0DCFG_OUTSEL__DIRECT_OUT 0x00 ///< The AES0YOUT register targets the direct AES     
                                         ///< output data.                                     
#define AES0DCFG_OUTSEL__XOR_OUT    0x02 ///< The AES0YOUT register targets the AES output data
                                         ///< XORed with AES0XIN.                              
#define AES0DCFG_OUTSEL__KEY        0x04 ///< The AES0YOUT register targets the inverse key.   
                                                                                               
//------------------------------------------------------------------------------
// AES0KIN Enums (AES Key Input @ 0xED)
//------------------------------------------------------------------------------
#define AES0KIN_AES0KIN__FMASK 0xFF ///< AES Key Input
#define AES0KIN_AES0KIN__SHIFT 0x00 ///< AES Key Input
                                                      
//------------------------------------------------------------------------------
// AES0XIN Enums (AES XOR Input @ 0xEC)
//------------------------------------------------------------------------------
#define AES0XIN_AES0XIN__FMASK 0xFF ///< AES XOR Input
#define AES0XIN_AES0XIN__SHIFT 0x00 ///< AES XOR Input
                                                      
//------------------------------------------------------------------------------
// AES0YOUT Enums (AES Y Output @ 0xF5)
//------------------------------------------------------------------------------
#define AES0YOUT_AES0YOUT__FMASK 0xFF ///< AES Y Output
#define AES0YOUT_AES0YOUT__SHIFT 0x00 ///< AES Y Output
                                                       
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
// PSBANK Enums (Program Space Bank Select @ 0x84)
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
// SFRPGCN Enums (SFR Page Control @ 0x8E)
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
// CLKMODE Enums (Clock Mode @ 0xFD)
//------------------------------------------------------------------------------
#define CLKMODE_LPMEN__BMASK    0x04 ///< Low Power Mode Enable                            
#define CLKMODE_LPMEN__SHIFT    0x02 ///< Low Power Mode Enable                            
#define CLKMODE_LPMEN__DISABLED 0x00 ///< Disable low power active and idle modes.         
#define CLKMODE_LPMEN__ENABLED  0x04 ///< Enable low power active and low power idle modes.
                                                                                           
//------------------------------------------------------------------------------
// CLKSEL Enums (Clock Select @ 0xA9)
//------------------------------------------------------------------------------
#define CLKSEL_CLKSL__FMASK           0x07 ///< Clock Source Select                               
#define CLKSEL_CLKSL__SHIFT           0x00 ///< Clock Source Select                               
#define CLKSEL_CLKSL__HFOSC           0x00 ///< Clock derived from the internal precision High-   
                                           ///< Frequency Oscillator.                             
#define CLKSEL_CLKSL__EXTOSC          0x01 ///< Clock derived from the External Oscillator        
                                           ///< circuit.                                          
#define CLKSEL_CLKSL__LPO_DIV_8       0x02 ///< Clock derived from the Internal Low Power         
                                           ///< Oscillator divided by 8.                          
#define CLKSEL_CLKSL__RTC             0x03 ///< Clock derived from the RTC.                       
#define CLKSEL_CLKSL__LPOSC           0x04 ///< Clock derived from the Internal Low Power         
                                           ///< Oscillator.                                       
                                                                                                  
#define CLKSEL_CLKDIV__FMASK          0x70 ///< Clock Source Divider                              
#define CLKSEL_CLKDIV__SHIFT          0x04 ///< Clock Source Divider                              
#define CLKSEL_CLKDIV__SYSCLK_DIV_1   0x00 ///< SYSCLK is equal to selected clock source divided  
                                           ///< by 1.                                             
#define CLKSEL_CLKDIV__SYSCLK_DIV_2   0x10 ///< SYSCLK is equal to selected clock source divided  
                                           ///< by 2.                                             
#define CLKSEL_CLKDIV__SYSCLK_DIV_4   0x20 ///< SYSCLK is equal to selected clock source divided  
                                           ///< by 4.                                             
#define CLKSEL_CLKDIV__SYSCLK_DIV_8   0x30 ///< SYSCLK is equal to selected clock source divided  
                                           ///< by 8.                                             
#define CLKSEL_CLKDIV__SYSCLK_DIV_16  0x40 ///< SYSCLK is equal to selected clock source divided  
                                           ///< by 16.                                            
#define CLKSEL_CLKDIV__SYSCLK_DIV_32  0x50 ///< SYSCLK is equal to selected clock source divided  
                                           ///< by 32.                                            
#define CLKSEL_CLKDIV__SYSCLK_DIV_64  0x60 ///< SYSCLK is equal to selected clock source divided  
                                           ///< by 64.                                            
#define CLKSEL_CLKDIV__SYSCLK_DIV_128 0x70 ///< SYSCLK is equal to selected clock source divided  
                                           ///< by 128.                                           
                                                                                                  
#define CLKSEL_CLKRDY__BMASK          0x80 ///< System Clock Divider Clock Ready Flag             
#define CLKSEL_CLKRDY__SHIFT          0x07 ///< System Clock Divider Clock Ready Flag             
#define CLKSEL_CLKRDY__NOT_SET        0x00 ///< The selected clock divide setting has not been    
                                           ///< applied to the system clock.                      
#define CLKSEL_CLKRDY__SET            0x80 ///< The selected clock divide setting has been applied
                                           ///< to the system clock.                              
                                                                                                  
//------------------------------------------------------------------------------
// PCLKACT Enums (Peripheral Active Clock Enable @ 0xF5)
//------------------------------------------------------------------------------
#define PCLKACT_PCLKACT0__BMASK    0x01 ///< Low Power Active Mode Peripheral Set 0 Enable     
#define PCLKACT_PCLKACT0__SHIFT    0x00 ///< Low Power Active Mode Peripheral Set 0 Enable     
#define PCLKACT_PCLKACT0__DISABLED 0x00 ///< Clocks to UART0, Timer 3, SPI0, and the SMBus     
                                        ///< revert to the PCLKEN0 setting in low power active 
                                        ///< mode.                                             
#define PCLKACT_PCLKACT0__ENABLED  0x01 ///< Enable clocks to UART0, Timer 3, SPI0, and the    
                                        ///< SMBus in low power active mode.                   
                                                                                               
#define PCLKACT_PCLKACT1__BMASK    0x02 ///< Low Power Active Mode Peripheral Set 1 Enable     
#define PCLKACT_PCLKACT1__SHIFT    0x01 ///< Low Power Active Mode Peripheral Set 1 Enable     
#define PCLKACT_PCLKACT1__DISABLED 0x00 ///< Clocks to ADC0 and PCA0 revert to the PCLKEN1     
                                        ///< setting in low power active mode.                 
#define PCLKACT_PCLKACT1__ENABLED  0x02 ///< Enable clocks to ADC0 and PCA0 in low power active
                                        ///< mode.                                             
                                                                                               
#define PCLKACT_PCLKACT2__BMASK    0x04 ///< Low Power Active Mode Peripheral Set 2 Enable     
#define PCLKACT_PCLKACT2__SHIFT    0x02 ///< Low Power Active Mode Peripheral Set 2 Enable     
#define PCLKACT_PCLKACT2__DISABLED 0x00 ///< Clocks to Timer 0, Timer 1, Timer 2, and CRC0     
                                        ///< revert to the PCLKEN2 setting in low power active 
                                        ///< mode.                                             
#define PCLKACT_PCLKACT2__ENABLED  0x04 ///< Enable clocks to Timer 0, Timer 1, Timer 2, and   
                                        ///< CRC0 in low power active mode.                    
                                                                                               
#define PCLKACT_PCLKACT3__BMASK    0x08 ///< Low Power Active Mode Peripheral Set 3 Enable     
#define PCLKACT_PCLKACT3__SHIFT    0x03 ///< Low Power Active Mode Peripheral Set 3 Enable     
#define PCLKACT_PCLKACT3__DISABLED 0x00 ///< Clocks to RTC0, Pulse Counter, and PMU0 revert to 
                                        ///< the PCLKEN3 setting in low power active mode.     
#define PCLKACT_PCLKACT3__ENABLED  0x08 ///< Enable clocks to RTC0, Pulse Counter, and PMU0 in 
                                        ///< low power active mode.                            
                                                                                               
//------------------------------------------------------------------------------
// PCLKEN Enums (Low Power Peripheral Clock Enable @ 0xFE)
//------------------------------------------------------------------------------
#define PCLKEN_PCLKEN0__BMASK    0x01 ///< Low Power Idle Mode Peripheral Set 0 Enable       
#define PCLKEN_PCLKEN0__SHIFT    0x00 ///< Low Power Idle Mode Peripheral Set 0 Enable       
#define PCLKEN_PCLKEN0__DISABLED 0x00 ///< Disable clocks to UART0, Timer 3, SPI0, and the   
                                      ///< SMBus in low power idle mode.                     
#define PCLKEN_PCLKEN0__ENABLED  0x01 ///< Enable clocks to UART0, Timer 3, SPI0, and the    
                                      ///< SMBus in low power idle mode.                     
                                                                                             
#define PCLKEN_PCLKEN1__BMASK    0x02 ///< Low Power Idle Mode Peripheral Set 1 Enable       
#define PCLKEN_PCLKEN1__SHIFT    0x01 ///< Low Power Idle Mode Peripheral Set 1 Enable       
#define PCLKEN_PCLKEN1__DISABLED 0x00 ///< Disable clocks to ADC0 and PCA0 in low power idle 
                                      ///< mode.                                             
#define PCLKEN_PCLKEN1__ENABLED  0x02 ///< Enable clocks to ADC0 and PCA0 in low power idle  
                                      ///< mode.                                             
                                                                                             
#define PCLKEN_PCLKEN2__BMASK    0x04 ///< Low Power Idle Mode Peripheral Set 2 Enable       
#define PCLKEN_PCLKEN2__SHIFT    0x02 ///< Low Power Idle Mode Peripheral Set 2 Enable       
#define PCLKEN_PCLKEN2__DISABLED 0x00 ///< Disable clocks to Timer 0, Timer 1, Timer 2, and  
                                      ///< CRC0 in low power idle mode.                      
#define PCLKEN_PCLKEN2__ENABLED  0x04 ///< Enable clocks to Timer 0, Timer 1, Timer 2, and   
                                      ///< CRC0 in low power idle mode.                      
                                                                                             
#define PCLKEN_PCLKEN3__BMASK    0x08 ///< Low Power Idle Mode Peripheral Set 3 Enable       
#define PCLKEN_PCLKEN3__SHIFT    0x03 ///< Low Power Idle Mode Peripheral Set 3 Enable       
#define PCLKEN_PCLKEN3__DISABLED 0x00 ///< Disable clocks to RTC0, Pulse Counter, and PMU0 in
                                      ///< low power idle mode.                              
#define PCLKEN_PCLKEN3__ENABLED  0x08 ///< Enable clocks to RTC0, Pulse Counter, and PMU0 in 
                                      ///< low power idle mode.                              
                                                                                             
//------------------------------------------------------------------------------
// CPT0CN Enums (Comparator 0 Control @ 0x9B)
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
// CPT0MD Enums (Comparator 0 Mode @ 0x9D)
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
// CPT0MX Enums (Comparator 0 Multiplexer Selection @ 0x9F)
//------------------------------------------------------------------------------
#define CPT0MX_CMXP__FMASK        0x0F ///< Comparator Positive Input MUX Selection
#define CPT0MX_CMXP__SHIFT        0x00 ///< Comparator Positive Input MUX Selection
#define CPT0MX_CMXP__CMP0P0       0x00 ///< External pin CMP0P.0.                  
#define CPT0MX_CMXP__CMP0P1       0x01 ///< External pin CMP0P.1.                  
#define CPT0MX_CMXP__CMP0P2       0x02 ///< External pin CMP0P.2.                  
#define CPT0MX_CMXP__CMP0P3       0x03 ///< External pin CMP0P.3.                  
#define CPT0MX_CMXP__CMP0P6       0x06 ///< External pin CMP0P.6.                  
#define CPT0MX_CMXP__CMP0P7       0x07 ///< External pin CMP0P.7.                  
#define CPT0MX_CMXP__CMP0P8       0x08 ///< External pin CMP0P.8.                  
#define CPT0MX_CMXP__CMP0P9       0x09 ///< External pin CMP0P.9.                  
#define CPT0MX_CMXP__CS_COMPARE   0x0C ///< Capacitive Sense Compare.              
#define CPT0MX_CMXP__VBAT_DIV_2   0x0D ///< VBAT divided by 2.                     
#define CPT0MX_CMXP__VBAT         0x0E ///< VBAT Supply Voltage.                   
#define CPT0MX_CMXP__NONE         0x0F ///< No input selected.                     
                                                                                   
#define CPT0MX_CMXN__FMASK        0xF0 ///< Comparator Negative Input MUX Selection
#define CPT0MX_CMXN__SHIFT        0x04 ///< Comparator Negative Input MUX Selection
#define CPT0MX_CMXN__CMP0N0       0x00 ///< External pin CMP0N.0.                  
#define CPT0MX_CMXN__CMP0N1       0x10 ///< External pin CMP0N.1.                  
#define CPT0MX_CMXN__CMP0N2       0x20 ///< External pin CMP0N.2.                  
#define CPT0MX_CMXN__CMP0N6       0x60 ///< External pin CMP0N.6.                  
#define CPT0MX_CMXN__CMP0N7       0x70 ///< External pin CMP0N.7.                  
#define CPT0MX_CMXN__CMP0N8       0x80 ///< External pin CMP0N.8.                  
#define CPT0MX_CMXN__CMP0N9       0x90 ///< External pin CMP0N.9.                  
#define CPT0MX_CMXN__CS_COMPARE   0xC0 ///< Capacitive Sense Compare.              
#define CPT0MX_CMXN__VBAT_DIV_2   0xD0 ///< VBAT divided by 2.                     
#define CPT0MX_CMXN__INTERNAL_LDO 0xE0 ///< Internal LDO output.                   
#define CPT0MX_CMXN__GND          0xF0 ///< Ground.                                
                                                                                   
//------------------------------------------------------------------------------
// CPT1CN Enums (Comparator 1 Control @ 0x9A)
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
// CPT1MD Enums (Comparator 1 Mode @ 0x9C)
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
// CPT1MX Enums (Comparator 1 Multiplexer Selection @ 0x9E)
//------------------------------------------------------------------------------
#define CPT1MX_CMXP__FMASK        0x0F ///< Comparator Positive Input MUX Selection
#define CPT1MX_CMXP__SHIFT        0x00 ///< Comparator Positive Input MUX Selection
#define CPT1MX_CMXP__CMP1P0       0x00 ///< External pin CMP1P.0.                  
#define CPT1MX_CMXP__CMP1P1       0x01 ///< External pin CMP1P.1.                  
#define CPT1MX_CMXP__CMP1P2       0x02 ///< External pin CMP1P.2.                  
#define CPT1MX_CMXP__CMP1P3       0x03 ///< External pin CMP1P.3.                  
#define CPT1MX_CMXP__CMP1P6       0x06 ///< External pin CMP1P.6.                  
#define CPT1MX_CMXP__CMP1P7       0x07 ///< External pin CMP1P.7.                  
#define CPT1MX_CMXP__CMP1P8       0x08 ///< External pin CMP1P.8.                  
#define CPT1MX_CMXP__CMP1P9       0x09 ///< External pin CMP1P.9.                  
#define CPT1MX_CMXP__CS_COMPARE   0x0C ///< Capacitive Sense Compare.              
#define CPT1MX_CMXP__VBAT_DIV_2   0x0D ///< VBAT divided by 2.                     
#define CPT1MX_CMXP__VBAT         0x0E ///< VBAT Supply Voltage.                   
#define CPT1MX_CMXP__NONE         0x0F ///< No input selected.                     
                                                                                   
#define CPT1MX_CMXN__FMASK        0xF0 ///< Comparator Negative Input MUX Selection
#define CPT1MX_CMXN__SHIFT        0x04 ///< Comparator Negative Input MUX Selection
#define CPT1MX_CMXN__CMP1N0       0x00 ///< External pin CMP1N.0.                  
#define CPT1MX_CMXN__CMP1N1       0x10 ///< External pin CMP1N.1.                  
#define CPT1MX_CMXN__CMP1N2       0x20 ///< External pin CMP1N.2.                  
#define CPT1MX_CMXN__CMP1N6       0x60 ///< External pin CMP1N.6.                  
#define CPT1MX_CMXN__CMP1N7       0x70 ///< External pin CMP1N.7.                  
#define CPT1MX_CMXN__CMP1N8       0x80 ///< External pin CMP1N.8.                  
#define CPT1MX_CMXN__CMP1N9       0x90 ///< External pin CMP1N.9.                  
#define CPT1MX_CMXN__CS_COMPARE   0xC0 ///< Capacitive Sense Compare.              
#define CPT1MX_CMXN__VBAT_DIV_2   0xD0 ///< VBAT divided by 2.                     
#define CPT1MX_CMXN__INTERNAL_LDO 0xE0 ///< Internal LDO output.                   
#define CPT1MX_CMXN__GND          0xF0 ///< Ground.                                
                                                                                   
//------------------------------------------------------------------------------
// CRC0AUTO Enums (CRC0 Automatic Control @ 0x96)
//------------------------------------------------------------------------------
#define CRC0AUTO_CRCST__FMASK     0x3F ///< Automatic CRC Calculation Starting Block  
#define CRC0AUTO_CRCST__SHIFT     0x00 ///< Automatic CRC Calculation Starting Block  
                                                                                      
#define CRC0AUTO_CRCDN__BMASK     0x40 ///< Automatic CRC Calculation Complete        
#define CRC0AUTO_CRCDN__SHIFT     0x06 ///< Automatic CRC Calculation Complete        
#define CRC0AUTO_CRCDN__NOT_SET   0x00 ///< A CRC calculation is in progress.         
#define CRC0AUTO_CRCDN__SET       0x40 ///< A CRC calculation is not in progress.     
                                                                                      
#define CRC0AUTO_AUTOEN__BMASK    0x80 ///< Automatic CRC Calculation Enable          
#define CRC0AUTO_AUTOEN__SHIFT    0x07 ///< Automatic CRC Calculation Enable          
#define CRC0AUTO_AUTOEN__DISABLED 0x00 ///< Disable automatic CRC operations on flash.
#define CRC0AUTO_AUTOEN__ENABLED  0x80 ///< Enable automatic CRC operations on flash. 
                                                                                      
//------------------------------------------------------------------------------
// CRC0CN Enums (CRC0 Control @ 0x92)
//------------------------------------------------------------------------------
#define CRC0CN_CRCPNT__FMASK        0x03 ///< CRC Result Pointer                                
#define CRC0CN_CRCPNT__SHIFT        0x00 ///< CRC Result Pointer                                
#define CRC0CN_CRCPNT__ACCESS_B0    0x00 ///< CRC0DAT accesses bits 7-0 of the 16-bit or 32-bit 
                                         ///< CRC result.                                       
#define CRC0CN_CRCPNT__ACCESS_B1    0x01 ///< CRC0DAT accesses bits 15-8 of the 16-bit or 32-bit
                                         ///< CRC result.                                       
#define CRC0CN_CRCPNT__ACCESS_B2    0x02 ///< CRC0DAT accesses bits 7-0 of the 16-bit or bits   
                                         ///< 23-15 of the 32-bit CRC result.                   
#define CRC0CN_CRCPNT__ACCESS_B3    0x03 ///< CRC0DAT accesses bits 15-8 of the 16-bit or bits  
                                         ///< 31-24 of the 32-bit CRC result.                   
                                                                                                
#define CRC0CN_CRCVAL__BMASK        0x04 ///< CRC Initialization Value                          
#define CRC0CN_CRCVAL__SHIFT        0x02 ///< CRC Initialization Value                          
#define CRC0CN_CRCVAL__SET_ZEROES   0x00 ///< CRC result is set to 0x00000000 on write of 1 to  
                                         ///< CRCINIT.                                          
#define CRC0CN_CRCVAL__SET_ONES     0x04 ///< CRC result is set to 0xFFFFFFFF on write of 1 to  
                                         ///< CRCINIT.                                          
                                                                                                
#define CRC0CN_CRCINIT__BMASK       0x08 ///< CRC Initialization Enable                         
#define CRC0CN_CRCINIT__SHIFT       0x03 ///< CRC Initialization Enable                         
#define CRC0CN_CRCINIT__DO_NOT_INIT 0x00 ///< Do not initialize the CRC result.                 
#define CRC0CN_CRCINIT__INIT        0x08 ///< Initialize the CRC result to ones or zeroes vased 
                                         ///< on the value of CRCVAL.                           
                                                                                                
#define CRC0CN_POLYSEL__BMASK       0x10 ///< CRC Polynomial Select Bit                         
#define CRC0CN_POLYSEL__SHIFT       0x04 ///< CRC Polynomial Select Bit                         
#define CRC0CN_POLYSEL__32_BIT      0x00 ///< Use the 32-bit polynomial 0x04C11DB7 for          
                                         ///< calculating the CRC result.                       
#define CRC0CN_POLYSEL__16_BIT      0x10 ///< Use the 16-bit polynomial 0x1021 for calculating  
                                         ///< the CRC result.                                   
                                                                                                
//------------------------------------------------------------------------------
// CRC0CNT Enums (CRC0 Automatic Flash Sector Count @ 0x97)
//------------------------------------------------------------------------------
#define CRC0CNT_CRCCNT__FMASK 0x3F ///< Automatic CRC Calculation Block Count
#define CRC0CNT_CRCCNT__SHIFT 0x00 ///< Automatic CRC Calculation Block Count
                                                                             
//------------------------------------------------------------------------------
// CRC0DAT Enums (CRC0 Data Output @ 0x91)
//------------------------------------------------------------------------------
#define CRC0DAT_CRC0DAT__FMASK 0xFF ///< CRC Data Output
#define CRC0DAT_CRC0DAT__SHIFT 0x00 ///< CRC Data Output
                                                        
//------------------------------------------------------------------------------
// CRC0FLIP Enums (CRC0 Bit Flip @ 0x94)
//------------------------------------------------------------------------------
#define CRC0FLIP_CRC0FLIP__FMASK 0xFF ///< CRC0 Bit Flip
#define CRC0FLIP_CRC0FLIP__SHIFT 0x00 ///< CRC0 Bit Flip
                                                        
//------------------------------------------------------------------------------
// CRC0IN Enums (CRC0 Data Input @ 0x93)
//------------------------------------------------------------------------------
#define CRC0IN_CRC0IN__FMASK 0xFF ///< CRC Data Input
#define CRC0IN_CRC0IN__SHIFT 0x00 ///< CRC Data Input
                                                     
//------------------------------------------------------------------------------
// CRC1CN Enums (CRC1 Control @ 0xBE)
//------------------------------------------------------------------------------
#define CRC1CN_SEED__BMASK      0x01 ///< Seed Polarity                                   
#define CRC1CN_SEED__SHIFT      0x00 ///< Seed Polarity                                   
#define CRC1CN_SEED__SET_ZEROES 0x00 ///< The CRC calculation uses an initial seed of     
                                     ///< 0x0000.                                         
#define CRC1CN_SEED__SET_ONES   0x01 ///< The CRC calculation uses an initial seed of     
                                     ///< 0xFFFF.                                         
                                                                                          
#define CRC1CN_INVERT__BMASK    0x02 ///< Invert Result Enable                            
#define CRC1CN_INVERT__SHIFT    0x01 ///< Invert Result Enable                            
#define CRC1CN_INVERT__DISABLED 0x00 ///< Do not invert the CRC result in the CRC1OUT     
                                     ///< registers.                                      
#define CRC1CN_INVERT__ENABLED  0x02 ///< Invert the CRC result in the CRC1OUT registers. 
                                                                                          
#define CRC1CN_FLIP__BMASK      0x04 ///< Flip Result Enable                              
#define CRC1CN_FLIP__SHIFT      0x02 ///< Flip Result Enable                              
#define CRC1CN_FLIP__DISABLED   0x00 ///< Do not bit flip the CRC result in the CRC1OUT   
                                     ///< registers.                                      
#define CRC1CN_FLIP__ENABLED    0x04 ///< Flip the CRC result in the CRC1OUT registers.   
                                                                                          
#define CRC1CN_DMA__BMASK       0x08 ///< DMA Mode Enable                                 
#define CRC1CN_DMA__SHIFT       0x03 ///< DMA Mode Enable                                 
#define CRC1CN_DMA__DISABLED    0x00 ///< The CRC module is not in DMA mode.              
#define CRC1CN_DMA__ENABLED     0x08 ///< The CRC module is in DMA mode.                  
                                                                                          
#define CRC1CN_RESET__BMASK     0x80 ///< Module Reset and Initialize                     
#define CRC1CN_RESET__SHIFT     0x07 ///< Module Reset and Initialize                     
#define CRC1CN_RESET__NOT_SET   0x00 ///< Do not reset the CRC module or a reset operation
                                     ///< completed.                                      
#define CRC1CN_RESET__SET       0x80 ///< Reset the CRC module.                           
                                                                                          
//------------------------------------------------------------------------------
// CRC1IN Enums (CRC1 Data In @ 0xB9)
//------------------------------------------------------------------------------
#define CRC1IN_CRC1IN__FMASK 0xFF ///< CRC1 Data In
#define CRC1IN_CRC1IN__SHIFT 0x00 ///< CRC1 Data In
                                                   
//------------------------------------------------------------------------------
// CRC1OUTH Enums (CRC1 Output High Byte @ 0xBB)
//------------------------------------------------------------------------------
#define CRC1OUTH_CRC1OUTH__FMASK 0xFF ///< CRC1 Output High Byte
#define CRC1OUTH_CRC1OUTH__SHIFT 0x00 ///< CRC1 Output High Byte
                                                                
//------------------------------------------------------------------------------
// CRC1OUTL Enums (CRC1 Output Low Byte @ 0xBA)
//------------------------------------------------------------------------------
#define CRC1OUTL_CRC1OUTL__FMASK 0xFF ///< CRC1 Output Low Byte
#define CRC1OUTL_CRC1OUTL__SHIFT 0x00 ///< CRC1 Output Low Byte
                                                               
//------------------------------------------------------------------------------
// CRC1POLH Enums (CRC1 Polynomial High Byte @ 0xBD)
//------------------------------------------------------------------------------
#define CRC1POLH_CRC1POLH__FMASK 0xFF ///< CRC1 Polynomial High Byte
#define CRC1POLH_CRC1POLH__SHIFT 0x00 ///< CRC1 Polynomial High Byte
                                                                    
//------------------------------------------------------------------------------
// CRC1POLL Enums (CRC1 Polynomial Low Byte @ 0xBC)
//------------------------------------------------------------------------------
#define CRC1POLL_CRC1POLL__FMASK 0xFF ///< CRC1 Polynomial Low Byte
#define CRC1POLL_CRC1POLL__SHIFT 0x00 ///< CRC1 Polynomial Low Byte
                                                                   
//------------------------------------------------------------------------------
// DC0CF Enums (DC-DC Converter Configuration @ 0xB2)
//------------------------------------------------------------------------------
#define DC0CF_SWSEL__FMASK        0x03 ///< DC-DC Converter Power Switch Select               
#define DC0CF_SWSEL__SHIFT        0x00 ///< DC-DC Converter Power Switch Select               
#define DC0CF_SWSEL__MINIMUM_SIZE 0x00 ///< Minimum switch size, optimized for load currents  
                                       ///< smaller than 5 mA.                                
#define DC0CF_SWSEL__MAXIMUM_SIZE 0x03 ///< Maximum switch size, optimized for load currents  
                                       ///< greater than 5 mA.                                
                                                                                              
#define DC0CF_OSCDIS__BMASK       0x04 ///< DC-DC Converter Local Oscillator Disable          
#define DC0CF_OSCDIS__SHIFT       0x02 ///< DC-DC Converter Local Oscillator Disable          
#define DC0CF_OSCDIS__ENABLED     0x00 ///< The local oscillator inside the dc-dc converter is
                                       ///< enabled.                                          
#define DC0CF_OSCDIS__DISABLED    0x04 ///< The local oscillator inside the dc-dc converter is
                                       ///< disabled.                                         
                                                                                              
#define DC0CF_VSEL__FMASK         0x78 ///< DC-DC Converter Output Voltage Select             
#define DC0CF_VSEL__SHIFT         0x03 ///< DC-DC Converter Output Voltage Select             
#define DC0CF_VSEL__1P8           0x00 ///< Target output voltage is 1.8 V.                   
#define DC0CF_VSEL__1P9           0x08 ///< Target output voltage is 1.9 V.                   
#define DC0CF_VSEL__2P0           0x10 ///< Target output voltage is 2.0 V.                   
#define DC0CF_VSEL__2P1           0x18 ///< Target output voltage is 2.1 V.                   
#define DC0CF_VSEL__2P2           0x20 ///< Target output voltage is 2.2 V.                   
#define DC0CF_VSEL__2P3           0x28 ///< Target output voltage is 2.3 V.                   
#define DC0CF_VSEL__2P4           0x30 ///< Target output voltage is 2.4 V.                   
#define DC0CF_VSEL__2P5           0x38 ///< Target output voltage is 2.5 V.                   
#define DC0CF_VSEL__2P6           0x40 ///< Target output voltage is 2.6 V.                   
#define DC0CF_VSEL__2P7           0x48 ///< Target output voltage is 2.7 V.                   
#define DC0CF_VSEL__2P8           0x50 ///< Target output voltage is 2.8 V.                   
#define DC0CF_VSEL__2P9           0x58 ///< Target output voltage is 2.9 V.                   
#define DC0CF_VSEL__3P0           0x60 ///< Target output voltage is 3.0 V.                   
#define DC0CF_VSEL__3P1           0x68 ///< Target output voltage is 3.1 V.                   
#define DC0CF_VSEL__3P3           0x70 ///< Target output voltage is 3.3 V.                   
#define DC0CF_VSEL__3P5           0x78 ///< Target output voltage is 3.5 V.                   
                                                                                              
#define DC0CF_BYPASS__BMASK       0x80 ///< DC-DC Converter Bypass Switch Enable              
#define DC0CF_BYPASS__SHIFT       0x07 ///< DC-DC Converter Bypass Switch Enable              
#define DC0CF_BYPASS__NORMAL      0x00 ///< The bypass switch is open.                        
#define DC0CF_BYPASS__BYPASS      0x80 ///< The bypass switch is closed (VDC is connected to  
                                       ///< VBATDC).                                          
                                                                                              
//------------------------------------------------------------------------------
// DC0CN Enums (DC-DC Converter Control @ 0xB1)
//------------------------------------------------------------------------------
#define DC0CN_MINPW__FMASK           0x03 ///< DC-DC Converter Minimum Pulse Width              
#define DC0CN_MINPW__SHIFT           0x00 ///< DC-DC Converter Minimum Pulse Width              
#define DC0CN_MINPW__DISABLED        0x00 ///< Minimum pulse detection logic is disabled (no    
                                          ///< pulse skipping).                                 
#define DC0CN_MINPW__10_NS           0x01 ///< Minimum pulse width is 10 ns.                    
#define DC0CN_MINPW__20_NS           0x02 ///< Minimum pulse width is 20 ns.                    
#define DC0CN_MINPW__40_NS           0x03 ///< Minimum pulse width is 40 ns.                    
                                                                                                
#define DC0CN_SYNC__BMASK            0x04 ///< ADC0 Synchronization Enable                      
#define DC0CN_SYNC__SHIFT            0x02 ///< ADC0 Synchronization Enable                      
#define DC0CN_SYNC__DISABLED         0x00 ///< The ADC is not synchronized to the dc-dc         
                                          ///< converter.                                       
#define DC0CN_SYNC__ENABLED          0x04 ///< The ADC is synchronized to the dc-dc converter.  
                                                                                                
#define DC0CN_CLKINV__BMASK          0x08 ///< DC-DC Converter Clock Invert                     
#define DC0CN_CLKINV__SHIFT          0x03 ///< DC-DC Converter Clock Invert                     
#define DC0CN_CLKINV__INVERTED       0x00 ///< The dc-dc converter clock is not inverted.       
#define DC0CN_CLKINV__NOT_INVERTED   0x08 ///< The dc-dc converter clock is inverted.           
                                                                                                
#define DC0CN_AD0CKINV__BMASK        0x10 ///< ADC0 Clock Inversion                             
#define DC0CN_AD0CKINV__SHIFT        0x04 ///< ADC0 Clock Inversion                             
#define DC0CN_AD0CKINV__INVERTED     0x00 ///< ADC0 SAR clock is inverted.                      
#define DC0CN_AD0CKINV__NOT_INVERTED 0x10 ///< ADC0 SAR clock is not inverted.                  
                                                                                                
#define DC0CN_CLKDIV__FMASK          0x60 ///< DC-DC Clock Divider                              
#define DC0CN_CLKDIV__SHIFT          0x05 ///< DC-DC Clock Divider                              
#define DC0CN_CLKDIV__SYSCLK_DIV_1   0x00 ///< The dc-dc converter clock is system clock divided
                                          ///< by 1.                                            
#define DC0CN_CLKDIV__SYSCLK_DIV_2   0x20 ///< The dc-dc converter clock is system clock divided
                                          ///< by 2.                                            
#define DC0CN_CLKDIV__SYSCLK_DIV_4   0x40 ///< The dc-dc converter clock is system clock divided
                                          ///< by 4.                                            
#define DC0CN_CLKDIV__SYSCLK_DIV_8   0x60 ///< The dc-dc converter clock is system clock divided
                                          ///< by 8.                                            
                                                                                                
#define DC0CN_CLKSEL__BMASK          0x80 ///< DC-DC Converter Clock Source Select              
#define DC0CN_CLKSEL__SHIFT          0x07 ///< DC-DC Converter Clock Source Select              
#define DC0CN_CLKSEL__LOCAL          0x00 ///< The dc-dc converter is clocked from its local    
                                          ///< oscillator.                                      
#define DC0CN_CLKSEL__SYSCLK         0x80 ///< The dc-dc converter is clocked from the system   
                                          ///< clock.                                           
                                                                                                
//------------------------------------------------------------------------------
// DC0MD Enums (DC-DC Converter Mode @ 0xB3)
//------------------------------------------------------------------------------
#define DC0MD_DC0EN__BMASK      0x01 ///< DC-DC Converter Enable                    
#define DC0MD_DC0EN__SHIFT      0x00 ///< DC-DC Converter Enable                    
#define DC0MD_DC0EN__DISABLED   0x00 ///< Disable the DC-DC converter.              
#define DC0MD_DC0EN__ENABLED    0x01 ///< Enable the DC-DC converter.               
                                                                                    
#define DC0MD_AUTOBYP__BMASK    0x04 ///< Automatic Bypass Mode Enable              
#define DC0MD_AUTOBYP__SHIFT    0x02 ///< Automatic Bypass Mode Enable              
#define DC0MD_AUTOBYP__DISABLED 0x00 ///< Disable automatic bypass mode.            
#define DC0MD_AUTOBYP__ENABLED  0x04 ///< Enable automatic bypass mode.             
                                                                                    
#define DC0MD_FORBYP__BMASK     0x08 ///< Forced Bypass Mode Enable                 
#define DC0MD_FORBYP__SHIFT     0x03 ///< Forced Bypass Mode Enable                 
#define DC0MD_FORBYP__DISABLED  0x00 ///< Disable forced bypass mode.               
#define DC0MD_FORBYP__ENABLED   0x08 ///< Enable forced bypass mode.                
                                                                                    
#define DC0MD_ILIMIT__FMASK     0x70 ///< Peak Current Limit Threshold              
#define DC0MD_ILIMIT__SHIFT     0x04 ///< Peak Current Limit Threshold              
#define DC0MD_ILIMIT__200_MA    0x10 ///< Peak Inductor current is limited to 200 mA
#define DC0MD_ILIMIT__300_MA    0x20 ///< Peak Inductor current is limited to 300 mA
#define DC0MD_ILIMIT__400_MA    0x30 ///< Peak Inductor current is limited to 400 mA
#define DC0MD_ILIMIT__500_MA    0x40 ///< Peak Inductor current is limited to 500 mA
#define DC0MD_ILIMIT__600_MA    0x50 ///< Peak Inductor current is limited to 600 mA
                                                                                    
//------------------------------------------------------------------------------
// DC0RDY Enums (DC-DC Converter Ready @ 0xFD)
//------------------------------------------------------------------------------
#define DC0RDY_RDYL__BMASK   0x40 ///< DC0 Ready Indicator (Low Threshold)          
#define DC0RDY_RDYL__SHIFT   0x06 ///< DC0 Ready Indicator (Low Threshold)          
#define DC0RDY_RDYL__NOT_SET 0x00 ///< VDC pin voltage is less than the DCDC0 Low   
                                  ///< Threshold.                                   
#define DC0RDY_RDYL__SET     0x40 ///< VDC pin voltage is higher than the DCDC0 Low 
                                  ///< Threshold.                                   
                                                                                    
#define DC0RDY_RDYH__BMASK   0x80 ///< DC0 Ready Indicator (High Threshold)         
#define DC0RDY_RDYH__SHIFT   0x07 ///< DC0 Ready Indicator (High Threshold)         
#define DC0RDY_RDYH__NOT_SET 0x00 ///< VDC pin voltage is less than the DCDC0 High  
                                  ///< Threshold.                                   
#define DC0RDY_RDYH__SET     0x80 ///< VDC pin voltage is higher than the DCDC0 High
                                  ///< Threshold.                                   
                                                                                    
//------------------------------------------------------------------------------
// DERIVID Enums (Device Identification @ 0xE9)
//------------------------------------------------------------------------------
#define DERIVID_DERIVID__FMASK           0xFF ///< Derivative ID  
#define DERIVID_DERIVID__SHIFT           0x00 ///< Derivative ID  
#define DERIVID_DERIVID__C8051F960_GM_GU 0xD0 ///< C8051F960-GM/GU
#define DERIVID_DERIVID__C8051F961_GM    0xD1 ///< C8051F961-GM   
#define DERIVID_DERIVID__C8051F962_GM_GU 0xD2 ///< C8051F962-GM/GU
#define DERIVID_DERIVID__C8051F963_GM    0xD3 ///< C8051F963-GM   
#define DERIVID_DERIVID__C8051F964_GM_GU 0xD4 ///< C8051F964-GM/GU
#define DERIVID_DERIVID__C8051F965_GM    0xD5 ///< C8051F965-GM   
#define DERIVID_DERIVID__C8051F966_GM_GU 0xD6 ///< C8051F966-GM/GU
#define DERIVID_DERIVID__C8051F967_GM    0xD7 ///< C8051F967-GM   
#define DERIVID_DERIVID__C8051F968_GM_GU 0xD8 ///< C8051F968-GM/GU
#define DERIVID_DERIVID__C8051F969_GM    0xD9 ///< C8051F969-GM   
                                                                  
//------------------------------------------------------------------------------
// REVID Enums (Revision Identifcation @ 0xEA)
//------------------------------------------------------------------------------
#define REVID_REVID__FMASK 0xFF ///< Revision ID
#define REVID_REVID__SHIFT 0x00 ///< Revision ID
#define REVID_REVID__REV_A 0x00 ///< Revision A 
                                                
//------------------------------------------------------------------------------
// DMA0BUSY Enums (DMA0 Busy @ 0xD5)
//------------------------------------------------------------------------------
#define DMA0BUSY_CH0BUSY__BMASK   0x01 ///< Channel 0 Busy                                    
#define DMA0BUSY_CH0BUSY__SHIFT   0x00 ///< Channel 0 Busy                                    
#define DMA0BUSY_CH0BUSY__NOT_SET 0x00 ///< DMA0 transfer is complete or no DMA0 transfer is  
                                       ///< currently in progress on channel 0.               
#define DMA0BUSY_CH0BUSY__SET     0x01 ///< DMA0 transfer is in progress on channel 0 or force
                                       ///< a DMA0 transfer to start on channel 0.            
                                                                                              
#define DMA0BUSY_CH1BUSY__BMASK   0x02 ///< Channel 1 Busy                                    
#define DMA0BUSY_CH1BUSY__SHIFT   0x01 ///< Channel 1 Busy                                    
#define DMA0BUSY_CH1BUSY__NOT_SET 0x00 ///< DMA0 transfer is complete or no DMA0 transfer is  
                                       ///< currently in progress on channel 1.               
#define DMA0BUSY_CH1BUSY__SET     0x02 ///< DMA0 transfer is in progress on channel 1 or force
                                       ///< a DMA0 transfer to start on channel 1.            
                                                                                              
#define DMA0BUSY_CH2BUSY__BMASK   0x04 ///< Channel 2 Busy                                    
#define DMA0BUSY_CH2BUSY__SHIFT   0x02 ///< Channel 2 Busy                                    
#define DMA0BUSY_CH2BUSY__NOT_SET 0x00 ///< DMA0 transfer is complete or no DMA0 transfer is  
                                       ///< currently in progress on channel 2.               
#define DMA0BUSY_CH2BUSY__SET     0x04 ///< DMA0 transfer is in progress on channel 2 or force
                                       ///< a DMA0 transfer to start on channel 2.            
                                                                                              
#define DMA0BUSY_CH3BUSY__BMASK   0x08 ///< Channel 3 Busy                                    
#define DMA0BUSY_CH3BUSY__SHIFT   0x03 ///< Channel 3 Busy                                    
#define DMA0BUSY_CH3BUSY__NOT_SET 0x00 ///< DMA0 transfer is complete or no DMA0 transfer is  
                                       ///< currently in progress on channel 3.               
#define DMA0BUSY_CH3BUSY__SET     0x08 ///< DMA0 transfer is in progress on channel 3 or force
                                       ///< a DMA0 transfer to start on channel 3.            
                                                                                              
#define DMA0BUSY_CH4BUSY__BMASK   0x10 ///< Channel 4 Busy                                    
#define DMA0BUSY_CH4BUSY__SHIFT   0x04 ///< Channel 4 Busy                                    
#define DMA0BUSY_CH4BUSY__NOT_SET 0x00 ///< DMA0 transfer is complete or no DMA0 transfer is  
                                       ///< currently in progress on channel 4.               
#define DMA0BUSY_CH4BUSY__SET     0x10 ///< DMA0 transfer is in progress on channel 6 or force
                                       ///< a DMA0 transfer to start on channel 4.            
                                                                                              
#define DMA0BUSY_CH5BUSY__BMASK   0x20 ///< Channel 5 Busy                                    
#define DMA0BUSY_CH5BUSY__SHIFT   0x05 ///< Channel 5 Busy                                    
#define DMA0BUSY_CH5BUSY__NOT_SET 0x00 ///< DMA0 transfer is complete or no DMA0 transfer is  
                                       ///< currently in progress on channel 5.               
#define DMA0BUSY_CH5BUSY__SET     0x20 ///< DMA0 transfer is in progress on channel 5 or force
                                       ///< a DMA0 transfer to start on channel 5.            
                                                                                              
#define DMA0BUSY_CH6BUSY__BMASK   0x40 ///< Channel 6 Busy                                    
#define DMA0BUSY_CH6BUSY__SHIFT   0x06 ///< Channel 6 Busy                                    
#define DMA0BUSY_CH6BUSY__NOT_SET 0x00 ///< DMA0 transfer is complete or no DMA0 transfer is  
                                       ///< currently in progress on channel 6.               
#define DMA0BUSY_CH6BUSY__SET     0x40 ///< DMA0 transfer is in progress on channel 6 or force
                                       ///< a DMA0 transfer to start on channel 6.            
                                                                                              
//------------------------------------------------------------------------------
// DMA0EN Enums (DMA0 Channel Enable @ 0xD2)
//------------------------------------------------------------------------------
#define DMA0EN_CH0EN__BMASK    0x01 ///< Channel 0 Enable       
#define DMA0EN_CH0EN__SHIFT    0x00 ///< Channel 0 Enable       
#define DMA0EN_CH0EN__DISABLED 0x00 ///< Disable DMA0 channel 0.
#define DMA0EN_CH0EN__ENABLED  0x01 ///< Enable DMA0 channel 0. 
                                                                
#define DMA0EN_CH1EN__BMASK    0x02 ///< Channel 1 Enable       
#define DMA0EN_CH1EN__SHIFT    0x01 ///< Channel 1 Enable       
#define DMA0EN_CH1EN__DISABLED 0x00 ///< Disable DMA0 channel 1.
#define DMA0EN_CH1EN__ENABLED  0x02 ///< Enable DMA0 channel 1. 
                                                                
#define DMA0EN_CH2EN__BMASK    0x04 ///< Channel 2 Enable       
#define DMA0EN_CH2EN__SHIFT    0x02 ///< Channel 2 Enable       
#define DMA0EN_CH2EN__DISABLED 0x00 ///< Disable DMA0 channel 2.
#define DMA0EN_CH2EN__ENABLED  0x04 ///< Enable DMA0 channel 2. 
                                                                
#define DMA0EN_CH3EN__BMASK    0x08 ///< Channel 3 Enable       
#define DMA0EN_CH3EN__SHIFT    0x03 ///< Channel 3 Enable       
#define DMA0EN_CH3EN__DISABLED 0x00 ///< Disable DMA0 channel 3.
#define DMA0EN_CH3EN__ENABLED  0x08 ///< Enable DMA0 channel 3. 
                                                                
#define DMA0EN_CH4EN__BMASK    0x10 ///< Channel 4 Enable       
#define DMA0EN_CH4EN__SHIFT    0x04 ///< Channel 4 Enable       
#define DMA0EN_CH4EN__DISABLED 0x00 ///< Disable DMA0 channel 4.
#define DMA0EN_CH4EN__ENABLED  0x10 ///< Enable DMA0 channel 4. 
                                                                
#define DMA0EN_CH5EN__BMASK    0x20 ///< Channel 5 Enable       
#define DMA0EN_CH5EN__SHIFT    0x05 ///< Channel 5 Enable       
#define DMA0EN_CH5EN__DISABLED 0x00 ///< Disable DMA0 channel 5.
#define DMA0EN_CH5EN__ENABLED  0x20 ///< Enable DMA0 channel 5. 
                                                                
#define DMA0EN_CH6EN__BMASK    0x40 ///< Channel 6 Enable       
#define DMA0EN_CH6EN__SHIFT    0x06 ///< Channel 6 Enable       
#define DMA0EN_CH6EN__DISABLED 0x00 ///< Disable DMA0 channel 6.
#define DMA0EN_CH6EN__ENABLED  0x40 ///< Enable DMA0 channel 6. 
                                                                
//------------------------------------------------------------------------------
// DMA0INT Enums (DMA0 Full-Length Interrupt Flags @ 0xD3)
//------------------------------------------------------------------------------
#define DMA0INT_CH0I__BMASK   0x01 ///< Channel 0 Full-Length Interrupt Flag         
#define DMA0INT_CH0I__SHIFT   0x00 ///< Channel 0 Full-Length Interrupt Flag         
#define DMA0INT_CH0I__NOT_SET 0x00 ///< No Interrupt generated.                      
#define DMA0INT_CH0I__SET     0x01 ///< Full-length interrupt generated in channel 0.
                                                                                     
#define DMA0INT_CH1I__BMASK   0x02 ///< Channel 1 Full-Length Interrupt Flag         
#define DMA0INT_CH1I__SHIFT   0x01 ///< Channel 1 Full-Length Interrupt Flag         
#define DMA0INT_CH1I__NOT_SET 0x00 ///< No Interrupt generated.                      
#define DMA0INT_CH1I__SET     0x02 ///< Full-length interrupt generated in channel 1.
                                                                                     
#define DMA0INT_CH2I__BMASK   0x04 ///< Channel 2 Full-Length Interrupt Flag         
#define DMA0INT_CH2I__SHIFT   0x02 ///< Channel 2 Full-Length Interrupt Flag         
#define DMA0INT_CH2I__NOT_SET 0x00 ///< No Interrupt generated.                      
#define DMA0INT_CH2I__SET     0x04 ///< Full-length interrupt generated in channel 2.
                                                                                     
#define DMA0INT_CH3I__BMASK   0x08 ///< Channel 3 Full-Length Interrupt Flag         
#define DMA0INT_CH3I__SHIFT   0x03 ///< Channel 3 Full-Length Interrupt Flag         
#define DMA0INT_CH3I__NOT_SET 0x00 ///< No Interrupt generated.                      
#define DMA0INT_CH3I__SET     0x08 ///< Full-length interrupt generated in channel 3.
                                                                                     
#define DMA0INT_CH4I__BMASK   0x10 ///< Channel 4 Full-Length Interrupt Flag         
#define DMA0INT_CH4I__SHIFT   0x04 ///< Channel 4 Full-Length Interrupt Flag         
#define DMA0INT_CH4I__NOT_SET 0x00 ///< No Interrupt generated.                      
#define DMA0INT_CH4I__SET     0x10 ///< Full-length interrupt generated in channel 4.
                                                                                     
#define DMA0INT_CH5I__BMASK   0x20 ///< Channel 5 Full-Length Interrupt Flag         
#define DMA0INT_CH5I__SHIFT   0x05 ///< Channel 5 Full-Length Interrupt Flag         
#define DMA0INT_CH5I__NOT_SET 0x00 ///< No Interrupt generated.                      
#define DMA0INT_CH5I__SET     0x20 ///< Full-length interrupt generated in channel 5.
                                                                                     
#define DMA0INT_CH6I__BMASK   0x40 ///< Channel 6 Full-Length Interrupt Flag         
#define DMA0INT_CH6I__SHIFT   0x06 ///< Channel 6 Full-Length Interrupt Flag         
#define DMA0INT_CH6I__NOT_SET 0x00 ///< No Interrupt generated.                      
#define DMA0INT_CH6I__SET     0x40 ///< Full-length interrupt generated in channel 6.
                                                                                     
//------------------------------------------------------------------------------
// DMA0MINT Enums (DMA0 Mid-Point Interrupt Flags @ 0xD4)
//------------------------------------------------------------------------------
#define DMA0MINT_CH0MI__BMASK   0x01 ///< Channel 0 Mid-Point Interrupt Flag         
#define DMA0MINT_CH0MI__SHIFT   0x00 ///< Channel 0 Mid-Point Interrupt Flag         
#define DMA0MINT_CH0MI__NOT_SET 0x00 ///< No mid-point Interrupt generated.          
#define DMA0MINT_CH0MI__SET     0x01 ///< Mid-point Interrupt generated in channel 0.
                                                                                     
#define DMA0MINT_CH1MI__BMASK   0x02 ///< Channel 1 Mid-Point Interrupt Flag         
#define DMA0MINT_CH1MI__SHIFT   0x01 ///< Channel 1 Mid-Point Interrupt Flag         
#define DMA0MINT_CH1MI__NOT_SET 0x00 ///< No mid-point Interrupt generated.          
#define DMA0MINT_CH1MI__SET     0x02 ///< Mid-point Interrupt generated in channel 1.
                                                                                     
#define DMA0MINT_CH2MI__BMASK   0x04 ///< Channel 2 Mid-Point Interrupt Flag         
#define DMA0MINT_CH2MI__SHIFT   0x02 ///< Channel 2 Mid-Point Interrupt Flag         
#define DMA0MINT_CH2MI__NOT_SET 0x00 ///< No mid-point Interrupt generated.          
#define DMA0MINT_CH2MI__SET     0x04 ///< Mid-point Interrupt generated in channel 2.
                                                                                     
#define DMA0MINT_CH3MI__BMASK   0x08 ///< Channel 3 Mid-Point Interrupt Flag         
#define DMA0MINT_CH3MI__SHIFT   0x03 ///< Channel 3 Mid-Point Interrupt Flag         
#define DMA0MINT_CH3MI__NOT_SET 0x00 ///< No mid-point Interrupt generated.          
#define DMA0MINT_CH3MI__SET     0x08 ///< Mid-point Interrupt generated in channel 3.
                                                                                     
#define DMA0MINT_CH4MI__BMASK   0x10 ///< Channel 4 Mid-Point Interrupt Flag         
#define DMA0MINT_CH4MI__SHIFT   0x04 ///< Channel 4 Mid-Point Interrupt Flag         
#define DMA0MINT_CH4MI__NOT_SET 0x00 ///< No mid-point Interrupt generated.          
#define DMA0MINT_CH4MI__SET     0x10 ///< Mid-point Interrupt generated in channel 4.
                                                                                     
#define DMA0MINT_CH5MI__BMASK   0x20 ///< Channel 5 Mid-Point Interrupt Flag         
#define DMA0MINT_CH5MI__SHIFT   0x05 ///< Channel 5 Mid-Point Interrupt Flag         
#define DMA0MINT_CH5MI__NOT_SET 0x00 ///< No mid-point Interrupt generated.          
#define DMA0MINT_CH5MI__SET     0x20 ///< Mid-point Interrupt generated in channel 5.
                                                                                     
#define DMA0MINT_CH6MI__BMASK   0x40 ///< Channel 6 Mid-Point Interrupt Flag         
#define DMA0MINT_CH6MI__SHIFT   0x06 ///< Channel 6 Mid-Point Interrupt Flag         
#define DMA0MINT_CH6MI__NOT_SET 0x00 ///< No mid-point Interrupt generated.          
#define DMA0MINT_CH6MI__SET     0x40 ///< Mid-point Interrupt generated in channel 6.
                                                                                     
//------------------------------------------------------------------------------
// DMA0NAOH Enums (Memory Address Offset High @ 0xCD)
//------------------------------------------------------------------------------
#define DMA0NAOH_NAOH__FMASK 0x03 ///< Memory Address Offset High
#define DMA0NAOH_NAOH__SHIFT 0x00 ///< Memory Address Offset High
                                                                 
//------------------------------------------------------------------------------
// DMA0NAOH0 Enums (Channel 0 Memory Address Offset High @ 0x00)
//------------------------------------------------------------------------------
#define DMA0NAOH0_NAOH__FMASK 0x03 ///< Memory Address Offset High
#define DMA0NAOH0_NAOH__SHIFT 0x00 ///< Memory Address Offset High
                                                                  
//------------------------------------------------------------------------------
// DMA0NAOH1 Enums (Channel 1 Memory Address Offset High @ 0x01)
//------------------------------------------------------------------------------
#define DMA0NAOH1_NAOH__FMASK 0x03 ///< Memory Address Offset High
#define DMA0NAOH1_NAOH__SHIFT 0x00 ///< Memory Address Offset High
                                                                  
//------------------------------------------------------------------------------
// DMA0NAOH2 Enums (Channel 2 Memory Address Offset High @ 0x02)
//------------------------------------------------------------------------------
#define DMA0NAOH2_NAOH__FMASK 0x03 ///< Memory Address Offset High
#define DMA0NAOH2_NAOH__SHIFT 0x00 ///< Memory Address Offset High
                                                                  
//------------------------------------------------------------------------------
// DMA0NAOH3 Enums (Channel 3 Memory Address Offset High @ 0x03)
//------------------------------------------------------------------------------
#define DMA0NAOH3_NAOH__FMASK 0x03 ///< Memory Address Offset High
#define DMA0NAOH3_NAOH__SHIFT 0x00 ///< Memory Address Offset High
                                                                  
//------------------------------------------------------------------------------
// DMA0NAOH4 Enums (Channel 4 Memory Address Offset High @ 0x04)
//------------------------------------------------------------------------------
#define DMA0NAOH4_NAOH__FMASK 0x03 ///< Memory Address Offset High
#define DMA0NAOH4_NAOH__SHIFT 0x00 ///< Memory Address Offset High
                                                                  
//------------------------------------------------------------------------------
// DMA0NAOH5 Enums (Channel 5 Memory Address Offset High @ 0x05)
//------------------------------------------------------------------------------
#define DMA0NAOH5_NAOH__FMASK 0x03 ///< Memory Address Offset High
#define DMA0NAOH5_NAOH__SHIFT 0x00 ///< Memory Address Offset High
                                                                  
//------------------------------------------------------------------------------
// DMA0NAOH6 Enums (Channel 6 Memory Address Offset High @ 0x06)
//------------------------------------------------------------------------------
#define DMA0NAOH6_NAOH__FMASK 0x03 ///< Memory Address Offset High
#define DMA0NAOH6_NAOH__SHIFT 0x00 ///< Memory Address Offset High
                                                                  
//------------------------------------------------------------------------------
// DMA0NAOL Enums (Memory Address Offset Low @ 0xCC)
//------------------------------------------------------------------------------
#define DMA0NAOL_NAOL__FMASK 0xFF ///< Memory Address Offset Low
#define DMA0NAOL_NAOL__SHIFT 0x00 ///< Memory Address Offset Low
                                                                
//------------------------------------------------------------------------------
// DMA0NAOL0 Enums (Channel 0 Memory Address Offset Low @ 0x00)
//------------------------------------------------------------------------------
#define DMA0NAOL0_NAOL__FMASK 0xFF ///< Memory Address Offset Low
#define DMA0NAOL0_NAOL__SHIFT 0x00 ///< Memory Address Offset Low
                                                                 
//------------------------------------------------------------------------------
// DMA0NAOL1 Enums (Channel 1 Memory Address Offset Low @ 0x01)
//------------------------------------------------------------------------------
#define DMA0NAOL1_NAOL__FMASK 0xFF ///< Memory Address Offset Low
#define DMA0NAOL1_NAOL__SHIFT 0x00 ///< Memory Address Offset Low
                                                                 
//------------------------------------------------------------------------------
// DMA0NAOL2 Enums (Channel 2 Memory Address Offset Low @ 0x02)
//------------------------------------------------------------------------------
#define DMA0NAOL2_NAOL__FMASK 0xFF ///< Memory Address Offset Low
#define DMA0NAOL2_NAOL__SHIFT 0x00 ///< Memory Address Offset Low
                                                                 
//------------------------------------------------------------------------------
// DMA0NAOL3 Enums (Channel 3 Memory Address Offset Low @ 0x03)
//------------------------------------------------------------------------------
#define DMA0NAOL3_NAOL__FMASK 0xFF ///< Memory Address Offset Low
#define DMA0NAOL3_NAOL__SHIFT 0x00 ///< Memory Address Offset Low
                                                                 
//------------------------------------------------------------------------------
// DMA0NAOL4 Enums (Channel 4 Memory Address Offset Low @ 0x04)
//------------------------------------------------------------------------------
#define DMA0NAOL4_NAOL__FMASK 0xFF ///< Memory Address Offset Low
#define DMA0NAOL4_NAOL__SHIFT 0x00 ///< Memory Address Offset Low
                                                                 
//------------------------------------------------------------------------------
// DMA0NAOL5 Enums (Channel 5 Memory Address Offset Low @ 0x05)
//------------------------------------------------------------------------------
#define DMA0NAOL5_NAOL__FMASK 0xFF ///< Memory Address Offset Low
#define DMA0NAOL5_NAOL__SHIFT 0x00 ///< Memory Address Offset Low
                                                                 
//------------------------------------------------------------------------------
// DMA0NAOL6 Enums (Channel 6 Memory Address Offset Low @ 0x06)
//------------------------------------------------------------------------------
#define DMA0NAOL6_NAOL__FMASK 0xFF ///< Memory Address Offset Low
#define DMA0NAOL6_NAOL__SHIFT 0x00 ///< Memory Address Offset Low
                                                                 
//------------------------------------------------------------------------------
// DMA0NBAH Enums (Memory Base Address High @ 0xCB)
//------------------------------------------------------------------------------
#define DMA0NBAH_NBAH__FMASK 0x0F ///< Memory Base Address High
#define DMA0NBAH_NBAH__SHIFT 0x00 ///< Memory Base Address High
                                                               
//------------------------------------------------------------------------------
// DMA0NBAH0 Enums (Channel 0 Memory Base Address High @ 0x00)
//------------------------------------------------------------------------------
#define DMA0NBAH0_NBAH__FMASK 0x0F ///< Memory Base Address High
#define DMA0NBAH0_NBAH__SHIFT 0x00 ///< Memory Base Address High
                                                                
//------------------------------------------------------------------------------
// DMA0NBAH1 Enums (Channel 1 Memory Base Address High @ 0x01)
//------------------------------------------------------------------------------
#define DMA0NBAH1_NBAH__FMASK 0x0F ///< Memory Base Address High
#define DMA0NBAH1_NBAH__SHIFT 0x00 ///< Memory Base Address High
                                                                
//------------------------------------------------------------------------------
// DMA0NBAH2 Enums (Channel 2 Memory Base Address High @ 0x02)
//------------------------------------------------------------------------------
#define DMA0NBAH2_NBAH__FMASK 0x0F ///< Memory Base Address High
#define DMA0NBAH2_NBAH__SHIFT 0x00 ///< Memory Base Address High
                                                                
//------------------------------------------------------------------------------
// DMA0NBAH3 Enums (Channel 3 Memory Base Address High @ 0x03)
//------------------------------------------------------------------------------
#define DMA0NBAH3_NBAH__FMASK 0x0F ///< Memory Base Address High
#define DMA0NBAH3_NBAH__SHIFT 0x00 ///< Memory Base Address High
                                                                
//------------------------------------------------------------------------------
// DMA0NBAH4 Enums (Channel 4 Memory Base Address High @ 0x04)
//------------------------------------------------------------------------------
#define DMA0NBAH4_NBAH__FMASK 0x0F ///< Memory Base Address High
#define DMA0NBAH4_NBAH__SHIFT 0x00 ///< Memory Base Address High
                                                                
//------------------------------------------------------------------------------
// DMA0NBAH5 Enums (Channel 5 Memory Base Address High @ 0x05)
//------------------------------------------------------------------------------
#define DMA0NBAH5_NBAH__FMASK 0x0F ///< Memory Base Address High
#define DMA0NBAH5_NBAH__SHIFT 0x00 ///< Memory Base Address High
                                                                
//------------------------------------------------------------------------------
// DMA0NBAH6 Enums (Channel 6 Memory Base Address High @ 0x06)
//------------------------------------------------------------------------------
#define DMA0NBAH6_NBAH__FMASK 0x0F ///< Memory Base Address High
#define DMA0NBAH6_NBAH__SHIFT 0x00 ///< Memory Base Address High
                                                                
//------------------------------------------------------------------------------
// DMA0NBAL Enums (Memory Base Address Low @ 0xCA)
//------------------------------------------------------------------------------
#define DMA0NBAL_NBAL__FMASK 0xFF ///< Memory Base Address Low
#define DMA0NBAL_NBAL__SHIFT 0x00 ///< Memory Base Address Low
                                                              
//------------------------------------------------------------------------------
// DMA0NBAL0 Enums (Channel 0 Memory Base Address Low @ 0x00)
//------------------------------------------------------------------------------
#define DMA0NBAL0_NBAL__FMASK 0xFF ///< Memory Base Address Low
#define DMA0NBAL0_NBAL__SHIFT 0x00 ///< Memory Base Address Low
                                                               
//------------------------------------------------------------------------------
// DMA0NBAL1 Enums (Channel 1 Memory Base Address Low @ 0x01)
//------------------------------------------------------------------------------
#define DMA0NBAL1_NBAL__FMASK 0xFF ///< Memory Base Address Low
#define DMA0NBAL1_NBAL__SHIFT 0x00 ///< Memory Base Address Low
                                                               
//------------------------------------------------------------------------------
// DMA0NBAL2 Enums (Channel 2 Memory Base Address Low @ 0x02)
//------------------------------------------------------------------------------
#define DMA0NBAL2_NBAL__FMASK 0xFF ///< Memory Base Address Low
#define DMA0NBAL2_NBAL__SHIFT 0x00 ///< Memory Base Address Low
                                                               
//------------------------------------------------------------------------------
// DMA0NBAL3 Enums (Channel 3 Memory Base Address Low @ 0x03)
//------------------------------------------------------------------------------
#define DMA0NBAL3_NBAL__FMASK 0xFF ///< Memory Base Address Low
#define DMA0NBAL3_NBAL__SHIFT 0x00 ///< Memory Base Address Low
                                                               
//------------------------------------------------------------------------------
// DMA0NBAL4 Enums (Channel 4 Memory Base Address Low @ 0x04)
//------------------------------------------------------------------------------
#define DMA0NBAL4_NBAL__FMASK 0xFF ///< Memory Base Address Low
#define DMA0NBAL4_NBAL__SHIFT 0x00 ///< Memory Base Address Low
                                                               
//------------------------------------------------------------------------------
// DMA0NBAL5 Enums (Channel 5 Memory Base Address Low @ 0x05)
//------------------------------------------------------------------------------
#define DMA0NBAL5_NBAL__FMASK 0xFF ///< Memory Base Address Low
#define DMA0NBAL5_NBAL__SHIFT 0x00 ///< Memory Base Address Low
                                                               
//------------------------------------------------------------------------------
// DMA0NBAL6 Enums (Channel 6 Memory Base Address Low @ 0x06)
//------------------------------------------------------------------------------
#define DMA0NBAL6_NBAL__FMASK 0xFF ///< Memory Base Address Low
#define DMA0NBAL6_NBAL__SHIFT 0x00 ///< Memory Base Address Low
                                                               
//------------------------------------------------------------------------------
// DMA0NCF Enums (DMA0 Channel Configuration @ 0xC9)
//------------------------------------------------------------------------------
#define DMA0NCF_PERIPH__FMASK            0x0F ///< Peripheral Transfer Select                        
#define DMA0NCF_PERIPH__SHIFT            0x00 ///< Peripheral Transfer Select                        
#define DMA0NCF_PERIPH__XRAM_TO_ENCDEC0  0x00 ///< The DMA channel transfers from XRAM to the        
                                              ///< ENC0H:M:L registers.                              
#define DMA0NCF_PERIPH__ENCDEC0_TO_XRAM  0x01 ///< The DMA channel transfers from the ENC0H:M:L      
                                              ///< registers to XRAM.                                
#define DMA0NCF_PERIPH__XRAM_TO_CRC1     0x02 ///< The DMA channel transfers from XRAM to the CRC1IN 
                                              ///< register.                                         
#define DMA0NCF_PERIPH__XRAM_TO_SPI1     0x03 ///< The DMA channel transfers from XRAM to the SPI1DAT
                                              ///< register.                                         
#define DMA0NCF_PERIPH__SPI1_TO_XRAM     0x04 ///< The DMA channel transfers from the SPI1DAT        
                                              ///< register to XRAM.                                 
#define DMA0NCF_PERIPH__XRAM_TO_AES0_KEY 0x05 ///< The DMA channel transfers from XRAM to the AES0   
                                              ///< key input (AES0KIN) register.                     
#define DMA0NCF_PERIPH__XRAM_TO_AES0_B   0x06 ///< The DMA channel transfers from XRAM to the AES0 B 
                                              ///< input (AES0BIN) register.                         
#define DMA0NCF_PERIPH__XRAM_TO_AES0_XOR 0x07 ///< The DMA channel transfers from XRAM to the AES0   
                                              ///< XOR input (AES0XIN) register.                     
#define DMA0NCF_PERIPH__AES0_Y_TO_XRAM   0x08 ///< The DMA channel transfers from the AES0 Y output  
                                              ///< (AES0YOUT) register to XRAM.                      
                                                                                                     
#define DMA0NCF_ENDIAN__BMASK            0x10 ///< Data Transfer Endianness                          
#define DMA0NCF_ENDIAN__SHIFT            0x04 ///< Data Transfer Endianness                          
#define DMA0NCF_ENDIAN__LITTLE           0x00 ///< Data is written to and read from XRAM in little   
                                              ///< endian order.                                     
#define DMA0NCF_ENDIAN__BIG              0x10 ///< Data is written to and read from XRAM in big      
                                              ///< endian order.                                     
                                                                                                     
#define DMA0NCF_STALL__BMASK             0x20 ///< Channel Stall                                     
#define DMA0NCF_STALL__SHIFT             0x05 ///< Channel Stall                                     
#define DMA0NCF_STALL__NOT_SET           0x00 ///< The DMA transfer of the selected channel is not   
                                              ///< stalled.                                          
#define DMA0NCF_STALL__SET               0x20 ///< The DMA transfer of the selected channel is       
                                              ///< stalled.                                          
                                                                                                     
#define DMA0NCF_MIEN__BMASK              0x40 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF_MIEN__SHIFT              0x06 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF_MIEN__DISABLED           0x00 ///< Disable the DMA0 mid-point interrupt request of   
                                              ///< the selected channel.                             
#define DMA0NCF_MIEN__ENABLED            0x40 ///< Enable the DMA0 mid-point interrupt request of the
                                              ///< selected channel.                                 
                                                                                                     
#define DMA0NCF_IEN__BMASK               0x80 ///< Full-Length Interrupt Enable                      
#define DMA0NCF_IEN__SHIFT               0x07 ///< Full-Length Interrupt Enable                      
#define DMA0NCF_IEN__DISABLED            0x00 ///< Disable the DMA0 full-length interrupt request of 
                                              ///< the selected channel.                             
#define DMA0NCF_IEN__ENABLED             0x80 ///< Enable the DMA0 full-length interrupt request of  
                                              ///< the selected channel.                             
                                                                                                     
//------------------------------------------------------------------------------
// DMA0NCF0 Enums (DMA0 Channel 0 Configuration @ 0x00)
//------------------------------------------------------------------------------
#define DMA0NCF0_PERIPH__FMASK            0x07 ///< Peripheral Transfer Select                        
#define DMA0NCF0_PERIPH__SHIFT            0x00 ///< Peripheral Transfer Select                        
#define DMA0NCF0_PERIPH__XRAM_TO_MAC_A    0x02 ///< The DMA channel transfers from XRAM to the MAC A  
                                               ///< register.                                         
#define DMA0NCF0_PERIPH__XRAM_TO_MAC_B    0x03 ///< The DMA channel transfers from XRAM to the MAC B  
                                               ///< register.                                         
#define DMA0NCF0_PERIPH__XRAM_TO_MAC_ACC  0x04 ///< The DMA channel transfers from XRAM to the MAC    
                                               ///< accumulator registers.                            
#define DMA0NCF0_PERIPH__MAC_ACC_TO_XRAM  0x05 ///< The DMA channel transfers from the MAC accumulator
                                               ///< registers to XRAM.                                
#define DMA0NCF0_PERIPH__XRAM_TO_I2C_DATA 0x06 ///< The DMA channel transfers from XRAM to the I2C    
                                               ///< Slave data register.                              
#define DMA0NCF0_PERIPH__I2C_DATA_TO_XRAM 0x07 ///< The DMA channel transfers from the I2C Slave data 
                                               ///< register to XRAM.                                 
                                                                                                      
#define DMA0NCF0_ENDIAN__BMASK            0x10 ///< Data Transfer Endianness                          
#define DMA0NCF0_ENDIAN__SHIFT            0x04 ///< Data Transfer Endianness                          
#define DMA0NCF0_ENDIAN__LITTLE           0x00 ///< Data is written to and read from XRAM in little   
                                               ///< endian order.                                     
#define DMA0NCF0_ENDIAN__BIG              0x10 ///< Data is written to and read from XRAM in big      
                                               ///< endian order.                                     
                                                                                                      
#define DMA0NCF0_STALL__BMASK             0x20 ///< Channel Stall                                     
#define DMA0NCF0_STALL__SHIFT             0x05 ///< Channel Stall                                     
#define DMA0NCF0_STALL__NOT_SET           0x00 ///< The DMA transfer of the selected channel is not   
                                               ///< stalled.                                          
#define DMA0NCF0_STALL__SET               0x20 ///< The DMA transfer of the selected channel is       
                                               ///< stalled.                                          
                                                                                                      
#define DMA0NCF0_MIEN__BMASK              0x40 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF0_MIEN__SHIFT              0x06 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF0_MIEN__DISABLED           0x00 ///< Disable the DMA0 mid-point interrupt request of   
                                               ///< the selected channel.                             
#define DMA0NCF0_MIEN__ENABLED            0x40 ///< Enable the DMA0 mid-point interrupt request of the
                                               ///< selected channel.                                 
                                                                                                      
#define DMA0NCF0_IEN__BMASK               0x80 ///< Full-Length Interrupt Enable                      
#define DMA0NCF0_IEN__SHIFT               0x07 ///< Full-Length Interrupt Enable                      
#define DMA0NCF0_IEN__DISABLED            0x00 ///< Disable the DMA0 full-length interrupt request of 
                                               ///< the selected channel.                             
#define DMA0NCF0_IEN__ENABLED             0x80 ///< Enable the DMA0 full-length interrupt request of  
                                               ///< the selected channel.                             
                                                                                                      
//------------------------------------------------------------------------------
// DMA0NCF1 Enums (DMA0 Channel 1 Configuration @ 0x01)
//------------------------------------------------------------------------------
#define DMA0NCF1_PERIPH__FMASK            0x07 ///< Peripheral Transfer Select                        
#define DMA0NCF1_PERIPH__SHIFT            0x00 ///< Peripheral Transfer Select                        
#define DMA0NCF1_PERIPH__XRAM_TO_MAC_A    0x02 ///< The DMA channel transfers from XRAM to the MAC A  
                                               ///< register.                                         
#define DMA0NCF1_PERIPH__XRAM_TO_MAC_B    0x03 ///< The DMA channel transfers from XRAM to the MAC B  
                                               ///< register.                                         
#define DMA0NCF1_PERIPH__XRAM_TO_MAC_ACC  0x04 ///< The DMA channel transfers from XRAM to the MAC    
                                               ///< accumulator registers.                            
#define DMA0NCF1_PERIPH__MAC_ACC_TO_XRAM  0x05 ///< The DMA channel transfers from the MAC accumulator
                                               ///< registers to XRAM.                                
#define DMA0NCF1_PERIPH__XRAM_TO_I2C_DATA 0x06 ///< The DMA channel transfers from XRAM to the I2C    
                                               ///< Slave data register.                              
#define DMA0NCF1_PERIPH__I2C_DATA_TO_XRAM 0x07 ///< The DMA channel transfers from the I2C Slave data 
                                               ///< register to XRAM.                                 
                                                                                                      
#define DMA0NCF1_ENDIAN__BMASK            0x10 ///< Data Transfer Endianness                          
#define DMA0NCF1_ENDIAN__SHIFT            0x04 ///< Data Transfer Endianness                          
#define DMA0NCF1_ENDIAN__LITTLE           0x00 ///< Data is written to and read from XRAM in little   
                                               ///< endian order.                                     
#define DMA0NCF1_ENDIAN__BIG              0x10 ///< Data is written to and read from XRAM in big      
                                               ///< endian order.                                     
                                                                                                      
#define DMA0NCF1_STALL__BMASK             0x20 ///< Channel Stall                                     
#define DMA0NCF1_STALL__SHIFT             0x05 ///< Channel Stall                                     
#define DMA0NCF1_STALL__NOT_SET           0x00 ///< The DMA transfer of the selected channel is not   
                                               ///< stalled.                                          
#define DMA0NCF1_STALL__SET               0x20 ///< The DMA transfer of the selected channel is       
                                               ///< stalled.                                          
                                                                                                      
#define DMA0NCF1_MIEN__BMASK              0x40 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF1_MIEN__SHIFT              0x06 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF1_MIEN__DISABLED           0x00 ///< Disable the DMA0 mid-point interrupt request of   
                                               ///< the selected channel.                             
#define DMA0NCF1_MIEN__ENABLED            0x40 ///< Enable the DMA0 mid-point interrupt request of the
                                               ///< selected channel.                                 
                                                                                                      
#define DMA0NCF1_IEN__BMASK               0x80 ///< Full-Length Interrupt Enable                      
#define DMA0NCF1_IEN__SHIFT               0x07 ///< Full-Length Interrupt Enable                      
#define DMA0NCF1_IEN__DISABLED            0x00 ///< Disable the DMA0 full-length interrupt request of 
                                               ///< the selected channel.                             
#define DMA0NCF1_IEN__ENABLED             0x80 ///< Enable the DMA0 full-length interrupt request of  
                                               ///< the selected channel.                             
                                                                                                      
//------------------------------------------------------------------------------
// DMA0NCF2 Enums (DMA0 Channel 2 Configuration @ 0x02)
//------------------------------------------------------------------------------
#define DMA0NCF2_PERIPH__FMASK            0x07 ///< Peripheral Transfer Select                        
#define DMA0NCF2_PERIPH__SHIFT            0x00 ///< Peripheral Transfer Select                        
#define DMA0NCF2_PERIPH__XRAM_TO_MAC_A    0x02 ///< The DMA channel transfers from XRAM to the MAC A  
                                               ///< register.                                         
#define DMA0NCF2_PERIPH__XRAM_TO_MAC_B    0x03 ///< The DMA channel transfers from XRAM to the MAC B  
                                               ///< register.                                         
#define DMA0NCF2_PERIPH__XRAM_TO_MAC_ACC  0x04 ///< The DMA channel transfers from XRAM to the MAC    
                                               ///< accumulator registers.                            
#define DMA0NCF2_PERIPH__MAC_ACC_TO_XRAM  0x05 ///< The DMA channel transfers from the MAC accumulator
                                               ///< registers to XRAM.                                
#define DMA0NCF2_PERIPH__XRAM_TO_I2C_DATA 0x06 ///< The DMA channel transfers from XRAM to the I2C    
                                               ///< Slave data register.                              
#define DMA0NCF2_PERIPH__I2C_DATA_TO_XRAM 0x07 ///< The DMA channel transfers from the I2C Slave data 
                                               ///< register to XRAM.                                 
                                                                                                      
#define DMA0NCF2_ENDIAN__BMASK            0x10 ///< Data Transfer Endianness                          
#define DMA0NCF2_ENDIAN__SHIFT            0x04 ///< Data Transfer Endianness                          
#define DMA0NCF2_ENDIAN__LITTLE           0x00 ///< Data is written to and read from XRAM in little   
                                               ///< endian order.                                     
#define DMA0NCF2_ENDIAN__BIG              0x10 ///< Data is written to and read from XRAM in big      
                                               ///< endian order.                                     
                                                                                                      
#define DMA0NCF2_STALL__BMASK             0x20 ///< Channel Stall                                     
#define DMA0NCF2_STALL__SHIFT             0x05 ///< Channel Stall                                     
#define DMA0NCF2_STALL__NOT_SET           0x00 ///< The DMA transfer of the selected channel is not   
                                               ///< stalled.                                          
#define DMA0NCF2_STALL__SET               0x20 ///< The DMA transfer of the selected channel is       
                                               ///< stalled.                                          
                                                                                                      
#define DMA0NCF2_MIEN__BMASK              0x40 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF2_MIEN__SHIFT              0x06 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF2_MIEN__DISABLED           0x00 ///< Disable the DMA0 mid-point interrupt request of   
                                               ///< the selected channel.                             
#define DMA0NCF2_MIEN__ENABLED            0x40 ///< Enable the DMA0 mid-point interrupt request of the
                                               ///< selected channel.                                 
                                                                                                      
#define DMA0NCF2_IEN__BMASK               0x80 ///< Full-Length Interrupt Enable                      
#define DMA0NCF2_IEN__SHIFT               0x07 ///< Full-Length Interrupt Enable                      
#define DMA0NCF2_IEN__DISABLED            0x00 ///< Disable the DMA0 full-length interrupt request of 
                                               ///< the selected channel.                             
#define DMA0NCF2_IEN__ENABLED             0x80 ///< Enable the DMA0 full-length interrupt request of  
                                               ///< the selected channel.                             
                                                                                                      
//------------------------------------------------------------------------------
// DMA0NCF3 Enums (DMA0 Channel 3 Configuration @ 0x03)
//------------------------------------------------------------------------------
#define DMA0NCF3_PERIPH__FMASK            0x07 ///< Peripheral Transfer Select                        
#define DMA0NCF3_PERIPH__SHIFT            0x00 ///< Peripheral Transfer Select                        
#define DMA0NCF3_PERIPH__XRAM_TO_MAC_A    0x02 ///< The DMA channel transfers from XRAM to the MAC A  
                                               ///< register.                                         
#define DMA0NCF3_PERIPH__XRAM_TO_MAC_B    0x03 ///< The DMA channel transfers from XRAM to the MAC B  
                                               ///< register.                                         
#define DMA0NCF3_PERIPH__XRAM_TO_MAC_ACC  0x04 ///< The DMA channel transfers from XRAM to the MAC    
                                               ///< accumulator registers.                            
#define DMA0NCF3_PERIPH__MAC_ACC_TO_XRAM  0x05 ///< The DMA channel transfers from the MAC accumulator
                                               ///< registers to XRAM.                                
#define DMA0NCF3_PERIPH__XRAM_TO_I2C_DATA 0x06 ///< The DMA channel transfers from XRAM to the I2C    
                                               ///< Slave data register.                              
#define DMA0NCF3_PERIPH__I2C_DATA_TO_XRAM 0x07 ///< The DMA channel transfers from the I2C Slave data 
                                               ///< register to XRAM.                                 
                                                                                                      
#define DMA0NCF3_ENDIAN__BMASK            0x10 ///< Data Transfer Endianness                          
#define DMA0NCF3_ENDIAN__SHIFT            0x04 ///< Data Transfer Endianness                          
#define DMA0NCF3_ENDIAN__LITTLE           0x00 ///< Data is written to and read from XRAM in little   
                                               ///< endian order.                                     
#define DMA0NCF3_ENDIAN__BIG              0x10 ///< Data is written to and read from XRAM in big      
                                               ///< endian order.                                     
                                                                                                      
#define DMA0NCF3_STALL__BMASK             0x20 ///< Channel Stall                                     
#define DMA0NCF3_STALL__SHIFT             0x05 ///< Channel Stall                                     
#define DMA0NCF3_STALL__NOT_SET           0x00 ///< The DMA transfer of the selected channel is not   
                                               ///< stalled.                                          
#define DMA0NCF3_STALL__SET               0x20 ///< The DMA transfer of the selected channel is       
                                               ///< stalled.                                          
                                                                                                      
#define DMA0NCF3_MIEN__BMASK              0x40 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF3_MIEN__SHIFT              0x06 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF3_MIEN__DISABLED           0x00 ///< Disable the DMA0 mid-point interrupt request of   
                                               ///< the selected channel.                             
#define DMA0NCF3_MIEN__ENABLED            0x40 ///< Enable the DMA0 mid-point interrupt request of the
                                               ///< selected channel.                                 
                                                                                                      
#define DMA0NCF3_IEN__BMASK               0x80 ///< Full-Length Interrupt Enable                      
#define DMA0NCF3_IEN__SHIFT               0x07 ///< Full-Length Interrupt Enable                      
#define DMA0NCF3_IEN__DISABLED            0x00 ///< Disable the DMA0 full-length interrupt request of 
                                               ///< the selected channel.                             
#define DMA0NCF3_IEN__ENABLED             0x80 ///< Enable the DMA0 full-length interrupt request of  
                                               ///< the selected channel.                             
                                                                                                      
//------------------------------------------------------------------------------
// DMA0NCF4 Enums (DMA0 Channel 4 Configuration @ 0x04)
//------------------------------------------------------------------------------
#define DMA0NCF4_PERIPH__FMASK            0x07 ///< Peripheral Transfer Select                        
#define DMA0NCF4_PERIPH__SHIFT            0x00 ///< Peripheral Transfer Select                        
#define DMA0NCF4_PERIPH__XRAM_TO_MAC_A    0x02 ///< The DMA channel transfers from XRAM to the MAC A  
                                               ///< register.                                         
#define DMA0NCF4_PERIPH__XRAM_TO_MAC_B    0x03 ///< The DMA channel transfers from XRAM to the MAC B  
                                               ///< register.                                         
#define DMA0NCF4_PERIPH__XRAM_TO_MAC_ACC  0x04 ///< The DMA channel transfers from XRAM to the MAC    
                                               ///< accumulator registers.                            
#define DMA0NCF4_PERIPH__MAC_ACC_TO_XRAM  0x05 ///< The DMA channel transfers from the MAC accumulator
                                               ///< registers to XRAM.                                
#define DMA0NCF4_PERIPH__XRAM_TO_I2C_DATA 0x06 ///< The DMA channel transfers from XRAM to the I2C    
                                               ///< Slave data register.                              
#define DMA0NCF4_PERIPH__I2C_DATA_TO_XRAM 0x07 ///< The DMA channel transfers from the I2C Slave data 
                                               ///< register to XRAM.                                 
                                                                                                      
#define DMA0NCF4_ENDIAN__BMASK            0x10 ///< Data Transfer Endianness                          
#define DMA0NCF4_ENDIAN__SHIFT            0x04 ///< Data Transfer Endianness                          
#define DMA0NCF4_ENDIAN__LITTLE           0x00 ///< Data is written to and read from XRAM in little   
                                               ///< endian order.                                     
#define DMA0NCF4_ENDIAN__BIG              0x10 ///< Data is written to and read from XRAM in big      
                                               ///< endian order.                                     
                                                                                                      
#define DMA0NCF4_STALL__BMASK             0x20 ///< Channel Stall                                     
#define DMA0NCF4_STALL__SHIFT             0x05 ///< Channel Stall                                     
#define DMA0NCF4_STALL__NOT_SET           0x00 ///< The DMA transfer of the selected channel is not   
                                               ///< stalled.                                          
#define DMA0NCF4_STALL__SET               0x20 ///< The DMA transfer of the selected channel is       
                                               ///< stalled.                                          
                                                                                                      
#define DMA0NCF4_MIEN__BMASK              0x40 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF4_MIEN__SHIFT              0x06 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF4_MIEN__DISABLED           0x00 ///< Disable the DMA0 mid-point interrupt request of   
                                               ///< the selected channel.                             
#define DMA0NCF4_MIEN__ENABLED            0x40 ///< Enable the DMA0 mid-point interrupt request of the
                                               ///< selected channel.                                 
                                                                                                      
#define DMA0NCF4_IEN__BMASK               0x80 ///< Full-Length Interrupt Enable                      
#define DMA0NCF4_IEN__SHIFT               0x07 ///< Full-Length Interrupt Enable                      
#define DMA0NCF4_IEN__DISABLED            0x00 ///< Disable the DMA0 full-length interrupt request of 
                                               ///< the selected channel.                             
#define DMA0NCF4_IEN__ENABLED             0x80 ///< Enable the DMA0 full-length interrupt request of  
                                               ///< the selected channel.                             
                                                                                                      
//------------------------------------------------------------------------------
// DMA0NCF5 Enums (DMA0 Channel 5 Configuration @ 0x05)
//------------------------------------------------------------------------------
#define DMA0NCF5_PERIPH__FMASK            0x07 ///< Peripheral Transfer Select                        
#define DMA0NCF5_PERIPH__SHIFT            0x00 ///< Peripheral Transfer Select                        
#define DMA0NCF5_PERIPH__XRAM_TO_MAC_A    0x02 ///< The DMA channel transfers from XRAM to the MAC A  
                                               ///< register.                                         
#define DMA0NCF5_PERIPH__XRAM_TO_MAC_B    0x03 ///< The DMA channel transfers from XRAM to the MAC B  
                                               ///< register.                                         
#define DMA0NCF5_PERIPH__XRAM_TO_MAC_ACC  0x04 ///< The DMA channel transfers from XRAM to the MAC    
                                               ///< accumulator registers.                            
#define DMA0NCF5_PERIPH__MAC_ACC_TO_XRAM  0x05 ///< The DMA channel transfers from the MAC accumulator
                                               ///< registers to XRAM.                                
#define DMA0NCF5_PERIPH__XRAM_TO_I2C_DATA 0x06 ///< The DMA channel transfers from XRAM to the I2C    
                                               ///< Slave data register.                              
#define DMA0NCF5_PERIPH__I2C_DATA_TO_XRAM 0x07 ///< The DMA channel transfers from the I2C Slave data 
                                               ///< register to XRAM.                                 
                                                                                                      
#define DMA0NCF5_ENDIAN__BMASK            0x10 ///< Data Transfer Endianness                          
#define DMA0NCF5_ENDIAN__SHIFT            0x04 ///< Data Transfer Endianness                          
#define DMA0NCF5_ENDIAN__LITTLE           0x00 ///< Data is written to and read from XRAM in little   
                                               ///< endian order.                                     
#define DMA0NCF5_ENDIAN__BIG              0x10 ///< Data is written to and read from XRAM in big      
                                               ///< endian order.                                     
                                                                                                      
#define DMA0NCF5_STALL__BMASK             0x20 ///< Channel Stall                                     
#define DMA0NCF5_STALL__SHIFT             0x05 ///< Channel Stall                                     
#define DMA0NCF5_STALL__NOT_SET           0x00 ///< The DMA transfer of the selected channel is not   
                                               ///< stalled.                                          
#define DMA0NCF5_STALL__SET               0x20 ///< The DMA transfer of the selected channel is       
                                               ///< stalled.                                          
                                                                                                      
#define DMA0NCF5_MIEN__BMASK              0x40 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF5_MIEN__SHIFT              0x06 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF5_MIEN__DISABLED           0x00 ///< Disable the DMA0 mid-point interrupt request of   
                                               ///< the selected channel.                             
#define DMA0NCF5_MIEN__ENABLED            0x40 ///< Enable the DMA0 mid-point interrupt request of the
                                               ///< selected channel.                                 
                                                                                                      
#define DMA0NCF5_IEN__BMASK               0x80 ///< Full-Length Interrupt Enable                      
#define DMA0NCF5_IEN__SHIFT               0x07 ///< Full-Length Interrupt Enable                      
#define DMA0NCF5_IEN__DISABLED            0x00 ///< Disable the DMA0 full-length interrupt request of 
                                               ///< the selected channel.                             
#define DMA0NCF5_IEN__ENABLED             0x80 ///< Enable the DMA0 full-length interrupt request of  
                                               ///< the selected channel.                             
                                                                                                      
//------------------------------------------------------------------------------
// DMA0NCF6 Enums (DMA0 Channel 6 Configuration @ 0x06)
//------------------------------------------------------------------------------
#define DMA0NCF6_PERIPH__FMASK            0x07 ///< Peripheral Transfer Select                        
#define DMA0NCF6_PERIPH__SHIFT            0x00 ///< Peripheral Transfer Select                        
#define DMA0NCF6_PERIPH__XRAM_TO_MAC_A    0x02 ///< The DMA channel transfers from XRAM to the MAC A  
                                               ///< register.                                         
#define DMA0NCF6_PERIPH__XRAM_TO_MAC_B    0x03 ///< The DMA channel transfers from XRAM to the MAC B  
                                               ///< register.                                         
#define DMA0NCF6_PERIPH__XRAM_TO_MAC_ACC  0x04 ///< The DMA channel transfers from XRAM to the MAC    
                                               ///< accumulator registers.                            
#define DMA0NCF6_PERIPH__MAC_ACC_TO_XRAM  0x05 ///< The DMA channel transfers from the MAC accumulator
                                               ///< registers to XRAM.                                
#define DMA0NCF6_PERIPH__XRAM_TO_I2C_DATA 0x06 ///< The DMA channel transfers from XRAM to the I2C    
                                               ///< Slave data register.                              
#define DMA0NCF6_PERIPH__I2C_DATA_TO_XRAM 0x07 ///< The DMA channel transfers from the I2C Slave data 
                                               ///< register to XRAM.                                 
                                                                                                      
#define DMA0NCF6_ENDIAN__BMASK            0x10 ///< Data Transfer Endianness                          
#define DMA0NCF6_ENDIAN__SHIFT            0x04 ///< Data Transfer Endianness                          
#define DMA0NCF6_ENDIAN__LITTLE           0x00 ///< Data is written to and read from XRAM in little   
                                               ///< endian order.                                     
#define DMA0NCF6_ENDIAN__BIG              0x10 ///< Data is written to and read from XRAM in big      
                                               ///< endian order.                                     
                                                                                                      
#define DMA0NCF6_STALL__BMASK             0x20 ///< Channel Stall                                     
#define DMA0NCF6_STALL__SHIFT             0x05 ///< Channel Stall                                     
#define DMA0NCF6_STALL__NOT_SET           0x00 ///< The DMA transfer of the selected channel is not   
                                               ///< stalled.                                          
#define DMA0NCF6_STALL__SET               0x20 ///< The DMA transfer of the selected channel is       
                                               ///< stalled.                                          
                                                                                                      
#define DMA0NCF6_MIEN__BMASK              0x40 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF6_MIEN__SHIFT              0x06 ///< Mid-Point Interrupt Enable                        
#define DMA0NCF6_MIEN__DISABLED           0x00 ///< Disable the DMA0 mid-point interrupt request of   
                                               ///< the selected channel.                             
#define DMA0NCF6_MIEN__ENABLED            0x40 ///< Enable the DMA0 mid-point interrupt request of the
                                               ///< selected channel.                                 
                                                                                                      
#define DMA0NCF6_IEN__BMASK               0x80 ///< Full-Length Interrupt Enable                      
#define DMA0NCF6_IEN__SHIFT               0x07 ///< Full-Length Interrupt Enable                      
#define DMA0NCF6_IEN__DISABLED            0x00 ///< Disable the DMA0 full-length interrupt request of 
                                               ///< the selected channel.                             
#define DMA0NCF6_IEN__ENABLED             0x80 ///< Enable the DMA0 full-length interrupt request of  
                                               ///< the selected channel.                             
                                                                                                      
//------------------------------------------------------------------------------
// DMA0NMD Enums (DMA Channel Mode @ 0xD6)
//------------------------------------------------------------------------------
#define DMA0NMD_WRAP__BMASK    0x01 ///< Wrap Enable                                  
#define DMA0NMD_WRAP__SHIFT    0x00 ///< Wrap Enable                                  
#define DMA0NMD_WRAP__DISABLED 0x00 ///< Disable wrapping on the selected DMA channel.
#define DMA0NMD_WRAP__ENABLED  0x01 ///< Enable wrapping on the selected DMA channel. 
                                                                                      
//------------------------------------------------------------------------------
// DMA0NSZH Enums (Memory Transfer Size High @ 0xCF)
//------------------------------------------------------------------------------
#define DMA0NSZH_NSZH__FMASK 0x03 ///< Memory Transfer Size High
#define DMA0NSZH_NSZH__SHIFT 0x00 ///< Memory Transfer Size High
                                                                
//------------------------------------------------------------------------------
// DMA0NSZH0 Enums (Channel 0 Memory Transfer Size High @ 0x00)
//------------------------------------------------------------------------------
#define DMA0NSZH0_NSZH__FMASK 0x03 ///< Memory Transfer Size High
#define DMA0NSZH0_NSZH__SHIFT 0x00 ///< Memory Transfer Size High
                                                                 
//------------------------------------------------------------------------------
// DMA0NSZH1 Enums (Channel 1 Memory Transfer Size High @ 0x01)
//------------------------------------------------------------------------------
#define DMA0NSZH1_NSZH__FMASK 0x03 ///< Memory Transfer Size High
#define DMA0NSZH1_NSZH__SHIFT 0x00 ///< Memory Transfer Size High
                                                                 
//------------------------------------------------------------------------------
// DMA0NSZH2 Enums (Channel 2 Memory Transfer Size High @ 0x02)
//------------------------------------------------------------------------------
#define DMA0NSZH2_NSZH__FMASK 0x03 ///< Memory Transfer Size High
#define DMA0NSZH2_NSZH__SHIFT 0x00 ///< Memory Transfer Size High
                                                                 
//------------------------------------------------------------------------------
// DMA0NSZH3 Enums (Channel 3 Memory Transfer Size High @ 0x03)
//------------------------------------------------------------------------------
#define DMA0NSZH3_NSZH__FMASK 0x03 ///< Memory Transfer Size High
#define DMA0NSZH3_NSZH__SHIFT 0x00 ///< Memory Transfer Size High
                                                                 
//------------------------------------------------------------------------------
// DMA0NSZH4 Enums (Channel 4 Memory Transfer Size High @ 0x04)
//------------------------------------------------------------------------------
#define DMA0NSZH4_NSZH__FMASK 0x03 ///< Memory Transfer Size High
#define DMA0NSZH4_NSZH__SHIFT 0x00 ///< Memory Transfer Size High
                                                                 
//------------------------------------------------------------------------------
// DMA0NSZH5 Enums (Channel 5 Memory Transfer Size High @ 0x05)
//------------------------------------------------------------------------------
#define DMA0NSZH5_NSZH__FMASK 0x03 ///< Memory Transfer Size High
#define DMA0NSZH5_NSZH__SHIFT 0x00 ///< Memory Transfer Size High
                                                                 
//------------------------------------------------------------------------------
// DMA0NSZH6 Enums (Channel 6 Memory Transfer Size High @ 0x06)
//------------------------------------------------------------------------------
#define DMA0NSZH6_NSZH__FMASK 0x03 ///< Memory Transfer Size High
#define DMA0NSZH6_NSZH__SHIFT 0x00 ///< Memory Transfer Size High
                                                                 
//------------------------------------------------------------------------------
// DMA0NSZL Enums (Memory Transfer Size Low @ 0xCE)
//------------------------------------------------------------------------------
#define DMA0NSZL_NSZL__FMASK 0xFF ///< Memory Transfer Size Low
#define DMA0NSZL_NSZL__SHIFT 0x00 ///< Memory Transfer Size Low
                                                               
//------------------------------------------------------------------------------
// DMA0NSZL0 Enums (Channel 0 Memory Transfer Size Low @ 0x00)
//------------------------------------------------------------------------------
#define DMA0NSZL0_NSZL__FMASK 0xFF ///< Memory Transfer Size Low
#define DMA0NSZL0_NSZL__SHIFT 0x00 ///< Memory Transfer Size Low
                                                                
//------------------------------------------------------------------------------
// DMA0NSZL1 Enums (Channel 1 Memory Transfer Size Low @ 0x01)
//------------------------------------------------------------------------------
#define DMA0NSZL1_NSZL__FMASK 0xFF ///< Memory Transfer Size Low
#define DMA0NSZL1_NSZL__SHIFT 0x00 ///< Memory Transfer Size Low
                                                                
//------------------------------------------------------------------------------
// DMA0NSZL2 Enums (Channel 2 Memory Transfer Size Low @ 0x02)
//------------------------------------------------------------------------------
#define DMA0NSZL2_NSZL__FMASK 0xFF ///< Memory Transfer Size Low
#define DMA0NSZL2_NSZL__SHIFT 0x00 ///< Memory Transfer Size Low
                                                                
//------------------------------------------------------------------------------
// DMA0NSZL3 Enums (Channel 3 Memory Transfer Size Low @ 0x03)
//------------------------------------------------------------------------------
#define DMA0NSZL3_NSZL__FMASK 0xFF ///< Memory Transfer Size Low
#define DMA0NSZL3_NSZL__SHIFT 0x00 ///< Memory Transfer Size Low
                                                                
//------------------------------------------------------------------------------
// DMA0NSZL4 Enums (Channel 4 Memory Transfer Size Low @ 0x04)
//------------------------------------------------------------------------------
#define DMA0NSZL4_NSZL__FMASK 0xFF ///< Memory Transfer Size Low
#define DMA0NSZL4_NSZL__SHIFT 0x00 ///< Memory Transfer Size Low
                                                                
//------------------------------------------------------------------------------
// DMA0NSZL5 Enums (Channel 5 Memory Transfer Size Low @ 0x05)
//------------------------------------------------------------------------------
#define DMA0NSZL5_NSZL__FMASK 0xFF ///< Memory Transfer Size Low
#define DMA0NSZL5_NSZL__SHIFT 0x00 ///< Memory Transfer Size Low
                                                                
//------------------------------------------------------------------------------
// DMA0NSZL6 Enums (Channel 6 Memory Transfer Size Low @ 0x06)
//------------------------------------------------------------------------------
#define DMA0NSZL6_NSZL__FMASK 0xFF ///< Memory Transfer Size Low
#define DMA0NSZL6_NSZL__SHIFT 0x00 ///< Memory Transfer Size Low
                                                                
//------------------------------------------------------------------------------
// DMA0SEL Enums (DMA0 Channel Select @ 0xD1)
//------------------------------------------------------------------------------
#define DMA0SEL_SELECT__FMASK 0x07 ///< Channel Select   
#define DMA0SEL_SELECT__SHIFT 0x00 ///< Channel Select   
#define DMA0SEL_SELECT__CH0   0x00 ///< Select channel 0.
#define DMA0SEL_SELECT__CH1   0x01 ///< Select channel 1.
#define DMA0SEL_SELECT__CH2   0x02 ///< Select channel 2.
#define DMA0SEL_SELECT__CH3   0x03 ///< Select channel 3.
#define DMA0SEL_SELECT__CH4   0x04 ///< Select channel 4.
#define DMA0SEL_SELECT__CH5   0x05 ///< Select channel 5.
#define DMA0SEL_SELECT__CH6   0x06 ///< Select channel 6.
                                                         
//------------------------------------------------------------------------------
// ENC0CN Enums (Encoder / Decoder 0 Control @ 0xC5)
//------------------------------------------------------------------------------
#define ENC0CN_MODE__BMASK               0x01 ///< Operation Mode                                    
#define ENC0CN_MODE__SHIFT               0x00 ///< Operation Mode                                    
#define ENC0CN_MODE__MANCHESTER          0x00 ///< Select Manchester encoding or decoding.           
#define ENC0CN_MODE__THREE_OUT_OF_SIX    0x01 ///< Select Three-out-of-Six encoding or decoding.     
                                                                                                     
#define ENC0CN_ENDIAN__BMASK             0x02 ///< Big-Endian DMA Mode Select                        
#define ENC0CN_ENDIAN__SHIFT             0x01 ///< Big-Endian DMA Mode Select                        
#define ENC0CN_ENDIAN__DMA_LITTLE_ENDIAN 0x00 ///< Configure the Encoder / Decoder for little-endian 
                                              ///< multiple-byte DMA transfers.                      
#define ENC0CN_ENDIAN__DMA_BIG_ENDIAN    0x02 ///< Configure the Encoder / Decoder for big-endian    
                                              ///< multiple-byte DMA transfers.                      
                                                                                                     
#define ENC0CN_DMA__BMASK                0x04 ///< DMA Mode Enable                                   
#define ENC0CN_DMA__SHIFT                0x02 ///< DMA Mode Enable                                   
#define ENC0CN_DMA__DISABLED             0x00 ///< Disable DMA mode.                                 
#define ENC0CN_DMA__ENABLED              0x04 ///< Enable DMA mode.                                  
                                                                                                     
#define ENC0CN_DEC__BMASK                0x10 ///< Decode                                            
#define ENC0CN_DEC__SHIFT                0x04 ///< Decode                                            
#define ENC0CN_DEC__START                0x10 ///< Start a decode operation.                         
                                                                                                     
#define ENC0CN_ENC__BMASK                0x20 ///< Encode                                            
#define ENC0CN_ENC__SHIFT                0x05 ///< Encode                                            
#define ENC0CN_ENC__START                0x20 ///< Start an encode operation.                        
                                                                                                     
#define ENC0CN_ERROR__BMASK              0x40 ///< Error Flag                                        
#define ENC0CN_ERROR__SHIFT              0x06 ///< Error Flag                                        
#define ENC0CN_ERROR__NOT_SET            0x00 ///< An error did not occur during the decode or encode
                                              ///< operation.                                        
#define ENC0CN_ERROR__SET                0x40 ///< An error occurred during the decode or encode     
                                              ///< operation.                                        
                                                                                                     
#define ENC0CN_READY__BMASK              0x80 ///< Ready Flag                                        
#define ENC0CN_READY__SHIFT              0x07 ///< Ready Flag                                        
#define ENC0CN_READY__NOT_SET            0x00 ///< An encode or decode operation is not in progress. 
#define ENC0CN_READY__SET                0x80 ///< An encode or decode operation is in progress.     
                                                                                                     
//------------------------------------------------------------------------------
// ENC0H Enums (Encoder / Decoder 0 Data High Byte @ 0xC4)
//------------------------------------------------------------------------------
#define ENC0H_ENC0H__FMASK 0xFF ///< Encoder / Decoder 0 Data High Byte
#define ENC0H_ENC0H__SHIFT 0x00 ///< Encoder / Decoder 0 Data High Byte
                                                                       
//------------------------------------------------------------------------------
// ENC0L Enums (Encoder / Decoder 0 Data Low Byte @ 0xC2)
//------------------------------------------------------------------------------
#define ENC0L_ENC0L__FMASK 0xFF ///< Encoder / Decoder 0 Data Low Byte
#define ENC0L_ENC0L__SHIFT 0x00 ///< Encoder / Decoder 0 Data Low Byte
                                                                      
//------------------------------------------------------------------------------
// ENC0M Enums (Encoder / Decoder 0 Data Middle Byte @ 0xC3)
//------------------------------------------------------------------------------
#define ENC0M_ENC0M__FMASK 0xFF ///< Encoder / Decoder 0 Data Middle Byte
#define ENC0M_ENC0M__SHIFT 0x00 ///< Encoder / Decoder 0 Data Middle Byte
                                                                         
//------------------------------------------------------------------------------
// IT01CF Enums (INT0/INT1 Configuration @ 0xE4)
//------------------------------------------------------------------------------
#define IT01CF_IN0SL__BMASK       0x01 ///< INT0 Port Pin Selection   
#define IT01CF_IN0SL__SHIFT       0x00 ///< INT0 Port Pin Selection   
#define IT01CF_IN0SL__P0_0        0x00 ///< Select P0.0.              
#define IT01CF_IN0SL__P0_1        0x01 ///< Select P0.1.              
#define IT01CF_IN0SL__P0_2        0x02 ///< Select P0.2.              
#define IT01CF_IN0SL__P0_3        0x03 ///< Select P0.3.              
#define IT01CF_IN0SL__P0_4        0x04 ///< Select P0.4.              
#define IT01CF_IN0SL__P0_5        0x05 ///< Select P0.5.              
#define IT01CF_IN0SL__P1_6        0x06 ///< Select P1.6.              
#define IT01CF_IN0SL__P1_7        0x07 ///< Select P1.7.              
                                                                      
#define IT01CF_IN0PL__BMASK       0x08 ///< INT0 Polarity             
#define IT01CF_IN0PL__SHIFT       0x03 ///< INT0 Polarity             
#define IT01CF_IN0PL__ACTIVE_LOW  0x00 ///< INT0 input is active low. 
#define IT01CF_IN0PL__ACTIVE_HIGH 0x08 ///< INT0 input is active high.
                                                                      
#define IT01CF_IN1SL__BMASK       0x10 ///< INT1 Port Pin Selection   
#define IT01CF_IN1SL__SHIFT       0x04 ///< INT1 Port Pin Selection   
#define IT01CF_IN1SL__P0_0        0x00 ///< Select P0.0.              
#define IT01CF_IN1SL__P0_1        0x10 ///< Select P0.1.              
#define IT01CF_IN1SL__P0_2        0x20 ///< Select P0.2.              
#define IT01CF_IN1SL__P0_3        0x30 ///< Select P0.3.              
#define IT01CF_IN1SL__P0_4        0x40 ///< Select P0.4.              
#define IT01CF_IN1SL__P0_5        0x50 ///< Select P0.5.              
#define IT01CF_IN1SL__P1_6        0x60 ///< Select P1.6.              
#define IT01CF_IN1SL__P1_7        0x70 ///< Select P1.7.              
                                                                      
#define IT01CF_IN1PL__BMASK       0x80 ///< INT1 Polarity             
#define IT01CF_IN1PL__SHIFT       0x07 ///< INT1 Polarity             
#define IT01CF_IN1PL__ACTIVE_LOW  0x00 ///< INT1 input is active low. 
#define IT01CF_IN1PL__ACTIVE_HIGH 0x80 ///< INT1 input is active high.
                                                                      
//------------------------------------------------------------------------------
// OSCXCN Enums (External Oscillator Control @ 0xB1)
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
                                                                                               
#define OSCXCN_XCLKVLD__BMASK        0x80 ///< External Oscillator Valid Flag                  
#define OSCXCN_XCLKVLD__SHIFT        0x07 ///< External Oscillator Valid Flag                  
#define OSCXCN_XCLKVLD__NOT_SET      0x00 ///< External Oscillator is unused or not yet stable.
#define OSCXCN_XCLKVLD__SET          0x80 ///< External Oscillator is running and stable.      
                                                                                               
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
#define FLSCL_BYPASS__BMASK    0x40 ///< Flash Read Timing One-Shot Bypass               
#define FLSCL_BYPASS__SHIFT    0x06 ///< Flash Read Timing One-Shot Bypass               
#define FLSCL_BYPASS__ONE_SHOT 0x00 ///< The one-shot determines the Flash read time.    
#define FLSCL_BYPASS__SYSCLK   0x40 ///< The system clock determines the Flash read time.
                                                                                         
//------------------------------------------------------------------------------
// FLWR Enums (Flash Write Only @ 0xE5)
//------------------------------------------------------------------------------
#define FLWR_FLWR__FMASK 0xFF ///< Flash Write Only
#define FLWR_FLWR__SHIFT 0x00 ///< Flash Write Only
                                                   
//------------------------------------------------------------------------------
// FRBCN Enums (Flash Read Buffer Control @ 0xB5)
//------------------------------------------------------------------------------
#define FRBCN_FLBLKWR__BMASK                0x01 ///< Block Write Enable                            
#define FRBCN_FLBLKWR__SHIFT                0x00 ///< Block Write Enable                            
#define FRBCN_FLBLKWR__BLOCK_WRITE_DISABLED 0x00 ///< Each byte of a firmware flash write is written
                                                 ///< individually.                                 
#define FRBCN_FLBLKWR__BLOCK_WRITE_ENABLED  0x01 ///< Flash bytes are written in groups of four.    
                                                                                                    
#define FRBCN_FRBD__BMASK                   0x02 ///< Flash Read Buffer Bypass                      
#define FRBCN_FRBD__SHIFT                   0x01 ///< Flash Read Buffer Bypass                      
#define FRBCN_FRBD__NORMAL                  0x00 ///< Flash read buffer is enabled and being used.  
#define FRBCN_FRBD__BYPASS                  0x02 ///< Flash read buffer is disabled and bypassed.   
                                                                                                    
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
// OSCICL Enums (High Frequency Oscillator Calibration @ 0xB3)
//------------------------------------------------------------------------------
#define OSCICL_OSCICL__FMASK 0x7F ///< Oscillator Calibration                   
#define OSCICL_OSCICL__SHIFT 0x00 ///< Oscillator Calibration                   
                                                                                
#define OSCICL_SSE__BMASK    0x80 ///< Spread Spectrum Enable                   
#define OSCICL_SSE__SHIFT    0x07 ///< Spread Spectrum Enable                   
#define OSCICL_SSE__DISABLED 0x00 ///< Spread Spectrum clock dithering disabled.
#define OSCICL_SSE__ENABLED  0x80 ///< Spread Spectrum clock dithering enabled. 
                                                                                
//------------------------------------------------------------------------------
// OSCICN Enums (High Frequency Oscillator Control @ 0xB2)
//------------------------------------------------------------------------------
#define OSCICN_IFRDY__BMASK     0x40 ///< Internal Oscillator Frequency Ready Flag       
#define OSCICN_IFRDY__SHIFT     0x06 ///< Internal Oscillator Frequency Ready Flag       
#define OSCICN_IFRDY__NOT_SET   0x00 ///< High Frequency Oscillator is not running at its
                                     ///< programmed frequency.                          
#define OSCICN_IFRDY__SET       0x40 ///< High Frequency Oscillator is running at its    
                                     ///< programmed frequency.                          
                                                                                         
#define OSCICN_IOSCEN__BMASK    0x80 ///< High Frequency Oscillator Enable               
#define OSCICN_IOSCEN__SHIFT    0x07 ///< High Frequency Oscillator Enable               
#define OSCICN_IOSCEN__DISABLED 0x00 ///< High Frequency Oscillator disabled.            
#define OSCICN_IOSCEN__ENABLED  0x80 ///< High Frequency Oscillator enabled.             
                                                                                         
//------------------------------------------------------------------------------
// EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
//------------------------------------------------------------------------------
#define EIE1_ESMB0__BMASK     0x01 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__SHIFT     0x00 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__DISABLED  0x00 ///< Disable all SMB0 interrupts.                      
#define EIE1_ESMB0__ENABLED   0x01 ///< Enable interrupt requests generated by SMB0.      
                                                                                          
#define EIE1_ERTC0A__BMASK    0x02 ///< RTC Alarm Interrupt Enable                        
#define EIE1_ERTC0A__SHIFT    0x01 ///< RTC Alarm Interrupt Enable                        
#define EIE1_ERTC0A__DISABLED 0x00 ///< Disable RTC Alarm interrupts.                     
#define EIE1_ERTC0A__ENABLED  0x02 ///< Enable interrupt requests generated by a RTC      
                                   ///< Alarm.                                            
                                                                                          
#define EIE1_EWADC0__BMASK    0x04 ///< Window Comparison ADC0 Interrupt Enable           
#define EIE1_EWADC0__SHIFT    0x02 ///< Window Comparison ADC0 Interrupt Enable           
#define EIE1_EWADC0__DISABLED 0x00 ///< Disable ADC0 Window Comparison interrupt.         
#define EIE1_EWADC0__ENABLED  0x04 ///< Enable interrupt requests generated by ADC0 Window
                                   ///< Compare flag (ADWINT).                            
                                                                                          
#define EIE1_EADC0__BMASK     0x08 ///< ADC0 Conversion Complete Interrupt Enable         
#define EIE1_EADC0__SHIFT     0x03 ///< ADC0 Conversion Complete Interrupt Enable         
#define EIE1_EADC0__DISABLED  0x00 ///< Disable ADC0 Conversion Complete interrupt.       
#define EIE1_EADC0__ENABLED   0x08 ///< Enable interrupt requests generated by the ADINT  
                                   ///< flag.                                             
                                                                                          
#define EIE1_EPCA0__BMASK     0x10 ///< Programmable Counter Array (PCA0) Interrupt Enable
#define EIE1_EPCA0__SHIFT     0x04 ///< Programmable Counter Array (PCA0) Interrupt Enable
#define EIE1_EPCA0__DISABLED  0x00 ///< Disable all PCA0 interrupts.                      
#define EIE1_EPCA0__ENABLED   0x10 ///< Enable interrupt requests generated by PCA0.      
                                                                                          
#define EIE1_ECP0__BMASK      0x20 ///< Comparator0 (CP0) Interrupt Enable                
#define EIE1_ECP0__SHIFT      0x05 ///< Comparator0 (CP0) Interrupt Enable                
#define EIE1_ECP0__DISABLED   0x00 ///< Disable CP0 interrupts.                           
#define EIE1_ECP0__ENABLED    0x20 ///< Enable interrupt requests generated by the        
                                   ///< comparator 0 CPRIF or CPFIF flags.                
                                                                                          
#define EIE1_ECP1__BMASK      0x40 ///< Comparator1 (CP1) Interrupt Enable                
#define EIE1_ECP1__SHIFT      0x06 ///< Comparator1 (CP1) Interrupt Enable                
#define EIE1_ECP1__DISABLED   0x00 ///< Disable CP1 interrupts.                           
#define EIE1_ECP1__ENABLED    0x40 ///< Enable interrupt requests generated by the        
                                   ///< comparator 1 CPRIF or CPFIF flags.                
                                                                                          
#define EIE1_ET3__BMASK       0x80 ///< Timer 3 Interrupt Enable                          
#define EIE1_ET3__SHIFT       0x07 ///< Timer 3 Interrupt Enable                          
#define EIE1_ET3__DISABLED    0x00 ///< Disable Timer 3 interrupts.                       
#define EIE1_ET3__ENABLED     0x80 ///< Enable interrupt requests generated by the TF3L or
                                   ///< TF3H flags.                                       
                                                                                          
//------------------------------------------------------------------------------
// EIE2 Enums (Extended Interrupt Enable 2 @ 0xE7)
//------------------------------------------------------------------------------
#define EIE2_EWARN__BMASK     0x01 ///< VDD/VBAT Supply Monitor Early Warning Interrupt Enable
#define EIE2_EWARN__SHIFT     0x00 ///< VDD/VBAT Supply Monitor Early Warning Interrupt Enable
#define EIE2_EWARN__DISABLED  0x00 ///< Disable the VDD/VBAT Supply Monitor Early Warning     
                                   ///< interrupt.                                            
#define EIE2_EWARN__ENABLED   0x01 ///< Enable interrupt requests generated by the            
                                   ///< VDD/VBAT Supply Monitor.                              
                                                                                              
#define EIE2_EMAT__BMASK      0x02 ///< Port Match Interrupts Enable                          
#define EIE2_EMAT__SHIFT      0x01 ///< Port Match Interrupts Enable                          
#define EIE2_EMAT__DISABLED   0x00 ///< Disable all Port Match interrupts.                    
#define EIE2_EMAT__ENABLED    0x02 ///< Enable interrupt requests generated by a Port         
                                   ///< Match.                                                
                                                                                              
#define EIE2_ERTC0F__BMASK    0x04 ///< RTC Oscillator Fail Interrupt Enable                  
#define EIE2_ERTC0F__SHIFT    0x02 ///< RTC Oscillator Fail Interrupt Enable                  
#define EIE2_ERTC0F__DISABLED 0x00 ///< Disable RTC Oscillator Fail interrupts.               
#define EIE2_ERTC0F__ENABLED  0x04 ///< Enable interrupt requests generated by the RTC        
                                   ///< Oscillator Fail event.                                
                                                                                              
#define EIE2_ESPI1__BMASK     0x08 ///< Serial Peripheral Interface (SPI1) Interrupt Enable   
#define EIE2_ESPI1__SHIFT     0x03 ///< Serial Peripheral Interface (SPI1) Interrupt Enable   
#define EIE2_ESPI1__DISABLED  0x00 ///< Disable all SPI1 interrupts.                          
#define EIE2_ESPI1__ENABLED   0x08 ///< Enable interrupt requests generated by SPI1.          
                                                                                              
#define EIE2_EPC0__BMASK      0x10 ///< Pulse Counter (PC0) Interrupt Enable                  
#define EIE2_EPC0__SHIFT      0x04 ///< Pulse Counter (PC0) Interrupt Enable                  
#define EIE2_EPC0__DISABLED   0x00 ///< Disable all PC0 interrupts.                           
#define EIE2_EPC0__ENABLED    0x10 ///< Enable interrupt requests generated by PC0.           
                                                                                              
#define EIE2_EDMA0__BMASK     0x20 ///< DMA0 Interrupt Enable                                 
#define EIE2_EDMA0__SHIFT     0x05 ///< DMA0 Interrupt Enable                                 
#define EIE2_EDMA0__DISABLED  0x00 ///< Disable all DMA0 interrupts.                          
#define EIE2_EDMA0__ENABLED   0x20 ///< Enable interrupt requests generated by DMA0.          
                                                                                              
#define EIE2_EENC0__BMASK     0x40 ///< Encoder / Decoder (ENCDEC0) Interrupt Enable          
#define EIE2_EENC0__SHIFT     0x06 ///< Encoder / Decoder (ENCDEC0) Interrupt Enable          
#define EIE2_EENC0__DISABLED  0x00 ///< Disable all ENCDEC0 interrupts.                       
#define EIE2_EENC0__ENABLED   0x40 ///< Enable interrupt requests generated by ENCDEC0.       
                                                                                              
#define EIE2_EAES0__BMASK     0x80 ///< AES0 Interrupt                                        
#define EIE2_EAES0__SHIFT     0x07 ///< AES0 Interrupt                                        
#define EIE2_EAES0__DISABLED  0x00 ///< Disable all AES0 interrupts.                          
#define EIE2_EAES0__ENABLED   0x80 ///< Enable interrupt requests generated by AES0.          
                                                                                              
//------------------------------------------------------------------------------
// EIP1 Enums (Extended Interrupt Priority 1 @ 0xF6)
//------------------------------------------------------------------------------
#define EIP1_PSMB0__BMASK  0x01 ///< SMBus (SMB0) Interrupt Priority Control                     
#define EIP1_PSMB0__SHIFT  0x00 ///< SMBus (SMB0) Interrupt Priority Control                     
#define EIP1_PSMB0__LOW    0x00 ///< SMB0 interrupt set to low priority level.                   
#define EIP1_PSMB0__HIGH   0x01 ///< SMB0 interrupt set to high priority level.                  
                                                                                                 
#define EIP1_PRTC0A__BMASK 0x02 ///< RTC Alarm Interrupt Priority Control                        
#define EIP1_PRTC0A__SHIFT 0x01 ///< RTC Alarm Interrupt Priority Control                        
#define EIP1_PRTC0A__LOW   0x00 ///< RTC Alarm interrupt set to low priority level.              
#define EIP1_PRTC0A__HIGH  0x02 ///< RTC Alarm interrupt set to high priority level.             
                                                                                                 
#define EIP1_PWADC0__BMASK 0x04 ///< ADC0 Window Comparator Interrupt Priority Control           
#define EIP1_PWADC0__SHIFT 0x02 ///< ADC0 Window Comparator Interrupt Priority Control           
#define EIP1_PWADC0__LOW   0x00 ///< ADC0 Window interrupt set to low priority level.            
#define EIP1_PWADC0__HIGH  0x04 ///< ADC0 Window interrupt set to high priority level.           
                                                                                                 
#define EIP1_PADC0__BMASK  0x08 ///< ADC0 Conversion Complete Interrupt Priority Control         
#define EIP1_PADC0__SHIFT  0x03 ///< ADC0 Conversion Complete Interrupt Priority Control         
#define EIP1_PADC0__LOW    0x00 ///< ADC0 Conversion Complete interrupt set to low               
                                ///< priority level.                                             
#define EIP1_PADC0__HIGH   0x08 ///< ADC0 Conversion Complete interrupt set to high              
                                ///< priority level.                                             
                                                                                                 
#define EIP1_PPCA0__BMASK  0x10 ///< Programmable Counter Array (PCA0) Interrupt Priority Control
#define EIP1_PPCA0__SHIFT  0x04 ///< Programmable Counter Array (PCA0) Interrupt Priority Control
#define EIP1_PPCA0__LOW    0x00 ///< PCA0 interrupt set to low priority level.                   
#define EIP1_PPCA0__HIGH   0x10 ///< PCA0 interrupt set to high priority level.                  
                                                                                                 
#define EIP1_PCP0__BMASK   0x20 ///< Comparator0 (CP0) Interrupt Priority Control                
#define EIP1_PCP0__SHIFT   0x05 ///< Comparator0 (CP0) Interrupt Priority Control                
#define EIP1_PCP0__LOW     0x00 ///< CP0 interrupt set to low priority level.                    
#define EIP1_PCP0__HIGH    0x20 ///< CP0 interrupt set to high priority level.                   
                                                                                                 
#define EIP1_PCP1__BMASK   0x40 ///< Comparator1 (CP1) Interrupt Priority Control                
#define EIP1_PCP1__SHIFT   0x06 ///< Comparator1 (CP1) Interrupt Priority Control                
#define EIP1_PCP1__LOW     0x00 ///< CP1 interrupt set to low priority level.                    
#define EIP1_PCP1__HIGH    0x40 ///< CP1 interrupt set to high priority level.                   
                                                                                                 
#define EIP1_PT3__BMASK    0x80 ///< Timer 3 Interrupt Priority Control                          
#define EIP1_PT3__SHIFT    0x07 ///< Timer 3 Interrupt Priority Control                          
#define EIP1_PT3__LOW      0x00 ///< Timer 3 interrupts set to low priority level.               
#define EIP1_PT3__HIGH     0x80 ///< Timer 3 interrupts set to high priority level.              
                                                                                                 
//------------------------------------------------------------------------------
// EIP2 Enums (Extended Interrupt Priority 2 @ 0xF7)
//------------------------------------------------------------------------------
#define EIP2_PWARN__BMASK  0x01 ///< VDD/VBAT Supply Monitor Early Warning Interrupt Priority Control
#define EIP2_PWARN__SHIFT  0x00 ///< VDD/VBAT Supply Monitor Early Warning Interrupt Priority Control
#define EIP2_PWARN__LOW    0x00 ///< VDD/VBAT Supply Monitor Early Warning interrupt                 
                                ///< set to low priority level.                                      
#define EIP2_PWARN__HIGH   0x01 ///< VDD/VBAT Supply Monitor Early Warning interrupt                 
                                ///< set to high priority level.                                     
                                                                                                     
#define EIP2_PMAT__BMASK   0x02 ///< Port Match Interrupt Priority Control                           
#define EIP2_PMAT__SHIFT   0x01 ///< Port Match Interrupt Priority Control                           
#define EIP2_PMAT__LOW     0x00 ///< Port Match interrupt set to low priority level.                 
#define EIP2_PMAT__HIGH    0x02 ///< Port Match interrupt set to high priority level.                
                                                                                                     
#define EIP2_PRTC0F__BMASK 0x04 ///< RTC Oscillator Fail Interrupt Priority Control                  
#define EIP2_PRTC0F__SHIFT 0x02 ///< RTC Oscillator Fail Interrupt Priority Control                  
#define EIP2_PRTC0F__LOW   0x00 ///< RTC Oscillator Fail interrupt set to low priority               
                                ///< level.                                                          
#define EIP2_PRTC0F__HIGH  0x04 ///< RTC Oscillator Fail interrupt set to high priority              
                                ///< level.                                                          
                                                                                                     
#define EIP2_PSPI1__BMASK  0x08 ///< Serial Peripheral Interface (SPI1) Interrupt Priority Control   
#define EIP2_PSPI1__SHIFT  0x03 ///< Serial Peripheral Interface (SPI1) Interrupt Priority Control   
#define EIP2_PSPI1__LOW    0x00 ///< SPI1 interrupt set to low priority level.                       
#define EIP2_PSPI1__HIGH   0x08 ///< SPI1 interrupt set to high priority level.                      
                                                                                                     
#define EIP2_PPC0__BMASK   0x10 ///< Pulse Counter (PC0) Interrupt Priority Control                  
#define EIP2_PPC0__SHIFT   0x04 ///< Pulse Counter (PC0) Interrupt Priority Control                  
#define EIP2_PPC0__LOW     0x00 ///< PC0 interrupt set to low priority level.                        
#define EIP2_PPC0__HIGH    0x10 ///< PC0 interrupt set to high priority level.                       
                                                                                                     
#define EIP2_PDMA0__BMASK  0x20 ///< DMA0 Interrupt Priority Control                                 
#define EIP2_PDMA0__SHIFT  0x05 ///< DMA0 Interrupt Priority Control                                 
#define EIP2_PDMA0__LOW    0x00 ///< DMA0 interrupt set to low priority level.                       
#define EIP2_PDMA0__HIGH   0x20 ///< DMA0 interrupt set to high priority level.                      
                                                                                                     
#define EIP2_PENC0__BMASK  0x40 ///< Encoder / Decoder (ENCDEC0) Interrupt Priority Control          
#define EIP2_PENC0__SHIFT  0x06 ///< Encoder / Decoder (ENCDEC0) Interrupt Priority Control          
#define EIP2_PENC0__LOW    0x00 ///< ENCDEC0 interrupt set to low priority level.                    
#define EIP2_PENC0__HIGH   0x40 ///< ENCDEC0 interrupt set to high priority level.                   
                                                                                                     
#define EIP2_PAES0__BMASK  0x80 ///< AES0 Interrupt Priority Control                                 
#define EIP2_PAES0__SHIFT  0x07 ///< AES0 Interrupt Priority Control                                 
#define EIP2_PAES0__LOW    0x00 ///< AES0 interrupt set to low priority level.                       
#define EIP2_PAES0__HIGH   0x80 ///< AES0 interrupt set to high priority level.                      
                                                                                                     
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
// IREF0CF Enums (Current Reference Configuration @ 0xB9)
//------------------------------------------------------------------------------
#define IREF0CF_PWMSS__FMASK             0x07 ///< PWM Source Select                               
#define IREF0CF_PWMSS__SHIFT             0x00 ///< PWM Source Select                               
#define IREF0CF_PWMSS__FINE_TUNE_CEX0    0x00 ///< CEX0 selected as the fine-tuning control signal.
#define IREF0CF_PWMSS__FINE_TUNE_CEX1    0x01 ///< CEX1 selected as the fine-tuning control signal.
#define IREF0CF_PWMSS__FINE_TUNE_CEX2    0x02 ///< CEX2 selected as the fine-tuning control signal.
#define IREF0CF_PWMSS__FINE_TUNE_CEX3    0x03 ///< CEX3 selected as the fine-tuning control signal.
#define IREF0CF_PWMSS__FINE_TUNE_CEX4    0x04 ///< CEX4 selected as the fine-tuning control signal.
#define IREF0CF_PWMSS__FINE_TUNE_CEX5    0x05 ///< CEX5 selected as the fine-tuning control signal.
                                                                                                   
#define IREF0CF_PWMEN__BMASK             0x80 ///< PWM Enhanced Mode Enable                        
#define IREF0CF_PWMEN__SHIFT             0x07 ///< PWM Enhanced Mode Enable                        
#define IREF0CF_PWMEN__ENHANCED_DISABLED 0x00 ///< Disable PWM Enhanced Mode.                      
#define IREF0CF_PWMEN__ENHANCED_ENABLED  0x80 ///< Enable PWM Enhanced Mode.                       
                                                                                                   
//------------------------------------------------------------------------------
// IREF0CN Enums (Current Reference Control @ 0xB9)
//------------------------------------------------------------------------------
#define IREF0CN_IREF0DAT__FMASK     0x3F ///< IREF0 Data Word                                  
#define IREF0CN_IREF0DAT__SHIFT     0x00 ///< IREF0 Data Word                                  
                                                                                               
#define IREF0CN_MDSEL__BMASK        0x40 ///< IREF0 Output Mode Select                         
#define IREF0CN_MDSEL__SHIFT        0x06 ///< IREF0 Output Mode Select                         
#define IREF0CN_MDSEL__LOW_POWER    0x00 ///< Low Current Mode is selected (step size = 1 uA). 
#define IREF0CN_MDSEL__HIGH_CURRENT 0x40 ///< High Current Mode is selected (step size = 8 uA).
                                                                                               
#define IREF0CN_SINK__BMASK         0x80 ///< IREF0 Current Sink Enable                        
#define IREF0CN_SINK__SHIFT         0x07 ///< IREF0 Current Sink Enable                        
#define IREF0CN_SINK__DISABLED      0x00 ///< IREF0 is a current source.                       
#define IREF0CN_SINK__ENABLED       0x80 ///< IREF0 is a current sink.                         
                                                                                               
//------------------------------------------------------------------------------
// LCD0BLINK Enums (LCD0 Blink Mask @ 0x9E)
//------------------------------------------------------------------------------
#define LCD0BLINK_LCD0BLKP0__FMASK 0x0F ///< LCD0 Blink Mask Pin 0
#define LCD0BLINK_LCD0BLKP0__SHIFT 0x00 ///< LCD0 Blink Mask Pin 0
                                                                  
#define LCD0BLINK_LCD0BLKP1__FMASK 0xF0 ///< LCD0 Blink Mask Pin 1
#define LCD0BLINK_LCD0BLKP1__SHIFT 0x04 ///< LCD0 Blink Mask Pin 1
                                                                  
//------------------------------------------------------------------------------
// LCD0CF Enums (LCD0 Configuration @ 0xA5)
//------------------------------------------------------------------------------
#define LCD0CF_CMPBYP__BMASK    0x20 ///< VLCD/VIO Supply Comparator Bypass              
#define LCD0CF_CMPBYP__SHIFT    0x05 ///< VLCD/VIO Supply Comparator Bypass              
#define LCD0CF_CMPBYP__NORMAL   0x00 ///< VLCD/VIO supply voltage comparator is not      
                                     ///< bypassed.                                      
#define LCD0CF_CMPBYP__BYPASSED 0x20 ///< VLCD/VIO supply voltage comparator is bypassed.
                                                                                         
//------------------------------------------------------------------------------
// LCD0CLKDIVH Enums (LCD0 Refresh Rate Prescaler High Byte @ 0xAA)
//------------------------------------------------------------------------------
#define LCD0CLKDIVH_LCDDIV__FMASK 0x03 ///< LCD Refresh Rate Prescaler
#define LCD0CLKDIVH_LCDDIV__SHIFT 0x00 ///< LCD Refresh Rate Prescaler
                                                                      
//------------------------------------------------------------------------------
// LCD0CLKDIVL Enums (LCD Refresh Rate Prescaler Low Byte @ 0xA9)
//------------------------------------------------------------------------------
#define LCD0CLKDIVL_LCDDIV__FMASK 0xFF ///< LCD Refresh Rate Prescaler
#define LCD0CLKDIVL_LCDDIV__SHIFT 0x00 ///< LCD Refresh Rate Prescaler
                                                                      
//------------------------------------------------------------------------------
// LCD0CN Enums (LCD0 Control @ 0x9D)
//------------------------------------------------------------------------------
#define LCD0CN_BIAS__BMASK       0x01 ///< Bias Select                                   
#define LCD0CN_BIAS__SHIFT       0x00 ///< Bias Select                                   
#define LCD0CN_BIAS__ONE_THIRD   0x00 ///< LCD0 is configured for 1/3 Bias.              
#define LCD0CN_BIAS__ONE_HALF    0x01 ///< LCD0 is configured for 1/2 Bias.              
                                                                                         
#define LCD0CN_MUXMD__FMASK      0x06 ///< Multiplexer Mode                              
#define LCD0CN_MUXMD__SHIFT      0x01 ///< Multiplexer Mode                              
#define LCD0CN_MUXMD__STATIC     0x00 ///< Select static mode (COM0 used).               
#define LCD0CN_MUXMD__2_MUX_MODE 0x02 ///< Select 2-mux mode (COM0 and COM1 used).       
#define LCD0CN_MUXMD__3_MUX_MODE 0x04 ///< Select 3-mux mode (COM0, COM1, and COM2 used).
#define LCD0CN_MUXMD__4_MUX_MODE 0x06 ///< Select 4-mux mode (COM0, COM1, COM2, and COM3 
                                      ///< used).                                        
                                                                                         
#define LCD0CN_SIZE__BMASK       0x08 ///< LCD Size Select                               
#define LCD0CN_SIZE__SHIFT       0x03 ///< LCD Size Select                               
#define LCD0CN_SIZE__16_PINS     0x00 ///< Use P0 and P1 as LCD segment pins.            
#define LCD0CN_SIZE__32_PINS     0x08 ///< Use P0, P1, P2, and P3 as LCD segment pins.   
                                                                                         
#define LCD0CN_BLANK__BMASK      0x10 ///< Blank All Segments Enable                     
#define LCD0CN_BLANK__SHIFT      0x04 ///< Blank All Segments Enable                     
#define LCD0CN_BLANK__DISABLED   0x00 ///< All LCD segments are controlled by the LCD0Dn 
                                      ///< registers.                                    
#define LCD0CN_BLANK__ENABLED    0x10 ///< All LCD segments are blank (turned off).      
                                                                                         
#define LCD0CN_CLKDIV__FMASK     0x60 ///< LCD0 Clock Divider                            
#define LCD0CN_CLKDIV__SHIFT     0x05 ///< LCD0 Clock Divider                            
#define LCD0CN_CLKDIV__RTC_DIV_1 0x00 ///< The LCD clock is the RTC clock divided by 1.  
#define LCD0CN_CLKDIV__RTC_DIV_2 0x20 ///< The LCD clock is the RTC clock divided by 2.  
#define LCD0CN_CLKDIV__RTC_DIV_4 0x40 ///< The LCD clock is the RTC clock divided by 4.  
                                                                                         
//------------------------------------------------------------------------------
// LCD0CNTRST Enums (LCD0 Contrast Adjustment @ 0x9C)
//------------------------------------------------------------------------------
#define LCD0CNTRST_CNTRST__FMASK 0x1F ///< Contrast Setpoint                  
#define LCD0CNTRST_CNTRST__SHIFT 0x00 ///< Contrast Setpoint                  
#define LCD0CNTRST_CNTRST__1P90  0x00 ///< Set the contrast voltage to 1.90 V.
#define LCD0CNTRST_CNTRST__1P96  0x01 ///< Set the contrast voltage to 1.96 V.
#define LCD0CNTRST_CNTRST__2P02  0x02 ///< Set the contrast voltage to 2.02 V.
#define LCD0CNTRST_CNTRST__2P08  0x03 ///< Set the contrast voltage to 2.08 V.
#define LCD0CNTRST_CNTRST__2P13  0x04 ///< Set the contrast voltage to 2.13 V.
#define LCD0CNTRST_CNTRST__2P19  0x05 ///< Set the contrast voltage to 2.19 V.
#define LCD0CNTRST_CNTRST__2P25  0x06 ///< Set the contrast voltage to 2.25 V.
#define LCD0CNTRST_CNTRST__2P31  0x07 ///< Set the contrast voltage to 2.31 V.
#define LCD0CNTRST_CNTRST__2P37  0x08 ///< Set the contrast voltage to 2.37 V.
#define LCD0CNTRST_CNTRST__2P43  0x09 ///< Set the contrast voltage to 2.43 V.
#define LCD0CNTRST_CNTRST__2P49  0x0A ///< Set the contrast voltage to 2.49 V.
#define LCD0CNTRST_CNTRST__2P55  0x0B ///< Set the contrast voltage to 2.55 V.
#define LCD0CNTRST_CNTRST__2P60  0x0C ///< Set the contrast voltage to 2.60 V.
#define LCD0CNTRST_CNTRST__2P66  0x0D ///< Set the contrast voltage to 2.66 V.
#define LCD0CNTRST_CNTRST__2P72  0x0E ///< Set the contrast voltage to 2.72 V.
#define LCD0CNTRST_CNTRST__2P78  0x0F ///< Set the contrast voltage to 2.78 V.
#define LCD0CNTRST_CNTRST__2P84  0x10 ///< Set the contrast voltage to 2.84 V.
#define LCD0CNTRST_CNTRST__2P90  0x11 ///< Set the contrast voltage to 2.90 V.
#define LCD0CNTRST_CNTRST__2P96  0x12 ///< Set the contrast voltage to 2.96 V.
#define LCD0CNTRST_CNTRST__3P02  0x13 ///< Set the contrast voltage to 3.02 V.
#define LCD0CNTRST_CNTRST__3P07  0x14 ///< Set the contrast voltage to 3.07 V.
#define LCD0CNTRST_CNTRST__3P13  0x15 ///< Set the contrast voltage to 3.13 V.
#define LCD0CNTRST_CNTRST__3P19  0x16 ///< Set the contrast voltage to 3.19 V.
#define LCD0CNTRST_CNTRST__3P25  0x17 ///< Set the contrast voltage to 3.25 V.
#define LCD0CNTRST_CNTRST__3P31  0x18 ///< Set the contrast voltage to 3.31 V.
#define LCD0CNTRST_CNTRST__3P37  0x19 ///< Set the contrast voltage to 3.37 V.
#define LCD0CNTRST_CNTRST__3P43  0x1A ///< Set the contrast voltage to 3.43 V.
#define LCD0CNTRST_CNTRST__3P49  0x1B ///< Set the contrast voltage to 3.49 V.
#define LCD0CNTRST_CNTRST__3P54  0x1C ///< Set the contrast voltage to 3.54 V.
#define LCD0CNTRST_CNTRST__3P60  0x1D ///< Set the contrast voltage to 3.60 V.
#define LCD0CNTRST_CNTRST__3P66  0x1E ///< Set the contrast voltage to 3.66 V.
#define LCD0CNTRST_CNTRST__3P72  0x1F ///< Set the contrast voltage to 3.72 V.
                                                                              
//------------------------------------------------------------------------------
// LCD0D0 Enums (LCD0 Data 0 @ 0x89)
//------------------------------------------------------------------------------
#define LCD0D0_LCD0P0__FMASK 0x0F ///< LCD Pin 0 Data
#define LCD0D0_LCD0P0__SHIFT 0x00 ///< LCD Pin 0 Data
                                                     
#define LCD0D0_LCD0P1__FMASK 0xF0 ///< LCD Pin 1 Data
#define LCD0D0_LCD0P1__SHIFT 0x04 ///< LCD Pin 1 Data
                                                     
//------------------------------------------------------------------------------
// LCD0D1 Enums (LCD0 Data 1 @ 0x8A)
//------------------------------------------------------------------------------
#define LCD0D1_LCD0P2__FMASK 0x0F ///< LCD Pin 2 Data
#define LCD0D1_LCD0P2__SHIFT 0x00 ///< LCD Pin 2 Data
                                                     
#define LCD0D1_LCD0P3__FMASK 0xF0 ///< LCD Pin 3 Data
#define LCD0D1_LCD0P3__SHIFT 0x04 ///< LCD Pin 3 Data
                                                     
//------------------------------------------------------------------------------
// LCD0D2 Enums (LCD0 Data 2 @ 0x8B)
//------------------------------------------------------------------------------
#define LCD0D2_LCD0P4__FMASK 0x0F ///< LCD Pin 4 Data
#define LCD0D2_LCD0P4__SHIFT 0x00 ///< LCD Pin 4 Data
                                                     
#define LCD0D2_LCD0P5__FMASK 0xF0 ///< LCD Pin 5 Data
#define LCD0D2_LCD0P5__SHIFT 0x04 ///< LCD Pin 5 Data
                                                     
//------------------------------------------------------------------------------
// LCD0D3 Enums (LCD0 Data 3 @ 0x8C)
//------------------------------------------------------------------------------
#define LCD0D3_LCD0P6__FMASK 0x0F ///< LCD Pin 6 Data
#define LCD0D3_LCD0P6__SHIFT 0x00 ///< LCD Pin 6 Data
                                                     
#define LCD0D3_LCD0P7__FMASK 0xF0 ///< LCD Pin 7 Data
#define LCD0D3_LCD0P7__SHIFT 0x04 ///< LCD Pin 7 Data
                                                     
//------------------------------------------------------------------------------
// LCD0D4 Enums (LCD0 Data 4 @ 0x8D)
//------------------------------------------------------------------------------
#define LCD0D4_LCD0P8__FMASK 0x0F ///< LCD Pin 8 Data
#define LCD0D4_LCD0P8__SHIFT 0x00 ///< LCD Pin 8 Data
                                                     
#define LCD0D4_LCD0P9__FMASK 0xF0 ///< LCD Pin 9 Data
#define LCD0D4_LCD0P9__SHIFT 0x04 ///< LCD Pin 9 Data
                                                     
//------------------------------------------------------------------------------
// LCD0D5 Enums (LCD0 Data 5 @ 0x8E)
//------------------------------------------------------------------------------
#define LCD0D5_LCD0P10__FMASK 0x0F ///< LCD Pin 10 Data
#define LCD0D5_LCD0P10__SHIFT 0x00 ///< LCD Pin 10 Data
                                                       
#define LCD0D5_LCD0P11__FMASK 0xF0 ///< LCD Pin 11 Data
#define LCD0D5_LCD0P11__SHIFT 0x04 ///< LCD Pin 11 Data
                                                       
//------------------------------------------------------------------------------
// LCD0D6 Enums (LCD0 Data 6 @ 0x91)
//------------------------------------------------------------------------------
#define LCD0D6_LCD0P12__FMASK 0x0F ///< LCD Pin 12 Data
#define LCD0D6_LCD0P12__SHIFT 0x00 ///< LCD Pin 12 Data
                                                       
#define LCD0D6_LCD0P13__FMASK 0xF0 ///< LCD Pin 13 Data
#define LCD0D6_LCD0P13__SHIFT 0x04 ///< LCD Pin 13 Data
                                                       
//------------------------------------------------------------------------------
// LCD0D7 Enums (LCD0 Data 7 @ 0x92)
//------------------------------------------------------------------------------
#define LCD0D7_LCD0P14__FMASK 0x0F ///< LCD Pin 14 Data
#define LCD0D7_LCD0P14__SHIFT 0x00 ///< LCD Pin 14 Data
                                                       
#define LCD0D7_LCD0P15__FMASK 0xF0 ///< LCD Pin 15 Data
#define LCD0D7_LCD0P15__SHIFT 0x04 ///< LCD Pin 15 Data
                                                       
//------------------------------------------------------------------------------
// LCD0D8 Enums (LCD0 Data 8 @ 0x93)
//------------------------------------------------------------------------------
#define LCD0D8_LCD0P16__FMASK 0x0F ///< LCD Pin 16 Data
#define LCD0D8_LCD0P16__SHIFT 0x00 ///< LCD Pin 16 Data
                                                       
#define LCD0D8_LCD0P17__FMASK 0xF0 ///< LCD Pin 17 Data
#define LCD0D8_LCD0P17__SHIFT 0x04 ///< LCD Pin 17 Data
                                                       
//------------------------------------------------------------------------------
// LCD0D9 Enums (LCD0 Data 9 @ 0x94)
//------------------------------------------------------------------------------
#define LCD0D9_LCD0P18__FMASK 0x0F ///< LCD Pin 18 Data
#define LCD0D9_LCD0P18__SHIFT 0x00 ///< LCD Pin 18 Data
                                                       
#define LCD0D9_LCD0P19__FMASK 0xF0 ///< LCD Pin 19 Data
#define LCD0D9_LCD0P19__SHIFT 0x04 ///< LCD Pin 19 Data
                                                       
//------------------------------------------------------------------------------
// LCD0DA Enums (LCD0 Data 10 @ 0x95)
//------------------------------------------------------------------------------
#define LCD0DA_LCD0P20__FMASK 0x0F ///< LCD Pin 20 Data
#define LCD0DA_LCD0P20__SHIFT 0x00 ///< LCD Pin 20 Data
                                                       
#define LCD0DA_LCD0P21__FMASK 0xF0 ///< LCD Pin 21 Data
#define LCD0DA_LCD0P21__SHIFT 0x04 ///< LCD Pin 21 Data
                                                       
//------------------------------------------------------------------------------
// LCD0DB Enums (LCD0 Data 11 @ 0x96)
//------------------------------------------------------------------------------
#define LCD0DB_LCD0P22__FMASK 0x0F ///< LCD Pin 22 Data
#define LCD0DB_LCD0P22__SHIFT 0x00 ///< LCD Pin 22 Data
                                                       
#define LCD0DB_LCD0P23__FMASK 0xF0 ///< LCD Pin 23 Data
#define LCD0DB_LCD0P23__SHIFT 0x04 ///< LCD Pin 23 Data
                                                       
//------------------------------------------------------------------------------
// LCD0DC Enums (LCD0 Data 12 @ 0x97)
//------------------------------------------------------------------------------
#define LCD0DC_LCD0P24__FMASK 0x0F ///< LCD Pin 24 Data
#define LCD0DC_LCD0P24__SHIFT 0x00 ///< LCD Pin 24 Data
                                                       
#define LCD0DC_LCD0P25__FMASK 0xF0 ///< LCD Pin 25 Data
#define LCD0DC_LCD0P25__SHIFT 0x04 ///< LCD Pin 25 Data
                                                       
//------------------------------------------------------------------------------
// LCD0DD Enums (LCD0 Data 13 @ 0x99)
//------------------------------------------------------------------------------
#define LCD0DD_LCD0P26__FMASK 0x0F ///< LCD Pin 26 Data
#define LCD0DD_LCD0P26__SHIFT 0x00 ///< LCD Pin 26 Data
                                                       
#define LCD0DD_LCD0P27__FMASK 0xF0 ///< LCD Pin 27 Data
#define LCD0DD_LCD0P27__SHIFT 0x04 ///< LCD Pin 27 Data
                                                       
//------------------------------------------------------------------------------
// LCD0DE Enums (LCD0 Data 14 @ 0x9A)
//------------------------------------------------------------------------------
#define LCD0DE_LCD0P28__FMASK 0x0F ///< LCD Pin 28 Data
#define LCD0DE_LCD0P28__SHIFT 0x00 ///< LCD Pin 28 Data
                                                       
#define LCD0DE_LCD0P29__FMASK 0xF0 ///< LCD Pin 29 Data
#define LCD0DE_LCD0P29__SHIFT 0x04 ///< LCD Pin 29 Data
                                                       
//------------------------------------------------------------------------------
// LCD0DF Enums (LCD0 Data 15 @ 0x9B)
//------------------------------------------------------------------------------
#define LCD0DF_LCD0P30__FMASK 0x0F ///< LCD Pin 30 Data
#define LCD0DF_LCD0P30__SHIFT 0x00 ///< LCD Pin 30 Data
                                                       
#define LCD0DF_LCD0P31__FMASK 0xF0 ///< LCD Pin 31 Data
#define LCD0DF_LCD0P31__SHIFT 0x04 ///< LCD Pin 31 Data
                                                       
//------------------------------------------------------------------------------
// LCD0MSCF Enums (LCD0 Master Configuration @ 0xAC)
//------------------------------------------------------------------------------
#define LCD0MSCF_CHPBYP__BMASK     0x01 ///< LCD0 Charge Pump Bypass                  
#define LCD0MSCF_CHPBYP__SHIFT     0x00 ///< LCD0 Charge Pump Bypass                  
#define LCD0MSCF_CHPBYP__NORMAL    0x00 ///< LCD0 charge pump is not bypassed.        
#define LCD0MSCF_CHPBYP__BYPASSED  0x01 ///< LCD0 charge pump is bypassed.            
                                                                                      
#define LCD0MSCF_DCENSLP__BMASK    0x02 ///< DCDC Converter Sleep Mode Enable         
#define LCD0MSCF_DCENSLP__SHIFT    0x01 ///< DCDC Converter Sleep Mode Enable         
#define LCD0MSCF_DCENSLP__DISABLED 0x00 ///< Disable the DCDC Converter in Sleep mode.
#define LCD0MSCF_DCENSLP__ENABLED  0x02 ///< Enable the DCDC Converter in Sleep mode. 
                                                                                      
//------------------------------------------------------------------------------
// LCD0MSCN Enums (LCD0 Master Control @ 0xAB)
//------------------------------------------------------------------------------
#define LCD0MSCN_LCDEN__BMASK       0x01 ///< LCD0 Enable                                      
#define LCD0MSCN_LCDEN__SHIFT       0x00 ///< LCD0 Enable                                      
#define LCD0MSCN_LCDEN__DISABLED    0x00 ///< Disable the LCD0 module.                         
#define LCD0MSCN_LCDEN__ENABLED     0x01 ///< Enable the LCD0 module.                          
                                                                                               
#define LCD0MSCN_LCDRST__BMASK      0x02 ///< LCD0 Reset                                       
#define LCD0MSCN_LCDRST__SHIFT      0x01 ///< LCD0 Reset                                       
#define LCD0MSCN_LCDRST__DISABLED   0x00 ///< Disable the LCD0 reset.                          
#define LCD0MSCN_LCDRST__ENABLED    0x02 ///< Clear all of the LCD0Dn registers to 0x00.       
                                                                                               
#define LCD0MSCN_LOWDRV__BMASK      0x04 ///< Charge Pump Reduced Drive Mode                   
#define LCD0MSCN_LOWDRV__SHIFT      0x02 ///< Charge Pump Reduced Drive Mode                   
#define LCD0MSCN_LOWDRV__DISABLED   0x00 ///< The charge pump operates at full power.          
#define LCD0MSCN_LOWDRV__ENABLED    0x04 ///< The charge pump operates at reduced power.       
                                                                                               
#define LCD0MSCN_CLKOE__BMASK       0x10 ///< LCD Clock Output Enable                          
#define LCD0MSCN_CLKOE__SHIFT       0x04 ///< LCD Clock Output Enable                          
#define LCD0MSCN_CLKOE__DISABLED    0x00 ///< Disable the clock to the LCD0 module.            
#define LCD0MSCN_CLKOE__ENABLED     0x10 ///< Enable the clock to the LCD0 module from the RTC.
                                                                                               
#define LCD0MSCN_DCBIASOE__BMASK    0x20 ///< DCDC Converter Bias Output Enable                
#define LCD0MSCN_DCBIASOE__SHIFT    0x05 ///< DCDC Converter Bias Output Enable                
#define LCD0MSCN_DCBIASOE__DISABLED 0x00 ///< Disable the bias output from the LCD0 module for 
                                         ///< the DCDC converter.                              
#define LCD0MSCN_DCBIASOE__ENABLED  0x20 ///< Enable the bias output from the LCD0 module for  
                                         ///< the DCDC converter.                              
                                                                                               
#define LCD0MSCN_BIASEN__BMASK      0x40 ///< LCD0 Bias Enable                                 
#define LCD0MSCN_BIASEN__SHIFT      0x06 ///< LCD0 Bias Enable                                 
#define LCD0MSCN_BIASEN__DISABLED   0x00 ///< Disable the LCD0 bias.                           
#define LCD0MSCN_BIASEN__ENABLED    0x40 ///< Enable the LCD0 bias.                            
                                                                                               
//------------------------------------------------------------------------------
// LCD0PWR Enums (LCD0 Power @ 0xA4)
//------------------------------------------------------------------------------
#define LCD0PWR_MODE__BMASK  0x08 ///< LCD0 Contrast Control Mode Selection          
#define LCD0PWR_MODE__SHIFT  0x03 ///< LCD0 Contrast Control Mode Selection          
#define LCD0PWR_MODE__1_OR_4 0x00 ///< Select LCD0 Contrast Control Mode 1 or Mode 4.
#define LCD0PWR_MODE__2_OR_3 0x08 ///< Select LCD0 Contrast Control Mode 2 or Mode 3.
                                                                                     
//------------------------------------------------------------------------------
// LCD0TOGR Enums (LCD0 Toggle Rate @ 0x9F)
//------------------------------------------------------------------------------
#define LCD0TOGR_TOGR__FMASK    0x0F ///< LCD Toggle Rate Divider                      
#define LCD0TOGR_TOGR__SHIFT    0x00 ///< LCD Toggle Rate Divider                      
#define LCD0TOGR_TOGR__DIV_2    0x02 ///< Toggle Rate Divider is set to divide by 2.   
#define LCD0TOGR_TOGR__DIV_4    0x03 ///< Toggle Rate Divider is set to divide by 4.   
#define LCD0TOGR_TOGR__DIV_8    0x04 ///< Toggle Rate Divider is set to divide by 8.   
#define LCD0TOGR_TOGR__DIV_16   0x05 ///< Toggle Rate Divider is set to divide by 16.  
#define LCD0TOGR_TOGR__DIV_32   0x06 ///< Toggle Rate Divider is set to divide by 32.  
#define LCD0TOGR_TOGR__DIV_64   0x07 ///< Toggle Rate Divider is set to divide by 64.  
#define LCD0TOGR_TOGR__DIV_128  0x08 ///< Toggle Rate Divider is set to divide by 128. 
#define LCD0TOGR_TOGR__DIV_256  0x09 ///< Toggle Rate Divider is set to divide by 256. 
#define LCD0TOGR_TOGR__DIV_512  0x0A ///< Toggle Rate Divider is set to divide by 512. 
#define LCD0TOGR_TOGR__DIV_1024 0x0B ///< Toggle Rate Divider is set to divide by 1024.
#define LCD0TOGR_TOGR__DIV_2048 0x0C ///< Toggle Rate Divider is set to divide by 2048.
#define LCD0TOGR_TOGR__DIV_4096 0x0D ///< Toggle Rate Divider is set to divide by 4096.
                                                                                       
//------------------------------------------------------------------------------
// LCD0VBMCN Enums (LCD0 VBAT Monitor Control @ 0xA6)
//------------------------------------------------------------------------------
#define LCD0VBMCN_THRLD__FMASK      0x1F ///< VBAT Monitor Threshold                          
#define LCD0VBMCN_THRLD__SHIFT      0x00 ///< VBAT Monitor Threshold                          
                                                                                              
#define LCD0VBMCN_OFFSET__BMASK     0x40 ///< VBAT Monitor Offset Enable                      
#define LCD0VBMCN_OFFSET__SHIFT     0x06 ///< VBAT Monitor Offset Enable                      
#define LCD0VBMCN_OFFSET__DISABLED  0x00 ///< The VBAT Monitor threshold is independent of the
                                         ///< contrast setting.                               
#define LCD0VBMCN_OFFSET__ENABLED   0x40 ///< The VBAT Monitor threshold is linked to the     
                                         ///< contrast setting.                               
                                                                                              
#define LCD0VBMCN_VBATMEN__BMASK    0x80 ///< VBAT Monitor Enable                             
#define LCD0VBMCN_VBATMEN__SHIFT    0x07 ///< VBAT Monitor Enable                             
#define LCD0VBMCN_VBATMEN__DISABLED 0x00 ///< Disable the VBAT Monitor.                       
#define LCD0VBMCN_VBATMEN__ENABLED  0x80 ///< Enable the VBAT Monitor.                        
                                                                                              
//------------------------------------------------------------------------------
// XBR0 Enums (Port I/O Crossbar 0 @ 0xE1)
//------------------------------------------------------------------------------
#define XBR0_URT0E__BMASK     0x01 ///< UART0 I/O Output Enable                       
#define XBR0_URT0E__SHIFT     0x00 ///< UART0 I/O Output Enable                       
#define XBR0_URT0E__DISABLED  0x00 ///< UART I/O unavailable at Port pin.             
#define XBR0_URT0E__ENABLED   0x01 ///< TX0 and RX0 routed to Port pins P0.4 and P0.5.
                                                                                      
#define XBR0_SPI0E__BMASK     0x02 ///< SPI0 I/O Enable                               
#define XBR0_SPI0E__SHIFT     0x01 ///< SPI0 I/O Enable                               
#define XBR0_SPI0E__DISABLED  0x00 ///< SPI I/O unavailable at Port pins.             
#define XBR0_SPI0E__ENABLED   0x02 ///< SPI I/O routed to Port pins. The SPI can be   
                                   ///< assigned either 3 or 4 GPIO pins.             
                                                                                      
#define XBR0_SMB0E__BMASK     0x04 ///< SMBus0 I/O Enable                             
#define XBR0_SMB0E__SHIFT     0x02 ///< SMBus0 I/O Enable                             
#define XBR0_SMB0E__DISABLED  0x00 ///< SMBus0 I/O unavailable at Port pins.          
#define XBR0_SMB0E__ENABLED   0x04 ///< SMBus0 I/O routed to Port pins.               
                                                                                      
#define XBR0_SYSCKE__BMASK    0x08 ///< SYSCLK Output Enable                          
#define XBR0_SYSCKE__SHIFT    0x03 ///< SYSCLK Output Enable                          
#define XBR0_SYSCKE__DISABLED 0x00 ///< SYSCLK unavailable at Port pin.               
#define XBR0_SYSCKE__ENABLED  0x08 ///< SYSCLK output routed to Port pin.             
                                                                                      
#define XBR0_CP0E__BMASK      0x10 ///< Comparator0 Output Enable                     
#define XBR0_CP0E__SHIFT      0x04 ///< Comparator0 Output Enable                     
#define XBR0_CP0E__DISABLED   0x00 ///< CP0 unavailable at Port pin.                  
#define XBR0_CP0E__ENABLED    0x10 ///< CP0 routed to Port pin.                       
                                                                                      
#define XBR0_CP0AE__BMASK     0x20 ///< Comparator0 Asynchronous Output Enable        
#define XBR0_CP0AE__SHIFT     0x05 ///< Comparator0 Asynchronous Output Enable        
#define XBR0_CP0AE__DISABLED  0x00 ///< Asynchronous CP0 unavailable at Port pin.     
#define XBR0_CP0AE__ENABLED   0x20 ///< Asynchronous CP0 routed to Port pin.          
                                                                                      
#define XBR0_CP1E__BMASK      0x40 ///< Comparator1 Output Enable                     
#define XBR0_CP1E__SHIFT      0x06 ///< Comparator1 Output Enable                     
#define XBR0_CP1E__DISABLED   0x00 ///< CP1 unavailable at Port pin.                  
#define XBR0_CP1E__ENABLED    0x40 ///< CP1 routed to Port pin.                       
                                                                                      
#define XBR0_CP1AE__BMASK     0x80 ///< Comparator1 Asynchronous Output Enable        
#define XBR0_CP1AE__SHIFT     0x07 ///< Comparator1 Asynchronous Output Enable        
#define XBR0_CP1AE__DISABLED  0x00 ///< Asynchronous CP1 unavailable at Port pin.     
#define XBR0_CP1AE__ENABLED   0x80 ///< Asynchronous CP1 routed to Port pin.          
                                                                                      
//------------------------------------------------------------------------------
// XBR1 Enums (Port I/O Crossbar 1 @ 0xE2)
//------------------------------------------------------------------------------
#define XBR1_PCA0ME__FMASK                         0x07 ///< PCA Module I/O Enable                            
#define XBR1_PCA0ME__SHIFT                         0x00 ///< PCA Module I/O Enable                            
#define XBR1_PCA0ME__DISABLED                      0x00 ///< All PCA I/O unavailable at Port pins.            
#define XBR1_PCA0ME__CEX0                          0x01 ///< CEX0 routed to Port pin.                         
#define XBR1_PCA0ME__CEX0_CEX1                     0x02 ///< CEX0, CEX1 routed to Port pins.                  
#define XBR1_PCA0ME__CEX0_CEX1_CEX2                0x03 ///< CEX0, CEX1, CEX2 routed to Port pins.            
#define XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3           0x04 ///< CEX0, CEX1, CEX2 CEX3 routed to Port pins.       
#define XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4      0x05 ///< CEX0, CEX1, CEX2, CEX3, CEX4 routed to Port pins.
#define XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4_CEX5 0x06 ///< CEX0, CEX1, CEX2, CEX3, CEX4, CEX5 routed to Port
                                                        ///< pins.                                            
                                                                                                              
#define XBR1_ECIE__BMASK                           0x08 ///< PCA0 External Counter Input Enable               
#define XBR1_ECIE__SHIFT                           0x03 ///< PCA0 External Counter Input Enable               
#define XBR1_ECIE__DISABLED                        0x00 ///< ECI unavailable at Port pin.                     
#define XBR1_ECIE__ENABLED                         0x08 ///< ECI routed to Port pin.                          
                                                                                                              
#define XBR1_T0E__BMASK                            0x10 ///< T0 Enable                                        
#define XBR1_T0E__SHIFT                            0x04 ///< T0 Enable                                        
#define XBR1_T0E__DISABLED                         0x00 ///< T0 unavailable at Port pin.                      
#define XBR1_T0E__ENABLED                          0x10 ///< T0 routed to Port pin.                           
                                                                                                              
#define XBR1_T1E__BMASK                            0x20 ///< T1 Enable                                        
#define XBR1_T1E__SHIFT                            0x05 ///< T1 Enable                                        
#define XBR1_T1E__DISABLED                         0x00 ///< T1 unavailable at Port pin.                      
#define XBR1_T1E__ENABLED                          0x20 ///< T1 routed to Port pin.                           
                                                                                                              
#define XBR1_SPI1E__BMASK                          0x40 ///< SPI1 I/O Enable                                  
#define XBR1_SPI1E__SHIFT                          0x06 ///< SPI1 I/O Enable                                  
#define XBR1_SPI1E__DISABLED                       0x00 ///< SPI1 I/O unavailable at Port pin.                
#define XBR1_SPI1E__ENABLED                        0x40 ///< SPI1 I/O routed to Port pins.                    
                                                                                                              
//------------------------------------------------------------------------------
// XBR2 Enums (Port I/O Crossbar 2 @ 0xE3)
//------------------------------------------------------------------------------
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
// PCA0CPH5 Enums (PCA Channel 5 Capture Module High Byte @ 0xD3)
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
// PCA0CPL5 Enums (PCA Channel 5 Capture Module Low Byte @ 0xD2)
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
// PCA0CPM5 Enums (PCA Channel 5 Capture/Compare Mode @ 0xCE)
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
// PCA0PWM Enums (PCA PWM Configuration @ 0xDF)
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
// PC0CMP0H Enums (PC0 Comparator 0 High Byte @ 0xE3)
//------------------------------------------------------------------------------
#define PC0CMP0H_PC0CMP0H__FMASK 0xFF ///< PC0 Comparator 0 High Byte
#define PC0CMP0H_PC0CMP0H__SHIFT 0x00 ///< PC0 Comparator 0 High Byte
                                                                     
//------------------------------------------------------------------------------
// PC0CMP0L Enums (PC0 Comparator 0 Low Byte @ 0xE1)
//------------------------------------------------------------------------------
#define PC0CMP0L_PC0CMP0L__FMASK 0xFF ///< PC0 Comparator 0 Low Byte
#define PC0CMP0L_PC0CMP0L__SHIFT 0x00 ///< PC0 Comparator 0 Low Byte
                                                                    
//------------------------------------------------------------------------------
// PC0CMP0M Enums (PC0 Comparator 0 Middle Byte @ 0xE2)
//------------------------------------------------------------------------------
#define PC0CMP0M_PC0CMP0M__FMASK 0xFF ///< PC0 Comparator 0 Middle Byte
#define PC0CMP0M_PC0CMP0M__SHIFT 0x00 ///< PC0 Comparator 0 Middle Byte
                                                                       
//------------------------------------------------------------------------------
// PC0CMP1H Enums (PC0 Comparator 1 High Byte @ 0xF3)
//------------------------------------------------------------------------------
#define PC0CMP1H_PC0CMP1H__FMASK 0xFF ///< PC0 Comparator 1 High Byte
#define PC0CMP1H_PC0CMP1H__SHIFT 0x00 ///< PC0 Comparator 1 High Byte
                                                                     
//------------------------------------------------------------------------------
// PC0CMP1L Enums (PC0 Comparator 1 Low Byte @ 0xF1)
//------------------------------------------------------------------------------
#define PC0CMP1L_PC0CMP1L__FMASK 0xFF ///< PC0 Comparator 1 Low Byte
#define PC0CMP1L_PC0CMP1L__SHIFT 0x00 ///< PC0 Comparator 1 Low Byte
                                                                    
//------------------------------------------------------------------------------
// PC0CMP1M Enums (PC0 Comparator 1 Middle Byte @ 0xF2)
//------------------------------------------------------------------------------
#define PC0CMP1M_PC0CMP1M__FMASK 0xFF ///< PC0 Comparator 1 Middle Byte
#define PC0CMP1M_PC0CMP1M__SHIFT 0x00 ///< PC0 Comparator 1 Middle Byte
                                                                       
//------------------------------------------------------------------------------
// PC0CTR0H Enums (PC0 Counter 0 High Byte @ 0xDC)
//------------------------------------------------------------------------------
#define PC0CTR0H_PC0CTR0H__FMASK 0xFF ///< PC0 Counter 0 High Byte
#define PC0CTR0H_PC0CTR0H__SHIFT 0x00 ///< PC0 Counter 0 High Byte
                                                                  
//------------------------------------------------------------------------------
// PC0CTR0L Enums (PC0 Counter 0 Low Byte @ 0xDA)
//------------------------------------------------------------------------------
#define PC0CTR0L_PC0CTR0L__FMASK 0xFF ///< PC0 Counter 0 Low Byte
#define PC0CTR0L_PC0CTR0L__SHIFT 0x00 ///< PC0 Counter 0 Low Byte
                                                                 
//------------------------------------------------------------------------------
// PC0CTR0M Enums (PC0 Counter 0 Middle Byte @ 0xDB)
//------------------------------------------------------------------------------
#define PC0CTR0M_PC0CTR0M__FMASK 0xFF ///< PC0 Counter 0 Middle Byte
#define PC0CTR0M_PC0CTR0M__SHIFT 0x00 ///< PC0 Counter 0 Middle Byte
                                                                    
//------------------------------------------------------------------------------
// PC0CTR1H Enums (PC0 Counter 1 High Byte @ 0xDF)
//------------------------------------------------------------------------------
#define PC0CTR1H_PC0CTR1H__FMASK 0xFF ///< PC0 Counter 1 High Byte
#define PC0CTR1H_PC0CTR1H__SHIFT 0x00 ///< PC0 Counter 1 High Byte
                                                                  
//------------------------------------------------------------------------------
// PC0CTR1L Enums (PC0 Counter 1 Low Byte @ 0xDD)
//------------------------------------------------------------------------------
#define PC0CTR1L_PC0CTR1L__FMASK 0xFF ///< PC0 Counter 1 Low Byte
#define PC0CTR1L_PC0CTR1L__SHIFT 0x00 ///< PC0 Counter 1 Low Byte
                                                                 
//------------------------------------------------------------------------------
// PC0CTR1M Enums (PC0 Counter 1 Middle Byte @ 0xDE)
//------------------------------------------------------------------------------
#define PC0CTR1M_PC0CTR1M__FMASK 0xFF ///< PC0 Counter 1 Middle Byte
#define PC0CTR1M_PC0CTR1M__SHIFT 0x00 ///< PC0 Counter 1 Middle Byte
                                                                    
//------------------------------------------------------------------------------
// PC0DCH Enums (PC0 Debounce Configuration High Byte @ 0xFA)
//------------------------------------------------------------------------------
#define PC0DCH_PC0DCH__FMASK 0xFF ///< Debounce High Byte
#define PC0DCH_PC0DCH__SHIFT 0x00 ///< Debounce High Byte
                                                         
//------------------------------------------------------------------------------
// PC0DCL Enums (PC0 Debounce Configuration Low Byte @ 0xF9)
//------------------------------------------------------------------------------
#define PC0DCL_PC0DCL__FMASK 0xFF ///< Debounce Low Byte
#define PC0DCL_PC0DCL__SHIFT 0x00 ///< Debounce Low Byte
                                                        
//------------------------------------------------------------------------------
// PC0HIST Enums (PC0 Direction History @ 0xF4)
//------------------------------------------------------------------------------
#define PC0HIST_DIRHIST0__BMASK 0x01 ///< PC0 Direction History Slot 0                 
#define PC0HIST_DIRHIST0__SHIFT 0x00 ///< PC0 Direction History Slot 0                 
#define PC0HIST_DIRHIST0__CCW   0x00 ///< The recorded direction was counter clock-wise
#define PC0HIST_DIRHIST0__CW    0x01 ///< The recorded direction was clock-wise.       
                                                                                       
#define PC0HIST_DIRHIST1__BMASK 0x02 ///< PC0 Direction History Slot 1                 
#define PC0HIST_DIRHIST1__SHIFT 0x01 ///< PC0 Direction History Slot 1                 
#define PC0HIST_DIRHIST1__CCW   0x00 ///< The recorded direction was counter clock-wise
#define PC0HIST_DIRHIST1__CW    0x02 ///< The recorded direction was clock-wise.       
                                                                                       
#define PC0HIST_DIRHIST2__BMASK 0x04 ///< PC0 Direction History Slot 2                 
#define PC0HIST_DIRHIST2__SHIFT 0x02 ///< PC0 Direction History Slot 2                 
#define PC0HIST_DIRHIST2__CCW   0x00 ///< The recorded direction was counter clock-wise
#define PC0HIST_DIRHIST2__CW    0x04 ///< The recorded direction was clock-wise.       
                                                                                       
#define PC0HIST_DIRHIST3__BMASK 0x08 ///< PC0 Direction History Slot 3                 
#define PC0HIST_DIRHIST3__SHIFT 0x03 ///< PC0 Direction History Slot 3                 
#define PC0HIST_DIRHIST3__CCW   0x00 ///< The recorded direction was counter clock-wise
#define PC0HIST_DIRHIST3__CW    0x08 ///< The recorded direction was clock-wise.       
                                                                                       
#define PC0HIST_DIRHIST4__BMASK 0x10 ///< PC0 Direction History Slot 4                 
#define PC0HIST_DIRHIST4__SHIFT 0x04 ///< PC0 Direction History Slot 4                 
#define PC0HIST_DIRHIST4__CCW   0x00 ///< The recorded direction was counter clock-wise
#define PC0HIST_DIRHIST4__CW    0x10 ///< The recorded direction was clock-wise.       
                                                                                       
#define PC0HIST_DIRHIST5__BMASK 0x20 ///< PC0 Direction History Slot 5                 
#define PC0HIST_DIRHIST5__SHIFT 0x05 ///< PC0 Direction History Slot 5                 
#define PC0HIST_DIRHIST5__CCW   0x00 ///< The recorded direction was counter clock-wise
#define PC0HIST_DIRHIST5__CW    0x20 ///< The recorded direction was clock-wise.       
                                                                                       
#define PC0HIST_DIRHIST6__BMASK 0x40 ///< PC0 Direction History Slot 6                 
#define PC0HIST_DIRHIST6__SHIFT 0x06 ///< PC0 Direction History Slot 6                 
#define PC0HIST_DIRHIST6__CCW   0x00 ///< The recorded direction was counter clock-wise
#define PC0HIST_DIRHIST6__CW    0x40 ///< The recorded direction was clock-wise.       
                                                                                       
#define PC0HIST_DIRHIST7__BMASK 0x80 ///< PC0 Direction History Slot 7                 
#define PC0HIST_DIRHIST7__SHIFT 0x07 ///< PC0 Direction History Slot 7                 
#define PC0HIST_DIRHIST7__CCW   0x00 ///< The recorded direction was counter clock-wise
#define PC0HIST_DIRHIST7__CW    0x80 ///< The recorded direction was clock-wise.       
                                                                                       
//------------------------------------------------------------------------------
// PC0INT0 Enums (PC0 Interrupt 0 @ 0xFB)
//------------------------------------------------------------------------------
#define PC0INT0_DIRCHGEN__BMASK    0x01 ///< Direction Change Interrupt/Wake-up Source Enable  
#define PC0INT0_DIRCHGEN__SHIFT    0x00 ///< Direction Change Interrupt/Wake-up Source Enable  
#define PC0INT0_DIRCHGEN__DISABLED 0x00 ///< Disable a direction change as an interrupt or     
                                        ///< wake-up source.                                   
#define PC0INT0_DIRCHGEN__ENABLED  0x01 ///< Enable a direction change as an interrupt or wake-
                                        ///< up source.                                        
                                                                                               
#define PC0INT0_DIRCHGF__BMASK     0x02 ///< Direction Change Flag                             
#define PC0INT0_DIRCHGF__SHIFT     0x01 ///< Direction Change Flag                             
#define PC0INT0_DIRCHGF__NOT_SET   0x00 ///< No change in direction was detected.              
#define PC0INT0_DIRCHGF__SET       0x02 ///< A change in direction was detected.               
                                                                                               
#define PC0INT0_OVREN__BMASK       0x04 ///< Counter Overflow Interrupt/Wake-up Source Enable  
#define PC0INT0_OVREN__SHIFT       0x02 ///< Counter Overflow Interrupt/Wake-up Source Enable  
#define PC0INT0_OVREN__DISABLED    0x00 ///< Disable a counter overflow as an interrupt or     
                                        ///< wake-up source.                                   
#define PC0INT0_OVREN__ENABLED     0x04 ///< Enable a counter overflow as an interrupt or wake-
                                        ///< up source.                                        
                                                                                               
#define PC0INT0_OVRF__BMASK        0x08 ///< Counter Overflow Flag                             
#define PC0INT0_OVRF__SHIFT        0x03 ///< Counter Overflow Flag                             
#define PC0INT0_OVRF__SET          0x08 ///< One of the counters has overflowed.               
                                                                                               
#define PC0INT0_CMP0EN__BMASK      0x10 ///< Comparator 0 Interrupt/Wake-up Source Enable      
#define PC0INT0_CMP0EN__SHIFT      0x04 ///< Comparator 0 Interrupt/Wake-up Source Enable      
#define PC0INT0_CMP0EN__DISABLED   0x00 ///< Disable the counter 0 comparator as an interrupt  
                                        ///< or wake-up source.                                
#define PC0INT0_CMP0EN__ENABLED    0x10 ///< Enable the counter 0 comparator as an interrupt or
                                        ///< wake-up source.                                   
                                                                                               
#define PC0INT0_CMP0F__BMASK       0x20 ///< Comparator 0 Flag                                 
#define PC0INT0_CMP0F__SHIFT       0x05 ///< Comparator 0 Flag                                 
#define PC0INT0_CMP0F__NOT_SET     0x00 ///< Counter 0 did not match counter 0 comparator      
                                        ///< value.                                            
#define PC0INT0_CMP0F__SET         0x20 ///< Counter 0 matched counter 0 comparator value.     
                                                                                               
#define PC0INT0_CMP1EN__BMASK      0x40 ///< Comparator 1 Interrupt/Wake-up Source Enable      
#define PC0INT0_CMP1EN__SHIFT      0x06 ///< Comparator 1 Interrupt/Wake-up Source Enable      
#define PC0INT0_CMP1EN__DISABLED   0x00 ///< Disable the counter 1 comparator as an interrupt  
                                        ///< or wake-up source.                                
#define PC0INT0_CMP1EN__ENABLED    0x40 ///< Enable the counter 1 comparator as an interrupt or
                                        ///< wake-up source.                                   
                                                                                               
#define PC0INT0_CMP1F__BMASK       0x80 ///< Comparator 1 Flag                                 
#define PC0INT0_CMP1F__SHIFT       0x07 ///< Comparator 1 Flag                                 
#define PC0INT0_CMP1F__NOT_SET     0x00 ///< Counter 1 did not match counter 1 comparator      
                                        ///< value.                                            
#define PC0INT0_CMP1F__SET         0x80 ///< Counter 1 matched counter 1 comparator value.     
                                                                                               
//------------------------------------------------------------------------------
// PC0INT1 Enums (PC0 Interrupt 1 @ 0xFC)
//------------------------------------------------------------------------------
#define PC0INT1_TRANSEN__BMASK      0x01 ///< Transition Interrupt/Wake-up Source Enable        
#define PC0INT1_TRANSEN__SHIFT      0x00 ///< Transition Interrupt/Wake-up Source Enable        
#define PC0INT1_TRANSEN__DISABLED   0x00 ///< Disable transitions on PC0 or PC1 as an interrupt 
                                         ///< or wake-up source.                                
#define PC0INT1_TRANSEN__ENABLED    0x01 ///< Enable transitions on PC0 or PC1 as an interrupt  
                                         ///< or wake-up source.                                
                                                                                                
#define PC0INT1_TRANSF__BMASK       0x02 ///< Transition Flag                                   
#define PC0INT1_TRANSF__SHIFT       0x01 ///< Transition Flag                                   
#define PC0INT1_TRANSF__NOT_SET     0x00 ///< No transitions detected.                          
#define PC0INT1_TRANSF__SET         0x02 ///< A transition was detected on the PC0 or PC1       
                                         ///< inputs.                                           
                                                                                                
#define PC0INT1_ERROREN__BMASK      0x04 ///< Quadrature Error Interrupt/Wake-up Source Enable  
#define PC0INT1_ERROREN__SHIFT      0x02 ///< Quadrature Error Interrupt/Wake-up Source Enable  
#define PC0INT1_ERROREN__DISABLED   0x00 ///< Disable a quadrature error as an interrupt or     
                                         ///< wake-up source.                                   
#define PC0INT1_ERROREN__ENABLED    0x04 ///< Enable a quadrature error as an interrupt or wake-
                                         ///< up source.                                        
                                                                                                
#define PC0INT1_ERRORF__BMASK       0x08 ///< Quadrature Error Flag                             
#define PC0INT1_ERRORF__SHIFT       0x03 ///< Quadrature Error Flag                             
#define PC0INT1_ERRORF__NOT_SET     0x00 ///< No quadrature error detected.                     
#define PC0INT1_ERRORF__SET         0x08 ///< Quadrature error detected.                        
                                                                                                
#define PC0INT1_FLTRSTPEN__BMASK    0x10 ///< Flutter Stop Interrupt/Wake-up Source Enable      
#define PC0INT1_FLTRSTPEN__SHIFT    0x04 ///< Flutter Stop Interrupt/Wake-up Source Enable      
#define PC0INT1_FLTRSTPEN__DISABLED 0x00 ///< Disable the end of a flutter event as an interrupt
                                         ///< or wake-up source.                                
#define PC0INT1_FLTRSTPEN__ENABLED  0x10 ///< Enable the end of a flutter event as an interrupt 
                                         ///< or wake-up source.                                
                                                                                                
#define PC0INT1_FLTRSTPF__BMASK     0x20 ///< Flutter Stop Flag                                 
#define PC0INT1_FLTRSTPF__SHIFT     0x05 ///< Flutter Stop Flag                                 
#define PC0INT1_FLTRSTPF__NOT_SET   0x00 ///< The end of a flutter event was not detected.      
#define PC0INT1_FLTRSTPF__SET       0x20 ///< The end of a flutter event was detected.          
                                                                                                
#define PC0INT1_FLTRSTREN__BMASK    0x40 ///< Flutter Start Interrupt/Wake-up Source Enable     
#define PC0INT1_FLTRSTREN__SHIFT    0x06 ///< Flutter Start Interrupt/Wake-up Source Enable     
#define PC0INT1_FLTRSTREN__DISABLED 0x00 ///< Disable the start of a flutter event as an        
                                         ///< interrupt or wake-up source.                      
#define PC0INT1_FLTRSTREN__ENABLED  0x40 ///< Enable the start of a flutter event as an         
                                         ///< interrupt or wake-up source.                      
                                                                                                
#define PC0INT1_FLTRSTRF__BMASK     0x80 ///< Flutter Start Flag                                
#define PC0INT1_FLTRSTRF__SHIFT     0x07 ///< Flutter Start Flag                                
#define PC0INT1_FLTRSTRF__NOT_SET   0x00 ///< The start of a flutter event was not detected.    
#define PC0INT1_FLTRSTRF__SET       0x80 ///< The start of a flutter event was detected.        
                                                                                                
//------------------------------------------------------------------------------
// PC0MD Enums (PC0 Mode Configuration @ 0xD9)
//------------------------------------------------------------------------------
#define PC0MD_DUALSTCH__BMASK    0x02 ///< Flutter Dual Mode Switch Enable                  
#define PC0MD_DUALSTCH__SHIFT    0x01 ///< Flutter Dual Mode Switch Enable                  
#define PC0MD_DUALSTCH__DISABLED 0x00 ///< Disable dual mode switching. The counter remains 
                                      ///< in quadrature mode during flutter.               
#define PC0MD_DUALSTCH__ENABLED  0x02 ///< Enable dual mode switching. The counter switches 
                                      ///< to dual mode during flutter.                     
                                                                                            
#define PC0MD_FLTRSTOP__BMASK    0x04 ///< Flutter Counter Stop Enable                      
#define PC0MD_FLTRSTOP__SHIFT    0x02 ///< Flutter Counter Stop Enable                      
#define PC0MD_FLTRSTOP__DISABLED 0x00 ///< Disable counter stops on flutter.                
#define PC0MD_FLTRSTOP__ENABLED  0x04 ///< Stop the counter when flutter occurs.            
                                                                                            
#define PC0MD_PCRATE__FMASK      0x30 ///< PC Sample Rate                                   
#define PC0MD_PCRATE__SHIFT      0x04 ///< PC Sample Rate                                   
#define PC0MD_PCRATE__250_US     0x00 ///< Set the pulse counter sample rate to 250 us.     
#define PC0MD_PCRATE__500_US     0x10 ///< Set the pulse counter sample rate to 500 us.     
#define PC0MD_PCRATE__1_MS       0x20 ///< Set the pulse counter sample rate to 1 ms.       
#define PC0MD_PCRATE__2_MS       0x30 ///< Set the pulse counter sample rate to 2 ms.       
                                                                                            
#define PC0MD_PCMODE__FMASK      0xC0 ///< Counter Mode                                     
#define PC0MD_PCMODE__SHIFT      0x06 ///< Counter Mode                                     
#define PC0MD_PCMODE__DISABLED   0x00 ///< Disable the pulse counter.                       
#define PC0MD_PCMODE__SINGLE     0x40 ///< Select single counter mode for the pulse counter.
#define PC0MD_PCMODE__DUAL       0x80 ///< Select dual counter mode for the pulse counter.  
#define PC0MD_PCMODE__QUADRATURE 0xC0 ///< Select quadrature counter mode for the pulse     
                                      ///< counter.                                         
                                                                                            
//------------------------------------------------------------------------------
// PC0PCF Enums (PC0 Pull-Up Configuration @ 0xD7)
//------------------------------------------------------------------------------
#define PC0PCF_DUTY__FMASK        0x03 ///< Pull-Up Resistor Duty Cycle Multiplier            
#define PC0PCF_DUTY__SHIFT        0x00 ///< Pull-Up Resistor Duty Cycle Multiplier            
#define PC0PCF_DUTY__25_PERCENT   0x00 ///< Set the pull-up resistor duty cycle to 1/4 (25%). 
#define PC0PCF_DUTY__37P5_PERCENT 0x01 ///< Set the pull-up resistor duty cycle to 3/8        
                                       ///< (37.5%).                                          
#define PC0PCF_DUTY__50_PERCENT   0x02 ///< Set the pull-up resistor duty cycle to 1/2 (50%). 
#define PC0PCF_DUTY__75_PERCENT   0x03 ///< Set the pull-up resistor duty cycle to 3/4 (75%). 
                                                                                              
#define PC0PCF_RES__FMASK         0x1C ///< Pull-Up Resistor Value                            
#define PC0PCF_RES__SHIFT         0x02 ///< Pull-Up Resistor Value                            
#define PC0PCF_RES__DISABLED      0x00 ///< Disable the pull-up resistors.                    
#define PC0PCF_RES__1_UA          0x04 ///< Set the pull-up resistor current to 1 uA.         
#define PC0PCF_RES__4_UA          0x08 ///< Set the pull-up resistor current to 4 uA.         
#define PC0PCF_RES__16_UA         0x0C ///< Set the pull-up resistor current to 16 uA.        
#define PC0PCF_RES__64_UA         0x10 ///< Set the pull-up resistor current to 64 uA.        
#define PC0PCF_RES__256_UA        0x14 ///< Set the pull-up resistor current to 256 uA.       
#define PC0PCF_RES__1_MA          0x18 ///< Set the pull-up resistor current to 1 mA.         
#define PC0PCF_RES__4_MA          0x1C ///< Set the pull-up resistor current to 4 mA.         
                                                                                              
#define PC0PCF_CALPORT__BMASK     0x20 ///< Calibration Port                                  
#define PC0PCF_CALPORT__SHIFT     0x05 ///< Calibration Port                                  
#define PC0PCF_CALPORT__CHANNEL_0 0x00 ///< Perform a pull-up calibration on channel 0 only   
                                       ///< (PC0).                                            
#define PC0PCF_CALPORT__CHANNEL_1 0x20 ///< Perform a pull-up calibration on channel 1 only   
                                       ///< (PC1).                                            
                                                                                              
#define PC0PCF_CALRES__BMASK      0x40 ///< Calibration Result                                
#define PC0PCF_CALRES__SHIFT      0x06 ///< Calibration Result                                
#define PC0PCF_CALRES__FAILED     0x00 ///< The pull-up calibration operation failed.         
#define PC0PCF_CALRES__PASSED     0x40 ///< The pull-up calibration operation passed.         
                                                                                              
#define PC0PCF_PUCAL__BMASK       0x80 ///< Pull-Up Driver Calibration                        
#define PC0PCF_PUCAL__SHIFT       0x07 ///< Pull-Up Driver Calibration                        
#define PC0PCF_PUCAL__NOT_SET     0x00 ///< The pull-up calibration is complete or not in     
                                       ///< progress.                                         
#define PC0PCF_PUCAL__SET         0x80 ///< Start a pull-up calibration operation. The        
                                       ///< calibration operation determines the lowest usable
                                       ///< pull-up strength.                                 
                                                                                              
//------------------------------------------------------------------------------
// PC0STAT Enums (PC0 Status @ 0xC1)
//------------------------------------------------------------------------------
#define PC0STAT_PC0__BMASK            0x01 ///< Current PC0 Integrator Output                     
#define PC0STAT_PC0__SHIFT            0x00 ///< Current PC0 Integrator Output                     
#define PC0STAT_PC0__LOW              0x00 ///< The PC0 integrator output is currently low.       
#define PC0STAT_PC0__HIGH             0x01 ///< The PC0 integrator output is currently high.      
                                                                                                  
#define PC0STAT_PC1__BMASK            0x02 ///< Current PC1 Integrator Output                     
#define PC0STAT_PC1__SHIFT            0x01 ///< Current PC1 Integrator Output                     
#define PC0STAT_PC1__LOW              0x00 ///< The PC1 integrator output is currently low.       
#define PC0STAT_PC1__HIGH             0x02 ///< The PC1 integrator output is currently high.      
                                                                                                  
#define PC0STAT_PC0PREV__BMASK        0x04 ///< Previous PC0 Integrator Output                    
#define PC0STAT_PC0PREV__SHIFT        0x02 ///< Previous PC0 Integrator Output                    
#define PC0STAT_PC0PREV__LOW          0x00 ///< The PC0 integrator output was previously low.     
#define PC0STAT_PC0PREV__HIGH         0x04 ///< The PC0 integrator output was previously high.    
                                                                                                  
#define PC0STAT_PC1PREV__BMASK        0x08 ///< Previous PC1 Integrator Output                    
#define PC0STAT_PC1PREV__SHIFT        0x03 ///< Previous PC1 Integrator Output                    
#define PC0STAT_PC1PREV__LOW          0x00 ///< The PC1 integrator output was previously low.     
#define PC0STAT_PC1PREV__HIGH         0x08 ///< The PC1 integrator output was previously high.    
                                                                                                  
#define PC0STAT_STATE__FMASK          0x30 ///< PC0 State                                         
#define PC0STAT_STATE__SHIFT          0x04 ///< PC0 State                                         
#define PC0STAT_STATE__LL             0x00 ///< The state of the pulse counter is LL (PC1 low, PC0
                                           ///< low).                                             
#define PC0STAT_STATE__LH             0x10 ///< The state of the pulse counter is LH (PC1 low, PC0
                                           ///< high).                                            
#define PC0STAT_STATE__HL             0x20 ///< The state of the pulse counter is HL (PC1 high,   
                                           ///< PC0 low).                                         
#define PC0STAT_STATE__HH             0x30 ///< The state of the pulse counter is HH (PC1 high,   
                                           ///< PC0 high).                                        
                                                                                                  
#define PC0STAT_DIRECTION__BMASK      0x40 ///< Direction                                         
#define PC0STAT_DIRECTION__SHIFT      0x06 ///< Direction                                         
#define PC0STAT_DIRECTION__CCW        0x00 ///< The current direction is counter clock-wise: LL-  
                                           ///< LH-HH-HL.                                         
#define PC0STAT_DIRECTION__CW         0x40 ///< The current direction is clock-wise: LL-HL-HH-LH. 
                                                                                                  
#define PC0STAT_FLUTTER__BMASK        0x80 ///< Flutter                                           
#define PC0STAT_FLUTTER__SHIFT        0x07 ///< Flutter                                           
#define PC0STAT_FLUTTER__NOT_DETECTED 0x00 ///< No flutter detected.                              
#define PC0STAT_FLUTTER__DETECTED     0x80 ///< Flutter detected.                                 
                                                                                                  
//------------------------------------------------------------------------------
// PC0TH Enums (PC0 Threshold Configuration @ 0xE4)
//------------------------------------------------------------------------------
#define PC0TH_RDVALID__BMASK         0x01 ///< Read Valid                                        
#define PC0TH_RDVALID__SHIFT         0x00 ///< Read Valid                                        
#define PC0TH_RDVALID__NOT_SET       0x00 ///< The last read was invalid.                        
#define PC0TH_RDVALID__SET           0x01 ///< The last read was valid.                          
                                                                                                 
#define PC0TH_PUP__BMASK             0x04 ///< Force Pull-Up Enable                              
#define PC0TH_PUP__SHIFT             0x02 ///< Force Pull-Up Enable                              
#define PC0TH_PUP__FORCE_DISABLED    0x00 ///< Channel 0 (PC0) and channel 1 (PC1) pull-ups are  
                                          ///< not forced on continuously.                       
#define PC0TH_PUP__FORCE_ENABLED     0x04 ///< Channel 0 (PC0) and channel 1 (PC1) pull-ups are  
                                          ///< forced on continuously.                           
                                                                                                 
#define PC0TH_PDOWN__BMASK           0x08 ///< Force Pull-Down Enable                            
#define PC0TH_PDOWN__SHIFT           0x03 ///< Force Pull-Down Enable                            
#define PC0TH_PDOWN__FORCE_DISABLED  0x00 ///< Channel 0 (PC0) and channel 1 (PC1) pull-downs are
                                          ///< not forced on continuously.                       
#define PC0TH_PDOWN__FORCE_ENABLED   0x08 ///< Channel 0 (PC0) and channel 1 (PC1) pull-downs are
                                          ///< forced on continuously, grounding the PC0 and PC1 
                                          ///< inputs.                                           
                                                                                                 
#define PC0TH_PCTHRESLO__FMASK       0x30 ///< Input Comparator VIL Threshold                    
#define PC0TH_PCTHRESLO__SHIFT       0x04 ///< Input Comparator VIL Threshold                    
#define PC0TH_PCTHRESLO__42_PERCENT  0x00 ///< Set the input comparator VIL threshold to 42% of  
                                          ///< VIO.                                              
#define PC0TH_PCTHRESLO__46_PERCENT  0x10 ///< Set the input comparator VIL threshold to 46% of  
                                          ///< VIO.                                              
#define PC0TH_PCTHRESLO__34_PERCENT  0x20 ///< Set the input comparator VIL threshold to 34% of  
                                          ///< VIO.                                              
#define PC0TH_PCTHRESLO__38_PERCENT  0x30 ///< Set the input comparator VIL threshold to 38% of  
                                          ///< VIO.                                              
                                                                                                 
#define PC0TH_PCTTHRESHI__FMASK      0xC0 ///< Input Comparator VIH Threshold                    
#define PC0TH_PCTTHRESHI__SHIFT      0x06 ///< Input Comparator VIH Threshold                    
#define PC0TH_PCTTHRESHI__59_PERCENT 0x00 ///< Set the input comparator VIH threshold to 59% of  
                                          ///< VIO.                                              
#define PC0TH_PCTTHRESHI__63_PERCENT 0x40 ///< Set the input comparator VIH threshold to 63% of  
                                          ///< VIO.                                              
#define PC0TH_PCTTHRESHI__50_PERCENT 0x80 ///< Set the input comparator VIH threshold to 50% of  
                                          ///< VIO.                                              
#define PC0TH_PCTTHRESHI__55_PERCENT 0xC0 ///< Set the input comparator VIH threshold to 55% of  
                                          ///< VIO.                                              
                                                                                                 
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
#define PCON_GF1__NOT_SET 0x00 ///< The GF0 flag is not set. Clear the GF0 flag.    
#define PCON_GF1__SET     0x08 ///< The GF0 flag is set. Set the GF0 flag.          
                                                                                    
#define PCON_GF2__BMASK   0x10 ///< General Purpose Flag 2                          
#define PCON_GF2__SHIFT   0x04 ///< General Purpose Flag 2                          
#define PCON_GF2__NOT_SET 0x00 ///< The GF0 flag is not set. Clear the GF0 flag.    
#define PCON_GF2__SET     0x10 ///< The GF0 flag is set. Set the GF0 flag.          
                                                                                    
#define PCON_GF3__BMASK   0x20 ///< General Purpose Flag 3                          
#define PCON_GF3__SHIFT   0x05 ///< General Purpose Flag 3                          
#define PCON_GF3__NOT_SET 0x00 ///< The GF0 flag is not set. Clear the GF0 flag.    
#define PCON_GF3__SET     0x20 ///< The GF0 flag is set. Set the GF0 flag.          
                                                                                    
#define PCON_GF4__BMASK   0x40 ///< General Purpose Flag 4                          
#define PCON_GF4__SHIFT   0x06 ///< General Purpose Flag 4                          
#define PCON_GF4__NOT_SET 0x00 ///< The GF0 flag is not set. Clear the GF0 flag.    
#define PCON_GF4__SET     0x40 ///< The GF0 flag is set. Set the GF0 flag.          
                                                                                    
#define PCON_GF5__BMASK   0x80 ///< General Purpose Flag 5                          
#define PCON_GF5__SHIFT   0x07 ///< General Purpose Flag 5                          
#define PCON_GF5__NOT_SET 0x00 ///< The GF0 flag is not set. Clear the GF0 flag.    
#define PCON_GF5__SET     0x80 ///< The GF0 flag is set. Set the GF0 flag.          
                                                                                    
//------------------------------------------------------------------------------
// PMU0CF Enums (Power Management Unit Configuration @ 0xB5)
//------------------------------------------------------------------------------
#define PMU0CF_CPT0WK__BMASK    0x01 ///< Comparator0 Wake-up Source Enable and Flag        
#define PMU0CF_CPT0WK__SHIFT    0x00 ///< Comparator0 Wake-up Source Enable and Flag        
#define PMU0CF_CPT0WK__NOT_SET  0x00 ///< Comparator 0 rising edge did not cause the last   
                                     ///< wake-up.                                          
#define PMU0CF_CPT0WK__SET      0x01 ///< Comparator 0 rising edge caused the last wake-up. 
                                                                                            
#define PMU0CF_PMATWK__BMASK    0x02 ///< Port Match Wake-up Source Enable and Flag         
#define PMU0CF_PMATWK__SHIFT    0x01 ///< Port Match Wake-up Source Enable and Flag         
#define PMU0CF_PMATWK__NOT_SET  0x00 ///< A Port Match event did not cause the last wake-up.
#define PMU0CF_PMATWK__SET      0x02 ///< A Port Match event caused the last wake-up.       
                                                                                            
#define PMU0CF_RTCAWK__BMASK    0x04 ///< RTC Alarm Wake-up Source Enable and Flag          
#define PMU0CF_RTCAWK__SHIFT    0x02 ///< RTC Alarm Wake-up Source Enable and Flag          
#define PMU0CF_RTCAWK__NOT_SET  0x00 ///< A RTC Alarm did not cause the last wake-up.       
#define PMU0CF_RTCAWK__SET      0x04 ///< A RTC Alarm caused the last wake-up.              
                                                                                            
#define PMU0CF_RTCFWK__BMASK    0x08 ///< RTC Oscillator Fail Wake-up Source Enable and Flag
#define PMU0CF_RTCFWK__SHIFT    0x03 ///< RTC Oscillator Fail Wake-up Source Enable and Flag
#define PMU0CF_RTCFWK__NOT_SET  0x00 ///< An RTC oscillator fail event did not cause the    
                                     ///< last wake-up.                                     
#define PMU0CF_RTCFWK__SET      0x08 ///< An RTC oscillator fail event caused the last wake-
                                     ///< up.                                               
                                                                                            
#define PMU0CF_RSTWK__BMASK     0x10 ///< Reset Pin Wake-up Flag                            
#define PMU0CF_RSTWK__SHIFT     0x04 ///< Reset Pin Wake-up Flag                            
#define PMU0CF_RSTWK__NOT_SET   0x00 ///< No glitch detected on /RST.                       
#define PMU0CF_RSTWK__SET       0x10 ///< Glitch detected on /RST.                          
                                                                                            
#define PMU0CF_CLEAR__BMASK     0x20 ///< Wake-up Flag Clear                                
#define PMU0CF_CLEAR__SHIFT     0x05 ///< Wake-up Flag Clear                                
#define PMU0CF_CLEAR__ALL_FLAGS 0x20 ///< Clear all wake-up flags.                          
                                                                                            
#define PMU0CF_SUSPEND__BMASK   0x40 ///< Suspend Mode Select                               
#define PMU0CF_SUSPEND__SHIFT   0x06 ///< Suspend Mode Select                               
#define PMU0CF_SUSPEND__NORMAL  0x00 ///< Suspend mode not activated.                       
#define PMU0CF_SUSPEND__START   0x40 ///< Place the device in Suspend mode.                 
                                                                                            
#define PMU0CF_SLEEP__BMASK     0x80 ///< Sleep Mode Select                                 
#define PMU0CF_SLEEP__SHIFT     0x07 ///< Sleep Mode Select                                 
#define PMU0CF_SLEEP__NORMAL    0x00 ///< Sleep mode not activated.                         
#define PMU0CF_SLEEP__START     0x80 ///< Place the device in Sleep mode.                   
                                                                                            
//------------------------------------------------------------------------------
// PMU0FL Enums (Power Management Unit Flag @ 0xB6)
//------------------------------------------------------------------------------
#define PMU0FL_PC0WK__BMASK    0x01 ///< Pulse Counter Wake-up Source Enable and Flag      
#define PMU0FL_PC0WK__SHIFT    0x00 ///< Pulse Counter Wake-up Source Enable and Flag      
#define PMU0FL_PC0WK__NOT_SET  0x00 ///< A Pulse Counter event did not cause the last wake-
                                    ///< up.                                               
#define PMU0FL_PC0WK__SET      0x01 ///< A Pulse Counter event caused the last wake-up.    
                                                                                           
#define PMU0FL_BATMWK__BMASK   0x04 ///< VBAT Monitor Wake-up Source Enable and Flag       
#define PMU0FL_BATMWK__SHIFT   0x02 ///< VBAT Monitor Wake-up Source Enable and Flag       
#define PMU0FL_BATMWK__NOT_SET 0x00 ///< A VBAT Monitor event did not cause the last wake- 
                                    ///< up.                                               
#define PMU0FL_BATMWK__SET     0x04 ///< A VBAT Monitor event caused the last wake-up.     
                                                                                           
//------------------------------------------------------------------------------
// PMU0MD Enums (Power Management Unit Mode @ 0xB3)
//------------------------------------------------------------------------------
#define PMU0MD_MONDIS__BMASK    0x20 ///< POR Supply Monitor Disable         
#define PMU0MD_MONDIS__SHIFT    0x05 ///< POR Supply Monitor Disable         
#define PMU0MD_MONDIS__ENABLED  0x00 ///< Enable the POR supply monitor.     
#define PMU0MD_MONDIS__DISABLED 0x20 ///< Disable the POR supply monitor.    
                                                                             
#define PMU0MD_WAKEOE__BMASK    0x40 ///< Wakeup Request Output Enable       
#define PMU0MD_WAKEOE__SHIFT    0x06 ///< Wakeup Request Output Enable       
#define PMU0MD_WAKEOE__DISABLED 0x00 ///< Disable the wake-up request signal.
#define PMU0MD_WAKEOE__ENABLED  0x40 ///< Enable the wake-up request signal. 
                                                                             
#define PMU0MD_RTCOE__BMASK     0x80 ///< Buffered RTC Output Enable         
#define PMU0MD_RTCOE__SHIFT     0x07 ///< Buffered RTC Output Enable         
#define PMU0MD_RTCOE__DISABLED  0x00 ///< Disable the buffered RTC output.   
#define PMU0MD_RTCOE__ENABLED   0x80 ///< Enable the buffered RTC output.    
                                                                             
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
// P0DRV Enums (Port 0 Drive Strength @ 0xA4)
//------------------------------------------------------------------------------
#define P0DRV_B0__BMASK      0x01 ///< Port 0 Bit 0 Drive Strength                
#define P0DRV_B0__SHIFT      0x00 ///< Port 0 Bit 0 Drive Strength                
#define P0DRV_B0__LOW_DRIVE  0x00 ///< P0.0 output has low output drive strength. 
#define P0DRV_B0__HIGH_DRIVE 0x01 ///< P0.0 output has high output drive strength.
                                                                                  
#define P0DRV_B1__BMASK      0x02 ///< Port 0 Bit 1 Drive Strength                
#define P0DRV_B1__SHIFT      0x01 ///< Port 0 Bit 1 Drive Strength                
#define P0DRV_B1__LOW_DRIVE  0x00 ///< P0.1 output has low output drive strength. 
#define P0DRV_B1__HIGH_DRIVE 0x02 ///< P0.1 output has high output drive strength.
                                                                                  
#define P0DRV_B2__BMASK      0x04 ///< Port 0 Bit 2 Drive Strength                
#define P0DRV_B2__SHIFT      0x02 ///< Port 0 Bit 2 Drive Strength                
#define P0DRV_B2__LOW_DRIVE  0x00 ///< P0.2 output has low output drive strength. 
#define P0DRV_B2__HIGH_DRIVE 0x04 ///< P0.2 output has high output drive strength.
                                                                                  
#define P0DRV_B3__BMASK      0x08 ///< Port 0 Bit 3 Drive Strength                
#define P0DRV_B3__SHIFT      0x03 ///< Port 0 Bit 3 Drive Strength                
#define P0DRV_B3__LOW_DRIVE  0x00 ///< P0.3 output has low output drive strength. 
#define P0DRV_B3__HIGH_DRIVE 0x08 ///< P0.3 output has high output drive strength.
                                                                                  
#define P0DRV_B4__BMASK      0x10 ///< Port 0 Bit 4 Drive Strength                
#define P0DRV_B4__SHIFT      0x04 ///< Port 0 Bit 4 Drive Strength                
#define P0DRV_B4__LOW_DRIVE  0x00 ///< P0.4 output has low output drive strength. 
#define P0DRV_B4__HIGH_DRIVE 0x10 ///< P0.4 output has high output drive strength.
                                                                                  
#define P0DRV_B5__BMASK      0x20 ///< Port 0 Bit 5 Drive Strength                
#define P0DRV_B5__SHIFT      0x05 ///< Port 0 Bit 5 Drive Strength                
#define P0DRV_B5__LOW_DRIVE  0x00 ///< P0.5 output has low output drive strength. 
#define P0DRV_B5__HIGH_DRIVE 0x20 ///< P0.5 output has high output drive strength.
                                                                                  
#define P0DRV_B6__BMASK      0x40 ///< Port 0 Bit 6 Drive Strength                
#define P0DRV_B6__SHIFT      0x06 ///< Port 0 Bit 6 Drive Strength                
#define P0DRV_B6__LOW_DRIVE  0x00 ///< P0.6 output has low output drive strength. 
#define P0DRV_B6__HIGH_DRIVE 0x40 ///< P0.6 output has high output drive strength.
                                                                                  
#define P0DRV_B7__BMASK      0x80 ///< Port 0 Bit 7 Drive Strength                
#define P0DRV_B7__SHIFT      0x07 ///< Port 0 Bit 7 Drive Strength                
#define P0DRV_B7__LOW_DRIVE  0x00 ///< P0.7 output has low output drive strength. 
#define P0DRV_B7__HIGH_DRIVE 0x80 ///< P0.7 output has high output drive strength.
                                                                                  
//------------------------------------------------------------------------------
// P0MASK Enums (Port 0 Mask @ 0xC7)
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
// P0MAT Enums (Port 0 Match @ 0xD7)
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
// P1DRV Enums (Port 1 Drive Strength @ 0xA5)
//------------------------------------------------------------------------------
#define P1DRV_B0__BMASK      0x01 ///< Port 1 Bit 0 Drive Strength                
#define P1DRV_B0__SHIFT      0x00 ///< Port 1 Bit 0 Drive Strength                
#define P1DRV_B0__LOW_DRIVE  0x00 ///< P1.0 output has low output drive strength. 
#define P1DRV_B0__HIGH_DRIVE 0x01 ///< P1.0 output has high output drive strength.
                                                                                  
#define P1DRV_B1__BMASK      0x02 ///< Port 1 Bit 1 Drive Strength                
#define P1DRV_B1__SHIFT      0x01 ///< Port 1 Bit 1 Drive Strength                
#define P1DRV_B1__LOW_DRIVE  0x00 ///< P1.1 output has low output drive strength. 
#define P1DRV_B1__HIGH_DRIVE 0x02 ///< P1.1 output has high output drive strength.
                                                                                  
#define P1DRV_B2__BMASK      0x04 ///< Port 1 Bit 2 Drive Strength                
#define P1DRV_B2__SHIFT      0x02 ///< Port 1 Bit 2 Drive Strength                
#define P1DRV_B2__LOW_DRIVE  0x00 ///< P1.2 output has low output drive strength. 
#define P1DRV_B2__HIGH_DRIVE 0x04 ///< P1.2 output has high output drive strength.
                                                                                  
#define P1DRV_B3__BMASK      0x08 ///< Port 1 Bit 3 Drive Strength                
#define P1DRV_B3__SHIFT      0x03 ///< Port 1 Bit 3 Drive Strength                
#define P1DRV_B3__LOW_DRIVE  0x00 ///< P1.3 output has low output drive strength. 
#define P1DRV_B3__HIGH_DRIVE 0x08 ///< P1.3 output has high output drive strength.
                                                                                  
#define P1DRV_B4__BMASK      0x10 ///< Port 1 Bit 4 Drive Strength                
#define P1DRV_B4__SHIFT      0x04 ///< Port 1 Bit 4 Drive Strength                
#define P1DRV_B4__LOW_DRIVE  0x00 ///< P1.4 output has low output drive strength. 
#define P1DRV_B4__HIGH_DRIVE 0x10 ///< P1.4 output has high output drive strength.
                                                                                  
#define P1DRV_B5__BMASK      0x20 ///< Port 1 Bit 5 Drive Strength                
#define P1DRV_B5__SHIFT      0x05 ///< Port 1 Bit 5 Drive Strength                
#define P1DRV_B5__LOW_DRIVE  0x00 ///< P1.5 output has low output drive strength. 
#define P1DRV_B5__HIGH_DRIVE 0x20 ///< P1.5 output has high output drive strength.
                                                                                  
#define P1DRV_B6__BMASK      0x40 ///< Port 1 Bit 6 Drive Strength                
#define P1DRV_B6__SHIFT      0x06 ///< Port 1 Bit 6 Drive Strength                
#define P1DRV_B6__LOW_DRIVE  0x00 ///< P1.6 output has low output drive strength. 
#define P1DRV_B6__HIGH_DRIVE 0x40 ///< P1.6 output has high output drive strength.
                                                                                  
#define P1DRV_B7__BMASK      0x80 ///< Port 1 Bit 7 Drive Strength                
#define P1DRV_B7__SHIFT      0x07 ///< Port 1 Bit 7 Drive Strength                
#define P1DRV_B7__LOW_DRIVE  0x00 ///< P1.7 output has low output drive strength. 
#define P1DRV_B7__HIGH_DRIVE 0x80 ///< P1.7 output has high output drive strength.
                                                                                  
//------------------------------------------------------------------------------
// P1MASK Enums (Port 1 Mask @ 0xBF)
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
// P1MAT Enums (Port 1 Match @ 0xCF)
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
// P2DRV Enums (Port 2 Drive Strength @ 0xA6)
//------------------------------------------------------------------------------
#define P2DRV_B0__BMASK      0x01 ///< Port 2 Bit 0 Drive Strength                
#define P2DRV_B0__SHIFT      0x00 ///< Port 2 Bit 0 Drive Strength                
#define P2DRV_B0__LOW_DRIVE  0x00 ///< P2.0 output has low output drive strength. 
#define P2DRV_B0__HIGH_DRIVE 0x01 ///< P2.0 output has high output drive strength.
                                                                                  
#define P2DRV_B1__BMASK      0x02 ///< Port 2 Bit 1 Drive Strength                
#define P2DRV_B1__SHIFT      0x01 ///< Port 2 Bit 1 Drive Strength                
#define P2DRV_B1__LOW_DRIVE  0x00 ///< P2.1 output has low output drive strength. 
#define P2DRV_B1__HIGH_DRIVE 0x02 ///< P2.1 output has high output drive strength.
                                                                                  
#define P2DRV_B2__BMASK      0x04 ///< Port 2 Bit 2 Drive Strength                
#define P2DRV_B2__SHIFT      0x02 ///< Port 2 Bit 2 Drive Strength                
#define P2DRV_B2__LOW_DRIVE  0x00 ///< P2.2 output has low output drive strength. 
#define P2DRV_B2__HIGH_DRIVE 0x04 ///< P2.2 output has high output drive strength.
                                                                                  
#define P2DRV_B3__BMASK      0x08 ///< Port 2 Bit 3 Drive Strength                
#define P2DRV_B3__SHIFT      0x03 ///< Port 2 Bit 3 Drive Strength                
#define P2DRV_B3__LOW_DRIVE  0x00 ///< P2.3 output has low output drive strength. 
#define P2DRV_B3__HIGH_DRIVE 0x08 ///< P2.3 output has high output drive strength.
                                                                                  
#define P2DRV_B4__BMASK      0x10 ///< Port 2 Bit 4 Drive Strength                
#define P2DRV_B4__SHIFT      0x04 ///< Port 2 Bit 4 Drive Strength                
#define P2DRV_B4__LOW_DRIVE  0x00 ///< P2.4 output has low output drive strength. 
#define P2DRV_B4__HIGH_DRIVE 0x10 ///< P2.4 output has high output drive strength.
                                                                                  
#define P2DRV_B5__BMASK      0x20 ///< Port 2 Bit 5 Drive Strength                
#define P2DRV_B5__SHIFT      0x05 ///< Port 2 Bit 5 Drive Strength                
#define P2DRV_B5__LOW_DRIVE  0x00 ///< P2.5 output has low output drive strength. 
#define P2DRV_B5__HIGH_DRIVE 0x20 ///< P2.5 output has high output drive strength.
                                                                                  
#define P2DRV_B6__BMASK      0x40 ///< Port 2 Bit 6 Drive Strength                
#define P2DRV_B6__SHIFT      0x06 ///< Port 2 Bit 6 Drive Strength                
#define P2DRV_B6__LOW_DRIVE  0x00 ///< P2.6 output has low output drive strength. 
#define P2DRV_B6__HIGH_DRIVE 0x40 ///< P2.6 output has high output drive strength.
                                                                                  
#define P2DRV_B7__BMASK      0x80 ///< Port 2 Bit 7 Drive Strength                
#define P2DRV_B7__SHIFT      0x07 ///< Port 2 Bit 7 Drive Strength                
#define P2DRV_B7__LOW_DRIVE  0x00 ///< P2.7 output has low output drive strength. 
#define P2DRV_B7__HIGH_DRIVE 0x80 ///< P2.7 output has high output drive strength.
                                                                                  
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
// P3DRV Enums (Port 3 Drive Strength @ 0xA1)
//------------------------------------------------------------------------------
#define P3DRV_B0__BMASK      0x01 ///< Port 3 Bit 0 Drive Strength                
#define P3DRV_B0__SHIFT      0x00 ///< Port 3 Bit 0 Drive Strength                
#define P3DRV_B0__LOW_DRIVE  0x00 ///< P3.0 output has low output drive strength. 
#define P3DRV_B0__HIGH_DRIVE 0x01 ///< P3.0 output has high output drive strength.
                                                                                  
#define P3DRV_B1__BMASK      0x02 ///< Port 3 Bit 1 Drive Strength                
#define P3DRV_B1__SHIFT      0x01 ///< Port 3 Bit 1 Drive Strength                
#define P3DRV_B1__LOW_DRIVE  0x00 ///< P3.1 output has low output drive strength. 
#define P3DRV_B1__HIGH_DRIVE 0x02 ///< P3.1 output has high output drive strength.
                                                                                  
#define P3DRV_B2__BMASK      0x04 ///< Port 3 Bit 2 Drive Strength                
#define P3DRV_B2__SHIFT      0x02 ///< Port 3 Bit 2 Drive Strength                
#define P3DRV_B2__LOW_DRIVE  0x00 ///< P3.2 output has low output drive strength. 
#define P3DRV_B2__HIGH_DRIVE 0x04 ///< P3.2 output has high output drive strength.
                                                                                  
#define P3DRV_B3__BMASK      0x08 ///< Port 3 Bit 3 Drive Strength                
#define P3DRV_B3__SHIFT      0x03 ///< Port 3 Bit 3 Drive Strength                
#define P3DRV_B3__LOW_DRIVE  0x00 ///< P3.3 output has low output drive strength. 
#define P3DRV_B3__HIGH_DRIVE 0x08 ///< P3.3 output has high output drive strength.
                                                                                  
#define P3DRV_B4__BMASK      0x10 ///< Port 3 Bit 4 Drive Strength                
#define P3DRV_B4__SHIFT      0x04 ///< Port 3 Bit 4 Drive Strength                
#define P3DRV_B4__LOW_DRIVE  0x00 ///< P3.4 output has low output drive strength. 
#define P3DRV_B4__HIGH_DRIVE 0x10 ///< P3.4 output has high output drive strength.
                                                                                  
#define P3DRV_B5__BMASK      0x20 ///< Port 3 Bit 5 Drive Strength                
#define P3DRV_B5__SHIFT      0x05 ///< Port 3 Bit 5 Drive Strength                
#define P3DRV_B5__LOW_DRIVE  0x00 ///< P3.5 output has low output drive strength. 
#define P3DRV_B5__HIGH_DRIVE 0x20 ///< P3.5 output has high output drive strength.
                                                                                  
#define P3DRV_B6__BMASK      0x40 ///< Port 3 Bit 6 Drive Strength                
#define P3DRV_B6__SHIFT      0x06 ///< Port 3 Bit 6 Drive Strength                
#define P3DRV_B6__LOW_DRIVE  0x00 ///< P3.6 output has low output drive strength. 
#define P3DRV_B6__HIGH_DRIVE 0x40 ///< P3.6 output has high output drive strength.
                                                                                  
#define P3DRV_B7__BMASK      0x80 ///< Port 3 Bit 7 Drive Strength                
#define P3DRV_B7__SHIFT      0x07 ///< Port 3 Bit 7 Drive Strength                
#define P3DRV_B7__LOW_DRIVE  0x00 ///< P3.7 output has low output drive strength. 
#define P3DRV_B7__HIGH_DRIVE 0x80 ///< P3.7 output has high output drive strength.
                                                                                  
//------------------------------------------------------------------------------
// P3MDIN Enums (Port 3 Input Mode @ 0xF1)
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
// P3MDOUT Enums (Port 3 Output Mode @ 0xB1)
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
// P4 Enums (Port 4 Pin Latch @ 0xD9)
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
// P4DRV Enums (Port 4 Drive Strength @ 0xA2)
//------------------------------------------------------------------------------
#define P4DRV_B0__BMASK      0x01 ///< Port 4 Bit 0 Drive Strength                
#define P4DRV_B0__SHIFT      0x00 ///< Port 4 Bit 0 Drive Strength                
#define P4DRV_B0__LOW_DRIVE  0x00 ///< P4.0 output has low output drive strength. 
#define P4DRV_B0__HIGH_DRIVE 0x01 ///< P4.0 output has high output drive strength.
                                                                                  
#define P4DRV_B1__BMASK      0x02 ///< Port 4 Bit 1 Drive Strength                
#define P4DRV_B1__SHIFT      0x01 ///< Port 4 Bit 1 Drive Strength                
#define P4DRV_B1__LOW_DRIVE  0x00 ///< P4.1 output has low output drive strength. 
#define P4DRV_B1__HIGH_DRIVE 0x02 ///< P4.1 output has high output drive strength.
                                                                                  
#define P4DRV_B2__BMASK      0x04 ///< Port 4 Bit 2 Drive Strength                
#define P4DRV_B2__SHIFT      0x02 ///< Port 4 Bit 2 Drive Strength                
#define P4DRV_B2__LOW_DRIVE  0x00 ///< P4.2 output has low output drive strength. 
#define P4DRV_B2__HIGH_DRIVE 0x04 ///< P4.2 output has high output drive strength.
                                                                                  
#define P4DRV_B3__BMASK      0x08 ///< Port 4 Bit 3 Drive Strength                
#define P4DRV_B3__SHIFT      0x03 ///< Port 4 Bit 3 Drive Strength                
#define P4DRV_B3__LOW_DRIVE  0x00 ///< P4.3 output has low output drive strength. 
#define P4DRV_B3__HIGH_DRIVE 0x08 ///< P4.3 output has high output drive strength.
                                                                                  
#define P4DRV_B4__BMASK      0x10 ///< Port 4 Bit 4 Drive Strength                
#define P4DRV_B4__SHIFT      0x04 ///< Port 4 Bit 4 Drive Strength                
#define P4DRV_B4__LOW_DRIVE  0x00 ///< P4.4 output has low output drive strength. 
#define P4DRV_B4__HIGH_DRIVE 0x10 ///< P4.4 output has high output drive strength.
                                                                                  
#define P4DRV_B5__BMASK      0x20 ///< Port 4 Bit 5 Drive Strength                
#define P4DRV_B5__SHIFT      0x05 ///< Port 4 Bit 5 Drive Strength                
#define P4DRV_B5__LOW_DRIVE  0x00 ///< P4.5 output has low output drive strength. 
#define P4DRV_B5__HIGH_DRIVE 0x20 ///< P4.5 output has high output drive strength.
                                                                                  
#define P4DRV_B6__BMASK      0x40 ///< Port 4 Bit 6 Drive Strength                
#define P4DRV_B6__SHIFT      0x06 ///< Port 4 Bit 6 Drive Strength                
#define P4DRV_B6__LOW_DRIVE  0x00 ///< P4.6 output has low output drive strength. 
#define P4DRV_B6__HIGH_DRIVE 0x40 ///< P4.6 output has high output drive strength.
                                                                                  
#define P4DRV_B7__BMASK      0x80 ///< Port 4 Bit 7 Drive Strength                
#define P4DRV_B7__SHIFT      0x07 ///< Port 4 Bit 7 Drive Strength                
#define P4DRV_B7__LOW_DRIVE  0x00 ///< P4.7 output has low output drive strength. 
#define P4DRV_B7__HIGH_DRIVE 0x80 ///< P4.7 output has high output drive strength.
                                                                                  
//------------------------------------------------------------------------------
// P4MDIN Enums (Port 4 Input Mode @ 0xF2)
//------------------------------------------------------------------------------
#define P4MDIN_B0__BMASK   0x01 ///< Port 4 Bit 0 Input Mode                 
#define P4MDIN_B0__SHIFT   0x00 ///< Port 4 Bit 0 Input Mode                 
#define P4MDIN_B0__ANALOG  0x00 ///< P4.0 pin is configured for analog mode. 
#define P4MDIN_B0__DIGITAL 0x01 ///< P4.0 pin is configured for digital mode.
                                                                             
#define P4MDIN_B1__BMASK   0x02 ///< Port 4 Bit 1 Input Mode                 
#define P4MDIN_B1__SHIFT   0x01 ///< Port 4 Bit 1 Input Mode                 
#define P4MDIN_B1__ANALOG  0x00 ///< P4.1 pin is configured for analog mode. 
#define P4MDIN_B1__DIGITAL 0x02 ///< P4.1 pin is configured for digital mode.
                                                                             
#define P4MDIN_B2__BMASK   0x04 ///< Port 4 Bit 2 Input Mode                 
#define P4MDIN_B2__SHIFT   0x02 ///< Port 4 Bit 2 Input Mode                 
#define P4MDIN_B2__ANALOG  0x00 ///< P4.2 pin is configured for analog mode. 
#define P4MDIN_B2__DIGITAL 0x04 ///< P4.2 pin is configured for digital mode.
                                                                             
#define P4MDIN_B3__BMASK   0x08 ///< Port 4 Bit 3 Input Mode                 
#define P4MDIN_B3__SHIFT   0x03 ///< Port 4 Bit 3 Input Mode                 
#define P4MDIN_B3__ANALOG  0x00 ///< P4.3 pin is configured for analog mode. 
#define P4MDIN_B3__DIGITAL 0x08 ///< P4.3 pin is configured for digital mode.
                                                                             
#define P4MDIN_B4__BMASK   0x10 ///< Port 4 Bit 4 Input Mode                 
#define P4MDIN_B4__SHIFT   0x04 ///< Port 4 Bit 4 Input Mode                 
#define P4MDIN_B4__ANALOG  0x00 ///< P4.4 pin is configured for analog mode. 
#define P4MDIN_B4__DIGITAL 0x10 ///< P4.4 pin is configured for digital mode.
                                                                             
#define P4MDIN_B5__BMASK   0x20 ///< Port 4 Bit 5 Input Mode                 
#define P4MDIN_B5__SHIFT   0x05 ///< Port 4 Bit 5 Input Mode                 
#define P4MDIN_B5__ANALOG  0x00 ///< P4.5 pin is configured for analog mode. 
#define P4MDIN_B5__DIGITAL 0x20 ///< P4.5 pin is configured for digital mode.
                                                                             
#define P4MDIN_B6__BMASK   0x40 ///< Port 4 Bit 6 Input Mode                 
#define P4MDIN_B6__SHIFT   0x06 ///< Port 4 Bit 6 Input Mode                 
#define P4MDIN_B6__ANALOG  0x00 ///< P4.6 pin is configured for analog mode. 
#define P4MDIN_B6__DIGITAL 0x40 ///< P4.6 pin is configured for digital mode.
                                                                             
#define P4MDIN_B7__BMASK   0x80 ///< Port 4 Bit 7 Input Mode                 
#define P4MDIN_B7__SHIFT   0x07 ///< Port 4 Bit 7 Input Mode                 
#define P4MDIN_B7__ANALOG  0x00 ///< P4.7 pin is configured for analog mode. 
#define P4MDIN_B7__DIGITAL 0x80 ///< P4.7 pin is configured for digital mode.
                                                                             
//------------------------------------------------------------------------------
// P4MDOUT Enums (Port 4 Output Mode @ 0xF9)
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
// P5 Enums (Port 5 Pin Latch @ 0xDA)
//------------------------------------------------------------------------------
#define P5_B0__BMASK 0x01 ///< Port 5 Bit 0 Latch                            
#define P5_B0__SHIFT 0x00 ///< Port 5 Bit 0 Latch                            
#define P5_B0__LOW   0x00 ///< P5.0 is low. Set P5.0 to drive low.           
#define P5_B0__HIGH  0x01 ///< P5.0 is high. Set P5.0 to drive or float high.
                                                                             
#define P5_B1__BMASK 0x02 ///< Port 5 Bit 1 Latch                            
#define P5_B1__SHIFT 0x01 ///< Port 5 Bit 1 Latch                            
#define P5_B1__LOW   0x00 ///< P5.1 is low. Set P5.1 to drive low.           
#define P5_B1__HIGH  0x02 ///< P5.1 is high. Set P5.1 to drive or float high.
                                                                             
#define P5_B2__BMASK 0x04 ///< Port 5 Bit 2 Latch                            
#define P5_B2__SHIFT 0x02 ///< Port 5 Bit 2 Latch                            
#define P5_B2__LOW   0x00 ///< P5.2 is low. Set P5.2 to drive low.           
#define P5_B2__HIGH  0x04 ///< P5.2 is high. Set P5.2 to drive or float high.
                                                                             
#define P5_B3__BMASK 0x08 ///< Port 5 Bit 3 Latch                            
#define P5_B3__SHIFT 0x03 ///< Port 5 Bit 3 Latch                            
#define P5_B3__LOW   0x00 ///< P5.3 is low. Set P5.3 to drive low.           
#define P5_B3__HIGH  0x08 ///< P5.3 is high. Set P5.3 to drive or float high.
                                                                             
#define P5_B4__BMASK 0x10 ///< Port 5 Bit 4 Latch                            
#define P5_B4__SHIFT 0x04 ///< Port 5 Bit 4 Latch                            
#define P5_B4__LOW   0x00 ///< P5.4 is low. Set P5.4 to drive low.           
#define P5_B4__HIGH  0x10 ///< P5.4 is high. Set P5.4 to drive or float high.
                                                                             
#define P5_B5__BMASK 0x20 ///< Port 5 Bit 5 Latch                            
#define P5_B5__SHIFT 0x05 ///< Port 5 Bit 5 Latch                            
#define P5_B5__LOW   0x00 ///< P5.5 is low. Set P5.5 to drive low.           
#define P5_B5__HIGH  0x20 ///< P5.5 is high. Set P5.5 to drive or float high.
                                                                             
#define P5_B6__BMASK 0x40 ///< Port 5 Bit 6 Latch                            
#define P5_B6__SHIFT 0x06 ///< Port 5 Bit 6 Latch                            
#define P5_B6__LOW   0x00 ///< P5.6 is low. Set P5.6 to drive low.           
#define P5_B6__HIGH  0x40 ///< P5.6 is high. Set P5.6 to drive or float high.
                                                                             
#define P5_B7__BMASK 0x80 ///< Port 5 Bit 7 Latch                            
#define P5_B7__SHIFT 0x07 ///< Port 5 Bit 7 Latch                            
#define P5_B7__LOW   0x00 ///< P5.7 is low. Set P5.7 to drive low.           
#define P5_B7__HIGH  0x80 ///< P5.7 is high. Set P5.7 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P5DRV Enums (Port 5 Drive Strength @ 0xA3)
//------------------------------------------------------------------------------
#define P5DRV_B0__BMASK      0x01 ///< Port 5 Bit 0 Drive Strength                
#define P5DRV_B0__SHIFT      0x00 ///< Port 5 Bit 0 Drive Strength                
#define P5DRV_B0__LOW_DRIVE  0x00 ///< P5.0 output has low output drive strength. 
#define P5DRV_B0__HIGH_DRIVE 0x01 ///< P5.0 output has high output drive strength.
                                                                                  
#define P5DRV_B1__BMASK      0x02 ///< Port 5 Bit 1 Drive Strength                
#define P5DRV_B1__SHIFT      0x01 ///< Port 5 Bit 1 Drive Strength                
#define P5DRV_B1__LOW_DRIVE  0x00 ///< P5.1 output has low output drive strength. 
#define P5DRV_B1__HIGH_DRIVE 0x02 ///< P5.1 output has high output drive strength.
                                                                                  
#define P5DRV_B2__BMASK      0x04 ///< Port 5 Bit 2 Drive Strength                
#define P5DRV_B2__SHIFT      0x02 ///< Port 5 Bit 2 Drive Strength                
#define P5DRV_B2__LOW_DRIVE  0x00 ///< P5.2 output has low output drive strength. 
#define P5DRV_B2__HIGH_DRIVE 0x04 ///< P5.2 output has high output drive strength.
                                                                                  
#define P5DRV_B3__BMASK      0x08 ///< Port 5 Bit 3 Drive Strength                
#define P5DRV_B3__SHIFT      0x03 ///< Port 5 Bit 3 Drive Strength                
#define P5DRV_B3__LOW_DRIVE  0x00 ///< P5.3 output has low output drive strength. 
#define P5DRV_B3__HIGH_DRIVE 0x08 ///< P5.3 output has high output drive strength.
                                                                                  
#define P5DRV_B4__BMASK      0x10 ///< Port 5 Bit 4 Drive Strength                
#define P5DRV_B4__SHIFT      0x04 ///< Port 5 Bit 4 Drive Strength                
#define P5DRV_B4__LOW_DRIVE  0x00 ///< P5.4 output has low output drive strength. 
#define P5DRV_B4__HIGH_DRIVE 0x10 ///< P5.4 output has high output drive strength.
                                                                                  
#define P5DRV_B5__BMASK      0x20 ///< Port 5 Bit 5 Drive Strength                
#define P5DRV_B5__SHIFT      0x05 ///< Port 5 Bit 5 Drive Strength                
#define P5DRV_B5__LOW_DRIVE  0x00 ///< P5.5 output has low output drive strength. 
#define P5DRV_B5__HIGH_DRIVE 0x20 ///< P5.5 output has high output drive strength.
                                                                                  
#define P5DRV_B6__BMASK      0x40 ///< Port 5 Bit 6 Drive Strength                
#define P5DRV_B6__SHIFT      0x06 ///< Port 5 Bit 6 Drive Strength                
#define P5DRV_B6__LOW_DRIVE  0x00 ///< P5.6 output has low output drive strength. 
#define P5DRV_B6__HIGH_DRIVE 0x40 ///< P5.6 output has high output drive strength.
                                                                                  
#define P5DRV_B7__BMASK      0x80 ///< Port 5 Bit 7 Drive Strength                
#define P5DRV_B7__SHIFT      0x07 ///< Port 5 Bit 7 Drive Strength                
#define P5DRV_B7__LOW_DRIVE  0x00 ///< P5.7 output has low output drive strength. 
#define P5DRV_B7__HIGH_DRIVE 0x80 ///< P5.7 output has high output drive strength.
                                                                                  
//------------------------------------------------------------------------------
// P5MDIN Enums (Port 5 Input Mode @ 0xF3)
//------------------------------------------------------------------------------
#define P5MDIN_B0__BMASK   0x01 ///< Port 5 Bit 0 Input Mode                 
#define P5MDIN_B0__SHIFT   0x00 ///< Port 5 Bit 0 Input Mode                 
#define P5MDIN_B0__ANALOG  0x00 ///< P5.0 pin is configured for analog mode. 
#define P5MDIN_B0__DIGITAL 0x01 ///< P5.0 pin is configured for digital mode.
                                                                             
#define P5MDIN_B1__BMASK   0x02 ///< Port 5 Bit 1 Input Mode                 
#define P5MDIN_B1__SHIFT   0x01 ///< Port 5 Bit 1 Input Mode                 
#define P5MDIN_B1__ANALOG  0x00 ///< P5.1 pin is configured for analog mode. 
#define P5MDIN_B1__DIGITAL 0x02 ///< P5.1 pin is configured for digital mode.
                                                                             
#define P5MDIN_B2__BMASK   0x04 ///< Port 5 Bit 2 Input Mode                 
#define P5MDIN_B2__SHIFT   0x02 ///< Port 5 Bit 2 Input Mode                 
#define P5MDIN_B2__ANALOG  0x00 ///< P5.2 pin is configured for analog mode. 
#define P5MDIN_B2__DIGITAL 0x04 ///< P5.2 pin is configured for digital mode.
                                                                             
#define P5MDIN_B3__BMASK   0x08 ///< Port 5 Bit 3 Input Mode                 
#define P5MDIN_B3__SHIFT   0x03 ///< Port 5 Bit 3 Input Mode                 
#define P5MDIN_B3__ANALOG  0x00 ///< P5.3 pin is configured for analog mode. 
#define P5MDIN_B3__DIGITAL 0x08 ///< P5.3 pin is configured for digital mode.
                                                                             
#define P5MDIN_B4__BMASK   0x10 ///< Port 5 Bit 4 Input Mode                 
#define P5MDIN_B4__SHIFT   0x04 ///< Port 5 Bit 4 Input Mode                 
#define P5MDIN_B4__ANALOG  0x00 ///< P5.4 pin is configured for analog mode. 
#define P5MDIN_B4__DIGITAL 0x10 ///< P5.4 pin is configured for digital mode.
                                                                             
#define P5MDIN_B5__BMASK   0x20 ///< Port 5 Bit 5 Input Mode                 
#define P5MDIN_B5__SHIFT   0x05 ///< Port 5 Bit 5 Input Mode                 
#define P5MDIN_B5__ANALOG  0x00 ///< P5.5 pin is configured for analog mode. 
#define P5MDIN_B5__DIGITAL 0x20 ///< P5.5 pin is configured for digital mode.
                                                                             
#define P5MDIN_B6__BMASK   0x40 ///< Port 5 Bit 6 Input Mode                 
#define P5MDIN_B6__SHIFT   0x06 ///< Port 5 Bit 6 Input Mode                 
#define P5MDIN_B6__ANALOG  0x00 ///< P5.6 pin is configured for analog mode. 
#define P5MDIN_B6__DIGITAL 0x40 ///< P5.6 pin is configured for digital mode.
                                                                             
#define P5MDIN_B7__BMASK   0x80 ///< Port 5 Bit 7 Input Mode                 
#define P5MDIN_B7__SHIFT   0x07 ///< Port 5 Bit 7 Input Mode                 
#define P5MDIN_B7__ANALOG  0x00 ///< P5.7 pin is configured for analog mode. 
#define P5MDIN_B7__DIGITAL 0x80 ///< P5.7 pin is configured for digital mode.
                                                                             
//------------------------------------------------------------------------------
// P5MDOUT Enums (Port 5 Output Mode @ 0xFA)
//------------------------------------------------------------------------------
#define P5MDOUT_B0__BMASK      0x01 ///< Port 5 Bit 0 Output Mode  
#define P5MDOUT_B0__SHIFT      0x00 ///< Port 5 Bit 0 Output Mode  
#define P5MDOUT_B0__OPEN_DRAIN 0x00 ///< P5.0 output is open-drain.
#define P5MDOUT_B0__PUSH_PULL  0x01 ///< P5.0 output is push-pull. 
                                                                   
#define P5MDOUT_B1__BMASK      0x02 ///< Port 5 Bit 1 Output Mode  
#define P5MDOUT_B1__SHIFT      0x01 ///< Port 5 Bit 1 Output Mode  
#define P5MDOUT_B1__OPEN_DRAIN 0x00 ///< P5.1 output is open-drain.
#define P5MDOUT_B1__PUSH_PULL  0x02 ///< P5.1 output is push-pull. 
                                                                   
#define P5MDOUT_B2__BMASK      0x04 ///< Port 5 Bit 2 Output Mode  
#define P5MDOUT_B2__SHIFT      0x02 ///< Port 5 Bit 2 Output Mode  
#define P5MDOUT_B2__OPEN_DRAIN 0x00 ///< P5.2 output is open-drain.
#define P5MDOUT_B2__PUSH_PULL  0x04 ///< P5.2 output is push-pull. 
                                                                   
#define P5MDOUT_B3__BMASK      0x08 ///< Port 5 Bit 3 Output Mode  
#define P5MDOUT_B3__SHIFT      0x03 ///< Port 5 Bit 3 Output Mode  
#define P5MDOUT_B3__OPEN_DRAIN 0x00 ///< P5.3 output is open-drain.
#define P5MDOUT_B3__PUSH_PULL  0x08 ///< P5.3 output is push-pull. 
                                                                   
#define P5MDOUT_B4__BMASK      0x10 ///< Port 5 Bit 4 Output Mode  
#define P5MDOUT_B4__SHIFT      0x04 ///< Port 5 Bit 4 Output Mode  
#define P5MDOUT_B4__OPEN_DRAIN 0x00 ///< P5.4 output is open-drain.
#define P5MDOUT_B4__PUSH_PULL  0x10 ///< P5.4 output is push-pull. 
                                                                   
#define P5MDOUT_B5__BMASK      0x20 ///< Port 5 Bit 5 Output Mode  
#define P5MDOUT_B5__SHIFT      0x05 ///< Port 5 Bit 5 Output Mode  
#define P5MDOUT_B5__OPEN_DRAIN 0x00 ///< P5.5 output is open-drain.
#define P5MDOUT_B5__PUSH_PULL  0x20 ///< P5.5 output is push-pull. 
                                                                   
#define P5MDOUT_B6__BMASK      0x40 ///< Port 5 Bit 6 Output Mode  
#define P5MDOUT_B6__SHIFT      0x06 ///< Port 5 Bit 6 Output Mode  
#define P5MDOUT_B6__OPEN_DRAIN 0x00 ///< P5.6 output is open-drain.
#define P5MDOUT_B6__PUSH_PULL  0x40 ///< P5.6 output is push-pull. 
                                                                   
#define P5MDOUT_B7__BMASK      0x80 ///< Port 5 Bit 7 Output Mode  
#define P5MDOUT_B7__SHIFT      0x07 ///< Port 5 Bit 7 Output Mode  
#define P5MDOUT_B7__OPEN_DRAIN 0x00 ///< P5.7 output is open-drain.
#define P5MDOUT_B7__PUSH_PULL  0x80 ///< P5.7 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// P6 Enums (Port 6 Pin Latch @ 0xDB)
//------------------------------------------------------------------------------
#define P6_B0__BMASK 0x01 ///< Port 6 Bit 0 Latch                            
#define P6_B0__SHIFT 0x00 ///< Port 6 Bit 0 Latch                            
#define P6_B0__LOW   0x00 ///< P6.0 is low. Set P6.0 to drive low.           
#define P6_B0__HIGH  0x01 ///< P6.0 is high. Set P6.0 to drive or float high.
                                                                             
#define P6_B1__BMASK 0x02 ///< Port 6 Bit 1 Latch                            
#define P6_B1__SHIFT 0x01 ///< Port 6 Bit 1 Latch                            
#define P6_B1__LOW   0x00 ///< P6.1 is low. Set P6.1 to drive low.           
#define P6_B1__HIGH  0x02 ///< P6.1 is high. Set P6.1 to drive or float high.
                                                                             
#define P6_B2__BMASK 0x04 ///< Port 6 Bit 2 Latch                            
#define P6_B2__SHIFT 0x02 ///< Port 6 Bit 2 Latch                            
#define P6_B2__LOW   0x00 ///< P6.2 is low. Set P6.2 to drive low.           
#define P6_B2__HIGH  0x04 ///< P6.2 is high. Set P6.2 to drive or float high.
                                                                             
#define P6_B3__BMASK 0x08 ///< Port 6 Bit 3 Latch                            
#define P6_B3__SHIFT 0x03 ///< Port 6 Bit 3 Latch                            
#define P6_B3__LOW   0x00 ///< P6.3 is low. Set P6.3 to drive low.           
#define P6_B3__HIGH  0x08 ///< P6.3 is high. Set P6.3 to drive or float high.
                                                                             
#define P6_B4__BMASK 0x10 ///< Port 6 Bit 4 Latch                            
#define P6_B4__SHIFT 0x04 ///< Port 6 Bit 4 Latch                            
#define P6_B4__LOW   0x00 ///< P6.4 is low. Set P6.4 to drive low.           
#define P6_B4__HIGH  0x10 ///< P6.4 is high. Set P6.4 to drive or float high.
                                                                             
#define P6_B5__BMASK 0x20 ///< Port 6 Bit 5 Latch                            
#define P6_B5__SHIFT 0x05 ///< Port 6 Bit 5 Latch                            
#define P6_B5__LOW   0x00 ///< P6.5 is low. Set P6.5 to drive low.           
#define P6_B5__HIGH  0x20 ///< P6.5 is high. Set P6.5 to drive or float high.
                                                                             
#define P6_B6__BMASK 0x40 ///< Port 6 Bit 6 Latch                            
#define P6_B6__SHIFT 0x06 ///< Port 6 Bit 6 Latch                            
#define P6_B6__LOW   0x00 ///< P6.6 is low. Set P6.6 to drive low.           
#define P6_B6__HIGH  0x40 ///< P6.6 is high. Set P6.6 to drive or float high.
                                                                             
#define P6_B7__BMASK 0x80 ///< Port 6 Bit 7 Latch                            
#define P6_B7__SHIFT 0x07 ///< Port 6 Bit 7 Latch                            
#define P6_B7__LOW   0x00 ///< P6.7 is low. Set P6.7 to drive low.           
#define P6_B7__HIGH  0x80 ///< P6.7 is high. Set P6.7 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P6DRV Enums (Port 6 Drive Strength @ 0xAA)
//------------------------------------------------------------------------------
#define P6DRV_B0__BMASK      0x01 ///< Port 6 Bit 0 Drive Strength                
#define P6DRV_B0__SHIFT      0x00 ///< Port 6 Bit 0 Drive Strength                
#define P6DRV_B0__LOW_DRIVE  0x00 ///< P6.0 output has low output drive strength. 
#define P6DRV_B0__HIGH_DRIVE 0x01 ///< P6.0 output has high output drive strength.
                                                                                  
#define P6DRV_B1__BMASK      0x02 ///< Port 6 Bit 1 Drive Strength                
#define P6DRV_B1__SHIFT      0x01 ///< Port 6 Bit 1 Drive Strength                
#define P6DRV_B1__LOW_DRIVE  0x00 ///< P6.1 output has low output drive strength. 
#define P6DRV_B1__HIGH_DRIVE 0x02 ///< P6.1 output has high output drive strength.
                                                                                  
#define P6DRV_B2__BMASK      0x04 ///< Port 6 Bit 2 Drive Strength                
#define P6DRV_B2__SHIFT      0x02 ///< Port 6 Bit 2 Drive Strength                
#define P6DRV_B2__LOW_DRIVE  0x00 ///< P6.2 output has low output drive strength. 
#define P6DRV_B2__HIGH_DRIVE 0x04 ///< P6.2 output has high output drive strength.
                                                                                  
#define P6DRV_B3__BMASK      0x08 ///< Port 6 Bit 3 Drive Strength                
#define P6DRV_B3__SHIFT      0x03 ///< Port 6 Bit 3 Drive Strength                
#define P6DRV_B3__LOW_DRIVE  0x00 ///< P6.3 output has low output drive strength. 
#define P6DRV_B3__HIGH_DRIVE 0x08 ///< P6.3 output has high output drive strength.
                                                                                  
#define P6DRV_B4__BMASK      0x10 ///< Port 6 Bit 4 Drive Strength                
#define P6DRV_B4__SHIFT      0x04 ///< Port 6 Bit 4 Drive Strength                
#define P6DRV_B4__LOW_DRIVE  0x00 ///< P6.4 output has low output drive strength. 
#define P6DRV_B4__HIGH_DRIVE 0x10 ///< P6.4 output has high output drive strength.
                                                                                  
#define P6DRV_B5__BMASK      0x20 ///< Port 6 Bit 5 Drive Strength                
#define P6DRV_B5__SHIFT      0x05 ///< Port 6 Bit 5 Drive Strength                
#define P6DRV_B5__LOW_DRIVE  0x00 ///< P6.5 output has low output drive strength. 
#define P6DRV_B5__HIGH_DRIVE 0x20 ///< P6.5 output has high output drive strength.
                                                                                  
#define P6DRV_B6__BMASK      0x40 ///< Port 6 Bit 6 Drive Strength                
#define P6DRV_B6__SHIFT      0x06 ///< Port 6 Bit 6 Drive Strength                
#define P6DRV_B6__LOW_DRIVE  0x00 ///< P6.6 output has low output drive strength. 
#define P6DRV_B6__HIGH_DRIVE 0x40 ///< P6.6 output has high output drive strength.
                                                                                  
#define P6DRV_B7__BMASK      0x80 ///< Port 6 Bit 7 Drive Strength                
#define P6DRV_B7__SHIFT      0x07 ///< Port 6 Bit 7 Drive Strength                
#define P6DRV_B7__LOW_DRIVE  0x00 ///< P6.7 output has low output drive strength. 
#define P6DRV_B7__HIGH_DRIVE 0x80 ///< P6.7 output has high output drive strength.
                                                                                  
//------------------------------------------------------------------------------
// P6MDIN Enums (Port 6 Input Mode @ 0xF4)
//------------------------------------------------------------------------------
#define P6MDIN_B0__BMASK   0x01 ///< Port 6 Bit 0 Input Mode                 
#define P6MDIN_B0__SHIFT   0x00 ///< Port 6 Bit 0 Input Mode                 
#define P6MDIN_B0__ANALOG  0x00 ///< P6.0 pin is configured for analog mode. 
#define P6MDIN_B0__DIGITAL 0x01 ///< P6.0 pin is configured for digital mode.
                                                                             
#define P6MDIN_B1__BMASK   0x02 ///< Port 6 Bit 1 Input Mode                 
#define P6MDIN_B1__SHIFT   0x01 ///< Port 6 Bit 1 Input Mode                 
#define P6MDIN_B1__ANALOG  0x00 ///< P6.1 pin is configured for analog mode. 
#define P6MDIN_B1__DIGITAL 0x02 ///< P6.1 pin is configured for digital mode.
                                                                             
#define P6MDIN_B2__BMASK   0x04 ///< Port 6 Bit 2 Input Mode                 
#define P6MDIN_B2__SHIFT   0x02 ///< Port 6 Bit 2 Input Mode                 
#define P6MDIN_B2__ANALOG  0x00 ///< P6.2 pin is configured for analog mode. 
#define P6MDIN_B2__DIGITAL 0x04 ///< P6.2 pin is configured for digital mode.
                                                                             
#define P6MDIN_B3__BMASK   0x08 ///< Port 6 Bit 3 Input Mode                 
#define P6MDIN_B3__SHIFT   0x03 ///< Port 6 Bit 3 Input Mode                 
#define P6MDIN_B3__ANALOG  0x00 ///< P6.3 pin is configured for analog mode. 
#define P6MDIN_B3__DIGITAL 0x08 ///< P6.3 pin is configured for digital mode.
                                                                             
#define P6MDIN_B4__BMASK   0x10 ///< Port 6 Bit 4 Input Mode                 
#define P6MDIN_B4__SHIFT   0x04 ///< Port 6 Bit 4 Input Mode                 
#define P6MDIN_B4__ANALOG  0x00 ///< P6.4 pin is configured for analog mode. 
#define P6MDIN_B4__DIGITAL 0x10 ///< P6.4 pin is configured for digital mode.
                                                                             
#define P6MDIN_B5__BMASK   0x20 ///< Port 6 Bit 5 Input Mode                 
#define P6MDIN_B5__SHIFT   0x05 ///< Port 6 Bit 5 Input Mode                 
#define P6MDIN_B5__ANALOG  0x00 ///< P6.5 pin is configured for analog mode. 
#define P6MDIN_B5__DIGITAL 0x20 ///< P6.5 pin is configured for digital mode.
                                                                             
#define P6MDIN_B6__BMASK   0x40 ///< Port 6 Bit 6 Input Mode                 
#define P6MDIN_B6__SHIFT   0x06 ///< Port 6 Bit 6 Input Mode                 
#define P6MDIN_B6__ANALOG  0x00 ///< P6.6 pin is configured for analog mode. 
#define P6MDIN_B6__DIGITAL 0x40 ///< P6.6 pin is configured for digital mode.
                                                                             
#define P6MDIN_B7__BMASK   0x80 ///< Port 6 Bit 7 Input Mode                 
#define P6MDIN_B7__SHIFT   0x07 ///< Port 6 Bit 7 Input Mode                 
#define P6MDIN_B7__ANALOG  0x00 ///< P6.7 pin is configured for analog mode. 
#define P6MDIN_B7__DIGITAL 0x80 ///< P6.7 pin is configured for digital mode.
                                                                             
//------------------------------------------------------------------------------
// P6MDOUT Enums (Port 6 Output Mode @ 0xFB)
//------------------------------------------------------------------------------
#define P6MDOUT_B0__BMASK      0x01 ///< Port 6 Bit 0 Output Mode  
#define P6MDOUT_B0__SHIFT      0x00 ///< Port 6 Bit 0 Output Mode  
#define P6MDOUT_B0__OPEN_DRAIN 0x00 ///< P6.0 output is open-drain.
#define P6MDOUT_B0__PUSH_PULL  0x01 ///< P6.0 output is push-pull. 
                                                                   
#define P6MDOUT_B1__BMASK      0x02 ///< Port 6 Bit 1 Output Mode  
#define P6MDOUT_B1__SHIFT      0x01 ///< Port 6 Bit 1 Output Mode  
#define P6MDOUT_B1__OPEN_DRAIN 0x00 ///< P6.1 output is open-drain.
#define P6MDOUT_B1__PUSH_PULL  0x02 ///< P6.1 output is push-pull. 
                                                                   
#define P6MDOUT_B2__BMASK      0x04 ///< Port 6 Bit 2 Output Mode  
#define P6MDOUT_B2__SHIFT      0x02 ///< Port 6 Bit 2 Output Mode  
#define P6MDOUT_B2__OPEN_DRAIN 0x00 ///< P6.2 output is open-drain.
#define P6MDOUT_B2__PUSH_PULL  0x04 ///< P6.2 output is push-pull. 
                                                                   
#define P6MDOUT_B3__BMASK      0x08 ///< Port 6 Bit 3 Output Mode  
#define P6MDOUT_B3__SHIFT      0x03 ///< Port 6 Bit 3 Output Mode  
#define P6MDOUT_B3__OPEN_DRAIN 0x00 ///< P6.3 output is open-drain.
#define P6MDOUT_B3__PUSH_PULL  0x08 ///< P6.3 output is push-pull. 
                                                                   
#define P6MDOUT_B4__BMASK      0x10 ///< Port 6 Bit 4 Output Mode  
#define P6MDOUT_B4__SHIFT      0x04 ///< Port 6 Bit 4 Output Mode  
#define P6MDOUT_B4__OPEN_DRAIN 0x00 ///< P6.4 output is open-drain.
#define P6MDOUT_B4__PUSH_PULL  0x10 ///< P6.4 output is push-pull. 
                                                                   
#define P6MDOUT_B5__BMASK      0x20 ///< Port 6 Bit 5 Output Mode  
#define P6MDOUT_B5__SHIFT      0x05 ///< Port 6 Bit 5 Output Mode  
#define P6MDOUT_B5__OPEN_DRAIN 0x00 ///< P6.5 output is open-drain.
#define P6MDOUT_B5__PUSH_PULL  0x20 ///< P6.5 output is push-pull. 
                                                                   
#define P6MDOUT_B6__BMASK      0x40 ///< Port 6 Bit 6 Output Mode  
#define P6MDOUT_B6__SHIFT      0x06 ///< Port 6 Bit 6 Output Mode  
#define P6MDOUT_B6__OPEN_DRAIN 0x00 ///< P6.6 output is open-drain.
#define P6MDOUT_B6__PUSH_PULL  0x40 ///< P6.6 output is push-pull. 
                                                                   
#define P6MDOUT_B7__BMASK      0x80 ///< Port 6 Bit 7 Output Mode  
#define P6MDOUT_B7__SHIFT      0x07 ///< Port 6 Bit 7 Output Mode  
#define P6MDOUT_B7__OPEN_DRAIN 0x00 ///< P6.7 output is open-drain.
#define P6MDOUT_B7__PUSH_PULL  0x80 ///< P6.7 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// P7 Enums (Port 7 Pin Latch @ 0xDC)
//------------------------------------------------------------------------------
#define P7_B0__BMASK 0x01 ///< Port 7 Bit 0 Latch                            
#define P7_B0__SHIFT 0x00 ///< Port 7 Bit 0 Latch                            
#define P7_B0__LOW   0x00 ///< P7.0 is low. Set P7.0 to drive low.           
#define P7_B0__HIGH  0x01 ///< P7.0 is high. Set P7.0 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P7DRV Enums (Port 7 Drive Strength @ 0xAB)
//------------------------------------------------------------------------------
#define P7DRV_B0__BMASK      0x01 ///< Port 7 Bit 0 Drive Strength                
#define P7DRV_B0__SHIFT      0x00 ///< Port 7 Bit 0 Drive Strength                
#define P7DRV_B0__LOW_DRIVE  0x00 ///< P7.0 output has low output drive strength. 
#define P7DRV_B0__HIGH_DRIVE 0x01 ///< P7.0 output has high output drive strength.
                                                                                  
//------------------------------------------------------------------------------
// P7MDOUT Enums (Port 7 Output Mode @ 0xFC)
//------------------------------------------------------------------------------
#define P7MDOUT_B0__BMASK      0x01 ///< Port 7 Bit 0 Output Mode  
#define P7MDOUT_B0__SHIFT      0x00 ///< Port 7 Bit 0 Output Mode  
#define P7MDOUT_B0__OPEN_DRAIN 0x00 ///< P7.0 output is open-drain.
#define P7MDOUT_B0__PUSH_PULL  0x01 ///< P7.0 output is push-pull. 
                                                                   
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
                                                                                                              
#define RSTSRC_RTC0RE__BMASK   0x80 ///< RTC Reset Enable and Flag                                            
#define RSTSRC_RTC0RE__SHIFT   0x07 ///< RTC Reset Enable and Flag                                            
#define RSTSRC_RTC0RE__NOT_SET 0x00 ///< A RTC alarm or oscillator fail reset did not                         
                                    ///< occur.                                                               
#define RSTSRC_RTC0RE__SET     0x80 ///< A RTC alarm or oscillator fail reset occurred.                       
                                                                                                              
//------------------------------------------------------------------------------
// ALARM0B0 Enums (RTC Alarm 0 Programmed Value 0 @ 0x08)
//------------------------------------------------------------------------------
#define ALARM0B0_ALARM0B0__FMASK 0xFF ///< RTC Alarm 0 Programmed Value 0
#define ALARM0B0_ALARM0B0__SHIFT 0x00 ///< RTC Alarm 0 Programmed Value 0
                                                                         
//------------------------------------------------------------------------------
// ALARM0B1 Enums (RTC Alarm 0 Programmed Value 1 @ 0x09)
//------------------------------------------------------------------------------
#define ALARM0B1_ALARM0B1__FMASK 0xFF ///< RTC Alarm 0 Programmed Value 1
#define ALARM0B1_ALARM0B1__SHIFT 0x00 ///< RTC Alarm 0 Programmed Value 1
                                                                         
//------------------------------------------------------------------------------
// ALARM0B2 Enums (RTC Alarm 0 Programmed Value 2 @ 0x0A)
//------------------------------------------------------------------------------
#define ALARM0B2_ALARM0B2__FMASK 0xFF ///< RTC Alarm 0 Programmed Value 2
#define ALARM0B2_ALARM0B2__SHIFT 0x00 ///< RTC Alarm 0 Programmed Value 2
                                                                         
//------------------------------------------------------------------------------
// ALARM0B3 Enums (RTC Alarm 0 Programmed Value 3 @ 0x0B)
//------------------------------------------------------------------------------
#define ALARM0B3_ALARM0B3__FMASK 0xFF ///< RTC Alarm 0 Programmed Value 3
#define ALARM0B3_ALARM0B3__SHIFT 0x00 ///< RTC Alarm 0 Programmed Value 3
                                                                         
//------------------------------------------------------------------------------
// ALARM1B0 Enums (RTC Alarm 1 Programmed Value 0 @ 0x0C)
//------------------------------------------------------------------------------
#define ALARM1B0_ALARM1B0__FMASK 0xFF ///< RTC Alarm 1 Programmed Value 0
#define ALARM1B0_ALARM1B0__SHIFT 0x00 ///< RTC Alarm 1 Programmed Value 0
                                                                         
//------------------------------------------------------------------------------
// ALARM1B1 Enums (RTC Alarm 1 Programmed Value 1 @ 0x0D)
//------------------------------------------------------------------------------
#define ALARM1B1_ALARM1B1__FMASK 0xFF ///< RTC Alarm 1 Programmed Value 1
#define ALARM1B1_ALARM1B1__SHIFT 0x00 ///< RTC Alarm 1 Programmed Value 1
                                                                         
//------------------------------------------------------------------------------
// ALARM1B2 Enums (RTC Alarm 1 Programmed Value 2 @ 0x0E)
//------------------------------------------------------------------------------
#define ALARM1B2_ALARM1B2__FMASK 0xFF ///< RTC Alarm 1 Programmed Value 2
#define ALARM1B2_ALARM1B2__SHIFT 0x00 ///< RTC Alarm 1 Programmed Value 2
                                                                         
//------------------------------------------------------------------------------
// ALARM1B3 Enums (RTC Alarm 1 Programmed Value 3 @ 0x0F)
//------------------------------------------------------------------------------
#define ALARM1B3_ALARM1B3__FMASK 0xFF ///< RTC Alarm 1 Programmed Value 3
#define ALARM1B3_ALARM1B3__SHIFT 0x00 ///< RTC Alarm 1 Programmed Value 3
                                                                         
//------------------------------------------------------------------------------
// ALARM2B0 Enums (RTC Alarm 2 Programmed Value 0 @ 0x10)
//------------------------------------------------------------------------------
#define ALARM2B0_ALARM2B0__FMASK 0xFF ///< RTC Alarm 2 Programmed Value 0
#define ALARM2B0_ALARM2B0__SHIFT 0x00 ///< RTC Alarm 2 Programmed Value 0
                                                                         
//------------------------------------------------------------------------------
// ALARM2B1 Enums (RTC Alarm 2 Programmed Value 1 @ 0x11)
//------------------------------------------------------------------------------
#define ALARM2B1_ALARM2B1__FMASK 0xFF ///< RTC Alarm 2 Programmed Value 1
#define ALARM2B1_ALARM2B1__SHIFT 0x00 ///< RTC Alarm 2 Programmed Value 1
                                                                         
//------------------------------------------------------------------------------
// ALARM2B2 Enums (RTC Alarm 2 Programmed Value 2 @ 0x12)
//------------------------------------------------------------------------------
#define ALARM2B2_ALARM2B2__FMASK 0xFF ///< RTC Alarm 2 Programmed Value 2
#define ALARM2B2_ALARM2B2__SHIFT 0x00 ///< RTC Alarm 2 Programmed Value 2
                                                                         
//------------------------------------------------------------------------------
// ALARM2B3 Enums (RTC Alarm 2 Programmed Value 3 @ 0x13)
//------------------------------------------------------------------------------
#define ALARM2B3_ALARM2B3__FMASK 0xFF ///< RTC Alarm 2 Programmed Value 3
#define ALARM2B3_ALARM2B3__SHIFT 0x00 ///< RTC Alarm 2 Programmed Value 3
                                                                         
//------------------------------------------------------------------------------
// CAPTURE0 Enums (RTC Timer Capture 0 @ 0x00)
//------------------------------------------------------------------------------
#define CAPTURE0_CAPTURE0__FMASK 0xFF ///< RTC Timer Capture 0
#define CAPTURE0_CAPTURE0__SHIFT 0x00 ///< RTC Timer Capture 0
                                                              
//------------------------------------------------------------------------------
// CAPTURE1 Enums (RTC Timer Capture 1 @ 0x01)
//------------------------------------------------------------------------------
#define CAPTURE1_CAPTURE1__FMASK 0xFF ///< RTC Timer Capture 1
#define CAPTURE1_CAPTURE1__SHIFT 0x00 ///< RTC Timer Capture 1
                                                              
//------------------------------------------------------------------------------
// CAPTURE2 Enums (RTC Timer Capture 2 @ 0x02)
//------------------------------------------------------------------------------
#define CAPTURE2_CAPTURE2__FMASK 0xFF ///< RTC Timer Capture 2
#define CAPTURE2_CAPTURE2__SHIFT 0x00 ///< RTC Timer Capture 2
                                                              
//------------------------------------------------------------------------------
// CAPTURE3 Enums (RTC Timer Capture 3 @ 0x03)
//------------------------------------------------------------------------------
#define CAPTURE3_CAPTURE3__FMASK 0xFF ///< RTC Timer Capture 3
#define CAPTURE3_CAPTURE3__SHIFT 0x00 ///< RTC Timer Capture 3
                                                              
//------------------------------------------------------------------------------
// RTC0ADR Enums (RTC Address @ 0xAC)
//------------------------------------------------------------------------------
#define RTC0ADR_ADDR__FMASK      0x1F ///< RTC Indirect Register Address                     
#define RTC0ADR_ADDR__SHIFT      0x00 ///< RTC Indirect Register Address                     
#define RTC0ADR_ADDR__CAPTURE0   0x00 ///< Select the CAPTURE0 register.                     
#define RTC0ADR_ADDR__CAPTURE1   0x01 ///< Select the CAPTURE1 register.                     
#define RTC0ADR_ADDR__CAPTURE2   0x02 ///< Select the CAPTURE2 register.                     
#define RTC0ADR_ADDR__CAPTURE3   0x03 ///< Select the CAPTURE3 register.                     
#define RTC0ADR_ADDR__RTC0CN     0x04 ///< Select the RTC0CN register.                       
#define RTC0ADR_ADDR__RTC0XCN    0x05 ///< Select the RTC0XCN register.                      
#define RTC0ADR_ADDR__RTC0XCF    0x06 ///< Select the RTC0XCF register.                      
#define RTC0ADR_ADDR__RTC0CF     0x07 ///< Select the RTC0CF register.                       
#define RTC0ADR_ADDR__ALARM1B0   0x0C ///< Select the Alarm 1 Byte 0 register.               
#define RTC0ADR_ADDR__ALARM1B1   0x0D ///< Select the Alarm 1 Byte 1 register.               
#define RTC0ADR_ADDR__ALARM1B2   0x0E ///< Select the Alarm 1 Byte 2 register.               
#define RTC0ADR_ADDR__ALARM1B3   0x0F ///< Select the Alarm 1 Byte 3 register.               
#define RTC0ADR_ADDR__ALARM2B0   0x10 ///< Select the Alarm 2 Byte 0 register.               
#define RTC0ADR_ADDR__ALARM2B1   0x11 ///< Select the Alarm 2 Byte 1 register.               
#define RTC0ADR_ADDR__ALARM2B2   0x12 ///< Select the Alarm 2 Byte 2 register.               
#define RTC0ADR_ADDR__ALARM2B3   0x13 ///< Select the Alarm 2 Byte 3 register.               
                                                                                             
#define RTC0ADR_AUTORD__BMASK    0x40 ///< RTC Interface Autoread Enable                     
#define RTC0ADR_AUTORD__SHIFT    0x06 ///< RTC Interface Autoread Enable                     
#define RTC0ADR_AUTORD__DISABLED 0x00 ///< Disable autoread. Firmware must write the BUSY bit
                                      ///< for each RTC indirect read operation.             
#define RTC0ADR_AUTORD__ENABLED  0x40 ///< Enable autoread. The next RTC indirect read       
                                      ///< operation is initiated when firmware reads the    
                                      ///< RTC0DAT register.                                 
                                                                                             
//------------------------------------------------------------------------------
// RTC0CF Enums (RTC Configuration @ 0x07)
//------------------------------------------------------------------------------
#define RTC0CF_ALRM0EN__BMASK    0x01 ///< Alarm 0 Enable                                 
#define RTC0CF_ALRM0EN__SHIFT    0x00 ///< Alarm 0 Enable                                 
#define RTC0CF_ALRM0EN__DISABLED 0x00 ///< Disable Alarm 0.                               
#define RTC0CF_ALRM0EN__ENABLED  0x01 ///< Enable Alarm 0.                                
                                                                                          
#define RTC0CF_ALRM1EN__BMASK    0x02 ///< Alarm 1 Enable                                 
#define RTC0CF_ALRM1EN__SHIFT    0x01 ///< Alarm 1 Enable                                 
#define RTC0CF_ALRM1EN__DISABLED 0x00 ///< Disable Alarm 1.                               
#define RTC0CF_ALRM1EN__ENABLED  0x02 ///< Enable Alarm 1.                                
                                                                                          
#define RTC0CF_ALRM2EN__BMASK    0x04 ///< Alarm 2 Enable                                 
#define RTC0CF_ALRM2EN__SHIFT    0x02 ///< Alarm 2 Enable                                 
#define RTC0CF_ALRM2EN__DISABLED 0x00 ///< Disable Alarm 2.                               
#define RTC0CF_ALRM2EN__ENABLED  0x04 ///< Enable Alarm 2.                                
                                                                                          
#define RTC0CF_AUTORST__BMASK    0x08 ///< Auto Reset Enable                              
#define RTC0CF_AUTORST__SHIFT    0x03 ///< Auto Reset Enable                              
#define RTC0CF_AUTORST__DISABLED 0x00 ///< Disable auto reset.                            
#define RTC0CF_AUTORST__ENABLED  0x08 ///< Enable auto reset.                             
                                                                                          
#define RTC0CF_ALRM0__BMASK      0x10 ///< Event Flag for Alarm 0                         
#define RTC0CF_ALRM0__SHIFT      0x04 ///< Event Flag for Alarm 0                         
#define RTC0CF_ALRM0__NOT_SET    0x00 ///< An Alarm 0 event has not occured since the last
                                      ///< time the flag was cleared.                     
#define RTC0CF_ALRM0__SET        0x10 ///< An Alarm 0 event has occured.                  
                                                                                          
#define RTC0CF_ALRM1__BMASK      0x20 ///< Event Flag for Alarm 1                         
#define RTC0CF_ALRM1__SHIFT      0x05 ///< Event Flag for Alarm 1                         
#define RTC0CF_ALRM1__NOT_SET    0x00 ///< An Alarm 1 event has not occured since the last
                                      ///< time the flag was cleared.                     
#define RTC0CF_ALRM1__SET        0x20 ///< An Alarm 1 event has occured.                  
                                                                                          
#define RTC0CF_ALRM2__BMASK      0x40 ///< Event Flag for Alarm 2                         
#define RTC0CF_ALRM2__SHIFT      0x06 ///< Event Flag for Alarm 2                         
#define RTC0CF_ALRM2__NOT_SET    0x00 ///< An Alarm 2 event has not occured since the last
                                      ///< time the flag was cleared.                     
#define RTC0CF_ALRM2__SET        0x40 ///< An Alarm 2 event has occured.                  
                                                                                          
//------------------------------------------------------------------------------
// RTC0CN Enums (RTC Control @ 0x04)
//------------------------------------------------------------------------------
#define RTC0CN_RTC0CAP__BMASK    0x01 ///< RTC Timer Capture                          
#define RTC0CN_RTC0CAP__SHIFT    0x00 ///< RTC Timer Capture                          
#define RTC0CN_RTC0CAP__NOT_SET  0x00 ///< Do not start a capture operation.          
#define RTC0CN_RTC0CAP__SET      0x01 ///< Start a capture operation.                 
                                                                                      
#define RTC0CN_RTC0SET__BMASK    0x02 ///< RTC Timer Set                              
#define RTC0CN_RTC0SET__SHIFT    0x01 ///< RTC Timer Set                              
#define RTC0CN_RTC0SET__NOT_SET  0x00 ///< Do not start a set operation.              
#define RTC0CN_RTC0SET__SET      0x02 ///< Start a set operation.                     
                                                                                      
#define RTC0CN_HSMODE__BMASK     0x04 ///< High Speed Mode Enable                     
#define RTC0CN_HSMODE__SHIFT     0x02 ///< High Speed Mode Enable                     
#define RTC0CN_HSMODE__DISABLED  0x00 ///< Disable high speed mode.                   
#define RTC0CN_HSMODE__ENABLED   0x04 ///< Enable high speed mode.                    
                                                                                      
#define RTC0CN_RTC0AEN__BMASK    0x08 ///< RTC Alarm Enable                           
#define RTC0CN_RTC0AEN__SHIFT    0x03 ///< RTC Alarm Enable                           
#define RTC0CN_RTC0AEN__DISABLED 0x00 ///< Disable RTC alarm.                         
#define RTC0CN_RTC0AEN__ENABLED  0x08 ///< Enable RTC alarm.                          
                                                                                      
#define RTC0CN_RTC0TR__BMASK     0x10 ///< RTC Timer Run Control                      
#define RTC0CN_RTC0TR__SHIFT     0x04 ///< RTC Timer Run Control                      
#define RTC0CN_RTC0TR__STOP      0x00 ///< RTC timer is stopped.                      
#define RTC0CN_RTC0TR__RUN       0x10 ///< RTC timer is running.                      
                                                                                      
#define RTC0CN_OSCFAIL__BMASK    0x20 ///< RTC Oscillator Fail Event Flag             
#define RTC0CN_OSCFAIL__SHIFT    0x05 ///< RTC Oscillator Fail Event Flag             
#define RTC0CN_OSCFAIL__NOT_SET  0x00 ///< Missing RTC detector timeout did not occur.
#define RTC0CN_OSCFAIL__SET      0x20 ///< Missing RTC detector timeout occurred.     
                                                                                      
#define RTC0CN_MCLKEN__BMASK     0x40 ///< Missing RTC Detector Enable                
#define RTC0CN_MCLKEN__SHIFT     0x06 ///< Missing RTC Detector Enable                
#define RTC0CN_MCLKEN__DISABLED  0x00 ///< Disable missing RTC detector.              
#define RTC0CN_MCLKEN__ENABLED   0x40 ///< Enable missing RTC detector.               
                                                                                      
#define RTC0CN_RTC0EN__BMASK     0x80 ///< RTC Enable                                 
#define RTC0CN_RTC0EN__SHIFT     0x07 ///< RTC Enable                                 
#define RTC0CN_RTC0EN__DISABLED  0x00 ///< Disable RTC oscillator.                    
#define RTC0CN_RTC0EN__ENABLED   0x80 ///< Enable RTC oscillator.                     
                                                                                      
//------------------------------------------------------------------------------
// RTC0DAT Enums (RTC Data @ 0xAD)
//------------------------------------------------------------------------------
#define RTC0DAT_RTC0DAT__FMASK 0xFF ///< RTC Data
#define RTC0DAT_RTC0DAT__SHIFT 0x00 ///< RTC Data
                                                 
//------------------------------------------------------------------------------
// RTC0KEY Enums (RTC Lock and Key @ 0xAE)
//------------------------------------------------------------------------------
#define RTC0KEY_RTC0ST__FMASK    0xFF ///< RTC Interface Status      
#define RTC0KEY_RTC0ST__SHIFT    0x00 ///< RTC Interface Status      
#define RTC0KEY_RTC0ST__UNLOCKED 0x02 ///< RTC Interface is unlocked.
                                                                     
//------------------------------------------------------------------------------
// RTC0XCF Enums (RTC Oscillator Configuration @ 0x06)
//------------------------------------------------------------------------------
#define RTC0XCF_LOADCAP__FMASK    0x0F ///< Load Capacitance Programmed Value                
#define RTC0XCF_LOADCAP__SHIFT    0x00 ///< Load Capacitance Programmed Value                
                                                                                             
#define RTC0XCF_LOADRDY__BMASK    0x40 ///< Load Capacitance Ready Indicator                 
#define RTC0XCF_LOADRDY__SHIFT    0x06 ///< Load Capacitance Ready Indicator                 
#define RTC0XCF_LOADRDY__NOT_SET  0x00 ///< Load capacitance is currently stepping.          
#define RTC0XCF_LOADRDY__SET      0x40 ///< Load capacitance has reached it programmed value.
                                                                                             
#define RTC0XCF_AUTOSTP__BMASK    0x80 ///< Automatic Load Capacitance Stepping Enable       
#define RTC0XCF_AUTOSTP__SHIFT    0x07 ///< Automatic Load Capacitance Stepping Enable       
#define RTC0XCF_AUTOSTP__DISABLED 0x00 ///< Disable load capacitance stepping.               
#define RTC0XCF_AUTOSTP__ENABLED  0x80 ///< Enable load capacitance stepping.                
                                                                                             
//------------------------------------------------------------------------------
// RTC0XCN Enums (RTC Oscillator Control @ 0x05)
//------------------------------------------------------------------------------
#define RTC0XCN_LFOEN__BMASK          0x08 ///< Low Frequency Oscillator Enable and Select        
#define RTC0XCN_LFOEN__SHIFT          0x03 ///< Low Frequency Oscillator Enable and Select        
#define RTC0XCN_LFOEN__DISABLED       0x00 ///< XMODE determines RTC oscillator source.           
#define RTC0XCN_LFOEN__ENABLED        0x08 ///< LFOSC enabled and selected as RTC oscillator      
                                           ///< source.                                           
                                                                                                  
#define RTC0XCN_CLKVLD__BMASK         0x10 ///< RTC Oscillator Crystal Valid Indicator            
#define RTC0XCN_CLKVLD__SHIFT         0x04 ///< RTC Oscillator Crystal Valid Indicator            
#define RTC0XCN_CLKVLD__NOT_SET       0x00 ///< Oscillation has not started or oscillation        
                                           ///< amplitude is too low to maintain oscillation.     
#define RTC0XCN_CLKVLD__SET           0x10 ///< Sufficient oscillation amplitude detected.        
                                                                                                  
#define RTC0XCN_BIASX2__BMASK         0x20 ///< RTC Oscillator Bias Double Enable                 
#define RTC0XCN_BIASX2__SHIFT         0x05 ///< RTC Oscillator Bias Double Enable                 
#define RTC0XCN_BIASX2__DISABLED      0x00 ///< Disable the Bias Double feature.                  
#define RTC0XCN_BIASX2__ENABLED       0x20 ///< Enable the Bias Double feature.                   
                                                                                                  
#define RTC0XCN_XMODE__BMASK          0x40 ///< RTC Oscillator Mode                               
#define RTC0XCN_XMODE__SHIFT          0x06 ///< RTC Oscillator Mode                               
#define RTC0XCN_XMODE__SELF_OSCILLATE 0x00 ///< Self-Oscillate Mode selected.                     
#define RTC0XCN_XMODE__CRYSTAL        0x40 ///< Crystal Mode selected.                            
                                                                                                  
#define RTC0XCN_AGCEN__BMASK          0x80 ///< RTC Oscillator Automatic Gain Control (AGC) Enable
#define RTC0XCN_AGCEN__SHIFT          0x07 ///< RTC Oscillator Automatic Gain Control (AGC) Enable
#define RTC0XCN_AGCEN__DISABLED       0x00 ///< Disable AGC.                                      
#define RTC0XCN_AGCEN__ENABLED        0x80 ///< Enable AGC.                                       
                                                                                                  
//------------------------------------------------------------------------------
// SMB0ADM Enums (SMBus 0 Slave Address Mask @ 0xF5)
//------------------------------------------------------------------------------
#define SMB0ADM_EHACK__BMASK             0x01 ///< Hardware Acknowledge Enable                     
#define SMB0ADM_EHACK__SHIFT             0x00 ///< Hardware Acknowledge Enable                     
#define SMB0ADM_EHACK__ADR_ACK_MANUAL    0x00 ///< Firmware must manually acknowledge all incoming 
                                              ///< address and data bytes.                         
#define SMB0ADM_EHACK__ADR_ACK_AUTOMATIC 0x01 ///< Automatic slave address recognition and hardware
                                              ///< acknowledge is enabled.                         
                                                                                                   
#define SMB0ADM_SLVM__FMASK              0xFE ///< SMBus Slave Address Mask                        
#define SMB0ADM_SLVM__SHIFT              0x01 ///< SMBus Slave Address Mask                        
                                                                                                   
//------------------------------------------------------------------------------
// SMB0ADR Enums (SMBus 0 Slave Address @ 0xF4)
//------------------------------------------------------------------------------
#define SMB0ADR_GC__BMASK      0x01 ///< General Call Address Enable        
#define SMB0ADR_GC__SHIFT      0x00 ///< General Call Address Enable        
#define SMB0ADR_GC__IGNORED    0x00 ///< General Call Address is ignored.   
#define SMB0ADR_GC__RECOGNIZED 0x01 ///< General Call Address is recognized.
                                                                            
#define SMB0ADR_SLV__FMASK     0xFE ///< SMBus Hardware Slave Address       
#define SMB0ADR_SLV__SHIFT     0x01 ///< SMBus Hardware Slave Address       
                                                                            
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
// SPI1CFG Enums (SPI1 Configuration @ 0xA1)
//------------------------------------------------------------------------------
#define SPI1CFG_RXBMT__BMASK                0x01 ///< Receive Buffer Empty                              
#define SPI1CFG_RXBMT__SHIFT                0x00 ///< Receive Buffer Empty                              
#define SPI1CFG_RXBMT__NOT_SET              0x00 ///< New data is available in the receive buffer (Slave
                                                 ///< mode).                                            
#define SPI1CFG_RXBMT__SET                  0x01 ///< No new data in the receive buffer (Slave mode).   
                                                                                                        
#define SPI1CFG_SRMT__BMASK                 0x02 ///< Shift Register Empty                              
#define SPI1CFG_SRMT__SHIFT                 0x01 ///< Shift Register Empty                              
#define SPI1CFG_SRMT__NOT_SET               0x00 ///< The shift register is not empty.                  
#define SPI1CFG_SRMT__SET                   0x02 ///< The shift register is empty.                      
                                                                                                        
#define SPI1CFG_NSSIN__BMASK                0x04 ///< NSS Instantaneous Pin Input                       
#define SPI1CFG_NSSIN__SHIFT                0x02 ///< NSS Instantaneous Pin Input                       
#define SPI1CFG_NSSIN__LOW                  0x00 ///< The NSS pin is low.                               
#define SPI1CFG_NSSIN__HIGH                 0x04 ///< The NSS pin is high.                              
                                                                                                        
#define SPI1CFG_SLVSEL__BMASK               0x08 ///< Slave Selected Flag                               
#define SPI1CFG_SLVSEL__SHIFT               0x03 ///< Slave Selected Flag                               
#define SPI1CFG_SLVSEL__NOT_SELECTED        0x00 ///< The Slave is not selected (NSS is high).          
#define SPI1CFG_SLVSEL__SELECTED            0x08 ///< The Slave is selected (NSS is low).               
                                                                                                        
#define SPI1CFG_CKPOL__BMASK                0x10 ///< SPI1 Clock Polarity                               
#define SPI1CFG_CKPOL__SHIFT                0x04 ///< SPI1 Clock Polarity                               
#define SPI1CFG_CKPOL__IDLE_LOW             0x00 ///< SCK line low in idle state.                       
#define SPI1CFG_CKPOL__IDLE_HIGH            0x10 ///< SCK line high in idle state.                      
                                                                                                        
#define SPI1CFG_CKPHA__BMASK                0x20 ///< SPI1 Clock Phase                                  
#define SPI1CFG_CKPHA__SHIFT                0x05 ///< SPI1 Clock Phase                                  
#define SPI1CFG_CKPHA__DATA_CENTERED_FIRST  0x00 ///< Data centered on first edge of SCK period.        
#define SPI1CFG_CKPHA__DATA_CENTERED_SECOND 0x20 ///< Data centered on second edge of SCK period.       
                                                                                                        
#define SPI1CFG_MSTEN__BMASK                0x40 ///< Master Mode Enable                                
#define SPI1CFG_MSTEN__SHIFT                0x06 ///< Master Mode Enable                                
#define SPI1CFG_MSTEN__MASTER_DISABLED      0x00 ///< Disable master mode. Operate in slave mode.       
#define SPI1CFG_MSTEN__MASTER_ENABLED       0x40 ///< Enable master mode. Operate as a master.          
                                                                                                        
#define SPI1CFG_SPIBSY__BMASK               0x80 ///< SPI Busy                                          
#define SPI1CFG_SPIBSY__SHIFT               0x07 ///< SPI Busy                                          
#define SPI1CFG_SPIBSY__NOT_SET             0x00 ///< A SPI transfer is not in progress.                
#define SPI1CFG_SPIBSY__SET                 0x80 ///< A SPI transfer is in progress.                    
                                                                                                        
//------------------------------------------------------------------------------
// SPI1CKR Enums (SPI1 Clock Rate @ 0xA2)
//------------------------------------------------------------------------------
#define SPI1CKR_SPI1CKR__FMASK 0xFF ///< SPI1 Clock Rate
#define SPI1CKR_SPI1CKR__SHIFT 0x00 ///< SPI1 Clock Rate
                                                        
//------------------------------------------------------------------------------
// SPI1CN Enums (SPI1 Control @ 0xF8)
//------------------------------------------------------------------------------
#define SPI1CN_SPIEN__BMASK                  0x01 ///< SPI1 Enable                                       
#define SPI1CN_SPIEN__SHIFT                  0x00 ///< SPI1 Enable                                       
#define SPI1CN_SPIEN__DISABLED               0x00 ///< Disable the SPI module.                           
#define SPI1CN_SPIEN__ENABLED                0x01 ///< Enable the SPI module.                            
                                                                                                         
#define SPI1CN_TXBMT__BMASK                  0x02 ///< Transmit Buffer Empty                             
#define SPI1CN_TXBMT__SHIFT                  0x01 ///< Transmit Buffer Empty                             
#define SPI1CN_TXBMT__NOT_SET                0x00 ///< The transmit buffer is not empty.                 
#define SPI1CN_TXBMT__SET                    0x02 ///< The transmit buffer is empty.                     
                                                                                                         
#define SPI1CN_NSSMD__FMASK                  0x0C ///< Slave Select Mode                                 
#define SPI1CN_NSSMD__SHIFT                  0x02 ///< Slave Select Mode                                 
#define SPI1CN_NSSMD__3_WIRE                 0x00 ///< 3-Wire Slave or 3-Wire Master Mode. NSS signal is 
                                                  ///< not routed to a port pin.                         
#define SPI1CN_NSSMD__4_WIRE_SLAVE           0x04 ///< 4-Wire Slave or Multi-Master Mode. NSS is an input
                                                  ///< to the device.                                    
#define SPI1CN_NSSMD__4_WIRE_MASTER_NSS_LOW  0x08 ///< 4-Wire Single-Master Mode. NSS is an output and   
                                                  ///< logic low.                                        
#define SPI1CN_NSSMD__4_WIRE_MASTER_NSS_HIGH 0x0C ///< 4-Wire Single-Master Mode. NSS is an output and   
                                                  ///< logic high.                                       
                                                                                                         
#define SPI1CN_RXOVRN__BMASK                 0x10 ///< Receive Overrun Flag                              
#define SPI1CN_RXOVRN__SHIFT                 0x04 ///< Receive Overrun Flag                              
#define SPI1CN_RXOVRN__NOT_SET               0x00 ///< A receive overrun did not occur.                  
#define SPI1CN_RXOVRN__SET                   0x10 ///< A receive overrun occurred.                       
                                                                                                         
#define SPI1CN_MODF__BMASK                   0x20 ///< Mode Fault Flag                                   
#define SPI1CN_MODF__SHIFT                   0x05 ///< Mode Fault Flag                                   
#define SPI1CN_MODF__NOT_SET                 0x00 ///< A master collision did not occur.                 
#define SPI1CN_MODF__SET                     0x20 ///< A master collision occurred.                      
                                                                                                         
#define SPI1CN_WCOL__BMASK                   0x40 ///< Write Collision Flag                              
#define SPI1CN_WCOL__SHIFT                   0x06 ///< Write Collision Flag                              
#define SPI1CN_WCOL__NOT_SET                 0x00 ///< A write collision did not occur.                  
#define SPI1CN_WCOL__SET                     0x40 ///< A write collision occurred.                       
                                                                                                         
#define SPI1CN_SPIF__BMASK                   0x80 ///< SPI1 Interrupt Flag                               
#define SPI1CN_SPIF__SHIFT                   0x07 ///< SPI1 Interrupt Flag                               
#define SPI1CN_SPIF__NOT_SET                 0x00 ///< A data transfer has not completed since the last  
                                                  ///< time SPIF was cleared.                            
#define SPI1CN_SPIF__SET                     0x80 ///< A data transfer completed.                        
                                                                                                         
//------------------------------------------------------------------------------
// SPI1DAT Enums (SPI1 Data @ 0xA3)
//------------------------------------------------------------------------------
#define SPI1DAT_SPI1DAT__FMASK 0xFF ///< SPI1 Transmit and Receive Data
#define SPI1DAT_SPI1DAT__SHIFT 0x00 ///< SPI1 Transmit and Receive Data
                                                                       
//------------------------------------------------------------------------------
// TOFFH Enums (Temperature Sensor Offset High @ 0xBE)
//------------------------------------------------------------------------------
#define TOFFH_TOFF__FMASK 0xFF ///< Temperature Sensor Offset High
#define TOFFH_TOFF__SHIFT 0x00 ///< Temperature Sensor Offset High
                                                                  
//------------------------------------------------------------------------------
// TOFFL Enums (Temperature Sensor Offset Low @ 0xBD)
//------------------------------------------------------------------------------
#define TOFFL_TOFF__FMASK 0xC0 ///< Temperature Sensor Offset Low
#define TOFFL_TOFF__SHIFT 0x06 ///< Temperature Sensor Offset Low
                                                                 
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
#define TMR2CN_T2XCLK__FMASK                  0x03 ///< Timer 2 External Clock Select                     
#define TMR2CN_T2XCLK__SHIFT                  0x00 ///< Timer 2 External Clock Select                     
#define TMR2CN_T2XCLK__SYSCLK_DIV_12_CAP_RTC  0x00 ///< External Clock is SYSCLK/12. Capture trigger is   
                                                   ///< RTC/8.                                            
#define TMR2CN_T2XCLK__CMP_0_CAP_RTC          0x01 ///< External Clock is Comparator 0. Capture trigger is
                                                   ///< RTC/8.                                            
#define TMR2CN_T2XCLK__SYSCLK_DIV_12_CAP_CMP0 0x02 ///< External Clock is SYSCLK/12. Capture trigger is   
                                                   ///< Comparator 0.                                     
#define TMR2CN_T2XCLK__RTC_DIV_8_CAP_CMP0     0x03 ///< External Clock is RTC/8. Capture trigger is       
                                                   ///< Comparator 0.                                     
                                                                                                          
#define TMR2CN_TR2__BMASK                     0x04 ///< Timer 2 Run Control                               
#define TMR2CN_TR2__SHIFT                     0x02 ///< Timer 2 Run Control                               
#define TMR2CN_TR2__STOP                      0x00 ///< Stop Timer 2.                                     
#define TMR2CN_TR2__RUN                       0x04 ///< Start Timer 2 running.                            
                                                                                                          
#define TMR2CN_T2SPLIT__BMASK                 0x08 ///< Timer 2 Split Mode Enable                         
#define TMR2CN_T2SPLIT__SHIFT                 0x03 ///< Timer 2 Split Mode Enable                         
#define TMR2CN_T2SPLIT__16_BIT_RELOAD         0x00 ///< Timer 2 operates in 16-bit auto-reload mode.      
#define TMR2CN_T2SPLIT__8_BIT_RELOAD          0x08 ///< Timer 2 operates as two 8-bit auto-reload timers. 
                                                                                                          
#define TMR2CN_TF2CEN__BMASK                  0x10 ///< Timer 2 Capture Enable                            
#define TMR2CN_TF2CEN__SHIFT                  0x04 ///< Timer 2 Capture Enable                            
#define TMR2CN_TF2CEN__DISABLED               0x00 ///< Disable capture mode.                             
#define TMR2CN_TF2CEN__ENABLED                0x10 ///< Enable capture mode.                              
                                                                                                          
#define TMR2CN_TF2LEN__BMASK                  0x20 ///< Timer 2 Low Byte Interrupt Enable                 
#define TMR2CN_TF2LEN__SHIFT                  0x05 ///< Timer 2 Low Byte Interrupt Enable                 
#define TMR2CN_TF2LEN__DISABLED               0x00 ///< Disable low byte interrupts.                      
#define TMR2CN_TF2LEN__ENABLED                0x20 ///< Enable low byte interrupts.                       
                                                                                                          
#define TMR2CN_TF2L__BMASK                    0x40 ///< Timer 2 Low Byte Overflow Flag                    
#define TMR2CN_TF2L__SHIFT                    0x06 ///< Timer 2 Low Byte Overflow Flag                    
#define TMR2CN_TF2L__NOT_SET                  0x00 ///< Timer 2 low byte did not overflow.                
#define TMR2CN_TF2L__SET                      0x40 ///< Timer 2 low byte overflowed.                      
                                                                                                          
#define TMR2CN_TF2H__BMASK                    0x80 ///< Timer 2 High Byte Overflow Flag                   
#define TMR2CN_TF2H__SHIFT                    0x07 ///< Timer 2 High Byte Overflow Flag                   
#define TMR2CN_TF2H__NOT_SET                  0x00 ///< Timer 2 8-bit high byte or 16-bit value did not   
                                                   ///< overflow.                                         
#define TMR2CN_TF2H__SET                      0x80 ///< Timer 2 8-bit high byte or 16-bit value           
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
#define TMR3CN_T3XCLK__FMASK                    0x03 ///< Timer 3 External Clock Select                     
#define TMR3CN_T3XCLK__SHIFT                    0x00 ///< Timer 3 External Clock Select                     
#define TMR3CN_T3XCLK__SYSCLK_DIV_12_CAP_RTC    0x00 ///< External Clock is SYSCLK/12. Capture trigger is   
                                                     ///< RTC.                                              
#define TMR3CN_T3XCLK__EXTOSC_DIV_8_CAP_RTC     0x01 ///< External Clock is External Oscillator/8. Capture  
                                                     ///< trigger is RTC.                                   
#define TMR3CN_T3XCLK__SYSCLK_DIV_12_CAP_EXTOSC 0x02 ///< External Clock is SYSCLK/12. Capture trigger is   
                                                     ///< External Oscillator/8.                            
#define TMR3CN_T3XCLK__RTC_CAP_EXTOSC           0x03 ///< External Clock is RTC. Capture trigger is External
                                                     ///< Oscillator/8.                                     
                                                                                                            
#define TMR3CN_TR3__BMASK                       0x04 ///< Timer 3 Run Control                               
#define TMR3CN_TR3__SHIFT                       0x02 ///< Timer 3 Run Control                               
#define TMR3CN_TR3__STOP                        0x00 ///< Stop Timer 3.                                     
#define TMR3CN_TR3__RUN                         0x04 ///< Start Timer 3 running.                            
                                                                                                            
#define TMR3CN_T3SPLIT__BMASK                   0x08 ///< Timer 3 Split Mode Enable                         
#define TMR3CN_T3SPLIT__SHIFT                   0x03 ///< Timer 3 Split Mode Enable                         
#define TMR3CN_T3SPLIT__16_BIT_RELOAD           0x00 ///< Timer 3 operates in 16-bit auto-reload mode.      
#define TMR3CN_T3SPLIT__8_BIT_RELOAD            0x08 ///< Timer 3 operates as two 8-bit auto-reload timers. 
                                                                                                            
#define TMR3CN_TF3CEN__BMASK                    0x10 ///< Timer 3 Capture Enable                            
#define TMR3CN_TF3CEN__SHIFT                    0x04 ///< Timer 3 Capture Enable                            
#define TMR3CN_TF3CEN__DISABLED                 0x00 ///< Disable capture mode.                             
#define TMR3CN_TF3CEN__ENABLED                  0x10 ///< Enable capture mode.                              
                                                                                                            
#define TMR3CN_TF3LEN__BMASK                    0x20 ///< Timer 3 Low Byte Interrupt Enable                 
#define TMR3CN_TF3LEN__SHIFT                    0x05 ///< Timer 3 Low Byte Interrupt Enable                 
#define TMR3CN_TF3LEN__DISABLED                 0x00 ///< Disable low byte interrupts.                      
#define TMR3CN_TF3LEN__ENABLED                  0x20 ///< Enable low byte interrupts.                       
                                                                                                            
#define TMR3CN_TF3L__BMASK                      0x40 ///< Timer 3 Low Byte Overflow Flag                    
#define TMR3CN_TF3L__SHIFT                      0x06 ///< Timer 3 Low Byte Overflow Flag                    
#define TMR3CN_TF3L__NOT_SET                    0x00 ///< Timer 3 low byte did not overflow.                
#define TMR3CN_TF3L__SET                        0x40 ///< Timer 3 low byte overflowed.                      
                                                                                                            
#define TMR3CN_TF3H__BMASK                      0x80 ///< Timer 3 High Byte Overflow Flag                   
#define TMR3CN_TF3H__SHIFT                      0x07 ///< Timer 3 High Byte Overflow Flag                   
#define TMR3CN_TF3H__NOT_SET                    0x00 ///< Timer 3 8-bit high byte or 16-bit value did not   
                                                     ///< overflow.                                         
#define TMR3CN_TF3H__SET                        0x80 ///< Timer 3 8-bit high byte or 16-bit value           
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
// SBUF0 Enums (UART0 Serial Port Data Buffer @ 0x99)
//------------------------------------------------------------------------------
#define SBUF0_SBUF0__FMASK 0xFF ///< Serial Data Buffer
#define SBUF0_SBUF0__SHIFT 0x00 ///< Serial Data Buffer
                                                       
//------------------------------------------------------------------------------
// SCON0 Enums (UART0 Serial Port Control @ 0x98)
//------------------------------------------------------------------------------
#define SCON0_RI__BMASK             0x01 ///< Receive Interrupt Flag                           
#define SCON0_RI__SHIFT             0x00 ///< Receive Interrupt Flag                           
#define SCON0_RI__NOT_SET           0x00 ///< A byte of data has not been received by UART0.   
#define SCON0_RI__SET               0x01 ///< UART0 received a byte of data.                   
                                                                                               
#define SCON0_TI__BMASK             0x02 ///< Transmit Interrupt Flag                          
#define SCON0_TI__SHIFT             0x01 ///< Transmit Interrupt Flag                          
#define SCON0_TI__NOT_SET           0x00 ///< A byte of data has not been transmitted by UART0.
#define SCON0_TI__SET               0x02 ///< UART0 transmitted a byte of data.                
                                                                                               
#define SCON0_RB8__BMASK            0x04 ///< Ninth Receive Bit                                
#define SCON0_RB8__SHIFT            0x02 ///< Ninth Receive Bit                                
#define SCON0_RB8__CLEARED_TO_0     0x00 ///< In Mode 0, the STOP bit was 0. In Mode 1, the 9th
                                         ///< bit was 0.                                       
#define SCON0_RB8__SET_TO_1         0x04 ///< In Mode 0, the STOP bit was 1. In Mode 1, the 9th
                                         ///< bit was 1.                                       
                                                                                               
#define SCON0_TB8__BMASK            0x08 ///< Ninth Transmission Bit                           
#define SCON0_TB8__SHIFT            0x03 ///< Ninth Transmission Bit                           
#define SCON0_TB8__CLEARED_TO_0     0x00 ///< In Mode 1, set the 9th transmission bit to 0.    
#define SCON0_TB8__SET_TO_1         0x08 ///< In Mode 1, set the 9th transmission bit to 1.    
                                                                                               
#define SCON0_REN__BMASK            0x10 ///< Receive Enable                                   
#define SCON0_REN__SHIFT            0x04 ///< Receive Enable                                   
#define SCON0_REN__RECEIVE_DISABLED 0x00 ///< UART0 reception disabled.                        
#define SCON0_REN__RECEIVE_ENABLED  0x10 ///< UART0 reception enabled.                         
                                                                                               
#define SCON0_MCE__BMASK            0x20 ///< Multiprocessor Communication Enable              
#define SCON0_MCE__SHIFT            0x05 ///< Multiprocessor Communication Enable              
#define SCON0_MCE__MULTI_DISABLED   0x00 ///< Ignore level of 9th bit / Stop bit.              
#define SCON0_MCE__MULTI_ENABLED    0x20 ///< RI is set and an interrupt is generated only when
                                         ///< the stop bit is logic 1 (Mode 0) or when the 9th 
                                         ///< bit is logic 1 (Mode 1).                         
                                                                                               
#define SCON0_SMODE__BMASK          0x80 ///< Serial Port 0 Operation Mode                     
#define SCON0_SMODE__SHIFT          0x07 ///< Serial Port 0 Operation Mode                     
#define SCON0_SMODE__8_BIT          0x00 ///< 8-bit UART with Variable Baud Rate (Mode 0).     
#define SCON0_SMODE__9_BIT          0x80 ///< 9-bit UART with Variable Baud Rate (Mode 1).     
                                                                                               
//------------------------------------------------------------------------------
// VDM0CN Enums (VDD Supply Monitor Control @ 0xFF)
//------------------------------------------------------------------------------
#define VDM0CN_VBOKIE__BMASK            0x01 ///< VBAT Early Warning Interrupt Enable       
#define VDM0CN_VBOKIE__SHIFT            0x00 ///< VBAT Early Warning Interrupt Enable       
#define VDM0CN_VBOKIE__DISABLED         0x00 ///< Disable the VBAT Early Warning interrupt. 
#define VDM0CN_VBOKIE__ENABLED          0x01 ///< Enable the VBAT Early Warning interrupt.  
                                                                                            
#define VDM0CN_VBOK__BMASK              0x02 ///< VBAT Early Warning Status                 
#define VDM0CN_VBOK__SHIFT              0x01 ///< VBAT Early Warning Status                 
#define VDM0CN_VBOK__AT_OR_BELOW        0x00 ///< VBAT is at or below the VDDWARN threshold.
#define VDM0CN_VBOK__ABOVE              0x02 ///< VBAT is above the VDDWARN threshold.      
                                                                                            
#define VDM0CN_VBSTAT__BMASK            0x04 ///< VBAT Supply Status                        
#define VDM0CN_VBSTAT__SHIFT            0x02 ///< VBAT Supply Status                        
#define VDM0CN_VBSTAT__AT_OR_BELOW      0x00 ///< VBAT is at or below the VRST threshold.   
#define VDM0CN_VBSTAT__ABOVE            0x04 ///< VBAT is above the VRST threshold.         
                                                                                            
#define VDM0CN_VBMEN__BMASK             0x08 ///< VBAT Supply Monitor Enable                
#define VDM0CN_VBMEN__SHIFT             0x03 ///< VBAT Supply Monitor Enable                
#define VDM0CN_VBMEN__DISABLED          0x00 ///< Disable the VBAT Supply Monitor.          
#define VDM0CN_VBMEN__ENABLED           0x08 ///< Enable the VBAT Supply Monitor.           
                                                                                            
#define VDM0CN_VDDOKIE__BMASK           0x10 ///< Digital Early Warning Interrupt Enable    
#define VDM0CN_VDDOKIE__SHIFT           0x04 ///< Digital Early Warning Interrupt Enable    
#define VDM0CN_VDDOKIE__DISABLED        0x00 ///< Disable the VDD early warning interrupt.  
#define VDM0CN_VDDOKIE__ENABLED         0x10 ///< Enable the VDD early warning interrupt.   
                                                                                            
#define VDM0CN_VDDOK__BMASK             0x20 ///< VDD Supply Status (Early Warning)         
#define VDM0CN_VDDOK__SHIFT             0x05 ///< VDD Supply Status (Early Warning)         
#define VDM0CN_VDDOK__VDD_BELOW_VDDWARN 0x00 ///< VDD is at or below the VDDWARN threshold. 
#define VDM0CN_VDDOK__VDD_ABOVE_VDDWARN 0x20 ///< VDD is above the VDDWARN threshold.       
                                                                                            
#define VDM0CN_VDDSTAT__BMASK           0x40 ///< VDD Supply Status                         
#define VDM0CN_VDDSTAT__SHIFT           0x06 ///< VDD Supply Status                         
#define VDM0CN_VDDSTAT__VDD_BELOW_VRST  0x00 ///< VDD is at or below the VRST threshold.    
#define VDM0CN_VDDSTAT__VDD_ABOVE_VRST  0x40 ///< VDD is above the VRST threshold.          
                                                                                            
#define VDM0CN_VDMEN__BMASK             0x80 ///< VDD Supply Monitor Enable                 
#define VDM0CN_VDMEN__SHIFT             0x07 ///< VDD Supply Monitor Enable                 
#define VDM0CN_VDMEN__DISABLED          0x00 ///< Disable the VDD supply monitor.           
#define VDM0CN_VDMEN__ENABLED           0x80 ///< Enable the VDD supply monitor.            
                                                                                            
//------------------------------------------------------------------------------
// REF0CN Enums (Voltage Reference Control @ 0xD1)
//------------------------------------------------------------------------------
#define REF0CN_TEMPE__BMASK           0x04 ///< Temperature Sensor Enable                        
#define REF0CN_TEMPE__SHIFT           0x02 ///< Temperature Sensor Enable                        
#define REF0CN_TEMPE__TEMP_DISABLED   0x00 ///< Disable the Temperature Sensor.                  
#define REF0CN_TEMPE__TEMP_ENABLED    0x04 ///< Enable the Temperature Sensor.                   
                                                                                                 
#define REF0CN_REFSL__FMASK           0x18 ///< Voltage Reference Select                         
#define REF0CN_REFSL__SHIFT           0x03 ///< Voltage Reference Select                         
#define REF0CN_REFSL__VREF_PIN        0x00 ///< The ADC0 voltage reference is the P0.0/VREF pin. 
#define REF0CN_REFSL__VDD_PIN         0x08 ///< The ADC0 voltage reference is the VDD pin.       
#define REF0CN_REFSL__INTERNAL_LDO    0x10 ///< The ADC0 voltage reference is the internal 1.8 V 
                                           ///< digital supply voltage.                          
#define REF0CN_REFSL__HIGH_SPEED_VREF 0x18 ///< The ADC0 voltage reference is the internal 1.65 V
                                           ///< high speed voltage reference.                    
                                                                                                 
#define REF0CN_REFGND__BMASK          0x20 ///< Analog Ground Reference                          
#define REF0CN_REFGND__SHIFT          0x05 ///< Analog Ground Reference                          
#define REF0CN_REFGND__GND_PIN        0x00 ///< The ADC0 ground reference is the GND pin.        
#define REF0CN_REFGND__AGND_PIN       0x20 ///< The ADC0 ground reference is the P0.1/AGND pin.  
                                                                                                 
//------------------------------------------------------------------------------
// REG0CN Enums (Voltage Regulator Control @ 0xC9)
//------------------------------------------------------------------------------
#define REG0CN_OSCBIAS__BMASK    0x10 ///< High Frequency Oscillator Bias                 
#define REG0CN_OSCBIAS__SHIFT    0x04 ///< High Frequency Oscillator Bias                 
#define REG0CN_OSCBIAS__DISABLED 0x00 ///< Disable the precision High Frequency Oscillator
                                      ///< bias.                                          
#define REG0CN_OSCBIAS__ENABLED  0x10 ///< Enable the precision High Frequency Oscillator 
                                      ///< bias.                                          
                                                                                          
//------------------------------------------------------------------------------
// EMI0CF Enums (External Memory Configuration @ 0xAB)
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
// EMI0TC Enums (External Memory Timing Control @ 0xAF)
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
                                                                                       
#endif // SI_C8051F960_REGISTER_ENUMS_H
//-eof--------------------------------------------------------------------------

