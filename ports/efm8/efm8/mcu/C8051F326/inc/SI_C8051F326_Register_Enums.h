//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  C8051F326_GM
//  C8051F327_GM

#ifndef SI_C8051F326_REGISTER_ENUMS_H
#define SI_C8051F326_REGISTER_ENUMS_H

//Standard device includes
#include "SI_C8051F326_Defs.h"
//------------------------------------------------------------------------------
// ACC Enums (Accumulator @ 0xE0)
//------------------------------------------------------------------------------
#define ACC_ACC__FMASK 0xFF ///< Accumulator
#define ACC_ACC__SHIFT 0x00 ///< Accumulator
                                            
//------------------------------------------------------------------------------
// B Enums (B Register @ 0xF0)
//------------------------------------------------------------------------------
#define B_B__FMASK 0xFF ///< B Register
#define B_B__SHIFT 0x00 ///< B Register
                                       
//------------------------------------------------------------------------------
// DPH Enums (Data Pointer High @ 0x83)
//------------------------------------------------------------------------------
#define DPH_DPH__FMASK 0xFF ///< Data Pointer High
#define DPH_DPH__SHIFT 0x00 ///< Data Pointer High
                                                  
//------------------------------------------------------------------------------
// DPL Enums (Data Pointer Low @ 0x82)
//------------------------------------------------------------------------------
#define DPL_DPL__FMASK 0xFF ///< Data Pointer Low
#define DPL_DPL__SHIFT 0x00 ///< Data Pointer Low
                                                 
//------------------------------------------------------------------------------
// PSW Enums (Program Status Word @ 0xD0)
//------------------------------------------------------------------------------
#define PSW_PARITY__BMASK   0x01 ///< Parity Flag                                       
#define PSW_PARITY__SHIFT   0x00 ///< Parity Flag                                       
#define PSW_PARITY__NOT_SET 0x00 ///< The sum of the 8 bits in the accumulator is even. 
#define PSW_PARITY__SET     0x01 ///< The sum of the 8 bits in the accumulator is odd.  
                                                                                        
#define PSW_F1__BMASK       0x02 ///< User Flag 1                                       
#define PSW_F1__SHIFT       0x01 ///< User Flag 1                                       
#define PSW_F1__NOT_SET     0x00 ///< Flag is not set.                                  
#define PSW_F1__SET         0x02 ///< Flag is set.                                      
                                                                                        
#define PSW_OV__BMASK       0x04 ///< Overflow Flag                                     
#define PSW_OV__SHIFT       0x02 ///< Overflow Flag                                     
#define PSW_OV__NOT_SET     0x00 ///< An overflow did not occur.                        
#define PSW_OV__SET         0x04 ///< An overflow occurred.                             
                                                                                        
#define PSW_RS__FMASK       0x18 ///< Register Bank Select                              
#define PSW_RS__SHIFT       0x03 ///< Register Bank Select                              
#define PSW_RS__BANK0       0x00 ///< Bank 0, Addresses 0x00-0x07                       
#define PSW_RS__BANK1       0x08 ///< Bank 1, Addresses 0x08-0x0F                       
#define PSW_RS__BANK2       0x10 ///< Bank 2, Addresses 0x10-0x17                       
#define PSW_RS__BANK3       0x18 ///< Bank 3, Addresses 0x18-0x1F                       
                                                                                        
#define PSW_F0__BMASK       0x20 ///< User Flag 0                                       
#define PSW_F0__SHIFT       0x05 ///< User Flag 0                                       
#define PSW_F0__NOT_SET     0x00 ///< Flag is not set.                                  
#define PSW_F0__SET         0x20 ///< Flag is set.                                      
                                                                                        
#define PSW_AC__BMASK       0x40 ///< Auxiliary Carry Flag                              
#define PSW_AC__SHIFT       0x06 ///< Auxiliary Carry Flag                              
#define PSW_AC__NOT_SET     0x00 ///< A carry into (addition) or borrow from            
                                 ///< (subtraction) the high order nibble did not occur.
#define PSW_AC__SET         0x40 ///< A carry into (addition) or borrow from            
                                 ///< (subtraction) the high order nibble occurred.     
                                                                                        
#define PSW_CY__BMASK       0x80 ///< Carry Flag                                        
#define PSW_CY__SHIFT       0x07 ///< Carry Flag                                        
#define PSW_CY__NOT_SET     0x00 ///< A carry (addition) or borrow (subtraction) did not
                                 ///< occur.                                            
#define PSW_CY__SET         0x80 ///< A carry (addition) or borrow (subtraction)        
                                 ///< occurred.                                         
                                                                                        
//------------------------------------------------------------------------------
// SP Enums (Stack Pointer @ 0x81)
//------------------------------------------------------------------------------
#define SP_SP__FMASK 0xFF ///< Stack Pointer
#define SP_SP__SHIFT 0x00 ///< Stack Pointer
                                            
//------------------------------------------------------------------------------
// CLKMUL Enums (Clock Multiplier Control @ 0xB9)
//------------------------------------------------------------------------------
#define CLKMUL_MULSEL__BMASK    0x01 ///< Clock Multiplier Input Select             
#define CLKMUL_MULSEL__SHIFT    0x00 ///< Clock Multiplier Input Select             
#define CLKMUL_MULSEL__HFOSC    0x00 ///< Clock Multiplier input clock source is the
                                     ///< Internal High-Frequency Oscillator.       
#define CLKMUL_MULSEL__EXTOSC   0x01 ///< Clock Multiplier input clock source is the
                                     ///< External Oscillator.                      
                                                                                    
#define CLKMUL_MULRDY__BMASK    0x20 ///< Clock Multiplier Ready                    
#define CLKMUL_MULRDY__SHIFT    0x05 ///< Clock Multiplier Ready                    
#define CLKMUL_MULRDY__NOT_SET  0x00 ///< Clock Multiplier not ready.               
#define CLKMUL_MULRDY__SET      0x20 ///< Clock Multiplier is ready (locked).       
                                                                                    
#define CLKMUL_MULINIT__BMASK   0x40 ///< Clock Multiplier Initialize               
#define CLKMUL_MULINIT__SHIFT   0x06 ///< Clock Multiplier Initialize               
#define CLKMUL_MULINIT__NOT_SET 0x00 ///< Do not initialize the Clock Multiplier.   
#define CLKMUL_MULINIT__SET     0x40 ///< Initialize the Clock Multiplier.          
                                                                                    
#define CLKMUL_MULEN__BMASK     0x80 ///< Clock Multiplier Enable                   
#define CLKMUL_MULEN__SHIFT     0x07 ///< Clock Multiplier Enable                   
#define CLKMUL_MULEN__DISABLED  0x00 ///< Disable the Clock Multiplier.             
#define CLKMUL_MULEN__ENABLED   0x80 ///< Enable the Clock Multiplier.              
                                                                                    
//------------------------------------------------------------------------------
// CLKSEL Enums (Clock Select @ 0xA9)
//------------------------------------------------------------------------------
#define CLKSEL_CLKSL__FMASK         0x07 ///< System Clock Source Select Bits                   
#define CLKSEL_CLKSL__SHIFT         0x00 ///< System Clock Source Select Bits                   
#define CLKSEL_CLKSL__DIVIDED_HFOSC 0x00 ///< Clock (SYSCLK) derived from the Internal High-    
                                         ///< Frequency Oscillator and scaled per the IFCN bits 
                                         ///< in register OSCICN.                               
#define CLKSEL_CLKSL__EXTOSC        0x01 ///< Clock (SYSCLK) derived from the External          
                                         ///< Oscillator circuit.                               
#define CLKSEL_CLKSL__CLKMUL_DIV_2  0x02 ///< Clock (SYSCLK) derived from the 4x Clock          
                                         ///< Multiplier / 2.                                   
#define CLKSEL_CLKSL__LFOSC         0x03 ///< Clock (SYSCLK) derived from the Internal Low-     
                                         ///< Frequency Oscillator.                             
                                                                                                
#define CLKSEL_USBCLK__FMASK        0x30 ///< USB Clock Source Select Bits                      
#define CLKSEL_USBCLK__SHIFT        0x04 ///< USB Clock Source Select Bits                      
#define CLKSEL_USBCLK__CLKMUL       0x00 ///< USB clock (USBCLK) derived from the 4x Clock      
                                         ///< Multiplier.                                       
#define CLKSEL_USBCLK__HFOSC_DIV_2  0x10 ///< USB clock (USBCLK) derived from the Internal High-
                                         ///< Frequency Oscillator / 2.                         
#define CLKSEL_USBCLK__EXTOSC       0x20 ///< USB clock (USBCLK) derived from the External      
                                         ///< Oscillator.                                       
#define CLKSEL_USBCLK__OFF          0x30 ///< USB clock (USBCLK) off.                           
                                                                                                
//------------------------------------------------------------------------------
// FLKEY Enums (Flash Lock and Key @ 0xB7)
//------------------------------------------------------------------------------
#define FLKEY_FLKEY__FMASK    0xFF ///< Flash Lock and Key Register                       
#define FLKEY_FLKEY__SHIFT    0x00 ///< Flash Lock and Key Register                       
#define FLKEY_FLKEY__LOCKED   0x00 ///< Flash is write/erase locked.                      
#define FLKEY_FLKEY__FIRST    0x01 ///< The first key code has been written (0xA5).       
#define FLKEY_FLKEY__UNLOCKED 0x02 ///< Flash is unlocked (writes/erases allowed).        
#define FLKEY_FLKEY__DISABLED 0x03 ///< Flash writes/erases disabled until the next reset.
#define FLKEY_FLKEY__KEY1     0xA5 ///< Flash writes and erases are enabled by writing    
                                   ///< 0xA5 followed by 0xF1 to the FLKEY register.      
#define FLKEY_FLKEY__KEY2     0xF1 ///< Flash writes and erases are enabled by writing    
                                   ///< 0xA5 followed by 0xF1 to the FLKEY register.      
                                                                                          
//------------------------------------------------------------------------------
// FLSCL Enums (Flash Scale @ 0xB6)
//------------------------------------------------------------------------------
#define FLSCL_FOSE__BMASK    0x80 ///< Flash One-Shot Enable                   
#define FLSCL_FOSE__SHIFT    0x07 ///< Flash One-Shot Enable                   
#define FLSCL_FOSE__DISABLED 0x00 ///< Disable the flash one-shot.             
#define FLSCL_FOSE__ENABLED  0x80 ///< Enable the flash one-shot (recommended).
                                                                               
//------------------------------------------------------------------------------
// PSCTL Enums (Program Store Control @ 0x8F)
//------------------------------------------------------------------------------
#define PSCTL_PSWE__BMASK          0x01 ///< Program Store Write Enable                      
#define PSCTL_PSWE__SHIFT          0x00 ///< Program Store Write Enable                      
#define PSCTL_PSWE__WRITE_DISABLED 0x00 ///< Writes to flash program memory disabled.        
#define PSCTL_PSWE__WRITE_ENABLED  0x01 ///< Writes to flash program memory enabled; the MOVX
                                        ///< write instruction targets flash memory.         
                                                                                             
#define PSCTL_PSEE__BMASK          0x02 ///< Program Store Erase Enable                      
#define PSCTL_PSEE__SHIFT          0x01 ///< Program Store Erase Enable                      
#define PSCTL_PSEE__ERASE_DISABLED 0x00 ///< Flash program memory erasure disabled.          
#define PSCTL_PSEE__ERASE_ENABLED  0x02 ///< Flash program memory erasure enabled.           
                                                                                             
//------------------------------------------------------------------------------
// OSCICL Enums (High Frequency Oscillator Calibration @ 0xB3)
//------------------------------------------------------------------------------
#define OSCICL_OSCICL__FMASK 0x1F ///< Internal Oscillator Calibration
#define OSCICL_OSCICL__SHIFT 0x00 ///< Internal Oscillator Calibration
                                                                      
//------------------------------------------------------------------------------
// OSCICN Enums (High Frequency Oscillator Control @ 0xB2)
//------------------------------------------------------------------------------
#define OSCICN_IFCN__FMASK       0x03 ///< Oscillator Frequency Divider Control             
#define OSCICN_IFCN__SHIFT       0x00 ///< Oscillator Frequency Divider Control             
#define OSCICN_IFCN__HFOSC_DIV_8 0x00 ///< SYSCLK derived from High Frequency Oscillator    
                                      ///< divided by 8.                                    
#define OSCICN_IFCN__HFOSC_DIV_4 0x01 ///< SYSCLK derived from High Frequency Oscillator    
                                      ///< divided by 4.                                    
