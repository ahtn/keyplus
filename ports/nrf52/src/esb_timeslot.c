// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "esb_timeslot.h"

#include "app_scheduler.h"
#include "app_error.h"
#include "nrf_soc.h"
#include "nrf_log.h"
#include "nrf_sdh.h"

#include "nrf_esb.h"
#include "nrf_esb_error_codes.h"

#include "core/led.h"

#define TIMESLOT_BEGIN_IRQn        LPCOMP_IRQn
#define TIMESLOT_BEGIN_IRQHandler  LPCOMP_IRQHandler
#define TIMESLOT_BEGIN_IRQPriority 1
#define TIMESLOT_END_IRQn          QDEC_IRQn
#define TIMESLOT_END_IRQHandler    QDEC_IRQHandler
#define TIMESLOT_END_IRQPriority   1

#define TS_LEN_US            (5000UL)   //< Starting timeslot length in µs
#define TX_LEN_EXTENSION_US  (5000UL)   //< Length of timeslot extension in µs

/// The timeslot activity should be finished with this much to spare.
#define TS_SAFETY_MARGIN_US  (700UL)
/// The timeslot activity should request an extension this long before end of timeslot.
#define TS_EXTEND_MARGIN_US  (2000UL)

#define MAX_TX_ATTEMPTS 10
#define MAIN_DEBUG 0x12345678UL

static timeslot_data_handler_t m_evt_handler = 0;
static volatile bool        m_timeslot_session_open;
static uint32_t             m_tx_attempts = 0;
static volatile uint32_t    m_total_timeslot_length = 0;
static fifo_t               m_transmit_fifo;
static nrf_esb_config_t     m_esb_config;
static volatile bool        m_flash_busy = false;

typedef enum {
    TIMESLOT_STATE_IDLE,   // timeslot is inactive
    TIMESLOT_STATE_START,  // timeslot just started
    TIMESLOT_STATE_ACTIVE, // timeslot has started and BEGIN_IRQ has been called
    TIMESLOT_STATE_EXTEND_FAILED, // failed to extend timeslot
} timeslot_state_t;

static volatile timeslot_state_t m_state = TIMESLOT_STATE_IDLE;

static timeslot_stats_t m_stats;

// Function prototypes
void RADIO_IRQHandler(void);
static void nrf_timeslot_esb_event_handler(nrf_esb_evt_t const * p_event);
static nrf_radio_signal_callback_return_param_t * radio_callback (uint8_t signal_type);

//
// Timeslot requests
//

/// This will be used when requesting the first timeslot or any time a timeslot
/// is blocked or cancelled.
static nrf_radio_request_t m_timeslot_req_earliest = {
    NRF_RADIO_REQ_TYPE_EARLIEST,
    .params.earliest = {
        NRF_RADIO_HFCLK_CFG_XTAL_GUARANTEED,
        NRF_RADIO_PRIORITY_NORMAL,
        TS_LEN_US,
        NRF_RADIO_EARLIEST_TIMEOUT_MAX_US
    }
};

/// This will be used at the end of each timeslot to request the next timeslot.
static nrf_radio_signal_callback_return_param_t m_rsc_return_sched_next = {
    NRF_RADIO_SIGNAL_CALLBACK_ACTION_REQUEST_AND_END,
    .params.request = {
            (nrf_radio_request_t*) &m_timeslot_req_earliest
    }
};

/// This will be used at the end of each timeslot to request an extension of
/// the timeslot.
static nrf_radio_signal_callback_return_param_t m_rsc_extend = {
    NRF_RADIO_SIGNAL_CALLBACK_ACTION_EXTEND,
    .params.extend = {TX_LEN_EXTENSION_US}
};

/// This will be used at the end of each timeslot to request the next timeslot.
static nrf_radio_signal_callback_return_param_t m_rsc_return_no_action = {
    NRF_RADIO_SIGNAL_CALLBACK_ACTION_NONE,
    .params.request = {NULL}
};

