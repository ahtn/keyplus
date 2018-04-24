//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  C8051F410_GQ
//  C8051F411_GM
//  C8051F412_GQ
//  C8051F413_GM
//  C8051F414_GQ
//  C8051F415_GM
//  C8051F416_GQ
//  C8051F417_GM

#ifndef SI_C8051F410_REGISTER_ENUMS_H
#define SI_C8051F410_REGISTER_ENUMS_H

//Standard device includes
#include "SI_C8051F410_Defs.h"
//------------------------------------------------------------------------------
// ADC0CF Enums (ADC0 Configuration @ 0xBC)
//------------------------------------------------------------------------------
#define ADC0CF_ADRPT__FMASK  0x06 ///< Repeat Count                          
#define ADC0CF_ADRPT__SHIFT  0x01 ///< Repeat Count                          
#define ADC0CF_ADRPT__ACC_1  0x00 ///< Perform and Accumulate 1 conversion.  
#define ADC0CF_ADRPT__ACC_4  0x02 ///< Perform and Accumulate 4 conversions. 
#define ADC0CF_ADRPT__ACC_8  0x04 ///< Perform and Accumulate 8 conversions. 
#define ADC0CF_ADRPT__ACC_16 0x06 ///< Perform and Accumulate 16 conversions.
                                                                             
#define ADC0CF_ADSC__FMASK   0xF8 ///< SAR Clock Divider                     
#define ADC0CF_ADSC__SHIFT   0x03 ///< SAR Clock Divider                     
                                                                             
//------------------------------------------------------------------------------
// ADC0CN Enums (ADC0 Control @ 0xE8)
//------------------------------------------------------------------------------
#define ADC0CN_ADCM__FMASK            0x03 ///< Start of Conversion Mode Select                   
#define ADC0CN_ADCM__SHIFT            0x00 ///< Start of Conversion Mode Select                   
#define ADC0CN_ADCM__ADBUSY           0x00 ///< ADC0 conversion initiated on write of 1 to ADBUSY.
#define ADC0CN_ADCM__TIMER3           0x01 ///< ADC0 conversion initiated on overflow of Timer 3. 
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
#define ADC0MX_ADC0MX__FMASK   0x1F ///< AMUX Positive Input Selection
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
#define ADC0MX_ADC0MX__TEMP    0x18 ///< Temperature Sensor.          
#define ADC0MX_ADC0MX__VDD     0x19 ///< VDD Supply Voltage.          
#define ADC0MX_ADC0MX__GND     0x1F ///< Ground.                      
                                                                      
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
// SP Enums (Stack Pointer @ 0x81)
//------------------------------------------------------------------------------
#define SP_SP__FMASK 0xFF ///< Stack Pointer
#define SP_SP__SHIFT 0x00 ///< Stack Pointer
                                            
//------------------------------------------------------------------------------
// CLKMUL Enums (Clock Multiplier Control @ 0xAB)
//------------------------------------------------------------------------------
#define CLKMUL_MULSEL__FMASK            0x03 ///< Clock Multiplier Input Select                     
#define CLKMUL_MULSEL__SHIFT            0x00 ///< Clock Multiplier Input Select                     
#define CLKMUL_MULSEL__HFOSC_DIV_2      0x00 ///< Clock Multiplier input clock source is the        
                                             ///< Internal High-Frequency Oscillator / 2.           
#define CLKMUL_MULSEL__EXTOSC           0x01 ///< Clock Multiplier input clock source is the        
                                             ///< External Oscillator.                              
#define CLKMUL_MULSEL__EXTOSC_DIV_2     0x02 ///< Clock Multiplier input clock source is the        
                                             ///< External Oscillator / 2.                          
#define CLKMUL_MULSEL__HFOSC            0x03 ///< Clock Multiplier input clock source is the        
                                             ///< Internal High-Frequency Oscillator.               
                                                                                                    
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
// CLKSEL Enums (Clock Select @ 0xA9)
//------------------------------------------------------------------------------
#define CLKSEL_CLKSL__FMASK             0x03 ///< Clock Source Select                               
#define CLKSEL_CLKSL__SHIFT             0x00 ///< Clock Source Select                               
#define CLKSEL_CLKSL__DIVIDED_HFOSC     0x00 ///< Clock (SYSCLK) derived from the Internal precision
                                             ///< High-Frequency Oscillator and scaled per the IFCN 
                                             ///< bits in register OSCICN.                          
#define CLKSEL_CLKSL__EXTOSC            0x01 ///< Clock (SYSCLK) derived from the External          
                                             ///< Oscillator circuit.                               
#define CLKSEL_CLKSL__CLKMUL            0x02 ///< Clock (SYSCLK) derived from the Clock Multiplier. 
#define CLKSEL_CLKSL__RTC               0x03 ///< Clock (SYSCLK) derived from RTC0.                 
                                                                                                    
#define CLKSEL_CLKDIV__FMASK            0x30 ///< Output Clock Divider                              
#define CLKSEL_CLKDIV__SHIFT            0x04 ///< Output Clock Divider                              
#define CLKSEL_CLKDIV__SYSCLK_DIV_1_OUT 0x00 ///< Output will be divided by SYSCLK / 1.             
#define CLKSEL_CLKDIV__SYSCLK_DIV_2_OUT 0x10 ///< Output will be divided by SYSCLK / 2.             
#define CLKSEL_CLKDIV__SYSCLK_DIV_4_OUT 0x20 ///< Output will be divided by SYSCLK / 4.             
#define CLKSEL_CLKDIV__SYSCLK_DIV_8_OUT 0x30 ///< Output will be divided by SYSCLK / 8.             
                                                                                                    
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
// CRC0CN Enums (CRC0 Control @ 0x84)
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
// CRC0DAT Enums (CRC0 Data Output @ 0x86)
//------------------------------------------------------------------------------
#define CRC0DAT_CRC0DAT__FMASK 0xFF ///< CRC Data Output
#define CRC0DAT_CRC0DAT__SHIFT 0x00 ///< CRC Data Output
                                                        
//------------------------------------------------------------------------------
// CRC0FLIP Enums (CRC0 Bit Flip @ 0xDF)
//------------------------------------------------------------------------------
#define CRC0FLIP_CRC0FLIP__FMASK 0xFF ///< CRC0 Bit Flip
#define CRC0FLIP_CRC0FLIP__SHIFT 0x00 ///< CRC0 Bit Flip
                                                        
