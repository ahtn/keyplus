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
; CLKMUL Enums (Clock Multiplier Control @ 0xB9)
;------------------------------------------------------------------------------
CLKMUL_MULSEL__BMASK    EQU 001H ; Clock Multiplier Input Select             
CLKMUL_MULSEL__SHIFT    EQU 000H ; Clock Multiplier Input Select             
CLKMUL_MULSEL__HFOSC    EQU 000H ; Clock Multiplier input clock source is the
                                 ; Internal High-Frequency Oscillator.       
CLKMUL_MULSEL__EXTOSC   EQU 001H ; Clock Multiplier input clock source is the
                                 ; External Oscillator.                      
                                                                             
CLKMUL_MULRDY__BMASK    EQU 020H ; Clock Multiplier Ready                    
CLKMUL_MULRDY__SHIFT    EQU 005H ; Clock Multiplier Ready                    
CLKMUL_MULRDY__NOT_SET  EQU 000H ; Clock Multiplier not ready.               
CLKMUL_MULRDY__SET      EQU 020H ; Clock Multiplier is ready (locked).       
                                                                             
CLKMUL_MULINIT__BMASK   EQU 040H ; Clock Multiplier Initialize               
CLKMUL_MULINIT__SHIFT   EQU 006H ; Clock Multiplier Initialize               
CLKMUL_MULINIT__NOT_SET EQU 000H ; Do not initialize the Clock Multiplier.   
CLKMUL_MULINIT__SET     EQU 040H ; Initialize the Clock Multiplier.          
                                                                             
CLKMUL_MULEN__BMASK     EQU 080H ; Clock Multiplier Enable                   
CLKMUL_MULEN__SHIFT     EQU 007H ; Clock Multiplier Enable                   
CLKMUL_MULEN__DISABLED  EQU 000H ; Disable the Clock Multiplier.             
CLKMUL_MULEN__ENABLED   EQU 080H ; Enable the Clock Multiplier.              
                                                                             
;------------------------------------------------------------------------------
; CLKSEL Enums (Clock Select @ 0xA9)
;------------------------------------------------------------------------------
CLKSEL_CLKSL__FMASK         EQU 007H ; System Clock Source Select Bits                   
CLKSEL_CLKSL__SHIFT         EQU 000H ; System Clock Source Select Bits                   
CLKSEL_CLKSL__DIVIDED_HFOSC EQU 000H ; Clock (SYSCLK) derived from the Internal High-    
                                     ; Frequency Oscillator and scaled per the IFCN bits 
                                     ; in register OSCICN.                               
CLKSEL_CLKSL__EXTOSC        EQU 001H ; Clock (SYSCLK) derived from the External          
                                     ; Oscillator circuit.                               
CLKSEL_CLKSL__CLKMUL_DIV_2  EQU 002H ; Clock (SYSCLK) derived from the 4x Clock          
                                     ; Multiplier / 2.                                   
CLKSEL_CLKSL__LFOSC         EQU 003H ; Clock (SYSCLK) derived from the Internal Low-     
                                     ; Frequency Oscillator.                             
                                                                                         
CLKSEL_USBCLK__FMASK        EQU 030H ; USB Clock Source Select Bits                      
CLKSEL_USBCLK__SHIFT        EQU 004H ; USB Clock Source Select Bits                      
CLKSEL_USBCLK__CLKMUL       EQU 000H ; USB clock (USBCLK) derived from the 4x Clock      
                                     ; Multiplier.                                       
CLKSEL_USBCLK__HFOSC_DIV_2  EQU 010H ; USB clock (USBCLK) derived from the Internal High-
                                     ; Frequency Oscillator / 2.                         
CLKSEL_USBCLK__EXTOSC       EQU 020H ; USB clock (USBCLK) derived from the External      
                                     ; Oscillator.                                       
CLKSEL_USBCLK__OFF          EQU 030H ; USB clock (USBCLK) off.                           
                                                                                         
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
FLSCL_FOSE__BMASK    EQU 080H ; Flash One-Shot Enable                   
FLSCL_FOSE__SHIFT    EQU 007H ; Flash One-Shot Enable                   
FLSCL_FOSE__DISABLED EQU 000H ; Disable the flash one-shot.             
FLSCL_FOSE__ENABLED  EQU 080H ; Enable the flash one-shot (recommended).
                                                                        
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
OSCICL_OSCICL__FMASK EQU 01FH ; Internal Oscillator Calibration
OSCICL_OSCICL__SHIFT EQU 000H ; Internal Oscillator Calibration
                                                               
;------------------------------------------------------------------------------
; OSCICN Enums (High Frequency Oscillator Control @ 0xB2)
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
                                                                                     
