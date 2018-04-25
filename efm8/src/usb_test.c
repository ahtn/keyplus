// Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
//
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// With modifications by:
// jem@seethis (c) 2018

#include "usb_test.h"

#include "peripheral_driver/inc/usb_0.h"

#include "usb_defs.h"
#include "usb_desc/descriptors.h"

// #include "lib/efm8_usb/inc/efm8_usb.h"

#include "efm8_util/delay.h"
#include "efm8_sfr.h"

#define GetEp(epAddr)  (\
    epAddr == EP0    ? &ep0    : \
    epAddr == EP1IN  ? &ep1in  : \
    epAddr == EP2IN  ? &ep2in  : \
    epAddr == EP3IN  ? &ep3in  : \
    epAddr == EP3OUT ? &ep3out : &ep0 \
    )

static XRAM uint8_t s_usb_state;
static XRAM uint8_t s_usb_saved_state;
static XRAM uint8_t s_configuration;
static XRAM ep0String_type ep0String;

static XRAM USBD_Ep_TypeDef ep0;
static XRAM USBD_Ep_TypeDef ep1in;
static XRAM USBD_Ep_TypeDef ep2in;
static XRAM USBD_Ep_TypeDef ep3in;
static XRAM USBD_Ep_TypeDef ep3out;
// static XRAM USBD_Ep_TypeDef ep1out;
static XRAM USB_Setup_TypeDef setup;

static const ROM uint8_t txZero[2];

uint8_t XRAM keyboardReport[8] = {0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00};

static USB_Status_TypeDef ClearFeature(void);

#if (SLAB_USB_EP1IN_USED)
void handleUsbIn1Int(void);
#endif // SLAB_USB_EP1IN_USED
#if (SLAB_USB_EP2IN_USED)
void handleUsbIn2Int(void);
#endif // SLAB_USB_EP2IN_USED
#if (SLAB_USB_EP3IN_USED)
void handleUsbIn3Int(void);
#endif // SLAB_USB_EP3IN_USED

void USBD_Connect(void) {
    USB_SaveSfrPage();
    ep0.state = D_EP_IDLE;
    USB_EnablePullUpResistor();
    USB_EnableTransceiver();
    USB_RestoreSfrPage();
}

void USBD_Disconnect(void) {
    USB_SaveSfrPage();
    USB_DisablePullUpResistor();
    USB_RestoreSfrPage();
}

uint8_t usb_init(void) {
    USB_SaveSfrPage();
    USB_DisableInts();

    // Enable USB clock, full speed
    USB_SetClockIntOsc();
    USB_SelectFullSpeed();

    // Enable or disable VBUS detection
#if SLAB_USB_BUS_POWERED
    USB_VbusDetectDisable();
#else
    USB_VbusDetectEnable();
#endif

    // Rest hardware controller
    USB_ForceReset();
    USB_EnableDeviceInts();

    // Attach to the USB host
    USBD_Connect();

    // If VBUS is present, the state should be Default.
    // Otherwise, it is Attached.
#if SLAB_USB_BUS_POWERED
    s_usb_state = USBD_STATE_DEFAULT;
#else
    if (USB_IsVbusOn()) {
        s_usb_state = USBD_STATE_DEFAULT;
    }
    else {
        s_usb_state = USBD_STATE_ATTACHED;
    }
#endif

    // Only enable USB interrupts when not in polled mode
#if (SLAB_USB_POLLED_MODE == 0)
    USB_EnableInts();
#endif

    USB_RestoreSfrPage();
    USB_DisableInhibit();

    return USB_STATUS_OK;
}

static USB_Status_TypeDef SetAddress(void) {
    USB_Status_TypeDef retVal = USB_STATUS_REQ_ERR;

    if ((setup.wValue < 128)
        && (setup.wLength == 0)
        && (setup.bmRequestType.Recipient == USB_SETUP_RECIPIENT_DEVICE)
        && (setup.wIndex == 0))
    {
        // If the device is in the Default state and the address is non-zero, put
        // the device in the Addressed state.
        if (s_usb_state == USBD_STATE_DEFAULT) {
            if (setup.wValue != 0) {
                USBD_SetUsbState(USBD_STATE_ADDRESSED);
            }
            retVal = USB_STATUS_OK;
        }
        // If the device is already addressed and the address is zero, put the
        // device in the Default state.
        else if (s_usb_state == USBD_STATE_ADDRESSED) {
            if (setup.wValue == 0) {
                USBD_SetUsbState(USBD_STATE_DEFAULT);
            }
            retVal = USB_STATUS_OK;
        }

        // Set the new address if the request was valid.
        if (retVal == USB_STATUS_OK) {
            USB_SetAddress(setup.wValue);
        }
    }

    return retVal;
}

int8_t USBD_AbortTransfer(uint8_t epAddr)
{
    XRAM USBD_Ep_TypeDef *ep;
    int8_t retVal = USB_STATUS_OK;
    bool usbIntsEnabled;

    USB_SaveSfrPage();

    // Verify this is a valid endpoint address and is not Endpoint 0.
    if ((epAddr == EP0) || (epAddr >= SLAB_USB_NUM_EPS_USED))
    {
        SLAB_ASSERT(false);
        retVal = USB_STATUS_ILLEGAL;
    }
    else
    {
        DISABLE_USB_INTS;
        ep = GetEp(epAddr);

        // If the state of the endpoint is already idle, there is not need to abort
        // a transfer
        if (ep->state != D_EP_IDLE)
        {
            switch (epAddr)
            {
#if SLAB_USB_EP1IN_USED
                case EP1IN: USB_AbortInEp(1); break;
#endif
#if SLAB_USB_EP2IN_USED
                case EP2IN: USB_AbortInEp(2); break;
#endif
#if SLAB_USB_EP3IN_USED
                case EP3IN: USB_AbortInEp(3); break;
#endif
#if SLAB_USB_EP1OUT_USED
                case EP1OUT: USB_AbortOutEp(1); break;
#endif
#if SLAB_USB_EP2OUT_USED
                case EP2OUT: USB_AbortOutEp(2); break;
#endif
#if SLAB_USB_EP3OUT_USED
                case EP3OUT: USB_AbortOutEp(3); break;
#endif
            }

            // Set the endpoint state to idle and clear out endpoint state variables
            ep->state = D_EP_IDLE;
            ep->misc.c = 0;
        }
    }

    ENABLE_USB_INTS;
    USB_RestoreSfrPage();

    return retVal;
}


