//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  C8051F120_GQ
//  C8051F121_GQ
//  C8051F122_GQ
//  C8051F123_GQ
//  C8051F124_GQ
//  C8051F125_GQ
//  C8051F126_GQ
//  C8051F127_GQ
//  C8051F130_GQ
//  C8051F131_GQ
//  C8051F132_GQ
//  C8051F133_GQ

#ifndef SI_C8051F120_REGISTER_ENUMS_H
#define SI_C8051F120_REGISTER_ENUMS_H

//Standard device includes
#include "SI_C8051F120_Defs.h"
//------------------------------------------------------------------------------
// ADC2 Enums (ADC2 Data Word @ 0xBE)
//------------------------------------------------------------------------------
#define ADC2_ADC2H__FMASK 0xFF ///< Data Word
#define ADC2_ADC2H__SHIFT 0x00 ///< Data Word
                                             
//------------------------------------------------------------------------------
// ADC2CF Enums (ADC2 Configuration @ 0xBC)
//------------------------------------------------------------------------------
#define ADC2CF_AMP2GN__FMASK    0x03 ///< ADC2 Internal Amplifier Gain (PGA)
#define ADC2CF_AMP2GN__SHIFT    0x00 ///< ADC2 Internal Amplifier Gain (PGA)
#define ADC2CF_AMP2GN__GAIN_0P5 0x00 ///< The on-chip PGA gain is 0.5.      
#define ADC2CF_AMP2GN__GAIN_1   0x01 ///< The on-chip PGA gain is 1.        
#define ADC2CF_AMP2GN__GAIN_2   0x02 ///< The on-chip PGA gain is 2.        
#define ADC2CF_AMP2GN__GAIN_4   0x03 ///< The on-chip PGA gain is 4.        
                                                                            
#define ADC2CF_AD2SC__FMASK     0xF8 ///< SAR Clock Divider                 
#define ADC2CF_AD2SC__SHIFT     0x03 ///< SAR Clock Divider                 
                                                                            
//------------------------------------------------------------------------------
// ADC2CN Enums (ADC2 Control @ 0xE8)
//------------------------------------------------------------------------------
#define ADC2CN_ADWINT__BMASK     0x01 ///< Window Compare Interrupt Flag                     
#define ADC2CN_ADWINT__SHIFT     0x00 ///< Window Compare Interrupt Flag                     
#define ADC2CN_ADWINT__NOT_SET   0x00 ///< An ADC window compare event did not occur.        
#define ADC2CN_ADWINT__SET       0x01 ///< An ADC window compare event occurred.             
                                                                                             
#define ADC2CN_ADCM__FMASK       0x0E ///< Start of Conversion Mode Select                   
#define ADC2CN_ADCM__SHIFT       0x01 ///< Start of Conversion Mode Select                   
#define ADC2CN_ADCM__ADBUSY      0x00 ///< ADC2 conversion initiated on write of 1 to ADBUSY.
#define ADC2CN_ADCM__TIMER3      0x02 ///< ADC2 conversion initiated on overflow of Timer 3. 
#define ADC2CN_ADCM__CNVSTR      0x04 ///< ADC2 conversion initiated on rising edge of       
                                      ///< CNVSTR0.                                          
#define ADC2CN_ADCM__TIMER2      0x06 ///< ADC2 conversion initiated on overflow of Timer 2. 
#define ADC2CN_ADCM__ADC0_ADBUSY 0x08 ///< ADC2 conversion initiated on write of 1 to ADC0's 
                                      ///< ADBUSY.                                           
                                                                                             
#define ADC2CN_ADBUSY__BMASK     0x10 ///< ADC Busy                                          
#define ADC2CN_ADBUSY__SHIFT     0x04 ///< ADC Busy                                          
#define ADC2CN_ADBUSY__NOT_SET   0x00 ///< An ADC2 conversion is not currently in progress.  
#define ADC2CN_ADBUSY__SET       0x10 ///< ADC2 conversion is in progress or start an ADC2   
                                      ///< conversion.                                       
                                                                                             
#define ADC2CN_ADINT__BMASK      0x20 ///< Conversion Complete Interrupt Flag                
#define ADC2CN_ADINT__SHIFT      0x05 ///< Conversion Complete Interrupt Flag                
#define ADC2CN_ADINT__NOT_SET    0x00 ///< ADC2 has not completed a conversion since the last
                                      ///< time ADINT was cleared.                           
#define ADC2CN_ADINT__SET        0x20 ///< ADC2 completed a data conversion.                 
                                                                                             
#define ADC2CN_ADTM__BMASK       0x40 ///< ADC Track Mode                                    
#define ADC2CN_ADTM__SHIFT       0x06 ///< ADC Track Mode                                    
#define ADC2CN_ADTM__CONTINUOUS  0x00 ///< When the ADC is enabled, tracking is continuous   
                                      ///< unless a conversion is in process.                
#define ADC2CN_ADTM__ADJUSTABLE  0x40 ///< Tracking defined by the ADCM field.               
                                                                                             
#define ADC2CN_ADEN__BMASK       0x80 ///< ADC Enable                                        
#define ADC2CN_ADEN__SHIFT       0x07 ///< ADC Enable                                        
#define ADC2CN_ADEN__DISABLED    0x00 ///< Disable ADC2 (low-power shutdown).                
#define ADC2CN_ADEN__ENABLED     0x80 ///< Enable ADC2 (active and ready for data            
                                      ///< conversions).                                     
                                                                                             
//------------------------------------------------------------------------------
// ADC2GT Enums (ADC2 Greater-Than Data Byte @ 0xC4)
//------------------------------------------------------------------------------
#define ADC2GT_ADC2GTH__FMASK 0xFF ///< Greater-Than Byte
#define ADC2GT_ADC2GTH__SHIFT 0x00 ///< Greater-Than Byte
                                                         
//------------------------------------------------------------------------------
// ADC2LT Enums (ADC2 Less-Than Data Byte @ 0xC6)
//------------------------------------------------------------------------------
#define ADC2LT_ADC2LTH__FMASK 0xFF ///< Less-Than Data Byte
#define ADC2LT_ADC2LTH__SHIFT 0x00 ///< Less-Than Data Byte
                                                           
//------------------------------------------------------------------------------
// AMX2CF Enums (AMUX2 Configuration @ 0xBA)
//------------------------------------------------------------------------------
#define AMX2CF_AIN01IC__BMASK        0x01 ///< AIN2.0, AIN2.1 Input Pair Configuration         
#define AMX2CF_AIN01IC__SHIFT        0x00 ///< AIN2.0, AIN2.1 Input Pair Configuration         
#define AMX2CF_AIN01IC__SINGLE_ENDED 0x00 ///< AIN2.0 and AIN2.1 are independent single-ended  
                                          ///< inputs.                                         
#define AMX2CF_AIN01IC__DIFFERENTIAL 0x01 ///< AIN2.0 and AIN2.1 are a (respectively) positive,
                                          ///< negative differential input pair.               
                                                                                               
#define AMX2CF_AIN23IC__BMASK        0x02 ///< AIN2.2, AIN2.3 Input Pair Configuration         
#define AMX2CF_AIN23IC__SHIFT        0x01 ///< AIN2.2, AIN2.3 Input Pair Configuration         
#define AMX2CF_AIN23IC__SINGLE_ENDED 0x00 ///< AIN2.2 and AIN2.3 are independent single-ended  
                                          ///< inputs.                                         
#define AMX2CF_AIN23IC__DIFFERENTIAL 0x02 ///< AIN2.2 and AIN2.3 are a (respectively) positive,
                                          ///< negative differential input pair.               
                                                                                               
#define AMX2CF_AIN45IC__BMASK        0x04 ///< AIN2.4, AIN2.5 Input Pair Configuration         
#define AMX2CF_AIN45IC__SHIFT        0x02 ///< AIN2.4, AIN2.5 Input Pair Configuration         
#define AMX2CF_AIN45IC__SINGLE_ENDED 0x00 ///< AIN2.4 and AIN2.5 are independent single-ended  
                                          ///< inputs.                                         
#define AMX2CF_AIN45IC__DIFFERENTIAL 0x04 ///< AIN2.4 and AIN2.5 are a (respectively) positive,
                                          ///< negative differential input pair.               
                                                                                               
#define AMX2CF_AIN67IC__BMASK        0x08 ///< AIN2.6, AIN2.7 Input Pair Configuration         
#define AMX2CF_AIN67IC__SHIFT        0x03 ///< AIN2.6, AIN2.7 Input Pair Configuration         
#define AMX2CF_AIN67IC__SINGLE_ENDED 0x00 ///< AIN2.6 and AIN2.7 are independent single-ended  
                                          ///< inputs.                                         
#define AMX2CF_AIN67IC__DIFFERENTIAL 0x08 ///< AIN2.6 and AIN2.7 are a (respectively) positive,
                                          ///< negative differential input pair.               
                                                                                               
//------------------------------------------------------------------------------
// AMX2SL Enums (AMUX2 Channel Select @ 0xBB)
//------------------------------------------------------------------------------
#define AMX2SL_ADC2AD__FMASK  0x07 ///< ADC2 Input Selection
#define AMX2SL_ADC2AD__SHIFT  0x00 ///< ADC2 Input Selection
#define AMX2SL_ADC2AD__ADC2P0 0x00 ///< Select ADC2.0.      
#define AMX2SL_ADC2AD__ADC2P1 0x01 ///< Select ADC2.1.      
#define AMX2SL_ADC2AD__ADC2P2 0x02 ///< Select ADC2.2.      
#define AMX2SL_ADC2AD__ADC2P3 0x03 ///< Select ADC2.3.      
#define AMX2SL_ADC2AD__ADC2P4 0x04 ///< Select ADC2.4.      
#define AMX2SL_ADC2AD__ADC2P5 0x05 ///< Select ADC2.5.      
#define AMX2SL_ADC2AD__ADC2P6 0x06 ///< Select ADC2.6.      
#define AMX2SL_ADC2AD__ADC2P7 0x07 ///< Select ADC2.7.      
                                                            
//------------------------------------------------------------------------------
// ADC0CF Enums (ADC0 Configuration @ 0xBC)
//------------------------------------------------------------------------------
#define ADC0CF_AMP0GN__FMASK    0x07 ///< ADC0 Internal Amplifier Gain (PGA)
#define ADC0CF_AMP0GN__SHIFT    0x00 ///< ADC0 Internal Amplifier Gain (PGA)
#define ADC0CF_AMP0GN__GAIN_1   0x00 ///< The on-chip PGA gain is 1.        
#define ADC0CF_AMP0GN__GAIN_2   0x01 ///< The on-chip PGA gain is 2.        
#define ADC0CF_AMP0GN__GAIN_4   0x02 ///< The on-chip PGA gain is 4.        
#define ADC0CF_AMP0GN__GAIN_8   0x03 ///< The on-chip PGA gain is 8.        
#define ADC0CF_AMP0GN__GAIN_16  0x04 ///< The on-chip PGA gain is 16.       
#define ADC0CF_AMP0GN__GAIN_0P5 0x06 ///< The on-chip PGA gain is 0.5.      
                                                                            
#define ADC0CF_AD0SC__FMASK     0xF8 ///< SAR Clock Divider                 
#define ADC0CF_AD0SC__SHIFT     0x03 ///< SAR Clock Divider                 
                                                                            
//------------------------------------------------------------------------------
// ADC0CN Enums (ADC0 Control @ 0xE8)
//------------------------------------------------------------------------------
#define ADC0CN_ADLJST__BMASK           0x01 ///< ADC Left Justify Select                           
#define ADC0CN_ADLJST__SHIFT           0x00 ///< ADC Left Justify Select                           
#define ADC0CN_ADLJST__RIGHT_JUSTIFIED 0x00 ///< Data in the ADC0H:ADC0L registers is right-       
                                            ///< justified.                                        
#define ADC0CN_ADLJST__LEFT_JUSTIFIED  0x01 ///< Data in the ADC0H:ADC0L registers is left-        
                                            ///< justified.                                        
                                                                                                   
#define ADC0CN_ADWINT__BMASK           0x02 ///< Window Compare Interrupt Flag                     
#define ADC0CN_ADWINT__SHIFT           0x01 ///< Window Compare Interrupt Flag                     
#define ADC0CN_ADWINT__NOT_SET         0x00 ///< An ADC window compare event did not occur.        
#define ADC0CN_ADWINT__SET             0x02 ///< An ADC window compare event occurred.             
                                                                                                   
#define ADC0CN_ADCM__FMASK             0x0C ///< Start of Conversion Mode Select                   
#define ADC0CN_ADCM__SHIFT             0x02 ///< Start of Conversion Mode Select                   
#define ADC0CN_ADCM__ADBUSY            0x00 ///< ADC0 conversion initiated on write of 1 to ADBUSY.
#define ADC0CN_ADCM__TIMER3            0x04 ///< ADC0 conversion initiated on overflow of Timer 3. 
#define ADC0CN_ADCM__CNVSTR            0x08 ///< ADC0 conversion initiated on rising edge of       
                                            ///< CNVSTR0.                                          
#define ADC0CN_ADCM__TIMER2            0x0C ///< ADC0 conversion initiated on overflow of Timer 2. 
                                                                                                   
#define ADC0CN_ADBUSY__BMASK           0x10 ///< ADC Busy                                          
#define ADC0CN_ADBUSY__SHIFT           0x04 ///< ADC Busy                                          
#define ADC0CN_ADBUSY__NOT_SET         0x00 ///< An ADC0 conversion is not currently in progress.  
#define ADC0CN_ADBUSY__SET             0x10 ///< ADC0 conversion is in progress or start an ADC0   
                                            ///< conversion.                                       
                                                                                                   
#define ADC0CN_ADINT__BMASK            0x20 ///< Conversion Complete Interrupt Flag                
#define ADC0CN_ADINT__SHIFT            0x05 ///< Conversion Complete Interrupt Flag                
#define ADC0CN_ADINT__NOT_SET          0x00 ///< ADC0 has not completed a conversion since the last
                                            ///< time ADINT was cleared.                           
#define ADC0CN_ADINT__SET              0x20 ///< ADC0 completed a data conversion.                 
                                                                                                   
#define ADC0CN_ADTM__BMASK             0x40 ///< ADC Track Mode                                    
#define ADC0CN_ADTM__SHIFT             0x06 ///< ADC Track Mode                                    
#define ADC0CN_ADTM__CONTINUOUS        0x00 ///< When the ADC is enabled, tracking is continuous   
                                            ///< unless a conversion is in process.                
#define ADC0CN_ADTM__ADJUSTABLE        0x40 ///< Tracking defined by the ADCM field.               
                                                                                                   
#define ADC0CN_ADEN__BMASK             0x80 ///< ADC Enable                                        
#define ADC0CN_ADEN__SHIFT             0x07 ///< ADC Enable                                        
#define ADC0CN_ADEN__DISABLED          0x00 ///< Disable ADC0 (low-power shutdown).                
#define ADC0CN_ADEN__ENABLED           0x80 ///< Enable ADC0 (active and ready for data            
                                            ///< conversions).                                     
                                                                                                   
//------------------------------------------------------------------------------
// ADC0GTH Enums (ADC0 Greater-Than High Byte @ 0xC5)
//------------------------------------------------------------------------------
#define ADC0GTH_ADC0GTH__FMASK 0xFF ///< Greater-Than High Byte
#define ADC0GTH_ADC0GTH__SHIFT 0x00 ///< Greater-Than High Byte
                                                               
//------------------------------------------------------------------------------
// ADC0GTL Enums (ADC0 Greater-Than Low Byte @ 0xC4)
//------------------------------------------------------------------------------
#define ADC0GTL_ADC0GTL__FMASK 0xFF ///< Greater-Than Low Byte
#define ADC0GTL_ADC0GTL__SHIFT 0x00 ///< Greater-Than Low Byte
                                                              
//------------------------------------------------------------------------------
// ADC0H Enums (ADC0 Data Word High Byte @ 0xBF)
//------------------------------------------------------------------------------
#define ADC0H_ADC0H__FMASK 0xFF ///< Data Word High Byte
#define ADC0H_ADC0H__SHIFT 0x00 ///< Data Word High Byte
                                                        
//------------------------------------------------------------------------------
// ADC0L Enums (ADC0 Data Word Low Byte @ 0xBE)
//------------------------------------------------------------------------------
#define ADC0L_ADC0L__FMASK 0xFF ///< Data Word Low Byte
#define ADC0L_ADC0L__SHIFT 0x00 ///< Data Word Low Byte
                                                       
//------------------------------------------------------------------------------
// ADC0LTH Enums (ADC0 Less-Than High Byte @ 0xC7)
//------------------------------------------------------------------------------
#define ADC0LTH_ADC0LTH__FMASK 0xFF ///< Less-Than High Byte
#define ADC0LTH_ADC0LTH__SHIFT 0x00 ///< Less-Than High Byte
                                                            
//------------------------------------------------------------------------------
// ADC0LTL Enums (ADC0 Less-Than Low Byte @ 0xC6)
//------------------------------------------------------------------------------
#define ADC0LTL_ADC0LTL__FMASK 0xFF ///< Less-Than Low Byte
#define ADC0LTL_ADC0LTL__SHIFT 0x00 ///< Less-Than Low Byte
                                                           
//------------------------------------------------------------------------------
// AMX0CF Enums (AMUX0 Configuration @ 0xBA)
//------------------------------------------------------------------------------
#define AMX0CF_AIN01IC__BMASK        0x01 ///< AIN0.0, AIN0.1 Input Pair Configuration         
#define AMX0CF_AIN01IC__SHIFT        0x00 ///< AIN0.0, AIN0.1 Input Pair Configuration         
#define AMX0CF_AIN01IC__SINGLE_ENDED 0x00 ///< AIN0.0 and AIN0.1 are independent single-ended  
                                          ///< inputs.                                         
#define AMX0CF_AIN01IC__DIFFERENTIAL 0x01 ///< AIN0.0 and AIN0.1 are a (respectively) positive,
                                          ///< negative differential input pair.               
                                                                                               
#define AMX0CF_AIN23IC__BMASK        0x02 ///< AIN0.2, AIN0.3 Input Pair Configuration         
#define AMX0CF_AIN23IC__SHIFT        0x01 ///< AIN0.2, AIN0.3 Input Pair Configuration         
#define AMX0CF_AIN23IC__SINGLE_ENDED 0x00 ///< AIN0.2 and AIN0.3 are independent single-ended  
                                          ///< inputs.                                         
#define AMX0CF_AIN23IC__DIFFERENTIAL 0x02 ///< AIN0.2 and AIN0.3 are a (respectively) positive,
                                          ///< negative differential input pair.               
                                                                                               
#define AMX0CF_AIN45IC__BMASK        0x04 ///< AIN0.4, AIN0.5 Input Pair Configuration         
#define AMX0CF_AIN45IC__SHIFT        0x02 ///< AIN0.4, AIN0.5 Input Pair Configuration         
#define AMX0CF_AIN45IC__SINGLE_ENDED 0x00 ///< AIN0.4 and AIN0.5 are independent single-ended  
                                          ///< inputs.                                         
#define AMX0CF_AIN45IC__DIFFERENTIAL 0x04 ///< AIN0.4 and AIN0.5 are a (respectively) positive,
                                          ///< negative differential input pair.               
                                                                                               
#define AMX0CF_AIN67IC__BMASK        0x08 ///< AIN0.6, AIN0.7 Input Pair Configuration         
#define AMX0CF_AIN67IC__SHIFT        0x03 ///< AIN0.6, AIN0.7 Input Pair Configuration         
#define AMX0CF_AIN67IC__SINGLE_ENDED 0x00 ///< AIN0.6 and AIN0.7 are independent single-ended  
                                          ///< inputs.                                         
