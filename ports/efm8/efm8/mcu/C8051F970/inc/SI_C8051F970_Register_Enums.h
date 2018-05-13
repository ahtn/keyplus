//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  C8051F970_GM
//  C8051F971_GM
//  C8051F972_GM
//  C8051F973_GM
//  C8051F974_GM
//  C8051F975_GM

#ifndef SI_C8051F970_REGISTER_ENUMS_H
#define SI_C8051F970_REGISTER_ENUMS_H

//Standard device includes
#include "SI_C8051F970_Defs.h"
//------------------------------------------------------------------------------
// ADC0AC Enums (ADC0 Accumulator Configuration @ 0xBA)
//------------------------------------------------------------------------------
#define ADC0AC_ADRPT__FMASK           0x07 ///< Repeat Count                                      
#define ADC0AC_ADRPT__SHIFT           0x00 ///< Repeat Count                                      
#define ADC0AC_ADRPT__ACC_1           0x00 ///< Perform and Accumulate 1 conversion.              
#define ADC0AC_ADRPT__ACC_4           0x01 ///< Perform and Accumulate 4 conversions.             
#define ADC0AC_ADRPT__ACC_8           0x02 ///< Perform and Accumulate 8 conversions.             
#define ADC0AC_ADRPT__ACC_16          0x03 ///< Perform and Accumulate 16 conversions.            
#define ADC0AC_ADRPT__ACC_32          0x04 ///< Perform and Accumulate 32 conversions.            
#define ADC0AC_ADRPT__ACC_64          0x05 ///< Perform and Accumulate 64 conversions.            
                                                                                                  
#define ADC0AC_ADSJST__FMASK          0x38 ///< Accumulator Shift and Justify                     
#define ADC0AC_ADSJST__SHIFT          0x03 ///< Accumulator Shift and Justify                     
#define ADC0AC_ADSJST__RIGHT_NO_SHIFT 0x00 ///< Right justified. No shifting applied.             
#define ADC0AC_ADSJST__RIGHT_SHIFT_1  0x08 ///< Right justified. Shifted right by 1 bit.          
#define ADC0AC_ADSJST__RIGHT_SHIFT_2  0x10 ///< Right justified. Shifted right by 2 bits.         
#define ADC0AC_ADSJST__RIGHT_SHIFT_3  0x18 ///< Right justified. Shifted right by 3 bits.         
#define ADC0AC_ADSJST__LEFT_NO_SHIFT  0x20 ///< Left justified. No shifting applied.              
                                                                                                  
#define ADC0AC_ADAE__BMASK            0x40 ///< Accumulate Enable                                 
#define ADC0AC_ADAE__SHIFT            0x06 ///< Accumulate Enable                                 
#define ADC0AC_ADAE__ACC_DISABLED     0x00 ///< ADC0H:ADC0L contain the result of the latest      
                                           ///< conversion when Burst Mode is disabled.           
#define ADC0AC_ADAE__ACC_ENABLED      0x40 ///< ADC0H:ADC0L contain the accumulated conversion    
                                           ///< results when Burst Mode is disabled. Firmware must
                                           ///< write 0x0000 to ADC0H:ADC0L to clear the          
                                           ///< accumulated result.                               
                                                                                                  
//------------------------------------------------------------------------------
// ADC0CF Enums (ADC0 Configuration @ 0x97)
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
#define ADC0CF_AD8BE__NORMAL       0x00 ///< ADC0 operates in 10-bit mode (normal operation).  
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
#define ADC0CN_ADBMEN__BURST_DISABLED 0x00 ///< ADC0 Burst Mode Disabled.                         
#define ADC0CN_ADBMEN__BURST_ENABLED  0x40 ///< ADC0 Burst Mode Enabled.                          
                                                                                                  
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
// ADC0H Enums (ADC0 Data Word High Byte @ 0xD3)
//------------------------------------------------------------------------------
#define ADC0H_ADC0H__FMASK 0xFF ///< Data Word High Byte
#define ADC0H_ADC0H__SHIFT 0x00 ///< Data Word High Byte
                                                        
//------------------------------------------------------------------------------
// ADC0L Enums (ADC0 Data Word Low Byte @ 0xD2)
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
// ADC0MX Enums (ADC0 Multiplexer Selection @ 0xD4)
//------------------------------------------------------------------------------
#define ADC0MX_ADC0MX__FMASK  0x1F ///< ADC0 Positive Input Selection 
#define ADC0MX_ADC0MX__SHIFT  0x00 ///< ADC0 Positive Input Selection 
#define ADC0MX_ADC0MX__ADC0P0 0x00 ///< Select channel ADC0.0.        
#define ADC0MX_ADC0MX__TEMP   0x1B ///< Temperature Sensor.           
#define ADC0MX_ADC0MX__VDD    0x1C ///< VDD Supply Voltage.           
#define ADC0MX_ADC0MX__LDO    0x1D ///< Internal LDO regulator output.
#define ADC0MX_ADC0MX__GND    0x1F ///< Ground.                       
                                                                      
//------------------------------------------------------------------------------
// ADC0PWR Enums (ADC0 Power Control @ 0xBB)
//------------------------------------------------------------------------------
#define ADC0PWR_ADPWR__FMASK              0x0F ///< Burst Mode Power Up Time                         
#define ADC0PWR_ADPWR__SHIFT              0x00 ///< Burst Mode Power Up Time                         
                                                                                                     
#define ADC0PWR_ADLPM__BMASK              0x80 ///< Low Power Mode Enable                            
#define ADC0PWR_ADLPM__SHIFT              0x07 ///< Low Power Mode Enable                            
#define ADC0PWR_ADLPM__LOW_POWER_DISABLED 0x00 ///< Disable low power mode.                          
#define ADC0PWR_ADLPM__LOW_POWER_ENABLED  0x80 ///< Enable low power mode (requires extended tracking
                                               ///< time).                                           
                                                                                                     
//------------------------------------------------------------------------------
// ADC0TK Enums (ADC0 Burst Mode Track Time @ 0xBC)
//------------------------------------------------------------------------------
#define ADC0TK_ADTK__FMASK 0x3F ///< Burst Mode Tracking Time
#define ADC0TK_ADTK__SHIFT 0x00 ///< Burst Mode Tracking Time
                                                             
//------------------------------------------------------------------------------
// AMUX0P0 Enums (Port 0 Analog Multiplexer Control @ 0x9A)
//------------------------------------------------------------------------------
#define AMUX0P0_B0__BMASK         0x01 ///< Port 0 Bit 0 Analog Multiplexor Control        
#define AMUX0P0_B0__SHIFT         0x00 ///< Port 0 Bit 0 Analog Multiplexor Control        
#define AMUX0P0_B0__NOT_CONNECTED 0x00 ///< P0.0 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P0_B0__CONNECTED     0x01 ///< P0.0 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P0_B1__BMASK         0x02 ///< Port 0 Bit 1 Analog Multiplexor Control        
#define AMUX0P0_B1__SHIFT         0x01 ///< Port 0 Bit 1 Analog Multiplexor Control        
#define AMUX0P0_B1__NOT_CONNECTED 0x00 ///< P0.1 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P0_B1__CONNECTED     0x02 ///< P0.1 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P0_B2__BMASK         0x04 ///< Port 0 Bit 2 Analog Multiplexor Control        
#define AMUX0P0_B2__SHIFT         0x02 ///< Port 0 Bit 2 Analog Multiplexor Control        
#define AMUX0P0_B2__NOT_CONNECTED 0x00 ///< P0.2 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P0_B2__CONNECTED     0x04 ///< P0.2 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P0_B3__BMASK         0x08 ///< Port 0 Bit 3 Analog Multiplexor Control        
#define AMUX0P0_B3__SHIFT         0x03 ///< Port 0 Bit 3 Analog Multiplexor Control        
#define AMUX0P0_B3__NOT_CONNECTED 0x00 ///< P0.3 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P0_B3__CONNECTED     0x08 ///< P0.3 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P0_B4__BMASK         0x10 ///< Port 0 Bit 4 Analog Multiplexor Control        
#define AMUX0P0_B4__SHIFT         0x04 ///< Port 0 Bit 4 Analog Multiplexor Control        
#define AMUX0P0_B4__NOT_CONNECTED 0x00 ///< P0.4 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P0_B4__CONNECTED     0x10 ///< P0.4 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P0_B5__BMASK         0x20 ///< Port 0 Bit 5 Analog Multiplexor Control        
#define AMUX0P0_B5__SHIFT         0x05 ///< Port 0 Bit 5 Analog Multiplexor Control        
#define AMUX0P0_B5__NOT_CONNECTED 0x00 ///< P0.5 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P0_B5__CONNECTED     0x20 ///< P0.5 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P0_B6__BMASK         0x40 ///< Port 0 Bit 6 Analog Multiplexor Control        
#define AMUX0P0_B6__SHIFT         0x06 ///< Port 0 Bit 6 Analog Multiplexor Control        
#define AMUX0P0_B6__NOT_CONNECTED 0x00 ///< P0.6 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P0_B6__CONNECTED     0x40 ///< P0.6 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P0_B7__BMASK         0x80 ///< Port 0 Bit 7 Analog Multiplexor Control        
#define AMUX0P0_B7__SHIFT         0x07 ///< Port 0 Bit 7 Analog Multiplexor Control        
#define AMUX0P0_B7__NOT_CONNECTED 0x00 ///< P0.7 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P0_B7__CONNECTED     0x80 ///< P0.7 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
//------------------------------------------------------------------------------
// AMUX0P1 Enums (Port 1 Analog Multiplexer Control @ 0x9B)
//------------------------------------------------------------------------------
#define AMUX0P1_B0__BMASK         0x01 ///< Port 1 Bit 0 Analog Multiplexor Control        
#define AMUX0P1_B0__SHIFT         0x00 ///< Port 1 Bit 0 Analog Multiplexor Control        
#define AMUX0P1_B0__NOT_CONNECTED 0x00 ///< P1.0 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P1_B0__CONNECTED     0x01 ///< P1.0 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P1_B1__BMASK         0x02 ///< Port 1 Bit 1 Analog Multiplexor Control        
#define AMUX0P1_B1__SHIFT         0x01 ///< Port 1 Bit 1 Analog Multiplexor Control        
#define AMUX0P1_B1__NOT_CONNECTED 0x00 ///< P1.1 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P1_B1__CONNECTED     0x02 ///< P1.1 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P1_B2__BMASK         0x04 ///< Port 1 Bit 2 Analog Multiplexor Control        
#define AMUX0P1_B2__SHIFT         0x02 ///< Port 1 Bit 2 Analog Multiplexor Control        
#define AMUX0P1_B2__NOT_CONNECTED 0x00 ///< P1.2 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P1_B2__CONNECTED     0x04 ///< P1.2 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P1_B3__BMASK         0x08 ///< Port 1 Bit 3 Analog Multiplexor Control        
#define AMUX0P1_B3__SHIFT         0x03 ///< Port 1 Bit 3 Analog Multiplexor Control        
#define AMUX0P1_B3__NOT_CONNECTED 0x00 ///< P1.3 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P1_B3__CONNECTED     0x08 ///< P1.3 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P1_B4__BMASK         0x10 ///< Port 1 Bit 4 Analog Multiplexor Control        
#define AMUX0P1_B4__SHIFT         0x04 ///< Port 1 Bit 4 Analog Multiplexor Control        
#define AMUX0P1_B4__NOT_CONNECTED 0x00 ///< P1.4 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P1_B4__CONNECTED     0x10 ///< P1.4 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P1_B5__BMASK         0x20 ///< Port 1 Bit 5 Analog Multiplexor Control        
#define AMUX0P1_B5__SHIFT         0x05 ///< Port 1 Bit 5 Analog Multiplexor Control        
#define AMUX0P1_B5__NOT_CONNECTED 0x00 ///< P1.5 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P1_B5__CONNECTED     0x20 ///< P1.5 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P1_B6__BMASK         0x40 ///< Port 1 Bit 6 Analog Multiplexor Control        
#define AMUX0P1_B6__SHIFT         0x06 ///< Port 1 Bit 6 Analog Multiplexor Control        
#define AMUX0P1_B6__NOT_CONNECTED 0x00 ///< P1.6 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P1_B6__CONNECTED     0x40 ///< P1.6 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P1_B7__BMASK         0x80 ///< Port 1 Bit 7 Analog Multiplexor Control        
#define AMUX0P1_B7__SHIFT         0x07 ///< Port 1 Bit 7 Analog Multiplexor Control        
#define AMUX0P1_B7__NOT_CONNECTED 0x00 ///< P1.7 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P1_B7__CONNECTED     0x80 ///< P1.7 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
//------------------------------------------------------------------------------
// AMUX0P2 Enums (Port 2 Analog Multiplexer Control @ 0x9C)
//------------------------------------------------------------------------------
#define AMUX0P2_B0__BMASK         0x01 ///< Port 2 Bit 0 Analog Multiplexor Control        
#define AMUX0P2_B0__SHIFT         0x00 ///< Port 2 Bit 0 Analog Multiplexor Control        
#define AMUX0P2_B0__NOT_CONNECTED 0x00 ///< P2.0 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P2_B0__CONNECTED     0x01 ///< P2.0 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P2_B1__BMASK         0x02 ///< Port 2 Bit 1 Analog Multiplexor Control        
#define AMUX0P2_B1__SHIFT         0x01 ///< Port 2 Bit 1 Analog Multiplexor Control        
#define AMUX0P2_B1__NOT_CONNECTED 0x00 ///< P2.1 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P2_B1__CONNECTED     0x02 ///< P2.1 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P2_B2__BMASK         0x04 ///< Port 2 Bit 2 Analog Multiplexor Control        
#define AMUX0P2_B2__SHIFT         0x02 ///< Port 2 Bit 2 Analog Multiplexor Control        
#define AMUX0P2_B2__NOT_CONNECTED 0x00 ///< P2.2 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P2_B2__CONNECTED     0x04 ///< P2.2 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P2_B3__BMASK         0x08 ///< Port 2 Bit 3 Analog Multiplexor Control        
#define AMUX0P2_B3__SHIFT         0x03 ///< Port 2 Bit 3 Analog Multiplexor Control        
#define AMUX0P2_B3__NOT_CONNECTED 0x00 ///< P2.3 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P2_B3__CONNECTED     0x08 ///< P2.3 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P2_B4__BMASK         0x10 ///< Port 2 Bit 4 Analog Multiplexor Control        
#define AMUX0P2_B4__SHIFT         0x04 ///< Port 2 Bit 4 Analog Multiplexor Control        
#define AMUX0P2_B4__NOT_CONNECTED 0x00 ///< P2.4 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P2_B4__CONNECTED     0x10 ///< P2.4 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P2_B5__BMASK         0x20 ///< Port 2 Bit 5 Analog Multiplexor Control        
#define AMUX0P2_B5__SHIFT         0x05 ///< Port 2 Bit 5 Analog Multiplexor Control        
#define AMUX0P2_B5__NOT_CONNECTED 0x00 ///< P2.5 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P2_B5__CONNECTED     0x20 ///< P2.5 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P2_B6__BMASK         0x40 ///< Port 2 Bit 6 Analog Multiplexor Control        
#define AMUX0P2_B6__SHIFT         0x06 ///< Port 2 Bit 6 Analog Multiplexor Control        
#define AMUX0P2_B6__NOT_CONNECTED 0x00 ///< P2.6 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P2_B6__CONNECTED     0x40 ///< P2.6 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P2_B7__BMASK         0x80 ///< Port 2 Bit 7 Analog Multiplexor Control        
#define AMUX0P2_B7__SHIFT         0x07 ///< Port 2 Bit 7 Analog Multiplexor Control        
#define AMUX0P2_B7__NOT_CONNECTED 0x00 ///< P2.7 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P2_B7__CONNECTED     0x80 ///< P2.7 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
//------------------------------------------------------------------------------
// AMUX0P3 Enums (Port 3 Analog Multiplexer Control @ 0xA4)
//------------------------------------------------------------------------------
#define AMUX0P3_B0__BMASK         0x01 ///< Port 3 Bit 0 Analog Multiplexor Control        
#define AMUX0P3_B0__SHIFT         0x00 ///< Port 3 Bit 0 Analog Multiplexor Control        
#define AMUX0P3_B0__NOT_CONNECTED 0x00 ///< P3.0 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P3_B0__CONNECTED     0x01 ///< P3.0 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P3_B1__BMASK         0x02 ///< Port 3 Bit 1 Analog Multiplexor Control        
#define AMUX0P3_B1__SHIFT         0x01 ///< Port 3 Bit 1 Analog Multiplexor Control        
#define AMUX0P3_B1__NOT_CONNECTED 0x00 ///< P3.1 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P3_B1__CONNECTED     0x02 ///< P3.1 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P3_B2__BMASK         0x04 ///< Port 3 Bit 2 Analog Multiplexor Control        
#define AMUX0P3_B2__SHIFT         0x02 ///< Port 3 Bit 2 Analog Multiplexor Control        
#define AMUX0P3_B2__NOT_CONNECTED 0x00 ///< P3.2 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P3_B2__CONNECTED     0x04 ///< P3.2 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P3_B3__BMASK         0x08 ///< Port 3 Bit 3 Analog Multiplexor Control        
#define AMUX0P3_B3__SHIFT         0x03 ///< Port 3 Bit 3 Analog Multiplexor Control        
#define AMUX0P3_B3__NOT_CONNECTED 0x00 ///< P3.3 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P3_B3__CONNECTED     0x08 ///< P3.3 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P3_B4__BMASK         0x10 ///< Port 3 Bit 4 Analog Multiplexor Control        
#define AMUX0P3_B4__SHIFT         0x04 ///< Port 3 Bit 4 Analog Multiplexor Control        
#define AMUX0P3_B4__NOT_CONNECTED 0x00 ///< P3.4 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P3_B4__CONNECTED     0x10 ///< P3.4 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P3_B5__BMASK         0x20 ///< Port 3 Bit 5 Analog Multiplexor Control        
#define AMUX0P3_B5__SHIFT         0x05 ///< Port 3 Bit 5 Analog Multiplexor Control        
#define AMUX0P3_B5__NOT_CONNECTED 0x00 ///< P3.5 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P3_B5__CONNECTED     0x20 ///< P3.5 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P3_B6__BMASK         0x40 ///< Port 3 Bit 6 Analog Multiplexor Control        
#define AMUX0P3_B6__SHIFT         0x06 ///< Port 3 Bit 6 Analog Multiplexor Control        
#define AMUX0P3_B6__NOT_CONNECTED 0x00 ///< P3.6 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P3_B6__CONNECTED     0x40 ///< P3.6 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P3_B7__BMASK         0x80 ///< Port 3 Bit 7 Analog Multiplexor Control        
#define AMUX0P3_B7__SHIFT         0x07 ///< Port 3 Bit 7 Analog Multiplexor Control        
#define AMUX0P3_B7__NOT_CONNECTED 0x00 ///< P3.7 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P3_B7__CONNECTED     0x80 ///< P3.7 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
//------------------------------------------------------------------------------
// AMUX0P4 Enums (Port 4 Analog Multiplexer Control @ 0xA5)
//------------------------------------------------------------------------------
#define AMUX0P4_B0__BMASK         0x01 ///< Port 4 Bit 0 Analog Multiplexor Control        
#define AMUX0P4_B0__SHIFT         0x00 ///< Port 4 Bit 0 Analog Multiplexor Control        
#define AMUX0P4_B0__NOT_CONNECTED 0x00 ///< P4.0 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P4_B0__CONNECTED     0x01 ///< P4.0 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P4_B1__BMASK         0x02 ///< Port 4 Bit 1 Analog Multiplexor Control        
#define AMUX0P4_B1__SHIFT         0x01 ///< Port 4 Bit 1 Analog Multiplexor Control        
#define AMUX0P4_B1__NOT_CONNECTED 0x00 ///< P4.1 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P4_B1__CONNECTED     0x02 ///< P4.1 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P4_B2__BMASK         0x04 ///< Port 4 Bit 2 Analog Multiplexor Control        
#define AMUX0P4_B2__SHIFT         0x02 ///< Port 4 Bit 2 Analog Multiplexor Control        
#define AMUX0P4_B2__NOT_CONNECTED 0x00 ///< P4.2 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P4_B2__CONNECTED     0x04 ///< P4.2 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P4_B3__BMASK         0x08 ///< Port 4 Bit 3 Analog Multiplexor Control        
#define AMUX0P4_B3__SHIFT         0x03 ///< Port 4 Bit 3 Analog Multiplexor Control        
#define AMUX0P4_B3__NOT_CONNECTED 0x00 ///< P4.3 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P4_B3__CONNECTED     0x08 ///< P4.3 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P4_B4__BMASK         0x10 ///< Port 4 Bit 4 Analog Multiplexor Control        
#define AMUX0P4_B4__SHIFT         0x04 ///< Port 4 Bit 4 Analog Multiplexor Control        
#define AMUX0P4_B4__NOT_CONNECTED 0x00 ///< P4.4 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P4_B4__CONNECTED     0x10 ///< P4.4 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P4_B5__BMASK         0x20 ///< Port 4 Bit 5 Analog Multiplexor Control        
#define AMUX0P4_B5__SHIFT         0x05 ///< Port 4 Bit 5 Analog Multiplexor Control        
#define AMUX0P4_B5__NOT_CONNECTED 0x00 ///< P4.5 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P4_B5__CONNECTED     0x20 ///< P4.5 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P4_B6__BMASK         0x40 ///< Port 4 Bit 6 Analog Multiplexor Control        
#define AMUX0P4_B6__SHIFT         0x06 ///< Port 4 Bit 6 Analog Multiplexor Control        
#define AMUX0P4_B6__NOT_CONNECTED 0x00 ///< P4.6 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P4_B6__CONNECTED     0x40 ///< P4.6 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P4_B7__BMASK         0x80 ///< Port 4 Bit 7 Analog Multiplexor Control        
#define AMUX0P4_B7__SHIFT         0x07 ///< Port 4 Bit 7 Analog Multiplexor Control        
#define AMUX0P4_B7__NOT_CONNECTED 0x00 ///< P4.7 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P4_B7__CONNECTED     0x80 ///< P4.7 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
//------------------------------------------------------------------------------
// AMUX0P5 Enums (Port 5 Analog Multiplexer Control @ 0xA6)
//------------------------------------------------------------------------------
#define AMUX0P5_B0__BMASK         0x01 ///< Port 5 Bit 0 Analog Multiplexor Control        
#define AMUX0P5_B0__SHIFT         0x00 ///< Port 5 Bit 0 Analog Multiplexor Control        
#define AMUX0P5_B0__NOT_CONNECTED 0x00 ///< P5.0 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P5_B0__CONNECTED     0x01 ///< P5.0 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P5_B1__BMASK         0x02 ///< Port 5 Bit 1 Analog Multiplexor Control        
#define AMUX0P5_B1__SHIFT         0x01 ///< Port 5 Bit 1 Analog Multiplexor Control        
#define AMUX0P5_B1__NOT_CONNECTED 0x00 ///< P5.1 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P5_B1__CONNECTED     0x02 ///< P5.1 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
#define AMUX0P5_B2__BMASK         0x04 ///< Port 5 Bit 2 Analog Multiplexor Control        
#define AMUX0P5_B2__SHIFT         0x02 ///< Port 5 Bit 2 Analog Multiplexor Control        
#define AMUX0P5_B2__NOT_CONNECTED 0x00 ///< P5.2 pin is not connected by the Analog        
                                       ///< Multiplexer for CS0 or ADC0 measurements.      