//------------------------------------------------------------------------------
// CRC0IN Enums (CRC0 Data Input @ 0x85)
//------------------------------------------------------------------------------
#define CRC0IN_CRC0IN__FMASK 0xFF ///< CRC Data Input
#define CRC0IN_CRC0IN__SHIFT 0x00 ///< CRC Data Input
                                                     
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
// FLSCL Enums (Flash Scale @ 0xB6)
//------------------------------------------------------------------------------
#define FLSCL_FLRT__BMASK               0x10 ///< Flash Read Timing
#define FLSCL_FLRT__SHIFT               0x04 ///< Flash Read Timing
#define FLSCL_FLRT__SYSCLK_BELOW_25_MHZ 0x00 ///< SYSCLK <= 25 MHz.
#define FLSCL_FLRT__SYSCLK_BELOW_50_MHZ 0x10 ///< SYSCLK <= 50 MHz.
                                                                   
//------------------------------------------------------------------------------
// ONESHOT Enums (Flash Oneshot Period @ 0xAF)
//------------------------------------------------------------------------------
#define ONESHOT_PERIOD__FMASK 0x0F ///< Oneshot Period Control
#define ONESHOT_PERIOD__SHIFT 0x00 ///< Oneshot Period Control
                                                              
//------------------------------------------------------------------------------
// PFE0CN Enums (Prefetch Engine Control @ 0xE3)
//------------------------------------------------------------------------------
#define PFE0CN_FLBWE__BMASK                0x01 ///< Flash Block Write Enable                       
#define PFE0CN_FLBWE__SHIFT                0x00 ///< Flash Block Write Enable                       
#define PFE0CN_FLBWE__BLOCK_WRITE_DISABLED 0x00 ///< Each byte of a firmware flash write is written 
                                                ///< individually.                                  
#define PFE0CN_FLBWE__BLOCK_WRITE_ENABLED  0x01 ///< Flash bytes are written in groups of two.      
                                                                                                    
#define PFE0CN_PFEN__BMASK                 0x20 ///< Prefetch Enable                                
#define PFE0CN_PFEN__SHIFT                 0x05 ///< Prefetch Enable                                
#define PFE0CN_PFEN__DISABLED              0x00 ///< Disable the prefetch engine (SYSCLK <= 25 MHz).
#define PFE0CN_PFEN__ENABLED               0x20 ///< Enable the prefetch engine (SYSCLK > 25 MHz).  
                                                                                                    
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
#define OSCICL_OSCICL__FMASK 0x7F ///< Internal Oscillator Calibration
#define OSCICL_OSCICL__SHIFT 0x00 ///< Internal Oscillator Calibration
                                                                      
//------------------------------------------------------------------------------
// OSCICN Enums (High Frequency Oscillator Control @ 0xB2)
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
                                                                                              
#define OSCICN_SUSPEND__BMASK      0x20 ///< Oscillator Suspend Enable                        
#define OSCICN_SUSPEND__SHIFT      0x05 ///< Oscillator Suspend Enable                        
#define OSCICN_SUSPEND__DISABLED   0x00 ///< The internal oscillator is not in suspend mode.  
#define OSCICN_SUSPEND__ENABLED    0x20 ///< Place the internal oscillator in suspend mode.   
                                                                                              
#define OSCICN_IFRDY__BMASK        0x40 ///< Oscillator Frequency Ready Flag                  
#define OSCICN_IFRDY__SHIFT        0x06 ///< Oscillator Frequency Ready Flag                  
#define OSCICN_IFRDY__NOT_SET      0x00 ///< The Internal High Frequency Oscillator is not    
                                        ///< running at the programmed frequency.             
#define OSCICN_IFRDY__SET          0x40 ///< The Internal High Frequency Oscillator is running
                                        ///< at the programmed frequency.                     
                                                                                              
#define OSCICN_IOSCEN__BMASK       0x80 ///< Oscillator Enable                                
#define OSCICN_IOSCEN__SHIFT       0x07 ///< Oscillator Enable                                
#define OSCICN_IOSCEN__DISABLED    0x00 ///< Disable the High Frequency Oscillator.           
#define OSCICN_IOSCEN__ENABLED     0x80 ///< Enable the High Frequency Oscillator.            
                                                                                              
//------------------------------------------------------------------------------
// IDA0CN Enums (IDAC0 Control @ 0xB9)
//------------------------------------------------------------------------------
#define IDA0CN_IDAOMD__FMASK              0x03 ///< Output Mode Select                           
#define IDA0CN_IDAOMD__SHIFT              0x00 ///< Output Mode Select                           
#define IDA0CN_IDAOMD__0P25_MA            0x00 ///< 0.25 mA full-scale output current.           
#define IDA0CN_IDAOMD__0P5_MA             0x01 ///< 0.5 mA full-scale output current.            
#define IDA0CN_IDAOMD__1_MA               0x02 ///< 1.0 mA full-scale output current.            
#define IDA0CN_IDAOMD__2_MA               0x03 ///< 2.0 mA full-scale output current.            
                                                                                                 
#define IDA0CN_IDARJST__BMASK             0x04 ///< Right Justification Select                   
#define IDA0CN_IDARJST__SHIFT             0x02 ///< Right Justification Select                   
#define IDA0CN_IDARJST__DISABLED          0x00 ///< IDAC0 data in IDA0H:L is left-justified.     
#define IDA0CN_IDARJST__ENABLED           0x04 ///< IDAC0 data in IDA0H:L is right-justified.    
                                                                                                 
#define IDA0CN_IDACM__FMASK               0x70 ///< Update Source Select                         
#define IDA0CN_IDACM__SHIFT               0x04 ///< Update Source Select                         
#define IDA0CN_IDACM__TIMER0              0x00 ///< DAC output updates on Timer 0 overflow.      
#define IDA0CN_IDACM__TIMER1              0x10 ///< DAC output updates on Timer 1 overflow.      
#define IDA0CN_IDACM__TIMER2              0x20 ///< DAC output updates on Timer 2 overflow.      
#define IDA0CN_IDACM__TIMER3              0x30 ///< DAC output updates on Timer 3 overflow.      
#define IDA0CN_IDACM__CNVSTR_RISING_EDGE  0x40 ///< DAC output updates on rising edge of CNVSTR. 
#define IDA0CN_IDACM__CNVSTR_FALLING_EDGE 0x50 ///< DAC output updates on falling edge of CNVSTR.
#define IDA0CN_IDACM__CNVSTR_ANY_EDGE     0x60 ///< DAC output updates on any edge of CNVSTR.    
#define IDA0CN_IDACM__IDA0H               0x70 ///< DAC output updates on write to IDA0H.        
                                                                                                 
