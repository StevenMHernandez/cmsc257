/*
    June 28, 2008

    purpose:  Demonstrate using a function to change the values
              in an array of structures.
*/

#include <stdio.h>

#define SIZE 4

typedef struct
{
    char name[20];
    int age;
} PERSON;

void changeAge(PERSON a[]);

int main(void)
{
    PERSON singer[] = { {"Madonna", 50},
                         {"Tom Jones", 68}, 
                         {"Britney Spears", 27},
                         {"Mick Jagger", 65} };
    int i;

    changeAge(singer);

    for(i = 0; i < SIZE; i++)
        printf("%s will be %d years old in 10 years\n", singer[i].name, singer[i].age);
}

void changeAge(PERSON s[])
{
    int i;

    for(i = 0; i < SIZE; i++)
    {
        printf("%s is %d years old\n", s[i].name, s[i].age);
        s[i].age += 10; /* change the original values in the array */
    }
    printf("\n");
}

/**************************************
***             Output              ***

Madonna is 50 years old
Tom Jones is 68 years old
Britney Spears is 27 years old
Mick Jagger is 65 years old

Madonna will be 60 years old in 10 years
Tom Jones will be 78 years old in 10 years
Britney Spears will be 37 years old in 10 years
Mick Jagger will be 75 years old in 10 years

*/