// TODO: integrate this with non-timesloted ESB code
#include "core/settings.h"
#include "core/rf.h"
#include "core/nrf52_esb.h"

#define NUM_ESB_PIPES 6

static nrf_esb_payload_t        m_rx_payload;
void nrf52_esb_packet_buffer_add(nrf_esb_payload_t *packet);

static uint8_t m_base_addr_0[4];
static uint8_t m_base_addr_1[4];
static uint8_t m_addr_prefix[NUM_ESB_PIPES];
static uint8_t m_rf_channel;

static void nrf52_esb_config_init_common(nrf_esb_mode_t mode, uint8_t tx_pipe_num) {
    uint8_t i;

    // memcpy(m_base_addr_0, g_rf_settings.pipe_addr_0+1, 4);
    for (i = 0; i < 4; ++i) {
        m_base_addr_0[i] = g_rf_settings.pipe_addr_0[i+1];
    }
    for (i = 0; i < 4; ++i) {
        m_base_addr_1[i] = g_rf_settings.pipe_addr_1[i+1];
    }

    m_addr_prefix[0] = g_rf_settings.pipe_addr_0[0];
    m_addr_prefix[1] = g_rf_settings.pipe_addr_1[0];
    m_addr_prefix[2] = g_rf_settings.pipe_addr_2;
    m_addr_prefix[3] = g_rf_settings.pipe_addr_3;
    m_addr_prefix[4] = g_rf_settings.pipe_addr_4;
    m_addr_prefix[5] = g_rf_settings.pipe_addr_5;

    m_rf_channel = g_rf_settings.channel;

    // The ARD is given by `(ard + 1) * 250µs` with a maximum delay of 4ms.
    const uint8_t dev_ard = device_id_to_pipe_num(GET_SETTING(device_id)) + 1;
    const uint32_t ard_in_ms = (dev_ard + 1) * 250;
    const uint8_t arc = g_rf_settings.arc & 0x0F;

    const nrf_esb_config_t temp           = NRF_ESB_DEFAULT_CONFIG;
    m_esb_config                          = temp;
    m_esb_config.protocol                 = NRF_ESB_PROTOCOL_ESB_DPL;
    m_esb_config.retransmit_delay         = ard_in_ms;
    m_esb_config.bitrate                  = NRF_ESB_BITRATE_2MBPS;
    m_esb_config.crc                      = NRF_ESB_CRC_16BIT;
    m_esb_config.event_handler            = nrf_timeslot_esb_event_handler;
    m_esb_config.selective_auto_ack       = false;
    m_esb_config.payload_length           = 32;
    m_esb_config.retransmit_count         = arc;

    m_esb_config.mode                     = mode;
}

void nrf52_esb_config_init_tx( void ) {
    const uint8_t pipe_num = device_id_to_pipe_num(GET_SETTING(device_id));
    nrf52_esb_config_init_common(NRF_ESB_MODE_PTX, pipe_num);
}

void nrf52_esb_config_init_rx( void ) {
    nrf52_esb_config_init_common(NRF_ESB_MODE_PRX, 0);
}

uint32_t nrf52_esb_start_common(nrf_esb_mode_t mode) {
    ret_code_t err_code;

    err_code = nrf_esb_init(&m_esb_config);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_esb_set_base_address_0(m_base_addr_0);
    APP_ERROR_CHECK(err_code);

    if (mode == NRF_ESB_MODE_PRX) {
        err_code = nrf_esb_set_base_address_1(m_base_addr_1);
        APP_ERROR_CHECK(err_code);

        err_code = nrf_esb_set_prefixes(m_addr_prefix, NUM_ESB_PIPES);
        APP_ERROR_CHECK(err_code);
    } else if (mode == NRF_ESB_MODE_PTX) {
        err_code = nrf_esb_set_prefixes(m_addr_prefix, 1);
        APP_ERROR_CHECK(err_code);
    }

    err_code = nrf_esb_set_rf_channel(m_rf_channel);
    APP_ERROR_CHECK(err_code);

    return err_code;
}


