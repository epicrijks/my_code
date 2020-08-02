def is_distinct(data):
    end = len(data)
    for current in range(0, end):
        if data[current] in data[current+1:end]:
            return False
    return True

assert is_distinct([0]) == True
assert is_distinct([1, 2]) == True
assert is_distinct([-5, -4, -3]) == True
assert is_distinct([4, 5, 7, 8, 4]) == False
assert is_distinct([1, 2, 3, 3, 4]) == False
assert is_distinct('Hello') == False
assert is_distinct('python') == True