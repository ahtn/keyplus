/**************************************************************************//**
 * @file
 * @brief   Header file for the VCPXpress firmware library.  Includes function
 *          prototypes, type definitions, and function return value macro
 *          definitions.
 * @author  Silicon Laboratories
 * @version 1.0.0 (DM: July 14, 2014)
 *
 *******************************************************************************
 * @section License
 * (C) Copyright 2014 Silicon Labs Inc,
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *******************************************************************************
 *
 * @addtogroup vcpxpress VCPXpress
 * @{
 *
 * @brief
 *   VCPXpress interface library.
 *
 * ## Introduction
 *
 *   This module provides a firmware interface which interfaces with the Silicion Labs
 *   VCP (Virtual Com Port) driver and allows firmware to interact with host programs via
 *   standard COM Port.
 *   
 * ### Memory Usage
 *
 *  The library consumes aproximatly 9K of Flash 110 bytes of XDATA and 60 bytes if IRAM
 *
 * ## Theory of operation:
 *   
 *   The VCPxpress library interfaces with the Silicon Labs VCP drivers. The interface
 *   consists of a set of commands and two data transmission pipes (rx and tx). The commands
 *   are used to relay changes to the COM port configuration and the data pipes are used
 *   to send and receive the COM port data.

 * ### Get Commands
 *   
 *   The library has internal storage which maintains the status of the com port. When the
 *   host issues a command to read this information it is returned without user intervention.
 *   
 * ### Set Commands
 *   When the host issues a command to change the com port configuration the user call-back
 *   is called and a flag passed to indicate what information has been modified. The full list
 *   of possible call-back events is found in the @ref vcpx_status section of the module documentation.
 *
 *   The content and encoding of each command is detailed in AN512. For example if the user is
 *   called back with the VCP_CB_SET_EVENTMASK flag set the data associated with that command
 *   can be retrieved with VCP_Get_Eventmask(). That data will be 16bits wide as shown in section
 *   5.15 of AN512.
 *   
 *  ### Data
 *
 *   Data reception and transmission is handled with Block_Read() and Block_Write(). Upon
 *   Completion of a sent or received packet the user is called back with RX_COMPLETE or TX_COMPLETE.
 *
 *  # Additional Resources
 *
 *   * [Communication AppNote - AN571](http://www.silabs.com/Support%20Documents/TechnicalDocs/AN571.pdf)
 *   * [Development drivers](http://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx)  
 *   * [Driver Customization - AN220](http://www.silabs.com/Support%20Documents/TechnicalDocs/AN200.pdf)
 *
 *   This driver wraps the efm8_usb Library and both can not be used at the same time.
 *
 * ## Re-entrance (non-thread-safe)
 *   
 *   @warn
 *     The VCPXPress library is NOT reentrant.
 *   
 *   For example if the main loop calls into the library and that call is interrupted 
 *   by code which also calls into the library an error may occur. The user must ensure that 
 *   the library is accessed from only one context at a time.
 *   
 *   The most common way of handling this is to disable USB interrupts when calling
 *   into the library from the main loop. If other ISR's call into the 
 *   library those interrupts must be disabled as well.
 *   
 * ## Interrupts
 *   
 *   This library handles USB0 interrupts and will enabled USB0 interrupts at
 *   it's  discretion. It will NOT enable global interrupts and the user is 
 *   responsible for enabling global interrupts.
 *   
 *****************************************************************************/

#ifndef  _VCPXPRESS_H_
#define  _VCPXPRESS_H_
#include <stdint.h>
#include <stdbool.h>

/**************************************************************************//**
 * Define user API call-back function with:
 * VCPXpress_API_Callback( <call-back name here> ){}
 *
 * @warn
 *   The call-back routine is called by the VCPXpress library from
 * within the USB interrupt.  It should run as quickly as possible.
 *
 * If timing becomes an issue, consider using the call-back routine to set
 * user-defined flags that may be serviced in the project's main loop.
 * Additionally note that the call-back routine will be called for every call-back
 * source, whether or not the user checks for that call-back source.  All code
 * except variable declarations and the Get_call-back_Source() call should check
 * for a pertinent call-back source (see the Status Flags section for all call-back sources).
 *
 *****************************************************************************/
