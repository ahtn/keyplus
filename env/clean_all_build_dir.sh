#!/bin/bash

TARGETS="atmega32u4 xmega nrf24lu1 efm8"

for target in $TARGETS; do
    rm -fr ports/$target/build
done
