//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  C8051F700_GQ
//  C8051F701_GQ
//  C8051F702_GQ
//  C8051F703_GQ
//  C8051F704_GM
//  C8051F704_GQ
//  C8051F705_GM
//  C8051F705_GQ
//  C8051F706_GM
//  C8051F706_GQ
//  C8051F707_GM
//  C8051F707_GQ
//  C8051F708_GQ
//  C8051F709_GQ
//  C8051F710_GQ
//  C8051F711_GQ
//  C8051F712_GM
//  C8051F712_GQ
//  C8051F713_GM
//  C8051F713_GQ
//  C8051F714_GM
//  C8051F714_GQ
//  C8051F715_GM
//  C8051F715_GQ
//  C8051F716_GM
//  C8051F717_GM

#ifndef SI_C8051F700_REGISTER_ENUMS_H
#define SI_C8051F700_REGISTER_ENUMS_H

//Standard device includes
#include "SI_C8051F700_Defs.h"
//------------------------------------------------------------------------------
// ADC0CF Enums (ADC0 Configuration @ 0xBC)
//------------------------------------------------------------------------------
#define ADC0CF_AMP0GN__BMASK           0x01 ///< Gain Control                                    
#define ADC0CF_AMP0GN__SHIFT           0x00 ///< Gain Control                                    
#define ADC0CF_AMP0GN__GAIN_0P5        0x00 ///< The on-chip PGA gain is 0.5.                    
#define ADC0CF_AMP0GN__GAIN_1          0x01 ///< The on-chip PGA gain is 1.                      
                                                                                                 
#define ADC0CF_AD8BE__BMASK            0x02 ///< 8-Bit Mode Enable                               
#define ADC0CF_AD8BE__SHIFT            0x01 ///< 8-Bit Mode Enable                               
#define ADC0CF_AD8BE__NORMAL           0x00 ///< ADC0 operates in 10-bit mode (normal operation).
#define ADC0CF_AD8BE__8_BIT            0x02 ///< ADC0 operates in 8-bit mode.                    
                                                                                                 
#define ADC0CF_ADLJST__BMASK           0x04 ///< ADC0 Left Justify Select                        
#define ADC0CF_ADLJST__SHIFT           0x02 ///< ADC0 Left Justify Select                        
#define ADC0CF_ADLJST__RIGHT_JUSTIFIED 0x00 ///< Data in the ADC0H:ADC0L registers is right-     
                                            ///< justified.                                      
#define ADC0CF_ADLJST__LEFT_JUSTIFIED  0x04 ///< Data in the ADC0H:ADC0L registers is left-      
                                            ///< justified.                                      
                                                                                                 
#define ADC0CF_ADSC__FMASK             0xF8 ///< SAR Clock Divider                               
#define ADC0CF_ADSC__SHIFT             0x03 ///< SAR Clock Divider                               
                                                                                                 
//------------------------------------------------------------------------------
// ADC0CN Enums (ADC0 Control @ 0xE8)
//------------------------------------------------------------------------------
#define ADC0CN_ADCM__FMASK         0x07 ///< Start of Conversion Mode Select                   
#define ADC0CN_ADCM__SHIFT         0x00 ///< Start of Conversion Mode Select                   
#define ADC0CN_ADCM__ADBUSY        0x00 ///< ADC0 conversion initiated on write of 1 to ADBUSY.
#define ADC0CN_ADCM__TIMER0        0x01 ///< ADC0 conversion initiated on overflow of Timer 0. 
#define ADC0CN_ADCM__TIMER2        0x02 ///< ADC0 conversion initiated on overflow of Timer 2. 
#define ADC0CN_ADCM__TIMER1        0x03 ///< ADC0 conversion initiated on overflow of Timer 1. 
#define ADC0CN_ADCM__CNVSTR        0x04 ///< ADC0 conversion initiated on rising edge of       
                                        ///< CNVSTR.                                           
#define ADC0CN_ADCM__TIMER3        0x05 ///< ADC0 conversion initiated on overflow of Timer 3. 
                                                                                               
#define ADC0CN_ADWINT__BMASK       0x08 ///< Window Compare Interrupt Flag                     
#define ADC0CN_ADWINT__SHIFT       0x03 ///< Window Compare Interrupt Flag                     
#define ADC0CN_ADWINT__NOT_SET     0x00 ///< An ADC window compare event did not occur.        
#define ADC0CN_ADWINT__SET         0x08 ///< An ADC window compare event occurred.             
                                                                                               
#define ADC0CN_ADBUSY__BMASK       0x10 ///< ADC Busy                                          
#define ADC0CN_ADBUSY__SHIFT       0x04 ///< ADC Busy                                          
#define ADC0CN_ADBUSY__NOT_SET     0x00 ///< An ADC0 conversion is not currently in progress.  
#define ADC0CN_ADBUSY__SET         0x10 ///< ADC0 conversion is in progress or start an ADC0   
                                        ///< conversion.                                       
                                                                                               
#define ADC0CN_ADINT__BMASK        0x20 ///< Conversion Complete Interrupt Flag                
#define ADC0CN_ADINT__SHIFT        0x05 ///< Conversion Complete Interrupt Flag                
#define ADC0CN_ADINT__NOT_SET      0x00 ///< ADC0 has not completed a conversion since the last
                                        ///< time ADINT was cleared.                           
#define ADC0CN_ADINT__SET          0x20 ///< ADC0 completed a data conversion.                 
                                                                                               
#define ADC0CN_ADTM__BMASK         0x40 ///< Track Mode                                        
#define ADC0CN_ADTM__SHIFT         0x06 ///< Track Mode                                        
#define ADC0CN_ADTM__TRACK_NORMAL  0x00 ///< Normal Track Mode. When ADC0 is enabled,          
                                        ///< conversion begins immediately following the start-
                                        ///< of-conversion signal.                             
#define ADC0CN_ADTM__TRACK_DELAYED 0x40 ///< Delayed Track Mode. When ADC0 is enabled,         
                                        ///< conversion begins 3 SAR clock cycles following the
                                        ///< start-of-conversion signal. The ADC is allowed to 
                                        ///< track during this time. Note that there is not a  
                                        ///< tracking delay when the external conversion start 
                                        ///< (CNVSTR) is used as the start-of-conversion       
                                        ///< source.                                           
                                                                                               
