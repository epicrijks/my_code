def _find_min_max_recur(S, end):
    if end == 0:
        return (S[0], S[0]) # Base case, return last element as min and max
    else:
        min_max_tup = _find_min_max_recur(S[0:end], end-1)
        return (min(S[end], min_max_tup[0]), max(S[end], min_max_tup[1]))    # Use Python's max funtion to compare and get max

def find_min_max(S):
    """Returns a tuple with the min value in S and max value in S."""
    return _find_min_max_recur(S, len(S)-1)


print(find_min_max([  3, 52, 21, 64, 39, 81, 17, 37, 48, 13, 22, 46, 77, 34, 65,9, 59, 40, 54, 47, 75, 30, 15, 95, 86, 56, 57, 38, 80, 28,\
     61, 25,5, 82, 43, 83, 79, 63,4, 94, 35, 36, 51, 93, 78, 41, 20, 92,8, 68, 69, 71, 66, 27, 88, 33,6, 14, 24, 16, 32,7, 18, 53, 55, 19, \
         31, 60, 29, 42, 91, 85, 11, 87, 70, 67, 74,2, 98, 76, 97, 62, 73, 84,1, 50, 10, 58, 12, 89, 49, 45, 96, 23, 26, 72, 44, 90])) 
print(find_min_max([1, 2, 3, 4]))