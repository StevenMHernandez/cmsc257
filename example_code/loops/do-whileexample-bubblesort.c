/*
      author:  Preetam Ghosh

        date:  Fri Jan 18 12:30:32 CST 2008

     purpose:  Demonstrate how to sort a set of numbers so that they are in
               ascending order

  pseudocode:
              1) beginning with the first two numbers
              2) compare the numbers
                 if first number > second number
                   swap the positions
              3) shift over to the second and third numbers
              4) repeat until comparing last two numbers
              5) if swapping occurred, return to step 1
*/

#include <stdio.h>

int main( void )
{
    /*  
        a, b, c and d represent placeholders for the four numbers to be sorted.  
        a is the first location, b is the second, c is the third, and d is the
        fourth.
    */
    int a = 3;
    int b = 2;
    int c = 4;
    int d = 1;
    int temp;
    int still_changing;

    printf("%d, %d, %d, %d\n", a, b, c, d);

    do
    {
        still_changing = 0;

        if (b < a)
        {
            temp = a;
            a = b;
            b = temp;
            still_changing = 1;
            printf("%d, %d, %d, %d\n", a, b, c, d);
        }

        if (c < b)
        {
            temp = b;
            b = c;
            c = temp;
            still_changing = 1;
            printf("%d, %d, %d, %d\n", a, b, c, d);
        }

        if (d < c)
        {
            temp = c;
            c = d;
            d = temp;
            still_changing = 1;
            printf("%d, %d, %d, %d\n", a, b, c, d);
        }
    } while (still_changing);
}


/*******************************************
**********   output    *********************

3, 2, 4, 1
2, 3, 4, 1
2, 3, 1, 4
2, 1, 3, 4
1, 2, 3, 4

*******************************************/