#define ADC0CN_ADEN__BMASK         0x80 ///< ADC Enable                                        
#define ADC0CN_ADEN__SHIFT         0x07 ///< ADC Enable                                        
#define ADC0CN_ADEN__DISABLED      0x00 ///< ADC0 Disabled (low-power shutdown).               
#define ADC0CN_ADEN__ENABLED       0x80 ///< ADC0 Enabled (active and ready for data           
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
#define ADC0MX_ADC0MX__ADC0P0  0x00 ///< Select ADC0P.0.               
#define ADC0MX_ADC0MX__ADC0P1  0x01 ///< Select ADC0P.1.               
#define ADC0MX_ADC0MX__ADC0P2  0x02 ///< Select ADC0P.2.               
#define ADC0MX_ADC0MX__ADC0P3  0x03 ///< Select ADC0P.3.               
#define ADC0MX_ADC0MX__ADC0P4  0x04 ///< Select ADC0P.4.               
#define ADC0MX_ADC0MX__ADC0P5  0x05 ///< Select ADC0P.5.               
#define ADC0MX_ADC0MX__ADC0P6  0x06 ///< Select ADC0P.6.               
#define ADC0MX_ADC0MX__ADC0P7  0x07 ///< Select ADC0P.7.               
#define ADC0MX_ADC0MX__ADC0P8  0x08 ///< Select ADC0P.8.               
#define ADC0MX_ADC0MX__ADC0P9  0x09 ///< Select ADC0P.9.               
#define ADC0MX_ADC0MX__ADC0P10 0x0A ///< Select ADC0P.10.              
#define ADC0MX_ADC0MX__ADC0P11 0x0B ///< Select ADC0P.11.              
#define ADC0MX_ADC0MX__ADC0P12 0x0C ///< Select ADC0P.12.              
#define ADC0MX_ADC0MX__ADC0P13 0x0D ///< Select ADC0P.13.              
#define ADC0MX_ADC0MX__ADC0P14 0x0E ///< Select ADC0P.14.              
#define ADC0MX_ADC0MX__ADC0P15 0x0F ///< Select ADC0P.15.              
#define ADC0MX_ADC0MX__TEMP    0x10 ///< Temperature sensor.           
#define ADC0MX_ADC0MX__LDO     0x11 ///< Internal LDO regulator output.
#define ADC0MX_ADC0MX__VDD     0x12 ///< VDD.                          
#define ADC0MX_ADC0MX__GND     0x13 ///< GND.                          
                                                                       
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
// SFRPAGE Enums (SFR Page @ 0xA7)
//------------------------------------------------------------------------------
#define SFRPAGE_SFRPAGE__FMASK 0xFF ///< SFR Page
#define SFRPAGE_SFRPAGE__SHIFT 0x00 ///< SFR Page
                                                 
//------------------------------------------------------------------------------
// SP Enums (Stack Pointer @ 0x81)
//------------------------------------------------------------------------------
#define SP_SP__FMASK 0xFF ///< Stack Pointer
#define SP_SP__SHIFT 0x00 ///< Stack Pointer
                                            
//------------------------------------------------------------------------------
// CLKSEL Enums (Clock Select @ 0xBD)
//------------------------------------------------------------------------------
#define CLKSEL_CLKSL__FMASK           0x07 ///< Clock Source Select                               
#define CLKSEL_CLKSL__SHIFT           0x00 ///< Clock Source Select                               
#define CLKSEL_CLKSL__HFOSC           0x00 ///< Clock derived from the internal precision High-   
                                           ///< Frequency Oscillator.                             
#define CLKSEL_CLKSL__EXTOSC          0x01 ///< Clock derived from the External Oscillator        
                                           ///< circuit.                                          
                                                                                                  
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
#define CPT0MX_CMXP__FMASK  0x07 ///< Comparator Positive Input MUX Selection
#define CPT0MX_CMXP__SHIFT  0x00 ///< Comparator Positive Input MUX Selection
#define CPT0MX_CMXP__CMP0P0 0x00 ///< External pin CMP0P.0.                  
#define CPT0MX_CMXP__CMP0P1 0x01 ///< External pin CMP0P.1.                  
#define CPT0MX_CMXP__CMP0P2 0x02 ///< External pin CMP0P.2.                  
#define CPT0MX_CMXP__CMP0P3 0x03 ///< External pin CMP0P.3.                  
#define CPT0MX_CMXP__NONE   0x0F ///< No input selected.                     
                                                                             
#define CPT0MX_CMXN__FMASK  0x70 ///< Comparator Negative Input MUX Selection
#define CPT0MX_CMXN__SHIFT  0x04 ///< Comparator Negative Input MUX Selection
#define CPT0MX_CMXN__CMP0N0 0x00 ///< External pin CMP0N.0.                  
#define CPT0MX_CMXN__CMP0N1 0x10 ///< External pin CMP0N.1.                  
#define CPT0MX_CMXN__CMP0N2 0x20 ///< External pin CMP0N.2.                  
#define CPT0MX_CMXN__CMP0N3 0x30 ///< External pin CMP0N.3.                  
#define CPT0MX_CMXN__NONE   0xF0 ///< No input selected.                     
                                                                             
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
// CRC0CN Enums (CRC0 Control @ 0x91)
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
// CRC0DAT Enums (CRC0 Data Output @ 0xD9)
//------------------------------------------------------------------------------
#define CRC0DAT_CRC0DAT__FMASK 0xFF ///< CRC Data Output
#define CRC0DAT_CRC0DAT__SHIFT 0x00 ///< CRC Data Output
                                                        
//------------------------------------------------------------------------------
// CRC0FLIP Enums (CRC0 Bit Flip @ 0x95)
//------------------------------------------------------------------------------
#define CRC0FLIP_CRC0FLIP__FMASK 0xFF ///< CRC0 Bit Flip
#define CRC0FLIP_CRC0FLIP__SHIFT 0x00 ///< CRC0 Bit Flip
                                                        