#define AMX0CF_AIN67IC__DIFFERENTIAL 0x08 ///< AIN0.6 and AIN0.7 are a (respectively) positive,
                                          ///< negative differential input pair.               
                                                                                               
//------------------------------------------------------------------------------
// AMX0SL Enums (AMUX0 Channel Select @ 0xBB)
//------------------------------------------------------------------------------
#define AMX0SL_ADC0AD__FMASK  0x0F ///< ADC0 Input Selection
#define AMX0SL_ADC0AD__SHIFT  0x00 ///< ADC0 Input Selection
#define AMX0SL_ADC0AD__ADC0P0 0x00 ///< Select ADC0.0.      
#define AMX0SL_ADC0AD__ADC0P1 0x01 ///< Select ADC0.1.      
#define AMX0SL_ADC0AD__ADC0P2 0x02 ///< Select ADC0.2.      
#define AMX0SL_ADC0AD__ADC0P3 0x03 ///< Select ADC0.3.      
#define AMX0SL_ADC0AD__ADC0P4 0x04 ///< Select ADC0.4.      
#define AMX0SL_ADC0AD__ADC0P5 0x05 ///< Select ADC0.5.      
#define AMX0SL_ADC0AD__ADC0P6 0x06 ///< Select ADC0.6.      
#define AMX0SL_ADC0AD__ADC0P7 0x07 ///< Select ADC0.7.      
#define AMX0SL_ADC0AD__TEMP   0x08 ///< Temperature sensor. 
                                                            
//------------------------------------------------------------------------------
// CCH0CN Enums (Cache Control @ 0xA1)
//------------------------------------------------------------------------------
#define CCH0CN_CHBLKW__BMASK                0x01 ///< Block Write Enable                                
#define CCH0CN_CHBLKW__SHIFT                0x00 ///< Block Write Enable                                
#define CCH0CN_CHBLKW__BLOCK_WRITE_DISABLED 0x00 ///< Each byte of a firmware flash write is written    
                                                 ///< individually.                                     
#define CCH0CN_CHBLKW__BLOCK_WRITE_ENABLED  0x01 ///< Flash bytes are written in groups of four.        
                                                                                                        
#define CCH0CN_CHMOVC__BMASK                0x02 ///< Cache MOVC Enable                                 
#define CCH0CN_CHMOVC__SHIFT                0x01 ///< Cache MOVC Enable                                 
#define CCH0CN_CHMOVC__DISABLED             0x00 ///< Data requested by MOVC instructions will not be   
                                                 ///< cached.                                           
#define CCH0CN_CHMOVC__ENABLED              0x02 ///< Data requested by MOVC instructions will be loaded
                                                 ///< into cache memory.                                
                                                                                                        
#define CCH0CN_CHISR__BMASK                 0x04 ///< Cache ISR Enable                                  
#define CCH0CN_CHISR__SHIFT                 0x02 ///< Cache ISR Enable                                  
#define CCH0CN_CHISR__DISABLED              0x00 ///< Instructions in ISRs will not be loaded into cache
                                                 ///< memory.                                           
#define CCH0CN_CHISR__ENABLED               0x04 ///< Instructions in ISRs can be cached.               
                                                                                                        
#define CCH0CN_CHRETI__BMASK                0x08 ///< Cache RETI Destination Enable                     
#define CCH0CN_CHRETI__SHIFT                0x03 ///< Cache RETI Destination Enable                     
#define CCH0CN_CHRETI__DISABLED             0x00 ///< Destinations of RETI instructions will not be     
                                                 ///< cached.                                           
#define CCH0CN_CHRETI__ENABLED              0x08 ///< RETI destinations will be cached.                 
                                                                                                        
#define CCH0CN_CHFLSH__BMASK                0x10 ///< Cache Flush                                       
#define CCH0CN_CHFLSH__SHIFT                0x04 ///< Cache Flush                                       
#define CCH0CN_CHFLSH__DO_NOT_FLUSH         0x00 ///< Do not flush the cache.                           
#define CCH0CN_CHFLSH__FLUSH                0x10 ///< Flush the cache.                                  
                                                                                                        
#define CCH0CN_CHPFEN__BMASK                0x20 ///< Cache Prefetch Enable                             
#define CCH0CN_CHPFEN__SHIFT                0x05 ///< Cache Prefetch Enable                             
#define CCH0CN_CHPFEN__PREFETCH_DISABLED    0x00 ///< Disable the prefetch engine.                      
#define CCH0CN_CHPFEN__PREFETCH_ENABLED     0x20 ///< Enable the prefetch engine.                       
                                                                                                        
#define CCH0CN_CHRDEN__BMASK                0x40 ///< Cache Read Enable                                 
#define CCH0CN_CHRDEN__SHIFT                0x06 ///< Cache Read Enable                                 
#define CCH0CN_CHRDEN__READ_DISABLED        0x00 ///< All instruction data comes from Flash memory or   
                                                 ///< the prefetch engine.                              
#define CCH0CN_CHRDEN__READ_ENABLED         0x40 ///< Instruction data is obtained from cache (when     
                                                 ///< available).                                       
                                                                                                        
#define CCH0CN_CHWREN__BMASK                0x80 ///< Cache Write Enable                                
#define CCH0CN_CHWREN__SHIFT                0x07 ///< Cache Write Enable                                
#define CCH0CN_CHWREN__WRITE_DISABLED       0x00 ///< Cache contents are not allowed to change, except  
                                                 ///< during flash writes/erasures or cache locks.      
#define CCH0CN_CHWREN__WRITE_ENABLED        0x80 ///< Writes to cache memory are allowed.               
                                                                                                        
//------------------------------------------------------------------------------
// CCH0LC Enums (Cache Lock Control @ 0xA3)
//------------------------------------------------------------------------------
#define CCH0LC_CHSLOT__FMASK    0x3F ///< Cache Slot Pointer                               
#define CCH0LC_CHSLOT__SHIFT    0x00 ///< Cache Slot Pointer                               
                                                                                           
#define CCH0LC_CHPOP__BMASK     0x40 ///< Cache Pop                                        
#define CCH0LC_CHPOP__SHIFT     0x06 ///< Cache Pop                                        
#define CCH0LC_CHPOP__NOT_SET   0x00 ///< Do not increment CHSLOT.                         
#define CCH0LC_CHPOP__SET       0x40 ///< Increment CHSLOT and unlock that location.       
                                                                                           
#define CCH0LC_CHPUSH__BMASK    0x80 ///< Cache Push Enable                                
#define CCH0LC_CHPUSH__SHIFT    0x07 ///< Cache Push Enable                                
#define CCH0LC_CHPUSH__DISABLED 0x00 ///< Disable cache push operations.                   
#define CCH0LC_CHPUSH__ENABLED  0x80 ///< Enable cache push operations. When a MOVC read is
                                     ///< executed, the requested 4-byte segment containing
                                     ///< the data is locked into the cache at the location
                                     ///< indicated by CHSLOT, and CHSLOT is decremented.  
                                                                                           
//------------------------------------------------------------------------------
// CCH0MA Enums (Cache Miss Accumulator @ 0x9A)
//------------------------------------------------------------------------------
#define CCH0MA_CHMSCTH__FMASK      0x7F ///< Cache Miss Penalty Accumulator               
#define CCH0MA_CHMSCTH__SHIFT      0x00 ///< Cache Miss Penalty Accumulator               
                                                                                          
#define CCH0MA_CHMSOV__BMASK       0x80 ///< Cache Miss Penalty Overflow                  
#define CCH0MA_CHMSOV__SHIFT       0x07 ///< Cache Miss Penalty Overflow                  
#define CCH0MA_CHMSOV__NO_OVERFLOW 0x00 ///< The cache miss penalty accumulator has not   
                                        ///< overflowed since it was last written.        
#define CCH0MA_CHMSOV__OVERFLOW    0x80 ///< The cache miss penalty accumulator overflowed
                                        ///< since it was last written.                   
                                                                                          
//------------------------------------------------------------------------------
// CCH0TN Enums (Cache Tuning @ 0xA2)
//------------------------------------------------------------------------------
#define CCH0TN_CHMSTH__FMASK         0x03 ///< Cache Miss Penalty Threshold                      
#define CCH0TN_CHMSTH__SHIFT         0x00 ///< Cache Miss Penalty Threshold                      
#define CCH0TN_CHMSTH__0_CLOCKS      0x00 ///< Data that takes longer than 0 clocks to obtain    
                                          ///< will be cached.                                   
#define CCH0TN_CHMSTH__1_CLOCK       0x01 ///< Data that takes longer than 1 clock to obtain will
                                          ///< be cached.                                        
#define CCH0TN_CHMSTH__2_CLOCKS      0x02 ///< Data that takes longer than 2 clocks to obtain    
                                          ///< will be cached.                                   
#define CCH0TN_CHMSTH__3_CLOCKS      0x03 ///< Data that takes longer than 3 clocks to obtain    
                                          ///< will be cached.                                   
                                                                                                 
#define CCH0TN_CHFIXM__BMASK         0x04 ///< Cache Fix MOVC Enable                             
#define CCH0TN_CHFIXM__SHIFT         0x02 ///< Cache Fix MOVC Enable                             
#define CCH0TN_CHFIXM__USE_ALGORITHM 0x00 ///< MOVC data is written according to the current     
                                          ///< algorithm selected by the CHALGM bit.             
#define CCH0TN_CHFIXM__ALWAYS_SLOT_0 0x04 ///< MOVC data is always written to cache slot 0.      
                                                                                                 
#define CCH0TN_CHALGM__BMASK         0x08 ///< Cache Algorithm Select                            
#define CCH0TN_CHALGM__SHIFT         0x03 ///< Cache Algorithm Select                            
#define CCH0TN_CHALGM__REBOUND       0x00 ///< Cache uses Rebound algorithm.                     
#define CCH0TN_CHALGM__PSEUDO_RANDOM 0x08 ///< Cache uses Pseudo-random algorithm.               
                                                                                                 
#define CCH0TN_CHMSCTL__FMASK        0xF0 ///< Cache Miss Penalty Accumulator                    
#define CCH0TN_CHMSCTL__SHIFT        0x04 ///< Cache Miss Penalty Accumulator                    
                                                                                                 
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
// PSBANK Enums (Program Space Bank Select @ 0xB1)
//------------------------------------------------------------------------------
#define PSBANK_IFBANK__FMASK 0x03 ///< Instruction Fetch Operations Bank Select         
#define PSBANK_IFBANK__SHIFT 0x00 ///< Instruction Fetch Operations Bank Select         
#define PSBANK_IFBANK__BANK0 0x00 ///< Instructions fetch from Bank 0 (note that Bank 0 
                                  ///< is also mapped between 0x0000 to 0x7FFF).        
#define PSBANK_IFBANK__BANK1 0x01 ///< Instructions fetch from Bank 1.                  
#define PSBANK_IFBANK__BANK2 0x02 ///< Instructions fetch from Bank 2.                  
#define PSBANK_IFBANK__BANK3 0x03 ///< Instructions fetch from Bank 3.                  
                                                                                        
#define PSBANK_COBANK__FMASK 0x30 ///< Constant Operations Bank Select                  
#define PSBANK_COBANK__SHIFT 0x04 ///< Constant Operations Bank Select                  
#define PSBANK_COBANK__BANK0 0x00 ///< Constant operations target Bank 0 (note that Bank
                                  ///< 0 is also mapped between 0x0000 to 0x7FFF).      
#define PSBANK_COBANK__BANK1 0x10 ///< Constant operations target Bank 1.               
#define PSBANK_COBANK__BANK2 0x20 ///< Constant operations target Bank 2.               
#define PSBANK_COBANK__BANK3 0x30 ///< Constant operations target Bank 2.               
                                                                                        
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
// SP Enums (Stack Pointer @ 0x81)
//------------------------------------------------------------------------------
#define SP_SP__FMASK 0xFF ///< Stack Pointer
#define SP_SP__SHIFT 0x00 ///< Stack Pointer
                                            
//------------------------------------------------------------------------------
// CLKSEL Enums (Clock Select @ 0x97)
//------------------------------------------------------------------------------
#define CLKSEL_CLKSL__FMASK         0x03 ///< Clock Source Select                             
#define CLKSEL_CLKSL__SHIFT         0x00 ///< Clock Source Select                             
#define CLKSEL_CLKSL__HFOSC         0x00 ///< Clock derived from the Internal High-Frequency  
                                         ///< Oscillator and scaled as per the IFCN bits in   
                                         ///< OSCICN.                                         
#define CLKSEL_CLKSL__EXTOSC        0x01 ///< Clock derived from the External Oscillator clock
                                         ///< circuit.                                        
#define CLKSEL_CLKSL__PLL           0x02 ///< Clock derived from the PLL.                     
                                                                                              
#define CLKSEL_CLKDIV__FMASK        0x30 ///< Output SYSCLK Divide Factor                     
#define CLKSEL_CLKDIV__SHIFT        0x04 ///< Output SYSCLK Divide Factor                     
#define CLKSEL_CLKDIV__SYSCLK_DIV_1 0x00 ///< Output will be SYSCLK.                          
#define CLKSEL_CLKDIV__SYSCLK_DIV_2 0x10 ///< Output will be SYSCLK / 2.                      
#define CLKSEL_CLKDIV__SYSCLK_DIV_4 0x20 ///< Output will be SYSCLK / 4.                      
#define CLKSEL_CLKDIV__SYSCLK_DIV_8 0x30 ///< Output will be SYSCLK / 8.                      
                                                                                              
//------------------------------------------------------------------------------
// CPT0CN Enums (Comparator 0 Control @ 0x88)
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
// CPT0MD Enums (Comparator 0 Mode @ 0x89)
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
// CPT1CN Enums (Comparator 1 Control @ 0x88)
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
// CPT1MD Enums (Comparator 1 Mode @ 0x89)
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
// DAC0CN Enums (DAC0 Control @ 0xD4)
//------------------------------------------------------------------------------
#define DAC0CN_DAC0DF__FMASK           0x07 ///< DAC0 Data Format                                  
#define DAC0CN_DAC0DF__SHIFT           0x00 ///< DAC0 Data Format                                  
#define DAC0CN_DAC0DF__RIGHT_JUSTIFIED 0x00 ///< Right justified. The most significant nibble of   
                                            ///< the DAC0 Data Word is in DAC0H[3:0], while the    
                                            ///< least significant byte is in DAC0L.               
#define DAC0CN_DAC0DF__RIGHT_SHIFT_1   0x01 ///< Right justified. Shifted left by 1 bit. The most  
                                            ///< significant 5 bits of the DAC0 Data Word is in    
                                            ///< DAC0H[4:0], while the least significant 7 bits are
                                            ///< in DAC0L[7:1].                                    
#define DAC0CN_DAC0DF__RIGHT_SHIFT_2   0x02 ///< Right justified. Shifted left by 2 bits. The most 
                                            ///< significant 6 bits of the DAC0 Data Word is in    
                                            ///< DAC0H[5:0], while the least significant 6 bits are
                                            ///< in DAC0L[7:2].                                    
#define DAC0CN_DAC0DF__RIGHT_SHIFT_3   0x03 ///< Right justified. Shifted left by 3 bits. The most 
                                            ///< significant 7 bits of the DAC0 Data Word is in    
                                            ///< DAC0H[6:0], while the least significant 5 bits are
                                            ///< in DAC0L[7:3].                                    
#define DAC0CN_DAC0DF__LEFT_NO_SHIFT   0x04 ///< Left justified. The most significant 8-bits of the
                                            ///< DAC0 Data Word is in DAC0H[7:0], while the least  
                                            ///< significant 4-bits are in DAC0L[7:4].             
                                                                                                   
#define DAC0CN_DAC0MD__FMASK           0x18 ///< DAC0 Mode                                         
#define DAC0CN_DAC0MD__SHIFT           0x03 ///< DAC0 Mode                                         
#define DAC0CN_DAC0MD__DAC0H           0x00 ///< DAC output updates occur on a write to DAC0H.     
#define DAC0CN_DAC0MD__TIMER3          0x08 ///< DAC output updates occur on a Timer 3 overflow.   
#define DAC0CN_DAC0MD__TIMER4          0x10 ///< DAC output updates occur on a Timer 4 overflow.   
#define DAC0CN_DAC0MD__TIMER2          0x18 ///< DAC output updates occur on a Timer 2 overflow.   
                                                                                                   
#define DAC0CN_DAC0EN__BMASK           0x80 ///< DAC0 Enable                                       
#define DAC0CN_DAC0EN__SHIFT           0x07 ///< DAC0 Enable                                       
#define DAC0CN_DAC0EN__DISABLED        0x00 ///< DAC0 disabled. DAC0 output pin is disabled; DAC0  
                                            ///< is in low-power shutdown mode.                    
#define DAC0CN_DAC0EN__ENABLED         0x80 ///< DAC0 enabled. DAC0 output pin is active; DAC0 is  
                                            ///< operational.                                      
                                                                                                   
//------------------------------------------------------------------------------
// DAC0H Enums (DAC0 Data High Byte @ 0xD3)
//------------------------------------------------------------------------------
#define DAC0H_DAC0H__FMASK 0xFF ///< DAC0 Data High
#define DAC0H_DAC0H__SHIFT 0x00 ///< DAC0 Data High
                                                   
//------------------------------------------------------------------------------
// DAC0L Enums (DAC0 Data Low Byte @ 0xD2)
//------------------------------------------------------------------------------
#define DAC0L_DAC0L__FMASK 0xFF ///< DAC0 Data Low
#define DAC0L_DAC0L__SHIFT 0x00 ///< DAC0 Data Low
                                                  
//------------------------------------------------------------------------------
// DAC1CN Enums (DAC1 Control @ 0xD4)
//------------------------------------------------------------------------------
#define DAC1CN_DAC1DF__FMASK           0x07 ///< DAC1 Data Format                                  
#define DAC1CN_DAC1DF__SHIFT           0x00 ///< DAC1 Data Format                                  
#define DAC1CN_DAC1DF__RIGHT_JUSTIFIED 0x00 ///< Right justified. The most significant nibble of   
                                            ///< the DAC1 Data Word is in DAC1H[3:0], while the    
                                            ///< least significant byte is in DAC1L.               
#define DAC1CN_DAC1DF__RIGHT_SHIFT_1   0x01 ///< Right justified. Shifted left by 1 bit. The most  
                                            ///< significant 5 bits of the DAC1 Data Word is in    
                                            ///< DAC1H[4:0], while the least significant 7 bits are
                                            ///< in DAC1L[7:1].                                    
#define DAC1CN_DAC1DF__RIGHT_SHIFT_2   0x02 ///< Right justified. Shifted left by 2 bits. The most 
                                            ///< significant 6 bits of the DAC1 Data Word is in    
                                            ///< DAC1H[5:0], while the least significant 6 bits are
                                            ///< in DAC1L[7:2].                                    
#define DAC1CN_DAC1DF__RIGHT_SHIFT_3   0x03 ///< Right justified. Shifted left by 3 bits. The most 
                                            ///< significant 7 bits of the DAC1 Data Word is in    
                                            ///< DAC1H[6:0], while the least significant 5 bits are
                                            ///< in DAC1L[7:3].                                    
