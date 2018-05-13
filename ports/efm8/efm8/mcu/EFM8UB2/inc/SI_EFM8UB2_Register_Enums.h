//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  EFM8UB20F32G_QFN32
//  EFM8UB20F32G_QFP32
//  EFM8UB20F32G_QFP48
//  EFM8UB20F64G_QFN32
//  EFM8UB20F64G_QFP32
//  EFM8UB20F64G_QFP48

#ifndef SI_EFM8UB2_REGISTER_ENUMS_H
#define SI_EFM8UB2_REGISTER_ENUMS_H

//Standard device includes
#include "SI_EFM8UB2_Defs.h"
//------------------------------------------------------------------------------
// ADC0CF Enums (ADC0 Configuration @ 0xBC)
//------------------------------------------------------------------------------
#define ADC0CF_ADLJST__BMASK           0x04 ///< ADC0 Left Justify Select                   
#define ADC0CF_ADLJST__SHIFT           0x02 ///< ADC0 Left Justify Select                   
#define ADC0CF_ADLJST__RIGHT_JUSTIFIED 0x00 ///< Data in the ADC0H:ADC0L registers is right-
                                            ///< justified.                                 
#define ADC0CF_ADLJST__LEFT_JUSTIFIED  0x04 ///< Data in the ADC0H:ADC0L registers is left- 
                                            ///< justified.                                 
                                                                                            
#define ADC0CF_ADSC__FMASK             0xF8 ///< SAR Clock Divider                          
#define ADC0CF_ADSC__SHIFT             0x03 ///< SAR Clock Divider                          
                                                                                            
//------------------------------------------------------------------------------
// ADC0CN0 Enums (ADC0 Control @ 0xE8)
//------------------------------------------------------------------------------
#define ADC0CN0_ADCM__FMASK         0x07 ///< Start of Conversion Mode Select                   
#define ADC0CN0_ADCM__SHIFT         0x00 ///< Start of Conversion Mode Select                   
#define ADC0CN0_ADCM__ADBUSY        0x00 ///< ADC0 conversion initiated on write of 1 to ADBUSY.
#define ADC0CN0_ADCM__TIMER0        0x01 ///< ADC0 conversion initiated on overflow of Timer 0. 
#define ADC0CN0_ADCM__TIMER2        0x02 ///< ADC0 conversion initiated on overflow of Timer 2. 
#define ADC0CN0_ADCM__TIMER1        0x03 ///< ADC0 conversion initiated on overflow of Timer 1. 
#define ADC0CN0_ADCM__CNVSTR        0x04 ///< ADC0 conversion initiated on rising edge of       
                                         ///< CNVSTR.                                           
#define ADC0CN0_ADCM__TIMER3        0x05 ///< ADC0 conversion initiated on overflow of Timer 3. 
#define ADC0CN0_ADCM__TIMER4        0x06 ///< ADC0 conversion initiated on overflow of Timer 4. 
#define ADC0CN0_ADCM__TIMER5        0x07 ///< ADC0 conversion initiated on overflow of Timer 5. 
                                                                                                
#define ADC0CN0_ADWINT__BMASK       0x08 ///< Window Compare Interrupt Flag                     
#define ADC0CN0_ADWINT__SHIFT       0x03 ///< Window Compare Interrupt Flag                     
#define ADC0CN0_ADWINT__NOT_SET     0x00 ///< An ADC window compare event did not occur.        
#define ADC0CN0_ADWINT__SET         0x08 ///< An ADC window compare event occurred.             
                                                                                                
#define ADC0CN0_ADBUSY__BMASK       0x10 ///< ADC Busy                                          
#define ADC0CN0_ADBUSY__SHIFT       0x04 ///< ADC Busy                                          
#define ADC0CN0_ADBUSY__NOT_SET     0x00 ///< An ADC0 conversion is not currently in progress.  
#define ADC0CN0_ADBUSY__SET         0x10 ///< ADC0 conversion is in progress or start an ADC0   
                                         ///< conversion.                                       
                                                                                                
#define ADC0CN0_ADINT__BMASK        0x20 ///< Conversion Complete Interrupt Flag                
#define ADC0CN0_ADINT__SHIFT        0x05 ///< Conversion Complete Interrupt Flag                
#define ADC0CN0_ADINT__NOT_SET      0x00 ///< ADC0 has not completed a conversion since the last
                                         ///< time ADINT was cleared.                           
#define ADC0CN0_ADINT__SET          0x20 ///< ADC0 completed a data conversion.                 
                                                                                                
#define ADC0CN0_ADTM__BMASK         0x40 ///< Track Mode                                        
#define ADC0CN0_ADTM__SHIFT         0x06 ///< Track Mode                                        
#define ADC0CN0_ADTM__TRACK_NORMAL  0x00 ///< Normal Track Mode. When ADC0 is enabled,          
                                         ///< conversion begins immediately following the start-
                                         ///< of-conversion signal.                             
#define ADC0CN0_ADTM__TRACK_DELAYED 0x40 ///< Delayed Track Mode. When ADC0 is enabled,         
                                         ///< conversion begins 3 SAR clock cycles following the
                                         ///< start-of-conversion signal. The ADC is allowed to 
                                         ///< track during this time. Note that there is not a  
                                         ///< tracking delay when the external conversion start 
                                         ///< (CNVSTR) is used as the start-of-conversion       
                                         ///< source.                                           
                                                                                                
#define ADC0CN0_ADEN__BMASK         0x80 ///< ADC Enable                                        
#define ADC0CN0_ADEN__SHIFT         0x07 ///< ADC Enable                                        
#define ADC0CN0_ADEN__DISABLED      0x00 ///< ADC0 Disabled (low-power shutdown).               
#define ADC0CN0_ADEN__ENABLED       0x80 ///< ADC0 Enabled (active and ready for data           
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
// AMX0N Enums (AMUX0 Negative Multiplexer Selection @ 0xBA)
//------------------------------------------------------------------------------
#define AMX0N_AMX0N__FMASK   0x3F ///< AMUX0 Negative Input Selection
#define AMX0N_AMX0N__SHIFT   0x00 ///< AMUX0 Negative Input Selection
#define AMX0N_AMX0N__ADC0N0  0x00 ///< Select ADC0N.0.               
#define AMX0N_AMX0N__ADC0N1  0x01 ///< Select ADC0N.1.               
#define AMX0N_AMX0N__ADC0N2  0x02 ///< Select ADC0N.2.               
#define AMX0N_AMX0N__ADC0N3  0x03 ///< Select ADC0N.3.               
#define AMX0N_AMX0N__ADC0N4  0x04 ///< Select ADC0N.4.               
#define AMX0N_AMX0N__ADC0N5  0x05 ///< Select ADC0N.5.               
#define AMX0N_AMX0N__ADC0N6  0x06 ///< Select ADC0N.6.               
#define AMX0N_AMX0N__ADC0N7  0x07 ///< Select ADC0N.7.               
#define AMX0N_AMX0N__ADC0N8  0x08 ///< Select ADC0N.8.               
#define AMX0N_AMX0N__ADC0N9  0x09 ///< Select ADC0N.9.               
#define AMX0N_AMX0N__ADC0N10 0x0A ///< Select ADC0N.10.              
#define AMX0N_AMX0N__ADC0N11 0x0B ///< Select ADC0N.11.              
#define AMX0N_AMX0N__ADC0N12 0x0C ///< Select ADC0N.12.              
#define AMX0N_AMX0N__ADC0N13 0x0D ///< Select ADC0N.13.              
#define AMX0N_AMX0N__ADC0N14 0x0E ///< Select ADC0N.14.              
#define AMX0N_AMX0N__ADC0N15 0x0F ///< Select ADC0N.15.              
#define AMX0N_AMX0N__ADC0N16 0x10 ///< Select ADC0N.16.              
#define AMX0N_AMX0N__ADC0N17 0x11 ///< Select ADC0N.17.              
#define AMX0N_AMX0N__ADC0N18 0x12 ///< Select ADC0N.18.              
#define AMX0N_AMX0N__ADC0N19 0x13 ///< Select ADC0N.19.              
#define AMX0N_AMX0N__ADC0N20 0x14 ///< Select ADC0N.20.              
#define AMX0N_AMX0N__ADC0N21 0x15 ///< Select ADC0N.21.              
#define AMX0N_AMX0N__ADC0N22 0x16 ///< Select ADC0N.22.              
#define AMX0N_AMX0N__ADC0N23 0x17 ///< Select ADC0N.23.              
#define AMX0N_AMX0N__ADC0N24 0x18 ///< Select ADC0N.24.              
#define AMX0N_AMX0N__ADC0N25 0x19 ///< Select ADC0N.25.              
#define AMX0N_AMX0N__ADC0N26 0x1A ///< Select ADC0N.26.              
#define AMX0N_AMX0N__ADC0N27 0x1B ///< Select ADC0N.27.              
#define AMX0N_AMX0N__ADC0N28 0x1C ///< Select ADC0N.28.              
#define AMX0N_AMX0N__ADC0N29 0x1D ///< Select ADC0N.29.              
#define AMX0N_AMX0N__VREF    0x1E ///< Internal Voltage Reference.   
#define AMX0N_AMX0N__GND     0x1F ///< Ground (single-ended mode).   
#define AMX0N_AMX0N__ADC0N32 0x20 ///< Select ADC0N.32.              
#define AMX0N_AMX0N__ADC0N33 0x21 ///< Select ADC0N.33.              
#define AMX0N_AMX0N__ADC0N34 0x22 ///< Select ADC0N.34.              
                                                                     
//------------------------------------------------------------------------------
// AMX0P Enums (AMUX0 Positive Multiplexer Selection @ 0xBB)
//------------------------------------------------------------------------------
#define AMX0P_AMX0P__FMASK   0x3F ///< AMUX0 Positive Input Selection
#define AMX0P_AMX0P__SHIFT   0x00 ///< AMUX0 Positive Input Selection
#define AMX0P_AMX0P__ADC0P0  0x00 ///< Select ADC0P.0.               
#define AMX0P_AMX0P__ADC0P1  0x01 ///< Select ADC0P.1.               
#define AMX0P_AMX0P__ADC0P2  0x02 ///< Select ADC0P.2.               
#define AMX0P_AMX0P__ADC0P3  0x03 ///< Select ADC0P.3.               
#define AMX0P_AMX0P__ADC0P4  0x04 ///< Select ADC0P.4.               
#define AMX0P_AMX0P__ADC0P5  0x05 ///< Select ADC0P.5.               
#define AMX0P_AMX0P__ADC0P6  0x06 ///< Select ADC0P.6.               
#define AMX0P_AMX0P__ADC0P7  0x07 ///< Select ADC0P.7.               
#define AMX0P_AMX0P__ADC0P8  0x08 ///< Select ADC0P.8.               
#define AMX0P_AMX0P__ADC0P9  0x09 ///< Select ADC0P.9.               
#define AMX0P_AMX0P__ADC0P10 0x0A ///< Select ADC0P.10.              
#define AMX0P_AMX0P__ADC0P11 0x0B ///< Select ADC0P.11.              
#define AMX0P_AMX0P__ADC0P12 0x0C ///< Select ADC0P.12.              
#define AMX0P_AMX0P__ADC0P13 0x0D ///< Select ADC0P.13.              
#define AMX0P_AMX0P__ADC0P14 0x0E ///< Select ADC0P.14.              
#define AMX0P_AMX0P__ADC0P15 0x0F ///< Select ADC0P.15.              
#define AMX0P_AMX0P__ADC0P16 0x10 ///< Select ADC0P.16.              
#define AMX0P_AMX0P__ADC0P17 0x11 ///< Select ADC0P.17.              
#define AMX0P_AMX0P__ADC0P18 0x12 ///< Select ADC0P.18.              
#define AMX0P_AMX0P__ADC0P19 0x13 ///< Select ADC0P.19.              
#define AMX0P_AMX0P__ADC0P20 0x14 ///< Select ADC0P.20.              
#define AMX0P_AMX0P__ADC0P21 0x15 ///< Select ADC0P.21.              
#define AMX0P_AMX0P__ADC0P22 0x16 ///< Select ADC0P.22.              
#define AMX0P_AMX0P__ADC0P23 0x17 ///< Select ADC0P.23.              
#define AMX0P_AMX0P__ADC0P24 0x18 ///< Select ADC0P.24.              
#define AMX0P_AMX0P__ADC0P25 0x19 ///< Select ADC0P.25.              
#define AMX0P_AMX0P__ADC0P26 0x1A ///< Select ADC0P.26.              
#define AMX0P_AMX0P__ADC0P27 0x1B ///< Select ADC0P.27.              
#define AMX0P_AMX0P__ADC0P28 0x1C ///< Select ADC0P.28.              
#define AMX0P_AMX0P__ADC0P29 0x1D ///< Select ADC0P.29.              
#define AMX0P_AMX0P__TEMP    0x1E ///< Temperature sensor.           
#define AMX0P_AMX0P__VDD     0x1F ///< VDD Supply Voltage.           
#define AMX0P_AMX0P__ADC0P32 0x20 ///< Select ADC0P.32.              
#define AMX0P_AMX0P__ADC0P33 0x21 ///< Select ADC0P.33.              
#define AMX0P_AMX0P__ADC0P34 0x22 ///< Select ADC0P.34.              
                                                                     
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
// PFE0CN Enums (Prefetch Engine Control @ 0xAF)
//------------------------------------------------------------------------------
#define PFE0CN_FLBWE__BMASK                0x01 ///< Flash Block Write Enable                      
#define PFE0CN_FLBWE__SHIFT                0x00 ///< Flash Block Write Enable                      
#define PFE0CN_FLBWE__BLOCK_WRITE_DISABLED 0x00 ///< Each byte of a firmware flash write is written
                                                ///< individually.                                 
#define PFE0CN_FLBWE__BLOCK_WRITE_ENABLED  0x01 ///< Flash bytes are written in groups of two.     
                                                                                                   
#define PFE0CN_PFEN__BMASK                 0x20 ///< Prefetch Enable                               
#define PFE0CN_PFEN__SHIFT                 0x05 ///< Prefetch Enable                               
#define PFE0CN_PFEN__DISABLED              0x00 ///< Disable the prefetch engine (SYSCLK < 25 MHz).
#define PFE0CN_PFEN__ENABLED               0x20 ///< Enable the prefetch engine (SYSCLK > 25 MHz). 
                                                                                                   
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
// CLKSEL Enums (Clock Select @ 0xA9)
//------------------------------------------------------------------------------
#define CLKSEL_CLKSL__FMASK               0x07 ///< System Clock Source Select Bits                   
#define CLKSEL_CLKSL__SHIFT               0x00 ///< System Clock Source Select Bits                   
#define CLKSEL_CLKSL__DIVIDED_HFOSC_DIV_4 0x00 ///< Clock (SYSCLK) derived from the Internal High-    
                                               ///< Frequency Oscillator / 4 and scaled per the IFCN  
                                               ///< bits in register OSCICN.                          
#define CLKSEL_CLKSL__EXTOSC              0x01 ///< Clock (SYSCLK) derived from the External          
                                               ///< Oscillator circuit.                               
#define CLKSEL_CLKSL__HFOSC_DIV_2         0x02 ///< Clock (SYSCLK) derived from the Internal High-    
                                               ///< Frequency Oscillator / 2.                         
#define CLKSEL_CLKSL__HFOSC               0x03 ///< Clock (SYSCLK) derived from the Internal High-    
                                               ///< Frequency Oscillator.                             
#define CLKSEL_CLKSL__LFOSC               0x04 ///< Clock (SYSCLK) derived from the Internal Low-     
                                               ///< Frequency Oscillator and scaled per the OSCLD bits
                                               ///< in register OSCLCN.                               
                                                                                                      
#define CLKSEL_OUTCLK__BMASK              0x08 ///< Crossbar Clock Out Select                         
#define CLKSEL_OUTCLK__SHIFT              0x03 ///< Crossbar Clock Out Select                         
#define CLKSEL_OUTCLK__SYSCLK             0x00 ///< Enabling the Crossbar SYSCLK signal outputs       
                                               ///< SYSCLK.                                           
#define CLKSEL_OUTCLK__SYSCLK_SYNC_IO     0x08 ///< Enabling the Crossbar SYSCLK signal outputs SYSCLK
                                               ///< synchronized with the Port I/O.                   
                                                                                                      
#define CLKSEL_USBCLK__FMASK              0x70 ///< USB Clock Source Select Bits                      
#define CLKSEL_USBCLK__SHIFT              0x04 ///< USB Clock Source Select Bits                      
#define CLKSEL_USBCLK__HFOSC              0x00 ///< USB clock (USBCLK) derived from the Internal High-
                                               ///< Frequency Oscillator.                             
#define CLKSEL_USBCLK__HFOSC_DIV_8        0x10 ///< USB clock (USBCLK) derived from the Internal High-
                                               ///< Frequency Oscillator / 8.                         
#define CLKSEL_USBCLK__EXTOSC             0x20 ///< USB clock (USBCLK) derived from the External      
                                               ///< Oscillator.                                       
#define CLKSEL_USBCLK__EXTOSC_DIV_2       0x30 ///< USB clock (USBCLK) derived from the External      
                                               ///< Oscillator / 2.                                   
#define CLKSEL_USBCLK__EXTOSC_DIV_3       0x40 ///< USB clock (USBCLK) derived from the External      
                                               ///< Oscillator / 3.                                   
#define CLKSEL_USBCLK__EXTOSC_DIV_4       0x50 ///< USB clock (USBCLK) derived from the External      
                                               ///< Oscillator / 4.                                   
#define CLKSEL_USBCLK__LFOSC              0x60 ///< USB clock (USBCLK) derived from the Internal Low- 
                                               ///< Frequency Oscillator.                             
                                                                                                      
//------------------------------------------------------------------------------
// CMP0CN0 Enums (Comparator 0 Control 0 @ 0x9B)
//------------------------------------------------------------------------------
#define CMP0CN0_CPHYN__FMASK                0x03 ///< Comparator Negative Hysteresis Control            
#define CMP0CN0_CPHYN__SHIFT                0x00 ///< Comparator Negative Hysteresis Control            
#define CMP0CN0_CPHYN__DISABLED             0x00 ///< Negative Hysteresis disabled.                     
#define CMP0CN0_CPHYN__ENABLED_MODE1        0x01 ///< Negative Hysteresis = Hysteresis 1.               
#define CMP0CN0_CPHYN__ENABLED_MODE2        0x02 ///< Negative Hysteresis = Hysteresis 2.               
#define CMP0CN0_CPHYN__ENABLED_MODE3        0x03 ///< Negative Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                        
#define CMP0CN0_CPHYP__FMASK                0x0C ///< Comparator Positive Hysteresis Control            
#define CMP0CN0_CPHYP__SHIFT                0x02 ///< Comparator Positive Hysteresis Control            
#define CMP0CN0_CPHYP__DISABLED             0x00 ///< Positive Hysteresis disabled.                     
#define CMP0CN0_CPHYP__ENABLED_MODE1        0x04 ///< Positive Hysteresis = Hysteresis 1.               
#define CMP0CN0_CPHYP__ENABLED_MODE2        0x08 ///< Positive Hysteresis = Hysteresis 2.               
#define CMP0CN0_CPHYP__ENABLED_MODE3        0x0C ///< Positive Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                        
#define CMP0CN0_CPFIF__BMASK                0x10 ///< Comparator Falling-Edge Flag                      
#define CMP0CN0_CPFIF__SHIFT                0x04 ///< Comparator Falling-Edge Flag                      
#define CMP0CN0_CPFIF__NOT_SET              0x00 ///< No comparator falling edge has occurred since this
                                                 ///< flag was last cleared.                            
#define CMP0CN0_CPFIF__FALLING_EDGE         0x10 ///< Comparator falling edge has occurred.             
                                                                                                        
#define CMP0CN0_CPRIF__BMASK                0x20 ///< Comparator Rising-Edge Flag                       
#define CMP0CN0_CPRIF__SHIFT                0x05 ///< Comparator Rising-Edge Flag                       
#define CMP0CN0_CPRIF__NOT_SET              0x00 ///< No comparator rising edge has occurred since this 
                                                 ///< flag was last cleared.                            
#define CMP0CN0_CPRIF__RISING_EDGE          0x20 ///< Comparator rising edge has occurred.              
                                                                                                        
#define CMP0CN0_CPOUT__BMASK                0x40 ///< Comparator Output State Flag                      
#define CMP0CN0_CPOUT__SHIFT                0x06 ///< Comparator Output State Flag                      
#define CMP0CN0_CPOUT__POS_LESS_THAN_NEG    0x00 ///< Voltage on CP0P < CP0N.                           
#define CMP0CN0_CPOUT__POS_GREATER_THAN_NEG 0x40 ///< Voltage on CP0P > CP0N.                           
                                                                                                        
#define CMP0CN0_CPEN__BMASK                 0x80 ///< Comparator Enable                                 
#define CMP0CN0_CPEN__SHIFT                 0x07 ///< Comparator Enable                                 
#define CMP0CN0_CPEN__DISABLED              0x00 ///< Comparator disabled.                              
#define CMP0CN0_CPEN__ENABLED               0x80 ///< Comparator enabled.                               
                                                                                                        