#define OSCICN_IFCN__HFOSC_DIV_2 0x02 ///< SYSCLK derived from High Frequency Oscillator    
                                      ///< divided by 2.                                    
#define OSCICN_IFCN__HFOSC_DIV_1 0x03 ///< SYSCLK derived from High Frequency Oscillator    
                                      ///< divided by 1.                                    
                                                                                            
#define OSCICN_SUSPEND__BMASK    0x20 ///< Oscillator Suspend Enable                        
#define OSCICN_SUSPEND__SHIFT    0x05 ///< Oscillator Suspend Enable                        
#define OSCICN_SUSPEND__DISABLED 0x00 ///< The internal oscillator is not in suspend mode.  
#define OSCICN_SUSPEND__ENABLED  0x20 ///< Place the internal oscillator in suspend mode.   
                                                                                            
#define OSCICN_IFRDY__BMASK      0x40 ///< Oscillator Frequency Ready Flag                  
#define OSCICN_IFRDY__SHIFT      0x06 ///< Oscillator Frequency Ready Flag                  
#define OSCICN_IFRDY__NOT_SET    0x00 ///< The Internal High Frequency Oscillator is not    
                                      ///< running at the programmed frequency.             
#define OSCICN_IFRDY__SET        0x40 ///< The Internal High Frequency Oscillator is running
                                      ///< at the programmed frequency.                     
                                                                                            
#define OSCICN_IOSCEN__BMASK     0x80 ///< Oscillator Enable                                
#define OSCICN_IOSCEN__SHIFT     0x07 ///< Oscillator Enable                                
#define OSCICN_IOSCEN__DISABLED  0x00 ///< Disable the High Frequency Oscillator.           
#define OSCICN_IOSCEN__ENABLED   0x80 ///< Enable the High Frequency Oscillator.            
                                                                                            
//------------------------------------------------------------------------------
// EIE1 Enums (Extended Interrupt Enable 1 @ 0xE6)
//------------------------------------------------------------------------------
#define EIE1_EUSB0__BMASK    0x02 ///< USB (USB0) Interrupt Enable                 
#define EIE1_EUSB0__SHIFT    0x01 ///< USB (USB0) Interrupt Enable                 
#define EIE1_EUSB0__DISABLED 0x00 ///< Disable all USB0 interrupts.                
#define EIE1_EUSB0__ENABLED  0x02 ///< Enable interrupt requests generated by USB0.
                                                                                   
//------------------------------------------------------------------------------
// EIE2 Enums (Extended Interrupt Enable 2 @ 0xE7)
//------------------------------------------------------------------------------
#define EIE2_EVBUS__BMASK    0x01 ///< VBUS Level Interrupt Enable                      
#define EIE2_EVBUS__SHIFT    0x00 ///< VBUS Level Interrupt Enable                      
#define EIE2_EVBUS__DISABLED 0x00 ///< Disable all VBUS interrupts.                     
#define EIE2_EVBUS__ENABLED  0x01 ///< Enable interrupt requests generated by VBUS level
                                  ///< sense.                                           
                                                                                        
//------------------------------------------------------------------------------
// EIP1 Enums (Extended Interrupt Priority 1 @ 0xF6)
//------------------------------------------------------------------------------
#define EIP1_PUSB0__BMASK 0x02 ///< USB (USB0) Interrupt Priority Control     
#define EIP1_PUSB0__SHIFT 0x01 ///< USB (USB0) Interrupt Priority Control     
#define EIP1_PUSB0__LOW   0x00 ///< USB0 interrupt set to low priority level. 
#define EIP1_PUSB0__HIGH  0x02 ///< USB0 interrupt set to high priority level.
                                                                              
//------------------------------------------------------------------------------
// EIP2 Enums (Extended Interrupt Priority 2 @ 0xF7)
//------------------------------------------------------------------------------
#define EIP2_PVBUS__BMASK 0x01 ///< VBUS Level Interrupt Priority Control     
#define EIP2_PVBUS__SHIFT 0x00 ///< VBUS Level Interrupt Priority Control     
#define EIP2_PVBUS__LOW   0x00 ///< VBUS interrupt set to low priority level. 
#define EIP2_PVBUS__HIGH  0x01 ///< VBUS interrupt set to high priority level.
                                                                              
//------------------------------------------------------------------------------
// IE Enums (Interrupt Enable @ 0xA8)
//------------------------------------------------------------------------------
#define IE_EX0__BMASK    0x01 ///< External Interrupt 0 Enable                      
#define IE_EX0__SHIFT    0x00 ///< External Interrupt 0 Enable                      
#define IE_EX0__DISABLED 0x00 ///< Disable external interrupt 0.                    
#define IE_EX0__ENABLED  0x01 ///< Enable interrupt requests generated by the /INT0 
                              ///< input.                                           
                                                                                    
#define IE_ET0__BMASK    0x02 ///< Timer 0 Interrupt Enable                         
#define IE_ET0__SHIFT    0x01 ///< Timer 0 Interrupt Enable                         
#define IE_ET0__DISABLED 0x00 ///< Disable all Timer 0 interrupt.                   
#define IE_ET0__ENABLED  0x02 ///< Enable interrupt requests generated by the TF0   
                              ///< flag.                                            
                                                                                    
#define IE_EX1__BMASK    0x04 ///< External Interrupt 1 Enable                      
#define IE_EX1__SHIFT    0x02 ///< External Interrupt 1 Enable                      
#define IE_EX1__DISABLED 0x00 ///< Disable external interrupt 1.                    
#define IE_EX1__ENABLED  0x04 ///< Enable interrupt requests generated by the /INT1 
                              ///< input.                                           
                                                                                    
#define IE_ET1__BMASK    0x08 ///< Timer 1 Interrupt Enable                         
#define IE_ET1__SHIFT    0x03 ///< Timer 1 Interrupt Enable                         
#define IE_ET1__DISABLED 0x00 ///< Disable all Timer 1 interrupt.                   
#define IE_ET1__ENABLED  0x08 ///< Enable interrupt requests generated by the TF1   
                              ///< flag.                                            
                                                                                    
#define IE_ES0__BMASK    0x10 ///< UART0 Interrupt Enable                           
#define IE_ES0__SHIFT    0x04 ///< UART0 Interrupt Enable                           
#define IE_ES0__DISABLED 0x00 ///< Disable UART0 interrupt.                         
#define IE_ES0__ENABLED  0x10 ///< Enable UART0 interrupt.                          
                                                                                    
#define IE_EA__BMASK     0x80 ///< All Interrupts Enable                            
#define IE_EA__SHIFT     0x07 ///< All Interrupts Enable                            
#define IE_EA__DISABLED  0x00 ///< Disable all interrupt sources.                   
#define IE_EA__ENABLED   0x80 ///< Enable each interrupt according to its individual
                              ///< mask setting.                                    
                                                                                    
//------------------------------------------------------------------------------
// IP Enums (Interrupt Priority @ 0xB8)
//------------------------------------------------------------------------------
#define IP_PX0__BMASK 0x01 ///< External Interrupt 0 Priority Control           
#define IP_PX0__SHIFT 0x00 ///< External Interrupt 0 Priority Control           
#define IP_PX0__LOW   0x00 ///< External Interrupt 0 set to low priority level. 
#define IP_PX0__HIGH  0x01 ///< External Interrupt 0 set to high priority level.
                                                                                
#define IP_PT0__BMASK 0x02 ///< Timer 0 Interrupt Priority Control              
#define IP_PT0__SHIFT 0x01 ///< Timer 0 Interrupt Priority Control              
#define IP_PT0__LOW   0x00 ///< Timer 0 interrupt set to low priority level.    
#define IP_PT0__HIGH  0x02 ///< Timer 0 interrupt set to high priority level.   
                                                                                
#define IP_PX1__BMASK 0x04 ///< External Interrupt 1 Priority Control           
#define IP_PX1__SHIFT 0x02 ///< External Interrupt 1 Priority Control           
#define IP_PX1__LOW   0x00 ///< External Interrupt 1 set to low priority level. 
#define IP_PX1__HIGH  0x04 ///< External Interrupt 1 set to high priority level.
                                                                                
#define IP_PT1__BMASK 0x08 ///< Timer 1 Interrupt Priority Control              
#define IP_PT1__SHIFT 0x03 ///< Timer 1 Interrupt Priority Control              
#define IP_PT1__LOW   0x00 ///< Timer 1 interrupt set to low priority level.    
#define IP_PT1__HIGH  0x08 ///< Timer 1 interrupt set to high priority level.   
                                                                                
#define IP_PS0__BMASK 0x10 ///< UART0 Interrupt Priority Control                
#define IP_PS0__SHIFT 0x04 ///< UART0 Interrupt Priority Control                
#define IP_PS0__LOW   0x00 ///< UART0 interrupt set to low priority level.      
#define IP_PS0__HIGH  0x10 ///< UART0 interrupt set to high priority level.     
                                                                                
//------------------------------------------------------------------------------
// OSCLCN Enums (Internal Low Frequency Oscillator Control @ 0xE3)
//------------------------------------------------------------------------------
#define OSCLCN_OSCLEN__BMASK    0x80 ///< Oscillator Enable                    
#define OSCLCN_OSCLEN__SHIFT    0x07 ///< Oscillator Enable                    
#define OSCLCN_OSCLEN__DISABLED 0x00 ///< Disable the Low Frequency Oscillator.
#define OSCLCN_OSCLEN__ENABLED  0x80 ///< Enable the Low Frequency Oscillator. 
                                                                               
//------------------------------------------------------------------------------
// GPIOCN Enums (Global Port I/O Control @ 0xE2)
//------------------------------------------------------------------------------
#define GPIOCN_SYSCKE__BMASK              0x01 ///< SYSCLK Output Enable                              
#define GPIOCN_SYSCKE__SHIFT              0x00 ///< SYSCLK Output Enable                              
#define GPIOCN_SYSCKE__DISABLED           0x00 ///< SYSCLK unavailable at P0.0 pin. P0.0 latch routed 
                                               ///< to P0.0 pin.                                      
#define GPIOCN_SYSCKE__ENABLED            0x01 ///< SYSCLK routed to P0.0. P0.0 latch unavailable at  
                                               ///< P0.0 pin.                                         
                                                                                                      
#define GPIOCN_INPUTEN__BMASK             0x40 ///< Global Digital Input Enable                       
#define GPIOCN_INPUTEN__SHIFT             0x06 ///< Global Digital Input Enable                       
#define GPIOCN_INPUTEN__DISABLED          0x00 ///< Port I/O input path disabled, and port pins can be
                                               ///< used as outputs only.                             
#define GPIOCN_INPUTEN__ENABLED           0x40 ///< Port I/O input path enabled.                      
                                                                                                      
#define GPIOCN_WEAKPUD__BMASK             0x80 ///< Port I/O Weak Pullup Disable                      
#define GPIOCN_WEAKPUD__SHIFT             0x07 ///< Port I/O Weak Pullup Disable                      
#define GPIOCN_WEAKPUD__PULL_UPS_ENABLED  0x00 ///< Weak Pullups enabled (except for I/O pins with    
                                               ///< Port latches set to logic 0 or are configured to  
                                               ///< push-pull mode).                                  
#define GPIOCN_WEAKPUD__PULL_UPS_DISABLED 0x80 ///< Weak Pullups disabled.                            
                                                                                                      
//------------------------------------------------------------------------------
// PCON Enums (Power Control @ 0x87)
//------------------------------------------------------------------------------
#define PCON_IDLE__BMASK  0x01 ///< Idle Mode Select                                
#define PCON_IDLE__SHIFT  0x00 ///< Idle Mode Select                                
#define PCON_IDLE__NORMAL 0x00 ///< Idle mode not activated.                        
#define PCON_IDLE__IDLE   0x01 ///< CPU goes into Idle mode (shuts off clock to CPU,
                               ///< but clocks to enabled peripherals are still     
                               ///< active).                                        
                                                                                    
#define PCON_STOP__BMASK  0x02 ///< Stop Mode Select                                
#define PCON_STOP__SHIFT  0x01 ///< Stop Mode Select                                
#define PCON_STOP__NORMAL 0x00 ///< Stop mode not activated.                        
#define PCON_STOP__STOP   0x02 ///< CPU goes into Stop mode (internal oscillator    
                               ///< stopped).                                       
                                                                                    
#define PCON_GF0__BMASK   0x04 ///< General Purpose Flag 0                          
#define PCON_GF0__SHIFT   0x02 ///< General Purpose Flag 0                          
#define PCON_GF0__NOT_SET 0x00 ///< The GF0 flag is not set. Clear the GF0 flag.    
#define PCON_GF0__SET     0x04 ///< The GF0 flag is set. Set the GF0 flag.          
                                                                                    
