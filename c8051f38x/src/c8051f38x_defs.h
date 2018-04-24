// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

///////////////////////////////////////////////////////////////////////////////
//                             ADC                                           //
///////////////////////////////////////////////////////////////////////////////

// ADC0CF: ADC0 Configuration
//
#define AD0SC_gp 3
#define AD0SC_gm (0x1f << AD0SC_gp)

#define AD0LJST_bp 2
#define AD0LJST_bm (1 << AD0LJST_bp)

// ADC0CN: ADC0 Control
#define AD0EN_bp 7
#define AD0EN_bm (1 << AD0EN_bp)
#define AD0TM_bp 6
#define AD0TM_bm (1 << AD0TM_bp)
#define AD0INT_bp 5
#define AD0INT_bm (1 << AD0INT_bp)
#define AD0BUSY_bp 4
#define AD0BUSY_bm (1 << AD0BUSY_bp)
#define AD0WINT_bp 3
#define AD0WINT_bm (1 << AD0WINT_bp)

#define AD0CM_gp 0
#define AD0CM_gm 0x07
enum {
    AD0CM_AD0BUSY = 0b000,
    AD0CM_TIMER0  = 0b001,
    AD0CM_TIMER2  = 0b010,
    AD0CM_TIMER1  = 0b011,
    AD0CM_CNVSTR  = 0b100,
    AD0CM_TIMER3  = 0b101,
    AD0CM_TIMER4  = 0b110,
    AD0CM_TIMER5  = 0b111,
};
enum {
    AD0CM_AD0BUSY_gc = 0b000 << AD0CM_gp,
    AD0CM_TIMER0_gc  = 0b001 << AD0CM_gp,
    AD0CM_TIMER2_gc  = 0b010 << AD0CM_gp,
    AD0CM_TIMER1_gc  = 0b011 << AD0CM_gp,
    AD0CM_CNVSTR_gc  = 0b100 << AD0CM_gp,
    AD0CM_TIMER3_gc  = 0b101 << AD0CM_gp,
    AD0CM_TIMER4_gc  = 0b110 << AD0CM_gp,
    AD0CM_TIMER5_gc  = 0b111 << AD0CM_gp,
};

// AMX0P: AMUX0 Positive Channel Select
#define AMX0P_gp 0
#define AMX0P_gm 0x3f
enum {
    AMX0P_32PIN_P1_0        = 0b000000,
    AMX0P_32PIN_P1_1        = 0b000001,
    AMX0P_32PIN_P1_2        = 0b000010,
    AMX0P_32PIN_P1_3        = 0b000011,
    AMX0P_32PIN_P1_4        = 0b000100,
    AMX0P_32PIN_P1_5        = 0b000101,
    AMX0P_32PIN_P1_6        = 0b000110,
    AMX0P_32PIN_P1_7        = 0b000111,
    AMX0P_32PIN_P2_0        = 0b001000,
    AMX0P_32PIN_P2_1        = 0b001001,
    AMX0P_32PIN_P2_2        = 0b001010,
    AMX0P_32PIN_P2_3        = 0b001011,
    AMX0P_32PIN_P2_4        = 0b001100,
    AMX0P_32PIN_P2_5        = 0b001101,
    AMX0P_32PIN_P2_6        = 0b001110,
    AMX0P_32PIN_P2_7        = 0b001111,
    AMX0P_32PIN_P3_0        = 0b010000,
    AMX0P_32PIN_P0_0        = 0b010001,
    AMX0P_32PIN_P0_1        = 0b010010,
    AMX0P_32PIN_P0_4        = 0b010011,
    AMX0P_32PIN_P0_5        = 0b010100,
    AMX0P_32PIN_TEMP_SENSOR = 0b011110,
    AMX0P_32PIN_VDD         = 0b011111,
};
enum {
    AMX0P_32PIN_P1_0_gc        = 0b000000 << AMX0P_gp,
    AMX0P_32PIN_P1_1_gc        = 0b000001 << AMX0P_gp,
    AMX0P_32PIN_P1_2_gc        = 0b000010 << AMX0P_gp,
    AMX0P_32PIN_P1_3_gc        = 0b000011 << AMX0P_gp,
    AMX0P_32PIN_P1_4_gc        = 0b000100 << AMX0P_gp,
    AMX0P_32PIN_P1_5_gc        = 0b000101 << AMX0P_gp,
    AMX0P_32PIN_P1_6_gc        = 0b000110 << AMX0P_gp,
    AMX0P_32PIN_P1_7_gc        = 0b000111 << AMX0P_gp,
    AMX0P_32PIN_P2_0_gc        = 0b001000 << AMX0P_gp,
    AMX0P_32PIN_P2_1_gc        = 0b001001 << AMX0P_gp,
    AMX0P_32PIN_P2_2_gc        = 0b001010 << AMX0P_gp,
    AMX0P_32PIN_P2_3_gc        = 0b001011 << AMX0P_gp,
    AMX0P_32PIN_P2_4_gc        = 0b001100 << AMX0P_gp,
    AMX0P_32PIN_P2_5_gc        = 0b001101 << AMX0P_gp,
    AMX0P_32PIN_P2_6_gc        = 0b001110 << AMX0P_gp,
    AMX0P_32PIN_P2_7_gc        = 0b001111 << AMX0P_gp,
    AMX0P_32PIN_P3_0_gc        = 0b010000 << AMX0P_gp,
    AMX0P_32PIN_P0_0_gc        = 0b010001 << AMX0P_gp,
    AMX0P_32PIN_P0_1_gc        = 0b010010 << AMX0P_gp,
    AMX0P_32PIN_P0_4_gc        = 0b010011 << AMX0P_gp,
    AMX0P_32PIN_P0_5_gc        = 0b010100 << AMX0P_gp,
    AMX0P_32PIN_TEMP_SENSOR_gc = 0b011110 << AMX0P_gp,
    AMX0P_32PIN_VDD_gc         = 0b011111 << AMX0P_gp,
};
enum {
    AMX0P_48PIN_P2_0        = 0b000000,
    AMX0P_48PIN_P2_1        = 0b000001,
    AMX0P_48PIN_P2_2        = 0b000010,
    AMX0P_48PIN_P2_3        = 0b000011,
    AMX0P_48PIN_P2_5        = 0b000100,
    AMX0P_48PIN_P2_6        = 0b000101,
    AMX0P_48PIN_P3_0        = 0b000110,
    AMX0P_48PIN_P3_1        = 0b000111,
    AMX0P_48PIN_P3_4        = 0b001000,
    AMX0P_48PIN_P3_5        = 0b001001,
    AMX0P_48PIN_P3_7        = 0b001010,
    AMX0P_48PIN_P4_0        = 0b001011,
    AMX0P_48PIN_P4_3        = 0b001100,
    AMX0P_48PIN_P4_4        = 0b001101,
    AMX0P_48PIN_P4_5        = 0b001110,
    AMX0P_48PIN_P4_6        = 0b001111,
    // AMX0P_48PIN_Px_x        = 0b010000,
    AMX0P_48PIN_P0_3        = 0b010001,
    AMX0P_48PIN_P0_4        = 0b010010,
    AMX0P_48PIN_P1_1        = 0b010011,
    AMX0P_48PIN_P1_2        = 0b010100,
    AMX0P_48PIN_P1_0        = 0b010101,
    AMX0P_48PIN_P1_3        = 0b010110,
    AMX0P_48PIN_P1_6        = 0b010111,
    AMX0P_48PIN_P1_7        = 0b011000,
    AMX0P_48PIN_P2_4        = 0b011001,
    AMX0P_48PIN_P2_7        = 0b011010,
    AMX0P_48PIN_P3_2        = 0b011011,
    AMX0P_48PIN_P3_3        = 0b011100,
    AMX0P_48PIN_P3_6        = 0b011101,
    AMX0P_48PIN_TEMP_SENSOR = 0b011110,
    AMX0P_48PIN_VDD         = 0b011111,
    AMX0P_48PIN_P4_1        = 0b100000,
    AMX0P_48PIN_P4_2        = 0b100001,
    AMX0P_48PIN_P4_7        = 0b100010,
};
enum {
    AMX0P_48PIN_P2_0_gc        = 0b000000 << AMX0P_gp,
    AMX0P_48PIN_P2_1_gc        = 0b000001 << AMX0P_gp,
    AMX0P_48PIN_P2_2_gc        = 0b000010 << AMX0P_gp,
    AMX0P_48PIN_P2_3_gc        = 0b000011 << AMX0P_gp,
    AMX0P_48PIN_P2_5_gc        = 0b000100 << AMX0P_gp,
    AMX0P_48PIN_P2_6_gc        = 0b000101 << AMX0P_gp,
    AMX0P_48PIN_P3_0_gc        = 0b000110 << AMX0P_gp,
    AMX0P_48PIN_P3_1_gc        = 0b000111 << AMX0P_gp,
    AMX0P_48PIN_P3_4_gc        = 0b001000 << AMX0P_gp,
    AMX0P_48PIN_P3_5_gc        = 0b001001 << AMX0P_gp,
    AMX0P_48PIN_P3_7_gc        = 0b001010 << AMX0P_gp,
    AMX0P_48PIN_P4_0_gc        = 0b001011 << AMX0P_gp,
    AMX0P_48PIN_P4_3_gc        = 0b001100 << AMX0P_gp,
    AMX0P_48PIN_P4_4_gc        = 0b001101 << AMX0P_gp,
    AMX0P_48PIN_P4_5_gc        = 0b001110 << AMX0P_gp,
    AMX0P_48PIN_P4_6_gc        = 0b001111 << AMX0P_gp,
    // AMX0P_48PIN_Px_x        = 0b010000,
    AMX0P_48PIN_P0_3_gc        = 0b010001 << AMX0P_gp,
    AMX0P_48PIN_P0_4_gc        = 0b010010 << AMX0P_gp,
    AMX0P_48PIN_P1_1_gc        = 0b010011 << AMX0P_gp,
    AMX0P_48PIN_P1_2_gc        = 0b010100 << AMX0P_gp,
    AMX0P_48PIN_P1_0_gc        = 0b010101 << AMX0P_gp,
    AMX0P_48PIN_P1_3_gc        = 0b010110 << AMX0P_gp,
    AMX0P_48PIN_P1_6_gc        = 0b010111 << AMX0P_gp,
    AMX0P_48PIN_P1_7_gc        = 0b011000 << AMX0P_gp,
    AMX0P_48PIN_P2_4_gc        = 0b011001 << AMX0P_gp,
    AMX0P_48PIN_P2_7_gc        = 0b011010 << AMX0P_gp,
    AMX0P_48PIN_P3_2_gc        = 0b011011 << AMX0P_gp,
    AMX0P_48PIN_P3_3_gc        = 0b011100 << AMX0P_gp,
    AMX0P_48PIN_P3_6_gc        = 0b011101 << AMX0P_gp,
    AMX0P_48PIN_TEMP_SENSOR_gc = 0b011110 << AMX0P_gp,
    AMX0P_48PIN_VDD_gc         = 0b011111 << AMX0P_gp,
    AMX0P_48PIN_P4_1_gc        = 0b100000 << AMX0P_gp,
    AMX0P_48PIN_P4_2_gc        = 0b100001 << AMX0P_gp,
    AMX0P_48PIN_P4_7_gc        = 0b100010 << AMX0P_gp,
};