OSCICN_SUSPEND__BMASK    EQU 020H ; Oscillator Suspend Enable                        
OSCICN_SUSPEND__SHIFT    EQU 005H ; Oscillator Suspend Enable                        
OSCICN_SUSPEND__DISABLED EQU 000H ; The internal oscillator is not in suspend mode.  
OSCICN_SUSPEND__ENABLED  EQU 020H ; Place the internal oscillator in suspend mode.   
                                                                                     
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
EIE1_EUSB0__BMASK    EQU 002H ; USB (USB0) Interrupt Enable                 
EIE1_EUSB0__SHIFT    EQU 001H ; USB (USB0) Interrupt Enable                 
EIE1_EUSB0__DISABLED EQU 000H ; Disable all USB0 interrupts.                
EIE1_EUSB0__ENABLED  EQU 002H ; Enable interrupt requests generated by USB0.
                                                                            
;------------------------------------------------------------------------------
; EIE2 Enums (Extended Interrupt Enable 2 @ 0xE7)
;------------------------------------------------------------------------------
EIE2_EVBUS__BMASK    EQU 001H ; VBUS Level Interrupt Enable                      
EIE2_EVBUS__SHIFT    EQU 000H ; VBUS Level Interrupt Enable                      
EIE2_EVBUS__DISABLED EQU 000H ; Disable all VBUS interrupts.                     
EIE2_EVBUS__ENABLED  EQU 001H ; Enable interrupt requests generated by VBUS level
                              ; sense.                                           
                                                                                 
;------------------------------------------------------------------------------
; EIP1 Enums (Extended Interrupt Priority 1 @ 0xF6)
;------------------------------------------------------------------------------
EIP1_PUSB0__BMASK EQU 002H ; USB (USB0) Interrupt Priority Control     
EIP1_PUSB0__SHIFT EQU 001H ; USB (USB0) Interrupt Priority Control     
EIP1_PUSB0__LOW   EQU 000H ; USB0 interrupt set to low priority level. 
EIP1_PUSB0__HIGH  EQU 002H ; USB0 interrupt set to high priority level.
                                                                       
;------------------------------------------------------------------------------
; EIP2 Enums (Extended Interrupt Priority 2 @ 0xF7)
;------------------------------------------------------------------------------
EIP2_PVBUS__BMASK EQU 001H ; VBUS Level Interrupt Priority Control     
EIP2_PVBUS__SHIFT EQU 000H ; VBUS Level Interrupt Priority Control     
EIP2_PVBUS__LOW   EQU 000H ; VBUS interrupt set to low priority level. 
EIP2_PVBUS__HIGH  EQU 001H ; VBUS interrupt set to high priority level.
                                                                       
;------------------------------------------------------------------------------
; IE Enums (Interrupt Enable @ 0xA8)
;------------------------------------------------------------------------------
IE_EX0__BMASK    EQU 001H ; External Interrupt 0 Enable                      
IE_EX0__SHIFT    EQU 000H ; External Interrupt 0 Enable                      
IE_EX0__DISABLED EQU 000H ; Disable external interrupt 0.                    
IE_EX0__ENABLED  EQU 001H ; Enable interrupt requests generated by the /INT0 
                          ; input.                                           
                                                                             
IE_ET0__BMASK    EQU 002H ; Timer 0 Interrupt Enable                         
IE_ET0__SHIFT    EQU 001H ; Timer 0 Interrupt Enable                         
IE_ET0__DISABLED EQU 000H ; Disable all Timer 0 interrupt.                   
IE_ET0__ENABLED  EQU 002H ; Enable interrupt requests generated by the TF0   
                          ; flag.                                            
                                                                             
IE_EX1__BMASK    EQU 004H ; External Interrupt 1 Enable                      
IE_EX1__SHIFT    EQU 002H ; External Interrupt 1 Enable                      
IE_EX1__DISABLED EQU 000H ; Disable external interrupt 1.                    
IE_EX1__ENABLED  EQU 004H ; Enable interrupt requests generated by the /INT1 
                          ; input.                                           
                                                                             
IE_ET1__BMASK    EQU 008H ; Timer 1 Interrupt Enable                         
IE_ET1__SHIFT    EQU 003H ; Timer 1 Interrupt Enable                         
IE_ET1__DISABLED EQU 000H ; Disable all Timer 1 interrupt.                   
IE_ET1__ENABLED  EQU 008H ; Enable interrupt requests generated by the TF1   
                          ; flag.                                            
                                                                             
