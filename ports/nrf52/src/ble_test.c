/**
 * Copyright (c) 2012 - 2019, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/** @file
 *
 * @defgroup ble_sdk_app_hids_keyboard_main main.c
 * @{
 * @ingroup ble_sdk_app_hids_keyboard
 * @brief HID Keyboard Sample Application main file.
 *
 * This file contains is the source code for a sample application using the HID, Battery and Device
 * Information Services for implementing a simple keyboard functionality.
 * Pressing Button 0 will send text 'hello' to the connected peer. On receiving output report,
 * it toggles the state of LED 2 on the mother board based on whether or not Caps Lock is on.
 * This application uses the @ref app_scheduler.
 *
 * Also it would accept pairing requests from any peer device.
 */

#include <stdint.h>
#include <string.h>
#include "nordic_common.h"
#include "nrf.h"
#include "nrf_assert.h"
#include "app_error.h"
#include "ble.h"
#include "ble_err.h"
#include "ble_hci.h"
#include "ble_srv_common.h"
#include "ble_advertising.h"
#include "ble_advdata.h"
#include "ble_hids.h"
#include "ble_bas.h"
#include "ble_dis.h"
#include "ble_conn_params.h"
#include "sensorsim.h"
#include "app_scheduler.h"
#include "nrf_sdh.h"
#include "nrf_sdh_soc.h"
#include "nrf_sdh_ble.h"
#include "app_timer.h"
#include "peer_manager.h"
#include "ble_conn_state.h"
#include "nrf_ble_gatt.h"
#include "nrf_ble_qwr.h"
#include "nrf_pwr_mgmt.h"
#include "peer_manager_handler.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "kp_ble/hid.h"
#include "hid_reports/hid_reports.h"

#include "esb_timeslot.h"

#include "nrf_drv_power.h"

#define SHIFT_BUTTON_ID                     1                          /**< Button used as 'SHIFT' Key. */

#define DEVICE_NAME                         "Nordic_Keyboard"                  /**< Name of device. Will be included in the advertising data. */
#define MANUFACTURER_NAME                   "NordicSemiconductor"              /**< Manufacturer. Will be passed to Device Information Service. */

#define APP_BLE_OBSERVER_PRIO               3                          /**< Application's BLE observer priority. You shouldn't need to modify this value. */
#define APP_SOC_OBSERVER_PRIO               1                          /**< Applications' SoC observer priority. You shouldn't need to modify this value. */
#define APP_BLE_CONN_CFG_TAG                1                          /**< A tag identifying the SoftDevice BLE configuration. */

#define BATTERY_LEVEL_MEAS_INTERVAL         APP_TIMER_TICKS(2000)              /**< Battery level measurement interval (ticks). */
#define MIN_BATTERY_LEVEL                   81                         /**< Minimum simulated battery level. */
#define MAX_BATTERY_LEVEL                   100                        /**< Maximum simulated battery level. */
#define BATTERY_LEVEL_INCREMENT             1                          /**< Increment between each simulated battery level measurement. */

#define PNP_ID_VENDOR_ID_SOURCE             0x02                       /**< Vendor ID Source. */
#define PNP_ID_VENDOR_ID                    USB_VID                    /**< Vendor ID. */
#define PNP_ID_PRODUCT_ID                   USB_PID                    /**< Product ID. */
#define PNP_ID_PRODUCT_VERSION              (USB_DEVICE_VERSION | USB_VERSION_ACCESS_TYPE)                    /**< Product Version. */

#define APP_ADV_FAST_INTERVAL               0x0028                     /**< Fast advertising interval (in units of 0.625 ms. This value corresponds to 25 ms.). */
#define APP_ADV_SLOW_INTERVAL               0x0C80                     /**< Slow advertising interval (in units of 0.625 ms. This value corrsponds to 2 seconds). */

#define APP_ADV_FAST_DURATION               3000                       /**< The advertising duration of fast advertising in units of 10 milliseconds. */
#define APP_ADV_SLOW_DURATION               18000                      /**< The advertising duration of slow advertising in units of 10 milliseconds. */

/*lint -emacro(524, MIN_CONN_INTERVAL) // Loss of precision */
#define MIN_CONN_INTERVAL                   MSEC_TO_UNITS(7.5, UNIT_1_25_MS)           /**< Minimum connection interval (7.5 ms) */
#define MAX_CONN_INTERVAL                   MSEC_TO_UNITS(30, UNIT_1_25_MS)        /**< Maximum connection interval (30 ms). */
#define SLAVE_LATENCY                       6                          /**< Slave latency. */
#define CONN_SUP_TIMEOUT                    MSEC_TO_UNITS(430, UNIT_10_MS)         /**< Connection supervisory timeout (430 ms). */

#define FIRST_CONN_PARAMS_UPDATE_DELAY      APP_TIMER_TICKS(5000)              /**< Time from initiating event (connect or start of notification) to first time sd_ble_gap_conn_param_update is called (5 seconds). */
#define NEXT_CONN_PARAMS_UPDATE_DELAY       APP_TIMER_TICKS(30000)             /**< Time between each call to sd_ble_gap_conn_param_update after the first call (30 seconds). */
#define MAX_CONN_PARAMS_UPDATE_COUNT        3                          /**< Number of attempts before giving up the connection parameter negotiation. */

#define SEC_PARAM_BOND                      1                          /**< Perform bonding. */
#define SEC_PARAM_MITM                      0                          /**< Man In The Middle protection not required. */
#define SEC_PARAM_LESC                      0                          /**< LE Secure Connections not enabled. */
#define SEC_PARAM_KEYPRESS                  0                          /**< Keypress notifications not enabled. */
#define SEC_PARAM_IO_CAPABILITIES           BLE_GAP_IO_CAPS_NONE               /**< No I/O capabilities. */
#define SEC_PARAM_OOB                       0                          /**< Out Of Band data not available. */
#define SEC_PARAM_MIN_KEY_SIZE              7                          /**< Minimum encryption key size. */
#define SEC_PARAM_MAX_KEY_SIZE              16                         /**< Maximum encryption key size. */

#define OUTPUT_REPORT_MAX_LEN               1                          /**< Maximum length of Output Report. */
#define INPUT_REPORT_KEYS_INDEX             0                          /**< Index of Input Report. */
#define OUTPUT_REPORT_BIT_MASK_CAPS_LOCK    0x02                       /**< CAPS LOCK bit in Output Report (based on 'LED Page (0x08)' of the Universal Serial Bus HID Usage Tables). */
#define INPUT_REP_REF_ID                    0                          /**< Id of reference to Keyboard Input Report. */
#define OUTPUT_REP_REF_ID                   0                          /**< Id of reference to Keyboard Output Report. */

#define MAX_BUFFER_ENTRIES                  5                          /**< Number of elements that can be enqueued */

#define BASE_USB_HID_SPEC_VERSION           0x0101                     /**< Version number of base USB HID Specification implemented by this application. */

#define INPUT_REPORT_KEYS_MAX_LEN           8                          /**< Maximum length of the Input Report characteristic. */

#define DEAD_BEEF                           0xDEADBEEF                     /**< Value used as error code on stack dump, can be used to identify stack location on stack unwind. */

#define SCHED_MAX_EVENT_DATA_SIZE           APP_TIMER_SCHED_EVENT_DATA_SIZE        /**< Maximum size of scheduler events. */
#ifdef SVCALL_AS_NORMAL_FUNCTION
#define SCHED_QUEUE_SIZE                    20                         /**< Maximum number of events in the scheduler queue. More is needed in case of Serialization. */
#else
#define SCHED_QUEUE_SIZE                    10                         /**< Maximum number of events in the scheduler queue. */
#endif

#define MODIFIER_KEY_POS                    0                          /**< Position of the modifier byte in the Input Report. */
#define SCAN_CODE_POS                       2                          /**< The start position of the key scan code in a HID Report. */
#define SHIFT_KEY_CODE                      0x02                       /**< Key code indicating the press of the Shift Key. */

#define MAX_KEYS_IN_ONE_REPORT              (INPUT_REPORT_KEYS_MAX_LEN - SCAN_CODE_POS)/**< Maximum number of key presses that can be sent in one Input Report. */


/** @} */

APP_TIMER_DEF(m_battery_timer_id);                  /**< Battery timer. */
BLE_HIDS_DEF(m_hids,                            /**< Structure used to identify the HID service. */
    NRF_SDH_BLE_TOTAL_LINK_COUNT,
    BLE_INPUT_REPORT_SIZE_BOOT_KB,
    BLE_INPUT_REPORT_SIZE_MOUSE,
    BLE_INPUT_REPORT_SIZE_SYSTEM,
    BLE_INPUT_REPORT_SIZE_CONSUMER,
    BLE_INPUT_REPORT_SIZE_NKRO,
    BLE_INPUT_REPORT_SIZE_VENDOR,
    BLE_OUTPUT_REPORT_SIZE_BOOT_KB,
    BLE_OUTPUT_REPORT_SIZE_VENDOR
    );
