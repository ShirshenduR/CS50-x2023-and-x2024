# TODO
from cs50 import get_int


def main():
    number = get_card()
    if check(number) == 0:
        cardtype(number)
    else:
        print("INVALID")


def get_card():
    try:
        cnumber = get_int("Number: ")
    except ValueError:
        while True:
            cnumber = get_int("Number: ")
            return cnumber
    if len(str(cnumber)) < 13:
        print("INVALID")
    return cnumber


def check(number):
    length = len(str(number))
    num = str(number)
    sum = 0
    sum1 = 0
    sum2 = 0
    for i in range(0, length, 2):
        if int((num[i])) * int(2) < 9:
            sum = int(sum) + int((num[i])) * int(2)
        if int((num[i])) * int(2) > 9:
            s = int((num[i])) * int(2)
            while s != 0:
                d = int(s % 10)
                sum1 = int(sum1 + d)
                s = int(s / 10)
            sum = sum1 + sum

    for i in range(1, length, 2):
        sum2 = int(sum2) + int((num[i]))
    tsum = sum + sum2
    if tsum % 10 == 0:
        return 0
    else:
        return 1


def cardtype(number):
    num = len(str(number))
    num1 = str(number)
    if (
        num == 16
        and num1[0] == "5"
        and num1[1] == "1"
        or num1[1] == "2"
        or num1[1] == "3"
        or num1[1] == "4"
        or num1[1] == "5"
    ):
        print("MASTERCARD")
    elif num == 15 and num1[0] == "3" and num1[1] == "4" or num1[1] == "7":
        print("AMEX")
    elif num == 13 or num == 16 and num1[0] == "4":
        print("VISA")
    else:
        print("INVALID")


main()
