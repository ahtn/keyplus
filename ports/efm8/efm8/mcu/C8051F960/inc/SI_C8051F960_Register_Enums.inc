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

;------------------------------------------------------------------------------
; ADC0AC Enums (ADC0 Accumulator Configuration @ 0xBA)
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
                                    ; conversion begins 3 SAR clock cycles following the
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
ADC0CN_ADBMEN__BURST_DISABLED EQU 000H ; Disable ADC0 burst mode.                          
ADC0CN_ADBMEN__BURST_ENABLED  EQU 040H ; Enable ADC0 burst mode.                           
                                                                                           
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
ADC0MX_ADC0MX__FMASK   EQU 01FH ; AMUX0 Positive Input Selection
ADC0MX_ADC0MX__SHIFT   EQU 000H ; AMUX0 Positive Input Selection
ADC0MX_ADC0MX__ADC0P0  EQU 000H ; Select channel ADC0.0.        
ADC0MX_ADC0MX__ADC0P1  EQU 001H ; Select channel ADC0.1.        
ADC0MX_ADC0MX__ADC0P2  EQU 002H ; Select channel ADC0.2.        
ADC0MX_ADC0MX__ADC0P3  EQU 003H ; Select channel ADC0.3.        
ADC0MX_ADC0MX__ADC0P4  EQU 004H ; Select channel ADC0.4.        
ADC0MX_ADC0MX__ADC0P5  EQU 005H ; Select channel ADC0.5.        
ADC0MX_ADC0MX__ADC0P6  EQU 006H ; Select channel ADC0.6.        
ADC0MX_ADC0MX__ADC0P7  EQU 007H ; Select channel ADC0.7.        
ADC0MX_ADC0MX__ADC0P12 EQU 00CH ; Select channel ADC0.12.       
ADC0MX_ADC0MX__ADC0P13 EQU 00DH ; Select channel ADC0.13.       
ADC0MX_ADC0MX__ADC0P14 EQU 00EH ; Select channel ADC0.14.       
ADC0MX_ADC0MX__ADC0P15 EQU 00FH ; Select channel ADC0.15.       
ADC0MX_ADC0MX__ADC0P16 EQU 010H ; Select channel ADC0.16.       
ADC0MX_ADC0MX__ADC0P17 EQU 011H ; Select channel ADC0.17.       
ADC0MX_ADC0MX__ADC0P18 EQU 012H ; Select channel ADC0.18.       
ADC0MX_ADC0MX__ADC0P19 EQU 013H ; Select channel ADC0.19.       
ADC0MX_ADC0MX__TEMP    EQU 01BH ; Temperature Sensor.           
ADC0MX_ADC0MX__VBAT    EQU 01CH ; VBAT Supply Voltage.          
ADC0MX_ADC0MX__LDO     EQU 01DH ; Internal LDO regulator output.
ADC0MX_ADC0MX__VDC     EQU 01EH ; VDC Supply Voltage.           
ADC0MX_ADC0MX__GND     EQU 01FH ; Ground.                       
                                                                
;------------------------------------------------------------------------------
; ADC0PWR Enums (ADC0 Power Control @ 0xBA)
;------------------------------------------------------------------------------
ADC0PWR_ADPWR__FMASK              EQU 00FH ; Burst Mode Power Up Time                         
ADC0PWR_ADPWR__SHIFT              EQU 000H ; Burst Mode Power Up Time                         
                                                                                              
ADC0PWR_ADLPM__BMASK              EQU 080H ; Low Power Mode Enable                            
ADC0PWR_ADLPM__SHIFT              EQU 007H ; Low Power Mode Enable                            
ADC0PWR_ADLPM__LOW_POWER_DISABLED EQU 000H ; Disable low power mode.                          
ADC0PWR_ADLPM__LOW_POWER_ENABLED  EQU 080H ; Enable low power mode (requires extended tracking
                                           ; time).                                           
                                                                                              
;------------------------------------------------------------------------------
; ADC0TK Enums (ADC0 Burst Mode Track Time @ 0xBB)
;------------------------------------------------------------------------------
ADC0TK_ADTK__FMASK EQU 03FH ; Burst Mode Tracking Time
ADC0TK_ADTK__SHIFT EQU 000H ; Burst Mode Tracking Time
                                                      
;------------------------------------------------------------------------------
; AES0BCFG Enums (AES Block Configuration @ 0xE9)
;------------------------------------------------------------------------------
AES0BCFG_KSIZE__FMASK    EQU 003H ; AES Key Size                                    
AES0BCFG_KSIZE__SHIFT    EQU 000H ; AES Key Size                                    
AES0BCFG_KSIZE__128_BITS EQU 000H ; 128 bits (16 bytes).                            
AES0BCFG_KSIZE__196_BITS EQU 001H ; 198 bits (24 bytes).                            
AES0BCFG_KSIZE__256_BITS EQU 002H ; 256 bits (32 bytes).                            
                                                                                    
AES0BCFG_ENCMD__BMASK    EQU 004H ; Encryption/Decryption Select                    
AES0BCFG_ENCMD__SHIFT    EQU 002H ; Encryption/Decryption Select                    
AES0BCFG_ENCMD__DECRYPT  EQU 000H ; Select a decryption operation.                  
AES0BCFG_ENCMD__ENCRYPT  EQU 004H ; Select an encryption operation.                 
                                                                                    
AES0BCFG_START__BMASK    EQU 008H ; AES Start                                       
AES0BCFG_START__SHIFT    EQU 003H ; AES Start                                       
AES0BCFG_START__CLEAR    EQU 000H ; Reset the AES module.                           
AES0BCFG_START__START    EQU 008H ; Start an encryption or decryption operation.    
                                                                                    
AES0BCFG_BUSY__BMASK     EQU 010H ; AES Busy                                        
AES0BCFG_BUSY__SHIFT     EQU 004H ; AES Busy                                        
AES0BCFG_BUSY__NOT_SET   EQU 000H ; The AES block is not completing an encryption or
                                  ; decryption operation.                           
AES0BCFG_BUSY__SET       EQU 010H ; The AES block is completing an encryption or    
                                  ; decryption operation.                           
                                                                                    
AES0BCFG_DONE__BMASK     EQU 020H ; Done Flag                                       
AES0BCFG_DONE__SHIFT     EQU 005H ; Done Flag                                       
AES0BCFG_DONE__NOT_SET   EQU 000H ; The encryption or decryption operation has not  
                                  ; started or is in progress.                      
AES0BCFG_DONE__SET       EQU 020H ; The encyrption or decryption operation is       
                                  ; complete.                                       
                                                                                    
;------------------------------------------------------------------------------
; AES0BIN Enums (AES Block Input @ 0xEB)
;------------------------------------------------------------------------------
AES0BIN_AES0BIN__FMASK EQU 0FFH ; AES Block Input
AES0BIN_AES0BIN__SHIFT EQU 000H ; AES Block Input
                                                 
;------------------------------------------------------------------------------
; AES0DCFG Enums (AES Data Configuration @ 0xEA)
;------------------------------------------------------------------------------
AES0DCFG_XORIN__BMASK       EQU 001H ; XOR Input Enable                                 
AES0DCFG_XORIN__SHIFT       EQU 000H ; XOR Input Enable                                 
AES0DCFG_XORIN__DISABLED    EQU 000H ; Disable the XOR data path of the AES input.      
AES0DCFG_XORIN__ENABLED     EQU 001H ; Enable the XOR data path of the AES input.       
                                                                                        
AES0DCFG_OUTSEL__FMASK      EQU 006H ; Output Data Select                               
AES0DCFG_OUTSEL__SHIFT      EQU 001H ; Output Data Select                               
AES0DCFG_OUTSEL__DIRECT_OUT EQU 000H ; The AES0YOUT register targets the direct AES     
                                     ; output data.                                     
AES0DCFG_OUTSEL__XOR_OUT    EQU 002H ; The AES0YOUT register targets the AES output data
                                     ; XORed with AES0XIN.                              
AES0DCFG_OUTSEL__KEY        EQU 004H ; The AES0YOUT register targets the inverse key.   
                                                                                        
;------------------------------------------------------------------------------
; AES0KIN Enums (AES Key Input @ 0xED)
;------------------------------------------------------------------------------
AES0KIN_AES0KIN__FMASK EQU 0FFH ; AES Key Input
AES0KIN_AES0KIN__SHIFT EQU 000H ; AES Key Input
                                               
;------------------------------------------------------------------------------
; AES0XIN Enums (AES XOR Input @ 0xEC)
;------------------------------------------------------------------------------
AES0XIN_AES0XIN__FMASK EQU 0FFH ; AES XOR Input
AES0XIN_AES0XIN__SHIFT EQU 000H ; AES XOR Input
                                               
;------------------------------------------------------------------------------
; AES0YOUT Enums (AES Y Output @ 0xF5)
;------------------------------------------------------------------------------
AES0YOUT_AES0YOUT__FMASK EQU 0FFH ; AES Y Output
AES0YOUT_AES0YOUT__SHIFT EQU 000H ; AES Y Output
                                                
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
; PSBANK Enums (Program Space Bank Select @ 0x84)
;------------------------------------------------------------------------------
PSBANK_IFBANK__FMASK       EQU 003H ; Instruction Fetch Operations Bank Select         
PSBANK_IFBANK__SHIFT       EQU 000H ; Instruction Fetch Operations Bank Select         
PSBANK_IFBANK__INSTR_BANK0 EQU 000H ; Instructions fetch from Bank 0 (note that Bank 0 
                                    ; is also mapped between 0x0000 to 0x7FFF).        
PSBANK_IFBANK__INSTR_BANK1 EQU 001H ; Instructions fetch from Bank 1.                  
PSBANK_IFBANK__INSTR_BANK2 EQU 002H ; Instructions fetch from Bank 2.                  
PSBANK_IFBANK__INSTR_BANK3 EQU 003H ; Instructions fetch from Bank 3.                  
                                                                                       
PSBANK_COBANK__FMASK       EQU 030H ; Constant Operations Bank Select                  
PSBANK_COBANK__SHIFT       EQU 004H ; Constant Operations Bank Select                  
PSBANK_COBANK__CONST_BANK0 EQU 000H ; Constant operations target Bank 0 (note that Bank
                                    ; 0 is also mapped between 0x0000 to 0x7FFF).      
PSBANK_COBANK__CONST_BANK1 EQU 010H ; Constant operations target Bank 1.               
PSBANK_COBANK__CONST_BANK2 EQU 020H ; Constant operations target Bank 2.               
PSBANK_COBANK__CONST_BANK3 EQU 030H ; Constant operations target Bank 3.               
                                                                                       
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
; SFRPAGE Enums (SFR Page @ 0xA7)
;------------------------------------------------------------------------------
SFRPAGE_SFRPAGE__FMASK EQU 0FFH ; SFR Page
SFRPAGE_SFRPAGE__SHIFT EQU 000H ; SFR Page
                                          
;------------------------------------------------------------------------------
; SFRPGCN Enums (SFR Page Control @ 0x8E)
;------------------------------------------------------------------------------
SFRPGCN_SFRPGEN__BMASK              EQU 001H ; SFR Automatic Page Control Enable                 
SFRPGCN_SFRPGEN__SHIFT              EQU 000H ; SFR Automatic Page Control Enable                 
SFRPGCN_SFRPGEN__AUTO_PAGE_DISABLED EQU 000H ; Disable SFR automatic paging. The C8051 core will 
                                             ; not automatically change to the appropriate SFR   
                                             ; page (i.e., the SFR page that contains the SFRs   
                                             ; for the peripheral/function that was the source of
                                             ; the interrupt).                                   
SFRPGCN_SFRPGEN__AUTO_PAGE_ENABLED  EQU 001H ; Enable SFR automatic paging. Upon interrupt, the  
                                             ; C8051 will switch the SFR page to the page that   
                                             ; contains the SFRs for the peripheral or function  
                                             ; that is the source of the interrupt.              
                                                                                                 
;------------------------------------------------------------------------------
; SP Enums (Stack Pointer @ 0x81)
;------------------------------------------------------------------------------
SP_SP__FMASK EQU 0FFH ; Stack Pointer
SP_SP__SHIFT EQU 000H ; Stack Pointer
                                     
;------------------------------------------------------------------------------
; CLKMODE Enums (Clock Mode @ 0xFD)
;------------------------------------------------------------------------------
CLKMODE_LPMEN__BMASK    EQU 004H ; Low Power Mode Enable                            
CLKMODE_LPMEN__SHIFT    EQU 002H ; Low Power Mode Enable                            
CLKMODE_LPMEN__DISABLED EQU 000H ; Disable low power active and idle modes.         
CLKMODE_LPMEN__ENABLED  EQU 004H ; Enable low power active and low power idle modes.
                                                                                    
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
; PCLKACT Enums (Peripheral Active Clock Enable @ 0xF5)
;------------------------------------------------------------------------------
PCLKACT_PCLKACT0__BMASK    EQU 001H ; Low Power Active Mode Peripheral Set 0 Enable     
PCLKACT_PCLKACT0__SHIFT    EQU 000H ; Low Power Active Mode Peripheral Set 0 Enable     
PCLKACT_PCLKACT0__DISABLED EQU 000H ; Clocks to UART0, Timer 3, SPI0, and the SMBus     
                                    ; revert to the PCLKEN0 setting in low power active 
                                    ; mode.                                             
PCLKACT_PCLKACT0__ENABLED  EQU 001H ; Enable clocks to UART0, Timer 3, SPI0, and the    
                                    ; SMBus in low power active mode.                   
                                                                                        
PCLKACT_PCLKACT1__BMASK    EQU 002H ; Low Power Active Mode Peripheral Set 1 Enable     
PCLKACT_PCLKACT1__SHIFT    EQU 001H ; Low Power Active Mode Peripheral Set 1 Enable     
PCLKACT_PCLKACT1__DISABLED EQU 000H ; Clocks to ADC0 and PCA0 revert to the PCLKEN1     
                                    ; setting in low power active mode.                 
PCLKACT_PCLKACT1__ENABLED  EQU 002H ; Enable clocks to ADC0 and PCA0 in low power active
                                    ; mode.                                             
                                                                                        
PCLKACT_PCLKACT2__BMASK    EQU 004H ; Low Power Active Mode Peripheral Set 2 Enable     
PCLKACT_PCLKACT2__SHIFT    EQU 002H ; Low Power Active Mode Peripheral Set 2 Enable     
PCLKACT_PCLKACT2__DISABLED EQU 000H ; Clocks to Timer 0, Timer 1, Timer 2, and CRC0     
                                    ; revert to the PCLKEN2 setting in low power active 
                                    ; mode.                                             
PCLKACT_PCLKACT2__ENABLED  EQU 004H ; Enable clocks to Timer 0, Timer 1, Timer 2, and   
                                    ; CRC0 in low power active mode.                    
                                                                                        
PCLKACT_PCLKACT3__BMASK    EQU 008H ; Low Power Active Mode Peripheral Set 3 Enable     
PCLKACT_PCLKACT3__SHIFT    EQU 003H ; Low Power Active Mode Peripheral Set 3 Enable     
PCLKACT_PCLKACT3__DISABLED EQU 000H ; Clocks to RTC0, Pulse Counter, and PMU0 revert to 
                                    ; the PCLKEN3 setting in low power active mode.     
PCLKACT_PCLKACT3__ENABLED  EQU 008H ; Enable clocks to RTC0, Pulse Counter, and PMU0 in 
                                    ; low power active mode.                            
                                                                                        
;------------------------------------------------------------------------------
; PCLKEN Enums (Low Power Peripheral Clock Enable @ 0xFE)
;------------------------------------------------------------------------------
PCLKEN_PCLKEN0__BMASK    EQU 001H ; Low Power Idle Mode Peripheral Set 0 Enable       
PCLKEN_PCLKEN0__SHIFT    EQU 000H ; Low Power Idle Mode Peripheral Set 0 Enable       
PCLKEN_PCLKEN0__DISABLED EQU 000H ; Disable clocks to UART0, Timer 3, SPI0, and the   
                                  ; SMBus in low power idle mode.                     
PCLKEN_PCLKEN0__ENABLED  EQU 001H ; Enable clocks to UART0, Timer 3, SPI0, and the    
                                  ; SMBus in low power idle mode.                     
                                                                                      
PCLKEN_PCLKEN1__BMASK    EQU 002H ; Low Power Idle Mode Peripheral Set 1 Enable       
PCLKEN_PCLKEN1__SHIFT    EQU 001H ; Low Power Idle Mode Peripheral Set 1 Enable       
PCLKEN_PCLKEN1__DISABLED EQU 000H ; Disable clocks to ADC0 and PCA0 in low power idle 
                                  ; mode.                                             
PCLKEN_PCLKEN1__ENABLED  EQU 002H ; Enable clocks to ADC0 and PCA0 in low power idle  
                                  ; mode.                                             
                                                                                      
PCLKEN_PCLKEN2__BMASK    EQU 004H ; Low Power Idle Mode Peripheral Set 2 Enable       
PCLKEN_PCLKEN2__SHIFT    EQU 002H ; Low Power Idle Mode Peripheral Set 2 Enable       
PCLKEN_PCLKEN2__DISABLED EQU 000H ; Disable clocks to Timer 0, Timer 1, Timer 2, and  
                                  ; CRC0 in low power idle mode.                      
PCLKEN_PCLKEN2__ENABLED  EQU 004H ; Enable clocks to Timer 0, Timer 1, Timer 2, and   
                                  ; CRC0 in low power idle mode.                      
                                                                                      
PCLKEN_PCLKEN3__BMASK    EQU 008H ; Low Power Idle Mode Peripheral Set 3 Enable       
PCLKEN_PCLKEN3__SHIFT    EQU 003H ; Low Power Idle Mode Peripheral Set 3 Enable       
PCLKEN_PCLKEN3__DISABLED EQU 000H ; Disable clocks to RTC0, Pulse Counter, and PMU0 in
                                  ; low power idle mode.                              
PCLKEN_PCLKEN3__ENABLED  EQU 008H ; Enable clocks to RTC0, Pulse Counter, and PMU0 in 
                                  ; low power idle mode.                              
                                                                                      
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
CPT0MX_CMXP__FMASK        EQU 00FH ; Comparator Positive Input MUX Selection
CPT0MX_CMXP__SHIFT        EQU 000H ; Comparator Positive Input MUX Selection
CPT0MX_CMXP__CMP0P0       EQU 000H ; External pin CMP0P.0.                  
CPT0MX_CMXP__CMP0P1       EQU 001H ; External pin CMP0P.1.                  
CPT0MX_CMXP__CMP0P2       EQU 002H ; External pin CMP0P.2.                  
CPT0MX_CMXP__CMP0P3       EQU 003H ; External pin CMP0P.3.                  
CPT0MX_CMXP__CMP0P6       EQU 006H ; External pin CMP0P.6.                  
CPT0MX_CMXP__CMP0P7       EQU 007H ; External pin CMP0P.7.                  
CPT0MX_CMXP__CMP0P8       EQU 008H ; External pin CMP0P.8.                  
CPT0MX_CMXP__CMP0P9       EQU 009H ; External pin CMP0P.9.                  
CPT0MX_CMXP__CS_COMPARE   EQU 00CH ; Capacitive Sense Compare.              
CPT0MX_CMXP__VBAT_DIV_2   EQU 00DH ; VBAT divided by 2.                     
CPT0MX_CMXP__VBAT         EQU 00EH ; VBAT Supply Voltage.                   
CPT0MX_CMXP__NONE         EQU 00FH ; No input selected.                     
                                                                            
