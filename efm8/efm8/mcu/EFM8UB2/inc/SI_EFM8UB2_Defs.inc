;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  EFM8UB20F32G_QFN32
;  EFM8UB20F32G_QFP32
;  EFM8UB20F32G_QFP48
;  EFM8UB20F64G_QFN32
;  EFM8UB20F64G_QFP32
;  EFM8UB20F64G_QFP48

;-----------------------------------------------------------------------------
; Register Definitions
;-----------------------------------------------------------------------------
ACC      DATA 0E0H; Accumulator                           
ADC0CF   DATA 0BCH; ADC0 Configuration                    
ADC0CN0  DATA 0E8H; ADC0 Control                          
ADC0GTH  DATA 0C4H; ADC0 Greater-Than High Byte           
ADC0GTL  DATA 0C3H; ADC0 Greater-Than Low Byte            
ADC0H    DATA 0BEH; ADC0 Data Word High Byte              
ADC0L    DATA 0BDH; ADC0 Data Word Low Byte               
ADC0LTH  DATA 0C6H; ADC0 Less-Than High Byte              
ADC0LTL  DATA 0C5H; ADC0 Less-Than Low Byte               
AMX0N    DATA 0BAH; AMUX0 Negative Multiplexer Selection  
AMX0P    DATA 0BBH; AMUX0 Positive Multiplexer Selection  
B        DATA 0F0H; B Register                            
CKCON0   DATA 08EH; Clock Control 0                       
CKCON1   DATA 0E4H; Clock Control 1                       
CLKSEL   DATA 0A9H; Clock Select                          
CMP0CN0  DATA 09BH; Comparator 0 Control 0                
CMP0MD   DATA 09DH; Comparator 0 Mode                     
CMP0MX   DATA 09FH; Comparator 0 Multiplexer Selection    
CMP1CN0  DATA 09AH; Comparator 1 Control 0                
CMP1MD   DATA 09CH; Comparator 1 Mode                     
CMP1MX   DATA 09EH; Comparator 1 Multiplexer Selection    
DPH      DATA 083H; Data Pointer High                     
DPL      DATA 082H; Data Pointer Low                      
EIE1     DATA 0E6H; Extended Interrupt Enable 1           
EIE2     DATA 0E7H; Extended Interrupt Enable 2           
EIP1     DATA 0F6H; Extended Interrupt Priority 1         
EIP2     DATA 0F7H; Extended Interrupt Priority 2         
EMI0CF   DATA 085H; External Memory Configuration         
EMI0CN   DATA 0AAH; External Memory Interface Control     
EMI0TC   DATA 084H; External Memory Timing Control        
FLKEY    DATA 0B7H; Flash Lock and Key                    
FLSCL    DATA 0B6H; Flash Scale                           
HFO0CAL  DATA 0B3H; High Frequency Oscillator Calibration 
HFO0CN   DATA 0B2H; High Frequency Oscillator Control     
IE       DATA 0A8H; Interrupt Enable                      
IP       DATA 0B8H; Interrupt Priority                    
IT01CF   DATA 0E4H; INT0/INT1 Configuration               
LFO0CN   DATA 086H; Low Frequency Oscillator Control      
P0       DATA 080H; Port 0 Pin Latch                      
P0MDIN   DATA 0F1H; Port 0 Input Mode                     
P0MDOUT  DATA 0A4H; Port 0 Output Mode                    
P0SKIP   DATA 0D4H; Port 0 Skip                           
P1       DATA 090H; Port 1 Pin Latch                      
P1MDIN   DATA 0F2H; Port 1 Input Mode                     
P1MDOUT  DATA 0A5H; Port 1 Output Mode                    
P1SKIP   DATA 0D5H; Port 1 Skip                           
P2       DATA 0A0H; Port 2 Pin Latch                      
P2MDIN   DATA 0F3H; Port 2 Input Mode                     
P2MDOUT  DATA 0A6H; Port 2 Output Mode                    
P2SKIP   DATA 0D6H; Port 2 Skip                           
P3       DATA 0B0H; Port 3 Pin Latch                      
P3MDIN   DATA 0F4H; Port 3 Input Mode                     
P3MDOUT  DATA 0A7H; Port 3 Output Mode                    
P3SKIP   DATA 0DFH; Port 3 Skip                           
P4       DATA 0C7H; Port 4 Pin Latch                      
P4MDIN   DATA 0F5H; Port 4 Input Mode                     
P4MDOUT  DATA 0AEH; Port 4 Output Mode                    
PCA0CN0  DATA 0D8H; PCA Control 0                         
PCA0CPH0 DATA 0FCH; PCA Channel 0 Capture Module High Byte
PCA0CPH1 DATA 0EAH; PCA Channel 1 Capture Module High Byte
PCA0CPH2 DATA 0ECH; PCA Channel 2 Capture Module High Byte
PCA0CPH3 DATA 0EEH; PCA Channel 3 Capture Module High Byte
PCA0CPH4 DATA 0FEH; PCA Channel 4 Capture Module High Byte
PCA0CPL0 DATA 0FBH; PCA Channel 0 Capture Module Low Byte 
PCA0CPL1 DATA 0E9H; PCA Channel 1 Capture Module Low Byte 
PCA0CPL2 DATA 0EBH; PCA Channel 2 Capture Module Low Byte 
PCA0CPL3 DATA 0EDH; PCA Channel 3 Capture Module Low Byte 
PCA0CPL4 DATA 0FDH; PCA Channel 4 Capture Module Low Byte 
PCA0CPM0 DATA 0DAH; PCA Channel 0 Capture/Compare Mode    
PCA0CPM1 DATA 0DBH; PCA Channel 1 Capture/Compare Mode    
PCA0CPM2 DATA 0DCH; PCA Channel 2 Capture/Compare Mode    
PCA0CPM3 DATA 0DDH; PCA Channel 3 Capture/Compare Mode    
PCA0CPM4 DATA 0DEH; PCA Channel 4 Capture/Compare Mode    
PCA0H    DATA 0FAH; PCA Counter/Timer High Byte           
PCA0L    DATA 0F9H; PCA Counter/Timer Low Byte            
PCA0MD   DATA 0D9H; PCA Mode                              
PCON0    DATA 087H; Power Control                         
PFE0CN   DATA 0AFH; Prefetch Engine Control               
PSCTL    DATA 08FH; Program Store Control                 
PSW      DATA 0D0H; Program Status Word                   
REF0CN   DATA 0D1H; Voltage Reference Control             
REG01CN  DATA 0C9H; Voltage Regulator Control             
RSTSRC   DATA 0EFH; Reset Source                          
SBCON1   DATA 0ACH; UART1 Baud Rate Generator Control     
SBRLH1   DATA 0B5H; UART1 Baud Rate Generator High Byte   
SBRLL1   DATA 0B4H; UART1 Baud Rate Generator Low Byte    
SBUF0    DATA 099H; UART0 Serial Port Data Buffer         
SBUF1    DATA 0D3H; UART1 Serial Port Data Buffer         
SCON0    DATA 098H; UART0 Serial Port Control             
SCON1    DATA 0D2H; UART1 Serial Port Control             
SFRPAGE  DATA 0BFH; SFR Page                              
SMB0ADM  DATA 0CEH; SMBus 0 Slave Address Mask            
SMB0ADR  DATA 0CFH; SMBus 0 Slave Address                 
SMB0CF   DATA 0C1H; SMBus 0 Configuration                 
SMB0CN0  DATA 0C0H; SMBus 0 Control                       
SMB0DAT  DATA 0C2H; SMBus 0 Data                          
SMB1ADM  DATA 0CEH; SMBus 1 Slave Address Mask            
SMB1ADR  DATA 0CFH; SMBus 1 Slave Address                 
SMB1CF   DATA 0C1H; SMBus 1 Configuration                 
SMB1CN0  DATA 0C0H; SMBus 1 Control                       
SMB1DAT  DATA 0C2H; SMBus 1 Data                          
SMBTC    DATA 0B9H; SMBus Timing and Pin Control          
SMOD1    DATA 0E5H; UART1 Mode                            
SP       DATA 081H; Stack Pointer                         
SPI0CFG  DATA 0A1H; SPI0 Configuration                    
SPI0CKR  DATA 0A2H; SPI0 Clock Rate                       
SPI0CN0  DATA 0F8H; SPI0 Control                          
SPI0DAT  DATA 0A3H; SPI0 Data                             
TCON     DATA 088H; Timer 0/1 Control                     
TH0      DATA 08CH; Timer 0 High Byte                     
TH1      DATA 08DH; Timer 1 High Byte                     
TL0      DATA 08AH; Timer 0 Low Byte                      
TL1      DATA 08BH; Timer 1 Low Byte                      
TMOD     DATA 089H; Timer 0/1 Mode                        
TMR2CN0  DATA 0C8H; Timer 2 Control 0                     
TMR2H    DATA 0CDH; Timer 2 High Byte                     
TMR2L    DATA 0CCH; Timer 2 Low Byte                      
TMR2RLH  DATA 0CBH; Timer 2 Reload High Byte              
TMR2RLL  DATA 0CAH; Timer 2 Reload Low Byte               
TMR3CN0  DATA 091H; Timer 3 Control 0                     
TMR3H    DATA 095H; Timer 3 High Byte                     
TMR3L    DATA 094H; Timer 3 Low Byte                      
TMR3RLH  DATA 093H; Timer 3 Reload High Byte              
TMR3RLL  DATA 092H; Timer 3 Reload Low Byte               
TMR4CN0  DATA 091H; Timer 4 Control 0                     
TMR4H    DATA 095H; Timer 4 High Byte                     
TMR4L    DATA 094H; Timer 4 Low Byte                      
TMR4RLH  DATA 093H; Timer 4 Reload High Byte              
TMR4RLL  DATA 092H; Timer 4 Reload Low Byte               
TMR5CN0  DATA 0C8H; Timer 5 Control 0                     
TMR5H    DATA 0CDH; Timer 5 High Byte                     
TMR5L    DATA 0CCH; Timer 5 Low Byte                      
TMR5RLH  DATA 0CBH; Timer 5 Reload High Byte              
TMR5RLL  DATA 0CAH; Timer 5 Reload Low Byte               
USB0ADR  DATA 096H; USB0 Indirect Address                 
USB0DAT  DATA 097H; USB0 Data                             
USB0XCN  DATA 0D7H; USB0 Transceiver Control              
VDM0CN   DATA 0FFH; Supply Monitor Control                
XBR0     DATA 0E1H; Port I/O Crossbar 0                   
XBR1     DATA 0E2H; Port I/O Crossbar 1                   
XBR2     DATA 0E3H; Port I/O Crossbar 2                   
XOSC0CN  DATA 0B1H; External Oscillator Control           