// AMX0N: AMUX0 Negative Channel Select
#define AMX0N_gp 0
#define AMX0N_gm 0x3f
enum {
    AMX0N_32PIN_P1_0 = 0b000000,
    AMX0N_32PIN_P1_1 = 0b000001,
    AMX0N_32PIN_P1_2 = 0b000010,
    AMX0N_32PIN_P1_3 = 0b000011,
    AMX0N_32PIN_P1_4 = 0b000100,
    AMX0N_32PIN_P1_5 = 0b000101,
    AMX0N_32PIN_P1_6 = 0b000110,
    AMX0N_32PIN_P1_7 = 0b000111,
    AMX0N_32PIN_P2_0 = 0b001000,
    AMX0N_32PIN_P2_1 = 0b001001,
    AMX0N_32PIN_P2_2 = 0b001010,
    AMX0N_32PIN_P2_3 = 0b001011,
    AMX0N_32PIN_P2_4 = 0b001100,
    AMX0N_32PIN_P2_5 = 0b001101,
    AMX0N_32PIN_P2_6 = 0b001110,
    AMX0N_32PIN_P2_7 = 0b001111,
    AMX0N_32PIN_P3_0 = 0b010000,
    AMX0N_32PIN_P0_0 = 0b010001,
    AMX0N_32PIN_P0_1 = 0b010010,
    AMX0N_32PIN_P0_4 = 0b010011,
    AMX0N_32PIN_P0_5 = 0b010100,
    AMX0N_32PIN_VREF = 0b011110,
    AMX0N_32PIN_GND  = 0b011111,
};
enum {
    AMX0N_32PIN_P1_0_gc = 0b000000 << AMX0N_gp,
    AMX0N_32PIN_P1_1_gc = 0b000001 << AMX0N_gp,
    AMX0N_32PIN_P1_2_gc = 0b000010 << AMX0N_gp,
    AMX0N_32PIN_P1_3_gc = 0b000011 << AMX0N_gp,
    AMX0N_32PIN_P1_4_gc = 0b000100 << AMX0N_gp,
    AMX0N_32PIN_P1_5_gc = 0b000101 << AMX0N_gp,
    AMX0N_32PIN_P1_6_gc = 0b000110 << AMX0N_gp,
    AMX0N_32PIN_P1_7_gc = 0b000111 << AMX0N_gp,
    AMX0N_32PIN_P2_0_gc = 0b001000 << AMX0N_gp,
    AMX0N_32PIN_P2_1_gc = 0b001001 << AMX0N_gp,
    AMX0N_32PIN_P2_2_gc = 0b001010 << AMX0N_gp,
    AMX0N_32PIN_P2_3_gc = 0b001011 << AMX0N_gp,
    AMX0N_32PIN_P2_4_gc = 0b001100 << AMX0N_gp,
    AMX0N_32PIN_P2_5_gc = 0b001101 << AMX0N_gp,
    AMX0N_32PIN_P2_6_gc = 0b001110 << AMX0N_gp,
    AMX0N_32PIN_P2_7_gc = 0b001111 << AMX0N_gp,
    AMX0N_32PIN_P3_0_gc = 0b010000 << AMX0N_gp,
    AMX0N_32PIN_P0_0_gc = 0b010001 << AMX0N_gp,
    AMX0N_32PIN_P0_1_gc = 0b010010 << AMX0N_gp,
    AMX0N_32PIN_P0_4_gc = 0b010011 << AMX0N_gp,
    AMX0N_32PIN_P0_5_gc = 0b010100 << AMX0N_gp,
    AMX0N_32PIN_VREF_gc = 0b011110 << AMX0N_gp,
    AMX0N_32PIN_GND_gc  = 0b011111 << AMX0N_gp,
};
enum {
    AMX0N_48PIN_P2_0    = 0b000000,
    AMX0N_48PIN_P2_1    = 0b000001,
    AMX0N_48PIN_P2_2    = 0b000010,
    AMX0N_48PIN_P2_3    = 0b000011,
    AMX0N_48PIN_P2_5    = 0b000100,
    AMX0N_48PIN_P2_6    = 0b000101,
    AMX0N_48PIN_P3_0    = 0b000110,
    AMX0N_48PIN_P3_1    = 0b000111,
    AMX0N_48PIN_P3_4    = 0b001000,
    AMX0N_48PIN_P3_5    = 0b001001,
    AMX0N_48PIN_P3_7    = 0b001010,
    AMX0N_48PIN_P4_0    = 0b001011,
    AMX0N_48PIN_P4_3    = 0b001100,
    AMX0N_48PIN_P4_4    = 0b001101,
    AMX0N_48PIN_P4_5    = 0b001110,
    AMX0N_48PIN_P4_6    = 0b001111,
    // AMX0N_48PIN_Px_x = 0b010000,
    AMX0N_48PIN_P0_3    = 0b010001,
    AMX0N_48PIN_P0_4    = 0b010010,
    AMX0N_48PIN_P1_1    = 0b010011,
    AMX0N_48PIN_P1_2    = 0b010100,
    AMX0N_48PIN_P1_0    = 0b010101,
    AMX0N_48PIN_P1_3    = 0b010110,
    AMX0N_48PIN_P1_6    = 0b010111,
    AMX0N_48PIN_P1_7    = 0b011000,
    AMX0N_48PIN_P2_4    = 0b011001,
    AMX0N_48PIN_P2_7    = 0b011010,
    AMX0N_48PIN_P3_2    = 0b011011,
    AMX0N_48PIN_P3_3    = 0b011100,
    AMX0N_48PIN_P3_6    = 0b011101,
    AMX0N_48PIN_VREF    = 0b011110,
    AMX0N_48PIN_GND     = 0b011111,
    AMX0N_48PIN_P4_1    = 0b100000,
    AMX0N_48PIN_P4_2    = 0b100001,
    AMX0N_48PIN_P4_7    = 0b100010,
};
enum {
    AMX0N_48PIN_P2_0_gc = 0b000000 << AMX0N_gp,
    AMX0N_48PIN_P2_1_gc = 0b000001 << AMX0N_gp,
    AMX0N_48PIN_P2_2_gc = 0b000010 << AMX0N_gp,
    AMX0N_48PIN_P2_3_gc = 0b000011 << AMX0N_gp,
    AMX0N_48PIN_P2_5_gc = 0b000100 << AMX0N_gp,
    AMX0N_48PIN_P2_6_gc = 0b000101 << AMX0N_gp,
    AMX0N_48PIN_P3_0_gc = 0b000110 << AMX0N_gp,
    AMX0N_48PIN_P3_1_gc = 0b000111 << AMX0N_gp,
    AMX0N_48PIN_P3_4_gc = 0b001000 << AMX0N_gp,
    AMX0N_48PIN_P3_5_gc = 0b001001 << AMX0N_gp,
    AMX0N_48PIN_P3_7_gc = 0b001010 << AMX0N_gp,
    AMX0N_48PIN_P4_0_gc = 0b001011 << AMX0N_gp,
    AMX0N_48PIN_P4_3_gc = 0b001100 << AMX0N_gp,
    AMX0N_48PIN_P4_4_gc = 0b001101 << AMX0N_gp,
    AMX0N_48PIN_P4_5_gc = 0b001110 << AMX0N_gp,
    AMX0N_48PIN_P4_6_gc = 0b001111 << AMX0N_gp,
    // AMX0N_48PIN_Px_x = 0b010000,
    AMX0N_48PIN_P0_3_gc = 0b010001 << AMX0N_gp,
    AMX0N_48PIN_P0_4_gc = 0b010010 << AMX0N_gp,
    AMX0N_48PIN_P1_1_gc = 0b010011 << AMX0N_gp,
    AMX0N_48PIN_P1_2_gc = 0b010100 << AMX0N_gp,
    AMX0N_48PIN_P1_0_gc = 0b010101 << AMX0N_gp,
    AMX0N_48PIN_P1_3_gc = 0b010110 << AMX0N_gp,
    AMX0N_48PIN_P1_6_gc = 0b010111 << AMX0N_gp,
    AMX0N_48PIN_P1_7_gc = 0b011000 << AMX0N_gp,
    AMX0N_48PIN_P2_4_gc = 0b011001 << AMX0N_gp,
    AMX0N_48PIN_P2_7_gc = 0b011010 << AMX0N_gp,
    AMX0N_48PIN_P3_2_gc = 0b011011 << AMX0N_gp,
    AMX0N_48PIN_P3_3_gc = 0b011100 << AMX0N_gp,
    AMX0N_48PIN_P3_6_gc = 0b011101 << AMX0N_gp,
    AMX0N_48PIN_VREF_gc = 0b011110 << AMX0N_gp,
    AMX0N_48PIN_GND_gc  = 0b011111 << AMX0N_gp,
    AMX0N_48PIN_P4_1_gc = 0b100000 << AMX0N_gp,
    AMX0N_48PIN_P4_2_gc = 0b100001 << AMX0N_gp,
    AMX0N_48PIN_P4_7_gc = 0b100010 << AMX0N_gp,
};

