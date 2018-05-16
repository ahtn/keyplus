#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from setuptools import setup, find_packages
import os

# Load the version number
try: # python3
    fields = {}
    with open(os.path.join("keyplus", "version.py")) as f:
        exec(f.read(), fields)
    __version__ = fields['__version__']
except: # python2
    execfile(os.path.join("keyplus", "version.py"))

setup(
    name = 'keyplus',
    version = __version__,
    description = "Python library for interfacing with keyplus keyboards.",
    url = "http://github.com/ahtn/keyplus",
    author = "jem",
    author_email = "jem@seethis.link",
    license = 'MIT',
    packages = find_packages(include=['keyplus', 'keyplus.*']),
    install_requires = [
        'future', 'six', 'cstruct', 'enum-compat', 'hexdump', 'intelhex',
        'ruamel.yaml', 'pyusb', 'colorama',
        # Closely related
        'easyhid>=0.0.9',
        'xusbboot>=0.0.2',
        'efm8boot>=0.0.7',
        'kp_boot_32u4>=0.0.2',
        'kle>=0.0.5',
    ],
    keywords = ['keyboard', 'usb', 'hid'],
    scripts = ['keyplus-cli'],
    zip_safe = False,
)
