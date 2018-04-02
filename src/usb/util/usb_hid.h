// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

// Values country codes in HID Descriptors
typedef enum {
    HID_COUNTRY_NONE               = 0,
    HID_COUNTRY_ARABIC             = 1,
    HID_COUNTRY_BELGIAN            = 2,
    HID_COUNTRY_CANADIAN_BILINGUAL = 3,
    HID_COUNTRY_CANADIAN_FRENCH    = 4,
    HID_COUNTRY_CZECH              = 5,
    HID_COUNTRY_DANISH             = 6,
    HID_COUNTRY_FINNISH            = 7,
    HID_COUNTRY_FRENCH             = 8,
    HID_COUNTRY_GERMAN             = 9,
    HID_COUNTRY_GREEK              = 10,
    HID_COUNTRY_HEBREW             = 11,
    HID_COUNTRY_HUNGARY            = 12,
    HID_COUNTRY_INTERNATIONAL      = 13,
    HID_COUNTRY_ITALIAN            = 14,
    HID_COUNTRY_JAPAN              = 15,
    HID_COUNTRY_KOREAN             = 16,
    HID_COUNTRY_LATIN_AMERICAN     = 17,
    HID_COUNTRY_NETHERLANDS        = 18,
    HID_COUNTRY_NORWEGIAN          = 19,
    HID_COUNTRY_PERSIAN            = 20,
    HID_COUNTRY_POLAND             = 21,
    HID_COUNTRY_PORTUGUESE         = 22,
    HID_COUNTRY_RUSSIA             = 23,
    HID_COUNTRY_SLOVAKIA           = 24,
    HID_COUNTRY_SPANISH            = 25,
    HID_COUNTRY_SWEDISH            = 26,
    HID_COUNTRY_SWISS_FRENCH       = 27,
    HID_COUNTRY_SWISS_GERMAN       = 28,
    HID_COUNTRY_SWITZERLAND        = 29,
    HID_COUNTRY_TAIWAN             = 30,
    HID_COUNTRY_TURKISH_Q          = 31,
    HID_COUNTRY_UK                 = 32,
    HID_COUNTRY_US                 = 33,
    HID_COUNTRY_YUGOSLAVIA         = 34,
    HID_COUNTRY_TURKISH_F          = 35,
} HID_CountryCode_t;

#define HID_LANG_ARABIC     0x01
#define HID_LANG_BULGARIAN  0x02
#define HID_LANG_CATALAN    0x03
#define HID_LANG_CHINESE    0x04
#define HID_LANG_CZECH      0x05
#define HID_LANG_DANISH     0x06
#define HID_LANG_GERMAN     0x07
#define HID_LANG_GREEK      0x08
#define HID_LANG_ENGLISH    0x09
#define HID_LANG_SPANISH    0x0a
#define HID_LANG_FINNISH    0x0b
#define HID_LANG_FRENCH     0x0c
#define HID_LANG_HEBREW     0x0d
#define HID_LANG_HUNGARIAN  0x0e
#define HID_LANG_ICELANDIC  0x0f
#define HID_LANG_ITALIAN    0x10
#define HID_LANG_JAPANESE   0x11
#define HID_LANG_KOREAN     0x12
#define HID_LANG_DUTCH      0x13
#define HID_LANG_NORWEGIAN  0x14
#define HID_LANG_POLISH     0x15
#define HID_LANG_PORTUGUESE 0x16
#define HID_LANG_ROMANIAN   0x18
#define HID_LANG_RUSSIAN    0x19
#define HID_LANG_CROATIAN   0x1a
#define HID_LANG_SERBIAN    0x1a
#define HID_LANG_SLOVAK     0x1b
#define HID_LANG_ALBANIAN   0x1c
#define HID_LANG_SWEDISH    0x1d
#define HID_LANG_THAI       0x1e
#define HID_LANG_TURKISH    0x1f
#define HID_LANG_URDU       0x20
#define HID_LANG_INDONESIAN 0x21
#define HID_LANG_UKRANIAN   0x22
#define HID_LANG_BELARUSIAN 0x23
#define HID_LANG_SLOVENIAN  0x24
#define HID_LANG_ESTONIAN   0x25
#define HID_LANG_LATVIAN    0x26
#define HID_LANG_LITHUANIAN 0x27
#define HID_LANG_FARSI      0x29
#define HID_LANG_VIETNAMESE 0x2a
#define HID_LANG_ARMENIAN   0x2b
#define HID_LANG_AZERI      0x2c
#define HID_LANG_BASQUE     0x2d
#define HID_LANG_MACEDONIAN 0x2f
#define HID_LANG_AFRIKAANS  0x36
#define HID_LANG_GEORGIAN   0x37
#define HID_LANG_FAEROESE   0x38
#define HID_LANG_HINDI      0x39
#define HID_LANG_MALAY      0x3e
#define HID_LANG_KAZAK      0x3f
#define HID_LANG_SWAHILI    0x41
#define HID_LANG_UZBEK      0x43
#define HID_LANG_TATAR      0x44
#define HID_LANG_BENGALI    0x45
#define HID_LANG_PUNJABI    0x46
#define HID_LANG_GUJARATI   0x47
#define HID_LANG_ORIYA      0x48
#define HID_LANG_TAMIL      0x49
#define HID_LANG_TELUGU     0x4a
#define HID_LANG_KANNADA    0x4b
#define HID_LANG_MALAYALAM  0x4c
#define HID_LANG_ASSAMESE   0x4d
#define HID_LANG_MARATHI    0x4e
#define HID_LANG_SANSKRIT   0x4f
#define HID_LANG_KONKANI    0x57
#define HID_LANG_MANIPURI   0x58
#define HID_LANG_SINDHI     0x59
#define HID_LANG_KASHMIRI   0x60
#define HID_LANG_NEPALI     0x61

