#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

if 1:
    # PyQt <-> PySide signal compatability
    from PyQt5.QtCore import pyqtSlot, pyqtSignal
    Signal = pyqtSignal
    Slot = pyqtSlot

    # TODO: narrow down imports
    from PyQt5.QtWidgets import *
    from PyQt5.QtGui import *
    from PyQt5.QtCore import *
    from PyQt5.QtCore import *

    # from PyQt5.QtWidgets import (
    #     QMainWindow, QTextEdit, QAction, QApplication, QPushButton, QProgressBar,
    #     QWidget, QVBoxLayout, QLabel, QHBoxLayout, QLineEdit, QGroupBox,
    #     QFormLayout, QScrollArea, QSizePolicy, QGridLayout, QComboBox,
    #     QStackedLayout, QMessageBox, QFileDialog, QErrorMessage, QTableView,
    #     QFont, QDialog, QTabWidget
    # )
    # from PyQt5.QtGui import QIcon, QIntValidator
    # from PyQt5.QtCore import Qt, QBasicTimer, QSize , QFileInfo, QTimer
    # from PyQt5.QtCore import Slot, Signal, QAbstractTableModel

if 0:
    from PySide.QtGui import (
        QMainWindow, QTextEdit, QAction, QApplication, QPushButton, QProgressBar,
        QWidget, QVBoxLayout, QLabel, QHBoxLayout, QLineEdit, QGroupBox,
        QFormLayout, QScrollArea, QSizePolicy, QGridLayout, QComboBox,
        QStackedLayout, QMessageBox, QFileDialog, QErrorMessage, QTableView,
        QFont, QDialog, QTabWidget
    )
    from PySide.QtGui import QIcon, QIntValidator
    from PySide.QtCore import Qt, QBasicTimer, QSize , QFileInfo, QTimer
    from PySide.QtCore import Slot, Signal, QAbstractTableModel

from keyplus.layout import KeyplusLayout
from keyplus.layout.parser_info import KeyplusParserInfo
from keyplus.layout.rf_settings import LayoutRFSettings
from keyplus.device_info import KeyboardDeviceTarget, KeyboardFirmwareInfo
from keyplus import chip_id
from keyplus import KeyplusKeyboard
from keyplus.exceptions import *
from keyplus.debug import DEBUG
import keyplus.usb_ids
from keyplus.usb_ids import BootloaderType

# TODO: clean up directory structure
import sys
import traceback
import datetime, time, binascii
import ruamel.yaml as yaml
import colorama
import hexdump
import copy

import easyhid
import xusbboot
import efm8boot
import kp_boot_32u4

STATUS_BAR_TIMEOUT=4500

if DEBUG.gui:
    # debug settings

    # DEFAULT_LAYOUT_FILE = "../layouts/basic_split_test.yaml"
    # DEFAULT_RF_FILE = ""
    # DEFAULT_FIRMWARE_FILE = ""
    # DEFAULT_DEVICE_ID = 0

    DEFAULT_LAYOUT_FILE = "../layouts/basic_split_test.yaml"
    DEFAULT_RF_FILE = "../host-software/_ignore_rf_settings.yaml"
    DEFAULT_FIRMWARE_FILE = ""
    DEFAULT_DEVICE_ID = 20

    # EFM8 testing
    # DEFAULT_LAYOUT_FILE = "../layouts/efm8_1key.yaml"
    # DEFAULT_RF_FILE = "../layouts/test_rf_config.yaml"
    # DEFAULT_FIRMWARE_FILE = "../ports/efm8/build/default/usb_keyboard-default.hex"
    # DEFAULT_DEVICE_ID = 0
else:
    DEFAULT_LAYOUT_FILE = ""
    DEFAULT_RF_FILE = ""
    DEFAULT_FIRMWARE_FILE = ""
    DEFAULT_DEVICE_ID = ''

class KeyplusFlasherError(Exception):
    pass

def error_msg_box(msg, title="Error"):
    errorBox = QMessageBox()
    errorBox.setWindowTitle(title)
    errorBox.setText(msg)
    errorBox.exec_()

def msg_box(description="", title="Message"):
    msgBox = QMessageBox()
    msgBox.setWindowTitle(title)
    msgBox.setText(description)
    msgBox.exec_()

def is_keyplus_device(device):
    intf_num = device.interface_number
    prot_ver = device.release_number & 0xf000

    if (prot_ver, intf_num) not in [
        (0x0000, TYPE0_INTERFACE_VENDOR),
        (0x1000, TYPE1_INTERFACE_VENDOR),
    ]:
        return False

    usb_id = (device.vendor_id, device.product_id)
    if (
        usb_id in keyplus.usb_ids.KEYPLUS_USB_IDS or
        usb_id in [(0x6666, 0x1111*i) for i in range(16)]
    ):
        return True

def get_boot_loader_type(device):
    usb_id = (device.vendor_id, device.product_id)
    info = keyplus.usb_ids.BOOTLOADER_USB_IDS.get(usb_id)
    if info == None:
        return None
    return info.bootloader

def is_xusb_bootloader_device(device):
    return get_boot_loader_type(device) == BootloaderType.XUSB_BOOT

def is_kp_boot_device(device):
    return get_boot_loader_type(device) == BootloaderType.KP_BOOT_32U4

def is_nrf24lu1p_bootloader_device(device):
    return get_boot_loader_type(device) == BootloaderType.NRF24LU1P_FACTORY

def is_efm8_boot_device(device):
    return get_boot_loader_type(device) == BootloaderType.EFM8_BOOT

def is_unifying_bootloader_device(device):
    return False

def is_supported_device(device):
    return is_keyplus_device(device) or is_bootloader_device(device)

def is_bootloader_device(device):
    return keyplus.usb_ids.is_bootloader_usb_id(device.vendor_id, device.product_id)

