#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int numbers[]={20,500,10,5,1,100,50,21,13,28,24};
    int n=get_int("Number :");
    for (int i=0;i<10;i++)
    {
        if(numbers[i]==n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}