CPT0MX_CMXN__FMASK        EQU 0F0H ; Comparator Negative Input MUX Selection
CPT0MX_CMXN__SHIFT        EQU 004H ; Comparator Negative Input MUX Selection
CPT0MX_CMXN__CMP0N0       EQU 000H ; External pin CMP0N.0.                  
CPT0MX_CMXN__CMP0N1       EQU 010H ; External pin CMP0N.1.                  
CPT0MX_CMXN__CMP0N2       EQU 020H ; External pin CMP0N.2.                  
CPT0MX_CMXN__CMP0N6       EQU 060H ; External pin CMP0N.6.                  
CPT0MX_CMXN__CMP0N7       EQU 070H ; External pin CMP0N.7.                  
CPT0MX_CMXN__CMP0N8       EQU 080H ; External pin CMP0N.8.                  
CPT0MX_CMXN__CMP0N9       EQU 090H ; External pin CMP0N.9.                  
CPT0MX_CMXN__CS_COMPARE   EQU 0C0H ; Capacitive Sense Compare.              
CPT0MX_CMXN__VBAT_DIV_2   EQU 0D0H ; VBAT divided by 2.                     
CPT0MX_CMXN__INTERNAL_LDO EQU 0E0H ; Internal LDO output.                   
CPT0MX_CMXN__GND          EQU 0F0H ; Ground.                                
                                                                            
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
CPT1MX_CMXP__FMASK        EQU 00FH ; Comparator Positive Input MUX Selection
CPT1MX_CMXP__SHIFT        EQU 000H ; Comparator Positive Input MUX Selection
CPT1MX_CMXP__CMP1P0       EQU 000H ; External pin CMP1P.0.                  
CPT1MX_CMXP__CMP1P1       EQU 001H ; External pin CMP1P.1.                  
CPT1MX_CMXP__CMP1P2       EQU 002H ; External pin CMP1P.2.                  
CPT1MX_CMXP__CMP1P3       EQU 003H ; External pin CMP1P.3.                  
CPT1MX_CMXP__CMP1P6       EQU 006H ; External pin CMP1P.6.                  
CPT1MX_CMXP__CMP1P7       EQU 007H ; External pin CMP1P.7.                  
CPT1MX_CMXP__CMP1P8       EQU 008H ; External pin CMP1P.8.                  
CPT1MX_CMXP__CMP1P9       EQU 009H ; External pin CMP1P.9.                  
CPT1MX_CMXP__CS_COMPARE   EQU 00CH ; Capacitive Sense Compare.              
CPT1MX_CMXP__VBAT_DIV_2   EQU 00DH ; VBAT divided by 2.                     
CPT1MX_CMXP__VBAT         EQU 00EH ; VBAT Supply Voltage.                   
CPT1MX_CMXP__NONE         EQU 00FH ; No input selected.                     
                                                                            
CPT1MX_CMXN__FMASK        EQU 0F0H ; Comparator Negative Input MUX Selection
CPT1MX_CMXN__SHIFT        EQU 004H ; Comparator Negative Input MUX Selection
CPT1MX_CMXN__CMP1N0       EQU 000H ; External pin CMP1N.0.                  
CPT1MX_CMXN__CMP1N1       EQU 010H ; External pin CMP1N.1.                  
CPT1MX_CMXN__CMP1N2       EQU 020H ; External pin CMP1N.2.                  
CPT1MX_CMXN__CMP1N6       EQU 060H ; External pin CMP1N.6.                  
CPT1MX_CMXN__CMP1N7       EQU 070H ; External pin CMP1N.7.                  
CPT1MX_CMXN__CMP1N8       EQU 080H ; External pin CMP1N.8.                  
CPT1MX_CMXN__CMP1N9       EQU 090H ; External pin CMP1N.9.                  
CPT1MX_CMXN__CS_COMPARE   EQU 0C0H ; Capacitive Sense Compare.              
CPT1MX_CMXN__VBAT_DIV_2   EQU 0D0H ; VBAT divided by 2.                     
CPT1MX_CMXN__INTERNAL_LDO EQU 0E0H ; Internal LDO output.                   
CPT1MX_CMXN__GND          EQU 0F0H ; Ground.                                
                                                                            
;------------------------------------------------------------------------------
; CRC0AUTO Enums (CRC0 Automatic Control @ 0x96)
;------------------------------------------------------------------------------
CRC0AUTO_CRCST__FMASK     EQU 03FH ; Automatic CRC Calculation Starting Block  
CRC0AUTO_CRCST__SHIFT     EQU 000H ; Automatic CRC Calculation Starting Block  
                                                                               
CRC0AUTO_CRCDN__BMASK     EQU 040H ; Automatic CRC Calculation Complete        
CRC0AUTO_CRCDN__SHIFT     EQU 006H ; Automatic CRC Calculation Complete        
CRC0AUTO_CRCDN__NOT_SET   EQU 000H ; A CRC calculation is in progress.         
CRC0AUTO_CRCDN__SET       EQU 040H ; A CRC calculation is not in progress.     
                                                                               
CRC0AUTO_AUTOEN__BMASK    EQU 080H ; Automatic CRC Calculation Enable          
CRC0AUTO_AUTOEN__SHIFT    EQU 007H ; Automatic CRC Calculation Enable          
CRC0AUTO_AUTOEN__DISABLED EQU 000H ; Disable automatic CRC operations on flash.
CRC0AUTO_AUTOEN__ENABLED  EQU 080H ; Enable automatic CRC operations on flash. 
                                                                               
;------------------------------------------------------------------------------
; CRC0CN Enums (CRC0 Control @ 0x92)
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
; CRC0CNT Enums (CRC0 Automatic Flash Sector Count @ 0x97)
;------------------------------------------------------------------------------
CRC0CNT_CRCCNT__FMASK EQU 03FH ; Automatic CRC Calculation Block Count
CRC0CNT_CRCCNT__SHIFT EQU 000H ; Automatic CRC Calculation Block Count
                                                                      
;------------------------------------------------------------------------------
; CRC0DAT Enums (CRC0 Data Output @ 0x91)
;------------------------------------------------------------------------------
CRC0DAT_CRC0DAT__FMASK EQU 0FFH ; CRC Data Output
CRC0DAT_CRC0DAT__SHIFT EQU 000H ; CRC Data Output
                                                 
;------------------------------------------------------------------------------
; CRC0FLIP Enums (CRC0 Bit Flip @ 0x94)
;------------------------------------------------------------------------------
CRC0FLIP_CRC0FLIP__FMASK EQU 0FFH ; CRC0 Bit Flip
CRC0FLIP_CRC0FLIP__SHIFT EQU 000H ; CRC0 Bit Flip
                                                 
;------------------------------------------------------------------------------
; CRC0IN Enums (CRC0 Data Input @ 0x93)
;------------------------------------------------------------------------------
CRC0IN_CRC0IN__FMASK EQU 0FFH ; CRC Data Input
CRC0IN_CRC0IN__SHIFT EQU 000H ; CRC Data Input
                                              
;------------------------------------------------------------------------------
; CRC1CN Enums (CRC1 Control @ 0xBE)
;------------------------------------------------------------------------------
CRC1CN_SEED__BMASK      EQU 001H ; Seed Polarity                                   
CRC1CN_SEED__SHIFT      EQU 000H ; Seed Polarity                                   
CRC1CN_SEED__SET_ZEROES EQU 000H ; The CRC calculation uses an initial seed of     
                                 ; 0x0000.                                         
CRC1CN_SEED__SET_ONES   EQU 001H ; The CRC calculation uses an initial seed of     
                                 ; 0xFFFF.                                         
                                                                                   
CRC1CN_INVERT__BMASK    EQU 002H ; Invert Result Enable                            
CRC1CN_INVERT__SHIFT    EQU 001H ; Invert Result Enable                            
CRC1CN_INVERT__DISABLED EQU 000H ; Do not invert the CRC result in the CRC1OUT     
                                 ; registers.                                      
CRC1CN_INVERT__ENABLED  EQU 002H ; Invert the CRC result in the CRC1OUT registers. 
                                                                                   
CRC1CN_FLIP__BMASK      EQU 004H ; Flip Result Enable                              
CRC1CN_FLIP__SHIFT      EQU 002H ; Flip Result Enable                              
CRC1CN_FLIP__DISABLED   EQU 000H ; Do not bit flip the CRC result in the CRC1OUT   
                                 ; registers.                                      
CRC1CN_FLIP__ENABLED    EQU 004H ; Flip the CRC result in the CRC1OUT registers.   
                                                                                   
CRC1CN_DMA__BMASK       EQU 008H ; DMA Mode Enable                                 
CRC1CN_DMA__SHIFT       EQU 003H ; DMA Mode Enable                                 
CRC1CN_DMA__DISABLED    EQU 000H ; The CRC module is not in DMA mode.              
CRC1CN_DMA__ENABLED     EQU 008H ; The CRC module is in DMA mode.                  
                                                                                   
CRC1CN_RESET__BMASK     EQU 080H ; Module Reset and Initialize                     
CRC1CN_RESET__SHIFT     EQU 007H ; Module Reset and Initialize                     
CRC1CN_RESET__NOT_SET   EQU 000H ; Do not reset the CRC module or a reset operation
                                 ; completed.                                      
CRC1CN_RESET__SET       EQU 080H ; Reset the CRC module.                           
                                                                                   
;------------------------------------------------------------------------------
; CRC1IN Enums (CRC1 Data In @ 0xB9)
;------------------------------------------------------------------------------
CRC1IN_CRC1IN__FMASK EQU 0FFH ; CRC1 Data In
CRC1IN_CRC1IN__SHIFT EQU 000H ; CRC1 Data In
                                            
;------------------------------------------------------------------------------
; CRC1OUTH Enums (CRC1 Output High Byte @ 0xBB)
;------------------------------------------------------------------------------
CRC1OUTH_CRC1OUTH__FMASK EQU 0FFH ; CRC1 Output High Byte
CRC1OUTH_CRC1OUTH__SHIFT EQU 000H ; CRC1 Output High Byte
                                                         
;------------------------------------------------------------------------------
; CRC1OUTL Enums (CRC1 Output Low Byte @ 0xBA)
;------------------------------------------------------------------------------
CRC1OUTL_CRC1OUTL__FMASK EQU 0FFH ; CRC1 Output Low Byte
CRC1OUTL_CRC1OUTL__SHIFT EQU 000H ; CRC1 Output Low Byte
                                                        
;------------------------------------------------------------------------------
; CRC1POLH Enums (CRC1 Polynomial High Byte @ 0xBD)
;------------------------------------------------------------------------------
CRC1POLH_CRC1POLH__FMASK EQU 0FFH ; CRC1 Polynomial High Byte
CRC1POLH_CRC1POLH__SHIFT EQU 000H ; CRC1 Polynomial High Byte
                                                             
;------------------------------------------------------------------------------
; CRC1POLL Enums (CRC1 Polynomial Low Byte @ 0xBC)
;------------------------------------------------------------------------------
CRC1POLL_CRC1POLL__FMASK EQU 0FFH ; CRC1 Polynomial Low Byte
CRC1POLL_CRC1POLL__SHIFT EQU 000H ; CRC1 Polynomial Low Byte
                                                            
;------------------------------------------------------------------------------
; DC0CF Enums (DC-DC Converter Configuration @ 0xB2)
;------------------------------------------------------------------------------
DC0CF_SWSEL__FMASK        EQU 003H ; DC-DC Converter Power Switch Select               
DC0CF_SWSEL__SHIFT        EQU 000H ; DC-DC Converter Power Switch Select               
DC0CF_SWSEL__MINIMUM_SIZE EQU 000H ; Minimum switch size, optimized for load currents  
                                   ; smaller than 5 mA.                                
DC0CF_SWSEL__MAXIMUM_SIZE EQU 003H ; Maximum switch size, optimized for load currents  
                                   ; greater than 5 mA.                                
                                                                                       
DC0CF_OSCDIS__BMASK       EQU 004H ; DC-DC Converter Local Oscillator Disable          
DC0CF_OSCDIS__SHIFT       EQU 002H ; DC-DC Converter Local Oscillator Disable          
DC0CF_OSCDIS__ENABLED     EQU 000H ; The local oscillator inside the dc-dc converter is
                                   ; enabled.                                          
DC0CF_OSCDIS__DISABLED    EQU 004H ; The local oscillator inside the dc-dc converter is
                                   ; disabled.                                         
                                                                                       
DC0CF_VSEL__FMASK         EQU 078H ; DC-DC Converter Output Voltage Select             
DC0CF_VSEL__SHIFT         EQU 003H ; DC-DC Converter Output Voltage Select             
DC0CF_VSEL__1P8           EQU 000H ; Target output voltage is 1.8 V.                   
DC0CF_VSEL__1P9           EQU 008H ; Target output voltage is 1.9 V.                   
DC0CF_VSEL__2P0           EQU 010H ; Target output voltage is 2.0 V.                   
DC0CF_VSEL__2P1           EQU 018H ; Target output voltage is 2.1 V.                   
DC0CF_VSEL__2P2           EQU 020H ; Target output voltage is 2.2 V.                   
DC0CF_VSEL__2P3           EQU 028H ; Target output voltage is 2.3 V.                   
DC0CF_VSEL__2P4           EQU 030H ; Target output voltage is 2.4 V.                   
DC0CF_VSEL__2P5           EQU 038H ; Target output voltage is 2.5 V.                   
DC0CF_VSEL__2P6           EQU 040H ; Target output voltage is 2.6 V.                   
DC0CF_VSEL__2P7           EQU 048H ; Target output voltage is 2.7 V.                   
DC0CF_VSEL__2P8           EQU 050H ; Target output voltage is 2.8 V.                   
DC0CF_VSEL__2P9           EQU 058H ; Target output voltage is 2.9 V.                   
DC0CF_VSEL__3P0           EQU 060H ; Target output voltage is 3.0 V.                   
DC0CF_VSEL__3P1           EQU 068H ; Target output voltage is 3.1 V.                   
DC0CF_VSEL__3P3           EQU 070H ; Target output voltage is 3.3 V.                   
DC0CF_VSEL__3P5           EQU 078H ; Target output voltage is 3.5 V.                   
                                                                                       
DC0CF_BYPASS__BMASK       EQU 080H ; DC-DC Converter Bypass Switch Enable              
DC0CF_BYPASS__SHIFT       EQU 007H ; DC-DC Converter Bypass Switch Enable              
DC0CF_BYPASS__NORMAL      EQU 000H ; The bypass switch is open.                        
DC0CF_BYPASS__BYPASS      EQU 080H ; The bypass switch is closed (VDC is connected to  
                                   ; VBATDC).                                          
                                                                                       
;------------------------------------------------------------------------------
; DC0CN Enums (DC-DC Converter Control @ 0xB1)
;------------------------------------------------------------------------------
DC0CN_MINPW__FMASK           EQU 003H ; DC-DC Converter Minimum Pulse Width              
DC0CN_MINPW__SHIFT           EQU 000H ; DC-DC Converter Minimum Pulse Width              
DC0CN_MINPW__DISABLED        EQU 000H ; Minimum pulse detection logic is disabled (no    
                                      ; pulse skipping).                                 
DC0CN_MINPW__10_NS           EQU 001H ; Minimum pulse width is 10 ns.                    
DC0CN_MINPW__20_NS           EQU 002H ; Minimum pulse width is 20 ns.                    
DC0CN_MINPW__40_NS           EQU 003H ; Minimum pulse width is 40 ns.                    
                                                                                         
DC0CN_SYNC__BMASK            EQU 004H ; ADC0 Synchronization Enable                      
DC0CN_SYNC__SHIFT            EQU 002H ; ADC0 Synchronization Enable                      
DC0CN_SYNC__DISABLED         EQU 000H ; The ADC is not synchronized to the dc-dc         
                                      ; converter.                                       
DC0CN_SYNC__ENABLED          EQU 004H ; The ADC is synchronized to the dc-dc converter.  
                                                                                         
DC0CN_CLKINV__BMASK          EQU 008H ; DC-DC Converter Clock Invert                     
DC0CN_CLKINV__SHIFT          EQU 003H ; DC-DC Converter Clock Invert                     
DC0CN_CLKINV__INVERTED       EQU 000H ; The dc-dc converter clock is not inverted.       
DC0CN_CLKINV__NOT_INVERTED   EQU 008H ; The dc-dc converter clock is inverted.           
                                                                                         
DC0CN_AD0CKINV__BMASK        EQU 010H ; ADC0 Clock Inversion                             
DC0CN_AD0CKINV__SHIFT        EQU 004H ; ADC0 Clock Inversion                             
DC0CN_AD0CKINV__INVERTED     EQU 000H ; ADC0 SAR clock is inverted.                      
DC0CN_AD0CKINV__NOT_INVERTED EQU 010H ; ADC0 SAR clock is not inverted.                  
                                                                                         
DC0CN_CLKDIV__FMASK          EQU 060H ; DC-DC Clock Divider                              
DC0CN_CLKDIV__SHIFT          EQU 005H ; DC-DC Clock Divider                              
DC0CN_CLKDIV__SYSCLK_DIV_1   EQU 000H ; The dc-dc converter clock is system clock divided
                                      ; by 1.                                            
DC0CN_CLKDIV__SYSCLK_DIV_2   EQU 020H ; The dc-dc converter clock is system clock divided
                                      ; by 2.                                            
DC0CN_CLKDIV__SYSCLK_DIV_4   EQU 040H ; The dc-dc converter clock is system clock divided
                                      ; by 4.                                            
DC0CN_CLKDIV__SYSCLK_DIV_8   EQU 060H ; The dc-dc converter clock is system clock divided
                                      ; by 8.                                            
                                                                                         
DC0CN_CLKSEL__BMASK          EQU 080H ; DC-DC Converter Clock Source Select              
DC0CN_CLKSEL__SHIFT          EQU 007H ; DC-DC Converter Clock Source Select              
DC0CN_CLKSEL__LOCAL          EQU 000H ; The dc-dc converter is clocked from its local    
                                      ; oscillator.                                      
DC0CN_CLKSEL__SYSCLK         EQU 080H ; The dc-dc converter is clocked from the system   
                                      ; clock.                                           
                                                                                         
;------------------------------------------------------------------------------
; DC0MD Enums (DC-DC Converter Mode @ 0xB3)
;------------------------------------------------------------------------------
DC0MD_DC0EN__BMASK      EQU 001H ; DC-DC Converter Enable                    
DC0MD_DC0EN__SHIFT      EQU 000H ; DC-DC Converter Enable                    
DC0MD_DC0EN__DISABLED   EQU 000H ; Disable the DC-DC converter.              
DC0MD_DC0EN__ENABLED    EQU 001H ; Enable the DC-DC converter.               
                                                                             
DC0MD_AUTOBYP__BMASK    EQU 004H ; Automatic Bypass Mode Enable              
DC0MD_AUTOBYP__SHIFT    EQU 002H ; Automatic Bypass Mode Enable              
DC0MD_AUTOBYP__DISABLED EQU 000H ; Disable automatic bypass mode.            
DC0MD_AUTOBYP__ENABLED  EQU 004H ; Enable automatic bypass mode.             
                                                                             
DC0MD_FORBYP__BMASK     EQU 008H ; Forced Bypass Mode Enable                 
DC0MD_FORBYP__SHIFT     EQU 003H ; Forced Bypass Mode Enable                 
DC0MD_FORBYP__DISABLED  EQU 000H ; Disable forced bypass mode.               
DC0MD_FORBYP__ENABLED   EQU 008H ; Enable forced bypass mode.                
                                                                             
DC0MD_ILIMIT__FMASK     EQU 070H ; Peak Current Limit Threshold              
DC0MD_ILIMIT__SHIFT     EQU 004H ; Peak Current Limit Threshold              
DC0MD_ILIMIT__200_MA    EQU 010H ; Peak Inductor current is limited to 200 mA
DC0MD_ILIMIT__300_MA    EQU 020H ; Peak Inductor current is limited to 300 mA
DC0MD_ILIMIT__400_MA    EQU 030H ; Peak Inductor current is limited to 400 mA
DC0MD_ILIMIT__500_MA    EQU 040H ; Peak Inductor current is limited to 500 mA
DC0MD_ILIMIT__600_MA    EQU 050H ; Peak Inductor current is limited to 600 mA
                                                                             
;------------------------------------------------------------------------------
; DC0RDY Enums (DC-DC Converter Ready @ 0xFD)
;------------------------------------------------------------------------------
DC0RDY_RDYL__BMASK   EQU 040H ; DC0 Ready Indicator (Low Threshold)          
DC0RDY_RDYL__SHIFT   EQU 006H ; DC0 Ready Indicator (Low Threshold)          
DC0RDY_RDYL__NOT_SET EQU 000H ; VDC pin voltage is less than the DCDC0 Low   
                              ; Threshold.                                   
DC0RDY_RDYL__SET     EQU 040H ; VDC pin voltage is higher than the DCDC0 Low 
                              ; Threshold.                                   
                                                                             
DC0RDY_RDYH__BMASK   EQU 080H ; DC0 Ready Indicator (High Threshold)         
DC0RDY_RDYH__SHIFT   EQU 007H ; DC0 Ready Indicator (High Threshold)         
DC0RDY_RDYH__NOT_SET EQU 000H ; VDC pin voltage is less than the DCDC0 High  
                              ; Threshold.                                   
DC0RDY_RDYH__SET     EQU 080H ; VDC pin voltage is higher than the DCDC0 High
                              ; Threshold.                                   
                                                                             