class DeviceWidget(QGroupBox):

    PROGRAM_SIGNAL = 0
    INFO_SIGNAL = 1

    program = Signal(str)
    show_info = Signal(str)
    reset = Signal(str)

    def __init__(self, device):
        super(DeviceWidget, self).__init__(None)

        self.device = device
        self.has_critical_error = False
        self.label = QLabel()

        self.initUI()

    def tryOpenDevice(self, device):
        try:
            return KeyplusKeyboard(device)
        except Exception as err:
            return None

    # label for generic keyplus device
    def setup_keyplus_label(self):
        kb = self.tryOpenDevice(self.device)
        if kb == None:
            self.label = None
            return
            # raise KeyplusUSBCommandError()

        with kb:
            settingsInfo = kb.get_device_info()
            firmwareInfo = kb.get_firmware_info()
            errorInfo = kb.get_error_info()
            self.has_critical_error = errorInfo.has_critical_error()

        if settingsInfo.crc == settingsInfo.compute_crc():
            build_time_str = str(settingsInfo.get_timestamp())
            device_name = settingsInfo.get_device_name()

            self.label.setText('{} | {} | Firmware v{}.{}.{}\n'
                                'Device id: {}\n'
                                'Serial number: {}\n'
                                'Last time updated: {}'
                .format(
                    self.device.manufacturer_string,
                    device_name,
                    firmwareInfo.version_major,
                    firmwareInfo.version_minor,
                    firmwareInfo.version_patch,
                    settingsInfo.device_id,
                    self.device.serial_number,
                    build_time_str
                )
            )
        else:
            # CRC doesn't match
            if settingsInfo.is_empty:
                self.label.setText('{} | {} | Firmware v{}.{}.{}\n'
                                    'Warning: Empty settings!\n'
                                    'Serial number: {}\n'
                    .format(
                        self.device.manufacturer_string,
                        self.device.product_string,
                        firmwareInfo.version_major,
                        firmwareInfo.version_minor,
                        firmwareInfo.version_patch,
                        self.device.serial_number,
                    )
                )
            else:
                # corrupt settings in the flash
                build_time_str = str(settingsInfo.get_timestamp())
                self.label.setText('{} | {} | Firmware v{}.{}.{}\n'
                                    'WARNING: Settings are uninitialized\n'
                                    'Serial number: {}\n'
                    .format(
                        self.device.manufacturer_string,
                        self.device.product_string,
                        firmwareInfo.version_major,
                        firmwareInfo.version_minor,
                        firmwareInfo.version_patch,
                        self.device.serial_number,
                    )
                )

    # xusb_boot bootloader device
    def setup_xusb_bootloader_label(self):
        try:
            self.device.open()
            bootloader_info = xusbboot.get_boot_info(self.device)
        except easyhid.HIDException as err:
            # Incase opening the device fails
            raise KeyplusFlasherError ("Error Opening Device: {} | {}:{}"
                    .format(
                        self.device.path,
                        self.device.vendor_id,
                        self.device.product_id
                    ),
            )

        self.label.setText('{} | {} | Bootloader v{}.{}\n'
                            'MCU: {}\n'
                            'Flash size: {}\n'
                            'Serial number: {}\n'
            .format(
                self.device.manufacturer_string,
                self.device.product_string,
                bootloader_info.version_major,
                bootloader_info.version_minor,
                bootloader_info.mcu_string,
                bootloader_info.flash_size,
                self.device.serial_number
            )
        )

    def setup_kp_boot_32u4_label(self):
        try:
            boot_dev = kp_boot_32u4.BootloaderDevice(self.device)
        except easyhid.HIDException as err:
            # Incase opening the device fails
            raise KeyplusFlasherError ("Error Opening Device: {} | {}:{}"
                    .format(
                        self.device.path,
                        self.device.vendor_id,
                        self.device.product_id
                    ),
            )

        self.label.setText('kp_boot_32u4 - v{}\n'
                            'MCU: {}\n'
                            'Flash size: {}    EEPROM size: {}\n'
                            'Bootloader size: {}\n'
            .format(
                boot_dev.version,
                boot_dev.chip_name,
                boot_dev.flash_size,
                boot_dev.eeprom_size,
                boot_dev.boot_size,
            )
        )

    def setup_efm8_boot_label(self):
        try:
            boot_dev = efm8boot.EFM8BootloaderHID(self.device)
        except easyhid.HIDException as err:
            # Incase opening the device fails
            raise KeyplusFlasherError ("Error Opening Device: {} | {}:{}"
                    .format(
                        self.device.path,
                        self.device.vendor_id,
                        self.device.product_id
                    ),
            )

        with boot_dev:
            version = boot_dev.get_version()

        self.label.setText('EFM8 Factory Bootloader\n'
                            'MCU: {}\n'
                           'Bootloader version: 0x{:02X}\n'
                            'Flash size: {}kB    Bootloader size: {}kB\n'
            .format(
                boot_dev.info.name,
                version,
                (boot_dev.info.flashSize)/2**10,
                (boot_dev.info.flashSize - boot_dev.info.bootloaderStart)/2**10,
            )
        )

    # nrf24lu1p
    def setup_nrf24lu1p_label(self):
        # try:
        #     self.device.open()
        #     bootloader_info = xusbboot.get_boot_info(self.device)
        #     self.device.close()
        # except TimeoutError as err:
        #     # Incase opening the device fails
        #     raise Exception ("Error Opening Device: {} | {}:{}"
        #             .format(
        #                 self.device.path,
        #                 self.device.vendor_id,
        #                 self.device.product_id
        #             ),
        #           file=sys.stderr
        #     )

        self.label.setText('nRF24LU1+ Bootloader v{}.{}\n'
                            'MCU: nRF24LU1+\n'
            .format(
                0,
                0,
                self.device.manufacturer_string,
                self.device.product_string,
            )
        )

    def updateLabel(self):
        if is_keyplus_device(self.device):
            self.setup_keyplus_label()
        elif is_xusb_bootloader_device(self.device):
            self.setup_xusb_bootloader_label()
        elif is_kp_boot_device(self.device):
            self.setup_kp_boot_32u4_label()
        elif is_efm8_boot_device(self.device):
            self.setup_efm8_boot_label()
        elif is_nrf24lu1p_bootloader_device(self.device):
            self.setup_nrf24lu1p_label()
        else:
            self.device.close()
            raise KeyplusFlasherError("Unsupported USB device {}:{}".format(
                self.device.vendor_id, self.device.product_id))
        self.device.close()
        self.updateStyle()

    def updateStyle(self):
        if self.label == None:
            return
        if self.has_critical_error:
            self.label.setStyleSheet("""
            QLabel {
                background: #F88;
                border: 1px solid;
                padding: 2px;
                font: 11pt;
            }
            """)
        else:
            self.label.setStyleSheet("""
            QLabel {
                background: #FFF;
                                     self.updateLabel
                border: 1px solid;
                padding: 2px;
                font: 11pt;
            }
            """)


    def initUI(self):
        programIcon = QIcon('img/download.png')
        infoIcon = QIcon('img/info.png')

        self.updateLabel()

        if self.label == None:
            return

        self.label.setTextInteractionFlags(Qt.TextSelectableByMouse)
        self.updateStyle()
        self.label.setFixedHeight(90)
        self.label.setMinimumWidth(390)

        self.programButton = QPushButton(' Program')
        self.programButton.setIcon(programIcon)
        self.programButton.clicked.connect(self.programSignal)

        if is_bootloader_device(self.device):
            self.secondaryButton = QPushButton('Reset')
            self.secondaryButton.clicked.connect(self.resetSignal)
        else:
            self.secondaryButton = QPushButton('Info')
            self.secondaryButton.setIcon(infoIcon)
            self.secondaryButton.clicked.connect(self.infoSignal)

        self.layout = QGridLayout()
        self.layout.addWidget(self.label, 0, 0, 2, 1)
        self.layout.addWidget(self.programButton, 0, 1)
        self.layout.addWidget(self.secondaryButton, 1, 1)
        self.setLayout(self.layout)

        self.setMaximumHeight(150)
        self.setContentsMargins(0, 0, 0, 0)

        self.setStyleSheet("""
            QGroupBox {
                border: 1px solid #CCC;
            }
        """)

    def infoSignal(self):
        self.show_info.emit(self.device.path)

    def resetSignal(self):
        self.reset.emit(self.device.path)

    def programSignal(self):
        self.program.emit(self.device.path)

    def sizeHint(self):
        return QSize(560, 0)

