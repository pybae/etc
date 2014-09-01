#!/usr/bin/env python
# -*- coding: utf-8 -*-
# A general purpose file including several blanket functions to simplify Project
# Euler code

import numpy
import math
import cProfile
import pstats
import StringIO

def prime(n):
    return filter(lambda num: (num % \
        numpy.arange(2, 1+int(math.sqrt(num)))).all(), range(2, n+1))

pr = cProfile.Profile()
pr.enable()
array = prime(1000)
pr.disable()
s = StringIO.StringIO()
sortby = 'cumulative'
ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
ps.print_stats()