;------------------------------------------------------------------------------
; DERIVID Enums (Device Identification @ 0xE9)
;------------------------------------------------------------------------------
DERIVID_DERIVID__FMASK           EQU 0FFH ; Derivative ID  
DERIVID_DERIVID__SHIFT           EQU 000H ; Derivative ID  
DERIVID_DERIVID__C8051F960_GM_GU EQU 0D0H ; C8051F960-GM/GU
DERIVID_DERIVID__C8051F961_GM    EQU 0D1H ; C8051F961-GM   
DERIVID_DERIVID__C8051F962_GM_GU EQU 0D2H ; C8051F962-GM/GU
DERIVID_DERIVID__C8051F963_GM    EQU 0D3H ; C8051F963-GM   
DERIVID_DERIVID__C8051F964_GM_GU EQU 0D4H ; C8051F964-GM/GU
DERIVID_DERIVID__C8051F965_GM    EQU 0D5H ; C8051F965-GM   
DERIVID_DERIVID__C8051F966_GM_GU EQU 0D6H ; C8051F966-GM/GU
DERIVID_DERIVID__C8051F967_GM    EQU 0D7H ; C8051F967-GM   
DERIVID_DERIVID__C8051F968_GM_GU EQU 0D8H ; C8051F968-GM/GU
DERIVID_DERIVID__C8051F969_GM    EQU 0D9H ; C8051F969-GM   
                                                           
;------------------------------------------------------------------------------
; REVID Enums (Revision Identifcation @ 0xEA)
;------------------------------------------------------------------------------
REVID_REVID__FMASK EQU 0FFH ; Revision ID
REVID_REVID__SHIFT EQU 000H ; Revision ID
REVID_REVID__REV_A EQU 000H ; Revision A 
                                         
;------------------------------------------------------------------------------
; DMA0BUSY Enums (DMA0 Busy @ 0xD5)
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
; DMA0EN Enums (DMA0 Channel Enable @ 0xD2)
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
; DMA0INT Enums (DMA0 Full-Length Interrupt Flags @ 0xD3)
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
; DMA0MINT Enums (DMA0 Mid-Point Interrupt Flags @ 0xD4)
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
; DMA0NAOH Enums (Memory Address Offset High @ 0xCD)
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
; DMA0NAOL Enums (Memory Address Offset Low @ 0xCC)
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
; DMA0NBAH Enums (Memory Base Address High @ 0xCB)
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
; DMA0NBAL Enums (Memory Base Address Low @ 0xCA)
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
; DMA0NCF Enums (DMA0 Channel Configuration @ 0xC9)
;------------------------------------------------------------------------------
DMA0NCF_PERIPH__FMASK            EQU 00FH ; Peripheral Transfer Select                        
DMA0NCF_PERIPH__SHIFT            EQU 000H ; Peripheral Transfer Select                        
DMA0NCF_PERIPH__XRAM_TO_ENCDEC0  EQU 000H ; The DMA channel transfers from XRAM to the        
                                          ; ENC0H:M:L registers.                              
DMA0NCF_PERIPH__ENCDEC0_TO_XRAM  EQU 001H ; The DMA channel transfers from the ENC0H:M:L      
                                          ; registers to XRAM.                                
DMA0NCF_PERIPH__XRAM_TO_CRC1     EQU 002H ; The DMA channel transfers from XRAM to the CRC1IN 
                                          ; register.                                         
DMA0NCF_PERIPH__XRAM_TO_SPI1     EQU 003H ; The DMA channel transfers from XRAM to the SPI1DAT
                                          ; register.                                         
DMA0NCF_PERIPH__SPI1_TO_XRAM     EQU 004H ; The DMA channel transfers from the SPI1DAT        
                                          ; register to XRAM.                                 
DMA0NCF_PERIPH__XRAM_TO_AES0_KEY EQU 005H ; The DMA channel transfers from XRAM to the AES0   
                                          ; key input (AES0KIN) register.                     
DMA0NCF_PERIPH__XRAM_TO_AES0_B   EQU 006H ; The DMA channel transfers from XRAM to the AES0 B 
                                          ; input (AES0BIN) register.                         
DMA0NCF_PERIPH__XRAM_TO_AES0_XOR EQU 007H ; The DMA channel transfers from XRAM to the AES0   
                                          ; XOR input (AES0XIN) register.                     
DMA0NCF_PERIPH__AES0_Y_TO_XRAM   EQU 008H ; The DMA channel transfers from the AES0 Y output  
                                          ; (AES0YOUT) register to XRAM.                      
                                                                                              
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
; DMA0NMD Enums (DMA Channel Mode @ 0xD6)
;------------------------------------------------------------------------------
DMA0NMD_WRAP__BMASK    EQU 001H ; Wrap Enable                                  
DMA0NMD_WRAP__SHIFT    EQU 000H ; Wrap Enable                                  
DMA0NMD_WRAP__DISABLED EQU 000H ; Disable wrapping on the selected DMA channel.
DMA0NMD_WRAP__ENABLED  EQU 001H ; Enable wrapping on the selected DMA channel. 
                                                                               
;------------------------------------------------------------------------------
; DMA0NSZH Enums (Memory Transfer Size High @ 0xCF)
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
; DMA0NSZL Enums (Memory Transfer Size Low @ 0xCE)
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
; DMA0SEL Enums (DMA0 Channel Select @ 0xD1)
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
; ENC0CN Enums (Encoder / Decoder 0 Control @ 0xC5)
;------------------------------------------------------------------------------
ENC0CN_MODE__BMASK               EQU 001H ; Operation Mode                                    
ENC0CN_MODE__SHIFT               EQU 000H ; Operation Mode                                    
ENC0CN_MODE__MANCHESTER          EQU 000H ; Select Manchester encoding or decoding.           
ENC0CN_MODE__THREE_OUT_OF_SIX    EQU 001H ; Select Three-out-of-Six encoding or decoding.     
                                                                                              
ENC0CN_ENDIAN__BMASK             EQU 002H ; Big-Endian DMA Mode Select                        
ENC0CN_ENDIAN__SHIFT             EQU 001H ; Big-Endian DMA Mode Select                        
ENC0CN_ENDIAN__DMA_LITTLE_ENDIAN EQU 000H ; Configure the Encoder / Decoder for little-endian 
                                          ; multiple-byte DMA transfers.                      
ENC0CN_ENDIAN__DMA_BIG_ENDIAN    EQU 002H ; Configure the Encoder / Decoder for big-endian    
                                          ; multiple-byte DMA transfers.                      
                                                                                              
ENC0CN_DMA__BMASK                EQU 004H ; DMA Mode Enable                                   
ENC0CN_DMA__SHIFT                EQU 002H ; DMA Mode Enable                                   
ENC0CN_DMA__DISABLED             EQU 000H ; Disable DMA mode.                                 
ENC0CN_DMA__ENABLED              EQU 004H ; Enable DMA mode.                                  
                                                                                              
ENC0CN_DEC__BMASK                EQU 010H ; Decode                                            
ENC0CN_DEC__SHIFT                EQU 004H ; Decode                                            
ENC0CN_DEC__START                EQU 010H ; Start a decode operation.                         
                                                                                              
ENC0CN_ENC__BMASK                EQU 020H ; Encode                                            
ENC0CN_ENC__SHIFT                EQU 005H ; Encode                                            
ENC0CN_ENC__START                EQU 020H ; Start an encode operation.                        
                                                                                              
ENC0CN_ERROR__BMASK              EQU 040H ; Error Flag                                        
ENC0CN_ERROR__SHIFT              EQU 006H ; Error Flag                                        
ENC0CN_ERROR__NOT_SET            EQU 000H ; An error did not occur during the decode or encode
                                          ; operation.                                        
ENC0CN_ERROR__SET                EQU 040H ; An error occurred during the decode or encode     
                                          ; operation.                                        
                                                                                              
ENC0CN_READY__BMASK              EQU 080H ; Ready Flag                                        
ENC0CN_READY__SHIFT              EQU 007H ; Ready Flag                                        
ENC0CN_READY__NOT_SET            EQU 000H ; An encode or decode operation is not in progress. 
ENC0CN_READY__SET                EQU 080H ; An encode or decode operation is in progress.     
                                                                                              
;------------------------------------------------------------------------------
; ENC0H Enums (Encoder / Decoder 0 Data High Byte @ 0xC4)
;------------------------------------------------------------------------------
ENC0H_ENC0H__FMASK EQU 0FFH ; Encoder / Decoder 0 Data High Byte
ENC0H_ENC0H__SHIFT EQU 000H ; Encoder / Decoder 0 Data High Byte
                                                                
;------------------------------------------------------------------------------
; ENC0L Enums (Encoder / Decoder 0 Data Low Byte @ 0xC2)
;------------------------------------------------------------------------------
ENC0L_ENC0L__FMASK EQU 0FFH ; Encoder / Decoder 0 Data Low Byte
ENC0L_ENC0L__SHIFT EQU 000H ; Encoder / Decoder 0 Data Low Byte
                                                               
;------------------------------------------------------------------------------
; ENC0M Enums (Encoder / Decoder 0 Data Middle Byte @ 0xC3)
;------------------------------------------------------------------------------
ENC0M_ENC0M__FMASK EQU 0FFH ; Encoder / Decoder 0 Data Middle Byte
ENC0M_ENC0M__SHIFT EQU 000H ; Encoder / Decoder 0 Data Middle Byte
                                                                  
;------------------------------------------------------------------------------
; IT01CF Enums (INT0/INT1 Configuration @ 0xE4)
;------------------------------------------------------------------------------
IT01CF_IN0SL__BMASK       EQU 001H ; INT0 Port Pin Selection   
IT01CF_IN0SL__SHIFT       EQU 000H ; INT0 Port Pin Selection   
IT01CF_IN0SL__P0_0        EQU 000H ; Select P0.0.              
IT01CF_IN0SL__P0_1        EQU 001H ; Select P0.1.              
IT01CF_IN0SL__P0_2        EQU 002H ; Select P0.2.              
IT01CF_IN0SL__P0_3        EQU 003H ; Select P0.3.              
IT01CF_IN0SL__P0_4        EQU 004H ; Select P0.4.              
IT01CF_IN0SL__P0_5        EQU 005H ; Select P0.5.              
IT01CF_IN0SL__P1_6        EQU 006H ; Select P1.6.              
IT01CF_IN0SL__P1_7        EQU 007H ; Select P1.7.              
                                                               
IT01CF_IN0PL__BMASK       EQU 008H ; INT0 Polarity             
IT01CF_IN0PL__SHIFT       EQU 003H ; INT0 Polarity             
IT01CF_IN0PL__ACTIVE_LOW  EQU 000H ; INT0 input is active low. 
IT01CF_IN0PL__ACTIVE_HIGH EQU 008H ; INT0 input is active high.
                                                               
IT01CF_IN1SL__BMASK       EQU 010H ; INT1 Port Pin Selection   
IT01CF_IN1SL__SHIFT       EQU 004H ; INT1 Port Pin Selection   
IT01CF_IN1SL__P0_0        EQU 000H ; Select P0.0.              
IT01CF_IN1SL__P0_1        EQU 010H ; Select P0.1.              
IT01CF_IN1SL__P0_2        EQU 020H ; Select P0.2.              
IT01CF_IN1SL__P0_3        EQU 030H ; Select P0.3.              
IT01CF_IN1SL__P0_4        EQU 040H ; Select P0.4.              
IT01CF_IN1SL__P0_5        EQU 050H ; Select P0.5.              
IT01CF_IN1SL__P1_6        EQU 060H ; Select P1.6.              
IT01CF_IN1SL__P1_7        EQU 070H ; Select P1.7.              
                                                               
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
FLSCL_BYPASS__ONE_SHOT EQU 000H ; The one-shot determines the Flash read time.    
FLSCL_BYPASS__SYSCLK   EQU 040H ; The system clock determines the Flash read time.
                                                                                  
;------------------------------------------------------------------------------
; FLWR Enums (Flash Write Only @ 0xE5)
;------------------------------------------------------------------------------
FLWR_FLWR__FMASK EQU 0FFH ; Flash Write Only
FLWR_FLWR__SHIFT EQU 000H ; Flash Write Only
                                            
;------------------------------------------------------------------------------
; FRBCN Enums (Flash Read Buffer Control @ 0xB5)
;------------------------------------------------------------------------------
FRBCN_FLBLKWR__BMASK                EQU 001H ; Block Write Enable                            
FRBCN_FLBLKWR__SHIFT                EQU 000H ; Block Write Enable                            
FRBCN_FLBLKWR__BLOCK_WRITE_DISABLED EQU 000H ; Each byte of a firmware flash write is written
                                             ; individually.                                 
FRBCN_FLBLKWR__BLOCK_WRITE_ENABLED  EQU 001H ; Flash bytes are written in groups of four.    
                                                                                             
FRBCN_FRBD__BMASK                   EQU 002H ; Flash Read Buffer Bypass                      
FRBCN_FRBD__SHIFT                   EQU 001H ; Flash Read Buffer Bypass                      
FRBCN_FRBD__NORMAL                  EQU 000H ; Flash read buffer is enabled and being used.  
FRBCN_FRBD__BYPASS                  EQU 002H ; Flash read buffer is disabled and bypassed.   
                                                                                             
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
; EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
;------------------------------------------------------------------------------
EIE1_ESMB0__BMASK     EQU 001H ; SMBus (SMB0) Interrupt Enable                     
EIE1_ESMB0__SHIFT     EQU 000H ; SMBus (SMB0) Interrupt Enable                     
EIE1_ESMB0__DISABLED  EQU 000H ; Disable all SMB0 interrupts.                      
EIE1_ESMB0__ENABLED   EQU 001H ; Enable interrupt requests generated by SMB0.      
                                                                                   
EIE1_ERTC0A__BMASK    EQU 002H ; RTC Alarm Interrupt Enable                        
EIE1_ERTC0A__SHIFT    EQU 001H ; RTC Alarm Interrupt Enable                        
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
EIE2_EWARN__BMASK     EQU 001H ; VDD/VBAT Supply Monitor Early Warning Interrupt Enable
EIE2_EWARN__SHIFT     EQU 000H ; VDD/VBAT Supply Monitor Early Warning Interrupt Enable
EIE2_EWARN__DISABLED  EQU 000H ; Disable the VDD/VBAT Supply Monitor Early Warning     
                               ; interrupt.                                            
EIE2_EWARN__ENABLED   EQU 001H ; Enable interrupt requests generated by the            
                               ; VDD/VBAT Supply Monitor.                              
                                                                                       
EIE2_EMAT__BMASK      EQU 002H ; Port Match Interrupts Enable                          
EIE2_EMAT__SHIFT      EQU 001H ; Port Match Interrupts Enable                          
EIE2_EMAT__DISABLED   EQU 000H ; Disable all Port Match interrupts.                    
EIE2_EMAT__ENABLED    EQU 002H ; Enable interrupt requests generated by a Port         
                               ; Match.                                                
                                                                                       
EIE2_ERTC0F__BMASK    EQU 004H ; RTC Oscillator Fail Interrupt Enable                  
EIE2_ERTC0F__SHIFT    EQU 002H ; RTC Oscillator Fail Interrupt Enable                  
EIE2_ERTC0F__DISABLED EQU 000H ; Disable RTC Oscillator Fail interrupts.               
EIE2_ERTC0F__ENABLED  EQU 004H ; Enable interrupt requests generated by the RTC        
                               ; Oscillator Fail event.                                
                                                                                       
EIE2_ESPI1__BMASK     EQU 008H ; Serial Peripheral Interface (SPI1) Interrupt Enable   
EIE2_ESPI1__SHIFT     EQU 003H ; Serial Peripheral Interface (SPI1) Interrupt Enable   
EIE2_ESPI1__DISABLED  EQU 000H ; Disable all SPI1 interrupts.                          
EIE2_ESPI1__ENABLED   EQU 008H ; Enable interrupt requests generated by SPI1.          
                                                                                       
EIE2_EPC0__BMASK      EQU 010H ; Pulse Counter (PC0) Interrupt Enable                  
EIE2_EPC0__SHIFT      EQU 004H ; Pulse Counter (PC0) Interrupt Enable                  
EIE2_EPC0__DISABLED   EQU 000H ; Disable all PC0 interrupts.                           
EIE2_EPC0__ENABLED    EQU 010H ; Enable interrupt requests generated by PC0.           
                                                                                       
EIE2_EDMA0__BMASK     EQU 020H ; DMA0 Interrupt Enable                                 
EIE2_EDMA0__SHIFT     EQU 005H ; DMA0 Interrupt Enable                                 
EIE2_EDMA0__DISABLED  EQU 000H ; Disable all DMA0 interrupts.                          
EIE2_EDMA0__ENABLED   EQU 020H ; Enable interrupt requests generated by DMA0.          
                                                                                       
EIE2_EENC0__BMASK     EQU 040H ; Encoder / Decoder (ENCDEC0) Interrupt Enable          
EIE2_EENC0__SHIFT     EQU 006H ; Encoder / Decoder (ENCDEC0) Interrupt Enable          
EIE2_EENC0__DISABLED  EQU 000H ; Disable all ENCDEC0 interrupts.                       
EIE2_EENC0__ENABLED   EQU 040H ; Enable interrupt requests generated by ENCDEC0.       
                                                                                       
EIE2_EAES0__BMASK     EQU 080H ; AES0 Interrupt                                        
EIE2_EAES0__SHIFT     EQU 007H ; AES0 Interrupt                                        
EIE2_EAES0__DISABLED  EQU 000H ; Disable all AES0 interrupts.                          
EIE2_EAES0__ENABLED   EQU 080H ; Enable interrupt requests generated by AES0.          
                                                                                       
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
EIP2_PWARN__BMASK  EQU 001H ; VDD/VBAT Supply Monitor Early Warning Interrupt Priority Control
EIP2_PWARN__SHIFT  EQU 000H ; VDD/VBAT Supply Monitor Early Warning Interrupt Priority Control
EIP2_PWARN__LOW    EQU 000H ; VDD/VBAT Supply Monitor Early Warning interrupt                 
                            ; set to low priority level.                                      
EIP2_PWARN__HIGH   EQU 001H ; VDD/VBAT Supply Monitor Early Warning interrupt                 
                            ; set to high priority level.                                     
                                                                                              
EIP2_PMAT__BMASK   EQU 002H ; Port Match Interrupt Priority Control                           
EIP2_PMAT__SHIFT   EQU 001H ; Port Match Interrupt Priority Control                           
EIP2_PMAT__LOW     EQU 000H ; Port Match interrupt set to low priority level.                 
EIP2_PMAT__HIGH    EQU 002H ; Port Match interrupt set to high priority level.                
                                                                                              
EIP2_PRTC0F__BMASK EQU 004H ; RTC Oscillator Fail Interrupt Priority Control                  
EIP2_PRTC0F__SHIFT EQU 002H ; RTC Oscillator Fail Interrupt Priority Control                  
EIP2_PRTC0F__LOW   EQU 000H ; RTC Oscillator Fail interrupt set to low priority               
                            ; level.                                                          
EIP2_PRTC0F__HIGH  EQU 004H ; RTC Oscillator Fail interrupt set to high priority              
                            ; level.                                                          
                                                                                              
EIP2_PSPI1__BMASK  EQU 008H ; Serial Peripheral Interface (SPI1) Interrupt Priority Control   
EIP2_PSPI1__SHIFT  EQU 003H ; Serial Peripheral Interface (SPI1) Interrupt Priority Control   
EIP2_PSPI1__LOW    EQU 000H ; SPI1 interrupt set to low priority level.                       
EIP2_PSPI1__HIGH   EQU 008H ; SPI1 interrupt set to high priority level.                      
                                                                                              
EIP2_PPC0__BMASK   EQU 010H ; Pulse Counter (PC0) Interrupt Priority Control                  
EIP2_PPC0__SHIFT   EQU 004H ; Pulse Counter (PC0) Interrupt Priority Control                  
EIP2_PPC0__LOW     EQU 000H ; PC0 interrupt set to low priority level.                        
EIP2_PPC0__HIGH    EQU 010H ; PC0 interrupt set to high priority level.                       
                                                                                              
EIP2_PDMA0__BMASK  EQU 020H ; DMA0 Interrupt Priority Control                                 
EIP2_PDMA0__SHIFT  EQU 005H ; DMA0 Interrupt Priority Control                                 
EIP2_PDMA0__LOW    EQU 000H ; DMA0 interrupt set to low priority level.                       
EIP2_PDMA0__HIGH   EQU 020H ; DMA0 interrupt set to high priority level.                      
                                                                                              
EIP2_PENC0__BMASK  EQU 040H ; Encoder / Decoder (ENCDEC0) Interrupt Priority Control          
EIP2_PENC0__SHIFT  EQU 006H ; Encoder / Decoder (ENCDEC0) Interrupt Priority Control          
EIP2_PENC0__LOW    EQU 000H ; ENCDEC0 interrupt set to low priority level.                    
EIP2_PENC0__HIGH   EQU 040H ; ENCDEC0 interrupt set to high priority level.                   
                                                                                              
