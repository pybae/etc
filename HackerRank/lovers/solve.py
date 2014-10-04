# Python 3
import math

CASES = int(input())
for i in range(0, CASES):
    inputs = list(map(int, input().strip().split(' ')))
    n, r = inputs[0], inputs[1]

    lower_bound = 2*r-1
    if (lower_bound < n):
        gap = n - lower_bound
        current = 1     # the current section of numbers to add
        increment = r-1 # the number of places available to insert
        result = 0      # the total number of sequences

        result += gap + 1 # bare value
        result += gap*(gap+1) // 2
#        result += r-1

        print(result)
        
        
        for i in range(gap+1):
            result += current
            current += increment

        print (result % 100003)
    #    sum = gap*(gap+1) // 2
    #    result = r*sum+1
    else:
        print(0)
