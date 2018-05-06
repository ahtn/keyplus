;------------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; All rights reserved. This program and the accompanying materials
; are made available under the terms of the Silicon Laboratories End User
; License Agreement which accompanies this distribution, and is available at
; http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
; Original content and implementation provided by Silicon Laboratories.
;------------------------------------------------------------------------------
;Supported Devices:
;  C8051F970_GM
;  C8051F971_GM
;  C8051F972_GM
;  C8051F973_GM
;  C8051F974_GM
;  C8051F975_GM

;------------------------------------------------------------------------------
; ADC0AC Enums (ADC0 Accumulator Configuration @ 0xBA)
;------------------------------------------------------------------------------
ADC0AC_ADRPT__FMASK           EQU 007H ; Repeat Count                                      
ADC0AC_ADRPT__SHIFT           EQU 000H ; Repeat Count                                      
ADC0AC_ADRPT__ACC_1           EQU 000H ; Perform and Accumulate 1 conversion.              
ADC0AC_ADRPT__ACC_4           EQU 001H ; Perform and Accumulate 4 conversions.             
ADC0AC_ADRPT__ACC_8           EQU 002H ; Perform and Accumulate 8 conversions.             
ADC0AC_ADRPT__ACC_16          EQU 003H ; Perform and Accumulate 16 conversions.            
ADC0AC_ADRPT__ACC_32          EQU 004H ; Perform and Accumulate 32 conversions.            
ADC0AC_ADRPT__ACC_64          EQU 005H ; Perform and Accumulate 64 conversions.            
                                                                                           
ADC0AC_ADSJST__FMASK          EQU 038H ; Accumulator Shift and Justify                     
ADC0AC_ADSJST__SHIFT          EQU 003H ; Accumulator Shift and Justify                     
ADC0AC_ADSJST__RIGHT_NO_SHIFT EQU 000H ; Right justified. No shifting applied.             
ADC0AC_ADSJST__RIGHT_SHIFT_1  EQU 008H ; Right justified. Shifted right by 1 bit.          
ADC0AC_ADSJST__RIGHT_SHIFT_2  EQU 010H ; Right justified. Shifted right by 2 bits.         
ADC0AC_ADSJST__RIGHT_SHIFT_3  EQU 018H ; Right justified. Shifted right by 3 bits.         
ADC0AC_ADSJST__LEFT_NO_SHIFT  EQU 020H ; Left justified. No shifting applied.              
                                                                                           
ADC0AC_ADAE__BMASK            EQU 040H ; Accumulate Enable                                 
ADC0AC_ADAE__SHIFT            EQU 006H ; Accumulate Enable                                 
ADC0AC_ADAE__ACC_DISABLED     EQU 000H ; ADC0H:ADC0L contain the result of the latest      
                                       ; conversion when Burst Mode is disabled.           
ADC0AC_ADAE__ACC_ENABLED      EQU 040H ; ADC0H:ADC0L contain the accumulated conversion    
                                       ; results when Burst Mode is disabled. Firmware must
                                       ; write 0x0000 to ADC0H:ADC0L to clear the          
                                       ; accumulated result.                               
                                                                                           
;------------------------------------------------------------------------------
; ADC0CF Enums (ADC0 Configuration @ 0x97)
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
                                    ; conversion begins 3 SAR clock cycles following the
                                    ; start-of-conversion signal. The ADC is allowed to 
                                    ; track during this time.                           
                                                                                        
ADC0CF_AD8BE__BMASK        EQU 004H ; 8-Bit Mode Enable                                 
ADC0CF_AD8BE__SHIFT        EQU 002H ; 8-Bit Mode Enable                                 
ADC0CF_AD8BE__NORMAL       EQU 000H ; ADC0 operates in 10-bit mode (normal operation).  
ADC0CF_AD8BE__8_BIT        EQU 004H ; ADC0 operates in 8-bit mode.                      
                                                                                        
ADC0CF_ADSC__FMASK         EQU 0F8H ; SAR Clock Divider                                 
ADC0CF_ADSC__SHIFT         EQU 003H ; SAR Clock Divider                                 
                                                                                        
;------------------------------------------------------------------------------
; ADC0CN Enums (ADC0 Control @ 0xE8)
;------------------------------------------------------------------------------
ADC0CN_ADCM__FMASK            EQU 007H ; Start of Conversion Mode Select                   
ADC0CN_ADCM__SHIFT            EQU 000H ; Start of Conversion Mode Select                   
ADC0CN_ADCM__ADBUSY           EQU 000H ; ADC0 conversion initiated on write of 1 to ADBUSY.
ADC0CN_ADCM__TIMER0           EQU 001H ; ADC0 conversion initiated on overflow of Timer 0. 
ADC0CN_ADCM__TIMER2           EQU 002H ; ADC0 conversion initiated on overflow of Timer 2. 
ADC0CN_ADCM__TIMER3           EQU 003H ; ADC0 conversion initiated on overflow of Timer 3. 
ADC0CN_ADCM__CNVSTR           EQU 004H ; ADC0 conversion initiated on rising edge of       
                                       ; CNVSTR.                                           
                                                                                           
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
ADC0CN_ADBMEN__BURST_DISABLED EQU 000H ; ADC0 Burst Mode Disabled.                         
ADC0CN_ADBMEN__BURST_ENABLED  EQU 040H ; ADC0 Burst Mode Enabled.                          
                                                                                           
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
; ADC0H Enums (ADC0 Data Word High Byte @ 0xD3)
;------------------------------------------------------------------------------
ADC0H_ADC0H__FMASK EQU 0FFH ; Data Word High Byte
ADC0H_ADC0H__SHIFT EQU 000H ; Data Word High Byte
                                                 
;------------------------------------------------------------------------------
; ADC0L Enums (ADC0 Data Word Low Byte @ 0xD2)
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
; ADC0MX Enums (ADC0 Multiplexer Selection @ 0xD4)
;------------------------------------------------------------------------------
ADC0MX_ADC0MX__FMASK  EQU 01FH ; ADC0 Positive Input Selection 
ADC0MX_ADC0MX__SHIFT  EQU 000H ; ADC0 Positive Input Selection 
ADC0MX_ADC0MX__ADC0P0 EQU 000H ; Select channel ADC0.0.        
ADC0MX_ADC0MX__TEMP   EQU 01BH ; Temperature Sensor.           
ADC0MX_ADC0MX__VDD    EQU 01CH ; VDD Supply Voltage.           
ADC0MX_ADC0MX__LDO    EQU 01DH ; Internal LDO regulator output.
ADC0MX_ADC0MX__GND    EQU 01FH ; Ground.                       
                                                               
;------------------------------------------------------------------------------
; ADC0PWR Enums (ADC0 Power Control @ 0xBB)
;------------------------------------------------------------------------------
ADC0PWR_ADPWR__FMASK              EQU 00FH ; Burst Mode Power Up Time                         
ADC0PWR_ADPWR__SHIFT              EQU 000H ; Burst Mode Power Up Time                         
                                                                                              
ADC0PWR_ADLPM__BMASK              EQU 080H ; Low Power Mode Enable                            
ADC0PWR_ADLPM__SHIFT              EQU 007H ; Low Power Mode Enable                            
ADC0PWR_ADLPM__LOW_POWER_DISABLED EQU 000H ; Disable low power mode.                          
ADC0PWR_ADLPM__LOW_POWER_ENABLED  EQU 080H ; Enable low power mode (requires extended tracking
                                           ; time).                                           
                                                                                              
;------------------------------------------------------------------------------
; ADC0TK Enums (ADC0 Burst Mode Track Time @ 0xBC)
;------------------------------------------------------------------------------
ADC0TK_ADTK__FMASK EQU 03FH ; Burst Mode Tracking Time
ADC0TK_ADTK__SHIFT EQU 000H ; Burst Mode Tracking Time
                                                      
;------------------------------------------------------------------------------
; AMUX0P0 Enums (Port 0 Analog Multiplexer Control @ 0x9A)
;------------------------------------------------------------------------------
AMUX0P0_B0__BMASK         EQU 001H ; Port 0 Bit 0 Analog Multiplexor Control        
AMUX0P0_B0__SHIFT         EQU 000H ; Port 0 Bit 0 Analog Multiplexor Control        
AMUX0P0_B0__NOT_CONNECTED EQU 000H ; P0.0 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P0_B0__CONNECTED     EQU 001H ; P0.0 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P0_B1__BMASK         EQU 002H ; Port 0 Bit 1 Analog Multiplexor Control        
AMUX0P0_B1__SHIFT         EQU 001H ; Port 0 Bit 1 Analog Multiplexor Control        
AMUX0P0_B1__NOT_CONNECTED EQU 000H ; P0.1 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P0_B1__CONNECTED     EQU 002H ; P0.1 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P0_B2__BMASK         EQU 004H ; Port 0 Bit 2 Analog Multiplexor Control        
AMUX0P0_B2__SHIFT         EQU 002H ; Port 0 Bit 2 Analog Multiplexor Control        
AMUX0P0_B2__NOT_CONNECTED EQU 000H ; P0.2 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P0_B2__CONNECTED     EQU 004H ; P0.2 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P0_B3__BMASK         EQU 008H ; Port 0 Bit 3 Analog Multiplexor Control        
AMUX0P0_B3__SHIFT         EQU 003H ; Port 0 Bit 3 Analog Multiplexor Control        
AMUX0P0_B3__NOT_CONNECTED EQU 000H ; P0.3 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P0_B3__CONNECTED     EQU 008H ; P0.3 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P0_B4__BMASK         EQU 010H ; Port 0 Bit 4 Analog Multiplexor Control        
AMUX0P0_B4__SHIFT         EQU 004H ; Port 0 Bit 4 Analog Multiplexor Control        
AMUX0P0_B4__NOT_CONNECTED EQU 000H ; P0.4 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P0_B4__CONNECTED     EQU 010H ; P0.4 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P0_B5__BMASK         EQU 020H ; Port 0 Bit 5 Analog Multiplexor Control        
AMUX0P0_B5__SHIFT         EQU 005H ; Port 0 Bit 5 Analog Multiplexor Control        
AMUX0P0_B5__NOT_CONNECTED EQU 000H ; P0.5 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P0_B5__CONNECTED     EQU 020H ; P0.5 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P0_B6__BMASK         EQU 040H ; Port 0 Bit 6 Analog Multiplexor Control        
AMUX0P0_B6__SHIFT         EQU 006H ; Port 0 Bit 6 Analog Multiplexor Control        
AMUX0P0_B6__NOT_CONNECTED EQU 000H ; P0.6 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P0_B6__CONNECTED     EQU 040H ; P0.6 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P0_B7__BMASK         EQU 080H ; Port 0 Bit 7 Analog Multiplexor Control        
AMUX0P0_B7__SHIFT         EQU 007H ; Port 0 Bit 7 Analog Multiplexor Control        
AMUX0P0_B7__NOT_CONNECTED EQU 000H ; P0.7 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P0_B7__CONNECTED     EQU 080H ; P0.7 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
;------------------------------------------------------------------------------
; AMUX0P1 Enums (Port 1 Analog Multiplexer Control @ 0x9B)
;------------------------------------------------------------------------------
AMUX0P1_B0__BMASK         EQU 001H ; Port 1 Bit 0 Analog Multiplexor Control        
AMUX0P1_B0__SHIFT         EQU 000H ; Port 1 Bit 0 Analog Multiplexor Control        
AMUX0P1_B0__NOT_CONNECTED EQU 000H ; P1.0 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P1_B0__CONNECTED     EQU 001H ; P1.0 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P1_B1__BMASK         EQU 002H ; Port 1 Bit 1 Analog Multiplexor Control        
AMUX0P1_B1__SHIFT         EQU 001H ; Port 1 Bit 1 Analog Multiplexor Control        
AMUX0P1_B1__NOT_CONNECTED EQU 000H ; P1.1 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P1_B1__CONNECTED     EQU 002H ; P1.1 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P1_B2__BMASK         EQU 004H ; Port 1 Bit 2 Analog Multiplexor Control        
AMUX0P1_B2__SHIFT         EQU 002H ; Port 1 Bit 2 Analog Multiplexor Control        
AMUX0P1_B2__NOT_CONNECTED EQU 000H ; P1.2 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P1_B2__CONNECTED     EQU 004H ; P1.2 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P1_B3__BMASK         EQU 008H ; Port 1 Bit 3 Analog Multiplexor Control        
AMUX0P1_B3__SHIFT         EQU 003H ; Port 1 Bit 3 Analog Multiplexor Control        
AMUX0P1_B3__NOT_CONNECTED EQU 000H ; P1.3 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P1_B3__CONNECTED     EQU 008H ; P1.3 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P1_B4__BMASK         EQU 010H ; Port 1 Bit 4 Analog Multiplexor Control        
AMUX0P1_B4__SHIFT         EQU 004H ; Port 1 Bit 4 Analog Multiplexor Control        
AMUX0P1_B4__NOT_CONNECTED EQU 000H ; P1.4 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P1_B4__CONNECTED     EQU 010H ; P1.4 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P1_B5__BMASK         EQU 020H ; Port 1 Bit 5 Analog Multiplexor Control        
AMUX0P1_B5__SHIFT         EQU 005H ; Port 1 Bit 5 Analog Multiplexor Control        
AMUX0P1_B5__NOT_CONNECTED EQU 000H ; P1.5 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P1_B5__CONNECTED     EQU 020H ; P1.5 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P1_B6__BMASK         EQU 040H ; Port 1 Bit 6 Analog Multiplexor Control        
AMUX0P1_B6__SHIFT         EQU 006H ; Port 1 Bit 6 Analog Multiplexor Control        
AMUX0P1_B6__NOT_CONNECTED EQU 000H ; P1.6 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P1_B6__CONNECTED     EQU 040H ; P1.6 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P1_B7__BMASK         EQU 080H ; Port 1 Bit 7 Analog Multiplexor Control        
AMUX0P1_B7__SHIFT         EQU 007H ; Port 1 Bit 7 Analog Multiplexor Control        
AMUX0P1_B7__NOT_CONNECTED EQU 000H ; P1.7 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P1_B7__CONNECTED     EQU 080H ; P1.7 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
;------------------------------------------------------------------------------
; AMUX0P2 Enums (Port 2 Analog Multiplexer Control @ 0x9C)
;------------------------------------------------------------------------------
AMUX0P2_B0__BMASK         EQU 001H ; Port 2 Bit 0 Analog Multiplexor Control        
AMUX0P2_B0__SHIFT         EQU 000H ; Port 2 Bit 0 Analog Multiplexor Control        
AMUX0P2_B0__NOT_CONNECTED EQU 000H ; P2.0 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P2_B0__CONNECTED     EQU 001H ; P2.0 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P2_B1__BMASK         EQU 002H ; Port 2 Bit 1 Analog Multiplexor Control        
AMUX0P2_B1__SHIFT         EQU 001H ; Port 2 Bit 1 Analog Multiplexor Control        
AMUX0P2_B1__NOT_CONNECTED EQU 000H ; P2.1 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P2_B1__CONNECTED     EQU 002H ; P2.1 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P2_B2__BMASK         EQU 004H ; Port 2 Bit 2 Analog Multiplexor Control        
AMUX0P2_B2__SHIFT         EQU 002H ; Port 2 Bit 2 Analog Multiplexor Control        
AMUX0P2_B2__NOT_CONNECTED EQU 000H ; P2.2 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P2_B2__CONNECTED     EQU 004H ; P2.2 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P2_B3__BMASK         EQU 008H ; Port 2 Bit 3 Analog Multiplexor Control        
AMUX0P2_B3__SHIFT         EQU 003H ; Port 2 Bit 3 Analog Multiplexor Control        
AMUX0P2_B3__NOT_CONNECTED EQU 000H ; P2.3 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P2_B3__CONNECTED     EQU 008H ; P2.3 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P2_B4__BMASK         EQU 010H ; Port 2 Bit 4 Analog Multiplexor Control        
AMUX0P2_B4__SHIFT         EQU 004H ; Port 2 Bit 4 Analog Multiplexor Control        
AMUX0P2_B4__NOT_CONNECTED EQU 000H ; P2.4 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P2_B4__CONNECTED     EQU 010H ; P2.4 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P2_B5__BMASK         EQU 020H ; Port 2 Bit 5 Analog Multiplexor Control        
AMUX0P2_B5__SHIFT         EQU 005H ; Port 2 Bit 5 Analog Multiplexor Control        
AMUX0P2_B5__NOT_CONNECTED EQU 000H ; P2.5 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P2_B5__CONNECTED     EQU 020H ; P2.5 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P2_B6__BMASK         EQU 040H ; Port 2 Bit 6 Analog Multiplexor Control        
AMUX0P2_B6__SHIFT         EQU 006H ; Port 2 Bit 6 Analog Multiplexor Control        
AMUX0P2_B6__NOT_CONNECTED EQU 000H ; P2.6 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P2_B6__CONNECTED     EQU 040H ; P2.6 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P2_B7__BMASK         EQU 080H ; Port 2 Bit 7 Analog Multiplexor Control        
AMUX0P2_B7__SHIFT         EQU 007H ; Port 2 Bit 7 Analog Multiplexor Control        
AMUX0P2_B7__NOT_CONNECTED EQU 000H ; P2.7 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P2_B7__CONNECTED     EQU 080H ; P2.7 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
;------------------------------------------------------------------------------
; AMUX0P3 Enums (Port 3 Analog Multiplexer Control @ 0xA4)
;------------------------------------------------------------------------------
AMUX0P3_B0__BMASK         EQU 001H ; Port 3 Bit 0 Analog Multiplexor Control        
AMUX0P3_B0__SHIFT         EQU 000H ; Port 3 Bit 0 Analog Multiplexor Control        
AMUX0P3_B0__NOT_CONNECTED EQU 000H ; P3.0 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P3_B0__CONNECTED     EQU 001H ; P3.0 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P3_B1__BMASK         EQU 002H ; Port 3 Bit 1 Analog Multiplexor Control        
AMUX0P3_B1__SHIFT         EQU 001H ; Port 3 Bit 1 Analog Multiplexor Control        
AMUX0P3_B1__NOT_CONNECTED EQU 000H ; P3.1 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P3_B1__CONNECTED     EQU 002H ; P3.1 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P3_B2__BMASK         EQU 004H ; Port 3 Bit 2 Analog Multiplexor Control        
AMUX0P3_B2__SHIFT         EQU 002H ; Port 3 Bit 2 Analog Multiplexor Control        
AMUX0P3_B2__NOT_CONNECTED EQU 000H ; P3.2 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P3_B2__CONNECTED     EQU 004H ; P3.2 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P3_B3__BMASK         EQU 008H ; Port 3 Bit 3 Analog Multiplexor Control        
AMUX0P3_B3__SHIFT         EQU 003H ; Port 3 Bit 3 Analog Multiplexor Control        
AMUX0P3_B3__NOT_CONNECTED EQU 000H ; P3.3 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P3_B3__CONNECTED     EQU 008H ; P3.3 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P3_B4__BMASK         EQU 010H ; Port 3 Bit 4 Analog Multiplexor Control        
AMUX0P3_B4__SHIFT         EQU 004H ; Port 3 Bit 4 Analog Multiplexor Control        
AMUX0P3_B4__NOT_CONNECTED EQU 000H ; P3.4 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P3_B4__CONNECTED     EQU 010H ; P3.4 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P3_B5__BMASK         EQU 020H ; Port 3 Bit 5 Analog Multiplexor Control        
AMUX0P3_B5__SHIFT         EQU 005H ; Port 3 Bit 5 Analog Multiplexor Control        
AMUX0P3_B5__NOT_CONNECTED EQU 000H ; P3.5 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P3_B5__CONNECTED     EQU 020H ; P3.5 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P3_B6__BMASK         EQU 040H ; Port 3 Bit 6 Analog Multiplexor Control        
AMUX0P3_B6__SHIFT         EQU 006H ; Port 3 Bit 6 Analog Multiplexor Control        
AMUX0P3_B6__NOT_CONNECTED EQU 000H ; P3.6 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P3_B6__CONNECTED     EQU 040H ; P3.6 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P3_B7__BMASK         EQU 080H ; Port 3 Bit 7 Analog Multiplexor Control        
AMUX0P3_B7__SHIFT         EQU 007H ; Port 3 Bit 7 Analog Multiplexor Control        
AMUX0P3_B7__NOT_CONNECTED EQU 000H ; P3.7 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P3_B7__CONNECTED     EQU 080H ; P3.7 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
;------------------------------------------------------------------------------
; AMUX0P4 Enums (Port 4 Analog Multiplexer Control @ 0xA5)
;------------------------------------------------------------------------------
AMUX0P4_B0__BMASK         EQU 001H ; Port 4 Bit 0 Analog Multiplexor Control        
AMUX0P4_B0__SHIFT         EQU 000H ; Port 4 Bit 0 Analog Multiplexor Control        
AMUX0P4_B0__NOT_CONNECTED EQU 000H ; P4.0 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P4_B0__CONNECTED     EQU 001H ; P4.0 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P4_B1__BMASK         EQU 002H ; Port 4 Bit 1 Analog Multiplexor Control        
AMUX0P4_B1__SHIFT         EQU 001H ; Port 4 Bit 1 Analog Multiplexor Control        
AMUX0P4_B1__NOT_CONNECTED EQU 000H ; P4.1 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P4_B1__CONNECTED     EQU 002H ; P4.1 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P4_B2__BMASK         EQU 004H ; Port 4 Bit 2 Analog Multiplexor Control        
AMUX0P4_B2__SHIFT         EQU 002H ; Port 4 Bit 2 Analog Multiplexor Control        
AMUX0P4_B2__NOT_CONNECTED EQU 000H ; P4.2 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P4_B2__CONNECTED     EQU 004H ; P4.2 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P4_B3__BMASK         EQU 008H ; Port 4 Bit 3 Analog Multiplexor Control        
AMUX0P4_B3__SHIFT         EQU 003H ; Port 4 Bit 3 Analog Multiplexor Control        
AMUX0P4_B3__NOT_CONNECTED EQU 000H ; P4.3 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P4_B3__CONNECTED     EQU 008H ; P4.3 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P4_B4__BMASK         EQU 010H ; Port 4 Bit 4 Analog Multiplexor Control        
AMUX0P4_B4__SHIFT         EQU 004H ; Port 4 Bit 4 Analog Multiplexor Control        
AMUX0P4_B4__NOT_CONNECTED EQU 000H ; P4.4 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P4_B4__CONNECTED     EQU 010H ; P4.4 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P4_B5__BMASK         EQU 020H ; Port 4 Bit 5 Analog Multiplexor Control        
AMUX0P4_B5__SHIFT         EQU 005H ; Port 4 Bit 5 Analog Multiplexor Control        
AMUX0P4_B5__NOT_CONNECTED EQU 000H ; P4.5 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P4_B5__CONNECTED     EQU 020H ; P4.5 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P4_B6__BMASK         EQU 040H ; Port 4 Bit 6 Analog Multiplexor Control        
AMUX0P4_B6__SHIFT         EQU 006H ; Port 4 Bit 6 Analog Multiplexor Control        
AMUX0P4_B6__NOT_CONNECTED EQU 000H ; P4.6 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P4_B6__CONNECTED     EQU 040H ; P4.6 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P4_B7__BMASK         EQU 080H ; Port 4 Bit 7 Analog Multiplexor Control        
AMUX0P4_B7__SHIFT         EQU 007H ; Port 4 Bit 7 Analog Multiplexor Control        
AMUX0P4_B7__NOT_CONNECTED EQU 000H ; P4.7 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P4_B7__CONNECTED     EQU 080H ; P4.7 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
;------------------------------------------------------------------------------
; AMUX0P5 Enums (Port 5 Analog Multiplexer Control @ 0xA6)
;------------------------------------------------------------------------------
AMUX0P5_B0__BMASK         EQU 001H ; Port 5 Bit 0 Analog Multiplexor Control        
AMUX0P5_B0__SHIFT         EQU 000H ; Port 5 Bit 0 Analog Multiplexor Control        
AMUX0P5_B0__NOT_CONNECTED EQU 000H ; P5.0 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P5_B0__CONNECTED     EQU 001H ; P5.0 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P5_B1__BMASK         EQU 002H ; Port 5 Bit 1 Analog Multiplexor Control        
AMUX0P5_B1__SHIFT         EQU 001H ; Port 5 Bit 1 Analog Multiplexor Control        
AMUX0P5_B1__NOT_CONNECTED EQU 000H ; P5.1 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P5_B1__CONNECTED     EQU 002H ; P5.1 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
AMUX0P5_B2__BMASK         EQU 004H ; Port 5 Bit 2 Analog Multiplexor Control        
AMUX0P5_B2__SHIFT         EQU 002H ; Port 5 Bit 2 Analog Multiplexor Control        
AMUX0P5_B2__NOT_CONNECTED EQU 000H ; P5.2 pin is not connected by the Analog        
                                   ; Multiplexer for CS0 or ADC0 measurements.      
AMUX0P5_B2__CONNECTED     EQU 004H ; P5.2 pin is connected by the Analog Multiplexer
                                   ; for CS0 or ADC0 measurements.                  
                                                                                    
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
; SFRLAST Enums (SFR Page Last @ 0xB3)
;------------------------------------------------------------------------------
SFRLAST_SFRLAST__FMASK EQU 0FFH ; SFR Page Last
SFRLAST_SFRLAST__SHIFT EQU 000H ; SFR Page Last
                                               
;------------------------------------------------------------------------------
; SFRNEXT Enums (SFR Page Next @ 0xF3)
;------------------------------------------------------------------------------
SFRNEXT_SFRNEXT__FMASK EQU 0FFH ; SFR Page Next
SFRNEXT_SFRNEXT__SHIFT EQU 000H ; SFR Page Next
                                               
;------------------------------------------------------------------------------
; SFRPAGE Enums (SFR Page @ 0xA7)
;------------------------------------------------------------------------------
SFRPAGE_SFRPAGE__FMASK EQU 0FFH ; SFR Page
SFRPAGE_SFRPAGE__SHIFT EQU 000H ; SFR Page
                                          
;------------------------------------------------------------------------------
; SFRPGCN Enums (SFR Page Control @ 0xA6)
;------------------------------------------------------------------------------
SFRPGCN_SFRPGEN__BMASK              EQU 001H ; SFR Automatic Page Control Enable                 
SFRPGCN_SFRPGEN__SHIFT              EQU 000H ; SFR Automatic Page Control Enable                 
SFRPGCN_SFRPGEN__AUTO_PAGE_DISABLED EQU 000H ; Disable SFR automatic paging. The C8051 core will 
                                             ; not automatically change to the appropriate SFR   
                                             ; page (i.e., the SFR page that contains the SFRs   
                                             ; for the peripheral/function that was the source of
                                             ; the interrupt).                                   
SFRPGCN_SFRPGEN__AUTO_PAGE_ENABLED  EQU 001H ; Enable SFR automatic paging.  Upon interrupt, the 
                                             ; C8051 will switch the SFR page to the page that   
                                             ; contains the SFRs for the peripheral or function  
                                             ; that is the source of the interrupt.              
                                                                                                 
;------------------------------------------------------------------------------
; SP Enums (Stack Pointer @ 0x81)
;------------------------------------------------------------------------------
SP_SP__FMASK EQU 0FFH ; Stack Pointer
SP_SP__SHIFT EQU 000H ; Stack Pointer
                                     
;------------------------------------------------------------------------------
; CLKMODE Enums (Clock Mode @ 0xF7)
;------------------------------------------------------------------------------
CLKMODE_FCAM__BMASK             EQU 001H ; Force Clock Tree Enable                          
CLKMODE_FCAM__SHIFT             EQU 000H ; Force Clock Tree Enable                          
CLKMODE_FCAM__CLOCK_GATE_ALWAYS EQU 000H ; Clock gating occurs in active and idle mode.     
CLKMODE_FCAM__CLOCK_GATE_IDLE   EQU 001H ; Clock gating occurs only in idle mode.           
                                                                                            
CLKMODE_ECSR__BMASK             EQU 002H ; Clock Request Enable                             
CLKMODE_ECSR__SHIFT             EQU 001H ; Clock Request Enable                             
CLKMODE_ECSR__DISABLED          EQU 000H ; Disable clock requests.                          
CLKMODE_ECSR__ENABLED           EQU 002H ; Clocks will only be requested when an incoming   
                                         ; request is active or a peripheral clock is       
                                         ; enabled.                                         
                                                                                            
CLKMODE_LPME__BMASK             EQU 004H ; Low Power Mode Enable                            
CLKMODE_LPME__SHIFT             EQU 002H ; Low Power Mode Enable                            
CLKMODE_LPME__DISABLED          EQU 000H ; Disable low power active and idle modes.         
CLKMODE_LPME__ENABLED           EQU 004H ; Enable low power active and low power idle modes.
                                                                                            
;------------------------------------------------------------------------------
; CLKSEL Enums (Clock Select @ 0xA9)
;------------------------------------------------------------------------------
CLKSEL_CLKSL__FMASK           EQU 007H ; Clock Source Select                               
CLKSEL_CLKSL__SHIFT           EQU 000H ; Clock Source Select                               
CLKSEL_CLKSL__HFOSC           EQU 000H ; Clock derived from the internal precision High-   
                                       ; Frequency Oscillator.                             
CLKSEL_CLKSL__EXTOSC          EQU 001H ; Clock derived from the External Oscillator        
                                       ; circuit.                                          
CLKSEL_CLKSL__LPO_DIV_8       EQU 002H ; Clock derived from the Internal Low Power         
                                       ; Oscillator divided by 8.                          
CLKSEL_CLKSL__RTC             EQU 003H ; Clock derived from the RTC.                       
CLKSEL_CLKSL__LPOSC           EQU 004H ; Clock derived from the Internal Low Power         
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
                                                                                           
CLKSEL_CLKRDY__BMASK          EQU 080H ; System Clock Divider Clock Ready Flag             
CLKSEL_CLKRDY__SHIFT          EQU 007H ; System Clock Divider Clock Ready Flag             
CLKSEL_CLKRDY__NOT_SET        EQU 000H ; The selected clock divide setting has not been    
                                       ; applied to the system clock.                      
CLKSEL_CLKRDY__SET            EQU 080H ; The selected clock divide setting has been applied
                                       ; to the system clock.                              
                                                                                           
;------------------------------------------------------------------------------
; PCLKEN Enums (Low Power Peripheral Clock Enable @ 0xF6)
;------------------------------------------------------------------------------
PCLKEN_PCLKEN0__BMASK    EQU 001H ; Low Power Idle Mode Peripheral Set 0 Enable       
PCLKEN_PCLKEN0__SHIFT    EQU 000H ; Low Power Idle Mode Peripheral Set 0 Enable       
PCLKEN_PCLKEN0__DISABLED EQU 000H ; Disable clocks of UART0, Timer 3, SPI0, and I2C0  
                                  ; in low power idle mode.                           
PCLKEN_PCLKEN0__ENABLED  EQU 001H ; Enable clocks of UART0, Timer 3, SPI0, and I2C0 in
                                  ; low power idle mode.                              
                                                                                      
PCLKEN_PCLKEN1__BMASK    EQU 002H ; Low Power Idle Mode Peripheral Set 1 Enable       
PCLKEN_PCLKEN1__SHIFT    EQU 001H ; Low Power Idle Mode Peripheral Set 1 Enable       
PCLKEN_PCLKEN1__DISABLED EQU 000H ; Disable clocks of MAC0 in low power idle mode.    
PCLKEN_PCLKEN1__ENABLED  EQU 002H ; Enable clocks of MAC0 in low power idle mode.     
                                                                                      
PCLKEN_PCLKEN2__BMASK    EQU 004H ; Low Power Idle Mode Peripheral Set 2 Enable       
PCLKEN_PCLKEN2__SHIFT    EQU 002H ; Low Power Idle Mode Peripheral Set 2 Enable       
PCLKEN_PCLKEN2__DISABLED EQU 000H ; Disable clocks of PCA0, CS0, and ADC0 in low power
                                  ; idle mode.                                        
