print('maroon', 5) # auto inserts space between args (and new line at end)
print('maroon', 5, sep=': ') # unless you specify the separator
print('no', 'separator', 'between', 'arguments', sep ='')

print('Supress the ', end='')
print('trailing line.')

# can also print to file with print() func using file keyword