#define AMUX0P5_B2__CONNECTED     0x04 ///< P5.2 pin is connected by the Analog Multiplexer
                                       ///< for CS0 or ADC0 measurements.                  
                                                                                           
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
// SFRLAST Enums (SFR Page Last @ 0xB3)
//------------------------------------------------------------------------------
#define SFRLAST_SFRLAST__FMASK 0xFF ///< SFR Page Last
#define SFRLAST_SFRLAST__SHIFT 0x00 ///< SFR Page Last
                                                      
//------------------------------------------------------------------------------
// SFRNEXT Enums (SFR Page Next @ 0xF3)
//------------------------------------------------------------------------------
#define SFRNEXT_SFRNEXT__FMASK 0xFF ///< SFR Page Next
#define SFRNEXT_SFRNEXT__SHIFT 0x00 ///< SFR Page Next
                                                      
//------------------------------------------------------------------------------
// SFRPAGE Enums (SFR Page @ 0xA7)
//------------------------------------------------------------------------------
#define SFRPAGE_SFRPAGE__FMASK 0xFF ///< SFR Page
#define SFRPAGE_SFRPAGE__SHIFT 0x00 ///< SFR Page
                                                 
//------------------------------------------------------------------------------
// SFRPGCN Enums (SFR Page Control @ 0xA6)
//------------------------------------------------------------------------------
#define SFRPGCN_SFRPGEN__BMASK              0x01 ///< SFR Automatic Page Control Enable                 
#define SFRPGCN_SFRPGEN__SHIFT              0x00 ///< SFR Automatic Page Control Enable                 
#define SFRPGCN_SFRPGEN__AUTO_PAGE_DISABLED 0x00 ///< Disable SFR automatic paging. The C8051 core will 
                                                 ///< not automatically change to the appropriate SFR   
                                                 ///< page (i.e., the SFR page that contains the SFRs   
                                                 ///< for the peripheral/function that was the source of
                                                 ///< the interrupt).                                   
#define SFRPGCN_SFRPGEN__AUTO_PAGE_ENABLED  0x01 ///< Enable SFR automatic paging.  Upon interrupt, the 
                                                 ///< C8051 will switch the SFR page to the page that   
                                                 ///< contains the SFRs for the peripheral or function  
                                                 ///< that is the source of the interrupt.              
                                                                                                        
//------------------------------------------------------------------------------
// SP Enums (Stack Pointer @ 0x81)
//------------------------------------------------------------------------------
#define SP_SP__FMASK 0xFF ///< Stack Pointer
#define SP_SP__SHIFT 0x00 ///< Stack Pointer
                                            
//------------------------------------------------------------------------------
// CLKMODE Enums (Clock Mode @ 0xF7)
//------------------------------------------------------------------------------
#define CLKMODE_FCAM__BMASK             0x01 ///< Force Clock Tree Enable                          
#define CLKMODE_FCAM__SHIFT             0x00 ///< Force Clock Tree Enable                          
#define CLKMODE_FCAM__CLOCK_GATE_ALWAYS 0x00 ///< Clock gating occurs in active and idle mode.     
#define CLKMODE_FCAM__CLOCK_GATE_IDLE   0x01 ///< Clock gating occurs only in idle mode.           
                                                                                                   
#define CLKMODE_ECSR__BMASK             0x02 ///< Clock Request Enable                             
#define CLKMODE_ECSR__SHIFT             0x01 ///< Clock Request Enable                             
#define CLKMODE_ECSR__DISABLED          0x00 ///< Disable clock requests.                          
#define CLKMODE_ECSR__ENABLED           0x02 ///< Clocks will only be requested when an incoming   
                                             ///< request is active or a peripheral clock is       
                                             ///< enabled.                                         
                                                                                                   
#define CLKMODE_LPME__BMASK             0x04 ///< Low Power Mode Enable                            
#define CLKMODE_LPME__SHIFT             0x02 ///< Low Power Mode Enable                            
#define CLKMODE_LPME__DISABLED          0x00 ///< Disable low power active and idle modes.         
#define CLKMODE_LPME__ENABLED           0x04 ///< Enable low power active and low power idle modes.
                                                                                                   
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
// PCLKEN Enums (Low Power Peripheral Clock Enable @ 0xF6)
//------------------------------------------------------------------------------
#define PCLKEN_PCLKEN0__BMASK    0x01 ///< Low Power Idle Mode Peripheral Set 0 Enable       
#define PCLKEN_PCLKEN0__SHIFT    0x00 ///< Low Power Idle Mode Peripheral Set 0 Enable       
#define PCLKEN_PCLKEN0__DISABLED 0x00 ///< Disable clocks of UART0, Timer 3, SPI0, and I2C0  
                                      ///< in low power idle mode.                           
#define PCLKEN_PCLKEN0__ENABLED  0x01 ///< Enable clocks of UART0, Timer 3, SPI0, and I2C0 in
                                      ///< low power idle mode.                              
                                                                                             
#define PCLKEN_PCLKEN1__BMASK    0x02 ///< Low Power Idle Mode Peripheral Set 1 Enable       
#define PCLKEN_PCLKEN1__SHIFT    0x01 ///< Low Power Idle Mode Peripheral Set 1 Enable       
#define PCLKEN_PCLKEN1__DISABLED 0x00 ///< Disable clocks of MAC0 in low power idle mode.    
#define PCLKEN_PCLKEN1__ENABLED  0x02 ///< Enable clocks of MAC0 in low power idle mode.     
                                                                                             
#define PCLKEN_PCLKEN2__BMASK    0x04 ///< Low Power Idle Mode Peripheral Set 2 Enable       
#define PCLKEN_PCLKEN2__SHIFT    0x02 ///< Low Power Idle Mode Peripheral Set 2 Enable       
#define PCLKEN_PCLKEN2__DISABLED 0x00 ///< Disable clocks of PCA0, CS0, and ADC0 in low power
                                      ///< idle mode.                                        
#define PCLKEN_PCLKEN2__ENABLED  0x04 ///< Enable clocks of PCA0, CS0, and ADC0 in low power 
                                      ///< idle mode.                                        
                                                                                             
#define PCLKEN_PCLKEN3__BMASK    0x08 ///< Low Power Idle Mode Peripheral Set 3 Enable       
#define PCLKEN_PCLKEN3__SHIFT    0x03 ///< Low Power Idle Mode Peripheral Set 3 Enable       
#define PCLKEN_PCLKEN3__DISABLED 0x00 ///< Disable clocks of Timer 0, 1, 2, CRC0, C2, RTC0,  
                                      ///< and Port Match in low power idle mode.            
#define PCLKEN_PCLKEN3__ENABLED  0x08 ///< Enable clocks of Timer 0, 1, 2, CRC0, C2, RTC0,   
                                      ///< and Port Match in low power idle mode.            
                                                                                             
#define PCLKEN_PCLKEN4__BMASK    0x10 ///< Low Power Active Mode Peripheral Set 0 Enable     
#define PCLKEN_PCLKEN4__SHIFT    0x04 ///< Low Power Active Mode Peripheral Set 0 Enable     
#define PCLKEN_PCLKEN4__DISABLED 0x00 ///< Disable clocks of UART0, Timer 3, SPI0, and I2C0  
                                      ///< in low power active mode.                         
#define PCLKEN_PCLKEN4__ENABLED  0x10 ///< Enable clocks of UART0, Timer 3, SPI0, and I2C0 in
                                      ///< low power active mode.                            
                                                                                             
#define PCLKEN_PCLKEN5__BMASK    0x20 ///< Low Power Active Mode Peripheral Set 1 Enable     
#define PCLKEN_PCLKEN5__SHIFT    0x05 ///< Low Power Active Mode Peripheral Set 1 Enable     
#define PCLKEN_PCLKEN5__DISABLED 0x00 ///< Disable clocks of MAC0 in low power active mode.  
#define PCLKEN_PCLKEN5__ENABLED  0x20 ///< Enable clocks of MAC0 in low power active mode.   
                                                                                             
#define PCLKEN_PCLKEN6__BMASK    0x40 ///< Low Power Active Mode Peripheral Set 2 Enable     
#define PCLKEN_PCLKEN6__SHIFT    0x06 ///< Low Power Active Mode Peripheral Set 2 Enable     
#define PCLKEN_PCLKEN6__DISABLED 0x00 ///< Disable clocks of PCA0, CS0, and ADC0 in low power
                                      ///< active mode.                                      
#define PCLKEN_PCLKEN6__ENABLED  0x40 ///< Enable clocks of PCA0, CS0, and ADC0 in low power 
                                      ///< active mode.                                      
                                                                                             
