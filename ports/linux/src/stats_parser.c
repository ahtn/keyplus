// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#define JSMN_STRICT
#include "jsmn.h"

#define MAX_JSMN_TOKS 8192

// #include <stdlib.h>
#include <stdio.h>

#include "usb/util/hut_keyboard.h"
#include "core/settings.h"
#include "event_mapper.h"
#include "debug.h"
#include "stats.h"

static const char *m_buf;
static int m_cur;
static int m_tok_count;
static jsmntok_t *m_toks;

#define HID_CODE_MAX (sizeof(hid_code_table) / sizeof(struct hid_code_name))

struct hid_code_name {
    uint16_t code;
    const char* name;
};

static struct hid_code_name hid_code_table[] = {
    { KC_NONE, "NONE", },
    { KC_ERROR_ROLL_OVER, "ERROR_ROLL_OVER", },
    { KC_POST_FAIL, "POST_FAIL", },
    { KC_ERROR_UNDEFINED, "ERROR_UNDEFINED", },
    { KC_A, "A" },
    { KC_B, "B" },
    { KC_C, "C" },
    { KC_D, "D" },
    { KC_E, "E" },
    { KC_F, "F" },
    { KC_G, "G" },
    { KC_H, "H" },
    { KC_I, "I" },
    { KC_J, "J" },
    { KC_K, "K" },
    { KC_L, "L" },
    { KC_M, "M" },
    { KC_N, "N" },
    { KC_O, "O" },
    { KC_P, "P" },
    { KC_Q, "Q" },
    { KC_R, "R" },
    { KC_S, "S" },
    { KC_T, "T" },
    { KC_U, "U" },
    { KC_V, "V" },
    { KC_W, "W" },
    { KC_X, "X" },
    { KC_Y, "Y" },
    { KC_Z, "Z" },
    { KC_1, "1" },
    { KC_2, "2" },
    { KC_3, "3" },
    { KC_4, "4" },
    { KC_5, "5" },
    { KC_6, "6" },
    { KC_7, "7" },
    { KC_8, "8" },
    { KC_9, "9" },
    { KC_0, "0" },
    { KC_ENTER, "ENTER" },
    { KC_ESCAPE, "ESCAPE" },
    { KC_BACKSPACE, "BACKSPACE" },
    { KC_TAB, "TAB" },
    { KC_SPACEBAR, "SPACEBAR" },
    { KC_MINUS, "MINUS" },
    { KC_EQUAL, "EQUAL" },
    { KC_LEFT_BRACKET, "LEFT_BRACKET" },
    { KC_RIGHT_BRACKET, "RIGHT_BRACKET" },
    { KC_BACK_SLASH, "BACK_SLASH" },
    { KC_ISO_HASH, "ISO_HASH" },
    { KC_SEMICOLON, "SEMICOLON" },
    { KC_APOSTROPHE, "APOSTROPHE" },
    { KC_GRAVE, "GRAVE" },
    { KC_COMMA, "COMMA" },
    { KC_PERIOD, "PERIOD" },
    { KC_FORWARD_SLASH, "FORWARD_SLASH" },
    { KC_CAPS_LOCK, "CAPS_LOCK" },
    { KC_F1, "F1" },
    { KC_F2, "F2" },
    { KC_F3, "F3" },
    { KC_F4, "F4" },
    { KC_F5, "F5" },
    { KC_F6, "F6" },
    { KC_F7, "F7" },
    { KC_F8, "F8" },
    { KC_F9, "F9" },
    { KC_F10, "F10" },
    { KC_F11, "F11" },
    { KC_F12, "F12" },
    { KC_PRINT_SCREEN, "PRINT_SCREEN" },
    { KC_SCROLL_LOCK, "SCROLL_LOCK" },
    { KC_PAUSE, "PAUSE" },
    { KC_INSERT, "INSERT" },
    { KC_HOME, "HOME" },
    { KC_PAGE_UP, "PAGE_UP" },
    { KC_DELETE, "DELETE" },
    { KC_END, "END" },
    { KC_PAGE_DOWN, "PAGE_DOWN" },
    { KC_RIGHT_ARROW, "RIGHT_ARROW" },
    { KC_LEFT_ARROW, "LEFT_ARROW" },
    { KC_DOWN_ARROW, "DOWN_ARROW" },
    { KC_UP_ARROW, "UP_ARROW" },
    { KC_NUM_LOCK, "NUM_LOCK" },
    { KC_KP_FORWARD_SLASH, "KP_FORWARD_SLASH" },
    { KC_KP_ASTERISK, "KP_ASTERISK" },
    { KC_KP_MINUS, "KP_MINUS" },
    { KC_KP_PLUS, "KP_PLUS" },
    { KC_KP_ENTER, "KP_ENTER" },
    { KC_KP_1, "KP_1" },
    { KC_KP_2, "KP_2" },
    { KC_KP_3, "KP_3" },
    { KC_KP_4, "KP_4" },
    { KC_KP_5, "KP_5" },
    { KC_KP_6, "KP_6" },
    { KC_KP_7, "KP_7" },
    { KC_KP_8, "KP_8" },
    { KC_KP_9, "KP_9" },
    { KC_KP_0, "KP_0" },
    { KC_KP_PERIOD, "KP_PERIOD" },
    { KC_ISO_BACK_SLASH, "ISO_BACK_SLASH" },
    { KC_APPLICATION, "APPLICATION" },
    { KC_POWER, "POWER" },
    { KC_KP_EQUAL, "KP_EQUAL" },
    { KC_F13, "F13" },
    { KC_F14, "F14" },
    { KC_F15, "F15" },
    { KC_F16, "F16" },
    { KC_F17, "F17" },
    { KC_F18, "F18" },
    { KC_F19, "F19" },
    { KC_F20, "F20" },
    { KC_F21, "F21" },
    { KC_F22, "F22" },
    { KC_F23, "F23" },
    { KC_F24, "F24" },
    { KC_EXECUTE, "EXECUTE" },
    { KC_HELP, "HELP" },
    { KC_MENU, "MENU" },
    { KC_SELECT, "SELECT" },
    { KC_STOP, "STOP" },
    { KC_AGAIN, "AGAIN" },
    { KC_UNDO, "UNDO" },
    { KC_CUT, "CUT" },
    { KC_COPY, "COPY" },
    { KC_PASTE, "PASTE" },
    { KC_FIND, "FIND" },
    { KC_MUTE, "MUTE" },
    { KC_VOLUME_UP, "VOLUME_UP" },
    { KC_VOLUME_DOWN, "VOLUME_DOWN" },
    { KC_LOCKING_CAPS_LOCK, "LOCKING_CAPS_LOCK" },
    { KC_LOCKING_NUM_LOCK, "LOCKING_NUM_LOCK" },
    { KC_LOCKING_SCROLL_LOCK, "LOCKING_SCROLL_LOCK" },
    { KC_KP_COMMA, "KP_COMMA" },
    { KC_KP_EQUAL_AS400, "KP_EQUAL_AS400" },
    { KC_INTERNATIONAL_1, "INTERNATIONAL_1" },
    { KC_INTERNATIONAL_2, "INTERNATIONAL_2" },
    { KC_INTERNATIONAL_3, "INTERNATIONAL_3" },
    { KC_INTERNATIONAL_4, "INTERNATIONAL_4" },
    { KC_INTERNATIONAL_5, "INTERNATIONAL_5" },
    { KC_INTERNATIONAL_6, "INTERNATIONAL_6" },
    { KC_INTERNATIONAL_7, "INTERNATIONAL_7" },
    { KC_INTERNATIONAL_8, "INTERNATIONAL_8" },
    { KC_INTERNATIONAL_9, "INTERNATIONAL_9" },
    { KC_LANG_1, "LANG_1" },
    { KC_LANG_2, "LANG_2" },
    { KC_LANG_3, "LANG_3" },
    { KC_LANG_4, "LANG_4" },
    { KC_LANG_5, "LANG_5" },
    { KC_LANG_6, "LANG_6" },
    { KC_LANG_7, "LANG_7" },
    { KC_LANG_8, "LANG_8" },
    { KC_LANG_9, "LANG_9" },
    { KC_ALTERNATE_ERASE, "ALTERNATE_ERASE" },
    { KC_SYS_REQ, "SYS_REQ" },
    { KC_CANCEL, "CANCEL" },
    { KC_CLEAR, "CLEAR" },
    { KC_PRIOR, "PRIOR" },
    { KC_RETURN, "RETURN" },
    { KC_SEPARATOR, "SEPARATOR" },
    { KC_OUT, "OUT" },
    { KC_OPER, "OPER" },
    { KC_CLEAR_AGAIN, "CLEAR_AGAIN" },
    { KC_CRSEL, "CRSEL" },
    { KC_EXSEL, "EXSEL" },
    { HID_CODE_RESERVED, NULL }, /*  = 0xa5, */
    { HID_CODE_RESERVED, NULL }, /*  = 0xa6, */
    { HID_CODE_RESERVED, NULL }, /*  = 0xa7, */
    { HID_CODE_RESERVED, NULL }, /*  = 0xa8, */
    { HID_CODE_RESERVED, NULL }, /*  = 0xa9, */
    { HID_CODE_RESERVED, NULL }, /*  = 0xaa, */
    { HID_CODE_RESERVED, NULL }, /*  = 0xab, */
    { HID_CODE_RESERVED, NULL }, /*  = 0xac, */
    { HID_CODE_RESERVED, NULL }, /*  = 0xad, */
    { HID_CODE_RESERVED, NULL }, /*  = 0xae, */
    { HID_CODE_RESERVED, NULL }, /*  = 0xaf, */
    { KC_KP_00, "KP_00" },
    { KC_KP_000, "KP_000" },
    { KC_THOUSANDS_SEPARATOR, "THOUSANDS_SEPARATOR" },
    { KC_DECIMAL_SEPARATOR, "DECIMAL_SEPARATOR" },
    { KC_CURRENCY_UNIT, "CURRENCY_UNIT" },
    { KC_CURRENCY_SUB_UNIT, "CURRENCY_SUB_UNIT" },
    { KC_KP_LEFT_PARENTHESIS, "KP_LEFT_PARENTHESIS" },
    { KC_KP_RIGHT_PARENTHESIS, "KP_RIGHT_PARENTHESIS" },
    { KC_KP_LEFT_BRACE, "KP_LEFT_BRACE" },
    { KC_KP_RIGHT_BRACE, "KP_RIGHT_BRACE" },
    { KC_KP_TAB, "KP_TAB" },
    { KC_KP_BACK_SPACE, "KP_BACK_SPACE" },
    { KC_KP_A, "KP_A" },
    { KC_KP_B, "KP_B" },
    { KC_KP_C, "KP_C" },
    { KC_KP_D, "KP_D" },
    { KC_KP_E, "KP_E" },
    { KC_KP_F, "KP_F" },
    { KC_KP_XOR, "KP_XOR" },
    { KC_KP_CARET, "KP_CARET" },
    { KC_KP_PERCENT, "KP_PERCENT" },
    { KC_KP_LESS_THAN, "KP_LESS_THAN" },
    { KC_KP_GREATER_THAN, "KP_GREATER_THAN" },
    { KC_KP_BITWISE_AND, "KP_BITWISE_AND" },
    { KC_KP_LOGICAL_AND, "KP_LOGICAL_AND" },
    { KC_KP_BITWISE_OR, "KP_BITWISE_OR" },
    { KC_KP_LOGICAL_OR, "KP_LOGICAL_OR" },
    { KC_KP_COLON, "KP_COLON" },
    { KC_KP_HASH, "KP_HASH" },
    { KC_KP_SPACE, "KP_SPACE" },
    { KC_KP_AT_SIGN, "KP_AT_SIGN" },
    { KC_KP_EXCLAMATION, "KP_EXCLAMATION" },
    { KC_KP_MEMORY_STORE, "KP_MEMORY_STORE" },
    { KC_KP_MEMORY_RECALL, "KP_MEMORY_RECALL" },
    { KC_KP_MEMORY_CLEAR, "KP_MEMORY_CLEAR" },
    { KC_KP_MEMORY_ADD, "KP_MEMORY_ADD" },
    { KC_KP_MEMORY_SUBTRACT, "KP_MEMORY_SUBTRACT" },
    { KC_KP_MEMORY_MULTIPLY, "KP_MEMORY_MULTIPLY" },
    { KC_KP_MEMORY_DIVIDE, "KP_MEMORY_DIVIDE" },
    { KC_KP_PLUS_MINUS, "KP_PLUS_MINUS" },
    { KC_KP_CLEAR, "KP_CLEAR" },
    { KC_KP_CLEAR_ENTRY, "KP_CLEAR_ENTRY" },
    { KC_KP_BINARY, "KP_BINARY" },
    { KC_KP_OCTAL, "KP_OCTAL" },
    { KC_KP_DECIMAL, "KP_DECIMAL" },
    { KC_KP_HEXADECIMAL, "KP_HEXADECIMAL" },
    { HID_CODE_RESERVED, NULL}, /* = 0xde, */
    { HID_CODE_RESERVED, NULL}, /* = 0xdf, */
    { KC_LEFT_CONTROL, "LEFT_CONTROL" },
    { KC_LEFT_SHIFT, "LEFT_SHIFT" },
    { KC_LEFT_ALT, "LEFT_ALT" },
    { KC_LEFT_GUI, "LEFT_GUI" },
    { KC_RIGHT_CONTROL, "RIGHT_CONTROL" },
    { KC_RIGHT_SHIFT, "RIGHT_SHIFT" },
    { KC_RIGHT_ALT, "RIGHT_ALT" },
    { KC_RIGHT_GUI, "RIGHT_GUI" },
    {0, NULL},
};