//------------------------------------------------------------------------------
// CRC0IN Enums (CRC0 Data Input @ 0x94)
//------------------------------------------------------------------------------
#define CRC0IN_CRC0IN__FMASK 0xFF ///< CRC Data Input
#define CRC0IN_CRC0IN__SHIFT 0x00 ///< CRC Data Input
                                                     
//------------------------------------------------------------------------------
// CS0CF Enums (Capacitive Sense 0 Configuration @ 0x9E)
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
#define CS0CF_CS0MCEN__MULT_CHAN_ENABLED  0x08 ///< Channels selected by CS0SCAN0/1 are internally    
                                               ///< shorted together and the combined node is selected
                                               ///< as the CS0 input. This mode can be used to detect 
                                               ///< a capacitance change on multiple channels using a 
                                               ///< single conversion.                                
                                                                                                      
#define CS0CF_CS0CM__FMASK                0x70 ///< CS0 Start of Conversion Mode Select               
#define CS0CF_CS0CM__SHIFT                0x04 ///< CS0 Start of Conversion Mode Select               
#define CS0CF_CS0CM__CS0BUSY              0x00 ///< Conversion initiated on every write of 1 to       
                                               ///< CS0BUSY.                                          
#define CS0CF_CS0CM__TIMER0               0x10 ///< Conversion initiated on overflow of Timer 0.      
#define CS0CF_CS0CM__TIMER2               0x20 ///< Conversion initiated on overflow of Timer 2.      
#define CS0CF_CS0CM__TIMER1               0x30 ///< Conversion initiated on overflow of Timer 1.      
#define CS0CF_CS0CM__SINGLE_CONTINUOUS    0x60 ///< Conversion initiated continuously on the channel  
                                               ///< selected by CS0MX after writing 1 to CS0BUSY.     
#define CS0CF_CS0CM__AUTO_SCAN            0x70 ///< The converter enters Auto Scan Mode and           
                                               ///< continuously scans on channels from CS0SS to CS0SE
                                               ///< after firmware writes 1 to CS0BUSY.               
                                                                                                      
#define CS0CF_CS0SMEN__BMASK              0x80 ///< CS0 Channel Scan Masking Enable                   
#define CS0CF_CS0SMEN__SHIFT              0x07 ///< CS0 Channel Scan Masking Enable                   
#define CS0CF_CS0SMEN__SCAN_MASK_DISABLED 0x00 ///< The CS0SCAN0 and CS0SCAN1 register contents are   
                                               ///< ignored.                                          
#define CS0CF_CS0SMEN__SCAN_MASK_ENABLED  0x80 ///< The CS0SCAN0 and CS0SCAN1 registers determine     
                                               ///< which channels will be included in the scan.      
                                                                                                      
//------------------------------------------------------------------------------
// CS0CN Enums (Capacitive Sense 0 Control @ 0x9A)
//------------------------------------------------------------------------------
#define CS0CN_CSCMPF__BMASK     0x01 ///< CS0 Digital Comparator Interrupt Flag             
#define CS0CN_CSCMPF__SHIFT     0x00 ///< CS0 Digital Comparator Interrupt Flag             
#define CS0CN_CSCMPF__NOT_SET   0x00 ///< CS0 result is smaller than the value set by CS0THH
                                     ///< and CS0THL since the last time CS0CMPF was        
                                     ///< cleared.                                          
#define CS0CN_CSCMPF__SET       0x01 ///< CS0 result is greater than the value set by CS0THH
                                     ///< and CS0THL since the last time CS0CMPF was        
                                     ///< cleared.                                          
                                                                                            
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
                                                                                            
#define CS0CN_CSPME__BMASK      0x40 ///< CS0 Pin Monitor Event                             
#define CS0CN_CSPME__SHIFT      0x06 ///< CS0 Pin Monitor Event                             
#define CS0CN_CSPME__NO_RETRIES 0x00 ///< Converter re-tries have not occurred.             
#define CS0CN_CSPME__RETRIES    0x40 ///< Converter re-tries occurred.                      
                                                                                            
#define CS0CN_CSEN__BMASK       0x80 ///< CS0 Enable                                        
#define CS0CN_CSEN__SHIFT       0x07 ///< CS0 Enable                                        
#define CS0CN_CSEN__DISABLED    0x00 ///< CS0 disabled and in low-power mode.               
#define CS0CN_CSEN__ENABLED     0x80 ///< CS0 enabled and ready to convert.                 
                                                                                            
//------------------------------------------------------------------------------
// CS0DH Enums (Capacitive Sense 0 Data High Byte @ 0xAA)
//------------------------------------------------------------------------------
#define CS0DH_CS0DH__FMASK 0xFF ///< CS0 Data High Byte
#define CS0DH_CS0DH__SHIFT 0x00 ///< CS0 Data High Byte
                                                       
//------------------------------------------------------------------------------
// CS0DL Enums (Capacitive Sense 0 Data Low Byte @ 0xA9)
//------------------------------------------------------------------------------
#define CS0DL_CS0DL__FMASK 0xFF ///< CS0 Data Low Byte
#define CS0DL_CS0DL__SHIFT 0x00 ///< CS0 Data Low Byte
                                                      