BLE_BAS_DEF(m_bas);                         /**< Structure used to identify the battery service. */
NRF_BLE_GATT_DEF(m_gatt);                       /**< GATT module instance. */
NRF_BLE_QWR_DEF(m_qwr);                         /**< Context for the Queued Write module.*/
BLE_ADVERTISING_DEF(m_advertising);                 /**< Advertising module instance. */

static bool m_in_boot_mode = false;                 /**< Current protocol mode. */
static uint16_t m_conn_handle = BLE_CONN_HANDLE_INVALID;        /**< Handle of the current connection. */
static sensorsim_cfg_t m_battery_sim_cfg;               /**< Battery Level sensor simulator configuration. */
static sensorsim_state_t m_battery_sim_state;               /**< Battery Level sensor simulator state. */
static bool m_caps_on = false;                      /**< Variable to indicate if Caps Lock is turned on. */
static pm_peer_id_t m_peer_id;                      /**< Device reference handle to the current bonded central. */


/// Whether the device has connected yet
static bool m_conn_established;

/// Whether the device has established a secure connection yet
static bool m_conn_sec_established;

static ble_uuid_t m_adv_uuids[] =
{ {BLE_UUID_HUMAN_INTERFACE_DEVICE_SERVICE, BLE_UUID_TYPE_BLE} };

static void on_hids_evt(ble_hids_t * p_hids, ble_hids_evt_t * p_evt);

/**@brief Callback function for asserts in the SoftDevice.
 *
 * @details This function will be called in case of an assert in the SoftDevice.
 *
 * @warning This handler is an example only and does not fit a final product. You need to analyze
 *          how your product is supposed to react in case of Assert.
 * @warning On assert from the SoftDevice, the system can only recover on reset.
 *
 * @param[in]   line_num   Line number of the failing ASSERT call.
 * @param[in]   file_name  File name of the failing ASSERT call.
 */
void assert_nrf_callback(uint16_t line_num, const uint8_t * p_file_name)
{
    app_error_handler(DEAD_BEEF, line_num, p_file_name);
}

/**@brief Function for setting filtered whitelist.
 *
 * @param[in] skip  Filter passed to @ref pm_peer_id_list.
 */
static void whitelist_set(pm_peer_id_list_skip_t skip)
{
    pm_peer_id_t peer_ids[BLE_GAP_WHITELIST_ADDR_MAX_COUNT];
    uint32_t peer_id_count = BLE_GAP_WHITELIST_ADDR_MAX_COUNT;

    ret_code_t err_code =
        pm_peer_id_list(peer_ids, &peer_id_count, PM_PEER_ID_INVALID, skip);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_INFO("\tm_whitelist_peer_cnt %d, MAX_PEERS_WLIST %d",
             peer_id_count + 1, BLE_GAP_WHITELIST_ADDR_MAX_COUNT);

    err_code = pm_whitelist_set(peer_ids, peer_id_count);
    APP_ERROR_CHECK(err_code);
}

/**@brief Function for setting filtered device identities.
 *
 * @param[in] skip  Filter passed to @ref pm_peer_id_list.
 */
static void identities_set(pm_peer_id_list_skip_t skip)
{
    pm_peer_id_t peer_ids[BLE_GAP_DEVICE_IDENTITIES_MAX_COUNT];
    uint32_t peer_id_count = BLE_GAP_DEVICE_IDENTITIES_MAX_COUNT;

    ret_code_t err_code =
        pm_peer_id_list(peer_ids, &peer_id_count, PM_PEER_ID_INVALID, skip);
    APP_ERROR_CHECK(err_code);

    err_code = pm_device_identities_list_set(peer_ids, peer_id_count);
    APP_ERROR_CHECK(err_code);
}

/**@brief Clear bond information from persistent storage.
 */
static void delete_bonds(void)
{
    ret_code_t err_code;

    NRF_LOG_INFO("Erase bonds!");

    err_code = pm_peers_delete();
    APP_ERROR_CHECK(err_code);
}

/**@brief Function for starting advertising.
 */
static void advertising_start(bool erase_bonds)
{
    if (erase_bonds == true) {
        delete_bonds();
        // Advertising is started by PM_EVT_PEERS_DELETE_SUCCEEDED event.
    } else {
        whitelist_set(PM_PEER_ID_LIST_SKIP_NO_ID_ADDR);

        ret_code_t ret =
            ble_advertising_start(&m_advertising, BLE_ADV_MODE_FAST);
        APP_ERROR_CHECK(ret);
    }
}

/**@brief Function for handling Peer Manager events.
 *
 * @param[in] p_evt  Peer Manager event.
 */
static void pm_evt_handler(pm_evt_t const *p_evt)
{
    pm_handler_on_pm_evt(p_evt);
    pm_handler_flash_clean(p_evt);

    switch (p_evt->evt_id) {
        case PM_EVT_PEERS_DELETE_SUCCEEDED: {
            advertising_start(false);
        } break;

        case PM_EVT_PEER_DATA_UPDATE_SUCCEEDED: {
            if (p_evt->params.peer_data_update_succeeded.flash_changed
                && (p_evt->params.peer_data_update_succeeded.data_id ==
                    PM_PEER_DATA_ID_BONDING)) {
                NRF_LOG_INFO
                    ("New Bond, add the peer to the whitelist if possible");
                // Note: You should check on what kind of white list policy your application should use.

                whitelist_set(PM_PEER_ID_LIST_SKIP_NO_ID_ADDR);
            }
        } break;

        case PM_EVT_CONN_SEC_SUCCEEDED: {
            m_conn_sec_established = true;
        } break;

        case PM_EVT_CONN_SEC_FAILED: {
            m_conn_sec_established = false;
        } break;

        default: {
        } break;
    }
}

/**@brief Function for handling Service errors.
 *
 * @details A pointer to this function will be passed to each service which may need to inform the
 *          application about an error.
 *
 * @param[in]   nrf_error   Error code containing information about what went wrong.
 */
static void service_error_handler(uint32_t nrf_error)
{
    APP_ERROR_HANDLER(nrf_error);
}

/**@brief Function for handling advertising errors.
 *
 * @param[in] nrf_error  Error code containing information about what went wrong.
 */
static void ble_advertising_error_handler(uint32_t nrf_error)
{
    APP_ERROR_HANDLER(nrf_error);
}

/**@brief Function for performing a battery measurement, and update the Battery Level characteristic in the Battery Service.
 */
static void battery_level_update(void)
{
    ret_code_t err_code;
    uint8_t battery_level;

    battery_level = (uint8_t) sensorsim_measure(&m_battery_sim_state, &m_battery_sim_cfg);

    err_code = ble_bas_battery_level_update(&m_bas, battery_level, BLE_CONN_HANDLE_ALL);
    if ((err_code != NRF_SUCCESS) && (err_code != NRF_ERROR_BUSY)
        && (err_code != NRF_ERROR_RESOURCES)
        && (err_code != NRF_ERROR_FORBIDDEN)
        && (err_code != NRF_ERROR_INVALID_STATE)
        && (err_code != BLE_ERROR_GATTS_SYS_ATTR_MISSING)
    ) {
        APP_ERROR_HANDLER(err_code);
    }
}

/**@brief Function for handling the Battery measurement timer timeout.
 *
 * @details This function will be called each time the battery level measurement timer expires.
 *
 * @param[in]   p_context   Pointer used for passing some arbitrary information (context) from the
 *                          app_start_timer() call to the timeout handler.
 */
static void battery_level_meas_timeout_handler(void *p_context)
{
    UNUSED_PARAMETER(p_context);
    battery_level_update();
}

/**@brief Function for the Timer initialization.
 *
 * @details Initializes the timer module.
 */
static void timers_init(void)
{
    ret_code_t err_code;

    err_code = app_timer_init();
    APP_ERROR_CHECK(err_code);

    // Create battery timer.
    err_code = app_timer_create(&m_battery_timer_id,
                                APP_TIMER_MODE_REPEATED,
                                battery_level_meas_timeout_handler);
    APP_ERROR_CHECK(err_code);
}

/**@brief Function for the GAP initialization.
 *
 * @details This function sets up all the necessary GAP (Generic Access Profile) parameters of the
 *          device including the device name, appearance, and the preferred connection parameters.
 */