class DeviceInformationWindow(QDialog):
    def __init__(self, parent, header, device_settings, firmware_settings,
                 error_codes, *args):
        QDialog.__init__(self, parent, *args)
        self.setGeometry(300, 200, 570, 450)
        self.setWindowTitle("Device information")
        table_model = DeviceInformationTable(self, header, device_settings)
        dev_settings_table = QTableView()
        dev_settings_table.setModel(table_model)

        table_model = DeviceInformationTable(self, header, firmware_settings)
        fw_settings_table = QTableView()
        fw_settings_table.setModel(table_model)

        table_model = DeviceInformationTable(self, header, error_codes)
        error_code_table = QTableView()
        error_code_table.setModel(table_model)

        # set font
        # font = QFont("monospace", 10)
        # font = QFont("", 10)
        # dev_settings_table.setFont(font)
        # fw_settings_table.setFont(font)

        # set column width to fit contents (set font first!)
        dev_settings_table.resizeColumnsToContents()
        fw_settings_table.resizeColumnsToContents()
        error_code_table.resizeColumnsToContents()

        tab_view = QTabWidget()
        tab_view.addTab(dev_settings_table, "User settings")
        tab_view.addTab(fw_settings_table, "Firmware settings")
        tab_view.addTab(error_code_table, "Error Codes")

        layout = QVBoxLayout(self)
        layout.addWidget(tab_view)
        self.setLayout(layout)

class DeviceInformationTable(QAbstractTableModel):
    def __init__(self, parent, header, data_list, *args):
        QAbstractTableModel.__init__(self, parent, *args)
        self.data_list = data_list
        self.header = header

    def rowCount(self, parent):
        return len(self.data_list)

    def columnCount(self, parent):
        if len(self.data_list) == 0:
            return 0
        else:
            return len(self.data_list[0])

    def data(self, index, role):
        if not index.isValid():
            return None
        elif role != Qt.DisplayRole:
            return None
        return self.data_list[index.row()][index.column()]

    def headerData(self, col, orientation, role):
        if orientation == Qt.Horizontal and role == Qt.DisplayRole:
            return self.header[col]
        return None

class DeviceList(QScrollArea):
    def __init__(self, programming_handler, info_handler, reset_handler):
        super(DeviceList, self).__init__()

        self.deviceWidgets = []
        self.programming_handler = programming_handler
        self.info_handler = info_handler
        self.reset_handler = reset_handler
        self.updateCounter = 0

        self.initUI()

    def initUI(self):
        self.setHorizontalScrollBarPolicy(Qt.ScrollBarAsNeeded)
        self.setVerticalScrollBarPolicy(Qt.ScrollBarAsNeeded)

        self.listWidget = QWidget()
        self.layout = QVBoxLayout()
        self.layout.setContentsMargins(0, 0, 0, 0)

        self.listWidget.setLayout(self.layout)
        self.setWidgetResizable(True)

        self.setWidget(self.listWidget)

        self.updateList()

    # def updateLabels(self):
    #     for dev in self.deviceWidgets:
    #         dev.updateLabels()

    def clearList(self):
        # look at the list of connected devices and find out which devices are
        # no longer connected and remove them
        i = 0
        while i < self.layout.count():
            devItem = self.layout.itemAt(i).widget()
            self.layout.takeAt(i).widget().deleteLater()

    def rebuildList(self):
        self.clearList()
        self.updateList()

    def updateList(self):
        self.updateCounter += 1

        deviceInfoList = list(filter(is_supported_device, easyhid.Enumeration().find()))

        deleteList = []
        deviceIds = [dev.path for dev in deviceInfoList]
        oldDevices = []
        newDevices = []

        # look at the list of connected devices and find out which devices are
        # no longer connected and remove them
        i = 0
        while i < self.layout.count():
            devItem = self.layout.itemAt(i).widget()
            if hasattr(devItem, "device") and (devItem.device.path in deviceIds):
                oldDevices.append(devItem.device)
                i += 1
            else:
                self.layout.takeAt(i).widget().deleteLater()

        # Now find the list of new devices
        oldDeviceIds = [dev.path for dev in oldDevices]
        for dev in deviceInfoList:
            if dev.path in oldDeviceIds:
                continue
            else:
                newDevices.append(dev)

        for devInfo in newDevices:
            devWidget = DeviceWidget(devInfo)
            if devWidget.label:
                self.deviceWidgets.append(devWidget)
                self.layout.addWidget(devWidget)
                devWidget.program.connect(self.programming_handler)
                devWidget.show_info.connect(self.info_handler)
                devWidget.reset.connect(self.reset_handler)

        # if len(self.deviceWidgets) == 0:
        if len(oldDevices) == 0 and len(newDevices) == 0:
            n = self.updateCounter % 4
            label = QLabel("Scanning for devices" + "." * n + " " * (4-n))
            self.layout.setAlignment(Qt.AlignCenter)
            self.layout.addWidget(label)
            self.deviceWidgets = []
        else:
            self.layout.setAlignment(Qt.AlignTop)
            self.updateCounter = 0

