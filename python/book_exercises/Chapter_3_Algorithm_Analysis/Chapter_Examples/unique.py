# An n^2-algorithm
def unique(S):
    """Return True is there are no duplicate elements in sequence S."""
    for j in range(len(S)):
        for k in range(j+1, len(S)):
            if S[j] == S[k]:
                return False
    return True

# Using sorting to achieve n log n-time
def unique2(S):
    """Return True if there are no duplicate elements in sequence S."""
    temp = sorted(S)
    for j in range(1, len(temp)):
        if S[j-1] == S[j]:
            return False
    return True