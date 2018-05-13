# Notes about ld scripts

Use custom ld scripts to removed vector table.

# xmega link scripts (from avr-gcc man page)

* avrxmega2

    “XMEGA” devices with more than 8 KiB and up to 64 KiB of program memory.
    mcu = atxmega16a4, atxmega16a4u, atxmega16c4, atxmega16d4, atxmega16e5, atxmega32a4, atxmega32a4u, atxmega32c3, atxmega32c4, atxmega32d3, atxmega32d4, atxmega32e5, atxmega8e5.

* avrxmega3

    “XMEGA” devices with up to 64 KiB of combined program memory and RAM, and with program memory visible in the RAM address space.
    mcu = attiny1614, attiny1616, attiny1617, attiny212, attiny214, attiny3214, attiny3216, attiny3217, attiny412, attiny414, attiny416, attiny417, attiny814, attiny816, attiny817.

* avrxmega4

    “XMEGA” devices with more than 64 KiB and up to 128 KiB of program memory.
    mcu = atxmega64a3, atxmega64a3u, atxmega64a4u, atxmega64b1, atxmega64b3, atxmega64c3, atxmega64d3, atxmega64d4.

* avrxmega5

    “XMEGA” devices with more than 64 KiB and up to 128 KiB of program memory and more than 64 KiB of RAM.
    mcu = atxmega64a1, atxmega64a1u.

* avrxmega6

    “XMEGA” devices with more than 128 KiB of program memory.
    mcu = atxmega128a3, atxmega128a3u, atxmega128b1, atxmega128b3, atxmega128c3, atxmega128d3, atxmega128d4, atxmega192a3, atxmega192a3u, atxmega192c3, atxmega192d3, atxmega256a3, atxmega256a3b, atxmega256a3bu, atxmega256a3u, atxmega256c3, atxmega256d3, atxmega384c3, atxmega384d3.

* avrxmega7

    “XMEGA” devices with more than 128 KiB of program memory and more than 64 KiB of RAM.
    mcu = atxmega128a1, atxmega128a1u, atxmega128a4u.



# Why are there five different linker scripts? (from avr libc manual)

From a comment in the source code:

Which one of the five linker script files is actually used depends on command line options given to ld.

A .x script file is the default script A .xr script is for linking without relocation (-r flag) A .xu script is like .xr but *do* create constructors (-Ur flag) A .xn script is for linking with -n flag (mix text and data on same page). A .xbn script is for linking with -N flag (mix text and data on same page).