#define PCON_GF1__BMASK   0x08 ///< General Purpose Flag 1                          
#define PCON_GF1__SHIFT   0x03 ///< General Purpose Flag 1                          
#define PCON_GF1__NOT_SET 0x00 ///< The GF1 flag is not set. Clear the GF1 flag.    
#define PCON_GF1__SET     0x08 ///< The GF1 flag is set. Set the GF1 flag.          
                                                                                    
#define PCON_GF2__BMASK   0x10 ///< General Purpose Flag 2                          
#define PCON_GF2__SHIFT   0x04 ///< General Purpose Flag 2                          
#define PCON_GF2__NOT_SET 0x00 ///< The GF2 flag is not set. Clear the GF2 flag.    
#define PCON_GF2__SET     0x10 ///< The GF2 flag is set. Set the GF2 flag.          
                                                                                    
#define PCON_GF3__BMASK   0x20 ///< General Purpose Flag 3                          
#define PCON_GF3__SHIFT   0x05 ///< General Purpose Flag 3                          
#define PCON_GF3__NOT_SET 0x00 ///< The GF3 flag is not set. Clear the GF3 flag.    
#define PCON_GF3__SET     0x20 ///< The GF3 flag is set. Set the GF3 flag.          
                                                                                    
#define PCON_GF4__BMASK   0x40 ///< General Purpose Flag 4                          
#define PCON_GF4__SHIFT   0x06 ///< General Purpose Flag 4                          
#define PCON_GF4__NOT_SET 0x00 ///< The GF4 flag is not set. Clear the GF4 flag.    
#define PCON_GF4__SET     0x40 ///< The GF4 flag is set. Set the GF4 flag.          
                                                                                    
#define PCON_GF5__BMASK   0x80 ///< General Purpose Flag 5                          
#define PCON_GF5__SHIFT   0x07 ///< General Purpose Flag 5                          
#define PCON_GF5__NOT_SET 0x00 ///< The GF5 flag is not set. Clear the GF5 flag.    
#define PCON_GF5__SET     0x80 ///< The GF5 flag is set. Set the GF5 flag.          
                                                                                    
//------------------------------------------------------------------------------
// P0 Enums (Port 0 Pin Latch @ 0x80)
//------------------------------------------------------------------------------
#define P0_B0__BMASK 0x01 ///< Port 0 Bit 0 Latch                            
#define P0_B0__SHIFT 0x00 ///< Port 0 Bit 0 Latch                            
#define P0_B0__LOW   0x00 ///< P0.0 is low. Set P0.0 to drive low.           
#define P0_B0__HIGH  0x01 ///< P0.0 is high. Set P0.0 to drive or float high.
                                                                             
#define P0_B1__BMASK 0x02 ///< Port 0 Bit 1 Latch                            
#define P0_B1__SHIFT 0x01 ///< Port 0 Bit 1 Latch                            
#define P0_B1__LOW   0x00 ///< P0.1 is low. Set P0.1 to drive low.           
#define P0_B1__HIGH  0x02 ///< P0.1 is high. Set P0.1 to drive or float high.
                                                                             
#define P0_B2__BMASK 0x04 ///< Port 0 Bit 2 Latch                            
#define P0_B2__SHIFT 0x02 ///< Port 0 Bit 2 Latch                            
#define P0_B2__LOW   0x00 ///< P0.2 is low. Set P0.2 to drive low.           
#define P0_B2__HIGH  0x04 ///< P0.2 is high. Set P0.2 to drive or float high.
                                                                             
#define P0_B3__BMASK 0x08 ///< Port 0 Bit 3 Latch                            
#define P0_B3__SHIFT 0x03 ///< Port 0 Bit 3 Latch                            
#define P0_B3__LOW   0x00 ///< P0.3 is low. Set P0.3 to drive low.           
#define P0_B3__HIGH  0x08 ///< P0.3 is high. Set P0.3 to drive or float high.
                                                                             
#define P0_B4__BMASK 0x10 ///< Port 0 Bit 4 Latch                            
#define P0_B4__SHIFT 0x04 ///< Port 0 Bit 4 Latch                            
#define P0_B4__LOW   0x00 ///< P0.4 is low. Set P0.4 to drive low.           
#define P0_B4__HIGH  0x10 ///< P0.4 is high. Set P0.4 to drive or float high.
                                                                             
#define P0_B5__BMASK 0x20 ///< Port 0 Bit 5 Latch                            
#define P0_B5__SHIFT 0x05 ///< Port 0 Bit 5 Latch                            
#define P0_B5__LOW   0x00 ///< P0.5 is low. Set P0.5 to drive low.           
#define P0_B5__HIGH  0x20 ///< P0.5 is high. Set P0.5 to drive or float high.
                                                                             
#define P0_B6__BMASK 0x40 ///< Port 0 Bit 6 Latch                            
#define P0_B6__SHIFT 0x06 ///< Port 0 Bit 6 Latch                            
#define P0_B6__LOW   0x00 ///< P0.6 is low. Set P0.6 to drive low.           
#define P0_B6__HIGH  0x40 ///< P0.6 is high. Set P0.6 to drive or float high.
                                                                             
#define P0_B7__BMASK 0x80 ///< Port 0 Bit 7 Latch                            
#define P0_B7__SHIFT 0x07 ///< Port 0 Bit 7 Latch                            
#define P0_B7__LOW   0x00 ///< P0.7 is low. Set P0.7 to drive low.           
#define P0_B7__HIGH  0x80 ///< P0.7 is high. Set P0.7 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P0MDOUT Enums (Port 0 Output Mode @ 0xA4)
//------------------------------------------------------------------------------
#define P0MDOUT_B0__BMASK      0x01 ///< Port 0 Bit 0 Output Mode  
#define P0MDOUT_B0__SHIFT      0x00 ///< Port 0 Bit 0 Output Mode  
#define P0MDOUT_B0__OPEN_DRAIN 0x00 ///< P0.0 output is open-drain.
#define P0MDOUT_B0__PUSH_PULL  0x01 ///< P0.0 output is push-pull. 
                                                                   
#define P0MDOUT_B1__BMASK      0x02 ///< Port 0 Bit 1 Output Mode  
#define P0MDOUT_B1__SHIFT      0x01 ///< Port 0 Bit 1 Output Mode  
#define P0MDOUT_B1__OPEN_DRAIN 0x00 ///< P0.1 output is open-drain.
#define P0MDOUT_B1__PUSH_PULL  0x02 ///< P0.1 output is push-pull. 
                                                                   
#define P0MDOUT_B2__BMASK      0x04 ///< Port 0 Bit 2 Output Mode  
#define P0MDOUT_B2__SHIFT      0x02 ///< Port 0 Bit 2 Output Mode  
#define P0MDOUT_B2__OPEN_DRAIN 0x00 ///< P0.2 output is open-drain.
#define P0MDOUT_B2__PUSH_PULL  0x04 ///< P0.2 output is push-pull. 
                                                                   
#define P0MDOUT_B3__BMASK      0x08 ///< Port 0 Bit 3 Output Mode  
#define P0MDOUT_B3__SHIFT      0x03 ///< Port 0 Bit 3 Output Mode  
#define P0MDOUT_B3__OPEN_DRAIN 0x00 ///< P0.3 output is open-drain.
#define P0MDOUT_B3__PUSH_PULL  0x08 ///< P0.3 output is push-pull. 
                                                                   
#define P0MDOUT_B4__BMASK      0x10 ///< Port 0 Bit 4 Output Mode  
#define P0MDOUT_B4__SHIFT      0x04 ///< Port 0 Bit 4 Output Mode  
#define P0MDOUT_B4__OPEN_DRAIN 0x00 ///< P0.4 output is open-drain.
#define P0MDOUT_B4__PUSH_PULL  0x10 ///< P0.4 output is push-pull. 
                                                                   
#define P0MDOUT_B5__BMASK      0x20 ///< Port 0 Bit 5 Output Mode  
#define P0MDOUT_B5__SHIFT      0x05 ///< Port 0 Bit 5 Output Mode  
#define P0MDOUT_B5__OPEN_DRAIN 0x00 ///< P0.5 output is open-drain.
#define P0MDOUT_B5__PUSH_PULL  0x20 ///< P0.5 output is push-pull. 
                                                                   
#define P0MDOUT_B6__BMASK      0x40 ///< Port 0 Bit 6 Output Mode  
#define P0MDOUT_B6__SHIFT      0x06 ///< Port 0 Bit 6 Output Mode  
#define P0MDOUT_B6__OPEN_DRAIN 0x00 ///< P0.6 output is open-drain.
#define P0MDOUT_B6__PUSH_PULL  0x40 ///< P0.6 output is push-pull. 
                                                                   
#define P0MDOUT_B7__BMASK      0x80 ///< Port 0 Bit 7 Output Mode  
#define P0MDOUT_B7__SHIFT      0x07 ///< Port 0 Bit 7 Output Mode  
#define P0MDOUT_B7__OPEN_DRAIN 0x00 ///< P0.7 output is open-drain.
#define P0MDOUT_B7__PUSH_PULL  0x80 ///< P0.7 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// P2 Enums (Port 2 Pin Latch @ 0xA0)
//------------------------------------------------------------------------------
#define P2_B0__BMASK 0x01 ///< Port 2 Bit 0 Latch                            
#define P2_B0__SHIFT 0x00 ///< Port 2 Bit 0 Latch                            
#define P2_B0__LOW   0x00 ///< P2.0 is low. Set P2.0 to drive low.           
#define P2_B0__HIGH  0x01 ///< P2.0 is high. Set P2.0 to drive or float high.
                                                                             
#define P2_B1__BMASK 0x02 ///< Port 2 Bit 1 Latch                            
#define P2_B1__SHIFT 0x01 ///< Port 2 Bit 1 Latch                            
#define P2_B1__LOW   0x00 ///< P2.1 is low. Set P2.1 to drive low.           
#define P2_B1__HIGH  0x02 ///< P2.1 is high. Set P2.1 to drive or float high.
                                                                             
#define P2_B2__BMASK 0x04 ///< Port 2 Bit 2 Latch                            
#define P2_B2__SHIFT 0x02 ///< Port 2 Bit 2 Latch                            
#define P2_B2__LOW   0x00 ///< P2.2 is low. Set P2.2 to drive low.           
#define P2_B2__HIGH  0x04 ///< P2.2 is high. Set P2.2 to drive or float high.
                                                                             
#define P2_B3__BMASK 0x08 ///< Port 2 Bit 3 Latch                            
#define P2_B3__SHIFT 0x03 ///< Port 2 Bit 3 Latch                            
#define P2_B3__LOW   0x00 ///< P2.3 is low. Set P2.3 to drive low.           
#define P2_B3__HIGH  0x08 ///< P2.3 is high. Set P2.3 to drive or float high.
                                                                             
#define P2_B4__BMASK 0x10 ///< Port 2 Bit 4 Latch                            
#define P2_B4__SHIFT 0x04 ///< Port 2 Bit 4 Latch                            
#define P2_B4__LOW   0x00 ///< P2.4 is low. Set P2.4 to drive low.           
#define P2_B4__HIGH  0x10 ///< P2.4 is high. Set P2.4 to drive or float high.
                                                                             
#define P2_B5__BMASK 0x20 ///< Port 2 Bit 5 Latch                            
#define P2_B5__SHIFT 0x05 ///< Port 2 Bit 5 Latch                            
#define P2_B5__LOW   0x00 ///< P2.5 is low. Set P2.5 to drive low.           
#define P2_B5__HIGH  0x20 ///< P2.5 is high. Set P2.5 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P2MDOUT Enums (Port 2 Output Mode @ 0xA6)
//------------------------------------------------------------------------------
#define P2MDOUT_B0__BMASK      0x01 ///< Port 2 Bit 0 Output Mode  
#define P2MDOUT_B0__SHIFT      0x00 ///< Port 2 Bit 0 Output Mode  
#define P2MDOUT_B0__OPEN_DRAIN 0x00 ///< P2.0 output is open-drain.
#define P2MDOUT_B0__PUSH_PULL  0x01 ///< P2.0 output is push-pull. 
                                                                   
#define P2MDOUT_B1__BMASK      0x02 ///< Port 2 Bit 1 Output Mode  
#define P2MDOUT_B1__SHIFT      0x01 ///< Port 2 Bit 1 Output Mode  
#define P2MDOUT_B1__OPEN_DRAIN 0x00 ///< P2.1 output is open-drain.
#define P2MDOUT_B1__PUSH_PULL  0x02 ///< P2.1 output is push-pull. 
                                                                   
