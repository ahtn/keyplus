// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @dir xmega
/// @file xmega/main.c
///
/// @brief Main function and setup code for the xmega port.

#include <string.h>

#include "core/aes.h"
#include "core/debug.h"
#include "core/error.h"
#include "core/hardware.h"
#include "core/io_map.h"
#include "core/layout.h"
#include "core/led.h"
#include "core/macro.h"
#include "core/matrix_interpret.h"
#include "core/matrix_scanner.h"
#include "core/nrf24.h"
#include "core/packet.h"
#include "core/rf.h"
#include "core/settings.h"
#include "core/timer.h"
#include "core/usb_commands.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/media_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"

#include "key_handlers/key_hold.h"
#include "key_handlers/key_mouse.h"

#include "xmega/usb_xmega.h"
#include "hardware_user_impl.h"

#include "power.h"
#include "wired.h"
#include "led_vm.h"

#include "xmega_hardware.h"

#include "xusb-boot/spm_interface.h"

#if DUAL_USB
#include "dual_usb.h"
#endif

USB_ENDPOINTS(5);

// TODO: Pins that are left floating can cause the system to use more power, so
// making them output low.
void unused_pins_init(void) {
}

void pin_init(void) {
    unused_pins_init();
    led_init();
}

void xmega_common_init(void) {
    hardware_init();
    io_map_init();
    pin_init();
    settings_load_from_flash();
#if USE_NRF24
    aes_key_init(g_rf_settings.ekey, g_rf_settings.dkey);
#endif
    led_testing_set(0, 0);
    matrix_scanner_init();
}

#if USE_NRF24
void battery_mode_setup(void) {
    set_power_mode(MODE_BATTERY);

    // battery mode uses the ULP RTC timer
    rtc_ulp_init();

    // Disable spm instruction while running from battery power
    SP_LockSPM();

    battery_mode_clock_init();
    xmega_common_init();
    rf_init_send();

    // enable interrupt levels
    PMIC.CTRL = PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;
    sei();
}

#define MAX_RETRY_COUNT 10
#define ADAPTIVE_SCAN 1

