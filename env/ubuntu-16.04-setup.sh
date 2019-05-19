#!/bin/bash

# on error, cause the script to exit
set -e

git submodule update --init --recursive

TARFLAGS="xvf"
UNZIPFLAGS=""

# Setup Ubuntu 16.04 dependencies
if [[ -z $TRAVIS ]]; then
    sudo apt-get install -y make python3 python3-pip libpython-dev libffi-dev gawk libhidapi-dev python3-pyqt5
else
    # Reduce log output for travis
    TARFLAGS="xf"
    UNZIPFLAGS="-q"
fi

# load version number into __version__ as a bash variable
source ../host-software/keyplus/version.py

#######################################################################
#                          Python libraries                           #
#######################################################################

if [[ $TRAVIS ]]; then
    pip3 install --user -U setuptools
fi

# Install the latest version. Use pre_release branch if checked out from master
if [[ $(echo "$__version__" | grep pre) ]]; then
    pip3 install --user -U --pre keyplus
else
    pip3 install --user -U "keyplus==${__version__}"
fi

#######################################################################
#                           AVR8 toolchain                            #
#######################################################################


avr8_folder=avr8-gnu-toolchain-linux_x86_64
avr8_gnu=avr8-gnu-toolchain-3.6.2.1759-linux.any.x86_64.tar.gz
avr8_link=http://ww1.microchip.com/downloads/en/DeviceDoc/$avr8_gnu

wget $avr8_link
tar $TARFLAGS ${avr8_gnu}


#######################################################################
#                        SDCC MCS51 toolchain                         #
#######################################################################

if [[ -z $SDCC_VERSION ]]; then
    # This version has compiler error on the keyplus code base
    # SDCC_VERSION=3.8.0

    # This version produces larger code for bool (think in handling booleans)
    # SDCC_VERSION=3.7.0

    # This version produces smaller code than 3.7.0
    SDCC_VERSION=9948
fi

# Version 3.7.0
# sdcc_tar=sdcc-${SDCC_VERSION}-mcs51-x86_64-linux.tar.gz
# sdcc_dist=https://github.com/ahtn/efm8_sdcc/releases/download/sdcc/$sdcc_tar

# Version 3.8.0 sourceforge release
# sdcc_tar=sdcc-3.8.0-amd64-unknown-linux2.5.tar.bz2
# sdcc_dist=https://sourceforge.net/projects/sdcc/files/sdcc-linux-amd64/3.8.0/sdcc-3.8.0-amd64-unknown-linux2.5.tar.bz2/download

# Version svn-#9948
sdcc_tar=sdcc-${SDCC_VERSION}-mcs51-x86_64-linux.tar.gz
sdcc_dist=https://github.com/ahtn/efm8_sdcc/releases/download/sdcc/$sdcc_tar

wget $sdcc_dist -O $sdcc_tar
tar $TARFLAGS $sdcc_tar

#######################################################################
#                      NRF52/ARM Toolchain                            #
#######################################################################

armgcc_tar=gcc-arm-none-eabi-7-2018-q2-update-linux.tar.bz2
armgcc_link=https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/7-2018q2/$armgcc_tar

wget $armgcc_link
tar $TARFLAGS $armgcc_tar

nrf5_sdk_zip=nRF5SDK153059ac345.zip
nrf5_sdk_link=https://www.nordicsemi.com/-/media/Software-and-other-downloads/SDKs/nRF5/Binaries/$nrf5_sdk_zip

wget $nrf5_sdk_link
unzip $UNZIPFLAGS $nrf5_sdk_zip
