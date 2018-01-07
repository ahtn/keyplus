#!/usr/bin/env python
# -*- coding: utf-8 -*-


from __future__ import print_function, division

import intelhex
import argparse

import time, math, sys, datetime
import protocol, easyhid

__version_info__ = (0, 0, 1)
__version__ = '.'.join([str(i) for i in __version_info__])


def print_hid_info(device):
    print("{:x}:{:x} | {} | {} | {}"
        .format(
            device.vendor_id,
            device.product_id,
            device.manufacturer_string,
            device.product_string,
            device.serial_number,
        )
    )

def timestamp_to_string(tstamp):
    timestamp_str = "<Unavailable>"
    if tstamp != 0:
        build_date = datetime.datetime.fromtimestamp(tstamp)
        timestamp_str = str(build_date)
    return timestamp_str

def print_device_info(device, indent="  "):
    dev_info = protocol.get_device_info(device)
    print(indent, "id: ", dev_info.id)
    print(indent, "name: '{}'".format(dev_info.device_name_str()) )
    print(indent, "layout last updated: ", dev_info.timestamp_str())
    print(indent, "default_report_mode: ", dev_info.default_report_mode_str())
    print(indent, "scan_mode: ", dev_info.scan_mode)
    print(indent, "row_count: ", dev_info.row_count)
    print(indent, "col_count: ", dev_info.col_count)

def print_layout_info(device, indent="  "):
    layout_info = protocol.get_layout_info(device)
    print(indent, "number_devices: ", layout_info.number_devices)
    print(indent, "number_layouts: ", layout_info.number_layouts)

def print_firmware_info(device, indent="  "):
    fw_info = protocol.get_firmware_info(device)
    print(indent, "build time: ", timestamp_to_string(fw_info.timestamp))
    print(indent, "git_hash: {:08x}".format(fw_info.git_hash))

def print_all_info(device):
    print_hid_info(device)
    print_device_info(device)
    print_layout_info(device)
    print("firmware info:")
    print_firmware_info(device)

# Generic Command
class GenericCommand(object):
    def __init__(self, description):
        self.arg_parser = argparse.ArgumentParser(
            description=description
        )
        self.description = description

    def task(self, args):
        pass

    def run(self):
        # Get the args after the command
        args = self.arg_parser.parse_args(sys.argv[2:])

        self.task(args)

    def help(self):
        pass

# Commands that target a specific device, and includes arguments and functions
# to find the targeted device.
class GenericDeviceCommand(GenericCommand):
    def __init__(self, description):
        super(GenericDeviceCommand, self).__init__(description)

        self.arg_parser.add_argument(
            '-s', dest='serial', type=str, default=None,
            help='Serial number of the USB device to use. If there is no exact '
            'match, looks for partial matches.'
        )

        self.arg_parser.add_argument(
            '-d', dest='vid_pid', type=str, default=None,
            help='Open a device based on a vid_pid pair'
        )

        self.arg_parser.add_argument(
            '-n', dest='name', type=str, default=None,
            help='Name of the USB device to use. If there is no exact '
            'match, look for partial matches.'
        )

    def get_similar_serial_number(self, dev_list, serial):
        partial_match = None
        partial_match_pos = None
        for dev in dev_list.find():
            if dev.serial_number == serial:
                # found an exact match
                return serial
            elif partial_match == None:
                # didn't find an exact match, so keep track of partial matches
                match_pos = dev.serial_number.find(serial)

                # no match, ignore
                if match_pos == -1:
                    continue

                # update the best match we found, prioritize serial numbers
                # that match near the start of the string
                if partial_match_pos == None or match_pos < partial_match_pos:
                    partial_match = dev.serial_number
                    partial_match_pos = match_pos

        if partial_match:
            return partial_match
        else:
            return serial

    def find_matching_device(self, args):
        hid_list = easyhid.Enumeration()

        target_vid = protocol.DEFAULT_VID
        target_pid = None

        if args.vid_pid:
            matches = args.vid_pid.split(":")
            if len(matches) == 1:
                try:
                    target_vid = int(matches[0], base=16)
                    if target_vid > 0xffff: raise Exception
                except:
                    print("Bad VID/PID pair: " + args.vid_pid, file=sys.stderr)
                    exit(2)
            elif len(matches) == 2:
                try:
                    if matches[0] == '':
                        target_vid = None
                    else:
                        target_vid = target_vid = int(matches[0], base=16)
                    if matches[1] == '':
                        target_pid = None
                    else:
                        target_pid = target_pid = int(matches[1], base=16)
                    if target_vid and target_vid > 0xffff: raise Exception
                    if target_pid and target_pid > 0xffff: raise Exception
                except:
                    print("Bad VID/PID pair: " + args.vid_pid, file=sys.stderr)
                    exit(2)

        if args.serial != None:
            args.serial = self.get_similar_serial_number(hid_list, args.serial)

        matching_devices = hid_list.find(
            vid=target_vid,
            pid=target_pid,
            serial=args.serial,
            interface=3
        )

        if len(matching_devices) == 0:
            print("Couldn't find a matching device to open", file=sys.stderr)
            exit(1)

        return matching_devices[0]

    def task(self, args):
        pass

