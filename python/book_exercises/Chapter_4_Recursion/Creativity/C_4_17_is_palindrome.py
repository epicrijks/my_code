# Write a short recursive Python function that determines if a string s is a
# palindrome, that is, it is equal to its reverse. For example, racecar and
# gohangasalamiimalasagnahog are palindromes.

def is_palindrome(s):
    if len(s) <= 1:
        return True
    else:
        return (s[0] == s[-1]) and is_palindrome(s[1:-1])

assert is_palindrome("racecar") == True
assert is_palindrome("gohangasalamiimalasagnahog") == True
assert is_palindrome("steponnopets") == True

assert is_palindrome("hello") == False
assert is_palindrome("123") == False