PCLKEN_PCLKEN2__ENABLED  EQU 004H ; Enable clocks of PCA0, CS0, and ADC0 in low power 
                                  ; idle mode.                                        
                                                                                      
PCLKEN_PCLKEN3__BMASK    EQU 008H ; Low Power Idle Mode Peripheral Set 3 Enable       
PCLKEN_PCLKEN3__SHIFT    EQU 003H ; Low Power Idle Mode Peripheral Set 3 Enable       
PCLKEN_PCLKEN3__DISABLED EQU 000H ; Disable clocks of Timer 0, 1, 2, CRC0, C2, RTC0,  
                                  ; and Port Match in low power idle mode.            
PCLKEN_PCLKEN3__ENABLED  EQU 008H ; Enable clocks of Timer 0, 1, 2, CRC0, C2, RTC0,   
                                  ; and Port Match in low power idle mode.            
                                                                                      
PCLKEN_PCLKEN4__BMASK    EQU 010H ; Low Power Active Mode Peripheral Set 0 Enable     
PCLKEN_PCLKEN4__SHIFT    EQU 004H ; Low Power Active Mode Peripheral Set 0 Enable     
PCLKEN_PCLKEN4__DISABLED EQU 000H ; Disable clocks of UART0, Timer 3, SPI0, and I2C0  
                                  ; in low power active mode.                         
PCLKEN_PCLKEN4__ENABLED  EQU 010H ; Enable clocks of UART0, Timer 3, SPI0, and I2C0 in
                                  ; low power active mode.                            
                                                                                      
PCLKEN_PCLKEN5__BMASK    EQU 020H ; Low Power Active Mode Peripheral Set 1 Enable     
PCLKEN_PCLKEN5__SHIFT    EQU 005H ; Low Power Active Mode Peripheral Set 1 Enable     
PCLKEN_PCLKEN5__DISABLED EQU 000H ; Disable clocks of MAC0 in low power active mode.  
PCLKEN_PCLKEN5__ENABLED  EQU 020H ; Enable clocks of MAC0 in low power active mode.   
                                                                                      
PCLKEN_PCLKEN6__BMASK    EQU 040H ; Low Power Active Mode Peripheral Set 2 Enable     
PCLKEN_PCLKEN6__SHIFT    EQU 006H ; Low Power Active Mode Peripheral Set 2 Enable     
PCLKEN_PCLKEN6__DISABLED EQU 000H ; Disable clocks of PCA0, CS0, and ADC0 in low power
                                  ; active mode.                                      
PCLKEN_PCLKEN6__ENABLED  EQU 040H ; Enable clocks of PCA0, CS0, and ADC0 in low power 
                                  ; active mode.                                      
                                                                                      
PCLKEN_PCLKEN7__BMASK    EQU 080H ; Low Power Active Mode Peripheral Set 3 Enable     
PCLKEN_PCLKEN7__SHIFT    EQU 007H ; Low Power Active Mode Peripheral Set 3 Enable     
PCLKEN_PCLKEN7__DISABLED EQU 000H ; Disable clocks of Timer 0, 1, 2, CRC0, C2, RTC0,  
                                  ; and Port Match in low power active mode.          
PCLKEN_PCLKEN7__ENABLED  EQU 080H ; Enable clocks of Timer 0, 1, 2, CRC0, C2, RTC0,   
                                  ; and Port Match in low power active mode.          
                                                                                      
;------------------------------------------------------------------------------
; CRC0AUTO Enums (CRC0 Automatic Control @ 0x9E)
;------------------------------------------------------------------------------
CRC0AUTO_CRCST__FMASK     EQU 07FH ; Automatic CRC Calculation Starting Block  
CRC0AUTO_CRCST__SHIFT     EQU 000H ; Automatic CRC Calculation Starting Block  
                                                                               
CRC0AUTO_AUTOEN__BMASK    EQU 080H ; Automatic CRC Calculation Enable          
CRC0AUTO_AUTOEN__SHIFT    EQU 007H ; Automatic CRC Calculation Enable          
CRC0AUTO_AUTOEN__DISABLED EQU 000H ; Disable automatic CRC operations on flash.
CRC0AUTO_AUTOEN__ENABLED  EQU 080H ; Enable automatic CRC operations on flash. 
                                                                               
;------------------------------------------------------------------------------
; CRC0CN Enums (CRC0 Control @ 0x84)
;------------------------------------------------------------------------------
CRC0CN_CRCPNT__BMASK        EQU 001H ; CRC Result Pointer                               
CRC0CN_CRCPNT__SHIFT        EQU 000H ; CRC Result Pointer                               
CRC0CN_CRCPNT__ACCESS_LOWER EQU 000H ; CRC0DAT accesses bits 7-0 of the 16-bit CRC      
                                     ; result.                                          
CRC0CN_CRCPNT__ACCESS_UPPER EQU 001H ; CRC0DAT accesses bits 15-8 of the 16-bit CRC     
                                     ; result.                                          
                                                                                        
CRC0CN_CRCVAL__BMASK        EQU 004H ; CRC Initialization Value                         
CRC0CN_CRCVAL__SHIFT        EQU 002H ; CRC Initialization Value                         
CRC0CN_CRCVAL__SET_ZEROES   EQU 000H ; CRC result is set to 0x0000 on write of 1 to     
                                     ; CRCINIT.                                         
CRC0CN_CRCVAL__SET_ONES     EQU 004H ; CRC result is set to 0xFFFF on write of 1 to     
                                     ; CRCINIT.                                         
                                                                                        
CRC0CN_CRCINIT__BMASK       EQU 008H ; CRC Initialization Enable                        
CRC0CN_CRCINIT__SHIFT       EQU 003H ; CRC Initialization Enable                        
CRC0CN_CRCINIT__DO_NOT_INIT EQU 000H ; Do not initialize the CRC result.                
CRC0CN_CRCINIT__INIT        EQU 008H ; Initialize the CRC result to ones or zeroes vased
                                     ; on the value of CRCVAL.                          
                                                                                        
;------------------------------------------------------------------------------
; CRC0CNT Enums (CRC0 Automatic Flash Sector Count @ 0x9D)
;------------------------------------------------------------------------------
CRC0CNT_CRCCNT__FMASK  EQU 07FH ; Automatic CRC Calculation Block Count
CRC0CNT_CRCCNT__SHIFT  EQU 000H ; Automatic CRC Calculation Block Count
                                                                       
CRC0CNT_CRCDN__BMASK   EQU 080H ; Automatic CRC Calculation Complete   
CRC0CNT_CRCDN__SHIFT   EQU 007H ; Automatic CRC Calculation Complete   
CRC0CNT_CRCDN__NOT_SET EQU 000H ; A CRC calculation is in progress.    
CRC0CNT_CRCDN__SET     EQU 080H ; A CRC calculation is not in progress.
                                                                       
;------------------------------------------------------------------------------
; CRC0DAT Enums (CRC0 Data Output @ 0x86)
;------------------------------------------------------------------------------
CRC0DAT_CRC0DAT__FMASK EQU 0FFH ; CRC Data Output
CRC0DAT_CRC0DAT__SHIFT EQU 000H ; CRC Data Output
                                                 
;------------------------------------------------------------------------------
; CRC0FLIP Enums (CRC0 Bit Flip @ 0x9F)
;------------------------------------------------------------------------------
CRC0FLIP_CRC0FLIP__FMASK EQU 0FFH ; CRC0 Bit Flip
CRC0FLIP_CRC0FLIP__SHIFT EQU 000H ; CRC0 Bit Flip
                                                 
;------------------------------------------------------------------------------
; CRC0IN Enums (CRC0 Data Input @ 0x85)
;------------------------------------------------------------------------------
CRC0IN_CRC0IN__FMASK EQU 0FFH ; CRC Data Input
CRC0IN_CRC0IN__SHIFT EQU 000H ; CRC Data Input
                                              
;------------------------------------------------------------------------------
; CS0CF Enums (Capacitive Sense 0 Configuration @ 0xAA)
;------------------------------------------------------------------------------
CS0CF_CS0ACU__FMASK               EQU 007H ; CS0 Accumulator Mode Select                       
CS0CF_CS0ACU__SHIFT               EQU 000H ; CS0 Accumulator Mode Select                       
CS0CF_CS0ACU__ACC_1               EQU 000H ; Accumulate 1 sample.                              
CS0CF_CS0ACU__ACC_4               EQU 001H ; Accumulate 4 samples.                             
CS0CF_CS0ACU__ACC_8               EQU 002H ; Accumulate 8 samples.                             
CS0CF_CS0ACU__ACC_16              EQU 003H ; Accumulate 16 samples                             
CS0CF_CS0ACU__ACC_32              EQU 004H ; Accumulate 32 samples.                            
CS0CF_CS0ACU__ACC_64              EQU 005H ; Accumulate 64 samples.                            
                                                                                               
CS0CF_CS0MCEN__BMASK              EQU 008H ; CS0 Multiple Channel Enable                       
CS0CF_CS0MCEN__SHIFT              EQU 003H ; CS0 Multiple Channel Enable                       
CS0CF_CS0MCEN__MULT_CHAN_DISABLED EQU 000H ; Multiple channel feature is disabled.             
CS0CF_CS0MCEN__MULT_CHAN_ENABLED  EQU 008H ; Channels selected by the AMUX0 registers are      
                                           ; internally shorted together and the combined node 
                                           ; is selected as the CS0 input. This mode can be    
                                           ; used to detect a capacitance change on multiple   
                                           ; channels using a single conversion.               
                                                                                               
CS0CF_CS0CM__FMASK                EQU 070H ; CS0 Start of Conversion Mode Select               
CS0CF_CS0CM__SHIFT                EQU 004H ; CS0 Start of Conversion Mode Select               
CS0CF_CS0CM__CS0BUSY              EQU 000H ; Conversion initiated on every write of 1 to       
                                           ; CS0BUSY.                                          
CS0CF_CS0CM__TIMER0               EQU 010H ; Conversion initiated on overflow of Timer 0.      
CS0CF_CS0CM__TIMER2               EQU 020H ; Conversion initiated on overflow of Timer 2.      
CS0CF_CS0CM__TIMER1               EQU 030H ; Conversion initiated on overflow of Timer 1.      
CS0CF_CS0CM__TIMER3               EQU 040H ; Conversion initiated on overflow of Timer 3.      
CS0CF_CS0CM__SINGLE_SCAN          EQU 050H ; When CS0SMEN is set to 1, the converter completes 
                                           ; a Single Scan of the channels selected by the     
                                           ; AMUX0 registers. This setting is invalid when     
                                           ; CS0SMEN is cleared to 0.                          
CS0CF_CS0CM__SINGLE_CONTINUOUS    EQU 060H ; Conversion initiated continuously on the channel  
                                           ; selected by CS0MX after writing 1 to CS0BUSY.     
CS0CF_CS0CM__AUTO_SCAN            EQU 070H ; When CS0SMEN is set to 1, the converter enters    
                                           ; Auto Scan Mode and continuously scans the channels
                                           ; selected by the AMUX0 registers. When CS0SMEN is  
                                           ; cleared to 0, the converter scans continuously on 
                                           ; channels from CS0SS to CS0SE after firmware writes
                                           ; 1 to CS0BUSY.                                     
                                                                                               
CS0CF_CS0SMEN__BMASK              EQU 080H ; CS0 Channel Scan Masking Enable                   
CS0CF_CS0SMEN__SHIFT              EQU 007H ; CS0 Channel Scan Masking Enable                   
CS0CF_CS0SMEN__SCAN_MASK_DISABLED EQU 000H ; The AMUX0 register contents are ignored.          
CS0CF_CS0SMEN__SCAN_MASK_ENABLED  EQU 080H ; The AMUX0 registers determine which channels will 
                                           ; be included in the scan.                          
                                                                                               
;------------------------------------------------------------------------------
; CS0CN Enums (Capacitive Sense 0 Control @ 0xB0)
;------------------------------------------------------------------------------
CS0CN_CSCMPF__BMASK     EQU 001H ; CS0 Digital Comparator Interrupt Flag             
CS0CN_CSCMPF__SHIFT     EQU 000H ; CS0 Digital Comparator Interrupt Flag             
CS0CN_CSCMPF__NOT_SET   EQU 000H ; CS0 result is smaller than the value set by CS0THH
                                 ; and CS0THL since the last time CS0CMPF was        
                                 ; cleared.                                          
CS0CN_CSCMPF__SET       EQU 001H ; CS0 result is greater than the value set by CS0THH
                                 ; and CS0THL since the last time CS0CMPF was        
                                 ; cleared.                                          
                                                                                     
CS0CN_CSPME__BMASK      EQU 002H ; CS0 Pin Monitor Event                             
CS0CN_CSPME__SHIFT      EQU 001H ; CS0 Pin Monitor Event                             
CS0CN_CSPME__NO_RETRIES EQU 000H ; Converter re-tries have not occurred.             
CS0CN_CSPME__RETRIES    EQU 002H ; Converter re-tries occurred.                      
                                                                                     
CS0CN_CSCMPEN__BMASK    EQU 008H ; CS0 Digital Comparator Enable                     
CS0CN_CSCMPEN__SHIFT    EQU 003H ; CS0 Digital Comparator Enable                     
CS0CN_CSCMPEN__DISABLED EQU 000H ; Disable CS0 digital comparator.                   
CS0CN_CSCMPEN__ENABLED  EQU 008H ; Enable CS0 digital comparator.                    
                                                                                     
CS0CN_CSBUSY__BMASK     EQU 010H ; CS0 Busy                                          
CS0CN_CSBUSY__SHIFT     EQU 004H ; CS0 Busy                                          
CS0CN_CSBUSY__NOT_SET   EQU 000H ; A CS0 conversion is not currently in progress.    
CS0CN_CSBUSY__SET       EQU 010H ; CS0 conversion is in progress or start a CS0      
                                 ; conversion.                                       
                                                                                     
CS0CN_CSINT__BMASK      EQU 020H ; CS0 Interrupt Flag                                
CS0CN_CSINT__SHIFT      EQU 005H ; CS0 Interrupt Flag                                
CS0CN_CSINT__NOT_SET    EQU 000H ; CS0 has not completed a data conversion since the 
                                 ; last time CS0INT was cleared.                     
CS0CN_CSINT__SET        EQU 020H ; CS0 has completed a data conversion.              
                                                                                     
CS0CN_CSEOS__BMASK      EQU 040H ; CS0 End of Scan Interrupt Flag                    
CS0CN_CSEOS__SHIFT      EQU 006H ; CS0 End of Scan Interrupt Flag                    
CS0CN_CSEOS__NOT_SET    EQU 000H ; CS0 has not completed a scan since the last time  
                                 ; CS0EOS was cleared.                               
CS0CN_CSEOS__SET        EQU 040H ; CS0 has completed a scan.                         
                                                                                     
CS0CN_CSEN__BMASK       EQU 080H ; CS0 Enable                                        
CS0CN_CSEN__SHIFT       EQU 007H ; CS0 Enable                                        
CS0CN_CSEN__DISABLED    EQU 000H ; CS0 disabled and in low-power mode.               
CS0CN_CSEN__ENABLED     EQU 080H ; CS0 enabled and ready to convert.                 
                                                                                     
;------------------------------------------------------------------------------
; CS0DH Enums (Capacitive Sense 0 Data High Byte @ 0xEE)
;------------------------------------------------------------------------------
CS0DH_CS0DH__FMASK EQU 0FFH ; CS0 Data High Byte
CS0DH_CS0DH__SHIFT EQU 000H ; CS0 Data High Byte
                                                
;------------------------------------------------------------------------------
; CS0DL Enums (Capacitive Sense 0 Data Low Byte @ 0xED)
;------------------------------------------------------------------------------
CS0DL_CS0DL__FMASK EQU 0FFH ; CS0 Data Low Byte
CS0DL_CS0DL__SHIFT EQU 000H ; CS0 Data Low Byte
                                               
;------------------------------------------------------------------------------
; CS0MD1 Enums (Capacitive Sense 0 Mode 1 @ 0xBD)
;------------------------------------------------------------------------------
CS0MD1_CS0CG__FMASK                 EQU 007H ; CS0 Capacitance Gain Select                       
CS0MD1_CS0CG__SHIFT                 EQU 000H ; CS0 Capacitance Gain Select                       
CS0MD1_CS0CG__GAIN_1                EQU 000H ; Gain = 1x                                         
CS0MD1_CS0CG__GAIN_2                EQU 001H ; Gain = 2x                                         
CS0MD1_CS0CG__GAIN_3                EQU 002H ; Gain = 3x                                         
CS0MD1_CS0CG__GAIN_4                EQU 003H ; Gain = 4x                                         
CS0MD1_CS0CG__GAIN_5                EQU 004H ; Gain = 5x                                         
CS0MD1_CS0CG__GAIN_6                EQU 005H ; Gain = 6x                                         
CS0MD1_CS0CG__GAIN_7                EQU 006H ; Gain = 7x                                         
CS0MD1_CS0CG__GAIN_8                EQU 007H ; Gain = 8x                                         
                                                                                                 
CS0MD1_CS0WOI__BMASK                EQU 008H ; CS0 Wake on Interrupt Configuration               
CS0MD1_CS0WOI__SHIFT                EQU 003H ; CS0 Wake on Interrupt Configuration               
CS0MD1_CS0WOI__COMPARATOR_ONLY      EQU 000H ; Wake-up event generated on digital comparator     
                                             ; interrupt only.                                   
CS0MD1_CS0WOI__EOS_OR_COMPARATOR    EQU 008H ; Wake-up event generated on end of scan or digital 
                                             ; comparator interrupt.                             
                                                                                                 
CS0MD1_CS0DR__FMASK                 EQU 030H ; CS0 Double Reset Select                           
CS0MD1_CS0DR__SHIFT                 EQU 004H ; CS0 Double Reset Select                           
CS0MD1_CS0DR__DOUBLE_RESET_DISABLED EQU 000H ; No additional time is used for secondary reset.   
CS0MD1_CS0DR__ADD_0P75              EQU 010H ; An additional 0.75 us is used for secondary reset.
CS0MD1_CS0DR__ADD_1P5               EQU 020H ; An additional 1.5 us is used for secondary reset. 
CS0MD1_CS0DR__ADD_2P25              EQU 030H ; An additional 2.25 us is used for secondary reset.
                                                                                                 
CS0MD1_CS0POL__BMASK                EQU 040H ; CS0 Digital Comparator Polarity Select            
CS0MD1_CS0POL__SHIFT                EQU 006H ; CS0 Digital Comparator Polarity Select            
CS0MD1_CS0POL__GREATER_THAN         EQU 000H ; The digital comparator generates an interrupt if  
                                             ; the conversion is greater than the threshold.     
CS0MD1_CS0POL__LESS_THAN_OR_EQUAL   EQU 040H ; The digital comparator generates an interrupt if  
                                             ; the conversion is less than or equal to the       
                                             ; threshold.                                        
                                                                                                 
;------------------------------------------------------------------------------
; CS0MD2 Enums (Capacitive Sense 0 Mode 2 @ 0xBE)
;------------------------------------------------------------------------------
CS0MD2_CS0IA__FMASK           EQU 007H ; CS0 Output Current Adjustment                     
CS0MD2_CS0IA__SHIFT           EQU 000H ; CS0 Output Current Adjustment                     
CS0MD2_CS0IA__CURRENT_MODE0   EQU 000H ; Full current.                                     
CS0MD2_CS0IA__CURRENT_MODE1   EQU 001H ; 1/8 current.                                      
CS0MD2_CS0IA__CURRENT_MODE2   EQU 002H ; 1/4 current.                                      
CS0MD2_CS0IA__CURRENT_MODE3   EQU 003H ; 3/8 current.                                      
CS0MD2_CS0IA__CURRENT_MODE4   EQU 004H ; 1/2 current.                                      
CS0MD2_CS0IA__CURRENT_MODE5   EQU 005H ; 5/8 current.                                      
CS0MD2_CS0IA__CURRENT_MODE6   EQU 006H ; 3/4 current.                                      
CS0MD2_CS0IA__CURRENT_MODE7   EQU 007H ; 7/8 current.                                      
                                                                                           
CS0MD2_CS0DT__FMASK           EQU 038H ; CS0 Discharge Time                                
CS0MD2_CS0DT__SHIFT           EQU 003H ; CS0 Discharge Time                                
CS0MD2_CS0DT__DISCHARGE_MODE0 EQU 000H ; Discharge time is 0.75 us (recommended for most   
                                       ; switches).                                        
CS0MD2_CS0DT__DISCHARGE_MODE1 EQU 008H ; Discharge time is 1.0 us.                         
CS0MD2_CS0DT__DISCHARGE_MODE2 EQU 010H ; Discharge time is 1.2 us.                         
CS0MD2_CS0DT__DISCHARGE_MODE3 EQU 018H ; Discharge time is 1.5 us.                         
CS0MD2_CS0DT__DISCHARGE_MODE4 EQU 020H ; Discharge time is 2 us.                           
CS0MD2_CS0DT__DISCHARGE_MODE5 EQU 028H ; Discharge time is 3 us.                           
CS0MD2_CS0DT__DISCHARGE_MODE6 EQU 030H ; Discharge time is 6 us.                           
CS0MD2_CS0DT__DISCHARGE_MODE7 EQU 038H ; Discharge time is 12 us.                          
                                                                                           
CS0MD2_CS0CR__FMASK           EQU 0C0H ; CS0 Conversion Rate                               
CS0MD2_CS0CR__SHIFT           EQU 006H ; CS0 Conversion Rate                               
CS0MD2_CS0CR__12_BITS         EQU 000H ; Conversions last 12 internal CS0 clocks and are 12
                                       ; bits in length.                                   
CS0MD2_CS0CR__13_BITS         EQU 040H ; Conversions last 13 internal CS0 clocks and are 13
                                       ; bits in length.                                   
CS0MD2_CS0CR__14_BITS         EQU 080H ; Conversions last 14 internal CS0 clocks and are 14
                                       ; bits in length.                                   
CS0MD2_CS0CR__16_BITS         EQU 0C0H ; Conversions last 16 internal CS0 clocks.and are 16
                                       ; bits in length.                                   
                                                                                           
;------------------------------------------------------------------------------
; CS0MD3 Enums (Capacitive Sense 0 Mode 3 @ 0xBF)
;------------------------------------------------------------------------------
CS0MD3_CS0LP__FMASK      EQU 007H ; CS0 Low Pass Filter Selection        
CS0MD3_CS0LP__SHIFT      EQU 000H ; CS0 Low Pass Filter Selection        
                                                                         
CS0MD3_CS0RP__FMASK      EQU 018H ; CS0 Ramp Selection                   
CS0MD3_CS0RP__SHIFT      EQU 003H ; CS0 Ramp Selection                   
CS0MD3_CS0RP__RAMP_MODE0 EQU 000H ; Ramp time is less than 1.5 us.       
CS0MD3_CS0RP__RAMP_MODE1 EQU 008H ; Ramp time is between 1.5 us and 3 us.
CS0MD3_CS0RP__RAMP_MODE2 EQU 010H ; Ramp time is between 3 us and 6 us.  
CS0MD3_CS0RP__RAMP_MODE3 EQU 018H ; Ramp time is greater than 6 us.      
                                                                         
;------------------------------------------------------------------------------
; CS0MX Enums (Capacitive Sense 0 Mux Channel Select @ 0xAB)
;------------------------------------------------------------------------------
CS0MX_CS0MX__FMASK             EQU 03FH ; CS0 Mux Channel Select          
CS0MX_CS0MX__SHIFT             EQU 000H ; CS0 Mux Channel Select          
CS0MX_CS0MX__CS0P0             EQU 000H ; Select CS0.0.                   
CS0MX_CS0MX__CS0P1             EQU 001H ; Select CS0.1.                   
CS0MX_CS0MX__CS0P2             EQU 002H ; Select CS0.2.                   
CS0MX_CS0MX__CS0P3             EQU 003H ; Select CS0.3.                   
CS0MX_CS0MX__CS0P4             EQU 004H ; Select CS0.4.                   
CS0MX_CS0MX__CS0P5             EQU 005H ; Select CS0.5.                   
CS0MX_CS0MX__CS0P6             EQU 006H ; Select CS0.6.                   
CS0MX_CS0MX__CS0P7             EQU 007H ; Select CS0.7.                   
CS0MX_CS0MX__CS0P8             EQU 008H ; Select CS0.8.                   
CS0MX_CS0MX__CS0P9             EQU 009H ; Select CS0.9.                   
CS0MX_CS0MX__CS0P10            EQU 00AH ; Select CS0.10.                  
CS0MX_CS0MX__CS0P11            EQU 00BH ; Select CS0.11.                  
CS0MX_CS0MX__CS0P12            EQU 00CH ; Select CS0.12.                  
CS0MX_CS0MX__CS0P13            EQU 00DH ; Select CS0.13.                  
CS0MX_CS0MX__CS0P14            EQU 00EH ; Select CS0.14.                  
CS0MX_CS0MX__CS0P15            EQU 00FH ; Select CS0.15.                  
CS0MX_CS0MX__CS0P16            EQU 010H ; Select CS0.16.                  
CS0MX_CS0MX__CS0P17            EQU 011H ; Select CS0.17.                  
CS0MX_CS0MX__CS0P18            EQU 012H ; Select CS0.18.                  
CS0MX_CS0MX__CS0P19            EQU 013H ; Select CS0.19.                  
CS0MX_CS0MX__CS0P20            EQU 014H ; Select CS0.20.                  
CS0MX_CS0MX__CS0P21            EQU 015H ; Select CS0.21.                  
CS0MX_CS0MX__CS0P22            EQU 016H ; Select CS0.22.                  
CS0MX_CS0MX__CS0P23            EQU 017H ; Select CS0.23.                  
CS0MX_CS0MX__CS0P24            EQU 018H ; Select CS0.24.                  
CS0MX_CS0MX__CS0P25            EQU 019H ; Select CS0.25.                  
CS0MX_CS0MX__CS0P26            EQU 01AH ; Select CS0.26.                  
CS0MX_CS0MX__CS0P27            EQU 01BH ; Select CS0.27.                  
CS0MX_CS0MX__CS0P28            EQU 01CH ; Select CS0.28.                  
CS0MX_CS0MX__CS0P29            EQU 01DH ; Select CS0.29.                  
CS0MX_CS0MX__CS0P30            EQU 01EH ; Select CS0.30.                  
CS0MX_CS0MX__CS0P31            EQU 01FH ; Select CS0.31.                  
CS0MX_CS0MX__CS0P32            EQU 020H ; Select CS0.32.                  
CS0MX_CS0MX__CS0P33            EQU 021H ; Select CS0.33.                  
CS0MX_CS0MX__CS0P34            EQU 022H ; Select CS0.34.                  
CS0MX_CS0MX__CS0P35            EQU 023H ; Select CS0.35.                  
CS0MX_CS0MX__CS0P36            EQU 024H ; Select CS0.36.                  
CS0MX_CS0MX__CS0P37            EQU 025H ; Select CS0.37.                  
CS0MX_CS0MX__CS0P38            EQU 026H ; Select CS0.38.                  
CS0MX_CS0MX__CS0P39            EQU 027H ; Select CS0.39.                  
CS0MX_CS0MX__CS0P40            EQU 028H ; Select CS0.40.                  
CS0MX_CS0MX__CS0P41            EQU 029H ; Select CS0.41.                  
CS0MX_CS0MX__CS0P42            EQU 02AH ; Select CS0.42.                  
                                                                          
CS0MX_CS0UC__BMASK             EQU 080H ; CS0 Connect                     
CS0MX_CS0UC__SHIFT             EQU 007H ; CS0 Connect                     
CS0MX_CS0UC__PINS_CONNECTED    EQU 000H ; CS0 connected to port pins.     
CS0MX_CS0UC__PINS_DISCONNECTED EQU 080H ; CS0 disconnected from port pins.
                                                                          
;------------------------------------------------------------------------------
; CS0PM Enums (Capacitive Sense 0 Pin Monitor @ 0x96)
;------------------------------------------------------------------------------
CS0PM_CSPMMD__FMASK                 EQU 003H ; CS0 Pin Monitor Mode                             
CS0PM_CSPMMD__SHIFT                 EQU 000H ; CS0 Pin Monitor Mode                             
CS0PM_CSPMMD__ALWAYS_RETRY          EQU 000H ; Always retry bit cycles on a pin state change.   
CS0PM_CSPMMD__RETRY_TWO_TIMES       EQU 001H ; Retry up to twice on consecutive bit cycles.     
CS0PM_CSPMMD__RETRY_FOUR_TIMES      EQU 002H ; Retry up to four times on consecutive bit cycles.
                                                                                                
CS0PM_I2C0PM__BMASK                 EQU 004H ; I2C Slave Pin Monitor Enable                     
CS0PM_I2C0PM__SHIFT                 EQU 002H ; I2C Slave Pin Monitor Enable                     
CS0PM_I2C0PM__PORT_MONITOR_DISABLED EQU 000H ; Disable monitoring of the I2C Slave output pin.  
CS0PM_I2C0PM__PORT_MONITOR_ENABLED  EQU 004H ; Enable monitoring of the I2C Slave output pin.   
                                                                                                
CS0PM_PIOPM__BMASK                  EQU 008H ; Port I/O Pin Monitor Enable                      
CS0PM_PIOPM__SHIFT                  EQU 003H ; Port I/O Pin Monitor Enable                      
CS0PM_PIOPM__PORT_MONITOR_DISABLED  EQU 000H ; Disable monitoring of writes to the port latches.
CS0PM_PIOPM__PORT_MONITOR_ENABLED   EQU 008H ; Enable monitoring of writes to the port latches. 
                                                                                                
CS0PM_PCAPM__BMASK                  EQU 010H ; PCA Pin Monitor Enable                           
CS0PM_PCAPM__SHIFT                  EQU 004H ; PCA Pin Monitor Enable                           
CS0PM_PCAPM__PCA_MONITOR_DISABLED   EQU 000H ; Disable monitoring on the PCA output pins.       
CS0PM_PCAPM__PCA_MONITOR_ENABLED    EQU 010H ; Enable monitoring on the PCA output pins.        
                                                                                                
CS0PM_SMBPM__BMASK                  EQU 020H ; SMBus Pin Monitor Enable                         
CS0PM_SMBPM__SHIFT                  EQU 005H ; SMBus Pin Monitor Enable                         
CS0PM_SMBPM__SMBUS_MONITOR_DISABLED EQU 000H ; Disable monitoring on the SMBus pins.            
CS0PM_SMBPM__SMBUS_MONITOR_ENABLED  EQU 020H ; Enable monitoring on the SMBus pins.             
                                                                                                
CS0PM_SPIPM__BMASK                  EQU 040H ; SPI Pin Monitor Enable                           
CS0PM_SPIPM__SHIFT                  EQU 006H ; SPI Pin Monitor Enable                           
CS0PM_SPIPM__SPI_MONITOR_DISABLED   EQU 000H ; Disable monitoring on the SPI output pins.       
CS0PM_SPIPM__SPI_MONITOR_ENABLED    EQU 040H ; Enable monitoring on the SPI output pins.        
                                                                                                
CS0PM_UAPM__BMASK                   EQU 080H ; UART Pin Monitor Enable                          
CS0PM_UAPM__SHIFT                   EQU 007H ; UART Pin Monitor Enable                          
CS0PM_UAPM__UART_MONITOR_DISABLED   EQU 000H ; Disable monitoring on the UART TX pin.           
CS0PM_UAPM__UART_MONITOR_ENABLED    EQU 080H ; Enable monitoring on the UART TX pin.            
                                                                                                