#define HID_SUBLANG_ARABIC_SAUDI_ARABIA        0x01
#define HID_SUBLANG_ARABIC_IRAQ                0x02
#define HID_SUBLANG_ARABIC_EGYPT               0x03
#define HID_SUBLANG_ARABIC_LIBYA               0x04
#define HID_SUBLANG_ARABIC_ALGERIA             0x05
#define HID_SUBLANG_ARABIC_MOROCCO             0x06
#define HID_SUBLANG_ARABIC_TUNISIA             0x07
#define HID_SUBLANG_ARABIC_OMAN                0x08
#define HID_SUBLANG_ARABIC_YEMEN               0x09
#define HID_SUBLANG_ARABIC_SYRIA               0x10
#define HID_SUBLANG_ARABIC_JORDAN              0x11
#define HID_SUBLANG_ARABIC_LEBANON             0x12
#define HID_SUBLANG_ARABIC_KUWAIT              0x13
#define HID_SUBLANG_ARABIC_UAE                 0x14
#define HID_SUBLANG_ARABIC_BAHRAIN             0x15
#define HID_SUBLANG_ARABIC_QATAR               0x16
#define HID_SUBLANG_AZERI_CYRILLIC             0x01
#define HID_SUBLANG_AZERI_LATIN                0x02
#define HID_SUBLANG_CHINESE_TRADITIONAL        0x01
#define HID_SUBLANG_CHINESE_SIMPLIFIED         0x02
#define HID_SUBLANG_CHINESE_HONGKONG           0x03
#define HID_SUBLANG_CHINESE_SINGAPORE          0x04
#define HID_SUBLANG_CHINESE_MACAU              0x05
#define HID_SUBLANG_DUTCH                      0x01
#define HID_SUBLANG_DUTCH_BELGIAN              0x02
#define HID_SUBLANG_ENGLISH_US                 0x01
#define HID_SUBLANG_ENGLISH_UK                 0x02
#define HID_SUBLANG_ENGLISH_AUS                0x03
#define HID_SUBLANG_ENGLISH_CAN                0x04
#define HID_SUBLANG_ENGLISH_NZ                 0x05
#define HID_SUBLANG_ENGLISH_EIRE               0x06
#define HID_SUBLANG_ENGLISH_SOUTH_AFRICA       0x07
#define HID_SUBLANG_ENGLISH_JAMAICA            0x08
#define HID_SUBLANG_ENGLISH_CARIBBEAN          0x09
#define HID_SUBLANG_ENGLISH_BELIZE             0x0a
#define HID_SUBLANG_ENGLISH_TRINIDAD           0x0b
#define HID_SUBLANG_ENGLISH_PHILIPPINES        0x0c
#define HID_SUBLANG_ENGLISH_ZIMBABWE           0x0d
#define HID_SUBLANG_FRENCH                     0x01
#define HID_SUBLANG_FRENCH_BELGIAN             0x02
#define HID_SUBLANG_FRENCH_CANADIAN            0x03
#define HID_SUBLANG_FRENCH_SWISS               0x04
#define HID_SUBLANG_FRENCH_LUXEMBOURG          0x05
#define HID_SUBLANG_FRENCH_MONACO              0x06
#define HID_SUBLANG_GERMAN                     0x01
#define HID_SUBLANG_GERMAN_SWISS               0x02
#define HID_SUBLANG_GERMAN_AUSTRIAN            0x03
#define HID_SUBLANG_GERMAN_LUXEMBOURG          0x04
#define HID_SUBLANG_GERMAN_LIECHTENSTEIN       0x05
#define HID_SUBLANG_ITALIAN                    0x01
#define HID_SUBLANG_ITALIAN_SWISS              0x02
#define HID_SUBLANG_KASHMIRI_INDIA             0x02
#define HID_SUBLANG_KOREAN                     0x01
#define HID_SUBLANG_LITHUANIAN                 0x01
#define HID_SUBLANG_MALAY_MALAYSIA             0x01
#define HID_SUBLANG_MALAY_BRUNEI_DARUSSALAM    0x02
#define HID_SUBLANG_NEPALI_INDIA               0x02
#define HID_SUBLANG_NORWEGIAN_BOKMAL           0x01
#define HID_SUBLANG_NORWEGIAN_NYNORSK          0x02
#define HID_SUBLANG_PORTUGUESE                 0x01
#define HID_SUBLANG_PORTUGUESE_BRAZILIAN       0x02
#define HID_SUBLANG_SERBIAN_LATIN              0x02
#define HID_SUBLANG_SERBIAN_CYRILLIC           0x03
#define HID_SUBLANG_SPANISH                    0x01
#define HID_SUBLANG_SPANISH_MEXICAN            0x02
#define HID_SUBLANG_SPANISH_MODERN             0x03
#define HID_SUBLANG_SPANISH_GUATEMALA          0x04
#define HID_SUBLANG_SPANISH_COSTA_RICA         0x05
#define HID_SUBLANG_SPANISH_PANAMA             0x06
#define HID_SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#define HID_SUBLANG_SPANISH_VENEZUELA          0x08
#define HID_SUBLANG_SPANISH_COLOMBIA           0x09
#define HID_SUBLANG_SPANISH_PERU               0x0a
#define HID_SUBLANG_SPANISH_ARGENTINA          0x0b
#define HID_SUBLANG_SPANISH_ECUADOR            0x0c
#define HID_SUBLANG_SPANISH_CHILE              0x0d
#define HID_SUBLANG_SPANISH_URUGUAY            0x0e
#define HID_SUBLANG_SPANISH_PARAGUAY           0x0f
#define HID_SUBLANG_SPANISH_BOLIVIA            0x10
#define HID_SUBLANG_SPANISH_EL_SALVADOR        0x11
#define HID_SUBLANG_SPANISH_HONDURAS           0x12
#define HID_SUBLANG_SPANISH_NICARAGUA          0x13
#define HID_SUBLANG_SPANISH_PUERTO_RICO        0x14
#define HID_SUBLANG_SWEDISH                    0x01
#define HID_SUBLANG_SWEDISH_FINLAND            0x02
#define HID_SUBLANG_URDU_PAKISTAN              0x01
#define HID_SUBLANG_URDU_INDIA                 0x02
#define HID_SUBLANG_UZBEK_LATIN                0x01
#define HID_SUBLANG_UZBEK_CYRILLIC             0x02
#define HID_SUBLANG_HID_USAGE_DATA_DESCRIPTOR  0x01
#define HID_SUBLANG_HID_VENDOR_DEFINED_1       0x3c
#define HID_SUBLANG_HID_VENDOR_DEFINED_2       0x3d
#define HID_SUBLANG_HID_VENDOR_DEFINED_3       0x3e
#define HID_SUBLANG_HID_VENDOR_DEFINED_4       0x3f

