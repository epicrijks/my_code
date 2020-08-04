from matrix import Matrix

A = Matrix(4, 3)
B = Matrix(4, 3)
C = Matrix(4, 2)

A.insert(0, 0, 3)
B.insert(0, 0, 3)
print(A*B)