#define VCPXpress_API_CALLBACK(name) void name (void)

/***************************************************************************//**
 *  @addtogroup vcpx_status Status Flags
 *  @{
 *  
 *  These enums are returned by Get_Callback_Source(). The return value is 
 *  a mask and may contain the logical OR of any combination of status flags.
 *  Each flags maps to a call-back event.
 *  
 ******************************************************************************/
// Basic Get_Callback_Source() return value bit masks (32 bits)
// Note: More than one bit can be set at the same time.
#define USB_RESET                0x00000001     //!< USB Reset Interrupt has occurred
#define TX_COMPLETE              0x00000002     //!< Transmit Complete Interrupt has occurred
#define RX_COMPLETE              0x00000004     //!< Receive Complete Interrupt has occurred
#define FIFO_PURGE               0x00000008     //!< Command received (and serviced) from the host
//!< to purge the USB buffers
#define DEVICE_OPEN              0x00000010     //!< Device Instance Opened on host side
#define DEVICE_CLOSE             0x00000020     //!< Device Instance Closed on host side
#define DEV_CONFIGURED           0x00000040     //!< Device has entered configured state
#define DEV_SUSPEND              0x00000080     //!< USB suspend signaling present on bus
// VCP (CP2103) call-back control command bit masks for Get_Callback_Source().  See AN571 for details.
// Note: Devices using the VCPXpress library will enumerate as a CP2103 device.
//       This is so they will be correctly associated with the VCP driver.
#define VCP_CB_SET_BAUDRATE      0x00000100     //!< VCP (CP2103) set baud rate command. data = VCP_Get_LineControl()
#define VCP_CB_SET_LINE_CTL      0x00000200     //!< VCP (CP2103) set line control command. data = VCP_Get_LineControl()
#define VCP_CB_SET_MHS           0x00000400     //!< VCP (CP2103) set modem handshake state command. data = VCP_Get_ModemStatus()
#define VCP_CB_SET_FLOW          0x00000800     //!< VCP (CP2103) set flow control command. data = VCP_Get_FlowControl()
#define VCP_CB_SET_XON           0x00001000     //!< VCP (CP2103) emulate XON received command.
#define VCP_CB_SET_XOFF          0x00002000     //!< VCP (CP2103) emulate XOFF received command.
#define VCP_CB_SET_BREAK         0x00004000     //!< VCP (CP2103) break transmit/reset command.
#define VCP_CB_RESET_BREAK       0x00008000     //!< VCP (CP2103) break transmit/reset command.
#define VCP_CB_IMM_CHAR          0x00010000     //!< VCP (CP2103) immediate char transfer command. data = VCP_Get_ImmChar()
#define VCP_CB_SET_EVENTMASK     0x00020000     //!< VCP (CP2103) set event mask command. data = VCP_Get_Eventmask()
#define VCP_CB_SET_CHARS         0x00040000     //!< VCP (CP2103) set special chars command. data = VCP_Get_Chars()
#define VCP_CB_EMBED_EVENTS      0x00080000     //!< VCP (CP2103) embed events command. data = VCP_Get_EmbeddedEvent()
#define VCP_CB_PURGE_RX          0x00100000     //!< VCP (CP2103) clear receive queue command.
#define VCP_CB_PURGE_TX          0x00200000     //!< VCP (CP2103) clear transmit queue command.
/**  @} (end vcpx_status Status Flags) */

#define VCP_STATUS_OK                   0
#define VCP_STATUS_EP_BUSY             -2
#define VCP_STATUS_ILLEGAL             -4
#define VCP_STATUS_EP_STALLED          -5
#define VCP_STATUS_DEVICE_UNCONFIGURED -9



