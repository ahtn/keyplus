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

;------------------------------------------------------------------------------
; ADC2 Enums (ADC2 Data Word @ 0xBE)
;------------------------------------------------------------------------------
ADC2_ADC2H__FMASK EQU 0FFH ; Data Word
ADC2_ADC2H__SHIFT EQU 000H ; Data Word
                                      
;------------------------------------------------------------------------------
; ADC2CF Enums (ADC2 Configuration @ 0xBC)
;------------------------------------------------------------------------------
ADC2CF_AMP2GN__FMASK    EQU 003H ; ADC2 Internal Amplifier Gain (PGA)
ADC2CF_AMP2GN__SHIFT    EQU 000H ; ADC2 Internal Amplifier Gain (PGA)
ADC2CF_AMP2GN__GAIN_0P5 EQU 000H ; The on-chip PGA gain is 0.5.      
ADC2CF_AMP2GN__GAIN_1   EQU 001H ; The on-chip PGA gain is 1.        
ADC2CF_AMP2GN__GAIN_2   EQU 002H ; The on-chip PGA gain is 2.        
ADC2CF_AMP2GN__GAIN_4   EQU 003H ; The on-chip PGA gain is 4.        
                                                                     
ADC2CF_AD2SC__FMASK     EQU 0F8H ; SAR Clock Divider                 
ADC2CF_AD2SC__SHIFT     EQU 003H ; SAR Clock Divider                 
                                                                     
;------------------------------------------------------------------------------
; ADC2CN Enums (ADC2 Control @ 0xE8)
;------------------------------------------------------------------------------
ADC2CN_ADWINT__BMASK     EQU 001H ; Window Compare Interrupt Flag                     
ADC2CN_ADWINT__SHIFT     EQU 000H ; Window Compare Interrupt Flag                     
ADC2CN_ADWINT__NOT_SET   EQU 000H ; An ADC window compare event did not occur.        
ADC2CN_ADWINT__SET       EQU 001H ; An ADC window compare event occurred.             
                                                                                      
ADC2CN_ADCM__FMASK       EQU 00EH ; Start of Conversion Mode Select                   
ADC2CN_ADCM__SHIFT       EQU 001H ; Start of Conversion Mode Select                   
ADC2CN_ADCM__ADBUSY      EQU 000H ; ADC2 conversion initiated on write of 1 to ADBUSY.
ADC2CN_ADCM__TIMER3      EQU 002H ; ADC2 conversion initiated on overflow of Timer 3. 
ADC2CN_ADCM__CNVSTR      EQU 004H ; ADC2 conversion initiated on rising edge of       
                                  ; CNVSTR0.                                          
ADC2CN_ADCM__TIMER2      EQU 006H ; ADC2 conversion initiated on overflow of Timer 2. 
ADC2CN_ADCM__ADC0_ADBUSY EQU 008H ; ADC2 conversion initiated on write of 1 to ADC0's 
                                  ; ADBUSY.                                           
                                                                                      
ADC2CN_ADBUSY__BMASK     EQU 010H ; ADC Busy                                          
ADC2CN_ADBUSY__SHIFT     EQU 004H ; ADC Busy                                          
ADC2CN_ADBUSY__NOT_SET   EQU 000H ; An ADC2 conversion is not currently in progress.  
ADC2CN_ADBUSY__SET       EQU 010H ; ADC2 conversion is in progress or start an ADC2   
                                  ; conversion.                                       
                                                                                      
ADC2CN_ADINT__BMASK      EQU 020H ; Conversion Complete Interrupt Flag                
ADC2CN_ADINT__SHIFT      EQU 005H ; Conversion Complete Interrupt Flag                
ADC2CN_ADINT__NOT_SET    EQU 000H ; ADC2 has not completed a conversion since the last
                                  ; time ADINT was cleared.                           
ADC2CN_ADINT__SET        EQU 020H ; ADC2 completed a data conversion.                 
                                                                                      
ADC2CN_ADTM__BMASK       EQU 040H ; ADC Track Mode                                    
ADC2CN_ADTM__SHIFT       EQU 006H ; ADC Track Mode                                    
ADC2CN_ADTM__CONTINUOUS  EQU 000H ; When the ADC is enabled, tracking is continuous   
                                  ; unless a conversion is in process.                
ADC2CN_ADTM__ADJUSTABLE  EQU 040H ; Tracking defined by the ADCM field.               
                                                                                      
ADC2CN_ADEN__BMASK       EQU 080H ; ADC Enable                                        
ADC2CN_ADEN__SHIFT       EQU 007H ; ADC Enable                                        
ADC2CN_ADEN__DISABLED    EQU 000H ; Disable ADC2 (low-power shutdown).                
ADC2CN_ADEN__ENABLED     EQU 080H ; Enable ADC2 (active and ready for data            
                                  ; conversions).                                     
                                                                                      
;------------------------------------------------------------------------------
; ADC2GT Enums (ADC2 Greater-Than Data Byte @ 0xC4)
;------------------------------------------------------------------------------
ADC2GT_ADC2GTH__FMASK EQU 0FFH ; Greater-Than Byte
ADC2GT_ADC2GTH__SHIFT EQU 000H ; Greater-Than Byte
                                                  
;------------------------------------------------------------------------------
; ADC2LT Enums (ADC2 Less-Than Data Byte @ 0xC6)
;------------------------------------------------------------------------------
ADC2LT_ADC2LTH__FMASK EQU 0FFH ; Less-Than Data Byte
ADC2LT_ADC2LTH__SHIFT EQU 000H ; Less-Than Data Byte
                                                    
;------------------------------------------------------------------------------
; AMX2CF Enums (AMUX2 Configuration @ 0xBA)
;------------------------------------------------------------------------------
AMX2CF_AIN01IC__BMASK        EQU 001H ; AIN2.0, AIN2.1 Input Pair Configuration         
AMX2CF_AIN01IC__SHIFT        EQU 000H ; AIN2.0, AIN2.1 Input Pair Configuration         
AMX2CF_AIN01IC__SINGLE_ENDED EQU 000H ; AIN2.0 and AIN2.1 are independent single-ended  
                                      ; inputs.                                         
AMX2CF_AIN01IC__DIFFERENTIAL EQU 001H ; AIN2.0 and AIN2.1 are a (respectively) positive,
                                      ; negative differential input pair.               
                                                                                        
AMX2CF_AIN23IC__BMASK        EQU 002H ; AIN2.2, AIN2.3 Input Pair Configuration         
AMX2CF_AIN23IC__SHIFT        EQU 001H ; AIN2.2, AIN2.3 Input Pair Configuration         
AMX2CF_AIN23IC__SINGLE_ENDED EQU 000H ; AIN2.2 and AIN2.3 are independent single-ended  
                                      ; inputs.                                         
AMX2CF_AIN23IC__DIFFERENTIAL EQU 002H ; AIN2.2 and AIN2.3 are a (respectively) positive,
                                      ; negative differential input pair.               
                                                                                        
AMX2CF_AIN45IC__BMASK        EQU 004H ; AIN2.4, AIN2.5 Input Pair Configuration         
AMX2CF_AIN45IC__SHIFT        EQU 002H ; AIN2.4, AIN2.5 Input Pair Configuration         
AMX2CF_AIN45IC__SINGLE_ENDED EQU 000H ; AIN2.4 and AIN2.5 are independent single-ended  
                                      ; inputs.                                         
AMX2CF_AIN45IC__DIFFERENTIAL EQU 004H ; AIN2.4 and AIN2.5 are a (respectively) positive,
                                      ; negative differential input pair.               
                                                                                        
AMX2CF_AIN67IC__BMASK        EQU 008H ; AIN2.6, AIN2.7 Input Pair Configuration         
AMX2CF_AIN67IC__SHIFT        EQU 003H ; AIN2.6, AIN2.7 Input Pair Configuration         
AMX2CF_AIN67IC__SINGLE_ENDED EQU 000H ; AIN2.6 and AIN2.7 are independent single-ended  
                                      ; inputs.                                         
AMX2CF_AIN67IC__DIFFERENTIAL EQU 008H ; AIN2.6 and AIN2.7 are a (respectively) positive,
                                      ; negative differential input pair.               
                                                                                        
;------------------------------------------------------------------------------
; AMX2SL Enums (AMUX2 Channel Select @ 0xBB)
;------------------------------------------------------------------------------
AMX2SL_ADC2AD__FMASK  EQU 007H ; ADC2 Input Selection
AMX2SL_ADC2AD__SHIFT  EQU 000H ; ADC2 Input Selection
AMX2SL_ADC2AD__ADC2P0 EQU 000H ; Select ADC2.0.      
AMX2SL_ADC2AD__ADC2P1 EQU 001H ; Select ADC2.1.      
AMX2SL_ADC2AD__ADC2P2 EQU 002H ; Select ADC2.2.      
AMX2SL_ADC2AD__ADC2P3 EQU 003H ; Select ADC2.3.      
AMX2SL_ADC2AD__ADC2P4 EQU 004H ; Select ADC2.4.      
AMX2SL_ADC2AD__ADC2P5 EQU 005H ; Select ADC2.5.      
AMX2SL_ADC2AD__ADC2P6 EQU 006H ; Select ADC2.6.      
AMX2SL_ADC2AD__ADC2P7 EQU 007H ; Select ADC2.7.      
                                                     
;------------------------------------------------------------------------------
; ADC0CF Enums (ADC0 Configuration @ 0xBC)
;------------------------------------------------------------------------------
ADC0CF_AMP0GN__FMASK    EQU 007H ; ADC0 Internal Amplifier Gain (PGA)
ADC0CF_AMP0GN__SHIFT    EQU 000H ; ADC0 Internal Amplifier Gain (PGA)
ADC0CF_AMP0GN__GAIN_1   EQU 000H ; The on-chip PGA gain is 1.        
ADC0CF_AMP0GN__GAIN_2   EQU 001H ; The on-chip PGA gain is 2.        
ADC0CF_AMP0GN__GAIN_4   EQU 002H ; The on-chip PGA gain is 4.        
ADC0CF_AMP0GN__GAIN_8   EQU 003H ; The on-chip PGA gain is 8.        
ADC0CF_AMP0GN__GAIN_16  EQU 004H ; The on-chip PGA gain is 16.       
ADC0CF_AMP0GN__GAIN_0P5 EQU 006H ; The on-chip PGA gain is 0.5.      
                                                                     
ADC0CF_AD0SC__FMASK     EQU 0F8H ; SAR Clock Divider                 
ADC0CF_AD0SC__SHIFT     EQU 003H ; SAR Clock Divider                 
                                                                     
;------------------------------------------------------------------------------
; ADC0CN Enums (ADC0 Control @ 0xE8)
;------------------------------------------------------------------------------
ADC0CN_ADLJST__BMASK           EQU 001H ; ADC Left Justify Select                           
ADC0CN_ADLJST__SHIFT           EQU 000H ; ADC Left Justify Select                           
ADC0CN_ADLJST__RIGHT_JUSTIFIED EQU 000H ; Data in the ADC0H:ADC0L registers is right-       
                                        ; justified.                                        
ADC0CN_ADLJST__LEFT_JUSTIFIED  EQU 001H ; Data in the ADC0H:ADC0L registers is left-        
                                        ; justified.                                        
                                                                                            
ADC0CN_ADWINT__BMASK           EQU 002H ; Window Compare Interrupt Flag                     
ADC0CN_ADWINT__SHIFT           EQU 001H ; Window Compare Interrupt Flag                     
ADC0CN_ADWINT__NOT_SET         EQU 000H ; An ADC window compare event did not occur.        
ADC0CN_ADWINT__SET             EQU 002H ; An ADC window compare event occurred.             
                                                                                            
ADC0CN_ADCM__FMASK             EQU 00CH ; Start of Conversion Mode Select                   
ADC0CN_ADCM__SHIFT             EQU 002H ; Start of Conversion Mode Select                   
ADC0CN_ADCM__ADBUSY            EQU 000H ; ADC0 conversion initiated on write of 1 to ADBUSY.
ADC0CN_ADCM__TIMER3            EQU 004H ; ADC0 conversion initiated on overflow of Timer 3. 
ADC0CN_ADCM__CNVSTR            EQU 008H ; ADC0 conversion initiated on rising edge of       
                                        ; CNVSTR0.                                          
ADC0CN_ADCM__TIMER2            EQU 00CH ; ADC0 conversion initiated on overflow of Timer 2. 
                                                                                            
ADC0CN_ADBUSY__BMASK           EQU 010H ; ADC Busy                                          
ADC0CN_ADBUSY__SHIFT           EQU 004H ; ADC Busy                                          
ADC0CN_ADBUSY__NOT_SET         EQU 000H ; An ADC0 conversion is not currently in progress.  
ADC0CN_ADBUSY__SET             EQU 010H ; ADC0 conversion is in progress or start an ADC0   
                                        ; conversion.                                       
                                                                                            
ADC0CN_ADINT__BMASK            EQU 020H ; Conversion Complete Interrupt Flag                
ADC0CN_ADINT__SHIFT            EQU 005H ; Conversion Complete Interrupt Flag                
ADC0CN_ADINT__NOT_SET          EQU 000H ; ADC0 has not completed a conversion since the last
                                        ; time ADINT was cleared.                           
ADC0CN_ADINT__SET              EQU 020H ; ADC0 completed a data conversion.                 
                                                                                            
ADC0CN_ADTM__BMASK             EQU 040H ; ADC Track Mode                                    
ADC0CN_ADTM__SHIFT             EQU 006H ; ADC Track Mode                                    
ADC0CN_ADTM__CONTINUOUS        EQU 000H ; When the ADC is enabled, tracking is continuous   
                                        ; unless a conversion is in process.                
ADC0CN_ADTM__ADJUSTABLE        EQU 040H ; Tracking defined by the ADCM field.               
                                                                                            
ADC0CN_ADEN__BMASK             EQU 080H ; ADC Enable                                        
ADC0CN_ADEN__SHIFT             EQU 007H ; ADC Enable                                        
ADC0CN_ADEN__DISABLED          EQU 000H ; Disable ADC0 (low-power shutdown).                
ADC0CN_ADEN__ENABLED           EQU 080H ; Enable ADC0 (active and ready for data            
                                        ; conversions).                                     
                                                                                            
;------------------------------------------------------------------------------
; ADC0GTH Enums (ADC0 Greater-Than High Byte @ 0xC5)
;------------------------------------------------------------------------------
ADC0GTH_ADC0GTH__FMASK EQU 0FFH ; Greater-Than High Byte
ADC0GTH_ADC0GTH__SHIFT EQU 000H ; Greater-Than High Byte
                                                        
;------------------------------------------------------------------------------
; ADC0GTL Enums (ADC0 Greater-Than Low Byte @ 0xC4)
;------------------------------------------------------------------------------
ADC0GTL_ADC0GTL__FMASK EQU 0FFH ; Greater-Than Low Byte
ADC0GTL_ADC0GTL__SHIFT EQU 000H ; Greater-Than Low Byte
                                                       
;------------------------------------------------------------------------------
; ADC0H Enums (ADC0 Data Word High Byte @ 0xBF)
;------------------------------------------------------------------------------
ADC0H_ADC0H__FMASK EQU 0FFH ; Data Word High Byte
ADC0H_ADC0H__SHIFT EQU 000H ; Data Word High Byte
                                                 
;------------------------------------------------------------------------------
; ADC0L Enums (ADC0 Data Word Low Byte @ 0xBE)
;------------------------------------------------------------------------------
ADC0L_ADC0L__FMASK EQU 0FFH ; Data Word Low Byte
ADC0L_ADC0L__SHIFT EQU 000H ; Data Word Low Byte
                                                
;------------------------------------------------------------------------------
; ADC0LTH Enums (ADC0 Less-Than High Byte @ 0xC7)
;------------------------------------------------------------------------------
ADC0LTH_ADC0LTH__FMASK EQU 0FFH ; Less-Than High Byte
ADC0LTH_ADC0LTH__SHIFT EQU 000H ; Less-Than High Byte
                                                     
;------------------------------------------------------------------------------
; ADC0LTL Enums (ADC0 Less-Than Low Byte @ 0xC6)
;------------------------------------------------------------------------------
ADC0LTL_ADC0LTL__FMASK EQU 0FFH ; Less-Than Low Byte
ADC0LTL_ADC0LTL__SHIFT EQU 000H ; Less-Than Low Byte
                                                    
;------------------------------------------------------------------------------
; AMX0CF Enums (AMUX0 Configuration @ 0xBA)
;------------------------------------------------------------------------------
AMX0CF_AIN01IC__BMASK        EQU 001H ; AIN0.0, AIN0.1 Input Pair Configuration         
AMX0CF_AIN01IC__SHIFT        EQU 000H ; AIN0.0, AIN0.1 Input Pair Configuration         
AMX0CF_AIN01IC__SINGLE_ENDED EQU 000H ; AIN0.0 and AIN0.1 are independent single-ended  
                                      ; inputs.                                         
AMX0CF_AIN01IC__DIFFERENTIAL EQU 001H ; AIN0.0 and AIN0.1 are a (respectively) positive,
                                      ; negative differential input pair.               
                                                                                        
AMX0CF_AIN23IC__BMASK        EQU 002H ; AIN0.2, AIN0.3 Input Pair Configuration         
AMX0CF_AIN23IC__SHIFT        EQU 001H ; AIN0.2, AIN0.3 Input Pair Configuration         
AMX0CF_AIN23IC__SINGLE_ENDED EQU 000H ; AIN0.2 and AIN0.3 are independent single-ended  
                                      ; inputs.                                         
AMX0CF_AIN23IC__DIFFERENTIAL EQU 002H ; AIN0.2 and AIN0.3 are a (respectively) positive,
                                      ; negative differential input pair.               
                                                                                        
AMX0CF_AIN45IC__BMASK        EQU 004H ; AIN0.4, AIN0.5 Input Pair Configuration         
AMX0CF_AIN45IC__SHIFT        EQU 002H ; AIN0.4, AIN0.5 Input Pair Configuration         
AMX0CF_AIN45IC__SINGLE_ENDED EQU 000H ; AIN0.4 and AIN0.5 are independent single-ended  
                                      ; inputs.                                         
AMX0CF_AIN45IC__DIFFERENTIAL EQU 004H ; AIN0.4 and AIN0.5 are a (respectively) positive,
                                      ; negative differential input pair.               
                                                                                        
AMX0CF_AIN67IC__BMASK        EQU 008H ; AIN0.6, AIN0.7 Input Pair Configuration         
AMX0CF_AIN67IC__SHIFT        EQU 003H ; AIN0.6, AIN0.7 Input Pair Configuration         
AMX0CF_AIN67IC__SINGLE_ENDED EQU 000H ; AIN0.6 and AIN0.7 are independent single-ended  
                                      ; inputs.                                         
AMX0CF_AIN67IC__DIFFERENTIAL EQU 008H ; AIN0.6 and AIN0.7 are a (respectively) positive,
                                      ; negative differential input pair.               
                                                                                        
;------------------------------------------------------------------------------
; AMX0SL Enums (AMUX0 Channel Select @ 0xBB)
;------------------------------------------------------------------------------
AMX0SL_ADC0AD__FMASK  EQU 00FH ; ADC0 Input Selection
AMX0SL_ADC0AD__SHIFT  EQU 000H ; ADC0 Input Selection
AMX0SL_ADC0AD__ADC0P0 EQU 000H ; Select ADC0.0.      
AMX0SL_ADC0AD__ADC0P1 EQU 001H ; Select ADC0.1.      
AMX0SL_ADC0AD__ADC0P2 EQU 002H ; Select ADC0.2.      
AMX0SL_ADC0AD__ADC0P3 EQU 003H ; Select ADC0.3.      
AMX0SL_ADC0AD__ADC0P4 EQU 004H ; Select ADC0.4.      
AMX0SL_ADC0AD__ADC0P5 EQU 005H ; Select ADC0.5.      
AMX0SL_ADC0AD__ADC0P6 EQU 006H ; Select ADC0.6.      
AMX0SL_ADC0AD__ADC0P7 EQU 007H ; Select ADC0.7.      
AMX0SL_ADC0AD__TEMP   EQU 008H ; Temperature sensor. 
                                                     
;------------------------------------------------------------------------------
; CCH0CN Enums (Cache Control @ 0xA1)
;------------------------------------------------------------------------------
CCH0CN_CHBLKW__BMASK                EQU 001H ; Block Write Enable                                
CCH0CN_CHBLKW__SHIFT                EQU 000H ; Block Write Enable                                
CCH0CN_CHBLKW__BLOCK_WRITE_DISABLED EQU 000H ; Each byte of a firmware flash write is written    
                                             ; individually.                                     
CCH0CN_CHBLKW__BLOCK_WRITE_ENABLED  EQU 001H ; Flash bytes are written in groups of four.        
                                                                                                 
CCH0CN_CHMOVC__BMASK                EQU 002H ; Cache MOVC Enable                                 
CCH0CN_CHMOVC__SHIFT                EQU 001H ; Cache MOVC Enable                                 
CCH0CN_CHMOVC__DISABLED             EQU 000H ; Data requested by MOVC instructions will not be   
                                             ; cached.                                           
CCH0CN_CHMOVC__ENABLED              EQU 002H ; Data requested by MOVC instructions will be loaded
                                             ; into cache memory.                                
                                                                                                 