void USBD_AbortAllTransfers(void) {
    uint8_t i;
    bool usbIntsEnabled;

    USB_SaveSfrPage();
    DISABLE_USB_INTS;

    // Call USBD_AbortTransfer() for each endpoint
    for (i = 1; i < SLAB_USB_NUM_EPS_USED; i++)
    {
        USBD_AbortTransfer(i);
    }

    ENABLE_USB_INTS;
    USB_RestoreSfrPage();
}

static void USBD_ActivateAllEps(bool forceIdle) {
    if (forceIdle == true) {
#if SLAB_USB_EP1IN_USED
        ep1in.state = D_EP_IDLE;
#endif
#if SLAB_USB_EP2IN_USED
        ep2in.state = D_EP_IDLE;
#endif
#if SLAB_USB_EP3IN_USED
        ep3in.state = D_EP_IDLE;
#endif
#if SLAB_USB_EP1OUT_USED
        ep1out.state = D_EP_IDLE;
#endif
#if SLAB_USB_EP2OUT_USED
        ep2out.state = D_EP_IDLE;
#endif
#if SLAB_USB_EP3OUT_USED
        ep3out.state = D_EP_IDLE;
#endif
    }

#if SLAB_USB_EP1IN_USED
    USB_ActivateEp(1,                                        // ep
        SLAB_USB_EP1IN_MAX_PACKET_SIZE,                      // packetSize
        1,                                                   // inDir
        SLAB_USB_EP1OUT_USED,                                // splitMode
        0);                                                  // isoMod
#endif // SLAB_USB_EP1IN_USED
#if SLAB_USB_EP2IN_USED
    USB_ActivateEp(2,                                        // ep
        SLAB_USB_EP2IN_MAX_PACKET_SIZE,                      // packetSize
        1,                                                   // inDir
        SLAB_USB_EP2OUT_USED,                                // splitMode
        0);                                                  // isoMod
#endif // SLAB_USB_EP2IN_USED
#if SLAB_USB_EP3IN_USED
    USB_ActivateEp(3,                                        // ep
        SLAB_USB_EP3IN_MAX_PACKET_SIZE,                      // packetSize
        1,                                                   // inDir
        SLAB_USB_EP3OUT_USED,                                // splitMode
        (SLAB_USB_EP3IN_TRANSFER_TYPE == USB_EPTYPE_ISOC));  // isoMod
#endif // SLAB_USB_EP3IN_USED
#if SLAB_USB_EP1OUT_USED
    USB_ActivateEp(1,                                        // ep
        SLAB_USB_EP1OUT_MAX_PACKET_SIZE,                     // packetSize
        0,                                                   // inDir
        SLAB_USB_EP1IN_USED,                                 // splitMode
        0);                                                  // isoMod
#endif // SLAB_USB_EP1OUT_USED
#if SLAB_USB_EP2OUT_USED
    USB_ActivateEp(2,                                                   // ep
        SLAB_USB_EP2OUT_MAX_PACKET_SIZE,                     // packetSize
        0,                                                   // inDir
        SLAB_USB_EP2IN_USED,                                 // splitMode
        0);                                                  // isoMod
#endif // SLAB_USB_EP2OUT_USED
#if SLAB_USB_EP3OUT_USED
    USB_ActivateEp(3,                                                   // ep
        SLAB_USB_EP3OUT_MAX_PACKET_SIZE,                     // packetSize
        0,                                                   // inDir
        SLAB_USB_EP3IN_USED,                                 // splitMode
        (SLAB_USB_EP3OUT_TRANSFER_TYPE == USB_EPTYPE_ISOC)); // isoMod
#endif // SLAB_USB_EP1OUT_USED
}

static USB_Status_TypeDef SetConfiguration(void) {
    USB_Status_TypeDef retVal = USB_STATUS_REQ_ERR;

    if (((setup.wValue >> 8) == 0)
        && (setup.bmRequestType.Recipient == USB_SETUP_RECIPIENT_DEVICE)
        && (setup.wLength == 0)
        && (setup.wIndex == 0))
    {
        // If the device is in the Addressed state and a valid Configuration value
        // was sent, enter the Configured state.
        if (s_usb_state == USBD_STATE_ADDRESSED) {
            if ((setup.wValue == 0)
                || (setup.wValue == usb_config_desc.conf.bConfigurationValue)
            ) {
                s_configuration = setup.wValue;
                if (setup.wValue == usb_config_desc.conf.bConfigurationValue) {
                    USBD_ActivateAllEps(true);
                    USBD_SetUsbState(USBD_STATE_CONFIGURED);
                }
                retVal = USB_STATUS_OK;
            }
        }
        // If the device is in the Configured state and Configuration zero is sent,
        // abort all transfer and enter the Addressed state.
        else if (s_usb_state == USBD_STATE_CONFIGURED) {
            if ((setup.wValue == 0)
                || (setup.wValue == usb_config_desc.conf.bConfigurationValue)
            ) {
                s_configuration = setup.wValue;
                if (setup.wValue == 0) {
                    USBD_SetUsbState(USBD_STATE_ADDRESSED);
                    USBD_AbortAllTransfers();
                } else {
                    // Reenable device endpoints, will reset data toggles
                    USBD_ActivateAllEps(false);
                }
                retVal = USB_STATUS_OK;
            }
        }
    }

    return retVal;
}

static void EP0_Write(uint8_t *dat, uint16_t numBytes) {
    if (ep0.state == D_EP_IDLE) {
        ep0.buf = dat;
        ep0.remaining = numBytes;
        ep0.state = D_EP_TRANSMITTING;
        ep0.misc.c = 0;
    }
}