#define IDA0CN_IDAEN__BMASK               0x80 ///< IDAC Enable                                  
#define IDA0CN_IDAEN__SHIFT               0x07 ///< IDAC Enable                                  
#define IDA0CN_IDAEN__DISABLED            0x00 ///< Disable IDAC0.                               
#define IDA0CN_IDAEN__ENABLED             0x80 ///< Enable IDAC0.                                
                                                                                                 
//------------------------------------------------------------------------------
// IDA0H Enums (IDAC0 Data High Byte @ 0x97)
//------------------------------------------------------------------------------
#define IDA0H_IDA0__FMASK 0xFF ///< IDAC0 Data High
#define IDA0H_IDA0__SHIFT 0x00 ///< IDAC0 Data High
                                                   
//------------------------------------------------------------------------------
// IDA0L Enums (IDAC0 Data Low Byte @ 0x96)
//------------------------------------------------------------------------------
#define IDA0L_IDA0__FMASK 0xFF ///< IDA0 Data Low
#define IDA0L_IDA0__SHIFT 0x00 ///< IDA0 Data Low
                                                 
//------------------------------------------------------------------------------
// IDA1CN Enums (IDAC1 Control @ 0xB5)
//------------------------------------------------------------------------------
#define IDA1CN_IDAOMD__FMASK              0x03 ///< Output Mode Select                           
#define IDA1CN_IDAOMD__SHIFT              0x00 ///< Output Mode Select                           
#define IDA1CN_IDAOMD__0P25_MA            0x00 ///< 0.25 mA full-scale output current.           
#define IDA1CN_IDAOMD__0P5_MA             0x01 ///< 0.5 mA full-scale output current.            
#define IDA1CN_IDAOMD__1_MA               0x02 ///< 1.0 mA full-scale output current.            
#define IDA1CN_IDAOMD__2_MA               0x03 ///< 2.0 mA full-scale output current.            
                                                                                                 
#define IDA1CN_IDARJST__BMASK             0x04 ///< Right Justification Select                   
#define IDA1CN_IDARJST__SHIFT             0x02 ///< Right Justification Select                   
#define IDA1CN_IDARJST__DISABLED          0x00 ///< IDAC1 data in IDA1H:L is left-justified.     
#define IDA1CN_IDARJST__ENABLED           0x04 ///< IDAC1 data in IDA1H:L is right-justified.    
                                                                                                 
#define IDA1CN_IDACM__FMASK               0x70 ///< Update Source Select                         
#define IDA1CN_IDACM__SHIFT               0x04 ///< Update Source Select                         
#define IDA1CN_IDACM__TIMER0              0x00 ///< DAC output updates on Timer 0 overflow.      
#define IDA1CN_IDACM__TIMER1              0x10 ///< DAC output updates on Timer 1 overflow.      
#define IDA1CN_IDACM__TIMER2              0x20 ///< DAC output updates on Timer 2 overflow.      
#define IDA1CN_IDACM__TIMER3              0x30 ///< DAC output updates on Timer 3 overflow.      
#define IDA1CN_IDACM__CNVSTR_RISING_EDGE  0x40 ///< DAC output updates on rising edge of CNVSTR. 
#define IDA1CN_IDACM__CNVSTR_FALLING_EDGE 0x50 ///< DAC output updates on falling edge of CNVSTR.
#define IDA1CN_IDACM__CNVSTR_ANY_EDGE     0x60 ///< DAC output updates on any edge of CNVSTR.    
#define IDA1CN_IDACM__IDA1H               0x70 ///< DAC output updates on write to IDA1H.        
                                                                                                 
#define IDA1CN_IDAEN__BMASK               0x80 ///< IDAC Enable                                  
#define IDA1CN_IDAEN__SHIFT               0x07 ///< IDAC Enable                                  
#define IDA1CN_IDAEN__DISABLED            0x00 ///< Disable IDAC1.                               
#define IDA1CN_IDAEN__ENABLED             0x80 ///< Enable IDAC1.                                
                                                                                                 
//------------------------------------------------------------------------------
// IDA1H Enums (IDAC1 Data High Byte @ 0xF5)
//------------------------------------------------------------------------------
#define IDA1H_IDA1__FMASK 0xFF ///< IDAC1 Data High
#define IDA1H_IDA1__SHIFT 0x00 ///< IDAC1 Data High
                                                   
//------------------------------------------------------------------------------
// IDA1L Enums (IDAC1 Data Low Byte @ 0xF4)
//------------------------------------------------------------------------------
#define IDA1L_IDA1__FMASK 0xFF ///< IDA1 Data Low
#define IDA1L_IDA1__SHIFT 0x00 ///< IDA1 Data Low
                                                 
//------------------------------------------------------------------------------
// EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
//------------------------------------------------------------------------------
#define EIE1_ESMB0__BMASK     0x01 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__SHIFT     0x00 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__DISABLED  0x00 ///< Disable all SMB0 interrupts.                      
#define EIE1_ESMB0__ENABLED   0x01 ///< Enable interrupt requests generated by SMB0.      
                                                                                          
#define EIE1_ERTC0__BMASK     0x02 ///< RTC0 Interrupt Enable                             
#define EIE1_ERTC0__SHIFT     0x01 ///< RTC0 Interrupt Enable                             
#define EIE1_ERTC0__DISABLED  0x00 ///< Disable RTC0 interrupts.                          
#define EIE1_ERTC0__ENABLED   0x02 ///< Enable interrupt requests generated by the RTC0   
                                   ///< Alarm and  Oscillator Fail events.                
                                                                                          
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
#define EIE2_EREG0__BMASK    0x01 ///< Voltage Regulator Interrupt Enable                
#define EIE2_EREG0__SHIFT    0x00 ///< Voltage Regulator Interrupt Enable                
#define EIE2_EREG0__DISABLED 0x00 ///< Disable the Voltage Regulator dropout interrupt.  
#define EIE2_EREG0__ENABLED  0x01 ///< Enable interrupt requests generated by the Voltage
                                  ///< Regulator.                                        
                                                                                         