//------------------------------------------------------------------------------
// CS0MD1 Enums (Capacitive Sense 0 Mode 1 @ 0xAD)
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
// CS0MX Enums (Capacitive Sense 0 Mux Channel Select @ 0x9C)
//------------------------------------------------------------------------------
#define CS0MX_CS0MX__FMASK        0x3F ///< CS0 Mux Channel Select                 
#define CS0MX_CS0MX__SHIFT        0x00 ///< CS0 Mux Channel Select                 
#define CS0MX_CS0MX__CS0P0        0x00 ///< Select CS0.0.                          
#define CS0MX_CS0MX__CS0P1        0x01 ///< Select CS0.1.                          
#define CS0MX_CS0MX__CS0P2        0x02 ///< Select CS0.2.                          
#define CS0MX_CS0MX__CS0P3        0x03 ///< Select CS0.3.                          
#define CS0MX_CS0MX__CS0P4        0x04 ///< Select CS0.4.                          
#define CS0MX_CS0MX__CS0P5        0x05 ///< Select CS0.5.                          
#define CS0MX_CS0MX__CS0P6        0x06 ///< Select CS0.6.                          
#define CS0MX_CS0MX__CS0P7        0x07 ///< Select CS0.7.                          
#define CS0MX_CS0MX__CS0P8        0x08 ///< Select CS0.8.                          
#define CS0MX_CS0MX__CS0P9        0x09 ///< Select CS0.9.                          
#define CS0MX_CS0MX__CS0P10       0x0A ///< Select CS0.10.                         
#define CS0MX_CS0MX__CS0P11       0x0B ///< Select CS0.11.                         
#define CS0MX_CS0MX__CS0P12       0x0C ///< Select CS0.12.                         
#define CS0MX_CS0MX__CS0P13       0x0D ///< Select CS0.13.                         
#define CS0MX_CS0MX__CS0P14       0x0E ///< Select CS0.14.                         
#define CS0MX_CS0MX__CS0P15       0x0F ///< Select CS0.15.                         
#define CS0MX_CS0MX__CS0P16       0x10 ///< Select CS0.16.                         
#define CS0MX_CS0MX__CS0P17       0x11 ///< Select CS0.17.                         
#define CS0MX_CS0MX__CS0P18       0x12 ///< Select CS0.18.                         
#define CS0MX_CS0MX__CS0P19       0x13 ///< Select CS0.19.                         
#define CS0MX_CS0MX__CS0P20       0x14 ///< Select CS0.20.                         
#define CS0MX_CS0MX__CS0P21       0x15 ///< Select CS0.21.                         
#define CS0MX_CS0MX__CS0P22       0x16 ///< Select CS0.22.                         
#define CS0MX_CS0MX__CS0P23       0x17 ///< Select CS0.23.                         
#define CS0MX_CS0MX__CS0P24       0x18 ///< Select CS0.24.                         
#define CS0MX_CS0MX__CS0P25       0x19 ///< Select CS0.25.                         
#define CS0MX_CS0MX__CS0P26       0x1A ///< Select CS0.26.                         
#define CS0MX_CS0MX__CS0P27       0x1B ///< Select CS0.27.                         
#define CS0MX_CS0MX__CS0P28       0x1C ///< Select CS0.28.                         
#define CS0MX_CS0MX__CS0P29       0x1D ///< Select CS0.29.                         
#define CS0MX_CS0MX__CS0P30       0x1E ///< Select CS0.30.                         
#define CS0MX_CS0MX__CS0P31       0x1F ///< Select CS0.31.                         
#define CS0MX_CS0MX__CS0P32       0x20 ///< Select CS0.32.                         
#define CS0MX_CS0MX__CS0P33       0x21 ///< Select CS0.33.                         
#define CS0MX_CS0MX__CS0P34       0x22 ///< Select CS0.34.                         
#define CS0MX_CS0MX__CS0P35       0x23 ///< Select CS0.35.                         
#define CS0MX_CS0MX__CS0P36       0x24 ///< Select CS0.36.                         
#define CS0MX_CS0MX__CS0P37       0x25 ///< Select CS0.37.                         
                                                                                   
#define CS0MX_CS0UC__BMASK        0x80 ///< CS0 Unconnected                        
#define CS0MX_CS0UC__SHIFT        0x07 ///< CS0 Unconnected                        
#define CS0MX_CS0UC__CONNECTED    0x00 ///< CS0 is connected to the port pins.     
#define CS0MX_CS0UC__DISCONNECTED 0x80 ///< CS0 is disconnected from the port pins.
                                                                                   
//------------------------------------------------------------------------------
// CS0PM Enums (Capacitive Sense 0 Pin Monitor @ 0x9F)
//------------------------------------------------------------------------------
#define CS0PM_CSPMMD__FMASK                 0x03 ///< CS0 Pin Monitor Mode                             
#define CS0PM_CSPMMD__SHIFT                 0x00 ///< CS0 Pin Monitor Mode                             
#define CS0PM_CSPMMD__ALWAYS_RETRY          0x00 ///< Always retry bit cycles on a pin state change.   
#define CS0PM_CSPMMD__RETRY_TWO_TIMES       0x01 ///< Retry up to twice on consecutive bit cycles.     
#define CS0PM_CSPMMD__RETRY_FOUR_TIMES      0x02 ///< Retry up to four times on consecutive bit cycles.
                                                                                                       
#define CS0PM_CP0PM__BMASK                  0x04 ///< CP0 Pin Monitor Enable                           
#define CS0PM_CP0PM__SHIFT                  0x02 ///< CP0 Pin Monitor Enable                           
#define CS0PM_CP0PM__CMP_MONITOR_DISABLED   0x00 ///< Disable monitoring on the CP0 output.            
#define CS0PM_CP0PM__CMP_MONITOR_ENABLED    0x04 ///< Enable monitoring on the CP0 output.             
                                                                                                       
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
// CS0SE Enums (Capacitive Sense 0 Auto Scan End Channel @ 0x93)
//------------------------------------------------------------------------------
#define CS0SE_CS0SE__FMASK 0x1F ///< Ending Channel for Auto Scan
#define CS0SE_CS0SE__SHIFT 0x00 ///< Ending Channel for Auto Scan
                                                                 
//------------------------------------------------------------------------------
// CS0SS Enums (Capacitive Sense 0 Auto Scan Start Channel @ 0x92)
//------------------------------------------------------------------------------
#define CS0SS_CS0SS__FMASK 0x1F ///< Starting Channel for Auto Scan
#define CS0SS_CS0SS__SHIFT 0x00 ///< Starting Channel for Auto Scan
                                                                   
//------------------------------------------------------------------------------
// CS0THH Enums (Capacitive Sense 0 Comparator Threshold High Byte @ 0x97)
//------------------------------------------------------------------------------
#define CS0THH_CS0THH__FMASK 0xFF ///< CS0 Comparator Threshold High Byte
#define CS0THH_CS0THH__SHIFT 0x00 ///< CS0 Comparator Threshold High Byte
                                                                         
//------------------------------------------------------------------------------
// CS0THL Enums (Capacitive Sense 0 Comparator Threshold Low Byte @ 0x96)
//------------------------------------------------------------------------------
#define CS0THL_CS0THL__FMASK 0xFF ///< CS0 Comparator Threshold Low Byte
#define CS0THL_CS0THL__SHIFT 0x00 ///< CS0 Comparator Threshold Low Byte
                                                                        
