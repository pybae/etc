#!/usr/bin/env python
# -*- coding: utf-8 -*-

sum = 0
a, b = 0,1
while b < 4000000:
    if b % 2 == 0:
        sum += b
    a, b = b, a + b
print sum
