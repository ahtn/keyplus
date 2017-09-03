#!/bin/bash
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

if [[ $# -ne 1 ]]; then
    echo "usage: $0 fuses.hex"
fi

file=$1
bytes=$(grep ":060020" $file)
for i in 0 1 2 4 5; do
    b0=$(($i*2+10))
    b1=$(($i*2+11))
    fusex=$(echo $bytes | cut -c $b0-$b1 )
    echo FUSE${i}=${fusex}
done