IE_ES0__BMASK    EQU 010H ; UART0 Interrupt Enable                           
IE_ES0__SHIFT    EQU 004H ; UART0 Interrupt Enable                           
IE_ES0__DISABLED EQU 000H ; Disable UART0 interrupt.                         
IE_ES0__ENABLED  EQU 010H ; Enable UART0 interrupt.                          
                                                                             
IE_EA__BMASK     EQU 080H ; All Interrupts Enable                            
IE_EA__SHIFT     EQU 007H ; All Interrupts Enable                            
IE_EA__DISABLED  EQU 000H ; Disable all interrupt sources.                   
IE_EA__ENABLED   EQU 080H ; Enable each interrupt according to its individual
                          ; mask setting.                                    
                                                                             
;------------------------------------------------------------------------------
; IP Enums (Interrupt Priority @ 0xB8)
;------------------------------------------------------------------------------
IP_PX0__BMASK EQU 001H ; External Interrupt 0 Priority Control           
IP_PX0__SHIFT EQU 000H ; External Interrupt 0 Priority Control           
IP_PX0__LOW   EQU 000H ; External Interrupt 0 set to low priority level. 
IP_PX0__HIGH  EQU 001H ; External Interrupt 0 set to high priority level.
                                                                         
IP_PT0__BMASK EQU 002H ; Timer 0 Interrupt Priority Control              
IP_PT0__SHIFT EQU 001H ; Timer 0 Interrupt Priority Control              
IP_PT0__LOW   EQU 000H ; Timer 0 interrupt set to low priority level.    
IP_PT0__HIGH  EQU 002H ; Timer 0 interrupt set to high priority level.   
                                                                         
IP_PX1__BMASK EQU 004H ; External Interrupt 1 Priority Control           
IP_PX1__SHIFT EQU 002H ; External Interrupt 1 Priority Control           
IP_PX1__LOW   EQU 000H ; External Interrupt 1 set to low priority level. 
IP_PX1__HIGH  EQU 004H ; External Interrupt 1 set to high priority level.
                                                                         
IP_PT1__BMASK EQU 008H ; Timer 1 Interrupt Priority Control              
IP_PT1__SHIFT EQU 003H ; Timer 1 Interrupt Priority Control              
IP_PT1__LOW   EQU 000H ; Timer 1 interrupt set to low priority level.    
IP_PT1__HIGH  EQU 008H ; Timer 1 interrupt set to high priority level.   
                                                                         
IP_PS0__BMASK EQU 010H ; UART0 Interrupt Priority Control                
IP_PS0__SHIFT EQU 004H ; UART0 Interrupt Priority Control                
IP_PS0__LOW   EQU 000H ; UART0 interrupt set to low priority level.      
IP_PS0__HIGH  EQU 010H ; UART0 interrupt set to high priority level.     
                                                                         
;------------------------------------------------------------------------------
; OSCLCN Enums (Internal Low Frequency Oscillator Control @ 0xE3)
;------------------------------------------------------------------------------
OSCLCN_OSCLEN__BMASK    EQU 080H ; Oscillator Enable                    
OSCLCN_OSCLEN__SHIFT    EQU 007H ; Oscillator Enable                    
OSCLCN_OSCLEN__DISABLED EQU 000H ; Disable the Low Frequency Oscillator.
OSCLCN_OSCLEN__ENABLED  EQU 080H ; Enable the Low Frequency Oscillator. 
                                                                        
;------------------------------------------------------------------------------
; GPIOCN Enums (Global Port I/O Control @ 0xE2)
;------------------------------------------------------------------------------
GPIOCN_SYSCKE__BMASK              EQU 001H ; SYSCLK Output Enable                              
GPIOCN_SYSCKE__SHIFT              EQU 000H ; SYSCLK Output Enable                              
GPIOCN_SYSCKE__DISABLED           EQU 000H ; SYSCLK unavailable at P0.0 pin. P0.0 latch routed 
                                           ; to P0.0 pin.                                      
GPIOCN_SYSCKE__ENABLED            EQU 001H ; SYSCLK routed to P0.0. P0.0 latch unavailable at  
                                           ; P0.0 pin.                                         
                                                                                               
GPIOCN_INPUTEN__BMASK             EQU 040H ; Global Digital Input Enable                       
GPIOCN_INPUTEN__SHIFT             EQU 006H ; Global Digital Input Enable                       
GPIOCN_INPUTEN__DISABLED          EQU 000H ; Port I/O input path disabled, and port pins can be
                                           ; used as outputs only.                             
GPIOCN_INPUTEN__ENABLED           EQU 040H ; Port I/O input path enabled.                      
                                                                                               
