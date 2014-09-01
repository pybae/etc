#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.path.append('/Users/pybae/etc/Project Euler/')

import general

array = general.prime(200000)
print array[10000]
