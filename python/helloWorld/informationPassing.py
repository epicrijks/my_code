# on immutable objects
def double(x):
    x = x * 2
    return

num = 4
print(num)
double(num)
print(num)

# on mutable objects
def addEntry(numbers):
    numbers.append(6)

nums = [1, 2, 3, 4]
print(nums)
addEntry(nums)
print(nums)