GPIOCN_WEAKPUD__BMASK             EQU 080H ; Port I/O Weak Pullup Disable                      
GPIOCN_WEAKPUD__SHIFT             EQU 007H ; Port I/O Weak Pullup Disable                      
GPIOCN_WEAKPUD__PULL_UPS_ENABLED  EQU 000H ; Weak Pullups enabled (except for I/O pins with    
                                           ; Port latches set to logic 0 or are configured to  
                                           ; push-pull mode).                                  
GPIOCN_WEAKPUD__PULL_UPS_DISABLED EQU 080H ; Weak Pullups disabled.                            
                                                                                               
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
                                                            
;------------------------------------------------------------------------------
; P3 Enums (Port 3 Pin Latch @ 0xB0)
;------------------------------------------------------------------------------
P3_B0__BMASK EQU 001H ; Port 3 Bit 0 Latch                            
P3_B0__SHIFT EQU 000H ; Port 3 Bit 0 Latch                            
P3_B0__LOW   EQU 000H ; P3.0 is low. Set P3.0 to drive low.           
P3_B0__HIGH  EQU 001H ; P3.0 is high. Set P3.0 to drive or float high.
                                                                      
;------------------------------------------------------------------------------
; P3MDOUT Enums (Port 3 Output Mode @ 0xA7)
;------------------------------------------------------------------------------
P3MDOUT_B0__BMASK      EQU 001H ; Port 3 Bit 0 Output Mode  
P3MDOUT_B0__SHIFT      EQU 000H ; Port 3 Bit 0 Output Mode  
P3MDOUT_B0__OPEN_DRAIN EQU 000H ; P3.0 output is open-drain.
P3MDOUT_B0__PUSH_PULL  EQU 001H ; P3.0 output is push-pull. 
                                                            
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
                                                                                                       
RSTSRC_SWRSF__BMASK    EQU 010H ; Software Reset Force and Flag                                        
RSTSRC_SWRSF__SHIFT    EQU 004H ; Software Reset Force and Flag                                        
RSTSRC_SWRSF__NOT_SET  EQU 000H ; A software reset did not occur.                                      
RSTSRC_SWRSF__SET      EQU 010H ; A software reset occurred.                                           
                                                                                                       
RSTSRC_FERROR__BMASK   EQU 040H ; Flash Error Reset Flag                                               
RSTSRC_FERROR__SHIFT   EQU 006H ; Flash Error Reset Flag                                               
RSTSRC_FERROR__NOT_SET EQU 000H ; A flash error reset did not occur.                                   
RSTSRC_FERROR__SET     EQU 040H ; A flash error reset occurred.                                        
                                                                                                       
RSTSRC_USBRSF__BMASK   EQU 080H ; USB Reset Enable and Flag                                            
RSTSRC_USBRSF__SHIFT   EQU 007H ; USB Reset Enable and Flag                                            
RSTSRC_USBRSF__NOT_SET EQU 000H ; A USB0 reset did not occur.                                          
RSTSRC_USBRSF__SET     EQU 080H ; A USB0 reset occurred.                                               
                                                                                                       
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
; CKCON Enums (Clock Control @ 0x8E)
;------------------------------------------------------------------------------
CKCON_SCA__FMASK         EQU 003H ; Timer 0/1 Prescale                            
CKCON_SCA__SHIFT         EQU 000H ; Timer 0/1 Prescale                            
CKCON_SCA__SYSCLK_DIV_12 EQU 000H ; System clock divided by 12.                   
CKCON_SCA__SYSCLK_DIV_4  EQU 001H ; System clock divided by 4.                    
CKCON_SCA__SYSCLK_DIV_48 EQU 002H ; System clock divided by 48.                   
                                                                                  
CKCON_T0M__BMASK         EQU 004H ; Timer 0 Clock Select                          
CKCON_T0M__SHIFT         EQU 002H ; Timer 0 Clock Select                          
CKCON_T0M__PRESCALE      EQU 000H ; Counter/Timer 0 uses the clock defined by the 
                                  ; prescale field, SCA.                          
CKCON_T0M__SYSCLK        EQU 004H ; Counter/Timer 0 uses the system clock.        
                                                                                  
CKCON_T1M__BMASK         EQU 008H ; Timer 1 Clock Select                          
CKCON_T1M__SHIFT         EQU 003H ; Timer 1 Clock Select                          
CKCON_T1M__PRESCALE      EQU 000H ; Timer 1 uses the clock defined by the prescale
                                  ; field, SCA.                                   
CKCON_T1M__SYSCLK        EQU 008H ; Timer 1 uses the system clock.                
                                                                                  
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
                                                                                  
