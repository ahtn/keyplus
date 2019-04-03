#!/usr/bin/env bash

# on error, cause the script to exit
set -e

# print commands as they are executed and expand variables
set -x

# SDCC can be pretty buggy from release to release,
# so often need to compile from source to get things to
# work well.
#
# This script shows how to compile a static binary that can be used for travis
# or local builds

rev=9948
target_dir=sdcc-${rev}_mcs51
target_host=x86_64-linux
target_archive=sdcc-${rev}-mcs51-${target_host}.tar.gz
base_dir=../..

svn co -r${rev}  https://svn.code.sf.net/p/sdcc/code/trunk sdcc-code

cd sdcc-code/sdcc

./configure \
  --prefix=/ \
  --disable-z80-port \
  --disable-z180-port \
  --disable-r2k-port \
  --disable-r3ka-port \
  --disable-gbz80-port \
  --disable-tlcs90-port \
  --disable-ds390-port \
  --disable-ds400-port \
  --disable-pic14-port \
  --disable-pic16-port \
  --disable-hc08-port \
  --disable-s08-port \
  --disable-stm8-port \
  --disable-ucsim \
  --disable-sdcdb \
  --disable-non-free \
  CFLAGS=-static \
  LDFLAGS=-static \


make
mkdir -p $target_dir
make install DESTDIR=$PWD/$target_dir/

pwd

tar czf $target_archive $target_dir

cp -r $target_dir $base_dir
cp $target_archive $base_dir

cd $base_dir
