;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  EFM8BB10F2A_QFN20
;  EFM8BB10F2G_QFN20
;  EFM8BB10F2I_QFN20
;  EFM8BB10F4A_QFN20
;  EFM8BB10F4G_QFN20
;  EFM8BB10F4I_QFN20
;  EFM8BB10F8A_QFN20
;  EFM8BB10F8G_QFN20
;  EFM8BB10F8G_QSOP24
;  EFM8BB10F8G_SOIC16
;  EFM8BB10F8I_QFN20
;  EFM8BB10F8I_QSOP24
;  EFM8BB10F8I_SOIC16

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
ADC0CN0_ADCM__FMASK            EQU 007H ; Start of Conversion Mode Select                   
ADC0CN0_ADCM__SHIFT            EQU 000H ; Start of Conversion Mode Select                   
ADC0CN0_ADCM__ADBUSY           EQU 000H ; ADC0 conversion initiated on write of 1 to ADBUSY.
ADC0CN0_ADCM__TIMER0           EQU 001H ; ADC0 conversion initiated on overflow of Timer 0. 
ADC0CN0_ADCM__TIMER2           EQU 002H ; ADC0 conversion initiated on overflow of Timer 2. 
ADC0CN0_ADCM__TIMER3           EQU 003H ; ADC0 conversion initiated on overflow of Timer 3. 
ADC0CN0_ADCM__CNVSTR           EQU 004H ; ADC0 conversion initiated on rising edge of       
                                        ; CNVSTR.                                           
                                                                                            
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
ADC0MX_ADC0MX__FMASK   EQU 01FH ; AMUX0 Positive Input Selection
ADC0MX_ADC0MX__SHIFT   EQU 000H ; AMUX0 Positive Input Selection
ADC0MX_ADC0MX__ADC0P0  EQU 000H ; Select ADC0.0.                
ADC0MX_ADC0MX__ADC0P1  EQU 001H ; Select ADC0.1.                
ADC0MX_ADC0MX__ADC0P2  EQU 002H ; Select ADC0.2.                
ADC0MX_ADC0MX__ADC0P3  EQU 003H ; Select ADC0.3.                
ADC0MX_ADC0MX__ADC0P4  EQU 004H ; Select ADC0.4.                
ADC0MX_ADC0MX__ADC0P5  EQU 005H ; Select ADC0.5.                
ADC0MX_ADC0MX__ADC0P6  EQU 006H ; Select ADC0.6.                
ADC0MX_ADC0MX__ADC0P7  EQU 007H ; Select ADC0.7.                
ADC0MX_ADC0MX__ADC0P8  EQU 008H ; Select ADC0.8.                
ADC0MX_ADC0MX__ADC0P9  EQU 009H ; Select ADC0.9.                
ADC0MX_ADC0MX__ADC0P10 EQU 00AH ; Select ADC0.10.               
ADC0MX_ADC0MX__ADC0P11 EQU 00BH ; Select ADC0.11.               
ADC0MX_ADC0MX__ADC0P12 EQU 00CH ; Select ADC0.12.               
ADC0MX_ADC0MX__ADC0P13 EQU 00DH ; Select ADC0.13.               
ADC0MX_ADC0MX__ADC0P14 EQU 00EH ; Select ADC0.14.               
ADC0MX_ADC0MX__ADC0P15 EQU 00FH ; Select ADC0.15.               
ADC0MX_ADC0MX__TEMP    EQU 010H ; Select ADC0.16.               
ADC0MX_ADC0MX__LDO_OUT EQU 011H ; Select ADC0.17.               
ADC0MX_ADC0MX__VDD     EQU 012H ; Select ADC0.18.               
ADC0MX_ADC0MX__GND     EQU 013H ; Select ADC0.19.               
ADC0MX_ADC0MX__NONE    EQU 01FH ; No input selected.            
                                                                
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
CLKSEL_CLKSL__FMASK           EQU 003H ; Clock Source Select                             
CLKSEL_CLKSL__SHIFT           EQU 000H ; Clock Source Select                             
CLKSEL_CLKSL__HFOSC           EQU 000H ; Clock derived from the Internal High-Frequency  
                                       ; Oscillator.                                     