//------------------------------------------------------------------------------
// DERIVID Enums (Derivative Identification @ 0xEC)
//------------------------------------------------------------------------------
#define DERIVID_DERIVID__FMASK        0xFF ///< Derivative ID
#define DERIVID_DERIVID__SHIFT        0x00 ///< Derivative ID
#define DERIVID_DERIVID__C8051F700    0xD0 ///< C8051F700    
#define DERIVID_DERIVID__C8051F701    0xD1 ///< C8051F701    
#define DERIVID_DERIVID__C8051F702    0xD2 ///< C8051F702    
#define DERIVID_DERIVID__C8051F703    0xD3 ///< C8051F703    
#define DERIVID_DERIVID__C8051F704    0xD4 ///< C8051F704    
#define DERIVID_DERIVID__C8051F705    0xD5 ///< C8051F705    
#define DERIVID_DERIVID__C8051F706    0xD6 ///< C8051F706    
#define DERIVID_DERIVID__C8051F707    0xD7 ///< C8051F707    
#define DERIVID_DERIVID__C8051F708    0xD8 ///< C8051F708    
#define DERIVID_DERIVID__C8051F709    0xD9 ///< C8051F709    
#define DERIVID_DERIVID__C8051F710    0xDA ///< C8051F710    
#define DERIVID_DERIVID__C8051F711    0xDB ///< C8051F711    
#define DERIVID_DERIVID__C8051F712    0xDC ///< C8051F712    
#define DERIVID_DERIVID__C8051F713    0xDD ///< C8051F713    
#define DERIVID_DERIVID__C8051F714    0xDE ///< C8051F714    
#define DERIVID_DERIVID__C8051F715    0xDF ///< C8051F715    
#define DERIVID_DERIVID__C8051F716    0xE0 ///< C8051F716    
#define DERIVID_DERIVID__C8051F717    0xE1 ///< C8051F717    
#define DERIVID_DERIVID__C8051F862_GS 0xE2 ///< C8051F862-GS 
#define DERIVID_DERIVID__C8051F863_GS 0xE3 ///< C8051F863-GS 
#define DERIVID_DERIVID__C8051F864_GS 0xE4 ///< C8051F864-GS 
#define DERIVID_DERIVID__C8051F865_GS 0xE5 ///< C8051F865-GS 
#define DERIVID_DERIVID__C8051F850_GM 0xF0 ///< C8051F850-GM 
#define DERIVID_DERIVID__C8051F851_GM 0xF1 ///< C8051F851-GM 
#define DERIVID_DERIVID__C8051F852_GM 0xF2 ///< C8051F852-GM 
#define DERIVID_DERIVID__C8051F853_GM 0xF3 ///< C8051F853-GM 
#define DERIVID_DERIVID__C8051F854_GM 0xF4 ///< C8051F854-GM 
#define DERIVID_DERIVID__C8051F855_GM 0xF5 ///< C8051F855-GM 
                                                             
//------------------------------------------------------------------------------
// DEVICEID Enums (Device Identification @ 0xC4)
//------------------------------------------------------------------------------
#define DEVICEID_DEVICEID__FMASK 0xFF ///< Device ID
#define DEVICEID_DEVICEID__SHIFT 0x00 ///< Device ID
                                                    
//------------------------------------------------------------------------------
// REVID Enums (Revision Identifcation @ 0xAD)
//------------------------------------------------------------------------------
#define REVID_REVID__FMASK 0xFF ///< Revision ID
#define REVID_REVID__SHIFT 0x00 ///< Revision ID
#define REVID_REVID__REV_A 0x00 ///< Revision A 
#define REVID_REVID__REV_B 0x01 ///< Revision B 
#define REVID_REVID__REV_C 0x02 ///< Revision C 
                                                
//------------------------------------------------------------------------------
// EEADR Enums (EEPROM Byte Address @ 0xB6)
//------------------------------------------------------------------------------
#define EEADR_EEADR__FMASK 0x1F ///< EEPROM Byte Address
#define EEADR_EEADR__SHIFT 0x00 ///< EEPROM Byte Address
                                                        
//------------------------------------------------------------------------------
// EECN Enums (EEPROM Control @ 0xC5)
//------------------------------------------------------------------------------
#define EECN_AUTOINC__BMASK    0x01 ///< Auto Increment Enable                            
#define EECN_AUTOINC__SHIFT    0x00 ///< Auto Increment Enable                            
#define EECN_AUTOINC__DISABLED 0x00 ///< Disable auto-increment.                          
#define EECN_AUTOINC__ENABLED  0x01 ///< Enable auto-increment.                           
                                                                                          
#define EECN_EEWRITE__BMASK    0x02 ///< EEPROM 32-Byte Write                             
#define EECN_EEWRITE__SHIFT    0x01 ///< EEPROM 32-Byte Write                             
#define EECN_EEWRITE__COPY     0x02 ///< Copy the 32 bytes of EEPROM RAM into the EEPROM. 
                                                                                          
#define EECN_EEREAD__BMASK     0x04 ///< EEPROM 32-Byte Read                              
#define EECN_EEREAD__SHIFT     0x02 ///< EEPROM 32-Byte Read                              
#define EECN_EEREAD__COPY      0x04 ///< Copy the 32 bytes of the EEPROM into the EEPROM  
                                    ///< RAM.                                             
                                                                                          
#define EECN_EEEN__BMASK       0x80 ///< EEPROM Enable                                    
#define EECN_EEEN__SHIFT       0x07 ///< EEPROM Enable                                    
#define EECN_EEEN__DISABLED    0x00 ///< Disable the EEPROM control logic.                
#define EECN_EEEN__ENABLED     0x80 ///< Enable the EEPROM control logic. EEPROM reads and
                                    ///< writes can be performed.                         
                                                                                          
//------------------------------------------------------------------------------
// EEDAT Enums (EEPROM Byte Data @ 0xD1)
//------------------------------------------------------------------------------
#define EEDAT_EEDAT__FMASK 0xFF ///< EEPROM Data
#define EEDAT_EEDAT__SHIFT 0x00 ///< EEPROM Data
                                                
