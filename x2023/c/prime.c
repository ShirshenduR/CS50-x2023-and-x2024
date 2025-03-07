#include <cs50.h>
#include <stdio.h>
int getmin(void);
int getmax(void);
void checkprime(int min,int max);
int main(void)
{
    int max;
    //getting minimum from user
    int min=getmin();
    //getting maximum with a do while loop to check maximum is less than minimum
    do
    {
     max=getmax();
    }
    while(max<min);
    //checking and printing primt numbers between minimum and maximum using check prime function
    checkprime(min,max);
}
int getmin(void)
{
    int min;
    do
    {
        min=get_int("Minimum: \n");
    }
    while(min<1);
    return min;
}
int getmax(void)
{
    int max;
    do
    {
        max=get_int("Maximum: \n");
    }
    while(max<1 || max==0);
    return max;
}
void checkprime(int min,int max)
{
    int c=0;
    for(int i=min;i<=max;i++)
    {
        for(int j=1;j<=i;j++)
        {
           if(i%j==0)
           {
             c++;
           }
        }
        if(c==2)
        {
            printf("%i\n", i);
        }
        c=0;
}
}