#!/usr/bin/env python
# -*- coding: utf-8 -*-

from math import sqrt, sin, pi, acos, floor
EPS = 1e-4


def gcd(a, b):
    while abs(a) > EPS and abs(b) > EPS:
        if a > b:
            a -= floor(a/b)*b
        else:
            b -= floor(b/a)*a
    return a+b


def dist(a, b):
    return sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)


def area(a, b, c):
    return abs(a[0]*(b[1] - c[1]) +
               b[0]*(c[1] - a[1]) +
               c[0]*(a[1] - b[1])) / 2


I = lambda: tuple(map(float, input().split()))
a = I()
b = I()
c = I()

AB = dist(a, b)
AC = dist(a, c)
BC = dist(b, c)

r = (AB * AC * BC) / (4 * area(a, b, c))
A = acos((AC**2 + BC**2 - AB**2)/(2*AC*BC))
B = acos((AB**2 + BC**2 - AC**2)/(2*AB*BC))
C = acos((AB**2 + AC**2 - BC**2)/(2*AB*AC))

d = gcd(gcd(A, B), C)
n = pi/d

print((n/2)*(r**2)*sin(2*pi/n))
