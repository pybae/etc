"""
Solves the cover stains problem:
Input first line
N, K
and then pairs of stains (x, y)
"""

def getPairs(k, edge, stains):
    if len(edge) > k:
        return 0
    if len(edge) == k:
        return 1

    result = 1
    for i in xrange(k-1):
        result *= len(stains)-len(edge)
    return result

def findOverlap(a, b):
    i = 0
    while i < len(a) and i < len(b):
        if a[i] == b[i]:
            return 1
        i += 1
    return 0

def solve(n, k, stains):
    x_vals, y_vals = zip(*stains)

    x_min = min(x_vals)
    x_max = max(x_vals)
    y_min = min(y_vals)
    y_max = max(y_vals)

    # get the set of points corresponding to each edge
    left_edge = []
    right_edge = []
    bottom_edge = []
    top_edge = []
    for idx, tup in enumerate(stains):
        x, y = tup
        if x == x_min:
            left_edge.append(idx)
        elif x == x_max:
            right_edge.append(idx)
        if y == y_min:
            bottom_edge.append(idx)
        elif y == y_max:
            top_edge.append(idx)

    top_left = findOverlap(left_edge, top_edge)
    top_right = findOverlap(right_edge, top_edge)
    bottom_left = findOverlap(left_edge, bottom_edge)
    bottom_right = findOverlap(right_edge, bottom_edge)

    print top_left
    print top_right
    print bottom_left
    print bottom_right

    # get all pairs (including duplicates)
    result = getPairs(k, left_edge, stains)   + \
             getPairs(k, right_edge, stains)  + \
             getPairs(k, bottom_edge, stains) + \
             getPairs(k, top_edge, stains)

    result -= top_left     + \
              top_right    + \
              bottom_left  + \
              bottom_right

    return result % 1000000007

A = raw_input().split()
N, K = int(A[0]), int(A[1])
STAINS = []
for i in xrange(N):
    S = raw_input().split()
    STAINS.append((int(S[0]), int(S[1])))

print solve(N, K, STAINS)
