#!/bin/bash

# on error, cause the script to exit
set -e

git submodule update --init --recursive

# Setup Ubuntu 14.04 dependencies
if [[ -z $TRAVIS ]]; then
    sudo apt-get install make python3 python3-pip libpython-dev libffi-dev gawk hidapi python3-pyside
fi

# load version number into __version__ as a bash variable
source ../host-software/keyplus/version.py

# Install the latest version. Use pre_release branch if checked out from master
if [[ $(echo "$__version__" | grep pre) ]]; then
    pip3 install --user -U --pre keyplus
else
    if [[ $TRAVIS ]]; then
        pip3 install --user -U setuptools
    fi
    pip3 install --user -U "keyplus==${__version__}"
fi

#
# AVR8 tool chain
#
avr8_folder=avr8-gnu-toolchain-linux_x86_64
avr8_gnu=avr8-gnu-toolchain-3.5.4.1709-linux.any.x86_64.tar.gz
avr8_link=http://ww1.microchip.com/downloads/en/DeviceDoc/$avr8_gnu
avr8_headers=http://distribute.atmel.no/tools/opensource/Atmel-AVR-GNU-Toolchain/3.6.1/avr8-headers.zip

wget $avr8_link
tar xvf ${avr8_gnu}
wget $avr8_headers
unzip avr8-headers.zip
cp avr/* -t $avr8_folder/avr/include/avr

#
# SDCC mcs51 tool chain
#
if [[ -z $SDCC_VERSION ]]; then
    SDCC_VERSION=3.7.0
fi

sdcc_tar=sdcc-${SDCC_VERSION}-mcs51-x86_64-linux.tar.gz
sdcc_dist=https://github.com/ahtn/efm8_sdcc/releases/download/sdcc/$sdcc_tar

wget $sdcc_dist
tar xvf $sdcc_tar
