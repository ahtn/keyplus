#!/bin/bash

# Test building the documentation
doxygen doc/doxygen/doxygen_config

if [[ -z $1 ]]; then
    xdg-open build/doc/html/index.html
fi