EIP2_PAES0__BMASK  EQU 080H ; AES0 Interrupt Priority Control                                 
EIP2_PAES0__SHIFT  EQU 007H ; AES0 Interrupt Priority Control                                 
EIP2_PAES0__LOW    EQU 000H ; AES0 interrupt set to low priority level.                       
EIP2_PAES0__HIGH   EQU 080H ; AES0 interrupt set to high priority level.                      
                                                                                              
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
; IREF0CF Enums (Current Reference Configuration @ 0xB9)
;------------------------------------------------------------------------------
IREF0CF_PWMSS__FMASK             EQU 007H ; PWM Source Select                               
IREF0CF_PWMSS__SHIFT             EQU 000H ; PWM Source Select                               
IREF0CF_PWMSS__FINE_TUNE_CEX0    EQU 000H ; CEX0 selected as the fine-tuning control signal.
IREF0CF_PWMSS__FINE_TUNE_CEX1    EQU 001H ; CEX1 selected as the fine-tuning control signal.
IREF0CF_PWMSS__FINE_TUNE_CEX2    EQU 002H ; CEX2 selected as the fine-tuning control signal.
IREF0CF_PWMSS__FINE_TUNE_CEX3    EQU 003H ; CEX3 selected as the fine-tuning control signal.
IREF0CF_PWMSS__FINE_TUNE_CEX4    EQU 004H ; CEX4 selected as the fine-tuning control signal.
IREF0CF_PWMSS__FINE_TUNE_CEX5    EQU 005H ; CEX5 selected as the fine-tuning control signal.
                                                                                            
IREF0CF_PWMEN__BMASK             EQU 080H ; PWM Enhanced Mode Enable                        
IREF0CF_PWMEN__SHIFT             EQU 007H ; PWM Enhanced Mode Enable                        
IREF0CF_PWMEN__ENHANCED_DISABLED EQU 000H ; Disable PWM Enhanced Mode.                      
IREF0CF_PWMEN__ENHANCED_ENABLED  EQU 080H ; Enable PWM Enhanced Mode.                       
                                                                                            
;------------------------------------------------------------------------------
; IREF0CN Enums (Current Reference Control @ 0xB9)
;------------------------------------------------------------------------------
IREF0CN_IREF0DAT__FMASK     EQU 03FH ; IREF0 Data Word                                  
IREF0CN_IREF0DAT__SHIFT     EQU 000H ; IREF0 Data Word                                  
                                                                                        
IREF0CN_MDSEL__BMASK        EQU 040H ; IREF0 Output Mode Select                         
IREF0CN_MDSEL__SHIFT        EQU 006H ; IREF0 Output Mode Select                         
IREF0CN_MDSEL__LOW_POWER    EQU 000H ; Low Current Mode is selected (step size = 1 uA). 
IREF0CN_MDSEL__HIGH_CURRENT EQU 040H ; High Current Mode is selected (step size = 8 uA).
                                                                                        
IREF0CN_SINK__BMASK         EQU 080H ; IREF0 Current Sink Enable                        
IREF0CN_SINK__SHIFT         EQU 007H ; IREF0 Current Sink Enable                        
IREF0CN_SINK__DISABLED      EQU 000H ; IREF0 is a current source.                       
IREF0CN_SINK__ENABLED       EQU 080H ; IREF0 is a current sink.                         
                                                                                        
;------------------------------------------------------------------------------
; LCD0BLINK Enums (LCD0 Blink Mask @ 0x9E)
;------------------------------------------------------------------------------
LCD0BLINK_LCD0BLKP0__FMASK EQU 00FH ; LCD0 Blink Mask Pin 0
LCD0BLINK_LCD0BLKP0__SHIFT EQU 000H ; LCD0 Blink Mask Pin 0
                                                           
LCD0BLINK_LCD0BLKP1__FMASK EQU 0F0H ; LCD0 Blink Mask Pin 1
LCD0BLINK_LCD0BLKP1__SHIFT EQU 004H ; LCD0 Blink Mask Pin 1
                                                           
;------------------------------------------------------------------------------
; LCD0CF Enums (LCD0 Configuration @ 0xA5)
;------------------------------------------------------------------------------
LCD0CF_CMPBYP__BMASK    EQU 020H ; VLCD/VIO Supply Comparator Bypass              
LCD0CF_CMPBYP__SHIFT    EQU 005H ; VLCD/VIO Supply Comparator Bypass              
LCD0CF_CMPBYP__NORMAL   EQU 000H ; VLCD/VIO supply voltage comparator is not      
                                 ; bypassed.                                      
LCD0CF_CMPBYP__BYPASSED EQU 020H ; VLCD/VIO supply voltage comparator is bypassed.
                                                                                  
;------------------------------------------------------------------------------
; LCD0CLKDIVH Enums (LCD0 Refresh Rate Prescaler High Byte @ 0xAA)
;------------------------------------------------------------------------------
LCD0CLKDIVH_LCDDIV__FMASK EQU 003H ; LCD Refresh Rate Prescaler
LCD0CLKDIVH_LCDDIV__SHIFT EQU 000H ; LCD Refresh Rate Prescaler
                                                               
;------------------------------------------------------------------------------
; LCD0CLKDIVL Enums (LCD Refresh Rate Prescaler Low Byte @ 0xA9)
;------------------------------------------------------------------------------
LCD0CLKDIVL_LCDDIV__FMASK EQU 0FFH ; LCD Refresh Rate Prescaler
LCD0CLKDIVL_LCDDIV__SHIFT EQU 000H ; LCD Refresh Rate Prescaler
                                                               
;------------------------------------------------------------------------------
; LCD0CN Enums (LCD0 Control @ 0x9D)
;------------------------------------------------------------------------------
LCD0CN_BIAS__BMASK       EQU 001H ; Bias Select                                   
LCD0CN_BIAS__SHIFT       EQU 000H ; Bias Select                                   
LCD0CN_BIAS__ONE_THIRD   EQU 000H ; LCD0 is configured for 1/3 Bias.              
LCD0CN_BIAS__ONE_HALF    EQU 001H ; LCD0 is configured for 1/2 Bias.              
                                                                                  
LCD0CN_MUXMD__FMASK      EQU 006H ; Multiplexer Mode                              
LCD0CN_MUXMD__SHIFT      EQU 001H ; Multiplexer Mode                              
LCD0CN_MUXMD__STATIC     EQU 000H ; Select static mode (COM0 used).               
LCD0CN_MUXMD__2_MUX_MODE EQU 002H ; Select 2-mux mode (COM0 and COM1 used).       
LCD0CN_MUXMD__3_MUX_MODE EQU 004H ; Select 3-mux mode (COM0, COM1, and COM2 used).
LCD0CN_MUXMD__4_MUX_MODE EQU 006H ; Select 4-mux mode (COM0, COM1, COM2, and COM3 
                                  ; used).                                        
                                                                                  
LCD0CN_SIZE__BMASK       EQU 008H ; LCD Size Select                               
LCD0CN_SIZE__SHIFT       EQU 003H ; LCD Size Select                               
LCD0CN_SIZE__16_PINS     EQU 000H ; Use P0 and P1 as LCD segment pins.            
LCD0CN_SIZE__32_PINS     EQU 008H ; Use P0, P1, P2, and P3 as LCD segment pins.   
                                                                                  
LCD0CN_BLANK__BMASK      EQU 010H ; Blank All Segments Enable                     
LCD0CN_BLANK__SHIFT      EQU 004H ; Blank All Segments Enable                     
LCD0CN_BLANK__DISABLED   EQU 000H ; All LCD segments are controlled by the LCD0Dn 
                                  ; registers.                                    
LCD0CN_BLANK__ENABLED    EQU 010H ; All LCD segments are blank (turned off).      
                                                                                  
LCD0CN_CLKDIV__FMASK     EQU 060H ; LCD0 Clock Divider                            
LCD0CN_CLKDIV__SHIFT     EQU 005H ; LCD0 Clock Divider                            
LCD0CN_CLKDIV__RTC_DIV_1 EQU 000H ; The LCD clock is the RTC clock divided by 1.  
LCD0CN_CLKDIV__RTC_DIV_2 EQU 020H ; The LCD clock is the RTC clock divided by 2.  
LCD0CN_CLKDIV__RTC_DIV_4 EQU 040H ; The LCD clock is the RTC clock divided by 4.  
                                                                                  
;------------------------------------------------------------------------------
; LCD0CNTRST Enums (LCD0 Contrast Adjustment @ 0x9C)
;------------------------------------------------------------------------------
LCD0CNTRST_CNTRST__FMASK EQU 01FH ; Contrast Setpoint                  
LCD0CNTRST_CNTRST__SHIFT EQU 000H ; Contrast Setpoint                  
LCD0CNTRST_CNTRST__1P90  EQU 000H ; Set the contrast voltage to 1.90 V.
LCD0CNTRST_CNTRST__1P96  EQU 001H ; Set the contrast voltage to 1.96 V.
LCD0CNTRST_CNTRST__2P02  EQU 002H ; Set the contrast voltage to 2.02 V.
LCD0CNTRST_CNTRST__2P08  EQU 003H ; Set the contrast voltage to 2.08 V.
LCD0CNTRST_CNTRST__2P13  EQU 004H ; Set the contrast voltage to 2.13 V.
LCD0CNTRST_CNTRST__2P19  EQU 005H ; Set the contrast voltage to 2.19 V.
LCD0CNTRST_CNTRST__2P25  EQU 006H ; Set the contrast voltage to 2.25 V.
LCD0CNTRST_CNTRST__2P31  EQU 007H ; Set the contrast voltage to 2.31 V.
LCD0CNTRST_CNTRST__2P37  EQU 008H ; Set the contrast voltage to 2.37 V.
LCD0CNTRST_CNTRST__2P43  EQU 009H ; Set the contrast voltage to 2.43 V.
LCD0CNTRST_CNTRST__2P49  EQU 00AH ; Set the contrast voltage to 2.49 V.
LCD0CNTRST_CNTRST__2P55  EQU 00BH ; Set the contrast voltage to 2.55 V.
LCD0CNTRST_CNTRST__2P60  EQU 00CH ; Set the contrast voltage to 2.60 V.
LCD0CNTRST_CNTRST__2P66  EQU 00DH ; Set the contrast voltage to 2.66 V.
LCD0CNTRST_CNTRST__2P72  EQU 00EH ; Set the contrast voltage to 2.72 V.
LCD0CNTRST_CNTRST__2P78  EQU 00FH ; Set the contrast voltage to 2.78 V.
LCD0CNTRST_CNTRST__2P84  EQU 010H ; Set the contrast voltage to 2.84 V.
LCD0CNTRST_CNTRST__2P90  EQU 011H ; Set the contrast voltage to 2.90 V.
LCD0CNTRST_CNTRST__2P96  EQU 012H ; Set the contrast voltage to 2.96 V.
LCD0CNTRST_CNTRST__3P02  EQU 013H ; Set the contrast voltage to 3.02 V.
LCD0CNTRST_CNTRST__3P07  EQU 014H ; Set the contrast voltage to 3.07 V.
LCD0CNTRST_CNTRST__3P13  EQU 015H ; Set the contrast voltage to 3.13 V.
LCD0CNTRST_CNTRST__3P19  EQU 016H ; Set the contrast voltage to 3.19 V.
LCD0CNTRST_CNTRST__3P25  EQU 017H ; Set the contrast voltage to 3.25 V.
LCD0CNTRST_CNTRST__3P31  EQU 018H ; Set the contrast voltage to 3.31 V.
LCD0CNTRST_CNTRST__3P37  EQU 019H ; Set the contrast voltage to 3.37 V.
LCD0CNTRST_CNTRST__3P43  EQU 01AH ; Set the contrast voltage to 3.43 V.
LCD0CNTRST_CNTRST__3P49  EQU 01BH ; Set the contrast voltage to 3.49 V.
LCD0CNTRST_CNTRST__3P54  EQU 01CH ; Set the contrast voltage to 3.54 V.
LCD0CNTRST_CNTRST__3P60  EQU 01DH ; Set the contrast voltage to 3.60 V.
LCD0CNTRST_CNTRST__3P66  EQU 01EH ; Set the contrast voltage to 3.66 V.
LCD0CNTRST_CNTRST__3P72  EQU 01FH ; Set the contrast voltage to 3.72 V.
                                                                       
;------------------------------------------------------------------------------
; LCD0D0 Enums (LCD0 Data 0 @ 0x89)
;------------------------------------------------------------------------------
LCD0D0_LCD0P0__FMASK EQU 00FH ; LCD Pin 0 Data
LCD0D0_LCD0P0__SHIFT EQU 000H ; LCD Pin 0 Data
                                              
LCD0D0_LCD0P1__FMASK EQU 0F0H ; LCD Pin 1 Data
LCD0D0_LCD0P1__SHIFT EQU 004H ; LCD Pin 1 Data
                                              
;------------------------------------------------------------------------------
; LCD0D1 Enums (LCD0 Data 1 @ 0x8A)
;------------------------------------------------------------------------------
LCD0D1_LCD0P2__FMASK EQU 00FH ; LCD Pin 2 Data
LCD0D1_LCD0P2__SHIFT EQU 000H ; LCD Pin 2 Data
                                              
LCD0D1_LCD0P3__FMASK EQU 0F0H ; LCD Pin 3 Data
LCD0D1_LCD0P3__SHIFT EQU 004H ; LCD Pin 3 Data
                                              
;------------------------------------------------------------------------------
; LCD0D2 Enums (LCD0 Data 2 @ 0x8B)
;------------------------------------------------------------------------------
LCD0D2_LCD0P4__FMASK EQU 00FH ; LCD Pin 4 Data
LCD0D2_LCD0P4__SHIFT EQU 000H ; LCD Pin 4 Data
                                              
LCD0D2_LCD0P5__FMASK EQU 0F0H ; LCD Pin 5 Data
LCD0D2_LCD0P5__SHIFT EQU 004H ; LCD Pin 5 Data
                                              
;------------------------------------------------------------------------------
; LCD0D3 Enums (LCD0 Data 3 @ 0x8C)
;------------------------------------------------------------------------------
LCD0D3_LCD0P6__FMASK EQU 00FH ; LCD Pin 6 Data
LCD0D3_LCD0P6__SHIFT EQU 000H ; LCD Pin 6 Data
                                              
LCD0D3_LCD0P7__FMASK EQU 0F0H ; LCD Pin 7 Data
LCD0D3_LCD0P7__SHIFT EQU 004H ; LCD Pin 7 Data
                                              
;------------------------------------------------------------------------------
; LCD0D4 Enums (LCD0 Data 4 @ 0x8D)
;------------------------------------------------------------------------------
LCD0D4_LCD0P8__FMASK EQU 00FH ; LCD Pin 8 Data
LCD0D4_LCD0P8__SHIFT EQU 000H ; LCD Pin 8 Data
                                              
LCD0D4_LCD0P9__FMASK EQU 0F0H ; LCD Pin 9 Data
LCD0D4_LCD0P9__SHIFT EQU 004H ; LCD Pin 9 Data
                                              
;------------------------------------------------------------------------------
; LCD0D5 Enums (LCD0 Data 5 @ 0x8E)
;------------------------------------------------------------------------------
LCD0D5_LCD0P10__FMASK EQU 00FH ; LCD Pin 10 Data
LCD0D5_LCD0P10__SHIFT EQU 000H ; LCD Pin 10 Data
                                                
LCD0D5_LCD0P11__FMASK EQU 0F0H ; LCD Pin 11 Data
LCD0D5_LCD0P11__SHIFT EQU 004H ; LCD Pin 11 Data
                                                
;------------------------------------------------------------------------------
; LCD0D6 Enums (LCD0 Data 6 @ 0x91)
;------------------------------------------------------------------------------
LCD0D6_LCD0P12__FMASK EQU 00FH ; LCD Pin 12 Data
LCD0D6_LCD0P12__SHIFT EQU 000H ; LCD Pin 12 Data
                                                
LCD0D6_LCD0P13__FMASK EQU 0F0H ; LCD Pin 13 Data
LCD0D6_LCD0P13__SHIFT EQU 004H ; LCD Pin 13 Data
                                                
;------------------------------------------------------------------------------
; LCD0D7 Enums (LCD0 Data 7 @ 0x92)
;------------------------------------------------------------------------------
LCD0D7_LCD0P14__FMASK EQU 00FH ; LCD Pin 14 Data
LCD0D7_LCD0P14__SHIFT EQU 000H ; LCD Pin 14 Data
                                                
LCD0D7_LCD0P15__FMASK EQU 0F0H ; LCD Pin 15 Data
LCD0D7_LCD0P15__SHIFT EQU 004H ; LCD Pin 15 Data
                                                
;------------------------------------------------------------------------------
; LCD0D8 Enums (LCD0 Data 8 @ 0x93)
;------------------------------------------------------------------------------
LCD0D8_LCD0P16__FMASK EQU 00FH ; LCD Pin 16 Data
LCD0D8_LCD0P16__SHIFT EQU 000H ; LCD Pin 16 Data
                                                
LCD0D8_LCD0P17__FMASK EQU 0F0H ; LCD Pin 17 Data
LCD0D8_LCD0P17__SHIFT EQU 004H ; LCD Pin 17 Data
                                                
;------------------------------------------------------------------------------
; LCD0D9 Enums (LCD0 Data 9 @ 0x94)
;------------------------------------------------------------------------------
LCD0D9_LCD0P18__FMASK EQU 00FH ; LCD Pin 18 Data
LCD0D9_LCD0P18__SHIFT EQU 000H ; LCD Pin 18 Data
                                                
LCD0D9_LCD0P19__FMASK EQU 0F0H ; LCD Pin 19 Data
LCD0D9_LCD0P19__SHIFT EQU 004H ; LCD Pin 19 Data
                                                
;------------------------------------------------------------------------------
; LCD0DA Enums (LCD0 Data 10 @ 0x95)
;------------------------------------------------------------------------------
LCD0DA_LCD0P20__FMASK EQU 00FH ; LCD Pin 20 Data
LCD0DA_LCD0P20__SHIFT EQU 000H ; LCD Pin 20 Data
                                                
LCD0DA_LCD0P21__FMASK EQU 0F0H ; LCD Pin 21 Data
LCD0DA_LCD0P21__SHIFT EQU 004H ; LCD Pin 21 Data
                                                
;------------------------------------------------------------------------------
; LCD0DB Enums (LCD0 Data 11 @ 0x96)
;------------------------------------------------------------------------------
LCD0DB_LCD0P22__FMASK EQU 00FH ; LCD Pin 22 Data
LCD0DB_LCD0P22__SHIFT EQU 000H ; LCD Pin 22 Data
                                                
LCD0DB_LCD0P23__FMASK EQU 0F0H ; LCD Pin 23 Data
LCD0DB_LCD0P23__SHIFT EQU 004H ; LCD Pin 23 Data
                                                
;------------------------------------------------------------------------------
; LCD0DC Enums (LCD0 Data 12 @ 0x97)
;------------------------------------------------------------------------------
LCD0DC_LCD0P24__FMASK EQU 00FH ; LCD Pin 24 Data
LCD0DC_LCD0P24__SHIFT EQU 000H ; LCD Pin 24 Data
                                                
LCD0DC_LCD0P25__FMASK EQU 0F0H ; LCD Pin 25 Data
LCD0DC_LCD0P25__SHIFT EQU 004H ; LCD Pin 25 Data
                                                
;------------------------------------------------------------------------------
; LCD0DD Enums (LCD0 Data 13 @ 0x99)
;------------------------------------------------------------------------------
LCD0DD_LCD0P26__FMASK EQU 00FH ; LCD Pin 26 Data
LCD0DD_LCD0P26__SHIFT EQU 000H ; LCD Pin 26 Data
                                                
LCD0DD_LCD0P27__FMASK EQU 0F0H ; LCD Pin 27 Data
LCD0DD_LCD0P27__SHIFT EQU 004H ; LCD Pin 27 Data
                                                
;------------------------------------------------------------------------------
; LCD0DE Enums (LCD0 Data 14 @ 0x9A)
;------------------------------------------------------------------------------
LCD0DE_LCD0P28__FMASK EQU 00FH ; LCD Pin 28 Data
LCD0DE_LCD0P28__SHIFT EQU 000H ; LCD Pin 28 Data
                                                
LCD0DE_LCD0P29__FMASK EQU 0F0H ; LCD Pin 29 Data
LCD0DE_LCD0P29__SHIFT EQU 004H ; LCD Pin 29 Data
                                                
;------------------------------------------------------------------------------
; LCD0DF Enums (LCD0 Data 15 @ 0x9B)
;------------------------------------------------------------------------------
LCD0DF_LCD0P30__FMASK EQU 00FH ; LCD Pin 30 Data
LCD0DF_LCD0P30__SHIFT EQU 000H ; LCD Pin 30 Data
                                                
LCD0DF_LCD0P31__FMASK EQU 0F0H ; LCD Pin 31 Data
LCD0DF_LCD0P31__SHIFT EQU 004H ; LCD Pin 31 Data
                                                
