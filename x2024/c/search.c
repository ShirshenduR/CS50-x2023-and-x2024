#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int numbers[] = {20,10,500,100,1,5,50};

    int n = get_int("Number: ");
    for(int i = 0; i<7; i++)
    {
        if(numbers[i] == n)
        {
            printf("%i Found \n",n);
            return 0;
        }

    }
    printf("%i not Found \n", n);
    return 1;
}

