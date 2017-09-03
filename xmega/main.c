// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <string.h>

#include "core/keyboard_report.h"
#include "core/media_report.h"
#include "core/mouse_report.h"
#include "core/vendor_report.h"

#include "core/aes.h"
#include "core/hardware.h"
#include "core/layout.h"
#include "core/led.h"
#include "core/matrix_interpret.h"
#include "core/matrix_scanner.h"
#include "core/packet.h"
#include "core/rf.h"
#include "core/settings.h"
#include "core/timer.h"
#include "core/usb_commands.h"
#include "core/macro.h"
#include "core/nrf24.h"

#include "key_handlers/key_hold.h"

#include "xmega/usb_xmega.h"
#include "hardware_user_impl.h"

#include "power.h"
#include "wired.h"
#include "led_vm.h"

#include "xmega_hardware.h"

USB_ENDPOINTS(5);

void wdt_disable(void) {
    uint8_t temp = (WDT.CTRL & ~WDT_ENABLE_bm) | WDT_CEN_bm;
    CCP = CCP_IOREG_gc;
    WDT.CTRL = temp;
}

// NOTE: Pins that are left floating can cause the system to use more power, so
// making them output low.
// TODO: Can't use this implementation because which pins are being used is
// set at run time. Should probably make them input low with pull down.
void unused_pins_init(void) {
#if SET_FLOATING_PINS_LOW
    PORTA.DIRSET = PORTA_FLOATING_PINS;
    PORTA.OUTCLR = PORTA_FLOATING_PINS;
    PORTB.DIRSET = PORTB_FLOATING_PINS;
    PORTB.OUTCLR = PORTB_FLOATING_PINS;
    PORTC.DIRSET = PORTC_FLOATING_PINS;
    PORTC.OUTCLR = PORTC_FLOATING_PINS;
    PORTD.DIRSET = PORTD_FLOATING_PINS;
    PORTD.OUTCLR = PORTD_FLOATING_PINS;
    PORTE.DIRSET = PORTE_FLOATING_PINS;
    PORTE.OUTCLR = PORTE_FLOATING_PINS;
    PORTR.DIRSET = PORTR_FLOATING_PINS;
    PORTR.OUTCLR = PORTR_FLOATING_PINS;
#endif
}

void pin_init(void) {
    unused_pins_init();
    led_init();
}

void xmega_common_init(void) {
    hardware_init();
    pin_init();
    settings_load_from_flash();
    aes_key_init(g_rf_settings.ekey, g_rf_settings.dkey);
    matrix_scanner_init();
    led_testing_set(0);
}

