;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  C8051F580_IM
;  C8051F580_IQ
;  C8051F581_IM
;  C8051F581_IQ
;  C8051F582_IM
;  C8051F582_IQ
;  C8051F583_IM
;  C8051F583_IQ
;  C8051F584_IM
;  C8051F584_IQ
;  C8051F585_IM
;  C8051F585_IQ
;  C8051F586_IM
;  C8051F586_IQ
;  C8051F587_IM
;  C8051F587_IQ
;  C8051F588_IM
;  C8051F589_IM
;  C8051F590_IM
;  C8051F591_IM
;  C8051F592_AM

;-----------------------------------------------------------------------------
; Register Definitions
;-----------------------------------------------------------------------------
ACC         DATA 0E0H; Accumulator                                 
ADC0CF      DATA 0BCH; ADC0 Configuration                          
ADC0CN      DATA 0E8H; ADC0 Control                                
ADC0GTH     DATA 0C4H; ADC0 Greater-Than High Byte                 
ADC0GTL     DATA 0C3H; ADC0 Greater-Than Low Byte                  
ADC0H       DATA 0BEH; ADC0 Data Word High Byte                    
ADC0L       DATA 0BDH; ADC0 Data Word Low Byte                     
ADC0LTH     DATA 0C6H; ADC0 Less-Than High Byte                    
ADC0LTL     DATA 0C5H; ADC0 Less-Than Low Byte                     
ADC0MX      DATA 0BBH; ADC0 Multiplexer Selection                  
ADC0TK      DATA 0BAH; ADC0 Burst Mode Track Time                  
B           DATA 0F0H; B Register                                  
CAN0BRPE    DATA 0A1H; CAN BRP Extension                           
CAN0BTH     DATA 09BH; CAN Bit Timing High                         
CAN0BTL     DATA 09AH; CAN Bit Timing Low                          
CAN0CFG     DATA 092H; CAN Clock Configuration                     
CAN0CN      DATA 0C0H; CAN Control                                 
CAN0ERRH    DATA 097H; CAN Error Counter High                      
CAN0ERRL    DATA 096H; CAN Error Counter Low                       
CAN0IF1A1H  DATA 0CBH; CAN Interface 1 Arbitration 1 High          
CAN0IF1A1L  DATA 0CAH; CAN Interface 1 Arbitration 1 Low           
CAN0IF1A2H  DATA 0CDH; CAN Interface 1 Arbitration 2 High          
CAN0IF1A2L  DATA 0CCH; CAN Interface 1 Arbitration 2 Low           
CAN0IF1CMH  DATA 0C3H; CAN Interface 1 Command Mask High           
CAN0IF1CML  DATA 0C2H; CAN Interface 1 Command Mask Low            
CAN0IF1CRH  DATA 0BFH; CAN Interface 1 Command Request High        
CAN0IF1CRL  DATA 0BEH; CAN Interface 1 Command Request Low         
CAN0IF1DA1H DATA 0D5H; CAN Interface 1 Data A 1 High               
CAN0IF1DA1L DATA 0D4H; CAN Interface 1 Data A 1 Low                
CAN0IF1DA2H DATA 0D7H; CAN Interface 1 Data A 2 High               
CAN0IF1DA2L DATA 0D6H; CAN Interface 1 Data A 2 Low                
CAN0IF1DB1H DATA 0DBH; CAN Interface 1 Data B 1 High               
CAN0IF1DB1L DATA 0DAH; CAN Interface 1 Data B 1 Low                
CAN0IF1DB2H DATA 0DDH; CAN Interface 1 Data B 2 High               
CAN0IF1DB2L DATA 0DCH; CAN Interface 1 Data B 2 Low                
CAN0IF1M1H  DATA 0C5H; CAN Interface 1 Mask 1 High                 
CAN0IF1M1L  DATA 0C4H; CAN Interface 1 Mask 1 Low                  
CAN0IF1M2H  DATA 0C7H; CAN Interface 1 Mask 2 High                 
CAN0IF1M2L  DATA 0C6H; CAN Interface 1 Mask 2 Low                  
CAN0IF1MCH  DATA 0D3H; CAN Interface 1 Message Control High        
CAN0IF1MCL  DATA 0D2H; CAN Interface 1 Message Control Low         
CAN0IF2A1H  DATA 0EFH; CAN Interface 2 Arbitration 1 High          
CAN0IF2A1L  DATA 0EEH; CAN Interface 2 Arbitration 1 Low           
CAN0IF2A2H  DATA 0F3H; CAN Interface 2 Arbitration 2 High          
CAN0IF2A2L  DATA 0F2H; CAN Interface 2 Arbitration 2 Low           
CAN0IF2CMH  DATA 0E3H; CAN Interface 2 Command Mask High           
CAN0IF2CML  DATA 0E2H; CAN Interface 2 Command Mask Low            
CAN0IF2CRH  DATA 0DFH; CAN Interface 2 Command Request High        
CAN0IF2CRL  DATA 0DEH; CAN Interface 2 Command Request Low         
CAN0IF2DA1H DATA 0F7H; CAN Interface 2 Data A 1 High               
CAN0IF2DA1L DATA 0F6H; CAN Interface 2 Data A 1 Low                
CAN0IF2DA2H DATA 0FBH; CAN Interface 2 Data A 2 High               
CAN0IF2DA2L DATA 0FAH; CAN Interface 2 Data A 2 Low                
CAN0IF2DB1H DATA 0FDH; CAN Interface 2 Data B 1 High               
CAN0IF2DB1L DATA 0FCH; CAN Interface 2 Data B 1 Low                
CAN0IF2DB2H DATA 0FFH; CAN Interface 2 Data B 2 High               
CAN0IF2DB2L DATA 0FEH; CAN Interface 2 Data B 2 Low                
CAN0IF2M1H  DATA 0EBH; CAN Interface 2 Mask 1 High                 
CAN0IF2M1L  DATA 0EAH; CAN Interface 2 Mask 1 Low                  
CAN0IF2M2H  DATA 0EDH; CAN Interface 2 Mask 2 High                 
CAN0IF2M2L  DATA 0ECH; CAN Interface 2 Mask 2 Low                  
CAN0IF2MCH  DATA 0CFH; CAN Interface 2 Message Control High        
CAN0IF2MCL  DATA 0CEH; CAN Interface 2 Message Control Low         
CAN0IIDH    DATA 09DH; CAN Interrupt High                          
CAN0IIDL    DATA 09CH; CAN Interrupt Low                           
CAN0IP1H    DATA 0AFH; CAN Interrupt Pending 1 High                
CAN0IP1L    DATA 0AEH; CAN Interrupt Pending 1 Low                 
CAN0IP2H    DATA 0B3H; CAN Interrupt Pending 2 High                
CAN0IP2L    DATA 0B2H; CAN Interrupt Pending 2 Low                 
CAN0MV1H    DATA 0BBH; CAN Message Valid 1 High                    
CAN0MV1L    DATA 0BAH; CAN Message Valid 1 Low                     
CAN0MV2H    DATA 0BDH; CAN Message Valid 2 High                    
CAN0MV2L    DATA 0BCH; CAN Message Valid 2 Low                     
CAN0ND1H    DATA 0ABH; CAN New Data 1 High                         
CAN0ND1L    DATA 0AAH; CAN New Data 1 Low                          
CAN0ND2H    DATA 0ADH; CAN New Data 2 High                         
CAN0ND2L    DATA 0ACH; CAN New Data 2 Low                          
CAN0STAT    DATA 094H; CAN Status                                  
CAN0TR1H    DATA 0A3H; CAN Transmission Request 1 High             
CAN0TR1L    DATA 0A2H; CAN Transmission Request 1 Low              
CAN0TR2H    DATA 0A5H; CAN Transmission Request 2 High             
CAN0TR2L    DATA 0A4H; CAN Transmission Request 2 Low              
CAN0TST     DATA 09EH; CAN Test                                    
CCH0CN      DATA 0E3H; Cache Control                               
CKCON       DATA 08EH; Clock Control                               
CLKMUL      DATA 097H; Clock Multiplier Control                    
CLKSEL      DATA 08FH; Clock Select                                
CPT0CN      DATA 09AH; Comparator 0 Control                        
CPT0MD      DATA 09BH; Comparator 0 Mode                           
CPT0MX      DATA 09CH; Comparator 0 Multiplexer Selection          
CPT1CN      DATA 09DH; Comparator 1 Control                        
CPT1MD      DATA 09EH; Comparator 1 Mode                           
CPT1MX      DATA 09FH; Comparator 1 Multiplexer Selection          
CPT2CN      DATA 09AH; Comparator 2 Control                        
CPT2MD      DATA 09BH; Comparator 2 Mode                           
CPT2MX      DATA 09CH; Comparator 2 Multiplexer Selection          
DPH         DATA 083H; Data Pointer High                           
DPL         DATA 082H; Data Pointer Low                            
EIE1        DATA 0E6H; Extended Interrupt Enable 1                 
EIE2        DATA 0E7H; Extended Interrupt Enable 2                 
EIP1        DATA 0F6H; Extended Interrupt Priority 1               
EIP2        DATA 0F7H; Extended Interrupt Priority 2               
EMI0CF      DATA 0B2H; External Memory Configuration               
EMI0CN      DATA 0AAH; External Memory Interface Control           
EMI0TC      DATA 0AAH; External Memory Timing Control              
FLKEY       DATA 0B7H; Flash Lock and Key                          
FLSCL       DATA 0B6H; Flash Scale                                 
IE          DATA 0A8H; Interrupt Enable                            
IP          DATA 0B8H; Interrupt Priority                          
IT01CF      DATA 0E4H; INT0/INT1 Configuration                     
LIN0ADR     DATA 0D3H; LIN0 Indirect Address                       
LIN0CF      DATA 0C9H; LIN0 Control Mode                           
LIN0DAT     DATA 0D2H; LIN0 Indirect Data                          
ONESHOT     DATA 0BEH; Flash Oneshot Period                        
OSCICN      DATA 0A1H; High Frequency Oscillator Control           
OSCICRS     DATA 0A2H; High Frequency Oscillator Coarse Calibration
OSCIFIN     DATA 09EH; High Frequency Oscillator Fine Calibration  
OSCXCN      DATA 09FH; External Oscillator Control                 
P0          DATA 080H; Port 0 Pin Latch                            
P0MASK      DATA 0F2H; Port 0 Mask                                 
P0MAT       DATA 0F1H; Port 0 Match                                
P0MDIN      DATA 0F1H; Port 0 Input Mode                           
P0MDOUT     DATA 0A4H; Port 0 Output Mode                          
P0SKIP      DATA 0D4H; Port 0 Skip                                 
P1          DATA 090H; Port 1 Pin Latch                            
P1MASK      DATA 0F4H; Port 1 Mask                                 
P1MAT       DATA 0F3H; Port 1 Match                                
P1MDIN      DATA 0F2H; Port 1 Input Mode                           
P1MDOUT     DATA 0A5H; Port 1 Output Mode                          
P1SKIP      DATA 0D5H; Port 1 Skip                                 
P2          DATA 0A0H; Port 2 Pin Latch                            
P2MASK      DATA 0B2H; Port 2 Mask                                 
P2MAT       DATA 0B1H; Port 2 Match                                
P2MDIN      DATA 0F3H; Port 2 Input Mode                           
P2MDOUT     DATA 0A6H; Port 2 Output Mode                          
P2SKIP      DATA 0D6H; Port 2 Skip                                 
P3          DATA 0B0H; Port 3 Pin Latch                            
P3MASK      DATA 0AFH; Port 3 Mask                                 
P3MAT       DATA 0AEH; Port 3 Match                                
P3MDIN      DATA 0F4H; Port 3 Input Mode                           
P3MDOUT     DATA 0AEH; Port 3 Output Mode                          
P3SKIP      DATA 0D7H; Port 3 Skip                                 
P4          DATA 0B5H; Port 4 Pin Latch                            
P4MDOUT     DATA 0AFH; Port 4 Output Mode                          
PCA0CN      DATA 0D8H; PCA Control                                 
PCA0CPH0    DATA 0FCH; PCA Channel 0 Capture Module High Byte      
PCA0CPH1    DATA 0EAH; PCA Channel 1 Capture Module High Byte      
PCA0CPH2    DATA 0ECH; PCA Channel 2 Capture Module High Byte      
PCA0CPH3    DATA 0EEH; PCA Channel 3 Capture Module High Byte      
PCA0CPH4    DATA 0FEH; PCA Channel 4 Capture Module High Byte      
PCA0CPH5    DATA 0CFH; PCA Channel 5 Capture Module High Byte      
PCA0CPL0    DATA 0FBH; PCA Channel 0 Capture Module Low Byte       
PCA0CPL1    DATA 0E9H; PCA Channel 1 Capture Module Low Byte       
PCA0CPL2    DATA 0EBH; PCA Channel 2 Capture Module Low Byte       
PCA0CPL3    DATA 0EDH; PCA Channel 3 Capture Module Low Byte       
PCA0CPL4    DATA 0FDH; PCA Channel 4 Capture Module Low Byte       
PCA0CPL5    DATA 0CEH; PCA Channel 5 Capture Module Low Byte       
PCA0CPM0    DATA 0DAH; PCA Channel 0 Capture/Compare Mode 0        
PCA0CPM1    DATA 0DBH; PCA Channel 1 Capture/Compare Mode          
PCA0CPM2    DATA 0DCH; PCA Channel 2 Capture/Compare Mode          
PCA0CPM3    DATA 0DDH; PCA Channel 3 Capture/Compare Mode          
PCA0CPM4    DATA 0DEH; PCA Channel 4 Capture/Compare Mode          
PCA0CPM5    DATA 0DFH; PCA Channel 5 Capture/Compare Mode          
PCA0H       DATA 0FAH; PCA Counter/Timer High Byte                 
PCA0L       DATA 0F9H; PCA Counter/Timer Low Byte                  
PCA0MD      DATA 0D9H; PCA Mode                                    
PCA0PWM     DATA 0D9H; PCA PWM Configuration                       
PCA1CN      DATA 0D8H; PCA Control                                 
PCA1CPH10   DATA 0FEH; PCA Channel 10 Capture Module High Byte     
PCA1CPH11   DATA 0CFH; PCA Channel 11 Capture Module High Byte     
PCA1CPH6    DATA 0FCH; PCA Channel 6 Capture Module High Byte      
PCA1CPH7    DATA 0EAH; PCA Channel 7 Capture Module High Byte      
PCA1CPH8    DATA 0ECH; PCA Channel 8 Capture Module High Byte      
PCA1CPH9    DATA 0EEH; PCA Channel 9 Capture Module High Byte      
PCA1CPL10   DATA 0FDH; PCA Channel 10 Capture Module Low Byte      
PCA1CPL11   DATA 0CEH; PCA Channel 11 Capture Module Low Byte      
PCA1CPL6    DATA 0FBH; PCA Channel 6 Capture Module Low Byte       
PCA1CPL7    DATA 0E9H; PCA Channel 7 Capture Module Low Byte       
PCA1CPL8    DATA 0EBH; PCA Channel 8 Capture Module Low Byte       
PCA1CPL9    DATA 0EDH; PCA Channel 9 Capture Module Low Byte       
PCA1CPM10   DATA 0DEH; PCA Channel 10 Capture/Compare Mode         
PCA1CPM11   DATA 0DFH; PCA Channel 11 Capture/Compare Mode         
PCA1CPM6    DATA 0DAH; PCA Channel 6 Capture/Compare Mode          
PCA1CPM7    DATA 0DBH; PCA Channel 7 Capture/Compare Mode          
PCA1CPM8    DATA 0DCH; PCA Channel 8 Capture/Compare Mode          
PCA1CPM9    DATA 0DDH; PCA Channel 9 Capture/Compare Mode          
PCA1H       DATA 0FAH; PCA Counter/Timer High Byte                 
PCA1L       DATA 0F9H; PCA Counter/Timer Low Byte                  
PCA1MD      DATA 0D9H; PCA Mode                                    
PCA1PWM     DATA 0DAH; PCA PWM Configuration                       
PCON        DATA 087H; Power Control                               
PSBANK      DATA 0F5H; Program Space Bank Select                   
PSCTL       DATA 08FH; Program Store Control                       
PSW         DATA 0D0H; Program Status Word                         
REF0CN      DATA 0D1H; Voltage Reference Control                   
REG0CN      DATA 0C9H; Voltage Regulator Control                   
RSTSRC      DATA 0EFH; Reset Source                                
SBCON0      DATA 0ABH; UART0 Baud Rate Generator Control           
SBRLH0      DATA 0ADH; UART0 Baud Rate Generator High Byte         
SBRLL0      DATA 0ACH; UART0 Baud Rate Generator Low Byte          
SBUF0       DATA 099H; UART0 Serial Port Data Buffer               
SBUF1       DATA 099H; UART1 Serial Port Data Buffer               
SCON0       DATA 098H; UART0 Serial Port Control                   
SCON1       DATA 098H; UART1 Serial Port Control                   
SFRLAST     DATA 086H; SFR Page Last                               
SFRNEXT     DATA 085H; SFR Page Next                               
SFRPAGE     DATA 0A7H; SFR Page                                    
SFRPGCN     DATA 084H; SFR Page Control                            
SMB0CF      DATA 0C1H; SMBus 0 Configuration                       
SMB0CN      DATA 0C0H; SMBus 0 Control                             
SMB0DAT     DATA 0C2H; SMBus 0 Data                                
SMOD0       DATA 0A9H; UART0 Mode                                  
SN0         DATA 0F9H; Serial Number Byte 0                        
SN1         DATA 0FAH; Serial Number Byte 1                        
SN2         DATA 0FBH; Serial Number Byte 2                        
SN3         DATA 0FCH; Serial Number Byte 3                        
SP          DATA 081H; Stack Pointer                               
SPI0CFG     DATA 0A1H; SPI0 Configuration                          
SPI0CKR     DATA 0A2H; SPI0 Clock Rate                             
SPI0CN      DATA 0F8H; SPI0 Control                                
SPI0DAT     DATA 0A3H; SPI0 Data                                   
TCON        DATA 088H; Timer 0/1 Control                           
TH0         DATA 08CH; Timer 0 High Byte                           
TH1         DATA 08DH; Timer 1 High Byte                           
TL0         DATA 08AH; Timer 0 Low Byte                            
TL1         DATA 08BH; Timer 1 Low Byte                            
TMOD        DATA 089H; Timer 0/1 Mode                              
TMR2CN      DATA 0C8H; Timer 2 Control                             
TMR2H       DATA 0CDH; Timer 2 High Byte                           
TMR2L       DATA 0CCH; Timer 2 Low Byte                            
TMR2RLH     DATA 0CBH; Timer 2 Reload High Byte                    
TMR2RLL     DATA 0CAH; Timer 2 Reload Low Byte                     
TMR3CN      DATA 091H; Timer 3 Control                             
TMR3H       DATA 095H; Timer 3 High Byte                           
TMR3L       DATA 094H; Timer 3 Low Byte                            
TMR3RLH     DATA 093H; Timer 3 Reload High Byte                    
TMR3RLL     DATA 092H; Timer 3 Reload Low Byte                     
TMR4CAPH    DATA 0CBH; Timer 4 Reload High Byte                    
TMR4CAPL    DATA 0CAH; Timer 4 Reload Low Byte                     
TMR4CF      DATA 0C9H; Timer 4 Config                              
TMR4CN      DATA 0C8H; Timer 4 Control                             
TMR4H       DATA 0CDH; Timer 4 High Byte                           
TMR4L       DATA 0CCH; Timer 4 Low Byte                            
TMR5CAPH    DATA 093H; Timer 5 Reload High Byte                    
TMR5CAPL    DATA 092H; Timer 5 Reload Low Byte                     
TMR5CF      DATA 096H; Timer 5 Config                              
TMR5CN      DATA 091H; Timer 5 Control                             
TMR5H       DATA 095H; Timer 5 High Byte                           
TMR5L       DATA 094H; Timer 5 Low Byte                            
VDM0CN      DATA 0FFH; VDD Supply Monitor Control                  
XBR0        DATA 0E1H; Port I/O Crossbar 0                         
XBR1        DATA 0E2H; Port I/O Crossbar 1                         
XBR2        DATA 0C7H; Port I/O Crossbar 2                         
XBR3        DATA 0C6H; Port I/O Crossbar 3                         

