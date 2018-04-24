;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  C8051F960_GM
;  C8051F960_GQ
;  C8051F961_GM
;  C8051F962_GM
;  C8051F962_GQ
;  C8051F963_GM
;  C8051F964_GM
;  C8051F964_GQ
;  C8051F965_GM
;  C8051F966_GM
;  C8051F966_GQ
;  C8051F967_GM
;  C8051F968_GM
;  C8051F968_GQ
;  C8051F969_GM

;-----------------------------------------------------------------------------
; Register Definitions
;-----------------------------------------------------------------------------
ACC         DATA 0E0H; Accumulator                           
ADC0AC      DATA 0BAH; ADC0 Accumulator Configuration        
ADC0CF      DATA 0BCH; ADC0 Configuration                    
ADC0CN      DATA 0E8H; ADC0 Control                          
ADC0GTH     DATA 0C4H; ADC0 Greater-Than High Byte           
ADC0GTL     DATA 0C3H; ADC0 Greater-Than Low Byte            
ADC0H       DATA 0BEH; ADC0 Data Word High Byte              
ADC0L       DATA 0BDH; ADC0 Data Word Low Byte               
ADC0LTH     DATA 0C6H; ADC0 Less-Than High Byte              
ADC0LTL     DATA 0C5H; ADC0 Less-Than Low Byte               
ADC0MX      DATA 0BBH; ADC0 Multiplexer Selection            
ADC0PWR     DATA 0BAH; ADC0 Power Control                    
ADC0TK      DATA 0BBH; ADC0 Burst Mode Track Time            
AES0BCFG    DATA 0E9H; AES Block Configuration               
AES0BIN     DATA 0EBH; AES Block Input                       
AES0DCFG    DATA 0EAH; AES Data Configuration                
AES0KIN     DATA 0EDH; AES Key Input                         
AES0XIN     DATA 0ECH; AES XOR Input                         
AES0YOUT    DATA 0F5H; AES Y Output                          
B           DATA 0F0H; B Register                            
CKCON       DATA 08EH; Clock Control                         
CLKMODE     DATA 0FDH; Clock Mode                            
CLKSEL      DATA 0A9H; Clock Select                          
CPT0CN      DATA 09BH; Comparator 0 Control                  
CPT0MD      DATA 09DH; Comparator 0 Mode                     
CPT0MX      DATA 09FH; Comparator 0 Multiplexer Selection    
CPT1CN      DATA 09AH; Comparator 1 Control                  
CPT1MD      DATA 09CH; Comparator 1 Mode                     
CPT1MX      DATA 09EH; Comparator 1 Multiplexer Selection    
CRC0AUTO    DATA 096H; CRC0 Automatic Control                
CRC0CN      DATA 092H; CRC0 Control                          
CRC0CNT     DATA 097H; CRC0 Automatic Flash Sector Count     
CRC0DAT     DATA 091H; CRC0 Data Output                      
CRC0FLIP    DATA 094H; CRC0 Bit Flip                         
CRC0IN      DATA 093H; CRC0 Data Input                       
CRC1CN      DATA 0BEH; CRC1 Control                          
CRC1IN      DATA 0B9H; CRC1 Data In                          
CRC1OUTH    DATA 0BBH; CRC1 Output High Byte                 
CRC1OUTL    DATA 0BAH; CRC1 Output Low Byte                  
CRC1POLH    DATA 0BDH; CRC1 Polynomial High Byte             
CRC1POLL    DATA 0BCH; CRC1 Polynomial Low Byte              
DC0CF       DATA 0B2H; DC-DC Converter Configuration         
DC0CN       DATA 0B1H; DC-DC Converter Control               
DC0MD       DATA 0B3H; DC-DC Converter Mode                  
DC0RDY      DATA 0FDH; DC-DC Converter Ready                 
DERIVID     DATA 0E9H; Device Identification                 
DMA0BUSY    DATA 0D5H; DMA0 Busy                             
DMA0EN      DATA 0D2H; DMA0 Channel Enable                   
DMA0INT     DATA 0D3H; DMA0 Full-Length Interrupt Flags      
DMA0MINT    DATA 0D4H; DMA0 Mid-Point Interrupt Flags        
DMA0NAOH    DATA 0CDH; Memory Address Offset High            
DMA0NAOL    DATA 0CCH; Memory Address Offset Low             
DMA0NBAH    DATA 0CBH; Memory Base Address High              
DMA0NBAL    DATA 0CAH; Memory Base Address Low               
DMA0NCF     DATA 0C9H; DMA0 Channel Configuration            
DMA0NMD     DATA 0D6H; DMA Channel Mode                      
DMA0NSZH    DATA 0CFH; Memory Transfer Size High             
DMA0NSZL    DATA 0CEH; Memory Transfer Size Low              
DMA0SEL     DATA 0D1H; DMA0 Channel Select                   
DPH         DATA 083H; Data Pointer High                     
DPL         DATA 082H; Data Pointer Low                      
EIE1        DATA 0E6H; Extended Interrupt Enable 1           
EIE2        DATA 0E7H; Extended Interrupt Enable 2           
EIP1        DATA 0F6H; Extended Interrupt Priority 1         
EIP2        DATA 0F7H; Extended Interrupt Priority 2         
EMI0CF      DATA 0ABH; External Memory Configuration         
EMI0CN      DATA 0AAH; External Memory Interface Control     
EMI0TC      DATA 0AFH; External Memory Timing Control        
ENC0CN      DATA 0C5H; Encoder / Decoder 0 Control           
ENC0H       DATA 0C4H; Encoder / Decoder 0 Data High Byte    
ENC0L       DATA 0C2H; Encoder / Decoder 0 Data Low Byte     
ENC0M       DATA 0C3H; Encoder / Decoder 0 Data Middle Byte  
FLKEY       DATA 0B7H; Flash Lock and Key                    
FLSCL       DATA 0B6H; Flash Scale                           
FLWR        DATA 0E5H; Flash Write Only                      
FRBCN       DATA 0B5H; Flash Read Buffer Control             
IE          DATA 0A8H; Interrupt Enable                      
IP          DATA 0B8H; Interrupt Priority                    
IREF0CF     DATA 0B9H; Current Reference Configuration       
IREF0CN     DATA 0B9H; Current Reference Control             
IT01CF      DATA 0E4H; INT0/INT1 Configuration               
LCD0BLINK   DATA 09EH; LCD0 Blink Mask                       
LCD0CF      DATA 0A5H; LCD0 Configuration                    
LCD0CLKDIVH DATA 0AAH; LCD0 Refresh Rate Prescaler High Byte 
LCD0CLKDIVL DATA 0A9H; LCD Refresh Rate Prescaler Low Byte   
LCD0CN      DATA 09DH; LCD0 Control                          
LCD0CNTRST  DATA 09CH; LCD0 Contrast Adjustment              
LCD0D0      DATA 089H; LCD0 Data 0                           
LCD0D1      DATA 08AH; LCD0 Data 1                           
LCD0D2      DATA 08BH; LCD0 Data 2                           
LCD0D3      DATA 08CH; LCD0 Data 3                           
LCD0D4      DATA 08DH; LCD0 Data 4                           
LCD0D5      DATA 08EH; LCD0 Data 5                           
LCD0D6      DATA 091H; LCD0 Data 6                           
LCD0D7      DATA 092H; LCD0 Data 7                           
LCD0D8      DATA 093H; LCD0 Data 8                           
LCD0D9      DATA 094H; LCD0 Data 9                           
LCD0DA      DATA 095H; LCD0 Data 10                          
LCD0DB      DATA 096H; LCD0 Data 11                          
LCD0DC      DATA 097H; LCD0 Data 12                          
LCD0DD      DATA 099H; LCD0 Data 13                          
LCD0DE      DATA 09AH; LCD0 Data 14                          
LCD0DF      DATA 09BH; LCD0 Data 15                          
LCD0MSCF    DATA 0ACH; LCD0 Master Configuration             
LCD0MSCN    DATA 0ABH; LCD0 Master Control                   
LCD0PWR     DATA 0A4H; LCD0 Power                            
LCD0TOGR    DATA 09FH; LCD0 Toggle Rate                      
LCD0VBMCN   DATA 0A6H; LCD0 VBAT Monitor Control             
OSCICL      DATA 0B3H; High Frequency Oscillator Calibration 
OSCICN      DATA 0B2H; High Frequency Oscillator Control     
OSCXCN      DATA 0B1H; External Oscillator Control           
P0          DATA 080H; Port 0 Pin Latch                      
P0DRV       DATA 0A4H; Port 0 Drive Strength                 
P0MASK      DATA 0C7H; Port 0 Mask                           
P0MAT       DATA 0D7H; Port 0 Match                          
P0MDIN      DATA 0F1H; Port 0 Input Mode                     
P0MDOUT     DATA 0A4H; Port 0 Output Mode                    
P0SKIP      DATA 0D4H; Port 0 Skip                           
P1          DATA 090H; Port 1 Pin Latch                      
P1DRV       DATA 0A5H; Port 1 Drive Strength                 
P1MASK      DATA 0BFH; Port 1 Mask                           
P1MAT       DATA 0CFH; Port 1 Match                          
P1MDIN      DATA 0F2H; Port 1 Input Mode                     
P1MDOUT     DATA 0A5H; Port 1 Output Mode                    
P1SKIP      DATA 0D5H; Port 1 Skip                           
P2          DATA 0A0H; Port 2 Pin Latch                      
P2DRV       DATA 0A6H; Port 2 Drive Strength                 
P2MDIN      DATA 0F3H; Port 2 Input Mode                     
P2MDOUT     DATA 0A6H; Port 2 Output Mode                    
P2SKIP      DATA 0D6H; Port 2 Skip                           
P3          DATA 0B0H; Port 3 Pin Latch                      
P3DRV       DATA 0A1H; Port 3 Drive Strength                 
P3MDIN      DATA 0F1H; Port 3 Input Mode                     
P3MDOUT     DATA 0B1H; Port 3 Output Mode                    
P4          DATA 0D9H; Port 4 Pin Latch                      
P4DRV       DATA 0A2H; Port 4 Drive Strength                 
P4MDIN      DATA 0F2H; Port 4 Input Mode                     
P4MDOUT     DATA 0F9H; Port 4 Output Mode                    
P5          DATA 0DAH; Port 5 Pin Latch                      
P5DRV       DATA 0A3H; Port 5 Drive Strength                 
P5MDIN      DATA 0F3H; Port 5 Input Mode                     
P5MDOUT     DATA 0FAH; Port 5 Output Mode                    
P6          DATA 0DBH; Port 6 Pin Latch                      
P6DRV       DATA 0AAH; Port 6 Drive Strength                 
P6MDIN      DATA 0F4H; Port 6 Input Mode                     
P6MDOUT     DATA 0FBH; Port 6 Output Mode                    
P7          DATA 0DCH; Port 7 Pin Latch                      
P7DRV       DATA 0ABH; Port 7 Drive Strength                 
P7MDOUT     DATA 0FCH; Port 7 Output Mode                    
PC0CMP0H    DATA 0E3H; PC0 Comparator 0 High Byte            
PC0CMP0L    DATA 0E1H; PC0 Comparator 0 Low Byte             
PC0CMP0M    DATA 0E2H; PC0 Comparator 0 Middle Byte          
PC0CMP1H    DATA 0F3H; PC0 Comparator 1 High Byte            
PC0CMP1L    DATA 0F1H; PC0 Comparator 1 Low Byte             
PC0CMP1M    DATA 0F2H; PC0 Comparator 1 Middle Byte          
PC0CTR0H    DATA 0DCH; PC0 Counter 0 High Byte               
PC0CTR0L    DATA 0DAH; PC0 Counter 0 Low Byte                
PC0CTR0M    DATA 0DBH; PC0 Counter 0 Middle Byte             
PC0CTR1H    DATA 0DFH; PC0 Counter 1 High Byte               
PC0CTR1L    DATA 0DDH; PC0 Counter 1 Low Byte                
PC0CTR1M    DATA 0DEH; PC0 Counter 1 Middle Byte             
PC0DCH      DATA 0FAH; PC0 Debounce Configuration High Byte  
PC0DCL      DATA 0F9H; PC0 Debounce Configuration Low Byte   
PC0HIST     DATA 0F4H; PC0 Direction History                 
PC0INT0     DATA 0FBH; PC0 Interrupt 0                       
PC0INT1     DATA 0FCH; PC0 Interrupt 1                       
PC0MD       DATA 0D9H; PC0 Mode Configuration                
PC0PCF      DATA 0D7H; PC0 Pull-Up Configuration             
PC0STAT     DATA 0C1H; PC0 Status                            
PC0TH       DATA 0E4H; PC0 Threshold Configuration           
PCA0CN      DATA 0D8H; PCA Control                           
PCA0CPH0    DATA 0FCH; PCA Channel 0 Capture Module High Byte
PCA0CPH1    DATA 0EAH; PCA Channel 1 Capture Module High Byte
PCA0CPH2    DATA 0ECH; PCA Channel 2 Capture Module High Byte
PCA0CPH3    DATA 0EEH; PCA Channel 3 Capture Module High Byte
PCA0CPH4    DATA 0FEH; PCA Channel 4 Capture Module High Byte
PCA0CPH5    DATA 0D3H; PCA Channel 5 Capture Module High Byte
PCA0CPL0    DATA 0FBH; PCA Channel 0 Capture Module Low Byte 
PCA0CPL1    DATA 0E9H; PCA Channel 1 Capture Module Low Byte 
PCA0CPL2    DATA 0EBH; PCA Channel 2 Capture Module Low Byte 
PCA0CPL3    DATA 0EDH; PCA Channel 3 Capture Module Low Byte 
PCA0CPL4    DATA 0FDH; PCA Channel 4 Capture Module Low Byte 
PCA0CPL5    DATA 0D2H; PCA Channel 5 Capture Module Low Byte 
PCA0CPM0    DATA 0DAH; PCA Channel 0 Capture/Compare Mode 0  
PCA0CPM1    DATA 0DBH; PCA Channel 1 Capture/Compare Mode    
PCA0CPM2    DATA 0DCH; PCA Channel 2 Capture/Compare Mode    
PCA0CPM3    DATA 0DDH; PCA Channel 3 Capture/Compare Mode    
PCA0CPM4    DATA 0DEH; PCA Channel 4 Capture/Compare Mode    
PCA0CPM5    DATA 0CEH; PCA Channel 5 Capture/Compare Mode    
PCA0H       DATA 0FAH; PCA Counter/Timer High Byte           
PCA0L       DATA 0F9H; PCA Counter/Timer Low Byte            
PCA0MD      DATA 0D9H; PCA Mode                              
PCA0PWM     DATA 0DFH; PCA PWM Configuration                 
PCLKACT     DATA 0F5H; Peripheral Active Clock Enable        
PCLKEN      DATA 0FEH; Low Power Peripheral Clock Enable     
PCON        DATA 087H; Power Control                         
PMU0CF      DATA 0B5H; Power Management Unit Configuration   
PMU0FL      DATA 0B6H; Power Management Unit Flag            
PMU0MD      DATA 0B3H; Power Management Unit Mode            
PSBANK      DATA 084H; Program Space Bank Select             
PSCTL       DATA 08FH; Program Store Control                 
PSW         DATA 0D0H; Program Status Word                   
REF0CN      DATA 0D1H; Voltage Reference Control             
REG0CN      DATA 0C9H; Voltage Regulator Control             
REVID       DATA 0EAH; Revision Identifcation                
RSTSRC      DATA 0EFH; Reset Source                          
RTC0ADR     DATA 0ACH; RTC Address                           
RTC0DAT     DATA 0ADH; RTC Data                              
RTC0KEY     DATA 0AEH; RTC Lock and Key                      
SBUF0       DATA 099H; UART0 Serial Port Data Buffer         
SCON0       DATA 098H; UART0 Serial Port Control             
SFRLAST     DATA 086H; SFR Page Last                         
SFRNEXT     DATA 085H; SFR Page Next                         
SFRPAGE     DATA 0A7H; SFR Page                              
SFRPGCN     DATA 08EH; SFR Page Control                      
SMB0ADM     DATA 0F5H; SMBus 0 Slave Address Mask            
SMB0ADR     DATA 0F4H; SMBus 0 Slave Address                 
SMB0CF      DATA 0C1H; SMBus 0 Configuration                 
SMB0CN      DATA 0C0H; SMBus 0 Control                       
SMB0DAT     DATA 0C2H; SMBus 0 Data                          
SP          DATA 081H; Stack Pointer                         
SPI0CFG     DATA 0A1H; SPI0 Configuration                    
SPI0CKR     DATA 0A2H; SPI0 Clock Rate                       
SPI0CN      DATA 0F8H; SPI0 Control                          
SPI0DAT     DATA 0A3H; SPI0 Data                             
SPI1CFG     DATA 0A1H; SPI1 Configuration                    
SPI1CKR     DATA 0A2H; SPI1 Clock Rate                       
SPI1CN      DATA 0F8H; SPI1 Control                          
SPI1DAT     DATA 0A3H; SPI1 Data                             
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
TOFFH       DATA 0BEH; Temperature Sensor Offset High        
TOFFL       DATA 0BDH; Temperature Sensor Offset Low         
VDM0CN      DATA 0FFH; VDD Supply Monitor Control            
XBR0        DATA 0E1H; Port I/O Crossbar 0                   
XBR1        DATA 0E2H; Port I/O Crossbar 1                   
XBR2        DATA 0E3H; Port I/O Crossbar 2                   