/***************************************************************************//**
 *  @brief
 *    VCPXpress initialization function parameter typedef
 *
 *  User should instantiate and pass by reference to USB_Init.
 *
 *****************************************************************************/
typedef struct VCPXpress_Init_TypeDef {
	uint16_t VendorID; /**< 16-bit Vendor ID to be returned to the
	 *   host's Operating System during USB
	 *   enumeration. Set to 0x10C4 to use the
	 *   default Silicon Laboratories Vendor ID.
	 */

	uint16_t ProductID; /**< 16-bit Product ID to be returned to the
	 *   host's Operating System during USB
	 *   enumeration. Set to 0xEA60 to associate
	 *   with the default VCP driver.
	 */

	uint8_t* ManufacturerString; /**< Pointer to a character string. See AN571
	 *    Appendix B for formatting. NULL pointer
	 *    will be treated as a valid address.
	 */

	uint8_t* ProductString; /**< Pointer to a character string. See AN571
	 *   Appendix B for formatting. NULL pointer
	 *   will be treated as a valid address.
	 */

	uint8_t* SerialString; /**< Pointer to a character string. See
	 *   Appendix B for formatting. NULL pointer
	 *   will be treated as a valid address.
	 */

	uint8_t MaxPower; /**< Specifies how much bus current a device
	 *   requires.  Set to one half the number of
	 *   milliamperes required. The maximum
	 *   allowed current is 500 milliamperes, and
	 *   hence any value above 0xFA will be
	 *   automatically set to 0xFA. Example: Set
	 *   to 0x32 to request 100 mA.
	 */

	uint8_t PowerAttribute; /**< Set bit 6 to 1 if the device is self-
	 *   powered and to 0 if it is bus-powered.
	 *   Set bit 5 to 1 if the device supports the
	 *   remote wakeup feature. Bits 0 through 4
	 *   must be 0 and bit 7 must be 1. Example:
	 *   Set to 0x80 to specify a bus-powered
	 *   device that does not support remote
	 *   wakeup.
	 */

	uint16_t ReleaseBCD; /**< The device's release number in BCD
	 *   (binary-coded decimal) format. In BCD,
	 *   the upper byte represents the integer,
	 *   the next four bits are tenths, and the
	 *   final four bits are hundredths.  Example:
	 *   2.13 is denoted by 0x0213.
	 */

	uint8_t useFifo; /**< Whether to use the USB FIFO space to
	 *   store VCP variables or else store them in
	 *   user xram.  The addresses of the
	 *   variables are the same either way.  If
	 *   the current device does not support the
	 *   use of the USB FIFO space form variable
	 *   storage, this option does nothing.
	 */

} VCPXpress_Init_TypeDef;

/***************************************************************************//**
 *  @addtogroup vcpx_func Functions
 *  @{
 *  
 *  These enums are returned by Get_Callback_Source(). The return value is 
 *  a mask and may contain the logical OR of any combination of status flags
 *  
 ******************************************************************************/

// VCPXpress external function prototypes.  Similar to corresponding USBXpress functions.
/**************************************************************************//**
 * @brief
 *   Enables user API call-backs
 *
 * @param   f:
 *   Pointer to user-defined call-back function.
 *
 * Enables USB interrups and sets the API call-back function pointer to the
 * passed function which should be defined with VCPXpress_API_CALLBACK.
 *
 *****************************************************************************/
void API_Callback_Enable(void (*f)(void)) large;

/**************************************************************************//**
 * @brief
 *   Inhibits user API call-backs and does NOT disable the USB interrupt.
 *
 *****************************************************************************/
void API_Callback_Disable(void) large;