CLKSEL_CLKSL__EXTOSC          EQU 001H ; Clock derived from the External CMOS clock      
                                       ; circuit.                                        
CLKSEL_CLKSL__LFOSC           EQU 002H ; Clock derived from the Internal Low-Frequency   
                                       ; Oscillator.                                     
                                                                                         
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
                                                                                       
CMP0MD_CPFIE__BMASK             EQU 010H ; Comparator Falling-Edge Interrupt Enable    
CMP0MD_CPFIE__SHIFT             EQU 004H ; Comparator Falling-Edge Interrupt Enable    
CMP0MD_CPFIE__FALL_INT_DISABLED EQU 000H ; Comparator falling-edge interrupt disabled. 
CMP0MD_CPFIE__FALL_INT_ENABLED  EQU 010H ; Comparator falling-edge interrupt enabled.  
                                                                                       
CMP0MD_CPRIE__BMASK             EQU 020H ; Comparator Rising-Edge Interrupt Enable     
CMP0MD_CPRIE__SHIFT             EQU 005H ; Comparator Rising-Edge Interrupt Enable     
CMP0MD_CPRIE__RISE_INT_DISABLED EQU 000H ; Comparator rising-edge interrupt disabled.  
CMP0MD_CPRIE__RISE_INT_ENABLED  EQU 020H ; Comparator rising-edge interrupt enabled.   
                                                                                       
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
CMP0MX_CMXP__LDO_OUT EQU 008H ; External pin CMP0P.8.                  
CMP0MX_CMXP__NONE    EQU 00FH ; No input selected.                     
                                                                       
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
CMP0MX_CMXN__GND     EQU 080H ; External pin CMP0N.8.                  
CMP0MX_CMXN__NONE    EQU 0F0H ; No input selected.                     
                                                                       
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
                                                                                       
CMP1MD_CPFIE__BMASK             EQU 010H ; Comparator Falling-Edge Interrupt Enable    
CMP1MD_CPFIE__SHIFT             EQU 004H ; Comparator Falling-Edge Interrupt Enable    
CMP1MD_CPFIE__FALL_INT_DISABLED EQU 000H ; Comparator falling-edge interrupt disabled. 
CMP1MD_CPFIE__FALL_INT_ENABLED  EQU 010H ; Comparator falling-edge interrupt enabled.  
                                                                                       
CMP1MD_CPRIE__BMASK             EQU 020H ; Comparator Rising-Edge Interrupt Enable     
CMP1MD_CPRIE__SHIFT             EQU 005H ; Comparator Rising-Edge Interrupt Enable     
CMP1MD_CPRIE__RISE_INT_DISABLED EQU 000H ; Comparator rising-edge interrupt disabled.  
CMP1MD_CPRIE__RISE_INT_ENABLED  EQU 020H ; Comparator rising-edge interrupt enabled.   
                                                                                       
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
CMP1MX_CMXP__LDO_OUT EQU 008H ; External pin CMP1P.8.                  
CMP1MX_CMXP__NONE    EQU 00FH ; No input selected.                     
                                                                       
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
CMP1MX_CMXN__GND     EQU 080H ; External pin CMP1N.8.                  
CMP1MX_CMXN__NONE    EQU 0F0H ; No input selected.                     
                                                                       
;------------------------------------------------------------------------------
; CRC0AUTO Enums (CRC0 Automatic Control @ 0xD2)
;------------------------------------------------------------------------------
CRC0AUTO_CRCST__FMASK     EQU 03FH ; Automatic CRC Calculation Starting Block  
CRC0AUTO_CRCST__SHIFT     EQU 000H ; Automatic CRC Calculation Starting Block  
                                                                               
CRC0AUTO_AUTOEN__BMASK    EQU 080H ; Automatic CRC Calculation Enable          
CRC0AUTO_AUTOEN__SHIFT    EQU 007H ; Automatic CRC Calculation Enable          
CRC0AUTO_AUTOEN__DISABLED EQU 000H ; Disable automatic CRC operations on flash.
CRC0AUTO_AUTOEN__ENABLED  EQU 080H ; Enable automatic CRC operations on flash. 
                                                                               
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
; CRC0CNT Enums (CRC0 Automatic Flash Sector Count @ 0xD3)
;------------------------------------------------------------------------------
CRC0CNT_CRCCNT__FMASK  EQU 01FH ; Automatic CRC Calculation Block Count
CRC0CNT_CRCCNT__SHIFT  EQU 000H ; Automatic CRC Calculation Block Count
                                                                       