#define PCLKEN_PCLKEN7__BMASK    0x80 ///< Low Power Active Mode Peripheral Set 3 Enable     
#define PCLKEN_PCLKEN7__SHIFT    0x07 ///< Low Power Active Mode Peripheral Set 3 Enable     
#define PCLKEN_PCLKEN7__DISABLED 0x00 ///< Disable clocks of Timer 0, 1, 2, CRC0, C2, RTC0,  
                                      ///< and Port Match in low power active mode.          
#define PCLKEN_PCLKEN7__ENABLED  0x80 ///< Enable clocks of Timer 0, 1, 2, CRC0, C2, RTC0,   
                                      ///< and Port Match in low power active mode.          
                                                                                             
//------------------------------------------------------------------------------
// CRC0AUTO Enums (CRC0 Automatic Control @ 0x9E)
//------------------------------------------------------------------------------
#define CRC0AUTO_CRCST__FMASK     0x7F ///< Automatic CRC Calculation Starting Block  
#define CRC0AUTO_CRCST__SHIFT     0x00 ///< Automatic CRC Calculation Starting Block  
                                                                                      
#define CRC0AUTO_AUTOEN__BMASK    0x80 ///< Automatic CRC Calculation Enable          
#define CRC0AUTO_AUTOEN__SHIFT    0x07 ///< Automatic CRC Calculation Enable          
#define CRC0AUTO_AUTOEN__DISABLED 0x00 ///< Disable automatic CRC operations on flash.
#define CRC0AUTO_AUTOEN__ENABLED  0x80 ///< Enable automatic CRC operations on flash. 
                                                                                      
//------------------------------------------------------------------------------
// CRC0CN Enums (CRC0 Control @ 0x84)
//------------------------------------------------------------------------------
#define CRC0CN_CRCPNT__BMASK        0x01 ///< CRC Result Pointer                               
#define CRC0CN_CRCPNT__SHIFT        0x00 ///< CRC Result Pointer                               
#define CRC0CN_CRCPNT__ACCESS_LOWER 0x00 ///< CRC0DAT accesses bits 7-0 of the 16-bit CRC      
                                         ///< result.                                          
#define CRC0CN_CRCPNT__ACCESS_UPPER 0x01 ///< CRC0DAT accesses bits 15-8 of the 16-bit CRC     
                                         ///< result.                                          
                                                                                               
#define CRC0CN_CRCVAL__BMASK        0x04 ///< CRC Initialization Value                         
#define CRC0CN_CRCVAL__SHIFT        0x02 ///< CRC Initialization Value                         
#define CRC0CN_CRCVAL__SET_ZEROES   0x00 ///< CRC result is set to 0x0000 on write of 1 to     
                                         ///< CRCINIT.                                         
#define CRC0CN_CRCVAL__SET_ONES     0x04 ///< CRC result is set to 0xFFFF on write of 1 to     
                                         ///< CRCINIT.                                         
                                                                                               
#define CRC0CN_CRCINIT__BMASK       0x08 ///< CRC Initialization Enable                        
#define CRC0CN_CRCINIT__SHIFT       0x03 ///< CRC Initialization Enable                        
#define CRC0CN_CRCINIT__DO_NOT_INIT 0x00 ///< Do not initialize the CRC result.                
#define CRC0CN_CRCINIT__INIT        0x08 ///< Initialize the CRC result to ones or zeroes vased
                                         ///< on the value of CRCVAL.                          
                                                                                               
//------------------------------------------------------------------------------
// CRC0CNT Enums (CRC0 Automatic Flash Sector Count @ 0x9D)
//------------------------------------------------------------------------------
#define CRC0CNT_CRCCNT__FMASK  0x7F ///< Automatic CRC Calculation Block Count
#define CRC0CNT_CRCCNT__SHIFT  0x00 ///< Automatic CRC Calculation Block Count
                                                                              
#define CRC0CNT_CRCDN__BMASK   0x80 ///< Automatic CRC Calculation Complete   
#define CRC0CNT_CRCDN__SHIFT   0x07 ///< Automatic CRC Calculation Complete   
#define CRC0CNT_CRCDN__NOT_SET 0x00 ///< A CRC calculation is in progress.    
#define CRC0CNT_CRCDN__SET     0x80 ///< A CRC calculation is not in progress.
                                                                              
//------------------------------------------------------------------------------
// CRC0DAT Enums (CRC0 Data Output @ 0x86)
//------------------------------------------------------------------------------
#define CRC0DAT_CRC0DAT__FMASK 0xFF ///< CRC Data Output
#define CRC0DAT_CRC0DAT__SHIFT 0x00 ///< CRC Data Output
                                                        
//------------------------------------------------------------------------------
// CRC0FLIP Enums (CRC0 Bit Flip @ 0x9F)
//------------------------------------------------------------------------------
#define CRC0FLIP_CRC0FLIP__FMASK 0xFF ///< CRC0 Bit Flip
#define CRC0FLIP_CRC0FLIP__SHIFT 0x00 ///< CRC0 Bit Flip
                                                        
//------------------------------------------------------------------------------
// CRC0IN Enums (CRC0 Data Input @ 0x85)
//------------------------------------------------------------------------------
#define CRC0IN_CRC0IN__FMASK 0xFF ///< CRC Data Input
#define CRC0IN_CRC0IN__SHIFT 0x00 ///< CRC Data Input
                                                     
//------------------------------------------------------------------------------
// CS0CF Enums (Capacitive Sense 0 Configuration @ 0xAA)
//------------------------------------------------------------------------------
#define CS0CF_CS0ACU__FMASK               0x07 ///< CS0 Accumulator Mode Select                       
#define CS0CF_CS0ACU__SHIFT               0x00 ///< CS0 Accumulator Mode Select                       
#define CS0CF_CS0ACU__ACC_1               0x00 ///< Accumulate 1 sample.                              
#define CS0CF_CS0ACU__ACC_4               0x01 ///< Accumulate 4 samples.                             
#define CS0CF_CS0ACU__ACC_8               0x02 ///< Accumulate 8 samples.                             
#define CS0CF_CS0ACU__ACC_16              0x03 ///< Accumulate 16 samples                             
#define CS0CF_CS0ACU__ACC_32              0x04 ///< Accumulate 32 samples.                            
#define CS0CF_CS0ACU__ACC_64              0x05 ///< Accumulate 64 samples.                            
                                                                                                      
#define CS0CF_CS0MCEN__BMASK              0x08 ///< CS0 Multiple Channel Enable                       
#define CS0CF_CS0MCEN__SHIFT              0x03 ///< CS0 Multiple Channel Enable                       
#define CS0CF_CS0MCEN__MULT_CHAN_DISABLED 0x00 ///< Multiple channel feature is disabled.             
#define CS0CF_CS0MCEN__MULT_CHAN_ENABLED  0x08 ///< Channels selected by the AMUX0 registers are      
                                               ///< internally shorted together and the combined node 
                                               ///< is selected as the CS0 input. This mode can be    
                                               ///< used to detect a capacitance change on multiple   
                                               ///< channels using a single conversion.               
                                                                                                      
#define CS0CF_CS0CM__FMASK                0x70 ///< CS0 Start of Conversion Mode Select               
#define CS0CF_CS0CM__SHIFT                0x04 ///< CS0 Start of Conversion Mode Select               
#define CS0CF_CS0CM__CS0BUSY              0x00 ///< Conversion initiated on every write of 1 to       
                                               ///< CS0BUSY.                                          
#define CS0CF_CS0CM__TIMER0               0x10 ///< Conversion initiated on overflow of Timer 0.      
#define CS0CF_CS0CM__TIMER2               0x20 ///< Conversion initiated on overflow of Timer 2.      
#define CS0CF_CS0CM__TIMER1               0x30 ///< Conversion initiated on overflow of Timer 1.      
#define CS0CF_CS0CM__TIMER3               0x40 ///< Conversion initiated on overflow of Timer 3.      
#define CS0CF_CS0CM__SINGLE_SCAN          0x50 ///< When CS0SMEN is set to 1, the converter completes 
                                               ///< a Single Scan of the channels selected by the     
                                               ///< AMUX0 registers. This setting is invalid when     
                                               ///< CS0SMEN is cleared to 0.                          
#define CS0CF_CS0CM__SINGLE_CONTINUOUS    0x60 ///< Conversion initiated continuously on the channel  
                                               ///< selected by CS0MX after writing 1 to CS0BUSY.     
#define CS0CF_CS0CM__AUTO_SCAN            0x70 ///< When CS0SMEN is set to 1, the converter enters    
                                               ///< Auto Scan Mode and continuously scans the channels
                                               ///< selected by the AMUX0 registers. When CS0SMEN is  
                                               ///< cleared to 0, the converter scans continuously on 
                                               ///< channels from CS0SS to CS0SE after firmware writes
                                               ///< 1 to CS0BUSY.                                     
                                                                                                      
#define CS0CF_CS0SMEN__BMASK              0x80 ///< CS0 Channel Scan Masking Enable                   
#define CS0CF_CS0SMEN__SHIFT              0x07 ///< CS0 Channel Scan Masking Enable                   
#define CS0CF_CS0SMEN__SCAN_MASK_DISABLED 0x00 ///< The AMUX0 register contents are ignored.          
#define CS0CF_CS0SMEN__SCAN_MASK_ENABLED  0x80 ///< The AMUX0 registers determine which channels will 
                                               ///< be included in the scan.                          
                                                                                                      
//------------------------------------------------------------------------------
// CS0CN Enums (Capacitive Sense 0 Control @ 0xB0)
//------------------------------------------------------------------------------
#define CS0CN_CSCMPF__BMASK     0x01 ///< CS0 Digital Comparator Interrupt Flag             
#define CS0CN_CSCMPF__SHIFT     0x00 ///< CS0 Digital Comparator Interrupt Flag             
#define CS0CN_CSCMPF__NOT_SET   0x00 ///< CS0 result is smaller than the value set by CS0THH
                                     ///< and CS0THL since the last time CS0CMPF was        
                                     ///< cleared.                                          
#define CS0CN_CSCMPF__SET       0x01 ///< CS0 result is greater than the value set by CS0THH
                                     ///< and CS0THL since the last time CS0CMPF was        
                                     ///< cleared.                                          
                                                                                            
#define CS0CN_CSPME__BMASK      0x02 ///< CS0 Pin Monitor Event                             
#define CS0CN_CSPME__SHIFT      0x01 ///< CS0 Pin Monitor Event                             
#define CS0CN_CSPME__NO_RETRIES 0x00 ///< Converter re-tries have not occurred.             
#define CS0CN_CSPME__RETRIES    0x02 ///< Converter re-tries occurred.                      
                                                                                            
#define CS0CN_CSCMPEN__BMASK    0x08 ///< CS0 Digital Comparator Enable                     
#define CS0CN_CSCMPEN__SHIFT    0x03 ///< CS0 Digital Comparator Enable                     
#define CS0CN_CSCMPEN__DISABLED 0x00 ///< Disable CS0 digital comparator.                   
#define CS0CN_CSCMPEN__ENABLED  0x08 ///< Enable CS0 digital comparator.                    
                                                                                            
#define CS0CN_CSBUSY__BMASK     0x10 ///< CS0 Busy                                          
#define CS0CN_CSBUSY__SHIFT     0x04 ///< CS0 Busy                                          
#define CS0CN_CSBUSY__NOT_SET   0x00 ///< A CS0 conversion is not currently in progress.    
#define CS0CN_CSBUSY__SET       0x10 ///< CS0 conversion is in progress or start a CS0      
                                     ///< conversion.                                       
                                                                                            
#define CS0CN_CSINT__BMASK      0x20 ///< CS0 Interrupt Flag                                
#define CS0CN_CSINT__SHIFT      0x05 ///< CS0 Interrupt Flag                                
#define CS0CN_CSINT__NOT_SET    0x00 ///< CS0 has not completed a data conversion since the 
                                     ///< last time CS0INT was cleared.                     
#define CS0CN_CSINT__SET        0x20 ///< CS0 has completed a data conversion.              
                                                                                            
#define CS0CN_CSEOS__BMASK      0x40 ///< CS0 End of Scan Interrupt Flag                    
#define CS0CN_CSEOS__SHIFT      0x06 ///< CS0 End of Scan Interrupt Flag                    
#define CS0CN_CSEOS__NOT_SET    0x00 ///< CS0 has not completed a scan since the last time  
                                     ///< CS0EOS was cleared.                               
#define CS0CN_CSEOS__SET        0x40 ///< CS0 has completed a scan.                         
                                                                                            
#define CS0CN_CSEN__BMASK       0x80 ///< CS0 Enable                                        
#define CS0CN_CSEN__SHIFT       0x07 ///< CS0 Enable                                        
#define CS0CN_CSEN__DISABLED    0x00 ///< CS0 disabled and in low-power mode.               
#define CS0CN_CSEN__ENABLED     0x80 ///< CS0 enabled and ready to convert.                 
                                                                                            
//------------------------------------------------------------------------------
// CS0DH Enums (Capacitive Sense 0 Data High Byte @ 0xEE)
//------------------------------------------------------------------------------
#define CS0DH_CS0DH__FMASK 0xFF ///< CS0 Data High Byte
#define CS0DH_CS0DH__SHIFT 0x00 ///< CS0 Data High Byte
                                                       
//------------------------------------------------------------------------------
// CS0DL Enums (Capacitive Sense 0 Data Low Byte @ 0xED)
//------------------------------------------------------------------------------
#define CS0DL_CS0DL__FMASK 0xFF ///< CS0 Data Low Byte
#define CS0DL_CS0DL__SHIFT 0x00 ///< CS0 Data Low Byte
                                                      
//------------------------------------------------------------------------------
// CS0MD1 Enums (Capacitive Sense 0 Mode 1 @ 0xBD)
//------------------------------------------------------------------------------
#define CS0MD1_CS0CG__FMASK                 0x07 ///< CS0 Capacitance Gain Select                       
#define CS0MD1_CS0CG__SHIFT                 0x00 ///< CS0 Capacitance Gain Select                       
#define CS0MD1_CS0CG__GAIN_1                0x00 ///< Gain = 1x                                         
#define CS0MD1_CS0CG__GAIN_2                0x01 ///< Gain = 2x                                         
#define CS0MD1_CS0CG__GAIN_3                0x02 ///< Gain = 3x                                         
#define CS0MD1_CS0CG__GAIN_4                0x03 ///< Gain = 4x                                         
#define CS0MD1_CS0CG__GAIN_5                0x04 ///< Gain = 5x                                         
#define CS0MD1_CS0CG__GAIN_6                0x05 ///< Gain = 6x                                         
#define CS0MD1_CS0CG__GAIN_7                0x06 ///< Gain = 7x                                         
#define CS0MD1_CS0CG__GAIN_8                0x07 ///< Gain = 8x                                         
                                                                                                        
#define CS0MD1_CS0WOI__BMASK                0x08 ///< CS0 Wake on Interrupt Configuration               
#define CS0MD1_CS0WOI__SHIFT                0x03 ///< CS0 Wake on Interrupt Configuration               
#define CS0MD1_CS0WOI__COMPARATOR_ONLY      0x00 ///< Wake-up event generated on digital comparator     
                                                 ///< interrupt only.                                   
#define CS0MD1_CS0WOI__EOS_OR_COMPARATOR    0x08 ///< Wake-up event generated on end of scan or digital 
                                                 ///< comparator interrupt.                             
                                                                                                        
#define CS0MD1_CS0DR__FMASK                 0x30 ///< CS0 Double Reset Select                           
#define CS0MD1_CS0DR__SHIFT                 0x04 ///< CS0 Double Reset Select                           
#define CS0MD1_CS0DR__DOUBLE_RESET_DISABLED 0x00 ///< No additional time is used for secondary reset.   
#define CS0MD1_CS0DR__ADD_0P75              0x10 ///< An additional 0.75 us is used for secondary reset.
#define CS0MD1_CS0DR__ADD_1P5               0x20 ///< An additional 1.5 us is used for secondary reset. 
#define CS0MD1_CS0DR__ADD_2P25              0x30 ///< An additional 2.25 us is used for secondary reset.
                                                                                                        
#define CS0MD1_CS0POL__BMASK                0x40 ///< CS0 Digital Comparator Polarity Select            
#define CS0MD1_CS0POL__SHIFT                0x06 ///< CS0 Digital Comparator Polarity Select            
#define CS0MD1_CS0POL__GREATER_THAN         0x00 ///< The digital comparator generates an interrupt if  
                                                 ///< the conversion is greater than the threshold.     
