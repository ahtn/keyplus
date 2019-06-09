// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "cmdline.h"

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#include "core/settings.h"
#include "core/version.h"

static const char *m_default_lockfile_path = LOCKFILE_PATH;
static const char *m_default_config_path = CONFIG_FILE_PATH;
static const char *m_default_stats_path = STATS_FILE_PATH;

static void print_version(void) {
    printf("keyplus version %d.%d.%d",
           KEYPLUS_VERSION_MAJOR,
           KEYPLUS_VERSION_MINOR,
           KEYPLUS_VERSION_PATCH);
    if (!KEYPLUS_VERSION_IS_STABLE) {
        printf("-");
        for (int i = 0; i < 5; ++i) {
            printf("%02x", g_firmware_build_settings.git_hash[i]);
        }
    }
    printf("\n");
}

static void print_build_info(void) {
    print_version();
    printf("default config path: %s\n", m_default_config_path);
    printf("default lockfile path: %s\n", m_default_lockfile_path);
}

void print_usage(void) {
    const char* usage_str = (
        "Usage: keyplusd [options]\n"
        "\n"
        "Options:\n"
        "  -h --help                  * Show this help message and exit\n"
        "  -v --version               * Show version information and exit\n"
        "  -i --info                  * Show keyplusd build info\n"
        "  -c --config CONFIG_FILE    * Set the keyplusd configuration file to use\n"
        "  -p --pidfile PID_FILE      * Set the location of the pid lockfile\n"
        "  -s --statsfile STATS_FILE  * Set the location of the usage statistics file\n"
        "  -u --as-user               * Run as the current user in the shell\n"
        "  -r --refresh               * Reload the config file and write stats file\n"
        "  -k --kill                  * Kill the daemon\n"
    );
    printf("%s", usage_str);
}

/// Parse the command line args and set their default values in `args`
void parse_cmdline_args(struct cmdline_args *args, int argc, char** argv) {
    int c;

    const struct option long_options[] = {
        {"help"      , no_argument       , 0 , 'h' } ,
        {"version"   , no_argument       , 0 , 'v' } ,
        {"info"      , no_argument       , 0 , 'i' } ,
        {"config"    , required_argument , 0 , 'c' } ,
        {"pidfile"   , required_argument , 0 , 'p' } ,
        {"statsfile" , required_argument , 0 , 's' } ,
        {"as-user"   , no_argument       , 0 , 'u' } ,
        {"refresh"   , no_argument       , 0 , 'r' } ,
        {"kill"      , no_argument       , 0 , 'k' } ,
        {0           , 0                 , 0 , 0   }
    };

    const char* opt_string = "hviurk" "c:p:s:";

    // set default values
    args->config = m_default_config_path;
    args->lockfile = m_default_lockfile_path;
    args->stats = m_default_stats_path;
    args->daemonize = true;
    args->restart = false;
    args->kill = false;

    while (1) {
        int option_index = 0;
        c = getopt_long(argc, argv, opt_string, long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
            case 'h': {
                print_usage();
                exit(EXIT_SUCCESS);
            } break;

            case 'v': {
                print_version();
                exit(EXIT_SUCCESS);
            } break;

            case 'i': {
                print_build_info();
                exit(EXIT_SUCCESS);
            } break;

            case 'c': {
                args->config = optarg;
            } break;

            case 'p': {
                args->lockfile = optarg;
            } break;

            case 's': {
                args->stats = optarg;
            } break;

            case 'u': {
                args->daemonize = false;
            } break;

            case 'r': {
                args->restart = true;
            } break;

            case 'k': {
                args->kill = true;
            } break;

            case '?': {
                print_usage();
                exit(EXIT_FAILURE);
            } break;

            default: {
                printf("?? getopt returned character code 0%o %d %c ??\n", c, c, c);
            } break;
        }
    }

    if (optind < argc) {
        fprintf(stderr, "error: unexpected arguments: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
        exit(EXIT_FAILURE);
    }

    if (args->kill && args->restart) {
        fprintf(stderr, "error: conflicting flags -k (--kill) and -r (--refresh)\n");
        exit(EXIT_FAILURE);
    }
}