#define HID_LANG_ID(lang_id, sub_lang_id) (\
    ((sub_lang_id<<10)&0xffc0) | (lang_id&0x003f) \
)


// HID Item types
typedef enum {
    HID_TYPE_MAIN   = 0,
    HID_TYPE_GLOBAL = 1,
    HID_TYPE_LOCAL  = 3,
} HID_Item_Type_t;

// HID Item Tags
typedef enum {
    // main items
    HID_TAG_INPUT = 0x80,
    HID_TAG_OUTUPT = 0x90,
    HID_TAG_COLLECTION = 0xA0,
    HID_TAG_FEATURE = 0xB0,
    HID_TAG_END_COLLECTION = 0xC0,

    // global items
    HID_TAG_USAGE_PAGE = 0x04,
    HID_TAG_LOGICAL_MINIMUM = 0x14,
    HID_TAG_LOGICAL_MAXIMUM = 0x24,
    HID_TAG_PHYSICAL_MINIMUM = 0x34,
    HID_TAG_PHYSICAL_MAXIMUM = 0x44,
    HID_TAG_UNIT_EXPONENT = 0x54,
    HID_TAG_UNIT = 0x64,
    HID_TAG_REPORT_SIZE = 0x74,
    HID_TAG_REPORT_ID = 0x84,
    HID_TAG_REPORT_COUNT = 0x94,
    HID_TAG_PUSH = 0xA4,
    HID_TAG_POP = 0xB4,

    // local items
    HID_TAG_USAGE = 0x08,
    HID_TAG_USAGE_MINIMUM = 0x18,
    HID_TAG_USAGE_MAXIMUM = 0x28,
    HID_TAG_DESIGNATOR_INDEX = 0x38,
    HID_TAG_DESIGNATOR_MINIMUM = 0x48,
    HID_TAG_DESIGNATOR_MAXIMUM = 0x58,
    /* USB_TAG_ UNASSIGNED = 0x68, */
    HID_TAG_STRING_INDEX = 0x78,
    HID_TAG_STRING_MINIMUM = 0x88,
    HID_TAG_STRING_MAXIMUM = 0x98,
    HID_TAG_DELIMITER = 0xA8,
} HID_Item_Tag_t;

