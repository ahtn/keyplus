// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#define OP_REG(op, dest, x, y) (op | (dest<<DEST_bp | x<<R0_bp | y<<R1_bp)<<8)
#define OP_I(op, dest, x, im_type) (op | (1<<IM_bp | dest<<DEST_bp | x<<R0_bp | im_type<<IM_TYPE_bp)<<8)

#define MOVI(dest) OP_I(OP_MOV, dest, 0, IM_CODE)

#define ADD(dest, x, y) OP_REG(OP_ADD, dest, x, y)
#define SUB(dest, x, y) OP_REG(OP_SUB, dest, x, y)
#define MUL(dest, x, y) OP_REG(OP_MUL, dest, x, y)
#define DIV(dest, x, y) OP_REG(OP_DIV, dest, x, y)
#define INC(dest, x) OP_REG(OP_INC, dest, x, 0)
#define DEC(dest, x) OP_REG(OP_DEC, dest, x, 0)

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_color_t;

typedef enum op_codes {
    OP_NOP,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_MOV,
    OP_AND,
    OP_OR,
    OP_XOR,
    OP_NOT,
    OP_INC,
    OP_DEC,
    OP_RJMP,
    OP_JZ,
    OP_JNZ,
    OP_HSV,
    OP_RGB,
    // OP_LOAD_LAST,
    OP_END,
} op_codes_t;


#define IM_bp 0
#define DEST_bp 1
#define R0_bp 3
#define IM_TYPE_bp 5
#define R1_bp 5

typedef struct {
    uint8_t immediate: 1;
    uint8_t dest: 2;
    uint8_t reg0: 2;
    uint8_t reg1: 2;
} op_code_fmt_t;


typedef enum {
    IM_CODE = 0x00,
    IM_TIMER = 0x01,
    IM_LED_NUM = 0x02,
    IM_NUM_LEDS = 0x03,
} immediate_type_t;

extern uint16_t registers[4];

void execute_program(uint16_t *program, uint16_t len);
void test_hsv(uint8_t h, uint8_t s, uint8_t v);
void led_task(void);