static USB_Status_TypeDef GetDescriptor(void) {
#if (SLAB_USB_NUM_LANGUAGES > 1)
    bool langSupported;
    uint8_t lang;
#endif

    uint8_t index;
    uint16_t length = 0;
    uint8_t *dat;
    USB_Status_TypeDef retVal = USB_STATUS_REQ_ERR;

    if (*((uint8_t *)&setup.bmRequestType) ==
        (USB_SETUP_DIR_D2H | USB_SETUP_TYPE_STANDARD | USB_SETUP_RECIPIENT_DEVICE)
    ) {
        index = setup.wValue & 0xFF;

        switch (setup.wValue >> 8) {
            case USB_DEVICE_DESCRIPTOR: {
                if (index != 0) {
                    break;
                }
                dat = (uint8_t*)&usb_device_desc;
                length = sizeof(usb_device_desc_t);
            } break;

            case USB_CONFIG_DESCRIPTOR: {
                if (index != 0) {
                    break;
                }
                dat = (uint8_t*)&usb_config_desc;
                length = sizeof(usb_config_desc);
            } break;

#if 0
            case USB_STRING_DESCRIPTOR: {
#if (SLAB_USB_NUM_LANGUAGES == 1)

                dat = (SI_VARIABLE_SEGMENT_POINTER(, uint8_t, SI_SEG_GENERIC))stringDescriptors[index];

                // Index 0 is the language string. If SLAB_USB_NUM_LANGUAGES == 1, we
                // know the length will be 4 and the format will be UTF16LE.
                if (index == 0) {
                    length = 4;
                    ep0String.encoding.type = USB_STRING_DESCRIPTOR_UTF16LE;
                }
                // Otherwise, verify the language is correct (either the value set as
                // SLAB_USB_LANGUAGE in usbconfig.h, or 0).
                else if ((setup.wIndex == 0) || (setup.wIndex == SLAB_USB_LANGUAGE)) {
                    // Verify the index is valid
                    if (index < numberOfStrings) {
                        length = *(dat + USB_STRING_DESCRIPTOR_LENGTH);
                        ep0String.encoding.type = *(dat + USB_STRING_DESCRIPTOR_ENCODING);
                        dat += USB_STRING_DESCRIPTOR_LENGTH;
                        ep0String.encoding.init = true;
                    }
                }
#elif (SLAB_USB_NUM_LANGUAGES > 1)

                langSupported = false;

                // Index 0 is the language.
                if (index == 0) {
                    dat = ((SI_VARIABLE_SEGMENT_POINTER(, uint8_t, SI_SEG_GENERIC))stringDescriptors->languageArray[0][index]);
                    length = *((uint8_t *)dat);
                    ep0String.encoding.type = USB_STRING_DESCRIPTOR_UTF16LE;
                } else {
                    // Otherwise, verify the language is one of the supported languages or 0.
                    for (lang = 0; lang < SLAB_USB_NUM_LANGUAGES; lang++) {
                        if ((stringDescriptors->languageIDs[lang] == setup.wIndex)
                            || (stringDescriptors->languageIDs[lang] == 0)
                        ) {
                            langSupported = true;
                            break;
                        }
                    }
                    if ((langSupported == true) && (index < numberOfStrings)) {
                        dat = ((SI_VARIABLE_SEGMENT_POINTER(, uint8_t, SI_SEG_GENERIC))stringDescriptors->languageArray[lang][index]);
                        length = *(dat + USB_STRING_DESCRIPTOR_LENGTH);
                        ep0String.encoding.type = *(dat + USB_STRING_DESCRIPTOR_ENCODING);
                        dat += USB_STRING_DESCRIPTOR_LENGTH;

                        if (ep0String.encoding.type == USB_STRING_DESCRIPTOR_UTF16LE_PACKED) {
                            ep0String.encoding.init = true;
                        } else {
                            ep0String.encoding.init = false;
                        }
                    }
                }
#endif // ( SLAB_USB_NUM_LANGUAGES == 1 )
            } break;
#endif
        }

        // If there is a descriptor to send, get the proper length, then call
        // EP0_Write() to send.
        if (length) {
            // If length != 0, then dat is defined
            if (length > setup.wLength) {
                length = setup.wLength;
            }

            EP0_Write(dat, length);

            retVal = USB_STATUS_OK;
        }
    }

    return retVal;
}


USB_Status_TypeDef USBDCH9_SetupCmd(void) {
    USB_Status_TypeDef status = USB_STATUS_OK;

    switch (setup.bRequest) {
#if 0
        case GET_STATUS:
            status = GetStatus();
            break;

        case CLEAR_FEATURE:
            status = ClearFeature();
            break;

        case SET_FEATURE:
            status = SetFeature();
            break;
#endif

        case SET_ADDRESS:
            status = SetAddress();
            break;

        case GET_DESCRIPTOR:
            status = GetDescriptor();
            break;
#if 0

        case GET_CONFIGURATION:
            status = GetConfiguration();
            break;
#endif

        case SET_CONFIGURATION:
            status = SetConfiguration();
            break;

#if 0
        case GET_INTERFACE:
            status = GetInterface();
            break;

        case SET_INTERFACE:
            status = SetInterface();
            break;
#endif

        default:
            status = USB_STATUS_REQ_ERR;
            break;
    }

    return status;
}

/***************************************************************************//**
 * @brief       Reads data from the USB FIFO to a buffer in generic memory space
 * @param       numBytes
 *              Number of bytes to read from the FIFO
 * @param       dat
 *              Pointer to generic buffer to hold data read from the FIFO
 * @param       fifoNum
 *              USB FIFO to read
 ******************************************************************************/
void USB_ReadFIFO(uint8_t fifoNum, uint8_t numBytes, uint8_t *dat) {
    if (numBytes > 0) {
        USB_EnableReadFIFO(fifoNum);

        // Read the bytes of the FIFO into dat
        while (--numBytes) {
            USB_GetFIFOByte(dat);
            dat++;
        }
        USB_GetLastFIFOByte(dat, fifoNum);

        USB_DisableReadFIFO(fifoNum);
    }
}

void USB_WriteFIFO(uint8_t fifoNum, uint8_t numBytes, uint8_t *dat, bool txPacket) {
    USB_EnableWriteFIFO(fifoNum);

    // Write the bytes of the FIFO int dat
    while (numBytes--) {
        USB_SetFIFOByte(*dat);
        dat++;
    }

    USB_DisableWriteFIFO(fifoNum);

    if ((txPacket == true) && (fifoNum > 0)) {
        USB_SetIndex(fifoNum);
        USB_EpnSetInPacketReady();
    }
}

bool USBD_EpIsBusy(uint8_t epAddr) {
    XRAM USBD_Ep_TypeDef *ep;

    // Verify this is a valid endpoint address
    if (epAddr >= SLAB_USB_NUM_EPS_USED) {
        SLAB_ASSERT(false);
        return true;
    }

    ep = GetEp(epAddr);

    if (ep->state == D_EP_IDLE) {
        return false;
    }

    return true;
}

void SendEp0Stall(void) {
    USB_SetIndex(0);
    ep0.state = D_EP_STALL;
    USB_Ep0SendStall();
}

/***************************************************************************//**
 * @brief       Reads and formats a setup packet
 ******************************************************************************/
static void USB_ReadFIFOSetup(void) {
    XRAM uint16_t *ptr = (XRAM uint16_t*)&setup;
    USB_ReadFIFO(EP0, 8, ptr);
}