CRC0CNT_CRCDN__BMASK   EQU 080H ; Automatic CRC Calculation Complete   
CRC0CNT_CRCDN__SHIFT   EQU 007H ; Automatic CRC Calculation Complete   
CRC0CNT_CRCDN__NOT_SET EQU 000H ; A CRC calculation is in progress.    
CRC0CNT_CRCDN__SET     EQU 080H ; A CRC calculation is not in progress.
                                                                       
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
; DERIVID Enums (Derivative Identification @ 0xAD)
;------------------------------------------------------------------------------
DERIVID_DERIVID__FMASK              EQU 0FFH ; Derivative ID         
DERIVID_DERIVID__SHIFT              EQU 000H ; Derivative ID         
DERIVID_DERIVID__EFM8BB10F8G_QSOP24 EQU 001H ; EFM8BB10F8G-{R}-QSOP24
DERIVID_DERIVID__EFM8BB10F8G_QFN20  EQU 002H ; EFM8BB10F8G-{R}-QFN20 
DERIVID_DERIVID__EFM8BB10F8G_SOIC16 EQU 003H ; EFM8BB10F8G-{R}-SOIC16
DERIVID_DERIVID__EFM8BB10F4G_QFN20  EQU 005H ; EFM8BB10F4G-{R}-QFN20 
DERIVID_DERIVID__EFM8BB10F2G_QFN20  EQU 008H ; EFM8BB10F2G-{R}-QFN20 
DERIVID_DERIVID__EFM8BB10F8I_QSOP24 EQU 011H ; EFM8BB10F8I-{R}-QSOP24
DERIVID_DERIVID__EFM8BB10F8I_QFN20  EQU 012H ; EFM8BB10F8I-{R}-QFN20 
DERIVID_DERIVID__EFM8BB10F8I_SOIC16 EQU 013H ; EFM8BB10F8I-{R}-SOIC16
                                                                     
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
REVID_REVID__REV_A EQU 002H ; Revision A 
                                         
;------------------------------------------------------------------------------
; IT01CF Enums (INT0/INT1 Configuration @ 0xE4)
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
; EIP1 Enums (Extended Interrupt Priority 1 @ 0xF3)
;------------------------------------------------------------------------------
EIP1_PSMB0__BMASK  EQU 001H ; SMBus (SMB0) Interrupt Priority Control                     
EIP1_PSMB0__SHIFT  EQU 000H ; SMBus (SMB0) Interrupt Priority Control                     
EIP1_PSMB0__LOW    EQU 000H ; SMB0 interrupt set to low priority level.                   
EIP1_PSMB0__HIGH   EQU 001H ; SMB0 interrupt set to high priority level.                  
                                                                                          
EIP1_PMAT__BMASK   EQU 002H ; Port Match Interrupt Priority Control                       
EIP1_PMAT__SHIFT   EQU 001H ; Port Match Interrupt Priority Control                       
EIP1_PMAT__LOW     EQU 000H ; Port Match interrupt set to low priority level.             
EIP1_PMAT__HIGH    EQU 002H ; Port Match interrupt set to high priority level.            
                                                                                          
EIP1_PWADC0__BMASK EQU 004H ; ADC0 Window Comparator Interrupt Priority Control           
EIP1_PWADC0__SHIFT EQU 002H ; ADC0 Window Comparator Interrupt Priority Control           
EIP1_PWADC0__LOW   EQU 000H ; ADC0 Window interrupt set to low priority level.            
EIP1_PWADC0__HIGH  EQU 004H ; ADC0 Window interrupt set to high priority level.           
                                                                                          
