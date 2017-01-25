/*
    author:  Preetam Ghosh
      date:  April 13, 2008
      file:  example-structures12.c
    
   purpose:  Demonstrate changing values of members 
             of structures in an array.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 3

typedef struct
{
    char id[10];
    char instructor[20];
} COURSE;

void uppercase(char *input);

int main(void)
{
    COURSE classes[] = { {"css 102", "Preetam Ghosh"}, 
                         {"csc 306", "Preetam Ghosh"}, 
                         {"math 537", "Ren-cang Li"} };
    int i;

    for(i = 0; i < SIZE; i++)
    {
        uppercase(classes[i].id);
        printf("%s is taught by %s\n", classes[i].id, classes[i].instructor);
    }
}


void uppercase(char *input)
{
    /* Notes:  A--Z is 65--90, a--z is 97--122

         Uppercase letters will have a decimal value
         of at least 65 but will be no larger than 90.

         Remember that strings conclude with a null
         character, so a string that takes n bytes of
         storage will have n-1 actual characters.
    */
    int i = 0;

    while(input[i] != '\0')
    {
        if(input[i] >= 97 && input[i] <= 122)
            input[i] -= 32;
        i++;
    }
}
/***************************************
***             Output               ***

CSS 333 is taught by Preetam Ghosh
CSC 306 is taught by Preetam Ghosh
MATH 537 is taught by Ren-cang Li

*/

