"""
For the problem https://www.hackerrank.com/challenges/pangrams
"""

import string

def solve():
    """
    solves the problem with raw_input
    """
    line = raw_input()
    d = dict.fromkeys(string.ascii_lowercase, 0)
    for char in line:
        char = char.lower()
        if char in d:
            d[char] += 1

    for value in d.itervalues():
        if not value:
            return "not pangram"
    return "pangram"

print solve()
