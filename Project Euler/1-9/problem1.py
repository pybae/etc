#!/usr/bin/env python
# -*- coding: utf-8 -*-

sum = 0
n = 1000

for i in xrange(0, n, 3):
    sum += i
for i in xrange(0, n, 5):
    sum += i
for i in xrange(0, n, 15):
    sum -= i

print sum