///////////////////////////////////////////////////////////////////////////////
//                        Voltage Reference                                  //
///////////////////////////////////////////////////////////////////////////////

// REF0CN: Reference Control
#define REFBGS_bp 7
#define REFBGS_bm (1 << REFBGS_bp)
#define REGOVR_bp 4
#define REGOVR_bm (1 << REGOVR_bp)
#define REFSL_bp 3
#define REFSL_bm (1 << REFSL_bp)
#define TEMPE_bp 2
#define TEMPE_bm (1 << TEMPE_bp)
#define BIASE_bp 1
#define BIASE_bm (1 << BIASE_bp)
#define REFBE_bp 0
#define REFBE_bm (1 << REFBE_bp)

///////////////////////////////////////////////////////////////////////////////
//                        Comparator                                         //
///////////////////////////////////////////////////////////////////////////////

// CPT0CN: Comparator0 Control
#define CP0EN_bp 7
#define CP0EN_bm (1 << CP0EN_bp)
#define CP0OUT_bp 6
#define CP0OUT_bm (1 << CP0OUT_bp)
#define CP0RIF_bp 5
#define CP0RIF_bm (1 << CP0RIF_bp)
#define CP0FIF_bp 4
#define CP0FIF_bm (1 << CP0FIF_bp)

#define CP0HYP_gp 2
#define CP0HYP_gm 0x0c
enum {
    CP0HYP_POS_HYSTERESIS_DISABLED = 0b00,
    CP0HYP_POS_HYSTERESIS_5MV      = 0b01,
    CP0HYP_POS_HYSTERESIS_10MV     = 0b10,
    CP0HYP_POS_HYSTERESIS_20MV     = 0b11,
};
enum {
    CP0HYP_POS_HYSTERESIS_DISABLED_gc = 0b00 << CP0HYP_gp,
    CP0HYP_POS_HYSTERESIS_5MV_gc      = 0b01 << CP0HYP_gp,
    CP0HYP_POS_HYSTERESIS_10MV_gc     = 0b10 << CP0HYP_gp,
    CP0HYP_POS_HYSTERESIS_20MV_gc     = 0b11 << CP0HYP_gp,
};

#define CP0HYN_gp 0
#define CP0HYN_gm 0x03
enum {
    CP0HYN_NEG_HYSTERESIS_DISABLED = 0b00,
    CP0HYN_NEG_HYSTERESIS_5MV      = 0b01,
    CP0HYN_NEG_HYSTERESIS_10MV     = 0b10,
    CP0HYN_NEG_HYSTERESIS_20MV     = 0b11,
};
enum {
    CP0HYN_NEG_HYSTERESIS_DISABLED_gc = 0b00 << CP0HYP_gp,
    CP0HYN_NEG_HYSTERESIS_5MV_gc      = 0b01 << CP0HYP_gp,
    CP0HYN_NEG_HYSTERESIS_10MV_gc     = 0b10 << CP0HYP_gp,
    CP0HYN_NEG_HYSTERESIS_20MV_gc     = 0b11 << CP0HYP_gp,
};

// CPT0MD: Comparator0 Mode Selection
#define CP0RIE_bp 5
#define CP0RIE_bm (1 << CP0RIE_bp)
#define CP0FIE_bp 4
#define CP0FIE_bm (1 << CP0FIE_bp)

#define CP0MD_gp 0
#define CP0MD_gm 0x03
enum {
    CP0MD_MODE_0 = 0b00,
    CP0MD_MODE_1 = 0b01,
    CP0MD_MODE_2 = 0b10,
    CP0MD_MODE_3 = 0b11,
};
enum {
    CP0MD_MODE_0_gc = 0b00 << CP0MD_gp,
    CP0MD_MODE_1_gc = 0b01 << CP0MD_gp,
    CP0MD_MODE_2_gc = 0b10 << CP0MD_gp,
    CP0MD_MODE_3_gc = 0b11 << CP0MD_gp,
};

// CPT1CN: Comparator1 Control
#define CP1EN_bp 7
#define CP1EN_bm (1 << CP1EN_bp)
#define CP1OUT_bp 6
#define CP1OUT_bm (1 << CP1OUT_bp)
#define CP1RIF_bp 5
#define CP1RIF_bm (1 << CP1RIF_bp)
#define CP1FIF_bp 4
#define CP1FIF_bm (1 << CP1FIF_bp)

#define CP1HYP_gp 2
#define CP1HYP_gm 0x0c
enum {
    CP1HYP_POS_HYSTERESIS_DISABLED = 0b00,
    CP1HYP_POS_HYSTERESIS_5MV      = 0b01,
    CP1HYP_POS_HYSTERESIS_10MV     = 0b10,
    CP1HYP_POS_HYSTERESIS_20MV     = 0b11,
};
enum {
    CP1HYP_POS_HYSTERESIS_DISABLED_gc = 0b00 << CP1HYP_gp,
    CP1HYP_POS_HYSTERESIS_5MV_gc      = 0b01 << CP1HYP_gp,
    CP1HYP_POS_HYSTERESIS_10MV_gc     = 0b10 << CP1HYP_gp,
    CP1HYP_POS_HYSTERESIS_20MV_gc     = 0b11 << CP1HYP_gp,
};

#define CP1HYN_gp 0
#define CP1HYN_gm 0x03
enum {
    CP1HYN_NEG_HYSTERESIS_DISABLED = 0b00,
    CP1HYN_NEG_HYSTERESIS_5MV      = 0b01,
    CP1HYN_NEG_HYSTERESIS_10MV     = 0b10,
    CP1HYN_NEG_HYSTERESIS_20MV     = 0b11,
};
enum {
    CP1HYN_NEG_HYSTERESIS_DISABLED_gc = 0b00 << CP1HYP_gp,
    CP1HYN_NEG_HYSTERESIS_5MV_gc      = 0b01 << CP1HYP_gp,
    CP1HYN_NEG_HYSTERESIS_10MV_gc     = 0b10 << CP1HYP_gp,
    CP1HYN_NEG_HYSTERESIS_20MV_gc     = 0b11 << CP1HYP_gp,
};

// CPT0MD: Comparator1 Mode Selection
#define CP1RIE_bp 5
#define CP1RIE_bm (1 << CP1RIE_bp)
#define CP1FIE_bp 4
#define CP1FIE_bm (1 << CP1FIE_bp)

#define CP1MD_gp 0
#define CP1MD_gm 0x03
enum {
    CP1MD_MODE_0 = 0b00,
    CP1MD_MODE_1 = 0b01,
    CP1MD_MODE_2 = 0b10,
    CP1MD_MODE_3 = 0b11,
};
enum {
    CP1MD_MODE_0_gc = 0b00 << CP1MD_gp,
    CP1MD_MODE_1_gc = 0b01 << CP1MD_gp,
    CP1MD_MODE_2_gc = 0b10 << CP1MD_gp,
    CP1MD_MODE_3_gc = 0b11 << CP1MD_gp,
};

// CPT0MX: Comparator0 MUX Selection
#define CMX0N_gp 4
#define CMX0N_gm 0x70
enum {
    CMX0N_32PIN_P1_1 = 0b000,
    CMX0N_32PIN_P1_5 = 0b001,
    CMX0N_32PIN_P2_1 = 0b010,
    CMX0N_32PIN_P2_5 = 0b011,
    CMX0N_32PIN_P0_1 = 0b100,
};
enum {
    CMX0N_32PIN_P1_1_gc = 0b000 << CMX0N_gp,
    CMX0N_32PIN_P1_5_gc = 0b001 << CMX0N_gp,
    CMX0N_32PIN_P2_1_gc = 0b010 << CMX0N_gp,
    CMX0N_32PIN_P2_5_gc = 0b011 << CMX0N_gp,
    CMX0N_32PIN_P0_1_gc = 0b100 << CMX0N_gp,
};
enum {
    CMX0N_48PIN_P2_1 = 0b000,
    CMX0N_48PIN_P2_6 = 0b001,
    CMX0N_48PIN_P3_5 = 0b010,
    CMX0N_48PIN_P4_4 = 0b011,
    CMX0N_48PIN_P0_4 = 0b100,
};
enum {
    CMX0N_48PIN_P2_1_gc = 0b000 << CMX0N_gp,
    CMX0N_48PIN_P2_6_gc = 0b001 << CMX0N_gp,
    CMX0N_48PIN_P3_5_gc = 0b010 << CMX0N_gp,
    CMX0N_48PIN_P4_4_gc = 0b011 << CMX0N_gp,
    CMX0N_48PIN_P0_4_gc = 0b100 << CMX0N_gp,
};

