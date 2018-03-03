#!/bin/bash
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

keyplus_cmd=../host-software/keyplus_cli.py
xusb_cmd=./xusb-boot/scripts/bin/xusbboot-cli

if [[ $# -ne 2 ]]; then
    echo "Usage: $0 hex_file"
fi

$keyplus_cmd bootloader -d 6666:1111
sleep 1.5
$xusb_cmd -d 6666:b007 -f $1 -mcu $2
