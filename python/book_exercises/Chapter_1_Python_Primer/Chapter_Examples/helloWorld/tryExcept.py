try:
    fp = open('sample.txt')
except IOError as e:
    print('Unable to open the file:', e, sep = '\n')

# multiple exception cases - same response
age = -1
while age <= 0:
    try:
        age = int(input('Enter your age in years: '))
        if age <= 0:
            print('Your age must be positive')
    except (ValueError, EOFError):
        pass    # keyword that does nothing

# multiple exception cases - different response
age = −1    # an initially invalid choice
while age <= 0:
    try:
        age = int(input( Enter your age in years: ))
        if age <= 0:
            print( Your age must be positive )
    except ValueError:
        print( That is an invalid age specification )
    except EOFError:
        print( There was an unexpected error reading input. )
        raise # let s re-raise this exception