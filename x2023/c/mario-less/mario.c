#include <cs50.h>
#include <stdio.h>
int get_height(void);//function to get height input from user
void printgrid(int ht);//function to print grid or as the program gets input
int main(void)
{
 int height=get_height();
 printgrid(height);
}
int get_height(void)//taking height input from user
{
    int height;
    do
    {
        height=get_int("Height: \n");
    }
    while(height<1 || height==9 || height>10);
    return height;
}
void printgrid(int ht)
{
    for(int i=1;i<=ht;i++)
    {
        for(int k=i;k<=ht-1;k++)
        {
            printf(" ");
        }
        for(int j=1;j<=i;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}