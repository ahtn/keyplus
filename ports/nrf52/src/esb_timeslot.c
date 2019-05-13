#include "esb_timeslot.h"

#include "app_scheduler.h"
#include "app_error.h"
#include "nrf_soc.h"
#include "nrf_log.h"

#include "nrf_esb.h"
#include "nrf_esb_error_codes.h"

#define TIMESLOT_BEGIN_IRQn        LPCOMP_IRQn
#define TIMESLOT_BEGIN_IRQHandler  LPCOMP_IRQHandler
#define TIMESLOT_BEGIN_IRQPriority 1
#define TIMESLOT_END_IRQn          QDEC_IRQn
#define TIMESLOT_END_IRQHandler    QDEC_IRQHandler
#define TIMESLOT_END_IRQPriority   1
#define UESB_RX_HANDLE_IRQn        WDT_IRQn
#define UESB_RX_HANDLE_IRQHandler  WDT_IRQHandler
#define UESB_RX_HANDLE_IRQPriority 3

#define MAX_TX_ATTEMPTS 10

#define TS_LEN_US            (2000UL)
// #define TX_LEN_EXTENSION_US  (10000UL)
#define TX_LEN_EXTENSION_US  (5000UL)
#define TS_SAFETY_MARGIN_US  (700UL)    /**< The timeslot activity should be finished with this much to spare. */
#define TS_EXTEND_MARGIN_US  (1000UL)   /**< The timeslot activity should request an extension this long before end of timeslot. */
#define TS_INTERVAL_US       (100000UL)

#define MAIN_DEBUG                           0x12345678UL

static timeslot_data_handler_t m_evt_handler = 0;
static volatile bool        m_timeslot_session_open;
static uint32_t             m_blocked_cancelled_count;
static uint32_t             m_tx_attempts = 0;
static volatile uint32_t    m_total_timeslot_length = 0;
static fifo_t               m_transmit_fifo;
static nrf_esb_config_t     m_esb_config;

typedef enum {
    TIMESLOT_STATE_IDLE, /* Default state */
    TIMESLOT_STATE_RX,   /* Waiting for packets */
    TIMESLOT_STATE_TX    /* Trying to transmit packet */
} timeslot_state_t;

static timeslot_stats_t m_stats;

static volatile timeslot_state_t m_timeslot_state = TIMESLOT_STATE_IDLE;


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

#include "core/settings.h"
#include "core/rf.h"
#include "core/nrf52_esb.h"

static nrf_esb_payload_t        m_rx_payload;
void nrf52_esb_packet_buffer_add(nrf_esb_payload_t *packet);

#define NUM_ESB_PIPES 6

static uint8_t m_base_addr_0[4];
static uint8_t m_base_addr_1[4];
static uint8_t m_addr_prefix[NUM_ESB_PIPES];
static uint8_t m_rf_channel;

// Function prototypes
void RADIO_IRQHandler(void);
static void nrf_timeslot_esb_event_handler(nrf_esb_evt_t const * p_event);
static nrf_radio_signal_callback_return_param_t * radio_callback (uint8_t signal_type);

