;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  C8051F410_GQ
;  C8051F411_GM
;  C8051F412_GQ
;  C8051F413_GM
;  C8051F414_GQ
;  C8051F415_GM
;  C8051F416_GQ
;  C8051F417_GM

;------------------------------------------------------------------------------
; ADC0CF Enums (ADC0 Configuration @ 0xBC)
;------------------------------------------------------------------------------
ADC0CF_ADRPT__FMASK  EQU 006H ; Repeat Count                          
ADC0CF_ADRPT__SHIFT  EQU 001H ; Repeat Count                          
ADC0CF_ADRPT__ACC_1  EQU 000H ; Perform and Accumulate 1 conversion.  
ADC0CF_ADRPT__ACC_4  EQU 002H ; Perform and Accumulate 4 conversions. 
ADC0CF_ADRPT__ACC_8  EQU 004H ; Perform and Accumulate 8 conversions. 
ADC0CF_ADRPT__ACC_16 EQU 006H ; Perform and Accumulate 16 conversions.
                                                                      
ADC0CF_ADSC__FMASK   EQU 0F8H ; SAR Clock Divider                     
ADC0CF_ADSC__SHIFT   EQU 003H ; SAR Clock Divider                     
                                                                      
;------------------------------------------------------------------------------
; ADC0CN Enums (ADC0 Control @ 0xE8)
;------------------------------------------------------------------------------
ADC0CN_ADCM__FMASK            EQU 003H ; Start of Conversion Mode Select                   
ADC0CN_ADCM__SHIFT            EQU 000H ; Start of Conversion Mode Select                   
ADC0CN_ADCM__ADBUSY           EQU 000H ; ADC0 conversion initiated on write of 1 to ADBUSY.
ADC0CN_ADCM__TIMER3           EQU 001H ; ADC0 conversion initiated on overflow of Timer 3. 
ADC0CN_ADCM__CNVSTR           EQU 002H ; ADC0 conversion initiated on rising edge of       
                                       ; CNVSTR.                                           
ADC0CN_ADCM__TIMER2           EQU 003H ; ADC0 conversion initiated on overflow of Timer 2. 
                                                                                           
ADC0CN_ADLJST__BMASK          EQU 004H ; Justification Select                              
ADC0CN_ADLJST__SHIFT          EQU 002H ; Justification Select                              
ADC0CN_ADLJST__RIGHT          EQU 000H ; Data in ADC0H:L is right-justified.               
ADC0CN_ADLJST__LEFT           EQU 004H ; Data in ADC0H:L is left-justified. This option    
                                       ; should not be used with a repeat count greater    
                                       ; than 1 (ADRPT set to any value other than 0).     
                                                                                           
ADC0CN_ADWINT__BMASK          EQU 008H ; Window Compare Interrupt Flag                     
ADC0CN_ADWINT__SHIFT          EQU 003H ; Window Compare Interrupt Flag                     
ADC0CN_ADWINT__NOT_SET        EQU 000H ; An ADC window compare event did not occur.        
ADC0CN_ADWINT__SET            EQU 008H ; An ADC window compare event occurred.             
                                                                                           
ADC0CN_ADBUSY__BMASK          EQU 010H ; ADC Busy                                          
ADC0CN_ADBUSY__SHIFT          EQU 004H ; ADC Busy                                          
ADC0CN_ADBUSY__NOT_SET        EQU 000H ; An ADC0 conversion is not currently in progress.  
ADC0CN_ADBUSY__SET            EQU 010H ; ADC0 conversion is in progress or start an ADC0   
                                       ; conversion.                                       
                                                                                           
ADC0CN_ADINT__BMASK           EQU 020H ; Conversion Complete Interrupt Flag                
ADC0CN_ADINT__SHIFT           EQU 005H ; Conversion Complete Interrupt Flag                
ADC0CN_ADINT__NOT_SET         EQU 000H ; ADC0 has not completed a conversion since the last
                                       ; time ADINT was cleared.                           
ADC0CN_ADINT__SET             EQU 020H ; ADC0 completed a data conversion.                 
                                                                                           
ADC0CN_ADBMEN__BMASK          EQU 040H ; Burst Mode Enable                                 
ADC0CN_ADBMEN__SHIFT          EQU 006H ; Burst Mode Enable                                 
ADC0CN_ADBMEN__BURST_DISABLED EQU 000H ; Disable ADC0 Burst Mode.                          
ADC0CN_ADBMEN__BURST_ENABLED  EQU 040H ; Enable ADC0 Burst Mode.                           
                                                                                           
ADC0CN_ADEN__BMASK            EQU 080H ; ADC Enable                                        
ADC0CN_ADEN__SHIFT            EQU 007H ; ADC Enable                                        
ADC0CN_ADEN__DISABLED         EQU 000H ; Disable ADC0 (low-power shutdown).                
ADC0CN_ADEN__ENABLED          EQU 080H ; Enable ADC0 (active and ready for data            
                                       ; conversions).                                     
                                                                                           
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
ADC0MX_ADC0MX__FMASK   EQU 01FH ; AMUX Positive Input Selection
ADC0MX_ADC0MX__SHIFT   EQU 000H ; AMUX Positive Input Selection
ADC0MX_ADC0MX__ADC0P0  EQU 000H ; Select channel ADC0.0.       
ADC0MX_ADC0MX__ADC0P1  EQU 001H ; Select channel ADC0.1.       
ADC0MX_ADC0MX__ADC0P2  EQU 002H ; Select channel ADC0.2.       
ADC0MX_ADC0MX__ADC0P3  EQU 003H ; Select channel ADC0.3.       
ADC0MX_ADC0MX__ADC0P4  EQU 004H ; Select channel ADC0.4.       
ADC0MX_ADC0MX__ADC0P5  EQU 005H ; Select channel ADC0.5.       
ADC0MX_ADC0MX__ADC0P6  EQU 006H ; Select channel ADC0.6.       
ADC0MX_ADC0MX__ADC0P7  EQU 007H ; Select channel ADC0.7.       
ADC0MX_ADC0MX__ADC0P8  EQU 008H ; Select channel ADC0.8.       
ADC0MX_ADC0MX__ADC0P9  EQU 009H ; Select channel ADC0.9.       
ADC0MX_ADC0MX__ADC0P10 EQU 00AH ; Select channel ADC0.10.      
ADC0MX_ADC0MX__ADC0P11 EQU 00BH ; Select channel ADC0.11.      
ADC0MX_ADC0MX__ADC0P12 EQU 00CH ; Select channel ADC0.12.      
ADC0MX_ADC0MX__ADC0P13 EQU 00DH ; Select channel ADC0.13.      
ADC0MX_ADC0MX__ADC0P14 EQU 00EH ; Select channel ADC0.14.      
ADC0MX_ADC0MX__ADC0P15 EQU 00FH ; Select channel ADC0.15.      
ADC0MX_ADC0MX__ADC0P16 EQU 010H ; Select channel ADC0.16.      
ADC0MX_ADC0MX__ADC0P17 EQU 011H ; Select channel ADC0.17.      
ADC0MX_ADC0MX__ADC0P18 EQU 012H ; Select channel ADC0.18.      
ADC0MX_ADC0MX__ADC0P19 EQU 013H ; Select channel ADC0.19.      
ADC0MX_ADC0MX__ADC0P20 EQU 014H ; Select channel ADC0.20.      
ADC0MX_ADC0MX__ADC0P21 EQU 015H ; Select channel ADC0.21.      
ADC0MX_ADC0MX__ADC0P22 EQU 016H ; Select channel ADC0.22.      
ADC0MX_ADC0MX__ADC0P23 EQU 017H ; Select channel ADC0.23.      
ADC0MX_ADC0MX__TEMP    EQU 018H ; Temperature Sensor.          
ADC0MX_ADC0MX__VDD     EQU 019H ; VDD Supply Voltage.          
ADC0MX_ADC0MX__GND     EQU 01FH ; Ground.                      
                                                               
;------------------------------------------------------------------------------
; ADC0TK Enums (ADC0 Burst Mode Track Time @ 0xBA)
;------------------------------------------------------------------------------
ADC0TK_ADTK__FMASK         EQU 003H ; Post Tracking Time                                
ADC0TK_ADTK__SHIFT         EQU 000H ; Post Tracking Time                                
ADC0TK_ADTK__2_SAR_CLOCKS  EQU 000H ; Post-Tracking time is equal to 2 SAR clock cycles 
                                    ; + 2 FADCCLK cycles.                               
ADC0TK_ADTK__4_SAR_CLOCKS  EQU 001H ; Post-Tracking time is equal to 4 SAR clock cycles 
                                    ; + 2 FADCCLK cycles.                               
ADC0TK_ADTK__8_SAR_CLOCKS  EQU 002H ; Post-Tracking time is equal to 8 SAR clock cycles 
                                    ; + 2 FADCCLK cycles.                               
ADC0TK_ADTK__16_SAR_CLOCKS EQU 003H ; Post-Tracking time is equal to 16 SAR clock cycles
                                    ; + 2 FADCCLK cycles.                               
                                                                                        
ADC0TK_ADTM__FMASK         EQU 00CH ; Tracking Mode                                     
ADC0TK_ADTM__SHIFT         EQU 002H ; Tracking Mode                                     
ADC0TK_ADTM__POST_TRACKING EQU 004H ; ADC0 is configured to Post-Tracking Mode.         
ADC0TK_ADTM__PRE_TRACKING  EQU 008H ; ADC0 is configured to Pre-Tracking Mode.          
ADC0TK_ADTM__DUAL_TRACKING EQU 00CH ; ADC0 is configured to Dual-Tracking Mode.         
                                                                                        
ADC0TK_ADPWR__FMASK        EQU 0F0H ; Burst Mode Power Up Time                          
ADC0TK_ADPWR__SHIFT        EQU 004H ; Burst Mode Power Up Time                          
                                                                                        
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
; CLKMUL Enums (Clock Multiplier Control @ 0xAB)
;------------------------------------------------------------------------------
CLKMUL_MULSEL__FMASK            EQU 003H ; Clock Multiplier Input Select                     
CLKMUL_MULSEL__SHIFT            EQU 000H ; Clock Multiplier Input Select                     
CLKMUL_MULSEL__HFOSC_DIV_2      EQU 000H ; Clock Multiplier input clock source is the        
                                         ; Internal High-Frequency Oscillator / 2.           
CLKMUL_MULSEL__EXTOSC           EQU 001H ; Clock Multiplier input clock source is the        
                                         ; External Oscillator.                              
CLKMUL_MULSEL__EXTOSC_DIV_2     EQU 002H ; Clock Multiplier input clock source is the        
                                         ; External Oscillator / 2.                          
CLKMUL_MULSEL__HFOSC            EQU 003H ; Clock Multiplier input clock source is the        
                                         ; Internal High-Frequency Oscillator.               
                                                                                             
CLKMUL_MULDIV__FMASK            EQU 01CH ; Clock Multiplier Output Scaling Factor            
CLKMUL_MULDIV__SHIFT            EQU 002H ; Clock Multiplier Output Scaling Factor            
CLKMUL_MULDIV__DIV_ONE          EQU 000H ; Clock Multiplier Output scaled by a factor of 1.  
CLKMUL_MULDIV__DIV_TWO_THIRDS   EQU 00CH ; Clock Multiplier Output scaled by a factor of 2/3.
CLKMUL_MULDIV__DIV_HALF         EQU 010H ; Clock Multiplier Output scaled by a factor of 2/4 
                                         ; (or 1/2).                                         
CLKMUL_MULDIV__DIV_TWO_FIFTHS   EQU 014H ; Clock Multiplier Output scaled by a factor of 2/5.
CLKMUL_MULDIV__DIV_ONE_THIRD    EQU 018H ; Clock Multiplier Output scaled by a factor of 2/6 
                                         ; (or 1/3).                                         
CLKMUL_MULDIV__DIV_TWO_SEVENTHS EQU 01CH ; Clock Multiplier Output scaled by a factor of 2/7.
                                                                                             
CLKMUL_MULRDY__BMASK            EQU 020H ; Clock Multiplier Ready                            
CLKMUL_MULRDY__SHIFT            EQU 005H ; Clock Multiplier Ready                            
CLKMUL_MULRDY__NOT_SET          EQU 000H ; Clock Multiplier not ready.                       
CLKMUL_MULRDY__SET              EQU 020H ; Clock Multiplier is ready (locked).               
                                                                                             
CLKMUL_MULINIT__BMASK           EQU 040H ; Clock Multiplier Initialize                       
CLKMUL_MULINIT__SHIFT           EQU 006H ; Clock Multiplier Initialize                       
CLKMUL_MULINIT__NOT_SET         EQU 000H ; Do not initialize the Clock Multiplier.           
CLKMUL_MULINIT__SET             EQU 040H ; Initialize the Clock Multiplier.                  
                                                                                             
CLKMUL_MULEN__BMASK             EQU 080H ; Clock Multiplier Enable                           
CLKMUL_MULEN__SHIFT             EQU 007H ; Clock Multiplier Enable                           
CLKMUL_MULEN__DISABLED          EQU 000H ; Disable the Clock Multiplier.                     
CLKMUL_MULEN__ENABLED           EQU 080H ; Enable the Clock Multiplier.                      
                                                                                             
;------------------------------------------------------------------------------
; CLKSEL Enums (Clock Select @ 0xA9)
;------------------------------------------------------------------------------
CLKSEL_CLKSL__FMASK             EQU 003H ; Clock Source Select                               
CLKSEL_CLKSL__SHIFT             EQU 000H ; Clock Source Select                               
CLKSEL_CLKSL__DIVIDED_HFOSC     EQU 000H ; Clock (SYSCLK) derived from the Internal precision
                                         ; High-Frequency Oscillator and scaled per the IFCN 
                                         ; bits in register OSCICN.                          
CLKSEL_CLKSL__EXTOSC            EQU 001H ; Clock (SYSCLK) derived from the External          
                                         ; Oscillator circuit.                               
CLKSEL_CLKSL__CLKMUL            EQU 002H ; Clock (SYSCLK) derived from the Clock Multiplier. 
CLKSEL_CLKSL__RTC               EQU 003H ; Clock (SYSCLK) derived from RTC0.                 
                                                                                             
CLKSEL_CLKDIV__FMASK            EQU 030H ; Output Clock Divider                              
CLKSEL_CLKDIV__SHIFT            EQU 004H ; Output Clock Divider                              
CLKSEL_CLKDIV__SYSCLK_DIV_1_OUT EQU 000H ; Output will be divided by SYSCLK / 1.             
CLKSEL_CLKDIV__SYSCLK_DIV_2_OUT EQU 010H ; Output will be divided by SYSCLK / 2.             
CLKSEL_CLKDIV__SYSCLK_DIV_4_OUT EQU 020H ; Output will be divided by SYSCLK / 4.             
CLKSEL_CLKDIV__SYSCLK_DIV_8_OUT EQU 030H ; Output will be divided by SYSCLK / 8.             
                                                                                             
;------------------------------------------------------------------------------
; CPT0CN Enums (Comparator 0 Control @ 0x9B)
;------------------------------------------------------------------------------
CPT0CN_CPHYN__FMASK                EQU 003H ; Comparator Negative Hysteresis Control            
CPT0CN_CPHYN__SHIFT                EQU 000H ; Comparator Negative Hysteresis Control            
CPT0CN_CPHYN__DISABLED             EQU 000H ; Disable negative hysteresis.                      
CPT0CN_CPHYN__ENABLED_MODE1        EQU 001H ; Negative Hysteresis = Hysteresis 1.               
CPT0CN_CPHYN__ENABLED_MODE2        EQU 002H ; Negative Hysteresis = Hysteresis 2.               
CPT0CN_CPHYN__ENABLED_MODE3        EQU 003H ; Negative Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                
CPT0CN_CPHYP__FMASK                EQU 00CH ; Comparator Positive Hysteresis Control            
CPT0CN_CPHYP__SHIFT                EQU 002H ; Comparator Positive Hysteresis Control            
CPT0CN_CPHYP__DISABLED             EQU 000H ; Disable positive hysteresis.                      
CPT0CN_CPHYP__ENABLED_MODE1        EQU 004H ; Positive Hysteresis = Hysteresis 1.               
CPT0CN_CPHYP__ENABLED_MODE2        EQU 008H ; Positive Hysteresis = Hysteresis 2.               
CPT0CN_CPHYP__ENABLED_MODE3        EQU 00CH ; Positive Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                
CPT0CN_CPFIF__BMASK                EQU 010H ; Comparator Falling-Edge Flag                      
CPT0CN_CPFIF__SHIFT                EQU 004H ; Comparator Falling-Edge Flag                      
CPT0CN_CPFIF__NOT_SET              EQU 000H ; No comparator falling edge has occurred since this
                                            ; flag was last cleared.                            
CPT0CN_CPFIF__FALLING_EDGE         EQU 010H ; Comparator falling edge has occurred.             
                                                                                                
CPT0CN_CPRIF__BMASK                EQU 020H ; Comparator Rising-Edge Flag                       
CPT0CN_CPRIF__SHIFT                EQU 005H ; Comparator Rising-Edge Flag                       
CPT0CN_CPRIF__NOT_SET              EQU 000H ; No comparator rising edge has occurred since this 
                                            ; flag was last cleared.                            
CPT0CN_CPRIF__RISING_EDGE          EQU 020H ; Comparator rising edge has occurred.              
                                                                                                
CPT0CN_CPOUT__BMASK                EQU 040H ; Comparator Output State Flag                      
CPT0CN_CPOUT__SHIFT                EQU 006H ; Comparator Output State Flag                      
CPT0CN_CPOUT__POS_LESS_THAN_NEG    EQU 000H ; Voltage on CP0P < CP0N.                           
CPT0CN_CPOUT__POS_GREATER_THAN_NEG EQU 040H ; Voltage on CP0P > CP0N.                           
                                                                                                
CPT0CN_CPEN__BMASK                 EQU 080H ; Comparator Enable                                 
CPT0CN_CPEN__SHIFT                 EQU 007H ; Comparator Enable                                 
CPT0CN_CPEN__DISABLED              EQU 000H ; Comparator disabled.                              
CPT0CN_CPEN__ENABLED               EQU 080H ; Comparator enabled.                               
                                                                                                
;------------------------------------------------------------------------------
; CPT0MD Enums (Comparator 0 Mode @ 0x9D)
;------------------------------------------------------------------------------
CPT0MD_CPMD__FMASK              EQU 003H ; Comparator Mode Select                      
CPT0MD_CPMD__SHIFT              EQU 000H ; Comparator Mode Select                      
CPT0MD_CPMD__MODE0              EQU 000H ; Mode 0 (Fastest Response Time, Highest Power
                                         ; Consumption)                                
CPT0MD_CPMD__MODE1              EQU 001H ; Mode 1                                      
CPT0MD_CPMD__MODE2              EQU 002H ; Mode 2                                      
CPT0MD_CPMD__MODE3              EQU 003H ; Mode 3 (Slowest Response Time, Lowest Power 
                                         ; Consumption)                                
                                                                                       
