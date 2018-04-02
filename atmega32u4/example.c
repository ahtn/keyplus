/* Keyboard example for Teensy USB Development Board
 * http://www.pjrc.com/teensy/usb_keyboard.html
 * Copyright (c) 2008 PJRC.COM, LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <avr/boot.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "usb_keyboard.h"
#include "usb_reports/keyboard_report.h"
#include "usb_reports/media_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"
#include "core/usb_commands.h"
#include "core/flash.h"

#define LED_CONFIG      (DDRD |= (1<<6))
#define LED_ON          (PORTD &= ~(1<<6))
#define LED_OFF         (PORTD |= (1<<6))
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

uint8_t number_keys[10]=
        {KEY_0,KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9};

uint16_t idle_count=0;

#include "bootloaders/atmel_dfu/atmel_bootloader.h"

int main(void)
{
    uint8_t b, d, mask, i, reset_idle;
    uint8_t b_prev=0xFF, d_prev=0xFF;

    // set for 16 MHz clock
    CPU_PRESCALE(0);

    // Configure all port B and port D pins as inputs with pullup resistors.
    // See the "Using I/O Pins" page for details.
    // http://www.pjrc.com/teensy/pins.html
    DDRD = 0x00;
    DDRB = 0x00;
    PORTB = 0xFF;
    PORTD = 0xFF;

    DDRF |= _BV(7) | _BV(6);
    PORTF |= _BV(7) | _BV(6);

    flash_modify_enable();
#if 0
    // Hello wold of writing to flash
        for (int i = 0; i < SPM_PAGESIZE; i += 2) {
                flash_fill_temp_buffer((i & 0xff) | (((i+1) & 0xff)<<8), i);
    }
    flash_page_erase_and_write(0x4000);
    // flash_erase_page(0x4000 / PAGE_SIZE); // check erase page works
#elif 0
    // test flash.c interface
    flash_erase_page(0x4000 / PAGE_SIZE);
    flash_write(
        number_keys,
        0x4000,
        0x10
    );
#elif 0
    // Dump the signature section to flash at address 0x4000
    {
        uint8_t sig_data[256];
        uint8_t i;

        do {
            sig_data[i] = boot_signature_byte_get(i);
            i++;
        } while (i != 0);
        flash_erase_page(0x4000 / PAGE_SIZE);
        flash_write(
            sig_data,
            0x4000,
            sizeof(sig_data)
        );
    }
#endif
    flash_modify_disable();

    // Initialize the USB, and then wait for the host to set configuration.
    // If the Teensy is powered without a PC connected to the USB port,
    // this will wait forever.
    usb_init();
    sei();
    while (!usb_configured()) /* wait */ ;

    // Wait an extra second for the PC's operating system to load drivers
    // and do whatever it does to actually be ready for input
    _delay_ms(1000);

    // Configure timer 0 to generate a timer overflow interrupt every
    // 256*1024 clock cycles, or approx 61 Hz when using 16 MHz clock
    // This demonstrates how to use interrupts to implement a simple
    // inactivity timeout.
    TCCR0A = 0x00;
    TCCR0B = 0x05;
    TIMSK0 = (1<<TOIE0);

    while (1) {
        // read all port B and port D pins
        b = PINB;
        d = PIND;
        // check if any pins are low, but were high previously
        mask = 1;
        reset_idle = 0;
        for (i=0; i<8; i++) {
                if (((b & mask) == 0) && (b_prev & mask) != 0) {
                        usb_keyboard_press(KEY_B, KEY_SHIFT);
                        usb_keyboard_press(number_keys[i], 0);
                        reset_idle = 1;
                }
                if (((d & mask) == 0) && (d_prev & mask) != 0) {
                        usb_keyboard_press(KEY_D, KEY_SHIFT);
                        usb_keyboard_press(number_keys[i], 0);
                        reset_idle = 1;
                }
                mask = mask << 1;
        }
        // if any keypresses were detected, reset the idle counter
        if (reset_idle) {
                // variables shared with interrupt routines must be
                // accessed carefully so the interrupt routine doesn't
                // try to use the variable in the middle of our access
                cli();
                idle_count = 0;
                sei();
        }
        // now the current pins will be the previous, and
        // wait a short delay so we're not highly sensitive
        // to mechanical "bounce".
        b_prev = b;
        d_prev = d;
        _delay_ms(2);

        send_vendor_report();
        handle_vendor_out_reports();
    }
}

// This interrupt routine is run approx 61 times per second.
// A very simple inactivity timeout is implemented, where we
// will send a space character.
ISR(TIMER0_OVF_vect)
{
        idle_count++;
        // if (idle_count > 61 * 8) {
        //      idle_count = 0;
        //      usb_keyboard_press(KEY_SPACE, 0);
        // }
}


