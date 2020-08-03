# Credit: https://stackoverflow.com/questions/26332412/python-recursive-function-to-display-all-subsets-of-given-set

def subs(l):
    if l == []:
        return [[]]

    x = subs(l[1:])

    return x + [[l[0]] + y for y in x]