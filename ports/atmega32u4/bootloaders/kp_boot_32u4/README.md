
# kp_boot_32u4 USB HID bootloader for ATmega32u4 family of microcontrollers

A simple bootloader for the ATmega32u4 family of USB microcontrollers.
The code size is <1kB and doesn't need drivers on Windows.
Supports writing flash, eeprom, and lock bits.

It also exposes an `SPM` interface allowing firmware to write its own flash.

## CLI interface

List the currently connected devices:
```sh
./kp_boot_32u4_cli.py -l
```

Program a firmware hex file:
```sh
./kp_boot_32u4_cli.py -f program.hex
```

Program an eeprom hex file:
```sh
./kp_boot_32u4_cli.py -E eeprom.hex
```

## GUI interface

You can also use the [keyplus](https://github.com/ahtn/keyplus) flasher to
wire firmware hex files.

You can [download the flasher here.](https://github.com/ahtn/keyplus/releases)

![keyplus gui](https://rawgit.com/ahtn/kp_boot_32u4/master/img/keyplus_gui.png)

## Convert a Arduino Pro Micro to use the bootloader (without an ISP programmer)

Since the Pro Micro doesn't set the lock bits on the bootloader section, it's
possible to update its bootloader without an ISP programmer by loading a
special program onto it using its current bootloader.

[Here's an Arduino script
](https://github.com/ahtn/avr-bootloader-upgrade/blob/master/promicro_to_keyplus.ino)
that will replace the Pro Micro `Caterina` bootloader with the `kp_boot_32u4`
bootloader. Simply flash this script to a Pro Micro using the Arduino IDE and
the bootloader will be replaced. When the bootloader has been replaced
successfully, the left LED on the Pro Micro will light up. Then the next time
the Pro Micro is restarted, the device will enter the new bootloader.
See the [Sparkfun page on how to setup the
Arduino IDE and program the Pro Micro](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide#windows_driver).

Although the bootloader only needs 1kb of flash, using this technique it will
still take up 4kb of flash space since the size of the bootloader cannot be
change using this technique. Changing the size of the bootloader to 1kb still
requires an external programmer.

## Program bootloader with ISP

### Build the bootloader

```
git submodule update --init --recursive
make
```

### Flash the bootloader with ISP programmer

By default the makefile is configured to use a USBasp programmer.  If you have
one of these, you should then be able to flash the bootloader by running:

```
make program-fuses
make program-hard
make program-lock
```

If you want to use a different programmer, look for the `programmer options`
section in the makefile and reconfigure the avrdude command for use with
your ISP progammer. You should then be able to run the above commands to
flash the bootloader.

The bootloader should now be ready to use, with either the CLI or GUI.

## Enter bootloader
Ways to enter the bootloader:

* 1. Push the reset button (short RST pin to GND) once. The device will then
  stay in bootloader mode until a firmware hex file is loaded, or the reset
  button is pushed a second time.
* 2. The firmware can enter the bootloader by setting a magic value and causing
  wdt reset. The bootloader will check for the value `0xda54` at the SRAM
  address `0x01fc`. If the value matches `0xda54` then the bootloader will be
  run, other values at the address `0x01fc` will cause the code to jmp to
  the application section.

## SPM interface

The bootloader has an SPM instruction with the appropriate support code to
allow firmware to update its own flash. The interface is always stored in
the last 16 bytes of flash at address. The `interface` directory provides
c functions to interface with the bootloader.


The code stored in the last 16 bytes corresponds to this assembly.

```asm
; ---
; Performs an SPM command and waits for it to finish executing.
;
; Input:
;
; * r0:r1: optional data value used by SPM command
; * Z[r30:r31]: address used by SPM command
; * r10: spm command loaded into SPMCSR register
; * r11: spm command loaded into SPMCSR register. It should be used
;        to re-enable the RWW enable section after flash erase/write
;        operations by setting it equal to `(1<<SPMEN) | (1<<RWWSRE)`.
;        When writing to the temporary page buffer, it should be set
;        to 0 to perform no action.
;
; Returns:
;     Nothing.
; ---

call_spm:
	out	IO_(SPMCSR), r10	; r18 decides function
	spm				; Store program memory

wait1:  in	r10, IO_(SPMCSR)	; get SPMCR into r18
	sbrc	r10, SPMEN
	rjmp	wait1			; Wait for SPMEN flag cleared

	out	IO_(SPMCSR), r11
	spm

	ret
```

## License

MIT Licensed.