;------------------------------------------------------------------------------
; 16-bit Register Definitions (may not work on all compilers)
;------------------------------------------------------------------------------
ADC0GT     DATA 0C3H ; ADC0 Greater-Than Low Byte           
ADC0       DATA 0BDH ; ADC0 Data Word Low Byte              
ADC0LT     DATA 0C5H ; ADC0 Less-Than Low Byte              
DMA0NAO    DATA 0CCH ; Memory Address Offset Low            
DMA0NBA    DATA 0CAH ; Memory Base Address Low              
DMA0NSZ    DATA 0CEH ; Memory Transfer Size Low             
DP         DATA 082H ; Data Pointer Low                     
LCD0CLKDIV DATA 0A9H ; LCD Refresh Rate Prescaler Low Byte  
PCA0CP0    DATA 0FBH ; PCA Channel 0 Capture Module Low Byte
PCA0CP1    DATA 0E9H ; PCA Channel 1 Capture Module Low Byte
PCA0CP2    DATA 0EBH ; PCA Channel 2 Capture Module Low Byte
PCA0CP3    DATA 0EDH ; PCA Channel 3 Capture Module Low Byte
PCA0CP4    DATA 0FDH ; PCA Channel 4 Capture Module Low Byte
PCA0CP5    DATA 0D2H ; PCA Channel 5 Capture Module Low Byte
PCA0       DATA 0F9H ; PCA Counter/Timer Low Byte           
TMR2       DATA 0CCH ; Timer 2 Low Byte                     
TMR2RL     DATA 0CAH ; Timer 2 Reload Low Byte              
TMR3       DATA 094H ; Timer 3 Low Byte                     
TMR3RL     DATA 092H ; Timer 3 Reload Low Byte              
TOFF       DATA 0BDH ; Temperature Sensor Offset Low        

