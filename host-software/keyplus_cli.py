#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import absolute_import, division, print_function, unicode_literals

import intelhex
import argparse
import yaml
import hexdump
import sys

import layout.parser
import protocol

import keyplus

from keyplus.exceptions import KeyplusUSBCommandError
from keyplus.constants import *

from keyplus_cli.common import *

__version_info__ = (0, 2, 2)
__version__ = '.'.join([str(i) for i in __version_info__])

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
                    # print_layout_info(kb_device.layout_info)

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
            exit(0)

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

    def process_layout(self, layout_json_obj, rf_json, layout_file, device_id):
        try:
            settings_gen = layout.parser.SettingsGenerator(layout_json_obj, rf_json)
            if not settings_gen.has_id(device_id):
                print(
                    'Error parsing "{}": No device with id {}'.format(
                        layout_file,
                        device_id
                    ),
                    file=sys.stderr
                )
                exit(EXIT_BAD_FILE)
            layout_data = settings_gen.gen_layout_section(device_id)
            settings_data = settings_gen.gen_settings_section(device_id)
            return layout_data, settings_data
        except (layout.parser.ParseError, layout.parser.ParseKeycodeError) as err:
            print(
                'Error parsing "{}": {}'.format(layout_file, str(err)),
            )
            exit(EXIT_BAD_FILE)

    def task(self, args):
        layout_file = args.layout_file
        rf_file = args.rf_file
        hex_file = args.hex_file
        new_id = args.new_id

        if args.merge_hex:
            if (new_id == None or layout_file == None or rf_file == None or \
                    new_id == None):
                print("Error: To generate a merged hex file, need all settings"
                        " files.", file=sys.stderr)
                exit(EXIT_COMMAND_ERROR)
            if len(args.merge_hex) != 3:
                print("Error: To generate a merged hex file, need to provide "
                      "[settings_addr, layout_addr, layout_size] as arguments",
                      file=sys.stderr)
                exit(EXIT_COMMAND_ERROR)


        if new_id != None and (layout_file == None or rf_file == None):
            print("Error: when providing a new ID, a layout and RF file "
                  "must be provided", file=sys.stderr)
            exit(EXIT_COMMAND_ERROR)

        if layout_file == None and hex_file == None and rf_file == None:
            self.arg_parser.print_help()
            exit(0)


        if not args.merge_hex:
            device = self.find_matching_device(args)

            device.open()
            print("Programing start...")
            print_hid_info(device)
            print_device_info(device)
            print_layout_info(device)
            print("")


        if layout_file != None:
            with open(layout_file) as file_obj:
                try:
                    layout_json_obj = yaml.safe_load(file_obj.read())
                # except yaml.YAMLError as err:
                except Exception as err:
                    print("Error in Layout Settings YAML file: " + str(err), file=sys.stderr)
                    device.close()
                    exit(EXIT_BAD_FILE)
        else:
            layout_json_obj = None

        if rf_file != None:
            with open(rf_file) as file_obj:
                try:
                    rf_json_obj = yaml.safe_load(file_obj.read())
                # except yaml.YAMLError as err:
                except Exception as err:
                    print("Error in RF Settings YAML file: " + str(err), file=sys.stderr)
                    device.close()
                    exit(EXIT_BAD_FILE)
        else:
            rf_json_obj = None

        if layout_file != None:
            print("Parsing files...")

            if not args.merge_hex:
                device_info = protocol.get_device_info(device)

            if new_id == None:
                target_id = device_info.id
            else:
                target_id = new_id

            layout_data, settings_data = self.process_layout(
                layout_json_obj,
                rf_json_obj,
                layout_file,
                target_id
            )
            if layout_data == None or settings_data == None:
                exit(EXIT_BAD_FILE)
            print("Parsing finished...")

        if args.merge_hex:
            # don't want to program the device, instead we want to build a
            # hexfile with the settings preprogrammed
            with open(hex_file) as f:
                fw_hex = intelhex.IntelHex(f)

            settings_addr = args.merge_hex[0]
            layout_addr = args.merge_hex[1]
            layout_size = args.merge_hex[2]

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
                fw_hex[i] = 0 # dummy, write so del works
                del fw_hex[i]

            fw_hex.merge(layout_hex, overlap='replace')

            if args.outfile:
                with open(args.outfile, 'w') as outfile:
                    fw_hex.write_hex_file(outfile)
            else:
                    fw_hex.write_hex_file(sys.stdout)
            exit(0)
        elif layout_file and not rf_file:
            print("Updating layout only...")
            protocol.update_settings_section(device, settings_data, keep_rf=True)
            protocol.update_layout_section(device, layout_data)
        elif layout_file and rf_file:
            print("Updating layout and rf settings...")
            protocol.update_settings_section(device, settings_data)
            protocol.update_layout_section(device, layout_data)
        elif layout_file and rf_file and hex_file:
            print("TODO: not implemented", file=sys.stderr)
        elif hex_file and not layout_file and not rf_file:
            print("TODO: not implemented", file=sys.stderr)
        else:
            pass

        print("Done!")

        protocol.reset_device(device)
        device.close()

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
        exit(0)


if __name__ == "__main__":
    KeyplusCLI()
