//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  C8051F580_IM
//  C8051F580_IQ
//  C8051F581_IM
//  C8051F581_IQ
//  C8051F582_IM
//  C8051F582_IQ
//  C8051F583_IM
//  C8051F583_IQ
//  C8051F584_IM
//  C8051F584_IQ
//  C8051F585_IM
//  C8051F585_IQ
//  C8051F586_IM
//  C8051F586_IQ
//  C8051F587_IM
//  C8051F587_IQ
//  C8051F588_IM
//  C8051F589_IM
//  C8051F590_IM
//  C8051F591_IM
//  C8051F592_AM

#ifndef SI_C8051F580_SI_DEFS_H
#define SI_C8051F580_SI_DEFS_H

#include <si_toolchain.h>

//-----------------------------------------------------------------------------
// Register Definitions
//-----------------------------------------------------------------------------
SI_SFR (ACC,         0xE0); ///< Accumulator                                 
SI_SFR (ADC0CF,      0xBC); ///< ADC0 Configuration                          
SI_SFR (ADC0CN,      0xE8); ///< ADC0 Control                                
SI_SFR (ADC0GTH,     0xC4); ///< ADC0 Greater-Than High Byte                 
SI_SFR (ADC0GTL,     0xC3); ///< ADC0 Greater-Than Low Byte                  
SI_SFR (ADC0H,       0xBE); ///< ADC0 Data Word High Byte                    
SI_SFR (ADC0L,       0xBD); ///< ADC0 Data Word Low Byte                     
SI_SFR (ADC0LTH,     0xC6); ///< ADC0 Less-Than High Byte                    
SI_SFR (ADC0LTL,     0xC5); ///< ADC0 Less-Than Low Byte                     
SI_SFR (ADC0MX,      0xBB); ///< ADC0 Multiplexer Selection                  
SI_SFR (ADC0TK,      0xBA); ///< ADC0 Burst Mode Track Time                  
SI_SFR (B,           0xF0); ///< B Register                                  
SI_SFR (CAN0BRPE,    0xA1); ///< CAN BRP Extension                           
SI_SFR (CAN0BTH,     0x9B); ///< CAN Bit Timing High                         
SI_SFR (CAN0BTL,     0x9A); ///< CAN Bit Timing Low                          
SI_SFR (CAN0CFG,     0x92); ///< CAN Clock Configuration                     
SI_SFR (CAN0CN,      0xC0); ///< CAN Control                                 
SI_SFR (CAN0ERRH,    0x97); ///< CAN Error Counter High                      
SI_SFR (CAN0ERRL,    0x96); ///< CAN Error Counter Low                       
SI_SFR (CAN0IF1A1H,  0xCB); ///< CAN Interface 1 Arbitration 1 High          
SI_SFR (CAN0IF1A1L,  0xCA); ///< CAN Interface 1 Arbitration 1 Low           
SI_SFR (CAN0IF1A2H,  0xCD); ///< CAN Interface 1 Arbitration 2 High          
SI_SFR (CAN0IF1A2L,  0xCC); ///< CAN Interface 1 Arbitration 2 Low           
SI_SFR (CAN0IF1CMH,  0xC3); ///< CAN Interface 1 Command Mask High           
SI_SFR (CAN0IF1CML,  0xC2); ///< CAN Interface 1 Command Mask Low            
SI_SFR (CAN0IF1CRH,  0xBF); ///< CAN Interface 1 Command Request High        
SI_SFR (CAN0IF1CRL,  0xBE); ///< CAN Interface 1 Command Request Low         
SI_SFR (CAN0IF1DA1H, 0xD5); ///< CAN Interface 1 Data A 1 High               
SI_SFR (CAN0IF1DA1L, 0xD4); ///< CAN Interface 1 Data A 1 Low                
SI_SFR (CAN0IF1DA2H, 0xD7); ///< CAN Interface 1 Data A 2 High               
SI_SFR (CAN0IF1DA2L, 0xD6); ///< CAN Interface 1 Data A 2 Low                
SI_SFR (CAN0IF1DB1H, 0xDB); ///< CAN Interface 1 Data B 1 High               
SI_SFR (CAN0IF1DB1L, 0xDA); ///< CAN Interface 1 Data B 1 Low                
SI_SFR (CAN0IF1DB2H, 0xDD); ///< CAN Interface 1 Data B 2 High               
SI_SFR (CAN0IF1DB2L, 0xDC); ///< CAN Interface 1 Data B 2 Low                
SI_SFR (CAN0IF1M1H,  0xC5); ///< CAN Interface 1 Mask 1 High                 
SI_SFR (CAN0IF1M1L,  0xC4); ///< CAN Interface 1 Mask 1 Low                  
SI_SFR (CAN0IF1M2H,  0xC7); ///< CAN Interface 1 Mask 2 High                 
SI_SFR (CAN0IF1M2L,  0xC6); ///< CAN Interface 1 Mask 2 Low                  
SI_SFR (CAN0IF1MCH,  0xD3); ///< CAN Interface 1 Message Control High        
SI_SFR (CAN0IF1MCL,  0xD2); ///< CAN Interface 1 Message Control Low         
SI_SFR (CAN0IF2A1H,  0xEF); ///< CAN Interface 2 Arbitration 1 High          
SI_SFR (CAN0IF2A1L,  0xEE); ///< CAN Interface 2 Arbitration 1 Low           
SI_SFR (CAN0IF2A2H,  0xF3); ///< CAN Interface 2 Arbitration 2 High          
SI_SFR (CAN0IF2A2L,  0xF2); ///< CAN Interface 2 Arbitration 2 Low           
SI_SFR (CAN0IF2CMH,  0xE3); ///< CAN Interface 2 Command Mask High           
SI_SFR (CAN0IF2CML,  0xE2); ///< CAN Interface 2 Command Mask Low            
SI_SFR (CAN0IF2CRH,  0xDF); ///< CAN Interface 2 Command Request High        
SI_SFR (CAN0IF2CRL,  0xDE); ///< CAN Interface 2 Command Request Low         
SI_SFR (CAN0IF2DA1H, 0xF7); ///< CAN Interface 2 Data A 1 High               
SI_SFR (CAN0IF2DA1L, 0xF6); ///< CAN Interface 2 Data A 1 Low                
SI_SFR (CAN0IF2DA2H, 0xFB); ///< CAN Interface 2 Data A 2 High               
SI_SFR (CAN0IF2DA2L, 0xFA); ///< CAN Interface 2 Data A 2 Low                
SI_SFR (CAN0IF2DB1H, 0xFD); ///< CAN Interface 2 Data B 1 High               
SI_SFR (CAN0IF2DB1L, 0xFC); ///< CAN Interface 2 Data B 1 Low                
SI_SFR (CAN0IF2DB2H, 0xFF); ///< CAN Interface 2 Data B 2 High               
SI_SFR (CAN0IF2DB2L, 0xFE); ///< CAN Interface 2 Data B 2 Low                
SI_SFR (CAN0IF2M1H,  0xEB); ///< CAN Interface 2 Mask 1 High                 
SI_SFR (CAN0IF2M1L,  0xEA); ///< CAN Interface 2 Mask 1 Low                  
SI_SFR (CAN0IF2M2H,  0xED); ///< CAN Interface 2 Mask 2 High                 
SI_SFR (CAN0IF2M2L,  0xEC); ///< CAN Interface 2 Mask 2 Low                  
SI_SFR (CAN0IF2MCH,  0xCF); ///< CAN Interface 2 Message Control High        
SI_SFR (CAN0IF2MCL,  0xCE); ///< CAN Interface 2 Message Control Low         
SI_SFR (CAN0IIDH,    0x9D); ///< CAN Interrupt High                          
SI_SFR (CAN0IIDL,    0x9C); ///< CAN Interrupt Low                           
SI_SFR (CAN0IP1H,    0xAF); ///< CAN Interrupt Pending 1 High                
SI_SFR (CAN0IP1L,    0xAE); ///< CAN Interrupt Pending 1 Low                 
SI_SFR (CAN0IP2H,    0xB3); ///< CAN Interrupt Pending 2 High                
SI_SFR (CAN0IP2L,    0xB2); ///< CAN Interrupt Pending 2 Low                 
SI_SFR (CAN0MV1H,    0xBB); ///< CAN Message Valid 1 High                    
SI_SFR (CAN0MV1L,    0xBA); ///< CAN Message Valid 1 Low                     
SI_SFR (CAN0MV2H,    0xBD); ///< CAN Message Valid 2 High                    
SI_SFR (CAN0MV2L,    0xBC); ///< CAN Message Valid 2 Low                     
SI_SFR (CAN0ND1H,    0xAB); ///< CAN New Data 1 High                         
SI_SFR (CAN0ND1L,    0xAA); ///< CAN New Data 1 Low                          
SI_SFR (CAN0ND2H,    0xAD); ///< CAN New Data 2 High                         
SI_SFR (CAN0ND2L,    0xAC); ///< CAN New Data 2 Low                          
SI_SFR (CAN0STAT,    0x94); ///< CAN Status                                  
SI_SFR (CAN0TR1H,    0xA3); ///< CAN Transmission Request 1 High             
SI_SFR (CAN0TR1L,    0xA2); ///< CAN Transmission Request 1 Low              
SI_SFR (CAN0TR2H,    0xA5); ///< CAN Transmission Request 2 High             
SI_SFR (CAN0TR2L,    0xA4); ///< CAN Transmission Request 2 Low              
SI_SFR (CAN0TST,     0x9E); ///< CAN Test                                    
SI_SFR (CCH0CN,      0xE3); ///< Cache Control                               
SI_SFR (CKCON,       0x8E); ///< Clock Control                               
SI_SFR (CLKMUL,      0x97); ///< Clock Multiplier Control                    
SI_SFR (CLKSEL,      0x8F); ///< Clock Select                                
SI_SFR (CPT0CN,      0x9A); ///< Comparator 0 Control                        
SI_SFR (CPT0MD,      0x9B); ///< Comparator 0 Mode                           
SI_SFR (CPT0MX,      0x9C); ///< Comparator 0 Multiplexer Selection          
SI_SFR (CPT1CN,      0x9D); ///< Comparator 1 Control                        
SI_SFR (CPT1MD,      0x9E); ///< Comparator 1 Mode                           
SI_SFR (CPT1MX,      0x9F); ///< Comparator 1 Multiplexer Selection          
SI_SFR (CPT2CN,      0x9A); ///< Comparator 2 Control                        
SI_SFR (CPT2MD,      0x9B); ///< Comparator 2 Mode                           
SI_SFR (CPT2MX,      0x9C); ///< Comparator 2 Multiplexer Selection          
SI_SFR (DPH,         0x83); ///< Data Pointer High                           
SI_SFR (DPL,         0x82); ///< Data Pointer Low                            
SI_SFR (EIE1,        0xE6); ///< Extended Interrupt Enable 1                 
SI_SFR (EIE2,        0xE7); ///< Extended Interrupt Enable 2                 
SI_SFR (EIP1,        0xF6); ///< Extended Interrupt Priority 1               
SI_SFR (EIP2,        0xF7); ///< Extended Interrupt Priority 2               
SI_SFR (EMI0CF,      0xB2); ///< External Memory Configuration               
SI_SFR (EMI0CN,      0xAA); ///< External Memory Interface Control           
SI_SFR (EMI0TC,      0xAA); ///< External Memory Timing Control              
SI_SFR (FLKEY,       0xB7); ///< Flash Lock and Key                          
SI_SFR (FLSCL,       0xB6); ///< Flash Scale                                 
SI_SFR (IE,          0xA8); ///< Interrupt Enable                            
SI_SFR (IP,          0xB8); ///< Interrupt Priority                          
SI_SFR (IT01CF,      0xE4); ///< INT0/INT1 Configuration                     
SI_SFR (LIN0ADR,     0xD3); ///< LIN0 Indirect Address                       
SI_SFR (LIN0CF,      0xC9); ///< LIN0 Control Mode                           
SI_SFR (LIN0DAT,     0xD2); ///< LIN0 Indirect Data                          
SI_SFR (ONESHOT,     0xBE); ///< Flash Oneshot Period                        
SI_SFR (OSCICN,      0xA1); ///< High Frequency Oscillator Control           
SI_SFR (OSCICRS,     0xA2); ///< High Frequency Oscillator Coarse Calibration
SI_SFR (OSCIFIN,     0x9E); ///< High Frequency Oscillator Fine Calibration  
SI_SFR (OSCXCN,      0x9F); ///< External Oscillator Control                 
SI_SFR (P0,          0x80); ///< Port 0 Pin Latch                            
SI_SFR (P0MASK,      0xF2); ///< Port 0 Mask                                 
SI_SFR (P0MAT,       0xF1); ///< Port 0 Match                                
SI_SFR (P0MDIN,      0xF1); ///< Port 0 Input Mode                           
SI_SFR (P0MDOUT,     0xA4); ///< Port 0 Output Mode                          
SI_SFR (P0SKIP,      0xD4); ///< Port 0 Skip                                 
SI_SFR (P1,          0x90); ///< Port 1 Pin Latch                            
SI_SFR (P1MASK,      0xF4); ///< Port 1 Mask                                 
SI_SFR (P1MAT,       0xF3); ///< Port 1 Match                                
SI_SFR (P1MDIN,      0xF2); ///< Port 1 Input Mode                           
SI_SFR (P1MDOUT,     0xA5); ///< Port 1 Output Mode                          
SI_SFR (P1SKIP,      0xD5); ///< Port 1 Skip                                 
SI_SFR (P2,          0xA0); ///< Port 2 Pin Latch                            
SI_SFR (P2MASK,      0xB2); ///< Port 2 Mask                                 
SI_SFR (P2MAT,       0xB1); ///< Port 2 Match                                
SI_SFR (P2MDIN,      0xF3); ///< Port 2 Input Mode                           
SI_SFR (P2MDOUT,     0xA6); ///< Port 2 Output Mode                          
SI_SFR (P2SKIP,      0xD6); ///< Port 2 Skip                                 
SI_SFR (P3,          0xB0); ///< Port 3 Pin Latch                            
SI_SFR (P3MASK,      0xAF); ///< Port 3 Mask                                 
SI_SFR (P3MAT,       0xAE); ///< Port 3 Match                                
SI_SFR (P3MDIN,      0xF4); ///< Port 3 Input Mode                           
SI_SFR (P3MDOUT,     0xAE); ///< Port 3 Output Mode                          
SI_SFR (P3SKIP,      0xD7); ///< Port 3 Skip                                 
SI_SFR (P4,          0xB5); ///< Port 4 Pin Latch                            
SI_SFR (P4MDOUT,     0xAF); ///< Port 4 Output Mode                          
SI_SFR (PCA0CN,      0xD8); ///< PCA Control                                 
SI_SFR (PCA0CPH0,    0xFC); ///< PCA Channel 0 Capture Module High Byte      
SI_SFR (PCA0CPH1,    0xEA); ///< PCA Channel 1 Capture Module High Byte      
SI_SFR (PCA0CPH2,    0xEC); ///< PCA Channel 2 Capture Module High Byte      
SI_SFR (PCA0CPH3,    0xEE); ///< PCA Channel 3 Capture Module High Byte      
SI_SFR (PCA0CPH4,    0xFE); ///< PCA Channel 4 Capture Module High Byte      
SI_SFR (PCA0CPH5,    0xCF); ///< PCA Channel 5 Capture Module High Byte      
SI_SFR (PCA0CPL0,    0xFB); ///< PCA Channel 0 Capture Module Low Byte       
SI_SFR (PCA0CPL1,    0xE9); ///< PCA Channel 1 Capture Module Low Byte       
SI_SFR (PCA0CPL2,    0xEB); ///< PCA Channel 2 Capture Module Low Byte       
SI_SFR (PCA0CPL3,    0xED); ///< PCA Channel 3 Capture Module Low Byte       
SI_SFR (PCA0CPL4,    0xFD); ///< PCA Channel 4 Capture Module Low Byte       
SI_SFR (PCA0CPL5,    0xCE); ///< PCA Channel 5 Capture Module Low Byte       
SI_SFR (PCA0CPM0,    0xDA); ///< PCA Channel 0 Capture/Compare Mode 0        
SI_SFR (PCA0CPM1,    0xDB); ///< PCA Channel 1 Capture/Compare Mode          
SI_SFR (PCA0CPM2,    0xDC); ///< PCA Channel 2 Capture/Compare Mode          
SI_SFR (PCA0CPM3,    0xDD); ///< PCA Channel 3 Capture/Compare Mode          
SI_SFR (PCA0CPM4,    0xDE); ///< PCA Channel 4 Capture/Compare Mode          
SI_SFR (PCA0CPM5,    0xDF); ///< PCA Channel 5 Capture/Compare Mode          
SI_SFR (PCA0H,       0xFA); ///< PCA Counter/Timer High Byte                 
SI_SFR (PCA0L,       0xF9); ///< PCA Counter/Timer Low Byte                  
SI_SFR (PCA0MD,      0xD9); ///< PCA Mode                                    
SI_SFR (PCA0PWM,     0xD9); ///< PCA PWM Configuration                       
SI_SFR (PCA1CN,      0xD8); ///< PCA Control                                 
SI_SFR (PCA1CPH10,   0xFE); ///< PCA Channel 10 Capture Module High Byte     
SI_SFR (PCA1CPH11,   0xCF); ///< PCA Channel 11 Capture Module High Byte     
SI_SFR (PCA1CPH6,    0xFC); ///< PCA Channel 6 Capture Module High Byte      
SI_SFR (PCA1CPH7,    0xEA); ///< PCA Channel 7 Capture Module High Byte      
SI_SFR (PCA1CPH8,    0xEC); ///< PCA Channel 8 Capture Module High Byte      
SI_SFR (PCA1CPH9,    0xEE); ///< PCA Channel 9 Capture Module High Byte      
SI_SFR (PCA1CPL10,   0xFD); ///< PCA Channel 10 Capture Module Low Byte      
SI_SFR (PCA1CPL11,   0xCE); ///< PCA Channel 11 Capture Module Low Byte      
SI_SFR (PCA1CPL6,    0xFB); ///< PCA Channel 6 Capture Module Low Byte       
SI_SFR (PCA1CPL7,    0xE9); ///< PCA Channel 7 Capture Module Low Byte       
SI_SFR (PCA1CPL8,    0xEB); ///< PCA Channel 8 Capture Module Low Byte       
SI_SFR (PCA1CPL9,    0xED); ///< PCA Channel 9 Capture Module Low Byte       
SI_SFR (PCA1CPM10,   0xDE); ///< PCA Channel 10 Capture/Compare Mode         
SI_SFR (PCA1CPM11,   0xDF); ///< PCA Channel 11 Capture/Compare Mode         
SI_SFR (PCA1CPM6,    0xDA); ///< PCA Channel 6 Capture/Compare Mode          
SI_SFR (PCA1CPM7,    0xDB); ///< PCA Channel 7 Capture/Compare Mode          
SI_SFR (PCA1CPM8,    0xDC); ///< PCA Channel 8 Capture/Compare Mode          
SI_SFR (PCA1CPM9,    0xDD); ///< PCA Channel 9 Capture/Compare Mode          
SI_SFR (PCA1H,       0xFA); ///< PCA Counter/Timer High Byte                 
SI_SFR (PCA1L,       0xF9); ///< PCA Counter/Timer Low Byte                  
SI_SFR (PCA1MD,      0xD9); ///< PCA Mode                                    
SI_SFR (PCA1PWM,     0xDA); ///< PCA PWM Configuration                       
SI_SFR (PCON,        0x87); ///< Power Control                               
SI_SFR (PSBANK,      0xF5); ///< Program Space Bank Select                   
SI_SFR (PSCTL,       0x8F); ///< Program Store Control                       
SI_SFR (PSW,         0xD0); ///< Program Status Word                         
SI_SFR (REF0CN,      0xD1); ///< Voltage Reference Control                   
SI_SFR (REG0CN,      0xC9); ///< Voltage Regulator Control                   
SI_SFR (RSTSRC,      0xEF); ///< Reset Source                                
SI_SFR (SBCON0,      0xAB); ///< UART0 Baud Rate Generator Control           
SI_SFR (SBRLH0,      0xAD); ///< UART0 Baud Rate Generator High Byte         
SI_SFR (SBRLL0,      0xAC); ///< UART0 Baud Rate Generator Low Byte          
SI_SFR (SBUF0,       0x99); ///< UART0 Serial Port Data Buffer               
SI_SFR (SBUF1,       0x99); ///< UART1 Serial Port Data Buffer               
SI_SFR (SCON0,       0x98); ///< UART0 Serial Port Control                   
SI_SFR (SCON1,       0x98); ///< UART1 Serial Port Control                   
SI_SFR (SFRLAST,     0x86); ///< SFR Page Last                               
SI_SFR (SFRNEXT,     0x85); ///< SFR Page Next                               
SI_SFR (SFRPAGE,     0xA7); ///< SFR Page                                    
SI_SFR (SFRPGCN,     0x84); ///< SFR Page Control                            
SI_SFR (SMB0CF,      0xC1); ///< SMBus 0 Configuration                       
SI_SFR (SMB0CN,      0xC0); ///< SMBus 0 Control                             
SI_SFR (SMB0DAT,     0xC2); ///< SMBus 0 Data                                
SI_SFR (SMOD0,       0xA9); ///< UART0 Mode                                  
SI_SFR (SN0,         0xF9); ///< Serial Number Byte 0                        
SI_SFR (SN1,         0xFA); ///< Serial Number Byte 1                        
SI_SFR (SN2,         0xFB); ///< Serial Number Byte 2                        
SI_SFR (SN3,         0xFC); ///< Serial Number Byte 3                        
SI_SFR (SP,          0x81); ///< Stack Pointer                               
SI_SFR (SPI0CFG,     0xA1); ///< SPI0 Configuration                          
SI_SFR (SPI0CKR,     0xA2); ///< SPI0 Clock Rate                             
SI_SFR (SPI0CN,      0xF8); ///< SPI0 Control                                
SI_SFR (SPI0DAT,     0xA3); ///< SPI0 Data                                   
SI_SFR (TCON,        0x88); ///< Timer 0/1 Control                           
SI_SFR (TH0,         0x8C); ///< Timer 0 High Byte                           
SI_SFR (TH1,         0x8D); ///< Timer 1 High Byte                           
SI_SFR (TL0,         0x8A); ///< Timer 0 Low Byte                            
SI_SFR (TL1,         0x8B); ///< Timer 1 Low Byte                            
SI_SFR (TMOD,        0x89); ///< Timer 0/1 Mode                              
SI_SFR (TMR2CN,      0xC8); ///< Timer 2 Control                             
SI_SFR (TMR2H,       0xCD); ///< Timer 2 High Byte                           
SI_SFR (TMR2L,       0xCC); ///< Timer 2 Low Byte                            
SI_SFR (TMR2RLH,     0xCB); ///< Timer 2 Reload High Byte                    
SI_SFR (TMR2RLL,     0xCA); ///< Timer 2 Reload Low Byte                     
SI_SFR (TMR3CN,      0x91); ///< Timer 3 Control                             
SI_SFR (TMR3H,       0x95); ///< Timer 3 High Byte                           
SI_SFR (TMR3L,       0x94); ///< Timer 3 Low Byte                            
SI_SFR (TMR3RLH,     0x93); ///< Timer 3 Reload High Byte                    
SI_SFR (TMR3RLL,     0x92); ///< Timer 3 Reload Low Byte                     
SI_SFR (TMR4CAPH,    0xCB); ///< Timer 4 Reload High Byte                    
SI_SFR (TMR4CAPL,    0xCA); ///< Timer 4 Reload Low Byte                     
SI_SFR (TMR4CF,      0xC9); ///< Timer 4 Config                              
SI_SFR (TMR4CN,      0xC8); ///< Timer 4 Control                             
SI_SFR (TMR4H,       0xCD); ///< Timer 4 High Byte                           
SI_SFR (TMR4L,       0xCC); ///< Timer 4 Low Byte                            
SI_SFR (TMR5CAPH,    0x93); ///< Timer 5 Reload High Byte                    
SI_SFR (TMR5CAPL,    0x92); ///< Timer 5 Reload Low Byte                     
SI_SFR (TMR5CF,      0x96); ///< Timer 5 Config                              
SI_SFR (TMR5CN,      0x91); ///< Timer 5 Control                             
SI_SFR (TMR5H,       0x95); ///< Timer 5 High Byte                           
SI_SFR (TMR5L,       0x94); ///< Timer 5 Low Byte                            
SI_SFR (VDM0CN,      0xFF); ///< VDD Supply Monitor Control                  
SI_SFR (XBR0,        0xE1); ///< Port I/O Crossbar 0                         
SI_SFR (XBR1,        0xE2); ///< Port I/O Crossbar 1                         
SI_SFR (XBR2,        0xC7); ///< Port I/O Crossbar 2                         
SI_SFR (XBR3,        0xC6); ///< Port I/O Crossbar 3                         

