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

#ifndef SI_C8051F960_DEFS_H
#define SI_C8051F960_DEFS_H

#include <compiler_defs.h>

//-----------------------------------------------------------------------------
// Register Definitions
//-----------------------------------------------------------------------------
SFR (ACC,         0xE0); ///< Accumulator                           
SFR (ADC0AC,      0xBA); ///< ADC0 Accumulator Configuration        
SFR (ADC0CF,      0xBC); ///< ADC0 Configuration                    
SFR (ADC0CN,      0xE8); ///< ADC0 Control                          
SFR (ADC0GTH,     0xC4); ///< ADC0 Greater-Than High Byte           
SFR (ADC0GTL,     0xC3); ///< ADC0 Greater-Than Low Byte            
SFR (ADC0H,       0xBE); ///< ADC0 Data Word High Byte              
SFR (ADC0L,       0xBD); ///< ADC0 Data Word Low Byte               
SFR (ADC0LTH,     0xC6); ///< ADC0 Less-Than High Byte              
SFR (ADC0LTL,     0xC5); ///< ADC0 Less-Than Low Byte               
SFR (ADC0MX,      0xBB); ///< ADC0 Multiplexer Selection            
SFR (ADC0PWR,     0xBA); ///< ADC0 Power Control                    
SFR (ADC0TK,      0xBB); ///< ADC0 Burst Mode Track Time            
SFR (AES0BCFG,    0xE9); ///< AES Block Configuration               
SFR (AES0BIN,     0xEB); ///< AES Block Input                       
SFR (AES0DCFG,    0xEA); ///< AES Data Configuration                
SFR (AES0KIN,     0xED); ///< AES Key Input                         
SFR (AES0XIN,     0xEC); ///< AES XOR Input                         
SFR (AES0YOUT,    0xF5); ///< AES Y Output                          
SFR (B,           0xF0); ///< B Register                            
SFR (CKCON,       0x8E); ///< Clock Control                         
SFR (CLKMODE,     0xFD); ///< Clock Mode                            
SFR (CLKSEL,      0xA9); ///< Clock Select                          
SFR (CPT0CN,      0x9B); ///< Comparator 0 Control                  
SFR (CPT0MD,      0x9D); ///< Comparator 0 Mode                     
SFR (CPT0MX,      0x9F); ///< Comparator 0 Multiplexer Selection    
SFR (CPT1CN,      0x9A); ///< Comparator 1 Control                  
SFR (CPT1MD,      0x9C); ///< Comparator 1 Mode                     
SFR (CPT1MX,      0x9E); ///< Comparator 1 Multiplexer Selection    
SFR (CRC0AUTO,    0x96); ///< CRC0 Automatic Control                
SFR (CRC0CN,      0x92); ///< CRC0 Control                          
SFR (CRC0CNT,     0x97); ///< CRC0 Automatic Flash Sector Count     
SFR (CRC0DAT,     0x91); ///< CRC0 Data Output                      
SFR (CRC0FLIP,    0x94); ///< CRC0 Bit Flip                         
SFR (CRC0IN,      0x93); ///< CRC0 Data Input                       
SFR (CRC1CN,      0xBE); ///< CRC1 Control                          
SFR (CRC1IN,      0xB9); ///< CRC1 Data In                          
SFR (CRC1OUTH,    0xBB); ///< CRC1 Output High Byte                 
SFR (CRC1OUTL,    0xBA); ///< CRC1 Output Low Byte                  
SFR (CRC1POLH,    0xBD); ///< CRC1 Polynomial High Byte             
SFR (CRC1POLL,    0xBC); ///< CRC1 Polynomial Low Byte              
SFR (DC0CF,       0xB2); ///< DC-DC Converter Configuration         
SFR (DC0CN,       0xB1); ///< DC-DC Converter Control               
SFR (DC0MD,       0xB3); ///< DC-DC Converter Mode                  
SFR (DC0RDY,      0xFD); ///< DC-DC Converter Ready                 
SFR (DERIVID,     0xE9); ///< Device Identification                 
SFR (DMA0BUSY,    0xD5); ///< DMA0 Busy                             
SFR (DMA0EN,      0xD2); ///< DMA0 Channel Enable                   
SFR (DMA0INT,     0xD3); ///< DMA0 Full-Length Interrupt Flags      
SFR (DMA0MINT,    0xD4); ///< DMA0 Mid-Point Interrupt Flags        
SFR (DMA0NAOH,    0xCD); ///< Memory Address Offset High            
SFR (DMA0NAOL,    0xCC); ///< Memory Address Offset Low             
SFR (DMA0NBAH,    0xCB); ///< Memory Base Address High              
SFR (DMA0NBAL,    0xCA); ///< Memory Base Address Low               
SFR (DMA0NCF,     0xC9); ///< DMA0 Channel Configuration            
SFR (DMA0NMD,     0xD6); ///< DMA Channel Mode                      
SFR (DMA0NSZH,    0xCF); ///< Memory Transfer Size High             
SFR (DMA0NSZL,    0xCE); ///< Memory Transfer Size Low              
SFR (DMA0SEL,     0xD1); ///< DMA0 Channel Select                   
SFR (DPH,         0x83); ///< Data Pointer High                     
SFR (DPL,         0x82); ///< Data Pointer Low                      
SFR (EIE1,        0xE6); ///< Extended Interrupt Enable 1           
SFR (EIE2,        0xE7); ///< Extended Interrupt Enable 2           
SFR (EIP1,        0xF6); ///< Extended Interrupt Priority 1         
SFR (EIP2,        0xF7); ///< Extended Interrupt Priority 2         
SFR (EMI0CF,      0xAB); ///< External Memory Configuration         
SFR (EMI0CN,      0xAA); ///< External Memory Interface Control     
SFR (EMI0TC,      0xAF); ///< External Memory Timing Control        
SFR (ENC0CN,      0xC5); ///< Encoder / Decoder 0 Control           
SFR (ENC0H,       0xC4); ///< Encoder / Decoder 0 Data High Byte    
SFR (ENC0L,       0xC2); ///< Encoder / Decoder 0 Data Low Byte     
SFR (ENC0M,       0xC3); ///< Encoder / Decoder 0 Data Middle Byte  
SFR (FLKEY,       0xB7); ///< Flash Lock and Key                    
SFR (FLSCL,       0xB6); ///< Flash Scale                           
SFR (FLWR,        0xE5); ///< Flash Write Only                      
SFR (FRBCN,       0xB5); ///< Flash Read Buffer Control             
SFR (IE,          0xA8); ///< Interrupt Enable                      
SFR (IP,          0xB8); ///< Interrupt Priority                    
SFR (IREF0CF,     0xB9); ///< Current Reference Configuration       
SFR (IREF0CN,     0xB9); ///< Current Reference Control             
SFR (IT01CF,      0xE4); ///< INT0/INT1 Configuration               
SFR (LCD0BLINK,   0x9E); ///< LCD0 Blink Mask                       
SFR (LCD0CF,      0xA5); ///< LCD0 Configuration                    
SFR (LCD0CLKDIVH, 0xAA); ///< LCD0 Refresh Rate Prescaler High Byte 
SFR (LCD0CLKDIVL, 0xA9); ///< LCD Refresh Rate Prescaler Low Byte   
SFR (LCD0CN,      0x9D); ///< LCD0 Control                          
SFR (LCD0CNTRST,  0x9C); ///< LCD0 Contrast Adjustment              
SFR (LCD0D0,      0x89); ///< LCD0 Data 0                           
SFR (LCD0D1,      0x8A); ///< LCD0 Data 1                           
SFR (LCD0D2,      0x8B); ///< LCD0 Data 2                           
SFR (LCD0D3,      0x8C); ///< LCD0 Data 3                           
SFR (LCD0D4,      0x8D); ///< LCD0 Data 4                           
SFR (LCD0D5,      0x8E); ///< LCD0 Data 5                           
SFR (LCD0D6,      0x91); ///< LCD0 Data 6                           
SFR (LCD0D7,      0x92); ///< LCD0 Data 7                           
SFR (LCD0D8,      0x93); ///< LCD0 Data 8                           
SFR (LCD0D9,      0x94); ///< LCD0 Data 9                           
SFR (LCD0DA,      0x95); ///< LCD0 Data 10                          
SFR (LCD0DB,      0x96); ///< LCD0 Data 11                          
SFR (LCD0DC,      0x97); ///< LCD0 Data 12                          
SFR (LCD0DD,      0x99); ///< LCD0 Data 13                          
SFR (LCD0DE,      0x9A); ///< LCD0 Data 14                          
SFR (LCD0DF,      0x9B); ///< LCD0 Data 15                          
SFR (LCD0MSCF,    0xAC); ///< LCD0 Master Configuration             
SFR (LCD0MSCN,    0xAB); ///< LCD0 Master Control                   
SFR (LCD0PWR,     0xA4); ///< LCD0 Power                            
SFR (LCD0TOGR,    0x9F); ///< LCD0 Toggle Rate                      
SFR (LCD0VBMCN,   0xA6); ///< LCD0 VBAT Monitor Control             
SFR (OSCICL,      0xB3); ///< High Frequency Oscillator Calibration 
SFR (OSCICN,      0xB2); ///< High Frequency Oscillator Control     
SFR (OSCXCN,      0xB1); ///< External Oscillator Control           
SFR (P0,          0x80); ///< Port 0 Pin Latch                      
SFR (P0DRV,       0xA4); ///< Port 0 Drive Strength                 
SFR (P0MASK,      0xC7); ///< Port 0 Mask                           
SFR (P0MAT,       0xD7); ///< Port 0 Match                          
SFR (P0MDIN,      0xF1); ///< Port 0 Input Mode                     
SFR (P0MDOUT,     0xA4); ///< Port 0 Output Mode                    
SFR (P0SKIP,      0xD4); ///< Port 0 Skip                           
SFR (P1,          0x90); ///< Port 1 Pin Latch                      
SFR (P1DRV,       0xA5); ///< Port 1 Drive Strength                 
SFR (P1MASK,      0xBF); ///< Port 1 Mask                           
SFR (P1MAT,       0xCF); ///< Port 1 Match                          
SFR (P1MDIN,      0xF2); ///< Port 1 Input Mode                     
SFR (P1MDOUT,     0xA5); ///< Port 1 Output Mode                    
SFR (P1SKIP,      0xD5); ///< Port 1 Skip                           
SFR (P2,          0xA0); ///< Port 2 Pin Latch                      
SFR (P2DRV,       0xA6); ///< Port 2 Drive Strength                 
SFR (P2MDIN,      0xF3); ///< Port 2 Input Mode                     
SFR (P2MDOUT,     0xA6); ///< Port 2 Output Mode                    
SFR (P2SKIP,      0xD6); ///< Port 2 Skip                           
SFR (P3,          0xB0); ///< Port 3 Pin Latch                      
SFR (P3DRV,       0xA1); ///< Port 3 Drive Strength                 
SFR (P3MDIN,      0xF1); ///< Port 3 Input Mode                     
SFR (P3MDOUT,     0xB1); ///< Port 3 Output Mode                    
SFR (P4,          0xD9); ///< Port 4 Pin Latch                      
SFR (P4DRV,       0xA2); ///< Port 4 Drive Strength                 
SFR (P4MDIN,      0xF2); ///< Port 4 Input Mode                     
SFR (P4MDOUT,     0xF9); ///< Port 4 Output Mode                    
SFR (P5,          0xDA); ///< Port 5 Pin Latch                      
SFR (P5DRV,       0xA3); ///< Port 5 Drive Strength                 
SFR (P5MDIN,      0xF3); ///< Port 5 Input Mode                     
SFR (P5MDOUT,     0xFA); ///< Port 5 Output Mode                    
SFR (P6,          0xDB); ///< Port 6 Pin Latch                      
SFR (P6DRV,       0xAA); ///< Port 6 Drive Strength                 
SFR (P6MDIN,      0xF4); ///< Port 6 Input Mode                     
SFR (P6MDOUT,     0xFB); ///< Port 6 Output Mode                    
SFR (P7,          0xDC); ///< Port 7 Pin Latch                      
SFR (P7DRV,       0xAB); ///< Port 7 Drive Strength                 
SFR (P7MDOUT,     0xFC); ///< Port 7 Output Mode                    
SFR (PC0CMP0H,    0xE3); ///< PC0 Comparator 0 High Byte            
SFR (PC0CMP0L,    0xE1); ///< PC0 Comparator 0 Low Byte             
SFR (PC0CMP0M,    0xE2); ///< PC0 Comparator 0 Middle Byte          
SFR (PC0CMP1H,    0xF3); ///< PC0 Comparator 1 High Byte            
SFR (PC0CMP1L,    0xF1); ///< PC0 Comparator 1 Low Byte             
SFR (PC0CMP1M,    0xF2); ///< PC0 Comparator 1 Middle Byte          
SFR (PC0CTR0H,    0xDC); ///< PC0 Counter 0 High Byte               
SFR (PC0CTR0L,    0xDA); ///< PC0 Counter 0 Low Byte                
SFR (PC0CTR0M,    0xDB); ///< PC0 Counter 0 Middle Byte             
SFR (PC0CTR1H,    0xDF); ///< PC0 Counter 1 High Byte               
SFR (PC0CTR1L,    0xDD); ///< PC0 Counter 1 Low Byte                
SFR (PC0CTR1M,    0xDE); ///< PC0 Counter 1 Middle Byte             
SFR (PC0DCH,      0xFA); ///< PC0 Debounce Configuration High Byte  
SFR (PC0DCL,      0xF9); ///< PC0 Debounce Configuration Low Byte   
SFR (PC0HIST,     0xF4); ///< PC0 Direction History                 
SFR (PC0INT0,     0xFB); ///< PC0 Interrupt 0                       
SFR (PC0INT1,     0xFC); ///< PC0 Interrupt 1                       
SFR (PC0MD,       0xD9); ///< PC0 Mode Configuration                
SFR (PC0PCF,      0xD7); ///< PC0 Pull-Up Configuration             
SFR (PC0STAT,     0xC1); ///< PC0 Status                            
SFR (PC0TH,       0xE4); ///< PC0 Threshold Configuration           
SFR (PCA0CN,      0xD8); ///< PCA Control                           
SFR (PCA0CPH0,    0xFC); ///< PCA Channel 0 Capture Module High Byte
SFR (PCA0CPH1,    0xEA); ///< PCA Channel 1 Capture Module High Byte
SFR (PCA0CPH2,    0xEC); ///< PCA Channel 2 Capture Module High Byte
SFR (PCA0CPH3,    0xEE); ///< PCA Channel 3 Capture Module High Byte
SFR (PCA0CPH4,    0xFE); ///< PCA Channel 4 Capture Module High Byte
SFR (PCA0CPH5,    0xD3); ///< PCA Channel 5 Capture Module High Byte
SFR (PCA0CPL0,    0xFB); ///< PCA Channel 0 Capture Module Low Byte 
SFR (PCA0CPL1,    0xE9); ///< PCA Channel 1 Capture Module Low Byte 
SFR (PCA0CPL2,    0xEB); ///< PCA Channel 2 Capture Module Low Byte 
SFR (PCA0CPL3,    0xED); ///< PCA Channel 3 Capture Module Low Byte 
SFR (PCA0CPL4,    0xFD); ///< PCA Channel 4 Capture Module Low Byte 
SFR (PCA0CPL5,    0xD2); ///< PCA Channel 5 Capture Module Low Byte 
SFR (PCA0CPM0,    0xDA); ///< PCA Channel 0 Capture/Compare Mode 0  
SFR (PCA0CPM1,    0xDB); ///< PCA Channel 1 Capture/Compare Mode    
SFR (PCA0CPM2,    0xDC); ///< PCA Channel 2 Capture/Compare Mode    
SFR (PCA0CPM3,    0xDD); ///< PCA Channel 3 Capture/Compare Mode    
SFR (PCA0CPM4,    0xDE); ///< PCA Channel 4 Capture/Compare Mode    
SFR (PCA0CPM5,    0xCE); ///< PCA Channel 5 Capture/Compare Mode    
SFR (PCA0H,       0xFA); ///< PCA Counter/Timer High Byte           
SFR (PCA0L,       0xF9); ///< PCA Counter/Timer Low Byte            
SFR (PCA0MD,      0xD9); ///< PCA Mode                              
SFR (PCA0PWM,     0xDF); ///< PCA PWM Configuration                 
SFR (PCLKACT,     0xF5); ///< Peripheral Active Clock Enable        
SFR (PCLKEN,      0xFE); ///< Low Power Peripheral Clock Enable     
SFR (PCON,        0x87); ///< Power Control                         
SFR (PMU0CF,      0xB5); ///< Power Management Unit Configuration   
SFR (PMU0FL,      0xB6); ///< Power Management Unit Flag            
SFR (PMU0MD,      0xB3); ///< Power Management Unit Mode            
SFR (PSBANK,      0x84); ///< Program Space Bank Select             
SFR (PSCTL,       0x8F); ///< Program Store Control                 
SFR (PSW,         0xD0); ///< Program Status Word                   
SFR (REF0CN,      0xD1); ///< Voltage Reference Control             
SFR (REG0CN,      0xC9); ///< Voltage Regulator Control             
SFR (REVID,       0xEA); ///< Revision Identifcation                
SFR (RSTSRC,      0xEF); ///< Reset Source                          
SFR (RTC0ADR,     0xAC); ///< RTC Address                           
SFR (RTC0DAT,     0xAD); ///< RTC Data                              
SFR (RTC0KEY,     0xAE); ///< RTC Lock and Key                      
SFR (SBUF0,       0x99); ///< UART0 Serial Port Data Buffer         
SFR (SCON0,       0x98); ///< UART0 Serial Port Control             
SFR (SFRLAST,     0x86); ///< SFR Page Last                         
SFR (SFRNEXT,     0x85); ///< SFR Page Next                         
SFR (SFRPAGE,     0xA7); ///< SFR Page                              
SFR (SFRPGCN,     0x8E); ///< SFR Page Control                      
SFR (SMB0ADM,     0xF5); ///< SMBus 0 Slave Address Mask            
SFR (SMB0ADR,     0xF4); ///< SMBus 0 Slave Address                 
SFR (SMB0CF,      0xC1); ///< SMBus 0 Configuration                 
SFR (SMB0CN,      0xC0); ///< SMBus 0 Control                       
SFR (SMB0DAT,     0xC2); ///< SMBus 0 Data                          
SFR (SP,          0x81); ///< Stack Pointer                         
SFR (SPI0CFG,     0xA1); ///< SPI0 Configuration                    
SFR (SPI0CKR,     0xA2); ///< SPI0 Clock Rate                       
SFR (SPI0CN,      0xF8); ///< SPI0 Control                          
SFR (SPI0DAT,     0xA3); ///< SPI0 Data                             
SFR (SPI1CFG,     0xA1); ///< SPI1 Configuration                    
SFR (SPI1CKR,     0xA2); ///< SPI1 Clock Rate                       
SFR (SPI1CN,      0xF8); ///< SPI1 Control                          
SFR (SPI1DAT,     0xA3); ///< SPI1 Data                             
SFR (TCON,        0x88); ///< Timer 0/1 Control                     
SFR (TH0,         0x8C); ///< Timer 0 High Byte                     
SFR (TH1,         0x8D); ///< Timer 1 High Byte                     
SFR (TL0,         0x8A); ///< Timer 0 Low Byte                      
SFR (TL1,         0x8B); ///< Timer 1 Low Byte                      
SFR (TMOD,        0x89); ///< Timer 0/1 Mode                        
SFR (TMR2CN,      0xC8); ///< Timer 2 Control                       
SFR (TMR2H,       0xCD); ///< Timer 2 High Byte                     
SFR (TMR2L,       0xCC); ///< Timer 2 Low Byte                      
SFR (TMR2RLH,     0xCB); ///< Timer 2 Reload High Byte              
SFR (TMR2RLL,     0xCA); ///< Timer 2 Reload Low Byte               
SFR (TMR3CN,      0x91); ///< Timer 3 Control                       
SFR (TMR3H,       0x95); ///< Timer 3 High Byte                     
SFR (TMR3L,       0x94); ///< Timer 3 Low Byte                      
SFR (TMR3RLH,     0x93); ///< Timer 3 Reload High Byte              
SFR (TMR3RLL,     0x92); ///< Timer 3 Reload Low Byte               
SFR (TOFFH,       0xBE); ///< Temperature Sensor Offset High        
SFR (TOFFL,       0xBD); ///< Temperature Sensor Offset Low         
SFR (VDM0CN,      0xFF); ///< VDD Supply Monitor Control            
SFR (XBR0,        0xE1); ///< Port I/O Crossbar 0                   
SFR (XBR1,        0xE2); ///< Port I/O Crossbar 1                   
SFR (XBR2,        0xE3); ///< Port I/O Crossbar 2                   