;------------------------------------------------------------------------------
; Indirect Register Definitions
;------------------------------------------------------------------------------
ALARM0B0   EQU 008H ; RTC Alarm 0 Programmed Value 0      
ALARM0B1   EQU 009H ; RTC Alarm 0 Programmed Value 1      
ALARM0B2   EQU 00AH ; RTC Alarm 0 Programmed Value 2      
ALARM0B3   EQU 00BH ; RTC Alarm 0 Programmed Value 3      
ALARM1B0   EQU 00CH ; RTC Alarm 1 Programmed Value 0      
ALARM1B1   EQU 00DH ; RTC Alarm 1 Programmed Value 1      
ALARM1B2   EQU 00EH ; RTC Alarm 1 Programmed Value 2      
ALARM1B3   EQU 00FH ; RTC Alarm 1 Programmed Value 3      
ALARM2B0   EQU 010H ; RTC Alarm 2 Programmed Value 0      
ALARM2B1   EQU 011H ; RTC Alarm 2 Programmed Value 1      
ALARM2B2   EQU 012H ; RTC Alarm 2 Programmed Value 2      
ALARM2B3   EQU 013H ; RTC Alarm 2 Programmed Value 3      
CAPTURE0   EQU 000H ; RTC Timer Capture 0                 
CAPTURE1   EQU 001H ; RTC Timer Capture 1                 
CAPTURE2   EQU 002H ; RTC Timer Capture 2                 
CAPTURE3   EQU 003H ; RTC Timer Capture 3                 
DMA0NAOH0  EQU 000H ; Channel 0 Memory Address Offset High
DMA0NAOH1  EQU 001H ; Channel 1 Memory Address Offset High
DMA0NAOH2  EQU 002H ; Channel 2 Memory Address Offset High
DMA0NAOH3  EQU 003H ; Channel 3 Memory Address Offset High
DMA0NAOH4  EQU 004H ; Channel 4 Memory Address Offset High
DMA0NAOH5  EQU 005H ; Channel 5 Memory Address Offset High
DMA0NAOH6  EQU 006H ; Channel 6 Memory Address Offset High
DMA0NAOL0  EQU 000H ; Channel 0 Memory Address Offset     
DMA0NAOL1  EQU 001H ; Channel 1 Memory Address Offset     
DMA0NAOL2  EQU 002H ; Channel 2 Memory Address Offset     
DMA0NAOL3  EQU 003H ; Channel 3 Memory Address Offset     
DMA0NAOL4  EQU 004H ; Channel 4 Memory Address Offset     
DMA0NAOL5  EQU 005H ; Channel 5 Memory Address Offset     
DMA0NAOL6  EQU 006H ; Channel 6 Memory Address Offset     
DMA0NBAH0  EQU 000H ; Channel 0 Memory Base Address High  
DMA0NBAH1  EQU 001H ; Channel 1 Memory Base Address High  
DMA0NBAH2  EQU 002H ; Channel 2 Memory Base Address High  
DMA0NBAH3  EQU 003H ; Channel 3 Memory Base Address High  
DMA0NBAH4  EQU 004H ; Channel 4 Memory Base Address High  
DMA0NBAH5  EQU 005H ; Channel 5 Memory Base Address High  
DMA0NBAH6  EQU 006H ; Channel 6 Memory Base Address High  
DMA0NBAL0  EQU 000H ; Channel 0 Memory Base Address       
DMA0NBAL1  EQU 001H ; Channel 1 Memory Base Address       
DMA0NBAL2  EQU 002H ; Channel 2 Memory Base Address       
DMA0NBAL3  EQU 003H ; Channel 3 Memory Base Address       
DMA0NBAL4  EQU 004H ; Channel 4 Memory Base Address       
DMA0NBAL5  EQU 005H ; Channel 5 Memory Base Address       
DMA0NBAL6  EQU 006H ; Channel 6 Memory Base Address       
DMA0NCF0   EQU 000H ; DMA0 Channel 0 Configuration        
DMA0NCF1   EQU 001H ; DMA0 Channel 1 Configuration        
DMA0NCF2   EQU 002H ; DMA0 Channel 2 Configuration        
DMA0NCF3   EQU 003H ; DMA0 Channel 3 Configuration        
DMA0NCF4   EQU 004H ; DMA0 Channel 4 Configuration        
DMA0NCF5   EQU 005H ; DMA0 Channel 5 Configuration        
DMA0NCF6   EQU 006H ; DMA0 Channel 6 Configuration        
DMA0NSZH0  EQU 000H ; Channel 0 Memory Transfer Size High 
DMA0NSZH1  EQU 001H ; Channel 1 Memory Transfer Size High 
DMA0NSZH2  EQU 002H ; Channel 2 Memory Transfer Size High 
DMA0NSZH3  EQU 003H ; Channel 3 Memory Transfer Size High 
DMA0NSZH4  EQU 004H ; Channel 4 Memory Transfer Size High 
DMA0NSZH5  EQU 005H ; Channel 5 Memory Transfer Size High 
DMA0NSZH6  EQU 006H ; Channel 6 Memory Transfer Size High 
DMA0NSZL0  EQU 000H ; Channel 0 Memory Transfer Size      
DMA0NSZL1  EQU 001H ; Channel 1 Memory Transfer Size      
DMA0NSZL2  EQU 002H ; Channel 2 Memory Transfer Size      
DMA0NSZL3  EQU 003H ; Channel 3 Memory Transfer Size      
DMA0NSZL4  EQU 004H ; Channel 4 Memory Transfer Size      
DMA0NSZL5  EQU 005H ; Channel 5 Memory Transfer Size      
DMA0NSZL6  EQU 006H ; Channel 6 Memory Transfer Size      
RTC0CF     EQU 007H ; RTC Configuration                   
RTC0CN     EQU 004H ; RTC Control                         
RTC0XCF    EQU 006H ; RTC Oscillator Configuration        
RTC0XCN    EQU 005H ; RTC Oscillator Control              

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