TMOD_GATE1__BMASK    EQU 080H ; Timer 1 Gate Control                              
TMOD_GATE1__SHIFT    EQU 007H ; Timer 1 Gate Control                              
TMOD_GATE1__DISABLED EQU 000H ; Timer 1 enabled when TR1 = 1 irrespective of /INT1
                              ; logic level.                                      
TMOD_GATE1__ENABLED  EQU 080H ; Timer 1 enabled only when TR1 = 1 and /INT1 is    
                              ; active as defined by bit IN1PL in register IT01CF.
                                                                                  
;------------------------------------------------------------------------------
; SBCON0 Enums (UART0 Baud Rate Generator Control @ 0x91)
;------------------------------------------------------------------------------
SBCON0_SBPS__FMASK     EQU 003H ; Baud Rate Prescaler Select                        
SBCON0_SBPS__SHIFT     EQU 000H ; Baud Rate Prescaler Select                        
SBCON0_SBPS__DIV_BY_12 EQU 000H ; Prescaler = 12.                                   
SBCON0_SBPS__DIV_BY_4  EQU 001H ; Prescaler = 4.                                    
SBCON0_SBPS__DIV_BY_48 EQU 002H ; Prescaler = 48.                                   
SBCON0_SBPS__DIV_BY_1  EQU 003H ; Prescaler = 1.                                    
                                                                                    
SBCON0_SBRUN__BMASK    EQU 040H ; Baud Rate Generator Enable                        
SBCON0_SBRUN__SHIFT    EQU 006H ; Baud Rate Generator Enable                        
SBCON0_SBRUN__DISABLED EQU 000H ; Disable the baud rate generator. UART0 will not   
                                ; function.                                         
SBCON0_SBRUN__ENABLED  EQU 040H ; Enable the baud rate generator.                   
                                                                                    
SBCON0_SBCLK__BMASK    EQU 080H ; Baud Rate Generator Clock Source                  
SBCON0_SBCLK__SHIFT    EQU 007H ; Baud Rate Generator Clock Source                  
SBCON0_SBCLK__SYSCLK   EQU 000H ; The system clock (SYSCLK) is used as the baud rate
                                ; generator clock source.                           
SBCON0_SBCLK__USBCLK   EQU 080H ; The USB clock (USBCLK) is used as the baud rate   
                                ; generator clock source.                           
                                                                                    
;------------------------------------------------------------------------------
; SBRLH0 Enums (UART0 Baud Rate Generator High Byte @ 0x94)
;------------------------------------------------------------------------------
SBRLH0_SBRL__FMASK EQU 0FFH ; UART0 Baud Rate Reload High
SBRLH0_SBRL__SHIFT EQU 000H ; UART0 Baud Rate Reload High
                                                         
;------------------------------------------------------------------------------
; SBRLL0 Enums (UART0 Baud Rate Generator Low Byte @ 0x93)
;------------------------------------------------------------------------------
SBRLL0_SBRL__FMASK EQU 0FFH ; UART0 Baud Rate Reload Low
SBRLL0_SBRL__SHIFT EQU 000H ; UART0 Baud Rate Reload Low
                                                        
;------------------------------------------------------------------------------
; SBUF0 Enums (UART0 Serial Port Data Buffer @ 0x99)
;------------------------------------------------------------------------------
SBUF0_SBUF0__FMASK EQU 0FFH ; Serial Port Data Buffer
SBUF0_SBUF0__SHIFT EQU 000H ; Serial Port Data Buffer
                                                     
;------------------------------------------------------------------------------
; SCON0 Enums (UART0 Serial Port Control @ 0x98)
;------------------------------------------------------------------------------
SCON0_RI__BMASK             EQU 001H ; Receive Interrupt Flag                           
SCON0_RI__SHIFT             EQU 000H ; Receive Interrupt Flag                           
SCON0_RI__NOT_SET           EQU 000H ; A byte of data has not been received by UART0.   
SCON0_RI__SET               EQU 001H ; UART0 received a byte of data or data remains in 
                                     ; the receive FIFO.                                
                                                                                        
SCON0_TI__BMASK             EQU 002H ; Transmit Interrupt Flag                          
SCON0_TI__SHIFT             EQU 001H ; Transmit Interrupt Flag                          
SCON0_TI__NOT_SET           EQU 000H ; A byte of data has not been transmitted by UART0.
SCON0_TI__SET               EQU 002H ; UART0 transmitted a byte of data.                
                                                                                        
SCON0_RBX__BMASK            EQU 004H ; Extra Receive Bit                                
SCON0_RBX__SHIFT            EQU 002H ; Extra Receive Bit                                
SCON0_RBX__LOW              EQU 000H ; The extra bit or the first stop bit is 0.        
SCON0_RBX__HIGH             EQU 004H ; The extra bit or the first stop bit is 1.        
                                                                                        
