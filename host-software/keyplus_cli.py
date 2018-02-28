#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import absolute_import, division, print_function, unicode_literals

import intelhex
import argparse
import yaml
import hexdump
import sys
import colorama
from colorama import Fore, Style

import layout.parser
import datetime
import sys

import keyplus
from keyplus.layout import KeyplusLayout
from keyplus.device_info import KeyboardDeviceTarget

from keyplus.exceptions import *
from keyplus.constants import *

__version__ = keyplus.__version__

EXIT_NO_ERROR = 0
EXIT_COMMAND_ERROR = 1
EXIT_MATCH_DEVICE = 2
EXIT_UNSUPPORTED_FEATURE = 3
EXIT_BAD_FILE = 4
EXIT_INSUFFICIENT_SPACE = 5

def print_hid_info(hid_device):
    print("{:x}:{:x} | {} | {} | {}"
        .format(
            hid_device.vendor_id,
            hid_device.product_id,
            hid_device.manufacturer_string,
            hid_device.product_string,
            hid_device.serial_number,
        )
    )

def timestamp_to_string(tstamp):
    timestamp_str = "<Unavailable>"
    if tstamp != 0:
        build_date = datetime.datetime.fromtimestamp(tstamp)
        timestamp_str = str(build_date)
    return timestamp_str

def print_device_info(device_info, indent="  "):
    print(indent, "id: ", device_info.device_id)
    print(indent, "name: '{}'".format(device_info.get_name_str()) )
    print(indent, "layout last updated: ", timestamp_to_string(device_info.timestamp_raw))
    print(indent, "default_report_mode: ", device_info.get_default_report_mode_str())
    print(indent, "scan_mode: ", device_info.scan_plan.mode)
    print(indent, "row_count: ", device_info.scan_plan.rows)
    print(indent, "col_count: ", device_info.scan_plan.cols)

def print_firmware_info(device, indent="  "):
    fw_info = protocol.get_firmware_info(device)
    print(indent, "build time: ", timestamp_to_string(fw_info.timestamp_raw))
    print(indent, "git_hash: {:08x}".format(fw_info.git_hash))

def print_all_info(kb_device):
    print_hid_info(kb_device.hid_device)
    print_device_info(kb_device.device_info)



# Generic Command
class GenericCommand(object):
    def __init__(self, description):

        command_name = ""
        for name in KeyplusCLI.COMMAND_NAME_MAP:
            if KeyplusCLI.COMMAND_NAME_MAP[name] == self.__class__:
                command_name = name

        command_name = sys.argv[0] + " " + command_name

        self.arg_parser = argparse.ArgumentParser(
            prog=command_name,
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
            '-i', '--id', dest='device_id', type=int, default=None,
            help='The id of the device to program'
        )

        self.arg_parser.add_argument(
            '-s', '--serial', dest='serial', type=str, default=None,
            help='Serial number of the USB device to use. Can be a partial match.'
        )

        self.arg_parser.add_argument(
            '-d', '--vid-pid', dest='vid_pid', type=str, default=None,
            help='Open a device based on a vid_pid pair'
        )

        self.arg_parser.add_argument(
            '-n', dest='name', type=str, default=None,
            help='Name of the USB device to use. Can be a partial match.'
        )

    def find_matching_device(self, args, multiple_matches=False):
        matching_devices = keyplus.find_devices(
            name = args.name,
            device_id = args.device_id,
            vid_pid = args.vid_pid,
            serial_number = args.serial,
        )
        num_matches = len(matching_devices)

        if multiple_matches:
            return matching_devices

        if num_matches== 0:
            print("Couldn't find any matching devices.", file=sys.stderr)
            exit(EXIT_MATCH_DEVICE)
        elif num_matches == 1:
            return matching_devices[0]
        elif num_matches > 1:
            print("Error: found {} matching devices, select a specifc device or "
                  "disconnect the other devices".format(num_matches), file=sys.stderr)
            exit(EXIT_MATCH_DEVICE)

    def task(self, args):
        pass


# Hexdump of raw debug output
class DebugCommand(GenericDeviceCommand):
    def __init__(self):
        super(DebugCommand, self).__init__(
            'Shows raw debug output as a hexdump'
        )

    def task(self, args):
        kb = self.find_matching_device(args)
        print_all_info(kb)

        with kb:
            kb.listen_raw()


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

        self.arg_parser.add_argument(
            '-V', dest='verbose', action='store_const',
            const=True, default=False,
            help='Verbose output'
        )

    def task(self, args):

        kb = self.find_matching_device(args)

        with kb:
            try:
                kb.set_passthrough_mode(True)
            except KeyplusUSBCommandError as err:
                if err.error_code == KeyplusUSBCommandError.ERROR_UNSUPPORTED_COMMAND:
                    print("Target device doesn't support matrix scanning", file=sys.stderr)
                    exit(EXIT_UNSUPPORTED_FEATURE)
                raise err
            passthrough_timeout = 10000

            response = kb.read(timeout=passthrough_timeout)

            while response != None:
                if response[0] == CMD_PASSTHROUGH_MATRIX:
                    if (args.verbose):
                        hexdump.hexdump(response[1:])
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
                response = kb.read(timeout=passthrough_timeout)

            kb.set_passthrough_mode(False)

