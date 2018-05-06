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

#ifndef SI_C8051F970_DEFS_H
#define SI_C8051F970_DEFS_H

#include <compiler_defs.h>

//-----------------------------------------------------------------------------
// Register Definitions
//-----------------------------------------------------------------------------
SFR (ACC,      0xE0); ///< Accumulator                                      
SFR (ADC0AC,   0xBA); ///< ADC0 Accumulator Configuration                   
SFR (ADC0CF,   0x97); ///< ADC0 Configuration                               
SFR (ADC0CN,   0xE8); ///< ADC0 Control                                     
SFR (ADC0GTH,  0xC4); ///< ADC0 Greater-Than High Byte                      
SFR (ADC0GTL,  0xC3); ///< ADC0 Greater-Than Low Byte                       
SFR (ADC0H,    0xD3); ///< ADC0 Data Word High Byte                         
SFR (ADC0L,    0xD2); ///< ADC0 Data Word Low Byte                          
SFR (ADC0LTH,  0xC6); ///< ADC0 Less-Than High Byte                         
SFR (ADC0LTL,  0xC5); ///< ADC0 Less-Than Low Byte                          
SFR (ADC0MX,   0xD4); ///< ADC0 Multiplexer Selection                       
SFR (ADC0PWR,  0xBB); ///< ADC0 Power Control                               
SFR (ADC0TK,   0xBC); ///< ADC0 Burst Mode Track Time                       
SFR (AMUX0P0,  0x9A); ///< Port 0 Analog Multiplexer Control                
SFR (AMUX0P1,  0x9B); ///< Port 1 Analog Multiplexer Control                
SFR (AMUX0P2,  0x9C); ///< Port 2 Analog Multiplexer Control                
SFR (AMUX0P3,  0xA4); ///< Port 3 Analog Multiplexer Control                
SFR (AMUX0P4,  0xA5); ///< Port 4 Analog Multiplexer Control                
SFR (AMUX0P5,  0xA6); ///< Port 5 Analog Multiplexer Control                
SFR (B,        0xF0); ///< B Register                                       
SFR (CKCON,    0x8E); ///< Clock Control                                    
SFR (CLKMODE,  0xF7); ///< Clock Mode                                       
SFR (CLKSEL,   0xA9); ///< Clock Select                                     
SFR (CRC0AUTO, 0x9E); ///< CRC0 Automatic Control                           
SFR (CRC0CN,   0x84); ///< CRC0 Control                                     
SFR (CRC0CNT,  0x9D); ///< CRC0 Automatic Flash Sector Count                
SFR (CRC0DAT,  0x86); ///< CRC0 Data Output                                 
SFR (CRC0FLIP, 0x9F); ///< CRC0 Bit Flip                                    
SFR (CRC0IN,   0x85); ///< CRC0 Data Input                                  
SFR (CS0CF,    0xAA); ///< Capacitive Sense 0 Configuration                 
SFR (CS0CN,    0xB0); ///< Capacitive Sense 0 Control                       
SFR (CS0DH,    0xEE); ///< Capacitive Sense 0 Data High Byte                
SFR (CS0DL,    0xED); ///< Capacitive Sense 0 Data Low Byte                 
SFR (CS0MD1,   0xBD); ///< Capacitive Sense 0 Mode 1                        
SFR (CS0MD2,   0xBE); ///< Capacitive Sense 0 Mode 2                        
SFR (CS0MD3,   0xBF); ///< Capacitive Sense 0 Mode 3                        
SFR (CS0MX,    0xAB); ///< Capacitive Sense 0 Mux Channel Select            
SFR (CS0PM,    0x96); ///< Capacitive Sense 0 Pin Monitor                   
SFR (CS0SE,    0xDE); ///< Capacitive Sense 0 Auto Scan End Channel         
SFR (CS0SS,    0xDD); ///< Capacitive Sense 0 Auto Scan Start Channel       
SFR (CS0THH,   0xFE); ///< Capacitive Sense 0 Comparator Threshold High Byte
SFR (CS0THL,   0xFD); ///< Capacitive Sense 0 Comparator Threshold Low Byte 
SFR (DEVICEID, 0xE1); ///< Device Identification                            
SFR (DMA0BUSY, 0x91); ///< DMA0 Busy                                        
SFR (DMA0EN,   0x92); ///< DMA0 Channel Enable                              
SFR (DMA0INT,  0xE8); ///< DMA0 Full-Length Interrupt Flags                 
SFR (DMA0MINT, 0x88); ///< DMA0 Mid-Point Interrupt Flags                   
SFR (DMA0NAOH, 0xCC); ///< Memory Address Offset High                       
SFR (DMA0NAOL, 0xCB); ///< Memory Address Offset Low                        
SFR (DMA0NBAH, 0xCA); ///< Memory Base Address High                         
SFR (DMA0NBAL, 0xC9); ///< Memory Base Address Low                          
SFR (DMA0NCF,  0xD8); ///< DMA0 Channel Configuration                       
SFR (DMA0NSZH, 0xCE); ///< Memory Transfer Size High                        
SFR (DMA0NSZL, 0xCD); ///< Memory Transfer Size Low                         
SFR (DMA0SEL,  0x94); ///< DMA0 Channel Select                              
SFR (DPH,      0x83); ///< Data Pointer High                                
SFR (DPL,      0x82); ///< Data Pointer Low                                 
SFR (EIE1,     0xE6); ///< Extended Interrupt Enable 1                      
SFR (EIE2,     0xE7); ///< Extended Interrupt Enable 2                      
SFR (EIP1,     0xF6); ///< Extended Interrupt Priority 1                    
SFR (EIP2,     0xF7); ///< Extended Interrupt Priority 2                    
SFR (EMI0CN,   0xB9); ///< External Memory Interface Control                
SFR (FLKEY,    0xB7); ///< Flash Lock and Key                               
SFR (FLSCL,    0xB6); ///< Flash Scale                                      
SFR (FLWR,     0xE5); ///< Flash Write Only                                 
SFR (I2C0CN,   0xAC); ///< I2C0 Control                                     
SFR (I2C0DIN,  0xA5); ///< I2C0 Received Data                               
SFR (I2C0DOUT, 0xA4); ///< I2C0 Transmit Data                               
SFR (I2C0SLAD, 0xAD); ///< I2C0 Slave Address                               
SFR (I2C0STAT, 0xF8); ///< I2C0 Status                                      
SFR (IE,       0xA8); ///< Interrupt Enable                                 
SFR (IP,       0xB8); ///< Interrupt Priority                               
SFR (IT01CF,   0xDE); ///< INT0/INT1 Configuration                          
SFR (MAC0ACC0, 0xD2); ///< Accumulator Byte 0                               
SFR (MAC0ACC1, 0xD3); ///< Accumulator Byte 1                               
SFR (MAC0ACC2, 0xD4); ///< Accumulator Byte 2                               
SFR (MAC0ACC3, 0xD5); ///< Accumulator Byte 3                               
SFR (MAC0AH,   0xAB); ///< Operand A High Byte                              
SFR (MAC0AL,   0xAA); ///< Operand A Low Byte                               
SFR (MAC0BH,   0xAF); ///< Operand B High Byte                              
SFR (MAC0BL,   0xAE); ///< Operand B Low Byte                               
SFR (MAC0CF0,  0xC0); ///< MAC0 Configuration 0                             
SFR (MAC0CF1,  0xC4); ///< MAC0 Configuration 1                             
SFR (MAC0CF2,  0xC5); ///< MAC0 Configuration 2                             
SFR (MAC0INTE, 0xC1); ///< MAC0 Interrupt Enable                            
SFR (MAC0ITER, 0xD7); ///< Iteration Counter                                
SFR (MAC0OVF,  0xD6); ///< Accumulator Overflow Byte                        
SFR (MAC0STA,  0xCF); ///< MAC0 Status                                      
SFR (OSCICL,   0xAF); ///< High Frequency Oscillator Calibration            
SFR (OSCICN,   0xB2); ///< High Frequency Oscillator Control                
SFR (OSCXCN,   0xB1); ///< External Oscillator Control                      
SFR (P0,       0x80); ///< Port 0 Pin Latch                                 
SFR (P0DRV,    0x99); ///< Port 0 Drive Strength                            
SFR (P0MASK,   0x8B); ///< Port 0 Mask                                      
SFR (P0MAT,    0xF4); ///< Port 0 Match                                     
SFR (P0MDIN,   0xEC); ///< Port 0 Input Mode                                
SFR (P0MDOUT,  0xD9); ///< Port 0 Output Mode                               
SFR (P0SKIP,   0xB6); ///< Port 0 Skip                                      
SFR (P1,       0x90); ///< Port 1 Pin Latch                                 
SFR (P1DRV,    0x9A); ///< Port 1 Drive Strength                            
SFR (P1MASK,   0x8C); ///< Port 1 Mask                                      
SFR (P1MAT,    0xF5); ///< Port 1 Match                                     
SFR (P1MDIN,   0xED); ///< Port 1 Input Mode                                
SFR (P1MDOUT,  0xDC); ///< Port 1 Output Mode                               
SFR (P1SKIP,   0xC6); ///< Port 1 Skip                                      
SFR (P2,       0xA0); ///< Port 2 Pin Latch                                 
SFR (P2DRV,    0x9B); ///< Port 2 Drive Strength                            
SFR (P2MASK,   0x84); ///< Port 2 Mask                                      
SFR (P2MAT,    0x85); ///< Port 2 Match                                     
SFR (P2MDIN,   0xEE); ///< Port 2 Input Mode                                
SFR (P2MDOUT,  0xDD); ///< Port 2 Output Mode                               
SFR (P2SKIP,   0xC7); ///< Port 2 Skip                                      
SFR (P3,       0xE1); ///< Port 3 Pin Latch                                 
SFR (P3DRV,    0x9C); ///< Port 3 Drive Strength                            
SFR (P3MDIN,   0xEF); ///< Port 3 Input Mode                                
SFR (P3MDOUT,  0xDF); ///< Port 3 Output Mode                               
SFR (P4,       0xE2); ///< Port 4 Pin Latch                                 
SFR (P4DRV,    0xB9); ///< Port 4 Drive Strength                            
SFR (P4MDIN,   0xF1); ///< Port 4 Input Mode                                
SFR (P4MDOUT,  0xC3); ///< Port 4 Output Mode                               
SFR (P5,       0xE3); ///< Port 5 Pin Latch                                 
SFR (P5DRV,    0x9D); ///< Port 5 Drive Strength                            
SFR (P5MDIN,   0xF2); ///< Port 5 Input Mode                                
SFR (P5MDOUT,  0xFF); ///< Port 5 Output Mode                               
SFR (P6,       0xE4); ///< Port 6 Pin Latch                                 
SFR (P6MDIN,   0x97); ///< Port 6 Input Mode                                
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
SFR (PCA0PWM,  0xDF); ///< PCA PWM Configuration                            
SFR (PCLKEN,   0xF6); ///< Low Power Peripheral Clock Enable                
SFR (PCON,     0x87); ///< Power Control                                    
SFR (PMU0CF,   0xB5); ///< Power Management Unit Configuration              
SFR (PMU0FL,   0xCE); ///< Power Management Unit Flag                       
SFR (PMU0MD,   0xCF); ///< Power Management Unit Mode                       
SFR (PSCTL,    0x8F); ///< Program Store Control                            
SFR (PSW,      0xD0); ///< Program Status Word                              
SFR (REF0CN,   0xD1); ///< Voltage Reference Control                        
SFR (REG0CN,   0xC9); ///< Voltage Regulator Control                        
SFR (REVID,    0xE2); ///< Revision Identifcation                           
SFR (RSTSRC,   0xEF); ///< Reset Source                                     
SFR (RTC0ADR,  0xAC); ///< RTC Address                                      
SFR (RTC0DAT,  0xAD); ///< RTC Data                                         
SFR (SBUF0,    0x99); ///< UART0 Serial Port Data Buffer                    
SFR (SCON0,    0x98); ///< UART0 Serial Port Control                        
SFR (SFRLAST,  0xB3); ///< SFR Page Last                                    
SFR (SFRNEXT,  0xF3); ///< SFR Page Next                                    
SFR (SFRPAGE,  0xA7); ///< SFR Page                                         
SFR (SFRPGCN,  0xA6); ///< SFR Page Control                                 
SFR (SMB0ADM,  0xF5); ///< SMBus 0 Slave Address Mask                       
SFR (SMB0ADR,  0xF4); ///< SMBus 0 Slave Address                            
SFR (SMB0CF,   0xC1); ///< SMBus 0 Configuration                            
SFR (SMB0CN,   0xC0); ///< SMBus 0 Control                                  
SFR (SMB0DAT,  0xC2); ///< SMBus 0 Data                                     
SFR (SP,       0x81); ///< Stack Pointer                                    
SFR (SPI0CFG,  0xA1); ///< SPI0 Configuration                               
SFR (SPI0CKR,  0xA2); ///< SPI0 Clock Rate                                  
SFR (SPI0CN,   0xF8); ///< SPI0 Control                                     
SFR (SPI0DAT,  0xA3); ///< SPI0 Data                                        
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
SFR (TMR3CN,   0x91); ///< Timer 3 Control                                  
SFR (TMR3H,    0x95); ///< Timer 3 High Byte                                
SFR (TMR3L,    0x94); ///< Timer 3 Low Byte                                 
SFR (TMR3RLH,  0x93); ///< Timer 3 Reload High Byte                         
SFR (TMR3RLL,  0x92); ///< Timer 3 Reload Low Byte                          
SFR (TOFFH,    0x8E); ///< Temperature Sensor Offset High                   
SFR (TOFFL,    0x8D); ///< Temperature Sensor Offset Low                    
SFR (VDM0CN,   0xFF); ///< VDD Supply Monitor Control                       
SFR (XBR0,     0x95); ///< Port I/O Crossbar 0                              
SFR (XBR1,     0x96); ///< Port I/O Crossbar 1                              

