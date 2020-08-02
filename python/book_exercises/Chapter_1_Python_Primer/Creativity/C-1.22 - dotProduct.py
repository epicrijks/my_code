# Write a short Python program that takes two arrays a and b of length n
# storing int values, and returns the dot product of a and b. That is, it returns
# an array c of length n such that c[i] = a[i] · b[i], for i = 0, . . . , n − 1.

def dot_product(a, b):
    length = len(a)
    if length != len(b):
        print("Arrays must be of same size.")
        return list()
    else:
        try:
            c = []
            for i in range(length):
                if not isinstance(a[i], int) or not isinstance(b[i], int):
                    raise ValueError
                c.append(a[i]*b[i])
            return c
        except ValueError:
            print("Invalid item.")
            return list()

assert dot_product([1, 2], [1]) == []
assert dot_product([0, 1, 2], [4, 'hello', 5]) == []
assert dot_product([1.2], [2.0]) == []
assert dot_product([0], [0]) == [0]
assert dot_product([1, 2, 3], [3, 2, 1]) == [3, 4, 3]
assert dot_product([-5, -6, -7], [1, 2, 3]) == [-5, -12, -21]