//------------------------------------------------------------------------------
// 16-bit Register Definitions (may not work on all compilers)
//------------------------------------------------------------------------------
SI_SFR16 (ADC0GT,     0xC3); ///< ADC0 Greater-Than               
SI_SFR16 (ADC0,       0xBD); ///< ADC0 Data Word                  
SI_SFR16 (ADC0LT,     0xC5); ///< ADC0 Less-Than                  
SI_SFR16 (CAN0BT,     0x9A); ///< CAN Bit Timing                  
SI_SFR16 (CAN0ERR,    0x96); ///< CAN Error Counter               
SI_SFR16 (CAN0IF1A1,  0xCA); ///< CAN Interface 1 Arbitration 1   
SI_SFR16 (CAN0IF1A2,  0xCC); ///< CAN Interface 1 Arbitration 2   
SI_SFR16 (CAN0IF1CM,  0xC2); ///< CAN Interface 1 Command Mask    
SI_SFR16 (CAN0IF1CR,  0xBE); ///< CAN Interface 1 Command Request 
SI_SFR16 (CAN0IF1DA1, 0xD4); ///< CAN Interface 1 Data A 1        
SI_SFR16 (CAN0IF1DA2, 0xD6); ///< CAN Interface 1 Data A 2        
SI_SFR16 (CAN0IF1DB1, 0xDA); ///< CAN Interface 1 Data B 1        
SI_SFR16 (CAN0IF1DB2, 0xDC); ///< CAN Interface 1 Data B 2        
SI_SFR16 (CAN0IF1M1,  0xC4); ///< CAN Interface 1 Mask 1          
SI_SFR16 (CAN0IF1M2,  0xC6); ///< CAN Interface 1 Mask 2          
SI_SFR16 (CAN0IF1MC,  0xD2); ///< CAN Interface 1 Message Control 
SI_SFR16 (CAN0IF2A1,  0xEE); ///< CAN Interface 2 Arbitration 1   
SI_SFR16 (CAN0IF2A2,  0xF2); ///< CAN Interface 2 Arbitration 2   
SI_SFR16 (CAN0IF2CM,  0xE2); ///< CAN Interface 2 Command Mask    
SI_SFR16 (CAN0IF2CR,  0xDE); ///< CAN Interface 2 Command Request 
SI_SFR16 (CAN0IF2DA1, 0xF6); ///< CAN Interface 2 Data A 1        
SI_SFR16 (CAN0IF2DA2, 0xFA); ///< CAN Interface 2 Data A 2        
SI_SFR16 (CAN0IF2DB1, 0xFC); ///< CAN Interface 2 Data B 1        
SI_SFR16 (CAN0IF2DB2, 0xFE); ///< CAN Interface 2 Data B 2        
SI_SFR16 (CAN0IF2M1,  0xEA); ///< CAN Interface 2 Mask 1          
SI_SFR16 (CAN0IF2M2,  0xEC); ///< CAN Interface 2 Mask 2          
SI_SFR16 (CAN0IF2MC,  0xCE); ///< CAN Interface 2 Message Control 
SI_SFR16 (CAN0IID,    0x9C); ///< CAN Interrupt                   
SI_SFR16 (CAN0IP1,    0xAE); ///< CAN Interrupt Pending 1         
SI_SFR16 (CAN0IP2,    0xB2); ///< CAN Interrupt Pending 2         
SI_SFR16 (CAN0MV1,    0xBA); ///< CAN Message Valid 1             
SI_SFR16 (CAN0MV2,    0xBC); ///< CAN Message Valid 2             
SI_SFR16 (CAN0ND1,    0xAA); ///< CAN New Data 1                  
SI_SFR16 (CAN0ND2,    0xAC); ///< CAN New Data 2                  
SI_SFR16 (CAN0TR1,    0xA2); ///< CAN Transmission Request 1      
SI_SFR16 (CAN0TR2,    0xA4); ///< CAN Transmission Request 2      
SI_SFR16 (DP,         0x82); ///< Data Pointer                    
SI_SFR16 (PCA0CP0,    0xFB); ///< PCA Channel 0 Capture Module    
SI_SFR16 (PCA0CP1,    0xE9); ///< PCA Channel 1 Capture Module    
SI_SFR16 (PCA0CP2,    0xEB); ///< PCA Channel 2 Capture Module    
SI_SFR16 (PCA0CP3,    0xED); ///< PCA Channel 3 Capture Module    
SI_SFR16 (PCA0CP4,    0xFD); ///< PCA Channel 4 Capture Module    
SI_SFR16 (PCA0CP5,    0xCE); ///< PCA Channel 5 Capture Module    
SI_SFR16 (PCA0,       0xF9); ///< PCA Counter/Timer               
SI_SFR16 (PCA1CP10,   0xFD); ///< PCA Channel 10 Capture Module   
SI_SFR16 (PCA1CP11,   0xCE); ///< PCA Channel 11 Capture Module   
SI_SFR16 (PCA1CP6,    0xFB); ///< PCA Channel 6 Capture Module    
SI_SFR16 (PCA1CP7,    0xE9); ///< PCA Channel 7 Capture Module    
SI_SFR16 (PCA1CP8,    0xEB); ///< PCA Channel 8 Capture Module    
SI_SFR16 (PCA1CP9,    0xED); ///< PCA Channel 9 Capture Module    
SI_SFR16 (PCA1,       0xF9); ///< PCA Counter/Timer               
SI_SFR16 (SBRL0,      0xAC); ///< UART0 Baud Rate Generator       
SI_SFR16 (TMR2,       0xCC); ///< Timer 2                         
SI_SFR16 (TMR2RL,     0xCA); ///< Timer 2 Reload                  
SI_SFR16 (TMR3,       0x94); ///< Timer 3                         
SI_SFR16 (TMR3RL,     0x92); ///< Timer 3 Reload                  
SI_SFR16 (TMR4CAP,    0xCA); ///< Timer 4 Reload                  
SI_SFR16 (TMR4,       0xCC); ///< Timer 4                         
SI_SFR16 (TMR5CAP,    0x92); ///< Timer 5 Reload                  
SI_SFR16 (TMR5,       0x94); ///< Timer 5                         

