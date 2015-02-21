#!/usr/bin/env python

n, l = map(int, input().strip().split())
a = map(int, input().strip().split())

a = sorted(a)

prev = a[0] if len(a) else 0
total = 0

if (prev > total):
    total = prev

for lamp in a[1:]:
    if ((lamp - prev) / 2 > total):
        total = (lamp - prev) / 2
    prev = lamp

if (l - prev > total):
    total = l - prev

print(float(total))