uint32_t nrf52_esb_timeslot_start_tx(void) {
    ret_code_t err_code;

    err_code = nrf52_esb_start_common(NRF_ESB_MODE_PTX);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_esb_start_tx();
    APP_ERROR_CHECK(err_code);

    return err_code;
}

uint32_t nrf52_esb_timeslot_start_rx(void) {
    ret_code_t err_code;

    err_code = nrf52_esb_start_common(NRF_ESB_MODE_PRX);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_esb_flush_rx();
    APP_ERROR_CHECK(err_code);

    err_code = nrf_esb_start_rx();
    APP_ERROR_CHECK(err_code);

    return err_code;
}

/// @brief Initialize the ESB timeslot library
uint32_t esb_timeslot_init(void) {
    // Setup m_esb_config for the current mode
    if (1) {
        nrf52_esb_config_init_rx();
    } else {
        nrf52_esb_config_init_tx();
    }

    m_total_timeslot_length = 0;

    // m_uesb_config.retransmit_count   = 2;
    // m_uesb_config.event_handler      = uesb_event_handler;
    // m_uesb_config.radio_irq_priority = 0; // Needs to match softdevice priority

    fifo_init(&m_transmit_fifo);

    // Using three avilable interrupt handlers for interrupt level management
    // These can be any available IRQ as we're not using any of the hardware,
    // simply triggering them through software
    NVIC_ClearPendingIRQ(TIMESLOT_END_IRQn);
    NVIC_SetPriority(TIMESLOT_END_IRQn, TIMESLOT_BEGIN_IRQPriority);
    NVIC_EnableIRQ(TIMESLOT_END_IRQn);

    NVIC_ClearPendingIRQ(TIMESLOT_BEGIN_IRQn);
    NVIC_SetPriority(TIMESLOT_BEGIN_IRQn, TIMESLOT_BEGIN_IRQPriority);
    NVIC_EnableIRQ(TIMESLOT_BEGIN_IRQn);

    return NRF_SUCCESS;
}

/// @brief Get timeslot execution stats
struct timeslot_stats_t get_timeslot_stats(void) {
    return m_stats;
}

/// @brief Start requesting ESB timeslots
uint32_t esb_timeslot_start(void) {
    uint32_t err_code;

    if (m_timeslot_session_open) {
        return NRF_ERROR_INVALID_STATE;
    }

    err_code = sd_radio_session_open(radio_callback);
    if (err_code != NRF_SUCCESS) {
        return err_code;
    }

    err_code = sd_radio_request(&m_timeslot_req_earliest);
    if (err_code != NRF_SUCCESS) {
        return err_code;
    }

    m_stats.start = 0;
    m_stats.end = 0;
    m_stats.rx = 0;
    m_stats.tx = 0;
    m_stats.extensions = 0;

    m_stats.blocked  = 0;
    m_stats.canceled  = 0;

    m_timeslot_session_open = true;

    return NRF_SUCCESS;
}

uint32_t esb_timeslot_stop() {
    return NRF_ERROR_NOT_SUPPORTED;
}

/// @brief Remove the current packet from the timeslot ACK payload FIFO
static void remove_ack_payload(void) {
    nrf_esb_payload_t payload;
    uint32_t payload_len;

    if (fifo_is_empty(&m_transmit_fifo)) {
        return;
    }

    payload_len = sizeof(nrf_esb_payload_t);
    fifo_get_pkt(&m_transmit_fifo, (uint8_t *) &payload, &payload_len);
    APP_ERROR_CHECK_BOOL(payload_len == sizeof(nrf_esb_payload_t));
}