;------------------------------------------------------------------------------
; 16-bit Register Definitions (may not work on all compilers)
;------------------------------------------------------------------------------
ADC0GT     DATA 0C3H ; ADC0 Greater-Than Low Byte            
ADC0       DATA 0BDH ; ADC0 Data Word Low Byte               
ADC0LT     DATA 0C5H ; ADC0 Less-Than Low Byte               
CAN0BT     DATA 09AH ; CAN Bit Timing Low                    
CAN0ERR    DATA 096H ; CAN Error Counter Low                 
CAN0IF1A1  DATA 0CAH ; CAN Interface 1 Arbitration 1 Low     
CAN0IF1A2  DATA 0CCH ; CAN Interface 1 Arbitration 2 Low     
CAN0IF1CM  DATA 0C2H ; CAN Interface 1 Command Mask Low      
CAN0IF1CR  DATA 0BEH ; CAN Interface 1 Command Request Low   
CAN0IF1DA1 DATA 0D4H ; CAN Interface 1 Data A 1 Low          
CAN0IF1DA2 DATA 0D6H ; CAN Interface 1 Data A 2 Low          
CAN0IF1DB1 DATA 0DAH ; CAN Interface 1 Data B 1 Low          
CAN0IF1DB2 DATA 0DCH ; CAN Interface 1 Data B 2 Low          
CAN0IF1M1  DATA 0C4H ; CAN Interface 1 Mask 1 Low            
CAN0IF1M2  DATA 0C6H ; CAN Interface 1 Mask 2 Low            
CAN0IF1MC  DATA 0D2H ; CAN Interface 1 Message Control Low   
CAN0IF2A1  DATA 0EEH ; CAN Interface 2 Arbitration 1 Low     
CAN0IF2A2  DATA 0F2H ; CAN Interface 2 Arbitration 2 Low     
CAN0IF2CM  DATA 0E2H ; CAN Interface 2 Command Mask Low      
CAN0IF2CR  DATA 0DEH ; CAN Interface 2 Command Request Low   
CAN0IF2DA1 DATA 0F6H ; CAN Interface 2 Data A 1 Low          
CAN0IF2DA2 DATA 0FAH ; CAN Interface 2 Data A 2 Low          
CAN0IF2DB1 DATA 0FCH ; CAN Interface 2 Data B 1 Low          
CAN0IF2DB2 DATA 0FEH ; CAN Interface 2 Data B 2 Low          
CAN0IF2M1  DATA 0EAH ; CAN Interface 2 Mask 1 Low            
CAN0IF2M2  DATA 0ECH ; CAN Interface 2 Mask 2 Low            
CAN0IF2MC  DATA 0CEH ; CAN Interface 2 Message Control Low   
CAN0IID    DATA 09CH ; CAN Interrupt Low                     
CAN0IP1    DATA 0AEH ; CAN Interrupt Pending 1 Low           
CAN0IP2    DATA 0B2H ; CAN Interrupt Pending 2 Low           
CAN0MV1    DATA 0BAH ; CAN Message Valid 1 Low               
CAN0MV2    DATA 0BCH ; CAN Message Valid 2 Low               
CAN0ND1    DATA 0AAH ; CAN New Data 1 Low                    
CAN0ND2    DATA 0ACH ; CAN New Data 2 Low                    
CAN0TR1    DATA 0A2H ; CAN Transmission Request 1 Low        
CAN0TR2    DATA 0A4H ; CAN Transmission Request 2 Low        
DP         DATA 082H ; Data Pointer Low                      
PCA0CP0    DATA 0FBH ; PCA Channel 0 Capture Module Low Byte 
PCA0CP1    DATA 0E9H ; PCA Channel 1 Capture Module Low Byte 
PCA0CP2    DATA 0EBH ; PCA Channel 2 Capture Module Low Byte 
PCA0CP3    DATA 0EDH ; PCA Channel 3 Capture Module Low Byte 
PCA0CP4    DATA 0FDH ; PCA Channel 4 Capture Module Low Byte 
PCA0CP5    DATA 0CEH ; PCA Channel 5 Capture Module Low Byte 
PCA0       DATA 0F9H ; PCA Counter/Timer Low Byte            
PCA1CP10   DATA 0FDH ; PCA Channel 10 Capture Module Low Byte
PCA1CP11   DATA 0CEH ; PCA Channel 11 Capture Module Low Byte
PCA1CP6    DATA 0FBH ; PCA Channel 6 Capture Module Low Byte 
PCA1CP7    DATA 0E9H ; PCA Channel 7 Capture Module Low Byte 
PCA1CP8    DATA 0EBH ; PCA Channel 8 Capture Module Low Byte 
PCA1CP9    DATA 0EDH ; PCA Channel 9 Capture Module Low Byte 
PCA1       DATA 0F9H ; PCA Counter/Timer Low Byte            
SBRL0      DATA 0ACH ; UART0 Baud Rate Generator Low Byte    
TMR2       DATA 0CCH ; Timer 2 Low Byte                      
TMR2RL     DATA 0CAH ; Timer 2 Reload Low Byte               
TMR3       DATA 094H ; Timer 3 Low Byte                      
TMR3RL     DATA 092H ; Timer 3 Reload Low Byte               
TMR4CAP    DATA 0CAH ; Timer 4 Reload Low Byte               
TMR4       DATA 0CCH ; Timer 4 Low Byte                      
TMR5CAP    DATA 092H ; Timer 5 Reload Low Byte               
TMR5       DATA 094H ; Timer 5 Low Byte                      

