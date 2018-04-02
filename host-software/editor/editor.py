#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

# # PyQt <-> PySide signal compatability
# from PyQt5.QtCore import pyqtSlot, pyqtSignal
# Signal = pyqtSignal
# Slot = pyqtSlot
# from PyQt5.QtWidgets import (

from PySide.QtCore import QSize, Qt, QRectF, QPointF, QPoint, QLine, QObject, \
    QTimer
from PySide.QtGui import QPainter, QBrush, QPainterPath, QFont, QFontMetrics, \
    QColor, QPen, QTransform, QPolygonF
from PySide.QtGui import QApplication, QWidget, QComboBox, QVBoxLayout, \
    QGraphicsItem, QGraphicsScene, QGraphicsView

from PySide.QtCore import Slot, Signal

import os
import json
import kle

import key_widgets

class Window(QWidget):

    def __init__(self):
        super(Window, self).__init__()

        self.inputType = QComboBox()

        # layout of the widgets in the window
        self.layout = QVBoxLayout()
        self.layout.addWidget(self.inputType)
        self.key_size = key_widgets.DEFAULT_KEY_SIZE

        self.setLayout(self.layout)

        self.resize(1600, 900)

        self.scene = key_widgets.KeyboardEditorScene(
            -200, -200, 1000, 600,
            key_size = self.key_size
        )

        keyFont = self.font()
        keyFont.setPixelSize(20)

        self.view = key_widgets.GraphicsView(self.scene)
        self.view.setRenderHint(QPainter.Antialiasing)
        self.view.setViewportUpdateMode(QGraphicsView.BoundingRectViewportUpdate)
        self.view.setBackgroundBrush(QColor(0xFF, 0xFF, 0xFF))
        self.view.setFont(keyFont)

        test_items = [
            ("dox-left",  os.path.join("layouts", "dox-left.json")),
            ("dox-right", os.path.join("layouts", "dox-right.json")),
            ("60%", os.path.join("layouts", "60-percent.json")),
            ("jemini-v5", os.path.join("layouts", "jemini-v5.json")),
            ("ortho-left",  os.path.join("layouts", "ortho_4x6.json")),
            ("ortho-right", os.path.join("layouts", "ortho_4x6.json")),
        ]

        self.test_objs = [
            key_widgets.KeyboardDeviceWidget.from_file(
                kb[1],
                kb[0],
                key_size=self.key_size
            ) for kb in test_items
        ]

        print(test_items)
        print(self.test_objs)

        for kb in self.test_objs:
            self.scene.addItem(kb)

        self.refreshEvent = QTimer()
        self.refreshEvent.setInterval(33)
        # self.refreshEvent.timeout.connect(self.USBUpdate)
        self.refreshEvent.start()



        # make a view port for the scene
        self.view.show()

        self.layout.addWidget(self.view)

if __name__ == '__main__':
    import sys

    app = QApplication(sys.argv)
    window = Window()
    window.show()
    sys.exit(app.exec_())
