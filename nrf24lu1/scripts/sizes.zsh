#!/bin/bash

function sizes() {
    csum=0
    for i in obj/**/*.sym; do
        csize=`cat $i | \
        grep size | \
        grep $1 | \
        sed -e 's/.*size\s*\([[:xdigit:]]\+\).*/\1/g'`;
        csum=$(($csum + 0x$csize))
        if [[ $((0x$csize)) -ne 0 ]]; then
            echo -e $((0x$csize)) "\t" $i
        fi
    done
    echo -e "="$csum "\t total"
}

xram_size=$((0x800))
function x_sizes() {
    csum_1=0
    csum_2=0
    csum_3=0
    for i in obj/**/*.sym; do
        xseg=`cat $i | grep size | grep XSEG | \
        sed -e 's/.*size\s*\([[:xdigit:]]\+\).*/\1/g'`;
        xiseg=`cat $i | grep size | grep XISEG | \
        sed -e 's/.*size\s*\([[:xdigit:]]\+\).*/\1/g'`;
        xtotal=$((0x$xseg + 0x$xiseg))
        csum_1=$(($csum_1 + $xtotal))
        csum_2=$(($csum_2 + 0x$xseg))
        csum_3=$(($csum_3 + 0x$xiseg))
        if [[ $xtotal -ne 0 ]]; then
            echo -e $(($xtotal)) "\t" $((0x$xseg)) "\t" $((0x$xiseg)) "\t" $i
        fi
    done
    echo -e "="$csum_1 "\t" $csum_2 "\t" $csum_3 "\t total ($(($csum_1*100/$xram_size))% of $xram_size)"
}

echo "=====DSEG====="
echo -e "bytes\thex\tname"
sizes DSEG | sort -nr

echo "=====OSEG====="
echo -e "bytes\thex\tname"
sizes OSEG | sort -nr

echo "=====XSEG====="
echo -e "xram\txseg\txiseg\tname"
x_sizes  | sort -nr

echo "=====CSEG====="
echo -e "bytes\thex\tname"
sizes CSEG | sort -nr