//------------------------------------------------------------------------------
// CMP0MD Enums (Comparator 0 Mode @ 0x9D)
//------------------------------------------------------------------------------
#define CMP0MD_CPMD__FMASK              0x03 ///< Comparator Mode Select                      
#define CMP0MD_CPMD__SHIFT              0x00 ///< Comparator Mode Select                      
#define CMP0MD_CPMD__MODE0              0x00 ///< Mode 0 (Fastest Response Time, Highest Power
                                             ///< Consumption)                                
#define CMP0MD_CPMD__MODE1              0x01 ///< Mode 1                                      
#define CMP0MD_CPMD__MODE2              0x02 ///< Mode 2                                      
#define CMP0MD_CPMD__MODE3              0x03 ///< Mode 3 (Slowest Response Time, Lowest Power 
                                             ///< Consumption)                                
                                                                                              
#define CMP0MD_CPFIE__BMASK             0x10 ///< Comparator Falling-Edge Interrupt Enable    
#define CMP0MD_CPFIE__SHIFT             0x04 ///< Comparator Falling-Edge Interrupt Enable    
#define CMP0MD_CPFIE__FALL_INT_DISABLED 0x00 ///< Comparator falling-edge interrupt disabled. 
#define CMP0MD_CPFIE__FALL_INT_ENABLED  0x10 ///< Comparator falling-edge interrupt enabled.  
                                                                                              
#define CMP0MD_CPRIE__BMASK             0x20 ///< Comparator Rising-Edge Interrupt Enable     
#define CMP0MD_CPRIE__SHIFT             0x05 ///< Comparator Rising-Edge Interrupt Enable     
#define CMP0MD_CPRIE__RISE_INT_DISABLED 0x00 ///< Comparator rising-edge interrupt disabled.  
#define CMP0MD_CPRIE__RISE_INT_ENABLED  0x20 ///< Comparator rising-edge interrupt enabled.   
                                                                                              
//------------------------------------------------------------------------------
// CMP0MX Enums (Comparator 0 Multiplexer Selection @ 0x9F)
//------------------------------------------------------------------------------
#define CMP0MX_CMXP__FMASK  0x07 ///< Comparator Positive Input MUX Selection
#define CMP0MX_CMXP__SHIFT  0x00 ///< Comparator Positive Input MUX Selection
#define CMP0MX_CMXP__CMP0P0 0x00 ///< External pin CMP0P.0.                  
#define CMP0MX_CMXP__CMP0P1 0x01 ///< External pin CMP0P.1.                  
#define CMP0MX_CMXP__CMP0P2 0x02 ///< External pin CMP0P.2.                  
#define CMP0MX_CMXP__CMP0P3 0x03 ///< External pin CMP0P.3.                  
#define CMP0MX_CMXP__CMP0P4 0x04 ///< External pin CMP0P.4.                  
                                                                             
#define CMP0MX_CMXN__FMASK  0x70 ///< Comparator Negative Input MUX Selection
#define CMP0MX_CMXN__SHIFT  0x04 ///< Comparator Negative Input MUX Selection
#define CMP0MX_CMXN__CMP0N0 0x00 ///< External pin CMP0N.0.                  
#define CMP0MX_CMXN__CMP0N1 0x10 ///< External pin CMP0N.1.                  
#define CMP0MX_CMXN__CMP0N2 0x20 ///< External pin CMP0N.2.                  
#define CMP0MX_CMXN__CMP0N3 0x30 ///< External pin CMP0N.3.                  
#define CMP0MX_CMXN__CMP0N4 0x40 ///< External pin CMP0N.4.                  
                                                                             
//------------------------------------------------------------------------------
// CMP1CN0 Enums (Comparator 1 Control 0 @ 0x9A)
//------------------------------------------------------------------------------
#define CMP1CN0_CPHYN__FMASK                0x03 ///< Comparator Negative Hysteresis Control            
#define CMP1CN0_CPHYN__SHIFT                0x00 ///< Comparator Negative Hysteresis Control            
#define CMP1CN0_CPHYN__DISABLED             0x00 ///< Negative Hysteresis disabled.                     
#define CMP1CN0_CPHYN__ENABLED_MODE1        0x01 ///< Negative Hysteresis = Hysteresis 1.               
#define CMP1CN0_CPHYN__ENABLED_MODE2        0x02 ///< Negative Hysteresis = Hysteresis 2.               
#define CMP1CN0_CPHYN__ENABLED_MODE3        0x03 ///< Negative Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                        
#define CMP1CN0_CPHYP__FMASK                0x0C ///< Comparator Positive Hysteresis Control            
#define CMP1CN0_CPHYP__SHIFT                0x02 ///< Comparator Positive Hysteresis Control            
#define CMP1CN0_CPHYP__DISABLED             0x00 ///< Positive Hysteresis disabled.                     
#define CMP1CN0_CPHYP__ENABLED_MODE1        0x04 ///< Positive Hysteresis = Hysteresis 1.               
#define CMP1CN0_CPHYP__ENABLED_MODE2        0x08 ///< Positive Hysteresis = Hysteresis 2.               
#define CMP1CN0_CPHYP__ENABLED_MODE3        0x0C ///< Positive Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                        
#define CMP1CN0_CPFIF__BMASK                0x10 ///< Comparator Falling-Edge Flag                      
#define CMP1CN0_CPFIF__SHIFT                0x04 ///< Comparator Falling-Edge Flag                      
#define CMP1CN0_CPFIF__NOT_SET              0x00 ///< No comparator falling edge has occurred since this
                                                 ///< flag was last cleared.                            
#define CMP1CN0_CPFIF__FALLING_EDGE         0x10 ///< Comparator falling edge has occurred.             
                                                                                                        
#define CMP1CN0_CPRIF__BMASK                0x20 ///< Comparator Rising-Edge Flag                       
#define CMP1CN0_CPRIF__SHIFT                0x05 ///< Comparator Rising-Edge Flag                       
#define CMP1CN0_CPRIF__NOT_SET              0x00 ///< No comparator rising edge has occurred since this 
                                                 ///< flag was last cleared.                            
#define CMP1CN0_CPRIF__RISING_EDGE          0x20 ///< Comparator rising edge has occurred.              
                                                                                                        
#define CMP1CN0_CPOUT__BMASK                0x40 ///< Comparator Output State Flag                      
#define CMP1CN0_CPOUT__SHIFT                0x06 ///< Comparator Output State Flag                      
#define CMP1CN0_CPOUT__POS_LESS_THAN_NEG    0x00 ///< Voltage on CP1P < CP1N.                           
#define CMP1CN0_CPOUT__POS_GREATER_THAN_NEG 0x40 ///< Voltage on CP1P > CP1N.                           
                                                                                                        
#define CMP1CN0_CPEN__BMASK                 0x80 ///< Comparator Enable                                 
#define CMP1CN0_CPEN__SHIFT                 0x07 ///< Comparator Enable                                 
#define CMP1CN0_CPEN__DISABLED              0x00 ///< Comparator disabled.                              
#define CMP1CN0_CPEN__ENABLED               0x80 ///< Comparator enabled.                               
                                                                                                        
//------------------------------------------------------------------------------
// CMP1MD Enums (Comparator 1 Mode @ 0x9C)
//------------------------------------------------------------------------------
#define CMP1MD_CPMD__FMASK              0x03 ///< Comparator Mode Select                      
#define CMP1MD_CPMD__SHIFT              0x00 ///< Comparator Mode Select                      
#define CMP1MD_CPMD__MODE0              0x00 ///< Mode 0 (Fastest Response Time, Highest Power
                                             ///< Consumption)                                
#define CMP1MD_CPMD__MODE1              0x01 ///< Mode 1                                      
#define CMP1MD_CPMD__MODE2              0x02 ///< Mode 2                                      
#define CMP1MD_CPMD__MODE3              0x03 ///< Mode 3 (Slowest Response Time, Lowest Power 
                                             ///< Consumption)                                
                                                                                              
#define CMP1MD_CPFIE__BMASK             0x10 ///< Comparator Falling-Edge Interrupt Enable    
#define CMP1MD_CPFIE__SHIFT             0x04 ///< Comparator Falling-Edge Interrupt Enable    
#define CMP1MD_CPFIE__FALL_INT_DISABLED 0x00 ///< Comparator falling-edge interrupt disabled. 
#define CMP1MD_CPFIE__FALL_INT_ENABLED  0x10 ///< Comparator falling-edge interrupt enabled.  
                                                                                              
#define CMP1MD_CPRIE__BMASK             0x20 ///< Comparator Rising-Edge Interrupt Enable     
#define CMP1MD_CPRIE__SHIFT             0x05 ///< Comparator Rising-Edge Interrupt Enable     
#define CMP1MD_CPRIE__RISE_INT_DISABLED 0x00 ///< Comparator rising-edge interrupt disabled.  
#define CMP1MD_CPRIE__RISE_INT_ENABLED  0x20 ///< Comparator rising-edge interrupt enabled.   
                                                                                              
//------------------------------------------------------------------------------
// CMP1MX Enums (Comparator 1 Multiplexer Selection @ 0x9E)
//------------------------------------------------------------------------------
#define CMP1MX_CMXP__FMASK  0x07 ///< Comparator Positive Input MUX Selection
#define CMP1MX_CMXP__SHIFT  0x00 ///< Comparator Positive Input MUX Selection
#define CMP1MX_CMXP__CMP1P0 0x00 ///< External pin CMP1P.0.                  
#define CMP1MX_CMXP__CMP1P1 0x01 ///< External pin CMP1P.1.                  
#define CMP1MX_CMXP__CMP1P2 0x02 ///< External pin CMP1P.2.                  
#define CMP1MX_CMXP__CMP1P3 0x03 ///< External pin CMP1P.3.                  
#define CMP1MX_CMXP__CMP1P4 0x04 ///< External pin CMP1P.4.                  
                                                                             
#define CMP1MX_CMXN__FMASK  0x70 ///< Comparator Negative Input MUX Selection
#define CMP1MX_CMXN__SHIFT  0x04 ///< Comparator Negative Input MUX Selection
#define CMP1MX_CMXN__CMP1N0 0x00 ///< External pin CMP1N.0.                  
#define CMP1MX_CMXN__CMP1N1 0x10 ///< External pin CMP1N.1.                  
#define CMP1MX_CMXN__CMP1N2 0x20 ///< External pin CMP1N.2.                  
#define CMP1MX_CMXN__CMP1N3 0x30 ///< External pin CMP1N.3.                  
#define CMP1MX_CMXN__CMP1N4 0x40 ///< External pin CMP1N.4.                  
                                                                             
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
// XOSC0CN Enums (External Oscillator Control @ 0xB1)
//------------------------------------------------------------------------------
#define XOSC0CN_XFCN__FMASK           0x07 ///< External Oscillator Frequency Control            
#define XOSC0CN_XFCN__SHIFT           0x00 ///< External Oscillator Frequency Control            
#define XOSC0CN_XFCN__MODE0           0x00 ///< Select external oscillator mode 0: Crystal       
                                           ///< frequency <= 20 kHz, RC/C frequency <= 25 kHz, C 
                                           ///< mode K factor = 0.87.                            
#define XOSC0CN_XFCN__MODE1           0x01 ///< Select external oscillator mode 1: 20 kHz <      
                                           ///< Crystal frequency <= 58 kHz, 25 kHz < RC/C       
                                           ///< frequency <= 50 kHz, C mode K factor = 2.6.      
#define XOSC0CN_XFCN__MODE2           0x02 ///< Select external oscillator mode 2: 58 kHz <      
                                           ///< Crystal frequency <= 155 kHz, 50 kHz < RC/C      
                                           ///< frequency <= 100 kHz, C mode K factor = 7.7.     
#define XOSC0CN_XFCN__MODE3           0x03 ///< Select external oscillator mode 3: 155 kHz <     
                                           ///< Crystal frequency <= 415 kHz, 100 kHz < RC/C     
                                           ///< frequency <= 200 kHz, C mode K factor = 22.      
#define XOSC0CN_XFCN__MODE4           0x04 ///< Select external oscillator mode 4: 415 kHz <     
                                           ///< Crystal frequency <= 1.1 MHz, 200 kHz < RC/C     
                                           ///< frequency <= 400 kHz, C mode K factor = 65.      
#define XOSC0CN_XFCN__MODE5           0x05 ///< Select external oscillator mode 5: 1.1 MHz <     
                                           ///< Crystal frequency <= 3.1 MHz, 400 kHz < RC/C     
                                           ///< frequency <= 800 kHz, C mode K factor = 180.     
#define XOSC0CN_XFCN__MODE6           0x06 ///< Select external oscillator mode 6: 3.1 MHz <     
                                           ///< Crystal frequency <= 8.2 kHz, 800 kHz < RC/C     
                                           ///< frequency <= 1.6 MHz, C mode K factor = 664.     
#define XOSC0CN_XFCN__MODE7           0x07 ///< Select external oscillator mode 7: 8.2 MHz <     
                                           ///< Crystal frequency <= 25 MHz, 1.6 MHz < RC/C      
                                           ///< frequency <= 3.2 MHz, C mode K factor = 1590.    
                                                                                                 
#define XOSC0CN_XOSCMD__FMASK         0x70 ///< External Oscillator Mode                         
#define XOSC0CN_XOSCMD__SHIFT         0x04 ///< External Oscillator Mode                         
#define XOSC0CN_XOSCMD__DISABLED      0x00 ///< External Oscillator circuit disabled.            
#define XOSC0CN_XOSCMD__CMOS          0x20 ///< External CMOS Clock Mode.                        
#define XOSC0CN_XOSCMD__CMOS_DIV_2    0x30 ///< External CMOS Clock Mode with divide by 2 stage. 
#define XOSC0CN_XOSCMD__RC_DIV_2      0x40 ///< RC Oscillator Mode with divide by 2 stage.       
#define XOSC0CN_XOSCMD__C_DIV_2       0x50 ///< Capacitor Oscillator Mode with divide by 2 stage.
#define XOSC0CN_XOSCMD__CRYSTAL       0x60 ///< Crystal Oscillator Mode.                         
#define XOSC0CN_XOSCMD__CRYSTAL_DIV_2 0x70 ///< Crystal Oscillator Mode with divide by 2 stage.  
                                                                                                 
#define XOSC0CN_XCLKVLD__BMASK        0x80 ///< External Oscillator Valid Flag                   
#define XOSC0CN_XCLKVLD__SHIFT        0x07 ///< External Oscillator Valid Flag                   
#define XOSC0CN_XCLKVLD__NOT_SET      0x00 ///< External Oscillator is unused or not yet stable. 
#define XOSC0CN_XCLKVLD__SET          0x80 ///< External Oscillator is running and stable.       
                                                                                                 
//------------------------------------------------------------------------------
// FLKEY Enums (Flash Lock and Key @ 0xB7)
//------------------------------------------------------------------------------
#define FLKEY_FLKEY__FMASK    0xFF ///< Flash Lock and Key                             
#define FLKEY_FLKEY__SHIFT    0x00 ///< Flash Lock and Key                             
#define FLKEY_FLKEY__LOCKED   0x00 ///< Flash is write/erase locked.                   
#define FLKEY_FLKEY__FIRST    0x01 ///< The first key code has been written (0xA5).    
#define FLKEY_FLKEY__UNLOCKED 0x02 ///< Flash is unlocked (writes/erases allowed).     
#define FLKEY_FLKEY__DISABLED 0x03 ///< Flash writes/erases are disabled until the next
                                   ///< reset.                                         
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
#define FLSCL_FLRT__SYSCLK_BELOW_48_MHZ 0x10 ///< SYSCLK <= 48 MHz.                       
                                                                                          
#define FLSCL_FOSE__BMASK               0x80 ///< Flash One-Shot Enable                   
#define FLSCL_FOSE__SHIFT               0x07 ///< Flash One-Shot Enable                   
#define FLSCL_FOSE__DISABLED            0x00 ///< Disable the flash one-shot.             
#define FLSCL_FOSE__ENABLED             0x80 ///< Enable the flash one-shot (recommended).
                                                                                          
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
// HFO0CAL Enums (High Frequency Oscillator Calibration @ 0xB3)
//------------------------------------------------------------------------------
#define HFO0CAL_OSCICL__FMASK 0x7F ///< Internal Oscillator Calibration
#define HFO0CAL_OSCICL__SHIFT 0x00 ///< Internal Oscillator Calibration
                                                                       
//------------------------------------------------------------------------------
// HFO0CN Enums (High Frequency Oscillator Control @ 0xB2)
//------------------------------------------------------------------------------
#define HFO0CN_IFCN__FMASK        0x03 ///< Oscillator Frequency Divider Control              
#define HFO0CN_IFCN__SHIFT        0x00 ///< Oscillator Frequency Divider Control              
#define HFO0CN_IFCN__SYSCLK_DIV_8 0x00 ///< SYSCLK can be derived from Internal H-F Oscillator
                                       ///< divided by 8 (1.5 MHz).                           
#define HFO0CN_IFCN__SYSCLK_DIV_4 0x01 ///< SYSCLK can be derived from Internal H-F Oscillator
                                       ///< divided by 4 (3 MHz).                             
#define HFO0CN_IFCN__SYSCLK_DIV_2 0x02 ///< SYSCLK can be derived from Internal H-F Oscillator
                                       ///< divided by 2 (6 MHz).                             
#define HFO0CN_IFCN__SYSCLK_DIV_1 0x03 ///< SYSCLK can be derived from Internal H-F Oscillator
                                       ///< divided by 1 (12 MHz).                            
                                                                                              
#define HFO0CN_SUSPEND__BMASK     0x20 ///< Oscillator Suspend Enable                         
#define HFO0CN_SUSPEND__SHIFT     0x05 ///< Oscillator Suspend Enable                         
#define HFO0CN_SUSPEND__DISABLED  0x00 ///< The internal oscillator is not in suspend mode.   
#define HFO0CN_SUSPEND__ENABLED   0x20 ///< Place the internal oscillator in suspend mode.    
                                                                                              
#define HFO0CN_IFRDY__BMASK       0x40 ///< Oscillator Frequency Ready Flag                   
#define HFO0CN_IFRDY__SHIFT       0x06 ///< Oscillator Frequency Ready Flag                   
#define HFO0CN_IFRDY__NOT_SET     0x00 ///< The Internal High Frequency Oscillator is not     
                                       ///< running at the programmed frequency.              
#define HFO0CN_IFRDY__SET         0x40 ///< The Internal High Frequency Oscillator is running 
                                       ///< at the programmed frequency.                      
                                                                                              
#define HFO0CN_IOSCEN__BMASK      0x80 ///< Oscillator Enable                                 
#define HFO0CN_IOSCEN__SHIFT      0x07 ///< Oscillator Enable                                 
#define HFO0CN_IOSCEN__DISABLED   0x00 ///< Disable the High Frequency Oscillator.            
#define HFO0CN_IOSCEN__ENABLED    0x80 ///< Enable the High Frequency Oscillator.             
                                                                                              
//------------------------------------------------------------------------------
// EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
//------------------------------------------------------------------------------
#define EIE1_ESMB0__BMASK     0x01 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__SHIFT     0x00 ///< SMBus (SMB0) Interrupt Enable                     
#define EIE1_ESMB0__DISABLED  0x00 ///< Disable all SMB0 interrupts.                      
#define EIE1_ESMB0__ENABLED   0x01 ///< Enable interrupt requests generated by SMB0.      
                                                                                          
#define EIE1_EUSB0__BMASK     0x02 ///< USB (USB0) Interrupt Enable                       
#define EIE1_EUSB0__SHIFT     0x01 ///< USB (USB0) Interrupt Enable                       
#define EIE1_EUSB0__DISABLED  0x00 ///< Disable all USB0 interrupts.                      
#define EIE1_EUSB0__ENABLED   0x02 ///< Enable interrupt requests generated by USB0.      
                                                                                          
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
#define EIE2_EVBUS__BMASK    0x01 ///< VBUS Level Interrupt Enable                       
#define EIE2_EVBUS__SHIFT    0x00 ///< VBUS Level Interrupt Enable                       
#define EIE2_EVBUS__DISABLED 0x00 ///< Disable all VBUS interrupts.                      
#define EIE2_EVBUS__ENABLED  0x01 ///< Enable interrupt requests generated by VBUS level 
                                  ///< sense.                                            
                                                                                         
#define EIE2_ES1__BMASK      0x02 ///< UART1 Interrupt Enable                            
#define EIE2_ES1__SHIFT      0x01 ///< UART1 Interrupt Enable                            
#define EIE2_ES1__DISABLED   0x00 ///< Disable UART1 interrupt.                          
#define EIE2_ES1__ENABLED    0x02 ///< Enable UART1 interrupt.                           
                                                                                         
#define EIE2_ESMB1__BMASK    0x08 ///< SMBus1 Interrupt Enable                           
#define EIE2_ESMB1__SHIFT    0x03 ///< SMBus1 Interrupt Enable                           
#define EIE2_ESMB1__DISABLED 0x00 ///< Disable all SMB1 interrupts.                      
#define EIE2_ESMB1__ENABLED  0x08 ///< Enable interrupt requests generated by SMB1.      
                                                                                         