static void gap_params_init(void)
{
    ret_code_t err_code;
    ble_gap_conn_params_t gap_conn_params;
    ble_gap_conn_sec_mode_t sec_mode;

    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&sec_mode);

    err_code = sd_ble_gap_device_name_set(&sec_mode,
                                          (const uint8_t *)DEVICE_NAME,
                                          strlen(DEVICE_NAME));
    APP_ERROR_CHECK(err_code);

    err_code = sd_ble_gap_appearance_set(BLE_APPEARANCE_HID_KEYBOARD);
    APP_ERROR_CHECK(err_code);

    memset(&gap_conn_params, 0, sizeof(gap_conn_params));

    gap_conn_params.min_conn_interval = MIN_CONN_INTERVAL;
    gap_conn_params.max_conn_interval = MAX_CONN_INTERVAL;
    gap_conn_params.slave_latency = SLAVE_LATENCY;
    gap_conn_params.conn_sup_timeout = CONN_SUP_TIMEOUT;

    err_code = sd_ble_gap_ppcp_set(&gap_conn_params);
    APP_ERROR_CHECK(err_code);
}

/// @brief Function for initializing the GATT module.
static void gatt_init(void) {
    ret_code_t err_code = nrf_ble_gatt_init(&m_gatt, NULL);
    APP_ERROR_CHECK(err_code);
}

/**@brief Function for handling Queued Write Module errors.
 *
 * @details A pointer to this function will be passed to each service which may need to inform the
 *          application about an error.
 *
 * @param[in]   nrf_error   Error code containing information about what went wrong.
 */
static void nrf_qwr_error_handler(uint32_t nrf_error) {
    APP_ERROR_HANDLER(nrf_error);
}

/// @brief Function for initializing the Queued Write Module.
static void qwr_init(void) {
    ret_code_t err_code;
    nrf_ble_qwr_init_t qwr_init_obj = { 0 };

    qwr_init_obj.error_handler = nrf_qwr_error_handler;

    err_code = nrf_ble_qwr_init(&m_qwr, &qwr_init_obj);
    APP_ERROR_CHECK(err_code);
}

/// @brief Function for initializing Device Information Service.
static void dis_init(void) {
    ret_code_t err_code;
    ble_dis_init_t dis_init_obj;
    ble_dis_pnp_id_t pnp_id;

    pnp_id.vendor_id_source = PNP_ID_VENDOR_ID_SOURCE;
    pnp_id.vendor_id = PNP_ID_VENDOR_ID;
    pnp_id.product_id = PNP_ID_PRODUCT_ID;
    pnp_id.product_version = PNP_ID_PRODUCT_VERSION;

    memset(&dis_init_obj, 0, sizeof(dis_init_obj));

    ble_srv_ascii_to_utf8(&dis_init_obj.manufact_name_str, MANUFACTURER_NAME);
    dis_init_obj.p_pnp_id = &pnp_id;

    dis_init_obj.dis_char_rd_sec = SEC_JUST_WORKS;

    err_code = ble_dis_init(&dis_init_obj);
    APP_ERROR_CHECK(err_code);
}

/// @brief Function for initializing Battery Service.
static void bas_init(void) {
    ret_code_t err_code;
    ble_bas_init_t bas_init_obj;

    memset(&bas_init_obj, 0, sizeof(bas_init_obj));

    bas_init_obj.evt_handler = NULL;
    bas_init_obj.support_notification = true;
    bas_init_obj.p_report_ref = NULL;
    bas_init_obj.initial_batt_level = 100;

    bas_init_obj.bl_rd_sec = SEC_JUST_WORKS;
    bas_init_obj.bl_cccd_wr_sec = SEC_JUST_WORKS;
    bas_init_obj.bl_report_rd_sec = SEC_JUST_WORKS;

    err_code = ble_bas_init(&m_bas, &bas_init_obj);
    APP_ERROR_CHECK(err_code);
}

#include "usb/util/usb_hid.h"
#include "usb/util/hut_keyboard.h"
#include "usb/util/hut_led.h"
#include "usb/util/hut_desktop.h"
#include "usb/util/hut_consumer.h"

