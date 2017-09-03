//
// MIT License
//
// Copyright (c) 2017 seethis.link
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

#pragma once

#define USB_CS_BUSY 0x02

// interrupt codes
#define INT_SUDAV     0x00
#define INT_SOF       0x04
#define INT_SUTOK     0x08
#define INT_SUSPEND   0x0C
#define INT_USBRESET  0x10
#define INT_EP0IN     0x18
#define INT_EP0OUT    0x1C
#define INT_EP1IN     0x20
#define INT_EP1OUT    0x24
#define INT_EP2IN     0x28
#define INT_EP2OUT    0x2C
#define INT_EP3IN     0x30
#define INT_EP3OUT    0x34
#define INT_EP4IN     0x38
#define INT_EP4OUT    0x3C
#define INT_EP5IN     0x40
#define INT_EP5OUT    0x44

// clear hsnak bit
#define USB_EP0_HSNAK() ep0cs = 0x02

// set stall and dstall bits to stall during setup data transaction
#define USB_EP0_STALL() ep0cs  =  0x11