static void nrf52_esb_config_init_common(nrf_esb_mode_t mode, uint8_t tx_pipe_num) {
    uint8_t i;

    g_rf_settings.hw_type = RF_HW_NRF52_ESB;

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

    // NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;
    // NRF_CLOCK->TASKS_HFCLKSTART = 1;

    // while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0);

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

uint32_t esb_timeslot_init(timeslot_data_handler_t evt_handler) {
    m_evt_handler = evt_handler;

    // Setup m_esb_config for the current mode
    if (1) {
        nrf52_esb_config_init_rx();
    } else {
        nrf52_esb_config_init_tx();
    }

    NRF_LOG_HEXDUMP_INFO(m_base_addr_0, 4);
    NRF_LOG_HEXDUMP_INFO(m_base_addr_1, 4);
    NRF_LOG_HEXDUMP_INFO(m_addr_prefix, 6);

    m_timeslot_state = TIMESLOT_STATE_IDLE;

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

    NVIC_ClearPendingIRQ(UESB_RX_HANDLE_IRQn);
    NVIC_SetPriority(UESB_RX_HANDLE_IRQn, UESB_RX_HANDLE_IRQPriority);
    NVIC_EnableIRQ(UESB_RX_HANDLE_IRQn);

    return NRF_SUCCESS;
}

struct timeslot_stats_t get_timeslot_stats(void) {
    return m_stats;
}

uint32_t esb_timeslot_start(void) {
    uint32_t err_code;

    if (m_timeslot_session_open) {
        return NRF_ERROR_INVALID_STATE;
    }

    // m_uesb_config.rf_channel = rf_channel;
    // memcpy(m_uesb_config.rx_address_p0, rf_address, 5);

    m_blocked_cancelled_count  = 0;

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
    m_stats.extensions = 0;

    m_timeslot_session_open = true;

    return NRF_SUCCESS;
}

uint32_t esb_timeslot_stop() {
    return NRF_ERROR_NOT_SUPPORTED;
}

void nrf_timeslot_esb_event_handler(nrf_esb_evt_t const * p_event) {
    // led_testing_toggle(2);
    switch (p_event->evt_id) {
        case NRF_ESB_EVENT_TX_SUCCESS: {
            NRF_LOG_DEBUG("TX SUCCESS EVENT");
            // tx_packet_count++;
            nrf_esb_payload_t payload;
            uint32_t payload_len;

            // Successful transmission. Can now remove packet from our FIFO
            // payload_len = sizeof(payload);
            // fifo_get_pkt(&m_transmit_fifo, (uint8_t *) &payload, &payload_len);
            // APP_ERROR_CHECK_BOOL(payload_len == sizeof(payload));

            m_tx_attempts = 0;
            // m_timeslot_state = TIMESLOT_STATE_RX;
        } break;
        case NRF_ESB_EVENT_TX_FAILED: {
            NRF_LOG_DEBUG("TX FAILED EVENT");
            // tx_failed_count++;
            // nrf_esb_flush_tx();
            // nrf_esb_start_tx();
            // nrf_esb_pop_tx();
            //
            nrf_esb_flush_tx();
            m_tx_attempts += 1;
            // m_timeslot_state = TIMESLOT_STATE_RX;
        } break;
        case NRF_ESB_EVENT_RX_RECEIVED: {
            NRF_LOG_DEBUG("RX RECEIVED EVENT");

            // Data reception is handled in a lower priority interrupt
            NVIC_SetPendingIRQ(UESB_RX_HANDLE_IRQn);
        } break;
    }
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
        NRF_TIMER0->INTENSET            = (TIMER_INTENSET_COMPARE0_Set << TIMER_INTENSET_COMPARE0_Pos) |
                                          (TIMER_INTENSET_COMPARE1_Set << TIMER_INTENSET_COMPARE1_Pos);
        NRF_TIMER0->CC[0]               = (TS_LEN_US - TS_SAFETY_MARGIN_US);
        NRF_TIMER0->CC[1]               = (TS_LEN_US - TS_EXTEND_MARGIN_US);
        NRF_TIMER0->BITMODE             = (TIMER_BITMODE_BITMODE_24Bit << TIMER_BITMODE_BITMODE_Pos);
        NRF_TIMER0->TASKS_START         = 1;

        NRF_RADIO->POWER                = (RADIO_POWER_POWER_Enabled << RADIO_POWER_POWER_Pos);

        NVIC_EnableIRQ(TIMER0_IRQn);
    } break;

    case NRF_RADIO_CALLBACK_SIGNAL_TYPE_TIMER0: {
        if (NRF_TIMER0->EVENTS_COMPARE[0] &&
           (NRF_TIMER0->INTENSET & (TIMER_INTENSET_COMPARE0_Enabled << TIMER_INTENCLR_COMPARE0_Pos)))
        {
            NRF_TIMER0->TASKS_STOP  = 1;
            NRF_TIMER0->EVENTS_COMPARE[0] = 0;

            // This is the "timeslot is about to end" timeout

            // Disabling UESB is done in a lower interrupt priority
            NVIC_SetPendingIRQ(TIMESLOT_END_IRQn);

            // Schedule next timeslot
            return (nrf_radio_signal_callback_return_param_t*) &m_rsc_return_sched_next;
        }

        if (NRF_TIMER0->EVENTS_COMPARE[1] &&
           (NRF_TIMER0->INTENSET & (TIMER_INTENSET_COMPARE1_Enabled << TIMER_INTENCLR_COMPARE1_Pos)))
        {
            NRF_TIMER0->EVENTS_COMPARE[1] = 0;

            // This is the "try to extend timeslot" timeout

            if (m_total_timeslot_length < (128000000UL - 1UL - TX_LEN_EXTENSION_US))
            {
                // Request timeslot extension if total length does not exceed 128 seconds
                return (nrf_radio_signal_callback_return_param_t*) &m_rsc_extend;
            }
            else
            {
                // Return with no action request
                return (nrf_radio_signal_callback_return_param_t*) &m_rsc_return_no_action;
            }
        }
    } break;

    case NRF_RADIO_CALLBACK_SIGNAL_TYPE_RADIO: {
        // Call the uesb IRQHandler
        RADIO_IRQHandler();
    } break;

    case NRF_RADIO_CALLBACK_SIGNAL_TYPE_EXTEND_FAILED: {
        // NVIC_SetPendingIRQ(TIMESLOT_END_IRQn);
        // Don't do anything. Our timer will expire before timeslot ends
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

        // UESB packet receiption and transmission are synchronized at the beginning of timeslot extensions.
        // Ideally we would also transmit at the beginning of the initial timeslot, not only extensions,
        // but this is to simplify a bit.
        NVIC_SetPendingIRQ(TIMESLOT_BEGIN_IRQn);
    } break;

    default: {
        app_error_handler(MAIN_DEBUG, __LINE__, (const uint8_t*)__FILE__);
    } break;

    };

    // Fall-through return: return with no action request
    return (nrf_radio_signal_callback_return_param_t*) &m_rsc_return_no_action;
}

