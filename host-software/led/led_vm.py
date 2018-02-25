#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

from __future__ import absolute_import, division, print_function, unicode_literals


from sexpr import sexp
import pprint
import copy
import hexdump

DEBUG = 0

def u8(x):
    return x & 0xff

def i16(x):
    return x & 0xffff

class LEDVMError(Exception):
    pass

class OpCodeInfo(object):
    def __init__(self, name, data_len, arg_type):
        self.name = name
        self.data_len = data_len
        self.arg_type = arg_type

    ARG_NONE = 0
    ARG_REFRENCES = 1

class OpCode(object):
    SHOW_HSV   = 0x00
    SHOW_RGB   = 0x01
    LOAD_PIXEL = 0x02
    ADD_VEC3   = 0x03
    SUB_VEC3   = 0x04
    IF_EQ      = 0x05

    OP_CODE_TABLE = {
        # CODE  , MENOMIC   , DATA_SIZE
        SHOW_HSV   : OpCodeInfo("SHOW_HSV"   , 0 , OpCodeInfo.ARG_NONE)      ,
        SHOW_RGB   : OpCodeInfo("SHOW_RGB"   , 0 , OpCodeInfo.ARG_NONE)      ,
        LOAD_PIXEL : OpCodeInfo("LOAD_PIXEL" , 3 , OpCodeInfo.ARG_REFRENCES) ,
        ADD_VEC3   : OpCodeInfo("ADD_VEC3"   , 3 , OpCodeInfo.ARG_REFRENCES) ,
        SUB_VEC3   : OpCodeInfo("SUB_VEC3"   , 3 , OpCodeInfo.ARG_REFRENCES) ,
        IF_EQ      : OpCodeInfo("IF_EQ"      , 3 , OpCodeInfo.ARG_REFRENCES) ,
    }

    @staticmethod
    def to_string(code):
        if code in OpCode.OP_CODE_TABLE:
            name = OpCode.OP_CODE_TABLE[code].name
            return "{}<{}>".format(name, code)
        else:
            return "{}<{}>".format("UnknownOpCode", code)

    def __init__(self, name, data_len=0):
        self.name = name
        self.data_len = data_len

class Register(object):
    # Register codes
    PIXEL_NUM = 0
    OUTPUT_TYPE = 1
    KEY_STATE = 2
    MOUSE_X   = 3
    MOUSE_Y   = 4

    OUTPUT_TYPE_RGB = 0
    OUTPUT_TYPE_HSV = 1

    def __init__(self, name, default_value=0):
        self.name = name
        self.value = default_value
        self.default_value = default_value


