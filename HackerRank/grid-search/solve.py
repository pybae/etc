def solve():
    num_cases = int(raw_input())

    for i in xrange(num_cases):
        array = []
        dimensions = map(int, raw_input().strip().split(' '))
        x, y = dimensions[0], dimensions[1]

        for a in xrange(x):
            current_row = []
            line = raw_input().strip()
            for char in line:
                current_row.append(int(char))
            array.append(current_row)
        print array
