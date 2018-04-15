#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

from enum import Enum

###############################################################################
#                                   classes                                   #
###############################################################################

class USBDeviceInfo(object):
    def __init__(self, vid, pid, description):
        self.vid = vid
        self.pid = pid
        self.description = description

    def is_prototype(self):
        return self.vid == 0x6666

class USBKeyplusKeyboardInfo(USBDeviceInfo):
    def __init__(self, vid, pid, description, interface=3):
        super(USBKeyplusKeyboardInfo, self).__init__(
            vid, pid, description,
        )
        self.interface = interface

class USBBootloaderInfo(USBDeviceInfo):
    def __init__(self, vid, pid, bootloader, description):
        super(USBBootloaderInfo, self).__init__(
            vid, pid, description
        )
        self.bootloader = bootloader


###############################################################################
#                                  constants                                  #
###############################################################################

class BootloaderType(Enum):
    XUSB_BOOT = 0
    NRF24LU1P_512 = 1
    NRF24LU1P_FACTORY = 2
    KP_BOOT_32U4 = 3


KEYPLUS_USB_IDS = {
    (0x6666, 0x1111): USBKeyplusKeyboardInfo(
        vid = 0x6666,
        pid = 0x1111,
        description = "keyplus keyboard xmega (prototype)",
    ),

    (0x6666, 0x2222): USBKeyplusKeyboardInfo(
        vid = 0x6666,
        pid = 0x2222,
        description = "keyplus keyboard atmega32u4 (prototype)",
    ),

    (0x6666, 0x3333): USBKeyplusKeyboardInfo(
        vid = 0x6666,
        pid = 0x3333,
        description = "keyplus nRF24 wireless keyboard dongle (prototype)",
    ),

    (0x1209, 0xBB00): USBKeyplusKeyboardInfo(
        vid = 0x1209,
        pid = 0xBB00,
        description = "keyplus keyboard xmega",
    ),

    (0x1209, 0xBB02): USBKeyplusKeyboardInfo(
        vid = 0x1209,
        pid = 0xBB02,
        description = "keyplus nRF24 wireless keyboard dongle",
    ),
}

BOOTLOADER_USB_IDS = {
    (0x6666, 0xB007): USBBootloaderInfo(
        vid = 0x6666,
        pid = 0xB007,
        bootloader = BootloaderType.XUSB_BOOT,
        description = "xusb boot (prototype id)",
    ),

    (0x1209, 0xBB01): USBBootloaderInfo(
        vid = 0x1209,
        pid = 0xBB01,
        bootloader = BootloaderType.XUSB_BOOT,
        description = "keyplus xusb boot bootloader",
    ),

    (0x1209, 0xBB03): USBBootloaderInfo(
        vid = 0x1209,
        pid = 0xBB03,
        bootloader = BootloaderType.NRF24LU1P_512,
        description = "keyplus nrf24lu1p-512 bootloader",
    ),

    (0x6666, 0x9999): USBBootloaderInfo(
        vid = 0x6666,
        pid = 0x9999,
        bootloader = BootloaderType.KP_BOOT_32U4,
        description = "kp_boot_32u4 bootloader (prototype id)",
    ),

    (0x1209, 0xBB05): USBBootloaderInfo(
        vid = 0x6666,
        pid = 0x9999,
        bootloader = BootloaderType.KP_BOOT_32U4,
        description = "kp_boot_32u4 bootloader",
    ),

    (0x1915, 0x0101): USBBootloaderInfo(
        vid = 0x1915,
        pid = 0x0101,
        bootloader = BootloaderType.NRF24LU1P_FACTORY,
        description = "Nordic nRF24LU1+ factory bootloader",
    ),
}

###############################################################################
#                                  functions                                  #
###############################################################################

def is_keyplus_usb_id(vendor_id, product_id):
    return (vendor_id, product_id) in KEYPLUS_USB_IDS

def is_bootloader_usb_id(vendor_id, product_id):
    return (vendor_id, product_id) in BOOTLOADER_USB_IDS
