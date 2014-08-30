#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import division
import sys
import math

def factorUp(n, factor):
    if factor == 0:
    	print 0 if n <= 0 else "No multiples greater than n!"
        return
    if n % factor == 0:
        print n
        return
    d = int(math.ceil(n/factor)) if factor > 0 else int(math.floor(n/factor))
    result = d*factor    
    print result if result < sys.maxint else "No multiples greater than n!"

factorUp(10, 3)
factorUp(10, -3)
factorUp(-10, 3)
factorUp(-10, -3)
factorUp(10, 0)
factorUp(10, 10)
factorUp(21, -9)
factorUp(-21, 9)
factorUp(sys.maxint, 1)
factorUp(sys.maxint, 2)
factorUp(sys.maxint, sys.maxint)
factorUp(-sys.maxint-1, 1)
factorUp(-sys.maxint-1, 2)
