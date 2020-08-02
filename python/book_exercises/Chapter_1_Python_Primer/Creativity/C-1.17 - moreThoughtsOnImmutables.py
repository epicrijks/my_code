# Had we implemented the scale function (page 25) as follows, does it work
# properly?
# def scale(data, factor):
#   for val in data:
#       val *= factor
# Explain why or why not.

# No, because val *= factor is attempting to chanege the value in the object
# pointed to by the pointer in the list. But that value is immutable.
