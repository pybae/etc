#!/usr/bin/env python
# -*- coding: utf-8 -*-

def prime_factors(n):
    factors = set()
    primes = []
    for i in range(2, n+1):
        if i not in factors and n % i == 0:
            primes.append(i)
            factors.update(range(i*i, n+1, i))
    return primes

n = 20
max_prime_factors = []
max_prime_powers = []
for i in xrange(1, n+1):
    factors = prime_factors(i)
    for a in factors:
        power = 0
        while i % a == 0:
            power += 1
            i /= a
        if a in max_prime_factors:
            j = max_prime_factors.index(a)
            if max_prime_powers[j] < power:
                max_prime_powers[j] = power
        else:
            max_prime_factors.append(a)
            max_prime_powers.append(power)
l = [(x ** y) for (x, y) in zip(max_prime_factors, max_prime_powers)]
print l, reduce(lambda x, y: x*y, l)