CCH0CN_CHISR__BMASK                 EQU 004H ; Cache ISR Enable                                  
CCH0CN_CHISR__SHIFT                 EQU 002H ; Cache ISR Enable                                  
CCH0CN_CHISR__DISABLED              EQU 000H ; Instructions in ISRs will not be loaded into cache
                                             ; memory.                                           
CCH0CN_CHISR__ENABLED               EQU 004H ; Instructions in ISRs can be cached.               
                                                                                                 
CCH0CN_CHRETI__BMASK                EQU 008H ; Cache RETI Destination Enable                     
CCH0CN_CHRETI__SHIFT                EQU 003H ; Cache RETI Destination Enable                     
CCH0CN_CHRETI__DISABLED             EQU 000H ; Destinations of RETI instructions will not be     
                                             ; cached.                                           
CCH0CN_CHRETI__ENABLED              EQU 008H ; RETI destinations will be cached.                 
                                                                                                 
CCH0CN_CHFLSH__BMASK                EQU 010H ; Cache Flush                                       
CCH0CN_CHFLSH__SHIFT                EQU 004H ; Cache Flush                                       
CCH0CN_CHFLSH__DO_NOT_FLUSH         EQU 000H ; Do not flush the cache.                           
CCH0CN_CHFLSH__FLUSH                EQU 010H ; Flush the cache.                                  
                                                                                                 
CCH0CN_CHPFEN__BMASK                EQU 020H ; Cache Prefetch Enable                             
CCH0CN_CHPFEN__SHIFT                EQU 005H ; Cache Prefetch Enable                             
CCH0CN_CHPFEN__PREFETCH_DISABLED    EQU 000H ; Disable the prefetch engine.                      
CCH0CN_CHPFEN__PREFETCH_ENABLED     EQU 020H ; Enable the prefetch engine.                       
                                                                                                 
CCH0CN_CHRDEN__BMASK                EQU 040H ; Cache Read Enable                                 
CCH0CN_CHRDEN__SHIFT                EQU 006H ; Cache Read Enable                                 
CCH0CN_CHRDEN__READ_DISABLED        EQU 000H ; All instruction data comes from Flash memory or   
                                             ; the prefetch engine.                              
CCH0CN_CHRDEN__READ_ENABLED         EQU 040H ; Instruction data is obtained from cache (when     
                                             ; available).                                       
                                                                                                 
CCH0CN_CHWREN__BMASK                EQU 080H ; Cache Write Enable                                
CCH0CN_CHWREN__SHIFT                EQU 007H ; Cache Write Enable                                
CCH0CN_CHWREN__WRITE_DISABLED       EQU 000H ; Cache contents are not allowed to change, except  
                                             ; during flash writes/erasures or cache locks.      
CCH0CN_CHWREN__WRITE_ENABLED        EQU 080H ; Writes to cache memory are allowed.               
                                                                                                 
;------------------------------------------------------------------------------
; CCH0LC Enums (Cache Lock Control @ 0xA3)
;------------------------------------------------------------------------------
CCH0LC_CHSLOT__FMASK    EQU 03FH ; Cache Slot Pointer                               
CCH0LC_CHSLOT__SHIFT    EQU 000H ; Cache Slot Pointer                               
                                                                                    
CCH0LC_CHPOP__BMASK     EQU 040H ; Cache Pop                                        
CCH0LC_CHPOP__SHIFT     EQU 006H ; Cache Pop                                        
CCH0LC_CHPOP__NOT_SET   EQU 000H ; Do not increment CHSLOT.                         
CCH0LC_CHPOP__SET       EQU 040H ; Increment CHSLOT and unlock that location.       
                                                                                    
CCH0LC_CHPUSH__BMASK    EQU 080H ; Cache Push Enable                                
CCH0LC_CHPUSH__SHIFT    EQU 007H ; Cache Push Enable                                
CCH0LC_CHPUSH__DISABLED EQU 000H ; Disable cache push operations.                   
CCH0LC_CHPUSH__ENABLED  EQU 080H ; Enable cache push operations. When a MOVC read is
                                 ; executed, the requested 4-byte segment containing
                                 ; the data is locked into the cache at the location
                                 ; indicated by CHSLOT, and CHSLOT is decremented.  
                                                                                    
;------------------------------------------------------------------------------
; CCH0MA Enums (Cache Miss Accumulator @ 0x9A)
;------------------------------------------------------------------------------
CCH0MA_CHMSCTH__FMASK      EQU 07FH ; Cache Miss Penalty Accumulator               
CCH0MA_CHMSCTH__SHIFT      EQU 000H ; Cache Miss Penalty Accumulator               
                                                                                   
CCH0MA_CHMSOV__BMASK       EQU 080H ; Cache Miss Penalty Overflow                  
CCH0MA_CHMSOV__SHIFT       EQU 007H ; Cache Miss Penalty Overflow                  
CCH0MA_CHMSOV__NO_OVERFLOW EQU 000H ; The cache miss penalty accumulator has not   
                                    ; overflowed since it was last written.        
CCH0MA_CHMSOV__OVERFLOW    EQU 080H ; The cache miss penalty accumulator overflowed
                                    ; since it was last written.                   
                                                                                   
;------------------------------------------------------------------------------
; CCH0TN Enums (Cache Tuning @ 0xA2)
;------------------------------------------------------------------------------
CCH0TN_CHMSTH__FMASK         EQU 003H ; Cache Miss Penalty Threshold                      
CCH0TN_CHMSTH__SHIFT         EQU 000H ; Cache Miss Penalty Threshold                      
CCH0TN_CHMSTH__0_CLOCKS      EQU 000H ; Data that takes longer than 0 clocks to obtain    
                                      ; will be cached.                                   
CCH0TN_CHMSTH__1_CLOCK       EQU 001H ; Data that takes longer than 1 clock to obtain will
                                      ; be cached.                                        
CCH0TN_CHMSTH__2_CLOCKS      EQU 002H ; Data that takes longer than 2 clocks to obtain    
                                      ; will be cached.                                   
CCH0TN_CHMSTH__3_CLOCKS      EQU 003H ; Data that takes longer than 3 clocks to obtain    
                                      ; will be cached.                                   
                                                                                          
CCH0TN_CHFIXM__BMASK         EQU 004H ; Cache Fix MOVC Enable                             
CCH0TN_CHFIXM__SHIFT         EQU 002H ; Cache Fix MOVC Enable                             
CCH0TN_CHFIXM__USE_ALGORITHM EQU 000H ; MOVC data is written according to the current     
                                      ; algorithm selected by the CHALGM bit.             
CCH0TN_CHFIXM__ALWAYS_SLOT_0 EQU 004H ; MOVC data is always written to cache slot 0.      
                                                                                          
CCH0TN_CHALGM__BMASK         EQU 008H ; Cache Algorithm Select                            
CCH0TN_CHALGM__SHIFT         EQU 003H ; Cache Algorithm Select                            
CCH0TN_CHALGM__REBOUND       EQU 000H ; Cache uses Rebound algorithm.                     
CCH0TN_CHALGM__PSEUDO_RANDOM EQU 008H ; Cache uses Pseudo-random algorithm.               
                                                                                          
CCH0TN_CHMSCTL__FMASK        EQU 0F0H ; Cache Miss Penalty Accumulator                    
CCH0TN_CHMSCTL__SHIFT        EQU 004H ; Cache Miss Penalty Accumulator                    
                                                                                          
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
; PSBANK Enums (Program Space Bank Select @ 0xB1)
;------------------------------------------------------------------------------
PSBANK_IFBANK__FMASK EQU 003H ; Instruction Fetch Operations Bank Select         
PSBANK_IFBANK__SHIFT EQU 000H ; Instruction Fetch Operations Bank Select         
PSBANK_IFBANK__BANK0 EQU 000H ; Instructions fetch from Bank 0 (note that Bank 0 
                              ; is also mapped between 0x0000 to 0x7FFF).        
PSBANK_IFBANK__BANK1 EQU 001H ; Instructions fetch from Bank 1.                  
PSBANK_IFBANK__BANK2 EQU 002H ; Instructions fetch from Bank 2.                  
PSBANK_IFBANK__BANK3 EQU 003H ; Instructions fetch from Bank 3.                  
                                                                                 
PSBANK_COBANK__FMASK EQU 030H ; Constant Operations Bank Select                  
PSBANK_COBANK__SHIFT EQU 004H ; Constant Operations Bank Select                  
PSBANK_COBANK__BANK0 EQU 000H ; Constant operations target Bank 0 (note that Bank
                              ; 0 is also mapped between 0x0000 to 0x7FFF).      
PSBANK_COBANK__BANK1 EQU 010H ; Constant operations target Bank 1.               
PSBANK_COBANK__BANK2 EQU 020H ; Constant operations target Bank 2.               
PSBANK_COBANK__BANK3 EQU 030H ; Constant operations target Bank 2.               
                                                                                 
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
; CLKSEL Enums (Clock Select @ 0x97)
;------------------------------------------------------------------------------
CLKSEL_CLKSL__FMASK         EQU 003H ; Clock Source Select                             
CLKSEL_CLKSL__SHIFT         EQU 000H ; Clock Source Select                             
CLKSEL_CLKSL__HFOSC         EQU 000H ; Clock derived from the Internal High-Frequency  
                                     ; Oscillator and scaled as per the IFCN bits in   
                                     ; OSCICN.                                         
CLKSEL_CLKSL__EXTOSC        EQU 001H ; Clock derived from the External Oscillator clock
                                     ; circuit.                                        
CLKSEL_CLKSL__PLL           EQU 002H ; Clock derived from the PLL.                     
                                                                                       
CLKSEL_CLKDIV__FMASK        EQU 030H ; Output SYSCLK Divide Factor                     
CLKSEL_CLKDIV__SHIFT        EQU 004H ; Output SYSCLK Divide Factor                     
CLKSEL_CLKDIV__SYSCLK_DIV_1 EQU 000H ; Output will be SYSCLK.                          
CLKSEL_CLKDIV__SYSCLK_DIV_2 EQU 010H ; Output will be SYSCLK / 2.                      
CLKSEL_CLKDIV__SYSCLK_DIV_4 EQU 020H ; Output will be SYSCLK / 4.                      
CLKSEL_CLKDIV__SYSCLK_DIV_8 EQU 030H ; Output will be SYSCLK / 8.                      
                                                                                       
;------------------------------------------------------------------------------
; CPT0CN Enums (Comparator 0 Control @ 0x88)
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
; CPT0MD Enums (Comparator 0 Mode @ 0x89)
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
; CPT1CN Enums (Comparator 1 Control @ 0x88)
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
; CPT1MD Enums (Comparator 1 Mode @ 0x89)
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
; DAC0CN Enums (DAC0 Control @ 0xD4)
;------------------------------------------------------------------------------
DAC0CN_DAC0DF__FMASK           EQU 007H ; DAC0 Data Format                                  
DAC0CN_DAC0DF__SHIFT           EQU 000H ; DAC0 Data Format                                  
DAC0CN_DAC0DF__RIGHT_JUSTIFIED EQU 000H ; Right justified. The most significant nibble of   
                                        ; the DAC0 Data Word is in DAC0H[3:0], while the    
                                        ; least significant byte is in DAC0L.               
DAC0CN_DAC0DF__RIGHT_SHIFT_1   EQU 001H ; Right justified. Shifted left by 1 bit. The most  
                                        ; significant 5 bits of the DAC0 Data Word is in    
                                        ; DAC0H[4:0], while the least significant 7 bits are
                                        ; in DAC0L[7:1].                                    
DAC0CN_DAC0DF__RIGHT_SHIFT_2   EQU 002H ; Right justified. Shifted left by 2 bits. The most 
                                        ; significant 6 bits of the DAC0 Data Word is in    
                                        ; DAC0H[5:0], while the least significant 6 bits are
                                        ; in DAC0L[7:2].                                    
DAC0CN_DAC0DF__RIGHT_SHIFT_3   EQU 003H ; Right justified. Shifted left by 3 bits. The most 
                                        ; significant 7 bits of the DAC0 Data Word is in    
                                        ; DAC0H[6:0], while the least significant 5 bits are
                                        ; in DAC0L[7:3].                                    
DAC0CN_DAC0DF__LEFT_NO_SHIFT   EQU 004H ; Left justified. The most significant 8-bits of the
                                        ; DAC0 Data Word is in DAC0H[7:0], while the least  
                                        ; significant 4-bits are in DAC0L[7:4].             
                                                                                            
DAC0CN_DAC0MD__FMASK           EQU 018H ; DAC0 Mode                                         
DAC0CN_DAC0MD__SHIFT           EQU 003H ; DAC0 Mode                                         
DAC0CN_DAC0MD__DAC0H           EQU 000H ; DAC output updates occur on a write to DAC0H.     
DAC0CN_DAC0MD__TIMER3          EQU 008H ; DAC output updates occur on a Timer 3 overflow.   
DAC0CN_DAC0MD__TIMER4          EQU 010H ; DAC output updates occur on a Timer 4 overflow.   
DAC0CN_DAC0MD__TIMER2          EQU 018H ; DAC output updates occur on a Timer 2 overflow.   
                                                                                            
DAC0CN_DAC0EN__BMASK           EQU 080H ; DAC0 Enable                                       
DAC0CN_DAC0EN__SHIFT           EQU 007H ; DAC0 Enable                                       
DAC0CN_DAC0EN__DISABLED        EQU 000H ; DAC0 disabled. DAC0 output pin is disabled; DAC0  
                                        ; is in low-power shutdown mode.                    
DAC0CN_DAC0EN__ENABLED         EQU 080H ; DAC0 enabled. DAC0 output pin is active; DAC0 is  
                                        ; operational.                                      
                                                                                            
;------------------------------------------------------------------------------
; DAC0H Enums (DAC0 Data High Byte @ 0xD3)
;------------------------------------------------------------------------------
DAC0H_DAC0H__FMASK EQU 0FFH ; DAC0 Data High
DAC0H_DAC0H__SHIFT EQU 000H ; DAC0 Data High
                                            
;------------------------------------------------------------------------------
; DAC0L Enums (DAC0 Data Low Byte @ 0xD2)
;------------------------------------------------------------------------------
DAC0L_DAC0L__FMASK EQU 0FFH ; DAC0 Data Low
DAC0L_DAC0L__SHIFT EQU 000H ; DAC0 Data Low
                                           
;------------------------------------------------------------------------------
; DAC1CN Enums (DAC1 Control @ 0xD4)
;------------------------------------------------------------------------------
DAC1CN_DAC1DF__FMASK           EQU 007H ; DAC1 Data Format                                  
DAC1CN_DAC1DF__SHIFT           EQU 000H ; DAC1 Data Format                                  
DAC1CN_DAC1DF__RIGHT_JUSTIFIED EQU 000H ; Right justified. The most significant nibble of   
                                        ; the DAC1 Data Word is in DAC1H[3:0], while the    
                                        ; least significant byte is in DAC1L.               
DAC1CN_DAC1DF__RIGHT_SHIFT_1   EQU 001H ; Right justified. Shifted left by 1 bit. The most  
                                        ; significant 5 bits of the DAC1 Data Word is in    
                                        ; DAC1H[4:0], while the least significant 7 bits are
                                        ; in DAC1L[7:1].                                    
DAC1CN_DAC1DF__RIGHT_SHIFT_2   EQU 002H ; Right justified. Shifted left by 2 bits. The most 
                                        ; significant 6 bits of the DAC1 Data Word is in    
                                        ; DAC1H[5:0], while the least significant 6 bits are
                                        ; in DAC1L[7:2].                                    
DAC1CN_DAC1DF__RIGHT_SHIFT_3   EQU 003H ; Right justified. Shifted left by 3 bits. The most 
                                        ; significant 7 bits of the DAC1 Data Word is in    
                                        ; DAC1H[6:0], while the least significant 5 bits are
                                        ; in DAC1L[7:3].                                    
DAC1CN_DAC1DF__LEFT_NO_SHIFT   EQU 004H ; Left justified. The most significant 8-bits of the
                                        ; DAC1 Data Word is in DAC1H[7:0], while the least  
                                        ; significant 4-bits are in DAC1L[7:4].             
                                                                                            
DAC1CN_DAC1MD__FMASK           EQU 018H ; DAC1 Mode                                         
DAC1CN_DAC1MD__SHIFT           EQU 003H ; DAC1 Mode                                         
DAC1CN_DAC1MD__DAC1H           EQU 000H ; DAC output updates occur on a write to DAC1H.     
DAC1CN_DAC1MD__TIMER3          EQU 008H ; DAC output updates occur on a Timer 3 overflow.   
DAC1CN_DAC1MD__TIMER4          EQU 010H ; DAC output updates occur on a Timer 4 overflow.   
DAC1CN_DAC1MD__TIMER2          EQU 018H ; DAC output updates occur on a Timer 2 overflow.   
                                                                                            
DAC1CN_DAC1EN__BMASK           EQU 080H ; DAC1 Enable                                       
DAC1CN_DAC1EN__SHIFT           EQU 007H ; DAC1 Enable                                       
DAC1CN_DAC1EN__DISABLED        EQU 000H ; DAC1 disabled. DAC1 output pin is disabled; DAC1  
                                        ; is in low-power shutdown mode.                    
DAC1CN_DAC1EN__ENABLED         EQU 080H ; DAC1 enabled. DAC1 output pin is active; DAC1 is  
                                        ; operational.                                      
                                                                                            
;------------------------------------------------------------------------------
; DAC1H Enums (DAC1 Data High Byte @ 0xD3)
;------------------------------------------------------------------------------
DAC1H_DAC1H__FMASK EQU 0FFH ; DAC1 Data High
DAC1H_DAC1H__SHIFT EQU 000H ; DAC1 Data High
                                            
;------------------------------------------------------------------------------
; DAC1L Enums (DAC1 Data Low Byte @ 0xD2)
;------------------------------------------------------------------------------
DAC1L_DAC1L__FMASK EQU 0FFH ; DAC1 Data Low
DAC1L_DAC1L__SHIFT EQU 000H ; DAC1 Data Low
                                           
;------------------------------------------------------------------------------
; OSCXCN Enums (External Oscillator Control @ 0x8C)
;------------------------------------------------------------------------------
OSCXCN_XFCN__FMASK           EQU 007H ; External Oscillator Frequency Control             
OSCXCN_XFCN__SHIFT           EQU 000H ; External Oscillator Frequency Control             
OSCXCN_XFCN__MODE0           EQU 000H ; Select external oscillator mode 0: Crystal        
                                      ; frequency <= 32 kHz, RC/C frequency <= 25 kHz, C  
                                      ; mode K factor = 0.87.                             
OSCXCN_XFCN__MODE1           EQU 001H ; Select external oscillator mode 1: 32 kHz <       
                                      ; Crystal frequency <= 84 kHz, 25 kHz < RC/C        
                                      ; frequency <= 50 kHz, C mode K factor = 2.6.       
OSCXCN_XFCN__MODE2           EQU 002H ; Select external oscillator mode 2: 84 kHz <       
                                      ; Crystal frequency <= 225 kHz, 50 kHz < RC/C       
                                      ; frequency <= 100 kHz, C mode K factor = 7.7.      
OSCXCN_XFCN__MODE3           EQU 003H ; Select external oscillator mode 3: 225 kHz <      
                                      ; Crystal frequency <= 590 kHz, 100 kHz < RC/C      
                                      ; frequency <= 200 kHz, C mode K factor = 22.       
OSCXCN_XFCN__MODE4           EQU 004H ; Select external oscillator mode 4: 590 kHz <      
                                      ; Crystal frequency <= 1.5 MHz, 200 kHz < RC/C      
                                      ; frequency <= 400 kHz, C mode K factor = 65.       
OSCXCN_XFCN__MODE5           EQU 005H ; Select external oscillator mode 5: 1.5 MHz <      
                                      ; Crystal frequency <= 4 MHz, 400 kHz < RC/C        
                                      ; frequency <= 800 kHz, C mode K factor = 180.      
OSCXCN_XFCN__MODE6           EQU 006H ; Select external oscillator mode 6: 4 MHz < Crystal
                                      ; frequency <= 10 MHz, 800 kHz < RC/C frequency <=  
                                      ; 1.6 MHz, C mode K factor = 664.                   
OSCXCN_XFCN__MODE7           EQU 007H ; Select external oscillator mode 7: 10 MHz <       
                                      ; Crystal frequency <= 30 MHz, 1.6 MHz < RC/C       
                                      ; frequency <= 3.2 MHz, C mode K factor = 1590.     
                                                                                          
OSCXCN_XOSCMD__FMASK         EQU 070H ; External Oscillator Mode                          
OSCXCN_XOSCMD__SHIFT         EQU 004H ; External Oscillator Mode                          
OSCXCN_XOSCMD__DISABLED      EQU 000H ; External Oscillator circuit disabled.             
OSCXCN_XOSCMD__CMOS          EQU 020H ; External CMOS Clock Mode.                         
OSCXCN_XOSCMD__CMOS_DIV_2    EQU 030H ; External CMOS Clock Mode with divide by 2 stage.  
OSCXCN_XOSCMD__RC            EQU 040H ; RC Oscillator Mode with divide by 2 stage.        
OSCXCN_XOSCMD__CRYSTAL       EQU 060H ; Crystal Oscillator Mode.                          
OSCXCN_XOSCMD__CRYSTAL_DIV_2 EQU 070H ; Crystal Oscillator Mode with divide by 2 stage.   
                                                                                          
