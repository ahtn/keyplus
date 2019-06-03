// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdbool.h>

struct cmdline_args {
    const char* config;
    const char* lockfile;
    bool daemonize;
};

void parse_cmdline_args(struct cmdline_args *args, int argc, char** argv);