# List connected USB devices
class ListCommand(GenericDeviceCommand):
    def __init__(self):
        super(ListCommand, self).__init__(
            'List the connected keyplus devices'
        )

        self.arg_parser.add_argument(
            '--verbose', '-v', action='count', dest='verbosity',
            help='Verbose device information'
        )

    def task(self, args):
        kb_devices = self.find_matching_device(args, multiple_matches=True)

        for kb_device in kb_devices:
            print_hid_info(kb_device.hid_device)
            if args.verbosity != None:
                if args.verbosity >= 1:
                    print_device_info(kb_device.device_info)

# Test command for controlling LEDs
class LEDCommand(GenericDeviceCommand):
    def __init__(self):
        super(LEDCommand, self).__init__(
            'Set the state of the indicator LED'
        )

        self.arg_parser.add_argument(
            'led_number', type=int,
            help="Led number to set"
        )

        self.arg_parser.add_argument(
            'led_state', type=int,
            help="State to set the led: 0->off, 1->on"
        )

    def task(self, args):
        kb = self.find_matching_device(args)
        with kb:
            kb.set_indicator_led(args.led_number, args.led_state)

# Test command for controlling LEDs
class ResetCommand(GenericDeviceCommand):
    def __init__(self):
        super(ResetCommand, self).__init__(
            'Reset the target device'
        )

    def task(self, args):
        kb = self.find_matching_device(args)
        with kb:
            kb.reset()

# Enter the devices bootloader
class BootloaderCommand(GenericDeviceCommand):
    def __init__(self):
        super(BootloaderCommand, self).__init__(
            'Run the bootloader of the target device'
        )

    def task(self, args):
        kb = self.find_matching_device(args)
        with kb:
            kb.enter_bootloader()

class HelpCommand(GenericCommand):
    def __init__(self):
        super(HelpCommand, self).__init__(
            'Prints help for the given command'
        )

        self.arg_parser.add_argument(
            'command_name', type=str, default=None, nargs='?',
            help='The command to provide help for'
        )

    def task(self, args):
        if args.command_name == None:
            self.arg_parser.print_help()
            exit(EXIT_NO_ERROR)

        if args.command_name in KeyplusCLI.COMMAND_NAME_MAP:
            cmd = KeyplusCLI.COMMAND_NAME_MAP[args.command_name]()
            cmd.arg_parser.print_help()
        else:
            print("Error: Can't find help for unknown command " +
                  str(args.command_name), file=sys.stderr)