#define DAC1CN_DAC1DF__LEFT_NO_SHIFT   0x04 ///< Left justified. The most significant 8-bits of the
                                            ///< DAC1 Data Word is in DAC1H[7:0], while the least  
                                            ///< significant 4-bits are in DAC1L[7:4].             
                                                                                                   
#define DAC1CN_DAC1MD__FMASK           0x18 ///< DAC1 Mode                                         
#define DAC1CN_DAC1MD__SHIFT           0x03 ///< DAC1 Mode                                         
#define DAC1CN_DAC1MD__DAC1H           0x00 ///< DAC output updates occur on a write to DAC1H.     
#define DAC1CN_DAC1MD__TIMER3          0x08 ///< DAC output updates occur on a Timer 3 overflow.   
#define DAC1CN_DAC1MD__TIMER4          0x10 ///< DAC output updates occur on a Timer 4 overflow.   
#define DAC1CN_DAC1MD__TIMER2          0x18 ///< DAC output updates occur on a Timer 2 overflow.   
                                                                                                   
#define DAC1CN_DAC1EN__BMASK           0x80 ///< DAC1 Enable                                       
#define DAC1CN_DAC1EN__SHIFT           0x07 ///< DAC1 Enable                                       
#define DAC1CN_DAC1EN__DISABLED        0x00 ///< DAC1 disabled. DAC1 output pin is disabled; DAC1  
                                            ///< is in low-power shutdown mode.                    
#define DAC1CN_DAC1EN__ENABLED         0x80 ///< DAC1 enabled. DAC1 output pin is active; DAC1 is  
                                            ///< operational.                                      
                                                                                                   
//------------------------------------------------------------------------------
// DAC1H Enums (DAC1 Data High Byte @ 0xD3)
//------------------------------------------------------------------------------
#define DAC1H_DAC1H__FMASK 0xFF ///< DAC1 Data High
#define DAC1H_DAC1H__SHIFT 0x00 ///< DAC1 Data High
                                                   
//------------------------------------------------------------------------------
// DAC1L Enums (DAC1 Data Low Byte @ 0xD2)
//------------------------------------------------------------------------------
#define DAC1L_DAC1L__FMASK 0xFF ///< DAC1 Data Low
#define DAC1L_DAC1L__SHIFT 0x00 ///< DAC1 Data Low
                                                  
//------------------------------------------------------------------------------
// OSCXCN Enums (External Oscillator Control @ 0x8C)
//------------------------------------------------------------------------------
#define OSCXCN_XFCN__FMASK           0x07 ///< External Oscillator Frequency Control             
#define OSCXCN_XFCN__SHIFT           0x00 ///< External Oscillator Frequency Control             
#define OSCXCN_XFCN__MODE0           0x00 ///< Select external oscillator mode 0: Crystal        
                                          ///< frequency <= 32 kHz, RC/C frequency <= 25 kHz, C  
                                          ///< mode K factor = 0.87.                             
#define OSCXCN_XFCN__MODE1           0x01 ///< Select external oscillator mode 1: 32 kHz <       
                                          ///< Crystal frequency <= 84 kHz, 25 kHz < RC/C        
                                          ///< frequency <= 50 kHz, C mode K factor = 2.6.       
#define OSCXCN_XFCN__MODE2           0x02 ///< Select external oscillator mode 2: 84 kHz <       
                                          ///< Crystal frequency <= 225 kHz, 50 kHz < RC/C       
                                          ///< frequency <= 100 kHz, C mode K factor = 7.7.      
#define OSCXCN_XFCN__MODE3           0x03 ///< Select external oscillator mode 3: 225 kHz <      
                                          ///< Crystal frequency <= 590 kHz, 100 kHz < RC/C      
                                          ///< frequency <= 200 kHz, C mode K factor = 22.       
#define OSCXCN_XFCN__MODE4           0x04 ///< Select external oscillator mode 4: 590 kHz <      
                                          ///< Crystal frequency <= 1.5 MHz, 200 kHz < RC/C      
                                          ///< frequency <= 400 kHz, C mode K factor = 65.       
#define OSCXCN_XFCN__MODE5           0x05 ///< Select external oscillator mode 5: 1.5 MHz <      
                                          ///< Crystal frequency <= 4 MHz, 400 kHz < RC/C        
                                          ///< frequency <= 800 kHz, C mode K factor = 180.      
#define OSCXCN_XFCN__MODE6           0x06 ///< Select external oscillator mode 6: 4 MHz < Crystal
                                          ///< frequency <= 10 MHz, 800 kHz < RC/C frequency <=  
                                          ///< 1.6 MHz, C mode K factor = 664.                   
#define OSCXCN_XFCN__MODE7           0x07 ///< Select external oscillator mode 7: 10 MHz <       
                                          ///< Crystal frequency <= 30 MHz, 1.6 MHz < RC/C       
                                          ///< frequency <= 3.2 MHz, C mode K factor = 1590.     
                                                                                                 
#define OSCXCN_XOSCMD__FMASK         0x70 ///< External Oscillator Mode                          
#define OSCXCN_XOSCMD__SHIFT         0x04 ///< External Oscillator Mode                          
#define OSCXCN_XOSCMD__DISABLED      0x00 ///< External Oscillator circuit disabled.             
#define OSCXCN_XOSCMD__CMOS          0x20 ///< External CMOS Clock Mode.                         
#define OSCXCN_XOSCMD__CMOS_DIV_2    0x30 ///< External CMOS Clock Mode with divide by 2 stage.  
#define OSCXCN_XOSCMD__RC            0x40 ///< RC Oscillator Mode with divide by 2 stage.        
#define OSCXCN_XOSCMD__CRYSTAL       0x60 ///< Crystal Oscillator Mode.                          
#define OSCXCN_XOSCMD__CRYSTAL_DIV_2 0x70 ///< Crystal Oscillator Mode with divide by 2 stage.   
                                                                                                 
#define OSCXCN_XTLVLD__BMASK         0x80 ///< Crystal Oscillator Valid Flag                     
#define OSCXCN_XTLVLD__SHIFT         0x07 ///< Crystal Oscillator Valid Flag                     
#define OSCXCN_XTLVLD__NOT_SET       0x00 ///< External crystal is unused or not yet stable.     
#define OSCXCN_XTLVLD__SET           0x80 ///< External crystal is running and stable.           
                                                                                                 
//------------------------------------------------------------------------------
// FLACL Enums (Flash Access Limit @ 0xB7)
//------------------------------------------------------------------------------
#define FLACL_FLACL__FMASK 0xFF ///< Flash Access Limit
#define FLACL_FLACL__SHIFT 0x00 ///< Flash Access Limit
                                                       
//------------------------------------------------------------------------------
// FLSCL Enums (Flash Scale @ 0xB7)
//------------------------------------------------------------------------------
#define FLSCL_FLWE__BMASK                0x01 ///< Flash Write/Erase Enable     
#define FLSCL_FLWE__SHIFT                0x00 ///< Flash Write/Erase Enable     
#define FLSCL_FLWE__DISABLED             0x00 ///< Flash writes/erases disabled.
#define FLSCL_FLWE__ENABLED              0x01 ///< Flash writes/erases enabled. 
                                                                                
#define FLSCL_FLRT__FMASK                0x30 ///< Flash Read Timing            
#define FLSCL_FLRT__SHIFT                0x04 ///< Flash Read Timing            
#define FLSCL_FLRT__SYSCLK_BELOW_25_MHZ  0x00 ///< SYSCLK <= 25 MHz.            
#define FLSCL_FLRT__SYSCLK_BELOW_50_MHZ  0x10 ///< SYSCLK <= 50 MHz.            
#define FLSCL_FLRT__SYSCLK_BELOW_75_MHZ  0x20 ///< SYSCLK <= 75 MHz.            
#define FLSCL_FLRT__SYSCLK_BELOW_100_MHZ 0x30 ///< SYSCLK <= 100 MHz.           
                                                                                
//------------------------------------------------------------------------------
// FLSTAT Enums (Flash Status @ 0x88)
//------------------------------------------------------------------------------
#define FLSTAT_FLBUSY__BMASK   0x01 ///< Flash Busy                                 
#define FLSTAT_FLBUSY__SHIFT   0x00 ///< Flash Busy                                 
#define FLSTAT_FLBUSY__NOT_SET 0x00 ///< Flash is idle or reading.                  
#define FLSTAT_FLBUSY__SET     0x01 ///< Flash write/erase operation is currently in
                                    ///< progress.                                  
                                                                                    
//------------------------------------------------------------------------------
// PSCTL Enums (Program Store Control @ 0x8F)
//------------------------------------------------------------------------------
#define PSCTL_PSWE__BMASK               0x01 ///< Program Store Write Enable                      
#define PSCTL_PSWE__SHIFT               0x00 ///< Program Store Write Enable                      
#define PSCTL_PSWE__WRITE_DISABLED      0x00 ///< Writes to flash program memory disabled.        
#define PSCTL_PSWE__WRITE_ENABLED       0x01 ///< Writes to flash program memory enabled; the MOVX
                                             ///< write instruction targets flash memory.         
                                                                                                  
#define PSCTL_PSEE__BMASK               0x02 ///< Program Store Erase Enable                      
#define PSCTL_PSEE__SHIFT               0x01 ///< Program Store Erase Enable                      
#define PSCTL_PSEE__ERASE_DISABLED      0x00 ///< Flash program memory erasure disabled.          
#define PSCTL_PSEE__ERASE_ENABLED       0x02 ///< Flash program memory erasure enabled.           
                                                                                                  
#define PSCTL_SFLE__BMASK               0x04 ///< Scratchpad Flash Memory Access Enable           
#define PSCTL_SFLE__SHIFT               0x02 ///< Scratchpad Flash Memory Access Enable           
#define PSCTL_SFLE__SCRATCHPAD_DISABLED 0x00 ///< Flash access from user software directed to the 
                                             ///< Program/Data flash sector.                      
#define PSCTL_SFLE__SCRATCHPAD_ENABLED  0x04 ///< Flash access from user software directed to the 
                                             ///< two 128 byte Scratchpad sectors.                
                                                                                                  
//------------------------------------------------------------------------------
// OSCICL Enums (High Frequency Oscillator Calibration @ 0x8B)
//------------------------------------------------------------------------------
#define OSCICL_OSCICL__FMASK 0xFF ///< Internal Oscillator Calibration
#define OSCICL_OSCICL__SHIFT 0x00 ///< Internal Oscillator Calibration
                                                                      
//------------------------------------------------------------------------------
// OSCICN Enums (High Frequency Oscillator Control @ 0x8A)
//------------------------------------------------------------------------------
#define OSCICN_IFCN__FMASK       0x03 ///< Oscillator Frequency Divider Control             
#define OSCICN_IFCN__SHIFT       0x00 ///< Oscillator Frequency Divider Control             
#define OSCICN_IFCN__HFOSC_DIV_8 0x00 ///< SYSCLK derived from High Frequency Oscillator    
                                      ///< divided by 8.                                    
#define OSCICN_IFCN__HFOSC_DIV_4 0x01 ///< SYSCLK derived from High Frequency Oscillator    
                                      ///< divided by 4.                                    
#define OSCICN_IFCN__HFOSC_DIV_2 0x02 ///< SYSCLK derived from High Frequency Oscillator    
                                      ///< divided by 2.                                    
#define OSCICN_IFCN__HFOSC_DIV_1 0x03 ///< SYSCLK derived from High Frequency Oscillator    
                                      ///< divided by 1.                                    
                                                                                            
#define OSCICN_IFRDY__BMASK      0x40 ///< Oscillator Frequency Ready Flag                  
#define OSCICN_IFRDY__SHIFT      0x06 ///< Oscillator Frequency Ready Flag                  
#define OSCICN_IFRDY__NOT_SET    0x00 ///< The Internal High Frequency Oscillator is not    
                                      ///< running at the programmed frequency.             
#define OSCICN_IFRDY__SET        0x40 ///< The Internal High Frequency Oscillator is running
                                      ///< at the programmed frequency.                     
                                                                                            
#define OSCICN_IOSCEN__BMASK     0x80 ///< Oscillator Enable                                
#define OSCICN_IOSCEN__SHIFT     0x07 ///< Oscillator Enable                                
#define OSCICN_IOSCEN__DISABLED  0x00 ///< Disable the High Frequency Oscillator.           
#define OSCICN_IOSCEN__ENABLED   0x80 ///< Enable the High Frequency Oscillator.            
                                                                                            
//------------------------------------------------------------------------------
// EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
//------------------------------------------------------------------------------
#define EIE1_ESPI0__BMASK     0x01 ///< SPI0 Interrupt Enable                             
#define EIE1_ESPI0__SHIFT     0x00 ///< SPI0 Interrupt Enable                             
#define EIE1_ESPI0__DISABLED  0x00 ///< Disable all SPI0 interrupts.                      
#define EIE1_ESPI0__ENABLED   0x01 ///< Enable interrupt requests generated by SPI0.      
                                                                                          
#define EIE1_EMAT__BMASK      0x02 ///< Port Match Interrupts Enable                      
#define EIE1_EMAT__SHIFT      0x01 ///< Port Match Interrupts Enable                      
#define EIE1_EMAT__DISABLED   0x00 ///< Disable all Port Match interrupts.                
#define EIE1_EMAT__ENABLED    0x02 ///< Enable interrupt requests generated by a Port     
                                   ///< Match.                                            
                                                                                          
#define EIE1_ESMB0__BMASK     0x02 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__SHIFT     0x01 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__DISABLED  0x00 ///< Disable all SMB0 interrupts.                      
#define EIE1_ESMB0__ENABLED   0x02 ///< Enable interrupt requests generated by SMB0.      
                                                                                          
#define EIE1_EWADC0__BMASK    0x04 ///< ADC0 Window Comparison Interrupt Enable           
#define EIE1_EWADC0__SHIFT    0x02 ///< ADC0 Window Comparison Interrupt Enable           
#define EIE1_EWADC0__DISABLED 0x00 ///< Disable ADC0 Window Comparison interrupt.         
#define EIE1_EWADC0__ENABLED  0x04 ///< Enable interrupt requests generated by ADC0 Window
                                   ///< Compare flag (ADWINT).                            
                                                                                          
#define EIE1_EADC0__BMASK     0x08 ///< ADC0 Conversion Complete Interrupt Enable         
#define EIE1_EADC0__SHIFT     0x03 ///< ADC0 Conversion Complete Interrupt Enable         
#define EIE1_EADC0__DISABLED  0x00 ///< Disable ADC0 Conversion Complete interrupt.       
#define EIE1_EADC0__ENABLED   0x08 ///< Enable interrupt requests generated by the ADINT  
                                   ///< flag.                                             
                                                                                          
#define EIE1_EPCA0__BMASK     0x08 ///< Programmable Counter Array (PCA0) Interrupt Enable
#define EIE1_EPCA0__SHIFT     0x03 ///< Programmable Counter Array (PCA0) Interrupt Enable
#define EIE1_EPCA0__DISABLED  0x00 ///< Disable all PCA0 interrupts.                      
#define EIE1_EPCA0__ENABLED   0x08 ///< Enable interrupt requests generated by PCA0.      
                                                                                          
#define EIE1_ECP0F__BMASK     0x10 ///< Comparator0 (CP0) Falling Edge Interrupt Enable   
#define EIE1_ECP0F__SHIFT     0x04 ///< Comparator0 (CP0) Falling Edge Interrupt Enable   
#define EIE1_ECP0F__DISABLED  0x00 ///< Disable CP0 falling edge interrupts.              
#define EIE1_ECP0F__ENABLED   0x10 ///< Enable interrupt requests generated by the        
                                   ///< comparator 0 CPFIF flag.                          
                                                                                          
#define EIE1_ECP0__BMASK      0x20 ///< Comparator0 (CP0) Interrupt Enable                
#define EIE1_ECP0__SHIFT      0x05 ///< Comparator0 (CP0) Interrupt Enable                
#define EIE1_ECP0__DISABLED   0x00 ///< Disable CP0 interrupts.                           
#define EIE1_ECP0__ENABLED    0x20 ///< Enable interrupt requests generated by the        
                                   ///< comparator 0 CPRIF or CPFIF flags.                
                                                                                          
#define EIE1_ECP0R__BMASK     0x20 ///< Comparator0 (CP0) Rising Edge Interrupt Enable    
#define EIE1_ECP0R__SHIFT     0x05 ///< Comparator0 (CP0) Rising Edge Interrupt Enable    
#define EIE1_ECP0R__DISABLED  0x00 ///< Disable CP0 rising edge interrupts.               
#define EIE1_ECP0R__ENABLED   0x20 ///< Enable interrupt requests generated by the        
                                   ///< comparator 0 CPRIF flag.                          
                                                                                          
#define EIE1_ECP1__BMASK      0x40 ///< Comparator1 (CP1) Interrupt Enable                
#define EIE1_ECP1__SHIFT      0x06 ///< Comparator1 (CP1) Interrupt Enable                
#define EIE1_ECP1__DISABLED   0x00 ///< Disable CP1 interrupts.                           
#define EIE1_ECP1__ENABLED    0x40 ///< Enable interrupt requests generated by the        
                                   ///< comparator 1 CPRIF or CPFIF flags.                
                                                                                          
#define EIE1_ECP1F__FMASK     0xC0 ///< Comparator1 (CP1) Falling Edge Interrupt Enable   
#define EIE1_ECP1F__SHIFT     0x06 ///< Comparator1 (CP1) Falling Edge Interrupt Enable   
#define EIE1_ECP1F__DISABLED  0x00 ///< Disable CP1 rising edge interrupts.               
#define EIE1_ECP1F__ENABLED   0x40 ///< Enable interrupt requests generated by the        
                                   ///< comparator 1 CPRIF flag.                          
                                                                                          
#define EIE1_ET3__BMASK       0x80 ///< Timer 3 Interrupt Enable                          
#define EIE1_ET3__SHIFT       0x07 ///< Timer 3 Interrupt Enable                          
#define EIE1_ET3__DISABLED    0x00 ///< Disable Timer 3 interrupts.                       
#define EIE1_ET3__ENABLED     0x80 ///< Enable interrupt requests generated by the TF3L or
                                   ///< TF3H flags.                                       
                                                                                          
//------------------------------------------------------------------------------
// EIE2 Enums (Extended Interrupt Enable 2 @ 0xE7)
//------------------------------------------------------------------------------
#define EIE2_ET3__BMASK       0x01 ///< Timer 3 Interrupt Enable                          
#define EIE2_ET3__SHIFT       0x00 ///< Timer 3 Interrupt Enable                          
#define EIE2_ET3__DISABLED    0x00 ///< Disable Timer 3 interrupts.                       
#define EIE2_ET3__ENABLED     0x01 ///< Enable interrupt requests generated by the TF3L or
                                   ///< TF3H flags.                                       
                                                                                          
#define EIE2_EADC0__BMASK     0x02 ///< ADC0 Conversion Complete Interrupt Enable         
#define EIE2_EADC0__SHIFT     0x01 ///< ADC0 Conversion Complete Interrupt Enable         
#define EIE2_EADC0__DISABLED  0x00 ///< Disable ADC0 Conversion Complete interrupt.       
#define EIE2_EADC0__ENABLED   0x02 ///< Enable interrupt requests generated by the ADINT  
                                   ///< flag.                                             
                                                                                          
#define EIE2_ET4__BMASK       0x04 ///< Timer 4 Interrupt Enable                          
#define EIE2_ET4__SHIFT       0x02 ///< Timer 4 Interrupt Enable                          
#define EIE2_ET4__DISABLED    0x00 ///< Disable Timer 4 interrupts.                       
#define EIE2_ET4__ENABLED     0x04 ///< Enable interrupt requests generated by the TF4L or
                                   ///< TF4H flags.                                       
                                                                                          
