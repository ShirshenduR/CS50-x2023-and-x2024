from cs50 import get_string


def main():
    text = get_string("Text: ")
    letters = countletters(text)
    words = countwords(text)
    sentences = countsentences(text)
    L = (letters/words) * 100
    S = (sentences/words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    if index < 1:
        print("Before Grade 1")
    elif index >= 15.5:
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")


def countletters(text):
    count = 0
    int(count)
    length = len(text)
    for i in range(0, length):
        if text[i].isalpha():
            count = count+1
    return count


def countwords(text):
    count = 0
    int(count)
    length = len(text)
    for i in range(0, length):
        if text[i].isspace():
            count = count + 1
    return count+1


def countsentences(text):
    count = 0
    int(count)
    length = len(text)
    for i in range(0, length):
        if text[i] == '.' or text[i] == '?' or text[i] == '!':
            count = count+1
    return count


main()
