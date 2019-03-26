// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"
#include "core/keycode.h"

#define UNIFYING_PAIR_FAILED 0
#define UNIFYING_PAIR_IN_PROGRESS 1
#define UNIFYING_PAIR_FINISHED 2
#define UNIFYING_PAIR_DISABLED 255

// If pairing is not complete in this time, fail
#define UNIFYING_PAIRING_TIMEOUT 20000
#define UNIFYING_PAIRING_PACKET_TIMEOUT 2000

#define KEYPLUS_HIDPP_SOFTWARE_ID 0x0D

typedef enum {
    UNIFYING_FRAME_HIDPP_SHORT = 0x10,
    UNIFYING_FRAME_HIDPP_LONG  = 0x11,

    UNIFYING_FRAME_UNENCRYPTED_HID = 0xC1,
    UNIFYING_FRAME_MOUSE = 0xC2,
    UNIFYING_FRAME_MEDIA = 0xC3,

    UNIFYING_FRAME_EXTRA_BUTTON = 0xD1,
    UNIFYING_FRAME_ENCRYPTED_HID = 0xD3,

    UNIFYING_FRAME_KEEP_ALIVE_1 = 0x40,
    UNIFYING_FRAME_KEEP_ALIVE_2 = 0x4F,

    UNIFYING_FRAME_HIDPP_SHORT_RESP = 0x50,
    UNIFYING_FRAME_HIDPP_LONG_RESP = 0x51,

    UNIFYING_FRAME_PAIRING = 0x5f,

    // Seem to be have the same as 0x10 and 0x11 respectively
    // UNIFYING_FRAME_HIDPP_2 = 0x30,
    // UNIFYING_FRAME_HIDPP_3 = 0x31,
    // UNIFYING_FRAME_HIDPP_4 = 0x90,
    // UNIFYING_FRAME_HIDPP_5 = 0x91,
    // UNIFYING_FRAME_HIDPP_6 = 0xB0,
    // UNIFYING_FRAME_HIDPP_7 = 0xB1,
} unifying_frame_type_t;

typedef enum {
    UNIFYING_EXTRA_MIDDLE    = 0xAF,
    UNIFYING_EXTRA_SIDE_UP   = 0xB0,
    UNIFYING_EXTRA_SIDE_DOWN = 0xAE,
} unifying_extra_button;

typedef enum {
    UNIFYING_MSB_LEFT = 0x01,
    UNIFYING_MSB_RIGHT = 0x02,
    UNIFYING_MSB_MIDDLE = 0x04,
    UNIFYING_MSB_FORWARD = 0x08,
    UNIFYING_MSB_BACK = 0x10,

    // Not offically used in Logitech software, but used to store extra mouse
    // buttons in keyplus.
    UNIFYING_MSB_EXTRA_1 = 0x20,
    UNIFYING_MSB_EXTRA_2 = 0x40,
    UNIFYING_MSB_EXTRA_3 = 0x80,
} unifying_mouse_button_mask_t;

typedef enum {
    UNIFYING_MOUSE_INACTIVE = 0x00,
    UNIFYING_MOUSE_ACTIVE = 0x01,
    UNIFYING_MOUSE_EXTRA_BUTTON = 0x02,
} unifying_mouse_activity_t;

typedef struct {
    uint8_t id;
    uint8_t type;
    uint8_t step;
} unifying_packet_header_t;

// Unifying Pairing packet step 1
typedef struct {
    uint8_t id; //< sending device id
    /// frame_type == 0x0f -> device to receiver
    /// frame_type == 0x1f -> receiver to device
    uint8_t frame_type;
    uint8_t step; //< step == 1
    uint8_t addr[5];
    uint8_t unknown_1;
    uint16_t pid;
    uint8_t unknown_2[2];
    uint16_t type;
    uint8_t unknown_3[5];
    uint8_t unknown_4;
    uint8_t checksum;
} unifying_req_1_t;