#define P2MDOUT_B2__BMASK      0x04 ///< Port 2 Bit 2 Output Mode  
#define P2MDOUT_B2__SHIFT      0x02 ///< Port 2 Bit 2 Output Mode  
#define P2MDOUT_B2__OPEN_DRAIN 0x00 ///< P2.2 output is open-drain.
#define P2MDOUT_B2__PUSH_PULL  0x04 ///< P2.2 output is push-pull. 
                                                                   
#define P2MDOUT_B3__BMASK      0x08 ///< Port 2 Bit 3 Output Mode  
#define P2MDOUT_B3__SHIFT      0x03 ///< Port 2 Bit 3 Output Mode  
#define P2MDOUT_B3__OPEN_DRAIN 0x00 ///< P2.3 output is open-drain.
#define P2MDOUT_B3__PUSH_PULL  0x08 ///< P2.3 output is push-pull. 
                                                                   
#define P2MDOUT_B4__BMASK      0x10 ///< Port 2 Bit 4 Output Mode  
#define P2MDOUT_B4__SHIFT      0x04 ///< Port 2 Bit 4 Output Mode  
#define P2MDOUT_B4__OPEN_DRAIN 0x00 ///< P2.4 output is open-drain.
#define P2MDOUT_B4__PUSH_PULL  0x10 ///< P2.4 output is push-pull. 
                                                                   
#define P2MDOUT_B5__BMASK      0x20 ///< Port 2 Bit 5 Output Mode  
#define P2MDOUT_B5__SHIFT      0x05 ///< Port 2 Bit 5 Output Mode  
#define P2MDOUT_B5__OPEN_DRAIN 0x00 ///< P2.5 output is open-drain.
#define P2MDOUT_B5__PUSH_PULL  0x20 ///< P2.5 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// P3 Enums (Port 3 Pin Latch @ 0xB0)
//------------------------------------------------------------------------------
#define P3_B0__BMASK 0x01 ///< Port 3 Bit 0 Latch                            
#define P3_B0__SHIFT 0x00 ///< Port 3 Bit 0 Latch                            
#define P3_B0__LOW   0x00 ///< P3.0 is low. Set P3.0 to drive low.           
#define P3_B0__HIGH  0x01 ///< P3.0 is high. Set P3.0 to drive or float high.
                                                                             
//------------------------------------------------------------------------------
// P3MDOUT Enums (Port 3 Output Mode @ 0xA7)
//------------------------------------------------------------------------------
#define P3MDOUT_B0__BMASK      0x01 ///< Port 3 Bit 0 Output Mode  
#define P3MDOUT_B0__SHIFT      0x00 ///< Port 3 Bit 0 Output Mode  
#define P3MDOUT_B0__OPEN_DRAIN 0x00 ///< P3.0 output is open-drain.
#define P3MDOUT_B0__PUSH_PULL  0x01 ///< P3.0 output is push-pull. 
                                                                   
//------------------------------------------------------------------------------
// RSTSRC Enums (Reset Source @ 0xEF)
//------------------------------------------------------------------------------
#define RSTSRC_PINRSF__BMASK   0x01 ///< HW Pin Reset Flag                                                    
#define RSTSRC_PINRSF__SHIFT   0x00 ///< HW Pin Reset Flag                                                    
#define RSTSRC_PINRSF__NOT_SET 0x00 ///< The /RST pin did not cause the last reset.                           
#define RSTSRC_PINRSF__SET     0x01 ///< The /RST pin caused the last reset.                                  
                                                                                                              
#define RSTSRC_PORSF__BMASK    0x02 ///< Power-On / Supply Monitor Reset Flag, and Supply Monitor Reset Enable
#define RSTSRC_PORSF__SHIFT    0x01 ///< Power-On / Supply Monitor Reset Flag, and Supply Monitor Reset Enable
#define RSTSRC_PORSF__NOT_SET  0x00 ///< A power-on or supply monitor reset did not occur.                    
#define RSTSRC_PORSF__SET      0x02 ///< A power-on or supply monitor reset occurred.                         
                                                                                                              
#define RSTSRC_MCDRSF__BMASK   0x04 ///< Missing Clock Detector Enable and Flag                               
#define RSTSRC_MCDRSF__SHIFT   0x02 ///< Missing Clock Detector Enable and Flag                               
#define RSTSRC_MCDRSF__NOT_SET 0x00 ///< A missing clock detector reset did not occur.                        
#define RSTSRC_MCDRSF__SET     0x04 ///< A missing clock detector reset occurred.                             
                                                                                                              
#define RSTSRC_SWRSF__BMASK    0x10 ///< Software Reset Force and Flag                                        
#define RSTSRC_SWRSF__SHIFT    0x04 ///< Software Reset Force and Flag                                        
#define RSTSRC_SWRSF__NOT_SET  0x00 ///< A software reset did not occur.                                      
#define RSTSRC_SWRSF__SET      0x10 ///< A software reset occurred.                                           
                                                                                                              
#define RSTSRC_FERROR__BMASK   0x40 ///< Flash Error Reset Flag                                               
#define RSTSRC_FERROR__SHIFT   0x06 ///< Flash Error Reset Flag                                               
#define RSTSRC_FERROR__NOT_SET 0x00 ///< A flash error reset did not occur.                                   
#define RSTSRC_FERROR__SET     0x40 ///< A flash error reset occurred.                                        
                                                                                                              
#define RSTSRC_USBRSF__BMASK   0x80 ///< USB Reset Enable and Flag                                            
#define RSTSRC_USBRSF__SHIFT   0x07 ///< USB Reset Enable and Flag                                            
#define RSTSRC_USBRSF__NOT_SET 0x00 ///< A USB0 reset did not occur.                                          
#define RSTSRC_USBRSF__SET     0x80 ///< A USB0 reset occurred.                                               
                                                                                                              
//------------------------------------------------------------------------------
// TH0 Enums (Timer 0 High Byte @ 0x8C)
//------------------------------------------------------------------------------
#define TH0_TH0__FMASK 0xFF ///< Timer 0 High Byte
#define TH0_TH0__SHIFT 0x00 ///< Timer 0 High Byte
                                                  
//------------------------------------------------------------------------------
// TH1 Enums (Timer 1 High Byte @ 0x8D)
//------------------------------------------------------------------------------
#define TH1_TH1__FMASK 0xFF ///< Timer 1 High Byte
#define TH1_TH1__SHIFT 0x00 ///< Timer 1 High Byte
                                                  
//------------------------------------------------------------------------------
// TL0 Enums (Timer 0 Low Byte @ 0x8A)
//------------------------------------------------------------------------------
#define TL0_TL0__FMASK 0xFF ///< Timer 0 Low Byte
#define TL0_TL0__SHIFT 0x00 ///< Timer 0 Low Byte
                                                 
//------------------------------------------------------------------------------
// TL1 Enums (Timer 1 Low Byte @ 0x8B)
//------------------------------------------------------------------------------
#define TL1_TL1__FMASK 0xFF ///< Timer 1 Low Byte
#define TL1_TL1__SHIFT 0x00 ///< Timer 1 Low Byte
                                                 
//------------------------------------------------------------------------------
// CKCON Enums (Clock Control @ 0x8E)
//------------------------------------------------------------------------------
#define CKCON_SCA__FMASK         0x03 ///< Timer 0/1 Prescale                            
#define CKCON_SCA__SHIFT         0x00 ///< Timer 0/1 Prescale                            
#define CKCON_SCA__SYSCLK_DIV_12 0x00 ///< System clock divided by 12.                   
#define CKCON_SCA__SYSCLK_DIV_4  0x01 ///< System clock divided by 4.                    
#define CKCON_SCA__SYSCLK_DIV_48 0x02 ///< System clock divided by 48.                   
                                                                                         
#define CKCON_T0M__BMASK         0x04 ///< Timer 0 Clock Select                          
#define CKCON_T0M__SHIFT         0x02 ///< Timer 0 Clock Select                          
#define CKCON_T0M__PRESCALE      0x00 ///< Counter/Timer 0 uses the clock defined by the 
                                      ///< prescale field, SCA.                          
#define CKCON_T0M__SYSCLK        0x04 ///< Counter/Timer 0 uses the system clock.        
                                                                                         
#define CKCON_T1M__BMASK         0x08 ///< Timer 1 Clock Select                          
#define CKCON_T1M__SHIFT         0x03 ///< Timer 1 Clock Select                          
#define CKCON_T1M__PRESCALE      0x00 ///< Timer 1 uses the clock defined by the prescale
                                      ///< field, SCA.                                   
#define CKCON_T1M__SYSCLK        0x08 ///< Timer 1 uses the system clock.                
                                                                                         
//------------------------------------------------------------------------------
// TCON Enums (Timer 0/1 Control @ 0x88)
//------------------------------------------------------------------------------
#define TCON_IT0__BMASK   0x01 ///< Interrupt 0 Type Select  
#define TCON_IT0__SHIFT   0x00 ///< Interrupt 0 Type Select  
#define TCON_IT0__LEVEL   0x00 ///< /INT0 is level triggered.
#define TCON_IT0__EDGE    0x01 ///< /INT0 is edge triggered. 
                                                             
#define TCON_IE0__BMASK   0x02 ///< External Interrupt 0     
#define TCON_IE0__SHIFT   0x01 ///< External Interrupt 0     
#define TCON_IE0__NOT_SET 0x00 ///< Edge/level not detected. 
#define TCON_IE0__SET     0x02 ///< Edge/level detected      
                                                             
#define TCON_IT1__BMASK   0x04 ///< Interrupt 1 Type Select  
#define TCON_IT1__SHIFT   0x02 ///< Interrupt 1 Type Select  
#define TCON_IT1__LEVEL   0x00 ///< /INT1 is level triggered.
#define TCON_IT1__EDGE    0x04 ///< /INT1 is edge triggered. 
                                                             
#define TCON_IE1__BMASK   0x08 ///< External Interrupt 1     
#define TCON_IE1__SHIFT   0x03 ///< External Interrupt 1     
#define TCON_IE1__NOT_SET 0x00 ///< Edge/level not detected. 
#define TCON_IE1__SET     0x08 ///< Edge/level detected      
                                                             
#define TCON_TR0__BMASK   0x10 ///< Timer 0 Run Control      
#define TCON_TR0__SHIFT   0x04 ///< Timer 0 Run Control      
#define TCON_TR0__STOP    0x00 ///< Stop Timer 0.            
#define TCON_TR0__RUN     0x10 ///< Start Timer 0 running.   
                                                             
#define TCON_TF0__BMASK   0x20 ///< Timer 0 Overflow Flag    
#define TCON_TF0__SHIFT   0x05 ///< Timer 0 Overflow Flag    
#define TCON_TF0__NOT_SET 0x00 ///< Timer 0 did not overflow.
#define TCON_TF0__SET     0x20 ///< Timer 0 overflowed.      
                                                             
#define TCON_TR1__BMASK   0x40 ///< Timer 1 Run Control      
#define TCON_TR1__SHIFT   0x06 ///< Timer 1 Run Control      
#define TCON_TR1__STOP    0x00 ///< Stop Timer 1.            
#define TCON_TR1__RUN     0x40 ///< Start Timer 1 running.   
                                                             
#define TCON_TF1__BMASK   0x80 ///< Timer 1 Overflow Flag    
#define TCON_TF1__SHIFT   0x07 ///< Timer 1 Overflow Flag    
#define TCON_TF1__NOT_SET 0x00 ///< Timer 1 did not overflow.
#define TCON_TF1__SET     0x80 ///< Timer 1 overflowed.      
                                                             
//------------------------------------------------------------------------------
// TMOD Enums (Timer 0/1 Mode @ 0x89)
//------------------------------------------------------------------------------
#define TMOD_T0M__FMASK      0x03 ///< Timer 0 Mode Select                               
#define TMOD_T0M__SHIFT      0x00 ///< Timer 0 Mode Select                               
#define TMOD_T0M__MODE0      0x00 ///< Mode 0, 13-bit Counter/Timer                      
#define TMOD_T0M__MODE1      0x01 ///< Mode 1, 16-bit Counter/Timer                      
#define TMOD_T0M__MODE2      0x02 ///< Mode 2, 8-bit Counter/Timer with Auto-Reload      
#define TMOD_T0M__MODE3      0x03 ///< Mode 3, Two 8-bit Counter/Timers                  
                                                                                         
#define TMOD_GATE0__BMASK    0x08 ///< Timer 0 Gate Control                              
#define TMOD_GATE0__SHIFT    0x03 ///< Timer 0 Gate Control                              
#define TMOD_GATE0__DISABLED 0x00 ///< Timer 0 enabled when TR0 = 1 irrespective of /INT0
                                  ///< logic level.                                      
