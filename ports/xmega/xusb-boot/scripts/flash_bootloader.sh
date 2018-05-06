#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color
function test_cmd {
    "$@"
    local status=$?
    if [ $status -ne 0 ]; then
        echo -e "${RED}##############################${NC}" >&2
        echo -e "${RED}##########CMD FAILED##########${NC}" >&2
        echo -e "${RED}##############################${NC}" >&2
        echo -e "${RED}error:${NC} command failed to execute $1" >&2
        exit 1
    fi
    return $status
}

make MCU=atxmega32a4u BOARD=keyplus_mini program-fuses || \
    test_cmd make MCU=atxmega32a4u BOARD=keyplus_mini program-fuses

test_cmd make MCU=atxmega32a4u BOARD=keyplus_mini program-hard && \
test_cmd make MCU=atxmega32a4u BOARD=keyplus_mini program-lock

echo -e "${GREEN}######################################${NC}" >&2
echo -e "${GREEN}##########PROGRAM SUCCESSFUL##########${NC}" >&2
echo -e "${GREEN}######################################${NC}" >&2
