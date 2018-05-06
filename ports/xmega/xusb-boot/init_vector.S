
.section .init_vector, "ax", @progbits
.global __vector_default
__vector_default:
    jmp __init