#define CS0MD1_CS0POL__LESS_THAN_OR_EQUAL   0x40 ///< The digital comparator generates an interrupt if  
                                                 ///< the conversion is less than or equal to the       
                                                 ///< threshold.                                        
                                                                                                        
//------------------------------------------------------------------------------
// CS0MD2 Enums (Capacitive Sense 0 Mode 2 @ 0xBE)
//------------------------------------------------------------------------------
#define CS0MD2_CS0IA__FMASK           0x07 ///< CS0 Output Current Adjustment                     
#define CS0MD2_CS0IA__SHIFT           0x00 ///< CS0 Output Current Adjustment                     
#define CS0MD2_CS0IA__CURRENT_MODE0   0x00 ///< Full current.                                     
#define CS0MD2_CS0IA__CURRENT_MODE1   0x01 ///< 1/8 current.                                      
#define CS0MD2_CS0IA__CURRENT_MODE2   0x02 ///< 1/4 current.                                      
#define CS0MD2_CS0IA__CURRENT_MODE3   0x03 ///< 3/8 current.                                      
#define CS0MD2_CS0IA__CURRENT_MODE4   0x04 ///< 1/2 current.                                      
#define CS0MD2_CS0IA__CURRENT_MODE5   0x05 ///< 5/8 current.                                      
#define CS0MD2_CS0IA__CURRENT_MODE6   0x06 ///< 3/4 current.                                      
#define CS0MD2_CS0IA__CURRENT_MODE7   0x07 ///< 7/8 current.                                      
                                                                                                  
#define CS0MD2_CS0DT__FMASK           0x38 ///< CS0 Discharge Time                                
#define CS0MD2_CS0DT__SHIFT           0x03 ///< CS0 Discharge Time                                
#define CS0MD2_CS0DT__DISCHARGE_MODE0 0x00 ///< Discharge time is 0.75 us (recommended for most   
                                           ///< switches).                                        
#define CS0MD2_CS0DT__DISCHARGE_MODE1 0x08 ///< Discharge time is 1.0 us.                         
#define CS0MD2_CS0DT__DISCHARGE_MODE2 0x10 ///< Discharge time is 1.2 us.                         
#define CS0MD2_CS0DT__DISCHARGE_MODE3 0x18 ///< Discharge time is 1.5 us.                         
#define CS0MD2_CS0DT__DISCHARGE_MODE4 0x20 ///< Discharge time is 2 us.                           
#define CS0MD2_CS0DT__DISCHARGE_MODE5 0x28 ///< Discharge time is 3 us.                           
#define CS0MD2_CS0DT__DISCHARGE_MODE6 0x30 ///< Discharge time is 6 us.                           
#define CS0MD2_CS0DT__DISCHARGE_MODE7 0x38 ///< Discharge time is 12 us.                          
                                                                                                  
#define CS0MD2_CS0CR__FMASK           0xC0 ///< CS0 Conversion Rate                               
#define CS0MD2_CS0CR__SHIFT           0x06 ///< CS0 Conversion Rate                               
#define CS0MD2_CS0CR__12_BITS         0x00 ///< Conversions last 12 internal CS0 clocks and are 12
                                           ///< bits in length.                                   
#define CS0MD2_CS0CR__13_BITS         0x40 ///< Conversions last 13 internal CS0 clocks and are 13
                                           ///< bits in length.                                   
#define CS0MD2_CS0CR__14_BITS         0x80 ///< Conversions last 14 internal CS0 clocks and are 14
                                           ///< bits in length.                                   
#define CS0MD2_CS0CR__16_BITS         0xC0 ///< Conversions last 16 internal CS0 clocks.and are 16
                                           ///< bits in length.                                   
                                                                                                  
//------------------------------------------------------------------------------
// CS0MD3 Enums (Capacitive Sense 0 Mode 3 @ 0xBF)
//------------------------------------------------------------------------------
#define CS0MD3_CS0LP__FMASK      0x07 ///< CS0 Low Pass Filter Selection        
#define CS0MD3_CS0LP__SHIFT      0x00 ///< CS0 Low Pass Filter Selection        
                                                                                
#define CS0MD3_CS0RP__FMASK      0x18 ///< CS0 Ramp Selection                   
#define CS0MD3_CS0RP__SHIFT      0x03 ///< CS0 Ramp Selection                   
#define CS0MD3_CS0RP__RAMP_MODE0 0x00 ///< Ramp time is less than 1.5 us.       
#define CS0MD3_CS0RP__RAMP_MODE1 0x08 ///< Ramp time is between 1.5 us and 3 us.
#define CS0MD3_CS0RP__RAMP_MODE2 0x10 ///< Ramp time is between 3 us and 6 us.  
#define CS0MD3_CS0RP__RAMP_MODE3 0x18 ///< Ramp time is greater than 6 us.      
                                                                                
//------------------------------------------------------------------------------
// CS0MX Enums (Capacitive Sense 0 Mux Channel Select @ 0xAB)
//------------------------------------------------------------------------------
#define CS0MX_CS0MX__FMASK             0x3F ///< CS0 Mux Channel Select          
#define CS0MX_CS0MX__SHIFT             0x00 ///< CS0 Mux Channel Select          
#define CS0MX_CS0MX__CS0P0             0x00 ///< Select CS0.0.                   
#define CS0MX_CS0MX__CS0P1             0x01 ///< Select CS0.1.                   
#define CS0MX_CS0MX__CS0P2             0x02 ///< Select CS0.2.                   
#define CS0MX_CS0MX__CS0P3             0x03 ///< Select CS0.3.                   
#define CS0MX_CS0MX__CS0P4             0x04 ///< Select CS0.4.                   
#define CS0MX_CS0MX__CS0P5             0x05 ///< Select CS0.5.                   
#define CS0MX_CS0MX__CS0P6             0x06 ///< Select CS0.6.                   
#define CS0MX_CS0MX__CS0P7             0x07 ///< Select CS0.7.                   
#define CS0MX_CS0MX__CS0P8             0x08 ///< Select CS0.8.                   
#define CS0MX_CS0MX__CS0P9             0x09 ///< Select CS0.9.                   
#define CS0MX_CS0MX__CS0P10            0x0A ///< Select CS0.10.                  
#define CS0MX_CS0MX__CS0P11            0x0B ///< Select CS0.11.                  
#define CS0MX_CS0MX__CS0P12            0x0C ///< Select CS0.12.                  
#define CS0MX_CS0MX__CS0P13            0x0D ///< Select CS0.13.                  
#define CS0MX_CS0MX__CS0P14            0x0E ///< Select CS0.14.                  
#define CS0MX_CS0MX__CS0P15            0x0F ///< Select CS0.15.                  
#define CS0MX_CS0MX__CS0P16            0x10 ///< Select CS0.16.                  
#define CS0MX_CS0MX__CS0P17            0x11 ///< Select CS0.17.                  
#define CS0MX_CS0MX__CS0P18            0x12 ///< Select CS0.18.                  
#define CS0MX_CS0MX__CS0P19            0x13 ///< Select CS0.19.                  
#define CS0MX_CS0MX__CS0P20            0x14 ///< Select CS0.20.                  
#define CS0MX_CS0MX__CS0P21            0x15 ///< Select CS0.21.                  
#define CS0MX_CS0MX__CS0P22            0x16 ///< Select CS0.22.                  
#define CS0MX_CS0MX__CS0P23            0x17 ///< Select CS0.23.                  
#define CS0MX_CS0MX__CS0P24            0x18 ///< Select CS0.24.                  
#define CS0MX_CS0MX__CS0P25            0x19 ///< Select CS0.25.                  
#define CS0MX_CS0MX__CS0P26            0x1A ///< Select CS0.26.                  
#define CS0MX_CS0MX__CS0P27            0x1B ///< Select CS0.27.                  
#define CS0MX_CS0MX__CS0P28            0x1C ///< Select CS0.28.                  
#define CS0MX_CS0MX__CS0P29            0x1D ///< Select CS0.29.                  
#define CS0MX_CS0MX__CS0P30            0x1E ///< Select CS0.30.                  
#define CS0MX_CS0MX__CS0P31            0x1F ///< Select CS0.31.                  
#define CS0MX_CS0MX__CS0P32            0x20 ///< Select CS0.32.                  
#define CS0MX_CS0MX__CS0P33            0x21 ///< Select CS0.33.                  
#define CS0MX_CS0MX__CS0P34            0x22 ///< Select CS0.34.                  
#define CS0MX_CS0MX__CS0P35            0x23 ///< Select CS0.35.                  
#define CS0MX_CS0MX__CS0P36            0x24 ///< Select CS0.36.                  
#define CS0MX_CS0MX__CS0P37            0x25 ///< Select CS0.37.                  
#define CS0MX_CS0MX__CS0P38            0x26 ///< Select CS0.38.                  
#define CS0MX_CS0MX__CS0P39            0x27 ///< Select CS0.39.                  
#define CS0MX_CS0MX__CS0P40            0x28 ///< Select CS0.40.                  
#define CS0MX_CS0MX__CS0P41            0x29 ///< Select CS0.41.                  
#define CS0MX_CS0MX__CS0P42            0x2A ///< Select CS0.42.                  
                                                                                 
#define CS0MX_CS0UC__BMASK             0x80 ///< CS0 Connect                     
#define CS0MX_CS0UC__SHIFT             0x07 ///< CS0 Connect                     
#define CS0MX_CS0UC__PINS_CONNECTED    0x00 ///< CS0 connected to port pins.     
#define CS0MX_CS0UC__PINS_DISCONNECTED 0x80 ///< CS0 disconnected from port pins.
                                                                                 
//------------------------------------------------------------------------------
// CS0PM Enums (Capacitive Sense 0 Pin Monitor @ 0x96)
//------------------------------------------------------------------------------
#define CS0PM_CSPMMD__FMASK                 0x03 ///< CS0 Pin Monitor Mode                             
#define CS0PM_CSPMMD__SHIFT                 0x00 ///< CS0 Pin Monitor Mode                             
#define CS0PM_CSPMMD__ALWAYS_RETRY          0x00 ///< Always retry bit cycles on a pin state change.   
#define CS0PM_CSPMMD__RETRY_TWO_TIMES       0x01 ///< Retry up to twice on consecutive bit cycles.     
#define CS0PM_CSPMMD__RETRY_FOUR_TIMES      0x02 ///< Retry up to four times on consecutive bit cycles.
                                                                                                       
#define CS0PM_I2C0PM__BMASK                 0x04 ///< I2C Slave Pin Monitor Enable                     
#define CS0PM_I2C0PM__SHIFT                 0x02 ///< I2C Slave Pin Monitor Enable                     
#define CS0PM_I2C0PM__PORT_MONITOR_DISABLED 0x00 ///< Disable monitoring of the I2C Slave output pin.  
#define CS0PM_I2C0PM__PORT_MONITOR_ENABLED  0x04 ///< Enable monitoring of the I2C Slave output pin.   
                                                                                                       
#define CS0PM_PIOPM__BMASK                  0x08 ///< Port I/O Pin Monitor Enable                      
#define CS0PM_PIOPM__SHIFT                  0x03 ///< Port I/O Pin Monitor Enable                      
#define CS0PM_PIOPM__PORT_MONITOR_DISABLED  0x00 ///< Disable monitoring of writes to the port latches.
#define CS0PM_PIOPM__PORT_MONITOR_ENABLED   0x08 ///< Enable monitoring of writes to the port latches. 
                                                                                                       
#define CS0PM_PCAPM__BMASK                  0x10 ///< PCA Pin Monitor Enable                           
#define CS0PM_PCAPM__SHIFT                  0x04 ///< PCA Pin Monitor Enable                           
#define CS0PM_PCAPM__PCA_MONITOR_DISABLED   0x00 ///< Disable monitoring on the PCA output pins.       
#define CS0PM_PCAPM__PCA_MONITOR_ENABLED    0x10 ///< Enable monitoring on the PCA output pins.        
                                                                                                       
#define CS0PM_SMBPM__BMASK                  0x20 ///< SMBus Pin Monitor Enable                         
#define CS0PM_SMBPM__SHIFT                  0x05 ///< SMBus Pin Monitor Enable                         
#define CS0PM_SMBPM__SMBUS_MONITOR_DISABLED 0x00 ///< Disable monitoring on the SMBus pins.            
#define CS0PM_SMBPM__SMBUS_MONITOR_ENABLED  0x20 ///< Enable monitoring on the SMBus pins.             
                                                                                                       
#define CS0PM_SPIPM__BMASK                  0x40 ///< SPI Pin Monitor Enable                           
#define CS0PM_SPIPM__SHIFT                  0x06 ///< SPI Pin Monitor Enable                           
#define CS0PM_SPIPM__SPI_MONITOR_DISABLED   0x00 ///< Disable monitoring on the SPI output pins.       
#define CS0PM_SPIPM__SPI_MONITOR_ENABLED    0x40 ///< Enable monitoring on the SPI output pins.        
                                                                                                       
#define CS0PM_UAPM__BMASK                   0x80 ///< UART Pin Monitor Enable                          
#define CS0PM_UAPM__SHIFT                   0x07 ///< UART Pin Monitor Enable                          
#define CS0PM_UAPM__UART_MONITOR_DISABLED   0x00 ///< Disable monitoring on the UART TX pin.           
#define CS0PM_UAPM__UART_MONITOR_ENABLED    0x80 ///< Enable monitoring on the UART TX pin.            
                                                                                                       
//------------------------------------------------------------------------------
// CS0SE Enums (Capacitive Sense 0 Auto Scan End Channel @ 0xDE)
//------------------------------------------------------------------------------
#define CS0SE_CS0SE__FMASK 0x3F ///< Ending Channel for Auto Scan
#define CS0SE_CS0SE__SHIFT 0x00 ///< Ending Channel for Auto Scan
                                                                 
//------------------------------------------------------------------------------
// CS0SS Enums (Capacitive Sense 0 Auto Scan Start Channel @ 0xDD)
//------------------------------------------------------------------------------
#define CS0SS_CS0SS__FMASK 0x3F ///< Starting Channel for Auto Scan
#define CS0SS_CS0SS__SHIFT 0x00 ///< Starting Channel for Auto Scan
                                                                   
//------------------------------------------------------------------------------
// CS0THH Enums (Capacitive Sense 0 Comparator Threshold High Byte @ 0xFE)
//------------------------------------------------------------------------------
#define CS0THH_CS0THH__FMASK 0xFF ///< CS0 Comparator Threshold High Byte
#define CS0THH_CS0THH__SHIFT 0x00 ///< CS0 Comparator Threshold High Byte
                                                                         
//------------------------------------------------------------------------------
// CS0THL Enums (Capacitive Sense 0 Comparator Threshold Low Byte @ 0xFD)
//------------------------------------------------------------------------------
#define CS0THL_CS0THL__FMASK 0xFF ///< CS0 Comparator Threshold Low Byte
#define CS0THL_CS0THL__SHIFT 0x00 ///< CS0 Comparator Threshold Low Byte
                                                                        
//------------------------------------------------------------------------------
// DEVICEID Enums (Device Identification @ 0xE1)
//------------------------------------------------------------------------------
#define DEVICEID_DEVICEID__FMASK 0xFF ///< Device ID
#define DEVICEID_DEVICEID__SHIFT 0x00 ///< Device ID
                                                    
//------------------------------------------------------------------------------
// REVID Enums (Revision Identifcation @ 0xE2)
//------------------------------------------------------------------------------
#define REVID_REVID__FMASK 0xFF ///< Revision ID
#define REVID_REVID__SHIFT 0x00 ///< Revision ID
#define REVID_REVID__REV_A 0x01 ///< Revision A 
                                                