#define EIE2_EWADC2__BMASK    0x08 ///< ADC2 Window Comparison Interrupt Enable           
#define EIE2_EWADC2__SHIFT    0x03 ///< ADC2 Window Comparison Interrupt Enable           
#define EIE2_EWADC2__DISABLED 0x00 ///< Disable ADC2 Window Comparison interrupt.         
#define EIE2_EWADC2__ENABLED  0x08 ///< Enable interrupt requests generated by ADC2 Window
                                   ///< Compare flag (ADWINT).                            
                                                                                          
#define EIE2_EADC2__BMASK     0x10 ///< ADC2 Conversion Complete Interrupt Enable         
#define EIE2_EADC2__SHIFT     0x04 ///< ADC2 Conversion Complete Interrupt Enable         
#define EIE2_EADC2__DISABLED  0x00 ///< Disable ADC2 Conversion Complete interrupt.       
#define EIE2_EADC2__ENABLED   0x10 ///< Enable interrupt requests generated by the ADINT  
                                   ///< flag.                                             
                                                                                          
#define EIE2_ES1__BMASK       0x40 ///< UART1 Interrupt Enable                            
#define EIE2_ES1__SHIFT       0x06 ///< UART1 Interrupt Enable                            
#define EIE2_ES1__DISABLED    0x00 ///< Disable UART1 interrupts.                         
#define EIE2_ES1__ENABLED     0x40 ///< Enable UART1 interrupts.                          
                                                                                          
//------------------------------------------------------------------------------
// EIP1 Enums (Extended Interrupt Priority 1 Low @ 0xF6)
//------------------------------------------------------------------------------
#define EIP1_PSPI0__BMASK  0x01 ///< Serial Peripheral Interface (SPI0) Interrupt Priority Control
#define EIP1_PSPI0__SHIFT  0x00 ///< Serial Peripheral Interface (SPI0) Interrupt Priority Control
#define EIP1_PSPI0__LOW    0x00 ///< SPI0 interrupt priority set to low.                          
#define EIP1_PSPI0__HIGH   0x01 ///< SPI0 interrupt priority set to high.                         
                                                                                                  
#define EIP1_PMAT__BMASK   0x02 ///< Port Match Interrupt Priority Control                        
#define EIP1_PMAT__SHIFT   0x01 ///< Port Match Interrupt Priority Control                        
#define EIP1_PMAT__LOW     0x00 ///< Port Match interrupt set to low priority level.              
#define EIP1_PMAT__HIGH    0x02 ///< Port Match interrupt set to high priority level.             
                                                                                                  
#define EIP1_PSMB0__BMASK  0x02 ///< SMBus (SMB0) Interrupt Priority Control                      
#define EIP1_PSMB0__SHIFT  0x01 ///< SMBus (SMB0) Interrupt Priority Control                      
#define EIP1_PSMB0__LOW    0x00 ///< SMB0 interrupt priority set to low.                          
#define EIP1_PSMB0__HIGH   0x02 ///< SMB0 interrupt priority set to high.                         
                                                                                                  
#define EIP1_PWADC0__BMASK 0x04 ///< ADC0 Window Comparator Interrupt Priority Control            
#define EIP1_PWADC0__SHIFT 0x02 ///< ADC0 Window Comparator Interrupt Priority Control            
#define EIP1_PWADC0__LOW   0x00 ///< ADC0 Conversion Complete interrupt priority set to           
                                ///< low.                                                         
#define EIP1_PWADC0__HIGH  0x04 ///< ADC0 Conversion Complete interrupt priority set to           
                                ///< high.                                                        
                                                                                                  
#define EIP1_PADC0__BMASK  0x08 ///< ADC0 Conversion Complete Interrupt Priority Control          
#define EIP1_PADC0__SHIFT  0x03 ///< ADC0 Conversion Complete Interrupt Priority Control          
#define EIP1_PADC0__LOW    0x00 ///< ADC0 Conversion Complete interrupt set to low                
                                ///< priority level.                                              
#define EIP1_PADC0__HIGH   0x08 ///< ADC0 Conversion Complete interrupt set to high               
                                ///< priority level.                                              
                                                                                                  
#define EIP1_PPCA0__BMASK  0x08 ///< Programmable Counter Array (PCA0) Interrupt Priority Control 
#define EIP1_PPCA0__SHIFT  0x03 ///< Programmable Counter Array (PCA0) Interrupt Priority Control 
#define EIP1_PPCA0__LOW    0x00 ///< PCA0 interrupt priority set to low.                          
#define EIP1_PPCA0__HIGH   0x08 ///< PCA0 interrupt priority set to high.                         
                                                                                                  
#define EIP1_PCP0F__BMASK  0x10 ///< Comparator0 (CP0) Falling Edge Interrupt Priority Control    
#define EIP1_PCP0F__SHIFT  0x04 ///< Comparator0 (CP0) Falling Edge Interrupt Priority Control    
#define EIP1_PCP0F__LOW    0x00 ///< CP0 falling edge interrupt priority set to low.              
#define EIP1_PCP0F__HIGH   0x10 ///< CP0 falling edge interrupt priority set to high.             
                                                                                                  
#define EIP1_PCP0__BMASK   0x20 ///< Comparator0 (CP0) Interrupt Priority Control                 
#define EIP1_PCP0__SHIFT   0x05 ///< Comparator0 (CP0) Interrupt Priority Control                 
#define EIP1_PCP0__LOW     0x00 ///< CP0 interrupt set to low priority level.                     
#define EIP1_PCP0__HIGH    0x20 ///< CP0 interrupt set to high priority level.                    
                                                                                                  
#define EIP1_PCP0R__BMASK  0x20 ///< Comparator0 (CP0) Rising Edge Interrupt Priority Control     
#define EIP1_PCP0R__SHIFT  0x05 ///< Comparator0 (CP0) Rising Edge Interrupt Priority Control     
#define EIP1_PCP0R__LOW    0x00 ///< CP0 rising edge interrupt priority set to low.               
#define EIP1_PCP0R__HIGH   0x20 ///< CP0 rising edge interrupt priority set to high.              
                                                                                                  
#define EIP1_PCP1__BMASK   0x40 ///< Comparator1 (CP1) Interrupt Priority Control                 
#define EIP1_PCP1__SHIFT   0x06 ///< Comparator1 (CP1) Interrupt Priority Control                 
#define EIP1_PCP1__LOW     0x00 ///< CP1 interrupt set to low priority level.                     
#define EIP1_PCP1__HIGH    0x40 ///< CP1 interrupt set to high priority level.                    
                                                                                                  
#define EIP1_PCP1F__BMASK  0x40 ///< Comparator1 (CP1) Falling Edge Interrupt Priority Control    
#define EIP1_PCP1F__SHIFT  0x06 ///< Comparator1 (CP1) Falling Edge Interrupt Priority Control    
#define EIP1_PCP1F__LOW    0x00 ///< CP1 falling edge interrupt priority set to low.              
#define EIP1_PCP1F__HIGH   0x40 ///< CP1 falling edge interrupt priority set to high.             
                                                                                                  
#define EIP1_PCP1R__BMASK  0x80 ///< Comparator1 (CP1) Rising Edge Interrupt Priority Control     
#define EIP1_PCP1R__SHIFT  0x07 ///< Comparator1 (CP1) Rising Edge Interrupt Priority Control     
#define EIP1_PCP1R__LOW    0x00 ///< CP1 rising edge interrupt priority set to low.               
#define EIP1_PCP1R__HIGH   0x80 ///< CP1 rising edge interrupt priority set to high.              
                                                                                                  
#define EIP1_PT3__BMASK    0x80 ///< Timer 3 Interrupt Priority Control                           
#define EIP1_PT3__SHIFT    0x07 ///< Timer 3 Interrupt Priority Control                           
#define EIP1_PT3__LOW      0x00 ///< Timer 3 interrupts set to low priority level.                
#define EIP1_PT3__HIGH     0x80 ///< Timer 3 interrupts set to high priority level.               
                                                                                                  
//------------------------------------------------------------------------------
// EIP2 Enums (Extended Interrupt Priority 2 @ 0xF7)
//------------------------------------------------------------------------------
#define EIP2_PT3__BMASK    0x01 ///< Timer 3 Interrupt Priority Control                 
#define EIP2_PT3__SHIFT    0x00 ///< Timer 3 Interrupt Priority Control                 
#define EIP2_PT3__LOW      0x00 ///< CP1 interrupt priority set to low.                 
#define EIP2_PT3__HIGH     0x01 ///< CP1 interrupt priority set to high.                
                                                                                        
#define EIP2_PADC0__BMASK  0x02 ///< ADC0 Conversion Complete Interrupt Priority Control
#define EIP2_PADC0__SHIFT  0x01 ///< ADC0 Conversion Complete Interrupt Priority Control
#define EIP2_PADC0__LOW    0x00 ///< ADC0 Conversion Complete interrupt priority set to 
                                ///< low.                                               
#define EIP2_PADC0__HIGH   0x02 ///< ADC0 Conversion Complete interrupt priority set to 
                                ///< high.                                              
                                                                                        
#define EIP2_PT4__BMASK    0x04 ///< Timer 4 Interrupt Priority Control                 
#define EIP2_PT4__SHIFT    0x02 ///< Timer 4 Interrupt Priority Control                 
#define EIP2_PT4__LOW      0x00 ///< Timer 4 interrupt priority set to low.             
#define EIP2_PT4__HIGH     0x04 ///< Timer 4 interrupt priority set to high.            
                                                                                        
#define EIP2_PWADC2__BMASK 0x08 ///< ADC2 Window Comparator Interrupt Priority Control  
#define EIP2_PWADC2__SHIFT 0x03 ///< ADC2 Window Comparator Interrupt Priority Control  
#define EIP2_PWADC2__LOW   0x00 ///< ADC2 Conversion Complete interrupt priority set to 
                                ///< low.                                               
#define EIP2_PWADC2__HIGH  0x08 ///< ADC2 Conversion Complete interrupt priority set to 
                                ///< high.                                              
                                                                                        
#define EIP2_PADC2__BMASK  0x10 ///< ADC2 Conversion Complete Interrupt Priority Control
#define EIP2_PADC2__SHIFT  0x04 ///< ADC2 Conversion Complete Interrupt Priority Control
#define EIP2_PADC2__LOW    0x00 ///< ADC2 Conversion Complete interrupt priority set to 
                                ///< low.                                               
#define EIP2_PADC2__HIGH   0x10 ///< ADC2 Conversion Complete interrupt priority set to 
                                ///< high.                                              
                                                                                        
#define EIP2_PS1__BMASK    0x40 ///< UART1 Interrupt Priority Control                   
#define EIP2_PS1__SHIFT    0x06 ///< UART1 Interrupt Priority Control                   
#define EIP2_PS1__LOW      0x00 ///< UART1 interrupt priority set to low.               
#define EIP2_PS1__HIGH     0x40 ///< UART1 interrupt priority set to high.              
                                                                                        
//------------------------------------------------------------------------------
// IE Enums (Interrupt Enable @ 0xA8)
//------------------------------------------------------------------------------
#define IE_EX0__BMASK      0x01 ///< External Interrupt 0 Enable                       
#define IE_EX0__SHIFT      0x00 ///< External Interrupt 0 Enable                       
#define IE_EX0__DISABLED   0x00 ///< Disable external interrupt 0.                     
#define IE_EX0__ENABLED    0x01 ///< Enable interrupt requests generated by the INT0   
                                ///< input.                                            
                                                                                       
#define IE_ET0__BMASK      0x02 ///< Timer 0 Interrupt Enable                          
#define IE_ET0__SHIFT      0x01 ///< Timer 0 Interrupt Enable                          
#define IE_ET0__DISABLED   0x00 ///< Disable all Timer 0 interrupt.                    
#define IE_ET0__ENABLED    0x02 ///< Enable interrupt requests generated by the TF0    
                                ///< flag.                                             
                                                                                       
#define IE_EX1__BMASK      0x04 ///< External Interrupt 1 Enable                       
#define IE_EX1__SHIFT      0x02 ///< External Interrupt 1 Enable                       
#define IE_EX1__DISABLED   0x00 ///< Disable external interrupt 1.                     
#define IE_EX1__ENABLED    0x04 ///< Enable interrupt requests generated by the INT1   
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
                                                                                       
#define IE_IEGF0__BMASK    0x40 ///< General Purpose Flag 0                            
#define IE_IEGF0__SHIFT    0x06 ///< General Purpose Flag 0                            
#define IE_IEGF0__NOT_SET  0x00 ///< The flag is not set. Clear the flag.              
#define IE_IEGF0__SET      0x40 ///< The flag is set. Set the flag.                    
                                                                                       
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
#define IP_PX0__LOW     0x00 ///< External Interrupt 0 priority set to low.                    
#define IP_PX0__HIGH    0x01 ///< External Interrupt 0 priority set to high.                   
                                                                                               
#define IP_PT0__BMASK   0x02 ///< Timer 0 Interrupt Priority Control                           
#define IP_PT0__SHIFT   0x01 ///< Timer 0 Interrupt Priority Control                           
#define IP_PT0__LOW     0x00 ///< Timer 0 interrupt priority set to low.                       
#define IP_PT0__HIGH    0x02 ///< Timer 0 interrupt priority set to high.                      
                                                                                               
#define IP_PX1__BMASK   0x04 ///< External Interrupt 1 Priority Control                        
#define IP_PX1__SHIFT   0x02 ///< External Interrupt 1 Priority Control                        
#define IP_PX1__LOW     0x00 ///< External Interrupt 1 priority set to low.                    
#define IP_PX1__HIGH    0x04 ///< External Interrupt 1 priority set to high.                   
                                                                                               
#define IP_PT1__BMASK   0x08 ///< Timer 1 Interrupt Priority Control                           
#define IP_PT1__SHIFT   0x03 ///< Timer 1 Interrupt Priority Control                           
#define IP_PT1__LOW     0x00 ///< Timer 1 interrupt priority set to low.                       
#define IP_PT1__HIGH    0x08 ///< Timer 1 interrupt priority set to high.                      
                                                                                               
#define IP_PS0__BMASK   0x10 ///< UART0 Interrupt Priority Control                             
#define IP_PS0__SHIFT   0x04 ///< UART0 Interrupt Priority Control                             
#define IP_PS0__LOW     0x00 ///< UART0 interrupt priority set to low.                         
#define IP_PS0__HIGH    0x10 ///< UART0 interrupt priority set to high.                        
                                                                                               
#define IP_PT2__BMASK   0x20 ///< Timer 2 Interrupt Priority Control                           
#define IP_PT2__SHIFT   0x05 ///< Timer 2 Interrupt Priority Control                           
#define IP_PT2__LOW     0x00 ///< Timer 2 interrupt priority set to low.                       
#define IP_PT2__HIGH    0x20 ///< Timer 2 interrupt priority set to high.                      
                                                                                               
#define IP_PSPI0__BMASK 0x40 ///< Serial Peripheral Interface (SPI0) Interrupt Priority Control
#define IP_PSPI0__SHIFT 0x06 ///< Serial Peripheral Interface (SPI0) Interrupt Priority Control
#define IP_PSPI0__LOW   0x00 ///< SPI0 interrupt set to low priority level.                    
#define IP_PSPI0__HIGH  0x40 ///< SPI0 interrupt set to high priority level.                   
                                                                                               
//------------------------------------------------------------------------------
// DEVICEID Enums (JTAG Device ID @ 0x04)
//------------------------------------------------------------------------------
#define DEVICEID_DEVICEID__FMASK 0xFFFFFFFF ///< Device ID
#define DEVICEID_DEVICEID__SHIFT 0x00       ///< Device ID
                                                          
//------------------------------------------------------------------------------
// FLASHADR Enums (JTAG Flash Address @ 0x84)
//------------------------------------------------------------------------------
#define FLASHADR_FLASHADR__FMASK 0x1FFFF ///< Flash Operation 17-bit Address
#define FLASHADR_FLASHADR__SHIFT 0x00    ///< Flash Operation 17-bit Address
                                                                            
//------------------------------------------------------------------------------
// FLASHCON Enums (JTAG Flash Control @ 0x82)
//------------------------------------------------------------------------------
#define FLASHCON_RDMD__FMASK 0x0F ///< Read Mode Select                     
#define FLASHCON_RDMD__SHIFT 0x00 ///< Read Mode Select                     
                                                                            
#define FLASHCON_WRMD__FMASK 0x70 ///< Write Mode Select                    
#define FLASHCON_WRMD__SHIFT 0x04 ///< Write Mode Select                    
                                                                            
#define FLASHCON_SFLE__BMASK 0x80 ///< Scratchpad Flash Memory Access Enable
#define FLASHCON_SFLE__SHIFT 0x07 ///< Scratchpad Flash Memory Access Enable
                                                                            
//------------------------------------------------------------------------------
// FLASHDAT Enums (JTAG Flash Data @ 0x83)
//------------------------------------------------------------------------------
#define FLASHDAT_BUSY__BMASK 0x01  ///< Flash Busy     
#define FLASHDAT_BUSY__SHIFT 0x00  ///< Flash Busy     
                                                       
#define FLASHDAT_FAIL__BMASK 0x02  ///< Flash Fail     
#define FLASHDAT_FAIL__SHIFT 0x01  ///< Flash Fail     
                                                       
#define FLASHDAT_DATA__FMASK 0x3FC ///< Flash Data Byte
#define FLASHDAT_DATA__SHIFT 0x02  ///< Flash Data Byte
                                                       
//------------------------------------------------------------------------------
// MAC0ACC0 Enums (Accumulator Byte 0 @ 0x93)
//------------------------------------------------------------------------------
#define MAC0ACC0_MAC0ACC0__FMASK 0xFF ///< MAC0 Accumulator Byte 0
#define MAC0ACC0_MAC0ACC0__SHIFT 0x00 ///< MAC0 Accumulator Byte 0
                                                                  
//------------------------------------------------------------------------------
// MAC0ACC1 Enums (Accumulator Byte 1 @ 0x94)
//------------------------------------------------------------------------------
#define MAC0ACC1_MAC0ACC1__FMASK 0xFF ///< MAC0 Accumulator Byte 1
#define MAC0ACC1_MAC0ACC1__SHIFT 0x00 ///< MAC0 Accumulator Byte 1
                                                                  
//------------------------------------------------------------------------------
// MAC0ACC2 Enums (Accumulator Byte 2 @ 0x95)
//------------------------------------------------------------------------------
#define MAC0ACC2_MAC0ACC2__FMASK 0xFF ///< MAC0 Accumulator Byte 2
#define MAC0ACC2_MAC0ACC2__SHIFT 0x00 ///< MAC0 Accumulator Byte 2
                                                                  
//------------------------------------------------------------------------------
// MAC0ACC3 Enums (Accumulator Byte 3 @ 0x96)
//------------------------------------------------------------------------------
#define MAC0ACC3_MAC0ACC3__FMASK 0xFF ///< MAC0 Accumulator Byte 3
#define MAC0ACC3_MAC0ACC3__SHIFT 0x00 ///< MAC0 Accumulator Byte 3
                                                                  
//------------------------------------------------------------------------------
// MAC0AH Enums (Operand A High Byte @ 0xC2)
//------------------------------------------------------------------------------
#define MAC0AH_MAC0AH__FMASK 0xFF ///< MAC0 A High Byte
#define MAC0AH_MAC0AH__SHIFT 0x00 ///< MAC0 A High Byte
                                                       