//------------------------------------------------------------------------------
// 16-bit Register Definitions (may not work on all compilers)
//------------------------------------------------------------------------------
SFR16 (ADC0GT,  0xC3); ///< ADC0 Greater-Than                       
SFR16 (ADC0,    0xD2); ///< ADC0 Data Word                          
SFR16 (ADC0LT,  0xC5); ///< ADC0 Less-Than                          
SFR16 (CS0D,    0xED); ///< Capacitive Sense 0 Data                 
SFR16 (CS0TH,   0xFD); ///< Capacitive Sense 0 Comparator Threshold 
SFR16 (DMA0NAO, 0xCB); ///< Memory Address Offset                   
SFR16 (DMA0NBA, 0xC9); ///< Memory Base Address                     
SFR16 (DMA0NSZ, 0xCD); ///< Memory Transfer Size                    
SFR16 (DP,      0x82); ///< Data Pointer                            
SFR16 (MAC0A,   0xAA); ///< Operand A                               
SFR16 (MAC0B,   0xAE); ///< Operand B                               
SFR16 (PCA0CP0, 0xFB); ///< PCA Channel 0 Capture Module            
SFR16 (PCA0CP1, 0xE9); ///< PCA Channel 1 Capture Module            
SFR16 (PCA0CP2, 0xEB); ///< PCA Channel 2 Capture Module            
SFR16 (PCA0,    0xF9); ///< PCA Counter/Timer                       
SFR16 (TMR2,    0xCC); ///< Timer 2                                 
SFR16 (TMR2RL,  0xCA); ///< Timer 2 Reload                          
SFR16 (TMR3,    0x94); ///< Timer 3                                 
SFR16 (TMR3RL,  0x92); ///< Timer 3 Reload                          
SFR16 (TOFF,    0x8D); ///< Temperature Sensor Offset               

