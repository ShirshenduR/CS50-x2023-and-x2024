#include <stdio.h>
#include <cs50.h>

int checksum(long n);

int main(void)
{
    long n =get_long("Number: ");
    int sum = checksum(n);
    printf("%i\n", sum);
}

int checksum(long n)
{
    //Checking the card no. if it is valid
    int sum = 0;
    int prod =2;
    int d;
    while(n!=0)
    {
        d = n%100;
        d = d/10;
        prod = prod*d;
        if(prod<10)
        {
            sum = sum+d;
        }
        else
        {

                sum = sum+d%10;
        }
        n=n/100;
    }
    return sum;
}
