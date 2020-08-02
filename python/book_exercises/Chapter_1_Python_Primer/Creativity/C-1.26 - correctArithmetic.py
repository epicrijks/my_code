# Write a short program that takes as input three integers, a, b, and c, from
# the console and determines if they can be used in a correct arithmetic
# formula (in the given order), like “a + b = c,” “a = b − c,” or “a ∗ b = c.”

# possible arithmetic +, -, *, /, =

# take in a, b, c as arguments
def correct_arithmetic(a, b, c):
    if not isinstance((a, b, c), int):
            return False    
    try:
        return (a + b == c) or (a - b == c) or (a * b == c) or (a == b - c) \
            or (a / b == c) or (a == b / c)
    except ZeroDivisionError:
            return False

assert correct_arithmetic(0, 0, 0) == True      # Division by 0
assert correct_arithmetic(10, 2, 12) == True    # 10 + 2 = 13
assert correct_arithmetic(11, 12, -1) == True   # 11 - 12 = -1  && 11 = 12 + -1
assert correct_arithmetic(10, 20, 200) == True  # 10 * 20 = 200
assert correct_arithmetic(525, 5, 15) == True   # 525 / 5 = 15  && 525 = 5 * 15
assert correct_arithmetic(15, 20, 5) == True    # 15 = 20 - 5
assert correct_arithmetic(16, 32, 2) == True    # 16 = 32 / 2
assert correct_arithmetic(0, 0, 1) == True      # 0 = 0 / 1

assert correct_arithmetic(2.0, 5, 6) == False
assert correct_arithmetic(4, 3, "hello") == False
assert correct_arithmetic(51, 7, 8) == False
assert correct_arithmetic(26, 4, 6) == False