//------------------------------------------------------------------------------
// Indirect Register Definitions
//------------------------------------------------------------------------------
#define ALARM0    0x08 ///< RTC Alarm Programmed Value 0        
#define ALARM1    0x09 ///< RTC Alarm Programmed Value 1        
#define ALARM2    0x0A ///< RTC Alarm Programmed Value 2        
#define ALARM3    0x0B ///< RTC Alarm Programmed Value 3        
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

// CS0CN (Capacitive Sense 0 Control)
#define SFR_CS0CN 0xB0
SBIT (CS0CN_CSCMPF,  SFR_CS0CN, 0); ///< CS0 Digital Comparator Interrupt Flag
SBIT (CS0CN_CSPME,   SFR_CS0CN, 1); ///< CS0 Pin Monitor Event                
SBIT (CS0CN_CSCMPEN, SFR_CS0CN, 3); ///< CS0 Digital Comparator Enable        
SBIT (CS0CN_CSBUSY,  SFR_CS0CN, 4); ///< CS0 Busy                             
SBIT (CS0CN_CSINT,   SFR_CS0CN, 5); ///< CS0 Interrupt Flag                   
SBIT (CS0CN_CSEOS,   SFR_CS0CN, 6); ///< CS0 End of Scan Interrupt Flag       
SBIT (CS0CN_CSEN,    SFR_CS0CN, 7); ///< CS0 Enable                           

