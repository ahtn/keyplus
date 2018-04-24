;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  C8051F300_GM
;  C8051F300_GS
;  C8051F301_GM
;  C8051F301_GS
;  C8051F302_GM
;  C8051F302_GS
;  C8051F303_GM
;  C8051F303_GS
;  C8051F304_GM
;  C8051F304_GS
;  C8051F305_GM
;  C8051F305_GS

;-----------------------------------------------------------------------------
; Register Definitions
;-----------------------------------------------------------------------------
ACC      DATA 0E0H; Accumulator                           
ADC0     DATA 0BEH; ADC0 Data Word                        
ADC0CF   DATA 0BCH; ADC0 Configuration                    
ADC0CN   DATA 0E8H; ADC0 Control                          
ADC0GT   DATA 0C4H; ADC0 Greater-Than Threshold           
ADC0LT   DATA 0C6H; ADC0 Less-Than Threshold              
AMX0SL   DATA 0BBH; AMUX0 Multiplexer Selection           
B        DATA 0F0H; B Register                            
CKCON    DATA 08EH; Clock Control                         
CPT0CN   DATA 0F8H; Comparator 0 Control                  
CPT0MD   DATA 09DH; Comparator 0 Mode                     
CPT0MX   DATA 09FH; Comparator 0 Multiplexer Selection    
DPH      DATA 083H; Data Pointer High                     
DPL      DATA 082H; Data Pointer Low                      
EIE1     DATA 0E6H; Extended Interrupt Enable 1           
EIP1     DATA 0F6H; Extended Interrupt Priority 1         
FLKEY    DATA 0B7H; Flash Lock and Key                    
FLSCL    DATA 0B6H; Flash Scale                           
IE       DATA 0A8H; Interrupt Enable                      
IP       DATA 0B8H; Interrupt Priority                    
IT01CF   DATA 0E4H; INT0/INT1 Configuration               
OSCICL   DATA 0B3H; High Frequency Oscillator Calibration 
OSCICN   DATA 0B2H; High Frequency Oscillator Control     
OSCXCN   DATA 0B1H; External Oscillator Control           
P0       DATA 080H; Port 0 Pin Latch                      
P0MDIN   DATA 0F1H; Port 0 Input Mode                     
P0MDOUT  DATA 0A4H; Port 0 Output Mode                    
PCA0CN   DATA 0D8H; PCA Control                           
PCA0CPH0 DATA 0FCH; PCA Channel 0 Capture Module High Byte
PCA0CPH1 DATA 0EAH; PCA Channel 1 Capture Module High Byte
PCA0CPH2 DATA 0ECH; PCA Channel 2 Capture Module High Byte
PCA0CPL0 DATA 0FBH; PCA Channel 0 Capture Module Low Byte 
PCA0CPL1 DATA 0E9H; PCA Channel 1 Capture Module Low Byte 
PCA0CPL2 DATA 0EBH; PCA Channel 2 Capture Module Low Byte 
PCA0CPM0 DATA 0DAH; PCA Channel 0 Capture/Compare Mode 0  
PCA0CPM1 DATA 0DBH; PCA Channel 1 Capture/Compare Mode    
PCA0CPM2 DATA 0DCH; PCA Channel 2 Capture/Compare Mode    
PCA0H    DATA 0FAH; PCA Counter/Timer High Byte           
PCA0L    DATA 0F9H; PCA Counter/Timer Low Byte            
PCA0MD   DATA 0D9H; PCA Mode                              
PCON     DATA 087H; Power Control                         
PSCTL    DATA 08FH; Program Store Control                 
PSW      DATA 0D0H; Program Status Word                   
REF0CN   DATA 0D1H; Voltage Reference Control             
RSTSRC   DATA 0EFH; Reset Source                          
SBUF0    DATA 099H; UART0 Serial Port Data Buffer         
SCON0    DATA 098H; UART0 Serial Port Control             
SMB0CF   DATA 0C1H; SMBus 0 Configuration                 
SMB0CN   DATA 0C0H; SMBus 0 Control                       
SMB0DAT  DATA 0C2H; SMBus 0 Data                          
SP       DATA 081H; Stack Pointer                         
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
XBR0     DATA 0E1H; Port I/O Crossbar 0                   
XBR1     DATA 0E2H; Port I/O Crossbar 1                   
XBR2     DATA 0E3H; Port I/O Crossbar 2                   

;------------------------------------------------------------------------------
; 16-bit Register Definitions (may not work on all compilers)
;------------------------------------------------------------------------------
DP      DATA 082H ; Data Pointer Low                     
PCA0CP0 DATA 0FBH ; PCA Channel 0 Capture Module Low Byte
PCA0CP1 DATA 0E9H ; PCA Channel 1 Capture Module Low Byte
PCA0CP2 DATA 0EBH ; PCA Channel 2 Capture Module Low Byte
PCA0    DATA 0F9H ; PCA Counter/Timer Low Byte           
TMR2    DATA 0CCH ; Timer 2 Low Byte                     
TMR2RL  DATA 0CAH ; Timer 2 Reload Low Byte              

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