static uint8_t report_map_data[] = {
    // Boot keyboard report: 0
    HID_USAGE_PAGE(1), HID_USAGE_PAGE_GENERIC_DESKTOP,
    HID_USAGE(1), HID_USAGE_KEYBOARD,
    HID_COLLECTION(1), HID_COLLECTION_APPLICATION,
    HID_REPORT_ID(1)       , BLE_REPORT_ID_BOOT_KB,
    // modifiers
    HID_USAGE_PAGE(1), HID_USAGE_PAGE_KEYBOARD,
    HID_USAGE_MINIMUM(1), KC_LEFT_CONTROL,
    HID_USAGE_MAXIMUM(1), KC_RIGHT_GUI,
    HID_LOGICAL_MINIMUM(1), 0x00,
    HID_LOGICAL_MAXIMUM(1), 0x01,
    HID_REPORT_COUNT(1), 0x08,
    HID_REPORT_SIZE(1), 0x01,
    HID_INPUT(1), IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
    // reserved/OEM
    HID_REPORT_COUNT(1), 0x01,
    HID_REPORT_SIZE(1), 0x08,
    HID_INPUT(1), IOF_CONSTANT | IOF_VARIABLE | IOF_ABSOLUTE,
    // keycodes
    HID_LOGICAL_MINIMUM(1), KC_NONE,
    HID_LOGICAL_MAXIMUM(1), KC_RIGHT_GUI,
    HID_USAGE_MINIMUM(1), KC_NONE,
    HID_USAGE_MAXIMUM(1), KC_RIGHT_GUI,
    HID_REPORT_COUNT(1), 0x06,
    // HID_REPORT_SIZE(1)     , 0x08, // Reuse global item
    HID_INPUT(1), IOF_DATA | IOF_ARRAY | IOF_ABSOLUTE,
    // LEDs
    HID_USAGE_PAGE(1), HID_USAGE_PAGE_LEDS,
    HID_LOGICAL_MINIMUM(1), 0x00,
    HID_LOGICAL_MAXIMUM(1), 0x01,
    HID_USAGE_MINIMUM(1), HID_LED_Num_Lock,
    HID_USAGE_MAXIMUM(1), HID_LED_Kana,
    HID_REPORT_COUNT(1), 0x05,
    HID_REPORT_SIZE(1), 0x01,
    HID_OUTPUT(1), IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
    // leftover
    HID_REPORT_COUNT(1), 0x01,
    HID_REPORT_SIZE(1), 0x03,
    HID_OUTPUT(1), IOF_CONSTANT | IOF_VARIABLE | IOF_ABSOLUTE,
    HID_END_COLLECTION(0),

#if 1
    //
    // Mouse report: 1
    //
    HID_USAGE_PAGE(1), HID_USAGE_PAGE_GENERIC_DESKTOP,
    HID_USAGE(1), HID_USAGE_MOUSE,
    HID_COLLECTION(1), HID_COLLECTION_APPLICATION,
    HID_REPORT_ID(1), BLE_REPORT_ID_MOUSE,
    // mouse
    HID_USAGE(1), HID_USAGE_POINTER,
    HID_COLLECTION(1), HID_COLLECTION_PHYSICAL,
    // mouse buttons
    HID_USAGE_PAGE(1), HID_USAGE_PAGE_BUTTON,
    HID_LOGICAL_MINIMUM(1), 0,
    HID_LOGICAL_MAXIMUM(1), 1,
    HID_USAGE_MINIMUM(1), 1,
    HID_USAGE_MAXIMUM(1), 16,
    HID_REPORT_COUNT(1), 16,
    HID_REPORT_SIZE(1), 1,
    HID_INPUT(1), IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
    // mouse X, Y
    HID_USAGE_PAGE(1), HID_USAGE_PAGE_GENERIC_DESKTOP,
    HID_USAGE(1), HID_USAGE_X,
    HID_USAGE(1), HID_USAGE_Y,
    HID_LOGICAL_MINIMUM(2), DB16(INT16_MIN),
    HID_LOGICAL_MAXIMUM(2), DB16(INT16_MAX),
    HID_REPORT_COUNT(1), 2,
    HID_REPORT_SIZE(1), 16,
    HID_INPUT(1), IOF_DATA | IOF_VARIABLE | IOF_RELATIVE,
    // mouse wheel
    HID_USAGE(1), HID_USAGE_WHEEL,
    HID_LOGICAL_MINIMUM(1), DB8(INT8_MIN),
    HID_LOGICAL_MAXIMUM(1), DB8(INT8_MAX),
    HID_REPORT_COUNT(1), 1,
    HID_REPORT_SIZE(1), 8,
    HID_INPUT(1), IOF_DATA | IOF_VARIABLE | IOF_RELATIVE,
    // mouse pan wheel
    HID_USAGE_PAGE(1), HID_USAGE_PAGE_CONSUMER,
    HID_USAGE(2), DB16(HID_CONSUMER_AC_PAN),
    // HID_LOGICAL_MINIMUM(1) , DB8(INT8_MIN), // Reuse global item
    // HID_LOGICAL_MAXIMUM(1) , DB8(INT8_MAX), // Reuse global item
    // HID_REPORT_COUNT(1)    , 1, // Reuse global item
    // HID_REPORT_SIZE(1)     , 8, // Reuse global item
    HID_INPUT(1), IOF_DATA | IOF_VARIABLE | IOF_RELATIVE,
    HID_END_COLLECTION(0),
    HID_END_COLLECTION(0),
#endif

#if 1
    //
    // System report
    //
    HID_USAGE_PAGE(1) , HID_USAGE_PAGE_GENERIC_DESKTOP, // Generic Desktop
    HID_USAGE(1)      , HID_USAGE_SYSTEM_CONTROL,
    HID_COLLECTION(1) , HID_COLLECTION_APPLICATION,
    HID_REPORT_ID(1)       , BLE_REPORT_ID_SYSTEM,
    // hid system code
    HID_LOGICAL_MINIMUM(1) , DB8(0x01),
    HID_LOGICAL_MAXIMUM(2) , DB16(HID_DESKTOP_SYSTEM_DISPLAY_LCD_AUTOSCALE),
    HID_USAGE_MINIMUM(1)   , DB8(0x01),
    HID_USAGE_MAXIMUM(2)   , DB16(HID_DESKTOP_SYSTEM_DISPLAY_LCD_AUTOSCALE),
    HID_REPORT_SIZE(1)     , 16,
    HID_REPORT_COUNT(1)    , 1,
    HID_INPUT(1)           , IOF_DATA | IOF_ARRAY | IOF_ABSOLUTE,
    HID_END_COLLECTION(0),
#endif

#if 1
    //
    // Consumer report
    //
    HID_USAGE_PAGE(1) , HID_USAGE_PAGE_CONSUMER,
    HID_USAGE(1)      , HID_CONSUMER_CONSUMER_CONTROL,
    HID_COLLECTION(1) , HID_COLLECTION_APPLICATION,
    HID_REPORT_ID(1)       , BLE_REPORT_ID_CONSUMER,
    // hid consumer code
    HID_LOGICAL_MINIMUM(1) , DB8(0x01),
    HID_LOGICAL_MAXIMUM(2) , DB16(HID_CONSUMER_AC_DISTRIBUTE_VERTICALLY),
    HID_USAGE_MINIMUM(1)   , DB8(0x01),
    HID_USAGE_MAXIMUM(2)   , DB16(HID_CONSUMER_AC_DISTRIBUTE_VERTICALLY),
    HID_REPORT_SIZE(1)     , 16,
    HID_REPORT_COUNT(1)    , 1,
    HID_INPUT(1)           , IOF_DATA | IOF_ARRAY | IOF_ABSOLUTE,
    HID_END_COLLECTION(0),
#endif

#if 1
    //
    // NKRO keyboard report
    //
    HID_USAGE_PAGE(1)        , HID_USAGE_PAGE_GENERIC_DESKTOP,
    HID_USAGE(1)             , HID_USAGE_KEYBOARD,
    HID_COLLECTION(1)        , HID_COLLECTION_APPLICATION,
    HID_REPORT_ID(1)       , BLE_REPORT_ID_NKRO,
    // keycode bitmap
    HID_USAGE_PAGE(1)      , HID_USAGE_PAGE_KEYBOARD,
    HID_USAGE_MINIMUM(1)   , KC_LEFT_CONTROL,
    HID_USAGE_MAXIMUM(1)   , KC_RIGHT_GUI,
    HID_LOGICAL_MINIMUM(1) , 0x00,
    HID_LOGICAL_MAXIMUM(1) , 0x01,
    HID_REPORT_COUNT(1)    , 0x08,
    HID_REPORT_SIZE(1)     , 0x01,
    HID_INPUT(1)           , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
    // keycodes
    // HID_LOGICAL_MINIMUM(1) , 0x00, // Reuse global item
    // HID_LOGICAL_MAXIMUM(1) , 0x01, // Reuse global item
    HID_USAGE_MINIMUM(1)   , 0x00,
    HID_USAGE_MAXIMUM(1)   , 0xdf,
    HID_REPORT_COUNT(1)    , 0xe0,
    // HID_REPORT_SIZE(1)     , 0x01, // Reuse global item
    HID_INPUT(1)           , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
    HID_END_COLLECTION(0),
#endif

#if 1
    HID_USAGE_PAGE(2), DB16(HID_USAGE_PAGE_VENDOR_START),
    HID_USAGE(1), HID_USAGE_VENDOR_0,
    HID_COLLECTION(1), HID_COLLECTION_VENDOR,
    HID_REPORT_ID(1)       , BLE_REPORT_ID_VENDOR,
    // Vendor input usage:
    HID_LOGICAL_MINIMUM(1) , DB8(0),
    HID_LOGICAL_MAXIMUM(2) , DB16(0x00ff),
    HID_REPORT_SIZE(1)     , 8,
    HID_REPORT_COUNT(1)    , VENDOR_REPORT_SIZE,
    HID_USAGE(1)           , HID_USAGE_VENDOR_1,
    HID_INPUT(1)           , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
    // Vendor output usage:
    // HID_LOGICAL_MINIMUM(1) , DB8(0), // Reuse global item
    // HID_LOGICAL_MAXIMUM(2) , DB16(0x00FF), // Reuse global item
    // HID_REPORT_SIZE(1)     , 8, // Reuse global item
    // HID_REPORT_COUNT(1)    , 64, // Reuse global item
    HID_USAGE(1)           , HID_USAGE_VENDOR_2,
    HID_OUTPUT(1)          , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
    HID_END_COLLECTION(0),
#endif

};