#define CMX0P_gp 0
#define CMX0P_gm 0x07
enum {
    CMX0P_32PIN_P1_0 = 0b000,
    CMX0P_32PIN_P1_4 = 0b001,
    CMX0P_32PIN_P2_0 = 0b010,
    CMX0P_32PIN_P2_4 = 0b011,
    CMX0P_32PIN_P0_0 = 0b100,
};
enum {
    CMX0P_32PIN_P1_0_gc = 0b000 << CMX0P_gp,
    CMX0P_32PIN_P1_4_gc = 0b001 << CMX0P_gp,
    CMX0P_32PIN_P2_0_gc = 0b010 << CMX0P_gp,
    CMX0P_32PIN_P2_4_gc = 0b011 << CMX0P_gp,
    CMX0P_32PIN_P0_0_gc = 0b100 << CMX0P_gp,
};
enum {
    CMX0P_48PIN_P2_0 = 0b000,
    CMX0P_48PIN_P2_5 = 0b001,
    CMX0P_48PIN_P3_4 = 0b010,
    CMX0P_48PIN_P4_3 = 0b011,
    CMX0P_48PIN_P0_3 = 0b100,
};
enum {
    CMX0P_48PIN_P2_0_gc = 0b000 << CMX0P_gp,
    CMX0P_48PIN_P2_5_gc = 0b001 << CMX0P_gp,
    CMX0P_48PIN_P3_4_gc = 0b010 << CMX0P_gp,
    CMX0P_48PIN_P4_3_gc = 0b011 << CMX0P_gp,
    CMX0P_48PIN_P0_3_gc = 0b100 << CMX0P_gp,
};

// CPT1MX: Comparator1 MUX Selection
#define CMX1N_gp 4
#define CMX1N_gm 0x70
enum {
    CMX1N_32PIN_P1_3 = 0b000,
    CMX1N_32PIN_P1_7 = 0b001,
    CMX1N_32PIN_P2_3 = 0b010,
    // CMX1N_32PIN_Px_x = 0b011,
    CMX1N_32PIN_P0_5 = 0b100,

    CMX1N_48PIN_P2_3 = 0b000,
    CMX1N_48PIN_P3_1 = 0b001,
    CMX1N_48PIN_P4_0 = 0b010,
    CMX1N_48PIN_P4_6 = 0b011,
    CMX1N_48PIN_P1_2 = 0b100,
};
enum {
    CMX1N_32PIN_P1_3_gc = 0b000 << CMX1N_gp,
    CMX1N_32PIN_P1_7_gc = 0b001 << CMX1N_gp,
    CMX1N_32PIN_P2_3_gc = 0b010 << CMX1N_gp,
    // CMX1N_32PIN_P2_5_gc = 0b011 << CMX1N_gp,
    CMX1N_32PIN_P0_5_gc = 0b100 << CMX1N_gp,

    CMX1N_48PIN_P2_3_gc = 0b000 << CMX1N_gp,
    CMX1N_48PIN_P3_1_gc = 0b001 << CMX1N_gp,
    CMX1N_48PIN_P4_0_gc = 0b010 << CMX1N_gp,
    CMX1N_48PIN_P4_6_gc = 0b011 << CMX1N_gp,
    CMX1N_48PIN_P1_2_gc = 0b100 << CMX1N_gp,
};

#define CMX1P_gp 0
#define CMX1P_gm 0x07
enum {
    CMX1P_32PIN_P1_2 = 0b000,
    CMX1P_32PIN_P1_6 = 0b001,
    CMX1P_32PIN_P2_2 = 0b010,
    // CMX1P_32PIN_Px_x = 0b011,
    CMX1P_32PIN_P0_4 = 0b100,

    CMX1P_48PIN_P2_2 = 0b000,
    CMX1P_48PIN_P3_0 = 0b001,
    CMX1P_48PIN_P3_7 = 0b010,
    CMX1P_48PIN_P4_5 = 0b011,
    CMX1P_48PIN_P1_1 = 0b100,
};
enum {
    CMX1P_32PIN_P1_2_gc = 0b000 << CMX1P_gp,
    CMX1P_32PIN_P1_6_gc = 0b001 << CMX1P_gp,
    CMX1P_32PIN_P2_2_gc = 0b010 << CMX1P_gp,
    // CMX1P_32PIN_Px_x_gc = 0b011 << CMX1P_gp,
    CMX1P_32PIN_P0_4_gc = 0b100 << CMX1P_gp,

    CMX1P_48PIN_P2_2_gc = 0b000 << CMX1P_gp,
    CMX1P_48PIN_P3_0_gc = 0b001 << CMX1P_gp,
    CMX1P_48PIN_P3_7_gc = 0b010 << CMX1P_gp,
    CMX1P_48PIN_P4_5_gc = 0b011 << CMX1P_gp,
    CMX1P_48PIN_P1_1_gc = 0b100 << CMX1P_gp,
};

///////////////////////////////////////////////////////////////////////////////
//                        Voltage Regulator                                  //
///////////////////////////////////////////////////////////////////////////////

// REG01CN: Voltage Regulator Control
#define REG0DIS_bp 7
#define REG0DIS_bm (1 << REG0DIS_bp)
#define VBSTAT_bp 6
#define VBSTAT_bm (1 << VBSTAT_bp)
#define REG0MD_bp 4
#define REG0MD_bm (1 << REG0MD_bp)
#define STOPCF_bp 3
#define STOPCF_bm (1 << STOPCF_bp)
#define REG1MD_bp 1
#define REG1MD_bm (1 << REG1MD_bp)

///////////////////////////////////////////////////////////////////////////////
//                        Power Management                                   //
///////////////////////////////////////////////////////////////////////////////

// PCON: Power Control
#define PCON_GF5_bp 7
#define PCON_GF5_bm (1 << PCON_GPF_5_bp)
#define PCON_GF4_bp 6
#define PCON_GF4_bm (1 << PCON_GPF_4_bp)
#define PCON_GF3_bp 5
#define PCON_GF3_bm (1 << PCON_GPF_3_bp)
#define PCON_GF2_bp 4
#define PCON_GF2_bm (1 << PCON_GPF_2_bp)
#define PCON_GF1_bp 3
#define PCON_GF1_bm (1 << PCON_GPF_1_bp)
#define PCON_GF0_bp 2
#define PCON_GF0_bm (1 << PCON_GPF_0_bp)
#define STOP_bp 1
#define STOP_bm (1 << STOP_bp)
#define IDLE_bp 0
#define IDLE_bm (1 << IDLE_bp)

///////////////////////////////////////////////////////////////////////////////
//                        Prefetch                                           //
///////////////////////////////////////////////////////////////////////////////

// PFE0CN: Prefetch Engine Control
#define PFEN_bp 5
#define PFEN_bm (1 << PFEN_bp)
#define FLBWE_bp 0
#define FLBWE_bm (1 << FLBWE_bp)

///////////////////////////////////////////////////////////////////////////////
//                     External Memory Interface                             //
///////////////////////////////////////////////////////////////////////////////

// EMI0CF: External Memory Interface Configuration
#define USBFAE_bp 6
#define USBFAE_bm (1 << USBFAE_bp)
#define EMD2_bp 4
#define EMD2_bm (1 << EMD2_bp)

#define EMD_gp 0
#define EMD_gm 0x0c
enum {
    EMD_INTERNAL_ONLY     = 0b00,
    EMD_SPLIT             = 0b01,
    EMD_SPLIT_BANK_SELECT = 0b10,
    EMD_EXTERNAL_ONLY     = 0b11,
};
enum {
    EMD_INTERNAL_ONLY_gc     = 0b00 << EMD_gp,
    EMD_SPLIT_gc             = 0b01 << EMD_gp,
    EMD_SPLIT_BANK_SELECT_gc = 0b10 << EMD_gp,
    EMD_EXTERNAL_ONLY_gc     = 0b11 << EMD_gp,
};

#define EALE_gp 0
#define EALE_gm 0x03
enum {
    EALE_1_CYCLE = 0b00,
    EALE_2_CYCLE = 0b01,
    EALE_3_CYCLE = 0b10,
    EALE_4_CYCLE = 0b11,
};
enum {
    EALE_1_CYCLE_gc = 0b00 << EALE_gp,
    EALE_2_CYCLE_gc = 0b01 << EALE_gp,
    EALE_3_CYCLE_gc = 0b10 << EALE_gp,
    EALE_4_CYCLE_gc = 0b11 << EALE_gp,
};


///////////////////////////////////////////////////////////////////////////////
//                         Interrupts                                        //
///////////////////////////////////////////////////////////////////////////////

// IE: Interrupt Enable
#define EA_bp 7
#define EA_bm (1 << EA_bp)
#define ESPI0_bp 6
#define ESPI0_bm (1 << ESPI0_bp)
#define ET2_bp 5
#define ET2_bm (1 << ET2_bp)
#define ES0_bp 4
#define ES0_bm (1 << ES0_bp)
#define ET1_bp 3
#define ET1_bm (1 << ET1_bp)
#define EX1_bp 2
#define EX1_bm (1 << EX1_bp)
#define ET0_bp 1
#define ET0_bm (1 << ET0_bp)
#define EX0_bp 0
#define EX0_bm (1 << EX0_bp)