#if USE_NRF24
void battery_mode_setup(void) {
    set_power_mode(MODE_BATTERY);

    // battery mode uses the ULP RTC timer
    rtc_ulp_init();

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

    while (1) {
#if TESTING_PIN_TGL
        // PORTC.OUTTGL = PIN0_bm;

        PORTC.OUTTGL = PIN1_bm | PIN2_bm;
#endif

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

#if TESTING_PIN_TGL
        PORTC.OUTTGL = PIN1_bm | PIN2_bm;
#endif

        uint8_t nrf_status = nrf24_read_status();

#if TESTING_PIN_TGL
        PORTC.OUTTGL = PIN2_bm;
#endif

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
#if TESTING_PIN_TGL
                PORTC.OUTTGL = PIN0_bm;
#endif
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

#if TESTING_PIN_TGL
        PORTC.OUTTGL = PIN2_bm;
#endif

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

#if TESTING_PIN_TGL
        PORTC.OUTTGL = PIN2_bm;
#endif

        if (get_matrix_num_keys_down() == 0 &&
            (uint16_t)(timer_read16_ms() - idle_time_start) > DEEP_SLEEP_TIME &&
            get_matrix_num_keys_debouncing() == 0 &&
            !scan_changed &&
            (fifo_status & FIFO_TX_EMPTY_bm)
            ) {
#if TESTING_PIN_TGL
            PORTC.OUTTGL = PIN2_bm;
#endif
            deep_sleep();
            idle_time_start = timer_read16_ms();
            matrix_needs_scanning = true;
            deep_sleep_resync_packet = true;
        } else {
#if TESTING_PIN_TGL
            PORTC.OUTTGL = PIN2_bm;
#endif

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

void usb_mode_setup(void) {
    set_power_mode(MODE_USB);

    timer_init();

    wdt_init();

    g_slow_clock_mode = 0;
    usb_configure_clock();

    xmega_common_init();

    usb_init();
    reset_usb_reports();
    keyboards_init();

#if USE_NRF24
    g_rf_enabled = true;
    rf_init_receive();
#endif

#if USE_I2C
    i2c_init();
#endif

    // enable all interrupt levels
    PMIC.CTRL = PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;

    // Enable USB interrupts
    USB.INTCTRLA = USB_SOFIE_bm | USB_BUSEVIE_bm | USB_INTLVL_MED_gc;
    USB.INTCTRLB = USB_TRNIE_bm | USB_SETUPIE_bm;

    sei();

    usb_attach();
}

void usb_mode_main_loop(void) {
    // uint8_t has_rf_message = false;

    while (1) {
        bool scan_changed = false;

        scan_changed |= matrix_scan();


        // TODO: need to clean this up
        if (scan_changed) {
            uint8_t i2c_packet[32];
            uint8_t *matrix_data = i2c_packet+1;
            const uint8_t use_deltas = true;

            i2c_packet[0] = (i2c_get_active_address() << 1) | 0x01;
            const uint8_t data_size = get_matrix_data(matrix_data, use_deltas);
            i2c_packet[data_size+1] = i2c_calculate_checksum(i2c_packet, data_size+1);

#if USE_I2C
            // TODO: important
            // TODO: don't block here, add buffer for queued messages
            while (!i2c_broadcast(i2c_packet, data_size+2));
#endif

            keyboard_update_device_matrix(g_settings.device_id, matrix_data);

            if (is_passthrough_enabled()) {
                g_vendor_report_in.data[0] = CMD_PASSTHROUGH_MATRIX;
                memcpy(g_vendor_report_in.data+1, g_matrix, MATRIX_DATA_SIZE);
                g_vendor_report_in.len = MATRIX_DATA_SIZE+1;
            }
        }

#if USE_I2C
        // check for i2c data
        {
            uint8_t *i2c_packet = i2c_get_buffer();
            while (i2c_packet) {
                const uint8_t sender_i2c_address = i2c_packet[0] >> 1;
                const uint8_t sender_device_id = i2c_address_to_device_id(sender_i2c_address);
                keyboard_update_device_matrix(sender_device_id, i2c_packet+1);

                i2c_buffer_advance();
                i2c_packet = i2c_get_buffer();
            }
        }
#endif

        interpret_all_keyboard_matrices();

#if USE_NRF24
        if (g_rf_enabled) {
            // TODO: might want to implement a scheduling system for tasks
            rf_task();
        }

        // TODO: ignore these USB tasks when no USB present connected (i.e. i2c
        // mode). We can then use deeper sleep modes.
        unifying_mouse_handle();
#endif

        led_task();
        macro_task();

        send_keyboard_report();
        send_media_report();
        send_mouse_report();
        send_vendor_report();

        // usb out reports
        handle_vendor_out_reports();

        sticky_key_task();
        hold_key_task();

        enter_sleep_mode(SLEEP_MODE_IDLE);
        wdt_kick();

    }
}

int main(void) {
    // Disable the wdt incase it was running
    wdt_disable();

#if USE_CHECK_PIN
    // Enable VBUS pin so we can check USB voltage
    vbus_pin_init();
#endif

#if TESTING_PIN_TGL
    PORTC.DIRSET = 0b1111;
    PORTC.OUTCLR = 0b1111;
#endif


#if USE_NRF24 && USE_CHECK_PIN
#if !TESTING_PIN_TGL
    if (has_vbus_power())
    {
        usb_mode_setup();
        usb_mode_main_loop();
    } else {
#endif
        battery_mode_setup();
        battery_mode_main_loop();
#if !TESTING_PIN_TGL
    }
#endif

#else
    usb_mode_setup();
    usb_mode_main_loop();
#endif

    return 0;
}
