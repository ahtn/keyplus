// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/usb_commands.h"

#include <string.h>
#include <stddef.h>

#include "core/bootloader.h"
#include "core/debug.h"
#include "core/error.h"
#include "core/flash.h"
#include "core/hardware.h"
#include "core/layout.h"
#include "core/led.h"
#include "core/matrix_interpret.h"
#include "core/matrix_scanner.h"
#include "core/unifying.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/media_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"

#include "core/debug.h"

/* TODO: abstract mcu specifi usb code */

static bit_t passthrough_mode_on;

XRAM static uint8_t s_vendor_state = STATE_WAIT_CMD;
XRAM static bool s_restore_rf_settings;

XRAM static uint8_t s_usb_commands_in_progress;

XRAM struct {
    // TODO: clean up most of the code related to this
    // TODO: must change to 16bit, need to check flashing software first
    uint8_t num_packets;
    uint8_t counter;
    uint16_t addr;
} flash_layout;

static uint8_t usb_commands_is_locked(void) {
    return s_usb_commands_in_progress;
}

static void unlock_usb_commands(void) {
    s_usb_commands_in_progress = false;
}

static void lock_usb_commands(void) {
    // TODO:
//     s_usb_commands_in_progress = true;
    s_usb_commands_in_progress = false;
}

bit_t is_passthrough_enabled(void) {
    return passthrough_mode_on;
}

void queue_vendor_in_packet(
    uint8_t usb_cmd,
    const XRAM uint8_t *payload,
    uint8_t payload_length,
    bool is_variable_length
) {
    // how big the USB vendor in report length is
    const uint8_t packet_length =
        1 + // 1 byte for command
        is_variable_length + // include length in packet (optional)
        payload_length;

    // how much space we need in queue to store the packet
    const uint8_t vendor_in_queue_packet_length = packet_length+1;

    if (vendor_in_free_space() >= vendor_in_queue_packet_length) {
        // 1st byte is the amount of bytes in the payload
        // 2nd byte is the command
        // then payload_length bytes from the payload are loaded
        //
        // payload_length+2 bytes loaded into the queue. There's will be
        // unloaded and sent in the next/future vendor_in report as a packet.

        vendor_in_write_byte(packet_length);
        vendor_in_write_byte(usb_cmd);
        if (is_variable_length) {
            vendor_in_write_byte(payload_length);
        }
        vendor_in_write_buf(payload, payload_length);
    } else {
        register_error(ERROR_VENDOR_IN_REPORT_CANT_KEEP_UP);
    }
}

// TODO: probably move this elsewhere
void reset_usb_reports(void) {
    s_vendor_state = STATE_WAIT_CMD;
    s_restore_rf_settings = false;

    passthrough_mode_on = false;
    reset_media_report();
    reset_vendor_report();
    reset_mouse_report();
    reset_keyboard_reports();

    unlock_usb_commands();
}

#define ERROR_PACKET_LENGTH 2
void cmd_error(uint8_t code) {
#if USB_BUFFERED
    queue_vendor_in_packet(
        CMD_ERROR_CODE,
        (uint8_t*)&code,
        sizeof(code),
        STATIC_LENGTH_CMD
    );
#else
    g_vendor_report_in.len = ERROR_PACKET_LENGTH;
    g_vendor_report_in.data[0] = CMD_ERROR_CODE;
    g_vendor_report_in.data[1] = code;
    send_vendor_report();
#endif
}

void cmd_ok(void) {
    cmd_error(CMD_ERROR_CODE_NONE);
}

/* TODO: abstract */
void cmd_reset(uint8_t reset_type) {
    if (reset_type == RESET_TYPE_HARDWARE) {
        reset_mcu();
    } else if (reset_type == RESET_TYPE_SOFTWARE) {
        // TODO: software reset
    }
}

// send data to the host for debugging purposes
uint8_t usb_print(const uint8_t *data, uint8_t len) {
#if USB_BUFFERED
    if (usb_commands_is_locked()) {
        return 1;
    }

    queue_vendor_in_packet(CMD_PRINT, data, len, VARIABLE_LENGTH_CMD);
#else

    if (usb_commands_is_locked()) {
        return 1;
    }

    g_vendor_report_in.data[0] = CMD_PRINT;
    g_vendor_report_in.data[1] = len;
    if (len > VENDOR_REPORT_LEN-2) {
        len = VENDOR_REPORT_LEN-2;
    }
    /* copy(vendor_report.data+1, data, len); */
    memcpy(g_vendor_report_in.data+2, data, len);
    g_vendor_report_in.len = len+2;
    send_vendor_report();
#endif
    return 0;
}