/// @brief Load a single packet from the timeslot FIFO into the nrf_esb FIFO
static void load_ack_payload(void) {
    uint32_t err_code;

    // If we have an ack payload upload it
    if ( !fifo_is_empty(&m_transmit_fifo) ) {
        uint32_t payload_len;
        nrf_esb_payload_t payload;

        // There are packets in the FIFO, so upload the next ack payload
        payload_len = sizeof(payload);
        fifo_peek_pkt(&m_transmit_fifo, (uint8_t *) &payload, &payload_len);
        APP_ERROR_CHECK_BOOL(payload_len == sizeof(payload));

        err_code = nrf_esb_write_payload(&payload);
        APP_ERROR_CHECK(err_code);
    }
}

/// @brief Event handler for nrf_esb
void nrf_timeslot_esb_event_handler(nrf_esb_evt_t const * p_event) {
    led_testing_toggle(4);
    switch (p_event->evt_id) {
        case NRF_ESB_EVENT_TX_SUCCESS: {
            NRF_LOG_DEBUG("TX SUCCESS EVENT");
            m_stats.tx++;

            // Successful transmission. Can now remove packet from our FIFO
            remove_ack_payload();
            load_ack_payload();

        } break;
        case NRF_ESB_EVENT_TX_FAILED: {
            NRF_LOG_DEBUG("TX FAILED EVENT");
            // nrf_esb_flush_tx();
            // nrf_esb_start_tx();
            // nrf_esb_pop_tx();
            //
            m_tx_attempts += 1;
        } break;
        case NRF_ESB_EVENT_RX_RECEIVED: {
            NRF_LOG_DEBUG("RX RECEIVED EVENT");

            while (nrf_esb_read_rx_payload(&m_rx_payload) == NRF_SUCCESS) {
                m_stats.rx++;
                if (m_rx_payload.length > 0) {
                    NRF_LOG_DEBUG("RX RECEIVED PAYLOAD");
                    // rx_packet_count++;
                    nrf52_esb_packet_buffer_add(&m_rx_payload);
                }
            }
        } break;
    }

    led_testing_toggle(4);
}

/// @brief Queue a ESB ack payload with ESB using timeslots
void esb_timeslot_ack_payload(nrf_esb_payload_t *tx_payload) {
    uint32_t err_code;
    bool success;

    CRITICAL_REGION_ENTER();
    success = fifo_put_pkt(&m_transmit_fifo, (uint8_t *)tx_payload, sizeof(nrf_esb_payload_t));
    if (!success) {
        NRF_LOG_INFO("TX_FIFO FULL");
        // clear fifo
        fifo_init(&m_transmit_fifo);
        // guaranteed to work this time
        success = fifo_put_pkt(&m_transmit_fifo, (uint8_t *)tx_payload, sizeof(nrf_esb_payload_t));
    }

    if (m_state == TIMESLOT_STATE_ACTIVE && !fifo_is_empty(&m_transmit_fifo)) {
        // No ack payload is currently loaded, so load this one
        err_code = nrf_esb_write_payload(tx_payload);
        APP_ERROR_CHECK(err_code);

        m_tx_attempts = 0;
    }
    CRITICAL_REGION_EXIT();
}

void esb_timeslot_clear_tx(void) {
    CRITICAL_REGION_ENTER();
    fifo_init(&m_transmit_fifo);
    CRITICAL_REGION_EXIT();
}

