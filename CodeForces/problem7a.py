#!/usr/bin/env python
# -*- coding: utf-8 -*-

a = [input().count('B') for i in range(8)]
print(min(a) % 8 + a.count(8))
