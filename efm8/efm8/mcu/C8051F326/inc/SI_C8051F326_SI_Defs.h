//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  C8051F326_GM
//  C8051F327_GM

#ifndef SI_C8051F326_SI_DEFS_H
#define SI_C8051F326_SI_DEFS_H

#include <si_toolchain.h>

//-----------------------------------------------------------------------------
// Register Definitions
//-----------------------------------------------------------------------------
SI_SFR (ACC,     0xE0); ///< Accumulator                              
SI_SFR (B,       0xF0); ///< B Register                               
SI_SFR (CKCON,   0x8E); ///< Clock Control                            
SI_SFR (CLKMUL,  0xB9); ///< Clock Multiplier Control                 
SI_SFR (CLKSEL,  0xA9); ///< Clock Select                             
SI_SFR (DPH,     0x83); ///< Data Pointer High                        
SI_SFR (DPL,     0x82); ///< Data Pointer Low                         
SI_SFR (EIE1,    0xE6); ///< Extended Interrupt Enable 1              
SI_SFR (EIE2,    0xE7); ///< Extended Interrupt Enable 2              
SI_SFR (EIP1,    0xF6); ///< Extended Interrupt Priority 1            
SI_SFR (EIP2,    0xF7); ///< Extended Interrupt Priority 2            
SI_SFR (EMI0CN,  0xAA); ///< External Memory Interface Control        
SI_SFR (FLKEY,   0xB7); ///< Flash Lock and Key                       
SI_SFR (FLSCL,   0xB6); ///< Flash Scale                              
SI_SFR (GPIOCN,  0xE2); ///< Global Port I/O Control                  
SI_SFR (IE,      0xA8); ///< Interrupt Enable                         
SI_SFR (IP,      0xB8); ///< Interrupt Priority                       
SI_SFR (OSCICL,  0xB3); ///< High Frequency Oscillator Calibration    
SI_SFR (OSCICN,  0xB2); ///< High Frequency Oscillator Control        
SI_SFR (OSCLCN,  0xE3); ///< Internal Low Frequency Oscillator Control
SI_SFR (P0,      0x80); ///< Port 0 Pin Latch                         
SI_SFR (P0MDOUT, 0xA4); ///< Port 0 Output Mode                       
SI_SFR (P2,      0xA0); ///< Port 2 Pin Latch                         
SI_SFR (P2MDOUT, 0xA6); ///< Port 2 Output Mode                       
SI_SFR (P3,      0xB0); ///< Port 3 Pin Latch                         
SI_SFR (P3MDOUT, 0xA7); ///< Port 3 Output Mode                       
SI_SFR (PCON,    0x87); ///< Power Control                            
SI_SFR (PSCTL,   0x8F); ///< Program Store Control                    
SI_SFR (PSW,     0xD0); ///< Program Status Word                      
SI_SFR (REG0CN,  0xC9); ///< Voltage Regulator Control                
SI_SFR (RSTSRC,  0xEF); ///< Reset Source                             
SI_SFR (SBCON0,  0x91); ///< UART0 Baud Rate Generator Control        
SI_SFR (SBRLH0,  0x94); ///< UART0 Baud Rate Generator High Byte      
SI_SFR (SBRLL0,  0x93); ///< UART0 Baud Rate Generator Low Byte       
SI_SFR (SBUF0,   0x99); ///< UART0 Serial Port Data Buffer            
SI_SFR (SCON0,   0x98); ///< UART0 Serial Port Control                
SI_SFR (SMOD0,   0x9A); ///< UART0 Mode                               
SI_SFR (SP,      0x81); ///< Stack Pointer                            
SI_SFR (TCON,    0x88); ///< Timer 0/1 Control                        
SI_SFR (TH0,     0x8C); ///< Timer 0 High Byte                        
SI_SFR (TH1,     0x8D); ///< Timer 1 High Byte                        
SI_SFR (TL0,     0x8A); ///< Timer 0 Low Byte                         
SI_SFR (TL1,     0x8B); ///< Timer 1 Low Byte                         
SI_SFR (TMOD,    0x89); ///< Timer 0/1 Mode                           
SI_SFR (USB0ADR, 0x96); ///< USB0 Indirect Address                    
SI_SFR (USB0DAT, 0x97); ///< USB0 Data                                
SI_SFR (USB0XCN, 0xD7); ///< USB0 Transceiver Control                 
SI_SFR (VDM0CN,  0xFF); ///< VDD Supply Monitor Control               

//------------------------------------------------------------------------------
// 16-bit Register Definitions (may not work on all compilers)
//------------------------------------------------------------------------------
SI_SFR16 (DP, 0x82); ///< Data Pointer 

