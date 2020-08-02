# Write a short Python function that takes a string s, representing a sentence,
# and returns a copy of the string with all punctuation removed. For exam-
# ple, if given the string "Let s try, Mike.", this function would return
# "Lets try Mike".

def remove_punctuation(s):
    r = ""
    non_punct = list(range(48, 58)) # ASCII for 0-9
    for c in range(65, 91):         # ASCII for 'A'-'Z'
        non_punct.append(c)
    for c in range(97, 123):        # ASCII for 'a'-'z'
        non_punct.append(c)
    non_punct.append(32)            # Space

    for ind in range(0, len(s)):
        if ord(s[ind]) in non_punct:
            r += s[ind]
    return r

assert remove_punctuation("abcdefghijklmnopqrstuvwxyz") == "abcdefghijklmnopqrstuvwxyz"
assert remove_punctuation("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
assert remove_punctuation("1234567890") == "1234567890"
assert remove_punctuation("~`!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?") == ""
assert remove_punctuation("Let's try, Mike!") == "Lets try Mike"