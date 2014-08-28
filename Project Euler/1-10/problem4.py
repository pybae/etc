#!/usr/bin/env python
# -*- coding: utf-8 -*-

# A palindromic number reads the same both ways. The largest palindrome made
# from the product of two 2-digit numbers is 9009 = 91 × 99.

# Find the largest palindrome made from the product of two 3-digit numbers.
import sys

max = 0
for i in reversed(xrange(101, 1000)):
    for j in reversed(xrange(101, 1000)):
        if i*j < max:
            break
        if str(i*j)==str(i*j)[::-1] and i*j > max:
            max = i*j
print max
