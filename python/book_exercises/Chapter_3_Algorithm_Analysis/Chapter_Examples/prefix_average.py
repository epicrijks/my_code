# A quadratic-time algorithm
def prefix_average1(S):
    """Return list such that, for all j, A[j] equals the average of S[0], ..., S[j]."""
    n = len(S)
    A = [0] * n
    for j in range(n):
        total = 0
        for i in range(j + 1):
            total += S[i]
        A[j] = total / (j + 1)
    return A

# Another quadratic-time implemention
def prefix_averge2(S):
    """Return list such that, for all j, A[j] equals the average of S[0], ..., S[j]."""
    n = len(S)
    A = [0] * n
    for j in range(n):
        A[j] = sum(S[0:j+1]) / (j+1)
    return A

# A linear-time algorithm
def prefix_average3(S):
    """Return list such that, for all j, A[j] equals the average of S[0], ..., S[j]."""
    n = len(S)
    A = [0] * n
    total = 0
    for j in range(n):
        total += S[j]
        A[j] = total / (j + 1)
    return A