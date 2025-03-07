#include<stdio.h>
#include<cs50.h>
int getstartsize(void);
int getendsize(void);
void years(int st,int end);
int main(void)
{
   int start=getstartsize();//getting start size using function getstartsize();

    int end=getendsize();//getting end size using function getendsize();
    if(end<start)
    {
      getendsize();
    }
    years(start,end);
}


int getstartsize(void)
{
  int start;
   do
   {
    start=get_int("Start Size: \n");
   }
   while(start<9);
   return start;
}
int getendsize(void)
{
   int end;
  do
  {
     end=get_int("End Size: \n");
  }
  while(end<18);
  return end;
}
void years(int st,int end)
{

    int years=0;
    if(st==end)
    {
      printf("Years: %i\n", years);
    }
    else
    {
    do
    {
      st=st+(st/3)-(st/4);
      years++;
    }
    while (st<end);
    printf(" Years: %i\n", years);
    }
}