/**@brief Function for handling the Application's system events.
 *
 * @param[in]   sys_evt   system event.
 */
void ut_on_sys_evt(uint32_t sys_evt) {
    switch(sys_evt) {
        case NRF_EVT_FLASH_OPERATION_SUCCESS:
        case NRF_EVT_FLASH_OPERATION_ERROR: {
        } break;

        case NRF_EVT_RADIO_BLOCKED:
        case NRF_EVT_RADIO_CANCELED: {
            // Blocked events are rescheduled with normal priority. They could also
            // be rescheduled with high priority if necessary.
            uint32_t err_code = sd_radio_request((nrf_radio_request_t*) &m_timeslot_req_earliest);
            APP_ERROR_CHECK(err_code);

            m_blocked_cancelled_count++;
        } break;

        case NRF_EVT_RADIO_SIGNAL_CALLBACK_INVALID_RETURN: {
            // DEBUG_PRINT("NRF_EVT_RADIO_SIGNAL_CALLBACK_INVALID_RETURN\r\n");
            app_error_handler(MAIN_DEBUG, __LINE__, (const uint8_t*)__FILE__);
        } break;

        case NRF_EVT_RADIO_SESSION_CLOSED: {
            m_timeslot_session_open = false;

            // DEBUG_PRINT("NRF_EVT_RADIO_SESSION_CLOSED\r\n");
        } break;

        case NRF_EVT_RADIO_SESSION_IDLE: {
            // DEBUG_PRINT("NRF_EVT_RADIO_SESSION_IDLE\r\n");

            uint32_t err_code = sd_radio_session_close();
            APP_ERROR_CHECK(err_code);
        } break;

        default: {
            // No implementation needed.
        } break;
    }
}

/**@brief IRQHandler used for execution context management.
  *        This handler is used to initiate UESB RX/TX
  */