class FileSelector(QWidget):
    ScopeLayout = 0
    ScopeDevice = 1
    ScopeFirmware = 2
    ScopeAll = 3

    def __init__(self):
        super(FileSelector, self).__init__()

        self.initUI()
        self.lastDir = None

    def initUI(self):

        self.scopeSelector = QComboBox()
        self.scopeSelector.addItem("Layout", FileSelector.ScopeLayout)
        self.scopeSelector.addItem("Device and RF", FileSelector.ScopeDevice)
        self.scopeSelector.addItem("Firmware Update", FileSelector.ScopeFirmware)
        # self.scopeSelector.addItem("All", FileSelector.ScopeAll)

        self.scopeSelector.currentIndexChanged.connect(self.scopeUpdate)

        self.layoutSettings = LayoutSettingsScope()
        self.deviceSettings = DeviceSettingsScope()
        self.firmwareSettings = FirmwareSettingsScope()

        self.scope = None

        self.layout = QVBoxLayout()
        self.layout.addWidget(self.scopeSelector)

        self.stackedLayout = QStackedLayout()
        self.stackedLayout.addWidget(self.layoutSettings)
        self.stackedLayout.addWidget(self.deviceSettings)
        self.stackedLayout.addWidget(self.firmwareSettings)

        self.layout.addLayout(self.stackedLayout)

        self.setMinimumSize(0, 300)

        self.setLayout(self.layout)
        # self.updateUI(FileSelector.ScopeLayout)

    def scopeUpdate(self, index):
        self.stackedLayout.setCurrentIndex(index)

    def updateUI(self, scope):
        if self.scope == scope:
            return

        self.layout.removeWidget(self.layoutSettings)
        self.layout.removeWidget(self.deviceSettings)
        self.layout.removeWidget(self.firmwareSettings)

        if scope == FileSelector.ScopeLayout:
            self.layout.addWidget(self.layoutSettings)
        elif scope == FileSelector.ScopeDevice:
            self.layout.addWidget(self.deviceSettings)
        elif scope == FileSelector.ScopeFirmware:
            self.layout.addWidget(self.firmwareSettings)
        elif scope == FileSelector.ScopeAll:
            self.layout.addWidget(self.layoutSettings)
            self.layout.addWidget(self.deviceSettings)
            self.layout.addWidget(self.firmwareSettings)

    def getProgramingInfo(self):
        return self.scopeSelector.currentIndex()

    def getFirmwareFile(self):
        return self.firmwareSettings.getFirmwareFile()

    def getLayoutFile(self):
        return self.layoutSettings.getLayoutFile()

    def getRFLayoutFile(self):
        return self.deviceSettings.getCurrentSettings()[2]

    def getRFFile(self):
        return self.deviceSettings.getCurrentSettings()[1]

    def getTargetID(self):
        return self.deviceSettings.getCurrentSettings()[0]

class LayoutSettingsScope(QGroupBox):

    def __init__(self, parent=None):
        super(LayoutSettingsScope, self).__init__("Layout settings:")

        self.initUI()

    def initUI(self):
        self.fileWidget = FileBrowseWidget("Layout file (*.yaml)")
        self.fileWidget.setText(DEFAULT_LAYOUT_FILE)
        layout = QFormLayout()
        layout.addRow(QLabel("Layout file (.yaml): "), self.fileWidget)
        label = QLabel("<b>Note:</b> Each device that can act as a "
                       "wireless/wired receiver stores its own copy of the "
                       "layout settings. The other devices will still function "
                       "when the layout is updated, but they will use their "
                       "old version of the layout instead. "
                       "You can intentionally load different layouts on different "
                       "keyboard components to have different layout options depending "
                       "on which device is acting as the receiver."
                       )
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)
        label.setWordWrap(True)
        layout.addRow(label)
        self.setLayout(layout)

    def getLayoutFile(self):
        return self.fileWidget.text()

class DeviceSettingsScope(QGroupBox):
    def __init__(self):
        super(DeviceSettingsScope, self).__init__("Device and RF settings:")

        self.initUI()

    def initUI(self):
        self.layoutFile = FileBrowseWidget("Layout settings file .yaml (*.yaml)")
        self.layoutFile.setText(DEFAULT_LAYOUT_FILE)
        self.rfSettingsFile = FileBrowseWidget("Device settings file .yaml (*.yaml)")
        self.rfSettingsFile.setText(DEFAULT_RF_FILE)
        layout = QFormLayout()
        layout.addRow(QLabel("Layout settings file (.yaml):"), self.layoutFile)
        layout.addRow(QLabel("RF settings file (.yaml):"), self.rfSettingsFile)
        self.idLine = QLineEdit()
        self.idLine.setText(str(DEFAULT_DEVICE_ID))
        self.idLine.setMaximumWidth(50)
        self.idLine.setValidator(QIntValidator(0, 63))
        layout.addRow(QLabel("Device id (0-63):"), self.idLine)

        self.generateButton = QPushButton("Generate new RF settings")
        self.generateButton.setMaximumWidth(230)
        self.generateButton.clicked.connect(self.generateRFSettings)
        layout.addRow(None, self.generateButton)

        label = QLabel("<b>Note:</b> These settings only need to be loaded on each "
                       "device once and are persistent when you update the layout. "
                       "To ensure proper operation and security, each device must "
                       "have a unique device ID for a given RF settings file. "
                       "Since RF settings file contains your encryption key, make "
                       "sure to keep it secret.")
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)
        label.setWordWrap(True)
        layout.addRow(label)
        self.setLayout(layout)

    def generateRFSettings(self):
        result = QFileDialog.getSaveFileName(
            self, "Save file", FileBrowseWidget.lastDirectory, "RF settings .yaml (*.yaml)")
        fname = result[0]
        if fname != '':
            fileInfo = QFileInfo(fname)
            try:
                FileBrowseWidget.lastDir = fileInfo.baseName()
            except:
                pass

            try:
                rf_settings = LayoutRFSettings()
                rf_settings.load_random()
                json_obj = rf_settings.to_json()
                timeNow = datetime.datetime.now().strftime("%Y-%M-%d at %H:%M")
                with open(fname, 'w') as outFile:
                    outFile.write(
                        "# Generated on {}\n\n".format(timeNow) +
                        yaml.safe_dump(json_obj, default_flow_style=False)
                    )
                self.rfSettingsFile.lineEdit.setText(fname)
            except IOError as e:
                # TODO: proper error message
                print("error writing file: " + str(e))

    def getCurrentSettings(self):
        rawID = self.idLine.text()
        if rawID == '':
            rawID = None
        else:
            rawID = int(rawID)
        return (
            rawID,
            self.rfSettingsFile.lineEdit.text(),
            self.layoutFile.lineEdit.text()
        )