OSCXCN_XTLVLD__BMASK         EQU 080H ; Crystal Oscillator Valid Flag                     
OSCXCN_XTLVLD__SHIFT         EQU 007H ; Crystal Oscillator Valid Flag                     
OSCXCN_XTLVLD__NOT_SET       EQU 000H ; External crystal is unused or not yet stable.     
OSCXCN_XTLVLD__SET           EQU 080H ; External crystal is running and stable.           
                                                                                          
;------------------------------------------------------------------------------
; FLACL Enums (Flash Access Limit @ 0xB7)
;------------------------------------------------------------------------------
FLACL_FLACL__FMASK EQU 0FFH ; Flash Access Limit
FLACL_FLACL__SHIFT EQU 000H ; Flash Access Limit
                                                
;------------------------------------------------------------------------------
; FLSCL Enums (Flash Scale @ 0xB7)
;------------------------------------------------------------------------------
FLSCL_FLWE__BMASK                EQU 001H ; Flash Write/Erase Enable     
FLSCL_FLWE__SHIFT                EQU 000H ; Flash Write/Erase Enable     
FLSCL_FLWE__DISABLED             EQU 000H ; Flash writes/erases disabled.
FLSCL_FLWE__ENABLED              EQU 001H ; Flash writes/erases enabled. 
                                                                         
FLSCL_FLRT__FMASK                EQU 030H ; Flash Read Timing            
FLSCL_FLRT__SHIFT                EQU 004H ; Flash Read Timing            
FLSCL_FLRT__SYSCLK_BELOW_25_MHZ  EQU 000H ; SYSCLK <= 25 MHz.            
FLSCL_FLRT__SYSCLK_BELOW_50_MHZ  EQU 010H ; SYSCLK <= 50 MHz.            
FLSCL_FLRT__SYSCLK_BELOW_75_MHZ  EQU 020H ; SYSCLK <= 75 MHz.            
FLSCL_FLRT__SYSCLK_BELOW_100_MHZ EQU 030H ; SYSCLK <= 100 MHz.           
                                                                         
;------------------------------------------------------------------------------
; FLSTAT Enums (Flash Status @ 0x88)
;------------------------------------------------------------------------------
FLSTAT_FLBUSY__BMASK   EQU 001H ; Flash Busy                                 
FLSTAT_FLBUSY__SHIFT   EQU 000H ; Flash Busy                                 
FLSTAT_FLBUSY__NOT_SET EQU 000H ; Flash is idle or reading.                  
FLSTAT_FLBUSY__SET     EQU 001H ; Flash write/erase operation is currently in
                                ; progress.                                  
                                                                             
;------------------------------------------------------------------------------
; PSCTL Enums (Program Store Control @ 0x8F)
;------------------------------------------------------------------------------
PSCTL_PSWE__BMASK               EQU 001H ; Program Store Write Enable                      
PSCTL_PSWE__SHIFT               EQU 000H ; Program Store Write Enable                      
PSCTL_PSWE__WRITE_DISABLED      EQU 000H ; Writes to flash program memory disabled.        
PSCTL_PSWE__WRITE_ENABLED       EQU 001H ; Writes to flash program memory enabled; the MOVX
                                         ; write instruction targets flash memory.         
                                                                                           
PSCTL_PSEE__BMASK               EQU 002H ; Program Store Erase Enable                      
PSCTL_PSEE__SHIFT               EQU 001H ; Program Store Erase Enable                      
PSCTL_PSEE__ERASE_DISABLED      EQU 000H ; Flash program memory erasure disabled.          
PSCTL_PSEE__ERASE_ENABLED       EQU 002H ; Flash program memory erasure enabled.           
                                                                                           
PSCTL_SFLE__BMASK               EQU 004H ; Scratchpad Flash Memory Access Enable           
PSCTL_SFLE__SHIFT               EQU 002H ; Scratchpad Flash Memory Access Enable           
PSCTL_SFLE__SCRATCHPAD_DISABLED EQU 000H ; Flash access from user software directed to the 
                                         ; Program/Data flash sector.                      
PSCTL_SFLE__SCRATCHPAD_ENABLED  EQU 004H ; Flash access from user software directed to the 
                                         ; two 128 byte Scratchpad sectors.                
                                                                                           
;------------------------------------------------------------------------------
; OSCICL Enums (High Frequency Oscillator Calibration @ 0x8B)
;------------------------------------------------------------------------------
OSCICL_OSCICL__FMASK EQU 0FFH ; Internal Oscillator Calibration
OSCICL_OSCICL__SHIFT EQU 000H ; Internal Oscillator Calibration
                                                               
;------------------------------------------------------------------------------
; OSCICN Enums (High Frequency Oscillator Control @ 0x8A)
;------------------------------------------------------------------------------
OSCICN_IFCN__FMASK       EQU 003H ; Oscillator Frequency Divider Control             
OSCICN_IFCN__SHIFT       EQU 000H ; Oscillator Frequency Divider Control             
OSCICN_IFCN__HFOSC_DIV_8 EQU 000H ; SYSCLK derived from High Frequency Oscillator    
                                  ; divided by 8.                                    
OSCICN_IFCN__HFOSC_DIV_4 EQU 001H ; SYSCLK derived from High Frequency Oscillator    
                                  ; divided by 4.                                    
OSCICN_IFCN__HFOSC_DIV_2 EQU 002H ; SYSCLK derived from High Frequency Oscillator    
                                  ; divided by 2.                                    
OSCICN_IFCN__HFOSC_DIV_1 EQU 003H ; SYSCLK derived from High Frequency Oscillator    
                                  ; divided by 1.                                    
                                                                                     
OSCICN_IFRDY__BMASK      EQU 040H ; Oscillator Frequency Ready Flag                  
OSCICN_IFRDY__SHIFT      EQU 006H ; Oscillator Frequency Ready Flag                  
OSCICN_IFRDY__NOT_SET    EQU 000H ; The Internal High Frequency Oscillator is not    
                                  ; running at the programmed frequency.             
OSCICN_IFRDY__SET        EQU 040H ; The Internal High Frequency Oscillator is running
                                  ; at the programmed frequency.                     
                                                                                     
OSCICN_IOSCEN__BMASK     EQU 080H ; Oscillator Enable                                
OSCICN_IOSCEN__SHIFT     EQU 007H ; Oscillator Enable                                
OSCICN_IOSCEN__DISABLED  EQU 000H ; Disable the High Frequency Oscillator.           
OSCICN_IOSCEN__ENABLED   EQU 080H ; Enable the High Frequency Oscillator.            
                                                                                     
;------------------------------------------------------------------------------
; EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
;------------------------------------------------------------------------------
EIE1_ESPI0__BMASK     EQU 001H ; SPI0 Interrupt Enable                             
EIE1_ESPI0__SHIFT     EQU 000H ; SPI0 Interrupt Enable                             
EIE1_ESPI0__DISABLED  EQU 000H ; Disable all SPI0 interrupts.                      
EIE1_ESPI0__ENABLED   EQU 001H ; Enable interrupt requests generated by SPI0.      
                                                                                   
EIE1_EMAT__BMASK      EQU 002H ; Port Match Interrupts Enable                      
EIE1_EMAT__SHIFT      EQU 001H ; Port Match Interrupts Enable                      
EIE1_EMAT__DISABLED   EQU 000H ; Disable all Port Match interrupts.                
EIE1_EMAT__ENABLED    EQU 002H ; Enable interrupt requests generated by a Port     
                               ; Match.                                            
                                                                                   
EIE1_ESMB0__BMASK     EQU 002H ; SMBus (SMB0) Interrupt Enable                     
EIE1_ESMB0__SHIFT     EQU 001H ; SMBus (SMB0) Interrupt Enable                     
EIE1_ESMB0__DISABLED  EQU 000H ; Disable all SMB0 interrupts.                      
EIE1_ESMB0__ENABLED   EQU 002H ; Enable interrupt requests generated by SMB0.      
                                                                                   
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
                                                                                   
EIE1_EPCA0__BMASK     EQU 008H ; Programmable Counter Array (PCA0) Interrupt Enable
EIE1_EPCA0__SHIFT     EQU 003H ; Programmable Counter Array (PCA0) Interrupt Enable
EIE1_EPCA0__DISABLED  EQU 000H ; Disable all PCA0 interrupts.                      
EIE1_EPCA0__ENABLED   EQU 008H ; Enable interrupt requests generated by PCA0.      
                                                                                   
EIE1_ECP0F__BMASK     EQU 010H ; Comparator0 (CP0) Falling Edge Interrupt Enable   
EIE1_ECP0F__SHIFT     EQU 004H ; Comparator0 (CP0) Falling Edge Interrupt Enable   
EIE1_ECP0F__DISABLED  EQU 000H ; Disable CP0 falling edge interrupts.              
EIE1_ECP0F__ENABLED   EQU 010H ; Enable interrupt requests generated by the        
                               ; comparator 0 CPFIF flag.                          
                                                                                   
EIE1_ECP0__BMASK      EQU 020H ; Comparator0 (CP0) Interrupt Enable                
EIE1_ECP0__SHIFT      EQU 005H ; Comparator0 (CP0) Interrupt Enable                
EIE1_ECP0__DISABLED   EQU 000H ; Disable CP0 interrupts.                           
EIE1_ECP0__ENABLED    EQU 020H ; Enable interrupt requests generated by the        
                               ; comparator 0 CPRIF or CPFIF flags.                
                                                                                   
EIE1_ECP0R__BMASK     EQU 020H ; Comparator0 (CP0) Rising Edge Interrupt Enable    
EIE1_ECP0R__SHIFT     EQU 005H ; Comparator0 (CP0) Rising Edge Interrupt Enable    
EIE1_ECP0R__DISABLED  EQU 000H ; Disable CP0 rising edge interrupts.               
EIE1_ECP0R__ENABLED   EQU 020H ; Enable interrupt requests generated by the        
                               ; comparator 0 CPRIF flag.                          
                                                                                   
EIE1_ECP1__BMASK      EQU 040H ; Comparator1 (CP1) Interrupt Enable                
EIE1_ECP1__SHIFT      EQU 006H ; Comparator1 (CP1) Interrupt Enable                
EIE1_ECP1__DISABLED   EQU 000H ; Disable CP1 interrupts.                           
EIE1_ECP1__ENABLED    EQU 040H ; Enable interrupt requests generated by the        
                               ; comparator 1 CPRIF or CPFIF flags.                
                                                                                   
EIE1_ECP1F__FMASK     EQU 0C0H ; Comparator1 (CP1) Falling Edge Interrupt Enable   
EIE1_ECP1F__SHIFT     EQU 006H ; Comparator1 (CP1) Falling Edge Interrupt Enable   
EIE1_ECP1F__DISABLED  EQU 000H ; Disable CP1 rising edge interrupts.               
EIE1_ECP1F__ENABLED   EQU 040H ; Enable interrupt requests generated by the        
                               ; comparator 1 CPRIF flag.                          
                                                                                   
EIE1_ET3__BMASK       EQU 080H ; Timer 3 Interrupt Enable                          
EIE1_ET3__SHIFT       EQU 007H ; Timer 3 Interrupt Enable                          
EIE1_ET3__DISABLED    EQU 000H ; Disable Timer 3 interrupts.                       
EIE1_ET3__ENABLED     EQU 080H ; Enable interrupt requests generated by the TF3L or
                               ; TF3H flags.                                       
                                                                                   
;------------------------------------------------------------------------------
; EIE2 Enums (Extended Interrupt Enable 2 @ 0xE7)
;------------------------------------------------------------------------------
EIE2_ET3__BMASK       EQU 001H ; Timer 3 Interrupt Enable                          
EIE2_ET3__SHIFT       EQU 000H ; Timer 3 Interrupt Enable                          
EIE2_ET3__DISABLED    EQU 000H ; Disable Timer 3 interrupts.                       
EIE2_ET3__ENABLED     EQU 001H ; Enable interrupt requests generated by the TF3L or
                               ; TF3H flags.                                       
                                                                                   
EIE2_EADC0__BMASK     EQU 002H ; ADC0 Conversion Complete Interrupt Enable         
EIE2_EADC0__SHIFT     EQU 001H ; ADC0 Conversion Complete Interrupt Enable         
EIE2_EADC0__DISABLED  EQU 000H ; Disable ADC0 Conversion Complete interrupt.       
EIE2_EADC0__ENABLED   EQU 002H ; Enable interrupt requests generated by the ADINT  
                               ; flag.                                             
                                                                                   
EIE2_ET4__BMASK       EQU 004H ; Timer 4 Interrupt Enable                          
EIE2_ET4__SHIFT       EQU 002H ; Timer 4 Interrupt Enable                          
EIE2_ET4__DISABLED    EQU 000H ; Disable Timer 4 interrupts.                       
EIE2_ET4__ENABLED     EQU 004H ; Enable interrupt requests generated by the TF4L or
                               ; TF4H flags.                                       
                                                                                   
EIE2_EWADC2__BMASK    EQU 008H ; ADC2 Window Comparison Interrupt Enable           
EIE2_EWADC2__SHIFT    EQU 003H ; ADC2 Window Comparison Interrupt Enable           
EIE2_EWADC2__DISABLED EQU 000H ; Disable ADC2 Window Comparison interrupt.         
EIE2_EWADC2__ENABLED  EQU 008H ; Enable interrupt requests generated by ADC2 Window
                               ; Compare flag (ADWINT).                            
                                                                                   
EIE2_EADC2__BMASK     EQU 010H ; ADC2 Conversion Complete Interrupt Enable         
EIE2_EADC2__SHIFT     EQU 004H ; ADC2 Conversion Complete Interrupt Enable         
EIE2_EADC2__DISABLED  EQU 000H ; Disable ADC2 Conversion Complete interrupt.       
EIE2_EADC2__ENABLED   EQU 010H ; Enable interrupt requests generated by the ADINT  
                               ; flag.                                             
                                                                                   
EIE2_ES1__BMASK       EQU 040H ; UART1 Interrupt Enable                            
EIE2_ES1__SHIFT       EQU 006H ; UART1 Interrupt Enable                            
EIE2_ES1__DISABLED    EQU 000H ; Disable UART1 interrupts.                         
EIE2_ES1__ENABLED     EQU 040H ; Enable UART1 interrupts.                          
                                                                                   
;------------------------------------------------------------------------------
; EIP1 Enums (Extended Interrupt Priority 1 Low @ 0xF6)
;------------------------------------------------------------------------------
EIP1_PSPI0__BMASK  EQU 001H ; Serial Peripheral Interface (SPI0) Interrupt Priority Control
EIP1_PSPI0__SHIFT  EQU 000H ; Serial Peripheral Interface (SPI0) Interrupt Priority Control
EIP1_PSPI0__LOW    EQU 000H ; SPI0 interrupt priority set to low.                          
EIP1_PSPI0__HIGH   EQU 001H ; SPI0 interrupt priority set to high.                         
                                                                                           
EIP1_PMAT__BMASK   EQU 002H ; Port Match Interrupt Priority Control                        
EIP1_PMAT__SHIFT   EQU 001H ; Port Match Interrupt Priority Control                        
EIP1_PMAT__LOW     EQU 000H ; Port Match interrupt set to low priority level.              
EIP1_PMAT__HIGH    EQU 002H ; Port Match interrupt set to high priority level.             
                                                                                           
EIP1_PSMB0__BMASK  EQU 002H ; SMBus (SMB0) Interrupt Priority Control                      
EIP1_PSMB0__SHIFT  EQU 001H ; SMBus (SMB0) Interrupt Priority Control                      
EIP1_PSMB0__LOW    EQU 000H ; SMB0 interrupt priority set to low.                          
EIP1_PSMB0__HIGH   EQU 002H ; SMB0 interrupt priority set to high.                         
                                                                                           
EIP1_PWADC0__BMASK EQU 004H ; ADC0 Window Comparator Interrupt Priority Control            
EIP1_PWADC0__SHIFT EQU 002H ; ADC0 Window Comparator Interrupt Priority Control            
EIP1_PWADC0__LOW   EQU 000H ; ADC0 Conversion Complete interrupt priority set to           
                            ; low.                                                         
EIP1_PWADC0__HIGH  EQU 004H ; ADC0 Conversion Complete interrupt priority set to           
                            ; high.                                                        
                                                                                           
EIP1_PADC0__BMASK  EQU 008H ; ADC0 Conversion Complete Interrupt Priority Control          
EIP1_PADC0__SHIFT  EQU 003H ; ADC0 Conversion Complete Interrupt Priority Control          
EIP1_PADC0__LOW    EQU 000H ; ADC0 Conversion Complete interrupt set to low                
                            ; priority level.                                              
EIP1_PADC0__HIGH   EQU 008H ; ADC0 Conversion Complete interrupt set to high               
                            ; priority level.                                              
                                                                                           
EIP1_PPCA0__BMASK  EQU 008H ; Programmable Counter Array (PCA0) Interrupt Priority Control 
EIP1_PPCA0__SHIFT  EQU 003H ; Programmable Counter Array (PCA0) Interrupt Priority Control 
EIP1_PPCA0__LOW    EQU 000H ; PCA0 interrupt priority set to low.                          
EIP1_PPCA0__HIGH   EQU 008H ; PCA0 interrupt priority set to high.                         
                                                                                           
EIP1_PCP0F__BMASK  EQU 010H ; Comparator0 (CP0) Falling Edge Interrupt Priority Control    
EIP1_PCP0F__SHIFT  EQU 004H ; Comparator0 (CP0) Falling Edge Interrupt Priority Control    
EIP1_PCP0F__LOW    EQU 000H ; CP0 falling edge interrupt priority set to low.              
EIP1_PCP0F__HIGH   EQU 010H ; CP0 falling edge interrupt priority set to high.             
                                                                                           
EIP1_PCP0__BMASK   EQU 020H ; Comparator0 (CP0) Interrupt Priority Control                 
EIP1_PCP0__SHIFT   EQU 005H ; Comparator0 (CP0) Interrupt Priority Control                 
EIP1_PCP0__LOW     EQU 000H ; CP0 interrupt set to low priority level.                     
EIP1_PCP0__HIGH    EQU 020H ; CP0 interrupt set to high priority level.                    
                                                                                           
EIP1_PCP0R__BMASK  EQU 020H ; Comparator0 (CP0) Rising Edge Interrupt Priority Control     
EIP1_PCP0R__SHIFT  EQU 005H ; Comparator0 (CP0) Rising Edge Interrupt Priority Control     
EIP1_PCP0R__LOW    EQU 000H ; CP0 rising edge interrupt priority set to low.               
EIP1_PCP0R__HIGH   EQU 020H ; CP0 rising edge interrupt priority set to high.              
                                                                                           
EIP1_PCP1__BMASK   EQU 040H ; Comparator1 (CP1) Interrupt Priority Control                 
EIP1_PCP1__SHIFT   EQU 006H ; Comparator1 (CP1) Interrupt Priority Control                 
EIP1_PCP1__LOW     EQU 000H ; CP1 interrupt set to low priority level.                     
EIP1_PCP1__HIGH    EQU 040H ; CP1 interrupt set to high priority level.                    
                                                                                           
EIP1_PCP1F__BMASK  EQU 040H ; Comparator1 (CP1) Falling Edge Interrupt Priority Control    
EIP1_PCP1F__SHIFT  EQU 006H ; Comparator1 (CP1) Falling Edge Interrupt Priority Control    
EIP1_PCP1F__LOW    EQU 000H ; CP1 falling edge interrupt priority set to low.              
EIP1_PCP1F__HIGH   EQU 040H ; CP1 falling edge interrupt priority set to high.             
                                                                                           
EIP1_PCP1R__BMASK  EQU 080H ; Comparator1 (CP1) Rising Edge Interrupt Priority Control     
EIP1_PCP1R__SHIFT  EQU 007H ; Comparator1 (CP1) Rising Edge Interrupt Priority Control     
EIP1_PCP1R__LOW    EQU 000H ; CP1 rising edge interrupt priority set to low.               
EIP1_PCP1R__HIGH   EQU 080H ; CP1 rising edge interrupt priority set to high.              
                                                                                           
EIP1_PT3__BMASK    EQU 080H ; Timer 3 Interrupt Priority Control                           
EIP1_PT3__SHIFT    EQU 007H ; Timer 3 Interrupt Priority Control                           
EIP1_PT3__LOW      EQU 000H ; Timer 3 interrupts set to low priority level.                
EIP1_PT3__HIGH     EQU 080H ; Timer 3 interrupts set to high priority level.               
                                                                                           
;------------------------------------------------------------------------------
; EIP2 Enums (Extended Interrupt Priority 2 @ 0xF7)
;------------------------------------------------------------------------------
EIP2_PT3__BMASK    EQU 001H ; Timer 3 Interrupt Priority Control                 
EIP2_PT3__SHIFT    EQU 000H ; Timer 3 Interrupt Priority Control                 
EIP2_PT3__LOW      EQU 000H ; CP1 interrupt priority set to low.                 
EIP2_PT3__HIGH     EQU 001H ; CP1 interrupt priority set to high.                
                                                                                 
EIP2_PADC0__BMASK  EQU 002H ; ADC0 Conversion Complete Interrupt Priority Control
EIP2_PADC0__SHIFT  EQU 001H ; ADC0 Conversion Complete Interrupt Priority Control
EIP2_PADC0__LOW    EQU 000H ; ADC0 Conversion Complete interrupt priority set to 
                            ; low.                                               