//------------------------------------------------------------------------------
// MAC0AL Enums (Operand A Low Byte @ 0xC1)
//------------------------------------------------------------------------------
#define MAC0AL_MAC0AL__FMASK 0xFF ///< MAC0 A Low Byte
#define MAC0AL_MAC0AL__SHIFT 0x00 ///< MAC0 A Low Byte
                                                      
//------------------------------------------------------------------------------
// MAC0BH Enums (Operand B High Byte @ 0x92)
//------------------------------------------------------------------------------
#define MAC0BH_MAC0BH__FMASK 0xFF ///< MAC0 B High Byte
#define MAC0BH_MAC0BH__SHIFT 0x00 ///< MAC0 B High Byte
                                                       
//------------------------------------------------------------------------------
// MAC0BL Enums (Operand B Low Byte @ 0x91)
//------------------------------------------------------------------------------
#define MAC0BL_MAC0BL__FMASK 0xFF ///< MAC0 B Low Byte
#define MAC0BL_MAC0BL__SHIFT 0x00 ///< MAC0 B Low Byte
                                                      
//------------------------------------------------------------------------------
// MAC0CF Enums (MAC0 Configuration @ 0xC3)
//------------------------------------------------------------------------------
#define MAC0CF_ACCMD__BMASK       0x01 ///< Accumulate Mode                                 
#define MAC0CF_ACCMD__SHIFT       0x00 ///< Accumulate Mode                                 
#define MAC0CF_ACCMD__MAC_MODE    0x00 ///< Select multiply-and-accumulate (MAC) mode.      
#define MAC0CF_ACCMD__MUL_MODE    0x01 ///< Select multiply-only mode.                      
                                                                                            
#define MAC0CF_FRACMD__BMASK      0x02 ///< Fractional Mode                                 
#define MAC0CF_FRACMD__SHIFT      0x01 ///< Fractional Mode                                 
#define MAC0CF_FRACMD__INT_MODE   0x00 ///< MAC0 operates in Integer Mode.                  
#define MAC0CF_FRACMD__FRAC_MODE  0x02 ///< MAC0 operates in Fractional Mode.               
                                                                                            
#define MAC0CF_SATURATE__BMASK    0x04 ///< Saturation Enable                               
#define MAC0CF_SATURATE__SHIFT    0x02 ///< Saturation Enable                               
#define MAC0CF_SATURATE__DISABLED 0x00 ///< Rounded result will not saturate.               
#define MAC0CF_SATURATE__ENABLED  0x04 ///< Rounded result will saturate.                   
                                                                                            
#define MAC0CF_CLRACC__BMASK      0x08 ///< Clear Accumulator                               
#define MAC0CF_CLRACC__SHIFT      0x03 ///< Clear Accumulator                               
#define MAC0CF_CLRACC__COMPLETED  0x00 ///< The accumulator clear operation completed.      
#define MAC0CF_CLRACC__START      0x08 ///< Clear the accumulator and the related MAC0STA   
                                       ///< register flags.                                 
                                                                                            
#define MAC0CF_SHIFTDIR__BMASK    0x10 ///< Accumulator Shift Direction                     
#define MAC0CF_SHIFTDIR__SHIFT    0x04 ///< Accumulator Shift Direction                     
#define MAC0CF_SHIFTDIR__LEFT     0x00 ///< The MAC0 accumulator will be shifted left.      
#define MAC0CF_SHIFTDIR__RIGHT    0x10 ///< The MAC0 accumulator will be shifted right.     
                                                                                            
#define MAC0CF_SHIFTEN__BMASK     0x20 ///< Accumulator Shift Control                       
#define MAC0CF_SHIFTEN__SHIFT     0x05 ///< Accumulator Shift Control                       
#define MAC0CF_SHIFTEN__COMPLETED 0x00 ///< The shift operation completed.                  
#define MAC0CF_SHIFTEN__START     0x20 ///< Shift the accumulator by one bit in the SHIFTDIR
                                       ///< direction.                                      
                                                                                            
//------------------------------------------------------------------------------
// MAC0OVR Enums (Accumulator Overflow Byte @ 0x97)
//------------------------------------------------------------------------------
#define MAC0OVR_MAC0OVF__FMASK 0xFF ///< MAC0 Accumulator Overflow Byte
#define MAC0OVR_MAC0OVF__SHIFT 0x00 ///< MAC0 Accumulator Overflow Byte
                                                                       
//------------------------------------------------------------------------------
// MAC0RNDH Enums (Rounded Result High Byte @ 0xCF)
//------------------------------------------------------------------------------
#define MAC0RNDH_MAC0RND__FMASK 0xFF ///< Rounded Result High
#define MAC0RNDH_MAC0RND__SHIFT 0x00 ///< Rounded Result High
                                                             
//------------------------------------------------------------------------------
// MAC0RNDL Enums (Rounded Result Low Byte @ 0xCE)
//------------------------------------------------------------------------------
#define MAC0RNDL_MAC0RND__FMASK 0xFF ///< Rounded Result Low
#define MAC0RNDL_MAC0RND__SHIFT 0x00 ///< Rounded Result Low
                                                            
//------------------------------------------------------------------------------
// MAC0STA Enums (MAC0 Status @ 0xC0)
//------------------------------------------------------------------------------
#define MAC0STA_NEGF__BMASK    0x01 ///< Negative Flag                                
#define MAC0STA_NEGF__SHIFT    0x00 ///< Negative Flag                                
#define MAC0STA_NEGF__NOT_SET  0x00 ///< The accumulator result is zero or positive.  
#define MAC0STA_NEGF__SET      0x01 ///< The accumulator result is negative.          
                                                                                      
#define MAC0STA_SOVF__BMASK    0x02 ///< Soft Overflow Flag                           
#define MAC0STA_SOVF__SHIFT    0x01 ///< Soft Overflow Flag                           
#define MAC0STA_SOVF__NOT_SET  0x00 ///< A soft overflow did not occur.               
#define MAC0STA_SOVF__SET      0x02 ///< A soft overflow occurred.                    
                                                                                      
#define MAC0STA_ZEROF__BMASK   0x04 ///< Zero Flag                                    
#define MAC0STA_ZEROF__SHIFT   0x02 ///< Zero Flag                                    
#define MAC0STA_ZEROF__NOT_SET 0x00 ///< The last operation did not result in an      
                                    ///< accumulator value of zero.                   
#define MAC0STA_ZEROF__SET     0x04 ///< The last operation resulted in an accumulator
                                    ///< value of zero.                               
                                                                                      
#define MAC0STA_HOVF__BMASK    0x08 ///< Hard Overflow Flag                           
#define MAC0STA_HOVF__SHIFT    0x03 ///< Hard Overflow Flag                           
#define MAC0STA_HOVF__NOT_SET  0x00 ///< A hardware overflow did not occur.           
#define MAC0STA_HOVF__SET      0x08 ///< A hardware overflow occurred.                
                                                                                      
//------------------------------------------------------------------------------
// XBR0 Enums (Port I/O Crossbar 0 @ 0xE1)
//------------------------------------------------------------------------------
#define XBR0_SMB0EN__BMASK                         0x01 ///< SMBus0 I/O Enable                                
#define XBR0_SMB0EN__SHIFT                         0x00 ///< SMBus0 I/O Enable                                
#define XBR0_SMB0EN__DISABLED                      0x00 ///< SMBus0 I/O unavailable at Port pins.             
#define XBR0_SMB0EN__ENABLED                       0x01 ///< SMBus0 I/O routed to Port pins.                  
                                                                                                              
#define XBR0_SPI0EN__BMASK                         0x02 ///< SPI I/O Enable                                   
#define XBR0_SPI0EN__SHIFT                         0x01 ///< SPI I/O Enable                                   
#define XBR0_SPI0EN__DISABLED                      0x00 ///< SPI I/O unavailable at Port pins.                
#define XBR0_SPI0EN__ENABLED                       0x02 ///< SPI I/O routed to Port pins. The SPI can be      
                                                        ///< assigned either 3 or 4 GPIO pins.                
                                                                                                              
#define XBR0_UART0EN__BMASK                        0x04 ///< UART I/O Output Enable                           
#define XBR0_UART0EN__SHIFT                        0x02 ///< UART I/O Output Enable                           
#define XBR0_UART0EN__DISABLED                     0x00 ///< UART I/O unavailable at Port pin.                
#define XBR0_UART0EN__ENABLED                      0x04 ///< UART TX, RX routed to Port pins P0.0 and P0.1.   
                                                                                                              
#define XBR0_PCA0ME__FMASK                         0x38 ///< PCA Module I/O Enable                            
#define XBR0_PCA0ME__SHIFT                         0x03 ///< PCA Module I/O Enable                            
#define XBR0_PCA0ME__DISABLED                      0x00 ///< All PCA I/O unavailable at Port pins.            
#define XBR0_PCA0ME__CEX0                          0x08 ///< CEX0 routed to Port pin.                         
#define XBR0_PCA0ME__CEX0_CEX1                     0x10 ///< CEX0, CEX1 routed to Port pins.                  
#define XBR0_PCA0ME__CEX0_CEX1_CEX2                0x18 ///< CEX0, CEX1, CEX2 routed to Port pins.            
#define XBR0_PCA0ME__CEX0_CEX1_CEX2_CEX3           0x20 ///< CEX0, CEX1, CEX2, CEX3 routed to Port pins.      
#define XBR0_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4      0x28 ///< CEX0, CEX1, CEX2, CEX3, CEX4 routed to Port pins.
#define XBR0_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4_CEX5 0x30 ///< CEX0, CEX1, CEX2, CEX3, CEX4, CEX5 routed to Port
                                                        ///< pins.                                            
                                                                                                              
#define XBR0_ECI0E__BMASK                          0x40 ///< PCA0 External Counter Input Enable               
#define XBR0_ECI0E__SHIFT                          0x06 ///< PCA0 External Counter Input Enable               
#define XBR0_ECI0E__DISABLED                       0x00 ///< ECI unavailable at Port pin.                     
#define XBR0_ECI0E__ENABLED                        0x40 ///< ECI routed to Port pin.                          
                                                                                                              
#define XBR0_CP0E__BMASK                           0x80 ///< Comparator0 Output Enable                        
#define XBR0_CP0E__SHIFT                           0x07 ///< Comparator0 Output Enable                        
#define XBR0_CP0E__DISABLED                        0x00 ///< CP0 unavailable at Port pin.                     
#define XBR0_CP0E__ENABLED                         0x80 ///< CP0 routed to Port pin.                          
                                                                                                              
//------------------------------------------------------------------------------
// XBR1 Enums (Port I/O Crossbar 1 @ 0xE2)
//------------------------------------------------------------------------------
#define XBR1_CP1E__BMASK      0x01 ///< Comparator1 Output Enable        
#define XBR1_CP1E__SHIFT      0x00 ///< Comparator1 Output Enable        
#define XBR1_CP1E__DISABLED   0x00 ///< CP1 unavailable at Port pin.     
#define XBR1_CP1E__ENABLED    0x01 ///< CP1 routed to Port pin.          
                                                                         
#define XBR1_T0E__BMASK       0x02 ///< T0 Enable                        
#define XBR1_T0E__SHIFT       0x01 ///< T0 Enable                        
#define XBR1_T0E__DISABLED    0x00 ///< T0 unavailable at Port pin.      
#define XBR1_T0E__ENABLED     0x02 ///< T0 routed to Port pin.           
                                                                         
#define XBR1_INT0E__BMASK     0x04 ///< /INT0 Input Enable               
#define XBR1_INT0E__SHIFT     0x02 ///< /INT0 Input Enable               
#define XBR1_INT0E__DISABLED  0x00 ///< /INT0 unavailable at Port pin.   
#define XBR1_INT0E__ENABLED   0x04 ///< /INT0 routed to Port pin.        
                                                                         
#define XBR1_T1E__BMASK       0x08 ///< T1 Enable                        
#define XBR1_T1E__SHIFT       0x03 ///< T1 Enable                        
#define XBR1_T1E__DISABLED    0x00 ///< T1 unavailable at Port pin.      
#define XBR1_T1E__ENABLED     0x08 ///< T1 routed to Port pin.           
                                                                         
#define XBR1_INT1E__BMASK     0x10 ///< /INT1 Input Enable               
#define XBR1_INT1E__SHIFT     0x04 ///< /INT1 Input Enable               
#define XBR1_INT1E__DISABLED  0x00 ///< /INT1 unavailable at Port pin.   
#define XBR1_INT1E__ENABLED   0x10 ///< /INT1 routed to Port pin.        
                                                                         
#define XBR1_T2E__BMASK       0x20 ///< T2 Enable                        
#define XBR1_T2E__SHIFT       0x05 ///< T2 Enable                        
#define XBR1_T2E__DISABLED    0x00 ///< T2 unavailable at Port pin.      
#define XBR1_T2E__ENABLED     0x20 ///< T2 routed to Port pin.           
                                                                         
#define XBR1_T2EXE__BMASK     0x40 ///< T2EX Input Enable                
#define XBR1_T2EXE__SHIFT     0x06 ///< T2EX Input Enable                
#define XBR1_T2EXE__DISABLED  0x00 ///< T2EX unavailable at Port pin.    
#define XBR1_T2EXE__ENABLED   0x40 ///< T2EX routed to Port pin.         
                                                                         
#define XBR1_SYSCKE__BMASK    0x80 ///< SYSCLK Output Enable             
#define XBR1_SYSCKE__SHIFT    0x07 ///< SYSCLK Output Enable             
#define XBR1_SYSCKE__DISABLED 0x00 ///< SYSCLK unavailable at Port pin.  
#define XBR1_SYSCKE__ENABLED  0x80 ///< SYSCLK output routed to Port pin.
                                                                         
//------------------------------------------------------------------------------
// XBR2 Enums (Port I/O Crossbar 2 @ 0xE3)
//------------------------------------------------------------------------------
#define XBR2_CNVST0E__BMASK             0x01 ///< ADC0 External Convert Start Input Enable          
#define XBR2_CNVST0E__SHIFT             0x00 ///< ADC0 External Convert Start Input Enable          
#define XBR2_CNVST0E__DISABLED          0x00 ///< CNVSTR0 for ADC0 unavailable at Port pin.         
#define XBR2_CNVST0E__ENABLED           0x01 ///< CNVSTR0 for ADC0 routed to Port pin.              
                                                                                                    
#define XBR2_EMIFLE__BMASK              0x02 ///< External Memory Interface Low-Port Enable         
#define XBR2_EMIFLE__SHIFT              0x01 ///< External Memory Interface Low-Port Enable         
#define XBR2_EMIFLE__DISABLED           0x00 ///< P0.7, P0.6, and P0.5 functions are determined by  
                                             ///< the Crossbar or the Port latches.                 
#define XBR2_EMIFLE__ENABLED            0x02 ///< If EMI0CF.4 = 0 (External Memory Interface is in  
                                             ///< Multiplexed mode), P0.7 (/WR), P0.6 (/RD), and    
                                             ///< P0.5 (ALE) are skipped by the Crossbar and their  
                                             ///< output states are determined by the Port latches  
                                             ///< and the External Memory Interface. If EMI0CF.4 = 1
                                             ///< (External Memory Interface is in Non-multiplexed  
                                             ///< mode), P0.7 (/WR) and P0.6 (/RD) are skipped by   
                                             ///< the Crossbar and their output.                    
                                                                                                    
#define XBR2_UART1E__BMASK              0x04 ///< UART I/O Output Enable                            
#define XBR2_UART1E__SHIFT              0x02 ///< UART I/O Output Enable                            
#define XBR2_UART1E__DISABLED           0x00 ///< UART I/O unavailable at Port pin.                 
#define XBR2_UART1E__ENABLED            0x04 ///< UART TX, RX routed to Port pins.                  
                                                                                                    
#define XBR2_T4E__BMASK                 0x08 ///< T4 Enable                                         
#define XBR2_T4E__SHIFT                 0x03 ///< T4 Enable                                         
#define XBR2_T4E__DISABLED              0x00 ///< T4 unavailable at Port pin.                       
#define XBR2_T4E__ENABLED               0x08 ///< T4 routed to Port pin.                            
                                                                                                    
#define XBR2_T4EXE__BMASK               0x10 ///< T4EX Input Enable                                 
#define XBR2_T4EXE__SHIFT               0x04 ///< T4EX Input Enable                                 
#define XBR2_T4EXE__DISABLED            0x00 ///< T4EX unavailable at Port pin.                     
#define XBR2_T4EXE__ENABLED             0x10 ///< T4EX routed to Port pin.                          
                                                                                                    
#define XBR2_CNVST2E__BMASK             0x20 ///< ADC2 External Convert Start Input Enable          
#define XBR2_CNVST2E__SHIFT             0x05 ///< ADC2 External Convert Start Input Enable          
#define XBR2_CNVST2E__DISABLED          0x00 ///< CNVSTR2 for ADC2 unavailable at Port pin.         
#define XBR2_CNVST2E__ENABLED           0x20 ///< CNVSTR2 for ADC2 routed to Port pin.              
                                                                                                    
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
// PCA0CPH0 Enums (PCA Channel 0 Capture Module High Byte @ 0xFC)
//------------------------------------------------------------------------------
#define PCA0CPH0_PCA0CPH0__FMASK 0xFF ///< PCA Channel 0 Capture Module High Byte
#define PCA0CPH0_PCA0CPH0__SHIFT 0x00 ///< PCA Channel 0 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL0 Enums (PCA Channel 0 Capture Module Low Byte @ 0xFB)
//------------------------------------------------------------------------------
#define PCA0CPL0_PCA0CPL0__FMASK 0xFF ///< PCA Channel 0 Capture Module Low Byte
#define PCA0CPL0_PCA0CPL0__SHIFT 0x00 ///< PCA Channel 0 Capture Module Low Byte
                                                                                
