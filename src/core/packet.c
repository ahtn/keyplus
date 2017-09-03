// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/packet.h"

#include "core/settings.h"

uint8_t get_packet_type(const packet_t *packet) {
    return packet->gen.type;
}

void set_packet_type(packet_t *packet, uint8_t type) {
    packet->gen.type = type;
}

bool is_matrix_packet(packet_t *packet) {
    uint8_t type = packet->gen.type >> PACKET_MATRIX_TYPE_BIT_POS;
    return type <= PACKET_MATRIX_DELTA_LIST;
}

/* void set_packet_uid(void) { */
/*  packet->gen.device_id = g_settings.device_id; */
/*  packet->gen.is_master = 0; /1* TODO: load based on *1/ */
/*  packet->gen.packet_id = get_unique_pid(); */
/* } */
