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

#ifndef SI_C8051F120_SI_DEFS_H
#define SI_C8051F120_SI_DEFS_H

#include <si_toolchain.h>

//-----------------------------------------------------------------------------
// Register Definitions
//-----------------------------------------------------------------------------
SI_SFR (ACC,      0xE0); ///< Accumulator                           
SI_SFR (ADC0CF,   0xBC); ///< ADC0 Configuration                    
SI_SFR (ADC0CN,   0xE8); ///< ADC0 Control                          
SI_SFR (ADC0GTH,  0xC5); ///< ADC0 Greater-Than High Byte           
SI_SFR (ADC0GTL,  0xC4); ///< ADC0 Greater-Than Low Byte            
SI_SFR (ADC0H,    0xBF); ///< ADC0 Data Word High Byte              
SI_SFR (ADC0L,    0xBE); ///< ADC0 Data Word Low Byte               
SI_SFR (ADC0LTH,  0xC7); ///< ADC0 Less-Than High Byte              
SI_SFR (ADC0LTL,  0xC6); ///< ADC0 Less-Than Low Byte               
SI_SFR (ADC2,     0xBE); ///< ADC2 Data Word                        
SI_SFR (ADC2CF,   0xBC); ///< ADC2 Configuration                    
SI_SFR (ADC2CN,   0xE8); ///< ADC2 Control                          
SI_SFR (ADC2GT,   0xC4); ///< ADC2 Greater-Than Data Byte           
SI_SFR (ADC2LT,   0xC6); ///< ADC2 Less-Than Data Byte              
SI_SFR (AMX0CF,   0xBA); ///< AMUX0 Configuration                   
SI_SFR (AMX0SL,   0xBB); ///< AMUX0 Channel Select                  
SI_SFR (AMX2CF,   0xBA); ///< AMUX2 Configuration                   
SI_SFR (AMX2SL,   0xBB); ///< AMUX2 Channel Select                  
SI_SFR (B,        0xF0); ///< B Register                            
SI_SFR (CCH0CN,   0xA1); ///< Cache Control                         
SI_SFR (CCH0LC,   0xA3); ///< Cache Lock Control                    
SI_SFR (CCH0MA,   0x9A); ///< Cache Miss Accumulator                
SI_SFR (CCH0TN,   0xA2); ///< Cache Tuning                          
SI_SFR (CKCON,    0x8E); ///< Clock Control                         
SI_SFR (CLKSEL,   0x97); ///< Clock Select                          
SI_SFR (CPT0CN,   0x88); ///< Comparator 0 Control                  
SI_SFR (CPT0MD,   0x89); ///< Comparator 0 Mode                     
SI_SFR (CPT1CN,   0x88); ///< Comparator 1 Control                  
SI_SFR (CPT1MD,   0x89); ///< Comparator 1 Mode                     
SI_SFR (DAC0CN,   0xD4); ///< DAC0 Control                          
SI_SFR (DAC0H,    0xD3); ///< DAC0 Data High Byte                   
SI_SFR (DAC0L,    0xD2); ///< DAC0 Data Low Byte                    
SI_SFR (DAC1CN,   0xD4); ///< DAC1 Control                          
SI_SFR (DAC1H,    0xD3); ///< DAC1 Data High Byte                   
SI_SFR (DAC1L,    0xD2); ///< DAC1 Data Low Byte                    
SI_SFR (DEVICEID, 0x04); ///< JTAG Device ID                        
SI_SFR (DPH,      0x83); ///< Data Pointer High                     
SI_SFR (DPL,      0x82); ///< Data Pointer Low                      
SI_SFR (EIE1,     0xE6); ///< Extended Interrupt Enable 1           
SI_SFR (EIE2,     0xE7); ///< Extended Interrupt Enable 2           
SI_SFR (EIP1,     0xF6); ///< Extended Interrupt Priority 1 Low     
SI_SFR (EIP2,     0xF7); ///< Extended Interrupt Priority 2         
SI_SFR (EMI0CF,   0xA3); ///< External Memory Configuration         
SI_SFR (EMI0CN,   0xA2); ///< External Memory Interface Control     
SI_SFR (EMI0TC,   0xA1); ///< External Memory Timing Control        
SI_SFR (FLACL,    0xB7); ///< Flash Access Limit                    
SI_SFR (FLASHADR, 0x84); ///< JTAG Flash Address                    
SI_SFR (FLASHCON, 0x82); ///< JTAG Flash Control                    
SI_SFR (FLASHDAT, 0x83); ///< JTAG Flash Data                       
SI_SFR (FLSCL,    0xB7); ///< Flash Scale                           
SI_SFR (FLSTAT,   0x88); ///< Flash Status                          
SI_SFR (IE,       0xA8); ///< Interrupt Enable                      
SI_SFR (IP,       0xB8); ///< Interrupt Priority                    
SI_SFR (MAC0ACC0, 0x93); ///< Accumulator Byte 0                    
SI_SFR (MAC0ACC1, 0x94); ///< Accumulator Byte 1                    
SI_SFR (MAC0ACC2, 0x95); ///< Accumulator Byte 2                    
SI_SFR (MAC0ACC3, 0x96); ///< Accumulator Byte 3                    
SI_SFR (MAC0AH,   0xC2); ///< Operand A High Byte                   
SI_SFR (MAC0AL,   0xC1); ///< Operand A Low Byte                    
SI_SFR (MAC0BH,   0x92); ///< Operand B High Byte                   
SI_SFR (MAC0BL,   0x91); ///< Operand B Low Byte                    
SI_SFR (MAC0CF,   0xC3); ///< MAC0 Configuration                    
SI_SFR (MAC0OVR,  0x97); ///< Accumulator Overflow Byte             
SI_SFR (MAC0RNDH, 0xCF); ///< Rounded Result High Byte              
SI_SFR (MAC0RNDL, 0xCE); ///< Rounded Result Low Byte               
SI_SFR (MAC0STA,  0xC0); ///< MAC0 Status                           
SI_SFR (OSCICL,   0x8B); ///< High Frequency Oscillator Calibration 
SI_SFR (OSCICN,   0x8A); ///< High Frequency Oscillator Control     
SI_SFR (OSCXCN,   0x8C); ///< External Oscillator Control           
SI_SFR (P0,       0x80); ///< Port 0 Pin Latch                      
SI_SFR (P0MDOUT,  0xA4); ///< Port 0 Output Mode                    
SI_SFR (P1,       0x90); ///< Port 1 Pin Latch                      
SI_SFR (P1MDIN,   0xAD); ///< Port 1 Input Mode                     
SI_SFR (P1MDOUT,  0xA5); ///< Port 1 Output Mode                    
SI_SFR (P2,       0xA0); ///< Port 2 Pin Latch                      
SI_SFR (P2MDOUT,  0xA6); ///< Port 2 Output Mode                    
SI_SFR (P3,       0xB0); ///< Port 3 Pin Latch                      
SI_SFR (P3MDOUT,  0xA7); ///< Port 3 Output Mode                    
SI_SFR (P4,       0xC8); ///< Port 4 Pin Latch                      
SI_SFR (P4MDOUT,  0x9C); ///< Port 4 Output Mode                    
SI_SFR (P5,       0xD8); ///< Port 5 Pin Latch                      
SI_SFR (P5MDOUT,  0x9D); ///< Port 5 Output Mode                    
SI_SFR (P6,       0xE8); ///< Port 6 Pin Latch                      
SI_SFR (P6MDOUT,  0x9E); ///< Port 6 Output Mode                    
SI_SFR (P7,       0xF8); ///< Port 7 Pin Latch                      
SI_SFR (P7MDOUT,  0x9F); ///< Port 7 Output Mode                    
SI_SFR (PCA0CN,   0xD8); ///< PCA Control                           
SI_SFR (PCA0CPH0, 0xFC); ///< PCA Channel 0 Capture Module High Byte
SI_SFR (PCA0CPH1, 0xFE); ///< PCA Channel 1 Capture Module High Byte
SI_SFR (PCA0CPH2, 0xEA); ///< PCA Channel 2 Capture Module High Byte
SI_SFR (PCA0CPH3, 0xEC); ///< PCA Channel 3 Capture Module High Byte
SI_SFR (PCA0CPH4, 0xEE); ///< PCA Channel 4 Capture Module High Byte
SI_SFR (PCA0CPH5, 0xE2); ///< PCA Channel 5 Capture Module High Byte
SI_SFR (PCA0CPL0, 0xFB); ///< PCA Channel 0 Capture Module Low Byte 
SI_SFR (PCA0CPL1, 0xFD); ///< PCA Channel 1 Capture Module Low Byte 
SI_SFR (PCA0CPL2, 0xE9); ///< PCA Channel 2 Capture Module Low Byte 
SI_SFR (PCA0CPL3, 0xEB); ///< PCA Channel 3 Capture Module Low Byte 
SI_SFR (PCA0CPL4, 0xED); ///< PCA Channel 4 Capture Module Low Byte 
SI_SFR (PCA0CPL5, 0xE1); ///< PCA Channel 5 Capture Module Low Byte 
SI_SFR (PCA0CPM0, 0xDA); ///< PCA Channel 0 Capture/Compare Mode    
SI_SFR (PCA0CPM1, 0xDB); ///< PCA Channel 1 Capture/Compare Mode    
SI_SFR (PCA0CPM2, 0xDC); ///< PCA Channel 2 Capture/Compare Mode    
SI_SFR (PCA0CPM3, 0xDD); ///< PCA Channel 3 Capture/Compare Mode    
SI_SFR (PCA0CPM4, 0xDE); ///< PCA Channel 4 Capture/Compare Mode    
SI_SFR (PCA0CPM5, 0xDF); ///< PCA Channel 5 Capture/Compare Mode    
SI_SFR (PCA0H,    0xFA); ///< PCA Counter/Timer High Byte           
SI_SFR (PCA0L,    0xF9); ///< PCA Counter/Timer Low Byte            
SI_SFR (PCA0MD,   0xD9); ///< PCA Mode                              
SI_SFR (PCON,     0x87); ///< Power Control                         
SI_SFR (PLL0CN,   0x89); ///< PLL Control                           
SI_SFR (PLL0DIV,  0x8D); ///< PLL Divider                           
SI_SFR (PLL0FLT,  0x8F); ///< PLL Filter                            
SI_SFR (PLL0MUL,  0x8E); ///< PLL Multiplier                        
SI_SFR (PSBANK,   0xB1); ///< Program Space Bank Select             
SI_SFR (PSCTL,    0x8F); ///< Program Store Control                 
SI_SFR (PSW,      0xD0); ///< Program Status Word                   
SI_SFR (RCAP2H,   0xCB); ///< Timer 2 Capture Register High Byte    
SI_SFR (RCAP2L,   0xCA); ///< Timer 2 Capture Register Low Byte     
SI_SFR (RCAP3H,   0xCB); ///< Timer 3 Capture Register High Byte    
SI_SFR (RCAP3L,   0xCA); ///< Timer 3 Capture Register Low Byte     
SI_SFR (RCAP4H,   0xCB); ///< Timer 4 Capture Register High Byte    
SI_SFR (RCAP4L,   0xCA); ///< Timer 4 Capture Register Low Byte     
SI_SFR (REF0CN,   0xD1); ///< Voltage Reference Control             
SI_SFR (RSTSRC,   0xEF); ///< Reset Source                          
SI_SFR (SADDR0,   0xA9); ///< UART0 Slave Address                   
SI_SFR (SADEN0,   0xB9); ///< UART0 Slave Address Enable            
SI_SFR (SBUF0,    0x99); ///< UART0 Serial Port Data Buffer         
SI_SFR (SBUF1,    0x99); ///< UART1 Serial Port Data Buffer         
SI_SFR (SCON0,    0x98); ///< UART0 Serial Port Control             
SI_SFR (SCON1,    0x98); ///< UART1 Serial Port Control             
SI_SFR (SFRLAST,  0x86); ///< SFR Page Last                         
SI_SFR (SFRNEXT,  0x85); ///< SFR Page Next                         
SI_SFR (SFRPAGE,  0x84); ///< SFR Page                              
SI_SFR (SFRPGCN,  0x96); ///< SFR Page Control                      
SI_SFR (SMB0ADR,  0xC3); ///< SMBus 0 Address                       
SI_SFR (SMB0CN,   0xC0); ///< SMBus 0 Control                       
SI_SFR (SMB0CR,   0xCF); ///< SMBus 0 Clock Rate                    
SI_SFR (SMB0DAT,  0xC2); ///< SMBus 0 Data                          
SI_SFR (SMB0STA,  0xC1); ///< SMBus 0 Status                        
SI_SFR (SP,       0x81); ///< Stack Pointer                         
SI_SFR (SPI0CFG,  0x9A); ///< SPI0 Configuration                    
SI_SFR (SPI0CKR,  0x9D); ///< SPI0 Clock Rate                       
SI_SFR (SPI0CN,   0xF8); ///< SPI0 Control                          
SI_SFR (SPI0DAT,  0x9B); ///< SPI0 Data                             
SI_SFR (SSTA0,    0x91); ///< UART0 Status and Clock Selection      
SI_SFR (TCON,     0x88); ///< Timer 0/1 Control                     
SI_SFR (TH0,      0x8C); ///< Timer 0 High Byte                     
SI_SFR (TH1,      0x8D); ///< Timer 1 High Byte                     
SI_SFR (TL0,      0x8A); ///< Timer 0 Low Byte                      
SI_SFR (TL1,      0x8B); ///< Timer 1 Low Byte                      
SI_SFR (TMOD,     0x89); ///< Timer 0/1 Mode                        
SI_SFR (TMR2CF,   0xC9); ///< Timer 2 Configuration                 
SI_SFR (TMR2CN,   0xC8); ///< Timer 2 Control                       
SI_SFR (TMR2H,    0xCD); ///< Timer 2 High Byte                     
SI_SFR (TMR2L,    0xCC); ///< Timer 2 Low Byte                      
SI_SFR (TMR3CF,   0xC9); ///< Timer 3 Configuration                 
SI_SFR (TMR3CN,   0xC8); ///< Timer 3 Control                       
SI_SFR (TMR3H,    0xCD); ///< Timer 3 High Byte                     
SI_SFR (TMR3L,    0xCC); ///< Timer 3 Low Byte                      
SI_SFR (TMR4CF,   0xC9); ///< Timer 4 Configuration                 
SI_SFR (TMR4CN,   0xC8); ///< Timer 4 Control                       
SI_SFR (TMR4H,    0xCD); ///< Timer 4 High Byte                     
SI_SFR (TMR4L,    0xCC); ///< Timer 4 Low Byte                      
SI_SFR (WDTCN,    0xFF); ///< Watchdog Timer Control                
SI_SFR (XBR0,     0xE1); ///< Port I/O Crossbar 0                   
SI_SFR (XBR1,     0xE2); ///< Port I/O Crossbar 1                   
SI_SFR (XBR2,     0xE3); ///< Port I/O Crossbar 2                   