// IP: Interrupt Priority
#define PSPI0_bp 6
#define PSPI0_bm (1 << PSPI0_bp)
#define PT2_bp 5
#define PT2_bm (1 << PT2_bp)
#define PS0_bp 4
#define PS0_bm (1 << PS0_bp)
#define PT1_bp 3
#define PT1_bm (1 << PT1_bp)
#define PX1_bp 2
#define PX1_bm (1 << PX1_bp)
#define PT0_bp 1
#define PT0_bm (1 << PT0_bp)
#define PX0_bp 0
#define PX0_bm (1 << PX0_bp)

// EIE1: Extended Interrupt Enable 1
#define ET3_bp 7
#define ET3_bm (1 << ET3_bp)
#define ECP1_bp 6
#define ECP1_bm (1 << ECP1_bp)
#define ECP0_bp 5
#define ECP0_bm (1 << ECP0_bp)
#define EPCA0_bp 4
#define EPCA0_bm (1 << EPCA0_bp)
#define EADC0_bp 3
#define EADC0_bm (1 << EADC0_bp)
#define EWADC0_bp 2
#define EWADC0_bm (1 << EWADC0_bp)
#define EUSB0_bp 1
#define EUSB0_bm (1 << EUSB0_bp)
#define ESMB0_bp 0
#define ESMB0_bm (1 << ESMB0_bp)

// EIP1: Extended Interrupt Priority 1
#define PT3_bp 7
#define PT3_bm (1 << PT3_bp)
#define PCP1_bp 7
#define PCP1_bm (1 << PCP1_bp)
#define PCP0_bp 7
#define PCP0_bm (1 << PCP0_bp)
#define PPCA0_bp 7
#define PPCA0_bm (1 << PPCA0_bp)
#define PADC0_bp 7
#define PADC0_bm (1 << PADC0_bp)
#define PWADC0_bp 7
#define PWADC0_bm (1 << PWADC0_bp)
#define PUSB0_bp 7
#define PUSB0_bm (1 << PUSB0_bp)
#define PSMB0_bp 7
#define PSMB0_bm (1 << PSMB0_bp)

// EIP2: Extended Interrupt Priority 2
#define PT5_bp 5
#define PT5_bm (1 << PT5_bp)
#define PT4_bp 4
#define PT4_bm (1 << PT4_bp)
#define PSMB1_bp 3
#define PSMB1_bm (1 << PSMB1_bp)
#define PS1_bp 1
#define PS1_bm (1 << PS1_bp)
#define PVBUS_bp 0
#define PVBUS_bm (1 << PVBUS_bp)

// IT01CF: INT0/INT1 Configuration
#define IN1PL_bp 7
#define IN1PL_bm (1 << IN1PL_bp)

#define IN1SL_gp 4
#define IN1SL_gm 0x70
enum {
    IN1SL_P0_0 = 0b000,
    IN1SL_P0_1 = 0b001,
    IN1SL_P0_2 = 0b010,
    IN1SL_P0_3 = 0b011,
    IN1SL_P0_4 = 0b100,
    IN1SL_P0_5 = 0b101,
    IN1SL_P0_6 = 0b110,
    IN1SL_P0_7 = 0b111,
};
enum {
    IN1SL_P0_0_gc = 0b000 << IN1SL_gp,
    IN1SL_P0_1_gc = 0b001 << IN1SL_gp,
    IN1SL_P0_2_gc = 0b010 << IN1SL_gp,
    IN1SL_P0_3_gc = 0b011 << IN1SL_gp,
    IN1SL_P0_4_gc = 0b100 << IN1SL_gp,
    IN1SL_P0_5_gc = 0b101 << IN1SL_gp,
    IN1SL_P0_6_gc = 0b110 << IN1SL_gp,
    IN1SL_P0_7_gc = 0b111 << IN1SL_gp,
};

#define IN0PL_bp 3
#define IN0PL_bm (1 << IN0PL_bp)

#define IN0SL_gp 0
#define IN0SL_gm 0x07
enum {
    IN0SL_P0_0 = 0b000,
    IN0SL_P0_1 = 0b001,
    IN0SL_P0_2 = 0b010,
    IN0SL_P0_3 = 0b011,
    IN0SL_P0_4 = 0b100,
    IN0SL_P0_5 = 0b101,
    IN0SL_P0_6 = 0b110,
    IN0SL_P0_7 = 0b111,
};
enum {
    IN0SL_P0_0_gc = 0b000 << IN0SL_gp,
    IN0SL_P0_1_gc = 0b001 << IN0SL_gp,
    IN0SL_P0_2_gc = 0b010 << IN0SL_gp,
    IN0SL_P0_3_gc = 0b011 << IN0SL_gp,
    IN0SL_P0_4_gc = 0b100 << IN0SL_gp,
    IN0SL_P0_5_gc = 0b101 << IN0SL_gp,
    IN0SL_P0_6_gc = 0b110 << IN0SL_gp,
    IN0SL_P0_7_gc = 0b111 << IN0SL_gp,
};


///////////////////////////////////////////////////////////////////////////////
//                         Power-on Reset                                    //
///////////////////////////////////////////////////////////////////////////////

//
// VDM0CN: V DD Monitor Control
//
#define VDMEN_bp 7
#define VDMEN_bm (1 << VDMEN_bp)
#define VDDSTAT_bp 6
#define VDDSTAT_bm (1 << VDDSTAT_bp)

//
// RSTSRC: Reset Source
//
#define USBRSF_bp 7
#define USBRSF_bm (1 << USBRSF_bp)
#define FERROR_bp 6
#define FERROR_bm (1 << FERROR_bp)
#define C0RSEF_bp 5
#define C0RSEF_bm (1 << C0RSEF_bp)
#define SWRSF_bp 4
#define SWRSF_bm (1 << SWRSF_bp)
#define WDTRSF_bp 3
#define WDTRSF_bm (1 << WDTRSF_bp)
#define MCDRSF_bp 2
#define MCDRSF_bm (1 << MCDRSF_bp)
#define PORSF_bp 1
#define PORSF_bm (1 << PORSF_bp)
#define PINRSF_bp 0
#define PINRSF_bm (1 << PINRSF_bp)

///////////////////////////////////////////////////////////////////////////////
//                         Flash settings                                    //
///////////////////////////////////////////////////////////////////////////////

//
// PSCTL: Program Store R/W Control
//
#define PSEE_bp 1
#define PSEE_bm (1 << PSEE_bp)
#define PSWE_bp 0
#define PSWE_bm (1 << PSWE_bp)

//
// FLSCL: Flash Scale
//
#define FOSE_bp 7
#define FOSE_bm (1 << FOSE_bp)
#define FLRT_bp 4
#define FLRT_bm (1 << FLRT_bp)

///////////////////////////////////////////////////////////////////////////////
//                         Clock settings                                    //
///////////////////////////////////////////////////////////////////////////////

//
// CLKSEL: Clock Select
//

// USBCLK: USB Clock Source
#define USBCLK_gp 4
#define USBCLK_gm 0x70
enum {
    USBCLK_INTERNAL_HF_OSC       = 0b000,
    USBCLK_INTERNAL_HF_OSC_DIV_8 = 0b001,
    USBCLK_EXTERNAL_OSC          = 0b010,
    USBCLK_EXTERNAL_OSC_DIV_2    = 0b011,
    USBCLK_EXTERNAL_OSC_DIV_3    = 0b100,
    USBCLK_EXTERNAL_OSC_DIV_4    = 0b101,
    USBCLK_INTERNAL_LF_OSC       = 0b110,
};
enum {
    USBCLK_INTERNAL_HF_OSC_gc       = 0b000 << USBCLK_gp,
    USBCLK_INTERNAL_HF_OSC_DIV_8_gc = 0b001 << USBCLK_gp,
    USBCLK_EXTERNAL_OSC_gc          = 0b010 << USBCLK_gp,
    USBCLK_EXTERNAL_OSC_DIV_2_gc    = 0b011 << USBCLK_gp,
    USBCLK_EXTERNAL_OSC_DIV_3_gc    = 0b100 << USBCLK_gp,
    USBCLK_EXTERNAL_OSC_DIV_4_gc    = 0b101 << USBCLK_gp,
    USBCLK_INTERNAL_LF_OSC_gc       = 0b110 << USBCLK_gp,
};

// OUTCLK: Crossbar Clock Out Select.
#define OUTCLK_bp 3
#define OUTCLK_bm (1 << OUTCLK_bp)

// SYSCLK: System Clock Source Select Bits.
#define SYSCLK_gp 0
#define SYSCLK_gm 0x07
enum {
    SYSCLK_INTERNAL_HF_OSC_DIV_4 = 0b000,
    SYSCLK_EXTERNAL_OSC          = 0b001,
    SYSCLK_INTERNAL_HF_OSC_DIV_2 = 0b010,
    SYSCLK_INTERNAL_HF_OSC       = 0b011,
    SYSCLK_INTERNAL_LF_OSC       = 0b100,
};
enum {
    SYSCLK_INTERNAL_HF_OSC_DIV_4_gc = 0b000 << SYSCLK_gp,
    SYSCLK_EXTERNAL_OSC_gc          = 0b001 << SYSCLK_gp,
    SYSCLK_INTERNAL_HF_OSC_DIV_2_gc = 0b010 << SYSCLK_gp,
    SYSCLK_INTERNAL_HF_OSC_gc       = 0b011 << SYSCLK_gp,
    SYSCLK_INTERNAL_LF_OSC_gc       = 0b100 << SYSCLK_gp,
};

