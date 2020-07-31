# Write a Python program that repeatedly reads lines from standard input
# until an EOFError is raised, and then outputs those lines in reverse order
# (a user can indicate end of input by typing ctrl-D).

print("""Enter as many lines as you wish.
Press ctrl-D when you are finished.\n""")

data = []
try:    
    while (True):
        data.insert(0, input())
except EOFError:
        print()
        for line in data:
            print(line)
    