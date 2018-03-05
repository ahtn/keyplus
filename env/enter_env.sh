#!/bin/bash

avr8_gnu=avr8-gnu-toolchain-linux_x86_64

deactivate () {
    if ! [ -z "${_OLD_ENV_PATH+_}" ]; then
        PATH="$_OLD_ENV_PATH"
        export PATH
        unset _OLD_ENV_PATH
    fi

    if ! [ -z "${_OLD_ENV_PS1+_}" ]; then
        PS1="$_OLD_ENV_PS1"
        export PS1
        unset _OLD_ENV_PS1
    fi

    unset VIRT_ENV
}

VIRT_ENV="${PWD}/env/$avr8_gnu/bin"
export VIRT_ENV

_OLD_ENV_PS1="$PS1"
if [ "x" != x ]; then
    PS1="$PS1"
else
    PS1="(env) $PS1"
fi
export PS1

_OLD_ENV_PATH="$PATH"
PATH="$VIRT_ENV:$PATH"
export PATH

echo "New path: $PATH"
