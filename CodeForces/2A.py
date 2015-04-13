#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input().strip())
players = {}
b = []

for i in range(n):
    cur, i = input().split()

    if cur not in players:
        players[cur] = 0
    players[cur] += int(i)
    b.append((cur, players[cur]))

m = max(players.values())

for name, val in b:
    if val >= m and players[name] == m:
        print(name)
        break