//------------------------------------------------------------------------------
// 16-bit Register Definitions (may not work on all compilers)
//------------------------------------------------------------------------------
SFR16 (ADC0GT,     0xC3); ///< ADC0 Greater-Than            
SFR16 (ADC0,       0xBD); ///< ADC0 Data Word               
SFR16 (ADC0LT,     0xC5); ///< ADC0 Less-Than               
SFR16 (DMA0NAO,    0xCC); ///< Memory Address Offset        
SFR16 (DMA0NBA,    0xCA); ///< Memory Base Address          
SFR16 (DMA0NSZ,    0xCE); ///< Memory Transfer Size         
SFR16 (DP,         0x82); ///< Data Pointer                 
SFR16 (LCD0CLKDIV, 0xA9); ///< LCD Refresh Rate Prescaler   
SFR16 (PCA0CP0,    0xFB); ///< PCA Channel 0 Capture Module 
SFR16 (PCA0CP1,    0xE9); ///< PCA Channel 1 Capture Module 
SFR16 (PCA0CP2,    0xEB); ///< PCA Channel 2 Capture Module 
SFR16 (PCA0CP3,    0xED); ///< PCA Channel 3 Capture Module 
SFR16 (PCA0CP4,    0xFD); ///< PCA Channel 4 Capture Module 
SFR16 (PCA0CP5,    0xD2); ///< PCA Channel 5 Capture Module 
SFR16 (PCA0,       0xF9); ///< PCA Counter/Timer            
SFR16 (TMR2,       0xCC); ///< Timer 2                      
SFR16 (TMR2RL,     0xCA); ///< Timer 2 Reload               
SFR16 (TMR3,       0x94); ///< Timer 3                      
SFR16 (TMR3RL,     0x92); ///< Timer 3 Reload               
SFR16 (TOFF,       0xBD); ///< Temperature Sensor Offset    

