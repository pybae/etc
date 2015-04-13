#! /usr/bin/python

from itertools import permutations

n, k = map(int, input().split())
N = []
for i in range(n):
    N.append(permutations(input().strip()))

ans = 1000000000
try:
    while True:
        X = []
        for i in range(n):
            X.append(int("".join(next(N[i]))))

        diff = max(X) - min(X)
        if diff < ans:
            ans = diff

except StopIteration:
    print(ans)
