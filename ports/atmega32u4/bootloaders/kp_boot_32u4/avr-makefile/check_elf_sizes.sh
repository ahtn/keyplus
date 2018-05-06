#!/bin/bash

if [[ $# != 2 ]]; then
    echo "Usage: $0 elf_file section"
    echo "Example: $0 main.elf .bss"
fi

elf_file=$1
section=$2

avr-nm ${elf_file} -f sysv | grep "${section}$" | column -s '|' -t | sort -k 5,5
