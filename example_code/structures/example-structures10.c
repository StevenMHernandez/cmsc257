/*
    author:  Preetam Ghosh
      date:  Sun Apr 13 20:02:36 CDT 2008
      file:  example-structures10.c
    
   purpose:  Demonstrate passing array of structures to a
             function and accessing of structure members.
*/

#include <stdio.h>

#define SIZE 4
struct person
{
    char name[20];
    int birthyear;
};

int oldest(struct person []);

int main(void)
{
    struct person singers[SIZE] = { {"Madonna", 1958},
                                    {"Tom Jones", 1940}, 
                                    {"Britney Spears", 1981},
                                    {"Mick Jagger", 1943} };
    int old;

    old = oldest(singers);

    printf("the oldest singer is %s, who was born in %d\n", 
            singers[old].name, singers[old].birthyear);
}

int oldest(struct person s[])
{
    int year = 2008;
    int sub = 0;
    int i;

    for(i = 0; i < SIZE; i++)
    {
        if(s[i].birthyear < year)
        {
            year = s[i].birthyear;
            sub = i;
        }
    }

    return sub;
}

/***************************************
***             Output               ***

the oldest singer is Tom Jones, who was born in 1940

*/