/**@brief Function for initializing HID Service.
*/
static void hids_init(void)
{
    ret_code_t err_code;
    ble_hids_init_t hids_init_obj;
    ble_hids_inp_rep_init_t *p_input_report;
    ble_hids_outp_rep_init_t *p_output_report;
    // ble_hids_feature_rep_init_t * p_feature_report;
    uint8_t hid_info_flags;

    static ble_hids_inp_rep_init_t input_report_array[BLE_INPUT_REPORT_COUNT];
    static ble_hids_outp_rep_init_t output_report_array[BLE_OUTPUT_REPORT_COUNT];
    static ble_hids_feature_rep_init_t feature_report_array[BLE_FEATURE_REP_COUNT];

    memset((void *)input_report_array, 0, sizeof(ble_hids_inp_rep_init_t));
    memset((void *)output_report_array, 0,
        sizeof(ble_hids_outp_rep_init_t));
    memset((void *)feature_report_array, 0,
        sizeof(ble_hids_feature_rep_init_t));

    //
    // Input reports
    //

    // HID Boot keyboard
    p_input_report = &input_report_array[BLE_INPUT_REPORT_INDEX_BOOT_KB];
    p_input_report->max_len = BLE_INPUT_REPORT_SIZE_BOOT_KB;
    p_input_report->rep_ref.report_id = BLE_REPORT_ID_BOOT_KB;
    p_input_report->rep_ref.report_type = BLE_HIDS_REP_TYPE_INPUT;

    p_input_report->sec.cccd_wr = SEC_JUST_WORKS;
    p_input_report->sec.wr = SEC_JUST_WORKS;
    p_input_report->sec.rd = SEC_JUST_WORKS;

#if 1
    // HID Mouse
    p_input_report = &input_report_array[BLE_INPUT_REPORT_INDEX_MOUSE];
    p_input_report->max_len = BLE_INPUT_REPORT_SIZE_MOUSE;
    p_input_report->rep_ref.report_id = BLE_REPORT_ID_MOUSE;
    p_input_report->rep_ref.report_type = BLE_HIDS_REP_TYPE_INPUT;

    p_input_report->sec.cccd_wr = SEC_JUST_WORKS;
    p_input_report->sec.wr = SEC_JUST_WORKS;
    p_input_report->sec.rd = SEC_JUST_WORKS;
#endif

#if 1
    // HID System
    p_input_report = &input_report_array[BLE_INPUT_REPORT_INDEX_SYSTEM];
    p_input_report->max_len = BLE_INPUT_REPORT_SIZE_SYSTEM;
    p_input_report->rep_ref.report_id = BLE_REPORT_ID_SYSTEM;
    p_input_report->rep_ref.report_type = BLE_HIDS_REP_TYPE_INPUT;

    p_input_report->sec.cccd_wr = SEC_JUST_WORKS;
    p_input_report->sec.wr = SEC_JUST_WORKS;
    p_input_report->sec.rd = SEC_JUST_WORKS;
#endif

#if 1
    // HID Consumer
    p_input_report = &input_report_array[BLE_INPUT_REPORT_INDEX_CONSUMER];
    p_input_report->max_len = BLE_INPUT_REPORT_SIZE_CONSUMER;
    p_input_report->rep_ref.report_id = BLE_REPORT_ID_CONSUMER;
    p_input_report->rep_ref.report_type = BLE_HIDS_REP_TYPE_INPUT;

    p_input_report->sec.cccd_wr = SEC_JUST_WORKS;
    p_input_report->sec.wr = SEC_JUST_WORKS;
    p_input_report->sec.rd = SEC_JUST_WORKS;
#endif

#if 1
    // HID NKRO keyboard
    p_input_report = &input_report_array[BLE_INPUT_REPORT_INDEX_NKRO];
    p_input_report->max_len = BLE_INPUT_REPORT_SIZE_NKRO;
    p_input_report->rep_ref.report_id = BLE_REPORT_ID_NKRO;
    p_input_report->rep_ref.report_type = BLE_HIDS_REP_TYPE_INPUT;

    p_input_report->sec.cccd_wr = SEC_JUST_WORKS;
    p_input_report->sec.wr = SEC_JUST_WORKS;
    p_input_report->sec.rd = SEC_JUST_WORKS;
#endif

#if 1
    // HID Vendor
    p_input_report = &input_report_array[BLE_INPUT_REPORT_INDEX_VENDOR];
    p_input_report->max_len = BLE_INPUT_REPORT_SIZE_VENDOR;
    p_input_report->rep_ref.report_id = BLE_REPORT_ID_VENDOR;
    p_input_report->rep_ref.report_type = BLE_HIDS_REP_TYPE_INPUT;

    p_input_report->sec.cccd_wr = SEC_JUST_WORKS;
    p_input_report->sec.wr = SEC_JUST_WORKS;
    p_input_report->sec.rd = SEC_JUST_WORKS;
#endif

    //
    // Output reports
    //

    // Boot keyboard output report (capslock led, etc)
    p_output_report = &output_report_array[BLE_OUTPUT_REPORT_INDEX_BOOT_KB];
    p_output_report->max_len = BLE_OUTPUT_REPORT_SIZE_BOOT_KB;
    p_output_report->rep_ref.report_id = OUTPUT_REP_REF_ID;
    p_output_report->rep_ref.report_type = BLE_HIDS_REP_TYPE_OUTPUT;

    p_output_report->sec.wr = SEC_JUST_WORKS;
    p_output_report->sec.rd = SEC_JUST_WORKS;

#if 1
    p_output_report = &output_report_array[BLE_OUTPUT_REPORT_INDEX_VENDOR];
    p_output_report->max_len = BLE_OUTPUT_REPORT_SIZE_VENDOR;
    p_output_report->rep_ref.report_id = BLE_REPORT_ID_VENDOR;
    p_output_report->rep_ref.report_type = BLE_HIDS_REP_TYPE_OUTPUT;

    p_output_report->sec.wr = SEC_JUST_WORKS;
    p_output_report->sec.rd = SEC_JUST_WORKS;
#endif

    //
    // Feature reports
    //
#if 0
    p_feature_report                      = &feature_report_array[FEATURE_REPORT_INDEX];
    p_feature_report->max_len             = FEATURE_REPORT_MAX_LEN;
    p_feature_report->rep_ref.report_id   = FEATURE_REP_REF_ID;
    p_feature_report->rep_ref.report_type = BLE_HIDS_REP_TYPE_FEATURE;

    p_feature_report->sec.rd              = SEC_JUST_WORKS;
    p_feature_report->sec.wr              = SEC_JUST_WORKS;
#endif

    hid_info_flags = HID_INFO_FLAG_REMOTE_WAKE_MSK |
                     HID_INFO_FLAG_NORMALLY_CONNECTABLE_MSK;
    memset(&hids_init_obj, 0, sizeof(hids_init_obj));

    hids_init_obj.evt_handler = on_hids_evt;
    hids_init_obj.error_handler = service_error_handler;
    hids_init_obj.is_kb = true;
    hids_init_obj.is_mouse = false;
    hids_init_obj.inp_rep_count = BLE_INPUT_REPORT_COUNT;
    hids_init_obj.p_inp_rep_array = input_report_array;
    hids_init_obj.outp_rep_count = BLE_OUTPUT_REPORT_COUNT;
    hids_init_obj.p_outp_rep_array = output_report_array;
    hids_init_obj.feature_rep_count = BLE_FEATURE_REP_COUNT;
    hids_init_obj.p_feature_rep_array = feature_report_array;
    hids_init_obj.rep_map.data_len = sizeof(report_map_data);
    hids_init_obj.rep_map.p_data = report_map_data;
    hids_init_obj.hid_information.bcd_hid = BASE_USB_HID_SPEC_VERSION;
    hids_init_obj.hid_information.b_country_code = 0;
    hids_init_obj.hid_information.flags = hid_info_flags;
    hids_init_obj.included_services_count = 0;
    hids_init_obj.p_included_services_array = NULL;

    hids_init_obj.rep_map.rd_sec = SEC_JUST_WORKS;
    hids_init_obj.hid_information.rd_sec = SEC_JUST_WORKS;

    hids_init_obj.boot_kb_inp_rep_sec.cccd_wr = SEC_JUST_WORKS;
    hids_init_obj.boot_kb_inp_rep_sec.rd = SEC_JUST_WORKS;

    hids_init_obj.boot_kb_outp_rep_sec.rd = SEC_JUST_WORKS;
    hids_init_obj.boot_kb_outp_rep_sec.wr = SEC_JUST_WORKS;

    hids_init_obj.protocol_mode_rd_sec = SEC_JUST_WORKS;
    hids_init_obj.protocol_mode_wr_sec = SEC_JUST_WORKS;
    hids_init_obj.ctrl_point_wr_sec = SEC_JUST_WORKS;

    err_code = ble_hids_init(&m_hids, &hids_init_obj);
    APP_ERROR_CHECK(err_code);
}

/// @brief Function for initializing services that will be used by the application.
static void services_init(void) {
    qwr_init();
    dis_init();
    bas_init();
    hids_init();
}

/**@brief Function for initializing the battery sensor simulator.
*/
static void sensor_simulator_init(void) {
    m_battery_sim_cfg.min = MIN_BATTERY_LEVEL;
    m_battery_sim_cfg.max = MAX_BATTERY_LEVEL;
    m_battery_sim_cfg.incr = BATTERY_LEVEL_INCREMENT;
    m_battery_sim_cfg.start_at_max = true;

    sensorsim_init(&m_battery_sim_state, &m_battery_sim_cfg);
}

/**@brief Function for handling a Connection Parameters error.
 *
 * @param[in]   nrf_error   Error code containing information about what went wrong.
 */
static void conn_params_error_handler(uint32_t nrf_error) {
    APP_ERROR_HANDLER(nrf_error);
}

/// @brief Function for handling a Connection Parameters event
void conn_params_handler(ble_conn_params_evt_t * p_evt) {
    switch (p_evt->evt_type) {
        case BLE_CONN_PARAMS_EVT_SUCCEEDED: {
            NRF_LOG_INFO("BLE conn parameters succeeded");
            m_conn_established = true;
        } break;
        case BLE_CONN_PARAMS_EVT_FAILED: {
            NRF_LOG_INFO("BLE conn parameters failed");
            m_conn_established = false;
        } break;
    }
}

/// @brief Function for initializing the Connection Parameters module.
static void conn_params_init(void) {
    ret_code_t err_code;
    ble_conn_params_init_t cp_init;

    m_conn_established = false;

    memset(&cp_init, 0, sizeof(cp_init));

    cp_init.p_conn_params = NULL;
    cp_init.first_conn_params_update_delay = FIRST_CONN_PARAMS_UPDATE_DELAY;
    cp_init.next_conn_params_update_delay = NEXT_CONN_PARAMS_UPDATE_DELAY;
    cp_init.max_conn_params_update_count = MAX_CONN_PARAMS_UPDATE_COUNT;
    cp_init.start_on_notify_cccd_handle = BLE_GATT_HANDLE_INVALID;
    cp_init.disconnect_on_fail = false;
    cp_init.evt_handler = conn_params_handler;
    cp_init.error_handler = conn_params_error_handler;

    err_code = ble_conn_params_init(&cp_init);
    APP_ERROR_CHECK(err_code);
}