//------------------------------------------------------------------------------
// PCA0CPM0 Enums (PCA Channel 0 Capture/Compare Mode @ 0xDA)
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
#define PCA0CPM0_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
#define PCA0CPM0_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0CPH1 Enums (PCA Channel 1 Capture Module High Byte @ 0xFE)
//------------------------------------------------------------------------------
#define PCA0CPH1_PCA0CPH1__FMASK 0xFF ///< PCA Channel 1 Capture Module High Byte
#define PCA0CPH1_PCA0CPH1__SHIFT 0x00 ///< PCA Channel 1 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL1 Enums (PCA Channel 1 Capture Module Low Byte @ 0xFD)
//------------------------------------------------------------------------------
#define PCA0CPL1_PCA0CPL1__FMASK 0xFF ///< PCA Channel 1 Capture Module Low Byte
#define PCA0CPL1_PCA0CPL1__SHIFT 0x00 ///< PCA Channel 1 Capture Module Low Byte
                                                                                
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
#define PCA0CPM1_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
#define PCA0CPM1_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0CPH2 Enums (PCA Channel 2 Capture Module High Byte @ 0xEA)
//------------------------------------------------------------------------------
#define PCA0CPH2_PCA0CPH2__FMASK 0xFF ///< PCA Channel 2 Capture Module High Byte
#define PCA0CPH2_PCA0CPH2__SHIFT 0x00 ///< PCA Channel 2 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL2 Enums (PCA Channel 2 Capture Module Low Byte @ 0xE9)
//------------------------------------------------------------------------------
#define PCA0CPL2_PCA0CPL2__FMASK 0xFF ///< PCA Channel 2 Capture Module Low Byte
#define PCA0CPL2_PCA0CPL2__SHIFT 0x00 ///< PCA Channel 2 Capture Module Low Byte
                                                                                
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
#define PCA0CPM2_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
#define PCA0CPM2_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0CPH3 Enums (PCA Channel 3 Capture Module High Byte @ 0xEC)
//------------------------------------------------------------------------------
#define PCA0CPH3_PCA0CPH3__FMASK 0xFF ///< PCA Channel 3 Capture Module High Byte
#define PCA0CPH3_PCA0CPH3__SHIFT 0x00 ///< PCA Channel 3 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL3 Enums (PCA Channel 3 Capture Module Low Byte @ 0xEB)
//------------------------------------------------------------------------------
#define PCA0CPL3_PCA0CPL3__FMASK 0xFF ///< PCA Channel 3 Capture Module Low Byte
#define PCA0CPL3_PCA0CPL3__SHIFT 0x00 ///< PCA Channel 3 Capture Module Low Byte
                                                                                
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
#define PCA0CPM3_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
#define PCA0CPM3_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0CPH4 Enums (PCA Channel 4 Capture Module High Byte @ 0xEE)
//------------------------------------------------------------------------------
#define PCA0CPH4_PCA0CPH4__FMASK 0xFF ///< PCA Channel 4 Capture Module High Byte
#define PCA0CPH4_PCA0CPH4__SHIFT 0x00 ///< PCA Channel 4 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL4 Enums (PCA Channel 4 Capture Module Low Byte @ 0xED)
//------------------------------------------------------------------------------
#define PCA0CPL4_PCA0CPL4__FMASK 0xFF ///< PCA Channel 4 Capture Module Low Byte
#define PCA0CPL4_PCA0CPL4__SHIFT 0x00 ///< PCA Channel 4 Capture Module Low Byte
                                                                                
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
#define PCA0CPM4_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
#define PCA0CPM4_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
//------------------------------------------------------------------------------
// PCA0CPH5 Enums (PCA Channel 5 Capture Module High Byte @ 0xE2)
//------------------------------------------------------------------------------
#define PCA0CPH5_PCA0CPH5__FMASK 0xFF ///< PCA Channel 5 Capture Module High Byte
#define PCA0CPH5_PCA0CPH5__SHIFT 0x00 ///< PCA Channel 5 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL5 Enums (PCA Channel 5 Capture Module Low Byte @ 0xE1)
//------------------------------------------------------------------------------
#define PCA0CPL5_PCA0CPL5__FMASK 0xFF ///< PCA Channel 5 Capture Module Low Byte
#define PCA0CPL5_PCA0CPL5__SHIFT 0x00 ///< PCA Channel 5 Capture Module Low Byte
                                                                                
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
#define PCA0CPM5_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
#define PCA0CPM5_PWM16__16_BIT  0x80 ///< 16-bit PWM selected.                           
                                                                                         
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
                                          ///< request when CF is set.                           
                                                                                                 
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
                                                                                                 
#define PCA0MD_CIDL__BMASK           0x80 ///< PCA Counter/Timer Idle Control                    
#define PCA0MD_CIDL__SHIFT           0x07 ///< PCA Counter/Timer Idle Control                    
#define PCA0MD_CIDL__NORMAL          0x00 ///< PCA continues to function normally while the      
                                          ///< system controller is in Idle Mode.                
#define PCA0MD_CIDL__SUSPEND         0x80 ///< PCA operation is suspended while the system       
                                          ///< controller is in Idle Mode.                       
                                                                                                 
//------------------------------------------------------------------------------
// PLL0CN Enums (PLL Control @ 0x89)
//------------------------------------------------------------------------------
#define PLL0CN_PLLPWR__BMASK      0x01 ///< Power Enable                                    
#define PLL0CN_PLLPWR__SHIFT      0x00 ///< Power Enable                                    
#define PLL0CN_PLLPWR__DISABLED   0x00 ///< Disable the PLL bias generator. The PLL does not
                                       ///< consume any static power.                       
#define PLL0CN_PLLPWR__ENABLED    0x01 ///< Enable the PLL bias generator.                  
                                                                                            
#define PLL0CN_PLLEN__BMASK       0x02 ///< PLL Enable                                      
#define PLL0CN_PLLEN__SHIFT       0x01 ///< PLL Enable                                      
#define PLL0CN_PLLEN__DISABLED    0x00 ///< PLL is held in reset.                           
#define PLL0CN_PLLEN__ENABLED     0x02 ///< PLL is enabled.                                 
                                                                                            
#define PLL0CN_PLLSRC__BMASK      0x04 ///< Reference Clock Source Select                   
#define PLL0CN_PLLSRC__SHIFT      0x02 ///< Reference Clock Source Select                   
#define PLL0CN_PLLSRC__HFOSC      0x00 ///< PLL reference clock source is the internal High-
                                       ///< Frequency Oscillator.                           
#define PLL0CN_PLLSRC__EXTOSC     0x04 ///< PLL reference clock source is the external      
                                       ///< oscillator.                                     
                                                                                            
#define PLL0CN_PLLLCK__BMASK      0x10 ///< Lock Flag                                       
#define PLL0CN_PLLLCK__SHIFT      0x04 ///< Lock Flag                                       
#define PLL0CN_PLLLCK__NOT_LOCKED 0x00 ///< PLL output frequency is not locked.             
#define PLL0CN_PLLLCK__LOCKED     0x10 ///< PLL output frequency is locked.                 
                                                                                            
//------------------------------------------------------------------------------
// PLL0DIV Enums (PLL Divider @ 0x8D)
//------------------------------------------------------------------------------
#define PLL0DIV_PLLM__FMASK 0x1F ///< PLL Reference Clock Divider
#define PLL0DIV_PLLM__SHIFT 0x00 ///< PLL Reference Clock Divider
                                                                 
//------------------------------------------------------------------------------
// PLL0FLT Enums (PLL Filter @ 0x8F)
//------------------------------------------------------------------------------
#define PLL0FLT_PLLLP__FMASK                      0x0F ///< PLL Loop Filter Control
#define PLL0FLT_PLLLP__SHIFT                      0x00 ///< PLL Loop Filter Control
#define PLL0FLT_PLLLP__DIV_INPUT_19_TO_30_MHZ     0x01 ///< 19-30 MHz.             
#define PLL0FLT_PLLLP__DIV_INPUT_12P2_TO_19P5_MHZ 0x03 ///< 12.2-19.5 MHz.         
#define PLL0FLT_PLLLP__DIV_INPUT_7P8_TO_12P5_MHZ  0x07 ///< 7.8-12.5 MHz.          
#define PLL0FLT_PLLLP__DIV_INPUT_5_TO_8_MHZ       0x0F ///< 5-8 MHz.               
                                                                                   
#define PLL0FLT_PLLICO__FMASK                     0x30 ///< PLL Output Range       
#define PLL0FLT_PLLICO__SHIFT                     0x04 ///< PLL Output Range       
#define PLL0FLT_PLLICO__OUTPUT_65_TO_100_MHZ      0x00 ///< 65-100 MHz.            
#define PLL0FLT_PLLICO__OUTPUT_45_TO_80_MHZ       0x10 ///< 45-80 MHz.             
#define PLL0FLT_PLLICO__OUTPUT_30_TO_60_MHZ       0x20 ///< 30-60 MHz.             
#define PLL0FLT_PLLICO__OUTPUT_25_TO_50_MHZ       0x30 ///< 25-50 MHz.             
                                                                                   
//------------------------------------------------------------------------------
// PLL0MUL Enums (PLL Multiplier @ 0x8E)
//------------------------------------------------------------------------------
#define PLL0MUL_PLLN__FMASK 0xFF ///< PLL Multiplier
#define PLL0MUL_PLLN__SHIFT 0x00 ///< PLL Multiplier
                                                    
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
// P1MDIN Enums (Port 1 Input Mode @ 0xAD)
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
// P3MDOUT Enums (Port 3 Output Mode @ 0xA7)
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
// P4 Enums (Port 4 Pin Latch @ 0xC8)
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
// P4MDOUT Enums (Port 4 Output Mode @ 0x9C)
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
// P5 Enums (Port 5 Pin Latch @ 0xD8)
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
// P5MDOUT Enums (Port 5 Output Mode @ 0x9D)
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
// P6 Enums (Port 6 Pin Latch @ 0xE8)
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
// P6MDOUT Enums (Port 6 Output Mode @ 0x9E)
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
// P7 Enums (Port 7 Pin Latch @ 0xF8)
//------------------------------------------------------------------------------
#define P7_B0__BMASK 0x01 ///< Port 7 Bit 0 Latch                            
#define P7_B0__SHIFT 0x00 ///< Port 7 Bit 0 Latch                            
#define P7_B0__LOW   0x00 ///< P7.0 is low. Set P7.0 to drive low.           
#define P7_B0__HIGH  0x01 ///< P7.0 is high. Set P7.0 to drive or float high.
                                                                             
#define P7_B1__BMASK 0x02 ///< Port 7 Bit 1 Latch                            
#define P7_B1__SHIFT 0x01 ///< Port 7 Bit 1 Latch                            
#define P7_B1__LOW   0x00 ///< P7.1 is low. Set P7.1 to drive low.           
#define P7_B1__HIGH  0x02 ///< P7.1 is high. Set P7.1 to drive or float high.
                                                                             
#define P7_B2__BMASK 0x04 ///< Port 7 Bit 2 Latch                            
#define P7_B2__SHIFT 0x02 ///< Port 7 Bit 2 Latch                            
#define P7_B2__LOW   0x00 ///< P7.2 is low. Set P7.2 to drive low.           
#define P7_B2__HIGH  0x04 ///< P7.2 is high. Set P7.2 to drive or float high.
                                                                             
#define P7_B3__BMASK 0x08 ///< Port 7 Bit 3 Latch                            
#define P7_B3__SHIFT 0x03 ///< Port 7 Bit 3 Latch                            
#define P7_B3__LOW   0x00 ///< P7.3 is low. Set P7.3 to drive low.           
#define P7_B3__HIGH  0x08 ///< P7.3 is high. Set P7.3 to drive or float high.
                                                                             
#define P7_B4__BMASK 0x10 ///< Port 7 Bit 4 Latch                            
#define P7_B4__SHIFT 0x04 ///< Port 7 Bit 4 Latch                            
#define P7_B4__LOW   0x00 ///< P7.4 is low. Set P7.4 to drive low.           
#define P7_B4__HIGH  0x10 ///< P7.4 is high. Set P7.4 to drive or float high.
                                                                             
#define P7_B5__BMASK 0x20 ///< Port 7 Bit 5 Latch                            
#define P7_B5__SHIFT 0x05 ///< Port 7 Bit 5 Latch                            
#define P7_B5__LOW   0x00 ///< P7.5 is low. Set P7.5 to drive low.           
#define P7_B5__HIGH  0x20 ///< P7.5 is high. Set P7.5 to drive or float high.
                                                                             
#define P7_B6__BMASK 0x40 ///< Port 7 Bit 6 Latch                            
#define P7_B6__SHIFT 0x06 ///< Port 7 Bit 6 Latch                            
#define P7_B6__LOW   0x00 ///< P7.6 is low. Set P7.6 to drive low.           
#define P7_B6__HIGH  0x40 ///< P7.6 is high. Set P7.6 to drive or float high.
                                                                             
#define P7_B7__BMASK 0x80 ///< Port 7 Bit 7 Latch                            
#define P7_B7__SHIFT 0x07 ///< Port 7 Bit 7 Latch                            
#define P7_B7__LOW   0x00 ///< P7.7 is low. Set P7.7 to drive low.           
#define P7_B7__HIGH  0x80 ///< P7.7 is high. Set P7.7 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P7MDOUT Enums (Port 7 Output Mode @ 0x9F)
//------------------------------------------------------------------------------
#define P7MDOUT_B0__BMASK      0x01 ///< Port 7 Bit 0 Output Mode  
#define P7MDOUT_B0__SHIFT      0x00 ///< Port 7 Bit 0 Output Mode  
#define P7MDOUT_B0__OPEN_DRAIN 0x00 ///< P7.0 output is open-drain.
#define P7MDOUT_B0__PUSH_PULL  0x01 ///< P7.0 output is push-pull. 
                                                                   
#define P7MDOUT_B1__BMASK      0x02 ///< Port 7 Bit 1 Output Mode  
#define P7MDOUT_B1__SHIFT      0x01 ///< Port 7 Bit 1 Output Mode  
#define P7MDOUT_B1__OPEN_DRAIN 0x00 ///< P7.1 output is open-drain.
#define P7MDOUT_B1__PUSH_PULL  0x02 ///< P7.1 output is push-pull. 
                                                                   
#define P7MDOUT_B2__BMASK      0x04 ///< Port 7 Bit 2 Output Mode  
#define P7MDOUT_B2__SHIFT      0x02 ///< Port 7 Bit 2 Output Mode  
#define P7MDOUT_B2__OPEN_DRAIN 0x00 ///< P7.2 output is open-drain.
#define P7MDOUT_B2__PUSH_PULL  0x04 ///< P7.2 output is push-pull. 
                                                                   
#define P7MDOUT_B3__BMASK      0x08 ///< Port 7 Bit 3 Output Mode  
#define P7MDOUT_B3__SHIFT      0x03 ///< Port 7 Bit 3 Output Mode  
#define P7MDOUT_B3__OPEN_DRAIN 0x00 ///< P7.3 output is open-drain.
#define P7MDOUT_B3__PUSH_PULL  0x08 ///< P7.3 output is push-pull. 
                                                                   
#define P7MDOUT_B4__BMASK      0x10 ///< Port 7 Bit 4 Output Mode  
#define P7MDOUT_B4__SHIFT      0x04 ///< Port 7 Bit 4 Output Mode  
#define P7MDOUT_B4__OPEN_DRAIN 0x00 ///< P7.4 output is open-drain.
#define P7MDOUT_B4__PUSH_PULL  0x10 ///< P7.4 output is push-pull. 
                                                                   
#define P7MDOUT_B5__BMASK      0x20 ///< Port 7 Bit 5 Output Mode  
#define P7MDOUT_B5__SHIFT      0x05 ///< Port 7 Bit 5 Output Mode  
#define P7MDOUT_B5__OPEN_DRAIN 0x00 ///< P7.5 output is open-drain.
#define P7MDOUT_B5__PUSH_PULL  0x20 ///< P7.5 output is push-pull. 
                                                                   
#define P7MDOUT_B6__BMASK      0x40 ///< Port 7 Bit 6 Output Mode  
#define P7MDOUT_B6__SHIFT      0x06 ///< Port 7 Bit 6 Output Mode  
#define P7MDOUT_B6__OPEN_DRAIN 0x00 ///< P7.6 output is open-drain.
#define P7MDOUT_B6__PUSH_PULL  0x40 ///< P7.6 output is push-pull. 
                                                                   
#define P7MDOUT_B7__BMASK      0x80 ///< Port 7 Bit 7 Output Mode  
#define P7MDOUT_B7__SHIFT      0x07 ///< Port 7 Bit 7 Output Mode  
#define P7MDOUT_B7__OPEN_DRAIN 0x00 ///< P7.7 output is open-drain.
#define P7MDOUT_B7__PUSH_PULL  0x80 ///< P7.7 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// RSTSRC Enums (Reset Source @ 0xEF)
//------------------------------------------------------------------------------
#define RSTSRC_PINRSF__BMASK    0x01 ///< HW Pin Reset Flag                                                    
#define RSTSRC_PINRSF__SHIFT    0x00 ///< HW Pin Reset Flag                                                    
#define RSTSRC_PINRSF__NOT_SET  0x00 ///< The /RST pin did not cause the last reset.                           
#define RSTSRC_PINRSF__SET      0x01 ///< The /RST pin caused the last reset.                                  
                                                                                                               
#define RSTSRC_PORSF__BMASK     0x02 ///< Power-On / Supply Monitor Reset Flag, and Supply Monitor Reset Enable
#define RSTSRC_PORSF__SHIFT     0x01 ///< Power-On / Supply Monitor Reset Flag, and Supply Monitor Reset Enable
#define RSTSRC_PORSF__NOT_SET   0x00 ///< A power-on or supply monitor reset did not occur.                    
#define RSTSRC_PORSF__SET       0x02 ///< A power-on or supply monitor reset occurred.                         
                                                                                                               
#define RSTSRC_MCDRSF__BMASK    0x04 ///< Missing Clock Detector Enable and Flag                               
#define RSTSRC_MCDRSF__SHIFT    0x02 ///< Missing Clock Detector Enable and Flag                               
#define RSTSRC_MCDRSF__NOT_SET  0x00 ///< A missing clock detector reset did not occur.                        
#define RSTSRC_MCDRSF__SET      0x04 ///< A missing clock detector reset occurred.                             
                                                                                                               
#define RSTSRC_WDTRSF__BMASK    0x08 ///< Watchdog Timer Reset Flag                                            
#define RSTSRC_WDTRSF__SHIFT    0x03 ///< Watchdog Timer Reset Flag                                            
#define RSTSRC_WDTRSF__NOT_SET  0x00 ///< A watchdog timer overflow reset did not occur.                       
#define RSTSRC_WDTRSF__SET      0x08 ///< A watchdog timer overflow reset occurred.                            
                                                                                                               
#define RSTSRC_SWRSF__BMASK     0x10 ///< Software Reset Force and Flag                                        
#define RSTSRC_SWRSF__SHIFT     0x04 ///< Software Reset Force and Flag                                        
#define RSTSRC_SWRSF__NOT_SET   0x00 ///< A software reset did not occur.                                      
#define RSTSRC_SWRSF__SET       0x10 ///< A software reset occurred.                                           
                                                                                                               
#define RSTSRC_C0RSEF__BMASK    0x20 ///< Comparator0 Reset Enable and Flag                                    
#define RSTSRC_C0RSEF__SHIFT    0x05 ///< Comparator0 Reset Enable and Flag                                    
#define RSTSRC_C0RSEF__NOT_SET  0x00 ///< A Comparator 0 reset did not occur.                                  
#define RSTSRC_C0RSEF__SET      0x20 ///< A Comparator 0 reset occurred.                                       
                                                                                                               
#define RSTSRC_CNVRSEF__BMASK   0x40 ///< Convert Start 0 Reset Source Enable and Flag                         
#define RSTSRC_CNVRSEF__SHIFT   0x06 ///< Convert Start 0 Reset Source Enable and Flag                         
#define RSTSRC_CNVRSEF__NOT_SET 0x00 ///< A CNVSTR0 reset did not occur.                                       
#define RSTSRC_CNVRSEF__SET     0x40 ///< A CNVSTR0 reset occurred.                                            
                                                                                                               
#define RSTSRC_RTC0RE__BMASK    0x80 ///< RTC Reset Enable and Flag                                            
#define RSTSRC_RTC0RE__SHIFT    0x07 ///< RTC Reset Enable and Flag                                            
#define RSTSRC_RTC0RE__NOT_SET  0x00 ///< A RTC alarm or oscillator fail reset did not                         
                                     ///< occur.                                                               
#define RSTSRC_RTC0RE__SET      0x80 ///< A RTC alarm or oscillator fail reset occurred.                       
                                                                                                               
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
// SFRPAGE Enums (SFR Page @ 0x84)
//------------------------------------------------------------------------------
#define SFRPAGE_SFRPAGE__FMASK 0xFF ///< SFR Page
#define SFRPAGE_SFRPAGE__SHIFT 0x00 ///< SFR Page
                                                 
