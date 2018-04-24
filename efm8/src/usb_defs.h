/***************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 ******************************************************************************/

#pragma once

// -----------------------------------------------------------------------------
// Global Constants

// SETUP request, direction of data stage
#define USB_SETUP_DIR_OUT       0               ///< Setup request data stage OUT direction value.
#define USB_SETUP_DIR_IN        1               ///< Setup request data stage IN direction value.
#define USB_SETUP_DIR_MASK      0x80            ///< Setup request data stage direction mask.
#define USB_SETUP_DIR_D2H       0x80            ///< Setup request data stage IN direction mask.
#define USB_SETUP_DIR_H2D       0x00            ///< Setup request data stage OUT direction mask.

// SETUP request type
#define USB_SETUP_TYPE_STANDARD       0         ///< Standard setup request value.
#define USB_SETUP_TYPE_CLASS          1         ///< Class setup request value.
#define USB_SETUP_TYPE_VENDOR         2         ///< Vendor setup request value.
#define USB_SETUP_TYPE_STANDARD_MASK  0x00      ///< Standard setup request mask.
#define USB_SETUP_TYPE_CLASS_MASK     0x20      ///< Class setup request mask.
#define USB_SETUP_TYPE_VENDOR_MASK    0x40      ///< Vendor setup request mask.

// SETUP request recipient
#define USB_SETUP_RECIPIENT_DEVICE    0         ///< Setup request device recipient value.
#define USB_SETUP_RECIPIENT_INTERFACE 1         ///< Setup request interface recipient value.
#define USB_SETUP_RECIPIENT_ENDPOINT  2         ///< Setup request endpoint recipient value.
#define USB_SETUP_RECIPIENT_OTHER     3         ///< Setup request other recipient value.

// bmRequestType bitmasks
#define USB_BMREQUESTTYPE_RECIPIENT     0x1F    ///< Recipient is bmRequestType[4:0]
#define USB_BMREQUESTTYPE_TYPE          0x60    ///< Type is bmRequestType[6:5]
#define USB_BMREQUESTTYPE_DIRECTION     0x80    ///< Recipient is bmRequestType[7]

// SETUP standard request codes for Full Speed devices
#define GET_STATUS                0             ///< Standard setup request GET_STATUS.
#define CLEAR_FEATURE             1             ///< Standard setup request CLEAR_FEATURE.
#define SET_FEATURE               3             ///< Standard setup request SET_FEATURE.
#define SET_ADDRESS               5             ///< Standard setup request SET_ADDRESS.
#define GET_DESCRIPTOR            6             ///< Standard setup request GET_DESCRIPTOR.
#define SET_DESCRIPTOR            7             ///< Standard setup request SET_DESCRIPTOR.
#define GET_CONFIGURATION         8             ///< Standard setup request GET_CONFIGURATION.
#define SET_CONFIGURATION         9             ///< Standard setup request SET_CONFIGURATION.
#define GET_INTERFACE             10            ///< Standard setup request GET_INTERFACE.
#define SET_INTERFACE             11            ///< Standard setup request SET_INTERFACE.
#define SYNCH_FRAME               12            ///< Standard setup request SYNCH_FRAME.

// SETUP class request codes
#define USB_HID_GET_REPORT        0x01          ///< HID class setup request GET_REPORT.
#define USB_HID_GET_IDLE          0x02          ///< HID class setup request GET_IDLE.
#define USB_HID_SET_REPORT        0x09          ///< HID class setup request SET_REPORT.
#define USB_HID_SET_IDLE          0x0A          ///< HID class setup request SET_IDLE.
#define USB_HID_SET_PROTOCOL      0x0B          ///< HID class setup request SET_PROTOCOL.
#define USB_CDC_SETLINECODING     0x20          ///< CDC class setup request SET_LINE_CODING.
#define USB_CDC_GETLINECODING     0x21          ///< CDC class setup request GET_LINE_CODING.
#define USB_CDC_SETCTRLLINESTATE  0x22          ///< CDC class setup request SET_CONTROL_LINE_STATE.
#define USB_MSD_BOTRESET          0xFF          ///< MSD class setup request Bulk only transfer reset.
#define USB_MSD_GETMAXLUN         0xFE          ///< MSD class setup request Get Max LUN.