//
// OSCICN: Internal H-F Oscillator Control
//
#define IOSCEN_bp 7
#define IOSCEN_bm (1 << IOSCEN_bp)

#define IFRDY_bp 6
#define IFRDY_bm (1 << IFRDY_bp)

#define SUSPEND_bp 5
#define SUSPEND_bm (1 << SUSPEND_bp)

#define IFCN_gp 0
#define IFCN_gm 0x03
enum {
    IFCN_DIV_8 = 0b00,
    IFCN_DIV_4 = 0b01,
    IFCN_DIV_2 = 0b10,
    IFCN_DIV_1 = 0b11,
};
enum {
    IFCN_DIV_8_gc = 0b00 << IFCN_gp,
    IFCN_DIV_4_gc = 0b01 << IFCN_gp,
    IFCN_DIV_2_gc = 0b10 << IFCN_gp,
    IFCN_DIV_1_gc = 0b11 << IFCN_gp,
};

//
// CLKMUL: Clock Multiplier Control
//
#define MULEN_bp 7
#define MULEN_bm (1 << MULEN_bp)

#define MULINIT_bp 6
#define MULINIT_bm (1 << MULINIT)

#define MULRDY_bp 5
#define MULRDY_bm (1 << MULRDY_bp)

#define MULSEL_gp 0
#define MULSEL_gm 0x03

//
// OSCLCN: Internal L-F Oscillator Control
//
#define OSCLEN_bp 7
#define OSCLEN_bm (1 << OSCLEN_bp)

#define OSCLRDY_bp 6
#define OSCLRDY_bm (1 << OSCLRDY_bp)

#define OSCLF_gp 2
#define OSCLF_gm 0x3c

#define OSCLD_gp 0
#define OSCLD_gm 0x03
enum {
    OSCLD_DIV_8 = 0b00,
    OSCLD_DIV_4 = 0b01,
    OSCLD_DIV_2 = 0b10,
    OSCLD_DIV_1 = 0b11,
};
enum {
    OSCLD_DIV_8_gc = 0b00 << OSCLD_gp,
    OSCLD_DIV_4_gc = 0b01 << OSCLD_gp,
    OSCLD_DIV_2_gc = 0b10 << OSCLD_gp,
    OSCLD_DIV_1_gc = 0b11 << OSCLD_gp,
};

//
// OSCXCN: External Oscillator Control
//
#define XCLKVLD_bp 7
#define XCLKVLD_bm (1 << XCLKVLD_bp)

// XOSCMD: External Oscillator Mode Select.
#define XOSCMD_gp 4
#define XOSCMD_gm 0x70
enum {
    XOSCMD_OFF        = 0b000,
    // 00x: External Oscillator circuit off.
    XOSCMD_CMOS       = 0b010, // External CMOS Clock Mode.
    XOSCMD_CMOS_DIV_2 = 0b011, // External CMOS Clock Mode with divide-by-2 stage.
    XOSCMD_RC_DIV_2   = 0b100, // RC Oscillator Mode with divide-by-2 stage.
    XOSCMD_C_DIV_2    = 0b101, // Capacitor Oscillator Mode with divide-by-2 stage.
    XOSCMD_XTAL       = 0b110, // Crystal Oscillator Mode.
    XOSCMD_XTAL_DIV2  = 0b111, // Crystal Oscillator Mode with divide-by-2 stage.
};

enum {
    XOSCMD_OFF_gc        = 0b000 << XOSCMD_gp,
    // 00x: External Oscillator circuit off.
    XOSCMD_CMOS_gc       = 0b010 << XOSCMD_gp, // External CMOS Clock Mode.
    XOSCMD_CMOS_DIV_2_gc = 0b011 << XOSCMD_gp, // External CMOS Clock Mode with divide-by-2 stage.
    XOSCMD_RC_DIV_2_gc   = 0b100 << XOSCMD_gp, // RC Oscillator Mode with divide-by-2 stage.
    XOSCMD_C_DIV_2_gc    = 0b101 << XOSCMD_gp, // Capacitor Oscillator Mode with divide-by-2 stage.
    XOSCMD_XTAL_gc       = 0b110 << XOSCMD_gp, // Crystal Oscillator Mode.
    XOSCMD_XTAL_DIV2_gc  = 0b111 << XOSCMD_gp, // Crystal Oscillator Mode with divide-by-2 stage.
};

#define XFCN_gp 0
#define XFCN_gm 0x07

///////////////////////////////////////////////////////////////////////////////
//                         GPIO settings                                     //
///////////////////////////////////////////////////////////////////////////////

//
// XBR0: Port I/O Crossbar Register 0
//
#define CP1AE_bp 7
#define CP1AE_bm (1 << CP1AE_bp)
#define CP1E_bp 6
#define CP1E_bm (1 << CP1E_bp)
#define CP0AE_bp 5
#define CP0AE_bm (1 << CP0AE_bp)
#define CP0E_bp 4
#define CP0E_bm (1 << CP0E_bp)
#define SYSCKE_bp 3
#define SYSCKE_bm (1 << SYSCKE_bp)
#define SMB0E_bp 2
#define SMB0E_bm (1 << SMB0E_bp)
#define SPI0E_bp 1
#define SPI0E_bm (1 << SPI0E_bp)
#define URT0E_bp 0
#define URT0E_bm (1 << URT0E_bp)

//
// XBR1: Port I/O Crossbar Register 1
//
#define WEAKPUD_bp 7
#define WEAKPUD_bm (1 << WEAKPUD_bp)
#define XBARE_bp 6
#define XBARE_bm (1 << XBARE_bp)
#define T1E_bp 5
#define T1E_bm (1 << T1E_bp)
#define T0E_bp 4
#define T0E_bm (1 << T0E_bp)
#define ECIE_bp 3
#define ECIE_bm (1 << ECIE_bp)

// PCA0ME: PCA Module I/O Enable Bits.
#define PCA0ME_gp 0
#define PCA0ME_gm 0x07

//
// XBR1: Port I/O Crossbar Register 1
//
#define SMB1E_bp 1
#define SMB1E_bm (1 << SMB1E_bp)
#define URT1E_bp 0
#define URT1E_bm (1 << URT1E_bp)

#define PIN0_bm (1 << 0)
#define PIN1_bm (1 << 1)
#define PIN2_bm (1 << 2)
#define PIN3_bm (1 << 3)
#define PIN4_bm (1 << 4)
#define PIN5_bm (1 << 5)
#define PIN6_bm (1 << 6)
#define PIN7_bm (1 << 7)

///////////////////////////////////////////////////////////////////////////////
//                              SMBUS                                        //
///////////////////////////////////////////////////////////////////////////////

// SMB0CF: SMBus Clock/Configuration
#define ENSMB0_bp 7
#define ENSMB0_bm (1 << ENSMB0_bp)
#define INH0_bp 6
#define INH0_bm (1 << INH0_bp)
#define BUSY0_bp 5
#define BUSY0_bm (1 << BUSY0_bp)
#define EXTHOLD0_bp 4
#define EXTHOLD0_bm (1 << EXTHOLD0_bp)
#define SMB0TOE_bp 3
#define SMB0TOE_bm (1 << SMB0TOE_bp)
#define SMB0FTE_bp 2
#define SMB0FTE_bm (1 << SMB0FTE_bp)

#define SMB0CS_gp 0
#define SMB0CS_gm 0x03
enum {
    SMB0CS_TIMER0_OVF    = 0b00,
    SMB0CS_TIMER1_OVF    = 0b01,
    SMB0CS_TIMER2_OVF_HI = 0b10,
    SMB0CS_TIMER2_OVF_LO = 0b11,
};
enum {
    SMB0CS_TIMER0_OVF_gc    = 0b00 << SMB0CS_gp,
    SMB0CS_TIMER1_OVF_gc    = 0b01 << SMB0CS_gp,
    SMB0CS_TIMER2_OVF_HI_gc = 0b10 << SMB0CS_gp,
    SMB0CS_TIMER2_OVF_LO_gc = 0b11 << SMB0CS_gp,
};

// SMB1CF: SMBus Clock/Configuration
#define ENSMB1_bp 7
#define ENSMB1_bm (1 << ENSMB1_bp)
#define INH1_bp 6
#define INH1_bm (1 << INH1_bp)
#define BUSY1_bp 5
#define BUSY1_bm (1 << BUSY1_bp)
#define EXTHOLD1_bp 4
#define EXTHOLD1_bm (1 << EXTHOLD1_bp)
#define SMB1TOE_bp 3
#define SMB1TOE_bm (1 << SMB1TOE_bp)
#define SMB1FTE_bp 2
#define SMB1FTE_bm (1 << SMB1FTE_bp)

#define SMB1CS_gp 0
#define SMB1CS_gm 0x03
enum {
    SMB1CS_TIMER0_OVF    = 0b00,
    SMB1CS_TIMER1_OVF    = 0b01,
    SMB1CS_TIMER2_OVF_HI = 0b10,
    SMB1CS_TIMER2_OVF_LO = 0b11,
};
enum {
    SMB1CS_TIMER0_OVF_gc    = 0b00 << SMB1CS_gp,
    SMB1CS_TIMER1_OVF_gc    = 0b01 << SMB1CS_gp,
    SMB1CS_TIMER2_OVF_HI_gc = 0b10 << SMB1CS_gp,
    SMB1CS_TIMER2_OVF_LO_gc = 0b11 << SMB1CS_gp,
};