//------------------------------------------------------------------------------
// SFRPGCN Enums (SFR Page Control @ 0x96)
//------------------------------------------------------------------------------
#define SFRPGCN_SFRPGEN__BMASK    0x01 ///< SFR Automatic Page Control Enable
#define SFRPGCN_SFRPGEN__SHIFT    0x00 ///< SFR Automatic Page Control Enable
#define SFRPGCN_SFRPGEN__DISABLED 0x00 ///< Disable automatic SFR paging.    
#define SFRPGCN_SFRPGEN__ENABLED  0x01 ///< Enable automatic SFR paging.     
                                                                             
//------------------------------------------------------------------------------
// SMB0ADR Enums (SMBus 0 Address @ 0xC3)
//------------------------------------------------------------------------------
#define SMB0ADR_GC__BMASK      0x01 ///< General Call Address Enable        
#define SMB0ADR_GC__SHIFT      0x00 ///< General Call Address Enable        
#define SMB0ADR_GC__IGNORED    0x00 ///< General Call Address is ignored.   
#define SMB0ADR_GC__RECOGNIZED 0x01 ///< General Call Address is recognized.
                                                                            
#define SMB0ADR_SLV__FMASK     0xFE ///< SMBus Slave Address                
#define SMB0ADR_SLV__SHIFT     0x01 ///< SMBus Slave Address                
                                                                            
//------------------------------------------------------------------------------
// SMB0CN Enums (SMBus 0 Control @ 0xC0)
//------------------------------------------------------------------------------
#define SMB0CN_TOE__BMASK            0x01 ///< SMBus Timeout Enable                              
#define SMB0CN_TOE__SHIFT            0x00 ///< SMBus Timeout Enable                              
#define SMB0CN_TOE__SCL_TO_DISABLED  0x00 ///< No timeout when SCL is low.                       
#define SMB0CN_TOE__SCL_TO_ENABLED   0x01 ///< Timeout when SCL low time exceeds limit specified 
                                          ///< by Timer 3, if enabled.                           
                                                                                                 
#define SMB0CN_FTE__BMASK            0x02 ///< SMBus Free Timer Enable                           
#define SMB0CN_FTE__SHIFT            0x01 ///< SMBus Free Timer Enable                           
#define SMB0CN_FTE__FREE_TO_DISABLED 0x00 ///< No timeout when SCL is high.                      
#define SMB0CN_FTE__FREE_TO_ENABLED  0x02 ///< Timeout when SCL high time exceeds limit specified
                                          ///< by the SMBCR value.                               
                                                                                                 
#define SMB0CN_AA__BMASK             0x04 ///< SMBus Assert Acknowledge Flag                     
#define SMB0CN_AA__SHIFT             0x02 ///< SMBus Assert Acknowledge Flag                     
#define SMB0CN_AA__NOT_SET           0x00 ///< A "not acknowledge" (high level on SDA) is        
                                          ///< returned during the acknowledge cycle.            
#define SMB0CN_AA__SET               0x04 ///< An "acknowledge" (low level on SDA) is returned   
                                          ///< during the acknowledge cycle.                     
                                                                                                 
#define SMB0CN_SI__BMASK             0x08 ///< SMBus Acknowledge Request                         
#define SMB0CN_SI__SHIFT             0x03 ///< SMBus Acknowledge Request                         
#define SMB0CN_SI__NOT_SET           0x00 ///< An SMBus interrupt did not occur.                 
#define SMB0CN_SI__SET               0x08 ///< An SMBus interrupt occurred.                      
                                                                                                 
#define SMB0CN_STO__BMASK            0x10 ///< SMBus Stop Flag                                   
#define SMB0CN_STO__SHIFT            0x04 ///< SMBus Stop Flag                                   
#define SMB0CN_STO__NOT_SET          0x00 ///< No STOP condition is transmitted.                 
#define SMB0CN_STO__SET              0x10 ///< Setting STO to logic 1 causes a STOP condition to 
                                          ///< be transmitted.                                   
                                                                                                 
#define SMB0CN_STA__BMASK            0x20 ///< SMBus Start Flag                                  
#define SMB0CN_STA__SHIFT            0x05 ///< SMBus Start Flag                                  
#define SMB0CN_STA__NOT_SET          0x00 ///< No START condition is transmitted.                
#define SMB0CN_STA__SET              0x20 ///< When operating as a master, a START condition is  
                                          ///< transmitted if the bus is free. (If the bus is not
                                          ///< free, the START is transmitted after a STOP is    
                                          ///< received.)                                        
                                                                                                 
#define SMB0CN_ENSMB__BMASK          0x40 ///< SMBus Enable                                      
#define SMB0CN_ENSMB__SHIFT          0x06 ///< SMBus Enable                                      
#define SMB0CN_ENSMB__DISABLED       0x00 ///< SMBus 0 disabled.                                 
#define SMB0CN_ENSMB__ENABLED        0x40 ///< SMBus 0 enabled.                                  
                                                                                                 
#define SMB0CN_BUSY__BMASK           0x80 ///< Busy Status Flag                                  
#define SMB0CN_BUSY__SHIFT           0x07 ///< Busy Status Flag                                  
#define SMB0CN_BUSY__NOT_SET         0x00 ///< SMBus 0 is free.                                  
#define SMB0CN_BUSY__SET             0x80 ///< SMBus 0 is busy.                                  
                                                                                                 
//------------------------------------------------------------------------------
// SMB0CR Enums (SMBus 0 Clock Rate @ 0xCF)
//------------------------------------------------------------------------------
#define SMB0CR_SMBCR__FMASK 0xFF ///< SMBus0 Clock Rate Preset
#define SMB0CR_SMBCR__SHIFT 0x00 ///< SMBus0 Clock Rate Preset
                                                              
//------------------------------------------------------------------------------
// SMB0DAT Enums (SMBus 0 Data @ 0xC2)
//------------------------------------------------------------------------------
#define SMB0DAT_SMB0DAT__FMASK 0xFF ///< SMBus 0 Data
#define SMB0DAT_SMB0DAT__SHIFT 0x00 ///< SMBus 0 Data
                                                     
//------------------------------------------------------------------------------
// SMB0STA Enums (SMBus 0 Status @ 0xC1)
//------------------------------------------------------------------------------
#define SMB0STA_STA__FMASK 0xFF ///< SMBus 0 Status
#define SMB0STA_STA__SHIFT 0x00 ///< SMBus 0 Status
                                                   
//------------------------------------------------------------------------------
// SPI0CFG Enums (SPI0 Configuration @ 0x9A)
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
// SPI0CKR Enums (SPI0 Clock Rate @ 0x9D)
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
// SPI0DAT Enums (SPI0 Data @ 0x9B)
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
// RCAP2H Enums (Timer 2 Capture Register High Byte @ 0xCB)
//------------------------------------------------------------------------------
#define RCAP2H_RCAP2L__FMASK 0xFF ///< Timer 2 Capture Register High Byte
#define RCAP2H_RCAP2L__SHIFT 0x00 ///< Timer 2 Capture Register High Byte
                                                                         
//------------------------------------------------------------------------------
// RCAP2L Enums (Timer 2 Capture Register Low Byte @ 0xCA)
//------------------------------------------------------------------------------
#define RCAP2L_RCAP2L__FMASK 0xFF ///< Timer 2 Capture Register Low Byte
#define RCAP2L_RCAP2L__SHIFT 0x00 ///< Timer 2 Capture Register Low Byte
                                                                        
//------------------------------------------------------------------------------
// TMR2CF Enums (Timer 2 Configuration @ 0xC9)
//------------------------------------------------------------------------------
#define TMR2CF_DCEN2__BMASK          0x01 ///< Decrement Enable                                  
#define TMR2CF_DCEN2__SHIFT          0x00 ///< Decrement Enable                                  
#define TMR2CF_DCEN2__DISABLED       0x00 ///< Timer will count up, regardless of the state of   
                                          ///< T2EX.                                             
#define TMR2CF_DCEN2__ENABLED        0x01 ///< Timer will count up or down depending on the state
                                          ///< of T2EX as follows: if T2EX = 0, the timer counts 
                                          ///< DOWN; if T2EX = 1, the timer counts UP.           
                                                                                                 
#define TMR2CF_T2OE__BMASK           0x02 ///< Timer Output Enable                               
#define TMR2CF_T2OE__SHIFT           0x01 ///< Timer Output Enable                               
#define TMR2CF_T2OE__OUTPUT_DISABLED 0x00 ///< Output of toggle mode not available at Timer's    
                                          ///< assigned port pin.                                
#define TMR2CF_T2OE__OUTPUT_ENABLED  0x02 ///< Output of toggle mode available at Timer's        
                                          ///< assigned port pin.                                
                                                                                                 
#define TMR2CF_TOG2__BMASK           0x04 ///< Toggle Output State                               
#define TMR2CF_TOG2__SHIFT           0x02 ///< Toggle Output State                               
#define TMR2CF_TOG2__NOT_SET         0x00 ///< Timer output is low. Set the timer output low.    
#define TMR2CF_TOG2__SET             0x04 ///< Timer output is high. Set the timer output high.  
                                                                                                 
#define TMR2CF_T2M__FMASK            0x18 ///< Timer Clock Mode Select                           
#define TMR2CF_T2M__SHIFT            0x03 ///< Timer Clock Mode Select                           
#define TMR2CF_T2M__SYSCLK_DIV_12    0x00 ///< System clock divided by 12.                       
#define TMR2CF_T2M__SYSCLK           0x08 ///< System clock.                                     
#define TMR2CF_T2M__EXTOSC_DIV_8     0x10 ///< External oscillator divided by 8 (synchronized    
                                          ///< with the system clock).                           
#define TMR2CF_T2M__SYSCLK_DIV_2     0x18 ///< System clock divided by 2.                        
                                                                                                 
//------------------------------------------------------------------------------
// TMR2CN Enums (Timer 2 Control @ 0xC8)
//------------------------------------------------------------------------------
#define TMR2CN_CPRL2__BMASK       0x01 ///< Capture/Reload Select                             
#define TMR2CN_CPRL2__SHIFT       0x00 ///< Capture/Reload Select                             
#define TMR2CN_CPRL2__AUTO_RELOAD 0x00 ///< Timer is in Auto-Reload Mode.                     
#define TMR2CN_CPRL2__CAPTURE     0x01 ///< Timer is in Capture Mode.                         
                                                                                              
#define TMR2CN_CT2__BMASK         0x02 ///< Counter/Timer Select                              
#define TMR2CN_CT2__SHIFT         0x01 ///< Counter/Timer Select                              
#define TMR2CN_CT2__TIMER         0x00 ///< Timer Function: Timer incremented by clock defined
                                       ///< by T2M.                                           
#define TMR2CN_CT2__COUNTER       0x02 ///< Counter Function: Timer incremented by high-to-low
                                       ///< transitions on external input pin.                
                                                                                              
#define TMR2CN_TR2__BMASK         0x04 ///< Timer 2 Run Control                               
#define TMR2CN_TR2__SHIFT         0x02 ///< Timer 2 Run Control                               
#define TMR2CN_TR2__STOP          0x00 ///< Stop Timer 2.                                     
#define TMR2CN_TR2__RUN           0x04 ///< Start Timer 2 running.                            
                                                                                              
#define TMR2CN_EXEN2__BMASK       0x08 ///< Timer 2 External Enable                           
#define TMR2CN_EXEN2__SHIFT       0x03 ///< Timer 2 External Enable                           
#define TMR2CN_EXEN2__DISABLED    0x00 ///< Transitions on the T2EX pin are ignored.          
#define TMR2CN_EXEN2__ENABLED     0x08 ///< Transitions on the T2EX pin cause capture, reload,
                                       ///< or control the direction of timer count (up or    
                                       ///< down).                                            
                                                                                              
#define TMR2CN_EXF2__BMASK        0x40 ///< Timer 2 External Flag                             
#define TMR2CN_EXF2__SHIFT        0x06 ///< Timer 2 External Flag                             
#define TMR2CN_EXF2__NOT_SET      0x00 ///< Timer 2 capture or reload did not occur.          
#define TMR2CN_EXF2__SET          0x40 ///< Timer 2 capture or reload occurred.               
                                                                                              
#define TMR2CN_TF2__BMASK         0x80 ///< Timer 2 Overflow/Underflow Flag                   
#define TMR2CN_TF2__SHIFT         0x07 ///< Timer 2 Overflow/Underflow Flag                   
#define TMR2CN_TF2__NOT_SET       0x00 ///< Timer 2 did not overflow or underflow.            
#define TMR2CN_TF2__SET           0x80 ///< Timer 2 overflowed or underflowed.                
                                                                                              
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
// RCAP3H Enums (Timer 3 Capture Register High Byte @ 0xCB)
//------------------------------------------------------------------------------
#define RCAP3H_RCAP3L__FMASK 0xFF ///< Timer 3 Capture Register High Byte
#define RCAP3H_RCAP3L__SHIFT 0x00 ///< Timer 3 Capture Register High Byte
                                                                         
//------------------------------------------------------------------------------
// RCAP3L Enums (Timer 3 Capture Register Low Byte @ 0xCA)
//------------------------------------------------------------------------------
#define RCAP3L_RCAP3L__FMASK 0xFF ///< Timer 3 Capture Register Low Byte
#define RCAP3L_RCAP3L__SHIFT 0x00 ///< Timer 3 Capture Register Low Byte
                                                                        
//------------------------------------------------------------------------------
// TMR3CF Enums (Timer 3 Configuration @ 0xC9)
//------------------------------------------------------------------------------
#define TMR3CF_DCEN3__BMASK          0x01 ///< Decrement Enable                                  
#define TMR3CF_DCEN3__SHIFT          0x00 ///< Decrement Enable                                  
#define TMR3CF_DCEN3__DISABLED       0x00 ///< Timer will count up, regardless of the state of   
                                          ///< T3EX.                                             
#define TMR3CF_DCEN3__ENABLED        0x01 ///< Timer will count up or down depending on the state
                                          ///< of T3EX as follows: if T3EX = 0, the timer counts 
                                          ///< DOWN; if T3EX = 1, the timer counts UP.           
                                                                                                 
#define TMR3CF_T3OE__BMASK           0x02 ///< Timer Output Enable                               
#define TMR3CF_T3OE__SHIFT           0x01 ///< Timer Output Enable                               
#define TMR3CF_T3OE__OUTPUT_DISABLED 0x00 ///< Output of toggle mode not available at Timer's    
                                          ///< assigned port pin.                                
#define TMR3CF_T3OE__OUTPUT_ENABLED  0x02 ///< Output of toggle mode available at Timer's        
                                          ///< assigned port pin.                                
                                                                                                 
#define TMR3CF_TOG3__BMASK           0x04 ///< Toggle Output State                               
#define TMR3CF_TOG3__SHIFT           0x02 ///< Toggle Output State                               
#define TMR3CF_TOG3__NOT_SET         0x00 ///< Timer output is low. Set the timer output low.    
#define TMR3CF_TOG3__SET             0x04 ///< Timer output is high. Set the timer output high.  
                                                                                                 
#define TMR3CF_T3M__FMASK            0x18 ///< Timer Clock Mode Select                           
#define TMR3CF_T3M__SHIFT            0x03 ///< Timer Clock Mode Select                           
#define TMR3CF_T3M__SYSCLK_DIV_12    0x00 ///< System clock divided by 12.                       
#define TMR3CF_T3M__SYSCLK           0x08 ///< System clock.                                     
#define TMR3CF_T3M__EXTOSC_DIV_8     0x10 ///< External oscillator divided by 8 (synchronized    
                                          ///< with the system clock).                           
#define TMR3CF_T3M__SYSCLK_DIV_2     0x18 ///< System clock divided by 2.                        
                                                                                                 
//------------------------------------------------------------------------------
// TMR3CN Enums (Timer 3 Control @ 0xC8)
//------------------------------------------------------------------------------
#define TMR3CN_CPRL3__BMASK       0x01 ///< Capture/Reload Select                             
#define TMR3CN_CPRL3__SHIFT       0x00 ///< Capture/Reload Select                             
#define TMR3CN_CPRL3__AUTO_RELOAD 0x00 ///< Timer is in Auto-Reload Mode.                     
#define TMR3CN_CPRL3__CAPTURE     0x01 ///< Timer is in Capture Mode.                         
                                                                                              
#define TMR3CN_CT3__BMASK         0x02 ///< Counter/Timer Select                              
#define TMR3CN_CT3__SHIFT         0x01 ///< Counter/Timer Select                              
#define TMR3CN_CT3__TIMER         0x00 ///< Timer Function: Timer incremented by clock defined
                                       ///< by T3M.                                           
#define TMR3CN_CT3__COUNTER       0x02 ///< Counter Function: Timer incremented by high-to-low
                                       ///< transitions on external input pin.                
                                                                                              
#define TMR3CN_TR3__BMASK         0x04 ///< Timer 3 Run Control                               
#define TMR3CN_TR3__SHIFT         0x02 ///< Timer 3 Run Control                               
#define TMR3CN_TR3__STOP          0x00 ///< Stop Timer 3.                                     
#define TMR3CN_TR3__RUN           0x04 ///< Start Timer 3 running.                            
                                                                                              
#define TMR3CN_EXEN3__BMASK       0x08 ///< Timer 3 External Enable                           
#define TMR3CN_EXEN3__SHIFT       0x03 ///< Timer 3 External Enable                           
#define TMR3CN_EXEN3__DISABLED    0x00 ///< Transitions on the T3EX pin are ignored.          
#define TMR3CN_EXEN3__ENABLED     0x08 ///< Transitions on the T3EX pin cause capture, reload,
                                       ///< or control the direction of timer count (up or    
                                       ///< down).                                            
                                                                                              
#define TMR3CN_EXF3__BMASK        0x40 ///< Timer 3 External Flag                             
#define TMR3CN_EXF3__SHIFT        0x06 ///< Timer 3 External Flag                             
#define TMR3CN_EXF3__NOT_SET      0x00 ///< Timer 3 capture or reload did not occur.          
#define TMR3CN_EXF3__SET          0x40 ///< Timer 3 capture or reload occurred.               
                                                                                              
#define TMR3CN_TF3__BMASK         0x80 ///< Timer 3 Overflow/Underflow Flag                   
#define TMR3CN_TF3__SHIFT         0x07 ///< Timer 3 Overflow/Underflow Flag                   
#define TMR3CN_TF3__NOT_SET       0x00 ///< Timer 3 did not overflow or underflow.            
#define TMR3CN_TF3__SET           0x80 ///< Timer 3 overflowed or underflowed.                
                                                                                              
//------------------------------------------------------------------------------
// TMR3H Enums (Timer 3 High Byte @ 0xCD)
//------------------------------------------------------------------------------
#define TMR3H_TMR3H__FMASK 0xFF ///< Timer 3 High Byte
#define TMR3H_TMR3H__SHIFT 0x00 ///< Timer 3 High Byte
                                                      
//------------------------------------------------------------------------------
// TMR3L Enums (Timer 3 Low Byte @ 0xCC)
//------------------------------------------------------------------------------
#define TMR3L_TMR3L__FMASK 0xFF ///< Timer 3 Low Byte
#define TMR3L_TMR3L__SHIFT 0x00 ///< Timer 3 Low Byte
                                                     
//------------------------------------------------------------------------------
// RCAP4H Enums (Timer 4 Capture Register High Byte @ 0xCB)
//------------------------------------------------------------------------------
#define RCAP4H_RCAP4L__FMASK 0xFF ///< Timer 4 Capture Register High Byte
#define RCAP4H_RCAP4L__SHIFT 0x00 ///< Timer 4 Capture Register High Byte
                                                                         
