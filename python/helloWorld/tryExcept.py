try:
    fp = open('sample.txt')
except IOError as e:
    print('Unable to open the file:', e, sep = '\n')

# multiple exception cases
age = -1
while age <= 0:
    try:
        age = int(input('Enter your age in years: '))
        if age <= 0:
            print('Your age must be positive')
    except (ValueError, EOFError):
        pass    # keyword that does nothing