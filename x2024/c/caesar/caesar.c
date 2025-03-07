#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string text = get_string("plaintext: ");
    // For each character in the plaintext:
    // Rotate the character if it's a letter
    int cipher[strlen(text)];
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                int p = (int) text[i] - 97;
                cipher[i] = (p + key) % 26;
            }
            if (isupper(text[i]))
            {
                int p = (int) text[i] - 65;
                cipher[i] = (p + key) % 26;
            }
        }
    }
    printf("ciphertext: ");

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", (char) (cipher[i] + 65));
        }
        if (islower(text[i]))
        {
            printf("%c", (char) (cipher[i] + 97));
        }
        if (isspace(text[i]) || ispunct(text[i]))
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