#define EIE2_EMAT__BMASK     0x02 ///< Port Match Interrupts Enable                      
#define EIE2_EMAT__SHIFT     0x01 ///< Port Match Interrupts Enable                      
#define EIE2_EMAT__DISABLED  0x00 ///< Disable all Port Match interrupts.                
#define EIE2_EMAT__ENABLED   0x02 ///< Enable interrupt requests generated by a Port     
                                  ///< Match.                                            
                                                                                         
//------------------------------------------------------------------------------
// EIP1 Enums (Extended Interrupt Priority 1 @ 0xF6)
//------------------------------------------------------------------------------
#define EIP1_PSMB0__BMASK  0x01 ///< SMBus (SMB0) Interrupt Priority Control                     
#define EIP1_PSMB0__SHIFT  0x00 ///< SMBus (SMB0) Interrupt Priority Control                     
#define EIP1_PSMB0__LOW    0x00 ///< SMB0 interrupt set to low priority level.                   
#define EIP1_PSMB0__HIGH   0x01 ///< SMB0 interrupt set to high priority level.                  
                                                                                                 
#define EIP1_PRTC0__BMASK  0x02 ///< RTC0 Interrupt Priority Control                             
#define EIP1_PRTC0__SHIFT  0x01 ///< RTC0 Interrupt Priority Control                             
#define EIP1_PRTC0__LOW    0x00 ///< RTC0 interrupts set to low priority level.                  
#define EIP1_PRTC0__HIGH   0x02 ///< RTC0 interrupts set to high priority level.                 
                                                                                                 
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
#define EIP2_PREG0__BMASK 0x01 ///< Voltage Regulator Interrupt Priority Control    
#define EIP2_PREG0__SHIFT 0x00 ///< Voltage Regulator Interrupt Priority Control    
#define EIP2_PREG0__LOW   0x00 ///< Voltage Regulator dropout interrupt set to low  
                               ///< priority level.                                 
#define EIP2_PREG0__HIGH  0x01 ///< Voltage Regulator dropout interrupt set to high 
                               ///< priority level.                                 
                                                                                    
#define EIP2_PMAT__BMASK  0x02 ///< Port Match Interrupt Priority Control           
#define EIP2_PMAT__SHIFT  0x01 ///< Port Match Interrupt Priority Control           
#define EIP2_PMAT__LOW    0x00 ///< Port Match interrupt set to low priority level. 
#define EIP2_PMAT__HIGH   0x02 ///< Port Match interrupt set to high priority level.
                                                                                    
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
                                                                                                              
#define XBR1_XBARE__BMASK                          0x40 ///< Crossbar Enable                                  
#define XBR1_XBARE__SHIFT                          0x06 ///< Crossbar Enable                                  
#define XBR1_XBARE__DISABLED                       0x00 ///< Crossbar disabled.                               
#define XBR1_XBARE__ENABLED                        0x40 ///< Crossbar enabled.                                
                                                                                                              
#define XBR1_WEAKPUD__BMASK                        0x80 ///< Port I/O Weak Pullup Disable                     
#define XBR1_WEAKPUD__SHIFT                        0x07 ///< Port I/O Weak Pullup Disable                     
#define XBR1_WEAKPUD__PULL_UPS_ENABLED             0x00 ///< Weak Pullups enabled (except for Ports whose I/O 
                                                        ///< are configured for analog mode).                 
#define XBR1_WEAKPUD__PULL_UPS_DISABLED            0x80 ///< Weak Pullups disabled.                           
                                                                                                              
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
#define PCA0CPM0_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
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
#define PCA0CPM1_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
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
#define PCA0CPM2_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
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
#define PCA0CPM3_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
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
#define PCA0CPM4_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
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
#define PCA0CPM5_PWM16__8_BIT   0x00 ///< 8-bit PWM selected.                            
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
// P0ODEN Enums (Port 0 Overdrive Mode @ 0xB0)
//------------------------------------------------------------------------------
#define P0ODEN_B0__BMASK          0x01 ///< Port 0 Bit 0 Overdrive Mode                     
#define P0ODEN_B0__SHIFT          0x00 ///< Port 0 Bit 0 Overdrive Mode                     
#define P0ODEN_B0__NORMAL         0x00 ///< Configure P0.0 to normal overdrive mode.        
#define P0ODEN_B0__HIGH_IMPEDANCE 0x01 ///< Configure P0.0 to high-impedance overdrive mode.
                                                                                            
#define P0ODEN_B1__BMASK          0x02 ///< Port 0 Bit 1 Overdrive Mode                     
#define P0ODEN_B1__SHIFT          0x01 ///< Port 0 Bit 1 Overdrive Mode                     
#define P0ODEN_B1__NORMAL         0x00 ///< Configure P0.1 to normal overdrive mode.        
#define P0ODEN_B1__HIGH_IMPEDANCE 0x02 ///< Configure P0.1 to high-impedance overdrive mode.
                                                                                            
#define P0ODEN_B2__BMASK          0x04 ///< Port 0 Bit 2 Overdrive Mode                     
#define P0ODEN_B2__SHIFT          0x02 ///< Port 0 Bit 2 Overdrive Mode                     
#define P0ODEN_B2__NORMAL         0x00 ///< Configure P0.2 to normal overdrive mode.        
#define P0ODEN_B2__HIGH_IMPEDANCE 0x04 ///< Configure P0.2 to high-impedance overdrive mode.
                                                                                            
#define P0ODEN_B3__BMASK          0x08 ///< Port 0 Bit 3 Overdrive Mode                     
#define P0ODEN_B3__SHIFT          0x03 ///< Port 0 Bit 3 Overdrive Mode                     
#define P0ODEN_B3__NORMAL         0x00 ///< Configure P0.3 to normal overdrive mode.        
#define P0ODEN_B3__HIGH_IMPEDANCE 0x08 ///< Configure P0.3 to high-impedance overdrive mode.
                                                                                            
#define P0ODEN_B4__BMASK          0x10 ///< Port 0 Bit 4 Overdrive Mode                     
#define P0ODEN_B4__SHIFT          0x04 ///< Port 0 Bit 4 Overdrive Mode                     
#define P0ODEN_B4__NORMAL         0x00 ///< Configure P0.4 to normal overdrive mode.        
#define P0ODEN_B4__HIGH_IMPEDANCE 0x10 ///< Configure P0.4 to high-impedance overdrive mode.
                                                                                            
