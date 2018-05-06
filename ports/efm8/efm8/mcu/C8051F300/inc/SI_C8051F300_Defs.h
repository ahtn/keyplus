//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  C8051F300_GM
//  C8051F300_GS
//  C8051F301_GM
//  C8051F301_GS
//  C8051F302_GM
//  C8051F302_GS
//  C8051F303_GM
//  C8051F303_GS
//  C8051F304_GM
//  C8051F304_GS
//  C8051F305_GM
//  C8051F305_GS

#ifndef SI_C8051F300_DEFS_H
#define SI_C8051F300_DEFS_H

#include <compiler_defs.h>

//-----------------------------------------------------------------------------
// Register Definitions
//-----------------------------------------------------------------------------
SFR (ACC,      0xE0); ///< Accumulator                           
SFR (ADC0,     0xBE); ///< ADC0 Data Word                        
SFR (ADC0CF,   0xBC); ///< ADC0 Configuration                    
SFR (ADC0CN,   0xE8); ///< ADC0 Control                          
SFR (ADC0GT,   0xC4); ///< ADC0 Greater-Than Threshold           
SFR (ADC0LT,   0xC6); ///< ADC0 Less-Than Threshold              
SFR (AMX0SL,   0xBB); ///< AMUX0 Multiplexer Selection           
SFR (B,        0xF0); ///< B Register                            
SFR (CKCON,    0x8E); ///< Clock Control                         
SFR (CPT0CN,   0xF8); ///< Comparator 0 Control                  
SFR (CPT0MD,   0x9D); ///< Comparator 0 Mode                     
SFR (CPT0MX,   0x9F); ///< Comparator 0 Multiplexer Selection    
SFR (DPH,      0x83); ///< Data Pointer High                     
SFR (DPL,      0x82); ///< Data Pointer Low                      
SFR (EIE1,     0xE6); ///< Extended Interrupt Enable 1           
SFR (EIP1,     0xF6); ///< Extended Interrupt Priority 1         
SFR (FLKEY,    0xB7); ///< Flash Lock and Key                    
SFR (FLSCL,    0xB6); ///< Flash Scale                           
SFR (IE,       0xA8); ///< Interrupt Enable                      
SFR (IP,       0xB8); ///< Interrupt Priority                    
SFR (IT01CF,   0xE4); ///< INT0/INT1 Configuration               
SFR (OSCICL,   0xB3); ///< High Frequency Oscillator Calibration 
SFR (OSCICN,   0xB2); ///< High Frequency Oscillator Control     
SFR (OSCXCN,   0xB1); ///< External Oscillator Control           
SFR (P0,       0x80); ///< Port 0 Pin Latch                      
SFR (P0MDIN,   0xF1); ///< Port 0 Input Mode                     
SFR (P0MDOUT,  0xA4); ///< Port 0 Output Mode                    
SFR (PCA0CN,   0xD8); ///< PCA Control                           
SFR (PCA0CPH0, 0xFC); ///< PCA Channel 0 Capture Module High Byte
SFR (PCA0CPH1, 0xEA); ///< PCA Channel 1 Capture Module High Byte
SFR (PCA0CPH2, 0xEC); ///< PCA Channel 2 Capture Module High Byte
SFR (PCA0CPL0, 0xFB); ///< PCA Channel 0 Capture Module Low Byte 
SFR (PCA0CPL1, 0xE9); ///< PCA Channel 1 Capture Module Low Byte 
SFR (PCA0CPL2, 0xEB); ///< PCA Channel 2 Capture Module Low Byte 
SFR (PCA0CPM0, 0xDA); ///< PCA Channel 0 Capture/Compare Mode 0  
SFR (PCA0CPM1, 0xDB); ///< PCA Channel 1 Capture/Compare Mode    
SFR (PCA0CPM2, 0xDC); ///< PCA Channel 2 Capture/Compare Mode    
SFR (PCA0H,    0xFA); ///< PCA Counter/Timer High Byte           
SFR (PCA0L,    0xF9); ///< PCA Counter/Timer Low Byte            
SFR (PCA0MD,   0xD9); ///< PCA Mode                              
SFR (PCON,     0x87); ///< Power Control                         
SFR (PSCTL,    0x8F); ///< Program Store Control                 
SFR (PSW,      0xD0); ///< Program Status Word                   
SFR (REF0CN,   0xD1); ///< Voltage Reference Control             
SFR (RSTSRC,   0xEF); ///< Reset Source                          
SFR (SBUF0,    0x99); ///< UART0 Serial Port Data Buffer         
SFR (SCON0,    0x98); ///< UART0 Serial Port Control             
SFR (SMB0CF,   0xC1); ///< SMBus 0 Configuration                 
SFR (SMB0CN,   0xC0); ///< SMBus 0 Control                       
SFR (SMB0DAT,  0xC2); ///< SMBus 0 Data                          
SFR (SP,       0x81); ///< Stack Pointer                         
SFR (TCON,     0x88); ///< Timer 0/1 Control                     
SFR (TH0,      0x8C); ///< Timer 0 High Byte                     
SFR (TH1,      0x8D); ///< Timer 1 High Byte                     
SFR (TL0,      0x8A); ///< Timer 0 Low Byte                      
SFR (TL1,      0x8B); ///< Timer 1 Low Byte                      
SFR (TMOD,     0x89); ///< Timer 0/1 Mode                        
SFR (TMR2CN,   0xC8); ///< Timer 2 Control                       
SFR (TMR2H,    0xCD); ///< Timer 2 High Byte                     
SFR (TMR2L,    0xCC); ///< Timer 2 Low Byte                      
SFR (TMR2RLH,  0xCB); ///< Timer 2 Reload High Byte              
SFR (TMR2RLL,  0xCA); ///< Timer 2 Reload Low Byte               
SFR (XBR0,     0xE1); ///< Port I/O Crossbar 0                   
SFR (XBR1,     0xE2); ///< Port I/O Crossbar 1                   
SFR (XBR2,     0xE3); ///< Port I/O Crossbar 2                   