;------------------------------------------------------------------------------
; Indirect Register Definitions
;------------------------------------------------------------------------------
ADC0GNA   EQU 008H ; ADC0 Adjustable Selectable Gain
ADC0GNH   EQU 004H ; ADC0 Selectable Gain High      
ADC0GNL   EQU 007H ; ADC0 Selectable Gain           
LIN0CTRL  EQU 008H ; LIN0 Control                   
LIN0DIV   EQU 00CH ; LIN0 Divider                   
LIN0DT1   EQU 000H ; LIN0 Data Byte 1               
LIN0DT2   EQU 001H ; LIN0 Data Byte 2               
LIN0DT3   EQU 002H ; LIN0 Data Byte 3               
LIN0DT4   EQU 003H ; LIN0 Data Byte 4               
LIN0DT5   EQU 004H ; LIN0 Data Byte 5               
LIN0DT6   EQU 005H ; LIN0 Data Byte 6               
LIN0DT7   EQU 006H ; LIN0 Data Byte 7               
LIN0DT8   EQU 007H ; LIN0 Data Byte 8               
LIN0ERR   EQU 00AH ; LIN0 Error                     
LIN0ID    EQU 00EH ; LIN0 Identifier                
LIN0MUL   EQU 00DH ; LIN0 Multiplier                
LIN0SIZE  EQU 00BH ; LIN0 Size                      
LIN0ST    EQU 009H ; LIN0 Status                    