//------------------------------------------------------------------------------
// Indirect Register Definitions
//------------------------------------------------------------------------------
#define ALARM0B0  0x08 ///< RTC Alarm 0 Programmed Value 0      
#define ALARM0B1  0x09 ///< RTC Alarm 0 Programmed Value 1      
#define ALARM0B2  0x0A ///< RTC Alarm 0 Programmed Value 2      
#define ALARM0B3  0x0B ///< RTC Alarm 0 Programmed Value 3      
#define ALARM1B0  0x0C ///< RTC Alarm 1 Programmed Value 0      
#define ALARM1B1  0x0D ///< RTC Alarm 1 Programmed Value 1      
#define ALARM1B2  0x0E ///< RTC Alarm 1 Programmed Value 2      
#define ALARM1B3  0x0F ///< RTC Alarm 1 Programmed Value 3      
#define ALARM2B0  0x10 ///< RTC Alarm 2 Programmed Value 0      
#define ALARM2B1  0x11 ///< RTC Alarm 2 Programmed Value 1      
#define ALARM2B2  0x12 ///< RTC Alarm 2 Programmed Value 2      
#define ALARM2B3  0x13 ///< RTC Alarm 2 Programmed Value 3      
#define CAPTURE0  0x00 ///< RTC Timer Capture 0                 
#define CAPTURE1  0x01 ///< RTC Timer Capture 1                 
#define CAPTURE2  0x02 ///< RTC Timer Capture 2                 
#define CAPTURE3  0x03 ///< RTC Timer Capture 3                 
#define DMA0NAOH0 0x00 ///< Channel 0 Memory Address Offset High
#define DMA0NAOH1 0x01 ///< Channel 1 Memory Address Offset High
#define DMA0NAOH2 0x02 ///< Channel 2 Memory Address Offset High
#define DMA0NAOH3 0x03 ///< Channel 3 Memory Address Offset High
#define DMA0NAOH4 0x04 ///< Channel 4 Memory Address Offset High
#define DMA0NAOH5 0x05 ///< Channel 5 Memory Address Offset High
#define DMA0NAOH6 0x06 ///< Channel 6 Memory Address Offset High
#define DMA0NAOL0 0x00 ///< Channel 0 Memory Address Offset     
#define DMA0NAOL1 0x01 ///< Channel 1 Memory Address Offset     
#define DMA0NAOL2 0x02 ///< Channel 2 Memory Address Offset     
#define DMA0NAOL3 0x03 ///< Channel 3 Memory Address Offset     
#define DMA0NAOL4 0x04 ///< Channel 4 Memory Address Offset     
#define DMA0NAOL5 0x05 ///< Channel 5 Memory Address Offset     
#define DMA0NAOL6 0x06 ///< Channel 6 Memory Address Offset     
#define DMA0NBAH0 0x00 ///< Channel 0 Memory Base Address High  
#define DMA0NBAH1 0x01 ///< Channel 1 Memory Base Address High  
#define DMA0NBAH2 0x02 ///< Channel 2 Memory Base Address High  
#define DMA0NBAH3 0x03 ///< Channel 3 Memory Base Address High  
#define DMA0NBAH4 0x04 ///< Channel 4 Memory Base Address High  
#define DMA0NBAH5 0x05 ///< Channel 5 Memory Base Address High  
#define DMA0NBAH6 0x06 ///< Channel 6 Memory Base Address High  
#define DMA0NBAL0 0x00 ///< Channel 0 Memory Base Address       
#define DMA0NBAL1 0x01 ///< Channel 1 Memory Base Address       
#define DMA0NBAL2 0x02 ///< Channel 2 Memory Base Address       
#define DMA0NBAL3 0x03 ///< Channel 3 Memory Base Address       
#define DMA0NBAL4 0x04 ///< Channel 4 Memory Base Address       
#define DMA0NBAL5 0x05 ///< Channel 5 Memory Base Address       
#define DMA0NBAL6 0x06 ///< Channel 6 Memory Base Address       
#define DMA0NCF0  0x00 ///< DMA0 Channel 0 Configuration        
#define DMA0NCF1  0x01 ///< DMA0 Channel 1 Configuration        
#define DMA0NCF2  0x02 ///< DMA0 Channel 2 Configuration        
#define DMA0NCF3  0x03 ///< DMA0 Channel 3 Configuration        
#define DMA0NCF4  0x04 ///< DMA0 Channel 4 Configuration        
#define DMA0NCF5  0x05 ///< DMA0 Channel 5 Configuration        
#define DMA0NCF6  0x06 ///< DMA0 Channel 6 Configuration        
#define DMA0NSZH0 0x00 ///< Channel 0 Memory Transfer Size High 
#define DMA0NSZH1 0x01 ///< Channel 1 Memory Transfer Size High 
#define DMA0NSZH2 0x02 ///< Channel 2 Memory Transfer Size High 
#define DMA0NSZH3 0x03 ///< Channel 3 Memory Transfer Size High 
#define DMA0NSZH4 0x04 ///< Channel 4 Memory Transfer Size High 
#define DMA0NSZH5 0x05 ///< Channel 5 Memory Transfer Size High 
#define DMA0NSZH6 0x06 ///< Channel 6 Memory Transfer Size High 
#define DMA0NSZL0 0x00 ///< Channel 0 Memory Transfer Size      
#define DMA0NSZL1 0x01 ///< Channel 1 Memory Transfer Size      
#define DMA0NSZL2 0x02 ///< Channel 2 Memory Transfer Size      
#define DMA0NSZL3 0x03 ///< Channel 3 Memory Transfer Size      
#define DMA0NSZL4 0x04 ///< Channel 4 Memory Transfer Size      
#define DMA0NSZL5 0x05 ///< Channel 5 Memory Transfer Size      
#define DMA0NSZL6 0x06 ///< Channel 6 Memory Transfer Size      
#define RTC0CF    0x07 ///< RTC Configuration                   
#define RTC0CN    0x04 ///< RTC Control                         
#define RTC0XCF   0x06 ///< RTC Oscillator Configuration        
#define RTC0XCN   0x05 ///< RTC Oscillator Control              

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
SBIT (ADC0CN_ADBMEN, SFR_ADC0CN, 6); ///< Burst Mode Enable                    
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

