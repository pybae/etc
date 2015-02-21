#!/usr/bin/env python

n, r, avg = map(int, input().strip().split())
total = 0
exams = []

for i in range(n):
    x, y = map(int, input().strip().split())
    exams.append((y, r - x))
    total += x

exams.sort()

deficit = avg * n - total
count = 0
i = 0

while deficit > 0:
    gap = min(exams[i][1], deficit)
    count += gap * exams[i][0]
    deficit -= gap
    i += 1

print(count)