#define TMOD_GATE0__ENABLED  0x08 ///< Timer 0 enabled only when TR0 = 1 and /INT0 is    
                                  ///< active as defined by bit IN0PL in register IT01CF.
                                                                                         
#define TMOD_T1M__FMASK      0x30 ///< Timer 1 Mode Select                               
#define TMOD_T1M__SHIFT      0x04 ///< Timer 1 Mode Select                               
#define TMOD_T1M__MODE0      0x00 ///< Mode 0, 13-bit Counter/Timer                      
#define TMOD_T1M__MODE1      0x10 ///< Mode 1, 16-bit Counter/Timer                      
#define TMOD_T1M__MODE2      0x20 ///< Mode 2, 8-bit Counter/Timer with Auto-Reload      
#define TMOD_T1M__MODE3      0x30 ///< Mode 3, Timer 1 Inactive                          
                                                                                         
#define TMOD_GATE1__BMASK    0x80 ///< Timer 1 Gate Control                              
#define TMOD_GATE1__SHIFT    0x07 ///< Timer 1 Gate Control                              
#define TMOD_GATE1__DISABLED 0x00 ///< Timer 1 enabled when TR1 = 1 irrespective of /INT1
                                  ///< logic level.                                      
#define TMOD_GATE1__ENABLED  0x80 ///< Timer 1 enabled only when TR1 = 1 and /INT1 is    
                                  ///< active as defined by bit IN1PL in register IT01CF.
                                                                                         
//------------------------------------------------------------------------------
// SBCON0 Enums (UART0 Baud Rate Generator Control @ 0x91)
//------------------------------------------------------------------------------
#define SBCON0_SBPS__FMASK     0x03 ///< Baud Rate Prescaler Select                        
#define SBCON0_SBPS__SHIFT     0x00 ///< Baud Rate Prescaler Select                        
#define SBCON0_SBPS__DIV_BY_12 0x00 ///< Prescaler = 12.                                   
#define SBCON0_SBPS__DIV_BY_4  0x01 ///< Prescaler = 4.                                    
#define SBCON0_SBPS__DIV_BY_48 0x02 ///< Prescaler = 48.                                   
#define SBCON0_SBPS__DIV_BY_1  0x03 ///< Prescaler = 1.                                    
                                                                                           
#define SBCON0_SBRUN__BMASK    0x40 ///< Baud Rate Generator Enable                        
#define SBCON0_SBRUN__SHIFT    0x06 ///< Baud Rate Generator Enable                        
#define SBCON0_SBRUN__DISABLED 0x00 ///< Disable the baud rate generator. UART0 will not   
                                    ///< function.                                         
#define SBCON0_SBRUN__ENABLED  0x40 ///< Enable the baud rate generator.                   
                                                                                           
#define SBCON0_SBCLK__BMASK    0x80 ///< Baud Rate Generator Clock Source                  
#define SBCON0_SBCLK__SHIFT    0x07 ///< Baud Rate Generator Clock Source                  
#define SBCON0_SBCLK__SYSCLK   0x00 ///< The system clock (SYSCLK) is used as the baud rate
                                    ///< generator clock source.                           
#define SBCON0_SBCLK__USBCLK   0x80 ///< The USB clock (USBCLK) is used as the baud rate   
                                    ///< generator clock source.                           
                                                                                           
//------------------------------------------------------------------------------
// SBRLH0 Enums (UART0 Baud Rate Generator High Byte @ 0x94)
//------------------------------------------------------------------------------
#define SBRLH0_SBRL__FMASK 0xFF ///< UART0 Baud Rate Reload High
#define SBRLH0_SBRL__SHIFT 0x00 ///< UART0 Baud Rate Reload High
                                                                
//------------------------------------------------------------------------------
// SBRLL0 Enums (UART0 Baud Rate Generator Low Byte @ 0x93)
//------------------------------------------------------------------------------
#define SBRLL0_SBRL__FMASK 0xFF ///< UART0 Baud Rate Reload Low
#define SBRLL0_SBRL__SHIFT 0x00 ///< UART0 Baud Rate Reload Low
                                                               
//------------------------------------------------------------------------------
// SBUF0 Enums (UART0 Serial Port Data Buffer @ 0x99)
//------------------------------------------------------------------------------
#define SBUF0_SBUF0__FMASK 0xFF ///< Serial Port Data Buffer
#define SBUF0_SBUF0__SHIFT 0x00 ///< Serial Port Data Buffer
                                                            
//------------------------------------------------------------------------------
// SCON0 Enums (UART0 Serial Port Control @ 0x98)
//------------------------------------------------------------------------------
#define SCON0_RI__BMASK             0x01 ///< Receive Interrupt Flag                           
#define SCON0_RI__SHIFT             0x00 ///< Receive Interrupt Flag                           
#define SCON0_RI__NOT_SET           0x00 ///< A byte of data has not been received by UART0.   
#define SCON0_RI__SET               0x01 ///< UART0 received a byte of data or data remains in 
                                         ///< the receive FIFO.                                
                                                                                               
#define SCON0_TI__BMASK             0x02 ///< Transmit Interrupt Flag                          
#define SCON0_TI__SHIFT             0x01 ///< Transmit Interrupt Flag                          
#define SCON0_TI__NOT_SET           0x00 ///< A byte of data has not been transmitted by UART0.
#define SCON0_TI__SET               0x02 ///< UART0 transmitted a byte of data.                
                                                                                               
#define SCON0_RBX__BMASK            0x04 ///< Extra Receive Bit                                
#define SCON0_RBX__SHIFT            0x02 ///< Extra Receive Bit                                
#define SCON0_RBX__LOW              0x00 ///< The extra bit or the first stop bit is 0.        
#define SCON0_RBX__HIGH             0x04 ///< The extra bit or the first stop bit is 1.        
                                                                                               
#define SCON0_TBX__BMASK            0x08 ///< Extra Transmission Bit                           
#define SCON0_TBX__SHIFT            0x03 ///< Extra Transmission Bit                           
#define SCON0_TBX__LOW              0x00 ///< Set extra bit to 0 (low).                        
#define SCON0_TBX__HIGH             0x08 ///< Set extra bit to 1 (high).                       
                                                                                               
#define SCON0_REN__BMASK            0x10 ///< Receive Enable                                   
#define SCON0_REN__SHIFT            0x04 ///< Receive Enable                                   
#define SCON0_REN__RECEIVE_DISABLED 0x00 ///< UART0 reception disabled.                        
#define SCON0_REN__RECEIVE_ENABLED  0x10 ///< UART0 reception enabled.                         
                                                                                               
#define SCON0_PERR__BMASK           0x40 ///< Parity Error Flag                                
#define SCON0_PERR__SHIFT           0x06 ///< Parity Error Flag                                
#define SCON0_PERR__NOT_SET         0x00 ///< Parity error has not occurred.                   
#define SCON0_PERR__SET             0x40 ///< Parity error has occurred.                       
                                                                                               
#define SCON0_OVR__BMASK            0x80 ///< Receive FIFO Overrun Flag                        
#define SCON0_OVR__SHIFT            0x07 ///< Receive FIFO Overrun Flag                        
#define SCON0_OVR__NOT_SET          0x00 ///< Receive FIFO overrun has not occurred.           
#define SCON0_OVR__SET              0x80 ///< Receive FIFO overrun has occurred.               
                                                                                               
//------------------------------------------------------------------------------
// SMOD0 Enums (UART0 Mode @ 0x9A)
//------------------------------------------------------------------------------
#define SMOD0_SBL__BMASK          0x01 ///< Stop Bit Length                                 
#define SMOD0_SBL__SHIFT          0x00 ///< Stop Bit Length                                 
#define SMOD0_SBL__SHORT          0x00 ///< Short: Stop bit is active for one bit time.     
#define SMOD0_SBL__LONG           0x01 ///< Long: Stop bit is active for two bit times (data
                                       ///< length = 6, 7, or 8 bits) or 1.5 bit times (data
                                       ///< length = 5 bits).                               
                                                                                            
#define SMOD0_XBE__BMASK          0x02 ///< Extra Bit Enable                                
#define SMOD0_XBE__SHIFT          0x01 ///< Extra Bit Enable                                
#define SMOD0_XBE__DISABLED       0x00 ///< Disable the extra bit.                          
#define SMOD0_XBE__ENABLED        0x02 ///< Enable the extra bit.                           
                                                                                            
#define SMOD0_SDL__FMASK          0x0C ///< Data Length                                     
#define SMOD0_SDL__SHIFT          0x02 ///< Data Length                                     
#define SMOD0_SDL__5_BITS         0x00 ///< 5 bits.                                         
#define SMOD0_SDL__6_BITS         0x04 ///< 6 bits.                                         
#define SMOD0_SDL__7_BITS         0x08 ///< 7 bits.                                         
#define SMOD0_SDL__8_BITS         0x0C ///< 8 bits.                                         
                                                                                            
#define SMOD0_PE__BMASK           0x10 ///< Parity Enable                                   
#define SMOD0_PE__SHIFT           0x04 ///< Parity Enable                                   
#define SMOD0_PE__PARITY_DISABLED 0x00 ///< Disable hardware parity.                        
#define SMOD0_PE__PARITY_ENABLED  0x10 ///< Enable hardware parity.                         
                                                                                            
#define SMOD0_SPT__FMASK          0x60 ///< Parity Type                                     
#define SMOD0_SPT__SHIFT          0x05 ///< Parity Type                                     
#define SMOD0_SPT__ODD_PARTY      0x00 ///< Odd.                                            
#define SMOD0_SPT__EVEN_PARITY    0x20 ///< Even.                                           
#define SMOD0_SPT__MARK_PARITY    0x40 ///< Mark.                                           
#define SMOD0_SPT__SPACE_PARITY   0x60 ///< Space.                                          
                                                                                            
#define SMOD0_MCE__BMASK          0x80 ///< Multiprocessor Communication Enable             
#define SMOD0_MCE__SHIFT          0x07 ///< Multiprocessor Communication Enable             
#define SMOD0_MCE__MULTI_DISABLED 0x00 ///< RI will be activated if the stop bits are 1.    
#define SMOD0_MCE__MULTI_ENABLED  0x80 ///< RI will be activated if the stop bits and extra 
                                       ///< bit are 1. The extra bit must be enabled using  
                                       ///< XBE.                                            
                                                                                            
//------------------------------------------------------------------------------
// CLKREC Enums (USB0 Clock Recovery Control @ 0x0F)
//------------------------------------------------------------------------------
#define CLKREC_CRLOW__BMASK      0x20 ///< Low Speed Clock Recovery Mode               
#define CLKREC_CRLOW__SHIFT      0x05 ///< Low Speed Clock Recovery Mode               
#define CLKREC_CRLOW__FULL_SPEED 0x00 ///< Full Speed Mode.                            
#define CLKREC_CRLOW__LOW_SPEED  0x20 ///< Low Speed Mode.                             
                                                                                       
#define CLKREC_CRSSEN__BMASK     0x40 ///< Clock Recovery Single Step                  
#define CLKREC_CRSSEN__SHIFT     0x06 ///< Clock Recovery Single Step                  
#define CLKREC_CRSSEN__DISABLED  0x00 ///< Disable single-step mode (normal calibration
                                      ///< mode).                                      
#define CLKREC_CRSSEN__ENABLED   0x40 ///< Enable single-step mode.                    
                                                                                       
#define CLKREC_CRE__BMASK        0x80 ///< Clock Recovery Enable                       
#define CLKREC_CRE__SHIFT        0x07 ///< Clock Recovery Enable                       
#define CLKREC_CRE__DISABLED     0x00 ///< Disable clock recovery.                     
#define CLKREC_CRE__ENABLED      0x80 ///< Enable clock recovery.                      
                                                                                       
//------------------------------------------------------------------------------
// CMIE Enums (USB0 Common Interrupt Enable @ 0x0B)
//------------------------------------------------------------------------------
#define CMIE_SUSINTE__BMASK    0x01 ///< Suspend Interrupt Enable       
#define CMIE_SUSINTE__SHIFT    0x00 ///< Suspend Interrupt Enable       
#define CMIE_SUSINTE__DISABLED 0x00 ///< Disable suspend interrupts.    
#define CMIE_SUSINTE__ENABLED  0x01 ///< Enable suspend interrupts.     
                                                                        