EIP2_PADC0__HIGH   EQU 002H ; ADC0 Conversion Complete interrupt priority set to 
                            ; high.                                              
                                                                                 
EIP2_PT4__BMASK    EQU 004H ; Timer 4 Interrupt Priority Control                 
EIP2_PT4__SHIFT    EQU 002H ; Timer 4 Interrupt Priority Control                 
EIP2_PT4__LOW      EQU 000H ; Timer 4 interrupt priority set to low.             
EIP2_PT4__HIGH     EQU 004H ; Timer 4 interrupt priority set to high.            
                                                                                 
EIP2_PWADC2__BMASK EQU 008H ; ADC2 Window Comparator Interrupt Priority Control  
EIP2_PWADC2__SHIFT EQU 003H ; ADC2 Window Comparator Interrupt Priority Control  
EIP2_PWADC2__LOW   EQU 000H ; ADC2 Conversion Complete interrupt priority set to 
                            ; low.                                               
EIP2_PWADC2__HIGH  EQU 008H ; ADC2 Conversion Complete interrupt priority set to 
                            ; high.                                              
                                                                                 
EIP2_PADC2__BMASK  EQU 010H ; ADC2 Conversion Complete Interrupt Priority Control
EIP2_PADC2__SHIFT  EQU 004H ; ADC2 Conversion Complete Interrupt Priority Control
EIP2_PADC2__LOW    EQU 000H ; ADC2 Conversion Complete interrupt priority set to 
                            ; low.                                               
EIP2_PADC2__HIGH   EQU 010H ; ADC2 Conversion Complete interrupt priority set to 
                            ; high.                                              
                                                                                 
EIP2_PS1__BMASK    EQU 040H ; UART1 Interrupt Priority Control                   
EIP2_PS1__SHIFT    EQU 006H ; UART1 Interrupt Priority Control                   
EIP2_PS1__LOW      EQU 000H ; UART1 interrupt priority set to low.               
EIP2_PS1__HIGH     EQU 040H ; UART1 interrupt priority set to high.              
                                                                                 
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
                                                                                
IE_IEGF0__BMASK    EQU 040H ; General Purpose Flag 0                            
IE_IEGF0__SHIFT    EQU 006H ; General Purpose Flag 0                            
IE_IEGF0__NOT_SET  EQU 000H ; The flag is not set. Clear the flag.              
IE_IEGF0__SET      EQU 040H ; The flag is set. Set the flag.                    
                                                                                
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
IP_PX0__LOW     EQU 000H ; External Interrupt 0 priority set to low.                    
IP_PX0__HIGH    EQU 001H ; External Interrupt 0 priority set to high.                   
                                                                                        
IP_PT0__BMASK   EQU 002H ; Timer 0 Interrupt Priority Control                           
IP_PT0__SHIFT   EQU 001H ; Timer 0 Interrupt Priority Control                           
IP_PT0__LOW     EQU 000H ; Timer 0 interrupt priority set to low.                       
IP_PT0__HIGH    EQU 002H ; Timer 0 interrupt priority set to high.                      
                                                                                        
IP_PX1__BMASK   EQU 004H ; External Interrupt 1 Priority Control                        
IP_PX1__SHIFT   EQU 002H ; External Interrupt 1 Priority Control                        
IP_PX1__LOW     EQU 000H ; External Interrupt 1 priority set to low.                    
IP_PX1__HIGH    EQU 004H ; External Interrupt 1 priority set to high.                   
                                                                                        
IP_PT1__BMASK   EQU 008H ; Timer 1 Interrupt Priority Control                           
IP_PT1__SHIFT   EQU 003H ; Timer 1 Interrupt Priority Control                           
IP_PT1__LOW     EQU 000H ; Timer 1 interrupt priority set to low.                       
IP_PT1__HIGH    EQU 008H ; Timer 1 interrupt priority set to high.                      
                                                                                        
IP_PS0__BMASK   EQU 010H ; UART0 Interrupt Priority Control                             
IP_PS0__SHIFT   EQU 004H ; UART0 Interrupt Priority Control                             
IP_PS0__LOW     EQU 000H ; UART0 interrupt priority set to low.                         
IP_PS0__HIGH    EQU 010H ; UART0 interrupt priority set to high.                        
                                                                                        
IP_PT2__BMASK   EQU 020H ; Timer 2 Interrupt Priority Control                           
IP_PT2__SHIFT   EQU 005H ; Timer 2 Interrupt Priority Control                           
IP_PT2__LOW     EQU 000H ; Timer 2 interrupt priority set to low.                       
IP_PT2__HIGH    EQU 020H ; Timer 2 interrupt priority set to high.                      
                                                                                        
IP_PSPI0__BMASK EQU 040H ; Serial Peripheral Interface (SPI0) Interrupt Priority Control
IP_PSPI0__SHIFT EQU 006H ; Serial Peripheral Interface (SPI0) Interrupt Priority Control
IP_PSPI0__LOW   EQU 000H ; SPI0 interrupt set to low priority level.                    
IP_PSPI0__HIGH  EQU 040H ; SPI0 interrupt set to high priority level.                   
                                                                                        
;------------------------------------------------------------------------------
; DEVICEID Enums (JTAG Device ID @ 0x04)
;------------------------------------------------------------------------------
DEVICEID_DEVICEID__FMASK EQU FFFFFFFFH ; Device ID
DEVICEID_DEVICEID__SHIFT EQU 000H      ; Device ID
                                                  
;------------------------------------------------------------------------------
; FLASHADR Enums (JTAG Flash Address @ 0x84)
;------------------------------------------------------------------------------
FLASHADR_FLASHADR__FMASK EQU 1FFFFH ; Flash Operation 17-bit Address
FLASHADR_FLASHADR__SHIFT EQU 000H   ; Flash Operation 17-bit Address
                                                                    
;------------------------------------------------------------------------------
; FLASHCON Enums (JTAG Flash Control @ 0x82)
;------------------------------------------------------------------------------
FLASHCON_RDMD__FMASK EQU 00FH ; Read Mode Select                     
FLASHCON_RDMD__SHIFT EQU 000H ; Read Mode Select                     
                                                                     
FLASHCON_WRMD__FMASK EQU 070H ; Write Mode Select                    
FLASHCON_WRMD__SHIFT EQU 004H ; Write Mode Select                    
                                                                     
FLASHCON_SFLE__BMASK EQU 080H ; Scratchpad Flash Memory Access Enable
FLASHCON_SFLE__SHIFT EQU 007H ; Scratchpad Flash Memory Access Enable
                                                                     
;------------------------------------------------------------------------------
; FLASHDAT Enums (JTAG Flash Data @ 0x83)
;------------------------------------------------------------------------------
FLASHDAT_BUSY__BMASK EQU 001H ; Flash Busy     
FLASHDAT_BUSY__SHIFT EQU 000H ; Flash Busy     
                                               
FLASHDAT_FAIL__BMASK EQU 002H ; Flash Fail     
FLASHDAT_FAIL__SHIFT EQU 001H ; Flash Fail     
                                               
FLASHDAT_DATA__FMASK EQU 3FCH ; Flash Data Byte
FLASHDAT_DATA__SHIFT EQU 002H ; Flash Data Byte
                                               
;------------------------------------------------------------------------------
; MAC0ACC0 Enums (Accumulator Byte 0 @ 0x93)
;------------------------------------------------------------------------------
MAC0ACC0_MAC0ACC0__FMASK EQU 0FFH ; MAC0 Accumulator Byte 0
MAC0ACC0_MAC0ACC0__SHIFT EQU 000H ; MAC0 Accumulator Byte 0
                                                           
;------------------------------------------------------------------------------
; MAC0ACC1 Enums (Accumulator Byte 1 @ 0x94)
;------------------------------------------------------------------------------
MAC0ACC1_MAC0ACC1__FMASK EQU 0FFH ; MAC0 Accumulator Byte 1
MAC0ACC1_MAC0ACC1__SHIFT EQU 000H ; MAC0 Accumulator Byte 1
                                                           
;------------------------------------------------------------------------------
; MAC0ACC2 Enums (Accumulator Byte 2 @ 0x95)
;------------------------------------------------------------------------------
MAC0ACC2_MAC0ACC2__FMASK EQU 0FFH ; MAC0 Accumulator Byte 2
MAC0ACC2_MAC0ACC2__SHIFT EQU 000H ; MAC0 Accumulator Byte 2
                                                           
;------------------------------------------------------------------------------
; MAC0ACC3 Enums (Accumulator Byte 3 @ 0x96)
;------------------------------------------------------------------------------
MAC0ACC3_MAC0ACC3__FMASK EQU 0FFH ; MAC0 Accumulator Byte 3
MAC0ACC3_MAC0ACC3__SHIFT EQU 000H ; MAC0 Accumulator Byte 3
                                                           
;------------------------------------------------------------------------------
; MAC0AH Enums (Operand A High Byte @ 0xC2)
;------------------------------------------------------------------------------
MAC0AH_MAC0AH__FMASK EQU 0FFH ; MAC0 A High Byte
MAC0AH_MAC0AH__SHIFT EQU 000H ; MAC0 A High Byte
                                                
;------------------------------------------------------------------------------
; MAC0AL Enums (Operand A Low Byte @ 0xC1)
;------------------------------------------------------------------------------
MAC0AL_MAC0AL__FMASK EQU 0FFH ; MAC0 A Low Byte
MAC0AL_MAC0AL__SHIFT EQU 000H ; MAC0 A Low Byte
                                               
;------------------------------------------------------------------------------
; MAC0BH Enums (Operand B High Byte @ 0x92)
;------------------------------------------------------------------------------
MAC0BH_MAC0BH__FMASK EQU 0FFH ; MAC0 B High Byte
MAC0BH_MAC0BH__SHIFT EQU 000H ; MAC0 B High Byte
                                                
;------------------------------------------------------------------------------
; MAC0BL Enums (Operand B Low Byte @ 0x91)
;------------------------------------------------------------------------------
MAC0BL_MAC0BL__FMASK EQU 0FFH ; MAC0 B Low Byte
MAC0BL_MAC0BL__SHIFT EQU 000H ; MAC0 B Low Byte
                                               
;------------------------------------------------------------------------------
; MAC0CF Enums (MAC0 Configuration @ 0xC3)
;------------------------------------------------------------------------------
MAC0CF_ACCMD__BMASK       EQU 001H ; Accumulate Mode                                 
MAC0CF_ACCMD__SHIFT       EQU 000H ; Accumulate Mode                                 
MAC0CF_ACCMD__MAC_MODE    EQU 000H ; Select multiply-and-accumulate (MAC) mode.      
MAC0CF_ACCMD__MUL_MODE    EQU 001H ; Select multiply-only mode.                      
                                                                                     
MAC0CF_FRACMD__BMASK      EQU 002H ; Fractional Mode                                 
MAC0CF_FRACMD__SHIFT      EQU 001H ; Fractional Mode                                 
MAC0CF_FRACMD__INT_MODE   EQU 000H ; MAC0 operates in Integer Mode.                  
MAC0CF_FRACMD__FRAC_MODE  EQU 002H ; MAC0 operates in Fractional Mode.               
                                                                                     
MAC0CF_SATURATE__BMASK    EQU 004H ; Saturation Enable                               
MAC0CF_SATURATE__SHIFT    EQU 002H ; Saturation Enable                               
MAC0CF_SATURATE__DISABLED EQU 000H ; Rounded result will not saturate.               
MAC0CF_SATURATE__ENABLED  EQU 004H ; Rounded result will saturate.                   
                                                                                     
MAC0CF_CLRACC__BMASK      EQU 008H ; Clear Accumulator                               
MAC0CF_CLRACC__SHIFT      EQU 003H ; Clear Accumulator                               
MAC0CF_CLRACC__COMPLETED  EQU 000H ; The accumulator clear operation completed.      
MAC0CF_CLRACC__START      EQU 008H ; Clear the accumulator and the related MAC0STA   
                                   ; register flags.                                 
                                                                                     
MAC0CF_SHIFTDIR__BMASK    EQU 010H ; Accumulator Shift Direction                     
MAC0CF_SHIFTDIR__SHIFT    EQU 004H ; Accumulator Shift Direction                     
MAC0CF_SHIFTDIR__LEFT     EQU 000H ; The MAC0 accumulator will be shifted left.      
MAC0CF_SHIFTDIR__RIGHT    EQU 010H ; The MAC0 accumulator will be shifted right.     
                                                                                     
MAC0CF_SHIFTEN__BMASK     EQU 020H ; Accumulator Shift Control                       
MAC0CF_SHIFTEN__SHIFT     EQU 005H ; Accumulator Shift Control                       
MAC0CF_SHIFTEN__COMPLETED EQU 000H ; The shift operation completed.                  
MAC0CF_SHIFTEN__START     EQU 020H ; Shift the accumulator by one bit in the SHIFTDIR
                                   ; direction.                                      
                                                                                     
;------------------------------------------------------------------------------
; MAC0OVR Enums (Accumulator Overflow Byte @ 0x97)
;------------------------------------------------------------------------------
MAC0OVR_MAC0OVF__FMASK EQU 0FFH ; MAC0 Accumulator Overflow Byte
MAC0OVR_MAC0OVF__SHIFT EQU 000H ; MAC0 Accumulator Overflow Byte
                                                                
;------------------------------------------------------------------------------
; MAC0RNDH Enums (Rounded Result High Byte @ 0xCF)
;------------------------------------------------------------------------------
MAC0RNDH_MAC0RND__FMASK EQU 0FFH ; Rounded Result High
MAC0RNDH_MAC0RND__SHIFT EQU 000H ; Rounded Result High
                                                      
;------------------------------------------------------------------------------
; MAC0RNDL Enums (Rounded Result Low Byte @ 0xCE)
;------------------------------------------------------------------------------
MAC0RNDL_MAC0RND__FMASK EQU 0FFH ; Rounded Result Low
MAC0RNDL_MAC0RND__SHIFT EQU 000H ; Rounded Result Low
                                                     
;------------------------------------------------------------------------------
; MAC0STA Enums (MAC0 Status @ 0xC0)
;------------------------------------------------------------------------------
MAC0STA_NEGF__BMASK    EQU 001H ; Negative Flag                                
MAC0STA_NEGF__SHIFT    EQU 000H ; Negative Flag                                
MAC0STA_NEGF__NOT_SET  EQU 000H ; The accumulator result is zero or positive.  
MAC0STA_NEGF__SET      EQU 001H ; The accumulator result is negative.          
                                                                               
MAC0STA_SOVF__BMASK    EQU 002H ; Soft Overflow Flag                           
MAC0STA_SOVF__SHIFT    EQU 001H ; Soft Overflow Flag                           
MAC0STA_SOVF__NOT_SET  EQU 000H ; A soft overflow did not occur.               
MAC0STA_SOVF__SET      EQU 002H ; A soft overflow occurred.                    
                                                                               
MAC0STA_ZEROF__BMASK   EQU 004H ; Zero Flag                                    
MAC0STA_ZEROF__SHIFT   EQU 002H ; Zero Flag                                    
MAC0STA_ZEROF__NOT_SET EQU 000H ; The last operation did not result in an      
                                ; accumulator value of zero.                   
MAC0STA_ZEROF__SET     EQU 004H ; The last operation resulted in an accumulator
                                ; value of zero.                               
                                                                               
MAC0STA_HOVF__BMASK    EQU 008H ; Hard Overflow Flag                           
MAC0STA_HOVF__SHIFT    EQU 003H ; Hard Overflow Flag                           
MAC0STA_HOVF__NOT_SET  EQU 000H ; A hardware overflow did not occur.           
MAC0STA_HOVF__SET      EQU 008H ; A hardware overflow occurred.                
                                                                               
;------------------------------------------------------------------------------
; XBR0 Enums (Port I/O Crossbar 0 @ 0xE1)
;------------------------------------------------------------------------------
XBR0_SMB0EN__BMASK                         EQU 001H ; SMBus0 I/O Enable                                
XBR0_SMB0EN__SHIFT                         EQU 000H ; SMBus0 I/O Enable                                
XBR0_SMB0EN__DISABLED                      EQU 000H ; SMBus0 I/O unavailable at Port pins.             
XBR0_SMB0EN__ENABLED                       EQU 001H ; SMBus0 I/O routed to Port pins.                  
                                                                                                       
XBR0_SPI0EN__BMASK                         EQU 002H ; SPI I/O Enable                                   
XBR0_SPI0EN__SHIFT                         EQU 001H ; SPI I/O Enable                                   
XBR0_SPI0EN__DISABLED                      EQU 000H ; SPI I/O unavailable at Port pins.                
XBR0_SPI0EN__ENABLED                       EQU 002H ; SPI I/O routed to Port pins. The SPI can be      
                                                    ; assigned either 3 or 4 GPIO pins.                
                                                                                                       
XBR0_UART0EN__BMASK                        EQU 004H ; UART I/O Output Enable                           
XBR0_UART0EN__SHIFT                        EQU 002H ; UART I/O Output Enable                           
XBR0_UART0EN__DISABLED                     EQU 000H ; UART I/O unavailable at Port pin.                
XBR0_UART0EN__ENABLED                      EQU 004H ; UART TX, RX routed to Port pins P0.0 and P0.1.   
                                                                                                       
XBR0_PCA0ME__FMASK                         EQU 038H ; PCA Module I/O Enable                            
XBR0_PCA0ME__SHIFT                         EQU 003H ; PCA Module I/O Enable                            
XBR0_PCA0ME__DISABLED                      EQU 000H ; All PCA I/O unavailable at Port pins.            
XBR0_PCA0ME__CEX0                          EQU 008H ; CEX0 routed to Port pin.                         
XBR0_PCA0ME__CEX0_CEX1                     EQU 010H ; CEX0, CEX1 routed to Port pins.                  
XBR0_PCA0ME__CEX0_CEX1_CEX2                EQU 018H ; CEX0, CEX1, CEX2 routed to Port pins.            
XBR0_PCA0ME__CEX0_CEX1_CEX2_CEX3           EQU 020H ; CEX0, CEX1, CEX2, CEX3 routed to Port pins.      
XBR0_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4      EQU 028H ; CEX0, CEX1, CEX2, CEX3, CEX4 routed to Port pins.
XBR0_PCA0ME__CEX0_CEX1_CEX2_CEX3_CEX4_CEX5 EQU 030H ; CEX0, CEX1, CEX2, CEX3, CEX4, CEX5 routed to Port
                                                    ; pins.                                            
                                                                                                       
XBR0_ECI0E__BMASK                          EQU 040H ; PCA0 External Counter Input Enable               
XBR0_ECI0E__SHIFT                          EQU 006H ; PCA0 External Counter Input Enable               
XBR0_ECI0E__DISABLED                       EQU 000H ; ECI unavailable at Port pin.                     
XBR0_ECI0E__ENABLED                        EQU 040H ; ECI routed to Port pin.                          
                                                                                                       
XBR0_CP0E__BMASK                           EQU 080H ; Comparator0 Output Enable                        
XBR0_CP0E__SHIFT                           EQU 007H ; Comparator0 Output Enable                        
XBR0_CP0E__DISABLED                        EQU 000H ; CP0 unavailable at Port pin.                     
XBR0_CP0E__ENABLED                         EQU 080H ; CP0 routed to Port pin.                          
                                                                                                       
;------------------------------------------------------------------------------
; XBR1 Enums (Port I/O Crossbar 1 @ 0xE2)
;------------------------------------------------------------------------------
XBR1_CP1E__BMASK      EQU 001H ; Comparator1 Output Enable        
XBR1_CP1E__SHIFT      EQU 000H ; Comparator1 Output Enable        
XBR1_CP1E__DISABLED   EQU 000H ; CP1 unavailable at Port pin.     
XBR1_CP1E__ENABLED    EQU 001H ; CP1 routed to Port pin.          
                                                                  
XBR1_T0E__BMASK       EQU 002H ; T0 Enable                        
XBR1_T0E__SHIFT       EQU 001H ; T0 Enable                        
XBR1_T0E__DISABLED    EQU 000H ; T0 unavailable at Port pin.      
XBR1_T0E__ENABLED     EQU 002H ; T0 routed to Port pin.           
                                                                  
XBR1_INT0E__BMASK     EQU 004H ; /INT0 Input Enable               
XBR1_INT0E__SHIFT     EQU 002H ; /INT0 Input Enable               
XBR1_INT0E__DISABLED  EQU 000H ; /INT0 unavailable at Port pin.   
XBR1_INT0E__ENABLED   EQU 004H ; /INT0 routed to Port pin.        
                                                                  
XBR1_T1E__BMASK       EQU 008H ; T1 Enable                        
XBR1_T1E__SHIFT       EQU 003H ; T1 Enable                        
XBR1_T1E__DISABLED    EQU 000H ; T1 unavailable at Port pin.      
XBR1_T1E__ENABLED     EQU 008H ; T1 routed to Port pin.           
                                                                  
XBR1_INT1E__BMASK     EQU 010H ; /INT1 Input Enable               
XBR1_INT1E__SHIFT     EQU 004H ; /INT1 Input Enable               
XBR1_INT1E__DISABLED  EQU 000H ; /INT1 unavailable at Port pin.   
XBR1_INT1E__ENABLED   EQU 010H ; /INT1 routed to Port pin.        
                                                                  
