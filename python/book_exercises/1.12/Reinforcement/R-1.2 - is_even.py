# no mult, div, or mod
def is_even(k):
    if k !=1 and k != -1 and isinstance(k, int):
        return k == 0 or bin(k).count("1") == 1
    return False
    

assert is_even(0) == True
assert is_even(4) == True
assert is_even(-4) == True

assert is_even(1) == False
assert is_even(-1) == False
assert is_even(1.5) == False