//------------------------------------------------------------------------------
// EEKEY Enums (EEPROM Key @ 0xC6)
//------------------------------------------------------------------------------
#define EEKEY_EEKEY__FMASK    0xFF ///< EEPROM Key                                      
#define EEKEY_EEKEY__SHIFT    0x00 ///< EEPROM Key                                      
#define EEKEY_EEKEY__LOCKED   0x00 ///< EEPROM writes are not enabled.                  
#define EEKEY_EEKEY__FIRST    0x01 ///< The first key code has been written (0x55).     
#define EEKEY_EEKEY__UNLOCKED 0x02 ///< The EEPROM is unlocked (writes allowed).        
#define EEKEY_EEKEY__DISABLED 0x03 ///< EEPROM writes are disabled until the next reset.
#define EEKEY_EEKEY__KEY1     0x55 ///<                                                 
#define EEKEY_EEKEY__KEY2     0xAA ///<                                                 
                                                                                        
//------------------------------------------------------------------------------
// IT01CF Enums (INT0/INT1 Configuration @ 0xE4)
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
// OSCXCN Enums (External Oscillator Control @ 0xB5)
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
// OSCICL Enums (High Frequency Oscillator Calibration @ 0xBF)
//------------------------------------------------------------------------------
#define OSCICL_OSCICL__FMASK 0xFF ///< Internal Oscillator Calibration
#define OSCICL_OSCICL__SHIFT 0x00 ///< Internal Oscillator Calibration
                                                                      
//------------------------------------------------------------------------------
// OSCICN Enums (High Frequency Oscillator Control @ 0xA9)
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
                                                                                            
#define OSCICN_SSE__BMASK        0x08 ///< Spread Spectrum Enable                           
#define OSCICN_SSE__SHIFT        0x03 ///< Spread Spectrum Enable                           
#define OSCICN_SSE__DISABLED     0x00 ///< Spread Spectrum clock dithering disabled.        
#define OSCICN_SSE__ENABLED      0x08 ///< Spread Spectrum clock dithering enabled.         
                                                                                            
#define OSCICN_STSYNC__BMASK     0x10 ///< Suspend Timer Synchronization                    
#define OSCICN_STSYNC__SHIFT     0x04 ///< Suspend Timer Synchronization                    
#define OSCICN_STSYNC__NOT_SET   0x00 ///< It is safe to read and write the suspend timer   
                                      ///< registers.                                       
#define OSCICN_STSYNC__SET       0x10 ///< Reads and writes of the suspend timer register   
                                      ///< should not be performed.                         
                                                                                            
#define OSCICN_SUSPEND__BMASK    0x20 ///< Oscillator Suspend Enable                        
#define OSCICN_SUSPEND__SHIFT    0x05 ///< Oscillator Suspend Enable                        
#define OSCICN_SUSPEND__DISABLED 0x00 ///< The internal oscillator is not in suspend mode.  
#define OSCICN_SUSPEND__ENABLED  0x20 ///< Place the internal oscillator in suspend mode.   
                                                                                            
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
#define EIE1_ESMB0__BMASK     0x01 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__SHIFT     0x00 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__DISABLED  0x00 ///< Disable all SMB0 interrupts.                      
#define EIE1_ESMB0__ENABLED   0x01 ///< Enable interrupt requests generated by SMB0.      
                                                                                          
#define EIE1_EMAT__BMASK      0x02 ///< Port Match Interrupts Enable                      
#define EIE1_EMAT__SHIFT      0x01 ///< Port Match Interrupts Enable                      
#define EIE1_EMAT__DISABLED   0x00 ///< Disable all Port Match interrupts.                
#define EIE1_EMAT__ENABLED    0x02 ///< Enable interrupt requests generated by a Port     
                                   ///< Match.                                            
                                                                                          
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
                                                                                          
#define EIE1_ET3__BMASK       0x80 ///< Timer 3 Interrupt Enable                          
#define EIE1_ET3__SHIFT       0x07 ///< Timer 3 Interrupt Enable                          
#define EIE1_ET3__DISABLED    0x00 ///< Disable Timer 3 interrupts.                       
#define EIE1_ET3__ENABLED     0x80 ///< Enable interrupt requests generated by the TF3L or
                                   ///< TF3H flags.                                       
                                                                                          
//------------------------------------------------------------------------------
// EIE2 Enums (Extended Interrupt Enable 2 @ 0xE7)
//------------------------------------------------------------------------------
#define EIE2_ECSCPT__BMASK    0x01 ///< Capacitive Sense Conversion Complete Interrupt Enable
#define EIE2_ECSCPT__SHIFT    0x00 ///< Capacitive Sense Conversion Complete Interrupt Enable
#define EIE2_ECSCPT__DISABLED 0x00 ///< Disable Capacitive Sense Conversion Complete         
                                   ///< interrupt.                                           
#define EIE2_ECSCPT__ENABLED  0x01 ///< Enable interrupt requests generated by CS0INT.       
                                                                                             
#define EIE2_ECSDC__BMASK     0x02 ///< Capacitive Sense Digital Comparator Interrupt Enable 
#define EIE2_ECSDC__SHIFT     0x01 ///< Capacitive Sense Digital Comparator Interrupt Enable 
#define EIE2_ECSDC__DISABLED  0x00 ///< Disable Capacitive Sense Digital Comparator          
                                   ///< interrupt.                                           
#define EIE2_ECSDC__ENABLED   0x02 ///< Enable interrupt requests generated by the           
                                   ///< Capacitive Sense Digital Comparator.                 
                                                                                             
//------------------------------------------------------------------------------
// EIP1 Enums (Extended Interrupt Priority 1 @ 0xCE)
//------------------------------------------------------------------------------
#define EIP1_PSMB0__BMASK  0x01 ///< SMBus (SMB0) Interrupt Priority Control                     
#define EIP1_PSMB0__SHIFT  0x00 ///< SMBus (SMB0) Interrupt Priority Control                     
#define EIP1_PSMB0__LOW    0x00 ///< SMB0 interrupt set to low priority level.                   
#define EIP1_PSMB0__HIGH   0x01 ///< SMB0 interrupt set to high priority level.                  
                                                                                                 
