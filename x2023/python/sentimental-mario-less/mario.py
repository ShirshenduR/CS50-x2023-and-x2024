# TODO
from cs50 import get_int
import sys
def main():
    height=get_height()
    printmario(height)


def get_height():
    height=get_int("Height: ")
    while height>8 or height<1:
        height=get_int("Height: ")
    return height


def printmario(ht):
    for i in range(1,ht+1):
        for k in range(i,ht):
            print(" ", end="")
        for j in range(i):
            print("#", end="")
        print("")


main()