#define P0ODEN_B5__BMASK          0x20 ///< Port 0 Bit 5 Overdrive Mode                     
#define P0ODEN_B5__SHIFT          0x05 ///< Port 0 Bit 5 Overdrive Mode                     
#define P0ODEN_B5__NORMAL         0x00 ///< Configure P0.5 to normal overdrive mode.        
#define P0ODEN_B5__HIGH_IMPEDANCE 0x20 ///< Configure P0.5 to high-impedance overdrive mode.
                                                                                            
#define P0ODEN_B6__BMASK          0x40 ///< Port 0 Bit 6 Overdrive Mode                     
#define P0ODEN_B6__SHIFT          0x06 ///< Port 0 Bit 6 Overdrive Mode                     
#define P0ODEN_B6__NORMAL         0x00 ///< Configure P0.6 to normal overdrive mode.        
#define P0ODEN_B6__HIGH_IMPEDANCE 0x40 ///< Configure P0.6 to high-impedance overdrive mode.
                                                                                            
#define P0ODEN_B7__BMASK          0x80 ///< Port 0 Bit 7 Overdrive Mode                     
#define P0ODEN_B7__SHIFT          0x07 ///< Port 0 Bit 7 Overdrive Mode                     
#define P0ODEN_B7__NORMAL         0x00 ///< Configure P0.7 to normal overdrive mode.        
#define P0ODEN_B7__HIGH_IMPEDANCE 0x80 ///< Configure P0.7 to high-impedance overdrive mode.
                                                                                            
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
// ALARM4 Enums (RTC Alarm Programmed Value 4 @ 0x0C)
//------------------------------------------------------------------------------
#define ALARM4_ALARM4__FMASK 0xFF ///< RTC Alarm Programmed Value 4
#define ALARM4_ALARM4__SHIFT 0x00 ///< RTC Alarm Programmed Value 4
                                                                   
//------------------------------------------------------------------------------
// ALARM5 Enums (RTC Alarm Programmed Value 5 @ 0x0D)
//------------------------------------------------------------------------------
#define ALARM5_ALARM5__FMASK 0xFF ///< RTC Alarm Programmed Value 5
#define ALARM5_ALARM5__SHIFT 0x00 ///< RTC Alarm Programmed Value 5
                                                                   
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
// CAPTURE4 Enums (RTC Timer Capture 4 @ 0x04)
//------------------------------------------------------------------------------
#define CAPTURE4_CAPTURE4__FMASK 0xFF ///< RTC Timer Capture 4
#define CAPTURE4_CAPTURE4__SHIFT 0x00 ///< RTC Timer Capture 4
                                                              
//------------------------------------------------------------------------------
// CAPTURE5 Enums (RTC Timer Capture 5 @ 0x05)
//------------------------------------------------------------------------------
#define CAPTURE5_CAPTURE5__FMASK 0xFF ///< RTC Timer Capture 5
#define CAPTURE5_CAPTURE5__SHIFT 0x00 ///< RTC Timer Capture 5
                                                              
//------------------------------------------------------------------------------
// RAMADDR Enums (RTC Backup RAM Address @ 0x0E)
//------------------------------------------------------------------------------
#define RAMADDR_RAMADDR__FMASK 0xFF ///< RTC Backup RAM Address
#define RAMADDR_RAMADDR__SHIFT 0x00 ///< RTC Backup RAM Address
                                                               
//------------------------------------------------------------------------------
// RAMDATA Enums (RTC Backup RAM Data @ 0x0F)
//------------------------------------------------------------------------------
#define RAMDATA_RAMDATA__FMASK 0xFF ///< RTC Backup RAM Data
#define RAMDATA_RAMDATA__SHIFT 0x00 ///< RTC Backup RAM Data
                                                            
//------------------------------------------------------------------------------
// RTC0ADR Enums (RTC Address @ 0xAC)
//------------------------------------------------------------------------------
#define RTC0ADR_ADDR__FMASK             0x0F ///< RTC Indirect Register Address                     
#define RTC0ADR_ADDR__SHIFT             0x00 ///< RTC Indirect Register Address                     
#define RTC0ADR_ADDR__CAPTURE0          0x00 ///< Select the CAPTURE0 register.                     
#define RTC0ADR_ADDR__CAPTURE1          0x01 ///< Select the CAPTURE1 register.                     
#define RTC0ADR_ADDR__CAPTURE2          0x02 ///< Select the CAPTURE2 register.                     
#define RTC0ADR_ADDR__CAPTURE3          0x03 ///< Select the CAPTURE3 register.                     
#define RTC0ADR_ADDR__CAPTURE4          0x04 ///< Select the CAPTURE4 register.                     
#define RTC0ADR_ADDR__CAPTURE5          0x05 ///< Select the CAPTURE5 register.                     
#define RTC0ADR_ADDR__RTC0CN            0x06 ///< Select the RTC0CN register.                       
#define RTC0ADR_ADDR__RTC0XCN           0x07 ///< Select the RTC0XCN register.                      
#define RTC0ADR_ADDR__ALARM0            0x08 ///< Select the ALARM0 register.                       
#define RTC0ADR_ADDR__ALARM1            0x09 ///< Select the ALARM1 register.                       
#define RTC0ADR_ADDR__ALARM2            0x0A ///< Select the ALARM2 register.                       
#define RTC0ADR_ADDR__ALARM3            0x0B ///< Select the ALARM3 register.                       
#define RTC0ADR_ADDR__ALARM4            0x0C ///< Select the ALARM4 register.                       
#define RTC0ADR_ADDR__ALARM5            0x0D ///< Select the ALARM5 register.                       
#define RTC0ADR_ADDR__RAMADDR           0x0E ///< Select the RAMADDR register.                      
#define RTC0ADR_ADDR__RAMDATA           0x0F ///< Select the RAMDATA register.                      
                                                                                                    
#define RTC0ADR_SHORT__BMASK            0x10 ///< Short Strobe Enable                               
#define RTC0ADR_SHORT__SHIFT            0x04 ///< Short Strobe Enable                               
#define RTC0ADR_SHORT__DISABLED         0x00 ///< Disable short strobe.                             
#define RTC0ADR_SHORT__ENABLED          0x10 ///< Enable short strobe.                              
                                                                                                    