//------------------------------------------------------------------------------
// Indirect Register Definitions
//------------------------------------------------------------------------------
#define ADC0GNA  0x08 ///< ADC0 Adjustable Selectable Gain
#define ADC0GNH  0x04 ///< ADC0 Selectable Gain High      
#define ADC0GNL  0x07 ///< ADC0 Selectable Gain           
#define LIN0CTRL 0x08 ///< LIN0 Control                   
#define LIN0DIV  0x0C ///< LIN0 Divider                   
#define LIN0DT1  0x00 ///< LIN0 Data Byte 1               
#define LIN0DT2  0x01 ///< LIN0 Data Byte 2               
#define LIN0DT3  0x02 ///< LIN0 Data Byte 3               
#define LIN0DT4  0x03 ///< LIN0 Data Byte 4               
#define LIN0DT5  0x04 ///< LIN0 Data Byte 5               
#define LIN0DT6  0x05 ///< LIN0 Data Byte 6               
#define LIN0DT7  0x06 ///< LIN0 Data Byte 7               
#define LIN0DT8  0x07 ///< LIN0 Data Byte 8               
#define LIN0ERR  0x0A ///< LIN0 Error                     
#define LIN0ID   0x0E ///< LIN0 Identifier                
#define LIN0MUL  0x0D ///< LIN0 Multiplier                
#define LIN0SIZE 0x0B ///< LIN0 Size                      
#define LIN0ST   0x09 ///< LIN0 Status                    

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
SI_SBIT (ADC0CN_ADCM0,  SFR_ADC0CN, 0); ///< Start of Conversion Mode Select Bit 0
SI_SBIT (ADC0CN_ADCM1,  SFR_ADC0CN, 1); ///< Start of Conversion Mode Select Bit 1
SI_SBIT (ADC0CN_ADLJST, SFR_ADC0CN, 2); ///< Justification Select                 
SI_SBIT (ADC0CN_ADWINT, SFR_ADC0CN, 3); ///< Window Compare Interrupt Flag        
SI_SBIT (ADC0CN_ADBUSY, SFR_ADC0CN, 4); ///< ADC Busy                             
SI_SBIT (ADC0CN_ADINT,  SFR_ADC0CN, 5); ///< Conversion Complete Interrupt Flag   
SI_SBIT (ADC0CN_ADBMEN, SFR_ADC0CN, 6); ///< Burst Mode Enable                    
SI_SBIT (ADC0CN_ADEN,   SFR_ADC0CN, 7); ///< ADC Enable                           

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

