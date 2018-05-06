// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define DEF_AVR_PORT_a(x) PORT ## x
#define DEF_AVR_PORT_b(x) DEF_AVR_PORT_a(x)
#define DEF_AVR_PORT(x)   DEF_AVR_PORT_b(x)

#define DEF_AVR_PIN_MASK_a(x) PIN ## x ## _bm
#define DEF_AVR_PIN_MASK(x) DEF_AVR_PIN_MASK_a(x)

#define DEF_AVR_INT_INTMASK_a(port, int_num) PORT ## port . INT ## int_num ## MASK
#define DEF_AVR_INT_INTMASK(port, int_num) DEF_AVR_INT_INTMASK_a(port, int_num)

#define DEF_AVR_INT_LVL_a(int_num, lvl) PORT_INT ## int_num ## LVL_ ## lvl ## _gc
#define DEF_AVR_INT_LVL(int_num, lvl) DEF_AVR_INT_LVL_a(int_num, lvl)

#define DEF_AVR_INT_LVL_MASK_a(int_num) PORT_INT ## int_num ## LVL_gm
#define DEF_AVR_INT_LVL_MASK(int_num) DEF_AVR_INT_LVL_MASK_a(int_num)

#define DEF_AVR_INT_VECT_a(port, int_num) \
    PORT ## port ## _ ## INT ## int_num ## _vect
#define DEF_AVR_INT_VECT(port, int_num) DEF_AVR_INT_VECT_a(port, int_num)