//------------------------------------------------------------------------------
// 16-bit Register Definitions (may not work on all compilers)
//------------------------------------------------------------------------------
SI_SFR16 (ADC0GT,  0xC4); ///< ADC0 Greater-Than            
SI_SFR16 (ADC0,    0xBE); ///< ADC0 Data Word               
SI_SFR16 (ADC0LT,  0xC6); ///< ADC0 Less-Than               
SI_SFR16 (DP,      0x82); ///< Data Pointer                 
SI_SFR16 (PCA0CP0, 0xFB); ///< PCA Channel 0 Capture Module 
SI_SFR16 (PCA0CP1, 0xFD); ///< PCA Channel 1 Capture Module 
SI_SFR16 (PCA0CP2, 0xE9); ///< PCA Channel 2 Capture Module 
SI_SFR16 (PCA0CP3, 0xEB); ///< PCA Channel 3 Capture Module 
SI_SFR16 (PCA0CP4, 0xED); ///< PCA Channel 4 Capture Module 
SI_SFR16 (PCA0CP5, 0xE1); ///< PCA Channel 5 Capture Module 
SI_SFR16 (PCA0,    0xF9); ///< PCA Counter/Timer            

//------------------------------------------------------------------------------
// Indirect Register Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Bit Definitions
//------------------------------------------------------------------------------