//------------------------------------------------------------------------------
// RCAP4L Enums (Timer 4 Capture Register Low Byte @ 0xCA)
//------------------------------------------------------------------------------
#define RCAP4L_RCAP4L__FMASK 0xFF ///< Timer 4 Capture Register Low Byte
#define RCAP4L_RCAP4L__SHIFT 0x00 ///< Timer 4 Capture Register Low Byte
                                                                        
//------------------------------------------------------------------------------
// TMR4CF Enums (Timer 4 Configuration @ 0xC9)
//------------------------------------------------------------------------------
#define TMR4CF_DCEN4__BMASK          0x01 ///< Decrement Enable                                  
#define TMR4CF_DCEN4__SHIFT          0x00 ///< Decrement Enable                                  
#define TMR4CF_DCEN4__DISABLED       0x00 ///< Timer will count up, regardless of the state of   
                                          ///< T4EX.                                             
#define TMR4CF_DCEN4__ENABLED        0x01 ///< Timer will count up or down depending on the state
                                          ///< of T4EX as follows: if T4EX = 0, the timer counts 
                                          ///< DOWN; if T4EX = 1, the timer counts UP.           
                                                                                                 
#define TMR4CF_T4OE__BMASK           0x02 ///< Timer Output Enable                               
#define TMR4CF_T4OE__SHIFT           0x01 ///< Timer Output Enable                               
#define TMR4CF_T4OE__OUTPUT_DISABLED 0x00 ///< Output of toggle mode not available at Timer's    
                                          ///< assigned port pin.                                
#define TMR4CF_T4OE__OUTPUT_ENABLED  0x02 ///< Output of toggle mode available at Timer's        
                                          ///< assigned port pin.                                
                                                                                                 
#define TMR4CF_TOG4__BMASK           0x04 ///< Toggle Output State                               
#define TMR4CF_TOG4__SHIFT           0x02 ///< Toggle Output State                               
#define TMR4CF_TOG4__NOT_SET         0x00 ///< Timer output is low. Set the timer output low.    
#define TMR4CF_TOG4__SET             0x04 ///< Timer output is high. Set the timer output high.  
                                                                                                 
#define TMR4CF_T4M__FMASK            0x18 ///< Timer Clock Mode Select                           
#define TMR4CF_T4M__SHIFT            0x03 ///< Timer Clock Mode Select                           
#define TMR4CF_T4M__SYSCLK_DIV_12    0x00 ///< System clock divided by 12.                       
#define TMR4CF_T4M__SYSCLK           0x08 ///< System clock.                                     
#define TMR4CF_T4M__EXTOSC_DIV_8     0x10 ///< External oscillator divided by 8 (synchronized    
                                          ///< with the system clock).                           
#define TMR4CF_T4M__SYSCLK_DIV_2     0x18 ///< System clock divided by 2.                        
                                                                                                 
//------------------------------------------------------------------------------
// TMR4CN Enums (Timer 4 Control @ 0xC8)
//------------------------------------------------------------------------------
#define TMR4CN_CPRL4__BMASK       0x01 ///< Capture/Reload Select                             
#define TMR4CN_CPRL4__SHIFT       0x00 ///< Capture/Reload Select                             
#define TMR4CN_CPRL4__AUTO_RELOAD 0x00 ///< Timer is in Auto-Reload Mode.                     
#define TMR4CN_CPRL4__CAPTURE     0x01 ///< Timer is in Capture Mode.                         
                                                                                              
#define TMR4CN_CT4__BMASK         0x02 ///< Counter/Timer Select                              
#define TMR4CN_CT4__SHIFT         0x01 ///< Counter/Timer Select                              
#define TMR4CN_CT4__TIMER         0x00 ///< Timer Function: Timer incremented by clock defined
                                       ///< by T4M.                                           
#define TMR4CN_CT4__COUNTER       0x02 ///< Counter Function: Timer incremented by high-to-low
                                       ///< transitions on external input pin.                
                                                                                              
#define TMR4CN_TR4__BMASK         0x04 ///< Timer 4 Run Control                               
#define TMR4CN_TR4__SHIFT         0x02 ///< Timer 4 Run Control                               
#define TMR4CN_TR4__STOP          0x00 ///< Stop Timer 4.                                     
#define TMR4CN_TR4__RUN           0x04 ///< Start Timer 4 running.                            
                                                                                              
#define TMR4CN_EXEN4__BMASK       0x08 ///< Timer 4 External Enable                           
#define TMR4CN_EXEN4__SHIFT       0x03 ///< Timer 4 External Enable                           
#define TMR4CN_EXEN4__DISABLED    0x00 ///< Transitions on the T4EX pin are ignored.          
#define TMR4CN_EXEN4__ENABLED     0x08 ///< Transitions on the T4EX pin cause capture, reload,
                                       ///< or control the direction of timer count (up or    
                                       ///< down).                                            
                                                                                              
#define TMR4CN_EXF4__BMASK        0x40 ///< Timer 4 External Flag                             
#define TMR4CN_EXF4__SHIFT        0x06 ///< Timer 4 External Flag                             
#define TMR4CN_EXF4__NOT_SET      0x00 ///< Timer 4 capture or reload did not occur.          
#define TMR4CN_EXF4__SET          0x40 ///< Timer 4 capture or reload occurred.               
                                                                                              
#define TMR4CN_TF4__BMASK         0x80 ///< Timer 4 Overflow/Underflow Flag                   
#define TMR4CN_TF4__SHIFT         0x07 ///< Timer 4 Overflow/Underflow Flag                   
#define TMR4CN_TF4__NOT_SET       0x00 ///< Timer 4 did not overflow or underflow.            
#define TMR4CN_TF4__SET           0x80 ///< Timer 4 overflowed or underflowed.                
                                                                                              
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
// CKCON Enums (Clock Control @ 0x8E)
//------------------------------------------------------------------------------
#define CKCON_SCA__FMASK         0x03 ///< Timer 0/1 Prescale                            
#define CKCON_SCA__SHIFT         0x00 ///< Timer 0/1 Prescale                            
#define CKCON_SCA__SYSCLK_DIV_12 0x00 ///< System clock divided by 12.                   
#define CKCON_SCA__SYSCLK_DIV_4  0x01 ///< System clock divided by 4.                    
#define CKCON_SCA__SYSCLK_DIV_48 0x02 ///< System clock divided by 48.                   
#define CKCON_SCA__EXTOSC_DIV_8  0x03 ///< External oscillator divided by 8 (synchronized
                                      ///< with the system clock).                       
                                                                                         
#define CKCON_T0M__BMASK         0x08 ///< Timer 0 Clock Select                          
#define CKCON_T0M__SHIFT         0x03 ///< Timer 0 Clock Select                          
#define CKCON_T0M__PRESCALE      0x00 ///< Counter/Timer 0 uses the clock defined by the 
                                      ///< prescale field, SCA.                          
#define CKCON_T0M__SYSCLK        0x08 ///< Counter/Timer 0 uses the system clock.        
                                                                                         
#define CKCON_T1M__BMASK         0x10 ///< Timer 1 Clock Select                          
#define CKCON_T1M__SHIFT         0x04 ///< Timer 1 Clock Select                          
#define CKCON_T1M__PRESCALE      0x00 ///< Timer 1 uses the clock defined by the prescale
                                      ///< field, SCA.                                   
#define CKCON_T1M__SYSCLK        0x10 ///< Timer 1 uses the system clock.                
                                                                                         
//------------------------------------------------------------------------------
// TCON Enums (Timer 0/1 Control @ 0x88)
//------------------------------------------------------------------------------
#define TCON_IT0__BMASK   0x01 ///< Interrupt 0 Type Select               
#define TCON_IT0__SHIFT   0x00 ///< Interrupt 0 Type Select               
#define TCON_IT0__LEVEL   0x00 ///< /INT0 is level triggered, active low. 
#define TCON_IT0__EDGE    0x01 ///< /INT0 is edge triggered, falling-edge.
                                                                          
#define TCON_IE0__BMASK   0x02 ///< External Interrupt 0                  
#define TCON_IE0__SHIFT   0x01 ///< External Interrupt 0                  
#define TCON_IE0__NOT_SET 0x00 ///< Edge/level not detected.              
#define TCON_IE0__SET     0x02 ///< Edge/level detected                   
                                                                          
#define TCON_IT1__BMASK   0x04 ///< Interrupt 1 Type Select               
#define TCON_IT1__SHIFT   0x02 ///< Interrupt 1 Type Select               
#define TCON_IT1__LEVEL   0x00 ///< /INT1 is level triggered, active low. 
#define TCON_IT1__EDGE    0x04 ///< /INT1 is edge triggered, falling-edge.
                                                                          
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
                                  ///< active.                                           
                                                                                         
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
                                  ///< active.                                           
                                                                                         
//------------------------------------------------------------------------------
// SADDR0 Enums (UART0 Slave Address @ 0xA9)
//------------------------------------------------------------------------------
#define SADDR0_SADDR0__FMASK 0xFF ///< UART0 Slave Address
#define SADDR0_SADDR0__SHIFT 0x00 ///< UART0 Slave Address
                                                          
//------------------------------------------------------------------------------
// SADEN0 Enums (UART0 Slave Address Enable @ 0xB9)
//------------------------------------------------------------------------------
#define SADEN0_SADEN0__FMASK 0xFF ///< UART0 Slave Address Enable
#define SADEN0_SADEN0__SHIFT 0x00 ///< UART0 Slave Address Enable
                                                                 
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
                                                                                               
#define SCON0_SM2__BMASK            0x20 ///< Multiprocessor Communication Enable              
#define SCON0_SM2__SHIFT            0x05 ///< Multiprocessor Communication Enable              
#define SCON0_SM2__MULTI_DISABLED   0x00 ///< Multiprocessor communication disabled.           
#define SCON0_SM2__MULTI_ENABLED    0x20 ///< Multiprocessor communication enabled.            
                                                                                               
#define SCON0_SM__FMASK             0xC0 ///< Serial Port 0 Operation Mode                     
#define SCON0_SM__SHIFT             0x06 ///< Serial Port 0 Operation Mode                     
#define SCON0_SM__MODE0             0x00 ///< Mode 0: Sychronous Mode                          
#define SCON0_SM__MODE1             0x40 ///< Mode 1: 8-bit UART, Variable Baud Rate           
#define SCON0_SM__MODE2             0x80 ///< Mode 2: 9-bit UART, Fixed Baud Rate              
#define SCON0_SM__MODE3             0xC0 ///< Mode 3: 9-bit UART, Variable Baud Rate           
                                                                                               
//------------------------------------------------------------------------------
// SSTA0 Enums (UART0 Status and Clock Selection @ 0x91)
//------------------------------------------------------------------------------
#define SSTA0_S0RCLK__FMASK          0x03 ///< UART0 Receive Baud Rate Clock Selection        
#define SSTA0_S0RCLK__SHIFT          0x00 ///< UART0 Receive Baud Rate Clock Selection        
#define SSTA0_S0RCLK__TIMER1         0x00 ///< Timer 1 generates UART0 RX baud rate.          
#define SSTA0_S0RCLK__TIMER2         0x01 ///< Timer 2 overflow generates UART0 RX baud rate. 
#define SSTA0_S0RCLK__TIMER3         0x02 ///< Timer 3 overflow generates UART0 RX baud rate. 
#define SSTA0_S0RCLK__TIMER4         0x03 ///< Timer 4 overflow generates UART0 RX baud rate. 
                                                                                              
#define SSTA0_S0TCLK__FMASK          0x0C ///< UART0 Transmit Baud Rate Clock Selection       
#define SSTA0_S0TCLK__SHIFT          0x02 ///< UART0 Transmit Baud Rate Clock Selection       
#define SSTA0_S0TCLK__TIMER1         0x00 ///< Timer 1 generates UART0 TX baud rate.          
#define SSTA0_S0TCLK__TIMER2         0x04 ///< Timer 2 overflow generates UART0 TX baud rate. 
#define SSTA0_S0TCLK__TIMER3         0x08 ///< Timer 3 overflow generates UART0 TX baud rate. 
#define SSTA0_S0TCLK__TIMER4         0x0C ///< Timer 4 overflow generates UART0 TX baud rate. 
                                                                                              
#define SSTA0_SMOD__BMASK            0x10 ///< UART0 Baud Rate Doubler Enable                 
#define SSTA0_SMOD__SHIFT            0x04 ///< UART0 Baud Rate Doubler Enable                 
#define SSTA0_SMOD__DOUBLER_DISABLED 0x00 ///< UART0 baud rate divide-by-two enabled (doubler 
                                          ///< disabled).                                     
#define SSTA0_SMOD__DOUBLER_ENABLED  0x10 ///< UART0 baud rate divide-by-two disabled (doubler
                                          ///< enabled).                                      
                                                                                              
#define SSTA0_TXCOL__BMASK           0x20 ///< Transmit Collision Flag                        
#define SSTA0_TXCOL__SHIFT           0x05 ///< Transmit Collision Flag                        
#define SSTA0_TXCOL__NOT_SET         0x00 ///< Transmission collision has not been detected.  
#define SSTA0_TXCOL__SET             0x20 ///< Transmission collision has been detected.      
                                                                                              
#define SSTA0_RXOV__BMASK            0x40 ///< Receive Overrun Flag                           
#define SSTA0_RXOV__SHIFT            0x06 ///< Receive Overrun Flag                           
#define SSTA0_RXOV__NOT_SET          0x00 ///< Receive overrun has not been detected.         
#define SSTA0_RXOV__SET              0x40 ///< Receive overrun has been detected.             
                                                                                              
#define SSTA0_FE__BMASK              0x80 ///< Frame Error Flag                               
#define SSTA0_FE__SHIFT              0x07 ///< Frame Error Flag                               
#define SSTA0_FE__NOT_SET            0x00 ///< Frame Error has not been detected              
#define SSTA0_FE__SET                0x80 ///< Frame Error has been detected.                 
                                                                                              
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
// REF0CN Enums (Voltage Reference Control @ 0xD1)
//------------------------------------------------------------------------------
#define REF0CN_REFBE__BMASK         0x01 ///< Internal Reference Buffer Enable                  
#define REF0CN_REFBE__SHIFT         0x00 ///< Internal Reference Buffer Enable                  
#define REF0CN_REFBE__REF_DISABLED  0x00 ///< Internal reference buffer off.                    
#define REF0CN_REFBE__REF_ENABLED   0x01 ///< Internal reference buffer on. The internal voltage
                                         ///< reference is driven on the VREF pin.              
                                                                                                
#define REF0CN_BIASE__BMASK         0x02 ///< ADC/DAC Bias Generator Enable                     
#define REF0CN_BIASE__SHIFT         0x01 ///< ADC/DAC Bias Generator Enable                     
#define REF0CN_BIASE__BIAS_DISABLED 0x00 ///< Internal bias generator off.                      
#define REF0CN_BIASE__BIAS_ENABLED  0x02 ///< Internal bias generator on.                       
                                                                                                
#define REF0CN_TEMPE__BMASK         0x04 ///< Temperature Sensor Enable                         
#define REF0CN_TEMPE__SHIFT         0x02 ///< Temperature Sensor Enable                         
#define REF0CN_TEMPE__TEMP_DISABLED 0x00 ///< Disable the Temperature Sensor.                   
#define REF0CN_TEMPE__TEMP_ENABLED  0x04 ///< Enable the Temperature Sensor.                    
                                                                                                
#define REF0CN_AD2VRS__BMASK        0x08 ///< ADC2 Voltage Reference Select                     
#define REF0CN_AD2VRS__SHIFT        0x03 ///< ADC2 Voltage Reference Select                     
#define REF0CN_AD2VRS__VREF2_PIN    0x00 ///< ADC2 voltage reference from VREF2 pin.            
#define REF0CN_AD2VRS__AV_PLUS      0x08 ///< ADC2 voltage reference from AV+.                  
                                                                                                
#define REF0CN_REFSL__FMASK         0x18 ///< Voltage Reference Select                          
#define REF0CN_REFSL__SHIFT         0x03 ///< Voltage Reference Select                          
#define REF0CN_REFSL__VREF_PIN      0x00 ///< The ADC0 voltage reference is the P0.0/VREF pin.  
#define REF0CN_REFSL__VDD_PIN       0x08 ///< The ADC0 voltage reference is the VDD pin.        
#define REF0CN_REFSL__INTERNAL_LDO  0x10 ///< The ADC0 voltage reference is the internal 1.8 V  
                                         ///< digital supply voltage.                           
#define REF0CN_REFSL__INTERNAL_VREF 0x18 ///< The ADC0 voltage reference is the internal voltage
                                         ///< reference.                                        
                                                                                                
#define REF0CN_AD0VRS__BMASK        0x10 ///< ADC0 Voltage Reference Select                     
#define REF0CN_AD0VRS__SHIFT        0x04 ///< ADC0 Voltage Reference Select                     
#define REF0CN_AD0VRS__VREF0_PIN    0x00 ///< ADC0 voltage reference from VREF0 pin.            
#define REF0CN_AD0VRS__DAC0_OUTPUT  0x10 ///< ADC0 voltage reference from the DAC0 output.      
                                                                                                
#define REF0CN_GNDSL__BMASK         0x20 ///< Analog Ground Reference                           
#define REF0CN_GNDSL__SHIFT         0x05 ///< Analog Ground Reference                           
#define REF0CN_GNDSL__GND_PIN       0x00 ///< The ADC0 ground reference is the GND pin.         
#define REF0CN_GNDSL__AGND_PIN      0x20 ///< The ADC0 ground reference is the P0.1/AGND pin.   
                                                                                                
#define REF0CN_IREFLVL__BMASK       0x80 ///< Internal Voltage Reference Level                  
#define REF0CN_IREFLVL__SHIFT       0x07 ///< Internal Voltage Reference Level                  
#define REF0CN_IREFLVL__1P65        0x00 ///< The internal reference operates at 1.65 V nominal.
#define REF0CN_IREFLVL__2P4         0x80 ///< The internal reference operates at 2.4 V nominal. 
                                                                                                
//------------------------------------------------------------------------------
// WDTCN Enums (Watchdog Timer Control @ 0xFF)
//------------------------------------------------------------------------------
#define WDTCN_WDTCN__FMASK 0xFF ///< WDT Control
#define WDTCN_WDTCN__SHIFT 0x00 ///< WDT Control
                                                
//------------------------------------------------------------------------------
// EMI0CF Enums (External Memory Configuration @ 0xA3)
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
                                                                                                          
#define EMI0CF_PRTSEL__BMASK                  0x20 ///< EMIF Port Select                                  
#define EMI0CF_PRTSEL__SHIFT                  0x05 ///< EMIF Port Select                                  
#define EMI0CF_PRTSEL__P0_P3                  0x00 ///< EMIF active on P0-P3.                             
#define EMI0CF_PRTSEL__P4_P7                  0x20 ///< EMIF active on P4-P7.                             
                                                                                                          
//------------------------------------------------------------------------------
// EMI0CN Enums (External Memory Interface Control @ 0xA2)
//------------------------------------------------------------------------------
#define EMI0CN_PGSEL__FMASK 0xFF ///< XRAM Page Select
#define EMI0CN_PGSEL__SHIFT 0x00 ///< XRAM Page Select
                                                      
//------------------------------------------------------------------------------
// EMI0TC Enums (External Memory Timing Control @ 0xA1)
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
                                                                                       
#endif // SI_C8051F120_REGISTER_ENUMS_H
//-eof--------------------------------------------------------------------------

