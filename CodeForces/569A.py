#!/usr/bin/env python
# -*- coding: utf-8 -*-

t, s, q = map(int, input().split())

c = 0
while s < t:
    s *= q
    c += 1

print(c)
