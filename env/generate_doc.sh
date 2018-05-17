#!/bin/bash

# Test building the documentation
doxygen doc/doxygen/doxygen_config

xdg-open build/doc/html/index.html
