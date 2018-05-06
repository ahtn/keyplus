;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  C8051F120_GQ
;  C8051F121_GQ
;  C8051F122_GQ
;  C8051F123_GQ
;  C8051F124_GQ
;  C8051F125_GQ
;  C8051F126_GQ
;  C8051F127_GQ
;  C8051F130_GQ
;  C8051F131_GQ
;  C8051F132_GQ
;  C8051F133_GQ

;-----------------------------------------------------------------------------
; Register Definitions
;-----------------------------------------------------------------------------
ACC      DATA 0E0H; Accumulator                           
ADC0CF   DATA 0BCH; ADC0 Configuration                    
ADC0CN   DATA 0E8H; ADC0 Control                          
ADC0GTH  DATA 0C5H; ADC0 Greater-Than High Byte           
ADC0GTL  DATA 0C4H; ADC0 Greater-Than Low Byte            
ADC0H    DATA 0BFH; ADC0 Data Word High Byte              
ADC0L    DATA 0BEH; ADC0 Data Word Low Byte               
ADC0LTH  DATA 0C7H; ADC0 Less-Than High Byte              
ADC0LTL  DATA 0C6H; ADC0 Less-Than Low Byte               
ADC2     DATA 0BEH; ADC2 Data Word                        
ADC2CF   DATA 0BCH; ADC2 Configuration                    
ADC2CN   DATA 0E8H; ADC2 Control                          
ADC2GT   DATA 0C4H; ADC2 Greater-Than Data Byte           
ADC2LT   DATA 0C6H; ADC2 Less-Than Data Byte              
AMX0CF   DATA 0BAH; AMUX0 Configuration                   
AMX0SL   DATA 0BBH; AMUX0 Channel Select                  
AMX2CF   DATA 0BAH; AMUX2 Configuration                   
AMX2SL   DATA 0BBH; AMUX2 Channel Select                  
B        DATA 0F0H; B Register                            
CCH0CN   DATA 0A1H; Cache Control                         
CCH0LC   DATA 0A3H; Cache Lock Control                    
CCH0MA   DATA 09AH; Cache Miss Accumulator                
CCH0TN   DATA 0A2H; Cache Tuning                          
CKCON    DATA 08EH; Clock Control                         
CLKSEL   DATA 097H; Clock Select                          
CPT0CN   DATA 088H; Comparator 0 Control                  
CPT0MD   DATA 089H; Comparator 0 Mode                     
CPT1CN   DATA 088H; Comparator 1 Control                  
CPT1MD   DATA 089H; Comparator 1 Mode                     
DAC0CN   DATA 0D4H; DAC0 Control                          
DAC0H    DATA 0D3H; DAC0 Data High Byte                   
DAC0L    DATA 0D2H; DAC0 Data Low Byte                    
DAC1CN   DATA 0D4H; DAC1 Control                          
DAC1H    DATA 0D3H; DAC1 Data High Byte                   
DAC1L    DATA 0D2H; DAC1 Data Low Byte                    
DEVICEID DATA 004H; JTAG Device ID                        
DPH      DATA 083H; Data Pointer High                     
DPL      DATA 082H; Data Pointer Low                      
EIE1     DATA 0E6H; Extended Interrupt Enable 1           
EIE2     DATA 0E7H; Extended Interrupt Enable 2           
EIP1     DATA 0F6H; Extended Interrupt Priority 1 Low     
EIP2     DATA 0F7H; Extended Interrupt Priority 2         
EMI0CF   DATA 0A3H; External Memory Configuration         
EMI0CN   DATA 0A2H; External Memory Interface Control     
EMI0TC   DATA 0A1H; External Memory Timing Control        
FLACL    DATA 0B7H; Flash Access Limit                    
FLASHADR DATA 084H; JTAG Flash Address                    
FLASHCON DATA 082H; JTAG Flash Control                    
FLASHDAT DATA 083H; JTAG Flash Data                       
FLSCL    DATA 0B7H; Flash Scale                           
FLSTAT   DATA 088H; Flash Status                          
IE       DATA 0A8H; Interrupt Enable                      
IP       DATA 0B8H; Interrupt Priority                    
MAC0ACC0 DATA 093H; Accumulator Byte 0                    
MAC0ACC1 DATA 094H; Accumulator Byte 1                    
MAC0ACC2 DATA 095H; Accumulator Byte 2                    
MAC0ACC3 DATA 096H; Accumulator Byte 3                    
MAC0AH   DATA 0C2H; Operand A High Byte                   
MAC0AL   DATA 0C1H; Operand A Low Byte                    
MAC0BH   DATA 092H; Operand B High Byte                   
MAC0BL   DATA 091H; Operand B Low Byte                    
MAC0CF   DATA 0C3H; MAC0 Configuration                    
MAC0OVR  DATA 097H; Accumulator Overflow Byte             
MAC0RNDH DATA 0CFH; Rounded Result High Byte              
MAC0RNDL DATA 0CEH; Rounded Result Low Byte               
MAC0STA  DATA 0C0H; MAC0 Status                           
OSCICL   DATA 08BH; High Frequency Oscillator Calibration 
OSCICN   DATA 08AH; High Frequency Oscillator Control     
OSCXCN   DATA 08CH; External Oscillator Control           
P0       DATA 080H; Port 0 Pin Latch                      
P0MDOUT  DATA 0A4H; Port 0 Output Mode                    
P1       DATA 090H; Port 1 Pin Latch                      
P1MDIN   DATA 0ADH; Port 1 Input Mode                     
P1MDOUT  DATA 0A5H; Port 1 Output Mode                    
P2       DATA 0A0H; Port 2 Pin Latch                      
P2MDOUT  DATA 0A6H; Port 2 Output Mode                    
P3       DATA 0B0H; Port 3 Pin Latch                      
P3MDOUT  DATA 0A7H; Port 3 Output Mode                    
P4       DATA 0C8H; Port 4 Pin Latch                      
P4MDOUT  DATA 09CH; Port 4 Output Mode                    
P5       DATA 0D8H; Port 5 Pin Latch                      
P5MDOUT  DATA 09DH; Port 5 Output Mode                    
P6       DATA 0E8H; Port 6 Pin Latch                      
P6MDOUT  DATA 09EH; Port 6 Output Mode                    
P7       DATA 0F8H; Port 7 Pin Latch                      
P7MDOUT  DATA 09FH; Port 7 Output Mode                    
PCA0CN   DATA 0D8H; PCA Control                           
PCA0CPH0 DATA 0FCH; PCA Channel 0 Capture Module High Byte
PCA0CPH1 DATA 0FEH; PCA Channel 1 Capture Module High Byte
PCA0CPH2 DATA 0EAH; PCA Channel 2 Capture Module High Byte
PCA0CPH3 DATA 0ECH; PCA Channel 3 Capture Module High Byte
PCA0CPH4 DATA 0EEH; PCA Channel 4 Capture Module High Byte
PCA0CPH5 DATA 0E2H; PCA Channel 5 Capture Module High Byte
PCA0CPL0 DATA 0FBH; PCA Channel 0 Capture Module Low Byte 
PCA0CPL1 DATA 0FDH; PCA Channel 1 Capture Module Low Byte 
PCA0CPL2 DATA 0E9H; PCA Channel 2 Capture Module Low Byte 
PCA0CPL3 DATA 0EBH; PCA Channel 3 Capture Module Low Byte 
PCA0CPL4 DATA 0EDH; PCA Channel 4 Capture Module Low Byte 
PCA0CPL5 DATA 0E1H; PCA Channel 5 Capture Module Low Byte 
PCA0CPM0 DATA 0DAH; PCA Channel 0 Capture/Compare Mode    
PCA0CPM1 DATA 0DBH; PCA Channel 1 Capture/Compare Mode    
PCA0CPM2 DATA 0DCH; PCA Channel 2 Capture/Compare Mode    
PCA0CPM3 DATA 0DDH; PCA Channel 3 Capture/Compare Mode    
PCA0CPM4 DATA 0DEH; PCA Channel 4 Capture/Compare Mode    
PCA0CPM5 DATA 0DFH; PCA Channel 5 Capture/Compare Mode    
PCA0H    DATA 0FAH; PCA Counter/Timer High Byte           
PCA0L    DATA 0F9H; PCA Counter/Timer Low Byte            
PCA0MD   DATA 0D9H; PCA Mode                              
PCON     DATA 087H; Power Control                         
PLL0CN   DATA 089H; PLL Control                           
PLL0DIV  DATA 08DH; PLL Divider                           
PLL0FLT  DATA 08FH; PLL Filter                            
PLL0MUL  DATA 08EH; PLL Multiplier                        
PSBANK   DATA 0B1H; Program Space Bank Select             
PSCTL    DATA 08FH; Program Store Control                 
PSW      DATA 0D0H; Program Status Word                   
RCAP2H   DATA 0CBH; Timer 2 Capture Register High Byte    
RCAP2L   DATA 0CAH; Timer 2 Capture Register Low Byte     
RCAP3H   DATA 0CBH; Timer 3 Capture Register High Byte    
RCAP3L   DATA 0CAH; Timer 3 Capture Register Low Byte     
RCAP4H   DATA 0CBH; Timer 4 Capture Register High Byte    
RCAP4L   DATA 0CAH; Timer 4 Capture Register Low Byte     
REF0CN   DATA 0D1H; Voltage Reference Control             
RSTSRC   DATA 0EFH; Reset Source                          
SADDR0   DATA 0A9H; UART0 Slave Address                   
SADEN0   DATA 0B9H; UART0 Slave Address Enable            
SBUF0    DATA 099H; UART0 Serial Port Data Buffer         
SBUF1    DATA 099H; UART1 Serial Port Data Buffer         
SCON0    DATA 098H; UART0 Serial Port Control             
SCON1    DATA 098H; UART1 Serial Port Control             
SFRLAST  DATA 086H; SFR Page Last                         
SFRNEXT  DATA 085H; SFR Page Next                         
SFRPAGE  DATA 084H; SFR Page                              
SFRPGCN  DATA 096H; SFR Page Control                      
SMB0ADR  DATA 0C3H; SMBus 0 Address                       
SMB0CN   DATA 0C0H; SMBus 0 Control                       
SMB0CR   DATA 0CFH; SMBus 0 Clock Rate                    
SMB0DAT  DATA 0C2H; SMBus 0 Data                          
SMB0STA  DATA 0C1H; SMBus 0 Status                        
SP       DATA 081H; Stack Pointer                         
SPI0CFG  DATA 09AH; SPI0 Configuration                    
SPI0CKR  DATA 09DH; SPI0 Clock Rate                       
SPI0CN   DATA 0F8H; SPI0 Control                          
SPI0DAT  DATA 09BH; SPI0 Data                             
SSTA0    DATA 091H; UART0 Status and Clock Selection      
TCON     DATA 088H; Timer 0/1 Control                     
TH0      DATA 08CH; Timer 0 High Byte                     
TH1      DATA 08DH; Timer 1 High Byte                     
TL0      DATA 08AH; Timer 0 Low Byte                      
TL1      DATA 08BH; Timer 1 Low Byte                      
TMOD     DATA 089H; Timer 0/1 Mode                        
TMR2CF   DATA 0C9H; Timer 2 Configuration                 
TMR2CN   DATA 0C8H; Timer 2 Control                       
TMR2H    DATA 0CDH; Timer 2 High Byte                     
TMR2L    DATA 0CCH; Timer 2 Low Byte                      
TMR3CF   DATA 0C9H; Timer 3 Configuration                 
TMR3CN   DATA 0C8H; Timer 3 Control                       
TMR3H    DATA 0CDH; Timer 3 High Byte                     
TMR3L    DATA 0CCH; Timer 3 Low Byte                      
TMR4CF   DATA 0C9H; Timer 4 Configuration                 
TMR4CN   DATA 0C8H; Timer 4 Control                       
TMR4H    DATA 0CDH; Timer 4 High Byte                     
TMR4L    DATA 0CCH; Timer 4 Low Byte                      
WDTCN    DATA 0FFH; Watchdog Timer Control                
XBR0     DATA 0E1H; Port I/O Crossbar 0                   
XBR1     DATA 0E2H; Port I/O Crossbar 1                   
XBR2     DATA 0E3H; Port I/O Crossbar 2                   

