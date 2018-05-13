#!/bin/bash
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

cmd=""
tmp_file=`mktemp`
tmp_file2=`mktemp`
for i in 0 1 2 4 5; do
    # cmd="$cmd -U fuse$i:r:$tmp_file:h"
    cmd="-U fuse$i:r:$tmp_file:h"
    avrdude-pdi -C ~/local/etc/avrdude-pdi.conf -c usbasp -p x32a4 $cmd
    echo -n "FUSE$i=" >> $tmp_file2
    cat $tmp_file >> $tmp_file2
done
cat $tmp_file2