void TIMESLOT_BEGIN_IRQHandler(void) {
    nrf_esb_payload_t   payload;
    uint32_t            payload_len;
    uint32_t            err_code;

    m_stats.start++;

#if 0
    if (m_total_timeslot_length == 0) {
        nrf52_esb_timeslot_start_rx();
        m_timeslot_state = TIMESLOT_STATE_RX;
    } else {
        m_stats.extensions++;
    }
#else
    nrf52_esb_timeslot_start_rx();
    m_timeslot_state = TIMESLOT_STATE_RX;
#endif

#if 0
    // Packet transmission is syncrhonized to the beginning of timeslots
    // Check FIFO for packets and transmit if not empty
    if (
        m_transmit_fifo.free_items < sizeof(m_transmit_fifo.buf)
        && m_timeslot_state != TIMESLOT_STATE_TX
    ) {
        // There are packets in the FIFO: Start transmitting
        payload_len = sizeof(payload);

        // Copy packet from FIFO. Packet isn't removed until transmissions succeeds or max retries has been exceeded
        if (m_tx_attempts < MAX_TX_ATTEMPTS) {
            fifo_peek_pkt(&m_transmit_fifo, (uint8_t *) &payload, &payload_len);
            APP_ERROR_CHECK_BOOL(payload_len == sizeof(payload));
        } else {
            fifo_get_pkt(&m_transmit_fifo, (uint8_t *) &payload, &payload_len);
            APP_ERROR_CHECK_BOOL(payload_len == sizeof(payload));

            m_tx_attempts = 0;
        }

        // if (m_timeslot_state == TIMESLOT_STATE_RX) {
        //     nrf_esb_stop_rx();
        // }

        // err_code = nrf_esb_write_payload(&payload);
        // APP_ERROR_CHECK(err_code);

        m_timeslot_state = TIMESLOT_STATE_TX;
    } else {
        // No packets in the FIFO: start reception

        m_timeslot_state = TIMESLOT_STATE_RX;
    }
#endif
}

/**@brief IRQHandler used for execution context management.
  *        This handler is used to stop and disable UESB
  */
void TIMESLOT_END_IRQHandler(void) {
    uint32_t err_code;
    m_stats.end++;

    // Timeslot is about to end

#if 0
    err_code = nrf_esb_stop_rx();
    if (err_code != UESB_SUCCESS) {
        // Override
        NRF_RADIO->INTENCLR      = 0xFFFFFFFF;
        NRF_RADIO->TASKS_DISABLE = 1;
    }

    nrf_esb_disable();
#elif 0
    err_code = nrf_esb_stop_rx();

    nrf_esb_disable();
#elif 0
    if (m_timeslot_state == TIMESLOT_STATE_RX) {
        err_code = nrf_esb_stop_rx();

        if (err_code == NRF_ESB_ERROR_NOT_IN_RX_MODE) {
            // ignore
        } else {
            APP_ERROR_CHECK(err_code);
        }
    }

    nrf_esb_suspend();
#else
    nrf_esb_suspend();
    // nrf_esb_disable();
#endif

    m_total_timeslot_length = 0;
}


/**@brief IRQHandler used for execution context management.
  *        This handler is used to notify of received data
  */
void UESB_RX_HANDLE_IRQHandler(void) {
    m_stats.rx++;

    while (nrf_esb_read_rx_payload(&m_rx_payload) == NRF_SUCCESS) {
        if (m_rx_payload.length > 0) {
            NRF_LOG_DEBUG("RX RECEIVED PAYLOAD");
            // rx_packet_count++;
            nrf52_esb_packet_buffer_add(&m_rx_payload);
        }
    }
#if 0
    uesb_payload_t payload;
    uint32_t       err_code;

    // Get packet from UESB buffer
    uesb_read_rx_payload(&payload);

    // Give packet to main application via the scheduler
    err_code = app_sched_event_put(payload.data, payload.length, m_evt_handler);
    APP_ERROR_CHECK(err_code);
#endif
}