// ACC (Accumulator)
#define SFR_ACC 0xE0
SI_SBIT (ACC_ACC0, SFR_ACC, 0); ///< Accumulator Bit 0
SI_SBIT (ACC_ACC1, SFR_ACC, 1); ///< Accumulator Bit 1
SI_SBIT (ACC_ACC2, SFR_ACC, 2); ///< Accumulator Bit 2
SI_SBIT (ACC_ACC3, SFR_ACC, 3); ///< Accumulator Bit 3
SI_SBIT (ACC_ACC4, SFR_ACC, 4); ///< Accumulator Bit 4
SI_SBIT (ACC_ACC5, SFR_ACC, 5); ///< Accumulator Bit 5
SI_SBIT (ACC_ACC6, SFR_ACC, 6); ///< Accumulator Bit 6
SI_SBIT (ACC_ACC7, SFR_ACC, 7); ///< Accumulator Bit 7

// ADC0CN (ADC0 Control)
#define SFR_ADC0CN 0xE8
SI_SBIT (ADC0CN_ADLJST, SFR_ADC0CN, 0); ///< ADC Left Justify Select              
SI_SBIT (ADC0CN_ADWINT, SFR_ADC0CN, 1); ///< Window Compare Interrupt Flag        
SI_SBIT (ADC0CN_ADCM0,  SFR_ADC0CN, 2); ///< Start of Conversion Mode Select Bit 0
SI_SBIT (ADC0CN_ADCM1,  SFR_ADC0CN, 3); ///< Start of Conversion Mode Select Bit 1
SI_SBIT (ADC0CN_ADBUSY, SFR_ADC0CN, 4); ///< ADC Busy                             
SI_SBIT (ADC0CN_ADINT,  SFR_ADC0CN, 5); ///< Conversion Complete Interrupt Flag   
SI_SBIT (ADC0CN_ADTM,   SFR_ADC0CN, 6); ///< ADC Track Mode                       
SI_SBIT (ADC0CN_ADEN,   SFR_ADC0CN, 7); ///< ADC Enable                           

