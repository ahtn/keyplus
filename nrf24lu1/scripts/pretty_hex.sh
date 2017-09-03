#!/bin/bash
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

if [[ $# -ne 1 ]]; then
    echo "no hexfile given"
    exit 1
fi


target_file="$(basename -s ".hex" $1)-pretty.hex"
hex2bin.py $1 | bin2hex.py - > "$target_file"
