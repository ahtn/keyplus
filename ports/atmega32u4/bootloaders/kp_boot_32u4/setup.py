#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from setuptools import setup
import os

app_name = 'kp_boot_32u4'

# Load the version number
try: # python3
    fields = {}
    with open(os.path.join(app_name, "version.py")) as f:
        exec(f.read(), fields)
    __version__ = fields['__version__']
except: # python2
    execfile(os.path.join(app_name, "version.py"))

setup(
    name = app_name,
    version = __version__,
    description = "Python library for kp_boot_32u4 AVR USB bootloader",
    url = "http://github.com/ahtn/kp_boot_32u4",
    author = "jem",
    author_email = "jem@seethis.link",
    license = 'MIT',
    packages = [app_name],
    install_requires = ['hexdump', 'intelhex', 'easyhid'],
    keywords = ['usb', 'hid', 'avr', 'atmega32u4', 'bootloader'],
    scripts = ['kp_boot_32u4_cli.py'],
    zip_safe = False
)