// DMA0INT (DMA0 Full-Length Interrupt Flags)
#define SFR_DMA0INT 0xE8
SBIT (DMA0INT_CH0I, SFR_DMA0INT, 0); ///< Channel 0 Full-Length Interrupt Flag
SBIT (DMA0INT_CH1I, SFR_DMA0INT, 1); ///< Channel 1 Full-Length Interrupt Flag
SBIT (DMA0INT_CH2I, SFR_DMA0INT, 2); ///< Channel 2 Full-Length Interrupt Flag
SBIT (DMA0INT_CH3I, SFR_DMA0INT, 3); ///< Channel 3 Full-Length Interrupt Flag
SBIT (DMA0INT_CH4I, SFR_DMA0INT, 4); ///< Channel 4 Full-Length Interrupt Flag
SBIT (DMA0INT_CH5I, SFR_DMA0INT, 5); ///< Channel 5 Full-Length Interrupt Flag
SBIT (DMA0INT_CH6I, SFR_DMA0INT, 6); ///< Channel 6 Full-Length Interrupt Flag

// DMA0MINT (DMA0 Mid-Point Interrupt Flags)
#define SFR_DMA0MINT 0x88
SBIT (DMA0MINT_CH0MI, SFR_DMA0MINT, 0); ///< Channel 0 Mid-Point Interrupt Flag
SBIT (DMA0MINT_CH1MI, SFR_DMA0MINT, 1); ///< Channel 1 Mid-Point Interrupt Flag
SBIT (DMA0MINT_CH2MI, SFR_DMA0MINT, 2); ///< Channel 2 Mid-Point Interrupt Flag
SBIT (DMA0MINT_CH3MI, SFR_DMA0MINT, 3); ///< Channel 3 Mid-Point Interrupt Flag
SBIT (DMA0MINT_CH4MI, SFR_DMA0MINT, 4); ///< Channel 4 Mid-Point Interrupt Flag
SBIT (DMA0MINT_CH5MI, SFR_DMA0MINT, 5); ///< Channel 5 Mid-Point Interrupt Flag
SBIT (DMA0MINT_CH6MI, SFR_DMA0MINT, 6); ///< Channel 6 Mid-Point Interrupt Flag

