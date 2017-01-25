/*
    author:  Preetam Ghosh
      date:  Sun Apr 13 20:04:26 CDT 2008
      file:  example-structures11.c
    
   purpose:  Demonstrate the use of string functions 
             with structures.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 5

struct person
{
    char firstname[20];
    char lastname[20];
    int birthyear;
};

enum bln {F, T};

void cmpNames(struct person [], int, int);

int main(void)
{
    struct person people[SIZE] = { {"John", "Smith", 1958},
                                   {"Tom", "Jones", 1940}, 
                                   {"John", "Denver", 1943},
                                   {"Mary", "Smith", 1980},
                                   {"Susan", "Smith", 1943} };
    int i, j;

    for(i = 0; i < SIZE - 1; i++)
        for(j = i + 1; j < SIZE; j++)
            cmpNames(people, i, j);
}

void cmpNames(struct person data[], int a, int b)
{
    static enum bln first = T;

    if(strcmp(data[a].lastname, data[b].lastname) == 0)
        if(first == T)
        {
            printf("%s %s and %s %s have the same last name\n", 
                    data[a].firstname, data[a].lastname, 
                    data[b].firstname, data[b].lastname);
            first = F;
        }
        else
            printf("%s %s and %s %s also have the same last name\n", 
                    data[a].firstname, data[a].lastname, 
                    data[b].firstname, data[b].lastname);
}

/*****************************************************
***                      Output                    ***

John Smith and Mary Smith have the same last name
John Smith and Susan Smith also have the same last name
Mary Smith and Susan Smith also have the same last name

*/