;------------------------------------------------------------------------------
; 16-bit Register Definitions (may not work on all compilers)
;------------------------------------------------------------------------------
ADC0GT  DATA 0C4H ; ADC0 Greater-Than Low Byte           
ADC0    DATA 0BEH ; ADC0 Data Word Low Byte              
ADC0LT  DATA 0C6H ; ADC0 Less-Than Low Byte              
DP      DATA 082H ; Data Pointer Low                     
PCA0CP0 DATA 0FBH ; PCA Channel 0 Capture Module Low Byte
PCA0CP1 DATA 0FDH ; PCA Channel 1 Capture Module Low Byte
PCA0CP2 DATA 0E9H ; PCA Channel 2 Capture Module Low Byte
PCA0CP3 DATA 0EBH ; PCA Channel 3 Capture Module Low Byte
PCA0CP4 DATA 0EDH ; PCA Channel 4 Capture Module Low Byte
PCA0CP5 DATA 0E1H ; PCA Channel 5 Capture Module Low Byte
PCA0    DATA 0F9H ; PCA Counter/Timer Low Byte           

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
ADC0CN_ADLJST BIT ADC0CN.0 ; ADC Left Justify Select              
ADC0CN_ADWINT BIT ADC0CN.1 ; Window Compare Interrupt Flag        
ADC0CN_ADCM0  BIT ADC0CN.2 ; Start of Conversion Mode Select Bit 0
ADC0CN_ADCM1  BIT ADC0CN.3 ; Start of Conversion Mode Select Bit 1
ADC0CN_ADBUSY BIT ADC0CN.4 ; ADC Busy                             
ADC0CN_ADINT  BIT ADC0CN.5 ; Conversion Complete Interrupt Flag   
ADC0CN_ADTM   BIT ADC0CN.6 ; ADC Track Mode                       
ADC0CN_ADEN   BIT ADC0CN.7 ; ADC Enable                           