#define EIE2_ET4__BMASK      0x10 ///< Timer 4 Interrupt Enable                          
#define EIE2_ET4__SHIFT      0x04 ///< Timer 4 Interrupt Enable                          
#define EIE2_ET4__DISABLED   0x00 ///< Disable Timer 4interrupts.                        
#define EIE2_ET4__ENABLED    0x10 ///< Enable interrupt requests generated by the TF4L or
                                  ///< TF4H flags.                                       
                                                                                         
#define EIE2_ET5__BMASK      0x20 ///< Timer 5 Interrupt Enable                          
#define EIE2_ET5__SHIFT      0x05 ///< Timer 5 Interrupt Enable                          
#define EIE2_ET5__DISABLED   0x00 ///< Disable Timer 5 interrupts.                       
#define EIE2_ET5__ENABLED    0x20 ///< Enable interrupt requests generated by the TF5L or
                                  ///< TF5H flags.                                       
                                                                                         
//------------------------------------------------------------------------------
// EIP1 Enums (Extended Interrupt Priority 1 @ 0xF6)
//------------------------------------------------------------------------------
#define EIP1_PSMB0__BMASK  0x01 ///< SMBus (SMB0) Interrupt Priority Control                     
#define EIP1_PSMB0__SHIFT  0x00 ///< SMBus (SMB0) Interrupt Priority Control                     
#define EIP1_PSMB0__LOW    0x00 ///< SMB0 interrupt set to low priority level.                   
#define EIP1_PSMB0__HIGH   0x01 ///< SMB0 interrupt set to high priority level.                  
                                                                                                 
#define EIP1_PUSB0__BMASK  0x02 ///< USB (USB0) Interrupt Priority Control                       
#define EIP1_PUSB0__SHIFT  0x01 ///< USB (USB0) Interrupt Priority Control                       
#define EIP1_PUSB0__LOW    0x00 ///< USB0 interrupt set to low priority level.                   
#define EIP1_PUSB0__HIGH   0x02 ///< USB0 interrupt set to high priority level.                  
                                                                                                 
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
#define EIP2_PVBUS__BMASK 0x01 ///< VBUS Level Interrupt Priority Control        
#define EIP2_PVBUS__SHIFT 0x00 ///< VBUS Level Interrupt Priority Control        
#define EIP2_PVBUS__LOW   0x00 ///< VBUS interrupt set to low priority level.    
#define EIP2_PVBUS__HIGH  0x01 ///< VBUS interrupt set to high priority level.   
                                                                                 
#define EIP2_PS1__BMASK   0x02 ///< UART1 Interrupt Priority Control             
#define EIP2_PS1__SHIFT   0x01 ///< UART1 Interrupt Priority Control             
#define EIP2_PS1__LOW     0x00 ///< UART1 interrupt set to low priority level.   
#define EIP2_PS1__HIGH    0x02 ///< UART1 interrupt set to high priority level.  
                                                                                 
#define EIP2_PSMB1__BMASK 0x08 ///< SMBus1 Interrupt Priority Control            
#define EIP2_PSMB1__SHIFT 0x03 ///< SMBus1 Interrupt Priority Control            
#define EIP2_PSMB1__LOW   0x00 ///< SMB1 interrupt set to low priority level.    
#define EIP2_PSMB1__HIGH  0x08 ///< SMB1 interrupt set to high priority level.   
                                                                                 
#define EIP2_PT4__BMASK   0x10 ///< Timer 4 Interrupt Priority Control           
#define EIP2_PT4__SHIFT   0x04 ///< Timer 4 Interrupt Priority Control           
#define EIP2_PT4__LOW     0x00 ///< Timer 4 interrupt set to low priority level. 
#define EIP2_PT4__HIGH    0x10 ///< Timer 4 interrupt set to high priority level.
                                                                                 
#define EIP2_PT5__BMASK   0x20 ///< Timer 5 Interrupt Priority Control           
#define EIP2_PT5__SHIFT   0x05 ///< Timer 5 Interrupt Priority Control           
#define EIP2_PT5__LOW     0x00 ///< Timer 5 interrupt set to low priority level. 
#define EIP2_PT5__HIGH    0x20 ///< Timer 5 interrupt set to high priority level.
                                                                                 
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
// LFO0CN Enums (Low Frequency Oscillator Control @ 0x86)
//------------------------------------------------------------------------------
#define LFO0CN_OSCLD__FMASK       0x03 ///< Internal L-F Oscillator Divider Select           
#define LFO0CN_OSCLD__SHIFT       0x00 ///< Internal L-F Oscillator Divider Select           
#define LFO0CN_OSCLD__DIVIDE_BY_8 0x00 ///< Divide by 8 selected.                            
#define LFO0CN_OSCLD__DIVIDE_BY_4 0x01 ///< Divide by 4 selected.                            
#define LFO0CN_OSCLD__DIVIDE_BY_2 0x02 ///< Divide by 2 selected.                            
#define LFO0CN_OSCLD__DIVIDE_BY_1 0x03 ///< Divide by 1 selected.                            
                                                                                             
#define LFO0CN_OSCLF__FMASK       0x3C ///< Internal L-F Oscillator Frequency Control        
#define LFO0CN_OSCLF__SHIFT       0x02 ///< Internal L-F Oscillator Frequency Control        
                                                                                             
#define LFO0CN_OSCLRDY__BMASK     0x40 ///< Internal L-F Oscillator Ready                    
#define LFO0CN_OSCLRDY__SHIFT     0x06 ///< Internal L-F Oscillator Ready                    
#define LFO0CN_OSCLRDY__NOT_SET   0x00 ///< Internal L-F Oscillator frequency not stabilized.
#define LFO0CN_OSCLRDY__SET       0x40 ///< Internal L-F Oscillator frequency stabilized.    
                                                                                             
#define LFO0CN_OSCLEN__BMASK      0x80 ///< Internal L-F Oscillator Enable                   
#define LFO0CN_OSCLEN__SHIFT      0x07 ///< Internal L-F Oscillator Enable                   
#define LFO0CN_OSCLEN__DISABLED   0x00 ///< Internal L-F Oscillator Disabled.                
#define LFO0CN_OSCLEN__ENABLED    0x80 ///< Internal L-F Oscillator Enabled.                 
                                                                                             
//------------------------------------------------------------------------------
// XBR0 Enums (Port I/O Crossbar 0 @ 0xE1)
//------------------------------------------------------------------------------
#define XBR0_URT0E__BMASK     0x01 ///< UART0 I/O Output Enable                        
#define XBR0_URT0E__SHIFT     0x00 ///< UART0 I/O Output Enable                        
#define XBR0_URT0E__DISABLED  0x00 ///< UART0 I/O unavailable at Port pin.             
#define XBR0_URT0E__ENABLED   0x01 ///< UART0 TX, RX routed to Port pins P0.4 and P0.5.
                                                                                       
#define XBR0_SPI0E__BMASK     0x02 ///< SPI I/O Enable                                 
#define XBR0_SPI0E__SHIFT     0x01 ///< SPI I/O Enable                                 
#define XBR0_SPI0E__DISABLED  0x00 ///< SPI I/O unavailable at Port pins.              
#define XBR0_SPI0E__ENABLED   0x02 ///< SPI I/O routed to Port pins. The SPI can be    
                                   ///< assigned either 3 or 4 GPIO pins.              
                                                                                       
#define XBR0_SMB0E__BMASK     0x04 ///< SMB0 I/O Enable                                
#define XBR0_SMB0E__SHIFT     0x02 ///< SMB0 I/O Enable                                
#define XBR0_SMB0E__DISABLED  0x00 ///< SMBus 0 I/O unavailable at Port pins.          
#define XBR0_SMB0E__ENABLED   0x04 ///< SMBus 0 I/O routed to Port pins.               
                                                                                       
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
#define XBR1_PCA0ME__FMASK                    0x07 ///< PCA Module I/O Enable                            
#define XBR1_PCA0ME__SHIFT                    0x00 ///< PCA Module I/O Enable                            
#define XBR1_PCA0ME__DISABLED                 0x00 ///< All PCA I/O unavailable at Port pins.            
#define XBR1_PCA0ME__CEX0                     0x01 ///< CEX0 routed to Port pin.                         
#define XBR1_PCA0ME__CEX0_CEX1                0x02 ///< CEX0, CEX1 routed to Port pins.                  
#define XBR1_PCA0ME__CEX0_CEX1_CEX2           0x03 ///< CEX0, CEX1, CEX2 routed to Port pins.            
#define XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3      0x04 ///< CEX0, CEX1, CEX2, CEX3 routed to Port pins.      
#define XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4 0x05 ///< CEX0, CEX1, CEX2, CEX3, CEX4 routed to Port pins.
                                                                                                         
#define XBR1_ECIE__BMASK                      0x08 ///< PCA0 External Counter Input Enable               
#define XBR1_ECIE__SHIFT                      0x03 ///< PCA0 External Counter Input Enable               
#define XBR1_ECIE__DISABLED                   0x00 ///< ECI unavailable at Port pin.                     
#define XBR1_ECIE__ENABLED                    0x08 ///< ECI routed to Port pin.                          
                                                                                                         
#define XBR1_T0E__BMASK                       0x10 ///< T0 Enable                                        
#define XBR1_T0E__SHIFT                       0x04 ///< T0 Enable                                        
#define XBR1_T0E__DISABLED                    0x00 ///< T0 unavailable at Port pin.                      
#define XBR1_T0E__ENABLED                     0x10 ///< T0 routed to Port pin.                           
                                                                                                         
#define XBR1_T1E__BMASK                       0x20 ///< T1 Enable                                        
#define XBR1_T1E__SHIFT                       0x05 ///< T1 Enable                                        
#define XBR1_T1E__DISABLED                    0x00 ///< T1 unavailable at Port pin.                      
#define XBR1_T1E__ENABLED                     0x20 ///< T1 routed to Port pin.                           
                                                                                                         
#define XBR1_XBARE__BMASK                     0x40 ///< Crossbar Enable                                  
#define XBR1_XBARE__SHIFT                     0x06 ///< Crossbar Enable                                  
#define XBR1_XBARE__DISABLED                  0x00 ///< Crossbar disabled.                               
#define XBR1_XBARE__ENABLED                   0x40 ///< Crossbar enabled.                                
                                                                                                         
#define XBR1_WEAKPUD__BMASK                   0x80 ///< Port I/O Weak Pullup Disable                     
#define XBR1_WEAKPUD__SHIFT                   0x07 ///< Port I/O Weak Pullup Disable                     
#define XBR1_WEAKPUD__PULL_UPS_ENABLED        0x00 ///< Weak Pullups enabled (except for Ports whose I/O 
                                                   ///< are configured for analog mode).                 
#define XBR1_WEAKPUD__PULL_UPS_DISABLED       0x80 ///< Weak Pullups disabled.                           
                                                                                                         
//------------------------------------------------------------------------------
// XBR2 Enums (Port I/O Crossbar 2 @ 0xE3)
//------------------------------------------------------------------------------
#define XBR2_URT1E__BMASK    0x01 ///< UART1 I/O Output Enable             
#define XBR2_URT1E__SHIFT    0x00 ///< UART1 I/O Output Enable             
#define XBR2_URT1E__DISABLED 0x00 ///< UART1 I/O unavailable at Port pin.  
#define XBR2_URT1E__ENABLED  0x01 ///< UART1 TX, RX routed to Port pins.   
                                                                           
#define XBR2_SMB1E__BMASK    0x02 ///< SMBus1 I/O Enable                   
#define XBR2_SMB1E__SHIFT    0x01 ///< SMBus1 I/O Enable                   
#define XBR2_SMB1E__DISABLED 0x00 ///< SMBus1 I/O unavailable at Port pins.
#define XBR2_SMB1E__ENABLED  0x02 ///< SMBus1 I/O routed to Port pins.     
                                                                           
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
// PCA0CPH1 Enums (PCA Channel 1 Capture Module High Byte @ 0xEA)
//------------------------------------------------------------------------------
#define PCA0CPH1_PCA0CPH1__FMASK 0xFF ///< PCA Channel 1 Capture Module High Byte
#define PCA0CPH1_PCA0CPH1__SHIFT 0x00 ///< PCA Channel 1 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL1 Enums (PCA Channel 1 Capture Module Low Byte @ 0xE9)
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
// PCA0CPH2 Enums (PCA Channel 2 Capture Module High Byte @ 0xEC)
//------------------------------------------------------------------------------
#define PCA0CPH2_PCA0CPH2__FMASK 0xFF ///< PCA Channel 2 Capture Module High Byte
#define PCA0CPH2_PCA0CPH2__SHIFT 0x00 ///< PCA Channel 2 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL2 Enums (PCA Channel 2 Capture Module Low Byte @ 0xEB)
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
// PCA0CPH3 Enums (PCA Channel 3 Capture Module High Byte @ 0xEE)
//------------------------------------------------------------------------------
#define PCA0CPH3_PCA0CPH3__FMASK 0xFF ///< PCA Channel 3 Capture Module High Byte
#define PCA0CPH3_PCA0CPH3__SHIFT 0x00 ///< PCA Channel 3 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL3 Enums (PCA Channel 3 Capture Module Low Byte @ 0xED)
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
// PCA0CPH4 Enums (PCA Channel 4 Capture Module High Byte @ 0xFE)
//------------------------------------------------------------------------------
#define PCA0CPH4_PCA0CPH4__FMASK 0xFF ///< PCA Channel 4 Capture Module High Byte
#define PCA0CPH4_PCA0CPH4__SHIFT 0x00 ///< PCA Channel 4 Capture Module High Byte
                                                                                 
//------------------------------------------------------------------------------
// PCA0CPL4 Enums (PCA Channel 4 Capture Module Low Byte @ 0xFD)
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
// PCA0CN0 Enums (PCA Control 0 @ 0xD8)
//------------------------------------------------------------------------------
#define PCA0CN0_CCF0__BMASK   0x01 ///< PCA Module 0 Capture/Compare Flag             
#define PCA0CN0_CCF0__SHIFT   0x00 ///< PCA Module 0 Capture/Compare Flag             
#define PCA0CN0_CCF0__NOT_SET 0x00 ///< A match or capture did not occur on channel 0.
#define PCA0CN0_CCF0__SET     0x01 ///< A match or capture occurred on channel 0.     
                                                                                      
#define PCA0CN0_CCF1__BMASK   0x02 ///< PCA Module 1 Capture/Compare Flag             
#define PCA0CN0_CCF1__SHIFT   0x01 ///< PCA Module 1 Capture/Compare Flag             
#define PCA0CN0_CCF1__NOT_SET 0x00 ///< A match or capture did not occur on channel 1.
#define PCA0CN0_CCF1__SET     0x02 ///< A match or capture occurred on channel 1.     
                                                                                      
#define PCA0CN0_CCF2__BMASK   0x04 ///< PCA Module 2 Capture/Compare Flag             
#define PCA0CN0_CCF2__SHIFT   0x02 ///< PCA Module 2 Capture/Compare Flag             
#define PCA0CN0_CCF2__NOT_SET 0x00 ///< A match or capture did not occur on channel 2.
#define PCA0CN0_CCF2__SET     0x04 ///< A match or capture occurred on channel 2.     
                                                                                      
#define PCA0CN0_CCF3__BMASK   0x08 ///< PCA Module 3 Capture/Compare Flag             
#define PCA0CN0_CCF3__SHIFT   0x03 ///< PCA Module 3 Capture/Compare Flag             
#define PCA0CN0_CCF3__NOT_SET 0x00 ///< A match or capture did not occur on channel 3.
#define PCA0CN0_CCF3__SET     0x08 ///< A match or capture occurred on channel 3.     
                                                                                      
#define PCA0CN0_CCF4__BMASK   0x10 ///< PCA Module 4 Capture/Compare Flag             
#define PCA0CN0_CCF4__SHIFT   0x04 ///< PCA Module 4 Capture/Compare Flag             
#define PCA0CN0_CCF4__NOT_SET 0x00 ///< A match or capture did not occur on channel 4.
#define PCA0CN0_CCF4__SET     0x10 ///< A match or capture occurred on channel 4.     
                                                                                      
#define PCA0CN0_CR__BMASK     0x40 ///< PCA Counter/Timer Run Control                 
#define PCA0CN0_CR__SHIFT     0x06 ///< PCA Counter/Timer Run Control                 
#define PCA0CN0_CR__STOP      0x00 ///< Stop the PCA Counter/Timer.                   
#define PCA0CN0_CR__RUN       0x40 ///< Start the PCA Counter/Timer running.          
                                                                                      
#define PCA0CN0_CF__BMASK     0x80 ///< PCA Counter/Timer Overflow Flag               
#define PCA0CN0_CF__SHIFT     0x07 ///< PCA Counter/Timer Overflow Flag               
#define PCA0CN0_CF__NOT_SET   0x00 ///< The PCA counter/timer did not overflow.       
#define PCA0CN0_CF__SET       0x80 ///< The PCA counter/timer overflowed.             
                                                                                      
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
                                                                                                 
#define PCA0MD_WDLCK__BMASK          0x20 ///< Watchdog Timer Lock                               
#define PCA0MD_WDLCK__SHIFT          0x05 ///< Watchdog Timer Lock                               
#define PCA0MD_WDLCK__UNLOCKED       0x00 ///< Watchdog Timer Enable unlocked.                   
#define PCA0MD_WDLCK__LOCKED         0x20 ///< Watchdog Timer Enable locked.                     
                                                                                                 
#define PCA0MD_WDTE__BMASK           0x40 ///< Watchdog Timer Enable                             
#define PCA0MD_WDTE__SHIFT           0x06 ///< Watchdog Timer Enable                             
#define PCA0MD_WDTE__DISABLED        0x00 ///< Disable Watchdog Timer.                           
#define PCA0MD_WDTE__ENABLED         0x40 ///< Enable PCA Module 4 as the Watchdog Timer.        
                                                                                                 
#define PCA0MD_CIDL__BMASK           0x80 ///< PCA Counter/Timer Idle Control                    
#define PCA0MD_CIDL__SHIFT           0x07 ///< PCA Counter/Timer Idle Control                    
#define PCA0MD_CIDL__NORMAL          0x00 ///< PCA continues to function normally while the      
                                          ///< system controller is in Idle Mode.                
#define PCA0MD_CIDL__SUSPEND         0x80 ///< PCA operation is suspended while the system       
                                          ///< controller is in Idle Mode.                       
                                                                                                 
//------------------------------------------------------------------------------
// PCON0 Enums (Power Control @ 0x87)
//------------------------------------------------------------------------------
#define PCON0_IDLE__BMASK  0x01 ///< Idle Mode Select                                
#define PCON0_IDLE__SHIFT  0x00 ///< Idle Mode Select                                
#define PCON0_IDLE__NORMAL 0x00 ///< Idle mode not activated.                        
#define PCON0_IDLE__IDLE   0x01 ///< CPU goes into Idle mode (shuts off clock to CPU,
                                ///< but clocks to enabled peripherals are still     
                                ///< active).                                        
                                                                                     
#define PCON0_STOP__BMASK  0x02 ///< Stop Mode Select                                
#define PCON0_STOP__SHIFT  0x01 ///< Stop Mode Select                                
#define PCON0_STOP__NORMAL 0x00 ///< Stop mode not activated.                        
#define PCON0_STOP__STOP   0x02 ///< CPU goes into Stop mode (internal oscillator    
                                ///< stopped).                                       
                                                                                     
#define PCON0_GF0__BMASK   0x04 ///< General Purpose Flag 0                          
#define PCON0_GF0__SHIFT   0x02 ///< General Purpose Flag 0                          
#define PCON0_GF0__NOT_SET 0x00 ///< The GF0 flag is not set. Clear the GF0 flag.    
#define PCON0_GF0__SET     0x04 ///< The GF0 flag is set. Set the GF0 flag.          
                                                                                     
#define PCON0_GF1__BMASK   0x08 ///< General Purpose Flag 1                          
#define PCON0_GF1__SHIFT   0x03 ///< General Purpose Flag 1                          
#define PCON0_GF1__NOT_SET 0x00 ///< The GF1 flag is not set. Clear the GF1 flag.    
#define PCON0_GF1__SET     0x08 ///< The GF1 flag is set. Set the GF1 flag.          
                                                                                     
#define PCON0_GF2__BMASK   0x10 ///< General Purpose Flag 2                          
#define PCON0_GF2__SHIFT   0x04 ///< General Purpose Flag 2                          
#define PCON0_GF2__NOT_SET 0x00 ///< The GF2 flag is not set. Clear the GF2 flag.    
#define PCON0_GF2__SET     0x10 ///< The GF2 flag is set. Set the GF2 flag.          
                                                                                     
#define PCON0_GF3__BMASK   0x20 ///< General Purpose Flag 3                          
#define PCON0_GF3__SHIFT   0x05 ///< General Purpose Flag 3                          
#define PCON0_GF3__NOT_SET 0x00 ///< The GF3 flag is not set. Clear the GF3 flag.    
#define PCON0_GF3__SET     0x20 ///< The GF3 flag is set. Set the GF3 flag.          
                                                                                     
#define PCON0_GF4__BMASK   0x40 ///< General Purpose Flag 4                          
#define PCON0_GF4__SHIFT   0x06 ///< General Purpose Flag 4                          
#define PCON0_GF4__NOT_SET 0x00 ///< The GF4 flag is not set. Clear the GF4 flag.    
#define PCON0_GF4__SET     0x40 ///< The GF4 flag is set. Set the GF4 flag.          
                                                                                     
