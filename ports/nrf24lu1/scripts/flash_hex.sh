#!/bin/bash
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

if [[ $# -ne 1 && $# -ne 2 ]]; then
    echo "Usage: $0 hex_file"
fi

../host-software/keyplus_cli.py bootloader -d 6666:3333
sleep 1.0
./nrf24lu1p-512-bootloader/scripts/flash.py write_hex $1