; ADC2CN 0xE8 (ADC2 Control)
ADC2CN_ADWINT BIT ADC2CN.0 ; Window Compare Interrupt Flag        
ADC2CN_ADCM0  BIT ADC2CN.1 ; Start of Conversion Mode Select Bit 0
ADC2CN_ADCM1  BIT ADC2CN.2 ; Start of Conversion Mode Select Bit 1
ADC2CN_ADCM2  BIT ADC2CN.3 ; Start of Conversion Mode Select Bit 2
ADC2CN_ADBUSY BIT ADC2CN.4 ; ADC Busy                             
ADC2CN_ADINT  BIT ADC2CN.5 ; Conversion Complete Interrupt Flag   
ADC2CN_ADTM   BIT ADC2CN.6 ; ADC Track Mode                       
ADC2CN_ADEN   BIT ADC2CN.7 ; ADC Enable                           

; B 0xF0 (B Register)
B_B0 BIT B.0 ; B Register Bit 0
B_B1 BIT B.1 ; B Register Bit 1
B_B2 BIT B.2 ; B Register Bit 2
B_B3 BIT B.3 ; B Register Bit 3
B_B4 BIT B.4 ; B Register Bit 4
B_B5 BIT B.5 ; B Register Bit 5
B_B6 BIT B.6 ; B Register Bit 6
B_B7 BIT B.7 ; B Register Bit 7

