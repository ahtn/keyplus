// Copyright (c) 2011-2014 Nonolith Labs
// Copyright (c) 2014 Technical Machine
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

#include "usb.h"
#include "xmega/usb_xmega.h"
#include "xmega/usb_xmega_internal.h"

static uint8_t usb_connection_established;

void usb_init() {
    NVM.CMD  = NVM_CMD_READ_CALIB_ROW_gc;
    USB.CAL0 = pgm_read_byte(offsetof(NVM_PROD_SIGNATURES_t, USBCAL0));
    NVM.CMD  = NVM_CMD_READ_CALIB_ROW_gc;
    USB.CAL1 = pgm_read_byte(offsetof(NVM_PROD_SIGNATURES_t, USBCAL1));
    NVM.CMD = NVM_CMD_NO_OPERATION_gc;

    usb_connection_established = 0;

    usb_reset();
}

void usb_reset() {
    CLK.USBCTRL = ((((F_USB / 48000000) - 1) << CLK_USBPSDIV_gp) | CLK_USBSRC_RC32M_gc | CLK_USBSEN_bm);
    USB.EPPTR = (unsigned) &usb_xmega_endpoints;
    USB.ADDR = 0;

    usb_xmega_endpoints[0].out.STATUS = 0;
    usb_xmega_endpoints[0].out.CTRL = USB_EP_TYPE_CONTROL_gc | USB_EP_size_to_gc(USB_EP0_SIZE);
    usb_xmega_endpoints[0].out.DATAPTR = (unsigned) &ep0_buf_out;
    usb_xmega_endpoints[0].in.STATUS = USB_EP_BUSNACK0_bm;
    usb_xmega_endpoints[0].in.CTRL = USB_EP_TYPE_CONTROL_gc | USB_EP_size_to_gc(USB_EP0_SIZE);
    usb_xmega_endpoints[0].in.DATAPTR = (unsigned) &ep0_buf_in;

    USB.CTRLA = USB_ENABLE_bm | USB_SPEED_bm | (usb_num_endpoints+1);

    usb_cb_reset();
}

bool has_usb_connection(void) {
    return usb_connection_established;
}

void usb_set_address(uint8_t addr) {
    USB.ADDR = addr;
}

const uint8_t* usb_ep0_from_progmem(const uint8_t* addr, uint16_t size) {
    uint8_t *buf = ep0_buf_in;
    uint16_t remaining = size;
    NVM.CMD = NVM_CMD_NO_OPERATION_gc;
    while (remaining--){
        *buf++ = pgm_read_byte(addr++);
    }
    return ep0_buf_in;
}

inline usb_bank usb_ep_start_out(uint8_t ep, uint8_t* data, usb_size len) {
    _USB_EP(ep);
    e->DATAPTR = (unsigned) data;
    LACR16(&(e->STATUS), USB_EP_BUSNACK0_bm | USB_EP_TRNCOMPL0_bm);
    return 0;
}

inline usb_bank usb_ep_start_in(uint8_t ep, const uint8_t* data, usb_size size, bool zlp) {
    _USB_EP(ep);
    e->DATAPTR = (unsigned) data;
    e->CNT = size | (zlp << 15);
    LACR16(&(e->STATUS), USB_EP_BUSNACK0_bm | USB_EP_TRNCOMPL0_bm);
    return 0;
}

inline bool usb_ep_ready(uint8_t ep) {
    _USB_EP(ep);
    return !(e->STATUS & (USB_EP_BUSNACK0_bm | USB_EP_TRNCOMPL0_bm));
}

inline bool usb_ep_empty(uint8_t ep) {
    _USB_EP(ep);
    return !(e->STATUS & (USB_EP_BUSNACK0_bm | USB_EP_TRNCOMPL0_bm));
}

inline bool usb_ep_pending(uint8_t ep) {
    _USB_EP(ep);
    return e->STATUS & USB_EP_TRNCOMPL0_bm;
}

inline void usb_ep_handled(uint8_t ep) {
    _USB_EP(ep);
    LACR16(&(e->STATUS), USB_EP_TRNCOMPL0_bm);
}

inline uint16_t usb_ep_out_length(uint8_t ep){
    _USB_EP(ep);
    return e->CNT;
}

