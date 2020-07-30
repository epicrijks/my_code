myFile = open('files.txt', 'w+')
myFile.writelines('Hello, world\n')
print('This is a second line.', file = myFile, end='')

myFile.seek(0)

for line in myFile:
    print(line)

myFile.close()