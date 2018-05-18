// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "key_handlers/key_media.h"

#include "usb/descriptors.h"
#include "usb/util/hut_consumer.h"
#include "usb/util/hut_desktop.h"

#include "core/keycode.h"

#include "usb_reports/media_report.h"

bit_t is_media_keycode(keycode_t keycode) {
    return IS_MEDIA(keycode);
}

void handle_media_keycode(keycode_t keycode, key_event_t event) REENT {
    uint8_t consumer_code = 0;
    if (event == EVENT_PRESSED) {
        switch (keycode) {
            case KC_MEDIA_NEXT_TRACK   : consumer_code = HID_CONSUMER_SCAN_NEXT_TRACK ; break ;
            case KC_MEDIA_PREV_TRACK   : consumer_code = HID_CONSUMER_SCAN_PREVIOUS_TRACK ; break ;
            case KC_MEDIA_FAST_FORWARD : consumer_code = HID_CONSUMER_FAST_FORWARD ; break ;
            case KC_MEDIA_REWIND       : consumer_code = HID_CONSUMER_REWIND ; break ;
            case KC_MEDIA_STOP         : consumer_code = HID_CONSUMER_STOP ; break ;
            case KC_MEDIA_EJECT        : consumer_code = HID_CONSUMER_EJECT ; break ;
            case KC_MEDIA_PLAY_PAUSE   : consumer_code = HID_CONSUMER_PLAY_PAUSE ; break ;
            case KC_AUDIO_MUTE         : consumer_code = HID_CONSUMER_MUTE             ; break ;
            case KC_AUDIO_VOL_UP       : consumer_code = HID_CONSUMER_VOLUME_INCREMENT ; break ;
            case KC_AUDIO_VOL_DOWN     : consumer_code = HID_CONSUMER_VOLUME_DECREMENT ; break ;
        }
        g_media_report.report_id = REPORT_ID_CONSUMER;
        g_media_report.code = consumer_code;
        touch_media_report();
    } else if (event == EVENT_RELEASED) {
        g_media_report.report_id = REPORT_ID_CONSUMER;
        g_media_report.code = 0;
        touch_media_report();
    }
}

XRAM keycode_callbacks_t media_keycodes = {
    .checker = is_media_keycode,
    .handler = handle_media_keycode,
};