#define CMIE_RSUINTE__BMASK    0x02 ///< Resume Interrupt Enable        
#define CMIE_RSUINTE__SHIFT    0x01 ///< Resume Interrupt Enable        
#define CMIE_RSUINTE__DISABLED 0x00 ///< Disable resume interrupts.     
#define CMIE_RSUINTE__ENABLED  0x02 ///< Enable resume interrupts.      
                                                                        
#define CMIE_RSTINTE__BMASK    0x04 ///< Reset Interrupt Enable         
#define CMIE_RSTINTE__SHIFT    0x02 ///< Reset Interrupt Enable         
#define CMIE_RSTINTE__DISABLED 0x00 ///< Disable reset interrupts.      
#define CMIE_RSTINTE__ENABLED  0x04 ///< Enable reset interrupts.       
                                                                        
#define CMIE_SOFE__BMASK       0x08 ///< Start of Frame Interrupt Enable
#define CMIE_SOFE__SHIFT       0x03 ///< Start of Frame Interrupt Enable
#define CMIE_SOFE__DISABLED    0x00 ///< Disable SOF interrupts.        
#define CMIE_SOFE__ENABLED     0x08 ///< Enable SOF interrupts.         
                                                                        
//------------------------------------------------------------------------------
// CMINT Enums (USB0 Common Interrupt @ 0x06)
//------------------------------------------------------------------------------
#define CMINT_SUSINT__BMASK   0x01 ///< Suspend Interrupt Flag       
#define CMINT_SUSINT__SHIFT   0x00 ///< Suspend Interrupt Flag       
#define CMINT_SUSINT__NOT_SET 0x00 ///< Suspend interrupt inactive.  
#define CMINT_SUSINT__SET     0x01 ///< Suspend interrupt active.    
                                                                     
#define CMINT_RSUINT__BMASK   0x02 ///< Resume Interrupt Flag        
#define CMINT_RSUINT__SHIFT   0x01 ///< Resume Interrupt Flag        
#define CMINT_RSUINT__NOT_SET 0x00 ///< Resume interrupt inactive.   
#define CMINT_RSUINT__SET     0x02 ///< Resume interrupt active.     
                                                                     
#define CMINT_RSTINT__BMASK   0x04 ///< Reset Interrupt Flag         
#define CMINT_RSTINT__SHIFT   0x02 ///< Reset Interrupt Flag         
#define CMINT_RSTINT__NOT_SET 0x00 ///< Reset interrupt inactive.    
#define CMINT_RSTINT__SET     0x04 ///< Reset interrupt active.      
                                                                     
#define CMINT_SOF__BMASK      0x08 ///< Start of Frame Interrupt Flag
#define CMINT_SOF__SHIFT      0x03 ///< Start of Frame Interrupt Flag
#define CMINT_SOF__NOT_SET    0x00 ///< SOF interrupt inactive.      
#define CMINT_SOF__SET        0x08 ///< SOF interrupt active.        
                                                                     
//------------------------------------------------------------------------------
// E0CNT Enums (USB0 Endpoint0 Data Count @ 0x16)
//------------------------------------------------------------------------------
#define E0CNT_E0CNT__FMASK 0x7F ///< Endpoint 0 Data Count
#define E0CNT_E0CNT__SHIFT 0x00 ///< Endpoint 0 Data Count
                                                          
//------------------------------------------------------------------------------
// E0CSR Enums (USB0 Endpoint0 Control @ 0x11)
//------------------------------------------------------------------------------
#define E0CSR_OPRDY__BMASK     0x01 ///< OUT Packet Ready                                  
#define E0CSR_OPRDY__SHIFT     0x00 ///< OUT Packet Ready                                  
#define E0CSR_OPRDY__NOT_SET   0x00 ///< A data packet has not been received.              
#define E0CSR_OPRDY__SET       0x01 ///< A data packet has been received.                  
                                                                                           
#define E0CSR_INPRDY__BMASK    0x02 ///< IN Packet Ready                                   
#define E0CSR_INPRDY__SHIFT    0x01 ///< IN Packet Ready                                   
#define E0CSR_INPRDY__NOT_SET  0x00 ///< An IN packet is not ready to transmit.            
#define E0CSR_INPRDY__SET      0x02 ///< An IN packet is ready to transmit.                
                                                                                           
#define E0CSR_STSTL__BMASK     0x04 ///< Sent Stall                                        
#define E0CSR_STSTL__SHIFT     0x02 ///< Sent Stall                                        
#define E0CSR_STSTL__NOT_SET   0x00 ///< A STALL handshake signal was not transmitted.     
#define E0CSR_STSTL__SET       0x04 ///< A STALL handshake signal was transmitted.         
                                                                                           
#define E0CSR_DATAEND__BMASK   0x08 ///< Data End                                          
#define E0CSR_DATAEND__SHIFT   0x03 ///< Data End                                          
#define E0CSR_DATAEND__NOT_SET 0x00 ///< This is not the last data packet.                 
#define E0CSR_DATAEND__SET     0x08 ///< This is the last data packet.                     
                                                                                           
#define E0CSR_SUEND__BMASK     0x10 ///< Setup End                                         
#define E0CSR_SUEND__SHIFT     0x04 ///< Setup End                                         
#define E0CSR_SUEND__NOT_SET   0x00 ///< A control transaction did not end before firmware 
                                    ///< wrote a 1 to the DATAEND bit.                     
#define E0CSR_SUEND__SET       0x10 ///< A control transaction ended before firmware wrote 
                                    ///< a 1 to the DATAEND bit.                           
                                                                                           
#define E0CSR_SDSTL__BMASK     0x20 ///< Send Stall                                        
#define E0CSR_SDSTL__SHIFT     0x05 ///< Send Stall                                        
#define E0CSR_SDSTL__NOT_SET   0x00 ///< Do not send a STALL.                              
#define E0CSR_SDSTL__SET       0x20 ///< Send a STALL.                                     
                                                                                           
#define E0CSR_SOPRDY__BMASK    0x40 ///< Serviced OPRDY                                    
#define E0CSR_SOPRDY__SHIFT    0x06 ///< Serviced OPRDY                                    
#define E0CSR_SOPRDY__NOT_SET  0x00 ///< OUT packet has not been serviced.                 
#define E0CSR_SOPRDY__SET      0x40 ///< OUT packet has been serviced.                     
                                                                                           
#define E0CSR_SSUEND__BMASK    0x80 ///< Serviced Setup End                                
#define E0CSR_SSUEND__SHIFT    0x07 ///< Serviced Setup End                                
#define E0CSR_SSUEND__NOT_SET  0x00 ///< The setup end (SUEND) event has not been serviced.
#define E0CSR_SSUEND__SET      0x80 ///< The setup end (SUEND) event has been serviced.    
                                                                                           
//------------------------------------------------------------------------------
// EINCSRH Enums (USB0 IN Endpoint Control High @ 0x12)
//------------------------------------------------------------------------------
#define EINCSRH_FCDT__BMASK         0x08 ///< Force Data Toggle                                
#define EINCSRH_FCDT__SHIFT         0x03 ///< Force Data Toggle                                
#define EINCSRH_FCDT__ACK_TOGGLE    0x00 ///< Endpoint data toggle switches only when an ACK is
                                         ///< received following a data packet transmission.   
#define EINCSRH_FCDT__ALWAYS_TOGGLE 0x08 ///< Endpoint data toggle forced to switch after every
                                         ///< data packet is transmitted, regardless of ACK    
                                         ///< reception.                                       
                                                                                               
#define EINCSRH_ISO__BMASK          0x40 ///< Isochronous Transfer Enable                      
#define EINCSRH_ISO__SHIFT          0x06 ///< Isochronous Transfer Enable                      
#define EINCSRH_ISO__DISABLED       0x00 ///< Endpoint configured for Bulk/Interrupt transfers.
#define EINCSRH_ISO__ENABLED        0x40 ///< Endpoint configured for Isochronous transfers.   
                                                                                               
#define EINCSRH_DBIEN__BMASK        0x80 ///< IN Endpoint Double-Buffer Enable                 
#define EINCSRH_DBIEN__SHIFT        0x07 ///< IN Endpoint Double-Buffer Enable                 
#define EINCSRH_DBIEN__DISABLED     0x00 ///< Disable double-buffering for the selected IN     
                                         ///< endpoint.                                        
#define EINCSRH_DBIEN__ENABLED      0x80 ///< Enable double-buffering for the selected IN      
                                         ///< endpoint.                                        
                                                                                               
//------------------------------------------------------------------------------
// EINCSRL Enums (USB0 IN Endpoint Control Low @ 0x11)
//------------------------------------------------------------------------------
#define EINCSRL_INPRDY__BMASK     0x01 ///< In Packet Ready                                   
#define EINCSRL_INPRDY__SHIFT     0x00 ///< In Packet Ready                                   
#define EINCSRL_INPRDY__NOT_SET   0x00 ///< A packet is not available in the Endpoint IN FIFO.
#define EINCSRL_INPRDY__SET       0x01 ///< A packet is available in the Endpoint IN FIFO.    
                                                                                              
#define EINCSRL_FIFONE__BMASK     0x02 ///< FIFO Not Empty                                    
#define EINCSRL_FIFONE__SHIFT     0x01 ///< FIFO Not Empty                                    
#define EINCSRL_FIFONE__EMPTY     0x00 ///< The IN Endpoint FIFO is empty.                    
#define EINCSRL_FIFONE__NOT_EMPTY 0x02 ///< The IN Endpoint FIFO contains one or more packets.
                                                                                              
#define EINCSRL_UNDRUN__BMASK     0x04 ///< Data Underrun Flag                                
#define EINCSRL_UNDRUN__SHIFT     0x02 ///< Data Underrun Flag                                
#define EINCSRL_UNDRUN__NOT_SET   0x00 ///< A data underrun did not occur.                    
#define EINCSRL_UNDRUN__SET       0x04 ///< A data underrun occurred.                         
                                                                                              
#define EINCSRL_FLUSH__BMASK      0x08 ///< FIFO Flush                                        
#define EINCSRL_FLUSH__SHIFT      0x03 ///< FIFO Flush                                        
#define EINCSRL_FLUSH__NOT_SET    0x00 ///< Do not flush the next packet.                     
#define EINCSRL_FLUSH__SET        0x08 ///< Flush the next packet to be transmitted from the  
                                       ///< IN Endpoint FIFO.                                 
                                                                                              
#define EINCSRL_SDSTL__BMASK      0x10 ///< Send Stall                                        
#define EINCSRL_SDSTL__SHIFT      0x04 ///< Send Stall                                        
#define EINCSRL_SDSTL__NOT_SET    0x00 ///< Terminate the STALL.                              
#define EINCSRL_SDSTL__SET        0x10 ///< Generate a STALL in response to an IN token.      
                                                                                              
#define EINCSRL_STSTL__BMASK      0x20 ///< Sent Stall Flag                                   
#define EINCSRL_STSTL__SHIFT      0x05 ///< Sent Stall Flag                                   
#define EINCSRL_STSTL__NOT_SET    0x00 ///< A STALL handshake was not transmitted.            
#define EINCSRL_STSTL__SET        0x20 ///< A STALL handshake was transmitted.                
                                                                                              
#define EINCSRL_CLRDT__BMASK      0x40 ///< Clear Data Toggle                                 
#define EINCSRL_CLRDT__SHIFT      0x06 ///< Clear Data Toggle                                 
#define EINCSRL_CLRDT__CLEAR      0x00 ///< Clear the IN Endpoint data toggle.                
                                                                                              
//------------------------------------------------------------------------------
// EOUTCNTH Enums (USB0 OUT Endpoint Count High @ 0x17)
//------------------------------------------------------------------------------
#define EOUTCNTH_EOCH__FMASK 0x03 ///< OUT Endpoint Count High
#define EOUTCNTH_EOCH__SHIFT 0x00 ///< OUT Endpoint Count High
                                                              
//------------------------------------------------------------------------------
// EOUTCNTL Enums (USB0 OUT Endpoint Count Low @ 0x16)
//------------------------------------------------------------------------------
#define EOUTCNTL_EOCL__FMASK 0xFF ///< OUT Endpoint Count Low
#define EOUTCNTL_EOCL__SHIFT 0x00 ///< OUT Endpoint Count Low
                                                             
//------------------------------------------------------------------------------
// EOUTCSRH Enums (USB0 OUT Endpoint Control High @ 0x15)
//------------------------------------------------------------------------------
#define EOUTCSRH_ISO__BMASK      0x40 ///< Isochronous Transfer Enable                      
#define EOUTCSRH_ISO__SHIFT      0x06 ///< Isochronous Transfer Enable                      
#define EOUTCSRH_ISO__DISABLED   0x00 ///< Endpoint configured for Bulk/Interrupt transfers.
#define EOUTCSRH_ISO__ENABLED    0x40 ///< Endpoint configured for Isochronous transfers.   
                                                                                            
