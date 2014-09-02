#!/usr/bin/env python
# -*- coding: utf-8 -*-

# all Pythagorean triples are either primitive triples (in where two of the
# numbers are coprime and the last is odd), or multiples of coprimes

# therefore we are looking for either a primitive triple a, b, c whose sum is
# 1000 or k*a + k*b + k*c = 1000
# so, we can generate primitive triples, and see if k is an integer

import operator

# by Euclid's formula
# note: not quite efficient, since m and n have to be coprime for the triple to
# be primitive
for m in xrange(1, 10):
    for n in xrange(1, m):
        a = m**2 - n**2
        b = 2*m*n
        c = m**2 + n**2
        if 1000 % (a+b+c) == 0:
        	factor = 1000 / (a+b+c)
        	tup = (factor*a, factor*b, factor*c)
        	print reduce(operator.mul, tup)
