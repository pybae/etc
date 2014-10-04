def look_for_swap(list):
    i = 0
    out_of_order = False
    while i < len(list)-1:
        if out_of_order:
            return False
        out_of_order = True
        if list[i+1] < list[i]: # out of order
            j = i + 1
            while j < len(list):
                if (i == 0 or list[i-1] <= list[j]) and \
                   (list[i+1] >= j):
                    if (list[j-1] <= list[i]) and \
                       (j == len(list)-1 or list[j+1] >= list[i]):
                        print "yes"
                        print "swap", i+1, j+1
                        return True
                j += 1
            i += 1

    if not out_of_order:
        print "no"
        return True
    return False

def look_for_reverse(list):
    # look for reverses
    i = 0
    has_reverse = False

    start_idx  = 0
    end_idx    = 0
    while i < len(list) - 1:
        if list[i+1] < list[i]: # out of order
            # already swapped or reversed, cannot be correct
            if has_reverse:
                print "no"
                return

            # find section that is in decreasing order
            # can assumes there are no duplicates
            start_idx = end_idx = i
            while end_idx < len(list) - 1 and \
                  list[end_idx+1] < list[end_idx]:
                end_idx += 1
            section = list[start_idx:end_idx+1]

            # we might be able to fix this with a reverse
            if (start_idx == 0 or section[-1] > list[start_idx-1]) and \
               (end_idx == len(list)-1 or section[0] < list[end_idx+1]):
                has_reverse = True
            else:
                print "no"
                return
            i = end_idx
        else:
            i += 1

    print "yes"
    print "reverse", start_idx+1, end_idx+1

NUM_INTS = raw_input()
NUMS = map(int, raw_input().strip().split(' '))
# COUNT = count_out_of_ordered(NUMS)

#elif COUNT < 2:
#    # look for swaps
if not look_for_swap(NUMS):
    look_for_reverse(NUMS)
