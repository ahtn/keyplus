#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from setuptools import setup

setup(
    name = 'keyplus',
    version = '0.0.3',
    description = "Python library for interfacing with keyplus keyboards.",
    url = "http://github.com/ahtn/keyplus",
    author = "jem",
    author_email = "jem@seethis.link",
    license = 'MIT',
    packages = ['keyplus'],
    install_requires = [
        'hexdump', 'intelhex', 'easyhid', 'pyyaml', 'pyusb', 'cstruct'
    ],
    keywords = ['keyboard', 'usb', 'hid'],
    zip_safe = False
)