;------------------------------------------------------------------------------
; 16-bit Register Definitions (may not work on all compilers)
;------------------------------------------------------------------------------
ADC0GT  DATA 0C3H ; ADC0 Greater-Than Low Byte           
ADC0    DATA 0BDH ; ADC0 Data Word Low Byte              
ADC0LT  DATA 0C5H ; ADC0 Less-Than Low Byte              
DP      DATA 082H ; Data Pointer Low                     
PCA0CP0 DATA 0FBH ; PCA Channel 0 Capture Module Low Byte
PCA0CP1 DATA 0E9H ; PCA Channel 1 Capture Module Low Byte
PCA0CP2 DATA 0EBH ; PCA Channel 2 Capture Module Low Byte
PCA0CP3 DATA 0EDH ; PCA Channel 3 Capture Module Low Byte
PCA0CP4 DATA 0FDH ; PCA Channel 4 Capture Module Low Byte
PCA0    DATA 0F9H ; PCA Counter/Timer Low Byte           
SBRL1   DATA 0B4H ; UART1 Baud Rate Generator Low Byte   
TMR2    DATA 0CCH ; Timer 2 Low Byte                     
TMR2RL  DATA 0CAH ; Timer 2 Reload Low Byte              
TMR3    DATA 094H ; Timer 3 Low Byte                     
TMR3RL  DATA 092H ; Timer 3 Reload Low Byte              
TMR4    DATA 094H ; Timer 4 Low Byte                     
TMR4RL  DATA 092H ; Timer 4 Reload Low Byte              
TMR5    DATA 0CCH ; Timer 5 Low Byte                     
TMR5RL  DATA 0CAH ; Timer 5 Reload Low Byte              

