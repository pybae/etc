#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input().strip())
ans = 0
count = 0

while n:
    v = n % 10
    n //= 10
    if v == 4:
        ans += 1 * 2 ** count
    else:
        ans += 2 * 2 ** count
    count += 1

print(ans)