;------------------------------------------------------------------------------
; CS0SE Enums (Capacitive Sense 0 Auto Scan End Channel @ 0xDE)
;------------------------------------------------------------------------------
CS0SE_CS0SE__FMASK EQU 03FH ; Ending Channel for Auto Scan
CS0SE_CS0SE__SHIFT EQU 000H ; Ending Channel for Auto Scan
                                                          
;------------------------------------------------------------------------------
; CS0SS Enums (Capacitive Sense 0 Auto Scan Start Channel @ 0xDD)
;------------------------------------------------------------------------------
CS0SS_CS0SS__FMASK EQU 03FH ; Starting Channel for Auto Scan
CS0SS_CS0SS__SHIFT EQU 000H ; Starting Channel for Auto Scan
                                                            
;------------------------------------------------------------------------------
; CS0THH Enums (Capacitive Sense 0 Comparator Threshold High Byte @ 0xFE)
;------------------------------------------------------------------------------
CS0THH_CS0THH__FMASK EQU 0FFH ; CS0 Comparator Threshold High Byte
CS0THH_CS0THH__SHIFT EQU 000H ; CS0 Comparator Threshold High Byte
                                                                  
;------------------------------------------------------------------------------
; CS0THL Enums (Capacitive Sense 0 Comparator Threshold Low Byte @ 0xFD)
;------------------------------------------------------------------------------
CS0THL_CS0THL__FMASK EQU 0FFH ; CS0 Comparator Threshold Low Byte
CS0THL_CS0THL__SHIFT EQU 000H ; CS0 Comparator Threshold Low Byte
                                                                 
;------------------------------------------------------------------------------
; DEVICEID Enums (Device Identification @ 0xE1)
;------------------------------------------------------------------------------
DEVICEID_DEVICEID__FMASK EQU 0FFH ; Device ID
DEVICEID_DEVICEID__SHIFT EQU 000H ; Device ID
                                             
;------------------------------------------------------------------------------
; REVID Enums (Revision Identifcation @ 0xE2)
;------------------------------------------------------------------------------
REVID_REVID__FMASK EQU 0FFH ; Revision ID
REVID_REVID__SHIFT EQU 000H ; Revision ID
REVID_REVID__REV_A EQU 001H ; Revision A 
                                         
;------------------------------------------------------------------------------
; DMA0BUSY Enums (DMA0 Busy @ 0x91)
;------------------------------------------------------------------------------
DMA0BUSY_CH0BUSY__BMASK   EQU 001H ; Channel 0 Busy                                    
DMA0BUSY_CH0BUSY__SHIFT   EQU 000H ; Channel 0 Busy                                    
DMA0BUSY_CH0BUSY__NOT_SET EQU 000H ; DMA0 transfer is complete or no DMA0 transfer is  
                                   ; currently in progress on channel 0.               
DMA0BUSY_CH0BUSY__SET     EQU 001H ; DMA0 transfer is in progress on channel 0 or force
                                   ; a DMA0 transfer to start on channel 0.            
                                                                                       
DMA0BUSY_CH1BUSY__BMASK   EQU 002H ; Channel 1 Busy                                    
DMA0BUSY_CH1BUSY__SHIFT   EQU 001H ; Channel 1 Busy                                    
DMA0BUSY_CH1BUSY__NOT_SET EQU 000H ; DMA0 transfer is complete or no DMA0 transfer is  
                                   ; currently in progress on channel 1.               
DMA0BUSY_CH1BUSY__SET     EQU 002H ; DMA0 transfer is in progress on channel 1 or force
                                   ; a DMA0 transfer to start on channel 1.            
                                                                                       
DMA0BUSY_CH2BUSY__BMASK   EQU 004H ; Channel 2 Busy                                    
DMA0BUSY_CH2BUSY__SHIFT   EQU 002H ; Channel 2 Busy                                    
DMA0BUSY_CH2BUSY__NOT_SET EQU 000H ; DMA0 transfer is complete or no DMA0 transfer is  
                                   ; currently in progress on channel 2.               
DMA0BUSY_CH2BUSY__SET     EQU 004H ; DMA0 transfer is in progress on channel 2 or force
                                   ; a DMA0 transfer to start on channel 2.            
                                                                                       
DMA0BUSY_CH3BUSY__BMASK   EQU 008H ; Channel 3 Busy                                    
DMA0BUSY_CH3BUSY__SHIFT   EQU 003H ; Channel 3 Busy                                    
DMA0BUSY_CH3BUSY__NOT_SET EQU 000H ; DMA0 transfer is complete or no DMA0 transfer is  
                                   ; currently in progress on channel 3.               
DMA0BUSY_CH3BUSY__SET     EQU 008H ; DMA0 transfer is in progress on channel 3 or force
                                   ; a DMA0 transfer to start on channel 3.            
                                                                                       
DMA0BUSY_CH4BUSY__BMASK   EQU 010H ; Channel 4 Busy                                    
DMA0BUSY_CH4BUSY__SHIFT   EQU 004H ; Channel 4 Busy                                    
DMA0BUSY_CH4BUSY__NOT_SET EQU 000H ; DMA0 transfer is complete or no DMA0 transfer is  
                                   ; currently in progress on channel 4.               
DMA0BUSY_CH4BUSY__SET     EQU 010H ; DMA0 transfer is in progress on channel 6 or force
                                   ; a DMA0 transfer to start on channel 4.            
                                                                                       
DMA0BUSY_CH5BUSY__BMASK   EQU 020H ; Channel 5 Busy                                    
DMA0BUSY_CH5BUSY__SHIFT   EQU 005H ; Channel 5 Busy                                    
DMA0BUSY_CH5BUSY__NOT_SET EQU 000H ; DMA0 transfer is complete or no DMA0 transfer is  
                                   ; currently in progress on channel 5.               
DMA0BUSY_CH5BUSY__SET     EQU 020H ; DMA0 transfer is in progress on channel 5 or force
                                   ; a DMA0 transfer to start on channel 5.            
                                                                                       
DMA0BUSY_CH6BUSY__BMASK   EQU 040H ; Channel 6 Busy                                    
DMA0BUSY_CH6BUSY__SHIFT   EQU 006H ; Channel 6 Busy                                    
DMA0BUSY_CH6BUSY__NOT_SET EQU 000H ; DMA0 transfer is complete or no DMA0 transfer is  
                                   ; currently in progress on channel 6.               
DMA0BUSY_CH6BUSY__SET     EQU 040H ; DMA0 transfer is in progress on channel 6 or force
                                   ; a DMA0 transfer to start on channel 6.            
                                                                                       
;------------------------------------------------------------------------------
; DMA0EN Enums (DMA0 Channel Enable @ 0x92)
;------------------------------------------------------------------------------
DMA0EN_CH0EN__BMASK    EQU 001H ; Channel 0 Enable       
DMA0EN_CH0EN__SHIFT    EQU 000H ; Channel 0 Enable       
DMA0EN_CH0EN__DISABLED EQU 000H ; Disable DMA0 channel 0.
DMA0EN_CH0EN__ENABLED  EQU 001H ; Enable DMA0 channel 0. 
                                                         
DMA0EN_CH1EN__BMASK    EQU 002H ; Channel 1 Enable       
DMA0EN_CH1EN__SHIFT    EQU 001H ; Channel 1 Enable       
DMA0EN_CH1EN__DISABLED EQU 000H ; Disable DMA0 channel 1.
DMA0EN_CH1EN__ENABLED  EQU 002H ; Enable DMA0 channel 1. 
                                                         
DMA0EN_CH2EN__BMASK    EQU 004H ; Channel 2 Enable       
DMA0EN_CH2EN__SHIFT    EQU 002H ; Channel 2 Enable       
DMA0EN_CH2EN__DISABLED EQU 000H ; Disable DMA0 channel 2.
DMA0EN_CH2EN__ENABLED  EQU 004H ; Enable DMA0 channel 2. 
                                                         
DMA0EN_CH3EN__BMASK    EQU 008H ; Channel 3 Enable       
DMA0EN_CH3EN__SHIFT    EQU 003H ; Channel 3 Enable       
DMA0EN_CH3EN__DISABLED EQU 000H ; Disable DMA0 channel 3.
DMA0EN_CH3EN__ENABLED  EQU 008H ; Enable DMA0 channel 3. 
                                                         
DMA0EN_CH4EN__BMASK    EQU 010H ; Channel 4 Enable       
DMA0EN_CH4EN__SHIFT    EQU 004H ; Channel 4 Enable       
DMA0EN_CH4EN__DISABLED EQU 000H ; Disable DMA0 channel 4.
DMA0EN_CH4EN__ENABLED  EQU 010H ; Enable DMA0 channel 4. 
                                                         
DMA0EN_CH5EN__BMASK    EQU 020H ; Channel 5 Enable       
DMA0EN_CH5EN__SHIFT    EQU 005H ; Channel 5 Enable       
DMA0EN_CH5EN__DISABLED EQU 000H ; Disable DMA0 channel 5.
DMA0EN_CH5EN__ENABLED  EQU 020H ; Enable DMA0 channel 5. 
                                                         
DMA0EN_CH6EN__BMASK    EQU 040H ; Channel 6 Enable       
DMA0EN_CH6EN__SHIFT    EQU 006H ; Channel 6 Enable       
DMA0EN_CH6EN__DISABLED EQU 000H ; Disable DMA0 channel 6.
DMA0EN_CH6EN__ENABLED  EQU 040H ; Enable DMA0 channel 6. 
                                                         
;------------------------------------------------------------------------------
; DMA0INT Enums (DMA0 Full-Length Interrupt Flags @ 0xE8)
;------------------------------------------------------------------------------
DMA0INT_CH0I__BMASK   EQU 001H ; Channel 0 Full-Length Interrupt Flag         
DMA0INT_CH0I__SHIFT   EQU 000H ; Channel 0 Full-Length Interrupt Flag         
DMA0INT_CH0I__NOT_SET EQU 000H ; No Interrupt generated.                      
DMA0INT_CH0I__SET     EQU 001H ; Full-length interrupt generated in channel 0.
                                                                              
DMA0INT_CH1I__BMASK   EQU 002H ; Channel 1 Full-Length Interrupt Flag         
DMA0INT_CH1I__SHIFT   EQU 001H ; Channel 1 Full-Length Interrupt Flag         
DMA0INT_CH1I__NOT_SET EQU 000H ; No Interrupt generated.                      
DMA0INT_CH1I__SET     EQU 002H ; Full-length interrupt generated in channel 1.
                                                                              
DMA0INT_CH2I__BMASK   EQU 004H ; Channel 2 Full-Length Interrupt Flag         
DMA0INT_CH2I__SHIFT   EQU 002H ; Channel 2 Full-Length Interrupt Flag         
DMA0INT_CH2I__NOT_SET EQU 000H ; No Interrupt generated.                      
DMA0INT_CH2I__SET     EQU 004H ; Full-length interrupt generated in channel 2.
                                                                              
DMA0INT_CH3I__BMASK   EQU 008H ; Channel 3 Full-Length Interrupt Flag         
DMA0INT_CH3I__SHIFT   EQU 003H ; Channel 3 Full-Length Interrupt Flag         
DMA0INT_CH3I__NOT_SET EQU 000H ; No Interrupt generated.                      
DMA0INT_CH3I__SET     EQU 008H ; Full-length interrupt generated in channel 3.
                                                                              
DMA0INT_CH4I__BMASK   EQU 010H ; Channel 4 Full-Length Interrupt Flag         
DMA0INT_CH4I__SHIFT   EQU 004H ; Channel 4 Full-Length Interrupt Flag         
DMA0INT_CH4I__NOT_SET EQU 000H ; No Interrupt generated.                      
DMA0INT_CH4I__SET     EQU 010H ; Full-length interrupt generated in channel 4.
                                                                              
DMA0INT_CH5I__BMASK   EQU 020H ; Channel 5 Full-Length Interrupt Flag         
DMA0INT_CH5I__SHIFT   EQU 005H ; Channel 5 Full-Length Interrupt Flag         
DMA0INT_CH5I__NOT_SET EQU 000H ; No Interrupt generated.                      
DMA0INT_CH5I__SET     EQU 020H ; Full-length interrupt generated in channel 5.
                                                                              
DMA0INT_CH6I__BMASK   EQU 040H ; Channel 6 Full-Length Interrupt Flag         
DMA0INT_CH6I__SHIFT   EQU 006H ; Channel 6 Full-Length Interrupt Flag         
DMA0INT_CH6I__NOT_SET EQU 000H ; No Interrupt generated.                      
DMA0INT_CH6I__SET     EQU 040H ; Full-length interrupt generated in channel 6.
                                                                              
;------------------------------------------------------------------------------
; DMA0MINT Enums (DMA0 Mid-Point Interrupt Flags @ 0x88)
;------------------------------------------------------------------------------
DMA0MINT_CH0MI__BMASK   EQU 001H ; Channel 0 Mid-Point Interrupt Flag         
DMA0MINT_CH0MI__SHIFT   EQU 000H ; Channel 0 Mid-Point Interrupt Flag         
DMA0MINT_CH0MI__NOT_SET EQU 000H ; No mid-point Interrupt generated.          
DMA0MINT_CH0MI__SET     EQU 001H ; Mid-point Interrupt generated in channel 0.
                                                                              
DMA0MINT_CH1MI__BMASK   EQU 002H ; Channel 1 Mid-Point Interrupt Flag         
DMA0MINT_CH1MI__SHIFT   EQU 001H ; Channel 1 Mid-Point Interrupt Flag         
DMA0MINT_CH1MI__NOT_SET EQU 000H ; No mid-point Interrupt generated.          
DMA0MINT_CH1MI__SET     EQU 002H ; Mid-point Interrupt generated in channel 1.
                                                                              
DMA0MINT_CH2MI__BMASK   EQU 004H ; Channel 2 Mid-Point Interrupt Flag         
DMA0MINT_CH2MI__SHIFT   EQU 002H ; Channel 2 Mid-Point Interrupt Flag         
DMA0MINT_CH2MI__NOT_SET EQU 000H ; No mid-point Interrupt generated.          
DMA0MINT_CH2MI__SET     EQU 004H ; Mid-point Interrupt generated in channel 2.
                                                                              
DMA0MINT_CH3MI__BMASK   EQU 008H ; Channel 3 Mid-Point Interrupt Flag         
DMA0MINT_CH3MI__SHIFT   EQU 003H ; Channel 3 Mid-Point Interrupt Flag         
DMA0MINT_CH3MI__NOT_SET EQU 000H ; No mid-point Interrupt generated.          
DMA0MINT_CH3MI__SET     EQU 008H ; Mid-point Interrupt generated in channel 3.
                                                                              
DMA0MINT_CH4MI__BMASK   EQU 010H ; Channel 4 Mid-Point Interrupt Flag         
DMA0MINT_CH4MI__SHIFT   EQU 004H ; Channel 4 Mid-Point Interrupt Flag         
DMA0MINT_CH4MI__NOT_SET EQU 000H ; No mid-point Interrupt generated.          
DMA0MINT_CH4MI__SET     EQU 010H ; Mid-point Interrupt generated in channel 4.
                                                                              
DMA0MINT_CH5MI__BMASK   EQU 020H ; Channel 5 Mid-Point Interrupt Flag         
DMA0MINT_CH5MI__SHIFT   EQU 005H ; Channel 5 Mid-Point Interrupt Flag         
DMA0MINT_CH5MI__NOT_SET EQU 000H ; No mid-point Interrupt generated.          
DMA0MINT_CH5MI__SET     EQU 020H ; Mid-point Interrupt generated in channel 5.
                                                                              
DMA0MINT_CH6MI__BMASK   EQU 040H ; Channel 6 Mid-Point Interrupt Flag         
DMA0MINT_CH6MI__SHIFT   EQU 006H ; Channel 6 Mid-Point Interrupt Flag         
DMA0MINT_CH6MI__NOT_SET EQU 000H ; No mid-point Interrupt generated.          
DMA0MINT_CH6MI__SET     EQU 040H ; Mid-point Interrupt generated in channel 6.
                                                                              
;------------------------------------------------------------------------------
; DMA0NAOH Enums (Memory Address Offset High @ 0xCC)
;------------------------------------------------------------------------------
DMA0NAOH_NAOH__FMASK EQU 003H ; Memory Address Offset High
DMA0NAOH_NAOH__SHIFT EQU 000H ; Memory Address Offset High
                                                          
;------------------------------------------------------------------------------
; DMA0NAOH0 Enums (Channel 0 Memory Address Offset High @ 0x00)
;------------------------------------------------------------------------------
DMA0NAOH0_NAOH__FMASK EQU 003H ; Memory Address Offset High
DMA0NAOH0_NAOH__SHIFT EQU 000H ; Memory Address Offset High
                                                           
;------------------------------------------------------------------------------
; DMA0NAOH1 Enums (Channel 1 Memory Address Offset High @ 0x01)
;------------------------------------------------------------------------------
DMA0NAOH1_NAOH__FMASK EQU 003H ; Memory Address Offset High
DMA0NAOH1_NAOH__SHIFT EQU 000H ; Memory Address Offset High
                                                           
;------------------------------------------------------------------------------
; DMA0NAOH2 Enums (Channel 2 Memory Address Offset High @ 0x02)
;------------------------------------------------------------------------------
DMA0NAOH2_NAOH__FMASK EQU 003H ; Memory Address Offset High
DMA0NAOH2_NAOH__SHIFT EQU 000H ; Memory Address Offset High
                                                           
;------------------------------------------------------------------------------
; DMA0NAOH3 Enums (Channel 3 Memory Address Offset High @ 0x03)
;------------------------------------------------------------------------------
DMA0NAOH3_NAOH__FMASK EQU 003H ; Memory Address Offset High
DMA0NAOH3_NAOH__SHIFT EQU 000H ; Memory Address Offset High
                                                           
;------------------------------------------------------------------------------
; DMA0NAOH4 Enums (Channel 4 Memory Address Offset High @ 0x04)
;------------------------------------------------------------------------------
DMA0NAOH4_NAOH__FMASK EQU 003H ; Memory Address Offset High
DMA0NAOH4_NAOH__SHIFT EQU 000H ; Memory Address Offset High
                                                           
;------------------------------------------------------------------------------
; DMA0NAOH5 Enums (Channel 5 Memory Address Offset High @ 0x05)
;------------------------------------------------------------------------------
DMA0NAOH5_NAOH__FMASK EQU 003H ; Memory Address Offset High
DMA0NAOH5_NAOH__SHIFT EQU 000H ; Memory Address Offset High
                                                           
;------------------------------------------------------------------------------
; DMA0NAOH6 Enums (Channel 6 Memory Address Offset High @ 0x06)
;------------------------------------------------------------------------------
DMA0NAOH6_NAOH__FMASK EQU 003H ; Memory Address Offset High
DMA0NAOH6_NAOH__SHIFT EQU 000H ; Memory Address Offset High
                                                           
;------------------------------------------------------------------------------
; DMA0NAOL Enums (Memory Address Offset Low @ 0xCB)
;------------------------------------------------------------------------------
DMA0NAOL_NAOL__FMASK EQU 0FFH ; Memory Address Offset Low
DMA0NAOL_NAOL__SHIFT EQU 000H ; Memory Address Offset Low
                                                         
;------------------------------------------------------------------------------
; DMA0NAOL0 Enums (Channel 0 Memory Address Offset Low @ 0x00)
;------------------------------------------------------------------------------
DMA0NAOL0_NAOL__FMASK EQU 0FFH ; Memory Address Offset Low
DMA0NAOL0_NAOL__SHIFT EQU 000H ; Memory Address Offset Low
                                                          
;------------------------------------------------------------------------------
; DMA0NAOL1 Enums (Channel 1 Memory Address Offset Low @ 0x01)
;------------------------------------------------------------------------------
DMA0NAOL1_NAOL__FMASK EQU 0FFH ; Memory Address Offset Low
DMA0NAOL1_NAOL__SHIFT EQU 000H ; Memory Address Offset Low
                                                          
;------------------------------------------------------------------------------
; DMA0NAOL2 Enums (Channel 2 Memory Address Offset Low @ 0x02)
;------------------------------------------------------------------------------
DMA0NAOL2_NAOL__FMASK EQU 0FFH ; Memory Address Offset Low
DMA0NAOL2_NAOL__SHIFT EQU 000H ; Memory Address Offset Low
                                                          
;------------------------------------------------------------------------------
; DMA0NAOL3 Enums (Channel 3 Memory Address Offset Low @ 0x03)
;------------------------------------------------------------------------------
DMA0NAOL3_NAOL__FMASK EQU 0FFH ; Memory Address Offset Low
DMA0NAOL3_NAOL__SHIFT EQU 000H ; Memory Address Offset Low
                                                          
;------------------------------------------------------------------------------
; DMA0NAOL4 Enums (Channel 4 Memory Address Offset Low @ 0x04)
;------------------------------------------------------------------------------
DMA0NAOL4_NAOL__FMASK EQU 0FFH ; Memory Address Offset Low
DMA0NAOL4_NAOL__SHIFT EQU 000H ; Memory Address Offset Low
                                                          
;------------------------------------------------------------------------------
; DMA0NAOL5 Enums (Channel 5 Memory Address Offset Low @ 0x05)
;------------------------------------------------------------------------------
DMA0NAOL5_NAOL__FMASK EQU 0FFH ; Memory Address Offset Low
DMA0NAOL5_NAOL__SHIFT EQU 000H ; Memory Address Offset Low
                                                          
;------------------------------------------------------------------------------
; DMA0NAOL6 Enums (Channel 6 Memory Address Offset Low @ 0x06)
;------------------------------------------------------------------------------
DMA0NAOL6_NAOL__FMASK EQU 0FFH ; Memory Address Offset Low
DMA0NAOL6_NAOL__SHIFT EQU 000H ; Memory Address Offset Low
                                                          
;------------------------------------------------------------------------------
; DMA0NBAH Enums (Memory Base Address High @ 0xCA)
;------------------------------------------------------------------------------
DMA0NBAH_NBAH__FMASK EQU 00FH ; Memory Base Address High
DMA0NBAH_NBAH__SHIFT EQU 000H ; Memory Base Address High
                                                        
;------------------------------------------------------------------------------
; DMA0NBAH0 Enums (Channel 0 Memory Base Address High @ 0x00)
;------------------------------------------------------------------------------
DMA0NBAH0_NBAH__FMASK EQU 00FH ; Memory Base Address High
DMA0NBAH0_NBAH__SHIFT EQU 000H ; Memory Base Address High
                                                         
;------------------------------------------------------------------------------
; DMA0NBAH1 Enums (Channel 1 Memory Base Address High @ 0x01)
;------------------------------------------------------------------------------
DMA0NBAH1_NBAH__FMASK EQU 00FH ; Memory Base Address High
DMA0NBAH1_NBAH__SHIFT EQU 000H ; Memory Base Address High
                                                         
;------------------------------------------------------------------------------
; DMA0NBAH2 Enums (Channel 2 Memory Base Address High @ 0x02)
;------------------------------------------------------------------------------
DMA0NBAH2_NBAH__FMASK EQU 00FH ; Memory Base Address High
DMA0NBAH2_NBAH__SHIFT EQU 000H ; Memory Base Address High
                                                         
;------------------------------------------------------------------------------
; DMA0NBAH3 Enums (Channel 3 Memory Base Address High @ 0x03)
;------------------------------------------------------------------------------
DMA0NBAH3_NBAH__FMASK EQU 00FH ; Memory Base Address High
DMA0NBAH3_NBAH__SHIFT EQU 000H ; Memory Base Address High
                                                         
;------------------------------------------------------------------------------
; DMA0NBAH4 Enums (Channel 4 Memory Base Address High @ 0x04)
;------------------------------------------------------------------------------
DMA0NBAH4_NBAH__FMASK EQU 00FH ; Memory Base Address High
DMA0NBAH4_NBAH__SHIFT EQU 000H ; Memory Base Address High
                                                         
;------------------------------------------------------------------------------
; DMA0NBAH5 Enums (Channel 5 Memory Base Address High @ 0x05)
;------------------------------------------------------------------------------
DMA0NBAH5_NBAH__FMASK EQU 00FH ; Memory Base Address High
DMA0NBAH5_NBAH__SHIFT EQU 000H ; Memory Base Address High
                                                         
;------------------------------------------------------------------------------
; DMA0NBAH6 Enums (Channel 6 Memory Base Address High @ 0x06)
;------------------------------------------------------------------------------
DMA0NBAH6_NBAH__FMASK EQU 00FH ; Memory Base Address High
DMA0NBAH6_NBAH__SHIFT EQU 000H ; Memory Base Address High
                                                         
;------------------------------------------------------------------------------
; DMA0NBAL Enums (Memory Base Address Low @ 0xC9)
;------------------------------------------------------------------------------
DMA0NBAL_NBAL__FMASK EQU 0FFH ; Memory Base Address Low
DMA0NBAL_NBAL__SHIFT EQU 000H ; Memory Base Address Low
                                                       
;------------------------------------------------------------------------------
; DMA0NBAL0 Enums (Channel 0 Memory Base Address Low @ 0x00)
;------------------------------------------------------------------------------
DMA0NBAL0_NBAL__FMASK EQU 0FFH ; Memory Base Address Low
DMA0NBAL0_NBAL__SHIFT EQU 000H ; Memory Base Address Low
                                                        
;------------------------------------------------------------------------------
; DMA0NBAL1 Enums (Channel 1 Memory Base Address Low @ 0x01)
;------------------------------------------------------------------------------
DMA0NBAL1_NBAL__FMASK EQU 0FFH ; Memory Base Address Low
DMA0NBAL1_NBAL__SHIFT EQU 000H ; Memory Base Address Low
                                                        
;------------------------------------------------------------------------------
; DMA0NBAL2 Enums (Channel 2 Memory Base Address Low @ 0x02)
;------------------------------------------------------------------------------
DMA0NBAL2_NBAL__FMASK EQU 0FFH ; Memory Base Address Low
DMA0NBAL2_NBAL__SHIFT EQU 000H ; Memory Base Address Low
                                                        
;------------------------------------------------------------------------------
; DMA0NBAL3 Enums (Channel 3 Memory Base Address Low @ 0x03)
;------------------------------------------------------------------------------
DMA0NBAL3_NBAL__FMASK EQU 0FFH ; Memory Base Address Low
DMA0NBAL3_NBAL__SHIFT EQU 000H ; Memory Base Address Low
                                                        
;------------------------------------------------------------------------------
; DMA0NBAL4 Enums (Channel 4 Memory Base Address Low @ 0x04)
;------------------------------------------------------------------------------
DMA0NBAL4_NBAL__FMASK EQU 0FFH ; Memory Base Address Low
DMA0NBAL4_NBAL__SHIFT EQU 000H ; Memory Base Address Low
                                                        
;------------------------------------------------------------------------------
; DMA0NBAL5 Enums (Channel 5 Memory Base Address Low @ 0x05)
;------------------------------------------------------------------------------
DMA0NBAL5_NBAL__FMASK EQU 0FFH ; Memory Base Address Low
DMA0NBAL5_NBAL__SHIFT EQU 000H ; Memory Base Address Low
                                                        
;------------------------------------------------------------------------------
; DMA0NBAL6 Enums (Channel 6 Memory Base Address Low @ 0x06)
;------------------------------------------------------------------------------
DMA0NBAL6_NBAL__FMASK EQU 0FFH ; Memory Base Address Low
DMA0NBAL6_NBAL__SHIFT EQU 000H ; Memory Base Address Low
                                                        
;------------------------------------------------------------------------------
; DMA0NCF Enums (DMA0 Channel Configuration @ 0xD8)
;------------------------------------------------------------------------------
DMA0NCF_PERIPH__FMASK            EQU 007H ; Peripheral Transfer Select                        
DMA0NCF_PERIPH__SHIFT            EQU 000H ; Peripheral Transfer Select                        
DMA0NCF_PERIPH__XRAM_TO_MAC_A    EQU 002H ; The DMA channel transfers from XRAM to the MAC A  
                                          ; register.                                         
DMA0NCF_PERIPH__XRAM_TO_MAC_B    EQU 003H ; The DMA channel transfers from XRAM to the MAC B  
                                          ; register.                                         
DMA0NCF_PERIPH__XRAM_TO_MAC_ACC  EQU 004H ; The DMA channel transfers from XRAM to the MAC    
                                          ; accumulator registers.                            
DMA0NCF_PERIPH__MAC_ACC_TO_XRAM  EQU 005H ; The DMA channel transfers from the MAC accumulator
                                          ; registers to XRAM.                                
DMA0NCF_PERIPH__XRAM_TO_I2C_DATA EQU 006H ; The DMA channel transfers from XRAM to the I2C    
                                          ; Slave data register.                              
DMA0NCF_PERIPH__I2C_DATA_TO_XRAM EQU 007H ; The DMA channel transfers from the I2C Slave data 
                                          ; register to XRAM.                                 
                                                                                              
DMA0NCF_ENDIAN__BMASK            EQU 010H ; Data Transfer Endianness                          
DMA0NCF_ENDIAN__SHIFT            EQU 004H ; Data Transfer Endianness                          
DMA0NCF_ENDIAN__LITTLE           EQU 000H ; Data is written to and read from XRAM in little   
                                          ; endian order.                                     
DMA0NCF_ENDIAN__BIG              EQU 010H ; Data is written to and read from XRAM in big      
                                          ; endian order.                                     
                                                                                              
DMA0NCF_STALL__BMASK             EQU 020H ; Channel Stall                                     
DMA0NCF_STALL__SHIFT             EQU 005H ; Channel Stall                                     
DMA0NCF_STALL__NOT_SET           EQU 000H ; The DMA transfer of the selected channel is not   
                                          ; stalled.                                          
DMA0NCF_STALL__SET               EQU 020H ; The DMA transfer of the selected channel is       
                                          ; stalled.                                          
                                                                                              
DMA0NCF_MIEN__BMASK              EQU 040H ; Mid-Point Interrupt Enable                        
DMA0NCF_MIEN__SHIFT              EQU 006H ; Mid-Point Interrupt Enable                        
DMA0NCF_MIEN__DISABLED           EQU 000H ; Disable the DMA0 mid-point interrupt request of   
                                          ; the selected channel.                             
DMA0NCF_MIEN__ENABLED            EQU 040H ; Enable the DMA0 mid-point interrupt request of the
                                          ; selected channel.                                 
                                                                                              
DMA0NCF_IEN__BMASK               EQU 080H ; Full-Length Interrupt Enable                      
DMA0NCF_IEN__SHIFT               EQU 007H ; Full-Length Interrupt Enable                      
DMA0NCF_IEN__DISABLED            EQU 000H ; Disable the DMA0 full-length interrupt request of 
                                          ; the selected channel.                             
DMA0NCF_IEN__ENABLED             EQU 080H ; Enable the DMA0 full-length interrupt request of  
                                          ; the selected channel.                             
                                                                                              
;------------------------------------------------------------------------------
; DMA0NCF0 Enums (DMA0 Channel 0 Configuration @ 0x00)
;------------------------------------------------------------------------------
DMA0NCF0_PERIPH__FMASK            EQU 007H ; Peripheral Transfer Select                        
DMA0NCF0_PERIPH__SHIFT            EQU 000H ; Peripheral Transfer Select                        
DMA0NCF0_PERIPH__XRAM_TO_MAC_A    EQU 002H ; The DMA channel transfers from XRAM to the MAC A  
                                           ; register.                                         
DMA0NCF0_PERIPH__XRAM_TO_MAC_B    EQU 003H ; The DMA channel transfers from XRAM to the MAC B  
                                           ; register.                                         
DMA0NCF0_PERIPH__XRAM_TO_MAC_ACC  EQU 004H ; The DMA channel transfers from XRAM to the MAC    
                                           ; accumulator registers.                            
DMA0NCF0_PERIPH__MAC_ACC_TO_XRAM  EQU 005H ; The DMA channel transfers from the MAC accumulator
                                           ; registers to XRAM.                                