;------------------------------------------------------------------------------
; LCD0MSCF Enums (LCD0 Master Configuration @ 0xAC)
;------------------------------------------------------------------------------
LCD0MSCF_CHPBYP__BMASK     EQU 001H ; LCD0 Charge Pump Bypass                  
LCD0MSCF_CHPBYP__SHIFT     EQU 000H ; LCD0 Charge Pump Bypass                  
LCD0MSCF_CHPBYP__NORMAL    EQU 000H ; LCD0 charge pump is not bypassed.        
LCD0MSCF_CHPBYP__BYPASSED  EQU 001H ; LCD0 charge pump is bypassed.            
                                                                               
LCD0MSCF_DCENSLP__BMASK    EQU 002H ; DCDC Converter Sleep Mode Enable         
LCD0MSCF_DCENSLP__SHIFT    EQU 001H ; DCDC Converter Sleep Mode Enable         
LCD0MSCF_DCENSLP__DISABLED EQU 000H ; Disable the DCDC Converter in Sleep mode.
LCD0MSCF_DCENSLP__ENABLED  EQU 002H ; Enable the DCDC Converter in Sleep mode. 
                                                                               
;------------------------------------------------------------------------------
; LCD0MSCN Enums (LCD0 Master Control @ 0xAB)
;------------------------------------------------------------------------------
LCD0MSCN_LCDEN__BMASK       EQU 001H ; LCD0 Enable                                      
LCD0MSCN_LCDEN__SHIFT       EQU 000H ; LCD0 Enable                                      
LCD0MSCN_LCDEN__DISABLED    EQU 000H ; Disable the LCD0 module.                         
LCD0MSCN_LCDEN__ENABLED     EQU 001H ; Enable the LCD0 module.                          
                                                                                        
LCD0MSCN_LCDRST__BMASK      EQU 002H ; LCD0 Reset                                       
LCD0MSCN_LCDRST__SHIFT      EQU 001H ; LCD0 Reset                                       
LCD0MSCN_LCDRST__DISABLED   EQU 000H ; Disable the LCD0 reset.                          
LCD0MSCN_LCDRST__ENABLED    EQU 002H ; Clear all of the LCD0Dn registers to 0x00.       
                                                                                        
LCD0MSCN_LOWDRV__BMASK      EQU 004H ; Charge Pump Reduced Drive Mode                   
LCD0MSCN_LOWDRV__SHIFT      EQU 002H ; Charge Pump Reduced Drive Mode                   
LCD0MSCN_LOWDRV__DISABLED   EQU 000H ; The charge pump operates at full power.          
LCD0MSCN_LOWDRV__ENABLED    EQU 004H ; The charge pump operates at reduced power.       
                                                                                        
LCD0MSCN_CLKOE__BMASK       EQU 010H ; LCD Clock Output Enable                          
LCD0MSCN_CLKOE__SHIFT       EQU 004H ; LCD Clock Output Enable                          
LCD0MSCN_CLKOE__DISABLED    EQU 000H ; Disable the clock to the LCD0 module.            
LCD0MSCN_CLKOE__ENABLED     EQU 010H ; Enable the clock to the LCD0 module from the RTC.
                                                                                        
LCD0MSCN_DCBIASOE__BMASK    EQU 020H ; DCDC Converter Bias Output Enable                
LCD0MSCN_DCBIASOE__SHIFT    EQU 005H ; DCDC Converter Bias Output Enable                
LCD0MSCN_DCBIASOE__DISABLED EQU 000H ; Disable the bias output from the LCD0 module for 
                                     ; the DCDC converter.                              
LCD0MSCN_DCBIASOE__ENABLED  EQU 020H ; Enable the bias output from the LCD0 module for  
                                     ; the DCDC converter.                              
                                                                                        
LCD0MSCN_BIASEN__BMASK      EQU 040H ; LCD0 Bias Enable                                 
LCD0MSCN_BIASEN__SHIFT      EQU 006H ; LCD0 Bias Enable                                 
LCD0MSCN_BIASEN__DISABLED   EQU 000H ; Disable the LCD0 bias.                           
LCD0MSCN_BIASEN__ENABLED    EQU 040H ; Enable the LCD0 bias.                            
                                                                                        
;------------------------------------------------------------------------------
; LCD0PWR Enums (LCD0 Power @ 0xA4)
;------------------------------------------------------------------------------
LCD0PWR_MODE__BMASK  EQU 008H ; LCD0 Contrast Control Mode Selection          
LCD0PWR_MODE__SHIFT  EQU 003H ; LCD0 Contrast Control Mode Selection          
LCD0PWR_MODE__1_OR_4 EQU 000H ; Select LCD0 Contrast Control Mode 1 or Mode 4.
LCD0PWR_MODE__2_OR_3 EQU 008H ; Select LCD0 Contrast Control Mode 2 or Mode 3.
                                                                              
;------------------------------------------------------------------------------
; LCD0TOGR Enums (LCD0 Toggle Rate @ 0x9F)
;------------------------------------------------------------------------------
LCD0TOGR_TOGR__FMASK    EQU 00FH ; LCD Toggle Rate Divider                      
LCD0TOGR_TOGR__SHIFT    EQU 000H ; LCD Toggle Rate Divider                      
LCD0TOGR_TOGR__DIV_2    EQU 002H ; Toggle Rate Divider is set to divide by 2.   
LCD0TOGR_TOGR__DIV_4    EQU 003H ; Toggle Rate Divider is set to divide by 4.   
LCD0TOGR_TOGR__DIV_8    EQU 004H ; Toggle Rate Divider is set to divide by 8.   
LCD0TOGR_TOGR__DIV_16   EQU 005H ; Toggle Rate Divider is set to divide by 16.  
LCD0TOGR_TOGR__DIV_32   EQU 006H ; Toggle Rate Divider is set to divide by 32.  
LCD0TOGR_TOGR__DIV_64   EQU 007H ; Toggle Rate Divider is set to divide by 64.  
LCD0TOGR_TOGR__DIV_128  EQU 008H ; Toggle Rate Divider is set to divide by 128. 
LCD0TOGR_TOGR__DIV_256  EQU 009H ; Toggle Rate Divider is set to divide by 256. 
LCD0TOGR_TOGR__DIV_512  EQU 00AH ; Toggle Rate Divider is set to divide by 512. 
LCD0TOGR_TOGR__DIV_1024 EQU 00BH ; Toggle Rate Divider is set to divide by 1024.
LCD0TOGR_TOGR__DIV_2048 EQU 00CH ; Toggle Rate Divider is set to divide by 2048.
LCD0TOGR_TOGR__DIV_4096 EQU 00DH ; Toggle Rate Divider is set to divide by 4096.
                                                                                
;------------------------------------------------------------------------------
; LCD0VBMCN Enums (LCD0 VBAT Monitor Control @ 0xA6)
;------------------------------------------------------------------------------
LCD0VBMCN_THRLD__FMASK      EQU 01FH ; VBAT Monitor Threshold                          
LCD0VBMCN_THRLD__SHIFT      EQU 000H ; VBAT Monitor Threshold                          
                                                                                       
LCD0VBMCN_OFFSET__BMASK     EQU 040H ; VBAT Monitor Offset Enable                      
LCD0VBMCN_OFFSET__SHIFT     EQU 006H ; VBAT Monitor Offset Enable                      
LCD0VBMCN_OFFSET__DISABLED  EQU 000H ; The VBAT Monitor threshold is independent of the
                                     ; contrast setting.                               
LCD0VBMCN_OFFSET__ENABLED   EQU 040H ; The VBAT Monitor threshold is linked to the     
                                     ; contrast setting.                               
                                                                                       
LCD0VBMCN_VBATMEN__BMASK    EQU 080H ; VBAT Monitor Enable                             
LCD0VBMCN_VBATMEN__SHIFT    EQU 007H ; VBAT Monitor Enable                             
LCD0VBMCN_VBATMEN__DISABLED EQU 000H ; Disable the VBAT Monitor.                       
LCD0VBMCN_VBATMEN__ENABLED  EQU 080H ; Enable the VBAT Monitor.                        
                                                                                       
;------------------------------------------------------------------------------
; XBR0 Enums (Port I/O Crossbar 0 @ 0xE1)
;------------------------------------------------------------------------------
XBR0_URT0E__BMASK     EQU 001H ; UART0 I/O Output Enable                       
XBR0_URT0E__SHIFT     EQU 000H ; UART0 I/O Output Enable                       
XBR0_URT0E__DISABLED  EQU 000H ; UART I/O unavailable at Port pin.             
XBR0_URT0E__ENABLED   EQU 001H ; TX0 and RX0 routed to Port pins P0.4 and P0.5.
                                                                               
XBR0_SPI0E__BMASK     EQU 002H ; SPI0 I/O Enable                               
XBR0_SPI0E__SHIFT     EQU 001H ; SPI0 I/O Enable                               
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
                                                                                                       
XBR1_SPI1E__BMASK                          EQU 040H ; SPI1 I/O Enable                                  
XBR1_SPI1E__SHIFT                          EQU 006H ; SPI1 I/O Enable                                  
XBR1_SPI1E__DISABLED                       EQU 000H ; SPI1 I/O unavailable at Port pin.                
XBR1_SPI1E__ENABLED                        EQU 040H ; SPI1 I/O routed to Port pins.                    
                                                                                                       
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
PCA0CPM3_PWM16__8_BIT   EQU 000H ; 8 to 11-bit PWM selected.                      
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
PCA0CPM4_PWM16__8_BIT   EQU 000H ; 8 to 11-bit PWM selected.                      
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
PCA0CPM5_PWM16__8_BIT   EQU 000H ; 8 to 11-bit PWM selected.                      
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
; PC0CMP0H Enums (PC0 Comparator 0 High Byte @ 0xE3)
;------------------------------------------------------------------------------
PC0CMP0H_PC0CMP0H__FMASK EQU 0FFH ; PC0 Comparator 0 High Byte
PC0CMP0H_PC0CMP0H__SHIFT EQU 000H ; PC0 Comparator 0 High Byte
                                                              
;------------------------------------------------------------------------------
; PC0CMP0L Enums (PC0 Comparator 0 Low Byte @ 0xE1)
;------------------------------------------------------------------------------
PC0CMP0L_PC0CMP0L__FMASK EQU 0FFH ; PC0 Comparator 0 Low Byte
PC0CMP0L_PC0CMP0L__SHIFT EQU 000H ; PC0 Comparator 0 Low Byte
                                                             
;------------------------------------------------------------------------------
; PC0CMP0M Enums (PC0 Comparator 0 Middle Byte @ 0xE2)
;------------------------------------------------------------------------------
PC0CMP0M_PC0CMP0M__FMASK EQU 0FFH ; PC0 Comparator 0 Middle Byte
PC0CMP0M_PC0CMP0M__SHIFT EQU 000H ; PC0 Comparator 0 Middle Byte
                                                                
;------------------------------------------------------------------------------
; PC0CMP1H Enums (PC0 Comparator 1 High Byte @ 0xF3)
;------------------------------------------------------------------------------
PC0CMP1H_PC0CMP1H__FMASK EQU 0FFH ; PC0 Comparator 1 High Byte
PC0CMP1H_PC0CMP1H__SHIFT EQU 000H ; PC0 Comparator 1 High Byte
                                                              
;------------------------------------------------------------------------------
; PC0CMP1L Enums (PC0 Comparator 1 Low Byte @ 0xF1)
;------------------------------------------------------------------------------
PC0CMP1L_PC0CMP1L__FMASK EQU 0FFH ; PC0 Comparator 1 Low Byte
PC0CMP1L_PC0CMP1L__SHIFT EQU 000H ; PC0 Comparator 1 Low Byte
                                                             
;------------------------------------------------------------------------------
; PC0CMP1M Enums (PC0 Comparator 1 Middle Byte @ 0xF2)
;------------------------------------------------------------------------------
PC0CMP1M_PC0CMP1M__FMASK EQU 0FFH ; PC0 Comparator 1 Middle Byte
PC0CMP1M_PC0CMP1M__SHIFT EQU 000H ; PC0 Comparator 1 Middle Byte
                                                                
;------------------------------------------------------------------------------
; PC0CTR0H Enums (PC0 Counter 0 High Byte @ 0xDC)
;------------------------------------------------------------------------------
PC0CTR0H_PC0CTR0H__FMASK EQU 0FFH ; PC0 Counter 0 High Byte
PC0CTR0H_PC0CTR0H__SHIFT EQU 000H ; PC0 Counter 0 High Byte
                                                           
;------------------------------------------------------------------------------
; PC0CTR0L Enums (PC0 Counter 0 Low Byte @ 0xDA)
;------------------------------------------------------------------------------
PC0CTR0L_PC0CTR0L__FMASK EQU 0FFH ; PC0 Counter 0 Low Byte
PC0CTR0L_PC0CTR0L__SHIFT EQU 000H ; PC0 Counter 0 Low Byte
                                                          
;------------------------------------------------------------------------------
; PC0CTR0M Enums (PC0 Counter 0 Middle Byte @ 0xDB)
;------------------------------------------------------------------------------
PC0CTR0M_PC0CTR0M__FMASK EQU 0FFH ; PC0 Counter 0 Middle Byte
PC0CTR0M_PC0CTR0M__SHIFT EQU 000H ; PC0 Counter 0 Middle Byte
                                                             
;------------------------------------------------------------------------------
; PC0CTR1H Enums (PC0 Counter 1 High Byte @ 0xDF)
;------------------------------------------------------------------------------
PC0CTR1H_PC0CTR1H__FMASK EQU 0FFH ; PC0 Counter 1 High Byte
PC0CTR1H_PC0CTR1H__SHIFT EQU 000H ; PC0 Counter 1 High Byte
                                                           
;------------------------------------------------------------------------------
; PC0CTR1L Enums (PC0 Counter 1 Low Byte @ 0xDD)
;------------------------------------------------------------------------------
PC0CTR1L_PC0CTR1L__FMASK EQU 0FFH ; PC0 Counter 1 Low Byte
PC0CTR1L_PC0CTR1L__SHIFT EQU 000H ; PC0 Counter 1 Low Byte
                                                          
;------------------------------------------------------------------------------
; PC0CTR1M Enums (PC0 Counter 1 Middle Byte @ 0xDE)
;------------------------------------------------------------------------------
PC0CTR1M_PC0CTR1M__FMASK EQU 0FFH ; PC0 Counter 1 Middle Byte
PC0CTR1M_PC0CTR1M__SHIFT EQU 000H ; PC0 Counter 1 Middle Byte
                                                             
;------------------------------------------------------------------------------
; PC0DCH Enums (PC0 Debounce Configuration High Byte @ 0xFA)
;------------------------------------------------------------------------------
PC0DCH_PC0DCH__FMASK EQU 0FFH ; Debounce High Byte
PC0DCH_PC0DCH__SHIFT EQU 000H ; Debounce High Byte
                                                  
;------------------------------------------------------------------------------
; PC0DCL Enums (PC0 Debounce Configuration Low Byte @ 0xF9)
;------------------------------------------------------------------------------
PC0DCL_PC0DCL__FMASK EQU 0FFH ; Debounce Low Byte
PC0DCL_PC0DCL__SHIFT EQU 000H ; Debounce Low Byte
                                                 
;------------------------------------------------------------------------------
; PC0HIST Enums (PC0 Direction History @ 0xF4)
;------------------------------------------------------------------------------
PC0HIST_DIRHIST0__BMASK EQU 001H ; PC0 Direction History Slot 0                 
PC0HIST_DIRHIST0__SHIFT EQU 000H ; PC0 Direction History Slot 0                 
PC0HIST_DIRHIST0__CCW   EQU 000H ; The recorded direction was counter clock-wise
PC0HIST_DIRHIST0__CW    EQU 001H ; The recorded direction was clock-wise.       
                                                                                
PC0HIST_DIRHIST1__BMASK EQU 002H ; PC0 Direction History Slot 1                 
PC0HIST_DIRHIST1__SHIFT EQU 001H ; PC0 Direction History Slot 1                 
PC0HIST_DIRHIST1__CCW   EQU 000H ; The recorded direction was counter clock-wise
PC0HIST_DIRHIST1__CW    EQU 002H ; The recorded direction was clock-wise.       
                                                                                
PC0HIST_DIRHIST2__BMASK EQU 004H ; PC0 Direction History Slot 2                 
PC0HIST_DIRHIST2__SHIFT EQU 002H ; PC0 Direction History Slot 2                 
PC0HIST_DIRHIST2__CCW   EQU 000H ; The recorded direction was counter clock-wise
PC0HIST_DIRHIST2__CW    EQU 004H ; The recorded direction was clock-wise.       
                                                                                
PC0HIST_DIRHIST3__BMASK EQU 008H ; PC0 Direction History Slot 3                 
PC0HIST_DIRHIST3__SHIFT EQU 003H ; PC0 Direction History Slot 3                 
PC0HIST_DIRHIST3__CCW   EQU 000H ; The recorded direction was counter clock-wise
PC0HIST_DIRHIST3__CW    EQU 008H ; The recorded direction was clock-wise.       
                                                                                
PC0HIST_DIRHIST4__BMASK EQU 010H ; PC0 Direction History Slot 4                 
PC0HIST_DIRHIST4__SHIFT EQU 004H ; PC0 Direction History Slot 4                 
PC0HIST_DIRHIST4__CCW   EQU 000H ; The recorded direction was counter clock-wise
PC0HIST_DIRHIST4__CW    EQU 010H ; The recorded direction was clock-wise.       
                                                                                
PC0HIST_DIRHIST5__BMASK EQU 020H ; PC0 Direction History Slot 5                 
PC0HIST_DIRHIST5__SHIFT EQU 005H ; PC0 Direction History Slot 5                 
PC0HIST_DIRHIST5__CCW   EQU 000H ; The recorded direction was counter clock-wise
PC0HIST_DIRHIST5__CW    EQU 020H ; The recorded direction was clock-wise.       
                                                                                
PC0HIST_DIRHIST6__BMASK EQU 040H ; PC0 Direction History Slot 6                 
PC0HIST_DIRHIST6__SHIFT EQU 006H ; PC0 Direction History Slot 6                 
PC0HIST_DIRHIST6__CCW   EQU 000H ; The recorded direction was counter clock-wise
PC0HIST_DIRHIST6__CW    EQU 040H ; The recorded direction was clock-wise.       
                                                                                
PC0HIST_DIRHIST7__BMASK EQU 080H ; PC0 Direction History Slot 7                 
PC0HIST_DIRHIST7__SHIFT EQU 007H ; PC0 Direction History Slot 7                 
PC0HIST_DIRHIST7__CCW   EQU 000H ; The recorded direction was counter clock-wise
PC0HIST_DIRHIST7__CW    EQU 080H ; The recorded direction was clock-wise.       
                                                                                
;------------------------------------------------------------------------------
; PC0INT0 Enums (PC0 Interrupt 0 @ 0xFB)
;------------------------------------------------------------------------------
PC0INT0_DIRCHGEN__BMASK    EQU 001H ; Direction Change Interrupt/Wake-up Source Enable  
PC0INT0_DIRCHGEN__SHIFT    EQU 000H ; Direction Change Interrupt/Wake-up Source Enable  
PC0INT0_DIRCHGEN__DISABLED EQU 000H ; Disable a direction change as an interrupt or     
                                    ; wake-up source.                                   
PC0INT0_DIRCHGEN__ENABLED  EQU 001H ; Enable a direction change as an interrupt or wake-
                                    ; up source.                                        
                                                                                        
PC0INT0_DIRCHGF__BMASK     EQU 002H ; Direction Change Flag                             
PC0INT0_DIRCHGF__SHIFT     EQU 001H ; Direction Change Flag                             
PC0INT0_DIRCHGF__NOT_SET   EQU 000H ; No change in direction was detected.              
PC0INT0_DIRCHGF__SET       EQU 002H ; A change in direction was detected.               
                                                                                        
PC0INT0_OVREN__BMASK       EQU 004H ; Counter Overflow Interrupt/Wake-up Source Enable  
PC0INT0_OVREN__SHIFT       EQU 002H ; Counter Overflow Interrupt/Wake-up Source Enable  
PC0INT0_OVREN__DISABLED    EQU 000H ; Disable a counter overflow as an interrupt or     
                                    ; wake-up source.                                   
PC0INT0_OVREN__ENABLED     EQU 004H ; Enable a counter overflow as an interrupt or wake-
                                    ; up source.                                        
                                                                                        
PC0INT0_OVRF__BMASK        EQU 008H ; Counter Overflow Flag                             
PC0INT0_OVRF__SHIFT        EQU 003H ; Counter Overflow Flag                             
PC0INT0_OVRF__SET          EQU 008H ; One of the counters has overflowed.               
                                                                                        
PC0INT0_CMP0EN__BMASK      EQU 010H ; Comparator 0 Interrupt/Wake-up Source Enable      
PC0INT0_CMP0EN__SHIFT      EQU 004H ; Comparator 0 Interrupt/Wake-up Source Enable      
PC0INT0_CMP0EN__DISABLED   EQU 000H ; Disable the counter 0 comparator as an interrupt  
                                    ; or wake-up source.                                
