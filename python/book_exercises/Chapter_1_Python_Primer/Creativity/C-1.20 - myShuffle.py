# Python’s random module includes a function shuffle(data) that accepts a
# list of elements and randomly reorders the elements so that each possi-
# ble order occurs with equal probability. The random module includes a
# more basic function randint(a, b) that returns a uniformly random integer
# from a to b (including both endpoints). Using only the randint function,
# implement your own version of the shuffle function.

# Pseudo code
# start with data
# store last index
# iterate through list, starting from beginning
# choose a random index between current position and last index
# swap current position and that random index
# increase current position and repeat until last element

from random import randint, shuffle
import time

def my_shuffle(data):
    end = len(data)-1
    for i in range(0, end+1):
         j = randint(i, end)
         data[i], data[j] = data[j], data[i]

start_time = time.time()
data = [1, 2, 3]
resultingPerms = []

for n in range(10000000):
    my_shuffle(data)
    # resultingPerms.append(data)
    data = [1, 2, 3]

# a = [1, 2, 3]
# b = [1, 3, 2]
# c = [2, 1, 3]
# d = [2, 3, 1]
# e = [3, 2, 1]
# f = [3, 1, 2]


# print('[1, 2, 3]:', resultingPerms.count([1, 2, 3]))
# print('[1, 3, 2]:', resultingPerms.count([1, 3, 2]))
# print('[2, 1, 3]:', resultingPerms.count([2, 1, 3]))
# print('[2, 3, 1]:', resultingPerms.count([2, 3, 1]))
# print('[3, 1, 2]:', resultingPerms.count([3, 1, 2]))
# print('[3, 2, 1]:', resultingPerms.count([3, 2, 1]))

print("--- %s seconds ---" % (time.time() - start_time))