//------------------------------------------------------------------------------
// 16-bit Register Definitions (may not work on all compilers)
//------------------------------------------------------------------------------
SFR16 (DP,      0x82); ///< Data Pointer                 
SFR16 (PCA0CP0, 0xFB); ///< PCA Channel 0 Capture Module 
SFR16 (PCA0CP1, 0xE9); ///< PCA Channel 1 Capture Module 
SFR16 (PCA0CP2, 0xEB); ///< PCA Channel 2 Capture Module 
SFR16 (PCA0,    0xF9); ///< PCA Counter/Timer            
SFR16 (TMR2,    0xCC); ///< Timer 2                      
SFR16 (TMR2RL,  0xCA); ///< Timer 2 Reload               

//------------------------------------------------------------------------------
// Indirect Register Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Bit Definitions
//------------------------------------------------------------------------------

// ACC (Accumulator)
#define SFR_ACC 0xE0
SBIT (ACC_ACC0, SFR_ACC, 0); ///< Accumulator Bit 0
SBIT (ACC_ACC1, SFR_ACC, 1); ///< Accumulator Bit 1
SBIT (ACC_ACC2, SFR_ACC, 2); ///< Accumulator Bit 2
SBIT (ACC_ACC3, SFR_ACC, 3); ///< Accumulator Bit 3
SBIT (ACC_ACC4, SFR_ACC, 4); ///< Accumulator Bit 4
SBIT (ACC_ACC5, SFR_ACC, 5); ///< Accumulator Bit 5
SBIT (ACC_ACC6, SFR_ACC, 6); ///< Accumulator Bit 6
SBIT (ACC_ACC7, SFR_ACC, 7); ///< Accumulator Bit 7

