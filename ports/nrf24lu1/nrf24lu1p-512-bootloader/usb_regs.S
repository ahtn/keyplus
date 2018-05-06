.module usb_regs

_INT_SUDAV    = 0x00
_INT_SOF      = 0x04
_INT_SUTOK    = 0x08
_INT_SUSPEND  = 0x0C
_INT_USBRESET = 0x10
_INT_EP0_IN    = 0x18
_INT_EP0_OUT   = 0x1C
_INT_EP1_IN    = 0x20
_INT_EP1_OUT   = 0x24

; info page addresses
_rdismb = 0x0023

;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
.area XSEG    (XDATA)
    _in1buf           = 0xc680
    _out1buf          = 0xc640
    _in0buf           = 0xc700
    _out8data         = 0xc760
    _in8data          = 0xc768
    _out8bch          = 0xc770
    _out8bcl          = 0xc771
    _bout1addr        = 0xc781
    _bout2addr        = 0xc782
    _bout3addr        = 0xc783
    _bout4addr        = 0xc784
    _bout5addr        = 0xc785
    _binstaddr        = 0xc788
    _bin1addr         = 0xc789
    _bin2addr         = 0xc78a
    _bin3addr         = 0xc78b
    _bin4addr         = 0xc78c
    _bin5addr         = 0xc78d
    _isoerr           = 0xc7a0
    _zbcout           = 0xc7a2
    _ivec             = 0xc7a8
    _in_irq           = 0xc7a9
    _out_irq          = 0xc7aa
    _usbirq           = 0xc7ab
    _in_ien           = 0xc7ac
    _out_ien          = 0xc7ad
    _usbien           = 0xc7ae
    _usbbav           = 0xc7af
    _ep0cs            = 0xc7b4
    _in0bc            = 0xc7b5
    _in1cs            = 0xc7b6
    _in1bc            = 0xc7b7
    _in2cs            = 0xc7b8
    _in2bc            = 0xc7b9
    _in3cs            = 0xc7ba
    _in3bc            = 0xc7bb
    _in4cs            = 0xc7bc
    _in4bc            = 0xc7bd
    _in5cs            = 0xc7be
    _in5bc            = 0xc7bf
    _out0bc           = 0xc7c5
    _out1cs           = 0xc7c6
    _out1bc           = 0xc7c7
    _out2cs           = 0xc7c8
    _out2bc           = 0xc7c9
    _out3cs           = 0xc7ca
    _out3bc           = 0xc7cb
    _out4cs           = 0xc7cc
    _out4bc           = 0xc7cd
    _out5cs           = 0xc7ce
    _out5bc           = 0xc7cf
    _usbcs            = 0xc7d6
    _togctl           = 0xc7d7
    _usbframel        = 0xc7d8
    _usbframeh        = 0xc7d9
    _fnaddr           = 0xc7db
    _usbpair          = 0xc7dd
    _inbulkval        = 0xc7de
    _outbulkval       = 0xc7df
    _inisoval         = 0xc7e0
    _outisoval        = 0xc7e1
    _isostaddr        = 0xc7e2
    _isosize          = 0xc7e3
    _setupbuf         = 0xc7e8
    _usbRequest       = 0xc7e8
    _usbReqGetDesc    = 0xc7e8
    _usbReqHidGetDesc = 0xc7e8
    _out8addr         = 0xc7f0
    _in8addr          = 0xc7f8
