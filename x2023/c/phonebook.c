#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name="Abhyudaya";
    people[0].number="+91-343-344-4334";
    people[1].name="David";
    people[1].number="+91-334-344-4443";

    string name=get_string("Name :");
    for(int i=0;i<2;i++)
    {
        if(strcmp(people[i].name, name)==0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}