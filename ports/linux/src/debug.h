#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>

#if defined(DEBUG) && DEBUG > 0
    #define KP_DEBUG_PRINT(lvl, fmt, args...) do {\
        if (DEBUG >= lvl) { \
            fprintf(stderr, "DEBUG: %s:%d: " fmt, __FILE__, __LINE__, ##args); \
            syslog(LOG_DEBUG, "DEBUG %s:%d: " fmt, __FILE__, __LINE__, ##args); \
        } \
    } while (0)
#else
    #define KP_DEBUG_PRINT(lvl, fmt, args...) /* Don't do anything in release builds */
#endif

#define KP_LOG_ERROR(fmt, args...) do { \
    fprintf(stderr, "ERROR %s:%d: " fmt, __FILE__, __LINE__, ##args); \
    syslog(LOG_ERR, "ERROR %s:%d: " fmt, __FILE__, __LINE__, ##args); \
} while (0)

#define KP_LOG_INFO(fmt, args...) do { \
    fprintf(stdout, "INFO " fmt "\n", ##args); \
    syslog(LOG_INFO, "%s:%d: " fmt, __FILE__, __LINE__, ##args); \
} while (0)

#define KP_LOG_ERRNO(fmt) do {\
    syslog(LOG_ERR, "%s:%d: " fmt ": %s\n", __FILE__, __LINE__, strerror(errno)); \
    fprintf(stderr, "%s:%d: " fmt ": %s\n", __FILE__, __LINE__, strerror(errno)); \
} while (0)

#define KP_CHECK_ERRNO(x) do {\
    if (x < 0) { \
        fprintf(stderr, "%s:%d: [Errno %d] %s\n", __FILE__, __LINE__, errno, strerror(errno)); \
        syslog(LOG_ERR, "%s:%d: [Errno %d] %s\n", __FILE__, __LINE__, errno, strerror(errno)); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

#define KP_ASSERT(x) do { \
    if (!(x)) { \
        fprintf(stderr, "%s:%d: error (%s) failed\n", __FILE__, __LINE__, #x); \
        syslog(LOG_ERR, "%s:%d: error (%s) failed\n", __FILE__, __LINE__, #x); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

// See: https://stackoverflow.com/questions/7775991/how-to-get-hexdump-of-a-structure-data
static inline void hexDump (char *desc, void *addr, int len) {
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char*)addr;

    // Output description if given.
    if (desc != NULL)
        printf ("%s:\n", desc);

    if (len == 0) {
        printf("  ZERO LENGTH\n");
        return;
    }
    if (len < 0) {
        printf("  NEGATIVE LENGTH: %i\n",len);
        return;
    }

    // Process every byte in the data.
    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).

        if ((i % 16) == 0) {
            // Just don't print ASCII for the zeroth line.
            if (i != 0)
                printf ("  %s\n", buff);

            // Output the offset.
            printf ("  %04x ", i);
        }

        // Now the hex code for the specific character.
        printf (" %02x", pc[i]);

        // And store a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }

    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        printf ("   ");
        i++;
    }

    // And print the final ASCII bit.
    printf ("  %s\n", buff);
}
