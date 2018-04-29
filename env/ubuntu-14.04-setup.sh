#!/bin/bash

if [[ -z $TRAVIS ]]; then
    sudo apt-get install make python3 python3-pip libpython-dev libffi-dev gawk hidapi python3-pyside
    sudo pip install -U keyplus
fi

avr8_gnu=avr8-gnu-toolchain-3.5.4.1709-linux.any.x86_64.tar.gz
avr8_link=http://ww1.microchip.com/downloads/en/DeviceDoc/$avr8_gnu

sdcc_bz2=sdcc-3.6.0-i386-unknown-linux2.5.tar.bz2
sdcc_dist=https://jaist.dl.sourceforge.net/project/sdcc/sdcc-linux-x86/3.6.0/sdcc-3.6.0-i386-unknown-linux2.5.tar.bz2

wget $avr8_link
tar xvf ${avr8_gnu}

wget $sdcc_dist
tar xvf $sdcc_bz2