; CPT0CN 0x88 (Comparator 0 Control)
CPT0CN_CPHYN0 BIT CPT0CN.0 ; Comparator Negative Hysteresis Control Bit 0
CPT0CN_CPHYN1 BIT CPT0CN.1 ; Comparator Negative Hysteresis Control Bit 1
CPT0CN_CPHYP0 BIT CPT0CN.2 ; Comparator Positive Hysteresis Control Bit 0
CPT0CN_CPHYP1 BIT CPT0CN.3 ; Comparator Positive Hysteresis Control Bit 1
CPT0CN_CPFIF  BIT CPT0CN.4 ; Comparator Falling-Edge Flag                
CPT0CN_CPRIF  BIT CPT0CN.5 ; Comparator Rising-Edge Flag                 
CPT0CN_CPOUT  BIT CPT0CN.6 ; Comparator Output State Flag                
CPT0CN_CPEN   BIT CPT0CN.7 ; Comparator Enable                           

; CPT1CN 0x88 (Comparator 1 Control)
CPT1CN_CPHYN0 BIT CPT1CN.0 ; Comparator Negative Hysteresis Control Bit 0
CPT1CN_CPHYN1 BIT CPT1CN.1 ; Comparator Negative Hysteresis Control Bit 1
CPT1CN_CPHYP0 BIT CPT1CN.2 ; Comparator Positive Hysteresis Control Bit 0
CPT1CN_CPHYP1 BIT CPT1CN.3 ; Comparator Positive Hysteresis Control Bit 1
CPT1CN_CPFIF  BIT CPT1CN.4 ; Comparator Falling-Edge Flag                
CPT1CN_CPRIF  BIT CPT1CN.5 ; Comparator Rising-Edge Flag                 
CPT1CN_CPOUT  BIT CPT1CN.6 ; Comparator Output State Flag                
CPT1CN_CPEN   BIT CPT1CN.7 ; Comparator Enable                           