SCON0_TBX__BMASK            EQU 008H ; Extra Transmission Bit                           
SCON0_TBX__SHIFT            EQU 003H ; Extra Transmission Bit                           
SCON0_TBX__LOW              EQU 000H ; Set extra bit to 0 (low).                        
SCON0_TBX__HIGH             EQU 008H ; Set extra bit to 1 (high).                       
                                                                                        
SCON0_REN__BMASK            EQU 010H ; Receive Enable                                   
SCON0_REN__SHIFT            EQU 004H ; Receive Enable                                   
SCON0_REN__RECEIVE_DISABLED EQU 000H ; UART0 reception disabled.                        
SCON0_REN__RECEIVE_ENABLED  EQU 010H ; UART0 reception enabled.                         
                                                                                        
SCON0_PERR__BMASK           EQU 040H ; Parity Error Flag                                
SCON0_PERR__SHIFT           EQU 006H ; Parity Error Flag                                
SCON0_PERR__NOT_SET         EQU 000H ; Parity error has not occurred.                   
SCON0_PERR__SET             EQU 040H ; Parity error has occurred.                       
                                                                                        
SCON0_OVR__BMASK            EQU 080H ; Receive FIFO Overrun Flag                        
SCON0_OVR__SHIFT            EQU 007H ; Receive FIFO Overrun Flag                        
SCON0_OVR__NOT_SET          EQU 000H ; Receive FIFO overrun has not occurred.           
SCON0_OVR__SET              EQU 080H ; Receive FIFO overrun has occurred.               
                                                                                        
;------------------------------------------------------------------------------
; SMOD0 Enums (UART0 Mode @ 0x9A)
;------------------------------------------------------------------------------
SMOD0_SBL__BMASK          EQU 001H ; Stop Bit Length                                 
SMOD0_SBL__SHIFT          EQU 000H ; Stop Bit Length                                 
SMOD0_SBL__SHORT          EQU 000H ; Short: Stop bit is active for one bit time.     
SMOD0_SBL__LONG           EQU 001H ; Long: Stop bit is active for two bit times (data
                                   ; length = 6, 7, or 8 bits) or 1.5 bit times (data
                                   ; length = 5 bits).                               
                                                                                     
SMOD0_XBE__BMASK          EQU 002H ; Extra Bit Enable                                
SMOD0_XBE__SHIFT          EQU 001H ; Extra Bit Enable                                
SMOD0_XBE__DISABLED       EQU 000H ; Disable the extra bit.                          
SMOD0_XBE__ENABLED        EQU 002H ; Enable the extra bit.                           
                                                                                     
SMOD0_SDL__FMASK          EQU 00CH ; Data Length                                     
SMOD0_SDL__SHIFT          EQU 002H ; Data Length                                     
SMOD0_SDL__5_BITS         EQU 000H ; 5 bits.                                         
SMOD0_SDL__6_BITS         EQU 004H ; 6 bits.                                         
SMOD0_SDL__7_BITS         EQU 008H ; 7 bits.                                         
SMOD0_SDL__8_BITS         EQU 00CH ; 8 bits.                                         
                                                                                     
SMOD0_PE__BMASK           EQU 010H ; Parity Enable                                   
SMOD0_PE__SHIFT           EQU 004H ; Parity Enable                                   
SMOD0_PE__PARITY_DISABLED EQU 000H ; Disable hardware parity.                        
SMOD0_PE__PARITY_ENABLED  EQU 010H ; Enable hardware parity.                         
                                                                                     
SMOD0_SPT__FMASK          EQU 060H ; Parity Type                                     
SMOD0_SPT__SHIFT          EQU 005H ; Parity Type                                     
SMOD0_SPT__ODD_PARTY      EQU 000H ; Odd.                                            
SMOD0_SPT__EVEN_PARITY    EQU 020H ; Even.                                           
SMOD0_SPT__MARK_PARITY    EQU 040H ; Mark.                                           
SMOD0_SPT__SPACE_PARITY   EQU 060H ; Space.                                          
                                                                                     
SMOD0_MCE__BMASK          EQU 080H ; Multiprocessor Communication Enable             
SMOD0_MCE__SHIFT          EQU 007H ; Multiprocessor Communication Enable             
SMOD0_MCE__MULTI_DISABLED EQU 000H ; RI will be activated if the stop bits are 1.    
SMOD0_MCE__MULTI_ENABLED  EQU 080H ; RI will be activated if the stop bits and extra 
                                   ; bit are 1. The extra bit must be enabled using  
                                   ; XBE.                                            
                                                                                     
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
; EINCSRH Enums (USB0 IN Endpoint Control High @ 0x12)
;------------------------------------------------------------------------------
EINCSRH_FCDT__BMASK         EQU 008H ; Force Data Toggle                                
EINCSRH_FCDT__SHIFT         EQU 003H ; Force Data Toggle                                
EINCSRH_FCDT__ACK_TOGGLE    EQU 000H ; Endpoint data toggle switches only when an ACK is
                                     ; received following a data packet transmission.   