PC0INT0_CMP0EN__ENABLED    EQU 010H ; Enable the counter 0 comparator as an interrupt or
                                    ; wake-up source.                                   
                                                                                        
PC0INT0_CMP0F__BMASK       EQU 020H ; Comparator 0 Flag                                 
PC0INT0_CMP0F__SHIFT       EQU 005H ; Comparator 0 Flag                                 
PC0INT0_CMP0F__NOT_SET     EQU 000H ; Counter 0 did not match counter 0 comparator      
                                    ; value.                                            
PC0INT0_CMP0F__SET         EQU 020H ; Counter 0 matched counter 0 comparator value.     
                                                                                        
PC0INT0_CMP1EN__BMASK      EQU 040H ; Comparator 1 Interrupt/Wake-up Source Enable      
PC0INT0_CMP1EN__SHIFT      EQU 006H ; Comparator 1 Interrupt/Wake-up Source Enable      
PC0INT0_CMP1EN__DISABLED   EQU 000H ; Disable the counter 1 comparator as an interrupt  
                                    ; or wake-up source.                                
PC0INT0_CMP1EN__ENABLED    EQU 040H ; Enable the counter 1 comparator as an interrupt or
                                    ; wake-up source.                                   
                                                                                        
PC0INT0_CMP1F__BMASK       EQU 080H ; Comparator 1 Flag                                 
PC0INT0_CMP1F__SHIFT       EQU 007H ; Comparator 1 Flag                                 
PC0INT0_CMP1F__NOT_SET     EQU 000H ; Counter 1 did not match counter 1 comparator      
                                    ; value.                                            
PC0INT0_CMP1F__SET         EQU 080H ; Counter 1 matched counter 1 comparator value.     
                                                                                        
;------------------------------------------------------------------------------
; PC0INT1 Enums (PC0 Interrupt 1 @ 0xFC)
;------------------------------------------------------------------------------
PC0INT1_TRANSEN__BMASK      EQU 001H ; Transition Interrupt/Wake-up Source Enable        
PC0INT1_TRANSEN__SHIFT      EQU 000H ; Transition Interrupt/Wake-up Source Enable        
PC0INT1_TRANSEN__DISABLED   EQU 000H ; Disable transitions on PC0 or PC1 as an interrupt 
                                     ; or wake-up source.                                
PC0INT1_TRANSEN__ENABLED    EQU 001H ; Enable transitions on PC0 or PC1 as an interrupt  
                                     ; or wake-up source.                                
                                                                                         
PC0INT1_TRANSF__BMASK       EQU 002H ; Transition Flag                                   
PC0INT1_TRANSF__SHIFT       EQU 001H ; Transition Flag                                   
PC0INT1_TRANSF__NOT_SET     EQU 000H ; No transitions detected.                          
PC0INT1_TRANSF__SET         EQU 002H ; A transition was detected on the PC0 or PC1       
                                     ; inputs.                                           
                                                                                         
PC0INT1_ERROREN__BMASK      EQU 004H ; Quadrature Error Interrupt/Wake-up Source Enable  
PC0INT1_ERROREN__SHIFT      EQU 002H ; Quadrature Error Interrupt/Wake-up Source Enable  
PC0INT1_ERROREN__DISABLED   EQU 000H ; Disable a quadrature error as an interrupt or     
                                     ; wake-up source.                                   
PC0INT1_ERROREN__ENABLED    EQU 004H ; Enable a quadrature error as an interrupt or wake-
                                     ; up source.                                        
                                                                                         
PC0INT1_ERRORF__BMASK       EQU 008H ; Quadrature Error Flag                             
PC0INT1_ERRORF__SHIFT       EQU 003H ; Quadrature Error Flag                             
PC0INT1_ERRORF__NOT_SET     EQU 000H ; No quadrature error detected.                     
PC0INT1_ERRORF__SET         EQU 008H ; Quadrature error detected.                        
                                                                                         
PC0INT1_FLTRSTPEN__BMASK    EQU 010H ; Flutter Stop Interrupt/Wake-up Source Enable      
PC0INT1_FLTRSTPEN__SHIFT    EQU 004H ; Flutter Stop Interrupt/Wake-up Source Enable      
PC0INT1_FLTRSTPEN__DISABLED EQU 000H ; Disable the end of a flutter event as an interrupt
                                     ; or wake-up source.                                
PC0INT1_FLTRSTPEN__ENABLED  EQU 010H ; Enable the end of a flutter event as an interrupt 
                                     ; or wake-up source.                                
                                                                                         
PC0INT1_FLTRSTPF__BMASK     EQU 020H ; Flutter Stop Flag                                 
PC0INT1_FLTRSTPF__SHIFT     EQU 005H ; Flutter Stop Flag                                 
PC0INT1_FLTRSTPF__NOT_SET   EQU 000H ; The end of a flutter event was not detected.      
PC0INT1_FLTRSTPF__SET       EQU 020H ; The end of a flutter event was detected.          
                                                                                         
PC0INT1_FLTRSTREN__BMASK    EQU 040H ; Flutter Start Interrupt/Wake-up Source Enable     
PC0INT1_FLTRSTREN__SHIFT    EQU 006H ; Flutter Start Interrupt/Wake-up Source Enable     
PC0INT1_FLTRSTREN__DISABLED EQU 000H ; Disable the start of a flutter event as an        
                                     ; interrupt or wake-up source.                      
PC0INT1_FLTRSTREN__ENABLED  EQU 040H ; Enable the start of a flutter event as an         
                                     ; interrupt or wake-up source.                      
                                                                                         
PC0INT1_FLTRSTRF__BMASK     EQU 080H ; Flutter Start Flag                                
PC0INT1_FLTRSTRF__SHIFT     EQU 007H ; Flutter Start Flag                                
PC0INT1_FLTRSTRF__NOT_SET   EQU 000H ; The start of a flutter event was not detected.    
PC0INT1_FLTRSTRF__SET       EQU 080H ; The start of a flutter event was detected.        
                                                                                         
;------------------------------------------------------------------------------
; PC0MD Enums (PC0 Mode Configuration @ 0xD9)
;------------------------------------------------------------------------------
PC0MD_DUALSTCH__BMASK    EQU 002H ; Flutter Dual Mode Switch Enable                  
PC0MD_DUALSTCH__SHIFT    EQU 001H ; Flutter Dual Mode Switch Enable                  
PC0MD_DUALSTCH__DISABLED EQU 000H ; Disable dual mode switching. The counter remains 
                                  ; in quadrature mode during flutter.               
PC0MD_DUALSTCH__ENABLED  EQU 002H ; Enable dual mode switching. The counter switches 
                                  ; to dual mode during flutter.                     
                                                                                     
PC0MD_FLTRSTOP__BMASK    EQU 004H ; Flutter Counter Stop Enable                      
PC0MD_FLTRSTOP__SHIFT    EQU 002H ; Flutter Counter Stop Enable                      
PC0MD_FLTRSTOP__DISABLED EQU 000H ; Disable counter stops on flutter.                
PC0MD_FLTRSTOP__ENABLED  EQU 004H ; Stop the counter when flutter occurs.            
                                                                                     
PC0MD_PCRATE__FMASK      EQU 030H ; PC Sample Rate                                   
PC0MD_PCRATE__SHIFT      EQU 004H ; PC Sample Rate                                   
PC0MD_PCRATE__250_US     EQU 000H ; Set the pulse counter sample rate to 250 us.     
PC0MD_PCRATE__500_US     EQU 010H ; Set the pulse counter sample rate to 500 us.     
PC0MD_PCRATE__1_MS       EQU 020H ; Set the pulse counter sample rate to 1 ms.       
PC0MD_PCRATE__2_MS       EQU 030H ; Set the pulse counter sample rate to 2 ms.       
                                                                                     
PC0MD_PCMODE__FMASK      EQU 0C0H ; Counter Mode                                     
PC0MD_PCMODE__SHIFT      EQU 006H ; Counter Mode                                     
PC0MD_PCMODE__DISABLED   EQU 000H ; Disable the pulse counter.                       
PC0MD_PCMODE__SINGLE     EQU 040H ; Select single counter mode for the pulse counter.
PC0MD_PCMODE__DUAL       EQU 080H ; Select dual counter mode for the pulse counter.  
PC0MD_PCMODE__QUADRATURE EQU 0C0H ; Select quadrature counter mode for the pulse     
                                  ; counter.                                         
                                                                                     
;------------------------------------------------------------------------------
; PC0PCF Enums (PC0 Pull-Up Configuration @ 0xD7)
;------------------------------------------------------------------------------
PC0PCF_DUTY__FMASK        EQU 003H ; Pull-Up Resistor Duty Cycle Multiplier            
PC0PCF_DUTY__SHIFT        EQU 000H ; Pull-Up Resistor Duty Cycle Multiplier            
PC0PCF_DUTY__25_PERCENT   EQU 000H ; Set the pull-up resistor duty cycle to 1/4 (25%). 
PC0PCF_DUTY__37P5_PERCENT EQU 001H ; Set the pull-up resistor duty cycle to 3/8        
                                   ; (37.5%).                                          
PC0PCF_DUTY__50_PERCENT   EQU 002H ; Set the pull-up resistor duty cycle to 1/2 (50%). 
PC0PCF_DUTY__75_PERCENT   EQU 003H ; Set the pull-up resistor duty cycle to 3/4 (75%). 
                                                                                       
PC0PCF_RES__FMASK         EQU 01CH ; Pull-Up Resistor Value                            
PC0PCF_RES__SHIFT         EQU 002H ; Pull-Up Resistor Value                            
PC0PCF_RES__DISABLED      EQU 000H ; Disable the pull-up resistors.                    
PC0PCF_RES__1_UA          EQU 004H ; Set the pull-up resistor current to 1 uA.         
PC0PCF_RES__4_UA          EQU 008H ; Set the pull-up resistor current to 4 uA.         
PC0PCF_RES__16_UA         EQU 00CH ; Set the pull-up resistor current to 16 uA.        
PC0PCF_RES__64_UA         EQU 010H ; Set the pull-up resistor current to 64 uA.        
PC0PCF_RES__256_UA        EQU 014H ; Set the pull-up resistor current to 256 uA.       
PC0PCF_RES__1_MA          EQU 018H ; Set the pull-up resistor current to 1 mA.         
PC0PCF_RES__4_MA          EQU 01CH ; Set the pull-up resistor current to 4 mA.         
                                                                                       
PC0PCF_CALPORT__BMASK     EQU 020H ; Calibration Port                                  
PC0PCF_CALPORT__SHIFT     EQU 005H ; Calibration Port                                  
PC0PCF_CALPORT__CHANNEL_0 EQU 000H ; Perform a pull-up calibration on channel 0 only   
                                   ; (PC0).                                            
PC0PCF_CALPORT__CHANNEL_1 EQU 020H ; Perform a pull-up calibration on channel 1 only   
                                   ; (PC1).                                            
                                                                                       
PC0PCF_CALRES__BMASK      EQU 040H ; Calibration Result                                
PC0PCF_CALRES__SHIFT      EQU 006H ; Calibration Result                                
PC0PCF_CALRES__FAILED     EQU 000H ; The pull-up calibration operation failed.         
PC0PCF_CALRES__PASSED     EQU 040H ; The pull-up calibration operation passed.         
                                                                                       
PC0PCF_PUCAL__BMASK       EQU 080H ; Pull-Up Driver Calibration                        
PC0PCF_PUCAL__SHIFT       EQU 007H ; Pull-Up Driver Calibration                        
PC0PCF_PUCAL__NOT_SET     EQU 000H ; The pull-up calibration is complete or not in     
                                   ; progress.                                         
PC0PCF_PUCAL__SET         EQU 080H ; Start a pull-up calibration operation. The        
                                   ; calibration operation determines the lowest usable
                                   ; pull-up strength.                                 
                                                                                       
;------------------------------------------------------------------------------
; PC0STAT Enums (PC0 Status @ 0xC1)
;------------------------------------------------------------------------------
PC0STAT_PC0__BMASK            EQU 001H ; Current PC0 Integrator Output                     
PC0STAT_PC0__SHIFT            EQU 000H ; Current PC0 Integrator Output                     
PC0STAT_PC0__LOW              EQU 000H ; The PC0 integrator output is currently low.       
PC0STAT_PC0__HIGH             EQU 001H ; The PC0 integrator output is currently high.      
                                                                                           
PC0STAT_PC1__BMASK            EQU 002H ; Current PC1 Integrator Output                     
PC0STAT_PC1__SHIFT            EQU 001H ; Current PC1 Integrator Output                     
PC0STAT_PC1__LOW              EQU 000H ; The PC1 integrator output is currently low.       
PC0STAT_PC1__HIGH             EQU 002H ; The PC1 integrator output is currently high.      
                                                                                           
PC0STAT_PC0PREV__BMASK        EQU 004H ; Previous PC0 Integrator Output                    
PC0STAT_PC0PREV__SHIFT        EQU 002H ; Previous PC0 Integrator Output                    
PC0STAT_PC0PREV__LOW          EQU 000H ; The PC0 integrator output was previously low.     
PC0STAT_PC0PREV__HIGH         EQU 004H ; The PC0 integrator output was previously high.    
                                                                                           
PC0STAT_PC1PREV__BMASK        EQU 008H ; Previous PC1 Integrator Output                    
PC0STAT_PC1PREV__SHIFT        EQU 003H ; Previous PC1 Integrator Output                    
PC0STAT_PC1PREV__LOW          EQU 000H ; The PC1 integrator output was previously low.     
PC0STAT_PC1PREV__HIGH         EQU 008H ; The PC1 integrator output was previously high.    
                                                                                           
PC0STAT_STATE__FMASK          EQU 030H ; PC0 State                                         
PC0STAT_STATE__SHIFT          EQU 004H ; PC0 State                                         
PC0STAT_STATE__LL             EQU 000H ; The state of the pulse counter is LL (PC1 low, PC0
                                       ; low).                                             
PC0STAT_STATE__LH             EQU 010H ; The state of the pulse counter is LH (PC1 low, PC0
                                       ; high).                                            
PC0STAT_STATE__HL             EQU 020H ; The state of the pulse counter is HL (PC1 high,   
                                       ; PC0 low).                                         
PC0STAT_STATE__HH             EQU 030H ; The state of the pulse counter is HH (PC1 high,   
                                       ; PC0 high).                                        
                                                                                           
PC0STAT_DIRECTION__BMASK      EQU 040H ; Direction                                         
PC0STAT_DIRECTION__SHIFT      EQU 006H ; Direction                                         
PC0STAT_DIRECTION__CCW        EQU 000H ; The current direction is counter clock-wise: LL-  
                                       ; LH-HH-HL.                                         
PC0STAT_DIRECTION__CW         EQU 040H ; The current direction is clock-wise: LL-HL-HH-LH. 
                                                                                           
PC0STAT_FLUTTER__BMASK        EQU 080H ; Flutter                                           
PC0STAT_FLUTTER__SHIFT        EQU 007H ; Flutter                                           
PC0STAT_FLUTTER__NOT_DETECTED EQU 000H ; No flutter detected.                              
PC0STAT_FLUTTER__DETECTED     EQU 080H ; Flutter detected.                                 
                                                                                           
;------------------------------------------------------------------------------
; PC0TH Enums (PC0 Threshold Configuration @ 0xE4)
;------------------------------------------------------------------------------
PC0TH_RDVALID__BMASK         EQU 001H ; Read Valid                                        
PC0TH_RDVALID__SHIFT         EQU 000H ; Read Valid                                        
PC0TH_RDVALID__NOT_SET       EQU 000H ; The last read was invalid.                        
PC0TH_RDVALID__SET           EQU 001H ; The last read was valid.                          
                                                                                          
PC0TH_PUP__BMASK             EQU 004H ; Force Pull-Up Enable                              
PC0TH_PUP__SHIFT             EQU 002H ; Force Pull-Up Enable                              
PC0TH_PUP__FORCE_DISABLED    EQU 000H ; Channel 0 (PC0) and channel 1 (PC1) pull-ups are  
                                      ; not forced on continuously.                       
PC0TH_PUP__FORCE_ENABLED     EQU 004H ; Channel 0 (PC0) and channel 1 (PC1) pull-ups are  
                                      ; forced on continuously.                           
                                                                                          
PC0TH_PDOWN__BMASK           EQU 008H ; Force Pull-Down Enable                            
PC0TH_PDOWN__SHIFT           EQU 003H ; Force Pull-Down Enable                            
PC0TH_PDOWN__FORCE_DISABLED  EQU 000H ; Channel 0 (PC0) and channel 1 (PC1) pull-downs are
                                      ; not forced on continuously.                       
PC0TH_PDOWN__FORCE_ENABLED   EQU 008H ; Channel 0 (PC0) and channel 1 (PC1) pull-downs are
                                      ; forced on continuously, grounding the PC0 and PC1 
                                      ; inputs.                                           
                                                                                          
PC0TH_PCTHRESLO__FMASK       EQU 030H ; Input Comparator VIL Threshold                    
PC0TH_PCTHRESLO__SHIFT       EQU 004H ; Input Comparator VIL Threshold                    
PC0TH_PCTHRESLO__42_PERCENT  EQU 000H ; Set the input comparator VIL threshold to 42% of  
                                      ; VIO.                                              
PC0TH_PCTHRESLO__46_PERCENT  EQU 010H ; Set the input comparator VIL threshold to 46% of  
                                      ; VIO.                                              
PC0TH_PCTHRESLO__34_PERCENT  EQU 020H ; Set the input comparator VIL threshold to 34% of  
                                      ; VIO.                                              
PC0TH_PCTHRESLO__38_PERCENT  EQU 030H ; Set the input comparator VIL threshold to 38% of  
                                      ; VIO.                                              
                                                                                          
PC0TH_PCTTHRESHI__FMASK      EQU 0C0H ; Input Comparator VIH Threshold                    
PC0TH_PCTTHRESHI__SHIFT      EQU 006H ; Input Comparator VIH Threshold                    
PC0TH_PCTTHRESHI__59_PERCENT EQU 000H ; Set the input comparator VIH threshold to 59% of  
                                      ; VIO.                                              
PC0TH_PCTTHRESHI__63_PERCENT EQU 040H ; Set the input comparator VIH threshold to 63% of  
                                      ; VIO.                                              
PC0TH_PCTTHRESHI__50_PERCENT EQU 080H ; Set the input comparator VIH threshold to 50% of  
                                      ; VIO.                                              
PC0TH_PCTTHRESHI__55_PERCENT EQU 0C0H ; Set the input comparator VIH threshold to 55% of  
                                      ; VIO.                                              
                                                                                          
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
PMU0CF_CPT0WK__BMASK    EQU 001H ; Comparator0 Wake-up Source Enable and Flag        
PMU0CF_CPT0WK__SHIFT    EQU 000H ; Comparator0 Wake-up Source Enable and Flag        
PMU0CF_CPT0WK__NOT_SET  EQU 000H ; Comparator 0 rising edge did not cause the last   
                                 ; wake-up.                                          
PMU0CF_CPT0WK__SET      EQU 001H ; Comparator 0 rising edge caused the last wake-up. 
                                                                                     
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
; PMU0FL Enums (Power Management Unit Flag @ 0xB6)
;------------------------------------------------------------------------------
PMU0FL_PC0WK__BMASK    EQU 001H ; Pulse Counter Wake-up Source Enable and Flag      
PMU0FL_PC0WK__SHIFT    EQU 000H ; Pulse Counter Wake-up Source Enable and Flag      
PMU0FL_PC0WK__NOT_SET  EQU 000H ; A Pulse Counter event did not cause the last wake-
                                ; up.                                               
PMU0FL_PC0WK__SET      EQU 001H ; A Pulse Counter event caused the last wake-up.    
                                                                                    
PMU0FL_BATMWK__BMASK   EQU 004H ; VBAT Monitor Wake-up Source Enable and Flag       
PMU0FL_BATMWK__SHIFT   EQU 002H ; VBAT Monitor Wake-up Source Enable and Flag       
PMU0FL_BATMWK__NOT_SET EQU 000H ; A VBAT Monitor event did not cause the last wake- 
                                ; up.                                               
PMU0FL_BATMWK__SET     EQU 004H ; A VBAT Monitor event caused the last wake-up.     
                                                                                    
