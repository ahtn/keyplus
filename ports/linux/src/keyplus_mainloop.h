// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

// TODO: probably move exit ability to a key_handler
#ifndef DEBUG_EXIT_KEY
    #define DEBUG_EXIT_KEY KEY_F1
#endif

int kp_mainloop(int, const char **);
void kp_mainloop_stop(void);