#define PCON0_GF5__BMASK   0x80 ///< General Purpose Flag 5                          
#define PCON0_GF5__SHIFT   0x07 ///< General Purpose Flag 5                          
#define PCON0_GF5__NOT_SET 0x00 ///< The GF5 flag is not set. Clear the GF5 flag.    
#define PCON0_GF5__SET     0x80 ///< The GF5 flag is set. Set the GF5 flag.          
                                                                                     
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
// P3SKIP Enums (Port 3 Skip @ 0xDF)
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
// P4 Enums (Port 4 Pin Latch @ 0xC7)
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
// P4MDOUT Enums (Port 4 Output Mode @ 0xAE)
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
#define RSTSRC_PINRSF__NOT_SET 0x00 ///< The RSTb pin did not cause the last reset.                           
#define RSTSRC_PINRSF__SET     0x01 ///< The RSTb pin caused the last reset.                                  
                                                                                                              
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
                                                                                                              
#define RSTSRC_USBRSF__BMASK   0x80 ///< USB Reset Enable and Flag                                            
#define RSTSRC_USBRSF__SHIFT   0x07 ///< USB Reset Enable and Flag                                            
#define RSTSRC_USBRSF__NOT_SET 0x00 ///< A USB0 reset did not occur.                                          
#define RSTSRC_USBRSF__SET     0x80 ///< A USB0 reset occurred.                                               
                                                                                                              
//------------------------------------------------------------------------------
// SFRPAGE Enums (SFR Page @ 0xBF)
//------------------------------------------------------------------------------
#define SFRPAGE_SFRPAGE__FMASK 0xFF ///< SFR Page
#define SFRPAGE_SFRPAGE__SHIFT 0x00 ///< SFR Page
                                                 
//------------------------------------------------------------------------------
// SMB0ADM Enums (SMBus 0 Slave Address Mask @ 0xCE)
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
// SMB0ADR Enums (SMBus 0 Slave Address @ 0xCF)
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
// SMB0CN0 Enums (SMBus 0 Control @ 0xC0)
//------------------------------------------------------------------------------
#define SMB0CN0_SI__BMASK           0x01 ///< SMBus Interrupt Flag                           
#define SMB0CN0_SI__SHIFT           0x00 ///< SMBus Interrupt Flag                           
#define SMB0CN0_SI__NOT_SET         0x00 ///<                                                
#define SMB0CN0_SI__SET             0x01 ///<                                                
                                                                                             
#define SMB0CN0_ACK__BMASK          0x02 ///< SMBus Acknowledge                              
#define SMB0CN0_ACK__SHIFT          0x01 ///< SMBus Acknowledge                              
#define SMB0CN0_ACK__NOT_SET        0x00 ///< Generate a NACK, or the response was a NACK.   
#define SMB0CN0_ACK__SET            0x02 ///< Generate an ACK, or the response was an ACK.   
                                                                                             
#define SMB0CN0_ARBLOST__BMASK      0x04 ///< SMBus Arbitration Lost Indicator               
#define SMB0CN0_ARBLOST__SHIFT      0x02 ///< SMBus Arbitration Lost Indicator               
#define SMB0CN0_ARBLOST__NOT_SET    0x00 ///< No arbitration error.                          
#define SMB0CN0_ARBLOST__ERROR      0x04 ///< Arbitration error occurred.                    
                                                                                             
#define SMB0CN0_ACKRQ__BMASK        0x08 ///< SMBus Acknowledge Request                      
#define SMB0CN0_ACKRQ__SHIFT        0x03 ///< SMBus Acknowledge Request                      
#define SMB0CN0_ACKRQ__NOT_SET      0x00 ///< No ACK requested.                              
#define SMB0CN0_ACKRQ__REQUESTED    0x08 ///< ACK requested.                                 
                                                                                             
#define SMB0CN0_STO__BMASK          0x10 ///< SMBus Stop Flag                                
#define SMB0CN0_STO__SHIFT          0x04 ///< SMBus Stop Flag                                
#define SMB0CN0_STO__NOT_SET        0x00 ///< A STOP is not pending.                         
#define SMB0CN0_STO__SET            0x10 ///< Generate a STOP or a STOP is currently pending.
                                                                                             
#define SMB0CN0_STA__BMASK          0x20 ///< SMBus Start Flag                               
#define SMB0CN0_STA__SHIFT          0x05 ///< SMBus Start Flag                               
#define SMB0CN0_STA__NOT_SET        0x00 ///< A START was not detected.                      
#define SMB0CN0_STA__SET            0x20 ///< Generate a START, repeated START, or a START is
                                         ///< currently pending.                             
                                                                                             
#define SMB0CN0_TXMODE__BMASK       0x40 ///< SMBus Transmit Mode Indicator                  
#define SMB0CN0_TXMODE__SHIFT       0x06 ///< SMBus Transmit Mode Indicator                  
#define SMB0CN0_TXMODE__RECEIVER    0x00 ///< SMBus in Receiver Mode.                        
#define SMB0CN0_TXMODE__TRANSMITTER 0x40 ///< SMBus in Transmitter Mode.                     
                                                                                             
#define SMB0CN0_MASTER__BMASK       0x80 ///< SMBus Master/Slave Indicator                   
#define SMB0CN0_MASTER__SHIFT       0x07 ///< SMBus Master/Slave Indicator                   
#define SMB0CN0_MASTER__SLAVE       0x00 ///< SMBus operating in slave mode.                 
#define SMB0CN0_MASTER__MASTER      0x80 ///< SMBus operating in master mode.                
                                                                                             
//------------------------------------------------------------------------------
// SMB0DAT Enums (SMBus 0 Data @ 0xC2)
//------------------------------------------------------------------------------
#define SMB0DAT_SMB0DAT__FMASK 0xFF ///< SMBus 0 Data
#define SMB0DAT_SMB0DAT__SHIFT 0x00 ///< SMBus 0 Data
                                                     
//------------------------------------------------------------------------------
// SMB1ADM Enums (SMBus 1 Slave Address Mask @ 0xCE)
//------------------------------------------------------------------------------
#define SMB1ADM_EHACK__BMASK             0x01 ///< Hardware Acknowledge Enable                     
#define SMB1ADM_EHACK__SHIFT             0x00 ///< Hardware Acknowledge Enable                     
#define SMB1ADM_EHACK__ADR_ACK_MANUAL    0x00 ///< Firmware must manually acknowledge all incoming 
                                              ///< address and data bytes.                         
#define SMB1ADM_EHACK__ADR_ACK_AUTOMATIC 0x01 ///< Automatic slave address recognition and hardware
                                              ///< acknowledge is enabled.                         
                                                                                                   
#define SMB1ADM_SLVM__FMASK              0xFE ///< SMBus Slave Address Mask                        
#define SMB1ADM_SLVM__SHIFT              0x01 ///< SMBus Slave Address Mask                        
                                                                                                   
//------------------------------------------------------------------------------
// SMB1ADR Enums (SMBus 1 Slave Address @ 0xCF)
//------------------------------------------------------------------------------
#define SMB1ADR_GC__BMASK      0x01 ///< General Call Address Enable        
#define SMB1ADR_GC__SHIFT      0x00 ///< General Call Address Enable        
#define SMB1ADR_GC__IGNORED    0x00 ///< General Call Address is ignored.   
#define SMB1ADR_GC__RECOGNIZED 0x01 ///< General Call Address is recognized.
                                                                            
#define SMB1ADR_SLV__FMASK     0xFE ///< SMBus Hardware Slave Address       
#define SMB1ADR_SLV__SHIFT     0x01 ///< SMBus Hardware Slave Address       
                                                                            
//------------------------------------------------------------------------------
// SMB1CF Enums (SMBus 1 Configuration @ 0xC1)
//------------------------------------------------------------------------------
#define SMB1CF_SMBCS__FMASK             0x03 ///< SMBus Clock Source Selection                     
#define SMB1CF_SMBCS__SHIFT             0x00 ///< SMBus Clock Source Selection                     
#define SMB1CF_SMBCS__TIMER0            0x00 ///< Timer 0 Overflow.                                
#define SMB1CF_SMBCS__TIMER5            0x01 ///< Timer 5 Overflow.                                
#define SMB1CF_SMBCS__TIMER2_HIGH       0x02 ///< Timer 2 High Byte Overflow.                      
#define SMB1CF_SMBCS__TIMER2_LOW        0x03 ///< Timer 2 Low Byte Overflow.                       
                                                                                                   
#define SMB1CF_SMBFTE__BMASK            0x04 ///< SMBus Free Timeout Detection Enable              
#define SMB1CF_SMBFTE__SHIFT            0x02 ///< SMBus Free Timeout Detection Enable              
#define SMB1CF_SMBFTE__FREE_TO_DISABLED 0x00 ///< Disable bus free timeouts.                       
#define SMB1CF_SMBFTE__FREE_TO_ENABLED  0x04 ///< Enable bus free timeouts. The bus the bus will be
                                             ///< considered free if SCL and SDA remain high for   
                                             ///< more than 10 SMBus clock source periods.         
                                                                                                   
#define SMB1CF_SMBTOE__BMASK            0x08 ///< SMBus SCL Timeout Detection Enable               
#define SMB1CF_SMBTOE__SHIFT            0x03 ///< SMBus SCL Timeout Detection Enable               
#define SMB1CF_SMBTOE__SCL_TO_DISABLED  0x00 ///< Disable SCL low timeouts.                        
#define SMB1CF_SMBTOE__SCL_TO_ENABLED   0x08 ///< Enable SCL low timeouts.                         
                                                                                                   
#define SMB1CF_EXTHOLD__BMASK           0x10 ///< SMBus Setup and Hold Time Extension Enable       
#define SMB1CF_EXTHOLD__SHIFT           0x04 ///< SMBus Setup and Hold Time Extension Enable       
#define SMB1CF_EXTHOLD__DISABLED        0x00 ///< Disable SDA extended setup and hold times.       
#define SMB1CF_EXTHOLD__ENABLED         0x10 ///< Enable SDA extended setup and hold times.        
                                                                                                   
#define SMB1CF_BUSY__BMASK              0x20 ///< SMBus Busy Indicator                             
#define SMB1CF_BUSY__SHIFT              0x05 ///< SMBus Busy Indicator                             
#define SMB1CF_BUSY__NOT_SET            0x00 ///< The bus is not busy.                             
#define SMB1CF_BUSY__SET                0x20 ///< The bus is busy and a transfer is currently in   
                                             ///< progress.                                        
                                                                                                   
#define SMB1CF_INH__BMASK               0x40 ///< SMBus Slave Inhibit                              
#define SMB1CF_INH__SHIFT               0x06 ///< SMBus Slave Inhibit                              
#define SMB1CF_INH__SLAVE_ENABLED       0x00 ///< Slave states are enabled.                        
#define SMB1CF_INH__SLAVE_DISABLED      0x40 ///< Slave states are inhibited.                      
                                                                                                   
#define SMB1CF_ENSMB__BMASK             0x80 ///< SMBus Enable                                     
#define SMB1CF_ENSMB__SHIFT             0x07 ///< SMBus Enable                                     
#define SMB1CF_ENSMB__DISABLED          0x00 ///< Disable the SMBus module.                        
#define SMB1CF_ENSMB__ENABLED           0x80 ///< Enable the SMBus module.                         
                                                                                                   
//------------------------------------------------------------------------------
// SMB1CN0 Enums (SMBus 1 Control @ 0xC0)
//------------------------------------------------------------------------------
#define SMB1CN0_SI__BMASK           0x01 ///< SMBus Interrupt Flag                           
#define SMB1CN0_SI__SHIFT           0x00 ///< SMBus Interrupt Flag                           
#define SMB1CN0_SI__NOT_SET         0x00 ///<                                                
#define SMB1CN0_SI__SET             0x01 ///<                                                
                                                                                             
#define SMB1CN0_ACK__BMASK          0x02 ///< SMBus Acknowledge                              
#define SMB1CN0_ACK__SHIFT          0x01 ///< SMBus Acknowledge                              
#define SMB1CN0_ACK__NOT_SET        0x00 ///< Generate a NACK, or the response was a NACK.   
#define SMB1CN0_ACK__SET            0x02 ///< Generate an ACK, or the response was an ACK.   
                                                                                             
#define SMB1CN0_ARBLOST__BMASK      0x04 ///< SMBus Arbitration Lost Indicator               
#define SMB1CN0_ARBLOST__SHIFT      0x02 ///< SMBus Arbitration Lost Indicator               
#define SMB1CN0_ARBLOST__NOT_SET    0x00 ///< No arbitration error.                          
#define SMB1CN0_ARBLOST__ERROR      0x04 ///< Arbitration error occurred.                    
                                                                                             
#define SMB1CN0_ACKRQ__BMASK        0x08 ///< SMBus Acknowledge Request                      
#define SMB1CN0_ACKRQ__SHIFT        0x03 ///< SMBus Acknowledge Request                      
#define SMB1CN0_ACKRQ__NOT_SET      0x00 ///< No ACK requested.                              
#define SMB1CN0_ACKRQ__REQUESTED    0x08 ///< ACK requested.                                 
                                                                                             
#define SMB1CN0_STO__BMASK          0x10 ///< SMBus Stop Flag                                
#define SMB1CN0_STO__SHIFT          0x04 ///< SMBus Stop Flag                                
#define SMB1CN0_STO__NOT_SET        0x00 ///< A STOP is not pending.                         
#define SMB1CN0_STO__SET            0x10 ///< Generate a STOP or a STOP is currently pending.
                                                                                             
#define SMB1CN0_STA__BMASK          0x20 ///< SMBus Start Flag                               
#define SMB1CN0_STA__SHIFT          0x05 ///< SMBus Start Flag                               
#define SMB1CN0_STA__NOT_SET        0x00 ///< A START was not detected.                      
#define SMB1CN0_STA__SET            0x20 ///< Generate a START, repeated START, or a START is
                                         ///< currently pending.                             
                                                                                             
#define SMB1CN0_TXMODE__BMASK       0x40 ///< SMBus Transmit Mode Indicator                  
#define SMB1CN0_TXMODE__SHIFT       0x06 ///< SMBus Transmit Mode Indicator                  
#define SMB1CN0_TXMODE__RECEIVER    0x00 ///< SMBus in Receiver Mode.                        
#define SMB1CN0_TXMODE__TRANSMITTER 0x40 ///< SMBus in Transmitter Mode.                     
                                                                                             
#define SMB1CN0_MASTER__BMASK       0x80 ///< SMBus Master/Slave Indicator                   
#define SMB1CN0_MASTER__SHIFT       0x07 ///< SMBus Master/Slave Indicator                   
#define SMB1CN0_MASTER__SLAVE       0x00 ///< SMBus operating in slave mode.                 
#define SMB1CN0_MASTER__MASTER      0x80 ///< SMBus operating in master mode.                
                                                                                             
//------------------------------------------------------------------------------
// SMB1DAT Enums (SMBus 1 Data @ 0xC2)
//------------------------------------------------------------------------------
#define SMB1DAT_SMB1DAT__FMASK 0xFF ///< SMBus 1 Data
#define SMB1DAT_SMB1DAT__SHIFT 0x00 ///< SMBus 1 Data
                                                     
//------------------------------------------------------------------------------
// SMBTC Enums (SMBus Timing and Pin Control @ 0xB9)
//------------------------------------------------------------------------------
#define SMBTC_SMB0SDD__FMASK         0x03 ///< SMBus 0 Start Detection Window                   
#define SMBTC_SMB0SDD__SHIFT         0x00 ///< SMBus 0 Start Detection Window                   
#define SMBTC_SMB0SDD__NONE          0x00 ///< No additional hold time window (0-1 SYSCLK).     
#define SMBTC_SMB0SDD__ADD_2_SYSCLKS 0x01 ///< Increase hold time window to 2-3 SYSCLKs.        
#define SMBTC_SMB0SDD__ADD_4_SYSCLKS 0x02 ///< Increase hold time window to 4-5 SYSCLKs.        
#define SMBTC_SMB0SDD__ADD_8_SYSCLKS 0x03 ///< Increase hold time window to 8-9 SYSCLKs.        
                                                                                                
#define SMBTC_SMB1SDD__FMASK         0x0C ///< SMBus 1 Start Detection Window                   
#define SMBTC_SMB1SDD__SHIFT         0x02 ///< SMBus 1 Start Detection Window                   
#define SMBTC_SMB1SDD__NONE          0x00 ///< No additional hold time requirement (0-1 SYSCLK).
#define SMBTC_SMB1SDD__ADD_2_SYSCLKS 0x04 ///< Increase hold time window to 2-3 SYSCLKs.        
#define SMBTC_SMB1SDD__ADD_4_SYSCLKS 0x08 ///< Increase hold time window to 4-5 SYSCLKs.        
#define SMBTC_SMB1SDD__ADD_8_SYSCLKS 0x0C ///< Increase hold time window to 8-9 SYSCLKs.        
                                                                                                
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
// SPI0CN0 Enums (SPI0 Control @ 0xF8)
//------------------------------------------------------------------------------
#define SPI0CN0_SPIEN__BMASK                  0x01 ///< SPI0 Enable                                       
#define SPI0CN0_SPIEN__SHIFT                  0x00 ///< SPI0 Enable                                       
#define SPI0CN0_SPIEN__DISABLED               0x00 ///< Disable the SPI module.                           
#define SPI0CN0_SPIEN__ENABLED                0x01 ///< Enable the SPI module.                            
                                                                                                          
#define SPI0CN0_TXBMT__BMASK                  0x02 ///< Transmit Buffer Empty                             
#define SPI0CN0_TXBMT__SHIFT                  0x01 ///< Transmit Buffer Empty                             
#define SPI0CN0_TXBMT__NOT_SET                0x00 ///< The transmit buffer is not empty.                 
#define SPI0CN0_TXBMT__SET                    0x02 ///< The transmit buffer is empty.                     
                                                                                                          
#define SPI0CN0_NSSMD__FMASK                  0x0C ///< Slave Select Mode                                 
#define SPI0CN0_NSSMD__SHIFT                  0x02 ///< Slave Select Mode                                 
#define SPI0CN0_NSSMD__3_WIRE                 0x00 ///< 3-Wire Slave or 3-Wire Master Mode. NSS signal is 
                                                   ///< not routed to a port pin.                         
#define SPI0CN0_NSSMD__4_WIRE_SLAVE           0x04 ///< 4-Wire Slave or Multi-Master Mode. NSS is an input
                                                   ///< to the device.                                    
#define SPI0CN0_NSSMD__4_WIRE_MASTER_NSS_LOW  0x08 ///< 4-Wire Single-Master Mode. NSS is an output and   
                                                   ///< logic low.                                        
#define SPI0CN0_NSSMD__4_WIRE_MASTER_NSS_HIGH 0x0C ///< 4-Wire Single-Master Mode. NSS is an output and   
                                                   ///< logic high.                                       
                                                                                                          
#define SPI0CN0_RXOVRN__BMASK                 0x10 ///< Receive Overrun Flag                              
#define SPI0CN0_RXOVRN__SHIFT                 0x04 ///< Receive Overrun Flag                              
#define SPI0CN0_RXOVRN__NOT_SET               0x00 ///< A receive overrun did not occur.                  
#define SPI0CN0_RXOVRN__SET                   0x10 ///< A receive overrun occurred.                       
                                                                                                          
#define SPI0CN0_MODF__BMASK                   0x20 ///< Mode Fault Flag                                   
#define SPI0CN0_MODF__SHIFT                   0x05 ///< Mode Fault Flag                                   
#define SPI0CN0_MODF__NOT_SET                 0x00 ///< A master collision did not occur.                 
#define SPI0CN0_MODF__SET                     0x20 ///< A master collision occurred.                      
                                                                                                          
#define SPI0CN0_WCOL__BMASK                   0x40 ///< Write Collision Flag                              
#define SPI0CN0_WCOL__SHIFT                   0x06 ///< Write Collision Flag                              
#define SPI0CN0_WCOL__NOT_SET                 0x00 ///< A write collision did not occur.                  
#define SPI0CN0_WCOL__SET                     0x40 ///< A write collision occurred.                       
                                                                                                          
#define SPI0CN0_SPIF__BMASK                   0x80 ///< SPI0 Interrupt Flag                               
#define SPI0CN0_SPIF__SHIFT                   0x07 ///< SPI0 Interrupt Flag                               
#define SPI0CN0_SPIF__NOT_SET                 0x00 ///< A data transfer has not completed since the last  
                                                   ///< time SPIF was cleared.                            
#define SPI0CN0_SPIF__SET                     0x80 ///< A data transfer completed.                        
                                                                                                          
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
// TMR2CN0 Enums (Timer 2 Control 0 @ 0xC8)
//------------------------------------------------------------------------------
#define TMR2CN0_T2XCLK__BMASK          0x01 ///< Timer 2 External Clock Select                    
#define TMR2CN0_T2XCLK__SHIFT          0x00 ///< Timer 2 External Clock Select                    
#define TMR2CN0_T2XCLK__SYSCLK_DIV_12  0x00 ///< Timer 2 clock is the system clock divided by 12. 
#define TMR2CN0_T2XCLK__EXTOSC_DIV_8   0x01 ///< Timer 2 clock is the external oscillator divided 
                                            ///< by 8 (synchronized with SYSCLK).                 
                                                                                                  
