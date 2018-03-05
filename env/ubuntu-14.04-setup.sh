#!/bin/bash

if [[ $TRAVIS ]]; then
    apt-get install make python python-virtualenv libpython-dev libffi-dev gawk
fi

avr8_gnu=avr8-gnu-toolchain-3.5.4.1709-linux.any.x86_64.tar.gz
avr8_link=http://ww1.microchip.com/downloads/en/DeviceDoc/$avr8_gnu

wget $avr8_link
tar xvf ${avr8_gnu}
pip install hexdump intelhex easyhid pyyaml pyusb cstruct kle \
    six colorama xusbboot cffi future
