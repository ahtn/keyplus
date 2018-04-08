// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "usb_keyboard.h"
#include "usb_reports/keyboard_report.h"
#include "usb_reports/media_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"
#include "core/usb_commands.h"
#include "core/flash.h"

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

int main(void)
{
    // set for 16 MHz clock
    CPU_PRESCALE(0);

    wdt_reset();
    wdt_disable();

    DDRF |= _BV(7) | _BV(6);
    PORTF |= _BV(7) | _BV(6);

    usb_init();
    sei();

    while (1) {
        _delay_ms(2);

        send_vendor_report();
        handle_vendor_out_reports();
    }
}
