#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.path.append('/Users/pybae/etc/Project Euler')

import general
import operator
array = general.prime(2000000)

print reduce(operator.add, array)