class FirmwareSettingsScope(QGroupBox):
    def __init__(self):
        super(FirmwareSettingsScope, self).__init__("Firmware Update:")

        self.initUI()

    def initUI(self):
        self.fileWidget = FileBrowseWidget("Firmware file .hex (*.hex)")
        self.fileWidget.setText(DEFAULT_FIRMWARE_FILE)
        layout = QFormLayout()
        layout.addRow(QLabel("Firmware file (.hex):"), self.fileWidget)
        label = QLabel("<b>Note:</b> after updating the firmware, all layout "
                       "and device settings will be erased.")
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)
        layout.addRow(label)
        self.setLayout(layout)

    def getFirmwareFile(self):
        return self.fileWidget.text()


class FileBrowseWidget(QWidget):
    lastDirectory = None

    def __init__(self, fileType="Layout File (*.yaml)"):
        super(FileBrowseWidget, self).__init__()

        self.fileTypeName = fileType

        self.initUI()

    def initUI(self):
        # hbox = QHBoxLayout()
        hbox = QGridLayout()

        self.lineEdit = QLineEdit()
        self.browseButton = QPushButton("Browse")

        hbox.addWidget(self.lineEdit, 0, 0, )
        hbox.addWidget(self.browseButton, 0, 1)
        hbox.setContentsMargins(0, 0, 0, 0)

        self.browseButton.clicked.connect(self.grabFileName)

        self.setLayout(hbox)

    def setText(self, val):
        self.lineEdit.setText(val)

    def text(self):
        return self.lineEdit.text()

    def grabFileName(self):
        result = QFileDialog.getOpenFileName(
            self, "Open file", FileBrowseWidget.lastDirectory, self.fileTypeName)
        fname = result[0]
        if fname != '':
            fileInfo = QFileInfo(fname)
            try:
                FileBrowseWidget.lastDir = fileInfo.baseName()
            except:
                pass
            self.lineEdit.setText(fname)


