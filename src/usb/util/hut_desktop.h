// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

// Generic Desktop Page (0x01)
// See: http://www.usb.org/developers/hidpage/Hut1_12v2.pdf

typedef enum hut_desktop_t {
    HID_DESKTOP_Undefined = 0x00,
    HID_DESKTOP_Pointer = 0x01,
    HID_DESKTOP_Mouse = 0x02,
    /* 03 Reserved */
    HID_DESKTOP_Joystick = 0x04,
    HID_DESKTOP_Game_Pad = 0x05,
    HID_DESKTOP_Keyboard = 0x06,
    HID_DESKTOP_Keypad = 0x07,
    HID_DESKTOP_Multi_axis_Controller = 0x08,
    HID_DESKTOP_Tablet_PC_System_Controls = 0x09,
    /* 0A-2F Reserved */
    HID_DESKTOP_X = 0x30,
    HID_DESKTOP_Y = 0x31,
    HID_DESKTOP_Z = 0x32,
    HID_DESKTOP_Rx = 0x33,
    HID_DESKTOP_Ry = 0x34,
    HID_DESKTOP_Rz = 0x35,
    HID_DESKTOP_Slider = 0x36,
    HID_DESKTOP_Dial = 0x37,
    HID_DESKTOP_Wheel = 0x38,
    HID_DESKTOP_Hat_switch = 0x39,
    HID_DESKTOP_Counted_Buffer = 0x3A,
    HID_DESKTOP_Byte_Count = 0x3B,
    HID_DESKTOP_Motion_Wakeup = 0x3C,
    HID_DESKTOP_Start = 0x3D,
    HID_DESKTOP_Select = 0x3E,
    /* 3F Reserved */
    HID_DESKTOP_Vx = 0x40,
    HID_DESKTOP_Vy = 0x41,
    HID_DESKTOP_Vz = 0x42,
    HID_DESKTOP_Vbrx = 0x43,
    HID_DESKTOP_Vbry = 0x44,
    HID_DESKTOP_Vbrz = 0x45,
    HID_DESKTOP_Vno = 0x46,
    HID_DESKTOP_Resolution_Multiplier = 0x48,
    /* 49-7F Reserved */
    HID_DESKTOP_System_Control = 0x80,
    HID_DESKTOP_System_Power_Down = 0x81,
    HID_DESKTOP_System_Sleep = 0x82,
    HID_DESKTOP_System_Wake_Up = 0x83,
    HID_DESKTOP_System_Context_Menu = 0x84,
    HID_DESKTOP_System_Main_Menu = 0x85,
    HID_DESKTOP_System_App_Menu = 0x86,
    HID_DESKTOP_System_Menu_Help = 0x87,
    HID_DESKTOP_System_Menu_Exit = 0x88,
    HID_DESKTOP_System_Menu_Select = 0x89,
    HID_DESKTOP_System_Menu_Right = 0x8A,
    HID_DESKTOP_System_Menu_Left = 0x8B,
    HID_DESKTOP_System_Menu_Up = 0x8C,
    HID_DESKTOP_System_Menu_Down = 0x8D,
    HID_DESKTOP_System_Cold_Restart = 0x8E,
    HID_DESKTOP_System_Warm_Restart = 0x8F,
    HID_DESKTOP_D_pad_Up = 0x90,
    HID_DESKTOP_D_pad_Down = 0x91,
    HID_DESKTOP_D_pad_Right = 0x92,
    HID_DESKTOP_D_pad_Left = 0x93,
    /* 94-9F Reserved */
    HID_DESKTOP_System_Dock = 0xA0,
    HID_DESKTOP_System_Undock = 0xA1,
    HID_DESKTOP_System_Setup = 0xA2,
    HID_DESKTOP_System_Break = 0xA3,
    HID_DESKTOP_System_Debugger_Break = 0xA4,
    HID_DESKTOP_Application_Break = 0xA5,
    HID_DESKTOP_Application_Debugger_Break = 0xA6,
    HID_DESKTOP_System_Speaker_Mute = 0xA7,
    HID_DESKTOP_System_Hibernate = 0xA8,
    /* A9-AF Reserved */
    HID_DESKTOP_System_Display_Invert = 0xB0,
    HID_DESKTOP_System_Display_Internal = 0xB1,
    HID_DESKTOP_System_Display_External = 0xB2,
    HID_DESKTOP_System_Display_Both = 0xB3,
    HID_DESKTOP_System_Display_Dual = 0xB4,
    HID_DESKTOP_System_Display_Toggle_Int_Ext = 0xB5,
    HID_DESKTOP_System_Display_Swap_Primary_Secondary = 0xB6,
    HID_DESKTOP_System_Display_LCD_Autoscale = 0xB7,
    /* B8-FFFF Reserved */
} hut_desktop_t;