; SPI1CN 0xF8 (SPI1 Control)
SPI1CN_SPIEN  BIT SPI1CN.0 ; SPI1 Enable            
SPI1CN_TXBMT  BIT SPI1CN.1 ; Transmit Buffer Empty  
SPI1CN_NSSMD0 BIT SPI1CN.2 ; Slave Select Mode Bit 0
SPI1CN_NSSMD1 BIT SPI1CN.3 ; Slave Select Mode Bit 1
SPI1CN_RXOVRN BIT SPI1CN.4 ; Receive Overrun Flag   
SPI1CN_MODF   BIT SPI1CN.5 ; Mode Fault Flag        
SPI1CN_WCOL   BIT SPI1CN.6 ; Write Collision Flag   
SPI1CN_SPIF   BIT SPI1CN.7 ; SPI1 Interrupt Flag    

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
TMR2CN_T2XCLK0 BIT TMR2CN.0 ; Timer 2 External Clock Select Bit 0
TMR2CN_T2XCLK1 BIT TMR2CN.1 ; Timer 2 External Clock Select Bit 1
TMR2CN_TR2     BIT TMR2CN.2 ; Timer 2 Run Control                
TMR2CN_T2SPLIT BIT TMR2CN.3 ; Timer 2 Split Mode Enable          
TMR2CN_TF2CEN  BIT TMR2CN.4 ; Timer 2 Capture Enable             
TMR2CN_TF2LEN  BIT TMR2CN.5 ; Timer 2 Low Byte Interrupt Enable  
TMR2CN_TF2L    BIT TMR2CN.6 ; Timer 2 Low Byte Overflow Flag     
TMR2CN_TF2H    BIT TMR2CN.7 ; Timer 2 High Byte Overflow Flag    