#define RTC0ADR_VREGEN__BMASK           0x20 ///< Backup Supply Voltage Regulator Enable            
#define RTC0ADR_VREGEN__SHIFT           0x05 ///< Backup Supply Voltage Regulator Enable            
#define RTC0ADR_VREGEN__BACKUP_DISABLED 0x00 ///< Disable the backup supply voltage regulator. The  
                                             ///< RTC is powered from VDD.                          
#define RTC0ADR_VREGEN__BACKUP_ENABLED  0x20 ///< Force the backup supply voltage regulator enabled.
                                             ///< The RTC is powered from VRTC-BACKUP.              
                                                                                                    
#define RTC0ADR_AUTORD__BMASK           0x40 ///< RTC Interface Autoread Enable                     
#define RTC0ADR_AUTORD__SHIFT           0x06 ///< RTC Interface Autoread Enable                     
#define RTC0ADR_AUTORD__DISABLED        0x00 ///< Disable autoread. Firmware must write the BUSY bit
                                             ///< for each RTC indirect read operation.             
#define RTC0ADR_AUTORD__ENABLED         0x40 ///< Enable autoread. The next RTC indirect read       
                                             ///< operation is initiated when firmware reads the    
                                             ///< RTC0DAT register.                                 
                                                                                                    
#define RTC0ADR_BUSY__BMASK             0x80 ///< RTC Interface Busy Indicator                      
#define RTC0ADR_BUSY__SHIFT             0x07 ///< RTC Interface Busy Indicator                      
#define RTC0ADR_BUSY__NOT_SET           0x00 ///< The RTC interface is not busy.                    
#define RTC0ADR_BUSY__SET               0x80 ///< The RTC interface is busy.                        
                                                                                                    
//------------------------------------------------------------------------------
// RTC0CN Enums (RTC Control @ 0x06)
//------------------------------------------------------------------------------
#define RTC0CN_RTCCAP__BMASK    0x01 ///< RTC Timer Capture                               
#define RTC0CN_RTCCAP__SHIFT    0x00 ///< RTC Timer Capture                               
#define RTC0CN_RTCCAP__NOT_SET  0x00 ///< Do not start a capture operation.               
#define RTC0CN_RTCCAP__SET      0x01 ///< Start a capture operation.                      
                                                                                          
#define RTC0CN_RTCSET__BMASK    0x02 ///< RTC Timer Set                                   
#define RTC0CN_RTCSET__SHIFT    0x01 ///< RTC Timer Set                                   
#define RTC0CN_RTCSET__NOT_SET  0x00 ///< Do not start a set operation.                   
#define RTC0CN_RTCSET__SET      0x02 ///< Start a set operation.                          
                                                                                          
#define RTC0CN_ALRM__BMASK      0x04 ///< RTC Alarm Event Flag and Auto Reset Enable      
#define RTC0CN_ALRM__SHIFT      0x02 ///< RTC Alarm Event Flag and Auto Reset Enable      
#define RTC0CN_ALRM__NOT_SET    0x00 ///< Alarm event flag is not set or disable the auto 
                                     ///< reset function.                                 
#define RTC0CN_ALRM__SET        0x04 ///< Alarm event flag is set or enable the auto reset
                                     ///< function.                                       
                                                                                          
#define RTC0CN_RTCAEN__BMASK    0x08 ///< RTC Alarm Enable                                
#define RTC0CN_RTCAEN__SHIFT    0x03 ///< RTC Alarm Enable                                
#define RTC0CN_RTCAEN__DISABLED 0x00 ///< Disable RTC alarm.                              
#define RTC0CN_RTCAEN__ENABLED  0x08 ///< Enable RTC alarm.                               
                                                                                          
#define RTC0CN_RTCTR__BMASK     0x10 ///< RTC Timer Run Control                           
#define RTC0CN_RTCTR__SHIFT     0x04 ///< RTC Timer Run Control                           
#define RTC0CN_RTCTR__STOP      0x00 ///< RTC timer is stopped.                           
#define RTC0CN_RTCTR__RUN       0x10 ///< RTC timer is running.                           
                                                                                          
#define RTC0CN_OSCFAIL__BMASK   0x20 ///< RTC Oscillator Fail Event Flag                  
#define RTC0CN_OSCFAIL__SHIFT   0x05 ///< RTC Oscillator Fail Event Flag                  
#define RTC0CN_OSCFAIL__NOT_SET 0x00 ///< Missing RTC detector timeout did not occur.     
#define RTC0CN_OSCFAIL__SET     0x20 ///< Missing RTC detector timeout occurred.          
                                                                                          
#define RTC0CN_MCLKEN__BMASK    0x40 ///< Missing RTC Detector Enable                     
#define RTC0CN_MCLKEN__SHIFT    0x06 ///< Missing RTC Detector Enable                     
#define RTC0CN_MCLKEN__DISABLED 0x00 ///< Disable missing RTC detector.                   
#define RTC0CN_MCLKEN__ENABLED  0x40 ///< Enable missing RTC detector.                    
                                                                                          
#define RTC0CN_RTCEN__BMASK     0x80 ///< RTC Enable                                      
#define RTC0CN_RTCEN__SHIFT     0x07 ///< RTC Enable                                      
#define RTC0CN_RTCEN__DISABLED  0x00 ///< Disable RTC oscillator.                         
#define RTC0CN_RTCEN__ENABLED   0x80 ///< Enable RTC oscillator.                          
                                                                                          
//------------------------------------------------------------------------------
// RTC0DAT Enums (RTC Data @ 0xAD)
//------------------------------------------------------------------------------
#define RTC0DAT_RTC0DAT__FMASK 0xFF ///< RTC Data
#define RTC0DAT_RTC0DAT__SHIFT 0x00 ///< RTC Data
                                                 
//------------------------------------------------------------------------------
// RTC0KEY Enums (RTC Lock and Key @ 0xAE)
//------------------------------------------------------------------------------
#define RTC0KEY_RTC0ST__FMASK           0xFF ///< RTC Interface Lock/Key and Status                 
#define RTC0KEY_RTC0ST__SHIFT           0x00 ///< RTC Interface Lock/Key and Status                 
#define RTC0KEY_RTC0ST__LOCKED          0x00 ///< RTC Interface is locked. Writing 0xA5 followed by 
                                             ///< 0xF1 unlocks the RTC interface.                   
