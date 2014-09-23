#!/usr/bin/env python
# -*- coding: utf-8 -*-

withdraw, balance = raw_input().split()
withdraw = int(withdraw)
balance  = float(balance)

if (withdraw % 5 or withdraw + .5 > balance):
    print '%.2f' % balance
else:
    print '%.2f' % (balance - withdraw - .5)
