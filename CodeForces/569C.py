#!/usr/bin/env python
# -*- coding: utf-8 -*-

limit = 2*10**6 + 7

primes = [True] * limit

for i in range(3, int(limit ** .5) + 1, 2):
    if primes[i]:
        primes[i*i::2*i] = [False] * len(range(i*i, limit, 2*i))

primes[0] = primes[1] = False
primes[4::2] = [False] * len(range(4, limit, 2))

cumm = 0
cump = []
for i in primes:
    cumm += i
    cump.append(cumm)

palin = [str(i) == str(i)[:: -1] for i in range(limit)]
cumm = -1
cuml = []
for i in palin:
    cumm += i
    cuml.append(cumm)

p, q = map(int, input().split())

for i in range(limit - 1, 0, -1):
    if q*cump[i] <= p*cuml[i]:
        print(i)
        break
else:
    print('Palindromic tree is better than splay tree')
