import math

def getAngle(tup):
    x = tup[0]
    y = tup[1]

    if y >= 0:
        return math.atan2(y, x)
    else:
        return 2*math.pi + math.atan2(y, x)

def solve():

    num_cases = int(raw_input())

    list = []
    for i in xrange(num_cases):
        array = raw_input().split(' ')
        x = int(array[0])
        y = int(array[1])

        list.append((x, y))
        
    list = sorted(list, key=lambda tup: math.sqrt(tup[0]**2 + tup[1]**2))
    list = sorted(list, key=getAngle)
    for tup in list:
        print tup[0], tup[1]

solve()
