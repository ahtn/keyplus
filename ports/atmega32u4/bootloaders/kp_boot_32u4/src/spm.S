#include <avr/io.h>

#define IO_(x)  _SFR_IO_ADDR(x)

#define SPMEN_bm 0x01
#define PGERS_bm 0x02
#define PGWRT_bm 0x04
#define BLBSET_bm 0x08
#define RWWSRE_bm 0x10
#define SIGRD_bm 0x20
#define RWWSB_bm 0x40
#define SPMIE_bm 0x80

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

.section .boot_extra,"ax",@progbits
.global call_spm

call_spm:
	out	IO_(SPMCSR), r10	; r18 decides function
	spm				; Store program memory

wait1:  in	r10, IO_(SPMCSR)	; get SPMCR into r18
	sbrc	r10, SPMEN
	rjmp	wait1			; Wait for SPMEN flag cleared

	out	IO_(SPMCSR), r11
	spm

finspm:
	ret