EIP1_PADC0__BMASK  EQU 008H ; ADC0 Conversion Complete Interrupt Priority Control         
EIP1_PADC0__SHIFT  EQU 003H ; ADC0 Conversion Complete Interrupt Priority Control         
EIP1_PADC0__LOW    EQU 000H ; ADC0 Conversion Complete interrupt set to low               
                            ; priority level.                                             
EIP1_PADC0__HIGH   EQU 008H ; ADC0 Conversion Complete interrupt set to high              
                            ; priority level.                                             
                                                                                          
EIP1_PPCA0__BMASK  EQU 010H ; Programmable Counter Array (PCA0) Interrupt Priority Control
EIP1_PPCA0__SHIFT  EQU 004H ; Programmable Counter Array (PCA0) Interrupt Priority Control
EIP1_PPCA0__LOW    EQU 000H ; PCA0 interrupt set to low priority level.                   
EIP1_PPCA0__HIGH   EQU 010H ; PCA0 interrupt set to high priority level.                  
                                                                                          
EIP1_PCP0__BMASK   EQU 020H ; Comparator0 (CP0) Interrupt Priority Control                
EIP1_PCP0__SHIFT   EQU 005H ; Comparator0 (CP0) Interrupt Priority Control                
EIP1_PCP0__LOW     EQU 000H ; CP0 interrupt set to low priority level.                    
EIP1_PCP0__HIGH    EQU 020H ; CP0 interrupt set to high priority level.                   
                                                                                          
EIP1_PCP1__BMASK   EQU 040H ; Comparator1 (CP1) Interrupt Priority Control                
EIP1_PCP1__SHIFT   EQU 006H ; Comparator1 (CP1) Interrupt Priority Control                
EIP1_PCP1__LOW     EQU 000H ; CP1 interrupt set to low priority level.                    
EIP1_PCP1__HIGH    EQU 040H ; CP1 interrupt set to high priority level.                   
                                                                                          
EIP1_PT3__BMASK    EQU 080H ; Timer 3 Interrupt Priority Control                          
EIP1_PT3__SHIFT    EQU 007H ; Timer 3 Interrupt Priority Control                          
EIP1_PT3__LOW      EQU 000H ; Timer 3 interrupts set to low priority level.               
EIP1_PT3__HIGH     EQU 080H ; Timer 3 interrupts set to high priority level.              
                                                                                          
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
                                                                                
IE_ES0__BMASK      EQU 010H ; UART0 Interrupt Enable                            
IE_ES0__SHIFT      EQU 004H ; UART0 Interrupt Enable                            
IE_ES0__DISABLED   EQU 000H ; Disable UART0 interrupt.                          
IE_ES0__ENABLED    EQU 010H ; Enable UART0 interrupt.                           
                                                                                
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
IP_PX0__BMASK   EQU 001H ; External Interrupt 0 Priority Control                        
IP_PX0__SHIFT   EQU 000H ; External Interrupt 0 Priority Control                        
IP_PX0__LOW     EQU 000H ; External Interrupt 0 set to low priority level.              
IP_PX0__HIGH    EQU 001H ; External Interrupt 0 set to high priority level.             
                                                                                        
IP_PT0__BMASK   EQU 002H ; Timer 0 Interrupt Priority Control                           
IP_PT0__SHIFT   EQU 001H ; Timer 0 Interrupt Priority Control                           
IP_PT0__LOW     EQU 000H ; Timer 0 interrupt set to low priority level.                 
IP_PT0__HIGH    EQU 002H ; Timer 0 interrupt set to high priority level.                
                                                                                        
IP_PX1__BMASK   EQU 004H ; External Interrupt 1 Priority Control                        
IP_PX1__SHIFT   EQU 002H ; External Interrupt 1 Priority Control                        
IP_PX1__LOW     EQU 000H ; External Interrupt 1 set to low priority level.              
IP_PX1__HIGH    EQU 004H ; External Interrupt 1 set to high priority level.             
                                                                                        
IP_PT1__BMASK   EQU 008H ; Timer 1 Interrupt Priority Control                           
IP_PT1__SHIFT   EQU 003H ; Timer 1 Interrupt Priority Control                           
IP_PT1__LOW     EQU 000H ; Timer 1 interrupt set to low priority level.                 
IP_PT1__HIGH    EQU 008H ; Timer 1 interrupt set to high priority level.                
                                                                                        