;------------------------------------------------------------------------------
; PMU0MD Enums (Power Management Unit Mode @ 0xB3)
;------------------------------------------------------------------------------
PMU0MD_MONDIS__BMASK    EQU 020H ; POR Supply Monitor Disable         
PMU0MD_MONDIS__SHIFT    EQU 005H ; POR Supply Monitor Disable         
PMU0MD_MONDIS__ENABLED  EQU 000H ; Enable the POR supply monitor.     
PMU0MD_MONDIS__DISABLED EQU 020H ; Disable the POR supply monitor.    
                                                                      
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
; P0DRV Enums (Port 0 Drive Strength @ 0xA4)
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
; P1DRV Enums (Port 1 Drive Strength @ 0xA5)
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
; P2DRV Enums (Port 2 Drive Strength @ 0xA6)
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
; P3DRV Enums (Port 3 Drive Strength @ 0xA1)
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
; P3MDIN Enums (Port 3 Input Mode @ 0xF1)
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
; P3MDOUT Enums (Port 3 Output Mode @ 0xB1)
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
; P4 Enums (Port 4 Pin Latch @ 0xD9)
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
; P4DRV Enums (Port 4 Drive Strength @ 0xA2)
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
; P4MDIN Enums (Port 4 Input Mode @ 0xF2)
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
; P4MDOUT Enums (Port 4 Output Mode @ 0xF9)
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
; P5 Enums (Port 5 Pin Latch @ 0xDA)
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
; P5DRV Enums (Port 5 Drive Strength @ 0xA3)
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
                                                                           
P5DRV_B3__BMASK      EQU 008H ; Port 5 Bit 3 Drive Strength                
P5DRV_B3__SHIFT      EQU 003H ; Port 5 Bit 3 Drive Strength                
P5DRV_B3__LOW_DRIVE  EQU 000H ; P5.3 output has low output drive strength. 
P5DRV_B3__HIGH_DRIVE EQU 008H ; P5.3 output has high output drive strength.
                                                                           
P5DRV_B4__BMASK      EQU 010H ; Port 5 Bit 4 Drive Strength                
P5DRV_B4__SHIFT      EQU 004H ; Port 5 Bit 4 Drive Strength                
P5DRV_B4__LOW_DRIVE  EQU 000H ; P5.4 output has low output drive strength. 
P5DRV_B4__HIGH_DRIVE EQU 010H ; P5.4 output has high output drive strength.
                                                                           
P5DRV_B5__BMASK      EQU 020H ; Port 5 Bit 5 Drive Strength                
P5DRV_B5__SHIFT      EQU 005H ; Port 5 Bit 5 Drive Strength                
P5DRV_B5__LOW_DRIVE  EQU 000H ; P5.5 output has low output drive strength. 
P5DRV_B5__HIGH_DRIVE EQU 020H ; P5.5 output has high output drive strength.
                                                                           
P5DRV_B6__BMASK      EQU 040H ; Port 5 Bit 6 Drive Strength                
P5DRV_B6__SHIFT      EQU 006H ; Port 5 Bit 6 Drive Strength                
P5DRV_B6__LOW_DRIVE  EQU 000H ; P5.6 output has low output drive strength. 
P5DRV_B6__HIGH_DRIVE EQU 040H ; P5.6 output has high output drive strength.
                                                                           
P5DRV_B7__BMASK      EQU 080H ; Port 5 Bit 7 Drive Strength                
P5DRV_B7__SHIFT      EQU 007H ; Port 5 Bit 7 Drive Strength                
P5DRV_B7__LOW_DRIVE  EQU 000H ; P5.7 output has low output drive strength. 
P5DRV_B7__HIGH_DRIVE EQU 080H ; P5.7 output has high output drive strength.
                                                                           
;------------------------------------------------------------------------------
; P5MDIN Enums (Port 5 Input Mode @ 0xF3)
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
                                                                      
P5MDIN_B3__BMASK   EQU 008H ; Port 5 Bit 3 Input Mode                 
P5MDIN_B3__SHIFT   EQU 003H ; Port 5 Bit 3 Input Mode                 
P5MDIN_B3__ANALOG  EQU 000H ; P5.3 pin is configured for analog mode. 
P5MDIN_B3__DIGITAL EQU 008H ; P5.3 pin is configured for digital mode.
                                                                      
P5MDIN_B4__BMASK   EQU 010H ; Port 5 Bit 4 Input Mode                 
P5MDIN_B4__SHIFT   EQU 004H ; Port 5 Bit 4 Input Mode                 
P5MDIN_B4__ANALOG  EQU 000H ; P5.4 pin is configured for analog mode. 
P5MDIN_B4__DIGITAL EQU 010H ; P5.4 pin is configured for digital mode.
                                                                      
P5MDIN_B5__BMASK   EQU 020H ; Port 5 Bit 5 Input Mode                 
P5MDIN_B5__SHIFT   EQU 005H ; Port 5 Bit 5 Input Mode                 
P5MDIN_B5__ANALOG  EQU 000H ; P5.5 pin is configured for analog mode. 
P5MDIN_B5__DIGITAL EQU 020H ; P5.5 pin is configured for digital mode.
                                                                      
P5MDIN_B6__BMASK   EQU 040H ; Port 5 Bit 6 Input Mode                 
P5MDIN_B6__SHIFT   EQU 006H ; Port 5 Bit 6 Input Mode                 
P5MDIN_B6__ANALOG  EQU 000H ; P5.6 pin is configured for analog mode. 
P5MDIN_B6__DIGITAL EQU 040H ; P5.6 pin is configured for digital mode.
                                                                      
P5MDIN_B7__BMASK   EQU 080H ; Port 5 Bit 7 Input Mode                 
P5MDIN_B7__SHIFT   EQU 007H ; Port 5 Bit 7 Input Mode                 
P5MDIN_B7__ANALOG  EQU 000H ; P5.7 pin is configured for analog mode. 
P5MDIN_B7__DIGITAL EQU 080H ; P5.7 pin is configured for digital mode.
                                                                      
;------------------------------------------------------------------------------
; P5MDOUT Enums (Port 5 Output Mode @ 0xFA)
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
; P6 Enums (Port 6 Pin Latch @ 0xDB)
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
; P6DRV Enums (Port 6 Drive Strength @ 0xAA)
;------------------------------------------------------------------------------
P6DRV_B0__BMASK      EQU 001H ; Port 6 Bit 0 Drive Strength                
P6DRV_B0__SHIFT      EQU 000H ; Port 6 Bit 0 Drive Strength                
P6DRV_B0__LOW_DRIVE  EQU 000H ; P6.0 output has low output drive strength. 
P6DRV_B0__HIGH_DRIVE EQU 001H ; P6.0 output has high output drive strength.
                                                                           
P6DRV_B1__BMASK      EQU 002H ; Port 6 Bit 1 Drive Strength                
P6DRV_B1__SHIFT      EQU 001H ; Port 6 Bit 1 Drive Strength                
P6DRV_B1__LOW_DRIVE  EQU 000H ; P6.1 output has low output drive strength. 
P6DRV_B1__HIGH_DRIVE EQU 002H ; P6.1 output has high output drive strength.
                                                                           
P6DRV_B2__BMASK      EQU 004H ; Port 6 Bit 2 Drive Strength                
P6DRV_B2__SHIFT      EQU 002H ; Port 6 Bit 2 Drive Strength                
P6DRV_B2__LOW_DRIVE  EQU 000H ; P6.2 output has low output drive strength. 
P6DRV_B2__HIGH_DRIVE EQU 004H ; P6.2 output has high output drive strength.
                                                                           
P6DRV_B3__BMASK      EQU 008H ; Port 6 Bit 3 Drive Strength                
P6DRV_B3__SHIFT      EQU 003H ; Port 6 Bit 3 Drive Strength                
P6DRV_B3__LOW_DRIVE  EQU 000H ; P6.3 output has low output drive strength. 
P6DRV_B3__HIGH_DRIVE EQU 008H ; P6.3 output has high output drive strength.
                                                                           
P6DRV_B4__BMASK      EQU 010H ; Port 6 Bit 4 Drive Strength                
P6DRV_B4__SHIFT      EQU 004H ; Port 6 Bit 4 Drive Strength                
P6DRV_B4__LOW_DRIVE  EQU 000H ; P6.4 output has low output drive strength. 
P6DRV_B4__HIGH_DRIVE EQU 010H ; P6.4 output has high output drive strength.
                                                                           
P6DRV_B5__BMASK      EQU 020H ; Port 6 Bit 5 Drive Strength                
P6DRV_B5__SHIFT      EQU 005H ; Port 6 Bit 5 Drive Strength                
P6DRV_B5__LOW_DRIVE  EQU 000H ; P6.5 output has low output drive strength. 
P6DRV_B5__HIGH_DRIVE EQU 020H ; P6.5 output has high output drive strength.
                                                                           
P6DRV_B6__BMASK      EQU 040H ; Port 6 Bit 6 Drive Strength                
P6DRV_B6__SHIFT      EQU 006H ; Port 6 Bit 6 Drive Strength                
P6DRV_B6__LOW_DRIVE  EQU 000H ; P6.6 output has low output drive strength. 
P6DRV_B6__HIGH_DRIVE EQU 040H ; P6.6 output has high output drive strength.
                                                                           
P6DRV_B7__BMASK      EQU 080H ; Port 6 Bit 7 Drive Strength                
P6DRV_B7__SHIFT      EQU 007H ; Port 6 Bit 7 Drive Strength                
P6DRV_B7__LOW_DRIVE  EQU 000H ; P6.7 output has low output drive strength. 
P6DRV_B7__HIGH_DRIVE EQU 080H ; P6.7 output has high output drive strength.
                                                                           
;------------------------------------------------------------------------------
; P6MDIN Enums (Port 6 Input Mode @ 0xF4)
;------------------------------------------------------------------------------
P6MDIN_B0__BMASK   EQU 001H ; Port 6 Bit 0 Input Mode                 
P6MDIN_B0__SHIFT   EQU 000H ; Port 6 Bit 0 Input Mode                 
P6MDIN_B0__ANALOG  EQU 000H ; P6.0 pin is configured for analog mode. 
P6MDIN_B0__DIGITAL EQU 001H ; P6.0 pin is configured for digital mode.
                                                                      
P6MDIN_B1__BMASK   EQU 002H ; Port 6 Bit 1 Input Mode                 
P6MDIN_B1__SHIFT   EQU 001H ; Port 6 Bit 1 Input Mode                 
P6MDIN_B1__ANALOG  EQU 000H ; P6.1 pin is configured for analog mode. 
P6MDIN_B1__DIGITAL EQU 002H ; P6.1 pin is configured for digital mode.
                                                                      
P6MDIN_B2__BMASK   EQU 004H ; Port 6 Bit 2 Input Mode                 
P6MDIN_B2__SHIFT   EQU 002H ; Port 6 Bit 2 Input Mode                 
P6MDIN_B2__ANALOG  EQU 000H ; P6.2 pin is configured for analog mode. 
P6MDIN_B2__DIGITAL EQU 004H ; P6.2 pin is configured for digital mode.
                                                                      
P6MDIN_B3__BMASK   EQU 008H ; Port 6 Bit 3 Input Mode                 
P6MDIN_B3__SHIFT   EQU 003H ; Port 6 Bit 3 Input Mode                 
P6MDIN_B3__ANALOG  EQU 000H ; P6.3 pin is configured for analog mode. 
P6MDIN_B3__DIGITAL EQU 008H ; P6.3 pin is configured for digital mode.
                                                                      
P6MDIN_B4__BMASK   EQU 010H ; Port 6 Bit 4 Input Mode                 
P6MDIN_B4__SHIFT   EQU 004H ; Port 6 Bit 4 Input Mode                 
P6MDIN_B4__ANALOG  EQU 000H ; P6.4 pin is configured for analog mode. 
P6MDIN_B4__DIGITAL EQU 010H ; P6.4 pin is configured for digital mode.
                                                                      
P6MDIN_B5__BMASK   EQU 020H ; Port 6 Bit 5 Input Mode                 
P6MDIN_B5__SHIFT   EQU 005H ; Port 6 Bit 5 Input Mode                 
P6MDIN_B5__ANALOG  EQU 000H ; P6.5 pin is configured for analog mode. 
P6MDIN_B5__DIGITAL EQU 020H ; P6.5 pin is configured for digital mode.
                                                                      
P6MDIN_B6__BMASK   EQU 040H ; Port 6 Bit 6 Input Mode                 
P6MDIN_B6__SHIFT   EQU 006H ; Port 6 Bit 6 Input Mode                 
P6MDIN_B6__ANALOG  EQU 000H ; P6.6 pin is configured for analog mode. 
P6MDIN_B6__DIGITAL EQU 040H ; P6.6 pin is configured for digital mode.
                                                                      
P6MDIN_B7__BMASK   EQU 080H ; Port 6 Bit 7 Input Mode                 
P6MDIN_B7__SHIFT   EQU 007H ; Port 6 Bit 7 Input Mode                 
P6MDIN_B7__ANALOG  EQU 000H ; P6.7 pin is configured for analog mode. 
P6MDIN_B7__DIGITAL EQU 080H ; P6.7 pin is configured for digital mode.
                                                                      
;------------------------------------------------------------------------------
; P6MDOUT Enums (Port 6 Output Mode @ 0xFB)
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
; P7 Enums (Port 7 Pin Latch @ 0xDC)
;------------------------------------------------------------------------------
P7_B0__BMASK EQU 001H ; Port 7 Bit 0 Latch                            
P7_B0__SHIFT EQU 000H ; Port 7 Bit 0 Latch                            
P7_B0__LOW   EQU 000H ; P7.0 is low. Set P7.0 to drive low.           
P7_B0__HIGH  EQU 001H ; P7.0 is high. Set P7.0 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P7DRV Enums (Port 7 Drive Strength @ 0xAB)
;------------------------------------------------------------------------------
P7DRV_B0__BMASK      EQU 001H ; Port 7 Bit 0 Drive Strength                
P7DRV_B0__SHIFT      EQU 000H ; Port 7 Bit 0 Drive Strength                
P7DRV_B0__LOW_DRIVE  EQU 000H ; P7.0 output has low output drive strength. 
P7DRV_B0__HIGH_DRIVE EQU 001H ; P7.0 output has high output drive strength.
                                                                           
;------------------------------------------------------------------------------
; P7MDOUT Enums (Port 7 Output Mode @ 0xFC)
;------------------------------------------------------------------------------
P7MDOUT_B0__BMASK      EQU 001H ; Port 7 Bit 0 Output Mode  
P7MDOUT_B0__SHIFT      EQU 000H ; Port 7 Bit 0 Output Mode  
P7MDOUT_B0__OPEN_DRAIN EQU 000H ; P7.0 output is open-drain.
P7MDOUT_B0__PUSH_PULL  EQU 001H ; P7.0 output is push-pull. 
                                                            
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
; ALARM0B0 Enums (RTC Alarm 0 Programmed Value 0 @ 0x08)
;------------------------------------------------------------------------------
ALARM0B0_ALARM0B0__FMASK EQU 0FFH ; RTC Alarm 0 Programmed Value 0
ALARM0B0_ALARM0B0__SHIFT EQU 000H ; RTC Alarm 0 Programmed Value 0
                                                                  
;------------------------------------------------------------------------------
; ALARM0B1 Enums (RTC Alarm 0 Programmed Value 1 @ 0x09)
;------------------------------------------------------------------------------
ALARM0B1_ALARM0B1__FMASK EQU 0FFH ; RTC Alarm 0 Programmed Value 1
ALARM0B1_ALARM0B1__SHIFT EQU 000H ; RTC Alarm 0 Programmed Value 1
                                                                  
;------------------------------------------------------------------------------
; ALARM0B2 Enums (RTC Alarm 0 Programmed Value 2 @ 0x0A)
;------------------------------------------------------------------------------
ALARM0B2_ALARM0B2__FMASK EQU 0FFH ; RTC Alarm 0 Programmed Value 2
ALARM0B2_ALARM0B2__SHIFT EQU 000H ; RTC Alarm 0 Programmed Value 2
                                                                  
;------------------------------------------------------------------------------
; ALARM0B3 Enums (RTC Alarm 0 Programmed Value 3 @ 0x0B)
;------------------------------------------------------------------------------
ALARM0B3_ALARM0B3__FMASK EQU 0FFH ; RTC Alarm 0 Programmed Value 3
ALARM0B3_ALARM0B3__SHIFT EQU 000H ; RTC Alarm 0 Programmed Value 3
                                                                  
;------------------------------------------------------------------------------
; ALARM1B0 Enums (RTC Alarm 1 Programmed Value 0 @ 0x0C)
;------------------------------------------------------------------------------
ALARM1B0_ALARM1B0__FMASK EQU 0FFH ; RTC Alarm 1 Programmed Value 0
ALARM1B0_ALARM1B0__SHIFT EQU 000H ; RTC Alarm 1 Programmed Value 0
                                                                  
;------------------------------------------------------------------------------
; ALARM1B1 Enums (RTC Alarm 1 Programmed Value 1 @ 0x0D)
;------------------------------------------------------------------------------
ALARM1B1_ALARM1B1__FMASK EQU 0FFH ; RTC Alarm 1 Programmed Value 1
ALARM1B1_ALARM1B1__SHIFT EQU 000H ; RTC Alarm 1 Programmed Value 1
                                                                  
;------------------------------------------------------------------------------
; ALARM1B2 Enums (RTC Alarm 1 Programmed Value 2 @ 0x0E)
;------------------------------------------------------------------------------
ALARM1B2_ALARM1B2__FMASK EQU 0FFH ; RTC Alarm 1 Programmed Value 2
ALARM1B2_ALARM1B2__SHIFT EQU 000H ; RTC Alarm 1 Programmed Value 2
                                                                  
;------------------------------------------------------------------------------
; ALARM1B3 Enums (RTC Alarm 1 Programmed Value 3 @ 0x0F)
;------------------------------------------------------------------------------
ALARM1B3_ALARM1B3__FMASK EQU 0FFH ; RTC Alarm 1 Programmed Value 3
ALARM1B3_ALARM1B3__SHIFT EQU 000H ; RTC Alarm 1 Programmed Value 3
                                                                  
;------------------------------------------------------------------------------
; ALARM2B0 Enums (RTC Alarm 2 Programmed Value 0 @ 0x10)
;------------------------------------------------------------------------------
ALARM2B0_ALARM2B0__FMASK EQU 0FFH ; RTC Alarm 2 Programmed Value 0
ALARM2B0_ALARM2B0__SHIFT EQU 000H ; RTC Alarm 2 Programmed Value 0
                                                                  
;------------------------------------------------------------------------------
; ALARM2B1 Enums (RTC Alarm 2 Programmed Value 1 @ 0x11)
;------------------------------------------------------------------------------
ALARM2B1_ALARM2B1__FMASK EQU 0FFH ; RTC Alarm 2 Programmed Value 1
ALARM2B1_ALARM2B1__SHIFT EQU 000H ; RTC Alarm 2 Programmed Value 1
                                                                  
;------------------------------------------------------------------------------
; ALARM2B2 Enums (RTC Alarm 2 Programmed Value 2 @ 0x12)
;------------------------------------------------------------------------------
ALARM2B2_ALARM2B2__FMASK EQU 0FFH ; RTC Alarm 2 Programmed Value 2
ALARM2B2_ALARM2B2__SHIFT EQU 000H ; RTC Alarm 2 Programmed Value 2
                                                                  
;------------------------------------------------------------------------------
; ALARM2B3 Enums (RTC Alarm 2 Programmed Value 3 @ 0x13)
;------------------------------------------------------------------------------
ALARM2B3_ALARM2B3__FMASK EQU 0FFH ; RTC Alarm 2 Programmed Value 3
ALARM2B3_ALARM2B3__SHIFT EQU 000H ; RTC Alarm 2 Programmed Value 3
                                                                  
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
RTC0ADR_ADDR__FMASK      EQU 01FH ; RTC Indirect Register Address                     
RTC0ADR_ADDR__SHIFT      EQU 000H ; RTC Indirect Register Address                     
RTC0ADR_ADDR__CAPTURE0   EQU 000H ; Select the CAPTURE0 register.                     
RTC0ADR_ADDR__CAPTURE1   EQU 001H ; Select the CAPTURE1 register.                     
RTC0ADR_ADDR__CAPTURE2   EQU 002H ; Select the CAPTURE2 register.                     
RTC0ADR_ADDR__CAPTURE3   EQU 003H ; Select the CAPTURE3 register.                     
RTC0ADR_ADDR__RTC0CN     EQU 004H ; Select the RTC0CN register.                       
RTC0ADR_ADDR__RTC0XCN    EQU 005H ; Select the RTC0XCN register.                      
RTC0ADR_ADDR__RTC0XCF    EQU 006H ; Select the RTC0XCF register.                      
RTC0ADR_ADDR__RTC0CF     EQU 007H ; Select the RTC0CF register.                       
RTC0ADR_ADDR__ALARM1B0   EQU 00CH ; Select the Alarm 1 Byte 0 register.               
RTC0ADR_ADDR__ALARM1B1   EQU 00DH ; Select the Alarm 1 Byte 1 register.               
RTC0ADR_ADDR__ALARM1B2   EQU 00EH ; Select the Alarm 1 Byte 2 register.               
RTC0ADR_ADDR__ALARM1B3   EQU 00FH ; Select the Alarm 1 Byte 3 register.               
RTC0ADR_ADDR__ALARM2B0   EQU 010H ; Select the Alarm 2 Byte 0 register.               
RTC0ADR_ADDR__ALARM2B1   EQU 011H ; Select the Alarm 2 Byte 1 register.               
RTC0ADR_ADDR__ALARM2B2   EQU 012H ; Select the Alarm 2 Byte 2 register.               
RTC0ADR_ADDR__ALARM2B3   EQU 013H ; Select the Alarm 2 Byte 3 register.               
                                                                                      