;------------------------------------------------------------------------------
; Indirect Register Definitions
;------------------------------------------------------------------------------
CLKREC    EQU 00FH ; USB0 Clock Recovery Control       
CMIE      EQU 00BH ; USB0 Common Interrupt Enable      
CMINT     EQU 006H ; USB0 Common Interrupt             
E0CNT     EQU 016H ; USB0 Endpoint0 Data Count         
E0CSR     EQU 011H ; USB0 Endpoint0 Control            
EENABLE   EQU 01EH ; USB0 Endpoint Enable              
EINCSRH   EQU 012H ; USB0 IN Endpoint Control High     
EINCSRL   EQU 011H ; USB0 IN Endpoint Control          
EOUTCNTH  EQU 017H ; USB0 OUT Endpoint Count High      
EOUTCNTL  EQU 016H ; USB0 OUT Endpoint Count           
EOUTCSRH  EQU 015H ; USB0 OUT Endpoint Control High    
EOUTCSRL  EQU 014H ; USB0 OUT Endpoint Control         
FADDR     EQU 000H ; USB0 Function Address             
FIFO0     EQU 020H ; USB0 Endpoint 0 FIFO Access       
FIFO1     EQU 021H ; USB0 Endpoint 1 FIFO Access       
FIFO2     EQU 022H ; USB0 Endpoint 2 FIFO Access       
FIFO3     EQU 023H ; USB0 Endpoint 3 FIFO Access       
FRAMEH    EQU 00DH ; USB0 Frame Number High            
FRAMEL    EQU 00CH ; USB0 Frame Number                 
IN1IE     EQU 007H ; USB0 IN Endpoint Interrupt Enable 
IN1INT    EQU 002H ; USB0 IN Endpoint Interrupt        
INDEX     EQU 00EH ; USB0 Endpoint Index               
OUT1IE    EQU 009H ; USB0 OUT Endpoint Interrupt Enable
OUT1INT   EQU 004H ; USB0 OUT Endpoint Interrupt       
POWER     EQU 001H ; USB0 Power                        

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