CPT0MD_CPFIE__BMASK             EQU 010H ; Comparator Falling-Edge Interrupt Enable    
CPT0MD_CPFIE__SHIFT             EQU 004H ; Comparator Falling-Edge Interrupt Enable    
CPT0MD_CPFIE__FALL_INT_DISABLED EQU 000H ; Comparator falling-edge interrupt disabled. 
CPT0MD_CPFIE__FALL_INT_ENABLED  EQU 010H ; Comparator falling-edge interrupt enabled.  
                                                                                       
CPT0MD_CPRIE__BMASK             EQU 020H ; Comparator Rising-Edge Interrupt Enable     
CPT0MD_CPRIE__SHIFT             EQU 005H ; Comparator Rising-Edge Interrupt Enable     
CPT0MD_CPRIE__RISE_INT_DISABLED EQU 000H ; Comparator rising-edge interrupt disabled.  
CPT0MD_CPRIE__RISE_INT_ENABLED  EQU 020H ; Comparator rising-edge interrupt enabled.   
                                                                                       
;------------------------------------------------------------------------------
; CPT0MX Enums (Comparator 0 Multiplexer Selection @ 0x9F)
;------------------------------------------------------------------------------
CPT0MX_CMXP__FMASK   EQU 00FH ; Comparator Positive Input MUX Selection
CPT0MX_CMXP__SHIFT   EQU 000H ; Comparator Positive Input MUX Selection
CPT0MX_CMXP__CMP0P0  EQU 000H ; External pin CMP0P.0.                  
CPT0MX_CMXP__CMP0P1  EQU 001H ; External pin CMP0P.1.                  
CPT0MX_CMXP__CMP0P2  EQU 002H ; External pin CMP0P.2.                  
CPT0MX_CMXP__CMP0P3  EQU 003H ; External pin CMP0P.3.                  
CPT0MX_CMXP__CMP0P4  EQU 004H ; External pin CMP0P.4.                  
CPT0MX_CMXP__CMP0P5  EQU 005H ; External pin CMP0P.5.                  
CPT0MX_CMXP__CMP0P6  EQU 006H ; External pin CMP0P.6.                  
CPT0MX_CMXP__CMP0P7  EQU 007H ; External pin CMP0P.7.                  
CPT0MX_CMXP__CMP0P8  EQU 008H ; External pin CMP0P.8.                  
CPT0MX_CMXP__CMP0P9  EQU 009H ; External pin CMP0P.9.                  
CPT0MX_CMXP__CMP0P10 EQU 00AH ; External pin CMP0P.10.                 
CPT0MX_CMXP__CMP0P11 EQU 00BH ; External pin CMP0P.11.                 
CPT0MX_CMXP__NONE    EQU 00FH ; No input selected.                     
                                                                       
CPT0MX_CMXN__FMASK   EQU 0F0H ; Comparator Negative Input MUX Selection
CPT0MX_CMXN__SHIFT   EQU 004H ; Comparator Negative Input MUX Selection
CPT0MX_CMXN__CMP0N0  EQU 000H ; External pin CMP0N.0.                  
CPT0MX_CMXN__CMP0N1  EQU 010H ; External pin CMP0N.1.                  
CPT0MX_CMXN__CMP0N2  EQU 020H ; External pin CMP0N.2.                  
CPT0MX_CMXN__CMP0N3  EQU 030H ; External pin CMP0N.3.                  
CPT0MX_CMXN__CMP0N4  EQU 040H ; External pin CMP0N.4.                  
CPT0MX_CMXN__CMP0N5  EQU 050H ; External pin CMP0N.5.                  
CPT0MX_CMXN__CMP0N6  EQU 060H ; External pin CMP0N.6.                  
CPT0MX_CMXN__CMP0N7  EQU 070H ; External pin CMP0N.7.                  
CPT0MX_CMXN__CMP0N8  EQU 080H ; External pin CMP0N.8.                  
CPT0MX_CMXN__CMP0N9  EQU 090H ; External pin CMP0N.9.                  
CPT0MX_CMXN__CMP0N10 EQU 0A0H ; External pin CMP0N.10.                 
CPT0MX_CMXN__CMP0N11 EQU 0B0H ; External pin CMP0N.11.                 
CPT0MX_CMXN__NONE    EQU 0F0H ; No input selected.                     
                                                                       
;------------------------------------------------------------------------------
; CPT1CN Enums (Comparator 1 Control @ 0x9A)
;------------------------------------------------------------------------------
CPT1CN_CPHYN__FMASK                EQU 003H ; Comparator Negative Hysteresis Control            
CPT1CN_CPHYN__SHIFT                EQU 000H ; Comparator Negative Hysteresis Control            
CPT1CN_CPHYN__DISABLED             EQU 000H ; Disable negative hysteresis.                      
CPT1CN_CPHYN__ENABLED_MODE1        EQU 001H ; Negative Hysteresis = Hysteresis 1.               
CPT1CN_CPHYN__ENABLED_MODE2        EQU 002H ; Negative Hysteresis = Hysteresis 2.               
CPT1CN_CPHYN__ENABLED_MODE3        EQU 003H ; Negative Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                
CPT1CN_CPHYP__FMASK                EQU 00CH ; Comparator Positive Hysteresis Control            
CPT1CN_CPHYP__SHIFT                EQU 002H ; Comparator Positive Hysteresis Control            
CPT1CN_CPHYP__DISABLED             EQU 000H ; Disable positive hysteresis.                      
CPT1CN_CPHYP__ENABLED_MODE1        EQU 004H ; Positive Hysteresis = Hysteresis 1.               
CPT1CN_CPHYP__ENABLED_MODE2        EQU 008H ; Positive Hysteresis = Hysteresis 2.               
CPT1CN_CPHYP__ENABLED_MODE3        EQU 00CH ; Positive Hysteresis = Hysteresis 3 (Maximum).     
                                                                                                
CPT1CN_CPFIF__BMASK                EQU 010H ; Comparator Falling-Edge Flag                      
CPT1CN_CPFIF__SHIFT                EQU 004H ; Comparator Falling-Edge Flag                      
CPT1CN_CPFIF__NOT_SET              EQU 000H ; No comparator falling edge has occurred since this
                                            ; flag was last cleared.                            
CPT1CN_CPFIF__FALLING_EDGE         EQU 010H ; Comparator falling edge has occurred.             
                                                                                                
CPT1CN_CPRIF__BMASK                EQU 020H ; Comparator Rising-Edge Flag                       
CPT1CN_CPRIF__SHIFT                EQU 005H ; Comparator Rising-Edge Flag                       
CPT1CN_CPRIF__NOT_SET              EQU 000H ; No comparator rising edge has occurred since this 
                                            ; flag was last cleared.                            
CPT1CN_CPRIF__RISING_EDGE          EQU 020H ; Comparator rising edge has occurred.              
                                                                                                
CPT1CN_CPOUT__BMASK                EQU 040H ; Comparator Output State Flag                      
CPT1CN_CPOUT__SHIFT                EQU 006H ; Comparator Output State Flag                      
CPT1CN_CPOUT__POS_LESS_THAN_NEG    EQU 000H ; Voltage on CP1P < CP1N.                           
CPT1CN_CPOUT__POS_GREATER_THAN_NEG EQU 040H ; Voltage on CP1P > CP1N.                           
                                                                                                
CPT1CN_CPEN__BMASK                 EQU 080H ; Comparator Enable                                 
CPT1CN_CPEN__SHIFT                 EQU 007H ; Comparator Enable                                 
CPT1CN_CPEN__DISABLED              EQU 000H ; Comparator disabled.                              
CPT1CN_CPEN__ENABLED               EQU 080H ; Comparator enabled.                               
                                                                                                
;------------------------------------------------------------------------------
; CPT1MD Enums (Comparator 1 Mode @ 0x9C)
;------------------------------------------------------------------------------
CPT1MD_CPMD__FMASK              EQU 003H ; Comparator Mode Select                      
CPT1MD_CPMD__SHIFT              EQU 000H ; Comparator Mode Select                      
CPT1MD_CPMD__MODE0              EQU 000H ; Mode 0 (Fastest Response Time, Highest Power
                                         ; Consumption)                                
CPT1MD_CPMD__MODE1              EQU 001H ; Mode 1                                      
CPT1MD_CPMD__MODE2              EQU 002H ; Mode 2                                      
CPT1MD_CPMD__MODE3              EQU 003H ; Mode 3 (Slowest Response Time, Lowest Power 
                                         ; Consumption)                                
                                                                                       
CPT1MD_CPFIE__BMASK             EQU 010H ; Comparator Falling-Edge Interrupt Enable    
CPT1MD_CPFIE__SHIFT             EQU 004H ; Comparator Falling-Edge Interrupt Enable    
CPT1MD_CPFIE__FALL_INT_DISABLED EQU 000H ; Comparator falling-edge interrupt disabled. 
CPT1MD_CPFIE__FALL_INT_ENABLED  EQU 010H ; Comparator falling-edge interrupt enabled.  
                                                                                       
CPT1MD_CPRIE__BMASK             EQU 020H ; Comparator Rising-Edge Interrupt Enable     
CPT1MD_CPRIE__SHIFT             EQU 005H ; Comparator Rising-Edge Interrupt Enable     
CPT1MD_CPRIE__RISE_INT_DISABLED EQU 000H ; Comparator rising-edge interrupt disabled.  
CPT1MD_CPRIE__RISE_INT_ENABLED  EQU 020H ; Comparator rising-edge interrupt enabled.   
                                                                                       
;------------------------------------------------------------------------------
; CPT1MX Enums (Comparator 1 Multiplexer Selection @ 0x9E)
;------------------------------------------------------------------------------
CPT1MX_CMXP__FMASK   EQU 00FH ; Comparator Positive Input MUX Selection
CPT1MX_CMXP__SHIFT   EQU 000H ; Comparator Positive Input MUX Selection
CPT1MX_CMXP__CMP1P0  EQU 000H ; External pin CMP1P.0.                  
CPT1MX_CMXP__CMP1P1  EQU 001H ; External pin CMP1P.1.                  
CPT1MX_CMXP__CMP1P2  EQU 002H ; External pin CMP1P.2.                  
CPT1MX_CMXP__CMP1P3  EQU 003H ; External pin CMP1P.3.                  
CPT1MX_CMXP__CMP1P4  EQU 004H ; External pin CMP1P.4.                  
CPT1MX_CMXP__CMP1P5  EQU 005H ; External pin CMP1P.5.                  
CPT1MX_CMXP__CMP1P6  EQU 006H ; External pin CMP1P.6.                  
CPT1MX_CMXP__CMP1P7  EQU 007H ; External pin CMP1P.7.                  
CPT1MX_CMXP__CMP1P8  EQU 008H ; External pin CMP1P.8.                  
CPT1MX_CMXP__CMP1P9  EQU 009H ; External pin CMP1P.9.                  
CPT1MX_CMXP__CMP1P10 EQU 00AH ; External pin CMP1P.10.                 
CPT1MX_CMXP__CMP1P11 EQU 00BH ; External pin CMP1P.11.                 
CPT1MX_CMXP__NONE    EQU 00FH ; No input selected.                     
                                                                       
CPT1MX_CMXN__FMASK   EQU 0F0H ; Comparator Negative Input MUX Selection
CPT1MX_CMXN__SHIFT   EQU 004H ; Comparator Negative Input MUX Selection
CPT1MX_CMXN__CMP1N0  EQU 000H ; External pin CMP1N.0.                  
CPT1MX_CMXN__CMP1N1  EQU 010H ; External pin CMP1N.1.                  
CPT1MX_CMXN__CMP1N2  EQU 020H ; External pin CMP1N.2.                  
CPT1MX_CMXN__CMP1N3  EQU 030H ; External pin CMP1N.3.                  
CPT1MX_CMXN__CMP1N4  EQU 040H ; External pin CMP1N.4.                  
CPT1MX_CMXN__CMP1N5  EQU 050H ; External pin CMP1N.5.                  
CPT1MX_CMXN__CMP1N6  EQU 060H ; External pin CMP1N.6.                  
CPT1MX_CMXN__CMP1N7  EQU 070H ; External pin CMP1N.7.                  
CPT1MX_CMXN__CMP1N8  EQU 080H ; External pin CMP1N.8.                  
CPT1MX_CMXN__CMP1N9  EQU 090H ; External pin CMP1N.9.                  
CPT1MX_CMXN__CMP1N10 EQU 0A0H ; External pin CMP1N.10.                 
CPT1MX_CMXN__CMP1N11 EQU 0B0H ; External pin CMP1N.11.                 
CPT1MX_CMXN__NONE    EQU 0F0H ; No input selected.                     
                                                                       
;------------------------------------------------------------------------------
; CRC0CN Enums (CRC0 Control @ 0x84)
;------------------------------------------------------------------------------
CRC0CN_CRCPNT__FMASK        EQU 003H ; CRC Result Pointer                                
CRC0CN_CRCPNT__SHIFT        EQU 000H ; CRC Result Pointer                                
CRC0CN_CRCPNT__ACCESS_B0    EQU 000H ; CRC0DAT accesses bits 7-0 of the 16-bit or 32-bit 
                                     ; CRC result.                                       
CRC0CN_CRCPNT__ACCESS_B1    EQU 001H ; CRC0DAT accesses bits 15-8 of the 16-bit or 32-bit
                                     ; CRC result.                                       
CRC0CN_CRCPNT__ACCESS_B2    EQU 002H ; CRC0DAT accesses bits 7-0 of the 16-bit or bits   
                                     ; 23-15 of the 32-bit CRC result.                   
CRC0CN_CRCPNT__ACCESS_B3    EQU 003H ; CRC0DAT accesses bits 15-8 of the 16-bit or bits  
                                     ; 31-24 of the 32-bit CRC result.                   
                                                                                         
CRC0CN_CRCVAL__BMASK        EQU 004H ; CRC Initialization Value                          
CRC0CN_CRCVAL__SHIFT        EQU 002H ; CRC Initialization Value                          
CRC0CN_CRCVAL__SET_ZEROES   EQU 000H ; CRC result is set to 0x00000000 on write of 1 to  
                                     ; CRCINIT.                                          
CRC0CN_CRCVAL__SET_ONES     EQU 004H ; CRC result is set to 0xFFFFFFFF on write of 1 to  
                                     ; CRCINIT.                                          
                                                                                         
CRC0CN_CRCINIT__BMASK       EQU 008H ; CRC Initialization Enable                         
CRC0CN_CRCINIT__SHIFT       EQU 003H ; CRC Initialization Enable                         
CRC0CN_CRCINIT__DO_NOT_INIT EQU 000H ; Do not initialize the CRC result.                 
CRC0CN_CRCINIT__INIT        EQU 008H ; Initialize the CRC result to ones or zeroes vased 
                                     ; on the value of CRCVAL.                           
                                                                                         
CRC0CN_POLYSEL__BMASK       EQU 010H ; CRC Polynomial Select Bit                         
CRC0CN_POLYSEL__SHIFT       EQU 004H ; CRC Polynomial Select Bit                         
CRC0CN_POLYSEL__32_BIT      EQU 000H ; Use the 32-bit polynomial 0x04C11DB7 for          
                                     ; calculating the CRC result.                       
CRC0CN_POLYSEL__16_BIT      EQU 010H ; Use the 16-bit polynomial 0x1021 for calculating  
                                     ; the CRC result.                                   
                                                                                         
;------------------------------------------------------------------------------
; CRC0DAT Enums (CRC0 Data Output @ 0x86)
;------------------------------------------------------------------------------
CRC0DAT_CRC0DAT__FMASK EQU 0FFH ; CRC Data Output
CRC0DAT_CRC0DAT__SHIFT EQU 000H ; CRC Data Output
                                                 
;------------------------------------------------------------------------------
; CRC0FLIP Enums (CRC0 Bit Flip @ 0xDF)
;------------------------------------------------------------------------------
CRC0FLIP_CRC0FLIP__FMASK EQU 0FFH ; CRC0 Bit Flip
CRC0FLIP_CRC0FLIP__SHIFT EQU 000H ; CRC0 Bit Flip
                                                 
;------------------------------------------------------------------------------
; CRC0IN Enums (CRC0 Data Input @ 0x85)
;------------------------------------------------------------------------------
CRC0IN_CRC0IN__FMASK EQU 0FFH ; CRC Data Input
CRC0IN_CRC0IN__SHIFT EQU 000H ; CRC Data Input
                                              
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
; OSCXCN Enums (External Oscillator Control @ 0xB1)
;------------------------------------------------------------------------------
OSCXCN_XFCN__FMASK           EQU 007H ; External Oscillator Frequency Control           
OSCXCN_XFCN__SHIFT           EQU 000H ; External Oscillator Frequency Control           
OSCXCN_XFCN__MODE0           EQU 000H ; Select external oscillator mode 0: Crystal      
                                      ; frequency <= 20 kHz, RC/C frequency <= 25 kHz, C
                                      ; mode K factor = 0.87.                           
OSCXCN_XFCN__MODE1           EQU 001H ; Select external oscillator mode 1: 20 kHz <     
                                      ; Crystal frequency <= 58 kHz, 25 kHz < RC/C      
                                      ; frequency <= 50 kHz, C mode K factor = 2.6.     
OSCXCN_XFCN__MODE2           EQU 002H ; Select external oscillator mode 2: 58 kHz <     
                                      ; Crystal frequency <= 155 kHz, 50 kHz < RC/C     
                                      ; frequency <= 100 kHz, C mode K factor = 7.7.    
OSCXCN_XFCN__MODE3           EQU 003H ; Select external oscillator mode 3: 155 kHz <    
                                      ; Crystal frequency <= 415 kHz, 100 kHz < RC/C    
                                      ; frequency <= 200 kHz, C mode K factor = 22.     
OSCXCN_XFCN__MODE4           EQU 004H ; Select external oscillator mode 4: 415 kHz <    
                                      ; Crystal frequency <= 1.1 MHz, 200 kHz < RC/C    
                                      ; frequency <= 400 kHz, C mode K factor = 65.     
OSCXCN_XFCN__MODE5           EQU 005H ; Select external oscillator mode 5: 1.1 MHz <    
                                      ; Crystal frequency <= 3.1 MHz, 400 kHz < RC/C    
                                      ; frequency <= 800 kHz, C mode K factor = 180.    
OSCXCN_XFCN__MODE6           EQU 006H ; Select external oscillator mode 6: 3.1 MHz <    
                                      ; Crystal frequency <= 8.2 MHz, 800 kHz < RC/C    
                                      ; frequency <= 1.6 MHz, C mode K factor = 664.    
OSCXCN_XFCN__MODE7           EQU 007H ; Select external oscillator mode 7: 8.2 MHz <    
                                      ; Crystal frequency <= 25 MHz, 1.6 MHz < RC/C     
                                      ; frequency <= 3.2 MHz, C mode K factor = 1590.   
                                                                                        
