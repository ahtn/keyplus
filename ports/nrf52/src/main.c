// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "app_error.h"

#include "nrf_delay.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "core/timer.h"
#include "core/error.h"
#include "core/flash.h"
#include "core/settings.h"
#include "core/nonce.h"
#include "core/aes.h"

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

}

int usb_test(void);

int main(void) {
    usb_test();

    init_logging();

    NRF_LOG_INFO("main() started");

    // Setup
    {
        NRF_LOG_INFO("loading settings from flash");
        init_error_system();
        timer_init();
        settings_load_from_flash();
        aes_key_init(g_rf_settings.ekey, g_rf_settings.dkey);
        matrix_scanner_init();
    }

    print_settings_info();

    NRF_LOG_INFO("Starting main() loop");

    while (true) {
        nrf_delay_ms(10);
        if (matrix_scan()) {
            NRF_LOG_INFO(
                "g_matrix[0]: %02X%02X%02X%02X",
                g_matrix[0][3],
                g_matrix[0][2],
                g_matrix[0][1],
                g_matrix[0][0]
            );
            NRF_LOG_FLUSH();
        }
    }
}