; ADC0CN0 0xE8 (ADC0 Control)
ADC0CN0_ADCM0  BIT ADC0CN0.0 ; Start of Conversion Mode Select Bit 0
ADC0CN0_ADCM1  BIT ADC0CN0.1 ; Start of Conversion Mode Select Bit 1
ADC0CN0_ADCM2  BIT ADC0CN0.2 ; Start of Conversion Mode Select Bit 2
ADC0CN0_ADWINT BIT ADC0CN0.3 ; Window Compare Interrupt Flag        
ADC0CN0_ADBUSY BIT ADC0CN0.4 ; ADC Busy                             
ADC0CN0_ADINT  BIT ADC0CN0.5 ; Conversion Complete Interrupt Flag   
ADC0CN0_ADTM   BIT ADC0CN0.6 ; Track Mode                           
ADC0CN0_ADEN   BIT ADC0CN0.7 ; ADC Enable                           

; B 0xF0 (B Register)
B_B0 BIT B.0 ; B Register Bit 0
B_B1 BIT B.1 ; B Register Bit 1
B_B2 BIT B.2 ; B Register Bit 2
B_B3 BIT B.3 ; B Register Bit 3
B_B4 BIT B.4 ; B Register Bit 4
B_B5 BIT B.5 ; B Register Bit 5
B_B6 BIT B.6 ; B Register Bit 6
B_B7 BIT B.7 ; B Register Bit 7

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