#define TMR2CN0_T2CSS__BMASK           0x02 ///< Timer 2 Capture Source Select                    
#define TMR2CN0_T2CSS__SHIFT           0x01 ///< Timer 2 Capture Source Select                    
#define TMR2CN0_T2CSS__USB_SOF_CAPTURE 0x00 ///< Capture source is USB SOF event.                 
#define TMR2CN0_T2CSS__LFOSC_CAPTURE   0x02 ///< Capture source is falling edge of Low-Frequency  
                                            ///< Oscillator.                                      
                                                                                                  
#define TMR2CN0_TR2__BMASK             0x04 ///< Timer 2 Run Control                              
#define TMR2CN0_TR2__SHIFT             0x02 ///< Timer 2 Run Control                              
#define TMR2CN0_TR2__STOP              0x00 ///< Stop Timer 2.                                    
#define TMR2CN0_TR2__RUN               0x04 ///< Start Timer 2 running.                           
                                                                                                  
#define TMR2CN0_T2SPLIT__BMASK         0x08 ///< Timer 2 Split Mode Enable                        
#define TMR2CN0_T2SPLIT__SHIFT         0x03 ///< Timer 2 Split Mode Enable                        
#define TMR2CN0_T2SPLIT__16_BIT_RELOAD 0x00 ///< Timer 2 operates in 16-bit auto-reload mode.     
#define TMR2CN0_T2SPLIT__8_BIT_RELOAD  0x08 ///< Timer 2 operates as two 8-bit auto-reload timers.
                                                                                                  
#define TMR2CN0_TF2CEN__BMASK          0x10 ///< Timer 2 Capture Enable                           
#define TMR2CN0_TF2CEN__SHIFT          0x04 ///< Timer 2 Capture Enable                           
#define TMR2CN0_TF2CEN__DISABLED       0x00 ///< Disable capture mode.                            
#define TMR2CN0_TF2CEN__ENABLED        0x10 ///< Enable capture mode.                             
                                                                                                  
#define TMR2CN0_TF2LEN__BMASK          0x20 ///< Timer 2 Low Byte Interrupt Enable                
#define TMR2CN0_TF2LEN__SHIFT          0x05 ///< Timer 2 Low Byte Interrupt Enable                
#define TMR2CN0_TF2LEN__DISABLED       0x00 ///< Disable low byte interrupts.                     
#define TMR2CN0_TF2LEN__ENABLED        0x20 ///< Enable low byte interrupts.                      
                                                                                                  
#define TMR2CN0_TF2L__BMASK            0x40 ///< Timer 2 Low Byte Overflow Flag                   
#define TMR2CN0_TF2L__SHIFT            0x06 ///< Timer 2 Low Byte Overflow Flag                   
#define TMR2CN0_TF2L__NOT_SET          0x00 ///< Timer 2 low byte did not overflow.               
#define TMR2CN0_TF2L__SET              0x40 ///< Timer 2 low byte overflowed.                     
                                                                                                  
#define TMR2CN0_TF2H__BMASK            0x80 ///< Timer 2 High Byte Overflow Flag                  
#define TMR2CN0_TF2H__SHIFT            0x07 ///< Timer 2 High Byte Overflow Flag                  
#define TMR2CN0_TF2H__NOT_SET          0x00 ///< Timer 2 8-bit high byte or 16-bit value did not  
                                            ///< overflow.                                        
#define TMR2CN0_TF2H__SET              0x80 ///< Timer 2 8-bit high byte or 16-bit value          
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
// TMR3CN0 Enums (Timer 3 Control 0 @ 0x91)
//------------------------------------------------------------------------------
#define TMR3CN0_T3XCLK__BMASK          0x01 ///< Timer 3 External Clock Select                    
#define TMR3CN0_T3XCLK__SHIFT          0x00 ///< Timer 3 External Clock Select                    
#define TMR3CN0_T3XCLK__SYSCLK_DIV_12  0x00 ///< Timer 3 clock is the system clock divided by 12. 
#define TMR3CN0_T3XCLK__EXTOSC_DIV_8   0x01 ///< Timer 3 clock is the external oscillator divided 
                                            ///< by 8 (synchronized with SYSCLK).                 
                                                                                                  
#define TMR3CN0_T3CSS__BMASK           0x02 ///< Timer 3 Capture Source Select                    
#define TMR3CN0_T3CSS__SHIFT           0x01 ///< Timer 3 Capture Source Select                    
#define TMR3CN0_T3CSS__USB_SOF_CAPTURE 0x00 ///< Capture source is USB SOF event.                 
#define TMR3CN0_T3CSS__LFOSC_CAPTURE   0x02 ///< Capture source is falling edge of Low-Frequency  
                                            ///< Oscillator.                                      
                                                                                                  
#define TMR3CN0_TR3__BMASK             0x04 ///< Timer 3 Run Control                              
#define TMR3CN0_TR3__SHIFT             0x02 ///< Timer 3 Run Control                              
#define TMR3CN0_TR3__STOP              0x00 ///< Stop Timer 3.                                    
#define TMR3CN0_TR3__RUN               0x04 ///< Start Timer 3 running.                           
                                                                                                  
#define TMR3CN0_T3SPLIT__BMASK         0x08 ///< Timer 3 Split Mode Enable                        
#define TMR3CN0_T3SPLIT__SHIFT         0x03 ///< Timer 3 Split Mode Enable                        
#define TMR3CN0_T3SPLIT__16_BIT_RELOAD 0x00 ///< Timer 3 operates in 16-bit auto-reload mode.     
#define TMR3CN0_T3SPLIT__8_BIT_RELOAD  0x08 ///< Timer 3 operates as two 8-bit auto-reload timers.
                                                                                                  
#define TMR3CN0_TF3CEN__BMASK          0x10 ///< Timer 3 Capture Enable                           
#define TMR3CN0_TF3CEN__SHIFT          0x04 ///< Timer 3 Capture Enable                           
#define TMR3CN0_TF3CEN__DISABLED       0x00 ///< Disable capture mode.                            
#define TMR3CN0_TF3CEN__ENABLED        0x10 ///< Enable capture mode.                             
                                                                                                  
#define TMR3CN0_TF3LEN__BMASK          0x20 ///< Timer 3 Low Byte Interrupt Enable                
#define TMR3CN0_TF3LEN__SHIFT          0x05 ///< Timer 3 Low Byte Interrupt Enable                
#define TMR3CN0_TF3LEN__DISABLED       0x00 ///< Disable low byte interrupts.                     
#define TMR3CN0_TF3LEN__ENABLED        0x20 ///< Enable low byte interrupts.                      
                                                                                                  
#define TMR3CN0_TF3L__BMASK            0x40 ///< Timer 3 Low Byte Overflow Flag                   
#define TMR3CN0_TF3L__SHIFT            0x06 ///< Timer 3 Low Byte Overflow Flag                   
#define TMR3CN0_TF3L__NOT_SET          0x00 ///< Timer 3 low byte did not overflow.               
#define TMR3CN0_TF3L__SET              0x40 ///< Timer 3 low byte overflowed.                     
                                                                                                  
#define TMR3CN0_TF3H__BMASK            0x80 ///< Timer 3 High Byte Overflow Flag                  
#define TMR3CN0_TF3H__SHIFT            0x07 ///< Timer 3 High Byte Overflow Flag                  
#define TMR3CN0_TF3H__NOT_SET          0x00 ///< Timer 3 8-bit high byte or 16-bit value did not  
                                            ///< overflow.                                        
#define TMR3CN0_TF3H__SET              0x80 ///< Timer 3 8-bit high byte or 16-bit value          
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
// TMR4CN0 Enums (Timer 4 Control 0 @ 0x91)
//------------------------------------------------------------------------------
#define TMR4CN0_T4XCLK__BMASK          0x01 ///< Timer 4 External Clock Select                    
#define TMR4CN0_T4XCLK__SHIFT          0x00 ///< Timer 4 External Clock Select                    
#define TMR4CN0_T4XCLK__SYSCLK_DIV_12  0x00 ///< Timer 4 clock is the system clock divided by 12. 
#define TMR4CN0_T4XCLK__EXTOSC_DIV_8   0x01 ///< Timer 4 clock is the external oscillator divided 
                                            ///< by 8 (synchronized with SYSCLK).                 
                                                                                                  
#define TMR4CN0_TR4__BMASK             0x04 ///< Timer 4 Run Control                              
#define TMR4CN0_TR4__SHIFT             0x02 ///< Timer 4 Run Control                              
#define TMR4CN0_TR4__STOP              0x00 ///< Stop Timer 4.                                    
#define TMR4CN0_TR4__RUN               0x04 ///< Start Timer 4 running.                           
                                                                                                  
#define TMR4CN0_T4SPLIT__BMASK         0x08 ///< Timer 4 Split Mode Enable                        
#define TMR4CN0_T4SPLIT__SHIFT         0x03 ///< Timer 4 Split Mode Enable                        
#define TMR4CN0_T4SPLIT__16_BIT_RELOAD 0x00 ///< Timer 4 operates in 16-bit auto-reload mode.     
#define TMR4CN0_T4SPLIT__8_BIT_RELOAD  0x08 ///< Timer 4 operates as two 8-bit auto-reload timers.
                                                                                                  
#define TMR4CN0_TF4LEN__BMASK          0x20 ///< Timer 4 Low Byte Interrupt Enable                
#define TMR4CN0_TF4LEN__SHIFT          0x05 ///< Timer 4 Low Byte Interrupt Enable                
#define TMR4CN0_TF4LEN__DISABLED       0x00 ///< Disable low byte interrupts.                     
#define TMR4CN0_TF4LEN__ENABLED        0x20 ///< Enable low byte interrupts.                      
                                                                                                  
#define TMR4CN0_TF4L__BMASK            0x40 ///< Timer 4 Low Byte Overflow Flag                   
#define TMR4CN0_TF4L__SHIFT            0x06 ///< Timer 4 Low Byte Overflow Flag                   
#define TMR4CN0_TF4L__NOT_SET          0x00 ///< Timer 4 low byte did not overflow.               
#define TMR4CN0_TF4L__SET              0x40 ///< Timer 4 low byte overflowed.                     
                                                                                                  
#define TMR4CN0_TF4H__BMASK            0x80 ///< Timer 4 High Byte Overflow Flag                  
#define TMR4CN0_TF4H__SHIFT            0x07 ///< Timer 4 High Byte Overflow Flag                  
#define TMR4CN0_TF4H__NOT_SET          0x00 ///< Timer 4 8-bit high byte or 16-bit value did not  
                                            ///< overflow.                                        
#define TMR4CN0_TF4H__SET              0x80 ///< Timer 4 8-bit high byte or 16-bit value          
                                            ///< overflowed.                                      
                                                                                                  
//------------------------------------------------------------------------------
// TMR4H Enums (Timer 4 High Byte @ 0x95)
//------------------------------------------------------------------------------
#define TMR4H_TMR4H__FMASK 0xFF ///< Timer 4 High Byte
#define TMR4H_TMR4H__SHIFT 0x00 ///< Timer 4 High Byte
                                                      
//------------------------------------------------------------------------------
// TMR4L Enums (Timer 4 Low Byte @ 0x94)
//------------------------------------------------------------------------------
#define TMR4L_TMR4L__FMASK 0xFF ///< Timer 4 Low Byte
#define TMR4L_TMR4L__SHIFT 0x00 ///< Timer 4 Low Byte
                                                     
//------------------------------------------------------------------------------
// TMR4RLH Enums (Timer 4 Reload High Byte @ 0x93)
//------------------------------------------------------------------------------
#define TMR4RLH_TMR4RLH__FMASK 0xFF ///< Timer 4 Reload High Byte
#define TMR4RLH_TMR4RLH__SHIFT 0x00 ///< Timer 4 Reload High Byte
                                                                 
//------------------------------------------------------------------------------
// TMR4RLL Enums (Timer 4 Reload Low Byte @ 0x92)
//------------------------------------------------------------------------------
#define TMR4RLL_TMR4RLL__FMASK 0xFF ///< Timer 4 Reload Low Byte
#define TMR4RLL_TMR4RLL__SHIFT 0x00 ///< Timer 4 Reload Low Byte
                                                                
//------------------------------------------------------------------------------
// TMR5CN0 Enums (Timer 5 Control 0 @ 0xC8)
//------------------------------------------------------------------------------
#define TMR5CN0_T5XCLK__BMASK          0x01 ///< Timer 5 External Clock Select                    
#define TMR5CN0_T5XCLK__SHIFT          0x00 ///< Timer 5 External Clock Select                    
#define TMR5CN0_T5XCLK__SYSCLK_DIV_12  0x00 ///< Timer 5 clock is the system clock divided by 12. 
#define TMR5CN0_T5XCLK__EXTOSC_DIV_8   0x01 ///< Timer 5 clock is the external oscillator divided 
                                            ///< by 8 (synchronized with SYSCLK).                 
                                                                                                  
#define TMR5CN0_TR5__BMASK             0x04 ///< Timer 5 Run Control                              
#define TMR5CN0_TR5__SHIFT             0x02 ///< Timer 5 Run Control                              
#define TMR5CN0_TR5__STOP              0x00 ///< Stop Timer 5.                                    
#define TMR5CN0_TR5__RUN               0x04 ///< Start Timer 5 running.                           
                                                                                                  
#define TMR5CN0_T5SPLIT__BMASK         0x08 ///< Timer 5 Split Mode Enable                        
#define TMR5CN0_T5SPLIT__SHIFT         0x03 ///< Timer 5 Split Mode Enable                        
#define TMR5CN0_T5SPLIT__16_BIT_RELOAD 0x00 ///< Timer 5 operates in 16-bit auto-reload mode.     
#define TMR5CN0_T5SPLIT__8_BIT_RELOAD  0x08 ///< Timer 5 operates as two 8-bit auto-reload timers.
                                                                                                  
#define TMR5CN0_TF5LEN__BMASK          0x20 ///< Timer 5 Low Byte Interrupt Enable                
#define TMR5CN0_TF5LEN__SHIFT          0x05 ///< Timer 5 Low Byte Interrupt Enable                
#define TMR5CN0_TF5LEN__DISABLED       0x00 ///< Disable low byte interrupts.                     
#define TMR5CN0_TF5LEN__ENABLED        0x20 ///< Enable low byte interrupts.                      
                                                                                                  
#define TMR5CN0_TF5L__BMASK            0x40 ///< Timer 5 Low Byte Overflow Flag                   
#define TMR5CN0_TF5L__SHIFT            0x06 ///< Timer 5 Low Byte Overflow Flag                   
#define TMR5CN0_TF5L__NOT_SET          0x00 ///< Timer 5 low byte did not overflow.               
#define TMR5CN0_TF5L__SET              0x40 ///< Timer 5 low byte overflowed.                     
                                                                                                  
#define TMR5CN0_TF5H__BMASK            0x80 ///< Timer 5 High Byte Overflow Flag                  
#define TMR5CN0_TF5H__SHIFT            0x07 ///< Timer 5 High Byte Overflow Flag                  
#define TMR5CN0_TF5H__NOT_SET          0x00 ///< Timer 5 8-bit high byte or 16-bit value did not  
                                            ///< overflow.                                        
#define TMR5CN0_TF5H__SET              0x80 ///< Timer 5 8-bit high byte or 16-bit value          
                                            ///< overflowed.                                      
                                                                                                  
//------------------------------------------------------------------------------
// TMR5H Enums (Timer 5 High Byte @ 0xCD)
//------------------------------------------------------------------------------
#define TMR5H_TMR5H__FMASK 0xFF ///< Timer 5 High Byte
#define TMR5H_TMR5H__SHIFT 0x00 ///< Timer 5 High Byte
                                                      
//------------------------------------------------------------------------------
// TMR5L Enums (Timer 5 Low Byte @ 0xCC)
//------------------------------------------------------------------------------
#define TMR5L_TMR5L__FMASK 0xFF ///< Timer 5 Low Byte
#define TMR5L_TMR5L__SHIFT 0x00 ///< Timer 5 Low Byte
                                                     
//------------------------------------------------------------------------------
// TMR5RLH Enums (Timer 5 Reload High Byte @ 0xCB)
//------------------------------------------------------------------------------
#define TMR5RLH_TMR5RLH__FMASK 0xFF ///< Timer 5 Reload High Byte
#define TMR5RLH_TMR5RLH__SHIFT 0x00 ///< Timer 5 Reload High Byte
                                                                 
//------------------------------------------------------------------------------
// TMR5RLL Enums (Timer 5 Reload Low Byte @ 0xCA)
//------------------------------------------------------------------------------
#define TMR5RLL_TMR5RLL__FMASK 0xFF ///< Timer 5 Reload Low Byte
#define TMR5RLL_TMR5RLL__SHIFT 0x00 ///< Timer 5 Reload Low Byte
                                                                
//------------------------------------------------------------------------------
// CKCON0 Enums (Clock Control 0 @ 0x8E)
//------------------------------------------------------------------------------
#define CKCON0_SCA__FMASK           0x03 ///< Timer 0/1 Prescale                                
#define CKCON0_SCA__SHIFT           0x00 ///< Timer 0/1 Prescale                                
#define CKCON0_SCA__SYSCLK_DIV_12   0x00 ///< System clock divided by 12.                       
#define CKCON0_SCA__SYSCLK_DIV_4    0x01 ///< System clock divided by 4.                        
#define CKCON0_SCA__SYSCLK_DIV_48   0x02 ///< System clock divided by 48.                       
#define CKCON0_SCA__EXTOSC_DIV_8    0x03 ///< External oscillator divided by 8 (synchronized    
                                         ///< with the system clock).                           
                                                                                                
#define CKCON0_T0M__BMASK           0x04 ///< Timer 0 Clock Select                              
#define CKCON0_T0M__SHIFT           0x02 ///< Timer 0 Clock Select                              
#define CKCON0_T0M__PRESCALE        0x00 ///< Counter/Timer 0 uses the clock defined by the     
                                         ///< prescale field, SCA.                              
#define CKCON0_T0M__SYSCLK          0x04 ///< Counter/Timer 0 uses the system clock.            
                                                                                                
#define CKCON0_T1M__BMASK           0x08 ///< Timer 1 Clock Select                              
#define CKCON0_T1M__SHIFT           0x03 ///< Timer 1 Clock Select                              
#define CKCON0_T1M__PRESCALE        0x00 ///< Timer 1 uses the clock defined by the prescale    
                                         ///< field, SCA.                                       
#define CKCON0_T1M__SYSCLK          0x08 ///< Timer 1 uses the system clock.                    
                                                                                                
#define CKCON0_T2ML__BMASK          0x10 ///< Timer 2 Low Byte Clock Select                     
#define CKCON0_T2ML__SHIFT          0x04 ///< Timer 2 Low Byte Clock Select                     
#define CKCON0_T2ML__EXTERNAL_CLOCK 0x00 ///< Timer 2 low byte uses the clock defined by T2XCLK 
                                         ///< in TMR2CN0.                                       
#define CKCON0_T2ML__SYSCLK         0x10 ///< Timer 2 low byte uses the system clock.           
                                                                                                
#define CKCON0_T2MH__BMASK          0x20 ///< Timer 2 High Byte Clock Select                    
#define CKCON0_T2MH__SHIFT          0x05 ///< Timer 2 High Byte Clock Select                    
#define CKCON0_T2MH__EXTERNAL_CLOCK 0x00 ///< Timer 2 high byte uses the clock defined by T2XCLK
                                         ///< in TMR2CN0.                                       
#define CKCON0_T2MH__SYSCLK         0x20 ///< Timer 2 high byte uses the system clock.          
                                                                                                
#define CKCON0_T3ML__BMASK          0x40 ///< Timer 3 Low Byte Clock Select                     
#define CKCON0_T3ML__SHIFT          0x06 ///< Timer 3 Low Byte Clock Select                     
#define CKCON0_T3ML__EXTERNAL_CLOCK 0x00 ///< Timer 3 low byte uses the clock defined by T3XCLK 
                                         ///< in TMR3CN0.                                       
#define CKCON0_T3ML__SYSCLK         0x40 ///< Timer 3 low byte uses the system clock.           
                                                                                                
#define CKCON0_T3MH__BMASK          0x80 ///< Timer 3 High Byte Clock Select                    
#define CKCON0_T3MH__SHIFT          0x07 ///< Timer 3 High Byte Clock Select                    
#define CKCON0_T3MH__EXTERNAL_CLOCK 0x00 ///< Timer 3 high byte uses the clock defined by T3XCLK
                                         ///< in TMR3CN0.                                       
#define CKCON0_T3MH__SYSCLK         0x80 ///< Timer 3 high byte uses the system clock.          
                                                                                                
//------------------------------------------------------------------------------
// CKCON1 Enums (Clock Control 1 @ 0xE4)
//------------------------------------------------------------------------------
#define CKCON1_T4ML__BMASK          0x01 ///< Timer 4 Low Byte Clock Select                     
#define CKCON1_T4ML__SHIFT          0x00 ///< Timer 4 Low Byte Clock Select                     
#define CKCON1_T4ML__EXTERNAL_CLOCK 0x00 ///< Timer 4 low byte uses the clock defined by T4XCLK 
                                         ///< in TMR4CN0.                                       
