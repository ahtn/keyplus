#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

import math

from keyplus.layout.common import *

class Layout:
    def __init__(self, layout, layout_id, layout_name):
        self.id = layout_id
        self.layers = try_get(layout, "layers", layout_name, val_type=list)
        self.sub_matrix_sizes = []
        self.name = layout_name

        # optional default layer
        if "default_layer" in layout:
            self.default_layer = try_get(layout, "default_layer", layout_name, val_type=int)
        else:
            self.default_layer = 0

        # first determine the layer structure for the keyboard
        try:
            self.layer_count = len(self.layers)
        except:
            raise ParseError("Expected at least one layer in {}".format(layout_name))

        # check for at least one keyboard
        try:
            self.keyboard_count = len(self.layers[0])
        except:
            raise ParseError("Expected at least one keyboard device in 'layers' field of {}".format(layout_name))

        # number of keys in keyboards
        try:
            self.sub_matrix_sizes = [len(kb) for kb in self.layers[0]]
        except:
            raise ParseError("Couldn't get keyboard sizes {}".format(layout_name))

        # check that all the layers have the same dimensions
        for layer_i in range(self.layer_count):
            device_count_i = len(self.layers[layer_i])
            if device_count_i != self.keyboard_count:
                raise ParseError("Unbalanced layer structure in layout '{}'. "
                    " The first layer has '{}' devices, but the {} layer has '{}' devices."
                    .format(layout_name, self.layer_count,
                            num_to_ordinal_str(layer_i+1), device_count_i)
                )
            for device_i in range(self.keyboard_count):
                expected_size = self.sub_matrix_sizes[device_i]
                actual_size = len(self.layers[layer_i][device_i])
                if actual_size != expected_size:
                    raise ParseError("Mismatching devices in layout '{}'. "
                        "The {} device has '{}' keycodes in the first layer, but "
                        "in the {} layer the same device has '{}' keycodes."
                        .format(
                            layout_name,
                            num_to_ordinal_str(device_i+1), expected_size,
                            num_to_ordinal_str(layer_i+1), actual_size
                        )
                    )

        # total matrix size of layout
        self.matrix_size = self.calc_total_matrix_size()

        # which matrix_maps are used (if any) for the layout
        if "matrix_maps" in layout:
            self.matrix_maps = try_get(layout, "matrix_maps", layout_name, val_type=list)
            if len(self.matrix_maps) != self.keyboard_count:
                raise ParseError("In layout '{}', found '{}' maps in 'matrix_maps', "
                        "but found {} devices in its 'layers' list".found(
                        self.name, len(self.matrix_maps), self.keyboard_count))
        else:
            self.matrix_maps = None

    def calc_total_matrix_size(self):
        # total size need for the key matrices in the layout
        matrix_size = 0
        for size in self.sub_matrix_sizes:
            matrix_size += int(math.ceil(size / 8))
        if matrix_size > MAX_MATRIX_SIZE:
            raise ParseError("Too many keys in layout '{}'".format(layout_name))
        return matrix_size

    def check_layers(self, layout, debug_hint, layout_id):
        # check all layers have the same number of keyboards and all
        # keyboards have the same number of keys
        for (l_i, layer) in enumerate(self.layers):
            if len(layer) != self.layer_count:
                raise ParseError("'{}' has a mismatched number of keyboards "
                    "in its layers starting at layer '{}'".format(debug_hint, l_i))
            for (kb_i, kb) in enumerate(layer):
                if len(kb) != self.sub_matrix_sizes[kb_i]:
                    raise ParseError("'{}' has a mismatched number of keys "
                        "starting at keyboard '{}' of layer '{}'".format(debug_hint, kb_i, l_i))

