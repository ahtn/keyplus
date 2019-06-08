#!/bin/bash

if ! id -u keyplusd 2>&1 > /dev/null; then
    # Create the `keyplusd` user
    useradd keyplusd \
        --comment "keyplus daemon user" \
        --system \
        --home-dir "/" \
        --groups input \
        --shell /sbin/nologin
fi

if [ "$1" == "no-install" ]; then
    mkdir -p /usr/local/lib/udev/rules.d/
    cp ./etc/udev/rules.d/85-keyplusd.rules -t /usr/local/lib/udev/rules.d/
fi