/**************************************************************************//**
 * @brief
 *   User API function to get data from host.
 *
 * @param   block:
 *   Pointer to user's array where received data will be stored.
 * @param   numBytes:
 *   Number of bytes to receive from host
 * @param[out]   count_ptr:
 *   Pointer to user's storage for number of bytes actually received from the
 *   host.  This will be valid upon the subsequent RX_COMPLETE call-back.
 *
 * @return
 *   This function returns a status word. 0 indicates that the read was
 *   Successfully started. Any other value indicates that the request was
 *   ignored. The most common reason is VCP_STATUS_EP_BUSY meaning that
 *   a Read is alreay in progress.
 *
 * A RX_COMPLET call-back will occur for each usb packet (64 bytes) in the block
 * write. For example if the user reads a block of 100 bytes RX_COMPLETE will
 * occur 2 times. Once with 64bytes sent and once with 100-64 = 36 bytes sent.
 *
 * This function utilizes the efm8_usb library's USBD_Read function,
 * which only prepares for a read.  The actual read will occur over time as the
 * host transmits data. The user API RX_COMPLETE call-back will be called as each
 * usb packet is received.
 *
 *
 *****************************************************************************/
int8_t Block_Read(uint8_t* block, uint16_t numBytes, uint16_t* count_ptr) large;

/**************************************************************************//**
 * @brief
 *   User API function to send data to host.
 *
 * @param   block:
 *   Pointer to user's array where data to be transmitted is stored.
 * @param   numBytes:
 *   Number of bytes to send to host
 * @param[out]   count_ptr:
 *   Pointer to user's storage for number of bytes actually transmitted to the
 *   host.  This will be valid upon the subsequent TX_COMPLETE call-back.
 *
 * @return
 *   This function returns a status word. 0 indicates that the write was
 *   successfully started. Any other value indicates that the request was
 *   ignored. The most common reason is VCP_STATUS_EP_BUSY meaning that
 *   a write is already in progress.
 *
 * A TX_COMPLETE callback will occure for each usb packet (64 bytes) in the block
 * write. For example if the user writes a block of 100 bytes TX_COMPLETE will
 * occur 2 times. Once with 64bytes sent and once with 100-64 = 36 bytes sent.
 *
 * This function utilizes the efm8_usb library's USBD_Write function,
 * which only prepares for a write.  The actual write will occur over time as the
 * host transmits data. The user API RX_COMPLETE call-back will be called as each
 * usb packet is received.
 *
 *****************************************************************************/
int8_t Block_Write(uint8_t* block, uint16_t numBytes, uint16_t* count_ptr) large;

/**************************************************************************//**
 * @brief
 *   User API function to get the call-back source.
 *
 * Returns an 32-bit value indicating the reason(s) for the API call-back, and
 * clears the USB API call-back pending flag(s). This function should be called
 * at the beginning of the user's call-back service routine to determine which
 * event(s) has/have occurred.
 *
 * @return
 *   An unsigned 32-bit code indicating the reason(s) for the API
 *   interrupt. The code can indicate more than one type of interrupt at
 *   the same time. Valid flags are found in @ref vcpx_status
 *****************************************************************************/
uint32_t Get_Callback_Source(void) large;

/**************************************************************************//**
 * @brief
 *   Returns the VCPXpress library version.
 *
 * @return Library version
 *
 * Library version is returned in binary-coded decimal format.
 *
 *****************************************************************************/
uint16_t USB_Get_Library_Version(void) large;

/**************************************************************************//**
 * @brief
 *   Disables the USB interface.
 *
 *****************************************************************************/
void USB_Disable(void) large;

/**
 * @brief
 *   User API USB initialization function.
 *
 * @param p:
 *   Pointer to VCPXpress_Init_Typedef structure.  Not modified by this routine.
 *
 * The use of this initialization function is similar to that of the USB_Init
 * in the USBXpress library.  The primary differences are:
 *    - Addition of the useFifo parameter.
 *    - All parameters are placed in VCPXpress_Init_Typedef structure for code
 *      organization.
 *    - Calling USB_Clock_Start() is no longer required.  If the USB FIFO space
 *      is supported, the clock is started immediately prior to initialization
 *      of the VCP variables.  Otherwise, the clock is started in the USBD_Init
 *      routine (part of the efm8_usb library).
 *
 * To minimize user xdata use, the user should pass initialization parameters
 * from code memory to the USB_Init function.
 *
 *****************************************************************************/