class LEDEffectVM(object):
    REGISTER_TABLE = {
        Register.PIXEL_NUM   : Register("PIXEL_NUM",   0),
        Register.OUTPUT_TYPE : Register("OUTPUT_TYPE", 0),
        Register.KEY_STATE   : Register("KEY_STATE",   0),
        Register.MOUSE_X     : Register("MOUSE_X",     0),
        Register.MOUSE_Y     : Register("MOUSE_Y",     0),
    }

    def __init__(self, led_program_table={'main': []}, num_pixels=None):
        self.pixels = [(0, 0, 0)] * num_pixels
        self.led_program_table = led_program_table
        self.set_active_progarm('main')
        self.instr_ptr = 0
        self.registers = {}
        for reg in self.REGISTER_TABLE:
            self.registers[reg] = self.REGISTER_TABLE[reg].default_value

    def set_active_progarm(self, name):
        self._current_program_name = name
        self.current_program = self.led_program_table[name]

    def goto_start(self):
        self.instr_ptr = 0

    def rel_jump(self, offset):
        self.instr_ptr += (offset)

    def get_next_word(self):
        if self.instr_ptr >= len(self.current_program):
            return None
        result = self.current_program[self.instr_ptr]
        self.instr_ptr += 1
        return result

    def read_op_code(self):
        code = self.get_next_word()
        if code == None:
            return None, None

        self.vm_assert(code in OpCode.OP_CODE_TABLE, "Invalid OpCode: {}".format(code))
        op_code = OpCode.OP_CODE_TABLE[code]

        data = []
        for i in range(op_code.data_len):
            data.append(self.get_next_word())

        # if DEBUG >= 1
        if DEBUG >= 5:
            print("Instruction: {}".format(self.instr_ptr))
            print("Current code: {}, data:{}".format(
                    OpCode.to_string(code), data
                )
            )

        return code, data

    REFERENCE_TYPE_IMMEDIATE = 0
    REFERENCE_TYPE_REGISTER = 1
    REFERENCE_TYPE_PIXEL = 2

    def lookup_refrence(self, ref):
        # Refrences either an immediate value or another register value
        # Format of refrence values (in hex):
        #  * 00xx -> Single byte immediate value
        #  * 01xx -> Single byte immediate value
        value    = (ref >> 0) & 0xff
        ref_type = (ref >> 8) & 0xff
        if ref_type == self.REFERENCE_TYPE_IMMEDIATE:
            return value
        elif ref_type == self.REFERENCE_TYPE_PIXEL:
            assert(value < 3)
            return self.get_current_pixel()[value]
        elif ref_type == self.REFERENCE_TYPE_REGISTER:
            assert(value in self.REGISTER_TABLE)
            return self.registers[value]


    def get_pixel(self, pixel_num):
        return self.pixels[pixel_num]

    def get_pixel_type(self, pixel_num):
        return self.registers[Register.OUTPUT_TYPE]

    def get_current_pixel(self):
        return self.pixels[self.registers[Register.PIXEL_NUM]]

    def set_current_pixel(self, x, y, z):
        self.pixels[self.registers[Register.PIXEL_NUM]] = (x, y, z)

    def execute_op_code(self, code, data):
        """
        Return True if the program has finished executing
        """
        if code == OpCode.SHOW_HSV:
            self.registers[Register.OUTPUT_TYPE] = Register.OUTPUT_TYPE_HSV
            return True
        elif code == OpCode.SHOW_RGB:
            self.registers[Register.OUTPUT_TYPE] = Register.OUTPUT_TYPE_RGB
            return True
        elif code == OpCode.LOAD_PIXEL:
            self.set_current_pixel(
                self.lookup_refrence(data[0]),
                self.lookup_refrence(data[1]),
                self.lookup_refrence(data[2])
            )
        elif code == OpCode.ADD_VEC3:
            old_value = self.get_current_pixel()
            self.set_current_pixel(
                u8(old_value[0] + self.lookup_refrence(data[0])),
                u8(old_value[1] + self.lookup_refrence(data[1])),
                u8(old_value[2] + self.lookup_refrence(data[2]))
            )
        elif code == OpCode.SUB_VEC3:
            old_value = self.get_current_pixel()
            self.set_current_pixel(
                u8(old_value[0] - self.lookup_refrence(data[0])),
                u8(old_value[1] - self.lookup_refrence(data[1])),
                u8(old_value[2] - self.lookup_refrence(data[2]))
            )
        elif code == OpCode.IF_EQ:
            lhs = self.lookup_refrence(data[0])
            rhs = self.lookup_refrence(data[1])
            jmp_pos = self.lookup_refrence(data[2])
            if DEBUG >= 5:
                print("lhs, rhs, == :", lhs, rhs, lhs == rhs)
            if lhs != rhs:
                self.rel_jump(jmp_pos)
        else:
            raise LEDVMError("Unknown opcode {}".format(code))


        return False

    def execute_program(self, program_name):
        self.set_active_progarm(program_name)

        for (pixel_i, _) in enumerate(self.pixels):
            self.execute_program_pixel(pixel_i)

    def execute_program_pixel(self, pixel_number):
        self.goto_start()
        self.registers[Register.PIXEL_NUM] = pixel_number

        is_running = True

        if DEBUG:
            print("Starting program for pixel: {}".format(pixel_number))

        while is_running:
            (code, data) = self.read_op_code()
            if code == None:
                break;

            if DEBUG:
                print("(OpCode {}, Data {})".format(code, data))
            is_running = not self.execute_op_code(code, data)

    def vm_assert(self, exp, msg=""):
        if exp != True:
            self.print_core_dump(msg)
        if msg == "":
            LEDVMError("LEDVMError: unspecified error")
        else:
            LEDVMError("LEDVMError: {}".format(msg))

    def print_core_dump(self, error_msg):
        print(
            "\n"
            "Core dump while executing program '{}':\n"
            "Error message: {}\n"
            "instr_ptr: {}\n"
            "program: {}\n"
            .format(
                self._current_program_name,
                error_msg,
                self.instr_ptr,
                self.current_program
            )
        )


