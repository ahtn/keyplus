#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Copyright 2019 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

import struct
import random
import io

from collections import namedtuple

HIDPP_REPORT_SHORT = 0x10
HIDPP_REPORT_LONG  = 0x11

HIDPP_UNIFYING_RESP_SHORT    = 0x50
HIDPP_UNIFYING_RESP_LONG     = 0x51
HIDPP_UNIFYING_RESP_BIT_MASK = 0x40

class HIDPP20Exception(Exception):
    pass

class HIDPP20ProtocolError(HIDPP20Exception):
    pass

class HIDPP20PacketError(HIDPP20Exception):
    pass

class HIDPP20TimeoutException(HIDPP20Exception):
    pass

class HIDPP20(object):
    ROOT_INDEX = 0x00
    ERROR_INDEX = 0xff

    class Root(object):
        GetFeature = 0
        Ping = 1

    class FeatureSet(object):
        GetCount = 0
        GetFeatureID = 1

    class DeviceName(object):
        GetCount = 0
        GetDeviceName = 1
        GetDeviceType = 2

    class FirmwareInfo(object):
        GetEntityCount = 0
        GetFwInfo = 1

    class BatteryLevelStatus(object):
        GetBatteryLevelStatus = 0
        GetBatteryCapability = 1
        BatteryLevelStatusBroadcastEvent = 0

    class SpecialKeysMSEButtons(object):
        GetCount = 0
        GetCtrlIdInfo = 1
        GetCtrlIdReporting = 2
        SetCtrlIdReporting = 3

        DivertedButtonsEvent = 0
        DivertedRawMouseEvent = 1

    class CryptoID(object):
        Unknown0 = 0 # cryptoID 1: returns 16 bytes of random data
        Unknown1 = 1 # cryptoID 2: returns 16 bytes of random data
        Unknown2 = 2 # reset crypto ID, changes the 16 random bytes sent by the first two commands

    ROOT                   = 0x0000
    FEATURE_SET            = 0x0001
    FEATURE_INFO           = 0x0002
    DEVICE_FW_VERSION      = 0x0003
    DEVICE_NAME            = 0x0005
    DEVICE_GROUPS          = 0x0006
    RESET                  = 0x0020
    CRYPTO_ID              = 0x0021
    DFUCONTROL             = 0x00C0
    DFUCONTROL_2           = 0x00C1
    DFU                    = 0x00D0
    BATTERY_STATUS         = 0x1000
    LED_CONTROL            = 0x1300
    CHANGE_HOST            = 0x1814
    BACKLIGHT              = 0x1981
    REPROG_CONTROLS        = 0x1B00
    REPROG_CONTROLS_V2     = 0x1B01
    REPROG_CONTROLS_V2_2   = 0x1B02
    REPROG_CONTROLS_V3     = 0x1B03
    REPROG_CONTROLS_V4     = 0x1B04
    WIRELESS_DEVICE_STATUS = 0x1D4B
    LEFT_RIGHT_SWAP        = 0x2001
    SWAP_BUTTON            = 0x2005
    VERTICAL_SCROLLING     = 0x2100
    SMART_SHIFT            = 0x2110
    HI_RES_SCROLLING       = 0x2120
    HIRES_WHEEL            = 0x2121
    LOWRES_WHEEL           = 0x2130
    MOUSE_POINTER          = 0x2200
    ADJUSTABLE_DPI         = 0x2201
    POINTER_SPEED          = 0x2205
    ANGLE_SNAPPING         = 0x2230
    SURFACE_TUNING         = 0x2240
    HYBRID_TRACKING        = 0x2400
    FN_INVERSION           = 0x40A0
    NEW_FN_INVERSION       = 0x40A2
    NEW_FN_INVERSION_2     = 0x40A3
    K375S_FN_INVERSION     = 0x40A3
    ENCRYPTION             = 0x4100
    LOCK_KEY_STATE         = 0x4220
    SOLAR_DASHBOARD        = 0x4301
    KEYBOARD_LAYOUT        = 0x4520
    KEYBOARD_DISABLE       = 0x4521
    DUALPLATFORM           = 0x4530
    KEYBOARD_LAYOUT_2      = 0x4540
    TOUCHPAD_FW_ITEMS      = 0x6010
    TOUCHPAD_SW_ITEMS      = 0x6011
    TOUCHPAD_WIN8_FW_ITEMS = 0x6012
    TOUCHPAD_RAW_XY        = 0x6100
    TOUCHMOUSE_RAW_POINTS  = 0x6110
    TOUCHMOUSE_6120        = 0x6120
    GESTURE                = 0x6500
    GESTURE_2              = 0x6501
    GKEY                   = 0x8010
    MKEYS                  = 0x8020
    MR                     = 0x8030
    REPORT_RATE            = 0x8060
    COLOR_LED_EFECTS       = 0x8070
    PER_KEY_LIGHTING       = 0x8080
    ONBOARD_PROFILES       = 0x8100
    MOUSE_BUTTON_SPY       = 0x8110

    # Experimental
    HOST_CAPABILITIES      = 0x1815

    class HostCapabilites(object):
        GetDevicePairingAbilities = 0
        GetHostInfo = 1
        # remove host?
        # move host?

    class ChangeHost(object):
        GetCount = 0
        SetHost = 1

    class X1E22(object):
        Unknown0 = 0
        Unknown1 = 1
        Unknown2 = 2

    class X1C00(object):
        Unknown0 = 0
        Unknown1 = 1
        Unknown2 = 2

    # probably some DFU command
    class X00C2(object):
        pass

    def get_feature_name(feature):
        if feature not in HIDPP20.lookup_table:
            return "UNKNOWN_FEATURE"
        return HIDPP20.lookup_table[feature]