// IE (Interrupt Enable)
#define SFR_IE 0xA8
SBIT (IE_EX0,   SFR_IE, 0); ///< External Interrupt 0 Enable
SBIT (IE_ET0,   SFR_IE, 1); ///< Timer 0 Interrupt Enable   
SBIT (IE_EX1,   SFR_IE, 2); ///< External Interrupt 1 Enable
SBIT (IE_ET1,   SFR_IE, 3); ///< Timer 1 Interrupt Enable   
SBIT (IE_ES0,   SFR_IE, 4); ///< UART0 Interrupt Enable     
SBIT (IE_ET2,   SFR_IE, 5); ///< Timer 2 Interrupt Enable   
SBIT (IE_ESPI0, SFR_IE, 6); ///< SPI0 Interrupt Enable      
SBIT (IE_EA,    SFR_IE, 7); ///< All Interrupts Enable      

// IP (Interrupt Priority)
#define SFR_IP 0xB8
SBIT (IP_PX0,   SFR_IP, 0); ///< External Interrupt 0 Priority Control                        
SBIT (IP_PT0,   SFR_IP, 1); ///< Timer 0 Interrupt Priority Control                           
SBIT (IP_PX1,   SFR_IP, 2); ///< External Interrupt 1 Priority Control                        
SBIT (IP_PT1,   SFR_IP, 3); ///< Timer 1 Interrupt Priority Control                           
SBIT (IP_PS0,   SFR_IP, 4); ///< UART0 Interrupt Priority Control                             
SBIT (IP_PT2,   SFR_IP, 5); ///< Timer 2 Interrupt Priority Control                           
SBIT (IP_PSPI0, SFR_IP, 6); ///< Serial Peripheral Interface (SPI0) Interrupt Priority Control

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

