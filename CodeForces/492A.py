#!/usr/bin/env python

n = int(input())
count = 0
i = 1

while count <= n:
    i += 1
    count += i * (i - 1) / 2

print(i - 2)