XBR1_T2E__BMASK       EQU 020H ; T2 Enable                        
XBR1_T2E__SHIFT       EQU 005H ; T2 Enable                        
XBR1_T2E__DISABLED    EQU 000H ; T2 unavailable at Port pin.      
XBR1_T2E__ENABLED     EQU 020H ; T2 routed to Port pin.           
                                                                  
XBR1_T2EXE__BMASK     EQU 040H ; T2EX Input Enable                
XBR1_T2EXE__SHIFT     EQU 006H ; T2EX Input Enable                
XBR1_T2EXE__DISABLED  EQU 000H ; T2EX unavailable at Port pin.    
XBR1_T2EXE__ENABLED   EQU 040H ; T2EX routed to Port pin.         
                                                                  
XBR1_SYSCKE__BMASK    EQU 080H ; SYSCLK Output Enable             
XBR1_SYSCKE__SHIFT    EQU 007H ; SYSCLK Output Enable             
XBR1_SYSCKE__DISABLED EQU 000H ; SYSCLK unavailable at Port pin.  
XBR1_SYSCKE__ENABLED  EQU 080H ; SYSCLK output routed to Port pin.
                                                                  
;------------------------------------------------------------------------------
; XBR2 Enums (Port I/O Crossbar 2 @ 0xE3)
;------------------------------------------------------------------------------
XBR2_CNVST0E__BMASK             EQU 001H ; ADC0 External Convert Start Input Enable          
XBR2_CNVST0E__SHIFT             EQU 000H ; ADC0 External Convert Start Input Enable          
XBR2_CNVST0E__DISABLED          EQU 000H ; CNVSTR0 for ADC0 unavailable at Port pin.         
XBR2_CNVST0E__ENABLED           EQU 001H ; CNVSTR0 for ADC0 routed to Port pin.              
                                                                                             
XBR2_EMIFLE__BMASK              EQU 002H ; External Memory Interface Low-Port Enable         
XBR2_EMIFLE__SHIFT              EQU 001H ; External Memory Interface Low-Port Enable         
XBR2_EMIFLE__DISABLED           EQU 000H ; P0.7, P0.6, and P0.5 functions are determined by  
                                         ; the Crossbar or the Port latches.                 
XBR2_EMIFLE__ENABLED            EQU 002H ; If EMI0CF.4 = 0 (External Memory Interface is in  
                                         ; Multiplexed mode), P0.7 (/WR), P0.6 (/RD), and    
                                         ; P0.5 (ALE) are skipped by the Crossbar and their  
                                         ; output states are determined by the Port latches  
                                         ; and the External Memory Interface. If EMI0CF.4 = 1
                                         ; (External Memory Interface is in Non-multiplexed  
                                         ; mode), P0.7 (/WR) and P0.6 (/RD) are skipped by   
                                         ; the Crossbar and their output.                    
                                                                                             
XBR2_UART1E__BMASK              EQU 004H ; UART I/O Output Enable                            
XBR2_UART1E__SHIFT              EQU 002H ; UART I/O Output Enable                            
XBR2_UART1E__DISABLED           EQU 000H ; UART I/O unavailable at Port pin.                 
XBR2_UART1E__ENABLED            EQU 004H ; UART TX, RX routed to Port pins.                  
                                                                                             
XBR2_T4E__BMASK                 EQU 008H ; T4 Enable                                         
XBR2_T4E__SHIFT                 EQU 003H ; T4 Enable                                         
XBR2_T4E__DISABLED              EQU 000H ; T4 unavailable at Port pin.                       
XBR2_T4E__ENABLED               EQU 008H ; T4 routed to Port pin.                            
                                                                                             
XBR2_T4EXE__BMASK               EQU 010H ; T4EX Input Enable                                 
XBR2_T4EXE__SHIFT               EQU 004H ; T4EX Input Enable                                 
XBR2_T4EXE__DISABLED            EQU 000H ; T4EX unavailable at Port pin.                     
XBR2_T4EXE__ENABLED             EQU 010H ; T4EX routed to Port pin.                          
                                                                                             
XBR2_CNVST2E__BMASK             EQU 020H ; ADC2 External Convert Start Input Enable          
XBR2_CNVST2E__SHIFT             EQU 005H ; ADC2 External Convert Start Input Enable          
XBR2_CNVST2E__DISABLED          EQU 000H ; CNVSTR2 for ADC2 unavailable at Port pin.         
XBR2_CNVST2E__ENABLED           EQU 020H ; CNVSTR2 for ADC2 routed to Port pin.              
                                                                                             
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
PCA0CPM0_PWM16__8_BIT   EQU 000H ; 8-bit PWM selected.                            
PCA0CPM0_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
;------------------------------------------------------------------------------
; PCA0CPH1 Enums (PCA Channel 1 Capture Module High Byte @ 0xFE)
;------------------------------------------------------------------------------
PCA0CPH1_PCA0CPH1__FMASK EQU 0FFH ; PCA Channel 1 Capture Module High Byte
PCA0CPH1_PCA0CPH1__SHIFT EQU 000H ; PCA Channel 1 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPL1 Enums (PCA Channel 1 Capture Module Low Byte @ 0xFD)
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
PCA0CPM1_PWM16__8_BIT   EQU 000H ; 8-bit PWM selected.                            
PCA0CPM1_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
;------------------------------------------------------------------------------
; PCA0CPH2 Enums (PCA Channel 2 Capture Module High Byte @ 0xEA)
;------------------------------------------------------------------------------
PCA0CPH2_PCA0CPH2__FMASK EQU 0FFH ; PCA Channel 2 Capture Module High Byte
PCA0CPH2_PCA0CPH2__SHIFT EQU 000H ; PCA Channel 2 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPL2 Enums (PCA Channel 2 Capture Module Low Byte @ 0xE9)
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
PCA0CPM2_PWM16__8_BIT   EQU 000H ; 8-bit PWM selected.                            
PCA0CPM2_PWM16__16_BIT  EQU 080H ; 16-bit PWM selected.                           
                                                                                  
;------------------------------------------------------------------------------
; PCA0CPH3 Enums (PCA Channel 3 Capture Module High Byte @ 0xEC)
;------------------------------------------------------------------------------
PCA0CPH3_PCA0CPH3__FMASK EQU 0FFH ; PCA Channel 3 Capture Module High Byte
PCA0CPH3_PCA0CPH3__SHIFT EQU 000H ; PCA Channel 3 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPL3 Enums (PCA Channel 3 Capture Module Low Byte @ 0xEB)
;------------------------------------------------------------------------------
PCA0CPL3_PCA0CPL3__FMASK EQU 0FFH ; PCA Channel 3 Capture Module Low Byte
PCA0CPL3_PCA0CPL3__SHIFT EQU 000H ; PCA Channel 3 Capture Module Low Byte
                                                                         
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
; PCA0CPH4 Enums (PCA Channel 4 Capture Module High Byte @ 0xEE)
;------------------------------------------------------------------------------
PCA0CPH4_PCA0CPH4__FMASK EQU 0FFH ; PCA Channel 4 Capture Module High Byte
PCA0CPH4_PCA0CPH4__SHIFT EQU 000H ; PCA Channel 4 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPL4 Enums (PCA Channel 4 Capture Module Low Byte @ 0xED)
;------------------------------------------------------------------------------
PCA0CPL4_PCA0CPL4__FMASK EQU 0FFH ; PCA Channel 4 Capture Module Low Byte
PCA0CPL4_PCA0CPL4__SHIFT EQU 000H ; PCA Channel 4 Capture Module Low Byte
                                                                         
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
; PCA0CPH5 Enums (PCA Channel 5 Capture Module High Byte @ 0xE2)
;------------------------------------------------------------------------------
PCA0CPH5_PCA0CPH5__FMASK EQU 0FFH ; PCA Channel 5 Capture Module High Byte
PCA0CPH5_PCA0CPH5__SHIFT EQU 000H ; PCA Channel 5 Capture Module High Byte
                                                                          
;------------------------------------------------------------------------------
; PCA0CPL5 Enums (PCA Channel 5 Capture Module Low Byte @ 0xE1)
;------------------------------------------------------------------------------
PCA0CPL5_PCA0CPL5__FMASK EQU 0FFH ; PCA Channel 5 Capture Module Low Byte
PCA0CPL5_PCA0CPL5__SHIFT EQU 000H ; PCA Channel 5 Capture Module Low Byte
                                                                         
;------------------------------------------------------------------------------
; PCA0CPM5 Enums (PCA Channel 5 Capture/Compare Mode @ 0xDF)
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
                                                                                          
PCA0MD_CIDL__BMASK           EQU 080H ; PCA Counter/Timer Idle Control                    
PCA0MD_CIDL__SHIFT           EQU 007H ; PCA Counter/Timer Idle Control                    
PCA0MD_CIDL__NORMAL          EQU 000H ; PCA continues to function normally while the      
                                      ; system controller is in Idle Mode.                
PCA0MD_CIDL__SUSPEND         EQU 080H ; PCA operation is suspended while the system       
                                      ; controller is in Idle Mode.                       
                                                                                          
;------------------------------------------------------------------------------
; PLL0CN Enums (PLL Control @ 0x89)
;------------------------------------------------------------------------------
PLL0CN_PLLPWR__BMASK      EQU 001H ; Power Enable                                    
PLL0CN_PLLPWR__SHIFT      EQU 000H ; Power Enable                                    
PLL0CN_PLLPWR__DISABLED   EQU 000H ; Disable the PLL bias generator. The PLL does not
                                   ; consume any static power.                       
PLL0CN_PLLPWR__ENABLED    EQU 001H ; Enable the PLL bias generator.                  
                                                                                     
PLL0CN_PLLEN__BMASK       EQU 002H ; PLL Enable                                      
PLL0CN_PLLEN__SHIFT       EQU 001H ; PLL Enable                                      
PLL0CN_PLLEN__DISABLED    EQU 000H ; PLL is held in reset.                           
PLL0CN_PLLEN__ENABLED     EQU 002H ; PLL is enabled.                                 
                                                                                     
PLL0CN_PLLSRC__BMASK      EQU 004H ; Reference Clock Source Select                   
PLL0CN_PLLSRC__SHIFT      EQU 002H ; Reference Clock Source Select                   
PLL0CN_PLLSRC__HFOSC      EQU 000H ; PLL reference clock source is the internal High-
                                   ; Frequency Oscillator.                           
PLL0CN_PLLSRC__EXTOSC     EQU 004H ; PLL reference clock source is the external      
                                   ; oscillator.                                     
                                                                                     
PLL0CN_PLLLCK__BMASK      EQU 010H ; Lock Flag                                       
PLL0CN_PLLLCK__SHIFT      EQU 004H ; Lock Flag                                       
PLL0CN_PLLLCK__NOT_LOCKED EQU 000H ; PLL output frequency is not locked.             
PLL0CN_PLLLCK__LOCKED     EQU 010H ; PLL output frequency is locked.                 
                                                                                     
;------------------------------------------------------------------------------
; PLL0DIV Enums (PLL Divider @ 0x8D)
;------------------------------------------------------------------------------
PLL0DIV_PLLM__FMASK EQU 01FH ; PLL Reference Clock Divider
PLL0DIV_PLLM__SHIFT EQU 000H ; PLL Reference Clock Divider
                                                          
;------------------------------------------------------------------------------
; PLL0FLT Enums (PLL Filter @ 0x8F)
;------------------------------------------------------------------------------
PLL0FLT_PLLLP__FMASK                      EQU 00FH ; PLL Loop Filter Control
PLL0FLT_PLLLP__SHIFT                      EQU 000H ; PLL Loop Filter Control
PLL0FLT_PLLLP__DIV_INPUT_19_TO_30_MHZ     EQU 001H ; 19-30 MHz.             
PLL0FLT_PLLLP__DIV_INPUT_12P2_TO_19P5_MHZ EQU 003H ; 12.2-19.5 MHz.         
PLL0FLT_PLLLP__DIV_INPUT_7P8_TO_12P5_MHZ  EQU 007H ; 7.8-12.5 MHz.          
PLL0FLT_PLLLP__DIV_INPUT_5_TO_8_MHZ       EQU 00FH ; 5-8 MHz.               
                                                                            
PLL0FLT_PLLICO__FMASK                     EQU 030H ; PLL Output Range       
PLL0FLT_PLLICO__SHIFT                     EQU 004H ; PLL Output Range       
PLL0FLT_PLLICO__OUTPUT_65_TO_100_MHZ      EQU 000H ; 65-100 MHz.            
PLL0FLT_PLLICO__OUTPUT_45_TO_80_MHZ       EQU 010H ; 45-80 MHz.             
PLL0FLT_PLLICO__OUTPUT_30_TO_60_MHZ       EQU 020H ; 30-60 MHz.             
PLL0FLT_PLLICO__OUTPUT_25_TO_50_MHZ       EQU 030H ; 25-50 MHz.             
                                                                            
;------------------------------------------------------------------------------
; PLL0MUL Enums (PLL Multiplier @ 0x8E)
;------------------------------------------------------------------------------
PLL0MUL_PLLN__FMASK EQU 0FFH ; PLL Multiplier
PLL0MUL_PLLN__SHIFT EQU 000H ; PLL Multiplier
                                             
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
; P1MDIN Enums (Port 1 Input Mode @ 0xAD)
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
; P3 Enums (Port 3 Pin Latch @ 0xB0)
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
; P3MDOUT Enums (Port 3 Output Mode @ 0xA7)
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
; P4 Enums (Port 4 Pin Latch @ 0xC8)
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
; P4MDOUT Enums (Port 4 Output Mode @ 0x9C)
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
; P5 Enums (Port 5 Pin Latch @ 0xD8)
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
                                                                      
P5_B3__BMASK EQU 008H ; Port 5 Bit 3 Latch                            
P5_B3__SHIFT EQU 003H ; Port 5 Bit 3 Latch                            
P5_B3__LOW   EQU 000H ; P5.3 is low. Set P5.3 to drive low.           
P5_B3__HIGH  EQU 008H ; P5.3 is high. Set P5.3 to drive or float high.
                                                                      
P5_B4__BMASK EQU 010H ; Port 5 Bit 4 Latch                            
P5_B4__SHIFT EQU 004H ; Port 5 Bit 4 Latch                            
P5_B4__LOW   EQU 000H ; P5.4 is low. Set P5.4 to drive low.           
P5_B4__HIGH  EQU 010H ; P5.4 is high. Set P5.4 to drive or float high.
                                                                      
P5_B5__BMASK EQU 020H ; Port 5 Bit 5 Latch                            
P5_B5__SHIFT EQU 005H ; Port 5 Bit 5 Latch                            
P5_B5__LOW   EQU 000H ; P5.5 is low. Set P5.5 to drive low.           
P5_B5__HIGH  EQU 020H ; P5.5 is high. Set P5.5 to drive or float high.
                                                                      
P5_B6__BMASK EQU 040H ; Port 5 Bit 6 Latch                            
P5_B6__SHIFT EQU 006H ; Port 5 Bit 6 Latch                            
P5_B6__LOW   EQU 000H ; P5.6 is low. Set P5.6 to drive low.           
P5_B6__HIGH  EQU 040H ; P5.6 is high. Set P5.6 to drive or float high.
                                                                      
P5_B7__BMASK EQU 080H ; Port 5 Bit 7 Latch                            
P5_B7__SHIFT EQU 007H ; Port 5 Bit 7 Latch                            
P5_B7__LOW   EQU 000H ; P5.7 is low. Set P5.7 to drive low.           
P5_B7__HIGH  EQU 080H ; P5.7 is high. Set P5.7 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P5MDOUT Enums (Port 5 Output Mode @ 0x9D)
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
                                                            
P5MDOUT_B3__BMASK      EQU 008H ; Port 5 Bit 3 Output Mode  
P5MDOUT_B3__SHIFT      EQU 003H ; Port 5 Bit 3 Output Mode  
P5MDOUT_B3__OPEN_DRAIN EQU 000H ; P5.3 output is open-drain.
P5MDOUT_B3__PUSH_PULL  EQU 008H ; P5.3 output is push-pull. 
                                                            
P5MDOUT_B4__BMASK      EQU 010H ; Port 5 Bit 4 Output Mode  
P5MDOUT_B4__SHIFT      EQU 004H ; Port 5 Bit 4 Output Mode  
P5MDOUT_B4__OPEN_DRAIN EQU 000H ; P5.4 output is open-drain.
P5MDOUT_B4__PUSH_PULL  EQU 010H ; P5.4 output is push-pull. 
                                                            
P5MDOUT_B5__BMASK      EQU 020H ; Port 5 Bit 5 Output Mode  
P5MDOUT_B5__SHIFT      EQU 005H ; Port 5 Bit 5 Output Mode  
P5MDOUT_B5__OPEN_DRAIN EQU 000H ; P5.5 output is open-drain.
P5MDOUT_B5__PUSH_PULL  EQU 020H ; P5.5 output is push-pull. 
                                                            
P5MDOUT_B6__BMASK      EQU 040H ; Port 5 Bit 6 Output Mode  
P5MDOUT_B6__SHIFT      EQU 006H ; Port 5 Bit 6 Output Mode  
P5MDOUT_B6__OPEN_DRAIN EQU 000H ; P5.6 output is open-drain.
P5MDOUT_B6__PUSH_PULL  EQU 040H ; P5.6 output is push-pull. 
                                                            
P5MDOUT_B7__BMASK      EQU 080H ; Port 5 Bit 7 Output Mode  
P5MDOUT_B7__SHIFT      EQU 007H ; Port 5 Bit 7 Output Mode  
P5MDOUT_B7__OPEN_DRAIN EQU 000H ; P5.7 output is open-drain.
P5MDOUT_B7__PUSH_PULL  EQU 080H ; P5.7 output is push-pull. 
                                                            
;------------------------------------------------------------------------------
; P6 Enums (Port 6 Pin Latch @ 0xE8)
;------------------------------------------------------------------------------
P6_B0__BMASK EQU 001H ; Port 6 Bit 0 Latch                            
P6_B0__SHIFT EQU 000H ; Port 6 Bit 0 Latch                            
P6_B0__LOW   EQU 000H ; P6.0 is low. Set P6.0 to drive low.           
P6_B0__HIGH  EQU 001H ; P6.0 is high. Set P6.0 to drive or float high.
                                                                      
P6_B1__BMASK EQU 002H ; Port 6 Bit 1 Latch                            
P6_B1__SHIFT EQU 001H ; Port 6 Bit 1 Latch                            
P6_B1__LOW   EQU 000H ; P6.1 is low. Set P6.1 to drive low.           
P6_B1__HIGH  EQU 002H ; P6.1 is high. Set P6.1 to drive or float high.
                                                                      
P6_B2__BMASK EQU 004H ; Port 6 Bit 2 Latch                            
P6_B2__SHIFT EQU 002H ; Port 6 Bit 2 Latch                            
P6_B2__LOW   EQU 000H ; P6.2 is low. Set P6.2 to drive low.           
P6_B2__HIGH  EQU 004H ; P6.2 is high. Set P6.2 to drive or float high.
                                                                      
P6_B3__BMASK EQU 008H ; Port 6 Bit 3 Latch                            
P6_B3__SHIFT EQU 003H ; Port 6 Bit 3 Latch                            
P6_B3__LOW   EQU 000H ; P6.3 is low. Set P6.3 to drive low.           
P6_B3__HIGH  EQU 008H ; P6.3 is high. Set P6.3 to drive or float high.
                                                                      
P6_B4__BMASK EQU 010H ; Port 6 Bit 4 Latch                            
P6_B4__SHIFT EQU 004H ; Port 6 Bit 4 Latch                            
P6_B4__LOW   EQU 000H ; P6.4 is low. Set P6.4 to drive low.           
P6_B4__HIGH  EQU 010H ; P6.4 is high. Set P6.4 to drive or float high.
                                                                      
P6_B5__BMASK EQU 020H ; Port 6 Bit 5 Latch                            
P6_B5__SHIFT EQU 005H ; Port 6 Bit 5 Latch                            
P6_B5__LOW   EQU 000H ; P6.5 is low. Set P6.5 to drive low.           
P6_B5__HIGH  EQU 020H ; P6.5 is high. Set P6.5 to drive or float high.
                                                                      
P6_B6__BMASK EQU 040H ; Port 6 Bit 6 Latch                            
P6_B6__SHIFT EQU 006H ; Port 6 Bit 6 Latch                            
P6_B6__LOW   EQU 000H ; P6.6 is low. Set P6.6 to drive low.           
P6_B6__HIGH  EQU 040H ; P6.6 is high. Set P6.6 to drive or float high.
                                                                      
P6_B7__BMASK EQU 080H ; Port 6 Bit 7 Latch                            
P6_B7__SHIFT EQU 007H ; Port 6 Bit 7 Latch                            
P6_B7__LOW   EQU 000H ; P6.7 is low. Set P6.7 to drive low.           
P6_B7__HIGH  EQU 080H ; P6.7 is high. Set P6.7 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P6MDOUT Enums (Port 6 Output Mode @ 0x9E)
;------------------------------------------------------------------------------
P6MDOUT_B0__BMASK      EQU 001H ; Port 6 Bit 0 Output Mode  
P6MDOUT_B0__SHIFT      EQU 000H ; Port 6 Bit 0 Output Mode  
P6MDOUT_B0__OPEN_DRAIN EQU 000H ; P6.0 output is open-drain.
P6MDOUT_B0__PUSH_PULL  EQU 001H ; P6.0 output is push-pull. 
                                                            
