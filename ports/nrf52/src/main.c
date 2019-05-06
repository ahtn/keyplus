// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "app_error.h"

#include "nrf_delay.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "core/aes.h"
#include "core/error.h"
#include "core/flash.h"
#include "core/macro.h"
#include "core/nonce.h"
#include "core/rf.h"
#include "core/settings.h"
#include "core/timer.h"
#include "core/nrf52_esb.h"

#include "nrf52_usb.h"

#include "core/usb_commands.h"
#include "core/matrix_interpret.h"
#include "core/matrix_scanner.h"

#include "key_handlers/key_hold.h"
#include "key_handlers/key_mouse.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/media_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"


void init_logging(void) {
    uint32_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_DEFAULT_BACKENDS_INIT();
}

static void print_settings_info(void) {
    // Read session ID
    uint16_t sid = 0xFFFF;
    sid = load_session_id();
    NRF_LOG_INFO("sid: %d", sid);

    // Print RF settings
    NRF_LOG_INFO("=== Read settings ===");
    NRF_LOG_INFO("RF pipe_addr_0: ");
    NRF_LOG_HEXDUMP_INFO(g_rf_settings.pipe_addr_0, 5);
    NRF_LOG_INFO("RF pipe_addr_1: ");
    NRF_LOG_HEXDUMP_INFO(g_rf_settings.pipe_addr_1, 5);
    NRF_LOG_FLUSH();
    NRF_LOG_INFO("RF pipe_addr_2: %d", g_rf_settings.pipe_addr_2);
    NRF_LOG_INFO("RF pipe_addr_3: %d", g_rf_settings.pipe_addr_3);
    NRF_LOG_INFO("RF pipe_addr_4: %d", g_rf_settings.pipe_addr_4);
    NRF_LOG_INFO("RF pipe_addr_5: %d", g_rf_settings.pipe_addr_5);
    NRF_LOG_INFO("RF channel: %d", g_rf_settings.channel);
    NRF_LOG_INFO("RF arc: %d", g_rf_settings.arc);
    NRF_LOG_INFO("RF data rate: %d", g_rf_settings.data_rate);
    NRF_LOG_INFO("RF power: %d", g_rf_settings.power);
    NRF_LOG_FLUSH();

#if 0
    // NOTE: This seems code breaks when optimizations are enabled?
    NRF_LOG_INFO("> AES: begin test");
    {
        uint8_t test_block[AES_BLOCK_SIZE] = {
            'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o',
            'r', 'l', 'd', '!', ' ', '3', '6', '5',
        };
        NRF_LOG_HEXDUMP_INFO(test_block, AES_BLOCK_SIZE);
        aes_encrypt(test_block);
        NRF_LOG_HEXDUMP_INFO(test_block, AES_BLOCK_SIZE);
        aes_decrypt(test_block);
        NRF_LOG_HEXDUMP_INFO(test_block, AES_BLOCK_SIZE);
    }
    NRF_LOG_INFO("> AES: finish test");
#endif

    NRF_LOG_FLUSH();
}

NO_RETURN_ATTR void recovery_mode_main_loop(void) {
    NRF_LOG_ERROR("keyplus: encountered critical error");
    NRF_LOG_HEXDUMP_INFO(g_error_code_table, SIZE_ERROR_CODE_TABLE)
    NRF_LOG_FLUSH();

    while (1) {
        if (is_usb_configured()) {
            // send_keyboard_report();
            // send_media_report();
            // send_mouse_report();
            send_vendor_report();
        }

        handle_vendor_out_reports();

        wdt_kick();

        // Even if we miss an event enabling USB, USB event would wake us up.
        __WFE();
        // Clear SEV flag if CPU was woken up by event
        __SEV();
        __WFE();

        UNUSED_RETURN_VALUE(NRF_LOG_PROCESS());
    }
}

int ble_test_main(uint8_t x);

int main(void) {
    // usb_test();

#if USE_BLUETOOTH
    ble_test_main(0);
#endif


    init_logging();

    NRF_LOG_INFO("main() started");

    // Setup
    {
        usb_init_power_clock();
        timer_init();

        io_map_init();
        hardware_init();
        init_error_system();


        NRF_LOG_INFO("Setting up USB");
        usb_setup_nrf();
        // USB setup
        reset_usb_reports();

        NRF_LOG_INFO("loading settings from flash");
        settings_load_from_flash();
        aes_key_init(g_rf_settings.ekey, g_rf_settings.dkey);
        keyboards_init();

        if (has_critical_error()) {
            recovery_mode_main_loop();
        }

        matrix_scanner_init();

        #if 1
            g_rf_settings.hw_type = RF_HW_NRF52_ESB;
            nrf52_esb_hw_init();
            rf_init_receive();
        #else
            g_rf_enabled = false;
        #endif
    }
    print_settings_info();

    NRF_LOG_INFO("Starting main() loop");

    uint32_t last_time = 0;

    while (true) {
        if (has_critical_error()) {
            recovery_mode_main_loop();
        }

        {
            uint32_t new_time = timer_read_ms();
            if ((uint32_t)(new_time - last_time) >= 1000) {
                NRF_LOG_INFO("time: %d", timer_read_ms());
                last_time = new_time;
            }
        }

        // Matrix scanning
        {
            bool scan_changed = false;

            scan_changed |= matrix_scan();
            if (scan_changed) {
                uint8_t matrix_data[32];
                const uint8_t use_deltas = true;
                const uint8_t data_size = get_matrix_data(matrix_data, use_deltas);

                keyboard_update_device_matrix(GET_SETTING(device_id), matrix_data);
            }

            interpret_all_keyboard_matrices();

        }

#if USE_NRF24
        if (g_rf_enabled) {
            #if USE_UNIFYING
                if (unifying_is_pairing_active()) {
                    unifying_pairing_poll();
                } else {
                    rf_task();
                }
                unifying_mouse_handle();
            #else
                rf_task();
            #endif
        }
#endif

        macro_task();
        mouse_key_task();

        if (is_usb_configured()) {
            send_keyboard_report();
            send_media_report();
            send_mouse_report();
            send_vendor_report();
        }

        // TODO: testing needed
        handle_vendor_out_reports();

        sticky_key_task();
        hold_key_task(false);

        UNUSED_RETURN_VALUE(NRF_LOG_PROCESS());

        // Even if we miss an event enabling USB, USB event would wake us up.
        __WFE();
        // Clear SEV flag if CPU was woken up by event
        __SEV();
        __WFE();
    }
}
