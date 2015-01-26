# CodeForces Problem 2

import re

n = int(input())
for num in range(n):
    s = input()
    if(re.match('R\d+C\d', s)):
        r, c = re.findall('\d+', s)
        
        output = ""
        c = int(c)
        while c != 0:
            c -= 1
            output += chr(c % 26 + ord('A'))
            c //= 26
        output = output[::-1] + r
        
        print(output)
    else:
        c, r = re.findall('([A-Z]+|\d+)', s)
        
        output = "R" + r + "C"
        num = 0
        for i, v in enumerate(reversed(c)):
            num += (ord(v) - ord('A') + 1) * 26 ** i
            
        output += str(num)
        
        print(output)

print()