// ADC2CN (ADC2 Control)
#define SFR_ADC2CN 0xE8
SI_SBIT (ADC2CN_ADWINT, SFR_ADC2CN, 0); ///< Window Compare Interrupt Flag        
SI_SBIT (ADC2CN_ADCM0,  SFR_ADC2CN, 1); ///< Start of Conversion Mode Select Bit 0
SI_SBIT (ADC2CN_ADCM1,  SFR_ADC2CN, 2); ///< Start of Conversion Mode Select Bit 1
SI_SBIT (ADC2CN_ADCM2,  SFR_ADC2CN, 3); ///< Start of Conversion Mode Select Bit 2
SI_SBIT (ADC2CN_ADBUSY, SFR_ADC2CN, 4); ///< ADC Busy                             
SI_SBIT (ADC2CN_ADINT,  SFR_ADC2CN, 5); ///< Conversion Complete Interrupt Flag   
SI_SBIT (ADC2CN_ADTM,   SFR_ADC2CN, 6); ///< ADC Track Mode                       
SI_SBIT (ADC2CN_ADEN,   SFR_ADC2CN, 7); ///< ADC Enable                           

// B (B Register)
#define SFR_B 0xF0
SI_SBIT (B_B0, SFR_B, 0); ///< B Register Bit 0
SI_SBIT (B_B1, SFR_B, 1); ///< B Register Bit 1
SI_SBIT (B_B2, SFR_B, 2); ///< B Register Bit 2
SI_SBIT (B_B3, SFR_B, 3); ///< B Register Bit 3
SI_SBIT (B_B4, SFR_B, 4); ///< B Register Bit 4
SI_SBIT (B_B5, SFR_B, 5); ///< B Register Bit 5
SI_SBIT (B_B6, SFR_B, 6); ///< B Register Bit 6
SI_SBIT (B_B7, SFR_B, 7); ///< B Register Bit 7

// CPT0CN (Comparator 0 Control)
#define SFR_CPT0CN 0x88
SI_SBIT (CPT0CN_CPHYN0, SFR_CPT0CN, 0); ///< Comparator Negative Hysteresis Control Bit 0
SI_SBIT (CPT0CN_CPHYN1, SFR_CPT0CN, 1); ///< Comparator Negative Hysteresis Control Bit 1
SI_SBIT (CPT0CN_CPHYP0, SFR_CPT0CN, 2); ///< Comparator Positive Hysteresis Control Bit 0
SI_SBIT (CPT0CN_CPHYP1, SFR_CPT0CN, 3); ///< Comparator Positive Hysteresis Control Bit 1
SI_SBIT (CPT0CN_CPFIF,  SFR_CPT0CN, 4); ///< Comparator Falling-Edge Flag                
SI_SBIT (CPT0CN_CPRIF,  SFR_CPT0CN, 5); ///< Comparator Rising-Edge Flag                 
SI_SBIT (CPT0CN_CPOUT,  SFR_CPT0CN, 6); ///< Comparator Output State Flag                
SI_SBIT (CPT0CN_CPEN,   SFR_CPT0CN, 7); ///< Comparator Enable                           

// CPT1CN (Comparator 1 Control)
#define SFR_CPT1CN 0x88
SI_SBIT (CPT1CN_CPHYN0, SFR_CPT1CN, 0); ///< Comparator Negative Hysteresis Control Bit 0
SI_SBIT (CPT1CN_CPHYN1, SFR_CPT1CN, 1); ///< Comparator Negative Hysteresis Control Bit 1
SI_SBIT (CPT1CN_CPHYP0, SFR_CPT1CN, 2); ///< Comparator Positive Hysteresis Control Bit 0
SI_SBIT (CPT1CN_CPHYP1, SFR_CPT1CN, 3); ///< Comparator Positive Hysteresis Control Bit 1
SI_SBIT (CPT1CN_CPFIF,  SFR_CPT1CN, 4); ///< Comparator Falling-Edge Flag                
SI_SBIT (CPT1CN_CPRIF,  SFR_CPT1CN, 5); ///< Comparator Rising-Edge Flag                 
SI_SBIT (CPT1CN_CPOUT,  SFR_CPT1CN, 6); ///< Comparator Output State Flag                
SI_SBIT (CPT1CN_CPEN,   SFR_CPT1CN, 7); ///< Comparator Enable                           

// FLSTAT (Flash Status)
#define SFR_FLSTAT 0x88
SI_SBIT (FLSTAT_FLBUSY, SFR_FLSTAT, 0); ///< Flash Busy

