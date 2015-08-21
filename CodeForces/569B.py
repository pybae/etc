#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input().strip())
l = list(map(int, input().split()))

d = dict.fromkeys(range(1, n + 1), 0)

for e in l:
    if e in d:
        d[e] += 1

missing = []
for k in d:
    if d[k] == 0:
        missing.append(k)

for e in l:
    if e not in d:
        print(missing.pop(), end=" ")
    elif d[e] == 1:
        print(e, end=" ")
    else:
        print(missing.pop(), end=" ")
        d[e] -= 1

print()