void battery_mode_main_loop(void) {
    uint16_t idle_time_start = 0;
    uint8_t err_count = 0;

    bool matrix_needs_scanning = true;
    bool scan_changed = false;
    bool deep_sleep_resync_packet = false;

    if (g_runtime_settings.feature.ctrl.rf_disabled || has_critical_error()) {
        // If we are running in battery mode, there's nothing we can do if
        // the rf module is disabled. So go into deep sleep until the VBUS
        // check pin wakes us up.
        while (1) {
            deep_sleep();
        }
    }

    while (1) {
#if ADAPTIVE_SCAN
        scan_changed = false;
        if (matrix_needs_scanning) {
#else
        {
#endif
            // TODO: Add an optimization to skip matrix scanning all together if
            // no keys are down. If no keys are down or debouncing, then we can set
            // the matrix in interrupt mode. Then as long as no matrix interrupts
            // are generated, we don't need to scan th matrix.
            scan_changed = matrix_scan();
        }

        uint8_t nrf_status = nrf24_read_status();

        // TODO: add queue of messages.
        // try process messages based on order in queue.
        // drop messages if queued for too long
        if (nrf_status & (STATUS_MAX_RT_bm)) {
            // TODO: Probably want to do this differently.
            // Instead, when we write an RF packet, we should check if the TX
            // buffer is full, then, if it is we should queue the packet for
            // a time when it is not full.
            //
            // Then if we have lots of failed attempts, we should clear
            // messages from the queue.
            err_count++;

            if (err_count > MAX_RETRY_COUNT) {
                nrf24_flush_tx();
                err_count = 0;
            } else {
                nrf24_send_one();
            }
            nrf24_write_reg(NRF_STATUS, STATUS_MAX_RT_bm);
        }

        if (scan_changed) {
            rf_send_matrix_packet();
            idle_time_start = timer_read16_ms();
        }

        if (NRF24_STATUS_RX_PIPE(nrf_status) != STATUS_RX_FIFO_EMPTY ) {
            rf_handle_ack_payloads();
        }

        // TODO: We can combine getting the FIFO_STATUS and STATUS register
        // into one SPI transaction.
        uint8_t fifo_status = nrf24_read_reg(FIFO_STATUS);

        if (fifo_status & FIFO_TX_EMPTY_bm) {
            // empty
            err_count = 0;
        } else {
            // not empty
            nrf24_send_one();
        }

        if (get_matrix_num_keys_down() == 0 &&
            (uint16_t)(timer_read16_ms() - idle_time_start) > DEEP_SLEEP_TIME &&
            get_matrix_num_keys_debouncing() == 0 &&
            !scan_changed &&
            (fifo_status & FIFO_TX_EMPTY_bm)
            ) {
            deep_sleep();
            idle_time_start = timer_read16_ms();
            matrix_needs_scanning = true;
            deep_sleep_resync_packet = true;
        } else {

#if ADAPTIVE_SCAN
            uint8_t num_keys = get_matrix_num_keys_down();

            if (num_keys == 0 && get_matrix_num_keys_debouncing() == 0) {
                matrix_scan_irq_enable();

                // this wakes up everytime the timer ticks, or when a key is
                // pressed
                enter_sleep_mode(SLEEP_MODE_PWR_SAVE);

                if (matrix_has_active_row()) {
                    matrix_needs_scanning = true;
                    matrix_scan_irq_disable();
                } else {
                    matrix_needs_scanning = false;
                }
            } else {
                // this wakes up everytime the timer ticks
                enter_sleep_mode(SLEEP_MODE_PWR_SAVE);
                matrix_needs_scanning = true;
            }
#else
        enter_sleep_mode(SLEEP_MODE_PWR_SAVE);
#endif

            // NOTE: This sends an additional packet after wakeup from deep
            // sleep. This is done because in the nRF ESB protocl we can only
            // receive data immediately after we send a packet (i.e. in ACK
            // payloads). We might need to resync our AES counter when
            // waking from deep sleep, so we need to be able to receive an ACK
            // payload after wakeup from deep sleep.
            // If this is not done, an unsynced device might not be able to
            // register a key press until a second key is pressed.
            if (deep_sleep_resync_packet) {
                rf_send_matrix_packet();
                deep_sleep_resync_packet = false;
            }
        }
    }
}
#endif

/*********************************************************************
 *                             USB Mode                              *
 *********************************************************************/

#if USE_USB

void usb_mode_setup(void) {
#if USE_NRF24 || USE_I2C
    set_power_mode(MODE_USB);
#endif

    timer_init();

    wdt_init();

    g_slow_clock_mode = 0;
    usb_configure_clock();

    xmega_common_init();

    reset_usb_reports();
    keyboards_init();

#if DUAL_USB
    init_bus_switches();
#else
    usb_init();
#endif

    // enable all interrupt levels
    PMIC.CTRL = PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;

    // Enable USB interrupts
    USB.INTCTRLA = USB_SOFIE_bm | USB_BUSEVIE_bm | USB_INTLVL_MED_gc;
    USB.INTCTRLB = USB_TRNIE_bm | USB_SETUPIE_bm;

    sei();

#if DUAL_USB
    const uint8_t s_has_usb_port = usb_find_port();
    if (s_has_usb_port) {
        usb_init();
        usb_attach();
    }
#else
    // TODO: when we don't have the dual USB feature, need to check if we are
    // have a USB connection as well
    const uint8_t s_has_usb_port = true;
    usb_attach();
#endif

#if USE_I2C
    i2c_init();
#endif


#if USE_NRF24
    g_rf_enabled = false;

    if (s_has_usb_port) {
        rf_init_receive();
    }
#endif

#if USE_I2C || USE_NRF24
    g_has_usb_port = s_has_usb_port;
#endif

}

NO_RETURN_ATTR void recovery_mode_main_loop(void);
extern port_mask_t s_available_pins[IO_PORT_COUNT];

void usb_mode_main_loop(void) {
    if (has_critical_error()) {
        recovery_mode_main_loop();
    }

    while (1) {
        bool scan_changed = false;

        scan_changed |= matrix_scan();

        // TODO: need to clean this up
        if (scan_changed) {
            uint8_t i2c_packet[32];
            uint8_t *matrix_data = i2c_packet+1;
            const uint8_t use_deltas = true;

#if USE_I2C
            i2c_packet[0] = (i2c_get_active_address() << 1) | 0x01;
#endif

            const uint8_t data_size = get_matrix_data(matrix_data, use_deltas);

#if USE_I2C
            if (!g_runtime_settings.feature.ctrl.wired_disabled) {
                i2c_packet[data_size+1] = i2c_calculate_checksum(i2c_packet, data_size+1);


                // TODO: IMPORTANT! really need to fix this
                // TODO: don't block here, add buffer for queued messages
                // while (!i2c_broadcast(i2c_packet, data_size+2));

                // TODO: I2C is broken
                // i2c_broadcast(i2c_packet, data_size+2);
            }
#endif

            keyboard_update_device_matrix(GET_SETTING(device_id), matrix_data);

        }

        passthrough_keycodes_task();

        //

// #if USE_I2C
        // // check for i2c data
        // {
        //     uint8_t *i2c_packet = i2c_get_buffer();
        //     while (i2c_packet) {
        //         const uint8_t sender_i2c_address = i2c_packet[0] >> 1;
        //         const uint8_t sender_device_id = i2c_address_to_device_id(sender_i2c_address);
        //         keyboard_update_device_matrix(sender_device_id, i2c_packet+1);

        //         i2c_buffer_advance();
        //         i2c_packet = i2c_get_buffer();
        //     }
        // }
// #endif

        interpret_all_keyboard_matrices();

#if USE_NRF24
        if (g_rf_enabled) {
            // TODO: might want to implement a scheduling system for tasks
            if (unifying_is_pairing_active()) {
                unifying_pairing_poll();
            } else {
                rf_task();
            }
            unifying_mouse_handle();
        }
#endif
        macro_task();
        mouse_key_task();

        send_keyboard_report();
        send_media_report();
        send_mouse_report();
        send_vendor_report();

        // usb out reports
        handle_vendor_out_reports();

        sticky_key_task();
        hold_key_task();

        // led_task();

#if USE_NRF24 && RF_POLLING
        // Don't have RF IRQ, so don't sleep to reduce chance that packets are
        // dropped
        // debug_toggle(0);
#else
        // okay to sleep if we have RF IRQ
        // debug_set(0, 1);
        enter_sleep_mode(SLEEP_MODE_IDLE);
        // debug_set(0, 0);
#endif

        wdt_kick();
    }
}

NO_RETURN_ATTR void recovery_mode_main_loop(void) {
    while (1) {
        send_vendor_report();
        handle_vendor_out_reports();

        enter_sleep_mode(SLEEP_MODE_IDLE);
        wdt_kick();
    }
}

#endif

int main(void) {
    // Disable the wdt incase it was running
    wdt_disable_();
    init_debug();

#if USE_CHECK_PIN
    // Enable VBUS pin so we can check USB voltage
    vbus_pin_init();
#endif

#if USE_NRF24 && USE_CHECK_PIN
    if (has_vbus_power())
    {
        usb_mode_setup();
        usb_mode_main_loop();
    } else {
        battery_mode_setup();
        battery_mode_main_loop();
    }
#elif !USE_CHECK_PIN && USE_NRF24
    battery_mode_setup();
    battery_mode_main_loop();
#else
    usb_mode_setup();
    usb_mode_main_loop();
#endif

    return 0;
}