OSCXCN_XOSCMD__FMASK         EQU 070H ; External Oscillator Mode                        
OSCXCN_XOSCMD__SHIFT         EQU 004H ; External Oscillator Mode                        
OSCXCN_XOSCMD__DISABLED      EQU 000H ; External Oscillator circuit disabled.           
OSCXCN_XOSCMD__CMOS          EQU 020H ; External CMOS Clock Mode.                       
OSCXCN_XOSCMD__CMOS_DIV_2    EQU 030H ; External CMOS Clock Mode with divide by 2 stage.
OSCXCN_XOSCMD__RC            EQU 040H ; RC Oscillator Mode.                             
OSCXCN_XOSCMD__C             EQU 050H ; Capacitor Oscillator Mode.                      
OSCXCN_XOSCMD__CRYSTAL       EQU 060H ; Crystal Oscillator Mode.                        
OSCXCN_XOSCMD__CRYSTAL_DIV_2 EQU 070H ; Crystal Oscillator Mode with divide by 2 stage. 
                                                                                        
OSCXCN_XTLVLD__BMASK         EQU 080H ; Crystal Oscillator Valid Flag                   
OSCXCN_XTLVLD__SHIFT         EQU 007H ; Crystal Oscillator Valid Flag                   
OSCXCN_XTLVLD__NOT_SET       EQU 000H ; External crystal is unused or not yet stable.   
OSCXCN_XTLVLD__SET           EQU 080H ; External crystal is running and stable.         
                                                                                        
;------------------------------------------------------------------------------
; FLKEY Enums (Flash Lock and Key @ 0xB7)
;------------------------------------------------------------------------------
FLKEY_FLKEY__FMASK    EQU 0FFH ; Flash Lock and Key Register                       
FLKEY_FLKEY__SHIFT    EQU 000H ; Flash Lock and Key Register                       
FLKEY_FLKEY__LOCKED   EQU 000H ; Flash is write/erase locked.                      
FLKEY_FLKEY__FIRST    EQU 001H ; The first key code has been written (0xA5).       
FLKEY_FLKEY__UNLOCKED EQU 002H ; Flash is unlocked (writes/erases allowed).        
FLKEY_FLKEY__DISABLED EQU 003H ; Flash writes/erases disabled until the next reset.
FLKEY_FLKEY__KEY1     EQU 0A5H ; Flash writes and erases are enabled by writing    
                               ; 0xA5 followed by 0xF1 to the FLKEY register.      
FLKEY_FLKEY__KEY2     EQU 0F1H ; Flash writes and erases are enabled by writing    
                               ; 0xA5 followed by 0xF1 to the FLKEY register.      
                                                                                   
;------------------------------------------------------------------------------
; FLSCL Enums (Flash Scale @ 0xB6)
;------------------------------------------------------------------------------
FLSCL_FLRT__BMASK               EQU 010H ; Flash Read Timing
FLSCL_FLRT__SHIFT               EQU 004H ; Flash Read Timing
FLSCL_FLRT__SYSCLK_BELOW_25_MHZ EQU 000H ; SYSCLK <= 25 MHz.
FLSCL_FLRT__SYSCLK_BELOW_50_MHZ EQU 010H ; SYSCLK <= 50 MHz.
                                                            
;------------------------------------------------------------------------------
; ONESHOT Enums (Flash Oneshot Period @ 0xAF)
;------------------------------------------------------------------------------
ONESHOT_PERIOD__FMASK EQU 00FH ; Oneshot Period Control
ONESHOT_PERIOD__SHIFT EQU 000H ; Oneshot Period Control
                                                       
;------------------------------------------------------------------------------
; PFE0CN Enums (Prefetch Engine Control @ 0xE3)
;------------------------------------------------------------------------------
PFE0CN_FLBWE__BMASK                EQU 001H ; Flash Block Write Enable                       
PFE0CN_FLBWE__SHIFT                EQU 000H ; Flash Block Write Enable                       
PFE0CN_FLBWE__BLOCK_WRITE_DISABLED EQU 000H ; Each byte of a firmware flash write is written 
                                            ; individually.                                  
PFE0CN_FLBWE__BLOCK_WRITE_ENABLED  EQU 001H ; Flash bytes are written in groups of two.      
                                                                                             
PFE0CN_PFEN__BMASK                 EQU 020H ; Prefetch Enable                                
PFE0CN_PFEN__SHIFT                 EQU 005H ; Prefetch Enable                                
PFE0CN_PFEN__DISABLED              EQU 000H ; Disable the prefetch engine (SYSCLK <= 25 MHz).
PFE0CN_PFEN__ENABLED               EQU 020H ; Enable the prefetch engine (SYSCLK > 25 MHz).  
                                                                                             
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
; OSCICL Enums (High Frequency Oscillator Calibration @ 0xB3)
;------------------------------------------------------------------------------
OSCICL_OSCICL__FMASK EQU 07FH ; Internal Oscillator Calibration
OSCICL_OSCICL__SHIFT EQU 000H ; Internal Oscillator Calibration
                                                               
;------------------------------------------------------------------------------
; OSCICN Enums (High Frequency Oscillator Control @ 0xB2)
;------------------------------------------------------------------------------
OSCICN_IFCN__FMASK         EQU 007H ; Oscillator Frequency Divider Control             
OSCICN_IFCN__SHIFT         EQU 000H ; Oscillator Frequency Divider Control             
OSCICN_IFCN__HFOSC_DIV_128 EQU 000H ; SYSCLK derived from High Frequency Oscillator    
                                    ; divided by 128.                                  
OSCICN_IFCN__HFOSC_DIV_64  EQU 001H ; SYSCLK derived from High Frequency Oscillator    
                                    ; divided by 64.                                   
OSCICN_IFCN__HFOSC_DIV_32  EQU 002H ; SYSCLK derived from High Frequency Oscillator    
                                    ; divided by 32.                                   
OSCICN_IFCN__HFOSC_DIV_16  EQU 003H ; SYSCLK derived from High Frequency Oscillator    
                                    ; divided by 16.                                   
OSCICN_IFCN__HFOSC_DIV_8   EQU 004H ; SYSCLK derived from High Frequency Oscillator    
                                    ; divided by 8.                                    
OSCICN_IFCN__HFOSC_DIV_4   EQU 005H ; SYSCLK derived from High Frequency Oscillator    
                                    ; divided by 4.                                    
OSCICN_IFCN__HFOSC_DIV_2   EQU 006H ; SYSCLK derived from High Frequency Oscillator    
                                    ; divided by 2.                                    
OSCICN_IFCN__HFOSC_DIV_1   EQU 007H ; SYSCLK derived from High Frequency Oscillator    
                                    ; divided by 1.                                    
                                                                                       
OSCICN_SUSPEND__BMASK      EQU 020H ; Oscillator Suspend Enable                        
OSCICN_SUSPEND__SHIFT      EQU 005H ; Oscillator Suspend Enable                        
OSCICN_SUSPEND__DISABLED   EQU 000H ; The internal oscillator is not in suspend mode.  
OSCICN_SUSPEND__ENABLED    EQU 020H ; Place the internal oscillator in suspend mode.   
                                                                                       
OSCICN_IFRDY__BMASK        EQU 040H ; Oscillator Frequency Ready Flag                  
OSCICN_IFRDY__SHIFT        EQU 006H ; Oscillator Frequency Ready Flag                  
OSCICN_IFRDY__NOT_SET      EQU 000H ; The Internal High Frequency Oscillator is not    
                                    ; running at the programmed frequency.             
OSCICN_IFRDY__SET          EQU 040H ; The Internal High Frequency Oscillator is running
                                    ; at the programmed frequency.                     
                                                                                       
OSCICN_IOSCEN__BMASK       EQU 080H ; Oscillator Enable                                
OSCICN_IOSCEN__SHIFT       EQU 007H ; Oscillator Enable                                
OSCICN_IOSCEN__DISABLED    EQU 000H ; Disable the High Frequency Oscillator.           
OSCICN_IOSCEN__ENABLED     EQU 080H ; Enable the High Frequency Oscillator.            
                                                                                       
;------------------------------------------------------------------------------
; IDA0CN Enums (IDAC0 Control @ 0xB9)
;------------------------------------------------------------------------------
IDA0CN_IDAOMD__FMASK              EQU 003H ; Output Mode Select                           
IDA0CN_IDAOMD__SHIFT              EQU 000H ; Output Mode Select                           
IDA0CN_IDAOMD__0P25_MA            EQU 000H ; 0.25 mA full-scale output current.           
IDA0CN_IDAOMD__0P5_MA             EQU 001H ; 0.5 mA full-scale output current.            
IDA0CN_IDAOMD__1_MA               EQU 002H ; 1.0 mA full-scale output current.            
IDA0CN_IDAOMD__2_MA               EQU 003H ; 2.0 mA full-scale output current.            
                                                                                          
IDA0CN_IDARJST__BMASK             EQU 004H ; Right Justification Select                   
IDA0CN_IDARJST__SHIFT             EQU 002H ; Right Justification Select                   
IDA0CN_IDARJST__DISABLED          EQU 000H ; IDAC0 data in IDA0H:L is left-justified.     
IDA0CN_IDARJST__ENABLED           EQU 004H ; IDAC0 data in IDA0H:L is right-justified.    
                                                                                          
IDA0CN_IDACM__FMASK               EQU 070H ; Update Source Select                         
IDA0CN_IDACM__SHIFT               EQU 004H ; Update Source Select                         
IDA0CN_IDACM__TIMER0              EQU 000H ; DAC output updates on Timer 0 overflow.      
IDA0CN_IDACM__TIMER1              EQU 010H ; DAC output updates on Timer 1 overflow.      
IDA0CN_IDACM__TIMER2              EQU 020H ; DAC output updates on Timer 2 overflow.      
IDA0CN_IDACM__TIMER3              EQU 030H ; DAC output updates on Timer 3 overflow.      
IDA0CN_IDACM__CNVSTR_RISING_EDGE  EQU 040H ; DAC output updates on rising edge of CNVSTR. 
IDA0CN_IDACM__CNVSTR_FALLING_EDGE EQU 050H ; DAC output updates on falling edge of CNVSTR.
IDA0CN_IDACM__CNVSTR_ANY_EDGE     EQU 060H ; DAC output updates on any edge of CNVSTR.    
IDA0CN_IDACM__IDA0H               EQU 070H ; DAC output updates on write to IDA0H.        
                                                                                          
IDA0CN_IDAEN__BMASK               EQU 080H ; IDAC Enable                                  
IDA0CN_IDAEN__SHIFT               EQU 007H ; IDAC Enable                                  
IDA0CN_IDAEN__DISABLED            EQU 000H ; Disable IDAC0.                               
IDA0CN_IDAEN__ENABLED             EQU 080H ; Enable IDAC0.                                
                                                                                          
;------------------------------------------------------------------------------
; IDA0H Enums (IDAC0 Data High Byte @ 0x97)
;------------------------------------------------------------------------------
IDA0H_IDA0__FMASK EQU 0FFH ; IDAC0 Data High
IDA0H_IDA0__SHIFT EQU 000H ; IDAC0 Data High
                                            
;------------------------------------------------------------------------------
; IDA0L Enums (IDAC0 Data Low Byte @ 0x96)
;------------------------------------------------------------------------------
IDA0L_IDA0__FMASK EQU 0FFH ; IDA0 Data Low
IDA0L_IDA0__SHIFT EQU 000H ; IDA0 Data Low
                                          
;------------------------------------------------------------------------------
; IDA1CN Enums (IDAC1 Control @ 0xB5)
;------------------------------------------------------------------------------
IDA1CN_IDAOMD__FMASK              EQU 003H ; Output Mode Select                           
IDA1CN_IDAOMD__SHIFT              EQU 000H ; Output Mode Select                           
IDA1CN_IDAOMD__0P25_MA            EQU 000H ; 0.25 mA full-scale output current.           
IDA1CN_IDAOMD__0P5_MA             EQU 001H ; 0.5 mA full-scale output current.            
IDA1CN_IDAOMD__1_MA               EQU 002H ; 1.0 mA full-scale output current.            
IDA1CN_IDAOMD__2_MA               EQU 003H ; 2.0 mA full-scale output current.            
                                                                                          
IDA1CN_IDARJST__BMASK             EQU 004H ; Right Justification Select                   
IDA1CN_IDARJST__SHIFT             EQU 002H ; Right Justification Select                   
IDA1CN_IDARJST__DISABLED          EQU 000H ; IDAC1 data in IDA1H:L is left-justified.     
IDA1CN_IDARJST__ENABLED           EQU 004H ; IDAC1 data in IDA1H:L is right-justified.    
                                                                                          
IDA1CN_IDACM__FMASK               EQU 070H ; Update Source Select                         
IDA1CN_IDACM__SHIFT               EQU 004H ; Update Source Select                         
IDA1CN_IDACM__TIMER0              EQU 000H ; DAC output updates on Timer 0 overflow.      
IDA1CN_IDACM__TIMER1              EQU 010H ; DAC output updates on Timer 1 overflow.      
IDA1CN_IDACM__TIMER2              EQU 020H ; DAC output updates on Timer 2 overflow.      
IDA1CN_IDACM__TIMER3              EQU 030H ; DAC output updates on Timer 3 overflow.      
IDA1CN_IDACM__CNVSTR_RISING_EDGE  EQU 040H ; DAC output updates on rising edge of CNVSTR. 
IDA1CN_IDACM__CNVSTR_FALLING_EDGE EQU 050H ; DAC output updates on falling edge of CNVSTR.
IDA1CN_IDACM__CNVSTR_ANY_EDGE     EQU 060H ; DAC output updates on any edge of CNVSTR.    
IDA1CN_IDACM__IDA1H               EQU 070H ; DAC output updates on write to IDA1H.        
                                                                                          
IDA1CN_IDAEN__BMASK               EQU 080H ; IDAC Enable                                  
IDA1CN_IDAEN__SHIFT               EQU 007H ; IDAC Enable                                  
IDA1CN_IDAEN__DISABLED            EQU 000H ; Disable IDAC1.                               
IDA1CN_IDAEN__ENABLED             EQU 080H ; Enable IDAC1.                                
                                                                                          
;------------------------------------------------------------------------------
; IDA1H Enums (IDAC1 Data High Byte @ 0xF5)
;------------------------------------------------------------------------------
IDA1H_IDA1__FMASK EQU 0FFH ; IDAC1 Data High
IDA1H_IDA1__SHIFT EQU 000H ; IDAC1 Data High
                                            
;------------------------------------------------------------------------------
; IDA1L Enums (IDAC1 Data Low Byte @ 0xF4)
;------------------------------------------------------------------------------
IDA1L_IDA1__FMASK EQU 0FFH ; IDA1 Data Low
IDA1L_IDA1__SHIFT EQU 000H ; IDA1 Data Low
                                          
;------------------------------------------------------------------------------
; EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
;------------------------------------------------------------------------------
EIE1_ESMB0__BMASK     EQU 001H ; SMBus (SMB0) Interrupt Enable                     
EIE1_ESMB0__SHIFT     EQU 000H ; SMBus (SMB0) Interrupt Enable                     
EIE1_ESMB0__DISABLED  EQU 000H ; Disable all SMB0 interrupts.                      
EIE1_ESMB0__ENABLED   EQU 001H ; Enable interrupt requests generated by SMB0.      
                                                                                   
EIE1_ERTC0__BMASK     EQU 002H ; RTC0 Interrupt Enable                             
EIE1_ERTC0__SHIFT     EQU 001H ; RTC0 Interrupt Enable                             
EIE1_ERTC0__DISABLED  EQU 000H ; Disable RTC0 interrupts.                          
EIE1_ERTC0__ENABLED   EQU 002H ; Enable interrupt requests generated by the RTC0   
                               ; Alarm and  Oscillator Fail events.                
                                                                                   
EIE1_EWADC0__BMASK    EQU 004H ; Window Comparison ADC0 Interrupt Enable           
EIE1_EWADC0__SHIFT    EQU 002H ; Window Comparison ADC0 Interrupt Enable           
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
; EIE2 Enums (Extended Interrupt Enable 2 @ 0xE7)
;------------------------------------------------------------------------------
EIE2_EREG0__BMASK    EQU 001H ; Voltage Regulator Interrupt Enable                
EIE2_EREG0__SHIFT    EQU 000H ; Voltage Regulator Interrupt Enable                
EIE2_EREG0__DISABLED EQU 000H ; Disable the Voltage Regulator dropout interrupt.  
EIE2_EREG0__ENABLED  EQU 001H ; Enable interrupt requests generated by the Voltage
                              ; Regulator.                                        
                                                                                  
EIE2_EMAT__BMASK     EQU 002H ; Port Match Interrupts Enable                      
EIE2_EMAT__SHIFT     EQU 001H ; Port Match Interrupts Enable                      
EIE2_EMAT__DISABLED  EQU 000H ; Disable all Port Match interrupts.                
EIE2_EMAT__ENABLED   EQU 002H ; Enable interrupt requests generated by a Port     
                              ; Match.                                            
                                                                                  
;------------------------------------------------------------------------------
; EIP1 Enums (Extended Interrupt Priority 1 @ 0xF6)
;------------------------------------------------------------------------------
EIP1_PSMB0__BMASK  EQU 001H ; SMBus (SMB0) Interrupt Priority Control                     
EIP1_PSMB0__SHIFT  EQU 000H ; SMBus (SMB0) Interrupt Priority Control                     
EIP1_PSMB0__LOW    EQU 000H ; SMB0 interrupt set to low priority level.                   
EIP1_PSMB0__HIGH   EQU 001H ; SMB0 interrupt set to high priority level.                  
                                                                                          
EIP1_PRTC0__BMASK  EQU 002H ; RTC0 Interrupt Priority Control                             
EIP1_PRTC0__SHIFT  EQU 001H ; RTC0 Interrupt Priority Control                             
EIP1_PRTC0__LOW    EQU 000H ; RTC0 interrupts set to low priority level.                  
EIP1_PRTC0__HIGH   EQU 002H ; RTC0 interrupts set to high priority level.                 
                                                                                          
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
; EIP2 Enums (Extended Interrupt Priority 2 @ 0xF7)
;------------------------------------------------------------------------------
EIP2_PREG0__BMASK EQU 001H ; Voltage Regulator Interrupt Priority Control    
EIP2_PREG0__SHIFT EQU 000H ; Voltage Regulator Interrupt Priority Control    
EIP2_PREG0__LOW   EQU 000H ; Voltage Regulator dropout interrupt set to low  
                           ; priority level.                                 
EIP2_PREG0__HIGH  EQU 001H ; Voltage Regulator dropout interrupt set to high 
                           ; priority level.                                 
                                                                             
EIP2_PMAT__BMASK  EQU 002H ; Port Match Interrupt Priority Control           
EIP2_PMAT__SHIFT  EQU 001H ; Port Match Interrupt Priority Control           
EIP2_PMAT__LOW    EQU 000H ; Port Match interrupt set to low priority level. 
EIP2_PMAT__HIGH   EQU 002H ; Port Match interrupt set to high priority level.
                                                                             