;------------------------------------------------------------------------------
; Interrupt Definitions
;------------------------------------------------------------------------------
INT0_IRQn      EQU 0  ; External Interrupt 0                 
TIMER0_IRQn    EQU 1  ; Timer 0 Overflow                     
INT1_IRQn      EQU 2  ; External Interrupt 1                 
TIMER1_IRQn    EQU 3  ; Timer 1 Overflow                     
UART0_IRQn     EQU 4  ; UART 0                               
TIMER2_IRQn    EQU 5  ; Timer 2 Overflow                     
SPI0_IRQn      EQU 6  ; SPI0                                 
SMBUS0_IRQn    EQU 7  ; SMBus 0                              
RTC0ALARM_IRQn EQU 8  ; RTC0 Alarm                           
ADC0WC_IRQn    EQU 9  ; ADC0 Window Compare                  
ADC0EOC_IRQn   EQU 10 ; ADC0 End of Conversion               
PCA0_IRQn      EQU 11 ; PCA0                                 
CMP0_IRQn      EQU 12 ; Comparator 0                         
CMP1_IRQn      EQU 13 ; Comparator 1                         
TIMER3_IRQn    EQU 14 ; Timer 3 Overflow                     
VDDMON_IRQn    EQU 15 ; VBAT/VDD Supply Monitor Early Warning
PMATCH_IRQn    EQU 16 ; Port Match                           
RTC0FAIL_IRQn  EQU 17 ; RTC0 Oscillator Fail                 
SPI1_IRQn      EQU 18 ; SPI1                                 
PC0_IRQn       EQU 19 ; Pulse Counter                        
DMA0_IRQn      EQU 20 ; DMA0                                 
ENCDEC0_IRQn   EQU 21 ; Encoder / Decoder                    
AES0_IRQn      EQU 22 ; AES0                                 

;------------------------------------------------------------------------------
; SFR Page Definitions
;------------------------------------------------------------------------------
LEGACY_PAGE  EQU 000H ; Legacy SFR Page                           
AES0_PAGE    EQU 002H ;                                           
CRC1_PAGE    EQU 002H ;                                           
DMA0_PAGE    EQU 002H ;                                           
DPPE_PAGE    EQU 002H ; Data Packet Processing Engine (DPPE) Page 
ENC0_PAGE    EQU 002H ; Encoder / Decoder Page                    
LCD0_PAGE    EQU 002H ;                                           
SPI1_PAGE    EQU 002H ;                                           
CONFIG_PAGE  EQU 00FH ; System and Port Configuration Page        
CRC0_PAGE    EQU 00FH ;                                           
TOFF_PAGE    EQU 00FH ; Temperature Sensor Calibration Offset Page
