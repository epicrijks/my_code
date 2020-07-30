def is_multiple(n, m):
    if m == 0:
        return False
    return n % m == 0

assert is_multiple(12, 0) == False
assert is_multiple(0, 45) == True
assert is_multiple(6, 3) == True
assert is_multiple(100, 3) == False