;------------------------------------------------------------------------------
; Bit Definitions
;------------------------------------------------------------------------------

; ACC 0xE0 (Accumulator)
ACC_ACC0 BIT ACC.0 ; Accumulator Bit 0
ACC_ACC1 BIT ACC.1 ; Accumulator Bit 1
ACC_ACC2 BIT ACC.2 ; Accumulator Bit 2
ACC_ACC3 BIT ACC.3 ; Accumulator Bit 3
ACC_ACC4 BIT ACC.4 ; Accumulator Bit 4
ACC_ACC5 BIT ACC.5 ; Accumulator Bit 5
ACC_ACC6 BIT ACC.6 ; Accumulator Bit 6
ACC_ACC7 BIT ACC.7 ; Accumulator Bit 7

; ADC0CN 0xE8 (ADC0 Control)
ADC0CN_ADCM0  BIT ADC0CN.0 ; Start of Conversion Mode Select Bit 0
ADC0CN_ADCM1  BIT ADC0CN.1 ; Start of Conversion Mode Select Bit 1
ADC0CN_ADLJST BIT ADC0CN.2 ; Justification Select                 
ADC0CN_ADWINT BIT ADC0CN.3 ; Window Compare Interrupt Flag        
ADC0CN_ADBUSY BIT ADC0CN.4 ; ADC Busy                             
ADC0CN_ADINT  BIT ADC0CN.5 ; Conversion Complete Interrupt Flag   
ADC0CN_ADBMEN BIT ADC0CN.6 ; Burst Mode Enable                    
ADC0CN_ADEN   BIT ADC0CN.7 ; ADC Enable                           

