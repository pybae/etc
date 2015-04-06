#!/usr/bin/env python
# -*- coding: utf-8 -*-

n, k = map(int, input().split())
if n == k:
    print(-1)
else:
    print(' '.join(map(str, list(range(2, n-k+1)) + [1] + list(range(n-k+1, n+1)))))
