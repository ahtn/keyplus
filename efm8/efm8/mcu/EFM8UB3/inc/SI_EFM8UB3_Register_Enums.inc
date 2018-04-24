;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  EFM8UB30F40G_QFN20
;  EFM8UB31F40G_QFN24
;  EFM8UB31F40G_QSOP24

;------------------------------------------------------------------------------
; ADC0AC Enums (ADC0 Accumulator Configuration @ 0xB3)
;------------------------------------------------------------------------------
ADC0AC_ADRPT__FMASK            EQU 007H ; Repeat Count                                      
ADC0AC_ADRPT__SHIFT            EQU 000H ; Repeat Count                                      
ADC0AC_ADRPT__ACC_1            EQU 000H ; Perform and Accumulate 1 conversion (not used in  
                                        ; 12-bit mode).                                     
ADC0AC_ADRPT__ACC_4            EQU 001H ; Perform and Accumulate 4 conversions (1 conversion
                                        ; in 12-bit mode).                                  
ADC0AC_ADRPT__ACC_8            EQU 002H ; Perform and Accumulate 8 conversions (2           
                                        ; conversions in 12-bit mode).                      
ADC0AC_ADRPT__ACC_16           EQU 003H ; Perform and Accumulate 16 conversions (4          
                                        ; conversions in 12-bit mode).                      
ADC0AC_ADRPT__ACC_32           EQU 004H ; Perform and Accumulate 32 conversions (8          
                                        ; conversions in 12-bit mode).                      
ADC0AC_ADRPT__ACC_64           EQU 005H ; Perform and Accumulate 64 conversions (16         
                                        ; conversions in 12-bit mode).                      
                                                                                            
ADC0AC_ADSJST__FMASK           EQU 038H ; Accumulator Shift and Justify                     
ADC0AC_ADSJST__SHIFT           EQU 003H ; Accumulator Shift and Justify                     
ADC0AC_ADSJST__RIGHT_NO_SHIFT  EQU 000H ; Right justified. No shifting applied.             
ADC0AC_ADSJST__RIGHT_SHIFT_1   EQU 008H ; Right justified. Shifted right by 1 bit.          
ADC0AC_ADSJST__RIGHT_SHIFT_2   EQU 010H ; Right justified. Shifted right by 2 bits.         
ADC0AC_ADSJST__RIGHT_SHIFT_3   EQU 018H ; Right justified. Shifted right by 3 bits.         
ADC0AC_ADSJST__LEFT_NO_SHIFT   EQU 020H ; Left justified. No shifting applied.              
                                                                                            
ADC0AC_ADAE__BMASK             EQU 040H ; Accumulate Enable                                 
ADC0AC_ADAE__SHIFT             EQU 006H ; Accumulate Enable                                 
ADC0AC_ADAE__ACC_DISABLED      EQU 000H ; ADC0H:ADC0L contain the result of the latest      
                                        ; conversion when Burst Mode is disabled.           
ADC0AC_ADAE__ACC_ENABLED       EQU 040H ; ADC0H:ADC0L contain the accumulated conversion    
                                        ; results when Burst Mode is disabled. Firmware must
                                        ; write 0x0000 to ADC0H:ADC0L to clear the          
                                        ; accumulated result.                               
                                                                                            
ADC0AC_AD12BE__BMASK           EQU 080H ; 12-Bit Mode Enable                                
ADC0AC_AD12BE__SHIFT           EQU 007H ; 12-Bit Mode Enable                                
ADC0AC_AD12BE__12_BIT_DISABLED EQU 000H ; Disable 12-bit mode.                              
ADC0AC_AD12BE__12_BIT_ENABLED  EQU 080H ; Enable 12-bit mode.                               
                                                                                            
;------------------------------------------------------------------------------
; ADC0CF Enums (ADC0 Configuration @ 0xBC)
;------------------------------------------------------------------------------
ADC0CF_ADGN__BMASK         EQU 001H ; Gain Control                                      
ADC0CF_ADGN__SHIFT         EQU 000H ; Gain Control                                      
ADC0CF_ADGN__GAIN_0P5      EQU 000H ; The on-chip PGA gain is 0.5.                      
ADC0CF_ADGN__GAIN_1        EQU 001H ; The on-chip PGA gain is 1.                        
                                                                                        
ADC0CF_ADTM__BMASK         EQU 002H ; Track Mode                                        
ADC0CF_ADTM__SHIFT         EQU 001H ; Track Mode                                        
ADC0CF_ADTM__TRACK_NORMAL  EQU 000H ; Normal Track Mode. When ADC0 is enabled,          
                                    ; conversion begins immediately following the start-
                                    ; of-conversion signal.                             
ADC0CF_ADTM__TRACK_DELAYED EQU 002H ; Delayed Track Mode. When ADC0 is enabled,         
                                    ; conversion begins 4 SAR clock cycles following the
                                    ; start-of-conversion signal. The ADC is allowed to 
                                    ; track during this time.                           
                                                                                        
ADC0CF_AD8BE__BMASK        EQU 004H ; 8-Bit Mode Enable                                 
ADC0CF_AD8BE__SHIFT        EQU 002H ; 8-Bit Mode Enable                                 
ADC0CF_AD8BE__NORMAL       EQU 000H ; ADC0 operates in 10-bit or 12-bit mode (normal    
                                    ; operation).                                       
ADC0CF_AD8BE__8_BIT        EQU 004H ; ADC0 operates in 8-bit mode.                      
                                                                                        
ADC0CF_ADSC__FMASK         EQU 0F8H ; SAR Clock Divider                                 
ADC0CF_ADSC__SHIFT         EQU 003H ; SAR Clock Divider                                 
                                                                                        
;------------------------------------------------------------------------------
; ADC0CN0 Enums (ADC0 Control 0 @ 0xE8)
;------------------------------------------------------------------------------
ADC0CN0_ADWINT__BMASK          EQU 008H ; Window Compare Interrupt Flag                     
ADC0CN0_ADWINT__SHIFT          EQU 003H ; Window Compare Interrupt Flag                     
ADC0CN0_ADWINT__NOT_SET        EQU 000H ; An ADC window compare event did not occur.        
ADC0CN0_ADWINT__SET            EQU 008H ; An ADC window compare event occurred.             
                                                                                            
ADC0CN0_ADBUSY__BMASK          EQU 010H ; ADC Busy                                          
ADC0CN0_ADBUSY__SHIFT          EQU 004H ; ADC Busy                                          
ADC0CN0_ADBUSY__NOT_SET        EQU 000H ; An ADC0 conversion is not currently in progress.  
ADC0CN0_ADBUSY__SET            EQU 010H ; ADC0 conversion is in progress or start an ADC0   
                                        ; conversion.                                       
                                                                                            
ADC0CN0_ADINT__BMASK           EQU 020H ; Conversion Complete Interrupt Flag                
ADC0CN0_ADINT__SHIFT           EQU 005H ; Conversion Complete Interrupt Flag                
ADC0CN0_ADINT__NOT_SET         EQU 000H ; ADC0 has not completed a conversion since the last
                                        ; time ADINT was cleared.                           
ADC0CN0_ADINT__SET             EQU 020H ; ADC0 completed a data conversion.                 
                                                                                            
ADC0CN0_ADBMEN__BMASK          EQU 040H ; Burst Mode Enable                                 
ADC0CN0_ADBMEN__SHIFT          EQU 006H ; Burst Mode Enable                                 
ADC0CN0_ADBMEN__BURST_DISABLED EQU 000H ; Disable ADC0 burst mode.                          
ADC0CN0_ADBMEN__BURST_ENABLED  EQU 040H ; Enable ADC0 burst mode.                           
                                                                                            
ADC0CN0_ADEN__BMASK            EQU 080H ; ADC Enable                                        
ADC0CN0_ADEN__SHIFT            EQU 007H ; ADC Enable                                        
ADC0CN0_ADEN__DISABLED         EQU 000H ; Disable ADC0 (low-power shutdown).                
ADC0CN0_ADEN__ENABLED          EQU 080H ; Enable ADC0 (active and ready for data            
                                        ; conversions).                                     
                                                                                            
;------------------------------------------------------------------------------
; ADC0CN1 Enums (ADC0 Control 1 @ 0xB2)
;------------------------------------------------------------------------------
ADC0CN1_ADCMBE__BMASK              EQU 001H ; Common Mode Buffer Enable                         
ADC0CN1_ADCMBE__SHIFT              EQU 000H ; Common Mode Buffer Enable                         
ADC0CN1_ADCMBE__CM_BUFFER_DISABLED EQU 000H ; Disable the common mode buffer. This setting      
                                            ; should be used only if the tracking time of the   
                                            ; signal is greater than 1.5 us.                    
ADC0CN1_ADCMBE__CM_BUFFER_ENABLED  EQU 001H ; Enable the common mode buffer. This setting should
                                            ; be used in most cases, and will give the best     
                                            ; dynamic ADC performance. The common mode buffer   
                                            ; must be enabled if signal tracking time is less   
                                            ; than or equal to 1.5 us.                          
                                                                                                
ADC0CN1_ADCM__FMASK                EQU 0F0H ; Start of Conversion Mode Select                   
ADC0CN1_ADCM__SHIFT                EQU 004H ; Start of Conversion Mode Select                   
ADC0CN1_ADCM__ADBUSY               EQU 000H ; ADC0 conversion initiated on write of 1 to ADBUSY.
ADC0CN1_ADCM__TIMER0               EQU 010H ; ADC0 conversion initiated on overflow of Timer 0. 
ADC0CN1_ADCM__TIMER2               EQU 020H ; ADC0 conversion initiated on overflow of Timer 2. 
ADC0CN1_ADCM__TIMER3               EQU 030H ; ADC0 conversion initiated on overflow of Timer 3. 
ADC0CN1_ADCM__CNVSTR               EQU 040H ; ADC0 conversion initiated on rising edge of       
                                            ; CNVSTR.                                           
ADC0CN1_ADCM__CEX2                 EQU 050H ; ADC0 conversion initiated on rising edge of CEX2. 
ADC0CN1_ADCM__GATED_TIMER2         EQU 060H ; ADC0 conversion initiated on overflow of Timer 2  
                                            ; when CEX2 is logic high.                          
ADC0CN1_ADCM__TIMER4               EQU 070H ; ADC0 conversion initiated on overflow of Timer 4. 
ADC0CN1_ADCM__TIMER5               EQU 080H ; ADC0 conversion initiated on overflow of Timer 5. 
ADC0CN1_ADCM__CLU0                 EQU 090H ; ADC0 conversion initiated on CLU0 Output.         
ADC0CN1_ADCM__CLU1                 EQU 0A0H ; ADC0 conversion initiated on CLU1 Output.         
ADC0CN1_ADCM__CLU2                 EQU 0B0H ; ADC0 conversion initiated on CLU2 Output.         
ADC0CN1_ADCM__CLU3                 EQU 0C0H ; ADC0 conversion initiated on CLU3 Output.         
                                                                                                
;------------------------------------------------------------------------------
; ADC0GTH Enums (ADC0 Greater-Than High Byte @ 0xC4)
;------------------------------------------------------------------------------
ADC0GTH_ADC0GTH__FMASK EQU 0FFH ; Greater-Than High Byte
ADC0GTH_ADC0GTH__SHIFT EQU 000H ; Greater-Than High Byte
                                                        
;------------------------------------------------------------------------------
; ADC0GTL Enums (ADC0 Greater-Than Low Byte @ 0xC3)
;------------------------------------------------------------------------------
ADC0GTL_ADC0GTL__FMASK EQU 0FFH ; Greater-Than Low Byte
ADC0GTL_ADC0GTL__SHIFT EQU 000H ; Greater-Than Low Byte
                                                       
;------------------------------------------------------------------------------
; ADC0H Enums (ADC0 Data Word High Byte @ 0xBE)
;------------------------------------------------------------------------------
ADC0H_ADC0H__FMASK EQU 0FFH ; Data Word High Byte
ADC0H_ADC0H__SHIFT EQU 000H ; Data Word High Byte
                                                 
;------------------------------------------------------------------------------
; ADC0L Enums (ADC0 Data Word Low Byte @ 0xBD)
;------------------------------------------------------------------------------
ADC0L_ADC0L__FMASK EQU 0FFH ; Data Word Low Byte
ADC0L_ADC0L__SHIFT EQU 000H ; Data Word Low Byte
                                                
;------------------------------------------------------------------------------
; ADC0LTH Enums (ADC0 Less-Than High Byte @ 0xC6)
;------------------------------------------------------------------------------
ADC0LTH_ADC0LTH__FMASK EQU 0FFH ; Less-Than High Byte
ADC0LTH_ADC0LTH__SHIFT EQU 000H ; Less-Than High Byte
                                                     
;------------------------------------------------------------------------------
; ADC0LTL Enums (ADC0 Less-Than Low Byte @ 0xC5)
;------------------------------------------------------------------------------
ADC0LTL_ADC0LTL__FMASK EQU 0FFH ; Less-Than Low Byte
ADC0LTL_ADC0LTL__SHIFT EQU 000H ; Less-Than Low Byte
                                                    
;------------------------------------------------------------------------------
; ADC0MX Enums (ADC0 Multiplexer Selection @ 0xBB)
;------------------------------------------------------------------------------
ADC0MX_ADC0MX__FMASK        EQU 01FH ; AMUX0 Positive Input Selection
ADC0MX_ADC0MX__SHIFT        EQU 000H ; AMUX0 Positive Input Selection
ADC0MX_ADC0MX__ADC0P0       EQU 000H ; Select ADC0.0.                
ADC0MX_ADC0MX__ADC0P1       EQU 001H ; Select ADC0.1.                
ADC0MX_ADC0MX__ADC0P2       EQU 002H ; Select ADC0.2.                
ADC0MX_ADC0MX__ADC0P3       EQU 003H ; Select ADC0.3.                
ADC0MX_ADC0MX__ADC0P4       EQU 004H ; Select ADC0.4.                
ADC0MX_ADC0MX__ADC0P5       EQU 005H ; Select ADC0.5.                
ADC0MX_ADC0MX__ADC0P6       EQU 006H ; Select ADC0.6.                
ADC0MX_ADC0MX__ADC0P7       EQU 007H ; Select ADC0.7.                
ADC0MX_ADC0MX__ADC0P8       EQU 008H ; Select ADC0.8.                
ADC0MX_ADC0MX__ADC0P9       EQU 009H ; Select ADC0.9.                
ADC0MX_ADC0MX__ADC0P10      EQU 00AH ; Select ADC0.10.               
ADC0MX_ADC0MX__ADC0P11      EQU 00BH ; Select ADC0.11.               
ADC0MX_ADC0MX__ADC0P12      EQU 00CH ; Select ADC0.12.               
ADC0MX_ADC0MX__ADC0P13      EQU 00DH ; Select ADC0.13.               
ADC0MX_ADC0MX__ADC0P14      EQU 00EH ; Select ADC0.14.               
ADC0MX_ADC0MX__ADC0P15      EQU 00FH ; Select ADC0.15.               
ADC0MX_ADC0MX__TEMP         EQU 010H ; Select ADC0.16.               
ADC0MX_ADC0MX__LDO_OUT      EQU 011H ; Select ADC0.17.               
ADC0MX_ADC0MX__VDD          EQU 012H ; Select ADC0.18.               
ADC0MX_ADC0MX__GND          EQU 013H ; Select ADC0.19.               
ADC0MX_ADC0MX__ADC0P20      EQU 014H ; Select ADC0.20                
ADC0MX_ADC0MX__ADC0P21      EQU 015H ; Select ADC0.21                
ADC0MX_ADC0MX__ADC0P22      EQU 016H ; Select ADC0.22                
ADC0MX_ADC0MX__ADC0P23      EQU 017H ; Select ADC0.23                
ADC0MX_ADC0MX__ADC0P24      EQU 018H ; Select ADC0.24                
ADC0MX_ADC0MX__USB_DP       EQU 01CH ; Select ADC0.28                
ADC0MX_ADC0MX__USB_DM       EQU 01DH ; Select ADC0.29                
ADC0MX_ADC0MX__VREGIN_DIV_4 EQU 01EH ; Select ADC0.30                
ADC0MX_ADC0MX__NONE         EQU 01FH ; No input selected.            
                                                                     
;------------------------------------------------------------------------------
; ADC0PWR Enums (ADC0 Power Control @ 0xDF)
;------------------------------------------------------------------------------
ADC0PWR_ADPWR__FMASK                 EQU 00FH ; Burst Mode Power Up Time                         
ADC0PWR_ADPWR__SHIFT                 EQU 000H ; Burst Mode Power Up Time                         
                                                                                                 
ADC0PWR_ADLPM__BMASK                 EQU 010H ; Low Power Mode Enable                            
ADC0PWR_ADLPM__SHIFT                 EQU 004H ; Low Power Mode Enable                            
ADC0PWR_ADLPM__LP_BUFFER_DISABLED    EQU 000H ; Disable low power mode.                          
ADC0PWR_ADLPM__LP_BUFFER_ENABLED     EQU 010H ; Enable low power mode (requires extended tracking
                                              ; time).                                           
                                                                                                 
ADC0PWR_ADMXLP__BMASK                EQU 020H ; Mux and Reference Low Power Mode Enable          
ADC0PWR_ADMXLP__SHIFT                EQU 005H ; Mux and Reference Low Power Mode Enable          
ADC0PWR_ADMXLP__LP_MUX_VREF_DISABLED EQU 000H ; Low power mode disabled.                         
ADC0PWR_ADMXLP__LP_MUX_VREF_ENABLED  EQU 020H ; Low power mode enabled (SAR clock < 4 MHz).      
                                                                                                 
ADC0PWR_ADBIAS__FMASK                EQU 0C0H ; Bias Power Select                                
ADC0PWR_ADBIAS__SHIFT                EQU 006H ; Bias Power Select                                
ADC0PWR_ADBIAS__MODE0                EQU 000H ; Select bias current mode 0. Recommended to use   
                                              ; modes 1, 2, or 3.                                
ADC0PWR_ADBIAS__MODE1                EQU 040H ; Select bias current mode 1 (SARCLK <= 16 MHz).   
ADC0PWR_ADBIAS__MODE2                EQU 080H ; Select bias current mode 2.                      
ADC0PWR_ADBIAS__MODE3                EQU 0C0H ; Select bias current mode 3 (SARCLK <= 4 MHz).    
                                                                                                 
;------------------------------------------------------------------------------
; ADC0TK Enums (ADC0 Burst Mode Track Time @ 0xB9)
;------------------------------------------------------------------------------
ADC0TK_ADTK__FMASK         EQU 03FH ; Burst Mode Tracking Time                       
ADC0TK_ADTK__SHIFT         EQU 000H ; Burst Mode Tracking Time                       
                                                                                     
ADC0TK_AD12SM__BMASK       EQU 080H ; 12-Bit Sampling Mode                           
ADC0TK_AD12SM__SHIFT       EQU 007H ; 12-Bit Sampling Mode                           
ADC0TK_AD12SM__SAMPLE_FOUR EQU 000H ; The ADC will re-track and sample the input four
                                    ; times during a 12-bit conversion.              
ADC0TK_AD12SM__SAMPLE_ONCE EQU 080H ; The ADC will sample the input once at the      
                                    ; beginning of each 12-bit conversion. The ADTK  
                                    ; field can be set to 63 to maximize throughput. 
                                                                                     
;------------------------------------------------------------------------------
; ACC Enums (Accumulator @ 0xE0)
;------------------------------------------------------------------------------
ACC_ACC__FMASK EQU 0FFH ; Accumulator
ACC_ACC__SHIFT EQU 000H ; Accumulator
                                     
;------------------------------------------------------------------------------
; B Enums (B Register @ 0xF0)
;------------------------------------------------------------------------------
B_B__FMASK EQU 0FFH ; B Register
B_B__SHIFT EQU 000H ; B Register
                                
;------------------------------------------------------------------------------
; DPH Enums (Data Pointer High @ 0x83)
;------------------------------------------------------------------------------
DPH_DPH__FMASK EQU 0FFH ; Data Pointer High
DPH_DPH__SHIFT EQU 000H ; Data Pointer High
                                           
;------------------------------------------------------------------------------
; DPL Enums (Data Pointer Low @ 0x82)
;------------------------------------------------------------------------------
DPL_DPL__FMASK EQU 0FFH ; Data Pointer Low
DPL_DPL__SHIFT EQU 000H ; Data Pointer Low
                                          
;------------------------------------------------------------------------------
; PFE0CN Enums (Prefetch Engine Control @ 0xC1)
;------------------------------------------------------------------------------
PFE0CN_FLRT__BMASK               EQU 010H ; Flash Read Timing
PFE0CN_FLRT__SHIFT               EQU 004H ; Flash Read Timing
PFE0CN_FLRT__SYSCLK_BELOW_25_MHZ EQU 000H ; SYSCLK < 25 MHz. 
PFE0CN_FLRT__SYSCLK_BELOW_50_MHZ EQU 010H ; SYSCLK < 50 MHz. 
                                                             
;------------------------------------------------------------------------------
; PSW Enums (Program Status Word @ 0xD0)
;------------------------------------------------------------------------------
PSW_PARITY__BMASK   EQU 001H ; Parity Flag                                       
PSW_PARITY__SHIFT   EQU 000H ; Parity Flag                                       
PSW_PARITY__NOT_SET EQU 000H ; The sum of the 8 bits in the accumulator is even. 
PSW_PARITY__SET     EQU 001H ; The sum of the 8 bits in the accumulator is odd.  
                                                                                 
PSW_F1__BMASK       EQU 002H ; User Flag 1                                       
PSW_F1__SHIFT       EQU 001H ; User Flag 1                                       
PSW_F1__NOT_SET     EQU 000H ; Flag is not set.                                  
PSW_F1__SET         EQU 002H ; Flag is set.                                      
                                                                                 
PSW_OV__BMASK       EQU 004H ; Overflow Flag                                     
PSW_OV__SHIFT       EQU 002H ; Overflow Flag                                     
PSW_OV__NOT_SET     EQU 000H ; An overflow did not occur.                        
PSW_OV__SET         EQU 004H ; An overflow occurred.                             
                                                                                 
PSW_RS__FMASK       EQU 018H ; Register Bank Select                              
PSW_RS__SHIFT       EQU 003H ; Register Bank Select                              
PSW_RS__BANK0       EQU 000H ; Bank 0, Addresses 0x00-0x07                       
PSW_RS__BANK1       EQU 008H ; Bank 1, Addresses 0x08-0x0F                       
PSW_RS__BANK2       EQU 010H ; Bank 2, Addresses 0x10-0x17                       
PSW_RS__BANK3       EQU 018H ; Bank 3, Addresses 0x18-0x1F                       
                                                                                 
PSW_F0__BMASK       EQU 020H ; User Flag 0                                       
PSW_F0__SHIFT       EQU 005H ; User Flag 0                                       
PSW_F0__NOT_SET     EQU 000H ; Flag is not set.                                  
PSW_F0__SET         EQU 020H ; Flag is set.                                      
                                                                                 
PSW_AC__BMASK       EQU 040H ; Auxiliary Carry Flag                              
PSW_AC__SHIFT       EQU 006H ; Auxiliary Carry Flag                              
PSW_AC__NOT_SET     EQU 000H ; A carry into (addition) or borrow from            
                             ; (subtraction) the high order nibble did not occur.
PSW_AC__SET         EQU 040H ; A carry into (addition) or borrow from            
                             ; (subtraction) the high order nibble occurred.     
                                                                                 
PSW_CY__BMASK       EQU 080H ; Carry Flag                                        
PSW_CY__SHIFT       EQU 007H ; Carry Flag                                        
PSW_CY__NOT_SET     EQU 000H ; A carry (addition) or borrow (subtraction) did not
                             ; occur.                                            
PSW_CY__SET         EQU 080H ; A carry (addition) or borrow (subtraction)        
                             ; occurred.                                         
                                                                                 
;------------------------------------------------------------------------------
; SP Enums (Stack Pointer @ 0x81)
;------------------------------------------------------------------------------
SP_SP__FMASK EQU 0FFH ; Stack Pointer
SP_SP__SHIFT EQU 000H ; Stack Pointer
                                     
;------------------------------------------------------------------------------
; CLKSEL Enums (Clock Select @ 0xA9)
;------------------------------------------------------------------------------
CLKSEL_CLKSL__FMASK           EQU 007H ; Clock Source Select                             
CLKSEL_CLKSL__SHIFT           EQU 000H ; Clock Source Select                             
CLKSEL_CLKSL__HFOSC0          EQU 000H ; Clock derived from the Internal High Frequency  
                                       ; Oscillator 0.                                   
CLKSEL_CLKSL__EXTOSC          EQU 001H ; Clock derived from the External Oscillator      
                                       ; circuit.                                        
CLKSEL_CLKSL__LFOSC           EQU 002H ; Clock derived from the Internal Low-Frequency   
                                       ; Oscillator.                                     
CLKSEL_CLKSL__HFOSC1          EQU 003H ; Clock derived from the Internal High Frequency  
                                       ; Oscillator 1.                                   
CLKSEL_CLKSL__HFOSC0_DIV_1P5  EQU 004H ; Clock derived from the Internal High Frequency  
                                       ; Oscillator 0, pre-scaled by 1.5.                
CLKSEL_CLKSL__HFOSC1_DIV_1P5  EQU 007H ; Clock derived from the Internal High Frequency  
                                       ; Oscillator 1, pre-scaled by 1.5.                
                                                                                         
CLKSEL_CLKDIV__FMASK          EQU 070H ; Clock Source Divider                            
CLKSEL_CLKDIV__SHIFT          EQU 004H ; Clock Source Divider                            
CLKSEL_CLKDIV__SYSCLK_DIV_1   EQU 000H ; SYSCLK is equal to selected clock source divided
                                       ; by 1.                                           
CLKSEL_CLKDIV__SYSCLK_DIV_2   EQU 010H ; SYSCLK is equal to selected clock source divided
                                       ; by 2.                                           
CLKSEL_CLKDIV__SYSCLK_DIV_4   EQU 020H ; SYSCLK is equal to selected clock source divided
                                       ; by 4.                                           
CLKSEL_CLKDIV__SYSCLK_DIV_8   EQU 030H ; SYSCLK is equal to selected clock source divided
                                       ; by 8.                                           
CLKSEL_CLKDIV__SYSCLK_DIV_16  EQU 040H ; SYSCLK is equal to selected clock source divided
                                       ; by 16.                                          
CLKSEL_CLKDIV__SYSCLK_DIV_32  EQU 050H ; SYSCLK is equal to selected clock source divided
                                       ; by 32.                                          
CLKSEL_CLKDIV__SYSCLK_DIV_64  EQU 060H ; SYSCLK is equal to selected clock source divided
                                       ; by 64.                                          
CLKSEL_CLKDIV__SYSCLK_DIV_128 EQU 070H ; SYSCLK is equal to selected clock source divided
                                       ; by 128.                                         
                                                                                         
CLKSEL_DIVRDY__BMASK          EQU 080H ; Clock Divider Ready                             
CLKSEL_DIVRDY__SHIFT          EQU 007H ; Clock Divider Ready                             
CLKSEL_DIVRDY__NOT_READY      EQU 000H ; Clock has not propagated through divider yet.   
CLKSEL_DIVRDY__READY          EQU 080H ; Clock has propagated through divider.           
                                                                                         
;------------------------------------------------------------------------------
; CLU0CF Enums (Configurable Logic Unit 0 Configuration @ 0xB1)
;------------------------------------------------------------------------------
CLU0CF_CLKSEL__FMASK     EQU 003H ; CLU D flip-flop Clock Selection                  
CLU0CF_CLKSEL__SHIFT     EQU 000H ; CLU D flip-flop Clock Selection                  
CLU0CF_CLKSEL__CARRY_IN  EQU 000H ; The carry-in signal.                             
CLU0CF_CLKSEL__MXA_INPUT EQU 001H ; The MXA input.                                   
CLU0CF_CLKSEL__ALTCLK0   EQU 002H ; The alternate clock signal CLU0ALTCLK0.          
CLU0CF_CLKSEL__ALTCLK1   EQU 003H ; The alternate clock signal CLU0ALTCLK1.          
                                                                                     
CLU0CF_CLKINV__BMASK     EQU 004H ; CLU D flip-flop Clock Invert                     
CLU0CF_CLKINV__SHIFT     EQU 002H ; CLU D flip-flop Clock Invert                     
CLU0CF_CLKINV__NORMAL    EQU 000H ; Clock signal is not inverted.                    
CLU0CF_CLKINV__INVERT    EQU 004H ; Clock signal will be inverted.                   
                                                                                     
CLU0CF_RST__BMASK        EQU 008H ; CLU D flip-flop Reset                            
CLU0CF_RST__SHIFT        EQU 003H ; CLU D flip-flop Reset                            
CLU0CF_RST__RESET        EQU 008H ; Reset the flip flop.                             
                                                                                     
CLU0CF_OEN__BMASK        EQU 040H ; CLU Port Output Enable                           
CLU0CF_OEN__SHIFT        EQU 006H ; CLU Port Output Enable                           
CLU0CF_OEN__DISABLE      EQU 000H ; Disables asynchronous output to the selected GPIO
                                  ; pin                                              
CLU0CF_OEN__ENABLE       EQU 040H ; Enables asynchronous output to the selected GPIO 
                                  ; pin                                              
                                                                                     
CLU0CF_OUTSEL__BMASK     EQU 080H ; CLU Output Select                                
CLU0CF_OUTSEL__SHIFT     EQU 007H ; CLU Output Select                                
CLU0CF_OUTSEL__D_FF      EQU 000H ; Select D flip-flop output of CLU                 
CLU0CF_OUTSEL__LUT       EQU 080H ; Select LUT output.                               
                                                                                     
;------------------------------------------------------------------------------
; CLU0FN Enums (Configurable Logic Unit 0 Function Select @ 0xAD)
;------------------------------------------------------------------------------
CLU0FN_FNSEL__FMASK EQU 0FFH ; CLU Look-Up-Table function select
CLU0FN_FNSEL__SHIFT EQU 000H ; CLU Look-Up-Table function select
                                                                
;------------------------------------------------------------------------------
; CLU0MX Enums (Configurable Logic Unit 0 Multiplexer @ 0x84)
;------------------------------------------------------------------------------
CLU0MX_MXB__FMASK   EQU 00FH ; CLU0 B Input Multiplexer Selection
CLU0MX_MXB__SHIFT   EQU 000H ; CLU0 B Input Multiplexer Selection
CLU0MX_MXB__CLU0B0  EQU 000H ; Select CLU0B.0                    
CLU0MX_MXB__CLU0B1  EQU 001H ; Select CLU0B.1                    
CLU0MX_MXB__CLU0B2  EQU 002H ; Select CLU0B.2                    
CLU0MX_MXB__CLU0B3  EQU 003H ; Select CLU0B.3                    
CLU0MX_MXB__CLU0B4  EQU 004H ; Select CLU0B.4                    
CLU0MX_MXB__CLU0B5  EQU 005H ; Select CLU0B.5                    
CLU0MX_MXB__CLU0B6  EQU 006H ; Select CLU0B.6                    
CLU0MX_MXB__CLU0B7  EQU 007H ; Select CLU0B.7                    
CLU0MX_MXB__CLU0B8  EQU 008H ; Select CLU0B.8                    
CLU0MX_MXB__CLU0B9  EQU 009H ; Select CLU0B.9                    
CLU0MX_MXB__CLU0B10 EQU 00AH ; Select CLU0B.10                   
CLU0MX_MXB__CLU0B11 EQU 00BH ; Select CLU0B.11                   
CLU0MX_MXB__CLU0B12 EQU 00CH ; Select CLU0B.12                   
CLU0MX_MXB__CLU0B13 EQU 00DH ; Select CLU0B.13                   
CLU0MX_MXB__CLU0B14 EQU 00EH ; Select CLU0B.14                   
CLU0MX_MXB__CLU0B15 EQU 00FH ; Select CLU0B.15                   
                                                                 
CLU0MX_MXA__FMASK   EQU 0F0H ; CLU0 A Input Multiplexer Selection
CLU0MX_MXA__SHIFT   EQU 004H ; CLU0 A Input Multiplexer Selection
CLU0MX_MXA__CLU0A0  EQU 000H ; Select CLU0A.0                    
CLU0MX_MXA__CLU0A1  EQU 010H ; Select CLU0A.1                    
CLU0MX_MXA__CLU0A2  EQU 020H ; Select CLU0A.2                    
CLU0MX_MXA__CLU0A3  EQU 030H ; Select CLU0A.3                    
CLU0MX_MXA__CLU0A4  EQU 040H ; Select CLU0A.4                    
CLU0MX_MXA__CLU0A5  EQU 050H ; Select CLU0A.5                    
CLU0MX_MXA__CLU0A6  EQU 060H ; Select CLU0A.6                    
CLU0MX_MXA__CLU0A7  EQU 070H ; Select CLU0A.7                    
CLU0MX_MXA__CLU0A8  EQU 080H ; Select CLU0A.8                    
CLU0MX_MXA__CLU0A9  EQU 090H ; Select CLU0A.9                    
CLU0MX_MXA__CLU0A10 EQU 0A0H ; Select CLU0A.10                   
CLU0MX_MXA__CLU0A11 EQU 0B0H ; Select CLU0A.11                   
CLU0MX_MXA__CLU0A12 EQU 0C0H ; Select CLU0A.12                   
CLU0MX_MXA__CLU0A13 EQU 0D0H ; Select CLU0A.13                   
CLU0MX_MXA__CLU0A14 EQU 0E0H ; Select CLU0A.14                   
CLU0MX_MXA__CLU0A15 EQU 0F0H ; Select CLU0A.15                   
                                                                 
;------------------------------------------------------------------------------
; CLU1CF Enums (Configurable Logic Unit 1 Configuration @ 0xBB)
;------------------------------------------------------------------------------
CLU1CF_CLKSEL__FMASK     EQU 003H ; CLU D flip-flop Clock Selection                  
CLU1CF_CLKSEL__SHIFT     EQU 000H ; CLU D flip-flop Clock Selection                  
CLU1CF_CLKSEL__CARRY_IN  EQU 000H ; The carry-in signal.                             
CLU1CF_CLKSEL__MXA_INPUT EQU 001H ; The MXA input.                                   
CLU1CF_CLKSEL__ALTCLK0   EQU 002H ; The alternate clock signal CLU1ALTCLK0.          
CLU1CF_CLKSEL__ALTCLK1   EQU 003H ; The alternate clock signal CLU1ALTCLK1.          
                                                                                     
CLU1CF_CLKINV__BMASK     EQU 004H ; CLU D flip-flop Clock Invert                     
CLU1CF_CLKINV__SHIFT     EQU 002H ; CLU D flip-flop Clock Invert                     
CLU1CF_CLKINV__NORMAL    EQU 000H ; Clock signal is not inverted.                    
CLU1CF_CLKINV__INVERT    EQU 004H ; Clock signal will be inverted.                   
                                                                                     
CLU1CF_RST__BMASK        EQU 008H ; CLU D flip-flop Reset                            
CLU1CF_RST__SHIFT        EQU 003H ; CLU D flip-flop Reset                            
CLU1CF_RST__RESET        EQU 008H ; Reset the flip flop.                             
                                                                                     
CLU1CF_OEN__BMASK        EQU 040H ; CLU Port Output Enable                           
CLU1CF_OEN__SHIFT        EQU 006H ; CLU Port Output Enable                           
CLU1CF_OEN__DISABLE      EQU 000H ; Disables asynchronous output to the selected GPIO
                                  ; pin                                              
CLU1CF_OEN__ENABLE       EQU 040H ; Enables asynchronous output to the selected GPIO 
                                  ; pin                                              
                                                                                     
CLU1CF_OUTSEL__BMASK     EQU 080H ; CLU Output Select                                
CLU1CF_OUTSEL__SHIFT     EQU 007H ; CLU Output Select                                
CLU1CF_OUTSEL__D_FF      EQU 000H ; Select D flip-flop output of CLU                 
CLU1CF_OUTSEL__LUT       EQU 080H ; Select LUT output.                               
                                                                                     
;------------------------------------------------------------------------------
; CLU1FN Enums (Configurable Logic Unit 1 Function Select @ 0xB9)
;------------------------------------------------------------------------------
CLU1FN_FNSEL__FMASK EQU 0FFH ; CLU Look-Up-Table function select
CLU1FN_FNSEL__SHIFT EQU 000H ; CLU Look-Up-Table function select
                                                                
;------------------------------------------------------------------------------
; CLU1MX Enums (Configurable Logic Unit 1 Multiplexer @ 0x85)
;------------------------------------------------------------------------------
CLU1MX_MXB__FMASK   EQU 00FH ; CLU1 B Input Multiplexer Selection
CLU1MX_MXB__SHIFT   EQU 000H ; CLU1 B Input Multiplexer Selection
CLU1MX_MXB__CLU1B0  EQU 000H ; Select CLU1B.0                    
CLU1MX_MXB__CLU1B1  EQU 001H ; Select CLU1B.1                    
CLU1MX_MXB__CLU1B2  EQU 002H ; Select CLU1B.2                    
CLU1MX_MXB__CLU1B3  EQU 003H ; Select CLU1B.3                    
CLU1MX_MXB__CLU1B4  EQU 004H ; Select CLU1B.4                    
CLU1MX_MXB__CLU1B5  EQU 005H ; Select CLU1B.5                    
CLU1MX_MXB__CLU1B6  EQU 006H ; Select CLU1B.6                    
CLU1MX_MXB__CLU1B7  EQU 007H ; Select CLU1B.7                    
CLU1MX_MXB__CLU1B8  EQU 008H ; Select CLU1B.8                    
CLU1MX_MXB__CLU1B9  EQU 009H ; Select CLU1B.9                    
CLU1MX_MXB__CLU1B10 EQU 00AH ; Select CLU1B.10                   
CLU1MX_MXB__CLU1B11 EQU 00BH ; Select CLU1B.11                   
CLU1MX_MXB__CLU1B12 EQU 00CH ; Select CLU1B.12                   
CLU1MX_MXB__CLU1B13 EQU 00DH ; Select CLU1B.13                   
CLU1MX_MXB__CLU1B14 EQU 00EH ; Select CLU1B.14                   
CLU1MX_MXB__CLU1B15 EQU 00FH ; Select CLU1B.15                   
                                                                 
CLU1MX_MXA__FMASK   EQU 0F0H ; CLU1 A Input Multiplexer Selection
CLU1MX_MXA__SHIFT   EQU 004H ; CLU1 A Input Multiplexer Selection
CLU1MX_MXA__CLU1A0  EQU 000H ; Select CLU1A.0                    
CLU1MX_MXA__CLU1A1  EQU 010H ; Select CLU1A.1                    
CLU1MX_MXA__CLU1A2  EQU 020H ; Select CLU1A.2                    
CLU1MX_MXA__CLU1A3  EQU 030H ; Select CLU1A.3                    
CLU1MX_MXA__CLU1A4  EQU 040H ; Select CLU1A.4                    
CLU1MX_MXA__CLU1A5  EQU 050H ; Select CLU1A.5                    
CLU1MX_MXA__CLU1A6  EQU 060H ; Select CLU1A.6                    
CLU1MX_MXA__CLU1A7  EQU 070H ; Select CLU1A.7                    
CLU1MX_MXA__CLU1A8  EQU 080H ; Select CLU1A.8                    
CLU1MX_MXA__CLU1A9  EQU 090H ; Select CLU1A.9                    
CLU1MX_MXA__CLU1A10 EQU 0A0H ; Select CLU1A.10                   
CLU1MX_MXA__CLU1A11 EQU 0B0H ; Select CLU1A.11                   
CLU1MX_MXA__CLU1A12 EQU 0C0H ; Select CLU1A.12                   
CLU1MX_MXA__CLU1A13 EQU 0D0H ; Select CLU1A.13                   
CLU1MX_MXA__CLU1A14 EQU 0E0H ; Select CLU1A.14                   
CLU1MX_MXA__CLU1A15 EQU 0F0H ; Select CLU1A.15                   
                                                                 
;------------------------------------------------------------------------------
; CLU2CF Enums (Configurable Logic Unit 2 Configuration @ 0xBD)
;------------------------------------------------------------------------------
CLU2CF_CLKSEL__FMASK     EQU 003H ; CLU D flip-flop Clock Selection                  
CLU2CF_CLKSEL__SHIFT     EQU 000H ; CLU D flip-flop Clock Selection                  
CLU2CF_CLKSEL__CARRY_IN  EQU 000H ; The carry-in signal.                             
CLU2CF_CLKSEL__MXA_INPUT EQU 001H ; The MXA input.                                   
CLU2CF_CLKSEL__ALTCLK0   EQU 002H ; The alternate clock signal CLU2ALTCLK0.          
CLU2CF_CLKSEL__ALTCLK1   EQU 003H ; The alternate clock signal CLU2ALTCLK1.          
                                                                                     
CLU2CF_CLKINV__BMASK     EQU 004H ; CLU D flip-flop Clock Invert                     
CLU2CF_CLKINV__SHIFT     EQU 002H ; CLU D flip-flop Clock Invert                     
CLU2CF_CLKINV__NORMAL    EQU 000H ; Clock signal is not inverted.                    
CLU2CF_CLKINV__INVERT    EQU 004H ; Clock signal will be inverted.                   
                                                                                     
CLU2CF_RST__BMASK        EQU 008H ; CLU D flip-flop Reset                            
CLU2CF_RST__SHIFT        EQU 003H ; CLU D flip-flop Reset                            
CLU2CF_RST__RESET        EQU 008H ; Reset the flip flop.                             
                                                                                     
CLU2CF_OEN__BMASK        EQU 040H ; CLU Port Output Enable                           
CLU2CF_OEN__SHIFT        EQU 006H ; CLU Port Output Enable                           
CLU2CF_OEN__DISABLE      EQU 000H ; Disables asynchronous output to the selected GPIO
                                  ; pin                                              
CLU2CF_OEN__ENABLE       EQU 040H ; Enables asynchronous output to the selected GPIO 
                                  ; pin                                              
                                                                                     
CLU2CF_OUTSEL__BMASK     EQU 080H ; CLU Output Select                                
CLU2CF_OUTSEL__SHIFT     EQU 007H ; CLU Output Select                                
CLU2CF_OUTSEL__D_FF      EQU 000H ; Select D flip-flop output of CLU                 
CLU2CF_OUTSEL__LUT       EQU 080H ; Select LUT output.                               
                                                                                     
;------------------------------------------------------------------------------
; CLU2FN Enums (Configurable Logic Unit 2 Function Select @ 0xBC)
;------------------------------------------------------------------------------
CLU2FN_FNSEL__FMASK EQU 0FFH ; CLU Look-Up-Table function select
CLU2FN_FNSEL__SHIFT EQU 000H ; CLU Look-Up-Table function select
                                                                
;------------------------------------------------------------------------------
; CLU2MX Enums (Configurable Logic Unit 2 Multiplexer @ 0x91)
;------------------------------------------------------------------------------
CLU2MX_MXB__FMASK   EQU 00FH ; CLU2 B Input Multiplexer Selection
CLU2MX_MXB__SHIFT   EQU 000H ; CLU2 B Input Multiplexer Selection
CLU2MX_MXB__CLU2B0  EQU 000H ; Select CLU2B.0                    
CLU2MX_MXB__CLU2B1  EQU 001H ; Select CLU2B.1                    
CLU2MX_MXB__CLU2B2  EQU 002H ; Select CLU2B.2                    
CLU2MX_MXB__CLU2B3  EQU 003H ; Select CLU2B.3                    
CLU2MX_MXB__CLU2B4  EQU 004H ; Select CLU2B.4                    
CLU2MX_MXB__CLU2B5  EQU 005H ; Select CLU2B.5                    
CLU2MX_MXB__CLU2B6  EQU 006H ; Select CLU2B.6                    
CLU2MX_MXB__CLU2B7  EQU 007H ; Select CLU2B.7                    
CLU2MX_MXB__CLU2B8  EQU 008H ; Select CLU2B.8                    
CLU2MX_MXB__CLU2B9  EQU 009H ; Select CLU2B.9                    
CLU2MX_MXB__CLU2B10 EQU 00AH ; Select CLU2B.10                   
CLU2MX_MXB__CLU2B11 EQU 00BH ; Select CLU2B.11                   
CLU2MX_MXB__CLU2B12 EQU 00CH ; Select CLU2B.12                   
CLU2MX_MXB__CLU2B13 EQU 00DH ; Select CLU2B.13                   
CLU2MX_MXB__CLU2B14 EQU 00EH ; Select CLU2B.14                   
CLU2MX_MXB__CLU2B15 EQU 00FH ; Select CLU2B.15                   
                                                                 
CLU2MX_MXA__FMASK   EQU 0F0H ; CLU2 A Input Multiplexer Selection
CLU2MX_MXA__SHIFT   EQU 004H ; CLU2 A Input Multiplexer Selection
CLU2MX_MXA__CLU2A0  EQU 000H ; Select CLU2A.0                    
CLU2MX_MXA__CLU2A1  EQU 010H ; Select CLU2A.1                    
CLU2MX_MXA__CLU2A2  EQU 020H ; Select CLU2A.2                    
CLU2MX_MXA__CLU2A3  EQU 030H ; Select CLU2A.3                    
CLU2MX_MXA__CLU2A4  EQU 040H ; Select CLU2A.4                    
CLU2MX_MXA__CLU2A5  EQU 050H ; Select CLU2A.5                    
CLU2MX_MXA__CLU2A6  EQU 060H ; Select CLU2A.6                    
CLU2MX_MXA__CLU2A7  EQU 070H ; Select CLU2A.7                    
CLU2MX_MXA__CLU2A8  EQU 080H ; Select CLU2A.8                    
CLU2MX_MXA__CLU2A9  EQU 090H ; Select CLU2A.9                    
CLU2MX_MXA__CLU2A10 EQU 0A0H ; Select CLU2A.10                   
CLU2MX_MXA__CLU2A11 EQU 0B0H ; Select CLU2A.11                   
CLU2MX_MXA__CLU2A12 EQU 0C0H ; Select CLU2A.12                   
CLU2MX_MXA__CLU2A13 EQU 0D0H ; Select CLU2A.13                   
CLU2MX_MXA__CLU2A14 EQU 0E0H ; Select CLU2A.14                   
CLU2MX_MXA__CLU2A15 EQU 0F0H ; Select CLU2A.15                   
                                                                 
;------------------------------------------------------------------------------
; CLU3CF Enums (Configurable Logic Unit 3 Configuration @ 0xCA)
;------------------------------------------------------------------------------
CLU3CF_CLKSEL__FMASK     EQU 003H ; CLU D flip-flop Clock Selection                  
CLU3CF_CLKSEL__SHIFT     EQU 000H ; CLU D flip-flop Clock Selection                  
CLU3CF_CLKSEL__CARRY_IN  EQU 000H ; The carry-in signal.                             
CLU3CF_CLKSEL__MXA_INPUT EQU 001H ; The MXA input.                                   
CLU3CF_CLKSEL__ALTCLK0   EQU 002H ; The alternate clock signal CLU3ALTCLK0.          
CLU3CF_CLKSEL__ALTCLK1   EQU 003H ; The alternate clock signal CLU3ALTCLK1.          
                                                                                     
CLU3CF_CLKINV__BMASK     EQU 004H ; CLU D flip-flop Clock Invert                     
CLU3CF_CLKINV__SHIFT     EQU 002H ; CLU D flip-flop Clock Invert                     
CLU3CF_CLKINV__NORMAL    EQU 000H ; Clock signal is not inverted.                    
CLU3CF_CLKINV__INVERT    EQU 004H ; Clock signal will be inverted.                   
                                                                                     
CLU3CF_RST__BMASK        EQU 008H ; CLU D flip-flop Reset                            
CLU3CF_RST__SHIFT        EQU 003H ; CLU D flip-flop Reset                            
CLU3CF_RST__RESET        EQU 008H ; Reset the flip flop.                             
                                                                                     
CLU3CF_OEN__BMASK        EQU 040H ; CLU Port Output Enable                           
CLU3CF_OEN__SHIFT        EQU 006H ; CLU Port Output Enable                           
CLU3CF_OEN__DISABLE      EQU 000H ; Disables asynchronous output to the selected GPIO
                                  ; pin                                              
CLU3CF_OEN__ENABLE       EQU 040H ; Enables asynchronous output to the selected GPIO 
                                  ; pin                                              
                                                                                     
CLU3CF_OUTSEL__BMASK     EQU 080H ; CLU Output Select                                
CLU3CF_OUTSEL__SHIFT     EQU 007H ; CLU Output Select                                
CLU3CF_OUTSEL__D_FF      EQU 000H ; Select D flip-flop output of CLU                 
CLU3CF_OUTSEL__LUT       EQU 080H ; Select LUT output.                               
                                                                                     
;------------------------------------------------------------------------------
; CLU3FN Enums (Configurable Logic Unit 3 Function Select @ 0xC7)
;------------------------------------------------------------------------------
CLU3FN_FNSEL__FMASK EQU 0FFH ; CLU Look-Up-Table function select
CLU3FN_FNSEL__SHIFT EQU 000H ; CLU Look-Up-Table function select
                                                                
;------------------------------------------------------------------------------
; CLU3MX Enums (Configurable Logic Unit 3 Multiplexer @ 0x92)
;------------------------------------------------------------------------------
CLU3MX_MXB__FMASK   EQU 00FH ; CLU3 B Input Multiplexer Selection
CLU3MX_MXB__SHIFT   EQU 000H ; CLU3 B Input Multiplexer Selection
CLU3MX_MXB__CLU3B0  EQU 000H ; Select CLU3B.0                    
CLU3MX_MXB__CLU3B1  EQU 001H ; Select CLU3B.1                    
CLU3MX_MXB__CLU3B2  EQU 002H ; Select CLU3B.2                    
CLU3MX_MXB__CLU3B3  EQU 003H ; Select CLU3B.3                    
CLU3MX_MXB__CLU3B4  EQU 004H ; Select CLU3B.4                    
CLU3MX_MXB__CLU3B5  EQU 005H ; Select CLU3B.5                    
CLU3MX_MXB__CLU3B6  EQU 006H ; Select CLU3B.6                    
CLU3MX_MXB__CLU3B7  EQU 007H ; Select CLU3B.7                    
CLU3MX_MXB__CLU3B8  EQU 008H ; Select CLU3B.8                    
CLU3MX_MXB__CLU3B9  EQU 009H ; Select CLU3B.9                    
CLU3MX_MXB__CLU3B10 EQU 00AH ; Select CLU3B.10                   
CLU3MX_MXB__CLU3B11 EQU 00BH ; Select CLU3B.11                   
CLU3MX_MXB__CLU3B12 EQU 00CH ; Select CLU3B.12                   
CLU3MX_MXB__CLU3B13 EQU 00DH ; Select CLU3B.13                   
CLU3MX_MXB__CLU3B14 EQU 00EH ; Select CLU3B.14                   
CLU3MX_MXB__CLU3B15 EQU 00FH ; Select CLU3B.15                   
                                                                 
CLU3MX_MXA__FMASK   EQU 0F0H ; CLU3 A Input Multiplexer Selection
CLU3MX_MXA__SHIFT   EQU 004H ; CLU3 A Input Multiplexer Selection
CLU3MX_MXA__CLU3A0  EQU 000H ; Select CLU3A.0                    
CLU3MX_MXA__CLU3A1  EQU 010H ; Select CLU3A.1                    
CLU3MX_MXA__CLU3A2  EQU 020H ; Select CLU3A.2                    
CLU3MX_MXA__CLU3A3  EQU 030H ; Select CLU3A.3                    
CLU3MX_MXA__CLU3A4  EQU 040H ; Select CLU3A.4                    
CLU3MX_MXA__CLU3A5  EQU 050H ; Select CLU3A.5                    
CLU3MX_MXA__CLU3A6  EQU 060H ; Select CLU3A.6                    
CLU3MX_MXA__CLU3A7  EQU 070H ; Select CLU3A.7                    
CLU3MX_MXA__CLU3A8  EQU 080H ; Select CLU3A.8                    
CLU3MX_MXA__CLU3A9  EQU 090H ; Select CLU3A.9                    
CLU3MX_MXA__CLU3A10 EQU 0A0H ; Select CLU3A.10                   
CLU3MX_MXA__CLU3A11 EQU 0B0H ; Select CLU3A.11                   
CLU3MX_MXA__CLU3A12 EQU 0C0H ; Select CLU3A.12                   
CLU3MX_MXA__CLU3A13 EQU 0D0H ; Select CLU3A.13                   
CLU3MX_MXA__CLU3A14 EQU 0E0H ; Select CLU3A.14                   
CLU3MX_MXA__CLU3A15 EQU 0F0H ; Select CLU3A.15                   
                                                                 
;------------------------------------------------------------------------------
; CLEN0 Enums (Configurable Logic Enable 0 @ 0xCB)
;------------------------------------------------------------------------------
CLEN0_C0EN__BMASK   EQU 001H ; CLU0 Enable                                      
CLEN0_C0EN__SHIFT   EQU 000H ; CLU0 Enable                                      
CLEN0_C0EN__DISABLE EQU 000H ; CLU0 is disabled. The output of the block will be
                             ; logic low.                                       
CLEN0_C0EN__ENABLE  EQU 001H ; CLU0 is enabled.                                 
                                                                                
CLEN0_C1EN__BMASK   EQU 002H ; CLU1 Enable                                      
CLEN0_C1EN__SHIFT   EQU 001H ; CLU1 Enable                                      
CLEN0_C1EN__DISABLE EQU 000H ; CLU1 is disabled. The output of the block will be
                             ; logic low.                                       
CLEN0_C1EN__ENABLE  EQU 002H ; CLU1 is enabled.                                 
                                                                                
CLEN0_C2EN__BMASK   EQU 004H ; CLU2 Enable                                      
CLEN0_C2EN__SHIFT   EQU 002H ; CLU2 Enable                                      
CLEN0_C2EN__DISABLE EQU 000H ; CLU2 is disabled. The output of the block will be
                             ; logic low.                                       
CLEN0_C2EN__ENABLE  EQU 004H ; CLU2 is enabled.                                 
                                                                                
CLEN0_C3EN__BMASK   EQU 008H ; CLU3 Enable                                      
CLEN0_C3EN__SHIFT   EQU 003H ; CLU3 Enable                                      
CLEN0_C3EN__DISABLE EQU 000H ; CLU3 is disabled. The output of the block will be
                             ; logic low.                                       
CLEN0_C3EN__ENABLE  EQU 008H ; CLU3 is enabled.                                 
                                                                                
;------------------------------------------------------------------------------
; CLIE0 Enums (Configurable Logic Interrupt Enable 0 @ 0xCD)
;------------------------------------------------------------------------------
CLIE0_C0FIE__BMASK   EQU 001H ; CLU0 Falling Edge Interrupt Enable                
CLIE0_C0FIE__SHIFT   EQU 000H ; CLU0 Falling Edge Interrupt Enable                
CLIE0_C0FIE__DISABLE EQU 000H ; Interrupts will not be generated for CLU0 falling-
                              ; edge events.                                      
CLIE0_C0FIE__ENABLE  EQU 001H ; Interrupts will be generated for CLU0 falling-edge
                              ; events.                                           
                                                                                  
CLIE0_C0RIE__BMASK   EQU 002H ; CLU0 Rising Edge Interrupt Enable                 
CLIE0_C0RIE__SHIFT   EQU 001H ; CLU0 Rising Edge Interrupt Enable                 
CLIE0_C0RIE__DISABLE EQU 000H ; Interrupts will not be generated for CLU0 rising- 
                              ; edge events.                                      
CLIE0_C0RIE__ENABLE  EQU 002H ; Interrupts will be generated for CLU0 rising-edge 
                              ; events.                                           
                                                                                  
CLIE0_C1FIE__BMASK   EQU 004H ; CLU1 Falling Edge Interrupt Enable                
CLIE0_C1FIE__SHIFT   EQU 002H ; CLU1 Falling Edge Interrupt Enable                
CLIE0_C1FIE__DISABLE EQU 000H ; Interrupts will not be generated for CLU1 falling-
                              ; edge events.                                      
CLIE0_C1FIE__ENABLE  EQU 004H ; Interrupts will be generated for CLU1 falling-edge
                              ; events.                                           
                                                                                  
CLIE0_C1RIE__BMASK   EQU 008H ; CLU1 Rising Edge Interrupt Enable                 
CLIE0_C1RIE__SHIFT   EQU 003H ; CLU1 Rising Edge Interrupt Enable                 
CLIE0_C1RIE__DISABLE EQU 000H ; Interrupts will not be generated for CLU1 rising- 
                              ; edge events.                                      
CLIE0_C1RIE__ENABLE  EQU 008H ; Interrupts will be generated for CLU1 rising-edge 
                              ; events.                                           
                                                                                  
CLIE0_C2FIE__BMASK   EQU 010H ; CLU2 Falling Edge Interrupt Enable                
CLIE0_C2FIE__SHIFT   EQU 004H ; CLU2 Falling Edge Interrupt Enable                
CLIE0_C2FIE__DISABLE EQU 000H ; Interrupts will not be generated for CLU2 falling-
                              ; edge events.                                      
CLIE0_C2FIE__ENABLE  EQU 010H ; Interrupts will be generated for CLU2 falling-edge
                              ; events.                                           
                                                                                  
CLIE0_C2RIE__BMASK   EQU 020H ; CLU2 Rising Edge Interrupt Enable                 
CLIE0_C2RIE__SHIFT   EQU 005H ; CLU2 Rising Edge Interrupt Enable                 
CLIE0_C2RIE__DISABLE EQU 000H ; Interrupts will not be generated for CLU2 rising- 
                              ; edge events.                                      
CLIE0_C2RIE__ENABLE  EQU 020H ; Interrupts will be generated for CLU2 rising-edge 
                              ; events.                                           
                                                                                  
CLIE0_C3FIE__BMASK   EQU 040H ; CLU3 Falling Edge Interrupt Enable                
CLIE0_C3FIE__SHIFT   EQU 006H ; CLU3 Falling Edge Interrupt Enable                
CLIE0_C3FIE__DISABLE EQU 000H ; Interrupts will not be generated for CLU3 falling-
                              ; edge events.                                      
CLIE0_C3FIE__ENABLE  EQU 040H ; Interrupts will be generated for CLU3 falling-edge
                              ; events.                                           
                                                                                  
CLIE0_C3RIE__BMASK   EQU 080H ; CLU3 Rising Edge Interrupt Enable                 
CLIE0_C3RIE__SHIFT   EQU 007H ; CLU3 Rising Edge Interrupt Enable                 
CLIE0_C3RIE__DISABLE EQU 000H ; Interrupts will not be generated for CLU3 rising- 
                              ; edge events.                                      
CLIE0_C3RIE__ENABLE  EQU 080H ; Interrupts will be generated for CLU3 rising-edge 
                              ; events.                                           
                                                                                  
;------------------------------------------------------------------------------
; CLIF0 Enums (Configurable Logic Interrupt Flag 0 @ 0xE8)
;------------------------------------------------------------------------------
CLIF0_C0FIF__BMASK   EQU 001H ; CLU0 Falling Edge Flag                            
CLIF0_C0FIF__SHIFT   EQU 000H ; CLU0 Falling Edge Flag                            
CLIF0_C0FIF__NOT_SET EQU 000H ; A CLU0 falling edge has not been detected since   
                              ; this flag was last cleared.                       
CLIF0_C0FIF__SET     EQU 001H ; A CLU0 falling edge (synchronized with SYSCLK) has
                              ; occurred. This bit must be cleared by firmware.   
                                                                                  
CLIF0_C0RIF__BMASK   EQU 002H ; CLU0 Rising Edge Flag                             
CLIF0_C0RIF__SHIFT   EQU 001H ; CLU0 Rising Edge Flag                             
CLIF0_C0RIF__NOT_SET EQU 000H ; A CLU0 rising edge has not been detected since    
                              ; this flag was last cleared.                       
CLIF0_C0RIF__SET     EQU 002H ; A CLU0 rising edge (synchronized with SYSCLK) has 
                              ; occurred. This bit must be cleared by firmware.   
                                                                                  
CLIF0_C1FIF__BMASK   EQU 004H ; CLU1 Falling Edge Flag                            
CLIF0_C1FIF__SHIFT   EQU 002H ; CLU1 Falling Edge Flag                            
CLIF0_C1FIF__NOT_SET EQU 000H ; A CLU1 falling edge has not been detected since   
                              ; this flag was last cleared.                       
CLIF0_C1FIF__SET     EQU 004H ; A CLU1 falling edge (synchronized with SYSCLK) has
                              ; occurred. This bit must be cleared by firmware.   
                                                                                  
CLIF0_C1RIF__BMASK   EQU 008H ; CLU1 Rising Edge Flag                             
CLIF0_C1RIF__SHIFT   EQU 003H ; CLU1 Rising Edge Flag                             
CLIF0_C1RIF__NOT_SET EQU 000H ; A CLU1 rising edge has not been detected since    
                              ; this flag was last cleared.                       
CLIF0_C1RIF__SET     EQU 008H ; A CLU1 rising edge (synchronized with SYSCLK) has 
                              ; occurred. This bit must be cleared by firmware.   
                                                                                  
CLIF0_C2FIF__BMASK   EQU 010H ; CLU2 Falling Edge Flag                            
CLIF0_C2FIF__SHIFT   EQU 004H ; CLU2 Falling Edge Flag                            
CLIF0_C2FIF__NOT_SET EQU 000H ; A CLU2 falling edge has not been detected since   
                              ; this flag was last cleared.                       
CLIF0_C2FIF__SET     EQU 010H ; A CLU2 falling edge (synchronized with SYSCLK) has
                              ; occurred. This bit must be cleared by firmware.   
                                                                                  
CLIF0_C2RIF__BMASK   EQU 020H ; CLU2 Rising Edge Flag                             
CLIF0_C2RIF__SHIFT   EQU 005H ; CLU2 Rising Edge Flag                             
CLIF0_C2RIF__NOT_SET EQU 000H ; A CLU2 rising edge has not been detected since    
                              ; this flag was last cleared.                       
CLIF0_C2RIF__SET     EQU 020H ; A CLU2 rising edge (synchronized with SYSCLK) has 
                              ; occurred. This bit must be cleared by firmware.   
                                                                                  
CLIF0_C3FIF__BMASK   EQU 040H ; CLU3 Falling Edge Flag                            
CLIF0_C3FIF__SHIFT   EQU 006H ; CLU3 Falling Edge Flag                            
CLIF0_C3FIF__NOT_SET EQU 000H ; A CLU3 falling edge has not been detected since   
                              ; this flag was last cleared.                       
CLIF0_C3FIF__SET     EQU 040H ; A CLU3 falling edge (synchronized with SYSCLK) has
                              ; occurred. This bit must be cleared by firmware.   
                                                                                  
CLIF0_C3RIF__BMASK   EQU 080H ; CLU3 Rising Edge Flag                             
CLIF0_C3RIF__SHIFT   EQU 007H ; CLU3 Rising Edge Flag                             
CLIF0_C3RIF__NOT_SET EQU 000H ; A CLU3 rising edge has not been detected since    
                              ; this flag was last cleared.                       
CLIF0_C3RIF__SET     EQU 080H ; A CLU3 rising edge (synchronized with SYSCLK) has 
                              ; occurred. This bit must be cleared by firmware.   
                                                                                  
;------------------------------------------------------------------------------
; CLOUT0 Enums (Configurable Logic Output 0 @ 0xD9)
;------------------------------------------------------------------------------
CLOUT0_C0OUT__BMASK EQU 001H ; CLU0 Output State
CLOUT0_C0OUT__SHIFT EQU 000H ; CLU0 Output State
                                                
CLOUT0_C1OUT__BMASK EQU 002H ; CLU1 Output State
CLOUT0_C1OUT__SHIFT EQU 001H ; CLU1 Output State
                                                
CLOUT0_C2OUT__BMASK EQU 004H ; CLU2 Output State
CLOUT0_C2OUT__SHIFT EQU 002H ; CLU2 Output State
                                                
CLOUT0_C3OUT__BMASK EQU 008H ; CLU3 Output State
CLOUT0_C3OUT__SHIFT EQU 003H ; CLU3 Output State
                                                
;------------------------------------------------------------------------------
; CMP0CN0 Enums (Comparator 0 Control 0 @ 0x9B)
;------------------------------------------------------------------------------
CMP0CN0_CPHYN__FMASK                EQU 003H ; Comparator Negative Hysteresis Control            
CMP0CN0_CPHYN__SHIFT                EQU 000H ; Comparator Negative Hysteresis Control            
CMP0CN0_CPHYN__DISABLED             EQU 000H ; Negative Hysteresis disabled.                     
CMP0CN0_CPHYN__ENABLED_MODE1        EQU 001H ; Negative Hysteresis = Hysteresis 1.               
CMP0CN0_CPHYN__ENABLED_MODE2        EQU 002H ; Negative Hysteresis = Hysteresis 2.               
CMP0CN0_CPHYN__ENABLED_MODE3        EQU 003H ; Negative Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                 
CMP0CN0_CPHYP__FMASK                EQU 00CH ; Comparator Positive Hysteresis Control            
CMP0CN0_CPHYP__SHIFT                EQU 002H ; Comparator Positive Hysteresis Control            
CMP0CN0_CPHYP__DISABLED             EQU 000H ; Positive Hysteresis disabled.                     
CMP0CN0_CPHYP__ENABLED_MODE1        EQU 004H ; Positive Hysteresis = Hysteresis 1.               
CMP0CN0_CPHYP__ENABLED_MODE2        EQU 008H ; Positive Hysteresis = Hysteresis 2.               
CMP0CN0_CPHYP__ENABLED_MODE3        EQU 00CH ; Positive Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                 
CMP0CN0_CPFIF__BMASK                EQU 010H ; Comparator Falling-Edge Flag                      
CMP0CN0_CPFIF__SHIFT                EQU 004H ; Comparator Falling-Edge Flag                      
CMP0CN0_CPFIF__NOT_SET              EQU 000H ; No comparator falling edge has occurred since this
                                             ; flag was last cleared.                            
CMP0CN0_CPFIF__FALLING_EDGE         EQU 010H ; Comparator falling edge has occurred.             
                                                                                                 
CMP0CN0_CPRIF__BMASK                EQU 020H ; Comparator Rising-Edge Flag                       
CMP0CN0_CPRIF__SHIFT                EQU 005H ; Comparator Rising-Edge Flag                       
CMP0CN0_CPRIF__NOT_SET              EQU 000H ; No comparator rising edge has occurred since this 
                                             ; flag was last cleared.                            
CMP0CN0_CPRIF__RISING_EDGE          EQU 020H ; Comparator rising edge has occurred.              
                                                                                                 
CMP0CN0_CPOUT__BMASK                EQU 040H ; Comparator Output State Flag                      
CMP0CN0_CPOUT__SHIFT                EQU 006H ; Comparator Output State Flag                      
CMP0CN0_CPOUT__POS_LESS_THAN_NEG    EQU 000H ; Voltage on CP0P < CP0N.                           
CMP0CN0_CPOUT__POS_GREATER_THAN_NEG EQU 040H ; Voltage on CP0P > CP0N.                           
                                                                                                 
CMP0CN0_CPEN__BMASK                 EQU 080H ; Comparator Enable                                 
CMP0CN0_CPEN__SHIFT                 EQU 007H ; Comparator Enable                                 
CMP0CN0_CPEN__DISABLED              EQU 000H ; Comparator disabled.                              
CMP0CN0_CPEN__ENABLED               EQU 080H ; Comparator enabled.                               
                                                                                                 
;------------------------------------------------------------------------------
; CMP0CN1 Enums (Comparator 0 Control 1 @ 0x99)
;------------------------------------------------------------------------------
CMP0CN1_DACLVL__FMASK   EQU 03FH ; Internal Comparator DAC Reference Level           
CMP0CN1_DACLVL__SHIFT   EQU 000H ; Internal Comparator DAC Reference Level           
                                                                                     
CMP0CN1_CPINH__BMASK    EQU 080H ; Output Inhibit                                    
CMP0CN1_CPINH__SHIFT    EQU 007H ; Output Inhibit                                    
CMP0CN1_CPINH__DISABLED EQU 000H ; The comparator output will always reflect the     
                                 ; input conditions.                                 
CMP0CN1_CPINH__ENABLED  EQU 080H ; The comparator output will hold state any time the
                                 ; PCA CEX2 channel is low.                          
                                                                                     
;------------------------------------------------------------------------------
; CMP0MD Enums (Comparator 0 Mode @ 0x9D)
;------------------------------------------------------------------------------
CMP0MD_CPMD__FMASK              EQU 003H ; Comparator Mode Select                            
CMP0MD_CPMD__SHIFT              EQU 000H ; Comparator Mode Select                            
CMP0MD_CPMD__MODE0              EQU 000H ; Mode 0 (Fastest Response Time, Highest Power      
                                         ; Consumption)                                      
CMP0MD_CPMD__MODE1              EQU 001H ; Mode 1                                            
CMP0MD_CPMD__MODE2              EQU 002H ; Mode 2                                            
CMP0MD_CPMD__MODE3              EQU 003H ; Mode 3 (Slowest Response Time, Lowest Power       
                                         ; Consumption)                                      
                                                                                             
CMP0MD_INSL__FMASK              EQU 00CH ; Comparator Input Selection                        
CMP0MD_INSL__SHIFT              EQU 002H ; Comparator Input Selection                        
CMP0MD_INSL__CMXP_CMXN          EQU 000H ; Connect the comparator inputs directly to the     
                                         ; signals selected in the CMP0MX register. CMP+ is  
                                         ; selected by CMXP and CMP- is selected by CMXN. The
                                         ; internal DAC is not active.                       
CMP0MD_INSL__CMXP_GND           EQU 004H ; Connect the CMP+ input to the signal selected by  
                                         ; CMXP, and CMP- is connected to GND. The internal  
                                         ; DAC is not active.                                
CMP0MD_INSL__DAC_CMXN           EQU 008H ; Connect the CMP+ input to the internal DAC output,
                                         ; and CMP- is selected by CMXN. The internal DAC    
                                         ; uses the signal specified by CMXP as its full-    
                                         ; scale reference.                                  
CMP0MD_INSL__CMXP_DAC           EQU 00CH ; Connect the CMP- input to the internal DAC output,
                                         ; and CMP+ is selected by CMXP. The internal DAC    
                                         ; uses the signal specified by CMXN as its full-    
                                         ; scale reference.                                  
                                                                                             
CMP0MD_CPFIE__BMASK             EQU 010H ; Comparator Falling-Edge Interrupt Enable          
CMP0MD_CPFIE__SHIFT             EQU 004H ; Comparator Falling-Edge Interrupt Enable          
CMP0MD_CPFIE__FALL_INT_DISABLED EQU 000H ; Comparator falling-edge interrupt disabled.       
CMP0MD_CPFIE__FALL_INT_ENABLED  EQU 010H ; Comparator falling-edge interrupt enabled.        
                                                                                             
CMP0MD_CPRIE__BMASK             EQU 020H ; Comparator Rising-Edge Interrupt Enable           
CMP0MD_CPRIE__SHIFT             EQU 005H ; Comparator Rising-Edge Interrupt Enable           
CMP0MD_CPRIE__RISE_INT_DISABLED EQU 000H ; Comparator rising-edge interrupt disabled.        
CMP0MD_CPRIE__RISE_INT_ENABLED  EQU 020H ; Comparator rising-edge interrupt enabled.         
                                                                                             
CMP0MD_CPINV__BMASK             EQU 040H ; Output Inversion                                  
CMP0MD_CPINV__SHIFT             EQU 006H ; Output Inversion                                  
CMP0MD_CPINV__NORMAL            EQU 000H ; Output is not inverted.                           
CMP0MD_CPINV__INVERT            EQU 040H ; Output is inverted.                               
                                                                                             
CMP0MD_CPLOUT__BMASK            EQU 080H ; Comparator Latched Output Flag                    
CMP0MD_CPLOUT__SHIFT            EQU 007H ; Comparator Latched Output Flag                    
CMP0MD_CPLOUT__LOW              EQU 000H ; Comparator output was logic low at last PCA       
                                         ; overflow.                                         
CMP0MD_CPLOUT__HIGH             EQU 080H ; Comparator output was logic high at last PCA      
                                         ; overflow.                                         
                                                                                             
;------------------------------------------------------------------------------
; CMP0MX Enums (Comparator 0 Multiplexer Selection @ 0x9F)
;------------------------------------------------------------------------------
CMP0MX_CMXP__FMASK   EQU 00FH ; Comparator Positive Input MUX Selection
CMP0MX_CMXP__SHIFT   EQU 000H ; Comparator Positive Input MUX Selection
CMP0MX_CMXP__CMP0P0  EQU 000H ; External pin CMP0P.0.                  
CMP0MX_CMXP__CMP0P1  EQU 001H ; External pin CMP0P.1.                  
CMP0MX_CMXP__CMP0P2  EQU 002H ; External pin CMP0P.2.                  
CMP0MX_CMXP__CMP0P3  EQU 003H ; External pin CMP0P.3.                  
CMP0MX_CMXP__CMP0P4  EQU 004H ; External pin CMP0P.4.                  
CMP0MX_CMXP__CMP0P5  EQU 005H ; External pin CMP0P.5.                  
CMP0MX_CMXP__CMP0P6  EQU 006H ; External pin CMP0P.6.                  
CMP0MX_CMXP__CMP0P7  EQU 007H ; External pin CMP0P.7.                  
CMP0MX_CMXP__CMP0P8  EQU 008H ; External pin CMP0P.8.                  
CMP0MX_CMXP__CMP0P9  EQU 009H ; External pin CMP0P.9.                  
CMP0MX_CMXP__CMP0P10 EQU 00AH ; External pin CMP0P.10.                 
CMP0MX_CMXP__CMP0P11 EQU 00BH ; External pin CMP0P.11.                 
CMP0MX_CMXP__CMP0P12 EQU 00CH ; External pin CMP0P.12.                 
CMP0MX_CMXP__CMP0P15 EQU 00FH ; External pin CMP0P.15.                 
                                                                       
CMP0MX_CMXN__FMASK   EQU 0F0H ; Comparator Negative Input MUX Selection
CMP0MX_CMXN__SHIFT   EQU 004H ; Comparator Negative Input MUX Selection
CMP0MX_CMXN__CMP0N0  EQU 000H ; External pin CMP0N.0.                  
CMP0MX_CMXN__CMP0N1  EQU 010H ; External pin CMP0N.1.                  
CMP0MX_CMXN__CMP0N2  EQU 020H ; External pin CMP0N.2.                  
CMP0MX_CMXN__CMP0N3  EQU 030H ; External pin CMP0N.3.                  
CMP0MX_CMXN__CMP0N4  EQU 040H ; External pin CMP0N.4.                  
CMP0MX_CMXN__CMP0N5  EQU 050H ; External pin CMP0N.5.                  
CMP0MX_CMXN__CMP0N6  EQU 060H ; External pin CMP0N.6.                  
CMP0MX_CMXN__CMP0N7  EQU 070H ; External pin CMP0N.7.                  
CMP0MX_CMXN__CMP0N8  EQU 080H ; External pin CMP0N.8.                  
CMP0MX_CMXN__CMP0N9  EQU 090H ; External pin CMP0N.9.                  
CMP0MX_CMXN__CMP0N10 EQU 0A0H ; External pin CMP0N.10.                 
CMP0MX_CMXN__CMP0N11 EQU 0B0H ; External pin CMP0N.11.                 
CMP0MX_CMXN__CMP0N12 EQU 0C0H ; External pin CMP0N.12.                 
CMP0MX_CMXN__CMP0N15 EQU 0F0H ; External pin CMP0N.15.                 
                                                                       
;------------------------------------------------------------------------------
; CMP1CN0 Enums (Comparator 1 Control 0 @ 0xBF)
;------------------------------------------------------------------------------
CMP1CN0_CPHYN__FMASK                EQU 003H ; Comparator Negative Hysteresis Control            
CMP1CN0_CPHYN__SHIFT                EQU 000H ; Comparator Negative Hysteresis Control            
CMP1CN0_CPHYN__DISABLED             EQU 000H ; Negative Hysteresis disabled.                     
CMP1CN0_CPHYN__ENABLED_MODE1        EQU 001H ; Negative Hysteresis = Hysteresis 1.               
CMP1CN0_CPHYN__ENABLED_MODE2        EQU 002H ; Negative Hysteresis = Hysteresis 2.               
CMP1CN0_CPHYN__ENABLED_MODE3        EQU 003H ; Negative Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                 
CMP1CN0_CPHYP__FMASK                EQU 00CH ; Comparator Positive Hysteresis Control            
CMP1CN0_CPHYP__SHIFT                EQU 002H ; Comparator Positive Hysteresis Control            
CMP1CN0_CPHYP__DISABLED             EQU 000H ; Positive Hysteresis disabled.                     
CMP1CN0_CPHYP__ENABLED_MODE1        EQU 004H ; Positive Hysteresis = Hysteresis 1.               
CMP1CN0_CPHYP__ENABLED_MODE2        EQU 008H ; Positive Hysteresis = Hysteresis 2.               
CMP1CN0_CPHYP__ENABLED_MODE3        EQU 00CH ; Positive Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                 
CMP1CN0_CPFIF__BMASK                EQU 010H ; Comparator Falling-Edge Flag                      
CMP1CN0_CPFIF__SHIFT                EQU 004H ; Comparator Falling-Edge Flag                      
CMP1CN0_CPFIF__NOT_SET              EQU 000H ; No comparator falling edge has occurred since this
                                             ; flag was last cleared.                            
CMP1CN0_CPFIF__FALLING_EDGE         EQU 010H ; Comparator falling edge has occurred.             
                                                                                                 
CMP1CN0_CPRIF__BMASK                EQU 020H ; Comparator Rising-Edge Flag                       
CMP1CN0_CPRIF__SHIFT                EQU 005H ; Comparator Rising-Edge Flag                       
CMP1CN0_CPRIF__NOT_SET              EQU 000H ; No comparator rising edge has occurred since this 
                                             ; flag was last cleared.                            
CMP1CN0_CPRIF__RISING_EDGE          EQU 020H ; Comparator rising edge has occurred.              
                                                                                                 
CMP1CN0_CPOUT__BMASK                EQU 040H ; Comparator Output State Flag                      
CMP1CN0_CPOUT__SHIFT                EQU 006H ; Comparator Output State Flag                      
CMP1CN0_CPOUT__POS_LESS_THAN_NEG    EQU 000H ; Voltage on CP1P < CP1N.                           
CMP1CN0_CPOUT__POS_GREATER_THAN_NEG EQU 040H ; Voltage on CP1P > CP1N.                           
                                                                                                 
CMP1CN0_CPEN__BMASK                 EQU 080H ; Comparator Enable                                 
CMP1CN0_CPEN__SHIFT                 EQU 007H ; Comparator Enable                                 
CMP1CN0_CPEN__DISABLED              EQU 000H ; Comparator disabled.                              
CMP1CN0_CPEN__ENABLED               EQU 080H ; Comparator enabled.                               
                                                                                                 
;------------------------------------------------------------------------------
; CMP1CN1 Enums (Comparator 1 Control 1 @ 0xAC)
;------------------------------------------------------------------------------
CMP1CN1_DACLVL__FMASK   EQU 03FH ; Internal Comparator DAC Reference Level           
CMP1CN1_DACLVL__SHIFT   EQU 000H ; Internal Comparator DAC Reference Level           
                                                                                     
CMP1CN1_CPINH__BMASK    EQU 080H ; Output Inhibit                                    
CMP1CN1_CPINH__SHIFT    EQU 007H ; Output Inhibit                                    
CMP1CN1_CPINH__DISABLED EQU 000H ; The comparator output will always reflect the     
                                 ; input conditions.                                 
CMP1CN1_CPINH__ENABLED  EQU 080H ; The comparator output will hold state any time the
                                 ; PCA CEX2 channel is low.                          
                                                                                     
;------------------------------------------------------------------------------
; CMP1MD Enums (Comparator 1 Mode @ 0xAB)
;------------------------------------------------------------------------------
CMP1MD_CPMD__FMASK              EQU 003H ; Comparator Mode Select                            
CMP1MD_CPMD__SHIFT              EQU 000H ; Comparator Mode Select                            
CMP1MD_CPMD__MODE0              EQU 000H ; Mode 0 (Fastest Response Time, Highest Power      
                                         ; Consumption)                                      
CMP1MD_CPMD__MODE1              EQU 001H ; Mode 1                                            
CMP1MD_CPMD__MODE2              EQU 002H ; Mode 2                                            
CMP1MD_CPMD__MODE3              EQU 003H ; Mode 3 (Slowest Response Time, Lowest Power       
                                         ; Consumption)                                      
                                                                                             
CMP1MD_INSL__FMASK              EQU 00CH ; Comparator Input Selection                        
CMP1MD_INSL__SHIFT              EQU 002H ; Comparator Input Selection                        
CMP1MD_INSL__CMXP_CMXN          EQU 000H ; Connect the comparator inputs directly to the     
                                         ; signals selected in the CMP1MX register. CMP+ is  
                                         ; selected by CMXP and CMP- is selected by CMXN. The
                                         ; internal DAC is not active.                       
CMP1MD_INSL__CMXP_GND           EQU 004H ; Connect the CMP+ input to the signal selected by  
                                         ; CMXP, and CMP- is connected to GND. The internal  
                                         ; DAC is not active.                                
CMP1MD_INSL__DAC_CMXN           EQU 008H ; Connect the CMP+ input to the internal DAC output,
                                         ; and CMP- is selected by CMXN. The internal DAC    
                                         ; uses the signal specified by CMXP as its full-    
                                         ; scale reference.                                  
CMP1MD_INSL__CMXP_DAC           EQU 00CH ; Connect the CMP- input to the internal DAC output,
                                         ; and CMP+ is selected by CMXP. The internal DAC    
                                         ; uses the signal specified by CMXN as its full-    
                                         ; scale reference.                                  
                                                                                             
CMP1MD_CPFIE__BMASK             EQU 010H ; Comparator Falling-Edge Interrupt Enable          
CMP1MD_CPFIE__SHIFT             EQU 004H ; Comparator Falling-Edge Interrupt Enable          
CMP1MD_CPFIE__FALL_INT_DISABLED EQU 000H ; Comparator falling-edge interrupt disabled.       
CMP1MD_CPFIE__FALL_INT_ENABLED  EQU 010H ; Comparator falling-edge interrupt enabled.        
                                                                                             
CMP1MD_CPRIE__BMASK             EQU 020H ; Comparator Rising-Edge Interrupt Enable           
CMP1MD_CPRIE__SHIFT             EQU 005H ; Comparator Rising-Edge Interrupt Enable           
CMP1MD_CPRIE__RISE_INT_DISABLED EQU 000H ; Comparator rising-edge interrupt disabled.        
CMP1MD_CPRIE__RISE_INT_ENABLED  EQU 020H ; Comparator rising-edge interrupt enabled.         
                                                                                             
CMP1MD_CPINV__BMASK             EQU 040H ; Output Inversion                                  
CMP1MD_CPINV__SHIFT             EQU 006H ; Output Inversion                                  
CMP1MD_CPINV__NORMAL            EQU 000H ; Output is not inverted.                           
CMP1MD_CPINV__INVERT            EQU 040H ; Output is inverted.                               
                                                                                             
CMP1MD_CPLOUT__BMASK            EQU 080H ; Comparator Latched Output Flag                    
CMP1MD_CPLOUT__SHIFT            EQU 007H ; Comparator Latched Output Flag                    
CMP1MD_CPLOUT__LOW              EQU 000H ; Comparator output was logic low at last PCA       
                                         ; overflow.                                         
CMP1MD_CPLOUT__HIGH             EQU 080H ; Comparator output was logic high at last PCA      
                                         ; overflow.                                         
                                                                                             
;------------------------------------------------------------------------------
; CMP1MX Enums (Comparator 1 Multiplexer Selection @ 0xAA)
;------------------------------------------------------------------------------
CMP1MX_CMXP__FMASK   EQU 00FH ; Comparator Positive Input MUX Selection
CMP1MX_CMXP__SHIFT   EQU 000H ; Comparator Positive Input MUX Selection
CMP1MX_CMXP__CMP1P0  EQU 000H ; External pin CMP1P.0.                  
CMP1MX_CMXP__CMP1P1  EQU 001H ; External pin CMP1P.1.                  
CMP1MX_CMXP__CMP1P2  EQU 002H ; External pin CMP1P.2.                  
CMP1MX_CMXP__CMP1P3  EQU 003H ; External pin CMP1P.3.                  
CMP1MX_CMXP__CMP1P4  EQU 004H ; External pin CMP1P.4.                  
CMP1MX_CMXP__CMP1P5  EQU 005H ; External pin CMP1P.5.                  
CMP1MX_CMXP__CMP1P6  EQU 006H ; External pin CMP1P.6.                  
CMP1MX_CMXP__CMP1P7  EQU 007H ; External pin CMP1P.7.                  
CMP1MX_CMXP__CMP1P8  EQU 008H ; External pin CMP1P.8.                  
CMP1MX_CMXP__CMP1P9  EQU 009H ; External pin CMP1P.9.                  
CMP1MX_CMXP__CMP1P10 EQU 00AH ; External pin CMP1P.10.                 
CMP1MX_CMXP__CMP1P11 EQU 00BH ; External pin CMP1P.11.                 
CMP1MX_CMXP__CMP1P12 EQU 00CH ; External pin CMP1P.12.                 
CMP1MX_CMXP__CMP1P15 EQU 00FH ; External pin CMP1P.15.                 
                                                                       
CMP1MX_CMXN__FMASK   EQU 0F0H ; Comparator Negative Input MUX Selection
CMP1MX_CMXN__SHIFT   EQU 004H ; Comparator Negative Input MUX Selection
CMP1MX_CMXN__CMP1N0  EQU 000H ; External pin CMP1N.0.                  
CMP1MX_CMXN__CMP1N1  EQU 010H ; External pin CMP1N.1.                  
CMP1MX_CMXN__CMP1N2  EQU 020H ; External pin CMP1N.2.                  
CMP1MX_CMXN__CMP1N3  EQU 030H ; External pin CMP1N.3.                  
CMP1MX_CMXN__CMP1N4  EQU 040H ; External pin CMP1N.4.                  
CMP1MX_CMXN__CMP1N5  EQU 050H ; External pin CMP1N.5.                  
CMP1MX_CMXN__CMP1N6  EQU 060H ; External pin CMP1N.6.                  
CMP1MX_CMXN__CMP1N7  EQU 070H ; External pin CMP1N.7.                  
CMP1MX_CMXN__CMP1N8  EQU 080H ; External pin CMP1N.8.                  
CMP1MX_CMXN__CMP1N9  EQU 090H ; External pin CMP1N.9.                  
CMP1MX_CMXN__CMP1N10 EQU 0A0H ; External pin CMP1N.10.                 
CMP1MX_CMXN__CMP1N11 EQU 0B0H ; External pin CMP1N.11.                 
CMP1MX_CMXN__CMP1N12 EQU 0C0H ; External pin CMP1N.12.                 
CMP1MX_CMXN__CMP1N15 EQU 0F0H ; External pin CMP1N.15.                 
                                                                       
;------------------------------------------------------------------------------
; CRC0CN0 Enums (CRC0 Control 0 @ 0xCE)
;------------------------------------------------------------------------------
CRC0CN0_CRCPNT__BMASK        EQU 001H ; CRC Result Pointer                               
CRC0CN0_CRCPNT__SHIFT        EQU 000H ; CRC Result Pointer                               
CRC0CN0_CRCPNT__ACCESS_LOWER EQU 000H ; CRC0DAT accesses bits 7-0 of the 16-bit CRC      
                                      ; result.                                          
CRC0CN0_CRCPNT__ACCESS_UPPER EQU 001H ; CRC0DAT accesses bits 15-8 of the 16-bit CRC     
                                      ; result.                                          
                                                                                         
CRC0CN0_CRCVAL__BMASK        EQU 004H ; CRC Initialization Value                         
CRC0CN0_CRCVAL__SHIFT        EQU 002H ; CRC Initialization Value                         
CRC0CN0_CRCVAL__SET_ZEROES   EQU 000H ; CRC result is set to 0x0000 on write of 1 to     
                                      ; CRCINIT.                                         
CRC0CN0_CRCVAL__SET_ONES     EQU 004H ; CRC result is set to 0xFFFF on write of 1 to     
                                      ; CRCINIT.                                         
                                                                                         
CRC0CN0_CRCINIT__BMASK       EQU 008H ; CRC Initialization Enable                        
CRC0CN0_CRCINIT__SHIFT       EQU 003H ; CRC Initialization Enable                        
CRC0CN0_CRCINIT__DO_NOT_INIT EQU 000H ; Do not initialize the CRC result.                
CRC0CN0_CRCINIT__INIT        EQU 008H ; Initialize the CRC result to ones or zeroes vased
                                      ; on the value of CRCVAL.                          
                                                                                         
;------------------------------------------------------------------------------
; CRC0CN1 Enums (CRC0 Control 1 @ 0x86)
;------------------------------------------------------------------------------
CRC0CN1_CRCDN__BMASK     EQU 040H ; Automatic CRC Calculation Complete        
CRC0CN1_CRCDN__SHIFT     EQU 006H ; Automatic CRC Calculation Complete        
CRC0CN1_CRCDN__NOT_SET   EQU 000H ; A CRC calculation is in progress.         
CRC0CN1_CRCDN__SET       EQU 040H ; A CRC calculation is not in progress.     
                                                                              
CRC0CN1_AUTOEN__BMASK    EQU 080H ; Automatic CRC Calculation Enable          
CRC0CN1_AUTOEN__SHIFT    EQU 007H ; Automatic CRC Calculation Enable          
CRC0CN1_AUTOEN__DISABLED EQU 000H ; Disable automatic CRC operations on flash.
CRC0CN1_AUTOEN__ENABLED  EQU 080H ; Enable automatic CRC operations on flash. 
                                                                              
;------------------------------------------------------------------------------
; CRC0CNT Enums (CRC0 Automatic Flash Sector Count @ 0xD3)
;------------------------------------------------------------------------------
CRC0CNT_CRCCNT__FMASK EQU 0FFH ; Automatic CRC Calculation Block Count
CRC0CNT_CRCCNT__SHIFT EQU 000H ; Automatic CRC Calculation Block Count
                                                                      
;------------------------------------------------------------------------------
; CRC0DAT Enums (CRC0 Data Output @ 0xDE)
;------------------------------------------------------------------------------
CRC0DAT_CRC0DAT__FMASK EQU 0FFH ; CRC Data Output
CRC0DAT_CRC0DAT__SHIFT EQU 000H ; CRC Data Output
                                                 
;------------------------------------------------------------------------------
; CRC0FLIP Enums (CRC0 Bit Flip @ 0xCF)
;------------------------------------------------------------------------------
CRC0FLIP_CRC0FLIP__FMASK EQU 0FFH ; CRC0 Bit Flip
CRC0FLIP_CRC0FLIP__SHIFT EQU 000H ; CRC0 Bit Flip
                                                 
;------------------------------------------------------------------------------
; CRC0IN Enums (CRC0 Data Input @ 0xDD)
;------------------------------------------------------------------------------
CRC0IN_CRC0IN__FMASK EQU 0FFH ; CRC Data Input
CRC0IN_CRC0IN__SHIFT EQU 000H ; CRC Data Input
                                              
;------------------------------------------------------------------------------
; CRC0ST Enums (CRC0 Automatic Flash Sector Start @ 0xD2)
;------------------------------------------------------------------------------
CRC0ST_CRCST__FMASK EQU 0FFH ; Automatic CRC Calculation Starting Block
CRC0ST_CRCST__SHIFT EQU 000H ; Automatic CRC Calculation Starting Block
                                                                       
;------------------------------------------------------------------------------
; DERIVID Enums (Derivative Identification @ 0xAD)
;------------------------------------------------------------------------------
DERIVID_DERIVID__FMASK               EQU 0FFH ; Derivative ID          
DERIVID_DERIVID__SHIFT               EQU 000H ; Derivative ID          
DERIVID_DERIVID__EFM8UB30F40G_QFN20  EQU 000H ; EFM8UB30F40G-{R}-QFN20 
DERIVID_DERIVID__EFM8UB31F40G_QFN24  EQU 001H ; EFM8UB31F40G-{R}-QFN24 
DERIVID_DERIVID__EFM8UB31F40G_QSOP24 EQU 002H ; EFM8UB31F40G-{R}-QSOP24
                                                                       
;------------------------------------------------------------------------------
; DEVICEID Enums (Device Identification @ 0xB5)
;------------------------------------------------------------------------------
DEVICEID_DEVICEID__FMASK EQU 0FFH ; Device ID
DEVICEID_DEVICEID__SHIFT EQU 000H ; Device ID
                                             
;------------------------------------------------------------------------------
; REVID Enums (Revision Identifcation @ 0xB6)
;------------------------------------------------------------------------------
REVID_REVID__FMASK EQU 0FFH ; Revision ID
REVID_REVID__SHIFT EQU 000H ; Revision ID
REVID_REVID__REV_A EQU 000H ; Revision A.
                                         
;------------------------------------------------------------------------------
; IT01CF Enums (INT0/INT1 Configuration @ 0x85)
;------------------------------------------------------------------------------
IT01CF_IN0SL__FMASK       EQU 007H ; INT0 Port Pin Selection   
IT01CF_IN0SL__SHIFT       EQU 000H ; INT0 Port Pin Selection   
IT01CF_IN0SL__P0_0        EQU 000H ; Select P0.0.              
IT01CF_IN0SL__P0_1        EQU 001H ; Select P0.1.              
IT01CF_IN0SL__P0_2        EQU 002H ; Select P0.2.              
IT01CF_IN0SL__P0_3        EQU 003H ; Select P0.3.              
IT01CF_IN0SL__P0_4        EQU 004H ; Select P0.4.              
IT01CF_IN0SL__P0_5        EQU 005H ; Select P0.5.              
IT01CF_IN0SL__P0_6        EQU 006H ; Select P0.6.              
IT01CF_IN0SL__P0_7        EQU 007H ; Select P0.7.              
                                                               
IT01CF_IN0PL__BMASK       EQU 008H ; INT0 Polarity             
IT01CF_IN0PL__SHIFT       EQU 003H ; INT0 Polarity             
IT01CF_IN0PL__ACTIVE_LOW  EQU 000H ; INT0 input is active low. 
IT01CF_IN0PL__ACTIVE_HIGH EQU 008H ; INT0 input is active high.
                                                               
IT01CF_IN1SL__FMASK       EQU 070H ; INT1 Port Pin Selection   
IT01CF_IN1SL__SHIFT       EQU 004H ; INT1 Port Pin Selection   
IT01CF_IN1SL__P0_0        EQU 000H ; Select P0.0.              
IT01CF_IN1SL__P0_1        EQU 010H ; Select P0.1.              
IT01CF_IN1SL__P0_2        EQU 020H ; Select P0.2.              
IT01CF_IN1SL__P0_3        EQU 030H ; Select P0.3.              
IT01CF_IN1SL__P0_4        EQU 040H ; Select P0.4.              
IT01CF_IN1SL__P0_5        EQU 050H ; Select P0.5.              
IT01CF_IN1SL__P0_6        EQU 060H ; Select P0.6.              
IT01CF_IN1SL__P0_7        EQU 070H ; Select P0.7.              
                                                               
IT01CF_IN1PL__BMASK       EQU 080H ; INT1 Polarity             
IT01CF_IN1PL__SHIFT       EQU 007H ; INT1 Polarity             
IT01CF_IN1PL__ACTIVE_LOW  EQU 000H ; INT1 input is active low. 
IT01CF_IN1PL__ACTIVE_HIGH EQU 080H ; INT1 input is active high.
                                                               
;------------------------------------------------------------------------------
; FLKEY Enums (Flash Lock and Key @ 0xB7)
;------------------------------------------------------------------------------
FLKEY_FLKEY__FMASK    EQU 0FFH ; Flash Lock and Key                             
FLKEY_FLKEY__SHIFT    EQU 000H ; Flash Lock and Key                             
FLKEY_FLKEY__LOCKED   EQU 000H ; Flash is write/erase locked.                   
FLKEY_FLKEY__FIRST    EQU 001H ; The first key code has been written (0xA5).    
FLKEY_FLKEY__UNLOCKED EQU 002H ; Flash is unlocked (writes/erases allowed).     
FLKEY_FLKEY__DISABLED EQU 003H ; Flash writes/erases are disabled until the next
                               ; reset.                                         
FLKEY_FLKEY__KEY1     EQU 0A5H ; Flash writes and erases are enabled by writing 
                               ; 0xA5 followed by 0xF1 to the FLKEY register.   
FLKEY_FLKEY__KEY2     EQU 0F1H ; Flash writes and erases are enabled by writing 
                               ; 0xA5 followed by 0xF1 to the FLKEY register.   
                                                                                
;------------------------------------------------------------------------------
; PSCTL Enums (Program Store Control @ 0x8F)
;------------------------------------------------------------------------------
PSCTL_PSWE__BMASK          EQU 001H ; Program Store Write Enable                      
PSCTL_PSWE__SHIFT          EQU 000H ; Program Store Write Enable                      
PSCTL_PSWE__WRITE_DISABLED EQU 000H ; Writes to flash program memory disabled.        
PSCTL_PSWE__WRITE_ENABLED  EQU 001H ; Writes to flash program memory enabled; the MOVX
                                    ; write instruction targets flash memory.         
                                                                                      
PSCTL_PSEE__BMASK          EQU 002H ; Program Store Erase Enable                      
PSCTL_PSEE__SHIFT          EQU 001H ; Program Store Erase Enable                      
PSCTL_PSEE__ERASE_DISABLED EQU 000H ; Flash program memory erasure disabled.          
PSCTL_PSEE__ERASE_ENABLED  EQU 002H ; Flash program memory erasure enabled.           
                                                                                      
;------------------------------------------------------------------------------
; HFO0CAL Enums (High Frequency Oscillator 0 Calibration @ 0xC7)
;------------------------------------------------------------------------------
HFO0CAL_HFO0CAL__FMASK EQU 0FFH ; Oscillator Calibration
HFO0CAL_HFO0CAL__SHIFT EQU 000H ; Oscillator Calibration
                                                        
;------------------------------------------------------------------------------
; HFO1CAL Enums (High Frequency Oscillator 1 Calibration @ 0xD6)
;------------------------------------------------------------------------------
HFO1CAL_HFO1CAL__FMASK EQU 07FH ; Oscillator Calibration
HFO1CAL_HFO1CAL__SHIFT EQU 000H ; Oscillator Calibration
                                                        
;------------------------------------------------------------------------------
; HFOCN Enums (High Frequency Oscillator Control @ 0xEF)
;------------------------------------------------------------------------------
HFOCN_HFO0EN__BMASK    EQU 008H ; HFOSC0 Oscillator Enable                        
HFOCN_HFO0EN__SHIFT    EQU 003H ; HFOSC0 Oscillator Enable                        
HFOCN_HFO0EN__DISABLED EQU 000H ; Disable High Frequency Oscillator 0 (HFOSC0 will
                                ; still turn on if requested by any block in the  
                                ; device or selected as the SYSCLK source).       
HFOCN_HFO0EN__ENABLED  EQU 008H ; Force High Frequency Oscillator 0 to run.       
                                                                                  
HFOCN_HFO1EN__BMASK    EQU 080H ; HFOSC1 Oscillator Enable                        
HFOCN_HFO1EN__SHIFT    EQU 007H ; HFOSC1 Oscillator Enable                        
HFOCN_HFO1EN__DISABLED EQU 000H ; Disable High Frequency Oscillator 1 (HFOSC1 will
                                ; still turn on if requested by any block in the  
                                ; device or selected as the SYSCLK source).       
HFOCN_HFO1EN__ENABLED  EQU 080H ; Force High Frequency Oscillator 1 to run.       
                                                                                  
;------------------------------------------------------------------------------
; EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
;------------------------------------------------------------------------------
EIE1_ESMB0__BMASK     EQU 001H ; SMBus (SMB0) Interrupt Enable                     
EIE1_ESMB0__SHIFT     EQU 000H ; SMBus (SMB0) Interrupt Enable                     
EIE1_ESMB0__DISABLED  EQU 000H ; Disable all SMB0 interrupts.                      
EIE1_ESMB0__ENABLED   EQU 001H ; Enable interrupt requests generated by SMB0.      
                                                                                   
EIE1_EMAT__BMASK      EQU 002H ; Port Match Interrupts Enable                      
EIE1_EMAT__SHIFT      EQU 001H ; Port Match Interrupts Enable                      
EIE1_EMAT__DISABLED   EQU 000H ; Disable all Port Match interrupts.                
EIE1_EMAT__ENABLED    EQU 002H ; Enable interrupt requests generated by a Port     
                               ; Match.                                            
                                                                                   
EIE1_EWADC0__BMASK    EQU 004H ; ADC0 Window Comparison Interrupt Enable           
EIE1_EWADC0__SHIFT    EQU 002H ; ADC0 Window Comparison Interrupt Enable           
EIE1_EWADC0__DISABLED EQU 000H ; Disable ADC0 Window Comparison interrupt.         
EIE1_EWADC0__ENABLED  EQU 004H ; Enable interrupt requests generated by ADC0 Window
                               ; Compare flag (ADWINT).                            
                                                                                   
EIE1_EADC0__BMASK     EQU 008H ; ADC0 Conversion Complete Interrupt Enable         
EIE1_EADC0__SHIFT     EQU 003H ; ADC0 Conversion Complete Interrupt Enable         
EIE1_EADC0__DISABLED  EQU 000H ; Disable ADC0 Conversion Complete interrupt.       
EIE1_EADC0__ENABLED   EQU 008H ; Enable interrupt requests generated by the ADINT  
                               ; flag.                                             
                                                                                   
EIE1_EPCA0__BMASK     EQU 010H ; Programmable Counter Array (PCA0) Interrupt Enable
EIE1_EPCA0__SHIFT     EQU 004H ; Programmable Counter Array (PCA0) Interrupt Enable
EIE1_EPCA0__DISABLED  EQU 000H ; Disable all PCA0 interrupts.                      
EIE1_EPCA0__ENABLED   EQU 010H ; Enable interrupt requests generated by PCA0.      
                                                                                   
EIE1_ECP0__BMASK      EQU 020H ; Comparator0 (CP0) Interrupt Enable                
EIE1_ECP0__SHIFT      EQU 005H ; Comparator0 (CP0) Interrupt Enable                
EIE1_ECP0__DISABLED   EQU 000H ; Disable CP0 interrupts.                           
EIE1_ECP0__ENABLED    EQU 020H ; Enable interrupt requests generated by the        
                               ; comparator 0 CPRIF or CPFIF flags.                
                                                                                   
EIE1_ECP1__BMASK      EQU 040H ; Comparator1 (CP1) Interrupt Enable                
EIE1_ECP1__SHIFT      EQU 006H ; Comparator1 (CP1) Interrupt Enable                
EIE1_ECP1__DISABLED   EQU 000H ; Disable CP1 interrupts.                           
EIE1_ECP1__ENABLED    EQU 040H ; Enable interrupt requests generated by the        
                               ; comparator 1 CPRIF or CPFIF flags.                
                                                                                   
EIE1_ET3__BMASK       EQU 080H ; Timer 3 Interrupt Enable                          
EIE1_ET3__SHIFT       EQU 007H ; Timer 3 Interrupt Enable                          
EIE1_ET3__DISABLED    EQU 000H ; Disable Timer 3 interrupts.                       
EIE1_ET3__ENABLED     EQU 080H ; Enable interrupt requests generated by the TF3L or
                               ; TF3H flags.                                       
                                                                                   
;------------------------------------------------------------------------------
; EIE2 Enums (Extended Interrupt Enable 2 @ 0xCE)
;------------------------------------------------------------------------------
EIE2_EUSB0__BMASK    EQU 001H ; USB (USB0) Interrupt Enable                       
EIE2_EUSB0__SHIFT    EQU 000H ; USB (USB0) Interrupt Enable                       
EIE2_EUSB0__DISABLED EQU 000H ; Disable all USB0 interrupts.                      
EIE2_EUSB0__ENABLED  EQU 001H ; Enable interrupt requests generated by USB0.      
                                                                                  
EIE2_EVBUS__BMASK    EQU 002H ; VBUS and USB Charger Detect Interrupt             
EIE2_EVBUS__SHIFT    EQU 001H ; VBUS and USB Charger Detect Interrupt             
EIE2_EVBUS__DISABLED EQU 000H ; Disable all VBUS and VBUS and USB Charger Detect  
                              ; interrupts.                                       
EIE2_EVBUS__ENABLED  EQU 002H ; Enable interrupt requests generated by VBUS and   
                              ; VBUS and USB Charger Detect.                      
                                                                                  
EIE2_ET4__BMASK      EQU 004H ; Timer 4 Interrupt Enable                          
EIE2_ET4__SHIFT      EQU 002H ; Timer 4 Interrupt Enable                          
EIE2_ET4__DISABLED   EQU 000H ; Disable Timer 4 interrupts.                       
EIE2_ET4__ENABLED    EQU 004H ; Enable interrupt requests generated by the TF4L or
                              ; TF4H flags.                                       
                                                                                  
EIE2_ET5__BMASK      EQU 008H ; Timer 5 Interrupt Enable                          
EIE2_ET5__SHIFT      EQU 003H ; Timer 5 Interrupt Enable                          
EIE2_ET5__DISABLED   EQU 000H ; Disable Timer 5 interrupts.                       
EIE2_ET5__ENABLED    EQU 008H ; Enable interrupt requests generated by the TF5L or
                              ; TF5H flags.                                       
                                                                                  
EIE2_ECL0__BMASK     EQU 040H ; Configurable Logic (CL0) Interrupt Enable         
EIE2_ECL0__SHIFT     EQU 006H ; Configurable Logic (CL0) Interrupt Enable         
EIE2_ECL0__DISABLED  EQU 000H ; Disable CL0 interrupts.                           
EIE2_ECL0__ENABLED   EQU 040H ; Enable interrupt requests generated by CL0.       
                                                                                  
;------------------------------------------------------------------------------
; EIP1 Enums (Extended Interrupt Priority 1 Low @ 0xF3)
;------------------------------------------------------------------------------
EIP1_PSMB0__BMASK  EQU 001H ; SMBus (SMB0) Interrupt Priority Control LSB                     
EIP1_PSMB0__SHIFT  EQU 000H ; SMBus (SMB0) Interrupt Priority Control LSB                     
EIP1_PSMB0__LOW    EQU 000H ; SMB0 interrupt priority LSB set to low.                         
EIP1_PSMB0__HIGH   EQU 001H ; SMB0 interrupt priority LSB set to high.                        
                                                                                              
EIP1_PMAT__BMASK   EQU 002H ; Port Match Interrupt Priority Control LSB                       
EIP1_PMAT__SHIFT   EQU 001H ; Port Match Interrupt Priority Control LSB                       
EIP1_PMAT__LOW     EQU 000H ; Port Match interrupt priority LSB set to low.                   
EIP1_PMAT__HIGH    EQU 002H ; Port Match interrupt priority LSB set to high.                  
                                                                                              
EIP1_PWADC0__BMASK EQU 004H ; ADC0 Window Comparator Interrupt Priority Control LSB           
EIP1_PWADC0__SHIFT EQU 002H ; ADC0 Window Comparator Interrupt Priority Control LSB           
EIP1_PWADC0__LOW   EQU 000H ; ADC0 Window interrupt priority LSB set to low.                  
EIP1_PWADC0__HIGH  EQU 004H ; ADC0 Window interrupt priority LSB set to high.                 
                                                                                              
EIP1_PADC0__BMASK  EQU 008H ; ADC0 Conversion Complete Interrupt Priority Control LSB         
EIP1_PADC0__SHIFT  EQU 003H ; ADC0 Conversion Complete Interrupt Priority Control LSB         
EIP1_PADC0__LOW    EQU 000H ; ADC0 Conversion Complete interrupt priority LSB                 
                            ; set to low.                                                     
EIP1_PADC0__HIGH   EQU 008H ; ADC0 Conversion Complete interrupt priority LSB                 
                            ; set to high.                                                    
                                                                                              
EIP1_PPCA0__BMASK  EQU 010H ; Programmable Counter Array (PCA0) Interrupt Priority Control LSB
EIP1_PPCA0__SHIFT  EQU 004H ; Programmable Counter Array (PCA0) Interrupt Priority Control LSB
EIP1_PPCA0__LOW    EQU 000H ; PCA0 interrupt priority LSB set to low.                         
EIP1_PPCA0__HIGH   EQU 010H ; PCA0 interrupt priority LSB set to high.                        
                                                                                              
EIP1_PCP0__BMASK   EQU 020H ; Comparator0 (CP0) Interrupt Priority Control LSB                
EIP1_PCP0__SHIFT   EQU 005H ; Comparator0 (CP0) Interrupt Priority Control LSB                
EIP1_PCP0__LOW     EQU 000H ; CP0 interrupt priority LSB set to low.                          
EIP1_PCP0__HIGH    EQU 020H ; CP0 interrupt priority LSB set to high.                         
                                                                                              
EIP1_PCP1__BMASK   EQU 040H ; Comparator1 (CP1) Interrupt Priority Control LSB                
EIP1_PCP1__SHIFT   EQU 006H ; Comparator1 (CP1) Interrupt Priority Control LSB                
EIP1_PCP1__LOW     EQU 000H ; CP1 interrupt priority LSB set to low.                          
EIP1_PCP1__HIGH    EQU 040H ; CP1 interrupt priority LSB set to high.                         
                                                                                              
EIP1_PT3__BMASK    EQU 080H ; Timer 3 Interrupt Priority Control LSB                          
EIP1_PT3__SHIFT    EQU 007H ; Timer 3 Interrupt Priority Control LSB                          
EIP1_PT3__LOW      EQU 000H ; Timer 3 interrupt priority LSB set to low.                      
EIP1_PT3__HIGH     EQU 080H ; Timer 3 interrupt priority LSB set to high.                     
                                                                                              
;------------------------------------------------------------------------------
; EIP1H Enums (Extended Interrupt Priority 1 High @ 0xF5)
;------------------------------------------------------------------------------
EIP1H_PHSMB0__BMASK  EQU 001H ; SMBus (SMB0) Interrupt Priority Control MSB                     
EIP1H_PHSMB0__SHIFT  EQU 000H ; SMBus (SMB0) Interrupt Priority Control MSB                     
EIP1H_PHSMB0__LOW    EQU 000H ; SMB0 interrupt priority MSB set to low.                         
EIP1H_PHSMB0__HIGH   EQU 001H ; SMB0 interrupt priority MSB set to high.                        
                                                                                                
EIP1H_PHMAT__BMASK   EQU 002H ; Port Match Interrupt Priority Control MSB                       
EIP1H_PHMAT__SHIFT   EQU 001H ; Port Match Interrupt Priority Control MSB                       
EIP1H_PHMAT__LOW     EQU 000H ; Port Match interrupt priority MSB set to low.                   
EIP1H_PHMAT__HIGH    EQU 002H ; Port Match interrupt priority MSB set to high.                  
                                                                                                
EIP1H_PHWADC0__BMASK EQU 004H ; ADC0 Window Comparator Interrupt Priority Control MSB           
EIP1H_PHWADC0__SHIFT EQU 002H ; ADC0 Window Comparator Interrupt Priority Control MSB           
EIP1H_PHWADC0__LOW   EQU 000H ; ADC0 Window interrupt priority MSB set to low.                  
EIP1H_PHWADC0__HIGH  EQU 004H ; ADC0 Window interrupt priority MSB set to high.                 
                                                                                                
EIP1H_PHADC0__BMASK  EQU 008H ; ADC0 Conversion Complete Interrupt Priority Control MSB         
EIP1H_PHADC0__SHIFT  EQU 003H ; ADC0 Conversion Complete Interrupt Priority Control MSB         
EIP1H_PHADC0__LOW    EQU 000H ; ADC0 Conversion Complete interrupt priority MSB                 
                              ; set to low.                                                     
EIP1H_PHADC0__HIGH   EQU 008H ; ADC0 Conversion Complete interrupt priority MSB                 
                              ; set to high.                                                    
                                                                                                
EIP1H_PHPCA0__BMASK  EQU 010H ; Programmable Counter Array (PCA0) Interrupt Priority Control MSB
EIP1H_PHPCA0__SHIFT  EQU 004H ; Programmable Counter Array (PCA0) Interrupt Priority Control MSB
EIP1H_PHPCA0__LOW    EQU 000H ; PCA0 interrupt priority MSB set to low.                         
EIP1H_PHPCA0__HIGH   EQU 010H ; PCA0 interrupt priority MSB set to high.                        
                                                                                                
EIP1H_PHCP0__BMASK   EQU 020H ; Comparator0 (CP0) Interrupt Priority Control MSB                
EIP1H_PHCP0__SHIFT   EQU 005H ; Comparator0 (CP0) Interrupt Priority Control MSB                
EIP1H_PHCP0__LOW     EQU 000H ; CP0 interrupt priority MSB set to low.                          
EIP1H_PHCP0__HIGH    EQU 020H ; CP0 interrupt priority MSB set to high.                         
                                                                                                
EIP1H_PHCP1__BMASK   EQU 040H ; Comparator1 (CP1) Interrupt Priority Control MSB                
EIP1H_PHCP1__SHIFT   EQU 006H ; Comparator1 (CP1) Interrupt Priority Control MSB                
EIP1H_PHCP1__LOW     EQU 000H ; CP1 interrupt priority MSB set to low.                          
EIP1H_PHCP1__HIGH    EQU 040H ; CP1 interrupt priority MSB set to high.                         
                                                                                                
EIP1H_PHT3__BMASK    EQU 080H ; Timer 3 Interrupt Priority Control MSB                          
EIP1H_PHT3__SHIFT    EQU 007H ; Timer 3 Interrupt Priority Control MSB                          
EIP1H_PHT3__LOW      EQU 000H ; Timer 3 interrupt priority MSB set to low.                      
EIP1H_PHT3__HIGH     EQU 080H ; Timer 3 interrupt priority MSB set to high.                     
                                                                                                
;------------------------------------------------------------------------------
; EIP2 Enums (Extended Interrupt Priority 2 @ 0xF4)
;------------------------------------------------------------------------------
EIP2_PUSB0__BMASK EQU 001H ; USB (USB0) Interrupt Priority Control LSB                 
EIP2_PUSB0__SHIFT EQU 000H ; USB (USB0) Interrupt Priority Control LSB                 
EIP2_PUSB0__LOW   EQU 000H ; USB0 interrupt priority LSB set to low.                   
EIP2_PUSB0__HIGH  EQU 001H ; USB0 interrupt priority LSB set to high.                  
                                                                                       
EIP2_PVBUS__BMASK EQU 002H ; VBUS and USB Charger Detect Interrupt Priority Control LSB
EIP2_PVBUS__SHIFT EQU 001H ; VBUS and USB Charger Detect Interrupt Priority Control LSB
EIP2_PVBUS__LOW   EQU 000H ; VBUS / USB Charger Detect interrupt priority LSB          
                           ; set to low.                                               
EIP2_PVBUS__HIGH  EQU 002H ; VBUS / USB Charger Detect interrupt priority LSB          
                           ; set to high.                                              
                                                                                       
EIP2_PT4__BMASK   EQU 004H ; Timer 4 Interrupt Priority Control LSB                    
EIP2_PT4__SHIFT   EQU 002H ; Timer 4 Interrupt Priority Control LSB                    
EIP2_PT4__LOW     EQU 000H ; Timer 4 interrupt priority LSB set to low.                
EIP2_PT4__HIGH    EQU 004H ; Timer 4 interrupt priority LSB set to high.               
                                                                                       
EIP2_PT5__BMASK   EQU 008H ; Timer 5 Interrupt Priority Control LSB                    
EIP2_PT5__SHIFT   EQU 003H ; Timer 5 Interrupt Priority Control LSB                    
EIP2_PT5__LOW     EQU 000H ; Timer 5 interrupt priority LSB set to low.                
EIP2_PT5__HIGH    EQU 008H ; Timer 4 interrupt priority LSB set to high.               
                                                                                       
EIP2_PCL0__BMASK  EQU 040H ; Configurable Logic (CL0) Interrupt Priority Control LSB   
EIP2_PCL0__SHIFT  EQU 006H ; Configurable Logic (CL0) Interrupt Priority Control LSB   
EIP2_PCL0__LOW    EQU 000H ; CL0 interrupt priority LSB set to low.                    
EIP2_PCL0__HIGH   EQU 040H ; CL0 interrupt priority LSB set to high.                   
                                                                                       
;------------------------------------------------------------------------------
; EIP2H Enums (Extended Interrupt Priority 2 High @ 0xF6)
;------------------------------------------------------------------------------
EIP2H_PHUSB0__BMASK EQU 001H ; USB (USB0) Interrupt Priority Control MSB                 
EIP2H_PHUSB0__SHIFT EQU 000H ; USB (USB0) Interrupt Priority Control MSB                 
EIP2H_PHUSB0__LOW   EQU 000H ; USB0 interrupt priority MSB set to low.                   
EIP2H_PHUSB0__HIGH  EQU 001H ; USB0 interrupt priority MSB set to high.                  
                                                                                         
EIP2H_PHVBUS__BMASK EQU 002H ; VBUS and USB Charger Detect Interrupt Priority Control MSB
EIP2H_PHVBUS__SHIFT EQU 001H ; VBUS and USB Charger Detect Interrupt Priority Control MSB
EIP2H_PHVBUS__LOW   EQU 000H ; VBUS / USB Charger Detect interrupt priority MSB          
                             ; set to low.                                               
EIP2H_PHVBUS__HIGH  EQU 002H ; VBUS / USB Charger Detect interrupt priority MSB          
                             ; set to high.                                              
                                                                                         
EIP2H_PHT4__BMASK   EQU 004H ; Timer 4 Interrupt Priority Control MSB                    
EIP2H_PHT4__SHIFT   EQU 002H ; Timer 4 Interrupt Priority Control MSB                    
EIP2H_PHT4__LOW     EQU 000H ; Timer 4 interrupt priority MSB set to low.                
EIP2H_PHT4__HIGH    EQU 004H ; Timer 4 interrupt priority MSB set to high.               
                                                                                         
EIP2H_PHT5__BMASK   EQU 008H ; Timer 5 Interrupt Priority Control MSB                    
EIP2H_PHT5__SHIFT   EQU 003H ; Timer 5 Interrupt Priority Control MSB                    
EIP2H_PHT5__LOW     EQU 000H ; Timer 5 interrupt priority MSB set to low.                
EIP2H_PHT5__HIGH    EQU 008H ; Timer 5 interrupt priority MSB set to high.               
                                                                                         
EIP2H_PHCL0__BMASK  EQU 040H ; Configurable Logic (CL0) Interrupt Priority Control MSB   
EIP2H_PHCL0__SHIFT  EQU 006H ; Configurable Logic (CL0) Interrupt Priority Control MSB   
EIP2H_PHCL0__LOW    EQU 000H ; CL0 interrupt priority MSB set to low.                    
EIP2H_PHCL0__HIGH   EQU 040H ; CL0 interrupt priority MSB set to high.                   
                                                                                         
;------------------------------------------------------------------------------
; IE Enums (Interrupt Enable @ 0xA8)
;------------------------------------------------------------------------------
IE_EX0__BMASK      EQU 001H ; External Interrupt 0 Enable                       
IE_EX0__SHIFT      EQU 000H ; External Interrupt 0 Enable                       
IE_EX0__DISABLED   EQU 000H ; Disable external interrupt 0.                     
IE_EX0__ENABLED    EQU 001H ; Enable interrupt requests generated by the INT0   
                            ; input.                                            
                                                                                
IE_ET0__BMASK      EQU 002H ; Timer 0 Interrupt Enable                          
IE_ET0__SHIFT      EQU 001H ; Timer 0 Interrupt Enable                          
IE_ET0__DISABLED   EQU 000H ; Disable all Timer 0 interrupt.                    
IE_ET0__ENABLED    EQU 002H ; Enable interrupt requests generated by the TF0    
                            ; flag.                                             
                                                                                
IE_EX1__BMASK      EQU 004H ; External Interrupt 1 Enable                       
IE_EX1__SHIFT      EQU 002H ; External Interrupt 1 Enable                       
IE_EX1__DISABLED   EQU 000H ; Disable external interrupt 1.                     
IE_EX1__ENABLED    EQU 004H ; Enable interrupt requests generated by the INT1   
                            ; input.                                            
                                                                                
IE_ET1__BMASK      EQU 008H ; Timer 1 Interrupt Enable                          
IE_ET1__SHIFT      EQU 003H ; Timer 1 Interrupt Enable                          
IE_ET1__DISABLED   EQU 000H ; Disable all Timer 1 interrupt.                    
IE_ET1__ENABLED    EQU 008H ; Enable interrupt requests generated by the TF1    
                            ; flag.                                             
                                                                                
IE_ES1__BMASK      EQU 010H ; UART1 Interrupt Enable                            
IE_ES1__SHIFT      EQU 004H ; UART1 Interrupt Enable                            
IE_ES1__DISABLED   EQU 000H ; Disable UART1 interrupts.                         
IE_ES1__ENABLED    EQU 010H ; Enable UART1 interrupts.                          
                                                                                
IE_ET2__BMASK      EQU 020H ; Timer 2 Interrupt Enable                          
IE_ET2__SHIFT      EQU 005H ; Timer 2 Interrupt Enable                          
IE_ET2__DISABLED   EQU 000H ; Disable Timer 2 interrupt.                        
IE_ET2__ENABLED    EQU 020H ; Enable interrupt requests generated by the TF2L or
                            ; TF2H flags.                                       
                                                                                
IE_ESPI0__BMASK    EQU 040H ; SPI0 Interrupt Enable                             
IE_ESPI0__SHIFT    EQU 006H ; SPI0 Interrupt Enable                             
IE_ESPI0__DISABLED EQU 000H ; Disable all SPI0 interrupts.                      
IE_ESPI0__ENABLED  EQU 040H ; Enable interrupt requests generated by SPI0.      
                                                                                
IE_EA__BMASK       EQU 080H ; All Interrupts Enable                             
IE_EA__SHIFT       EQU 007H ; All Interrupts Enable                             
IE_EA__DISABLED    EQU 000H ; Disable all interrupt sources.                    
IE_EA__ENABLED     EQU 080H ; Enable each interrupt according to its individual 
                            ; mask setting.                                     
                                                                                
;------------------------------------------------------------------------------
; IP Enums (Interrupt Priority @ 0xB8)
;------------------------------------------------------------------------------
IP_PX0__BMASK   EQU 001H ; External Interrupt 0 Priority Control LSB                        
IP_PX0__SHIFT   EQU 000H ; External Interrupt 0 Priority Control LSB                        
IP_PX0__LOW     EQU 000H ; External Interrupt 0 priority LSB set to low.                    
IP_PX0__HIGH    EQU 001H ; External Interrupt 0 priority LSB set to high.                   
                                                                                            
IP_PT0__BMASK   EQU 002H ; Timer 0 Interrupt Priority Control LSB                           
IP_PT0__SHIFT   EQU 001H ; Timer 0 Interrupt Priority Control LSB                           
IP_PT0__LOW     EQU 000H ; Timer 0 interrupt priority LSB set to low.                       
IP_PT0__HIGH    EQU 002H ; Timer 0 interrupt priority LSB set to high.                      
                                                                                            
IP_PX1__BMASK   EQU 004H ; External Interrupt 1 Priority Control LSB                        
IP_PX1__SHIFT   EQU 002H ; External Interrupt 1 Priority Control LSB                        
IP_PX1__LOW     EQU 000H ; External Interrupt 1 priority LSB set to low.                    
IP_PX1__HIGH    EQU 004H ; External Interrupt 1 priority LSB set to high.                   
                                                                                            
IP_PT1__BMASK   EQU 008H ; Timer 1 Interrupt Priority Control LSB                           
IP_PT1__SHIFT   EQU 003H ; Timer 1 Interrupt Priority Control LSB                           
IP_PT1__LOW     EQU 000H ; Timer 1 interrupt priority LSB set to low.                       
IP_PT1__HIGH    EQU 008H ; Timer 1 interrupt priority LSB set to high.                      
                                                                                            
IP_PS1__BMASK   EQU 010H ; UART1 Interrupt Priority Control LSB                             
IP_PS1__SHIFT   EQU 004H ; UART1 Interrupt Priority Control LSB                             
IP_PS1__LOW     EQU 000H ; UART1 interrupt priority LSB set to low.                         
IP_PS1__HIGH    EQU 010H ; UART1 interrupt priority LSB set to high.                        
                                                                                            
IP_PT2__BMASK   EQU 020H ; Timer 2 Interrupt Priority Control LSB                           
IP_PT2__SHIFT   EQU 005H ; Timer 2 Interrupt Priority Control LSB                           
IP_PT2__LOW     EQU 000H ; Timer 2 interrupt priority LSB set to low.                       
IP_PT2__HIGH    EQU 020H ; Timer 2 interrupt priority LSB set to high.                      
                                                                                            
IP_PSPI0__BMASK EQU 040H ; Serial Peripheral Interface (SPI0) Interrupt Priority Control LSB
IP_PSPI0__SHIFT EQU 006H ; Serial Peripheral Interface (SPI0) Interrupt Priority Control LSB
IP_PSPI0__LOW   EQU 000H ; SPI0 interrupt priority LSB set to low.                          
IP_PSPI0__HIGH  EQU 040H ; SPI0 interrupt priority LSB set to high.                         
                                                                                            
;------------------------------------------------------------------------------
; IPH Enums (Interrupt Priority High @ 0xF2)
;------------------------------------------------------------------------------
IPH_PHX0__BMASK   EQU 001H ; External Interrupt 0 Priority Control MSB                        
IPH_PHX0__SHIFT   EQU 000H ; External Interrupt 0 Priority Control MSB                        
IPH_PHX0__LOW     EQU 000H ; External Interrupt 0 priority MSB set to low.                    
IPH_PHX0__HIGH    EQU 001H ; External Interrupt 0 priority MSB set to high.                   
                                                                                              
IPH_PHT0__BMASK   EQU 002H ; Timer 0 Interrupt Priority Control MSB                           
IPH_PHT0__SHIFT   EQU 001H ; Timer 0 Interrupt Priority Control MSB                           
IPH_PHT0__LOW     EQU 000H ; Timer 0 interrupt priority MSB set to low.                       
IPH_PHT0__HIGH    EQU 002H ; Timer 0 interrupt priority MSB set to high.                      
                                                                                              
IPH_PHX1__BMASK   EQU 004H ; External Interrupt 1 Priority Control MSB                        
IPH_PHX1__SHIFT   EQU 002H ; External Interrupt 1 Priority Control MSB                        
IPH_PHX1__LOW     EQU 000H ; External Interrupt 1 priority MSB set to low.                    
IPH_PHX1__HIGH    EQU 004H ; External Interrupt 1 priority MSB set to high.                   
                                                                                              
IPH_PHT1__BMASK   EQU 008H ; Timer 1 Interrupt Priority Control MSB                           
IPH_PHT1__SHIFT   EQU 003H ; Timer 1 Interrupt Priority Control MSB                           
IPH_PHT1__LOW     EQU 000H ; Timer 1 interrupt priority MSB set to low.                       
IPH_PHT1__HIGH    EQU 008H ; Timer 1 interrupt priority MSB set to high.                      
                                                                                              
IPH_PHS1__BMASK   EQU 010H ; UART1 Interrupt Priority Control MSB                             
IPH_PHS1__SHIFT   EQU 004H ; UART1 Interrupt Priority Control MSB                             
IPH_PHS1__LOW     EQU 000H ; UART1 interrupt priority MSB set to low.                         
IPH_PHS1__HIGH    EQU 010H ; UART1 interrupt priority MSB set to high.                        
                                                                                              
IPH_PHT2__BMASK   EQU 020H ; Timer 2 Interrupt Priority Control MSB                           
IPH_PHT2__SHIFT   EQU 005H ; Timer 2 Interrupt Priority Control MSB                           
IPH_PHT2__LOW     EQU 000H ; Timer 2 interrupt priority MSB set to low.                       
IPH_PHT2__HIGH    EQU 020H ; Timer 2 interrupt priority MSB set to high.                      
                                                                                              
IPH_PHSPI0__BMASK EQU 040H ; Serial Peripheral Interface (SPI0) Interrupt Priority Control MSB
IPH_PHSPI0__SHIFT EQU 006H ; Serial Peripheral Interface (SPI0) Interrupt Priority Control MSB
IPH_PHSPI0__LOW   EQU 000H ; SPI0 interrupt priority MSB set to low.                          
IPH_PHSPI0__HIGH  EQU 040H ; SPI0 interrupt priority MSB set to high.                         
                                                                                              
;------------------------------------------------------------------------------
; LFO0CN Enums (Low Frequency Oscillator Control @ 0xB1)
;------------------------------------------------------------------------------
LFO0CN_OSCLD__FMASK       EQU 003H ; Internal L-F Oscillator Divider Select           
LFO0CN_OSCLD__SHIFT       EQU 000H ; Internal L-F Oscillator Divider Select           
LFO0CN_OSCLD__DIVIDE_BY_8 EQU 000H ; Divide by 8 selected.                            
LFO0CN_OSCLD__DIVIDE_BY_4 EQU 001H ; Divide by 4 selected.                            
LFO0CN_OSCLD__DIVIDE_BY_2 EQU 002H ; Divide by 2 selected.                            
LFO0CN_OSCLD__DIVIDE_BY_1 EQU 003H ; Divide by 1 selected.                            
                                                                                      
LFO0CN_OSCLF__FMASK       EQU 03CH ; Internal L-F Oscillator Frequency Control        
LFO0CN_OSCLF__SHIFT       EQU 002H ; Internal L-F Oscillator Frequency Control        
                                                                                      
LFO0CN_OSCLRDY__BMASK     EQU 040H ; Internal L-F Oscillator Ready                    
LFO0CN_OSCLRDY__SHIFT     EQU 006H ; Internal L-F Oscillator Ready                    
LFO0CN_OSCLRDY__NOT_SET   EQU 000H ; Internal L-F Oscillator frequency not stabilized.
LFO0CN_OSCLRDY__SET       EQU 040H ; Internal L-F Oscillator frequency stabilized.    
                                                                                      
LFO0CN_OSCLEN__BMASK      EQU 080H ; Internal L-F Oscillator Enable                   
LFO0CN_OSCLEN__SHIFT      EQU 007H ; Internal L-F Oscillator Enable                   
LFO0CN_OSCLEN__DISABLED   EQU 000H ; Internal L-F Oscillator Disabled.                
LFO0CN_OSCLEN__ENABLED    EQU 080H ; Internal L-F Oscillator Enabled.                 
                                                                                      
;------------------------------------------------------------------------------
; PRTDRV Enums (Port Drive Strength @ 0xF6)
;------------------------------------------------------------------------------
PRTDRV_P0DRV__BMASK      EQU 001H ; Port 0 Drive Strength                  
PRTDRV_P0DRV__SHIFT      EQU 000H ; Port 0 Drive Strength                  
PRTDRV_P0DRV__LOW_DRIVE  EQU 000H ; All pins on P0 use low drive strength. 
PRTDRV_P0DRV__HIGH_DRIVE EQU 001H ; All pins on P0 use high drive strength.
                                                                           
PRTDRV_P1DRV__BMASK      EQU 002H ; Port 1 Drive Strength                  
PRTDRV_P1DRV__SHIFT      EQU 001H ; Port 1 Drive Strength                  
PRTDRV_P1DRV__LOW_DRIVE  EQU 000H ; All pins on P1 use low drive strength. 
PRTDRV_P1DRV__HIGH_DRIVE EQU 002H ; All pins on P1 use high drive strength.
                                                                           
PRTDRV_P2DRV__BMASK      EQU 004H ; Port 2 Drive Strength                  
PRTDRV_P2DRV__SHIFT      EQU 002H ; Port 2 Drive Strength                  
PRTDRV_P2DRV__LOW_DRIVE  EQU 000H ; All pins on P2 use low drive strength. 
PRTDRV_P2DRV__HIGH_DRIVE EQU 004H ; All pins on P2 use high drive strength.
                                                                           
;------------------------------------------------------------------------------
; XBR0 Enums (Port I/O Crossbar 0 @ 0xE1)
;------------------------------------------------------------------------------
XBR0_URT1EL__BMASK    EQU 001H ; UART1 I/O Legacy Enable                          
XBR0_URT1EL__SHIFT    EQU 000H ; UART1 I/O Legacy Enable                          
XBR0_URT1EL__DISABLED EQU 000H ; UART1 I/O unavailable at Port pin.               
XBR0_URT1EL__ENABLED  EQU 001H ; UART1 TX0, RX0 routed to Port pins P0.4 and P0.5.
                                                                                  
XBR0_SPI0E__BMASK     EQU 002H ; SPI I/O Enable                                   
XBR0_SPI0E__SHIFT     EQU 001H ; SPI I/O Enable                                   
XBR0_SPI0E__DISABLED  EQU 000H ; SPI I/O unavailable at Port pins.                
XBR0_SPI0E__ENABLED   EQU 002H ; SPI I/O routed to Port pins. The SPI can be      
                               ; assigned either 3 or 4 GPIO pins.                
                                                                                  
XBR0_SMB0E__BMASK     EQU 004H ; SMB0 I/O Enable                                  
XBR0_SMB0E__SHIFT     EQU 002H ; SMB0 I/O Enable                                  
XBR0_SMB0E__DISABLED  EQU 000H ; SMBus 0 I/O unavailable at Port pins.            
XBR0_SMB0E__ENABLED   EQU 004H ; SMBus 0 I/O routed to Port pins.                 
                                                                                  
XBR0_CP0E__BMASK      EQU 008H ; Comparator0 Output Enable                        
XBR0_CP0E__SHIFT      EQU 003H ; Comparator0 Output Enable                        
XBR0_CP0E__DISABLED   EQU 000H ; CP0 unavailable at Port pin.                     
XBR0_CP0E__ENABLED    EQU 008H ; CP0 routed to Port pin.                          
                                                                                  
XBR0_CP0AE__BMASK     EQU 010H ; Comparator0 Asynchronous Output Enable           
XBR0_CP0AE__SHIFT     EQU 004H ; Comparator0 Asynchronous Output Enable           
XBR0_CP0AE__DISABLED  EQU 000H ; Asynchronous CP0 unavailable at Port pin.        
XBR0_CP0AE__ENABLED   EQU 010H ; Asynchronous CP0 routed to Port pin.             
                                                                                  
XBR0_CP1E__BMASK      EQU 020H ; Comparator1 Output Enable                        
XBR0_CP1E__SHIFT      EQU 005H ; Comparator1 Output Enable                        
XBR0_CP1E__DISABLED   EQU 000H ; CP1 unavailable at Port pin.                     
XBR0_CP1E__ENABLED    EQU 020H ; CP1 routed to Port pin.                          
                                                                                  
XBR0_CP1AE__BMASK     EQU 040H ; Comparator1 Asynchronous Output Enable           
XBR0_CP1AE__SHIFT     EQU 006H ; Comparator1 Asynchronous Output Enable           
XBR0_CP1AE__DISABLED  EQU 000H ; Asynchronous CP1 unavailable at Port pin.        
XBR0_CP1AE__ENABLED   EQU 040H ; Asynchronous CP1 routed to Port pin.             
                                                                                  
XBR0_SYSCKE__BMASK    EQU 080H ; SYSCLK Output Enable                             
XBR0_SYSCKE__SHIFT    EQU 007H ; SYSCLK Output Enable                             
XBR0_SYSCKE__DISABLED EQU 000H ; SYSCLK unavailable at Port pin.                  
XBR0_SYSCKE__ENABLED  EQU 080H ; SYSCLK output routed to Port pin.                
                                                                                  
;------------------------------------------------------------------------------
; XBR1 Enums (Port I/O Crossbar 1 @ 0xE2)
;------------------------------------------------------------------------------
XBR1_PCA0ME__FMASK          EQU 003H ; PCA Module I/O Enable                
XBR1_PCA0ME__SHIFT          EQU 000H ; PCA Module I/O Enable                
XBR1_PCA0ME__DISABLED       EQU 000H ; All PCA I/O unavailable at Port pins.
XBR1_PCA0ME__CEX0           EQU 001H ; CEX0 routed to Port pin.             
XBR1_PCA0ME__CEX0_CEX1      EQU 002H ; CEX0, CEX1 routed to Port pins.      
XBR1_PCA0ME__CEX0_CEX1_CEX2 EQU 003H ; CEX0, CEX1, CEX2 routed to Port pins.
                                                                            
XBR1_ECIE__BMASK            EQU 004H ; PCA0 External Counter Input Enable   
XBR1_ECIE__SHIFT            EQU 002H ; PCA0 External Counter Input Enable   
XBR1_ECIE__DISABLED         EQU 000H ; ECI unavailable at Port pin.         
XBR1_ECIE__ENABLED          EQU 004H ; ECI routed to Port pin.              
                                                                            
XBR1_T0E__BMASK             EQU 008H ; T0 Enable                            
XBR1_T0E__SHIFT             EQU 003H ; T0 Enable                            
XBR1_T0E__DISABLED          EQU 000H ; T0 unavailable at Port pin.          
XBR1_T0E__ENABLED           EQU 008H ; T0 routed to Port pin.               
                                                                            
XBR1_T1E__BMASK             EQU 010H ; T1 Enable                            
XBR1_T1E__SHIFT             EQU 004H ; T1 Enable                            
XBR1_T1E__DISABLED          EQU 000H ; T1 unavailable at Port pin.          
XBR1_T1E__ENABLED           EQU 010H ; T1 routed to Port pin.               
                                                                            
XBR1_T2E__BMASK             EQU 020H ; T2 Enable                            
XBR1_T2E__SHIFT             EQU 005H ; T2 Enable                            
XBR1_T2E__DISABLED          EQU 000H ; T2 unavailable at Port pin.          
XBR1_T2E__ENABLED           EQU 020H ; T2 routed to Port pin.               
                                                                            
;------------------------------------------------------------------------------
; XBR2 Enums (Port I/O Crossbar 2 @ 0xE3)
;------------------------------------------------------------------------------
XBR2_URT1E__BMASK               EQU 001H ; UART1 I/O Enable                                
XBR2_URT1E__SHIFT               EQU 000H ; UART1 I/O Enable                                
XBR2_URT1E__DISABLED            EQU 000H ; UART1 I/O unavailable at Port pin.              
XBR2_URT1E__ENABLED             EQU 001H ; UART1 TX1 RX1 routed to Port pins.              
                                                                                           
XBR2_URT1RTSE__BMASK            EQU 002H ; UART1 RTS Output Enable                         
XBR2_URT1RTSE__SHIFT            EQU 001H ; UART1 RTS Output Enable                         
XBR2_URT1RTSE__DISABLED         EQU 000H ; UART1 RTS1 unavailable at Port pin.             
XBR2_URT1RTSE__ENABLED          EQU 002H ; UART1 RTS1 routed to Port pin.                  
                                                                                           
XBR2_URT1CTSE__BMASK            EQU 004H ; UART1 CTS Input Enable                          
XBR2_URT1CTSE__SHIFT            EQU 002H ; UART1 CTS Input Enable                          
XBR2_URT1CTSE__DISABLED         EQU 000H ; UART1 CTS1 unavailable at Port pin.             
XBR2_URT1CTSE__ENABLED          EQU 004H ; UART1 CTS1 routed to Port pin.                  
                                                                                           
XBR2_XBARE__BMASK               EQU 040H ; Crossbar Enable                                 
XBR2_XBARE__SHIFT               EQU 006H ; Crossbar Enable                                 
XBR2_XBARE__DISABLED            EQU 000H ; Crossbar disabled.                              
XBR2_XBARE__ENABLED             EQU 040H ; Crossbar enabled.                               
                                                                                           
XBR2_WEAKPUD__BMASK             EQU 080H ; Port I/O Weak Pullup Disable                    
XBR2_WEAKPUD__SHIFT             EQU 007H ; Port I/O Weak Pullup Disable                    
XBR2_WEAKPUD__PULL_UPS_ENABLED  EQU 000H ; Weak Pullups enabled (except for Ports whose I/O
                                         ; are configured for analog mode).                
XBR2_WEAKPUD__PULL_UPS_DISABLED EQU 080H ; Weak Pullups disabled.                          
                                                                                           
;------------------------------------------------------------------------------
; PCA0CPH0 Enums (PCA Channel 0 Capture Module High Byte @ 0xFC)
;------------------------------------------------------------------------------
PCA0CPH0_PCA0CPH0__FMASK EQU 0FFH ; PCA Channel 0 Capture Module High Byte
PCA0CPH0_PCA0CPH0__SHIFT EQU 000H ; PCA Channel 0 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPL0 Enums (PCA Channel 0 Capture Module Low Byte @ 0xFB)
;------------------------------------------------------------------------------
PCA0CPL0_PCA0CPL0__FMASK EQU 0FFH ; PCA Channel 0 Capture Module Low Byte
PCA0CPL0_PCA0CPL0__SHIFT EQU 000H ; PCA Channel 0 Capture Module Low Byte
                                                                         
;------------------------------------------------------------------------------
; PCA0CPM0 Enums (PCA Channel 0 Capture/Compare Mode @ 0xDA)
;------------------------------------------------------------------------------
PCA0CPM0_ECCF__BMASK    EQU 001H ; Channel 0 Capture/Compare Flag Interrupt Enable
PCA0CPM0_ECCF__SHIFT    EQU 000H ; Channel 0 Capture/Compare Flag Interrupt Enable
PCA0CPM0_ECCF__DISABLED EQU 000H ; Disable CCF0 interrupts.                       
PCA0CPM0_ECCF__ENABLED  EQU 001H ; Enable a Capture/Compare Flag interrupt request
                                 ; when CCF0 is set.                              
                                                                                  
PCA0CPM0_PWM__BMASK     EQU 002H ; Channel 0 Pulse Width Modulation Mode Enable   
PCA0CPM0_PWM__SHIFT     EQU 001H ; Channel 0 Pulse Width Modulation Mode Enable   
PCA0CPM0_PWM__DISABLED  EQU 000H ; Disable PWM function.                          
PCA0CPM0_PWM__ENABLED   EQU 002H ; Enable PWM function.                           
                                                                                  
PCA0CPM0_TOG__BMASK     EQU 004H ; Channel 0 Toggle Function Enable               
PCA0CPM0_TOG__SHIFT     EQU 002H ; Channel 0 Toggle Function Enable               
PCA0CPM0_TOG__DISABLED  EQU 000H ; Disable toggle function.                       
PCA0CPM0_TOG__ENABLED   EQU 004H ; Enable toggle function.                        
                                                                                  
PCA0CPM0_MAT__BMASK     EQU 008H ; Channel 0 Match Function Enable                
PCA0CPM0_MAT__SHIFT     EQU 003H ; Channel 0 Match Function Enable                
PCA0CPM0_MAT__DISABLED  EQU 000H ; Disable match function.                        
PCA0CPM0_MAT__ENABLED   EQU 008H ; Enable match function.                         
                                                                                  
PCA0CPM0_CAPN__BMASK    EQU 010H ; Channel 0 Capture Negative Function Enable     
PCA0CPM0_CAPN__SHIFT    EQU 004H ; Channel 0 Capture Negative Function Enable     
PCA0CPM0_CAPN__DISABLED EQU 000H ; Disable negative edge capture.                 
PCA0CPM0_CAPN__ENABLED  EQU 010H ; Enable negative edge capture.                  
                                                                                  
PCA0CPM0_CAPP__BMASK    EQU 020H ; Channel 0 Capture Positive Function Enable     
PCA0CPM0_CAPP__SHIFT    EQU 005H ; Channel 0 Capture Positive Function Enable     
PCA0CPM0_CAPP__DISABLED EQU 000H ; Disable positive edge capture.                 
PCA0CPM0_CAPP__ENABLED  EQU 020H ; Enable positive edge capture.                  
                                                                                  
PCA0CPM0_ECOM__BMASK    EQU 040H ; Channel 0 Comparator Function Enable           
PCA0CPM0_ECOM__SHIFT    EQU 006H ; Channel 0 Comparator Function Enable           
PCA0CPM0_ECOM__DISABLED EQU 000H ; Disable comparator function.                   
PCA0CPM0_ECOM__ENABLED  EQU 040H ; Enable comparator function.                    
                                                                                  
PCA0CPM0_PWM16__BMASK   EQU 080H ; Channel 0 16-bit Pulse Width Modulation Enable 
PCA0CPM0_PWM16__SHIFT   EQU 007H ; Channel 0 16-bit Pulse Width Modulation Enable 
PCA0CPM0_PWM16__8_BIT   EQU 000H ; 8 to 11-bit PWM selected.                      
PCA0CPM0_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
;------------------------------------------------------------------------------
; PCA0CPH1 Enums (PCA Channel 1 Capture Module High Byte @ 0xEA)
;------------------------------------------------------------------------------
PCA0CPH1_PCA0CPH1__FMASK EQU 0FFH ; PCA Channel 1 Capture Module High Byte
PCA0CPH1_PCA0CPH1__SHIFT EQU 000H ; PCA Channel 1 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPL1 Enums (PCA Channel 1 Capture Module Low Byte @ 0xE9)
;------------------------------------------------------------------------------
PCA0CPL1_PCA0CPL1__FMASK EQU 0FFH ; PCA Channel 1 Capture Module Low Byte
PCA0CPL1_PCA0CPL1__SHIFT EQU 000H ; PCA Channel 1 Capture Module Low Byte
                                                                         
;------------------------------------------------------------------------------
; PCA0CPM1 Enums (PCA Channel 1 Capture/Compare Mode @ 0xDB)
;------------------------------------------------------------------------------
PCA0CPM1_ECCF__BMASK    EQU 001H ; Channel 1 Capture/Compare Flag Interrupt Enable
PCA0CPM1_ECCF__SHIFT    EQU 000H ; Channel 1 Capture/Compare Flag Interrupt Enable
PCA0CPM1_ECCF__DISABLED EQU 000H ; Disable CCF1 interrupts.                       
PCA0CPM1_ECCF__ENABLED  EQU 001H ; Enable a Capture/Compare Flag interrupt request
                                 ; when CCF1 is set.                              
                                                                                  
PCA0CPM1_PWM__BMASK     EQU 002H ; Channel 1 Pulse Width Modulation Mode Enable   
PCA0CPM1_PWM__SHIFT     EQU 001H ; Channel 1 Pulse Width Modulation Mode Enable   
PCA0CPM1_PWM__DISABLED  EQU 000H ; Disable PWM function.                          
PCA0CPM1_PWM__ENABLED   EQU 002H ; Enable PWM function.                           
                                                                                  
PCA0CPM1_TOG__BMASK     EQU 004H ; Channel 1 Toggle Function Enable               
PCA0CPM1_TOG__SHIFT     EQU 002H ; Channel 1 Toggle Function Enable               
PCA0CPM1_TOG__DISABLED  EQU 000H ; Disable toggle function.                       
PCA0CPM1_TOG__ENABLED   EQU 004H ; Enable toggle function.                        
                                                                                  
PCA0CPM1_MAT__BMASK     EQU 008H ; Channel 1 Match Function Enable                
PCA0CPM1_MAT__SHIFT     EQU 003H ; Channel 1 Match Function Enable                
PCA0CPM1_MAT__DISABLED  EQU 000H ; Disable match function.                        
PCA0CPM1_MAT__ENABLED   EQU 008H ; Enable match function.                         
                                                                                  
PCA0CPM1_CAPN__BMASK    EQU 010H ; Channel 1 Capture Negative Function Enable     
PCA0CPM1_CAPN__SHIFT    EQU 004H ; Channel 1 Capture Negative Function Enable     
PCA0CPM1_CAPN__DISABLED EQU 000H ; Disable negative edge capture.                 
PCA0CPM1_CAPN__ENABLED  EQU 010H ; Enable negative edge capture.                  
                                                                                  
PCA0CPM1_CAPP__BMASK    EQU 020H ; Channel 1 Capture Positive Function Enable     
PCA0CPM1_CAPP__SHIFT    EQU 005H ; Channel 1 Capture Positive Function Enable     
PCA0CPM1_CAPP__DISABLED EQU 000H ; Disable positive edge capture.                 
PCA0CPM1_CAPP__ENABLED  EQU 020H ; Enable positive edge capture.                  
                                                                                  
PCA0CPM1_ECOM__BMASK    EQU 040H ; Channel 1 Comparator Function Enable           
PCA0CPM1_ECOM__SHIFT    EQU 006H ; Channel 1 Comparator Function Enable           
PCA0CPM1_ECOM__DISABLED EQU 000H ; Disable comparator function.                   
PCA0CPM1_ECOM__ENABLED  EQU 040H ; Enable comparator function.                    
                                                                                  
PCA0CPM1_PWM16__BMASK   EQU 080H ; Channel 1 16-bit Pulse Width Modulation Enable 
PCA0CPM1_PWM16__SHIFT   EQU 007H ; Channel 1 16-bit Pulse Width Modulation Enable 
PCA0CPM1_PWM16__8_BIT   EQU 000H ; 8 to 11-bit PWM selected.                      
PCA0CPM1_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
;------------------------------------------------------------------------------
; PCA0CPH2 Enums (PCA Channel 2 Capture Module High Byte @ 0xEC)
;------------------------------------------------------------------------------
PCA0CPH2_PCA0CPH2__FMASK EQU 0FFH ; PCA Channel 2 Capture Module High Byte
PCA0CPH2_PCA0CPH2__SHIFT EQU 000H ; PCA Channel 2 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPL2 Enums (PCA Channel 2 Capture Module Low Byte @ 0xEB)
;------------------------------------------------------------------------------
PCA0CPL2_PCA0CPL2__FMASK EQU 0FFH ; PCA Channel 2 Capture Module Low Byte
PCA0CPL2_PCA0CPL2__SHIFT EQU 000H ; PCA Channel 2 Capture Module Low Byte
                                                                         
;------------------------------------------------------------------------------
; PCA0CPM2 Enums (PCA Channel 2 Capture/Compare Mode @ 0xDC)
;------------------------------------------------------------------------------
PCA0CPM2_ECCF__BMASK    EQU 001H ; Channel 2 Capture/Compare Flag Interrupt Enable
PCA0CPM2_ECCF__SHIFT    EQU 000H ; Channel 2 Capture/Compare Flag Interrupt Enable
PCA0CPM2_ECCF__DISABLED EQU 000H ; Disable CCF2 interrupts.                       
PCA0CPM2_ECCF__ENABLED  EQU 001H ; Enable a Capture/Compare Flag interrupt request
                                 ; when CCF2 is set.                              
                                                                                  
PCA0CPM2_PWM__BMASK     EQU 002H ; Channel 2 Pulse Width Modulation Mode Enable   
PCA0CPM2_PWM__SHIFT     EQU 001H ; Channel 2 Pulse Width Modulation Mode Enable   
PCA0CPM2_PWM__DISABLED  EQU 000H ; Disable PWM function.                          
PCA0CPM2_PWM__ENABLED   EQU 002H ; Enable PWM function.                           
                                                                                  
PCA0CPM2_TOG__BMASK     EQU 004H ; Channel 2 Toggle Function Enable               
PCA0CPM2_TOG__SHIFT     EQU 002H ; Channel 2 Toggle Function Enable               
PCA0CPM2_TOG__DISABLED  EQU 000H ; Disable toggle function.                       
PCA0CPM2_TOG__ENABLED   EQU 004H ; Enable toggle function.                        
                                                                                  
PCA0CPM2_MAT__BMASK     EQU 008H ; Channel 2 Match Function Enable                
PCA0CPM2_MAT__SHIFT     EQU 003H ; Channel 2 Match Function Enable                
PCA0CPM2_MAT__DISABLED  EQU 000H ; Disable match function.                        
PCA0CPM2_MAT__ENABLED   EQU 008H ; Enable match function.                         
                                                                                  
PCA0CPM2_CAPN__BMASK    EQU 010H ; Channel 2 Capture Negative Function Enable     
PCA0CPM2_CAPN__SHIFT    EQU 004H ; Channel 2 Capture Negative Function Enable     
PCA0CPM2_CAPN__DISABLED EQU 000H ; Disable negative edge capture.                 
PCA0CPM2_CAPN__ENABLED  EQU 010H ; Enable negative edge capture.                  
                                                                                  
PCA0CPM2_CAPP__BMASK    EQU 020H ; Channel 2 Capture Positive Function Enable     
PCA0CPM2_CAPP__SHIFT    EQU 005H ; Channel 2 Capture Positive Function Enable     
PCA0CPM2_CAPP__DISABLED EQU 000H ; Disable positive edge capture.                 
PCA0CPM2_CAPP__ENABLED  EQU 020H ; Enable positive edge capture.                  
                                                                                  
PCA0CPM2_ECOM__BMASK    EQU 040H ; Channel 2 Comparator Function Enable           
PCA0CPM2_ECOM__SHIFT    EQU 006H ; Channel 2 Comparator Function Enable           
PCA0CPM2_ECOM__DISABLED EQU 000H ; Disable comparator function.                   
PCA0CPM2_ECOM__ENABLED  EQU 040H ; Enable comparator function.                    
                                                                                  
PCA0CPM2_PWM16__BMASK   EQU 080H ; Channel 2 16-bit Pulse Width Modulation Enable 
PCA0CPM2_PWM16__SHIFT   EQU 007H ; Channel 2 16-bit Pulse Width Modulation Enable 
PCA0CPM2_PWM16__8_BIT   EQU 000H ; 8 to 11-bit PWM selected.                      
PCA0CPM2_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
;------------------------------------------------------------------------------
; PCA0CENT Enums (PCA Center Alignment Enable @ 0x9E)
;------------------------------------------------------------------------------
PCA0CENT_CEX0CEN__BMASK  EQU 001H ; CEX0 Center Alignment Enable
PCA0CENT_CEX0CEN__SHIFT  EQU 000H ; CEX0 Center Alignment Enable
PCA0CENT_CEX0CEN__EDGE   EQU 000H ; Edge-aligned.               
PCA0CENT_CEX0CEN__CENTER EQU 001H ; Center-aligned.             
                                                                
PCA0CENT_CEX1CEN__BMASK  EQU 002H ; CEX1 Center Alignment Enable
PCA0CENT_CEX1CEN__SHIFT  EQU 001H ; CEX1 Center Alignment Enable
PCA0CENT_CEX1CEN__EDGE   EQU 000H ; Edge-aligned.               
PCA0CENT_CEX1CEN__CENTER EQU 002H ; Center-aligned.             
                                                                
PCA0CENT_CEX2CEN__BMASK  EQU 004H ; CEX2 Center Alignment Enable
PCA0CENT_CEX2CEN__SHIFT  EQU 002H ; CEX2 Center Alignment Enable
PCA0CENT_CEX2CEN__EDGE   EQU 000H ; Edge-aligned.               
PCA0CENT_CEX2CEN__CENTER EQU 004H ; Center-aligned.             
                                                                
;------------------------------------------------------------------------------
; PCA0CLR Enums (PCA Comparator Clear Control @ 0x9C)
;------------------------------------------------------------------------------
PCA0CLR_CPCE0__BMASK    EQU 001H ; Comparator Clear Enable for CEX0              
PCA0CLR_CPCE0__SHIFT    EQU 000H ; Comparator Clear Enable for CEX0              
PCA0CLR_CPCE0__DISABLED EQU 000H ; Disable the comparator clear function on PCA  
                                 ; channel 0.                                    
PCA0CLR_CPCE0__ENABLED  EQU 001H ; Enable the comparator clear function on PCA   
                                 ; channel 0.                                    
                                                                                 
PCA0CLR_CPCE1__BMASK    EQU 002H ; Comparator Clear Enable for CEX1              
PCA0CLR_CPCE1__SHIFT    EQU 001H ; Comparator Clear Enable for CEX1              
PCA0CLR_CPCE1__DISABLED EQU 000H ; Disable the comparator clear function on PCA  
                                 ; channel 1.                                    
PCA0CLR_CPCE1__ENABLED  EQU 002H ; Enable the comparator clear function on PCA   
                                 ; channel 1.                                    
                                                                                 
PCA0CLR_CPCE2__BMASK    EQU 004H ; Comparator Clear Enable for CEX2              
PCA0CLR_CPCE2__SHIFT    EQU 002H ; Comparator Clear Enable for CEX2              
PCA0CLR_CPCE2__DISABLED EQU 000H ; Disable the comparator clear function on PCA  
                                 ; channel 2.                                    
PCA0CLR_CPCE2__ENABLED  EQU 004H ; Enable the comparator clear function on PCA   
                                 ; channel 2.                                    
                                                                                 
PCA0CLR_CPSEL__BMASK    EQU 040H ; Comparator Clear Select                       
PCA0CLR_CPSEL__SHIFT    EQU 006H ; Comparator Clear Select                       
PCA0CLR_CPSEL__CMP0     EQU 000H ; Use Comparator 0 for the comparator clear     
                                 ; function.                                     
PCA0CLR_CPSEL__CMP1     EQU 040H ; Use Comparator 1 for the comparator clear     
                                 ; function.                                     
                                                                                 
PCA0CLR_CPCPOL__BMASK   EQU 080H ; Comparator Clear Polarity                     
PCA0CLR_CPCPOL__SHIFT   EQU 007H ; Comparator Clear Polarity                     
PCA0CLR_CPCPOL__LOW     EQU 000H ; PCA channel(s) will be cleared when comparator
                                 ; result goes logic low.                        
PCA0CLR_CPCPOL__HIGH    EQU 080H ; PCA channel(s) will be cleared when comparator
                                 ; result goes logic high.                       
                                                                                 
;------------------------------------------------------------------------------
; PCA0CN0 Enums (PCA Control @ 0xD8)
;------------------------------------------------------------------------------
PCA0CN0_CCF0__BMASK   EQU 001H ; PCA Module 0 Capture/Compare Flag             
PCA0CN0_CCF0__SHIFT   EQU 000H ; PCA Module 0 Capture/Compare Flag             
PCA0CN0_CCF0__NOT_SET EQU 000H ; A match or capture did not occur on channel 0.
PCA0CN0_CCF0__SET     EQU 001H ; A match or capture occurred on channel 0.     
                                                                               
PCA0CN0_CCF1__BMASK   EQU 002H ; PCA Module 1 Capture/Compare Flag             
PCA0CN0_CCF1__SHIFT   EQU 001H ; PCA Module 1 Capture/Compare Flag             
PCA0CN0_CCF1__NOT_SET EQU 000H ; A match or capture did not occur on channel 1.
PCA0CN0_CCF1__SET     EQU 002H ; A match or capture occurred on channel 1.     
                                                                               
PCA0CN0_CCF2__BMASK   EQU 004H ; PCA Module 2 Capture/Compare Flag             
PCA0CN0_CCF2__SHIFT   EQU 002H ; PCA Module 2 Capture/Compare Flag             
PCA0CN0_CCF2__NOT_SET EQU 000H ; A match or capture did not occur on channel 2.
PCA0CN0_CCF2__SET     EQU 004H ; A match or capture occurred on channel 2.     
                                                                               
PCA0CN0_CR__BMASK     EQU 040H ; PCA Counter/Timer Run Control                 
PCA0CN0_CR__SHIFT     EQU 006H ; PCA Counter/Timer Run Control                 
PCA0CN0_CR__STOP      EQU 000H ; Stop the PCA Counter/Timer.                   
PCA0CN0_CR__RUN       EQU 040H ; Start the PCA Counter/Timer running.          
                                                                               
PCA0CN0_CF__BMASK     EQU 080H ; PCA Counter/Timer Overflow Flag               
PCA0CN0_CF__SHIFT     EQU 007H ; PCA Counter/Timer Overflow Flag               
PCA0CN0_CF__NOT_SET   EQU 000H ; The PCA counter/timer did not overflow.       
PCA0CN0_CF__SET       EQU 080H ; The PCA counter/timer overflowed.             
                                                                               
;------------------------------------------------------------------------------
; PCA0H Enums (PCA Counter/Timer High Byte @ 0xFA)
;------------------------------------------------------------------------------
PCA0H_PCA0H__FMASK EQU 0FFH ; PCA Counter/Timer High Byte
PCA0H_PCA0H__SHIFT EQU 000H ; PCA Counter/Timer High Byte
                                                         
;------------------------------------------------------------------------------
; PCA0L Enums (PCA Counter/Timer Low Byte @ 0xF9)
;------------------------------------------------------------------------------
PCA0L_PCA0L__FMASK EQU 0FFH ; PCA Counter/Timer Low Byte
PCA0L_PCA0L__SHIFT EQU 000H ; PCA Counter/Timer Low Byte
                                                        
;------------------------------------------------------------------------------
; PCA0MD Enums (PCA Mode @ 0xD9)
;------------------------------------------------------------------------------
PCA0MD_ECF__BMASK            EQU 001H ; PCA Counter/Timer Overflow Interrupt Enable       
PCA0MD_ECF__SHIFT            EQU 000H ; PCA Counter/Timer Overflow Interrupt Enable       
PCA0MD_ECF__OVF_INT_DISABLED EQU 000H ; Disable the CF interrupt.                         
PCA0MD_ECF__OVF_INT_ENABLED  EQU 001H ; Enable a PCA Counter/Timer Overflow interrupt     
                                      ; request when CF is set.                           
                                                                                          
PCA0MD_CPS__FMASK            EQU 00EH ; PCA Counter/Timer Pulse Select                    
PCA0MD_CPS__SHIFT            EQU 001H ; PCA Counter/Timer Pulse Select                    
PCA0MD_CPS__SYSCLK_DIV_12    EQU 000H ; System clock divided by 12.                       
PCA0MD_CPS__SYSCLK_DIV_4     EQU 002H ; System clock divided by 4.                        
PCA0MD_CPS__T0_OVERFLOW      EQU 004H ; Timer 0 overflow.                                 
PCA0MD_CPS__ECI              EQU 006H ; High-to-low transitions on ECI (max rate = system 
                                      ; clock divided by 4).                              
PCA0MD_CPS__SYSCLK           EQU 008H ; System clock.                                     
PCA0MD_CPS__EXTOSC_DIV_8     EQU 00AH ; External clock divided by 8 (synchronized with the
                                      ; system clock).                                    
PCA0MD_CPS__LFOSC_DIV_8      EQU 00CH ; Low frequency oscillator divided by 8.            
                                                                                          
PCA0MD_CIDL__BMASK           EQU 080H ; PCA Counter/Timer Idle Control                    
PCA0MD_CIDL__SHIFT           EQU 007H ; PCA Counter/Timer Idle Control                    
PCA0MD_CIDL__NORMAL          EQU 000H ; PCA continues to function normally while the      
                                      ; system controller is in Idle Mode.                
PCA0MD_CIDL__SUSPEND         EQU 080H ; PCA operation is suspended while the system       
                                      ; controller is in Idle Mode.                       
                                                                                          
;------------------------------------------------------------------------------
; PCA0POL Enums (PCA Output Polarity @ 0x96)
;------------------------------------------------------------------------------
PCA0POL_CEX0POL__BMASK   EQU 001H ; CEX0 Output Polarity 
PCA0POL_CEX0POL__SHIFT   EQU 000H ; CEX0 Output Polarity 
PCA0POL_CEX0POL__DEFAULT EQU 000H ; Use default polarity.
PCA0POL_CEX0POL__INVERT  EQU 001H ; Invert polarity.     
                                                         
PCA0POL_CEX1POL__BMASK   EQU 002H ; CEX1 Output Polarity 
PCA0POL_CEX1POL__SHIFT   EQU 001H ; CEX1 Output Polarity 
PCA0POL_CEX1POL__DEFAULT EQU 000H ; Use default polarity.
PCA0POL_CEX1POL__INVERT  EQU 002H ; Invert polarity.     
                                                         
PCA0POL_CEX2POL__BMASK   EQU 004H ; CEX2 Output Polarity 
PCA0POL_CEX2POL__SHIFT   EQU 002H ; CEX2 Output Polarity 
PCA0POL_CEX2POL__DEFAULT EQU 000H ; Use default polarity.
PCA0POL_CEX2POL__INVERT  EQU 004H ; Invert polarity.     
                                                         
;------------------------------------------------------------------------------
; PCA0PWM Enums (PCA PWM Configuration @ 0xF7)
;------------------------------------------------------------------------------
PCA0PWM_CLSEL__FMASK             EQU 007H ; Cycle Length Select                              
PCA0PWM_CLSEL__SHIFT             EQU 000H ; Cycle Length Select                              
PCA0PWM_CLSEL__8_BITS            EQU 000H ; 8 bits.                                          
PCA0PWM_CLSEL__9_BITS            EQU 001H ; 9 bits.                                          
PCA0PWM_CLSEL__10_BITS           EQU 002H ; 10 bits.                                         
PCA0PWM_CLSEL__11_BITS           EQU 003H ; 11 bits.                                         
                                                                                             
PCA0PWM_COVF__BMASK              EQU 020H ; Cycle Overflow Flag                              
PCA0PWM_COVF__SHIFT              EQU 005H ; Cycle Overflow Flag                              
PCA0PWM_COVF__NO_OVERFLOW        EQU 000H ; No overflow has occurred since the last time this
                                          ; bit was cleared.                                 
PCA0PWM_COVF__OVERFLOW           EQU 020H ; An overflow has occurred since the last time this
                                          ; bit was cleared.                                 
                                                                                             
PCA0PWM_ECOV__BMASK              EQU 040H ; Cycle Overflow Interrupt Enable                  
PCA0PWM_ECOV__SHIFT              EQU 006H ; Cycle Overflow Interrupt Enable                  
PCA0PWM_ECOV__COVF_MASK_DISABLED EQU 000H ; COVF will not generate PCA interrupts.           
PCA0PWM_ECOV__COVF_MASK_ENABLED  EQU 040H ; A PCA interrupt will be generated when COVF is   
                                          ; set.                                             
                                                                                             
PCA0PWM_ARSEL__BMASK             EQU 080H ; Auto-Reload Register Select                      
PCA0PWM_ARSEL__SHIFT             EQU 007H ; Auto-Reload Register Select                      
PCA0PWM_ARSEL__CAPTURE_COMPARE   EQU 000H ; Read/Write Capture/Compare Registers at PCA0CPHn 
                                          ; and PCA0CPLn.                                    
PCA0PWM_ARSEL__AUTORELOAD        EQU 080H ; Read/Write Auto-Reload Registers at PCA0CPHn and 
                                          ; PCA0CPLn.                                        
                                                                                             
;------------------------------------------------------------------------------
; PCON0 Enums (Power Control @ 0x87)
;------------------------------------------------------------------------------
PCON0_IDLE__BMASK  EQU 001H ; Idle Mode Select                                
PCON0_IDLE__SHIFT  EQU 000H ; Idle Mode Select                                
PCON0_IDLE__NORMAL EQU 000H ; Idle mode not activated.                        
PCON0_IDLE__IDLE   EQU 001H ; CPU goes into Idle mode (shuts off clock to CPU,
                            ; but clocks to enabled peripherals are still     
                            ; active).                                        
                                                                              
PCON0_STOP__BMASK  EQU 002H ; Stop Mode Select                                
PCON0_STOP__SHIFT  EQU 001H ; Stop Mode Select                                
PCON0_STOP__NORMAL EQU 000H ; Stop mode not activated.                        
PCON0_STOP__STOP   EQU 002H ; CPU goes into Stop mode (internal oscillator    
                            ; stopped).                                       
                                                                              
PCON0_GF0__BMASK   EQU 004H ; General Purpose Flag 0                          
PCON0_GF0__SHIFT   EQU 002H ; General Purpose Flag 0                          
PCON0_GF0__NOT_SET EQU 000H ; The GF0 flag is not set. Clear the GF0 flag.    
PCON0_GF0__SET     EQU 004H ; The GF0 flag is set. Set the GF0 flag.          
                                                                              
PCON0_GF1__BMASK   EQU 008H ; General Purpose Flag 1                          
PCON0_GF1__SHIFT   EQU 003H ; General Purpose Flag 1                          
PCON0_GF1__NOT_SET EQU 000H ; The GF1 flag is not set. Clear the GF1 flag.    
PCON0_GF1__SET     EQU 008H ; The GF1 flag is set. Set the GF1 flag.          
                                                                              
PCON0_GF2__BMASK   EQU 010H ; General Purpose Flag 2                          
PCON0_GF2__SHIFT   EQU 004H ; General Purpose Flag 2                          
PCON0_GF2__NOT_SET EQU 000H ; The GF2 flag is not set. Clear the GF2 flag.    
PCON0_GF2__SET     EQU 010H ; The GF2 flag is set. Set the GF2 flag.          
                                                                              
PCON0_GF3__BMASK   EQU 020H ; General Purpose Flag 3                          
PCON0_GF3__SHIFT   EQU 005H ; General Purpose Flag 3                          
PCON0_GF3__NOT_SET EQU 000H ; The GF3 flag is not set. Clear the GF3 flag.    
PCON0_GF3__SET     EQU 020H ; The GF3 flag is set. Set the GF3 flag.          
                                                                              
PCON0_GF4__BMASK   EQU 040H ; General Purpose Flag 4                          
PCON0_GF4__SHIFT   EQU 006H ; General Purpose Flag 4                          
PCON0_GF4__NOT_SET EQU 000H ; The GF4 flag is not set. Clear the GF4 flag.    
PCON0_GF4__SET     EQU 040H ; The GF4 flag is set. Set the GF4 flag.          
                                                                              
PCON0_GF5__BMASK   EQU 080H ; General Purpose Flag 5                          
PCON0_GF5__SHIFT   EQU 007H ; General Purpose Flag 5                          
PCON0_GF5__NOT_SET EQU 000H ; The GF5 flag is not set. Clear the GF5 flag.    
PCON0_GF5__SET     EQU 080H ; The GF5 flag is set. Set the GF5 flag.          
                                                                              
;------------------------------------------------------------------------------
; PCON1 Enums (Power Control 1 @ 0xE4)
;------------------------------------------------------------------------------
PCON1_SUSPEND__BMASK   EQU 040H ; Suspend Mode Select                               
PCON1_SUSPEND__SHIFT   EQU 006H ; Suspend Mode Select                               
PCON1_SUSPEND__NORMAL  EQU 000H ; Suspend mode not activated.                       
PCON1_SUSPEND__SUSPEND EQU 040H ; Device goes into suspend mode (high-frequency     
                                ; oscillators and SYSCLK are halted).               
                                                                                    
PCON1_SNOOZE__BMASK    EQU 080H ; Snooze Mode Select                                
PCON1_SNOOZE__SHIFT    EQU 007H ; Snooze Mode Select                                
PCON1_SNOOZE__NORMAL   EQU 000H ; Snooze mode not activated.                        
PCON1_SNOOZE__SNOOZE   EQU 080H ; Device goes into snooze mode (high-frequency      
                                ; oscillators and SYSCLK are halted, internal LDO in
                                ; low-power state).                                 
                                                                                    
;------------------------------------------------------------------------------
; PSTAT0 Enums (Power Status @ 0xAD)
;------------------------------------------------------------------------------
PSTAT0_CPT0WK__BMASK    EQU 001H ; Comparator 0 Wake-up Event                        
PSTAT0_CPT0WK__SHIFT    EQU 000H ; Comparator 0 Wake-up Event                        
PSTAT0_CPT0WK__NOT_SET  EQU 000H ; A comparator 0 output falling edge event did not  
                                 ; occur.                                            
PSTAT0_CPT0WK__SET      EQU 001H ; A comparator 0 output falling edge event occurred.
                                                                                     
PSTAT0_PMATWK__BMASK    EQU 002H ; Port Match Wake-up Event                          
PSTAT0_PMATWK__SHIFT    EQU 001H ; Port Match Wake-up Event                          
PSTAT0_PMATWK__NOT_SET  EQU 000H ; A Port Match event did not occur.                 
PSTAT0_PMATWK__SET      EQU 002H ; A Port Match event occurred.                      
                                                                                     
PSTAT0_TMR4WK__BMASK    EQU 004H ; Timer 4 Wake-up Event                             
PSTAT0_TMR4WK__SHIFT    EQU 002H ; Timer 4 Wake-up Event                             
PSTAT0_TMR4WK__NOT_SET  EQU 000H ; A Timer 4 overflow event did not occur.           
PSTAT0_TMR4WK__SET      EQU 004H ; A Timer 4 overflow event occurred.                
                                                                                     
PSTAT0_SPI0WK__BMASK    EQU 008H ; SPI0 Slave Wake-up Event                          
PSTAT0_SPI0WK__SHIFT    EQU 003H ; SPI0 Slave Wake-up Event                          
PSTAT0_SPI0WK__NOT_SET  EQU 000H ; The SPI0 Slave did not receive a byte.            
PSTAT0_SPI0WK__SET      EQU 008H ; The SPI0 Slave received a byte.                   
                                                                                     
PSTAT0_USB0RWK__BMASK   EQU 010H ; USB0 Resume Wake-up Event                         
PSTAT0_USB0RWK__SHIFT   EQU 004H ; USB0 Resume Wake-up Event                         
PSTAT0_USB0RWK__NOT_SET EQU 000H ; A USB Resume wake up event did not occur.         
PSTAT0_USB0RWK__SET     EQU 010H ; A USB Resume wake up event occurred.              
                                                                                     
PSTAT0_CL0WK__BMASK     EQU 020H ; CL0 Wake-up Event                                 
PSTAT0_CL0WK__SHIFT     EQU 005H ; CL0 Wake-up Event                                 
PSTAT0_CL0WK__NOT_SET   EQU 000H ; A CL0 interrupt-enabled event did not occur.      
PSTAT0_CL0WK__SET       EQU 020H ; A CL0 interrupt-enabled event occurred.           
                                                                                     
;------------------------------------------------------------------------------
; P0 Enums (Port 0 Pin Latch @ 0x80)
;------------------------------------------------------------------------------
P0_B0__BMASK EQU 001H ; Port 0 Bit 0 Latch                            
P0_B0__SHIFT EQU 000H ; Port 0 Bit 0 Latch                            
P0_B0__LOW   EQU 000H ; P0.0 is low. Set P0.0 to drive low.           
P0_B0__HIGH  EQU 001H ; P0.0 is high. Set P0.0 to drive or float high.
                                                                      
P0_B1__BMASK EQU 002H ; Port 0 Bit 1 Latch                            
P0_B1__SHIFT EQU 001H ; Port 0 Bit 1 Latch                            
P0_B1__LOW   EQU 000H ; P0.1 is low. Set P0.1 to drive low.           
P0_B1__HIGH  EQU 002H ; P0.1 is high. Set P0.1 to drive or float high.
                                                                      
P0_B2__BMASK EQU 004H ; Port 0 Bit 2 Latch                            
P0_B2__SHIFT EQU 002H ; Port 0 Bit 2 Latch                            
P0_B2__LOW   EQU 000H ; P0.2 is low. Set P0.2 to drive low.           
P0_B2__HIGH  EQU 004H ; P0.2 is high. Set P0.2 to drive or float high.
                                                                      
P0_B3__BMASK EQU 008H ; Port 0 Bit 3 Latch                            
P0_B3__SHIFT EQU 003H ; Port 0 Bit 3 Latch                            
P0_B3__LOW   EQU 000H ; P0.3 is low. Set P0.3 to drive low.           
P0_B3__HIGH  EQU 008H ; P0.3 is high. Set P0.3 to drive or float high.
                                                                      
P0_B4__BMASK EQU 010H ; Port 0 Bit 4 Latch                            
P0_B4__SHIFT EQU 004H ; Port 0 Bit 4 Latch                            
P0_B4__LOW   EQU 000H ; P0.4 is low. Set P0.4 to drive low.           
P0_B4__HIGH  EQU 010H ; P0.4 is high. Set P0.4 to drive or float high.
                                                                      
P0_B5__BMASK EQU 020H ; Port 0 Bit 5 Latch                            
P0_B5__SHIFT EQU 005H ; Port 0 Bit 5 Latch                            
P0_B5__LOW   EQU 000H ; P0.5 is low. Set P0.5 to drive low.           
P0_B5__HIGH  EQU 020H ; P0.5 is high. Set P0.5 to drive or float high.
                                                                      
P0_B6__BMASK EQU 040H ; Port 0 Bit 6 Latch                            
P0_B6__SHIFT EQU 006H ; Port 0 Bit 6 Latch                            
P0_B6__LOW   EQU 000H ; P0.6 is low. Set P0.6 to drive low.           
P0_B6__HIGH  EQU 040H ; P0.6 is high. Set P0.6 to drive or float high.
                                                                      
P0_B7__BMASK EQU 080H ; Port 0 Bit 7 Latch                            
P0_B7__SHIFT EQU 007H ; Port 0 Bit 7 Latch                            
P0_B7__LOW   EQU 000H ; P0.7 is low. Set P0.7 to drive low.           
P0_B7__HIGH  EQU 080H ; P0.7 is high. Set P0.7 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P0MASK Enums (Port 0 Mask @ 0xFE)
;------------------------------------------------------------------------------
P0MASK_B0__BMASK    EQU 001H ; Port 0 Bit 0 Mask Value                           
P0MASK_B0__SHIFT    EQU 000H ; Port 0 Bit 0 Mask Value                           
P0MASK_B0__IGNORED  EQU 000H ; P0.0 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P0MASK_B0__COMPARED EQU 001H ; P0.0 pin logic value is compared to P0MAT.0.      
                                                                                 
P0MASK_B1__BMASK    EQU 002H ; Port 0 Bit 1 Mask Value                           
P0MASK_B1__SHIFT    EQU 001H ; Port 0 Bit 1 Mask Value                           
P0MASK_B1__IGNORED  EQU 000H ; P0.1 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P0MASK_B1__COMPARED EQU 002H ; P0.1 pin logic value is compared to P0MAT.1.      
                                                                                 
P0MASK_B2__BMASK    EQU 004H ; Port 0 Bit 2 Mask Value                           
P0MASK_B2__SHIFT    EQU 002H ; Port 0 Bit 2 Mask Value                           
P0MASK_B2__IGNORED  EQU 000H ; P0.2 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P0MASK_B2__COMPARED EQU 004H ; P0.2 pin logic value is compared to P0MAT.2.      
                                                                                 
P0MASK_B3__BMASK    EQU 008H ; Port 0 Bit 3 Mask Value                           
P0MASK_B3__SHIFT    EQU 003H ; Port 0 Bit 3 Mask Value                           
P0MASK_B3__IGNORED  EQU 000H ; P0.3 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P0MASK_B3__COMPARED EQU 008H ; P0.3 pin logic value is compared to P0MAT.3.      
                                                                                 
P0MASK_B4__BMASK    EQU 010H ; Port 0 Bit 4 Mask Value                           
P0MASK_B4__SHIFT    EQU 004H ; Port 0 Bit 4 Mask Value                           
P0MASK_B4__IGNORED  EQU 000H ; P0.4 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P0MASK_B4__COMPARED EQU 010H ; P0.4 pin logic value is compared to P0MAT.4.      
                                                                                 
P0MASK_B5__BMASK    EQU 020H ; Port 0 Bit 5 Mask Value                           
P0MASK_B5__SHIFT    EQU 005H ; Port 0 Bit 5 Mask Value                           
P0MASK_B5__IGNORED  EQU 000H ; P0.5 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P0MASK_B5__COMPARED EQU 020H ; P0.5 pin logic value is compared to P0MAT.5.      
                                                                                 
P0MASK_B6__BMASK    EQU 040H ; Port 0 Bit 6 Mask Value                           
P0MASK_B6__SHIFT    EQU 006H ; Port 0 Bit 6 Mask Value                           
P0MASK_B6__IGNORED  EQU 000H ; P0.6 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P0MASK_B6__COMPARED EQU 040H ; P0.6 pin logic value is compared to P0MAT.6.      
                                                                                 
P0MASK_B7__BMASK    EQU 080H ; Port 0 Bit 7 Mask Value                           
P0MASK_B7__SHIFT    EQU 007H ; Port 0 Bit 7 Mask Value                           
P0MASK_B7__IGNORED  EQU 000H ; P0.7 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P0MASK_B7__COMPARED EQU 080H ; P0.7 pin logic value is compared to P0MAT.7.      
                                                                                 
;------------------------------------------------------------------------------
; P0MAT Enums (Port 0 Match @ 0xFD)
;------------------------------------------------------------------------------
P0MAT_B0__BMASK EQU 001H ; Port 0 Bit 0 Match Value                         
P0MAT_B0__SHIFT EQU 000H ; Port 0 Bit 0 Match Value                         
P0MAT_B0__LOW   EQU 000H ; P0.0 pin logic value is compared with logic LOW. 
P0MAT_B0__HIGH  EQU 001H ; P0.0 pin logic value is compared with logic HIGH.
                                                                            
P0MAT_B1__BMASK EQU 002H ; Port 0 Bit 1 Match Value                         
P0MAT_B1__SHIFT EQU 001H ; Port 0 Bit 1 Match Value                         
P0MAT_B1__LOW   EQU 000H ; P0.1 pin logic value is compared with logic LOW. 
P0MAT_B1__HIGH  EQU 002H ; P0.1 pin logic value is compared with logic HIGH.
                                                                            
P0MAT_B2__BMASK EQU 004H ; Port 0 Bit 2 Match Value                         
P0MAT_B2__SHIFT EQU 002H ; Port 0 Bit 2 Match Value                         
P0MAT_B2__LOW   EQU 000H ; P0.2 pin logic value is compared with logic LOW. 
P0MAT_B2__HIGH  EQU 004H ; P0.2 pin logic value is compared with logic HIGH.
                                                                            
P0MAT_B3__BMASK EQU 008H ; Port 0 Bit 3 Match Value                         
P0MAT_B3__SHIFT EQU 003H ; Port 0 Bit 3 Match Value                         
P0MAT_B3__LOW   EQU 000H ; P0.3 pin logic value is compared with logic LOW. 
P0MAT_B3__HIGH  EQU 008H ; P0.3 pin logic value is compared with logic HIGH.
                                                                            
P0MAT_B4__BMASK EQU 010H ; Port 0 Bit 4 Match Value                         
P0MAT_B4__SHIFT EQU 004H ; Port 0 Bit 4 Match Value                         
P0MAT_B4__LOW   EQU 000H ; P0.4 pin logic value is compared with logic LOW. 
P0MAT_B4__HIGH  EQU 010H ; P0.4 pin logic value is compared with logic HIGH.
                                                                            
P0MAT_B5__BMASK EQU 020H ; Port 0 Bit 5 Match Value                         
P0MAT_B5__SHIFT EQU 005H ; Port 0 Bit 5 Match Value                         
P0MAT_B5__LOW   EQU 000H ; P0.5 pin logic value is compared with logic LOW. 
P0MAT_B5__HIGH  EQU 020H ; P0.5 pin logic value is compared with logic HIGH.
                                                                            
P0MAT_B6__BMASK EQU 040H ; Port 0 Bit 6 Match Value                         
P0MAT_B6__SHIFT EQU 006H ; Port 0 Bit 6 Match Value                         
P0MAT_B6__LOW   EQU 000H ; P0.6 pin logic value is compared with logic LOW. 
P0MAT_B6__HIGH  EQU 040H ; P0.6 pin logic value is compared with logic HIGH.
                                                                            
P0MAT_B7__BMASK EQU 080H ; Port 0 Bit 7 Match Value                         
P0MAT_B7__SHIFT EQU 007H ; Port 0 Bit 7 Match Value                         
P0MAT_B7__LOW   EQU 000H ; P0.7 pin logic value is compared with logic LOW. 
P0MAT_B7__HIGH  EQU 080H ; P0.7 pin logic value is compared with logic HIGH.
                                                                            
;------------------------------------------------------------------------------
; P0MDIN Enums (Port 0 Input Mode @ 0xF1)
;------------------------------------------------------------------------------
P0MDIN_B0__BMASK   EQU 001H ; Port 0 Bit 0 Input Mode                 
P0MDIN_B0__SHIFT   EQU 000H ; Port 0 Bit 0 Input Mode                 
P0MDIN_B0__ANALOG  EQU 000H ; P0.0 pin is configured for analog mode. 
P0MDIN_B0__DIGITAL EQU 001H ; P0.0 pin is configured for digital mode.
                                                                      
P0MDIN_B1__BMASK   EQU 002H ; Port 0 Bit 1 Input Mode                 
P0MDIN_B1__SHIFT   EQU 001H ; Port 0 Bit 1 Input Mode                 
P0MDIN_B1__ANALOG  EQU 000H ; P0.1 pin is configured for analog mode. 
P0MDIN_B1__DIGITAL EQU 002H ; P0.1 pin is configured for digital mode.
                                                                      
P0MDIN_B2__BMASK   EQU 004H ; Port 0 Bit 2 Input Mode                 
P0MDIN_B2__SHIFT   EQU 002H ; Port 0 Bit 2 Input Mode                 
P0MDIN_B2__ANALOG  EQU 000H ; P0.2 pin is configured for analog mode. 
P0MDIN_B2__DIGITAL EQU 004H ; P0.2 pin is configured for digital mode.
                                                                      
P0MDIN_B3__BMASK   EQU 008H ; Port 0 Bit 3 Input Mode                 
P0MDIN_B3__SHIFT   EQU 003H ; Port 0 Bit 3 Input Mode                 
P0MDIN_B3__ANALOG  EQU 000H ; P0.3 pin is configured for analog mode. 
P0MDIN_B3__DIGITAL EQU 008H ; P0.3 pin is configured for digital mode.
                                                                      
P0MDIN_B4__BMASK   EQU 010H ; Port 0 Bit 4 Input Mode                 
P0MDIN_B4__SHIFT   EQU 004H ; Port 0 Bit 4 Input Mode                 
P0MDIN_B4__ANALOG  EQU 000H ; P0.4 pin is configured for analog mode. 
P0MDIN_B4__DIGITAL EQU 010H ; P0.4 pin is configured for digital mode.
                                                                      
P0MDIN_B5__BMASK   EQU 020H ; Port 0 Bit 5 Input Mode                 
P0MDIN_B5__SHIFT   EQU 005H ; Port 0 Bit 5 Input Mode                 
P0MDIN_B5__ANALOG  EQU 000H ; P0.5 pin is configured for analog mode. 
P0MDIN_B5__DIGITAL EQU 020H ; P0.5 pin is configured for digital mode.
                                                                      
P0MDIN_B6__BMASK   EQU 040H ; Port 0 Bit 6 Input Mode                 
P0MDIN_B6__SHIFT   EQU 006H ; Port 0 Bit 6 Input Mode                 
P0MDIN_B6__ANALOG  EQU 000H ; P0.6 pin is configured for analog mode. 
P0MDIN_B6__DIGITAL EQU 040H ; P0.6 pin is configured for digital mode.
                                                                      
P0MDIN_B7__BMASK   EQU 080H ; Port 0 Bit 7 Input Mode                 
P0MDIN_B7__SHIFT   EQU 007H ; Port 0 Bit 7 Input Mode                 
P0MDIN_B7__ANALOG  EQU 000H ; P0.7 pin is configured for analog mode. 
P0MDIN_B7__DIGITAL EQU 080H ; P0.7 pin is configured for digital mode.
                                                                      
;------------------------------------------------------------------------------
; P0MDOUT Enums (Port 0 Output Mode @ 0xA4)
;------------------------------------------------------------------------------
P0MDOUT_B0__BMASK      EQU 001H ; Port 0 Bit 0 Output Mode  
P0MDOUT_B0__SHIFT      EQU 000H ; Port 0 Bit 0 Output Mode  
P0MDOUT_B0__OPEN_DRAIN EQU 000H ; P0.0 output is open-drain.
P0MDOUT_B0__PUSH_PULL  EQU 001H ; P0.0 output is push-pull. 
                                                            
P0MDOUT_B1__BMASK      EQU 002H ; Port 0 Bit 1 Output Mode  
P0MDOUT_B1__SHIFT      EQU 001H ; Port 0 Bit 1 Output Mode  
P0MDOUT_B1__OPEN_DRAIN EQU 000H ; P0.1 output is open-drain.
P0MDOUT_B1__PUSH_PULL  EQU 002H ; P0.1 output is push-pull. 
                                                            
P0MDOUT_B2__BMASK      EQU 004H ; Port 0 Bit 2 Output Mode  
P0MDOUT_B2__SHIFT      EQU 002H ; Port 0 Bit 2 Output Mode  
P0MDOUT_B2__OPEN_DRAIN EQU 000H ; P0.2 output is open-drain.
P0MDOUT_B2__PUSH_PULL  EQU 004H ; P0.2 output is push-pull. 
                                                            
P0MDOUT_B3__BMASK      EQU 008H ; Port 0 Bit 3 Output Mode  
P0MDOUT_B3__SHIFT      EQU 003H ; Port 0 Bit 3 Output Mode  
P0MDOUT_B3__OPEN_DRAIN EQU 000H ; P0.3 output is open-drain.
P0MDOUT_B3__PUSH_PULL  EQU 008H ; P0.3 output is push-pull. 
                                                            
P0MDOUT_B4__BMASK      EQU 010H ; Port 0 Bit 4 Output Mode  
P0MDOUT_B4__SHIFT      EQU 004H ; Port 0 Bit 4 Output Mode  
P0MDOUT_B4__OPEN_DRAIN EQU 000H ; P0.4 output is open-drain.
P0MDOUT_B4__PUSH_PULL  EQU 010H ; P0.4 output is push-pull. 
                                                            
P0MDOUT_B5__BMASK      EQU 020H ; Port 0 Bit 5 Output Mode  
P0MDOUT_B5__SHIFT      EQU 005H ; Port 0 Bit 5 Output Mode  
P0MDOUT_B5__OPEN_DRAIN EQU 000H ; P0.5 output is open-drain.
P0MDOUT_B5__PUSH_PULL  EQU 020H ; P0.5 output is push-pull. 
                                                            
P0MDOUT_B6__BMASK      EQU 040H ; Port 0 Bit 6 Output Mode  
P0MDOUT_B6__SHIFT      EQU 006H ; Port 0 Bit 6 Output Mode  
P0MDOUT_B6__OPEN_DRAIN EQU 000H ; P0.6 output is open-drain.
P0MDOUT_B6__PUSH_PULL  EQU 040H ; P0.6 output is push-pull. 
                                                            
P0MDOUT_B7__BMASK      EQU 080H ; Port 0 Bit 7 Output Mode  
P0MDOUT_B7__SHIFT      EQU 007H ; Port 0 Bit 7 Output Mode  
P0MDOUT_B7__OPEN_DRAIN EQU 000H ; P0.7 output is open-drain.
P0MDOUT_B7__PUSH_PULL  EQU 080H ; P0.7 output is push-pull. 
                                                            
;------------------------------------------------------------------------------
; P0SKIP Enums (Port 0 Skip @ 0xD4)
;------------------------------------------------------------------------------
P0SKIP_B0__BMASK       EQU 001H ; Port 0 Bit 0 Skip                       
P0SKIP_B0__SHIFT       EQU 000H ; Port 0 Bit 0 Skip                       
P0SKIP_B0__NOT_SKIPPED EQU 000H ; P0.0 pin is not skipped by the crossbar.
P0SKIP_B0__SKIPPED     EQU 001H ; P0.0 pin is skipped by the crossbar.    
                                                                          
P0SKIP_B1__BMASK       EQU 002H ; Port 0 Bit 1 Skip                       
P0SKIP_B1__SHIFT       EQU 001H ; Port 0 Bit 1 Skip                       
P0SKIP_B1__NOT_SKIPPED EQU 000H ; P0.1 pin is not skipped by the crossbar.
P0SKIP_B1__SKIPPED     EQU 002H ; P0.1 pin is skipped by the crossbar.    
                                                                          
P0SKIP_B2__BMASK       EQU 004H ; Port 0 Bit 2 Skip                       
P0SKIP_B2__SHIFT       EQU 002H ; Port 0 Bit 2 Skip                       
P0SKIP_B2__NOT_SKIPPED EQU 000H ; P0.2 pin is not skipped by the crossbar.
P0SKIP_B2__SKIPPED     EQU 004H ; P0.2 pin is skipped by the crossbar.    
                                                                          
P0SKIP_B3__BMASK       EQU 008H ; Port 0 Bit 3 Skip                       
P0SKIP_B3__SHIFT       EQU 003H ; Port 0 Bit 3 Skip                       
P0SKIP_B3__NOT_SKIPPED EQU 000H ; P0.3 pin is not skipped by the crossbar.
P0SKIP_B3__SKIPPED     EQU 008H ; P0.3 pin is skipped by the crossbar.    
                                                                          
P0SKIP_B4__BMASK       EQU 010H ; Port 0 Bit 4 Skip                       
P0SKIP_B4__SHIFT       EQU 004H ; Port 0 Bit 4 Skip                       
P0SKIP_B4__NOT_SKIPPED EQU 000H ; P0.4 pin is not skipped by the crossbar.
P0SKIP_B4__SKIPPED     EQU 010H ; P0.4 pin is skipped by the crossbar.    
                                                                          
P0SKIP_B5__BMASK       EQU 020H ; Port 0 Bit 5 Skip                       
P0SKIP_B5__SHIFT       EQU 005H ; Port 0 Bit 5 Skip                       
P0SKIP_B5__NOT_SKIPPED EQU 000H ; P0.5 pin is not skipped by the crossbar.
P0SKIP_B5__SKIPPED     EQU 020H ; P0.5 pin is skipped by the crossbar.    
                                                                          
P0SKIP_B6__BMASK       EQU 040H ; Port 0 Bit 6 Skip                       
P0SKIP_B6__SHIFT       EQU 006H ; Port 0 Bit 6 Skip                       
P0SKIP_B6__NOT_SKIPPED EQU 000H ; P0.6 pin is not skipped by the crossbar.
P0SKIP_B6__SKIPPED     EQU 040H ; P0.6 pin is skipped by the crossbar.    
                                                                          
P0SKIP_B7__BMASK       EQU 080H ; Port 0 Bit 7 Skip                       
P0SKIP_B7__SHIFT       EQU 007H ; Port 0 Bit 7 Skip                       
P0SKIP_B7__NOT_SKIPPED EQU 000H ; P0.7 pin is not skipped by the crossbar.
P0SKIP_B7__SKIPPED     EQU 080H ; P0.7 pin is skipped by the crossbar.    
                                                                          
;------------------------------------------------------------------------------
; P1 Enums (Port 1 Pin Latch @ 0x90)
;------------------------------------------------------------------------------
P1_B0__BMASK EQU 001H ; Port 1 Bit 0 Latch                            
P1_B0__SHIFT EQU 000H ; Port 1 Bit 0 Latch                            
P1_B0__LOW   EQU 000H ; P1.0 is low. Set P1.0 to drive low.           
P1_B0__HIGH  EQU 001H ; P1.0 is high. Set P1.0 to drive or float high.
                                                                      
P1_B1__BMASK EQU 002H ; Port 1 Bit 1 Latch                            
P1_B1__SHIFT EQU 001H ; Port 1 Bit 1 Latch                            
P1_B1__LOW   EQU 000H ; P1.1 is low. Set P1.1 to drive low.           
P1_B1__HIGH  EQU 002H ; P1.1 is high. Set P1.1 to drive or float high.
                                                                      
P1_B2__BMASK EQU 004H ; Port 1 Bit 2 Latch                            
P1_B2__SHIFT EQU 002H ; Port 1 Bit 2 Latch                            
P1_B2__LOW   EQU 000H ; P1.2 is low. Set P1.2 to drive low.           
P1_B2__HIGH  EQU 004H ; P1.2 is high. Set P1.2 to drive or float high.
                                                                      
P1_B3__BMASK EQU 008H ; Port 1 Bit 3 Latch                            
P1_B3__SHIFT EQU 003H ; Port 1 Bit 3 Latch                            
P1_B3__LOW   EQU 000H ; P1.3 is low. Set P1.3 to drive low.           
P1_B3__HIGH  EQU 008H ; P1.3 is high. Set P1.3 to drive or float high.
                                                                      
P1_B4__BMASK EQU 010H ; Port 1 Bit 4 Latch                            
P1_B4__SHIFT EQU 004H ; Port 1 Bit 4 Latch                            
P1_B4__LOW   EQU 000H ; P1.4 is low. Set P1.4 to drive low.           
P1_B4__HIGH  EQU 010H ; P1.4 is high. Set P1.4 to drive or float high.
                                                                      
P1_B5__BMASK EQU 020H ; Port 1 Bit 5 Latch                            
P1_B5__SHIFT EQU 005H ; Port 1 Bit 5 Latch                            
P1_B5__LOW   EQU 000H ; P1.5 is low. Set P1.5 to drive low.           
P1_B5__HIGH  EQU 020H ; P1.5 is high. Set P1.5 to drive or float high.
                                                                      
P1_B6__BMASK EQU 040H ; Port 1 Bit 6 Latch                            
P1_B6__SHIFT EQU 006H ; Port 1 Bit 6 Latch                            
P1_B6__LOW   EQU 000H ; P1.6 is low. Set P1.6 to drive low.           
P1_B6__HIGH  EQU 040H ; P1.6 is high. Set P1.6 to drive or float high.
                                                                      
P1_B7__BMASK EQU 080H ; Port 1 Bit 7 Latch                            
P1_B7__SHIFT EQU 007H ; Port 1 Bit 7 Latch                            
P1_B7__LOW   EQU 000H ; P1.7 is low. Set P1.7 to drive low.           
P1_B7__HIGH  EQU 080H ; P1.7 is high. Set P1.7 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P1MASK Enums (Port 1 Mask @ 0xEE)
;------------------------------------------------------------------------------
P1MASK_B0__BMASK    EQU 001H ; Port 1 Bit 0 Mask Value                           
P1MASK_B0__SHIFT    EQU 000H ; Port 1 Bit 0 Mask Value                           
P1MASK_B0__IGNORED  EQU 000H ; P1.0 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P1MASK_B0__COMPARED EQU 001H ; P1.0 pin logic value is compared to P1MAT.0.      
                                                                                 
P1MASK_B1__BMASK    EQU 002H ; Port 1 Bit 1 Mask Value                           
P1MASK_B1__SHIFT    EQU 001H ; Port 1 Bit 1 Mask Value                           
P1MASK_B1__IGNORED  EQU 000H ; P1.1 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P1MASK_B1__COMPARED EQU 002H ; P1.1 pin logic value is compared to P1MAT.1.      
                                                                                 
P1MASK_B2__BMASK    EQU 004H ; Port 1 Bit 2 Mask Value                           
P1MASK_B2__SHIFT    EQU 002H ; Port 1 Bit 2 Mask Value                           
P1MASK_B2__IGNORED  EQU 000H ; P1.2 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P1MASK_B2__COMPARED EQU 004H ; P1.2 pin logic value is compared to P1MAT.2.      
                                                                                 
P1MASK_B3__BMASK    EQU 008H ; Port 1 Bit 3 Mask Value                           
P1MASK_B3__SHIFT    EQU 003H ; Port 1 Bit 3 Mask Value                           
P1MASK_B3__IGNORED  EQU 000H ; P1.3 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P1MASK_B3__COMPARED EQU 008H ; P1.3 pin logic value is compared to P1MAT.3.      
                                                                                 
P1MASK_B4__BMASK    EQU 010H ; Port 1 Bit 4 Mask Value                           
P1MASK_B4__SHIFT    EQU 004H ; Port 1 Bit 4 Mask Value                           
P1MASK_B4__IGNORED  EQU 000H ; P1.4 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P1MASK_B4__COMPARED EQU 010H ; P1.4 pin logic value is compared to P1MAT.4.      
                                                                                 
P1MASK_B5__BMASK    EQU 020H ; Port 1 Bit 5 Mask Value                           
P1MASK_B5__SHIFT    EQU 005H ; Port 1 Bit 5 Mask Value                           
P1MASK_B5__IGNORED  EQU 000H ; P1.5 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P1MASK_B5__COMPARED EQU 020H ; P1.5 pin logic value is compared to P1MAT.5.      
                                                                                 
P1MASK_B6__BMASK    EQU 040H ; Port 1 Bit 6 Mask Value                           
P1MASK_B6__SHIFT    EQU 006H ; Port 1 Bit 6 Mask Value                           
P1MASK_B6__IGNORED  EQU 000H ; P1.6 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P1MASK_B6__COMPARED EQU 040H ; P1.6 pin logic value is compared to P1MAT.6.      
                                                                                 
P1MASK_B7__BMASK    EQU 080H ; Port 1 Bit 7 Mask Value                           
P1MASK_B7__SHIFT    EQU 007H ; Port 1 Bit 7 Mask Value                           
P1MASK_B7__IGNORED  EQU 000H ; P1.7 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P1MASK_B7__COMPARED EQU 080H ; P1.7 pin logic value is compared to P1MAT.7.      
                                                                                 
;------------------------------------------------------------------------------
; P1MAT Enums (Port 1 Match @ 0xED)
;------------------------------------------------------------------------------
P1MAT_B0__BMASK EQU 001H ; Port 1 Bit 0 Match Value                         
P1MAT_B0__SHIFT EQU 000H ; Port 1 Bit 0 Match Value                         
P1MAT_B0__LOW   EQU 000H ; P1.0 pin logic value is compared with logic LOW. 
P1MAT_B0__HIGH  EQU 001H ; P1.0 pin logic value is compared with logic HIGH.
                                                                            
P1MAT_B1__BMASK EQU 002H ; Port 1 Bit 1 Match Value                         
P1MAT_B1__SHIFT EQU 001H ; Port 1 Bit 1 Match Value                         
P1MAT_B1__LOW   EQU 000H ; P1.1 pin logic value is compared with logic LOW. 
P1MAT_B1__HIGH  EQU 002H ; P1.1 pin logic value is compared with logic HIGH.
                                                                            
P1MAT_B2__BMASK EQU 004H ; Port 1 Bit 2 Match Value                         
P1MAT_B2__SHIFT EQU 002H ; Port 1 Bit 2 Match Value                         
P1MAT_B2__LOW   EQU 000H ; P1.2 pin logic value is compared with logic LOW. 
P1MAT_B2__HIGH  EQU 004H ; P1.2 pin logic value is compared with logic HIGH.
                                                                            
P1MAT_B3__BMASK EQU 008H ; Port 1 Bit 3 Match Value                         
P1MAT_B3__SHIFT EQU 003H ; Port 1 Bit 3 Match Value                         
P1MAT_B3__LOW   EQU 000H ; P1.3 pin logic value is compared with logic LOW. 
P1MAT_B3__HIGH  EQU 008H ; P1.3 pin logic value is compared with logic HIGH.
                                                                            
P1MAT_B4__BMASK EQU 010H ; Port 1 Bit 4 Match Value                         
P1MAT_B4__SHIFT EQU 004H ; Port 1 Bit 4 Match Value                         
P1MAT_B4__LOW   EQU 000H ; P1.4 pin logic value is compared with logic LOW. 
P1MAT_B4__HIGH  EQU 010H ; P1.4 pin logic value is compared with logic HIGH.
                                                                            
P1MAT_B5__BMASK EQU 020H ; Port 1 Bit 5 Match Value                         
P1MAT_B5__SHIFT EQU 005H ; Port 1 Bit 5 Match Value                         
P1MAT_B5__LOW   EQU 000H ; P1.5 pin logic value is compared with logic LOW. 
P1MAT_B5__HIGH  EQU 020H ; P1.5 pin logic value is compared with logic HIGH.
                                                                            
P1MAT_B6__BMASK EQU 040H ; Port 1 Bit 6 Match Value                         
P1MAT_B6__SHIFT EQU 006H ; Port 1 Bit 6 Match Value                         
P1MAT_B6__LOW   EQU 000H ; P1.6 pin logic value is compared with logic LOW. 
P1MAT_B6__HIGH  EQU 040H ; P1.6 pin logic value is compared with logic HIGH.
                                                                            
P1MAT_B7__BMASK EQU 080H ; Port 1 Bit 7 Match Value                         
P1MAT_B7__SHIFT EQU 007H ; Port 1 Bit 7 Match Value                         
P1MAT_B7__LOW   EQU 000H ; P1.7 pin logic value is compared with logic LOW. 
P1MAT_B7__HIGH  EQU 080H ; P1.7 pin logic value is compared with logic HIGH.
                                                                            
;------------------------------------------------------------------------------
; P1MDIN Enums (Port 1 Input Mode @ 0xF2)
;------------------------------------------------------------------------------
P1MDIN_B0__BMASK   EQU 001H ; Port 1 Bit 0 Input Mode                 
P1MDIN_B0__SHIFT   EQU 000H ; Port 1 Bit 0 Input Mode                 
P1MDIN_B0__ANALOG  EQU 000H ; P1.0 pin is configured for analog mode. 
P1MDIN_B0__DIGITAL EQU 001H ; P1.0 pin is configured for digital mode.
                                                                      
P1MDIN_B1__BMASK   EQU 002H ; Port 1 Bit 1 Input Mode                 
P1MDIN_B1__SHIFT   EQU 001H ; Port 1 Bit 1 Input Mode                 
P1MDIN_B1__ANALOG  EQU 000H ; P1.1 pin is configured for analog mode. 
P1MDIN_B1__DIGITAL EQU 002H ; P1.1 pin is configured for digital mode.
                                                                      
P1MDIN_B2__BMASK   EQU 004H ; Port 1 Bit 2 Input Mode                 
P1MDIN_B2__SHIFT   EQU 002H ; Port 1 Bit 2 Input Mode                 
P1MDIN_B2__ANALOG  EQU 000H ; P1.2 pin is configured for analog mode. 
P1MDIN_B2__DIGITAL EQU 004H ; P1.2 pin is configured for digital mode.
                                                                      
P1MDIN_B3__BMASK   EQU 008H ; Port 1 Bit 3 Input Mode                 
P1MDIN_B3__SHIFT   EQU 003H ; Port 1 Bit 3 Input Mode                 
P1MDIN_B3__ANALOG  EQU 000H ; P1.3 pin is configured for analog mode. 
P1MDIN_B3__DIGITAL EQU 008H ; P1.3 pin is configured for digital mode.
                                                                      
P1MDIN_B4__BMASK   EQU 010H ; Port 1 Bit 4 Input Mode                 
P1MDIN_B4__SHIFT   EQU 004H ; Port 1 Bit 4 Input Mode                 
P1MDIN_B4__ANALOG  EQU 000H ; P1.4 pin is configured for analog mode. 
P1MDIN_B4__DIGITAL EQU 010H ; P1.4 pin is configured for digital mode.
                                                                      
P1MDIN_B5__BMASK   EQU 020H ; Port 1 Bit 5 Input Mode                 
P1MDIN_B5__SHIFT   EQU 005H ; Port 1 Bit 5 Input Mode                 
P1MDIN_B5__ANALOG  EQU 000H ; P1.5 pin is configured for analog mode. 
P1MDIN_B5__DIGITAL EQU 020H ; P1.5 pin is configured for digital mode.
                                                                      
P1MDIN_B6__BMASK   EQU 040H ; Port 1 Bit 6 Input Mode                 
P1MDIN_B6__SHIFT   EQU 006H ; Port 1 Bit 6 Input Mode                 
P1MDIN_B6__ANALOG  EQU 000H ; P1.6 pin is configured for analog mode. 
P1MDIN_B6__DIGITAL EQU 040H ; P1.6 pin is configured for digital mode.
                                                                      
P1MDIN_B7__BMASK   EQU 080H ; Port 1 Bit 7 Input Mode                 
P1MDIN_B7__SHIFT   EQU 007H ; Port 1 Bit 7 Input Mode                 
P1MDIN_B7__ANALOG  EQU 000H ; P1.7 pin is configured for analog mode. 
P1MDIN_B7__DIGITAL EQU 080H ; P1.7 pin is configured for digital mode.
                                                                      
;------------------------------------------------------------------------------
; P1MDOUT Enums (Port 1 Output Mode @ 0xA5)
;------------------------------------------------------------------------------
P1MDOUT_B0__BMASK      EQU 001H ; Port 1 Bit 0 Output Mode  
P1MDOUT_B0__SHIFT      EQU 000H ; Port 1 Bit 0 Output Mode  
P1MDOUT_B0__OPEN_DRAIN EQU 000H ; P1.0 output is open-drain.
P1MDOUT_B0__PUSH_PULL  EQU 001H ; P1.0 output is push-pull. 
                                                            
P1MDOUT_B1__BMASK      EQU 002H ; Port 1 Bit 1 Output Mode  
P1MDOUT_B1__SHIFT      EQU 001H ; Port 1 Bit 1 Output Mode  
P1MDOUT_B1__OPEN_DRAIN EQU 000H ; P1.1 output is open-drain.
P1MDOUT_B1__PUSH_PULL  EQU 002H ; P1.1 output is push-pull. 
                                                            
P1MDOUT_B2__BMASK      EQU 004H ; Port 1 Bit 2 Output Mode  
P1MDOUT_B2__SHIFT      EQU 002H ; Port 1 Bit 2 Output Mode  
P1MDOUT_B2__OPEN_DRAIN EQU 000H ; P1.2 output is open-drain.
P1MDOUT_B2__PUSH_PULL  EQU 004H ; P1.2 output is push-pull. 
                                                            
P1MDOUT_B3__BMASK      EQU 008H ; Port 1 Bit 3 Output Mode  
P1MDOUT_B3__SHIFT      EQU 003H ; Port 1 Bit 3 Output Mode  
P1MDOUT_B3__OPEN_DRAIN EQU 000H ; P1.3 output is open-drain.
P1MDOUT_B3__PUSH_PULL  EQU 008H ; P1.3 output is push-pull. 
                                                            
P1MDOUT_B4__BMASK      EQU 010H ; Port 1 Bit 4 Output Mode  
P1MDOUT_B4__SHIFT      EQU 004H ; Port 1 Bit 4 Output Mode  
P1MDOUT_B4__OPEN_DRAIN EQU 000H ; P1.4 output is open-drain.
P1MDOUT_B4__PUSH_PULL  EQU 010H ; P1.4 output is push-pull. 
                                                            
P1MDOUT_B5__BMASK      EQU 020H ; Port 1 Bit 5 Output Mode  
P1MDOUT_B5__SHIFT      EQU 005H ; Port 1 Bit 5 Output Mode  
P1MDOUT_B5__OPEN_DRAIN EQU 000H ; P1.5 output is open-drain.
P1MDOUT_B5__PUSH_PULL  EQU 020H ; P1.5 output is push-pull. 
                                                            
P1MDOUT_B6__BMASK      EQU 040H ; Port 1 Bit 6 Output Mode  
P1MDOUT_B6__SHIFT      EQU 006H ; Port 1 Bit 6 Output Mode  
P1MDOUT_B6__OPEN_DRAIN EQU 000H ; P1.6 output is open-drain.
P1MDOUT_B6__PUSH_PULL  EQU 040H ; P1.6 output is push-pull. 
                                                            
P1MDOUT_B7__BMASK      EQU 080H ; Port 1 Bit 7 Output Mode  
P1MDOUT_B7__SHIFT      EQU 007H ; Port 1 Bit 7 Output Mode  
P1MDOUT_B7__OPEN_DRAIN EQU 000H ; P1.7 output is open-drain.
P1MDOUT_B7__PUSH_PULL  EQU 080H ; P1.7 output is push-pull. 
                                                            
;------------------------------------------------------------------------------
; P1SKIP Enums (Port 1 Skip @ 0xD5)
;------------------------------------------------------------------------------
P1SKIP_B0__BMASK       EQU 001H ; Port 1 Bit 0 Skip                       
P1SKIP_B0__SHIFT       EQU 000H ; Port 1 Bit 0 Skip                       
P1SKIP_B0__NOT_SKIPPED EQU 000H ; P1.0 pin is not skipped by the crossbar.
P1SKIP_B0__SKIPPED     EQU 001H ; P1.0 pin is skipped by the crossbar.    
                                                                          
P1SKIP_B1__BMASK       EQU 002H ; Port 1 Bit 1 Skip                       
P1SKIP_B1__SHIFT       EQU 001H ; Port 1 Bit 1 Skip                       
P1SKIP_B1__NOT_SKIPPED EQU 000H ; P1.1 pin is not skipped by the crossbar.
P1SKIP_B1__SKIPPED     EQU 002H ; P1.1 pin is skipped by the crossbar.    
                                                                          
P1SKIP_B2__BMASK       EQU 004H ; Port 1 Bit 2 Skip                       
P1SKIP_B2__SHIFT       EQU 002H ; Port 1 Bit 2 Skip                       
P1SKIP_B2__NOT_SKIPPED EQU 000H ; P1.2 pin is not skipped by the crossbar.
P1SKIP_B2__SKIPPED     EQU 004H ; P1.2 pin is skipped by the crossbar.    
                                                                          
P1SKIP_B3__BMASK       EQU 008H ; Port 1 Bit 3 Skip                       
P1SKIP_B3__SHIFT       EQU 003H ; Port 1 Bit 3 Skip                       
P1SKIP_B3__NOT_SKIPPED EQU 000H ; P1.3 pin is not skipped by the crossbar.
P1SKIP_B3__SKIPPED     EQU 008H ; P1.3 pin is skipped by the crossbar.    
                                                                          
P1SKIP_B4__BMASK       EQU 010H ; Port 1 Bit 4 Skip                       
P1SKIP_B4__SHIFT       EQU 004H ; Port 1 Bit 4 Skip                       
P1SKIP_B4__NOT_SKIPPED EQU 000H ; P1.4 pin is not skipped by the crossbar.
P1SKIP_B4__SKIPPED     EQU 010H ; P1.4 pin is skipped by the crossbar.    
                                                                          
P1SKIP_B5__BMASK       EQU 020H ; Port 1 Bit 5 Skip                       
P1SKIP_B5__SHIFT       EQU 005H ; Port 1 Bit 5 Skip                       
P1SKIP_B5__NOT_SKIPPED EQU 000H ; P1.5 pin is not skipped by the crossbar.
P1SKIP_B5__SKIPPED     EQU 020H ; P1.5 pin is skipped by the crossbar.    
                                                                          
P1SKIP_B6__BMASK       EQU 040H ; Port 1 Bit 6 Skip                       
P1SKIP_B6__SHIFT       EQU 006H ; Port 1 Bit 6 Skip                       
P1SKIP_B6__NOT_SKIPPED EQU 000H ; P1.6 pin is not skipped by the crossbar.
P1SKIP_B6__SKIPPED     EQU 040H ; P1.6 pin is skipped by the crossbar.    
                                                                          
P1SKIP_B7__BMASK       EQU 080H ; Port 1 Bit 7 Skip                       
P1SKIP_B7__SHIFT       EQU 007H ; Port 1 Bit 7 Skip                       
P1SKIP_B7__NOT_SKIPPED EQU 000H ; P1.7 pin is not skipped by the crossbar.
P1SKIP_B7__SKIPPED     EQU 080H ; P1.7 pin is skipped by the crossbar.    
                                                                          
;------------------------------------------------------------------------------
; P2 Enums (Port 2 Pin Latch @ 0xA0)
;------------------------------------------------------------------------------
P2_B0__BMASK EQU 001H ; Port 2 Bit 0 Latch                            
P2_B0__SHIFT EQU 000H ; Port 2 Bit 0 Latch                            
P2_B0__LOW   EQU 000H ; P2.0 is low. Set P2.0 to drive low.           
P2_B0__HIGH  EQU 001H ; P2.0 is high. Set P2.0 to drive or float high.
                                                                      
P2_B1__BMASK EQU 002H ; Port 2 Bit 1 Latch                            
P2_B1__SHIFT EQU 001H ; Port 2 Bit 1 Latch                            
P2_B1__LOW   EQU 000H ; P2.1 is low. Set P2.1 to drive low.           
P2_B1__HIGH  EQU 002H ; P2.1 is high. Set P2.1 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P2MASK Enums (Port 2 Mask @ 0xFC)
;------------------------------------------------------------------------------
P2MASK_B0__BMASK    EQU 001H ; Port 2 Bit 0 Mask Value                           
P2MASK_B0__SHIFT    EQU 000H ; Port 2 Bit 0 Mask Value                           
P2MASK_B0__IGNORED  EQU 000H ; P2.0 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P2MASK_B0__COMPARED EQU 001H ; P2.0 pin logic value is compared to P2MAT.0.      
                                                                                 
P2MASK_B1__BMASK    EQU 002H ; Port 2 Bit 1 Mask Value                           
P2MASK_B1__SHIFT    EQU 001H ; Port 2 Bit 1 Mask Value                           
P2MASK_B1__IGNORED  EQU 000H ; P2.1 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P2MASK_B1__COMPARED EQU 002H ; P2.1 pin logic value is compared to P2MAT.1.      
                                                                                 
;------------------------------------------------------------------------------
; P2MAT Enums (Port 2 Match @ 0xFB)
;------------------------------------------------------------------------------
P2MAT_B0__BMASK EQU 001H ; Port 2 Bit 0 Match Value                         
P2MAT_B0__SHIFT EQU 000H ; Port 2 Bit 0 Match Value                         
P2MAT_B0__LOW   EQU 000H ; P2.0 pin logic value is compared with logic LOW. 
P2MAT_B0__HIGH  EQU 001H ; P2.0 pin logic value is compared with logic HIGH.
                                                                            
P2MAT_B1__BMASK EQU 002H ; Port 2 Bit 1 Match Value                         
P2MAT_B1__SHIFT EQU 001H ; Port 2 Bit 1 Match Value                         
P2MAT_B1__LOW   EQU 000H ; P2.1 pin logic value is compared with logic LOW. 
P2MAT_B1__HIGH  EQU 002H ; P2.1 pin logic value is compared with logic HIGH.
                                                                            
;------------------------------------------------------------------------------
; P2MDIN Enums (Port 2 Input Mode @ 0xF3)
;------------------------------------------------------------------------------
P2MDIN_B0__BMASK   EQU 001H ; Port 2 Bit 0 Input Mode                 
P2MDIN_B0__SHIFT   EQU 000H ; Port 2 Bit 0 Input Mode                 
P2MDIN_B0__ANALOG  EQU 000H ; P2.0 pin is configured for analog mode. 
P2MDIN_B0__DIGITAL EQU 001H ; P2.0 pin is configured for digital mode.
                                                                      
P2MDIN_B1__BMASK   EQU 002H ; Port 2 Bit 1 Input Mode                 
P2MDIN_B1__SHIFT   EQU 001H ; Port 2 Bit 1 Input Mode                 
P2MDIN_B1__ANALOG  EQU 000H ; P2.1 pin is configured for analog mode. 
P2MDIN_B1__DIGITAL EQU 002H ; P2.1 pin is configured for digital mode.
                                                                      
;------------------------------------------------------------------------------
; P2MDOUT Enums (Port 2 Output Mode @ 0xA6)
;------------------------------------------------------------------------------
P2MDOUT_B0__BMASK      EQU 001H ; Port 2 Bit 0 Output Mode  
P2MDOUT_B0__SHIFT      EQU 000H ; Port 2 Bit 0 Output Mode  
P2MDOUT_B0__OPEN_DRAIN EQU 000H ; P2.0 output is open-drain.
P2MDOUT_B0__PUSH_PULL  EQU 001H ; P2.0 output is push-pull. 
                                                            
P2MDOUT_B1__BMASK      EQU 002H ; Port 2 Bit 1 Output Mode  
P2MDOUT_B1__SHIFT      EQU 001H ; Port 2 Bit 1 Output Mode  
P2MDOUT_B1__OPEN_DRAIN EQU 000H ; P2.1 output is open-drain.
P2MDOUT_B1__PUSH_PULL  EQU 002H ; P2.1 output is push-pull. 
                                                            
;------------------------------------------------------------------------------
; RSTSRC Enums (Reset Source @ 0xEF)
;------------------------------------------------------------------------------
RSTSRC_PINRSF__BMASK   EQU 001H ; HW Pin Reset Flag                                                    
RSTSRC_PINRSF__SHIFT   EQU 000H ; HW Pin Reset Flag                                                    
RSTSRC_PINRSF__NOT_SET EQU 000H ; The RSTb pin did not cause the last reset.                           
RSTSRC_PINRSF__SET     EQU 001H ; The RSTb pin caused the last reset.                                  
                                                                                                       
RSTSRC_PORSF__BMASK    EQU 002H ; Power-On / Supply Monitor Reset Flag, and Supply Monitor Reset Enable
RSTSRC_PORSF__SHIFT    EQU 001H ; Power-On / Supply Monitor Reset Flag, and Supply Monitor Reset Enable
RSTSRC_PORSF__NOT_SET  EQU 000H ; A power-on or supply monitor reset did not occur.                    
RSTSRC_PORSF__SET      EQU 002H ; A power-on or supply monitor reset occurred.                         
                                                                                                       
RSTSRC_MCDRSF__BMASK   EQU 004H ; Missing Clock Detector Enable and Flag                               
RSTSRC_MCDRSF__SHIFT   EQU 002H ; Missing Clock Detector Enable and Flag                               
RSTSRC_MCDRSF__NOT_SET EQU 000H ; A missing clock detector reset did not occur.                        
RSTSRC_MCDRSF__SET     EQU 004H ; A missing clock detector reset occurred.                             
                                                                                                       
RSTSRC_WDTRSF__BMASK   EQU 008H ; Watchdog Timer Reset Flag                                            
RSTSRC_WDTRSF__SHIFT   EQU 003H ; Watchdog Timer Reset Flag                                            
RSTSRC_WDTRSF__NOT_SET EQU 000H ; A watchdog timer overflow reset did not occur.                       
RSTSRC_WDTRSF__SET     EQU 008H ; A watchdog timer overflow reset occurred.                            
                                                                                                       
RSTSRC_SWRSF__BMASK    EQU 010H ; Software Reset Force and Flag                                        
RSTSRC_SWRSF__SHIFT    EQU 004H ; Software Reset Force and Flag                                        
RSTSRC_SWRSF__NOT_SET  EQU 000H ; A software reset did not occur.                                      
RSTSRC_SWRSF__SET      EQU 010H ; A software reset occurred.                                           
                                                                                                       
RSTSRC_C0RSEF__BMASK   EQU 020H ; Comparator0 Reset Enable and Flag                                    
RSTSRC_C0RSEF__SHIFT   EQU 005H ; Comparator0 Reset Enable and Flag                                    
RSTSRC_C0RSEF__NOT_SET EQU 000H ; A Comparator 0 reset did not occur.                                  
RSTSRC_C0RSEF__SET     EQU 020H ; A Comparator 0 reset occurred.                                       
                                                                                                       
RSTSRC_FERROR__BMASK   EQU 040H ; Flash Error Reset Flag                                               
RSTSRC_FERROR__SHIFT   EQU 006H ; Flash Error Reset Flag                                               
RSTSRC_FERROR__NOT_SET EQU 000H ; A flash error reset did not occur.                                   
RSTSRC_FERROR__SET     EQU 040H ; A flash error reset occurred.                                        
                                                                                                       
RSTSRC_USBRSF__BMASK   EQU 080H ; USB Reset Enable and Flag                                            
RSTSRC_USBRSF__SHIFT   EQU 007H ; USB Reset Enable and Flag                                            
RSTSRC_USBRSF__NOT_SET EQU 000H ; A USB0 reset did not occur.                                          
RSTSRC_USBRSF__SET     EQU 080H ; A USB0 reset occurred.                                               
                                                                                                       
;------------------------------------------------------------------------------
; SFRPAGE Enums (SFR Page @ 0xA7)
;------------------------------------------------------------------------------
SFRPAGE_SFRPAGE__FMASK EQU 0FFH ; SFR Page
SFRPAGE_SFRPAGE__SHIFT EQU 000H ; SFR Page
                                          
;------------------------------------------------------------------------------
; SFRPGCN Enums (SFR Page Control @ 0xCF)
;------------------------------------------------------------------------------
SFRPGCN_SFRPGEN__BMASK        EQU 001H ; SFR Automatic Page Control Enable                
SFRPGCN_SFRPGEN__SHIFT        EQU 000H ; SFR Automatic Page Control Enable                
SFRPGCN_SFRPGEN__DISABLED     EQU 000H ; Disable automatic SFR paging.                    
SFRPGCN_SFRPGEN__ENABLED      EQU 001H ; Enable automatic SFR paging.                     
                                                                                          
SFRPGCN_SFRPGIDX__FMASK       EQU 070H ; SFR Page Stack Index                             
SFRPGCN_SFRPGIDX__SHIFT       EQU 004H ; SFR Page Stack Index                             
SFRPGCN_SFRPGIDX__FIRST_BYTE  EQU 000H ; SFRSTACK contains the value of SFRPAGE, the      
                                       ; first/top byte of the SFR page stack.            
SFRPGCN_SFRPGIDX__SECOND_BYTE EQU 010H ; SFRSTACK contains the value of the second byte of
                                       ; the SFR page stack.                              
SFRPGCN_SFRPGIDX__THIRD_BYTE  EQU 020H ; SFRSTACK contains the value of the third byte of 
                                       ; the SFR page stack.                              
SFRPGCN_SFRPGIDX__FOURTH_BYTE EQU 030H ; SFRSTACK contains the value of the fourth byte of
                                       ; the SFR page stack.                              
SFRPGCN_SFRPGIDX__FIFTH_BYTE  EQU 040H ; SFRSTACK contains the value of the fifth byte of 
                                       ; the SFR page stack.                              
                                                                                          
;------------------------------------------------------------------------------
; SFRSTACK Enums (SFR Page Stack @ 0xD7)
;------------------------------------------------------------------------------
SFRSTACK_SFRSTACK__FMASK EQU 0FFH ; SFR Page Stack
SFRSTACK_SFRSTACK__SHIFT EQU 000H ; SFR Page Stack
                                                  
;------------------------------------------------------------------------------
; SMB0ADM Enums (SMBus 0 Slave Address Mask @ 0xD6)
;------------------------------------------------------------------------------
SMB0ADM_EHACK__BMASK             EQU 001H ; Hardware Acknowledge Enable                     
SMB0ADM_EHACK__SHIFT             EQU 000H ; Hardware Acknowledge Enable                     
SMB0ADM_EHACK__ADR_ACK_MANUAL    EQU 000H ; Firmware must manually acknowledge all incoming 
                                          ; address and data bytes.                         
SMB0ADM_EHACK__ADR_ACK_AUTOMATIC EQU 001H ; Automatic slave address recognition and hardware
                                          ; acknowledge is enabled.                         
                                                                                            
SMB0ADM_SLVM__FMASK              EQU 0FEH ; SMBus Slave Address Mask                        
SMB0ADM_SLVM__SHIFT              EQU 001H ; SMBus Slave Address Mask                        
                                                                                            
;------------------------------------------------------------------------------
; SMB0ADR Enums (SMBus 0 Slave Address @ 0xD7)
;------------------------------------------------------------------------------
SMB0ADR_GC__BMASK      EQU 001H ; General Call Address Enable        
SMB0ADR_GC__SHIFT      EQU 000H ; General Call Address Enable        
SMB0ADR_GC__IGNORED    EQU 000H ; General Call Address is ignored.   
SMB0ADR_GC__RECOGNIZED EQU 001H ; General Call Address is recognized.
                                                                     
SMB0ADR_SLV__FMASK     EQU 0FEH ; SMBus Hardware Slave Address       
SMB0ADR_SLV__SHIFT     EQU 001H ; SMBus Hardware Slave Address       
                                                                     
;------------------------------------------------------------------------------
; SMB0CF Enums (SMBus 0 Configuration @ 0xC1)
;------------------------------------------------------------------------------
SMB0CF_SMBCS__FMASK             EQU 003H ; SMBus Clock Source Selection                     
SMB0CF_SMBCS__SHIFT             EQU 000H ; SMBus Clock Source Selection                     
SMB0CF_SMBCS__TIMER0            EQU 000H ; Timer 0 Overflow.                                
SMB0CF_SMBCS__TIMER1            EQU 001H ; Timer 1 Overflow.                                
SMB0CF_SMBCS__TIMER2_HIGH       EQU 002H ; Timer 2 High Byte Overflow.                      
SMB0CF_SMBCS__TIMER2_LOW        EQU 003H ; Timer 2 Low Byte Overflow.                       
                                                                                            
SMB0CF_SMBFTE__BMASK            EQU 004H ; SMBus Free Timeout Detection Enable              
SMB0CF_SMBFTE__SHIFT            EQU 002H ; SMBus Free Timeout Detection Enable              
SMB0CF_SMBFTE__FREE_TO_DISABLED EQU 000H ; Disable bus free timeouts.                       
SMB0CF_SMBFTE__FREE_TO_ENABLED  EQU 004H ; Enable bus free timeouts. The bus the bus will be
                                         ; considered free if SCL and SDA remain high for   
                                         ; more than 10 SMBus clock source periods.         
                                                                                            
SMB0CF_SMBTOE__BMASK            EQU 008H ; SMBus SCL Timeout Detection Enable               
SMB0CF_SMBTOE__SHIFT            EQU 003H ; SMBus SCL Timeout Detection Enable               
SMB0CF_SMBTOE__SCL_TO_DISABLED  EQU 000H ; Disable SCL low timeouts.                        
SMB0CF_SMBTOE__SCL_TO_ENABLED   EQU 008H ; Enable SCL low timeouts.                         
                                                                                            
SMB0CF_EXTHOLD__BMASK           EQU 010H ; SMBus Setup and Hold Time Extension Enable       
SMB0CF_EXTHOLD__SHIFT           EQU 004H ; SMBus Setup and Hold Time Extension Enable       
SMB0CF_EXTHOLD__DISABLED        EQU 000H ; Disable SDA extended setup and hold times.       
SMB0CF_EXTHOLD__ENABLED         EQU 010H ; Enable SDA extended setup and hold times. See the
                                         ; DLYEXT field in SMB0TC for the number of SYSCLKs 
                                         ; to extend the setup and hold times.              
                                                                                            
SMB0CF_BUSY__BMASK              EQU 020H ; SMBus Busy Indicator                             
SMB0CF_BUSY__SHIFT              EQU 005H ; SMBus Busy Indicator                             
SMB0CF_BUSY__NOT_SET            EQU 000H ; The bus is not busy.                             
SMB0CF_BUSY__SET                EQU 020H ; The bus is busy and a transfer is currently in   
                                         ; progress.                                        
                                                                                            
SMB0CF_INH__BMASK               EQU 040H ; SMBus Slave Inhibit                              
SMB0CF_INH__SHIFT               EQU 006H ; SMBus Slave Inhibit                              
SMB0CF_INH__SLAVE_ENABLED       EQU 000H ; Slave states are enabled.                        
SMB0CF_INH__SLAVE_DISABLED      EQU 040H ; Slave states are inhibited.                      
                                                                                            
SMB0CF_ENSMB__BMASK             EQU 080H ; SMBus Enable                                     
SMB0CF_ENSMB__SHIFT             EQU 007H ; SMBus Enable                                     
SMB0CF_ENSMB__DISABLED          EQU 000H ; Disable the SMBus module.                        
SMB0CF_ENSMB__ENABLED           EQU 080H ; Enable the SMBus module.                         
                                                                                            
;------------------------------------------------------------------------------
; SMB0CN0 Enums (SMBus 0 Control @ 0xC0)
;------------------------------------------------------------------------------
SMB0CN0_SI__BMASK           EQU 001H ; SMBus Interrupt Flag                           
SMB0CN0_SI__SHIFT           EQU 000H ; SMBus Interrupt Flag                           
SMB0CN0_SI__NOT_SET         EQU 000H ;                                                
SMB0CN0_SI__SET             EQU 001H ;                                                
                                                                                      
SMB0CN0_ACK__BMASK          EQU 002H ; SMBus Acknowledge                              
SMB0CN0_ACK__SHIFT          EQU 001H ; SMBus Acknowledge                              
SMB0CN0_ACK__NOT_SET        EQU 000H ; Generate a NACK, or the response was a NACK.   
SMB0CN0_ACK__SET            EQU 002H ; Generate an ACK, or the response was an ACK.   
                                                                                      
SMB0CN0_ARBLOST__BMASK      EQU 004H ; SMBus Arbitration Lost Indicator               
SMB0CN0_ARBLOST__SHIFT      EQU 002H ; SMBus Arbitration Lost Indicator               
SMB0CN0_ARBLOST__NOT_SET    EQU 000H ; No arbitration error.                          
SMB0CN0_ARBLOST__ERROR      EQU 004H ; Arbitration error occurred.                    
                                                                                      
SMB0CN0_ACKRQ__BMASK        EQU 008H ; SMBus Acknowledge Request                      
SMB0CN0_ACKRQ__SHIFT        EQU 003H ; SMBus Acknowledge Request                      
SMB0CN0_ACKRQ__NOT_SET      EQU 000H ; No ACK requested.                              
SMB0CN0_ACKRQ__REQUESTED    EQU 008H ; ACK requested.                                 
                                                                                      
SMB0CN0_STO__BMASK          EQU 010H ; SMBus Stop Flag                                
SMB0CN0_STO__SHIFT          EQU 004H ; SMBus Stop Flag                                
SMB0CN0_STO__NOT_SET        EQU 000H ; A STOP is not pending.                         
SMB0CN0_STO__SET            EQU 010H ; Generate a STOP or a STOP is currently pending.
                                                                                      
SMB0CN0_STA__BMASK          EQU 020H ; SMBus Start Flag                               
SMB0CN0_STA__SHIFT          EQU 005H ; SMBus Start Flag                               
SMB0CN0_STA__NOT_SET        EQU 000H ; A START was not detected.                      
SMB0CN0_STA__SET            EQU 020H ; Generate a START, repeated START, or a START is
                                     ; currently pending.                             
                                                                                      
SMB0CN0_TXMODE__BMASK       EQU 040H ; SMBus Transmit Mode Indicator                  
SMB0CN0_TXMODE__SHIFT       EQU 006H ; SMBus Transmit Mode Indicator                  
SMB0CN0_TXMODE__RECEIVER    EQU 000H ; SMBus in Receiver Mode.                        
SMB0CN0_TXMODE__TRANSMITTER EQU 040H ; SMBus in Transmitter Mode.                     
                                                                                      
SMB0CN0_MASTER__BMASK       EQU 080H ; SMBus Master/Slave Indicator                   
SMB0CN0_MASTER__SHIFT       EQU 007H ; SMBus Master/Slave Indicator                   
SMB0CN0_MASTER__SLAVE       EQU 000H ; SMBus operating in slave mode.                 
SMB0CN0_MASTER__MASTER      EQU 080H ; SMBus operating in master mode.                
                                                                                      
;------------------------------------------------------------------------------
; SMB0DAT Enums (SMBus 0 Data @ 0xC2)
;------------------------------------------------------------------------------
SMB0DAT_SMB0DAT__FMASK EQU 0FFH ; SMBus 0 Data
SMB0DAT_SMB0DAT__SHIFT EQU 000H ; SMBus 0 Data
                                              
;------------------------------------------------------------------------------
; SMB0FCN0 Enums (SMBus 0 FIFO Control 0 @ 0xC3)
;------------------------------------------------------------------------------
SMB0FCN0_RXTH__FMASK     EQU 003H ; RX FIFO Threshold                                 
SMB0FCN0_RXTH__SHIFT     EQU 000H ; RX FIFO Threshold                                 
SMB0FCN0_RXTH__ZERO      EQU 000H ; RFRQ will be set anytime new data arrives in the  
                                  ; RX FIFO (when the RX FIFO is not empty).          
                                                                                      
SMB0FCN0_RFLSH__BMASK    EQU 004H ; RX FIFO Flush                                     
SMB0FCN0_RFLSH__SHIFT    EQU 002H ; RX FIFO Flush                                     
SMB0FCN0_RFLSH__FLUSH    EQU 004H ; Initiate an RX FIFO flush.                        
                                                                                      
SMB0FCN0_RFRQE__BMASK    EQU 008H ; Read Request Interrupt Enable                     
SMB0FCN0_RFRQE__SHIFT    EQU 003H ; Read Request Interrupt Enable                     
SMB0FCN0_RFRQE__DISABLED EQU 000H ; SMBus 0 interrupts will not be generated when RFRQ
                                  ; is set.                                           
SMB0FCN0_RFRQE__ENABLED  EQU 008H ; SMBus 0 interrupts will be generated if RFRQ is   
                                  ; set.                                              
                                                                                      
SMB0FCN0_TXTH__FMASK     EQU 030H ; TX FIFO Threshold                                 
SMB0FCN0_TXTH__SHIFT     EQU 004H ; TX FIFO Threshold                                 
SMB0FCN0_TXTH__ZERO      EQU 000H ; TFRQ will be set when the TX FIFO is empty.       
                                                                                      
SMB0FCN0_TFLSH__BMASK    EQU 040H ; TX FIFO Flush                                     
SMB0FCN0_TFLSH__SHIFT    EQU 006H ; TX FIFO Flush                                     
SMB0FCN0_TFLSH__FLUSH    EQU 040H ; Initiate a TX FIFO flush.                         
                                                                                      
SMB0FCN0_TFRQE__BMASK    EQU 080H ; Write Request Interrupt Enable                    
SMB0FCN0_TFRQE__SHIFT    EQU 007H ; Write Request Interrupt Enable                    
SMB0FCN0_TFRQE__DISABLED EQU 000H ; SMBus 0 interrupts will not be generated when TFRQ
                                  ; is set.                                           
SMB0FCN0_TFRQE__ENABLED  EQU 080H ; SMBus 0 interrupts will be generated if TFRQ is   
                                  ; set.                                              
                                                                                      
;------------------------------------------------------------------------------
; SMB0FCN1 Enums (SMBus 0 FIFO Control 1 @ 0xC4)
;------------------------------------------------------------------------------
SMB0FCN1_RXE__BMASK     EQU 004H ; RX FIFO Empty                                     
SMB0FCN1_RXE__SHIFT     EQU 002H ; RX FIFO Empty                                     
SMB0FCN1_RXE__NOT_EMPTY EQU 000H ; The RX FIFO contains data.                        
SMB0FCN1_RXE__EMPTY     EQU 004H ; The RX FIFO is empty.                             
                                                                                     
SMB0FCN1_RFRQ__BMASK    EQU 008H ; Receive FIFO Request                              
SMB0FCN1_RFRQ__SHIFT    EQU 003H ; Receive FIFO Request                              
SMB0FCN1_RFRQ__NOT_SET  EQU 000H ; The number of bytes in the RX FIFO is less than or
                                 ; equal to RXTH.                                    
SMB0FCN1_RFRQ__SET      EQU 008H ; The number of bytes in the RX FIFO is greater than
                                 ; RXTH.                                             
                                                                                     
SMB0FCN1_TXNF__BMASK    EQU 040H ; TX FIFO Not Full                                  
SMB0FCN1_TXNF__SHIFT    EQU 006H ; TX FIFO Not Full                                  
SMB0FCN1_TXNF__FULL     EQU 000H ; The TX FIFO is full.                              
SMB0FCN1_TXNF__NOT_FULL EQU 040H ; The TX FIFO has room for more data.               
                                                                                     
SMB0FCN1_TFRQ__BMASK    EQU 080H ; Transmit FIFO Request                             
SMB0FCN1_TFRQ__SHIFT    EQU 007H ; Transmit FIFO Request                             
SMB0FCN1_TFRQ__NOT_SET  EQU 000H ; The number of bytes in the TX FIFO is greater than
                                 ; TXTH.                                             
SMB0FCN1_TFRQ__SET      EQU 080H ; The number of bytes in the TX FIFO is less than or
                                 ; equal to TXTH.                                    
                                                                                     
;------------------------------------------------------------------------------
; SMB0FCT Enums (SMBus 0 FIFO Count @ 0xEF)
;------------------------------------------------------------------------------
SMB0FCT_RXCNT__FMASK EQU 007H ; RX FIFO Count
SMB0FCT_RXCNT__SHIFT EQU 000H ; RX FIFO Count
                                             
SMB0FCT_TXCNT__FMASK EQU 070H ; TX FIFO Count
SMB0FCT_TXCNT__SHIFT EQU 004H ; TX FIFO Count
                                             
;------------------------------------------------------------------------------
; SMB0RXLN Enums (SMBus 0 Receive Length Counter @ 0xC5)
;------------------------------------------------------------------------------
SMB0RXLN_RXLN__FMASK EQU 0FFH ; SMBus Receive Length Counter
SMB0RXLN_RXLN__SHIFT EQU 000H ; SMBus Receive Length Counter
                                                            
;------------------------------------------------------------------------------
; SMB0TC Enums (SMBus 0 Timing and Pin Control @ 0xAC)
;------------------------------------------------------------------------------
SMB0TC_SDD__FMASK         EQU 003H ; SMBus Start Detection Window                     
SMB0TC_SDD__SHIFT         EQU 000H ; SMBus Start Detection Window                     
SMB0TC_SDD__NONE          EQU 000H ; No additional SDA falling edge recognition delay 
                                   ; (0-1 SYSCLK).                                    
SMB0TC_SDD__ADD_2_SYSCLKS EQU 001H ; Increase SDA falling edge recognition time window
                                   ; to 2-3 SYSCLKs after the SCL falling edge.       
SMB0TC_SDD__ADD_4_SYSCLKS EQU 002H ; Increase SDA falling edge recognition window to  
                                   ; 4-5 SYSCLKs after the SCL falling edge.          
SMB0TC_SDD__ADD_8_SYSCLKS EQU 003H ; Increase SDA falling edge recognition window to  
                                   ; 8-9 SYSCLKs after the SCL falling edge.          
                                                                                      
SMB0TC_DLYEXT__BMASK      EQU 010H ; Setup and Hold Delay Extension Selection         
SMB0TC_DLYEXT__SHIFT      EQU 004H ; Setup and Hold Delay Extension Selection         
SMB0TC_DLYEXT__SHORT      EQU 000H ; SDA Setup time is 11 SYSCLKs. SDA Hold time is 12
                                   ; SYSCLKs.                                         
SMB0TC_DLYEXT__LONG       EQU 010H ; SDA Setup and Hold time is 31 SYSCLKs.           
                                                                                      
SMB0TC_SWAP__BMASK        EQU 080H ; SMBus Swap Pins                                  
SMB0TC_SWAP__SHIFT        EQU 007H ; SMBus Swap Pins                                  
SMB0TC_SWAP__SDA_LOW_PIN  EQU 000H ; SDA is mapped to the lower-numbered port pin, and
                                   ; SCL is mapped to the higher-numbered port pin.   
SMB0TC_SWAP__SDA_HIGH_PIN EQU 080H ; SCL is mapped to the lower-numbered port pin, and
                                   ; SDA is mapped to the higher-numbered port pin.   
                                                                                      
;------------------------------------------------------------------------------
; SPI0CFG Enums (SPI0 Configuration @ 0xA1)
;------------------------------------------------------------------------------
SPI0CFG_RXE__BMASK                  EQU 001H ; RX FIFO Empty                              
SPI0CFG_RXE__SHIFT                  EQU 000H ; RX FIFO Empty                              
SPI0CFG_RXE__NOT_EMPTY              EQU 000H ; The RX FIFO contains data.                 
SPI0CFG_RXE__EMPTY                  EQU 001H ; The RX FIFO is empty.                      
                                                                                          
SPI0CFG_SRMT__BMASK                 EQU 002H ; Shift Register Empty                       
SPI0CFG_SRMT__SHIFT                 EQU 001H ; Shift Register Empty                       
SPI0CFG_SRMT__NOT_SET               EQU 000H ; The shift register is not empty.           
SPI0CFG_SRMT__SET                   EQU 002H ; The shift register is empty.               
                                                                                          
SPI0CFG_NSSIN__BMASK                EQU 004H ; NSS Instantaneous Pin Input                
SPI0CFG_NSSIN__SHIFT                EQU 002H ; NSS Instantaneous Pin Input                
SPI0CFG_NSSIN__LOW                  EQU 000H ; The NSS pin is low.                        
SPI0CFG_NSSIN__HIGH                 EQU 004H ; The NSS pin is high.                       
                                                                                          
SPI0CFG_SLVSEL__BMASK               EQU 008H ; Slave Selected Flag                        
SPI0CFG_SLVSEL__SHIFT               EQU 003H ; Slave Selected Flag                        
SPI0CFG_SLVSEL__NOT_SELECTED        EQU 000H ; The Slave is not selected (NSS is high).   
SPI0CFG_SLVSEL__SELECTED            EQU 008H ; The Slave is selected (NSS is low).        
                                                                                          
SPI0CFG_CKPOL__BMASK                EQU 010H ; SPI0 Clock Polarity                        
SPI0CFG_CKPOL__SHIFT                EQU 004H ; SPI0 Clock Polarity                        
SPI0CFG_CKPOL__IDLE_LOW             EQU 000H ; SCK line low in idle state.                
SPI0CFG_CKPOL__IDLE_HIGH            EQU 010H ; SCK line high in idle state.               
                                                                                          
SPI0CFG_CKPHA__BMASK                EQU 020H ; SPI0 Clock Phase                           
SPI0CFG_CKPHA__SHIFT                EQU 005H ; SPI0 Clock Phase                           
SPI0CFG_CKPHA__DATA_CENTERED_FIRST  EQU 000H ; Data centered on first edge of SCK period. 
SPI0CFG_CKPHA__DATA_CENTERED_SECOND EQU 020H ; Data centered on second edge of SCK period.
                                                                                          
SPI0CFG_MSTEN__BMASK                EQU 040H ; Master Mode Enable                         
SPI0CFG_MSTEN__SHIFT                EQU 006H ; Master Mode Enable                         
SPI0CFG_MSTEN__MASTER_DISABLED      EQU 000H ; Disable master mode. Operate in slave mode.
SPI0CFG_MSTEN__MASTER_ENABLED       EQU 040H ; Enable master mode. Operate as a master.   
                                                                                          
SPI0CFG_SPIBSY__BMASK               EQU 080H ; SPI Busy                                   
SPI0CFG_SPIBSY__SHIFT               EQU 007H ; SPI Busy                                   
SPI0CFG_SPIBSY__NOT_SET             EQU 000H ; A SPI transfer is not in progress.         
SPI0CFG_SPIBSY__SET                 EQU 080H ; A SPI transfer is in progress.             
                                                                                          
;------------------------------------------------------------------------------
; SPI0CKR Enums (SPI0 Clock Rate @ 0xA2)
;------------------------------------------------------------------------------
SPI0CKR_SPI0CKR__FMASK EQU 0FFH ; SPI0 Clock Rate
SPI0CKR_SPI0CKR__SHIFT EQU 000H ; SPI0 Clock Rate
                                                 
;------------------------------------------------------------------------------
; SPI0CN0 Enums (SPI0 Control @ 0xF8)
;------------------------------------------------------------------------------
SPI0CN0_SPIEN__BMASK                  EQU 001H ; SPI0 Enable                                       
SPI0CN0_SPIEN__SHIFT                  EQU 000H ; SPI0 Enable                                       
SPI0CN0_SPIEN__DISABLED               EQU 000H ; Disable the SPI module.                           
SPI0CN0_SPIEN__ENABLED                EQU 001H ; Enable the SPI module.                            
                                                                                                   
SPI0CN0_TXNF__BMASK                   EQU 002H ; TX FIFO Not Full                                  
SPI0CN0_TXNF__SHIFT                   EQU 001H ; TX FIFO Not Full                                  
SPI0CN0_TXNF__FULL                    EQU 000H ; The TX FIFO is full.                              
SPI0CN0_TXNF__NOT_FULL                EQU 002H ; The TX FIFO has room for more data.               
                                                                                                   
SPI0CN0_NSSMD__FMASK                  EQU 00CH ; Slave Select Mode                                 
SPI0CN0_NSSMD__SHIFT                  EQU 002H ; Slave Select Mode                                 
SPI0CN0_NSSMD__3_WIRE                 EQU 000H ; 3-Wire Slave or 3-Wire Master Mode. NSS signal is 
                                               ; not routed to a port pin.                         
SPI0CN0_NSSMD__4_WIRE_SLAVE           EQU 004H ; 4-Wire Slave or Multi-Master Mode. NSS is an input
                                               ; to the device.                                    
SPI0CN0_NSSMD__4_WIRE_MASTER_NSS_LOW  EQU 008H ; 4-Wire Single-Master Mode. NSS is an output and   
                                               ; logic low.                                        
SPI0CN0_NSSMD__4_WIRE_MASTER_NSS_HIGH EQU 00CH ; 4-Wire Single-Master Mode. NSS is an output and   
                                               ; logic high.                                       
                                                                                                   
SPI0CN0_RXOVRN__BMASK                 EQU 010H ; Receive Overrun Flag                              
SPI0CN0_RXOVRN__SHIFT                 EQU 004H ; Receive Overrun Flag                              
SPI0CN0_RXOVRN__NOT_SET               EQU 000H ; A receive overrun did not occur.                  
SPI0CN0_RXOVRN__SET                   EQU 010H ; A receive overrun occurred.                       
                                                                                                   
SPI0CN0_MODF__BMASK                   EQU 020H ; Mode Fault Flag                                   
SPI0CN0_MODF__SHIFT                   EQU 005H ; Mode Fault Flag                                   
SPI0CN0_MODF__NOT_SET                 EQU 000H ; A master collision did not occur.                 
SPI0CN0_MODF__SET                     EQU 020H ; A master collision occurred.                      
                                                                                                   
SPI0CN0_WCOL__BMASK                   EQU 040H ; Write Collision Flag                              
SPI0CN0_WCOL__SHIFT                   EQU 006H ; Write Collision Flag                              
SPI0CN0_WCOL__NOT_SET                 EQU 000H ; A write collision did not occur.                  
SPI0CN0_WCOL__SET                     EQU 040H ; A write collision occurred.                       
                                                                                                   
SPI0CN0_SPIF__BMASK                   EQU 080H ; SPI0 Interrupt Flag                               
SPI0CN0_SPIF__SHIFT                   EQU 007H ; SPI0 Interrupt Flag                               
SPI0CN0_SPIF__NOT_SET                 EQU 000H ; A data transfer has not completed since the last  
                                               ; time SPIF was cleared.                            
SPI0CN0_SPIF__SET                     EQU 080H ; A data transfer completed.                        
                                                                                                   
;------------------------------------------------------------------------------
; SPI0DAT Enums (SPI0 Data @ 0xA3)
;------------------------------------------------------------------------------
SPI0DAT_SPI0DAT__FMASK EQU 0FFH ; SPI0 Transmit and Receive Data
SPI0DAT_SPI0DAT__SHIFT EQU 000H ; SPI0 Transmit and Receive Data
                                                                
;------------------------------------------------------------------------------
; SPI0FCN0 Enums (SPI0 FIFO Control 0 @ 0x9A)
;------------------------------------------------------------------------------
SPI0FCN0_RXTH__FMASK     EQU 003H ; RX FIFO Threshold                                 
SPI0FCN0_RXTH__SHIFT     EQU 000H ; RX FIFO Threshold                                 
SPI0FCN0_RXTH__ZERO      EQU 000H ; RFRQ will be set anytime new data arrives in the  
                                  ; RX FIFO (when the RX FIFO is not empty).          
SPI0FCN0_RXTH__ONE       EQU 001H ; RFRQ will be set if the RX FIFO contains more than
                                  ; one byte.                                         
                                                                                      
SPI0FCN0_RFLSH__BMASK    EQU 004H ; RX FIFO Flush                                     
SPI0FCN0_RFLSH__SHIFT    EQU 002H ; RX FIFO Flush                                     
SPI0FCN0_RFLSH__FLUSH    EQU 004H ; Initiate an RX FIFO flush.                        
                                                                                      
SPI0FCN0_RFRQE__BMASK    EQU 008H ; Read Request Interrupt Enable                     
SPI0FCN0_RFRQE__SHIFT    EQU 003H ; Read Request Interrupt Enable                     
SPI0FCN0_RFRQE__DISABLED EQU 000H ; SPI0 interrupts will not be generated when RFRQ is
                                  ; set.                                              
SPI0FCN0_RFRQE__ENABLED  EQU 008H ; SPI0 interrupts will be generated if RFRQ is set. 
                                                                                      
SPI0FCN0_TXTH__FMASK     EQU 030H ; TX FIFO Threshold                                 
SPI0FCN0_TXTH__SHIFT     EQU 004H ; TX FIFO Threshold                                 
SPI0FCN0_TXTH__ZERO      EQU 000H ; TFRQ will be set when the TX FIFO is empty.       
SPI0FCN0_TXTH__ONE       EQU 010H ; TFRQ will be set when the TX FIFO contains one or 
                                  ; fewer bytes.                                      
                                                                                      
SPI0FCN0_TFLSH__BMASK    EQU 040H ; TX FIFO Flush                                     
SPI0FCN0_TFLSH__SHIFT    EQU 006H ; TX FIFO Flush                                     
SPI0FCN0_TFLSH__FLUSH    EQU 040H ; Initiate a TX FIFO flush.                         
                                                                                      
SPI0FCN0_TFRQE__BMASK    EQU 080H ; Write Request Interrupt Enable                    
SPI0FCN0_TFRQE__SHIFT    EQU 007H ; Write Request Interrupt Enable                    
SPI0FCN0_TFRQE__DISABLED EQU 000H ; SPI0 interrupts will not be generated when TFRQ is
                                  ; set.                                              
SPI0FCN0_TFRQE__ENABLED  EQU 080H ; SPI0 interrupts will be generated if TFRQ is set. 
                                                                                      
;------------------------------------------------------------------------------
; SPI0FCN1 Enums (SPI0 FIFO Control 1 @ 0x9B)
;------------------------------------------------------------------------------
SPI0FCN1_RXFIFOE__BMASK    EQU 001H ; Receive FIFO Enable                               
SPI0FCN1_RXFIFOE__SHIFT    EQU 000H ; Receive FIFO Enable                               
SPI0FCN1_RXFIFOE__DISABLED EQU 000H ; Received bytes will be discarded.                 
SPI0FCN1_RXFIFOE__ENABLED  EQU 001H ; Received bytes will be placed in the RX FIFO.     
                                                                                        
SPI0FCN1_RXTOE__BMASK      EQU 002H ; Receive Timeout Enable                            
SPI0FCN1_RXTOE__SHIFT      EQU 001H ; Receive Timeout Enable                            
SPI0FCN1_RXTOE__DISABLED   EQU 000H ; Lingering bytes in the RX FIFO will not generate  
                                    ; an interrupt.                                     
SPI0FCN1_RXTOE__ENABLED    EQU 002H ; Lingering bytes in the RX FIFO will generate an   
                                    ; interrupt after timeout.                          
                                                                                        
SPI0FCN1_RFRQ__BMASK       EQU 008H ; Receive FIFO Request                              
SPI0FCN1_RFRQ__SHIFT       EQU 003H ; Receive FIFO Request                              
SPI0FCN1_RFRQ__NOT_SET     EQU 000H ; The number of bytes in the RX FIFO is less than or
                                    ; equal to RXTH.                                    
SPI0FCN1_RFRQ__SET         EQU 008H ; The number of bytes in the RX FIFO is greater than
                                    ; RXTH.                                             
                                                                                        
SPI0FCN1_SPIFEN__BMASK     EQU 010H ; SPIF Interrupt Enable                             
SPI0FCN1_SPIFEN__SHIFT     EQU 004H ; SPIF Interrupt Enable                             
SPI0FCN1_SPIFEN__DISABLED  EQU 000H ; SPI0 interrupts will not be generated when SPIF is
                                    ; set.                                              
SPI0FCN1_SPIFEN__ENABLED   EQU 010H ; SPI0 interrupts will be generated if SPIF is set. 
                                                                                        
SPI0FCN1_TXHOLD__BMASK     EQU 020H ; Transmit Hold                                     
SPI0FCN1_TXHOLD__SHIFT     EQU 005H ; Transmit Hold                                     
SPI0FCN1_TXHOLD__CONTINUE  EQU 000H ; The UART will continue to transmit any available  
                                    ; data in the TX FIFO.                              
SPI0FCN1_TXHOLD__HOLD      EQU 020H ; The UART will not transmit any new data from the  
                                    ; TX FIFO.                                          
                                                                                        
SPI0FCN1_THPOL__BMASK      EQU 040H ; Transmit Hold Polarity                            
SPI0FCN1_THPOL__SHIFT      EQU 006H ; Transmit Hold Polarity                            
SPI0FCN1_THPOL__HOLD_0     EQU 000H ; Data output will be held at logic low when TXHOLD 
                                    ; is set.                                           
SPI0FCN1_THPOL__HOLD_1     EQU 040H ; Data output will be held at logic high when TXHOLD
                                    ; is set.                                           
                                                                                        
SPI0FCN1_TFRQ__BMASK       EQU 080H ; Transmit FIFO Request                             
SPI0FCN1_TFRQ__SHIFT       EQU 007H ; Transmit FIFO Request                             
SPI0FCN1_TFRQ__NOT_SET     EQU 000H ; The number of bytes in the TX FIFO is greater than
                                    ; TXTH.                                             
SPI0FCN1_TFRQ__SET         EQU 080H ; The number of bytes in the TX FIFO is less than or
                                    ; equal to TXTH.                                    
                                                                                        
;------------------------------------------------------------------------------
; SPI0FCT Enums (SPI0 FIFO Count @ 0xF7)
;------------------------------------------------------------------------------
SPI0FCT_RXCNT__FMASK EQU 003H ; RX FIFO Count
SPI0FCT_RXCNT__SHIFT EQU 000H ; RX FIFO Count
                                             
SPI0FCT_TXCNT__FMASK EQU 030H ; TX FIFO Count
SPI0FCT_TXCNT__SHIFT EQU 004H ; TX FIFO Count
                                             
;------------------------------------------------------------------------------
; SPI0PCF Enums (SPI0 Pin Configuration @ 0xDF)
;------------------------------------------------------------------------------
SPI0PCF_SISEL__FMASK     EQU 003H ; Slave MOSI Input Select                           
SPI0PCF_SISEL__SHIFT     EQU 000H ; Slave MOSI Input Select                           
SPI0PCF_SISEL__CROSSBAR  EQU 000H ; The crossbar input is the MOSI input (slave mode).
SPI0PCF_SISEL__CLU0      EQU 001H ; The CLU0 synchronous output is the MOSI input     
                                  ; (slave mode).                                     
SPI0PCF_SISEL__CLU1      EQU 002H ; The CLU1 synchronous output is the MOSI input     
                                  ; (slave mode).                                     
SPI0PCF_SISEL__CLU3      EQU 003H ; The CLU3 synchronous output is the MOSI input     
                                  ; (slave mode).                                     
                                                                                      
SPI0PCF_MISEL__FMASK     EQU 018H ; Master MISO Input Select                          
SPI0PCF_MISEL__SHIFT     EQU 003H ; Master MISO Input Select                          
SPI0PCF_MISEL__CROSSBAR  EQU 000H ; The crossbar input is the MISO input (master      
                                  ; mode).                                            
SPI0PCF_MISEL__CLU0      EQU 008H ; The CLU0 synchronous output is the MISO input     
                                  ; (master mode).                                    
SPI0PCF_MISEL__CLU2      EQU 010H ; The CLU2 synchronous output is the MISO input     
                                  ; (master mode).                                    
SPI0PCF_MISEL__CLU3      EQU 018H ; The CLU3 synchronous output is the MISO input     
                                  ; (master mode).                                    
                                                                                      
SPI0PCF_SCKSEL__FMASK    EQU 0C0H ; Slave Clock Input Select                          
SPI0PCF_SCKSEL__SHIFT    EQU 006H ; Slave Clock Input Select                          
SPI0PCF_SCKSEL__CROSSBAR EQU 000H ; The crossbar input is the SCK input (slave mode). 
SPI0PCF_SCKSEL__CLU1     EQU 040H ; The CLU1 synchronous output is the SCK input      
                                  ; (slave mode).                                     
SPI0PCF_SCKSEL__CLU2     EQU 080H ; The CLU2 synchronous output is the SCK input      
                                  ; (slave mode).                                     
SPI0PCF_SCKSEL__CLU3     EQU 0C0H ; The CLU3 synchronous output is the SCK input      
                                  ; (slave mode).                                     
                                                                                      
;------------------------------------------------------------------------------
; TH0 Enums (Timer 0 High Byte @ 0x8C)
;------------------------------------------------------------------------------
TH0_TH0__FMASK EQU 0FFH ; Timer 0 High Byte
TH0_TH0__SHIFT EQU 000H ; Timer 0 High Byte
                                           
;------------------------------------------------------------------------------
; TH1 Enums (Timer 1 High Byte @ 0x8D)
;------------------------------------------------------------------------------
TH1_TH1__FMASK EQU 0FFH ; Timer 1 High Byte
TH1_TH1__SHIFT EQU 000H ; Timer 1 High Byte
                                           
;------------------------------------------------------------------------------
; TL0 Enums (Timer 0 Low Byte @ 0x8A)
;------------------------------------------------------------------------------
TL0_TL0__FMASK EQU 0FFH ; Timer 0 Low Byte
TL0_TL0__SHIFT EQU 000H ; Timer 0 Low Byte
                                          
;------------------------------------------------------------------------------
; TL1 Enums (Timer 1 Low Byte @ 0x8B)
;------------------------------------------------------------------------------
TL1_TL1__FMASK EQU 0FFH ; Timer 1 Low Byte
TL1_TL1__SHIFT EQU 000H ; Timer 1 Low Byte
                                          
;------------------------------------------------------------------------------
; TMR2CN0 Enums (Timer 2 Control 0 @ 0xC8)
;------------------------------------------------------------------------------
TMR2CN0_T2XCLK__FMASK          EQU 003H ; Timer 2 External Clock Select                    
TMR2CN0_T2XCLK__SHIFT          EQU 000H ; Timer 2 External Clock Select                    
TMR2CN0_T2XCLK__SYSCLK_DIV_12  EQU 000H ; Timer 2 clock is the system clock divided by 12. 
TMR2CN0_T2XCLK__EXTOSC_DIV_8   EQU 001H ; Timer 2 clock is the external oscillator divided 
                                        ; by 8 (synchronized with SYSCLK).                 
                                                                                           
TMR2CN0_TR2__BMASK             EQU 004H ; Timer 2 Run Control                              
TMR2CN0_TR2__SHIFT             EQU 002H ; Timer 2 Run Control                              
TMR2CN0_TR2__STOP              EQU 000H ; Stop Timer 2.                                    
TMR2CN0_TR2__RUN               EQU 004H ; Start Timer 2 running.                           
                                                                                           
TMR2CN0_T2SPLIT__BMASK         EQU 008H ; Timer 2 Split Mode Enable                        
TMR2CN0_T2SPLIT__SHIFT         EQU 003H ; Timer 2 Split Mode Enable                        
TMR2CN0_T2SPLIT__16_BIT_RELOAD EQU 000H ; Timer 2 operates in 16-bit auto-reload mode.     
TMR2CN0_T2SPLIT__8_BIT_RELOAD  EQU 008H ; Timer 2 operates as two 8-bit auto-reload timers.
                                                                                           
TMR2CN0_TF2CEN__BMASK          EQU 010H ; Timer 2 Capture Enable                           
TMR2CN0_TF2CEN__SHIFT          EQU 004H ; Timer 2 Capture Enable                           
TMR2CN0_TF2CEN__DISABLED       EQU 000H ; Disable capture mode.                            
TMR2CN0_TF2CEN__ENABLED        EQU 010H ; Enable capture mode.                             
                                                                                           
TMR2CN0_TF2LEN__BMASK          EQU 020H ; Timer 2 Low Byte Interrupt Enable                
TMR2CN0_TF2LEN__SHIFT          EQU 005H ; Timer 2 Low Byte Interrupt Enable                
TMR2CN0_TF2LEN__DISABLED       EQU 000H ; Disable low byte interrupts.                     
TMR2CN0_TF2LEN__ENABLED        EQU 020H ; Enable low byte interrupts.                      
                                                                                           
TMR2CN0_TF2L__BMASK            EQU 040H ; Timer 2 Low Byte Overflow Flag                   
TMR2CN0_TF2L__SHIFT            EQU 006H ; Timer 2 Low Byte Overflow Flag                   
TMR2CN0_TF2L__NOT_SET          EQU 000H ; Timer 2 low byte did not overflow.               
TMR2CN0_TF2L__SET              EQU 040H ; Timer 2 low byte overflowed.                     
                                                                                           
TMR2CN0_TF2H__BMASK            EQU 080H ; Timer 2 High Byte Overflow Flag                  
TMR2CN0_TF2H__SHIFT            EQU 007H ; Timer 2 High Byte Overflow Flag                  
TMR2CN0_TF2H__NOT_SET          EQU 000H ; Timer 2 8-bit high byte or 16-bit value did not  
                                        ; overflow.                                        
TMR2CN0_TF2H__SET              EQU 080H ; Timer 2 8-bit high byte or 16-bit value          
                                        ; overflowed.                                      
                                                                                           
;------------------------------------------------------------------------------
; TMR2CN1 Enums (Timer 2 Control 1 @ 0xFD)
;------------------------------------------------------------------------------
TMR2CN1_T2CSEL__FMASK       EQU 007H ; Timer 2 Capture Select                           
TMR2CN1_T2CSEL__SHIFT       EQU 000H ; Timer 2 Capture Select                           
TMR2CN1_T2CSEL__PIN         EQU 000H ; Capture high-to-low transitions on the T2 input  
                                     ; pin.                                             
TMR2CN1_T2CSEL__LFOSC       EQU 001H ; Capture high-to-low transitions of the LFO       
                                     ; oscillator.                                      
TMR2CN1_T2CSEL__COMPARATOR0 EQU 002H ; Capture high-to-low transitions of the Comparator
                                     ; 0 output.                                        
TMR2CN1_T2CSEL__USB_SOF     EQU 003H ; Capture USB start-of-frame (SOF) events.         
TMR2CN1_T2CSEL__CLU0_OUT    EQU 004H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 0 synchronous output.    
TMR2CN1_T2CSEL__CLU1_OUT    EQU 005H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 1 synchronous output.    
TMR2CN1_T2CSEL__CLU2_OUT    EQU 006H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 2 synchronous output.    
TMR2CN1_T2CSEL__CLU3_OUT    EQU 007H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 3 synchronous output.    
                                                                                        
TMR2CN1_RLFSEL__FMASK       EQU 0E0H ; Force Reload Select                              
TMR2CN1_RLFSEL__SHIFT       EQU 005H ; Force Reload Select                              
TMR2CN1_RLFSEL__NONE        EQU 000H ; Timer will only reload on overflow events.       
TMR2CN1_RLFSEL__CLU0_OUT    EQU 020H ; Timer will reload on overflow events and CLU0    
                                     ; synchronous output high.                         
TMR2CN1_RLFSEL__CLU1_OUT    EQU 040H ; Timer will reload on overflow events and CLU1    
                                     ; synchronous output high.                         
TMR2CN1_RLFSEL__CLU2_OUT    EQU 060H ; Timer will reload on overflow events and CLU2    
                                     ; synchronous output high.                         
                                                                                        
;------------------------------------------------------------------------------
; TMR2H Enums (Timer 2 High Byte @ 0xCD)
;------------------------------------------------------------------------------
TMR2H_TMR2H__FMASK EQU 0FFH ; Timer 2 High Byte
TMR2H_TMR2H__SHIFT EQU 000H ; Timer 2 High Byte
                                               
;------------------------------------------------------------------------------
; TMR2L Enums (Timer 2 Low Byte @ 0xCC)
;------------------------------------------------------------------------------
TMR2L_TMR2L__FMASK EQU 0FFH ; Timer 2 Low Byte
TMR2L_TMR2L__SHIFT EQU 000H ; Timer 2 Low Byte
                                              
;------------------------------------------------------------------------------
; TMR2RLH Enums (Timer 2 Reload High Byte @ 0xCB)
;------------------------------------------------------------------------------
TMR2RLH_TMR2RLH__FMASK EQU 0FFH ; Timer 2 Reload High Byte
TMR2RLH_TMR2RLH__SHIFT EQU 000H ; Timer 2 Reload High Byte
                                                          
;------------------------------------------------------------------------------
; TMR2RLL Enums (Timer 2 Reload Low Byte @ 0xCA)
;------------------------------------------------------------------------------
TMR2RLL_TMR2RLL__FMASK EQU 0FFH ; Timer 2 Reload Low Byte
TMR2RLL_TMR2RLL__SHIFT EQU 000H ; Timer 2 Reload Low Byte
                                                         
;------------------------------------------------------------------------------
; TMR3CN0 Enums (Timer 3 Control 0 @ 0x91)
;------------------------------------------------------------------------------
TMR3CN0_T3XCLK__FMASK          EQU 003H ; Timer 3 External Clock Select                    
TMR3CN0_T3XCLK__SHIFT          EQU 000H ; Timer 3 External Clock Select                    
TMR3CN0_T3XCLK__SYSCLK_DIV_12  EQU 000H ; Timer 3 clock is the system clock divided by 12. 
TMR3CN0_T3XCLK__EXTOSC_DIV_8   EQU 001H ; Timer 3 clock is the external oscillator divided 
                                        ; by 8 (synchronized with SYSCLK).                 
TMR3CN0_T3XCLK__LFOSC_DIV_8    EQU 003H ; Timer 3 clock is the low-frequency oscillator    
                                        ; divided by 8 (synchronized with SYSCLK).         
                                                                                           
TMR3CN0_TR3__BMASK             EQU 004H ; Timer 3 Run Control                              
TMR3CN0_TR3__SHIFT             EQU 002H ; Timer 3 Run Control                              
TMR3CN0_TR3__STOP              EQU 000H ; Stop Timer 3.                                    
TMR3CN0_TR3__RUN               EQU 004H ; Start Timer 3 running.                           
                                                                                           
TMR3CN0_T3SPLIT__BMASK         EQU 008H ; Timer 3 Split Mode Enable                        
TMR3CN0_T3SPLIT__SHIFT         EQU 003H ; Timer 3 Split Mode Enable                        
TMR3CN0_T3SPLIT__16_BIT_RELOAD EQU 000H ; Timer 3 operates in 16-bit auto-reload mode.     
TMR3CN0_T3SPLIT__8_BIT_RELOAD  EQU 008H ; Timer 3 operates as two 8-bit auto-reload timers.
                                                                                           
TMR3CN0_TF3CEN__BMASK          EQU 010H ; Timer 3 Capture Enable                           
TMR3CN0_TF3CEN__SHIFT          EQU 004H ; Timer 3 Capture Enable                           
TMR3CN0_TF3CEN__DISABLED       EQU 000H ; Disable capture mode.                            
TMR3CN0_TF3CEN__ENABLED        EQU 010H ; Enable capture mode.                             
                                                                                           
TMR3CN0_TF3LEN__BMASK          EQU 020H ; Timer 3 Low Byte Interrupt Enable                
TMR3CN0_TF3LEN__SHIFT          EQU 005H ; Timer 3 Low Byte Interrupt Enable                
TMR3CN0_TF3LEN__DISABLED       EQU 000H ; Disable low byte interrupts.                     
TMR3CN0_TF3LEN__ENABLED        EQU 020H ; Enable low byte interrupts.                      
                                                                                           
TMR3CN0_TF3L__BMASK            EQU 040H ; Timer 3 Low Byte Overflow Flag                   
TMR3CN0_TF3L__SHIFT            EQU 006H ; Timer 3 Low Byte Overflow Flag                   
TMR3CN0_TF3L__NOT_SET          EQU 000H ; Timer 3 low byte did not overflow.               
TMR3CN0_TF3L__SET              EQU 040H ; Timer 3 low byte overflowed.                     
                                                                                           
TMR3CN0_TF3H__BMASK            EQU 080H ; Timer 3 High Byte Overflow Flag                  
TMR3CN0_TF3H__SHIFT            EQU 007H ; Timer 3 High Byte Overflow Flag                  
TMR3CN0_TF3H__NOT_SET          EQU 000H ; Timer 3 8-bit high byte or 16-bit value did not  
                                        ; overflow.                                        
TMR3CN0_TF3H__SET              EQU 080H ; Timer 3 8-bit high byte or 16-bit value          
                                        ; overflowed.                                      
                                                                                           
;------------------------------------------------------------------------------
; TMR3CN1 Enums (Timer 3 Control 1 @ 0xFE)
;------------------------------------------------------------------------------
TMR3CN1_T3CSEL__FMASK       EQU 007H ; Timer 3 Capture Select                           
TMR3CN1_T3CSEL__SHIFT       EQU 000H ; Timer 3 Capture Select                           
TMR3CN1_T3CSEL__PIN         EQU 000H ; Capture high-to-low transitions on the T2 input  
                                     ; pin.                                             
TMR3CN1_T3CSEL__LFOSC       EQU 001H ; Capture high-to-low transitions of the LFO       
                                     ; oscillator.                                      
TMR3CN1_T3CSEL__COMPARATOR0 EQU 002H ; Capture high-to-low transitions of the Comparator
                                     ; 0 output.                                        
TMR3CN1_T3CSEL__USB_SOF     EQU 003H ; Capture USB start-of-frame (SOF) events.         
TMR3CN1_T3CSEL__CLU0_OUT    EQU 004H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 0 synchronous output.    
TMR3CN1_T3CSEL__CLU1_OUT    EQU 005H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 1 synchronous output.    
TMR3CN1_T3CSEL__CLU2_OUT    EQU 006H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 2 synchronous output.    
TMR3CN1_T3CSEL__CLU3_OUT    EQU 007H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 3 synchronous output.    
                                                                                        
TMR3CN1_STSYNC__BMASK       EQU 010H ; Suspend Timer Synchronization Status             
TMR3CN1_STSYNC__SHIFT       EQU 004H ; Suspend Timer Synchronization Status             
TMR3CN1_STSYNC__NOT_SET     EQU 000H ; It is safe to read and write the timer registers.
TMR3CN1_STSYNC__SET         EQU 010H ; Reads and writes of the timer register should not
                                     ; be performed                                     
                                                                                        
TMR3CN1_RLFSEL__FMASK       EQU 0E0H ; Force Reload Select                              
TMR3CN1_RLFSEL__SHIFT       EQU 005H ; Force Reload Select                              
TMR3CN1_RLFSEL__SMB_SCL     EQU 000H ; If SMBTOE is 0, then this is always 0. If SMBTOE 
                                     ; is 1, then the timer will only reload on overflow
                                     ; events and when the SMB0 SCL signal is high.     
TMR3CN1_RLFSEL__CLU0_OUT    EQU 020H ; Timer will reload on overflow events and CLU0    
                                     ; synchronous output high.                         
TMR3CN1_RLFSEL__CLU1_OUT    EQU 040H ; Timer will reload on overflow events and CLU1    
                                     ; synchronous output high.                         
TMR3CN1_RLFSEL__CLU2_OUT    EQU 060H ; Timer will reload on overflow events and CLU2    
                                     ; synchronous output high.                         
TMR3CN1_RLFSEL__NONE        EQU 080H ; Timer will only reload on overflow events.       
                                                                                        
;------------------------------------------------------------------------------
; TMR3H Enums (Timer 3 High Byte @ 0x95)
;------------------------------------------------------------------------------
TMR3H_TMR3H__FMASK EQU 0FFH ; Timer 3 High Byte
TMR3H_TMR3H__SHIFT EQU 000H ; Timer 3 High Byte
                                               
;------------------------------------------------------------------------------
; TMR3L Enums (Timer 3 Low Byte @ 0x94)
;------------------------------------------------------------------------------
TMR3L_TMR3L__FMASK EQU 0FFH ; Timer 3 Low Byte
TMR3L_TMR3L__SHIFT EQU 000H ; Timer 3 Low Byte
                                              
;------------------------------------------------------------------------------
; TMR3RLH Enums (Timer 3 Reload High Byte @ 0x93)
;------------------------------------------------------------------------------
TMR3RLH_TMR3RLH__FMASK EQU 0FFH ; Timer 3 Reload High Byte
TMR3RLH_TMR3RLH__SHIFT EQU 000H ; Timer 3 Reload High Byte
                                                          
;------------------------------------------------------------------------------
; TMR3RLL Enums (Timer 3 Reload Low Byte @ 0x92)
;------------------------------------------------------------------------------
TMR3RLL_TMR3RLL__FMASK EQU 0FFH ; Timer 3 Reload Low Byte
TMR3RLL_TMR3RLL__SHIFT EQU 000H ; Timer 3 Reload Low Byte
                                                         
;------------------------------------------------------------------------------
; TMR4CN0 Enums (Timer 4 Control 0 @ 0x98)
;------------------------------------------------------------------------------
TMR4CN0_T4XCLK__FMASK          EQU 003H ; Timer 4 External Clock Select                    
TMR4CN0_T4XCLK__SHIFT          EQU 000H ; Timer 4 External Clock Select                    
TMR4CN0_T4XCLK__SYSCLK_DIV_12  EQU 000H ; Timer 4 clock is the system clock divided by 12. 
TMR4CN0_T4XCLK__EXTOSC_DIV_8   EQU 001H ; Timer 4 clock is the external oscillator divided 
                                        ; by 8 (synchronized with SYSCLK).                 
TMR4CN0_T4XCLK__TIMER3         EQU 002H ; Timer 4 is clocked by Timer 3 overflows.         
TMR4CN0_T4XCLK__LFOSC_DIV_8    EQU 003H ; Timer 4 clock is the low-frequency oscillator    
                                        ; divided by 8 (synchronized with SYSCLK).         
                                                                                           
TMR4CN0_TR4__BMASK             EQU 004H ; Timer 4 Run Control                              
TMR4CN0_TR4__SHIFT             EQU 002H ; Timer 4 Run Control                              
TMR4CN0_TR4__STOP              EQU 000H ; Stop Timer 4.                                    
TMR4CN0_TR4__RUN               EQU 004H ; Start Timer 4 running.                           
                                                                                           
TMR4CN0_T4SPLIT__BMASK         EQU 008H ; Timer 4 Split Mode Enable                        
TMR4CN0_T4SPLIT__SHIFT         EQU 003H ; Timer 4 Split Mode Enable                        
TMR4CN0_T4SPLIT__16_BIT_RELOAD EQU 000H ; Timer 4 operates in 16-bit auto-reload mode.     
TMR4CN0_T4SPLIT__8_BIT_RELOAD  EQU 008H ; Timer 4 operates as two 8-bit auto-reload timers.
                                                                                           
TMR4CN0_TF4CEN__BMASK          EQU 010H ; Timer 4 Capture Enable                           
TMR4CN0_TF4CEN__SHIFT          EQU 004H ; Timer 4 Capture Enable                           
TMR4CN0_TF4CEN__DISABLED       EQU 000H ; Disable capture mode.                            
TMR4CN0_TF4CEN__ENABLED        EQU 010H ; Enable capture mode.                             
                                                                                           
TMR4CN0_TF4LEN__BMASK          EQU 020H ; Timer 4 Low Byte Interrupt Enable                
TMR4CN0_TF4LEN__SHIFT          EQU 005H ; Timer 4 Low Byte Interrupt Enable                
TMR4CN0_TF4LEN__DISABLED       EQU 000H ; Disable low byte interrupts.                     
TMR4CN0_TF4LEN__ENABLED        EQU 020H ; Enable low byte interrupts.                      
                                                                                           
TMR4CN0_TF4L__BMASK            EQU 040H ; Timer 4 Low Byte Overflow Flag                   
TMR4CN0_TF4L__SHIFT            EQU 006H ; Timer 4 Low Byte Overflow Flag                   
TMR4CN0_TF4L__NOT_SET          EQU 000H ; Timer 4 low byte did not overflow.               
TMR4CN0_TF4L__SET              EQU 040H ; Timer 4 low byte overflowed.                     
                                                                                           
TMR4CN0_TF4H__BMASK            EQU 080H ; Timer 4 High Byte Overflow Flag                  
TMR4CN0_TF4H__SHIFT            EQU 007H ; Timer 4 High Byte Overflow Flag                  
TMR4CN0_TF4H__NOT_SET          EQU 000H ; Timer 4 8-bit high byte or 16-bit value did not  
                                        ; overflow.                                        
TMR4CN0_TF4H__SET              EQU 080H ; Timer 4 8-bit high byte or 16-bit value          
                                        ; overflowed.                                      
                                                                                           
;------------------------------------------------------------------------------
; TMR4CN1 Enums (Timer 4 Control 1 @ 0xFF)
;------------------------------------------------------------------------------
TMR4CN1_T4CSEL__FMASK       EQU 007H ; Timer 4 Capture Select                           
TMR4CN1_T4CSEL__SHIFT       EQU 000H ; Timer 4 Capture Select                           
TMR4CN1_T4CSEL__PIN         EQU 000H ; Capture high-to-low transitions on the T2 input  
                                     ; pin.                                             
TMR4CN1_T4CSEL__LFOSC       EQU 001H ; Capture high-to-low transitions of the LFO       
                                     ; oscillator.                                      
TMR4CN1_T4CSEL__COMPARATOR0 EQU 002H ; Capture high-to-low transitions of the Comparator
                                     ; 0 output.                                        
TMR4CN1_T4CSEL__USB_SOF     EQU 003H ; Capture USB start-of-frame (SOF) events.         
TMR4CN1_T4CSEL__CLU0_OUT    EQU 004H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 0 synchronous output.    
TMR4CN1_T4CSEL__CLU1_OUT    EQU 005H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 1 synchronous output.    
TMR4CN1_T4CSEL__CLU2_OUT    EQU 006H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 2 synchronous output.    
TMR4CN1_T4CSEL__CLU3_OUT    EQU 007H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 3 synchronous output.    
                                                                                        
TMR4CN1_STSYNC__BMASK       EQU 010H ; Suspend Timer Synchronization Status             
TMR4CN1_STSYNC__SHIFT       EQU 004H ; Suspend Timer Synchronization Status             
TMR4CN1_STSYNC__NOT_SET     EQU 000H ; It is safe to read and write the timer registers.
TMR4CN1_STSYNC__SET         EQU 010H ; Reads and writes of the timer register should not
                                     ; be performed                                     
                                                                                        
TMR4CN1_RLFSEL__FMASK       EQU 0E0H ; Force Reload Select                              
TMR4CN1_RLFSEL__SHIFT       EQU 005H ; Force Reload Select                              
TMR4CN1_RLFSEL__CLU0_OUT    EQU 020H ; Timer will reload on overflow events and CLU0    
                                     ; synchronous output high.                         
TMR4CN1_RLFSEL__CLU1_OUT    EQU 040H ; Timer will reload on overflow events and CLU1    
                                     ; synchronous output high.                         
TMR4CN1_RLFSEL__CLU2_OUT    EQU 060H ; Timer will reload on overflow events and CLU2    
                                     ; synchronous output high.                         
TMR4CN1_RLFSEL__NONE        EQU 080H ; Timer will only reload on overflow events.       
                                                                                        
;------------------------------------------------------------------------------
; TMR4H Enums (Timer 4 High Byte @ 0xA5)
;------------------------------------------------------------------------------
TMR4H_TMR4H__FMASK EQU 0FFH ; Timer 4 High Byte
TMR4H_TMR4H__SHIFT EQU 000H ; Timer 4 High Byte
                                               
;------------------------------------------------------------------------------
; TMR4L Enums (Timer 4 Low Byte @ 0xA4)
;------------------------------------------------------------------------------
TMR4L_TMR4L__FMASK EQU 0FFH ; Timer 4 Low Byte
TMR4L_TMR4L__SHIFT EQU 000H ; Timer 4 Low Byte
                                              
;------------------------------------------------------------------------------
; TMR4RLH Enums (Timer 4 Reload High Byte @ 0xA3)
;------------------------------------------------------------------------------
TMR4RLH_TMR4RLH__FMASK EQU 0FFH ; Timer 4 Reload High Byte
TMR4RLH_TMR4RLH__SHIFT EQU 000H ; Timer 4 Reload High Byte
                                                          
;------------------------------------------------------------------------------
; TMR4RLL Enums (Timer 4 Reload Low Byte @ 0xA2)
;------------------------------------------------------------------------------
TMR4RLL_TMR4RLL__FMASK EQU 0FFH ; Timer 4 Reload Low Byte
TMR4RLL_TMR4RLL__SHIFT EQU 000H ; Timer 4 Reload Low Byte
                                                         
;------------------------------------------------------------------------------
; TMR5CN0 Enums (Timer 5 Control 0 @ 0xC0)
;------------------------------------------------------------------------------
TMR5CN0_T5XCLK__FMASK          EQU 003H ; Timer 5 External Clock Select                     
TMR5CN0_T5XCLK__SHIFT          EQU 000H ; Timer 5 External Clock Select                     
TMR5CN0_T5XCLK__SYSCLK_DIV_12  EQU 000H ; Timer 5 clock is the system clock divided by 12.  
TMR5CN0_T5XCLK__EXTOSC_DIV_8   EQU 001H ; Timer 5 clock is the external oscillator divided  
                                        ; by 8 (synchronized with SYSCLK when not in suspend
                                        ; or snooze mode).                                  
                                                                                            
TMR5CN0_TR5__BMASK             EQU 004H ; Timer 5 Run Control                               
TMR5CN0_TR5__SHIFT             EQU 002H ; Timer 5 Run Control                               
TMR5CN0_TR5__STOP              EQU 000H ; Stop Timer 5.                                     
TMR5CN0_TR5__RUN               EQU 004H ; Start Timer 5 running.                            
                                                                                            
TMR5CN0_T5SPLIT__BMASK         EQU 008H ; Timer 5 Split Mode Enable                         
TMR5CN0_T5SPLIT__SHIFT         EQU 003H ; Timer 5 Split Mode Enable                         
TMR5CN0_T5SPLIT__16_BIT_RELOAD EQU 000H ; Timer 5 operates in 16-bit auto-reload mode.      
TMR5CN0_T5SPLIT__8_BIT_RELOAD  EQU 008H ; Timer 5 operates as two 8-bit auto-reload timers. 
                                                                                            
TMR5CN0_TF5CEN__BMASK          EQU 010H ; Timer 5 Capture Enable                            
TMR5CN0_TF5CEN__SHIFT          EQU 004H ; Timer 5 Capture Enable                            
TMR5CN0_TF5CEN__DISABLED       EQU 000H ; Disable capture mode.                             
TMR5CN0_TF5CEN__ENABLED        EQU 010H ; Enable capture mode.                              
                                                                                            
TMR5CN0_TF5LEN__BMASK          EQU 020H ; Timer 5 Low Byte Interrupt Enable                 
TMR5CN0_TF5LEN__SHIFT          EQU 005H ; Timer 5 Low Byte Interrupt Enable                 
TMR5CN0_TF5LEN__DISABLED       EQU 000H ; Disable low byte interrupts.                      
TMR5CN0_TF5LEN__ENABLED        EQU 020H ; Enable low byte interrupts.                       
                                                                                            
TMR5CN0_TF5L__BMASK            EQU 040H ; Timer 5 Low Byte Overflow Flag                    
TMR5CN0_TF5L__SHIFT            EQU 006H ; Timer 5 Low Byte Overflow Flag                    
TMR5CN0_TF5L__NOT_SET          EQU 000H ; Timer 5 low byte did not overflow.                
TMR5CN0_TF5L__SET              EQU 040H ; Timer 5 low byte overflowed.                      
                                                                                            
TMR5CN0_TF5H__BMASK            EQU 080H ; Timer 5 High Byte Overflow Flag                   
TMR5CN0_TF5H__SHIFT            EQU 007H ; Timer 5 High Byte Overflow Flag                   
TMR5CN0_TF5H__NOT_SET          EQU 000H ; Timer 5 8-bit high byte or 16-bit value did not   
                                        ; overflow.                                         
TMR5CN0_TF5H__SET              EQU 080H ; Timer 5 8-bit high byte or 16-bit value           
                                        ; overflowed.                                       
                                                                                            
;------------------------------------------------------------------------------
; TMR5CN1 Enums (Timer 5 Control 1 @ 0xF1)
;------------------------------------------------------------------------------
TMR5CN1_T5CSEL__FMASK       EQU 007H ; Timer 5 Capture Select                           
TMR5CN1_T5CSEL__SHIFT       EQU 000H ; Timer 5 Capture Select                           
TMR5CN1_T5CSEL__PIN         EQU 000H ; Capture high-to-low transitions on the T2 input  
                                     ; pin.                                             
TMR5CN1_T5CSEL__LFOSC       EQU 001H ; Capture high-to-low transitions of the LFO       
                                     ; oscillator.                                      
TMR5CN1_T5CSEL__COMPARATOR0 EQU 002H ; Capture high-to-low transitions of the Comparator
                                     ; 0 output.                                        
TMR5CN1_T5CSEL__USB_SOF     EQU 003H ; Capture USB start-of-frame (SOF) events.         
TMR5CN1_T5CSEL__CLU0_OUT    EQU 004H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 0 synchronous output.    
TMR5CN1_T5CSEL__CLU1_OUT    EQU 005H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 1 synchronous output.    
TMR5CN1_T5CSEL__CLU2_OUT    EQU 006H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 2 synchronous output.    
TMR5CN1_T5CSEL__CLU3_OUT    EQU 007H ; Capture high-to-low transitions on the           
                                     ; configurable logic unit 3 synchronous output.    
                                                                                        
TMR5CN1_RLFSEL__FMASK       EQU 0E0H ; Force Reload Select                              
TMR5CN1_RLFSEL__SHIFT       EQU 005H ; Force Reload Select                              
TMR5CN1_RLFSEL__CLU0_OUT    EQU 020H ; Timer will reload on overflow events and CLU0    
                                     ; synchronous output high.                         
TMR5CN1_RLFSEL__CLU1_OUT    EQU 040H ; Timer will reload on overflow events and CLU1    
                                     ; synchronous output high.                         
TMR5CN1_RLFSEL__CLU3_OUT    EQU 060H ; Timer will reload on overflow events and CLU3    
                                     ; synchronous output high.                         
                                                                                        
;------------------------------------------------------------------------------
; TMR5H Enums (Timer 5 High Byte @ 0xD5)
;------------------------------------------------------------------------------
TMR5H_TMR5H__FMASK EQU 0FFH ; Timer 5 High Byte
TMR5H_TMR5H__SHIFT EQU 000H ; Timer 5 High Byte
                                               
;------------------------------------------------------------------------------
; TMR5L Enums (Timer 5 Low Byte @ 0xD4)
;------------------------------------------------------------------------------
TMR5L_TMR5L__FMASK EQU 0FFH ; Timer 5 Low Byte
TMR5L_TMR5L__SHIFT EQU 000H ; Timer 5 Low Byte
                                              
;------------------------------------------------------------------------------
; TMR5RLH Enums (Timer 5 Reload High Byte @ 0xD3)
;------------------------------------------------------------------------------
TMR5RLH_TMR5RLH__FMASK EQU 0FFH ; Timer 5 Reload High Byte
TMR5RLH_TMR5RLH__SHIFT EQU 000H ; Timer 5 Reload High Byte
                                                          
;------------------------------------------------------------------------------
; TMR5RLL Enums (Timer 5 Reload Low Byte @ 0xD2)
;------------------------------------------------------------------------------
TMR5RLL_TMR5RLL__FMASK EQU 0FFH ; Timer 5 Reload Low Byte
TMR5RLL_TMR5RLL__SHIFT EQU 000H ; Timer 5 Reload Low Byte
                                                         
;------------------------------------------------------------------------------
; CKCON0 Enums (Clock Control 0 @ 0x8E)
;------------------------------------------------------------------------------
CKCON0_SCA__FMASK           EQU 003H ; Timer 0/1 Prescale                                
CKCON0_SCA__SHIFT           EQU 000H ; Timer 0/1 Prescale                                
CKCON0_SCA__SYSCLK_DIV_12   EQU 000H ; System clock divided by 12.                       
CKCON0_SCA__SYSCLK_DIV_4    EQU 001H ; System clock divided by 4.                        
CKCON0_SCA__SYSCLK_DIV_48   EQU 002H ; System clock divided by 48.                       
CKCON0_SCA__EXTOSC_DIV_8    EQU 003H ; External oscillator divided by 8 (synchronized    
                                     ; with the system clock).                           
                                                                                         
CKCON0_T0M__BMASK           EQU 004H ; Timer 0 Clock Select                              
CKCON0_T0M__SHIFT           EQU 002H ; Timer 0 Clock Select                              
CKCON0_T0M__PRESCALE        EQU 000H ; Counter/Timer 0 uses the clock defined by the     
                                     ; prescale field, SCA.                              
CKCON0_T0M__SYSCLK          EQU 004H ; Counter/Timer 0 uses the system clock.            
                                                                                         
CKCON0_T1M__BMASK           EQU 008H ; Timer 1 Clock Select                              
CKCON0_T1M__SHIFT           EQU 003H ; Timer 1 Clock Select                              
CKCON0_T1M__PRESCALE        EQU 000H ; Timer 1 uses the clock defined by the prescale    
                                     ; field, SCA.                                       
CKCON0_T1M__SYSCLK          EQU 008H ; Timer 1 uses the system clock.                    
                                                                                         
CKCON0_T2ML__BMASK          EQU 010H ; Timer 2 Low Byte Clock Select                     
CKCON0_T2ML__SHIFT          EQU 004H ; Timer 2 Low Byte Clock Select                     
CKCON0_T2ML__EXTERNAL_CLOCK EQU 000H ; Timer 2 low byte uses the clock defined by T2XCLK 
                                     ; in TMR2CN0.                                       
CKCON0_T2ML__SYSCLK         EQU 010H ; Timer 2 low byte uses the system clock.           
                                                                                         
CKCON0_T2MH__BMASK          EQU 020H ; Timer 2 High Byte Clock Select                    
CKCON0_T2MH__SHIFT          EQU 005H ; Timer 2 High Byte Clock Select                    
CKCON0_T2MH__EXTERNAL_CLOCK EQU 000H ; Timer 2 high byte uses the clock defined by T2XCLK
                                     ; in TMR2CN0.                                       
CKCON0_T2MH__SYSCLK         EQU 020H ; Timer 2 high byte uses the system clock.          
                                                                                         
CKCON0_T3ML__BMASK          EQU 040H ; Timer 3 Low Byte Clock Select                     
CKCON0_T3ML__SHIFT          EQU 006H ; Timer 3 Low Byte Clock Select                     
CKCON0_T3ML__EXTERNAL_CLOCK EQU 000H ; Timer 3 low byte uses the clock defined by T3XCLK 
                                     ; in TMR3CN0.                                       
CKCON0_T3ML__SYSCLK         EQU 040H ; Timer 3 low byte uses the system clock.           
                                                                                         
CKCON0_T3MH__BMASK          EQU 080H ; Timer 3 High Byte Clock Select                    
CKCON0_T3MH__SHIFT          EQU 007H ; Timer 3 High Byte Clock Select                    
CKCON0_T3MH__EXTERNAL_CLOCK EQU 000H ; Timer 3 high byte uses the clock defined by T3XCLK
                                     ; in TMR3CN0.                                       
CKCON0_T3MH__SYSCLK         EQU 080H ; Timer 3 high byte uses the system clock.          
                                                                                         
;------------------------------------------------------------------------------
; CKCON1 Enums (Clock Control 1 @ 0xA6)
;------------------------------------------------------------------------------
CKCON1_T4ML__BMASK          EQU 001H ; Timer 4 Low Byte Clock Select                     
CKCON1_T4ML__SHIFT          EQU 000H ; Timer 4 Low Byte Clock Select                     
CKCON1_T4ML__EXTERNAL_CLOCK EQU 000H ; Timer 4 low byte uses the clock defined by T4XCLK 
                                     ; in TMR4CN0.                                       
CKCON1_T4ML__SYSCLK         EQU 001H ; Timer 4 low byte uses the system clock.           
                                                                                         
CKCON1_T4MH__BMASK          EQU 002H ; Timer 4 High Byte Clock Select                    
CKCON1_T4MH__SHIFT          EQU 001H ; Timer 4 High Byte Clock Select                    
CKCON1_T4MH__EXTERNAL_CLOCK EQU 000H ; Timer 4 high byte uses the clock defined by T4XCLK
                                     ; in TMR4CN0.                                       
CKCON1_T4MH__SYSCLK         EQU 002H ; Timer 4 high byte uses the system clock.          
                                                                                         
CKCON1_T5ML__BMASK          EQU 004H ; Timer 5 Low Byte Clock Select                     
CKCON1_T5ML__SHIFT          EQU 002H ; Timer 5 Low Byte Clock Select                     
CKCON1_T5ML__EXTERNAL_CLOCK EQU 000H ; Timer 5 low byte uses the clock defined by T5XCLK 
                                     ; in TMR5CN0.                                       
CKCON1_T5ML__SYSCLK         EQU 004H ; Timer 5 low byte uses the system clock.           
                                                                                         
CKCON1_T5MH__BMASK          EQU 008H ; Timer 5 High Byte Clock Select                    
CKCON1_T5MH__SHIFT          EQU 003H ; Timer 5 High Byte Clock Select                    
CKCON1_T5MH__EXTERNAL_CLOCK EQU 000H ; Timer 5 high byte uses the clock defined by T5XCLK
                                     ; in TMR5CN0.                                       
CKCON1_T5MH__SYSCLK         EQU 008H ; Timer 5 high byte uses the system clock.          
                                                                                         
;------------------------------------------------------------------------------
; TCON Enums (Timer 0/1 Control @ 0x88)
;------------------------------------------------------------------------------
TCON_IT0__BMASK   EQU 001H ; Interrupt 0 Type Select  
TCON_IT0__SHIFT   EQU 000H ; Interrupt 0 Type Select  
TCON_IT0__LEVEL   EQU 000H ; INT0 is level triggered. 
TCON_IT0__EDGE    EQU 001H ; INT0 is edge triggered.  
                                                      
TCON_IE0__BMASK   EQU 002H ; External Interrupt 0     
TCON_IE0__SHIFT   EQU 001H ; External Interrupt 0     
TCON_IE0__NOT_SET EQU 000H ; Edge/level not detected. 
TCON_IE0__SET     EQU 002H ; Edge/level detected      
                                                      
TCON_IT1__BMASK   EQU 004H ; Interrupt 1 Type Select  
TCON_IT1__SHIFT   EQU 002H ; Interrupt 1 Type Select  
TCON_IT1__LEVEL   EQU 000H ; INT1 is level triggered. 
TCON_IT1__EDGE    EQU 004H ; INT1 is edge triggered.  
                                                      
TCON_IE1__BMASK   EQU 008H ; External Interrupt 1     
TCON_IE1__SHIFT   EQU 003H ; External Interrupt 1     
TCON_IE1__NOT_SET EQU 000H ; Edge/level not detected. 
TCON_IE1__SET     EQU 008H ; Edge/level detected      
                                                      
TCON_TR0__BMASK   EQU 010H ; Timer 0 Run Control      
TCON_TR0__SHIFT   EQU 004H ; Timer 0 Run Control      
TCON_TR0__STOP    EQU 000H ; Stop Timer 0.            
TCON_TR0__RUN     EQU 010H ; Start Timer 0 running.   
                                                      
TCON_TF0__BMASK   EQU 020H ; Timer 0 Overflow Flag    
TCON_TF0__SHIFT   EQU 005H ; Timer 0 Overflow Flag    
TCON_TF0__NOT_SET EQU 000H ; Timer 0 did not overflow.
TCON_TF0__SET     EQU 020H ; Timer 0 overflowed.      
                                                      
TCON_TR1__BMASK   EQU 040H ; Timer 1 Run Control      
TCON_TR1__SHIFT   EQU 006H ; Timer 1 Run Control      
TCON_TR1__STOP    EQU 000H ; Stop Timer 1.            
TCON_TR1__RUN     EQU 040H ; Start Timer 1 running.   
                                                      
TCON_TF1__BMASK   EQU 080H ; Timer 1 Overflow Flag    
TCON_TF1__SHIFT   EQU 007H ; Timer 1 Overflow Flag    
TCON_TF1__NOT_SET EQU 000H ; Timer 1 did not overflow.
TCON_TF1__SET     EQU 080H ; Timer 1 overflowed.      
                                                      
;------------------------------------------------------------------------------
; TMOD Enums (Timer 0/1 Mode @ 0x89)
;------------------------------------------------------------------------------
TMOD_T0M__FMASK      EQU 003H ; Timer 0 Mode Select                               
TMOD_T0M__SHIFT      EQU 000H ; Timer 0 Mode Select                               
TMOD_T0M__MODE0      EQU 000H ; Mode 0, 13-bit Counter/Timer                      
TMOD_T0M__MODE1      EQU 001H ; Mode 1, 16-bit Counter/Timer                      
TMOD_T0M__MODE2      EQU 002H ; Mode 2, 8-bit Counter/Timer with Auto-Reload      
TMOD_T0M__MODE3      EQU 003H ; Mode 3, Two 8-bit Counter/Timers                  
                                                                                  
TMOD_CT0__BMASK      EQU 004H ; Counter/Timer 0 Select                            
TMOD_CT0__SHIFT      EQU 002H ; Counter/Timer 0 Select                            
TMOD_CT0__TIMER      EQU 000H ; Timer Mode. Timer 0 increments on the clock       
                              ; defined by T0M in the CKCON0 register.            
TMOD_CT0__COUNTER    EQU 004H ; Counter Mode. Timer 0 increments on high-to-low   
                              ; transitions of an external pin (T0).              
                                                                                  
TMOD_GATE0__BMASK    EQU 008H ; Timer 0 Gate Control                              
TMOD_GATE0__SHIFT    EQU 003H ; Timer 0 Gate Control                              
TMOD_GATE0__DISABLED EQU 000H ; Timer 0 enabled when TR0 = 1 irrespective of INT0 
                              ; logic level.                                      
TMOD_GATE0__ENABLED  EQU 008H ; Timer 0 enabled only when TR0 = 1 and INT0 is     
                              ; active as defined by bit IN0PL in register IT01CF.
                                                                                  
TMOD_T1M__FMASK      EQU 030H ; Timer 1 Mode Select                               
TMOD_T1M__SHIFT      EQU 004H ; Timer 1 Mode Select                               
TMOD_T1M__MODE0      EQU 000H ; Mode 0, 13-bit Counter/Timer                      
TMOD_T1M__MODE1      EQU 010H ; Mode 1, 16-bit Counter/Timer                      
TMOD_T1M__MODE2      EQU 020H ; Mode 2, 8-bit Counter/Timer with Auto-Reload      
TMOD_T1M__MODE3      EQU 030H ; Mode 3, Timer 1 Inactive                          
                                                                                  
TMOD_CT1__BMASK      EQU 040H ; Counter/Timer 1 Select                            
TMOD_CT1__SHIFT      EQU 006H ; Counter/Timer 1 Select                            
TMOD_CT1__TIMER      EQU 000H ; Timer Mode. Timer 1 increments on the clock       
                              ; defined by T1M in the CKCON0 register.            
TMOD_CT1__COUNTER    EQU 040H ; Counter Mode. Timer 1 increments on high-to-low   
                              ; transitions of an external pin (T1).              
                                                                                  
TMOD_GATE1__BMASK    EQU 080H ; Timer 1 Gate Control                              
TMOD_GATE1__SHIFT    EQU 007H ; Timer 1 Gate Control                              
TMOD_GATE1__DISABLED EQU 000H ; Timer 1 enabled when TR1 = 1 irrespective of INT1 
                              ; logic level.                                      
TMOD_GATE1__ENABLED  EQU 080H ; Timer 1 enabled only when TR1 = 1 and INT1 is     
                              ; active as defined by bit IN1PL in register IT01CF.
                                                                                  
;------------------------------------------------------------------------------
; SBCON1 Enums (UART1 Baud Rate Generator Control @ 0x94)
;------------------------------------------------------------------------------
SBCON1_BPS__FMASK     EQU 007H ; Baud Rate Prescaler Select                     
SBCON1_BPS__SHIFT     EQU 000H ; Baud Rate Prescaler Select                     
SBCON1_BPS__DIV_BY_12 EQU 000H ; Prescaler = 12.                                
SBCON1_BPS__DIV_BY_4  EQU 001H ; Prescaler = 4.                                 
SBCON1_BPS__DIV_BY_48 EQU 002H ; Prescaler = 48.                                
SBCON1_BPS__DIV_BY_1  EQU 003H ; Prescaler = 1.                                 
SBCON1_BPS__DIV_BY_8  EQU 004H ; Prescaler = 8.                                 
SBCON1_BPS__DIV_BY_16 EQU 005H ; Prescaler = 16.                                
SBCON1_BPS__DIV_BY_24 EQU 006H ; Prescaler = 24.                                
SBCON1_BPS__DIV_BY_32 EQU 007H ; Prescaler = 32.                                
                                                                                
SBCON1_BREN__BMASK    EQU 040H ; Baud Rate Generator Enable                     
SBCON1_BREN__SHIFT    EQU 006H ; Baud Rate Generator Enable                     
SBCON1_BREN__DISABLED EQU 000H ; Disable the baud rate generator. UART1 will not
                               ; function.                                      
SBCON1_BREN__ENABLED  EQU 040H ; Enable the baud rate generator.                
                                                                                
;------------------------------------------------------------------------------
; SBRLH1 Enums (UART1 Baud Rate Generator High Byte @ 0x96)
;------------------------------------------------------------------------------
SBRLH1_BRH__FMASK EQU 0FFH ; UART1 Baud Rate Reload High
SBRLH1_BRH__SHIFT EQU 000H ; UART1 Baud Rate Reload High
                                                        
;------------------------------------------------------------------------------
; SBRLL1 Enums (UART1 Baud Rate Generator Low Byte @ 0x95)
;------------------------------------------------------------------------------
SBRLL1_BRL__FMASK EQU 0FFH ; UART1 Baud Rate Reload Low
SBRLL1_BRL__SHIFT EQU 000H ; UART1 Baud Rate Reload Low
                                                       
;------------------------------------------------------------------------------
; SBUF1 Enums (UART1 Serial Port Data Buffer @ 0x99)
;------------------------------------------------------------------------------
SBUF1_SBUF1__FMASK EQU 0FFH ; Serial Port Data Buffer
SBUF1_SBUF1__SHIFT EQU 000H ; Serial Port Data Buffer
                                                     
;------------------------------------------------------------------------------
; SCON1 Enums (UART1 Serial Port Control @ 0x98)
;------------------------------------------------------------------------------
SCON1_RI__BMASK             EQU 001H ; Receive Interrupt Flag                           
SCON1_RI__SHIFT             EQU 000H ; Receive Interrupt Flag                           
SCON1_RI__NOT_SET           EQU 000H ; New data has not been received by UART1.         
SCON1_RI__SET               EQU 001H ; UART1 received one or more data bytes.           
                                                                                        
SCON1_TI__BMASK             EQU 002H ; Transmit Interrupt Flag                          
SCON1_TI__SHIFT             EQU 001H ; Transmit Interrupt Flag                          
SCON1_TI__NOT_SET           EQU 000H ; A byte of data has not been transmitted by UART1.
SCON1_TI__SET               EQU 002H ; UART1 transmitted a byte of data.                
                                                                                        
SCON1_RBX__BMASK            EQU 004H ; Extra Receive Bit                                
SCON1_RBX__SHIFT            EQU 002H ; Extra Receive Bit                                
SCON1_RBX__LOW              EQU 000H ; The extra bit or the first stop bit is 0.        
SCON1_RBX__HIGH             EQU 004H ; The extra bit or the first stop bit is 1.        
                                                                                        
SCON1_TBX__BMASK            EQU 008H ; Extra Transmission Bit                           
SCON1_TBX__SHIFT            EQU 003H ; Extra Transmission Bit                           
SCON1_TBX__LOW              EQU 000H ; Set extra bit to 0 (low).                        
SCON1_TBX__HIGH             EQU 008H ; Set extra bit to 1 (high).                       
                                                                                        
SCON1_REN__BMASK            EQU 010H ; Receive Enable                                   
SCON1_REN__SHIFT            EQU 004H ; Receive Enable                                   
SCON1_REN__RECEIVE_DISABLED EQU 000H ; UART1 reception disabled.                        
SCON1_REN__RECEIVE_ENABLED  EQU 010H ; UART1 reception enabled.                         
                                                                                        
SCON1_PERR__BMASK           EQU 040H ; Parity Error Flag                                
SCON1_PERR__SHIFT           EQU 006H ; Parity Error Flag                                
SCON1_PERR__NOT_SET         EQU 000H ; Parity error has not occurred.                   
SCON1_PERR__SET             EQU 040H ; Parity error has occurred.                       
                                                                                        
SCON1_OVR__BMASK            EQU 080H ; Receive FIFO Overrun Flag                        
SCON1_OVR__SHIFT            EQU 007H ; Receive FIFO Overrun Flag                        
SCON1_OVR__NOT_SET          EQU 000H ; Receive FIFO overrun has not occurred.           
SCON1_OVR__SET              EQU 080H ; Receive FIFO overrun has occurred.               
                                                                                        
;------------------------------------------------------------------------------
; SMOD1 Enums (UART1 Mode @ 0x93)
;------------------------------------------------------------------------------
SMOD1_SBL__BMASK          EQU 001H ; Stop Bit Length                                 
SMOD1_SBL__SHIFT          EQU 000H ; Stop Bit Length                                 
SMOD1_SBL__SHORT          EQU 000H ; Short: Stop bit is active for one bit time.     
SMOD1_SBL__LONG           EQU 001H ; Long: Stop bit is active for two bit times (data
                                   ; length = 6, 7, or 8 bits) or 1.5 bit times (data
                                   ; length = 5 bits).                               
                                                                                     
SMOD1_XBE__BMASK          EQU 002H ; Extra Bit Enable                                
SMOD1_XBE__SHIFT          EQU 001H ; Extra Bit Enable                                
SMOD1_XBE__DISABLED       EQU 000H ; Disable the extra bit.                          
SMOD1_XBE__ENABLED        EQU 002H ; Enable the extra bit.                           
                                                                                     
SMOD1_SDL__FMASK          EQU 00CH ; Data Length                                     
SMOD1_SDL__SHIFT          EQU 002H ; Data Length                                     
SMOD1_SDL__5_BITS         EQU 000H ; 5 bits.                                         
SMOD1_SDL__6_BITS         EQU 004H ; 6 bits.                                         
SMOD1_SDL__7_BITS         EQU 008H ; 7 bits.                                         
SMOD1_SDL__8_BITS         EQU 00CH ; 8 bits.                                         
                                                                                     
SMOD1_PE__BMASK           EQU 010H ; Parity Enable                                   
SMOD1_PE__SHIFT           EQU 004H ; Parity Enable                                   
SMOD1_PE__PARITY_DISABLED EQU 000H ; Disable hardware parity.                        
SMOD1_PE__PARITY_ENABLED  EQU 010H ; Enable hardware parity.                         
                                                                                     
SMOD1_SPT__FMASK          EQU 060H ; Parity Type                                     
SMOD1_SPT__SHIFT          EQU 005H ; Parity Type                                     
SMOD1_SPT__ODD_PARITY     EQU 000H ; Odd.                                            
SMOD1_SPT__EVEN_PARITY    EQU 020H ; Even.                                           
SMOD1_SPT__MARK_PARITY    EQU 040H ; Mark.                                           
SMOD1_SPT__SPACE_PARITY   EQU 060H ; Space.                                          
                                                                                     
SMOD1_MCE__BMASK          EQU 080H ; Multiprocessor Communication Enable             
SMOD1_MCE__SHIFT          EQU 007H ; Multiprocessor Communication Enable             
SMOD1_MCE__MULTI_DISABLED EQU 000H ; RI will be activated if the stop bits are 1.    
SMOD1_MCE__MULTI_ENABLED  EQU 080H ; RI will be activated if the stop bits and extra 
                                   ; bit are 1. The extra bit must be enabled using  
                                   ; XBE.                                            
                                                                                     
;------------------------------------------------------------------------------
; UART1FCN0 Enums (UART1 FIFO Control 0 @ 0x9D)
;------------------------------------------------------------------------------
UART1FCN0_RXTH__FMASK     EQU 003H ; RX FIFO Threshold                                 
UART1FCN0_RXTH__SHIFT     EQU 000H ; RX FIFO Threshold                                 
UART1FCN0_RXTH__ZERO      EQU 000H ; RFRQ will be set anytime new data arrives in the  
                                   ; RX FIFO (when the RX FIFO is not empty).          
UART1FCN0_RXTH__ONE       EQU 001H ; RFRQ will be set if the RX FIFO contains more than
                                   ; one byte.                                         
UART1FCN0_RXTH__TWO       EQU 002H ; RFRQ will be set if the RX FIFO contains more than
                                   ; two bytes.                                        
UART1FCN0_RXTH__THREE     EQU 003H ; RFRQ will be set if the RX FIFO contains more than
                                   ; three bytes.                                      
                                                                                       
UART1FCN0_RFLSH__BMASK    EQU 004H ; RX FIFO Flush                                     
UART1FCN0_RFLSH__SHIFT    EQU 002H ; RX FIFO Flush                                     
UART1FCN0_RFLSH__FLUSH    EQU 004H ; Initiate an RX FIFO flush.                        
                                                                                       
UART1FCN0_RFRQE__BMASK    EQU 008H ; Read Request Interrupt Enable                     
UART1FCN0_RFRQE__SHIFT    EQU 003H ; Read Request Interrupt Enable                     
UART1FCN0_RFRQE__DISABLED EQU 000H ; UART1 interrupts will not be generated when RFRQ  
                                   ; is set.                                           
UART1FCN0_RFRQE__ENABLED  EQU 008H ; UART1 interrupts will be generated if RFRQ is set.
                                                                                       
UART1FCN0_TXTH__FMASK     EQU 030H ; TX FIFO Threshold                                 
UART1FCN0_TXTH__SHIFT     EQU 004H ; TX FIFO Threshold                                 
UART1FCN0_TXTH__ZERO      EQU 000H ; TFRQ will be set when the TX FIFO is empty.       
UART1FCN0_TXTH__ONE       EQU 010H ; TFRQ will be set when the TX FIFO contains one or 
                                   ; fewer bytes.                                      
UART1FCN0_TXTH__TWO       EQU 020H ; TFRQ will be set when the TX FIFO contains two or 
                                   ; fewer bytes.                                      
UART1FCN0_TXTH__THREE     EQU 030H ; TFRQ will be set when the TX FIFO contains three  
                                   ; or fewer bytes.                                   
                                                                                       
UART1FCN0_TFLSH__BMASK    EQU 040H ; TX FIFO Flush                                     
UART1FCN0_TFLSH__SHIFT    EQU 006H ; TX FIFO Flush                                     
UART1FCN0_TFLSH__FLUSH    EQU 040H ; Initiate a TX FIFO flush.                         
                                                                                       
UART1FCN0_TFRQE__BMASK    EQU 080H ; Write Request Interrupt Enable                    
UART1FCN0_TFRQE__SHIFT    EQU 007H ; Write Request Interrupt Enable                    
UART1FCN0_TFRQE__DISABLED EQU 000H ; UART1 interrupts will not be generated when TFRQ  
                                   ; is set.                                           
UART1FCN0_TFRQE__ENABLED  EQU 080H ; UART1 interrupts will be generated if TFRQ is set.
                                                                                       
;------------------------------------------------------------------------------
; UART1FCN1 Enums (UART1 FIFO Control 1 @ 0xD8)
;------------------------------------------------------------------------------
UART1FCN1_RIE__BMASK       EQU 001H ; Receive Interrupt Enable                          
UART1FCN1_RIE__SHIFT       EQU 000H ; Receive Interrupt Enable                          
UART1FCN1_RIE__DISABLED    EQU 000H ; The RI flag will not generate UART1 interrupts.   
UART1FCN1_RIE__ENABLED     EQU 001H ; The RI flag will generate UART1 interrupts when it
                                    ; is set.                                           
                                                                                        
UART1FCN1_RXTO__FMASK      EQU 006H ; Receive Timeout                                   
UART1FCN1_RXTO__SHIFT      EQU 001H ; Receive Timeout                                   
UART1FCN1_RXTO__DISABLED   EQU 000H ; The receive timeout feature is disabled.          
UART1FCN1_RXTO__TIMEOUT_2  EQU 002H ; A receive timeout will occur after 2 idle periods 
                                    ; on the UART RX line.                              
UART1FCN1_RXTO__TIMEOUT_4  EQU 004H ; A receive timeout will occur after 4 idle periods 
                                    ; on the UART RX line.                              
UART1FCN1_RXTO__TIMEOUT_16 EQU 006H ; A receive timeout will occur after 16 idle periods
                                    ; on the UART RX line.                              
                                                                                        
UART1FCN1_RFRQ__BMASK      EQU 008H ; Receive FIFO Request                              
UART1FCN1_RFRQ__SHIFT      EQU 003H ; Receive FIFO Request                              
UART1FCN1_RFRQ__NOT_SET    EQU 000H ; The number of bytes in the RX FIFO is less than or
                                    ; equal to RXTH.                                    
UART1FCN1_RFRQ__SET        EQU 008H ; The number of bytes in the RX FIFO is greater than
                                    ; RXTH.                                             
                                                                                        
UART1FCN1_TIE__BMASK       EQU 010H ; Transmit Interrupt Enable                         
UART1FCN1_TIE__SHIFT       EQU 004H ; Transmit Interrupt Enable                         
UART1FCN1_TIE__DISABLED    EQU 000H ; The TI flag will not generate UART1 interrupts.   
UART1FCN1_TIE__ENABLED     EQU 010H ; The TI flag will generate UART1 interrupts when it
                                    ; is set.                                           
                                                                                        
UART1FCN1_TXHOLD__BMASK    EQU 020H ; Transmit Hold                                     
UART1FCN1_TXHOLD__SHIFT    EQU 005H ; Transmit Hold                                     
UART1FCN1_TXHOLD__CONTINUE EQU 000H ; The UART will continue to transmit any available  
                                    ; data in the TX FIFO.                              
UART1FCN1_TXHOLD__HOLD     EQU 020H ; The UART will not transmit any new data from the  
                                    ; TX FIFO.                                          
                                                                                        
UART1FCN1_TXNF__BMASK      EQU 040H ; TX FIFO Not Full                                  
UART1FCN1_TXNF__SHIFT      EQU 006H ; TX FIFO Not Full                                  
UART1FCN1_TXNF__FULL       EQU 000H ; The TX FIFO is full.                              
UART1FCN1_TXNF__NOT_FULL   EQU 040H ; The TX FIFO has room for more data.               
                                                                                        
UART1FCN1_TFRQ__BMASK      EQU 080H ; Transmit FIFO Request                             
UART1FCN1_TFRQ__SHIFT      EQU 007H ; Transmit FIFO Request                             
UART1FCN1_TFRQ__NOT_SET    EQU 000H ; The number of bytes in the TX FIFO is greater than
                                    ; TXTH.                                             
UART1FCN1_TFRQ__SET        EQU 080H ; The number of bytes in the TX FIFO is less than or
                                    ; equal to TXTH.                                    
                                                                                        
;------------------------------------------------------------------------------
; UART1FCT Enums (UART1 FIFO Count @ 0xFA)
;------------------------------------------------------------------------------
UART1FCT_RXCNT__FMASK EQU 003H ; RX FIFO Count
UART1FCT_RXCNT__SHIFT EQU 000H ; RX FIFO Count
                                              
UART1FCT_TXCNT__FMASK EQU 030H ; TX FIFO Count
UART1FCT_TXCNT__SHIFT EQU 004H ; TX FIFO Count
                                              
;------------------------------------------------------------------------------
; UART1LIN Enums (UART1 LIN Configuration @ 0x9E)
;------------------------------------------------------------------------------
UART1LIN_SYNCDIE__BMASK      EQU 001H ; LIN Sync Detect Interrupt Enable                  
UART1LIN_SYNCDIE__SHIFT      EQU 000H ; LIN Sync Detect Interrupt Enable                  
UART1LIN_SYNCDIE__DISABLED   EQU 000H ; The SYNCD flag will not generate UART1 interrupts.
UART1LIN_SYNCDIE__ENABLED    EQU 001H ; The SYNCD flag will generate UART1 interrupts when
                                      ; it is set.                                        
                                                                                          
UART1LIN_SYNCTOIE__BMASK     EQU 002H ; LIN Sync Detect Timeout Interrupt Enable          
UART1LIN_SYNCTOIE__SHIFT     EQU 001H ; LIN Sync Detect Timeout Interrupt Enable          
UART1LIN_SYNCTOIE__DISABLED  EQU 000H ; The SYNCTO flag will not generate UART1           
                                      ; interrupts.                                       
UART1LIN_SYNCTOIE__ENABLED   EQU 002H ; The SYNCTO flag will generate UART1 interrupts    
                                      ; when it is set.                                   
                                                                                          
UART1LIN_BREAKDNIE__BMASK    EQU 004H ; LIN Break Done Interrupt Enable                   
UART1LIN_BREAKDNIE__SHIFT    EQU 002H ; LIN Break Done Interrupt Enable                   
UART1LIN_BREAKDNIE__DISABLED EQU 000H ; The BREAKDN flag will not generate UART1          
                                      ; interrupts.                                       
UART1LIN_BREAKDNIE__ENABLED  EQU 004H ; The BREAKDN flag will generate UART1 interrupts   
                                      ; when it is set.                                   
                                                                                          
UART1LIN_LINMDE__BMASK       EQU 008H ; LIN Mode Enable                                   
UART1LIN_LINMDE__SHIFT       EQU 003H ; LIN Mode Enable                                   
UART1LIN_LINMDE__DISABLED    EQU 000H ; If AUTOBDE is set to 1, sync detection and        
                                      ; autobaud will begin on the first falling edge of  
                                      ; RX.                                               
UART1LIN_LINMDE__ENABLED     EQU 008H ; A valid LIN break field and delimiter must be     
                                      ; detected prior to the hardware state machine      
                                      ; recognizing a sync word and performing autobaud.  
                                                                                          
UART1LIN_SYNCD__BMASK        EQU 010H ; LIN Sync Detect Flag                              
UART1LIN_SYNCD__SHIFT        EQU 004H ; LIN Sync Detect Flag                              
UART1LIN_SYNCD__NOT_SET      EQU 000H ; A sync has not been detected or is not yet        
                                      ; complete.                                         
UART1LIN_SYNCD__SYNC_DONE    EQU 010H ; A valid sync word was detected.                   
                                                                                          
UART1LIN_SYNCTO__BMASK       EQU 020H ; LIN Sync Timeout Flag                             
UART1LIN_SYNCTO__SHIFT       EQU 005H ; LIN Sync Timeout Flag                             
UART1LIN_SYNCTO__NOT_SET     EQU 000H ; A sync timeout has not occured.                   
UART1LIN_SYNCTO__TIMEOUT     EQU 020H ; A sync timeout occured.                           
                                                                                          
UART1LIN_BREAKDN__BMASK      EQU 040H ; LIN Break Done Flag                               
UART1LIN_BREAKDN__SHIFT      EQU 006H ; LIN Break Done Flag                               
UART1LIN_BREAKDN__NOT_SET    EQU 000H ; A LIN break has not been detected.                
UART1LIN_BREAKDN__BREAK      EQU 040H ; A LIN break was detected since the flag was last  
                                      ; cleared.                                          
                                                                                          
UART1LIN_AUTOBDE__BMASK      EQU 080H ; Auto Baud Detection Enable                        
UART1LIN_AUTOBDE__SHIFT      EQU 007H ; Auto Baud Detection Enable                        
UART1LIN_AUTOBDE__DISABLED   EQU 000H ; Autobaud is not enabled.                          
UART1LIN_AUTOBDE__ENABLED    EQU 080H ; Autobaud is enabled.                              
                                                                                          
;------------------------------------------------------------------------------
; UART1PCF Enums (UART1 Configuration @ 0xDA)
;------------------------------------------------------------------------------
UART1PCF_RXSEL__FMASK    EQU 003H ; RX Source Select                        
UART1PCF_RXSEL__SHIFT    EQU 000H ; RX Source Select                        
UART1PCF_RXSEL__CROSSBAR EQU 000H ; The crossbar input is UART1 RX.         
UART1PCF_RXSEL__CLU0     EQU 001H ; The CLU0 synchronous output is UART1 RX.
UART1PCF_RXSEL__CLU1     EQU 002H ; The CLU1 synchronous output is UART1 RX.
UART1PCF_RXSEL__CLU2     EQU 003H ; The CLU2 synchronous output is UART1 RX.
                                                                            
;------------------------------------------------------------------------------
; CLKREC Enums (USB0 Clock Recovery Control @ 0x0F)
;------------------------------------------------------------------------------
CLKREC_CRLOW__BMASK      EQU 020H ; Low Speed Clock Recovery Mode               
CLKREC_CRLOW__SHIFT      EQU 005H ; Low Speed Clock Recovery Mode               
CLKREC_CRLOW__FULL_SPEED EQU 000H ; Full Speed Mode.                            
CLKREC_CRLOW__LOW_SPEED  EQU 020H ; Low Speed Mode.                             
                                                                                
CLKREC_CRSSEN__BMASK     EQU 040H ; Clock Recovery Single Step                  
CLKREC_CRSSEN__SHIFT     EQU 006H ; Clock Recovery Single Step                  
CLKREC_CRSSEN__DISABLED  EQU 000H ; Disable single-step mode (normal calibration
                                  ; mode).                                      
CLKREC_CRSSEN__ENABLED   EQU 040H ; Enable single-step mode.                    
                                                                                
CLKREC_CRE__BMASK        EQU 080H ; Clock Recovery Enable                       
CLKREC_CRE__SHIFT        EQU 007H ; Clock Recovery Enable                       
CLKREC_CRE__DISABLED     EQU 000H ; Disable clock recovery.                     
CLKREC_CRE__ENABLED      EQU 080H ; Enable clock recovery.                      
                                                                                
;------------------------------------------------------------------------------
; CMIE Enums (USB0 Common Interrupt Enable @ 0x0B)
;------------------------------------------------------------------------------
CMIE_SUSINTE__BMASK    EQU 001H ; Suspend Interrupt Enable       
CMIE_SUSINTE__SHIFT    EQU 000H ; Suspend Interrupt Enable       
CMIE_SUSINTE__DISABLED EQU 000H ; Disable suspend interrupts.    
CMIE_SUSINTE__ENABLED  EQU 001H ; Enable suspend interrupts.     
                                                                 
CMIE_RSUINTE__BMASK    EQU 002H ; Resume Interrupt Enable        
CMIE_RSUINTE__SHIFT    EQU 001H ; Resume Interrupt Enable        
CMIE_RSUINTE__DISABLED EQU 000H ; Disable resume interrupts.     
CMIE_RSUINTE__ENABLED  EQU 002H ; Enable resume interrupts.      
                                                                 
CMIE_RSTINTE__BMASK    EQU 004H ; Reset Interrupt Enable         
CMIE_RSTINTE__SHIFT    EQU 002H ; Reset Interrupt Enable         
CMIE_RSTINTE__DISABLED EQU 000H ; Disable reset interrupts.      
CMIE_RSTINTE__ENABLED  EQU 004H ; Enable reset interrupts.       
                                                                 
CMIE_SOFE__BMASK       EQU 008H ; Start of Frame Interrupt Enable
CMIE_SOFE__SHIFT       EQU 003H ; Start of Frame Interrupt Enable
CMIE_SOFE__DISABLED    EQU 000H ; Disable SOF interrupts.        
CMIE_SOFE__ENABLED     EQU 008H ; Enable SOF interrupts.         
                                                                 
;------------------------------------------------------------------------------
; CMINT Enums (USB0 Common Interrupt @ 0x06)
;------------------------------------------------------------------------------
CMINT_SUSINT__BMASK   EQU 001H ; Suspend Interrupt Flag       
CMINT_SUSINT__SHIFT   EQU 000H ; Suspend Interrupt Flag       
CMINT_SUSINT__NOT_SET EQU 000H ; Suspend interrupt inactive.  
CMINT_SUSINT__SET     EQU 001H ; Suspend interrupt active.    
                                                              
CMINT_RSUINT__BMASK   EQU 002H ; Resume Interrupt Flag        
CMINT_RSUINT__SHIFT   EQU 001H ; Resume Interrupt Flag        
CMINT_RSUINT__NOT_SET EQU 000H ; Resume interrupt inactive.   
CMINT_RSUINT__SET     EQU 002H ; Resume interrupt active.     
                                                              
CMINT_RSTINT__BMASK   EQU 004H ; Reset Interrupt Flag         
CMINT_RSTINT__SHIFT   EQU 002H ; Reset Interrupt Flag         
CMINT_RSTINT__NOT_SET EQU 000H ; Reset interrupt inactive.    
CMINT_RSTINT__SET     EQU 004H ; Reset interrupt active.      
                                                              
CMINT_SOF__BMASK      EQU 008H ; Start of Frame Interrupt Flag
CMINT_SOF__SHIFT      EQU 003H ; Start of Frame Interrupt Flag
CMINT_SOF__NOT_SET    EQU 000H ; SOF interrupt inactive.      
CMINT_SOF__SET        EQU 008H ; SOF interrupt active.        
                                                              
;------------------------------------------------------------------------------
; E0CNT Enums (USB0 Endpoint0 Data Count @ 0x16)
;------------------------------------------------------------------------------
E0CNT_E0CNT__FMASK EQU 07FH ; Endpoint 0 Data Count
E0CNT_E0CNT__SHIFT EQU 000H ; Endpoint 0 Data Count
                                                   
;------------------------------------------------------------------------------
; E0CSR Enums (USB0 Endpoint0 Control @ 0x11)
;------------------------------------------------------------------------------
E0CSR_OPRDY__BMASK     EQU 001H ; OUT Packet Ready                                  
E0CSR_OPRDY__SHIFT     EQU 000H ; OUT Packet Ready                                  
E0CSR_OPRDY__NOT_SET   EQU 000H ; A data packet has not been received.              
E0CSR_OPRDY__SET       EQU 001H ; A data packet has been received.                  
                                                                                    
E0CSR_INPRDY__BMASK    EQU 002H ; IN Packet Ready                                   
E0CSR_INPRDY__SHIFT    EQU 001H ; IN Packet Ready                                   
E0CSR_INPRDY__NOT_SET  EQU 000H ; An IN packet is not ready to transmit.            
E0CSR_INPRDY__SET      EQU 002H ; An IN packet is ready to transmit.                
                                                                                    
E0CSR_STSTL__BMASK     EQU 004H ; Sent Stall                                        
E0CSR_STSTL__SHIFT     EQU 002H ; Sent Stall                                        
E0CSR_STSTL__NOT_SET   EQU 000H ; A STALL handshake signal was not transmitted.     
E0CSR_STSTL__SET       EQU 004H ; A STALL handshake signal was transmitted.         
                                                                                    
E0CSR_DATAEND__BMASK   EQU 008H ; Data End                                          
E0CSR_DATAEND__SHIFT   EQU 003H ; Data End                                          
E0CSR_DATAEND__NOT_SET EQU 000H ; This is not the last data packet.                 
E0CSR_DATAEND__SET     EQU 008H ; This is the last data packet.                     
                                                                                    
E0CSR_SUEND__BMASK     EQU 010H ; Setup End                                         
E0CSR_SUEND__SHIFT     EQU 004H ; Setup End                                         
E0CSR_SUEND__NOT_SET   EQU 000H ; A control transaction did not end before firmware 
                                ; wrote a 1 to the DATAEND bit.                     
E0CSR_SUEND__SET       EQU 010H ; A control transaction ended before firmware wrote 
                                ; a 1 to the DATAEND bit.                           
                                                                                    
E0CSR_SDSTL__BMASK     EQU 020H ; Send Stall                                        
E0CSR_SDSTL__SHIFT     EQU 005H ; Send Stall                                        
E0CSR_SDSTL__NOT_SET   EQU 000H ; Do not send a STALL.                              
E0CSR_SDSTL__SET       EQU 020H ; Send a STALL.                                     
                                                                                    
E0CSR_SOPRDY__BMASK    EQU 040H ; Serviced OPRDY                                    
E0CSR_SOPRDY__SHIFT    EQU 006H ; Serviced OPRDY                                    
E0CSR_SOPRDY__NOT_SET  EQU 000H ; OUT packet has not been serviced.                 
E0CSR_SOPRDY__SET      EQU 040H ; OUT packet has been serviced.                     
                                                                                    
E0CSR_SSUEND__BMASK    EQU 080H ; Serviced Setup End                                
E0CSR_SSUEND__SHIFT    EQU 007H ; Serviced Setup End                                
E0CSR_SSUEND__NOT_SET  EQU 000H ; The setup end (SUEND) event has not been serviced.
E0CSR_SSUEND__SET      EQU 080H ; The setup end (SUEND) event has been serviced.    
                                                                                    
;------------------------------------------------------------------------------
; EENABLE Enums (USB0 Endpoint Enable @ 0x1E)
;------------------------------------------------------------------------------
EENABLE_EEN1__BMASK    EQU 002H ; Endpoint 1 Enable                                
EENABLE_EEN1__SHIFT    EQU 001H ; Endpoint 1 Enable                                
EENABLE_EEN1__DISABLED EQU 000H ; Disable Endpoint 1 (no NACK, ACK, or STALL on the
                                ; USB network).                                    
EENABLE_EEN1__ENABLED  EQU 002H ; Enable Endpoint 1 (normal).                      
                                                                                   
EENABLE_EEN2__BMASK    EQU 004H ; Endpoint 2 Enable                                
EENABLE_EEN2__SHIFT    EQU 002H ; Endpoint 2 Enable                                
EENABLE_EEN2__DISABLED EQU 000H ; Disable Endpoint 2 (no NACK, ACK, or STALL on the
                                ; USB network).                                    
EENABLE_EEN2__ENABLED  EQU 004H ; Enable Endpoint 2 (normal).                      
                                                                                   
EENABLE_EEN3__BMASK    EQU 008H ; Endpoint 3 Enable                                
EENABLE_EEN3__SHIFT    EQU 003H ; Endpoint 3 Enable                                
EENABLE_EEN3__DISABLED EQU 000H ; Disable Endpoint 3 (no NACK, ACK, or STALL on the
                                ; USB network).                                    
EENABLE_EEN3__ENABLED  EQU 008H ; Enable Endpoint 3 (normal).                      
                                                                                   
;------------------------------------------------------------------------------
; EINCSRH Enums (USB0 IN Endpoint Control High @ 0x12)
;------------------------------------------------------------------------------
EINCSRH_SPLIT__BMASK        EQU 004H ; FIFO Split Enable                                
EINCSRH_SPLIT__SHIFT        EQU 002H ; FIFO Split Enable                                
EINCSRH_SPLIT__DISABLED     EQU 000H ; Disable split mode.                              
EINCSRH_SPLIT__ENABLED      EQU 004H ; Enable split mode.                               
                                                                                        
EINCSRH_FCDT__BMASK         EQU 008H ; Force Data Toggle                                
EINCSRH_FCDT__SHIFT         EQU 003H ; Force Data Toggle                                
EINCSRH_FCDT__ACK_TOGGLE    EQU 000H ; Endpoint data toggle switches only when an ACK is
                                     ; received following a data packet transmission.   
EINCSRH_FCDT__ALWAYS_TOGGLE EQU 008H ; Endpoint data toggle forced to switch after every
                                     ; data packet is transmitted, regardless of ACK    
                                     ; reception.                                       
                                                                                        
EINCSRH_DIRSEL__BMASK       EQU 020H ; Endpoint Direction Select                        
EINCSRH_DIRSEL__SHIFT       EQU 005H ; Endpoint Direction Select                        
EINCSRH_DIRSEL__OUT         EQU 000H ; Endpoint direction selected as OUT.              
EINCSRH_DIRSEL__IN          EQU 020H ; Endpoint direction selected as IN.               
                                                                                        
EINCSRH_ISO__BMASK          EQU 040H ; Isochronous Transfer Enable                      
EINCSRH_ISO__SHIFT          EQU 006H ; Isochronous Transfer Enable                      
EINCSRH_ISO__DISABLED       EQU 000H ; Endpoint configured for Bulk/Interrupt transfers.
EINCSRH_ISO__ENABLED        EQU 040H ; Endpoint configured for Isochronous transfers.   
                                                                                        
EINCSRH_DBIEN__BMASK        EQU 080H ; IN Endpoint Double-Buffer Enable                 
EINCSRH_DBIEN__SHIFT        EQU 007H ; IN Endpoint Double-Buffer Enable                 
EINCSRH_DBIEN__DISABLED     EQU 000H ; Disable double-buffering for the selected IN     
                                     ; endpoint.                                        
EINCSRH_DBIEN__ENABLED      EQU 080H ; Enable double-buffering for the selected IN      
                                     ; endpoint.                                        
                                                                                        
;------------------------------------------------------------------------------
; EINCSRL Enums (USB0 IN Endpoint Control Low @ 0x11)
;------------------------------------------------------------------------------
EINCSRL_INPRDY__BMASK     EQU 001H ; In Packet Ready                                   
EINCSRL_INPRDY__SHIFT     EQU 000H ; In Packet Ready                                   
EINCSRL_INPRDY__NOT_SET   EQU 000H ; A packet is not available in the Endpoint IN FIFO.
EINCSRL_INPRDY__SET       EQU 001H ; A packet is available in the Endpoint IN FIFO.    
                                                                                       
EINCSRL_FIFONE__BMASK     EQU 002H ; FIFO Not Empty                                    
EINCSRL_FIFONE__SHIFT     EQU 001H ; FIFO Not Empty                                    
EINCSRL_FIFONE__EMPTY     EQU 000H ; The IN Endpoint FIFO is empty.                    
EINCSRL_FIFONE__NOT_EMPTY EQU 002H ; The IN Endpoint FIFO contains one or more packets.
                                                                                       
EINCSRL_UNDRUN__BMASK     EQU 004H ; Data Underrun Flag                                
EINCSRL_UNDRUN__SHIFT     EQU 002H ; Data Underrun Flag                                
EINCSRL_UNDRUN__NOT_SET   EQU 000H ; A data underrun did not occur.                    
EINCSRL_UNDRUN__SET       EQU 004H ; A data underrun occurred.                         
                                                                                       
EINCSRL_FLUSH__BMASK      EQU 008H ; FIFO Flush                                        
EINCSRL_FLUSH__SHIFT      EQU 003H ; FIFO Flush                                        
EINCSRL_FLUSH__NOT_SET    EQU 000H ; Do not flush the next packet.                     
EINCSRL_FLUSH__SET        EQU 008H ; Flush the next packet to be transmitted from the  
                                   ; IN Endpoint FIFO.                                 
                                                                                       
EINCSRL_SDSTL__BMASK      EQU 010H ; Send Stall                                        
EINCSRL_SDSTL__SHIFT      EQU 004H ; Send Stall                                        
EINCSRL_SDSTL__NOT_SET    EQU 000H ; Terminate the STALL.                              
EINCSRL_SDSTL__SET        EQU 010H ; Generate a STALL in response to an IN token.      
                                                                                       
EINCSRL_STSTL__BMASK      EQU 020H ; Sent Stall Flag                                   
EINCSRL_STSTL__SHIFT      EQU 005H ; Sent Stall Flag                                   
EINCSRL_STSTL__NOT_SET    EQU 000H ; A STALL handshake was not transmitted.            
EINCSRL_STSTL__SET        EQU 020H ; A STALL handshake was transmitted.                
                                                                                       
EINCSRL_CLRDT__BMASK      EQU 040H ; Clear Data Toggle                                 
EINCSRL_CLRDT__SHIFT      EQU 006H ; Clear Data Toggle                                 
EINCSRL_CLRDT__CLEAR      EQU 000H ; Clear the IN Endpoint data toggle.                
                                                                                       
;------------------------------------------------------------------------------
; EOUTCNTH Enums (USB0 OUT Endpoint Count High @ 0x17)
;------------------------------------------------------------------------------
EOUTCNTH_EOCH__FMASK EQU 003H ; OUT Endpoint Count High
EOUTCNTH_EOCH__SHIFT EQU 000H ; OUT Endpoint Count High
                                                       
;------------------------------------------------------------------------------
; EOUTCNTL Enums (USB0 OUT Endpoint Count Low @ 0x16)
;------------------------------------------------------------------------------
EOUTCNTL_EOCL__FMASK EQU 0FFH ; OUT Endpoint Count Low
EOUTCNTL_EOCL__SHIFT EQU 000H ; OUT Endpoint Count Low
                                                      
;------------------------------------------------------------------------------
; EOUTCSRH Enums (USB0 OUT Endpoint Control High @ 0x15)
;------------------------------------------------------------------------------
EOUTCSRH_ISO__BMASK      EQU 040H ; Isochronous Transfer Enable                      
EOUTCSRH_ISO__SHIFT      EQU 006H ; Isochronous Transfer Enable                      
EOUTCSRH_ISO__DISABLED   EQU 000H ; Endpoint configured for Bulk/Interrupt transfers.
EOUTCSRH_ISO__ENABLED    EQU 040H ; Endpoint configured for Isochronous transfers.   
                                                                                     
EOUTCSRH_DBOEN__BMASK    EQU 080H ; Double-Buffer Enable                             
EOUTCSRH_DBOEN__SHIFT    EQU 007H ; Double-Buffer Enable                             
EOUTCSRH_DBOEN__DISABLED EQU 000H ; Disable double-buffering for the selected OUT    
                                  ; endpoint.                                        
EOUTCSRH_DBOEN__ENABLED  EQU 080H ; Enable double-buffering for the selected OUT     
                                  ; endpoint.                                        
                                                                                     
;------------------------------------------------------------------------------
; EOUTCSRL Enums (USB0 OUT Endpoint Control Low @ 0x14)
;------------------------------------------------------------------------------
EOUTCSRL_OPRDY__BMASK      EQU 001H ; OUT Packet Ready                                  
EOUTCSRL_OPRDY__SHIFT      EQU 000H ; OUT Packet Ready                                  
EOUTCSRL_OPRDY__NOT_SET    EQU 000H ; A data packet is not available in the Endpoint OUT
                                    ; FIFO.                                             
EOUTCSRL_OPRDY__SET        EQU 001H ; A data packet is available in the Endpoint OUT    
                                    ; FIFO.                                             
                                                                                        
EOUTCSRL_FIFOFUL__BMASK    EQU 002H ; OUT FIFO Full                                     
EOUTCSRL_FIFOFUL__SHIFT    EQU 001H ; OUT FIFO Full                                     
EOUTCSRL_FIFOFUL__NOT_FULL EQU 000H ; OUT endpoint FIFO is not full.                    
EOUTCSRL_FIFOFUL__FULL     EQU 002H ; OUT endpoint FIFO is full.                        
                                                                                        
EOUTCSRL_OVRUN__BMASK      EQU 004H ; Data Overrun Flag                                 
EOUTCSRL_OVRUN__SHIFT      EQU 002H ; Data Overrun Flag                                 
EOUTCSRL_OVRUN__NOT_SET    EQU 000H ; No data overrun.                                  
EOUTCSRL_OVRUN__SET        EQU 004H ; A data packet was lost because of a full FIFO     
                                    ; since this flag was last cleared.                 
                                                                                        
EOUTCSRL_DATERR__BMASK     EQU 008H ; Data Error Flag                                   
EOUTCSRL_DATERR__SHIFT     EQU 003H ; Data Error Flag                                   
EOUTCSRL_DATERR__NOT_SET   EQU 000H ; A received packet does not have a CRC or bit-     
                                    ; stuffing error.                                   
EOUTCSRL_DATERR__SET       EQU 008H ; A received packet has a CRC or bit-stuffing error.
                                                                                        
EOUTCSRL_FLUSH__BMASK      EQU 010H ; FIFO Flush                                        
EOUTCSRL_FLUSH__SHIFT      EQU 004H ; FIFO Flush                                        
EOUTCSRL_FLUSH__NOT_SET    EQU 000H ; Do not flush the next packet.                     
EOUTCSRL_FLUSH__SET        EQU 010H ; Flush the next packet to be read from the OUT     
                                    ; endpoint FIFO.                                    
                                                                                        
EOUTCSRL_SDSTL__BMASK      EQU 020H ; Send Stall                                        
EOUTCSRL_SDSTL__SHIFT      EQU 005H ; Send Stall                                        
EOUTCSRL_SDSTL__NOT_SET    EQU 000H ; Terminate the STALL.                              
EOUTCSRL_SDSTL__SET        EQU 020H ; Generate a STALL handshake.                       
                                                                                        
EOUTCSRL_STSTL__BMASK      EQU 040H ; Sent Stall Flag                                   
EOUTCSRL_STSTL__SHIFT      EQU 006H ; Sent Stall Flag                                   
EOUTCSRL_STSTL__NOT_SET    EQU 000H ; A STALL handshake was not transmitted.            
EOUTCSRL_STSTL__SET        EQU 040H ; A STALL handshake was transmitted.                
                                                                                        
EOUTCSRL_CLRDT__BMASK      EQU 080H ; Clear Data Toggle                                 
EOUTCSRL_CLRDT__SHIFT      EQU 007H ; Clear Data Toggle                                 
EOUTCSRL_CLRDT__CLEAR      EQU 000H ; Clear the OUT Endpoint data toggle.               
                                                                                        
;------------------------------------------------------------------------------
; FADDR Enums (USB0 Function Address @ 0x00)
;------------------------------------------------------------------------------
FADDR_FADDR__FMASK    EQU 07FH ; Function Address                               
FADDR_FADDR__SHIFT    EQU 000H ; Function Address                               
                                                                                
FADDR_UPDATE__BMASK   EQU 080H ; Function Address Update                        
FADDR_UPDATE__SHIFT   EQU 007H ; Function Address Update                        
FADDR_UPDATE__NOT_SET EQU 000H ; The last address written to FADDR is in effect.
FADDR_UPDATE__SET     EQU 080H ; The last address written to FADDR is not yet in
                               ; effect.                                        
                                                                                
;------------------------------------------------------------------------------
; FIFO0 Enums (USB0 Endpoint 0 FIFO Access @ 0x20)
;------------------------------------------------------------------------------
FIFO0_FIFODATA__FMASK EQU 0FFH ; Endpoint 0 FIFO Access
FIFO0_FIFODATA__SHIFT EQU 000H ; Endpoint 0 FIFO Access
                                                       
;------------------------------------------------------------------------------
; FIFO1 Enums (USB0 Endpoint 1 FIFO Access @ 0x21)
;------------------------------------------------------------------------------
FIFO1_FIFODATA__FMASK EQU 0FFH ; Endpoint 1 FIFO Access
FIFO1_FIFODATA__SHIFT EQU 000H ; Endpoint 1 FIFO Access
                                                       
;------------------------------------------------------------------------------
; FIFO2 Enums (USB0 Endpoint 2 FIFO Access @ 0x22)
;------------------------------------------------------------------------------
FIFO2_FIFODATA__FMASK EQU 0FFH ; Endpoint 2 FIFO Access
FIFO2_FIFODATA__SHIFT EQU 000H ; Endpoint 2 FIFO Access
                                                       
;------------------------------------------------------------------------------
; FIFO3 Enums (USB0 Endpoint 3 FIFO Access @ 0x23)
;------------------------------------------------------------------------------
FIFO3_FIFODATA__FMASK EQU 0FFH ; Endpoint 3 FIFO Access
FIFO3_FIFODATA__SHIFT EQU 000H ; Endpoint 3 FIFO Access
                                                       
;------------------------------------------------------------------------------
; FRAMEH Enums (USB0 Frame Number High @ 0x0D)
;------------------------------------------------------------------------------
FRAMEH_FRMEH__FMASK EQU 007H ; Frame Number High
FRAMEH_FRMEH__SHIFT EQU 000H ; Frame Number High
                                                
;------------------------------------------------------------------------------
; FRAMEL Enums (USB0 Frame Number Low @ 0x0C)
;------------------------------------------------------------------------------
FRAMEL_FRMEL__FMASK EQU 0FFH ; Frame Number Low
FRAMEL_FRMEL__SHIFT EQU 000H ; Frame Number Low
                                               
;------------------------------------------------------------------------------
; IN1IE Enums (USB0 IN Endpoint Interrupt Enable @ 0x07)
;------------------------------------------------------------------------------
IN1IE_EP0E__BMASK    EQU 001H ; Endpoint 0 Interrupt Enable      
IN1IE_EP0E__SHIFT    EQU 000H ; Endpoint 0 Interrupt Enable      
IN1IE_EP0E__DISABLED EQU 000H ; Disable Endpoint 0 interrupts.   
IN1IE_EP0E__ENABLED  EQU 001H ; Enable Endpoint 0 interrupts.    
                                                                 
IN1IE_IN1E__BMASK    EQU 002H ; IN Endpoint 1 Interrupt Enable   
IN1IE_IN1E__SHIFT    EQU 001H ; IN Endpoint 1 Interrupt Enable   
IN1IE_IN1E__DISABLED EQU 000H ; Disable Endpoint 1 IN interrupts.
IN1IE_IN1E__ENABLED  EQU 002H ; Enable Endpoint 1 IN interrupts. 
                                                                 
IN1IE_IN2E__BMASK    EQU 004H ; IN Endpoint 2 Interrupt Enable   
IN1IE_IN2E__SHIFT    EQU 002H ; IN Endpoint 2 Interrupt Enable   
IN1IE_IN2E__DISABLED EQU 000H ; Disable Endpoint 2 IN interrupts.
IN1IE_IN2E__ENABLED  EQU 004H ; Enable Endpoint 2 IN interrupts. 
                                                                 
IN1IE_IN3E__BMASK    EQU 008H ; IN Endpoint 3 Interrupt Enable   
IN1IE_IN3E__SHIFT    EQU 003H ; IN Endpoint 3 Interrupt Enable   
IN1IE_IN3E__DISABLED EQU 000H ; Disable Endpoint 3 IN interrupts.
IN1IE_IN3E__ENABLED  EQU 008H ; Enable Endpoint 3 IN interrupts. 
                                                                 
;------------------------------------------------------------------------------
; IN1INT Enums (USB0 IN Endpoint Interrupt @ 0x02)
;------------------------------------------------------------------------------
IN1INT_EP0__BMASK   EQU 001H ; Endpoint 0 Interrupt Flag        
IN1INT_EP0__SHIFT   EQU 000H ; Endpoint 0 Interrupt Flag        
IN1INT_EP0__NOT_SET EQU 000H ; Endpoint 0 interrupt inactive.   
IN1INT_EP0__SET     EQU 001H ; Endpoint 0 interrupt active.     
                                                                
IN1INT_IN1__BMASK   EQU 002H ; IN Endpoint 1 Interrupt Flag     
IN1INT_IN1__SHIFT   EQU 001H ; IN Endpoint 1 Interrupt Flag     
IN1INT_IN1__NOT_SET EQU 000H ; IN Endpoint 1 interrupt inactive.
IN1INT_IN1__SET     EQU 002H ; IN Endpoint 1 interrupt active.  
                                                                
IN1INT_IN2__BMASK   EQU 004H ; IN Endpoint 2 Interrupt Flag     
IN1INT_IN2__SHIFT   EQU 002H ; IN Endpoint 2 Interrupt Flag     
IN1INT_IN2__NOT_SET EQU 000H ; IN Endpoint 2 interrupt inactive.
IN1INT_IN2__SET     EQU 004H ; IN Endpoint 2 interrupt active.  
                                                                
IN1INT_IN3__BMASK   EQU 008H ; IN Endpoint 3 Interrupt Flag     
IN1INT_IN3__SHIFT   EQU 003H ; IN Endpoint 3 Interrupt Flag     
IN1INT_IN3__NOT_SET EQU 000H ; IN Endpoint 3 interrupt inactive.
IN1INT_IN3__SET     EQU 008H ; IN Endpoint 3 interrupt active.  
                                                                
;------------------------------------------------------------------------------
; INDEX Enums (USB0 Endpoint Index @ 0x0E)
;------------------------------------------------------------------------------
INDEX_EPSEL__FMASK      EQU 00FH ; Endpoint Select Bits
INDEX_EPSEL__SHIFT      EQU 000H ; Endpoint Select Bits
INDEX_EPSEL__ENDPOINT_0 EQU 000H ; Endpoint 0.         
INDEX_EPSEL__ENDPOINT_1 EQU 001H ; Endpoint 1.         
INDEX_EPSEL__ENDPOINT_2 EQU 002H ; Endpoint 2.         
INDEX_EPSEL__ENDPOINT_3 EQU 003H ; Endpoint 3.         
                                                       
;------------------------------------------------------------------------------
; OUT1IE Enums (USB0 OUT Endpoint Interrupt Enable @ 0x09)
;------------------------------------------------------------------------------
OUT1IE_OUT1E__BMASK    EQU 002H ; OUT Endpoint 1 Interrupt Enable   
OUT1IE_OUT1E__SHIFT    EQU 001H ; OUT Endpoint 1 Interrupt Enable   
OUT1IE_OUT1E__DISABLED EQU 000H ; Disable Endpoint 1 OUT interrupts.
OUT1IE_OUT1E__ENABLED  EQU 002H ; Enable Endpoint 1 OUT interrupts. 
                                                                    
OUT1IE_OUT2E__BMASK    EQU 004H ; OUT Endpoint 2 Interrupt Enable   
OUT1IE_OUT2E__SHIFT    EQU 002H ; OUT Endpoint 2 Interrupt Enable   
OUT1IE_OUT2E__DISABLED EQU 000H ; Disable Endpoint 2 OUT interrupts.
OUT1IE_OUT2E__ENABLED  EQU 004H ; Enable Endpoint 2 OUT interrupts. 
                                                                    
OUT1IE_OUT3E__BMASK    EQU 008H ; OUT Endpoint 3 Interrupt Enable   
OUT1IE_OUT3E__SHIFT    EQU 003H ; OUT Endpoint 3 Interrupt Enable   
OUT1IE_OUT3E__DISABLED EQU 000H ; Disable Endpoint 3 OUT interrupts.
OUT1IE_OUT3E__ENABLED  EQU 008H ; Enable Endpoint 3 OUT interrupts. 
                                                                    
;------------------------------------------------------------------------------
; OUT1INT Enums (USB0 OUT Endpoint Interrupt @ 0x04)
;------------------------------------------------------------------------------
OUT1INT_OUT1__BMASK   EQU 002H ; OUT Endpoint 1 Interrupt Flag     
OUT1INT_OUT1__SHIFT   EQU 001H ; OUT Endpoint 1 Interrupt Flag     
OUT1INT_OUT1__NOT_SET EQU 000H ; OUT Endpoint 1 interrupt inactive.
OUT1INT_OUT1__SET     EQU 002H ; OUT Endpoint 1 interrupt active.  
                                                                   
OUT1INT_OUT2__BMASK   EQU 004H ; OUT Endpoint 2 Interrupt Flag     
OUT1INT_OUT2__SHIFT   EQU 002H ; OUT Endpoint 2 Interrupt Flag     
OUT1INT_OUT2__NOT_SET EQU 000H ; OUT Endpoint 2 interrupt inactive.
OUT1INT_OUT2__SET     EQU 004H ; OUT Endpoint 2 interrupt active.  
                                                                   
OUT1INT_OUT3__BMASK   EQU 008H ; OUT Endpoint 3 Interrupt Flag     
OUT1INT_OUT3__SHIFT   EQU 003H ; OUT Endpoint 3 Interrupt Flag     
OUT1INT_OUT3__NOT_SET EQU 000H ; OUT Endpoint 3 interrupt inactive.
OUT1INT_OUT3__SET     EQU 008H ; OUT Endpoint 3 interrupt active.  
                                                                   
;------------------------------------------------------------------------------
; POWER Enums (USB0 Power @ 0x01)
;------------------------------------------------------------------------------
POWER_SUSEN__BMASK         EQU 001H ; Suspend Detection Enable                          
POWER_SUSEN__SHIFT         EQU 000H ; Suspend Detection Enable                          
POWER_SUSEN__DISABLED      EQU 000H ; Disable suspend detection. USB0 will ignore       
                                    ; suspend signaling on the bus.                     
POWER_SUSEN__ENABLED       EQU 001H ; Enable suspend detection. USB0 will enter suspend 
                                    ; mode if it detects suspend signaling on the bus.  
                                                                                        
POWER_SUSMD__BMASK         EQU 002H ; Suspend Mode                                      
POWER_SUSMD__SHIFT         EQU 001H ; Suspend Mode                                      
POWER_SUSMD__NOT_SUSPENDED EQU 000H ; USB0 not in suspend mode.                         
POWER_SUSMD__SUSPENDED     EQU 002H ; USB0 in suspend mode.                             
                                                                                        
POWER_RESUME__BMASK        EQU 004H ; Force Resume                                      
POWER_RESUME__SHIFT        EQU 002H ; Force Resume                                      
POWER_RESUME__START        EQU 004H ; Generate resume signalling to create a remote     
                                    ; wakeup event.                                     
                                                                                        
POWER_USBRST__BMASK        EQU 008H ; Reset Detect                                      
POWER_USBRST__SHIFT        EQU 003H ; Reset Detect                                      
POWER_USBRST__NOT_SET      EQU 000H ; USB reset signalling not detected.                
POWER_USBRST__SET          EQU 008H ; USB reset signalling detected.                    
                                                                                        
POWER_USBINH__BMASK        EQU 010H ; USB0 Inhibit                                      
POWER_USBINH__SHIFT        EQU 004H ; USB0 Inhibit                                      
POWER_USBINH__ENABLED      EQU 000H ; USB0 enabled.                                     
POWER_USBINH__DISABLED     EQU 010H ; USB0 inhibited. All USB traffic is ignored.       
                                                                                        
POWER_ISOUD__BMASK         EQU 080H ; Isochronous Update Mode                           
POWER_ISOUD__SHIFT         EQU 007H ; Isochronous Update Mode                           
POWER_ISOUD__IN_TOKEN      EQU 000H ; When firmware writes INPRDY = 1, USB0 will send   
                                    ; the packet when the next IN token is received.    
POWER_ISOUD__SOF_TOKEN     EQU 080H ; When firmware writes INPRDY = 1, USB0 will wait   
                                    ; for a SOF token before sending the packet. If an  
                                    ; IN token is received before a SOF token, USB0 will
                                    ; send a zero-length data packet.                   
                                                                                        
;------------------------------------------------------------------------------
; USB0ADR Enums (USB0 Indirect Address @ 0xAE)
;------------------------------------------------------------------------------
USB0ADR_USB0ADR__FMASK          EQU 03FH ; USB0 Indirect Register Address                    
USB0ADR_USB0ADR__SHIFT          EQU 000H ; USB0 Indirect Register Address                    
USB0ADR_USB0ADR__FADDR          EQU 000H ; Function Address.                                 
USB0ADR_USB0ADR__POWER          EQU 001H ; Power Management.                                 
USB0ADR_USB0ADR__IN1INT         EQU 002H ; Endpoint 0 and Endpoints 1-3 IN Interrupt Flags.  
USB0ADR_USB0ADR__OUT1INT        EQU 004H ; Endpoints 1-3 OUT Interrupt Flags.                
USB0ADR_USB0ADR__CMINT          EQU 006H ; Common USB Interrupt Flags.                       
USB0ADR_USB0ADR__IN1IE          EQU 007H ; Endpoint 0 and Endpoints 1-3 IN Interrupt Enables.
USB0ADR_USB0ADR__OUT1IE         EQU 009H ; Endpoints 1-3 OUT Interrupt Enables.              
USB0ADR_USB0ADR__CMIE           EQU 00BH ; Common USB Interrupt Enables.                     
USB0ADR_USB0ADR__FRAMEL         EQU 00CH ; Frame Number Low Byte.                            
USB0ADR_USB0ADR__FRAMEH         EQU 00DH ; Frame Number High Byte.                           
USB0ADR_USB0ADR__INDEX          EQU 00EH ; Endpoint Index Selection.                         
USB0ADR_USB0ADR__CLKREC         EQU 00FH ; Clock Recovery Control.                           
USB0ADR_USB0ADR__E0CSR_EINCSRL  EQU 011H ; Endpoint 0 Control / Status, Endpoint IN Control /
                                         ; Status Low Byte.                                  
USB0ADR_USB0ADR__EINCSRH        EQU 012H ; Endpoint IN Control / Status High Byte.           
USB0ADR_USB0ADR__EOUTCSRL       EQU 014H ; Endpoint OUT Control / Status Low Byte.           
USB0ADR_USB0ADR__EOUTCSRH       EQU 015H ; Endpoint OUT Control / Status High Byte.          
USB0ADR_USB0ADR__E0CNT_EOUTCNTL EQU 016H ; Number of Received Bytes in Endpoint 0 FIFO,      
                                         ; Endpoint OUT Packet Count Low Byte.               
USB0ADR_USB0ADR__EOUTCNTH       EQU 017H ; Endpoint OUT Packet Count High Byte.              
USB0ADR_USB0ADR__EENABLE        EQU 01EH ; Endpoint Enable.                                  
USB0ADR_USB0ADR__FIFO0          EQU 020H ; Endpoint 0 FIFO.                                  
USB0ADR_USB0ADR__FIFO1          EQU 021H ; Endpoint 1 FIFO.                                  
USB0ADR_USB0ADR__FIFO2          EQU 022H ; Endpoint 2 FIFO.                                  
USB0ADR_USB0ADR__FIFO3          EQU 023H ; Endpoint 3 FIFO.                                  
                                                                                             
USB0ADR_AUTORD__BMASK           EQU 040H ; USB0 Register Auto-Read Flag                      
USB0ADR_AUTORD__SHIFT           EQU 006H ; USB0 Register Auto-Read Flag                      
USB0ADR_AUTORD__DISABLED        EQU 000H ; BUSY must be written manually for each USB0       
                                         ; indirect register read.                           
USB0ADR_AUTORD__ENABLED         EQU 040H ; The next indirect register read will automatically
                                         ; be initiated when firmware reads USB0DAT (USBADDR 
                                         ; bits will not be changed).                        
                                                                                             
USB0ADR_BUSY__BMASK             EQU 080H ; USB0 Register Read Busy Flag                      
USB0ADR_BUSY__SHIFT             EQU 007H ; USB0 Register Read Busy Flag                      
USB0ADR_BUSY__NOT_SET           EQU 000H ; A read is not in progress.                        
USB0ADR_BUSY__SET               EQU 080H ; Initiate a read or a read is in progress.         
                                                                                             
;------------------------------------------------------------------------------
; USB0AEC Enums (USB0 Advanced Energy Control @ 0xB2)
;------------------------------------------------------------------------------
USB0AEC_LEMCN__FMASK             EQU 003H ; Low Energy Mode Control                          
USB0AEC_LEMCN__SHIFT             EQU 000H ; Low Energy Mode Control                          
USB0AEC_LEMCN__DISABLED          EQU 000H ; LE mode is disabled.                             
USB0AEC_LEMCN__IDLE              EQU 001H ; LE takes effect only during idle bus times.      
USB0AEC_LEMCN__NAK_OUT           EQU 002H ; LE takes effect only during NAKed OUT packets.   
USB0AEC_LEMCN__ALL               EQU 003H ; LE takes effect during idle bus and NAKed OUT    
                                          ; packets.                                         
                                                                                             
USB0AEC_OSCMD__FMASK             EQU 030H ; Low Energy Mode Oscillator Control               
USB0AEC_OSCMD__SHIFT             EQU 004H ; Low Energy Mode Oscillator Control               
USB0AEC_OSCMD__OSC_GATED_SUSPEND EQU 000H ; The USB clock source is selectively gated by LE  
                                          ; mode, and the High-Frequency Oscillator (HFOSC1) 
                                          ; is suspended if possible.                        
USB0AEC_OSCMD__OSC_GATED         EQU 010H ; The USB clock source is selectively gated by LE  
                                          ; mode. There is no effect to HFOSC1.              
USB0AEC_OSCMD__OSC_ON            EQU 030H ; LE mode has no effect on either the USB clock or 
                                          ; HFOSC1.                                          
                                                                                             
USB0AEC_XCVRMD__BMASK            EQU 040H ; Transceiver Mode                                 
USB0AEC_XCVRMD__SHIFT            EQU 006H ; Transceiver Mode                                 
USB0AEC_XCVRMD__LOW_POWER        EQU 000H ; The USB transceiver is selectively put into a    
                                          ; lower power state when low energy mode is active.
USB0AEC_XCVRMD__NORMAL_POWER     EQU 040H ; The USB transceiver is not affected by low energy
                                          ; mode.                                            
                                                                                             
USB0AEC_LEMSTA__BMASK            EQU 080H ; Low Energy Mode Status                           
USB0AEC_LEMSTA__SHIFT            EQU 007H ; Low Energy Mode Status                           
USB0AEC_LEMSTA__OFF              EQU 000H ; The USB peripheral is in normal mode.            
USB0AEC_LEMSTA__ON               EQU 080H ; The USB peripheral is in a low energy mode.      
                                                                                             
;------------------------------------------------------------------------------
; USB0CDCF Enums (USB0 Charger Detect Configuration @ 0xB6)
;------------------------------------------------------------------------------
USB0CDCF_DCDIE__BMASK    EQU 002H ; DCD Interrupt Enable                              
USB0CDCF_DCDIE__SHIFT    EQU 001H ; DCD Interrupt Enable                              
USB0CDCF_DCDIE__DISABLED EQU 000H ; DCDI will not generate charger detect interrupts. 
USB0CDCF_DCDIE__ENABLED  EQU 002H ; DCDI allowed to generate charger detect           
                                  ; interrupts.                                       
                                                                                      
USB0CDCF_PDIE__BMASK     EQU 004H ; PD Interrupt Enable                               
USB0CDCF_PDIE__SHIFT     EQU 002H ; PD Interrupt Enable                               
USB0CDCF_PDIE__DISABLED  EQU 000H ; PDI will not generate charger detect interrupts.  
USB0CDCF_PDIE__ENABLED   EQU 004H ; PDI allowed to generate charger detect interrupts.
                                                                                      
USB0CDCF_SDIE__BMASK     EQU 008H ; SD Interrupt Enable                               
USB0CDCF_SDIE__SHIFT     EQU 003H ; SD Interrupt Enable                               
USB0CDCF_SDIE__DISABLED  EQU 000H ; SDI will not generate charger detect interrupts.  
USB0CDCF_SDIE__ENABLED   EQU 008H ; SDI allowed to generate charger detect interrupts.
                                                                                      
;------------------------------------------------------------------------------
; USB0CDCN Enums (USB0 Charger Detect Control @ 0xBE)
;------------------------------------------------------------------------------
USB0CDCN_DCDEN__FMASK    EQU 003H ; Data Contact Detection Enable                    
USB0CDCN_DCDEN__SHIFT    EQU 000H ; Data Contact Detection Enable                    
USB0CDCN_DCDEN__DISABLED EQU 000H ; DCD is disabled.                                 
USB0CDCN_DCDEN__TIMEOUT  EQU 002H ; Only DCD timeout will be initiated.              
USB0CDCN_DCDEN__ENABLED  EQU 003H ; Full DCD operation (physical contact and timeout)
                                  ; will be initiated.                               
                                                                                     
USB0CDCN_PDEN__BMASK     EQU 004H ; Primary Detection Enable                         
USB0CDCN_PDEN__SHIFT     EQU 002H ; Primary Detection Enable                         
USB0CDCN_PDEN__DISABLED  EQU 000H ; Disable primary detection.                       
USB0CDCN_PDEN__ENABLED   EQU 004H ; Enable primary detection.                        
                                                                                     
USB0CDCN_SDEN__BMASK     EQU 008H ; Secondary Detection Enable                       
USB0CDCN_SDEN__SHIFT     EQU 003H ; Secondary Detection Enable                       
USB0CDCN_SDEN__DISABLED  EQU 000H ; Disable secondary detection.                     
USB0CDCN_SDEN__ENABLED   EQU 008H ; Enable secondary detection.                      
                                                                                     
USB0CDCN_CHDEN__BMASK    EQU 010H ; Charger Detection Enable                         
USB0CDCN_CHDEN__SHIFT    EQU 004H ; Charger Detection Enable                         
USB0CDCN_CHDEN__DISABLED EQU 000H ; Disable the charger detection block.             
USB0CDCN_CHDEN__ENABLED  EQU 010H ; Enable the charger detection block.              
                                                                                     
;------------------------------------------------------------------------------
; USB0CDSTA Enums (USB0 Charger Detect Status @ 0xBF)
;------------------------------------------------------------------------------
USB0CDSTA_DCDTO__BMASK      EQU 001H ; Data Contact Detection Timeout                   
USB0CDSTA_DCDTO__SHIFT      EQU 000H ; Data Contact Detection Timeout                   
USB0CDSTA_DCDTO__NO_TIMEOUT EQU 000H ; A DCD timeout was not triggered.                 
USB0CDSTA_DCDTO__TIMEOUT    EQU 001H ; A DCD timeout was triggered.                     
                                                                                        
USB0CDSTA_DCDI__BMASK       EQU 002H ; Data Contact Detect Complete                     
USB0CDSTA_DCDI__SHIFT       EQU 001H ; Data Contact Detect Complete                     
USB0CDSTA_DCDI__NOT_SET     EQU 000H ; DCD operation has not completed.                 
USB0CDSTA_DCDI__SET         EQU 002H ; DCD operation has completed. If DCDIE is set to 1
                                     ; a charger detect interrupt may be generated. This
                                     ; flag must be cleared by firmware.                
                                                                                        
USB0CDSTA_PDI__BMASK        EQU 004H ; Primary Detection Complete                       
USB0CDSTA_PDI__SHIFT        EQU 002H ; Primary Detection Complete                       
USB0CDSTA_PDI__NOT_SET      EQU 000H ; PD operation has not completed.                  
USB0CDSTA_PDI__SET          EQU 004H ; PD operation has completed. If PDIE is set to 1 a
                                     ; charger detect interrupt may be generated. This  
                                     ; flag must be cleared by firmware.                
                                                                                        
USB0CDSTA_SDI__BMASK        EQU 008H ; Secondary Detection Complete                     
USB0CDSTA_SDI__SHIFT        EQU 003H ; Secondary Detection Complete                     
USB0CDSTA_SDI__NOT_SET      EQU 000H ; SD operation has not completed.                  
USB0CDSTA_SDI__SET          EQU 008H ; SD operation has completed. If SDIE is set to 1 a
                                     ; charger detect interrupt may be generated. This  
                                     ; flag must be cleared by firmware.                
                                                                                        
USB0CDSTA_DCP__BMASK        EQU 010H ; Dedicated Charging Port Detected                 
USB0CDSTA_DCP__SHIFT        EQU 004H ; Dedicated Charging Port Detected                 
USB0CDSTA_DCP__NOT_DETECTED EQU 000H ; DCP was not detected.                            
USB0CDSTA_DCP__DETECTED     EQU 010H ; DCP was detected.                                
                                                                                        
USB0CDSTA_CDP__BMASK        EQU 020H ; Charging Downstream Port Detected                
USB0CDSTA_CDP__SHIFT        EQU 005H ; Charging Downstream Port Detected                
USB0CDSTA_CDP__NOT_DETECTED EQU 000H ; CDP was not detected.                            
USB0CDSTA_CDP__DETECTED     EQU 020H ; CDP was detected.                                
                                                                                        
USB0CDSTA_SDP__BMASK        EQU 040H ; Standard Downstream Port Detected                
USB0CDSTA_SDP__SHIFT        EQU 006H ; Standard Downstream Port Detected                
USB0CDSTA_SDP__NOT_DETECTED EQU 000H ; SDP was not detected.                            
USB0CDSTA_SDP__DETECTED     EQU 040H ; SDP was detected.                                
                                                                                        
USB0CDSTA_ERR__BMASK        EQU 080H ; USB Charger Detection Error                      
USB0CDSTA_ERR__SHIFT        EQU 007H ; USB Charger Detection Error                      
USB0CDSTA_ERR__NO_ERROR     EQU 000H ; No error has occurred.                           
USB0CDSTA_ERR__ERROR        EQU 080H ; An error has occurred. If enabled, a USB charger 
                                     ; detect interrupt will be triggered. This bit must
                                     ; be cleared by firmware.                          
                                                                                        
;------------------------------------------------------------------------------
; USB0CF Enums (USB0 Configuration @ 0xB5)
;------------------------------------------------------------------------------
USB0CF_USBCLK__FMASK        EQU 007H ; USB0 Clock Source Select Bits                     
USB0CF_USBCLK__SHIFT        EQU 000H ; USB0 Clock Source Select Bits                     
USB0CF_USBCLK__HFOSC1       EQU 000H ; USB0 clock (USB0CLK) derived from High-Frequency  
                                     ; Oscillator 1 (HFOSC1).                            
USB0CF_USBCLK__HFOSC1_DIV_8 EQU 001H ; USB0 clock (USB0CLK) derived from High-Frequency  
                                     ; Oscillator 1 / 8 (HFOSC1 / 8).                    
USB0CF_USBCLK__EXTOSC       EQU 002H ; USB0 clock (USB0CLK) derived from the External    
                                     ; Oscillator.                                       
USB0CF_USBCLK__EXTOSC_DIV_2 EQU 003H ; USB0 clock (USB0CLK) derived from the External    
                                     ; Oscillator / 2.                                   
USB0CF_USBCLK__EXTOSC_DIV_3 EQU 004H ; USB0 clock (USB0CLK) derived from the External    
                                     ; Oscillator / 3.                                   
USB0CF_USBCLK__EXTOSC_DIV_4 EQU 005H ; USB0 clock (USB0CLK) derived from the External    
                                     ; Oscillator / 4.                                   
USB0CF_USBCLK__LFOSC        EQU 006H ; USB0 clock (USB0CLK) derived from the Internal    
                                     ; Low-Frequency Oscillator.                         
USB0CF_USBCLK__NOCLOCK      EQU 007H ; USB0 clock (USB0CLK) is turned off.               
                                                                                         
USB0CF_VBUSI__BMASK         EQU 020H ; VBUS Interrupt                                    
USB0CF_VBUSI__SHIFT         EQU 005H ; VBUS Interrupt                                    
USB0CF_VBUSI__NOT_SET       EQU 000H ; A VBUS event has not occurred.                    
USB0CF_VBUSI__SET           EQU 020H ; A VBUS event has occurred.                        
                                                                                         
USB0CF_VBUSIE__BMASK        EQU 040H ; VBUS Interrupt Enable                             
USB0CF_VBUSIE__SHIFT        EQU 006H ; VBUS Interrupt Enable                             
USB0CF_VBUSIE__DISABLED     EQU 000H ; The VBUS sense signal will not generate           
                                     ; interrupts.                                       
USB0CF_VBUSIE__ENABLED      EQU 040H ; The VBUS sense signal may generate VBUS interrupts
                                     ; when a VBUS event is deteted. The VBUS interrupt  
                                     ; must be enabled in the main interrupt controller  
                                     ; for the interrupt to occur.                       
                                                                                         
USB0CF_VBUSEN__BMASK        EQU 080H ; VBUS Sense Enable                                 
USB0CF_VBUSEN__SHIFT        EQU 007H ; VBUS Sense Enable                                 
USB0CF_VBUSEN__DISABLED     EQU 000H ; The VBUS pin can be used as GPIO.                 
USB0CF_VBUSEN__ENABLED      EQU 080H ; The VBUS pin is used to sense the USB VBUS signal 
                                     ; voltage.                                          
                                                                                         
;------------------------------------------------------------------------------
; USB0DAT Enums (USB0 Data @ 0xAF)
;------------------------------------------------------------------------------
USB0DAT_USB0DAT__FMASK EQU 0FFH ; USB0 Data
USB0DAT_USB0DAT__SHIFT EQU 000H ; USB0 Data
                                           
;------------------------------------------------------------------------------
; USB0XCN Enums (USB0 Transceiver Control @ 0xB3)
;------------------------------------------------------------------------------
USB0XCN_Dn__BMASK                EQU 001H ; D- Signal Status                                 
USB0XCN_Dn__SHIFT                EQU 000H ; D- Signal Status                                 
USB0XCN_Dn__LOW                  EQU 000H ; D- signal currently at logic 0.                  
USB0XCN_Dn__HIGH                 EQU 001H ; D- signal currently at logic 1.                  
                                                                                             
USB0XCN_Dp__BMASK                EQU 002H ; D+ Signal Status                                 
USB0XCN_Dp__SHIFT                EQU 001H ; D+ Signal Status                                 
USB0XCN_Dp__LOW                  EQU 000H ; D+ signal currently at logic 0.                  
USB0XCN_Dp__HIGH                 EQU 002H ; D+ signal currently at logic 1.                  
                                                                                             
USB0XCN_DFREC__BMASK             EQU 004H ; Differential Receiver                            
USB0XCN_DFREC__SHIFT             EQU 002H ; Differential Receiver                            
USB0XCN_DFREC__DIFFERENTIAL_ZERO EQU 000H ; Differential 0 signalling on the bus.            
USB0XCN_DFREC__DIFFERENTIAL_ONE  EQU 004H ; Differential 1 signalling on the bus.            
                                                                                             
USB0XCN_PHYTST__FMASK            EQU 018H ; Physical Layer Test                              
USB0XCN_PHYTST__SHIFT            EQU 003H ; Physical Layer Test                              
USB0XCN_PHYTST__MODE0            EQU 000H ; Mode 0: Normal (non-test mode) (D+ = X, D- = X). 
USB0XCN_PHYTST__MODE1            EQU 008H ; Mode 1: Differential 1 forced (D+ = 1, D- = 0).  
USB0XCN_PHYTST__MODE2            EQU 010H ; Mode 2: Differential 0 forced (D+ = 0, D- = 1).  
USB0XCN_PHYTST__MODE3            EQU 018H ; Mode 3: Single-Ended 0 forced (D+ = 0, D- = 0).  
                                                                                             
USB0XCN_SPEED__BMASK             EQU 020H ; USB0 Speed Select                                
USB0XCN_SPEED__SHIFT             EQU 005H ; USB0 Speed Select                                
USB0XCN_SPEED__LOW_SPEED         EQU 000H ; USB0 operates as a Low Speed device. If enabled, 
                                          ; the internal pull-up resistor appears on the D-  
                                          ; line.                                            
USB0XCN_SPEED__FULL_SPEED        EQU 020H ; USB0 operates as a Full Speed device. If enabled,
                                          ; the internal pull-up resistor appears on the D+  
                                          ; line.                                            
                                                                                             
USB0XCN_PHYEN__BMASK             EQU 040H ; Physical Layer Enable                            
USB0XCN_PHYEN__SHIFT             EQU 006H ; Physical Layer Enable                            
USB0XCN_PHYEN__DISABLED          EQU 000H ; Disable the USB0 physical layer transceiver      
                                          ; (suspend).                                       
USB0XCN_PHYEN__ENABLED           EQU 040H ; Enable the USB0 physical layer transceiver       
                                          ; (normal).                                        
                                                                                             
USB0XCN_PREN__BMASK              EQU 080H ; Internal Pull-up Resistor Enable                 
USB0XCN_PREN__SHIFT              EQU 007H ; Internal Pull-up Resistor Enable                 
USB0XCN_PREN__PULL_UP_DISABLED   EQU 000H ; Internal pull-up resistor disabled (device       
                                          ; effectively detached from USB network).          
USB0XCN_PREN__PULL_UP_ENABLED    EQU 080H ; Internal pull-up resistor enabled when VBUS is   
                                          ; present (device attached to the USB network).    
                                                                                             
;------------------------------------------------------------------------------
; VDM0CN Enums (Supply Monitor Control @ 0xFF)
;------------------------------------------------------------------------------
VDM0CN_VDDSTAT__BMASK  EQU 040H ; Supply Status                                   
VDM0CN_VDDSTAT__SHIFT  EQU 006H ; Supply Status                                   
VDM0CN_VDDSTAT__BELOW  EQU 000H ; VDD is at or below the supply monitor threshold.
VDM0CN_VDDSTAT__ABOVE  EQU 040H ; VDD is above the supply monitor threshold.      
                                                                                  
VDM0CN_VDMEN__BMASK    EQU 080H ; Supply Monitor Enable                           
VDM0CN_VDMEN__SHIFT    EQU 007H ; Supply Monitor Enable                           
VDM0CN_VDMEN__DISABLED EQU 000H ; Supply Monitor Disabled.                        
VDM0CN_VDMEN__ENABLED  EQU 080H ; Supply Monitor Enabled.                         
                                                                                  
;------------------------------------------------------------------------------
; REF0CN Enums (Voltage Reference Control @ 0xD1)
;------------------------------------------------------------------------------
REF0CN_TEMPE__BMASK         EQU 004H ; Temperature Sensor Enable                         
REF0CN_TEMPE__SHIFT         EQU 002H ; Temperature Sensor Enable                         
REF0CN_TEMPE__TEMP_DISABLED EQU 000H ; Disable the Temperature Sensor.                   
REF0CN_TEMPE__TEMP_ENABLED  EQU 004H ; Enable the Temperature Sensor.                    
                                                                                         
REF0CN_REFSL__FMASK         EQU 018H ; Voltage Reference Select                          
REF0CN_REFSL__SHIFT         EQU 003H ; Voltage Reference Select                          
REF0CN_REFSL__VREF_PIN      EQU 000H ; The ADC0 voltage reference is the P0.0/VREF pin.  
REF0CN_REFSL__VDD_PIN       EQU 008H ; The ADC0 voltage reference is the VDD pin.        
REF0CN_REFSL__INTERNAL_LDO  EQU 010H ; The ADC0 voltage reference is the internal 1.8 V  
                                     ; digital supply voltage.                           
REF0CN_REFSL__INTERNAL_VREF EQU 018H ; The ADC0 voltage reference is the internal voltage
                                     ; reference.                                        
                                                                                         
REF0CN_GNDSL__BMASK         EQU 020H ; Analog Ground Reference                           
REF0CN_GNDSL__SHIFT         EQU 005H ; Analog Ground Reference                           
REF0CN_GNDSL__GND_PIN       EQU 000H ; The ADC0 ground reference is the GND pin.         
REF0CN_GNDSL__AGND_PIN      EQU 020H ; The ADC0 ground reference is the P0.1/AGND pin.   
                                                                                         
REF0CN_IREFLVL__BMASK       EQU 080H ; Internal Voltage Reference Level                  
REF0CN_IREFLVL__SHIFT       EQU 007H ; Internal Voltage Reference Level                  
REF0CN_IREFLVL__1P65        EQU 000H ; The internal reference operates at 1.65 V nominal.
REF0CN_IREFLVL__2P4         EQU 080H ; The internal reference operates at 2.4 V nominal. 
                                                                                         
;------------------------------------------------------------------------------
; REG0CN Enums (Voltage Regulator 0 Control @ 0xC9)
;------------------------------------------------------------------------------
REG0CN_STOPCF__BMASK    EQU 008H ; Stop and Shutdown Mode Configuration              
REG0CN_STOPCF__SHIFT    EQU 003H ; Stop and Shutdown Mode Configuration              
REG0CN_STOPCF__ACTIVE   EQU 000H ; Regulator is still active in stop mode. Any       
                                 ; enabled reset source will reset the device.       
REG0CN_STOPCF__SHUTDOWN EQU 008H ; Regulator is shut down in stop mode (device enters
                                 ; Shutdown mode). Only the RSTb pin or power cycle  
                                 ; can reset the device.                             
                                                                                     
;------------------------------------------------------------------------------
; REG1CN Enums (Voltage Regulator 1 Control @ 0xC6)
;------------------------------------------------------------------------------
REG1CN_SUSEN__BMASK      EQU 002H ; Voltage Regulator 1 Suspend Enable                
REG1CN_SUSEN__SHIFT      EQU 001H ; Voltage Regulator 1 Suspend Enable                
REG1CN_SUSEN__NORMAL     EQU 000H ; The 5V regulator is in normal power mode. Normal  
                                  ; mode is the highest performance mode for the      
                                  ; regulator.                                        
REG1CN_SUSEN__SUSPEND    EQU 002H ; The 5V regulator is in suspend power mode. Suspend
                                  ; mode reduces the regulator bias current, but      
                                  ; increases the response times.                     
                                                                                      
REG1CN_BIASENB__BMASK    EQU 004H ; Regulator Bias Disable                            
REG1CN_BIASENB__SHIFT    EQU 002H ; Regulator Bias Disable                            
REG1CN_BIASENB__ENABLED  EQU 000H ; Regulator bias is enabled.                        
REG1CN_BIASENB__DISABLED EQU 004H ; Regulator bias is disabled.                       
                                                                                      
REG1CN_REG1ENB__BMASK    EQU 080H ; Voltage Regulator 1 Disable                       
REG1CN_REG1ENB__SHIFT    EQU 007H ; Voltage Regulator 1 Disable                       
REG1CN_REG1ENB__ENABLED  EQU 000H ; Regulator is enabled.                             
REG1CN_REG1ENB__DISABLED EQU 080H ; Regulator is disabled.                            
                                                                                      
;------------------------------------------------------------------------------
; WDTCN Enums (Watchdog Timer Control @ 0x97)
;------------------------------------------------------------------------------
WDTCN_WDTCN__FMASK EQU 0FFH ; WDT Control
WDTCN_WDTCN__SHIFT EQU 000H ; WDT Control
                                         
;------------------------------------------------------------------------------
; EMI0CN Enums (External Memory Interface Control @ 0xE7)
;------------------------------------------------------------------------------
EMI0CN_PGSEL__FMASK EQU 00FH ; XRAM Page Select
EMI0CN_PGSEL__SHIFT EQU 000H ; XRAM Page Select
                                               