#define RTC0KEY_RTC0ST__FIRST           0x01 ///< RTC Interface is locked, but 0xA5 has already been
                                             ///< written. Writing any value other than the second  
                                             ///< key code (0xF1) will change this field to 3 and   
                                             ///< disable the RTC interface until the next system   
                                             ///< reset.                                            
#define RTC0KEY_RTC0ST__UNLOCKED        0x02 ///< RTC Interface is unlocked. Any write to the       
                                             ///< RTC0KEY register will lock the RTC Interface.     
#define RTC0KEY_RTC0ST__DISABLED        0x03 ///< RTC Interface is disabled until the next system   
                                             ///< reset. Any writes to RTC0KEY have no effect.      
#define RTC0KEY_RTC0ST__DISABLE_OR_LOCK 0x0A ///< Writing any value other than 0xF1 for the second  
                                             ///< byte will disable the interface. Writing any value
                                             ///< when the interface is unlocked will lock the      
                                             ///< interface.                                        
#define RTC0KEY_RTC0ST__KEY1            0xA5 ///< Writing 0xA5 followed by 0xF1 unlocks the RTC     
                                             ///< interface.                                        
#define RTC0KEY_RTC0ST__KEY2            0xF1 ///< Writing 0xA5 followed by 0xF1 unlocks the RTC     
                                             ///< interface.                                        
                                                                                                    
//------------------------------------------------------------------------------
// RTC0XCN Enums (RTC Oscillator Control @ 0x07)
//------------------------------------------------------------------------------
#define RTC0XCN_VBATEN__BMASK         0x01 ///< RTC VBAT Indicator                                
#define RTC0XCN_VBATEN__SHIFT         0x00 ///< RTC VBAT Indicator                                
#define RTC0XCN_VBATEN__VDD           0x00 ///< RTC is powered from VDD.                          
#define RTC0XCN_VBATEN__VRTC_BACKUP   0x01 ///< RTC is powered from the VRTC-BACKUP supply.       
                                                                                                  
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
#define TMR2CN_T2XCLK__BMASK                      0x01 ///< Timer 2 External Clock Select                     
#define TMR2CN_T2XCLK__SHIFT                      0x00 ///< Timer 2 External Clock Select                     
#define TMR2CN_T2XCLK__SYSCLK_DIV_12              0x00 ///< Timer 2 clock is the system clock divided by 12.  
#define TMR2CN_T2XCLK__T2RCLK                     0x01 ///< Timer 2 clock is the clock defined by the T2RCLK  
                                                       ///< bit.                                              
                                                                                                              
#define TMR2CN_T2RCLK__BMASK                      0x02 ///< Timer 2 Capture Mode                              
#define TMR2CN_T2RCLK__SHIFT                      0x01 ///< Timer 2 Capture Mode                              
#define TMR2CN_T2RCLK__EXTOSC_DIV_8_CAP_RTC_DIV_8 0x00 ///< Capture trigger is RTC / 8. If T2XCLK = 1 and T2ML
                                                       ///< = 0, external clock is EXTOSC / 8.                
#define TMR2CN_T2RCLK__RTC_DIV_8_CAP_EXTOSC_DIV_8 0x02 ///< Capture trigger is EXTOSC / 8. If T2XCLK = 1 and  
                                                       ///< T2ML = 0, external clock is RTC / 8.              
                                                                                                              
#define TMR2CN_TR2__BMASK                         0x04 ///< Timer 2 Run Control                               
#define TMR2CN_TR2__SHIFT                         0x02 ///< Timer 2 Run Control                               
#define TMR2CN_TR2__STOP                          0x00 ///< Stop Timer 2.                                     
#define TMR2CN_TR2__RUN                           0x04 ///< Start Timer 2 running.                            
                                                                                                              
#define TMR2CN_T2SPLIT__BMASK                     0x08 ///< Timer 2 Split Mode Enable                         
#define TMR2CN_T2SPLIT__SHIFT                     0x03 ///< Timer 2 Split Mode Enable                         
#define TMR2CN_T2SPLIT__16_BIT_RELOAD             0x00 ///< Timer 2 operates in 16-bit auto-reload mode.      
#define TMR2CN_T2SPLIT__8_BIT_RELOAD              0x08 ///< Timer 2 operates as two 8-bit auto-reload timers. 
                                                                                                              
#define TMR2CN_TF2CEN__BMASK                      0x10 ///< Timer 2 Capture Enable                            
#define TMR2CN_TF2CEN__SHIFT                      0x04 ///< Timer 2 Capture Enable                            
#define TMR2CN_TF2CEN__DISABLED                   0x00 ///< Disable capture mode.                             
#define TMR2CN_TF2CEN__ENABLED                    0x10 ///< Enable capture mode.                              
                                                                                                              
#define TMR2CN_TF2LEN__BMASK                      0x20 ///< Timer 2 Low Byte Interrupt Enable                 
#define TMR2CN_TF2LEN__SHIFT                      0x05 ///< Timer 2 Low Byte Interrupt Enable                 
#define TMR2CN_TF2LEN__DISABLED                   0x00 ///< Disable low byte interrupts.                      
#define TMR2CN_TF2LEN__ENABLED                    0x20 ///< Enable low byte interrupts.                       
                                                                                                              
#define TMR2CN_TF2L__BMASK                        0x40 ///< Timer 2 Low Byte Overflow Flag                    
#define TMR2CN_TF2L__SHIFT                        0x06 ///< Timer 2 Low Byte Overflow Flag                    
#define TMR2CN_TF2L__NOT_SET                      0x00 ///< Timer 2 low byte did not overflow.                
#define TMR2CN_TF2L__SET                          0x40 ///< Timer 2 low byte overflowed.                      
                                                                                                              
#define TMR2CN_TF2H__BMASK                        0x80 ///< Timer 2 High Byte Overflow Flag                   
#define TMR2CN_TF2H__SHIFT                        0x07 ///< Timer 2 High Byte Overflow Flag                   
#define TMR2CN_TF2H__NOT_SET                      0x00 ///< Timer 2 8-bit high byte or 16-bit value did not   
                                                       ///< overflow.                                         