static nrf_radio_signal_callback_return_param_t * radio_callback (uint8_t signal_type) {
    // NOTE: This callback runs at lower-stack priority (the highest priority possible).
    switch (signal_type) {
    case NRF_RADIO_CALLBACK_SIGNAL_TYPE_START: {
        // TIMER0 is pre-configured for 1Mhz.
        NRF_TIMER0->TASKS_STOP          = 1;
        NRF_TIMER0->TASKS_CLEAR         = 1;
        NRF_TIMER0->MODE                = (TIMER_MODE_MODE_Timer << TIMER_MODE_MODE_Pos);
        NRF_TIMER0->EVENTS_COMPARE[0]   = 0;
        NRF_TIMER0->EVENTS_COMPARE[1]   = 0;
        NRF_TIMER0->INTENSET            = TIMER_INTENSET_COMPARE0_Msk | TIMER_INTENSET_COMPARE1_Msk ;
        NRF_TIMER0->CC[0]               = (TS_LEN_US - TS_SAFETY_MARGIN_US);
        NRF_TIMER0->CC[1]               = (TS_LEN_US - TS_EXTEND_MARGIN_US);
        NRF_TIMER0->BITMODE             = (TIMER_BITMODE_BITMODE_24Bit << TIMER_BITMODE_BITMODE_Pos);
        NRF_TIMER0->TASKS_START         = 1;

        NRF_RADIO->POWER                = (RADIO_POWER_POWER_Enabled << RADIO_POWER_POWER_Pos);

        // Call timeslot start handler
        m_state = TIMESLOT_STATE_START;
        NVIC_EnableIRQ(TIMER0_IRQn);
        NVIC_SetPendingIRQ(TIMESLOT_BEGIN_IRQn);
    } break;

    case NRF_RADIO_CALLBACK_SIGNAL_TYPE_RADIO: {
        RADIO_IRQHandler();
    } break;

    case NRF_RADIO_CALLBACK_SIGNAL_TYPE_TIMER0: {
        if (NRF_TIMER0->EVENTS_COMPARE[0] &&
           (NRF_TIMER0->INTENSET & TIMER_INTENSET_COMPARE0_Msk)
        ) {
            NRF_TIMER0->TASKS_STOP = 1;
            NRF_TIMER0->INTENCLR = TIMER_INTENSET_COMPARE0_Msk |
                                   TIMER_INTENSET_COMPARE1_Msk ;


            NRF_RADIO->INTENCLR      = 0xFFFFFFFF;
            NRF_RADIO->TASKS_DISABLE = 1;


            // Schedule next timeslot
            // return (nrf_radio_signal_callback_return_param_t*) &m_rsc_return_sched_next;
            return (nrf_radio_signal_callback_return_param_t*) &m_rsc_return_sched_next;
        }

        if (NRF_TIMER0->EVENTS_COMPARE[1] &&
           (NRF_TIMER0->INTENSET & TIMER_INTENSET_COMPARE1_Msk)
        ) {
            NRF_TIMER0->EVENTS_COMPARE[1] = 0;

            // This is the "try to extend timeslot" timeout

            // if (m_total_timeslot_length < (128000000UL - 1UL - TX_LEN_EXTENSION_US)) {
                // Request timeslot extension if total length does not exceed 128 seconds

            if ( m_total_timeslot_length <= 2*TX_LEN_EXTENSION_US ) {
                return (nrf_radio_signal_callback_return_param_t*) &m_rsc_extend;
            } else {
                NVIC_SetPendingIRQ(TIMESLOT_END_IRQn);

                // Return with no action request
                return (nrf_radio_signal_callback_return_param_t*) &m_rsc_return_no_action;
            }
        }
    } break;

    case NRF_RADIO_CALLBACK_SIGNAL_TYPE_EXTEND_FAILED: {
        // Don't do anything. Our timer will expire before timeslot ends
        m_state = TIMESLOT_STATE_EXTEND_FAILED;
        NVIC_SetPendingIRQ(TIMESLOT_END_IRQn);
        return (nrf_radio_signal_callback_return_param_t*) &m_rsc_return_no_action;
    } break;

    case NRF_RADIO_CALLBACK_SIGNAL_TYPE_EXTEND_SUCCEEDED: {
        // Extension succeeded: update timer
        NRF_TIMER0->TASKS_STOP          = 1;
        NRF_TIMER0->EVENTS_COMPARE[0]   = 0;
        NRF_TIMER0->EVENTS_COMPARE[1]   = 0;
        NRF_TIMER0->CC[0]               += (TX_LEN_EXTENSION_US - 25);
        NRF_TIMER0->CC[1]               += (TX_LEN_EXTENSION_US - 25);
        NRF_TIMER0->TASKS_START         = 1;

        // Keep track of total length
        m_total_timeslot_length += TX_LEN_EXTENSION_US;

        m_stats.extensions++;
    } break;

    default: {
        app_error_handler(MAIN_DEBUG, __LINE__, (const uint8_t*)__FILE__);
    } break;

    };

    // Fall-through return: return with no action request
    return (nrf_radio_signal_callback_return_param_t*) &m_rsc_return_no_action;
}

