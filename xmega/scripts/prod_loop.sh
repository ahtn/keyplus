#!/bin/bash

function count_down() {
    iter=$1
    while (( $iter > 0)); do
        echo $iter
        iter=$(( $iter - 1 ))
        sleep 1
    done
    echo 0
}

while true; do
    scripts/prod_flash.sh
    count_down 1
done
