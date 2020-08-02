# Write a short Python function that takes a sequence of integer values and
# determines if there is a distinct pair of numbers in the sequence whose
# product is odd.

# Thought: If the sequence has two odd numbers, then there exists a distinct pair
# whose product is odd.

def distinctProductOddPair(data):
    odds = []
    for n in data:
        if n % 2 == 1:
            if n not in odds:
                odds.append(n)
        if len(odds) == 2:
            return True
    return False

assert distinctProductOddPair([0]) == False
assert distinctProductOddPair([3]) == False
assert distinctProductOddPair([1, 2]) == False
assert distinctProductOddPair([1, 2, 3]) == True
assert distinctProductOddPair([3, 4, 5]) == True
assert distinctProductOddPair([4, 6, 8]) == False
assert distinctProductOddPair([-3, -1]) == True
assert distinctProductOddPair([-5, -9]) == True
assert distinctProductOddPair([9, 9, 6]) == False