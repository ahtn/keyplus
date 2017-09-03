// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "power.h"

#include "config.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <util/atomic.h>
#include <string.h>

#include "core/timer.h"
#include "core/hardware.h"
#include "core/nrf24.h"
#include "core/matrix_scanner.h"

#define PR_ALL_GENERAL_bm (PR_USB_bm | PR_AES_bm | PR_EBI_bm | \
            PR_RTC_bm | PR_EVSYS_bm | PR_DMA_bm)

#define PR_ALL_PERIPH_bm (PR_HIRES_bm | PR_TC0_bm | PR_TC1_bm | \
            PR_SPI_bm | PR_TWI_bm | PR_USART0_bm | PR_USART1_bm)

#define PR_ALL_ANALOG_bm (PR_ADC_bm | PR_DAC_bm | PR_AC_bm)

static power_mode_t s_power_mode = MODE_BATTERY;

power_mode_t get_power_mode(void) {
    return s_power_mode;
}

void set_power_mode(power_mode_t power_mode) {
    // What we use in different modes:
    // In battery mode:
    //  AES, RTC
    //  SPI: port C
    //
    // In i2c mode:
    //  RTC
    //  TWI: port E
    //
    // In USB mode:
    //  USB, AES, RTC
    //  TWI: port E
    //  SPI: port C
    //

    // Note: Other xmega chips have different options, so if a different chip is used
    // changes may need to be made.
    // Note: Modules need to re-initialized after they have been in a powered
    // down state.

    // options (setting 1: disabled, 0:enabled)

    // PR.PRGEN
    // Possible: USB, AES, EBI, RTC, EVSYS, DMA

    // ports C,D,E,F all have these options to choose from:
    //  TWI, USART1, USART0, SPI, HIRES, TC1, TC0
    //
    // Analog interface power reduction
    // ports A,B:
    // DAC, ADC, AC

    s_power_mode = power_mode;

    PR.PRPA = PR_ALL_ANALOG_bm; // port A
    PR.PRPB = PR_ALL_ANALOG_bm; // port B
    PR.PRPC = PR_ALL_PERIPH_bm; // port C
    PR.PRPD = PR_ALL_PERIPH_bm; // port D
    PR.PRPE = PR_ALL_PERIPH_bm; // port E
    PR.PRPF = PR_ALL_PERIPH_bm; // port F

    if (power_mode == MODE_BATTERY) {
        // ON: AES, RTC
        PR.PRGEN = PR_ALL_GENERAL_bm & ~(PR_AES_bm | PR_RTC_bm);

        PR.PRPC = PR_ALL_PERIPH_bm & ~(PR_SPI_bm); // port C: keep spi on
    } else if (power_mode == MODE_WIRED) {
        // ON: RTC
        PR.PRGEN = PR_ALL_GENERAL_bm & ~(PR_RTC_bm);

#if USE_NRF24
        // port C: turn spi on, so we can disable nrf24
        PR.PRPC = PR_ALL_PERIPH_bm & ~(PR_SPI_bm);

        // need to enable communication to disable nrf24
        nrf24_init();
        nrf24_power_set(0);

        PR.PRPC = PR_ALL_PERIPH_bm; // port C: don't need spi any more
#endif

        PR.PRPE = PR_ALL_PERIPH_bm & ~(PR_TWI_bm); // port E: keep twi on
    } else if (power_mode == MODE_USB) {
        // ON: USB, AES, RTC
        PR.PRGEN = PR_ALL_GENERAL_bm & ~(PR_USB_bm | PR_AES_bm | PR_RTC_bm);

        PR.PRPC = PR_ALL_PERIPH_bm & ~(PR_SPI_bm); // port C: keep spi on
        PR.PRPE = PR_ALL_PERIPH_bm & ~(PR_TWI_bm); // port E: keep twi on
    }

    // disable jtag
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        CCP = 0xD8;
        MCU_MCUCR = MCU_JTAGD_bm;
    }
}