// CAN0CN (CAN Control)
#define SFR_CAN0CN 0xC0
SI_SBIT (CAN0CN_INIT, SFR_CAN0CN, 0); ///< Initialization Start            
SI_SBIT (CAN0CN_IE,   SFR_CAN0CN, 1); ///< Interrupt Enable                
SI_SBIT (CAN0CN_SIE,  SFR_CAN0CN, 2); ///< Status Change Interrupt Enable  
SI_SBIT (CAN0CN_EIE,  SFR_CAN0CN, 3); ///< Error Interrupt Enable          
SI_SBIT (CAN0CN_DAR,  SFR_CAN0CN, 5); ///< Automatic Retransmission Disable
SI_SBIT (CAN0CN_CCE,  SFR_CAN0CN, 6); ///< Configuration Change Enable     
SI_SBIT (CAN0CN_TEST, SFR_CAN0CN, 7); ///< Test Mode Enable                

// IE (Interrupt Enable)
#define SFR_IE 0xA8
SI_SBIT (IE_EX0,   SFR_IE, 0); ///< External Interrupt 0 Enable
SI_SBIT (IE_ET0,   SFR_IE, 1); ///< Timer 0 Interrupt Enable   
SI_SBIT (IE_EX1,   SFR_IE, 2); ///< External Interrupt 1 Enable
SI_SBIT (IE_ET1,   SFR_IE, 3); ///< Timer 1 Interrupt Enable   
SI_SBIT (IE_ES0,   SFR_IE, 4); ///< UART0 Interrupt Enable     
SI_SBIT (IE_ET2,   SFR_IE, 5); ///< Timer 2 Interrupt Enable   
SI_SBIT (IE_ESPI0, SFR_IE, 6); ///< SPI0 Interrupt Enable      
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

