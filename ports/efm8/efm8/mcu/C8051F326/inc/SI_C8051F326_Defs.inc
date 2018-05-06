;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  C8051F326_GM
;  C8051F327_GM

;-----------------------------------------------------------------------------
; Register Definitions
;-----------------------------------------------------------------------------
ACC     DATA 0E0H; Accumulator                              
B       DATA 0F0H; B Register                               
CKCON   DATA 08EH; Clock Control                            
CLKMUL  DATA 0B9H; Clock Multiplier Control                 
CLKSEL  DATA 0A9H; Clock Select                             
DPH     DATA 083H; Data Pointer High                        
DPL     DATA 082H; Data Pointer Low                         
EIE1    DATA 0E6H; Extended Interrupt Enable 1              
EIE2    DATA 0E7H; Extended Interrupt Enable 2              
EIP1    DATA 0F6H; Extended Interrupt Priority 1            
EIP2    DATA 0F7H; Extended Interrupt Priority 2            
EMI0CN  DATA 0AAH; External Memory Interface Control        
FLKEY   DATA 0B7H; Flash Lock and Key                       
FLSCL   DATA 0B6H; Flash Scale                              
GPIOCN  DATA 0E2H; Global Port I/O Control                  
IE      DATA 0A8H; Interrupt Enable                         
IP      DATA 0B8H; Interrupt Priority                       
OSCICL  DATA 0B3H; High Frequency Oscillator Calibration    
OSCICN  DATA 0B2H; High Frequency Oscillator Control        
OSCLCN  DATA 0E3H; Internal Low Frequency Oscillator Control
P0      DATA 080H; Port 0 Pin Latch                         
P0MDOUT DATA 0A4H; Port 0 Output Mode                       
P2      DATA 0A0H; Port 2 Pin Latch                         
P2MDOUT DATA 0A6H; Port 2 Output Mode                       
P3      DATA 0B0H; Port 3 Pin Latch                         
P3MDOUT DATA 0A7H; Port 3 Output Mode                       
PCON    DATA 087H; Power Control                            
PSCTL   DATA 08FH; Program Store Control                    
PSW     DATA 0D0H; Program Status Word                      
REG0CN  DATA 0C9H; Voltage Regulator Control                
RSTSRC  DATA 0EFH; Reset Source                             
SBCON0  DATA 091H; UART0 Baud Rate Generator Control        
SBRLH0  DATA 094H; UART0 Baud Rate Generator High Byte      
SBRLL0  DATA 093H; UART0 Baud Rate Generator Low Byte       
SBUF0   DATA 099H; UART0 Serial Port Data Buffer            
SCON0   DATA 098H; UART0 Serial Port Control                
SMOD0   DATA 09AH; UART0 Mode                               
SP      DATA 081H; Stack Pointer                            
TCON    DATA 088H; Timer 0/1 Control                        
TH0     DATA 08CH; Timer 0 High Byte                        
TH1     DATA 08DH; Timer 1 High Byte                        
TL0     DATA 08AH; Timer 0 Low Byte                         
TL1     DATA 08BH; Timer 1 Low Byte                         
TMOD    DATA 089H; Timer 0/1 Mode                           
USB0ADR DATA 096H; USB0 Indirect Address                    
USB0DAT DATA 097H; USB0 Data                                
USB0XCN DATA 0D7H; USB0 Transceiver Control                 
VDM0CN  DATA 0FFH; VDD Supply Monitor Control               

;------------------------------------------------------------------------------
; 16-bit Register Definitions (may not work on all compilers)
;------------------------------------------------------------------------------
DP DATA 082H ; Data Pointer Low

