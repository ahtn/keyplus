#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from setuptools import setup

setup(
    name = 'nrf24lu1_boot',
    version = '0.0.0',
    description = "Python library for controlling the nrf24lu1p-512-bootloader.",
    url = "https://github.com/ahtn/nrf24lu1p-512-bootloader",
    author = "jem",
    author_email = "jem@seethis.link",
    license = 'MIT',
    packages = ['nrf24lu1_boot'],
    install_requires = ['easyhid', 'intelhex', 'pyusb'],
    keywords = ['nrf24lu1+', 'usb', 'hid', 'bootloader'],
    zip_safe = False
)
