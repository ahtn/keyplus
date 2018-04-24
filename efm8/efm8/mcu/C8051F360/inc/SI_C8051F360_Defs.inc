;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  C8051F360_GQ
;  C8051F361_GQ
;  C8051F362_GM
;  C8051F363_GQ
;  C8051F364_GQ
;  C8051F365_GM
;  C8051F366_GQ
;  C8051F367_GM
;  C8051F368_GQ
;  C8051F369_GM

;-----------------------------------------------------------------------------
; Register Definitions
;-----------------------------------------------------------------------------
ACC      DATA 0E0H; Accumulator                              
ADC0CF   DATA 0BCH; ADC0 Configuration                       
ADC0CN   DATA 0E8H; ADC0 Control                             
ADC0GTH  DATA 0C4H; ADC0 Greater-Than High Byte              
ADC0GTL  DATA 0C3H; ADC0 Greater-Than Low Byte               
ADC0H    DATA 0BEH; ADC0 Data Word High Byte                 
ADC0L    DATA 0BDH; ADC0 Data Word Low Byte                  
ADC0LTH  DATA 0C6H; ADC0 Less-Than High Byte                 
ADC0LTL  DATA 0C5H; ADC0 Less-Than Low Byte                  
AMX0N    DATA 0BAH; AMUX0 Negative Multiplexer Selection     
AMX0P    DATA 0BBH; AMUX0 Positive Multiplexer Selection     
B        DATA 0F0H; B Register                               
CCH0CN   DATA 084H; Cache Control                            
CCH0LC   DATA 0D2H; Cache Lock Control                       
CCH0MA   DATA 0D3H; Cache Miss Accumulator                   
CCH0TN   DATA 0C9H; Cache Tuning                             
CKCON    DATA 08EH; Clock Control                            
CLKSEL   DATA 08FH; Clock Select                             
CPT0CN   DATA 09BH; Comparator 0 Control                     
CPT0MD   DATA 09DH; Comparator 0 Mode                        
CPT0MX   DATA 09FH; Comparator 0 Multiplexer Selection       
CPT1CN   DATA 09AH; Comparator 1 Control                     
CPT1MD   DATA 09CH; Comparator 1 Mode                        
CPT1MX   DATA 09EH; Comparator 1 Multiplexer Selection       
DPH      DATA 083H; Data Pointer High                        
DPL      DATA 082H; Data Pointer Low                         
EIE1     DATA 0E6H; Extended Interrupt Enable 1              
EIE2     DATA 0E7H; Extended Interrupt Enable 2              
EIP1     DATA 0CEH; Extended Interrupt Priority 1            
EIP2     DATA 0CFH; Extended Interrupt Priority 2            
EMI0CF   DATA 0C7H; External Memory Configuration            
EMI0CN   DATA 0AAH; External Memory Interface Control        
EMI0TC   DATA 0F7H; External Memory Timing Control           
FLKEY    DATA 0B7H; Flash Lock and Key                       
FLSCL    DATA 0B6H; Flash Scale                              
FLSTAT   DATA 0ACH; Flash Status                             
IDA0CN   DATA 0B9H; IDAC0 Control                            
IDA0H    DATA 097H; IDAC0 Data High Byte                     
IDA0L    DATA 096H; IDAC0 Data Low Byte                      
IE       DATA 0A8H; Interrupt Enable                         
IP       DATA 0B8H; Interrupt Priority                       
IT01CF   DATA 0E4H; INT0/INT1 Configuration                  
MAC0ACC0 DATA 0D2H; Accumulator Byte 0                       
MAC0ACC1 DATA 0D3H; Accumulator Byte 1                       
MAC0ACC2 DATA 0D4H; Accumulator Byte 2                       
MAC0ACC3 DATA 0D5H; Accumulator Byte 3                       
MAC0AH   DATA 0A5H; Operand A High Byte                      
MAC0AL   DATA 0A4H; Operand A Low Byte                       
MAC0BH   DATA 0F2H; Operand B High Byte                      
MAC0BL   DATA 0F1H; Operand B Low Byte                       
MAC0CF   DATA 0D7H; MAC0 Configuration                       
MAC0OVR  DATA 0D6H; Accumulator Overflow Byte                
MAC0RNDH DATA 0AFH; Rounded Result High Byte                 
MAC0RNDL DATA 0AEH; Rounded Result Low Byte                  
MAC0STA  DATA 0CFH; MAC0 Status                              
OSCICL   DATA 0BFH; High Frequency Oscillator Calibration    
OSCICN   DATA 0B7H; High Frequency Oscillator Control        
OSCLCN   DATA 0ADH; Internal Low Frequency Oscillator Control
OSCXCN   DATA 0B6H; External Oscillator Control              
P0       DATA 080H; Port 0 Pin Latch                         
P0MASK   DATA 0F4H; Port 0 Mask                              
P0MAT    DATA 0F3H; Port 0 Match                             
P0MDIN   DATA 0F1H; Port 0 Input Mode                        
P0MDOUT  DATA 0A4H; Port 0 Output Mode                       
P0SKIP   DATA 0D4H; Port 0 Skip                              
P1       DATA 090H; Port 1 Pin Latch                         
P1MASK   DATA 0E2H; Port 1 Mask                              
P1MAT    DATA 0E1H; Port 1 Match                             
P1MDIN   DATA 0F2H; Port 1 Input Mode                        
P1MDOUT  DATA 0A5H; Port 1 Output Mode                       
P1SKIP   DATA 0D5H; Port 1 Skip                              
P2       DATA 0A0H; Port 2 Pin Latch                         
P2MASK   DATA 0B2H; Port 2 Mask                              
P2MAT    DATA 0B1H; Port 2 Match                             
P2MDIN   DATA 0F3H; Port 2 Input Mode                        
P2MDOUT  DATA 0A6H; Port 2 Output Mode                       
P2SKIP   DATA 0D6H; Port 2 Skip                              
P3       DATA 0B0H; Port 3 Pin Latch                         
P3MDIN   DATA 0F4H; Port 3 Input Mode                        
P3MDOUT  DATA 0AFH; Port 3 Output Mode                       
P3SKIP   DATA 0D7H; Port 3 Skip                              
P4       DATA 0B5H; Port 4 Pin Latch                         
P4MDOUT  DATA 0AEH; Port 4 Output Mode                       
PCA0CN   DATA 0D8H; PCA Control                              
PCA0CPH0 DATA 0FCH; PCA Channel 0 Capture Module High Byte   
PCA0CPH1 DATA 0EAH; PCA Channel 1 Capture Module High Byte   
PCA0CPH2 DATA 0ECH; PCA Channel 2 Capture Module High Byte   
PCA0CPH3 DATA 0EEH; PCA Channel 3 Capture Module High Byte   
PCA0CPH4 DATA 0FEH; PCA Channel 4 Capture Module High Byte   
PCA0CPH5 DATA 0F6H; PCA Channel 5 Capture Module High Byte   
PCA0CPL0 DATA 0FBH; PCA Channel 0 Capture Module Low Byte    
PCA0CPL1 DATA 0E9H; PCA Channel 1 Capture Module Low Byte    
PCA0CPL2 DATA 0EBH; PCA Channel 2 Capture Module Low Byte    
PCA0CPL3 DATA 0EDH; PCA Channel 3 Capture Module Low Byte    
PCA0CPL4 DATA 0FDH; PCA Channel 4 Capture Module Low Byte    
PCA0CPL5 DATA 0F5H; PCA Channel 5 Capture Module Low Byte    
PCA0CPM0 DATA 0DAH; PCA Channel 0 Capture/Compare Mode 0     
PCA0CPM1 DATA 0DBH; PCA Channel 1 Capture/Compare Mode       
PCA0CPM2 DATA 0DCH; PCA Channel 2 Capture/Compare Mode       
PCA0CPM3 DATA 0DDH; PCA Channel 3 Capture/Compare Mode       
PCA0CPM4 DATA 0DEH; PCA Channel 4 Capture/Compare Mode       
PCA0CPM5 DATA 0DFH; PCA Channel 5 Capture/Compare Mode       
PCA0H    DATA 0FAH; PCA Counter/Timer High Byte              
PCA0L    DATA 0F9H; PCA Counter/Timer Low Byte               
PCA0MD   DATA 0D9H; PCA Mode                                 
PCON     DATA 087H; Power Control                            
PLL0CN   DATA 0B3H; PLL Control                              
PLL0DIV  DATA 0A9H; PLL Divider                              
PLL0FLT  DATA 0B2H; PLL Filter                               
PLL0MUL  DATA 0B1H; PLL Multiplier                           
PSCTL    DATA 08FH; Program Store Control                    
PSW      DATA 0D0H; Program Status Word                      
REF0CN   DATA 0D1H; Voltage Reference Control                
RSTSRC   DATA 0EFH; Reset Source                             
SBUF0    DATA 099H; UART0 Serial Port Data Buffer            
SCON0    DATA 098H; UART0 Serial Port Control                
SFR0CN   DATA 0E5H; SFR Page Control                         
SFRLAST  DATA 086H; SFR Page Last                            
SFRNEXT  DATA 085H; SFR Page Next                            
SFRPAGE  DATA 0A7H; SFR Page                                 
SMB0CF   DATA 0C1H; SMBus 0 Configuration                    
SMB0CN   DATA 0C0H; SMBus 0 Control                          
SMB0DAT  DATA 0C2H; SMBus 0 Data                             
SP       DATA 081H; Stack Pointer                            
SPI0CFG  DATA 0A1H; SPI0 Configuration                       
SPI0CKR  DATA 0A2H; SPI0 Clock Rate                          
SPI0CN   DATA 0F8H; SPI0 Control                             
SPI0DAT  DATA 0A3H; SPI0 Data                                
TCON     DATA 088H; Timer 0/1 Control                        
TH0      DATA 08CH; Timer 0 High Byte                        
TH1      DATA 08DH; Timer 1 High Byte                        
TL0      DATA 08AH; Timer 0 Low Byte                         
TL1      DATA 08BH; Timer 1 Low Byte                         
TMOD     DATA 089H; Timer 0/1 Mode                           
TMR2CN   DATA 0C8H; Timer 2 Control                          
TMR2H    DATA 0CDH; Timer 2 High Byte                        
TMR2L    DATA 0CCH; Timer 2 Low Byte                         
TMR2RLH  DATA 0CBH; Timer 2 Reload High Byte                 
TMR2RLL  DATA 0CAH; Timer 2 Reload Low Byte                  
TMR3CN   DATA 091H; Timer 3 Control                          
TMR3H    DATA 095H; Timer 3 High Byte                        
TMR3L    DATA 094H; Timer 3 Low Byte                         
TMR3RLH  DATA 093H; Timer 3 Reload High Byte                 
TMR3RLL  DATA 092H; Timer 3 Reload Low Byte                  
VDM0CN   DATA 0FFH; VDD Supply Monitor Control               
XBR0     DATA 0E1H; Port I/O Crossbar 0                      
XBR1     DATA 0E2H; Port I/O Crossbar 1                      

