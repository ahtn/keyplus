// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "app_error.h"

#include "nrf_delay.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "core/flash.h"
#include "core/settings.h"
#include "core/nonce.h"
#include "core/aes.h"

//
void flash_write_test(void) {
    uint8_t data[] = {0,1,2,3,4,5,6,7,8};
    flash_write(
        data,
        0x040066,
        sizeof(data)
    );
}

void init_logging(void) {
    uint32_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_DEFAULT_BACKENDS_INIT();
}

int main(void) {
    uint16_t sid = 0xFFFF;
    init_logging();

    NRF_LOG_INFO("main() started");

    settings_load_from_flash();

    sid = load_session_id();
    NRF_LOG_INFO("sid: %d", sid);

    NRF_LOG_INFO("=== Read settings === ");
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
    aes_key_init(g_rf_settings.ekey, g_rf_settings.dkey);
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

    NRF_LOG_INFO("Starting main loop");

    while (true) {
        nrf_delay_ms(1000);
        NRF_LOG_FLUSH();
    }
}