DMA0NCF0_PERIPH__XRAM_TO_I2C_DATA EQU 006H ; The DMA channel transfers from XRAM to the I2C    
                                           ; Slave data register.                              
DMA0NCF0_PERIPH__I2C_DATA_TO_XRAM EQU 007H ; The DMA channel transfers from the I2C Slave data 
                                           ; register to XRAM.                                 
                                                                                               
DMA0NCF0_ENDIAN__BMASK            EQU 010H ; Data Transfer Endianness                          
DMA0NCF0_ENDIAN__SHIFT            EQU 004H ; Data Transfer Endianness                          
DMA0NCF0_ENDIAN__LITTLE           EQU 000H ; Data is written to and read from XRAM in little   
                                           ; endian order.                                     
DMA0NCF0_ENDIAN__BIG              EQU 010H ; Data is written to and read from XRAM in big      
                                           ; endian order.                                     
                                                                                               
DMA0NCF0_STALL__BMASK             EQU 020H ; Channel Stall                                     
DMA0NCF0_STALL__SHIFT             EQU 005H ; Channel Stall                                     
DMA0NCF0_STALL__NOT_SET           EQU 000H ; The DMA transfer of the selected channel is not   
                                           ; stalled.                                          
DMA0NCF0_STALL__SET               EQU 020H ; The DMA transfer of the selected channel is       
                                           ; stalled.                                          
                                                                                               
DMA0NCF0_MIEN__BMASK              EQU 040H ; Mid-Point Interrupt Enable                        
DMA0NCF0_MIEN__SHIFT              EQU 006H ; Mid-Point Interrupt Enable                        
DMA0NCF0_MIEN__DISABLED           EQU 000H ; Disable the DMA0 mid-point interrupt request of   
                                           ; the selected channel.                             
DMA0NCF0_MIEN__ENABLED            EQU 040H ; Enable the DMA0 mid-point interrupt request of the
                                           ; selected channel.                                 
                                                                                               
DMA0NCF0_IEN__BMASK               EQU 080H ; Full-Length Interrupt Enable                      
DMA0NCF0_IEN__SHIFT               EQU 007H ; Full-Length Interrupt Enable                      
DMA0NCF0_IEN__DISABLED            EQU 000H ; Disable the DMA0 full-length interrupt request of 
                                           ; the selected channel.                             
DMA0NCF0_IEN__ENABLED             EQU 080H ; Enable the DMA0 full-length interrupt request of  
                                           ; the selected channel.                             
                                                                                               
;------------------------------------------------------------------------------
; DMA0NCF1 Enums (DMA0 Channel 1 Configuration @ 0x01)
;------------------------------------------------------------------------------
DMA0NCF1_PERIPH__FMASK            EQU 007H ; Peripheral Transfer Select                        
DMA0NCF1_PERIPH__SHIFT            EQU 000H ; Peripheral Transfer Select                        
DMA0NCF1_PERIPH__XRAM_TO_MAC_A    EQU 002H ; The DMA channel transfers from XRAM to the MAC A  
                                           ; register.                                         
DMA0NCF1_PERIPH__XRAM_TO_MAC_B    EQU 003H ; The DMA channel transfers from XRAM to the MAC B  
                                           ; register.                                         
DMA0NCF1_PERIPH__XRAM_TO_MAC_ACC  EQU 004H ; The DMA channel transfers from XRAM to the MAC    
                                           ; accumulator registers.                            
DMA0NCF1_PERIPH__MAC_ACC_TO_XRAM  EQU 005H ; The DMA channel transfers from the MAC accumulator
                                           ; registers to XRAM.                                
DMA0NCF1_PERIPH__XRAM_TO_I2C_DATA EQU 006H ; The DMA channel transfers from XRAM to the I2C    
                                           ; Slave data register.                              
DMA0NCF1_PERIPH__I2C_DATA_TO_XRAM EQU 007H ; The DMA channel transfers from the I2C Slave data 
                                           ; register to XRAM.                                 
                                                                                               
DMA0NCF1_ENDIAN__BMASK            EQU 010H ; Data Transfer Endianness                          
DMA0NCF1_ENDIAN__SHIFT            EQU 004H ; Data Transfer Endianness                          
DMA0NCF1_ENDIAN__LITTLE           EQU 000H ; Data is written to and read from XRAM in little   
                                           ; endian order.                                     
DMA0NCF1_ENDIAN__BIG              EQU 010H ; Data is written to and read from XRAM in big      
                                           ; endian order.                                     
                                                                                               
DMA0NCF1_STALL__BMASK             EQU 020H ; Channel Stall                                     
DMA0NCF1_STALL__SHIFT             EQU 005H ; Channel Stall                                     
DMA0NCF1_STALL__NOT_SET           EQU 000H ; The DMA transfer of the selected channel is not   
                                           ; stalled.                                          
DMA0NCF1_STALL__SET               EQU 020H ; The DMA transfer of the selected channel is       
                                           ; stalled.                                          
                                                                                               
DMA0NCF1_MIEN__BMASK              EQU 040H ; Mid-Point Interrupt Enable                        
DMA0NCF1_MIEN__SHIFT              EQU 006H ; Mid-Point Interrupt Enable                        
DMA0NCF1_MIEN__DISABLED           EQU 000H ; Disable the DMA0 mid-point interrupt request of   
                                           ; the selected channel.                             
DMA0NCF1_MIEN__ENABLED            EQU 040H ; Enable the DMA0 mid-point interrupt request of the
                                           ; selected channel.                                 
                                                                                               
DMA0NCF1_IEN__BMASK               EQU 080H ; Full-Length Interrupt Enable                      
DMA0NCF1_IEN__SHIFT               EQU 007H ; Full-Length Interrupt Enable                      
DMA0NCF1_IEN__DISABLED            EQU 000H ; Disable the DMA0 full-length interrupt request of 
                                           ; the selected channel.                             
DMA0NCF1_IEN__ENABLED             EQU 080H ; Enable the DMA0 full-length interrupt request of  
                                           ; the selected channel.                             
                                                                                               
;------------------------------------------------------------------------------
; DMA0NCF2 Enums (DMA0 Channel 2 Configuration @ 0x02)
;------------------------------------------------------------------------------
DMA0NCF2_PERIPH__FMASK            EQU 007H ; Peripheral Transfer Select                        
DMA0NCF2_PERIPH__SHIFT            EQU 000H ; Peripheral Transfer Select                        
DMA0NCF2_PERIPH__XRAM_TO_MAC_A    EQU 002H ; The DMA channel transfers from XRAM to the MAC A  
                                           ; register.                                         
DMA0NCF2_PERIPH__XRAM_TO_MAC_B    EQU 003H ; The DMA channel transfers from XRAM to the MAC B  
                                           ; register.                                         
DMA0NCF2_PERIPH__XRAM_TO_MAC_ACC  EQU 004H ; The DMA channel transfers from XRAM to the MAC    
                                           ; accumulator registers.                            
DMA0NCF2_PERIPH__MAC_ACC_TO_XRAM  EQU 005H ; The DMA channel transfers from the MAC accumulator
                                           ; registers to XRAM.                                
DMA0NCF2_PERIPH__XRAM_TO_I2C_DATA EQU 006H ; The DMA channel transfers from XRAM to the I2C    
                                           ; Slave data register.                              
DMA0NCF2_PERIPH__I2C_DATA_TO_XRAM EQU 007H ; The DMA channel transfers from the I2C Slave data 
                                           ; register to XRAM.                                 
                                                                                               
DMA0NCF2_ENDIAN__BMASK            EQU 010H ; Data Transfer Endianness                          
DMA0NCF2_ENDIAN__SHIFT            EQU 004H ; Data Transfer Endianness                          
DMA0NCF2_ENDIAN__LITTLE           EQU 000H ; Data is written to and read from XRAM in little   
                                           ; endian order.                                     
DMA0NCF2_ENDIAN__BIG              EQU 010H ; Data is written to and read from XRAM in big      
                                           ; endian order.                                     
                                                                                               
DMA0NCF2_STALL__BMASK             EQU 020H ; Channel Stall                                     
DMA0NCF2_STALL__SHIFT             EQU 005H ; Channel Stall                                     
DMA0NCF2_STALL__NOT_SET           EQU 000H ; The DMA transfer of the selected channel is not   
                                           ; stalled.                                          
DMA0NCF2_STALL__SET               EQU 020H ; The DMA transfer of the selected channel is       
                                           ; stalled.                                          
                                                                                               
DMA0NCF2_MIEN__BMASK              EQU 040H ; Mid-Point Interrupt Enable                        
DMA0NCF2_MIEN__SHIFT              EQU 006H ; Mid-Point Interrupt Enable                        
DMA0NCF2_MIEN__DISABLED           EQU 000H ; Disable the DMA0 mid-point interrupt request of   
                                           ; the selected channel.                             
DMA0NCF2_MIEN__ENABLED            EQU 040H ; Enable the DMA0 mid-point interrupt request of the
                                           ; selected channel.                                 
                                                                                               
DMA0NCF2_IEN__BMASK               EQU 080H ; Full-Length Interrupt Enable                      
DMA0NCF2_IEN__SHIFT               EQU 007H ; Full-Length Interrupt Enable                      
DMA0NCF2_IEN__DISABLED            EQU 000H ; Disable the DMA0 full-length interrupt request of 
                                           ; the selected channel.                             
DMA0NCF2_IEN__ENABLED             EQU 080H ; Enable the DMA0 full-length interrupt request of  
                                           ; the selected channel.                             
                                                                                               
;------------------------------------------------------------------------------
; DMA0NCF3 Enums (DMA0 Channel 3 Configuration @ 0x03)
;------------------------------------------------------------------------------
DMA0NCF3_PERIPH__FMASK            EQU 007H ; Peripheral Transfer Select                        
DMA0NCF3_PERIPH__SHIFT            EQU 000H ; Peripheral Transfer Select                        
DMA0NCF3_PERIPH__XRAM_TO_MAC_A    EQU 002H ; The DMA channel transfers from XRAM to the MAC A  
                                           ; register.                                         
DMA0NCF3_PERIPH__XRAM_TO_MAC_B    EQU 003H ; The DMA channel transfers from XRAM to the MAC B  
                                           ; register.                                         
DMA0NCF3_PERIPH__XRAM_TO_MAC_ACC  EQU 004H ; The DMA channel transfers from XRAM to the MAC    
                                           ; accumulator registers.                            
DMA0NCF3_PERIPH__MAC_ACC_TO_XRAM  EQU 005H ; The DMA channel transfers from the MAC accumulator
                                           ; registers to XRAM.                                
DMA0NCF3_PERIPH__XRAM_TO_I2C_DATA EQU 006H ; The DMA channel transfers from XRAM to the I2C    
                                           ; Slave data register.                              
DMA0NCF3_PERIPH__I2C_DATA_TO_XRAM EQU 007H ; The DMA channel transfers from the I2C Slave data 
                                           ; register to XRAM.                                 
                                                                                               
DMA0NCF3_ENDIAN__BMASK            EQU 010H ; Data Transfer Endianness                          
DMA0NCF3_ENDIAN__SHIFT            EQU 004H ; Data Transfer Endianness                          
DMA0NCF3_ENDIAN__LITTLE           EQU 000H ; Data is written to and read from XRAM in little   
                                           ; endian order.                                     
DMA0NCF3_ENDIAN__BIG              EQU 010H ; Data is written to and read from XRAM in big      
                                           ; endian order.                                     
                                                                                               
DMA0NCF3_STALL__BMASK             EQU 020H ; Channel Stall                                     
DMA0NCF3_STALL__SHIFT             EQU 005H ; Channel Stall                                     
DMA0NCF3_STALL__NOT_SET           EQU 000H ; The DMA transfer of the selected channel is not   
                                           ; stalled.                                          
DMA0NCF3_STALL__SET               EQU 020H ; The DMA transfer of the selected channel is       
                                           ; stalled.                                          
                                                                                               
DMA0NCF3_MIEN__BMASK              EQU 040H ; Mid-Point Interrupt Enable                        
DMA0NCF3_MIEN__SHIFT              EQU 006H ; Mid-Point Interrupt Enable                        
DMA0NCF3_MIEN__DISABLED           EQU 000H ; Disable the DMA0 mid-point interrupt request of   
                                           ; the selected channel.                             
DMA0NCF3_MIEN__ENABLED            EQU 040H ; Enable the DMA0 mid-point interrupt request of the
                                           ; selected channel.                                 
                                                                                               
DMA0NCF3_IEN__BMASK               EQU 080H ; Full-Length Interrupt Enable                      
DMA0NCF3_IEN__SHIFT               EQU 007H ; Full-Length Interrupt Enable                      
DMA0NCF3_IEN__DISABLED            EQU 000H ; Disable the DMA0 full-length interrupt request of 
                                           ; the selected channel.                             
DMA0NCF3_IEN__ENABLED             EQU 080H ; Enable the DMA0 full-length interrupt request of  
                                           ; the selected channel.                             
                                                                                               
;------------------------------------------------------------------------------
; DMA0NCF4 Enums (DMA0 Channel 4 Configuration @ 0x04)
;------------------------------------------------------------------------------
DMA0NCF4_PERIPH__FMASK            EQU 007H ; Peripheral Transfer Select                        
DMA0NCF4_PERIPH__SHIFT            EQU 000H ; Peripheral Transfer Select                        
DMA0NCF4_PERIPH__XRAM_TO_MAC_A    EQU 002H ; The DMA channel transfers from XRAM to the MAC A  
                                           ; register.                                         
DMA0NCF4_PERIPH__XRAM_TO_MAC_B    EQU 003H ; The DMA channel transfers from XRAM to the MAC B  
                                           ; register.                                         
DMA0NCF4_PERIPH__XRAM_TO_MAC_ACC  EQU 004H ; The DMA channel transfers from XRAM to the MAC    
                                           ; accumulator registers.                            
DMA0NCF4_PERIPH__MAC_ACC_TO_XRAM  EQU 005H ; The DMA channel transfers from the MAC accumulator
                                           ; registers to XRAM.                                
DMA0NCF4_PERIPH__XRAM_TO_I2C_DATA EQU 006H ; The DMA channel transfers from XRAM to the I2C    
                                           ; Slave data register.                              
DMA0NCF4_PERIPH__I2C_DATA_TO_XRAM EQU 007H ; The DMA channel transfers from the I2C Slave data 
                                           ; register to XRAM.                                 
                                                                                               
DMA0NCF4_ENDIAN__BMASK            EQU 010H ; Data Transfer Endianness                          
DMA0NCF4_ENDIAN__SHIFT            EQU 004H ; Data Transfer Endianness                          
DMA0NCF4_ENDIAN__LITTLE           EQU 000H ; Data is written to and read from XRAM in little   
                                           ; endian order.                                     
DMA0NCF4_ENDIAN__BIG              EQU 010H ; Data is written to and read from XRAM in big      
                                           ; endian order.                                     
                                                                                               
DMA0NCF4_STALL__BMASK             EQU 020H ; Channel Stall                                     
DMA0NCF4_STALL__SHIFT             EQU 005H ; Channel Stall                                     
DMA0NCF4_STALL__NOT_SET           EQU 000H ; The DMA transfer of the selected channel is not   
                                           ; stalled.                                          
DMA0NCF4_STALL__SET               EQU 020H ; The DMA transfer of the selected channel is       
                                           ; stalled.                                          
                                                                                               
DMA0NCF4_MIEN__BMASK              EQU 040H ; Mid-Point Interrupt Enable                        
DMA0NCF4_MIEN__SHIFT              EQU 006H ; Mid-Point Interrupt Enable                        
DMA0NCF4_MIEN__DISABLED           EQU 000H ; Disable the DMA0 mid-point interrupt request of   
                                           ; the selected channel.                             
DMA0NCF4_MIEN__ENABLED            EQU 040H ; Enable the DMA0 mid-point interrupt request of the
                                           ; selected channel.                                 
                                                                                               
DMA0NCF4_IEN__BMASK               EQU 080H ; Full-Length Interrupt Enable                      
DMA0NCF4_IEN__SHIFT               EQU 007H ; Full-Length Interrupt Enable                      
DMA0NCF4_IEN__DISABLED            EQU 000H ; Disable the DMA0 full-length interrupt request of 
                                           ; the selected channel.                             
DMA0NCF4_IEN__ENABLED             EQU 080H ; Enable the DMA0 full-length interrupt request of  
                                           ; the selected channel.                             
                                                                                               
;------------------------------------------------------------------------------
; DMA0NCF5 Enums (DMA0 Channel 5 Configuration @ 0x05)
;------------------------------------------------------------------------------
DMA0NCF5_PERIPH__FMASK            EQU 007H ; Peripheral Transfer Select                        
DMA0NCF5_PERIPH__SHIFT            EQU 000H ; Peripheral Transfer Select                        
DMA0NCF5_PERIPH__XRAM_TO_MAC_A    EQU 002H ; The DMA channel transfers from XRAM to the MAC A  
                                           ; register.                                         
DMA0NCF5_PERIPH__XRAM_TO_MAC_B    EQU 003H ; The DMA channel transfers from XRAM to the MAC B  
                                           ; register.                                         
DMA0NCF5_PERIPH__XRAM_TO_MAC_ACC  EQU 004H ; The DMA channel transfers from XRAM to the MAC    
                                           ; accumulator registers.                            
DMA0NCF5_PERIPH__MAC_ACC_TO_XRAM  EQU 005H ; The DMA channel transfers from the MAC accumulator
                                           ; registers to XRAM.                                
DMA0NCF5_PERIPH__XRAM_TO_I2C_DATA EQU 006H ; The DMA channel transfers from XRAM to the I2C    
                                           ; Slave data register.                              
DMA0NCF5_PERIPH__I2C_DATA_TO_XRAM EQU 007H ; The DMA channel transfers from the I2C Slave data 
                                           ; register to XRAM.                                 
                                                                                               
DMA0NCF5_ENDIAN__BMASK            EQU 010H ; Data Transfer Endianness                          
DMA0NCF5_ENDIAN__SHIFT            EQU 004H ; Data Transfer Endianness                          
DMA0NCF5_ENDIAN__LITTLE           EQU 000H ; Data is written to and read from XRAM in little   
                                           ; endian order.                                     
DMA0NCF5_ENDIAN__BIG              EQU 010H ; Data is written to and read from XRAM in big      
                                           ; endian order.                                     
                                                                                               
DMA0NCF5_STALL__BMASK             EQU 020H ; Channel Stall                                     
DMA0NCF5_STALL__SHIFT             EQU 005H ; Channel Stall                                     
DMA0NCF5_STALL__NOT_SET           EQU 000H ; The DMA transfer of the selected channel is not   
                                           ; stalled.                                          
DMA0NCF5_STALL__SET               EQU 020H ; The DMA transfer of the selected channel is       
                                           ; stalled.                                          
                                                                                               
DMA0NCF5_MIEN__BMASK              EQU 040H ; Mid-Point Interrupt Enable                        
DMA0NCF5_MIEN__SHIFT              EQU 006H ; Mid-Point Interrupt Enable                        
DMA0NCF5_MIEN__DISABLED           EQU 000H ; Disable the DMA0 mid-point interrupt request of   
                                           ; the selected channel.                             
DMA0NCF5_MIEN__ENABLED            EQU 040H ; Enable the DMA0 mid-point interrupt request of the
                                           ; selected channel.                                 
                                                                                               
DMA0NCF5_IEN__BMASK               EQU 080H ; Full-Length Interrupt Enable                      
DMA0NCF5_IEN__SHIFT               EQU 007H ; Full-Length Interrupt Enable                      
DMA0NCF5_IEN__DISABLED            EQU 000H ; Disable the DMA0 full-length interrupt request of 
                                           ; the selected channel.                             
DMA0NCF5_IEN__ENABLED             EQU 080H ; Enable the DMA0 full-length interrupt request of  
                                           ; the selected channel.                             
                                                                                               
;------------------------------------------------------------------------------
; DMA0NCF6 Enums (DMA0 Channel 6 Configuration @ 0x06)
;------------------------------------------------------------------------------
DMA0NCF6_PERIPH__FMASK            EQU 007H ; Peripheral Transfer Select                        
DMA0NCF6_PERIPH__SHIFT            EQU 000H ; Peripheral Transfer Select                        
DMA0NCF6_PERIPH__XRAM_TO_MAC_A    EQU 002H ; The DMA channel transfers from XRAM to the MAC A  
                                           ; register.                                         
DMA0NCF6_PERIPH__XRAM_TO_MAC_B    EQU 003H ; The DMA channel transfers from XRAM to the MAC B  
                                           ; register.                                         
DMA0NCF6_PERIPH__XRAM_TO_MAC_ACC  EQU 004H ; The DMA channel transfers from XRAM to the MAC    
                                           ; accumulator registers.                            
DMA0NCF6_PERIPH__MAC_ACC_TO_XRAM  EQU 005H ; The DMA channel transfers from the MAC accumulator
                                           ; registers to XRAM.                                
DMA0NCF6_PERIPH__XRAM_TO_I2C_DATA EQU 006H ; The DMA channel transfers from XRAM to the I2C    
                                           ; Slave data register.                              
DMA0NCF6_PERIPH__I2C_DATA_TO_XRAM EQU 007H ; The DMA channel transfers from the I2C Slave data 
                                           ; register to XRAM.                                 
                                                                                               
DMA0NCF6_ENDIAN__BMASK            EQU 010H ; Data Transfer Endianness                          
DMA0NCF6_ENDIAN__SHIFT            EQU 004H ; Data Transfer Endianness                          
DMA0NCF6_ENDIAN__LITTLE           EQU 000H ; Data is written to and read from XRAM in little   
                                           ; endian order.                                     
DMA0NCF6_ENDIAN__BIG              EQU 010H ; Data is written to and read from XRAM in big      
                                           ; endian order.                                     
                                                                                               
DMA0NCF6_STALL__BMASK             EQU 020H ; Channel Stall                                     
DMA0NCF6_STALL__SHIFT             EQU 005H ; Channel Stall                                     
DMA0NCF6_STALL__NOT_SET           EQU 000H ; The DMA transfer of the selected channel is not   
                                           ; stalled.                                          
DMA0NCF6_STALL__SET               EQU 020H ; The DMA transfer of the selected channel is       
                                           ; stalled.                                          
                                                                                               
DMA0NCF6_MIEN__BMASK              EQU 040H ; Mid-Point Interrupt Enable                        
DMA0NCF6_MIEN__SHIFT              EQU 006H ; Mid-Point Interrupt Enable                        
DMA0NCF6_MIEN__DISABLED           EQU 000H ; Disable the DMA0 mid-point interrupt request of   
                                           ; the selected channel.                             
DMA0NCF6_MIEN__ENABLED            EQU 040H ; Enable the DMA0 mid-point interrupt request of the
                                           ; selected channel.                                 
                                                                                               
DMA0NCF6_IEN__BMASK               EQU 080H ; Full-Length Interrupt Enable                      
DMA0NCF6_IEN__SHIFT               EQU 007H ; Full-Length Interrupt Enable                      
DMA0NCF6_IEN__DISABLED            EQU 000H ; Disable the DMA0 full-length interrupt request of 
                                           ; the selected channel.                             
DMA0NCF6_IEN__ENABLED             EQU 080H ; Enable the DMA0 full-length interrupt request of  
                                           ; the selected channel.                             
                                                                                               
;------------------------------------------------------------------------------
; DMA0NSZH Enums (Memory Transfer Size High @ 0xCE)
;------------------------------------------------------------------------------
DMA0NSZH_NSZH__FMASK EQU 003H ; Memory Transfer Size High
DMA0NSZH_NSZH__SHIFT EQU 000H ; Memory Transfer Size High
                                                         
;------------------------------------------------------------------------------
; DMA0NSZH0 Enums (Channel 0 Memory Transfer Size High @ 0x00)
;------------------------------------------------------------------------------
DMA0NSZH0_NSZH__FMASK EQU 003H ; Memory Transfer Size High
DMA0NSZH0_NSZH__SHIFT EQU 000H ; Memory Transfer Size High
                                                          
;------------------------------------------------------------------------------
; DMA0NSZH1 Enums (Channel 1 Memory Transfer Size High @ 0x01)
;------------------------------------------------------------------------------
DMA0NSZH1_NSZH__FMASK EQU 003H ; Memory Transfer Size High
DMA0NSZH1_NSZH__SHIFT EQU 000H ; Memory Transfer Size High
                                                          
;------------------------------------------------------------------------------
; DMA0NSZH2 Enums (Channel 2 Memory Transfer Size High @ 0x02)
;------------------------------------------------------------------------------
DMA0NSZH2_NSZH__FMASK EQU 003H ; Memory Transfer Size High
DMA0NSZH2_NSZH__SHIFT EQU 000H ; Memory Transfer Size High
                                                          
;------------------------------------------------------------------------------
; DMA0NSZH3 Enums (Channel 3 Memory Transfer Size High @ 0x03)
;------------------------------------------------------------------------------
DMA0NSZH3_NSZH__FMASK EQU 003H ; Memory Transfer Size High
DMA0NSZH3_NSZH__SHIFT EQU 000H ; Memory Transfer Size High
                                                          
;------------------------------------------------------------------------------
; DMA0NSZH4 Enums (Channel 4 Memory Transfer Size High @ 0x04)
;------------------------------------------------------------------------------
DMA0NSZH4_NSZH__FMASK EQU 003H ; Memory Transfer Size High
DMA0NSZH4_NSZH__SHIFT EQU 000H ; Memory Transfer Size High
                                                          
;------------------------------------------------------------------------------
; DMA0NSZH5 Enums (Channel 5 Memory Transfer Size High @ 0x05)
;------------------------------------------------------------------------------
DMA0NSZH5_NSZH__FMASK EQU 003H ; Memory Transfer Size High
DMA0NSZH5_NSZH__SHIFT EQU 000H ; Memory Transfer Size High
                                                          
;------------------------------------------------------------------------------
; DMA0NSZH6 Enums (Channel 6 Memory Transfer Size High @ 0x06)
;------------------------------------------------------------------------------
DMA0NSZH6_NSZH__FMASK EQU 003H ; Memory Transfer Size High
DMA0NSZH6_NSZH__SHIFT EQU 000H ; Memory Transfer Size High
                                                          
;------------------------------------------------------------------------------
; DMA0NSZL Enums (Memory Transfer Size Low @ 0xCD)
;------------------------------------------------------------------------------
DMA0NSZL_NSZL__FMASK EQU 0FFH ; Memory Transfer Size Low
DMA0NSZL_NSZL__SHIFT EQU 000H ; Memory Transfer Size Low
                                                        
;------------------------------------------------------------------------------
; DMA0NSZL0 Enums (Channel 0 Memory Transfer Size Low @ 0x00)
;------------------------------------------------------------------------------
DMA0NSZL0_NSZL__FMASK EQU 0FFH ; Memory Transfer Size Low
DMA0NSZL0_NSZL__SHIFT EQU 000H ; Memory Transfer Size Low
                                                         
;------------------------------------------------------------------------------
; DMA0NSZL1 Enums (Channel 1 Memory Transfer Size Low @ 0x01)
;------------------------------------------------------------------------------
DMA0NSZL1_NSZL__FMASK EQU 0FFH ; Memory Transfer Size Low
DMA0NSZL1_NSZL__SHIFT EQU 000H ; Memory Transfer Size Low
                                                         
;------------------------------------------------------------------------------
; DMA0NSZL2 Enums (Channel 2 Memory Transfer Size Low @ 0x02)
;------------------------------------------------------------------------------
DMA0NSZL2_NSZL__FMASK EQU 0FFH ; Memory Transfer Size Low
DMA0NSZL2_NSZL__SHIFT EQU 000H ; Memory Transfer Size Low
                                                         
;------------------------------------------------------------------------------
; DMA0NSZL3 Enums (Channel 3 Memory Transfer Size Low @ 0x03)
;------------------------------------------------------------------------------
DMA0NSZL3_NSZL__FMASK EQU 0FFH ; Memory Transfer Size Low
DMA0NSZL3_NSZL__SHIFT EQU 000H ; Memory Transfer Size Low
                                                         
;------------------------------------------------------------------------------
; DMA0NSZL4 Enums (Channel 4 Memory Transfer Size Low @ 0x04)
;------------------------------------------------------------------------------
DMA0NSZL4_NSZL__FMASK EQU 0FFH ; Memory Transfer Size Low
DMA0NSZL4_NSZL__SHIFT EQU 000H ; Memory Transfer Size Low
                                                         
;------------------------------------------------------------------------------
; DMA0NSZL5 Enums (Channel 5 Memory Transfer Size Low @ 0x05)
;------------------------------------------------------------------------------
DMA0NSZL5_NSZL__FMASK EQU 0FFH ; Memory Transfer Size Low
DMA0NSZL5_NSZL__SHIFT EQU 000H ; Memory Transfer Size Low
                                                         
;------------------------------------------------------------------------------
; DMA0NSZL6 Enums (Channel 6 Memory Transfer Size Low @ 0x06)
;------------------------------------------------------------------------------
DMA0NSZL6_NSZL__FMASK EQU 0FFH ; Memory Transfer Size Low
DMA0NSZL6_NSZL__SHIFT EQU 000H ; Memory Transfer Size Low
                                                         
;------------------------------------------------------------------------------
; DMA0SEL Enums (DMA0 Channel Select @ 0x94)
;------------------------------------------------------------------------------
DMA0SEL_SELECT__FMASK EQU 007H ; Channel Select   
DMA0SEL_SELECT__SHIFT EQU 000H ; Channel Select   
DMA0SEL_SELECT__CH0   EQU 000H ; Select channel 0.
DMA0SEL_SELECT__CH1   EQU 001H ; Select channel 1.
DMA0SEL_SELECT__CH2   EQU 002H ; Select channel 2.
DMA0SEL_SELECT__CH3   EQU 003H ; Select channel 3.
DMA0SEL_SELECT__CH4   EQU 004H ; Select channel 4.
DMA0SEL_SELECT__CH5   EQU 005H ; Select channel 5.
DMA0SEL_SELECT__CH6   EQU 006H ; Select channel 6.
                                                  
;------------------------------------------------------------------------------
; IT01CF Enums (INT0/INT1 Configuration @ 0xDE)
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
                                                                                        
OSCXCN_XCLKVLD__BMASK        EQU 080H ; External Oscillator Valid Flag                  
OSCXCN_XCLKVLD__SHIFT        EQU 007H ; External Oscillator Valid Flag                  
OSCXCN_XCLKVLD__NOT_SET      EQU 000H ; External Oscillator is unused or not yet stable.
OSCXCN_XCLKVLD__SET          EQU 080H ; External Oscillator is running and stable.      
                                                                                        
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
FLSCL_BYPASS__BMASK    EQU 040H ; Flash Read Timing One-Shot Bypass                
FLSCL_BYPASS__SHIFT    EQU 006H ; Flash Read Timing One-Shot Bypass                
FLSCL_BYPASS__ONE_SHOT EQU 000H ; The one-shot determines the flash read time. This
                                ; setting should be used for operating frequencies 
                                ; less than 14 MHz.                                
FLSCL_BYPASS__SYSCLK   EQU 040H ; The system clock determines the flash read time. 
                                ; This setting should be used for frequencies      
                                ; greater than 14 MHz.                             
                                                                                   
;------------------------------------------------------------------------------
; FLWR Enums (Flash Write Only @ 0xE5)
;------------------------------------------------------------------------------
FLWR_FLWR__FMASK EQU 0FFH ; Flash Write Only
FLWR_FLWR__SHIFT EQU 000H ; Flash Write Only
                                            
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
; OSCICL Enums (High Frequency Oscillator Calibration @ 0xAF)
;------------------------------------------------------------------------------
OSCICL_OSCICL__FMASK EQU 07FH ; Oscillator Calibration                   
OSCICL_OSCICL__SHIFT EQU 000H ; Oscillator Calibration                   
                                                                         