/// @brief Function for starting timers.
static void timers_start(void) {
    ret_code_t err_code;

    err_code = app_timer_start(m_battery_timer_id,
                               BATTERY_LEVEL_MEAS_INTERVAL,
                               NULL);
    APP_ERROR_CHECK(err_code);
}

void kp_ble_hids_input_report_send(
    uint8_t report_index,
    uint8_t report_size,
    uint8_t* data
) {
    uint32_t err_code;

    assert(report_index < BLE_INPUT_REPORT_COUNT);

    err_code = ble_hids_inp_rep_send(&m_hids,
        report_index,
        report_size,
        data,
        m_conn_handle);

    if (err_code != NRF_SUCCESS) {
        NRF_LOG_INFO("sending: {index: %d, size: %d, err_code: %s}",
            report_index, report_size, nrf_strerror_get(err_code));
    }

    if ((err_code != NRF_SUCCESS) &&
        (err_code != NRF_ERROR_INVALID_STATE) &&
        (err_code != NRF_ERROR_RESOURCES) &&
        (err_code != NRF_ERROR_BUSY) &&
        (err_code != BLE_ERROR_GATTS_SYS_ATTR_MISSING)
       ) {
        APP_ERROR_HANDLER(err_code);
    }
}

uint8_t m_output_ready[BLE_OUTPUT_REPORT_COUNT];

bool kp_ble_hids_output_has_data(uint8_t report_index) {
    return m_output_ready[report_index];
}

void kp_ble_hids_output_report_read(
    uint8_t report_index,
    uint8_t report_size,
    uint8_t *dest
) {
    uint32_t err_code;
    err_code = ble_hids_outp_rep_get(&m_hids,
        report_index,
        report_size,
        0,
        m_conn_handle,
        dest);
    APP_ERROR_CHECK(err_code);
    m_output_ready[report_index] = 0;
}


void send_vendor(uint32_t code) {
    ret_code_t err_code;

    uint8_t data[64] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
        0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23,
        0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
        0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b,
        0x3c, 0x3d, 0x3e, 0x3f,
    };

    // ((uint32_t*)data)[0] = code;

    err_code = ble_hids_inp_rep_send(&m_hids,
        BLE_INPUT_REPORT_INDEX_VENDOR,
        BLE_INPUT_REPORT_SIZE_VENDOR,
        (uint8_t*)data,
        m_conn_handle);

    NRF_LOG_INFO("sending: {index: %d, size: %d, err_code: %s}",
        BLE_INPUT_REPORT_INDEX_VENDOR,
        BLE_INPUT_REPORT_SIZE_VENDOR,
        nrf_strerror_get(err_code));

    if ((err_code != NRF_SUCCESS) &&
        (err_code != NRF_ERROR_INVALID_STATE) &&
        (err_code != NRF_ERROR_RESOURCES) &&
        (err_code != NRF_ERROR_BUSY) &&
        (err_code != BLE_ERROR_GATTS_SYS_ATTR_MISSING)
       ) {
        APP_ERROR_HANDLER(err_code);
    }
}

/// @brief Function for putting the chip into sleep mode.
///
/// @note This function will not return.
static void sleep_mode_enter(void) {
    ret_code_t err_code;

    // Prepare wakeup buttons.

    // Go to system-off mode (this function will not return; wakeup will cause a reset).
    err_code = sd_power_system_off();
    APP_ERROR_CHECK(err_code);
}

/**@brief Function for handling HID events.
 *
 * @details This function will be called for all HID events which are passed to the application.
 *
 * @param[in]   p_hids  HID service structure.
 * @param[in]   p_evt   Event received from the HID service.
 */
static void on_hids_evt(ble_hids_t * p_hids, ble_hids_evt_t * p_evt) {
    switch (p_evt->evt_type) {
        case BLE_HIDS_EVT_BOOT_MODE_ENTERED:
            m_in_boot_mode = true;
            break;

        case BLE_HIDS_EVT_REPORT_MODE_ENTERED:
            m_in_boot_mode = false;
            break;

        case BLE_HIDS_EVT_REP_CHAR_WRITE:
            // on_hid_rep_char_write(p_evt);
            break;

        case BLE_HIDS_EVT_NOTIF_ENABLED:
            break;

        default:
            // No implementation needed.
            break;
    }
}

/**@brief Function for handling advertising events.
 *
 * @details This function will be called for advertising events which are passed to the application.
 *
 * @param[in] ble_adv_evt  Advertising event.
 */
static void on_adv_evt(ble_adv_evt_t ble_adv_evt) {
    ret_code_t err_code;

    switch (ble_adv_evt) {
        case BLE_ADV_EVT_DIRECTED_HIGH_DUTY:
            NRF_LOG_INFO("High Duty Directed advertising.");
            break;

        case BLE_ADV_EVT_DIRECTED:
            NRF_LOG_INFO("Directed advertising.");
            break;

        case BLE_ADV_EVT_FAST:
            NRF_LOG_INFO("Fast advertising.");
            break;

        case BLE_ADV_EVT_SLOW:
            NRF_LOG_INFO("Slow advertising.");
            break;

        case BLE_ADV_EVT_FAST_WHITELIST:
            NRF_LOG_INFO("Fast advertising with whitelist.");
            break;

        case BLE_ADV_EVT_SLOW_WHITELIST:
            NRF_LOG_INFO("Slow advertising with whitelist.");
            break;

        case BLE_ADV_EVT_IDLE:
            sleep_mode_enter();
            break;

        case BLE_ADV_EVT_WHITELIST_REQUEST:
            {
                ble_gap_addr_t
                    whitelist_addrs[BLE_GAP_WHITELIST_ADDR_MAX_COUNT];
                ble_gap_irk_t
                    whitelist_irks[BLE_GAP_WHITELIST_ADDR_MAX_COUNT];
                uint32_t addr_cnt = BLE_GAP_WHITELIST_ADDR_MAX_COUNT;
                uint32_t irk_cnt = BLE_GAP_WHITELIST_ADDR_MAX_COUNT;

                err_code = pm_whitelist_get(whitelist_addrs, &addr_cnt,
                    whitelist_irks, &irk_cnt);
                APP_ERROR_CHECK(err_code);
                NRF_LOG_DEBUG
                    ("pm_whitelist_get returns %d addr in whitelist and %d irk whitelist",
                     addr_cnt, irk_cnt);

                // Set the correct identities list (no excluding peers with no Central Address Resolution).
                identities_set(PM_PEER_ID_LIST_SKIP_NO_IRK);

                // Apply the whitelist.
                err_code =
                    ble_advertising_whitelist_reply(&m_advertising,
                        whitelist_addrs,
                        addr_cnt,
                        whitelist_irks,
                        irk_cnt);
                APP_ERROR_CHECK(err_code);
            }
            break;      //BLE_ADV_EVT_WHITELIST_REQUEST

        case BLE_ADV_EVT_PEER_ADDR_REQUEST:
            {
                pm_peer_data_bonding_t peer_bonding_data;

                // Only Give peer address if we have a handle to the bonded peer.
                if (m_peer_id != PM_PEER_ID_INVALID) {
                    err_code =
                        pm_peer_data_bonding_load(m_peer_id,
                            &peer_bonding_data);
                    if (err_code != NRF_ERROR_NOT_FOUND) {
                        APP_ERROR_CHECK(err_code);

                        // Manipulate identities to exclude peers with no Central Address Resolution.
                        identities_set
                            (PM_PEER_ID_LIST_SKIP_ALL);

                        ble_gap_addr_t *p_peer_addr =
                            &(peer_bonding_data.peer_ble_id.
                                id_addr_info);
                        err_code =
                            ble_advertising_peer_addr_reply
                            (&m_advertising, p_peer_addr);
                        APP_ERROR_CHECK(err_code);
                    }
                }
            }
            break;      //BLE_ADV_EVT_PEER_ADDR_REQUEST

        default:
            break;
    }
}

/**@brief Function for handling BLE events.
 *
 * @param[in]   p_ble_evt   Bluetooth stack event.
 * @param[in]   p_context   Unused.
 */