// SETUP command GET/SET_DESCRIPTOR descriptor types
#define USB_DEVICE_DESCRIPTOR             1     ///< DEVICE descriptor value.
#define USB_CONFIG_DESCRIPTOR             2     ///< CONFIGURATION descriptor value.
#define USB_STRING_DESCRIPTOR             3     ///< STRING descriptor value.
#define USB_INTERFACE_DESCRIPTOR          4     ///< INTERFACE descriptor value.
#define USB_ENDPOINT_DESCRIPTOR           5     ///< ENDPOINT descriptor value.
#define USB_DEVICE_QUALIFIER_DESCRIPTOR   6     ///< DEVICE_QUALIFIER descriptor value.
#define USB_OTHER_SPEED_CONFIG_DESCRIPTOR 7     ///< OTHER_SPEED_CONFIGURATION descriptor value.
#define USB_INTERFACE_POWER_DESCRIPTOR    8     ///< INTERFACE_POWER descriptor value.
#define USB_HUB_DESCRIPTOR                0x29  ///< HUB descriptor value.
#define USB_HID_DESCRIPTOR                0x21  ///< HID descriptor value.
#define USB_HID_REPORT_DESCRIPTOR         0x22  ///< HID REPORT descriptor value.
#define USB_CS_INTERFACE_DESCRIPTOR       0x24  ///< Audio Class-specific Descriptor Type.

#define USB_DEVICE_DESCSIZE               18    ///< Device descriptor size.
#define USB_CONFIG_DESCSIZE               9     ///< Configuration descriptor size.
#define USB_INTERFACE_DESCSIZE            9     ///< Interface descriptor size.
#define USB_ENDPOINT_DESCSIZE             7     ///< Endpoint descriptor size.
#define USB_DEVICE_QUALIFIER_DESCSIZE     10    ///< Device qualifier descriptor size.
#define USB_OTHER_SPEED_CONFIG_DESCSIZE   9     ///< Device other speed configuration descriptor size.
#define USB_HID_DESCSIZE                  9     ///< HID descriptor size.
#define USB_CDC_HEADER_FND_DESCSIZE       5     ///< CDC Header functional descriptor size.
#define USB_CDC_CALLMNG_FND_DESCSIZE      5     ///< CDC Call Management functional descriptor size.
#define USB_CDC_ACM_FND_DESCSIZE          4     ///< CDC Abstract Control Management functional descriptor size.

// String descriptor locations
#define USB_STRING_DESCRIPTOR_ENCODING    0     ///< Denotes whether string descriptor is UTF-8 or binary
#define USB_STRING_DESCRIPTOR_LENGTH      1     ///< Length of string descriptor
#define USB_STRING_DESCRIPTOR_TYPE        2     ///< Type of string descriptor (USB_STRING_DESCRIPTOR)
#define USB_STRING_DESCRIPTOR_NAME        3     ///< The string encoded as per USB_STRING_DESCRIPTOR_PACKED

// String descriptor encoding types
#define USB_STRING_DESCRIPTOR_UTF16LE        0  ///< The string is in UTF-16LE encoding
#define USB_STRING_DESCRIPTOR_UTF16LE_PACKED 1  ///< The string is in packed UTF-16LE encoding (the 0x00
///  characters between ASCII characters are omitted)
#define USB_STRING_DESCRIPTOR_UTF8           2  ///< The string is in UTF-8 encoding

// Misc. USB definitions
#define USB_FULL_EP0_SIZE                 64      ///< The size of endpoint 0 at full speed.
#define USB_FULL_INT_BULK_MAX_EP_SIZE     64      ///< The max size of any full speed bulk/interrupt endpoint.
#define USB_FULL_ISOC_MAX_EP_SIZE         1023    ///< The max size of any full speed isochronous endpoint.
#define USB_LOW_EP0_SIZE                  8       ///< The size of endpoint 0 at low speed.
#define USB_LOW_INT_BULK_MAX_EP_SIZE      8       ///< The max size of any low speed bulk/interrupt endpoint.
#define USB_LOW_ISOC_MAX_EP_SIZE          0       ///< The max size of any low speed isochronous endpoint.
#define USB_EPTYPE_CTRL                   0       ///< Endpoint type control.
#define USB_EPTYPE_ISOC                   1       ///< Endpoint type isochronous.
#define USB_EPTYPE_BULK                   2       ///< Endpoint type bulk.
#define USB_EPTYPE_INTR                   3       ///< Endpoint type interrupt.
#define USB_EP_DIR_IN                     0x80    ///< Endpoint IN direction mask.
#define USB_EP_DIR_OUT                    0x00    ///< Endponit OUT direction mask.
#define USB_SETUP_PKT_SIZE                8       ///< Setup request packet size.
#define USB_EPNUM_MASK                    0x0F    ///< Endpoint number mask.
#define USB_LANGID_ENUS                   0x0409  ///< English-United States language id.
#define USB_LANGID_NOBO                   0x0414  ///< Norwegian-Bokmal language id.
#define USB_MAX_DEVICE_ADDRESS            127     ///< Maximum allowable device address.
#define MAX_USB_EP_NUM                    15      ///< Limit imposed by the USB standard
#define USB_VENDOR_ID_SILICON_LABS        0x10C4  ///< Silicon Labs VID