// IE (Interrupt Enable)
#define SFR_IE 0xA8
SI_SBIT (IE_EX0,   SFR_IE, 0); ///< External Interrupt 0 Enable
SI_SBIT (IE_ET0,   SFR_IE, 1); ///< Timer 0 Interrupt Enable   
SI_SBIT (IE_EX1,   SFR_IE, 2); ///< External Interrupt 1 Enable
SI_SBIT (IE_ET1,   SFR_IE, 3); ///< Timer 1 Interrupt Enable   
SI_SBIT (IE_ES0,   SFR_IE, 4); ///< UART0 Interrupt Enable     
SI_SBIT (IE_ET2,   SFR_IE, 5); ///< Timer 2 Interrupt Enable   
SI_SBIT (IE_ESPI0, SFR_IE, 6); ///< SPI0 Interrupt Enable      
SI_SBIT (IE_IEGF0, SFR_IE, 6); ///< General Purpose Flag 0     
SI_SBIT (IE_EA,    SFR_IE, 7); ///< All Interrupts Enable      

// IP (Interrupt Priority)
#define SFR_IP 0xB8
SI_SBIT (IP_PX0,   SFR_IP, 0); ///< External Interrupt 0 Priority Control                        
SI_SBIT (IP_PT0,   SFR_IP, 1); ///< Timer 0 Interrupt Priority Control                           
SI_SBIT (IP_PX1,   SFR_IP, 2); ///< External Interrupt 1 Priority Control                        
SI_SBIT (IP_PT1,   SFR_IP, 3); ///< Timer 1 Interrupt Priority Control                           
SI_SBIT (IP_PS0,   SFR_IP, 4); ///< UART0 Interrupt Priority Control                             
SI_SBIT (IP_PT2,   SFR_IP, 5); ///< Timer 2 Interrupt Priority Control                           
SI_SBIT (IP_PSPI0, SFR_IP, 6); ///< Serial Peripheral Interface (SPI0) Interrupt Priority Control

// MAC0STA (MAC0 Status)
#define SFR_MAC0STA 0xC0
SI_SBIT (MAC0STA_NEGF,  SFR_MAC0STA, 0); ///< Negative Flag     
SI_SBIT (MAC0STA_SOVF,  SFR_MAC0STA, 1); ///< Soft Overflow Flag
SI_SBIT (MAC0STA_ZEROF, SFR_MAC0STA, 2); ///< Zero Flag         
SI_SBIT (MAC0STA_HOVF,  SFR_MAC0STA, 3); ///< Hard Overflow Flag

// P0 (Port 0 Pin Latch)
#define SFR_P0 0x80
SI_SBIT (P0_B0, SFR_P0, 0); ///< Port 0 Bit 0 Latch
SI_SBIT (P0_B1, SFR_P0, 1); ///< Port 0 Bit 1 Latch
SI_SBIT (P0_B2, SFR_P0, 2); ///< Port 0 Bit 2 Latch
SI_SBIT (P0_B3, SFR_P0, 3); ///< Port 0 Bit 3 Latch
SI_SBIT (P0_B4, SFR_P0, 4); ///< Port 0 Bit 4 Latch
SI_SBIT (P0_B5, SFR_P0, 5); ///< Port 0 Bit 5 Latch
SI_SBIT (P0_B6, SFR_P0, 6); ///< Port 0 Bit 6 Latch
SI_SBIT (P0_B7, SFR_P0, 7); ///< Port 0 Bit 7 Latch

// P1 (Port 1 Pin Latch)
#define SFR_P1 0x90
SI_SBIT (P1_B0, SFR_P1, 0); ///< Port 1 Bit 0 Latch
SI_SBIT (P1_B1, SFR_P1, 1); ///< Port 1 Bit 1 Latch
SI_SBIT (P1_B2, SFR_P1, 2); ///< Port 1 Bit 2 Latch
SI_SBIT (P1_B3, SFR_P1, 3); ///< Port 1 Bit 3 Latch
SI_SBIT (P1_B4, SFR_P1, 4); ///< Port 1 Bit 4 Latch
SI_SBIT (P1_B5, SFR_P1, 5); ///< Port 1 Bit 5 Latch
SI_SBIT (P1_B6, SFR_P1, 6); ///< Port 1 Bit 6 Latch
SI_SBIT (P1_B7, SFR_P1, 7); ///< Port 1 Bit 7 Latch

// P2 (Port 2 Pin Latch)
#define SFR_P2 0xA0
SI_SBIT (P2_B0, SFR_P2, 0); ///< Port 2 Bit 0 Latch
SI_SBIT (P2_B1, SFR_P2, 1); ///< Port 2 Bit 1 Latch
SI_SBIT (P2_B2, SFR_P2, 2); ///< Port 2 Bit 2 Latch
SI_SBIT (P2_B3, SFR_P2, 3); ///< Port 2 Bit 3 Latch
SI_SBIT (P2_B4, SFR_P2, 4); ///< Port 2 Bit 4 Latch
SI_SBIT (P2_B5, SFR_P2, 5); ///< Port 2 Bit 5 Latch
SI_SBIT (P2_B6, SFR_P2, 6); ///< Port 2 Bit 6 Latch
SI_SBIT (P2_B7, SFR_P2, 7); ///< Port 2 Bit 7 Latch

// P3 (Port 3 Pin Latch)
#define SFR_P3 0xB0
SI_SBIT (P3_B0, SFR_P3, 0); ///< Port 3 Bit 0 Latch
SI_SBIT (P3_B1, SFR_P3, 1); ///< Port 3 Bit 1 Latch
SI_SBIT (P3_B2, SFR_P3, 2); ///< Port 3 Bit 2 Latch
SI_SBIT (P3_B3, SFR_P3, 3); ///< Port 3 Bit 3 Latch
SI_SBIT (P3_B4, SFR_P3, 4); ///< Port 3 Bit 4 Latch
SI_SBIT (P3_B5, SFR_P3, 5); ///< Port 3 Bit 5 Latch
SI_SBIT (P3_B6, SFR_P3, 6); ///< Port 3 Bit 6 Latch
SI_SBIT (P3_B7, SFR_P3, 7); ///< Port 3 Bit 7 Latch

