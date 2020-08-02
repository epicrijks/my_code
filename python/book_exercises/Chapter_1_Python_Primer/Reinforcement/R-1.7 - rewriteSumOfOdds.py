def sumOfOdds(k):
    total = -1
    if isinstance(k, int) and k > 0:
        total = sum([n for n in range(1, k, 2)])
    return total


assert sumOfOdds(0) == -1
assert sumOfOdds(-5) == -1
assert sumOfOdds(1.5) == -1

assert sumOfOdds(1) == 0
assert sumOfOdds(2) == 1
assert sumOfOdds(3) == 1
assert sumOfOdds(4) == 4
assert sumOfOdds(5) == 4
assert sumOfOdds(6) == 9

print("Passed assertions.")