void USB_Init(const VCPXpress_Init_TypeDef* p) large;

/**************************************************************************//**
 * @brief
 *   Suspends the USB interface.
 *
 *****************************************************************************/
void USB_Suspend(void) large;

// VCP-Specific external function prototypes.
// See AN571 for more details on data structures.

/**************************************************************************//**
 * @brief
 *   Gets the VCP baud rate.
 *
 * @param[out] userptr:
 *   Pointer for location to store the baud rate.
 *
 * User should call this function on VCP_CB_SET_BAUDRATE call-back if
 * host-commanded baud is desired.
 *
 * @note:
 *   Baud rate is given in 4-byte little-endian format.
 *   Example conversion to 32-bit number (requires le32toh from endian.h):
 *
 *       uint8_t baud_array[4];
 *       uint32_t baud_num;
 *       VCP_Get_Baudrate(&baud_array);
 *       baud_num = le32toh(*((uint32_t*) &baud_array));
 *
 *****************************************************************************/
void VCP_Get_Baudrate(uint8_t* userptr);

/**************************************************************************//**
 * @brief
 *   Gets the current special charactar encoding.
 *
 * @param[out] userptr:
 *   Pointer for location to store the char array.
 *
 * User should call this function on VCP_CB_SET_CHARS call-back if the
 * host-commanded special characters are desired.
 *
 * Return data is a 6 byte array.
 *
 * |Byte| Name       | Description                                           |
 * |----|------------|-------------------------------------------------------|
 * |  0 | bEofChar   | EOF character (on the input)
 * |  1 | bErrorChar | Character that should be inserted when an error occurs
 * |  2 | bBreakChar | Character to insert when a break is detected
 * |  3 | bEventChar | Character that causes bit 2 of the event-occurred mask to be set
 * |  4 | bXonChar   | Character for XON
 * |  5 | bXoffChar  | Character for XOFF
 *
 *****************************************************************************/
void VCP_Get_Chars(uint8_t* userptr);

/**************************************************************************//**
 * @brief
 *   Gets the VCP embedded event.
 *
 * @param[out] userptr:
 *   Pointer for location to store the event.
 *
 * User should call this function on VCP_CB_EMBED_EVENTS call-back if the
 * host-commanded embedded event is desired.
 *
 * The data returned is a value between 0x00 and 0xFF. If 0x00 then no embedded
 * events are in the data stream. If another value then that is the value of the
 * escape character used for embedded events. See AN571 for further details on
 * embedded events.
 *
 *****************************************************************************/
void VCP_Get_EmbeddedEvent(uint16_t* userptr);

/**************************************************************************//**
 * @brief
 *   Gets the VCP event mask.
 *
 * @param[out] userptr:
 *   Pointer for location to store the event mask.
 *
 * User should call this function on VCP_CB_SET_EVENTMASK call-back if the
 * host-commanded event mask is desired.
 *
 * The returned 16 bit value is decoded as:
 *
 * |Bit | Description                                           |
 * |----|-------------------------------------------------------|
 * |  0 | RI trailing edge occured
 * |  1 | RESERVED
 * |  2 | The receive buffer is 80% full
 * |7:3 | RESERVED
 * |  8 | Character received
 * |  9 | Special character received
 * | 10 | Transmit queue empty
 * | 11 | CTS state changed
 * | 12 | DSR state changed
 * | 13 | DCD state changed
 * | 14 | Line break received
 * | 15 | Line-status error
 *
 *****************************************************************************/
void VCP_Get_Eventmask(uint16_t* userptr);