; B 0xF0 (B Register)
B_B0 BIT B.0 ; B Register Bit 0
B_B1 BIT B.1 ; B Register Bit 1
B_B2 BIT B.2 ; B Register Bit 2
B_B3 BIT B.3 ; B Register Bit 3
B_B4 BIT B.4 ; B Register Bit 4
B_B5 BIT B.5 ; B Register Bit 5
B_B6 BIT B.6 ; B Register Bit 6
B_B7 BIT B.7 ; B Register Bit 7

; CAN0CN 0xC0 (CAN Control)
CAN0CN_INIT BIT CAN0CN.0 ; Initialization Start            
CAN0CN_IE   BIT CAN0CN.1 ; Interrupt Enable                
CAN0CN_SIE  BIT CAN0CN.2 ; Status Change Interrupt Enable  
CAN0CN_EIE  BIT CAN0CN.3 ; Error Interrupt Enable          
CAN0CN_DAR  BIT CAN0CN.5 ; Automatic Retransmission Disable
CAN0CN_CCE  BIT CAN0CN.6 ; Configuration Change Enable     
CAN0CN_TEST BIT CAN0CN.7 ; Test Mode Enable                

; IE 0xA8 (Interrupt Enable)
IE_EX0   BIT IE.0 ; External Interrupt 0 Enable
IE_ET0   BIT IE.1 ; Timer 0 Interrupt Enable   
IE_EX1   BIT IE.2 ; External Interrupt 1 Enable
IE_ET1   BIT IE.3 ; Timer 1 Interrupt Enable   
IE_ES0   BIT IE.4 ; UART0 Interrupt Enable     
IE_ET2   BIT IE.5 ; Timer 2 Interrupt Enable   
IE_ESPI0 BIT IE.6 ; SPI0 Interrupt Enable      
IE_EA    BIT IE.7 ; All Interrupts Enable      