;------------------------------------------------------------------------------
; IE Enums (Interrupt Enable @ 0xA8)
;------------------------------------------------------------------------------
IE_EX0__BMASK      EQU 001H ; External Interrupt 0 Enable                       
IE_EX0__SHIFT      EQU 000H ; External Interrupt 0 Enable                       
IE_EX0__DISABLED   EQU 000H ; Disable external interrupt 0.                     
IE_EX0__ENABLED    EQU 001H ; Enable interrupt requests generated by the /INT0  
                            ; input.                                            
                                                                                
IE_ET0__BMASK      EQU 002H ; Timer 0 Interrupt Enable                          
IE_ET0__SHIFT      EQU 001H ; Timer 0 Interrupt Enable                          
IE_ET0__DISABLED   EQU 000H ; Disable all Timer 0 interrupt.                    
IE_ET0__ENABLED    EQU 002H ; Enable interrupt requests generated by the TF0    
                            ; flag.                                             
                                                                                
IE_EX1__BMASK      EQU 004H ; External Interrupt 1 Enable                       
IE_EX1__SHIFT      EQU 002H ; External Interrupt 1 Enable                       
IE_EX1__DISABLED   EQU 000H ; Disable external interrupt 1.                     
IE_EX1__ENABLED    EQU 004H ; Enable interrupt requests generated by the /INT1  
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
                                                                               
XBR0_SMB0E__BMASK     EQU 004H ; SMBus0 I/O Enable                             
XBR0_SMB0E__SHIFT     EQU 002H ; SMBus0 I/O Enable                             
XBR0_SMB0E__DISABLED  EQU 000H ; SMBus0 I/O unavailable at Port pins.          
XBR0_SMB0E__ENABLED   EQU 004H ; SMBus0 I/O routed to Port pins.               
                                                                               
XBR0_SYSCKE__BMASK    EQU 008H ; SYSCLK Output Enable                          
XBR0_SYSCKE__SHIFT    EQU 003H ; SYSCLK Output Enable                          
XBR0_SYSCKE__DISABLED EQU 000H ; SYSCLK unavailable at Port pin.               
XBR0_SYSCKE__ENABLED  EQU 008H ; SYSCLK output routed to Port pin.             
                                                                               
XBR0_CP0E__BMASK      EQU 010H ; Comparator0 Output Enable                     
XBR0_CP0E__SHIFT      EQU 004H ; Comparator0 Output Enable                     
XBR0_CP0E__DISABLED   EQU 000H ; CP0 unavailable at Port pin.                  
XBR0_CP0E__ENABLED    EQU 010H ; CP0 routed to Port pin.                       
                                                                               
XBR0_CP0AE__BMASK     EQU 020H ; Comparator0 Asynchronous Output Enable        
XBR0_CP0AE__SHIFT     EQU 005H ; Comparator0 Asynchronous Output Enable        
XBR0_CP0AE__DISABLED  EQU 000H ; Asynchronous CP0 unavailable at Port pin.     
XBR0_CP0AE__ENABLED   EQU 020H ; Asynchronous CP0 routed to Port pin.          
                                                                               
XBR0_CP1E__BMASK      EQU 040H ; Comparator1 Output Enable                     
XBR0_CP1E__SHIFT      EQU 006H ; Comparator1 Output Enable                     
XBR0_CP1E__DISABLED   EQU 000H ; CP1 unavailable at Port pin.                  
XBR0_CP1E__ENABLED    EQU 040H ; CP1 routed to Port pin.                       
                                                                               
XBR0_CP1AE__BMASK     EQU 080H ; Comparator1 Asynchronous Output Enable        
XBR0_CP1AE__SHIFT     EQU 007H ; Comparator1 Asynchronous Output Enable        
XBR0_CP1AE__DISABLED  EQU 000H ; Asynchronous CP1 unavailable at Port pin.     
XBR0_CP1AE__ENABLED   EQU 080H ; Asynchronous CP1 routed to Port pin.          
                                                                               
;------------------------------------------------------------------------------
; XBR1 Enums (Port I/O Crossbar 1 @ 0xE2)
;------------------------------------------------------------------------------
XBR1_PCA0ME__FMASK                         EQU 007H ; PCA Module I/O Enable                            
XBR1_PCA0ME__SHIFT                         EQU 000H ; PCA Module I/O Enable                            
XBR1_PCA0ME__DISABLED                      EQU 000H ; All PCA I/O unavailable at Port pins.            
XBR1_PCA0ME__CEX0                          EQU 001H ; CEX0 routed to Port pin.                         
XBR1_PCA0ME__CEX0_CEX1                     EQU 002H ; CEX0, CEX1 routed to Port pins.                  
XBR1_PCA0ME__CEX0_CEX1_CEX2                EQU 003H ; CEX0, CEX1, CEX2 routed to Port pins.            
XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3           EQU 004H ; CEX0, CEX1, CEX2 CEX3 routed to Port pins.       
XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4      EQU 005H ; CEX0, CEX1, CEX2, CEX3, CEX4 routed to Port pins.
XBR1_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4_CEX5 EQU 006H ; CEX0, CEX1, CEX2, CEX3, CEX4, CEX5 routed to Port
                                                    ; pins.                                            
                                                                                                       
XBR1_ECIE__BMASK                           EQU 008H ; PCA0 External Counter Input Enable               
XBR1_ECIE__SHIFT                           EQU 003H ; PCA0 External Counter Input Enable               
XBR1_ECIE__DISABLED                        EQU 000H ; ECI unavailable at Port pin.                     
XBR1_ECIE__ENABLED                         EQU 008H ; ECI routed to Port pin.                          
                                                                                                       
XBR1_T0E__BMASK                            EQU 010H ; T0 Enable                                        
XBR1_T0E__SHIFT                            EQU 004H ; T0 Enable                                        
XBR1_T0E__DISABLED                         EQU 000H ; T0 unavailable at Port pin.                      
XBR1_T0E__ENABLED                          EQU 010H ; T0 routed to Port pin.                           
                                                                                                       
XBR1_T1E__BMASK                            EQU 020H ; T1 Enable                                        
XBR1_T1E__SHIFT                            EQU 005H ; T1 Enable                                        
XBR1_T1E__DISABLED                         EQU 000H ; T1 unavailable at Port pin.                      
XBR1_T1E__ENABLED                          EQU 020H ; T1 routed to Port pin.                           
                                                                                                       
XBR1_XBARE__BMASK                          EQU 040H ; Crossbar Enable                                  
XBR1_XBARE__SHIFT                          EQU 006H ; Crossbar Enable                                  
XBR1_XBARE__DISABLED                       EQU 000H ; Crossbar disabled.                               
XBR1_XBARE__ENABLED                        EQU 040H ; Crossbar enabled.                                
                                                                                                       
XBR1_WEAKPUD__BMASK                        EQU 080H ; Port I/O Weak Pullup Disable                     
XBR1_WEAKPUD__SHIFT                        EQU 007H ; Port I/O Weak Pullup Disable                     
XBR1_WEAKPUD__PULL_UPS_ENABLED             EQU 000H ; Weak Pullups enabled (except for Ports whose I/O 
                                                    ; are configured for analog mode).                 
XBR1_WEAKPUD__PULL_UPS_DISABLED            EQU 080H ; Weak Pullups disabled.                           
                                                                                                       
;------------------------------------------------------------------------------
; PCA0CN Enums (PCA Control @ 0xD8)
;------------------------------------------------------------------------------
PCA0CN_CCF0__BMASK   EQU 001H ; PCA Module 0 Capture/Compare Flag             
PCA0CN_CCF0__SHIFT   EQU 000H ; PCA Module 0 Capture/Compare Flag             
PCA0CN_CCF0__NOT_SET EQU 000H ; A match or capture did not occur on channel 0.
PCA0CN_CCF0__SET     EQU 001H ; A match or capture occurred on channel 0.     
                                                                              
PCA0CN_CCF1__BMASK   EQU 002H ; PCA Module 1 Capture/Compare Flag             
PCA0CN_CCF1__SHIFT   EQU 001H ; PCA Module 1 Capture/Compare Flag             
PCA0CN_CCF1__NOT_SET EQU 000H ; A match or capture did not occur on channel 1.
PCA0CN_CCF1__SET     EQU 002H ; A match or capture occurred on channel 1.     
                                                                              
PCA0CN_CCF2__BMASK   EQU 004H ; PCA Module 2 Capture/Compare Flag             
PCA0CN_CCF2__SHIFT   EQU 002H ; PCA Module 2 Capture/Compare Flag             
PCA0CN_CCF2__NOT_SET EQU 000H ; A match or capture did not occur on channel 2.
PCA0CN_CCF2__SET     EQU 004H ; A match or capture occurred on channel 2.     
                                                                              
PCA0CN_CCF3__BMASK   EQU 008H ; PCA Module 3 Capture/Compare Flag             
PCA0CN_CCF3__SHIFT   EQU 003H ; PCA Module 3 Capture/Compare Flag             
PCA0CN_CCF3__NOT_SET EQU 000H ; A match or capture did not occur on channel 3.
PCA0CN_CCF3__SET     EQU 008H ; A match or capture occurred on channel 3.     
                                                                              
PCA0CN_CCF4__BMASK   EQU 010H ; PCA Module 4 Capture/Compare Flag             
PCA0CN_CCF4__SHIFT   EQU 004H ; PCA Module 4 Capture/Compare Flag             
PCA0CN_CCF4__NOT_SET EQU 000H ; A match or capture did not occur on channel 4.
PCA0CN_CCF4__SET     EQU 010H ; A match or capture occurred on channel 4.     
                                                                              
PCA0CN_CCF5__BMASK   EQU 020H ; PCA Module 5 Capture/Compare Flag             
PCA0CN_CCF5__SHIFT   EQU 005H ; PCA Module 5 Capture/Compare Flag             
PCA0CN_CCF5__NOT_SET EQU 000H ; A match or capture did not occur on channel 5.
PCA0CN_CCF5__SET     EQU 020H ; A match or capture occurred on channel 5.     
                                                                              
PCA0CN_CR__BMASK     EQU 040H ; PCA Counter/Timer Run Control                 
PCA0CN_CR__SHIFT     EQU 006H ; PCA Counter/Timer Run Control                 
PCA0CN_CR__STOP      EQU 000H ; Stop the PCA Counter/Timer.                   
PCA0CN_CR__RUN       EQU 040H ; Start the PCA Counter/Timer running.          
                                                                              
PCA0CN_CF__BMASK     EQU 080H ; PCA Counter/Timer Overflow Flag               
PCA0CN_CF__SHIFT     EQU 007H ; PCA Counter/Timer Overflow Flag               
PCA0CN_CF__NOT_SET   EQU 000H ; The PCA counter/timer did not overflow.       
PCA0CN_CF__SET       EQU 080H ; The PCA counter/timer overflowed.             
                                                                              
;------------------------------------------------------------------------------
; PCA0CPH0 Enums (PCA Channel 0 Capture Module High Byte @ 0xFC)
;------------------------------------------------------------------------------
PCA0CPH0_PCA0CPH0__FMASK EQU 0FFH ; PCA Channel 0 Capture Module High Byte
PCA0CPH0_PCA0CPH0__SHIFT EQU 000H ; PCA Channel 0 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPH1 Enums (PCA Channel 1 Capture Module High Byte @ 0xEA)
;------------------------------------------------------------------------------
PCA0CPH1_PCA0CPH1__FMASK EQU 0FFH ; PCA Channel 1 Capture Module High Byte
PCA0CPH1_PCA0CPH1__SHIFT EQU 000H ; PCA Channel 1 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPH2 Enums (PCA Channel 2 Capture Module High Byte @ 0xEC)
;------------------------------------------------------------------------------
PCA0CPH2_PCA0CPH2__FMASK EQU 0FFH ; PCA Channel 2 Capture Module High Byte
PCA0CPH2_PCA0CPH2__SHIFT EQU 000H ; PCA Channel 2 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPH3 Enums (PCA Channel 3 Capture Module High Byte @ 0xEE)
;------------------------------------------------------------------------------
PCA0CPH3_PCA0CPH3__FMASK EQU 0FFH ; PCA Channel 3 Capture Module High Byte
PCA0CPH3_PCA0CPH3__SHIFT EQU 000H ; PCA Channel 3 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPH4 Enums (PCA Channel 4 Capture Module High Byte @ 0xFE)
;------------------------------------------------------------------------------
PCA0CPH4_PCA0CPH4__FMASK EQU 0FFH ; PCA Channel 4 Capture Module High Byte
PCA0CPH4_PCA0CPH4__SHIFT EQU 000H ; PCA Channel 4 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPH5 Enums (PCA Channel 5 Capture Module High Byte @ 0xD3)
;------------------------------------------------------------------------------
PCA0CPH5_PCA0CPH5__FMASK EQU 0FFH ; PCA Channel 5 Capture Module High Byte
PCA0CPH5_PCA0CPH5__SHIFT EQU 000H ; PCA Channel 5 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPL0 Enums (PCA Channel 0 Capture Module Low Byte @ 0xFB)
;------------------------------------------------------------------------------
PCA0CPL0_PCA0CPL0__FMASK EQU 0FFH ; PCA Channel 0 Capture Module Low Byte
PCA0CPL0_PCA0CPL0__SHIFT EQU 000H ; PCA Channel 0 Capture Module Low Byte
                                                                         
;------------------------------------------------------------------------------
; PCA0CPL1 Enums (PCA Channel 1 Capture Module Low Byte @ 0xE9)
;------------------------------------------------------------------------------
PCA0CPL1_PCA0CPL1__FMASK EQU 0FFH ; PCA Channel 1 Capture Module Low Byte
PCA0CPL1_PCA0CPL1__SHIFT EQU 000H ; PCA Channel 1 Capture Module Low Byte
                                                                         
;------------------------------------------------------------------------------
; PCA0CPL2 Enums (PCA Channel 2 Capture Module Low Byte @ 0xEB)
;------------------------------------------------------------------------------
PCA0CPL2_PCA0CPL2__FMASK EQU 0FFH ; PCA Channel 2 Capture Module Low Byte
PCA0CPL2_PCA0CPL2__SHIFT EQU 000H ; PCA Channel 2 Capture Module Low Byte
                                                                         
;------------------------------------------------------------------------------
; PCA0CPL3 Enums (PCA Channel 3 Capture Module Low Byte @ 0xED)
;------------------------------------------------------------------------------
PCA0CPL3_PCA0CPL3__FMASK EQU 0FFH ; PCA Channel 3 Capture Module Low Byte
PCA0CPL3_PCA0CPL3__SHIFT EQU 000H ; PCA Channel 3 Capture Module Low Byte
                                                                         
;------------------------------------------------------------------------------
; PCA0CPL4 Enums (PCA Channel 4 Capture Module Low Byte @ 0xFD)
;------------------------------------------------------------------------------
PCA0CPL4_PCA0CPL4__FMASK EQU 0FFH ; PCA Channel 4 Capture Module Low Byte
PCA0CPL4_PCA0CPL4__SHIFT EQU 000H ; PCA Channel 4 Capture Module Low Byte
                                                                         
;------------------------------------------------------------------------------
; PCA0CPL5 Enums (PCA Channel 5 Capture Module Low Byte @ 0xD2)
;------------------------------------------------------------------------------
PCA0CPL5_PCA0CPL5__FMASK EQU 0FFH ; PCA Channel 5 Capture Module Low Byte
PCA0CPL5_PCA0CPL5__SHIFT EQU 000H ; PCA Channel 5 Capture Module Low Byte
                                                                         
;------------------------------------------------------------------------------
; PCA0CPM0 Enums (PCA Channel 0 Capture/Compare Mode 0 @ 0xDA)
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
PCA0CPM0_PWM16__8_BIT   EQU 000H ; 8-bit PWM selected.                            
PCA0CPM0_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
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
PCA0CPM1_PWM16__8_BIT   EQU 000H ; 8-bit PWM selected.                            
PCA0CPM1_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
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
PCA0CPM2_PWM16__8_BIT   EQU 000H ; 8-bit PWM selected.                            
PCA0CPM2_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
;------------------------------------------------------------------------------
; PCA0CPM3 Enums (PCA Channel 3 Capture/Compare Mode @ 0xDD)
;------------------------------------------------------------------------------
PCA0CPM3_ECCF__BMASK    EQU 001H ; Channel 3 Capture/Compare Flag Interrupt Enable
PCA0CPM3_ECCF__SHIFT    EQU 000H ; Channel 3 Capture/Compare Flag Interrupt Enable
PCA0CPM3_ECCF__DISABLED EQU 000H ; Disable CCF3 interrupts.                       
PCA0CPM3_ECCF__ENABLED  EQU 001H ; Enable a Capture/Compare Flag interrupt request
                                 ; when CCF3 is set.                              
                                                                                  
PCA0CPM3_PWM__BMASK     EQU 002H ; Channel 3 Pulse Width Modulation Mode Enable   
PCA0CPM3_PWM__SHIFT     EQU 001H ; Channel 3 Pulse Width Modulation Mode Enable   
PCA0CPM3_PWM__DISABLED  EQU 000H ; Disable PWM function.                          
PCA0CPM3_PWM__ENABLED   EQU 002H ; Enable PWM function.                           
                                                                                  
PCA0CPM3_TOG__BMASK     EQU 004H ; Channel 3 Toggle Function Enable               
PCA0CPM3_TOG__SHIFT     EQU 002H ; Channel 3 Toggle Function Enable               
PCA0CPM3_TOG__DISABLED  EQU 000H ; Disable toggle function.                       
PCA0CPM3_TOG__ENABLED   EQU 004H ; Enable toggle function.                        
                                                                                  
PCA0CPM3_MAT__BMASK     EQU 008H ; Channel 3 Match Function Enable                
PCA0CPM3_MAT__SHIFT     EQU 003H ; Channel 3 Match Function Enable                
PCA0CPM3_MAT__DISABLED  EQU 000H ; Disable match function.                        
PCA0CPM3_MAT__ENABLED   EQU 008H ; Enable match function.                         
                                                                                  
PCA0CPM3_CAPN__BMASK    EQU 010H ; Channel 3 Capture Negative Function Enable     
PCA0CPM3_CAPN__SHIFT    EQU 004H ; Channel 3 Capture Negative Function Enable     
PCA0CPM3_CAPN__DISABLED EQU 000H ; Disable negative edge capture.                 
PCA0CPM3_CAPN__ENABLED  EQU 010H ; Enable negative edge capture.                  
                                                                                  
PCA0CPM3_CAPP__BMASK    EQU 020H ; Channel 3 Capture Positive Function Enable     
PCA0CPM3_CAPP__SHIFT    EQU 005H ; Channel 3 Capture Positive Function Enable     
PCA0CPM3_CAPP__DISABLED EQU 000H ; Disable positive edge capture.                 
PCA0CPM3_CAPP__ENABLED  EQU 020H ; Enable positive edge capture.                  
                                                                                  