static void ble_evt_handler(ble_evt_t const *p_ble_evt, void *p_context) {
    ret_code_t err_code;

    switch (p_ble_evt->header.evt_id) {
        case BLE_GAP_EVT_CONNECTED: {
            NRF_LOG_INFO("Connected");
            m_conn_handle = p_ble_evt->evt.gap_evt.conn_handle;
            err_code =
                nrf_ble_qwr_conn_handle_assign(&m_qwr, m_conn_handle);
            APP_ERROR_CHECK(err_code);
        } break;

        case BLE_GAP_EVT_DISCONNECTED: {
            const uint8_t reason = p_ble_evt->evt.gap_evt.params.disconnected.reason;
            NRF_LOG_INFO("Disconnected: %d", reason);


            m_conn_handle = BLE_CONN_HANDLE_INVALID;
            m_conn_sec_established = false;
            m_conn_established = false;

            // Reset m_caps_on variable. Upon reconnect, the HID host will re-send the Output
            // report containing the Caps lock state.
            m_caps_on = false;
            // disabling alert 3. signal - used for capslock ON

        } break;      // BLE_GAP_EVT_DISCONNECTED

        case BLE_GAP_EVT_PHY_UPDATE_REQUEST: {
                NRF_LOG_DEBUG("PHY update request.");
                ble_gap_phys_t const phys = {
                    .rx_phys = BLE_GAP_PHY_AUTO,
                    .tx_phys = BLE_GAP_PHY_AUTO,
                };
                err_code =
                    sd_ble_gap_phy_update(p_ble_evt->evt.gap_evt.
                        conn_handle, &phys);
                APP_ERROR_CHECK(err_code);
        } break;

        case BLE_GATTS_EVT_HVN_TX_COMPLETE:
            // Send next key event
            // (void)buffer_dequeue(true);
            break;

        case BLE_GATTC_EVT_TIMEOUT: {
            // Disconnect on GATT Client timeout event.
            NRF_LOG_DEBUG("GATT Client Timeout.");
            err_code =
                sd_ble_gap_disconnect(p_ble_evt->evt.gattc_evt.conn_handle,
                    BLE_HCI_REMOTE_USER_TERMINATED_CONNECTION);
            APP_ERROR_CHECK(err_code);
        } break;

        case BLE_GATTS_EVT_TIMEOUT: {
            // Disconnect on GATT Server timeout event.
            NRF_LOG_DEBUG("GATT Server Timeout.");
            err_code =
                sd_ble_gap_disconnect(p_ble_evt->evt.gatts_evt.conn_handle,
                    BLE_HCI_REMOTE_USER_TERMINATED_CONNECTION);
            APP_ERROR_CHECK(err_code);
        } break;

        default: {
            // No implementation needed.
        } break;
    }
}

/// @brief Function for initializing the BLE stack.
///
/// @details Initializes the SoftDevice and the BLE event interrupt.
static void ble_stack_init(void) {
    ret_code_t err_code;

    err_code = nrf_sdh_enable_request();
    APP_ERROR_CHECK(err_code);

    // Configure the BLE stack using the default settings.
    // Fetch the start address of the application RAM.
    uint32_t ram_start = 0;
    err_code =
        nrf_sdh_ble_default_cfg_set(APP_BLE_CONN_CFG_TAG, &ram_start);
    APP_ERROR_CHECK(err_code);

    // Enable BLE stack.
    err_code = nrf_sdh_ble_enable(&ram_start);
    APP_ERROR_CHECK(err_code);

    // Register a handler for BLE events.
    NRF_SDH_BLE_OBSERVER(m_ble_observer, APP_BLE_OBSERVER_PRIO, ble_evt_handler, NULL);
    NRF_SDH_SOC_OBSERVER(m_soc_observer, APP_SOC_OBSERVER_PRIO, soc_evt_handler, NULL);
}

/// @brief Function for the Event Scheduler initialization.
static void scheduler_init(void) {
    APP_SCHED_INIT(SCHED_MAX_EVENT_DATA_SIZE, SCHED_QUEUE_SIZE);
}

/// @brief Function for the Peer Manager initialization.
static void peer_manager_init(void) {
    ble_gap_sec_params_t sec_param;
    ret_code_t err_code;

    err_code = pm_init();
    APP_ERROR_CHECK(err_code);

    memset(&sec_param, 0, sizeof(ble_gap_sec_params_t));

    m_conn_sec_established = false;

    // Security parameters to be used for all security procedures.
    sec_param.bond = SEC_PARAM_BOND;
    sec_param.mitm = SEC_PARAM_MITM;
    sec_param.lesc = SEC_PARAM_LESC;
    sec_param.keypress = SEC_PARAM_KEYPRESS;
    sec_param.io_caps = SEC_PARAM_IO_CAPABILITIES;
    sec_param.oob = SEC_PARAM_OOB;
    sec_param.min_key_size = SEC_PARAM_MIN_KEY_SIZE;
    sec_param.max_key_size = SEC_PARAM_MAX_KEY_SIZE;
    sec_param.kdist_own.enc = 1;
    sec_param.kdist_own.id = 1;
    sec_param.kdist_peer.enc = 1;
    sec_param.kdist_peer.id = 1;

    err_code = pm_sec_params_set(&sec_param);
    APP_ERROR_CHECK(err_code);

    err_code = pm_register(pm_evt_handler);
    APP_ERROR_CHECK(err_code);
}

/// @brief Function for initializing the Advertising functionality.
static void advertising_init(void) {
    uint32_t err_code;
    uint8_t adv_flags;
    ble_advertising_init_t init;

    memset(&init, 0, sizeof(init));

    adv_flags = BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE;
    init.advdata.name_type = BLE_ADVDATA_FULL_NAME;
    init.advdata.include_appearance = true;
    init.advdata.flags = adv_flags;
    init.advdata.uuids_complete.uuid_cnt =
        sizeof(m_adv_uuids) / sizeof(m_adv_uuids[0]);
    init.advdata.uuids_complete.p_uuids = m_adv_uuids;

    init.config.ble_adv_whitelist_enabled = true;
    init.config.ble_adv_directed_high_duty_enabled = true;
    init.config.ble_adv_directed_enabled = false;
    init.config.ble_adv_directed_interval = 0;
    init.config.ble_adv_directed_timeout = 0;
    init.config.ble_adv_fast_enabled = true;
    init.config.ble_adv_fast_interval = APP_ADV_FAST_INTERVAL;
    init.config.ble_adv_fast_timeout = APP_ADV_FAST_DURATION;
    init.config.ble_adv_slow_enabled = true;
    init.config.ble_adv_slow_interval = APP_ADV_SLOW_INTERVAL;
    init.config.ble_adv_slow_timeout = APP_ADV_SLOW_DURATION;

    init.evt_handler = on_adv_evt;
    init.error_handler = ble_advertising_error_handler;

    err_code = ble_advertising_init(&m_advertising, &init);
    APP_ERROR_CHECK(err_code);

    ble_advertising_conn_cfg_tag_set(&m_advertising, APP_BLE_CONN_CFG_TAG);
}

/// @brief Function for initializing the nrf log module.
static void log_init(void) {
    ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_DEFAULT_BACKENDS_INIT();
}

static void log_resetreason(void) {
    // Reset reason
    uint32_t rr = nrf_power_resetreas_get();
    nrf_power_resetreas_clear(rr);
    NRF_LOG_INFO("Reset reasons:");
    if (0 == rr) {
        NRF_LOG_INFO("- NONE");
    }
    if (0 != (rr & NRF_POWER_RESETREAS_RESETPIN_MASK)) {
        NRF_LOG_INFO("- RESETPIN");
    }
    if (0 != (rr & NRF_POWER_RESETREAS_DOG_MASK)) {
        NRF_LOG_INFO("- DOG");
    }
    if (0 != (rr & NRF_POWER_RESETREAS_SREQ_MASK)) {
        NRF_LOG_INFO("- SREQ");
    }
    if (0 != (rr & NRF_POWER_RESETREAS_LOCKUP_MASK)) {
        NRF_LOG_INFO("- LOCKUP");
    }

    // Reset from SYSTEM OFF sleep state
    if (0 != (rr & NRF_POWER_RESETREAS_OFF_MASK)) {
        NRF_LOG_INFO("- OFF");
    }
    if (0 != (rr & NRF_POWER_RESETREAS_LPCOMP_MASK)) {
        NRF_LOG_INFO("- LPCOMP");
    }
    if (0 != (rr & NRF_POWER_RESETREAS_DIF_MASK)) {
        NRF_LOG_INFO("- DIF");
    }
    if (0 != (rr & NRF_POWER_RESETREAS_NFC_MASK)) {
        NRF_LOG_INFO("- NFC");
    }
    if (0 != (rr & NRF_POWER_RESETREAS_VBUS_MASK)) {
        NRF_LOG_INFO("- VBUS");
    }
}


// void ble_hrs_app_start(void) {
//     gap_params_init();
//     advertising_init();
//     services_init();
//     sensor_simulator_init();
//     conn_params_init();
//     application_timers_start();
//     sec_params_init();
//     advertising_start();
// }