// Long items (6.2.2.3)
// Note: No long items defined as of HID 1.11
#define HID_LONG_ITEM_TAG 0xFE

// Short items
#define HID_SHORT_SIZE_MASK 0x03
#define HID_SHORT_TYPE_MASK 0x0C
#define HID_SHORT_TAG_MASK 0xF0
#define HID_SHORT_SIZE_POS 0
#define HID_SHORT_TYPE_POS 2
#define HID_SHORT_TAG_POS 4

#define HID_SHORT_ITEM(tag, size) ( \
        HID_TAG_##tag | (size & HID_SHORT_SIZE_MASK) \
        )

// Main items
#define HID_INPUT(size)             HID_SHORT_ITEM(INPUT, size)
#define HID_OUTPUT(size)            HID_SHORT_ITEM(OUTUPT, size)
#define HID_COLLECTION(size)        HID_SHORT_ITEM(COLLECTION, size)
#define HID_FEATURE(size)           HID_SHORT_ITEM(FEATURE, size)
#define HID_END_COLLECTION(size)    HID_SHORT_ITEM(END_COLLECTION, size)
// Global Items
#define HID_USAGE_PAGE(size)        HID_SHORT_ITEM(USAGE_PAGE, size)
#define HID_LOGICAL_MINIMUM(size)   HID_SHORT_ITEM(LOGICAL_MINIMUM, size)
#define HID_LOGICAL_MAXIMUM(size)   HID_SHORT_ITEM(LOGICAL_MAXIMUM, size)
#define HID_PHYSICAL_MINIMUM(size)  HID_SHORT_ITEM(PHYSICAL_MINIMUM, size)
#define HID_PHYSICAL_MAXIMUM(size)  HID_SHORT_ITEM(PHYSICAL_MAXIMUM, size)
#define HID_UNIT_EXPONENT(size)     HID_SHORT_ITEM(UNIT_EXPONENT, size)
#define HID_UNIT(size)              HID_SHORT_ITEM(UNIT, size)
#define HID_REPORT_SIZE(size)       HID_SHORT_ITEM(REPORT_SIZE, size)
#define HID_REPORT_ID(size)         HID_SHORT_ITEM(REPORT_ID, size)
#define HID_REPORT_COUNT(size)      HID_SHORT_ITEM(REPORT_COUNT, size)
#define HID_PUSH(size)              HID_SHORT_ITEM(PUSH, size)
#define HID_POP(size)               HID_SHORT_ITEM(POP, size)
// Local Items
#define HID_USAGE(size)             HID_SHORT_ITEM(USAGE, size)
#define HID_USAGE_MINIMUM(size)     HID_SHORT_ITEM(USAGE_MINIMUM, size)
#define HID_USAGE_MAXIMUM(size)     HID_SHORT_ITEM(USAGE_MAXIMUM, size)
#define HID_DESIGNATOR_INDEX        HID_SHORT_ITEM(DESIGNATOR_INDEX, size)
#define HID_DESIGNATOR_MINIMUM      HID_SHORT_ITEM(DESIGNATOR_MINIMUM, size)
#define HID_DESIGNATOR_MAXIMUM      HID_SHORT_ITEM(DESIGNATOR_MAXIMUM, size)
#define HID_STRING_INDEX            HID_SHORT_ITEM(STRING_INDEX, size)
#define HID_STRING_MINIMUM          HID_SHORT_ITEM(STRING_MINIMUM, size)
#define HID_STRING_MAXIMUM          HID_SHORT_ITEM(STRING_MAXIMUM, size)
#define HID_DELIMITER               HID_SHORT_ITEM(DELIMITER, size)