OSCICL_SSE__BMASK    EQU 080H ; Spread Spectrum Enable                   
OSCICL_SSE__SHIFT    EQU 007H ; Spread Spectrum Enable                   
OSCICL_SSE__DISABLED EQU 000H ; Spread Spectrum clock dithering disabled.
OSCICL_SSE__ENABLED  EQU 080H ; Spread Spectrum clock dithering enabled. 
                                                                         
;------------------------------------------------------------------------------
; OSCICN Enums (High Frequency Oscillator Control @ 0xB2)
;------------------------------------------------------------------------------
OSCICN_IFRDY__BMASK     EQU 040H ; Internal Oscillator Frequency Ready Flag       
OSCICN_IFRDY__SHIFT     EQU 006H ; Internal Oscillator Frequency Ready Flag       
OSCICN_IFRDY__NOT_SET   EQU 000H ; High Frequency Oscillator is not running at its
                                 ; programmed frequency.                          
OSCICN_IFRDY__SET       EQU 040H ; High Frequency Oscillator is running at its    
                                 ; programmed frequency.                          
                                                                                  
OSCICN_IOSCEN__BMASK    EQU 080H ; High Frequency Oscillator Enable               
OSCICN_IOSCEN__SHIFT    EQU 007H ; High Frequency Oscillator Enable               
OSCICN_IOSCEN__DISABLED EQU 000H ; High Frequency Oscillator disabled.            
OSCICN_IOSCEN__ENABLED  EQU 080H ; High Frequency Oscillator enabled.             
                                                                                  
;------------------------------------------------------------------------------
; I2C0CN Enums (I2C0 Control @ 0xAC)
;------------------------------------------------------------------------------
I2C0CN_BUSY__BMASK       EQU 001H ; Busy                                              
I2C0CN_BUSY__SHIFT       EQU 000H ; Busy                                              
I2C0CN_BUSY__NOT_SET     EQU 000H ; Device will acknowledge an I2C master.            
I2C0CN_BUSY__SET         EQU 001H ; Device will not respond to an I2C master. All I2C 
                                  ; data sent to the device will be NACKed.           
                                                                                      
I2C0CN_I2C0EN__BMASK     EQU 002H ; I2C Enable                                        
I2C0CN_I2C0EN__SHIFT     EQU 001H ; I2C Enable                                        
I2C0CN_I2C0EN__DISABLED  EQU 000H ; Disable the I2C0 Slave module.                    
I2C0CN_I2C0EN__ENABLED   EQU 002H ; Enable the I2C0 Slave module.                     
                                                                                      
I2C0CN_PRELOAD__BMASK    EQU 004H ; Preload Disable                                   
I2C0CN_PRELOAD__SHIFT    EQU 002H ; Preload Disable                                   
I2C0CN_PRELOAD__ENABLED  EQU 000H ; Data bytes must be written into the I2C0DOUT      
                                  ; register before the 8th SCL clock of the matching 
                                  ; slave address byte transfer arrives for an I2C    
                                  ; read operation.                                   
I2C0CN_PRELOAD__DISABLED EQU 004H ; Data bytes need not be preloaded for I2C read     
                                  ; operations. The data byte can be written to       
                                  ; I2C0DOUT during interrupt servicing or by the DMA.
                                                                                      
I2C0CN_TIMEOUT__BMASK    EQU 008H ; Timeout Enable                                    
I2C0CN_TIMEOUT__SHIFT    EQU 003H ; Timeout Enable                                    
I2C0CN_TIMEOUT__DISABLED EQU 000H ; Disable I2C SCL timeout detection using Timer 3.  
I2C0CN_TIMEOUT__ENABLED  EQU 008H ; Enable I2C SCL timeout detection using Timer 3.   
                                                                                      
I2C0CN_PINMD__BMASK      EQU 010H ; Pin Mode Enable                                   
I2C0CN_PINMD__SHIFT      EQU 004H ; Pin Mode Enable                                   
I2C0CN_PINMD__GPIO_MODE  EQU 000H ; Set the I2C0 Slave pins in GPIO mode.             
I2C0CN_PINMD__I2C_MODE   EQU 010H ; Set the I2C0 Slave pins in I2C mode.              
                                                                                      
I2C0CN_PUEN__BMASK       EQU 020H ; I2C Pull-Up Enable                                
I2C0CN_PUEN__SHIFT       EQU 005H ; I2C Pull-Up Enable                                
I2C0CN_PUEN__DISABLED    EQU 000H ; Disable internal pull-up resistors for the I2C0   
                                  ; Slave SCL and SDA pins.                           
I2C0CN_PUEN__ENABLED     EQU 020H ; Enable internal pull-up resistors for the I2C0    
                                  ; Slave SCL and SDA pins.                           
                                                                                      
;------------------------------------------------------------------------------
; I2C0DIN Enums (I2C0 Received Data @ 0xA5)
;------------------------------------------------------------------------------
I2C0DIN_I2C0DIN__FMASK EQU 0FFH ; I2C0 Received Data
I2C0DIN_I2C0DIN__SHIFT EQU 000H ; I2C0 Received Data
                                                    
;------------------------------------------------------------------------------
; I2C0DOUT Enums (I2C0 Transmit Data @ 0xA4)
;------------------------------------------------------------------------------
I2C0DOUT_I2C0DOUT__FMASK EQU 0FFH ; I2C0 Transmit Data
I2C0DOUT_I2C0DOUT__SHIFT EQU 000H ; I2C0 Transmit Data
                                                      
;------------------------------------------------------------------------------
; I2C0SLAD Enums (I2C0 Slave Address @ 0xAD)
;------------------------------------------------------------------------------
I2C0SLAD_I2C0SLAD__FMASK EQU 07FH ; I2C Hardware Slave Address
I2C0SLAD_I2C0SLAD__SHIFT EQU 000H ; I2C Hardware Slave Address
                                                              
;------------------------------------------------------------------------------
; I2C0STAT Enums (I2C0 Status @ 0xF8)
;------------------------------------------------------------------------------
I2C0STAT_RD__BMASK        EQU 001H ; I2C Read                                        
I2C0STAT_RD__SHIFT        EQU 000H ; I2C Read                                        
I2C0STAT_RD__NOT_SET      EQU 000H ; An I2C Read operation is not in progress.       
I2C0STAT_RD__SET          EQU 001H ; An I2C Read operation is in progress.           
                                                                                     
I2C0STAT_WR__BMASK        EQU 002H ; I2C Write                                       
I2C0STAT_WR__SHIFT        EQU 001H ; I2C Write                                       
I2C0STAT_WR__NOT_SET      EQU 000H ; An I2C Write operation is not in progress.      
I2C0STAT_WR__SET          EQU 002H ; An I2C Write operation is in progress.          
                                                                                     
I2C0STAT_STOP__BMASK      EQU 004H ; Stop                                            
I2C0STAT_STOP__SHIFT      EQU 002H ; Stop                                            
I2C0STAT_STOP__NOT_SET    EQU 000H ; A STOP is not pending.                          
I2C0STAT_STOP__SET        EQU 004H ; A STOP is currently pending for the I2C0 Slave. 
                                                                                     
I2C0STAT_START__BMASK     EQU 008H ; Start                                           
I2C0STAT_START__SHIFT     EQU 003H ; Start                                           
I2C0STAT_START__NOT_SET   EQU 000H ; A START was not detected.                       
I2C0STAT_START__SET       EQU 008H ; A START is currently pending for the I2C0 Slave.
                                                                                     
I2C0STAT_NACK__BMASK      EQU 010H ; NACK                                            
I2C0STAT_NACK__SHIFT      EQU 004H ; NACK                                            
I2C0STAT_NACK__NOT_SET    EQU 000H ; A NACK did not occur.                           
I2C0STAT_NACK__SET        EQU 010H ; A NACK occurred.                                
                                                                                     
I2C0STAT_I2C0INT__BMASK   EQU 020H ; I2C Interrupt                                   
I2C0STAT_I2C0INT__SHIFT   EQU 005H ; I2C Interrupt                                   
I2C0STAT_I2C0INT__NOT_SET EQU 000H ; An interrupt did not occur.                     
I2C0STAT_I2C0INT__SET     EQU 020H ; An interrupt occurred.                          
                                                                                     
I2C0STAT_ACTIVE__BMASK    EQU 040H ; Bus Active                                      
I2C0STAT_ACTIVE__SHIFT    EQU 006H ; Bus Active                                      
I2C0STAT_ACTIVE__NOT_SET  EQU 000H ; A transfer is not in progress.                  
I2C0STAT_ACTIVE__SET      EQU 040H ; A transfer is in progress.                      
                                                                                     
I2C0STAT_HSMODE__BMASK    EQU 080H ; High Speed Mode                                 
I2C0STAT_HSMODE__SHIFT    EQU 007H ; High Speed Mode                                 
I2C0STAT_HSMODE__NOT_SET  EQU 000H ; A High Speed transfer is not in progress.       
I2C0STAT_HSMODE__SET      EQU 080H ; A High Speed transfer is in progress.           
                                                                                     
;------------------------------------------------------------------------------
; EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
;------------------------------------------------------------------------------
EIE1_ESMB0__BMASK     EQU 001H ; SMBus (SMB0) Interrupt Enable                     
EIE1_ESMB0__SHIFT     EQU 000H ; SMBus (SMB0) Interrupt Enable                     
EIE1_ESMB0__DISABLED  EQU 000H ; Disable all SMB0 interrupts.                      
EIE1_ESMB0__ENABLED   EQU 001H ; Enable interrupt requests generated by SMB0.      
                                                                                   
EIE1_ERTC0A__BMASK    EQU 002H ; RTC Alarm Interrupts Enable                       
EIE1_ERTC0A__SHIFT    EQU 001H ; RTC Alarm Interrupts Enable                       
EIE1_ERTC0A__DISABLED EQU 000H ; Disable RTC Alarm interrupts.                     
EIE1_ERTC0A__ENABLED  EQU 002H ; Enable interrupt requests generated by a RTC      
                               ; Alarm.                                            
                                                                                   
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
                                                                                   
EIE1_EDMA0M__BMASK    EQU 020H ; DMA0 Mid-Point Interrupt Enable                   
EIE1_EDMA0M__SHIFT    EQU 005H ; DMA0 Mid-Point Interrupt Enable                   
EIE1_EDMA0M__DISABLED EQU 000H ; Disable DMA0M interrupts.                         
EIE1_EDMA0M__ENABLED  EQU 020H ; Enable interrupt requests generated by the DMA0M  
                               ; flags.                                            
                                                                                   
EIE1_EDMA0__BMASK     EQU 040H ; DMA0 Interrupt Enable                             
EIE1_EDMA0__SHIFT     EQU 006H ; DMA0 Interrupt Enable                             
EIE1_EDMA0__DISABLED  EQU 000H ; Disable DMA0 interrupts.                          
EIE1_EDMA0__ENABLED   EQU 040H ; Enable interrupt requests generated by DMA0.      
                                                                                   
EIE1_ET3__BMASK       EQU 080H ; Timer 3 Interrupt Enable                          
EIE1_ET3__SHIFT       EQU 007H ; Timer 3 Interrupt Enable                          
EIE1_ET3__DISABLED    EQU 000H ; Disable Timer 3 interrupts.                       
EIE1_ET3__ENABLED     EQU 080H ; Enable interrupt requests generated by the TF3L or
                               ; TF3H flags.                                       
                                                                                   
;------------------------------------------------------------------------------
; EIE2 Enums (Extended Interrupt Enable 2 @ 0xE7)
;------------------------------------------------------------------------------
EIE2_EMAT__BMASK      EQU 002H ; Port Match Interrupts Enable                         
EIE2_EMAT__SHIFT      EQU 001H ; Port Match Interrupts Enable                         
EIE2_EMAT__DISABLED   EQU 000H ; Disable all Port Match interrupts.                   
EIE2_EMAT__ENABLED    EQU 002H ; Enable interrupt requests generated by a Port        
                               ; Match.                                               
                                                                                      
EIE2_ERTC0F__BMASK    EQU 004H ; RTC Oscillator Fail Interrupt Enable                 
EIE2_ERTC0F__SHIFT    EQU 002H ; RTC Oscillator Fail Interrupt Enable                 
EIE2_ERTC0F__DISABLED EQU 000H ; Disable RTC Alarm interrupts.                        
EIE2_ERTC0F__ENABLED  EQU 004H ; Enable interrupt requests generated by the RTC       
                               ; Alarm.                                               
                                                                                      
EIE2_EMAC0__BMASK     EQU 008H ; MAC0 Interrupt Enable                                
EIE2_EMAC0__SHIFT     EQU 003H ; MAC0 Interrupt Enable                                
EIE2_EMAC0__DISABLED  EQU 000H ; Disable MAC0 event interrupt.                        
EIE2_EMAC0__ENABLED   EQU 008H ; Enable interrupt requests generated by MAC0.         
                                                                                      
EIE2_ECSCPT__BMASK    EQU 010H ; Capacitive Sense Conversion Complete Interrupt Enable
EIE2_ECSCPT__SHIFT    EQU 004H ; Capacitive Sense Conversion Complete Interrupt Enable
EIE2_ECSCPT__DISABLED EQU 000H ; Disable Capacitive Sense Conversion Complete         
                               ; interrupt.                                           
EIE2_ECSCPT__ENABLED  EQU 010H ; Enable interrupt requests generated by CS0INT.       
                                                                                      
EIE2_ECSDC__BMASK     EQU 020H ; Capacitive Sense Digital Comparator Interrupt Enable 
EIE2_ECSDC__SHIFT     EQU 005H ; Capacitive Sense Digital Comparator Interrupt Enable 
EIE2_ECSDC__DISABLED  EQU 000H ; Disable Capacitive Sense Digital Comparator          
                               ; interrupt.                                           
EIE2_ECSDC__ENABLED   EQU 020H ; Enable interrupt requests generated by the           
                               ; Capacitive Sense Digital Comparator.                 
                                                                                      
EIE2_ECSEOS__BMASK    EQU 040H ; Capacitive Sense End of Scan Interrupt Enable        
EIE2_ECSEOS__SHIFT    EQU 006H ; Capacitive Sense End of Scan Interrupt Enable        
EIE2_ECSEOS__DISABLED EQU 000H ; Disable Capacitive Sense End of Scan interrupt.      
EIE2_ECSEOS__ENABLED  EQU 040H ; Enable interrupt requests generated by the           
                               ; Capacitive Sense End of Scan.                        
                                                                                      
EIE2_EI2C0__BMASK     EQU 080H ; I2C0 Slave Interrupt Enable                          
EIE2_EI2C0__SHIFT     EQU 007H ; I2C0 Slave Interrupt Enable                          
EIE2_EI2C0__DISABLED  EQU 000H ; Disable I2C0 Slave event interrupt.                  
EIE2_EI2C0__ENABLED   EQU 080H ; Enable interrupt requests generated by the I2C0      
                               ; Slave.                                               
                                                                                      
;------------------------------------------------------------------------------
; EIP1 Enums (Extended Interrupt Priority 1 @ 0xF6)
;------------------------------------------------------------------------------
EIP1_PSMB0__BMASK  EQU 001H ; SMBus (SMB0) Interrupt Priority Control                     
EIP1_PSMB0__SHIFT  EQU 000H ; SMBus (SMB0) Interrupt Priority Control                     
EIP1_PSMB0__LOW    EQU 000H ; SMB0 interrupt set to low priority level.                   
EIP1_PSMB0__HIGH   EQU 001H ; SMB0 interrupt set to high priority level.                  
                                                                                          
EIP1_PRTC0A__BMASK EQU 002H ; RTC Alarm Interrupt Priority Control                        
EIP1_PRTC0A__SHIFT EQU 001H ; RTC Alarm Interrupt Priority Control                        
EIP1_PRTC0A__LOW   EQU 000H ; RTC Alarm interrupt set to low priority level.              
EIP1_PRTC0A__HIGH  EQU 002H ; RTC Alarm interrupt set to high priority level.             
                                                                                          
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
                                                                                          
EIP1_PDMA0M__BMASK EQU 020H ; DMA0 Mid-Point Interrupt Priority Control                   
EIP1_PDMA0M__SHIFT EQU 005H ; DMA0 Mid-Point Interrupt Priority Control                   
EIP1_PDMA0M__LOW   EQU 000H ; Mid-point DMA0 interrupts set to low priority               
                            ; level.                                                      
EIP1_PDMA0M__HIGH  EQU 020H ; Mid-point DMA0 interrupts set to high priority              
                            ; level.                                                      
                                                                                          
EIP1_PDMA0__BMASK  EQU 040H ; DMA0 Interrupt Priority Control                             
EIP1_PDMA0__SHIFT  EQU 006H ; DMA0 Interrupt Priority Control                             
EIP1_PDMA0__LOW    EQU 000H ; DMA0 interrupts set to low priority level.                  
EIP1_PDMA0__HIGH   EQU 040H ; DMA0 interrupts set to high priority level.                 
                                                                                          
EIP1_PT3__BMASK    EQU 080H ; Timer 3 Interrupt Priority Control                          
EIP1_PT3__SHIFT    EQU 007H ; Timer 3 Interrupt Priority Control                          
EIP1_PT3__LOW      EQU 000H ; Timer 3 interrupts set to low priority level.               
EIP1_PT3__HIGH     EQU 080H ; Timer 3 interrupts set to high priority level.              
                                                                                          
;------------------------------------------------------------------------------
; EIP2 Enums (Extended Interrupt Priority 2 @ 0xF7)
;------------------------------------------------------------------------------
EIP2_PMAT__BMASK   EQU 002H ; Port Match Interrupt Priority Control                          
EIP2_PMAT__SHIFT   EQU 001H ; Port Match Interrupt Priority Control                          
EIP2_PMAT__LOW     EQU 000H ; Port Match interrupt set to low priority level.                
EIP2_PMAT__HIGH    EQU 002H ; Port Match interrupt set to high priority level.               
                                                                                             
EIP2_PRTC0F__BMASK EQU 004H ; RTC Oscillator Fail Interrupt Priority Control                 
EIP2_PRTC0F__SHIFT EQU 002H ; RTC Oscillator Fail Interrupt Priority Control                 
EIP2_PRTC0F__LOW   EQU 000H ; RTC Alarm interrupt set to low priority level.                 
EIP2_PRTC0F__HIGH  EQU 004H ; RTC Alarm interrupt set to high priority level.                
                                                                                             
EIP2_PMAC0__BMASK  EQU 008H ; MAC0 Interrupt Priority Control                                
EIP2_PMAC0__SHIFT  EQU 003H ; MAC0 Interrupt Priority Control                                
EIP2_PMAC0__LOW    EQU 000H ; MAC0 interrupts set to low priority level.                     
EIP2_PMAC0__HIGH   EQU 008H ; MAC0 interrupts set to high priority level.                    
                                                                                             
EIP2_PCSCPT__BMASK EQU 010H ; Capacitive Sense Conversion Complete Interrupt Priority Control
EIP2_PCSCPT__SHIFT EQU 004H ; Capacitive Sense Conversion Complete Interrupt Priority Control
EIP2_PCSCPT__LOW   EQU 000H ; Capacitive Sense Conversion Complete interrupt set             
                            ; to low priority level.                                         
EIP2_PCSCPT__HIGH  EQU 010H ; Capacitive Sense Conversion Complete interrupt set             
                            ; to high priority level.                                        
                                                                                             
EIP2_PCSDC__BMASK  EQU 020H ; Capacitive Sense Digital Comparator Interrupt Priority Control 
EIP2_PCSDC__SHIFT  EQU 005H ; Capacitive Sense Digital Comparator Interrupt Priority Control 
EIP2_PCSDC__LOW    EQU 000H ; Capacitive Sense Digital Comparator interrupt set              
                            ; to low priority level.                                         
EIP2_PCSDC__HIGH   EQU 020H ; Capacitive Sense Digital Comparator interrupt set              
                            ; to high priority level.                                        
                                                                                             
EIP2_PCSEOS__BMASK EQU 040H ; Capacitive Sense End of Scan Interrupt Priority Control        
EIP2_PCSEOS__SHIFT EQU 006H ; Capacitive Sense End of Scan Interrupt Priority Control        
EIP2_PCSEOS__LOW   EQU 000H ; Capacitive Sense End of Scan interrupt set to low              
                            ; priority level.                                                
EIP2_PCSEOS__HIGH  EQU 040H ; Capacitive Sense End of Scan interrupt set to high             
                            ; priority level.                                                
                                                                                             
EIP2_PI2C0__BMASK  EQU 080H ; I2C0 Slave Interrupt Priority Control                          
EIP2_PI2C0__SHIFT  EQU 007H ; I2C0 Slave Interrupt Priority Control                          
EIP2_PI2C0__LOW    EQU 000H ; I2C0 Slave interrupts set to low priority level.               
EIP2_PI2C0__HIGH   EQU 080H ; I2C0 Slave interrupts set to high priority level.              
                                                                                             
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
; MAC0ACC0 Enums (Accumulator Byte 0 @ 0xD2)
;------------------------------------------------------------------------------
MAC0ACC0_MAC0ACC0__FMASK EQU 0FFH ; MAC0 Accumulator Byte 0
MAC0ACC0_MAC0ACC0__SHIFT EQU 000H ; MAC0 Accumulator Byte 0
                                                           
;------------------------------------------------------------------------------
; MAC0ACC1 Enums (Accumulator Byte 1 @ 0xD3)
;------------------------------------------------------------------------------
MAC0ACC1_MAC0ACC1__FMASK EQU 0FFH ; MAC0 Accumulator Byte 1
MAC0ACC1_MAC0ACC1__SHIFT EQU 000H ; MAC0 Accumulator Byte 1
                                                           
;------------------------------------------------------------------------------
; MAC0ACC2 Enums (Accumulator Byte 2 @ 0xD4)
;------------------------------------------------------------------------------
MAC0ACC2_MAC0ACC2__FMASK EQU 0FFH ; MAC0 Accumulator Byte 2
MAC0ACC2_MAC0ACC2__SHIFT EQU 000H ; MAC0 Accumulator Byte 2
                                                           
;------------------------------------------------------------------------------
; MAC0ACC3 Enums (Accumulator Byte 3 @ 0xD5)
;------------------------------------------------------------------------------
MAC0ACC3_MAC0ACC3__FMASK EQU 0FFH ; MAC0 Accumulator Byte 3
MAC0ACC3_MAC0ACC3__SHIFT EQU 000H ; MAC0 Accumulator Byte 3
                                                           
;------------------------------------------------------------------------------
; MAC0AH Enums (Operand A High Byte @ 0xAB)
;------------------------------------------------------------------------------
MAC0AH_MAC0AH__FMASK EQU 0FFH ; MAC0 A High Byte
MAC0AH_MAC0AH__SHIFT EQU 000H ; MAC0 A High Byte
                                                
;------------------------------------------------------------------------------
; MAC0AL Enums (Operand A Low Byte @ 0xAA)
;------------------------------------------------------------------------------
MAC0AL_MAC0AL__FMASK EQU 0FFH ; MAC0 A Low Byte
MAC0AL_MAC0AL__SHIFT EQU 000H ; MAC0 A Low Byte
                                               
;------------------------------------------------------------------------------
; MAC0BH Enums (Operand B High Byte @ 0xAF)
;------------------------------------------------------------------------------
MAC0BH_MAC0BH__FMASK EQU 0FFH ; MAC0 B High Byte
MAC0BH_MAC0BH__SHIFT EQU 000H ; MAC0 B High Byte
                                                
;------------------------------------------------------------------------------
; MAC0BL Enums (Operand B Low Byte @ 0xAE)
;------------------------------------------------------------------------------
MAC0BL_MAC0BL__FMASK EQU 0FFH ; MAC0 B Low Byte
MAC0BL_MAC0BL__SHIFT EQU 000H ; MAC0 B Low Byte
                                               
;------------------------------------------------------------------------------
; MAC0CF0 Enums (MAC0 Configuration 0 @ 0xC0)
;------------------------------------------------------------------------------
MAC0CF0_ANEGATE__BMASK      EQU 001H ; Negate A input                                   
MAC0CF0_ANEGATE__SHIFT      EQU 000H ; Negate A input                                   
MAC0CF0_ANEGATE__DISABLED   EQU 000H ; No change is applied to the MAC0 A input before  
                                     ; the multiply operation.                          
MAC0CF0_ANEGATE__ENABLED    EQU 001H ; Hardware negates the MAC0 A input before the     
                                     ; multiply operation.                              
                                                                                        
MAC0CF0_BNEGATE__BMASK      EQU 002H ; Negate B input                                   
MAC0CF0_BNEGATE__SHIFT      EQU 001H ; Negate B input                                   
MAC0CF0_BNEGATE__DISABLED   EQU 000H ; No change is applied to the MAC0 B input before  
                                     ; the multiply operation.                          
MAC0CF0_BNEGATE__ENABLED    EQU 002H ; Hardware negates the MAC0 B input before the     
                                     ; multiply operation.                              
                                                                                        
MAC0CF0_ACCNEGATE__BMASK    EQU 004H ; Negate Accumulator Input                         
MAC0CF0_ACCNEGATE__SHIFT    EQU 002H ; Negate Accumulator Input                         
MAC0CF0_ACCNEGATE__DISABLED EQU 000H ; No change is applied to the accumulator before it
                                     ; is added to the multiplication result of A and B.
MAC0CF0_ACCNEGATE__ENABLED  EQU 004H ; Hardware negates the accumulator before it is    
                                     ; added to the multiplication result of A and B.   
                                                                                        
MAC0CF0_ACCMD__BMASK        EQU 008H ; Accumulate Mode                                  
MAC0CF0_ACCMD__SHIFT        EQU 003H ; Accumulate Mode                                  
MAC0CF0_ACCMD__MAC_MODE     EQU 000H ; Select multiply-and-accumulate (MAC) mode.       
MAC0CF0_ACCMD__MUL_MODE     EQU 008H ; Select multiply-only mode.                       
                                                                                        
MAC0CF0_FRACMD__BMASK       EQU 010H ; Fractional Mode                                  
MAC0CF0_FRACMD__SHIFT       EQU 004H ; Fractional Mode                                  
MAC0CF0_FRACMD__INT_MODE    EQU 000H ; MAC0 operates in Integer Mode.                   
MAC0CF0_FRACMD__FRAC_MODE   EQU 010H ; MAC0 operates in Fractional Mode.                
                                                                                        
MAC0CF0_CLRACC__BMASK       EQU 020H ; Clear Accumulator                                
MAC0CF0_CLRACC__SHIFT       EQU 005H ; Clear Accumulator                                
MAC0CF0_CLRACC__START       EQU 020H ; Clear the accumulator and the related MAC0STA    
                                     ; register flags.                                  
                                                                                        
MAC0CF0_SHIFTDIR__BMASK     EQU 040H ; Accumulator Shift Direction                      
MAC0CF0_SHIFTDIR__SHIFT     EQU 006H ; Accumulator Shift Direction                      
MAC0CF0_SHIFTDIR__LEFT      EQU 000H ; The MAC0 accumulator will be shifted left.       
MAC0CF0_SHIFTDIR__RIGHT     EQU 040H ; The MAC0 accumulator will be shifted right.      
                                                                                        
MAC0CF0_SHIFTEN__BMASK      EQU 080H ; Accumulator Shift Control                        
MAC0CF0_SHIFTEN__SHIFT      EQU 007H ; Accumulator Shift Control                        
MAC0CF0_SHIFTEN__DISABLED   EQU 000H ; Do not shift the accumulator by one bit in the   
                                     ; SHIFTDIR direction.                              
MAC0CF0_SHIFTEN__ENABLED    EQU 080H ; Shift the accumulator by one bit in the SHIFTDIR 
                                     ; direction.                                       
                                                                                        
;------------------------------------------------------------------------------
; MAC0CF1 Enums (MAC0 Configuration 1 @ 0xC4)
;------------------------------------------------------------------------------
MAC0CF1_APOSTINC__BMASK    EQU 001H ; A Post-Increment Enable                           
MAC0CF1_APOSTINC__SHIFT    EQU 000H ; A Post-Increment Enable                           
MAC0CF1_APOSTINC__DISABLED EQU 000H ; Do not change the MAC0 A register after a MAC0    
                                    ; operation.                                        
MAC0CF1_APOSTINC__ENABLED  EQU 001H ; Increment the MAC0 A register after a MAC0        
                                    ; operation.                                        
                                                                                        
MAC0CF1_ADMASRC__BMASK     EQU 002H ; A DMA Data Source Selection                       
MAC0CF1_ADMASRC__SHIFT     EQU 001H ; A DMA Data Source Selection                       
MAC0CF1_ADMASRC__XRAM      EQU 000H ; Each MAC0 operation will request the DMA fetch    
                                    ; data from XRAM for the MAC0 A register.           
MAC0CF1_ADMASRC__EXISTING  EQU 002H ; Each MAC0 operation will use existing data in MAC0
                                    ; A register.                                       
                                                                                        
MAC0CF1_BPOSTINC__BMASK    EQU 004H ; B Post-Increment Enable                           
MAC0CF1_BPOSTINC__SHIFT    EQU 002H ; B Post-Increment Enable                           
MAC0CF1_BPOSTINC__DISABLED EQU 000H ; Do not change the MAC0 B register after a MAC0    
                                    ; operation.                                        
MAC0CF1_BPOSTINC__ENABLED  EQU 004H ; Increment the MAC0 B register after a MAC0        
                                    ; operation.                                        
                                                                                        
MAC0CF1_MAC0BC__BMASK      EQU 008H ; B DMA Data Source Selection                       
MAC0CF1_MAC0BC__SHIFT      EQU 003H ; B DMA Data Source Selection                       
MAC0CF1_MAC0BC__XRAM       EQU 000H ; Each MAC0 operation will request the DMA fetch    
                                    ; data from XRAM for the MAC0 B register.           
MAC0CF1_MAC0BC__EXISTING   EQU 008H ; Each MAC0 operation will use existing data in MAC0
                                    ; B register.                                       
                                                                                        
MAC0CF1_SIGNEDEN__BMASK    EQU 010H ; Signed Mode Enable                                
MAC0CF1_SIGNEDEN__SHIFT    EQU 004H ; Signed Mode Enable                                
MAC0CF1_SIGNEDEN__DISABLED EQU 000H ; MAC operations use unsigned arithmetic.           
MAC0CF1_SIGNEDEN__ENABLED  EQU 010H ; MAC operations use signed arithmetic.             
                                                                                        
MAC0CF1_SIGNEXP__BMASK     EQU 020H ; Expected Accumulator Sign                         
MAC0CF1_SIGNEXP__SHIFT     EQU 005H ; Expected Accumulator Sign                         
MAC0CF1_SIGNEXP__NOT_SET   EQU 000H ; Set the expected sign to zero.                    
MAC0CF1_SIGNEXP__SET       EQU 020H ; Set the expected sign to one.                     
                                                                                        
MAC0CF1_MBSHIFT__FMASK     EQU 0C0H ; Multi-Bit Accumulator Shift                       
MAC0CF1_MBSHIFT__SHIFT     EQU 006H ; Multi-Bit Accumulator Shift                       
MAC0CF1_MBSHIFT__1_BIT     EQU 000H ; Shift the accumulator 1 bit.                      
MAC0CF1_MBSHIFT__2_BITS    EQU 040H ; Shift the accumulator by 2 bits.                  
MAC0CF1_MBSHIFT__3_BITS    EQU 080H ; Shift the accumulator by 3 bits.                  
MAC0CF1_MBSHIFT__4_BITS    EQU 0C0H ; Shift the accumulator by 4 bits.                  
                                                                                        