typedef struct {
    uint8_t id; //< sending device id
    uint8_t frame_type;
    uint8_t step; //< step == 2
    uint8_t crypto[4];
    uint8_t serial[4];
    uint16_t ability;
    uint8_t unknown_1[8];
    uint8_t checksum;
} unifying_req_2_t;

typedef struct {
    uint8_t id; //< sending device id
    uint8_t frame_type;
    uint8_t step; //< step == 3
    uint8_t unknown_1[2];
    uint8_t len;
    uint8_t dev_str[16];
    uint8_t checksum;
} unifying_req_3_t;

typedef struct {
    uint8_t id; //< sending device id
    uint8_t frame_type;
    uint8_t step; //< step == 3
    uint8_t crypto[6];
    uint8_t checksum;
} unifying_resp_3_t;

typedef struct {
    uint8_t id; //< sending device id
    uint8_t frame_type;
    uint8_t step;
    uint8_t cryto[6];
    uint8_t checksum;
} unifying_req_4_t;

typedef union unifying_packet_t {
    unifying_packet_header_t header;
    unifying_req_1_t req_1;
    unifying_req_2_t req_2;
    unifying_req_3_t req_3;
    unifying_resp_3_t resp_3;
    unifying_req_4_t req_4;
} unifying_packet_t;

typedef struct unifying_mouse_state_t {
    uint8_t buttons_1;
    uint8_t buttons_2;
    int16_t x;
    int16_t y;
    int8_t wheel_x;
    int8_t wheel_y;
} unifying_mouse_state_t;

/// Unifying basic mouse packet
///
/// frame_type: 0x2C
/// size: 10
typedef struct unifying_mouse_packet_t {
    uint8_t id; //< sending device id
    uint8_t frame_type;
    uint8_t buttons;
    uint8_t unknown;
    /// 8 least significant bits of 12bit x data
    uint8_t x0;
    /// The lower nibble contains the 4 most significant bits of x data.
    /// The upper nibble contains the 4 least significant bits of y data.
    ///
    /// b7 | b6 | b5 | b4 | b3  | b2  | b1  | b0  |
    /// Y3 | Y2 | Y1 | Y0 | x11 | x10 | x9  | x8  |
    uint8_t x1y0;
    /// 8 most significant bits of 12bit y data
    uint8_t y1;
    int8_t wheel_y;
    int8_t wheel_x;
    uint8_t checksum;
} unifying_mouse_packet_t;

/// Unifying keep alive packet
/// Keep the RF channel on the unifying receiver open for the given amount of
/// time. If the device does not connect the receiver before this time is up,
/// the unifying receiver will switch channels.
///
/// NOTE: When observing a devices, it seems they cycle through their channel
/// table in 180ms??? when they can't make contact with the receiver.
///
/// NOTE: from dissasembly, when sending packet unifying receiver uses
/// 15 retransmits with 1ms delay
///
/// NOTE: Unifying receiver listen to one of 24 rf channels. Thes channels
/// are pulled from this lookup table: [
///     5  , 8  , 11 , 14 , 17 , 20 , 23 , 26 ,
///     29 , 32 , 35 , 38 , 41 , 44 , 47 , 50 ,
///     53 , 56 , 59 , 62 , 65 , 68 , 71 , 74
/// ]
///
/// frame_type: 0x40
/// size: 5
typedef struct unifying_keep_alive_t {
    uint8_t id; //< sending device id
    uint8_t frame_type;
    /// The keep alive time in millseconds.
    /// NOTE: network byte order is big endian
    uint16_t keep_alive_time;
    uint8_t checksum;
} unifying_keep_alive_t;

/// Unifying long keep alive packet
/// Seems to be sent when transitioning between different keep alive states,
/// but otherwise seems to behave the same as the 0x40 packet type.
///
/// frame_type: 0x4f
/// size: 10
typedef struct unifying_keep_alive_long_t {
    uint8_t id; //< sending device id
    uint8_t frame_type;
    uint8_t buttons;
    uint8_t unknown_0;
    /// The keep alive time in millseconds.
    /// NOTE: network byte order is big endian
    uint16_t keep_alive_time;
    uint8_t unknown_1[4];
    uint8_t checksum;
} unifying_keep_alive_long_t;