// P4 (Port 4 Pin Latch)
#define SFR_P4 0xC8
SI_SBIT (P4_B0, SFR_P4, 0); ///< Port 4 Bit 0 Latch
SI_SBIT (P4_B1, SFR_P4, 1); ///< Port 4 Bit 1 Latch
SI_SBIT (P4_B2, SFR_P4, 2); ///< Port 4 Bit 2 Latch
SI_SBIT (P4_B3, SFR_P4, 3); ///< Port 4 Bit 3 Latch
SI_SBIT (P4_B4, SFR_P4, 4); ///< Port 4 Bit 4 Latch
SI_SBIT (P4_B5, SFR_P4, 5); ///< Port 4 Bit 5 Latch
SI_SBIT (P4_B6, SFR_P4, 6); ///< Port 4 Bit 6 Latch
SI_SBIT (P4_B7, SFR_P4, 7); ///< Port 4 Bit 7 Latch

// P5 (Port 5 Pin Latch)
#define SFR_P5 0xD8
SI_SBIT (P5_B0, SFR_P5, 0); ///< Port 5 Bit 0 Latch
SI_SBIT (P5_B1, SFR_P5, 1); ///< Port 5 Bit 1 Latch
SI_SBIT (P5_B2, SFR_P5, 2); ///< Port 5 Bit 2 Latch
SI_SBIT (P5_B3, SFR_P5, 3); ///< Port 5 Bit 3 Latch
SI_SBIT (P5_B4, SFR_P5, 4); ///< Port 5 Bit 4 Latch
SI_SBIT (P5_B5, SFR_P5, 5); ///< Port 5 Bit 5 Latch
SI_SBIT (P5_B6, SFR_P5, 6); ///< Port 5 Bit 6 Latch
SI_SBIT (P5_B7, SFR_P5, 7); ///< Port 5 Bit 7 Latch

// P6 (Port 6 Pin Latch)
#define SFR_P6 0xE8
SI_SBIT (P6_B0, SFR_P6, 0); ///< Port 6 Bit 0 Latch
SI_SBIT (P6_B1, SFR_P6, 1); ///< Port 6 Bit 1 Latch
SI_SBIT (P6_B2, SFR_P6, 2); ///< Port 6 Bit 2 Latch
SI_SBIT (P6_B3, SFR_P6, 3); ///< Port 6 Bit 3 Latch
SI_SBIT (P6_B4, SFR_P6, 4); ///< Port 6 Bit 4 Latch
SI_SBIT (P6_B5, SFR_P6, 5); ///< Port 6 Bit 5 Latch
SI_SBIT (P6_B6, SFR_P6, 6); ///< Port 6 Bit 6 Latch
SI_SBIT (P6_B7, SFR_P6, 7); ///< Port 6 Bit 7 Latch

// P7 (Port 7 Pin Latch)
#define SFR_P7 0xF8
SI_SBIT (P7_B0, SFR_P7, 0); ///< Port 7 Bit 0 Latch
SI_SBIT (P7_B1, SFR_P7, 1); ///< Port 7 Bit 1 Latch
SI_SBIT (P7_B2, SFR_P7, 2); ///< Port 7 Bit 2 Latch
SI_SBIT (P7_B3, SFR_P7, 3); ///< Port 7 Bit 3 Latch
SI_SBIT (P7_B4, SFR_P7, 4); ///< Port 7 Bit 4 Latch
SI_SBIT (P7_B5, SFR_P7, 5); ///< Port 7 Bit 5 Latch
SI_SBIT (P7_B6, SFR_P7, 6); ///< Port 7 Bit 6 Latch
SI_SBIT (P7_B7, SFR_P7, 7); ///< Port 7 Bit 7 Latch

// PCA0CN (PCA Control)
#define SFR_PCA0CN 0xD8
SI_SBIT (PCA0CN_CCF0, SFR_PCA0CN, 0); ///< PCA Module 0 Capture/Compare Flag
SI_SBIT (PCA0CN_CCF1, SFR_PCA0CN, 1); ///< PCA Module 1 Capture/Compare Flag
SI_SBIT (PCA0CN_CCF2, SFR_PCA0CN, 2); ///< PCA Module 2 Capture/Compare Flag
SI_SBIT (PCA0CN_CCF3, SFR_PCA0CN, 3); ///< PCA Module 3 Capture/Compare Flag
SI_SBIT (PCA0CN_CCF4, SFR_PCA0CN, 4); ///< PCA Module 4 Capture/Compare Flag
SI_SBIT (PCA0CN_CCF5, SFR_PCA0CN, 5); ///< PCA Module 5 Capture/Compare Flag
SI_SBIT (PCA0CN_CR,   SFR_PCA0CN, 6); ///< PCA Counter/Timer Run Control    
SI_SBIT (PCA0CN_CF,   SFR_PCA0CN, 7); ///< PCA Counter/Timer Overflow Flag  

// PSW (Program Status Word)
#define SFR_PSW 0xD0
SI_SBIT (PSW_PARITY, SFR_PSW, 0); ///< Parity Flag               
SI_SBIT (PSW_F1,     SFR_PSW, 1); ///< User Flag 1               
SI_SBIT (PSW_OV,     SFR_PSW, 2); ///< Overflow Flag             
SI_SBIT (PSW_RS0,    SFR_PSW, 3); ///< Register Bank Select Bit 0
SI_SBIT (PSW_RS1,    SFR_PSW, 4); ///< Register Bank Select Bit 1
SI_SBIT (PSW_F0,     SFR_PSW, 5); ///< User Flag 0               
SI_SBIT (PSW_AC,     SFR_PSW, 6); ///< Auxiliary Carry Flag      
SI_SBIT (PSW_CY,     SFR_PSW, 7); ///< Carry Flag                