; FLSTAT 0x88 (Flash Status)
FLSTAT_FLBUSY BIT FLSTAT.0 ; Flash Busy

; IE 0xA8 (Interrupt Enable)
IE_EX0   BIT IE.0 ; External Interrupt 0 Enable
IE_ET0   BIT IE.1 ; Timer 0 Interrupt Enable   
IE_EX1   BIT IE.2 ; External Interrupt 1 Enable
IE_ET1   BIT IE.3 ; Timer 1 Interrupt Enable   
IE_ES0   BIT IE.4 ; UART0 Interrupt Enable     
IE_ET2   BIT IE.5 ; Timer 2 Interrupt Enable   
IE_ESPI0 BIT IE.6 ; SPI0 Interrupt Enable      
IE_IEGF0 BIT IE.6 ; General Purpose Flag 0     
IE_EA    BIT IE.7 ; All Interrupts Enable      

; IP 0xB8 (Interrupt Priority)
IP_PX0   BIT IP.0 ; External Interrupt 0 Priority Control                        
IP_PT0   BIT IP.1 ; Timer 0 Interrupt Priority Control                           
IP_PX1   BIT IP.2 ; External Interrupt 1 Priority Control                        
IP_PT1   BIT IP.3 ; Timer 1 Interrupt Priority Control                           
IP_PS0   BIT IP.4 ; UART0 Interrupt Priority Control                             
IP_PT2   BIT IP.5 ; Timer 2 Interrupt Priority Control                           
IP_PSPI0 BIT IP.6 ; Serial Peripheral Interface (SPI0) Interrupt Priority Control

; MAC0STA 0xC0 (MAC0 Status)
MAC0STA_NEGF  BIT MAC0STA.0 ; Negative Flag     
MAC0STA_SOVF  BIT MAC0STA.1 ; Soft Overflow Flag
MAC0STA_ZEROF BIT MAC0STA.2 ; Zero Flag         
MAC0STA_HOVF  BIT MAC0STA.3 ; Hard Overflow Flag

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

; P4 0xC8 (Port 4 Pin Latch)
P4_B0 BIT P4.0 ; Port 4 Bit 0 Latch
P4_B1 BIT P4.1 ; Port 4 Bit 1 Latch
P4_B2 BIT P4.2 ; Port 4 Bit 2 Latch
P4_B3 BIT P4.3 ; Port 4 Bit 3 Latch
P4_B4 BIT P4.4 ; Port 4 Bit 4 Latch
P4_B5 BIT P4.5 ; Port 4 Bit 5 Latch
P4_B6 BIT P4.6 ; Port 4 Bit 6 Latch
P4_B7 BIT P4.7 ; Port 4 Bit 7 Latch

; P5 0xD8 (Port 5 Pin Latch)
P5_B0 BIT P5.0 ; Port 5 Bit 0 Latch
P5_B1 BIT P5.1 ; Port 5 Bit 1 Latch
P5_B2 BIT P5.2 ; Port 5 Bit 2 Latch
P5_B3 BIT P5.3 ; Port 5 Bit 3 Latch
P5_B4 BIT P5.4 ; Port 5 Bit 4 Latch
P5_B5 BIT P5.5 ; Port 5 Bit 5 Latch
P5_B6 BIT P5.6 ; Port 5 Bit 6 Latch
P5_B7 BIT P5.7 ; Port 5 Bit 7 Latch