RTC0ADR_AUTORD__BMASK    EQU 040H ; RTC Interface Autoread Enable                     
RTC0ADR_AUTORD__SHIFT    EQU 006H ; RTC Interface Autoread Enable                     
RTC0ADR_AUTORD__DISABLED EQU 000H ; Disable autoread. Firmware must write the BUSY bit
                                  ; for each RTC indirect read operation.             
RTC0ADR_AUTORD__ENABLED  EQU 040H ; Enable autoread. The next RTC indirect read       
                                  ; operation is initiated when firmware reads the    
                                  ; RTC0DAT register.                                 
                                                                                      
;------------------------------------------------------------------------------
; RTC0CF Enums (RTC Configuration @ 0x07)
;------------------------------------------------------------------------------
RTC0CF_ALRM0EN__BMASK    EQU 001H ; Alarm 0 Enable                                 
RTC0CF_ALRM0EN__SHIFT    EQU 000H ; Alarm 0 Enable                                 
RTC0CF_ALRM0EN__DISABLED EQU 000H ; Disable Alarm 0.                               
RTC0CF_ALRM0EN__ENABLED  EQU 001H ; Enable Alarm 0.                                
                                                                                   
RTC0CF_ALRM1EN__BMASK    EQU 002H ; Alarm 1 Enable                                 
RTC0CF_ALRM1EN__SHIFT    EQU 001H ; Alarm 1 Enable                                 
RTC0CF_ALRM1EN__DISABLED EQU 000H ; Disable Alarm 1.                               
RTC0CF_ALRM1EN__ENABLED  EQU 002H ; Enable Alarm 1.                                
                                                                                   
RTC0CF_ALRM2EN__BMASK    EQU 004H ; Alarm 2 Enable                                 
RTC0CF_ALRM2EN__SHIFT    EQU 002H ; Alarm 2 Enable                                 
RTC0CF_ALRM2EN__DISABLED EQU 000H ; Disable Alarm 2.                               
RTC0CF_ALRM2EN__ENABLED  EQU 004H ; Enable Alarm 2.                                
                                                                                   
RTC0CF_AUTORST__BMASK    EQU 008H ; Auto Reset Enable                              
RTC0CF_AUTORST__SHIFT    EQU 003H ; Auto Reset Enable                              
RTC0CF_AUTORST__DISABLED EQU 000H ; Disable auto reset.                            
RTC0CF_AUTORST__ENABLED  EQU 008H ; Enable auto reset.                             
                                                                                   
RTC0CF_ALRM0__BMASK      EQU 010H ; Event Flag for Alarm 0                         
RTC0CF_ALRM0__SHIFT      EQU 004H ; Event Flag for Alarm 0                         
RTC0CF_ALRM0__NOT_SET    EQU 000H ; An Alarm 0 event has not occured since the last
                                  ; time the flag was cleared.                     
RTC0CF_ALRM0__SET        EQU 010H ; An Alarm 0 event has occured.                  
                                                                                   
RTC0CF_ALRM1__BMASK      EQU 020H ; Event Flag for Alarm 1                         
RTC0CF_ALRM1__SHIFT      EQU 005H ; Event Flag for Alarm 1                         
RTC0CF_ALRM1__NOT_SET    EQU 000H ; An Alarm 1 event has not occured since the last
                                  ; time the flag was cleared.                     
RTC0CF_ALRM1__SET        EQU 020H ; An Alarm 1 event has occured.                  
                                                                                   
RTC0CF_ALRM2__BMASK      EQU 040H ; Event Flag for Alarm 2                         
RTC0CF_ALRM2__SHIFT      EQU 006H ; Event Flag for Alarm 2                         
RTC0CF_ALRM2__NOT_SET    EQU 000H ; An Alarm 2 event has not occured since the last
                                  ; time the flag was cleared.                     
RTC0CF_ALRM2__SET        EQU 040H ; An Alarm 2 event has occured.                  
                                                                                   
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
                                                                               
RTC0CN_HSMODE__BMASK     EQU 004H ; High Speed Mode Enable                     
RTC0CN_HSMODE__SHIFT     EQU 002H ; High Speed Mode Enable                     
RTC0CN_HSMODE__DISABLED  EQU 000H ; Disable high speed mode.                   
RTC0CN_HSMODE__ENABLED   EQU 004H ; Enable high speed mode.                    
                                                                               
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
; RTC0KEY Enums (RTC Lock and Key @ 0xAE)
;------------------------------------------------------------------------------
RTC0KEY_RTC0ST__FMASK    EQU 0FFH ; RTC Interface Status      
RTC0KEY_RTC0ST__SHIFT    EQU 000H ; RTC Interface Status      
RTC0KEY_RTC0ST__UNLOCKED EQU 002H ; RTC Interface is unlocked.
                                                              
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
; SPI1CFG Enums (SPI1 Configuration @ 0xA1)
;------------------------------------------------------------------------------
SPI1CFG_RXBMT__BMASK                EQU 001H ; Receive Buffer Empty                              
SPI1CFG_RXBMT__SHIFT                EQU 000H ; Receive Buffer Empty                              
SPI1CFG_RXBMT__NOT_SET              EQU 000H ; New data is available in the receive buffer (Slave
                                             ; mode).                                            
SPI1CFG_RXBMT__SET                  EQU 001H ; No new data in the receive buffer (Slave mode).   
                                                                                                 
SPI1CFG_SRMT__BMASK                 EQU 002H ; Shift Register Empty                              
SPI1CFG_SRMT__SHIFT                 EQU 001H ; Shift Register Empty                              
SPI1CFG_SRMT__NOT_SET               EQU 000H ; The shift register is not empty.                  
SPI1CFG_SRMT__SET                   EQU 002H ; The shift register is empty.                      
                                                                                                 
SPI1CFG_NSSIN__BMASK                EQU 004H ; NSS Instantaneous Pin Input                       
SPI1CFG_NSSIN__SHIFT                EQU 002H ; NSS Instantaneous Pin Input                       
SPI1CFG_NSSIN__LOW                  EQU 000H ; The NSS pin is low.                               
SPI1CFG_NSSIN__HIGH                 EQU 004H ; The NSS pin is high.                              
                                                                                                 
SPI1CFG_SLVSEL__BMASK               EQU 008H ; Slave Selected Flag                               
SPI1CFG_SLVSEL__SHIFT               EQU 003H ; Slave Selected Flag                               
SPI1CFG_SLVSEL__NOT_SELECTED        EQU 000H ; The Slave is not selected (NSS is high).          
SPI1CFG_SLVSEL__SELECTED            EQU 008H ; The Slave is selected (NSS is low).               
                                                                                                 
SPI1CFG_CKPOL__BMASK                EQU 010H ; SPI1 Clock Polarity                               
SPI1CFG_CKPOL__SHIFT                EQU 004H ; SPI1 Clock Polarity                               
SPI1CFG_CKPOL__IDLE_LOW             EQU 000H ; SCK line low in idle state.                       
SPI1CFG_CKPOL__IDLE_HIGH            EQU 010H ; SCK line high in idle state.                      
                                                                                                 
SPI1CFG_CKPHA__BMASK                EQU 020H ; SPI1 Clock Phase                                  
SPI1CFG_CKPHA__SHIFT                EQU 005H ; SPI1 Clock Phase                                  
SPI1CFG_CKPHA__DATA_CENTERED_FIRST  EQU 000H ; Data centered on first edge of SCK period.        
SPI1CFG_CKPHA__DATA_CENTERED_SECOND EQU 020H ; Data centered on second edge of SCK period.       
                                                                                                 
SPI1CFG_MSTEN__BMASK                EQU 040H ; Master Mode Enable                                
SPI1CFG_MSTEN__SHIFT                EQU 006H ; Master Mode Enable                                
SPI1CFG_MSTEN__MASTER_DISABLED      EQU 000H ; Disable master mode. Operate in slave mode.       
SPI1CFG_MSTEN__MASTER_ENABLED       EQU 040H ; Enable master mode. Operate as a master.          
                                                                                                 
SPI1CFG_SPIBSY__BMASK               EQU 080H ; SPI Busy                                          
SPI1CFG_SPIBSY__SHIFT               EQU 007H ; SPI Busy                                          
SPI1CFG_SPIBSY__NOT_SET             EQU 000H ; A SPI transfer is not in progress.                
SPI1CFG_SPIBSY__SET                 EQU 080H ; A SPI transfer is in progress.                    
                                                                                                 
;------------------------------------------------------------------------------
; SPI1CKR Enums (SPI1 Clock Rate @ 0xA2)
;------------------------------------------------------------------------------
SPI1CKR_SPI1CKR__FMASK EQU 0FFH ; SPI1 Clock Rate
SPI1CKR_SPI1CKR__SHIFT EQU 000H ; SPI1 Clock Rate
                                                 
;------------------------------------------------------------------------------
; SPI1CN Enums (SPI1 Control @ 0xF8)
;------------------------------------------------------------------------------
SPI1CN_SPIEN__BMASK                  EQU 001H ; SPI1 Enable                                       
SPI1CN_SPIEN__SHIFT                  EQU 000H ; SPI1 Enable                                       
SPI1CN_SPIEN__DISABLED               EQU 000H ; Disable the SPI module.                           
SPI1CN_SPIEN__ENABLED                EQU 001H ; Enable the SPI module.                            
                                                                                                  
SPI1CN_TXBMT__BMASK                  EQU 002H ; Transmit Buffer Empty                             
SPI1CN_TXBMT__SHIFT                  EQU 001H ; Transmit Buffer Empty                             
SPI1CN_TXBMT__NOT_SET                EQU 000H ; The transmit buffer is not empty.                 
SPI1CN_TXBMT__SET                    EQU 002H ; The transmit buffer is empty.                     
                                                                                                  
SPI1CN_NSSMD__FMASK                  EQU 00CH ; Slave Select Mode                                 
SPI1CN_NSSMD__SHIFT                  EQU 002H ; Slave Select Mode                                 
SPI1CN_NSSMD__3_WIRE                 EQU 000H ; 3-Wire Slave or 3-Wire Master Mode. NSS signal is 
                                              ; not routed to a port pin.                         
SPI1CN_NSSMD__4_WIRE_SLAVE           EQU 004H ; 4-Wire Slave or Multi-Master Mode. NSS is an input
                                              ; to the device.                                    
SPI1CN_NSSMD__4_WIRE_MASTER_NSS_LOW  EQU 008H ; 4-Wire Single-Master Mode. NSS is an output and   
                                              ; logic low.                                        
SPI1CN_NSSMD__4_WIRE_MASTER_NSS_HIGH EQU 00CH ; 4-Wire Single-Master Mode. NSS is an output and   
                                              ; logic high.                                       
                                                                                                  
SPI1CN_RXOVRN__BMASK                 EQU 010H ; Receive Overrun Flag                              
SPI1CN_RXOVRN__SHIFT                 EQU 004H ; Receive Overrun Flag                              
SPI1CN_RXOVRN__NOT_SET               EQU 000H ; A receive overrun did not occur.                  
SPI1CN_RXOVRN__SET                   EQU 010H ; A receive overrun occurred.                       
                                                                                                  
SPI1CN_MODF__BMASK                   EQU 020H ; Mode Fault Flag                                   
SPI1CN_MODF__SHIFT                   EQU 005H ; Mode Fault Flag                                   
SPI1CN_MODF__NOT_SET                 EQU 000H ; A master collision did not occur.                 
SPI1CN_MODF__SET                     EQU 020H ; A master collision occurred.                      
                                                                                                  
SPI1CN_WCOL__BMASK                   EQU 040H ; Write Collision Flag                              
SPI1CN_WCOL__SHIFT                   EQU 006H ; Write Collision Flag                              
SPI1CN_WCOL__NOT_SET                 EQU 000H ; A write collision did not occur.                  
SPI1CN_WCOL__SET                     EQU 040H ; A write collision occurred.                       
                                                                                                  
SPI1CN_SPIF__BMASK                   EQU 080H ; SPI1 Interrupt Flag                               
SPI1CN_SPIF__SHIFT                   EQU 007H ; SPI1 Interrupt Flag                               
SPI1CN_SPIF__NOT_SET                 EQU 000H ; A data transfer has not completed since the last  
                                              ; time SPIF was cleared.                            
SPI1CN_SPIF__SET                     EQU 080H ; A data transfer completed.                        
                                                                                                  
;------------------------------------------------------------------------------
; SPI1DAT Enums (SPI1 Data @ 0xA3)
;------------------------------------------------------------------------------
SPI1DAT_SPI1DAT__FMASK EQU 0FFH ; SPI1 Transmit and Receive Data
SPI1DAT_SPI1DAT__SHIFT EQU 000H ; SPI1 Transmit and Receive Data
                                                                
;------------------------------------------------------------------------------
; TOFFH Enums (Temperature Sensor Offset High @ 0xBE)
;------------------------------------------------------------------------------
TOFFH_TOFF__FMASK EQU 0FFH ; Temperature Sensor Offset High
TOFFH_TOFF__SHIFT EQU 000H ; Temperature Sensor Offset High
                                                           
;------------------------------------------------------------------------------
; TOFFL Enums (Temperature Sensor Offset Low @ 0xBD)
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
TMR2CN_T2XCLK__FMASK                  EQU 003H ; Timer 2 External Clock Select                     
TMR2CN_T2XCLK__SHIFT                  EQU 000H ; Timer 2 External Clock Select                     
TMR2CN_T2XCLK__SYSCLK_DIV_12_CAP_RTC  EQU 000H ; External Clock is SYSCLK/12. Capture trigger is   
                                               ; RTC/8.                                            
TMR2CN_T2XCLK__CMP_0_CAP_RTC          EQU 001H ; External Clock is Comparator 0. Capture trigger is
                                               ; RTC/8.                                            
TMR2CN_T2XCLK__SYSCLK_DIV_12_CAP_CMP0 EQU 002H ; External Clock is SYSCLK/12. Capture trigger is   
                                               ; Comparator 0.                                     
TMR2CN_T2XCLK__RTC_DIV_8_CAP_CMP0     EQU 003H ; External Clock is RTC/8. Capture trigger is       
                                               ; Comparator 0.                                     
                                                                                                   
TMR2CN_TR2__BMASK                     EQU 004H ; Timer 2 Run Control                               
TMR2CN_TR2__SHIFT                     EQU 002H ; Timer 2 Run Control                               
TMR2CN_TR2__STOP                      EQU 000H ; Stop Timer 2.                                     
TMR2CN_TR2__RUN                       EQU 004H ; Start Timer 2 running.                            
                                                                                                   
TMR2CN_T2SPLIT__BMASK                 EQU 008H ; Timer 2 Split Mode Enable                         
TMR2CN_T2SPLIT__SHIFT                 EQU 003H ; Timer 2 Split Mode Enable                         
TMR2CN_T2SPLIT__16_BIT_RELOAD         EQU 000H ; Timer 2 operates in 16-bit auto-reload mode.      
TMR2CN_T2SPLIT__8_BIT_RELOAD          EQU 008H ; Timer 2 operates as two 8-bit auto-reload timers. 
                                                                                                   
TMR2CN_TF2CEN__BMASK                  EQU 010H ; Timer 2 Capture Enable                            
TMR2CN_TF2CEN__SHIFT                  EQU 004H ; Timer 2 Capture Enable                            
TMR2CN_TF2CEN__DISABLED               EQU 000H ; Disable capture mode.                             
TMR2CN_TF2CEN__ENABLED                EQU 010H ; Enable capture mode.                              
                                                                                                   
TMR2CN_TF2LEN__BMASK                  EQU 020H ; Timer 2 Low Byte Interrupt Enable                 
TMR2CN_TF2LEN__SHIFT                  EQU 005H ; Timer 2 Low Byte Interrupt Enable                 
TMR2CN_TF2LEN__DISABLED               EQU 000H ; Disable low byte interrupts.                      
TMR2CN_TF2LEN__ENABLED                EQU 020H ; Enable low byte interrupts.                       
                                                                                                   
TMR2CN_TF2L__BMASK                    EQU 040H ; Timer 2 Low Byte Overflow Flag                    
TMR2CN_TF2L__SHIFT                    EQU 006H ; Timer 2 Low Byte Overflow Flag                    
TMR2CN_TF2L__NOT_SET                  EQU 000H ; Timer 2 low byte did not overflow.                
TMR2CN_TF2L__SET                      EQU 040H ; Timer 2 low byte overflowed.                      
                                                                                                   
TMR2CN_TF2H__BMASK                    EQU 080H ; Timer 2 High Byte Overflow Flag                   
TMR2CN_TF2H__SHIFT                    EQU 007H ; Timer 2 High Byte Overflow Flag                   
TMR2CN_TF2H__NOT_SET                  EQU 000H ; Timer 2 8-bit high byte or 16-bit value did not   
                                               ; overflow.                                         
TMR2CN_TF2H__SET                      EQU 080H ; Timer 2 8-bit high byte or 16-bit value           
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
VDM0CN_VBOKIE__BMASK            EQU 001H ; VBAT Early Warning Interrupt Enable       
VDM0CN_VBOKIE__SHIFT            EQU 000H ; VBAT Early Warning Interrupt Enable       
VDM0CN_VBOKIE__DISABLED         EQU 000H ; Disable the VBAT Early Warning interrupt. 
VDM0CN_VBOKIE__ENABLED          EQU 001H ; Enable the VBAT Early Warning interrupt.  
                                                                                     
VDM0CN_VBOK__BMASK              EQU 002H ; VBAT Early Warning Status                 
VDM0CN_VBOK__SHIFT              EQU 001H ; VBAT Early Warning Status                 
VDM0CN_VBOK__AT_OR_BELOW        EQU 000H ; VBAT is at or below the VDDWARN threshold.
VDM0CN_VBOK__ABOVE              EQU 002H ; VBAT is above the VDDWARN threshold.      
                                                                                     
VDM0CN_VBSTAT__BMASK            EQU 004H ; VBAT Supply Status                        
VDM0CN_VBSTAT__SHIFT            EQU 002H ; VBAT Supply Status                        
VDM0CN_VBSTAT__AT_OR_BELOW      EQU 000H ; VBAT is at or below the VRST threshold.   
VDM0CN_VBSTAT__ABOVE            EQU 004H ; VBAT is above the VRST threshold.         
                                                                                     
VDM0CN_VBMEN__BMASK             EQU 008H ; VBAT Supply Monitor Enable                
VDM0CN_VBMEN__SHIFT             EQU 003H ; VBAT Supply Monitor Enable                
VDM0CN_VBMEN__DISABLED          EQU 000H ; Disable the VBAT Supply Monitor.          
VDM0CN_VBMEN__ENABLED           EQU 008H ; Enable the VBAT Supply Monitor.           
                                                                                     
VDM0CN_VDDOKIE__BMASK           EQU 010H ; Digital Early Warning Interrupt Enable    
VDM0CN_VDDOKIE__SHIFT           EQU 004H ; Digital Early Warning Interrupt Enable    
VDM0CN_VDDOKIE__DISABLED        EQU 000H ; Disable the VDD early warning interrupt.  
VDM0CN_VDDOKIE__ENABLED         EQU 010H ; Enable the VDD early warning interrupt.   
                                                                                     
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
                                                                                          
REF0CN_REFGND__BMASK          EQU 020H ; Analog Ground Reference                          
REF0CN_REFGND__SHIFT          EQU 005H ; Analog Ground Reference                          
REF0CN_REFGND__GND_PIN        EQU 000H ; The ADC0 ground reference is the GND pin.        
REF0CN_REFGND__AGND_PIN       EQU 020H ; The ADC0 ground reference is the P0.1/AGND pin.  
                                                                                          
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
; EMI0CF Enums (External Memory Configuration @ 0xAB)
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
                                                                                                   
;------------------------------------------------------------------------------
; EMI0CN Enums (External Memory Interface Control @ 0xAA)
;------------------------------------------------------------------------------
EMI0CN_PGSEL__FMASK EQU 0FFH ; XRAM Page Select
EMI0CN_PGSEL__SHIFT EQU 000H ; XRAM Page Select
                                               
;------------------------------------------------------------------------------
; EMI0TC Enums (External Memory Timing Control @ 0xAF)
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
                                                                                