// DMA0NCF (DMA0 Channel Configuration)
#define SFR_DMA0NCF 0xD8
SBIT (DMA0NCF_PERIPH0, SFR_DMA0NCF, 0); ///< Peripheral Transfer Select Bit 0
SBIT (DMA0NCF_PERIPH1, SFR_DMA0NCF, 1); ///< Peripheral Transfer Select Bit 1
SBIT (DMA0NCF_PERIPH2, SFR_DMA0NCF, 2); ///< Peripheral Transfer Select Bit 2
SBIT (DMA0NCF_ENDIAN,  SFR_DMA0NCF, 4); ///< Data Transfer Endianness        
SBIT (DMA0NCF_STALL,   SFR_DMA0NCF, 5); ///< Channel Stall                   
SBIT (DMA0NCF_MIEN,    SFR_DMA0NCF, 6); ///< Mid-Point Interrupt Enable      
SBIT (DMA0NCF_IEN,     SFR_DMA0NCF, 7); ///< Full-Length Interrupt Enable    

// I2C0STAT (I2C0 Status)
#define SFR_I2C0STAT 0xF8
SBIT (I2C0STAT_RD,      SFR_I2C0STAT, 0); ///< I2C Read       
SBIT (I2C0STAT_WR,      SFR_I2C0STAT, 1); ///< I2C Write      
SBIT (I2C0STAT_STOP,    SFR_I2C0STAT, 2); ///< Stop           
SBIT (I2C0STAT_START,   SFR_I2C0STAT, 3); ///< Start          
SBIT (I2C0STAT_NACK,    SFR_I2C0STAT, 4); ///< NACK           
SBIT (I2C0STAT_I2C0INT, SFR_I2C0STAT, 5); ///< I2C Interrupt  
SBIT (I2C0STAT_ACTIVE,  SFR_I2C0STAT, 6); ///< Bus Active     
SBIT (I2C0STAT_HSMODE,  SFR_I2C0STAT, 7); ///< High Speed Mode

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

