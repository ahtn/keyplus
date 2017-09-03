// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include "core/util.h"

// Consumer Page(0x0C)
/* #define TRANSPORT_RECORD        0x00B2 */
/* #define TRANSPORT_FAST_FORWARD  0x00B3 */
/* #define TRANSPORT_REWIND        0x00B4 */
/* #define TRANSPORT_NEXT_TRACK    0x00B5 */
/* #define TRANSPORT_PREV_TRACK    0x00B6 */
/* #define TRANSPORT_STOP          0x00B7 */
/* #define TRANSPORT_EJECT         0x00B8 */

/* #define TRANSPORT_STOP_EJECT    0x00CC */
/* #define TRANSPORT_PLAY_PAUSE    0x00CD */
/* #define AUDIO_MUTE              0x00E2 */
/* #define AUDIO_VOL_UP            0x00E9 */
/* #define AUDIO_VOL_DOWN          0x00EA */


/* #define APPLAUNCH_CC_CONFIG     0x0183 */
/* #define APPLAUNCH_EMAIL         0x018A */
/* #define APPLAUNCH_CALCULATOR    0x0192 */
/* #define APPLAUNCH_LOCAL_BROWSER 0x0194 */
/* #define APPLAUNCH_LOCK          0x019E */
/* #define APPCONTROL_MINIMIZE     0x0206 */
/* #define APPCONTROL_SEARCH       0x0221 */
/* #define APPCONTROL_HOME         0x0223 */
/* #define APPCONTROL_BACK         0x0224 */
/* #define APPCONTROL_FORWARD      0x0225 */
/* #define APPCONTROL_STOP         0x0226 */
/* #define APPCONTROL_REFRESH      0x0227 */
/* #define APPCONTROL_BOOKMARKS    0x022A */

/* /1* Generic Desktop Page(0x01) - system power control *1/ */
/* #define SYSTEM_POWER_DOWN       0x0081 */
/* #define SYSTEM_SLEEP            0x0082 */
/* #define SYSTEM_WAKE_UP          0x0083 */

// this is what the data that we send to the host is comprised of
typedef struct {
    uint8_t id;
    uint16_t code;
} hid_report_media_t;

extern XRAM hid_report_media_t g_media_report;
extern bit_t g_report_pending_media;

void reset_media_report(void);

bit_t is_ready_media_report(void);
bit_t send_media_report(void);