class ProgramCommand(GenericDeviceCommand):
    def __init__(self):
        super(ProgramCommand, self).__init__(
            'Program layout, rf settings and hex files'
        )

        self.arg_parser.add_argument(
            '-l', '--layout', dest='layout_file', type=str, default=None,
            help='The layout file to program'
        )

        self.arg_parser.add_argument(
            '-r', '--rf', dest='rf_file', type=str, default=None,
            help='The rf file to program'
        )

        self.arg_parser.add_argument(
            '-I', '--new-id', dest='new_id', type=int, default=None,
            help='Gives the device a new device ID (requires both a layout file '
            ' and a rf file)'
        )

        self.arg_parser.add_argument(
            '-x', '--fw-hex', dest='hex_file', type=str, default=None,
            help='TODO firmware hex file'
        )

        self.arg_parser.add_argument(
            '-M', '--merge-hex', dest='merge_hex',
            type=lambda x: int(x, 0), # integer of any base
            nargs='+', default=None,
            help='For use in build scripts. Don\'t actually program the device,'
            ' instead use the arguments provided to construct a firmware hexfile'
            ' with the given settings pre-programmed. In addition to the other'
            ' settings fields this flag takes 3 arguments: '
            ' [settings_addr, layout_addr, layout_size]'
            ' which determine where the layout will be placed in the result hex.'
        )

        self.arg_parser.add_argument(
            '-o', '--outfile', dest='outfile',
            type=str, default=None,
            help='The file written by the -M flag. If no file is given, print'
            ' to stdoutput'
        )

    def task(self, args):
        if (
            args.layout_file == None and
            args.hex_file == None and
            args.rf_file == None and
            args.new_id == None
        ):
            self.arg_parser.print_help()
            exit(EXIT_NO_ERROR)

        if args.merge_hex:
            self.task_mereged_hex(args)
        else:
            self.task_program_device(args)

    def load_layout_file(self, args):
        try:
            kp_layout = KeyplusLayout()
            kp_layout.from_yaml_file(
                layout_file = args.layout_file,
                rf_file = args.rf_file,
                print_warnings = True,
            )
            return kp_layout
        except Exception as err:
            print(ERROR_COLOR + "Error: " + Style.RESET_ALL + str(err))
            exit(EXIT_BAD_FILE)

    def task_mereged_hex(self, args):
        if (
            args.new_id == None or
            args.layout_file == None or
            args.rf_file == None
        ):
            print("Error: To generate a merged hex file, need all settings"
                    " files.", file=sys.stderr)
            exit(EXIT_COMMAND_ERROR)

        if len(args.merge_hex) != 3:
            print("Error: To generate a merged hex file, need to provide "
                    "[settings_addr, layout_addr, layout_size] as arguments",
                    file=sys.stderr)
            exit(EXIT_COMMAND_ERROR)

        kp_layout = self.load_layout_file(args)

        # don't want to program the device, instead we want to build a
        # hexfile with the settings preprogrammed
        with open(args.hex_file) as f:
            fw_hex = intelhex.IntelHex(f)

        settings_addr = args.merge_hex[0]
        layout_addr = args.merge_hex[1]
        layout_size = args.merge_hex[2]

        # TODO: build device target from command line parameters
        device_target = KeyboardDeviceTarget()
        raise Exception("not implement yet")

        settings_data = kp_layout.build_layout_section(device_target)
        layout_data = kp_layout.build_settings_section(device_target)

        if len(layout_data) > layout_size:
            print("Error: layout data to large. Got {} bytes, but only "
                    "{} bytes available".format(
                        len(layout_data),
                        layout_size
                    ), file=sys.stderr)
            exit(EXIT_INSUFFICIENT_SPACE)

        settings_hex = intelhex.IntelHex()
        settings_hex.frombytes(
            settings_data,
            offset = settings_addr
        )

        layout_hex = intelhex.IntelHex()
        layout_hex.frombytes(
            layout_data,
            offset = layout_addr
        )


        fw_hex.merge(settings_hex, overlap='replace')

        # first erase anything that is in the layout section
        for i in range(layout_addr, layout_addr+layout_size):
            fw_hex[i] = 0 # dummy, write so del always works
            del fw_hex[i]

        fw_hex.merge(layout_hex, overlap='replace')

        if args.outfile:
            with open(args.outfile, 'w') as outfile:
                fw_hex.write_hex_file(outfile)
        else:
                fw_hex.write_hex_file(sys.stdout)
        exit(EXIT_NO_ERROR)

    def task_program_device(self, args):

        kb = self.find_matching_device(args)

        with kb:
            print("Programing start...")
            print_all_info(kb)
            print("")

            device_target = kb.get_device_target()

            # Set the target device id
            if args.new_id:
                device_target.device_id = args.new_id

            # If only a new id was provide, update the old settings section
            # with just the new id.
            if (
                args.layout_file == None and
                args.rf_file == None and
                args.new_id
            ):
                settings = kb.read_settings_section()
                settings.header.device_id = args.new_id
                kb.update_settings_section(settings, keep_rf=True)
                exit(EXIT_NO_ERROR)


            kp_layout = self.load_layout_file(args)

            # If this command is running, we always update the layout section
            settings = kp_layout.build_settings_section(device_target)

            update_rf = False
            if args.rf_file:
                update_rf = True

            kb.update_settings_section(settings, update_rf)

            # only update the layout section if a layout file was given
            if args.layout_file:
                layout = kp_layout.build_layout_section(device_target)
                kb.update_layout_section(layout)

            kb.reset()



class PairCommand(GenericDeviceCommand):
    def __init__(self):
        super(PairCommand, self).__init__(
            'Put the device into pairing mode'
        )

    def task(self, args):
        kb = self.find_matching_device(args)
        with kb:
            kb.enter_pairing_mode()

class KeyplusCLI(object):
    COMMAND_NAME_MAP = {
        "bootloader": BootloaderCommand,
        "debug": DebugCommand,
        "led": LEDCommand,
        "list": ListCommand,
        "passthrough": PassthroughCommand,
        "reset": ResetCommand,
        "program": ProgramCommand,
        "pair": PairCommand,
        # "layers": LayerCommand(),
        "help": HelpCommand,
    }

    def __init__(self):

        command_list = {
            "bootloader": BootloaderCommand(),
            "debug": DebugCommand(),
            "led": LEDCommand(),
            "list": ListCommand(),
            "passthrough": PassthroughCommand(),
            "reset": ResetCommand(),
            "program": ProgramCommand(),
            "pair": PairCommand(),
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
            command_list[args.command].run()
        else:
            print('Unrecognized command: {}'.format(args.command), file=sys.stderr)
            parser.print_help()
            exit(EXIT_COMMAND_ERROR)
        exit(EXIT_NO_ERROR)


if __name__ == "__main__":
    colorama.init()
    KeyplusCLI()
