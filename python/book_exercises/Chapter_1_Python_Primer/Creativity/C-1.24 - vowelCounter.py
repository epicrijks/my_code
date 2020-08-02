# Write a short Python function that counts the number of vowels in a given
# character string.

def count_vowels(s):
    vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
    total = -1
    if isinstance(s, str):
        total = 0
        for c in s:
            if c in vowels:
                total += 1
    return total


assert count_vowels(5) == -1
assert count_vowels(2.5) == -1
assert count_vowels("aeiou") == 5
assert count_vowels("bcdfghjklmnpqrstvwxyz") == 0
assert count_vowels("AEIOU") == 5
assert count_vowels("BCDFGHJKLMNPQRSTVWXYZ") == 0
assert count_vowels("A") == 1
assert count_vowels("E") == 1
assert count_vowels("I") == 1
assert count_vowels("O") == 1
assert count_vowels("U") == 1
assert count_vowels("a") == 1
assert count_vowels("e") == 1
assert count_vowels("i") == 1
assert count_vowels("o") == 1
assert count_vowels("u") == 1