// ADC0CN (ADC0 Control)
#define SFR_ADC0CN 0xE8
SBIT (ADC0CN_ADCM0,  SFR_ADC0CN, 0); ///< Start of Conversion Mode Select Bit 0
SBIT (ADC0CN_ADCM1,  SFR_ADC0CN, 1); ///< Start of Conversion Mode Select Bit 1
SBIT (ADC0CN_ADCM2,  SFR_ADC0CN, 2); ///< Start of Conversion Mode Select Bit 2
SBIT (ADC0CN_ADWINT, SFR_ADC0CN, 3); ///< Window Compare Interrupt Flag        
SBIT (ADC0CN_ADBUSY, SFR_ADC0CN, 4); ///< ADC Busy                             
SBIT (ADC0CN_ADINT,  SFR_ADC0CN, 5); ///< Conversion Complete Interrupt Flag   
SBIT (ADC0CN_ADTM,   SFR_ADC0CN, 6); ///< Track Mode                           
SBIT (ADC0CN_ADEN,   SFR_ADC0CN, 7); ///< ADC Enable                           

// B (B Register)
#define SFR_B 0xF0
SBIT (B_B0, SFR_B, 0); ///< B Register Bit 0
SBIT (B_B1, SFR_B, 1); ///< B Register Bit 1
SBIT (B_B2, SFR_B, 2); ///< B Register Bit 2
SBIT (B_B3, SFR_B, 3); ///< B Register Bit 3
SBIT (B_B4, SFR_B, 4); ///< B Register Bit 4
SBIT (B_B5, SFR_B, 5); ///< B Register Bit 5
SBIT (B_B6, SFR_B, 6); ///< B Register Bit 6
SBIT (B_B7, SFR_B, 7); ///< B Register Bit 7

// CPT0CN (Comparator 0 Control)
#define SFR_CPT0CN 0xF8
SBIT (CPT0CN_CPHYN0, SFR_CPT0CN, 0); ///< Comparator Negative Hysteresis Control Bit 0
SBIT (CPT0CN_CPHYN1, SFR_CPT0CN, 1); ///< Comparator Negative Hysteresis Control Bit 1
SBIT (CPT0CN_CPHYP0, SFR_CPT0CN, 2); ///< Comparator Positive Hysteresis Control Bit 0
SBIT (CPT0CN_CPHYP1, SFR_CPT0CN, 3); ///< Comparator Positive Hysteresis Control Bit 1
SBIT (CPT0CN_CPFIF,  SFR_CPT0CN, 4); ///< Comparator Falling-Edge Flag                
SBIT (CPT0CN_CPRIF,  SFR_CPT0CN, 5); ///< Comparator Rising-Edge Flag                 
SBIT (CPT0CN_CPOUT,  SFR_CPT0CN, 6); ///< Comparator Output State Flag                
SBIT (CPT0CN_CPEN,   SFR_CPT0CN, 7); ///< Comparator Enable                           

// IE (Interrupt Enable)
#define SFR_IE 0xA8
SBIT (IE_EX0,   SFR_IE, 0); ///< External Interrupt 0 Enable
SBIT (IE_ET0,   SFR_IE, 1); ///< Timer 0 Interrupt Enable   
SBIT (IE_EX1,   SFR_IE, 2); ///< External Interrupt 1 Enable
SBIT (IE_ET1,   SFR_IE, 3); ///< Timer 1 Interrupt Enable   
SBIT (IE_ES0,   SFR_IE, 4); ///< UART0 Interrupt Enable     
SBIT (IE_ET2,   SFR_IE, 5); ///< Timer 2 Interrupt Enable   
SBIT (IE_IEGF0, SFR_IE, 6); ///< General Purpose Flag 0     
SBIT (IE_EA,    SFR_IE, 7); ///< All Interrupts Enable      