; PCA0CN0 0xD8 (PCA Control 0)
PCA0CN0_CCF0 BIT PCA0CN0.0 ; PCA Module 0 Capture/Compare Flag
PCA0CN0_CCF1 BIT PCA0CN0.1 ; PCA Module 1 Capture/Compare Flag
PCA0CN0_CCF2 BIT PCA0CN0.2 ; PCA Module 2 Capture/Compare Flag
PCA0CN0_CCF3 BIT PCA0CN0.3 ; PCA Module 3 Capture/Compare Flag
PCA0CN0_CCF4 BIT PCA0CN0.4 ; PCA Module 4 Capture/Compare Flag
PCA0CN0_CR   BIT PCA0CN0.6 ; PCA Counter/Timer Run Control    
PCA0CN0_CF   BIT PCA0CN0.7 ; PCA Counter/Timer Overflow Flag  

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
SCON0_RI    BIT SCON0.0 ; Receive Interrupt Flag             
SCON0_TI    BIT SCON0.1 ; Transmit Interrupt Flag            
SCON0_RB8   BIT SCON0.2 ; Ninth Receive Bit                  
SCON0_TB8   BIT SCON0.3 ; Ninth Transmission Bit             
SCON0_REN   BIT SCON0.4 ; Receive Enable                     
SCON0_MCE   BIT SCON0.5 ; Multiprocessor Communication Enable
SCON0_SMODE BIT SCON0.7 ; Serial Port 0 Operation Mode       

; SMB0CN0 0xC0 (SMBus 0 Control)
SMB0CN0_SI      BIT SMB0CN0.0 ; SMBus Interrupt Flag            
SMB0CN0_ACK     BIT SMB0CN0.1 ; SMBus Acknowledge               
SMB0CN0_ARBLOST BIT SMB0CN0.2 ; SMBus Arbitration Lost Indicator
SMB0CN0_ACKRQ   BIT SMB0CN0.3 ; SMBus Acknowledge Request       
SMB0CN0_STO     BIT SMB0CN0.4 ; SMBus Stop Flag                 
SMB0CN0_STA     BIT SMB0CN0.5 ; SMBus Start Flag                
SMB0CN0_TXMODE  BIT SMB0CN0.6 ; SMBus Transmit Mode Indicator   
SMB0CN0_MASTER  BIT SMB0CN0.7 ; SMBus Master/Slave Indicator    

; SMB1CN0 0xC0 (SMBus 1 Control)
SMB1CN0_SI      BIT SMB1CN0.0 ; SMBus Interrupt Flag            
SMB1CN0_ACK     BIT SMB1CN0.1 ; SMBus Acknowledge               
SMB1CN0_ARBLOST BIT SMB1CN0.2 ; SMBus Arbitration Lost Indicator
SMB1CN0_ACKRQ   BIT SMB1CN0.3 ; SMBus Acknowledge Request       
SMB1CN0_STO     BIT SMB1CN0.4 ; SMBus Stop Flag                 
SMB1CN0_STA     BIT SMB1CN0.5 ; SMBus Start Flag                
SMB1CN0_TXMODE  BIT SMB1CN0.6 ; SMBus Transmit Mode Indicator   
SMB1CN0_MASTER  BIT SMB1CN0.7 ; SMBus Master/Slave Indicator    

; SPI0CN0 0xF8 (SPI0 Control)
SPI0CN0_SPIEN  BIT SPI0CN0.0 ; SPI0 Enable            
SPI0CN0_TXBMT  BIT SPI0CN0.1 ; Transmit Buffer Empty  
SPI0CN0_NSSMD0 BIT SPI0CN0.2 ; Slave Select Mode Bit 0
SPI0CN0_NSSMD1 BIT SPI0CN0.3 ; Slave Select Mode Bit 1
SPI0CN0_RXOVRN BIT SPI0CN0.4 ; Receive Overrun Flag   
SPI0CN0_MODF   BIT SPI0CN0.5 ; Mode Fault Flag        
SPI0CN0_WCOL   BIT SPI0CN0.6 ; Write Collision Flag   
SPI0CN0_SPIF   BIT SPI0CN0.7 ; SPI0 Interrupt Flag    

