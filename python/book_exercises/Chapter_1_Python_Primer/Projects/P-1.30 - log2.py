# Write a Python program that can take a positive integer greater than 2 as
# input and write out the number of times one must repeatedly divide this
# number by 2 before getting a value less than 2.

def log_base_2_approx(k):
    if not isinstance(k, int) or k <= 2:
        return -1
    
    count = 0
    while k >= 2:
        k /= 2
        count += 1
    return count

assert log_base_2_approx(2) == -1
assert log_base_2_approx(1) == -1
assert log_base_2_approx(3.5) == -1
assert log_base_2_approx("string") == -1
assert log_base_2_approx(True) == -1

assert log_base_2_approx(4) == 2
assert log_base_2_approx(8) == 3
assert log_base_2_approx(128) == 7

assert log_base_2_approx(3) == 1
assert log_base_2_approx(5) == 2
assert log_base_2_approx(45) == 5