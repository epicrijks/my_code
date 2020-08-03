# Write a short recursive Python function that takes a character string s and
# outputs its reverse. For example, the reverse of pots&pans would be
# snap&stop .

def reverse_string(s):
    if len(s) <= 1:
        return s
    else:
        return s[-1] + str(reverse_string(s[1:-1])) + s[0]

assert reverse_string("pots&pans") == "snap&stop"
assert reverse_string("prince") == "ecnirp"
assert reverse_string("hello") == "olleh"
assert reverse_string("A") == "A"
assert reverse_string("AB") == "BA"
assert reverse_string("ABC") == "CBA"
assert reverse_string("ABCD") == "DCBA"
assert reverse_string("ABCDE") == "EDCBA"