;------------------------------------------------------------------------------
; MAC0CF2 Enums (MAC0 Configuration 2 @ 0xC5)
;------------------------------------------------------------------------------
MAC0CF2_ACCDMAIN__FMASK               EQU 003H ; Accumulator DMA Input Count                       
MAC0CF2_ACCDMAIN__SHIFT               EQU 000H ; Accumulator DMA Input Count                       
MAC0CF2_ACCDMAIN__1_BYTE              EQU 000H ; Request the DMA move 1 byte from XRAM to the      
                                               ; accumulator.                                      
MAC0CF2_ACCDMAIN__2_BYTES             EQU 001H ; Request the DMA move 2 bytes from XRAM to the     
                                               ; accumulator.                                      
MAC0CF2_ACCDMAIN__4_BYTES             EQU 002H ; Request the DMA move 4 bytes from XRAM to the     
                                               ; accumulator.                                      
MAC0CF2_ACCDMAIN__5_BYTES             EQU 003H ; Request the DMA move 5 bytes from XRAM to the     
                                               ; accumulator.                                      
                                                                                                   
MAC0CF2_ACCDMAOUT__FMASK              EQU 00CH ; Accumulator DMA Output Count                      
MAC0CF2_ACCDMAOUT__SHIFT              EQU 002H ; Accumulator DMA Output Count                      
MAC0CF2_ACCDMAOUT__1_BYTE             EQU 000H ; Request the DMA move 1 byte from the accumulator  
                                               ; to XRAM.                                          
MAC0CF2_ACCDMAOUT__2_BYTES            EQU 004H ; Request the DMA move 2 bytes from the accumulator 
                                               ; to XRAM.                                          
MAC0CF2_ACCDMAOUT__4_BYTES            EQU 008H ; Request the DMA move 4 bytes from the accumulator 
                                               ; to XRAM.                                          
MAC0CF2_ACCDMAOUT__5_BYTES            EQU 00CH ; Request the DMA move 5 bytes from the accumulator 
                                               ; to XRAM.                                          
                                                                                                   
MAC0CF2_ACCALIGN__FMASK               EQU 030H ; Accumulator Alignment                             
MAC0CF2_ACCALIGN__SHIFT               EQU 004H ; Accumulator Alignment                             
MAC0CF2_ACCALIGN__NO_SHIFT            EQU 000H ; Do not shift the accumulator output.              
MAC0CF2_ACCALIGN__SHIFT_RIGHT_1_BYTE  EQU 010H ; Shift the accumulator output right by 1 byte.     
MAC0CF2_ACCALIGN__SHIFT_RIGHT_3_BYTES EQU 020H ; Shift the accumulator output right by 3 bytes.    
MAC0CF2_ACCALIGN__SHIFT_RIGHT_4_BYTES EQU 030H ; Shift the accumulator output right by 4 bytes.    
                                                                                                   
MAC0CF2_SATURATE__BMASK               EQU 040H ; Saturation Enable                                 
MAC0CF2_SATURATE__SHIFT               EQU 006H ; Saturation Enable                                 
MAC0CF2_SATURATE__DISABLED            EQU 000H ; Rounded result will not saturate.                 
MAC0CF2_SATURATE__ENABLED             EQU 040H ; Rounded result will saturate.                     
                                                                                                   
MAC0CF2_ROUND__BMASK                  EQU 080H ; Rounding Enable                                   
MAC0CF2_ROUND__SHIFT                  EQU 007H ; Rounding Enable                                   
MAC0CF2_ROUND__DISABLED               EQU 000H ; MAC0 accumulator does not contain a 16-bit rounded
                                               ; result.                                           
MAC0CF2_ROUND__ENABLED                EQU 080H ; MAC0 accumulator contains a 16-bit rounded result.
                                                                                                   
;------------------------------------------------------------------------------
; MAC0INTE Enums (MAC0 Interrupt Enable @ 0xC1)
;------------------------------------------------------------------------------
MAC0INTE_SOVFIEN__BMASK       EQU 001H ; Soft Overflow Interrupt Enable    
MAC0INTE_SOVFIEN__SHIFT       EQU 000H ; Soft Overflow Interrupt Enable    
MAC0INTE_SOVFIEN__DISABLED    EQU 000H ; Disable soft overflow interrupts. 
MAC0INTE_SOVFIEN__ENABLED     EQU 001H ; Enable soft overflow interrupts.  
                                                                           
MAC0INTE_ZEROFIEN__BMASK      EQU 002H ; Zero Flag Interrupt Enable        
MAC0INTE_ZEROFIEN__SHIFT      EQU 001H ; Zero Flag Interrupt Enable        
MAC0INTE_ZEROFIEN__DISABLED   EQU 000H ; Disable zero flag interrupts.     
MAC0INTE_ZEROFIEN__ENABLED    EQU 002H ; Enable zero flag interrupts.      
                                                                           
MAC0INTE_SCHANGEIEN__BMASK    EQU 004H ; Sign Change Event Interrupt Enable
MAC0INTE_SCHANGEIEN__SHIFT    EQU 002H ; Sign Change Event Interrupt Enable
MAC0INTE_SCHANGEIEN__DISABLED EQU 000H ; Disable sign change interrupts.   
MAC0INTE_SCHANGEIEN__ENABLED  EQU 004H ; Enable sign change interrupts.    
                                                                           
;------------------------------------------------------------------------------
; MAC0ITER Enums (Iteration Counter @ 0xD7)
;------------------------------------------------------------------------------
MAC0ITER_MAC0ITER__FMASK EQU 0FFH ; Iteration Counter
MAC0ITER_MAC0ITER__SHIFT EQU 000H ; Iteration Counter
                                                     
;------------------------------------------------------------------------------
; MAC0OVF Enums (Accumulator Overflow Byte @ 0xD6)
;------------------------------------------------------------------------------
MAC0OVF_MAC0OVF__FMASK EQU 0FFH ; MAC0 Accumulator Overflow Byte
MAC0OVF_MAC0OVF__SHIFT EQU 000H ; MAC0 Accumulator Overflow Byte
                                                                
;------------------------------------------------------------------------------
; MAC0STA Enums (MAC0 Status @ 0xCF)
;------------------------------------------------------------------------------
MAC0STA_BUSY__BMASK      EQU 001H ; Busy Flag                                         
MAC0STA_BUSY__SHIFT      EQU 000H ; Busy Flag                                         
MAC0STA_BUSY__NOT_SET    EQU 000H ; The MAC module is not busy with an operation or   
                                  ; series of operations.                             
MAC0STA_BUSY__SET        EQU 001H ; The MAC module is busy with an operation or series
                                  ; of operations.                                    
                                                                                      
MAC0STA_SOVF__BMASK      EQU 002H ; Soft Overflow Flag                                
MAC0STA_SOVF__SHIFT      EQU 001H ; Soft Overflow Flag                                
MAC0STA_SOVF__NOT_SET    EQU 000H ; A soft overflow did not occur.                    
MAC0STA_SOVF__SET        EQU 002H ; A soft overflow occurred.                         
                                                                                      
MAC0STA_ZEROF__BMASK     EQU 004H ; Zero Flag                                         
MAC0STA_ZEROF__SHIFT     EQU 002H ; Zero Flag                                         
MAC0STA_ZEROF__NOT_SET   EQU 000H ; The last operation did not result in an           
                                  ; accumulator value of zero.                        
MAC0STA_ZEROF__SET       EQU 004H ; The last operation resulted in an accumulator     
                                  ; value of zero.                                    
                                                                                      
MAC0STA_HOVF__BMASK      EQU 008H ; Hard Overflow Flag                                
MAC0STA_HOVF__SHIFT      EQU 003H ; Hard Overflow Flag                                
MAC0STA_HOVF__NOT_SET    EQU 000H ; A hardware overflow did not occur.                
MAC0STA_HOVF__SET        EQU 008H ; A hardware overflow occurred.                     
                                                                                      
MAC0STA_ACCRDY__BMASK    EQU 010H ; ACC Ready Status Flag                             
MAC0STA_ACCRDY__SHIFT    EQU 004H ; ACC Ready Status Flag                             
MAC0STA_ACCRDY__NOT_SET  EQU 000H ; A MAC operation did not complete.                 
MAC0STA_ACCRDY__SET      EQU 010H ; A MAC operation completed.                        
                                                                                      
MAC0STA_SCHANGE__BMASK   EQU 020H ; Sign Change Event                                 
MAC0STA_SCHANGE__SHIFT   EQU 005H ; Sign Change Event                                 
MAC0STA_SCHANGE__NOT_SET EQU 000H ; The accumulator result matches the expected sign  
                                  ; (SIGNEXP) bit.                                    
MAC0STA_SCHANGE__SET     EQU 020H ; The accumulator result does not match the expected
                                  ; sign (SIGNEXP) bit.                               
                                                                                      
MAC0STA_MACINT__BMASK    EQU 040H ; Interrupt Flag                                    
MAC0STA_MACINT__SHIFT    EQU 006H ; Interrupt Flag                                    
MAC0STA_MACINT__NOT_SET  EQU 000H ; An interrupt did not occur.                       
MAC0STA_MACINT__SET      EQU 040H ; An interrupt occurred and is pending.             
                                                                                      
;------------------------------------------------------------------------------
; XBR0 Enums (Port I/O Crossbar 0 @ 0x95)
;------------------------------------------------------------------------------
XBR0_URT0E__BMASK           EQU 001H ; UART I/O Output Enable                     
XBR0_URT0E__SHIFT           EQU 000H ; UART I/O Output Enable                     
XBR0_URT0E__DISABLED        EQU 000H ; UART I/O unavailable at Port pin.          
XBR0_URT0E__ENABLED         EQU 001H ; UART TX, RX routed to Port pins.           
                                                                                  
XBR0_SPI0E__BMASK           EQU 002H ; SPI I/O Enable                             
XBR0_SPI0E__SHIFT           EQU 001H ; SPI I/O Enable                             
XBR0_SPI0E__DISABLED        EQU 000H ; SPI I/O unavailable at Port pins.          
XBR0_SPI0E__ENABLED         EQU 002H ; SPI I/O routed to Port pins. The SPI can be
                                     ; assigned either 3 or 4 GPIO pins.          
                                                                                  
XBR0_SMB0E__BMASK           EQU 004H ; SMBus0 I/O Enable                          
XBR0_SMB0E__SHIFT           EQU 002H ; SMBus0 I/O Enable                          
XBR0_SMB0E__DISABLED        EQU 000H ; SMBus0 I/O unavailable at Port pins.       
XBR0_SMB0E__ENABLED         EQU 004H ; SMBus0 I/O routed to Port pins.            
                                                                                  
XBR0_SYSCKE__BMASK          EQU 008H ; SYSCLK Output Enable                       
XBR0_SYSCKE__SHIFT          EQU 003H ; SYSCLK Output Enable                       
XBR0_SYSCKE__DISABLED       EQU 000H ; SYSCLK unavailable at Port pin.            
XBR0_SYSCKE__ENABLED        EQU 008H ; SYSCLK output routed to Port pin.          
                                                                                  
XBR0_PCA0ME__FMASK          EQU 070H ; PCA Module I/O Enable                      
XBR0_PCA0ME__SHIFT          EQU 004H ; PCA Module I/O Enable                      
XBR0_PCA0ME__DISABLED       EQU 000H ; All PCA I/O unavailable at Port pins.      
XBR0_PCA0ME__CEX0           EQU 010H ; CEX0 routed to Port pin.                   
XBR0_PCA0ME__CEX0_CEX1      EQU 020H ; CEX0, CEX1 routed to Port pins.            
XBR0_PCA0ME__CEX0_CEX1_CEX2 EQU 030H ; CEX0, CEX1, CEX2 routed to Port pins.      
                                                                                  
XBR0_ECIE__BMASK            EQU 080H ; PCA0 External Counter Input Enable         
XBR0_ECIE__SHIFT            EQU 007H ; PCA0 External Counter Input Enable         
XBR0_ECIE__DISABLED         EQU 000H ; ECI unavailable at Port pin.               
XBR0_ECIE__ENABLED          EQU 080H ; ECI routed to Port pin.                    
                                                                                  
;------------------------------------------------------------------------------
; XBR1 Enums (Port I/O Crossbar 1 @ 0x96)
;------------------------------------------------------------------------------
XBR1_T0E__BMASK                 EQU 001H ; T0 Enable                                       
XBR1_T0E__SHIFT                 EQU 000H ; T0 Enable                                       
XBR1_T0E__DISABLED              EQU 000H ; T0 unavailable at Port pin.                     
XBR1_T0E__ENABLED               EQU 001H ; T0 routed to Port pin.                          
                                                                                           
XBR1_T1E__BMASK                 EQU 002H ; T1 Enable                                       
XBR1_T1E__SHIFT                 EQU 001H ; T1 Enable                                       
XBR1_T1E__DISABLED              EQU 000H ; T1 unavailable at Port pin.                     
XBR1_T1E__ENABLED               EQU 002H ; T1 routed to Port pin.                          
                                                                                           
XBR1_XBARE__BMASK               EQU 040H ; Crossbar Enable                                 
XBR1_XBARE__SHIFT               EQU 006H ; Crossbar Enable                                 
XBR1_XBARE__DISABLED            EQU 000H ; Crossbar disabled.                              
XBR1_XBARE__ENABLED             EQU 040H ; Crossbar enabled.                               
                                                                                           
XBR1_WEAKPUD__BMASK             EQU 080H ; Port I/O Weak Pullup Disable                    
XBR1_WEAKPUD__SHIFT             EQU 007H ; Port I/O Weak Pullup Disable                    
XBR1_WEAKPUD__PULL_UPS_ENABLED  EQU 000H ; Weak Pullups enabled (except for Ports whose I/O
                                         ; are configured for analog mode).                
XBR1_WEAKPUD__PULL_UPS_DISABLED EQU 080H ; Weak Pullups disabled.                          
                                                                                           
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
PCA0CPM0_PWM16__8_BIT   EQU 000H ; 8 to 11-bit PWM selected.                      
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
PCA0CPM1_PWM16__8_BIT   EQU 000H ; 8 to 11-bit PWM selected.                      
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
PCA0CPM2_PWM16__8_BIT   EQU 000H ; 8 to 11-bit PWM selected.                      
PCA0CPM2_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
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
PCA0MD_WDTE__ENABLED         EQU 040H ; Enable PCA Module 2 as the Watchdog Timer.        
                                                                                          
PCA0MD_CIDL__BMASK           EQU 080H ; PCA Counter/Timer Idle Control                    
PCA0MD_CIDL__SHIFT           EQU 007H ; PCA Counter/Timer Idle Control                    
PCA0MD_CIDL__NORMAL          EQU 000H ; PCA continues to function normally while the      
                                      ; system controller is in Idle Mode.                
PCA0MD_CIDL__SUSPEND         EQU 080H ; PCA operation is suspended while the system       
                                      ; controller is in Idle Mode.                       
                                                                                          
;------------------------------------------------------------------------------
; PCA0PWM Enums (PCA PWM Configuration @ 0xDF)
;------------------------------------------------------------------------------
PCA0PWM_CLSEL__FMASK             EQU 003H ; Cycle Length Select                              
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
PCON_GF1__NOT_SET EQU 000H ; The GF0 flag is not set. Clear the GF0 flag.    
PCON_GF1__SET     EQU 008H ; The GF0 flag is set. Set the GF0 flag.          
                                                                             
PCON_GF2__BMASK   EQU 010H ; General Purpose Flag 2                          
PCON_GF2__SHIFT   EQU 004H ; General Purpose Flag 2                          
PCON_GF2__NOT_SET EQU 000H ; The GF0 flag is not set. Clear the GF0 flag.    
PCON_GF2__SET     EQU 010H ; The GF0 flag is set. Set the GF0 flag.          
                                                                             
PCON_GF3__BMASK   EQU 020H ; General Purpose Flag 3                          
PCON_GF3__SHIFT   EQU 005H ; General Purpose Flag 3                          
PCON_GF3__NOT_SET EQU 000H ; The GF0 flag is not set. Clear the GF0 flag.    
PCON_GF3__SET     EQU 020H ; The GF0 flag is set. Set the GF0 flag.          
                                                                             
PCON_GF4__BMASK   EQU 040H ; General Purpose Flag 4                          
PCON_GF4__SHIFT   EQU 006H ; General Purpose Flag 4                          
PCON_GF4__NOT_SET EQU 000H ; The GF0 flag is not set. Clear the GF0 flag.    
PCON_GF4__SET     EQU 040H ; The GF0 flag is set. Set the GF0 flag.          
                                                                             
PCON_GF5__BMASK   EQU 080H ; General Purpose Flag 5                          
PCON_GF5__SHIFT   EQU 007H ; General Purpose Flag 5                          
PCON_GF5__NOT_SET EQU 000H ; The GF0 flag is not set. Clear the GF0 flag.    
PCON_GF5__SET     EQU 080H ; The GF0 flag is set. Set the GF0 flag.          
                                                                             
;------------------------------------------------------------------------------
; PMU0CF Enums (Power Management Unit Configuration @ 0xB5)
;------------------------------------------------------------------------------
PMU0CF_PMATWK__BMASK    EQU 002H ; Port Match Wake-up Source Enable and Flag         
PMU0CF_PMATWK__SHIFT    EQU 001H ; Port Match Wake-up Source Enable and Flag         
PMU0CF_PMATWK__NOT_SET  EQU 000H ; A Port Match event did not cause the last wake-up.
PMU0CF_PMATWK__SET      EQU 002H ; A Port Match event caused the last wake-up.       
                                                                                     
PMU0CF_RTCAWK__BMASK    EQU 004H ; RTC Alarm Wake-up Source Enable and Flag          
PMU0CF_RTCAWK__SHIFT    EQU 002H ; RTC Alarm Wake-up Source Enable and Flag          
PMU0CF_RTCAWK__NOT_SET  EQU 000H ; A RTC Alarm did not cause the last wake-up.       
PMU0CF_RTCAWK__SET      EQU 004H ; A RTC Alarm caused the last wake-up.              
                                                                                     
PMU0CF_RTCFWK__BMASK    EQU 008H ; RTC Oscillator Fail Wake-up Source Enable and Flag
PMU0CF_RTCFWK__SHIFT    EQU 003H ; RTC Oscillator Fail Wake-up Source Enable and Flag
PMU0CF_RTCFWK__NOT_SET  EQU 000H ; An RTC oscillator fail event did not cause the    
                                 ; last wake-up.                                     
PMU0CF_RTCFWK__SET      EQU 008H ; An RTC oscillator fail event caused the last wake-
                                 ; up.                                               
                                                                                     
PMU0CF_RSTWK__BMASK     EQU 010H ; Reset Pin Wake-up Flag                            
PMU0CF_RSTWK__SHIFT     EQU 004H ; Reset Pin Wake-up Flag                            
PMU0CF_RSTWK__NOT_SET   EQU 000H ; No glitch detected on /RST.                       
PMU0CF_RSTWK__SET       EQU 010H ; Glitch detected on /RST.                          
                                                                                     
PMU0CF_CLEAR__BMASK     EQU 020H ; Wake-up Flag Clear                                
PMU0CF_CLEAR__SHIFT     EQU 005H ; Wake-up Flag Clear                                
PMU0CF_CLEAR__ALL_FLAGS EQU 020H ; Clear all wake-up flags.                          
                                                                                     
PMU0CF_SUSPEND__BMASK   EQU 040H ; Suspend Mode Select                               
PMU0CF_SUSPEND__SHIFT   EQU 006H ; Suspend Mode Select                               
PMU0CF_SUSPEND__NORMAL  EQU 000H ; Suspend mode not activated.                       
PMU0CF_SUSPEND__START   EQU 040H ; Place the device in Suspend mode.                 
                                                                                     
PMU0CF_SLEEP__BMASK     EQU 080H ; Sleep Mode Select                                 
PMU0CF_SLEEP__SHIFT     EQU 007H ; Sleep Mode Select                                 
PMU0CF_SLEEP__NORMAL    EQU 000H ; Sleep mode not activated.                         
PMU0CF_SLEEP__START     EQU 080H ; Place the device in Sleep mode.                   
                                                                                     
;------------------------------------------------------------------------------
; PMU0FL Enums (Power Management Unit Flag @ 0xCE)
;------------------------------------------------------------------------------
PMU0FL_CS0WK__BMASK   EQU 001H ; CS0 Wake-up Source Enable and Flag              
PMU0FL_CS0WK__SHIFT   EQU 000H ; CS0 Wake-up Source Enable and Flag              
PMU0FL_CS0WK__NOT_SET EQU 000H ; A Capacitive Sensing  comparator threshold event
                               ; did not cause the last wake-up.                 
PMU0FL_CS0WK__SET     EQU 001H ; A Capacitive Sensing  comparator threshold event
                               ; caused the last wake-up.                        
                                                                                 
PMU0FL_I2CWK__BMASK   EQU 002H ; I2C0 Slave Wake-up Source Enable and Flag       
PMU0FL_I2CWK__SHIFT   EQU 001H ; I2C0 Slave Wake-up Source Enable and Flag       
PMU0FL_I2CWK__NOT_SET EQU 000H ; An I2C0 Slave event did not cause the last wake-
                               ; up.                                             
PMU0FL_I2CWK__SET     EQU 002H ; An I2C0 Slave event caused the last wake-up.    
                                                                                 
;------------------------------------------------------------------------------
; PMU0MD Enums (Power Management Unit Mode @ 0xCF)
;------------------------------------------------------------------------------
PMU0MD_WAKEOE__BMASK    EQU 040H ; Wakeup Request Output Enable       
PMU0MD_WAKEOE__SHIFT    EQU 006H ; Wakeup Request Output Enable       
PMU0MD_WAKEOE__DISABLED EQU 000H ; Disable the wake-up request signal.
PMU0MD_WAKEOE__ENABLED  EQU 040H ; Enable the wake-up request signal. 
                                                                      
PMU0MD_RTCOE__BMASK     EQU 080H ; Buffered RTC Output Enable         
PMU0MD_RTCOE__SHIFT     EQU 007H ; Buffered RTC Output Enable         
PMU0MD_RTCOE__DISABLED  EQU 000H ; Disable the buffered RTC output.   
PMU0MD_RTCOE__ENABLED   EQU 080H ; Enable the buffered RTC output.    
                                                                      
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
; P0DRV Enums (Port 0 Drive Strength @ 0x99)
;------------------------------------------------------------------------------
P0DRV_B0__BMASK      EQU 001H ; Port 0 Bit 0 Drive Strength                
P0DRV_B0__SHIFT      EQU 000H ; Port 0 Bit 0 Drive Strength                
P0DRV_B0__LOW_DRIVE  EQU 000H ; P0.0 output has low output drive strength. 
P0DRV_B0__HIGH_DRIVE EQU 001H ; P0.0 output has high output drive strength.
                                                                           
P0DRV_B1__BMASK      EQU 002H ; Port 0 Bit 1 Drive Strength                
P0DRV_B1__SHIFT      EQU 001H ; Port 0 Bit 1 Drive Strength                
P0DRV_B1__LOW_DRIVE  EQU 000H ; P0.1 output has low output drive strength. 
P0DRV_B1__HIGH_DRIVE EQU 002H ; P0.1 output has high output drive strength.
                                                                           
P0DRV_B2__BMASK      EQU 004H ; Port 0 Bit 2 Drive Strength                
P0DRV_B2__SHIFT      EQU 002H ; Port 0 Bit 2 Drive Strength                
P0DRV_B2__LOW_DRIVE  EQU 000H ; P0.2 output has low output drive strength. 
P0DRV_B2__HIGH_DRIVE EQU 004H ; P0.2 output has high output drive strength.
                                                                           
P0DRV_B3__BMASK      EQU 008H ; Port 0 Bit 3 Drive Strength                
P0DRV_B3__SHIFT      EQU 003H ; Port 0 Bit 3 Drive Strength                
P0DRV_B3__LOW_DRIVE  EQU 000H ; P0.3 output has low output drive strength. 
P0DRV_B3__HIGH_DRIVE EQU 008H ; P0.3 output has high output drive strength.
                                                                           
P0DRV_B4__BMASK      EQU 010H ; Port 0 Bit 4 Drive Strength                
P0DRV_B4__SHIFT      EQU 004H ; Port 0 Bit 4 Drive Strength                
P0DRV_B4__LOW_DRIVE  EQU 000H ; P0.4 output has low output drive strength. 
P0DRV_B4__HIGH_DRIVE EQU 010H ; P0.4 output has high output drive strength.
                                                                           
P0DRV_B5__BMASK      EQU 020H ; Port 0 Bit 5 Drive Strength                
P0DRV_B5__SHIFT      EQU 005H ; Port 0 Bit 5 Drive Strength                
P0DRV_B5__LOW_DRIVE  EQU 000H ; P0.5 output has low output drive strength. 
P0DRV_B5__HIGH_DRIVE EQU 020H ; P0.5 output has high output drive strength.
                                                                           
P0DRV_B6__BMASK      EQU 040H ; Port 0 Bit 6 Drive Strength                
P0DRV_B6__SHIFT      EQU 006H ; Port 0 Bit 6 Drive Strength                
P0DRV_B6__LOW_DRIVE  EQU 000H ; P0.6 output has low output drive strength. 
P0DRV_B6__HIGH_DRIVE EQU 040H ; P0.6 output has high output drive strength.
                                                                           
P0DRV_B7__BMASK      EQU 080H ; Port 0 Bit 7 Drive Strength                
P0DRV_B7__SHIFT      EQU 007H ; Port 0 Bit 7 Drive Strength                
P0DRV_B7__LOW_DRIVE  EQU 000H ; P0.7 output has low output drive strength. 
P0DRV_B7__HIGH_DRIVE EQU 080H ; P0.7 output has high output drive strength.
                                                                           
;------------------------------------------------------------------------------
; P0MASK Enums (Port 0 Mask @ 0x8B)
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
; P0MAT Enums (Port 0 Match @ 0xF4)
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
; P0MDIN Enums (Port 0 Input Mode @ 0xEC)
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
; P0MDOUT Enums (Port 0 Output Mode @ 0xD9)
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
; P0SKIP Enums (Port 0 Skip @ 0xB6)
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
; P1DRV Enums (Port 1 Drive Strength @ 0x9A)
;------------------------------------------------------------------------------
P1DRV_B0__BMASK      EQU 001H ; Port 1 Bit 0 Drive Strength                
P1DRV_B0__SHIFT      EQU 000H ; Port 1 Bit 0 Drive Strength                
P1DRV_B0__LOW_DRIVE  EQU 000H ; P1.0 output has low output drive strength. 
P1DRV_B0__HIGH_DRIVE EQU 001H ; P1.0 output has high output drive strength.
                                                                           
P1DRV_B1__BMASK      EQU 002H ; Port 1 Bit 1 Drive Strength                
P1DRV_B1__SHIFT      EQU 001H ; Port 1 Bit 1 Drive Strength                
P1DRV_B1__LOW_DRIVE  EQU 000H ; P1.1 output has low output drive strength. 
P1DRV_B1__HIGH_DRIVE EQU 002H ; P1.1 output has high output drive strength.
                                                                           
P1DRV_B2__BMASK      EQU 004H ; Port 1 Bit 2 Drive Strength                
P1DRV_B2__SHIFT      EQU 002H ; Port 1 Bit 2 Drive Strength                
P1DRV_B2__LOW_DRIVE  EQU 000H ; P1.2 output has low output drive strength. 
P1DRV_B2__HIGH_DRIVE EQU 004H ; P1.2 output has high output drive strength.
                                                                           
P1DRV_B3__BMASK      EQU 008H ; Port 1 Bit 3 Drive Strength                
P1DRV_B3__SHIFT      EQU 003H ; Port 1 Bit 3 Drive Strength                
P1DRV_B3__LOW_DRIVE  EQU 000H ; P1.3 output has low output drive strength. 
P1DRV_B3__HIGH_DRIVE EQU 008H ; P1.3 output has high output drive strength.
                                                                           
P1DRV_B4__BMASK      EQU 010H ; Port 1 Bit 4 Drive Strength                
P1DRV_B4__SHIFT      EQU 004H ; Port 1 Bit 4 Drive Strength                
P1DRV_B4__LOW_DRIVE  EQU 000H ; P1.4 output has low output drive strength. 
P1DRV_B4__HIGH_DRIVE EQU 010H ; P1.4 output has high output drive strength.
                                                                           
P1DRV_B5__BMASK      EQU 020H ; Port 1 Bit 5 Drive Strength                
P1DRV_B5__SHIFT      EQU 005H ; Port 1 Bit 5 Drive Strength                
P1DRV_B5__LOW_DRIVE  EQU 000H ; P1.5 output has low output drive strength. 
P1DRV_B5__HIGH_DRIVE EQU 020H ; P1.5 output has high output drive strength.
                                                                           
P1DRV_B6__BMASK      EQU 040H ; Port 1 Bit 6 Drive Strength                
P1DRV_B6__SHIFT      EQU 006H ; Port 1 Bit 6 Drive Strength                
P1DRV_B6__LOW_DRIVE  EQU 000H ; P1.6 output has low output drive strength. 
P1DRV_B6__HIGH_DRIVE EQU 040H ; P1.6 output has high output drive strength.
                                                                           
P1DRV_B7__BMASK      EQU 080H ; Port 1 Bit 7 Drive Strength                
P1DRV_B7__SHIFT      EQU 007H ; Port 1 Bit 7 Drive Strength                
P1DRV_B7__LOW_DRIVE  EQU 000H ; P1.7 output has low output drive strength. 
P1DRV_B7__HIGH_DRIVE EQU 080H ; P1.7 output has high output drive strength.
                                                                           
;------------------------------------------------------------------------------
; P1MASK Enums (Port 1 Mask @ 0x8C)
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
; P1MAT Enums (Port 1 Match @ 0xF5)
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
; P1MDIN Enums (Port 1 Input Mode @ 0xED)
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
; P1MDOUT Enums (Port 1 Output Mode @ 0xDC)
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
; P1SKIP Enums (Port 1 Skip @ 0xC6)
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
; P2DRV Enums (Port 2 Drive Strength @ 0x9B)
;------------------------------------------------------------------------------
P2DRV_B0__BMASK      EQU 001H ; Port 2 Bit 0 Drive Strength                
P2DRV_B0__SHIFT      EQU 000H ; Port 2 Bit 0 Drive Strength                
P2DRV_B0__LOW_DRIVE  EQU 000H ; P2.0 output has low output drive strength. 
P2DRV_B0__HIGH_DRIVE EQU 001H ; P2.0 output has high output drive strength.
                                                                           
P2DRV_B1__BMASK      EQU 002H ; Port 2 Bit 1 Drive Strength                
P2DRV_B1__SHIFT      EQU 001H ; Port 2 Bit 1 Drive Strength                
P2DRV_B1__LOW_DRIVE  EQU 000H ; P2.1 output has low output drive strength. 
P2DRV_B1__HIGH_DRIVE EQU 002H ; P2.1 output has high output drive strength.
                                                                           
P2DRV_B2__BMASK      EQU 004H ; Port 2 Bit 2 Drive Strength                
P2DRV_B2__SHIFT      EQU 002H ; Port 2 Bit 2 Drive Strength                
P2DRV_B2__LOW_DRIVE  EQU 000H ; P2.2 output has low output drive strength. 
P2DRV_B2__HIGH_DRIVE EQU 004H ; P2.2 output has high output drive strength.
                                                                           
P2DRV_B3__BMASK      EQU 008H ; Port 2 Bit 3 Drive Strength                
P2DRV_B3__SHIFT      EQU 003H ; Port 2 Bit 3 Drive Strength                
P2DRV_B3__LOW_DRIVE  EQU 000H ; P2.3 output has low output drive strength. 
P2DRV_B3__HIGH_DRIVE EQU 008H ; P2.3 output has high output drive strength.
                                                                           
P2DRV_B4__BMASK      EQU 010H ; Port 2 Bit 4 Drive Strength                
P2DRV_B4__SHIFT      EQU 004H ; Port 2 Bit 4 Drive Strength                
P2DRV_B4__LOW_DRIVE  EQU 000H ; P2.4 output has low output drive strength. 
P2DRV_B4__HIGH_DRIVE EQU 010H ; P2.4 output has high output drive strength.
                                                                           