; IP 0xB8 (Interrupt Priority)
IP_PX0   BIT IP.0 ; External Interrupt 0 Priority Control                        
IP_PT0   BIT IP.1 ; Timer 0 Interrupt Priority Control                           
IP_PX1   BIT IP.2 ; External Interrupt 1 Priority Control                        
IP_PT1   BIT IP.3 ; Timer 1 Interrupt Priority Control                           
IP_PS0   BIT IP.4 ; UART0 Interrupt Priority Control                             
IP_PT2   BIT IP.5 ; Timer 2 Interrupt Priority Control                           
IP_PSPI0 BIT IP.6 ; Serial Peripheral Interface (SPI0) Interrupt Priority Control

; P0 0x80 (Port 0 Pin Latch)
P0_B0 BIT P0.0 ; Port 0 Bit 0 Latch
P0_B1 BIT P0.1 ; Port 0 Bit 1 Latch
P0_B2 BIT P0.2 ; Port 0 Bit 2 Latch
P0_B3 BIT P0.3 ; Port 0 Bit 3 Latch
P0_B4 BIT P0.4 ; Port 0 Bit 4 Latch
P0_B5 BIT P0.5 ; Port 0 Bit 5 Latch
P0_B6 BIT P0.6 ; Port 0 Bit 6 Latch
P0_B7 BIT P0.7 ; Port 0 Bit 7 Latch

; P1 0x90 (Port 1 Pin Latch)
P1_B0 BIT P1.0 ; Port 1 Bit 0 Latch
P1_B1 BIT P1.1 ; Port 1 Bit 1 Latch
P1_B2 BIT P1.2 ; Port 1 Bit 2 Latch
P1_B3 BIT P1.3 ; Port 1 Bit 3 Latch
P1_B4 BIT P1.4 ; Port 1 Bit 4 Latch
P1_B5 BIT P1.5 ; Port 1 Bit 5 Latch
P1_B6 BIT P1.6 ; Port 1 Bit 6 Latch
P1_B7 BIT P1.7 ; Port 1 Bit 7 Latch