P6MDOUT_B1__BMASK      EQU 002H ; Port 6 Bit 1 Output Mode  
P6MDOUT_B1__SHIFT      EQU 001H ; Port 6 Bit 1 Output Mode  
P6MDOUT_B1__OPEN_DRAIN EQU 000H ; P6.1 output is open-drain.
P6MDOUT_B1__PUSH_PULL  EQU 002H ; P6.1 output is push-pull. 
                                                            
P6MDOUT_B2__BMASK      EQU 004H ; Port 6 Bit 2 Output Mode  
P6MDOUT_B2__SHIFT      EQU 002H ; Port 6 Bit 2 Output Mode  
P6MDOUT_B2__OPEN_DRAIN EQU 000H ; P6.2 output is open-drain.
P6MDOUT_B2__PUSH_PULL  EQU 004H ; P6.2 output is push-pull. 
                                                            
P6MDOUT_B3__BMASK      EQU 008H ; Port 6 Bit 3 Output Mode  
P6MDOUT_B3__SHIFT      EQU 003H ; Port 6 Bit 3 Output Mode  
P6MDOUT_B3__OPEN_DRAIN EQU 000H ; P6.3 output is open-drain.
P6MDOUT_B3__PUSH_PULL  EQU 008H ; P6.3 output is push-pull. 
                                                            
P6MDOUT_B4__BMASK      EQU 010H ; Port 6 Bit 4 Output Mode  
P6MDOUT_B4__SHIFT      EQU 004H ; Port 6 Bit 4 Output Mode  
P6MDOUT_B4__OPEN_DRAIN EQU 000H ; P6.4 output is open-drain.
P6MDOUT_B4__PUSH_PULL  EQU 010H ; P6.4 output is push-pull. 
                                                            
P6MDOUT_B5__BMASK      EQU 020H ; Port 6 Bit 5 Output Mode  
P6MDOUT_B5__SHIFT      EQU 005H ; Port 6 Bit 5 Output Mode  
P6MDOUT_B5__OPEN_DRAIN EQU 000H ; P6.5 output is open-drain.
P6MDOUT_B5__PUSH_PULL  EQU 020H ; P6.5 output is push-pull. 
                                                            
P6MDOUT_B6__BMASK      EQU 040H ; Port 6 Bit 6 Output Mode  
P6MDOUT_B6__SHIFT      EQU 006H ; Port 6 Bit 6 Output Mode  
P6MDOUT_B6__OPEN_DRAIN EQU 000H ; P6.6 output is open-drain.
P6MDOUT_B6__PUSH_PULL  EQU 040H ; P6.6 output is push-pull. 
                                                            
P6MDOUT_B7__BMASK      EQU 080H ; Port 6 Bit 7 Output Mode  
P6MDOUT_B7__SHIFT      EQU 007H ; Port 6 Bit 7 Output Mode  
P6MDOUT_B7__OPEN_DRAIN EQU 000H ; P6.7 output is open-drain.
P6MDOUT_B7__PUSH_PULL  EQU 080H ; P6.7 output is push-pull. 
                                                            
;------------------------------------------------------------------------------
; P7 Enums (Port 7 Pin Latch @ 0xF8)
;------------------------------------------------------------------------------
P7_B0__BMASK EQU 001H ; Port 7 Bit 0 Latch                            
P7_B0__SHIFT EQU 000H ; Port 7 Bit 0 Latch                            
P7_B0__LOW   EQU 000H ; P7.0 is low. Set P7.0 to drive low.           
P7_B0__HIGH  EQU 001H ; P7.0 is high. Set P7.0 to drive or float high.
                                                                      
P7_B1__BMASK EQU 002H ; Port 7 Bit 1 Latch                            
P7_B1__SHIFT EQU 001H ; Port 7 Bit 1 Latch                            
P7_B1__LOW   EQU 000H ; P7.1 is low. Set P7.1 to drive low.           
P7_B1__HIGH  EQU 002H ; P7.1 is high. Set P7.1 to drive or float high.
                                                                      
P7_B2__BMASK EQU 004H ; Port 7 Bit 2 Latch                            
P7_B2__SHIFT EQU 002H ; Port 7 Bit 2 Latch                            
P7_B2__LOW   EQU 000H ; P7.2 is low. Set P7.2 to drive low.           
P7_B2__HIGH  EQU 004H ; P7.2 is high. Set P7.2 to drive or float high.
                                                                      
P7_B3__BMASK EQU 008H ; Port 7 Bit 3 Latch                            
P7_B3__SHIFT EQU 003H ; Port 7 Bit 3 Latch                            
P7_B3__LOW   EQU 000H ; P7.3 is low. Set P7.3 to drive low.           
P7_B3__HIGH  EQU 008H ; P7.3 is high. Set P7.3 to drive or float high.
                                                                      
P7_B4__BMASK EQU 010H ; Port 7 Bit 4 Latch                            
P7_B4__SHIFT EQU 004H ; Port 7 Bit 4 Latch                            
P7_B4__LOW   EQU 000H ; P7.4 is low. Set P7.4 to drive low.           
P7_B4__HIGH  EQU 010H ; P7.4 is high. Set P7.4 to drive or float high.
                                                                      
P7_B5__BMASK EQU 020H ; Port 7 Bit 5 Latch                            
P7_B5__SHIFT EQU 005H ; Port 7 Bit 5 Latch                            
P7_B5__LOW   EQU 000H ; P7.5 is low. Set P7.5 to drive low.           
P7_B5__HIGH  EQU 020H ; P7.5 is high. Set P7.5 to drive or float high.
                                                                      
P7_B6__BMASK EQU 040H ; Port 7 Bit 6 Latch                            
P7_B6__SHIFT EQU 006H ; Port 7 Bit 6 Latch                            
P7_B6__LOW   EQU 000H ; P7.6 is low. Set P7.6 to drive low.           
P7_B6__HIGH  EQU 040H ; P7.6 is high. Set P7.6 to drive or float high.
                                                                      
P7_B7__BMASK EQU 080H ; Port 7 Bit 7 Latch                            
P7_B7__SHIFT EQU 007H ; Port 7 Bit 7 Latch                            
P7_B7__LOW   EQU 000H ; P7.7 is low. Set P7.7 to drive low.           
P7_B7__HIGH  EQU 080H ; P7.7 is high. Set P7.7 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P7MDOUT Enums (Port 7 Output Mode @ 0x9F)
;------------------------------------------------------------------------------
P7MDOUT_B0__BMASK      EQU 001H ; Port 7 Bit 0 Output Mode  
P7MDOUT_B0__SHIFT      EQU 000H ; Port 7 Bit 0 Output Mode  
P7MDOUT_B0__OPEN_DRAIN EQU 000H ; P7.0 output is open-drain.
P7MDOUT_B0__PUSH_PULL  EQU 001H ; P7.0 output is push-pull. 
                                                            
P7MDOUT_B1__BMASK      EQU 002H ; Port 7 Bit 1 Output Mode  
P7MDOUT_B1__SHIFT      EQU 001H ; Port 7 Bit 1 Output Mode  
P7MDOUT_B1__OPEN_DRAIN EQU 000H ; P7.1 output is open-drain.
P7MDOUT_B1__PUSH_PULL  EQU 002H ; P7.1 output is push-pull. 
                                                            
P7MDOUT_B2__BMASK      EQU 004H ; Port 7 Bit 2 Output Mode  
P7MDOUT_B2__SHIFT      EQU 002H ; Port 7 Bit 2 Output Mode  
P7MDOUT_B2__OPEN_DRAIN EQU 000H ; P7.2 output is open-drain.
P7MDOUT_B2__PUSH_PULL  EQU 004H ; P7.2 output is push-pull. 
                                                            
P7MDOUT_B3__BMASK      EQU 008H ; Port 7 Bit 3 Output Mode  
P7MDOUT_B3__SHIFT      EQU 003H ; Port 7 Bit 3 Output Mode  
P7MDOUT_B3__OPEN_DRAIN EQU 000H ; P7.3 output is open-drain.
P7MDOUT_B3__PUSH_PULL  EQU 008H ; P7.3 output is push-pull. 
                                                            
P7MDOUT_B4__BMASK      EQU 010H ; Port 7 Bit 4 Output Mode  
P7MDOUT_B4__SHIFT      EQU 004H ; Port 7 Bit 4 Output Mode  
P7MDOUT_B4__OPEN_DRAIN EQU 000H ; P7.4 output is open-drain.
P7MDOUT_B4__PUSH_PULL  EQU 010H ; P7.4 output is push-pull. 
                                                            
P7MDOUT_B5__BMASK      EQU 020H ; Port 7 Bit 5 Output Mode  
P7MDOUT_B5__SHIFT      EQU 005H ; Port 7 Bit 5 Output Mode  
P7MDOUT_B5__OPEN_DRAIN EQU 000H ; P7.5 output is open-drain.
P7MDOUT_B5__PUSH_PULL  EQU 020H ; P7.5 output is push-pull. 
                                                            
P7MDOUT_B6__BMASK      EQU 040H ; Port 7 Bit 6 Output Mode  
P7MDOUT_B6__SHIFT      EQU 006H ; Port 7 Bit 6 Output Mode  
P7MDOUT_B6__OPEN_DRAIN EQU 000H ; P7.6 output is open-drain.
P7MDOUT_B6__PUSH_PULL  EQU 040H ; P7.6 output is push-pull. 
                                                            
P7MDOUT_B7__BMASK      EQU 080H ; Port 7 Bit 7 Output Mode  
P7MDOUT_B7__SHIFT      EQU 007H ; Port 7 Bit 7 Output Mode  
P7MDOUT_B7__OPEN_DRAIN EQU 000H ; P7.7 output is open-drain.
P7MDOUT_B7__PUSH_PULL  EQU 080H ; P7.7 output is push-pull. 
                                                            
;------------------------------------------------------------------------------
; RSTSRC Enums (Reset Source @ 0xEF)
;------------------------------------------------------------------------------
RSTSRC_PINRSF__BMASK    EQU 001H ; HW Pin Reset Flag                                                    
RSTSRC_PINRSF__SHIFT    EQU 000H ; HW Pin Reset Flag                                                    
RSTSRC_PINRSF__NOT_SET  EQU 000H ; The /RST pin did not cause the last reset.                           
RSTSRC_PINRSF__SET      EQU 001H ; The /RST pin caused the last reset.                                  
                                                                                                        
RSTSRC_PORSF__BMASK     EQU 002H ; Power-On / Supply Monitor Reset Flag, and Supply Monitor Reset Enable
RSTSRC_PORSF__SHIFT     EQU 001H ; Power-On / Supply Monitor Reset Flag, and Supply Monitor Reset Enable
RSTSRC_PORSF__NOT_SET   EQU 000H ; A power-on or supply monitor reset did not occur.                    
RSTSRC_PORSF__SET       EQU 002H ; A power-on or supply monitor reset occurred.                         
                                                                                                        
RSTSRC_MCDRSF__BMASK    EQU 004H ; Missing Clock Detector Enable and Flag                               
RSTSRC_MCDRSF__SHIFT    EQU 002H ; Missing Clock Detector Enable and Flag                               
RSTSRC_MCDRSF__NOT_SET  EQU 000H ; A missing clock detector reset did not occur.                        
RSTSRC_MCDRSF__SET      EQU 004H ; A missing clock detector reset occurred.                             
                                                                                                        
RSTSRC_WDTRSF__BMASK    EQU 008H ; Watchdog Timer Reset Flag                                            
RSTSRC_WDTRSF__SHIFT    EQU 003H ; Watchdog Timer Reset Flag                                            
RSTSRC_WDTRSF__NOT_SET  EQU 000H ; A watchdog timer overflow reset did not occur.                       
RSTSRC_WDTRSF__SET      EQU 008H ; A watchdog timer overflow reset occurred.                            
                                                                                                        
RSTSRC_SWRSF__BMASK     EQU 010H ; Software Reset Force and Flag                                        
RSTSRC_SWRSF__SHIFT     EQU 004H ; Software Reset Force and Flag                                        
RSTSRC_SWRSF__NOT_SET   EQU 000H ; A software reset did not occur.                                      
RSTSRC_SWRSF__SET       EQU 010H ; A software reset occurred.                                           
                                                                                                        
RSTSRC_C0RSEF__BMASK    EQU 020H ; Comparator0 Reset Enable and Flag                                    
RSTSRC_C0RSEF__SHIFT    EQU 005H ; Comparator0 Reset Enable and Flag                                    
RSTSRC_C0RSEF__NOT_SET  EQU 000H ; A Comparator 0 reset did not occur.                                  
RSTSRC_C0RSEF__SET      EQU 020H ; A Comparator 0 reset occurred.                                       
                                                                                                        
RSTSRC_CNVRSEF__BMASK   EQU 040H ; Convert Start 0 Reset Source Enable and Flag                         
RSTSRC_CNVRSEF__SHIFT   EQU 006H ; Convert Start 0 Reset Source Enable and Flag                         
RSTSRC_CNVRSEF__NOT_SET EQU 000H ; A CNVSTR0 reset did not occur.                                       
RSTSRC_CNVRSEF__SET     EQU 040H ; A CNVSTR0 reset occurred.                                            
                                                                                                        
RSTSRC_RTC0RE__BMASK    EQU 080H ; RTC Reset Enable and Flag                                            
RSTSRC_RTC0RE__SHIFT    EQU 007H ; RTC Reset Enable and Flag                                            
RSTSRC_RTC0RE__NOT_SET  EQU 000H ; A RTC alarm or oscillator fail reset did not                         
                                 ; occur.                                                               
RSTSRC_RTC0RE__SET      EQU 080H ; A RTC alarm or oscillator fail reset occurred.                       
                                                                                                        
;------------------------------------------------------------------------------
; SFRLAST Enums (SFR Page Last @ 0x86)
;------------------------------------------------------------------------------
SFRLAST_SFRLAST__FMASK EQU 0FFH ; SFR Page Last
SFRLAST_SFRLAST__SHIFT EQU 000H ; SFR Page Last
                                               
;------------------------------------------------------------------------------
; SFRNEXT Enums (SFR Page Next @ 0x85)
;------------------------------------------------------------------------------
SFRNEXT_SFRNEXT__FMASK EQU 0FFH ; SFR Page Next
SFRNEXT_SFRNEXT__SHIFT EQU 000H ; SFR Page Next
                                               
;------------------------------------------------------------------------------
; SFRPAGE Enums (SFR Page @ 0x84)
;------------------------------------------------------------------------------
SFRPAGE_SFRPAGE__FMASK EQU 0FFH ; SFR Page
SFRPAGE_SFRPAGE__SHIFT EQU 000H ; SFR Page
                                          
;------------------------------------------------------------------------------
; SFRPGCN Enums (SFR Page Control @ 0x96)
;------------------------------------------------------------------------------
SFRPGCN_SFRPGEN__BMASK    EQU 001H ; SFR Automatic Page Control Enable
SFRPGCN_SFRPGEN__SHIFT    EQU 000H ; SFR Automatic Page Control Enable
SFRPGCN_SFRPGEN__DISABLED EQU 000H ; Disable automatic SFR paging.    
SFRPGCN_SFRPGEN__ENABLED  EQU 001H ; Enable automatic SFR paging.     
                                                                      
;------------------------------------------------------------------------------
; SMB0ADR Enums (SMBus 0 Address @ 0xC3)
;------------------------------------------------------------------------------
SMB0ADR_GC__BMASK      EQU 001H ; General Call Address Enable        
SMB0ADR_GC__SHIFT      EQU 000H ; General Call Address Enable        
SMB0ADR_GC__IGNORED    EQU 000H ; General Call Address is ignored.   
SMB0ADR_GC__RECOGNIZED EQU 001H ; General Call Address is recognized.
                                                                     
SMB0ADR_SLV__FMASK     EQU 0FEH ; SMBus Slave Address                
SMB0ADR_SLV__SHIFT     EQU 001H ; SMBus Slave Address                
                                                                     
;------------------------------------------------------------------------------
; SMB0CN Enums (SMBus 0 Control @ 0xC0)
;------------------------------------------------------------------------------
SMB0CN_TOE__BMASK            EQU 001H ; SMBus Timeout Enable                              
SMB0CN_TOE__SHIFT            EQU 000H ; SMBus Timeout Enable                              
SMB0CN_TOE__SCL_TO_DISABLED  EQU 000H ; No timeout when SCL is low.                       
SMB0CN_TOE__SCL_TO_ENABLED   EQU 001H ; Timeout when SCL low time exceeds limit specified 
                                      ; by Timer 3, if enabled.                           
                                                                                          
SMB0CN_FTE__BMASK            EQU 002H ; SMBus Free Timer Enable                           
SMB0CN_FTE__SHIFT            EQU 001H ; SMBus Free Timer Enable                           
SMB0CN_FTE__FREE_TO_DISABLED EQU 000H ; No timeout when SCL is high.                      
SMB0CN_FTE__FREE_TO_ENABLED  EQU 002H ; Timeout when SCL high time exceeds limit specified
                                      ; by the SMBCR value.                               
                                                                                          
SMB0CN_AA__BMASK             EQU 004H ; SMBus Assert Acknowledge Flag                     
SMB0CN_AA__SHIFT             EQU 002H ; SMBus Assert Acknowledge Flag                     
SMB0CN_AA__NOT_SET           EQU 000H ; A "not acknowledge" (high level on SDA) is        
                                      ; returned during the acknowledge cycle.            
SMB0CN_AA__SET               EQU 004H ; An "acknowledge" (low level on SDA) is returned   
                                      ; during the acknowledge cycle.                     
                                                                                          
SMB0CN_SI__BMASK             EQU 008H ; SMBus Acknowledge Request                         
SMB0CN_SI__SHIFT             EQU 003H ; SMBus Acknowledge Request                         
SMB0CN_SI__NOT_SET           EQU 000H ; An SMBus interrupt did not occur.                 
SMB0CN_SI__SET               EQU 008H ; An SMBus interrupt occurred.                      
                                                                                          
SMB0CN_STO__BMASK            EQU 010H ; SMBus Stop Flag                                   
SMB0CN_STO__SHIFT            EQU 004H ; SMBus Stop Flag                                   
SMB0CN_STO__NOT_SET          EQU 000H ; No STOP condition is transmitted.                 
SMB0CN_STO__SET              EQU 010H ; Setting STO to logic 1 causes a STOP condition to 
                                      ; be transmitted.                                   
                                                                                          
SMB0CN_STA__BMASK            EQU 020H ; SMBus Start Flag                                  
SMB0CN_STA__SHIFT            EQU 005H ; SMBus Start Flag                                  
SMB0CN_STA__NOT_SET          EQU 000H ; No START condition is transmitted.                
SMB0CN_STA__SET              EQU 020H ; When operating as a master, a START condition is  
                                      ; transmitted if the bus is free. (If the bus is not
                                      ; free, the START is transmitted after a STOP is    
                                      ; received.)                                        
                                                                                          
SMB0CN_ENSMB__BMASK          EQU 040H ; SMBus Enable                                      
SMB0CN_ENSMB__SHIFT          EQU 006H ; SMBus Enable                                      
SMB0CN_ENSMB__DISABLED       EQU 000H ; SMBus 0 disabled.                                 
SMB0CN_ENSMB__ENABLED        EQU 040H ; SMBus 0 enabled.                                  
                                                                                          
SMB0CN_BUSY__BMASK           EQU 080H ; Busy Status Flag                                  
SMB0CN_BUSY__SHIFT           EQU 007H ; Busy Status Flag                                  
SMB0CN_BUSY__NOT_SET         EQU 000H ; SMBus 0 is free.                                  
SMB0CN_BUSY__SET             EQU 080H ; SMBus 0 is busy.                                  
                                                                                          
;------------------------------------------------------------------------------
; SMB0CR Enums (SMBus 0 Clock Rate @ 0xCF)
;------------------------------------------------------------------------------
SMB0CR_SMBCR__FMASK EQU 0FFH ; SMBus0 Clock Rate Preset
SMB0CR_SMBCR__SHIFT EQU 000H ; SMBus0 Clock Rate Preset
                                                       
;------------------------------------------------------------------------------
; SMB0DAT Enums (SMBus 0 Data @ 0xC2)
;------------------------------------------------------------------------------
SMB0DAT_SMB0DAT__FMASK EQU 0FFH ; SMBus 0 Data
SMB0DAT_SMB0DAT__SHIFT EQU 000H ; SMBus 0 Data
                                              
;------------------------------------------------------------------------------
; SMB0STA Enums (SMBus 0 Status @ 0xC1)
;------------------------------------------------------------------------------
SMB0STA_STA__FMASK EQU 0FFH ; SMBus 0 Status
SMB0STA_STA__SHIFT EQU 000H ; SMBus 0 Status
                                            
;------------------------------------------------------------------------------
; SPI0CFG Enums (SPI0 Configuration @ 0x9A)
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
; SPI0CKR Enums (SPI0 Clock Rate @ 0x9D)
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
; SPI0DAT Enums (SPI0 Data @ 0x9B)
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
; RCAP2H Enums (Timer 2 Capture Register High Byte @ 0xCB)
;------------------------------------------------------------------------------
RCAP2H_RCAP2L__FMASK EQU 0FFH ; Timer 2 Capture Register High Byte
RCAP2H_RCAP2L__SHIFT EQU 000H ; Timer 2 Capture Register High Byte
                                                                  