// SMBTC: SMBus Timing Control

#define SMB1SDD_gp 2
#define SMB1SDD_gm 0x0c
enum {
    SMB1SDD_0_CYCLES = 0b00,
    SMB1SDD_2_CYCLES = 0b01,
    SMB1SDD_4_CYCLES = 0b10,
    SMB1SDD_8_CYCLES = 0b11,
};
enum {
    SMB1SDD_0_CYCLES_gc = 0b00 << SMB1SDD_gp,
    SMB1SDD_2_CYCLES_gc = 0b01 << SMB1SDD_gp,
    SMB1SDD_4_CYCLES_gc = 0b10 << SMB1SDD_gp,
    SMB1SDD_8_CYCLES_gc = 0b11 << SMB1SDD_gp,
};

#define SMB0SDD_gp 0
#define SMB0SDD_gm 0x03
enum {
    SMB0SDD_0_CYCLES = 0b00,
    SMB0SDD_2_CYCLES = 0b01,
    SMB0SDD_4_CYCLES = 0b10,
    SMB0SDD_8_CYCLES = 0b11,
};
enum {
    SMB0SDD_0_CYCLES_gc = 0b00 << SMB0SDD_gp,
    SMB0SDD_2_CYCLES_gc = 0b01 << SMB0SDD_gp,
    SMB0SDD_4_CYCLES_gc = 0b10 << SMB0SDD_gp,
    SMB0SDD_8_CYCLES_gc = 0b11 << SMB0SDD_gp,
};


// SMB0CN: SMBus Control
#define MASTER0_bp 7
#define MASTER0_bm (1 << MASTER0_bp)
#define TXMODE0_bp 6
#define TXMODE0_bm (1 << TXMODE0_bp)
#define STA0_bp 5
#define STA0_bm (1 << STA0_bp)
#define STO0_bp 4
#define STO0_bm (1 << STO0_bp)
#define ACKRQ0_bp 3
#define ACKRQ0_bm (1 << ACKRQ0_bp)
#define ARBLOST0_bp 2
#define ARBLOST0_bm (1 << ARBLOST0_bp)
#define ACK0_bp 1
#define ACK0_bm (1 << ACK0_bp)
#define SI0_bp 0
#define SI0_bm (1 << SI0_bp)

// SMB1CN: SMBus Control
#define MASTER1_bp 7
#define MASTER1_bm (1 << MASTER1_bp)
#define TXMODE1_bp 6
#define TXMODE1_bm (1 << TXMODE1_bp)
#define STA1_bp 5
#define STA1_bm (1 << STA1_bp)
#define STO1_bp 4
#define STO1_bm (1 << STO1_bp)
#define ACKRQ1_bp 3
#define ACKRQ1_bm (1 << ACKRQ1_bp)
#define ARBLOST1_bp 2
#define ARBLOST1_bm (1 << ARBLOST1_bp)
#define ACK1_bp 1
#define ACK1_bm (1 << ACK1_bp)
#define SI1_bp 0
#define SI1_bm (1 << SI1_bp)

// SMB0ADR: SMBus0 Slave Address

#define SLV0_gp 1
#define SLV0_gm 0xfe

#define GC0_bp 0
#define GC0_bm (1 << GC0_bp)

// SMB0ADM: SMBus0 Slave Address Mask
#define SLVM0_gp 1
#define SLVM0_gpm 0xfe

#define EHACK0_bp 0
#define EHACK0_bm (1 << EHACK0_bp)

// SMB1ADR: SMBus1 Slave Address

#define SLV1_gp 1
#define SLV1_gm 0xfe

#define GC1_bp 0
#define GC1_bm (1 << GC0_bp)

// SMB1ADM: SMBus1 Slave Address Mask
#define SLVM1_gp 1
#define SLVM1_gm 0xfe

#define EHACK1_bp 0
#define EHACK1_bm (1 << EHACK1_bp)

///////////////////////////////////////////////////////////////////////////////
//                              UART                                         //
///////////////////////////////////////////////////////////////////////////////

// SCON0: Serial Port 0 Control
#define S0MODE_bp 7
#define S0MODE_bm (1 << S0MODE_bp)
#define MCE0_bp 5
#define MCE0_bm (1 << MCE0_bp)
#define REN0_bp 4
#define REN0_bm (1 << REN0_bp)
#define TB80_bp 3
#define TB80_bm (1 << TB80_bp)
#define RB80_bp 2
#define RB80_bm (1 << RB80_bp)
#define TI0_bp 1
#define TI0_bm (1 << TI0_bp)
#define RI0_bp 0
#define RI0_bm (1 << RI0_bp)

// SCON1: UART1 Control
#define OVR1_bp 7
#define OVR1_bm (1 << OVR1_bp)
#define PERR1_bp 6
#define PERR1_bm (1 << PERR1_bp)
#define THRE1_bp 5
#define THRE1_bm (1 << THRE1_bp)
#define REN1_bp 4
#define REN1_bm (1 << REN1_bp)
#define TBX1_bp 3
#define TBX1_bm (1 << TBX1_bp)
#define RBX1_bp 2
#define RBX1_bm (1 << RBX1_bp)
#define TI1_bp 1
#define TI1_bm (1 << TI1_bp)
#define RI1_bp 0
#define RI1_bm (1 << RI1_bp)

// SMOD1: UART1 Mode
#define MCE1_bp 7
#define MCE1_bm (1 << MCE1_bp)

#define S1PT_gp 5
#define S1PT_gm 0x60
enum {
    S1PT_ODD   = 0b00,
    S1PT_EVEN  = 0b01,
    S1PT_MARK  = 0b10,
    S1PT_SPACE = 0b11,
};
enum {
    S1PT_ODD_gc   = 0b00 << S1PT_gp,
    S1PT_EVEN_gc  = 0b01 << S1PT_gp,
    S1PT_MARK_gc  = 0b10 << S1PT_gp,
    S1PT_SPACE_gc = 0b11 << S1PT_gp,
};

#define PE1_bp 4
#define PE1_bm (1 << PE1_bp)

#define S1DL_gp 2
#define S1DL_gm 0xc0
enum {
    S1DL_5_BIT = 0b00,
    S1DL_6_BIT = 0b01,
    S1DL_7_BIT = 0b10,
    S1DL_8_BIT = 0b11,
};
enum {
    S1DL_5_BIT_gc = 0b00 << S1DL_gp,
    S1DL_6_BIT_gc = 0b01 << S1DL_gp,
    S1DL_7_BIT_gc = 0b10 << S1DL_gp,
    S1DL_8_BIT_gc = 0b11 << S1DL_gp,
};

#define XBE1_bp 1
#define XBE1_bm (1 << XBE1_bp)
#define SBL1_bp 0
#define SBL1_bm (1 << SBL1_bp)

// SBCON1: UART1 Baud Rate Generator Control
#define SB1RUN_bp 6
#define SB1RUN_bm (1 << SB1RUN_bp)

#define SB1PS_gp 0
#define SB1PS_gm 0x03
enum {
    SB1PS_PRESCALE_12 = 0b00,
    SB1PS_PRESCALE_4  = 0b01,
    SB1PS_PRESCALE_48 = 0b10,
    SB1PS_PRESCALE_1  = 0b11,
};
enum {
    SB1PS_PRESCALE_12_gc = 0b00 << SB1PS_gp,
    SB1PS_PRESCALE_4_gc  = 0b01 << SB1PS_gp,
    SB1PS_PRESCALE_48_gc = 0b10 << SB1PS_gp,
    SB1PS_PRESCALE_1_gc  = 0b11 << SB1PS_gp,
};

///////////////////////////////////////////////////////////////////////////////
//                              SPI                                          //
///////////////////////////////////////////////////////////////////////////////

// SPI0CFG: SPI0 Configuration
#define SPIBSY_bp 7
#define SPIBSY_bm (1 << SPIBSY_bp)
#define MSTEN_bp 6
#define MSTEN_bm (1 << MSTEN_bp)
#define CKPHA_bp 5
#define CKPHA_bm (1 << CKPHA_bp)
#define CKPOL_bp 4
#define CKPOL_bm (1 << CKPOL_bp)
#define SLVSEL_bp 3
#define SLVSEL_bm (1 << SLVSEL_bp)
#define NSSIN_bp 2
#define NSSIN_bm (1 << NSSIN_bp)
#define SRMT_bp 1
#define SRMT_bm (1 << SRMT_bp)
#define RXBMT_bp 0
#define RXBMT_bm (1 << RXBMT_bp)

// SPI0CN: SPI0 Control
#define SPIF_bp 7
#define SPIF_bm (1 << SPIF_bp)
#define WCOL_bp 6
#define WCOL_bm (1 << WCOL_bp)
#define MODF_bp 5
#define MODF_bm (1 << MODF_bp)
#define RXOVRN_bp 4
#define RXOVRN_bm (1 << RXOVRN_bp)

#define NSSMD_gp 0
#define NSSMD_gm 0x0c
enum {
    NSSMD_3_WIRE = 0b00,
    NSSMD_4_WIRE_SLAVE_MASTER = 0b01,
    NSSMD_4_WIRE_SINGLE_MASTER = 0b10,
};

#define TXBMT_bp 1
#define TXBMT_bm (1 << TXBMT_bp)
#define SPIEN_bp 0
#define SPIEN_bm (1 << SPIEN_bp)

///////////////////////////////////////////////////////////////////////////////
//                              TIMERS                                       //
///////////////////////////////////////////////////////////////////////////////

