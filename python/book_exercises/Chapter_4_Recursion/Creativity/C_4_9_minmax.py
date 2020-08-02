def find_min_max_recur(S, end): # end = len(S) - 1
    if not end:
        return S[0]
    else:
        return max(S[end], find_min_max_recur(S[0:end-1], end-1))   # Use Python's max funtion to compare and get max

def find_min_max(S):
    return find_min_max_recur(S, len(S)-1)


print(find_min_max([1, 2, 3, 4]))