;------------------------------------------------------------------------------
; RCAP2L Enums (Timer 2 Capture Register Low Byte @ 0xCA)
;------------------------------------------------------------------------------
RCAP2L_RCAP2L__FMASK EQU 0FFH ; Timer 2 Capture Register Low Byte
RCAP2L_RCAP2L__SHIFT EQU 000H ; Timer 2 Capture Register Low Byte
                                                                 
;------------------------------------------------------------------------------
; TMR2CF Enums (Timer 2 Configuration @ 0xC9)
;------------------------------------------------------------------------------
TMR2CF_DCEN2__BMASK          EQU 001H ; Decrement Enable                                  
TMR2CF_DCEN2__SHIFT          EQU 000H ; Decrement Enable                                  
TMR2CF_DCEN2__DISABLED       EQU 000H ; Timer will count up, regardless of the state of   
                                      ; T2EX.                                             
TMR2CF_DCEN2__ENABLED        EQU 001H ; Timer will count up or down depending on the state
                                      ; of T2EX as follows: if T2EX = 0, the timer counts 
                                      ; DOWN; if T2EX = 1, the timer counts UP.           
                                                                                          
TMR2CF_T2OE__BMASK           EQU 002H ; Timer Output Enable                               
TMR2CF_T2OE__SHIFT           EQU 001H ; Timer Output Enable                               
TMR2CF_T2OE__OUTPUT_DISABLED EQU 000H ; Output of toggle mode not available at Timer's    
                                      ; assigned port pin.                                
TMR2CF_T2OE__OUTPUT_ENABLED  EQU 002H ; Output of toggle mode available at Timer's        
                                      ; assigned port pin.                                
                                                                                          
TMR2CF_TOG2__BMASK           EQU 004H ; Toggle Output State                               
TMR2CF_TOG2__SHIFT           EQU 002H ; Toggle Output State                               
TMR2CF_TOG2__NOT_SET         EQU 000H ; Timer output is low. Set the timer output low.    
TMR2CF_TOG2__SET             EQU 004H ; Timer output is high. Set the timer output high.  
                                                                                          
TMR2CF_T2M__FMASK            EQU 018H ; Timer Clock Mode Select                           
TMR2CF_T2M__SHIFT            EQU 003H ; Timer Clock Mode Select                           
TMR2CF_T2M__SYSCLK_DIV_12    EQU 000H ; System clock divided by 12.                       
TMR2CF_T2M__SYSCLK           EQU 008H ; System clock.                                     
TMR2CF_T2M__EXTOSC_DIV_8     EQU 010H ; External oscillator divided by 8 (synchronized    
                                      ; with the system clock).                           
TMR2CF_T2M__SYSCLK_DIV_2     EQU 018H ; System clock divided by 2.                        
                                                                                          
;------------------------------------------------------------------------------
; TMR2CN Enums (Timer 2 Control @ 0xC8)
;------------------------------------------------------------------------------
TMR2CN_CPRL2__BMASK       EQU 001H ; Capture/Reload Select                             
TMR2CN_CPRL2__SHIFT       EQU 000H ; Capture/Reload Select                             
TMR2CN_CPRL2__AUTO_RELOAD EQU 000H ; Timer is in Auto-Reload Mode.                     
TMR2CN_CPRL2__CAPTURE     EQU 001H ; Timer is in Capture Mode.                         
                                                                                       
TMR2CN_CT2__BMASK         EQU 002H ; Counter/Timer Select                              
TMR2CN_CT2__SHIFT         EQU 001H ; Counter/Timer Select                              
TMR2CN_CT2__TIMER         EQU 000H ; Timer Function: Timer incremented by clock defined
                                   ; by T2M.                                           
TMR2CN_CT2__COUNTER       EQU 002H ; Counter Function: Timer incremented by high-to-low
                                   ; transitions on external input pin.                
                                                                                       
TMR2CN_TR2__BMASK         EQU 004H ; Timer 2 Run Control                               
TMR2CN_TR2__SHIFT         EQU 002H ; Timer 2 Run Control                               
TMR2CN_TR2__STOP          EQU 000H ; Stop Timer 2.                                     
TMR2CN_TR2__RUN           EQU 004H ; Start Timer 2 running.                            
                                                                                       
TMR2CN_EXEN2__BMASK       EQU 008H ; Timer 2 External Enable                           
TMR2CN_EXEN2__SHIFT       EQU 003H ; Timer 2 External Enable                           
TMR2CN_EXEN2__DISABLED    EQU 000H ; Transitions on the T2EX pin are ignored.          
TMR2CN_EXEN2__ENABLED     EQU 008H ; Transitions on the T2EX pin cause capture, reload,
                                   ; or control the direction of timer count (up or    
                                   ; down).                                            
                                                                                       
TMR2CN_EXF2__BMASK        EQU 040H ; Timer 2 External Flag                             
TMR2CN_EXF2__SHIFT        EQU 006H ; Timer 2 External Flag                             
TMR2CN_EXF2__NOT_SET      EQU 000H ; Timer 2 capture or reload did not occur.          
TMR2CN_EXF2__SET          EQU 040H ; Timer 2 capture or reload occurred.               
                                                                                       
TMR2CN_TF2__BMASK         EQU 080H ; Timer 2 Overflow/Underflow Flag                   
TMR2CN_TF2__SHIFT         EQU 007H ; Timer 2 Overflow/Underflow Flag                   
TMR2CN_TF2__NOT_SET       EQU 000H ; Timer 2 did not overflow or underflow.            
TMR2CN_TF2__SET           EQU 080H ; Timer 2 overflowed or underflowed.                
                                                                                       
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
; RCAP3H Enums (Timer 3 Capture Register High Byte @ 0xCB)
;------------------------------------------------------------------------------
RCAP3H_RCAP3L__FMASK EQU 0FFH ; Timer 3 Capture Register High Byte
RCAP3H_RCAP3L__SHIFT EQU 000H ; Timer 3 Capture Register High Byte
                                                                  
;------------------------------------------------------------------------------
; RCAP3L Enums (Timer 3 Capture Register Low Byte @ 0xCA)
;------------------------------------------------------------------------------
RCAP3L_RCAP3L__FMASK EQU 0FFH ; Timer 3 Capture Register Low Byte
RCAP3L_RCAP3L__SHIFT EQU 000H ; Timer 3 Capture Register Low Byte
                                                                 
;------------------------------------------------------------------------------
; TMR3CF Enums (Timer 3 Configuration @ 0xC9)
;------------------------------------------------------------------------------
TMR3CF_DCEN3__BMASK          EQU 001H ; Decrement Enable                                  
TMR3CF_DCEN3__SHIFT          EQU 000H ; Decrement Enable                                  
TMR3CF_DCEN3__DISABLED       EQU 000H ; Timer will count up, regardless of the state of   
                                      ; T3EX.                                             
TMR3CF_DCEN3__ENABLED        EQU 001H ; Timer will count up or down depending on the state
                                      ; of T3EX as follows: if T3EX = 0, the timer counts 
                                      ; DOWN; if T3EX = 1, the timer counts UP.           
                                                                                          
TMR3CF_T3OE__BMASK           EQU 002H ; Timer Output Enable                               
TMR3CF_T3OE__SHIFT           EQU 001H ; Timer Output Enable                               
TMR3CF_T3OE__OUTPUT_DISABLED EQU 000H ; Output of toggle mode not available at Timer's    
                                      ; assigned port pin.                                
TMR3CF_T3OE__OUTPUT_ENABLED  EQU 002H ; Output of toggle mode available at Timer's        
                                      ; assigned port pin.                                
                                                                                          
TMR3CF_TOG3__BMASK           EQU 004H ; Toggle Output State                               
TMR3CF_TOG3__SHIFT           EQU 002H ; Toggle Output State                               
TMR3CF_TOG3__NOT_SET         EQU 000H ; Timer output is low. Set the timer output low.    
TMR3CF_TOG3__SET             EQU 004H ; Timer output is high. Set the timer output high.  
                                                                                          
TMR3CF_T3M__FMASK            EQU 018H ; Timer Clock Mode Select                           
TMR3CF_T3M__SHIFT            EQU 003H ; Timer Clock Mode Select                           
TMR3CF_T3M__SYSCLK_DIV_12    EQU 000H ; System clock divided by 12.                       
TMR3CF_T3M__SYSCLK           EQU 008H ; System clock.                                     
TMR3CF_T3M__EXTOSC_DIV_8     EQU 010H ; External oscillator divided by 8 (synchronized    
                                      ; with the system clock).                           
TMR3CF_T3M__SYSCLK_DIV_2     EQU 018H ; System clock divided by 2.                        
                                                                                          
;------------------------------------------------------------------------------
; TMR3CN Enums (Timer 3 Control @ 0xC8)
;------------------------------------------------------------------------------
TMR3CN_CPRL3__BMASK       EQU 001H ; Capture/Reload Select                             
TMR3CN_CPRL3__SHIFT       EQU 000H ; Capture/Reload Select                             
TMR3CN_CPRL3__AUTO_RELOAD EQU 000H ; Timer is in Auto-Reload Mode.                     
TMR3CN_CPRL3__CAPTURE     EQU 001H ; Timer is in Capture Mode.                         
                                                                                       
TMR3CN_CT3__BMASK         EQU 002H ; Counter/Timer Select                              
TMR3CN_CT3__SHIFT         EQU 001H ; Counter/Timer Select                              
TMR3CN_CT3__TIMER         EQU 000H ; Timer Function: Timer incremented by clock defined
                                   ; by T3M.                                           
TMR3CN_CT3__COUNTER       EQU 002H ; Counter Function: Timer incremented by high-to-low
                                   ; transitions on external input pin.                
                                                                                       
TMR3CN_TR3__BMASK         EQU 004H ; Timer 3 Run Control                               
TMR3CN_TR3__SHIFT         EQU 002H ; Timer 3 Run Control                               
TMR3CN_TR3__STOP          EQU 000H ; Stop Timer 3.                                     
TMR3CN_TR3__RUN           EQU 004H ; Start Timer 3 running.                            
                                                                                       
TMR3CN_EXEN3__BMASK       EQU 008H ; Timer 3 External Enable                           
TMR3CN_EXEN3__SHIFT       EQU 003H ; Timer 3 External Enable                           
TMR3CN_EXEN3__DISABLED    EQU 000H ; Transitions on the T3EX pin are ignored.          
TMR3CN_EXEN3__ENABLED     EQU 008H ; Transitions on the T3EX pin cause capture, reload,
                                   ; or control the direction of timer count (up or    
                                   ; down).                                            
                                                                                       
TMR3CN_EXF3__BMASK        EQU 040H ; Timer 3 External Flag                             
TMR3CN_EXF3__SHIFT        EQU 006H ; Timer 3 External Flag                             
TMR3CN_EXF3__NOT_SET      EQU 000H ; Timer 3 capture or reload did not occur.          
TMR3CN_EXF3__SET          EQU 040H ; Timer 3 capture or reload occurred.               
                                                                                       
TMR3CN_TF3__BMASK         EQU 080H ; Timer 3 Overflow/Underflow Flag                   
TMR3CN_TF3__SHIFT         EQU 007H ; Timer 3 Overflow/Underflow Flag                   
TMR3CN_TF3__NOT_SET       EQU 000H ; Timer 3 did not overflow or underflow.            
TMR3CN_TF3__SET           EQU 080H ; Timer 3 overflowed or underflowed.                
                                                                                       
;------------------------------------------------------------------------------
; TMR3H Enums (Timer 3 High Byte @ 0xCD)
;------------------------------------------------------------------------------
TMR3H_TMR3H__FMASK EQU 0FFH ; Timer 3 High Byte
TMR3H_TMR3H__SHIFT EQU 000H ; Timer 3 High Byte
                                               
;------------------------------------------------------------------------------
; TMR3L Enums (Timer 3 Low Byte @ 0xCC)
;------------------------------------------------------------------------------
TMR3L_TMR3L__FMASK EQU 0FFH ; Timer 3 Low Byte
TMR3L_TMR3L__SHIFT EQU 000H ; Timer 3 Low Byte
                                              
;------------------------------------------------------------------------------
; RCAP4H Enums (Timer 4 Capture Register High Byte @ 0xCB)
;------------------------------------------------------------------------------
RCAP4H_RCAP4L__FMASK EQU 0FFH ; Timer 4 Capture Register High Byte
RCAP4H_RCAP4L__SHIFT EQU 000H ; Timer 4 Capture Register High Byte
                                                                  
;------------------------------------------------------------------------------
; RCAP4L Enums (Timer 4 Capture Register Low Byte @ 0xCA)
;------------------------------------------------------------------------------
RCAP4L_RCAP4L__FMASK EQU 0FFH ; Timer 4 Capture Register Low Byte
RCAP4L_RCAP4L__SHIFT EQU 000H ; Timer 4 Capture Register Low Byte
                                                                 
;------------------------------------------------------------------------------
; TMR4CF Enums (Timer 4 Configuration @ 0xC9)
;------------------------------------------------------------------------------
TMR4CF_DCEN4__BMASK          EQU 001H ; Decrement Enable                                  
TMR4CF_DCEN4__SHIFT          EQU 000H ; Decrement Enable                                  
TMR4CF_DCEN4__DISABLED       EQU 000H ; Timer will count up, regardless of the state of   
                                      ; T4EX.                                             
TMR4CF_DCEN4__ENABLED        EQU 001H ; Timer will count up or down depending on the state
                                      ; of T4EX as follows: if T4EX = 0, the timer counts 
                                      ; DOWN; if T4EX = 1, the timer counts UP.           
                                                                                          
TMR4CF_T4OE__BMASK           EQU 002H ; Timer Output Enable                               
TMR4CF_T4OE__SHIFT           EQU 001H ; Timer Output Enable                               
TMR4CF_T4OE__OUTPUT_DISABLED EQU 000H ; Output of toggle mode not available at Timer's    
                                      ; assigned port pin.                                
TMR4CF_T4OE__OUTPUT_ENABLED  EQU 002H ; Output of toggle mode available at Timer's        
                                      ; assigned port pin.                                
                                                                                          
TMR4CF_TOG4__BMASK           EQU 004H ; Toggle Output State                               
TMR4CF_TOG4__SHIFT           EQU 002H ; Toggle Output State                               
TMR4CF_TOG4__NOT_SET         EQU 000H ; Timer output is low. Set the timer output low.    
TMR4CF_TOG4__SET             EQU 004H ; Timer output is high. Set the timer output high.  
                                                                                          
TMR4CF_T4M__FMASK            EQU 018H ; Timer Clock Mode Select                           
TMR4CF_T4M__SHIFT            EQU 003H ; Timer Clock Mode Select                           
TMR4CF_T4M__SYSCLK_DIV_12    EQU 000H ; System clock divided by 12.                       
TMR4CF_T4M__SYSCLK           EQU 008H ; System clock.                                     
TMR4CF_T4M__EXTOSC_DIV_8     EQU 010H ; External oscillator divided by 8 (synchronized    
                                      ; with the system clock).                           
TMR4CF_T4M__SYSCLK_DIV_2     EQU 018H ; System clock divided by 2.                        
                                                                                          
;------------------------------------------------------------------------------
; TMR4CN Enums (Timer 4 Control @ 0xC8)
;------------------------------------------------------------------------------
TMR4CN_CPRL4__BMASK       EQU 001H ; Capture/Reload Select                             
TMR4CN_CPRL4__SHIFT       EQU 000H ; Capture/Reload Select                             
TMR4CN_CPRL4__AUTO_RELOAD EQU 000H ; Timer is in Auto-Reload Mode.                     
TMR4CN_CPRL4__CAPTURE     EQU 001H ; Timer is in Capture Mode.                         
                                                                                       
TMR4CN_CT4__BMASK         EQU 002H ; Counter/Timer Select                              
TMR4CN_CT4__SHIFT         EQU 001H ; Counter/Timer Select                              
TMR4CN_CT4__TIMER         EQU 000H ; Timer Function: Timer incremented by clock defined
                                   ; by T4M.                                           
TMR4CN_CT4__COUNTER       EQU 002H ; Counter Function: Timer incremented by high-to-low
                                   ; transitions on external input pin.                
                                                                                       
TMR4CN_TR4__BMASK         EQU 004H ; Timer 4 Run Control                               
TMR4CN_TR4__SHIFT         EQU 002H ; Timer 4 Run Control                               
TMR4CN_TR4__STOP          EQU 000H ; Stop Timer 4.                                     
TMR4CN_TR4__RUN           EQU 004H ; Start Timer 4 running.                            
                                                                                       
TMR4CN_EXEN4__BMASK       EQU 008H ; Timer 4 External Enable                           
TMR4CN_EXEN4__SHIFT       EQU 003H ; Timer 4 External Enable                           
TMR4CN_EXEN4__DISABLED    EQU 000H ; Transitions on the T4EX pin are ignored.          
TMR4CN_EXEN4__ENABLED     EQU 008H ; Transitions on the T4EX pin cause capture, reload,
                                   ; or control the direction of timer count (up or    
                                   ; down).                                            
                                                                                       
TMR4CN_EXF4__BMASK        EQU 040H ; Timer 4 External Flag                             
TMR4CN_EXF4__SHIFT        EQU 006H ; Timer 4 External Flag                             
TMR4CN_EXF4__NOT_SET      EQU 000H ; Timer 4 capture or reload did not occur.          
TMR4CN_EXF4__SET          EQU 040H ; Timer 4 capture or reload occurred.               
                                                                                       
TMR4CN_TF4__BMASK         EQU 080H ; Timer 4 Overflow/Underflow Flag                   
TMR4CN_TF4__SHIFT         EQU 007H ; Timer 4 Overflow/Underflow Flag                   
TMR4CN_TF4__NOT_SET       EQU 000H ; Timer 4 did not overflow or underflow.            
TMR4CN_TF4__SET           EQU 080H ; Timer 4 overflowed or underflowed.                
                                                                                       
;------------------------------------------------------------------------------
; TMR4H Enums (Timer 4 High Byte @ 0xCD)
;------------------------------------------------------------------------------
TMR4H_TMR4H__FMASK EQU 0FFH ; Timer 4 High Byte
TMR4H_TMR4H__SHIFT EQU 000H ; Timer 4 High Byte
                                               
;------------------------------------------------------------------------------
; TMR4L Enums (Timer 4 Low Byte @ 0xCC)
;------------------------------------------------------------------------------
TMR4L_TMR4L__FMASK EQU 0FFH ; Timer 4 Low Byte
TMR4L_TMR4L__SHIFT EQU 000H ; Timer 4 Low Byte
                                              
;------------------------------------------------------------------------------
; CKCON Enums (Clock Control @ 0x8E)
;------------------------------------------------------------------------------
CKCON_SCA__FMASK         EQU 003H ; Timer 0/1 Prescale                            
CKCON_SCA__SHIFT         EQU 000H ; Timer 0/1 Prescale                            
CKCON_SCA__SYSCLK_DIV_12 EQU 000H ; System clock divided by 12.                   
CKCON_SCA__SYSCLK_DIV_4  EQU 001H ; System clock divided by 4.                    
CKCON_SCA__SYSCLK_DIV_48 EQU 002H ; System clock divided by 48.                   
CKCON_SCA__EXTOSC_DIV_8  EQU 003H ; External oscillator divided by 8 (synchronized
                                  ; with the system clock).                       
                                                                                  
CKCON_T0M__BMASK         EQU 008H ; Timer 0 Clock Select                          
CKCON_T0M__SHIFT         EQU 003H ; Timer 0 Clock Select                          
CKCON_T0M__PRESCALE      EQU 000H ; Counter/Timer 0 uses the clock defined by the 
                                  ; prescale field, SCA.                          
CKCON_T0M__SYSCLK        EQU 008H ; Counter/Timer 0 uses the system clock.        
                                                                                  
CKCON_T1M__BMASK         EQU 010H ; Timer 1 Clock Select                          
CKCON_T1M__SHIFT         EQU 004H ; Timer 1 Clock Select                          
CKCON_T1M__PRESCALE      EQU 000H ; Timer 1 uses the clock defined by the prescale
                                  ; field, SCA.                                   
CKCON_T1M__SYSCLK        EQU 010H ; Timer 1 uses the system clock.                
                                                                                  
;------------------------------------------------------------------------------
; TCON Enums (Timer 0/1 Control @ 0x88)
;------------------------------------------------------------------------------
TCON_IT0__BMASK   EQU 001H ; Interrupt 0 Type Select               
TCON_IT0__SHIFT   EQU 000H ; Interrupt 0 Type Select               
TCON_IT0__LEVEL   EQU 000H ; /INT0 is level triggered, active low. 
TCON_IT0__EDGE    EQU 001H ; /INT0 is edge triggered, falling-edge.
                                                                   
TCON_IE0__BMASK   EQU 002H ; External Interrupt 0                  
TCON_IE0__SHIFT   EQU 001H ; External Interrupt 0                  
TCON_IE0__NOT_SET EQU 000H ; Edge/level not detected.              
TCON_IE0__SET     EQU 002H ; Edge/level detected                   
                                                                   