//------------------------------------------------------------------------------
// DMA0BUSY Enums (DMA0 Busy @ 0x91)
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
// DMA0EN Enums (DMA0 Channel Enable @ 0x92)
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
// DMA0INT Enums (DMA0 Full-Length Interrupt Flags @ 0xE8)
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
// DMA0MINT Enums (DMA0 Mid-Point Interrupt Flags @ 0x88)
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
// DMA0NAOH Enums (Memory Address Offset High @ 0xCC)
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
// DMA0NAOL Enums (Memory Address Offset Low @ 0xCB)
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
// DMA0NBAH Enums (Memory Base Address High @ 0xCA)
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
// DMA0NBAL Enums (Memory Base Address Low @ 0xC9)
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
// DMA0NCF Enums (DMA0 Channel Configuration @ 0xD8)
//------------------------------------------------------------------------------
#define DMA0NCF_PERIPH__FMASK            0x07 ///< Peripheral Transfer Select                        
#define DMA0NCF_PERIPH__SHIFT            0x00 ///< Peripheral Transfer Select                        
#define DMA0NCF_PERIPH__XRAM_TO_MAC_A    0x02 ///< The DMA channel transfers from XRAM to the MAC A  
                                              ///< register.                                         
#define DMA0NCF_PERIPH__XRAM_TO_MAC_B    0x03 ///< The DMA channel transfers from XRAM to the MAC B  
                                              ///< register.                                         
#define DMA0NCF_PERIPH__XRAM_TO_MAC_ACC  0x04 ///< The DMA channel transfers from XRAM to the MAC    
                                              ///< accumulator registers.                            
#define DMA0NCF_PERIPH__MAC_ACC_TO_XRAM  0x05 ///< The DMA channel transfers from the MAC accumulator
                                              ///< registers to XRAM.                                
#define DMA0NCF_PERIPH__XRAM_TO_I2C_DATA 0x06 ///< The DMA channel transfers from XRAM to the I2C    
                                              ///< Slave data register.                              
#define DMA0NCF_PERIPH__I2C_DATA_TO_XRAM 0x07 ///< The DMA channel transfers from the I2C Slave data 
                                              ///< register to XRAM.                                 
                                                                                                     
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
// DMA0NSZH Enums (Memory Transfer Size High @ 0xCE)
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
// DMA0NSZL Enums (Memory Transfer Size Low @ 0xCD)
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
// DMA0SEL Enums (DMA0 Channel Select @ 0x94)
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
// IT01CF Enums (INT0/INT1 Configuration @ 0xDE)
//------------------------------------------------------------------------------
#define IT01CF_IN0SL__FMASK       0x07 ///< INT0 Port Pin Selection   
#define IT01CF_IN0SL__SHIFT       0x00 ///< INT0 Port Pin Selection   
#define IT01CF_IN0SL__P0_0        0x00 ///< Select P0.0.              
#define IT01CF_IN0SL__P0_1        0x01 ///< Select P0.1.              
#define IT01CF_IN0SL__P0_2        0x02 ///< Select P0.2.              
#define IT01CF_IN0SL__P0_3        0x03 ///< Select P0.3.              
#define IT01CF_IN0SL__P0_4        0x04 ///< Select P0.4.              
#define IT01CF_IN0SL__P0_5        0x05 ///< Select P0.5.              
#define IT01CF_IN0SL__P0_6        0x06 ///< Select P0.6.              
#define IT01CF_IN0SL__P0_7        0x07 ///< Select P0.7.              
                                                                      
#define IT01CF_IN0PL__BMASK       0x08 ///< INT0 Polarity             
#define IT01CF_IN0PL__SHIFT       0x03 ///< INT0 Polarity             
#define IT01CF_IN0PL__ACTIVE_LOW  0x00 ///< INT0 input is active low. 
#define IT01CF_IN0PL__ACTIVE_HIGH 0x08 ///< INT0 input is active high.
                                                                      
#define IT01CF_IN1SL__FMASK       0x70 ///< INT1 Port Pin Selection   
#define IT01CF_IN1SL__SHIFT       0x04 ///< INT1 Port Pin Selection   
#define IT01CF_IN1SL__P0_0        0x00 ///< Select P0.0.              
#define IT01CF_IN1SL__P0_1        0x10 ///< Select P0.1.              
#define IT01CF_IN1SL__P0_2        0x20 ///< Select P0.2.              
#define IT01CF_IN1SL__P0_3        0x30 ///< Select P0.3.              
#define IT01CF_IN1SL__P0_4        0x40 ///< Select P0.4.              
#define IT01CF_IN1SL__P0_5        0x50 ///< Select P0.5.              
#define IT01CF_IN1SL__P0_6        0x60 ///< Select P0.6.              
#define IT01CF_IN1SL__P0_7        0x70 ///< Select P0.7.              
                                                                      
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
#define FLSCL_BYPASS__ONE_SHOT 0x00 ///< The one-shot determines the flash read time. This
                                    ///< setting should be used for operating frequencies 
                                    ///< less than 14 MHz.                                
#define FLSCL_BYPASS__SYSCLK   0x40 ///< The system clock determines the flash read time. 
                                    ///< This setting should be used for frequencies      
                                    ///< greater than 14 MHz.                             
                                                                                          
//------------------------------------------------------------------------------
// FLWR Enums (Flash Write Only @ 0xE5)
//------------------------------------------------------------------------------
#define FLWR_FLWR__FMASK 0xFF ///< Flash Write Only
#define FLWR_FLWR__SHIFT 0x00 ///< Flash Write Only
                                                   
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
// OSCICL Enums (High Frequency Oscillator Calibration @ 0xAF)
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
// I2C0CN Enums (I2C0 Control @ 0xAC)
//------------------------------------------------------------------------------
#define I2C0CN_BUSY__BMASK       0x01 ///< Busy                                              
#define I2C0CN_BUSY__SHIFT       0x00 ///< Busy                                              
#define I2C0CN_BUSY__NOT_SET     0x00 ///< Device will acknowledge an I2C master.            
#define I2C0CN_BUSY__SET         0x01 ///< Device will not respond to an I2C master. All I2C 
                                      ///< data sent to the device will be NACKed.           
                                                                                             
#define I2C0CN_I2C0EN__BMASK     0x02 ///< I2C Enable                                        
#define I2C0CN_I2C0EN__SHIFT     0x01 ///< I2C Enable                                        
#define I2C0CN_I2C0EN__DISABLED  0x00 ///< Disable the I2C0 Slave module.                    
#define I2C0CN_I2C0EN__ENABLED   0x02 ///< Enable the I2C0 Slave module.                     
                                                                                             
#define I2C0CN_PRELOAD__BMASK    0x04 ///< Preload Disable                                   
#define I2C0CN_PRELOAD__SHIFT    0x02 ///< Preload Disable                                   
#define I2C0CN_PRELOAD__ENABLED  0x00 ///< Data bytes must be written into the I2C0DOUT      
                                      ///< register before the 8th SCL clock of the matching 
                                      ///< slave address byte transfer arrives for an I2C    
                                      ///< read operation.                                   
#define I2C0CN_PRELOAD__DISABLED 0x04 ///< Data bytes need not be preloaded for I2C read     
                                      ///< operations. The data byte can be written to       
                                      ///< I2C0DOUT during interrupt servicing or by the DMA.
                                                                                             
#define I2C0CN_TIMEOUT__BMASK    0x08 ///< Timeout Enable                                    
#define I2C0CN_TIMEOUT__SHIFT    0x03 ///< Timeout Enable                                    
#define I2C0CN_TIMEOUT__DISABLED 0x00 ///< Disable I2C SCL timeout detection using Timer 3.  
#define I2C0CN_TIMEOUT__ENABLED  0x08 ///< Enable I2C SCL timeout detection using Timer 3.   
                                                                                             
#define I2C0CN_PINMD__BMASK      0x10 ///< Pin Mode Enable                                   
#define I2C0CN_PINMD__SHIFT      0x04 ///< Pin Mode Enable                                   
#define I2C0CN_PINMD__GPIO_MODE  0x00 ///< Set the I2C0 Slave pins in GPIO mode.             
#define I2C0CN_PINMD__I2C_MODE   0x10 ///< Set the I2C0 Slave pins in I2C mode.              
                                                                                             
#define I2C0CN_PUEN__BMASK       0x20 ///< I2C Pull-Up Enable                                
#define I2C0CN_PUEN__SHIFT       0x05 ///< I2C Pull-Up Enable                                
#define I2C0CN_PUEN__DISABLED    0x00 ///< Disable internal pull-up resistors for the I2C0   
                                      ///< Slave SCL and SDA pins.                           
#define I2C0CN_PUEN__ENABLED     0x20 ///< Enable internal pull-up resistors for the I2C0    
                                      ///< Slave SCL and SDA pins.                           
                                                                                             
//------------------------------------------------------------------------------
// I2C0DIN Enums (I2C0 Received Data @ 0xA5)
//------------------------------------------------------------------------------
#define I2C0DIN_I2C0DIN__FMASK 0xFF ///< I2C0 Received Data
#define I2C0DIN_I2C0DIN__SHIFT 0x00 ///< I2C0 Received Data
                                                           
//------------------------------------------------------------------------------
// I2C0DOUT Enums (I2C0 Transmit Data @ 0xA4)
//------------------------------------------------------------------------------
#define I2C0DOUT_I2C0DOUT__FMASK 0xFF ///< I2C0 Transmit Data
#define I2C0DOUT_I2C0DOUT__SHIFT 0x00 ///< I2C0 Transmit Data
                                                             
//------------------------------------------------------------------------------
// I2C0SLAD Enums (I2C0 Slave Address @ 0xAD)
//------------------------------------------------------------------------------
#define I2C0SLAD_I2C0SLAD__FMASK 0x7F ///< I2C Hardware Slave Address
#define I2C0SLAD_I2C0SLAD__SHIFT 0x00 ///< I2C Hardware Slave Address
                                                                     
//------------------------------------------------------------------------------
// I2C0STAT Enums (I2C0 Status @ 0xF8)
//------------------------------------------------------------------------------
#define I2C0STAT_RD__BMASK        0x01 ///< I2C Read                                        
#define I2C0STAT_RD__SHIFT        0x00 ///< I2C Read                                        
#define I2C0STAT_RD__NOT_SET      0x00 ///< An I2C Read operation is not in progress.       
#define I2C0STAT_RD__SET          0x01 ///< An I2C Read operation is in progress.           
                                                                                            
#define I2C0STAT_WR__BMASK        0x02 ///< I2C Write                                       
#define I2C0STAT_WR__SHIFT        0x01 ///< I2C Write                                       
#define I2C0STAT_WR__NOT_SET      0x00 ///< An I2C Write operation is not in progress.      
#define I2C0STAT_WR__SET          0x02 ///< An I2C Write operation is in progress.          
                                                                                            
#define I2C0STAT_STOP__BMASK      0x04 ///< Stop                                            
#define I2C0STAT_STOP__SHIFT      0x02 ///< Stop                                            
#define I2C0STAT_STOP__NOT_SET    0x00 ///< A STOP is not pending.                          
#define I2C0STAT_STOP__SET        0x04 ///< A STOP is currently pending for the I2C0 Slave. 
                                                                                            
#define I2C0STAT_START__BMASK     0x08 ///< Start                                           
#define I2C0STAT_START__SHIFT     0x03 ///< Start                                           
#define I2C0STAT_START__NOT_SET   0x00 ///< A START was not detected.                       
#define I2C0STAT_START__SET       0x08 ///< A START is currently pending for the I2C0 Slave.
                                                                                            
#define I2C0STAT_NACK__BMASK      0x10 ///< NACK                                            
#define I2C0STAT_NACK__SHIFT      0x04 ///< NACK                                            
#define I2C0STAT_NACK__NOT_SET    0x00 ///< A NACK did not occur.                           
#define I2C0STAT_NACK__SET        0x10 ///< A NACK occurred.                                
                                                                                            
#define I2C0STAT_I2C0INT__BMASK   0x20 ///< I2C Interrupt                                   
#define I2C0STAT_I2C0INT__SHIFT   0x05 ///< I2C Interrupt                                   
#define I2C0STAT_I2C0INT__NOT_SET 0x00 ///< An interrupt did not occur.                     
#define I2C0STAT_I2C0INT__SET     0x20 ///< An interrupt occurred.                          
                                                                                            
#define I2C0STAT_ACTIVE__BMASK    0x40 ///< Bus Active                                      
#define I2C0STAT_ACTIVE__SHIFT    0x06 ///< Bus Active                                      
#define I2C0STAT_ACTIVE__NOT_SET  0x00 ///< A transfer is not in progress.                  
#define I2C0STAT_ACTIVE__SET      0x40 ///< A transfer is in progress.                      
                                                                                            
#define I2C0STAT_HSMODE__BMASK    0x80 ///< High Speed Mode                                 
#define I2C0STAT_HSMODE__SHIFT    0x07 ///< High Speed Mode                                 
#define I2C0STAT_HSMODE__NOT_SET  0x00 ///< A High Speed transfer is not in progress.       
#define I2C0STAT_HSMODE__SET      0x80 ///< A High Speed transfer is in progress.           
                                                                                            
//------------------------------------------------------------------------------
// EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
//------------------------------------------------------------------------------
#define EIE1_ESMB0__BMASK     0x01 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__SHIFT     0x00 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__DISABLED  0x00 ///< Disable all SMB0 interrupts.                      
#define EIE1_ESMB0__ENABLED   0x01 ///< Enable interrupt requests generated by SMB0.      
                                                                                          
#define EIE1_ERTC0A__BMASK    0x02 ///< RTC Alarm Interrupts Enable                       
#define EIE1_ERTC0A__SHIFT    0x01 ///< RTC Alarm Interrupts Enable                       
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
                                                                                          
#define EIE1_EDMA0M__BMASK    0x20 ///< DMA0 Mid-Point Interrupt Enable                   
#define EIE1_EDMA0M__SHIFT    0x05 ///< DMA0 Mid-Point Interrupt Enable                   
#define EIE1_EDMA0M__DISABLED 0x00 ///< Disable DMA0M interrupts.                         
#define EIE1_EDMA0M__ENABLED  0x20 ///< Enable interrupt requests generated by the DMA0M  
                                   ///< flags.                                            
                                                                                          
#define EIE1_EDMA0__BMASK     0x40 ///< DMA0 Interrupt Enable                             
#define EIE1_EDMA0__SHIFT     0x06 ///< DMA0 Interrupt Enable                             
#define EIE1_EDMA0__DISABLED  0x00 ///< Disable DMA0 interrupts.                          
#define EIE1_EDMA0__ENABLED   0x40 ///< Enable interrupt requests generated by DMA0.      
                                                                                          
#define EIE1_ET3__BMASK       0x80 ///< Timer 3 Interrupt Enable                          
#define EIE1_ET3__SHIFT       0x07 ///< Timer 3 Interrupt Enable                          
#define EIE1_ET3__DISABLED    0x00 ///< Disable Timer 3 interrupts.                       
#define EIE1_ET3__ENABLED     0x80 ///< Enable interrupt requests generated by the TF3L or
                                   ///< TF3H flags.                                       
                                                                                          
//------------------------------------------------------------------------------
// EIE2 Enums (Extended Interrupt Enable 2 @ 0xE7)
//------------------------------------------------------------------------------
#define EIE2_EMAT__BMASK      0x02 ///< Port Match Interrupts Enable                         
#define EIE2_EMAT__SHIFT      0x01 ///< Port Match Interrupts Enable                         
#define EIE2_EMAT__DISABLED   0x00 ///< Disable all Port Match interrupts.                   
#define EIE2_EMAT__ENABLED    0x02 ///< Enable interrupt requests generated by a Port        
                                   ///< Match.                                               
                                                                                             
#define EIE2_ERTC0F__BMASK    0x04 ///< RTC Oscillator Fail Interrupt Enable                 
#define EIE2_ERTC0F__SHIFT    0x02 ///< RTC Oscillator Fail Interrupt Enable                 
#define EIE2_ERTC0F__DISABLED 0x00 ///< Disable RTC Alarm interrupts.                        
#define EIE2_ERTC0F__ENABLED  0x04 ///< Enable interrupt requests generated by the RTC       
                                   ///< Alarm.                                               
                                                                                             
#define EIE2_EMAC0__BMASK     0x08 ///< MAC0 Interrupt Enable                                
#define EIE2_EMAC0__SHIFT     0x03 ///< MAC0 Interrupt Enable                                
#define EIE2_EMAC0__DISABLED  0x00 ///< Disable MAC0 event interrupt.                        
#define EIE2_EMAC0__ENABLED   0x08 ///< Enable interrupt requests generated by MAC0.         
                                                                                             
