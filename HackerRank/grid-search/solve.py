def inputMatrix():
    matrix = []
    dimensions = map(int, raw_input().strip().split(' '))
    x, y = dimensions[0], dimensions[1]

    for a in xrange(x):
        current_row = []
        line = raw_input().strip()
        for char in line:
            current_row.append(int(char))
        matrix.append(current_row)
    return matrix, (x, y)


def checkMatrices(x, y, pattern_x, pattern_y, matrix, pattern):
    for i in xrange(pattern_x):
        for j in xrange(pattern_y):
            if matrix[x+i][y+j] != pattern[i][j]:
                return False
    return True

def solve():
    matrix, (matrix_x, matrix_y) = inputMatrix()
    pattern, (pattern_x, pattern_y) = inputMatrix()

    for x in xrange(matrix_x-pattern_x+1):
        for y in xrange(matrix_y-pattern_y+1):
            match = checkMatrices(x, y, pattern_x, pattern_y, matrix, pattern)
            if match:
                return "YES"
    return "NO"

num_cases = int(raw_input())
for i in xrange(num_cases):
    print solve()