inline void usb_detach(void) ATTR_ALWAYS_INLINE;
inline void usb_detach(void) {
    USB.CTRLB &= ~USB_ATTACH_bm;
}

inline void usb_attach(void) ATTR_ALWAYS_INLINE;
inline void usb_attach(void) {
    USB.CTRLB |= USB_ATTACH_bm;
}

/// Enable the OUT stage on the default control pipe.
inline void usb_ep0_out(void) {
    LACR16(&usb_xmega_endpoints[0].out.STATUS, USB_EP_SETUP_bm | USB_EP_BUSNACK0_bm | USB_EP_TRNCOMPL0_bm | USB_EP_OVF_bm);
}

inline void usb_ep0_in(uint8_t size){
    usb_ep_start_in(0x80, ep0_buf_in, size, false);
}

inline void usb_ep0_stall(void) {
    usb_xmega_endpoints[0].out.CTRL |= USB_EP_STALL_bm;
    usb_xmega_endpoints[0].in.CTRL  |= USB_EP_STALL_bm;
}

void usb_set_speed(USB_Speed speed) { }
USB_Speed usb_get_speed() { return USB_SPEED_FULL; }

// use the 32MHz internal RC oscillator configured with DFLL for 48MHz (USB clk)
// use the 2MHz internal RC oscillator configured with PLL for 32MHz (CPU clk)
void usb_configure_clock() {

    // Calibrate the DFLL to clock the 32MHz RC oscillator at 48MHz for the
    // USB clock source but don't enable it yet.
    // See: datasheet section 7.7
    {
        // Note: We use USB SOF packets to calibrate the clock. SOF packets are
        // not generate until we actually attached to a USB port. Because of
        // this, we don't enable the DFLL here, instead we enable it when we
        // receive the first SOF interrupt after attaching to a USB port.
        DFLLRC32M.CTRL &= ~DFLL_ENABLE_bm;

        // Configure DFLL for 48MHz, calibrated by USB SOF
        OSC.DFLLCTRL = OSC_RC32MCREF_USBSOF_gc;

        // NOTE: The DFLL tweaks the value of CALA to dynamically recalibrate
        // the the RC oscillator. The CALA value is a 7 bit value, and the few
        // chips that I tested seem to have this value factory calibrated to
        // 0x40 (the mid point of its 7 bit range).
        // Note: Even if the DFLL is disabled, the values CALA and CALB can be
        // modified to adjust the frequency of the RC oscillator.
        NVM.CMD = NVM_CMD_READ_CALIB_ROW_gc;
        DFLLRC32M.CALA = pgm_read_byte(offsetof(NVM_PROD_SIGNATURES_t, USBRCOSCA));
        DFLLRC32M.CALB = pgm_read_byte(offsetof(NVM_PROD_SIGNATURES_t, USBRCOSC));
        NVM.CMD = NVM_CMD_NO_OPERATION_gc;

        // Setting DFLL clock calibration register.
        // Target clk frequency: 48MHz
        // SOF frequency: 1000Hz
        // COMP = 48MHz / 1000Hz = 0xBB80
        // See also:
        //  - Xmega AU manual, 4.17.19
        //  - http://www.avrfreaks.net/forum/xmega-internal-clock-problems
        DFLLRC32M.COMP1 = 0x80;
        DFLLRC32M.COMP2 = 0xBB;

        // Enable the 32MHz RC oscillator
        CCP = CCP_IOREG_gc; //Security Signature to modify clock
        OSC.CTRL = OSC_RC32MEN_bm; // enable internal 32MHz oscillator

        while(!(OSC.STATUS & OSC_RC32MRDY_bm)); // wait for oscillator ready
    }

    // Configure the CPU clock source to be 32MHz by multiplying the
    // 2MHz RC oscillator up with the PLL.
    // See: datasheet section 7.6
    {
        OSC.PLLCTRL = OSC_PLLSRC_RC2M_gc | 16; // 2MHz * 16 = 32MHz

        CCP = CCP_IOREG_gc;
        OSC.CTRL = OSC_RC32MEN_bm | OSC_PLLEN_bm | OSC_RC2MEN_bm ; // Enable PLL

        while(!(OSC.STATUS & OSC_PLLRDY_bm)); // wait for PLL ready

        DFLLRC2M.CTRL = DFLL_ENABLE_bm;

        CCP = CCP_IOREG_gc; //Security Signature to modify clock
        CLK.CTRL = CLK_SCLKSEL_PLL_gc; // Select PLL
        CLK.PSCTRL = 0x00; // No peripheral clock prescaler
    }
}

