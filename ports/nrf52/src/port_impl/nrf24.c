// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <string.h>

#include "app_error.h"

#include "nrf_log.h"
#include "nrf_gpio.h"
#include "nrf_drv_gpiote.h"
#include "nrfx_spim.h"

#include "core/error.h"
#include "core/io_map.h"
#include "core/nrf24.h"
#include "core/rf.h"

#define NRF24_PIN_CSN   NRF_GPIO_PIN_MAP(1, 12)
#define NRF24_PIN_MOSI  NRF_GPIO_PIN_MAP(1, 13)
#define NRF24_PIN_MISO  NRF_GPIO_PIN_MAP(1, 14)
#define NRF24_PIN_SCK   NRF_GPIO_PIN_MAP(1, 15)

#define NRF24_PIN_CE    NRF_GPIO_PIN_MAP(1, 11)
#define NRF24_PIN_IRQ   NRF_GPIO_PIN_MAP(1, 10)

#define SPI_INSTANCE  1
static const nrfx_spim_t spi = NRFX_SPIM_INSTANCE(SPI_INSTANCE);

#define SPI_BUFFER_MAX_SIZE (32+1)
static uint8_t m_tx_buf[SPI_BUFFER_MAX_SIZE];
static uint8_t m_rx_buf[SPI_BUFFER_MAX_SIZE];
static volatile bool spi_xfer_done;

nrf24_status_t nrf24_read_buf(nrf24_spi_command_t cmd, XRAM uint8_t *dest, uint8_t len) {
    nrfx_spim_xfer_desc_t xfer_desc;

    m_tx_buf[0] = cmd;

    xfer_desc.p_tx_buffer = m_tx_buf;
    xfer_desc.tx_length = 1;
    xfer_desc.p_rx_buffer = m_rx_buf;
    xfer_desc.rx_length = 1+len;

    spi_xfer_done = false;
    APP_ERROR_CHECK(nrfx_spim_xfer(&spi, &xfer_desc, 0));

    while (!spi_xfer_done) { __WFE(); }

    memcpy(dest, m_rx_buf+1, len);

    return m_rx_buf[0]; // STATUS value to return
}


nrf24_status_t nrf24_write_buf(nrf24_spi_command_t cmd, const XRAM uint8_t *src, uint8_t len) {
    nrfx_spim_xfer_desc_t xfer_desc;

    m_tx_buf[0] = cmd;
    memcpy(m_tx_buf+1, src, len);

    xfer_desc.p_tx_buffer = m_tx_buf;
    xfer_desc.tx_length = 1+len;
    xfer_desc.p_rx_buffer = m_rx_buf;
    xfer_desc.rx_length = 1+len;

    spi_xfer_done = false;
    APP_ERROR_CHECK(nrfx_spim_xfer(&spi, &xfer_desc, 0));

    while (!spi_xfer_done) { __WFE(); }

    return m_rx_buf[0]; // STATUS value to return
}

uint8_t nrf24_reg(nrf24_register_t reg, uint8_t val) {
    nrfx_spim_xfer_desc_t xfer_desc = NRFX_SPIM_XFER_TRX(
        m_tx_buf,
        2,
        m_rx_buf,
        2
    );

    m_tx_buf[0] = reg; // register read/write command
    m_tx_buf[1] = val; // value to write (if needed)

    spi_xfer_done = false;
    APP_ERROR_CHECK(nrfx_spim_xfer(&spi, &xfer_desc, 0));

    while (!spi_xfer_done) { __WFE(); }

    return m_rx_buf[1]; // value read from register
}

nrf24_status_t nrf24_read_status(void) {
    const nrfx_spim_xfer_desc_t xfer_desc = NRFX_SPIM_XFER_TRX(
        m_tx_buf,
        1,
        m_rx_buf,
        1
    );

    m_tx_buf[0] = 0xFF;

    spi_xfer_done = false;
    APP_ERROR_CHECK(nrfx_spim_xfer(&spi, &xfer_desc, 0));

    while (!spi_xfer_done) { __WFE(); }

    return m_rx_buf[0];
}

void nrf24_ce(uint8_t val) {
    nrf_gpio_pin_write(NRF24_PIN_CE, val);
}

void spim_event_handler(nrfx_spim_evt_t const * p_event,
    void *                  p_context)
{
    spi_xfer_done = true;
}


void nrf24_init(void) {
    uint32_t err = 0;

    err |= IO_MAP_CLAIM_PIN_NUMBER(NRF24_PIN_CE);
    err |= IO_MAP_CLAIM_PIN_NUMBER(NRF24_PIN_IRQ);

    err |= IO_MAP_CLAIM_PIN_NUMBER(NRF24_PIN_CSN);
    err |= IO_MAP_CLAIM_PIN_NUMBER(NRF24_PIN_MISO);
    err |= IO_MAP_CLAIM_PIN_NUMBER(NRF24_PIN_MOSI);
    err |= IO_MAP_CLAIM_PIN_NUMBER(NRF24_PIN_SCK);

    if (err) {
        return;
    }

    nrf_gpio_cfg_output(NRF24_PIN_CE);

    nrfx_spim_config_t spi_config = NRFX_SPIM_DEFAULT_CONFIG;
    spi_config.frequency      = NRF_SPIM_FREQ_8M;
    spi_config.ss_pin         = NRF24_PIN_CSN;
    spi_config.miso_pin       = NRF24_PIN_MISO;
    spi_config.mosi_pin       = NRF24_PIN_MOSI;
    spi_config.sck_pin        = NRF24_PIN_SCK;
    spi_config.ss_active_high = false;
    spi_config.orc            = NRF_NOP;

    err = nrfx_spim_init(&spi, &spi_config, spim_event_handler, NULL);

    if (err != NRF_SUCCESS) {
        register_error(ERROR_NRF24_BAD_SPI_CONNECTION);
    }
    APP_ERROR_CHECK(err);
}

void nrf24_disable(void) {
}

/*********************************************************************
 *                           irq handlers                            *
 *********************************************************************/

// NOTE: currently disabled.
//
// We can't control the NRF24L01+ from an interrupt because the SPI driver we
// use relies on other interrupts, so it's easier just to poll instead.
//
// However, might want to enable the interrupt to allow us to wake from sleep
// modes, and it will also help us avoid unnecessary SPI transactions

void nrf24_irq_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {
    // bsp_board_led_invert(0);
    // rf_isr();
}

void rf_init_receive_irq(void) {
    ret_code_t err_code;

    err_code = nrf_drv_gpiote_init();
    APP_ERROR_CHECK(err_code);

    nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
    in_config.pull = NRF_GPIO_PIN_PULLUP;

    err_code = nrf_drv_gpiote_in_init(NRF24_PIN_IRQ, &in_config, nrf24_irq_handler);
    APP_ERROR_CHECK(err_code);

}

void rf_enable_receive_irq(void) {
    nrf_drv_gpiote_in_event_enable(NRF24_PIN_IRQ, true);
}

void rf_disable_receive_irq(void) {
    nrf_drv_gpiote_in_event_disable(NRF24_PIN_IRQ);
}

uint8_t nrf24_irq(void) {
    return nrf_gpio_pin_read(NRF24_PIN_IRQ);
}
