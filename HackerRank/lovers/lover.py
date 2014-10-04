import math
cases = input()

def nCr(n, r):
  if n >= r >= 0:
    nr = 1
    rr = 1
    for i in xrange(1, min(r, n - r) + 1):
      nr *= n
      rr *= i
      n -= 1
    return nr // rr
  else:
  	return 0

for i in range(0, cases):
  inputs = map(int, raw_input().split())
  print nCr(inputs[0] - inputs[1] + 1, inputs[0] - 2 * inputs[1] + 1) % 100003
