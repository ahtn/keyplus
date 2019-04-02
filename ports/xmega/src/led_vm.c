// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>
#include "led_vm.h"

#include "core/timer.h"
#include "ws2812.h"

// #define scale(x, v) ( ((uint16_t)x * (uint16_t)v) >> 8)
static inline uint8_t scale(uint8_t x, uint8_t scale_factor) {
    return ((uint16_t)x * (uint16_t)scale_factor) >> 8;
}

rgb_color_t hsv_to_rgb(uint8_t h, uint8_t s, uint8_t v) {
    rgb_color_t rgb;

    uint8_t hue_hex = h / 43;
    uint8_t hue_mod = h % 43;
    uint8_t cc = (hue_mod*6);

    switch (hue_hex) { // ++: 0->1 transition, --: 1->0 transition
        case 0: // hue: r=1, g++, b=0
            rgb.r = v;
            rgb.g = scale(cc + scale(~cc, ~s), v);
        break;

        case 1: // hue: g=1, r--, b=0
            rgb.r = scale(~cc + scale(cc, ~s), v);
            rgb.g = v;
            rgb.b = scale(~s, v);
        break;

        case 2: // hue: g=1, b++, r=0
            rgb.r = scale(~s, v);
            rgb.g = v;
            rgb.b = scale(cc + scale(~cc, ~s), v);
        break;

        case 3: // hue: b=1, g--, r=0
            rgb.r = scale(~s, v);
            rgb.g = scale(~cc + scale(cc, ~s), v);
            rgb.b = v;
        break;

        case 4: // hue: b=1, r++, g=0
            rgb.r = scale(cc + scale(~cc, ~s), v);
            rgb.g = scale(~s, v);
            rgb.b = v;
        break;

        case 5: // hue: r=1, b--, g=0
            rgb.r = v;
            rgb.g = scale(~s, v);
            rgb.b = scale(~cc + scale(cc, ~s), v);
        break;
    }

    return rgb;
}

uint16_t *program_code_ptr;
uint16_t program_len;
uint16_t pc;
uint16_t registers[4];
uint16_t program_time_value;
uint8_t led_num;
uint8_t is_hsv;

uint16_t get_timer16(void) {
    return 0;
}

void init_program(uint16_t *program, uint16_t len) {
    program_code_ptr = program;
    program_len = len;
    is_hsv = 0;
    program_time_value = get_timer16();
    led_num = 5;
    pc = 0;
}

uint16_t get_next_word(void) {
    if (pc < program_len) {
        return program_code_ptr[pc++];
    } else {
        return 0;
    }
}

void execute_op_code(uint16_t op_code) {
    uint8_t op_code_operands = op_code >> 8;
    uint8_t immediate = (op_code_operands>>IM_bp) & 0x01;
    uint8_t dest = (op_code_operands>>DEST_bp) & 0x03;
    uint16_t reg0, reg1=0;

    reg0 = registers[(op_code_operands>>R0_bp) & 0x03];

    if (immediate) {
        // printf("im_val: %d\n", (op_code_operands>>IM_TYPE_bp) & 0x0f);
        switch ((op_code_operands>>IM_TYPE_bp) & 0x0f) {
            case IM_CODE: { reg1 = get_next_word(); } break;
            case IM_TIMER: { reg1 = program_time_value; } break;
            case IM_LED_NUM: { reg1 = led_num; } break;
        }
    } else {
        reg1 = registers[(op_code_operands>>R1_bp) & 0x03];
    }

    // printf("im:%d, dest:r%d, r0:%d, r1:%d   op_code:%d\n", immediate, dest, reg0, reg1, op_code);

    switch (op_code & 0xff) {
        case OP_ADD: {
            registers[dest] = reg0 + reg1;
        } break;
        case OP_SUB: {
            registers[dest] = reg0 - reg1;
        } break;
        case OP_MUL: {
            registers[dest] = reg0 * reg1;
        } break;
        case OP_DIV: {
            registers[dest] = reg0 / reg1;
        } break;
        case OP_MOD: {
            registers[dest] = reg0 % reg1;
        } break;
        case OP_MOV: {
            registers[dest] = reg1;
        } break;
        case OP_AND: {
            registers[dest] = reg0 & reg1;
        } break;
        case OP_OR: {
            registers[dest] = reg0 | reg1;
        } break;
        case OP_XOR: {
            registers[dest] = reg0 ^ reg1;
        } break;
        case OP_NOT: {
            registers[dest] = ~reg0;
        } break;
        case OP_INC: {
            registers[dest] = reg0+1;
        } break;
        case OP_DEC: {
            registers[dest] = reg0-1;
        } break;
        case OP_RJMP: {
            pc = pc + (int16_t)reg1;
        } break;
        case OP_JZ: {
            if (reg0 == 0) {
                pc = pc + (int16_t)reg1;
            }
        } break;
        case OP_JNZ: {
            if (reg0 != 0) {
                pc = pc + (int16_t)reg1;
            }
        } break;
        case OP_HSV: {
            is_hsv = 1;
        } break;
        case OP_RGB: {
            is_hsv = 0;
        } break;
        case OP_END: {
            pc = program_len;
        } break;
        // default:
    }
}

void execute_program(uint16_t *program, uint16_t len) {
    uint16_t counter = 0;
    init_program(program, len);
    while (pc < program_len) {
        execute_op_code(get_next_word());
        // printf("step%03d, pc:%d, r0: %d, r1:%d, r2:%d, r3:%d\n", counter, pc,
                // registers[0], registers[1], registers[2], registers[3]);
        counter++;
        // if (counter > 30) break;
    }
}

void test_hsv(uint8_t h, uint8_t s, uint8_t v) {
    /* rgb_color_t rgb; */
    /* rgb = hsv_to_rgb(h, s, v); */
    // printf("hsv: %d, %d, %d\n", h, s, v);
    // printf("rgb: %d, %d, %d\n", rgb.r, rgb.g, rgb.b);
    // printf("\n");
}

// int main(int argc, char *argv[]) {
//     uint16_t program[] = {
//         MOVI(0), 128,
//         MOVI(1), 64,
//         MOVI(2), 32,
//         SUB(0, 1, 2),
//         DEC(0, 0),
//         OP_JNZ | ((1<<IM_bp)<<8), -3,
//         OP_END,
//     };
//     execute_program(program, sizeof(program)/2);
//     test(registers[0], registers[1], registers[2]);
//     return 0;
// }

// int main(int argc, char *argv[]) {
//     test(0, 0, 0);
//     test(0, 255, 255);
//     test(0, 255, 0);
//     test(0, 128, 255);
//     test(0, 64, 255);
//     test(0, 64, 128);
//     test(0, 64, 64);
//     test(21, 64, 64);
//     test(63, 64, 192);
//     test(96, 64, 192);
//     return 0;
// }

void led_task(void) {
    /* uint8_t col = timer_read_ms() / 32; */
    /* col = (col % 64)/4; */
    /* sendPixel(col, 0, 0); */
    /* sendPixel(0, col, 0); */
    /* sendPixel(0, 0, col); */
    /* sendPixel(col, 0, 0); */
    /* sendPixel(0, col, 0); */
    /* sendPixel(0, 0, col); */
    /* sendPixel(col, 0, 0); */
    /* sendPixel(0, col, 0); */
    /* sendPixel(0, 0, col); */
    /* show(); */
}