; P2 0xA0 (Port 2 Pin Latch)
P2_B0 BIT P2.0 ; Port 2 Bit 0 Latch
P2_B1 BIT P2.1 ; Port 2 Bit 1 Latch
P2_B2 BIT P2.2 ; Port 2 Bit 2 Latch
P2_B3 BIT P2.3 ; Port 2 Bit 3 Latch
P2_B4 BIT P2.4 ; Port 2 Bit 4 Latch
P2_B5 BIT P2.5 ; Port 2 Bit 5 Latch
P2_B6 BIT P2.6 ; Port 2 Bit 6 Latch
P2_B7 BIT P2.7 ; Port 2 Bit 7 Latch

; P3 0xB0 (Port 3 Pin Latch)
P3_B0 BIT P3.0 ; Port 3 Bit 0 Latch
P3_B1 BIT P3.1 ; Port 3 Bit 1 Latch
P3_B2 BIT P3.2 ; Port 3 Bit 2 Latch
P3_B3 BIT P3.3 ; Port 3 Bit 3 Latch
P3_B4 BIT P3.4 ; Port 3 Bit 4 Latch
P3_B5 BIT P3.5 ; Port 3 Bit 5 Latch
P3_B6 BIT P3.6 ; Port 3 Bit 6 Latch
P3_B7 BIT P3.7 ; Port 3 Bit 7 Latch

; PCA0CN 0xD8 (PCA Control)
PCA0CN_CCF0 BIT PCA0CN.0 ; PCA Module 0 Capture/Compare Flag
PCA0CN_CCF1 BIT PCA0CN.1 ; PCA Module 1 Capture/Compare Flag
PCA0CN_CCF2 BIT PCA0CN.2 ; PCA Module 2 Capture/Compare Flag
PCA0CN_CCF3 BIT PCA0CN.3 ; PCA Module 3 Capture/Compare Flag
PCA0CN_CCF4 BIT PCA0CN.4 ; PCA Module 4 Capture/Compare Flag
PCA0CN_CCF5 BIT PCA0CN.5 ; PCA Module 5 Capture/Compare Flag
PCA0CN_CR   BIT PCA0CN.6 ; PCA Counter/Timer Run Control    
PCA0CN_CF   BIT PCA0CN.7 ; PCA Counter/Timer Overflow Flag  

; PCA1CN 0xD8 (PCA Control)
PCA1CN_CCF6  BIT PCA1CN.0 ; PCA Module 6 Capture/Compare Flag 
PCA1CN_CCF7  BIT PCA1CN.1 ; PCA Module 7 Capture/Compare Flag 
PCA1CN_CCF8  BIT PCA1CN.2 ; PCA Module 8 Capture/Compare Flag 
PCA1CN_CCF9  BIT PCA1CN.3 ; PCA Module 9 Capture/Compare Flag 
PCA1CN_CCF10 BIT PCA1CN.4 ; PCA Module 10 Capture/Compare Flag
PCA1CN_CCF11 BIT PCA1CN.5 ; PCA Module 11 Capture/Compare Flag
PCA1CN_CR    BIT PCA1CN.6 ; PCA Counter/Timer Run Control     
PCA1CN_CF    BIT PCA1CN.7 ; PCA Counter/Timer Overflow Flag   

; PSW 0xD0 (Program Status Word)
PSW_PARITY BIT PSW.0 ; Parity Flag               
PSW_F1     BIT PSW.1 ; User Flag 1               
PSW_OV     BIT PSW.2 ; Overflow Flag             
PSW_RS0    BIT PSW.3 ; Register Bank Select Bit 0
PSW_RS1    BIT PSW.4 ; Register Bank Select Bit 1
PSW_F0     BIT PSW.5 ; User Flag 0               
PSW_AC     BIT PSW.6 ; Auxiliary Carry Flag      
PSW_CY     BIT PSW.7 ; Carry Flag                

; SCON0 0x98 (UART0 Serial Port Control)
SCON0_RI   BIT SCON0.0 ; Receive Interrupt Flag              
SCON0_TI   BIT SCON0.1 ; Transmit Interrupt Flag             
SCON0_RBX  BIT SCON0.2 ; Extra Receive Bit                   
SCON0_TBX  BIT SCON0.3 ; Extra Transmission Bit              
SCON0_REN  BIT SCON0.4 ; Receive Enable                      
SCON0_THRE BIT SCON0.5 ; Transmit Holding Register Empty Flag
SCON0_PERR BIT SCON0.6 ; Parity Error Flag                   
SCON0_OVR  BIT SCON0.7 ; Receive FIFO Overrun Flag           

; SCON1 0x98 (UART1 Serial Port Control)
SCON1_RI    BIT SCON1.0 ; Receive Interrupt Flag             
SCON1_TI    BIT SCON1.1 ; Transmit Interrupt Flag            
SCON1_RB8   BIT SCON1.2 ; Ninth Receive Bit                  
SCON1_TB8   BIT SCON1.3 ; Ninth Transmission Bit             
SCON1_REN   BIT SCON1.4 ; Receive Enable                     
SCON1_MCE   BIT SCON1.5 ; Multiprocessor Communication Enable
SCON1_SMODE BIT SCON1.7 ; Serial Port 0 Operation Mode       

; SMB0CN 0xC0 (SMBus 0 Control)
SMB0CN_SI      BIT SMB0CN.0 ; SMBus Interrupt Flag            
SMB0CN_ACK     BIT SMB0CN.1 ; SMBus Acknowledge               
SMB0CN_ARBLOST BIT SMB0CN.2 ; SMBus Arbitration Lost Indicator
SMB0CN_ACKRQ   BIT SMB0CN.3 ; SMBus Acknowledge Request       
SMB0CN_STO     BIT SMB0CN.4 ; SMBus Stop Flag                 
SMB0CN_STA     BIT SMB0CN.5 ; SMBus Start Flag                
SMB0CN_TXMODE  BIT SMB0CN.6 ; SMBus Transmit Mode Indicator   
SMB0CN_MASTER  BIT SMB0CN.7 ; SMBus Master/Slave Indicator    

