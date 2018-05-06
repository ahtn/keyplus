// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "config.h"

#include "boot_protocol.h"

#include "xmega/usb_xmega.h"
#include "sp_driver.h"
#include "vendor_report.h"
#include "descriptors.h"
#include "util.h"

USB_ENDPOINTS(1);

#ifndef FLASH_SIZE
#define FLASH_SIZE (APP_SECTION_SIZE)
#endif

#ifndef PAGE_SIZE
#define PAGE_SIZE (APP_SECTION_PAGE_SIZE)
#endif

#if (PAGE_SIZE % EP_SIZE_VENDOR) != 0
#error "Code assumes that PAGE_SIZE is divisible by USB report len"
#endif

#ifdef ALPHA_SPLIT_V2
#include "boards/alpha_split/alpha_split_util.h"
#endif

uint8_t page_buffer[PAGE_SIZE];
uint8_t s_bootloader_state;
static uint8_t s_flash_has_been_erased; // indicates if the flash has been erased
static uint8_t s_flash_empty;
write_state_t s_write_state;

const boot_info_t boot_info = {
    .version_major = VERSION_MAJOR,
    .version_minor = VERSION_MINOR,
    .mcu_string = MCU_STRING,
    .flash_size = FLASH_SIZE,
    .page_size = PAGE_SIZE,
};

void send_response(uint8_t response) {
    g_vendor_report_in.data[0] = PACKET_ERROR_STATUS;
    g_vendor_report_in.data[1] = response;
    g_vendor_report_in.len = 2;
}

void parse_cmd(uint8_t *data) {
    uint8_t cmd = data[0];

    switch (cmd) {
        case CMD_GET_BOOT_INFO: {
            memcpy(g_vendor_report_in.data, &boot_info, sizeof(boot_info_t));
            g_vendor_report_in.len = sizeof(boot_info_t);
        } break;
        case CMD_ERASE: {
            if (!s_flash_empty) {
                SP_WaitForSPM();
                SP_EraseApplicationSection();
                SP_WaitForSPM();
                s_flash_empty = true;
                s_flash_has_been_erased = true;
            }
            send_response(OKAY);
        } break;
        // Write/Read operations are only unlocked after the flash has been erased
        case CMD_WRITE: {
            if (s_flash_has_been_erased) {
                memcpy(&s_write_state, data+1, sizeof(write_state_t));
                if (s_write_state.current % PAGE_SIZE != 0 ||
                    s_write_state.remaining % PAGE_SIZE != 0) {
                    send_response(ERROR_MISALIGNED);
                    break;
                }
                SP_WaitForSPM();
                SP_EraseFlashBuffer();
                s_write_state.page_position = 0;
                s_bootloader_state = STATE_WRITE;
                s_flash_empty = false;
                send_response(OKAY);
            } else {
                send_response(ERROR_NOT_ERASED);
            }
        } break;
        case CMD_CRC: {
            if (s_flash_has_been_erased) {
                uint32_t crc_app, crc_boot;
                SP_WaitForSPM();
                crc_app = SP_ApplicationCRC();
                crc_boot = SP_BootCRC();
                g_vendor_report_in.data[0] = PACKET_CRC;
                memcpy(g_vendor_report_in.data+1, (uint8_t*)&crc_app, 4);
                memcpy(g_vendor_report_in.data+5, (uint8_t*)&crc_boot, 4);
                g_vendor_report_in.len = 9;
            } else {
                send_response(ERROR_NOT_ERASED);
            }
        } break;
        case CMD_TEST: {
            memcpy(g_vendor_report_in.data, (uint8_t*)(*(uint16_t*)(g_vendor_report_out.data+1)), 64);
            g_vendor_report_in.len = 64;
        } break;
        case CMD_RESET: {
            usb_detach();
            _delay_ms(50);
            software_reset();
        }
    }
}


void bootloader_task(void) {
    uint8_t len = read_vendor_report(g_vendor_report_out.data);
    switch (s_bootloader_state) {
        case STATE_WAIT: {
            if (len) {
                parse_cmd(g_vendor_report_out.data);
            }
        } break;
        case STATE_WRITE: {
            if (len) {
                memcpy(
                    page_buffer + s_write_state.page_position,
                    g_vendor_report_out.data,
                    EP_SIZE_VENDOR
                );
                s_write_state.page_position += EP_SIZE_VENDOR;

                // check if page_buffer is full
                if (s_write_state.page_position == PAGE_SIZE) {
                    SP_WaitForSPM();
                    SP_LoadFlashPage(page_buffer);
                    SP_WriteApplicationPage(s_write_state.current);
                    s_write_state.page_position = 0;
                    s_write_state.current += PAGE_SIZE;
                    s_write_state.remaining -= PAGE_SIZE;
                    if (s_write_state.remaining == 0) {
                        s_bootloader_state = STATE_WAIT;
                    }
                }
                send_response(OKAY);
            }
        } break;
        // case STATE_ERROR: {
        // } break;
    }

    send_vendor_report();
}

void run_bootloader(void) {
    usb_init_descriptors();
    usb_configure_clock();
    usb_init();

    wdt_init();

    usb_attach();

#ifdef ALPHA_SPLIT_V2
    // Enable the USB bus switch and select the left USB port
    SET_BUS_SWITCH(I2C_OE_LEFT, 0);
    SET_BUS_SWITCH(USB_OE, 1);
    init_bus_switch_toggler();
#endif

    s_bootloader_state = STATE_WAIT;
    s_flash_empty = false;
    s_flash_has_been_erased = false;
    boot_magic = BOOTLOADER_MAGIC_BOOT_RESET;

    // use uint8_t because we only care if the lowest byte changes
    uint8_t last_sof_count = get_sof_count();
    bool usb_connected = false;
    while(1) {
        bootloader_task();
        usb_poll();

        uint8_t this_sof_count = get_sof_count();
        if (last_sof_count != this_sof_count) {
            wdt_kick();
            last_sof_count = this_sof_count;
            usb_connected = true;
        }

        if (usb_connected) {
            wdt_kick();
        }

#ifdef ALPHA_SPLIT_V2
        if (!usb_connected) {
            bus_switch_toggle_task();
        }
#endif
    }
}