#define EIE2_ECSCPT__BMASK    0x10 ///< Capacitive Sense Conversion Complete Interrupt Enable
#define EIE2_ECSCPT__SHIFT    0x04 ///< Capacitive Sense Conversion Complete Interrupt Enable
#define EIE2_ECSCPT__DISABLED 0x00 ///< Disable Capacitive Sense Conversion Complete         
                                   ///< interrupt.                                           
#define EIE2_ECSCPT__ENABLED  0x10 ///< Enable interrupt requests generated by CS0INT.       
                                                                                             
#define EIE2_ECSDC__BMASK     0x20 ///< Capacitive Sense Digital Comparator Interrupt Enable 
#define EIE2_ECSDC__SHIFT     0x05 ///< Capacitive Sense Digital Comparator Interrupt Enable 
#define EIE2_ECSDC__DISABLED  0x00 ///< Disable Capacitive Sense Digital Comparator          
                                   ///< interrupt.                                           
#define EIE2_ECSDC__ENABLED   0x20 ///< Enable interrupt requests generated by the           
                                   ///< Capacitive Sense Digital Comparator.                 
                                                                                             
#define EIE2_ECSEOS__BMASK    0x40 ///< Capacitive Sense End of Scan Interrupt Enable        
#define EIE2_ECSEOS__SHIFT    0x06 ///< Capacitive Sense End of Scan Interrupt Enable        
#define EIE2_ECSEOS__DISABLED 0x00 ///< Disable Capacitive Sense End of Scan interrupt.      
#define EIE2_ECSEOS__ENABLED  0x40 ///< Enable interrupt requests generated by the           
                                   ///< Capacitive Sense End of Scan.                        
                                                                                             
#define EIE2_EI2C0__BMASK     0x80 ///< I2C0 Slave Interrupt Enable                          
#define EIE2_EI2C0__SHIFT     0x07 ///< I2C0 Slave Interrupt Enable                          
#define EIE2_EI2C0__DISABLED  0x00 ///< Disable I2C0 Slave event interrupt.                  
#define EIE2_EI2C0__ENABLED   0x80 ///< Enable interrupt requests generated by the I2C0      
                                   ///< Slave.                                               
                                                                                             
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
                                                                                                 
#define EIP1_PDMA0M__BMASK 0x20 ///< DMA0 Mid-Point Interrupt Priority Control                   
#define EIP1_PDMA0M__SHIFT 0x05 ///< DMA0 Mid-Point Interrupt Priority Control                   
#define EIP1_PDMA0M__LOW   0x00 ///< Mid-point DMA0 interrupts set to low priority               
                                ///< level.                                                      
#define EIP1_PDMA0M__HIGH  0x20 ///< Mid-point DMA0 interrupts set to high priority              
                                ///< level.                                                      
                                                                                                 
#define EIP1_PDMA0__BMASK  0x40 ///< DMA0 Interrupt Priority Control                             
#define EIP1_PDMA0__SHIFT  0x06 ///< DMA0 Interrupt Priority Control                             
#define EIP1_PDMA0__LOW    0x00 ///< DMA0 interrupts set to low priority level.                  
#define EIP1_PDMA0__HIGH   0x40 ///< DMA0 interrupts set to high priority level.                 
                                                                                                 
#define EIP1_PT3__BMASK    0x80 ///< Timer 3 Interrupt Priority Control                          
#define EIP1_PT3__SHIFT    0x07 ///< Timer 3 Interrupt Priority Control                          
#define EIP1_PT3__LOW      0x00 ///< Timer 3 interrupts set to low priority level.               
#define EIP1_PT3__HIGH     0x80 ///< Timer 3 interrupts set to high priority level.              
                                                                                                 
//------------------------------------------------------------------------------
// EIP2 Enums (Extended Interrupt Priority 2 @ 0xF7)
//------------------------------------------------------------------------------
#define EIP2_PMAT__BMASK   0x02 ///< Port Match Interrupt Priority Control                          
#define EIP2_PMAT__SHIFT   0x01 ///< Port Match Interrupt Priority Control                          
#define EIP2_PMAT__LOW     0x00 ///< Port Match interrupt set to low priority level.                
#define EIP2_PMAT__HIGH    0x02 ///< Port Match interrupt set to high priority level.               
                                                                                                    
#define EIP2_PRTC0F__BMASK 0x04 ///< RTC Oscillator Fail Interrupt Priority Control                 
#define EIP2_PRTC0F__SHIFT 0x02 ///< RTC Oscillator Fail Interrupt Priority Control                 
#define EIP2_PRTC0F__LOW   0x00 ///< RTC Alarm interrupt set to low priority level.                 
#define EIP2_PRTC0F__HIGH  0x04 ///< RTC Alarm interrupt set to high priority level.                
                                                                                                    
#define EIP2_PMAC0__BMASK  0x08 ///< MAC0 Interrupt Priority Control                                
#define EIP2_PMAC0__SHIFT  0x03 ///< MAC0 Interrupt Priority Control                                
#define EIP2_PMAC0__LOW    0x00 ///< MAC0 interrupts set to low priority level.                     
#define EIP2_PMAC0__HIGH   0x08 ///< MAC0 interrupts set to high priority level.                    
                                                                                                    
#define EIP2_PCSCPT__BMASK 0x10 ///< Capacitive Sense Conversion Complete Interrupt Priority Control
#define EIP2_PCSCPT__SHIFT 0x04 ///< Capacitive Sense Conversion Complete Interrupt Priority Control
#define EIP2_PCSCPT__LOW   0x00 ///< Capacitive Sense Conversion Complete interrupt set             
                                ///< to low priority level.                                         
#define EIP2_PCSCPT__HIGH  0x10 ///< Capacitive Sense Conversion Complete interrupt set             
                                ///< to high priority level.                                        
                                                                                                    
#define EIP2_PCSDC__BMASK  0x20 ///< Capacitive Sense Digital Comparator Interrupt Priority Control 
#define EIP2_PCSDC__SHIFT  0x05 ///< Capacitive Sense Digital Comparator Interrupt Priority Control 
#define EIP2_PCSDC__LOW    0x00 ///< Capacitive Sense Digital Comparator interrupt set              
                                ///< to low priority level.                                         
#define EIP2_PCSDC__HIGH   0x20 ///< Capacitive Sense Digital Comparator interrupt set              
                                ///< to high priority level.                                        
                                                                                                    
#define EIP2_PCSEOS__BMASK 0x40 ///< Capacitive Sense End of Scan Interrupt Priority Control        
#define EIP2_PCSEOS__SHIFT 0x06 ///< Capacitive Sense End of Scan Interrupt Priority Control        
#define EIP2_PCSEOS__LOW   0x00 ///< Capacitive Sense End of Scan interrupt set to low              
                                ///< priority level.                                                
#define EIP2_PCSEOS__HIGH  0x40 ///< Capacitive Sense End of Scan interrupt set to high             
                                ///< priority level.                                                
                                                                                                    
#define EIP2_PI2C0__BMASK  0x80 ///< I2C0 Slave Interrupt Priority Control                          
#define EIP2_PI2C0__SHIFT  0x07 ///< I2C0 Slave Interrupt Priority Control                          
#define EIP2_PI2C0__LOW    0x00 ///< I2C0 Slave interrupts set to low priority level.               
#define EIP2_PI2C0__HIGH   0x80 ///< I2C0 Slave interrupts set to high priority level.              
                                                                                                    
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
// MAC0ACC0 Enums (Accumulator Byte 0 @ 0xD2)
//------------------------------------------------------------------------------
#define MAC0ACC0_MAC0ACC0__FMASK 0xFF ///< MAC0 Accumulator Byte 0
#define MAC0ACC0_MAC0ACC0__SHIFT 0x00 ///< MAC0 Accumulator Byte 0
                                                                  
//------------------------------------------------------------------------------
// MAC0ACC1 Enums (Accumulator Byte 1 @ 0xD3)
//------------------------------------------------------------------------------
#define MAC0ACC1_MAC0ACC1__FMASK 0xFF ///< MAC0 Accumulator Byte 1
#define MAC0ACC1_MAC0ACC1__SHIFT 0x00 ///< MAC0 Accumulator Byte 1
                                                                  
//------------------------------------------------------------------------------
// MAC0ACC2 Enums (Accumulator Byte 2 @ 0xD4)
//------------------------------------------------------------------------------
#define MAC0ACC2_MAC0ACC2__FMASK 0xFF ///< MAC0 Accumulator Byte 2
#define MAC0ACC2_MAC0ACC2__SHIFT 0x00 ///< MAC0 Accumulator Byte 2
                                                                  
//------------------------------------------------------------------------------
// MAC0ACC3 Enums (Accumulator Byte 3 @ 0xD5)
//------------------------------------------------------------------------------
#define MAC0ACC3_MAC0ACC3__FMASK 0xFF ///< MAC0 Accumulator Byte 3
#define MAC0ACC3_MAC0ACC3__SHIFT 0x00 ///< MAC0 Accumulator Byte 3
                                                                  
//------------------------------------------------------------------------------
// MAC0AH Enums (Operand A High Byte @ 0xAB)
//------------------------------------------------------------------------------
#define MAC0AH_MAC0AH__FMASK 0xFF ///< MAC0 A High Byte
#define MAC0AH_MAC0AH__SHIFT 0x00 ///< MAC0 A High Byte
                                                       
//------------------------------------------------------------------------------
// MAC0AL Enums (Operand A Low Byte @ 0xAA)
//------------------------------------------------------------------------------
#define MAC0AL_MAC0AL__FMASK 0xFF ///< MAC0 A Low Byte
#define MAC0AL_MAC0AL__SHIFT 0x00 ///< MAC0 A Low Byte
                                                      
//------------------------------------------------------------------------------
// MAC0BH Enums (Operand B High Byte @ 0xAF)
//------------------------------------------------------------------------------
#define MAC0BH_MAC0BH__FMASK 0xFF ///< MAC0 B High Byte
#define MAC0BH_MAC0BH__SHIFT 0x00 ///< MAC0 B High Byte
                                                       
//------------------------------------------------------------------------------
// MAC0BL Enums (Operand B Low Byte @ 0xAE)
//------------------------------------------------------------------------------
#define MAC0BL_MAC0BL__FMASK 0xFF ///< MAC0 B Low Byte
#define MAC0BL_MAC0BL__SHIFT 0x00 ///< MAC0 B Low Byte
                                                      
//------------------------------------------------------------------------------
// MAC0CF0 Enums (MAC0 Configuration 0 @ 0xC0)
//------------------------------------------------------------------------------
#define MAC0CF0_ANEGATE__BMASK      0x01 ///< Negate A input                                   
#define MAC0CF0_ANEGATE__SHIFT      0x00 ///< Negate A input                                   
#define MAC0CF0_ANEGATE__DISABLED   0x00 ///< No change is applied to the MAC0 A input before  
                                         ///< the multiply operation.                          
#define MAC0CF0_ANEGATE__ENABLED    0x01 ///< Hardware negates the MAC0 A input before the     
                                         ///< multiply operation.                              
                                                                                               
#define MAC0CF0_BNEGATE__BMASK      0x02 ///< Negate B input                                   
#define MAC0CF0_BNEGATE__SHIFT      0x01 ///< Negate B input                                   
#define MAC0CF0_BNEGATE__DISABLED   0x00 ///< No change is applied to the MAC0 B input before  
                                         ///< the multiply operation.                          
#define MAC0CF0_BNEGATE__ENABLED    0x02 ///< Hardware negates the MAC0 B input before the     
                                         ///< multiply operation.                              
                                                                                               
#define MAC0CF0_ACCNEGATE__BMASK    0x04 ///< Negate Accumulator Input                         
#define MAC0CF0_ACCNEGATE__SHIFT    0x02 ///< Negate Accumulator Input                         
#define MAC0CF0_ACCNEGATE__DISABLED 0x00 ///< No change is applied to the accumulator before it
                                         ///< is added to the multiplication result of A and B.
#define MAC0CF0_ACCNEGATE__ENABLED  0x04 ///< Hardware negates the accumulator before it is    
                                         ///< added to the multiplication result of A and B.   
                                                                                               
#define MAC0CF0_ACCMD__BMASK        0x08 ///< Accumulate Mode                                  
#define MAC0CF0_ACCMD__SHIFT        0x03 ///< Accumulate Mode                                  
#define MAC0CF0_ACCMD__MAC_MODE     0x00 ///< Select multiply-and-accumulate (MAC) mode.       
#define MAC0CF0_ACCMD__MUL_MODE     0x08 ///< Select multiply-only mode.                       
                                                                                               
#define MAC0CF0_FRACMD__BMASK       0x10 ///< Fractional Mode                                  
#define MAC0CF0_FRACMD__SHIFT       0x04 ///< Fractional Mode                                  
#define MAC0CF0_FRACMD__INT_MODE    0x00 ///< MAC0 operates in Integer Mode.                   
#define MAC0CF0_FRACMD__FRAC_MODE   0x10 ///< MAC0 operates in Fractional Mode.                
                                                                                               
#define MAC0CF0_CLRACC__BMASK       0x20 ///< Clear Accumulator                                
#define MAC0CF0_CLRACC__SHIFT       0x05 ///< Clear Accumulator                                
#define MAC0CF0_CLRACC__START       0x20 ///< Clear the accumulator and the related MAC0STA    
                                         ///< register flags.                                  
                                                                                               
#define MAC0CF0_SHIFTDIR__BMASK     0x40 ///< Accumulator Shift Direction                      
#define MAC0CF0_SHIFTDIR__SHIFT     0x06 ///< Accumulator Shift Direction                      
#define MAC0CF0_SHIFTDIR__LEFT      0x00 ///< The MAC0 accumulator will be shifted left.       
#define MAC0CF0_SHIFTDIR__RIGHT     0x40 ///< The MAC0 accumulator will be shifted right.      
                                                                                               
#define MAC0CF0_SHIFTEN__BMASK      0x80 ///< Accumulator Shift Control                        
#define MAC0CF0_SHIFTEN__SHIFT      0x07 ///< Accumulator Shift Control                        
#define MAC0CF0_SHIFTEN__DISABLED   0x00 ///< Do not shift the accumulator by one bit in the   
                                         ///< SHIFTDIR direction.                              
#define MAC0CF0_SHIFTEN__ENABLED    0x80 ///< Shift the accumulator by one bit in the SHIFTDIR 
                                         ///< direction.                                       
                                                                                               
//------------------------------------------------------------------------------
// MAC0CF1 Enums (MAC0 Configuration 1 @ 0xC4)
//------------------------------------------------------------------------------
#define MAC0CF1_APOSTINC__BMASK    0x01 ///< A Post-Increment Enable                           
#define MAC0CF1_APOSTINC__SHIFT    0x00 ///< A Post-Increment Enable                           
#define MAC0CF1_APOSTINC__DISABLED 0x00 ///< Do not change the MAC0 A register after a MAC0    
                                        ///< operation.                                        
#define MAC0CF1_APOSTINC__ENABLED  0x01 ///< Increment the MAC0 A register after a MAC0        
                                        ///< operation.                                        
                                                                                               
#define MAC0CF1_ADMASRC__BMASK     0x02 ///< A DMA Data Source Selection                       
#define MAC0CF1_ADMASRC__SHIFT     0x01 ///< A DMA Data Source Selection                       
#define MAC0CF1_ADMASRC__XRAM      0x00 ///< Each MAC0 operation will request the DMA fetch    
                                        ///< data from XRAM for the MAC0 A register.           
#define MAC0CF1_ADMASRC__EXISTING  0x02 ///< Each MAC0 operation will use existing data in MAC0
                                        ///< A register.                                       
                                                                                               
#define MAC0CF1_BPOSTINC__BMASK    0x04 ///< B Post-Increment Enable                           
#define MAC0CF1_BPOSTINC__SHIFT    0x02 ///< B Post-Increment Enable                           
#define MAC0CF1_BPOSTINC__DISABLED 0x00 ///< Do not change the MAC0 B register after a MAC0    
                                        ///< operation.                                        
