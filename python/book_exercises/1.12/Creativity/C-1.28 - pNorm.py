# The p-norm of a vector v = (v 1 , v 2 , . . . , v n ) in n-dimensional space is de-
# fined as
# 
# p
# v = v 1 p + v 2 p + · · · + v n p .
# For the special case of p = 2, this results in the traditional Euclidean
# norm, which represents the length of the vector. For example, the Eu-
# clidean norm of a two-dimensional
# with coordinates (4, 3) has a
# √
# √ vector √
# 2
# 2
# Euclidean norm of 4 + 3 = 16 + 9 = 25 = 5. Give an implemen-
# tation of a function named norm such that norm(v, p) returns the p-norm
# value of v and norm(v) returns the Euclidean norm of v. You may assume
# that v is a list of numbers.

def norm(v, p=2):
    for i in range(0, len(v)):
        v[i] *= v[i]
    return pow(sum(v), 1/float(p))