/**************************************************************************//**
 * @brief
 *   Gets the VCP event state.
 *
 * @param[out] userptr:
 *   Pointer for location to store the event state.
 *
 * User should call this function on VCP_CB_SET_EVENTSTATE call-back if the
 * host-commanded event state is desired.
 *
 * The Event state data is encode the same as in VCP_Get_Eventmask()
 *
 *****************************************************************************/
void VCP_Get_Eventstate(uint16_t* userptr);

/**************************************************************************//**
 * @brief
 *   Gets the VCP flow control state.
 *
 * @param[out] userptr:
 *   Pointer for location to store the flow control state array.
 *
 * User should call this function on VCP_CB_SET_FLOW call-back if the
 * host-commanded flow control state is desired.
 *
 * The returned data is an 18 byte structure of the form:
 *
 * |Byte | Name              | Description                                           |
 * |-----|-------------------|-------------------------------------------------------|
 * |  3:0| ulControllHanshake| (See AN571)
 * |  7:4| ulFlowReplace     | (See An571)
 * | 11:8| ulXonLimit        | Threshold for sending Xon
 * |15:12| ulXoffLimit       | Threshold for sending Xoff
 *
 *****************************************************************************/
void VCP_Get_FlowControl(uint8_t* userptr);

/**************************************************************************//**
 * @brief
 *   Gets the VCP immediate character.
 *
 * @param[out] userptr:
 *   Pointer for location to store the immediate character.
 *
 * User should call this function on VCP_CB_IMM_CHAR call-back if the
 * host-commanded immediate character value is desired.
 *
 * Signals the pointed to character should be sent immediately bypassing any other
 * data in the pipe.
 *
 *****************************************************************************/
void VCP_Get_ImmChar(uint8_t* userptr);

/**************************************************************************//**
 * @brief
 *   Gets the VCP line control state.
 *
 * @param[out] userptr:
 *   Pointer for location to store the line control state byte.
 *
 * User should call this function on VCP_CB_SET_LINE_CTL call-back if the
 * host-commanded line control state is desired.
 *
 * Returned 16 bits is decoded as follows (refer to AN571 for more details)
 *
 * |Bit | Description                                           |
 * |----|-------------------------------------------------------|
 * | 3:0| Stop Bits (1=1.5)
 * | 7:4| Parity
 * |15:8| word length (must be 5-8)
 *
 *****************************************************************************/
void VCP_Get_LineControl(uint16_t* userptr);

/**************************************************************************//**
 * @brief
 *   Gets the VCP modem handshaking states.
 *
 * @param[out] userptr:
 * Pointer for location to store the modem handshake state byte.
 *
 * User should call this function on VCP_CB_SET_MHS call-back if the
 * host-commanded modem handshaking states are desired.
 *
 * Returned 16 bits is decoded as follows (refer to AN571 for more details)
 *
 * |Bit  | Description                                           |
 * |-----|-------------------------------------------------------|
 * |    0| DTR state
 * |    1| RTS state
 * |  7:2| RESERVED
 * |    8| DTR mask
 * |    9| RTS mask
 * |15:10| RESERVED
 *
 *****************************************************************************/
void VCP_Get_ModemStatus(uint8_t* userptr);

/**************************************************************************//**
 * @brief
 *   Gets the VCP baud rate.
 *
 * @param[in] userptr:
 *   Pointer for location to store the baud rate.
 *
 * User should call this function on VCP_CB_SET_BAUDRATE call-back if
 * host-commanded baud is desired.
 *
 * See VCP_Get_Baudrate() for encoding.
 *
 * @note:
 *   Baud rate should be provided in 4-byte little-endian format.
 *   Example conversion from 32-bit number (requires htole32 from endian.h):
 *
 *       uint8_t baud_array[4];
 *       uint32_t baud_num = 115200;
 *       *((uint32_t*) &baud_array) = htole32(baud_num);
 *       VCP_Set_Baudrate(&baud_array);
 *
 *****************************************************************************/
