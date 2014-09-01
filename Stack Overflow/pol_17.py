#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
datafilename = 'pol_17.txt'
g = np.genfromtxt(datafilename, skiprows=6, usecols=(1, 2, 3, 4, 5, 6,7), 
        delimiter=None, dtype=[('f0', '<i4'), ('f1', '<i4'), ('f2', '<i4'),
            ('f3', '<f8'), ('f4', '<f8'), ('f5', '<f8'), ('f6', '<f8')])
#print g
#print g['f0']


for row in g:
    if row['f0'] == 17:
    	print row