IP_PS0__BMASK   EQU 010H ; UART0 Interrupt Priority Control                             
IP_PS0__SHIFT   EQU 004H ; UART0 Interrupt Priority Control                             
IP_PS0__LOW     EQU 000H ; UART0 interrupt set to low priority level.                   
IP_PS0__HIGH    EQU 010H ; UART0 interrupt set to high priority level.                  
                                                                                        
IP_PT2__BMASK   EQU 020H ; Timer 2 Interrupt Priority Control                           
IP_PT2__SHIFT   EQU 005H ; Timer 2 Interrupt Priority Control                           
IP_PT2__LOW     EQU 000H ; Timer 2 interrupt set to low priority level.                 
IP_PT2__HIGH    EQU 020H ; Timer 2 interrupt set to high priority level.                
                                                                                        
IP_PSPI0__BMASK EQU 040H ; Serial Peripheral Interface (SPI0) Interrupt Priority Control
IP_PSPI0__SHIFT EQU 006H ; Serial Peripheral Interface (SPI0) Interrupt Priority Control
IP_PSPI0__LOW   EQU 000H ; SPI0 interrupt set to low priority level.                    
IP_PSPI0__HIGH  EQU 040H ; SPI0 interrupt set to high priority level.                   
                                                                                        
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
XBR0_URT0E__BMASK     EQU 001H ; UART I/O Output Enable                        
XBR0_URT0E__SHIFT     EQU 000H ; UART I/O Output Enable                        
XBR0_URT0E__DISABLED  EQU 000H ; UART I/O unavailable at Port pin.             
XBR0_URT0E__ENABLED   EQU 001H ; UART TX, RX routed to Port pins P0.4 and P0.5.
                                                                               
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
SMB0CF_EXTHOLD__ENABLED         EQU 010H ; Enable SDA extended setup and hold times.        
                                                                                            
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
                                                                                      
SMB0TC_SWAP__BMASK        EQU 080H ; SMBus Swap Pins                                  
SMB0TC_SWAP__SHIFT        EQU 007H ; SMBus Swap Pins                                  
SMB0TC_SWAP__SDA_LOW_PIN  EQU 000H ; SDA is mapped to the lower-numbered port pin, and
                                   ; SCL is mapped to the higher-numbered port pin.   
SMB0TC_SWAP__SDA_HIGH_PIN EQU 080H ; SCL is mapped to the lower-numbered port pin, and
                                   ; SDA is mapped to the higher-numbered port pin.   
                                                                                      
;------------------------------------------------------------------------------
; SPI0CFG Enums (SPI0 Configuration @ 0xA1)
;------------------------------------------------------------------------------
SPI0CFG_RXBMT__BMASK                EQU 001H ; Receive Buffer Empty                              
SPI0CFG_RXBMT__SHIFT                EQU 000H ; Receive Buffer Empty                              
SPI0CFG_RXBMT__NOT_SET              EQU 000H ; New data is available in the receive buffer (Slave
                                             ; mode).                                            
SPI0CFG_RXBMT__SET                  EQU 001H ; No new data in the receive buffer (Slave mode).   
                                                                                                 
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
                                                                                                   
SPI0CN0_TXBMT__BMASK                  EQU 002H ; Transmit Buffer Empty                             
SPI0CN0_TXBMT__SHIFT                  EQU 001H ; Transmit Buffer Empty                             
SPI0CN0_TXBMT__NOT_SET                EQU 000H ; The transmit buffer is not empty.                 
SPI0CN0_TXBMT__SET                    EQU 002H ; The transmit buffer is empty.                     
                                                                                                   
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
TMR2CN0_T2XCLK__BMASK          EQU 001H ; Timer 2 External Clock Select                    
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
TMR3CN0_T3XCLK__BMASK          EQU 001H ; Timer 3 External Clock Select                    
TMR3CN0_T3XCLK__SHIFT          EQU 000H ; Timer 3 External Clock Select                    
TMR3CN0_T3XCLK__SYSCLK_DIV_12  EQU 000H ; Timer 3 clock is the system clock divided by 12. 
TMR3CN0_T3XCLK__EXTOSC_DIV_8   EQU 001H ; Timer 3 clock is the external oscillator divided 
                                        ; by 8 (synchronized with SYSCLK).                 
                                                                                           
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
; SBUF0 Enums (UART0 Serial Port Data Buffer @ 0x99)
;------------------------------------------------------------------------------
SBUF0_SBUF0__FMASK EQU 0FFH ; Serial Data Buffer
SBUF0_SBUF0__SHIFT EQU 000H ; Serial Data Buffer
                                                
