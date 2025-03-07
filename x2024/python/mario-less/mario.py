from cs50 import get_int

while True:
    size = get_int("Height: ")
    if size > 0 and size <= 8:
        break

for i in range(size):
    for j in range(size-1, i, -1):
        print(" ", end="")
    for k in range(0, i+1):
        print("#", end="")
    print()
