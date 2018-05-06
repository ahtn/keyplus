#!/usr/bin/env python

import sys

def gmul(a, b):
    a = int(a)
    b = int(b)
    result = 0
    while a:
        if a & 1:
            result ^= b
        a >>= 1
        b <<= 1
        if b & 0x100:
            b ^= 0x11B
    return result


if __name__ == "__main__":
    print(gmul(sys.argv[1], sys.argv[2]))