// SCON0 (UART0 Serial Port Control)
#define SFR_SCON0 0x98
SI_SBIT (SCON0_RI,  SFR_SCON0, 0); ///< Receive Interrupt Flag             
SI_SBIT (SCON0_TI,  SFR_SCON0, 1); ///< Transmit Interrupt Flag            
SI_SBIT (SCON0_RB8, SFR_SCON0, 2); ///< Ninth Receive Bit                  
SI_SBIT (SCON0_TB8, SFR_SCON0, 3); ///< Ninth Transmission Bit             
SI_SBIT (SCON0_REN, SFR_SCON0, 4); ///< Receive Enable                     
SI_SBIT (SCON0_SM2, SFR_SCON0, 5); ///< Multiprocessor Communication Enable
SI_SBIT (SCON0_SM0, SFR_SCON0, 6); ///< Serial Port 0 Operation Mode Bit 0 
SI_SBIT (SCON0_SM1, SFR_SCON0, 7); ///< Serial Port 0 Operation Mode Bit 1 

// SCON1 (UART1 Serial Port Control)
#define SFR_SCON1 0x98
SI_SBIT (SCON1_RI,    SFR_SCON1, 0); ///< Receive Interrupt Flag             
SI_SBIT (SCON1_TI,    SFR_SCON1, 1); ///< Transmit Interrupt Flag            
SI_SBIT (SCON1_RB8,   SFR_SCON1, 2); ///< Ninth Receive Bit                  
SI_SBIT (SCON1_TB8,   SFR_SCON1, 3); ///< Ninth Transmission Bit             
SI_SBIT (SCON1_REN,   SFR_SCON1, 4); ///< Receive Enable                     
SI_SBIT (SCON1_MCE,   SFR_SCON1, 5); ///< Multiprocessor Communication Enable
SI_SBIT (SCON1_SMODE, SFR_SCON1, 7); ///< Serial Port 0 Operation Mode       

// SMB0CN (SMBus 0 Control)
#define SFR_SMB0CN 0xC0
SI_SBIT (SMB0CN_TOE,   SFR_SMB0CN, 0); ///< SMBus Timeout Enable         
SI_SBIT (SMB0CN_FTE,   SFR_SMB0CN, 1); ///< SMBus Free Timer Enable      
SI_SBIT (SMB0CN_AA,    SFR_SMB0CN, 2); ///< SMBus Assert Acknowledge Flag
SI_SBIT (SMB0CN_SI,    SFR_SMB0CN, 3); ///< SMBus Acknowledge Request    
SI_SBIT (SMB0CN_STO,   SFR_SMB0CN, 4); ///< SMBus Stop Flag              
SI_SBIT (SMB0CN_STA,   SFR_SMB0CN, 5); ///< SMBus Start Flag             
SI_SBIT (SMB0CN_ENSMB, SFR_SMB0CN, 6); ///< SMBus Enable                 
SI_SBIT (SMB0CN_BUSY,  SFR_SMB0CN, 7); ///< Busy Status Flag             

// SPI0CN (SPI0 Control)
#define SFR_SPI0CN 0xF8
SI_SBIT (SPI0CN_SPIEN,  SFR_SPI0CN, 0); ///< SPI0 Enable            
SI_SBIT (SPI0CN_TXBMT,  SFR_SPI0CN, 1); ///< Transmit Buffer Empty  
SI_SBIT (SPI0CN_NSSMD0, SFR_SPI0CN, 2); ///< Slave Select Mode Bit 0
SI_SBIT (SPI0CN_NSSMD1, SFR_SPI0CN, 3); ///< Slave Select Mode Bit 1
SI_SBIT (SPI0CN_RXOVRN, SFR_SPI0CN, 4); ///< Receive Overrun Flag   
SI_SBIT (SPI0CN_MODF,   SFR_SPI0CN, 5); ///< Mode Fault Flag        
SI_SBIT (SPI0CN_WCOL,   SFR_SPI0CN, 6); ///< Write Collision Flag   
SI_SBIT (SPI0CN_SPIF,   SFR_SPI0CN, 7); ///< SPI0 Interrupt Flag    

// TCON (Timer 0/1 Control)
#define SFR_TCON 0x88
SI_SBIT (TCON_IT0, SFR_TCON, 0); ///< Interrupt 0 Type Select
SI_SBIT (TCON_IE0, SFR_TCON, 1); ///< External Interrupt 0   
SI_SBIT (TCON_IT1, SFR_TCON, 2); ///< Interrupt 1 Type Select
SI_SBIT (TCON_IE1, SFR_TCON, 3); ///< External Interrupt 1   
SI_SBIT (TCON_TR0, SFR_TCON, 4); ///< Timer 0 Run Control    
SI_SBIT (TCON_TF0, SFR_TCON, 5); ///< Timer 0 Overflow Flag  
SI_SBIT (TCON_TR1, SFR_TCON, 6); ///< Timer 1 Run Control    
SI_SBIT (TCON_TF1, SFR_TCON, 7); ///< Timer 1 Overflow Flag  

