#!/usr/bin/env python
# -*- coding: utf-8 -*-

sum = 0
n = 100 + 1
for i in xrange(n):
    for j in xrange(i+1, n):
        sum += i*j
print 2*sum
