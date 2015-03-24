a, b = sorted(map(int, input().split()))

ans = 0
while b:
    ans += (a // b)
    a, b = b, a % b

print(ans)
