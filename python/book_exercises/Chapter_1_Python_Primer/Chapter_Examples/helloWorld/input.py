s = input("Enter something: ")
print(s) # This is printing a string

# Throws exception because input() returns a string. Must cast to int/float
# num = input("Enter a number: ")
# if num < 5:
#     print("The number you entered is less than 5.")

year = int(input("What year were you born? "))
if year == 1991:
    print("That's the same year I was born!")

# Return a list of strings separated by spaces
reply = input('Enter x and y, separated by spaces: ')
pieces = reply.split()
x = float(pieces[0])
y = float(pieces[1])

print("x: {0}; y: {1}".format(x, y))