static void handleUsbEp0Tx(void) {
    uint8_t count, count_snapshot, i;
    bool callback = ep0.misc.bits.callback;

    // The number of bytes to send in the next packet must be less than or equal
    // to the maximum EP0 packet size.
    count = (ep0.remaining >= USB_EP0_SIZE) ?
        USB_EP0_SIZE : ep0.remaining;

    // Save the packet size for future use.
    count_snapshot = count;

    // Strings can use the USB_STRING_DESCRIPTOR_UTF16LE_PACKED type to pack
    // UTF16LE data without the zero's between each character.
    // If the current string is of type USB_STRING_DESCRIPTOR_UTF16LE_PACKED,
    // unpack it by inserting a zero between each character in the string.
    if ((ep0String.encoding.type == USB_STRING_DESCRIPTOR_UTF16LE_PACKED)
#if SLAB_USB_UTF8_STRINGS == 1
        || (ep0String.encoding.type == USB_STRING_DESCRIPTOR_UTF8)
#endif
       )
    {
        // If ep0String.encoding.init is true, this is the beginning of the string.
        // The first two bytes of the string are the bLength and bDescriptorType
        // fields. These are not packed like the reset of the string, so write them
        // to the FIFO and set ep0String.encoding.init to false.
        if (ep0String.encoding.init == true) {
            USB_WriteFIFO(EP0, 2, ep0.buf, false);
            ep0.buf += 2;
            count -= 2;
            ep0String.encoding.init = false;
        }

        // Insert a 0x00 between each character of the string.
        for (i = 0; i < count / 2; i++) {
#if SLAB_USB_UTF8_STRINGS == 1
            if (ep0String.encoding.type == USB_STRING_DESCRIPTOR_UTF8) {
                uint16_t ucs2;
                uint8_t utf8count;

                // decode the utf8 into ucs2 for usb string
                utf8count = decodeUtf8toUcs2(ep0.buf, &ucs2);

                // if consumed utf8 bytes is 0, it means either null byte was
                // input or bad utf8 byte sequence.  Either way its an error and
                // there's not much we can do.  So just advance the input string
                // by one character and keep going until count is expired.
                if (utf8count == 0)
                {
                    utf8count = 1;
                }

                // adjust to next char in utf8 byte sequence
                ep0.buf += utf8count;
                ucs2 = htole16(ucs2); // usb 16-bit chars are little endian
                USB_WriteFIFO(EP0, 2, &ucs2, false);
            }
            else
#endif
            {
                USB_WriteFIFO(EP0, 1, ep0.buf, false);
                ep0.buf++;
                USB_WriteFIFO(EP0, 1, txZero, false);
            }
        }
    } else {
        // For any data other than USB_STRING_DESCRIPTOR_UTF16LE_PACKED, just send the
        // data normally.
        USB_WriteFIFO(EP0, count, ep0.buf, false);
        ep0.buf += count;
    }

    ep0.misc.bits.inPacketPending = false;
    ep0.remaining -= count_snapshot;

    // If the last packet of the transfer is exactly the maximum EP0 packet size,
    // we will have to send a ZLP (zero-length packet) after the last data packet
    // to signal to the host that the transfer is complete.
    // Check for the ZLP packet case here.
    if ((ep0.remaining == 0) && (count_snapshot != USB_EP0_SIZE)) {
        USB_Ep0SetLastInPacketReady();
        ep0.state = D_EP_IDLE;
        ep0String.c = USB_STRING_DESCRIPTOR_UTF16LE;
        ep0.misc.c = 0;
    } else {
        // Do not call USB_Ep0SetLastInPacketReady() because we still need to send
        // the ZLP.
        USB_Ep0SetInPacketReady();
    }
}

/***************************************************************************//**
 * @brief       Handles receive data phase on Endpoint 0
 ******************************************************************************/
void handleUsbEp0Rx(void) {
    uint8_t count;
    USB_Status_TypeDef status;
    bool callback = ep0.misc.bits.callback;

    // Get the number of bytes received
    count = USB_Ep0GetCount();

    // If the call to USBD_Read() did not give a large enough buffer to hold this
    // data, set the outPacketPending flag and signal an RX overrun.
    if (ep0.remaining < count) {
        ep0.state = D_EP_IDLE;
        ep0.misc.bits.outPacketPending = true;
        status = USB_STATUS_EP_RX_BUFFER_OVERRUN;
    } else {
        USB_ReadFIFO(EP0, count, ep0.buf);
        ep0.buf += count;
        ep0.remaining -= count;
        status = USB_STATUS_OK;

        // If the last packet of the transfer is exactly the maximum EP0 packet
        // size, we will must wait to receive a ZLP (zero-length packet) after the
        // last data packet. This signals that the host has completed the transfer.
        // Check for the ZLP packet case here.
        if ((ep0.remaining == 0) && (count != USB_EP0_SIZE)) {
            USB_Ep0SetLastOutPacketReady();
            ep0.state = D_EP_IDLE;
            ep0.misc.bits.callback = false;
        } else {
            // Do not call USB_Ep0SetLastOutPacketReady() until we get the ZLP.
            USB_Ep0ServicedOutPacketReady();
        }
    }
}

/***************************************************************************//**
 * @brief       Handles Endpoint 0 transfer interrupt
 ******************************************************************************/
static void handleUsbEp0Int(void) {
    USB_Status_TypeDef retVal = USB_STATUS_REQ_UNHANDLED;

    USB_SetIndex(0);

    if (USB_Ep0SentStall() || USB_GetSetupEnd()) {
        USB_Ep0ClearSentStall();
        USB_ServicedSetupEnd();
        ep0.state = D_EP_IDLE;
        ep0.misc.c = 0;
    }

    if (USB_Ep0OutPacketReady()) {
        if (ep0.misc.bits.waitForRead == true) {
            ep0.misc.bits.outPacketPending = true;
        } else if (ep0.state == D_EP_IDLE) {
            // ep0String.c = USB_STRING_DESCRIPTOR_UTF16LE;
            USB_ReadFIFOSetup();

            // Vendor unique, Class or Standard setup commands override?
#if SLAB_USB_SETUP_CMD_CB
            retVal = USBD_SetupCmdCb(&setup);

            if (retVal == USB_STATUS_REQ_UNHANDLED) {
#endif
                if (setup.bmRequestType.Type == USB_SETUP_TYPE_STANDARD) {
                    retVal = USBDCH9_SetupCmd();
                }
#if SLAB_USB_SETUP_CMD_CB
            }
#endif

            // Reset index to 0 in case the call to USBD_SetupCmdCb() or
            // USBDCH9_SetupCmd() changed it.
            USB_SetIndex(0);

            // Put the Enpoint 0 hardware into the correct state here.
            if (retVal == USB_STATUS_OK) {
                // If wLength is 0, there is no Data Phase
                // Set both the Serviced Out Packet Ready and Data End bits
                if (setup.wLength == 0) {
                    USB_Ep0SetLastOutPacketReady();
                }
                // If wLength is non-zero, there is a Data Phase.
                // Set only the Serviced Out Packet Ready bit.
                else {
                    USB_Ep0ServicedOutPacketReady();

#if SLAB_USB_SETUP_CMD_CB
                    // If OUT packet but callback didn't set up a USBD_Read and we are expecting a
                    // data byte then we need to wait for the read to be setup and NACK packets until
                    // USBD_Read is called.
                    if ((setup.bmRequestType.Direction == USB_SETUP_DIR_OUT)
                        && (ep0.state != D_EP_RECEIVING)) {
                        ep0.misc.bits.waitForRead = true;
                    }
#endif
                }
            }
            // If the setup transaction detected an error, send a stall
            else {
                SendEp0Stall();
            }
        } else if (ep0.state == D_EP_RECEIVING) {
            handleUsbEp0Rx();
        } else {
            ep0.misc.bits.outPacketPending = true;
        }
    }

    if ((ep0.state == D_EP_TRANSMITTING) && (USB_Ep0InPacketReady() == 0)) {
        handleUsbEp0Tx();
    }
}