// Usage Pages
typedef enum {
    HID_USAGE_PAGE_UNDEFINED = 0x00,
    HID_USAGE_PAGE_GENERIC_DESKTOP = 0x01,
    HID_USAGE_PAGE_SIMULATION = 0x02,
    HID_USAGE_PAGE_VR = 0x03,
    HID_USAGE_PAGE_SPORTS = 0x04,
    HID_USAGE_PAGE_GAME = 0x05,
    HID_USAGE_PAGE_GENERIC_DEVICE = 0x06,
    HID_USAGE_PAGE_KEYBOARD = 0x07,
    HID_USAGE_PAGE_LEDS = 0x08,
    HID_USAGE_PAGE_BUTTON = 0x09,
    HID_USAGE_PAGE_ORDINAL = 0x0A,
    HID_USAGE_PAGE_TELEPHONY = 0x0B,
    HID_USAGE_PAGE_CONSUMER = 0x0C,
    HID_USAGE_PAGE_DIGITIZER = 0x0D,
    // 0E RESERVED
    HID_USAGE_PAGE_PID_PAGE = 0x0F,
    HID_USAGE_PAGE_UNICODE = 0x10,
    // 11-13 RESERVED
    HID_USAGE_PAGE_ALPHANUMERIC_DISPLAY = 0x14,
    // 15-3f RESERVED
    HID_USAGE_PAGE_MEDICAL_INSTRUMENTS = 0x40,
    // 41-7f RESERVED
    // 80-83 Monitor pages
    HID_USAGE_PAGE_MONITOR_PAGES = 0x80,
    // 84-87 Power pages
    HID_USAGE_PAGE_POWER_PAGES = 0x84,
    // 88-8B RESERVED
    HID_USAGE_PAGE_BAR_CODE_SCANNER = 0x8C,
    HID_USAGE_PAGE_SCALE_PAGE = 0x8D,
    HID_USAGE_PAGE_MAGNETIC_STRIPE_READING = 0x8E,
    HID_USAGE_PAGE_RESERVED_POINT_OF_SALEG = 0x8F,
    HID_USAGE_PAGE_CAMERA_CONTROL = 0x90,
    HID_USAGE_PAGE_ARCADE_PAGE = 0x91,
    // 0092-FEFF RESERVED
    HID_USAGE_PAGE_VENDOR_START = 0xFF00,
    // FF00-FFFF Vendor defined

} USB_HID_Usage_Page_t;

