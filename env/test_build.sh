#!/bin/bash

# on error, cause the script to exit
set -e

cd xmega
  echo "###########"
  echo "#  xmega  #"
  echo "###########"
  make MCU=atxmega32a4u ID=0 BOARD=keyplus_mini
  make MCU=atxmega128a4u ID=14 BOARD=alpha_split
  make MCU=atxmega64c3 LAYOUT_FILE=../layouts/spectre.yaml BOARD=plain
cd ..

cd atmega32u4
  echo "################"
  echo "#  atmega32u4  #"
  echo "################"
  make MCU=atmega32u4 BOARD=default LAYOUT_FILE=../layouts/1key.yaml
  make MCU=atmega32u4 BOARD=atmel-dfu LAYOUT_FILE=../layouts/32u4_test.yaml
cd ..

# TODO: building nrf24 doesn't work on travis
cd nrf24lu1
  echo "##############"
  echo "#  nrf24LU1  #"
  echo "##############"
  make BOARD=default ID=48 LAYOUT_FILE=../layouts/basic_split_test.yaml
  make BOARD=unirecv ID=48 LAYOUT_FILE=../layouts/basic_split_test.yaml
cd ..

# TODO: building nrf24 doesn't work on travis
cd efm8
  echo "##########"
  echo "#  efm8  #"
  echo "##########"
  make BOARD=default
  make BOARD=efm8ub10_qfn20
cd ..
