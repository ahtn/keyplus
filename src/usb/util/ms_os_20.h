// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "usb/util/descriptor_defs.h"

#include <stdint.h>

// Microsoft OS 2.0 descriptor platform capability descriptor
typedef struct usb_ms_os_20_desc_t {
    uint8_t bLength; // 10
    uint8_t bDescriptorType;
    uint8_t bDevCapabilityType;
    uint8_t bReserved;
    uint8_t PlatformCapabilityUUID[16];
    uint32_t dwWindowsVersion;
    uint16_t bMS_VendorCode;
    uint8_t bAltEnumCode;
} usb_ms_os_20_desc_t;

// Microsoft OS 2.0 descriptor set header
typedef struct usb_ms_os_20_desc_set_header_t {
    uint16_t wLength;
    uint16_t wDescriptorType;
    uint32_t dwWindowsVersion;
    uint16_t wTotalLength;
} usb_ms_os_20_desc_set_header_t;

// Microsoft OS 2.0 configuration subset header
typedef struct usb_ms_os_20_config_subset_header_t {
    uint16_t wLength;
    uint16_t wDescriptorType;
    uint8_t bConfigurationValue;
    uint8_t bReserved;
    uint16_t wTotalLength;
} usb_ms_os_20_config_subset_header_t;

// Microsoft OS 2.0 function subset header
typedef struct usb_ms_os_20_func_subset_header_t {
    uint16_t wLength;
    uint16_t wDescriptorType;
    uint8_t bFirstInterface;
    uint8_t bReserved;
    uint16_t wSubsetLength;
} usb_ms_os_20_func_subset_header_t;

// Microsoft OS 2.0 feature descriptor
typedef struct usb_ms_os_20_feat_subset_header_t {
    uint16_t wLength;
    uint16_t wDescriptorType;
    uint8_t CompatibleID[8];
    uint8_t SubCompatibleID[8];
} usb_ms_os_20_feat_subset_header_t;

#if 0
// Microsoft OS 2.0 registry property descriptor
typedef struct usb_ms_os_20_registry_property_t {
    uint16_t wLength;
    uint16_t wDescriptorType;
    uint16_t wPropertyDataType;
    uint16_t wPropertyNameLength;
    uint8_t PropertyName[]; // Variable length
    uint16_t wPropertyDataLength;
    uint16_t PropertyData[]; // Variable length
} usb_ms_os_20_registry_property_t;
#endif

// Microsoft OS 2.0 minimum USB recovery time descriptor
typedef struct usb_ms_os_20_min_recv_time_desc_t {
    uint16_t wLength;
    uint16_t wDescriptorType;
    uint16_t bResumeRecoveryTime;
    uint16_t bResumeSignalingTime;
} usb_ms_os_20_min_recv_time_desc_t;

// Microsoft OS 2.0 model ID descriptor
typedef struct usb_ms_os_20_model_id_desc_t {
    uint16_t wLength;
    uint16_t wDescriptorType;
    uint16_t bResumeRecoveryTime;
    uint16_t bResumeSignalingTime;
} usb_ms_os_20_model_id_desc_t;

// Microsoft OS 2.0 ccgp device descriptor
typedef struct usb_ms_os_20_ccgp_dev_desc_t {
    uint16_t wLength;
    uint16_t wDescriptorType;
} usb_ms_os_20_ccgp_dev_desc_t;

#define MS_OS_20_DESC_TYPE USB_DESC_DEVICE_CAPABILITY
#define MS_OS_20_CAPABILITY USB_DEV_CAPABILITY_PLATFORM

// The byte ordering for the WEBUSB UUID comes from Microsofts UUID structure:
// https://msdn.microsoft.com/en-us/library/windows/desktop/aa379358(v=vs.85).aspx
//
// struct UUID {
//   uint32_t data1;
//   uint16_t data2;
//   uint16_t data3;
//   uint8_t data4[8];
// };
//
// The webusb UUID: {3408b638-09a9-47a0-8bfd-a0768815b665}
// needs to be encoded in little endian based on the UUID structure above.

#define MS_OS_20_UUID { \
    0xDF, 0x60, 0xDD, 0xD8, \
    0x89, 0x45, \
    0xC7, 0x4C, \
    0x9C, 0xD2, 0x65, 0x9D, 0x9E, 0x64, 0x8A, 0x9F \
}

#define MS_OS_20_DESCRIPTOR_INDEX 0x07
#define MS_OS_20_SET_ALT_ENUMERATION 0x08

#define MS_OS_20_SET_HEADER_DESCRIPTOR 0x00
#define MS_OS_20_SUBSET_HEADER_CONFIGURATION 0x01
#define MS_OS_20_SUBSET_HEADER_FUNCTION 0x02
#define MS_OS_20_FEATURE_COMPATABLE_ID 0x03
#define MS_OS_20_FEATURE_REG_PROPERTY 0x04
#define MS_OS_20_FEATURE_MIN_RESUME_TIME 0x05
#define MS_OS_20_FEATURE_MODEL_ID 0x06
#define MS_OS_20_FEATURE_CCGP_DEVICE 0x07

#define MS_OS_20_REG_SZ 1
#define MS_OS_20_REG_EXPAND_SZ 2
#define MS_OS_20_REG_BINARY 3
#define MS_OS_20_REG_DWORD_LITTLE_ENDIAN 4
#define MS_OS_20_REG_DWORD_BIG_ENDIAN 5
#define MS_OS_20_REG_LINK 6
#define MS_OS_20_REG_MULTI_SZ 7

#define MS_OS_20_WINDOWS_81 0x06030000
