#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals

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

# TODO: clean up directory structure
import sys
import datetime, time, binascii
import yaml

import easyhid
import protocol
import layout.parser
import xusb_boot

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

class DeviceWidget(QGroupBox):

    PROGRAM_SIGNAL = 0
    INFO_SIGNAL = 1

    program = Signal(str)
    show_info = Signal(str)

    def __init__(self, device):
        super(DeviceWidget, self).__init__(None)

        self.device = device
        self.valid = False

        self.initUI()

    def initUI(self):
        programIcon = QIcon('img/download.png')
        infoIcon = QIcon('img/info.png')

        info = self.device
        try:
            self.device.open()
            settingsInfo = protocol.get_device_info(self.device)
            firmwareInfo = protocol.get_firmware_info(self.device)
            self.device.close()
        except TimeoutError as err:
            # Incase opening the device fails
            print("Error Opening Device: {} | {}:{}"
                    .format(
                        self.device.path,
                        self.device.vendor_id,
                        self.device.product_id
                    ),
                  file=sys.stderr
            )
            return
        self.valid = True
        build_time_str = protocol.timestamp_to_str(settingsInfo.timestamp)
        self.label = QLabel('{} | {} | Firmware v{}.{}.{}\n'
                            'Device id: {}\n'
                            'Serial number: {}\n'
                            'Last time updated: {}'
            .format(
                info.manufacturer_string,
                info.product_string,
                firmwareInfo.version_major,
                firmwareInfo.version_minor,
                firmwareInfo.version_patch,
                settingsInfo.id,
                info.serial_number,
                build_time_str
            )
        )
        self.label.setTextInteractionFlags(Qt.TextSelectableByMouse)
        self.label.setStyleSheet("""
        QLabel {
            background: #FFF;
            border: 1px solid;
            padding: 2px;
            font: 11pt;
        }
        """)
        self.label.setFixedHeight(90)
        self.label.setMinimumWidth(390)

        self.programButton = QPushButton(' Program')
        self.programButton.setIcon(programIcon)
        self.programButton.clicked.connect(self.programDevice)

        self.infoButton = QPushButton('Info')
        self.infoButton.setIcon(infoIcon)
        self.infoButton.clicked.connect(self.showDeviceInfo)

        self.layout = QGridLayout()
        self.layout.addWidget(self.label, 0, 0, 2, 1)
        self.layout.addWidget(self.programButton, 0, 1)
        self.layout.addWidget(self.infoButton, 1, 1)
        self.setLayout(self.layout)

        self.setMaximumHeight(150)
        self.setContentsMargins(0, 0, 0, 0)

        self.setStyleSheet("""
            QGroupBox {
                border: 1px solid #CCC;
            }
        """)

    def showDeviceInfo(self):
        self.show_info.emit(self.device.path)

    def programDevice(self):
        self.program.emit(self.device.path)

    def sizeHint(self):
        return QSize(560, 0)