EINCSRH_FCDT__ALWAYS_TOGGLE EQU 008H ; Endpoint data toggle forced to switch after every
                                     ; data packet is transmitted, regardless of ACK    
                                     ; reception.                                       
                                                                                        
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
                                                                
;------------------------------------------------------------------------------
; INDEX Enums (USB0 Endpoint Index @ 0x0E)
;------------------------------------------------------------------------------
INDEX_EPSEL__FMASK      EQU 00FH ; Endpoint Select Bits
INDEX_EPSEL__SHIFT      EQU 000H ; Endpoint Select Bits
INDEX_EPSEL__ENDPOINT_0 EQU 000H ; Endpoint 0.         
INDEX_EPSEL__ENDPOINT_1 EQU 001H ; Endpoint 1.         
                                                       
;------------------------------------------------------------------------------
; OUT1IE Enums (USB0 OUT Endpoint Interrupt Enable @ 0x09)
;------------------------------------------------------------------------------
OUT1IE_OUT1E__BMASK    EQU 002H ; OUT Endpoint 1 Interrupt Enable   
OUT1IE_OUT1E__SHIFT    EQU 001H ; OUT Endpoint 1 Interrupt Enable   
OUT1IE_OUT1E__DISABLED EQU 000H ; Disable Endpoint 1 OUT interrupts.
OUT1IE_OUT1E__ENABLED  EQU 002H ; Enable Endpoint 1 OUT interrupts. 
                                                                    
;------------------------------------------------------------------------------
; OUT1INT Enums (USB0 OUT Endpoint Interrupt @ 0x04)
;------------------------------------------------------------------------------
OUT1INT_OUT1__BMASK   EQU 002H ; OUT Endpoint 1 Interrupt Flag     
OUT1INT_OUT1__SHIFT   EQU 001H ; OUT Endpoint 1 Interrupt Flag     
OUT1INT_OUT1__NOT_SET EQU 000H ; OUT Endpoint 1 interrupt inactive.
OUT1INT_OUT1__SET     EQU 002H ; OUT Endpoint 1 interrupt active.  
                                                                   
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
; USB0ADR Enums (USB0 Indirect Address @ 0x96)
;------------------------------------------------------------------------------
USB0ADR_USBADDR__FMASK          EQU 03FH ; USB0 Indirect Register Address                    
USB0ADR_USBADDR__SHIFT          EQU 000H ; USB0 Indirect Register Address                    
USB0ADR_USBADDR__FADDR          EQU 000H ; Function Address.                                 
USB0ADR_USBADDR__POWER          EQU 001H ; Power Management.                                 
USB0ADR_USBADDR__IN1INT         EQU 002H ; Endpoint 0 and Endpoints 1-3 IN Interrupt Flags.  
USB0ADR_USBADDR__OUT1INT        EQU 004H ; Endpoints 1-3 OUT Interrupt Flags.                
USB0ADR_USBADDR__CMINT          EQU 006H ; Common USB Interrupt Flags.                       
USB0ADR_USBADDR__IN1IE          EQU 007H ; Endpoint 0 and Endpoints 1-3 IN Interrupt Enables.
USB0ADR_USBADDR__OUT1IE         EQU 009H ; Endpoints 1-3 OUT Interrupt Enables.              
USB0ADR_USBADDR__CMIE           EQU 00BH ; Common USB Interrupt Enables.                     
USB0ADR_USBADDR__FRAMEL         EQU 00CH ; Frame Number Low Byte.                            
USB0ADR_USBADDR__FRAMEH         EQU 00DH ; Frame Number High Byte.                           
USB0ADR_USBADDR__INDEX          EQU 00EH ; Endpoint Index Selection.                         
USB0ADR_USBADDR__CLKREC         EQU 00FH ; Clock Recovery Control.                           
USB0ADR_USBADDR__E0CSR_EINCSRL  EQU 011H ; Endpoint 0 Control / Status, Endpoint IN Control /
                                         ; Status Low Byte.                                  