;------------------------------------------------------------------------------
; 16-bit Register Definitions (may not work on all compilers)
;------------------------------------------------------------------------------
ADC0GT  DATA 0C3H ; ADC0 Greater-Than Low Byte           
ADC0    DATA 0BDH ; ADC0 Data Word Low Byte              
ADC0LT  DATA 0C5H ; ADC0 Less-Than Low Byte              
DP      DATA 082H ; Data Pointer Low                     
MAC0A   DATA 0A4H ; Operand A Low Byte                   
MAC0B   DATA 0F1H ; Operand B Low Byte                   
MAC0RND DATA 0AEH ; Rounded Result Low Byte              
PCA0CP0 DATA 0FBH ; PCA Channel 0 Capture Module Low Byte
PCA0CP1 DATA 0E9H ; PCA Channel 1 Capture Module Low Byte
PCA0CP2 DATA 0EBH ; PCA Channel 2 Capture Module Low Byte
PCA0CP3 DATA 0EDH ; PCA Channel 3 Capture Module Low Byte
PCA0CP4 DATA 0FDH ; PCA Channel 4 Capture Module Low Byte
PCA0CP5 DATA 0F5H ; PCA Channel 5 Capture Module Low Byte
PCA0    DATA 0F9H ; PCA Counter/Timer Low Byte           
TMR2    DATA 0CCH ; Timer 2 Low Byte                     
TMR2RL  DATA 0CAH ; Timer 2 Reload Low Byte              
TMR3    DATA 094H ; Timer 3 Low Byte                     
TMR3RL  DATA 092H ; Timer 3 Reload Low Byte              

