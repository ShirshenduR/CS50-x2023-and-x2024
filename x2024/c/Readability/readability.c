#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    double letters = count_letters(text);
    double words = count_words(text);
    double sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    double L = (letters / words) * 100;
    double S = (sentences / words) * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 15.5)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}
int count_letters(string text)
{
    // Return the number of letters in text
    int count = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    // Return the number of words in text
    int count = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count + 1;
}
int count_sentences(string text)
{
    // Return the number of senetences in text
    int count = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}