// P1 (Port 1 Pin Latch)
#define SFR_P1 0x90
SBIT (P1_B0, SFR_P1, 0); ///< Port 1 Bit 0 Latch
SBIT (P1_B1, SFR_P1, 1); ///< Port 1 Bit 1 Latch
SBIT (P1_B2, SFR_P1, 2); ///< Port 1 Bit 2 Latch
SBIT (P1_B3, SFR_P1, 3); ///< Port 1 Bit 3 Latch
SBIT (P1_B4, SFR_P1, 4); ///< Port 1 Bit 4 Latch
SBIT (P1_B5, SFR_P1, 5); ///< Port 1 Bit 5 Latch
SBIT (P1_B6, SFR_P1, 6); ///< Port 1 Bit 6 Latch
SBIT (P1_B7, SFR_P1, 7); ///< Port 1 Bit 7 Latch

// P2 (Port 2 Pin Latch)
#define SFR_P2 0xA0
SBIT (P2_B0, SFR_P2, 0); ///< Port 2 Bit 0 Latch
SBIT (P2_B1, SFR_P2, 1); ///< Port 2 Bit 1 Latch
SBIT (P2_B2, SFR_P2, 2); ///< Port 2 Bit 2 Latch
SBIT (P2_B3, SFR_P2, 3); ///< Port 2 Bit 3 Latch
SBIT (P2_B4, SFR_P2, 4); ///< Port 2 Bit 4 Latch
SBIT (P2_B5, SFR_P2, 5); ///< Port 2 Bit 5 Latch
SBIT (P2_B6, SFR_P2, 6); ///< Port 2 Bit 6 Latch
SBIT (P2_B7, SFR_P2, 7); ///< Port 2 Bit 7 Latch