#define CONFIG_DESC_BM_REMOTEWAKEUP 0x20        ///< Configuration descriptor attribute macro.
#define CONFIG_DESC_BM_SELFPOWERED  0x40        ///< Configuration descriptor attribute macro.
#define CONFIG_DESC_BM_RESERVED_D7  0x80        ///< Configuration descriptor attribute macro.
#define CONFIG_DESC_BM_TRANSFERTYPE 0x03        ///< Configuration descriptor transfer type bitmask.
#define CONFIG_DESC_MAXPOWER_mA(x)  (((x)+1)/2) ///< Configuration descriptor power macro.

#define DEVICE_IS_SELFPOWERED       0x0001      ///< Standard request GET_STATUS bitmask.
#define REMOTE_WAKEUP_ENABLED       0x0002      ///< Standard request GET_STATUS bitmask.
#define USB_FEATURE_ENDPOINT_HALT         0     ///< Standard request CLEAR/SET_FEATURE bitmask.
#define USB_FEATURE_DEVICE_REMOTE_WAKEUP  1     ///< Standard request CLEAR/SET_FEATURE bitmask.

#define HUB_FEATURE_PORT_RESET            4     ///< HUB class request CLEAR/SET_PORT_FEATURE feature selector.
#define HUB_FEATURE_PORT_POWER            8     ///< HUB class request CLEAR/SET_PORT_FEATURE feature selector.
#define HUB_FEATURE_C_PORT_CONNECTION     16    ///< HUB class request CLEAR/SET_PORT_FEATURE feature selector.
#define HUB_FEATURE_C_PORT_RESET          20    ///< HUB class request CLEAR/SET_PORT_FEATURE feature selector.
#define HUB_FEATURE_PORT_INDICATOR        22    ///< HUB class request CLEAR/SET_PORT_FEATURE feature selector.

#define USB_CLASS_CDC                     2     ///< CDC device/interface class code.
#define USB_CLASS_CDC_DATA                0x0A  ///< CDC Data interface class code.
#define USB_CLASS_CDC_ACM                 2     ///< CDC Abstract Control Model interface subclass code.
#define USB_CLASS_CDC_HFN                 0     ///< CDC class Header Functional Descriptor subtype.
#define USB_CLASS_CDC_CMNGFN              1     ///< CDC class Call Management Functional Descriptor subtype.
#define USB_CLASS_CDC_ACMFN               2     ///< CDC class Abstract Control Management Functional Descriptor subtype.
#define USB_CLASS_CDC_UNIONFN             6     ///< CDC class Union Functional Descriptor subtype.

#define USB_CLASS_HID                     3     ///< HID device/interface class code.
#define USB_CLASS_HID_KEYBOARD            1     ///< HID keyboard interface protocol code.
#define USB_CLASS_HID_MOUSE               2     ///< HID mouse interface protocol code.

#define USB_CLASS_HUB                     9     ///< HUB device/interface class code.

#define USB_CLASS_MSD                     8     ///< MSD device/interface class code.
#define USB_CLASS_MSD_BOT_TRANSPORT       0x50  ///< MSD Bulk Only Transport protocol.
#define USB_CLASS_MSD_SCSI_CMDSET         6     ///< MSD Subclass SCSI transparent command set.
#define USB_CLASS_MSD_CSW_CMDPASSED       0     ///< MSD BOT Command status wrapper command passed code.
#define USB_CLASS_MSD_CSW_CMDFAILED       1     ///< MSD BOT Command status wrapper command failed code.
#define USB_CLASS_MSD_CSW_PHASEERROR      2     ///< MSD BOT Command status wrapper cmd phase error code.

#define USB_CLASS_VENDOR_SPECIFIC         0xFF  ///< Vendor Specific class
#define USB_SUBCLASS_VENDOR_SPECIFIC      0xFF  ///< Vendor Specific sub-class

/// @brief USB power save modes
#define USB_PWRSAVE_MODE_OFF       0            ///< No energy saving option selected.
#define USB_PWRSAVE_MODE_ONSUSPEND 1            ///< Enter USB power-save mode on suspend.
#define USB_PWRSAVE_MODE_ONVBUSOFF 2            ///< Enter USB power-save mode when not attached to the USB host.
#define USB_PWRSAVE_MODE_FASTWAKE  4            ///< Exit USB power-save mode more quickly. This is useful for
///< some applications that support remote wakeup.

/// @brief Endpoint 0 packet size
#if SLAB_USB_FULL_SPEED
#define USB_EP0_SIZE    USB_FULL_EP0_SIZE
#else
#define USB_EP0_SIZE    USB_LOW_EP0_SIZE
#endif // SLABS_USB_FULL_SPEED