void VCP_Set_Baudrate(uint8_t* userptr);

/**************************************************************************//**
 * @brief
 *   Sets the VCP special characters.
 *
 * @param[in] userptr:
 *   Pointer for location where the user special characters array is stored
 *
 * Note that this will only have an effect if the host requests the characters
 * via a GET_CHARS control command as defined in AN571.
 *
 * See VCP_Get_Chars() for encoding.
 *
 *****************************************************************************/
void VCP_Set_Chars(uint8_t* userptr);

/**************************************************************************//**
 * @brief
 *   Sets the VCP event mask.
 *
 * @param[in] userptr:
 *   Pointer for location where the user event mask is stored.
 *
 * Note that this will only have an effect if the host requests the event mask
 * via a GET_EVENTMASK control command as defined in AN571.
 *
 * See VCP_Get_Eventmask() for encoding.
 *
 *****************************************************************************/
void VCP_Set_Eventmask(uint16_t* userptr);

/**************************************************************************//**
 * @brief
 *   Sets the VCP event state.
 * @param[in] userptr:
 *   Pointer for location where the user event state is stored.
 *
 * Note that this will only have an effect if the host requests the event state
 * via a GET_EVENTSTATE control command as defined in AN571.
 *
 * See VCP_Get_Eventstate() for encoding.
 *
 *****************************************************************************/
void VCP_Set_Eventstate(uint16_t* userptr);

/**************************************************************************//**
 * @brief
 *   Sets the VCP flow control state.
 *
 * @param[in] userptr:
 *   Pointer for location where the user flow control state array is stored.
 *
 * Note that this will only have an effect if the host requests the flow
 * control state via a GET_FLOW control command as defined in AN571.
 *
 * See  VCP_Get_FlowControl() for encoding.
 *
 *****************************************************************************/
void VCP_Set_FlowControl(uint8_t* userptr);

/**************************************************************************//**
 * @brief
 *   Sets the VCP modem status state.
 *
 * @param[in] userptr:
 *   Pointer for location where the user flow control state array is stored.
 *
 * Note that this will only have an effect if the host requests the flow
 * control state via a GET_FLOW control command as defined in AN571.
 *
 * |Byte | Name              | Description                                           |
 * |-----|-------------------|-------------------------------------------------------|
 * |  3:0| ulErrors          | Current error status(See AN571)
 * |  7:4| ulHoldReasons     | Reason for holding (See An571)
 * | 11:8| ulAmountInInQueue | Number of bytes in input queue
 * |15:12| ulAmountInOutQueue| Number of bytes in output queue
 * |   16| bEofReceived      | Alwasy 0
 * |   17| bwaitForImmediate | 0x1 if wating for an immediate transmission
 * |   18| bReserved         | Reserved
 *
 *****************************************************************************/
void VCP_Set_CommStatus(uint8_t* userptr);

/**************************************************************************//**
 * @brief
 *   Sets the VCP line control state.
 *
 * @param[in] userptr:
 *   Pointer for location where the user line control state byte is stored.
 *
 * Note that this will only have an effect if the host requests the line
 * control state via a GET_LINE_CTL control command as defined in AN571.
 *
 * See  VCP_Set_LineControl() for encoding.
 *
 *****************************************************************************/
void VCP_Get_LineControl(uint16_t* userptr);

/**************************************************************************//**
 * @brief
 *   Sets the VCP modem control line status.
 *
 * @param[in] userptr:
 *   Pointer for location where the user modem control line status byte is stored
 *
 * Note that this will only have an effect if the host requests the modem
 * status via a GET_MDMSTS control command as defined in AN571.
 *
 * See  VCP_Get_ModemStatus() for encoding.
 *
 *****************************************************************************/
void VCP_Set_ModemStatus(uint8_t* userptr);

/**  @} (end vcpx_func Functions) */

/**  @} (end addtogroup vcpxpress VCPXpress) */
#endif  /* _VCPXPRESS_H_ */