// IP (Interrupt Priority)
#define SFR_IP 0xB8
SBIT (IP_PX0, SFR_IP, 0); ///< External Interrupt 0 Priority Control
SBIT (IP_PT0, SFR_IP, 1); ///< Timer 0 Interrupt Priority Control   
SBIT (IP_PX1, SFR_IP, 2); ///< External Interrupt 1 Priority Control
SBIT (IP_PT1, SFR_IP, 3); ///< Timer 1 Interrupt Priority Control   
SBIT (IP_PS0, SFR_IP, 4); ///< UART0 Interrupt Priority Control     
SBIT (IP_PT2, SFR_IP, 5); ///< Timer 2 Interrupt Priority Control   

// P0 (Port 0 Pin Latch)
#define SFR_P0 0x80
SBIT (P0_B0, SFR_P0, 0); ///< Port 0 Bit 0 Latch
SBIT (P0_B1, SFR_P0, 1); ///< Port 0 Bit 1 Latch
SBIT (P0_B2, SFR_P0, 2); ///< Port 0 Bit 2 Latch
SBIT (P0_B3, SFR_P0, 3); ///< Port 0 Bit 3 Latch
SBIT (P0_B4, SFR_P0, 4); ///< Port 0 Bit 4 Latch
SBIT (P0_B5, SFR_P0, 5); ///< Port 0 Bit 5 Latch
SBIT (P0_B6, SFR_P0, 6); ///< Port 0 Bit 6 Latch
SBIT (P0_B7, SFR_P0, 7); ///< Port 0 Bit 7 Latch

// PCA0CN (PCA Control)
#define SFR_PCA0CN 0xD8
SBIT (PCA0CN_CCF0, SFR_PCA0CN, 0); ///< PCA Module 0 Capture/Compare Flag
SBIT (PCA0CN_CCF1, SFR_PCA0CN, 1); ///< PCA Module 1 Capture/Compare Flag
SBIT (PCA0CN_CCF2, SFR_PCA0CN, 2); ///< PCA Module 2 Capture/Compare Flag
SBIT (PCA0CN_CR,   SFR_PCA0CN, 6); ///< PCA Counter/Timer Run Control    
SBIT (PCA0CN_CF,   SFR_PCA0CN, 7); ///< PCA Counter/Timer Overflow Flag  

// PSW (Program Status Word)
#define SFR_PSW 0xD0
SBIT (PSW_PARITY, SFR_PSW, 0); ///< Parity Flag               
SBIT (PSW_F1,     SFR_PSW, 1); ///< User Flag 1               
SBIT (PSW_OV,     SFR_PSW, 2); ///< Overflow Flag             
SBIT (PSW_RS0,    SFR_PSW, 3); ///< Register Bank Select Bit 0
SBIT (PSW_RS1,    SFR_PSW, 4); ///< Register Bank Select Bit 1
SBIT (PSW_F0,     SFR_PSW, 5); ///< User Flag 0               
SBIT (PSW_AC,     SFR_PSW, 6); ///< Auxiliary Carry Flag      
SBIT (PSW_CY,     SFR_PSW, 7); ///< Carry Flag                

// SCON0 (UART0 Serial Port Control)
#define SFR_SCON0 0x98
SBIT (SCON0_RI,    SFR_SCON0, 0); ///< Receive Interrupt Flag             
SBIT (SCON0_TI,    SFR_SCON0, 1); ///< Transmit Interrupt Flag            
SBIT (SCON0_RB8,   SFR_SCON0, 2); ///< Ninth Receive Bit                  
SBIT (SCON0_TB8,   SFR_SCON0, 3); ///< Ninth Transmission Bit             
SBIT (SCON0_REN,   SFR_SCON0, 4); ///< Receive Enable                     
SBIT (SCON0_MCE,   SFR_SCON0, 5); ///< Multiprocessor Communication Enable
SBIT (SCON0_SMODE, SFR_SCON0, 7); ///< Serial Port 0 Operation Mode       