class LEDEffectVMParser(object):
    def __init__(self):
        # The Parser needs the inverse mappings of the op_code/register lookup
        # tables, so generate them here
        self.op_code_lookup_table = {}
        for code in OpCode.OP_CODE_TABLE:
            name = OpCode.OP_CODE_TABLE[code].name
            self.op_code_lookup_table[name] = code

        self.register_lookup_table = {}
        for reg in LEDEffectVM.REGISTER_TABLE:
            name = LEDEffectVM.REGISTER_TABLE[reg].name
            self.register_lookup_table[name] = reg

    # def exp_as_arrays(self, exp):
    #     print(exp)
    #     arr = exp[0]
    #     result = []
    #     for child in arr:
    #         result.append(self.exp_as_arrays(child))
    #     return result

    def parse_asm(self, program_str):
        sexpression = sexp.parseString(program_str, parseAll=True)
        if DEBUG:
            print(sexpression)
            pprint.pprint(sexpression)
        # sexpression = self.exp_as_arrays(sexpression)

        byte_code = []

        byte_code += self.parse_program(sexpression)

        return byte_code

    def generate_ref(self, ref):
        if isinstance(ref, int):
            assert(ref <= 255)
            ref_type = LEDEffectVM.REFERENCE_TYPE_IMMEDIATE
            value = ref
        elif isinstance(ref, str):
            if ref in self.register_lookup_table:
                ref_type = LEDEffectVM.REFERENCE_TYPE_REGISTER
                value = self.register_lookup_table[ref]
            elif ref in ('r', 'g', 'b', 'h', 's', 'v'):
                ref_type = LEDEffectVM.REFERENCE_TYPE_PIXEL
                value = {
                    'r': 0,
                    'h': 0,
                    'g': 1,
                    's': 1,
                    'b': 2,
                    'v': 2,
                }[ref]
            else:
                raise LEDVMError("Unknown reference: {}".format(ref))
        else:
            return None

        lo_byte = (value << 0)
        hi_byte = (ref_type << 8)
        return [lo_byte | hi_byte]

    def parse_instruction(self, exp):
        if DEBUG:
            print("Parse Instruction: ", exp)
        name = exp[0]

        result = []

        if not name in self.op_code_lookup_table:
            raise LEDVMError("Unknown opcode menomic: {}".format(name))

        op_code = self.op_code_lookup_table[name]
        op_info = OpCode.OP_CODE_TABLE[op_code]

        # Add the op_code to the result
        result += [op_code]

        OP_CODE_POS = 1
        data = exp[OP_CODE_POS:]

        if len(data) != op_info.data_len:
            raise LEDVMError("Expected {} arguments to opcode {}, got {}".format(
                    op_info.data_len,
                    name,
                    len(data)
                )
            )

        if op_code == OpCode.IF_EQ:
            print(data)
            print(data[0], data[1], data[2])
            LHS_POS = 0
            RHS_POS = 1
            JUMP_POS = 2
            result += self.generate_ref(data[LHS_POS])
            result += self.generate_ref(data[RHS_POS])

            if_block_exp = data[JUMP_POS]

            ref_data = self.generate_ref(if_block_exp)
            if ref_data != None:
                result += ref_data
            else:
                print('ifblock:', if_block_exp)
                if_block = self.parse_instruction_list(if_block_exp)

                jmp_offset = i16(len(if_block))
                result += [jmp_offset]
                result += if_block

            print('ifBlockResult:', result)

        elif op_info.arg_type == OpCodeInfo.ARG_NONE:
            pass # Don't need to add data
        elif op_info.arg_type == OpCodeInfo.ARG_REFRENCES:
            for ref in data:
                result += self.generate_ref(ref)

        return result

    def parse_instruction_list(self, instruction_list):
        result = []
        for instruction in instruction_list:
            result += self.parse_instruction(instruction)
        return result

    def parse_program(self, exp):
        if DEBUG:
            print("Parse program: ", exp)
        exp = exp[0]
        # pprint.pprint(exp)
        return self.parse_instruction_list(exp)


if __name__ == "__main__":
    init_prog = """
    (
        (LOAD_PIXEL PIXEL_NUM 255 200)
    )
    """
    # main_prog = """
    # (
    #     (LOAD_PIXEL r 255 200)
    #     (ADD_VEC3 1 0 0)
    #     (IF_EQ v 199
    #         (
    #             (ADD_VEC3 1 0 0)
    #         )
    #     )
    #     (IF_EQ v 200
    #         (
    #             (SUB_VEC3 1 0 0)
    #         )
    #     )
    #     (SHOW_HSV)
    # )
    # """
    main_prog = """
    (
        (IF_EQ h 0
            (
                (LOAD_PIXEL h 255 199)
            )
        )
        (IF_EQ h 255
            (
                (LOAD_PIXEL h 255 200)
            )
        )
        (IF_EQ v 200
            (
                (SUB_VEC3 1 0 0)
            )
        )
        (IF_EQ v 199
            (
                (ADD_VEC3 1 0 0)
            )
        )
        (SHOW_HSV)
    )
    """

    vm_parser = LEDEffectVMParser()
    led_programs = {
        "init": vm_parser.parse_asm(init_prog),
        "main": vm_parser.parse_asm(main_prog),
    }
    vm = LEDEffectVM(led_programs, num_pixels=64)

    for prog in led_programs:
        print(prog, led_programs[prog])
        byte_code_as_bytes = bytes([])
        for word in led_programs[prog]:
            byte_code_as_bytes += bytes([word & 0xff, word>>8 & 0xff])
        hexdump.hexdump(byte_code_as_bytes)

    vm.execute_program('init')
    for i in range(300):
        vm.execute_program('main')
    print(vm.pixels)