class DeviceType(object):
    Keyboard = 0
    RemoteControl = 1
    Numpad = 2
    Mouse = 3
    Touchpad = 4
    Trackball = 5
    Presenter = 6

class BatteryLevels(object):
    InvalidBatteryLevel = 0x00
    BatteryLow = 0x18
    BatteryGood = 0x38
    BatteryFull = 0x58
    BatteryError = 0x68
    BatteryLevelUnknown = 0x69
    WrongBatteryType = 0x6B
    BatteryNotCharging = 0x6C
    BatteryChargingUnknown = 0x6D
    BatteryCharging = 0x6E
    BatteryChargingSlow = 0x6F
    BatteryChargingFast = 0x70
    BatteryChargingComplete = 0x71
    BatteryChargingError = 0x72

class ControlID(object):
    NONE              = 0x0000
    LEFT_MSB          = 0x0050
    RIGHT_MSB         = 0x0051
    MIDDLE_MSB        = 0x0052
    BACK              = 0x0053
    FORWARD           = 0x0056
    SCROLL_LEFT       = 0x005B
    SCROLL_RIGHT      = 0x005D

    GESTURE           = 0x00D0
    TOGGLE_RF_CHANNEL = 0x00D7

for class_ in [HIDPP20, DeviceType, BatteryLevels, ControlID]:
    setattr(class_, "lookup_table", {})
    for attr_name in vars(class_):
        value = getattr(class_, attr_name)
        if isinstance(value, int):
            class_.lookup_table[value] = attr_name

class HIDPPPacket(object):
    def __init__(self, data):
        # uint8_t frame_type;
        # uint8_t device_index;
        # uint8_t feature_index;
        # uint8_t software_id : 4;
        # uint8_t function_id : 4;
        # uint8_t parameters[3 or 16];
        try:
            stream = io.BytesIO(data)
            self.frame_type, = struct.unpack(">B", stream.read(1))

            # Unifying RF protocol uses different headers for hid++ responses.
            # Normally, the uniyfing receiver translates these before sending them
            # to the host, but we do that manually here, since we may receive
            # untranslated packets
            if self.frame_type in [HIDPP_UNIFYING_RESP_SHORT, HIDPP_UNIFYING_RESP_LONG]:
                self.frame_type &= ~HIDPP_UNIFYING_RESP_BIT_MASK

            self.device_index, = struct.unpack(">B", stream.read(1))
            self.feature_index, = struct.unpack(">B", stream.read(1))

            ids, = struct.unpack(">B", stream.read(1))
            self.software_id = (ids & 0x0f) >> 0
            self.function_id = (ids & 0xf0) >> 4

            if self.frame_type == HIDPP_REPORT_SHORT:
                self.parameters = stream.read(3)
            elif self.frame_type == HIDPP_REPORT_LONG:
                self.parameters = stream.read(16)
        except:
            raise HIDPP20PacketError()

        if self.frame_type not in [HIDPP_REPORT_SHORT, HIDPP_REPORT_LONG]:
            raise HIDPP20PacketError()

    def __str__(self):
        return "HIDPPPacket(dev={}, sw={}, feat={}, fn={}, param={})".format(
            self.device_index,
            self.software_id,
            self.feature_index,
            self.function_id,
            "".join(["{:02x}".format(b) for b in self.parameters])
        )

