# An implementation of the Longest Common Subsequence Problem
# Takes two command line arguments, the two subsequences and prints out the
# longest common subsequence and its size

from copy import deepcopy
import sys

def lcs (prev, current, a, b):
    rows, columns = len(a), len(b)
    print(columns, rows)
    print(current)
    for i in range(1, rows + 1):
        for j in range(1, columns + 1): # skip the first column
            if a[i-1] == b[j-1]: # decrement since we start at 1
                current[j] = prev[j - 1] + 1
            else:
                current[j] = max(prev[j], current[j - 1])
        print(current)
        prev = deepcopy(current)
    print("Max value is", current[columns])
    return current[columns]

# Parse the command line arguments into an array
if len(sys.argv) != 3:
    print("There can only be two arguments")
    quit() # may be unsafe

# Initialize two rows of the array, our previous, and the one we are using
# n are the rows in the array and m are the columns
# We increment the length for our "perimeter"
prev = [0 for i in range(len(sys.argv[2]) + 1)]
current = [0 for i in range(len(sys.argv[2]) + 1)]
lcs (prev, current, sys.argv[1], sys.argv[2])
