def minmax(data):
    if data:
        min = max = data[0]
        
        for entry in data:
            max = entry if entry > max else max
            min = entry if entry < min else min
        
        return min, max
    return (None, None)

assert minmax([1, 2, 3, 4, 5, 6]) == (1, 6)
assert minmax([]) == (None, None)
assert minmax([5, -100, 100]) == (-100, 100)
assert minmax([0, 0]) == (0, 0)
assert minmax([0]) == (0, 0)
print("Passed.")