#define EIP1_PMAT__BMASK   0x02 ///< Port Match Interrupt Priority Control                       
#define EIP1_PMAT__SHIFT   0x01 ///< Port Match Interrupt Priority Control                       
#define EIP1_PMAT__LOW     0x00 ///< Port Match interrupt set to low priority level.             
#define EIP1_PMAT__HIGH    0x02 ///< Port Match interrupt set to high priority level.            
                                                                                                 
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
                                                                                                 
#define EIP1_PT3__BMASK    0x80 ///< Timer 3 Interrupt Priority Control                          
#define EIP1_PT3__SHIFT    0x07 ///< Timer 3 Interrupt Priority Control                          
#define EIP1_PT3__LOW      0x00 ///< Timer 3 interrupts set to low priority level.               
#define EIP1_PT3__HIGH     0x80 ///< Timer 3 interrupts set to high priority level.              
                                                                                                 
//------------------------------------------------------------------------------
// EIP2 Enums (Extended Interrupt Priority 2 @ 0xCF)
//------------------------------------------------------------------------------
#define EIP2_PCSCPT__BMASK 0x01 ///< Capacitive Sense Conversion Complete Interrupt Priority Control
#define EIP2_PCSCPT__SHIFT 0x00 ///< Capacitive Sense Conversion Complete Interrupt Priority Control
#define EIP2_PCSCPT__LOW   0x00 ///< Capacitive Sense Conversion Complete interrupt set             
                                ///< to low priority level.                                         
#define EIP2_PCSCPT__HIGH  0x01 ///< Capacitive Sense Conversion Complete interrupt set             
                                ///< to high priority level.                                        
                                                                                                    
#define EIP2_PCSDC__BMASK  0x02 ///< Capacitive Sense Digital Comparator Interrupt Priority Control 
#define EIP2_PCSDC__SHIFT  0x01 ///< Capacitive Sense Digital Comparator Interrupt Priority Control 
#define EIP2_PCSDC__LOW    0x00 ///< Capacitive Sense Digital Comparator interrupt set              
                                ///< to low priority level.                                         
#define EIP2_PCSDC__HIGH   0x02 ///< Capacitive Sense Digital Comparator interrupt set              
                                ///< to high priority level.                                        
                                                                                                    
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
// XBR0 Enums (Port I/O Crossbar 0 @ 0xE1)
//------------------------------------------------------------------------------
#define XBR0_URT0E__BMASK     0x01 ///< UART I/O Output Enable                        
#define XBR0_URT0E__SHIFT     0x00 ///< UART I/O Output Enable                        
#define XBR0_URT0E__DISABLED  0x00 ///< UART I/O unavailable at Port pin.             
#define XBR0_URT0E__ENABLED   0x01 ///< UART TX, RX routed to Port pins P0.4 and P0.5.
                                                                                      
#define XBR0_SPI0E__BMASK     0x02 ///< SPI I/O Enable                                
#define XBR0_SPI0E__SHIFT     0x01 ///< SPI I/O Enable                                
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
                                                                                      
//------------------------------------------------------------------------------
// XBR1 Enums (Port I/O Crossbar 1 @ 0xE2)
//------------------------------------------------------------------------------
#define XBR1_PCA0ME__FMASK              0x03 ///< PCA Module I/O Enable                           
#define XBR1_PCA0ME__SHIFT              0x00 ///< PCA Module I/O Enable                           
#define XBR1_PCA0ME__DISABLED           0x00 ///< All PCA I/O unavailable at Port pins.           
#define XBR1_PCA0ME__CEX0               0x01 ///< CEX0 routed to Port pin.                        
#define XBR1_PCA0ME__CEX0_CEX1          0x02 ///< CEX0, CEX1 routed to Port pins.                 
#define XBR1_PCA0ME__CEX0_CEX1_CEX2     0x03 ///< CEX0, CEX1, CEX2 routed to Port pins.           
                                                                                                  
#define XBR1_ECIE__BMASK                0x08 ///< PCA0 External Counter Input Enable              
#define XBR1_ECIE__SHIFT                0x03 ///< PCA0 External Counter Input Enable              
#define XBR1_ECIE__DISABLED             0x00 ///< ECI unavailable at Port pin.                    
#define XBR1_ECIE__ENABLED              0x08 ///< ECI routed to Port pin.                         
                                                                                                  
#define XBR1_T0E__BMASK                 0x10 ///< T0 Enable                                       
#define XBR1_T0E__SHIFT                 0x04 ///< T0 Enable                                       
#define XBR1_T0E__DISABLED              0x00 ///< T0 unavailable at Port pin.                     
#define XBR1_T0E__ENABLED               0x10 ///< T0 routed to Port pin.                          
                                                                                                  
#define XBR1_T1E__BMASK                 0x20 ///< T1 Enable                                       
#define XBR1_T1E__SHIFT                 0x05 ///< T1 Enable                                       
#define XBR1_T1E__DISABLED              0x00 ///< T1 unavailable at Port pin.                     
#define XBR1_T1E__ENABLED               0x20 ///< T1 routed to Port pin.                          
                                                                                                  
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
// PCA0MD Enums (PCA Mode @ 0xED)
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
                                                                                                 
#define PCA0MD_CIDL__BMASK           0x80 ///< PCA Counter/Timer Idle Control                    
#define PCA0MD_CIDL__SHIFT           0x07 ///< PCA Counter/Timer Idle Control                    
#define PCA0MD_CIDL__NORMAL          0x00 ///< PCA continues to function normally while the      
                                          ///< system controller is in Idle Mode.                
#define PCA0MD_CIDL__SUSPEND         0x80 ///< PCA operation is suspended while the system       
                                          ///< controller is in Idle Mode.                       
                                                                                                 
