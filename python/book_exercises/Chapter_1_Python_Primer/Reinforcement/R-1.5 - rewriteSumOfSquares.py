def sumOfSquaresOfIntLessThan(k):
    total = -1
    if isinstance(k, int) and k > 0:
        total = 0
        total = sum([n*n for n in range(1, k)])
    return total

assert sumOfSquaresOfIntLessThan(0) == -1
assert sumOfSquaresOfIntLessThan(-5) == -1
assert sumOfSquaresOfIntLessThan(1.5) == -1

assert sumOfSquaresOfIntLessThan(1) == 0
assert sumOfSquaresOfIntLessThan(2) == 1
assert sumOfSquaresOfIntLessThan(3) == 5
assert sumOfSquaresOfIntLessThan(4) == 14

print("Passed assertions.")