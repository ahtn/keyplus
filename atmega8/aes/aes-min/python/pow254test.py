#!/usr/bin/env python

from __future__ import print_function

from bisect import bisect_left

from gmul import gmul

def delta_gen(i):
    ii = iter(i)
    prev = next(ii)
    for a in ii:
        yield(a - prev)
        prev = a

def index(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError

def brauer_gen(fd):
    for line in fd:
        line = line.strip()
        num_line, tag = line.rsplit(" ", 1)
        if tag == "b":
            nums = tuple( int(x) for x in num_line.split(" ") )
            deltas = tuple(delta_gen(nums))
            indices = tuple( index(nums, x) for i, x in enumerate(delta_gen(nums)) )
            yield indices

def main():
    best = (-100, ())
    with open("ac0254.txt") as f:
        for a in brauer_gen(f):
            #print(a)
            count_zeros = sum(1 if i==x else 0 for i, x in enumerate(a))
            non_zero_indices_for_min = tuple(99 if i==x else x for i, x in enumerate(a))
            non_zero_indices_for_max = tuple(0 if i==x else x for i, x in enumerate(a))
            delta_indices = tuple(i - x for i, x in enumerate(a))
            worst_delta = max(delta_indices)
            min_non_zero_index = min(non_zero_indices_for_min)
            max_non_zero_index = max(non_zero_indices_for_max)
            #print("    ", worst_delta)

            if 0:
                if worst_delta >= best[1]:
                    best = (worst_delta, a)
                    print(best)
            if 1:
                if worst_delta <= 11 and min_non_zero_index >= 1 and max_non_zero_index <= 3 and count_zeros >= 7:
                    print((worst_delta, count_zeros, (min_non_zero_index, max_non_zero_index), a))

    #print("Best:", best)
            

if __name__ == "__main__":
    main()

