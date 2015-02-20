a, b, s = [abs(int(x)) for x in input().strip().split()]
diff = s - a - b
print("Yes" if diff >= 0 and diff % 2 == 0 else "No")
