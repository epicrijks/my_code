# Write a short recursive Python function that rearranges a sequence of in-
# teger values so that all the even values appear before all the odd values.

def even_before_odd(data):
    if len(data) == 0:
        return data

    if len(data) == 1:
        return data

    res = []
    if data[0] % 2 == 0:
        res.append(data[0])
        for entry in even_before_odd(data[1:]):
            res.append(entry)
        return res
    else:
        for entry in even_before_odd(data[1:]):
            res.append(entry)
        res.append(data[0])
        return res

print(even_before_odd([]))
print(even_before_odd([1]))
print(even_before_odd([1, 2]))

assert even_before_odd([]) == []
assert even_before_odd([1]) == [1]
assert even_before_odd([1, 2]) == [2, 1]
assert even_before_odd([2, 1]) == [2, 1]
assert even_before_odd([1, 2, 3]) == [2, 3, 1]
assert even_before_odd([1, 3, 2]) == [2, 3, 1]
assert even_before_odd([2, 1, 3]) == [2, 3, 1]
assert even_before_odd([2, 3, 1]) == [2, 1, 3]