;------------------------------------------------------------------------------
; Indirect Register Definitions
;------------------------------------------------------------------------------
CLKREC    EQU 00FH ; USB0 Clock Recovery Control       
CMIE      EQU 00BH ; USB0 Common Interrupt Enable      
CMINT     EQU 006H ; USB0 Common Interrupt             
E0CNT     EQU 016H ; USB0 Endpoint0 Data Count         
E0CSR     EQU 011H ; USB0 Endpoint0 Control            
EINCSRH   EQU 012H ; USB0 IN Endpoint Control High     
EINCSRL   EQU 011H ; USB0 IN Endpoint Control          
EOUTCNTH  EQU 017H ; USB0 OUT Endpoint Count High      
EOUTCNTL  EQU 016H ; USB0 OUT Endpoint Count           
EOUTCSRH  EQU 015H ; USB0 OUT Endpoint Control High    
EOUTCSRL  EQU 014H ; USB0 OUT Endpoint Control         
FADDR     EQU 000H ; USB0 Function Address             
FIFO0     EQU 020H ; USB0 Endpoint 0 FIFO Access       
FIFO1     EQU 021H ; USB0 Endpoint 1 FIFO Access       
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
IE_EX0 BIT IE.0 ; External Interrupt 0 Enable
IE_ET0 BIT IE.1 ; Timer 0 Interrupt Enable   
IE_EX1 BIT IE.2 ; External Interrupt 1 Enable
IE_ET1 BIT IE.3 ; Timer 1 Interrupt Enable   
IE_ES0 BIT IE.4 ; UART0 Interrupt Enable     
IE_EA  BIT IE.7 ; All Interrupts Enable      

; IP 0xB8 (Interrupt Priority)
IP_PX0 BIT IP.0 ; External Interrupt 0 Priority Control
IP_PT0 BIT IP.1 ; Timer 0 Interrupt Priority Control   
IP_PX1 BIT IP.2 ; External Interrupt 1 Priority Control
IP_PT1 BIT IP.3 ; Timer 1 Interrupt Priority Control   
IP_PS0 BIT IP.4 ; UART0 Interrupt Priority Control     

; P0 0x80 (Port 0 Pin Latch)
P0_B0 BIT P0.0 ; Port 0 Bit 0 Latch
P0_B1 BIT P0.1 ; Port 0 Bit 1 Latch
P0_B2 BIT P0.2 ; Port 0 Bit 2 Latch
P0_B3 BIT P0.3 ; Port 0 Bit 3 Latch
P0_B4 BIT P0.4 ; Port 0 Bit 4 Latch
P0_B5 BIT P0.5 ; Port 0 Bit 5 Latch
P0_B6 BIT P0.6 ; Port 0 Bit 6 Latch
P0_B7 BIT P0.7 ; Port 0 Bit 7 Latch

; P2 0xA0 (Port 2 Pin Latch)
P2_B0 BIT P2.0 ; Port 2 Bit 0 Latch
P2_B1 BIT P2.1 ; Port 2 Bit 1 Latch
P2_B2 BIT P2.2 ; Port 2 Bit 2 Latch
P2_B3 BIT P2.3 ; Port 2 Bit 3 Latch
P2_B4 BIT P2.4 ; Port 2 Bit 4 Latch
P2_B5 BIT P2.5 ; Port 2 Bit 5 Latch

; P3 0xB0 (Port 3 Pin Latch)
P3_B0 BIT P3.0 ; Port 3 Bit 0 Latch

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
SCON0_PERR BIT SCON0.6 ; Parity Error Flag        
SCON0_OVR  BIT SCON0.7 ; Receive FIFO Overrun Flag

; TCON 0x88 (Timer 0/1 Control)
TCON_IT0 BIT TCON.0 ; Interrupt 0 Type Select
TCON_IE0 BIT TCON.1 ; External Interrupt 0   
TCON_IT1 BIT TCON.2 ; Interrupt 1 Type Select
TCON_IE1 BIT TCON.3 ; External Interrupt 1   
TCON_TR0 BIT TCON.4 ; Timer 0 Run Control    
TCON_TF0 BIT TCON.5 ; Timer 0 Overflow Flag  
TCON_TR1 BIT TCON.6 ; Timer 1 Run Control    
TCON_TF1 BIT TCON.7 ; Timer 1 Overflow Flag  

;------------------------------------------------------------------------------
; Interrupt Definitions
;------------------------------------------------------------------------------
INT0_IRQn    EQU 0  ; External Interrupt 0
TIMER0_IRQn  EQU 1  ; Timer 0 Overflow    
INT1_IRQn    EQU 2  ; External Interrupt 1
TIMER1_IRQn  EQU 3  ; Timer 1 Overflow    
UART0_IRQn   EQU 4  ; UART 0              
USB0_IRQn    EQU 8  ; USB0                
VBUSLVL_IRQn EQU 15 ; VBUS Level          