static inline jsmntype_t tok_type(void) {
    return m_toks[m_cur].type;
}

static inline const char* tok_str(void) {
    return &m_buf[m_toks[m_cur].start];
}

static inline const char* tok_str_end(void) {
    return &m_buf[m_toks[m_cur].end];
}

static inline int tok_str_len(void) {
    return (m_toks[m_cur].end - m_toks[m_cur].start);
}

static inline bool tok_has(void) {
    return m_cur < m_tok_count;
}

static inline bool tok_next(void) {
    m_cur++;
    return tok_has();
}

static inline bool tok_next_(void) {
    m_cur++;
    return 1;
}

static inline bool tok_expect(jsmntype_t type) {
    return ( tok_has() && (tok_type() == type) && tok_next_());
}

// static inline bool tok_cmp_str(const char* str) {
//     return !strncmp(str, tok_str(), tok_str_len())
// }

static inline bool tok_match(jsmntype_t type) {
    return (tok_has() && (tok_type() == type));
}

static inline bool tok_match_str(const char* str) {
    return (
        tok_has() &&
        tok_type() == JSMN_STRING &&
        !strncmp(str, tok_str(), tok_str_len())
    );
}

static inline int tok_size(void) {
    return m_toks[m_cur].size;
}

static void parse_print_error(const char *msg) {
    KP_LOG_ERROR("json parse error at ch[%d]: %s", m_toks[m_cur].start, msg);
    KP_LOG_ERROR("%.20s", tok_str());
    KP_LOG_ERROR("^~~~~~ error here");
}

