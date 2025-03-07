#include <stdio.h>
int main(void)
{
    int a=20;
    int b=40;
    int t;
    printf("Orig a: %i\n",a);
    printf("Orig b: %i\n",b);
    t=a;
    a=b;
    b=t;
    printf("New a: %i\n",a);
    printf("New b: %i\n",b);
}