//------------------------------------------------------------------------------
// PCA0PWM Enums (PCA PWM Configuration @ 0xA1)
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
// P0DRV Enums (Port 0 Drive Strength @ 0xF9)
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
// P0MASK Enums (Port 0 Mask @ 0xF4)
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
// P0MAT Enums (Port 0 Match @ 0xF3)
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
// P1DRV Enums (Port 1 Drive Strength @ 0xFA)
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
// P1MASK Enums (Port 1 Mask @ 0xE2)
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
// P1MAT Enums (Port 1 Match @ 0xE1)
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
// P2DRV Enums (Port 2 Drive Strength @ 0xFB)
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
// P3DRV Enums (Port 3 Drive Strength @ 0xFC)
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
// P3MDOUT Enums (Port 3 Output Mode @ 0xAF)
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
// P4 Enums (Port 4 Pin Latch @ 0xAC)
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
// P4DRV Enums (Port 4 Drive Strength @ 0xFD)
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
// P4MDIN Enums (Port 4 Input Mode @ 0xF5)
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
// P4MDOUT Enums (Port 4 Output Mode @ 0x9A)
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
// P5 Enums (Port 5 Pin Latch @ 0xB3)
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
// P5DRV Enums (Port 5 Drive Strength @ 0xFE)
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
// P5MDIN Enums (Port 5 Input Mode @ 0xF6)
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
// P5MDOUT Enums (Port 5 Output Mode @ 0x9B)
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
// P6 Enums (Port 6 Pin Latch @ 0xB2)
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
                                                                             
//------------------------------------------------------------------------------
// P6DRV Enums (Port 6 Drive Strength @ 0xC1)
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
                                                                                  
//------------------------------------------------------------------------------
// P6MDIN Enums (Port 6 Input Mode @ 0xF7)
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
                                                                             
//------------------------------------------------------------------------------
// P6MDOUT Enums (Port 6 Output Mode @ 0x9C)
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
// SMB0ADM Enums (SMBus 0 Slave Address Mask @ 0xBB)
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
// SMB0ADR Enums (SMBus 0 Slave Address @ 0xBA)
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
#define VDM0CN_VDDSTAT__BMASK     0x40 ///< VDD Status                                   
#define VDM0CN_VDDSTAT__SHIFT     0x06 ///< VDD Status                                   
#define VDM0CN_VDDSTAT__VDD_BELOW 0x00 ///< VDD is at or below the VDD monitor threshold.
#define VDM0CN_VDDSTAT__VDD_ABOVE 0x40 ///< VDD is above the VDD monitor threshold.      
                                                                                         
#define VDM0CN_VDMEN__BMASK       0x80 ///< VDD Monitor Enable                           
#define VDM0CN_VDMEN__SHIFT       0x07 ///< VDD Monitor Enable                           
#define VDM0CN_VDMEN__DISABLED    0x00 ///< Disable the VDD Monitor.                     
#define VDM0CN_VDMEN__ENABLED     0x80 ///< Enable the VDD Monitor.                      
                                                                                         
//------------------------------------------------------------------------------
// REF0CN Enums (Voltage Reference Control @ 0xD2)
//------------------------------------------------------------------------------
#define REF0CN_BIASE__BMASK         0x02 ///< Internal Analog Bias Generator Enable             
#define REF0CN_BIASE__SHIFT         0x01 ///< Internal Analog Bias Generator Enable             
#define REF0CN_BIASE__DISABLED      0x00 ///< Disable the internal bias generator.              
#define REF0CN_BIASE__ENABLED       0x02 ///< Enable the internal bias generator.               
                                                                                                
#define REF0CN_TEMPE__BMASK         0x04 ///< Temperature Sensor Enable                         
#define REF0CN_TEMPE__SHIFT         0x02 ///< Temperature Sensor Enable                         
#define REF0CN_TEMPE__TEMP_DISABLED 0x00 ///< Disable the Temperature Sensor.                   
#define REF0CN_TEMPE__TEMP_ENABLED  0x04 ///< Enable the Temperature Sensor.                    
                                                                                                
#define REF0CN_REFSL__FMASK         0x18 ///< Voltage Reference Select                          
#define REF0CN_REFSL__SHIFT         0x03 ///< Voltage Reference Select                          
#define REF0CN_REFSL__VREF_PIN      0x00 ///< The ADC0 voltage reference is the P0.0/VREF pin.  
#define REF0CN_REFSL__VDD_PIN       0x08 ///< The ADC0 voltage reference is the VDD pin.        
#define REF0CN_REFSL__INTERNAL_LDO  0x10 ///< The ADC0 voltage reference is the internal 1.8 V  
                                         ///< digital supply voltage.                           
#define REF0CN_REFSL__INTERNAL_VREF 0x18 ///< The ADC0 voltage reference is the internal voltage
                                         ///< reference.                                        
                                                                                                
#define REF0CN_GNDSL__BMASK         0x20 ///< Analog Ground Reference                           
#define REF0CN_GNDSL__SHIFT         0x05 ///< Analog Ground Reference                           
#define REF0CN_GNDSL__GND_PIN       0x00 ///< The ADC0 ground reference is the GND pin.         
#define REF0CN_GNDSL__AGND_PIN      0x20 ///< The ADC0 ground reference is the P0.1/AGND pin.   
                                                                                                
//------------------------------------------------------------------------------
// REG0CN Enums (Voltage Regulator Control @ 0xB9)
//------------------------------------------------------------------------------
#define REG0CN_STOPCF__BMASK    0x80 ///< Stop Mode Configuration                           
#define REG0CN_STOPCF__SHIFT    0x07 ///< Stop Mode Configuration                           
#define REG0CN_STOPCF__ACTIVE   0x00 ///< Regulator is still active in stop mode. Any       
                                     ///< enabled reset source will reset the device.       
#define REG0CN_STOPCF__SHUTDOWN 0x80 ///< Regulator is shut down in stop mode. Only the /RST
                                     ///< pin or power cycle can reset the device.          
                                                                                            
//------------------------------------------------------------------------------
// WDTCN Enums (Watchdog Timer Control @ 0xE3)
//------------------------------------------------------------------------------
#define WDTCN_WDTCN__FMASK 0xFF ///< WDT Control
#define WDTCN_WDTCN__SHIFT 0x00 ///< WDT Control
                                                
//------------------------------------------------------------------------------
// EMI0CF Enums (External Memory Configuration @ 0xC7)
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
// EMI0TC Enums (External Memory Timing Control @ 0xEE)
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
                                                                                       
#endif // SI_C8051F700_REGISTER_ENUMS_H
//-eof--------------------------------------------------------------------------