static void parse_util_init(const char *buf, jsmntok_t *toks, int count) {
    m_cur = 0;
    m_buf = buf;
    m_toks = toks;
    m_tok_count = count;
}


/// Parse all the key counts in a device
///
/// The keys in the device are strings for HID keycodes, and their value
/// is the number of times that that key has been pressed
///
/// All keys must be upper case;
static uint16_t tok_get_hid_code(void) {
    const char *str = tok_str();
    const int len = tok_str_len();
    struct hid_code_name *hid = hid_code_table;

    while (!(hid->code == 0 && hid->name == NULL)) {
        if (hid->name != NULL && !strncmp(str, hid->name, len)) {
            return hid->code;
        }
        hid++;
    }

    return HID_CODE_UNKNOWN;
}

const char* get_hid_code_name(uint16_t code) {
    if (code == HID_CODE_UNKNOWN || code > HID_CODE_MAX) {
        return NULL;
    } else if (code == HID_CODE_RESERVED) {
        return "HID_CODE_RESERVED";
    } else {
        return hid_code_table[code].name;
    }
}

static int tok_get_press_count(uint32_t *dest) {
    const char *str = tok_str();

    switch(str[0]) {
        case 'n':
        case 'f':
        case 't': {
            parse_print_error("expected integer");
            return -1;
        } break;

        default: {
            long long res;
            errno = 0;
            res = strtoll(str, NULL, 10);
            if (errno || res < 0 || res >= UINT32_MAX) {
                return -1;
            }
            *dest = res;
            return 0;
        } break;

    }
}