#define CLK_PSADIV_1   (0b00000 << CLK_PSADIV_gp)
#define CLK_PSADIV_2   (0b00001 << CLK_PSADIV_gp)
#define CLK_PSADIV_4   (0b00011 << CLK_PSADIV_gp)
#define CLK_PSADIV_8   (0b00101 << CLK_PSADIV_gp)
#define CLK_PSADIV_16  (0b00111 << CLK_PSADIV_gp)
#define CLK_PSADIV_32  (0b01001 << CLK_PSADIV_gp)
#define CLK_PSADIV_64  (0b01011 << CLK_PSADIV_gp)
#define CLK_PSADIV_128 (0b01101 << CLK_PSADIV_gp)
#define CLK_PSADIV_256 (0b01111 << CLK_PSADIV_gp)
#define CLK_PSADIV_512 (0b10001 << CLK_PSADIV_gp)

#define CLK_PSBCDIV_1_1 (0b00 << CLK_PSBCDIV_gp)
#define CLK_PSBCDIV_1_2 (0b01 << CLK_PSBCDIV_gp)
#define CLK_PSBCDIV_4_1 (0b10 << CLK_PSBCDIV_gp)
#define CLK_PSBCDIV_2_2 (0b11 << CLK_PSBCDIV_gp)

// In battery mode use 12MHz clock by multiplying the 2MHz RC OSC by 12 with PLL.
// and dividing by 2 to get 12MHz.
// Note: The datasheet says the output frequency of PLL should be in the range
// of 20MHz to 128MHz. In practice it still seems to work anyway if it is below
// 20MHz.
void battery_mode_clock_init(void) {
    OSC.PLLCTRL = OSC_PLLSRC_RC2M_gc | OSC_PLLDIV_bm | 12; // 2MHz * 12 / 2 = 12MHz

    CCP = CCP_IOREG_gc; // make CCP register allow changes
    OSC.CTRL = OSC_PLLEN_bm | OSC_RC2MEN_bm; // Enable PLL and 2MHz internal OSC

    while(!(OSC.STATUS & OSC_PLLRDY_bm)); // wait for PLL ready

    CCP = CCP_IOREG_gc; // make CCP register allow changes
    CLK.CTRL = CLK_SCLKSEL_PLL_gc; // use PLL
    CLK.PSCTRL = 0x00; // no prescaler

    g_slow_clock_mode = 1;
}


void enter_sleep_mode(uint8_t sleep_mode) {
    // set sleep mode
    set_sleep_mode(sleep_mode);

    cli();
    // go to sleep
    sleep_enable();
    sei();
    sleep_cpu();
    sleep_disable();
}

#if USE_NRF24
void deep_sleep(void) {
    // TODO: consider disabling BOD while in deep sleep
    cli();

    nrf24_power_set(0);

    // the only way we can wake up is if a key is pressed, or if the VBUS check
    // pin changes
    matrix_scan_irq_enable();

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sei();
    sleep_cpu();
    sleep_disable();

    // disable irq on matrix change
    matrix_scan_irq_disable();

    // TODO: should probably check that the nRF24l01+ state is still valid.
    // While we were asleep, and it's registers are still okay.
    nrf24_power_set(1);
}
#endif

#if USE_CHECK_PIN
bool has_vbus_power(void) {
    return VBUS_PORT.IN & VBUS_PIN_MASK;
}

void vbus_pin_init(void) {
    // init the pin to check VUSB
    VBUS_PORT.DIRCLR = VBUS_PIN_MASK;
    PORTCFG.MPCMASK = VBUS_PIN_MASK;
    VBUS_PORT.PIN0CTRL = PORT_OPC_TOTEM_gc;
    VBUS_PORT.OUTCLR = VBUS_PIN_MASK;

    VBUS_PORT.INT0MASK |= VBUS_PIN_MASK;
    VBUS_PORT.INTCTRL = PORT_INT0LVL_HI_gc;
}

// TODO: when we reset make sure to add some sort of delay so that we don't
// trigger this over and over again while the input is debouncing.
ISR(VBUS_PIN_INT0_VECT) {
#if USE_NRF24
    // Put the nRF24 module in standby-I mode to stop RX and TX operations.
    nrf24_ce(0);
#endif
    reset_mcu();
}
#endif