// Unifying HID++ long packet
//
// frame_type: 0x11
// size: 22
typedef struct unifying_hidpp10_long_t {
    uint8_t id; //< sending device id
    uint8_t frame_type; //< frame_type == 0x11
    uint8_t device_index;
    uint8_t sub_id;
    uint8_t parameters[17];
    uint8_t checksum;
} unifying_hidpp10_long_t;

// Unifying HID++ short packet
//
// frame_type: 0x10
// size: 10
typedef struct unifying_hidpp10_t {
    uint8_t id; //< sending device id
    uint8_t frame_type; //< frame_type == 0x10
    uint8_t device_index;
    uint8_t sub_id;
    uint8_t parameters[4];
    uint8_t unused;
    uint8_t checksum;
} unifying_hidpp10_t;

// Unifying HID++ long packet
//
// frame_type: 0x11
// size: 22
typedef struct unifying_hidpp20_long_t {
    uint8_t id; //< sending device id
    uint8_t frame_type; //< frame_type == 0x11
    uint8_t device_index;
    uint8_t feature_index;
    uint8_t software_id : 4;
    uint8_t function_id : 4;
    uint8_t parameters[16];
    uint8_t checksum;
} unifying_hidpp20_long_t;

// Unifying HID++ short packet
//
// frame_type: 0x10
// size: 10
typedef struct unifying_hidpp20_t {
    uint8_t id; //< sending device id
    uint8_t frame_type; //< frame_type == 0x10
    uint8_t device_index;
    uint8_t feature_index;
    uint8_t software_id : 4;
    uint8_t function_id : 4;
    uint8_t parameters[3];
    uint8_t unused;
    uint8_t checksum;
} unifying_hidpp20_t;

// Unifying HID++ special keys packet
//
// frame_type: 0x51
// size: 22
typedef struct unifying_hidpp20_diverted_buttons_t {
    uint8_t id; //< sending device id
    uint8_t frame_type; //< frame_type == 0x51
    uint8_t device_index;
    uint8_t feature_index;
    uint8_t software_id : 4; // 0
    uint8_t function_id : 4; // 0
    uint16_t control_id_list[4]; //
    uint8_t padding[7];
    uint8_t checksum;
} unifying_hidpp20_diverted_buttons_t;

enum {
    GESTURE_STATE_INACTIVE = 0,
    GESTURE_STATE_SCANNING = 1,
    GESTURE_STATE_ACTIVATED = 2,
};

enum {
    GESTURE_LEFT = 0,
    GESTURE_RIGHT = 1,
    GESTURE_UP = 2,
    GESTURE_DOWN = 3,
    GESTURE_UP_LEFT = 4,
    GESTURE_UP_RIGHT = 5,
    GESTURE_DOWN_LEFT = 6,
    GESTURE_DOWN_RIGHT = 7,
    GESTURE_TAP = 8,
};

#define EKC_GESTURE_LEFT_ADDR 0x06
typedef struct gesture_state_t {
    uint8_t state;
    int16_t x;
    int16_t y;
    uint8_t kb_id;
    uint16_t ekc_addr;
    keycode_t triggered_kc;
    int16_t threshold;
    int16_t threshold_diag;
    int16_t threshold_tap;
} gesture_state_t;

extern XRAM unifying_mouse_state_t g_unifying_mouse_state;
extern XRAM uint8_t g_unifying_mouse_state_changed;

uint8_t unifying_calc_checksum(const XRAM uint8_t *data, const uint8_t len);

void unifying_send_packet(const XRAM uint8_t *data, uint8_t size);
void unifying_read_packet(const uint8_t XRAM *nrf_packet, uint8_t width);
void unifying_mouse_handle(void);
void unifying_begin_pairing(void);
void unifying_pairing_poll(void);

void gesture_init(void);
void gesture_press(uint16_t ekc_addr, uint8_t kd_id);
void gesture_release(uint16_t ekc_addr, uint8_t kd_id);

bit_t unifying_is_pairing_active(void);