; CPT0CN 0xF8 (Comparator 0 Control)
CPT0CN_CPHYN0 BIT CPT0CN.0 ; Comparator Negative Hysteresis Control Bit 0
CPT0CN_CPHYN1 BIT CPT0CN.1 ; Comparator Negative Hysteresis Control Bit 1
CPT0CN_CPHYP0 BIT CPT0CN.2 ; Comparator Positive Hysteresis Control Bit 0
CPT0CN_CPHYP1 BIT CPT0CN.3 ; Comparator Positive Hysteresis Control Bit 1
CPT0CN_CPFIF  BIT CPT0CN.4 ; Comparator Falling-Edge Flag                
CPT0CN_CPRIF  BIT CPT0CN.5 ; Comparator Rising-Edge Flag                 
CPT0CN_CPOUT  BIT CPT0CN.6 ; Comparator Output State Flag                
CPT0CN_CPEN   BIT CPT0CN.7 ; Comparator Enable                           

; IE 0xA8 (Interrupt Enable)
IE_EX0   BIT IE.0 ; External Interrupt 0 Enable
IE_ET0   BIT IE.1 ; Timer 0 Interrupt Enable   
IE_EX1   BIT IE.2 ; External Interrupt 1 Enable
IE_ET1   BIT IE.3 ; Timer 1 Interrupt Enable   
IE_ES0   BIT IE.4 ; UART0 Interrupt Enable     
IE_ET2   BIT IE.5 ; Timer 2 Interrupt Enable   
IE_IEGF0 BIT IE.6 ; General Purpose Flag 0     
IE_EA    BIT IE.7 ; All Interrupts Enable      

; IP 0xB8 (Interrupt Priority)
IP_PX0 BIT IP.0 ; External Interrupt 0 Priority Control
IP_PT0 BIT IP.1 ; Timer 0 Interrupt Priority Control   
IP_PX1 BIT IP.2 ; External Interrupt 1 Priority Control
IP_PT1 BIT IP.3 ; Timer 1 Interrupt Priority Control   
IP_PS0 BIT IP.4 ; UART0 Interrupt Priority Control     
IP_PT2 BIT IP.5 ; Timer 2 Interrupt Priority Control   

; P0 0x80 (Port 0 Pin Latch)
P0_B0 BIT P0.0 ; Port 0 Bit 0 Latch
P0_B1 BIT P0.1 ; Port 0 Bit 1 Latch
P0_B2 BIT P0.2 ; Port 0 Bit 2 Latch
P0_B3 BIT P0.3 ; Port 0 Bit 3 Latch
P0_B4 BIT P0.4 ; Port 0 Bit 4 Latch
P0_B5 BIT P0.5 ; Port 0 Bit 5 Latch
P0_B6 BIT P0.6 ; Port 0 Bit 6 Latch
P0_B7 BIT P0.7 ; Port 0 Bit 7 Latch

; PCA0CN 0xD8 (PCA Control)
PCA0CN_CCF0 BIT PCA0CN.0 ; PCA Module 0 Capture/Compare Flag
PCA0CN_CCF1 BIT PCA0CN.1 ; PCA Module 1 Capture/Compare Flag
PCA0CN_CCF2 BIT PCA0CN.2 ; PCA Module 2 Capture/Compare Flag
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
TMR2CN_TF2LEN  BIT TMR2CN.5 ; Timer 2 Low Byte Interrupt Enable
TMR2CN_TF2L    BIT TMR2CN.6 ; Timer 2 Low Byte Overflow Flag   
TMR2CN_TF2H    BIT TMR2CN.7 ; Timer 2 High Byte Overflow Flag  

;------------------------------------------------------------------------------
; Interrupt Definitions
;------------------------------------------------------------------------------
INT0_IRQn     EQU 0  ; External Interrupt 0     
TIMER0_IRQn   EQU 1  ; Timer 0 Overflow         
INT1_IRQn     EQU 2  ; External Interrupt 1     
TIMER1_IRQn   EQU 3  ; Timer 1 Overflow         
UART0_IRQn    EQU 4  ; UART 0                   
TIMER2_IRQn   EQU 5  ; Timer 2 Overflow         
SMBUS0_IRQn   EQU 6  ; SMBus 0                  
ADC0WC_IRQn   EQU 7  ; ADC0 Window Compare      
ADC0EOC_IRQn  EQU 8  ; ADC0 End of Conversion   
PCA0_IRQn     EQU 9  ; PCA0                     
CMP0FALL_IRQn EQU 10 ; Comparator 0 Falling Edge
CMP0RISE_IRQn EQU 11 ; Comparator 0 Rising Edge 