PCA0CPM3_ECOM__BMASK    EQU 040H ; Channel 3 Comparator Function Enable           
PCA0CPM3_ECOM__SHIFT    EQU 006H ; Channel 3 Comparator Function Enable           
PCA0CPM3_ECOM__DISABLED EQU 000H ; Disable comparator function.                   
PCA0CPM3_ECOM__ENABLED  EQU 040H ; Enable comparator function.                    
                                                                                  
PCA0CPM3_PWM16__BMASK   EQU 080H ; Channel 3 16-bit Pulse Width Modulation Enable 
PCA0CPM3_PWM16__SHIFT   EQU 007H ; Channel 3 16-bit Pulse Width Modulation Enable 
PCA0CPM3_PWM16__8_BIT   EQU 000H ; 8-bit PWM selected.                            
PCA0CPM3_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
;------------------------------------------------------------------------------
; PCA0CPM4 Enums (PCA Channel 4 Capture/Compare Mode @ 0xDE)
;------------------------------------------------------------------------------
PCA0CPM4_ECCF__BMASK    EQU 001H ; Channel 4 Capture/Compare Flag Interrupt Enable
PCA0CPM4_ECCF__SHIFT    EQU 000H ; Channel 4 Capture/Compare Flag Interrupt Enable
PCA0CPM4_ECCF__DISABLED EQU 000H ; Disable CCF4 interrupts.                       
PCA0CPM4_ECCF__ENABLED  EQU 001H ; Enable a Capture/Compare Flag interrupt request
                                 ; when CCF4 is set.                              
                                                                                  
PCA0CPM4_PWM__BMASK     EQU 002H ; Channel 4 Pulse Width Modulation Mode Enable   
PCA0CPM4_PWM__SHIFT     EQU 001H ; Channel 4 Pulse Width Modulation Mode Enable   
PCA0CPM4_PWM__DISABLED  EQU 000H ; Disable PWM function.                          
PCA0CPM4_PWM__ENABLED   EQU 002H ; Enable PWM function.                           
                                                                                  
PCA0CPM4_TOG__BMASK     EQU 004H ; Channel 4 Toggle Function Enable               
PCA0CPM4_TOG__SHIFT     EQU 002H ; Channel 4 Toggle Function Enable               
PCA0CPM4_TOG__DISABLED  EQU 000H ; Disable toggle function.                       
PCA0CPM4_TOG__ENABLED   EQU 004H ; Enable toggle function.                        
                                                                                  
PCA0CPM4_MAT__BMASK     EQU 008H ; Channel 4 Match Function Enable                
PCA0CPM4_MAT__SHIFT     EQU 003H ; Channel 4 Match Function Enable                
PCA0CPM4_MAT__DISABLED  EQU 000H ; Disable match function.                        
PCA0CPM4_MAT__ENABLED   EQU 008H ; Enable match function.                         
                                                                                  
PCA0CPM4_CAPN__BMASK    EQU 010H ; Channel 4 Capture Negative Function Enable     
PCA0CPM4_CAPN__SHIFT    EQU 004H ; Channel 4 Capture Negative Function Enable     
PCA0CPM4_CAPN__DISABLED EQU 000H ; Disable negative edge capture.                 
PCA0CPM4_CAPN__ENABLED  EQU 010H ; Enable negative edge capture.                  
                                                                                  
PCA0CPM4_CAPP__BMASK    EQU 020H ; Channel 4 Capture Positive Function Enable     
PCA0CPM4_CAPP__SHIFT    EQU 005H ; Channel 4 Capture Positive Function Enable     
PCA0CPM4_CAPP__DISABLED EQU 000H ; Disable positive edge capture.                 
PCA0CPM4_CAPP__ENABLED  EQU 020H ; Enable positive edge capture.                  
                                                                                  
PCA0CPM4_ECOM__BMASK    EQU 040H ; Channel 4 Comparator Function Enable           
PCA0CPM4_ECOM__SHIFT    EQU 006H ; Channel 4 Comparator Function Enable           
PCA0CPM4_ECOM__DISABLED EQU 000H ; Disable comparator function.                   
PCA0CPM4_ECOM__ENABLED  EQU 040H ; Enable comparator function.                    
                                                                                  
PCA0CPM4_PWM16__BMASK   EQU 080H ; Channel 4 16-bit Pulse Width Modulation Enable 
PCA0CPM4_PWM16__SHIFT   EQU 007H ; Channel 4 16-bit Pulse Width Modulation Enable 
PCA0CPM4_PWM16__8_BIT   EQU 000H ; 8-bit PWM selected.                            
PCA0CPM4_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
;------------------------------------------------------------------------------
; PCA0CPM5 Enums (PCA Channel 5 Capture/Compare Mode @ 0xCE)
;------------------------------------------------------------------------------
PCA0CPM5_ECCF__BMASK    EQU 001H ; Channel 5 Capture/Compare Flag Interrupt Enable
PCA0CPM5_ECCF__SHIFT    EQU 000H ; Channel 5 Capture/Compare Flag Interrupt Enable
PCA0CPM5_ECCF__DISABLED EQU 000H ; Disable CCF5 interrupts.                       
PCA0CPM5_ECCF__ENABLED  EQU 001H ; Enable a Capture/Compare Flag interrupt request
                                 ; when CCF5 is set.                              
                                                                                  
PCA0CPM5_PWM__BMASK     EQU 002H ; Channel 5 Pulse Width Modulation Mode Enable   
PCA0CPM5_PWM__SHIFT     EQU 001H ; Channel 5 Pulse Width Modulation Mode Enable   
PCA0CPM5_PWM__DISABLED  EQU 000H ; Disable PWM function.                          
PCA0CPM5_PWM__ENABLED   EQU 002H ; Enable PWM function.                           
                                                                                  
PCA0CPM5_TOG__BMASK     EQU 004H ; Channel 5 Toggle Function Enable               
PCA0CPM5_TOG__SHIFT     EQU 002H ; Channel 5 Toggle Function Enable               
PCA0CPM5_TOG__DISABLED  EQU 000H ; Disable toggle function.                       
PCA0CPM5_TOG__ENABLED   EQU 004H ; Enable toggle function.                        
                                                                                  
PCA0CPM5_MAT__BMASK     EQU 008H ; Channel 5 Match Function Enable                
PCA0CPM5_MAT__SHIFT     EQU 003H ; Channel 5 Match Function Enable                
PCA0CPM5_MAT__DISABLED  EQU 000H ; Disable match function.                        
PCA0CPM5_MAT__ENABLED   EQU 008H ; Enable match function.                         
                                                                                  
PCA0CPM5_CAPN__BMASK    EQU 010H ; Channel 5 Capture Negative Function Enable     
PCA0CPM5_CAPN__SHIFT    EQU 004H ; Channel 5 Capture Negative Function Enable     
PCA0CPM5_CAPN__DISABLED EQU 000H ; Disable negative edge capture.                 
PCA0CPM5_CAPN__ENABLED  EQU 010H ; Enable negative edge capture.                  
                                                                                  
PCA0CPM5_CAPP__BMASK    EQU 020H ; Channel 5 Capture Positive Function Enable     
PCA0CPM5_CAPP__SHIFT    EQU 005H ; Channel 5 Capture Positive Function Enable     
PCA0CPM5_CAPP__DISABLED EQU 000H ; Disable positive edge capture.                 
PCA0CPM5_CAPP__ENABLED  EQU 020H ; Enable positive edge capture.                  
                                                                                  
PCA0CPM5_ECOM__BMASK    EQU 040H ; Channel 5 Comparator Function Enable           
PCA0CPM5_ECOM__SHIFT    EQU 006H ; Channel 5 Comparator Function Enable           
PCA0CPM5_ECOM__DISABLED EQU 000H ; Disable comparator function.                   
PCA0CPM5_ECOM__ENABLED  EQU 040H ; Enable comparator function.                    
                                                                                  
PCA0CPM5_PWM16__BMASK   EQU 080H ; Channel 5 16-bit Pulse Width Modulation Enable 
PCA0CPM5_PWM16__SHIFT   EQU 007H ; Channel 5 16-bit Pulse Width Modulation Enable 
PCA0CPM5_PWM16__8_BIT   EQU 000H ; 8-bit PWM selected.                            
PCA0CPM5_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
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
                                      ; request when CF (PCA0CN.7) is set.                
                                                                                          
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
PCA0MD_CPS__RTC_DIV_8        EQU 00CH ; RTC divided by 8.                                 
                                                                                          
PCA0MD_WDLCK__BMASK          EQU 020H ; Watchdog Timer Lock                               
PCA0MD_WDLCK__SHIFT          EQU 005H ; Watchdog Timer Lock                               
PCA0MD_WDLCK__UNLOCKED       EQU 000H ; Watchdog Timer Enable unlocked.                   
PCA0MD_WDLCK__LOCKED         EQU 020H ; Watchdog Timer Enable locked.                     
                                                                                          
PCA0MD_WDTE__BMASK           EQU 040H ; Watchdog Timer Enable                             
PCA0MD_WDTE__SHIFT           EQU 006H ; Watchdog Timer Enable                             
PCA0MD_WDTE__DISABLED        EQU 000H ; Disable Watchdog Timer.                           
PCA0MD_WDTE__ENABLED         EQU 040H ; Enable PCA Module 5 as the Watchdog Timer.        
                                                                                          
PCA0MD_CIDL__BMASK           EQU 080H ; PCA Counter/Timer Idle Control                    
PCA0MD_CIDL__SHIFT           EQU 007H ; PCA Counter/Timer Idle Control                    
PCA0MD_CIDL__NORMAL          EQU 000H ; PCA continues to function normally while the      
                                      ; system controller is in Idle Mode.                
PCA0MD_CIDL__SUSPEND         EQU 080H ; PCA operation is suspended while the system       
                                      ; controller is in Idle Mode.                       
                                                                                          
;------------------------------------------------------------------------------
; PCON Enums (Power Control @ 0x87)
;------------------------------------------------------------------------------
PCON_IDLE__BMASK  EQU 001H ; Idle Mode Select                                
PCON_IDLE__SHIFT  EQU 000H ; Idle Mode Select                                
PCON_IDLE__NORMAL EQU 000H ; Idle mode not activated.                        
PCON_IDLE__IDLE   EQU 001H ; CPU goes into Idle mode (shuts off clock to CPU,
                           ; but clocks to enabled peripherals are still     
                           ; active).                                        
                                                                             
PCON_STOP__BMASK  EQU 002H ; Stop Mode Select                                
PCON_STOP__SHIFT  EQU 001H ; Stop Mode Select                                
PCON_STOP__NORMAL EQU 000H ; Stop mode not activated.                        
PCON_STOP__STOP   EQU 002H ; CPU goes into Stop mode (internal oscillator    
                           ; stopped).                                       
                                                                             
PCON_GF0__BMASK   EQU 004H ; General Purpose Flag 0                          
PCON_GF0__SHIFT   EQU 002H ; General Purpose Flag 0                          
PCON_GF0__NOT_SET EQU 000H ; The GF0 flag is not set. Clear the GF0 flag.    
PCON_GF0__SET     EQU 004H ; The GF0 flag is set. Set the GF0 flag.          
                                                                             
PCON_GF1__BMASK   EQU 008H ; General Purpose Flag 1                          
PCON_GF1__SHIFT   EQU 003H ; General Purpose Flag 1                          
PCON_GF1__NOT_SET EQU 000H ; The GF1 flag is not set. Clear the GF1 flag.    
PCON_GF1__SET     EQU 008H ; The GF1 flag is set. Set the GF1 flag.          
                                                                             
PCON_GF2__BMASK   EQU 010H ; General Purpose Flag 2                          
PCON_GF2__SHIFT   EQU 004H ; General Purpose Flag 2                          
PCON_GF2__NOT_SET EQU 000H ; The GF2 flag is not set. Clear the GF2 flag.    
PCON_GF2__SET     EQU 010H ; The GF2 flag is set. Set the GF2 flag.          
                                                                             
PCON_GF3__BMASK   EQU 020H ; General Purpose Flag 3                          
PCON_GF3__SHIFT   EQU 005H ; General Purpose Flag 3                          
PCON_GF3__NOT_SET EQU 000H ; The GF3 flag is not set. Clear the GF3 flag.    
PCON_GF3__SET     EQU 020H ; The GF3 flag is set. Set the GF3 flag.          
                                                                             
PCON_GF4__BMASK   EQU 040H ; General Purpose Flag 4                          
PCON_GF4__SHIFT   EQU 006H ; General Purpose Flag 4                          
PCON_GF4__NOT_SET EQU 000H ; The GF4 flag is not set. Clear the GF4 flag.    
PCON_GF4__SET     EQU 040H ; The GF4 flag is set. Set the GF4 flag.          
                                                                             
PCON_GF5__BMASK   EQU 080H ; General Purpose Flag 5                          
PCON_GF5__SHIFT   EQU 007H ; General Purpose Flag 5                          
PCON_GF5__NOT_SET EQU 000H ; The GF5 flag is not set. Clear the GF5 flag.    
PCON_GF5__SET     EQU 080H ; The GF5 flag is set. Set the GF5 flag.          
                                                                             
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
; P0MASK Enums (Port 0 Mask @ 0xC7)
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
; P0MAT Enums (Port 0 Match @ 0xD7)
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
; P0ODEN Enums (Port 0 Overdrive Mode @ 0xB0)
;------------------------------------------------------------------------------
P0ODEN_B0__BMASK          EQU 001H ; Port 0 Bit 0 Overdrive Mode                     
P0ODEN_B0__SHIFT          EQU 000H ; Port 0 Bit 0 Overdrive Mode                     
P0ODEN_B0__NORMAL         EQU 000H ; Configure P0.0 to normal overdrive mode.        
P0ODEN_B0__HIGH_IMPEDANCE EQU 001H ; Configure P0.0 to high-impedance overdrive mode.
                                                                                     
P0ODEN_B1__BMASK          EQU 002H ; Port 0 Bit 1 Overdrive Mode                     
P0ODEN_B1__SHIFT          EQU 001H ; Port 0 Bit 1 Overdrive Mode                     
P0ODEN_B1__NORMAL         EQU 000H ; Configure P0.1 to normal overdrive mode.        
P0ODEN_B1__HIGH_IMPEDANCE EQU 002H ; Configure P0.1 to high-impedance overdrive mode.
                                                                                     
P0ODEN_B2__BMASK          EQU 004H ; Port 0 Bit 2 Overdrive Mode                     
P0ODEN_B2__SHIFT          EQU 002H ; Port 0 Bit 2 Overdrive Mode                     
P0ODEN_B2__NORMAL         EQU 000H ; Configure P0.2 to normal overdrive mode.        
P0ODEN_B2__HIGH_IMPEDANCE EQU 004H ; Configure P0.2 to high-impedance overdrive mode.
                                                                                     
P0ODEN_B3__BMASK          EQU 008H ; Port 0 Bit 3 Overdrive Mode                     
P0ODEN_B3__SHIFT          EQU 003H ; Port 0 Bit 3 Overdrive Mode                     
P0ODEN_B3__NORMAL         EQU 000H ; Configure P0.3 to normal overdrive mode.        
P0ODEN_B3__HIGH_IMPEDANCE EQU 008H ; Configure P0.3 to high-impedance overdrive mode.
                                                                                     
P0ODEN_B4__BMASK          EQU 010H ; Port 0 Bit 4 Overdrive Mode                     
P0ODEN_B4__SHIFT          EQU 004H ; Port 0 Bit 4 Overdrive Mode                     
P0ODEN_B4__NORMAL         EQU 000H ; Configure P0.4 to normal overdrive mode.        
P0ODEN_B4__HIGH_IMPEDANCE EQU 010H ; Configure P0.4 to high-impedance overdrive mode.
                                                                                     
P0ODEN_B5__BMASK          EQU 020H ; Port 0 Bit 5 Overdrive Mode                     
P0ODEN_B5__SHIFT          EQU 005H ; Port 0 Bit 5 Overdrive Mode                     
P0ODEN_B5__NORMAL         EQU 000H ; Configure P0.5 to normal overdrive mode.        
P0ODEN_B5__HIGH_IMPEDANCE EQU 020H ; Configure P0.5 to high-impedance overdrive mode.
                                                                                     
P0ODEN_B6__BMASK          EQU 040H ; Port 0 Bit 6 Overdrive Mode                     
P0ODEN_B6__SHIFT          EQU 006H ; Port 0 Bit 6 Overdrive Mode                     
P0ODEN_B6__NORMAL         EQU 000H ; Configure P0.6 to normal overdrive mode.        
P0ODEN_B6__HIGH_IMPEDANCE EQU 040H ; Configure P0.6 to high-impedance overdrive mode.
                                                                                     
P0ODEN_B7__BMASK          EQU 080H ; Port 0 Bit 7 Overdrive Mode                     
P0ODEN_B7__SHIFT          EQU 007H ; Port 0 Bit 7 Overdrive Mode                     
P0ODEN_B7__NORMAL         EQU 000H ; Configure P0.7 to normal overdrive mode.        
P0ODEN_B7__HIGH_IMPEDANCE EQU 080H ; Configure P0.7 to high-impedance overdrive mode.
                                                                                     
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
; P1MASK Enums (Port 1 Mask @ 0xBF)
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
; P1MAT Enums (Port 1 Match @ 0xCF)
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
                                                                      
P2_B2__BMASK EQU 004H ; Port 2 Bit 2 Latch                            
P2_B2__SHIFT EQU 002H ; Port 2 Bit 2 Latch                            
P2_B2__LOW   EQU 000H ; P2.2 is low. Set P2.2 to drive low.           
P2_B2__HIGH  EQU 004H ; P2.2 is high. Set P2.2 to drive or float high.
                                                                      
P2_B3__BMASK EQU 008H ; Port 2 Bit 3 Latch                            
P2_B3__SHIFT EQU 003H ; Port 2 Bit 3 Latch                            
P2_B3__LOW   EQU 000H ; P2.3 is low. Set P2.3 to drive low.           
P2_B3__HIGH  EQU 008H ; P2.3 is high. Set P2.3 to drive or float high.
                                                                      
P2_B4__BMASK EQU 010H ; Port 2 Bit 4 Latch                            
P2_B4__SHIFT EQU 004H ; Port 2 Bit 4 Latch                            
P2_B4__LOW   EQU 000H ; P2.4 is low. Set P2.4 to drive low.           
P2_B4__HIGH  EQU 010H ; P2.4 is high. Set P2.4 to drive or float high.
                                                                      
P2_B5__BMASK EQU 020H ; Port 2 Bit 5 Latch                            
P2_B5__SHIFT EQU 005H ; Port 2 Bit 5 Latch                            
P2_B5__LOW   EQU 000H ; P2.5 is low. Set P2.5 to drive low.           
P2_B5__HIGH  EQU 020H ; P2.5 is high. Set P2.5 to drive or float high.
                                                                      
