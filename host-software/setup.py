#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from setuptools import setup
import os
import six

with open(os.path.join("keyplus", "version.py")) as f:
    six.exec_(f.read())

setup(
    name = 'keyplus',
    version = __version__,
    description = "Python library for interfacing with keyplus keyboards.",
    url = "http://github.com/ahtn/keyplus",
    author = "jem",
    author_email = "jem@seethis.link",
    license = 'MIT',
    packages = ['keyplus'],
    install_requires = [
        'hexdump', 'intelhex', 'easyhid', 'pyyaml', 'pyusb',
        'cstruct', 'kle', 'six'
    ],
    keywords = ['keyboard', 'usb', 'hid'],
    zip_safe = False
)
