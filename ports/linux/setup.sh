#!/bin/bash

# Create the `keyplusd` user
useradd keyplusd \
    --comment "keyplus daemon user" \
    --system \
    --home-dir "/" \
    --groups input \
    --shell /sbin/nologin

cp ./etc/udev/rules.d/85-keyplusd.rules -t /etc/udev/rules.d/
