def solve(list):
    # look for swaps
    i = 0
    sorted_list = sorted(list)
    while i < len(list):
        # found something out of order
        if (sorted_list[i] != list[i]):
            start_idx = i
            end_idx = i + 1
            while end_idx < len(list):
                # we might be able to fix this with a swap
                if (start_idx == 0 or list[start_idx] < list[end_idx]) and \
                   (start_idx == len(list)-1 or list[start_idx+1] > list[end_idx]):
                    print "Found a swap"
                end_idx += 1
        i += 1
    

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
#            print section
#            print start_idx
#            print end_idx

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
    if has_reverse:
        print "reverse " + str(start_idx+1) + " " + str(end_idx+1)
NUM_INTS = raw_input()
NUMS = map(int, raw_input().strip().split(' '))
solve(NUMS)