// CKCON: Clock Control
#define T3MH_bp 7
#define T3MH_bm (1 << T3MH_bp)
#define T3ML_bp 6
#define T3ML_bm (1 << T3ML_bp)
#define T2MH_bp 5
#define T2MH_bm (1 << T2MH_bp)
#define T2ML_bp 4
#define T2ML_bm (1 << T2ML_bp)
#define T1M_bp 3
#define T1M_bm (1 << T1M_bp)
#define T0M_bp 2
#define T0M_bm (1 << T0M_bp)

#define SCA_gp 0
#define SCA_gm 0x03
enum {
    SCA_SYSTEM_CLK_DIV_12  = 0b00,
    SCA_SYSTEM_CLK_DIV_4   = 0b01,
    SCA_SYSTEM_CLK_DIV_48  = 0b10,
    SCA_EXTERNAL_CLK_DIV_8 = 0b11,
};
enum {
    SCA_SYSTEM_CLK_DIV_12_gc  = 0b00 << SCA_gp,
    SCA_SYSTEM_CLK_DIV_4_gc   = 0b01 << SCA_gp,
    SCA_SYSTEM_CLK_DIV_48_gc  = 0b10 << SCA_gp,
    SCA_EXTERNAL_CLK_DIV_8_gc = 0b11 << SCA_gp,
};

// CKCON1: Clock Control 1
#define T5MH_bp 3
#define T5MH_bm (1 << T5MH_bp)
#define T5ML_bp 2
#define T5ML_bm (1 << T5ML_bp)
#define T4MH_bp 1
#define T4MH_bm (1 << T4MH_bp)
#define T4ML_bp 0
#define T4ML_bm (1 << T4ML_bp)

// TCON: Timer Control
#define TF1_bp 7
#define TF1_bm (1 << TF1_bp)
#define TR1_bp 6
#define TR1_bm (1 << TR1_bp)
#define TF0_bp 5
#define TF0_bm (1 << TF0_bp)
#define TR0_bp 4
#define TR0_bm (1 << TR0_bp)
#define IE1_bp 3
#define IE1_bm (1 << IE1_bp)
#define IT1_bp 2
#define IT1_bm (1 << IT1_bp)
#define IE0_bp 1
#define IE0_bm (1 << IE0_bp)
#define IT0_bp 0
#define IT0_bm (1 << IT0_bp)

// TMOD: Timer Mode
#define GATE1_bp 7
#define GATE1_bm (1 << GATE1_bp)
#define CT1_bp 6
#define CT1_bm (1 << CT1_bp)

#define T1M_gp 4
#define T1M_gm 0x30
enum {
    T1M_13_BIT     = 0b00,
    T1M_16_BIT     = 0b01,
    T1M_8_BIT_AUTO = 0b10,
    T1M_INACTIVE   = 0b11,
};
enum {
    T1M_13_BIT_gc     = 0b00 << T1M_gp,
    T1M_16_BIT_gc     = 0b01 << T1M_gp,
    T1M_8_BIT_AUTO_gc = 0b10 << T1M_gp,
    T1M_INACTIVE_gc   = 0b11 << T1M_gp,
};

#define GATE0_bp 3
#define GATE0_bm (1 << GATE0_bp)
#define CT0_bp 2
#define CT0_bm (1 << CT0_bp)
#define T0M_gp 0
#define T0M_gm 0x03
enum {
    T0M_13_BIT     = 0b00,
    T0M_16_BIT     = 0b01,
    T0M_8_BIT_AUTO = 0b10,
    T0M_TWO_8_BIT  = 0b11,
};
enum {
    T0M_13_BIT_gc     = 0b00 << T0M_gp,
    T0M_16_BIT_gc     = 0b01 << T0M_gp,
    T0M_8_BIT_AUTO_gc = 0b10 << T0M_gp,
    T0M_TWO_8_BIT_gc  = 0b11 << T0M_gp,
};

// TMR2CN: Timer 2 Control
#define TF2H_bp 7
#define TF2H_bm (1 << TF2H_bp)
#define TF2L_bp 6
#define TF2L_bm (1 << TF2L_bp)
#define TF2LEN_bp 5
#define TF2LEN_bm (1 << TF2LEN_bp)
#define TF2CEN_bp 4
#define TF2CEN_bm (1 << TF2CEN_bp)
#define T2SPLIT_bp 3
#define T2SPLIT_bm (1 << T2SPLIT_bp)
#define TR2_bp 2
#define TR2_bm (1 << TR2_bp)
#define T2CSS_bp 1
#define T2CSS_bm (1 << T2CSS_bp)
#define T2XCLK_bp 0
#define T2XCLK_bm (1 << T2XCLK_bp)

// TMR3CN: Timer 3 Control
#define TF3H_bp 7
#define TF3H_bm (1 << TF3H_bp)
#define TF3L_bp 6
#define TF3L_bm (1 << TF3L_bp)
#define TF3LEN_bp 5
#define TF3LEN_bm (1 << TF3LEN_bp)
#define TF3CEN_bp 4
#define TF3CEN_bm (1 << TF3CEN_bp)
#define T3SPLIT_bp 3
#define T3SPLIT_bm (1 << T3SPLIT_bp)
#define TR3_bp 2
#define TR3_bm (1 << TR3_bp)
#define T3CSS_bp 1
#define T3CSS_bm (1 << T3CSS_bp)
#define T3XCLK_bp 0
#define T3XCLK_bm (1 << T3XCLK_bp)

// TMR4CN: Timer 4 Control
#define TF4H_bp 7
#define TF4H_bm (1 << TF4H_bp)
#define TF4L_bp 6
#define TF4L_bm (1 << TF4L_bp)
#define TF4LEN_bp 5
#define TF4LEN_bm (1 << TF4LEN_bp)
#define T4SPLIT_bp 3
#define T4SPLIT_bm (1 << T4SPLIT_bp)
#define TR4_bp 2
#define TR4_bm (1 << TR4_bp)
#define T4XCLK_bp 0
#define T4XCLK_bm (1 << T4XCLK_bp)

// TMR5CN: Timer 5 Control
#define TF5H_bp 7
#define TF5H_bm (1 << TF5H_bp)
#define TF5L_bp 6
#define TF5L_bm (1 << TF5L_bp)
#define TF5LEN_bp 5
#define TF5LEN_bm (1 << TF5LEN_bp)
#define T5SPLIT_bp 3
#define T5SPLIT_bm (1 << T5SPLIT_bp)
#define TR5_bp 2
#define TR5_bm (1 << TR5_bp)
#define T5XCLK_bp 0
#define T5XCLK_bm (1 << T5XCLK_bp)

///////////////////////////////////////////////////////////////////////////////
//                       Programmable Counter Array                          //
///////////////////////////////////////////////////////////////////////////////

// PCA0CN: PCA Control
#define CF_bp 7
#define CF_bm (1 << CF_bp)
#define CR_bp 6
#define CR_bm (1 << CR_bp)
#define CCF4_bp 4
#define CCF4_bm (1 << CCF4_bp)
#define CCF3_bp 3
#define CCF3_bm (1 << CCF3_bp)
#define CCF2_bp 2
#define CCF2_bm (1 << CCF2_bp)
#define CCF1_bp 1
#define CCF1_bm (1 << CCF1_bp)
#define CCF0_bp 0
#define CCF0_bm (1 << CCF0_bp)

// PCA0MD: PCA Mode
#define CIDL_bp 7
#define CIDL_bm (1 << CIDL_bp)
#define WDTE_bp 6
#define WDTE_bm (1 << WDTE_bp)
#define WDLCK_bp 5
#define WDLCK_bm (1 << WDLCK_bp)

#define CPS_gp 0
#define CPS_gm 0x0e
enum {
    CPS_SYSTEM_CLK_DIV_12  = 0b000,
    CPS_SYSTEM_CLK_DIV_4   = 0b001,
    CPS_TIMER0_OVF         = 0b010,
    CPS_HI_TO_LO_ECI       = 0b011,
    CPS_SYSTEM_CLK         = 0b100,
    CPS_EXTERNAL_CLK_DIV_8 = 0b101,
};
enum {
    CPS_SYSTEM_CLK_DIV_12_gc  = 0b000 << CPS_gp,
    CPS_SYSTEM_CLK_DIV_4_gc   = 0b001 << CPS_gp,
    CPS_TIMER0_OVF_gc         = 0b010 << CPS_gp,
    CPS_HI_TO_LO_ECI_gc       = 0b011 << CPS_gp,
    CPS_SYSTEM_CLK_gc         = 0b100 << CPS_gp,
    CPS_EXTERNAL_CLK_DIV_8_gc = 0b101 << CPS_gp,
};

#define ECF_bp 0
#define ECF_bm (1 << ECF_bp)

// PCA0CPMn: PCA Capture/Compare Mode
#define PWM16n_bp 7
#define PWM16n_bm (1 << PWM16n_bp)
#define ECOMn_bp 6
#define ECOMn_bm (1 << ECOMn_bp)
#define CAPPn_bp 5
#define CAPPn_bm (1 << CAPPn_bp)
#define CAPNn_bp 4
#define CAPNn_bm (1 << CAPNn_bp)
#define MATn_bp 3
#define MATn_bm (1 << MATn_bp)
#define TOGn_bp 2
#define TOGn_bm (1 << TOGn_bp)
#define PWMn_bp 1
#define PWMn_bm (1 << PWMn_bp)
#define ECCFn_bp 0
#define ECCFn_bm (1 << ECCFn_bp)