P2_B6__BMASK EQU 040H ; Port 2 Bit 6 Latch                            
P2_B6__SHIFT EQU 006H ; Port 2 Bit 6 Latch                            
P2_B6__LOW   EQU 000H ; P2.6 is low. Set P2.6 to drive low.           
P2_B6__HIGH  EQU 040H ; P2.6 is high. Set P2.6 to drive or float high.
                                                                      
P2_B7__BMASK EQU 080H ; Port 2 Bit 7 Latch                            
P2_B7__SHIFT EQU 007H ; Port 2 Bit 7 Latch                            
P2_B7__LOW   EQU 000H ; P2.7 is low. Set P2.7 to drive low.           
P2_B7__HIGH  EQU 080H ; P2.7 is high. Set P2.7 to drive or float high.
                                                                      
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
                                                                      
P2MDIN_B2__BMASK   EQU 004H ; Port 2 Bit 2 Input Mode                 
P2MDIN_B2__SHIFT   EQU 002H ; Port 2 Bit 2 Input Mode                 
P2MDIN_B2__ANALOG  EQU 000H ; P2.2 pin is configured for analog mode. 
P2MDIN_B2__DIGITAL EQU 004H ; P2.2 pin is configured for digital mode.
                                                                      
P2MDIN_B3__BMASK   EQU 008H ; Port 2 Bit 3 Input Mode                 
P2MDIN_B3__SHIFT   EQU 003H ; Port 2 Bit 3 Input Mode                 
P2MDIN_B3__ANALOG  EQU 000H ; P2.3 pin is configured for analog mode. 
P2MDIN_B3__DIGITAL EQU 008H ; P2.3 pin is configured for digital mode.
                                                                      
P2MDIN_B4__BMASK   EQU 010H ; Port 2 Bit 4 Input Mode                 
P2MDIN_B4__SHIFT   EQU 004H ; Port 2 Bit 4 Input Mode                 
P2MDIN_B4__ANALOG  EQU 000H ; P2.4 pin is configured for analog mode. 
P2MDIN_B4__DIGITAL EQU 010H ; P2.4 pin is configured for digital mode.
                                                                      
P2MDIN_B5__BMASK   EQU 020H ; Port 2 Bit 5 Input Mode                 
P2MDIN_B5__SHIFT   EQU 005H ; Port 2 Bit 5 Input Mode                 
P2MDIN_B5__ANALOG  EQU 000H ; P2.5 pin is configured for analog mode. 
P2MDIN_B5__DIGITAL EQU 020H ; P2.5 pin is configured for digital mode.
                                                                      
P2MDIN_B6__BMASK   EQU 040H ; Port 2 Bit 6 Input Mode                 
P2MDIN_B6__SHIFT   EQU 006H ; Port 2 Bit 6 Input Mode                 
P2MDIN_B6__ANALOG  EQU 000H ; P2.6 pin is configured for analog mode. 
P2MDIN_B6__DIGITAL EQU 040H ; P2.6 pin is configured for digital mode.
                                                                      
P2MDIN_B7__BMASK   EQU 080H ; Port 2 Bit 7 Input Mode                 
P2MDIN_B7__SHIFT   EQU 007H ; Port 2 Bit 7 Input Mode                 
P2MDIN_B7__ANALOG  EQU 000H ; P2.7 pin is configured for analog mode. 
P2MDIN_B7__DIGITAL EQU 080H ; P2.7 pin is configured for digital mode.
                                                                      
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
                                                            
P2MDOUT_B2__BMASK      EQU 004H ; Port 2 Bit 2 Output Mode  
P2MDOUT_B2__SHIFT      EQU 002H ; Port 2 Bit 2 Output Mode  
P2MDOUT_B2__OPEN_DRAIN EQU 000H ; P2.2 output is open-drain.
P2MDOUT_B2__PUSH_PULL  EQU 004H ; P2.2 output is push-pull. 
                                                            
P2MDOUT_B3__BMASK      EQU 008H ; Port 2 Bit 3 Output Mode  
P2MDOUT_B3__SHIFT      EQU 003H ; Port 2 Bit 3 Output Mode  
P2MDOUT_B3__OPEN_DRAIN EQU 000H ; P2.3 output is open-drain.
P2MDOUT_B3__PUSH_PULL  EQU 008H ; P2.3 output is push-pull. 
                                                            
P2MDOUT_B4__BMASK      EQU 010H ; Port 2 Bit 4 Output Mode  
P2MDOUT_B4__SHIFT      EQU 004H ; Port 2 Bit 4 Output Mode  
P2MDOUT_B4__OPEN_DRAIN EQU 000H ; P2.4 output is open-drain.
P2MDOUT_B4__PUSH_PULL  EQU 010H ; P2.4 output is push-pull. 
                                                            
P2MDOUT_B5__BMASK      EQU 020H ; Port 2 Bit 5 Output Mode  
P2MDOUT_B5__SHIFT      EQU 005H ; Port 2 Bit 5 Output Mode  
P2MDOUT_B5__OPEN_DRAIN EQU 000H ; P2.5 output is open-drain.
P2MDOUT_B5__PUSH_PULL  EQU 020H ; P2.5 output is push-pull. 
                                                            
P2MDOUT_B6__BMASK      EQU 040H ; Port 2 Bit 6 Output Mode  
P2MDOUT_B6__SHIFT      EQU 006H ; Port 2 Bit 6 Output Mode  
P2MDOUT_B6__OPEN_DRAIN EQU 000H ; P2.6 output is open-drain.
P2MDOUT_B6__PUSH_PULL  EQU 040H ; P2.6 output is push-pull. 
                                                            
P2MDOUT_B7__BMASK      EQU 080H ; Port 2 Bit 7 Output Mode  
P2MDOUT_B7__SHIFT      EQU 007H ; Port 2 Bit 7 Output Mode  
P2MDOUT_B7__OPEN_DRAIN EQU 000H ; P2.7 output is open-drain.
P2MDOUT_B7__PUSH_PULL  EQU 080H ; P2.7 output is push-pull. 
                                                            
;------------------------------------------------------------------------------
; P2SKIP Enums (Port 2 Skip @ 0xD6)
;------------------------------------------------------------------------------
P2SKIP_B0__BMASK       EQU 001H ; Port 2 Bit 0 Skip                       
P2SKIP_B0__SHIFT       EQU 000H ; Port 2 Bit 0 Skip                       
P2SKIP_B0__NOT_SKIPPED EQU 000H ; P2.0 pin is not skipped by the crossbar.
P2SKIP_B0__SKIPPED     EQU 001H ; P2.0 pin is skipped by the crossbar.    
                                                                          
P2SKIP_B1__BMASK       EQU 002H ; Port 2 Bit 1 Skip                       
P2SKIP_B1__SHIFT       EQU 001H ; Port 2 Bit 1 Skip                       
P2SKIP_B1__NOT_SKIPPED EQU 000H ; P2.1 pin is not skipped by the crossbar.
P2SKIP_B1__SKIPPED     EQU 002H ; P2.1 pin is skipped by the crossbar.    
                                                                          
P2SKIP_B2__BMASK       EQU 004H ; Port 2 Bit 2 Skip                       
P2SKIP_B2__SHIFT       EQU 002H ; Port 2 Bit 2 Skip                       
P2SKIP_B2__NOT_SKIPPED EQU 000H ; P2.2 pin is not skipped by the crossbar.
P2SKIP_B2__SKIPPED     EQU 004H ; P2.2 pin is skipped by the crossbar.    
                                                                          
P2SKIP_B3__BMASK       EQU 008H ; Port 2 Bit 3 Skip                       
P2SKIP_B3__SHIFT       EQU 003H ; Port 2 Bit 3 Skip                       
P2SKIP_B3__NOT_SKIPPED EQU 000H ; P2.3 pin is not skipped by the crossbar.
P2SKIP_B3__SKIPPED     EQU 008H ; P2.3 pin is skipped by the crossbar.    
                                                                          
P2SKIP_B4__BMASK       EQU 010H ; Port 2 Bit 4 Skip                       
P2SKIP_B4__SHIFT       EQU 004H ; Port 2 Bit 4 Skip                       
P2SKIP_B4__NOT_SKIPPED EQU 000H ; P2.4 pin is not skipped by the crossbar.
P2SKIP_B4__SKIPPED     EQU 010H ; P2.4 pin is skipped by the crossbar.    
                                                                          
P2SKIP_B5__BMASK       EQU 020H ; Port 2 Bit 5 Skip                       
P2SKIP_B5__SHIFT       EQU 005H ; Port 2 Bit 5 Skip                       
P2SKIP_B5__NOT_SKIPPED EQU 000H ; P2.5 pin is not skipped by the crossbar.
P2SKIP_B5__SKIPPED     EQU 020H ; P2.5 pin is skipped by the crossbar.    
                                                                          
P2SKIP_B6__BMASK       EQU 040H ; Port 2 Bit 6 Skip                       
P2SKIP_B6__SHIFT       EQU 006H ; Port 2 Bit 6 Skip                       
P2SKIP_B6__NOT_SKIPPED EQU 000H ; P2.6 pin is not skipped by the crossbar.
P2SKIP_B6__SKIPPED     EQU 040H ; P2.6 pin is skipped by the crossbar.    
                                                                          
P2SKIP_B7__BMASK       EQU 080H ; Port 2 Bit 7 Skip                       
P2SKIP_B7__SHIFT       EQU 007H ; Port 2 Bit 7 Skip                       
P2SKIP_B7__NOT_SKIPPED EQU 000H ; P2.7 pin is not skipped by the crossbar.
P2SKIP_B7__SKIPPED     EQU 080H ; P2.7 pin is skipped by the crossbar.    
                                                                          
;------------------------------------------------------------------------------
; RSTSRC Enums (Reset Source @ 0xEF)
;------------------------------------------------------------------------------
RSTSRC_PINRSF__BMASK   EQU 001H ; HW Pin Reset Flag                                                    
RSTSRC_PINRSF__SHIFT   EQU 000H ; HW Pin Reset Flag                                                    
RSTSRC_PINRSF__NOT_SET EQU 000H ; The /RST pin did not cause the last reset.                           
RSTSRC_PINRSF__SET     EQU 001H ; The /RST pin caused the last reset.                                  
                                                                                                       
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
                                                                                                       
RSTSRC_RTC0RE__BMASK   EQU 080H ; RTC Reset Enable and Flag                                            
RSTSRC_RTC0RE__SHIFT   EQU 007H ; RTC Reset Enable and Flag                                            
RSTSRC_RTC0RE__NOT_SET EQU 000H ; A RTC alarm or oscillator fail reset did not                         
                                ; occur.                                                               
RSTSRC_RTC0RE__SET     EQU 080H ; A RTC alarm or oscillator fail reset occurred.                       
                                                                                                       
;------------------------------------------------------------------------------
; ALARM0 Enums (RTC Alarm Programmed Value 0 @ 0x08)
;------------------------------------------------------------------------------
ALARM0_ALARM0__FMASK EQU 0FFH ; RTC Alarm Programmed Value 0
ALARM0_ALARM0__SHIFT EQU 000H ; RTC Alarm Programmed Value 0
                                                            
;------------------------------------------------------------------------------
; ALARM1 Enums (RTC Alarm Programmed Value 1 @ 0x09)
;------------------------------------------------------------------------------
ALARM1_ALARM1__FMASK EQU 0FFH ; RTC Alarm Programmed Value 1
ALARM1_ALARM1__SHIFT EQU 000H ; RTC Alarm Programmed Value 1
                                                            
;------------------------------------------------------------------------------
; ALARM2 Enums (RTC Alarm Programmed Value 2 @ 0x0A)
;------------------------------------------------------------------------------
ALARM2_ALARM2__FMASK EQU 0FFH ; RTC Alarm Programmed Value 2
ALARM2_ALARM2__SHIFT EQU 000H ; RTC Alarm Programmed Value 2
                                                            
;------------------------------------------------------------------------------
; ALARM3 Enums (RTC Alarm Programmed Value 3 @ 0x0B)
;------------------------------------------------------------------------------
ALARM3_ALARM3__FMASK EQU 0FFH ; RTC Alarm Programmed Value 3
ALARM3_ALARM3__SHIFT EQU 000H ; RTC Alarm Programmed Value 3
                                                            
;------------------------------------------------------------------------------
; ALARM4 Enums (RTC Alarm Programmed Value 4 @ 0x0C)
;------------------------------------------------------------------------------
ALARM4_ALARM4__FMASK EQU 0FFH ; RTC Alarm Programmed Value 4
ALARM4_ALARM4__SHIFT EQU 000H ; RTC Alarm Programmed Value 4
                                                            
;------------------------------------------------------------------------------
; ALARM5 Enums (RTC Alarm Programmed Value 5 @ 0x0D)
;------------------------------------------------------------------------------
ALARM5_ALARM5__FMASK EQU 0FFH ; RTC Alarm Programmed Value 5
ALARM5_ALARM5__SHIFT EQU 000H ; RTC Alarm Programmed Value 5
                                                            
;------------------------------------------------------------------------------
; CAPTURE0 Enums (RTC Timer Capture 0 @ 0x00)
;------------------------------------------------------------------------------
CAPTURE0_CAPTURE0__FMASK EQU 0FFH ; RTC Timer Capture 0
CAPTURE0_CAPTURE0__SHIFT EQU 000H ; RTC Timer Capture 0
                                                       
;------------------------------------------------------------------------------
; CAPTURE1 Enums (RTC Timer Capture 1 @ 0x01)
;------------------------------------------------------------------------------
CAPTURE1_CAPTURE1__FMASK EQU 0FFH ; RTC Timer Capture 1
CAPTURE1_CAPTURE1__SHIFT EQU 000H ; RTC Timer Capture 1
                                                       
;------------------------------------------------------------------------------
; CAPTURE2 Enums (RTC Timer Capture 2 @ 0x02)
;------------------------------------------------------------------------------
CAPTURE2_CAPTURE2__FMASK EQU 0FFH ; RTC Timer Capture 2
CAPTURE2_CAPTURE2__SHIFT EQU 000H ; RTC Timer Capture 2
                                                       
;------------------------------------------------------------------------------
; CAPTURE3 Enums (RTC Timer Capture 3 @ 0x03)
;------------------------------------------------------------------------------
CAPTURE3_CAPTURE3__FMASK EQU 0FFH ; RTC Timer Capture 3
CAPTURE3_CAPTURE3__SHIFT EQU 000H ; RTC Timer Capture 3
                                                       
;------------------------------------------------------------------------------
; CAPTURE4 Enums (RTC Timer Capture 4 @ 0x04)
;------------------------------------------------------------------------------
CAPTURE4_CAPTURE4__FMASK EQU 0FFH ; RTC Timer Capture 4
CAPTURE4_CAPTURE4__SHIFT EQU 000H ; RTC Timer Capture 4
                                                       
;------------------------------------------------------------------------------
; CAPTURE5 Enums (RTC Timer Capture 5 @ 0x05)
;------------------------------------------------------------------------------
CAPTURE5_CAPTURE5__FMASK EQU 0FFH ; RTC Timer Capture 5
CAPTURE5_CAPTURE5__SHIFT EQU 000H ; RTC Timer Capture 5
                                                       
;------------------------------------------------------------------------------
; RAMADDR Enums (RTC Backup RAM Address @ 0x0E)
;------------------------------------------------------------------------------
RAMADDR_RAMADDR__FMASK EQU 0FFH ; RTC Backup RAM Address
RAMADDR_RAMADDR__SHIFT EQU 000H ; RTC Backup RAM Address
                                                        
;------------------------------------------------------------------------------
; RAMDATA Enums (RTC Backup RAM Data @ 0x0F)
;------------------------------------------------------------------------------
RAMDATA_RAMDATA__FMASK EQU 0FFH ; RTC Backup RAM Data
RAMDATA_RAMDATA__SHIFT EQU 000H ; RTC Backup RAM Data
                                                     
;------------------------------------------------------------------------------
; RTC0ADR Enums (RTC Address @ 0xAC)
;------------------------------------------------------------------------------
RTC0ADR_ADDR__FMASK             EQU 00FH ; RTC Indirect Register Address                     
RTC0ADR_ADDR__SHIFT             EQU 000H ; RTC Indirect Register Address                     
RTC0ADR_ADDR__CAPTURE0          EQU 000H ; Select the CAPTURE0 register.                     
RTC0ADR_ADDR__CAPTURE1          EQU 001H ; Select the CAPTURE1 register.                     
RTC0ADR_ADDR__CAPTURE2          EQU 002H ; Select the CAPTURE2 register.                     
RTC0ADR_ADDR__CAPTURE3          EQU 003H ; Select the CAPTURE3 register.                     
RTC0ADR_ADDR__CAPTURE4          EQU 004H ; Select the CAPTURE4 register.                     
RTC0ADR_ADDR__CAPTURE5          EQU 005H ; Select the CAPTURE5 register.                     
RTC0ADR_ADDR__RTC0CN            EQU 006H ; Select the RTC0CN register.                       
RTC0ADR_ADDR__RTC0XCN           EQU 007H ; Select the RTC0XCN register.                      
RTC0ADR_ADDR__ALARM0            EQU 008H ; Select the ALARM0 register.                       
RTC0ADR_ADDR__ALARM1            EQU 009H ; Select the ALARM1 register.                       
RTC0ADR_ADDR__ALARM2            EQU 00AH ; Select the ALARM2 register.                       
RTC0ADR_ADDR__ALARM3            EQU 00BH ; Select the ALARM3 register.                       
RTC0ADR_ADDR__ALARM4            EQU 00CH ; Select the ALARM4 register.                       
RTC0ADR_ADDR__ALARM5            EQU 00DH ; Select the ALARM5 register.                       
RTC0ADR_ADDR__RAMADDR           EQU 00EH ; Select the RAMADDR register.                      
RTC0ADR_ADDR__RAMDATA           EQU 00FH ; Select the RAMDATA register.                      
                                                                                             
RTC0ADR_SHORT__BMASK            EQU 010H ; Short Strobe Enable                               
RTC0ADR_SHORT__SHIFT            EQU 004H ; Short Strobe Enable                               
RTC0ADR_SHORT__DISABLED         EQU 000H ; Disable short strobe.                             
RTC0ADR_SHORT__ENABLED          EQU 010H ; Enable short strobe.                              
                                                                                             
RTC0ADR_VREGEN__BMASK           EQU 020H ; Backup Supply Voltage Regulator Enable            
RTC0ADR_VREGEN__SHIFT           EQU 005H ; Backup Supply Voltage Regulator Enable            
RTC0ADR_VREGEN__BACKUP_DISABLED EQU 000H ; Disable the backup supply voltage regulator. The  
                                         ; RTC is powered from VDD.                          
RTC0ADR_VREGEN__BACKUP_ENABLED  EQU 020H ; Force the backup supply voltage regulator enabled.
                                         ; The RTC is powered from VRTC-BACKUP.              
                                                                                             