; SPI0CN 0xF8 (SPI0 Control)
SPI0CN_SPIEN  BIT SPI0CN.0 ; SPI0 Enable            
SPI0CN_TXBMT  BIT SPI0CN.1 ; Transmit Buffer Empty  
SPI0CN_NSSMD0 BIT SPI0CN.2 ; Slave Select Mode Bit 0
SPI0CN_NSSMD1 BIT SPI0CN.3 ; Slave Select Mode Bit 1
SPI0CN_RXOVRN BIT SPI0CN.4 ; Receive Overrun Flag   
SPI0CN_MODF   BIT SPI0CN.5 ; Mode Fault Flag        
SPI0CN_WCOL   BIT SPI0CN.6 ; Write Collision Flag   
SPI0CN_SPIF   BIT SPI0CN.7 ; SPI0 Interrupt Flag    

; TCON 0x88 (Timer 0/1 Control)
TCON_IT0 BIT TCON.0 ; Interrupt 0 Type Select
TCON_IE0 BIT TCON.1 ; External Interrupt 0   
TCON_IT1 BIT TCON.2 ; Interrupt 1 Type Select
TCON_IE1 BIT TCON.3 ; External Interrupt 1   
TCON_TR0 BIT TCON.4 ; Timer 0 Run Control    
TCON_TF0 BIT TCON.5 ; Timer 0 Overflow Flag  
TCON_TR1 BIT TCON.6 ; Timer 1 Run Control    
TCON_TF1 BIT TCON.7 ; Timer 1 Overflow Flag  

; TMR2CN 0xC8 (Timer 2 Control)
TMR2CN_T2XCLK  BIT TMR2CN.0 ; Timer 2 External Clock Select    
TMR2CN_TR2     BIT TMR2CN.2 ; Timer 2 Run Control              
TMR2CN_T2SPLIT BIT TMR2CN.3 ; Timer 2 Split Mode Enable        
TMR2CN_TF2CEN  BIT TMR2CN.4 ; Timer 2 Capture Enable           
TMR2CN_TF2LEN  BIT TMR2CN.5 ; Timer 2 Low Byte Interrupt Enable
TMR2CN_TF2L    BIT TMR2CN.6 ; Timer 2 Low Byte Overflow Flag   
TMR2CN_TF2H    BIT TMR2CN.7 ; Timer 2 High Byte Overflow Flag  

; TMR4CN 0xC8 (Timer 4 Control)
TMR4CN_CPRL4 BIT TMR4CN.0 ; Capture / Reload Select           
TMR4CN_CT4   BIT TMR4CN.1 ; Counter / Timer Select            
TMR4CN_TR4   BIT TMR4CN.2 ; Timer 4 Run Control               
TMR4CN_EXE4  BIT TMR4CN.3 ; Timer 4 External Enable           
TMR4CN_EXF4  BIT TMR4CN.6 ; Timer 4 External Flag             
TMR4CN_TF4   BIT TMR4CN.7 ; Timer 4 Overflow or Underflow Flag

;------------------------------------------------------------------------------
; Interrupt Definitions
;------------------------------------------------------------------------------
INT0_IRQn    EQU 0  ; External Interrupt 0     
TIMER0_IRQn  EQU 1  ; Timer 0 Overflow         
INT1_IRQn    EQU 2  ; External Interrupt 1     
TIMER1_IRQn  EQU 3  ; Timer 1 Overflow         
UART0_IRQn   EQU 4  ; UART 0                   
TIMER2_IRQn  EQU 5  ; Timer 2 Overflow         
SPI0_IRQn    EQU 6  ; SPI0                     
SMBUS0_IRQn  EQU 7  ; SMBus 0                  
ADC0WC_IRQn  EQU 8  ; ADC0 Window Compare      
ADC0EOC_IRQn EQU 9  ; ADC0 End of Conversion   
PCA0_IRQn    EQU 10 ; PCA0                     
CMP0_IRQn    EQU 11 ; Comparator 0             
CMP1_IRQn    EQU 12 ; Comparator 1             
TIMER3_IRQn  EQU 13 ; Timer 3 Overflow         
LIN0_IRQn    EQU 14 ; LIN0                     
VREG0_IRQn   EQU 15 ; Voltage Regulator Dropout
CAN0_IRQn    EQU 16 ; CAN0                     
PMATCH_IRQn  EQU 17 ; Port Match               
UART1_IRQn   EQU 18 ; UART 1                   
PCA1_IRQn    EQU 19 ; PCA1                     
CMP2_IRQn    EQU 20 ; Comparator 2             
TIMER4_IRQn  EQU 21 ; Timer 4 Overflow         
TIMER5_IRQn  EQU 22 ; Timer 5 Overflow         

;------------------------------------------------------------------------------
; SFR Page Definitions
;------------------------------------------------------------------------------
ACTIVE1_PAGE  EQU 000H ; Active SFR Page 1                 
LEGACY_PAGE   EQU 000H ; Legacy SFR Page                   
CAN0_PAGE     EQU 00CH ; CAN0 Page                         
CONFIG_PAGE   EQU 00FH ; System and Port Configuration Page
ACTIVE2_PAGE  EQU 010H ; Active SFR Page 2                 
