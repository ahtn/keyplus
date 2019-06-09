// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

int parse_stats_file(const char *filename);
int parse_stats(const char *str, size_t len);
const char* get_hid_code_name(uint16_t code);
