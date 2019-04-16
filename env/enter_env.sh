#!/bin/bash
# To enter the environment run this command in your shell:
# source ./env/enter_env.sh

if [[ -z $SDCC_VERSION ]]; then
    SDCC_VERSION=9948
fi

# Values used for the virtual environment
avr8_tool_chain=avr8-gnu-toolchain-linux_x86_64
sdcc_tool_chain=sdcc-${SDCC_VERSION}_mcs51

AVR8_PATH="${PWD}/env/$avr8_tool_chain/bin"
SDCC_BIN_PATH="${PWD}/env/$sdcc_tool_chain/bin"
SDCC_PATH="${PWD}/env/$sdcc_tool_chain"

ARM_PATH="${PWD}/env/gcc-arm-none-eabi-7-2018-q2-update/bin/"
NRF52_SDK_PATH="${PWD}/env/nRF5_SDK_15.3.0_59ac345"


# Command to leave the environment
deactivate_env () {
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

    unset AVR8_PATH
    unset SDCC_BIN_PATH
    unset SDCC_PATH
}

# Change the shell command prompt so it is clear we are in the
# alternative environment
_OLD_ENV_PS1="$PS1"
if [ "x" != x ]; then
    PS1="$PS1"
else
    PS1="(keyplus env) $PS1"
fi

# Add the environment variables to the path
_OLD_ENV_PATH="$PATH"
PATH="$AVR8_PATH:$SDCC_BIN_PATH:$PATH"

export PATH
export PS1
export AVR8_PATH
export SDCC_BIN_PATH
export SDCC_PATH

export GNU_INSTALL_ROOT=$ARM_PATH
export GNU_VERSION=7.3.1
export GNU_PREFIX=arm-none-eabi
export NRF52_SDK_ROOT=$NRF52_SDK_PATH

echo "New path: $PATH"