//------------------------------------------------------------------------------
// Indirect Register Definitions
//------------------------------------------------------------------------------
#define CLKREC   0x0F ///< USB0 Clock Recovery Control       
#define CMIE     0x0B ///< USB0 Common Interrupt Enable      
#define CMINT    0x06 ///< USB0 Common Interrupt             
#define E0CNT    0x16 ///< USB0 Endpoint0 Data Count         
#define E0CSR    0x11 ///< USB0 Endpoint0 Control            
#define EINCSRH  0x12 ///< USB0 IN Endpoint Control High     
#define EINCSRL  0x11 ///< USB0 IN Endpoint Control          
#define EOUTCNTH 0x17 ///< USB0 OUT Endpoint Count High      
#define EOUTCNTL 0x16 ///< USB0 OUT Endpoint Count           
#define EOUTCSRH 0x15 ///< USB0 OUT Endpoint Control High    
#define EOUTCSRL 0x14 ///< USB0 OUT Endpoint Control         
#define FADDR    0x00 ///< USB0 Function Address             
#define FIFO0    0x20 ///< USB0 Endpoint 0 FIFO Access       
#define FIFO1    0x21 ///< USB0 Endpoint 1 FIFO Access       
#define FRAMEH   0x0D ///< USB0 Frame Number High            
#define FRAMEL   0x0C ///< USB0 Frame Number                 
#define IN1IE    0x07 ///< USB0 IN Endpoint Interrupt Enable 
#define IN1INT   0x02 ///< USB0 IN Endpoint Interrupt        
#define INDEX    0x0E ///< USB0 Endpoint Index               
#define OUT1IE   0x09 ///< USB0 OUT Endpoint Interrupt Enable
#define OUT1INT  0x04 ///< USB0 OUT Endpoint Interrupt       
#define POWER    0x01 ///< USB0 Power                        

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

// IE (Interrupt Enable)
#define SFR_IE 0xA8
SI_SBIT (IE_EX0, SFR_IE, 0); ///< External Interrupt 0 Enable
SI_SBIT (IE_ET0, SFR_IE, 1); ///< Timer 0 Interrupt Enable   
SI_SBIT (IE_EX1, SFR_IE, 2); ///< External Interrupt 1 Enable
SI_SBIT (IE_ET1, SFR_IE, 3); ///< Timer 1 Interrupt Enable   
SI_SBIT (IE_ES0, SFR_IE, 4); ///< UART0 Interrupt Enable     
SI_SBIT (IE_EA,  SFR_IE, 7); ///< All Interrupts Enable      

// IP (Interrupt Priority)
#define SFR_IP 0xB8
SI_SBIT (IP_PX0, SFR_IP, 0); ///< External Interrupt 0 Priority Control
SI_SBIT (IP_PT0, SFR_IP, 1); ///< Timer 0 Interrupt Priority Control   
SI_SBIT (IP_PX1, SFR_IP, 2); ///< External Interrupt 1 Priority Control
SI_SBIT (IP_PT1, SFR_IP, 3); ///< Timer 1 Interrupt Priority Control   
SI_SBIT (IP_PS0, SFR_IP, 4); ///< UART0 Interrupt Priority Control     

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

// P2 (Port 2 Pin Latch)
#define SFR_P2 0xA0
SI_SBIT (P2_B0, SFR_P2, 0); ///< Port 2 Bit 0 Latch
SI_SBIT (P2_B1, SFR_P2, 1); ///< Port 2 Bit 1 Latch
SI_SBIT (P2_B2, SFR_P2, 2); ///< Port 2 Bit 2 Latch
SI_SBIT (P2_B3, SFR_P2, 3); ///< Port 2 Bit 3 Latch
SI_SBIT (P2_B4, SFR_P2, 4); ///< Port 2 Bit 4 Latch
SI_SBIT (P2_B5, SFR_P2, 5); ///< Port 2 Bit 5 Latch

// P3 (Port 3 Pin Latch)
#define SFR_P3 0xB0
SI_SBIT (P3_B0, SFR_P3, 0); ///< Port 3 Bit 0 Latch

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
SI_SBIT (SCON0_RI,   SFR_SCON0, 0); ///< Receive Interrupt Flag   
SI_SBIT (SCON0_TI,   SFR_SCON0, 1); ///< Transmit Interrupt Flag  
SI_SBIT (SCON0_RBX,  SFR_SCON0, 2); ///< Extra Receive Bit        
SI_SBIT (SCON0_TBX,  SFR_SCON0, 3); ///< Extra Transmission Bit   
SI_SBIT (SCON0_REN,  SFR_SCON0, 4); ///< Receive Enable           
SI_SBIT (SCON0_PERR, SFR_SCON0, 6); ///< Parity Error Flag        
SI_SBIT (SCON0_OVR,  SFR_SCON0, 7); ///< Receive FIFO Overrun Flag

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

//------------------------------------------------------------------------------
// Interrupt Definitions
//------------------------------------------------------------------------------
#define INT0_IRQn    0  ///< External Interrupt 0
#define TIMER0_IRQn  1  ///< Timer 0 Overflow    
#define INT1_IRQn    2  ///< External Interrupt 1
#define TIMER1_IRQn  3  ///< Timer 1 Overflow    
#define UART0_IRQn   4  ///< UART 0              
#define USB0_IRQn    8  ///< USB0                
#define VBUSLVL_IRQn 15 ///< VBUS Level          

//-----------------------------------------------------------------------------
// SDCC PDATA External Memory Paging Support
//-----------------------------------------------------------------------------

#if defined SDCC

SI_SFR(_XPAGE, 0xAA); // Point to the EMI0CN register

#endif

#endif // SI_C8051F326_SI_DEFS_H
//-eof--------------------------------------------------------------------------