void handleUsbIn1Int(void) {
    bool callback;

    USB_SetIndex(1);

    if (USB_EpnInGetSentStall()) {
        USB_EpnInClearSentStall();
    } else if (ep1in.state == D_EP_TRANSMITTING) {
        uint8_t xferred;
        if (ep1in.remaining > SLAB_USB_EP1IN_MAX_PACKET_SIZE) {
            xferred = SLAB_USB_EP1IN_MAX_PACKET_SIZE;
        } else {
            xferred = ep1in.remaining;
        }
        ep1in.remaining -= xferred;
        ep1in.buf += xferred;

        callback = ep1in.misc.bits.callback;

        // Load more data
        if (ep1in.remaining > 0) {
            uint8_t num_bytes;
            if (ep1in.remaining > SLAB_USB_EP1IN_MAX_PACKET_SIZE) {
                num_bytes = SLAB_USB_EP1IN_MAX_PACKET_SIZE;
            } else {
                num_bytes = ep1in.remaining;
            }
            USB_WriteFIFO(1, num_bytes, ep1in.buf, true);
        } else {
            ep1in.misc.bits.callback = false;
            ep1in.state = D_EP_IDLE;
        }
    }
}

#if SLAB_USB_EP2IN_USED
/***************************************************************************//**
 * @brief       Handle Endpoint 2 IN transfer interrupt
 * @note        This function takes no parameters, but it uses the EP2IN status
 *              variables stored in @ref myUsbDevice.ep2in.
 ******************************************************************************/
void handleUsbIn2Int(void) {
    bool callback;

    USB_SetIndex(2);

    if (USB_EpnInGetSentStall()) {
        USB_EpnInClearSentStall();
    } else if (ep2in.state == D_EP_TRANSMITTING) {
        uint8_t xferred;
        if (ep2in.remaining > SLAB_USB_EP2IN_MAX_PACKET_SIZE) {
            xferred = SLAB_USB_EP2IN_MAX_PACKET_SIZE;
        } else {
            xferred = ep2in.remaining;
        }
        ep2in.remaining -= xferred;
        ep2in.buf += xferred;

        callback = ep2in.misc.bits.callback;

        // Load more data
        if (ep2in.remaining > 0) {
            uint8_t num_bytes;
            if (ep2in.remaining > SLAB_USB_EP2IN_MAX_PACKET_SIZE) {
                num_bytes = SLAB_USB_EP2IN_MAX_PACKET_SIZE;
            } else {
                num_bytes = ep2in.remaining;
            }
            USB_WriteFIFO(2, num_bytes, ep2in.buf, true);
        } else {
            ep2in.misc.bits.callback = false;
            ep2in.state = D_EP_IDLE;
        }
    }
}
#endif // SLAB_USB_EP2IN_USED

#if SLAB_USB_EP3IN_USED
void handleUsbIn3Int(void) {
    bool callback;

    USB_SetIndex(3);

    if (USB_EpnInGetSentStall()) {
        USB_EpnInClearSentStall();
    } else if (ep3in.state == D_EP_TRANSMITTING) {
        uint8_t xferred;

        if (ep3in.remaining > SLAB_USB_EP3IN_MAX_PACKET_SIZE) {
            xferred =SLAB_USB_EP3IN_MAX_PACKET_SIZE;
        } else {
            xferred = ep3in.remaining;
        }

        ep3in.remaining -= xferred;
        ep3in.buf += xferred;

        callback = ep3in.misc.bits.callback;
        // Load more data
        if (ep3in.remaining > 0) {
            uint8_t num_bytes;
            if (ep3in.remaining > SLAB_USB_EP3IN_MAX_PACKET_SIZE) {
                num_bytes = SLAB_USB_EP3IN_MAX_PACKET_SIZE;
            } else {
                num_bytes = ep3in.remaining;
            }
            USB_WriteFIFO(3, num_bytes, ep3in.buf, true);
        } else {
            ep3in.misc.bits.callback = false;
            ep3in.state = D_EP_IDLE;
        }
    }
}
#endif

#if SLAB_USB_EP3OUT_USED
void handleUsbOut3Int(void) {
    uint8_t count;
    USB_Status_TypeDef status;
    bool xferComplete = false;

    USB_SetIndex(3);

    if (USB_EpnOutGetSentStall()) {
        USB_EpnOutClearSentStall();
    } else if (USB_EpnGetOutPacketReady()) {
        count = USB_EpOutGetCount();

        // If USBD_Read() has not been called, return an error
        if (ep3out.state != D_EP_RECEIVING) {
            ep3out.misc.bits.outPacketPending = true;
            status = USB_STATUS_EP_ERROR;
        } else if (ep3out.remaining < count) {
            // Check for overrun of user buffer
            ep3out.state = D_EP_IDLE;
            ep3out.misc.bits.outPacketPending = true;
            status = USB_STATUS_EP_RX_BUFFER_OVERRUN;
        } else {
            USB_ReadFIFO(3, count, ep3out.buf);

            ep3out.misc.bits.outPacketPending = false;
            ep3out.remaining -= count;
            ep3out.buf += count;

            if ((ep3out.remaining == 0) ||
                (count != SLAB_USB_EP3OUT_MAX_PACKET_SIZE)
            ) {
                ep3out.state = D_EP_IDLE;
                xferComplete = true;
            }

            status = USB_STATUS_OK;
            USB_EpnClearOutPacketReady();
        }

        if (ep3out.misc.bits.callback == true) {
            if (xferComplete == true) {
                ep3out.misc.bits.callback = false;
            }
#if 0
            USBD_XferCompleteCb(EP3OUT, status, count, ep3out.remaining);
#endif
        }
    }
}
#endif