#define EOUTCSRH_DBOEN__BMASK    0x80 ///< Double-Buffer Enable                             
#define EOUTCSRH_DBOEN__SHIFT    0x07 ///< Double-Buffer Enable                             
#define EOUTCSRH_DBOEN__DISABLED 0x00 ///< Disable double-buffering for the selected OUT    
                                      ///< endpoint.                                        
#define EOUTCSRH_DBOEN__ENABLED  0x80 ///< Enable double-buffering for the selected OUT     
                                      ///< endpoint.                                        
                                                                                            
//------------------------------------------------------------------------------
// EOUTCSRL Enums (USB0 OUT Endpoint Control Low @ 0x14)
//------------------------------------------------------------------------------
#define EOUTCSRL_OPRDY__BMASK      0x01 ///< OUT Packet Ready                                  
#define EOUTCSRL_OPRDY__SHIFT      0x00 ///< OUT Packet Ready                                  
#define EOUTCSRL_OPRDY__NOT_SET    0x00 ///< A data packet is not available in the Endpoint OUT
                                        ///< FIFO.                                             
#define EOUTCSRL_OPRDY__SET        0x01 ///< A data packet is available in the Endpoint OUT    
                                        ///< FIFO.                                             
                                                                                               
#define EOUTCSRL_FIFOFUL__BMASK    0x02 ///< OUT FIFO Full                                     
#define EOUTCSRL_FIFOFUL__SHIFT    0x01 ///< OUT FIFO Full                                     
#define EOUTCSRL_FIFOFUL__NOT_FULL 0x00 ///< OUT endpoint FIFO is not full.                    
#define EOUTCSRL_FIFOFUL__FULL     0x02 ///< OUT endpoint FIFO is full.                        
                                                                                               
#define EOUTCSRL_OVRUN__BMASK      0x04 ///< Data Overrun Flag                                 
#define EOUTCSRL_OVRUN__SHIFT      0x02 ///< Data Overrun Flag                                 
#define EOUTCSRL_OVRUN__NOT_SET    0x00 ///< No data overrun.                                  
#define EOUTCSRL_OVRUN__SET        0x04 ///< A data packet was lost because of a full FIFO     
                                        ///< since this flag was last cleared.                 
                                                                                               
#define EOUTCSRL_DATERR__BMASK     0x08 ///< Data Error Flag                                   
#define EOUTCSRL_DATERR__SHIFT     0x03 ///< Data Error Flag                                   
#define EOUTCSRL_DATERR__NOT_SET   0x00 ///< A received packet does not have a CRC or bit-     
                                        ///< stuffing error.                                   
#define EOUTCSRL_DATERR__SET       0x08 ///< A received packet has a CRC or bit-stuffing error.
                                                                                               
#define EOUTCSRL_FLUSH__BMASK      0x10 ///< FIFO Flush                                        
#define EOUTCSRL_FLUSH__SHIFT      0x04 ///< FIFO Flush                                        
#define EOUTCSRL_FLUSH__NOT_SET    0x00 ///< Do not flush the next packet.                     
#define EOUTCSRL_FLUSH__SET        0x10 ///< Flush the next packet to be read from the OUT     
                                        ///< endpoint FIFO.                                    
                                                                                               
#define EOUTCSRL_SDSTL__BMASK      0x20 ///< Send Stall                                        
#define EOUTCSRL_SDSTL__SHIFT      0x05 ///< Send Stall                                        
#define EOUTCSRL_SDSTL__NOT_SET    0x00 ///< Terminate the STALL.                              
#define EOUTCSRL_SDSTL__SET        0x20 ///< Generate a STALL handshake.                       
                                                                                               
#define EOUTCSRL_STSTL__BMASK      0x40 ///< Sent Stall Flag                                   
#define EOUTCSRL_STSTL__SHIFT      0x06 ///< Sent Stall Flag                                   
#define EOUTCSRL_STSTL__NOT_SET    0x00 ///< A STALL handshake was not transmitted.            
#define EOUTCSRL_STSTL__SET        0x40 ///< A STALL handshake was transmitted.                
                                                                                               
#define EOUTCSRL_CLRDT__BMASK      0x80 ///< Clear Data Toggle                                 
#define EOUTCSRL_CLRDT__SHIFT      0x07 ///< Clear Data Toggle                                 
#define EOUTCSRL_CLRDT__CLEAR      0x00 ///< Clear the OUT Endpoint data toggle.               
                                                                                               
//------------------------------------------------------------------------------
// FADDR Enums (USB0 Function Address @ 0x00)
//------------------------------------------------------------------------------
#define FADDR_FADDR__FMASK    0x7F ///< Function Address                               
#define FADDR_FADDR__SHIFT    0x00 ///< Function Address                               
                                                                                       
#define FADDR_UPDATE__BMASK   0x80 ///< Function Address Update                        
#define FADDR_UPDATE__SHIFT   0x07 ///< Function Address Update                        
#define FADDR_UPDATE__NOT_SET 0x00 ///< The last address written to FADDR is in effect.
#define FADDR_UPDATE__SET     0x80 ///< The last address written to FADDR is not yet in
                                   ///< effect.                                        
                                                                                       
//------------------------------------------------------------------------------
// FIFO0 Enums (USB0 Endpoint 0 FIFO Access @ 0x20)
//------------------------------------------------------------------------------
#define FIFO0_FIFODATA__FMASK 0xFF ///< Endpoint 0 FIFO Access
#define FIFO0_FIFODATA__SHIFT 0x00 ///< Endpoint 0 FIFO Access
                                                              
//------------------------------------------------------------------------------
// FIFO1 Enums (USB0 Endpoint 1 FIFO Access @ 0x21)
//------------------------------------------------------------------------------
#define FIFO1_FIFODATA__FMASK 0xFF ///< Endpoint 1 FIFO Access
#define FIFO1_FIFODATA__SHIFT 0x00 ///< Endpoint 1 FIFO Access
                                                              
//------------------------------------------------------------------------------
// FRAMEH Enums (USB0 Frame Number High @ 0x0D)
//------------------------------------------------------------------------------
#define FRAMEH_FRMEH__FMASK 0x07 ///< Frame Number High
#define FRAMEH_FRMEH__SHIFT 0x00 ///< Frame Number High
                                                       
//------------------------------------------------------------------------------
// FRAMEL Enums (USB0 Frame Number Low @ 0x0C)
//------------------------------------------------------------------------------
#define FRAMEL_FRMEL__FMASK 0xFF ///< Frame Number Low
#define FRAMEL_FRMEL__SHIFT 0x00 ///< Frame Number Low
                                                      
//------------------------------------------------------------------------------
// IN1IE Enums (USB0 IN Endpoint Interrupt Enable @ 0x07)
//------------------------------------------------------------------------------
#define IN1IE_EP0E__BMASK    0x01 ///< Endpoint 0 Interrupt Enable      
#define IN1IE_EP0E__SHIFT    0x00 ///< Endpoint 0 Interrupt Enable      
#define IN1IE_EP0E__DISABLED 0x00 ///< Disable Endpoint 0 interrupts.   
#define IN1IE_EP0E__ENABLED  0x01 ///< Enable Endpoint 0 interrupts.    
                                                                        
#define IN1IE_IN1E__BMASK    0x02 ///< IN Endpoint 1 Interrupt Enable   
#define IN1IE_IN1E__SHIFT    0x01 ///< IN Endpoint 1 Interrupt Enable   
#define IN1IE_IN1E__DISABLED 0x00 ///< Disable Endpoint 1 IN interrupts.
#define IN1IE_IN1E__ENABLED  0x02 ///< Enable Endpoint 1 IN interrupts. 
                                                                        
//------------------------------------------------------------------------------
// IN1INT Enums (USB0 IN Endpoint Interrupt @ 0x02)
//------------------------------------------------------------------------------
#define IN1INT_EP0__BMASK   0x01 ///< Endpoint 0 Interrupt Flag        
#define IN1INT_EP0__SHIFT   0x00 ///< Endpoint 0 Interrupt Flag        
#define IN1INT_EP0__NOT_SET 0x00 ///< Endpoint 0 interrupt inactive.   
#define IN1INT_EP0__SET     0x01 ///< Endpoint 0 interrupt active.     
                                                                       
#define IN1INT_IN1__BMASK   0x02 ///< IN Endpoint 1 Interrupt Flag     
#define IN1INT_IN1__SHIFT   0x01 ///< IN Endpoint 1 Interrupt Flag     
#define IN1INT_IN1__NOT_SET 0x00 ///< IN Endpoint 1 interrupt inactive.
#define IN1INT_IN1__SET     0x02 ///< IN Endpoint 1 interrupt active.  
                                                                       
//------------------------------------------------------------------------------
// INDEX Enums (USB0 Endpoint Index @ 0x0E)
//------------------------------------------------------------------------------
#define INDEX_EPSEL__FMASK      0x0F ///< Endpoint Select Bits
#define INDEX_EPSEL__SHIFT      0x00 ///< Endpoint Select Bits
#define INDEX_EPSEL__ENDPOINT_0 0x00 ///< Endpoint 0.         
#define INDEX_EPSEL__ENDPOINT_1 0x01 ///< Endpoint 1.         
                                                              
//------------------------------------------------------------------------------
// OUT1IE Enums (USB0 OUT Endpoint Interrupt Enable @ 0x09)
//------------------------------------------------------------------------------
#define OUT1IE_OUT1E__BMASK    0x02 ///< OUT Endpoint 1 Interrupt Enable   
#define OUT1IE_OUT1E__SHIFT    0x01 ///< OUT Endpoint 1 Interrupt Enable   
#define OUT1IE_OUT1E__DISABLED 0x00 ///< Disable Endpoint 1 OUT interrupts.
#define OUT1IE_OUT1E__ENABLED  0x02 ///< Enable Endpoint 1 OUT interrupts. 
                                                                           
//------------------------------------------------------------------------------
// OUT1INT Enums (USB0 OUT Endpoint Interrupt @ 0x04)
//------------------------------------------------------------------------------
#define OUT1INT_OUT1__BMASK   0x02 ///< OUT Endpoint 1 Interrupt Flag     
#define OUT1INT_OUT1__SHIFT   0x01 ///< OUT Endpoint 1 Interrupt Flag     
#define OUT1INT_OUT1__NOT_SET 0x00 ///< OUT Endpoint 1 interrupt inactive.
#define OUT1INT_OUT1__SET     0x02 ///< OUT Endpoint 1 interrupt active.  
                                                                          
//------------------------------------------------------------------------------
// POWER Enums (USB0 Power @ 0x01)
//------------------------------------------------------------------------------
#define POWER_SUSEN__BMASK         0x01 ///< Suspend Detection Enable                          
#define POWER_SUSEN__SHIFT         0x00 ///< Suspend Detection Enable                          
#define POWER_SUSEN__DISABLED      0x00 ///< Disable suspend detection. USB0 will ignore       
                                        ///< suspend signaling on the bus.                     
#define POWER_SUSEN__ENABLED       0x01 ///< Enable suspend detection. USB0 will enter suspend 
                                        ///< mode if it detects suspend signaling on the bus.  
                                                                                               
#define POWER_SUSMD__BMASK         0x02 ///< Suspend Mode                                      
#define POWER_SUSMD__SHIFT         0x01 ///< Suspend Mode                                      
#define POWER_SUSMD__NOT_SUSPENDED 0x00 ///< USB0 not in suspend mode.                         
#define POWER_SUSMD__SUSPENDED     0x02 ///< USB0 in suspend mode.                             
                                                                                               
#define POWER_RESUME__BMASK        0x04 ///< Force Resume                                      
#define POWER_RESUME__SHIFT        0x02 ///< Force Resume                                      
#define POWER_RESUME__START        0x04 ///< Generate resume signalling to create a remote     
                                        ///< wakeup event.                                     
                                                                                               
#define POWER_USBRST__BMASK        0x08 ///< Reset Detect                                      
#define POWER_USBRST__SHIFT        0x03 ///< Reset Detect                                      
#define POWER_USBRST__NOT_SET      0x00 ///< USB reset signalling not detected.                
#define POWER_USBRST__SET          0x08 ///< USB reset signalling detected.                    
                                                                                               
#define POWER_USBINH__BMASK        0x10 ///< USB0 Inhibit                                      
#define POWER_USBINH__SHIFT        0x04 ///< USB0 Inhibit                                      
#define POWER_USBINH__ENABLED      0x00 ///< USB0 enabled.                                     
#define POWER_USBINH__DISABLED     0x10 ///< USB0 inhibited. All USB traffic is ignored.       
                                                                                               