;------------------------------------------------------------------------------
; Indirect Register Definitions
;------------------------------------------------------------------------------

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
ADC0CN_ADCM2  BIT ADC0CN.2 ; Start of Conversion Mode Select Bit 2
ADC0CN_ADWINT BIT ADC0CN.3 ; Window Compare Interrupt Flag        
ADC0CN_ADBUSY BIT ADC0CN.4 ; ADC Busy                             
ADC0CN_ADINT  BIT ADC0CN.5 ; Conversion Complete Interrupt Flag   
ADC0CN_ADTM   BIT ADC0CN.6 ; Track Mode                           
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
ADC0WC_IRQn  EQU 9  ; ADC0 Window Compare   
ADC0EOC_IRQn EQU 10 ; ADC0 End of Conversion
PCA0_IRQn    EQU 11 ; PCA0                  
CMP0_IRQn    EQU 12 ; Comparator 0          
CMP1_IRQn    EQU 13 ; Comparator 1          
TIMER3_IRQn  EQU 14 ; Timer 3 Overflow      
PMATCH_IRQn  EQU 16 ; Port Match            

;------------------------------------------------------------------------------
; SFR Page Definitions
;------------------------------------------------------------------------------
ADC0_PAGE     EQU 000H ;                                   
CMP0_PAGE     EQU 000H ; Comparator 0 Page                 
CMP1_PAGE     EQU 000H ; Comparator 1 Page                 
DAC0_PAGE     EQU 000H ;                                   
LEGACY_PAGE   EQU 000H ; Legacy SFR Page                   
MAC0_PAGE     EQU 000H ; Multiply and Accumulate (MAC) Page
PCA0_PAGE     EQU 000H ;                                   
PMATCH_PAGE   EQU 000H ; Port Match Page                   
SMBUS0_PAGE   EQU 000H ;                                   
SPI0_PAGE     EQU 000H ;                                   
TIMER01_PAGE  EQU 000H ; Timer 0/1 Page                    
TIMER2_PAGE   EQU 000H ;                                   
TIMER3_PAGE   EQU 000H ;                                   
UART0_PAGE    EQU 000H ; UART0 Page                        
CONFIG_PAGE   EQU 00FH ; System and Port Configuration Page
EMIF0_PAGE    EQU 00FH ; External Memory Interface Page    
PLL0_PAGE     EQU 00FH ;                                   
