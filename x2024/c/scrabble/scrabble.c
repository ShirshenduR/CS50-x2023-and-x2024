#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int computescore(string s);

int main(void)
{
    // Ask the user for two words
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    // Calculate and store score of each word
    int score1 = computescore(p1);
    int score2 = computescore(p2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int computescore(string w)
{
    int score = 0;
    // Function to Calculate the score of word
    int len = strlen(w);
    for (int i = 0; i < len; i++)
    {
        if (isupper(w[i]))
        {
            score = score + POINTS[w[i] - 'A'];
        }
        if (islower(w[i]))
        {
            score = score + POINTS[w[i] - 'a'];
        }
    }
    return score;
}