// P3 (Port 3 Pin Latch)
#define SFR_P3 0xB0
SBIT (P3_B0, SFR_P3, 0); ///< Port 3 Bit 0 Latch
SBIT (P3_B1, SFR_P3, 1); ///< Port 3 Bit 1 Latch
SBIT (P3_B2, SFR_P3, 2); ///< Port 3 Bit 2 Latch
SBIT (P3_B3, SFR_P3, 3); ///< Port 3 Bit 3 Latch
SBIT (P3_B4, SFR_P3, 4); ///< Port 3 Bit 4 Latch
SBIT (P3_B5, SFR_P3, 5); ///< Port 3 Bit 5 Latch
SBIT (P3_B6, SFR_P3, 6); ///< Port 3 Bit 6 Latch
SBIT (P3_B7, SFR_P3, 7); ///< Port 3 Bit 7 Latch

// PCA0CN (PCA Control)
#define SFR_PCA0CN 0xD8
SBIT (PCA0CN_CCF0, SFR_PCA0CN, 0); ///< PCA Module 0 Capture/Compare Flag
SBIT (PCA0CN_CCF1, SFR_PCA0CN, 1); ///< PCA Module 1 Capture/Compare Flag
SBIT (PCA0CN_CCF2, SFR_PCA0CN, 2); ///< PCA Module 2 Capture/Compare Flag
SBIT (PCA0CN_CCF3, SFR_PCA0CN, 3); ///< PCA Module 3 Capture/Compare Flag
SBIT (PCA0CN_CCF4, SFR_PCA0CN, 4); ///< PCA Module 4 Capture/Compare Flag
SBIT (PCA0CN_CCF5, SFR_PCA0CN, 5); ///< PCA Module 5 Capture/Compare Flag
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