#define MAC0CF1_BPOSTINC__ENABLED  0x04 ///< Increment the MAC0 B register after a MAC0        
                                        ///< operation.                                        
                                                                                               
#define MAC0CF1_MAC0BC__BMASK      0x08 ///< B DMA Data Source Selection                       
#define MAC0CF1_MAC0BC__SHIFT      0x03 ///< B DMA Data Source Selection                       
#define MAC0CF1_MAC0BC__XRAM       0x00 ///< Each MAC0 operation will request the DMA fetch    
                                        ///< data from XRAM for the MAC0 B register.           
#define MAC0CF1_MAC0BC__EXISTING   0x08 ///< Each MAC0 operation will use existing data in MAC0
                                        ///< B register.                                       
                                                                                               
#define MAC0CF1_SIGNEDEN__BMASK    0x10 ///< Signed Mode Enable                                
#define MAC0CF1_SIGNEDEN__SHIFT    0x04 ///< Signed Mode Enable                                
#define MAC0CF1_SIGNEDEN__DISABLED 0x00 ///< MAC operations use unsigned arithmetic.           
#define MAC0CF1_SIGNEDEN__ENABLED  0x10 ///< MAC operations use signed arithmetic.             
                                                                                               
#define MAC0CF1_SIGNEXP__BMASK     0x20 ///< Expected Accumulator Sign                         
#define MAC0CF1_SIGNEXP__SHIFT     0x05 ///< Expected Accumulator Sign                         
#define MAC0CF1_SIGNEXP__NOT_SET   0x00 ///< Set the expected sign to zero.                    
#define MAC0CF1_SIGNEXP__SET       0x20 ///< Set the expected sign to one.                     
                                                                                               
#define MAC0CF1_MBSHIFT__FMASK     0xC0 ///< Multi-Bit Accumulator Shift                       
#define MAC0CF1_MBSHIFT__SHIFT     0x06 ///< Multi-Bit Accumulator Shift                       
#define MAC0CF1_MBSHIFT__1_BIT     0x00 ///< Shift the accumulator 1 bit.                      
#define MAC0CF1_MBSHIFT__2_BITS    0x40 ///< Shift the accumulator by 2 bits.                  
#define MAC0CF1_MBSHIFT__3_BITS    0x80 ///< Shift the accumulator by 3 bits.                  
#define MAC0CF1_MBSHIFT__4_BITS    0xC0 ///< Shift the accumulator by 4 bits.                  
                                                                                               
//------------------------------------------------------------------------------
// MAC0CF2 Enums (MAC0 Configuration 2 @ 0xC5)
//------------------------------------------------------------------------------
#define MAC0CF2_ACCDMAIN__FMASK               0x03 ///< Accumulator DMA Input Count                       
#define MAC0CF2_ACCDMAIN__SHIFT               0x00 ///< Accumulator DMA Input Count                       
#define MAC0CF2_ACCDMAIN__1_BYTE              0x00 ///< Request the DMA move 1 byte from XRAM to the      
                                                   ///< accumulator.                                      
#define MAC0CF2_ACCDMAIN__2_BYTES             0x01 ///< Request the DMA move 2 bytes from XRAM to the     
                                                   ///< accumulator.                                      
#define MAC0CF2_ACCDMAIN__4_BYTES             0x02 ///< Request the DMA move 4 bytes from XRAM to the     
                                                   ///< accumulator.                                      
#define MAC0CF2_ACCDMAIN__5_BYTES             0x03 ///< Request the DMA move 5 bytes from XRAM to the     
                                                   ///< accumulator.                                      
                                                                                                          
#define MAC0CF2_ACCDMAOUT__FMASK              0x0C ///< Accumulator DMA Output Count                      
#define MAC0CF2_ACCDMAOUT__SHIFT              0x02 ///< Accumulator DMA Output Count                      
#define MAC0CF2_ACCDMAOUT__1_BYTE             0x00 ///< Request the DMA move 1 byte from the accumulator  
                                                   ///< to XRAM.                                          
#define MAC0CF2_ACCDMAOUT__2_BYTES            0x04 ///< Request the DMA move 2 bytes from the accumulator 
                                                   ///< to XRAM.                                          
#define MAC0CF2_ACCDMAOUT__4_BYTES            0x08 ///< Request the DMA move 4 bytes from the accumulator 
                                                   ///< to XRAM.                                          
#define MAC0CF2_ACCDMAOUT__5_BYTES            0x0C ///< Request the DMA move 5 bytes from the accumulator 
                                                   ///< to XRAM.                                          
                                                                                                          
#define MAC0CF2_ACCALIGN__FMASK               0x30 ///< Accumulator Alignment                             
#define MAC0CF2_ACCALIGN__SHIFT               0x04 ///< Accumulator Alignment                             
#define MAC0CF2_ACCALIGN__NO_SHIFT            0x00 ///< Do not shift the accumulator output.              
#define MAC0CF2_ACCALIGN__SHIFT_RIGHT_1_BYTE  0x10 ///< Shift the accumulator output right by 1 byte.     
#define MAC0CF2_ACCALIGN__SHIFT_RIGHT_3_BYTES 0x20 ///< Shift the accumulator output right by 3 bytes.    
#define MAC0CF2_ACCALIGN__SHIFT_RIGHT_4_BYTES 0x30 ///< Shift the accumulator output right by 4 bytes.    
                                                                                                          
#define MAC0CF2_SATURATE__BMASK               0x40 ///< Saturation Enable                                 
#define MAC0CF2_SATURATE__SHIFT               0x06 ///< Saturation Enable                                 
#define MAC0CF2_SATURATE__DISABLED            0x00 ///< Rounded result will not saturate.                 
#define MAC0CF2_SATURATE__ENABLED             0x40 ///< Rounded result will saturate.                     
                                                                                                          
#define MAC0CF2_ROUND__BMASK                  0x80 ///< Rounding Enable                                   
#define MAC0CF2_ROUND__SHIFT                  0x07 ///< Rounding Enable                                   
#define MAC0CF2_ROUND__DISABLED               0x00 ///< MAC0 accumulator does not contain a 16-bit rounded
                                                   ///< result.                                           
#define MAC0CF2_ROUND__ENABLED                0x80 ///< MAC0 accumulator contains a 16-bit rounded result.
                                                                                                          
//------------------------------------------------------------------------------
// MAC0INTE Enums (MAC0 Interrupt Enable @ 0xC1)
//------------------------------------------------------------------------------
#define MAC0INTE_SOVFIEN__BMASK       0x01 ///< Soft Overflow Interrupt Enable    
#define MAC0INTE_SOVFIEN__SHIFT       0x00 ///< Soft Overflow Interrupt Enable    
#define MAC0INTE_SOVFIEN__DISABLED    0x00 ///< Disable soft overflow interrupts. 
#define MAC0INTE_SOVFIEN__ENABLED     0x01 ///< Enable soft overflow interrupts.  
                                                                                  
#define MAC0INTE_ZEROFIEN__BMASK      0x02 ///< Zero Flag Interrupt Enable        
#define MAC0INTE_ZEROFIEN__SHIFT      0x01 ///< Zero Flag Interrupt Enable        
#define MAC0INTE_ZEROFIEN__DISABLED   0x00 ///< Disable zero flag interrupts.     
#define MAC0INTE_ZEROFIEN__ENABLED    0x02 ///< Enable zero flag interrupts.      
                                                                                  
#define MAC0INTE_SCHANGEIEN__BMASK    0x04 ///< Sign Change Event Interrupt Enable
#define MAC0INTE_SCHANGEIEN__SHIFT    0x02 ///< Sign Change Event Interrupt Enable
#define MAC0INTE_SCHANGEIEN__DISABLED 0x00 ///< Disable sign change interrupts.   
#define MAC0INTE_SCHANGEIEN__ENABLED  0x04 ///< Enable sign change interrupts.    
                                                                                  
//------------------------------------------------------------------------------
// MAC0ITER Enums (Iteration Counter @ 0xD7)
//------------------------------------------------------------------------------
#define MAC0ITER_MAC0ITER__FMASK 0xFF ///< Iteration Counter
#define MAC0ITER_MAC0ITER__SHIFT 0x00 ///< Iteration Counter
                                                            
//------------------------------------------------------------------------------
// MAC0OVF Enums (Accumulator Overflow Byte @ 0xD6)
//------------------------------------------------------------------------------
#define MAC0OVF_MAC0OVF__FMASK 0xFF ///< MAC0 Accumulator Overflow Byte
#define MAC0OVF_MAC0OVF__SHIFT 0x00 ///< MAC0 Accumulator Overflow Byte
                                                                       
//------------------------------------------------------------------------------
// MAC0STA Enums (MAC0 Status @ 0xCF)
//------------------------------------------------------------------------------
#define MAC0STA_BUSY__BMASK      0x01 ///< Busy Flag                                         
#define MAC0STA_BUSY__SHIFT      0x00 ///< Busy Flag                                         
#define MAC0STA_BUSY__NOT_SET    0x00 ///< The MAC module is not busy with an operation or   
                                      ///< series of operations.                             
#define MAC0STA_BUSY__SET        0x01 ///< The MAC module is busy with an operation or series
                                      ///< of operations.                                    
                                                                                             
#define MAC0STA_SOVF__BMASK      0x02 ///< Soft Overflow Flag                                
#define MAC0STA_SOVF__SHIFT      0x01 ///< Soft Overflow Flag                                
#define MAC0STA_SOVF__NOT_SET    0x00 ///< A soft overflow did not occur.                    
#define MAC0STA_SOVF__SET        0x02 ///< A soft overflow occurred.                         
                                                                                             
#define MAC0STA_ZEROF__BMASK     0x04 ///< Zero Flag                                         
#define MAC0STA_ZEROF__SHIFT     0x02 ///< Zero Flag                                         
#define MAC0STA_ZEROF__NOT_SET   0x00 ///< The last operation did not result in an           
                                      ///< accumulator value of zero.                        
#define MAC0STA_ZEROF__SET       0x04 ///< The last operation resulted in an accumulator     
                                      ///< value of zero.                                    
                                                                                             
#define MAC0STA_HOVF__BMASK      0x08 ///< Hard Overflow Flag                                
#define MAC0STA_HOVF__SHIFT      0x03 ///< Hard Overflow Flag                                
#define MAC0STA_HOVF__NOT_SET    0x00 ///< A hardware overflow did not occur.                
#define MAC0STA_HOVF__SET        0x08 ///< A hardware overflow occurred.                     
                                                                                             
#define MAC0STA_ACCRDY__BMASK    0x10 ///< ACC Ready Status Flag                             
#define MAC0STA_ACCRDY__SHIFT    0x04 ///< ACC Ready Status Flag                             
#define MAC0STA_ACCRDY__NOT_SET  0x00 ///< A MAC operation did not complete.                 
#define MAC0STA_ACCRDY__SET      0x10 ///< A MAC operation completed.                        
                                                                                             
#define MAC0STA_SCHANGE__BMASK   0x20 ///< Sign Change Event                                 
#define MAC0STA_SCHANGE__SHIFT   0x05 ///< Sign Change Event                                 
#define MAC0STA_SCHANGE__NOT_SET 0x00 ///< The accumulator result matches the expected sign  
                                      ///< (SIGNEXP) bit.                                    
#define MAC0STA_SCHANGE__SET     0x20 ///< The accumulator result does not match the expected
                                      ///< sign (SIGNEXP) bit.                               
                                                                                             
#define MAC0STA_MACINT__BMASK    0x40 ///< Interrupt Flag                                    
#define MAC0STA_MACINT__SHIFT    0x06 ///< Interrupt Flag                                    
#define MAC0STA_MACINT__NOT_SET  0x00 ///< An interrupt did not occur.                       
#define MAC0STA_MACINT__SET      0x40 ///< An interrupt occurred and is pending.             
                                                                                             
//------------------------------------------------------------------------------
// XBR0 Enums (Port I/O Crossbar 0 @ 0x95)
//------------------------------------------------------------------------------
#define XBR0_URT0E__BMASK           0x01 ///< UART I/O Output Enable                     
#define XBR0_URT0E__SHIFT           0x00 ///< UART I/O Output Enable                     
#define XBR0_URT0E__DISABLED        0x00 ///< UART I/O unavailable at Port pin.          
#define XBR0_URT0E__ENABLED         0x01 ///< UART TX, RX routed to Port pins.           
                                                                                         
#define XBR0_SPI0E__BMASK           0x02 ///< SPI I/O Enable                             
#define XBR0_SPI0E__SHIFT           0x01 ///< SPI I/O Enable                             
#define XBR0_SPI0E__DISABLED        0x00 ///< SPI I/O unavailable at Port pins.          
#define XBR0_SPI0E__ENABLED         0x02 ///< SPI I/O routed to Port pins. The SPI can be
                                         ///< assigned either 3 or 4 GPIO pins.          
                                                                                         
#define XBR0_SMB0E__BMASK           0x04 ///< SMBus0 I/O Enable                          
#define XBR0_SMB0E__SHIFT           0x02 ///< SMBus0 I/O Enable                          
#define XBR0_SMB0E__DISABLED        0x00 ///< SMBus0 I/O unavailable at Port pins.       
#define XBR0_SMB0E__ENABLED         0x04 ///< SMBus0 I/O routed to Port pins.            
                                                                                         
#define XBR0_SYSCKE__BMASK          0x08 ///< SYSCLK Output Enable                       
#define XBR0_SYSCKE__SHIFT          0x03 ///< SYSCLK Output Enable                       
#define XBR0_SYSCKE__DISABLED       0x00 ///< SYSCLK unavailable at Port pin.            
#define XBR0_SYSCKE__ENABLED        0x08 ///< SYSCLK output routed to Port pin.          
                                                                                         
#define XBR0_PCA0ME__FMASK          0x70 ///< PCA Module I/O Enable                      
#define XBR0_PCA0ME__SHIFT          0x04 ///< PCA Module I/O Enable                      
#define XBR0_PCA0ME__DISABLED       0x00 ///< All PCA I/O unavailable at Port pins.      
#define XBR0_PCA0ME__CEX0           0x10 ///< CEX0 routed to Port pin.                   
#define XBR0_PCA0ME__CEX0_CEX1      0x20 ///< CEX0, CEX1 routed to Port pins.            
#define XBR0_PCA0ME__CEX0_CEX1_CEX2 0x30 ///< CEX0, CEX1, CEX2 routed to Port pins.      
                                                                                         
#define XBR0_ECIE__BMASK            0x80 ///< PCA0 External Counter Input Enable         
#define XBR0_ECIE__SHIFT            0x07 ///< PCA0 External Counter Input Enable         
#define XBR0_ECIE__DISABLED         0x00 ///< ECI unavailable at Port pin.               
#define XBR0_ECIE__ENABLED          0x80 ///< ECI routed to Port pin.                    
                                                                                         
//------------------------------------------------------------------------------
// XBR1 Enums (Port I/O Crossbar 1 @ 0x96)
//------------------------------------------------------------------------------
#define XBR1_T0E__BMASK                 0x01 ///< T0 Enable                                       
#define XBR1_T0E__SHIFT                 0x00 ///< T0 Enable                                       
#define XBR1_T0E__DISABLED              0x00 ///< T0 unavailable at Port pin.                     
#define XBR1_T0E__ENABLED               0x01 ///< T0 routed to Port pin.                          
                                                                                                  
#define XBR1_T1E__BMASK                 0x02 ///< T1 Enable                                       
#define XBR1_T1E__SHIFT                 0x01 ///< T1 Enable                                       
#define XBR1_T1E__DISABLED              0x00 ///< T1 unavailable at Port pin.                     
#define XBR1_T1E__ENABLED               0x02 ///< T1 routed to Port pin.                          
                                                                                                  
#define XBR1_XBARE__BMASK               0x40 ///< Crossbar Enable                                 
#define XBR1_XBARE__SHIFT               0x06 ///< Crossbar Enable                                 
#define XBR1_XBARE__DISABLED            0x00 ///< Crossbar disabled.                              
#define XBR1_XBARE__ENABLED             0x40 ///< Crossbar enabled.                               
                                                                                                  