class DeviceInformationWindow(QDialog):
    def __init__(self, parent, header, device_settings, firmware_settings, *args):
        QDialog.__init__(self, parent, *args)
        self.setGeometry(300, 200, 570, 450)
        self.setWindowTitle("Device information")
        table_model = DeviceInformationTable(self, header, device_settings)
        dev_settings_table = QTableView()
        dev_settings_table.setModel(table_model)

        table_model = DeviceInformationTable(self, header, firmware_settings)
        fw_settings_table = QTableView()
        fw_settings_table.setModel(table_model)

        # set font
        # font = QFont("monospace", 10)
        font = QFont("", 10)
        dev_settings_table.setFont(font)
        fw_settings_table.setFont(font)
        # set column width to fit contents (set font first!)
        dev_settings_table.resizeColumnsToContents()
        fw_settings_table.resizeColumnsToContents()

        tab_view = QTabWidget()
        tab_view.addTab(dev_settings_table, "User settings")
        tab_view.addTab(fw_settings_table, "Firmware settings")

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
    def __init__(self, programming_handler, info_handler):
        super(DeviceList, self).__init__()

        self.deviceWidgets = []
        self.programming_handler = programming_handler
        self.info_handler = info_handler
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

    def updateList(self):
        self.updateCounter += 1

        deviceInfoList = easyhid.Enumeration(
        ).find(interface=protocol.DEFAULT_INTERFACE, manufacturer="keyplus")

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
            if devWidget.valid:
                self.deviceWidgets.append(devWidget)
                self.layout.addWidget(devWidget)
                devWidget.program.connect(self.programming_handler)
                devWidget.show_info.connect(self.info_handler)

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
        self.rfSettingsFile = FileBrowseWidget("Device settings file .yaml (*.yaml)")
        layout = QFormLayout()
        layout.addRow(QLabel("Layout settings file (.yaml):"), self.layoutFile)
        layout.addRow(QLabel("RF settings file (.yaml):"), self.rfSettingsFile)
        self.idLine = QLineEdit()
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
                rf_settings = layout.parser.RFSettings.from_rand()
                timeNow = datetime.datetime.now().strftime("%Y-%M-%d at %H:%M")
                with open(fname, 'w') as outFile:
                    outFile.write(
                        "# Generated on {}\n".format(timeNow) +
                        rf_settings.to_yaml()
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
        # self.checkButton = QPushButton("Check")
        self.infoButton = QPushButton("Info")

        hbox.addWidget(self.lineEdit, 0, 0, )
        hbox.addWidget(self.browseButton, 0, 1)
        hbox.setContentsMargins(0, 0, 0, 0)

        self.browseButton.clicked.connect(self.grabFileName)

        self.setLayout(hbox)

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

    def updateDeviceList(self):
        self.statusBar().showMessage("Device list updating...")
        self.deviceListWidget.updateList()
        self.statusBar().showMessage("Device list updated finished!")

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
        self.deviceListWidget = DeviceList(self.programDeviceHandler, self.infoDeviceHandler)
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

    @Slot(str)
    def programDeviceHandler(self, device_path):
        target_device = None

        try:
            target_device = easyhid.Enumeration().find(path=device_path)[0]
            target_device.open()
        except:
            error_msg_box("Failed to open device! Check it is still present "
                             "and you have permission to write to it.")
            return

        programmingMode = self.fileSelectorWidget.getProgramingInfo()

        if programmingMode == FileSelector.ScopeLayout:
            layout_file = self.fileSelectorWidget.getLayoutFile()

            if layout_file == '':
                error_msg_box("No layout file given.")
                target_device.close()
                return
            else:
                pass

            device_info = protocol.get_device_info(target_device)

            layout_json_obj = None
            with open(layout_file) as file_obj:
                try:
                    layout_json_obj = yaml.safe_load(file_obj.read())
                except Exception as err:
                    error_msg_box("Syntax error in yaml file: " + str(err))
                    target_device.close()
                    return

            settings_gen = layout.parser.SettingsGenerator(layout_json_obj, None)
            layout_data = settings_gen.gen_layout_section(device_info.id)
            rf_data = settings_gen.gen_settings_section(device_info.id)

            protocol.update_layout_section(target_device, layout_data)
            protocol.update_settings_section(target_device, rf_data, keep_rf=True)
            protocol.reset_device(target_device)
        elif programmingMode == FileSelector.ScopeDevice:
            layout_file = self.fileSelectorWidget.getRFLayoutFile()
            rf_file = self.fileSelectorWidget.getRFFile()
            device_id = self.fileSelectorWidget.getTargetID()

            if layout_file == '':
                error_msg_box("No layout file given.")
                target_device.close()
                return
            elif rf_file == '':
                error_msg_box("No RF settings file given.")
                target_device.close()
                return
            elif device_id == None:
                error_msg_box("No device id file given.")
                target_device.close()
                return

            layout_json_obj = None
            rf_json_obj = None
            with open(layout_file) as file_obj:
                try:
                    layout_json_obj = yaml.safe_load(file_obj.read())
                except Exception as err:
                    error_msg_box("Syntax error in yaml file: " + str(err))
                    target_device.close()
                    return
            with open(rf_file) as file_obj:
                try:
                    rf_json_obj = yaml.safe_load(file_obj.read())
                except Exception as err:
                    error_msg_box("Syntax error in yaml file: " + str(err))
                    target_device.close()
                    return

            try:
                settings_gen = layout.parser.SettingsGenerator(layout_json_obj, rf_json_obj)
            except IndexError:
                error_msg_box("No device has id '{}' in the given layout file"
                              .format(device_id))
                target_device.close()
                return
            except Exception as err:
                error_msg_box("Error Generating RF settings data: " + str(err))
                target_device.close()
                return

            layout_data = settings_gen.gen_layout_section(device_id)
            settings_data = settings_gen.gen_settings_section(device_id)

            protocol.update_settings_section(target_device, settings_data)
            protocol.update_layout_section(target_device, layout_data)
            protocol.reset_device(target_device)

        elif programmingMode == FileSelector.ScopeFirmware:
            fw_file = self.fileSelectorWidget.getFirmwareFile()
            if fw_file == '':
                error_msg_box("No firmware file given.")
            else:
                try:
                    serial_num = target_device.serial_number
                    boot_vid, boot_pid = protocol.enter_bootloader(target_device)

                    self.bootloaderProgramTimer = QTimer()
                    self.bootloaderProgramTimer.setInterval(1500)
                    self.bootloaderProgramTimer.setSingleShot(True)
                    self.bootloaderProgramTimer.timeout.connect( lambda:
                        self.programFirmwareHex(boot_vid, boot_pid, serial_num, fw_file)
                    )
                    self.bootloaderProgramTimer.start()
                except:
                    error_msg_box("Programming hex file failed: '{}'".format(fw_file))
        else:
            try:
                target_device.close()
            except:
                pass
            raise Exception("Unimplementend programming mode")

        try:
            target_device.close()
        except:
            pass

        self.deviceListWidget.updateList()

    def programFirmwareHex(self, boot_vid, boot_pid, serial_num, file_name):

        device = None

        for i in range(1):
            en = easyhid.Enumeration(vid=boot_vid, pid=boot_pid).find()

            # Look for devices with matching serial_num number
            for dev in en:
                if dev.serial_number == serial_num:
                    device = dev
                    break

            # if a device was found with matching vid:pid, but it doesn't have
            # a matching serial_num number, then assume that the bootloader/firmware
            # doesn't set the serial_num number to the same value, so just program
            # the first matching device
            if len(en) != 0:
                device = en[0]
                break

        if device == None:
            error_msg_box("Couldn't connect to the device's bootloader")
        else:
            device.open()
            try:
                xusb_boot.write_hexfile(device, file_name)
                msg_box("Programming completed successfully", title="Programming complete!")
            except xusb_boot.BootloaderException as err:
                error_msg_box("Error programming the bootloader to hex file: " + str(err))
            finally:
                device.close()

    @Slot(str)
    def infoDeviceHandler(self, device_path):
        device = None

        try:
            device = easyhid.Enumeration().find(path=device_path)[0]
            device.open()
        except:
            msg_box(
                    description="Failed to open device! Check it is still present "
                    "and you have permission to write to it.",
                    title="USB Device write error"
            )

            return

        settingsInfo = protocol.get_device_info(device)
        firmwareInfo = protocol.get_firmware_info(device)
        rfInfo = protocol.get_rf_info(device)
        device.close()

        header = ["Attribute", "Value"]
        device_settings = [
            ("Device ID", settingsInfo.id),
            ("Device Name", settingsInfo.name.decode('utf-8')),
            ("Device Serial Number", device.serial_number),
            ("Last layout update", protocol.timestamp_to_str(settingsInfo.timestamp)),
            ("Default report mode", protocol.report_mode_to_str(settingsInfo.default_report_mode)),
            ("Matrix scan mode", protocol.scan_mode_to_str(settingsInfo.scan_mode)),
            ("Matrix Columns", settingsInfo.col_count),
            ("Matrix Rows", settingsInfo.row_count),

            ("RF Pipe0", binascii.hexlify(rfInfo.pipe0).decode('ascii')),
            ("RF Pipe1", binascii.hexlify(rfInfo.pipe1).decode('ascii')),
            ("RF Pipe2", "{:02x}".format(rfInfo.pipe2)),
            ("RF Pipe3", "{:02x}".format(rfInfo.pipe3)),
            ("RF Pipe4", "{:02x}".format(rfInfo.pipe4)),
            ("RF Pipe5", "{:02x}".format(rfInfo.pipe5)),
        ]
        firmware_settings = [
            ("Firmware Version", "{}.{}.{}".format(
                firmwareInfo.version_major, firmwareInfo.version_minor, firmwareInfo.version_patch)),
            ("Firmware build date", str(datetime.datetime.fromtimestamp(firmwareInfo.timestamp))),
            ("Firmware git hash", "{:08x}".format(firmwareInfo.git_hash)),
            ("Layout storage size", firmwareInfo.layout_flash_size),
            ("Bootloader VID", "{:04x}".format(firmwareInfo.bootloader_vid)),
            ("Bootloader PID", "{:04x}".format(firmwareInfo.bootloader_pid)),
            ("Support scanning", protocol.has_fw_support_scanning(firmwareInfo)),
            ("Support scanning col to row", protocol.has_fw_support_scanning_col_row(firmwareInfo)),
            ("Support scanning row to col", protocol.has_fw_support_scanning_row_col(firmwareInfo)),

            ("Media keys", protocol.has_fw_support_key_media(firmwareInfo)),
            ("Mouse keys", protocol.has_fw_support_key_mouse(firmwareInfo)),
            ("Layer keys", protocol.has_fw_support_key_layers(firmwareInfo)),
            ("Sticky keys", protocol.has_fw_support_key_sticky(firmwareInfo)),
            ("Tap keys", protocol.has_fw_support_key_tap(firmwareInfo)),
            ("Hold keys", protocol.has_fw_support_key_hold(firmwareInfo)),

            ("Support 6KRO", protocol.has_fw_support_6kro(firmwareInfo)),
            ("Support NKRO", protocol.has_fw_support_key_hold(firmwareInfo)),

            ("Support indicator LEDs", protocol.has_fw_support_led_indicators(firmwareInfo)),
            ("Support LED backlighting", protocol.has_fw_support_led_backlighting(firmwareInfo)),
            ("Support ws2812 LEDs", protocol.has_fw_support_led_ws2812(firmwareInfo)),

            ("Support USB", protocol.has_fw_support_usb(firmwareInfo)),
            ("Support nRF24 wireless", protocol.has_fw_support_wireless(firmwareInfo)),
            ("Support Unifying", protocol.has_fw_support_unifying(firmwareInfo)),
            ("Support I2C", protocol.has_fw_support_i2c(firmwareInfo)),
            ("Support Bluetooth", protocol.has_fw_support_bluetooth(firmwareInfo)),
        ]
        self.info_window = DeviceInformationWindow(self, header, device_settings, firmware_settings)
        self.info_window.setModal(True)
        self.info_window.exec_()

        self.deviceListWidget.updateList()

    def USBUpdate(self):
        self.deviceListWidget.updateList()

    def showAboutDialog(self):
        QMessageBox.about(self, "About keyplus Loader",
"""
The keyplus layout and firmware loader.
""")

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
    import xusb_boot
    import easyhid
    import protocol
    # import time

    app = QApplication(sys.argv)
    ex = Loader()
    sys.exit(app.exec_())