static uint32_t sof_count = 0;

uint32_t get_sof_count(void) {
#ifdef USE_USB_POLLING
    return sof_count;
#else
    uint32_t result;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        result = sof_count;
    }
    return result;
#endif
}

static void inline busevent_vect(void) {
    if (!USB.INTFLAGSACLR) {
        return;
    }

    if (USB.INTFLAGSACLR & USB_SOFIF_bm) {
        USB.INTFLAGSACLR = USB_SOFIF_bm;
        sof_count++;

        if (!(DFLLRC32M.CTRL & DFLL_ENABLE_bm)) {
            // enable dfll because SOF packets are being generated
            DFLLRC32M.CTRL |= DFLL_ENABLE_bm;
            usb_connection_established = 1;
        }
    }

    if (USB.INTFLAGSACLR & (USB_CRCIF_bm | USB_UNFIF_bm | USB_OVFIF_bm)) {
        USB.INTFLAGSACLR = (USB_CRCIF_bm | USB_UNFIF_bm | USB_OVFIF_bm);
    }

    if (USB.INTFLAGSACLR & USB_STALLIF_bm) {
        USB.INTFLAGSACLR = USB_STALLIF_bm;
    }

    if (USB.INTFLAGSACLR & (USB_SUSPENDIF_bm | USB_RESUMEIF_bm | USB_RSTIF_bm)) {
        if (USB.INTFLAGSACLR & USB_RSTIF_bm) {
            USB.STATUS &= ~USB_BUSRST_bm;
            usb_reset();
        }

        USB.INTFLAGSACLR = USB_SUSPENDIF_bm | USB_RESUMEIF_bm | USB_RSTIF_bm;

        if (DFLLRC32M.CTRL & DFLL_ENABLE_bm) {
            // disable dfll now because SOF packets are not being generated
            DFLLRC32M.CTRL &= ~DFLL_ENABLE_bm;
            usb_connection_established = 0;
        }

        // re-load the factory calibration values for the RC oscillator
        NVM.CMD = NVM_CMD_READ_CALIB_ROW_gc;
        DFLLRC32M.CALA = pgm_read_byte(offsetof(NVM_PROD_SIGNATURES_t, USBRCOSCA));
        DFLLRC32M.CALB = pgm_read_byte(offsetof(NVM_PROD_SIGNATURES_t, USBRCOSC));
        NVM.CMD = NVM_CMD_NO_OPERATION_gc;
    }
}

static void inline trncompl_vect(void) {
    if (!(USB.INTFLAGSBCLR & (USB_SETUPIF_bm | USB_TRNIF_bm))) {
        return;
    }

    USB.FIFOWP = 0;
    USB.INTFLAGSBCLR = USB_SETUPIF_bm | USB_TRNIF_bm;

    // Read once to prevent race condition where SETUP packet is interpreted as OUT
    uint8_t status = usb_xmega_endpoints[0].out.STATUS;

    if (status & USB_EP_SETUP_bm){
        // TODO: race conditions because we can't block a setup packet
        LACR16(&(usb_xmega_endpoints[0].out.STATUS), USB_EP_TRNCOMPL0_bm | USB_EP_SETUP_bm);
        memcpy(&usb_setup, ep0_buf_out, sizeof(usb_setup));
        usb_handle_setup();
    } else if(status & USB_EP_TRNCOMPL0_bm){
        usb_handle_control_out_complete();
    }

    if (usb_xmega_endpoints[0].in.STATUS & USB_EP_TRNCOMPL0_bm) {
        usb_handle_control_in_complete();
    }

    usb_cb_completion();
}

#ifdef USE_USB_POLLING
void usb_poll(void) {
    busevent_vect();
    trncompl_vect();
}
#else
// use interrupt handlers if polling is not used
ISR(USB_BUSEVENT_vect) {
    busevent_vect();
}

ISR(USB_TRNCOMPL_vect){
    trncompl_vect();
}
#endif
