#include <stdio.h>
#include <cs50.h>
int main(void)
{
    string first = get_string("What's is your first name ?"); // taking input from user his first name
    printf("Hello, %s\n", first);//printing hello with the name of user
}