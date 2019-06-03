#!/bin/bash

# Create the `keyplusd` user
useradd keyplusd \
    --comment "keyplus daemon user" \
    --system \
    --home-dir "/" \
    --groups input \
    --shell /sbin/nologin

# grant keyplusd permission to access /dev/uinput

# NOTE: this command only lasts until reboot, since the /dev/uinput device is
# recreated at boot time. Need to use a udev rule to set this automatically
# at boot.
setfacl -m u:keyplusd:rw /dev/uinput

cp ./etc/udev/rules.d/85-keyplusd.rules -t /etc/udev/rules.d/
