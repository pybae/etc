#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

max = 0
for i in reversed(xrange(101, 1000)):
    for j in reversed(xrange(101, 1000)):
        if i*j < max:
            break
        if str(i*j)==str(i*j)[::-1] and i*j > max:
            max = i*j
print max
