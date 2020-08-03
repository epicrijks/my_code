# Use recursion to write a Python function for determining if a string s has
# more vowels than consonants.

# Linear time implementation.
# Will rewrite as log n time implementation on next revision

def is_vowel(s):
    return s in ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U']
    
def more_vowels_recur(s, vowelCount, consCount):
    # If the last letter, check for count then return tuple
    if len(s) == 1:
        if s[0] in ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U']:
            return (vowelCount+1, consCount)
        elif s[0].isalpha():
            return (vowelCount, consCount+1)
        else:
            return (vowelCount, consCount)


    if is_vowel(s[0]):
        return more_vowels_recur(s[1:], vowelCount+1, consCount)
    elif s[0].isalpha():
        return more_vowels_recur(s[1:], vowelCount, consCount+1)
    else:
        return more_vowels_recur(s[1:], vowelCount, consCount)

def more_vowels(s):
    results = more_vowels_recur(s, 0, 0)
    return results[0] > results[1]

assert more_vowels("B") == False
assert more_vowels("A") == True
assert more_vowels("abcde") == False
assert more_vowels('AEIOUt') == True