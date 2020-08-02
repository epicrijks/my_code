# prints all permutations of "catdog"

from math import factorial

def shift_left_one(data):
    for i in range(0, len(data)-1):
        data[i], data[i+1] = data[i+1], data[i]

def swap_first_and_second(data):
    data[0], data[1] = data[1], data[0]


def print_all_permutations(data):
    count = 1   # counter to print line numbers
    length = len(data) 
    for _ in range(1, factorial(length-1)+1): # iterate through (n-1)! groups of shifts/printing
        for j in range(1, length+1):    # iterates for each group, n possible permutations
            print(count, ": ", data)    # prints a line number with current permutation
            count += 1                  # increase line number
            if j != length:
                shift_left_one(data)
            else:
                swap_first_and_second(data)

catdog = ['c', 'a', 't', 'd', 'o', 'g']
print_all_permutations(catdog)              # prints 720 permutations of those letter :)