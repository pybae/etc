def solve():
    array = raw_input().split(' ')
    first = int(array[0])
    second = int(array[1])
    third = second**2 + first
    
    num = int(array[2])
    for i in xrange(num-2):
        third = second**2 + first
        first, second = second, third
    print third
solve()
