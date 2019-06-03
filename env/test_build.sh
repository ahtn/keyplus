#!/bin/bash

# on error, cause the script to exit
set -e

# load version number into __version__ as a bash variable
source ./host-software/keyplus/version.py

# get the current git hash
keyplus_git_hash=$(git rev-parse --short=7 HEAD)

layout_dir=../../layouts

export MAKEFLAGS="-j 4"

# print build and git hash of current
echo
echo -e "#########################################"
echo -e "# Starting Test build ${__version__}-${keyplus_git_hash}\t#"
echo -e "#########################################"
echo

cd ports/xmega
  echo "###########"
  echo "#  xmega  #"
  echo "###########"
  make MCU=atxmega32a4u ID=12 BOARD=keyplus_mini LAYOUT_FILE=$layout_dir/small_split_test.yaml
  make MCU=atxmega128a4u ID=14 BOARD=alpha_split LAYOUT_FILE=$layout_dir/basic_split_test.yaml
  make MCU=atxmega64c3 LAYOUT_FILE=$layout_dir/spectre.yaml BOARD=plain
cd ../..

cd ports/atmega32u4
  echo "################"
  echo "#  atmega32u4  #"
  echo "################"
  make MCU=atmega32u4 BOARD=default LAYOUT_FILE=$layout_dir/1key.yaml
  make MCU=atmega32u4 BOARD=atmel-dfu LAYOUT_FILE=$layout_dir/32u4_test.yaml
cd ../..

cd ports/nrf24lu1
  echo
  echo "##############"
  echo "#  nrf24LU1  #"
  echo "##############"
  echo
  make BOARD=512_bootloader ID=48 LAYOUT_FILE=$layout_dir/basic_split_test.yaml
  make BOARD=unirecv ID=48 LAYOUT_FILE=$layout_dir/basic_split_test.yaml
cd ../..

cd ports/efm8
  echo
  echo "##########"
  echo "#  efm8  #"
  echo "##########"
  echo
  make BOARD=default LAYOUT_FILE=$layout_dir/efm8_4x6.yaml
  make BOARD=efm8ub30_qfn20 LAYOUT_FILE=$layout_dir/efm8_4x6.yaml
cd ../..

cd ports/nrf52
  echo
  echo "###########"
  echo "#  nrf52  #"
  echo "###########"
  echo
  make BOARD=nrf52840_dk LAYOUT_FILE=$layout_dir/nrf52_4key.yaml ID=0
  make BOARD=nrf52840_dongle LAYOUT_FILE=$layout_dir/basic_split_test.yaml ID=21
  make BOARD=nrf52840_dk_ble hex
cd ../..

cd ports/linux
  echo
  echo "###########"
  echo "#  linux  #"
  echo "###########"
  echo
  make
cd ../..
