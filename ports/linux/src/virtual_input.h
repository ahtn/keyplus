// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

int create_virtual_keyboard(void);
int create_virtual_mouse(void);

void kp_virtual_keyboard_close(void);
void kp_virtual_mouse_close(void);

int kp_virtual_keyboard_send(unsigned int type, unsigned int code, int value);
int kp_virtual_mouse_send(unsigned int type, unsigned int code, int value);
