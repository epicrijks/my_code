# def factors(n):
#     k = 1
#     while k * k < n:
#         if n % k == 0:
#             yield k
#             yield n // k
#         k += 1
#     if k * k == n:
#         yield k

# print(list(factors(100)))

def factors2(num, start=1):
    if start > num:
        yield num
    
    while start * start < num:
        if num % start == 0:
            yield start
            factors2(num, start+1)
            yield num // start
        start += 1
    if start * start == num:
        yield start

while True:
    number = int(input())
    print(list(factors2(number)))
    

# Implemented as recursive function

# results = []
# def factors2(num, start=1):
#     if start > num:
#         results.append(num)
    
#     while start * start < num:
#         if num % start == 0:
#             results.append(start)
#             factors2(num, start+1)
#             results.append(num // start)
#             break
#         start += 1
#     if start * start == num:
#         results.append(start)

# while True:
#     results = []
#     num = int(input())
#     factors2(num)
#     print(results)
#     print()