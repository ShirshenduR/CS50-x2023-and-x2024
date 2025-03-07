# TODO
from cs50 import get_string


def main():
    text = get()
    l = countletters(text)
    w = countwords(text)
    se = countsentences(text)
    L = (l / w) * 100
    S = (se / w) * 100
    index = 0.0588 * L - 0.296 * S - 15.8  # calculating index by the given formula
    if round(index) >= 1 and round(index) < 16:
        print(f"Grade {round(index)}")
    elif round(index) >= 16:
        print("Grade 16+")
    else:
        print("Before Grade 1")


# Function to take input from user
def get():
    text = get_string("Text: ")
    while len(text) < 2:
        text = get_string("Text: ")
    return text


# FUnction to count letters
def countletters(text):
    c = 0
    for i in range(len(text)):
        if text[i].isalpha() == True:
            c += 1
    return c


# Function to count words
def countwords(text):
    c = 1  # taking c is equal to 1 because no of words is one more than no. of spaces
    for i in range(len(text)):
        if text[i] == " ":
            c += 1
    return c


# Function to count sentences
def countsentences(text):
    c = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            c += 1
    return c


main()
