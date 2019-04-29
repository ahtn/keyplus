// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file
/// @brief 6KRO and NKRO USB reports

#pragma once

#include "core/util.h"

#include "usb/descriptors.h"

/// The number of bytes in the NKRO report bitmask
#define NKRO_REPORT_BYTES (0xe0/8)

#define BOOT_REPORT_KEY_COUNT 6

#define PROTOCOL_REPORT 1
#define PROTOCOL_BOOT 0

/// Values for the keyboard report mode.
typedef enum {
    /// @brief Use 6KRO mode by default. Permanently changes to NKRO if more
    ///        than 6 keys are pressed at any time.
    ///
    /// This mode helps with older BIOS's that don't support NKRO or the
    /// the HID `SET_PROTOCOL` request.
    KEYBOARD_REPORT_MODE_AUTO = 0,
    /// Send key presses over the NKRO keyboard report
    KEYBOARD_REPORT_MODE_NKRO = 1,
    /// Send key presses over the 6KRO keyboard report
    KEYBOARD_REPORT_MODE_6KRO = 2,
    /// @brief Transitioning from 6KRO -> NKRO (internal use).
    ///
    /// If the report mode is set to @ref KEYBOARD_REPORT_MODE_AUTO, it will
    /// send key presses using the 6KRO report at first. However, the first
    /// time that more than 6 keys are pressed, then the keyboard will switch
    /// to @ref KEYBOARD_REPORT_MODE_UPGRADE. In this mode it will add new keys
    /// to the NKRO report, and it will delete the keys that triggered the
    /// upgrade event from the 6KRO report.  When all keys have been removed
    /// from the 6KRO report, the report mode will be switched to @ref
    /// KEYBOARD_REPORT_MODE_NKRO
    KEYBOARD_REPORT_MODE_UPGRADE,
} keyboard_report_mode_t;


typedef struct {
#ifdef SHARED_HID_DESCRIPTOR
    uint8_t report_id;
#endif
    uint8_t modifiers;
    uint8_t bitmask[NKRO_REPORT_BYTES];    // the keycode as defined in keycode.h
} ATTR_PACKED hid_report_nkro_keyboard_t;

typedef struct {
    uint8_t modifiers;
    uint8_t unused;
    uint8_t keys[BOOT_REPORT_KEY_COUNT];
} ATTR_PACKED hid_report_boot_keyboard_t;

extern XRAM hid_report_boot_keyboard_t g_boot_keyboard_report;
extern XRAM hid_report_nkro_keyboard_t g_nkro_keyboard_report;

void boot_add_keycode(uint8_t kc);
void boot_del_keycode(uint8_t kc);
void nkro_add_keycode(uint8_t kc);
void nkro_del_keycode(uint8_t kc);

void add_keycode(uint8_t kc);
void del_keycode(uint8_t kc);

void set_keyboard_protocol(uint8_t proto);
uint8_t get_keyboard_protocol(void);
void set_keyboard_report_mode(keyboard_report_mode_t mode);
uint8_t get_keyboard_report_mode(void);

void retrigger_keycode(uint8_t kc);
bool has_keycode(uint8_t kc);
void clear_keyboard_report(void);
void touch_keyboard_report(void);

void reset_keyboard_reports(void);

bit_t send_boot_keyboard_report(void);
bit_t send_nkro_keyboard_report(void);
bit_t send_keyboard_report(void);

bit_t is_ready_boot_keyboard_report(void);
bit_t is_ready_nkro_keyboard_report(void);
bit_t is_ready_keyboard_report(void);
