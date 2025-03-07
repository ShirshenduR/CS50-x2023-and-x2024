#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int countletters(string text);
int countwords(string text);
int countsentences(string text);
int main(void)
{
   string text=get_string("Text: ");
   double l=countletters(text);
   double w=countwords(text);
   double se=countsentences(text);
   double L=l/w*100; // average letters per words * 100
   double S=se/w*100; // average sentences per words *100
   double index = 0.0588 * L - 0.296 * S - 15.8;
   if((int) round(index)>=1 && (int) round(index)<16) //condition for printing grade by rounding index if it is between 1 to 16
   {
   printf("Grade %d\n",(int) round(index));
   }
   else if((int) round(index)>=16) //condition for printing grade 16+ when grade is more than or equal to 16
   {
      printf("Grade 16+\n");
   }
   else // else for printing "Before Grade 1" if grade is less than 1
   {
      printf("Before Grade 1\n");
   }
}
int countletters(string text) //function to count letters
{
   int s=strlen(text);
   int l=0;
   for(int i=0;i<s;i++)
   {
      if(isalpha(text[i]))
      {
      l++;
      }
   }
   return l;
}
int countwords(string text) //function to count words
{
  int s=strlen(text);
  int w=1;
  for(int i=0;i<s;i++)
  {
   if(isspace(text[i]))
   {
      w++;
   }
  }
  return w;
}
int countsentences(string text) //function to count no. of sentences
{
   int s=strlen(text);
   int se=0;
   for(int i=0;i<s;i++)
   {
     if(text[i]=='.' || text[i]=='!' || text[i]=='?')
     {
      se++;
     }
   }
   return se;
}