;------------------------------------------------------------------------------
; SCON0 Enums (UART0 Serial Port Control @ 0x98)
;------------------------------------------------------------------------------
SCON0_RI__BMASK             EQU 001H ; Receive Interrupt Flag                           
SCON0_RI__SHIFT             EQU 000H ; Receive Interrupt Flag                           
SCON0_RI__NOT_SET           EQU 000H ; A byte of data has not been received by UART0.   
SCON0_RI__SET               EQU 001H ; UART0 received a byte of data.                   
                                                                                        
SCON0_TI__BMASK             EQU 002H ; Transmit Interrupt Flag                          
SCON0_TI__SHIFT             EQU 001H ; Transmit Interrupt Flag                          
SCON0_TI__NOT_SET           EQU 000H ; A byte of data has not been transmitted by UART0.
SCON0_TI__SET               EQU 002H ; UART0 transmitted a byte of data.                
                                                                                        
SCON0_RB8__BMASK            EQU 004H ; Ninth Receive Bit                                
SCON0_RB8__SHIFT            EQU 002H ; Ninth Receive Bit                                
SCON0_RB8__CLEARED_TO_0     EQU 000H ; In Mode 0, the STOP bit was 0. In Mode 1, the 9th
                                     ; bit was 0.                                       
SCON0_RB8__SET_TO_1         EQU 004H ; In Mode 0, the STOP bit was 1. In Mode 1, the 9th
                                     ; bit was 1.                                       
                                                                                        
SCON0_TB8__BMASK            EQU 008H ; Ninth Transmission Bit                           
SCON0_TB8__SHIFT            EQU 003H ; Ninth Transmission Bit                           
SCON0_TB8__CLEARED_TO_0     EQU 000H ; In Mode 1, set the 9th transmission bit to 0.    
SCON0_TB8__SET_TO_1         EQU 008H ; In Mode 1, set the 9th transmission bit to 1.    
                                                                                        
SCON0_REN__BMASK            EQU 010H ; Receive Enable                                   
SCON0_REN__SHIFT            EQU 004H ; Receive Enable                                   
SCON0_REN__RECEIVE_DISABLED EQU 000H ; UART0 reception disabled.                        
SCON0_REN__RECEIVE_ENABLED  EQU 010H ; UART0 reception enabled.                         
                                                                                        
SCON0_MCE__BMASK            EQU 020H ; Multiprocessor Communication Enable              
SCON0_MCE__SHIFT            EQU 005H ; Multiprocessor Communication Enable              
SCON0_MCE__MULTI_DISABLED   EQU 000H ; Ignore level of 9th bit / Stop bit.              
SCON0_MCE__MULTI_ENABLED    EQU 020H ; RI is set and an interrupt is generated only when
                                     ; the stop bit is logic 1 (Mode 0) or when the 9th 
                                     ; bit is logic 1 (Mode 1).                         
                                                                                        
SCON0_SMODE__BMASK          EQU 080H ; Serial Port 0 Operation Mode                     
SCON0_SMODE__SHIFT          EQU 007H ; Serial Port 0 Operation Mode                     
SCON0_SMODE__8_BIT          EQU 000H ; 8-bit UART with Variable Baud Rate (Mode 0).     
SCON0_SMODE__9_BIT          EQU 080H ; 9-bit UART with Variable Baud Rate (Mode 1).     
                                                                                        
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
; WDTCN Enums (Watchdog Timer Control @ 0x97)
;------------------------------------------------------------------------------
WDTCN_WDTCN__FMASK EQU 0FFH ; WDT Control
WDTCN_WDTCN__SHIFT EQU 000H ; WDT Control
                                         