; P6 0xE8 (Port 6 Pin Latch)
P6_B0 BIT P6.0 ; Port 6 Bit 0 Latch
P6_B1 BIT P6.1 ; Port 6 Bit 1 Latch
P6_B2 BIT P6.2 ; Port 6 Bit 2 Latch
P6_B3 BIT P6.3 ; Port 6 Bit 3 Latch
P6_B4 BIT P6.4 ; Port 6 Bit 4 Latch
P6_B5 BIT P6.5 ; Port 6 Bit 5 Latch
P6_B6 BIT P6.6 ; Port 6 Bit 6 Latch
P6_B7 BIT P6.7 ; Port 6 Bit 7 Latch

; P7 0xF8 (Port 7 Pin Latch)
P7_B0 BIT P7.0 ; Port 7 Bit 0 Latch
P7_B1 BIT P7.1 ; Port 7 Bit 1 Latch
P7_B2 BIT P7.2 ; Port 7 Bit 2 Latch
P7_B3 BIT P7.3 ; Port 7 Bit 3 Latch
P7_B4 BIT P7.4 ; Port 7 Bit 4 Latch
P7_B5 BIT P7.5 ; Port 7 Bit 5 Latch
P7_B6 BIT P7.6 ; Port 7 Bit 6 Latch
P7_B7 BIT P7.7 ; Port 7 Bit 7 Latch

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
SCON0_RI  BIT SCON0.0 ; Receive Interrupt Flag             
SCON0_TI  BIT SCON0.1 ; Transmit Interrupt Flag            
SCON0_RB8 BIT SCON0.2 ; Ninth Receive Bit                  
SCON0_TB8 BIT SCON0.3 ; Ninth Transmission Bit             
SCON0_REN BIT SCON0.4 ; Receive Enable                     
SCON0_SM2 BIT SCON0.5 ; Multiprocessor Communication Enable
SCON0_SM0 BIT SCON0.6 ; Serial Port 0 Operation Mode Bit 0 
SCON0_SM1 BIT SCON0.7 ; Serial Port 0 Operation Mode Bit 1 

; SCON1 0x98 (UART1 Serial Port Control)
SCON1_RI    BIT SCON1.0 ; Receive Interrupt Flag             
SCON1_TI    BIT SCON1.1 ; Transmit Interrupt Flag            
SCON1_RB8   BIT SCON1.2 ; Ninth Receive Bit                  
SCON1_TB8   BIT SCON1.3 ; Ninth Transmission Bit             
SCON1_REN   BIT SCON1.4 ; Receive Enable                     
SCON1_MCE   BIT SCON1.5 ; Multiprocessor Communication Enable
SCON1_SMODE BIT SCON1.7 ; Serial Port 0 Operation Mode       

; SMB0CN 0xC0 (SMBus 0 Control)
SMB0CN_TOE   BIT SMB0CN.0 ; SMBus Timeout Enable         
SMB0CN_FTE   BIT SMB0CN.1 ; SMBus Free Timer Enable      
SMB0CN_AA    BIT SMB0CN.2 ; SMBus Assert Acknowledge Flag
SMB0CN_SI    BIT SMB0CN.3 ; SMBus Acknowledge Request    
SMB0CN_STO   BIT SMB0CN.4 ; SMBus Stop Flag              
SMB0CN_STA   BIT SMB0CN.5 ; SMBus Start Flag             
SMB0CN_ENSMB BIT SMB0CN.6 ; SMBus Enable                 
SMB0CN_BUSY  BIT SMB0CN.7 ; Busy Status Flag             

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
TMR2CN_CPRL2 BIT TMR2CN.0 ; Capture/Reload Select          
TMR2CN_CT2   BIT TMR2CN.1 ; Counter/Timer Select           
TMR2CN_TR2   BIT TMR2CN.2 ; Timer 2 Run Control            
TMR2CN_EXEN2 BIT TMR2CN.3 ; Timer 2 External Enable        
TMR2CN_EXF2  BIT TMR2CN.6 ; Timer 2 External Flag          
TMR2CN_TF2   BIT TMR2CN.7 ; Timer 2 Overflow/Underflow Flag

