def count(data, target):
    n = 0
    for item in data:
        if item == target:
            n += 1
    return n

print(count([1, 2, 3, 12, 1, 4, 2, 8, 1], 1) )