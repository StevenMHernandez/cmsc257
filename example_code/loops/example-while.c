/*
   author: Preetam Ghosh
     date: Wed Jan 23 11:25:15 CST 2008
  purpose: Beginning with 1, determine how many integers must be summed
           in order to reach a total of at least 100.
*/

#include <stdio.h>

int main(void)
{
    int sum = 0;
    int current_integer = 0;

    printf("integer  sum\n");

    while(sum < 100)
    {
        current_integer++;       /* increment to get the next integer */
        sum += current_integer;  /* add current integer to our total */
        printf("%5d, %5d\n", current_integer, sum);
    }

    /* the last integer to be added is also the count of how many integers
       we looked at */
    printf("\nIt took %d integers to reach 100; our final sum was %d\n", 
            current_integer, sum);
}

/*************************************************************************
***********     Output    ************************************************

integer  sum
    1,     1
    2,     3
    3,     6
    4,    10
    5,    15
    6,    21
    7,    28
    8,    36
    9,    45
   10,    55
   11,    66
   12,    78
   13,    91
   14,   105

It took 14 integers to reach 100; our final sum was 105

*/
