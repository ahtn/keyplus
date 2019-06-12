#!/bin/bash

# Create the `keyplusd` user if it doesn't exist already
if ! id -u keyplusd &> /dev/null; then
    useradd keyplusd \
        --comment "keyplus daemon user" \
        --system \
        --home-dir "/" \
        --groups input \
        --shell /sbin/nologin
fi
