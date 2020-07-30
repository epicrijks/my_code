from random import randrange

def my_choice(data):
    index = randrange(0, len(data))
    return data[index]

# Flaky, but should be fine ;)
# Does one million assertions make it reliable? 0.o
data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for k in range(1000000):
    assert my_choice(data) in data

print ("Passed assertions.")