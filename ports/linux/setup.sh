#!/bin/bash

# The user and group ID
_id=394

# Create the `keyplusd` user if it doesn't exist already
if ! id -u keyplusd &> /dev/null; then
    groupadd -g $_id keyplusd
    useradd keyplusd \
        --comment "keyplus daemon user" \
        --system \
        --home-dir "/" \
        --shell /sbin/nologin \
        --groups input \
        --uid $_id \
        --gid $_id
fi