# Hexdump of raw debug output
class DebugCommand(GenericDeviceCommand):
    def __init__(self):
        super(DebugCommand, self).__init__(
            'Shows raw debug output as a hexdump'
        )

    def task(self, args):
        device = self.find_matching_device(args)

        device.open()
        print_all_info(device)
        protocol.listen_raw(device)


# Prints matrix (row,col) pairs of pressed keys to stdout of a connected USB device
class PassthroughCommand(GenericDeviceCommand):
    def __init__(self):
        super(PassthroughCommand, self).__init__(
            'Prints the matrix row and column pairs of pressed keys. '
        )

        self.arg_parser.add_argument(
            'enable', nargs='?',
            help='Set passthrough state "on" or "off"'
        )

    def task(self, args):

        device = self.find_matching_device(args)
        device.open()

        try:
            protocol.set_passthrough_mode(device, 1)
        except protocol.KBProtocolException as err:
            if err.error_code == protocol.ProtocolError.ERROR_UNSUPPORTED_COMMAND:
                print("Target device doesn't support matrix scanning", file=sys.stderr)
                exit(3)
            raise err
        passthrough_timeout = 10000

        response = device.read(timeout=passthrough_timeout)

        while response != None:
            if response[0] == protocol.CMD_PASSTHROUGH_MATRIX:
                for row in range(10):
                    for col in range(2):
                        byte = response[1 + row*2 + col]
                        if byte == 0:
                            continue
                        else:
                            for i in range(8):
                                if byte & (1 << i):
                                    row_num = row
                                    col_num = col * 8 + i
                                    print("r{}c{} ".format(row_num, col_num), end="")
                print("")

            response = device.read(timeout=passthrough_timeout)

        protocol.set_passthrough_mode(device, 0)
        device.close()

# List connected USB devices
class ListCommand(GenericCommand):
    def __init__(self):
        super(ListCommand, self).__init__(
            'List the connected keyplus devices'
        )

        self.arg_parser.add_argument(
            '--verbose', '-v', action='count', dest='verbosity',
            help='Verbose device information'
        )

    def task(self, args):
        dev_list = easyhid.Enumeration().find(
            interface=3
        )
        for dev in dev_list:
            print_hid_info(dev)
            if args.verbosity != None:
                dev.open()
                if args.verbosity >= 1:
                    print_device_info(dev)
                    print_layout_info(dev)

# Test command for controlling LEDs
class LEDCommand(GenericDeviceCommand):
    def __init__(self):
        super(LEDCommand, self).__init__(
            'Set the state of the indicator LED'
        )

        self.arg_parser.add_argument(
            'led_state', type=int,
            help="State to set the led: 0->off, 1->on"
        )

    def task(self, args):
        device = self.find_matching_device(args)
        device.open()
        protocol.set_indicator_led(device, args.led_state)
        device.close()

# Test command for controlling LEDs
class ResetCommand(GenericDeviceCommand):
    def __init__(self):
        super(ResetCommand, self).__init__(
            'Reset the target device'
        )

    def task(self, args):
        device = self.find_matching_device(args)
        device.open()
        protocol.reset_device(device)
        device.close()

# Enter the devices bootloader
class BootloaderCommand(GenericDeviceCommand):
    def __init__(self):
        super(BootloaderCommand, self).__init__(
            'Run the bootloader of the target device'
        )

    def task(self, args):
        device = self.find_matching_device(args)
        device.open()
        protocol.enter_bootloader(device)
        device.close()

class HelpCommand(GenericDeviceCommand):
    def __init__(self):
        super(HelpCommand, self).__init__(
            'Prints help for the given command'
        )

class Keyer:
    def __init__(self):

        command_list = {
            "bootloader": BootloaderCommand(),
            "debug": DebugCommand(),
            "led": LEDCommand(),
            "list": ListCommand(),
            "passthrough": PassthroughCommand(),
            "reset": ResetCommand(),
            # "layers": LayerCommand(),
            "help": HelpCommand(),
        }

        command_list_string = "\n".join(["    {0: <16}{1:}".format(cmd, command_list[cmd].description) for cmd in command_list])

        usage_string = "%(prog)s <command> [<args>]\n\n" + \
        "Where command is one of the options listed below.\n" + command_list_string

        parser = argparse.ArgumentParser(
            description='keyplus keyboard control tool',
            usage=usage_string
        )

        parser.add_argument('command', help='Subcommand to run')

        parser.add_argument('-v', '--version', action='version',
                            version="%(prog)s: "+__version__)
        # parse_args defaults to [1:] for args, but you need to
        # exclude the rest of the args too, or validation will fail
        args = parser.parse_args(sys.argv[1:2])

        if args.command in command_list:
            if args.command == "help":
                if len(sys.argv) < 3:
                    parser.print_help()
                else:
                    cmd = sys.argv[2]
                    if cmd in command_list:
                        command_list[cmd].help()
                    else:
                        print('Unrecognized command: {}'.format(cmd), file=sys.stderr)
            else:
                command_list[args.command].run()
        else:
            print('Unrecognized command: {}'.format(args.command), file=sys.stderr)
            parser.print_help()
            exit(1)
        exit(0)


if __name__ == "__main__":
    Keyer()
