import sys
# sys.stdin = open("in.txt", 'r')

t = int(input())

for i in range(t):
    s = list(str(input()))
    s.sort(reverse=True)
    print("".join(s))