class Loader(QMainWindow):
    def __init__(self, parent=None):
        super(Loader, self).__init__(parent)

        self.initUI()

    def clearDeviceList(self):
        self.statusBar().showMessage("Refreshing device list...", STATUS_BAR_TIMEOUT)
        self.deviceListWidget.clearList()

    def updateDeviceList(self):
        self.statusBar().showMessage("Device list updating...", STATUS_BAR_TIMEOUT)
        self.deviceListWidget.updateList()
        self.statusBar().showMessage("Device list updated finished!", STATUS_BAR_TIMEOUT)

    def getFileName(self, ext):
        fname = QFileDialog.getOpenFileName(self, 'Open file', '/home')
        # if fname[0]:
        #     f = open(fname[0], 'r')

        #     with f:
        #         data = f.read()
        #         self.textEdit.setText(data)

    def initUI(self):

        # textEdit = QTextEdit()
        # self.setCentralWidget(textEdit)

        # self.setStyleSheet("QGroupBox {  border: 1px solid gray; padding: 5px;}");

        # Action to quit program
        exitAction = QAction(QIcon(None), 'Quit', self)
        exitAction.setShortcut('Ctrl+Q')
        exitAction.setStatusTip('Exit application')
        exitAction.triggered.connect(self.close)

        # # Action to update device list
        # self.refreshAction = QAction(QIcon('img/reload.png'), 'Refresh', self)
        # self.refreshAction.setShortcut('F5')
        # self.refreshAction.setStatusTip('Refresh list of connected devices.')
        # self.refreshAction.triggered.connect(self.updateDeviceList)

        # Action to show program information
        helpAction = QAction(QIcon(None), 'Help', self)
        helpAction.setShortcut('F1')
        helpAction.triggered.connect(self.showHelpDialog)

        # Action to help
        aboutAction = QAction(QIcon(None), 'About', self)
        aboutAction.triggered.connect(self.showAboutDialog)

        self.statusBar()

        # Add the file menu
        menubar = self.menuBar()
        fileMenu = menubar.addMenu('&File')
        # fileMenu.addAction(self.refreshAction)
        fileMenu.addAction(exitAction)
        fileMenu = menubar.addMenu('&Help')
        fileMenu.addAction(helpAction)
        fileMenu.addAction(aboutAction)

        # # Add the toolbar
        # toolbar = self.addToolBar('Exit')
        # # toolbar.addAction(self.refreshAction)
        # toolbar.setMovable(False)

        # Add the main windows widgets
        self.deviceListWidget = DeviceList(
            self.programDeviceHandler,
            self.infoDeviceHandler,
            self.resetDeviceHandler
        )
        self.fileSelectorWidget = FileSelector()

        self.setStyleSheet("""
            QStatusBar {
                border-top: 1px solid #CCC;
            }
            QToolBar {
                border-top: 1px solid #DDD;
                border-bottom: 1px solid #CCC;
            }
        """)

        gbox = QGroupBox("Connected USB devices:")
        gboxLayout = QVBoxLayout()
        gboxLayout.addWidget(self.deviceListWidget)
        gbox.setLayout(gboxLayout)

        self.refreshEvent = QTimer()
        self.refreshEvent.setInterval(1250)
        self.refreshEvent.timeout.connect(self.USBUpdate)
        self.refreshEvent.start()

        layout = QVBoxLayout()
        layout.addWidget(self.fileSelectorWidget)
        layout.addWidget(gbox)
        self.setCentralWidget(QWidget())
        self.centralWidget().setLayout(layout)

        self.setMinimumSize(620, 700)
        self.setMaximumWidth(620)
        self.setWindowFlags(Qt.Window | Qt.WindowMinimizeButtonHint | Qt.WindowCloseButtonHint)

        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('keyplus layout and firmware loader')
        self.show()

    def abort_update(self, target_device):
        try:
            target_device.close()
        except:
            pass

        self.deviceListWidget.updateList()

    def abort_update2(self):
        self.deviceListWidget.updateList()

    def update_device_list(self):
        """
        Update the device list.
        """
        for widget in self.deviceListWidget.deviceWidgets[:]: # Use [:] to copy list
            try:
                widget.updateLabel()
            except (easyhid.HIDException, KeyplusFlasherError):
                # If communication with a USB device fails, remove it from the list.
                self.deviceListWidget.deviceWidgets.remove(widget)

    def check_version(self, kb):
        if not kb.firmware_info.has_at_least_version(keyplus.__version__):
            version = kb.firmware_info.get_version_str()
            error_msg_box("Need at least version {}, but this device has {}. Select "
                          "'Firmware Update' from drop down box to update the firmware.\n\n"
                          "You can download newer versions from here: https://github.com/ahtn/keyplus/releases"
                          .format(keyplus.__version__, version))
            return -1
        else:
            return 0

    @Slot(str)
    def programDeviceHandler(self, device_path):
        target_device = self.tryOpenDevicePath(device_path)

        if target_device == None:
            self.abort_update(target_device)
            return

        programmingMode = self.fileSelectorWidget.getProgramingInfo()

        if is_bootloader_device(target_device) and programmingMode != FileSelector.ScopeFirmware:
            error_msg_box("The device's bootloader is running. "
                          "Choose 'Update Firmware' from the drop down box "
                          "to flash new firmware, or reset it to use to run "
                          "the currently loaded firmware (if any).")
            self.abort_update(target_device)
            return

        if programmingMode == FileSelector.ScopeLayout:
            target_device.close()
            kb = self.tryOpenDevicePath2(device_path)

            if kb == None:
                return

            if self.check_version(kb):
                return

            self.statusBar().showMessage("Started updating layout", STATUS_BAR_TIMEOUT)

            layout_file = self.fileSelectorWidget.getLayoutFile()

            if layout_file == '':
                error_msg_box("No layout file given.")
                return

            parser_info = KeyplusParserInfo()
            try:
                kp_layout = KeyplusLayout()
                kp_layout.from_yaml_file(layout_file, parser_info=parser_info)
                device_target = kb.get_device_target()
                settings_data = kp_layout.build_settings_section(device_target)
                layout_data = kp_layout.build_layout_section(device_target)
            except (KeyplusError, IOError) as err:
                error_msg_box(str(err))
                return
            except (yaml.YAMLError) as err:
                error_msg_box("YAML syntax error: \n" + str(err))
                self.abort_update(target_device)
                return

            with kb:
                reset_type = RESET_TYPE_SOFTWARE

                try:
                    if kb.get_error_info().has_critical_error():
                        reset_type = RESET_TYPE_HARDWARE
                    kb.update_settings_section(settings_data, keep_rf=True)
                    kb.update_layout_section(layout_data)
                except easyhid.HIDException:
                    error_msg_box("Error writing layout")
                    self.abort_update(target_device)
                    return

                try:
                    kb.reset(reset_type)
                except easyhid.HIDException:
                    pass # may fail if HID device re-enumerates differently
                kb.disconnect()

            self.update_device_list()

            if len(parser_info.warnings) > 0:
                error_msg_box(
                    "The device was programmed successfully, but some "
                    "non-critical errors were encountered:\n" +
                    "\n".join([str(warn) for warn in parser_info.warnings]),
                    title = "Warnings",
                )

            self.statusBar().showMessage("Finished updating layout", STATUS_BAR_TIMEOUT)
        elif programmingMode == FileSelector.ScopeDevice:
            target_device.close()
            kb = self.tryOpenDevicePath2(device_path)
            if kb == None:
                return

            if self.check_version(kb):
                return

            layout_file = self.fileSelectorWidget.getRFLayoutFile()
            rf_file = self.fileSelectorWidget.getRFFile()
            target_id = self.fileSelectorWidget.getTargetID()

            self.statusBar().showMessage("Started updating RF settings", STATUS_BAR_TIMEOUT)

            if layout_file == '':
                error_msg_box("No layout file given.")
                self.abort_update(target_device)
                return
            elif rf_file == '':
                error_msg_box("No RF settings file given.")
                self.abort_update(target_device)
                return
            elif target_id == None:
                error_msg_box("No device id file given.")
                self.abort_update(target_device)
                return

            parser_info = KeyplusParserInfo()
            rf_parser_info = KeyplusParserInfo()
            try:
                kp_layout = KeyplusLayout()
                warnings = []
                kp_layout.from_yaml_file(layout_file,
                                         rf_file,
                                         parser_info=parser_info,
                                         rf_parser_info=rf_parser_info)
                device_target = kb.get_device_target()
                device_target.device_id = target_id
                settings_data = kp_layout.build_settings_section(device_target)
                layout_data = kp_layout.build_layout_section(device_target)
            except IOError as err:
                error_msg_box("IOError: " + str(err))
                self.abort_update(target_device)
                return
            except KeyplusError as err:
                error_msg_box("KeyplusError: " + str(err))
                self.abort_update(target_device)
                return
            except (yaml.YAMLError) as err:
                error_msg_box("YAML syntax error: \n" + str(err))
                self.abort_update(target_device)
                return
            except Exception as err:
                traceback.print_tb(err.__traceback__, file=sys.stderr)
                error_msg_box("Exception({}): {}\nAt: {}"
                              .format(type(err),
                                      str(err),
                                      "".join(traceback.format_tb(err.__traceback__))
                                      )
                              )
                self.abort_update(target_device)
                return

            with kb:
                kb.update_settings_section(settings_data, keep_rf=False)
                kb.update_layout_section(layout_data)
                try:
                    kb.reset(reset_type=RESET_TYPE_HARDWARE)
                except easyhid.HIDException:
                    print("failed to reset")
                    pass # may fail if HID device re-enumerates differently
                kb.disconnect()

            self.clearDeviceList()
            self.updateDeviceList()

            if warnings != []:
                error_msg_box(
                    "The device was programmed successfully, but some "
                    "non-critical errors were encountered:\n" +
                    "\n".join([str(warn) for warn in warnings]),
                    title = "Warnings",
                )

            self.statusBar().showMessage("Finished updating RF settings", STATUS_BAR_TIMEOUT)

        elif programmingMode == FileSelector.ScopeFirmware:
            fw_file = self.fileSelectorWidget.getFirmwareFile()

            self.statusBar().showMessage("Starting update firmware", STATUS_BAR_TIMEOUT)

            if fw_file == '':
                error_msg_box("No firmware file given.")
            else:

                if is_xusb_bootloader_device(target_device):
                    self.program_xusb_boot_firmware_hex(target_device, fw_file)
                elif is_kp_boot_device(target_device):
                    self.program_kp_boot_32u4_firmware_hex(target_device, fw_file)
                elif is_efm8_boot_device(target_device):
                    self.program_efm8_boot_firmware_hex(target_device, fw_file)
                elif is_keyplus_device(target_device):
                    target_device.close()
                    kb = self.tryOpenDevicePath2(device_path)
                    try:
                        with kb:
                            boot_vid, boot_pid = kb.enter_bootloader()

                        bootloader_info = keyplus.usb_ids.get_bootloader_info(
                            boot_vid,
                            boot_pid,
                        )

                        if bootloader_info.bootloader == BootloaderType.UNKNOWN:
                            error_msg_box(
                                "The device has entered its bootloader but "
                                "requires an external utility to flash. " +
                                bootloader_info.nonHIDMessage
                            )

                        if bootloader_info.nonHID:
                            print(bootloader_info)
                            error_msg_box(
                                "The device has entered its bootloader but "
                                "requires an external utility to flash. " +
                                bootloader_info.nonHIDMessage
                            )
                            return

                        if bootloader_info and bootloader_info.uses_serial_num:
                            serial_num = target_device.serial_number
                        else:
                            serial_num = None


                        self.bootloaderProgramTimer = QTimer()
                        self.bootloaderProgramTimer.setInterval(3000)
                        self.bootloaderProgramTimer.setSingleShot(True)
                        self.bootloaderProgramTimer.timeout.connect( lambda:
                            self.programFirmwareHex(boot_vid, boot_pid,
                                                    serial_num, fw_file)
                        )
                        self.bootloaderProgramTimer.start()
                    except (easyhid.HIDException):
                        error_msg_box("Programming hex file failed: '{}'".format(fw_file))
                else:
                    error_msg_box("This bootloader is currently unsupported")
        else:
            try:
                target_device.close()
            except:
                pass
            raise Exception("Unimplemented programming mode")


    def programFirmwareHex(self, boot_vid, boot_pid, serial_num, file_name):
        device = None

        matches = []

        en = easyhid.Enumeration().find()

        # Look for devices with matching serial_num number
        for dev in en:
            if serial_num and dev.serial_number == serial_num:
                device = dev
                break
            elif (
                not serial_num and
                dev.vendor_id == boot_vid and
                dev.product_id == boot_pid
            ):
                # if a device was found with matching vid:pid, but the
                # original device didn't expose a serial number, then
                # assume that the bootloader/firmware doesn't set the
                # serial_num number, so just program the first matching
                # device
                device = dev
                break

        if device == None:
            error_msg_box("Couldn't connect to the device's bootloader")
            return
        else:
            if self.tryOpenDevice(device):
                return
            elif is_xusb_bootloader_device(device):
                self.program_xusb_boot_firmware_hex(device, file_name)
            elif is_kp_boot_device(device):
                self.program_kp_boot_32u4_firmware_hex(device, file_name)
            elif is_efm8_boot_device(device):
                self.program_efm8_boot_firmware_hex(device, file_name)
            elif is_nrf24lu1p_bootloader_device:
                error_msg_box("Programming nrf24 is currently unsupported")
                return

        self.statusBar().showMessage("Finished updating firmware", STATUS_BAR_TIMEOUT)

    def program_xusb_boot_firmware_hex(self, device, file_name):
        try:
            xusbboot.write_hexfile(device, file_name)
        except xusbboot.BootloaderException as err:
            error_msg_box("Error programming the hex file to the bootloader: " + str(err))
        finally:
            device.close()

    def program_kp_boot_32u4_firmware_hex(self, device, file_name):
        try:
            device.close()
            boot_dev = kp_boot_32u4.BootloaderDevice(device)
            with boot_dev:
                boot_dev.write_flash_hex(file_name)
                boot_dev.reset_mcu()
        except Exception as err:
            error_msg_box("Error programming the hex file to the bootloader: " + str(err))

    def program_efm8_boot_firmware_hex(self, device, file_name):
        try:
            device.close()
            boot_dev = efm8boot.EFM8BootloaderHID(device)
            with boot_dev:
                boot_dev.write_flash_hex(file_name)
                boot_dev.reset_mcu()
        except Exception as err:
            error_msg_box("Error programming the hex file the bootloader: " + str(err))

    def tryOpenDevicePath2(self, device_path):
        try:
            device = easyhid.Enumeration().find(path=device_path)[0]
            return KeyplusKeyboard(device)
        except Exception as err:
            msg_box(
                    description="Failed to open device! Check that it is not in "
                    "use by another program and you have permission to read/write "
                    "to it. ErrorMsg: {}"
                    .format(err),
                    title="USB Device write error"
            )
            traceback.print_exc(file=sys.stderr)
            return None

    def tryOpenDevicePath(self, device_path):
        try:
            device = easyhid.Enumeration().find(path=device_path)[0]
            device.open()
            return device
        except:
            msg_box(
                    description="Failed to open device! Check it is still present "
                    "and you have permission to write to it.",
                    title="USB Device write error"
            )
            return None

    def tryOpenDevice(self, device):
        try:
            device.open()
            return False
        except:
            msg_box(
                    description="Failed to open device! Check it is still present "
                    "and you have permission to write to it.",
                    title="USB Device write error"
            )
            return True

    @Slot(str)
    def resetDeviceHandler(self, device_path):
        device = self.tryOpenDevicePath(device_path)
        if device == None: return

        if is_keyplus_device(device):
            device.close()
            kb = self.tryOpenDevicePath2(device_path)

            with kb:
                kb.reset_device()
        elif is_xusb_bootloader_device(device):
            xusbboot.reset(device)
        elif is_kp_boot_device(device):
            device.close()
            dev = kp_boot_32u4.BootloaderDevice(device)
            with dev:
                dev.reset_mcu()
        elif is_nrf24lu1p_bootloader_device(device):
            print("TODO: reset: ", device_path, file=sys.stderr)
        elif is_efm8_boot_device(device):
            device.close()
            dev = efm8boot.EFM8BootloaderHID(device)
            with dev:
                dev.reset_mcu()
        else:
            print("Can't reset device: ", device_path, file=sys.stderr)

    @Slot(str)
    def infoDeviceHandler(self, device_path):
        kb = self.tryOpenDevicePath2(device_path)

        if kb == None:
            return

        with kb:
            deviceInfo = kb.get_device_info()
            firmwareInfo = kb.get_firmware_info()
            rfInfo = kb.get_rf_info()
            errorInfo = kb.get_error_info()
            serial_number = kb.serial_number

        def ms_str(x):
            return "{}ms".format(x)

        def us_str(x):
            return "{0:.1f}µs".format(x / 255 * 48.0)

        header = ["Attribute", "Value"]

        device_settings = []

        device_settings = [
            ("Device ID", deviceInfo.device_id),
            ("Device name", deviceInfo.get_device_name()),
            ("Device serial number", serial_number),
            ("Last layout update", str(deviceInfo.get_timestamp())),
            ("Default report mode", deviceInfo.get_default_report_mode_str()),
            ("Matrix scan mode", deviceInfo.get_scan_mode_str()),
            ("Matrix columns", deviceInfo.scan_plan.cols),
            ("Matrix rows", deviceInfo.scan_plan.rows),
            ("Key debounce press time", ms_str(deviceInfo.scan_plan.debounce_time_press)),
            ("Key debounce release time", ms_str(deviceInfo.scan_plan.debounce_time_release)),
            ("Key press trigger time", ms_str(deviceInfo.scan_plan.trigger_time_press)),
            ("Key release trigger time", ms_str(deviceInfo.scan_plan.trigger_time_release)),
            ("Key discharge idle time", us_str(deviceInfo.scan_plan.parasitic_discharge_delay_idle)),
            ("Key discharge debouncing time", us_str(deviceInfo.scan_plan.parasitic_discharge_delay_debouncing)),
            ("Settings stored CRC", hex(deviceInfo.crc)),
            ("Settings computed CRC", hex(deviceInfo.compute_crc())),

            ("USB", (not deviceInfo.usb_disabled and firmwareInfo.has_usb)),
            ("I2C", (not deviceInfo.i2c_disabled and firmwareInfo.has_i2c)),
            ("nRF24 wireless", (not deviceInfo.nrf24_disabled and firmwareInfo.has_nrf24)),
            ("Unifying mouse", (not deviceInfo.unifying_disabled and firmwareInfo.has_unifying)),
            ("Bluetooth", (not deviceInfo.bluetooth_disabled and firmwareInfo.has_bluetooth)),

            ("RF pipe0", binascii.hexlify(bytes(rfInfo.pipe_addr_0)).decode('ascii')),
            ("RF pipe1", binascii.hexlify(bytes(rfInfo.pipe_addr_1)).decode('ascii')),
            ("RF pipe2", "{:02x}".format(rfInfo.pipe_addr_2)),
            ("RF pipe3", "{:02x}".format(rfInfo.pipe_addr_3)),
            ("RF pipe4", "{:02x}".format(rfInfo.pipe_addr_4)),
            ("RF pipe5", "{:02x}".format(rfInfo.pipe_addr_5)),

            ("RF channel", str(rfInfo.channel)),
            ("RF auto retransmit count", str(rfInfo.arc)),
        ]

        firmware_settings = [
            ("Firmware version", firmwareInfo.get_version_str()),
            ("Firmware build date", str(datetime.datetime.fromtimestamp(firmwareInfo.timestamp_raw))),
            ("Firmware git hash", firmwareInfo.get_git_hash_str()),
            ("Microcontroller", chip_id.get_chip_name_from_id(firmwareInfo.chip_id)),
            ("Board ID", hex(firmwareInfo.board_id)),
            ("Internal scan method", firmwareInfo.get_interal_scan_method_as_str()),
            ("Layout storage size", firmwareInfo.layout_flash_size),
            ("Bootloader VID", "{:04x}".format(firmwareInfo.bootloader_vid)),
            ("Bootloader PID", "{:04x}".format(firmwareInfo.bootloader_pid)),

            ("Support scanning", firmwareInfo.has_scanning),
            ("Support scanning col to row", firmwareInfo.has_scanning_col_row),
            ("Support scanning row to col", firmwareInfo.has_scanning_row_col),

            ("Media keys", firmwareInfo.has_media_keys),
            ("Mouse keys", firmwareInfo.has_mouse_keys),
            ("Layer keys", firmwareInfo.has_layer_keys),
            ("Sticky keys", firmwareInfo.has_sticky_keys),
            ("Tap keys", firmwareInfo.has_tap_keys),
            ("Hold keys", firmwareInfo.has_hold_keys),

            ("Support 6KRO", firmwareInfo.has_6kro),
            ("Support NKRO", firmwareInfo.has_nkro),

            ("Support indicator LEDs", firmwareInfo.has_led_indicators),
            ("Support LED backlighting", firmwareInfo.has_led_backlighting),
            ("Support ws2812 LEDs", firmwareInfo.has_led_ws2812),

            ("Support USB"            , firmwareInfo.has_usb)       ,
            ("Support nRF24 wireless" , firmwareInfo.has_nrf24)     ,
            ("Support Unifying"       , firmwareInfo.has_unifying)  ,
            ("Support I2C"            , firmwareInfo.has_i2c)       ,
            ("Support Bluetooth"      , firmwareInfo.has_bluetooth) ,
        ]

        error_codes = []
        for code in errorInfo.get_error_codes():
            error_codes.append(
                (errorInfo.error_code_to_name(code), code)
            )

        self.info_window = DeviceInformationWindow(
            self,
            header,
            device_settings,
            firmware_settings,
            error_codes,
        )

        self.info_window.exec_()

        self.deviceListWidget.updateList()

    def USBUpdate(self):
        self.deviceListWidget.updateList()

    def showAboutDialog(self):
        QMessageBox.about(self, "About keyplus Loader.",
"""
The keyplus layout and firmware loader.
keyplus version: """ + keyplus.__version__
)

    def showHelpDialog(self):
        QMessageBox.about(self, "keyplus Loader Help",
"""
This is the layout and firmware loader for the keyplus keyboard firmware.

The layout files are *.yaml files. For documentation and examples see here: TODO

The rf files are *.yaml files. For documentation and examples see here: TODO

The firmware loader accepts *.hex files. For the latest keyplus firmware see here: TODO

"""
        )



if __name__ == '__main__':
    from colorama import Fore, Style
    colorama.init(convert=False)
    app = QApplication(sys.argv)
    ex = Loader()
    sys.exit(app.exec_())
