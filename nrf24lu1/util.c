
static uint8_t read_info_page_byte(uint16_t addr) {
    __asm
        ; addr -> (DPL, DPH)
        set     _INFEN          ; make movx read from info page
        movx    a, @dptr        ; read value at addr (dptr)
        clr     _INFEN          ; disable reading from info page
        mov     _DPL, a         ; return value is stored in DPL
    __endasm;
}