void cmd_send_layer(uint8_t kb_id) {
    if (!is_keyboard_active(kb_id)) {
        cmd_error(CMD_ERROR_KEYBOARD_INACTIVE);
        return;
    }



    g_vendor_report_in.data[0] = CMD_LAYER_STATE;
    g_vendor_report_in.data[1] = kb_id;
    {
        const uint8_t kb_slot_id = get_slot_id(kb_id);
        memcpy(g_vendor_report_in.data + 2, (uint8_t*)&g_keyboard_slots[kb_slot_id].active_layers, 2);
        memcpy(g_vendor_report_in.data + 4, (uint8_t*)&g_keyboard_slots[kb_slot_id].sticky_layers, 2);
        memcpy(g_vendor_report_in.data + 6, (uint8_t*)&g_keyboard_slots[kb_slot_id].default_layers, 2);
    }
    g_vendor_report_in.len = 8;
    send_vendor_report();
}

/// Resets into the Logitech unifying receiver bootloader.
void cmd_logitech_bootloader(void) {
    bootloader_jmp_2();
}

static void cmd_custom_bootloader(void) {
    bootloader_jmp();
}

static void cmd_unifying_pairing(void) {
    unifying_begin_pairing();
}

static void erase_page_range(uint16_t start_page, uint16_t page_count) {
    uint16_t i;
    wdt_kick();

    // erase all the pages for the layout
    flash_modify_enable();
    for (i = 0; i < page_count; ++i) {
        flash_erase_page(start_page + i);
    }
    flash_modify_disable();
}

static void cmd_get_info(void) {
    uint8_t info_type = g_vendor_report_out.data[1];

    g_vendor_report_in.data[0] = CMD_GET_INFO;
    g_vendor_report_in.data[1] = info_type;

    if (info_type == INFO_MAIN_0) {
        flash_read(
            g_vendor_report_in.data+2,
            SETTINGS_ADDR,
            EP_SIZE_VENDOR-2
        );
    } else if (info_type == INFO_MAIN_1) {
        flash_read(
            g_vendor_report_in.data+2,
            SETTINGS_ADDR + (EP_SIZE_VENDOR-2),
            SETTINGS_MAIN_INFO_SIZE - (EP_SIZE_VENDOR-2)
        );
    } else if (info_type == INFO_LAYOUT) {
        flash_read(
            g_vendor_report_in.data+2,
            SETTINGS_ADDR + SETTINGS_LAYOUT_INFO_OFFSET,
            SETTINGS_LAYOUT_INFO_SIZE
        );
    } else if (info_type == INFO_RF) {
        // NOTE: this command doesn't return the AES keys
        flash_read(
            g_vendor_report_in.data+2,
            SETTINGS_ADDR + SETTINGS_RF_INFO_OFFSET,
            SETTINGS_RF_INFO_HEADER_SIZE
        );
    } else if (info_type == INFO_FIRMWARE) {
        flash_read(
            g_vendor_report_in.data+2,
            (flash_ptr_t)(&g_firmware_build_settings),
            sizeof(firmware_build_settings_t)
        );
    } else if (info_type == INFO_ERROR_SYSTEM) {
        memcpy(
            g_vendor_report_in.data+2,
            g_error_code_table,
            SIZE_ERROR_CODE_TABLE
        );
    } else {
        g_vendor_report_in.data[1] = INFO_UNSUPPORTED;
    }

    g_vendor_report_in.len = VENDOR_REPORT_LEN;
    send_vendor_report();
}

