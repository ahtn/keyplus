#!/bin/bash

# We use record type 0x05 to hold the CHIP ID. The `nrfburn` command can't
# handle this record, so this command strips it from a hex file
sed '/^:04000005/d' $1