; TCON 0x88 (Timer 0/1 Control)
TCON_IT0 BIT TCON.0 ; Interrupt 0 Type Select
TCON_IE0 BIT TCON.1 ; External Interrupt 0   
TCON_IT1 BIT TCON.2 ; Interrupt 1 Type Select
TCON_IE1 BIT TCON.3 ; External Interrupt 1   
TCON_TR0 BIT TCON.4 ; Timer 0 Run Control    
TCON_TF0 BIT TCON.5 ; Timer 0 Overflow Flag  
TCON_TR1 BIT TCON.6 ; Timer 1 Run Control    
TCON_TF1 BIT TCON.7 ; Timer 1 Overflow Flag  

; TMR2CN0 0xC8 (Timer 2 Control 0)
TMR2CN0_T2XCLK  BIT TMR2CN0.0 ; Timer 2 External Clock Select    
TMR2CN0_T2CSS   BIT TMR2CN0.1 ; Timer 2 Capture Source Select    
TMR2CN0_TR2     BIT TMR2CN0.2 ; Timer 2 Run Control              
TMR2CN0_T2SPLIT BIT TMR2CN0.3 ; Timer 2 Split Mode Enable        
TMR2CN0_TF2CEN  BIT TMR2CN0.4 ; Timer 2 Capture Enable           
TMR2CN0_TF2LEN  BIT TMR2CN0.5 ; Timer 2 Low Byte Interrupt Enable
TMR2CN0_TF2L    BIT TMR2CN0.6 ; Timer 2 Low Byte Overflow Flag   
TMR2CN0_TF2H    BIT TMR2CN0.7 ; Timer 2 High Byte Overflow Flag  

; TMR5CN0 0xC8 (Timer 5 Control 0)
TMR5CN0_T5XCLK  BIT TMR5CN0.0 ; Timer 5 External Clock Select    
TMR5CN0_TR5     BIT TMR5CN0.2 ; Timer 5 Run Control              
TMR5CN0_T5SPLIT BIT TMR5CN0.3 ; Timer 5 Split Mode Enable        
TMR5CN0_TF5LEN  BIT TMR5CN0.5 ; Timer 5 Low Byte Interrupt Enable
TMR5CN0_TF5L    BIT TMR5CN0.6 ; Timer 5 Low Byte Overflow Flag   
TMR5CN0_TF5H    BIT TMR5CN0.7 ; Timer 5 High Byte Overflow Flag  

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
USB0_IRQn    EQU 8  ; USB0                  
ADC0WC_IRQn  EQU 9  ; ADC0 Window Compare   
ADC0EOC_IRQn EQU 10 ; ADC0 End of Conversion
PCA0_IRQn    EQU 11 ; PCA0                  
CMP0_IRQn    EQU 12 ; Comparator 0          
CMP1_IRQn    EQU 13 ; Comparator 1          
TIMER3_IRQn  EQU 14 ; Timer 3 Overflow      
VBUSLVL_IRQn EQU 15 ; VBUS Level            
UART1_IRQn   EQU 16 ; UART 1                
SMBUS1_IRQn  EQU 18 ; SMBus 1               
TIMER4_IRQn  EQU 19 ; Timer 4 Overflow      
TIMER5_IRQn  EQU 20 ; Timer 5 Overflow      

;------------------------------------------------------------------------------
; SFR Page Definitions
;------------------------------------------------------------------------------
LEGACY_PAGE  EQU 000H ; Legacy SFR Page                   
CONFIG_PAGE  EQU 00FH ; System and Port Configuration Page
SMB1_PAGE    EQU 00FH ; SMBus 1 Page                      