RTC0ADR_AUTORD__BMASK           EQU 040H ; RTC Interface Autoread Enable                     
RTC0ADR_AUTORD__SHIFT           EQU 006H ; RTC Interface Autoread Enable                     
RTC0ADR_AUTORD__DISABLED        EQU 000H ; Disable autoread. Firmware must write the BUSY bit
                                         ; for each RTC indirect read operation.             
RTC0ADR_AUTORD__ENABLED         EQU 040H ; Enable autoread. The next RTC indirect read       
                                         ; operation is initiated when firmware reads the    
                                         ; RTC0DAT register.                                 
                                                                                             
RTC0ADR_BUSY__BMASK             EQU 080H ; RTC Interface Busy Indicator                      
RTC0ADR_BUSY__SHIFT             EQU 007H ; RTC Interface Busy Indicator                      
RTC0ADR_BUSY__NOT_SET           EQU 000H ; The RTC interface is not busy.                    
RTC0ADR_BUSY__SET               EQU 080H ; The RTC interface is busy.                        
                                                                                             
;------------------------------------------------------------------------------
; RTC0CN Enums (RTC Control @ 0x06)
;------------------------------------------------------------------------------
RTC0CN_RTCCAP__BMASK    EQU 001H ; RTC Timer Capture                               
RTC0CN_RTCCAP__SHIFT    EQU 000H ; RTC Timer Capture                               
RTC0CN_RTCCAP__NOT_SET  EQU 000H ; Do not start a capture operation.               
RTC0CN_RTCCAP__SET      EQU 001H ; Start a capture operation.                      
                                                                                   
RTC0CN_RTCSET__BMASK    EQU 002H ; RTC Timer Set                                   
RTC0CN_RTCSET__SHIFT    EQU 001H ; RTC Timer Set                                   
RTC0CN_RTCSET__NOT_SET  EQU 000H ; Do not start a set operation.                   
RTC0CN_RTCSET__SET      EQU 002H ; Start a set operation.                          
                                                                                   
RTC0CN_ALRM__BMASK      EQU 004H ; RTC Alarm Event Flag and Auto Reset Enable      
RTC0CN_ALRM__SHIFT      EQU 002H ; RTC Alarm Event Flag and Auto Reset Enable      
RTC0CN_ALRM__NOT_SET    EQU 000H ; Alarm event flag is not set or disable the auto 
                                 ; reset function.                                 
RTC0CN_ALRM__SET        EQU 004H ; Alarm event flag is set or enable the auto reset
                                 ; function.                                       
                                                                                   
RTC0CN_RTCAEN__BMASK    EQU 008H ; RTC Alarm Enable                                
RTC0CN_RTCAEN__SHIFT    EQU 003H ; RTC Alarm Enable                                
RTC0CN_RTCAEN__DISABLED EQU 000H ; Disable RTC alarm.                              
RTC0CN_RTCAEN__ENABLED  EQU 008H ; Enable RTC alarm.                               
                                                                                   
RTC0CN_RTCTR__BMASK     EQU 010H ; RTC Timer Run Control                           
RTC0CN_RTCTR__SHIFT     EQU 004H ; RTC Timer Run Control                           
RTC0CN_RTCTR__STOP      EQU 000H ; RTC timer is stopped.                           
RTC0CN_RTCTR__RUN       EQU 010H ; RTC timer is running.                           
                                                                                   
RTC0CN_OSCFAIL__BMASK   EQU 020H ; RTC Oscillator Fail Event Flag                  
RTC0CN_OSCFAIL__SHIFT   EQU 005H ; RTC Oscillator Fail Event Flag                  
RTC0CN_OSCFAIL__NOT_SET EQU 000H ; Missing RTC detector timeout did not occur.     
RTC0CN_OSCFAIL__SET     EQU 020H ; Missing RTC detector timeout occurred.          
                                                                                   
RTC0CN_MCLKEN__BMASK    EQU 040H ; Missing RTC Detector Enable                     
RTC0CN_MCLKEN__SHIFT    EQU 006H ; Missing RTC Detector Enable                     
RTC0CN_MCLKEN__DISABLED EQU 000H ; Disable missing RTC detector.                   
RTC0CN_MCLKEN__ENABLED  EQU 040H ; Enable missing RTC detector.                    
                                                                                   
RTC0CN_RTCEN__BMASK     EQU 080H ; RTC Enable                                      
RTC0CN_RTCEN__SHIFT     EQU 007H ; RTC Enable                                      
RTC0CN_RTCEN__DISABLED  EQU 000H ; Disable RTC oscillator.                         
RTC0CN_RTCEN__ENABLED   EQU 080H ; Enable RTC oscillator.                          
                                                                                   
;------------------------------------------------------------------------------
; RTC0DAT Enums (RTC Data @ 0xAD)
;------------------------------------------------------------------------------
RTC0DAT_RTC0DAT__FMASK EQU 0FFH ; RTC Data
RTC0DAT_RTC0DAT__SHIFT EQU 000H ; RTC Data
                                          
;------------------------------------------------------------------------------
; RTC0KEY Enums (RTC Lock and Key @ 0xAE)
;------------------------------------------------------------------------------
RTC0KEY_RTC0ST__FMASK           EQU 0FFH ; RTC Interface Lock/Key and Status                 
RTC0KEY_RTC0ST__SHIFT           EQU 000H ; RTC Interface Lock/Key and Status                 
RTC0KEY_RTC0ST__LOCKED          EQU 000H ; RTC Interface is locked. Writing 0xA5 followed by 
                                         ; 0xF1 unlocks the RTC interface.                   
RTC0KEY_RTC0ST__FIRST           EQU 001H ; RTC Interface is locked, but 0xA5 has already been
                                         ; written. Writing any value other than the second  
                                         ; key code (0xF1) will change this field to 3 and   
                                         ; disable the RTC interface until the next system   
                                         ; reset.                                            
RTC0KEY_RTC0ST__UNLOCKED        EQU 002H ; RTC Interface is unlocked. Any write to the       
                                         ; RTC0KEY register will lock the RTC Interface.     
RTC0KEY_RTC0ST__DISABLED        EQU 003H ; RTC Interface is disabled until the next system   
                                         ; reset. Any writes to RTC0KEY have no effect.      
RTC0KEY_RTC0ST__DISABLE_OR_LOCK EQU 00AH ; Writing any value other than 0xF1 for the second  
                                         ; byte will disable the interface. Writing any value
                                         ; when the interface is unlocked will lock the      
                                         ; interface.                                        
RTC0KEY_RTC0ST__KEY1            EQU 0A5H ; Writing 0xA5 followed by 0xF1 unlocks the RTC     
                                         ; interface.                                        
RTC0KEY_RTC0ST__KEY2            EQU 0F1H ; Writing 0xA5 followed by 0xF1 unlocks the RTC     
                                         ; interface.                                        
                                                                                             
;------------------------------------------------------------------------------
; RTC0XCN Enums (RTC Oscillator Control @ 0x07)
;------------------------------------------------------------------------------
RTC0XCN_VBATEN__BMASK         EQU 001H ; RTC VBAT Indicator                                
RTC0XCN_VBATEN__SHIFT         EQU 000H ; RTC VBAT Indicator                                
RTC0XCN_VBATEN__VDD           EQU 000H ; RTC is powered from VDD.                          
RTC0XCN_VBATEN__VRTC_BACKUP   EQU 001H ; RTC is powered from the VRTC-BACKUP supply.       
                                                                                           
RTC0XCN_CLKVLD__BMASK         EQU 010H ; RTC Oscillator Crystal Valid Indicator            
RTC0XCN_CLKVLD__SHIFT         EQU 004H ; RTC Oscillator Crystal Valid Indicator            
RTC0XCN_CLKVLD__NOT_SET       EQU 000H ; Oscillation has not started or oscillation        
                                       ; amplitude is too low to maintain oscillation.     
RTC0XCN_CLKVLD__SET           EQU 010H ; Sufficient oscillation amplitude detected.        
                                                                                           
RTC0XCN_BIASX2__BMASK         EQU 020H ; RTC Oscillator Bias Double Enable                 
RTC0XCN_BIASX2__SHIFT         EQU 005H ; RTC Oscillator Bias Double Enable                 
RTC0XCN_BIASX2__DISABLED      EQU 000H ; Disable the Bias Double feature.                  
RTC0XCN_BIASX2__ENABLED       EQU 020H ; Enable the Bias Double feature.                   
                                                                                           
RTC0XCN_XMODE__BMASK          EQU 040H ; RTC Oscillator Mode                               
RTC0XCN_XMODE__SHIFT          EQU 006H ; RTC Oscillator Mode                               
RTC0XCN_XMODE__SELF_OSCILLATE EQU 000H ; Self-Oscillate Mode selected.                     
RTC0XCN_XMODE__CRYSTAL        EQU 040H ; Crystal Mode selected.                            
                                                                                           
RTC0XCN_AGCEN__BMASK          EQU 080H ; RTC Oscillator Automatic Gain Control (AGC) Enable
RTC0XCN_AGCEN__SHIFT          EQU 007H ; RTC Oscillator Automatic Gain Control (AGC) Enable
RTC0XCN_AGCEN__DISABLED       EQU 000H ; Disable AGC.                                      
RTC0XCN_AGCEN__ENABLED        EQU 080H ; Enable AGC.                                       
                                                                                           
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
; SMB0CN Enums (SMBus 0 Control @ 0xC0)
;------------------------------------------------------------------------------
SMB0CN_SI__BMASK           EQU 001H ; SMBus Interrupt Flag                           
SMB0CN_SI__SHIFT           EQU 000H ; SMBus Interrupt Flag                           
SMB0CN_SI__NOT_SET         EQU 000H ;                                                
SMB0CN_SI__SET             EQU 001H ;                                                
                                                                                     
SMB0CN_ACK__BMASK          EQU 002H ; SMBus Acknowledge                              
SMB0CN_ACK__SHIFT          EQU 001H ; SMBus Acknowledge                              
SMB0CN_ACK__NOT_SET        EQU 000H ; Generate a NACK, or the response was a NACK.   
SMB0CN_ACK__SET            EQU 002H ; Generate an ACK, or the response was an ACK.   
                                                                                     
SMB0CN_ARBLOST__BMASK      EQU 004H ; SMBus Arbitration Lost Indicator               
SMB0CN_ARBLOST__SHIFT      EQU 002H ; SMBus Arbitration Lost Indicator               
SMB0CN_ARBLOST__NOT_SET    EQU 000H ; No arbitration error.                          
SMB0CN_ARBLOST__ERROR      EQU 004H ; Arbitration error occurred.                    
                                                                                     
SMB0CN_ACKRQ__BMASK        EQU 008H ; SMBus Acknowledge Request                      
SMB0CN_ACKRQ__SHIFT        EQU 003H ; SMBus Acknowledge Request                      
SMB0CN_ACKRQ__NOT_SET      EQU 000H ; No ACK requested.                              
SMB0CN_ACKRQ__REQUESTED    EQU 008H ; ACK requested.                                 
                                                                                     
SMB0CN_STO__BMASK          EQU 010H ; SMBus Stop Flag                                
SMB0CN_STO__SHIFT          EQU 004H ; SMBus Stop Flag                                
SMB0CN_STO__NOT_SET        EQU 000H ; A STOP is not pending.                         
SMB0CN_STO__SET            EQU 010H ; Generate a STOP or a STOP is currently pending.
                                                                                     
SMB0CN_STA__BMASK          EQU 020H ; SMBus Start Flag                               
SMB0CN_STA__SHIFT          EQU 005H ; SMBus Start Flag                               
SMB0CN_STA__NOT_SET        EQU 000H ; A START was not detected.                      
SMB0CN_STA__SET            EQU 020H ; Generate a START, repeated START, or a START is
                                    ; currently pending.                             
                                                                                     
SMB0CN_TXMODE__BMASK       EQU 040H ; SMBus Transmit Mode Indicator                  
SMB0CN_TXMODE__SHIFT       EQU 006H ; SMBus Transmit Mode Indicator                  
SMB0CN_TXMODE__RECEIVER    EQU 000H ; SMBus in Receiver Mode.                        
SMB0CN_TXMODE__TRANSMITTER EQU 040H ; SMBus in Transmitter Mode.                     
                                                                                     
SMB0CN_MASTER__BMASK       EQU 080H ; SMBus Master/Slave Indicator                   
SMB0CN_MASTER__SHIFT       EQU 007H ; SMBus Master/Slave Indicator                   
SMB0CN_MASTER__SLAVE       EQU 000H ; SMBus operating in slave mode.                 
SMB0CN_MASTER__MASTER      EQU 080H ; SMBus operating in master mode.                
                                                                                     
;------------------------------------------------------------------------------
; SMB0DAT Enums (SMBus 0 Data @ 0xC2)
;------------------------------------------------------------------------------
SMB0DAT_SMB0DAT__FMASK EQU 0FFH ; SMBus 0 Data
SMB0DAT_SMB0DAT__SHIFT EQU 000H ; SMBus 0 Data
                                              
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
; SPI0CN Enums (SPI0 Control @ 0xF8)
;------------------------------------------------------------------------------
SPI0CN_SPIEN__BMASK                  EQU 001H ; SPI0 Enable                                       
SPI0CN_SPIEN__SHIFT                  EQU 000H ; SPI0 Enable                                       
SPI0CN_SPIEN__DISABLED               EQU 000H ; Disable the SPI module.                           
SPI0CN_SPIEN__ENABLED                EQU 001H ; Enable the SPI module.                            
                                                                                                  
SPI0CN_TXBMT__BMASK                  EQU 002H ; Transmit Buffer Empty                             
SPI0CN_TXBMT__SHIFT                  EQU 001H ; Transmit Buffer Empty                             
SPI0CN_TXBMT__NOT_SET                EQU 000H ; The transmit buffer is not empty.                 
SPI0CN_TXBMT__SET                    EQU 002H ; The transmit buffer is empty.                     
                                                                                                  
SPI0CN_NSSMD__FMASK                  EQU 00CH ; Slave Select Mode                                 
SPI0CN_NSSMD__SHIFT                  EQU 002H ; Slave Select Mode                                 
SPI0CN_NSSMD__3_WIRE                 EQU 000H ; 3-Wire Slave or 3-Wire Master Mode. NSS signal is 
                                              ; not routed to a port pin.                         
SPI0CN_NSSMD__4_WIRE_SLAVE           EQU 004H ; 4-Wire Slave or Multi-Master Mode. NSS is an input
                                              ; to the device.                                    
SPI0CN_NSSMD__4_WIRE_MASTER_NSS_LOW  EQU 008H ; 4-Wire Single-Master Mode. NSS is an output and   
                                              ; logic low.                                        
SPI0CN_NSSMD__4_WIRE_MASTER_NSS_HIGH EQU 00CH ; 4-Wire Single-Master Mode. NSS is an output and   
                                              ; logic high.                                       
                                                                                                  
SPI0CN_RXOVRN__BMASK                 EQU 010H ; Receive Overrun Flag                              
SPI0CN_RXOVRN__SHIFT                 EQU 004H ; Receive Overrun Flag                              
SPI0CN_RXOVRN__NOT_SET               EQU 000H ; A receive overrun did not occur.                  
SPI0CN_RXOVRN__SET                   EQU 010H ; A receive overrun occurred.                       
                                                                                                  
SPI0CN_MODF__BMASK                   EQU 020H ; Mode Fault Flag                                   
SPI0CN_MODF__SHIFT                   EQU 005H ; Mode Fault Flag                                   
SPI0CN_MODF__NOT_SET                 EQU 000H ; A master collision did not occur.                 
SPI0CN_MODF__SET                     EQU 020H ; A master collision occurred.                      
                                                                                                  
SPI0CN_WCOL__BMASK                   EQU 040H ; Write Collision Flag                              
SPI0CN_WCOL__SHIFT                   EQU 006H ; Write Collision Flag                              
SPI0CN_WCOL__NOT_SET                 EQU 000H ; A write collision did not occur.                  
SPI0CN_WCOL__SET                     EQU 040H ; A write collision occurred.                       
                                                                                                  
SPI0CN_SPIF__BMASK                   EQU 080H ; SPI0 Interrupt Flag                               
SPI0CN_SPIF__SHIFT                   EQU 007H ; SPI0 Interrupt Flag                               
SPI0CN_SPIF__NOT_SET                 EQU 000H ; A data transfer has not completed since the last  
                                              ; time SPIF was cleared.                            
SPI0CN_SPIF__SET                     EQU 080H ; A data transfer completed.                        
                                                                                                  
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
; TMR2CN Enums (Timer 2 Control @ 0xC8)
;------------------------------------------------------------------------------
TMR2CN_T2XCLK__BMASK                      EQU 001H ; Timer 2 External Clock Select                     
TMR2CN_T2XCLK__SHIFT                      EQU 000H ; Timer 2 External Clock Select                     
TMR2CN_T2XCLK__SYSCLK_DIV_12              EQU 000H ; Timer 2 clock is the system clock divided by 12.  
TMR2CN_T2XCLK__T2RCLK                     EQU 001H ; Timer 2 clock is the clock defined by the T2RCLK  
                                                   ; bit.                                              
                                                                                                       
TMR2CN_T2RCLK__BMASK                      EQU 002H ; Timer 2 Capture Mode                              
TMR2CN_T2RCLK__SHIFT                      EQU 001H ; Timer 2 Capture Mode                              
TMR2CN_T2RCLK__EXTOSC_DIV_8_CAP_RTC_DIV_8 EQU 000H ; Capture trigger is RTC / 8. If T2XCLK = 1 and T2ML
                                                   ; = 0, external clock is EXTOSC / 8.                
TMR2CN_T2RCLK__RTC_DIV_8_CAP_EXTOSC_DIV_8 EQU 002H ; Capture trigger is EXTOSC / 8. If T2XCLK = 1 and  
                                                   ; T2ML = 0, external clock is RTC / 8.              
                                                                                                       
TMR2CN_TR2__BMASK                         EQU 004H ; Timer 2 Run Control                               
TMR2CN_TR2__SHIFT                         EQU 002H ; Timer 2 Run Control                               
TMR2CN_TR2__STOP                          EQU 000H ; Stop Timer 2.                                     
TMR2CN_TR2__RUN                           EQU 004H ; Start Timer 2 running.                            
                                                                                                       
TMR2CN_T2SPLIT__BMASK                     EQU 008H ; Timer 2 Split Mode Enable                         
TMR2CN_T2SPLIT__SHIFT                     EQU 003H ; Timer 2 Split Mode Enable                         
TMR2CN_T2SPLIT__16_BIT_RELOAD             EQU 000H ; Timer 2 operates in 16-bit auto-reload mode.      
TMR2CN_T2SPLIT__8_BIT_RELOAD              EQU 008H ; Timer 2 operates as two 8-bit auto-reload timers. 
                                                                                                       
TMR2CN_TF2CEN__BMASK                      EQU 010H ; Timer 2 Capture Enable                            
TMR2CN_TF2CEN__SHIFT                      EQU 004H ; Timer 2 Capture Enable                            
TMR2CN_TF2CEN__DISABLED                   EQU 000H ; Disable capture mode.                             
TMR2CN_TF2CEN__ENABLED                    EQU 010H ; Enable capture mode.                              
                                                                                                       
