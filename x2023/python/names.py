import sys

names = ["Billi", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]
name = input("Name: ")

if name in names:
    print("Found")
    sys.exit(0)