TCON_IT1__BMASK   EQU 004H ; Interrupt 1 Type Select               
TCON_IT1__SHIFT   EQU 002H ; Interrupt 1 Type Select               
TCON_IT1__LEVEL   EQU 000H ; /INT1 is level triggered, active low. 
TCON_IT1__EDGE    EQU 004H ; /INT1 is edge triggered, falling-edge.
                                                                   
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
                              ; active.                                           
                                                                                  
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
                              ; active.                                           
                                                                                  
;------------------------------------------------------------------------------
; SADDR0 Enums (UART0 Slave Address @ 0xA9)
;------------------------------------------------------------------------------
SADDR0_SADDR0__FMASK EQU 0FFH ; UART0 Slave Address
SADDR0_SADDR0__SHIFT EQU 000H ; UART0 Slave Address
                                                   
;------------------------------------------------------------------------------
; SADEN0 Enums (UART0 Slave Address Enable @ 0xB9)
;------------------------------------------------------------------------------
SADEN0_SADEN0__FMASK EQU 0FFH ; UART0 Slave Address Enable
SADEN0_SADEN0__SHIFT EQU 000H ; UART0 Slave Address Enable
                                                          
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
                                                                                        
SCON0_SM2__BMASK            EQU 020H ; Multiprocessor Communication Enable              
SCON0_SM2__SHIFT            EQU 005H ; Multiprocessor Communication Enable              
SCON0_SM2__MULTI_DISABLED   EQU 000H ; Multiprocessor communication disabled.           
SCON0_SM2__MULTI_ENABLED    EQU 020H ; Multiprocessor communication enabled.            
                                                                                        
SCON0_SM__FMASK             EQU 0C0H ; Serial Port 0 Operation Mode                     
SCON0_SM__SHIFT             EQU 006H ; Serial Port 0 Operation Mode                     
SCON0_SM__MODE0             EQU 000H ; Mode 0: Sychronous Mode                          
SCON0_SM__MODE1             EQU 040H ; Mode 1: 8-bit UART, Variable Baud Rate           
SCON0_SM__MODE2             EQU 080H ; Mode 2: 9-bit UART, Fixed Baud Rate              
SCON0_SM__MODE3             EQU 0C0H ; Mode 3: 9-bit UART, Variable Baud Rate           
                                                                                        
;------------------------------------------------------------------------------
; SSTA0 Enums (UART0 Status and Clock Selection @ 0x91)
;------------------------------------------------------------------------------
SSTA0_S0RCLK__FMASK          EQU 003H ; UART0 Receive Baud Rate Clock Selection        
SSTA0_S0RCLK__SHIFT          EQU 000H ; UART0 Receive Baud Rate Clock Selection        
SSTA0_S0RCLK__TIMER1         EQU 000H ; Timer 1 generates UART0 RX baud rate.          
SSTA0_S0RCLK__TIMER2         EQU 001H ; Timer 2 overflow generates UART0 RX baud rate. 
SSTA0_S0RCLK__TIMER3         EQU 002H ; Timer 3 overflow generates UART0 RX baud rate. 
SSTA0_S0RCLK__TIMER4         EQU 003H ; Timer 4 overflow generates UART0 RX baud rate. 
                                                                                       
SSTA0_S0TCLK__FMASK          EQU 00CH ; UART0 Transmit Baud Rate Clock Selection       
SSTA0_S0TCLK__SHIFT          EQU 002H ; UART0 Transmit Baud Rate Clock Selection       
SSTA0_S0TCLK__TIMER1         EQU 000H ; Timer 1 generates UART0 TX baud rate.          
SSTA0_S0TCLK__TIMER2         EQU 004H ; Timer 2 overflow generates UART0 TX baud rate. 
SSTA0_S0TCLK__TIMER3         EQU 008H ; Timer 3 overflow generates UART0 TX baud rate. 
SSTA0_S0TCLK__TIMER4         EQU 00CH ; Timer 4 overflow generates UART0 TX baud rate. 
                                                                                       
SSTA0_SMOD__BMASK            EQU 010H ; UART0 Baud Rate Doubler Enable                 
SSTA0_SMOD__SHIFT            EQU 004H ; UART0 Baud Rate Doubler Enable                 
SSTA0_SMOD__DOUBLER_DISABLED EQU 000H ; UART0 baud rate divide-by-two enabled (doubler 
                                      ; disabled).                                     
SSTA0_SMOD__DOUBLER_ENABLED  EQU 010H ; UART0 baud rate divide-by-two disabled (doubler
                                      ; enabled).                                      
                                                                                       
SSTA0_TXCOL__BMASK           EQU 020H ; Transmit Collision Flag                        
SSTA0_TXCOL__SHIFT           EQU 005H ; Transmit Collision Flag                        
SSTA0_TXCOL__NOT_SET         EQU 000H ; Transmission collision has not been detected.  
SSTA0_TXCOL__SET             EQU 020H ; Transmission collision has been detected.      
                                                                                       
SSTA0_RXOV__BMASK            EQU 040H ; Receive Overrun Flag                           
SSTA0_RXOV__SHIFT            EQU 006H ; Receive Overrun Flag                           
SSTA0_RXOV__NOT_SET          EQU 000H ; Receive overrun has not been detected.         
SSTA0_RXOV__SET              EQU 040H ; Receive overrun has been detected.             
                                                                                       
SSTA0_FE__BMASK              EQU 080H ; Frame Error Flag                               
SSTA0_FE__SHIFT              EQU 007H ; Frame Error Flag                               
SSTA0_FE__NOT_SET            EQU 000H ; Frame Error has not been detected              
SSTA0_FE__SET                EQU 080H ; Frame Error has been detected.                 
                                                                                       
;------------------------------------------------------------------------------
; SBUF1 Enums (UART1 Serial Port Data Buffer @ 0x99)
;------------------------------------------------------------------------------
SBUF1_SBUF1__FMASK EQU 0FFH ; Serial Data Buffer
SBUF1_SBUF1__SHIFT EQU 000H ; Serial Data Buffer
                                                
;------------------------------------------------------------------------------
; SCON1 Enums (UART1 Serial Port Control @ 0x98)
;------------------------------------------------------------------------------
SCON1_RI__BMASK             EQU 001H ; Receive Interrupt Flag                           
SCON1_RI__SHIFT             EQU 000H ; Receive Interrupt Flag                           
SCON1_RI__NOT_SET           EQU 000H ; A byte of data has not been received by UART1.   
SCON1_RI__SET               EQU 001H ; UART1 received a byte of data.                   
                                                                                        
SCON1_TI__BMASK             EQU 002H ; Transmit Interrupt Flag                          
SCON1_TI__SHIFT             EQU 001H ; Transmit Interrupt Flag                          
SCON1_TI__NOT_SET           EQU 000H ; A byte of data has not been transmitted by UART1.
SCON1_TI__SET               EQU 002H ; UART1 transmitted a byte of data.                
                                                                                        
SCON1_RB8__BMASK            EQU 004H ; Ninth Receive Bit                                
SCON1_RB8__SHIFT            EQU 002H ; Ninth Receive Bit                                
SCON1_RB8__CLEARED_TO_0     EQU 000H ; In Mode 0, the STOP bit was 0. In Mode 1, the 9th
                                     ; bit was 0.                                       
SCON1_RB8__SET_TO_1         EQU 004H ; In Mode 0, the STOP bit was 1. In Mode 1, the 9th
                                     ; bit was 1.                                       
                                                                                        
SCON1_TB8__BMASK            EQU 008H ; Ninth Transmission Bit                           
SCON1_TB8__SHIFT            EQU 003H ; Ninth Transmission Bit                           
SCON1_TB8__CLEARED_TO_0     EQU 000H ; In Mode 1, set the 9th transmission bit to 0.    
SCON1_TB8__SET_TO_1         EQU 008H ; In Mode 1, set the 9th transmission bit to 1.    
                                                                                        
SCON1_REN__BMASK            EQU 010H ; Receive Enable                                   
SCON1_REN__SHIFT            EQU 004H ; Receive Enable                                   
SCON1_REN__RECEIVE_DISABLED EQU 000H ; UART1 reception disabled.                        
SCON1_REN__RECEIVE_ENABLED  EQU 010H ; UART1 reception enabled.                         
                                                                                        
SCON1_MCE__BMASK            EQU 020H ; Multiprocessor Communication Enable              
SCON1_MCE__SHIFT            EQU 005H ; Multiprocessor Communication Enable              
SCON1_MCE__MULTI_DISABLED   EQU 000H ; Ignore level of 9th bit / Stop bit.              
SCON1_MCE__MULTI_ENABLED    EQU 020H ; RI is set and an interrupt is generated only when
                                     ; the stop bit is logic 1 (Mode 0) or when the 9th 
                                     ; bit is logic 1 (Mode 1).                         
                                                                                        
SCON1_SMODE__BMASK          EQU 080H ; Serial Port 0 Operation Mode                     
SCON1_SMODE__SHIFT          EQU 007H ; Serial Port 0 Operation Mode                     
SCON1_SMODE__8_BIT          EQU 000H ; 8-bit UART with Variable Baud Rate (Mode 0).     
SCON1_SMODE__9_BIT          EQU 080H ; 9-bit UART with Variable Baud Rate (Mode 1).     
                                                                                        
;------------------------------------------------------------------------------
; REF0CN Enums (Voltage Reference Control @ 0xD1)
;------------------------------------------------------------------------------
REF0CN_REFBE__BMASK         EQU 001H ; Internal Reference Buffer Enable                  
REF0CN_REFBE__SHIFT         EQU 000H ; Internal Reference Buffer Enable                  
REF0CN_REFBE__REF_DISABLED  EQU 000H ; Internal reference buffer off.                    
REF0CN_REFBE__REF_ENABLED   EQU 001H ; Internal reference buffer on. The internal voltage
                                     ; reference is driven on the VREF pin.              
                                                                                         
REF0CN_BIASE__BMASK         EQU 002H ; ADC/DAC Bias Generator Enable                     
REF0CN_BIASE__SHIFT         EQU 001H ; ADC/DAC Bias Generator Enable                     
REF0CN_BIASE__BIAS_DISABLED EQU 000H ; Internal bias generator off.                      
REF0CN_BIASE__BIAS_ENABLED  EQU 002H ; Internal bias generator on.                       
                                                                                         
REF0CN_TEMPE__BMASK         EQU 004H ; Temperature Sensor Enable                         
REF0CN_TEMPE__SHIFT         EQU 002H ; Temperature Sensor Enable                         
REF0CN_TEMPE__TEMP_DISABLED EQU 000H ; Disable the Temperature Sensor.                   
REF0CN_TEMPE__TEMP_ENABLED  EQU 004H ; Enable the Temperature Sensor.                    
                                                                                         
REF0CN_AD2VRS__BMASK        EQU 008H ; ADC2 Voltage Reference Select                     
REF0CN_AD2VRS__SHIFT        EQU 003H ; ADC2 Voltage Reference Select                     
REF0CN_AD2VRS__VREF2_PIN    EQU 000H ; ADC2 voltage reference from VREF2 pin.            
REF0CN_AD2VRS__AV_PLUS      EQU 008H ; ADC2 voltage reference from AV+.                  
                                                                                         
REF0CN_REFSL__FMASK         EQU 018H ; Voltage Reference Select                          
REF0CN_REFSL__SHIFT         EQU 003H ; Voltage Reference Select                          
REF0CN_REFSL__VREF_PIN      EQU 000H ; The ADC0 voltage reference is the P0.0/VREF pin.  
REF0CN_REFSL__VDD_PIN       EQU 008H ; The ADC0 voltage reference is the VDD pin.        
REF0CN_REFSL__INTERNAL_LDO  EQU 010H ; The ADC0 voltage reference is the internal 1.8 V  
                                     ; digital supply voltage.                           
REF0CN_REFSL__INTERNAL_VREF EQU 018H ; The ADC0 voltage reference is the internal voltage
                                     ; reference.                                        
                                                                                         
REF0CN_AD0VRS__BMASK        EQU 010H ; ADC0 Voltage Reference Select                     
REF0CN_AD0VRS__SHIFT        EQU 004H ; ADC0 Voltage Reference Select                     
REF0CN_AD0VRS__VREF0_PIN    EQU 000H ; ADC0 voltage reference from VREF0 pin.            
REF0CN_AD0VRS__DAC0_OUTPUT  EQU 010H ; ADC0 voltage reference from the DAC0 output.      
                                                                                         
REF0CN_GNDSL__BMASK         EQU 020H ; Analog Ground Reference                           
REF0CN_GNDSL__SHIFT         EQU 005H ; Analog Ground Reference                           
REF0CN_GNDSL__GND_PIN       EQU 000H ; The ADC0 ground reference is the GND pin.         
REF0CN_GNDSL__AGND_PIN      EQU 020H ; The ADC0 ground reference is the P0.1/AGND pin.   
                                                                                         
REF0CN_IREFLVL__BMASK       EQU 080H ; Internal Voltage Reference Level                  
REF0CN_IREFLVL__SHIFT       EQU 007H ; Internal Voltage Reference Level                  
REF0CN_IREFLVL__1P65        EQU 000H ; The internal reference operates at 1.65 V nominal.
REF0CN_IREFLVL__2P4         EQU 080H ; The internal reference operates at 2.4 V nominal. 
                                                                                         
;------------------------------------------------------------------------------
; WDTCN Enums (Watchdog Timer Control @ 0xFF)
;------------------------------------------------------------------------------
WDTCN_WDTCN__FMASK EQU 0FFH ; WDT Control
WDTCN_WDTCN__SHIFT EQU 000H ; WDT Control
                                         
;------------------------------------------------------------------------------
; EMI0CF Enums (External Memory Configuration @ 0xA3)
;------------------------------------------------------------------------------
EMI0CF_EALE__FMASK                    EQU 003H ; ALE Pulse-Width Select                            
EMI0CF_EALE__SHIFT                    EQU 000H ; ALE Pulse-Width Select                            
EMI0CF_EALE__1_CLOCK                  EQU 000H ; ALE high and ALE low pulse width = 1 SYSCLK cycle.
EMI0CF_EALE__2_CLOCKS                 EQU 001H ; ALE high and ALE low pulse width = 2 SYSCLK       
                                               ; cycles.                                           
EMI0CF_EALE__3_CLOCKS                 EQU 002H ; ALE high and ALE low pulse width = 3 SYSCLK       
                                               ; cycles.                                           
EMI0CF_EALE__4_CLOCKS                 EQU 003H ; ALE high and ALE low pulse width = 4 SYSCLK       
                                               ; cycles.                                           
                                                                                                   
EMI0CF_EMD__FMASK                     EQU 00CH ; EMIF Operating Mode Select                        
EMI0CF_EMD__SHIFT                     EQU 002H ; EMIF Operating Mode Select                        
EMI0CF_EMD__INTERNAL_ONLY             EQU 000H ; Internal Only: MOVX accesses on-chip XRAM only.   
                                               ; All effective addresses alias to on-chip memory   
                                               ; space.                                            
EMI0CF_EMD__SPLIT_WITHOUT_BANK_SELECT EQU 004H ; Split Mode without Bank Select: Accesses below the
                                               ; internal XRAM boundary are directed on-chip.      
                                               ; Accesses above the internal XRAM boundary are     
                                               ; directed off-chip. 8-bit off-chip MOVX operations 
                                               ; use the current contents of the Address high port 
                                               ; latches to resolve the upper address byte. To     
                                               ; access off chip space, EMI0CN must be set to a    
                                               ; page that is not contained in the on-chip address 
                                               ; space.                                            
EMI0CF_EMD__SPLIT_WITH_BANK_SELECT    EQU 008H ; Split Mode with Bank Select: Accesses below the   
                                               ; internal XRAM boundary are directed on-chip.      
                                               ; Accesses above the internal XRAM boundary are     
                                               ; directed off-chip. 8-bit off-chip MOVX operations 
                                               ; uses the contents of EMI0CN to determine the high-
                                               ; byte of the address.                              
EMI0CF_EMD__EXTERNAL_ONLY             EQU 00CH ; External Only: MOVX accesses off-chip XRAM only.  
                                               ; On-chip XRAM is not visible to the core.          
                                                                                                   
EMI0CF_MUXMD__BMASK                   EQU 010H ; EMIF Multiplex Mode Select                        
EMI0CF_MUXMD__SHIFT                   EQU 004H ; EMIF Multiplex Mode Select                        
EMI0CF_MUXMD__MULTIPLEXED             EQU 000H ; EMIF operates in multiplexed address/data mode.   
EMI0CF_MUXMD__NON_MULTIPLEXED         EQU 010H ; EMIF operates in non-multiplexed mode (separate   
                                               ; address and data pins).                           
                                                                                                   
EMI0CF_PRTSEL__BMASK                  EQU 020H ; EMIF Port Select                                  
EMI0CF_PRTSEL__SHIFT                  EQU 005H ; EMIF Port Select                                  
EMI0CF_PRTSEL__P0_P3                  EQU 000H ; EMIF active on P0-P3.                             
EMI0CF_PRTSEL__P4_P7                  EQU 020H ; EMIF active on P4-P7.                             
                                                                                                   
;------------------------------------------------------------------------------
; EMI0CN Enums (External Memory Interface Control @ 0xA2)
;------------------------------------------------------------------------------
EMI0CN_PGSEL__FMASK EQU 0FFH ; XRAM Page Select
EMI0CN_PGSEL__SHIFT EQU 000H ; XRAM Page Select
                                               
;------------------------------------------------------------------------------
; EMI0TC Enums (External Memory Timing Control @ 0xA1)
;------------------------------------------------------------------------------
EMI0TC_AHOLD__FMASK      EQU 003H ; EMIF Address Hold Time                      
EMI0TC_AHOLD__SHIFT      EQU 000H ; EMIF Address Hold Time                      
EMI0TC_AHOLD__0_CLOCKS   EQU 000H ; Address hold time = 0 SYSCLK cycles.        
EMI0TC_AHOLD__1_CLOCK    EQU 001H ; Address hold time = 1 SYSCLK cycle.         
EMI0TC_AHOLD__2_CLOCKS   EQU 002H ; Address hold time = 2 SYSCLK cycles.        
EMI0TC_AHOLD__3_CLOCKS   EQU 003H ; Address hold time = 3 SYSCLK cycles.        
                                                                                
EMI0TC_PWIDTH__FMASK     EQU 03CH ; EMIF /WR and /RD Pulse-Width Control        
EMI0TC_PWIDTH__SHIFT     EQU 002H ; EMIF /WR and /RD Pulse-Width Control        
EMI0TC_PWIDTH__1_CLOCK   EQU 000H ; /WR and /RD pulse width is 1 SYSCLK cycle.  
EMI0TC_PWIDTH__2_CLOCKS  EQU 004H ; /WR and /RD pulse width is 2 SYSCLK cycles. 
EMI0TC_PWIDTH__3_CLOCKS  EQU 008H ; /WR and /RD pulse width is 3 SYSCLK cycles. 
EMI0TC_PWIDTH__4_CLOCKS  EQU 00CH ; /WR and /RD pulse width is 4 SYSCLK cycles. 
EMI0TC_PWIDTH__5_CLOCKS  EQU 010H ; /WR and /RD pulse width is 5 SYSCLK cycles. 
EMI0TC_PWIDTH__6_CLOCKS  EQU 014H ; /WR and /RD pulse width is 6 SYSCLK cycles. 
EMI0TC_PWIDTH__7_CLOCKS  EQU 018H ; /WR and /RD pulse width is 7 SYSCLK cycles. 
EMI0TC_PWIDTH__8_CLOCKS  EQU 01CH ; /WR and /RD pulse width is 8 SYSCLK cycles. 
EMI0TC_PWIDTH__9_CLOCKS  EQU 020H ; /WR and /RD pulse width is 9 SYSCLK cycles. 
EMI0TC_PWIDTH__10_CLOCKS EQU 024H ; /WR and /RD pulse width is 10 SYSCLK cycles.
EMI0TC_PWIDTH__11_CLOCKS EQU 028H ; /WR and /RD pulse width is 11 SYSCLK cycles.
EMI0TC_PWIDTH__12_CLOCKS EQU 02CH ; /WR and /RD pulse width is 12 SYSCLK cycles.
EMI0TC_PWIDTH__13_CLOCKS EQU 030H ; /WR and /RD pulse width is 13 SYSCLK cycles.
EMI0TC_PWIDTH__14_CLOCKS EQU 034H ; /WR and /RD pulse width is 14 SYSCLK cycles.
EMI0TC_PWIDTH__15_CLOCKS EQU 038H ; /WR and /RD pulse width is 15 SYSCLK cycles.
EMI0TC_PWIDTH__16_CLOCKS EQU 03CH ; /WR and /RD pulse width is 16 SYSCLK cycles.
                                                                                
EMI0TC_ASETUP__FMASK     EQU 0C0H ; EMIF Address Setup Time                     
EMI0TC_ASETUP__SHIFT     EQU 006H ; EMIF Address Setup Time                     
EMI0TC_ASETUP__0_CLOCKS  EQU 000H ; Address setup time = 0 SYSCLK cycles.       
EMI0TC_ASETUP__1_CLOCK   EQU 040H ; Address setup time = 1 SYSCLK cycle.        
EMI0TC_ASETUP__2_CLOCKS  EQU 080H ; Address setup time = 2 SYSCLK cycles.       
EMI0TC_ASETUP__3_CLOCKS  EQU 0C0H ; Address setup time = 3 SYSCLK cycles.       
                                                                                