// TMR2CN (Timer 2 Control)
#define SFR_TMR2CN 0xC8
SI_SBIT (TMR2CN_CPRL2, SFR_TMR2CN, 0); ///< Capture/Reload Select          
SI_SBIT (TMR2CN_CT2,   SFR_TMR2CN, 1); ///< Counter/Timer Select           
SI_SBIT (TMR2CN_TR2,   SFR_TMR2CN, 2); ///< Timer 2 Run Control            
SI_SBIT (TMR2CN_EXEN2, SFR_TMR2CN, 3); ///< Timer 2 External Enable        
SI_SBIT (TMR2CN_EXF2,  SFR_TMR2CN, 6); ///< Timer 2 External Flag          
SI_SBIT (TMR2CN_TF2,   SFR_TMR2CN, 7); ///< Timer 2 Overflow/Underflow Flag

// TMR3CN (Timer 3 Control)
#define SFR_TMR3CN 0xC8
SI_SBIT (TMR3CN_CPRL3, SFR_TMR3CN, 0); ///< Capture/Reload Select          
SI_SBIT (TMR3CN_CT3,   SFR_TMR3CN, 1); ///< Counter/Timer Select           
SI_SBIT (TMR3CN_TR3,   SFR_TMR3CN, 2); ///< Timer 3 Run Control            
SI_SBIT (TMR3CN_EXEN3, SFR_TMR3CN, 3); ///< Timer 3 External Enable        
SI_SBIT (TMR3CN_EXF3,  SFR_TMR3CN, 6); ///< Timer 3 External Flag          
SI_SBIT (TMR3CN_TF3,   SFR_TMR3CN, 7); ///< Timer 3 Overflow/Underflow Flag

// TMR4CN (Timer 4 Control)
#define SFR_TMR4CN 0xC8
SI_SBIT (TMR4CN_CPRL4, SFR_TMR4CN, 0); ///< Capture/Reload Select          
SI_SBIT (TMR4CN_CT4,   SFR_TMR4CN, 1); ///< Counter/Timer Select           
SI_SBIT (TMR4CN_TR4,   SFR_TMR4CN, 2); ///< Timer 4 Run Control            
SI_SBIT (TMR4CN_EXEN4, SFR_TMR4CN, 3); ///< Timer 4 External Enable        
SI_SBIT (TMR4CN_EXF4,  SFR_TMR4CN, 6); ///< Timer 4 External Flag          
SI_SBIT (TMR4CN_TF4,   SFR_TMR4CN, 7); ///< Timer 4 Overflow/Underflow Flag

//------------------------------------------------------------------------------
// Interrupt Definitions
//------------------------------------------------------------------------------
#define INT0_IRQn    0  ///< External Interrupt 0     
#define TIMER0_IRQn  1  ///< Timer 0 Overflow         
#define INT1_IRQn    2  ///< External Interrupt 1     
#define TIMER1_IRQn  3  ///< Timer 1 Overflow         
#define UART0_IRQn   4  ///< UART0                    
#define TIMER2_IRQn  5  ///< Timer 2 Overflow         
#define SPI0_IRQn    6  ///< SPI0                     
#define SMBUS0_IRQn  7  ///< SMBus 0                  
#define ADC0WC_IRQn  8  ///< ADC0 Window Compare      
#define PCA0_IRQn    9  ///< PCA0                     
#define CMP0F_IRQn   10 ///< Comparator 0 Falling Edge
#define CMP0R_IRQn   11 ///< Comparator 0 Rising Edge 
#define CMP1F_IRQn   12 ///< Comparator 1 Falling Edge
#define CMP1R_IRQn   13 ///< Comparator 1 Rising Edge 
#define TIMER3_IRQn  14 ///< Timer 3 Overflow         
#define ADC0EOC_IRQn 15 ///< ADC0 End of Conversion   
#define TIMER4_IRQn  16 ///< Timer 4 Overflow         
#define ADC2WC_IRQn  17 ///< ADC2 Window Compare      
#define ADC2EOC_IRQn 18 ///< ADC2 End of Conversion   
#define UART1_IRQn   20 ///< UART1                    

//------------------------------------------------------------------------------
// SFR Page Definitions
//------------------------------------------------------------------------------
#define ADC0_PAGE    0x00 ///< ADC0 Page                         
#define DAC0_PAGE    0x00 ///< DAC0 Page                         
#define EMI0_PAGE    0x00 ///< EMIF Page                         
#define LEGACY_PAGE  0x00 ///< Legacy SFR Page                   
#define PCA0_PAGE    0x00 ///< PCA0 Page                         
#define REF0_PAGE    0x00 ///< VREF0 Page                        
#define SMB0_PAGE    0x00 ///< SMBus 0 Page                      
#define SPI0_PAGE    0x00 ///< SPI0 Page                         
#define TIMER01_PAGE 0x00 ///< Timer 0 and Timer 1 Page          
#define TMR2_PAGE    0x00 ///< Timer 2 Page                      
#define UART0_PAGE   0x00 ///< UART0 Page                        
#define CPT0_PAGE    0x01 ///< Comparator 0 Page                 
#define DAC1_PAGE    0x01 ///< DAC1 Page                         
#define TMR3_PAGE    0x01 ///< Timer 3 Page                      
#define UART1_PAGE   0x01 ///< UART1 Page                        
#define ADC2_PAGE    0x02 ///< ADC2 Page                         
#define CPT1_PAGE    0x02 ///< Comparator 1 Page                 
#define TMR4_PAGE    0x02 ///< Timer 4 Page                      
#define MAC0_PAGE    0x03 ///< MAC Page                          
#define CONFIG_PAGE  0x0F ///< System and Port Configuration Page
#define PLL0_PAGE    0x0F ///< PLL0 Page                         

//-----------------------------------------------------------------------------
// SDCC PDATA External Memory Paging Support
//-----------------------------------------------------------------------------

#if defined SDCC

SI_SFR(_XPAGE, 0xAA); // Point to the EMI0CN register

#endif

#endif // SI_C8051F120_SI_DEFS_H
//-eof--------------------------------------------------------------------------