void stop_ble_services(void) {
    ret_code_t err_code;

    if (m_conn_handle != BLE_CONN_HANDLE_INVALID) {
        err_code = sd_ble_gap_disconnect(
            m_conn_handle,
            BLE_HCI_REMOTE_USER_TERMINATED_CONNECTION
        );
        APP_ERROR_CHECK(err_code);
    }

    // TODO: stop advertising
#if 0
    if () {
    }
#endif


    // Stop any impending connection parameters update.
    err_code = ble_conn_params_stop();
    APP_ERROR_CHECK(err_code);

    // Stop application timers.
    err_code = app_timer_stop(m_battery_timer_id);
    APP_ERROR_CHECK(err_code);
}

void stop_softdevice(void) {
    ret_code_t err_code;

    // Disable the soft device
    err_code = nrf_sdh_disable_request();
    APP_ERROR_CHECK(err_code);

    ASSERT(!nrf_sdh_is_enabled());
}

/// @brief Function for initializing power management.
static void power_management_init(void) {
    ret_code_t err_code;
    err_code = nrf_pwr_mgmt_init();
    APP_ERROR_CHECK(err_code);
}

/**@brief Function for handling the idle state (main loop).
 *
 * @details If there is no pending log operation, then sleep until next the next event occurs.
 */
static void idle_state_handle(void) {
    app_sched_execute();
    if (NRF_LOG_PROCESS() == false) {
        nrf_pwr_mgmt_run();
    }
}

static void esb_multiprotocol_start(void) {
    uint32_t err_code;

    err_code = esb_timeslot_init();
    APP_ERROR_CHECK(err_code);

    err_code = esb_timeslot_start();
    APP_ERROR_CHECK(err_code);
}

#include "core/aes.h"
#include "core/error.h"
#include "core/hardware.h"
#include "core/led.h"
#include "core/matrix_interpret.h"
#include "core/matrix_scanner.h"
#include "core/settings.h"
#include "core/usb_commands.h"
#include "core/timer.h"
#include "core/macro.h"
#include "core/rf.h"
#include "core/unifying.h"

#include "key_handlers/key_mouse.h"
#include "key_handlers/key_hold.h"

void vbus_detect_event_handler(nrf_drv_power_usb_evt_t event) {
    switch (event) {
    case NRF_DRV_POWER_USB_EVT_DETECTED:
        NRF_LOG_INFO("USB power detected");
        break;
    case NRF_DRV_POWER_USB_EVT_REMOVED:
        NRF_LOG_INFO("USB power removed");
        break;
    case NRF_DRV_POWER_USB_EVT_READY:
        NRF_LOG_INFO("USB ready");
        break;
    default:
        ASSERT(false);
    }
}

#if 0
void no_sd_setup_vbus_detection(void) {
    ret_code_t ret;
    static const nrf_drv_power_usbevt_config_t config = {
        .handler = vbus_detect_event_handler
    };
    ret = nrf_drv_power_usbevt_init(&config);
    APP_ERROR_CHECK(ret);

    nrf_delay_us(100);

    if (!nrf_drv_power_init_check()) {
        ret = nrf_drv_power_init(NULL);
        APP_ERROR_CHECK(ret);
    }
    nrfx_power_usb_state_t state = nrf_drv_power_usbstatus_get();

    switch (state) {
        case NRF_DRV_POWER_USB_STATE_CONNECTED:
        case NRF_DRV_POWER_USB_STATE_READY: {
            NRF_LOG_INFO("VBUS connected");
        } break;

        case NRF_DRV_POWER_USB_STATE_DISCONNECTED: {
            NRF_LOG_INFO("VBUS disconnected");
        } break;
    }
}
#endif

void setup_vbus_detection(void) {
    sd_power_usbdetected_enable(true);
    sd_power_usbpwrrdy_enable(true);
    sd_power_usbremoved_enable(true);

    {
        uint32_t status;
        sd_power_usbregstatus_get(&status);
        switch (status) {
            case NRF_DRV_POWER_USB_STATE_CONNECTED:
            case NRF_DRV_POWER_USB_STATE_READY: {
                NRF_LOG_INFO("Inital VBUS state: connected");
            } break;

            case NRF_DRV_POWER_USB_STATE_DISCONNECTED: {
                NRF_LOG_INFO("Inital VBUS state: disconnected");
            } break;
        }
    }
}

/// @brief Function for application main entry.
int ble_test_main(uint8_t x) {
    bool erase_bonds = false;

    // Initialize.
    log_init();

    // Reset reason
    log_resetreason();

    // no_sd_setup_vbus_detection();

    // keyplus init
    {
        timer_init();
        io_map_init();
        hardware_init();
        init_error_system();
        led_init();

        NRF_LOG_INFO("loading settings from flash");
        settings_load_from_flash();
        aes_key_init(g_rf_settings.ekey, g_rf_settings.dkey);
        keyboards_init();
        matrix_scanner_init();

        g_runtime_settings.mode = TRANS_MODE_BLE;
        g_rf_settings.hw_type = RF_HW_BLE_AND_ESB;
        g_rf_enabled = true;
        rf_init_receive();

        reset_hid_reports();
        // reset_usb_reports();

        if (has_critical_error()) {
            NRF_LOG_HEXDUMP_INFO(g_error_code_table, SIZE_ERROR_CODE_TABLE);
            // recovery_mode_main_loop();
            APP_ERROR_HANDLER(0xffff);
        }
    }
    {
        uint16_t sid = 0xFFFF;
        sid = load_session_id();
        NRF_LOG_INFO("sid: %d", sid);
    }

    timers_init();
    power_management_init();
    ble_stack_init();
    scheduler_init();
    gap_params_init();
    gatt_init();
    advertising_init();
    services_init();
    sensor_simulator_init();
    conn_params_init();
    peer_manager_init();

    // Enable vusb detection
    setup_vbus_detection();

    // Start execution.
    NRF_LOG_INFO("BLE HID Keyboard example started.");
    timers_start();
    advertising_start(erase_bonds);

    esb_multiprotocol_start();

    uint32_t last_time = 0;
    bool quiet = true;

    // Enter main loop.
    for (;;) {
        led_testing_toggle(1);
        led_testing_set(0, 0);

        // Log current time (for debugging)
        {
            uint32_t new_time = timer_read_ms();
            if ((uint32_t)(new_time - last_time) >= 1000) {
                uint32_t time_sec = new_time/1000;
                last_time = new_time;

                if (quiet) {
                    if (time_sec % 15 == 0) {
                        NRF_LOG_INFO("time: %d", time_sec);
                    }
                } else {
                    NRF_LOG_INFO("time: %d", new_time);

                    if (time_sec % 5 == 0) {
                        struct timeslot_stats_t stats = get_timeslot_stats();
                        NRF_LOG_INFO(
                            "timeslot stats: {start: %04d, end: %04d, "
                            "tx: %04d, rx: %04d, ext: %04d}",
                            stats.start, stats.end,
                            stats.tx, stats.rx,
                            stats.extensions
                            );
                        NRF_LOG_INFO(
                            "conn stats: {handle: %d, established: %d, sec: %d}",
                            m_conn_handle, m_conn_established, m_conn_sec_established
                            );
                    }
                }


                if (0) {
                    if (time_sec % 21 == 19) {
                        NRF_LOG_INFO("about to power off");
                    }

                    if (time_sec % 21 == 20) {
                        stop_ble_services();
                        stop_softdevice();
                        nrf_delay_ms(100);
                        sd_power_system_off();
                    }
                }

#if 0
                if (m_conn_handle != BLE_CONN_HANDLE_INVALID
                    && m_conn_sec_established && m_conn_established) {
                    send_vendor(0x12345678UL);
                }
#endif
            }
        }

        led_testing_toggle(0);

        // Matrix scanning
        {
            bool scan_changed = false;

            scan_changed |= matrix_scan();
            if (scan_changed) {
                uint8_t matrix_data[32];
                const uint8_t use_deltas = true;
                const uint8_t data_size = get_matrix_data(matrix_data, use_deltas);
                UNUSED_PARAMETER(data_size);

                NRF_LOG_INFO("button pressed");

                keyboard_update_device_matrix(GET_SETTING(device_id), matrix_data);
            }

            interpret_all_keyboard_matrices();
        }

        led_testing_toggle(0);

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

        led_testing_toggle(0);

        macro_task();
        mouse_key_task();

        if (m_conn_handle != BLE_CONN_HANDLE_INVALID
            && m_conn_sec_established && m_conn_established) {
            send_hid_reports();
        }

        led_testing_toggle(0);

        sticky_key_task();
        hold_key_task(false);

        led_testing_toggle(0);

        idle_state_handle();
    }
}

/**
 * @}
 */