; TMR3CN 0xC8 (Timer 3 Control)
TMR3CN_CPRL3 BIT TMR3CN.0 ; Capture/Reload Select          
TMR3CN_CT3   BIT TMR3CN.1 ; Counter/Timer Select           
TMR3CN_TR3   BIT TMR3CN.2 ; Timer 3 Run Control            
TMR3CN_EXEN3 BIT TMR3CN.3 ; Timer 3 External Enable        
TMR3CN_EXF3  BIT TMR3CN.6 ; Timer 3 External Flag          
TMR3CN_TF3   BIT TMR3CN.7 ; Timer 3 Overflow/Underflow Flag

; TMR4CN 0xC8 (Timer 4 Control)
TMR4CN_CPRL4 BIT TMR4CN.0 ; Capture/Reload Select          
TMR4CN_CT4   BIT TMR4CN.1 ; Counter/Timer Select           
TMR4CN_TR4   BIT TMR4CN.2 ; Timer 4 Run Control            
TMR4CN_EXEN4 BIT TMR4CN.3 ; Timer 4 External Enable        
TMR4CN_EXF4  BIT TMR4CN.6 ; Timer 4 External Flag          
TMR4CN_TF4   BIT TMR4CN.7 ; Timer 4 Overflow/Underflow Flag

;------------------------------------------------------------------------------
; Interrupt Definitions
;------------------------------------------------------------------------------
INT0_IRQn    EQU 0  ; External Interrupt 0     
TIMER0_IRQn  EQU 1  ; Timer 0 Overflow         
INT1_IRQn    EQU 2  ; External Interrupt 1     
TIMER1_IRQn  EQU 3  ; Timer 1 Overflow         
UART0_IRQn   EQU 4  ; UART0                    
TIMER2_IRQn  EQU 5  ; Timer 2 Overflow         
SPI0_IRQn    EQU 6  ; SPI0                     
SMBUS0_IRQn  EQU 7  ; SMBus 0                  
ADC0WC_IRQn  EQU 8  ; ADC0 Window Compare      
PCA0_IRQn    EQU 9  ; PCA0                     
CMP0F_IRQn   EQU 10 ; Comparator 0 Falling Edge
CMP0R_IRQn   EQU 11 ; Comparator 0 Rising Edge 
CMP1F_IRQn   EQU 12 ; Comparator 1 Falling Edge
CMP1R_IRQn   EQU 13 ; Comparator 1 Rising Edge 
TIMER3_IRQn  EQU 14 ; Timer 3 Overflow         
ADC0EOC_IRQn EQU 15 ; ADC0 End of Conversion   
TIMER4_IRQn  EQU 16 ; Timer 4 Overflow         
ADC2WC_IRQn  EQU 17 ; ADC2 Window Compare      
ADC2EOC_IRQn EQU 18 ; ADC2 End of Conversion   
UART1_IRQn   EQU 20 ; UART1                    

;------------------------------------------------------------------------------
; SFR Page Definitions
;------------------------------------------------------------------------------
ADC0_PAGE     EQU 000H ; ADC0 Page                         
DAC0_PAGE     EQU 000H ; DAC0 Page                         
EMI0_PAGE     EQU 000H ; EMIF Page                         
LEGACY_PAGE   EQU 000H ; Legacy SFR Page                   
PCA0_PAGE     EQU 000H ; PCA0 Page                         
REF0_PAGE     EQU 000H ; VREF0 Page                        
SMB0_PAGE     EQU 000H ; SMBus 0 Page                      
SPI0_PAGE     EQU 000H ; SPI0 Page                         
TIMER01_PAGE  EQU 000H ; Timer 0 and Timer 1 Page          
TMR2_PAGE     EQU 000H ; Timer 2 Page                      
UART0_PAGE    EQU 000H ; UART0 Page                        
CPT0_PAGE     EQU 001H ; Comparator 0 Page                 
DAC1_PAGE     EQU 001H ; DAC1 Page                         
TMR3_PAGE     EQU 001H ; Timer 3 Page                      
UART1_PAGE    EQU 001H ; UART1 Page                        
ADC2_PAGE     EQU 002H ; ADC2 Page                         
CPT1_PAGE     EQU 002H ; Comparator 1 Page                 
TMR4_PAGE     EQU 002H ; Timer 4 Page                      
MAC0_PAGE     EQU 003H ; MAC Page                          
CONFIG_PAGE   EQU 00FH ; System and Port Configuration Page
PLL0_PAGE     EQU 00FH ; PLL0 Page                         
