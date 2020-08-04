from time import time

def compute_average(n):
    """perform n appends to an empty list and return average time elapsed."""
    data = []
    start = time()
    for _ in range(n):
        data.append(None)
    end = time()
    return (end - start) / n

for p in range(2, 9):
    print(compute_average(10**p))