// PCA1CN (PCA Control)
#define SFR_PCA1CN 0xD8
SI_SBIT (PCA1CN_CCF6,  SFR_PCA1CN, 0); ///< PCA Module 6 Capture/Compare Flag 
SI_SBIT (PCA1CN_CCF7,  SFR_PCA1CN, 1); ///< PCA Module 7 Capture/Compare Flag 
SI_SBIT (PCA1CN_CCF8,  SFR_PCA1CN, 2); ///< PCA Module 8 Capture/Compare Flag 
SI_SBIT (PCA1CN_CCF9,  SFR_PCA1CN, 3); ///< PCA Module 9 Capture/Compare Flag 
SI_SBIT (PCA1CN_CCF10, SFR_PCA1CN, 4); ///< PCA Module 10 Capture/Compare Flag
SI_SBIT (PCA1CN_CCF11, SFR_PCA1CN, 5); ///< PCA Module 11 Capture/Compare Flag
SI_SBIT (PCA1CN_CR,    SFR_PCA1CN, 6); ///< PCA Counter/Timer Run Control     
SI_SBIT (PCA1CN_CF,    SFR_PCA1CN, 7); ///< PCA Counter/Timer Overflow Flag   

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
SI_SBIT (SCON0_THRE, SFR_SCON0, 5); ///< Transmit Holding Register Empty Flag
SI_SBIT (SCON0_PERR, SFR_SCON0, 6); ///< Parity Error Flag                   
SI_SBIT (SCON0_OVR,  SFR_SCON0, 7); ///< Receive FIFO Overrun Flag           

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
SI_SBIT (SMB0CN_SI,      SFR_SMB0CN, 0); ///< SMBus Interrupt Flag            
SI_SBIT (SMB0CN_ACK,     SFR_SMB0CN, 1); ///< SMBus Acknowledge               
SI_SBIT (SMB0CN_ARBLOST, SFR_SMB0CN, 2); ///< SMBus Arbitration Lost Indicator
SI_SBIT (SMB0CN_ACKRQ,   SFR_SMB0CN, 3); ///< SMBus Acknowledge Request       
SI_SBIT (SMB0CN_STO,     SFR_SMB0CN, 4); ///< SMBus Stop Flag                 
SI_SBIT (SMB0CN_STA,     SFR_SMB0CN, 5); ///< SMBus Start Flag                
SI_SBIT (SMB0CN_TXMODE,  SFR_SMB0CN, 6); ///< SMBus Transmit Mode Indicator   
SI_SBIT (SMB0CN_MASTER,  SFR_SMB0CN, 7); ///< SMBus Master/Slave Indicator    

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
SI_SBIT (TMR2CN_T2XCLK,  SFR_TMR2CN, 0); ///< Timer 2 External Clock Select    
SI_SBIT (TMR2CN_TR2,     SFR_TMR2CN, 2); ///< Timer 2 Run Control              
SI_SBIT (TMR2CN_T2SPLIT, SFR_TMR2CN, 3); ///< Timer 2 Split Mode Enable        
SI_SBIT (TMR2CN_TF2CEN,  SFR_TMR2CN, 4); ///< Timer 2 Capture Enable           
SI_SBIT (TMR2CN_TF2LEN,  SFR_TMR2CN, 5); ///< Timer 2 Low Byte Interrupt Enable
SI_SBIT (TMR2CN_TF2L,    SFR_TMR2CN, 6); ///< Timer 2 Low Byte Overflow Flag   
SI_SBIT (TMR2CN_TF2H,    SFR_TMR2CN, 7); ///< Timer 2 High Byte Overflow Flag  

