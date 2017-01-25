/*
    Preetam Ghosh
    May 24, 2008

    Demonstration of the do-while loop.
*/

#include <stdio.h>

int main(void)
{
    int x = 3;

    do
    {
        printf("%d is less than 5\n", x);
        x++;
    }
    while(x < 5);

    printf("\nx is %d\n\n", x);

    /*  this doesn't do what we want  */
    do
    {
        printf("%d is less than 5\n", x);
        x++;
    }
    while(x < 5);
}

/************************
***     Output        ***

3 is less than 5
4 is less than 5

x is 5

5 is less than 5

*/