P2DRV_B5__BMASK      EQU 020H ; Port 2 Bit 5 Drive Strength                
P2DRV_B5__SHIFT      EQU 005H ; Port 2 Bit 5 Drive Strength                
P2DRV_B5__LOW_DRIVE  EQU 000H ; P2.5 output has low output drive strength. 
P2DRV_B5__HIGH_DRIVE EQU 020H ; P2.5 output has high output drive strength.
                                                                           
P2DRV_B6__BMASK      EQU 040H ; Port 2 Bit 6 Drive Strength                
P2DRV_B6__SHIFT      EQU 006H ; Port 2 Bit 6 Drive Strength                
P2DRV_B6__LOW_DRIVE  EQU 000H ; P2.6 output has low output drive strength. 
P2DRV_B6__HIGH_DRIVE EQU 040H ; P2.6 output has high output drive strength.
                                                                           
P2DRV_B7__BMASK      EQU 080H ; Port 2 Bit 7 Drive Strength                
P2DRV_B7__SHIFT      EQU 007H ; Port 2 Bit 7 Drive Strength                
P2DRV_B7__LOW_DRIVE  EQU 000H ; P2.7 output has low output drive strength. 
P2DRV_B7__HIGH_DRIVE EQU 080H ; P2.7 output has high output drive strength.
                                                                           
;------------------------------------------------------------------------------
; P2MASK Enums (Port 2 Mask @ 0x84)
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
                                                                                 
P2MASK_B2__BMASK    EQU 004H ; Port 2 Bit 2 Mask Value                           
P2MASK_B2__SHIFT    EQU 002H ; Port 2 Bit 2 Mask Value                           
P2MASK_B2__IGNORED  EQU 000H ; P2.2 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P2MASK_B2__COMPARED EQU 004H ; P2.2 pin logic value is compared to P2MAT.2.      
                                                                                 
P2MASK_B3__BMASK    EQU 008H ; Port 2 Bit 3 Mask Value                           
P2MASK_B3__SHIFT    EQU 003H ; Port 2 Bit 3 Mask Value                           
P2MASK_B3__IGNORED  EQU 000H ; P2.3 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P2MASK_B3__COMPARED EQU 008H ; P2.3 pin logic value is compared to P2MAT.3.      
                                                                                 
P2MASK_B4__BMASK    EQU 010H ; Port 2 Bit 4 Mask Value                           
P2MASK_B4__SHIFT    EQU 004H ; Port 2 Bit 4 Mask Value                           
P2MASK_B4__IGNORED  EQU 000H ; P2.4 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P2MASK_B4__COMPARED EQU 010H ; P2.4 pin logic value is compared to P2MAT.4.      
                                                                                 
P2MASK_B5__BMASK    EQU 020H ; Port 2 Bit 5 Mask Value                           
P2MASK_B5__SHIFT    EQU 005H ; Port 2 Bit 5 Mask Value                           
P2MASK_B5__IGNORED  EQU 000H ; P2.5 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P2MASK_B5__COMPARED EQU 020H ; P2.5 pin logic value is compared to P2MAT.5.      
                                                                                 
P2MASK_B6__BMASK    EQU 040H ; Port 2 Bit 6 Mask Value                           
P2MASK_B6__SHIFT    EQU 006H ; Port 2 Bit 6 Mask Value                           
P2MASK_B6__IGNORED  EQU 000H ; P2.6 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P2MASK_B6__COMPARED EQU 040H ; P2.6 pin logic value is compared to P2MAT.6.      
                                                                                 
P2MASK_B7__BMASK    EQU 080H ; Port 2 Bit 7 Mask Value                           
P2MASK_B7__SHIFT    EQU 007H ; Port 2 Bit 7 Mask Value                           
P2MASK_B7__IGNORED  EQU 000H ; P2.7 pin logic value is ignored and will not cause
                             ; a port mismatch event.                            
P2MASK_B7__COMPARED EQU 080H ; P2.7 pin logic value is compared to P2MAT.7.      
                                                                                 
;------------------------------------------------------------------------------
; P2MAT Enums (Port 2 Match @ 0x85)
;------------------------------------------------------------------------------
P2MAT_B0__BMASK EQU 001H ; Port 2 Bit 0 Match Value                         
P2MAT_B0__SHIFT EQU 000H ; Port 2 Bit 0 Match Value                         
P2MAT_B0__LOW   EQU 000H ; P2.0 pin logic value is compared with logic LOW. 
P2MAT_B0__HIGH  EQU 001H ; P2.0 pin logic value is compared with logic HIGH.
                                                                            
P2MAT_B1__BMASK EQU 002H ; Port 2 Bit 1 Match Value                         
P2MAT_B1__SHIFT EQU 001H ; Port 2 Bit 1 Match Value                         
P2MAT_B1__LOW   EQU 000H ; P2.1 pin logic value is compared with logic LOW. 
P2MAT_B1__HIGH  EQU 002H ; P2.1 pin logic value is compared with logic HIGH.
                                                                            
P2MAT_B2__BMASK EQU 004H ; Port 2 Bit 2 Match Value                         
P2MAT_B2__SHIFT EQU 002H ; Port 2 Bit 2 Match Value                         
P2MAT_B2__LOW   EQU 000H ; P2.2 pin logic value is compared with logic LOW. 
P2MAT_B2__HIGH  EQU 004H ; P2.2 pin logic value is compared with logic HIGH.
                                                                            
P2MAT_B3__BMASK EQU 008H ; Port 2 Bit 3 Match Value                         
P2MAT_B3__SHIFT EQU 003H ; Port 2 Bit 3 Match Value                         
P2MAT_B3__LOW   EQU 000H ; P2.3 pin logic value is compared with logic LOW. 
P2MAT_B3__HIGH  EQU 008H ; P2.3 pin logic value is compared with logic HIGH.
                                                                            
P2MAT_B4__BMASK EQU 010H ; Port 2 Bit 4 Match Value                         
P2MAT_B4__SHIFT EQU 004H ; Port 2 Bit 4 Match Value                         
P2MAT_B4__LOW   EQU 000H ; P2.4 pin logic value is compared with logic LOW. 
P2MAT_B4__HIGH  EQU 010H ; P2.4 pin logic value is compared with logic HIGH.
                                                                            
P2MAT_B5__BMASK EQU 020H ; Port 2 Bit 5 Match Value                         
P2MAT_B5__SHIFT EQU 005H ; Port 2 Bit 5 Match Value                         
P2MAT_B5__LOW   EQU 000H ; P2.5 pin logic value is compared with logic LOW. 
P2MAT_B5__HIGH  EQU 020H ; P2.5 pin logic value is compared with logic HIGH.
                                                                            
P2MAT_B6__BMASK EQU 040H ; Port 2 Bit 6 Match Value                         
P2MAT_B6__SHIFT EQU 006H ; Port 2 Bit 6 Match Value                         
P2MAT_B6__LOW   EQU 000H ; P2.6 pin logic value is compared with logic LOW. 
P2MAT_B6__HIGH  EQU 040H ; P2.6 pin logic value is compared with logic HIGH.
                                                                            
P2MAT_B7__BMASK EQU 080H ; Port 2 Bit 7 Match Value                         
P2MAT_B7__SHIFT EQU 007H ; Port 2 Bit 7 Match Value                         
P2MAT_B7__LOW   EQU 000H ; P2.7 pin logic value is compared with logic LOW. 
P2MAT_B7__HIGH  EQU 080H ; P2.7 pin logic value is compared with logic HIGH.
                                                                            
;------------------------------------------------------------------------------
; P2MDIN Enums (Port 2 Input Mode @ 0xEE)
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
; P2MDOUT Enums (Port 2 Output Mode @ 0xDD)
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
; P2SKIP Enums (Port 2 Skip @ 0xC7)
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
; P3 Enums (Port 3 Pin Latch @ 0xE1)
;------------------------------------------------------------------------------
P3_B0__BMASK EQU 001H ; Port 3 Bit 0 Latch                            
P3_B0__SHIFT EQU 000H ; Port 3 Bit 0 Latch                            
P3_B0__LOW   EQU 000H ; P3.0 is low. Set P3.0 to drive low.           
P3_B0__HIGH  EQU 001H ; P3.0 is high. Set P3.0 to drive or float high.
                                                                      
P3_B1__BMASK EQU 002H ; Port 3 Bit 1 Latch                            
P3_B1__SHIFT EQU 001H ; Port 3 Bit 1 Latch                            
P3_B1__LOW   EQU 000H ; P3.1 is low. Set P3.1 to drive low.           
P3_B1__HIGH  EQU 002H ; P3.1 is high. Set P3.1 to drive or float high.
                                                                      
P3_B2__BMASK EQU 004H ; Port 3 Bit 2 Latch                            
P3_B2__SHIFT EQU 002H ; Port 3 Bit 2 Latch                            
P3_B2__LOW   EQU 000H ; P3.2 is low. Set P3.2 to drive low.           
P3_B2__HIGH  EQU 004H ; P3.2 is high. Set P3.2 to drive or float high.
                                                                      
P3_B3__BMASK EQU 008H ; Port 3 Bit 3 Latch                            
P3_B3__SHIFT EQU 003H ; Port 3 Bit 3 Latch                            
P3_B3__LOW   EQU 000H ; P3.3 is low. Set P3.3 to drive low.           
P3_B3__HIGH  EQU 008H ; P3.3 is high. Set P3.3 to drive or float high.
                                                                      
P3_B4__BMASK EQU 010H ; Port 3 Bit 4 Latch                            
P3_B4__SHIFT EQU 004H ; Port 3 Bit 4 Latch                            
P3_B4__LOW   EQU 000H ; P3.4 is low. Set P3.4 to drive low.           
P3_B4__HIGH  EQU 010H ; P3.4 is high. Set P3.4 to drive or float high.
                                                                      
P3_B5__BMASK EQU 020H ; Port 3 Bit 5 Latch                            
P3_B5__SHIFT EQU 005H ; Port 3 Bit 5 Latch                            
P3_B5__LOW   EQU 000H ; P3.5 is low. Set P3.5 to drive low.           
P3_B5__HIGH  EQU 020H ; P3.5 is high. Set P3.5 to drive or float high.
                                                                      
P3_B6__BMASK EQU 040H ; Port 3 Bit 6 Latch                            
P3_B6__SHIFT EQU 006H ; Port 3 Bit 6 Latch                            
P3_B6__LOW   EQU 000H ; P3.6 is low. Set P3.6 to drive low.           
P3_B6__HIGH  EQU 040H ; P3.6 is high. Set P3.6 to drive or float high.
                                                                      
P3_B7__BMASK EQU 080H ; Port 3 Bit 7 Latch                            
P3_B7__SHIFT EQU 007H ; Port 3 Bit 7 Latch                            
P3_B7__LOW   EQU 000H ; P3.7 is low. Set P3.7 to drive low.           
P3_B7__HIGH  EQU 080H ; P3.7 is high. Set P3.7 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P3DRV Enums (Port 3 Drive Strength @ 0x9C)
;------------------------------------------------------------------------------
P3DRV_B0__BMASK      EQU 001H ; Port 3 Bit 0 Drive Strength                
P3DRV_B0__SHIFT      EQU 000H ; Port 3 Bit 0 Drive Strength                
P3DRV_B0__LOW_DRIVE  EQU 000H ; P3.0 output has low output drive strength. 
P3DRV_B0__HIGH_DRIVE EQU 001H ; P3.0 output has high output drive strength.
                                                                           
P3DRV_B1__BMASK      EQU 002H ; Port 3 Bit 1 Drive Strength                
P3DRV_B1__SHIFT      EQU 001H ; Port 3 Bit 1 Drive Strength                
P3DRV_B1__LOW_DRIVE  EQU 000H ; P3.1 output has low output drive strength. 
P3DRV_B1__HIGH_DRIVE EQU 002H ; P3.1 output has high output drive strength.
                                                                           
P3DRV_B2__BMASK      EQU 004H ; Port 3 Bit 2 Drive Strength                
P3DRV_B2__SHIFT      EQU 002H ; Port 3 Bit 2 Drive Strength                
P3DRV_B2__LOW_DRIVE  EQU 000H ; P3.2 output has low output drive strength. 
P3DRV_B2__HIGH_DRIVE EQU 004H ; P3.2 output has high output drive strength.
                                                                           
P3DRV_B3__BMASK      EQU 008H ; Port 3 Bit 3 Drive Strength                
P3DRV_B3__SHIFT      EQU 003H ; Port 3 Bit 3 Drive Strength                
P3DRV_B3__LOW_DRIVE  EQU 000H ; P3.3 output has low output drive strength. 
P3DRV_B3__HIGH_DRIVE EQU 008H ; P3.3 output has high output drive strength.
                                                                           
P3DRV_B4__BMASK      EQU 010H ; Port 3 Bit 4 Drive Strength                
P3DRV_B4__SHIFT      EQU 004H ; Port 3 Bit 4 Drive Strength                
P3DRV_B4__LOW_DRIVE  EQU 000H ; P3.4 output has low output drive strength. 
P3DRV_B4__HIGH_DRIVE EQU 010H ; P3.4 output has high output drive strength.
                                                                           
P3DRV_B5__BMASK      EQU 020H ; Port 3 Bit 5 Drive Strength                
P3DRV_B5__SHIFT      EQU 005H ; Port 3 Bit 5 Drive Strength                
P3DRV_B5__LOW_DRIVE  EQU 000H ; P3.5 output has low output drive strength. 
P3DRV_B5__HIGH_DRIVE EQU 020H ; P3.5 output has high output drive strength.
                                                                           
P3DRV_B6__BMASK      EQU 040H ; Port 3 Bit 6 Drive Strength                
P3DRV_B6__SHIFT      EQU 006H ; Port 3 Bit 6 Drive Strength                
P3DRV_B6__LOW_DRIVE  EQU 000H ; P3.6 output has low output drive strength. 
P3DRV_B6__HIGH_DRIVE EQU 040H ; P3.6 output has high output drive strength.
                                                                           
P3DRV_B7__BMASK      EQU 080H ; Port 3 Bit 7 Drive Strength                
P3DRV_B7__SHIFT      EQU 007H ; Port 3 Bit 7 Drive Strength                
P3DRV_B7__LOW_DRIVE  EQU 000H ; P3.7 output has low output drive strength. 
P3DRV_B7__HIGH_DRIVE EQU 080H ; P3.7 output has high output drive strength.
                                                                           
;------------------------------------------------------------------------------
; P3MDIN Enums (Port 3 Input Mode @ 0xEF)
;------------------------------------------------------------------------------
P3MDIN_B0__BMASK   EQU 001H ; Port 3 Bit 0 Input Mode                 
P3MDIN_B0__SHIFT   EQU 000H ; Port 3 Bit 0 Input Mode                 
P3MDIN_B0__ANALOG  EQU 000H ; P3.0 pin is configured for analog mode. 
P3MDIN_B0__DIGITAL EQU 001H ; P3.0 pin is configured for digital mode.
                                                                      
P3MDIN_B1__BMASK   EQU 002H ; Port 3 Bit 1 Input Mode                 
P3MDIN_B1__SHIFT   EQU 001H ; Port 3 Bit 1 Input Mode                 
P3MDIN_B1__ANALOG  EQU 000H ; P3.1 pin is configured for analog mode. 
P3MDIN_B1__DIGITAL EQU 002H ; P3.1 pin is configured for digital mode.
                                                                      
P3MDIN_B2__BMASK   EQU 004H ; Port 3 Bit 2 Input Mode                 
P3MDIN_B2__SHIFT   EQU 002H ; Port 3 Bit 2 Input Mode                 
P3MDIN_B2__ANALOG  EQU 000H ; P3.2 pin is configured for analog mode. 
P3MDIN_B2__DIGITAL EQU 004H ; P3.2 pin is configured for digital mode.
                                                                      
P3MDIN_B3__BMASK   EQU 008H ; Port 3 Bit 3 Input Mode                 
P3MDIN_B3__SHIFT   EQU 003H ; Port 3 Bit 3 Input Mode                 
P3MDIN_B3__ANALOG  EQU 000H ; P3.3 pin is configured for analog mode. 
P3MDIN_B3__DIGITAL EQU 008H ; P3.3 pin is configured for digital mode.
                                                                      
P3MDIN_B4__BMASK   EQU 010H ; Port 3 Bit 4 Input Mode                 
P3MDIN_B4__SHIFT   EQU 004H ; Port 3 Bit 4 Input Mode                 
P3MDIN_B4__ANALOG  EQU 000H ; P3.4 pin is configured for analog mode. 
P3MDIN_B4__DIGITAL EQU 010H ; P3.4 pin is configured for digital mode.
                                                                      
P3MDIN_B5__BMASK   EQU 020H ; Port 3 Bit 5 Input Mode                 
P3MDIN_B5__SHIFT   EQU 005H ; Port 3 Bit 5 Input Mode                 
P3MDIN_B5__ANALOG  EQU 000H ; P3.5 pin is configured for analog mode. 
P3MDIN_B5__DIGITAL EQU 020H ; P3.5 pin is configured for digital mode.
                                                                      
P3MDIN_B6__BMASK   EQU 040H ; Port 3 Bit 6 Input Mode                 
P3MDIN_B6__SHIFT   EQU 006H ; Port 3 Bit 6 Input Mode                 
P3MDIN_B6__ANALOG  EQU 000H ; P3.6 pin is configured for analog mode. 
P3MDIN_B6__DIGITAL EQU 040H ; P3.6 pin is configured for digital mode.
                                                                      
P3MDIN_B7__BMASK   EQU 080H ; Port 3 Bit 7 Input Mode                 
P3MDIN_B7__SHIFT   EQU 007H ; Port 3 Bit 7 Input Mode                 
P3MDIN_B7__ANALOG  EQU 000H ; P3.7 pin is configured for analog mode. 
P3MDIN_B7__DIGITAL EQU 080H ; P3.7 pin is configured for digital mode.
                                                                      
;------------------------------------------------------------------------------
; P3MDOUT Enums (Port 3 Output Mode @ 0xDF)
;------------------------------------------------------------------------------
P3MDOUT_B0__BMASK      EQU 001H ; Port 3 Bit 0 Output Mode  
P3MDOUT_B0__SHIFT      EQU 000H ; Port 3 Bit 0 Output Mode  
P3MDOUT_B0__OPEN_DRAIN EQU 000H ; P3.0 output is open-drain.
P3MDOUT_B0__PUSH_PULL  EQU 001H ; P3.0 output is push-pull. 
                                                            
P3MDOUT_B1__BMASK      EQU 002H ; Port 3 Bit 1 Output Mode  
P3MDOUT_B1__SHIFT      EQU 001H ; Port 3 Bit 1 Output Mode  
P3MDOUT_B1__OPEN_DRAIN EQU 000H ; P3.1 output is open-drain.
P3MDOUT_B1__PUSH_PULL  EQU 002H ; P3.1 output is push-pull. 
                                                            
P3MDOUT_B2__BMASK      EQU 004H ; Port 3 Bit 2 Output Mode  
P3MDOUT_B2__SHIFT      EQU 002H ; Port 3 Bit 2 Output Mode  
P3MDOUT_B2__OPEN_DRAIN EQU 000H ; P3.2 output is open-drain.
P3MDOUT_B2__PUSH_PULL  EQU 004H ; P3.2 output is push-pull. 
                                                            
P3MDOUT_B3__BMASK      EQU 008H ; Port 3 Bit 3 Output Mode  
P3MDOUT_B3__SHIFT      EQU 003H ; Port 3 Bit 3 Output Mode  
P3MDOUT_B3__OPEN_DRAIN EQU 000H ; P3.3 output is open-drain.
P3MDOUT_B3__PUSH_PULL  EQU 008H ; P3.3 output is push-pull. 
                                                            
P3MDOUT_B4__BMASK      EQU 010H ; Port 3 Bit 4 Output Mode  
P3MDOUT_B4__SHIFT      EQU 004H ; Port 3 Bit 4 Output Mode  
P3MDOUT_B4__OPEN_DRAIN EQU 000H ; P3.4 output is open-drain.
P3MDOUT_B4__PUSH_PULL  EQU 010H ; P3.4 output is push-pull. 
                                                            
P3MDOUT_B5__BMASK      EQU 020H ; Port 3 Bit 5 Output Mode  
P3MDOUT_B5__SHIFT      EQU 005H ; Port 3 Bit 5 Output Mode  
P3MDOUT_B5__OPEN_DRAIN EQU 000H ; P3.5 output is open-drain.
P3MDOUT_B5__PUSH_PULL  EQU 020H ; P3.5 output is push-pull. 
                                                            
P3MDOUT_B6__BMASK      EQU 040H ; Port 3 Bit 6 Output Mode  
P3MDOUT_B6__SHIFT      EQU 006H ; Port 3 Bit 6 Output Mode  
P3MDOUT_B6__OPEN_DRAIN EQU 000H ; P3.6 output is open-drain.
P3MDOUT_B6__PUSH_PULL  EQU 040H ; P3.6 output is push-pull. 
                                                            
P3MDOUT_B7__BMASK      EQU 080H ; Port 3 Bit 7 Output Mode  
P3MDOUT_B7__SHIFT      EQU 007H ; Port 3 Bit 7 Output Mode  
P3MDOUT_B7__OPEN_DRAIN EQU 000H ; P3.7 output is open-drain.
P3MDOUT_B7__PUSH_PULL  EQU 080H ; P3.7 output is push-pull. 
                                                            
;------------------------------------------------------------------------------
; P4 Enums (Port 4 Pin Latch @ 0xE2)
;------------------------------------------------------------------------------
P4_B0__BMASK EQU 001H ; Port 4 Bit 0 Latch                            
P4_B0__SHIFT EQU 000H ; Port 4 Bit 0 Latch                            
P4_B0__LOW   EQU 000H ; P4.0 is low. Set P4.0 to drive low.           
P4_B0__HIGH  EQU 001H ; P4.0 is high. Set P4.0 to drive or float high.
                                                                      
P4_B1__BMASK EQU 002H ; Port 4 Bit 1 Latch                            
P4_B1__SHIFT EQU 001H ; Port 4 Bit 1 Latch                            
P4_B1__LOW   EQU 000H ; P4.1 is low. Set P4.1 to drive low.           
P4_B1__HIGH  EQU 002H ; P4.1 is high. Set P4.1 to drive or float high.
                                                                      
P4_B2__BMASK EQU 004H ; Port 4 Bit 2 Latch                            
P4_B2__SHIFT EQU 002H ; Port 4 Bit 2 Latch                            
P4_B2__LOW   EQU 000H ; P4.2 is low. Set P4.2 to drive low.           
P4_B2__HIGH  EQU 004H ; P4.2 is high. Set P4.2 to drive or float high.
                                                                      
P4_B3__BMASK EQU 008H ; Port 4 Bit 3 Latch                            
P4_B3__SHIFT EQU 003H ; Port 4 Bit 3 Latch                            
P4_B3__LOW   EQU 000H ; P4.3 is low. Set P4.3 to drive low.           
P4_B3__HIGH  EQU 008H ; P4.3 is high. Set P4.3 to drive or float high.
                                                                      
P4_B4__BMASK EQU 010H ; Port 4 Bit 4 Latch                            
P4_B4__SHIFT EQU 004H ; Port 4 Bit 4 Latch                            
P4_B4__LOW   EQU 000H ; P4.4 is low. Set P4.4 to drive low.           
P4_B4__HIGH  EQU 010H ; P4.4 is high. Set P4.4 to drive or float high.
                                                                      
P4_B5__BMASK EQU 020H ; Port 4 Bit 5 Latch                            
P4_B5__SHIFT EQU 005H ; Port 4 Bit 5 Latch                            
P4_B5__LOW   EQU 000H ; P4.5 is low. Set P4.5 to drive low.           
P4_B5__HIGH  EQU 020H ; P4.5 is high. Set P4.5 to drive or float high.
                                                                      
P4_B6__BMASK EQU 040H ; Port 4 Bit 6 Latch                            
P4_B6__SHIFT EQU 006H ; Port 4 Bit 6 Latch                            
P4_B6__LOW   EQU 000H ; P4.6 is low. Set P4.6 to drive low.           
P4_B6__HIGH  EQU 040H ; P4.6 is high. Set P4.6 to drive or float high.
                                                                      
P4_B7__BMASK EQU 080H ; Port 4 Bit 7 Latch                            
P4_B7__SHIFT EQU 007H ; Port 4 Bit 7 Latch                            
P4_B7__LOW   EQU 000H ; P4.7 is low. Set P4.7 to drive low.           
P4_B7__HIGH  EQU 080H ; P4.7 is high. Set P4.7 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P4DRV Enums (Port 4 Drive Strength @ 0xB9)
;------------------------------------------------------------------------------
P4DRV_B0__BMASK      EQU 001H ; Port 4 Bit 0 Drive Strength                
P4DRV_B0__SHIFT      EQU 000H ; Port 4 Bit 0 Drive Strength                
P4DRV_B0__LOW_DRIVE  EQU 000H ; P4.0 output has low output drive strength. 
P4DRV_B0__HIGH_DRIVE EQU 001H ; P4.0 output has high output drive strength.
                                                                           
P4DRV_B1__BMASK      EQU 002H ; Port 4 Bit 1 Drive Strength                
P4DRV_B1__SHIFT      EQU 001H ; Port 4 Bit 1 Drive Strength                
P4DRV_B1__LOW_DRIVE  EQU 000H ; P4.1 output has low output drive strength. 
P4DRV_B1__HIGH_DRIVE EQU 002H ; P4.1 output has high output drive strength.
                                                                           
P4DRV_B2__BMASK      EQU 004H ; Port 4 Bit 2 Drive Strength                
P4DRV_B2__SHIFT      EQU 002H ; Port 4 Bit 2 Drive Strength                
P4DRV_B2__LOW_DRIVE  EQU 000H ; P4.2 output has low output drive strength. 
P4DRV_B2__HIGH_DRIVE EQU 004H ; P4.2 output has high output drive strength.
                                                                           
P4DRV_B3__BMASK      EQU 008H ; Port 4 Bit 3 Drive Strength                
P4DRV_B3__SHIFT      EQU 003H ; Port 4 Bit 3 Drive Strength                
P4DRV_B3__LOW_DRIVE  EQU 000H ; P4.3 output has low output drive strength. 
P4DRV_B3__HIGH_DRIVE EQU 008H ; P4.3 output has high output drive strength.
                                                                           
P4DRV_B4__BMASK      EQU 010H ; Port 4 Bit 4 Drive Strength                
P4DRV_B4__SHIFT      EQU 004H ; Port 4 Bit 4 Drive Strength                
P4DRV_B4__LOW_DRIVE  EQU 000H ; P4.4 output has low output drive strength. 
P4DRV_B4__HIGH_DRIVE EQU 010H ; P4.4 output has high output drive strength.
                                                                           
P4DRV_B5__BMASK      EQU 020H ; Port 4 Bit 5 Drive Strength                
P4DRV_B5__SHIFT      EQU 005H ; Port 4 Bit 5 Drive Strength                
P4DRV_B5__LOW_DRIVE  EQU 000H ; P4.5 output has low output drive strength. 
P4DRV_B5__HIGH_DRIVE EQU 020H ; P4.5 output has high output drive strength.
                                                                           
P4DRV_B6__BMASK      EQU 040H ; Port 4 Bit 6 Drive Strength                
P4DRV_B6__SHIFT      EQU 006H ; Port 4 Bit 6 Drive Strength                
P4DRV_B6__LOW_DRIVE  EQU 000H ; P4.6 output has low output drive strength. 
P4DRV_B6__HIGH_DRIVE EQU 040H ; P4.6 output has high output drive strength.
                                                                           
P4DRV_B7__BMASK      EQU 080H ; Port 4 Bit 7 Drive Strength                
P4DRV_B7__SHIFT      EQU 007H ; Port 4 Bit 7 Drive Strength                
P4DRV_B7__LOW_DRIVE  EQU 000H ; P4.7 output has low output drive strength. 
P4DRV_B7__HIGH_DRIVE EQU 080H ; P4.7 output has high output drive strength.
                                                                           
;------------------------------------------------------------------------------
; P4MDIN Enums (Port 4 Input Mode @ 0xF1)
;------------------------------------------------------------------------------
P4MDIN_B0__BMASK   EQU 001H ; Port 4 Bit 0 Input Mode                 
P4MDIN_B0__SHIFT   EQU 000H ; Port 4 Bit 0 Input Mode                 
P4MDIN_B0__ANALOG  EQU 000H ; P4.0 pin is configured for analog mode. 
P4MDIN_B0__DIGITAL EQU 001H ; P4.0 pin is configured for digital mode.
                                                                      
P4MDIN_B1__BMASK   EQU 002H ; Port 4 Bit 1 Input Mode                 
P4MDIN_B1__SHIFT   EQU 001H ; Port 4 Bit 1 Input Mode                 
P4MDIN_B1__ANALOG  EQU 000H ; P4.1 pin is configured for analog mode. 
P4MDIN_B1__DIGITAL EQU 002H ; P4.1 pin is configured for digital mode.
                                                                      
P4MDIN_B2__BMASK   EQU 004H ; Port 4 Bit 2 Input Mode                 
P4MDIN_B2__SHIFT   EQU 002H ; Port 4 Bit 2 Input Mode                 
P4MDIN_B2__ANALOG  EQU 000H ; P4.2 pin is configured for analog mode. 
P4MDIN_B2__DIGITAL EQU 004H ; P4.2 pin is configured for digital mode.
                                                                      
P4MDIN_B3__BMASK   EQU 008H ; Port 4 Bit 3 Input Mode                 
P4MDIN_B3__SHIFT   EQU 003H ; Port 4 Bit 3 Input Mode                 
P4MDIN_B3__ANALOG  EQU 000H ; P4.3 pin is configured for analog mode. 
P4MDIN_B3__DIGITAL EQU 008H ; P4.3 pin is configured for digital mode.
                                                                      
P4MDIN_B4__BMASK   EQU 010H ; Port 4 Bit 4 Input Mode                 
P4MDIN_B4__SHIFT   EQU 004H ; Port 4 Bit 4 Input Mode                 
P4MDIN_B4__ANALOG  EQU 000H ; P4.4 pin is configured for analog mode. 
P4MDIN_B4__DIGITAL EQU 010H ; P4.4 pin is configured for digital mode.
                                                                      
P4MDIN_B5__BMASK   EQU 020H ; Port 4 Bit 5 Input Mode                 
P4MDIN_B5__SHIFT   EQU 005H ; Port 4 Bit 5 Input Mode                 
P4MDIN_B5__ANALOG  EQU 000H ; P4.5 pin is configured for analog mode. 
P4MDIN_B5__DIGITAL EQU 020H ; P4.5 pin is configured for digital mode.
                                                                      
P4MDIN_B6__BMASK   EQU 040H ; Port 4 Bit 6 Input Mode                 
P4MDIN_B6__SHIFT   EQU 006H ; Port 4 Bit 6 Input Mode                 
P4MDIN_B6__ANALOG  EQU 000H ; P4.6 pin is configured for analog mode. 
P4MDIN_B6__DIGITAL EQU 040H ; P4.6 pin is configured for digital mode.
                                                                      
P4MDIN_B7__BMASK   EQU 080H ; Port 4 Bit 7 Input Mode                 
P4MDIN_B7__SHIFT   EQU 007H ; Port 4 Bit 7 Input Mode                 
P4MDIN_B7__ANALOG  EQU 000H ; P4.7 pin is configured for analog mode. 
P4MDIN_B7__DIGITAL EQU 080H ; P4.7 pin is configured for digital mode.
                                                                      