// SMB0CN (SMBus 0 Control)
#define SFR_SMB0CN 0xC0
SBIT (SMB0CN_SI,      SFR_SMB0CN, 0); ///< SMBus Interrupt Flag            
SBIT (SMB0CN_ACK,     SFR_SMB0CN, 1); ///< SMBus Acknowledge               
SBIT (SMB0CN_ARBLOST, SFR_SMB0CN, 2); ///< SMBus Arbitration Lost Indicator
SBIT (SMB0CN_ACKRQ,   SFR_SMB0CN, 3); ///< SMBus Acknowledge Request       
SBIT (SMB0CN_STO,     SFR_SMB0CN, 4); ///< SMBus Stop Flag                 
SBIT (SMB0CN_STA,     SFR_SMB0CN, 5); ///< SMBus Start Flag                
SBIT (SMB0CN_TXMODE,  SFR_SMB0CN, 6); ///< SMBus Transmit Mode Indicator   
SBIT (SMB0CN_MASTER,  SFR_SMB0CN, 7); ///< SMBus Master/Slave Indicator    

// TCON (Timer 0/1 Control)
#define SFR_TCON 0x88
SBIT (TCON_IT0, SFR_TCON, 0); ///< Interrupt 0 Type Select
SBIT (TCON_IE0, SFR_TCON, 1); ///< External Interrupt 0   
SBIT (TCON_IT1, SFR_TCON, 2); ///< Interrupt 1 Type Select
SBIT (TCON_IE1, SFR_TCON, 3); ///< External Interrupt 1   
SBIT (TCON_TR0, SFR_TCON, 4); ///< Timer 0 Run Control    
SBIT (TCON_TF0, SFR_TCON, 5); ///< Timer 0 Overflow Flag  
SBIT (TCON_TR1, SFR_TCON, 6); ///< Timer 1 Run Control    
SBIT (TCON_TF1, SFR_TCON, 7); ///< Timer 1 Overflow Flag  

// TMR2CN (Timer 2 Control)
#define SFR_TMR2CN 0xC8
SBIT (TMR2CN_T2XCLK,  SFR_TMR2CN, 0); ///< Timer 2 External Clock Select    
SBIT (TMR2CN_TR2,     SFR_TMR2CN, 2); ///< Timer 2 Run Control              
SBIT (TMR2CN_T2SPLIT, SFR_TMR2CN, 3); ///< Timer 2 Split Mode Enable        
SBIT (TMR2CN_TF2LEN,  SFR_TMR2CN, 5); ///< Timer 2 Low Byte Interrupt Enable
SBIT (TMR2CN_TF2L,    SFR_TMR2CN, 6); ///< Timer 2 Low Byte Overflow Flag   
SBIT (TMR2CN_TF2H,    SFR_TMR2CN, 7); ///< Timer 2 High Byte Overflow Flag  

//------------------------------------------------------------------------------
// Interrupt Definitions
//------------------------------------------------------------------------------
#define INT0_IRQn     0  ///< External Interrupt 0     
#define TIMER0_IRQn   1  ///< Timer 0 Overflow         
#define INT1_IRQn     2  ///< External Interrupt 1     
#define TIMER1_IRQn   3  ///< Timer 1 Overflow         
#define UART0_IRQn    4  ///< UART 0                   
#define TIMER2_IRQn   5  ///< Timer 2 Overflow         
#define SMBUS0_IRQn   6  ///< SMBus 0                  
#define ADC0WC_IRQn   7  ///< ADC0 Window Compare      
#define ADC0EOC_IRQn  8  ///< ADC0 End of Conversion   
#define PCA0_IRQn     9  ///< PCA0                     
#define CMP0FALL_IRQn 10 ///< Comparator 0 Falling Edge
#define CMP0RISE_IRQn 11 ///< Comparator 0 Rising Edge 

//-----------------------------------------------------------------------------
// SDCC PDATA External Memory Paging Support
//-----------------------------------------------------------------------------

#if defined SDCC

SFR(_XPAGE, 0xAA); // Point to the EMI0CN register

#endif

#endif // SI_C8051F300_DEFS_H
//-eof--------------------------------------------------------------------------

