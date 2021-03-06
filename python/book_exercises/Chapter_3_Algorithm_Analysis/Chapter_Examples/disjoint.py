# n^3-time algorithm
def disjoint1(A, B, C):
    """Return True if there is no element comon to all three lists."""
    for a in A:
        for b in B:
            for c in C:
                if a == b == c:
                    return False
    return True

# an n^2-time algorithm
def disjoint2(A, B, C):
    """Return True if there is no element comon to all three lists."""
    for a in A:
        for b in B:
            if a == b:
                for c in C:
                    if a == c:
                        return False
    return True