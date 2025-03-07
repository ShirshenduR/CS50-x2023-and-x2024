#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
  if(argc!=2)//checking if key is more or less than 1 number
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  // checking if argv is digit or not and if it is digit then exitting the program and prompting user
   for(int i=0;i<strlen(argv[1]);i++)
   {
    if(!isdigit(argv[1][i]))
    {
      printf("Usage: ./caesar key\n");
      return 1;
    }
   }
   int k=atoi(argv[1]);
   string plain=get_string("Plaintext: ");
   printf("Ciphertext: ");
   for(int j=0;j<strlen(plain);j++)
   {
    if(isupper(plain[j]))
    {
    printf("%c", (plain[j]-65+k ) %26+65);// logic to cipher captial letters according to given key
    }
    else if(islower(plain[j]))
    {
      printf("%c", (plain[j]-97+k ) %26+97);// logic to cipher small letters
    }
    else
    {
      printf("%c",plain[j]);// logic used for spaces and symbols to not change in the string
    }
   }
     printf("\n");
   }