/// @brief For use to indicate a call to sd_flash_x() has been started.
void set_flash_busy_bit(void) {
    m_flash_busy = nrf_sdh_is_enabled();
}

/// @brief For use with sd_flash_x() to monitor completion of the flash operation)
bool is_flash_busy(void) {
    return m_flash_busy;
}

/// @brief Function for handling the Application's system events.
void soc_evt_handler(uint32_t sys_evt, void *p_context) {
    switch(sys_evt) {
        case NRF_EVT_FLASH_OPERATION_SUCCESS: {
            m_flash_busy = false;
        } break;

        case NRF_EVT_FLASH_OPERATION_ERROR: {
            app_error_handler(MAIN_DEBUG, __LINE__, (const uint8_t*)__FILE__);
        } break;

        case NRF_EVT_RADIO_BLOCKED:
        case NRF_EVT_RADIO_CANCELED: {
            if (sys_evt == NRF_EVT_RADIO_BLOCKED) {
                m_stats.blocked++;
            } else {
                m_stats.canceled++;
            }
            // Blocked events are rescheduled with normal priority. They could also
            // be rescheduled with high priority if necessary.
            uint32_t err_code = sd_radio_request((nrf_radio_request_t*) &m_timeslot_req_earliest);
            APP_ERROR_CHECK(err_code);

        } break;

        case NRF_EVT_RADIO_SIGNAL_CALLBACK_INVALID_RETURN: {
            DEBUG_PRINT("NRF_EVT_RADIO_SIGNAL_CALLBACK_INVALID_RETURN\r\n");
            app_error_handler(MAIN_DEBUG, __LINE__, (const uint8_t*)__FILE__);
        } break;

        case NRF_EVT_RADIO_SESSION_CLOSED: {
            DEBUG_PRINT("NRF_EVT_RADIO_SESSION_CLOSED\r\n");
            m_timeslot_session_open = false;
        } break;

        case NRF_EVT_RADIO_SESSION_IDLE: {
            DEBUG_PRINT("NRF_EVT_RADIO_SESSION_IDLE\r\n");
            uint32_t err_code = sd_radio_session_close();
            APP_ERROR_CHECK(err_code);
        } break;

        default: {
            // No implementation needed.
        } break;
    }
}

/// @brief IRQHandler called at the start of the time slot
void TIMESLOT_BEGIN_IRQHandler(void) {
    led_testing_toggle(3);
    m_stats.start++;

    nrf52_esb_timeslot_start_rx();
    m_state = TIMESLOT_STATE_ACTIVE;

    // If we have an ack payload upload it
    if ( !fifo_is_empty(&m_transmit_fifo) ) {
        if (m_tx_attempts < MAX_TX_ATTEMPTS) {
            m_tx_attempts++;
            load_ack_payload();
        } else {
            NRF_LOG_INFO("ACK Payload TX failed");
            m_tx_attempts = 0;
            remove_ack_payload();
            load_ack_payload();
        }
    } else {
        m_tx_attempts = 0;
    }
}

/// @brief IRQHandler handler called when ending the timeslot
void TIMESLOT_END_IRQHandler(void) {
    uint32_t err_code;
    m_stats.end++;
    led_testing_toggle(3);

    // Timeslot is about to end
    err_code = nrf_esb_stop_rx();
    APP_ERROR_CHECK(err_code);
    err_code = nrf_esb_flush_tx();
    APP_ERROR_CHECK(err_code);
    err_code = nrf_esb_flush_rx();
    APP_ERROR_CHECK(err_code);
    err_code = nrf_esb_disable();
    APP_ERROR_CHECK(err_code);

    m_state = TIMESLOT_STATE_IDLE;

    m_total_timeslot_length = 0;
}
