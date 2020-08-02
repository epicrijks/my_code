# Write a Python program that can “make change.” Your program should
# take two numbers as input, one that is a monetary amount charged and the
# other that is a monetary amount given. It should then return the number
# of each kind of bill and coin to give back as change for the difference
# between the amount given and the amount charged. The values assigned
# to the bills and coins can be based on the monetary system of any current
# or former government. Try to design your program so that it returns as
# few bills and coins as possible.

# USD: 100, 50, 20, 10, 5, 1, 0.25, 0.10, 0.05, 0.01

bills = {'100': 0, '50': 0, '20': 0, '10': 0, '5': 0, '1': 0} 
coins = {'25': 0, '10': 0, '05': 0, '01': 0}

def make_change(charge, received):
    change = received - charge

    for key in bills:
        bills[key] = 0                          # Reset count for each transaction
        bills[key] = int(change // int(key))    # Calculate number of each bill
        change -= (bills[key] * int(key))       # Subtract that amount from the current change

    change *= 100

    for key in coins:
        coins[key] = 0
        coins[key] = int(change // int(key))
        change -= (coins[key] * int(key))

def print_change():
    for key in bills:
        print(f"${key:>4}: ", end='')
        print(bills[key])

    for key in coins:
        print(f"$0.{key:>2}: ", end='')
        print(coins[key])

def cash_register():
    print("Welcome to Pythonmart.")
    print()

    while True:
        try:
            charged = float(input("Sale: $"))
            received = float(input("Amount Received: $"))
            print(f"Change: ${received - charged:.{2}f}")
            print()
            make_change(charged, received)
            print_change()
            print()
        except EOFError:
            print()
            return
        except:
            print("Invalid entry.")
            print()

cash_register()