TMR2CN_TF2LEN__BMASK                      EQU 020H ; Timer 2 Low Byte Interrupt Enable                 
TMR2CN_TF2LEN__SHIFT                      EQU 005H ; Timer 2 Low Byte Interrupt Enable                 
TMR2CN_TF2LEN__DISABLED                   EQU 000H ; Disable low byte interrupts.                      
TMR2CN_TF2LEN__ENABLED                    EQU 020H ; Enable low byte interrupts.                       
                                                                                                       
TMR2CN_TF2L__BMASK                        EQU 040H ; Timer 2 Low Byte Overflow Flag                    
TMR2CN_TF2L__SHIFT                        EQU 006H ; Timer 2 Low Byte Overflow Flag                    
TMR2CN_TF2L__NOT_SET                      EQU 000H ; Timer 2 low byte did not overflow.                
TMR2CN_TF2L__SET                          EQU 040H ; Timer 2 low byte overflowed.                      
                                                                                                       
TMR2CN_TF2H__BMASK                        EQU 080H ; Timer 2 High Byte Overflow Flag                   
TMR2CN_TF2H__SHIFT                        EQU 007H ; Timer 2 High Byte Overflow Flag                   
TMR2CN_TF2H__NOT_SET                      EQU 000H ; Timer 2 8-bit high byte or 16-bit value did not   
                                                   ; overflow.                                         
TMR2CN_TF2H__SET                          EQU 080H ; Timer 2 8-bit high byte or 16-bit value           
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
; TMR3CN Enums (Timer 3 Control @ 0x91)
;------------------------------------------------------------------------------
TMR3CN_T3XCLK__BMASK                      EQU 001H ; Timer 3 External Clock Select                     
TMR3CN_T3XCLK__SHIFT                      EQU 000H ; Timer 3 External Clock Select                     
TMR3CN_T3XCLK__SYSCLK_DIV_12              EQU 000H ; Timer 3 clock is the system clock divided by 12.  
TMR3CN_T3XCLK__T3RCLK                     EQU 001H ; Timer 3 clock is the clock defined by the T3RCLK  
                                                   ; bit.                                              
                                                                                                       
TMR3CN_T3RCLK__BMASK                      EQU 002H ; Timer 3 Capture Mode                              
TMR3CN_T3RCLK__SHIFT                      EQU 001H ; Timer 3 Capture Mode                              
TMR3CN_T3RCLK__EXTOSC_DIV_8_CAP_RTC_DIV_8 EQU 000H ; Capture trigger is RTC / 8. If T3XCLK = 1 and T3ML
                                                   ; = 0, external clock is EXTOSC / 8.                
TMR3CN_T3RCLK__RTC_DIV_8_CAP_EXTOSC_DIV_8 EQU 002H ; Capture trigger is EXTOSC / 8. If T3XCLK = 1 and  
                                                   ; T3ML = 0, external clock is RTC / 8.              
                                                                                                       
TMR3CN_TR3__BMASK                         EQU 004H ; Timer 3 Run Control                               
TMR3CN_TR3__SHIFT                         EQU 002H ; Timer 3 Run Control                               
TMR3CN_TR3__STOP                          EQU 000H ; Stop Timer 3.                                     
TMR3CN_TR3__RUN                           EQU 004H ; Start Timer 3 running.                            
                                                                                                       
TMR3CN_T3SPLIT__BMASK                     EQU 008H ; Timer 3 Split Mode Enable                         
TMR3CN_T3SPLIT__SHIFT                     EQU 003H ; Timer 3 Split Mode Enable                         
TMR3CN_T3SPLIT__16_BIT_RELOAD             EQU 000H ; Timer 3 operates in 16-bit auto-reload mode.      
TMR3CN_T3SPLIT__8_BIT_RELOAD              EQU 008H ; Timer 3 operates as two 8-bit auto-reload timers. 
                                                                                                       
TMR3CN_TF3CEN__BMASK                      EQU 010H ; Timer 3 Capture Enable                            
TMR3CN_TF3CEN__SHIFT                      EQU 004H ; Timer 3 Capture Enable                            
TMR3CN_TF3CEN__DISABLED                   EQU 000H ; Disable capture mode.                             
TMR3CN_TF3CEN__ENABLED                    EQU 010H ; Enable capture mode.                              
                                                                                                       
TMR3CN_TF3LEN__BMASK                      EQU 020H ; Timer 3 Low Byte Interrupt Enable                 
TMR3CN_TF3LEN__SHIFT                      EQU 005H ; Timer 3 Low Byte Interrupt Enable                 
TMR3CN_TF3LEN__DISABLED                   EQU 000H ; Disable low byte interrupts.                      
TMR3CN_TF3LEN__ENABLED                    EQU 020H ; Enable low byte interrupts.                       
                                                                                                       
TMR3CN_TF3L__BMASK                        EQU 040H ; Timer 3 Low Byte Overflow Flag                    
TMR3CN_TF3L__SHIFT                        EQU 006H ; Timer 3 Low Byte Overflow Flag                    
TMR3CN_TF3L__NOT_SET                      EQU 000H ; Timer 3 low byte did not overflow.                
TMR3CN_TF3L__SET                          EQU 040H ; Timer 3 low byte overflowed.                      
                                                                                                       
TMR3CN_TF3H__BMASK                        EQU 080H ; Timer 3 High Byte Overflow Flag                   
TMR3CN_TF3H__SHIFT                        EQU 007H ; Timer 3 High Byte Overflow Flag                   
TMR3CN_TF3H__NOT_SET                      EQU 000H ; Timer 3 8-bit high byte or 16-bit value did not   
                                                   ; overflow.                                         
TMR3CN_TF3H__SET                          EQU 080H ; Timer 3 8-bit high byte or 16-bit value           
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
; CKCON Enums (Clock Control @ 0x8E)
;------------------------------------------------------------------------------
CKCON_SCA__FMASK           EQU 003H ; Timer 0/1 Prescale                             
CKCON_SCA__SHIFT           EQU 000H ; Timer 0/1 Prescale                             
CKCON_SCA__SYSCLK_DIV_12   EQU 000H ; System clock divided by 12.                    
CKCON_SCA__SYSCLK_DIV_4    EQU 001H ; System clock divided by 4.                     
CKCON_SCA__SYSCLK_DIV_48   EQU 002H ; System clock divided by 48.                    
CKCON_SCA__EXTOSC_DIV_8    EQU 003H ; External oscillator divided by 8 (synchronized 
                                    ; with the system clock).                        
                                                                                     
CKCON_T0M__BMASK           EQU 004H ; Timer 0 Clock Select                           
CKCON_T0M__SHIFT           EQU 002H ; Timer 0 Clock Select                           
CKCON_T0M__PRESCALE        EQU 000H ; Counter/Timer 0 uses the clock defined by the  
                                    ; prescale field, SCA.                           
CKCON_T0M__SYSCLK          EQU 004H ; Counter/Timer 0 uses the system clock.         
                                                                                     
CKCON_T1M__BMASK           EQU 008H ; Timer 1 Clock Select                           
CKCON_T1M__SHIFT           EQU 003H ; Timer 1 Clock Select                           
CKCON_T1M__PRESCALE        EQU 000H ; Timer 1 uses the clock defined by the prescale 
                                    ; field, SCA.                                    
CKCON_T1M__SYSCLK          EQU 008H ; Timer 1 uses the system clock.                 
                                                                                     
CKCON_T2ML__BMASK          EQU 010H ; Timer 2 Low Byte Clock Select                  
CKCON_T2ML__SHIFT          EQU 004H ; Timer 2 Low Byte Clock Select                  
CKCON_T2ML__EXTERNAL_CLOCK EQU 000H ; Timer 2 low byte uses the clock defined by the 
                                    ; T2XCLK bit in TMR2CN.                          
CKCON_T2ML__SYSCLK         EQU 010H ; Timer 2 low byte uses the system clock.        
                                                                                     
CKCON_T2MH__BMASK          EQU 020H ; Timer 2 High Byte Clock Select                 
CKCON_T2MH__SHIFT          EQU 005H ; Timer 2 High Byte Clock Select                 
CKCON_T2MH__EXTERNAL_CLOCK EQU 000H ; Timer 2 high byte uses the clock defined by the
                                    ; T2XCLK bit in TMR2CN.                          
CKCON_T2MH__SYSCLK         EQU 020H ; Timer 2 high byte uses the system clock.       
                                                                                     
CKCON_T3ML__BMASK          EQU 040H ; Timer 3 Low Byte Clock Select                  
CKCON_T3ML__SHIFT          EQU 006H ; Timer 3 Low Byte Clock Select                  
CKCON_T3ML__EXTERNAL_CLOCK EQU 000H ; Timer 3 low byte uses the clock defined by the 
                                    ; T3XCLK bit in TMR3CN.                          
CKCON_T3ML__SYSCLK         EQU 040H ; Timer 3 low byte uses the system clock.        
                                                                                     
CKCON_T3MH__BMASK          EQU 080H ; Timer 3 High Byte Clock Select                 
CKCON_T3MH__SHIFT          EQU 007H ; Timer 3 High Byte Clock Select                 
CKCON_T3MH__EXTERNAL_CLOCK EQU 000H ; Timer 3 high byte uses the clock defined by the
                                    ; T3XCLK bit in TMR3CN.                          
CKCON_T3MH__SYSCLK         EQU 080H ; Timer 3 high byte uses the system clock.       
                                                                                     
;------------------------------------------------------------------------------
; TCON Enums (Timer 0/1 Control @ 0x88)
;------------------------------------------------------------------------------
TCON_IT0__BMASK   EQU 001H ; Interrupt 0 Type Select  
TCON_IT0__SHIFT   EQU 000H ; Interrupt 0 Type Select  
TCON_IT0__LEVEL   EQU 000H ; /INT0 is level triggered.
TCON_IT0__EDGE    EQU 001H ; /INT0 is edge triggered. 
                                                      
TCON_IE0__BMASK   EQU 002H ; External Interrupt 0     
TCON_IE0__SHIFT   EQU 001H ; External Interrupt 0     
TCON_IE0__NOT_SET EQU 000H ; Edge/level not detected. 
TCON_IE0__SET     EQU 002H ; Edge/level detected      
                                                      
TCON_IT1__BMASK   EQU 004H ; Interrupt 1 Type Select  
TCON_IT1__SHIFT   EQU 002H ; Interrupt 1 Type Select  
TCON_IT1__LEVEL   EQU 000H ; /INT1 is level triggered.
TCON_IT1__EDGE    EQU 004H ; /INT1 is edge triggered. 
                                                      
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
                              ; defined by T0M in the CKCON register.             
TMOD_CT0__COUNTER    EQU 004H ; Counter Mode. Timer 0 increments on high-to-low   
                              ; transitions of an external pin (T0).              
                                                                                  
TMOD_GATE0__BMASK    EQU 008H ; Timer 0 Gate Control                              
TMOD_GATE0__SHIFT    EQU 003H ; Timer 0 Gate Control                              
TMOD_GATE0__DISABLED EQU 000H ; Timer 0 enabled when TR0 = 1 irrespective of /INT0
                              ; logic level.                                      
TMOD_GATE0__ENABLED  EQU 008H ; Timer 0 enabled only when TR0 = 1 and /INT0 is    
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
                              ; defined by T1M in the CKCON register.             
TMOD_CT1__COUNTER    EQU 040H ; Counter Mode. Timer 1 increments on high-to-low   
                              ; transitions of an external pin (T1).              
                                                                                  
TMOD_GATE1__BMASK    EQU 080H ; Timer 1 Gate Control                              
TMOD_GATE1__SHIFT    EQU 007H ; Timer 1 Gate Control                              
TMOD_GATE1__DISABLED EQU 000H ; Timer 1 enabled when TR1 = 1 irrespective of /INT1
                              ; logic level.                                      
TMOD_GATE1__ENABLED  EQU 080H ; Timer 1 enabled only when TR1 = 1 and /INT1 is    
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
; VDM0CN Enums (VDD Supply Monitor Control @ 0xFF)
;------------------------------------------------------------------------------
VDM0CN_VDMLVL__BMASK      EQU 020H ; VDD Monitor Threshold Level Select              
VDM0CN_VDMLVL__SHIFT      EQU 005H ; VDD Monitor Threshold Level Select              
VDM0CN_VDMLVL__LOW        EQU 000H ; VDD Monitor Threshold is set to VRST-LOW.       
VDM0CN_VDMLVL__HIGH       EQU 020H ; VDD Monitor Threshold is set to VRST-HIGH. This 
                                   ; setting is required for any system with firmware
                                   ; that writes and/or erases flash.                
                                                                                     
VDM0CN_VDDSTAT__BMASK     EQU 040H ; VDD Status                                      
VDM0CN_VDDSTAT__SHIFT     EQU 006H ; VDD Status                                      
VDM0CN_VDDSTAT__VDD_BELOW EQU 000H ; VDD is at or below the VDD monitor threshold.   
VDM0CN_VDDSTAT__VDD_ABOVE EQU 040H ; VDD is above the VDD monitor threshold.         
                                                                                     
VDM0CN_VDMEN__BMASK       EQU 080H ; VDD Monitor Enable                              
VDM0CN_VDMEN__SHIFT       EQU 007H ; VDD Monitor Enable                              
VDM0CN_VDMEN__DISABLED    EQU 000H ; Disable the VDD Monitor.                        
VDM0CN_VDMEN__ENABLED     EQU 080H ; Enable the VDD Monitor.                         
                                                                                     
;------------------------------------------------------------------------------
; REF0CN Enums (Voltage Reference Control @ 0xD1)
;------------------------------------------------------------------------------
REF0CN_REFBE__BMASK         EQU 001H ; Internal Reference Buffer Enable                  
REF0CN_REFBE__SHIFT         EQU 000H ; Internal Reference Buffer Enable                  
REF0CN_REFBE__DISABLED      EQU 000H ; Disable the internal reference buffer.            
REF0CN_REFBE__ENABLED       EQU 001H ; Enable the internal reference buffer. The internal
                                     ; voltage reference is driven on the VREF pin.      
                                                                                         
REF0CN_BIASE__BMASK         EQU 002H ; Internal Analog Bias Generator Enable             
REF0CN_BIASE__SHIFT         EQU 001H ; Internal Analog Bias Generator Enable             
REF0CN_BIASE__DISABLED      EQU 000H ; Disable the internal bias generator.              
REF0CN_BIASE__ENABLED       EQU 002H ; Enable the internal bias generator.               
                                                                                         
REF0CN_TEMPE__BMASK         EQU 004H ; Temperature Sensor Enable                         
REF0CN_TEMPE__SHIFT         EQU 002H ; Temperature Sensor Enable                         
REF0CN_TEMPE__DISABLED      EQU 000H ; Disable the internal Temperature Sensor.          
REF0CN_TEMPE__ENABLED       EQU 004H ; Enable the internal Temperature Sensor.           
                                                                                         
REF0CN_REFSL__BMASK         EQU 008H ; Voltage Reference Select                          
REF0CN_REFSL__SHIFT         EQU 003H ; Voltage Reference Select                          
REF0CN_REFSL__VREF          EQU 000H ; Use the VREF pin as the voltage reference.        
REF0CN_REFSL__VDD           EQU 008H ; Use VDD as the voltage reference.                 
                                                                                         
REF0CN_REFLV__BMASK         EQU 010H ; Voltage Reference Output Level                    
REF0CN_REFLV__SHIFT         EQU 004H ; Voltage Reference Output Level                    
REF0CN_REFLV__1P5           EQU 000H ; Internal voltage reference set to 1.5 V.          
REF0CN_REFLV__2P2           EQU 010H ; Internal voltage reference set to 2.2 V.          
                                                                                         
REF0CN_ZTCEN__BMASK         EQU 020H ; Zero-TempCo Bias Enable                           
REF0CN_ZTCEN__SHIFT         EQU 005H ; Zero-TempCo Bias Enable                           
REF0CN_ZTCEN__AUTOMATIC     EQU 000H ; Zero-TC bias generator automatically enabled when 
                                     ; needed.                                           
REF0CN_ZTCEN__FORCE_ENABLED EQU 020H ; Zero-TC bias generator forced on.                 
                                                                                         
REF0CN_GF__BMASK            EQU 040H ; General Purpose Flag                              
REF0CN_GF__SHIFT            EQU 006H ; General Purpose Flag                              
REF0CN_GF__NOT_SET          EQU 000H ; The GF flag is not set. Clear the GF flag.        
REF0CN_GF__SET              EQU 040H ; The GF flag is set. Set the GF flag.              
                                                                                         
REF0CN_IDAMRG__BMASK        EQU 080H ; IDAC Output Merge Select                          
REF0CN_IDAMRG__SHIFT        EQU 007H ; IDAC Output Merge Select                          
REF0CN_IDAMRG__SEPARATED    EQU 000H ; IDAC1 output is separate from the IDAC0 output.   
REF0CN_IDAMRG__MERGED       EQU 080H ; IDAC1 output is merged with the IDAC0 output on   
                                     ; the same pin as IDAC0.0.                          
                                                                                         
;------------------------------------------------------------------------------
; REG0CN Enums (Voltage Regulator Control @ 0xC9)
;------------------------------------------------------------------------------
REG0CN_DROPOUT__BMASK   EQU 001H ; Voltage Regulator Dropout Indicator     
REG0CN_DROPOUT__SHIFT   EQU 000H ; Voltage Regulator Dropout Indicator     
REG0CN_DROPOUT__NOT_SET EQU 000H ; Voltage Regulator is not in dropout.    
REG0CN_DROPOUT__SET     EQU 001H ; Voltage Regulator is in or near dropout.
                                                                           
REG0CN_REGMD__BMASK     EQU 010H ; Voltage Regulator Output Mode           
REG0CN_REGMD__SHIFT     EQU 004H ; Voltage Regulator Output Mode           
REG0CN_REGMD__2P1       EQU 000H ; Voltage Regulator output is 2.1 V.      
REG0CN_REGMD__2P5       EQU 010H ; Voltage Regulator output is 2.5 V.      
                                                                           
REG0CN_REGDIS__BMASK    EQU 080H ; Voltage Regulator Disable               
REG0CN_REGDIS__SHIFT    EQU 007H ; Voltage Regulator Disable               
REG0CN_REGDIS__ENABLED  EQU 000H ; Enable the Voltage Regulator.           
REG0CN_REGDIS__DISABLED EQU 080H ; Disable the Voltage Regulator.          
                                                                           
;------------------------------------------------------------------------------
; EMI0CN Enums (External Memory Interface Control @ 0xAA)
;------------------------------------------------------------------------------
EMI0CN_PGSEL__FMASK EQU 007H ; XRAM Page Select
EMI0CN_PGSEL__SHIFT EQU 000H ; XRAM Page Select
                                               
