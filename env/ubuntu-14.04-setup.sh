#!/bin/bash

if [[ -z $TRAVIS ]]; then
    sudo apt-get install make python3 python3-pip libpython-dev libffi-dev gawk hidapi python3-pyside
    sudo pip install -U keyplus
fi

avr8_gnu=avr8-gnu-toolchain-3.5.4.1709-linux.any.x86_64.tar.gz
avr8_link=http://ww1.microchip.com/downloads/en/DeviceDoc/$avr8_gnu

wget $avr8_link
tar xvf ${avr8_gnu}