#define CKCON1_T4ML__SYSCLK         0x01 ///< Timer 4 low byte uses the system clock.           
                                                                                                
#define CKCON1_T4MH__BMASK          0x02 ///< Timer 4 High Byte Clock Select                    
#define CKCON1_T4MH__SHIFT          0x01 ///< Timer 4 High Byte Clock Select                    
#define CKCON1_T4MH__EXTERNAL_CLOCK 0x00 ///< Timer 4 high byte uses the clock defined by T4XCLK
                                         ///< in TMR4CN0.                                       
#define CKCON1_T4MH__SYSCLK         0x02 ///< Timer 4 high byte uses the system clock.          
                                                                                                
#define CKCON1_T5ML__BMASK          0x04 ///< Timer 5 Low Byte Clock Select                     
#define CKCON1_T5ML__SHIFT          0x02 ///< Timer 5 Low Byte Clock Select                     
#define CKCON1_T5ML__EXTERNAL_CLOCK 0x00 ///< Timer 5 low byte uses the clock defined by T5XCLK 
                                         ///< in TMR5CN.                                        
#define CKCON1_T5ML__SYSCLK         0x04 ///< Timer 5 low byte uses the system clock.           
                                                                                                
#define CKCON1_T5MH__BMASK          0x08 ///< Timer 5 High Byte Clock Select                    
#define CKCON1_T5MH__SHIFT          0x03 ///< Timer 5 High Byte Clock Select                    
#define CKCON1_T5MH__EXTERNAL_CLOCK 0x00 ///< Timer 5 high byte uses the clock defined by T5XCLK
                                         ///< in TMR5CN.                                        
#define CKCON1_T5MH__SYSCLK         0x08 ///< Timer 5 high byte uses the system clock.          
                                                                                                
//------------------------------------------------------------------------------
// TCON Enums (Timer 0/1 Control @ 0x88)
//------------------------------------------------------------------------------
#define TCON_IT0__BMASK   0x01 ///< Interrupt 0 Type Select  
#define TCON_IT0__SHIFT   0x00 ///< Interrupt 0 Type Select  
#define TCON_IT0__LEVEL   0x00 ///< INT0 is level triggered. 
#define TCON_IT0__EDGE    0x01 ///< INT0 is edge triggered.  
                                                             
#define TCON_IE0__BMASK   0x02 ///< External Interrupt 0     
#define TCON_IE0__SHIFT   0x01 ///< External Interrupt 0     
#define TCON_IE0__NOT_SET 0x00 ///< Edge/level not detected. 
#define TCON_IE0__SET     0x02 ///< Edge/level detected      
                                                             
#define TCON_IT1__BMASK   0x04 ///< Interrupt 1 Type Select  
#define TCON_IT1__SHIFT   0x02 ///< Interrupt 1 Type Select  
#define TCON_IT1__LEVEL   0x00 ///< INT1 is level triggered. 
#define TCON_IT1__EDGE    0x04 ///< INT1 is edge triggered.  
                                                             
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
                                  ///< defined by T0M in the CKCON0 register.            
#define TMOD_CT0__COUNTER    0x04 ///< Counter Mode. Timer 0 increments on high-to-low   
                                  ///< transitions of an external pin (T0).              
                                                                                         
#define TMOD_GATE0__BMASK    0x08 ///< Timer 0 Gate Control                              
#define TMOD_GATE0__SHIFT    0x03 ///< Timer 0 Gate Control                              
#define TMOD_GATE0__DISABLED 0x00 ///< Timer 0 enabled when TR0 = 1 irrespective of INT0 
                                  ///< logic level.                                      
#define TMOD_GATE0__ENABLED  0x08 ///< Timer 0 enabled only when TR0 = 1 and INT0 is     
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
                                  ///< defined by T1M in the CKCON0 register.            
#define TMOD_CT1__COUNTER    0x40 ///< Counter Mode. Timer 1 increments on high-to-low   
                                  ///< transitions of an external pin (T1).              
                                                                                         
#define TMOD_GATE1__BMASK    0x80 ///< Timer 1 Gate Control                              
#define TMOD_GATE1__SHIFT    0x07 ///< Timer 1 Gate Control                              
#define TMOD_GATE1__DISABLED 0x00 ///< Timer 1 enabled when TR1 = 1 irrespective of INT1 
                                  ///< logic level.                                      
#define TMOD_GATE1__ENABLED  0x80 ///< Timer 1 enabled only when TR1 = 1 and INT1 is     
                                  ///< active as defined by bit IN1PL in register IT01CF.
                                                                                         
//------------------------------------------------------------------------------
// SBCON1 Enums (UART1 Baud Rate Generator Control @ 0xAC)
//------------------------------------------------------------------------------
#define SBCON1_BPS__FMASK     0x03 ///< Baud Rate Prescaler Select                     
#define SBCON1_BPS__SHIFT     0x00 ///< Baud Rate Prescaler Select                     
#define SBCON1_BPS__DIV_BY_12 0x00 ///< Prescaler = 12.                                
#define SBCON1_BPS__DIV_BY_4  0x01 ///< Prescaler = 4.                                 
#define SBCON1_BPS__DIV_BY_48 0x02 ///< Prescaler = 48.                                
#define SBCON1_BPS__DIV_BY_1  0x03 ///< Prescaler = 1.                                 
                                                                                       
#define SBCON1_BREN__BMASK    0x40 ///< Baud Rate Generator Enable                     
#define SBCON1_BREN__SHIFT    0x06 ///< Baud Rate Generator Enable                     
#define SBCON1_BREN__DISABLED 0x00 ///< Disable the baud rate generator. UART1 will not
                                   ///< function.                                      
#define SBCON1_BREN__ENABLED  0x40 ///< Enable the baud rate generator.                
                                                                                       
//------------------------------------------------------------------------------
// SBRLH1 Enums (UART1 Baud Rate Generator High Byte @ 0xB5)
//------------------------------------------------------------------------------
#define SBRLH1_BRH__FMASK 0xFF ///< UART1 Baud Rate Reload High
#define SBRLH1_BRH__SHIFT 0x00 ///< UART1 Baud Rate Reload High
                                                               
//------------------------------------------------------------------------------
// SBRLL1 Enums (UART1 Baud Rate Generator Low Byte @ 0xB4)
//------------------------------------------------------------------------------
#define SBRLL1_BRL__FMASK 0xFF ///< UART1 Baud Rate Reload Low
#define SBRLL1_BRL__SHIFT 0x00 ///< UART1 Baud Rate Reload Low
                                                              
//------------------------------------------------------------------------------
// SBUF1 Enums (UART1 Serial Port Data Buffer @ 0xD3)
//------------------------------------------------------------------------------
#define SBUF1_SBUF1__FMASK 0xFF ///< Serial Port Data Buffer
#define SBUF1_SBUF1__SHIFT 0x00 ///< Serial Port Data Buffer
                                                            
//------------------------------------------------------------------------------
// SCON1 Enums (UART1 Serial Port Control @ 0xD2)
//------------------------------------------------------------------------------
#define SCON1_RI__BMASK             0x01 ///< Receive Interrupt Flag                           
#define SCON1_RI__SHIFT             0x00 ///< Receive Interrupt Flag                           
#define SCON1_RI__NOT_SET           0x00 ///< New data has not been received by UART1.         
#define SCON1_RI__SET               0x01 ///< UART1 received one or more data bytes.           
                                                                                               
#define SCON1_TI__BMASK             0x02 ///< Transmit Interrupt Flag                          
#define SCON1_TI__SHIFT             0x01 ///< Transmit Interrupt Flag                          
#define SCON1_TI__NOT_SET           0x00 ///< A byte of data has not been transmitted by UART1.
#define SCON1_TI__SET               0x02 ///< UART1 transmitted a byte of data.                
                                                                                               
#define SCON1_RBX__BMASK            0x04 ///< Extra Receive Bit                                
#define SCON1_RBX__SHIFT            0x02 ///< Extra Receive Bit                                
#define SCON1_RBX__LOW              0x00 ///< The extra bit or the first stop bit is 0.        
#define SCON1_RBX__HIGH             0x04 ///< The extra bit or the first stop bit is 1.        
                                                                                               
#define SCON1_TBX__BMASK            0x08 ///< Extra Transmission Bit                           
#define SCON1_TBX__SHIFT            0x03 ///< Extra Transmission Bit                           
#define SCON1_TBX__LOW              0x00 ///< Set extra bit to 0 (low).                        
#define SCON1_TBX__HIGH             0x08 ///< Set extra bit to 1 (high).                       
                                                                                               
#define SCON1_REN__BMASK            0x10 ///< Receive Enable                                   
#define SCON1_REN__SHIFT            0x04 ///< Receive Enable                                   
#define SCON1_REN__RECEIVE_DISABLED 0x00 ///< UART1 reception disabled.                        
#define SCON1_REN__RECEIVE_ENABLED  0x10 ///< UART1 reception enabled.                         
                                                                                               
#define SCON1_PERR__BMASK           0x40 ///< Parity Error Flag                                
#define SCON1_PERR__SHIFT           0x06 ///< Parity Error Flag                                
#define SCON1_PERR__NOT_SET         0x00 ///< Parity error has not occurred.                   
#define SCON1_PERR__SET             0x40 ///< Parity error has occurred.                       
                                                                                               
#define SCON1_OVR__BMASK            0x80 ///< Receive FIFO Overrun Flag                        
#define SCON1_OVR__SHIFT            0x07 ///< Receive FIFO Overrun Flag                        
#define SCON1_OVR__NOT_SET          0x00 ///< Receive FIFO overrun has not occurred.           
#define SCON1_OVR__SET              0x80 ///< Receive FIFO overrun has occurred.               
                                                                                               
//------------------------------------------------------------------------------
// SMOD1 Enums (UART1 Mode @ 0xE5)
//------------------------------------------------------------------------------
#define SMOD1_SBL__BMASK          0x01 ///< Stop Bit Length                                 
#define SMOD1_SBL__SHIFT          0x00 ///< Stop Bit Length                                 
#define SMOD1_SBL__SHORT          0x00 ///< Short: Stop bit is active for one bit time.     
#define SMOD1_SBL__LONG           0x01 ///< Long: Stop bit is active for two bit times (data
                                       ///< length = 6, 7, or 8 bits) or 1.5 bit times (data
                                       ///< length = 5 bits).                               
                                                                                            
#define SMOD1_XBE__BMASK          0x02 ///< Extra Bit Enable                                
#define SMOD1_XBE__SHIFT          0x01 ///< Extra Bit Enable                                
#define SMOD1_XBE__DISABLED       0x00 ///< Disable the extra bit.                          
#define SMOD1_XBE__ENABLED        0x02 ///< Enable the extra bit.                           
                                                                                            
#define SMOD1_SDL__FMASK          0x0C ///< Data Length                                     
#define SMOD1_SDL__SHIFT          0x02 ///< Data Length                                     
#define SMOD1_SDL__5_BITS         0x00 ///< 5 bits.                                         
#define SMOD1_SDL__6_BITS         0x04 ///< 6 bits.                                         
#define SMOD1_SDL__7_BITS         0x08 ///< 7 bits.                                         
#define SMOD1_SDL__8_BITS         0x0C ///< 8 bits.                                         
                                                                                            
#define SMOD1_PE__BMASK           0x10 ///< Parity Enable                                   
#define SMOD1_PE__SHIFT           0x04 ///< Parity Enable                                   
#define SMOD1_PE__PARITY_DISABLED 0x00 ///< Disable hardware parity.                        
#define SMOD1_PE__PARITY_ENABLED  0x10 ///< Enable hardware parity.                         
                                                                                            
#define SMOD1_SPT__FMASK          0x60 ///< Parity Type                                     
#define SMOD1_SPT__SHIFT          0x05 ///< Parity Type                                     
#define SMOD1_SPT__ODD_PARITY     0x00 ///< Odd.                                            
#define SMOD1_SPT__EVEN_PARITY    0x20 ///< Even.                                           
#define SMOD1_SPT__MARK_PARITY    0x40 ///< Mark.                                           
#define SMOD1_SPT__SPACE_PARITY   0x60 ///< Space.                                          
                                                                                            
#define SMOD1_MCE__BMASK          0x80 ///< Multiprocessor Communication Enable             
#define SMOD1_MCE__SHIFT          0x07 ///< Multiprocessor Communication Enable             
#define SMOD1_MCE__MULTI_DISABLED 0x00 ///< RI will be activated if the stop bits are 1.    
#define SMOD1_MCE__MULTI_ENABLED  0x80 ///< RI will be activated if the stop bits and extra 
                                       ///< bit are 1. The extra bit must be enabled using  
                                       ///< XBE.                                            
                                                                                            
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
// CLKREC Enums (USB0 Clock Recovery Control @ 0x0F)
//------------------------------------------------------------------------------
#define CLKREC_CRLOW__BMASK      0x20 ///< Low Speed Clock Recovery Mode               
#define CLKREC_CRLOW__SHIFT      0x05 ///< Low Speed Clock Recovery Mode               
#define CLKREC_CRLOW__FULL_SPEED 0x00 ///< Full Speed Mode.                            
#define CLKREC_CRLOW__LOW_SPEED  0x20 ///< Low Speed Mode.                             
                                                                                       
#define CLKREC_CRSSEN__BMASK     0x40 ///< Clock Recovery Single Step                  
#define CLKREC_CRSSEN__SHIFT     0x06 ///< Clock Recovery Single Step                  
#define CLKREC_CRSSEN__DISABLED  0x00 ///< Disable single-step mode (normal calibration
                                      ///< mode).                                      
#define CLKREC_CRSSEN__ENABLED   0x40 ///< Enable single-step mode.                    
                                                                                       
#define CLKREC_CRE__BMASK        0x80 ///< Clock Recovery Enable                       
#define CLKREC_CRE__SHIFT        0x07 ///< Clock Recovery Enable                       
#define CLKREC_CRE__DISABLED     0x00 ///< Disable clock recovery.                     
#define CLKREC_CRE__ENABLED      0x80 ///< Enable clock recovery.                      
                                                                                       
//------------------------------------------------------------------------------
// CMIE Enums (USB0 Common Interrupt Enable @ 0x0B)
//------------------------------------------------------------------------------
#define CMIE_SUSINTE__BMASK    0x01 ///< Suspend Interrupt Enable       
#define CMIE_SUSINTE__SHIFT    0x00 ///< Suspend Interrupt Enable       
#define CMIE_SUSINTE__DISABLED 0x00 ///< Disable suspend interrupts.    
#define CMIE_SUSINTE__ENABLED  0x01 ///< Enable suspend interrupts.     
                                                                        
#define CMIE_RSUINTE__BMASK    0x02 ///< Resume Interrupt Enable        
#define CMIE_RSUINTE__SHIFT    0x01 ///< Resume Interrupt Enable        
#define CMIE_RSUINTE__DISABLED 0x00 ///< Disable resume interrupts.     
#define CMIE_RSUINTE__ENABLED  0x02 ///< Enable resume interrupts.      
                                                                        
#define CMIE_RSTINTE__BMASK    0x04 ///< Reset Interrupt Enable         
#define CMIE_RSTINTE__SHIFT    0x02 ///< Reset Interrupt Enable         
#define CMIE_RSTINTE__DISABLED 0x00 ///< Disable reset interrupts.      
#define CMIE_RSTINTE__ENABLED  0x04 ///< Enable reset interrupts.       
                                                                        
#define CMIE_SOFE__BMASK       0x08 ///< Start of Frame Interrupt Enable
#define CMIE_SOFE__SHIFT       0x03 ///< Start of Frame Interrupt Enable
#define CMIE_SOFE__DISABLED    0x00 ///< Disable SOF interrupts.        
#define CMIE_SOFE__ENABLED     0x08 ///< Enable SOF interrupts.         
                                                                        
//------------------------------------------------------------------------------
// CMINT Enums (USB0 Common Interrupt @ 0x06)
//------------------------------------------------------------------------------
#define CMINT_SUSINT__BMASK   0x01 ///< Suspend Interrupt Flag       
#define CMINT_SUSINT__SHIFT   0x00 ///< Suspend Interrupt Flag       
#define CMINT_SUSINT__NOT_SET 0x00 ///< Suspend interrupt inactive.  
#define CMINT_SUSINT__SET     0x01 ///< Suspend interrupt active.    
                                                                     
#define CMINT_RSUINT__BMASK   0x02 ///< Resume Interrupt Flag        
#define CMINT_RSUINT__SHIFT   0x01 ///< Resume Interrupt Flag        
#define CMINT_RSUINT__NOT_SET 0x00 ///< Resume interrupt inactive.   
#define CMINT_RSUINT__SET     0x02 ///< Resume interrupt active.     
                                                                     
#define CMINT_RSTINT__BMASK   0x04 ///< Reset Interrupt Flag         
#define CMINT_RSTINT__SHIFT   0x02 ///< Reset Interrupt Flag         
#define CMINT_RSTINT__NOT_SET 0x00 ///< Reset interrupt inactive.    
#define CMINT_RSTINT__SET     0x04 ///< Reset interrupt active.      
                                                                     
#define CMINT_SOF__BMASK      0x08 ///< Start of Frame Interrupt Flag
#define CMINT_SOF__SHIFT      0x03 ///< Start of Frame Interrupt Flag
#define CMINT_SOF__NOT_SET    0x00 ///< SOF interrupt inactive.      
#define CMINT_SOF__SET        0x08 ///< SOF interrupt active.        
                                                                     
//------------------------------------------------------------------------------
// E0CNT Enums (USB0 Endpoint0 Data Count @ 0x16)
//------------------------------------------------------------------------------
#define E0CNT_E0CNT__FMASK 0x7F ///< Endpoint 0 Data Count
#define E0CNT_E0CNT__SHIFT 0x00 ///< Endpoint 0 Data Count
                                                          
//------------------------------------------------------------------------------
// E0CSR Enums (USB0 Endpoint0 Control @ 0x11)
//------------------------------------------------------------------------------
#define E0CSR_OPRDY__BMASK     0x01 ///< OUT Packet Ready                                  
#define E0CSR_OPRDY__SHIFT     0x00 ///< OUT Packet Ready                                  
#define E0CSR_OPRDY__NOT_SET   0x00 ///< A data packet has not been received.              
#define E0CSR_OPRDY__SET       0x01 ///< A data packet has been received.                  
                                                                                           
#define E0CSR_INPRDY__BMASK    0x02 ///< IN Packet Ready                                   
#define E0CSR_INPRDY__SHIFT    0x01 ///< IN Packet Ready                                   
#define E0CSR_INPRDY__NOT_SET  0x00 ///< An IN packet is not ready to transmit.            
#define E0CSR_INPRDY__SET      0x02 ///< An IN packet is ready to transmit.                
                                                                                           
#define E0CSR_STSTL__BMASK     0x04 ///< Sent Stall                                        
#define E0CSR_STSTL__SHIFT     0x02 ///< Sent Stall                                        
#define E0CSR_STSTL__NOT_SET   0x00 ///< A STALL handshake signal was not transmitted.     
#define E0CSR_STSTL__SET       0x04 ///< A STALL handshake signal was transmitted.         
                                                                                           
#define E0CSR_DATAEND__BMASK   0x08 ///< Data End                                          
#define E0CSR_DATAEND__SHIFT   0x03 ///< Data End                                          
#define E0CSR_DATAEND__NOT_SET 0x00 ///< This is not the last data packet.                 
#define E0CSR_DATAEND__SET     0x08 ///< This is the last data packet.                     
                                                                                           
#define E0CSR_SUEND__BMASK     0x10 ///< Setup End                                         
#define E0CSR_SUEND__SHIFT     0x04 ///< Setup End                                         
#define E0CSR_SUEND__NOT_SET   0x00 ///< A control transaction did not end before firmware 
                                    ///< wrote a 1 to the DATAEND bit.                     
#define E0CSR_SUEND__SET       0x10 ///< A control transaction ended before firmware wrote 
                                    ///< a 1 to the DATAEND bit.                           
                                                                                           
#define E0CSR_SDSTL__BMASK     0x20 ///< Send Stall                                        
#define E0CSR_SDSTL__SHIFT     0x05 ///< Send Stall                                        
#define E0CSR_SDSTL__NOT_SET   0x00 ///< Do not send a STALL.                              
#define E0CSR_SDSTL__SET       0x20 ///< Send a STALL.                                     
                                                                                           
#define E0CSR_SOPRDY__BMASK    0x40 ///< Serviced OPRDY                                    
#define E0CSR_SOPRDY__SHIFT    0x06 ///< Serviced OPRDY                                    
#define E0CSR_SOPRDY__NOT_SET  0x00 ///< OUT packet has not been serviced.                 
#define E0CSR_SOPRDY__SET      0x40 ///< OUT packet has been serviced.                     
                                                                                           
#define E0CSR_SSUEND__BMASK    0x80 ///< Serviced Setup End                                
#define E0CSR_SSUEND__SHIFT    0x07 ///< Serviced Setup End                                
#define E0CSR_SSUEND__NOT_SET  0x00 ///< The setup end (SUEND) event has not been serviced.
#define E0CSR_SSUEND__SET      0x80 ///< The setup end (SUEND) event has been serviced.    
                                                                                           