;------------------------------------------------------------------------------
; P4MDOUT Enums (Port 4 Output Mode @ 0xC3)
;------------------------------------------------------------------------------
P4MDOUT_B0__BMASK      EQU 001H ; Port 4 Bit 0 Output Mode  
P4MDOUT_B0__SHIFT      EQU 000H ; Port 4 Bit 0 Output Mode  
P4MDOUT_B0__OPEN_DRAIN EQU 000H ; P4.0 output is open-drain.
P4MDOUT_B0__PUSH_PULL  EQU 001H ; P4.0 output is push-pull. 
                                                            
P4MDOUT_B1__BMASK      EQU 002H ; Port 4 Bit 1 Output Mode  
P4MDOUT_B1__SHIFT      EQU 001H ; Port 4 Bit 1 Output Mode  
P4MDOUT_B1__OPEN_DRAIN EQU 000H ; P4.1 output is open-drain.
P4MDOUT_B1__PUSH_PULL  EQU 002H ; P4.1 output is push-pull. 
                                                            
P4MDOUT_B2__BMASK      EQU 004H ; Port 4 Bit 2 Output Mode  
P4MDOUT_B2__SHIFT      EQU 002H ; Port 4 Bit 2 Output Mode  
P4MDOUT_B2__OPEN_DRAIN EQU 000H ; P4.2 output is open-drain.
P4MDOUT_B2__PUSH_PULL  EQU 004H ; P4.2 output is push-pull. 
                                                            
P4MDOUT_B3__BMASK      EQU 008H ; Port 4 Bit 3 Output Mode  
P4MDOUT_B3__SHIFT      EQU 003H ; Port 4 Bit 3 Output Mode  
P4MDOUT_B3__OPEN_DRAIN EQU 000H ; P4.3 output is open-drain.
P4MDOUT_B3__PUSH_PULL  EQU 008H ; P4.3 output is push-pull. 
                                                            
P4MDOUT_B4__BMASK      EQU 010H ; Port 4 Bit 4 Output Mode  
P4MDOUT_B4__SHIFT      EQU 004H ; Port 4 Bit 4 Output Mode  
P4MDOUT_B4__OPEN_DRAIN EQU 000H ; P4.4 output is open-drain.
P4MDOUT_B4__PUSH_PULL  EQU 010H ; P4.4 output is push-pull. 
                                                            
P4MDOUT_B5__BMASK      EQU 020H ; Port 4 Bit 5 Output Mode  
P4MDOUT_B5__SHIFT      EQU 005H ; Port 4 Bit 5 Output Mode  
P4MDOUT_B5__OPEN_DRAIN EQU 000H ; P4.5 output is open-drain.
P4MDOUT_B5__PUSH_PULL  EQU 020H ; P4.5 output is push-pull. 
                                                            
P4MDOUT_B6__BMASK      EQU 040H ; Port 4 Bit 6 Output Mode  
P4MDOUT_B6__SHIFT      EQU 006H ; Port 4 Bit 6 Output Mode  
P4MDOUT_B6__OPEN_DRAIN EQU 000H ; P4.6 output is open-drain.
P4MDOUT_B6__PUSH_PULL  EQU 040H ; P4.6 output is push-pull. 
                                                            
P4MDOUT_B7__BMASK      EQU 080H ; Port 4 Bit 7 Output Mode  
P4MDOUT_B7__SHIFT      EQU 007H ; Port 4 Bit 7 Output Mode  
P4MDOUT_B7__OPEN_DRAIN EQU 000H ; P4.7 output is open-drain.
P4MDOUT_B7__PUSH_PULL  EQU 080H ; P4.7 output is push-pull. 
                                                            
;------------------------------------------------------------------------------
; P5 Enums (Port 5 Pin Latch @ 0xE3)
;------------------------------------------------------------------------------
P5_B0__BMASK EQU 001H ; Port 5 Bit 0 Latch                            
P5_B0__SHIFT EQU 000H ; Port 5 Bit 0 Latch                            
P5_B0__LOW   EQU 000H ; P5.0 is low. Set P5.0 to drive low.           
P5_B0__HIGH  EQU 001H ; P5.0 is high. Set P5.0 to drive or float high.
                                                                      
P5_B1__BMASK EQU 002H ; Port 5 Bit 1 Latch                            
P5_B1__SHIFT EQU 001H ; Port 5 Bit 1 Latch                            
P5_B1__LOW   EQU 000H ; P5.1 is low. Set P5.1 to drive low.           
P5_B1__HIGH  EQU 002H ; P5.1 is high. Set P5.1 to drive or float high.
                                                                      
P5_B2__BMASK EQU 004H ; Port 5 Bit 2 Latch                            
P5_B2__SHIFT EQU 002H ; Port 5 Bit 2 Latch                            
P5_B2__LOW   EQU 000H ; P5.2 is low. Set P5.2 to drive low.           
P5_B2__HIGH  EQU 004H ; P5.2 is high. Set P5.2 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P5DRV Enums (Port 5 Drive Strength @ 0x9D)
;------------------------------------------------------------------------------
P5DRV_B0__BMASK      EQU 001H ; Port 5 Bit 0 Drive Strength                
P5DRV_B0__SHIFT      EQU 000H ; Port 5 Bit 0 Drive Strength                
P5DRV_B0__LOW_DRIVE  EQU 000H ; P5.0 output has low output drive strength. 
P5DRV_B0__HIGH_DRIVE EQU 001H ; P5.0 output has high output drive strength.
                                                                           
P5DRV_B1__BMASK      EQU 002H ; Port 5 Bit 1 Drive Strength                
P5DRV_B1__SHIFT      EQU 001H ; Port 5 Bit 1 Drive Strength                
P5DRV_B1__LOW_DRIVE  EQU 000H ; P5.1 output has low output drive strength. 
P5DRV_B1__HIGH_DRIVE EQU 002H ; P5.1 output has high output drive strength.
                                                                           
P5DRV_B2__BMASK      EQU 004H ; Port 5 Bit 2 Drive Strength                
P5DRV_B2__SHIFT      EQU 002H ; Port 5 Bit 2 Drive Strength                
P5DRV_B2__LOW_DRIVE  EQU 000H ; P5.2 output has low output drive strength. 
P5DRV_B2__HIGH_DRIVE EQU 004H ; P5.2 output has high output drive strength.
                                                                           
;------------------------------------------------------------------------------
; P5MDIN Enums (Port 5 Input Mode @ 0xF2)
;------------------------------------------------------------------------------
P5MDIN_B0__BMASK   EQU 001H ; Port 5 Bit 0 Input Mode                 
P5MDIN_B0__SHIFT   EQU 000H ; Port 5 Bit 0 Input Mode                 
P5MDIN_B0__ANALOG  EQU 000H ; P5.0 pin is configured for analog mode. 
P5MDIN_B0__DIGITAL EQU 001H ; P5.0 pin is configured for digital mode.
                                                                      
P5MDIN_B1__BMASK   EQU 002H ; Port 5 Bit 1 Input Mode                 
P5MDIN_B1__SHIFT   EQU 001H ; Port 5 Bit 1 Input Mode                 
P5MDIN_B1__ANALOG  EQU 000H ; P5.1 pin is configured for analog mode. 
P5MDIN_B1__DIGITAL EQU 002H ; P5.1 pin is configured for digital mode.
                                                                      
P5MDIN_B2__BMASK   EQU 004H ; Port 5 Bit 2 Input Mode                 
P5MDIN_B2__SHIFT   EQU 002H ; Port 5 Bit 2 Input Mode                 
P5MDIN_B2__ANALOG  EQU 000H ; P5.2 pin is configured for analog mode. 
P5MDIN_B2__DIGITAL EQU 004H ; P5.2 pin is configured for digital mode.
                                                                      
;------------------------------------------------------------------------------
; P5MDOUT Enums (Port 5 Output Mode @ 0xFF)
;------------------------------------------------------------------------------
P5MDOUT_B0__BMASK      EQU 001H ; Port 5 Bit 0 Output Mode  
P5MDOUT_B0__SHIFT      EQU 000H ; Port 5 Bit 0 Output Mode  
P5MDOUT_B0__OPEN_DRAIN EQU 000H ; P5.0 output is open-drain.
P5MDOUT_B0__PUSH_PULL  EQU 001H ; P5.0 output is push-pull. 
                                                            
P5MDOUT_B1__BMASK      EQU 002H ; Port 5 Bit 1 Output Mode  
P5MDOUT_B1__SHIFT      EQU 001H ; Port 5 Bit 1 Output Mode  
P5MDOUT_B1__OPEN_DRAIN EQU 000H ; P5.1 output is open-drain.
P5MDOUT_B1__PUSH_PULL  EQU 002H ; P5.1 output is push-pull. 
                                                            
P5MDOUT_B2__BMASK      EQU 004H ; Port 5 Bit 2 Output Mode  
P5MDOUT_B2__SHIFT      EQU 002H ; Port 5 Bit 2 Output Mode  
P5MDOUT_B2__OPEN_DRAIN EQU 000H ; P5.2 output is open-drain.
P5MDOUT_B2__PUSH_PULL  EQU 004H ; P5.2 output is push-pull. 
                                                            
;------------------------------------------------------------------------------
; P6 Enums (Port 6 Pin Latch @ 0xE4)
;------------------------------------------------------------------------------
P6_B0__BMASK EQU 001H ; Port 6 Bit 0 Latch                            
P6_B0__SHIFT EQU 000H ; Port 6 Bit 0 Latch                            
P6_B0__LOW   EQU 000H ; P6.0 is low. Set P6.0 to drive low.           
P6_B0__HIGH  EQU 001H ; P6.0 is high. Set P6.0 to drive or float high.
                                                                      
P6_B1__BMASK EQU 002H ; Port 6 Bit 1 Latch                            
P6_B1__SHIFT EQU 001H ; Port 6 Bit 1 Latch                            
P6_B1__LOW   EQU 000H ; P6.1 is low. Set P6.1 to drive low.           
P6_B1__HIGH  EQU 002H ; P6.1 is high. Set P6.1 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P6MDIN Enums (Port 6 Input Mode @ 0x97)
;------------------------------------------------------------------------------
P6MDIN_B0__BMASK   EQU 001H ; Port 6 Bit 0 Input Mode                 
P6MDIN_B0__SHIFT   EQU 000H ; Port 6 Bit 0 Input Mode                 
P6MDIN_B0__ANALOG  EQU 000H ; P6.0 pin is configured for analog mode. 
P6MDIN_B0__DIGITAL EQU 001H ; P6.0 pin is configured for digital mode.
                                                                      
P6MDIN_B1__BMASK   EQU 002H ; Port 6 Bit 1 Input Mode                 
P6MDIN_B1__SHIFT   EQU 001H ; Port 6 Bit 1 Input Mode                 
P6MDIN_B1__ANALOG  EQU 000H ; P6.1 pin is configured for analog mode. 
P6MDIN_B1__DIGITAL EQU 002H ; P6.1 pin is configured for digital mode.
                                                                      
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
; RTC0ADR Enums (RTC Address @ 0xAC)
;------------------------------------------------------------------------------
RTC0ADR_ADDR__FMASK      EQU 00FH ; RTC Indirect Register Address                     
RTC0ADR_ADDR__SHIFT      EQU 000H ; RTC Indirect Register Address                     
RTC0ADR_ADDR__CAPTURE0   EQU 000H ; Select the CAPTURE0 register.                     
RTC0ADR_ADDR__CAPTURE1   EQU 001H ; Select the CAPTURE1 register.                     
RTC0ADR_ADDR__CAPTURE2   EQU 002H ; Select the CAPTURE2 register.                     
RTC0ADR_ADDR__CAPTURE3   EQU 003H ; Select the CAPTURE3 register.                     
RTC0ADR_ADDR__RTC0CN     EQU 004H ; Select the RTC0CN register.                       
RTC0ADR_ADDR__RTC0XCN    EQU 005H ; Select the RTC0XCN register.                      
RTC0ADR_ADDR__RTC0XCF    EQU 006H ; Select the RTC0XCF register.                      
RTC0ADR_ADDR__ALARM0     EQU 008H ; Select the ALARM0 register.                       
RTC0ADR_ADDR__ALARM1     EQU 009H ; Select the ALARM1 register.                       
RTC0ADR_ADDR__ALARM2     EQU 00AH ; Select the ALARM2 register.                       
RTC0ADR_ADDR__ALARM3     EQU 00BH ; Select the ALARM3 register.                       
                                                                                      
RTC0ADR_SHORT__BMASK     EQU 010H ; Short Strobe Enable                               
RTC0ADR_SHORT__SHIFT     EQU 004H ; Short Strobe Enable                               
RTC0ADR_SHORT__DISABLED  EQU 000H ; Disable short strobe.                             
RTC0ADR_SHORT__ENABLED   EQU 010H ; Enable short strobe.                              
                                                                                      
RTC0ADR_AUTORD__BMASK    EQU 040H ; RTC Interface Autoread Enable                     
RTC0ADR_AUTORD__SHIFT    EQU 006H ; RTC Interface Autoread Enable                     
RTC0ADR_AUTORD__DISABLED EQU 000H ; Disable autoread. Firmware must write the BUSY bit
                                  ; for each RTC indirect read operation.             
RTC0ADR_AUTORD__ENABLED  EQU 040H ; Enable autoread. The next RTC indirect read       
                                  ; operation is initiated when firmware reads the    
                                  ; RTC0DAT register.                                 
                                                                                      
RTC0ADR_BUSY__BMASK      EQU 080H ; RTC Interface Busy Indicator                      
RTC0ADR_BUSY__SHIFT      EQU 007H ; RTC Interface Busy Indicator                      
RTC0ADR_BUSY__NOT_SET    EQU 000H ; The RTC interface is not busy.                    
RTC0ADR_BUSY__SET        EQU 080H ; The RTC interface is busy.                        
                                                                                      
;------------------------------------------------------------------------------
; RTC0CN Enums (RTC Control @ 0x04)
;------------------------------------------------------------------------------
RTC0CN_RTC0CAP__BMASK    EQU 001H ; RTC Timer Capture                               
RTC0CN_RTC0CAP__SHIFT    EQU 000H ; RTC Timer Capture                               
RTC0CN_RTC0CAP__NOT_SET  EQU 000H ; Do not start a capture operation.               
RTC0CN_RTC0CAP__SET      EQU 001H ; Start a capture operation.                      
                                                                                    
RTC0CN_RTC0SET__BMASK    EQU 002H ; RTC Timer Set                                   
RTC0CN_RTC0SET__SHIFT    EQU 001H ; RTC Timer Set                                   
RTC0CN_RTC0SET__NOT_SET  EQU 000H ; Do not start a set operation.                   
RTC0CN_RTC0SET__SET      EQU 002H ; Start a set operation.                          
                                                                                    
RTC0CN_ALRM__BMASK       EQU 004H ; RTC Alarm Event Flag and Auto Reset Enable      
RTC0CN_ALRM__SHIFT       EQU 002H ; RTC Alarm Event Flag and Auto Reset Enable      
RTC0CN_ALRM__NOT_SET     EQU 000H ; Alarm event flag is not set or disable the auto 
                                  ; reset function.                                 
RTC0CN_ALRM__SET         EQU 004H ; Alarm event flag is set or enable the auto reset
                                  ; function.                                       
                                                                                    
RTC0CN_RTC0AEN__BMASK    EQU 008H ; RTC Alarm Enable                                
RTC0CN_RTC0AEN__SHIFT    EQU 003H ; RTC Alarm Enable                                
RTC0CN_RTC0AEN__DISABLED EQU 000H ; Disable RTC alarm.                              
RTC0CN_RTC0AEN__ENABLED  EQU 008H ; Enable RTC alarm.                               
                                                                                    
RTC0CN_RTC0TR__BMASK     EQU 010H ; RTC Timer Run Control                           
RTC0CN_RTC0TR__SHIFT     EQU 004H ; RTC Timer Run Control                           
RTC0CN_RTC0TR__STOP      EQU 000H ; RTC timer is stopped.                           
RTC0CN_RTC0TR__RUN       EQU 010H ; RTC timer is running.                           
                                                                                    
RTC0CN_OSCFAIL__BMASK    EQU 020H ; RTC Oscillator Fail Event Flag                  
RTC0CN_OSCFAIL__SHIFT    EQU 005H ; RTC Oscillator Fail Event Flag                  
RTC0CN_OSCFAIL__NOT_SET  EQU 000H ; Missing RTC detector timeout did not occur.     
RTC0CN_OSCFAIL__SET      EQU 020H ; Missing RTC detector timeout occurred.          
                                                                                    
RTC0CN_MCLKEN__BMASK     EQU 040H ; Missing RTC Detector Enable                     
RTC0CN_MCLKEN__SHIFT     EQU 006H ; Missing RTC Detector Enable                     
RTC0CN_MCLKEN__DISABLED  EQU 000H ; Disable missing RTC detector.                   
RTC0CN_MCLKEN__ENABLED   EQU 040H ; Enable missing RTC detector.                    
                                                                                    
RTC0CN_RTC0EN__BMASK     EQU 080H ; RTC Enable                                      
RTC0CN_RTC0EN__SHIFT     EQU 007H ; RTC Enable                                      
RTC0CN_RTC0EN__DISABLED  EQU 000H ; Disable RTC oscillator.                         
RTC0CN_RTC0EN__ENABLED   EQU 080H ; Enable RTC oscillator.                          
                                                                                    
;------------------------------------------------------------------------------
; RTC0DAT Enums (RTC Data @ 0xAD)
;------------------------------------------------------------------------------
RTC0DAT_RTC0DAT__FMASK EQU 0FFH ; RTC Data
RTC0DAT_RTC0DAT__SHIFT EQU 000H ; RTC Data
                                          
;------------------------------------------------------------------------------
; RTC0XCF Enums (RTC Oscillator Configuration @ 0x06)
;------------------------------------------------------------------------------
RTC0XCF_LOADCAP__FMASK    EQU 00FH ; Load Capacitance Programmed Value                
RTC0XCF_LOADCAP__SHIFT    EQU 000H ; Load Capacitance Programmed Value                
                                                                                      
RTC0XCF_LOADRDY__BMASK    EQU 040H ; Load Capacitance Ready Indicator                 
RTC0XCF_LOADRDY__SHIFT    EQU 006H ; Load Capacitance Ready Indicator                 
RTC0XCF_LOADRDY__NOT_SET  EQU 000H ; Load capacitance is currently stepping.          
RTC0XCF_LOADRDY__SET      EQU 040H ; Load capacitance has reached it programmed value.
                                                                                      
RTC0XCF_AUTOSTP__BMASK    EQU 080H ; Automatic Load Capacitance Stepping Enable       
RTC0XCF_AUTOSTP__SHIFT    EQU 007H ; Automatic Load Capacitance Stepping Enable       
RTC0XCF_AUTOSTP__DISABLED EQU 000H ; Disable load capacitance stepping.               
RTC0XCF_AUTOSTP__ENABLED  EQU 080H ; Enable load capacitance stepping.                
                                                                                      
;------------------------------------------------------------------------------
; RTC0XCN Enums (RTC Oscillator Control @ 0x05)
;------------------------------------------------------------------------------
RTC0XCN_LFOEN__BMASK          EQU 008H ; Low Frequency Oscillator Enable and Select        
RTC0XCN_LFOEN__SHIFT          EQU 003H ; Low Frequency Oscillator Enable and Select        
RTC0XCN_LFOEN__DISABLED       EQU 000H ; XMODE determines RTC oscillator source.           
RTC0XCN_LFOEN__ENABLED        EQU 008H ; LFOSC enabled and selected as RTC oscillator      
                                       ; source.                                           
                                                                                           
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
; SMB0ADM Enums (SMBus 0 Slave Address Mask @ 0xF5)
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
; SMB0ADR Enums (SMBus 0 Slave Address @ 0xF4)
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
; TOFFH Enums (Temperature Sensor Offset High @ 0x8E)
;------------------------------------------------------------------------------
TOFFH_TOFF__FMASK EQU 0FFH ; Temperature Sensor Offset High
TOFFH_TOFF__SHIFT EQU 000H ; Temperature Sensor Offset High
                                                           
;------------------------------------------------------------------------------
; TOFFL Enums (Temperature Sensor Offset Low @ 0x8D)
;------------------------------------------------------------------------------
TOFFL_TOFF__FMASK EQU 0C0H ; Temperature Sensor Offset Low
TOFFL_TOFF__SHIFT EQU 006H ; Temperature Sensor Offset Low
                                                          
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
TMR2CN_T2XCLK__FMASK                 EQU 003H ; Timer 2 External Clock Select                    
TMR2CN_T2XCLK__SHIFT                 EQU 000H ; Timer 2 External Clock Select                    
TMR2CN_T2XCLK__SYSCLK_DIV_12_CAP_RTC EQU 000H ; External Clock is SYSCLK/12. Capture trigger is  
                                              ; RTC/8.                                           
TMR2CN_T2XCLK__CAP_RTC               EQU 001H ; Capture trigger is RTC/8.                        
TMR2CN_T2XCLK__SYSCLK_DIV_12         EQU 002H ; External Clock is SYSCLK/12.                     
TMR2CN_T2XCLK__RTC_DIV_8             EQU 003H ; External Clock is RTC/8.                         
                                                                                                 
TMR2CN_TR2__BMASK                    EQU 004H ; Timer 2 Run Control                              
TMR2CN_TR2__SHIFT                    EQU 002H ; Timer 2 Run Control                              
TMR2CN_TR2__STOP                     EQU 000H ; Stop Timer 2.                                    
TMR2CN_TR2__RUN                      EQU 004H ; Start Timer 2 running.                           
                                                                                                 
TMR2CN_T2SPLIT__BMASK                EQU 008H ; Timer 2 Split Mode Enable                        
TMR2CN_T2SPLIT__SHIFT                EQU 003H ; Timer 2 Split Mode Enable                        
TMR2CN_T2SPLIT__16_BIT_RELOAD        EQU 000H ; Timer 2 operates in 16-bit auto-reload mode.     
TMR2CN_T2SPLIT__8_BIT_RELOAD         EQU 008H ; Timer 2 operates as two 8-bit auto-reload timers.
                                                                                                 
TMR2CN_TF2CEN__BMASK                 EQU 010H ; Timer 2 Capture Enable                           
TMR2CN_TF2CEN__SHIFT                 EQU 004H ; Timer 2 Capture Enable                           
TMR2CN_TF2CEN__DISABLED              EQU 000H ; Disable capture mode.                            
TMR2CN_TF2CEN__ENABLED               EQU 010H ; Enable capture mode.                             
                                                                                                 
TMR2CN_TF2LEN__BMASK                 EQU 020H ; Timer 2 Low Byte Interrupt Enable                
TMR2CN_TF2LEN__SHIFT                 EQU 005H ; Timer 2 Low Byte Interrupt Enable                
TMR2CN_TF2LEN__DISABLED              EQU 000H ; Disable low byte interrupts.                     
TMR2CN_TF2LEN__ENABLED               EQU 020H ; Enable low byte interrupts.                      
                                                                                                 
TMR2CN_TF2L__BMASK                   EQU 040H ; Timer 2 Low Byte Overflow Flag                   
TMR2CN_TF2L__SHIFT                   EQU 006H ; Timer 2 Low Byte Overflow Flag                   
TMR2CN_TF2L__NOT_SET                 EQU 000H ; Timer 2 low byte did not overflow.               
TMR2CN_TF2L__SET                     EQU 040H ; Timer 2 low byte overflowed.                     
                                                                                                 
TMR2CN_TF2H__BMASK                   EQU 080H ; Timer 2 High Byte Overflow Flag                  
TMR2CN_TF2H__SHIFT                   EQU 007H ; Timer 2 High Byte Overflow Flag                  
TMR2CN_TF2H__NOT_SET                 EQU 000H ; Timer 2 8-bit high byte or 16-bit value did not  
                                              ; overflow.                                        
TMR2CN_TF2H__SET                     EQU 080H ; Timer 2 8-bit high byte or 16-bit value          
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
TMR3CN_T3XCLK__FMASK                    EQU 003H ; Timer 3 External Clock Select                     
TMR3CN_T3XCLK__SHIFT                    EQU 000H ; Timer 3 External Clock Select                     
TMR3CN_T3XCLK__SYSCLK_DIV_12_CAP_RTC    EQU 000H ; External Clock is SYSCLK/12. Capture trigger is   
                                                 ; RTC.                                              
TMR3CN_T3XCLK__EXTOSC_DIV_8_CAP_RTC     EQU 001H ; External Clock is External Oscillator/8. Capture  
                                                 ; trigger is RTC.                                   
TMR3CN_T3XCLK__SYSCLK_DIV_12_CAP_EXTOSC EQU 002H ; External Clock is SYSCLK/12. Capture trigger is   
                                                 ; External Oscillator/8.                            
TMR3CN_T3XCLK__RTC_CAP_EXTOSC           EQU 003H ; External Clock is RTC. Capture trigger is External
                                                 ; Oscillator/8.                                     
                                                                                                     
TMR3CN_TR3__BMASK                       EQU 004H ; Timer 3 Run Control                               
TMR3CN_TR3__SHIFT                       EQU 002H ; Timer 3 Run Control                               
TMR3CN_TR3__STOP                        EQU 000H ; Stop Timer 3.                                     
TMR3CN_TR3__RUN                         EQU 004H ; Start Timer 3 running.                            
                                                                                                     
TMR3CN_T3SPLIT__BMASK                   EQU 008H ; Timer 3 Split Mode Enable                         
TMR3CN_T3SPLIT__SHIFT                   EQU 003H ; Timer 3 Split Mode Enable                         
TMR3CN_T3SPLIT__16_BIT_RELOAD           EQU 000H ; Timer 3 operates in 16-bit auto-reload mode.      
TMR3CN_T3SPLIT__8_BIT_RELOAD            EQU 008H ; Timer 3 operates as two 8-bit auto-reload timers. 
                                                                                                     
TMR3CN_TF3CEN__BMASK                    EQU 010H ; Timer 3 Capture Enable                            
TMR3CN_TF3CEN__SHIFT                    EQU 004H ; Timer 3 Capture Enable                            
TMR3CN_TF3CEN__DISABLED                 EQU 000H ; Disable capture mode.                             
TMR3CN_TF3CEN__ENABLED                  EQU 010H ; Enable capture mode.                              
                                                                                                     
TMR3CN_TF3LEN__BMASK                    EQU 020H ; Timer 3 Low Byte Interrupt Enable                 
TMR3CN_TF3LEN__SHIFT                    EQU 005H ; Timer 3 Low Byte Interrupt Enable                 
TMR3CN_TF3LEN__DISABLED                 EQU 000H ; Disable low byte interrupts.                      
TMR3CN_TF3LEN__ENABLED                  EQU 020H ; Enable low byte interrupts.                       
                                                                                                     
TMR3CN_TF3L__BMASK                      EQU 040H ; Timer 3 Low Byte Overflow Flag                    
TMR3CN_TF3L__SHIFT                      EQU 006H ; Timer 3 Low Byte Overflow Flag                    
TMR3CN_TF3L__NOT_SET                    EQU 000H ; Timer 3 low byte did not overflow.                
TMR3CN_TF3L__SET                        EQU 040H ; Timer 3 low byte overflowed.                      
                                                                                                     
TMR3CN_TF3H__BMASK                      EQU 080H ; Timer 3 High Byte Overflow Flag                   
TMR3CN_TF3H__SHIFT                      EQU 007H ; Timer 3 High Byte Overflow Flag                   
TMR3CN_TF3H__NOT_SET                    EQU 000H ; Timer 3 8-bit high byte or 16-bit value did not   
                                                 ; overflow.                                         
TMR3CN_TF3H__SET                        EQU 080H ; Timer 3 8-bit high byte or 16-bit value           
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
VDM0CN_VDDOKIE__BMASK           EQU 008H ; VDD Early Warning Interrupt Enable       
VDM0CN_VDDOKIE__SHIFT           EQU 003H ; VDD Early Warning Interrupt Enable       
VDM0CN_VDDOKIE__DISABLED        EQU 000H ; Disable the VDD Early Warning interrupt. 
VDM0CN_VDDOKIE__ENABLED         EQU 008H ; Enable the VDD Early Warning interrupt.  
                                                                                    
VDM0CN_VDDOK__BMASK             EQU 020H ; VDD Supply Status (Early Warning)        
VDM0CN_VDDOK__SHIFT             EQU 005H ; VDD Supply Status (Early Warning)        
VDM0CN_VDDOK__VDD_BELOW_VDDWARN EQU 000H ; VDD is at or below the VDDWARN threshold.
VDM0CN_VDDOK__VDD_ABOVE_VDDWARN EQU 020H ; VDD is above the VDDWARN threshold.      
                                                                                    
VDM0CN_VDDSTAT__BMASK           EQU 040H ; VDD Supply Status                        
VDM0CN_VDDSTAT__SHIFT           EQU 006H ; VDD Supply Status                        
VDM0CN_VDDSTAT__VDD_BELOW_VRST  EQU 000H ; VDD is at or below the VRST threshold.   
VDM0CN_VDDSTAT__VDD_ABOVE_VRST  EQU 040H ; VDD is above the VRST threshold.         
                                                                                    
VDM0CN_VDMEN__BMASK             EQU 080H ; VDD Supply Monitor Enable                
VDM0CN_VDMEN__SHIFT             EQU 007H ; VDD Supply Monitor Enable                
VDM0CN_VDMEN__DISABLED          EQU 000H ; Disable the VDD supply monitor.          
VDM0CN_VDMEN__ENABLED           EQU 080H ; Enable the VDD supply monitor.           
                                                                                    
;------------------------------------------------------------------------------
; REF0CN Enums (Voltage Reference Control @ 0xD1)
;------------------------------------------------------------------------------
REF0CN_TEMPE__BMASK           EQU 004H ; Temperature Sensor Enable                        
REF0CN_TEMPE__SHIFT           EQU 002H ; Temperature Sensor Enable                        
REF0CN_TEMPE__TEMP_DISABLED   EQU 000H ; Disable the Temperature Sensor.                  
REF0CN_TEMPE__TEMP_ENABLED    EQU 004H ; Enable the Temperature Sensor.                   
                                                                                          
REF0CN_REFSL__FMASK           EQU 018H ; Voltage Reference Select                         
REF0CN_REFSL__SHIFT           EQU 003H ; Voltage Reference Select                         
REF0CN_REFSL__VREF_PIN        EQU 000H ; The ADC0 voltage reference is the P0.0/VREF pin. 
REF0CN_REFSL__VDD_PIN         EQU 008H ; The ADC0 voltage reference is the VDD pin.       
REF0CN_REFSL__INTERNAL_LDO    EQU 010H ; The ADC0 voltage reference is the internal 1.8 V 
                                       ; digital supply voltage.                          
REF0CN_REFSL__HIGH_SPEED_VREF EQU 018H ; The ADC0 voltage reference is the internal 1.65 V
                                       ; high speed voltage reference.                    
                                                                                          
;------------------------------------------------------------------------------
; REG0CN Enums (Voltage Regulator Control @ 0xC9)
;------------------------------------------------------------------------------
REG0CN_OSCBIAS__BMASK    EQU 010H ; High Frequency Oscillator Bias                 
REG0CN_OSCBIAS__SHIFT    EQU 004H ; High Frequency Oscillator Bias                 
REG0CN_OSCBIAS__DISABLED EQU 000H ; Disable the precision High Frequency Oscillator
                                  ; bias.                                          
REG0CN_OSCBIAS__ENABLED  EQU 010H ; Enable the precision High Frequency Oscillator 
                                  ; bias.                                          
                                                                                   
;------------------------------------------------------------------------------
; EMI0CN Enums (External Memory Interface Control @ 0xB9)
;------------------------------------------------------------------------------
EMI0CN_PGSEL__FMASK EQU 0FFH ; XRAM Page Select
EMI0CN_PGSEL__SHIFT EQU 000H ; XRAM Page Select
                                               