#define XBR1_WEAKPUD__BMASK             0x80 ///< Port I/O Weak Pullup Disable                    
#define XBR1_WEAKPUD__SHIFT             0x07 ///< Port I/O Weak Pullup Disable                    
#define XBR1_WEAKPUD__PULL_UPS_ENABLED  0x00 ///< Weak Pullups enabled (except for Ports whose I/O
                                             ///< are configured for analog mode).                
#define XBR1_WEAKPUD__PULL_UPS_DISABLED 0x80 ///< Weak Pullups disabled.                          
                                                                                                  
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
#define PCA0MD_WDTE__ENABLED         0x40 ///< Enable PCA Module 2 as the Watchdog Timer.        
                                                                                                 
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
// PMU0FL Enums (Power Management Unit Flag @ 0xCE)
//------------------------------------------------------------------------------
#define PMU0FL_CS0WK__BMASK   0x01 ///< CS0 Wake-up Source Enable and Flag              
#define PMU0FL_CS0WK__SHIFT   0x00 ///< CS0 Wake-up Source Enable and Flag              
#define PMU0FL_CS0WK__NOT_SET 0x00 ///< A Capacitive Sensing  comparator threshold event
                                   ///< did not cause the last wake-up.                 
#define PMU0FL_CS0WK__SET     0x01 ///< A Capacitive Sensing  comparator threshold event
                                   ///< caused the last wake-up.                        
                                                                                        
#define PMU0FL_I2CWK__BMASK   0x02 ///< I2C0 Slave Wake-up Source Enable and Flag       
#define PMU0FL_I2CWK__SHIFT   0x01 ///< I2C0 Slave Wake-up Source Enable and Flag       
#define PMU0FL_I2CWK__NOT_SET 0x00 ///< An I2C0 Slave event did not cause the last wake-
                                   ///< up.                                             
#define PMU0FL_I2CWK__SET     0x02 ///< An I2C0 Slave event caused the last wake-up.    
                                                                                        
//------------------------------------------------------------------------------
// PMU0MD Enums (Power Management Unit Mode @ 0xCF)
//------------------------------------------------------------------------------
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
// P0DRV Enums (Port 0 Drive Strength @ 0x99)
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
// P0MASK Enums (Port 0 Mask @ 0x8B)
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
// P0MAT Enums (Port 0 Match @ 0xF4)
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
// P0MDIN Enums (Port 0 Input Mode @ 0xEC)
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
// P0MDOUT Enums (Port 0 Output Mode @ 0xD9)
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
// P0SKIP Enums (Port 0 Skip @ 0xB6)
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
// P1DRV Enums (Port 1 Drive Strength @ 0x9A)
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
// P1MASK Enums (Port 1 Mask @ 0x8C)
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
// P1MAT Enums (Port 1 Match @ 0xF5)
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
// P1MDIN Enums (Port 1 Input Mode @ 0xED)
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
// P1MDOUT Enums (Port 1 Output Mode @ 0xDC)
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
// P1SKIP Enums (Port 1 Skip @ 0xC6)
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
// P2DRV Enums (Port 2 Drive Strength @ 0x9B)
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
// P2MASK Enums (Port 2 Mask @ 0x84)
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
// P2MAT Enums (Port 2 Match @ 0x85)
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
// P2MDIN Enums (Port 2 Input Mode @ 0xEE)
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
// P2MDOUT Enums (Port 2 Output Mode @ 0xDD)
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
// P2SKIP Enums (Port 2 Skip @ 0xC7)
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
// P3 Enums (Port 3 Pin Latch @ 0xE1)
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
// P3DRV Enums (Port 3 Drive Strength @ 0x9C)
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
// P3MDIN Enums (Port 3 Input Mode @ 0xEF)
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
// P3MDOUT Enums (Port 3 Output Mode @ 0xDF)
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
// P4 Enums (Port 4 Pin Latch @ 0xE2)
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
// P4DRV Enums (Port 4 Drive Strength @ 0xB9)
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
// P4MDIN Enums (Port 4 Input Mode @ 0xF1)
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
// P4MDOUT Enums (Port 4 Output Mode @ 0xC3)
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
// P5 Enums (Port 5 Pin Latch @ 0xE3)
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
                                                                             
//------------------------------------------------------------------------------
// P5DRV Enums (Port 5 Drive Strength @ 0x9D)
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
                                                                                  
//------------------------------------------------------------------------------
// P5MDIN Enums (Port 5 Input Mode @ 0xF2)
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
                                                                             
//------------------------------------------------------------------------------
// P5MDOUT Enums (Port 5 Output Mode @ 0xFF)
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
                                                                   
//------------------------------------------------------------------------------
// P6 Enums (Port 6 Pin Latch @ 0xE4)
//------------------------------------------------------------------------------
#define P6_B0__BMASK 0x01 ///< Port 6 Bit 0 Latch                            
#define P6_B0__SHIFT 0x00 ///< Port 6 Bit 0 Latch                            
#define P6_B0__LOW   0x00 ///< P6.0 is low. Set P6.0 to drive low.           
#define P6_B0__HIGH  0x01 ///< P6.0 is high. Set P6.0 to drive or float high.
                                                                             
#define P6_B1__BMASK 0x02 ///< Port 6 Bit 1 Latch                            
#define P6_B1__SHIFT 0x01 ///< Port 6 Bit 1 Latch                            
#define P6_B1__LOW   0x00 ///< P6.1 is low. Set P6.1 to drive low.           
#define P6_B1__HIGH  0x02 ///< P6.1 is high. Set P6.1 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P6MDIN Enums (Port 6 Input Mode @ 0x97)
//------------------------------------------------------------------------------
#define P6MDIN_B0__BMASK   0x01 ///< Port 6 Bit 0 Input Mode                 
#define P6MDIN_B0__SHIFT   0x00 ///< Port 6 Bit 0 Input Mode                 
#define P6MDIN_B0__ANALOG  0x00 ///< P6.0 pin is configured for analog mode. 
#define P6MDIN_B0__DIGITAL 0x01 ///< P6.0 pin is configured for digital mode.
                                                                             
#define P6MDIN_B1__BMASK   0x02 ///< Port 6 Bit 1 Input Mode                 
#define P6MDIN_B1__SHIFT   0x01 ///< Port 6 Bit 1 Input Mode                 
#define P6MDIN_B1__ANALOG  0x00 ///< P6.1 pin is configured for analog mode. 
#define P6MDIN_B1__DIGITAL 0x02 ///< P6.1 pin is configured for digital mode.
                                                                             
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
// ALARM0 Enums (RTC Alarm Programmed Value 0 @ 0x08)
//------------------------------------------------------------------------------
#define ALARM0_ALARM0__FMASK 0xFF ///< RTC Alarm Programmed Value 0
#define ALARM0_ALARM0__SHIFT 0x00 ///< RTC Alarm Programmed Value 0
                                                                   
//------------------------------------------------------------------------------
// ALARM1 Enums (RTC Alarm Programmed Value 1 @ 0x09)
//------------------------------------------------------------------------------
#define ALARM1_ALARM1__FMASK 0xFF ///< RTC Alarm Programmed Value 1
#define ALARM1_ALARM1__SHIFT 0x00 ///< RTC Alarm Programmed Value 1
                                                                   
//------------------------------------------------------------------------------
// ALARM2 Enums (RTC Alarm Programmed Value 2 @ 0x0A)
//------------------------------------------------------------------------------
#define ALARM2_ALARM2__FMASK 0xFF ///< RTC Alarm Programmed Value 2
#define ALARM2_ALARM2__SHIFT 0x00 ///< RTC Alarm Programmed Value 2
                                                                   
//------------------------------------------------------------------------------
// ALARM3 Enums (RTC Alarm Programmed Value 3 @ 0x0B)
//------------------------------------------------------------------------------
#define ALARM3_ALARM3__FMASK 0xFF ///< RTC Alarm Programmed Value 3
#define ALARM3_ALARM3__SHIFT 0x00 ///< RTC Alarm Programmed Value 3
                                                                   
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
#define RTC0ADR_ADDR__FMASK      0x0F ///< RTC Indirect Register Address                     
#define RTC0ADR_ADDR__SHIFT      0x00 ///< RTC Indirect Register Address                     
#define RTC0ADR_ADDR__CAPTURE0   0x00 ///< Select the CAPTURE0 register.                     
#define RTC0ADR_ADDR__CAPTURE1   0x01 ///< Select the CAPTURE1 register.                     
#define RTC0ADR_ADDR__CAPTURE2   0x02 ///< Select the CAPTURE2 register.                     
#define RTC0ADR_ADDR__CAPTURE3   0x03 ///< Select the CAPTURE3 register.                     
#define RTC0ADR_ADDR__RTC0CN     0x04 ///< Select the RTC0CN register.                       
#define RTC0ADR_ADDR__RTC0XCN    0x05 ///< Select the RTC0XCN register.                      
#define RTC0ADR_ADDR__RTC0XCF    0x06 ///< Select the RTC0XCF register.                      
#define RTC0ADR_ADDR__ALARM0     0x08 ///< Select the ALARM0 register.                       
#define RTC0ADR_ADDR__ALARM1     0x09 ///< Select the ALARM1 register.                       
#define RTC0ADR_ADDR__ALARM2     0x0A ///< Select the ALARM2 register.                       
#define RTC0ADR_ADDR__ALARM3     0x0B ///< Select the ALARM3 register.                       
                                                                                             
#define RTC0ADR_SHORT__BMASK     0x10 ///< Short Strobe Enable                               
#define RTC0ADR_SHORT__SHIFT     0x04 ///< Short Strobe Enable                               
#define RTC0ADR_SHORT__DISABLED  0x00 ///< Disable short strobe.                             
#define RTC0ADR_SHORT__ENABLED   0x10 ///< Enable short strobe.                              
                                                                                             
#define RTC0ADR_AUTORD__BMASK    0x40 ///< RTC Interface Autoread Enable                     
#define RTC0ADR_AUTORD__SHIFT    0x06 ///< RTC Interface Autoread Enable                     
#define RTC0ADR_AUTORD__DISABLED 0x00 ///< Disable autoread. Firmware must write the BUSY bit
                                      ///< for each RTC indirect read operation.             
#define RTC0ADR_AUTORD__ENABLED  0x40 ///< Enable autoread. The next RTC indirect read       
                                      ///< operation is initiated when firmware reads the    
                                      ///< RTC0DAT register.                                 
                                                                                             
#define RTC0ADR_BUSY__BMASK      0x80 ///< RTC Interface Busy Indicator                      
#define RTC0ADR_BUSY__SHIFT      0x07 ///< RTC Interface Busy Indicator                      
#define RTC0ADR_BUSY__NOT_SET    0x00 ///< The RTC interface is not busy.                    
#define RTC0ADR_BUSY__SET        0x80 ///< The RTC interface is busy.                        
                                                                                             
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
                                                                                           
#define RTC0CN_ALRM__BMASK       0x04 ///< RTC Alarm Event Flag and Auto Reset Enable      
#define RTC0CN_ALRM__SHIFT       0x02 ///< RTC Alarm Event Flag and Auto Reset Enable      
#define RTC0CN_ALRM__NOT_SET     0x00 ///< Alarm event flag is not set or disable the auto 
                                      ///< reset function.                                 
#define RTC0CN_ALRM__SET         0x04 ///< Alarm event flag is set or enable the auto reset
                                      ///< function.                                       
                                                                                           
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
// TOFFH Enums (Temperature Sensor Offset High @ 0x8E)
//------------------------------------------------------------------------------
#define TOFFH_TOFF__FMASK 0xFF ///< Temperature Sensor Offset High
#define TOFFH_TOFF__SHIFT 0x00 ///< Temperature Sensor Offset High
                                                                  
//------------------------------------------------------------------------------
// TOFFL Enums (Temperature Sensor Offset Low @ 0x8D)
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
#define TMR2CN_T2XCLK__FMASK                 0x03 ///< Timer 2 External Clock Select                    
#define TMR2CN_T2XCLK__SHIFT                 0x00 ///< Timer 2 External Clock Select                    
#define TMR2CN_T2XCLK__SYSCLK_DIV_12_CAP_RTC 0x00 ///< External Clock is SYSCLK/12. Capture trigger is  
                                                  ///< RTC/8.                                           
#define TMR2CN_T2XCLK__CAP_RTC               0x01 ///< Capture trigger is RTC/8.                        
#define TMR2CN_T2XCLK__SYSCLK_DIV_12         0x02 ///< External Clock is SYSCLK/12.                     
#define TMR2CN_T2XCLK__RTC_DIV_8             0x03 ///< External Clock is RTC/8.                         
                                                                                                        
#define TMR2CN_TR2__BMASK                    0x04 ///< Timer 2 Run Control                              
#define TMR2CN_TR2__SHIFT                    0x02 ///< Timer 2 Run Control                              
#define TMR2CN_TR2__STOP                     0x00 ///< Stop Timer 2.                                    
#define TMR2CN_TR2__RUN                      0x04 ///< Start Timer 2 running.                           
                                                                                                        
#define TMR2CN_T2SPLIT__BMASK                0x08 ///< Timer 2 Split Mode Enable                        
#define TMR2CN_T2SPLIT__SHIFT                0x03 ///< Timer 2 Split Mode Enable                        
#define TMR2CN_T2SPLIT__16_BIT_RELOAD        0x00 ///< Timer 2 operates in 16-bit auto-reload mode.     
#define TMR2CN_T2SPLIT__8_BIT_RELOAD         0x08 ///< Timer 2 operates as two 8-bit auto-reload timers.
                                                                                                        
#define TMR2CN_TF2CEN__BMASK                 0x10 ///< Timer 2 Capture Enable                           
#define TMR2CN_TF2CEN__SHIFT                 0x04 ///< Timer 2 Capture Enable                           
#define TMR2CN_TF2CEN__DISABLED              0x00 ///< Disable capture mode.                            
#define TMR2CN_TF2CEN__ENABLED               0x10 ///< Enable capture mode.                             
                                                                                                        
#define TMR2CN_TF2LEN__BMASK                 0x20 ///< Timer 2 Low Byte Interrupt Enable                
#define TMR2CN_TF2LEN__SHIFT                 0x05 ///< Timer 2 Low Byte Interrupt Enable                
#define TMR2CN_TF2LEN__DISABLED              0x00 ///< Disable low byte interrupts.                     
#define TMR2CN_TF2LEN__ENABLED               0x20 ///< Enable low byte interrupts.                      
                                                                                                        
#define TMR2CN_TF2L__BMASK                   0x40 ///< Timer 2 Low Byte Overflow Flag                   
#define TMR2CN_TF2L__SHIFT                   0x06 ///< Timer 2 Low Byte Overflow Flag                   
#define TMR2CN_TF2L__NOT_SET                 0x00 ///< Timer 2 low byte did not overflow.               
#define TMR2CN_TF2L__SET                     0x40 ///< Timer 2 low byte overflowed.                     
                                                                                                        
#define TMR2CN_TF2H__BMASK                   0x80 ///< Timer 2 High Byte Overflow Flag                  
#define TMR2CN_TF2H__SHIFT                   0x07 ///< Timer 2 High Byte Overflow Flag                  
#define TMR2CN_TF2H__NOT_SET                 0x00 ///< Timer 2 8-bit high byte or 16-bit value did not  
                                                  ///< overflow.                                        
#define TMR2CN_TF2H__SET                     0x80 ///< Timer 2 8-bit high byte or 16-bit value          
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
#define VDM0CN_VDDOKIE__BMASK           0x08 ///< VDD Early Warning Interrupt Enable       
#define VDM0CN_VDDOKIE__SHIFT           0x03 ///< VDD Early Warning Interrupt Enable       
#define VDM0CN_VDDOKIE__DISABLED        0x00 ///< Disable the VDD Early Warning interrupt. 
#define VDM0CN_VDDOKIE__ENABLED         0x08 ///< Enable the VDD Early Warning interrupt.  
                                                                                           
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
// EMI0CN Enums (External Memory Interface Control @ 0xB9)
//------------------------------------------------------------------------------
#define EMI0CN_PGSEL__FMASK 0xFF ///< XRAM Page Select
#define EMI0CN_PGSEL__SHIFT 0x00 ///< XRAM Page Select
                                                      
#endif // SI_C8051F970_REGISTER_ENUMS_H
//-eof--------------------------------------------------------------------------

