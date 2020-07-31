# Write a pseudo-code description of a function that reverses a list of n
# integers, so that the numbers are listed in the opposite order than they
# were before, and compare this method to an equivalent Python function
# for doing the same thing.

# set i to 0, and j to -1
# while i < j
#   swap list[i] and list[j]
#   add 1 to i, subtract 1 from j

# I want to write it for fun

def reverse_list(data):
    i = 0
    j = -1
    length = len(data)

    while j + length > i:
        data[i], data[j] = data[j], data[i]
        i += 1
        j -= 1

checks = [0]
reverse_list(checks)
assert checks == [0]

checks = [1, 2]
reverse_list(checks)
assert checks == [2, 1]

checks = [1, 2, 3]
reverse_list(checks)
assert checks == [3, 2, 1]

checks = [1, 2, 2, 3]
reverse_list(checks)
assert checks == [3, 2, 2, 1,] 