static int parse_device(uint8_t dev_id) {
    int count; // number of toks in this 'device'
    int tok = 0;

    if (!tok_match(JSMN_OBJECT)) {
        parse_print_error("expected object");
        return -1;
    }
    count = tok_size();
    tok_next();

    if (count == 0) {
        return 0;
    }

    KP_DEBUG_PRINT(1, "loading stats for dev %d\n", dev_id);

    while (tok < count) {
        uint16_t hid_code;
        uint32_t press_count;
        uint16_t ev_code;
        int rc;

        if (!tok_match(JSMN_STRING)) {
            parse_print_error("expected key string");
            return -1;
        }
        hid_code = tok_get_hid_code();
        if (hid_code == HID_CODE_UNKNOWN) {
            parse_print_error("unknown HID code identifier");
            return -1;
        }
        tok_next();

        if (!tok_match(JSMN_PRIMITIVE)) {
            parse_print_error("expected key count");
            return -1;
        }

        rc = tok_get_press_count(&press_count);
        if (rc < 0) {
            parse_print_error("error parsing key press count");
            return -1;
        }

        KP_DEBUG_PRINT(1, "  %s(%04x) == %d\n",
                       get_hid_code_name(hid_code),
                       hid_code,
                       press_count);

        ev_code = mapper_hid_to_ev(hid_code);
        if (ev_code != 0 && ev_code < KEY_CNT) {
            stats_set_press_count(dev_id, ev_code, press_count);
        }

        tok_next();
        tok++;
    }

    return 0;
}

