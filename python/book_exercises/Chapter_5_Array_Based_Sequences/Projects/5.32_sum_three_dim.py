# Write a Python function that takes two three-dimensional numeric data
# sets and adds them componentwise.

def sum_three_dim(A, B):
    if len(A) != 3 or len(B) != 3:
        raise ValueError('lists must be 3x3')

    for row in A:
        if len(row) != 3:
            raise ValueError('lists must be 3x3')

    for row in B:
        if len(row) != 3:
            raise ValueError('lists must be 3x3')

    C = [[0] * 3 for j in range(3)]

    for i in range(3):
        for j in range(3):
            C[i][j] = A[i][j] + B[i][j]
    return C

a = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
b = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]

print(sum_three_dim(a, b))