// MAC0CF0 (MAC0 Configuration 0)
#define SFR_MAC0CF0 0xC0
SBIT (MAC0CF0_ANEGATE,   SFR_MAC0CF0, 0); ///< Negate A input             
SBIT (MAC0CF0_BNEGATE,   SFR_MAC0CF0, 1); ///< Negate B input             
SBIT (MAC0CF0_ACCNEGATE, SFR_MAC0CF0, 2); ///< Negate Accumulator Input   
SBIT (MAC0CF0_ACCMD,     SFR_MAC0CF0, 3); ///< Accumulate Mode            
SBIT (MAC0CF0_FRACMD,    SFR_MAC0CF0, 4); ///< Fractional Mode            
SBIT (MAC0CF0_CLRACC,    SFR_MAC0CF0, 5); ///< Clear Accumulator          
SBIT (MAC0CF0_SHIFTDIR,  SFR_MAC0CF0, 6); ///< Accumulator Shift Direction
SBIT (MAC0CF0_SHIFTEN,   SFR_MAC0CF0, 7); ///< Accumulator Shift Control  

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
#define DMA0MID_IRQn   12 ///< DMA0 Midpoint Operation Complete   
#define DMA0FULL_IRQn  13 ///< DMA0 Full-Length Operation Complete
#define TIMER3_IRQn    14 ///< Timer 3 Overflow                   
#define PMATCH_IRQn    16 ///< Port Match                         
#define RTC0FAIL_IRQn  17 ///< RTC0 Oscillator Fail               
#define MAC0_IRQn      18 ///< MAC0                               
#define CS0EOC_IRQn    19 ///< CS0 End of Conversion              
#define CS0DCMP_IRQn   20 ///< CS0 Digital Comparator             
#define CS0EOS_IRQn    21 ///< CS0 End of Scan                    
#define I2C0_IRQn      22 ///< I2C Slave 0                        

//------------------------------------------------------------------------------
// SFR Page Definitions
//------------------------------------------------------------------------------
#define ADC0_PAGE    0x00 ///<                                    
#define AMUX0_PAGE   0x00 ///< Analog Multiplexer Page            
#define CRC0_PAGE    0x00 ///<                                    
#define CS0_PAGE     0x00 ///<                                    
#define LEGACY_PAGE  0x00 ///< Legacy SFR Page                    
#define PCA0_PAGE    0x00 ///<                                    
#define PMU0_PAGE    0x00 ///<                                    
#define RTC0_PAGE    0x00 ///<                                    
#define SMBUS0_PAGE  0x00 ///<                                    
#define SPI0_PAGE    0x00 ///<                                    
#define TIMER01_PAGE 0x00 ///<                                    
#define TIMER2_PAGE  0x00 ///<                                    
#define TIMER3_PAGE  0x00 ///<                                    
#define UART0_PAGE   0x00 ///<                                    
#define CONFIG_PAGE  0x0F ///< System and Port Configuration Page 
#define DMA0_PAGE    0x0F ///<                                    
#define I2C0_PAGE    0x0F ///< I2C Slave 0 Page                   
#define MAC0_PAGE    0x0F ///< Multiply and Accumulate (MAC0) Page

//-----------------------------------------------------------------------------
// SDCC PDATA External Memory Paging Support
//-----------------------------------------------------------------------------

#if defined SDCC

SFR(_XPAGE, 0xAA); // Point to the EMI0CN register

#endif

#endif // SI_C8051F970_DEFS_H
//-eof--------------------------------------------------------------------------

