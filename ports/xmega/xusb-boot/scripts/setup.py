#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from setuptools import setup
import os

# Load the version number
try: # python3
    fields = {}
    with open(os.path.join("xusbboot", "version.py")) as f:
        exec(f.read(), fields)
    __version__ = fields['__version__']
except: # python2
    execfile(os.path.join("xusbboot", "version.py"))

setup(
    name = 'xusbboot',
    version = '0.0.2',
    description = "Python library for xmega xusb bootloader",
    url = "http://github.com/ahtn/xusb-boot",
    author = "jem",
    author_email = "jem@seethis.link",
    license = 'MIT',
    packages = ['xusbboot'],
    install_requires = ['hexdump', 'intelhex', 'easyhid'],
    keywords = ['xmega', 'usb', 'hid', 'avr', 'bootloader'],
    scripts = ['bin/xusbboot-cli'],
    zip_safe = False
)