typedef enum {
    HID_USAGE_UNDEFINED = 0x00,
    HID_USAGE_POINTER = 0x01,
    HID_USAGE_MOUSE = 0x02,
    // 03 RESERVED
    HID_USAGE_JOYSTICK = 0x04,
    HID_USAGE_GAME_PAD = 0x05,
    HID_USAGE_KEYBOARD = 0x06,
    HID_USAGE_KEYPAD = 0x07,
    HID_USAGE_MULTI_AXIS_CONTROLLER = 0x08,
    HID_USAGE_TABLET_PC_SYSTEM_CONTROLS = 0x09,
    // 0A-2F RESERVED

    HID_USAGE_X = 0x30,
    HID_USAGE_Y = 0x31,
    HID_USAGE_Z = 0x32,
    HID_USAGE_RX = 0x33,
    HID_USAGE_RY = 0x34,
    HID_USAGE_RZ = 0x35,
    HID_USAGE_SLIDER = 0x36,
    HID_USAGE_DIAL = 0x37,
    HID_USAGE_WHEEL = 0x38,
    HID_USAGE_HAT_SWITCH = 0x39,

    HID_USAGE_COUNTED_BUFFER = 0x3A,
    HID_USAGE_BYTE_COUNT = 0x3B,
    HID_USAGE_MOTION_WAKEUP = 0x3C,
    HID_USAGE_START = 0x3D,
    HID_USAGE_SELECT = 0x3E,
    // 3F RESERVED
    //
    HID_USAGE_V_X = 0x40,
    HID_USAGE_V_Y = 0x41,
    HID_USAGE_V_Z = 0x42,
    HID_USAGE_V_BR_X = 0x43,
    HID_USAGE_V_BR_Y = 0x44,
    HID_USAGE_V_BR_Z = 0x45,
    HID_USAGE_V_NO = 0x46,

    HID_USAGE_RESOLUTION_MULTIPLIER = 0x48,
    HID_USAGE_SYSTEM_CONTROL = 0x80,

} USB_HID_Generic_Desktop_t;

#define HID_USAGE_VENDOR_START 0x00

// Collection and End collection items
#define HID_COLLECTION_PHYSICAL        0x00
#define HID_COLLECTION_APPLICATION     0x01
#define HID_COLLECTION_LOGICAL         0x02
#define HID_COLLECTION_REPORT          0x03
#define HID_COLLECTION_NAMED_ARRAY     0x04
#define HID_COLLECTION_USAGE_SWITCH    0x05
#define HID_COLLECTION_USAGE_MODIFIER  0x06
#define HID_COLLECTION_VENDOR_START    0x80

// Input, Output and Feature item data fields
#define IOF_DATA                  (0 << 0)
#define IOF_CONSTANT              (1 << 0)
#define IOF_ARRAY                 (0 << 1)
#define IOF_VARIABLE              (1 << 1)
#define IOF_ABSOLUTE              (0 << 2)
#define IOF_RELATIVE              (1 << 2)
#define IOF_NO_WRAP               (0 << 3)
#define IOF_WRAP                  (1 << 3)
#define IOF_LINEAR                (0 << 4)
#define IOF_NON_LINEAR            (1 << 4)
#define IOF_PREFERRED_STATE       (0 << 5)
#define IOF_NO_PREFERRED_STATE    (1 << 5)
#define IOF_NO_NULL_POSITION      (0 << 6)
#define IOF_NULLSTATE             (1 << 6)
#define IOF_NON_VOLATILE          (0 << 7)
#define IOF_VOLATILE              (1 << 7)
#define IOF_BIT_FIELD             (0 << 8)
#define IOF_BUFFERED              (1 << 8)

#define DB8(word) ((uint8_t)(word & 0xff))
#define DB16(word) DB8(word) , DB8(((uint16_t)word) >> 8)

#define USB_DTYPE_HID         0x21
#define USB_DTYPE_HID_REPORT  0x22
#define USB_DTYPE_HID_PHYS    0x23

typedef struct {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdHID;
    uint8_t bCountryCode;
    uint8_t bNumDescriptors;
    uint8_t bDescriptorType_HID;
    uint16_t wDescriptorLength;
} USB_HID_Descriptor_t;
/* } __attribute__ ((packed)) USB_HID_Descriptor_t; */

typedef struct {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdHID;
    uint8_t bCountryCode;
    uint8_t bNumDescriptors;
    uint8_t bDescriptorType_HID;
    uint16_t wDescriptorLength;
    uint8_t bDescriptorType_Optional;
    uint16_t wDescriptorLength_Optional;
} USB_HID_Descriptor_Optional_t;
/* } __attribute__ ((packed)) USB_HID_Descriptor_Optional_t; */

// Note: No support for Physical Descriptors