class HIDPP(object):
    def __init__(self, software_id, device):
        assert(0 < software_id <= 15)
        self.software_id = software_id
        self.device = device
        self.ping_data = None

        self._device_index = 1
        self._last_packet = None

        self._feature_count = 0
        self._feature_table = {}

    @property
    def device_index(self):
        return self._device_index

    @device_index.setter
    def device_index(self, value):
        assert(value != 0)
        self._device_index = value

    def get_device_index(self):
        return self.device_index

    def make_packet(self, device_index, feature_index, function_id, parameters):
        assert(len(parameters) in [3, 16])
        assert(function_id <= 15)
        report_id = HIDPP_REPORT_SHORT if len(parameters)==3 else HIDPP_REPORT_LONG
        packet = bytearray()
        packet += struct.pack("> BBBB ",
                              report_id,
                              device_index,
                              feature_index,
                              ((function_id & 0x0f) << 4) | (self.software_id & 0xf),
                              )
        packet += parameters
        return packet

    def short_packet(self, feature_index, function_id, parameters):
        assert(len(parameters) <= 3)
        parameters += bytearray(3 - len(parameters))
        return self.make_packet(
            self._device_index,
            feature_index,
            function_id,
            parameters
        )

    def send_packet(self, feature_index, function_id, parameters, short=True):
        length = 3 if short else 16
        if parameters == None:
            parameters = bytearray()
        elif isinstance(parameters, list):
            parameters = bytearray(parameters)
        assert(len(parameters) <= length)
        parameters += bytearray(length - len(parameters))
        self._last_packet = self.make_packet(
            self._device_index,
            feature_index,
            function_id,
            parameters
        )
        self._last_feature_index = feature_index
        self._last_function_id = function_id
        self.device.send_hidpp_packet(self._last_packet)

    def long_packet(self, feature_index, function_id, parameters):
        assert(len(parameters) <= 16)
        parameters += bytearray(16 - len(parameters))
        return self.make_packet(
            self._device_index,
            feature_index,
            function_id,
            parameters
        )

    def hidpp20_request(self, feature, function, parameters=None):
        assert(self.has_feature(feature))
        feature_index = self.get_feature_index(feature)
        self.send_packet(feature_index, function, parameters)

    def hidpp20_request_long(self, feature, function, parameters=None):
        assert(self.has_feature(feature))
        feature_index = self.get_feature_index(feature)
        self.send_packet(feature_index, function, parameters, short=False)

    def get_response(self, version=2):
        attempts = 0
        while True:
            attempts += 1
            if attempts > 5:
                raise HIDPP20ProtocolError()

            packet_data = self.device.hid_read(timeout=2000)[:20]

            if isinstance(packet_data, bytearray):
                if packet_data[0] not in [0x10, 0x11, 0x50, 0x51]:
                    attempts -= 1
                    continue
                try:
                    packet = HIDPPPacket(packet_data)

                    is_bad = False
                    if version >= 2 and packet.software_id != self.software_id:
                        is_bad = True
                    if version >= 2 and packet.device_index != self._device_index:
                        is_bad = True
                    if self._last_feature_index and \
                            self._last_feature_index != packet.feature_index:
                        is_bad = True
                    if self._last_function_id and \
                            self._last_function_id != packet.function_id:
                        is_bad = True

                    if is_bad:
                        print(packet)
                        continue


                    self._last_function_id = None
                    self._last_feature_index = None
                    return packet
                except HIDPP20PacketError:
                    continue
            else:
                print("sending:", self._last_packet)
                self.device.send_hidpp_packet(self._last_packet)

    def GetFeature(self, feature_id):
        assert(feature_id != 0)
        self.send_packet(
            HIDPP20.ROOT,
            HIDPP20.Root.GetFeature,
            struct.pack('>HB', feature_id, 0)
        )

        resp = self.get_response()
        Resp = namedtuple('GetFeatureResp', 'featureIndex featureType')
        return Resp._make(struct.unpack('>BB', resp.parameters[:2]))


    def GetProtocolVersion(self):
        ping_data = random.randint(0, 255)
        attempts = 0
        while attempts < 5:
            attempts += 1

            self.send_packet(
                HIDPP20.ROOT,
                HIDPP20.Root.Ping,
                bytearray([0, 0, ping_data])
            )

            resp = self.get_response(version=1)

            if resp.parameters[2] != ping_data:
                continue

            Resp = namedtuple('ProtocolVersionResp', 'major minor')
            return Resp._make(struct.unpack('>BB', resp.parameters[:2]))

    # Technically, we should look up FEATURE_SET using the GetFeature command first.
    # However, in practice FEATURE_SET is afaik always has index 1.
    def FeatureSet_GetCount(self, feature_index=1):
        self.send_packet(
            feature_index,
            HIDPP20.FeatureSet.GetCount,
            bytearray([0, 0, 0])
        )
        resp = self.get_response()
        return resp.parameters[0]

    def FeatureSet_GetFeatureID(self, index, feature_index=1):
        self.send_packet(
            feature_index,
            HIDPP20.FeatureSet.GetFeatureID,
            bytearray([index, 0, 0])
        )
        resp = self.get_response()

        Resp = namedtuple('GetFeatureIDResp', 'featureID featureType')
        return Resp._make(struct.unpack('>HB', resp.parameters[0:0+3]))

    def Ping(self, device_index=1):
        self.GetProtocolVersion()

    def DeviceName_GetCount(self):
        self.hidpp20_request(HIDPP20.DEVICE_NAME, HIDPP20.DeviceName.GetCount)
        resp = self.get_response()
        return resp.parameters[0]

    def DeviceName_GetDeviceName(self, index):
        self.hidpp20_request(
            HIDPP20.DEVICE_NAME,
            HIDPP20.DeviceName.GetDeviceName,
            [index, 0, 0]
        )
        resp = self.get_response()
        return resp.parameters

    def DeviceName_GetDeviceType(self):
        self.hidpp20_request(
            HIDPP20.DEVICE_NAME,
            HIDPP20.DeviceName.GetDeviceType,
        )
        resp = self.get_response()
        return resp.parameters[0]

    def FirmwareInfo_GetEntityCount(self):
        self.hidpp20_request(
            HIDPP20.DEVICE_FW_VERSION,
            HIDPP20.FirmwareInfo.GetEntityCount,
        )
        resp = self.get_response()
        return resp.parameters[0]

    def FirmwareInfo_GetFwInfo(self, entity_id):
        self.hidpp20_request(
            HIDPP20.DEVICE_FW_VERSION,
            HIDPP20.FirmwareInfo.GetFwInfo,
            [entity_id]
        )
        resp = self.get_response()
        Resp = namedtuple('GetFwInfoResp', 'fwType fwPrefix fwVersion fwBuild xx transportLayer')
        return Resp._make(struct.unpack(">B 3s HH B 7s", resp.parameters))

    def BatteryLevelStatus_GetBatteryLevelStatus(self):
        self.hidpp20_request(
            HIDPP20.BATTERY_STATUS,
            HIDPP20.BatteryLevelStatus.GetBatteryLevelStatus,
        )
        resp = self.get_response()
        Resp = namedtuple('BatteryLevelStatusResp', 'level nextLevel status')
        result = Resp._make(struct.unpack(">BBB", resp.parameters[:3]))
        if not (
            (0 <= result.level <= 100) and
            (0 <= result.status <= 6) and
            (result.level > result.nextLevel)
        ):
            raise HIDPP20ProtocolError()
        else:
            return result

    def get_reprog_feature(self):
        """
        Get The highest known version for the SpecialKeysMSEButtons function
        """
        if self.has_feature(HIDPP20.REPROG_CONTROLS_V4):
            return HIDPP20.REPROG_CONTROLS_V4
        elif self.has_feature(HIDPP20.REPROG_CONTROLS_V3):
            return HIDPP20.REPROG_CONTROLS_V3
        elif self.has_feature(HIDPP20.REPROG_CONTROLS_V2_2):
            return HIDPP20.REPROG_CONTROLS_V2_2
        elif self.has_feature(HIDPP20.REPROG_CONTROLS_V2):
            return HIDPP20.REPROG_CONTROLS_V2
        elif self.has_feature(HIDPP20.REPROG_CONTROLS):
            return HIDPP20.REPROG_CONTROLS
        else:
            return None

    def has_reprog_feature(self, version=0):
        feature = self.get_reprog_feature()
        return (feature != None) and (feature >= HIDPP20.REPROG_CONTROLS+version)

    def SpecialKeysMSEButtons_GetCount(self):
        assert(self.has_reprog_feature())
        feature = self.get_reprog_feature()

        self.hidpp20_request(
            feature,
            HIDPP20.SpecialKeysMSEButtons.GetCount,
        )
        resp = self.get_response()
        return resp.parameters[0]

    def SpecialKeysMSEButtons_GetCtrlIdInfo(self, index):
        assert(self.has_reprog_feature())
        feature = self.get_reprog_feature()

        self.hidpp20_request(
            feature,
            HIDPP20.SpecialKeysMSEButtons.GetCtrlIdInfo,
            [index]
        )

        # Not sure exactly which features are supported in which version
        if feature >= HIDPP20.REPROG_CONTROLS_V3:
            resp = self.get_response()
            Resp = namedtuple('GetCtrlIdInfoResp',
                              'ctrlID taskID flags pos group gmask rawXY')
            result = Resp._make(struct.unpack(">HHBBBBB", resp.parameters[:9]))
            return result
        # elif feature >= HIDPP20.REPROG_CONTROLS_V3:
        #     resp = self.get_response()
        #     Resp = namedtuple('GetCtrlIdInfoResp',
        #                       'ctrlID taskID flags pos group gmask')
        #     result = Resp._make(struct.unpack(">HHBBBB", resp.parameters[:8]))
        #     return result
        else:
            resp = self.get_response()
            Resp = namedtuple('GetCtrlIdInfoResp', 'ctrlID taskID flags')
            result = Resp._make(struct.unpack(">HHB", resp.parameters[:5]))
            return result

    def SpecialKeysMSEButtons_SetCtrlIdReporting(
        self, cid, remap, divert, dvalid, persist, pvalid, rawXY, rvalid
    ):
        assert(self.has_reprog_feature(version=3))
        feature = self.get_reprog_feature()

        flags = (
            ((1 << 0) * divert) |
            ((1 << 1) * dvalid) |
            ((1 << 2) * persist) |
            ((1 << 3) * pvalid) |
            ((1 << 4) * rawXY ) |
            ((1 << 5) * rvalid)
        )

        self.hidpp20_request_long(
            feature,
            HIDPP20.SpecialKeysMSEButtons.SetCtrlIdReporting,
            struct.pack(">HBH", cid, flags, remap)
        )

        resp = self.get_response()
        return resp


    def ChangeHost_GetCount(self):
        self.hidpp20_request(
            HIDPP20.CHANGE_HOST,
            HIDPP20.ChangeHost.GetCount
        )
        resp = self.get_response()
        return resp.parameters[0]

    # Experimental
    def ChangeHost_SetHost(self, index):
        """
        index: 0 based host index

        NOTE: will automatically switch back to old host if a connect with the
        new host can't be established.
        """
        self.hidpp20_request(
            HIDPP20.CHANGE_HOST,
            HIDPP20.ChangeHost.SetHost,
            [index]
        )
        resp = self.get_response()
        return resp

    # Experimental
    def HostCapabilites_GetDevicePairingAbilities(self):
        self.hidpp20_request(
            HIDPP20.HOST_CAPABILITIES,
            HIDPP20.HostCapabilites.GetDevicePairingAbilities
        )
        resp = self.get_response()
        return resp.parameters

    # Experimental
    def HostCapabilites_GetHostInfo(self, index):
        self.hidpp20_request(
            HIDPP20.HOST_CAPABILITIES,
            HIDPP20.HostCapabilites.GetHostInfo,
            [index]
        )
        resp = self.get_response()
        return resp.parameters

    def test_feature(self, feature, function, parameters = None):
        parameters = parameters or []
        self.hidpp20_request(
            feature,
            function,
            parameters
        )
        return self.get_response()

    def has_feature(self, featureID):
        return featureID in self._feature_table

    def get_feature_index(self, featureID):
        if featureID in self._feature_table:
            return self._feature_table[featureID][0]
        else:
            return HIDPP20.ERROR_INDEX

    def build_feature_table(self):
        self._feature_count = self.FeatureSet_GetCount()
        for index in range(1, self._feature_count):
            feature = self.FeatureSet_GetFeatureID(index)
            self._feature_table[feature.featureID] = (index, feature.featureType)

    def get_device_name(self):
        name_length = self.DeviceName_GetCount()
        name = bytearray()
        while len(name) < name_length:
            name += self.DeviceName_GetDeviceName(len(name))
        return name[:name_length]