// SPI0CN (SPI0 Control)
#define SFR_SPI0CN 0xF8
SBIT (SPI0CN_SPIEN,  SFR_SPI0CN, 0); ///< SPI0 Enable            
SBIT (SPI0CN_TXBMT,  SFR_SPI0CN, 1); ///< Transmit Buffer Empty  
SBIT (SPI0CN_NSSMD0, SFR_SPI0CN, 2); ///< Slave Select Mode Bit 0
SBIT (SPI0CN_NSSMD1, SFR_SPI0CN, 3); ///< Slave Select Mode Bit 1
SBIT (SPI0CN_RXOVRN, SFR_SPI0CN, 4); ///< Receive Overrun Flag   
SBIT (SPI0CN_MODF,   SFR_SPI0CN, 5); ///< Mode Fault Flag        
SBIT (SPI0CN_WCOL,   SFR_SPI0CN, 6); ///< Write Collision Flag   
SBIT (SPI0CN_SPIF,   SFR_SPI0CN, 7); ///< SPI0 Interrupt Flag    

// SPI1CN (SPI1 Control)
#define SFR_SPI1CN 0xF8
SBIT (SPI1CN_SPIEN,  SFR_SPI1CN, 0); ///< SPI1 Enable            
SBIT (SPI1CN_TXBMT,  SFR_SPI1CN, 1); ///< Transmit Buffer Empty  
SBIT (SPI1CN_NSSMD0, SFR_SPI1CN, 2); ///< Slave Select Mode Bit 0
SBIT (SPI1CN_NSSMD1, SFR_SPI1CN, 3); ///< Slave Select Mode Bit 1
SBIT (SPI1CN_RXOVRN, SFR_SPI1CN, 4); ///< Receive Overrun Flag   
SBIT (SPI1CN_MODF,   SFR_SPI1CN, 5); ///< Mode Fault Flag        
SBIT (SPI1CN_WCOL,   SFR_SPI1CN, 6); ///< Write Collision Flag   
SBIT (SPI1CN_SPIF,   SFR_SPI1CN, 7); ///< SPI1 Interrupt Flag    

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
SBIT (TMR2CN_T2XCLK0, SFR_TMR2CN, 0); ///< Timer 2 External Clock Select Bit 0
SBIT (TMR2CN_T2XCLK1, SFR_TMR2CN, 1); ///< Timer 2 External Clock Select Bit 1
SBIT (TMR2CN_TR2,     SFR_TMR2CN, 2); ///< Timer 2 Run Control                
SBIT (TMR2CN_T2SPLIT, SFR_TMR2CN, 3); ///< Timer 2 Split Mode Enable          
SBIT (TMR2CN_TF2CEN,  SFR_TMR2CN, 4); ///< Timer 2 Capture Enable             
SBIT (TMR2CN_TF2LEN,  SFR_TMR2CN, 5); ///< Timer 2 Low Byte Interrupt Enable  
SBIT (TMR2CN_TF2L,    SFR_TMR2CN, 6); ///< Timer 2 Low Byte Overflow Flag     
SBIT (TMR2CN_TF2H,    SFR_TMR2CN, 7); ///< Timer 2 High Byte Overflow Flag    