//------------------------------------------------------------------------------
// EENABLE Enums (USB0 Endpoint Enable @ 0x1E)
//------------------------------------------------------------------------------
#define EENABLE_EEN1__BMASK    0x02 ///< Endpoint 1 Enable                                
#define EENABLE_EEN1__SHIFT    0x01 ///< Endpoint 1 Enable                                
#define EENABLE_EEN1__DISABLED 0x00 ///< Disable Endpoint 1 (no NACK, ACK, or STALL on the
                                    ///< USB network).                                    
#define EENABLE_EEN1__ENABLED  0x02 ///< Enable Endpoint 1 (normal).                      
                                                                                          
#define EENABLE_EEN2__BMASK    0x04 ///< Endpoint 2 Enable                                
#define EENABLE_EEN2__SHIFT    0x02 ///< Endpoint 2 Enable                                
#define EENABLE_EEN2__DISABLED 0x00 ///< Disable Endpoint 2 (no NACK, ACK, or STALL on the
                                    ///< USB network).                                    
#define EENABLE_EEN2__ENABLED  0x04 ///< Enable Endpoint 2 (normal).                      
                                                                                          
#define EENABLE_EEN3__BMASK    0x08 ///< Endpoint 3 Enable                                
#define EENABLE_EEN3__SHIFT    0x03 ///< Endpoint 3 Enable                                
#define EENABLE_EEN3__DISABLED 0x00 ///< Disable Endpoint 3 (no NACK, ACK, or STALL on the
                                    ///< USB network).                                    
#define EENABLE_EEN3__ENABLED  0x08 ///< Enable Endpoint 3 (normal).                      
                                                                                          
//------------------------------------------------------------------------------
// EINCSRH Enums (USB0 IN Endpoint Control High @ 0x12)
//------------------------------------------------------------------------------
#define EINCSRH_SPLIT__BMASK        0x04 ///< FIFO Split Enable                                
#define EINCSRH_SPLIT__SHIFT        0x02 ///< FIFO Split Enable                                
#define EINCSRH_SPLIT__DISABLED     0x00 ///< Disable split mode.                              
#define EINCSRH_SPLIT__ENABLED      0x04 ///< Enable split mode.                               
                                                                                               
#define EINCSRH_FCDT__BMASK         0x08 ///< Force Data Toggle                                
#define EINCSRH_FCDT__SHIFT         0x03 ///< Force Data Toggle                                
#define EINCSRH_FCDT__ACK_TOGGLE    0x00 ///< Endpoint data toggle switches only when an ACK is
                                         ///< received following a data packet transmission.   
#define EINCSRH_FCDT__ALWAYS_TOGGLE 0x08 ///< Endpoint data toggle forced to switch after every
                                         ///< data packet is transmitted, regardless of ACK    
                                         ///< reception.                                       
                                                                                               
#define EINCSRH_DIRSEL__BMASK       0x20 ///< Endpoint Direction Select                        
#define EINCSRH_DIRSEL__SHIFT       0x05 ///< Endpoint Direction Select                        
#define EINCSRH_DIRSEL__OUT         0x00 ///< Endpoint direction selected as OUT.              
#define EINCSRH_DIRSEL__IN          0x20 ///< Endpoint direction selected as IN.               
                                                                                               
#define EINCSRH_ISO__BMASK          0x40 ///< Isochronous Transfer Enable                      
#define EINCSRH_ISO__SHIFT          0x06 ///< Isochronous Transfer Enable                      
#define EINCSRH_ISO__DISABLED       0x00 ///< Endpoint configured for Bulk/Interrupt transfers.
#define EINCSRH_ISO__ENABLED        0x40 ///< Endpoint configured for Isochronous transfers.   
                                                                                               
#define EINCSRH_DBIEN__BMASK        0x80 ///< IN Endpoint Double-Buffer Enable                 
#define EINCSRH_DBIEN__SHIFT        0x07 ///< IN Endpoint Double-Buffer Enable                 
#define EINCSRH_DBIEN__DISABLED     0x00 ///< Disable double-buffering for the selected IN     
                                         ///< endpoint.                                        
#define EINCSRH_DBIEN__ENABLED      0x80 ///< Enable double-buffering for the selected IN      
                                         ///< endpoint.                                        
                                                                                               
//------------------------------------------------------------------------------
// EINCSRL Enums (USB0 IN Endpoint Control Low @ 0x11)
//------------------------------------------------------------------------------
#define EINCSRL_INPRDY__BMASK     0x01 ///< In Packet Ready                                   
#define EINCSRL_INPRDY__SHIFT     0x00 ///< In Packet Ready                                   
#define EINCSRL_INPRDY__NOT_SET   0x00 ///< A packet is not available in the Endpoint IN FIFO.
#define EINCSRL_INPRDY__SET       0x01 ///< A packet is available in the Endpoint IN FIFO.    
                                                                                              
#define EINCSRL_FIFONE__BMASK     0x02 ///< FIFO Not Empty                                    
#define EINCSRL_FIFONE__SHIFT     0x01 ///< FIFO Not Empty                                    
#define EINCSRL_FIFONE__EMPTY     0x00 ///< The IN Endpoint FIFO is empty.                    
#define EINCSRL_FIFONE__NOT_EMPTY 0x02 ///< The IN Endpoint FIFO contains one or more packets.
                                                                                              
#define EINCSRL_UNDRUN__BMASK     0x04 ///< Data Underrun Flag                                
#define EINCSRL_UNDRUN__SHIFT     0x02 ///< Data Underrun Flag                                
#define EINCSRL_UNDRUN__NOT_SET   0x00 ///< A data underrun did not occur.                    
#define EINCSRL_UNDRUN__SET       0x04 ///< A data underrun occurred.                         
                                                                                              
#define EINCSRL_FLUSH__BMASK      0x08 ///< FIFO Flush                                        
#define EINCSRL_FLUSH__SHIFT      0x03 ///< FIFO Flush                                        
#define EINCSRL_FLUSH__NOT_SET    0x00 ///< Do not flush the next packet.                     
#define EINCSRL_FLUSH__SET        0x08 ///< Flush the next packet to be transmitted from the  
                                       ///< IN Endpoint FIFO.                                 
                                                                                              
#define EINCSRL_SDSTL__BMASK      0x10 ///< Send Stall                                        
#define EINCSRL_SDSTL__SHIFT      0x04 ///< Send Stall                                        
#define EINCSRL_SDSTL__NOT_SET    0x00 ///< Terminate the STALL.                              
#define EINCSRL_SDSTL__SET        0x10 ///< Generate a STALL in response to an IN token.      
                                                                                              
#define EINCSRL_STSTL__BMASK      0x20 ///< Sent Stall Flag                                   
#define EINCSRL_STSTL__SHIFT      0x05 ///< Sent Stall Flag                                   
#define EINCSRL_STSTL__NOT_SET    0x00 ///< A STALL handshake was not transmitted.            
#define EINCSRL_STSTL__SET        0x20 ///< A STALL handshake was transmitted.                
                                                                                              
#define EINCSRL_CLRDT__BMASK      0x40 ///< Clear Data Toggle                                 
#define EINCSRL_CLRDT__SHIFT      0x06 ///< Clear Data Toggle                                 
#define EINCSRL_CLRDT__CLEAR      0x00 ///< Clear the IN Endpoint data toggle.                
                                                                                              
//------------------------------------------------------------------------------
// EOUTCNTH Enums (USB0 OUT Endpoint Count High @ 0x17)
//------------------------------------------------------------------------------
#define EOUTCNTH_EOCH__FMASK 0x03 ///< OUT Endpoint Count High
#define EOUTCNTH_EOCH__SHIFT 0x00 ///< OUT Endpoint Count High
                                                              
//------------------------------------------------------------------------------
// EOUTCNTL Enums (USB0 OUT Endpoint Count Low @ 0x16)
//------------------------------------------------------------------------------
#define EOUTCNTL_EOCL__FMASK 0xFF ///< OUT Endpoint Count Low
#define EOUTCNTL_EOCL__SHIFT 0x00 ///< OUT Endpoint Count Low
                                                             
//------------------------------------------------------------------------------
// EOUTCSRH Enums (USB0 OUT Endpoint Control High @ 0x15)
//------------------------------------------------------------------------------
#define EOUTCSRH_ISO__BMASK      0x40 ///< Isochronous Transfer Enable                      
#define EOUTCSRH_ISO__SHIFT      0x06 ///< Isochronous Transfer Enable                      
#define EOUTCSRH_ISO__DISABLED   0x00 ///< Endpoint configured for Bulk/Interrupt transfers.
#define EOUTCSRH_ISO__ENABLED    0x40 ///< Endpoint configured for Isochronous transfers.   
                                                                                            
#define EOUTCSRH_DBOEN__BMASK    0x80 ///< Double-Buffer Enable                             
#define EOUTCSRH_DBOEN__SHIFT    0x07 ///< Double-Buffer Enable                             
#define EOUTCSRH_DBOEN__DISABLED 0x00 ///< Disable double-buffering for the selected OUT    
                                      ///< endpoint.                                        
#define EOUTCSRH_DBOEN__ENABLED  0x80 ///< Enable double-buffering for the selected OUT     
                                      ///< endpoint.                                        
                                                                                            
//------------------------------------------------------------------------------
// EOUTCSRL Enums (USB0 OUT Endpoint Control Low @ 0x14)
//------------------------------------------------------------------------------
#define EOUTCSRL_OPRDY__BMASK      0x01 ///< OUT Packet Ready                                  
#define EOUTCSRL_OPRDY__SHIFT      0x00 ///< OUT Packet Ready                                  
#define EOUTCSRL_OPRDY__NOT_SET    0x00 ///< A data packet is not available in the Endpoint OUT
                                        ///< FIFO.                                             
#define EOUTCSRL_OPRDY__SET        0x01 ///< A data packet is available in the Endpoint OUT    
                                        ///< FIFO.                                             
                                                                                               
#define EOUTCSRL_FIFOFUL__BMASK    0x02 ///< OUT FIFO Full                                     
#define EOUTCSRL_FIFOFUL__SHIFT    0x01 ///< OUT FIFO Full                                     
#define EOUTCSRL_FIFOFUL__NOT_FULL 0x00 ///< OUT endpoint FIFO is not full.                    
#define EOUTCSRL_FIFOFUL__FULL     0x02 ///< OUT endpoint FIFO is full.                        
                                                                                               
#define EOUTCSRL_OVRUN__BMASK      0x04 ///< Data Overrun Flag                                 
#define EOUTCSRL_OVRUN__SHIFT      0x02 ///< Data Overrun Flag                                 
#define EOUTCSRL_OVRUN__NOT_SET    0x00 ///< No data overrun.                                  
#define EOUTCSRL_OVRUN__SET        0x04 ///< A data packet was lost because of a full FIFO     
                                        ///< since this flag was last cleared.                 
                                                                                               
#define EOUTCSRL_DATERR__BMASK     0x08 ///< Data Error Flag                                   
#define EOUTCSRL_DATERR__SHIFT     0x03 ///< Data Error Flag                                   
#define EOUTCSRL_DATERR__NOT_SET   0x00 ///< A received packet does not have a CRC or bit-     
                                        ///< stuffing error.                                   
#define EOUTCSRL_DATERR__SET       0x08 ///< A received packet has a CRC or bit-stuffing error.
                                                                                               
#define EOUTCSRL_FLUSH__BMASK      0x10 ///< FIFO Flush                                        
#define EOUTCSRL_FLUSH__SHIFT      0x04 ///< FIFO Flush                                        
#define EOUTCSRL_FLUSH__NOT_SET    0x00 ///< Do not flush the next packet.                     
#define EOUTCSRL_FLUSH__SET        0x10 ///< Flush the next packet to be read from the OUT     
                                        ///< endpoint FIFO.                                    
                                                                                               
#define EOUTCSRL_SDSTL__BMASK      0x20 ///< Send Stall                                        
#define EOUTCSRL_SDSTL__SHIFT      0x05 ///< Send Stall                                        
#define EOUTCSRL_SDSTL__NOT_SET    0x00 ///< Terminate the STALL.                              
#define EOUTCSRL_SDSTL__SET        0x20 ///< Generate a STALL handshake.                       
                                                                                               
#define EOUTCSRL_STSTL__BMASK      0x40 ///< Sent Stall Flag                                   
#define EOUTCSRL_STSTL__SHIFT      0x06 ///< Sent Stall Flag                                   
#define EOUTCSRL_STSTL__NOT_SET    0x00 ///< A STALL handshake was not transmitted.            
#define EOUTCSRL_STSTL__SET        0x40 ///< A STALL handshake was transmitted.                
                                                                                               
#define EOUTCSRL_CLRDT__BMASK      0x80 ///< Clear Data Toggle                                 
#define EOUTCSRL_CLRDT__SHIFT      0x07 ///< Clear Data Toggle                                 
#define EOUTCSRL_CLRDT__CLEAR      0x00 ///< Clear the OUT Endpoint data toggle.               
                                                                                               
//------------------------------------------------------------------------------
// FADDR Enums (USB0 Function Address @ 0x00)
//------------------------------------------------------------------------------
#define FADDR_FADDR__FMASK    0x7F ///< Function Address                               
#define FADDR_FADDR__SHIFT    0x00 ///< Function Address                               
                                                                                       
#define FADDR_UPDATE__BMASK   0x80 ///< Function Address Update                        
#define FADDR_UPDATE__SHIFT   0x07 ///< Function Address Update                        
#define FADDR_UPDATE__NOT_SET 0x00 ///< The last address written to FADDR is in effect.
#define FADDR_UPDATE__SET     0x80 ///< The last address written to FADDR is not yet in
                                   ///< effect.                                        
                                                                                       
//------------------------------------------------------------------------------
// FIFO0 Enums (USB0 Endpoint 0 FIFO Access @ 0x20)
//------------------------------------------------------------------------------
#define FIFO0_FIFODATA__FMASK 0xFF ///< Endpoint 0 FIFO Access
#define FIFO0_FIFODATA__SHIFT 0x00 ///< Endpoint 0 FIFO Access
                                                              
//------------------------------------------------------------------------------
// FIFO1 Enums (USB0 Endpoint 1 FIFO Access @ 0x21)
//------------------------------------------------------------------------------
#define FIFO1_FIFODATA__FMASK 0xFF ///< Endpoint 1 FIFO Access
#define FIFO1_FIFODATA__SHIFT 0x00 ///< Endpoint 1 FIFO Access
                                                              
//------------------------------------------------------------------------------
// FIFO2 Enums (USB0 Endpoint 2 FIFO Access @ 0x22)
//------------------------------------------------------------------------------
#define FIFO2_FIFODATA__FMASK 0xFF ///< Endpoint 2 FIFO Access
#define FIFO2_FIFODATA__SHIFT 0x00 ///< Endpoint 2 FIFO Access
                                                              
//------------------------------------------------------------------------------
// FIFO3 Enums (USB0 Endpoint 3 FIFO Access @ 0x23)
//------------------------------------------------------------------------------
#define FIFO3_FIFODATA__FMASK 0xFF ///< Endpoint 3 FIFO Access
#define FIFO3_FIFODATA__SHIFT 0x00 ///< Endpoint 3 FIFO Access
                                                              
//------------------------------------------------------------------------------
// FRAMEH Enums (USB0 Frame Number High @ 0x0D)
//------------------------------------------------------------------------------
#define FRAMEH_FRMEH__FMASK 0x07 ///< Frame Number High
#define FRAMEH_FRMEH__SHIFT 0x00 ///< Frame Number High
                                                       
//------------------------------------------------------------------------------
// FRAMEL Enums (USB0 Frame Number Low @ 0x0C)
//------------------------------------------------------------------------------
#define FRAMEL_FRMEL__FMASK 0xFF ///< Frame Number Low
#define FRAMEL_FRMEL__SHIFT 0x00 ///< Frame Number Low
                                                      
//------------------------------------------------------------------------------
// IN1IE Enums (USB0 IN Endpoint Interrupt Enable @ 0x07)
//------------------------------------------------------------------------------
#define IN1IE_EP0E__BMASK    0x01 ///< Endpoint 0 Interrupt Enable      
#define IN1IE_EP0E__SHIFT    0x00 ///< Endpoint 0 Interrupt Enable      
#define IN1IE_EP0E__DISABLED 0x00 ///< Disable Endpoint 0 interrupts.   
#define IN1IE_EP0E__ENABLED  0x01 ///< Enable Endpoint 0 interrupts.    
                                                                        
#define IN1IE_IN1E__BMASK    0x02 ///< IN Endpoint 1 Interrupt Enable   
#define IN1IE_IN1E__SHIFT    0x01 ///< IN Endpoint 1 Interrupt Enable   
#define IN1IE_IN1E__DISABLED 0x00 ///< Disable Endpoint 1 IN interrupts.
#define IN1IE_IN1E__ENABLED  0x02 ///< Enable Endpoint 1 IN interrupts. 
                                                                        
#define IN1IE_IN2E__BMASK    0x04 ///< IN Endpoint 2 Interrupt Enable   
#define IN1IE_IN2E__SHIFT    0x02 ///< IN Endpoint 2 Interrupt Enable   
#define IN1IE_IN2E__DISABLED 0x00 ///< Disable Endpoint 2 IN interrupts.
#define IN1IE_IN2E__ENABLED  0x04 ///< Enable Endpoint 2 IN interrupts. 
                                                                        
#define IN1IE_IN3E__BMASK    0x08 ///< IN Endpoint 3 Interrupt Enable   
#define IN1IE_IN3E__SHIFT    0x03 ///< IN Endpoint 3 Interrupt Enable   
#define IN1IE_IN3E__DISABLED 0x00 ///< Disable Endpoint 3 IN interrupts.
#define IN1IE_IN3E__ENABLED  0x08 ///< Enable Endpoint 3 IN interrupts. 
                                                                        
//------------------------------------------------------------------------------
// IN1INT Enums (USB0 IN Endpoint Interrupt @ 0x02)
//------------------------------------------------------------------------------
#define IN1INT_EP0__BMASK   0x01 ///< Endpoint 0 Interrupt Flag        
#define IN1INT_EP0__SHIFT   0x00 ///< Endpoint 0 Interrupt Flag        
#define IN1INT_EP0__NOT_SET 0x00 ///< Endpoint 0 interrupt inactive.   
#define IN1INT_EP0__SET     0x01 ///< Endpoint 0 interrupt active.     
                                                                       
#define IN1INT_IN1__BMASK   0x02 ///< IN Endpoint 1 Interrupt Flag     
#define IN1INT_IN1__SHIFT   0x01 ///< IN Endpoint 1 Interrupt Flag     
#define IN1INT_IN1__NOT_SET 0x00 ///< IN Endpoint 1 interrupt inactive.
#define IN1INT_IN1__SET     0x02 ///< IN Endpoint 1 interrupt active.  
                                                                       
#define IN1INT_IN2__BMASK   0x04 ///< IN Endpoint 2 Interrupt Flag     
#define IN1INT_IN2__SHIFT   0x02 ///< IN Endpoint 2 Interrupt Flag     
#define IN1INT_IN2__NOT_SET 0x00 ///< IN Endpoint 2 interrupt inactive.
#define IN1INT_IN2__SET     0x04 ///< IN Endpoint 2 interrupt active.  
                                                                       
#define IN1INT_IN3__BMASK   0x08 ///< IN Endpoint 3 Interrupt Flag     
#define IN1INT_IN3__SHIFT   0x03 ///< IN Endpoint 3 Interrupt Flag     
#define IN1INT_IN3__NOT_SET 0x00 ///< IN Endpoint 3 interrupt inactive.
#define IN1INT_IN3__SET     0x08 ///< IN Endpoint 3 interrupt active.  
                                                                       
//------------------------------------------------------------------------------
// INDEX Enums (USB0 Endpoint Index @ 0x0E)
//------------------------------------------------------------------------------
#define INDEX_EPSEL__FMASK      0x0F ///< Endpoint Select Bits
#define INDEX_EPSEL__SHIFT      0x00 ///< Endpoint Select Bits
#define INDEX_EPSEL__ENDPOINT_0 0x00 ///< Endpoint 0.         
#define INDEX_EPSEL__ENDPOINT_1 0x01 ///< Endpoint 1.         
#define INDEX_EPSEL__ENDPOINT_2 0x02 ///< Endpoint 2.         
#define INDEX_EPSEL__ENDPOINT_3 0x03 ///< Endpoint 3.         
                                                              
//------------------------------------------------------------------------------
// OUT1IE Enums (USB0 OUT Endpoint Interrupt Enable @ 0x09)
//------------------------------------------------------------------------------
#define OUT1IE_OUT1E__BMASK    0x02 ///< OUT Endpoint 1 Interrupt Enable   
#define OUT1IE_OUT1E__SHIFT    0x01 ///< OUT Endpoint 1 Interrupt Enable   
#define OUT1IE_OUT1E__DISABLED 0x00 ///< Disable Endpoint 1 OUT interrupts.
#define OUT1IE_OUT1E__ENABLED  0x02 ///< Enable Endpoint 1 OUT interrupts. 
                                                                           