// TMR4CN (Timer 4 Control)
#define SFR_TMR4CN 0xC8
SI_SBIT (TMR4CN_CPRL4, SFR_TMR4CN, 0); ///< Capture / Reload Select           
SI_SBIT (TMR4CN_CT4,   SFR_TMR4CN, 1); ///< Counter / Timer Select            
SI_SBIT (TMR4CN_TR4,   SFR_TMR4CN, 2); ///< Timer 4 Run Control               
SI_SBIT (TMR4CN_EXE4,  SFR_TMR4CN, 3); ///< Timer 4 External Enable           
SI_SBIT (TMR4CN_EXF4,  SFR_TMR4CN, 6); ///< Timer 4 External Flag             
SI_SBIT (TMR4CN_TF4,   SFR_TMR4CN, 7); ///< Timer 4 Overflow or Underflow Flag

//------------------------------------------------------------------------------
// Interrupt Definitions
//------------------------------------------------------------------------------
#define INT0_IRQn    0  ///< External Interrupt 0     
#define TIMER0_IRQn  1  ///< Timer 0 Overflow         
#define INT1_IRQn    2  ///< External Interrupt 1     
#define TIMER1_IRQn  3  ///< Timer 1 Overflow         
#define UART0_IRQn   4  ///< UART 0                   
#define TIMER2_IRQn  5  ///< Timer 2 Overflow         
#define SPI0_IRQn    6  ///< SPI0                     
#define SMBUS0_IRQn  7  ///< SMBus 0                  
#define ADC0WC_IRQn  8  ///< ADC0 Window Compare      
#define ADC0EOC_IRQn 9  ///< ADC0 End of Conversion   
#define PCA0_IRQn    10 ///< PCA0                     
#define CMP0_IRQn    11 ///< Comparator 0             
#define CMP1_IRQn    12 ///< Comparator 1             
#define TIMER3_IRQn  13 ///< Timer 3 Overflow         
#define LIN0_IRQn    14 ///< LIN0                     
#define VREG0_IRQn   15 ///< Voltage Regulator Dropout
#define CAN0_IRQn    16 ///< CAN0                     
#define PMATCH_IRQn  17 ///< Port Match               
#define UART1_IRQn   18 ///< UART 1                   
#define PCA1_IRQn    19 ///< PCA1                     
#define CMP2_IRQn    20 ///< Comparator 2             
#define TIMER4_IRQn  21 ///< Timer 4 Overflow         
#define TIMER5_IRQn  22 ///< Timer 5 Overflow         

//------------------------------------------------------------------------------
// SFR Page Definitions
//------------------------------------------------------------------------------
#define ACTIVE1_PAGE 0x00 ///< Active SFR Page 1                 
#define LEGACY_PAGE  0x00 ///< Legacy SFR Page                   
#define CAN0_PAGE    0x0C ///< CAN0 Page                         
#define CONFIG_PAGE  0x0F ///< System and Port Configuration Page
#define ACTIVE2_PAGE 0x10 ///< Active SFR Page 2                 

//-----------------------------------------------------------------------------
// SDCC PDATA External Memory Paging Support
//-----------------------------------------------------------------------------

#if defined SDCC

SI_SFR(_XPAGE, 0xAA); // Point to the EMI0CN register

#endif

#endif // SI_C8051F580_SI_DEFS_H
//-eof--------------------------------------------------------------------------