void parse_cmd(void) {
    const uint8_t cmd = g_vendor_report_out.data[0];
    const uint8_t data1 = g_vendor_report_out.data[1];
    const uint8_t data2 = g_vendor_report_out.data[2];
    debug_toggle(1);
    switch (cmd) {
        case CMD_BOOTLOADER: {
            cmd_custom_bootloader();
        } break;
        case CMD_GET_INFO: {
            debug_toggle(5);
            cmd_get_info();
        } break;
        case CMD_RESET: {
            cmd_reset(data1);
        } break;
        case CMD_LED_CONTROL: {
            const uint8_t led_number = data1;
            const uint8_t state = data2;
            led_testing_set(led_number, state);
        } break;
        case CMD_LAYER_STATE: {
            cmd_send_layer(data1);
        } break;
        case CMD_LOGITECH_BOOTLOADER: {
            cmd_logitech_bootloader();
        } break;
#ifndef NO_MATRIX
        case CMD_SET_PASSTHROUGH_MODE: {
            if (g_scan_plan.mode == MATRIX_SCANNER_MODE_NO_MATRIX ) {
                cmd_error(CMD_ERROR_UNSUPPORTED_COMMAND);
            } else {
                passthrough_mode_on = data1;
                cmd_ok();
            }
        } break;
#endif

        // TODO: before using this command on XMEGA, need to fix flash locations
        case CMD_UPDATE_SETTINGS: {
            uint8_t update_type = data1;

            flash_layout.counter = 0;
            flash_layout.addr = SETTINGS_ADDR;

            if (update_type == SETTING_UPDATE_ALL) {
                flash_layout.num_packets = (SETTINGS_SIZE) / EP_SIZE_VENDOR;
            } else if (update_type == SETTING_UPDATE_KEEP_RF) {
                flash_layout.num_packets = (SETTINGS_SIZE - SETTINGS_RF_INFO_SIZE) / EP_SIZE_VENDOR;
            } else {
                cmd_error(CMD_ERROR_INVALID_VALUE);
                return;
            }

            // TODO: instead of using this global, just run everything in a loop?
            g_input_disabled = true;

            lock_usb_commands();
            s_vendor_state = STATE_WRITE_FLASH;

            erase_page_range(SETTINGS_PAGE_NUM, SETTINGS_PAGE_COUNT);

            if (update_type == SETTING_UPDATE_KEEP_RF) {
                flash_modify_enable();
                flash_write(
                    (uint8_t*)&g_rf_settings,
                    SETTINGS_ADDR + SETTINGS_RF_INFO_OFFSET,
                    SETTINGS_RF_INFO_SIZE
                );
                flash_modify_disable();
            }

            cmd_ok();
        } break;
        case CMD_UPDATE_LAYOUT: {
            uint16_t number_pages;
            flash_layout.num_packets = data1;
            flash_layout.counter = 0;
            flash_layout.addr = LAYOUT_ADDR;

            number_pages = (flash_layout.num_packets+(CHUNKS_PER_PAGE-1))/CHUNKS_PER_PAGE;
            if (number_pages > LAYOUT_PAGE_COUNT) {
                cmd_error(CMD_ERROR_CODE_TOO_MUCH_DATA);
                return;
            }

            // TODO: instead of using this global, just run everything in a loop?
            g_input_disabled = true;

            lock_usb_commands();
            s_vendor_state = STATE_WRITE_FLASH;

            // debug_toggle(3);
            erase_page_range(LAYOUT_PAGE_NUM, number_pages);

            cmd_ok();
        } break;

        case CMD_UNIFYING_PAIR: {
            cmd_unifying_pairing();
        } break;
        default: {
            cmd_error(CMD_ERROR_UNKNOWN_CMD);
        } break;
    }
}

// TODO: might change how flashing layouts works. Make it so we need to request
// each block individually?

void handle_vendor_out_reports(void) {
    if (!is_ready_vendor_out_report()) {
        return;
    }

    read_vendor_report(g_vendor_report_out.data);

    if (g_vendor_report_out.len == 0) {
        return;
    }

    if (s_vendor_state == STATE_WAIT_CMD) {
        parse_cmd();
    } else if (s_vendor_state == STATE_WRITE_FLASH) {
        /* const uint8_t page = LAYOUT_PAGE_NUM + flash_layout.counter/CHUNKS_PER_PAGE; */
        const uint16_t addr = flash_layout.addr + (uint16_t)flash_layout.counter * EP_SIZE_VENDOR;
        const uint8_t size = g_vendor_report_out.len;

        debug_toggle(2);
        wdt_kick();

        // at this stage all the necessary pages have been erased, so all we
        // need to do is write to them.
        flash_modify_enable();
        flash_write(g_vendor_report_out.data, addr, size);
        flash_modify_disable();

        g_vendor_report_out.len = 0;

        // zero report incase it contained encryption key data, etc.
        memset(g_vendor_report_out.data, 0, EP_SIZE_VENDOR);

        cmd_ok();

        flash_layout.counter += 1;
        if (flash_layout.counter >= flash_layout.num_packets) {
            debug_toggle(3);
            s_vendor_state = STATE_WAIT_CMD;
            g_input_disabled = false;
            unlock_usb_commands();
            // dynamic_delay_ms(100);
            // cmd_reset();
        }
    }
}