#define TMR2CN_TF2H__SET                          0x80 ///< Timer 2 8-bit high byte or 16-bit value           
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
#define TMR3CN_T3XCLK__BMASK                      0x01 ///< Timer 3 External Clock Select                     
#define TMR3CN_T3XCLK__SHIFT                      0x00 ///< Timer 3 External Clock Select                     
#define TMR3CN_T3XCLK__SYSCLK_DIV_12              0x00 ///< Timer 3 clock is the system clock divided by 12.  
#define TMR3CN_T3XCLK__T3RCLK                     0x01 ///< Timer 3 clock is the clock defined by the T3RCLK  
                                                       ///< bit.                                              
                                                                                                              
#define TMR3CN_T3RCLK__BMASK                      0x02 ///< Timer 3 Capture Mode                              
#define TMR3CN_T3RCLK__SHIFT                      0x01 ///< Timer 3 Capture Mode                              
#define TMR3CN_T3RCLK__EXTOSC_DIV_8_CAP_RTC_DIV_8 0x00 ///< Capture trigger is RTC / 8. If T3XCLK = 1 and T3ML
                                                       ///< = 0, external clock is EXTOSC / 8.                
#define TMR3CN_T3RCLK__RTC_DIV_8_CAP_EXTOSC_DIV_8 0x02 ///< Capture trigger is EXTOSC / 8. If T3XCLK = 1 and  
                                                       ///< T3ML = 0, external clock is RTC / 8.              
                                                                                                              
#define TMR3CN_TR3__BMASK                         0x04 ///< Timer 3 Run Control                               
#define TMR3CN_TR3__SHIFT                         0x02 ///< Timer 3 Run Control                               
#define TMR3CN_TR3__STOP                          0x00 ///< Stop Timer 3.                                     
#define TMR3CN_TR3__RUN                           0x04 ///< Start Timer 3 running.                            
                                                                                                              
#define TMR3CN_T3SPLIT__BMASK                     0x08 ///< Timer 3 Split Mode Enable                         
#define TMR3CN_T3SPLIT__SHIFT                     0x03 ///< Timer 3 Split Mode Enable                         
#define TMR3CN_T3SPLIT__16_BIT_RELOAD             0x00 ///< Timer 3 operates in 16-bit auto-reload mode.      
#define TMR3CN_T3SPLIT__8_BIT_RELOAD              0x08 ///< Timer 3 operates as two 8-bit auto-reload timers. 
                                                                                                              
#define TMR3CN_TF3CEN__BMASK                      0x10 ///< Timer 3 Capture Enable                            
#define TMR3CN_TF3CEN__SHIFT                      0x04 ///< Timer 3 Capture Enable                            
#define TMR3CN_TF3CEN__DISABLED                   0x00 ///< Disable capture mode.                             
#define TMR3CN_TF3CEN__ENABLED                    0x10 ///< Enable capture mode.                              
                                                                                                              
#define TMR3CN_TF3LEN__BMASK                      0x20 ///< Timer 3 Low Byte Interrupt Enable                 
#define TMR3CN_TF3LEN__SHIFT                      0x05 ///< Timer 3 Low Byte Interrupt Enable                 
#define TMR3CN_TF3LEN__DISABLED                   0x00 ///< Disable low byte interrupts.                      
#define TMR3CN_TF3LEN__ENABLED                    0x20 ///< Enable low byte interrupts.                       
                                                                                                              
#define TMR3CN_TF3L__BMASK                        0x40 ///< Timer 3 Low Byte Overflow Flag                    
#define TMR3CN_TF3L__SHIFT                        0x06 ///< Timer 3 Low Byte Overflow Flag                    
#define TMR3CN_TF3L__NOT_SET                      0x00 ///< Timer 3 low byte did not overflow.                
#define TMR3CN_TF3L__SET                          0x40 ///< Timer 3 low byte overflowed.                      
                                                                                                              
#define TMR3CN_TF3H__BMASK                        0x80 ///< Timer 3 High Byte Overflow Flag                   
#define TMR3CN_TF3H__SHIFT                        0x07 ///< Timer 3 High Byte Overflow Flag                   
#define TMR3CN_TF3H__NOT_SET                      0x00 ///< Timer 3 8-bit high byte or 16-bit value did not   
                                                       ///< overflow.                                         
#define TMR3CN_TF3H__SET                          0x80 ///< Timer 3 8-bit high byte or 16-bit value           
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
                                                                                                
#define REF0CN_GF__BMASK            0x40 ///< General Purpose Flag                              
#define REF0CN_GF__SHIFT            0x06 ///< General Purpose Flag                              
#define REF0CN_GF__NOT_SET          0x00 ///< The GF flag is not set. Clear the GF flag.        
#define REF0CN_GF__SET              0x40 ///< The GF flag is set. Set the GF flag.              
                                                                                                
#define REF0CN_IDAMRG__BMASK        0x80 ///< IDAC Output Merge Select                          
#define REF0CN_IDAMRG__SHIFT        0x07 ///< IDAC Output Merge Select                          
#define REF0CN_IDAMRG__SEPARATED    0x00 ///< IDAC1 output is separate from the IDAC0 output.   
#define REF0CN_IDAMRG__MERGED       0x80 ///< IDAC1 output is merged with the IDAC0 output on   
                                         ///< the same pin as IDAC0.0.                          
                                                                                                
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
#define REG0CN_REGMD__2P5       0x10 ///< Voltage Regulator output is 2.5 V.      
                                                                                  
#define REG0CN_REGDIS__BMASK    0x80 ///< Voltage Regulator Disable               
#define REG0CN_REGDIS__SHIFT    0x07 ///< Voltage Regulator Disable               
#define REG0CN_REGDIS__ENABLED  0x00 ///< Enable the Voltage Regulator.           
#define REG0CN_REGDIS__DISABLED 0x80 ///< Disable the Voltage Regulator.          
                                                                                  
//------------------------------------------------------------------------------
// EMI0CN Enums (External Memory Interface Control @ 0xAA)
//------------------------------------------------------------------------------
#define EMI0CN_PGSEL__FMASK 0x07 ///< XRAM Page Select
#define EMI0CN_PGSEL__SHIFT 0x00 ///< XRAM Page Select
                                                      
#endif // SI_C8051F410_REGISTER_ENUMS_H
//-eof--------------------------------------------------------------------------

