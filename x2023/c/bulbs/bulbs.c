#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{

    string message = get_string("Message: ");
    int len = strlen(message);
    char ch;
    for (int i = 0; i < len; i++)
    {
        int bits[] = {0, 0, 0, 0, 0, 0, 0, 0}; // 8 bits array for showing 8 bits in the number
        ch = message[i];
        for (int j = 0; j < 7; j++)
        {
            while ((int) ch != 0)
            {
                bits[j] = (int) ch % 2;
                j++;
                ch = (int) ch / 2;
            }
        }
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--) // reversing the order of binary digits
        {
            print_bulb(bits[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
