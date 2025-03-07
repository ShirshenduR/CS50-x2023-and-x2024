from cs50 import get_float


def main():

    dollars = get_dollar()
    cents = int(dollars*100)

    quarters = calculate_quarters(cents)
    cents = cents - int(quarters*25)

    dimes = calc_dimes(cents)
    cents = cents - int(dimes*10)

    nickels = calc_nickels(cents)
    cents = cents - int(nickels*5)

    pennies = calc_pennies(cents)
    cents = cents - int(pennies)

    coins = quarters + dimes + nickels + pennies
    print(coins)

# function for taking input


def get_dollar():
    while True:
        dollar = get_float("Change: ")
        if dollar >= 0:
            return dollar


# function to calculate quarters


def calculate_quarters(dollars):
    quarters = int(dollars/25)
    return quarters

# function to calculate dimes


def calc_dimes(dollars):
    dimes = int(dollars/10)
    return dimes

# function to calculate nickels


def calc_nickels(dollars):
    nickels = int(dollars/5)
    return nickels

# function to calculate pennies


def calc_pennies(dollars):
    pennies = int(dollars/1)
    return pennies


main()
