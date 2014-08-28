#!/usr/bin/env python
# -*- coding: utf-8 -*-

# If we list all the natural numbers below 10 that are multiples of 3 or 5, we
# get 3, 5, 6 and 9. The sum of these multiples is 23.

# Find the sum of all the multiples of 3 or 5 below 1000.
sum = 0
n = 1000

for i in xrange(0, n, 3):
    sum += i
for i in xrange(0, n, 5):
    sum += i
for i in xrange(0, n, 15):
    sum -= i

print sum