static int parse_devices(void) {
    int count; // number of device objects in 'devices' array
    int dev_id = 0;
    count = tok_size();
    tok_next();

    if (count >= MAX_NUM_DEVICES) {
        parse_print_error("too many devices");
        return -1;
    }

    while (dev_id < count) {
        if (parse_device(dev_id) < 0) {
            return -1;
        }
        dev_id++;
    }
    return 0;
}

int parse_stats(const char *str, size_t len) {
    int rc;
    jsmn_parser parser;
    jsmntok_t toks[MAX_JSMN_TOKS];
    int num_toks;

    jsmn_init(&parser);
    rc = jsmn_parse(&parser, str, len, toks, MAX_JSMN_TOKS);

    if (rc < 0) {
        KP_LOG_ERROR("parsing json failed: %d", rc);
        exit(EXIT_FAILURE);
    }

    num_toks = rc;

    parse_util_init(str, toks, num_toks);

    KP_ASSERT(tok_match(JSMN_OBJECT));
    tok_next();
    if (!tok_has()) {
        return 0; // empty object {}, so return
    }

    if (tok_match_str("devices")) {
        tok_next();
        if (!tok_match(JSMN_ARRAY)) {
            parse_print_error("expected JSON array");
            goto error;
        }
        if (parse_devices() < 0) {
            goto error;
        }
    } else if (tok_match_str("layouts")) {
    } else {
        KP_LOG_ERROR("parsing stats file: expected 'devices' array");
        goto error;
    }

    while (tok_has()) {
        KP_DEBUG_PRINT(1, "ignoring token: %.*s", tok_str_len(), tok_str());
        tok_next();
    }

    return 0;

error:
    exit(EXIT_FAILURE);
    return -1;
}

int parse_stats_file(const char *filename) {
    char* buffer = NULL;
    FILE *file;
    int rc;
    long size;
    size_t rc_size;

    file = fopen(filename, "rb");
    if (file == NULL) {
        if (errno != ENOENT) {
            KP_LOG_ERRNO("failed to open file");
        }
        return -errno;
    }

    // goto end of file
    rc = fseek(file, 0, SEEK_END);
    if (rc < 0) {
        KP_LOG_ERRNO("fseek() failed");
        goto cleanup;
    }

    // read size of file
    size = ftell(file);
    if (size < 0) {
        KP_LOG_ERRNO("ftell() failed");
        goto cleanup;
    }

    // treat empty file as success
    if (size == 0) {
        KP_LOG_INFO("empty stats file, reseting");
        rc = 0;
        goto cleanup;
    }

    // return to start
    rc = fseek(file, 0, SEEK_SET);
    if (rc < 0) {
        KP_LOG_ERRNO("fseek() failed");
        goto cleanup;
    }

    buffer = malloc(size+1);
    buffer[size] = '\0';

    rc_size = fread(buffer, 1, size, file);
    if (rc_size < 0) {
        KP_LOG_ERRNO("fread failed");
        goto cleanup;
    } else if (rc_size != size) {
        KP_LOG_ERROR("read %ld bytes, expected %ld", rc_size, size);
        goto cleanup;
    }

    parse_stats(buffer, size);

    rc = 0;

cleanup:
    if (buffer != NULL) {
        free(buffer);
    }
    if (file != NULL) {
        fclose(file);
    }

    return rc;
}