static void handleUsbResetInt(void) {
  // Setup EP0 to receive SETUP packets
  ep0.state = D_EP_IDLE;

  // Halt all other endpoints
#if SLAB_USB_EP1IN_USED
  ep1in.state = D_EP_HALT;
#endif
#if SLAB_USB_EP2IN_USED
  ep2in.state = D_EP_HALT;
#endif
#if SLAB_USB_EP3IN_USED
  ep3in.state = D_EP_HALT;
#endif
#if SLAB_USB_EP1OUT_USED
  ep1out.state = D_EP_HALT;
#endif
#if SLAB_USB_EP2OUT_USED
  ep2out.state = D_EP_HALT;
#endif
#if SLAB_USB_EP3OUT_USED
  ep3out.state = D_EP_HALT;
#endif

  // After a USB reset, some USB hardware configurations will be reset and must
  // be reconfigured.

  // Re-enable clock recovery
#if SLAB_USB_CLOCK_RECOVERY_ENABLED
  USB_EnableFullSpeedClockRecovery();
#endif

  // Re-enable USB interrupts
  USB_EnableSuspendDetection();
  USB_EnableDeviceInts();

  // If the device is bus-powered, always put it in the Default state.
  // If the device is self-powered and VBUS is present, put the device in the
  // Default state. Otherwise, put it in the Attached state.
#if (!SLAB_USB_BUS_POWERED) && \
    (!(SLAB_USB_PWRSAVE_MODE & USB_PWRSAVE_MODE_ONVBUSOFF))
  if (USB_IsVbusOn()) {
    USBD_SetUsbState(USBD_STATE_DEFAULT);
  } else {
    USBD_SetUsbState(USBD_STATE_ATTACHED);
  }
#else
  USBD_SetUsbState(USBD_STATE_DEFAULT);
#endif  // (!(SLAB_USB_PWRSAVE_MODE & USB_PWRSAVE_MODE_ONVBUSOFF))

#if SLAB_USB_RESET_CB
  // Make the USB Reset Callback
  USBD_ResetCb();
#endif
}