#define POWER_ISOUD__BMASK         0x80 ///< Isochronous Update Mode                           
#define POWER_ISOUD__SHIFT         0x07 ///< Isochronous Update Mode                           
#define POWER_ISOUD__IN_TOKEN      0x00 ///< When firmware writes INPRDY = 1, USB0 will send   
                                        ///< the packet when the next IN token is received.    
#define POWER_ISOUD__SOF_TOKEN     0x80 ///< When firmware writes INPRDY = 1, USB0 will wait   
                                        ///< for a SOF token before sending the packet. If an  
                                        ///< IN token is received before a SOF token, USB0 will
                                        ///< send a zero-length data packet.                   
                                                                                               
//------------------------------------------------------------------------------
// USB0ADR Enums (USB0 Indirect Address @ 0x96)
//------------------------------------------------------------------------------
#define USB0ADR_USBADDR__FMASK          0x3F ///< USB0 Indirect Register Address                    
#define USB0ADR_USBADDR__SHIFT          0x00 ///< USB0 Indirect Register Address                    
#define USB0ADR_USBADDR__FADDR          0x00 ///< Function Address.                                 
#define USB0ADR_USBADDR__POWER          0x01 ///< Power Management.                                 
#define USB0ADR_USBADDR__IN1INT         0x02 ///< Endpoint 0 and Endpoints 1-3 IN Interrupt Flags.  
#define USB0ADR_USBADDR__OUT1INT        0x04 ///< Endpoints 1-3 OUT Interrupt Flags.                
#define USB0ADR_USBADDR__CMINT          0x06 ///< Common USB Interrupt Flags.                       
#define USB0ADR_USBADDR__IN1IE          0x07 ///< Endpoint 0 and Endpoints 1-3 IN Interrupt Enables.
#define USB0ADR_USBADDR__OUT1IE         0x09 ///< Endpoints 1-3 OUT Interrupt Enables.              
#define USB0ADR_USBADDR__CMIE           0x0B ///< Common USB Interrupt Enables.                     
#define USB0ADR_USBADDR__FRAMEL         0x0C ///< Frame Number Low Byte.                            
#define USB0ADR_USBADDR__FRAMEH         0x0D ///< Frame Number High Byte.                           
#define USB0ADR_USBADDR__INDEX          0x0E ///< Endpoint Index Selection.                         
#define USB0ADR_USBADDR__CLKREC         0x0F ///< Clock Recovery Control.                           
#define USB0ADR_USBADDR__E0CSR_EINCSRL  0x11 ///< Endpoint 0 Control / Status, Endpoint IN Control /
                                             ///< Status Low Byte.                                  
#define USB0ADR_USBADDR__EINCSRH        0x12 ///< Endpoint IN Control / Status High Byte.           
#define USB0ADR_USBADDR__EOUTCSRL       0x14 ///< Endpoint OUT Control / Status Low Byte.           
#define USB0ADR_USBADDR__EOUTCSRH       0x15 ///< Endpoint OUT Control / Status High Byte.          
#define USB0ADR_USBADDR__E0CNT_EOUTCNTL 0x16 ///< Number of Received Bytes in Endpoint 0 FIFO,      
                                             ///< Endpoint OUT Packet Count Low Byte.               
#define USB0ADR_USBADDR__EOUTCNTH       0x17 ///< Endpoint OUT Packet Count High Byte.              
#define USB0ADR_USBADDR__EENABLE        0x1E ///< Endpoint Enable.                                  
#define USB0ADR_USBADDR__FIFO0          0x20 ///< Endpoint 0 FIFO.                                  
#define USB0ADR_USBADDR__FIFO1          0x21 ///< Endpoint 1 FIFO.                                  
                                                                                                    
#define USB0ADR_AUTORD__BMASK           0x40 ///< USB0 Register Auto-Read Flag                      
#define USB0ADR_AUTORD__SHIFT           0x06 ///< USB0 Register Auto-Read Flag                      
#define USB0ADR_AUTORD__DISABLED        0x00 ///< BUSY must be written manually for each USB0       
                                             ///< indirect register read.                           
#define USB0ADR_AUTORD__ENABLED         0x40 ///< The next indirect register read will automatically
                                             ///< be initiated when firmware reads USB0DAT (USBADDR 
                                             ///< bits will not be changed).                        
                                                                                                    
#define USB0ADR_BUSY__BMASK             0x80 ///< USB0 Register Read Busy Flag                      
#define USB0ADR_BUSY__SHIFT             0x07 ///< USB0 Register Read Busy Flag                      
#define USB0ADR_BUSY__NOT_SET           0x00 ///< A read is not in progress.                        
#define USB0ADR_BUSY__SET               0x80 ///< Initiate a read or a read is in progress.         
                                                                                                    
//------------------------------------------------------------------------------
// USB0DAT Enums (USB0 Data @ 0x97)
//------------------------------------------------------------------------------
#define USB0DAT_USB0DAT__FMASK 0xFF ///< USB0 Data
#define USB0DAT_USB0DAT__SHIFT 0x00 ///< USB0 Data
                                                  
//------------------------------------------------------------------------------
// USB0XCN Enums (USB0 Transceiver Control @ 0xD7)
//------------------------------------------------------------------------------
#define USB0XCN_Dn__BMASK                0x01 ///< D- Signal Status                                 
#define USB0XCN_Dn__SHIFT                0x00 ///< D- Signal Status                                 
#define USB0XCN_Dn__LOW                  0x00 ///< D- signal currently at logic 0.                  
#define USB0XCN_Dn__HIGH                 0x01 ///< D- signal currently at logic 1.                  
                                                                                                    
#define USB0XCN_Dp__BMASK                0x02 ///< D+ Signal Status                                 
#define USB0XCN_Dp__SHIFT                0x01 ///< D+ Signal Status                                 
#define USB0XCN_Dp__LOW                  0x00 ///< D+ signal currently at logic 0.                  
#define USB0XCN_Dp__HIGH                 0x02 ///< D+ signal currently at logic 1.                  
                                                                                                    
#define USB0XCN_DFREC__BMASK             0x04 ///< Differential Receiver                            
#define USB0XCN_DFREC__SHIFT             0x02 ///< Differential Receiver                            
#define USB0XCN_DFREC__DIFFERENTIAL_ZERO 0x00 ///< Differential 0 signalling on the bus.            
#define USB0XCN_DFREC__DIFFERENTIAL_ONE  0x04 ///< Differential 1 signalling on the bus.            
                                                                                                    
#define USB0XCN_PHYTST__FMASK            0x18 ///< Physical Layer Test                              
#define USB0XCN_PHYTST__SHIFT            0x03 ///< Physical Layer Test                              
#define USB0XCN_PHYTST__MODE0            0x00 ///< Mode 0: Normal (non-test mode) (D+ = X, D- = X). 
#define USB0XCN_PHYTST__MODE1            0x08 ///< Mode 1: Differential 1 forced (D+ = 1, D- = 0).  
#define USB0XCN_PHYTST__MODE2            0x10 ///< Mode 2: Differential 0 forced (D+ = 0, D- = 1).  
#define USB0XCN_PHYTST__MODE3            0x18 ///< Mode 3: Single-Ended 0 forced (D+ = 0, D- = 0).  
                                                                                                    
#define USB0XCN_SPEED__BMASK             0x20 ///< USB0 Speed Select                                
#define USB0XCN_SPEED__SHIFT             0x05 ///< USB0 Speed Select                                
#define USB0XCN_SPEED__LOW_SPEED         0x00 ///< USB0 operates as a Low Speed device. If enabled, 
                                              ///< the internal pull-up resistor appears on the D-  
                                              ///< line.                                            
#define USB0XCN_SPEED__FULL_SPEED        0x20 ///< USB0 operates as a Full Speed device. If enabled,
                                              ///< the internal pull-up resistor appears on the D+  
                                              ///< line.                                            
                                                                                                    
#define USB0XCN_PHYEN__BMASK             0x40 ///< Physical Layer Enable                            
#define USB0XCN_PHYEN__SHIFT             0x06 ///< Physical Layer Enable                            
#define USB0XCN_PHYEN__DISABLED          0x00 ///< Disable the USB0 physical layer transceiver      
                                              ///< (suspend).                                       
#define USB0XCN_PHYEN__ENABLED           0x40 ///< Enable the USB0 physical layer transceiver       
                                              ///< (normal).                                        
                                                                                                    
#define USB0XCN_PREN__BMASK              0x80 ///< Internal Pull-up Resistor Enable                 
#define USB0XCN_PREN__SHIFT              0x07 ///< Internal Pull-up Resistor Enable                 
#define USB0XCN_PREN__PULL_UP_DISABLED   0x00 ///< Internal pull-up resistor disabled (device       
                                              ///< effectively detached from USB network).          
#define USB0XCN_PREN__PULL_UP_ENABLED    0x80 ///< Internal pull-up resistor enabled when VBUS is   
                                              ///< present (device attached to the USB network).    
                                                                                                    
//------------------------------------------------------------------------------
// VDM0CN Enums (VDD Supply Monitor Control @ 0xFF)
//------------------------------------------------------------------------------
#define VDM0CN_VDDSTAT__BMASK     0x40 ///< VDD Status                                   
#define VDM0CN_VDDSTAT__SHIFT     0x06 ///< VDD Status                                   
#define VDM0CN_VDDSTAT__VDD_BELOW 0x00 ///< VDD is at or below the VDD monitor threshold.
#define VDM0CN_VDDSTAT__VDD_ABOVE 0x40 ///< VDD is above the VDD monitor threshold.      
                                                                                         
#define VDM0CN_VDMEN__BMASK       0x80 ///< VDD Monitor Enable                           
#define VDM0CN_VDMEN__SHIFT       0x07 ///< VDD Monitor Enable                           
#define VDM0CN_VDMEN__DISABLED    0x00 ///< Disable the VDD Monitor.                     
#define VDM0CN_VDMEN__ENABLED     0x80 ///< Enable the VDD Monitor.                      
                                                                                         
//------------------------------------------------------------------------------
// REG0CN Enums (Voltage Regulator Control @ 0xC9)
//------------------------------------------------------------------------------
#define REG0CN_REG0MD__BMASK     0x10 ///< VREG0 Voltage Regulator Mode                     
#define REG0CN_REG0MD__SHIFT     0x04 ///< VREG0 Voltage Regulator Mode                     
#define REG0CN_REG0MD__NORMAL    0x00 ///< VREG0 Voltage Regulator in normal mode.          
#define REG0CN_REG0MD__LOW_POWER 0x10 ///< VREG0 Voltage Regulator in low power mode.       
                                                                                            
#define REG0CN_VBPOL__BMASK      0x20 ///< VBUS Interrupt Polarity Select                   
#define REG0CN_VBPOL__SHIFT      0x05 ///< VBUS Interrupt Polarity Select                   
#define REG0CN_VBPOL__LOW        0x00 ///< VBUS interrupt active when VBUS is low.          
#define REG0CN_VBPOL__HIGH       0x20 ///< VBUS interrupt active when VBUS is high.         
                                                                                            
#define REG0CN_VBSTAT__BMASK     0x40 ///< VBUS Signal Status                               
#define REG0CN_VBSTAT__SHIFT     0x06 ///< VBUS Signal Status                               
#define REG0CN_VBSTAT__NOT_SET   0x00 ///< VBUS signal currently absent (device not attached
                                      ///< to USB network).                                 
#define REG0CN_VBSTAT__SET       0x40 ///< VBUS signal currently present (device attached to
                                      ///< USB network).                                    
                                                                                            
#define REG0CN_REG0DIS__BMASK    0x80 ///< Voltage Regulator (REG0) Disable                 
#define REG0CN_REG0DIS__SHIFT    0x07 ///< Voltage Regulator (REG0) Disable                 
#define REG0CN_REG0DIS__ENABLED  0x00 ///< Enable the VREG0 Voltage Regulator.              
#define REG0CN_REG0DIS__DISABLED 0x80 ///< Disable the VREG0 Voltage Regulator.             
                                                                                            
//------------------------------------------------------------------------------
// EMI0CN Enums (External Memory Interface Control @ 0xAA)
//------------------------------------------------------------------------------
#define EMI0CN_PGSEL__FMASK 0x03 ///< XRAM Page Select
#define EMI0CN_PGSEL__SHIFT 0x00 ///< XRAM Page Select
                                                      
#endif // SI_C8051F326_REGISTER_ENUMS_H
//-eof--------------------------------------------------------------------------