USB0ADR_USBADDR__EINCSRH        EQU 012H ; Endpoint IN Control / Status High Byte.           
USB0ADR_USBADDR__EOUTCSRL       EQU 014H ; Endpoint OUT Control / Status Low Byte.           
USB0ADR_USBADDR__EOUTCSRH       EQU 015H ; Endpoint OUT Control / Status High Byte.          
USB0ADR_USBADDR__E0CNT_EOUTCNTL EQU 016H ; Number of Received Bytes in Endpoint 0 FIFO,      
                                         ; Endpoint OUT Packet Count Low Byte.               
USB0ADR_USBADDR__EOUTCNTH       EQU 017H ; Endpoint OUT Packet Count High Byte.              
USB0ADR_USBADDR__EENABLE        EQU 01EH ; Endpoint Enable.                                  
USB0ADR_USBADDR__FIFO0          EQU 020H ; Endpoint 0 FIFO.                                  
USB0ADR_USBADDR__FIFO1          EQU 021H ; Endpoint 1 FIFO.                                  
                                                                                             
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
; USB0DAT Enums (USB0 Data @ 0x97)
;------------------------------------------------------------------------------
USB0DAT_USB0DAT__FMASK EQU 0FFH ; USB0 Data
USB0DAT_USB0DAT__SHIFT EQU 000H ; USB0 Data
                                           
;------------------------------------------------------------------------------
; USB0XCN Enums (USB0 Transceiver Control @ 0xD7)
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
; VDM0CN Enums (VDD Supply Monitor Control @ 0xFF)
;------------------------------------------------------------------------------
VDM0CN_VDDSTAT__BMASK     EQU 040H ; VDD Status                                   
VDM0CN_VDDSTAT__SHIFT     EQU 006H ; VDD Status                                   
VDM0CN_VDDSTAT__VDD_BELOW EQU 000H ; VDD is at or below the VDD monitor threshold.
VDM0CN_VDDSTAT__VDD_ABOVE EQU 040H ; VDD is above the VDD monitor threshold.      
                                                                                  
VDM0CN_VDMEN__BMASK       EQU 080H ; VDD Monitor Enable                           
VDM0CN_VDMEN__SHIFT       EQU 007H ; VDD Monitor Enable                           
VDM0CN_VDMEN__DISABLED    EQU 000H ; Disable the VDD Monitor.                     
VDM0CN_VDMEN__ENABLED     EQU 080H ; Enable the VDD Monitor.                      
                                                                                  
;------------------------------------------------------------------------------
; REG0CN Enums (Voltage Regulator Control @ 0xC9)
;------------------------------------------------------------------------------
REG0CN_REG0MD__BMASK     EQU 010H ; VREG0 Voltage Regulator Mode                     
REG0CN_REG0MD__SHIFT     EQU 004H ; VREG0 Voltage Regulator Mode                     
REG0CN_REG0MD__NORMAL    EQU 000H ; VREG0 Voltage Regulator in normal mode.          
REG0CN_REG0MD__LOW_POWER EQU 010H ; VREG0 Voltage Regulator in low power mode.       
                                                                                     
REG0CN_VBPOL__BMASK      EQU 020H ; VBUS Interrupt Polarity Select                   
REG0CN_VBPOL__SHIFT      EQU 005H ; VBUS Interrupt Polarity Select                   
REG0CN_VBPOL__LOW        EQU 000H ; VBUS interrupt active when VBUS is low.          
REG0CN_VBPOL__HIGH       EQU 020H ; VBUS interrupt active when VBUS is high.         
                                                                                     
REG0CN_VBSTAT__BMASK     EQU 040H ; VBUS Signal Status                               
REG0CN_VBSTAT__SHIFT     EQU 006H ; VBUS Signal Status                               
REG0CN_VBSTAT__NOT_SET   EQU 000H ; VBUS signal currently absent (device not attached
                                  ; to USB network).                                 
REG0CN_VBSTAT__SET       EQU 040H ; VBUS signal currently present (device attached to
                                  ; USB network).                                    
                                                                                     
REG0CN_REG0DIS__BMASK    EQU 080H ; Voltage Regulator (REG0) Disable                 
REG0CN_REG0DIS__SHIFT    EQU 007H ; Voltage Regulator (REG0) Disable                 
REG0CN_REG0DIS__ENABLED  EQU 000H ; Enable the VREG0 Voltage Regulator.              
REG0CN_REG0DIS__DISABLED EQU 080H ; Disable the VREG0 Voltage Regulator.             
                                                                                     
;------------------------------------------------------------------------------
; EMI0CN Enums (External Memory Interface Control @ 0xAA)
;------------------------------------------------------------------------------
EMI0CN_PGSEL__FMASK EQU 003H ; XRAM Page Select
EMI0CN_PGSEL__SHIFT EQU 000H ; XRAM Page Select
                                               