//------------------------------------------------------------------------------
// Interrupt Definitions
//------------------------------------------------------------------------------
#define INT0_IRQn      0  ///< External Interrupt 0                 
#define TIMER0_IRQn    1  ///< Timer 0 Overflow                     
#define INT1_IRQn      2  ///< External Interrupt 1                 
#define TIMER1_IRQn    3  ///< Timer 1 Overflow                     
#define UART0_IRQn     4  ///< UART 0                               
#define TIMER2_IRQn    5  ///< Timer 2 Overflow                     
#define SPI0_IRQn      6  ///< SPI0                                 
#define SMBUS0_IRQn    7  ///< SMBus 0                              
#define RTC0ALARM_IRQn 8  ///< RTC0 Alarm                           
#define ADC0WC_IRQn    9  ///< ADC0 Window Compare                  
#define ADC0EOC_IRQn   10 ///< ADC0 End of Conversion               
#define PCA0_IRQn      11 ///< PCA0                                 
#define CMP0_IRQn      12 ///< Comparator 0                         
#define CMP1_IRQn      13 ///< Comparator 1                         
#define TIMER3_IRQn    14 ///< Timer 3 Overflow                     
#define VDDMON_IRQn    15 ///< VBAT/VDD Supply Monitor Early Warning
#define PMATCH_IRQn    16 ///< Port Match                           
#define RTC0FAIL_IRQn  17 ///< RTC0 Oscillator Fail                 
#define SPI1_IRQn      18 ///< SPI1                                 
#define PC0_IRQn       19 ///< Pulse Counter                        
#define DMA0_IRQn      20 ///< DMA0                                 
#define ENCDEC0_IRQn   21 ///< Encoder / Decoder                    
#define AES0_IRQn      22 ///< AES0                                 

//------------------------------------------------------------------------------
// SFR Page Definitions
//------------------------------------------------------------------------------
#define LEGACY_PAGE 0x00 ///< Legacy SFR Page                           
#define AES0_PAGE   0x02 ///<                                           
#define CRC1_PAGE   0x02 ///<                                           
#define DMA0_PAGE   0x02 ///<                                           
#define DPPE_PAGE   0x02 ///< Data Packet Processing Engine (DPPE) Page 
#define ENC0_PAGE   0x02 ///< Encoder / Decoder Page                    
#define LCD0_PAGE   0x02 ///<                                           
#define SPI1_PAGE   0x02 ///<                                           
#define CONFIG_PAGE 0x0F ///< System and Port Configuration Page        
#define CRC0_PAGE   0x0F ///<                                           
#define TOFF_PAGE   0x0F ///< Temperature Sensor Calibration Offset Page

//-----------------------------------------------------------------------------
// SDCC PDATA External Memory Paging Support
//-----------------------------------------------------------------------------

#if defined SDCC

SFR(_XPAGE, 0xAA); // Point to the EMI0CN register

#endif

#endif // SI_C8051F960_DEFS_H
//-eof--------------------------------------------------------------------------