#if (SLAB_USB_POLLED_MODE == 0)
void usb_isr(void) __interrupt (USB0_IRQn) {
#else
void usb_isr(void) {
#endif
    uint8_t statusCommon, statusIn, statusOut, indexSave;

#if SLAB_USB_HANDLER_CB
    // Callback to user before processing
    USBD_EnterHandler();
#endif

    // Get the interrupt sources
    statusCommon = USB_GetCommonInts();
    statusIn = USB_GetInInts();
    statusOut = USB_GetOutInts();

#if SLAB_USB_POLLED_MODE
    if ((statusCommon == 0) && (statusIn == 0) && (statusOut == 0)) {
        return;
    }
#endif

    // Save the current index
    indexSave = USB_GetIndex();

    // Check Common USB Interrupts
    if (USB_IsSofIntActive(statusCommon)) {
#if SLAB_USB_SOF_CB
        USBD_SofCb(USB_GetSofNumber());
#endif // SLAB_USB_SOF_CB

        // Check for unhandled USB packets on EP0 and set the corresponding IN or
        // OUT interrupt active flag if necessary.
        if (
            ((ep0.misc.bits.outPacketPending == true) && (ep0.state == D_EP_RECEIVING)) ||
            ((ep0.misc.bits.inPacketPending == true) && (ep0.state == D_EP_TRANSMITTING))
            ) {
            USB_SetEp0IntActive(statusIn);
        }
    }


    // Check USB Endpoint 0 Interrupt
    if (USB_IsEp0IntActive(statusIn)) {
        handleUsbEp0Int();
    }


    // handle IN / OUT endpoint interrupts
#if SLAB_USB_EP3IN_USED
    if (USB_IsIn3IntActive(statusIn)) {
        handleUsbIn3Int();
    }
#endif  // EP3IN_USED

#if SLAB_USB_EP3OUT_USED
    if (USB_IsOut3IntActive(statusOut)) {
        handleUsbOut3Int();
    }
#endif  // EP3OUT_USED

#if SLAB_USB_EP2IN_USED
    if (USB_IsIn2IntActive(statusIn)) {
        handleUsbIn2Int();
    }
#endif  // EP2IN_USED

#if SLAB_USB_EP1IN_USED
    if (USB_IsIn1IntActive(statusIn)) {
        handleUsbIn1Int();
    }
#endif  // EP1IN_USED

#if SLAB_USB_EP2OUT_USED
    if (USB_IsOut2IntActive(statusOut)) {
        handleUsbOut2Int();
    }
#endif  // EP2OUT_USED

#if SLAB_USB_EP1OUT_USED
    if (USB_IsOut1IntActive(statusOut)) {
        handleUsbOut1Int();
    }
#endif  // EP1OUT_USED

    // Restore index
    USB_SetIndex(indexSave);
#if SLAB_USB_HANDLER_CB
    // Callback to user before exiting
    USBD_ExitHandler();
#endif

#if 0

    // Check Common USB Interrupts
    if (USB_IsSofIntActive(statusCommon)) {
#if SLAB_USB_SOF_CB
        USBD_SofCb(USB_GetSofNumber());
#endif // SLAB_USB_SOF_CB

        // Check for unhandled USB packets on EP0 and set the corresponding IN or
        // OUT interrupt active flag if necessary.
        if (((ep0.misc.bits.outPacketPending == true) && (ep0.state == D_EP_RECEIVING)) ||
            ((ep0.misc.bits.inPacketPending == true) && (ep0.state == D_EP_TRANSMITTING)))
        {
            USB_SetEp0IntActive(statusIn);
        }
        // Check for unhandled USB OUT packets and set the corresponding OUT
        // interrupt active flag if necessary.
#if SLAB_USB_EP1OUT_USED
        if ((ep1out.misc.bits.outPacketPending == true) && (ep1out.state == D_EP_RECEIVING))
        {
            USB_SetOut1IntActive(statusOut);
        }
#endif
#if SLAB_USB_EP2OUT_USED
        if ((ep2out.misc.bits.outPacketPending == true) && (ep2out.state == D_EP_RECEIVING))
        {
            USB_SetOut2IntActive(statusOut);
        }
#endif
#if SLAB_USB_EP3OUT_USED
        if ((ep3out.misc.bits.outPacketPending == true) && (ep3out.state == D_EP_RECEIVING))
        {
            USB_SetOut3IntActive(statusOut);
        }
#endif
#if (SLAB_USB_EP3IN_USED && (SLAB_USB_EP3IN_TRANSFER_TYPE == USB_EPTYPE_ISOC))
        if ((ep3in.misc.bits.inPacketPending == true) && (ep3in.state == D_EP_TRANSMITTING))
        {
            USB_SetIn3IntActive(statusIn);
        }
#endif
    }

#endif


    if (USB_IsResetIntActive(statusCommon)) {
        handleUsbResetInt();

        // If VBUS is not present on detection of a USB reset, enter suspend mode.
#if (SLAB_USB_PWRSAVE_MODE & USB_PWRSAVE_MODE_ONVBUSOFF)
        if (USB_IsVbusOn() == false) {
            USB_SetSuspendIntActive(statusCommon);
        }
#endif
    }

#if 0
    if (USB_IsResumeIntActive(statusCommon)) {
        handleUsbResumeInt();
    }

    if (USB_IsSuspendIntActive(statusCommon)) {
        handleUsbSuspendInt();
    }
#endif

    return;
}


void USBD_SetUsbState(USBD_State_TypeDef newState)
{

#if (SLAB_USB_SUPPORT_ALT_INTERFACES)
    uint8_t i;
#endif
    USBD_State_TypeDef currentState;

    currentState = s_usb_state;

    // If the device is un-configuring, disable the data endpoints and clear out
    // alternate interface settings
    if ((currentState >= USBD_STATE_SUSPENDED)
        && (newState < USBD_STATE_SUSPENDED)) {
        USBD_AbortAllTransfers();

#if (SLAB_USB_SUPPORT_ALT_INTERFACES)
        for (i = 0; i < SLAB_USB_NUM_INTERFACES; i++) {
            interfaceAltSetting[i] = 0;
        }
#endif
    }
    if (newState == USBD_STATE_SUSPENDED) {
        s_usb_saved_state = currentState;
    }

    s_usb_state = newState;

#if SLAB_USB_STATE_CHANGE_CB
    if (currentState != newState) {
        USBD_DeviceStateChangeCb(currentState, newState);
    }
#endif
}

int8_t USBD_Write(uint8_t epAddr, void *dat, uint16_t byteCount, bool callback) {
    bool usbIntsEnabled;
    XRAM USBD_Ep_TypeDef *ep;

    USB_SaveSfrPage();

    // Verify the endpoint address is valid.
    switch (epAddr) {
        case EP0:
#if SLAB_USB_EP1IN_USED
        case EP1IN:
#endif
#if SLAB_USB_EP2IN_USED
        case EP2IN:
#endif
#if SLAB_USB_EP3IN_USED
        case EP3IN:
#endif
            break;
#if SLAB_USB_EP1OUT_USED
        case EP1OUT:
#endif
#if SLAB_USB_EP2OUT_USED
        case EP2OUT:
#endif
#if SLAB_USB_EP3OUT_USED
        case EP3OUT:
#endif
        default:
            SLAB_ASSERT(false);
            return USB_STATUS_ILLEGAL;
    }

    // If the device is not configured and it is not Endpoint 0, we cannot begin
    // a transfer.
    if ((epAddr != EP0) && (s_usb_state != USBD_STATE_CONFIGURED)) {
        return USB_STATUS_DEVICE_UNCONFIGURED;
    }

    ep = GetEp(epAddr);

    // If the endpoint is not idle, we cannot start a new transfer.
    // Return the appropriate error code.
    if (ep->state != D_EP_IDLE) {
        if (ep->state == D_EP_STALL) {
            return USB_STATUS_EP_STALLED;
        } else {
            return USB_STATUS_EP_BUSY;
        }
    }

    DISABLE_USB_INTS;

    ep->buf = dat;
    ep->remaining = byteCount;
    ep->state = D_EP_TRANSMITTING;
    ep->misc.bits.callback = callback;

    switch (epAddr) {
        // For Endpoint 0, set the inPacketPending flag to true. The USB handler
        // will see this on the next SOF and begin the transfer.
        case (EP0):
            ep0.misc.bits.inPacketPending = true;
            break;

            // For data endpoints, we will call USB_WriteFIFO here to reduce latency
            // between the call to USBD_Write() and the first packet being sent.
#if SLAB_USB_EP1IN_USED
        case (EP1IN):
            USB_WriteFIFO(1,
                (byteCount > SLAB_USB_EP1IN_MAX_PACKET_SIZE) ? SLAB_USB_EP1IN_MAX_PACKET_SIZE : byteCount,
                ep1in.buf,
                true);
            break;
#endif // SLAB_USB_EP1IN_USED
#if SLAB_USB_EP2IN_USED
        case (EP2IN):
            USB_WriteFIFO(2,
                (byteCount > SLAB_USB_EP2IN_MAX_PACKET_SIZE) ? SLAB_USB_EP2IN_MAX_PACKET_SIZE : byteCount,
                ep2in.buf,
                true);
            break;
#endif // SLAB_USB_EP2IN_USED
#if SLAB_USB_EP3IN_USED
        case (EP3IN):
#if  ((SLAB_USB_EP3IN_TRANSFER_TYPE == USB_EPTYPE_BULK) || (SLAB_USB_EP3IN_TRANSFER_TYPE == USB_EPTYPE_INTR))
            USB_WriteFIFO(3,
                (byteCount > SLAB_USB_EP3IN_MAX_PACKET_SIZE) ? SLAB_USB_EP3IN_MAX_PACKET_SIZE : byteCount,
                ep3in.buf,
                true);
#elif (SLAB_USB_EP3IN_TRANSFER_TYPE == USB_EPTYPE_ISOC)
            ep3in.misc.bits.inPacketPending = true;
            ep3inIsoIdx = 0;
#endif
            break;
#endif // SLAB_USB_EP3IN_USED
    }

    ENABLE_USB_INTS;
    USB_RestoreSfrPage();

    return USB_STATUS_OK;
}

USB_Status_TypeDef USBD_SetupCmdCb(XRAM USB_Setup_TypeDef *setup) {
    USB_Status_TypeDef retVal = USB_STATUS_REQ_UNHANDLED;

    if ((setup->bmRequestType.Type == USB_SETUP_TYPE_STANDARD)
        && (setup->bmRequestType.Direction == USB_SETUP_DIR_IN)
        && (setup->bmRequestType.Recipient == USB_SETUP_RECIPIENT_INTERFACE))
    {
        // A HID device must extend the standard GET_DESCRIPTOR command
        // with support for HID descriptors.
        switch (setup->bRequest) {
            case GET_DESCRIPTOR: {
                if ((setup->wValue >> 8) == USB_HID_REPORT_DESCRIPTOR) {
                    switch (setup->wIndex) {
                        case INTERFACE_BOOT_KEYBOARD: {
                            USBD_Write(
                                EP0,
                                hid_desc_boot_keyboard,
                                EFM8_MIN(sizeof_hid_desc_boot_keyboard, setup->wLength),
                                false
                            );
                            retVal = USB_STATUS_OK;
                        } break;

                        case INTERFACE_SHARED_HID: {
                            USBD_Write(
                                EP0,
                                hid_desc_shared_hid,
                                EFM8_MIN(sizeof_hid_desc_shared_hid, setup->wLength),
                                false
                            );
                            retVal = USB_STATUS_OK;
                        } break;

                        case INTERFACE_VENDOR: {
                            USBD_Write(
                                EP0,
                                hid_desc_vendor,
                                EFM8_MIN(sizeof_hid_desc_vendor, setup->wLength),
                                false
                            );
                            retVal = USB_STATUS_OK;
                        } break;

                        default: // Unhandled Interface
                            break;
                    }
                } else if ((setup->wValue >> 8) == USB_HID_DESCRIPTOR) {
                    switch (setup->wIndex) {
                        case INTERFACE_BOOT_KEYBOARD: {
                            USBD_Write(EP0, &usb_config_desc.hid0,
                                EFM8_MIN(sizeof(usb_hid_desc_t), setup->wLength),
                                false);
                            retVal = USB_STATUS_OK;
                        } break;

                        case INTERFACE_SHARED_HID: {
                            USBD_Write(EP0, &usb_config_desc.hid1,
                                EFM8_MIN(sizeof(usb_hid_desc_t), setup->wLength),
                                false);
                            retVal = USB_STATUS_OK;
                        } break;

                        case INTERFACE_VENDOR: {
                            USBD_Write(EP0, &usb_config_desc.hid2,
                                EFM8_MIN(sizeof(usb_hid_desc_t), setup->wLength),
                                false);
                            retVal = USB_STATUS_OK;
                        } break;

                        default: // Unhandled Interface
                            break;
                    }
                }
            } break;
        }
    } else if ((setup->bmRequestType.Type == USB_SETUP_TYPE_CLASS)
        && (setup->bmRequestType.Recipient == USB_SETUP_RECIPIENT_INTERFACE)
        && (setup->wIndex == INTERFACE_BOOT_KEYBOARD)
    ) {
        // Implement the necessary HID class specific commands.
        switch (setup->bRequest) {
            case USB_HID_SET_REPORT: {
                if (((setup->wValue >> 8) == 2)               // Output report
                    && ((setup->wValue & 0xFF) == 0)          // Report ID
                    && (setup->wLength == 1)                  // Report length
                    && (setup->bmRequestType.Direction != USB_SETUP_DIR_IN)
                ) {
                    uint8_t tmpBuffer;
                    USBD_Read(EP0, &tmpBuffer, 1, true);
                    retVal = USB_STATUS_OK;
                }
            } break;

            case USB_HID_GET_REPORT: {
                if (((setup->wValue >> 8) == 1)               // Input report
                    && ((setup->wValue & 0xFF) == 0)          // Report ID
                    && (setup->wLength == 8)                  // Report length
                    && (setup->bmRequestType.Direction == USB_SETUP_DIR_IN))
                {
                    // Send an empty (key released) report
                    USBD_Write(EP0,
                        keyboardReport,
                        sizeof(KeyReport_TypeDef),
                        false);
                    retVal = USB_STATUS_OK;
                }
            } break;

#if 0
            // USB by some OS's to set BOOT protocol for keyboard reports
            // allowing the OS to request the device to fall back to 6KRO
            // if it can't handle NKRO reports.
            // However, not all OS's support this, so we can't rely on this
            // to support both 6KRO and NKRO. Instead, we use a different
            // use both a NKRO and 6KRO report as a work around, and
            // use the 6KRO report at boot, and switch to the NKRO later.
            case USB_REQ_HID_SET_PROTOCOL: {
            } break;
            case USB_REQ_HID_GET_PROTOCOL: {
            } break;
#endif

#if 0
            // Technically necessary by USB HID spec, but doesn't seem to be
            // used in practice by most OS's for keyboards
            case USB_HID_SET_IDLE:
                if (((setup->wValue & 0xFF) == 0)             // Report ID
                    && (setup->wLength == 0)
                    && (setup->bmRequestType.Direction != USB_SETUP_DIR_IN))
                {
                    idleTimerSet(setup->wValue >> 8);
                    retVal = USB_STATUS_OK;
                }
                break;

            case USB_HID_GET_IDLE:
                if ((setup->wValue == 0)                      // Report ID
                    && (setup->wLength == 1)
                    && (setup->bmRequestType.Direction == USB_SETUP_DIR_IN))
                {
                    tmpBuffer = idleGetRate();
                    USBD_Write(EP0, &tmpBuffer, 1, false);
                    retVal = USB_STATUS_OK;
                }
                break;
#endif
        }
    }

    return retVal;
}

int8_t USBD_Read(uint8_t epAddr, void *dat, uint16_t byteCount, bool callback) {
    bool usbIntsEnabled;
    XRAM USBD_Ep_TypeDef *ep;

    USB_SaveSfrPage();

    // Verify the endpoint address is valid.
    switch (epAddr) {
        case EP0:
#if SLAB_USB_EP1OUT_USED
        case EP1OUT:
#endif
#if SLAB_USB_EP2OUT_USED
        case EP2OUT:
#endif
#if SLAB_USB_EP3OUT_USED
        case EP3OUT:
#endif
            break;
#if SLAB_USB_EP1IN_USED
        case EP1IN:
#endif
#if SLAB_USB_EP2IN_USED
        case EP2IN:
#endif
#if SLAB_USB_EP3IN_USED
        case EP3IN:
#endif
        default:
            SLAB_ASSERT(false);
            return USB_STATUS_ILLEGAL;
    }

    // If the device has not been configured, we cannot start a transfer.
    if ((epAddr != EP0) && (s_usb_state != USBD_STATE_CONFIGURED)) {
        return USB_STATUS_DEVICE_UNCONFIGURED;
    }

    ep = GetEp(epAddr);

    // If the endpoint is not idle, we cannot start a new transfer.
    // Return the appropriate error code.
    if (ep->state != D_EP_IDLE) {
        if (ep->state == D_EP_STALL) {
            return USB_STATUS_EP_STALLED;
        } else {
            return USB_STATUS_EP_BUSY;
        }
    }

    DISABLE_USB_INTS;

    ep->buf = dat;
    ep->remaining = byteCount;
    ep->state = D_EP_RECEIVING;
    ep->misc.bits.callback = callback;
    ep->misc.bits.waitForRead = false;

    ENABLE_USB_INTS;
    USB_RestoreSfrPage();

    return USB_STATUS_OK;
}
