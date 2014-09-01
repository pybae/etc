#!/usr/bin/env python
# -*- coding: utf-8 -*-

def sieve_of_erathosthenes(n):
    factors = set()
    primes = []
    for i in range(2, n+1):
        if i not in factors:
            primes.append(i)
            factors.update(range(i*i, n+1, i))
    return primes

n = 600851475143 
i = 0
max_factor = 2 # assuming n >= 2

primes = sieve_of_erathosthenes(100000)
while n > 1:
    if n % primes[i] == 0:
    	n /= primes[i]
    else:
    	i += 1
print primes[i]
