/*
    this program demonstrates different ways of declaring and
    defining functions that have arrays as function parameters
*/

#include <stdio.h>

void printname1(char [], int);
void printname2(char *,  int);
void printname3(char [], int); /* notice this doesn't match
                                  the definition            */

int main(void)
{
    char chararray[] = {68, 97, 114, 105, 110};
    int size = sizeof(chararray);

    printname1(chararray, size);    
    printf("\n");

    printname2(chararray, size);    
    printf("\n");

    printname3(chararray, size);    
    printf("\n");
}

/* uses subscript notation */
void printname1(char a[], int num)
{
    int i;
    for(i = 0; i < num; i++)
        printf("%c", a[i]);
}

/* uses pointer notation */
void printname2(char *a, int num)
{
    int i;
    for(i = 0; i < num; i++)
        printf("%c", *(a+i));
}

/* uses subscript and pointer notation */
void printname3(char *a, int num)
{
    int i;
    for(i = 0; i < num; i++)
        printf("%c", a[i]);
}
/**************************************
***********    Output    **************

Darin
Darin
Darin

*/