#define OUT1IE_OUT2E__BMASK    0x04 ///< OUT Endpoint 2 Interrupt Enable   
#define OUT1IE_OUT2E__SHIFT    0x02 ///< OUT Endpoint 2 Interrupt Enable   
#define OUT1IE_OUT2E__DISABLED 0x00 ///< Disable Endpoint 2 OUT interrupts.
#define OUT1IE_OUT2E__ENABLED  0x04 ///< Enable Endpoint 2 OUT interrupts. 
                                                                           
#define OUT1IE_OUT3E__BMASK    0x08 ///< OUT Endpoint 3 Interrupt Enable   
#define OUT1IE_OUT3E__SHIFT    0x03 ///< OUT Endpoint 3 Interrupt Enable   
#define OUT1IE_OUT3E__DISABLED 0x00 ///< Disable Endpoint 3 OUT interrupts.
#define OUT1IE_OUT3E__ENABLED  0x08 ///< Enable Endpoint 3 OUT interrupts. 
                                                                           
//------------------------------------------------------------------------------
// OUT1INT Enums (USB0 OUT Endpoint Interrupt @ 0x04)
//------------------------------------------------------------------------------
#define OUT1INT_OUT1__BMASK   0x02 ///< OUT Endpoint 1 Interrupt Flag     
#define OUT1INT_OUT1__SHIFT   0x01 ///< OUT Endpoint 1 Interrupt Flag     
#define OUT1INT_OUT1__NOT_SET 0x00 ///< OUT Endpoint 1 interrupt inactive.
#define OUT1INT_OUT1__SET     0x02 ///< OUT Endpoint 1 interrupt active.  
                                                                          
#define OUT1INT_OUT2__BMASK   0x04 ///< OUT Endpoint 2 Interrupt Flag     
#define OUT1INT_OUT2__SHIFT   0x02 ///< OUT Endpoint 2 Interrupt Flag     
#define OUT1INT_OUT2__NOT_SET 0x00 ///< OUT Endpoint 2 interrupt inactive.
#define OUT1INT_OUT2__SET     0x04 ///< OUT Endpoint 2 interrupt active.  
                                                                          
#define OUT1INT_OUT3__BMASK   0x08 ///< OUT Endpoint 3 Interrupt Flag     
#define OUT1INT_OUT3__SHIFT   0x03 ///< OUT Endpoint 3 Interrupt Flag     
#define OUT1INT_OUT3__NOT_SET 0x00 ///< OUT Endpoint 3 interrupt inactive.
#define OUT1INT_OUT3__SET     0x08 ///< OUT Endpoint 3 interrupt active.  
                                                                          
//------------------------------------------------------------------------------
// POWER Enums (USB0 Power @ 0x01)
//------------------------------------------------------------------------------
#define POWER_SUSEN__BMASK         0x01 ///< Suspend Detection Enable                          
#define POWER_SUSEN__SHIFT         0x00 ///< Suspend Detection Enable                          
#define POWER_SUSEN__DISABLED      0x00 ///< Disable suspend detection. USB0 will ignore       
                                        ///< suspend signaling on the bus.                     
#define POWER_SUSEN__ENABLED       0x01 ///< Enable suspend detection. USB0 will enter suspend 
                                        ///< mode if it detects suspend signaling on the bus.  
                                                                                               
#define POWER_SUSMD__BMASK         0x02 ///< Suspend Mode                                      
#define POWER_SUSMD__SHIFT         0x01 ///< Suspend Mode                                      
#define POWER_SUSMD__NOT_SUSPENDED 0x00 ///< USB0 not in suspend mode.                         
#define POWER_SUSMD__SUSPENDED     0x02 ///< USB0 in suspend mode.                             
                                                                                               
#define POWER_RESUME__BMASK        0x04 ///< Force Resume                                      
#define POWER_RESUME__SHIFT        0x02 ///< Force Resume                                      
#define POWER_RESUME__START        0x04 ///< Generate resume signalling to create a remote     
                                        ///< wakeup event.                                     
                                                                                               
#define POWER_USBRST__BMASK        0x08 ///< Reset Detect                                      
#define POWER_USBRST__SHIFT        0x03 ///< Reset Detect                                      
#define POWER_USBRST__NOT_SET      0x00 ///< USB reset signalling not detected.                
#define POWER_USBRST__SET          0x08 ///< USB reset signalling detected.                    
                                                                                               
#define POWER_USBINH__BMASK        0x10 ///< USB0 Inhibit                                      
#define POWER_USBINH__SHIFT        0x04 ///< USB0 Inhibit                                      
#define POWER_USBINH__ENABLED      0x00 ///< USB0 enabled.                                     
#define POWER_USBINH__DISABLED     0x10 ///< USB0 inhibited. All USB traffic is ignored.       
                                                                                               
#define POWER_ISOUD__BMASK         0x80 ///< Isochronous Update Mode                           
#define POWER_ISOUD__SHIFT         0x07 ///< Isochronous Update Mode                           
#define POWER_ISOUD__IN_TOKEN      0x00 ///< When firmware writes INPRDY = 1, USB0 will send   
                                        ///< the packet when the next IN token is received.    
#define POWER_ISOUD__SOF_TOKEN     0x80 ///< When firmware writes INPRDY = 1, USB0 will wait   
                                        ///< for a SOF token before sending the packet. If an  
                                        ///< IN token is received before a SOF token, USB0 will
                                        ///< send a zero-length data packet.                   
                                                                                               
//------------------------------------------------------------------------------
// USB0ADR Enums (USB0 Indirect Address @ 0x96)
//------------------------------------------------------------------------------
#define USB0ADR_USB0ADR__FMASK          0x3F ///< USB0 Indirect Register Address                    
#define USB0ADR_USB0ADR__SHIFT          0x00 ///< USB0 Indirect Register Address                    
#define USB0ADR_USB0ADR__FADDR          0x00 ///< Function Address.                                 
#define USB0ADR_USB0ADR__POWER          0x01 ///< Power Management.                                 
#define USB0ADR_USB0ADR__IN1INT         0x02 ///< Endpoint 0 and Endpoints 1-3 IN Interrupt Flags.  
#define USB0ADR_USB0ADR__OUT1INT        0x04 ///< Endpoints 1-3 OUT Interrupt Flags.                
#define USB0ADR_USB0ADR__CMINT          0x06 ///< Common USB Interrupt Flags.                       
#define USB0ADR_USB0ADR__IN1IE          0x07 ///< Endpoint 0 and Endpoints 1-3 IN Interrupt Enables.
#define USB0ADR_USB0ADR__OUT1IE         0x09 ///< Endpoints 1-3 OUT Interrupt Enables.              
#define USB0ADR_USB0ADR__CMIE           0x0B ///< Common USB Interrupt Enables.                     
#define USB0ADR_USB0ADR__FRAMEL         0x0C ///< Frame Number Low Byte.                            
#define USB0ADR_USB0ADR__FRAMEH         0x0D ///< Frame Number High Byte.                           
#define USB0ADR_USB0ADR__INDEX          0x0E ///< Endpoint Index Selection.                         
#define USB0ADR_USB0ADR__CLKREC         0x0F ///< Clock Recovery Control.                           
#define USB0ADR_USB0ADR__E0CSR_EINCSRL  0x11 ///< Endpoint 0 Control / Status, Endpoint IN Control /
                                             ///< Status Low Byte.                                  
#define USB0ADR_USB0ADR__EINCSRH        0x12 ///< Endpoint IN Control / Status High Byte.           
#define USB0ADR_USB0ADR__EOUTCSRL       0x14 ///< Endpoint OUT Control / Status Low Byte.           
#define USB0ADR_USB0ADR__EOUTCSRH       0x15 ///< Endpoint OUT Control / Status High Byte.          
#define USB0ADR_USB0ADR__E0CNT_EOUTCNTL 0x16 ///< Number of Received Bytes in Endpoint 0 FIFO,      
                                             ///< Endpoint OUT Packet Count Low Byte.               
#define USB0ADR_USB0ADR__EOUTCNTH       0x17 ///< Endpoint OUT Packet Count High Byte.              
#define USB0ADR_USB0ADR__EENABLE        0x1E ///< Endpoint Enable.                                  
#define USB0ADR_USB0ADR__FIFO0          0x20 ///< Endpoint 0 FIFO.                                  
#define USB0ADR_USB0ADR__FIFO1          0x21 ///< Endpoint 1 FIFO.                                  
#define USB0ADR_USB0ADR__FIFO2          0x22 ///< Endpoint 2 FIFO.                                  
#define USB0ADR_USB0ADR__FIFO3          0x23 ///< Endpoint 3 FIFO.                                  
                                                                                                    
#define USB0ADR_AUTORD__BMASK           0x40 ///< USB0 Register Auto-Read Flag                      
#define USB0ADR_AUTORD__SHIFT           0x06 ///< USB0 Register Auto-Read Flag                      
#define USB0ADR_AUTORD__DISABLED        0x00 ///< BUSY must be written manually for each USB0       
                                             ///< indirect register read.                           
#define USB0ADR_AUTORD__ENABLED         0x40 ///< The next indirect register read will automatically
                                             ///< be initiated when firmware reads USB0DAT (USBADDR 
                                             ///< bits will not be changed).                        
                                                                                                    
#define USB0ADR_BUSY__BMASK             0x80 ///< USB0 Register Read Busy Flag                      
#define USB0ADR_BUSY__SHIFT             0x07 ///< USB0 Register Read Busy Flag                      
#define USB0ADR_BUSY__NOT_SET           0x00 ///< A read is not in progress.                        
#define USB0ADR_BUSY__SET               0x80 ///< Initiate a read or a read is in progress.         
                                                                                                    
//------------------------------------------------------------------------------
// USB0DAT Enums (USB0 Data @ 0x97)
//------------------------------------------------------------------------------
#define USB0DAT_USB0DAT__FMASK 0xFF ///< USB0 Data
#define USB0DAT_USB0DAT__SHIFT 0x00 ///< USB0 Data
                                                  
//------------------------------------------------------------------------------
// USB0XCN Enums (USB0 Transceiver Control @ 0xD7)
//------------------------------------------------------------------------------
#define USB0XCN_Dn__BMASK                0x01 ///< D- Signal Status                                 
#define USB0XCN_Dn__SHIFT                0x00 ///< D- Signal Status                                 
#define USB0XCN_Dn__LOW                  0x00 ///< D- signal currently at logic 0.                  
#define USB0XCN_Dn__HIGH                 0x01 ///< D- signal currently at logic 1.                  
                                                                                                    
#define USB0XCN_Dp__BMASK                0x02 ///< D+ Signal Status                                 
#define USB0XCN_Dp__SHIFT                0x01 ///< D+ Signal Status                                 
#define USB0XCN_Dp__LOW                  0x00 ///< D+ signal currently at logic 0.                  
#define USB0XCN_Dp__HIGH                 0x02 ///< D+ signal currently at logic 1.                  
                                                                                                    
#define USB0XCN_DFREC__BMASK             0x04 ///< Differential Receiver                            
#define USB0XCN_DFREC__SHIFT             0x02 ///< Differential Receiver                            
#define USB0XCN_DFREC__DIFFERENTIAL_ZERO 0x00 ///< Differential 0 signalling on the bus.            
#define USB0XCN_DFREC__DIFFERENTIAL_ONE  0x04 ///< Differential 1 signalling on the bus.            
                                                                                                    
#define USB0XCN_PHYTST__FMASK            0x18 ///< Physical Layer Test                              
#define USB0XCN_PHYTST__SHIFT            0x03 ///< Physical Layer Test                              
#define USB0XCN_PHYTST__MODE0            0x00 ///< Mode 0: Normal (non-test mode) (D+ = X, D- = X). 
#define USB0XCN_PHYTST__MODE1            0x08 ///< Mode 1: Differential 1 forced (D+ = 1, D- = 0).  
#define USB0XCN_PHYTST__MODE2            0x10 ///< Mode 2: Differential 0 forced (D+ = 0, D- = 1).  
#define USB0XCN_PHYTST__MODE3            0x18 ///< Mode 3: Single-Ended 0 forced (D+ = 0, D- = 0).  
                                                                                                    
#define USB0XCN_SPEED__BMASK             0x20 ///< USB0 Speed Select                                
#define USB0XCN_SPEED__SHIFT             0x05 ///< USB0 Speed Select                                
#define USB0XCN_SPEED__LOW_SPEED         0x00 ///< USB0 operates as a Low Speed device. If enabled, 
                                              ///< the internal pull-up resistor appears on the D-  
                                              ///< line.                                            
#define USB0XCN_SPEED__FULL_SPEED        0x20 ///< USB0 operates as a Full Speed device. If enabled,
                                              ///< the internal pull-up resistor appears on the D+  
                                              ///< line.                                            
                                                                                                    
#define USB0XCN_PHYEN__BMASK             0x40 ///< Physical Layer Enable                            
#define USB0XCN_PHYEN__SHIFT             0x06 ///< Physical Layer Enable                            
#define USB0XCN_PHYEN__DISABLED          0x00 ///< Disable the USB0 physical layer transceiver      
                                              ///< (suspend).                                       
#define USB0XCN_PHYEN__ENABLED           0x40 ///< Enable the USB0 physical layer transceiver       
                                              ///< (normal).                                        
                                                                                                    
#define USB0XCN_PREN__BMASK              0x80 ///< Internal Pull-up Resistor Enable                 
#define USB0XCN_PREN__SHIFT              0x07 ///< Internal Pull-up Resistor Enable                 
#define USB0XCN_PREN__PULL_UP_DISABLED   0x00 ///< Internal pull-up resistor disabled (device       
                                              ///< effectively detached from USB network).          
#define USB0XCN_PREN__PULL_UP_ENABLED    0x80 ///< Internal pull-up resistor enabled when VBUS is   
                                              ///< present (device attached to the USB network).    
                                                                                                    
//------------------------------------------------------------------------------
// VDM0CN Enums (Supply Monitor Control @ 0xFF)
//------------------------------------------------------------------------------
#define VDM0CN_VDDSTAT__BMASK  0x40 ///< Supply Status                                   
#define VDM0CN_VDDSTAT__SHIFT  0x06 ///< Supply Status                                   
#define VDM0CN_VDDSTAT__BELOW  0x00 ///< VDD is at or below the supply monitor threshold.
#define VDM0CN_VDDSTAT__ABOVE  0x40 ///< VDD is above the supply monitor threshold.      
                                                                                         
#define VDM0CN_VDMEN__BMASK    0x80 ///< Supply Monitor Enable                           
#define VDM0CN_VDMEN__SHIFT    0x07 ///< Supply Monitor Enable                           
#define VDM0CN_VDMEN__DISABLED 0x00 ///< Supply Monitor Disabled.                        
#define VDM0CN_VDMEN__ENABLED  0x80 ///< Supply Monitor Enabled.                         
                                                                                         
//------------------------------------------------------------------------------
// REF0CN Enums (Voltage Reference Control @ 0xD1)
//------------------------------------------------------------------------------
#define REF0CN_REFBE__BMASK    0x01 ///< Internal Reference Buffer Enable                  
#define REF0CN_REFBE__SHIFT    0x00 ///< Internal Reference Buffer Enable                  
#define REF0CN_REFBE__DISABLED 0x00 ///< Disable the internal reference buffer.            
#define REF0CN_REFBE__ENABLED  0x01 ///< Enable the internal reference buffer. The internal
                                    ///< voltage reference is driven on the VREF pin.      
                                                                                           
#define REF0CN_TEMPE__BMASK    0x04 ///< Temperature Sensor Enable                         
#define REF0CN_TEMPE__SHIFT    0x02 ///< Temperature Sensor Enable                         
#define REF0CN_TEMPE__DISABLED 0x00 ///< Disable the internal Temperature Sensor.          
#define REF0CN_TEMPE__ENABLED  0x04 ///< Enable the internal Temperature Sensor.           
                                                                                           
#define REF0CN_REFSL__BMASK    0x08 ///< Voltage Reference Select                          
#define REF0CN_REFSL__SHIFT    0x03 ///< Voltage Reference Select                          
#define REF0CN_REFSL__VREF     0x00 ///< Use the VREF pin as the voltage reference.        
#define REF0CN_REFSL__VDD      0x08 ///< Use VDD as the voltage reference.                 
                                                                                           
#define REF0CN_REGOVR__BMASK   0x10 ///< Regulator Reference Override                      
#define REF0CN_REGOVR__SHIFT   0x04 ///< Regulator Reference Override                      
#define REF0CN_REGOVR__REFSL   0x00 ///< The REFSL bit selects the voltage reference       
                                    ///< source.                                           
#define REF0CN_REGOVR__VREG    0x10 ///< Use the output of the internal regulator as the   
                                    ///< voltage reference source.                         
                                                                                           
#define REF0CN_REFBGS__BMASK   0x80 ///< Reference Buffer Gain Select                      
#define REF0CN_REFBGS__SHIFT   0x07 ///< Reference Buffer Gain Select                      
#define REF0CN_REFBGS__GAIN_2  0x00 ///< The on-chip voltage reference buffer gain is 2.   
#define REF0CN_REFBGS__GAIN_1  0x80 ///< The on-chip voltage reference buffer gain is 1.   
                                                                                           
//------------------------------------------------------------------------------
// REG01CN Enums (Voltage Regulator Control @ 0xC9)
//------------------------------------------------------------------------------
#define REG01CN_REG1MD__BMASK     0x02 ///< VREG1 Voltage Regulator Mode                     
#define REG01CN_REG1MD__SHIFT     0x01 ///< VREG1 Voltage Regulator Mode                     
#define REG01CN_REG1MD__NORMAL    0x00 ///< VREG1 Voltage Regulator in normal mode.          
#define REG01CN_REG1MD__LOW_POWER 0x02 ///< VREG1 Voltage Regulator in low power mode.       
                                                                                             
#define REG01CN_STOPCF__BMASK     0x08 ///< VREG1 Stop and Shutdown Mode Configuration       
#define REG01CN_STOPCF__SHIFT     0x03 ///< VREG1 Stop and Shutdown Mode Configuration       
#define REG01CN_STOPCF__ACTIVE    0x00 ///< VREG1 Regulator is still active in stop mode. Any
                                       ///< enabled reset source will reset the device.      
#define REG01CN_STOPCF__SHUTDOWN  0x08 ///< VREG1 Regulator is shut down in stop mode (device
                                       ///< enters Shutdown mode). Only the RSTb pin or power
                                       ///< cycle can reset the device.                      
                                                                                             
#define REG01CN_REG0MD__BMASK     0x10 ///< VREG0 Voltage Regulator Mode                     
#define REG01CN_REG0MD__SHIFT     0x04 ///< VREG0 Voltage Regulator Mode                     
#define REG01CN_REG0MD__NORMAL    0x00 ///< VREG0 Voltage Regulator in normal mode.          
#define REG01CN_REG0MD__LOW_POWER 0x10 ///< VREG0 Voltage Regulator in low power mode.       
                                                                                             
#define REG01CN_VBSTAT__BMASK     0x40 ///< VBUS Signal Status                               
#define REG01CN_VBSTAT__SHIFT     0x06 ///< VBUS Signal Status                               
#define REG01CN_VBSTAT__NOT_SET   0x00 ///< VBUS signal currently absent (device not attached
                                       ///< to USB network).                                 
#define REG01CN_VBSTAT__SET       0x40 ///< VBUS signal currently present (device attached to
                                       ///< USB network).                                    
                                                                                             
#define REG01CN_REG0DIS__BMASK    0x80 ///< Voltage Regulator (REG0) Disable                 
#define REG01CN_REG0DIS__SHIFT    0x07 ///< Voltage Regulator (REG0) Disable                 
#define REG01CN_REG0DIS__ENABLED  0x00 ///< Enable the VREG0 Voltage Regulator.              
#define REG01CN_REG0DIS__DISABLED 0x80 ///< Disable the VREG0 Voltage Regulator.             
                                                                                             
//------------------------------------------------------------------------------
// EMI0CF Enums (External Memory Configuration @ 0x85)
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
                                                                                                          
#define EMI0CF_USBFAE__BMASK                  0x40 ///< USB FIFO Access Enable                            
#define EMI0CF_USBFAE__SHIFT                  0x06 ///< USB FIFO Access Enable                            
#define EMI0CF_USBFAE__FIFO_ACCESS_DISABLED   0x00 ///< USB FIFO RAM not available through MOVX           
                                                   ///< instructions.                                     
#define EMI0CF_USBFAE__FIFO_ACCESS_ENABLED    0x40 ///< USB FIFO RAM available using MOVX instructions.   
                                                   ///< The 1 KB of USB RAM will be mapped in XRAM space  
                                                   ///< at addresses 0x0400 to 0x07FF. The USB clock must 
                                                   ///< be active and greater than or equal to twice the  
                                                   ///< SYSCLK (USBCLK > 2 x SYSCLK) to access this area  
                                                   ///< with MOVX instructions.                           
                                                                                                          
//------------------------------------------------------------------------------
// EMI0CN Enums (External Memory Interface Control @ 0xAA)
//------------------------------------------------------------------------------
#define EMI0CN_PGSEL__FMASK 0xFF ///< XRAM Page Select
#define EMI0CN_PGSEL__SHIFT 0x00 ///< XRAM Page Select
                                                      
//------------------------------------------------------------------------------
// EMI0TC Enums (External Memory Timing Control @ 0x84)
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
                                                                                       
#endif // SI_EFM8UB2_REGISTER_ENUMS_H
//-eof--------------------------------------------------------------------------

