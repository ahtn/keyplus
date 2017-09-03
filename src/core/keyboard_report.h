// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

#include "usb/descriptors.h"

#define NKRO_REPORT_BYTES (0xe0/8)

#define BOOT_REPORT_KEY_COUNT 6

#define PROTOCOL_REPORT 1
#define PROTOCOL_BOOT 0

typedef struct {
    uint8_t modifiers;
    uint8_t bitmask[NKRO_REPORT_BYTES];    // the keycode as defined in keycode.h
} hid_report_nkro_keyboard_t;

typedef struct {
    uint8_t modifiers;
    uint8_t unused;
    uint8_t keys[BOOT_REPORT_KEY_COUNT];
} hid_report_boot_keyboard_t;

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
void set_keyboard_report_mode(uint8_t mode);
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
